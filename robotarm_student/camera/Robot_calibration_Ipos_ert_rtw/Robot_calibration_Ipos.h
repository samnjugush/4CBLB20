/*
 * Robot_calibration_Ipos.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Robot_calibration_Ipos".
 *
 * Model version              : 2.118
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Mon Jan 27 11:52:02 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Robot_calibration_Ipos_h_
#define RTW_HEADER_Robot_calibration_Ipos_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#ifndef Robot_calibration_Ipos_COMMON_INCLUDES_
#define Robot_calibration_Ipos_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SCI.h"
#endif                             /* Robot_calibration_Ipos_COMMON_INCLUDES_ */

#include "Robot_calibration_Ipos_types.h"

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
} DW_SerialWrite1_Robot_calibra_T;

/* Block signals for system '<S23>/quintic trajectory time' */
typedef struct {
  real_T A[36];
  real_T B[6];
  real_T path;                         /* '<S23>/quintic trajectory time' */
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
} B_quintictrajectorytime_Robot_T;

/* Block states (default storage) for system '<S23>/quintic trajectory time' */
typedef struct {
  real_T previous_value_reference_start;/* '<S23>/quintic trajectory time' */
  real_T previous_value_reference_end; /* '<S23>/quintic trajectory time' */
  real_T index;                        /* '<S23>/quintic trajectory time' */
  emxArray_real_T_Robot_calibra_T* path_array;/* '<S23>/quintic trajectory time' */
  boolean_T path_array_not_empty;      /* '<S23>/quintic trajectory time' */
} DW_quintictrajectorytime_Robo_T;

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
  real_T Constant1;                    /* '<S34>/Constant1' */
  real_T DiscreteTimeIntegrator;       /* '<S34>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_p;     /* '<S22>/Discrete-Time Integrator' */
  real_T Sum;                          /* '<S22>/Sum' */
  real_T Sum2;                         /* '<S22>/Sum2' */
  real_T Gain1;                        /* '<S15>/Gain1' */
  real_T DiscreteTimeIntegrator_d;     /* '<S23>/Discrete-Time Integrator' */
  real_T set_robot_calibration_x;      /* '<S16>/set_robot_calibration_x' */
  real_T Sum_p;                        /* '<S23>/Sum' */
  real_T Sum2_a;                       /* '<S23>/Sum2' */
  real_T Gain2;                        /* '<S15>/Gain2' */
  real_T DiscreteTimeIntegrator_pg;    /* '<S24>/Discrete-Time Integrator' */
  real_T set_robot_calibration_z;      /* '<S16>/set_robot_calibration_z' */
  real_T Sum_o;                        /* '<S24>/Sum' */
  real_T Sum2_e;                       /* '<S24>/Sum2' */
  real_T set_robot_calibration_r;      /* '<S16>/set_robot_calibration_r' */
  real_T Add1;                         /* '<S20>/Add1' */
  real_T Gain3;                        /* '<S15>/Gain3' */
  real_T Gain5;                        /* '<S15>/Gain5' */
  real_T Saturation;                   /* '<S17>/Saturation' */
  real_T Gain_h;                       /* '<S31>/Gain' */
  real_T Dctintegrator;                /* '<S31>/Dctintegrator' */
  real_T Dctleadlag;                   /* '<S31>/Dctleadlag' */
  real_T Dct1lowpass;                  /* '<S31>/Dct1lowpass' */
  real_T Product;                      /* '<S22>/Product' */
  real_T HomingRunningSwitch;          /* '<S22>/Homing Running Switch' */
  real_T Gain_p;                       /* '<S32>/Gain' */
  real_T Dctleadlag_l;                 /* '<S32>/Dctleadlag' */
  real_T Dct1lowpass_i;                /* '<S32>/Dct1lowpass' */
  real_T AirbagSwitch;                 /* '<S22>/AirbagSwitch' */
  real_T Product1;                     /* '<S22>/Product1' */
  real_T Saturation1;                  /* '<S22>/Saturation1' */
  real_T Gain1_p;                      /* '<S38>/Gain1' */
  real_T Dctintegrator_g;              /* '<S38>/Dctintegrator' */
  real_T Dctleadlag_h;                 /* '<S38>/Dctleadlag' */
  real_T Dct1lowpass_k;                /* '<S38>/Dct1lowpass' */
  real_T Gain1_o;                      /* '<S39>/Gain1' */
  real_T Dctleadlag_b;                 /* '<S39>/Dctleadlag' */
  real_T Dct1lowpass_j;                /* '<S39>/Dct1lowpass' */
  real_T Saturation1_n;                /* '<S23>/Saturation1' */
  real_T Gain_i;                       /* '<S48>/Gain' */
  real_T Dctintegrator_i;              /* '<S48>/Dctintegrator' */
  real_T Dctleadlag_m;                 /* '<S48>/Dctleadlag' */
  real_T Dct1lowpass_p;                /* '<S48>/Dct1lowpass' */
  real_T Gain_f;                       /* '<S49>/Gain' */
  real_T Dctleadlag_e;                 /* '<S49>/Dctleadlag' */
  real_T Dct1lowpass_a;                /* '<S49>/Dct1lowpass' */
  real_T Saturation1_a;                /* '<S24>/Saturation1' */
  real_T DiscreteTimeIntegrator_i;     /* '<S25>/Discrete-Time Integrator' */
  real_T Gain1_a;                      /* '<S59>/Gain1' */
  real_T Dctintegrator3;               /* '<S59>/Dctintegrator3' */
  real_T Dct1lowpass_g;                /* '<S59>/Dct1lowpass' */
  real_T Dctleadlag_k;                 /* '<S59>/Dctleadlag' */
  real_T HomingRunningSwitch_e;        /* '<S25>/Homing Running Switch' */
  real_T Saturation1_d;                /* '<S25>/Saturation1' */
  real_T Constant1_f;                  /* '<S51>/Constant1' */
  real_T DiscreteTimeIntegrator_pv;    /* '<S51>/Discrete-Time Integrator' */
  real_T Constant1_e;                  /* '<S40>/Constant1' */
  real_T DiscreteTimeIntegrator_e;     /* '<S40>/Discrete-Time Integrator' */
  real_T jogSpeed;                     /* '<S25>/Supervisor' */
  real_T homeControllerEnabled;        /* '<S25>/Supervisor' */
  real_T resetEnc;                     /* '<S25>/Supervisor' */
  real_T homingBusy;                   /* '<S25>/Supervisor' */
  real_T Ready;                        /* '<S25>/Supervisor' */
  real_T StopSim;                      /* '<S25>/Supervisor' */
  real_T jogSpeed_o;                   /* '<S24>/Supervisor' */
  real_T toPoint;                      /* '<S24>/Supervisor' */
  real_T homeControllerEnabled_m;      /* '<S24>/Supervisor' */
  real_T resetEnc_h;                   /* '<S24>/Supervisor' */
  real_T homingBusy_j;                 /* '<S24>/Supervisor' */
  real_T freddy;                       /* '<S24>/Supervisor' */
  real_T airBagEnabled;                /* '<S24>/Supervisor' */
  real_T airBagRef;                    /* '<S24>/Supervisor' */
  real_T controlEnabled;               /* '<S24>/Supervisor' */
  real_T Ready_b;                      /* '<S24>/Supervisor' */
  real_T StopSim_c;                    /* '<S24>/Supervisor' */
  real_T y;                            /* '<S24>/Angle2Z' */
  real_T jogSpeed_l;                   /* '<S23>/Supervisor2' */
  real_T toPoint_j;                    /* '<S23>/Supervisor2' */
  real_T homeControllerEnabled_a;      /* '<S23>/Supervisor2' */
  real_T resetEnc_d;                   /* '<S23>/Supervisor2' */
  real_T freddy_a;                     /* '<S23>/Supervisor2' */
  real_T homingBusy_i;                 /* '<S23>/Supervisor2' */
  real_T airBagEnabled_o;              /* '<S23>/Supervisor2' */
  real_T airBagRef_j;                  /* '<S23>/Supervisor2' */
  real_T controlEnabled_p;             /* '<S23>/Supervisor2' */
  real_T Ready_c;                      /* '<S23>/Supervisor2' */
  real_T StopSim_g;                    /* '<S23>/Supervisor2' */
  real_T jogSpeed_o1;                  /* '<S22>/Supervisor' */
  real_T toPoint_d;                    /* '<S22>/Supervisor' */
  real_T homeControllerEnabled_c;      /* '<S22>/Supervisor' */
  real_T resetEnc_g;                   /* '<S22>/Supervisor' */
  real_T freddy_n;                     /* '<S22>/Supervisor' */
  real_T homingBusy_jt;                /* '<S22>/Supervisor' */
  real_T airBagEnabled_m;              /* '<S22>/Supervisor' */
  real_T airBagRef_n;                  /* '<S22>/Supervisor' */
  real_T controlEnabled_i;             /* '<S22>/Supervisor' */
  real_T Ready_g;                      /* '<S22>/Supervisor' */
  real_T StopSim_i;                    /* '<S22>/Supervisor' */
  real_T y_e;                          /* '<S22>/Angle2Z' */
  real_T Selector2[9];                 /* '<S4>/Selector2' */
  real_T Selector[3];                  /* '<S4>/Selector' */
  real_T Conveyorreferencemm;          /* '<S1>/Discrete  integrator' */
  real_T Gain1_k;                      /* '<S5>/Gain1' */
  real_T Dctintegrator3_m;             /* '<S5>/Dctintegrator3' */
  real_T Dct1lowpass_b;                /* '<S5>/Dct1lowpass' */
  real_T Dctleadlag_ei;                /* '<S5>/Dctleadlag' */
  real_T SFunctionBuilder;             /* '<S4>/S-Function Builder' */
  real_T Sum_l;                        /* '<S4>/Sum' */
  real_T SignalConversion2;            /* '<S1>/Signal Conversion2' */
  real_T SignalConversion1;            /* '<S1>/Signal Conversion1' */
  real_T SignalConversion;             /* '<S1>/Signal Conversion' */
  real_T Sum4;                         /* '<S1>/Sum4' */
  real_T Sum5;                         /* '<S1>/Sum5' */
  real_T Sum6;                         /* '<S1>/Sum6' */
  real_T Gain1_b;                      /* '<S7>/Gain1' */
  real_T Doubleclickswitch;            /* '<S1>/Manual Switch' */
  real_T Object;                       /* '<S1>/Object' */
  real_T Plot;                         /* '<S1>/Plot' */
  real_T Stop;                         /* '<S1>/Stop' */
  real_T In1;                          /* '<S13>/In1' */
  real_T d12;
  real_T fx1_tmp;
  real_T fy1_tmp;
  real_T fy2_tmp;
  real_T d12_tmp;
  real_T d13_tmp;
  real_T LimitAcceleration_h;          /* '<S34>/Limit Acceleration' */
  real_T LimitAcceleration_b;          /* '<S40>/Limit Acceleration' */
  real_T LimitAcceleration;            /* '<S51>/Limit Acceleration' */
  real_T HomingRunningSwitch1_f;       /* '<S24>/Homing Running Switch1' */
  real_T HomingRunningSwitch1_l;       /* '<S23>/Homing Running Switch1' */
  real_T Add;                          /* '<S16>/Add' */
  real_T Add2;                         /* '<S16>/Add2' */
  real_T TSamp_k;                      /* '<S37>/TSamp' */
  real_T TSamp_d;                      /* '<S47>/TSamp' */
  real_T TSamp;                        /* '<S58>/TSamp' */
  real_T Saturation_c;                 /* '<S1>/Saturation ' */
  int32_T i;
  int32_T Selector2_tmp;
  int32_T loop_ub;
  int32_T i_b;
  int32_T i1;
  int32_T newNumel;
  int32_T i_p;
  int32_T i_c;
  uint32_T qY;
  int8_T b_fileid;
  int8_T j;
  boolean_T RelationalOperator;        /* '<S22>/Relational Operator' */
  boolean_T RelationalOperator_f;      /* '<S23>/Relational Operator' */
  boolean_T RelationalOperator_k;      /* '<S24>/Relational Operator' */
  boolean_T Compare;                   /* '<S19>/Compare' */
  boolean_T Compare_j;                 /* '<S18>/Compare' */
  boolean_T a;
  B_quintictrajectorytime_Robot_T sf_quintictrajectorytime_i;/* '<S24>/quintic trajectory time' */
  B_quintictrajectorytime_Robot_T sf_quintictrajectorytime;/* '<S23>/quintic trajectory time' */
} B_Robot_calibration_Ipos_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S34>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S22>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S23>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S23>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S24>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE_b;           /* '<S24>/Unit Delay' */
  real_T UnitDelay_DSTATE_f;           /* '<S16>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S16>/Unit Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S25>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S58>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S51>/Discrete-Time Integrator' */
  real_T UD_DSTATE_c;                  /* '<S47>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S40>/Discrete-Time Integrator' */
  real_T UD_DSTATE_cc;                 /* '<S37>/UD' */
  real_T DelayInput1_DSTATE[12];       /* '<S12>/Delay Input1' */
  real_T Discreteintegrator_DSTATE;    /* '<S1>/Discrete  integrator' */
  char_T Delay_DSTATE[256];            /* '<S27>/Delay' */
  real_T PrevY;                        /* '<S51>/Limit Speed' */
  real_T PrevY_j;                      /* '<S51>/Limit Acceleration' */
  real_T PrevY_d;                      /* '<S40>/Limit Speed' */
  real_T PrevY_f;                      /* '<S40>/Limit Acceleration' */
  real_T PrevY_i;                      /* '<S34>/Limit Speed' */
  real_T PrevY_k;                      /* '<S34>/Limit Acceleration' */
  real_T currentcarPos;                /* '<S24>/Supervisor' */
  real_T currentcarPos_m;              /* '<S23>/Supervisor2' */
  real_T currentcarPos_b;              /* '<S22>/Supervisor' */
  real_T fileID;                       /* '<S10>/SPERTE_measurement_function' */
  real_T Dctintegrator_RWORK[2];       /* '<S31>/Dctintegrator' */
  real_T Dctleadlag_RWORK[2];          /* '<S31>/Dctleadlag' */
  real_T Dct1lowpass_RWORK[2];         /* '<S31>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_k[2];        /* '<S32>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_a[2];       /* '<S32>/Dct1lowpass' */
  real_T Dctintegrator_RWORK_m[2];     /* '<S38>/Dctintegrator' */
  real_T Dctleadlag_RWORK_g[2];        /* '<S38>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_n[2];       /* '<S38>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_j[2];        /* '<S39>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_k[2];       /* '<S39>/Dct1lowpass' */
  real_T Dctintegrator_RWORK_i[2];     /* '<S48>/Dctintegrator' */
  real_T Dctleadlag_RWORK_n[2];        /* '<S48>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_g[2];       /* '<S48>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_i[2];        /* '<S49>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_h[2];       /* '<S49>/Dct1lowpass' */
  real_T Dctintegrator3_RWORK[2];      /* '<S59>/Dctintegrator3' */
  real_T Dct1lowpass_RWORK_ay[2];      /* '<S59>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_o[2];        /* '<S59>/Dctleadlag' */
  real_T Dctintegrator3_RWORK_e[2];    /* '<S5>/Dctintegrator3' */
  real_T Dct1lowpass_RWORK_e[2];       /* '<S5>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_h[2];        /* '<S5>/Dctleadlag' */
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
  } Scope5_PWORK;                      /* '<S24>/Scope5' */

  struct {
    void *LoggedData;
  } Scope17_PWORK;                     /* '<S23>/Scope17' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<S23>/Scope6' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_a;                    /* '<S22>/Scope1' */

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
  } Scope9_PWORK;                      /* '<S22>/Scope9' */

  struct {
    void *LoggedData;
  } Scope15_PWORK;                     /* '<S22>/Scope15' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S22>/Scope2' */

  struct {
    void *LoggedData;
  } Scope18_PWORK_i;                   /* '<S23>/Scope18' */

  struct {
    void *LoggedData;
  } Scope_PWORK_a;                     /* '<S24>/Scope' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_c;                    /* '<S22>/Scope6' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<S24>/Scope7' */

  struct {
    void *LoggedData;
  } Scope8_PWORK_i;                    /* '<S24>/Scope8' */

  struct {
    void *LoggedData;
  } Scope16_PWORK_l;                   /* '<S24>/Scope16' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_a;                    /* '<S24>/Scope6' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S24>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_i;                    /* '<S24>/Scope4' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_e;                    /* '<S24>/Scope2' */

  struct {
    void *LoggedData;
  } Scope21_PWORK_o;                   /* '<S23>/Scope21' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_ef;                   /* '<S23>/Scope2' */

  struct {
    void *LoggedData;
  } Scope22_PWORK_m;                   /* '<S23>/Scope22' */

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S23>/Scope' */

  struct {
    void *LoggedData;
  } Scope19_PWORK_d;                   /* '<S23>/Scope19' */

  struct {
    void *LoggedData;
  } Scope20_PWORK_a;                   /* '<S23>/Scope20' */

  struct {
    void *LoggedData;
  } Scope16_PWORK_o;                   /* '<S23>/Scope16' */

  struct {
    void *LoggedData;
  } Scope23_PWORK;                     /* '<S23>/Scope23' */

  struct {
    void *LoggedData;
  } Scope_PWORK_n;                     /* '<S22>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_n;                    /* '<S22>/Scope3' */

  struct {
    void *LoggedData;
  } Scope12_PWORK;                     /* '<S22>/Scope12' */

  struct {
    void *LoggedData[2];
  } Scope23_PWORK_e;                   /* '<S22>/Scope23' */

  struct {
    void *LoggedData;
  } Scope13_PWORK;                     /* '<S22>/Scope13' */

  struct {
    void *LoggedData;
  } Scope14_PWORK;                     /* '<S22>/Scope14' */

  struct {
    void *LoggedData;
  } Scope7_PWORK_j;                    /* '<S22>/Scope7' */

  struct {
    void *LoggedData;
  } Scope17_PWORK_o;                   /* '<S22>/Scope17' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S35>/Scope' */

  struct {
    void *LoggedData;
  } Scope5_PWORK_c;                    /* '<S22>/Scope5' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_h;                    /* '<S1>/Scope1' */

  int32_T sfEvent;                     /* '<S25>/Supervisor' */
  int32_T sfEvent_o;                   /* '<S24>/Supervisor' */
  int32_T sfEvent_j;                   /* '<S23>/Supervisor2' */
  int32_T sfEvent_m;                   /* '<S22>/Supervisor' */
  int32_T sfEvent_k;                   /* '<S1>/Stateflow ' */
  uint32_T is_c1_Robot_calibration_Ipos;/* '<S25>/Supervisor' */
  uint32_T is_c18_Robot_calibration_Ipos;/* '<S24>/Supervisor' */
  uint32_T is_c16_Robot_calibration_Ipos;/* '<S23>/Supervisor2' */
  uint32_T is_c12_Robot_calibration_Ipos;/* '<S22>/Supervisor' */
  uint32_T is_Object_Detection;        /* '<S1>/Stateflow ' */
  uint32_T is_Belt;                    /* '<S1>/Stateflow ' */
  uint32_T is_Robot_Arm;               /* '<S1>/Stateflow ' */
  uint32_T is_Vacuum;                  /* '<S1>/Stateflow ' */
  uint32_T NS;                         /* '<S10>/SPERTE_measurement_function' */
  int16_T NF;                          /* '<S10>/SPERTE_measurement_function' */
  uint16_T temporalCounter_i1;         /* '<S25>/Supervisor' */
  uint16_T temporalCounter_i1_d;       /* '<S24>/Supervisor' */
  uint16_T temporalCounter_i1_di;      /* '<S23>/Supervisor2' */
  uint16_T temporalCounter_i1_b;       /* '<S22>/Supervisor' */
  int8_T Subsystem3_SubsysRanBC;       /* '<S26>/Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S28>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S28>/If Action Subsystem' */
  int8_T Controller_SubsysRanBC;       /* '<Root>/Controller' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S4>/Enabled Subsystem' */
  uint8_T is_active_c1_Robot_calibration_;/* '<S25>/Supervisor' */
  uint8_T is_active_c18_Robot_calibration;/* '<S24>/Supervisor' */
  uint8_T is_active_c16_Robot_calibration;/* '<S23>/Supervisor2' */
  uint8_T is_active_c12_Robot_calibration;/* '<S22>/Supervisor' */
  uint8_T is_active_c3_Robot_calibration_;/* '<S1>/Stateflow ' */
  uint8_T is_active_Object_Detection;  /* '<S1>/Stateflow ' */
  uint8_T is_active_Belt;              /* '<S1>/Stateflow ' */
  uint8_T is_active_Robot_Arm;         /* '<S1>/Stateflow ' */
  uint8_T is_active_Vacuum;            /* '<S1>/Stateflow ' */
  uint8_T busy;                        /* '<S10>/SPERTE_measurement_function' */
  boolean_T doneDoubleBufferReInit;    /* '<S1>/Stateflow ' */
  boolean_T eml_autoflush[20];         /* '<S10>/SPERTE_measurement_function' */
  FILE * eml_openfiles[20];            /* '<S10>/SPERTE_measurement_function' */
  boolean_T Controller_MODE;           /* '<Root>/Controller' */
  DW_quintictrajectorytime_Robo_T sf_quintictrajectorytime_i;/* '<S24>/quintic trajectory time' */
  DW_quintictrajectorytime_Robo_T sf_quintictrajectorytime;/* '<S23>/quintic trajectory time' */
  DW_SerialWrite1_Robot_calibra_T SerialWrite;/* '<S29>/Serial Write1' */
  DW_SerialWrite1_Robot_calibra_T SerialWrite1;/* '<S29>/Serial Write1' */
} DW_Robot_calibration_Ipos_T;

