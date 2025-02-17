function varargout = qlgen(varargin)
% QLGEN Application M-file for qlgen.fig
%    FIG = QLGEN launch qlgen GUI.
%    QLGEN('callback_name', ...) invoke the named callback.

% Last Modified by GUIDE v2.5 14-Jan-2015 10:07:15

global g g2;

def=qs_defines;

if nargin == 0  % LAUNCH GUI

    warning off;
    fig = openfig(mfilename,'reuse');
    warning on;

    g.QSG_FIG=fig;
    g.QSG_GEN_OPEN=1;
    
	% Generate a structure of handles to pass to callbacks, and store it. 
	handles = guihandles(fig);
	guidata(fig, handles);
    
    g.QSG_HANDLES=handles;

%   adjust window position
    pos_gui=get(g2.QS_HANDLES.tag_qlgui,'Position');
    pos_gen=get(g.QSG_HANDLES.tag_qlgen,'Position');
    pos_gen(1)=max(0,pos_gui(1)-pos_gen(3)-6);
    pos_gen(2)=pos_gui(2);
    pos_scope(4)=pos_gui(4);
    set(g.QSG_HANDLES.tag_qlgen,'Position',pos_gen);

%   adjust selectable dac channels in gui
    dac_channels=cell(2*g.QS_NDEVS,1);
    for i=1:2*g.QS_NDEVS,
        %fix signal generator: msg=sprintf('analog out ch %d',i-1);
        msg=sprintf('Analog out ch %d',i);
        dac_channels{i,1}=msg; 
    end
    set(handles.tag_gen_signal,'String',dac_channels);
    
%   set active channel settings
    set(handles.tag_gen_signal,'Value',g.QSG_GEN_SIGNAL);
    g.QSG_GEN_CHAN(g.QSG_GEN_SIGNAL)=tde_gate_m(def.CALL_FG_STATUS,g.QSG_GEN_SIGNAL-1);
%   type    
    type=tde_gate_m(def.CALL_FG_GET_TYPE,g.QSG_GEN_SIGNAL-1);
    set(handles.tag_gen_type,'Value',type);
%   hold order
    sync_hold_order_button;
%   power buttons
    set(handles.tag_gen_power,'Value',g.QSG_GEN_CHAN(g.QSG_GEN_SIGNAL));
    if g.QSG_GEN_CHAN(g.QSG_GEN_SIGNAL)==1;
        %fix:
        %set(handles.tag_gen_power,'BackgroundColor',def.COLOR_YELLOW);
        %%change color
        set(handles.tag_gen_power,'BackgroundColor','green');
    else
        %fix: set(handles.tag_gen_power,'BackgroundColor',def.COLOR_GREY);
        %%change color
        set(handles.tag_gen_power, 'TextColor', 'white','BackgroundColor','red');
    end

    onoff=tde_gate_m(def.CALL_FG_GET_ONOFF);
    set(handles.tag_gen_onoff,'Value',onoff);
    if onoff==1
        %fix:
        %set(handles.tag_gen_onoff,'BackgroundColor',def.COLOR_YELLOW);
        %%change color
        set(handles.tag_gen_onoff,'BackgroundColor','green');

    else
       %fix: set(handles.tag_gen_onoff,'BackgroundColor',def.COLOR_GREY);
       %%change color
       set(handles.tag_gen_onoff, 'TextColor', 'white','BackgroundColor','red');

    end        

%   offset slider and display
    set(handles.tag_gen_offset,'Min',-2.5);
    set(handles.tag_gen_offset,'Max',2.5);
    set(handles.tag_gen_offset,'SliderStep',[0.0002 0.002]);
    offset=tde_gate_m(def.CALL_FG_GET_OFFSET,g.QSG_GEN_SIGNAL-1);
    set(handles.tag_gen_offset,'Value',offset);
    set(handles.tag_gen_offset_disp,'String',num2str(offset));
%   amplitude slider and display
    set(handles.tag_gen_amplitude,'Min',-2.5);
    set(handles.tag_gen_amplitude,'Max',2.5);
    set(handles.tag_gen_amplitude,'SliderStep',[0.0002 0.002]);
    
    set(handles.tag_gen_amp_select,'String','1');
    set(handles.tag_gen_amp_select,'Enable','off');
    iget=def.CALL_FG_GET_AMP1;
    if type==def.TWOTONE
        set(handles.tag_gen_amp_select,'Enable','on');
        if g.QSG_GEN_AMP_SELECT==2
            set(handles.tag_gen_amp_select,'String','2');
            iget=def.CALL_FG_GET_AMP2;
        end
    end
    amp=tde_gate_m(iget,g.QSG_GEN_SIGNAL-1);
    set(handles.tag_gen_amplitude,'Value',amp);
    set(handles.tag_gen_amplitude_disp,'String',num2str(amp));
