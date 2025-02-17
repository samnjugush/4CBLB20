function qs2gui()

global xgui g;

def=qs_defines;
    
% gui channel settings
% signal
if g.QS_CHAN_SIGNAL>g.QS_MAXCHAN
    xgui.chan_signal=g.QS_CHAN_SIGNAL-2*(def.MAXDEVS-g.QS_NDEVS);
else
    xgui.chan_signal=g.QS_CHAN_SIGNAL;
end
% enable
switch g.QS_CHAN_IN_STATE(g.QS_CHAN_SIGNAL)
case 0
    xgui.chan_enable=0;
    xgui.chan_enable_color=def.COLOR_GREY;
case 1
    xgui.chan_enable=1;
    %fix color: xgui.chan_enable_color=def.COLOR_YELLOW;
    xgui.chan_enable_color='green';
end
% offset
xgui.chan_offset=g.QS_CHAN_IN_OFFSET(g.QS_CHAN_SIGNAL);
current_range=g.QS_CHAN_IN_RANGE(g.QS_CHAN_SIGNAL);
xgui.chan_offset_maxlev=g.QS_MAXLEV(current_range);
% offset control disabled if signal disabled or if signal is of encoder type
if (~xgui.chan_enable) | (g.QS_CHAN_SIGNAL>g.QS_MAXCHAN)
    xgui.chan_offset_enable_control='off';
    xgui.chan_offset2_enable_control='off';
else
    xgui.chan_offset_enable_control='on';
    xgui.chan_offset2_enable_control='on';
end
% zeroise control disabled if signal disabled
switch xgui.chan_enable
case 0
    xgui.chan_zeroise_enable_control='off';
case 1
    xgui.chan_zeroise_enable_control='on';
end
% range
xgui.chan_range=g.QS_CHAN_IN_RANGE(g.QS_CHAN_SIGNAL);
if (xgui.chan_range==8) | (xgui.chan_range==9)
    xgui.chan_range_enable_control='off';
else
    xgui.chan_range_enable_control='on';
end

% gui measurement settings
% sampling rate
xgui.meas_sampling_rate=g.QS_MEAS_RATE;
% antialiasing
xgui.meas_antialiasing=min(1,g.QS_AACONFIG);
if g.QS_AQI(g.QS_CURRENT_DEVICE)==1
    xgui.meas_antialiasing_enable_control='on';
else
    xgui.meas_antialiasing_enable_control='off';
end
switch g.QS_AACONFIG
case 0
    xgui.meas_antialiasing_color=def.COLOR_GREY;
    xgui.meas_antialiasing_string='off';
case 1
    %fix color: xgui.meas_antialiasing_color=def.COLOR_YELLOW;
    xgui.meas_antialiasing_color='green';
    xgui.meas_antialiasing_string='1';    
case 2
    xgui.meas_antialiasing_color=def.COLOR_GREEN;
    xgui.meas_antialiasing_string='2';    
end
% frame length
xgui.meas_frame_length=g.QS_MEAS_LEN;
% windowing
xgui.windowing=g.QS_WINDOW+1;
% number of frames
xgui.meas_number_of_frames=g.QS_MEAS_NUM;
% acquisition time
xgui.meas_acqtime=g.QS_MEAS_TIME;
% current frame
xgui.meas_current_frame=num2str(g.QS_IFRAME);

% gui scope settings
% scope
xgui.scope_scope=g.QS_SCOPE_ID;
% type
xgui.scope_type=g.QS_SCOPE_TYPE(g.QS_SCOPE_ID);
% scale
xgui.scope_scale=g.QS_SCOPE_SCALE(g.QS_SCOPE_ID);
% hold
xgui.scope_hold=g.QS_SCOPE_MEM(g.QS_SCOPE_ID);
switch xgui.scope_hold
case 0
    xgui.scope_hold_color=def.COLOR_GREY;
case 1
    %fix color: xgui.scope_hold_color=def.COLOR_YELLOW;
    xgui.scope_hold_color='green';
end
% freeze
xgui.scope_freeze=g.QS_SCOPE_FREEZE(g.QS_SCOPE_ID);
switch xgui.scope_freeze
case 0
    xgui.scope_freeze_color=def.COLOR_GREY;
case 1
    %fix color: xgui.scope_freeze_color=def.COLOR_YELLOW;
    xgui.scope_freeze_color='green';
end
% analog in
for i=1:g.QS_MAXCHAN,
    switch g.QS_CHAN_IN_STATE(i)
    case 0
	cmd1=sprintf('xgui.scope_adc_ch%d=0;',i-1);
	cmd2=sprintf('xgui.scope_adc_ch%d_enable_control=''off'';',i-1);
    case 1
	cmd1=sprintf('xgui.scope_adc_ch%d=g.QS_SCOPE_CHAN(g.QS_SCOPE_ID,%d);',i-1,i);
	cmd2=sprintf('xgui.scope_adc_ch%d_enable_control=''on'';',i-1);
    end
    eval(cmd1);
    eval(cmd2);

