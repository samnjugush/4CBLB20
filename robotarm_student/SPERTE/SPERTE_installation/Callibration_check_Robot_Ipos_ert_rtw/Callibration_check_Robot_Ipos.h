/*
 * Callibration_check_Robot_Ipos.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Callibration_check_Robot_Ipos".
 *
 * Model version              : 2.17
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Sat Mar  9 15:44:48 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Callibration_check_Robot_Ipos_h_
#define RTW_HEADER_Callibration_check_Robot_Ipos_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#ifndef Callibration_check_Robot_Ipos_COMMON_INCLUDES_
#define Callibration_check_Robot_Ipos_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SCI.h"
#endif                      /* Callibration_check_Robot_Ipos_COMMON_INCLUDES_ */

#include "Callibration_check_Robot_Ipos_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block states (default storage) for system '<S29>/Serial Write1' */
typedef struct {
  codertarget_raspi_internal_SC_T obj; /* '<S29>/Serial Write1' */
  boolean_T objisempty;                /* '<S29>/Serial Write1' */
} DW_SerialWrite1_Callibration__T;

/* Block signals for system '<S22>/MATLAB Function2' */
typedef struct {
  real_T A[36];
  real_T B[6];
  real_T path;                         /* '<S22>/MATLAB Function2' */
  real_T smax;
  real_T ndbl;
  real_T cdiff;
  real_T B_m;
  real_T B_c;
  real_T B_k;
  real_T d;
  real_T d1;
  int8_T ipiv[6];
  int32_T j;
  int32_T kAcol;
  int32_T ix;
  int32_T c_k;
} B_MATLABFunction2_Callibratio_T;

/* Block states (default storage) for system '<S22>/MATLAB Function2' */
typedef struct {
  real_T previous_value_reference_start;/* '<S22>/MATLAB Function2' */
  real_T previous_value_reference_end; /* '<S22>/MATLAB Function2' */
  real_T index;                        /* '<S22>/MATLAB Function2' */
  emxArray_real_T_Callibration__T* path_array;/* '<S22>/MATLAB Function2' */
  boolean_T path_array_not_empty;      /* '<S22>/MATLAB Function2' */
} DW_MATLABFunction2_Callibrati_T;

