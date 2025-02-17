function setgui()

global xgui g g2;

def=qs_defines;
    
% gui channel settings
% signal
set(g2.QS_HANDLES.tag_chan_signal,'Value',xgui.chan_signal);
% enable
set(g2.QS_HANDLES.tag_channel,'Value',xgui.chan_enable);
set(g2.QS_HANDLES.tag_channel,'BackgroundColor',xgui.chan_enable_color);
% offset
set(g2.QS_HANDLES.tag_chan_offset,'Value',xgui.chan_offset);
set(g2.QS_HANDLES.tag_chan_offset,'Min',-xgui.chan_offset_maxlev);
set(g2.QS_HANDLES.tag_chan_offset,'Max',xgui.chan_offset_maxlev);
set(g2.QS_HANDLES.tag_chan_offset,'SliderStep',[0.0002 0.002]);
set(g2.QS_HANDLES.tag_chan_offset_disp,'String',num2str(xgui.chan_offset));
set(g2.QS_HANDLES.tag_chan_offset,'Enable',xgui.chan_offset_enable_control);
set(g2.QS_HANDLES.tag_chan_offset_disp,'Enable',xgui.chan_offset2_enable_control);
% zeroise
set(g2.QS_HANDLES.tag_chan_zeroise,'Enable',xgui.chan_zeroise_enable_control);
% range
set(g2.QS_HANDLES.tag_chan_range,'Value',xgui.chan_range);
set(g2.QS_HANDLES.tag_chan_range,'Enable',xgui.chan_range_enable_control);

% gui measurement settings
% sampling rate
set(g2.QS_HANDLES.tag_meas_rate,'Value',xgui.meas_sampling_rate);
% antialiasing
set(g2.QS_HANDLES.tag_aa,'Value',xgui.meas_antialiasing);
set(g2.QS_HANDLES.tag_aa,'Enable',xgui.meas_antialiasing_enable_control);
set(g2.QS_HANDLES.tag_aa,'BackgroundColor',xgui.meas_antialiasing_color);
set(g2.QS_HANDLES.tag_aa,'String',xgui.meas_antialiasing_string);
% frame length
set(g2.QS_HANDLES.tag_meas_len,'Value',xgui.meas_frame_length);
% windowing
set(g2.QS_HANDLES.tag_windowing,'Value',xgui.windowing);
% number of frames
set(g2.QS_HANDLES.tag_meas_num,'Value',xgui.meas_number_of_frames);
% acquisition time
set(g2.QS_HANDLES.tag_meas_time,'String',xgui.meas_acqtime);
% current frame (default setting)
set(g2.QS_HANDLES.tag_meas_num_disp,'String',xgui.meas_current_frame);

% gui scope settings
% scope
set(g2.QS_HANDLES.tag_scope_id,'Value',xgui.scope_scope);
% type
set(g2.QS_HANDLES.tag_scope_type,'Value',xgui.scope_type);
% scale
set(g2.QS_HANDLES.tag_scope_scale,'Value',xgui.scope_scale);
% hold
set(g2.QS_HANDLES.tag_scope_mem,'Value',xgui.scope_hold);
set(g2.QS_HANDLES.tag_scope_mem,'BackgroundColor',xgui.scope_hold_color);
% freeze
set(g2.QS_HANDLES.tag_scope_freeze,'Value',xgui.scope_freeze);
set(g2.QS_HANDLES.tag_scope_freeze,'BackgroundColor',xgui.scope_freeze_color);
% analog in
set(g2.QS_HANDLES.tag_scope_adc_ch0,'Value',xgui.scope_adc_ch0);
set(g2.QS_HANDLES.tag_scope_adc_ch1,'Value',xgui.scope_adc_ch1);
set(g2.QS_HANDLES.tag_scope_adc_ch2,'Value',xgui.scope_adc_ch2);
set(g2.QS_HANDLES.tag_scope_adc_ch3,'Value',xgui.scope_adc_ch3);
set(g2.QS_HANDLES.tag_scope_adc_ch4,'Value',xgui.scope_adc_ch4);
set(g2.QS_HANDLES.tag_scope_adc_ch5,'Value',xgui.scope_adc_ch5);
set(g2.QS_HANDLES.tag_scope_adc_ch6,'Value',xgui.scope_adc_ch6);
set(g2.QS_HANDLES.tag_scope_adc_ch7,'Value',xgui.scope_adc_ch7);

set(g2.QS_HANDLES.tag_scope_adc_ch0,'Enable',xgui.scope_adc_ch0_enable_control);
set(g2.QS_HANDLES.tag_scope_adc_ch1,'Enable',xgui.scope_adc_ch1_enable_control);
set(g2.QS_HANDLES.tag_scope_adc_ch2,'Enable',xgui.scope_adc_ch2_enable_control);
set(g2.QS_HANDLES.tag_scope_adc_ch3,'Enable',xgui.scope_adc_ch3_enable_control);
set(g2.QS_HANDLES.tag_scope_adc_ch4,'Enable',xgui.scope_adc_ch4_enable_control);
set(g2.QS_HANDLES.tag_scope_adc_ch5,'Enable',xgui.scope_adc_ch5_enable_control);
set(g2.QS_HANDLES.tag_scope_adc_ch6,'Enable',xgui.scope_adc_ch6_enable_control);
set(g2.QS_HANDLES.tag_scope_adc_ch7,'Enable',xgui.scope_adc_ch7_enable_control);

