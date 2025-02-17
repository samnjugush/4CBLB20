/*
	RT-Scope Simulink scope (Matlab 6 version)

	(c) Rene' van de Molengraft, 2005

	last update: March, 4th, 2005

	Inputs : u[0], u[3]             = adc channels 0 to 3
             u[4], u[7]             = enc channels 0 to 3
	Outputs: y[0], y[3]             = dac channels 0 and 1
*/

#define S_FUNCTION_NAME sf_rtscope
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
//#include <sys/resource.h>

#define NSTATES		0
#define NINPUTS		8
#define NOUTPUTS	4
#define NPARAMS		1

#define MAXFREQ		ssGetSFcnParam(S,0)
#define U(element)  (*uPtrs[element])  /* Pointer to Input Port0 */

#include <math.h>

#ifndef MATLAB_MEX_FILE
#include "libengine.c"
#include "fungen/libfungen.c"
#include "div/libdiv.c"
#include "fir/libfir.c"
#include "remez/libremez.c"
#include "../RTScope_shared/incomm/libincomm_server.c"
#include "c-ringbuf-master/ringbuf.c"
#else
#include "engine.h"
#endif

/*====================*
 * S-function methods *
 *====================*/

 



static void mdlInitializeSizes(SimStruct *S)
{
    int_T rWorkSize;
	real_T maxfreq;
	
	ssSetNumSFcnParams(S, NPARAMS);

	ssSetNumContStates(S, NSTATES);
	ssSetNumDiscStates(S, 0);

	if (!ssSetNumInputPorts(S, 1)) return;
	ssSetInputPortWidth(S, 0, NINPUTS);
/*	ssSetInputPortDirectFeedThrough(S, 0, NINPUTS);*/
	ssSetInputPortDirectFeedThrough(S, 0, 0);

	if (!ssSetNumOutputPorts(S, 1)) return;
	ssSetOutputPortWidth(S, 0, NOUTPUTS);

	ssSetNumSampleTimes(S, 1);
 
/*  compute necessary amount of real_T workspace */
    rWorkSize=( sizeof(rtscope_global_data)/sizeof(real_T) + 1 );
    //printf("rtscope reports: rWorkSize = %d\n", rWorkSize);
    ssSetNumRWork(S, rWorkSize);

	ssSetNumIWork(S, 0);
	ssSetNumPWork(S, 0);
	ssSetNumModes(S, 0);
	ssSetNumNonsampledZCs(S, 0);

    return;
}





static void mdlInitializeSampleTimes(SimStruct *S)
{
    real_T* pRWork=ssGetRWork(S);
	real_T maxfreq;
    prtscope_global_data prgd;

	ssSetSampleTime(S, 0, CONTINUOUS_SAMPLE_TIME);
	ssSetOffsetTime(S, 0, 0.0);
	
#ifndef MATLAB_MEX_FILE

#if 0
    const rlim_t kStackSize = 30 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
#endif

/*  get pointer to S-function global data */
    prgd=(prtscope_global_data) pRWork;
	tde_start_acq_simulink(prgd);
 
 /*	send maxfreq to rtscope */
	maxfreq=1.0/ssGetStepSize(S);
	if (maxfreq<=0.0) {
	    maxfreq=300.0;
	}
	tde_put_maxfreq_simulink(maxfreq, prgd);
#endif

    return;
}





static void mdlOutputs(SimStruct *S, int_T tid)
{
    real_T* pRWork=ssGetRWork(S);
	real_T *y=ssGetOutputPortRealSignal(S,0);
	InputRealPtrsType uPtrs=ssGetInputPortRealSignalPtrs(S,0);
#ifndef MATLAB_MEX_FILE

	int_T i;
	real_T u[8];
    prtscope_global_data prgd;

	for (i=0;i<8;i++) {
	    u[i]=U(i);
	}
 
/*  get pointer to S-function global data */
    prgd=(prtscope_global_data) pRWork;
	
	tde_timer_fun_simulink(&u[0], &y[0], prgd);
#endif
}





static void mdlTerminate(SimStruct *S)
{
    real_T* pRWork=ssGetRWork(S);

#ifndef MATLAB_MEX_FILE
    prtscope_global_data prgd;

/*  get pointer to S-function global data */
    prgd=(prtscope_global_data) pRWork;
    
    tde_stop_acq(prgd);
#endif
}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
