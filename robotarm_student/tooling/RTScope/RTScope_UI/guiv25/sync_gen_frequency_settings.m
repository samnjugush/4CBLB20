% --------------------------------------------------------------------
function sync_gen_frequency_settings()

global g;

def=qs_defines;

% return if generator is not open
if g.QSG_GEN_OPEN==0
    return;
end

% read type
type=tde_gate(def.CALL_FG_GET_TYPE, g.QSG_GEN_SIGNAL-1, g.QS_IP);

% always do frequency 1
% read gen frequency 1
freq1=tde_gate_m(def.CALL_FG_GET_FREQ1, g.QSG_GEN_SIGNAL-1, g.QS_IP);
% set gen frequency 1
tde_gate_m(def.CALL_FG_SET_FREQ1,freq1, g.QSG_GEN_SIGNAL-1, g.QS_IP);
% read gen frequency 1 again
freq1=tde_gate_m(def.CALL_FG_GET_FREQ1, g.QSG_GEN_SIGNAL-1, g.QS_IP);

% do frequency 1 for random type
if type==def.RAND
% bound frequency for fir filter design
    freq1=bound_freq(freq1);
    tde_gate_m(def.CALL_FG_SET_FREQ1, freq1, g.QSG_GEN_SIGNAL-1, g.QS_IP);
end

if type==def.TWOTONE | type==def.CHIRP | type==def.MULTISINE | type==def.WHISTLE
%   do frequency 2
%   read gen frequency 2
    freq2=tde_gate_m(def.CALL_FG_GET_FREQ2, g.QSG_GEN_SIGNAL-1, g.QS_IP);
%   set gen frequency 2
    tde_gate_m(def.CALL_FG_SET_FREQ2, freq2, g.QSG_GEN_SIGNAL-1, g.QS_IP);
%   read gen frequency 2 again
    freq2=tde_gate_m(def.CALL_FG_GET_FREQ2, g.QSG_GEN_SIGNAL-1, g.QS_IP);

%   enable freq select
    set(g.QSG_HANDLES.tag_gen_freq_select,'Enable','on');

    switch g.QSG_GEN_FREQ_SELECT
    case 1,
%   	update gen frequency 1 gui settings
	set(g.QSG_HANDLES.tag_gen_frequency_disp,'String',num2str(freq1));
	set(g.QSG_HANDLES.tag_gen_frequency,'Value',freq1);
    case 2,
%   	update gen frequency 2 gui settings
	set(g.QSG_HANDLES.tag_gen_frequency_disp,'String',num2str(freq2));
	set(g.QSG_HANDLES.tag_gen_frequency,'Value',freq2);
    end
else
%   disable freq select
    set(g.QSG_HANDLES.tag_gen_freq_select,'Enable','off');

%   set frequency select to 1
    g.QSG_GEN_FREQ_SELECT=1;
    set(g.QSG_HANDLES.tag_gen_freq_select','String','1');

%   update gen frequency 1 gui settings
    set(g.QSG_HANDLES.tag_gen_frequency_disp,'String',num2str(freq1));
    set(g.QSG_HANDLES.tag_gen_frequency,'Value',freq1);
end
