function frm_ind_init()

global g g2;

global frm_ind_istate frm_ind_hdls;

def=qs_defines;

frm_ind_istate=0;

frm_ind_hdls=[g2.QS_HANDLES.tag_frm_ind_inst, g2.QS_HANDLES.tag_frm_ind_avg];

set(frm_ind_hdls(1),'BackgroundColor',def.COLOR_RED+0.5*(ones(1,3)-def.COLOR_RED));
set(frm_ind_hdls(2),'BackgroundColor',def.COLOR_RED+0.5*(ones(1,3)-def.COLOR_RED));





function frm_ind_flash(meas_type)

% meas_type 1 (inst) or 2 (avg)

global frm_ind_istate frm_ind_hdls;

frm_ind_istate=1-frm_ind_istate;

switch frm_ind_istate
case 0,
    set(frm_ind_hdls(meas_type),'BackgroundColor',def.COLOR_RED+0.5*(ones(1,3)-def.COLOR_RED));
case 1,
    set(frm_ind_hdls(meas_type),'BackgroundColor',def.COLOR_RED);
end





function frm_ind_off()

frm_ind_init;
