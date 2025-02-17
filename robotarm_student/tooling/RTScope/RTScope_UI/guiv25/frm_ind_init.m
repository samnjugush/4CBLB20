function frm_ind_init()

global g g2;

global frm_ind_istate frm_ind_hdls;

def=qs_defines;

frm_ind_istate=0;

frm_ind_hdls=[g2.QS_HANDLES.tag_frm_ind_inst, g2.QS_HANDLES.tag_frm_ind_avg];

set(frm_ind_hdls(1),'BackgroundColor',def.COLOR_GREEN+0.75*(ones(1,3)-def.COLOR_GREEN));
set(frm_ind_hdls(2),'BackgroundColor',def.COLOR_GREEN+0.75*(ones(1,3)-def.COLOR_GREEN));