%   frequency slider and display
    set(handles.tag_gen_frequency,'Min',def.FMIN);
    set(handles.tag_gen_frequency,'Max',g.QS_MAXFREQ/2);
    set(handles.tag_gen_frequency,'SliderStep',[0.0001 0.001]);
    
%   sync frequency controls
    sync_gen_frequency_settings;
    
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
function varargout = cb_gen_type(h, eventdata, handles, varargin)

global g;

def=qs_defines;

type=get(handles.tag_gen_type,'Value');
tde_gate_m(def.CALL_FG_SET_TYPE,type,g.QSG_GEN_SIGNAL-1);

% set amplitude controls
set(handles.tag_gen_amp_select,'String','1');
set(handles.tag_gen_amp_select,'Enable','off');
iget=def.CALL_FG_GET_AMP1;
if type==def.TWOTONE
    set(handles.tag_gen_amp_select,'Enable','on');
    if g.QSG_GEN_AMP_SELECT==2
        set(handles.tag_gen_amp_select,'String','2');
        iget=def.CALL_FG_GET_AMP2;
    end
end
amp=tde_gate_m(iget,g.QSG_GEN_SIGNAL-1);
set(handles.tag_gen_amplitude,'Value',amp);
set(handles.tag_gen_amplitude_disp,'String',num2str(amp));

% sync frequency controls
sync_gen_frequency_settings;
    
% --------------------------------------------------------------------
function varargout = cb_gen_signal(h, eventdata, handles, varargin)

global g;

def=qs_defines;

g.QSG_GEN_SIGNAL=get(handles.tag_gen_signal,'Value');
if g.QSG_GEN_CHAN(g.QSG_GEN_SIGNAL)==1
      set(handles.tag_gen_power,'BackgroundColor',def.COLOR_YELLOW);
      set(handles.tag_gen_power,'Value',1);
else
      set(handles.tag_gen_power,'BackgroundColor',def.COLOR_GREY);    
      set(handles.tag_gen_power,'Value',0);
end

% type
type=tde_gate_m(def.CALL_FG_GET_TYPE,g.QSG_GEN_SIGNAL-1);
set(handles.tag_gen_type,'Value',type);

% get hold order
sync_hold_order_button;

% offset
offset=tde_gate_m(def.CALL_FG_GET_OFFSET,g.QSG_GEN_SIGNAL-1);
set(handles.tag_gen_offset,'Value',offset);
set(handles.tag_gen_offset_disp,'String',num2str(offset));

% amplitude
set(handles.tag_gen_amp_select,'String','1');
set(handles.tag_gen_amp_select,'Enable','off');
ifun=def.CALL_FG_GET_AMP1;
if type==def.TWOTONE
    set(handles.tag_gen_amp_select,'Enable','on');
    if g.QSG_GEN_AMP_SELECT==2
        set(handles.tag_gen_amp_select,'String','2');
        ifun=def.CALL_FG_GET_AMP2;
    end
end
amp=tde_gate_m(ifun,g.QSG_GEN_SIGNAL-1);
set(handles.tag_gen_amplitude,'Value',amp);
set(handles.tag_gen_amplitude_disp,'String',num2str(amp));

% sync frequency controls
sync_gen_frequency_settings;

% --------------------------------------------------------------------
function varargout = cb_gen_power(h, eventdata, handles, varargin)

global g;

def=qs_defines;

istate=get(handles.tag_gen_power,'Value');

tde_gate_m(def.CALL_TDE_SET_DAC_STATE,istate,g.QSG_GEN_SIGNAL-1);

if istate==1
    g.QSG_GEN_CHAN(g.QSG_GEN_SIGNAL)=1;
    tde_gate_m(def.CALL_FG_START,g.QSG_GEN_SIGNAL-1);
    set(handles.tag_gen_power,'BackgroundColor',def.COLOR_YELLOW);
