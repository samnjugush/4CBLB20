#ifndef ENGINE_H
#define ENGINE_H

#include <sys/time.h>
#include "constants.h"
#include "c-ringbuf-master/ringbuf.h"
#include "fir/fir.h"
#include "fungen/fungen.h"

/* macros */

#define MAXHIST		5

#define TRIG_STATE_WAIT		0
#define TRIG_STATE_GO		1
#define TRIG_STATE_DONE		2

#define CMD_STATUS_IDLE		0
#define CMD_STATUS_PENDING	1
#define CMD_STATUS_READY	2

#define DEVICE_NOT_READY	-1

#define EBOX_NONE_FOUND         0

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
#define CALL_OPEN_INCOMM_CLIENT		53
#define CALL_CLOSE_INCOMM_CLIENT	54

/* New E-Scope Enigine Funtionality */
#define CALL_EE_GET_NADC    101
#define CALL_EE_GET_NDAC    102
#define CALL_EE_GET_NENC    103
#define CALL_EE_GET_NPWM    104
#define CALL_EE_GET_NDIN    105
#define CALL_EE_GET_NDOUT   106





// frame as stored in ringbuffer
typedef struct tag_frame {
    int nsamp;
    double data[MAXFRAME*MAXCHAN*2];
} frame, *pframe;





typedef struct tag_tde_cmd
    {
	int id;
	int nargs;
	double* parg[6];
	int retval;
	int status;
	int delayed;
    } tde_cmd, *ptde_cmd;

typedef struct tag_tde_shm
	{
		int stop_server;
		int cmd_id;
		int cmd_status;
		double argin1;
		double argin2;
		double argin3;
		double argin4;
		double argin5;
		double argin6;
		double retval;
		double maxchan;
		double maxframe;
		double clip[MAXCHAN];
		double stat;
		double offset;
		double maxfreq;
		double amp;
		double freq;
		double offs;
		double type;
		double onoff;
		double holdorder;
		double allstat[2*MAXCHAN];
	} tde_shm, *ptde_shm;
 
 
 
 
 
typedef struct tag_rtscope_global_data {
/* Number of ports per type */
    int tde_ndevs;           /* Obsolete ?*/
    int tde_nadc;
    int tde_ndac;
    int tde_nenc;

    int tde_started;
    //double tde_data[MAXSAMP*MAXCHAN*2];
    double* tde_data;
    
//  ringbuffer
    struct ringbuf_t* rbuf;

    int tde_nsamp;       /* number of samples/frame */
    int tde_buffer_idx;  /* index for data buffer */
    int tde_frame_idx;
    int tde_data_idx;
    int tde_go;
    int tde_ndown;   /* downsampling factor of ADC and ENC */
    int tde_idown;   /* counter for ignored values due to downsamping */
    int tde_trigger;
    int tde_triggered;
    int tde_trig_signal;
    int tde_trig_type;
    int tde_trig_state;
    int tde_clip[MAXCHAN];   /* adc clipped ?*/
    int tde_linked;
    double tde_adc_offset[MAXCHAN];
/* static double tde_freq; */
    double tde_trig_level;
    double tde_trig_preroll;
    double tde_trig_val_hist[MAXHIST];
    int tde_ntaps;
/* static int tde_timer_stopped; */
    double tde_maxfreq;
    int tde_dac_ndown;   /* downsampling factor of DAC */
    int tde_dac_idown;   /* counter for ignored values due to downsamping */
    int tde_running;
    double tde_enc0[MAXCHAN];
    double tde_last_enc[MAXCHAN];

/*  states used for simulink purposes */
    int tde_adc_state[MAXCHAN];
    int tde_enc_state[MAXCHAN];
    int tde_dac_state[MAXCHAN];

//  user command
    tde_cmd cmd;

    int run;

    tde_shm copy_of_shm;
    frame* frameToGet;
    frame* frameToPut;
    
    struct timeval tv0, tva;

    fir_data fd;
    fungen_data fgd;
} rtscope_global_data, *prtscope_global_data;





/* prototypes */
int tde_put_maxfreq_simulink(double, prtscope_global_data);
int tde_start_acq_simulink(prtscope_global_data);
int tde_pause(int, prtscope_global_data);
int tde_set_nsamp(int, prtscope_global_data);
int tde_get_nsamp(prtscope_global_data);
int tde_set_ndown(int, prtscope_global_data);
int tde_stop_acq(prtscope_global_data);
double tde_get_slope(double *);
int tde_timer_fun_simulink(double*, double*, prtscope_global_data);
int tde_check_data(prtscope_global_data);
int tde_say_ready(prtscope_global_data);
int tde_get_data(double*, int, prtscope_global_data);
int tde_get_info(double*, double*);
int tde_trigger_on(int, int, double, double, double, int, prtscope_global_data);
int tde_trigger_off(prtscope_global_data);
int tde_check_clipping(double*, prtscope_global_data);
int tde_set_adc_state(int, int, prtscope_global_data);
int tde_get_adc_state(double*, int, prtscope_global_data);
int tde_set_enc_state(int, int, prtscope_global_data);
int tde_get_enc_state(double*, int, prtscope_global_data);
int tde_set_dac_state(int, int, prtscope_global_data);
int tde_get_dac_state(double*, int, prtscope_global_data);
int tde_set_adc_offset(double, int, prtscope_global_data);
int tde_get_adc_offset(double*, int, prtscope_global_data);
int tde_init_enc(int, prtscope_global_data);
int tde_get_device_type(int);
int tde_aafilter_on(double, int, int);
int tde_aafilter_off(int);
int tde_set_range(int, int, int);
int tde_get_range(int, int);
int tde_get_filter_enable(int, int);
int tde_get_maxfreq(double*, prtscope_global_data);
int tde_link2meas(int, prtscope_global_data);
int tde_link_is_active(prtscope_global_data);
int tde_get_adc_enc_state(double*, prtscope_global_data);
int perform_user_command_direct(prtscope_global_data);

#endif