/* Block signals (default storage) */
typedef struct {
  char_T rtb_StringConcatenate_m[256];
  char_T HomingRunningSwitch_c[256];   /* '<S21>/Homing Running Switch' */
  uint8_T MatrixConcatenate[32];       /* '<S30>/Matrix Concatenate' */
  uint8_T MatrixConcatenate1[32];      /* '<S29>/Matrix Concatenate1' */
  char_T cv[31];
  real32_T xout[3];
  boolean_T FixPtRelationalOperator[12];/* '<S12>/FixPt Relational Operator' */
  size_t bytesOutSizet;
  FILE * filestar;
  FILE * filestar_k;
  char_T ManualSwitch1[256];           /* '<S1>/Manual Switch1' */
  real_T SFunction;                    /* '<S3>/S-Function' */
  real_T ec_Ipos_o1;                   /* '<S17>/ec_Ipos' */
  real_T ec_Ipos_o2;                   /* '<S17>/ec_Ipos' */
  real_T ec_Ipos_o3;                   /* '<S17>/ec_Ipos' */
  real_T ec_Ipos_o4;                   /* '<S17>/ec_Ipos' */
  real_T ec_Ipos_o5;                   /* '<S17>/ec_Ipos' */
  real_T Gain;                         /* '<S15>/Gain' */
  real_T set_robot_calibration_r;      /* '<S16>/set_robot_calibration_r' */
  real_T Constant1;                    /* '<S36>/Constant1' */
  real_T DiscreteTimeIntegrator;       /* '<S22>/Discrete-Time Integrator' */
  real_T Sum;                          /* '<S22>/Sum' */
  real_T Sum2;                         /* '<S22>/Sum2' */
  real_T Gain1;                        /* '<S15>/Gain1' */
  real_T DiscreteTimeIntegrator_g;     /* '<S23>/Discrete-Time Integrator' */
  real_T set_robot_calibration_x;      /* '<S16>/set_robot_calibration_x' */
  real_T Constant1_p;                  /* '<S45>/Constant1' */
  real_T Sum_a;                        /* '<S23>/Sum' */
  real_T Sum2_f;                       /* '<S23>/Sum2' */
  real_T Gain2;                        /* '<S15>/Gain2' */
  real_T set_robot_calibration_z;      /* '<S16>/set_robot_calibration_z' */
  real_T Constant1_c;                  /* '<S58>/Constant1' */
  real_T Sum_n;                        /* '<S24>/Sum' */
  real_T Sum2_k;                       /* '<S24>/Sum2' */
  real_T Add1;                         /* '<S20>/Add1' */
  real_T Gain3;                        /* '<S15>/Gain3' */
  real_T Gain_b;                       /* '<S31>/Gain' */
  real_T Dctintegrator;                /* '<S31>/Dctintegrator' */
  real_T Dctleadlag;                   /* '<S31>/Dctleadlag' */
  real_T Dct1lowpass;                  /* '<S31>/Dct1lowpass' */
  real_T Product;                      /* '<S22>/Product' */
  real_T HomingRunningSwitch;          /* '<S22>/Homing Running Switch' */
  real_T Gain_h;                       /* '<S32>/Gain' */
  real_T Dctleadlag_h;                 /* '<S32>/Dctleadlag' */
  real_T Dct1lowpass_f;                /* '<S32>/Dct1lowpass' */
  real_T AirbagSwitch;                 /* '<S22>/AirbagSwitch' */
  real_T Product1;                     /* '<S22>/Product1' */
  real_T Gain1_l;                      /* '<S22>/Gain1' */
  real_T Gain1_m;                      /* '<S41>/Gain1' */
  real_T Dctintegrator_o;              /* '<S41>/Dctintegrator' */
  real_T Dctleadlag_m;                 /* '<S41>/Dctleadlag' */
  real_T Dct1lowpass_o;                /* '<S41>/Dct1lowpass' */
  real_T Gain1_f;                      /* '<S42>/Gain1' */
  real_T Dctleadlag_d;                 /* '<S42>/Dctleadlag' */
  real_T Dct1lowpass_d;                /* '<S42>/Dct1lowpass' */
  real_T Saturation1;                  /* '<S23>/Saturation1' */
  real_T Gain_f;                       /* '<S53>/Gain' */
  real_T Dctintegrator_l;              /* '<S53>/Dctintegrator' */
  real_T Dctleadlag_dv;                /* '<S53>/Dctleadlag' */
  real_T Dct1lowpass_a;                /* '<S53>/Dct1lowpass' */
  real_T Gain_l;                       /* '<S54>/Gain' */
  real_T Dctleadlag_g;                 /* '<S54>/Dctleadlag' */
  real_T Dct1lowpass_aa;               /* '<S54>/Dct1lowpass' */
  real_T Saturation;                   /* '<S24>/Saturation' */
  real_T DiscreteTimeIntegrator_m;     /* '<S25>/Discrete-Time Integrator' */
  real_T Gain1_k;                      /* '<S66>/Gain1' */
  real_T Dctintegrator3;               /* '<S66>/Dctintegrator3' */
  real_T Dct1lowpass_g;                /* '<S66>/Dct1lowpass' */
  real_T Dctleadlag_a;                 /* '<S66>/Dctleadlag' */
  real_T HomingRunningSwitch_i;        /* '<S25>/Homing Running Switch' */
  real_T Gain_lu;                      /* '<S25>/Gain' */
  real_T Constant1_g;                  /* '<S57>/Constant1' */
  real_T DiscreteTimeIntegrator_l;     /* '<S57>/Discrete-Time Integrator' */
  real_T Constant1_a;                  /* '<S44>/Constant1' */
  real_T DiscreteTimeIntegrator_my;    /* '<S44>/Discrete-Time Integrator' */
  real_T Constant1_p4;                 /* '<S35>/Constant1' */
  real_T DiscreteTimeIntegrator_e;     /* '<S35>/Discrete-Time Integrator' */
  real_T jogSpeed;                     /* '<S25>/Supervisor' */
  real_T homeControllerEnabled;        /* '<S25>/Supervisor' */
  real_T resetEnc;                     /* '<S25>/Supervisor' */
  real_T homingBusy;                   /* '<S25>/Supervisor' */
  real_T Ready;                        /* '<S25>/Supervisor' */
  real_T StopSim;                      /* '<S25>/Supervisor' */
  real_T jogSpeed_a;                   /* '<S24>/Supervisor' */
  real_T toPoint;                      /* '<S24>/Supervisor' */
  real_T homeControllerEnabled_m;      /* '<S24>/Supervisor' */
  real_T resetEnc_l;                   /* '<S24>/Supervisor' */
  real_T homingBusy_c;                 /* '<S24>/Supervisor' */
  real_T freddy;                       /* '<S24>/Supervisor' */
  real_T airBagEnabled;                /* '<S24>/Supervisor' */
  real_T airBagRef;                    /* '<S24>/Supervisor' */
  real_T controlEnabled;               /* '<S24>/Supervisor' */
  real_T Ready_a;                      /* '<S24>/Supervisor' */
  real_T StopSim_n;                    /* '<S24>/Supervisor' */
  real_T y;                            /* '<S24>/Angle2Z' */
  real_T jogSpeed_l;                   /* '<S23>/Supervisor2' */
  real_T toPoint_j;                    /* '<S23>/Supervisor2' */
  real_T homeControllerEnabled_c;      /* '<S23>/Supervisor2' */
  real_T resetEnc_ln;                  /* '<S23>/Supervisor2' */
  real_T freddy_a;                     /* '<S23>/Supervisor2' */
  real_T homingBusy_p;                 /* '<S23>/Supervisor2' */
  real_T airBagEnabled_a;              /* '<S23>/Supervisor2' */
  real_T airBagRef_l;                  /* '<S23>/Supervisor2' */
  real_T controlEnabled_i;             /* '<S23>/Supervisor2' */
  real_T Ready_f;                      /* '<S23>/Supervisor2' */
  real_T StopSim_o;                    /* '<S23>/Supervisor2' */
  real_T jogSpeed_j;                   /* '<S22>/Supervisor' */
  real_T toPoint_jr;                   /* '<S22>/Supervisor' */
  real_T homeControllerEnabled_d;      /* '<S22>/Supervisor' */
  real_T resetEnc_b;                   /* '<S22>/Supervisor' */
  real_T freddy_m;                     /* '<S22>/Supervisor' */
  real_T homingBusy_a;                 /* '<S22>/Supervisor' */
  real_T airBagEnabled_f;              /* '<S22>/Supervisor' */
  real_T airBagRef_lc;                 /* '<S22>/Supervisor' */
  real_T controlEnabled_f;             /* '<S22>/Supervisor' */
  real_T Ready_j;                      /* '<S22>/Supervisor' */
  real_T StopSim_e;                    /* '<S22>/Supervisor' */
  real_T y_g;                          /* '<S22>/Angle2Z' */
  real_T Selector2[9];                 /* '<S4>/Selector2' */
  real_T Selector[3];                  /* '<S4>/Selector' */
  real_T Conveyorreferencemm;          /* '<S1>/Discrete  integrator' */
  real_T Gain1_c;                      /* '<S5>/Gain1' */
  real_T Dctintegrator3_c;             /* '<S5>/Dctintegrator3' */
  real_T Dct1lowpass_l;                /* '<S5>/Dct1lowpass' */
  real_T Dctleadlag_f;                 /* '<S5>/Dctleadlag' */
  real_T SFunctionBuilder;             /* '<S4>/S-Function Builder' */
  real_T Sum_g;                        /* '<S4>/Sum' */
  real_T SignalConversion2;            /* '<S1>/Signal Conversion2' */
  real_T SignalConversion1;            /* '<S1>/Signal Conversion1' */
  real_T SignalConversion;             /* '<S1>/Signal Conversion' */
  real_T Sum4;                         /* '<S1>/Sum4' */
  real_T Sum5;                         /* '<S1>/Sum5' */
  real_T Sum6;                         /* '<S1>/Sum6' */
  real_T Gain1_n;                      /* '<S7>/Gain1' */
  real_T Doubleclickswitch;            /* '<S1>/Manual Switch' */
  real_T Object;                       /* '<S1>/Object' */
  real_T Plot;                         /* '<S1>/Plot' */
  real_T Stop;                         /* '<S1>/Stop' */
  real_T In1;                          /* '<S13>/In1' */
  real_T d12;
  real_T DiscreteTimeIntegrator_m_c;   /* '<S24>/Discrete-Time Integrator' */
  real_T fx1_tmp;
  real_T fy1_tmp;
  real_T d12_tmp;
  real_T d13_tmp;
  real_T LimitAcceleration_j;          /* '<S35>/Limit Acceleration' */
  real_T LimitAcceleration_d;          /* '<S44>/Limit Acceleration' */
  real_T LimitAcceleration;            /* '<S57>/Limit Acceleration' */
  real_T HomingRunningSwitch1_d;       /* '<S24>/Homing Running Switch1' */
  real_T HomingRunningSwitch1_m;       /* '<S23>/Homing Running Switch1' */
  real_T HomingRunningSwitch1_l;       /* '<S22>/Homing Running Switch1' */
  real_T Diff_dn;                      /* '<S40>/Diff' */
  real_T Diff_d;                       /* '<S52>/Diff' */
  real_T Diff;                         /* '<S65>/Diff' */
  real_T Add;                          /* '<S16>/Add' */
  real_T Add2;                         /* '<S16>/Add2' */
  real_T TSamp_e;                      /* '<S40>/TSamp' */
  real_T TSamp_p;                      /* '<S39>/TSamp' */
  real_T TSamp_j;                      /* '<S52>/TSamp' */
  real_T TSamp_o;                      /* '<S51>/TSamp' */
  real_T TSamp_k;                      /* '<S65>/TSamp' */
  real_T TSamp;                        /* '<S64>/TSamp' */
  real_T Saturation_b;                 /* '<S1>/Saturation ' */
  int32_T i;
  int32_T Selector2_tmp;
  int32_T loop_ub;
  int32_T i_p;
  int32_T i1;
  int32_T newNumel;
  int32_T i_c;
  int32_T i_f;
  uint32_T qY;
  int8_T b_fileid;
  int8_T j;
  boolean_T RelationalOperator;        /* '<S22>/Relational Operator' */
  boolean_T RelationalOperator_m;      /* '<S23>/Relational Operator' */
  boolean_T RelationalOperator_e;      /* '<S24>/Relational Operator' */
  boolean_T Compare;                   /* '<S19>/Compare' */
  boolean_T Compare_c;                 /* '<S18>/Compare' */
  boolean_T a;
  B_MATLABFunction2_Callibratio_T sf_MATLABFunction1;/* '<S24>/MATLAB Function1' */
  B_MATLABFunction2_Callibratio_T sf_MATLABFunction;/* '<S23>/MATLAB Function' */
  B_MATLABFunction2_Callibratio_T sf_MATLABFunction2;/* '<S22>/MATLAB Function2' */
} B_Callibration_check_Robot_Ipos_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S36>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S22>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S23>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S45>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_ef;/* '<S24>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_ei;/* '<S58>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S16>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S16>/Unit Delay1' */
  real_T DiscreteTimeIntegrator_DSTAT_dx;/* '<S25>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S64>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S57>/Discrete-Time Integrator' */
  real_T UD_DSTATE_n;                  /* '<S65>/UD' */
  real_T UD_DSTATE_d;                  /* '<S51>/UD' */
  real_T DiscreteTimeIntegrator_DSTAT_eh;/* '<S44>/Discrete-Time Integrator' */
  real_T UD_DSTATE_i;                  /* '<S52>/UD' */
  real_T UD_DSTATE_a;                  /* '<S39>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S35>/Discrete-Time Integrator' */
  real_T UD_DSTATE_c;                  /* '<S40>/UD' */
  real_T DelayInput1_DSTATE[12];       /* '<S12>/Delay Input1' */
  real_T Discreteintegrator_DSTATE;    /* '<S1>/Discrete  integrator' */
  char_T Delay_DSTATE[256];            /* '<S27>/Delay' */
  real_T PrevY;                        /* '<S57>/Limit Speed' */
  real_T PrevY_j;                      /* '<S57>/Limit Acceleration' */
  real_T PrevY_p;                      /* '<S44>/Limit Speed' */
  real_T PrevY_m;                      /* '<S44>/Limit Acceleration' */
  real_T PrevY_i;                      /* '<S35>/Limit Speed' */
  real_T PrevY_g;                      /* '<S35>/Limit Acceleration' */
  real_T currentcarPos;                /* '<S24>/Supervisor' */
  real_T currentcarPos_f;              /* '<S23>/Supervisor2' */
  real_T currentcarPos_k;              /* '<S22>/Supervisor' */
  real_T fileID;                       /* '<S10>/SPERTE_measurement_function' */
  real_T Dctintegrator_RWORK[2];       /* '<S31>/Dctintegrator' */
  real_T Dctleadlag_RWORK[2];          /* '<S31>/Dctleadlag' */
  real_T Dct1lowpass_RWORK[2];         /* '<S31>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_m[2];        /* '<S32>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_c[2];       /* '<S32>/Dct1lowpass' */
  real_T Dctintegrator_RWORK_m[2];     /* '<S41>/Dctintegrator' */
  real_T Dctleadlag_RWORK_e[2];        /* '<S41>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_m[2];       /* '<S41>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_c[2];        /* '<S42>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_d[2];       /* '<S42>/Dct1lowpass' */
  real_T Dctintegrator_RWORK_p[2];     /* '<S53>/Dctintegrator' */
  real_T Dctleadlag_RWORK_et[2];       /* '<S53>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_e[2];       /* '<S53>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_g[2];        /* '<S54>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_b[2];       /* '<S54>/Dct1lowpass' */
  real_T Dctintegrator3_RWORK[2];      /* '<S66>/Dctintegrator3' */
  real_T Dct1lowpass_RWORK_en[2];      /* '<S66>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_l[2];        /* '<S66>/Dctleadlag' */
  real_T Dctintegrator3_RWORK_c[2];    /* '<S5>/Dctintegrator3' */
  real_T Dct1lowpass_RWORK_mc[2];      /* '<S5>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_p[2];        /* '<S5>/Dctleadlag' */
  struct {
    void *LoggedData;
  } Scope16_PWORK;                     /* '<S22>/Scope16' */

  struct {
    void *LoggedData;
  } Scope18_PWORK;                     /* '<S22>/Scope18' */

  struct {
    void *LoggedData;
  } Scope20_PWORK;                     /* '<S22>/Scope20' */

  struct {
    void *LoggedData;
  } Scope21_PWORK;                     /* '<S22>/Scope21' */

  struct {
    void *LoggedData;
  } Scope22_PWORK;                     /* '<S22>/Scope22' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S25>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S24>/Scope1' */

  struct {
    void *LoggedData;
  } Scope17_PWORK;                     /* '<S23>/Scope17' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<S23>/Scope6' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_h;                    /* '<S22>/Scope1' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<S22>/Scope10' */

  struct {
    void *LoggedData;
  } Scope11_PWORK;                     /* '<S22>/Scope11' */

  struct {
    void *LoggedData;
  } Scope19_PWORK;                     /* '<S22>/Scope19' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S22>/Scope4' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<S22>/Scope8' */

  struct {
    void *LoggedData;
  } Scope14_PWORK;                     /* '<S22>/Scope14' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S22>/Scope2' */

  struct {
    void *LoggedData;
  } Scope18_PWORK_p;                   /* '<S23>/Scope18' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_h;                    /* '<S22>/Scope6' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_l;                    /* '<S24>/Scope2' */

  struct {
    void *LoggedData;
  } Scope21_PWORK_k;                   /* '<S23>/Scope21' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_n;                    /* '<S23>/Scope2' */

  struct {
    void *LoggedData;
  } Scope22_PWORK_c;                   /* '<S23>/Scope22' */

  struct {
    void *LoggedData;
  } Scope_PWORK_n;                     /* '<S23>/Scope' */

  struct {
    void *LoggedData;
  } Scope19_PWORK_k;                   /* '<S23>/Scope19' */

  struct {
    void *LoggedData;
  } Scope20_PWORK_a;                   /* '<S23>/Scope20' */

  struct {
    void *LoggedData;
  } Scope16_PWORK_b;                   /* '<S23>/Scope16' */

  struct {
    void *LoggedData;
  } Scope23_PWORK;                     /* '<S23>/Scope23' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S22>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S22>/Scope3' */

  struct {
    void *LoggedData;
  } Scope12_PWORK;                     /* '<S22>/Scope12' */

  struct {
    void *LoggedData[2];
  } Scope23_PWORK_m;                   /* '<S22>/Scope23' */

  struct {
    void *LoggedData;
  } Scope13_PWORK;                     /* '<S22>/Scope13' */

  struct {
    void *LoggedData;
  } Scope15_PWORK;                     /* '<S22>/Scope15' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<S22>/Scope7' */

  struct {
    void *LoggedData;
  } Scope17_PWORK_n;                   /* '<S22>/Scope17' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S37>/Scope' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S22>/Scope5' */

  int32_T sfEvent;                     /* '<S25>/Supervisor' */
  int32_T sfEvent_e;                   /* '<S24>/Supervisor' */
  int32_T sfEvent_l;                   /* '<S23>/Supervisor2' */
  int32_T sfEvent_m;                   /* '<S22>/Supervisor' */
  int32_T sfEvent_o;                   /* '<S1>/Stateflow ' */
  uint32_T is_c1_Callibration_check_Robot_;/* '<S25>/Supervisor' */
  uint32_T is_c18_Callibration_check_Robot;/* '<S24>/Supervisor' */
  uint32_T is_c16_Callibration_check_Robot;/* '<S23>/Supervisor2' */
  uint32_T is_c12_Callibration_check_Robot;/* '<S22>/Supervisor' */
  uint32_T is_Object_Detection;        /* '<S1>/Stateflow ' */
  uint32_T is_Belt;                    /* '<S1>/Stateflow ' */
  uint32_T is_Robot_Arm;               /* '<S1>/Stateflow ' */
  uint32_T is_Vacuum;                  /* '<S1>/Stateflow ' */
  uint32_T NS;                         /* '<S10>/SPERTE_measurement_function' */
  int16_T NF;                          /* '<S10>/SPERTE_measurement_function' */
  uint16_T temporalCounter_i1;         /* '<S25>/Supervisor' */
  uint16_T temporalCounter_i1_b;       /* '<S24>/Supervisor' */
  uint16_T temporalCounter_i1_h;       /* '<S23>/Supervisor2' */
  uint16_T temporalCounter_i1_p;       /* '<S22>/Supervisor' */
  int8_T Subsystem3_SubsysRanBC;       /* '<S26>/Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S28>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S28>/If Action Subsystem' */
  int8_T Controller_SubsysRanBC;       /* '<Root>/Controller' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S4>/Enabled Subsystem' */
  uint8_T is_active_c1_Callibration_check;/* '<S25>/Supervisor' */
  uint8_T is_active_c18_Callibration_chec;/* '<S24>/Supervisor' */
  uint8_T is_active_c16_Callibration_chec;/* '<S23>/Supervisor2' */
  uint8_T is_active_c12_Callibration_chec;/* '<S22>/Supervisor' */
  uint8_T is_active_c3_Callibration_check;/* '<S1>/Stateflow ' */
  uint8_T is_active_Object_Detection;  /* '<S1>/Stateflow ' */
  uint8_T is_active_Belt;              /* '<S1>/Stateflow ' */
  uint8_T is_active_Robot_Arm;         /* '<S1>/Stateflow ' */
  uint8_T is_active_Vacuum;            /* '<S1>/Stateflow ' */
  uint8_T busy;                        /* '<S10>/SPERTE_measurement_function' */
  boolean_T doneDoubleBufferReInit;    /* '<S1>/Stateflow ' */
  boolean_T eml_autoflush[20];         /* '<S10>/SPERTE_measurement_function' */
  FILE * eml_openfiles[20];            /* '<S10>/SPERTE_measurement_function' */
  boolean_T Controller_MODE;           /* '<Root>/Controller' */
  DW_MATLABFunction2_Callibrati_T sf_MATLABFunction1;/* '<S24>/MATLAB Function1' */
  DW_MATLABFunction2_Callibrati_T sf_MATLABFunction;/* '<S23>/MATLAB Function' */
  DW_MATLABFunction2_Callibrati_T sf_MATLABFunction2;/* '<S22>/MATLAB Function2' */
  DW_SerialWrite1_Callibration__T SerialWrite;/* '<S29>/Serial Write1' */
  DW_SerialWrite1_Callibration__T SerialWrite1;/* '<S29>/Serial Write1' */
} DW_Callibration_check_Robot_Ipos_T;

