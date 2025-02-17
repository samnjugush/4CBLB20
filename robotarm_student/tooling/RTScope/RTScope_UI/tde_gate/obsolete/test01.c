
/* Matlab MEX gate for use with tuedacs extension library */

/*
    René van de Molengraft, November, 2001
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
		    */

#define ERRRETVAL	-1000000

#include <math.h>
#include <mex.h>
#include "../shmtool_fusion/shm.h"
#include "../incomm/incomm.h"
#include <matrix.h>





/* input arguments */
#define	ARGIN0	prhs[0]
#define	ARGIN1	prhs[1]
#define	ARGIN2	prhs[2]
#define	ARGIN3	prhs[3]
#define	ARGIN4	prhs[4]
#define	ARGIN5	prhs[5]
#define	ARGIN6	prhs[6]

/* output argument */
#define	ARGOUT0	plhs[0]
#define ARGOUT1 plhs[1]
#define ARGOUT2 plhs[2]





int mexErrMsgTxtFree(char* pstring, ptde_shm pthe_shm)
{
    mexPrintf("pthe_shm = %x\n",pthe_shm);
    sleep(1);
    
    mexErrMsgTxt(pstring);

    return 0;
}





int tde_gate_cmd_begin(int icall, ptde_shm pthe_shm)
{
	mexPrintf("tde_gate_cmd_begin entered.\n");

	pthe_shm->cmd_id=icall;
	pthe_shm->cmd_status=1;

	mexPrintf("tde_gate_cmd_begin finished.\n");

	return 0;
}





int tde_gate_cmd_wait(int icall, ptde_shm pthe_shm)
{
	int err,icnt,maxcount;

	mexPrintf("tde_gate_cmd_wait entered.\n");

/*
	if (incomm_client_open(2039)==-1) {
		mexErrMsgTxtFree("incomm_client_open failed.\n",pthe_shm);
	}
	
	if (incomm_client_write((void*) pthe_shm, sizeof(tde_shm))==-1) {
		mexErrMsgTxtFree("incomm_client_write failed.\n",pthe_shm);
	}
	
	if (incomm_client_read((void*) pthe_shm, sizeof(tde_shm))==-1) {
		mexErrMsgTxtFree("incomm_client-read failed.\n",pthe_shm);
	}
	
	if (incomm_client_close()==-1) {
		mexErrMsgTxtFree("incomm_client_close failed.\n",pthe_shm);	
	}
*/

	mexPrintf("tde_gate_cmd_wait finished.\n");
		
	return 0;
}





