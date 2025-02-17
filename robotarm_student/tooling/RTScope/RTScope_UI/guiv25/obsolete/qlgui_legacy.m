function varargout = qlgui(varargin)
% QLGUI Application M-file for qlgui.fig
%    FIG = QLGUI launch qlgui GUI.
%    QLGUI('callback_name', ...) invoke the named callback.

global g g2 xgui;

def=qs_defines;

if nargin == 0  % LAUNCH GUI

    warning off;
    fig = openfig(mfilename,'reuse');
    warning on;
        
%   Generate a structure of handles to pass to callbacks, and store it. 
    handles = guihandles(fig);
    guidata(fig, handles);

    g2.QS_HANDLES=handles;
    g2.QS_FIG=fig;
    g.QS_GUI_OPEN=1;

%   set sampling rates in gui
    newfreqs=cell(g.QS_NRATES,1);
    for i=1:g.QS_NRATES,
        newfreqs{i,1}=[num2str(g.QS_MSAMPRATE(i)) ' Hz'];
    end
%   newfreqs
    set(handles.tag_meas_rate,'String',newfreqs);

%   set frame lengths in gui
    n=max(size(g.QS_MFRAMELEN));
    frmlens=cell(n,1);
    for i=1:n,
	frmlens{i,1}=[num2str(g.QS_MFRAMELEN(i))];    
    end
    set(handles.tag_meas_len,'String',frmlens);

%   adjust selectable adcq trigger channels in gui
    trig_channels=cell(2*g.QS_NDEVS,1);
    for i=1:2*g.QS_NDEVS,
        % fix1: msg=sprintf('analog in ch %d',i-1);
        msg=sprintf('Analog in ch %d',i);
        trig_channels{i,1}=msg;
    end
    set(handles.tag_trig_signal,'String',trig_channels);

%   adjust selectable adc/enc channels in gui
    adc_enc_channels=cell(4*g.QS_NDEVS,1);
    for i=1:2*g.QS_NDEVS,
	%fix2: msg=sprintf('analog in ch %d',i-1);
        msg=sprintf('Analog in ch %d',i);
	adc_enc_channels{i,1}=msg;
    end
    for i=2*g.QS_NDEVS+1:4*g.QS_NDEVS,
        % fix3: msg=sprintf('encoder in ch %d',i-2*g.QS_NDEVS-1);
        msg=sprintf('Enc/PWM in ch %d',i-g.QS_NDEVS-1);
        adc_enc_channels{i,1}=msg;
    end
    set(handles.tag_chan_signal,'String',adc_enc_channels);
    
%   disable all channels
    for i=1:2*g.QS_NDEVS,
        tde_gate_m(def.CALL_TDE_SET_ADC_STATE,0,i-1);
        g.QS_CHAN_IN_STATE(i)=tde_gate_m(def.CALL_TDE_GET_ADC_STATE,i-1);
    end
    for i=1:2*g.QS_NDEVS,
        tde_gate_m(def.CALL_TDE_SET_ENC_STATE,0,i-1);
	g.QS_CHAN_IN_STATE(g.QS_MAXCHAN+i)=tde_gate_m(def.CALL_TDE_GET_ENC_STATE,i-1);
    end
    for i=1:2*g.QS_NDEVS,
        tde_gate_m(def.CALL_TDE_SET_DAC_STATE,0,i-1);
	g.QS_CHAN_OUT_STATE(i)=tde_gate_m(def.CALL_TDE_GET_DAC_STATE,i-1);
    end

%   enable first analog in channel on scope 1
    tde_gate_m(def.CALL_TDE_SET_ADC_STATE,1,0);
    g.QS_CHAN_IN_STATE(1)=tde_gate_m(def.CALL_TDE_GET_ADC_STATE,0);
    g.QS_SCOPE_CHAN(1)=1;

%   no offsets
    for i=1:2*g.QS_NDEVS,
        tde_gate_m(def.CALL_TDE_SET_ADC_OFFSET,0.0,i-1);
	g.QS_CHAN_IN_OFFSET(i)=tde_gate_m(def.CALL_TDE_GET_ADC_OFFSET,i-1);
    end
    for i=1:2*g.QS_NDEVS,,
%       tde_gate_m(def.CALL_TDE_SET_DAC_OFFSET,0.0,i-1);
%	g.QS_CHAN_OUT_OFFSET(i)=tde_gate_m(def.CALL_TDE_GET_DAC_OFFSET,i-1);
	g.QS_CHAN_OUT_OFFSET(i)=0.0;
    end
    
%   get range of adc channels
    for i=1:2*g.QS_NDEVS,
	ilink=get_link_id(g.QS_CHAN_SIGNAL);
	if g.QS_AQI(ilink+1)==0
%	    QAD has fixed range
	    g.QS_CHAN_IN_RANGE(i)=8;
	else
%	    AQI/MicroGiant has variable range
    	    g.QS_CHAN_IN_RANGE(i)=tde_gate_m(def.CALL_TD_GET_RANGE,g.QS_CHAN_SIGNAL-1,0)+1;
	end
    end

    if g.QS_IS_SIMULINK==1
%	extra scope types of rtscope
	ttt=get(handles.tag_scope_type,'String');
        ttt{def.QSST_FRF_OL_MOD}='sens2ol: modulus';
        ttt{def.QSST_FRF_OL_PHS}='sens2ol: phase';
        ttt{def.QSST_FRF_OL_NYQ}='sens2ol: nyquist';
	set(handles.tag_scope_type,'String',ttt);
    end
    
%   sync aa-filter config for AQI's
    sync_aliasing(handles.tag_aa,g.QS_MSAMPRATE(g.QS_MEAS_RATE),g.QS_AACONFIG);

