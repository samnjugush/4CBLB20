
/* Matlab MEX gate for communication with scope kernel */

/*
    Ren� van de Molengraft, November, 2001
    last updated:   January, 26th, 2003
                    June, 22th, 2003: adapted for new tdext
                    February, 6th, 2004: added tde_get_maxfreq method
                    March, 7th, 2004: adapted for enhanced trigger signal filtering
                    June, 30th, 2004: linux port
                    July, 28th, 2004: separated tde_gate from tdext via shared memory ipc
                    December, 5th, 2004: added hold order methods
                    March, 5th, 2005: changed error handling on behalf of rtscope
                    April, 28th, 2005: error return value changed too ERRRETVAL=-1000000 instead of -1
				       offsets can also return (small!) negative values!
				       this is merely a patch than a nice solution...
                    June, 7th, 2005: adapted for RTAI-fusion
                    June, 21th, 2005: switched to network IPC
                    January, 21th, 2011: rebuilt for E-Box
                    October, 28th, 2021: ip address and port configuration via macro
                    December, 10th, 2021: ip address as first input argument
		    */

#ifndef RTSCOPE_IP_ADDRESS
#define RTSCOPE_IP_ADDRESS  "127.0.0.1"
#endif

#ifndef RTSCOPE_PORT
#define RTSCOPE_PORT        2039
#endif

#define ERRRETVAL               -1000000
#define ERR_INCOMM_CLIENT_OPEN	-1000001
#define ERR_INCOMM_CLIENT_WRITE	-1000002
#define ERR_INCOMM_CLIENT_READ	-1000003
#define ERR_INCOMM_CLIENT_CLOSE	-1000004

#include <math.h>
#include <mex.h>
#include <matrix.h>
#include "../../RTScope_engine/engine.h"
#include "../../RTScope_shared/incomm/incomm.h"
#include "stdlib.h"
#include "string.h"





/* input arguments */
#define	ARGIN0 prhs[0]
#define	ARGIN1 prhs[1]
#define	ARGIN2 prhs[2]
#define	ARGIN3 prhs[3]
#define	ARGIN4 prhs[4]
#define	ARGIN5 prhs[5]
#define	ARGIN6 prhs[6]
#define	ARGIN7 prhs[7] // last one is ip address

/* output argument */
#define	ARGOUT0 plhs[0]
#define ARGOUT1 plhs[1]
#define ARGOUT2 plhs[2]

static int tde_gate_err=0;





int mexErrMsgTxtFree(char* pstring, ptde_shm pthe_shm)
{
    tde_gate_err=1;

    mexErrMsgTxt(pstring);

    return 0;
}





int tde_gate_cmd_begin(int icall, ptde_shm pthe_shm)
{
	pthe_shm->cmd_id=icall;
	pthe_shm->cmd_status=1;

	return 0;
}





int tde_gate_cmd_wait(char* ip, int icall, ptde_shm pthe_shm, double* pdata, int nsamp)
{
	int err,icnt,maxcount;
    FILE* fid;
    
    if ( strlen(ip)==0 ) {
//      default is localhost
        strcpy(ip, "127.0.0.1");
    }

/*	open socket */
	//if (incomm_client_open(RTSCOPE_IP_ADDRESS, RTSCOPE_PORT)==-1) {
	if (incomm_client_open(ip, RTSCOPE_PORT)==-1) {
/*		set error status */
		mexPrintf("incomm_client_open failed.\n");
		tde_gate_err=1;
		pthe_shm->retval=(double) ERR_INCOMM_CLIENT_OPEN;
		return -1;
	}
	
	if (incomm_client_write((void*) pthe_shm, sizeof(tde_shm))==-1) {
		mexPrintf("incomm_client_write failed.\n");
/*		reset shm */
		memset(pthe_shm,0,sizeof(tde_shm));
/*		set error status */
		tde_gate_err=1;
		pthe_shm->retval=(double) ERR_INCOMM_CLIENT_WRITE;
		return -1;		
	}
	
	if (incomm_client_read((void*) pthe_shm, sizeof(tde_shm))==-1) {
		mexPrintf("incomm_client_read failed.\n");
/*		reset shm */
		memset(pthe_shm,0,sizeof(tde_shm));
/*		set error status */
		tde_gate_err=1;
		pthe_shm->retval=(double) ERR_INCOMM_CLIENT_READ;
		return -1;		
	}

	if (icall==CALL_TDE_GET_DATA) {
/*		read data */
		if (incomm_client_read((void*) pdata, nsamp*sizeof(double))==-1) {
			mexPrintf("incomm_client_read failed.\n");
/*			reset data */
			memset(pdata,0,nsamp*sizeof(double));
/*			set error status */			
            tde_gate_err=1;
			pthe_shm->retval=(double) ERR_INCOMM_CLIENT_READ;
			return -1;
		}
	}

/*	close socket */
	if (incomm_client_close()==-1) {
		mexPrintf("incomm_client_close failed.\n");
		tde_gate_err=1;
		pthe_shm->retval=(double) ERR_INCOMM_CLIENT_CLOSE;
		return -1;		
	}

	return 0;
}





