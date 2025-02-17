//#define DEBUG
//#define DUMMY

/* Scope engine
 *
 * Rene van de Molengraft, November, 2001
 * revision history: April, 16th, 2003
 *					 June, 21th, 2003: linked to new TUeDACS interface library
 *					 June, 27th, 2003: bug fixes
 *					 July, 2nd, 2003: triggering based on data history
 *					 November, 24th, 2003: MAXFREQ macro can be easily redefined
 *					 March, 7th, 2004: added enhanced trigger signal filtering
 *					 June, 30th, 2004: linux port
 *					 July, 28th, 2004: separated tdext from tde_gate via shared memory ipc
 *					 October, 24th, 2004: maxfreq enters tdext as argument in tde_start_acq
 *					 June, 2005: implemented tcp/ip IPC
 *					 October, 2005: adapted for USB
 *					 October, 9th, 2005: software encoder reset
 *                                       January, 21th, 2011: adapted for use with E-Box
 * Michael Ronde, May, 3rd, 2011: adapted for use with E-box
 *                May, 11th, 2011: added ec_io() to timer_fun
 *                May, 29th, 2011: adapted timer_fun for logical port api
 *                                 cleanup and comments (added prototypes, removed unused variables
 *		  August,31th,2011: Added logging possibility and quick solution to return first device as E/BOX
 * 		  September, 4th, Added funtionality to get number of adc, dac, enc, pwn, din and dout
 *        September,28th, Added posibility for dummy data
 *        September,30th, Fixed funtionalty to get adc and enc state 
 *
 * Rene van de Molengraft, February, 3rd, 2015: Fixed qlgui offset slider.
 *                         October, 26th, 2021: removed hardware stuff, rtscope only
 *
 */
 
#ifndef RTSCOPE_PORT
#define RTSCOPE_PORT        2039
#endif

#define EC_SUCCESS  0

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>
#include <sched.h>

#include "fungen/fungen.h"
#include "fir/fir.h"
#include "../RTScope_shared/incomm/incomm.h"
#include "div/div.h"
#include <string.h>
#include <stdlib.h>

#include "engine.h"

#define DEC	( void *(*)(void*) )






double signval(double x)
{
	if (x>=0) {
		return 1;
	} else {
		return -1;
	}
}





int igetmax(int x, int y)
{
	if (x>=y) {
		return x;
	} else {
		return y;
	}
}





int tde_reset_time(prtscope_global_data prgd)
{
  gettimeofday(&prgd->tv0, NULL);

  return 0;
}





double tde_get_time(prtscope_global_data prgd)
{ 
  double t;

  gettimeofday(&prgd->tva, NULL);

  t=(double) (prgd->tva.tv_sec-prgd->tv0.tv_sec)+((double) (prgd->tva.tv_usec-prgd->tv0.tv_usec))/1000000.0;

  return t;
}





int clear_user_command(prtscope_global_data prgd)
{
    int i;
    
/*  Clear user cmd  */
    prgd->cmd.status=0;
    prgd->cmd.delayed=0;
    prgd->cmd.id=0;
    prgd->cmd.nargs=0;
    for ( i=0; i<6; i++ ) {
        prgd->cmd.parg[i]=NULL;
    }

    return 0;
}





