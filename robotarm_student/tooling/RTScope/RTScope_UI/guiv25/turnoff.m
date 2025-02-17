function turnoff()

global g;

def=qs_defines;

if g.QS_RUNNING==1
    tde_gate_m(def.CALL_TDE_PAUSE, 1, g.QS_IP);
    g.QS_RUNNING=0;
    frm_ind_off;
end