/* Parameters (default storage) */
struct P_Callibration_check_Robot_Ipos_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S64>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_b;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_b
                               * Referenced by: '<S65>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_n;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
                               * Referenced by: '<S51>/UD'
                               */
  real_T DiscreteDerivative_ICPrevSca_bn;
                              /* Mask Parameter: DiscreteDerivative_ICPrevSca_bn
                               * Referenced by: '<S52>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_o;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_o
                               * Referenced by: '<S39>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_c;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_c
                               * Referenced by: '<S40>/UD'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S18>/Constant'
                                       */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S12>/Delay Input1'
                                        */
  uint32_T MeasurementBlock_N_samples;
                                   /* Mask Parameter: MeasurementBlock_N_samples
                                    * Referenced by: '<S10>/SPERTE_measurement_samples'
                                    */
  uint8_T CompareToConstant1_const;  /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S19>/Constant'
                                      */
  uint8_T MeasurementBlock_trigger_comman;
                              /* Mask Parameter: MeasurementBlock_trigger_comman
                               * Referenced by: '<S10>/SPERTE_measurement_trigger_command'
                               */
  uint8_T MeasurementBlock_triggertype;
                                 /* Mask Parameter: MeasurementBlock_triggertype
                                  * Referenced by: '<S10>/SPERTE_measurement_function'
                                  */
  real_T Delays_Y0;                    /* Computed Parameter: Delays_Y0
                                        * Referenced by: '<S13>/Delay [s]'
                                        */
  real_T Suck_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Suck'
                                        */
  real_T Blow_Value;                   /* Expression: 1
                                        * Referenced by: '<S1>/ Blow'
                                        */
  real_T RobotV_Y0;                    /* Computed Parameter: RobotV_Y0
                                        * Referenced by: '<S1>/Robot [V]'
                                        */
  real_T ConveyorV_Y0;                 /* Computed Parameter: ConveyorV_Y0
                                        * Referenced by: '<S1>/Conveyor [V] '
                                        */
  real_T VacuumV_Y0;                   /* Computed Parameter: VacuumV_Y0
                                        * Referenced by: '<S1>/Vacuum [V] '
                                        */
  real_T Blowsuck_Y0;                  /* Computed Parameter: Blowsuck_Y0
                                        * Referenced by: '<S1>/Blow//suck [-]'
                                        */
  real_T Objectdetectionmatrix_Value[12];
  /* Expression: [0                    0                    0      1709314849.7653;0  0  0  0;0  0  0  0]
   * Referenced by: '<S4>/Object detection matrix'
   */
  real_T Discreteintegrator_gainval;
                               /* Computed Parameter: Discreteintegrator_gainval
                                * Referenced by: '<S1>/Discrete  integrator'
                                */
  real_T Discreteintegrator_IC;        /* Expression: 0
                                        * Referenced by: '<S1>/Discrete  integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.05
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Dctintegrator3_P1_Size[2];/* Computed Parameter: Dctintegrator3_P1_Size
                                    * Referenced by: '<S5>/Dctintegrator3'
                                    */
  real_T Dctintegrator3_P1;            /* Expression: f_num
                                        * Referenced by: '<S5>/Dctintegrator3'
                                        */
  real_T Dctintegrator3_P2_Size[2];/* Computed Parameter: Dctintegrator3_P2_Size
                                    * Referenced by: '<S5>/Dctintegrator3'
                                    */
  real_T Dctintegrator3_P2;            /* Expression: 0.001
                                        * Referenced by: '<S5>/Dctintegrator3'
                                        */
  real_T Dct1lowpass_P1_Size[2];      /* Computed Parameter: Dct1lowpass_P1_Size
                                       * Referenced by: '<S5>/Dct1lowpass'
                                       */
  real_T Dct1lowpass_P1;               /* Expression: f_den
                                        * Referenced by: '<S5>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size[2];      /* Computed Parameter: Dct1lowpass_P2_Size
                                       * Referenced by: '<S5>/Dct1lowpass'
                                       */
  real_T Dct1lowpass_P2;               /* Expression: 0.001
                                        * Referenced by: '<S5>/Dct1lowpass'
                                        */
  real_T Dctleadlag_P1_Size[2];        /* Computed Parameter: Dctleadlag_P1_Size
                                        * Referenced by: '<S5>/Dctleadlag'
                                        */
  real_T Dctleadlag_P1;                /* Expression: f_num
                                        * Referenced by: '<S5>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size[2];        /* Computed Parameter: Dctleadlag_P2_Size
                                        * Referenced by: '<S5>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2;                /* Expression: f_den
                                        * Referenced by: '<S5>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size[2];        /* Computed Parameter: Dctleadlag_P3_Size
                                        * Referenced by: '<S5>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3;                /* Expression: 0.001
                                        * Referenced by: '<S5>/Dctleadlag'
                                        */
  real_T ReferenceRrad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Reference R [rad]'
                                        */
  real_T Gain_Gain;                    /* Expression: 5
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T FeedfowardRV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward R [V]'
                                        */
  real_T ReferenceXrad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Reference X [rad]'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 5
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T FeedfowardXV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward X [V]'
                                        */
  real_T ReferenceZrad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Reference Z [rad]'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 5
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T FeedfowardZV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward Z [V]'
                                        */
  real_T Conveyorspeedmms_Value;       /* Expression: 0
                                        * Referenced by: '<S1>/Conveyor speed [mm//s]'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S1>/Saturation '
                                        */
  real_T Saturation_LowerSat;          /* Expression: -100
                                        * Referenced by: '<S1>/Saturation '
                                        */
  real_T ReferenceVacuumbar_Value;     /* Expression: -1
                                        * Referenced by: '<S1>/Reference Vacuum [bar]'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: -10
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Object_Value;                 /* Expression: 1
                                        * Referenced by: '<S1>/Object'
                                        */
  real_T Plot_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Plot'
                                        */
  real_T Stop_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Stop'
                                        */
  real_T HomingRunningSwitch2_Threshold;/* Expression: 50
                                         * Referenced by: '<S21>/Homing Running Switch2'
                                         */
  real_T HomingRunningSwitch1_Threshold;/* Expression: 2.5
                                         * Referenced by: '<S21>/Homing Running Switch1'
                                         */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T HomingRunningSwitch_Threshold;/* Expression: 0.5
                                        * Referenced by: '<S23>/Homing Running Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T HomingRunningSwitch_Threshold_k;/* Expression: 0.5
                                          * Referenced by: '<S24>/Homing Running Switch'
                                          */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S3>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: portid
                                        * Referenced by: '<S3>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S3>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: ectimeout
                                        * Referenced by: '<S3>/S-Function'
                                        */
  real_T ec_Ipos_P1_Size[2];           /* Computed Parameter: ec_Ipos_P1_Size
                                        * Referenced by: '<S17>/ec_Ipos'
                                        */
  real_T ec_Ipos_P1;                   /* Expression: link_id
                                        * Referenced by: '<S17>/ec_Ipos'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1/16000*9/150*2*pi
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T set_robot_calibration_r_Value;/* Expression: 1.2633
                                        * Referenced by: '<S16>/set_robot_calibration_r'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S36>/Discrete-Time Integrator'
                            */
  real_T HomingRunningSwitch1_Threshol_c;/* Expression: 0.5
                                          * Referenced by: '<S22>/Homing Running Switch1'
                                          */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<S22>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S22>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                           * Referenced by: '<S22>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S22>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value;               /* Expression: -0.05
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 1/16000*9/100*2*pi
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_o;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                           * Referenced by: '<S23>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S23>/Discrete-Time Integrator'
                                        */
  real_T set_robot_calibration_x_Value;/* Expression: -0.60692
                                        * Referenced by: '<S16>/set_robot_calibration_x'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_m;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
                           * Referenced by: '<S45>/Discrete-Time Integrator'
                           */
  real_T HomingRunningSwitch1_Threshol_b;/* Expression: 0.5
                                          * Referenced by: '<S23>/Homing Running Switch1'
                                          */
  real_T Constant2_Value_h;            /* Expression: 2
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T Constant3_Value_g;            /* Expression: 0
                                        * Referenced by: '<S23>/Constant3'
                                        */
  real_T Constant_Value_i;             /* Expression: 0.05
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/16000*9/100*2*pi
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_i;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                           * Referenced by: '<S24>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_g;  /* Expression: 0
                                        * Referenced by: '<S24>/Discrete-Time Integrator'
                                        */
  real_T set_robot_calibration_z_Value;/* Expression: -0.39487
                                        * Referenced by: '<S16>/set_robot_calibration_z'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S58>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_a;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                           * Referenced by: '<S58>/Discrete-Time Integrator'
                           */
  real_T HomingRunningSwitch1_Threshol_o;/* Expression: 0.5
                                          * Referenced by: '<S24>/Homing Running Switch1'
                                          */
  real_T Constant5_Value;              /* Expression: 2
                                        * Referenced by: '<S24>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S24>/Constant6'
                                        */
  real_T Constant_Value_e;             /* Expression: 0.05
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S16>/Unit Delay'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 3
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/16000*2*pi*2.05*10
                                        * Referenced by: '<S15>/Gain3'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S16>/Unit Delay1'
                                        */
  real_T HomingRunningSwitch_Threshold_g;/* Expression: 0.5
                                          * Referenced by: '<S21>/Homing Running Switch'
                                          */
  real_T ResetEncoderR_P1_Size[2];  /* Computed Parameter: ResetEncoderR_P1_Size
                                     * Referenced by: '<S22>/Reset EncoderR'
                                     */
  real_T ResetEncoderR_P1;             /* Expression: ipos_id
                                        * Referenced by: '<S22>/Reset EncoderR'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 25
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T Dctintegrator_P1_Size[2];  /* Computed Parameter: Dctintegrator_P1_Size
                                     * Referenced by: '<S31>/Dctintegrator'
                                     */
  real_T Dctintegrator_P1;             /* Expression: f_num
                                        * Referenced by: '<S31>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size[2];  /* Computed Parameter: Dctintegrator_P2_Size
                                     * Referenced by: '<S31>/Dctintegrator'
                                     */
  real_T Dctintegrator_P2;             /* Expression: 0.001
                                        * Referenced by: '<S31>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_h[2];    /* Computed Parameter: Dctleadlag_P1_Size_h
                                      * Referenced by: '<S31>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_m;              /* Expression: f_num
                                        * Referenced by: '<S31>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_j[2];    /* Computed Parameter: Dctleadlag_P2_Size_j
                                      * Referenced by: '<S31>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_o;              /* Expression: f_den
                                        * Referenced by: '<S31>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_k[2];    /* Computed Parameter: Dctleadlag_P3_Size_k
                                      * Referenced by: '<S31>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_c;              /* Expression: 0.001
                                        * Referenced by: '<S31>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_b[2];  /* Computed Parameter: Dct1lowpass_P1_Size_b
                                     * Referenced by: '<S31>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_e;             /* Expression: f_den
                                        * Referenced by: '<S31>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_c[2];  /* Computed Parameter: Dct1lowpass_P2_Size_c
                                     * Referenced by: '<S31>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_c;             /* Expression: 0.001
                                        * Referenced by: '<S31>/Dct1lowpass'
                                        */
  real_T HomingRunningSwitch_Threshold_o;/* Expression: 0.5
                                          * Referenced by: '<S22>/Homing Running Switch'
                                          */
  real_T Gain_Gain_br;                 /* Expression: 25
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Dctleadlag_P1_Size_c[2];    /* Computed Parameter: Dctleadlag_P1_Size_c
                                      * Referenced by: '<S32>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_b;              /* Expression: f_num
                                        * Referenced by: '<S32>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_i[2];    /* Computed Parameter: Dctleadlag_P2_Size_i
                                      * Referenced by: '<S32>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_m;              /* Expression: f_den
                                        * Referenced by: '<S32>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_n[2];    /* Computed Parameter: Dctleadlag_P3_Size_n
                                      * Referenced by: '<S32>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_l;              /* Expression: 0.001
                                        * Referenced by: '<S32>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_p[2];  /* Computed Parameter: Dct1lowpass_P1_Size_p
                                     * Referenced by: '<S32>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_n;             /* Expression: f_den
                                        * Referenced by: '<S32>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_h[2];  /* Computed Parameter: Dct1lowpass_P2_Size_h
                                     * Referenced by: '<S32>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_a;             /* Expression: 0.001
                                        * Referenced by: '<S32>/Dct1lowpass'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 40
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T ResetEncoderR1_P1_Size[2];/* Computed Parameter: ResetEncoderR1_P1_Size
                                    * Referenced by: '<S23>/Reset EncoderR1'
                                    */
  real_T ResetEncoderR1_P1;            /* Expression: ipos_id
                                        * Referenced by: '<S23>/Reset EncoderR1'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 20
                                        * Referenced by: '<S41>/Gain1'
                                        */
  real_T Dctintegrator_P1_Size_a[2];
                                  /* Computed Parameter: Dctintegrator_P1_Size_a
                                   * Referenced by: '<S41>/Dctintegrator'
                                   */
  real_T Dctintegrator_P1_j;           /* Expression: f_num
                                        * Referenced by: '<S41>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size_p[2];
                                  /* Computed Parameter: Dctintegrator_P2_Size_p
                                   * Referenced by: '<S41>/Dctintegrator'
                                   */
  real_T Dctintegrator_P2_e;           /* Expression: 0.001
                                        * Referenced by: '<S41>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_o[2];    /* Computed Parameter: Dctleadlag_P1_Size_o
                                      * Referenced by: '<S41>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_a;              /* Expression: f_num
                                        * Referenced by: '<S41>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_p[2];    /* Computed Parameter: Dctleadlag_P2_Size_p
                                      * Referenced by: '<S41>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_g;              /* Expression: f_den
                                        * Referenced by: '<S41>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_e[2];    /* Computed Parameter: Dctleadlag_P3_Size_e
                                      * Referenced by: '<S41>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_f;              /* Expression: 0.001
                                        * Referenced by: '<S41>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_g[2];  /* Computed Parameter: Dct1lowpass_P1_Size_g
                                     * Referenced by: '<S41>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_p;             /* Expression: f_den
                                        * Referenced by: '<S41>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_hw[2];/* Computed Parameter: Dct1lowpass_P2_Size_hw
                                    * Referenced by: '<S41>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P2_e;             /* Expression: 0.001
                                        * Referenced by: '<S41>/Dct1lowpass'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 20
                                        * Referenced by: '<S42>/Gain1'
                                        */
  real_T Dctleadlag_P1_Size_j[2];    /* Computed Parameter: Dctleadlag_P1_Size_j
                                      * Referenced by: '<S42>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_d;              /* Expression: f_num
                                        * Referenced by: '<S42>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_g[2];    /* Computed Parameter: Dctleadlag_P2_Size_g
                                      * Referenced by: '<S42>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_n;              /* Expression: f_den
                                        * Referenced by: '<S42>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_j[2];    /* Computed Parameter: Dctleadlag_P3_Size_j
                                      * Referenced by: '<S42>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_k;              /* Expression: 0.001
                                        * Referenced by: '<S42>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_pc[2];/* Computed Parameter: Dct1lowpass_P1_Size_pc
                                    * Referenced by: '<S42>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P1_o;             /* Expression: f_den
                                        * Referenced by: '<S42>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_f[2];  /* Computed Parameter: Dct1lowpass_P2_Size_f
                                     * Referenced by: '<S42>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_l;             /* Expression: 0.001
                                        * Referenced by: '<S42>/Dct1lowpass'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 40
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1000
                                        * Referenced by: '<S23>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1000
                                        * Referenced by: '<S23>/Saturation1'
                                        */
  real_T ResetEncoderR1_P1_Size_p[2];
                                 /* Computed Parameter: ResetEncoderR1_P1_Size_p
                                  * Referenced by: '<S24>/Reset EncoderR1'
                                  */
  real_T ResetEncoderR1_P1_h;          /* Expression: ipos_id
                                        * Referenced by: '<S24>/Reset EncoderR1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 20
                                        * Referenced by: '<S53>/Gain'
                                        */
  real_T Dctintegrator_P1_Size_d[2];
                                  /* Computed Parameter: Dctintegrator_P1_Size_d
                                   * Referenced by: '<S53>/Dctintegrator'
                                   */
  real_T Dctintegrator_P1_d;           /* Expression: f_num
                                        * Referenced by: '<S53>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size_b[2];
                                  /* Computed Parameter: Dctintegrator_P2_Size_b
                                   * Referenced by: '<S53>/Dctintegrator'
                                   */
  real_T Dctintegrator_P2_g;           /* Expression: 0.001
                                        * Referenced by: '<S53>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_b[2];    /* Computed Parameter: Dctleadlag_P1_Size_b
                                      * Referenced by: '<S53>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_c;              /* Expression: f_num
                                        * Referenced by: '<S53>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_pu[2];  /* Computed Parameter: Dctleadlag_P2_Size_pu
                                     * Referenced by: '<S53>/Dctleadlag'
                                     */
  real_T Dctleadlag_P2_c;              /* Expression: f_den
                                        * Referenced by: '<S53>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_ja[2];  /* Computed Parameter: Dctleadlag_P3_Size_ja
                                     * Referenced by: '<S53>/Dctleadlag'
                                     */
  real_T Dctleadlag_P3_o;              /* Expression: 0.001
                                        * Referenced by: '<S53>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_n[2];  /* Computed Parameter: Dct1lowpass_P1_Size_n
                                     * Referenced by: '<S53>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_f;             /* Expression: f_den
                                        * Referenced by: '<S53>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_e[2];  /* Computed Parameter: Dct1lowpass_P2_Size_e
                                     * Referenced by: '<S53>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_ee;            /* Expression: 0.001
                                        * Referenced by: '<S53>/Dct1lowpass'
                                        */
  real_T Gain_Gain_dk;                 /* Expression: 30
                                        * Referenced by: '<S54>/Gain'
                                        */
  real_T Dctleadlag_P1_Size_p[2];    /* Computed Parameter: Dctleadlag_P1_Size_p
                                      * Referenced by: '<S54>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_l;              /* Expression: f_num
                                        * Referenced by: '<S54>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_e[2];    /* Computed Parameter: Dctleadlag_P2_Size_e
                                      * Referenced by: '<S54>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_l;              /* Expression: f_den
                                        * Referenced by: '<S54>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_p[2];    /* Computed Parameter: Dctleadlag_P3_Size_p
                                      * Referenced by: '<S54>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_d;              /* Expression: 0.001
                                        * Referenced by: '<S54>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_a[2];  /* Computed Parameter: Dct1lowpass_P1_Size_a
                                     * Referenced by: '<S54>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_k;             /* Expression: f_den
                                        * Referenced by: '<S54>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_p[2];  /* Computed Parameter: Dct1lowpass_P2_Size_p
                                     * Referenced by: '<S54>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_e5;            /* Expression: 0.001
                                        * Referenced by: '<S54>/Dct1lowpass'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 40
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 1000
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: -1000
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T ResetEncoderR1_P1_Size_j[2];
                                 /* Computed Parameter: ResetEncoderR1_P1_Size_j
                                  * Referenced by: '<S25>/Reset EncoderR1'
                                  */
  real_T ResetEncoderR1_P1_o;          /* Expression: ipos_id
                                        * Referenced by: '<S25>/Reset EncoderR1'
                                        */
  real_T DiscreteTimeIntegrator_gainv_mz;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_mz
                           * Referenced by: '<S25>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_h;  /* Expression: 0
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain_gc;                /* Expression: 10*2.5/500
                                        * Referenced by: '<S66>/Gain1'
                                        */
  real_T Dctintegrator3_P1_Size_c[2];
                                 /* Computed Parameter: Dctintegrator3_P1_Size_c
                                  * Referenced by: '<S66>/Dctintegrator3'
                                  */
  real_T Dctintegrator3_P1_i;          /* Expression: f_num
                                        * Referenced by: '<S66>/Dctintegrator3'
                                        */
  real_T Dctintegrator3_P2_Size_h[2];
                                 /* Computed Parameter: Dctintegrator3_P2_Size_h
                                  * Referenced by: '<S66>/Dctintegrator3'
                                  */
  real_T Dctintegrator3_P2_o;          /* Expression: 0.001
                                        * Referenced by: '<S66>/Dctintegrator3'
                                        */
  real_T Dct1lowpass_P1_Size_i[2];  /* Computed Parameter: Dct1lowpass_P1_Size_i
                                     * Referenced by: '<S66>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_j;             /* Expression: f_den
                                        * Referenced by: '<S66>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_d[2];  /* Computed Parameter: Dct1lowpass_P2_Size_d
                                     * Referenced by: '<S66>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_h;             /* Expression: 0.001
                                        * Referenced by: '<S66>/Dct1lowpass'
                                        */
  real_T Dctleadlag_P1_Size_d[2];    /* Computed Parameter: Dctleadlag_P1_Size_d
                                      * Referenced by: '<S66>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_f;              /* Expression: f_num
                                        * Referenced by: '<S66>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_g5[2];  /* Computed Parameter: Dctleadlag_P2_Size_g5
                                     * Referenced by: '<S66>/Dctleadlag'
                                     */
  real_T Dctleadlag_P2_go;             /* Expression: f_den
                                        * Referenced by: '<S66>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_i[2];    /* Computed Parameter: Dctleadlag_P3_Size_i
                                      * Referenced by: '<S66>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_b;              /* Expression: 0.001
                                        * Referenced by: '<S66>/Dctleadlag'
                                        */
  real_T HomingRunningSwitch_Threshold_i;/* Expression: 0.5
                                          * Referenced by: '<S25>/Homing Running Switch'
                                          */
  real_T Gain_Gain_fm;                 /* Expression: 32
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S57>/Constant1'
                                        */
  real_T LimitSpeed_RisingLim;         /* Expression: 0.2
                                        * Referenced by: '<S57>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim;        /* Expression: -0.2
                                        * Referenced by: '<S57>/Limit Speed'
                                        */
  real_T LimitSpeed_IC;                /* Expression: 0
                                        * Referenced by: '<S57>/Limit Speed'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S64>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim;  /* Expression: 0.5
                                        * Referenced by: '<S57>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim; /* Expression: -0.5
                                        * Referenced by: '<S57>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_IC;         /* Expression: 0
                                        * Referenced by: '<S57>/Limit Acceleration'
                                        */
  real_T DiscreteTimeIntegrator_gainva_f;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                           * Referenced by: '<S57>/Discrete-Time Integrator'
                           */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S65>/TSamp'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S44>/Constant1'
                                        */
  real_T LimitSpeed_RisingLim_l;       /* Expression: 0.4
                                        * Referenced by: '<S44>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim_j;      /* Expression: -0.4
                                        * Referenced by: '<S44>/Limit Speed'
                                        */
  real_T LimitSpeed_IC_m;              /* Expression: 0
                                        * Referenced by: '<S44>/Limit Speed'
                                        */
  real_T TSamp_WtEt_f;                 /* Computed Parameter: TSamp_WtEt_f
                                        * Referenced by: '<S51>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim_k;/* Expression: 0.5
                                        * Referenced by: '<S44>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim_l;/* Expression: -0.5
                                         * Referenced by: '<S44>/Limit Acceleration'
                                         */
  real_T LimitAcceleration_IC_h;       /* Expression: 0
                                        * Referenced by: '<S44>/Limit Acceleration'
                                        */
  real_T DiscreteTimeIntegrator_gainva_l;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                           * Referenced by: '<S44>/Discrete-Time Integrator'
                           */
  real_T TSamp_WtEt_k;                 /* Computed Parameter: TSamp_WtEt_k
                                        * Referenced by: '<S52>/TSamp'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T LimitSpeed_RisingLim_a;       /* Expression: 0.6
                                        * Referenced by: '<S35>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim_i;      /* Expression: -0.6
                                        * Referenced by: '<S35>/Limit Speed'
                                        */
  real_T LimitSpeed_IC_j;              /* Expression: 0
                                        * Referenced by: '<S35>/Limit Speed'
                                        */
  real_T TSamp_WtEt_p;                 /* Computed Parameter: TSamp_WtEt_p
                                        * Referenced by: '<S39>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim_n;/* Expression: 0.8
                                        * Referenced by: '<S35>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim_n;/* Expression: -0.8
                                         * Referenced by: '<S35>/Limit Acceleration'
                                         */
  real_T LimitAcceleration_IC_j;       /* Expression: 0
                                        * Referenced by: '<S35>/Limit Acceleration'
                                        */
  real_T DiscreteTimeIntegrator_gainva_c;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                           * Referenced by: '<S35>/Discrete-Time Integrator'
                           */
  real_T TSamp_WtEt_g;                 /* Computed Parameter: TSamp_WtEt_g
                                        * Referenced by: '<S40>/TSamp'
                                        */
  char_T LEDRing_Y0[256];              /* Computed Parameter: LEDRing_Y0
                                        * Referenced by: '<S1>/LED Ring [-]'
                                        */
  char_T Colorsetwithstringblackorwhite_[256];
                          /* Computed Parameter: Colorsetwithstringblackorwhite_
                           * Referenced by: '<S1>/Color; set with string; black or white'
                           */
  char_T Colorspecifiedin6hexdigitsrrggb[256];
                          /* Computed Parameter: Colorspecifiedin6hexdigitsrrggb
                           * Referenced by: '<S1>/Color; specified in 6 hex digits, rrggbb'
                           */
  char_T StringConstant3_String[256];
                                   /* Computed Parameter: StringConstant3_String
                                    * Referenced by: '<S30>/String Constant3'
                                    */
  char_T StringConstant1_String[256];
                                   /* Computed Parameter: StringConstant1_String
                                    * Referenced by: '<S30>/String Constant1'
                                    */
  char_T StringConstant4_String[256];
                                   /* Computed Parameter: StringConstant4_String
                                    * Referenced by: '<S28>/String Constant4'
                                    */
  char_T ReadyGreen_String[256];       /* Computed Parameter: ReadyGreen_String
                                        * Referenced by: '<S16>/Ready Green'
                                        */
  char_T AirbagRed_String[256];        /* Computed Parameter: AirbagRed_String
                                        * Referenced by: '<S16>/Airbag Red'
                                        */
  char_T HomingOrange_String[256];    /* Computed Parameter: HomingOrange_String
                                       * Referenced by: '<S16>/Homing Orange'
                                       */
  char_T Delay_InitialCondition[256];
                                   /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S27>/Delay'
                                    */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S1>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S1>/Manual Switch1'
                              */
  uint8_T Constant1_Value_l;           /* Computed Parameter: Constant1_Value_l
                                        * Referenced by: '<S29>/Constant1'
                                        */
  uint8_T Constant_Value_b;            /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S30>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Callibration_check_Robot_Ipos_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[27];
    SimStruct *childSFunctionPtrs[27];
    struct _ssBlkInfo2 blkInfo2[27];
    struct _ssSFcnModelMethods2 methods2[27];
    struct _ssSFcnModelMethods3 methods3[27];
    struct _ssSFcnModelMethods4 methods4[27];
    struct _ssStatesInfo2 statesInfo2[27];
    ssPeriodicStatesInfo periodicStatesInfo[27];
    struct _ssPortInfo2 inputOutputPortInfo2[27];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[6];
      struct _ssInPortUnit inputPortUnits[6];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[6];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      real_T const *UPtrs4[1];
      real_T const *UPtrs5[1];
      struct _ssPortOutputs outputPortInfo[5];
      struct _ssOutPortUnit outputPortUnits[5];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[5];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn16;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn19;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn20;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn21;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn22;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn23;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn24;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn25;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn26;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Callibration_check_Robot_Ipos_T Callibration_check_Robot_Ipos_P;