void* shm_thread(void* cookie)
{
    struct sched_param param;
    int policy=SCHED_FIFO;
    int priority_min, priority_max, status;
    pthread_t thread_id;
    int retval;
    prtscope_global_data prgd;
    
    prgd=(prtscope_global_data) cookie;
    printf("shm_thread: prgd = 0x%x\n", (int) prgd);

#if 1
    priority_max = sched_get_priority_max(policy);
    priority_min = sched_get_priority_min(policy);

/*  change priority and policy of thread */

    thread_id = pthread_self();
    param.sched_priority=priority_min;
    status = pthread_setschedparam(thread_id, policy, &param);
    if ( status!=0 ) perror("pthread_setschedparam"); /* error check */
#endif

#if 0
    /* set thread priority */
    memset(&threadschedparam,0,sizeof(threadschedparam));
    threadschedparam.sched_priority=20;
    retval = sched_setscheduler(0, SCHED_FIFO, &threadschedparam);
#ifdef DEBUG    
    printf("Return value= %d (%d %d %d) \n",retval, EINVAL, EPERM, ESRCH);
#endif
#endif

    if ( incomm_server_open(RTSCOPE_PORT)==INCOMM_ERR ) {
        printf("incomm_server_open failed\n");
        tde_stop_acq(prgd);
        return NULL;
    }

    while ( prgd->run ) {
	if ( incomm_server_read((void*) &(prgd->copy_of_shm), sizeof(tde_shm))==INCOMM_ERR ) {
	    printf("read_data failed.\n");
	    return NULL;
	}

//	printf("command %d has arrived!\n",copy_of_shm.cmd_id);

	prgd->cmd.id=prgd->copy_of_shm.cmd_id;

	switch ( prgd->cmd.id ) {
		case CALL_TDE_STOP_ACQ:
		case CALL_TDE_CHECK_DATA:
		case CALL_TDE_SAY_READY:
		case CALL_TDE_TRIGGER_OFF:
		case CALL_TDE_LINK_IS_ACTIVE:
		case CALL_FG_SET_DEFAULTS:
			prgd->cmd.nargs=0;
			break;
		case CALL_TDE_GET_DATA:
			prgd->cmd.nargs=2;
            prgd->cmd.parg[0]=&(prgd->frameToGet->data[0]);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin1);
            //printf("len = %d\n", (int) prgd->copy_of_shm.argin1);
			break;
		case CALL_TDE_GET_INFO:
			prgd->cmd.nargs=2;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.maxchan);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.maxframe);
			break;
		case CALL_TDE_TRIGGER_ON:
			prgd->cmd.nargs=6;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.argin1);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin2);
			prgd->cmd.parg[2]=&(prgd->copy_of_shm.argin3);
			prgd->cmd.parg[3]=&(prgd->copy_of_shm.argin4);
			prgd->cmd.parg[4]=&(prgd->copy_of_shm.argin5);
			prgd->cmd.parg[5]=&(prgd->copy_of_shm.argin6);
			break;
		case CALL_TDE_CHECK_CLIPPING:
			prgd->cmd.nargs=1;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.clip[0]);
			break;
		case CALL_TDE_SET_ADC_STATE:
		case CALL_TDE_SET_ENC_STATE:
		case CALL_TDE_SET_DAC_STATE:
		case CALL_TDE_SET_ADC_OFFSET:
		case CALL_TD_GET_RANGE:
		case CALL_TD_GET_FILTER_ENABLE:
		case CALL_FG_GET_VAL:
		case CALL_FG_SET_AMP1:
		case CALL_FG_SET_AMP2:
		case CALL_FG_SET_FREQ1:
		case CALL_FG_SET_FREQ2:
		case CALL_FG_SET_OFFSET:
		case CALL_FG_SET_TYPE:
		case CALL_FG_SET_HOLD_ORDER:
			prgd->cmd.nargs=2;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.argin1);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin2);
			break;
		case CALL_TDE_GET_ADC_STATE:
		case CALL_TDE_GET_ENC_STATE:
		case CALL_TDE_GET_DAC_STATE:
			prgd->cmd.nargs=2;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.stat);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin1);
			break;
		case CALL_TDE_GET_ADC_OFFSET:
			prgd->cmd.nargs=2;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.offset);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin1);
			break;
		case CALL_TDE_PAUSE:
		case CALL_TDE_SET_NSAMP:
		case CALL_TDE_SET_NDOWN:
		case CALL_TDE_INIT_ENC:
		case CALL_TD_GET_DEVICE_TYPE:
		case CALL_TD_AAFILTER_OFF:
		case CALL_TDE_LINK2MEAS:
		case CALL_FG_START:
		case CALL_FG_STOP:
		case CALL_FG_STATUS:
		case CALL_FG_SET_ONOFF:
			prgd->cmd.nargs=1;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.argin1);
			break;
		case CALL_TD_AAFILTER_ON:
		case CALL_TD_SET_RANGE:
			prgd->cmd.nargs=3;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.argin1);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin2);
			prgd->cmd.parg[2]=&(prgd->copy_of_shm.argin3);
			break;
		case CALL_TDE_GET_MAXFREQ:
			prgd->cmd.nargs=1;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.maxfreq);
			break;
		case CALL_FG_GET_AMP1:
		case CALL_FG_GET_AMP2:
			prgd->cmd.nargs=2;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.amp);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin1);
			break;
		case CALL_FG_GET_FREQ1:
		case CALL_FG_GET_FREQ2:
			prgd->cmd.nargs=2;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.freq);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin1);
			break;
		case CALL_FG_GET_OFFSET:
			prgd->cmd.nargs=2;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.offs);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin1);
			break;
		case CALL_FG_GET_TYPE:
			prgd->cmd.nargs=2;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.type);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin1);
			break;
		case CALL_FG_GET_ONOFF:
			prgd->cmd.nargs=1;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.onoff);
			break;
		case CALL_FG_GET_HOLD_ORDER:
			prgd->cmd.nargs=2;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.holdorder);
			prgd->cmd.parg[1]=&(prgd->copy_of_shm.argin1);
			break;
		case CALL_TDE_GET_ADC_ENC_STATE:
			prgd->cmd.nargs=1;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.allstat[0]);
			break;
        case CALL_EE_GET_NADC:  
        case CALL_EE_GET_NDAC:
        case CALL_EE_GET_NENC:
        case CALL_EE_GET_NPWM:
        case CALL_EE_GET_NDIN:
        case CALL_EE_GET_NDOUT:
			prgd->cmd.nargs=1;
			prgd->cmd.parg[0]=&(prgd->copy_of_shm.argin1);
			break;            
		default:
			printf("Unknown command: %d\n", prgd->cmd.id);
			break;
	}

//	update status
	prgd->cmd.status=prgd->copy_of_shm.cmd_status;
	
	switch ( prgd->cmd.id ) {
#ifndef USB
        case CALL_TDE_INIT_ENC:
        case CALL_TD_AAFILTER_ON:
        case CALL_TD_AAFILTER_OFF:
        case CALL_TD_SET_RANGE:
        case CALL_FG_SET_HOLD_ORDER:

//	        wait for asynchronous command to finish
            prgd->cmd.delayed=1;
            while ( prgd->cmd.delayed==1 ) {
                usleep(1000);
            }

            break;
#endif
        case CALL_TDE_STOP_ACQ:
            break;
        default:
            perform_user_command_direct(prgd);
            break;
    }