else
    g.QSG_GEN_CHAN(g.QSG_GEN_SIGNAL)=0;
    tde_gate_m(def.CALL_FG_STOP,g.QSG_GEN_SIGNAL-1);
    set(handles.tag_gen_power,'BackgroundColor',def.COLOR_GREY);
end

% --------------------------------------------------------------------
function varargout = cb_gen_offset(h, eventdata, handles, varargin)

global g;

def=qs_defines;

offset=get(handles.tag_gen_offset,'Value');
tde_gate_m(def.CALL_FG_SET_OFFSET,offset,g.QSG_GEN_SIGNAL-1);
set(handles.tag_gen_offset_disp,'String',num2str(offset));

% --------------------------------------------------------------------
function varargout = cb_gen_offset2(h, eventdata, handles, varargin)

global g;

def=qs_defines;

offset=str2num(get(handles.tag_gen_offset_disp,'String'));

offset=max(-2.5,min(2.5,offset));
set(handles.tag_gen_offset_disp,'String',num2str(offset));

tde_gate_m(def.CALL_FG_SET_OFFSET,offset,g.QSG_GEN_SIGNAL-1);
set(handles.tag_gen_offset,'Value',offset);

% --------------------------------------------------------------------
function varargout = cb_gen_zeroise(h, eventdata, handles, varargin)

global g;

def=qs_defines;

tde_gate_m(def.CALL_FG_SET_OFFSET,0,g.QSG_GEN_SIGNAL-1);
set(handles.tag_gen_offset,'Value',0);
set(handles.tag_gen_offset_disp,'String',num2str(0));

% --------------------------------------------------------------------
function varargout = cb_gen_amplitude(h, eventdata, handles, varargin)

global g;

def=qs_defines;

amp=get(handles.tag_gen_amplitude,'Value');

type=tde_gate_m(def.CALL_FG_GET_TYPE,g.QSG_GEN_SIGNAL-1);

ifun=def.CALL_FG_SET_AMP1;
if type==def.TWOTONE
    if g.QSG_GEN_AMP_SELECT==2
        ifun=def.CALL_FG_SET_AMP2;
    end
end

tde_gate_m(ifun,amp,g.QSG_GEN_SIGNAL-1);
set(handles.tag_gen_amplitude_disp,'String',num2str(amp));

% --------------------------------------------------------------------
function varargout = cb_gen_amplitude2(h, eventdata, handles, varargin)

global g;

def=qs_defines;

amp=str2num(get(handles.tag_gen_amplitude_disp,'String'));

amp=max(-2.5,min(2.5,amp));
set(handles.tag_gen_amplitude_disp,'String',num2str(amp));

type=tde_gate_m(def.CALL_FG_GET_TYPE,g.QSG_GEN_SIGNAL-1);

ifun=def.CALL_FG_SET_AMP1;
if type==def.TWOTONE
    if g.QSG_GEN_AMP_SELECT==2
        ifun=def.CALL_FG_SET_AMP2;
    end
end

tde_gate_m(ifun,amp,g.QSG_GEN_SIGNAL-1);
set(handles.tag_gen_amplitude,'Value',amp);

% --------------------------------------------------------------------
function varargout = cb_gen_amp_select(h, eventdata, handles, varargin)

global g;

def=qs_defines;

type=tde_gate_m(def.CALL_FG_GET_TYPE,g.QSG_GEN_SIGNAL-1);
if type==def.TWOTONE
    g.QSG_GEN_AMP_SELECT=3-g.QSG_GEN_AMP_SELECT;

    switch g.QSG_GEN_AMP_SELECT
    case 1,
        amp=tde_gate_m(def.CALL_FG_GET_AMP1,g.QSG_GEN_SIGNAL-1);
        set(handles.tag_gen_amp_select,'String','1');
    case 2,
        amp=tde_gate_m(def.CALL_FG_GET_AMP2,g.QSG_GEN_SIGNAL-1);    
        set(handles.tag_gen_amp_select,'String','2');
    end

    set(handles.tag_gen_amplitude,'Value',amp);
    set(handles.tag_gen_amplitude_disp,'String',num2str(amp));
end

% --------------------------------------------------------------------
function varargout = cb_gen_frequency(h, eventdata, handles, varargin)

global g;

def=qs_defines;

freq=get(handles.tag_gen_frequency,'Value');

type=tde_gate_m(def.CALL_FG_GET_TYPE,g.QSG_GEN_SIGNAL-1);
if type==def.RAND
    freq=bound_freq(freq);
end