%   update gui
    gupdate;

    if nargout > 0
		varargout{1} = fig;
	end

elseif ischar(varargin{1}) % INVOKE NAMED SUBFUNCTION OR CALLBACK

	try
		[varargout{1:nargout}] = feval(varargin{:}); % FEVAL switchyard
	catch
		disp(lasterr);
	end

end


%| ABOUT CALLBACKS:
%| GUIDE automatically appends subfunction prototypes to this file, and 
%| sets objects' callback properties to call them through the FEVAL 
%| switchyard above. This comment describes that mechanism.
%|
%| Each callback subfunction declaration has the following form:
%| <SUBFUNCTION_NAME>(H, EVENTDATA, HANDLES, VARARGIN)
%|
%| The subfunction name is composed using the object's Tag and the 
%| callback type separated by '_', e.g. 'slider2_Callback',
%| 'figure1_CloseRequestFcn', 'axis1_ButtondownFcn'.
%|
%| H is the callback object's handle (obtained using GCBO).
%|
%| EVENTDATA is empty, but reserved for future use.
%|
%| HANDLES is a structure containing handles of components in GUI using
%| tags as fieldnames, e.g. handles.figure1, handles.slider2. This
%| structure is created at GUI startup using GUIHANDLES and stored in
%| the figure's application data using GUIDATA. A copy of the structure
%| is passed to each callback.  You can store additional information in
%| this structure at GUI startup, and you can change the structure
%| during callbacks.  Call guidata(h, handles) after changing your
%| copy to replace the stored original so that subsequent callbacks see
%| the updates. Type "help guihandles" and "help guidata" for more
%| information.
%|
%| VARARGIN contains any extra arguments you have passed to the
%| callback. Specify the extra arguments by editing the callback
%| property in the inspector. By default, GUIDE sets the property to:
%| <MFILENAME>('<SUBFUNCTION_NAME>', gcbo, [], guidata(gcbo))
%| Add any extra arguments after the last argument, before the final
%| closing parenthesis.

