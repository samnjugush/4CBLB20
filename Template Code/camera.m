%% camera
% This m-file opens the camera on your laptop and does a blob analysis to
% detect objects. Three different objects can be chosen to be detected.
% The position coordinates of these objects are send to Simulink,
% which is running on the Raspberry Pi. The positions are sent as a matrix
% in which the first row is the x-coordinate and the second row the
% y-coordinate. The columns indicate different detected objects. The last
% column indicates the unix time of the raspberry pi when the current
% frame was taken.
%
% 2022 - 4GB20 Robot-arm

%% Set detection variables; ONLY MAKE CHANGES IN THIS SECTION!
% Color; change to exported color threshold function from the app "Color
% Thresholder" per object
mask_object_1 = @example_mask_red;
mask_object_2 = @example_mask_yellow;
mask_object_3 = @example_mask_blue;

% Blob area; minimum and maximum area for the blob analysis per object
% in pixels
min_blob_area_object_1 = 1000;  % Minimal blob area in pixels for object 1
max_blob_area_object_1 = 40000; % Maximum blob area in pixels for object 1       
min_blob_area_object_2 = 1000;  % Minimal blob area in pixels for object 2
max_blob_area_object_2 = 40000; % Maximum blob area in pixels for object 2     
min_blob_area_object_3 = 1000;  % Minimal blob area in pixels for object 3
max_blob_area_object_3 = 40000; % Maximum blob area in pixels for object 3       

% Framerate in Hz of the object detection; set this lower if you notice
% that the model is running slow. Do not set it higher than 5. 
framerate_detection = 5; 

%% Load calibration and file name
if exist('vid','var')
    vid.release();
    clear vid;
    pause(1)
end

if ~exist('file_name_simulink','var')
    robot_number = input('What is your Robot number?: ');
    file_name_simulink = get_param(bdroot, 'Name');
    load('calibration_matrix.mat');
    [camera_calibration_x_pixels,camera_calibration_y_pixels,...
        camera_calibration_pixels_per_mm,camera_calibration_ROI,...
        robot_calibration_r,robot_calibration_x, robot_calibration_z]...
        = Calibrate_Robot_Settings(robot_number,calibration);
end

% Check if Simulink is running
if ~strcmp(get_param(file_name_simulink,'SimulationStatus'),'external')
    error(append(file_name_simulink,' is not running. Please ',...
    'run the model before running the camera script. Run ',...
    'camera_standalone.m to run the camera without the model.'))
end

imaqreset

% Create a blob area matrix
blob_area_matrix = [min_blob_area_object_1 max_blob_area_object_1;...
                    min_blob_area_object_2 max_blob_area_object_2;...
                    min_blob_area_object_3 max_blob_area_object_3];

max_objects = 3;     % Max number of possible detected objects
image_handle = [];   % Initialize image handle
f = [];              % Initialize figure
figure_open = false; % Variable to check if figure is already open


%% Camera initialization
info          = imaqhwinfo();
adaptor_name  = info.InstalledAdaptors{1,1};
adaptor_info  = imaqhwinfo(adaptor_name);
device_id     = find(strcmp({adaptor_info.DeviceInfo.DeviceName},...
    'Daheng Imaging Device 1')==1);
format        = 'RGB24_1280x960';
color_space   = 'rgb';

% Create video device and set parameters
vid = imaq.VideoDevice(adaptor_name,device_id,format);
vid.ROI = camera_calibration_ROI;
vid.DeviceProperties.ExposureMode = 'auto';
vid.DeviceProperties.WhiteBalanceMode = 'auto';
vid.DeviceProperties.GainMode = 'auto';

%% Object detection at set framerate
stop_detection = str2double(get_param(file_name_simulink...
    + "/Controller/Stop",'Value'));


