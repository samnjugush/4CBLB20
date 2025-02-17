function [varargout]=tde_gate_m(varargin)

global g;

def=qs_defines;

%if g.QS_GATE_ERROR>0
%    disp('Error.');
%    return;
%end

% see tde_gate.c for definition of ERRRETVAL!!!
ERRRETVAL=-1000000;

%warning off

icall=varargin{1};
switch icall
case def.CALL_TDE_START_ACQ
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_TDE_STOP_ACQ
    [argout0]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};    
case def.CALL_TDE_CHECK_DATA
    [argout0]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
case def.CALL_TDE_SAY_READY
    [argout0]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
case def.CALL_TDE_GET_DATA
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_TDE_GET_INFO
    [argout0,argout1,argout2]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
    varargout(2)={argout1};
    varargout(3)={argout2};
case def.CALL_TDE_TRIGGER_ON
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4}, varargin{5}, varargin{6}, varargin{7}, varargin{8});
    varargout(1)={argout0};
case def.CALL_TDE_TRIGGER_OFF
    [argout0]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
case def.CALL_TDE_CHECK_CLIPPING
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_TDE_SET_ADC_STATE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_TDE_GET_ADC_STATE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TDE_SET_ENC_STATE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_TDE_GET_ENC_STATE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TDE_SET_DAC_STATE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_TDE_GET_DAC_STATE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TDE_SET_ADC_OFFSET
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_TDE_GET_ADC_OFFSET
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_TDE_PAUSE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TDE_SET_NSAMP
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TDE_SET_NDOWN
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TDE_INIT_ENC
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TD_GET_DEVICE_TYPE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TD_AAFILTER_ON
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4}, varargin{5});
    varargout(1)={argout0};
case def.CALL_TD_AAFILTER_OFF
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TD_SET_RANGE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4}, varargin{5});
    varargout(1)={argout0};
case def.CALL_TD_GET_RANGE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_TD_GET_FILTER_ENABLE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_TDE_GET_MAXFREQ
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_TDE_LINK2MEAS
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_TDE_LINK_IS_ACTIVE
    [argout0]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
case def.CALL_FG_GET_VAL
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_FG_START
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_FG_STOP
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_FG_SET_DEFAULTS
    [argout0]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
case def.CALL_FG_SET_AMP1
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_FG_GET_AMP1
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_FG_SET_AMP2
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_FG_GET_AMP2
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_FG_SET_FREQ1
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_FG_GET_FREQ1
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_FG_SET_FREQ2
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_FG_GET_FREQ2
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_FG_SET_OFFSET
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_FG_GET_OFFSET
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_FG_STATUS
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_FG_SET_TYPE
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_FG_GET_TYPE
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_FG_SET_ONOFF
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
case def.CALL_FG_GET_ONOFF
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_FG_SET_HOLD_ORDER
    [argout0]=tde_gate(varargin{1}, varargin{2}, varargin{3}, varargin{4});
    varargout(1)={argout0};
case def.CALL_FG_GET_HOLD_ORDER
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2}, varargin{3});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_TDE_GET_ADC_ENC_STATE
    [argout0,argout1]=tde_gate(varargin{1}, varargin{2});
    varargout(1)={argout0};
    varargout(2)={argout1};
case def.CALL_TDE_CHECK_ERROR
    argout0=g.QS_GATE_ERROR;
    varargout(1)={argout0};
otherwise
    error('Dont know what to do with these arguments.');
end

%warning on
%disp(num2str(argout0));
if argout0<=ERRRETVAL

    g.QS_GATE_ERROR=1;
%    disp(['g.QS_GATE_ERROR = ' num2str(g.QS_GATE_ERROR)]);
    
%   not allowed: recursion!!!
%   qsexit;

%    g.QS_EXIT=1;
%    g.QS_RUNNING=0;
    
%    if g.QS_GUI_OPEN==1
%        delete(g.QS_FIG);
%	g.QS_GUI_OPEN=0;
%    end
    
%    if g.QSG_GEN_OPEN==1
%	delete(g.QSG_FIG);
%	g.QSG_GEN_OPEN=0;
%    end
    
%    error('Real-time kernel is not running. Scope has been closed.');

end
