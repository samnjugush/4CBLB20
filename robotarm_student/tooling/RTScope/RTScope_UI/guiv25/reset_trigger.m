function reset_trigger()

global g;

def=qs_defines;

if g.QS_TRIGGER==1
%   reset trigger
    tde_gate_m(def.CALL_TDE_TRIGGER_OFF, g.QS_IP);
    irange=g.QS_CHAN_IN_RANGE(g.QS_TRIG_SIGNAL+1);
    tde_gate_m(def.CALL_TDE_TRIGGER_ON,g.QS_TRIG_SIGNAL,g.QS_TRIG_TYPE,g.QS_TSCALE(irange)*g.QS_TLEVEL(g.QS_TRIG_LEVEL),g.QS_TPREROLL(g.QS_TRIG_PREROLL),g.QS_TRELFREQ(g.QS_TRIG_RELFREQ),g.QS_NSAMP, g.QS_IP);
end