switch g.QSG_GEN_FREQ_SELECT
case 1,
%   update gen frequency 1 setting
    tde_gate_m(def.CALL_FG_SET_FREQ1,freq,g.QSG_GEN_SIGNAL-1);
case 2,
%   update gen frequency 2 setting
    tde_gate_m(def.CALL_FG_SET_FREQ2,freq,g.QSG_GEN_SIGNAL-1);
end

% sync frequency controls
sync_gen_frequency_settings;

% --------------------------------------------------------------------
function varargout = cb_gen_frequency2(h, eventdata, handles, varargin)

global g;

def=qs_defines;

freq=str2num(get(handles.tag_gen_frequency_disp,'String'));
freq=max(def.FMIN,min(g.QS_MAXFREQ/2,freq));

switch g.QSG_GEN_FREQ_SELECT
case 1,
%   update gen frequency 1 setting
    tde_gate_m(def.CALL_FG_SET_FREQ1,freq,g.QSG_GEN_SIGNAL-1);
case 2,
%   update gen frequency 2 setting
    tde_gate_m(def.CALL_FG_SET_FREQ2,freq,g.QSG_GEN_SIGNAL-1);
end

% sync frequency controls
sync_gen_frequency_settings;

% --------------------------------------------------------------------
function varargout = cb_gen_freq_select(h, eventdata, handles, varargin)

global g;

def=qs_defines;

type=tde_gate_m(def.CALL_FG_GET_TYPE,g.QSG_GEN_SIGNAL-1);
if type==def.TWOTONE | type==def.CHIRP | type==def.MULTISINE | type==def.WHISTLE
    g.QSG_GEN_FREQ_SELECT=3-g.QSG_GEN_FREQ_SELECT;

    switch g.QSG_GEN_FREQ_SELECT
    case 1,
        freq=tde_gate_m(def.CALL_FG_GET_FREQ1,g.QSG_GEN_SIGNAL-1);
        set(handles.tag_gen_freq_select,'String','1');
    case 2,
        freq=tde_gate_m(def.CALL_FG_GET_FREQ2,g.QSG_GEN_SIGNAL-1);    
        set(handles.tag_gen_freq_select,'String','2');
    end

    set(handles.tag_gen_frequency,'Value',freq);
    set(handles.tag_gen_frequency_disp,'String',num2str(freq));
end

% --------------------------------------------------------------------
function varargout = cb_gen_exit(h, eventdata, handles, varargin)

global g;

close(g.QSG_FIG);
g.QSG_GEN_OPEN=0;

% --------------------------------------------------------------------
function varargout = cb_gen_onoff(h, eventdata, handles, varargin)

global g;

def=qs_defines;

onoff=get(handles.tag_gen_onoff,'Value');
%disp('Toggle signal generator');
tde_gate_m(def.CALL_FG_SET_ONOFF,onoff);

if onoff==1
    set(handles.tag_gen_onoff,'BackgroundColor',def.COLOR_YELLOW);
    set(handles.uipanel2,'Enable', 'on')

else
    set(handles.tag_gen_onoff,'BackgroundColor',def.COLOR_GREY);
        set(handles.uipanel2,'Enable', 'off')
end



% --------------------------------------------------------------------
function varargout = cb_gen_link(h, eventdata, handles, varargin)

def=qs_defines;

ilinked=get(handles.tag_gen_link,'Value');

tde_gate_m(def.CALL_TDE_LINK2MEAS,ilinked);

% turn off generator
tde_gate_m(def.CALL_FG_SET_ONOFF,0);
set(handles.tag_gen_onoff,'Value',0);
    
% disable or enable on/off button
if ilinked==1
    set(handles.tag_gen_onoff,'Enable','off');
    set(handles.tag_gen_onoff,'BackgroundColor',def.COLOR_RED);
else
    set(handles.tag_gen_onoff,'Enable','on');
    set(handles.tag_gen_onoff,'BackgroundColor',def.COLOR_GREY);
end

% --------------------------------------------------------------------
function varargout = cb_gen_timepf(h, eventdata, handles, varargin)




% --------------------------------------------------------------------
function varargout = cb_gen_timepf_disp(h, eventdata, handles, varargin)





% --------------------------------------------------------------------
function varargout = cb_gen_hoh(h, eventdata, handles, varargin)

global g;

def=qs_defines;

% get hold order of current generator signal
hold_order=tde_gate_m(def.CALL_FG_GET_HOLD_ORDER,g.QSG_GEN_SIGNAL-1);