%   color
    cmd1=sprintf('xgui.scope_adc_ch%d_color=def.COLOR_GREY;',i-1);    
    eval(cmd1);
    
    switch g.QS_SCOPE_TYPE(g.QS_SCOPE_ID)
    case {def.QSST_PSD_CROSS, def.QSST_FRF_MOD, def.QSST_FRF_PHS, def.QSST_COHERENCE, def.QSST_FRF_OL_MOD, def.QSST_FRF_OL_PHS, def.QSST_FRF_OL_NYQ}
	if i==g.QS_IN
	    cmd1=sprintf('xgui.scope_adc_ch%d_color=def.COLOR_RED;',i-1);
	    eval(cmd1);
	    cmd1=sprintf('xgui.scope_adc_ch%d=1;',i-1);
	    eval(cmd1);
	    cmd1=sprintf('xgui.scope_adc_ch%d_enable_control=''on'';',i-1);
	    eval(cmd1);
	end

	if i==g.QS_OUT
	    cmd1=sprintf('xgui.scope_adc_ch%d_color=def.COLOR_GREEN;',i-1);
	    eval(cmd1);
	    cmd1=sprintf('xgui.scope_adc_ch%d=1;',i-1);
	    eval(cmd1);
	    cmd1=sprintf('xgui.scope_adc_ch%d_enable_control=''on'';',i-1);
	    eval(cmd1);
	end
    end
end

% encoder in
for i=1:g.QS_MAXCHAN,
    switch g.QS_CHAN_IN_STATE(g.QS_MAXCHAN+i)
    case 0
	cmd1=sprintf('xgui.scope_enc_ch%d=0;',i-1);    
	cmd2=sprintf('xgui.scope_enc_ch%d_enable_control=''off'';',i-1);
    case 1
	cmd1=sprintf('xgui.scope_enc_ch%d=g.QS_SCOPE_CHAN(g.QS_SCOPE_ID,g.QS_MAXCHAN+%d);',i-1,i);
	cmd2=sprintf('xgui.scope_enc_ch%d_enable_control=''on'';',i-1);
    end
    eval(cmd1);
    eval(cmd2);
    
%   color
    cmd1=sprintf('xgui.scope_enc_ch%d_color=def.COLOR_GREY;',i-1);
    eval(cmd1);
    
    switch g.QS_SCOPE_TYPE(g.QS_SCOPE_ID)
    case {def.QSST_PSD_CROSS, def.QSST_FRF_MOD, def.QSST_FRF_PHS, def.QSST_COHERENCE}
	if (g.QS_MAXCHAN+i)==g.QS_IN
	    cmd1=sprintf('xgui.scope_enc_ch%d_color=def.COLOR_RED;',i-1);
	    eval(cmd1);
	    cmd1=sprintf('xgui.scope_enc_ch%d=1;',i-1);
	    eval(cmd1);
	    cmd1=sprintf('xgui.scope_enc_ch%d_enable_control=''on'';',i-1);
	    eval(cmd1);
	end

	if (g.QS_MAXCHAN+i)==g.QS_OUT
	    cmd1=sprintf('xgui.scope_enc_ch%d_color=def.COLOR_GREEN;',i-1);
	    eval(cmd1);
	    cmd1=sprintf('xgui.scope_enc_ch%d=1;',i-1);
	    eval(cmd1);
	    cmd1=sprintf('xgui.scope_enc_ch%d_enable_control=''on'';',i-1);
	    eval(cmd1);
	end
    end
end

% gui trigger settings
% signal
xgui.trigger_signal=g.QS_TRIG_SIGNAL+1;
% enable
switch g.QS_TRIGGER
case 0
    xgui.trigger_enable=0;
    xgui.trigger_enable_color=def.COLOR_GREY;
case 1
    xgui.trigger_enable=1;
    %fix color: xgui.trigger_enable_color=def.COLOR_YELLOW;
    xgui.trigger_enable_color='green';
end
% type
xgui.trigger_type=g.QS_TRIG_TYPE+1;
% level
xgui.trigger_level=g.QS_TRIG_LEVEL;
% preroll
xgui.trigger_preroll=g.QS_TRIG_PREROLL;
% lowpass
xgui.trigger_relfreq=g.QS_TRIG_RELFREQ;

% experiment control settings
switch g.QS_RUNNING
case 0
    xgui.inst_enable_control='on';
    xgui.avg_enable_control='on';
    xgui.stop_enable_control='off';
case 1
    xgui.inst_enable_control='off';
    xgui.avg_enable_control='off';
    xgui.stop_enable_control='on';
end
