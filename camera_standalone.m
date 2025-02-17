%% camera_standalone.m
% This m-file opens the camera on your laptop and opens a UI where three
% threshold functions can be chosen that are defined here below. A snapshot
% can be made to be imported to the "Color Thresholder" app and the blob
% size can be changed. The binary image from the chosen threshold function
% can be showed and the object detection visualization can be turned on or
% off. All this can be done while the camera shows a live feed. 
%
% 2022 - 4GB20 Robot-arm

%% Set detection variables; ONLY MAKE CHANGES IN THIS SECTION!
% Color; change to exported color threshold function from the app "Color
% Thresholder" per object
mask_object_1 = @example_mask_red;
mask_object_2 = @example_mask_yellow;
mask_object_3 = @example_mask_blue;

%% Load calibration and file name
if exist('vid','var')
    vid.release();
    clear vid;
    pause(1)
end

if ~exist('camera_calibration_x_pixels','var')
    robot_number = input('What is your Robot number?: ');
    load('calibration_matrix.mat');
    [camera_calibration_x_pixels,camera_calibration_y_pixels,...
        camera_calibration_pixels_per_mm,camera_calibration_ROI,...
        robot_calibration_r,robot_calibration_x, robot_calibration_z]...
        = Calibrate_Robot_Settings(robot_number,calibration);
end

imaqreset

max_objects = 3; % Max number of possible detected objects

% Blob area; minimum and maximum area for the blob analysis per object
% in pixels as starting variables
min_blob_area_object = 0;      % Minimal blob area in pixels for object
max_blob_area_object = 400000; % Maximum blob area in pixels for object 

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

%% Create figure
f = figure('Toolbar','none',...
       'Menubar', 'none',...
       'NumberTitle','Off',...
       'Name','Object detection robotarm');
   
image_handle = imshow(vid.step);
   
% Move and resize figure
f.Position = [100 100 vid.ROI(3)+500, vid.ROI(4)+200];
movegui(f,'center');

% Create UI
% Blob size
uicontrol(f,'Style', 'text',...
    'Position',[20 120 140 20],...
    'String', 'Minimal blob area [pixel]');

uicontrol(f,'Style', 'edit',...
    'Callback', {@set_blob_variables_callback_min,f},...
    'String', num2str(min_blob_area_object),...
    'Position',[20 100 140 20]);

uicontrol(f,'Style', 'text',...
    'Position',[20 170 140 20],...
    'String', 'Maxmimal blob area [pixel]');

uicontrol(f,'Style', 'edit',...
    'Callback', {@set_blob_variables_callback_max,f},...
    'String', num2str(max_blob_area_object),...
    'Position',[20 150 140 20]);

% Snapshot
uicontrol('String', 'Snapshot',...
    'Callback', {@snapshot,vid},...
    'Units','normalized',...
    'Position',[0.005 0.005 0.15 .07]);

% Mask selection
uicontrol(f,'Style', 'popupmenu',...
    'Callback', {@select_mask,f},...
    'String', {func2str(mask_object_1),func2str(mask_object_2),...
    func2str(mask_object_3)},...
    'Position',[20 250 140 20])

uicontrol(f,'Style', 'text',...
    'Position',[20 270 140 20],...
    'String', 'Select threshold function');

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
rectangle('Position',[3,3,110,60],'FaceColor',[0 0 0],'EdgeColor','w',...
    'LineWidth',1);

centroid_text = text(21, 10, 'centroid', 'FontSize', 12, 'Color', 'white');
O_text = text(6, 10, 'O', 'Color', 'blue', 'FontSize', 12);

bbox_text = text(21, 30, 'bounding box', 'FontSize', 12, 'Color', 'white');
box_text = text(6, 30, '⬜', 'Color', 'yellow', 'FontSize', 12);

area_text = text(21, 50, 'area', 'FontSize', 12, 'Color', 'white');
area_sign = text(6, 50, '▬', 'Color', 'green', 'FontSize', 12);

% Set Blob variables
hBlob = set_blob_variables(min_blob_area_object,...
    max_blob_area_object, max_objects);

% Connect variables to figure, such that the callback functions can make
% changes to the variables
f.UserData = struct("blobHandle", hBlob, "maskFunction", mask_object_1,...
    "binaryToggle",0,"visToggle",1);

%% Object detection while figure is open
while ishandle(f)
    
    [x_position_pixel, y_position_pixel, area_pixel] = ...
        object_detection(vid, f.UserData.blobHandle,...
        f.UserData.maskFunction, image_handle, f);
    
    % Convert pixel position of camera to position in mm from the center of
    % robot using
    x_position_mm =  (160+camera_calibration_x_pixels/...
        camera_calibration_pixels_per_mm)-x_position_pixel/...
        camera_calibration_pixels_per_mm; % pixels to mm from center robot
    y_position_mm = -(150-camera_calibration_y_pixels/...
        camera_calibration_pixels_per_mm)-y_position_pixel/...
        camera_calibration_pixels_per_mm; % pixels to mm from center robot
    
    pause(0.02)
end

vid.release();

%% Object detection functions
function hBlob = set_blob_variables(min_blob_area_in, max_blob_area_in,...
    max_count)
    hBlob = vision.BlobAnalysis(...
        'MinimumBlobArea', min_blob_area_in,...
        'MaximumBlobArea', max_blob_area_in,...
        'MaximumCount', max_count);
end

function [x, y, area] = object_detection(videodevice, hBlob,...
    mask_object, image_handle, figure)

    % Get RGB-frame
    RGB_frame = im2uint8(videodevice.step());
    
    % Converts RGB to boolean
    boolean_frame = mask_object(RGB_frame);

    % Remove noisy pixels
    diskElem = strel('disk', 5);
    filtered_boolean_frame = imopen(boolean_frame,diskElem); 
    
    % Perform blob analysis
    [area, centroid, b_box] = hBlob(filtered_boolean_frame); 
    
    % Reverse x and y as robot x and y is different from image x and y
    x = centroid(:,2);
    y = centroid(:,1); 
    
    % Plot detected objects
    if figure.UserData.binaryToggle
        plot_frame = 255 * cat(3, filtered_boolean_frame,...
            filtered_boolean_frame, filtered_boolean_frame);
    else
        plot_frame = RGB_frame;
    end


    if isempty(area) || ~figure.UserData.visToggle
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

%% Callbacks UI
function snapshot(~,~,vid)
    frame = vid.step();
    file_name = inputdlg('Enter file name for snapshot: ','s');
    imwrite(frame, append(file_name{1},'.png'));
end

function set_blob_variables_callback_min(obj,~, figure)
    figure.UserData.blobHandle.MinimumBlobArea = str2double(obj.String);
end

function set_blob_variables_callback_max(obj,~, figure)
    figure.UserData.blobHandle.MaximumBlobArea = str2double(obj.String);
end

function select_mask(obj,~, figure)
    figure.UserData.maskFunction = str2func(obj.String{obj.Value});
end

function binary_toggle(obj,~, figure)
    figure.UserData.binaryToggle = obj.Value;
end

function vis_toggle(obj,~, figure)
    figure.UserData.visToggle = obj.Value;
end
