function Install()
%% Install()
% Installs the robotarm simulink library, RTScope, SPERTE and adds neccesary files
% to the MATLAB path
% 
% Control Systems Technology group
% Departement of Mechanical Engineering
% Eindhoven University of Technology
% 

% Get the current dir
current_dir = pwd;
mfilepath = mfilename('fullpath');
[lib_install_dir,~,~]  = fileparts(mfilepath);
% Change to the install script folder
cd(lib_install_dir)

% Opening the progress bar
wb = waitbar(0,'Adding files to path');

% Add all relevant folders to the path
folders = {'./camera', './hardware_documentation', './inverse_kinematics', './Simulink', ...
           './SPERTE', './tooling'};

for i = 1:length(folders)
    addpath(genpath(folders{i}));
end

% Saving the path to make it permanent
savepath;

% Installing SPERTE
waitbar(1/4,wb,'Installing SPERTE');
SPERTE_Install_User();

% Installing RTScope
waitbar(2/4,wb,'Installing RTScope');

% Installing Simulink library
waitbar(3/4,wb,'Installing Simulink library');
slblocks;

waitbar(4/4,wb,'Installation completed.');
try close(wb); catch, end

% Go back to previous folder
cd(current_dir)
disp('Robotarm installation completed.');
end
