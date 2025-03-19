function Simulator_Install()
    curdir = pwd;
    % List of required toolboxes (addon names)
    requiredAddons = ["Simulink", "Instrument Control Toolbox", "Stateflow"];
    
    % Get the list of installed add-ons
    installedAddons = matlab.addons.installedAddons();
    installedAddonNames = installedAddons.Name;
    
    allToolboxesPresent = true; % Flag to track toolbox presence

    % Check each required addon
    for i = 1:length(requiredAddons)
        if ~ismember(requiredAddons(i), installedAddonNames)
            % Print message to the command window
            fprintf('%s not found. Please install manually.\n', requiredAddons(i));
            
            % Display dynamic message in the message box
            msg = sprintf('The addon "%s" is not installed. Please install it manually and rerun Simulator_Install.', requiredAddons(i));
            msgbox(msg, 'Error', 'error');
            allToolboxesPresent = false; % Mark missing toolbox
        end
    end

    % Add the custom Simulink library directory to MATLAB path
    libraryPath = fullfile(pwd, 'Tools');
    invkinPath = fullfile(pwd, 'Invkin');
    addpath(libraryPath);
    addpath(invkinPath);
    savepath;
    
    cd(libraryPath)
    slblocks;

    cd(curdir)

    % Final success message if everything is set up correctly
    if allToolboxesPresent
        msgbox('Installation complete.', 'Success');
    end
end
