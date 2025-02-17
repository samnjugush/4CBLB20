
/* macros */

#define MAXFRAME	16384
#define MAXSAMP		2*MAXFRAME
#define MAXCHAN		4
#define MAXHIST		5

#define TRIG_STATE_WAIT		0
#define TRIG_STATE_GO		1
#define TRIG_STATE_DONE		2

#define CMD_STATUS_IDLE		0
#define CMD_STATUS_PENDING	1
#define CMD_STATUS_READY	2

#define DEVICE_NOT_READY	111

/* macros */
#define CALL_TDE_START_ACQ		1
#define CALL_TDE_STOP_ACQ		2
#define CALL_TDE_CHECK_DATA		3
#define CALL_TDE_SAY_READY		4
#define CALL_TDE_GET_DATA		5
#define CALL_TDE_GET_INFO		6
#define CALL_TDE_TRIGGER_ON		7
#define CALL_TDE_TRIGGER_OFF		8
#define CALL_TDE_CHECK_CLIPPING		9
#define CALL_TDE_SET_ADC_STATE		10
#define CALL_TDE_GET_ADC_STATE		11
#define CALL_TDE_SET_ENC_STATE		12
#define CALL_TDE_GET_ENC_STATE		13
#define CALL_TDE_SET_DAC_STATE		14
#define CALL_TDE_GET_DAC_STATE		15
#define CALL_TDE_SET_ADC_OFFSET		16
#define CALL_TDE_GET_ADC_OFFSET		17
#define CALL_TDE_PAUSE			18
#define CALL_TDE_SET_NSAMP		19
#define CALL_TDE_SET_NDOWN		20
#define CALL_TDE_INIT_ENC		21

#define CALL_TD_GET_DEVICE_TYPE		22
#define CALL_TD_AAFILTER_ON		23
#define CALL_TD_AAFILTER_OFF		24
#define CALL_TD_SET_RANGE		25
#define CALL_TD_GET_RANGE		26
#define CALL_TD_GET_FILTER_ENABLE	27

#define CALL_TDE_GET_MAXFREQ		28
#define CALL_TDE_LINK2MEAS		29
#define CALL_TDE_LINK_IS_ACTIVE		30

#define CALL_FG_GET_VAL			31
#define CALL_FG_START			32
#define CALL_FG_STOP			33
#define CALL_FG_SET_DEFAULTS		34
#define CALL_FG_SET_AMP1		35
#define CALL_FG_GET_AMP1		36
#define CALL_FG_SET_FREQ1		37
#define CALL_FG_GET_FREQ1		38
#define CALL_FG_SET_OFFSET		39
#define CALL_FG_GET_OFFSET		40
#define CALL_FG_STATUS			41
#define CALL_FG_SET_TYPE		42
#define CALL_FG_GET_TYPE		43
#define CALL_FG_SET_ONOFF		44
#define CALL_FG_GET_ONOFF		45
#define CALL_FG_SET_FREQ2		46
#define CALL_FG_GET_FREQ2		47
#define CALL_FG_SET_AMP2		48
#define CALL_FG_GET_AMP2		49
#define CALL_FG_SET_HOLD_ORDER		50
#define CALL_FG_GET_HOLD_ORDER		51

#define CALL_TDE_GET_ADC_ENC_STATE	52

/* prototypes */
int tde_start_acq(double, int, int, int);
int tde_put_maxfreq_simulink(double);
int tde_start_acq_simulink(void);
int tde_stop_acq_simulink(void);
int tde_pause(int);
int tde_set_nsamp(int);
int tde_get_nsamp(void);
int tde_set_ndown(int);
int tde_stop_acq(void);
double tde_get_slope(double *);
int tde_timer_fun(int, int);
int tde_timer_fun_simulink(double*, double*);
int tde_check_data(void);
int tde_say_ready(void);
int tde_get_data(double*, int);
int tde_get_info(double*, double*);
int tde_trigger_on(int, int, double, double, double, int);
int tde_trigger_off(void);
int tde_check_clipping(double*);
int tde_set_adc_state(int, int);
int tde_get_adc_state(double*, int);
int tde_set_enc_state(int, int);
int tde_get_enc_state(double*, int);
int tde_set_dac_state(int, int);
int tde_get_dac_state(double*, int);
int tde_set_adc_offset(double, int);
int tde_get_adc_offset(double*, int);
int tde_init_enc(int);
int tde_get_device_type(int);
int tde_aafilter_on(double, int, int);
int tde_aafilter_off(int);
int tde_set_range(int, int, int);
int tde_get_range(int, int);
int tde_get_filter_enable(int, int);
int tde_get_maxfreq(double*);
int tde_get_obsiv(double*);
int tde_link2meas(int);
int tde_link_is_active(void);

typedef struct tag_tde_cmd
    {
	int id;
	int nargs;
	double* parg[6];
	int retval;
	int status;
	int delayed;
    } tde_cmd, *ptde_cmd;