/* Block signals (default storage) */
extern B_Callibration_check_Robot_Ipos_T Callibration_check_Robot_Ipos_B;

/* Block states (default storage) */
extern DW_Callibration_check_Robot_Ipos_T Callibration_check_Robot_Ipos_DW;

/* Model entry point functions */
extern void Callibration_check_Robot_Ipos_initialize(void);
extern void Callibration_check_Robot_Ipos_step(void);
extern void Callibration_check_Robot_Ipos_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Callibration_check_Robot_Ipos_T *const
  Callibration_check_Robot_Ipos_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S22>/Constant1' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Saturation' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate' : Unused code path elimination
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Callibration_check_Robot_Ipos'
 * '<S1>'   : 'Callibration_check_Robot_Ipos/Controller'
 * '<S2>'   : 'Callibration_check_Robot_Ipos/RobotArm'
 * '<S3>'   : 'Callibration_check_Robot_Ipos/Supervisor2'
 * '<S4>'   : 'Callibration_check_Robot_Ipos/Controller/Camera'
 * '<S5>'   : 'Callibration_check_Robot_Ipos/Controller/Controller Conveyor'
 * '<S6>'   : 'Callibration_check_Robot_Ipos/Controller/Controller R'
 * '<S7>'   : 'Callibration_check_Robot_Ipos/Controller/Controller Vacuum'
 * '<S8>'   : 'Callibration_check_Robot_Ipos/Controller/Controller X'
 * '<S9>'   : 'Callibration_check_Robot_Ipos/Controller/Controller Z'
 * '<S10>'  : 'Callibration_check_Robot_Ipos/Controller/Measurement Block'
 * '<S11>'  : 'Callibration_check_Robot_Ipos/Controller/Stateflow '
 * '<S12>'  : 'Callibration_check_Robot_Ipos/Controller/Camera/Detect Change'
 * '<S13>'  : 'Callibration_check_Robot_Ipos/Controller/Camera/Enabled Subsystem'
 * '<S14>'  : 'Callibration_check_Robot_Ipos/Controller/Measurement Block/SPERTE_measurement_function'
 * '<S15>'  : 'Callibration_check_Robot_Ipos/RobotArm/Subsystem'
 * '<S16>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor'
 * '<S17>'  : 'Callibration_check_Robot_Ipos/RobotArm/Subsystem/Ipos'
 * '<S18>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Compare To Constant'
 * '<S19>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Compare To Constant1'
 * '<S20>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/HomingBusyCheck'
 * '<S21>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Subsystem'
 * '<S22>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R'
 * '<S23>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X'
 * '<S24>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z'
 * '<S25>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Conveyor1'
 * '<S26>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Subsystem/LED Ring'
 * '<S27>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem'
 * '<S28>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3'
 * '<S29>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3/If Action Subsystem'
 * '<S30>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3/If Action Subsystem1'
 * '<S31>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/ '
 * '<S32>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/   '
 * '<S33>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/Angle2Z'
 * '<S34>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/MATLAB Function2'
 * '<S35>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory'
 * '<S36>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory1'
 * '<S37>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/Selector1'
 * '<S38>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/Supervisor'
 * '<S39>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory/Discrete Derivative'
 * '<S40>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory1/Discrete Derivative'
 * '<S41>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Controller X1'
 * '<S42>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Controller X2'
 * '<S43>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/MATLAB Function'
 * '<S44>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory'
 * '<S45>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory1'
 * '<S46>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector'
 * '<S47>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector1'
 * '<S48>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector2'
 * '<S49>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector3'
 * '<S50>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Supervisor2'
 * '<S51>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory/Discrete Derivative'
 * '<S52>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory1/Discrete Derivative'
 * '<S53>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/    '
 * '<S54>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/     '
 * '<S55>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Angle2Z'
 * '<S56>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/MATLAB Function1'
 * '<S57>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory'
 * '<S58>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory1'
 * '<S59>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector'
 * '<S60>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector1'
 * '<S61>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector2'
 * '<S62>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector3'
 * '<S63>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Supervisor'
 * '<S64>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory/Discrete Derivative'
 * '<S65>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory1/Discrete Derivative'
 * '<S66>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Conveyor1/Controller Conveyor'
 * '<S67>'  : 'Callibration_check_Robot_Ipos/RobotArm/Supervisor/Supervisory Conveyor1/Supervisor'
 */
#endif                         /* RTW_HEADER_Callibration_check_Robot_Ipos_h_ */