% increase hold order by one and check bound
hold_order=hold_order+1;
if current_gen_chan_is_aqi
%   AQI
%   MAXHOLDORDER+1...2*MAXHOLDORDER are reserved for hardware hoh
    if hold_order>2*def.MAXHOLDORDER
	hold_order=0;
    end
else
%   QAD
    if hold_order>def.MAXHOLDORDER
	hold_order=0;
    end
end

% set new hold order for current generator channel
tde_gate_m(def.CALL_FG_SET_HOLD_ORDER,hold_order,g.QSG_GEN_SIGNAL-1);

sync_hold_order_button;





% --------------------------------------------------------------------
function is_aqi=current_gen_chan_is_aqi()

global g;

ilink=floor((g.QSG_GEN_SIGNAL-1)/2);

if g.QS_AQI(ilink+1)==1
    is_aqi=1;
else
    is_aqi=0;
end





% --------------------------------------------------------------------
function sync_hold_order_button()

global g;

def=qs_defines;

% get hold order
hold_order=tde_gate_m(def.CALL_FG_GET_HOLD_ORDER,g.QSG_GEN_SIGNAL-1);

% set hoh button color
if hold_order==0
    set(g.QSG_HANDLES.tag_gen_hoh,'String',num2str(hold_order));
    set(g.QSG_HANDLES.tag_gen_hoh,'BackgroundColor',def.COLOR_GREY);
else
    if current_gen_chan_is_aqi
%	AQI
        if hold_order>def.MAXHOLDORDER
	    set(g.QSG_HANDLES.tag_gen_hoh,'String',num2str(hold_order-def.MAXHOLDORDER));
	    set(g.QSG_HANDLES.tag_gen_hoh,'BackgroundColor',def.COLOR_RED);
	else
	    set(g.QSG_HANDLES.tag_gen_hoh,'String',num2str(hold_order));
	    set(g.QSG_HANDLES.tag_gen_hoh,'BackgroundColor',def.COLOR_YELLOW);
	end
    else
%	QAD
	set(g.QSG_HANDLES.tag_gen_hoh,'String',num2str(hold_order));
        set(g.QSG_HANDLES.tag_gen_hoh,'BackgroundColor',def.COLOR_YELLOW);
    end
end


% --- Executes during object creation, after setting all properties.
function uipanel2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to uipanel2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on selection change in popupmenu7.
function popupmenu7_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu7 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu7


% --- Executes during object creation, after setting all properties.
function popupmenu7_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider13_Callback(hObject, eventdata, handles)
% hObject    handle to slider13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function slider13_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit13_Callback(hObject, eventdata, handles)
% hObject    handle to edit13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit13 as text
%        str2double(get(hObject,'String')) returns contents of edit13 as a double


% --- Executes during object creation, after setting all properties.
function edit13_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider14_Callback(hObject, eventdata, handles)
% hObject    handle to slider14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function slider14_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit14_Callback(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit14 as text
%        str2double(get(hObject,'String')) returns contents of edit14 as a double


% --- Executes during object creation, after setting all properties.
function edit14_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in popupmenu8.
function popupmenu8_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu8 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu8


% --- Executes during object creation, after setting all properties.
function popupmenu8_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider15_Callback(hObject, eventdata, handles)
% hObject    handle to slider15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function slider15_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on button press in togglebutton4.
function togglebutton4_Callback(hObject, eventdata, handles)
% hObject    handle to togglebutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of togglebutton4



function edit15_Callback(hObject, eventdata, handles)
% hObject    handle to edit15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit15 as text
%        str2double(get(hObject,'String')) returns contents of edit15 as a double


% --- Executes during object creation, after setting all properties.
function edit15_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton20.
function pushbutton20_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton20 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton21.
function pushbutton21_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton21 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton22.
function pushbutton22_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton22 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in checkbox4.
function checkbox4_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox4


% --- Executes on slider movement.
function slider16_Callback(hObject, eventdata, handles)
% hObject    handle to slider16 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function slider16_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider16 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit16_Callback(hObject, eventdata, handles)
% hObject    handle to edit16 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit16 as text
%        str2double(get(hObject,'String')) returns contents of edit16 as a double


% --- Executes during object creation, after setting all properties.
function edit16_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit16 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton23.
function pushbutton23_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton23 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