//	get return value
	prgd->copy_of_shm.retval=prgd->cmd.retval;
//	printf("Give ready signal\n");
	prgd->copy_of_shm.cmd_status=2;
	
	if ( incomm_server_write((void*) &(prgd->copy_of_shm), sizeof(tde_shm)) == INCOMM_ERR) {
	    printf("write_data failed.\n");
	}

	if ( prgd->cmd.id==CALL_TDE_GET_DATA ) {
//		write data
		if ( incomm_server_write((void*) prgd->cmd.parg[0], *prgd->cmd.parg[1]*sizeof(double)) == INCOMM_ERR) {
		    printf("write_data failed.\n");
		}
	}

//	if (cmd.id==CALL_TDE_STOP_ACQ) {
//		wait for client to hang up...
//		printf("Waiting for client to hang up...\n");
//		incomm_server_read((void*) &ittt, sizeof(int));
//		printf("Hung up.\n");
//	}
	
//	close socket, but not the listening one!
	usleep(1000);
//	if (cmd.id==CALL_TDE_STOP_ACQ) {rtc_sleep(2);}
	incomm_server_close2();
	
//	clear cmd struct
	clear_user_command(prgd);
    }	

    incomm_server_close();

    return NULL;	
}





int perform_user_command_direct(prtscope_global_data prgd)
{
    switch ( prgd->cmd.id ) {
        case CALL_TDE_STOP_ACQ:
            prgd->cmd.retval=(double) tde_stop_acq(prgd);
            break;
        case CALL_TDE_CHECK_DATA:
            prgd->cmd.retval=tde_check_data(prgd);
            break;
        case CALL_TDE_SAY_READY:
            prgd->cmd.retval=tde_say_ready(prgd);
            break;
        case CALL_TDE_GET_DATA:
            //printf("TDE_GET_DATA: = 0x%x, len = %d\n", prgd->cmd.parg[0], (int) *prgd->cmd.parg[1]);
            prgd->cmd.retval=tde_get_data(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], prgd);
            break;
        case CALL_TDE_GET_INFO:
            prgd->cmd.retval=tde_get_info(prgd->cmd.parg[0], prgd->cmd.parg[1]);
            break;
        case CALL_TDE_TRIGGER_ON:
            prgd->cmd.retval=tde_trigger_on((int) *prgd->cmd.parg[0],(int) *prgd->cmd.parg[1], *prgd->cmd.parg[2], *prgd->cmd.parg[3], *prgd->cmd.parg[4], (int) *prgd->cmd.parg[5], prgd);
            break;
        case CALL_TDE_TRIGGER_OFF:
            prgd->cmd.retval=tde_trigger_off(prgd);
            break;
        case CALL_TDE_CHECK_CLIPPING:
            prgd->cmd.retval=tde_check_clipping(prgd->cmd.parg[0], prgd);
            break;
        case CALL_TDE_SET_ADC_STATE:
            prgd->cmd.retval=tde_set_adc_state((int) *prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], prgd);
            break;
        case CALL_TDE_GET_ADC_STATE:
            prgd->cmd.retval=tde_get_adc_state(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], prgd);
            break;
        case CALL_TDE_SET_ENC_STATE:
            prgd->cmd.retval=tde_set_enc_state((int) *prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], prgd);
            break;
        case CALL_TDE_GET_ENC_STATE:
            prgd->cmd.retval=tde_get_enc_state(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], prgd);
            break;
        case CALL_TDE_SET_DAC_STATE:
            prgd->cmd.retval=tde_set_dac_state((int) *prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], prgd);
            break;
        case CALL_TDE_GET_DAC_STATE:
            prgd->cmd.retval=tde_get_dac_state(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], prgd);
            break;
        case CALL_TDE_SET_ADC_OFFSET:
            prgd->cmd.retval=tde_set_adc_offset(*prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], prgd);
            break;
        case CALL_TDE_GET_ADC_OFFSET:
            prgd->cmd.retval=tde_get_adc_offset(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], prgd);
            break;
        case CALL_TDE_PAUSE:
            prgd->cmd.retval=tde_pause((int) *prgd->cmd.parg[0], prgd);
            break;
        case CALL_TDE_SET_NSAMP:
            prgd->cmd.retval=tde_set_nsamp((int) *prgd->cmd.parg[0], prgd);
            break;
        case CALL_TDE_SET_NDOWN:
            prgd->cmd.retval=tde_set_ndown((int) *prgd->cmd.parg[0], prgd);
            break;
        case CALL_TD_GET_DEVICE_TYPE:
	/*      replace cmd.retval=(double) tde_get_device_type((int) *cmd.parg[0]); */
	/*      Return E-box as first and only device */
            if (*prgd->cmd.parg[0] == 0){
                prgd->cmd.retval=1;
            } else {
                prgd->cmd.retval=0;
            }
            break;
        case CALL_TD_GET_RANGE:
            prgd->cmd.retval=tde_get_range((int) *prgd->cmd.parg[0], (int) *prgd->cmd.parg[1]);
            break;
    case CALL_TD_GET_FILTER_ENABLE:
        prgd->cmd.retval=tde_get_filter_enable((int) *prgd->cmd.parg[0], (int) *prgd->cmd.parg[1]);
        break;
    case CALL_TDE_GET_MAXFREQ:
        prgd->cmd.retval=tde_get_maxfreq(prgd->cmd.parg[0], prgd);
        break;
    case CALL_TDE_LINK2MEAS:
        prgd->cmd.retval=tde_link2meas((int) *prgd->cmd.parg[0], prgd);
        break;
    case CALL_TDE_LINK_IS_ACTIVE:
        prgd->cmd.retval=(double) tde_link_is_active(prgd);
        break;
    case CALL_FG_GET_VAL:
        prgd->cmd.retval=fg_get_val(*prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_START:
        prgd->cmd.retval=fg_start((int) *prgd->cmd.parg[0], &prgd->fgd);
        break;
    case CALL_FG_STOP:
        prgd->cmd.retval=fg_stop((int) *prgd->cmd.parg[0], &prgd->fgd);
        break;
    case CALL_FG_SET_DEFAULTS:
        prgd->cmd.retval=fg_set_defaults(&prgd->fgd);
        break;
    case CALL_FG_SET_AMP1:
        prgd->cmd.retval=fg_set_amp1(*prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_GET_AMP1:
        prgd->cmd.retval=fg_get_amp1(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_SET_AMP2:
        prgd->cmd.retval=fg_set_amp2(*prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_GET_AMP2:
        prgd->cmd.retval=fg_get_amp2(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_SET_FREQ1:
        prgd->cmd.retval=fg_set_freq1(*prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_GET_FREQ1:
        prgd->cmd.retval=fg_get_freq1(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_SET_FREQ2:
        prgd->cmd.retval=fg_set_freq2(*prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_GET_FREQ2:
        prgd->cmd.retval=fg_get_freq2(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_SET_OFFSET:
        prgd->cmd.retval=fg_set_offset(*prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_GET_OFFSET:
        prgd->cmd.retval=fg_get_offset(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_STATUS:
        prgd->cmd.retval=(double) fg_status((int) *prgd->cmd.parg[0], &prgd->fgd);
        break;
    case CALL_FG_SET_TYPE:
        prgd->cmd.retval=fg_set_type((int) *prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_GET_TYPE:
        prgd->cmd.retval=fg_get_type(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], &prgd->fgd);
        break;
    case CALL_FG_SET_ONOFF:
        prgd->cmd.retval=fg_set_onoff((int) *prgd->cmd.parg[0], &prgd->fgd);
        break;
    case CALL_FG_GET_ONOFF:
        prgd->cmd.retval=fg_get_onoff(prgd->cmd.parg[0], &prgd->fgd);
        break;
    case CALL_FG_GET_HOLD_ORDER:
        prgd->cmd.retval=fg_get_hold_order(prgd->cmd.parg[0], (int) *prgd->cmd.parg[1]);
        break;
    case CALL_TDE_GET_ADC_ENC_STATE:
        prgd->cmd.retval=tde_get_adc_enc_state(prgd->cmd.parg[0], prgd);
        break;
    /* New E-Scope Enigine Funtionality */
    /* Return globals or get from libec */
#ifdef USB
        case CALL_TDE_INIT_ENC:
        prgd->cmd.retval=tde_init_enc((int) *prgd->cmd.parg[0]);
                break;
        case CALL_TD_AAFILTER_ON:
            prgd->cmd.retval=tde_aafilter_on(*prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], (int) *prgd->cmd.parg[2]);
            break;
        case CALL_TD_AAFILTER_OFF:
            prgd->cmd.retval=tde_aafilter_off((int) *prgd->cmd.parg[0]);
            break;
        case CALL_TD_SET_RANGE:
            prgd->cmd.retval=tde_set_range((int) *prgd->cmd.parg[0], (int) *prgd->cmd.parg[1], (int) *prgd->cmd.parg[2]);
            break;
        case CALL_FG_SET_HOLD_ORDER:
            prgd->cmd.retval=fg_set_hold_order((int) *prgd->cmd.parg[0], (int) *prgd->cmd.parg[1]);
            break;
#endif
        default:
            prgd->cmd.retval=0.0;
            break;
    }

    return 0;
}





#if 0 //seems not to be called
int perform_user_command_delayed(void)
{
    if ( cmd.delayed!=1 ) {
//    	nothing to do
	return 0;
    }

#ifndef USB
    switch (cmd.id)
    {
    case CALL_TDE_INIT_ENC:
	cmd.retval=tde_init_enc((int) *cmd.parg[0]);
	break;
    case CALL_TD_AAFILTER_ON:
	cmd.retval=tde_aafilter_on(*cmd.parg[0],(int) *cmd.parg[1], (int) *cmd.parg[2]); 
	break;
    case CALL_TD_AAFILTER_OFF:
	cmd.retval=tde_aafilter_off((int) *cmd.parg[0]); 
	break;
    case CALL_TD_SET_RANGE:
	cmd.retval=tde_set_range((int) *cmd.parg[0], (int) *cmd.parg[1], (int) *cmd.parg[2]); 
	break;
    case CALL_FG_SET_HOLD_ORDER:
	cmd.retval=fg_set_hold_order((int) *cmd.parg[0], (int) *cmd.parg[1]);
	break;
    default:
	cmd.retval=0.0;
	break;
    }
#endif
    
//  command ready
    cmd.delayed=0;

    return 0;
}
#endif





int tde_put_maxfreq_simulink(double maxfreq, prtscope_global_data prgd)
{
        prgd->tde_maxfreq=maxfreq;
    
//      send maxfreq to function generator also
        fg_put_maxfreq(maxfreq, &prgd->fgd);

        return 0;
}





int tde_start_acq_simulink(prtscope_global_data prgd)
{
	pthread_t t1;
    pthread_attr_t attr_t1;
	int i, nsamp;
//  int iret, err;

    printf("prgd = 0x%x\n", (int) prgd);

    prgd->run=1;
	
//	simulink rtscope
	fg_put_issim(1, &prgd->fgd);
	
//	start value for nsamp
	nsamp=256;

//	store dac down
	prgd->tde_dac_ndown=0;

	prgd->tde_go=0;
	prgd->tde_linked=0;
	fg_notify(0, &prgd->fgd);
	
	prgd->tde_buffer_idx=0;
	prgd->tde_frame_idx=0;
	prgd->tde_started=0;
	prgd->tde_idown=0;
	prgd->tde_dac_idown=0;
	
	if ( nsamp<=MAXFRAME ) {
		prgd->tde_nsamp=nsamp;
	} else {
		printf("tde_start_acq: maximum number of samples is %d.\n", MAXFRAME);
		prgd->tde_nsamp=MAXFRAME;
	}

//	initialize data buffer
    prgd->tde_data=calloc(MAXSAMP*MAXCHAN*2, sizeof(double));
    //printf("size of data = %d bytes\n", sizeof(rtscope_global_data));

//  initialize ringbuffer with space for MAXFRAMES frames
    prgd->rbuf=ringbuf_new(MAXFRAMES*sizeof(frame));
    
//  initialize intermediate frames
    prgd->frameToPut=calloc(1, sizeof(frame));
    prgd->frameToGet=calloc(1, sizeof(frame));

	for (i=0;i<MAXCHAN;i++) {
		prgd->tde_clip[i]=0;
	}

//	clear command structure
	clear_user_command(prgd);

//	start server thread
    pthread_attr_init(&attr_t1);
    //pthread_attr_setstacksize(&attr_t1, 20*1024*1024); // 10 Mb stack size (rtscope_global_data is around 6 Mb)
	if (pthread_create(&t1, &attr_t1, DEC shm_thread, (void*) prgd)) {
	//if (pthread_create(&t1, NULL, DEC shm_thread, (void*) prgd)) {
          printf("pthread_create shm_thread failed.\n");
          return -1;
	 }

//	assume two devices
	prgd->tde_ndevs=2;

	return 0;
}





int tde_pause(int ipause, prtscope_global_data prgd)
{
	int i;
	
	prgd->tde_go=1-ipause;
	i=( prgd->tde_go==1 ) & ( prgd->tde_linked==1 );
	fg_notify(i, &prgd->fgd);
	
	if ( prgd->tde_go==1 ) {
		prgd->tde_buffer_idx=0;
		prgd->tde_frame_idx=0;
		prgd->tde_started=0;
		prgd->tde_idown=0;
	}

//	printf("tde_pause: tde_go = %d.\n",tde_go);	
	
	return 0;
}





int tde_set_nsamp(int nsamp, prtscope_global_data prgd)
{
	double obsiv;
	
	prgd->tde_buffer_idx=0;
	prgd->tde_frame_idx=0;
 
//  reset ring buffer
    ringbuf_reset(prgd->rbuf);

	prgd->tde_nsamp=nsamp;

//	(re)calculate obsiv
	obsiv=((double) prgd->tde_nsamp)/(prgd->tde_maxfreq/(((double) prgd->tde_ndown)+1.0));

//	send obsiv to function generator also
	fg_put_obsiv(obsiv, &prgd->fgd);

	return 0;
}





#if 0 // seems not to be called
int tde_get_nsamp(prtscope_global_data prgd)
{
    return prgd->tde_nsamp;
}
#endif





int tde_set_ndown(int ndown, prtscope_global_data prgd)
{
	double obsiv;
	
	prgd->tde_idown=0;
	prgd->tde_ndown=ndown;

//	(re)calculate obsiv
	obsiv=((double) prgd->tde_nsamp)/(prgd->tde_maxfreq/(((double) prgd->tde_ndown)+1.0));

//	send obsiv to function generator also
	fg_put_obsiv(obsiv, &prgd->fgd);

	return 0;
}





int tde_stop_acq(prtscope_global_data prgd)
{
//	stop data acquisition engine
	prgd->tde_go=-1;
	fg_notify(0, &prgd->fgd);
	
//	stop shm server as well!
	prgd->run=0;
 
//  cleanup memory
    free(prgd->frameToPut);
    free(prgd->frameToGet);
    ringbuf_free(&prgd->rbuf);
    free(prgd->tde_data);

	return 0;
}





double tde_get_slope(double *pval_hist)
{
	int i,ndata,norder;
	double **xdata,**ydata,**coeff,**pd,res;
	
	ndata=MAXHIST;
	xdata=create_double_matrix(ndata, 1);
	ydata=create_double_matrix(ndata, 1);

//	points are in opposite order, so result will also have opposite sign...
	for (i=0;i<ndata;i++) {
		xdata[i][0]=(double) i;
		ydata[i][0]=pval_hist[i];
	}

//	fit line
	norder=1;

	coeff=create_double_matrix(norder+1, 1);
	polyfit(coeff, xdata, ydata, ndata, norder);

	pd=create_double_matrix(norder+1, 1);
	polyget(pd, 0.0, coeff, norder);
	res=pd[1][0];

//	free allocated memory
	destroy_double_matrix(xdata, ndata, 1);
	destroy_double_matrix(ydata, ndata, 1);
	destroy_double_matrix(coeff, norder+1, 1);
	destroy_double_matrix(pd, norder+1, 1);

	return res;
}





int tde_timer_fun_simulink(double* pmeas, double* psteer, prtscope_global_data prgd)
{
	int i, j, idx, ichan, imeas, dac_imeas;
	double time,ttt;
#ifdef WINDOWS
    uint32_t availableBytesWriting;
#else
    u_int32_t availableBytesWriting;
#endif
    
//	current time
	time=tde_get_time(prgd);

//	adjust dac rate
	dac_imeas=1;
	if ( prgd->tde_dac_idown<prgd->tde_dac_ndown ) {
		prgd->tde_dac_idown++;
		dac_imeas=0;
	}
	
	if ( dac_imeas==1 ) {
		if ( prgd->tde_dac_idown==prgd->tde_dac_ndown) prgd->tde_dac_idown=0;
		
		for ( ichan=0; ichan<4; ichan++ ) {
			psteer[ichan]=fg_get_val(time, ichan, &prgd->fgd);
		}
//		printf("psteer[0]=%f\n",psteer[0]);
	}

	if ( prgd->tde_go==0 ) return 0;
	if ( prgd->tde_go==-1 ) return 1;

	if ( !prgd->tde_started ) {
		tde_reset_time(prgd);
		prgd->tde_started=1;
	}

//	adjust sampling frequency
	imeas=1;
	if ( prgd->tde_idown<prgd->tde_ndown ) {
		prgd->tde_idown++;
		imeas=0;
	}
	
	if ( imeas==1 ) {
		if ( prgd->tde_idown==prgd->tde_ndown ) prgd->tde_idown=0;
		
		for ( ichan=0; ichan<4; ichan++ ) {
//		    read adc channels
		    ttt=pmeas[ichan]+prgd->tde_adc_offset[ichan];
//		    store in cyclic buffer
		    (&prgd->tde_data[0]+prgd->tde_buffer_idx*MAXCHAN*2+ichan)[0]=ttt;
										
//		    read enc channels (sf_qadscope features 4+4 channels)
		    ttt=pmeas[4+ichan];
//		    store in cyclic buffer
		    prgd->tde_last_enc[ichan]=ttt-prgd->tde_enc0[ichan];
		    (&prgd->tde_data[0]+prgd->tde_buffer_idx*MAXCHAN*2+MAXCHAN+ichan)[0]=prgd->tde_last_enc[ichan];
		}

//		check trigger condition
		if ( prgd->tde_trigger==1 ) {

//			current trigger signal value
			prgd->tde_trig_val_hist[0]=fir_filter((&prgd->tde_data[0]+prgd->tde_buffer_idx*MAXCHAN*2+prgd->tde_trig_signal)[0], MAXCHAN+1, &prgd->fd);
			if ( prgd->tde_buffer_idx==0 ) {
//				there's no history yet...
				prgd->tde_trig_val_hist[1]=prgd->tde_trig_val_hist[0];
			}
		
//			no triggering before preroll has been passed
			if ( prgd->tde_trig_state==TRIG_STATE_WAIT ) {
//				if ( prgd->tde_buffer_idx>=igetmax((int) (prgd->tde_trig_preroll*prgd->tde_nsamp), prgd->tde_ntaps)) {
//				PATCHED 01-11-05
				if (prgd->tde_buffer_idx>=igetmax((int) ((prgd->tde_trig_preroll+1)*prgd->tde_nsamp), prgd->tde_ntaps)) {
					prgd->tde_trig_state=TRIG_STATE_GO;
				}
			}

			if ( prgd->tde_trig_state==TRIG_STATE_GO ) {
				switch ( prgd->tde_trig_type ) {
				case 0:
//					positive slope
					if ( (prgd->tde_trig_val_hist[0]-prgd->tde_trig_val_hist[1])>0.0 ) {
						if ( (prgd->tde_trig_val_hist[0]-prgd->tde_trig_level)*(prgd->tde_trig_level-prgd->tde_trig_val_hist[1])>0.0) {
#ifdef DEBUG
							printf("Triggered: positive slope\n");
							printf("hist[0]-hist[1]=%f\n", prgd->tde_trig_val_hist[0]-prgd->tde_trig_val_hist[1]);
#endif
							prgd->tde_trig_state=TRIG_STATE_DONE;
							prgd->tde_triggered=1;
							prgd->tde_frame_idx=((int) (prgd->tde_trig_preroll*prgd->tde_nsamp))+prgd->tde_ntaps/2;
						}
					}
					break;
				case 1:
//					negative slope
					if ( (prgd->tde_trig_val_hist[0]-prgd->tde_trig_val_hist[1])<0.0 ) {
						if ( (prgd->tde_trig_val_hist[0]-prgd->tde_trig_level)*(prgd->tde_trig_level-prgd->tde_trig_val_hist[1])>0.0) {
#ifdef DEBUG
							printf("Triggered: negative slope\n");							
							printf("hist[0]-hist[1]=%f\n", prgd->tde_trig_val_hist[0]-prgd->tde_trig_val_hist[1]);
#endif
							prgd->tde_trig_state=TRIG_STATE_DONE;
							prgd->tde_triggered=1;
							prgd->tde_frame_idx=((int) (prgd->tde_trig_preroll*prgd->tde_nsamp))+prgd->tde_ntaps/2;
						}
					}
					break;
				}
			}

//			store trigger history
			prgd->tde_trig_val_hist[1]=prgd->tde_trig_val_hist[0];

		}

		if ( prgd->tde_frame_idx>=prgd->tde_nsamp-1 ) {
#ifdef DEBUG
			//printf("tde_frame_idx = %d\n", prgd->tde_frame_idx);
#endif
			if ( (prgd->tde_trigger==0) | (prgd->tde_triggered==1) ) {
//				store index and pointer	
				prgd->tde_data_idx=prgd->tde_buffer_idx+1-prgd->tde_nsamp;

//				cycle compensation
				if ( prgd->tde_data_idx<0 ) {prgd->tde_data_idx=MAXSAMP+prgd->tde_data_idx;}

//              copy frame to ringbuffer
                availableBytesWriting=ringbuf_bytes_free(prgd->rbuf);
                if ( availableBytesWriting<sizeof(frame) ) {
                    ringbuf_reset(prgd->rbuf);
                }
//              prepare frame
                prgd->frameToPut->nsamp=prgd->tde_nsamp;
                //printf("nsamp = %d\n", prgd->tde_nsamp);
                for ( i=0; i<prgd->frameToPut->nsamp; i++ ) {
                    idx=prgd->tde_data_idx+i;
                    if ( idx>=MAXSAMP ) { idx=idx-MAXSAMP; }
                    for ( j=0; j<MAXCHAN*2; j++ ) {
                        prgd->frameToPut->data[i*MAXCHAN*2+j]=prgd->tde_data[idx*MAXCHAN*2+j];
                    }
                }
                ringbuf_memcpy_into(prgd->rbuf, prgd->frameToPut, sizeof(frame));

//				next frame
				prgd->tde_frame_idx=-1;
			}

			if ( (prgd->tde_trigger==1) & (prgd->tde_triggered==1) ) {
//				reset trigger
				prgd->tde_triggered=0;
				prgd->tde_trig_state=TRIG_STATE_WAIT;
			}
		}
		
//		next frame sample
		prgd->tde_frame_idx++;

//		next buffer sample
		if ( prgd->tde_buffer_idx==MAXSAMP-1 ) {
//			let's cycle...
			prgd->tde_buffer_idx=-1;
		}
		prgd->tde_buffer_idx++;

	}

	return EC_SUCCESS;

}





// 1 means no data..
int tde_check_data(prtscope_global_data prgd)
{
#ifdef WINDOWS
    uint32_t availableBytesReading;
#else
    u_int32_t availableBytesReading;
#endif
    
//  check for data
    availableBytesReading=ringbuf_bytes_used(prgd->rbuf);
    if ( availableBytesReading>=sizeof(frame) ) {
        return 0;
    } else {
        return 1;
    }
}





int tde_say_ready(prtscope_global_data prgd)
{
//  this is a signal given by the rtscope ui, obsolete

	return 1;
}





int tde_get_data(double* pdata, int ldata, prtscope_global_data prgd)
{
    int i, n;
    u_int32_t availableBytesReading;
    
    memset(prgd->frameToGet, 0, sizeof(frame));

//  read most recent frame
    availableBytesReading=ringbuf_bytes_used(prgd->rbuf);
    n=(int) (1.*availableBytesReading/sizeof(frame)+0.5);
    for ( i=0; i<n; i++ ) {
        ringbuf_memcpy_from(prgd->frameToGet, prgd->rbuf, sizeof(frame));
    }
    
    if ( ldata!=(prgd->frameToGet->nsamp*MAXCHAN*2) ) {
//      size does not match, set to zero
        memset(prgd->frameToGet, 0, sizeof(frame));
    }

    return 0;
}





int tde_get_info(double* pmaxchan, double* pmaxframe)
{
	pmaxchan[0]=(double) MAXCHAN;
	pmaxframe[0]=(double) MAXFRAME;
	
	return 0;
}





static int tde_get_link_id(int* pichan, int* pilink)
{
        int i,j;
    
//      reconstruct channel id and link id from channel number
        i=*pichan;
        j=0;
        while (i>1) {
                j++;
                i=i-2;
        }

//      channel id
        *pichan=i;    

//      link id
        *pilink=j;
    
        return 0;
}





int tde_trigger_on(int isignal, int itype, double level, double preroll, double relfreq, int nsamp, prtscope_global_data prgd)
{
	int i,go_bak;
	
//	halt measurement
	go_bak=prgd->tde_go;
	prgd->tde_go=0;
	fg_notify(0, &prgd->fgd);
	usleep(10000);

//	restart buffer/frame
	prgd->tde_buffer_idx=0;

//	trigger on, but not yet triggered
	prgd->tde_trigger=1;
	prgd->tde_triggered=0;
	prgd->tde_trig_state=TRIG_STATE_WAIT;

//	set trigger signal
	prgd->tde_trig_signal=isignal;

//	set trigger type
	prgd->tde_trig_type=itype;

//	set trigger level
	prgd->tde_trig_level=level;

//	set trigger preroll
	prgd->tde_trig_preroll=preroll;

//	initialize trigger fir filter
	prgd->tde_ntaps=fir_init(MAXCHAN+1, &prgd->fd);
#ifdef DEBUG
    //printf("trigger on isignal=%d \t", isignal);
	//printf("tde_ntaps = %d\n", prgd->tde_ntaps);
#endif

//	design trigger fir filter
	fir_design(relfreq, MAXCHAN+1, &prgd->fd);

//	restore tde_go
	prgd->tde_go=go_bak;
	i=( prgd->tde_go==1 ) & ( prgd->tde_linked==1 );
	fg_notify(i, &prgd->fgd);
	 
	return 0;
}





int tde_trigger_off(prtscope_global_data prgd)
{
	prgd->tde_trigger=0;
	prgd->tde_triggered=0;

	return 0;
}





int tde_check_clipping(double* pclip, prtscope_global_data prgd)
{
	int i;
	
	for ( i=0; i<MAXCHAN; i++ ) {
		pclip[i]=(double) prgd->tde_clip[i];
/*        printf("channel %d tde_clip = %d\n", i, prgd->tde_clip[i]);*/
	}

	return 0;
}





int tde_set_adc_state(int istat, int ichan, prtscope_global_data prgd)
{
    prgd->tde_adc_state[ichan]=istat;
    
    return 0;
}





int tde_get_adc_state(double* pstat, int port_id, prtscope_global_data prgd)
{
    pstat[0]=(double) prgd->tde_adc_state[port_id];
    
    return 0;
}





int tde_set_enc_state(int istat, int ichan, prtscope_global_data prgd)
{
    prgd->tde_enc_state[ichan]=istat;

    return 0;
}





int tde_get_enc_state(double* pstat, int port_id, prtscope_global_data prgd)
{
    pstat[0]=(double) prgd->tde_enc_state[port_id];
    
    return 0;
}





int tde_set_dac_state(int istat, int ichan, prtscope_global_data prgd)
{
    prgd->tde_dac_state[ichan]=istat;
    
    return 0;
}





int tde_get_dac_state(double* pstat, int ichan, prtscope_global_data prgd)
{
    pstat[0]=(double) prgd->tde_dac_state[ichan];
    
    return 0;
}





int tde_set_adc_offset(double offset, int ichan, prtscope_global_data prgd)
{
	prgd->tde_adc_offset[ichan]=offset;
	
	return 0;
}





int tde_get_adc_offset(double* poffset, int ichan, prtscope_global_data prgd)
{
	poffset[0]=prgd->tde_adc_offset[ichan];
	
	return 0;
}





int tde_init_enc(int ichan, prtscope_global_data prgd)
{
//	current count value becomes reset value
    prgd->tde_enc0[ichan]=prgd->tde_last_enc[ichan];

	return 0;
}






int tde_aafilter_on(double freq, int iconfig, int ilink)
{
    return 0;
}





int tde_aafilter_off(int ilink)
{
    return 0;
}





int tde_set_range(int irange, int ichan, int ilink)
{
    return 0;
}





int tde_get_range(int ichan, int ilink)
{
    return 0;
}





int tde_get_filter_enable(int ichan, int ilink)
{
    return 0;
}





int tde_get_maxfreq(double* pmaxfreq, prtscope_global_data prgd)
{
	pmaxfreq[0]=prgd->tde_maxfreq;
	
	return 0;
}





int tde_link2meas(int ilinked, prtscope_global_data prgd)
{
	int i;
	
	prgd->tde_linked=ilinked;
	i= ( prgd->tde_go==1 ) & ( prgd->tde_linked==1 );
	fg_notify(i, &prgd->fgd);

	return 0;
}





int tde_link_is_active(prtscope_global_data prgd)
{
	return ( prgd->tde_go==1 ) & ( prgd->tde_linked==1 );
}





int tde_get_adc_enc_state(double* pallstat, prtscope_global_data prgd)
{
	int status,i;
	
	for ( i=0; i<MAXCHAN; i++ ) {
	    status=tde_get_adc_state(pallstat+i, i, prgd);
	    status=tde_get_enc_state(pallstat+MAXCHAN+i, i, prgd);
	}

	return status;
}

