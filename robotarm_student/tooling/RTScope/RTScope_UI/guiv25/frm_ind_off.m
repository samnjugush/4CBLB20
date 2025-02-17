function frm_ind_off()

global frm_ind_hdls;

def=qs_defines;

set(frm_ind_hdls(1),'BackgroundColor',def.COLOR_GREEN+0.75*(ones(1,3)-def.COLOR_GREEN));
set(frm_ind_hdls(2),'BackgroundColor',def.COLOR_GREEN+0.75*(ones(1,3)-def.COLOR_GREEN));
