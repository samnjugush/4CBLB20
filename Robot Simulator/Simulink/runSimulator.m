function runSimulator()
    % Get the path of the script's directory
    scriptDir = fileparts(mfilename('fullpath'));
    
    % Define the relative path to the executable
    relativePath = '..\Simulator\Robotarm_simulator.exe';
    
    % Combine the script directory with the relative path
    exePath = fullfile(scriptDir, relativePath);
    
    % Ensure exePath is a character row vector
    exePath = char(exePath);
    
    % Define the executable name (without path) for process checking
    [~, exeName, ext] = fileparts(exePath);
    exeName = [exeName, ext];
    
    % Check if the executable is already running
    if ispc
        % For Windows
        [~, result] = system('tasklist');
        isRunning = contains(result, exeName);
    elseif isunix
        % For Unix-based systems (including Mac)
        [~, result] = system(['pgrep -f "', exeName, '"']);
        isRunning = ~isempty(result);
    else
        error('Unsupported operating system.');
    end
    
    if isRunning
        % Ask user what to do
        choice = questdlg(['The executable "' exeName '" is already running. Having two instances open is not allowed. What would you like to do?'], ...
                          'Executable Running', ...
                          'Restart simulator', 'Keep previous instance', 'Keep previous instance');
        
        % Handle response
        switch choice
            case 'Restart simulator'
                % Kill the existing executable
                if ispc
                    % For Windows
                    system(['taskkill /F /IM "' exeName '"']);
                elseif isunix
                    % For Unix-based systems
                    system(['pkill -f "', exeName, '"']);
                end
            case 'Keep previous instance'
                % Exit the function
                disp('Keeping the existing executable running.');
                return;
            otherwise
                % If dialog is closed or cancelled
                disp('No action taken.');
                return;
        end
    end
    
    % Run the executable asynchronously
    if ispc
        % For Windows
        status = system(['start "" "' exePath '"']);
    elseif isunix
        % For Unix-based systems (including Mac)
        status = system([exePath ' &']);
    else
        error('Unsupported operating system.');
    end
    
    if status ~= 0
        error('Failed to start the executable.');
    end
end