void mexFunction(int nlhs, mxArray* plhs[], 
		 int nrhs, const mxArray* prhs[])
{ 
	int icall,nrows,ncols;
	double *pcall, *pargin1, *pargin2, *pargin3, *pargin4, *pargin5, *pargin6;
    char* ip;
	double *pretval, *pdata, *pmaxchan, *pmaxframe, *pclip, *pstat, *poffset, *pmaxfreq, *pallstat;
	double *pamp,*pfreq,*poffs,*ptype,*ponoff,*pholdorder;
	ptde_shm pthe_shm;
	double ptde_data;
		
/*
	if (tde_gate_err==1) {
		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		pretval[0]=ERRRETVAL;
		return;
*/
/*		mexErrMsgTxt("tde_gate: kernel is not running (is TUeDACS/1 properly connected?)");*/
/*
	}
*/
	
	if (nrhs==0) {
		mexErrMsgTxtFree("At least one input argument required.",pthe_shm);
	}
	
	pthe_shm=(ptde_shm) mxMalloc(sizeof(tde_shm));
	memset(pthe_shm,0,sizeof(tde_shm));

	pcall=(double*) mxGetPr(ARGIN0);
	icall=(int) pcall[0];
/*	printf("tde_gate reports: icall = %d\n",icall);*/
		
	switch (icall)
	{
	case CALL_TDE_START_ACQ:
		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_TDE_START_ACQ).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=(double*) mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1), pargin1, sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2), pargin2, sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
    
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_TDE_STOP_ACQ:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input argument required (CALL_TDE_STOP_ACQ).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
							
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TDE_CHECK_DATA:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input argument required (CALL_TDE_CHECK_DATA).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
							
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);

		break;

	case CALL_TDE_SAY_READY:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input argument required (CALL_TDE_SAY_READY).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
							
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);

		break;

	case CALL_TDE_GET_DATA:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_GET_DATA).", pthe_shm);
		}

		nrows=(int) (MAXCHAN*2);
		pargin1=mxGetPr(ARGIN1);		
		ncols=(int) (pargin1[0]/(MAXCHAN*2));
		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(nrows,ncols,mxREAL);
		pdata=mxGetPr(ARGOUT0);
		
		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);

		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, pdata, *pargin1);

		break;

	case CALL_TDE_GET_INFO:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input argument required (CALL_TDE_GET_INFO).", pthe_shm);
		}
		
		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pmaxchan=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pmaxframe=mxGetPr(ARGOUT1);

		ARGOUT2=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT2);

		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
							
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		memcpy(pmaxchan,&(pthe_shm->maxchan),sizeof(double));
		if (pthe_shm->maxchan!=MAXCHAN) {
			printf("maxchan=%d\n",pthe_shm->maxchan);
			mexErrMsgTxtFree("TDE_GATE MUST BE RECOMPILED (INCONSISTENT MAXCHAN).",pthe_shm);
		}
				
		memcpy(pmaxframe,&(pthe_shm->maxframe),sizeof(double));
		if (pthe_shm->maxframe!=MAXFRAME) {
			printf("maxframe=%d\n",pthe_shm->maxframe);
			mexErrMsgTxtFree("TDE_GATE MUST BE RECOMPILED (INCONSISTENT MAXFRAME).",pthe_shm);
		}

		break;

	case CALL_TDE_TRIGGER_ON:

		if (nrhs!=8) {
			mexErrMsgTxtFree("Eight input arguments required (CALL_TDE_TRIGGER_ON).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
				
		pargin3=mxGetPr(ARGIN3);
		memcpy(&(pthe_shm->argin3),pargin3,sizeof(double));
				
		pargin4=mxGetPr(ARGIN4);
		memcpy(&(pthe_shm->argin4),pargin4,sizeof(double));
				
		pargin5=mxGetPr(ARGIN5);
		memcpy(&(pthe_shm->argin5),pargin5,sizeof(double));
				
		pargin6=mxGetPr(ARGIN6);
		memcpy(&(pthe_shm->argin6),pargin6,sizeof(double));
        
  		ip=mxArrayToString(ARGIN7);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);

		break;

	case CALL_TDE_TRIGGER_OFF:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input argument required (CALL_TDE_TRIGGER_OFF).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
							
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);

		break;

	case CALL_TDE_CHECK_CLIPPING:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input argument required (CALL_TDE_CHECK_CLIPPING).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix((int) MAXCHAN,1,mxREAL); 
		pclip=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);
		
		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
					
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);

		memcpy(pclip,&(pthe_shm->clip),MAXCHAN*sizeof(double));

		break;

	case CALL_TDE_SET_ADC_STATE:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_TDE_SET_ADC_STATE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
				
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TDE_GET_ADC_STATE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_GET_ADC_STATE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
  		ip=mxArrayToString(ARGIN2);
				
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pstat=mxGetPr(ARGOUT0);
		memcpy(pstat,&(pthe_shm->stat),sizeof(double));
		
		break;

	case CALL_TDE_SET_ENC_STATE:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_TDE_SET_ENC_STATE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
				
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TDE_GET_ENC_STATE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_GET_ENC_STATE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		ip=mxArrayToString(ARGIN2);
				
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pstat=mxGetPr(ARGOUT0);
		memcpy(pstat,&(pthe_shm->stat),sizeof(double));
		
		break;

	case CALL_TDE_SET_DAC_STATE:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_TDE_SET_DAC_STATE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
				
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TDE_GET_DAC_STATE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_GET_DAC_STATE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pstat=mxGetPr(ARGOUT0);
		memcpy(pstat,&(pthe_shm->stat),sizeof(double));
		
		break;

	case CALL_TDE_SET_ADC_OFFSET:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_TDE_SET_ADC_OFFSET).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
				
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TDE_GET_ADC_OFFSET:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_GET_ADC_OFFSET).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		poffset=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		memcpy(poffset,&(pthe_shm->offset),sizeof(double));
		
		break;
	
	case CALL_TDE_PAUSE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_PAUSE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TDE_SET_NSAMP:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_SET_NSAMP).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TDE_SET_NDOWN:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_SET_NDOWN).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;


	case CALL_TDE_INIT_ENC:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_INIT_ENC).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
				
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TD_GET_DEVICE_TYPE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TD_GET_DEVICE_TYPE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
				
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TD_AAFILTER_ON:

		if (nrhs!=5) {
			mexErrMsgTxtFree("Five input arguments required (CALL_TD_AAFILTER_ON).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
				
		pargin3=mxGetPr(ARGIN3);
		memcpy(&(pthe_shm->argin3),pargin3,sizeof(double));
  
		ip=mxArrayToString(ARGIN4);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TD_AAFILTER_OFF:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TD_AAFILTER_OFF).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_TD_SET_RANGE:

		if (nrhs!=5) {
			mexErrMsgTxtFree("Five input arguments required (CALL_TD_SET_RANGE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
				
		pargin3=mxGetPr(ARGIN3);
		memcpy(&(pthe_shm->argin3),pargin3,sizeof(double));
  
		ip=mxArrayToString(ARGIN4);
				
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_TD_GET_RANGE:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_TD_GET_RANGE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TD_GET_FILTER_ENABLE:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_TD_GET_FILTER_ENABLE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TDE_GET_MAXFREQ:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input argument required (CALL_TDE_GET_MAXFREQ).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pmaxfreq=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);
		
		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
					
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		memcpy(pmaxfreq,&(pthe_shm->maxfreq),sizeof(double));
		
		break;

	case CALL_TDE_LINK2MEAS:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_TDE_LINK2MEAS).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_TDE_LINK_IS_ACTIVE:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input argument required (CALL_TDE_LINK_IS_ACTIVE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
							
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_FG_GET_VAL:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_FG_GET_VAL).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);

		break;
		
	case CALL_FG_START:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_START).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_FG_STOP:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_STOP).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_FG_SET_DEFAULTS:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input argument required (CALL_FG_SET_DEFAULTS).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
							
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_FG_SET_AMP1:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_FG_SET_AMP1).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
			
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		break;

	case CALL_FG_GET_AMP1:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_GET_AMP1).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pamp=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		memcpy(pamp,&(pthe_shm->amp),sizeof(double));
		
		break;

	case CALL_FG_SET_AMP2:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_FG_SET_AMP2).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_FG_GET_AMP2:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_GET_AMP2).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pamp=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		memcpy(pamp,&(pthe_shm->amp),sizeof(double));
		
		break;

	case CALL_FG_SET_FREQ1:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_FG_SET_FREQ1).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_FG_GET_FREQ1:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_GET_FREQ1).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pfreq=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		memcpy(pfreq,&(pthe_shm->freq),sizeof(double));
		
		break;

	case CALL_FG_SET_FREQ2:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_FG_SET_FREQ2).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_FG_GET_FREQ2:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_GET_FREQ2).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pfreq=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		memcpy(pfreq,&(pthe_shm->freq),sizeof(double));
		
		break;

	case CALL_FG_SET_OFFSET:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_FG_SET_OFFSET).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_FG_GET_OFFSET:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_GET_OFFSET).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		poffs=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		memcpy(poffs,&(pthe_shm->offs),sizeof(double));
		
		break;

	case CALL_FG_STATUS:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_STATUS).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_FG_SET_TYPE:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_FG_SET_TYPE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_FG_GET_TYPE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_GET_TYPE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		ptype=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		memcpy(ptype,&(pthe_shm->type),sizeof(double));
		
		break;

	case CALL_FG_SET_ONOFF:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_SET_ONOFF).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		break;

	case CALL_FG_GET_ONOFF:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required (CALL_FG_GET_ONOFF).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		ponoff=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
		
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
		
		memcpy(ponoff,&(pthe_shm->onoff),sizeof(double));
		
		break;

	case CALL_FG_SET_HOLD_ORDER:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required (CALL_FG_SET_HOLD_ORDER).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
  
		ip=mxArrayToString(ARGIN3);

		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);

		break;

	case CALL_FG_GET_HOLD_ORDER:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required (CALL_FG_GET_HOLD_ORDER).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pholdorder=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
  
		ip=mxArrayToString(ARGIN2);

		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);

		memcpy(pholdorder,&(pthe_shm->holdorder),sizeof(double));

		break;

	case CALL_TDE_GET_ADC_ENC_STATE:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required (CALL_TDE_GET_ADC_ENC_STATE).", pthe_shm);
		}

		ARGOUT0=(mxArray*) mxCreateDoubleMatrix((int) 2*MAXCHAN,1,mxREAL); 
		pallstat=mxGetPr(ARGOUT0);

		ARGOUT1=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);
		
		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
					
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
				
		memcpy(pallstat,&(pthe_shm->allstat),2*MAXCHAN*sizeof(double));
		
		break;
        
    case CALL_EE_GET_NADC:
    case CALL_EE_GET_NDAC:
    case CALL_EE_GET_NENC:
    case CALL_EE_GET_NPWM:
    case CALL_EE_GET_NDIN:
    case CALL_EE_GET_NDOUT:
        if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required (CALL_EE_GET_NXXX).", pthe_shm);
		}
        		
        ARGOUT0=(mxArray*) mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
        		
		tde_gate_cmd_begin(icall,pthe_shm);
  
		ip=mxArrayToString(ARGIN1);
					
		tde_gate_cmd_wait(ip, icall, pthe_shm, NULL, 0);
        
        break;

	default:
		mexErrMsgTxtFree("Don't know what to do with these arguments.",pthe_shm);
		return;
	}

	memcpy(pretval,&(pthe_shm->retval),sizeof(double));

	mxFree(pthe_shm);

	return;
}
