function turnon()

global g;

def=qs_defines;

if g.QS_RUNNING==0
    tde_gate_m(def.CALL_TDE_PAUSE, 0, g.QS_IP);
    g.QS_RUNNING=1;
end
