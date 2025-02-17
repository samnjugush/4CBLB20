% QS  QadScope experimentation software for use with TUeDACS/
% QS  QadScope experimentation software for use with TUeDACS/1 QAD/AQI modules
% QS starts measuring with the default sampling rate of 4096 Hz.
% QS(MAXFREQ) starts with a sampling rate of MAXFREQ Hz.
% QS(MAXFREQ,DAC_NDOWN) starts with a sampling rate of MAXFREQ Hz and a
% down-sampled D/A-rate of MAXFREQ/(1+DAC_NDOWN) Hz.

function qs(varargin)

%% Check if engine is in simulation mode, if so reset to experiment mode
sim_ind='/home/edrive/ebox/src/E-box/Apps/sim_exp/sim_indicator';

% chech if the simulation indicator file (sim_indicator) is present to see
% if the engine has to be recompiled to experiment mode
if ~exist(sim_ind,'file')==1
    %run compilation script
    system('/usr/local/simexp/experiment/mlsim >/dev/null 2>&1');
end

%%
clear mex;

maxfreq=4096;
frame_length = maxfreq;
dac_ndown=0;

[status, geteth_output] = system('geteth');
netw_interface_name = regexp(geteth_output, 'Ethercat stack connected to ', 'split');
netw_interface_name = netw_interface_name{2}(1:end-1);

geteth_path = sprintf('/home/edrive/ebox/src/Apps/E-Scope/engine/eseng %d %d %d %s &',maxfreq, frame_length, dac_ndown, netw_interface_name);
system(geteth_path);

% start gui
qadscope