set(g2.QS_HANDLES.tag_scope_adc_ch0,'BackgroundColor',xgui.scope_adc_ch0_color);
set(g2.QS_HANDLES.tag_scope_adc_ch1,'BackgroundColor',xgui.scope_adc_ch1_color);
set(g2.QS_HANDLES.tag_scope_adc_ch2,'BackgroundColor',xgui.scope_adc_ch2_color);
set(g2.QS_HANDLES.tag_scope_adc_ch3,'BackgroundColor',xgui.scope_adc_ch3_color);
set(g2.QS_HANDLES.tag_scope_adc_ch4,'BackgroundColor',xgui.scope_adc_ch4_color);
set(g2.QS_HANDLES.tag_scope_adc_ch5,'BackgroundColor',xgui.scope_adc_ch5_color);
set(g2.QS_HANDLES.tag_scope_adc_ch6,'BackgroundColor',xgui.scope_adc_ch6_color);
set(g2.QS_HANDLES.tag_scope_adc_ch7,'BackgroundColor',xgui.scope_adc_ch7_color);
% encoder in
set(g2.QS_HANDLES.tag_scope_enc_ch0,'Value',xgui.scope_enc_ch0);
set(g2.QS_HANDLES.tag_scope_enc_ch1,'Value',xgui.scope_enc_ch1);
set(g2.QS_HANDLES.tag_scope_enc_ch2,'Value',xgui.scope_enc_ch2);
set(g2.QS_HANDLES.tag_scope_enc_ch3,'Value',xgui.scope_enc_ch3);
set(g2.QS_HANDLES.tag_scope_enc_ch4,'Value',xgui.scope_enc_ch4);
set(g2.QS_HANDLES.tag_scope_enc_ch5,'Value',xgui.scope_enc_ch5);
set(g2.QS_HANDLES.tag_scope_enc_ch6,'Value',xgui.scope_enc_ch6);
set(g2.QS_HANDLES.tag_scope_enc_ch7,'Value',xgui.scope_enc_ch7);

set(g2.QS_HANDLES.tag_scope_enc_ch0,'Enable',xgui.scope_enc_ch0_enable_control);
set(g2.QS_HANDLES.tag_scope_enc_ch1,'Enable',xgui.scope_enc_ch1_enable_control);
set(g2.QS_HANDLES.tag_scope_enc_ch2,'Enable',xgui.scope_enc_ch2_enable_control);
set(g2.QS_HANDLES.tag_scope_enc_ch3,'Enable',xgui.scope_enc_ch3_enable_control);
set(g2.QS_HANDLES.tag_scope_enc_ch4,'Enable',xgui.scope_enc_ch4_enable_control);
set(g2.QS_HANDLES.tag_scope_enc_ch5,'Enable',xgui.scope_enc_ch5_enable_control);
set(g2.QS_HANDLES.tag_scope_enc_ch6,'Enable',xgui.scope_enc_ch6_enable_control);
set(g2.QS_HANDLES.tag_scope_enc_ch7,'Enable',xgui.scope_enc_ch7_enable_control);

set(g2.QS_HANDLES.tag_scope_enc_ch0,'BackgroundColor',xgui.scope_enc_ch0_color);
set(g2.QS_HANDLES.tag_scope_enc_ch1,'BackgroundColor',xgui.scope_enc_ch1_color);
set(g2.QS_HANDLES.tag_scope_enc_ch2,'BackgroundColor',xgui.scope_enc_ch2_color);
set(g2.QS_HANDLES.tag_scope_enc_ch3,'BackgroundColor',xgui.scope_enc_ch3_color);
set(g2.QS_HANDLES.tag_scope_enc_ch4,'BackgroundColor',xgui.scope_enc_ch4_color);
set(g2.QS_HANDLES.tag_scope_enc_ch5,'BackgroundColor',xgui.scope_enc_ch5_color);
set(g2.QS_HANDLES.tag_scope_enc_ch6,'BackgroundColor',xgui.scope_enc_ch6_color);
set(g2.QS_HANDLES.tag_scope_enc_ch7,'BackgroundColor',xgui.scope_enc_ch7_color);

% gui trigger settings
% signal
set(g2.QS_HANDLES.tag_trig_signal,'Value',xgui.trigger_signal);
% enable
set(g2.QS_HANDLES.tag_trigger,'Value',xgui.trigger_enable);
set(g2.QS_HANDLES.tag_trigger,'BackgroundColor',xgui.trigger_enable_color);
% type
set(g2.QS_HANDLES.tag_trig_type,'Value',xgui.trigger_type);
% level
set(g2.QS_HANDLES.tag_trig_level,'Value',xgui.trigger_level);
% preroll
set(g2.QS_HANDLES.tag_trig_preroll,'Value',xgui.trigger_preroll);
% lowpass
set(g2.QS_HANDLES.tag_trig_relfreq,'Value',xgui.trigger_relfreq);

% gui experiment control settings
set(g2.QS_HANDLES.tag_inst,'Enable',xgui.inst_enable_control);
set(g2.QS_HANDLES.tag_avg,'Enable',xgui.avg_enable_control);
set(g2.QS_HANDLES.tag_stop,'Enable',xgui.stop_enable_control);
