function checkAddons()
    % Define required addons and hardware support packages
    addons = {'Image Acquisition Toolbox', ...
              'Image Acquisition Toolbox Support Package for OS Generic Video Interface', ...
              'Computer Vision Toolbox', ...
              'Image Processing Toolbox', ...
              'Stateflow', ...
              'MATLAB Coder', ...
              'Simulink Coder', ...
              'Embedded Coder', ...
              'Signal Processing Toolbox'};
          
    hardwareAddons = {'MATLAB Support Package for Raspberry Pi Hardware', ...
                      'Simulink Support Package for Raspberry Pi Hardware'};

    % Combine all addons
    allAddons = [addons, hardwareAddons];

    % List installed add-ons
    installedAddons = matlab.addons.installedAddons();

    % Store the current warning state
    oldWarningState = warning('off', 'backtrace');

    % Check if each specified add-on is installed
    for i = 1:length(allAddons)
        addon = allAddons{i};
        if any(strcmp(installedAddons.Name, addon))
            fprintf('Add-on "%s" is installed.\n', addon);
        else
            warning('Add-on "%s" is NOT installed.', addon);
        end
    end

    % Check for a suitable compiler
    try
        mexSetupOutput = evalc('mex -setup');
        fprintf('A suitable compiler is available.\n');
    catch ME
        if ~isempty(strfind(ME.message, 'Supported compiler not detected.'))
            warning(ME.message);
        else
            warning('An error occurred while checking for a compiler: %s', ME.message);
        end
    end

    % Check for Daheng Galaxy installation
    try
        if isfolder('C:\Program Files (x86)\Daheng Imaging') || ...
           isfolder('C:\Program Files\Daheng Imaging')
            fprintf('Daheng Galaxy software is installed.\n');
        else
            warning(['Daheng Galaxy software is NOT installed. Please run ', ...
                     '"Galaxy_Windows_EN_32bits-64bits_1.12.2106.9032.exe" ', ...
                     'in the camera folder.']);
        end
    catch ME
        warning('An error occurred while checking for Daheng Galaxy software: %s', ME.message);
    end

    % Restore the original warning state
    warning(oldWarningState);
end