% --------------------------------------------------------------------
function varargout = cb_inst(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_IFRAME=1;
g.QS_AVG_ON=0;

reset_trigger;

turnon;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_avg(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_IFRAME=1;
g.QS_AVG_ON=1;

reset_trigger;

turnon;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_stop(h, eventdata, handles, varargin)

global g;

def=qs_defines;

turnoff;

g.QS_IFRAME=1;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_exit(h, eventdata, handles, varargin)

global g;

g.QS_EXIT=1;

% --------------------------------------------------------------------
function varargout = cb_trig_signal(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_TRIG_SIGNAL=get(handles.tag_trig_signal,'Value')-1;

reset_trigger;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_trig_type(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_TRIG_TYPE=get(handles.tag_trig_type,'Value')-1;

reset_trigger;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_trig_level(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_TRIG_LEVEL=get(handles.tag_trig_level,'Value');

reset_trigger;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_trig_preroll(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_TRIG_PREROLL=get(handles.tag_trig_preroll,'Value');

reset_trigger;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_trig_relfreq(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_TRIG_RELFREQ=get(handles.tag_trig_relfreq,'Value');

reset_trigger;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_trigger(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_TRIGGER=get(handles.tag_trigger,'Value');

if g.QS_TRIGGER==1
%   turn on trigger
    reset_trigger;
else
%   turn off trigger
    tde_gate_m(def.CALL_TDE_TRIGGER_OFF); 
end

gupdate;

% --------------------------------------------------------------------
function varargout = cb_meas_rate(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_MEAS_RATE=get(handles.tag_meas_rate,'Value');
i=g.QS_MEAS_RATE;
while (g.QS_MSAMPRATE(i)>g.QS_MAXFREQ) & (i<max(size(g.QS_MSAMPRATE)))
    i=i+1;
end
g.QS_MEAS_RATE=i;

g.QS_NDOWN=max(round(g.QS_MAXFREQ/g.QS_MSAMPRATE(g.QS_MEAS_RATE))-1,0);

if g.QS_AVG_ON==0
%   pause measurement if necessary
    if g.QS_RUNNING==1
        tde_gate_m(def.CALL_TDE_PAUSE,1);
    end
else
    turnoff;
    
    g.QS_IFRAME=1;
end

tde_gate_m(def.CALL_TDE_SET_NDOWN,g.QS_NDOWN);

if g.QS_AACONFIG>0
%   sync aa-filter settings
    sync_aliasing(handles.tag_aa,g.QS_MSAMPRATE(g.QS_MEAS_RATE),g.QS_AACONFIG);
end

% update gen frequency settings before restarting measurement!
sync_gen_frequency_settings;

if g.QS_AVG_ON==0
%   continue measurement
    if g.QS_RUNNING==1
        tde_gate_m(def.CALL_TDE_PAUSE,0);
    end
end

g.QS_MEAS_TIME=num2str(g.QS_NSAMP/g.QS_MSAMPRATE(g.QS_MEAS_RATE));

g.QS_REDRAW=1;
g.QS_IFRAME=1;
g.QS_VALID=0;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_antialiasing(h, eventdata, handles, varargin)

global g;

% adapt aa-filter config
g.QS_AACONFIG=g.QS_AACONFIG+1;
if g.QS_AACONFIG>2
    g.QS_AACONFIG=0;
end

g.QS_MEAS_RATE=get(handles.tag_meas_rate,'Value');
sync_aliasing(handles.tag_aa,g.QS_MSAMPRATE(g.QS_MEAS_RATE),g.QS_AACONFIG);

% --------------------------------------------------------------------
function varargout = cb_windowing(h, eventdata, handles, varargin)

global g;

def=qs_defines;

istate=get(handles.tag_windowing,'Value');

g.QS_WINDOW=istate-1;

% --------------------------------------------------------------------
function varargout = cb_meas_len(h, eventdata, handles, varargin)

global g;

def=qs_defines;

if g.QS_AVG_ON==0
%   pause measurement if necessary
    if g.QS_RUNNING==1
        tde_gate_m(def.CALL_TDE_PAUSE,1);
    end
else
    turnoff;
    g.QS_IFRAME=1;
end

g.QS_MEAS_LEN=get(handles.tag_meas_len,'Value');
g.QS_NSAMP=min(g.QS_MFRAMELEN(g.QS_MEAS_LEN),g.QS_MAXFRAME);
tde_gate_m(def.CALL_TDE_SET_NSAMP,g.QS_NSAMP);

% update gen frequency settings before restarting measurement!
sync_gen_frequency_settings;

if g.QS_AVG_ON==0
%   continue measurement
    if g.QS_RUNNING==1
        tde_gate_m(def.CALL_TDE_PAUSE,0);
    end
end

g.QS_MEAS_TIME=num2str(g.QS_NSAMP/g.QS_MSAMPRATE(g.QS_MEAS_RATE));

g.QS_REDRAW=1;
g.QS_IFRAME=1;
g.QS_VALID=0;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_meas_num(h, eventdata, handles, varargin)

global g;

g.QS_MEAS_NUM=get(handles.tag_meas_num,'Value');

turnoff;

g.QS_IFRAME=1;
g.QS_VALID=0;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_chan_signal(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_CHAN_SIGNAL=get(handles.tag_chan_signal,'Value');

% correct chan id for number of TUeDACS devices
if g.QS_CHAN_SIGNAL>2*g.QS_NDEVS
    g.QS_CHAN_SIGNAL=g.QS_CHAN_SIGNAL+2*(def.MAXDEVS-g.QS_NDEVS);
end

if g.QS_CHAN_SIGNAL<=g.QS_MAXCHAN
%   selected channel is of type adc
    g.QS_CHAN_IN_STATE(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TDE_GET_ADC_STATE,g.QS_CHAN_SIGNAL-1);
    g.QS_CHAN_IN_OFFSET(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TDE_GET_ADC_OFFSET,g.QS_CHAN_SIGNAL-1);
else
%   selected channel is of type enc
    g.QS_CHAN_IN_STATE(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TDE_GET_ENC_STATE,g.QS_CHAN_SIGNAL-1-g.QS_MAXCHAN);
end

% get current device
g.QS_CURRENT_DEVICE=get_link_id(g.QS_CHAN_SIGNAL)+1;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_channel(h, eventdata, handles, varargin)

global g;

def=qs_defines;

istate=get(handles.tag_channel,'Value');

if g.QS_CHAN_SIGNAL<=g.QS_MAXCHAN
    tde_gate_m(def.CALL_TDE_SET_ADC_STATE,istate,g.QS_CHAN_SIGNAL-1);
    g.QS_CHAN_IN_STATE(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TDE_GET_ADC_STATE,g.QS_CHAN_SIGNAL-1);
else
    tde_gate_m(def.CALL_TDE_SET_ENC_STATE,istate,g.QS_CHAN_SIGNAL-1-g.QS_MAXCHAN);
    g.QS_CHAN_IN_STATE(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TDE_GET_ENC_STATE,g.QS_CHAN_SIGNAL-1-g.QS_MAXCHAN);
end

if g.QS_CHAN_SIGNAL<=g.QS_MAXCHAN
    for i=1:g.QS_MAXSCOPE,
        g.QS_SCOPE_CHAN(i,g.QS_CHAN_SIGNAL)=0;           
    end
else
    for i=1:g.QS_MAXSCOPE,
        g.QS_SCOPE_CHAN(i,g.QS_CHAN_SIGNAL)=0;
    end
end

gupdate;

% redraw
g.QS_REDRAW=1;

% --------------------------------------------------------------------
function varargout = cb_chan_offset(h, eventdata, handles, varargin)

global g;

def=qs_defines;

offset=get(handles.tag_chan_offset,'Value');
tde_gate_m(def.CALL_TDE_SET_ADC_OFFSET,offset,g.QS_CHAN_SIGNAL-1);
g.QS_CHAN_IN_OFFSET(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TDE_GET_ADC_OFFSET,g.QS_CHAN_SIGNAL-1);

gupdate;

% --------------------------------------------------------------------
function varargout = cb_chan_offset2(h, eventdata, handles, varargin)

global g;

def=qs_defines;

offset=str2num(get(handles.tag_chan_offset_disp,'String'));

current_range=g.QS_CHAN_IN_RANGE(g.QS_CHAN_SIGNAL);
offset=max(-g.QS_MAXLEV(current_range),min(g.QS_MAXLEV(current_range),offset))
tde_gate_m(def.CALL_TDE_SET_ADC_OFFSET,offset,g.QS_CHAN_SIGNAL-1);
g.QS_CHAN_IN_OFFSET(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TDE_GET_ADC_OFFSET,g.QS_CHAN_SIGNAL-1);

gupdate;

% --------------------------------------------------------------------
function varargout = cb_chan_zeroise(h, eventdata, handles, varargin)

global g;

def=qs_defines;

if g.QS_CHAN_SIGNAL<=g.QS_MAXCHAN
    offset=0.0;
    tde_gate_m(def.CALL_TDE_SET_ADC_OFFSET,offset,g.QS_CHAN_SIGNAL-1);
    g.QS_CHAN_IN_OFFSET(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TDE_GET_ADC_OFFSET,g.QS_CHAN_SIGNAL-1);
else
%   if g.QS_IS_SIMULINK~=1
    tde_gate_m(def.CALL_TDE_INIT_ENC,g.QS_CHAN_SIGNAL-1-g.QS_MAXCHAN);
%   end
end

gupdate;

% --------------------------------------------------------------------
function varargout = cb_chan_range(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_CHAN_SIGNAL=get(handles.tag_chan_signal,'Value');
fprintf('range = %d\n', get(handles.tag_chan_range, 'Value'));
% set range
if g.QS_CHAN_SIGNAL<=g.QS_MAXCHAN
    ilink=get_link_id(g.QS_CHAN_SIGNAL);    
    ioff=2*ilink;
    irange=get(handles.tag_chan_range,'Value');
    tde_gate_m(def.CALL_TD_SET_RANGE,irange-1,g.QS_CHAN_SIGNAL-1-ioff,ilink);
    g.QS_CHAN_IN_RANGE(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TD_GET_RANGE,g.QS_CHAN_SIGNAL-1-ioff,ilink)+1;
%   adapt offset to range
    offset=str2num(get(handles.tag_chan_offset_disp,'String'));
    current_range=g.QS_CHAN_IN_RANGE(g.QS_CHAN_SIGNAL);
    offset=max(-g.QS_MAXLEV(current_range),min(g.QS_MAXLEV(current_range),offset));
    tde_gate_m(def.CALL_TDE_SET_ADC_OFFSET,offset,g.QS_CHAN_SIGNAL-1);
    g.QS_CHAN_IN_OFFSET(g.QS_CHAN_SIGNAL)=tde_gate_m(def.CALL_TDE_GET_ADC_OFFSET,g.QS_CHAN_SIGNAL-1);
end

reset_trigger;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_stream(h, eventdata, handles, varargin)

% --------------------------------------------------------------------
function varargout = cb_save_last(h, eventdata, handles, varargin)

global g data;

def=qs_defines;

% stop measurement before loading
turnoff;
g.QS_IFRAME=1;

% ask file name
[filename,pathname]=uiputfile('*.mat', 'Save');

if filename~=0
%   check filename for extension

    l=max(size(filename));
    isdot=filename(max(1,l-3));
    if strcmp(isdot,'.')
        filename=filename(1:l-4);
    end

%   store present path
    present_path=cd;

%   change path and write file
    eval(sprintf('cd %s',pathname));
    eval(sprintf('save %s.mat filename',filename));
end

lfname=filename;

for i=1:g.QS_MAXCHAN*2,
    if g.QS_CHAN_IN_STATE(i)==1

        if i<=g.QS_MAXCHAN
            prefix='adc';
            idx=i;
        else
            prefix='enc';
            idx=i-g.QS_MAXCHAN;
        end
        
%       save time
        eval(sprintf('%s_time=data.TIM_XT;',prefix));
        eval(sprintf('save %s %s_time -append',lfname,prefix));
        
%       save frame
        eval(sprintf('%s_ch%d_frame=data.XT(i,:);',prefix,idx-1));
        eval(sprintf('save %s %s_ch%d_frame -append',lfname,prefix,idx-1));
        
%       save frequency
        eval(sprintf('%s_freq_xf=data.FREQ_XF'';',prefix));
        eval(sprintf('save %s %s_freq_xf -append',lfname,prefix));
        
%       save dft modulus
        eval(sprintf('%s_ch%d_xf_mod=data.XF_MOD(i,:);',prefix,idx-1));
        eval(sprintf('save %s %s_ch%d_xf_mod -append',lfname,prefix,idx-1));

%       save dft phase
        eval(sprintf('%s_ch%d_xf_phs=data.XF_PHS(i,:);',prefix,idx-1));
        eval(sprintf('save %s %s_ch%d_xf_phs -append',lfname,prefix,idx-1));
        
%       save frequency
        eval(sprintf('%s_freq_psd_auto=data.FREQ_PSD_AUTO'';',prefix));
        eval(sprintf('save %s %s_freq_psd_auto -append',lfname,prefix));
       
%       save psd_auto
        eval(sprintf('%s_ch%d_psd_auto=data.PSD_AUTO(i,:);',prefix,idx-1));
        eval(sprintf('save %s %s_ch%d_psd_auto -append',lfname,prefix,idx-1));
 
        if (g.QS_IN==i) & ((g.QS_SCOPE_DOFRF(1)==1 | g.QS_SCOPE_DOFRF(2)==1));
            if g.QS_OUT<=g.QS_MAXCHAN
                prefix2='adc';
                idx2=g.QS_OUT;
            else
                prefix2='enc';
                idx2=g.QS_OUT-g.QS_MAXCHAN;
            end
        
%           save frequency
            freq_frf=data.FREQ_FRF;
            freq_frf=freq_frf';
            eval(sprintf('save %s freq_frf -append',lfname));
            
%           save frf_mod
            eval(sprintf('%s_ch%d_%s_ch%d_frf_mod=data.FRF_MOD'';',prefix,idx-1,prefix2,idx2-1));
            eval(sprintf('save %s %s_ch%d_%s_ch%d_frf_mod -append',lfname,prefix,idx-1,prefix2,idx2-1));
            
%           save frf_phs
            eval(sprintf('%s_ch%d_%s_ch%d_frf_phs=data.FRF_PHS'';',prefix,idx-1,prefix2,idx2-1));
            eval(sprintf('save %s %s_ch%d_%s_ch%d_frf_phs -append',lfname,prefix,idx-1,prefix2,idx2-1));
            
%           save psd_cross
            eval(sprintf('%s_ch%d_%s_ch%d_psd_cross=data.PSD_CROSS'';',prefix,idx-1,prefix2,idx2-1));
            eval(sprintf('save %s %s_ch%d_%s_ch%d_psd_cross -append',lfname,prefix,idx-1,prefix2,idx2-1));
            
%           save coh
            eval(sprintf('%s_ch%d_%s_ch%d_coherence=data.COH'';',prefix,idx-1,prefix2,idx2-1));
            eval(sprintf('save %s %s_ch%d_%s_ch%d_coherence -append',lfname,prefix,idx-1,prefix2,idx2-1));
        end
    end
end

% restore path
eval(sprintf('cd %s',present_path));

gupdate;

% --------------------------------------------------------------------
function varargout = cb_fun_gen(h, eventdata, handles, varargin)

qlgen;

% --------------------------------------------------------------------
function varargout = cb_load(h, eventdata, handles, varargin)

global g;

def=qs_defines;

% stop measurement before loading
turnoff;
g.QS_IFRAME=1;

% close generator window if open (because gen save has not been implemented yet!)
if g.QSG_GEN_OPEN
    close(g.QSG_FIG);
    g.QSG_GEN_OPEN=0;
end

% backup globals
bak_g=g;

% ask file name
[filename,pathname]=uigetfile('*.qss', 'Load');

if filename~=0
%   store present path
    present_path=cd;

%   change path and read file
    eval(sprintf('cd %s',pathname));
    if filename~=0
        eval(sprintf('load -mat %s',filename));
    end

%   restore path
    eval(sprintf('cd %s',present_path));

%   consistency check
    ok=1;
    if g.QS_NDEVS~=bak_g.QS_NDEVS
	ok=0;
    end
    
    for i=1:def.MAXDEVS,
	if g.QS_AQI(i)~=bak_g.QS_AQI(i)
	    ok=0;
	end
    end

    if ~ok
	msgbox('File not consistent with current hardware configuration!');
%	restore globals
	g=bak_g;
    else
%	no generator window
	g.QSG_GEN_OPEN=0;    
    
%   	overwrite restored MAXFREQ with current one!
	g.QS_MAXFREQ=bak_g.QS_MAXFREQ;

%   	synchronize hardware with restored settings
	for i=1:2*g.QS_NDEVS,
	    tde_gate_m(def.CALL_TDE_SET_ADC_STATE,g.QS_CHAN_IN_STATE(i),i-1);	
    	    g.QS_CHAN_IN_STATE(i)=tde_gate_m(def.CALL_TDE_GET_ADC_STATE,i-1);
	end
	for i=1:2*g.QS_NDEVS,
    	    tde_gate_m(def.CALL_TDE_SET_ENC_STATE,g.QS_CHAN_IN_STATE(g.QS_MAXCHAN+i),i-1);
	    g.QS_CHAN_IN_STATE(g.QS_MAXCHAN+i)=tde_gate_m(def.CALL_TDE_GET_ENC_STATE,i-1);
	end
%	for i=1:2*g.QS_NDEVS,
%    	    tde_gate_m(def.CALL_TDE_SET_DAC_STATE,g.QS_CHAN_OUT_STATE(i),i-1);
%	    g.QS_CHAN_OUT_STATE(i)=tde_gate_m(def.CALL_TDE_GET_DAC_STATE,i-1);
%	end
	g.QS_CHAN_OUT_STATE=bak_g.QS_CHAN_OUT_STATE;
%   	offsets
	for i=1:2*g.QS_NDEVS,
            tde_gate_m(def.CALL_TDE_SET_ADC_OFFSET,g.QS_CHAN_IN_OFFSET(i),i-1);
	    g.QS_CHAN_IN_OFFSET(i)=tde_gate_m(def.CALL_TDE_GET_ADC_OFFSET,i-1);
	end
	for i=1:2*g.QS_NDEVS,,
%           tde_gate_m(def.CALL_TDE_SET_DAC_OFFSET,g.QS_CHAN_OUT_OFFSET(i),i-1);
%	    g.QS_CHAN_OUT_OFFSET(i)=tde_gate_m(def.CALL_TDE_GET_DAC_OFFSET,i-1);
	end
	g.QS_CHAN_OUT_OFFSET=bak_g.QS_CHAN_OUT_OFFSET;
%   	range of adc channels
	for i=1:2*g.QS_NDEVS,
	    ilink=get_link_id(g.QS_CHAN_SIGNAL);
	    if g.QS_AQI(ilink+1)==1
		tde_gate_m(def.CALL_TD_SET_RANGE,g.QS_CHAN_IN_RANGE(i)-1,g.QS_CHAN_SIGNAL-1,0);
    		g.QS_CHAN_IN_RANGE(i)=tde_gate_m(def.CALL_TD_GET_RANGE,g.QS_CHAN_SIGNAL-1,0)+1;
%		sync filter settings
		sync_aliasing(handles.tag_aa,g.QS_MSAMPRATE(g.QS_MEAS_RATE),g.QS_AACONFIG);
	    end
	end

%	write sampling rate to engine
	tde_gate_m(def.CALL_TDE_SET_NDOWN,g.QS_NDOWN);

%	write number of samples to engine
	tde_gate_m(def.CALL_TDE_SET_NSAMP,g.QS_NSAMP);
	
%	reset trigger
	reset_trigger;	
    end
end

gupdate;

g.QS_REDRAW=1;
g.QS_IFRAME=1;
g.QS_VALID=0;

% --------------------------------------------------------------------
function varargout = cb_save(h, eventdata, handles, varargin)

global g data;

def=qs_defines;

% stop measurement before saving
turnoff;
g.QS_IFRAME=1;
    
irange=zeros(g.QS_MAXCHAN,1);
for i=1:g.QS_MAXCHAN,
    ilink=get_link_id(i);
    ioff=2*ilink;
%    if g.QS_IS_SIMULINK==1
%	irange(i)=1;
%    else
	irange(i)=tde_gate_m(def.CALL_TD_GET_RANGE,i-1-ioff,ilink)+1;
%    end
end

% ask file name
[filename,pathname]=uiputfile('*.qss', 'Save');

if filename~=0
%   check filename for extension

    l=max(size(filename));
    isdot=filename(max(1,l-3));
    if strcmp(isdot,'.')
        filename=filename(1:l-4);
    end

%   store present path
    present_path=cd;

%   change path and write file
    eval(sprintf('cd %s',pathname));
    eval(sprintf('save %s.qss g data',filename));

%   restore path
    eval(sprintf('cd %s',present_path));
end

gupdate;

% --------------------------------------------------------------------
function varargout = cb_scope_id(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QS_SCOPE_ID=get(handles.tag_scope_id,'Value');

gupdate;
    
% --------------------------------------------------------------------
function varargout = cb_scope_mem(h, eventdata, handles, varargin)

global g data;

def=qs_defines;

g.QS_SCOPE_MEM(g.QS_SCOPE_ID)=get(handles.tag_scope_mem,'Value');

% set scope memory button state
if g.QS_SCOPE_MEM(g.QS_SCOPE_ID)==1
%   initialize scope data memory
    lent=max(size(data.TIM_XT));
    lenf1=max(size(data.FREQ_XF));
    lenf2=max(size(data.FREQ_PSD_AUTO));
    lenf3=max(size(data.FREQ_FRF));

%   current scope
    j=g.QS_SCOPE_ID;
    
%   reset current scope memory
    for i=1:2*g.QS_MAXCHAN,
        idx=(j-1)*g.QS_MAXCHAN*2+i;
        g.QS_SCOPE_MEM_IDAT(idx,1)=0;
    end
    
%   set current scope memory
    for i=1:g.QS_MAXCHAN*2,
        if g.QS_SCOPE_CHAN(j,i)==1
            idx=(j-1)*g.QS_MAXCHAN*2+i;
            g.QS_SCOPE_MEM_IDAT(idx,1)=1;
            switch g.QS_SCOPE_TYPE(j)
            case def.QSST_TIME,
                if g.QS_VALID==1
                    g.QS_SCOPE_MEM_XDAT(j,1:lent)=data.TIM_XT;
                    g.QS_SCOPE_MEM_YDAT(idx,1:lent)=data.XT(i,:);
                    g.QS_SCOPE_MEM_LDAT(j,1)=lent;
                end
            case def.QSST_FFT_MOD,
                if g.QS_VALID==1
                    g.QS_SCOPE_MEM_XDAT(j,1:lenf1)=data.FREQ_XF;
                    g.QS_SCOPE_MEM_YDAT(idx,1:lenf1)=data.XF_MOD(i,:);
                    g.QS_SCOPE_MEM_LDAT(j,1)=lenf1;
                end
            case def.QSST_FFT_PHS,
                if g.QS_VALID==1
                    g.QS_SCOPE_MEM_XDAT(j,1:lenf1)=data.FREQ_XF;
                    g.QS_SCOPE_MEM_YDAT(idx,1:lenf1)=data.XF_PHS(i,:);
                    g.QS_SCOPE_MEM_LDAT(j,1)=lenf1;
                end
            case {def.QSST_PSD_AUTO,def.QSST_ESD_AUTO,def.QSST_PSD_AUTO_CUM,def.QSST_POW_AUTO}
                if g.QS_VALID==1
                    g.QS_SCOPE_MEM_XDAT(j,1:lenf2)=data.FREQ_PSD_AUTO;
                    g.QS_SCOPE_MEM_YDAT(idx,1:lenf2)=data.PSD_AUTO(i,:);
                    g.QS_SCOPE_MEM_LDAT(j,1)=lenf2;
                end
            case def.QSST_PSD_CROSS,
                if i==g.QS_IN 
                    if g.QS_VALID==1
                        g.QS_SCOPE_MEM_XDAT(j,1:lenf3)=data.FREQ_FRF;
                        g.QS_SCOPE_MEM_YDAT(idx,1:lenf3)=data.PSD_CROSS';
                        g.QS_SCOPE_MEM_LDAT(j,1)=lenf3;
                    end
                 end
            case {def.QSST_FRF_MOD}
                if i==g.QS_IN 
                    if g.QS_VALID==1
                        g.QS_SCOPE_MEM_XDAT(j,1:lenf3)=data.FREQ_FRF;
                        g.QS_SCOPE_MEM_YDAT(idx,1:lenf3)=data.FRF_MOD';
                        g.QS_SCOPE_MEM_LDAT(j,1)=lenf3;
                    end
                end
            case {def.QSST_FRF_PHS}
                if i==g.QS_IN 
                    if g.QS_VALID==1
                        g.QS_SCOPE_MEM_XDAT(j,1:lenf3)=data.FREQ_FRF;
                        g.QS_SCOPE_MEM_YDAT(idx,1:lenf3)=data.FRF_PHS';
                        g.QS_SCOPE_MEM_LDAT(j,1)=lenf3;
                    end
                end
            case def.QSST_COHERENCE,
                if i==g.QS_IN 
                    if g.QS_VALID==1
                        g.QS_SCOPE_MEM_XDAT(j,1:lenf3)=data.FREQ_FRF;
                        g.QS_SCOPE_MEM_YDAT(idx,1:lenf3)=data.COH';
                        g.QS_SCOPE_MEM_LDAT(j,1)=lenf3;
                    end
                end
            case {def.QSST_FRF_OL_MOD}
                if i==g.QS_IN 
                    if g.QS_VALID==1
                        g.QS_SCOPE_MEM_XDAT(j,1:lenf3)=data.FREQ_FRF;
                        g.QS_SCOPE_MEM_YDAT(idx,1:lenf3)=data.FRF_OL_MOD';
                        g.QS_SCOPE_MEM_LDAT(j,1)=lenf3;
                    end
                end
            case {def.QSST_FRF_OL_PHS}
                if i==g.QS_IN 
                    if g.QS_VALID==1
                        g.QS_SCOPE_MEM_XDAT(j,1:lenf3)=data.FREQ_FRF;
                        g.QS_SCOPE_MEM_YDAT(idx,1:lenf3)=data.FRF_OL_PHS';
                        g.QS_SCOPE_MEM_LDAT(j,1)=lenf3;
                    end
                end
            case {def.QSST_FRF_OL_NYQ}
                if i==g.QS_IN 
                    if g.QS_VALID==1
                        g.QS_SCOPE_MEM_XDAT(j,1:lenf3)=real(data.FRF_OL)';
                        g.QS_SCOPE_MEM_YDAT(idx,1:lenf3)=imag(data.FRF_OL)';
                        g.QS_SCOPE_MEM_LDAT(j,1)=lenf3;
                    end
                end
            otherwise,
            end
        end
    end    
end

% redraw
g.QS_REDRAW=1;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_scope_type(h, eventdata, handles, varargin)

global g;

def=qs_defines;

old_type=g.QS_SCOPE_TYPE(g.QS_SCOPE_ID);
new_type=get(handles.tag_scope_type,'Value');

% check if frf measurement is requested
switch new_type
case {def.QSST_PSD_CROSS, def.QSST_FRF_MOD, def.QSST_FRF_PHS, def.QSST_COHERENCE, def.QSST_FRF_OL_MOD, def.QSST_FRF_OL_PHS, def.QSST_FRF_OL_NYQ},
    if g.QS_CHAN_IN_STATE(g.QS_IN) & g.QS_CHAN_IN_STATE(g.QS_OUT) & (g.QS_IN~=g.QS_OUT)
%	set frf mode
        g.QS_SCOPE_DOFRF(g.QS_SCOPE_ID)=1;

%	activate scope channels
	g.QS_SCOPE_CHAN(g.QS_SCOPE_ID,g.QS_IN)=1;	
        g.QS_SCOPE_CHAN(g.QS_SCOPE_ID,g.QS_OUT)=1;	

	g.QS_SCOPE_TYPE(g.QS_SCOPE_ID)=new_type;
%	sync other scope if of frf type
	other_scope_id=-g.QS_SCOPE_ID+3;
	if g.QS_SCOPE_DOFRF(other_scope_id)
	    g.QS_SCOPE_CHAN(other_scope_id,g.QS_IN)=1;
	    g.QS_SCOPE_CHAN(other_scope_id,g.QS_OUT)=1;
	end
    end
otherwise
    g.QS_SCOPE_DOFRF(g.QS_SCOPE_ID)=0;
    g.QS_SCOPE_TYPE(g.QS_SCOPE_ID)=new_type;    
end

% check if measurement should be stopped
switch old_type
case {def.QSST_TIME,def.QSST_FFT_MOD,def.QSST_FFT_PHS,def.QSST_PSD_AUTO}
    switch new_type
    case {def.QSST_TIME,def.QSST_FFT_MOD,def.QSST_FFT_PHS,def.QSST_PSD_AUTO}
%       new_type and old_type are from the same class
    otherwise,
%       new_type and old_type are not from the same class
        if g.QS_AVG_ON==1
            turnoff;
            g.QS_IFRAME=1;
        end       
    end
otherwise,
    switch new_type
    case {def.QSST_TIME,def.QSST_FFT_MOD,def.QSST_FFT_PHS,def.QSST_PSD_AUTO}
%       new_type and old_type are not from the same class
        if g.QS_AVG_ON==1
            turnoff;
            g.QS_IFRAME=1;
        end       
    otherwise,
%       new_type and old_type are from the same class
    end
end

% g.QS_SCOPE_TYPE(g.QS_SCOPE_ID)=get(handles.tag_scope_type,'Value');
switch g.QS_SCOPE_TYPE(g.QS_SCOPE_ID)
case {def.QSST_TIME, def.QSST_FFT_MOD, def.QSST_FFT_PHS},
    g.QS_SCOPE_SCALE(g.QS_SCOPE_ID)=def.QSSS_LIN;
end

% reset scope mem
g.QS_SCOPE_MEM(g.QS_SCOPE_ID)=0;

% reset scope freeze
g.QS_SCOPE_FREEZE(g.QS_SCOPE_ID)=0;

g.QS_REDRAW=1;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_scope_scale(h, eventdata, handles, varargin)

global g;

def=qs_defines;

switch g.QS_SCOPE_TYPE(g.QS_SCOPE_ID)
case {def.QSST_ESD_AUTO,def.QSST_PSD_AUTO, def.QSST_POW_AUTO,def.QSST_PSD_AUTO_CUM, def.QSST_PSD_CROSS, def.QSST_FRF_MOD, def.QSST_FRF_PHS, def.QSST_COHERENCE, def.QSST_FRF_OL_MOD, def.QSST_FRF_OL_PHS},
    g.QS_SCOPE_SCALE(g.QS_SCOPE_ID)=get(handles.tag_scope_scale,'Value');
otherwise,
    g.QS_SCOPE_SCALE(g.QS_SCOPE_ID)=def.QSSS_LIN;
    set(handles.tag_scope_scale,'Value',g.QS_SCOPE_SCALE(g.QS_SCOPE_ID));
end

g.QS_REDRAW=1;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_scope_freeze(h, eventdata, handles, varargin)

global g g2 data;

def=qs_defines;

g.QS_SCOPE_FREEZE(g.QS_SCOPE_ID)=get(handles.tag_scope_freeze,'Value');

j=g.QS_SCOPE_ID;
if g.QS_SCOPE_FREEZE(j)==1
    g.QS_SCOPE_XBAK(j,1:2)=get(g2.QS_SCOPE_HDLS(j),'Xlim');
    axis(g2.QS_SCOPE_HDLS(g.QS_SCOPE_ID),'manual');
else
    axis(g2.QS_SCOPE_HDLS(j),'auto');
    g.QS_REDRAW=1;
    if sum(abs(g.QS_SCOPE_XBAK(j,:)))>0
        set(g2.QS_SCOPE_HDLS(j),'XLim',g.QS_SCOPE_XBAK(j,:));
    end
end

gupdate;

% --------------------------------------------------------------------
function varargout = cb_scope_adc(h, eventdata, handles, varargin)

global g;

def=qs_defines;

if g.QS_AVG_ON==1
    turnoff;
    g.QS_IFRAME=1;
end

% get id of selected channel
the_tag=get(h,'Tag');
id=str2num(the_tag(17))+1;
val=get(h,'Value');

g.QS_SCOPE_CHAN(g.QS_SCOPE_ID,id)=val;

switch  g.QS_SCOPE_DOFRF(g.QS_SCOPE_ID);
case 0
    if val==1
%	new id becomes input, input becomes output
	g.QS_OUT=g.QS_IN;
	g.QS_IN=id;    
    end
case 1
    g.QS_SCOPE_CHAN(g.QS_SCOPE_ID,id)=1;
    switch id
    case g.QS_IN
%	swap in/out
	ttt=g.QS_OUT;
	g.QS_OUT=id;
	g.QS_IN=ttt;
    case g.QS_OUT
%	swap in/out
	ttt=g.QS_IN;
	g.QS_IN=id;
	g.QS_OUT=ttt;
    otherwise
%	selected channel becomes frf input signal    
	g.QS_IN=id;
    end
end

g.QS_REDRAW=1;
g.QS_VALID=0;

gupdate;

% --------------------------------------------------------------------
function varargout = cb_scope_enc(h, eventdata, handles, varargin)

global g;

def=qs_defines;

if g.QS_AVG_ON==1
    turnoff;
    g.QS_IFRAME=1;
end

% get id of selected channel
the_tag=get(h,'Tag');
id=str2num(the_tag(17))+1+g.QS_MAXCHAN;
val=get(h,'Value');

g.QS_SCOPE_CHAN(g.QS_SCOPE_ID,id)=val;

switch  g.QS_SCOPE_DOFRF(g.QS_SCOPE_ID);
case 0
    if val==1
%	new id becomes input, input becomes output
	g.QS_OUT=g.QS_IN;
	g.QS_IN=id;    
    end
case 1
    g.QS_SCOPE_CHAN(g.QS_SCOPE_ID,id)=1;
    switch id
    case g.QS_IN
%	swap in/out
	ttt=g.QS_OUT;
	g.QS_OUT=id;
	g.QS_IN=ttt;
    case g.QS_OUT
%	swap in/out
	ttt=g.QS_IN;
	g.QS_IN=id;
	g.QS_OUT=ttt;
    otherwise
%	selected channel becomes frf input signal    
	g.QS_IN=id;
    end
end

g.QS_REDRAW=1;
g.QS_VALID=0;

gupdate;

% --------------------------------------------------------------------
function varargout = tag_qlgui_DeleteFcn(h, eventdata, handles, varargin)
% Stub for DeleteFcn of the figure handles.tag_qlgui.

global g;

g.QS_EXIT=1;

% --------------------------------------------------------------------
function sync_aliasing(h,fs,iconfig)

global g;

def=qs_defines;

for i=1:g.QS_NDEVS,
    if (g.QS_AQI(i)==1)
        if iconfig==0
            tde_gate_m(def.CALL_TD_AAFILTER_OFF,i-1);
        else
            tde_gate_m(def.CALL_TD_AAFILTER_ON,fs/2.5,iconfig,i-1);
        end
    end
end

gupdate;

% --------------------------------------------------------------------
function is_aqi=current_chan_is_aqi()

global g;

ilink=get_link_id(g.QS_CHAN_SIGNAL);

if g.QS_AQI(ilink+1)==1
    is_aqi=1;
else
    is_aqi=0;
end
%---------------------------------------------------------------------
function ilink=get_link_id(ichan)
% ichan starts from 1

global g;

% copy channel id
i=ichan;

% correct channel id in case of encoder signal
if i>g.QS_MAXCHAN
    i=i-g.QS_MAXCHAN;
end

ilink=floor((i-1)/2);
%---------------------------------------------------------------------


% --- Executes on key press with focus on tag_scope_freeze and none of its controls.
function tag_scope_freeze_KeyPressFcn(hObject, eventdata, handles)
% hObject    handle to tag_scope_freeze (see GCBO)
% eventdata  structure with the following fields (see UICONTROL)
%	Key: name of the key that was pressed, in lower case
%	Character: character interpretation of the key(s) that was pressed
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function tag_scope_freeze_CreateFcn(hObject, eventdata, handles)
% hObject    handle to tag_scope_freeze (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over tag_channel.
function tag_channel_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to tag_channel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object deletion, before destroying properties.
function tag_channel_DeleteFcn(hObject, eventdata, handles)
% hObject    handle to tag_channel (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