void mexFunction(int nlhs, mxArray *plhs[], 
		 int nrhs, const mxArray *prhs[])
{ 
	int_T icall,nrows,ncols;
	real_T *pcall,*pargin1,*pargin2,*pargin3,*pargin4,*pargin5,*pargin6;
	real_T *pretval,*pdata,*pmaxchan,*pmaxframe, *pclip, *pstat, *poffset, *pmaxfreq, *pallstat;
	real_T *pamp,*pfreq,*poffs,*ptype,*ponoff,*pholdorder;
	ptde_shm pthe_shm;
		
	mexPrintf("Hier!!!\n");

/*
	pthe_shm=mxCalloc(1,sizeof(tde_shm));
	mexPrintf("pthe_shm = %x\n",pthe_shm);
	sleep(1);
*/
			
	if (nrhs==0) {
		mexErrMsgTxt("At least one input argument required.\n");
	}



/*
	mxFree(pthe_shm);
*/

	return;


	pcall=mxGetPr(ARGIN0);
	icall=(int_T) pcall[0];
	
	switch (icall)
	{
	case CALL_TDE_START_ACQ:
		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_TDE_STOP_ACQ:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TDE_CHECK_DATA:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		tde_gate_cmd_wait(icall,pthe_shm);

		break;

	case CALL_TDE_SAY_READY:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		tde_gate_cmd_wait(icall,pthe_shm);

		break;

	case CALL_TDE_GET_DATA:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		nrows=(int_T) (MAXCHAN*2);
		pargin1=mxGetPr(ARGIN1);		
		ncols=(int_T) (pargin1[0]/(MAXCHAN*2));
		ARGOUT0=mxCreateDoubleMatrix(nrows,ncols,mxREAL);
		pdata=mxGetPr(ARGOUT0);
		
		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);

		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);

		memcpy(pdata,&(pthe_shm->data),pargin1[0]*sizeof(double));
		
		break;

	case CALL_TDE_GET_INFO:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}
		
		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pmaxchan=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pmaxframe=mxGetPr(ARGOUT1);

		ARGOUT2=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT2);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		tde_gate_cmd_wait(icall,pthe_shm);
				
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

		if (nrhs!=7) {
			mexErrMsgTxtFree("Seven input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
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
		
		tde_gate_cmd_wait(icall,pthe_shm);

		break;

	case CALL_TDE_TRIGGER_OFF:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		tde_gate_cmd_wait(icall,pthe_shm);

		break;

	case CALL_TDE_CHECK_CLIPPING:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix((int_T) MAXCHAN,1,mxREAL); 
		pclip=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);
		
		tde_gate_cmd_begin(icall,pthe_shm);
					
		tde_gate_cmd_wait(icall,pthe_shm);
				
		memcpy(pclip,&(pthe_shm->clip),MAXCHAN*sizeof(double));
		
		break;

	case CALL_TDE_SET_ADC_STATE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
				
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TDE_GET_ADC_STATE:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		tde_gate_cmd_wait(icall,pthe_shm);
				
		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pstat=mxGetPr(ARGOUT0);
		memcpy(pstat,&(pthe_shm->stat),sizeof(double));
		
		break;

	case CALL_TDE_SET_ENC_STATE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
				
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TDE_GET_ENC_STATE:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		tde_gate_cmd_wait(icall,pthe_shm);
				
		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pstat=mxGetPr(ARGOUT0);
		memcpy(pstat,&(pthe_shm->stat),sizeof(double));
		
		break;

	case CALL_TDE_SET_DAC_STATE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
				
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TDE_GET_DAC_STATE:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pstat=mxGetPr(ARGOUT0);
		memcpy(pstat,&(pthe_shm->stat),sizeof(double));
		
		break;

	case CALL_TDE_SET_ADC_OFFSET:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
				
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TDE_GET_ADC_OFFSET:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		poffset=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		memcpy(poffset,&(pthe_shm->offset),sizeof(double));
		
		break;
	
	case CALL_TDE_PAUSE:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TDE_SET_NSAMP:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TDE_SET_NDOWN:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;


	case CALL_TDE_INIT_ENC:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TD_GET_DEVICE_TYPE:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TD_AAFILTER_ON:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
				
		pargin3=mxGetPr(ARGIN3);
		memcpy(&(pthe_shm->argin3),pargin3,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TD_AAFILTER_OFF:

		mexPrintf("AAFILTER_OFF\n");
		
		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_TD_SET_RANGE:

		if (nrhs!=4) {
			mexErrMsgTxtFree("Four input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
				
		pargin3=mxGetPr(ARGIN3);
		memcpy(&(pthe_shm->argin3),pargin3,sizeof(double));
				
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_TD_GET_RANGE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TD_GET_FILTER_ENABLE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);
		
		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
				
		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TDE_GET_MAXFREQ:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pmaxfreq=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);
		
		tde_gate_cmd_begin(icall,pthe_shm);
					
		tde_gate_cmd_wait(icall,pthe_shm);
				
		memcpy(pmaxfreq,&(pthe_shm->maxfreq),sizeof(double));
		
		break;

	case CALL_TDE_LINK2MEAS:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_TDE_LINK_IS_ACTIVE:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_FG_GET_VAL:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);

		break;
		
	case CALL_FG_START:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_FG_STOP:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_FG_SET_DEFAULTS:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_FG_SET_AMP1:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
			
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		break;

	case CALL_FG_GET_AMP1:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pamp=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
							
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
				
		memcpy(pamp,&(pthe_shm->amp),sizeof(double));
		
		break;

	case CALL_FG_SET_AMP2:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_FG_GET_AMP2:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pamp=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		memcpy(pamp,&(pthe_shm->amp),sizeof(double));
		
		break;

	case CALL_FG_SET_FREQ1:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_FG_GET_FREQ1:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pfreq=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		memcpy(pfreq,&(pthe_shm->freq),sizeof(double));
		
		break;

	case CALL_FG_SET_FREQ2:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_FG_GET_FREQ2:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pfreq=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		memcpy(pfreq,&(pthe_shm->freq),sizeof(double));
		
		break;

	case CALL_FG_SET_OFFSET:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_FG_GET_OFFSET:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		poffs=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		memcpy(poffs,&(pthe_shm->offs),sizeof(double));
		
		break;

	case CALL_FG_STATUS:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_FG_SET_TYPE:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_FG_GET_TYPE:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		ptype=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		memcpy(ptype,&(pthe_shm->type),sizeof(double));
		
		break;

	case CALL_FG_SET_ONOFF:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		break;

	case CALL_FG_GET_ONOFF:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		ponoff=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);
		
		tde_gate_cmd_wait(icall,pthe_shm);
		
		memcpy(ponoff,&(pthe_shm->onoff),sizeof(double));
		
		break;

	case CALL_FG_SET_HOLD_ORDER:

		if (nrhs!=3) {
			mexErrMsgTxtFree("Three input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT0);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		pargin2=mxGetPr(ARGIN2);
		memcpy(&(pthe_shm->argin2),pargin2,sizeof(double));

		tde_gate_cmd_wait(icall,pthe_shm);

		break;

	case CALL_FG_GET_HOLD_ORDER:

		if (nrhs!=2) {
			mexErrMsgTxtFree("Two input arguments required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix(1,1,mxREAL); 
		pholdorder=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);

		tde_gate_cmd_begin(icall,pthe_shm);

		pargin1=mxGetPr(ARGIN1);
		memcpy(&(pthe_shm->argin1),pargin1,sizeof(double));

		tde_gate_cmd_wait(icall,pthe_shm);

		memcpy(pholdorder,&(pthe_shm->holdorder),sizeof(double));

		break;

	case CALL_TDE_GET_ADC_ENC_STATE:

		if (nrhs!=1) {
			mexErrMsgTxtFree("One input argument required.",pthe_shm);
		}

		ARGOUT0=mxCreateDoubleMatrix((int_T) 2*MAXCHAN,1,mxREAL); 
		pallstat=mxGetPr(ARGOUT0);

		ARGOUT1=mxCreateDoubleMatrix(1,1,mxREAL); 
		pretval=mxGetPr(ARGOUT1);
		
		tde_gate_cmd_begin(icall,pthe_shm);
					
		tde_gate_cmd_wait(icall,pthe_shm);
				
		memcpy(pallstat,&(pthe_shm->allstat),2*MAXCHAN*sizeof(double));
		
		break;

	default:
		mexErrMsgTxtFree("Don't know what to do with these arguments.",pthe_shm);
		return;
	}

	mexPrintf("Copying output argument...\n");
	
	memcpy(pretval,&(pthe_shm->retval),sizeof(double));

	mxFree(pthe_shm);

	return;
}