while stop_detection ~= 1 %&& strcmp(get_param(file_name_simulink,...
        %'SimulationStatus'),'external')
    tic
    position_matrix = zeros(max_objects+1,3);
    
    % Get values from Simulink
    wanted_object = str2double(get_param(file_name_simulink...
        + "/Controller/Object",'Value'));
    plot_detection = str2double(get_param(file_name_simulink...
        + "/Controller/Plot",'Value'));
    stop_detection = str2double(get_param(file_name_simulink...
        + "/Controller/Stop",'Value'));
    
    % Get current time from raspberry pi, 1/15 needs to be added
    % to get perfect tracking. Unclear why exactly
    unix_time = str2double(system(p,'date +%s%N | cut -b1-13'))/1e3 - 1/15;
    
    hBlob = set_blob_variables(blob_area_matrix(wanted_object,1),...
        blob_area_matrix(wanted_object,2), max_objects);
    
    [x_position_pixel, y_position_pixel, area_pixel, figure_open,...
        image_handle, f] = object_detection(vid, hBlob, mask_object_1, ...
        mask_object_2, mask_object_3, wanted_object, plot_detection,...
        file_name_simulink, figure_open, image_handle, f);
    
    % Convert pixel position of camera to position in mm from the center of
    % robot using
    x_position_mm =  (160+camera_calibration_x_pixels/...
        camera_calibration_pixels_per_mm)-x_position_pixel/...
        camera_calibration_pixels_per_mm; % pixels to mm from center robot
    y_position_mm = -(150-camera_calibration_y_pixels/...
        camera_calibration_pixels_per_mm)-y_position_pixel/...
        camera_calibration_pixels_per_mm; % pixels to mm from center robot
    
    % Send positions to Simulink. First row is the x-coordinate, second row
    % the y-coordinate. Columns indicate different detected objects. Last
    % row indicates the unix time on the raspberry pi
    position_matrix(1:length(x_position_mm),1) = x_position_mm;
    position_matrix(1:length(y_position_mm),2) = y_position_mm;
    position_matrix(1:length(y_position_mm),3) = area_pixel;
    position_matrix(max_objects+1,1) = unix_time;
    
    set_param(file_name_simulink + ...
        "/Controller/Camera/Object detection matrix",'Value',"["+num2str...
        (position_matrix(:,1)')+";"+num2str(position_matrix(:,2)')...
        +";"+num2str(position_matrix(:,3)')+"]");
    
    x1 = toc;
    pause(max(0, 1/framerate_detection - x1));
end

vid.release();
set_param(file_name_simulink + "/Controller/Stop",'Value',"0");
set_param(file_name_simulink +...
    "/Controller/Camera/Object detection matrix",'Value',...
    "["+num2str(zeros(4))+";"+num2str(zeros(4))+";"+num2str(zeros(4))+"]")

%% Object detection functions
function hBlob = set_blob_variables(min_blob_area_in, max_blob_area_in,...
    max_count)
    hBlob = vision.BlobAnalysis(...
        'MinimumBlobArea', min_blob_area_in,...
        'MaximumBlobArea', max_blob_area_in,...
        'MaximumCount', max_count);
end

function [x, y, area, figure_open, image_handle, f] = object_detection(...
    videodevice, hBlob, mask_object_1, mask_object_2, mask_object_3,...
    object, plot, file_name_simulink, figure_open, image_handle, f)

    % Get RGB-frame
    RGB_frame = im2uint8(videodevice.step());
    
    % Converts RGB to boolean
    switch object
        case 1
            boolean_frame = mask_object_1(RGB_frame);
        case 2
            boolean_frame = mask_object_2(RGB_frame);
        case 3
            boolean_frame = mask_object_3(RGB_frame);
        otherwise 
            boolean_frame = mask_object_1(RGB_frame); 
    end
    
    % Remove noisy pixels
    diskElem = strel('disk', 5);
    filtered_boolean_frame = imopen(boolean_frame,diskElem); 
    
    % Perform blob analysis
    [area, centroid, b_box] = hBlob(filtered_boolean_frame); 
    
    % Reverse x and y as robot x and y is different from image x and y
    x = centroid(:,2);
    y = centroid(:,1); 
 
    % Plot detected objects
    if plot == 1
        
        % Open figure if not yet open
        if ~figure_open
            
            f = figure('Toolbar','none',...
               'Menubar', 'none',...
               'NumberTitle','Off',...
               'Name','Object detection robotarm');
           
            image_handle = imshow(RGB_frame);
           
            f.Position = [100 100 videodevice.ROI(3)+500,...
                videodevice.ROI(4)+200];
            movegui(f,'center');
            
            % Toggle mask
            uicontrol(f,'Style', 'checkbox',...
                'String', 'Show binary image',...
                'Callback', {@binary_toggle,f},...
                'Position',[20 300 140 20])

            % Toggle detection visualization
            uicontrol(f,'Style', 'checkbox',...
                'String', 'Show visualization',...
                'Callback', {@vis_toggle,f},...
                'Position',[20 320 140 20],...
                'Value', 1)

            % Create legend
            rectangle('Position',[3,3,110,60],'FaceColor',[0 0 0],...
                'EdgeColor','w',...
                'LineWidth',1);

            centroid_text = text(21, 10, 'centroid', 'FontSize', 12,...
                'Color', 'white');
            O_text = text(6, 10, 'O', 'Color', 'blue', 'FontSize', 12);

            bbox_text = text(21, 30, 'bounding box', 'FontSize', 12,...
                'Color', 'white');
            box_text = text(6, 30, '⬜', 'Color', 'yellow', 'FontSize', 12);

            area_text = text(21, 50, 'area', 'FontSize', 12, 'Color',...
                'white');
            area_sign = text(6, 50, '▬', 'Color', 'green', 'FontSize', 12);
            
            f.UserData = struct("binaryToggle",0,"visToggle",1);
            
            figure_open = true;
        end
        
        if ~ishandle(image_handle)
            figure_open = false;
            set_param(file_name_simulink + "/Controller/Plot",'Value',"0")
            return
        end 
        
        if f.UserData.binaryToggle
            plot_frame = 255 * cat(3, filtered_boolean_frame,...
                filtered_boolean_frame, filtered_boolean_frame);
        else
            plot_frame = RGB_frame;
        end

        if isempty(area) || ~f.UserData.visToggle
            image_handle.CData = plot_frame;
        else
        RGB_frame_circle = insertShape(plot_frame,'circle',...
            round([centroid,50*ones(length(centroid(:,1)),1)]),...
            'LineWidth',5,'color', 'blue');
        RGB_frame_circle_box = insertShape(RGB_frame_circle,'rectangle',...
            b_box,'LineWidth',5,'color', 'yellow');
        RGB_frame_circle_box_area = insertText(RGB_frame_circle_box,...
            centroid,area,'BoxOpacity',1,'BoxColor', 'green');
        image_handle.CData = RGB_frame_circle_box_area;
        end
        
    end
    
end

%% Callback functions
function binary_toggle(obj,~, figure)
    figure.UserData.binaryToggle = obj.Value;
end

function vis_toggle(obj,~, figure)
    figure.UserData.visToggle = obj.Value;
end
