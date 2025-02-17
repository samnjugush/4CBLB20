%% calibration
% This script calibrates the camera and the robot-arm using the 3D printed
% plate. First initialize the model from the Simulink calibration file
% and run Simulink first. Then run the calibration script and follow the
% instructions. This m-file saves the new calibration matrix.
%
% 2022 - 4GB20 Robot-arm

%% Set detection variables, ONLY MAKE CHANGES IN THIS SECTION PER ROBOT
% Color; change to exported color threshold function from the app "Color
% Thresholder" per object
red_mask = @red_mask;

% ROI; manually determine ROI via "Daheng Galaxy Viewer" or "Image
% Acquisition" app
ROI = [1,160,1080,700];

%% Startup and check model variables
% Check initialization
if ~exist('file_name_simulink','var')
    error('Please initialize the Simulink calibration file first')
end

% Check if Simulink is running
if ~strcmp(get_param(file_name_simulink,'SimulationStatus'),'external')
    error(append(file_name_simulink,' is not running. Please ',...
    'run the model before running the calibration script'))
end

imaqreset

if exist('vid','var')
    vid.release();
    clear vid
    pause(1)
end

% Blob Analysis settings
min_blob_area = 2000; % Minimum area for the blob analysis in pixels
max_blob_area = 10000; % Maximum area for the blob analysis in pixels

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
vid.ROI = ROI;
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
% Next
uicontrol('String', 'Next',...
    'Callback', {@next_button,f},...
    'Units','normalized',...
    'Position',[0.005 0.005 0.15 .07]);

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

% Connect variables to figure, such that the callback functions can make
% changes to the variables
f.UserData = struct("binaryToggle",0,"visToggle",1,"nextButton",1);

% Blob detection on red dots
% Set Blob variables
hBlob = set_blob_variables(min_blob_area,...
    max_blob_area, 2);

c = uicontrol(f,'Style','text');
c.Position = [300 25 400 30];
c.String = 'Detect the red dots on the 3D-printed plate and click "next"';

%% Camera calibration by detecting red dots
while f.UserData.nextButton
    
    [x_position_pixel_red, y_position_pixel_red, ~] = ...
    object_detection(vid, hBlob, red_mask,...
    image_handle, f);
    
    pause(0.02)
end

f.UserData.nextButton = 1;

%Calculate pixel per mm
pixel_distance_between_red_points = sqrt((x_position_pixel_red(1)...
    -x_position_pixel_red(2))^2 + (y_position_pixel_red(1)-...
    y_position_pixel_red(2))^2);
camera_calibration_pixels_per_mm = pixel_distance_between_red_points/60

% Find the maximal value of the y_position to get the right red dot pixel
% for calibration
max_index = find(y_position_pixel_red==max(y_position_pixel_red));
camera_calibration_x_pixels = x_position_pixel_red(max_index)
camera_calibration_y_pixels = y_position_pixel_red(max_index)

%% Robot detection by setting robot in a position by hand
c.String = "Place the robot by hand in the hole of the the 3D-printed plate and click next";

while f.UserData.nextButton
    
    [x_position_pixel_red, y_position_pixel_red, ~] = ...
    object_detection(vid, hBlob, red_mask,...
    image_handle, f);
    
    pause(0.02)
end

close

% Get current values of angles after putting it in the calibration position
% by hand
angles_current = ...
    SPERTE_Measure_And_Collect(p,3,1,file_name_simulink);
    
% Robot position at calibration
[R_calibration, X_calibration, Z_calibration] = invkin(160, 0, 54);

% Wanted homing robot position
[R_homing, X_homing, Z__homing] = invkin(160, 0, 99);
% 
% homing_diff = [R_calibration, X_calibration, Z_calibration] - [R_homing,...
%     X_homing, Z__homing] - angles_current
homing_diff = angles_current

%% Save new variables to calibration_matrix.mat
load('calibration_matrix.mat')

calibration(robot_number,1)   = camera_calibration_x_pixels;
calibration(robot_number,2)   = camera_calibration_y_pixels;
calibration(robot_number,3)   = camera_calibration_pixels_per_mm;
calibration(robot_number,4:7) = ROI;
calibration(robot_number,8)   = robot_calibration_r + homing_diff(1);
calibration(robot_number,9)   = robot_calibration_x + homing_diff(2);
calibration(robot_number,10)  = robot_calibration_z + homing_diff(3);

save('calibration_matrix.mat', 'calibration')

set_param(file_name_simulink, 'SimulationCommand', 'stop')

msgbox(append('Calibration completed, and new calibration_matrix.mat',...
' saved in ',pwd))

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
    RGB_frame = videodevice.step();
    
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
            round([centroid,10*ones(length(centroid(:,1)),1)]),...
            'LineWidth',5,'color', 'blue');
        RGB_frame_circle_box = insertShape(RGB_frame_circle,'rectangle',...
            b_box,'LineWidth',5,'color', 'yellow');
        RGB_frame_circle_box_area = insertText(RGB_frame_circle_box,...
            centroid+30,area,'BoxOpacity',1,'BoxColor', 'green');
        image_handle.CData = RGB_frame_circle_box_area;
    end
        
end

%% Callbacks UI
function next_button(~,~, figure)
    figure.UserData.nextButton = 0;
end

function binary_toggle(obj,~, figure)
    figure.UserData.binaryToggle = obj.Value;
end

function vis_toggle(obj,~, figure)
    figure.UserData.visToggle = obj.Value;
end
