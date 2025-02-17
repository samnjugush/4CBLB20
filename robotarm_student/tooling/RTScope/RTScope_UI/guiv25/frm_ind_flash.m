function frm_ind_flash(meas_type)

% meas_type 1 (inst) or 2 (avg)

global frm_ind_istate frm_ind_hdls;

def=qs_defines;

frm_ind_istate=1-frm_ind_istate;

% reset other...
set(frm_ind_hdls(3-meas_type),'BackgroundColor',def.COLOR_GREEN+0.75*(ones(1,3)-def.COLOR_GREEN));

switch frm_ind_istate
case 0,
    set(frm_ind_hdls(meas_type),'BackgroundColor',def.COLOR_GREEN+0.75*(ones(1,3)-def.COLOR_GREEN));
case 1,
    set(frm_ind_hdls(meas_type),'BackgroundColor',def.COLOR_GREEN);
end
