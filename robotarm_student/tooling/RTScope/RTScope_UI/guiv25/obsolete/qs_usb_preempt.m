function qs_usb_preempt(varargin)

% QS  QadScope experimentation software for use with TUeDACS/1 QAD/AQI modules
%
% QS starts measuring with the default sampling rate of 4096 Hz.
%
% QS(MAXFREQ) starts with a sampling rate of MAXFREQ Hz.
%
% QS(MAXFREQ,DAC_NDOWN) starts with a sampling rate of MAXFREQ Hz and a
% down-sampled D/A-rate of MAXFREQ/(1+DAC_NDOWN) Hz.

clear mex;

maxfreq=4000;
dac_ndown=0;
ical=1;

if nargin>0
    maxfreq=varargin{1,1};
end
if nargin>1
    dac_ndown=varargin{1,2};
end
if nargin>2
    ical=varargin{1,3};
end

%cmd=sprintf('!rxvt -title "QadScope engine" -e preempt_run_usb /usr/local/matlabr14sp2/toolbox/qadscope/qseng_usb_preempt %f %d %d &',maxfreq,dac_ndown,ical);
cmd=sprintf('!konsole -T "QadScope engine" -e preempt_run_usb /usr/local/matlabr14sp2/toolbox/qadscope/qseng_usb_preempt %f %d %d &',maxfreq,dac_ndown,ical);
eval(cmd);

% wait some time
pause(5);

% start gui
qadscope

pause(5)
