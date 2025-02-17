function [FRF_data, hz] = RTScope_figure2FRF_data(figure_name) 

% Convert data figure to FRF data (complex vector)
% Function to get data from a MATLAB figure which is made with RTScope.
% For example, [FRF_data, hz] = convert_data('figure_name') gives as output
% the FRF data (complex vector) and the frequency vector hz.

% Gerard van Hattum 29-11-2022
%
% Control Systems Technology group
% Departement of Mechanical Engineering
% Eindhoven University of Technology

    eval(['open ' figure_name '.fig']);
    subplot(2,1,1);
    D3=get(gca,'Children'); %get the handle of the line object
    XData1=get(D3,'XData');  %get the x data
    too_large=find(XData1>921); % remove frequencies from 921 and higher
    % due to a bug in the random function of RTScope
    XData1(too_large) = [];
    YData1=get(D3,'YData');  %get the y data
    YData1(too_large) = [];
    subplot(2,1,2);
    D4=get(gca,'Children'); %get the handle of the line object
    XData2=get(D4,'XData');  %get the x data
    XData2(too_large) = [];
    YData2=get(D4,'YData');  %get the y data
    YData2(too_large) = [];
    hz=XData1; 
    close;

    AV_Db=YData1;
    AV_abs=10.^(AV_Db/20);
    phase_deg=YData2;
    phase_rad=phase_deg/360*2*pi;

    reel_number=AV_abs.*cos(phase_rad);
    im_number=AV_abs.*sin(phase_rad);
    FRF_data=complex(reel_number,im_number);

end
