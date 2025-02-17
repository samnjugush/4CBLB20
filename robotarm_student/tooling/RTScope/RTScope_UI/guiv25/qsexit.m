function qsexit

global g g2;

def=qs_defines;

% turn off function generator
tde_gate_m(def.CALL_FG_SET_ONOFF, 0, g.QS_IP);

% shutdown QadScope
% close gui windows
if g.QS_GUI_OPEN==1
    delete(g2.QS_FIG);
    g.QS_GUI_OPEN=0;
end

if g.QSG_GEN_OPEN==1
    delete(g.QSG_FIG);
    g.QSG_GEN_OPEN=0;
end

% turn of data acquisition engine
tde_gate_m(def.CALL_TDE_STOP_ACQ, g.QS_IP);

clear mex

disp('RTScope has been shut down.');
