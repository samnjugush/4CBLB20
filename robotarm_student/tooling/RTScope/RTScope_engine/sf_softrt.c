/*
 *
 *		sf_softrt.c
 *
 *		Simulink S-function for soft realtime emulation
 *
 *		Rene van de Molengraft, August, 25th, 2006
 *
 */

#include "sf_softrt.h"

static int reset_real_time(psfun_global_data psfgd)
{
  gettimeofday(&psfgd->tv0, NULL);

  return 0;
}





static double get_real_time(psfun_global_data psfgd)
{
  double t;
  
  gettimeofday(&psfgd->tva, NULL);
  
  t=(double) (psfgd->tva.tv_sec-psfgd->tv0.tv_sec)+((double) (psfgd->tva.tv_usec-psfgd->tv0.tv_usec))/1000000.0+psfgd->t0;
  
  return t;
}





static void mdlInitializeSizes(SimStruct *S)
{
	int_T Rworksize;

        ssSetNumSFcnParams(S,NPARAMS);
        if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
            return; /* Parameter mismatch will be reported by Simulink */
        }
    
        if (!ssSetNumInputPorts(S, NINPORTS)) return;
    
        if (!ssSetNumOutputPorts(S, NOUTPORTS)) return;
        ssSetOutputPortWidth(S, 0, NOUTPUTS);

        ssSetNumSampleTimes(S, 1);
    
/*      compute necessary amount of real_T workspace */
	Rworksize=( sizeof(sfun_global_data)/sizeof(real_T) + 1 );
	//print("sf_softrt reports: Rworksize = %d\n",Rworksize);
	ssSetNumRWork(S,Rworksize);
        
        if (ssIsVariableStepSolver(S)) {
            ssSetErrorStatus(S, "sf_softrt can only be used with a fixed-step solver.");
        }
}





static void mdlInitializeSampleTimes(SimStruct *S)
{
        ssSetSampleTime(S, 0, 0.0);
        ssSetOffsetTime(S, 0, 0.0);
}





#define MDL_INITIALIZE_CONDITIONS
#if defined(MDL_INITIALIZE_CONDITIONS)
static void mdlInitializeConditions(SimStruct *S)
{
    	real_T* sfpar_priority=(real_T*) mxGetPr(SFPAR_PRIORITY(S));
	real_T* ptrRwrk=ssGetRWork(S);
	psfun_global_data psfgd;

/*	get pointer to S-function global data */
	psfgd=(psfun_global_data) ptrRwrk;

        psfgd->first_time=1;
        psfgd->priority=0;

        psfgd->priority=(int_T) *sfpar_priority;
	switch (psfgd->priority) {
        case PRIO_NORMAL:
            break;
        case PRIO_REALTIME:
#ifndef MATLAB_MEX_FILE
/*          use ipcomm api to set priority... */
/*	    psfgd->sd=ipcomm_client_realtime_priority();*/
            print("sf_softrt reports: priority set to realtime.\n");
#endif
	    break;
        }
}
#endif





static void mdlOutputs(SimStruct *S, int_T tid)
{
        real_T *y=(real_T*) ssGetOutputPortRealSignal(S, 0);
        real_T simulation_time, simulation_dt, real_time, real_dt, target_time;
	real_T* ptrRwrk=ssGetRWork(S);
	psfun_global_data psfgd;
        int_T wait_in_us;

/*	get pointer to S-function global data */
	psfgd=(psfun_global_data) ptrRwrk;

        simulation_time=ssGetT(S);
    
        if (psfgd->first_time) {
            reset_real_time(psfgd);
            psfgd->t0=simulation_time;
            psfgd->first_time=0;
        }

        real_time=get_real_time(psfgd);
        simulation_dt=ssGetSampleTime(S, tid);
        target_time=simulation_time+simulation_dt;
        real_dt=target_time-real_time;
/*
        print("%f  %f  %f  %f\n", simulation_time, real_time, target_time, real_dt);
*/
        if (real_dt>0.0) {
            wait_in_us=(int_T) (real_dt*1000000.0);
            usleep(wait_in_us);
        } else {
/*
            ssSetErrorStatus(S, "cannot keep up with real time, increase step size and try again.");
            return;
*/
/*
            print("t = %f: cannot keep up with real time.\n", real_time);
*/
        }

        y[0]=real_dt;
}





static void mdlTerminate(SimStruct *S)
{
	real_T* ptrRwrk=ssGetRWork(S);
	psfun_global_data psfgd;

/*	get pointer to S-function global data */
	psfgd=(psfun_global_data) ptrRwrk;

	switch (psfgd->priority) {
        case PRIO_NORMAL:
            break;
        case PRIO_REALTIME:
#ifndef MATLAB_MEX_FILE
/*	    use ipcomm api to reset priority... */
/*	    ipcomm_client_reset_priority(psfgd->sd);*/
            print("sf_softrt reports: priority reset to normal.\n");
#endif            
	    break;
        }
}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