/* Parameters (default storage) */
struct P_Robot_calibration_Ipos_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S58>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_e;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_e
                               * Referenced by: '<S47>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_h;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_h
                               * Referenced by: '<S37>/UD'
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
  real_T Gain_Gain;                    /* Expression: 5
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T FeedfowardRV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward R [V]'
                                        */
  real_T ReferenceXrad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Reference X [rad]'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 5
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T FeedfowardXV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward X [V]'
                                        */
  real_T ReferenceZrad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Reference Z [rad]'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 5
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
  real_T HomingRunningSwitch_Threshold;/* Expression: 0.5
                                        * Referenced by: '<S23>/Homing Running Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T HomingRunningSwitch_Threshold_d;/* Expression: 0.5
                                          * Referenced by: '<S24>/Homing Running Switch'
                                          */
  real_T Constant1_Value_f;            /* Expression: 0
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
  real_T Gain_Gain_n;                  /* Expression: 1/16000*9/150*2*pi
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S34>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S34>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_gainva_i;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                           * Referenced by: '<S22>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S22>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value;               /* Expression: -0.05
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Gain1_Gain_g2;                /* Expression: 1/16000*9/100*2*pi
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_h;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_h
                           * Referenced by: '<S23>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S23>/Discrete-Time Integrator'
                                        */
  real_T set_robot_calibration_x_Value;/* Expression: 0.58
                                        * Referenced by: '<S16>/set_robot_calibration_x'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S23>/Unit Delay'
                                        */
  real_T HomingRunningSwitch1_Threshol_h;/* Expression: 0.5
                                          * Referenced by: '<S23>/Homing Running Switch1'
                                          */
  real_T Constant2_Value;              /* Expression: 2
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S23>/Constant3'
                                        */
  real_T Constant_Value_f;             /* Expression: -0.1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/16000*9/100*2*pi
                                        * Referenced by: '<S15>/Gain2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_o;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                           * Referenced by: '<S24>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_o;  /* Expression: 0
                                        * Referenced by: '<S24>/Discrete-Time Integrator'
                                        */
  real_T set_robot_calibration_z_Value;/* Expression: -0.36
                                        * Referenced by: '<S16>/set_robot_calibration_z'
                                        */
  real_T UnitDelay_InitialCondition_d; /* Expression: 0
                                        * Referenced by: '<S24>/Unit Delay'
                                        */
  real_T HomingRunningSwitch1_Threshol_p;/* Expression: 0.5
                                          * Referenced by: '<S24>/Homing Running Switch1'
                                          */
  real_T Constant2_Value_h;            /* Expression: 2
                                        * Referenced by: '<S24>/Constant2'
                                        */
  real_T Constant3_Value_m;            /* Expression: 0
                                        * Referenced by: '<S24>/Constant3'
                                        */
  real_T Constant_Value_o;             /* Expression: 0.05
                                        * Referenced by: '<S24>/Constant'
                                        */
  real_T UnitDelay_InitialCondition_k; /* Expression: 0
                                        * Referenced by: '<S16>/Unit Delay'
                                        */
  real_T set_robot_calibration_r_Value;/* Expression: 1.23
                                        * Referenced by: '<S16>/set_robot_calibration_r'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 3
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/16000*2*pi*2.05*10
                                        * Referenced by: '<S15>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/65535
                                        * Referenced by: '<S15>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1/2
                                        * Referenced by: '<S15>/Gain5'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 255
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: 0
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S16>/Unit Delay1'
                                        */
  real_T HomingRunningSwitch_Threshold_l;/* Expression: 0.5
                                          * Referenced by: '<S21>/Homing Running Switch'
                                          */
  real_T ResetEncoderR_P1_Size[2];  /* Computed Parameter: ResetEncoderR_P1_Size
                                     * Referenced by: '<S22>/Reset EncoderR'
                                     */
  real_T ResetEncoderR_P1;             /* Expression: ipos_id
                                        * Referenced by: '<S22>/Reset EncoderR'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 25
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
  real_T Dctleadlag_P1_Size_m[2];    /* Computed Parameter: Dctleadlag_P1_Size_m
                                      * Referenced by: '<S31>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_g;              /* Expression: f_num
                                        * Referenced by: '<S31>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_p[2];    /* Computed Parameter: Dctleadlag_P2_Size_p
                                      * Referenced by: '<S31>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_g;              /* Expression: f_den
                                        * Referenced by: '<S31>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_h[2];    /* Computed Parameter: Dctleadlag_P3_Size_h
                                      * Referenced by: '<S31>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_e;              /* Expression: 0.001
                                        * Referenced by: '<S31>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_m[2];  /* Computed Parameter: Dct1lowpass_P1_Size_m
                                     * Referenced by: '<S31>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_e;             /* Expression: f_den
                                        * Referenced by: '<S31>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_o[2];  /* Computed Parameter: Dct1lowpass_P2_Size_o
                                     * Referenced by: '<S31>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_a;             /* Expression: 0.001
                                        * Referenced by: '<S31>/Dct1lowpass'
                                        */
  real_T HomingRunningSwitch_Threshold_g;/* Expression: 0.5
                                          * Referenced by: '<S22>/Homing Running Switch'
                                          */
  real_T Gain_Gain_c;                  /* Expression: 25
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Dctleadlag_P1_Size_c[2];    /* Computed Parameter: Dctleadlag_P1_Size_c
                                      * Referenced by: '<S32>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_e;              /* Expression: f_num
                                        * Referenced by: '<S32>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_k[2];    /* Computed Parameter: Dctleadlag_P2_Size_k
                                      * Referenced by: '<S32>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_b;              /* Expression: f_den
                                        * Referenced by: '<S32>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_hn[2];  /* Computed Parameter: Dctleadlag_P3_Size_hn
                                     * Referenced by: '<S32>/Dctleadlag'
                                     */
  real_T Dctleadlag_P3_g;              /* Expression: 0.001
                                        * Referenced by: '<S32>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_a[2];  /* Computed Parameter: Dct1lowpass_P1_Size_a
                                     * Referenced by: '<S32>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_g;             /* Expression: f_den
                                        * Referenced by: '<S32>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_l[2];  /* Computed Parameter: Dct1lowpass_P2_Size_l
                                     * Referenced by: '<S32>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_i;             /* Expression: 0.001
                                        * Referenced by: '<S32>/Dct1lowpass'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 32
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 127
                                        * Referenced by: '<S22>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -127
                                        * Referenced by: '<S22>/Saturation1'
                                        */
  real_T ResetEncoderR1_P1_Size[2];/* Computed Parameter: ResetEncoderR1_P1_Size
                                    * Referenced by: '<S23>/Reset EncoderR1'
                                    */
  real_T ResetEncoderR1_P1;            /* Expression: ipos_id
                                        * Referenced by: '<S23>/Reset EncoderR1'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 20
                                        * Referenced by: '<S38>/Gain1'
                                        */
  real_T Dctintegrator_P1_Size_i[2];
                                  /* Computed Parameter: Dctintegrator_P1_Size_i
                                   * Referenced by: '<S38>/Dctintegrator'
                                   */
  real_T Dctintegrator_P1_j;           /* Expression: f_num
                                        * Referenced by: '<S38>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size_p[2];
                                  /* Computed Parameter: Dctintegrator_P2_Size_p
                                   * Referenced by: '<S38>/Dctintegrator'
                                   */
  real_T Dctintegrator_P2_n;           /* Expression: 0.001
                                        * Referenced by: '<S38>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_d[2];    /* Computed Parameter: Dctleadlag_P1_Size_d
                                      * Referenced by: '<S38>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_m;              /* Expression: f_num
                                        * Referenced by: '<S38>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_g[2];    /* Computed Parameter: Dctleadlag_P2_Size_g
                                      * Referenced by: '<S38>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_p;              /* Expression: f_den
                                        * Referenced by: '<S38>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_o[2];    /* Computed Parameter: Dctleadlag_P3_Size_o
                                      * Referenced by: '<S38>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_ge;             /* Expression: 0.001
                                        * Referenced by: '<S38>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_m3[2];/* Computed Parameter: Dct1lowpass_P1_Size_m3
                                    * Referenced by: '<S38>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P1_f;             /* Expression: f_den
                                        * Referenced by: '<S38>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_b[2];  /* Computed Parameter: Dct1lowpass_P2_Size_b
                                     * Referenced by: '<S38>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_k;             /* Expression: 0.001
                                        * Referenced by: '<S38>/Dct1lowpass'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 20
                                        * Referenced by: '<S39>/Gain1'
                                        */
  real_T Dctleadlag_P1_Size_b[2];    /* Computed Parameter: Dctleadlag_P1_Size_b
                                      * Referenced by: '<S39>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_p;              /* Expression: f_num
                                        * Referenced by: '<S39>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_m[2];    /* Computed Parameter: Dctleadlag_P2_Size_m
                                      * Referenced by: '<S39>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_a;              /* Expression: f_den
                                        * Referenced by: '<S39>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_p[2];    /* Computed Parameter: Dctleadlag_P3_Size_p
                                      * Referenced by: '<S39>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_c;              /* Expression: 0.001
                                        * Referenced by: '<S39>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_n[2];  /* Computed Parameter: Dct1lowpass_P1_Size_n
                                     * Referenced by: '<S39>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_h;             /* Expression: f_den
                                        * Referenced by: '<S39>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_g[2];  /* Computed Parameter: Dct1lowpass_P2_Size_g
                                     * Referenced by: '<S39>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_b;             /* Expression: 0.001
                                        * Referenced by: '<S39>/Dct1lowpass'
                                        */
  real_T Gain_Gain_cj;                 /* Expression: 32
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Saturation1_UpperSat_e;       /* Expression: 127
                                        * Referenced by: '<S23>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_p;       /* Expression: -127
                                        * Referenced by: '<S23>/Saturation1'
                                        */
  real_T ResetEncoderR1_P1_Size_d[2];
                                 /* Computed Parameter: ResetEncoderR1_P1_Size_d
                                  * Referenced by: '<S24>/Reset EncoderR1'
                                  */
  real_T ResetEncoderR1_P1_d;          /* Expression: ipos_id
                                        * Referenced by: '<S24>/Reset EncoderR1'
                                        */
  real_T Gain_Gain_cr;                 /* Expression: 20
                                        * Referenced by: '<S48>/Gain'
                                        */
  real_T Dctintegrator_P1_Size_p[2];
                                  /* Computed Parameter: Dctintegrator_P1_Size_p
                                   * Referenced by: '<S48>/Dctintegrator'
                                   */
  real_T Dctintegrator_P1_k;           /* Expression: f_num
                                        * Referenced by: '<S48>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size_o[2];
                                  /* Computed Parameter: Dctintegrator_P2_Size_o
                                   * Referenced by: '<S48>/Dctintegrator'
                                   */
  real_T Dctintegrator_P2_m;           /* Expression: 0.001
                                        * Referenced by: '<S48>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_ch[2];  /* Computed Parameter: Dctleadlag_P1_Size_ch
                                     * Referenced by: '<S48>/Dctleadlag'
                                     */
  real_T Dctleadlag_P1_h;              /* Expression: f_num
                                        * Referenced by: '<S48>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_h[2];    /* Computed Parameter: Dctleadlag_P2_Size_h
                                      * Referenced by: '<S48>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_l;              /* Expression: f_den
                                        * Referenced by: '<S48>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_f[2];    /* Computed Parameter: Dctleadlag_P3_Size_f
                                      * Referenced by: '<S48>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_a;              /* Expression: 0.001
                                        * Referenced by: '<S48>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_ni[2];/* Computed Parameter: Dct1lowpass_P1_Size_ni
                                    * Referenced by: '<S48>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P1_j;             /* Expression: f_den
                                        * Referenced by: '<S48>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_a[2];  /* Computed Parameter: Dct1lowpass_P2_Size_a
                                     * Referenced by: '<S48>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_j;             /* Expression: 0.001
                                        * Referenced by: '<S48>/Dct1lowpass'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 30
                                        * Referenced by: '<S49>/Gain'
                                        */
  real_T Dctleadlag_P1_Size_by[2];  /* Computed Parameter: Dctleadlag_P1_Size_by
                                     * Referenced by: '<S49>/Dctleadlag'
                                     */
  real_T Dctleadlag_P1_i;              /* Expression: f_num
                                        * Referenced by: '<S49>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_j[2];    /* Computed Parameter: Dctleadlag_P2_Size_j
                                      * Referenced by: '<S49>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_o;              /* Expression: f_den
                                        * Referenced by: '<S49>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_oi[2];  /* Computed Parameter: Dctleadlag_P3_Size_oi
                                     * Referenced by: '<S49>/Dctleadlag'
                                     */
  real_T Dctleadlag_P3_aa;             /* Expression: 0.001
                                        * Referenced by: '<S49>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_p[2];  /* Computed Parameter: Dct1lowpass_P1_Size_p
                                     * Referenced by: '<S49>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_j3;            /* Expression: f_den
                                        * Referenced by: '<S49>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_j[2];  /* Computed Parameter: Dct1lowpass_P2_Size_j
                                     * Referenced by: '<S49>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_c;             /* Expression: 0.001
                                        * Referenced by: '<S49>/Dct1lowpass'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 32
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Saturation1_UpperSat_i;       /* Expression: 127
                                        * Referenced by: '<S24>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -127
                                        * Referenced by: '<S24>/Saturation1'
                                        */
  real_T ResetEncoderR1_P1_Size_b[2];
                                 /* Computed Parameter: ResetEncoderR1_P1_Size_b
                                  * Referenced by: '<S25>/Reset EncoderR1'
                                  */
  real_T ResetEncoderR1_P1_l;          /* Expression: ipos_id
                                        * Referenced by: '<S25>/Reset EncoderR1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_g;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                           * Referenced by: '<S25>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_co; /* Expression: 0
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain_ja;                /* Expression: 10*2.5/500
                                        * Referenced by: '<S59>/Gain1'
                                        */
  real_T Dctintegrator3_P1_Size_m[2];
                                 /* Computed Parameter: Dctintegrator3_P1_Size_m
                                  * Referenced by: '<S59>/Dctintegrator3'
                                  */
  real_T Dctintegrator3_P1_j;          /* Expression: f_num
                                        * Referenced by: '<S59>/Dctintegrator3'
                                        */
  real_T Dctintegrator3_P2_Size_b[2];
                                 /* Computed Parameter: Dctintegrator3_P2_Size_b
                                  * Referenced by: '<S59>/Dctintegrator3'
                                  */
  real_T Dctintegrator3_P2_j;          /* Expression: 0.001
                                        * Referenced by: '<S59>/Dctintegrator3'
                                        */
  real_T Dct1lowpass_P1_Size_j[2];  /* Computed Parameter: Dct1lowpass_P1_Size_j
                                     * Referenced by: '<S59>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_ez;            /* Expression: f_den
                                        * Referenced by: '<S59>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_aj[2];/* Computed Parameter: Dct1lowpass_P2_Size_aj
                                    * Referenced by: '<S59>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P2_n;             /* Expression: 0.001
                                        * Referenced by: '<S59>/Dct1lowpass'
                                        */
  real_T Dctleadlag_P1_Size_l[2];    /* Computed Parameter: Dctleadlag_P1_Size_l
                                      * Referenced by: '<S59>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_m0;             /* Expression: f_num
                                        * Referenced by: '<S59>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_n[2];    /* Computed Parameter: Dctleadlag_P2_Size_n
                                      * Referenced by: '<S59>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_f;              /* Expression: f_den
                                        * Referenced by: '<S59>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_d[2];    /* Computed Parameter: Dctleadlag_P3_Size_d
                                      * Referenced by: '<S59>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_i;              /* Expression: 0.001
                                        * Referenced by: '<S59>/Dctleadlag'
                                        */
  real_T HomingRunningSwitch_Threshol_lq;/* Expression: 0.5
                                          * Referenced by: '<S25>/Homing Running Switch'
                                          */
  real_T Gain_Gain_j;                  /* Expression: 32
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 127
                                        * Referenced by: '<S25>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_g;       /* Expression: -127
                                        * Referenced by: '<S25>/Saturation1'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S51>/Constant1'
                                        */
  real_T LimitSpeed_RisingLim;         /* Expression: 0.2
                                        * Referenced by: '<S51>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim;        /* Expression: -0.2
                                        * Referenced by: '<S51>/Limit Speed'
                                        */
  real_T LimitSpeed_IC;                /* Expression: 0
                                        * Referenced by: '<S51>/Limit Speed'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S58>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim;  /* Expression: 0.5
                                        * Referenced by: '<S51>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim; /* Expression: -0.5
                                        * Referenced by: '<S51>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_IC;         /* Expression: 0
                                        * Referenced by: '<S51>/Limit Acceleration'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                           * Referenced by: '<S51>/Discrete-Time Integrator'
                           */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T LimitSpeed_RisingLim_i;       /* Expression: 0.4
                                        * Referenced by: '<S40>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim_k;      /* Expression: -0.4
                                        * Referenced by: '<S40>/Limit Speed'
                                        */
  real_T LimitSpeed_IC_a;              /* Expression: 0
                                        * Referenced by: '<S40>/Limit Speed'
                                        */
  real_T TSamp_WtEt_d;                 /* Computed Parameter: TSamp_WtEt_d
                                        * Referenced by: '<S47>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim_k;/* Expression: 0.5
                                        * Referenced by: '<S40>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim_m;/* Expression: -0.5
                                         * Referenced by: '<S40>/Limit Acceleration'
                                         */
  real_T LimitAcceleration_IC_k;       /* Expression: 0
                                        * Referenced by: '<S40>/Limit Acceleration'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                           * Referenced by: '<S40>/Discrete-Time Integrator'
                           */
  real_T LimitSpeed_RisingLim_iu;      /* Expression: 0.6
                                        * Referenced by: '<S34>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim_j;      /* Expression: -0.6
                                        * Referenced by: '<S34>/Limit Speed'
                                        */
  real_T LimitSpeed_IC_e;              /* Expression: 0
                                        * Referenced by: '<S34>/Limit Speed'
                                        */
  real_T TSamp_WtEt_g;                 /* Computed Parameter: TSamp_WtEt_g
                                        * Referenced by: '<S37>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim_m;/* Expression: 0.8
                                        * Referenced by: '<S34>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim_k;/* Expression: -0.8
                                         * Referenced by: '<S34>/Limit Acceleration'
                                         */
  real_T LimitAcceleration_IC_i;       /* Expression: 0
                                        * Referenced by: '<S34>/Limit Acceleration'
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
  uint8_T Constant1_Value_j;           /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S29>/Constant1'
                                        */
  uint8_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S30>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Robot_calibration_Ipos_T {
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
extern P_Robot_calibration_Ipos_T Robot_calibration_Ipos_P;

/* Block signals (default storage) */
extern B_Robot_calibration_Ipos_T Robot_calibration_Ipos_B;

/* Block states (default storage) */
extern DW_Robot_calibration_Ipos_T Robot_calibration_Ipos_DW;

/* Model entry point functions */
extern void Robot_calibration_Ipos_initialize(void);
extern void Robot_calibration_Ipos_step(void);
extern void Robot_calibration_Ipos_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Robot_calibration_Ipos_T *const Robot_calibration_Ipos_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Reference R [rad]' : Unused code path elimination
 * Block '<S22>/Constant1' : Unused code path elimination
 * Block '<S22>/Constant2' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'Robot_calibration_Ipos'
 * '<S1>'   : 'Robot_calibration_Ipos/Controller'
 * '<S2>'   : 'Robot_calibration_Ipos/RobotArm'
 * '<S3>'   : 'Robot_calibration_Ipos/Supervisor2'
 * '<S4>'   : 'Robot_calibration_Ipos/Controller/Camera'
 * '<S5>'   : 'Robot_calibration_Ipos/Controller/Controller Conveyor'
 * '<S6>'   : 'Robot_calibration_Ipos/Controller/Controller R'
 * '<S7>'   : 'Robot_calibration_Ipos/Controller/Controller Vacuum'
 * '<S8>'   : 'Robot_calibration_Ipos/Controller/Controller X'
 * '<S9>'   : 'Robot_calibration_Ipos/Controller/Controller Z'
 * '<S10>'  : 'Robot_calibration_Ipos/Controller/Measurement Block'
 * '<S11>'  : 'Robot_calibration_Ipos/Controller/Stateflow '
 * '<S12>'  : 'Robot_calibration_Ipos/Controller/Camera/Detect Change'
 * '<S13>'  : 'Robot_calibration_Ipos/Controller/Camera/Enabled Subsystem'
 * '<S14>'  : 'Robot_calibration_Ipos/Controller/Measurement Block/SPERTE_measurement_function'
 * '<S15>'  : 'Robot_calibration_Ipos/RobotArm/Subsystem'
 * '<S16>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor'
 * '<S17>'  : 'Robot_calibration_Ipos/RobotArm/Subsystem/Ipos'
 * '<S18>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Compare To Constant'
 * '<S19>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Compare To Constant1'
 * '<S20>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/HomingBusyCheck'
 * '<S21>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Subsystem'
 * '<S22>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller R'
 * '<S23>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X'
 * '<S24>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z'
 * '<S25>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Conveyor1'
 * '<S26>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Subsystem/LED Ring'
 * '<S27>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem'
 * '<S28>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3'
 * '<S29>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3/If Action Subsystem'
 * '<S30>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3/If Action Subsystem1'
 * '<S31>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller R/ '
 * '<S32>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller R/   '
 * '<S33>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller R/Angle2Z'
 * '<S34>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory'
 * '<S35>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller R/Selector1'
 * '<S36>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller R/Supervisor'
 * '<S37>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory/Discrete Derivative'
 * '<S38>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/Controller X1'
 * '<S39>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/Controller X2'
 * '<S40>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory'
 * '<S41>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector'
 * '<S42>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector1'
 * '<S43>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector2'
 * '<S44>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector3'
 * '<S45>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/Supervisor2'
 * '<S46>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/quintic trajectory time'
 * '<S47>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory/Discrete Derivative'
 * '<S48>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/    '
 * '<S49>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/     '
 * '<S50>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Angle2Z'
 * '<S51>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory'
 * '<S52>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector'
 * '<S53>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector1'
 * '<S54>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector2'
 * '<S55>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector3'
 * '<S56>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Supervisor'
 * '<S57>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/quintic trajectory time'
 * '<S58>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory/Discrete Derivative'
 * '<S59>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Conveyor1/Controller Conveyor'
 * '<S60>'  : 'Robot_calibration_Ipos/RobotArm/Supervisor/Supervisory Conveyor1/Supervisor'
 */
#endif                                /* RTW_HEADER_Robot_calibration_Ipos_h_ */
