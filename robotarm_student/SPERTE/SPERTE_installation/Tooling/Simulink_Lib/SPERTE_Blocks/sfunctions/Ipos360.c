/*
 *  ec_Ebox (adapted from ec_EL3102_adc.c (c) Rene' van de Molengraft, 2007)
 *
 *  (c)  2010, Michael Ronde, Eindhoven University of Technology
 *  (c)  2021, Enzo Evers, see www.enzoevers.nl for contact
 *  (c)  2024, Bob Bindels & Gerard van Hattum, Eindhoven University of Technology
 *
 * Copyright (C) 2021 Enzo Evers
 * see www.enzoevers.nl for contact details
 *
 * Control Systems Technology group
 * Departement of Mechanical Engineering
 *
 * Eindhoven University of Technology
 * 
 * SPERTE is licensed under the GNU GPLv3
 *
 *      Inputs:  u0[0] - u0[1]  =   dac channels 0, 1
 *               u1[0] - u1[1]  =   pwm channels 0, 1
 *               u2[0] - u2[7]  =   do chanels 0-7
 *      Outputs: y1[0] - y1[1]  =   adc channels 0, 1
 *               y2[0] - y2[1]  =   encoder channels 0,1
 *               y3[0] - y3[7]  =   di chanels 0-7
 *
 *      Parameter: link id
 */

#define S_FUNCTION_NAME Ipos360
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

#define NSTATES         0
#define NINPUTS         6
#define NOUTPUTS        5
#define NADC            1
#define NDAC            1
#define NDI             1
#define NDO             1
#define NENC            1
#define NPWM            0
#define NPARAMS         1

#define LINK_ID         ssGetSFcnParam(S,0)

#define U0(element) (*u0Ptrs[element])  /* Pointer to Input Port0 torque Z */
#define U1(element) (*u1Ptrs[element])  /* Pointer to Input Port1 torque X */
#define U2(element) (*u2Ptrs[element])  /* Pointer to Input Port2 torque R */
#define U3(element) (*u3Ptrs[element])  /* Pointer to Input Port3 torqu C */
#define U4(element) (*u4Ptrs[element])  /* Pointer to Input Port4 digital outputs */
#define U5(element) (*u5Ptrs[element])  /* Pointer to Input Port5 vacuum pressure*/

#include <math.h>

// Extern from ec.c
extern int_T SetupCompleted;
extern int_T FirstRun;
extern int ec_IPOS_torque_write(int,int);
extern int ec_IPOS_do_write(double);
extern int ec_IPOS_dac_write(double);
extern int ec_IPOS_dac_read(double *);
extern int ec_IPOS_enc_read_chan(double *, int);
extern int ec_IPOS_di_read(double*,int);
extern int ec_IPOS_EnableDriveCiA402(int,int);
/*====================*
 * S-function methods *
 *====================*/

static void mdlInitializeSizes(SimStruct *S) /*Written by Brom */
{
    ssSetNumSFcnParams(S,NPARAMS);  /* Number of expected parameters */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }
    
    ssSetNumContStates(S,NSTATES);
    ssSetNumDiscStates(S,0);
    
    if (!ssSetNumInputPorts(S,NINPUTS)) return;
    ssSetInputPortWidth(S,0,NDAC);
    ssSetInputPortWidth(S,1,NDAC);
    ssSetInputPortWidth(S,2,NDAC);
    ssSetInputPortWidth(S,3,NDAC);
    ssSetInputPortWidth(S,4,NDO);
    ssSetInputPortWidth(S,5,NDAC);
    
    if (!ssSetNumOutputPorts(S,NOUTPUTS)) return;
    ssSetOutputPortWidth(S,0,NADC);
    ssSetOutputPortWidth(S,1,NENC);
    ssSetOutputPortWidth(S,2,NENC);
    ssSetOutputPortWidth(S,3,NENC);
    ssSetOutputPortWidth(S,4,NENC);
       
    ssSetNumSampleTimes(S,1);
    ssSetNumRWork(S,0);
    ssSetNumIWork(S,0);
    ssSetNumPWork(S,0);
    ssSetNumModes(S,0);
    ssSetNumNonsampledZCs(S,0);
}





static void mdlInitializeSampleTimes(SimStruct *S) /*Written by Brom*/
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
    ssSetOffsetTime(S, 0, 0.0);
}

static void mdlOutputs(SimStruct *S, int_T tid) 
{
    /* Initialize outputs */
    real_T *yadc    =   ssGetOutputPortRealSignal(S,0);
    real_T *yencM1  =   ssGetOutputPortRealSignal(S,1);
    real_T *yencM2  =   ssGetOutputPortRealSignal(S,2);
    real_T *yencM3  =   ssGetOutputPortRealSignal(S,3);
    real_T *yencM4  =   ssGetOutputPortRealSignal(S,4);
   
    
    /* Initialzie inputs */
    InputRealPtrsType u0Ptrs = ssGetInputPortRealSignalPtrs(S,0);
    InputRealPtrsType u1Ptrs = ssGetInputPortRealSignalPtrs(S,1);
    InputRealPtrsType u2Ptrs = ssGetInputPortRealSignalPtrs(S,2);
    InputRealPtrsType u3Ptrs = ssGetInputPortRealSignalPtrs(S,3);
    InputRealPtrsType u4Ptrs = ssGetInputPortRealSignalPtrs(S,4);
    InputRealPtrsType u5Ptrs = ssGetInputPortRealSignalPtrs(S,5);
    
#ifndef MATLAB_MEX_FILE
    int_T ichan, ilink, iret;
    
    if (SetupCompleted)
    {   //Enabling drives and write torques:
        ec_IPOS_EnableDriveCiA402(1,0); /*Enable 1st drive*/
        ec_IPOS_torque_write(U0(0),0); /*U0(0) = first port first element 1st drive: equals a torque value*/
        ec_IPOS_EnableDriveCiA402(1,1);/*Enable 2nd drive*/
        ec_IPOS_torque_write(U1(0),1); /*U1(0) = 2nd port first element 2nd drive: equals a torque value*/
        ec_IPOS_EnableDriveCiA402(1,2); /*Enable 3rd drive*/
        ec_IPOS_torque_write(U2(0),2); /*U2(0) = 3rd port first element 3rd drive: equals a torque value*/
        ec_IPOS_EnableDriveCiA402(1,3);/*Enable 4th drive*/
        ec_IPOS_torque_write(U3(0),3); /*U3(0) = 4th port first element 4th drive: equals a torque value*/
                
        ec_IPOS_do_write(U4(0)); /*U4(0) = 5th port first element: equals 0 or 1 for sucking/blowing*/
        ec_IPOS_dac_write(U5(0)); /*U5(0) = 6th port first element: equals a value for the pressure*/
        
        ec_IPOS_dac_read(&yadc[0]); /*reads the vacuum sensor value and writes it to the first element of yadc*/
        
        //read encoder data of 4 drives.
        ec_IPOS_enc_read_chan(&yencM1[0],0);/*reads the encoder sensor value and writes it to the first element of yencM1*/
        ec_IPOS_enc_read_chan(&yencM2[0],1);/*reads the encoder sensor value and writes it to the first element of yencM2*/
        ec_IPOS_enc_read_chan(&yencM3[0],2);/*reads the encoder sensor value and writes it to the first element of yencM3*/
        ec_IPOS_enc_read_chan(&yencM4[0],3);/*reads the encoder sensor value and writes it to the first element of yencM4*/
        
    }
    
#endif
}



static void mdlTerminate(SimStruct *S)
{
}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
