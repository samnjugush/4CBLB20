/*
 * robotarm_student_2021a_Ipos.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "robotarm_student_2021a_Ipos".
 *
 * Model version              : 2.124
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 24 10:04:26 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_robotarm_student_2021a_Ipos_h_
#define RTW_HEADER_robotarm_student_2021a_Ipos_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <float.h>
#ifndef robotarm_student_2021a_Ipos_COMMON_INCLUDES_
#define robotarm_student_2021a_Ipos_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SCI.h"
#endif                        /* robotarm_student_2021a_Ipos_COMMON_INCLUDES_ */

#include "robotarm_student_2021a_Ipos_types.h"

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

/* Block states (default storage) for system '<S27>/Serial Write1' */
typedef struct {
  codertarget_raspi_internal_SC_T obj; /* '<S27>/Serial Write1' */
  boolean_T objisempty;                /* '<S27>/Serial Write1' */
} DW_SerialWrite1_robotarm_stud_T;

/* Block signals (default storage) */
typedef struct {
  char_T rtb_StringConcatenate_m[256];
  char_T HomingRunningSwitch[256];     /* '<S19>/Homing Running Switch' */
  uint8_T MatrixConcatenate1[32];      /* '<S27>/Matrix Concatenate1' */
  uint8_T MatrixConcatenate[32];       /* '<S28>/Matrix Concatenate' */
  char_T cv[31];
  boolean_T FixPtRelationalOperator[12];/* '<S11>/FixPt Relational Operator' */
  char_T ManualSwitch1[256];           /* '<S1>/Manual Switch1' */
  real_T SFunction;                    /* '<S3>/S-Function' */
  real_T ec_Ipos_o1;                   /* '<S15>/ec_Ipos' */
  real_T ec_Ipos_o2;                   /* '<S15>/ec_Ipos' */
  real_T ec_Ipos_o3;                   /* '<S15>/ec_Ipos' */
  real_T ec_Ipos_o4;                   /* '<S15>/ec_Ipos' */
  real_T ec_Ipos_o5;                   /* '<S15>/ec_Ipos' */
  real_T Gain;                         /* '<S13>/Gain' */
  real_T Constant1;                    /* '<S32>/Constant1' */
  real_T DiscreteTimeIntegrator;       /* '<S32>/Discrete-Time Integrator' */
  real_T Sum;                          /* '<S20>/Sum' */
  real_T Sum2;                         /* '<S20>/Sum2' */
  real_T Gain1;                        /* '<S13>/Gain1' */
  real_T Constant1_e;                  /* '<S38>/Constant1' */
  real_T DiscreteTimeIntegrator_e;     /* '<S38>/Discrete-Time Integrator' */
  real_T Sum_p;                        /* '<S21>/Sum' */
  real_T Sum2_a;                       /* '<S21>/Sum2' */
  real_T Gain2;                        /* '<S13>/Gain2' */
  real_T Constant1_f;                  /* '<S48>/Constant1' */
  real_T DiscreteTimeIntegrator_p;     /* '<S48>/Discrete-Time Integrator' */
  real_T Sum_o;                        /* '<S22>/Sum' */
  real_T Sum2_e;                       /* '<S22>/Sum2' */
  real_T set_robot_calibration_r;      /* '<S14>/set_robot_calibration_r' */
  real_T set_robot_calibration_x;      /* '<S14>/set_robot_calibration_x' */
  real_T set_robot_calibration_z;      /* '<S14>/set_robot_calibration_z' */
  real_T Add1;                         /* '<S18>/Add1' */
  real_T Gain3;                        /* '<S13>/Gain3' */
  real_T Gain5;                        /* '<S13>/Gain5' */
  real_T Gain_h;                       /* '<S29>/Gain' */
  real_T Dctintegrator;                /* '<S29>/Dctintegrator' */
  real_T Dctleadlag;                   /* '<S29>/Dctleadlag' */
  real_T Dct1lowpass;                  /* '<S29>/Dct1lowpass' */
  real_T Product;                      /* '<S20>/Product' */
  real_T Gain_p;                       /* '<S30>/Gain' */
  real_T Dctleadlag_l;                 /* '<S30>/Dctleadlag' */
  real_T Dct1lowpass_i;                /* '<S30>/Dct1lowpass' */
  real_T Saturation1;                  /* '<S20>/Saturation1' */
  real_T Gain1_p;                      /* '<S36>/Gain1' */
  real_T Dctintegrator_g;              /* '<S36>/Dctintegrator' */
  real_T Dctleadlag_h;                 /* '<S36>/Dctleadlag' */
  real_T Dct1lowpass_k;                /* '<S36>/Dct1lowpass' */
  real_T Product_e;                    /* '<S21>/Product' */
  real_T Gain1_o;                      /* '<S37>/Gain1' */
  real_T Dctleadlag_b;                 /* '<S37>/Dctleadlag' */
  real_T Dct1lowpass_j;                /* '<S37>/Dct1lowpass' */
  real_T Saturation1_n;                /* '<S21>/Saturation1' */
  real_T Gain_i;                       /* '<S45>/Gain' */
  real_T Dctintegrator_i;              /* '<S45>/Dctintegrator' */
  real_T Dctleadlag_m;                 /* '<S45>/Dctleadlag' */
  real_T Dct1lowpass_p;                /* '<S45>/Dct1lowpass' */
  real_T Product_n;                    /* '<S22>/Product' */
  real_T Gain_f;                       /* '<S46>/Gain' */
  real_T Dctleadlag_e;                 /* '<S46>/Dctleadlag' */
  real_T Dct1lowpass_a;                /* '<S46>/Dct1lowpass' */
  real_T Saturation1_a;                /* '<S22>/Saturation1' */
  real_T DiscreteTimeIntegrator_i;     /* '<S23>/Discrete-Time Integrator' */
  real_T Gain1_a;                      /* '<S55>/Gain1' */
  real_T Dctintegrator3;               /* '<S55>/Dctintegrator3' */
  real_T Dct1lowpass_g;                /* '<S55>/Dct1lowpass' */
  real_T Dctleadlag_k;                 /* '<S55>/Dctleadlag' */
  real_T Saturation1_d;                /* '<S23>/Saturation1' */
  real_T jogSpeed;                     /* '<S23>/Supervisor' */
  real_T homeControllerEnabled;        /* '<S23>/Supervisor' */
  real_T resetEnc;                     /* '<S23>/Supervisor' */
  real_T homingBusy;                   /* '<S23>/Supervisor' */
  real_T Ready;                        /* '<S23>/Supervisor' */
  real_T StopSim;                      /* '<S23>/Supervisor' */
  real_T jogSpeed_o;                   /* '<S22>/Supervisor' */
  real_T toPoint;                      /* '<S22>/Supervisor' */
  real_T homeControllerEnabled_m;      /* '<S22>/Supervisor' */
  real_T resetEnc_h;                   /* '<S22>/Supervisor' */
  real_T homingBusy_j;                 /* '<S22>/Supervisor' */
  real_T airBagEnabled;                /* '<S22>/Supervisor' */
  real_T airBagRef;                    /* '<S22>/Supervisor' */
  real_T controlEnabled;               /* '<S22>/Supervisor' */
  real_T Ready_m;                      /* '<S22>/Supervisor' */
  real_T StopSim_i;                    /* '<S22>/Supervisor' */
  real_T y;                            /* '<S22>/Angle2Z' */
  real_T jogSpeed_l;                   /* '<S21>/Supervisor2' */
  real_T toPoint_j;                    /* '<S21>/Supervisor2' */
  real_T homeControllerEnabled_a;      /* '<S21>/Supervisor2' */
  real_T resetEnc_d;                   /* '<S21>/Supervisor2' */
  real_T homingBusy_i;                 /* '<S21>/Supervisor2' */
  real_T airBagEnabled_o;              /* '<S21>/Supervisor2' */
  real_T airBagRef_j;                  /* '<S21>/Supervisor2' */
  real_T controlEnabled_p;             /* '<S21>/Supervisor2' */
  real_T Ready_c;                      /* '<S21>/Supervisor2' */
  real_T StopSim_g;                    /* '<S21>/Supervisor2' */
  real_T jogSpeed_o1;                  /* '<S20>/Supervisor' */
  real_T toPoint_d;                    /* '<S20>/Supervisor' */
  real_T homeControllerEnabled_c;      /* '<S20>/Supervisor' */
  real_T resetEnc_g;                   /* '<S20>/Supervisor' */
  real_T freddy_n;                     /* '<S20>/Supervisor' */
  real_T homingBusy_jt;                /* '<S20>/Supervisor' */
  real_T airBagEnabled_m;              /* '<S20>/Supervisor' */
  real_T airBagRef_n;                  /* '<S20>/Supervisor' */
  real_T controlEnabled_i;             /* '<S20>/Supervisor' */
  real_T Ready_g;                      /* '<S20>/Supervisor' */
  real_T StopSim_is;                   /* '<S20>/Supervisor' */
  real_T y_e;                          /* '<S20>/Angle2Z' */
  real_T Selector2[9];                 /* '<S4>/Selector2' */
  real_T Selector[3];                  /* '<S4>/Selector' */
  real_T Conveyorreferencemm;          /* '<S1>/Discrete  integrator' */
  real_T Gain1_g;                      /* '<S5>/Gain1' */
  real_T Dctintegrator3_n;             /* '<S5>/Dctintegrator3' */
  real_T Dct1lowpass_ab;               /* '<S5>/Dct1lowpass' */
  real_T Dctleadlag_d;                 /* '<S5>/Dctleadlag' */
  real_T SFunctionBuilder;             /* '<S4>/S-Function Builder' */
  real_T Sum_m;                        /* '<S4>/Sum' */
  real_T SignalConversion2;            /* '<S1>/Signal Conversion2' */
  real_T Sum4;                         /* '<S1>/Sum4' */
  real_T SignalConversion1;            /* '<S1>/Signal Conversion1' */
  real_T Sum5;                         /* '<S1>/Sum5' */
  real_T SignalConversion;             /* '<S1>/Signal Conversion' */
  real_T Sum6;                         /* '<S1>/Sum6' */
  real_T Gain1_o1;                     /* '<S7>/Gain1' */
  real_T Doubleclickswitch;            /* '<S1>/Manual Switch' */
  real_T Object;                       /* '<S1>/Object' */
  real_T Plot;                         /* '<S1>/Plot' */
  real_T Stop;                         /* '<S1>/Stop' */
  real_T In1;                          /* '<S12>/In1' */
  real_T d12;
  real_T fx1_tmp;
  real_T fy1_tmp;
  real_T fy2_tmp;
  real_T d12_tmp;
  real_T d13_tmp;
  real_T LimitAcceleration_h;          /* '<S32>/Limit Acceleration' */
  real_T TSamp;                        /* '<S54>/TSamp' */
  real_T TSamp_d;                      /* '<S44>/TSamp' */
  real_T TSamp_k;                      /* '<S35>/TSamp' */
  real_T LimitAcceleration;            /* '<S48>/Limit Acceleration' */
  real_T LimitAcceleration_b;          /* '<S38>/Limit Acceleration' */
  real_T Add2;                         /* '<S14>/Add2' */
  boolean_T RelationalOperator;        /* '<S20>/Relational Operator' */
  boolean_T RelationalOperator_f;      /* '<S21>/Relational Operator' */
  boolean_T RelationalOperator_k;      /* '<S22>/Relational Operator' */
  boolean_T Compare;                   /* '<S17>/Compare' */
  boolean_T Compare_j;                 /* '<S16>/Compare' */
  boolean_T LogicalOperator1;          /* '<S20>/Logical Operator1' */
  boolean_T LogicalOperator1_p;        /* '<S21>/Logical Operator1' */
  boolean_T LogicalOperator1_i;        /* '<S22>/Logical Operator1' */
} B_robotarm_student_2021a_Ipos_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S32>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S20>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S21>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_o;/* '<S38>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_a;/* '<S22>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_j;/* '<S48>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S14>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S14>/Unit Delay1' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S23>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S54>/UD' */
  real_T UD_DSTATE_c;                  /* '<S44>/UD' */
  real_T UD_DSTATE_cc;                 /* '<S35>/UD' */
  real_T DelayInput1_DSTATE[12];       /* '<S11>/Delay Input1' */
  real_T Discreteintegrator_DSTATE;    /* '<S1>/Discrete  integrator' */
  char_T Delay_DSTATE[256];            /* '<S25>/Delay' */
  real_T PrevY;                        /* '<S48>/Limit Speed' */
  real_T PrevY_j;                      /* '<S48>/Limit Acceleration' */
  real_T PrevY_d;                      /* '<S38>/Limit Speed' */
  real_T PrevY_f;                      /* '<S38>/Limit Acceleration' */
  real_T PrevY_i;                      /* '<S32>/Limit Speed' */
  real_T PrevY_k;                      /* '<S32>/Limit Acceleration' */
  real_T currentcarPos;                /* '<S22>/Supervisor' */
  real_T currentcarPos_m;              /* '<S21>/Supervisor2' */
  real_T currentcarPos_b;              /* '<S20>/Supervisor' */
  real_T Dctintegrator_RWORK[2];       /* '<S29>/Dctintegrator' */
  real_T Dctleadlag_RWORK[2];          /* '<S29>/Dctleadlag' */
  real_T Dct1lowpass_RWORK[2];         /* '<S29>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_k[2];        /* '<S30>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_a[2];       /* '<S30>/Dct1lowpass' */
  real_T Dctintegrator_RWORK_m[2];     /* '<S36>/Dctintegrator' */
  real_T Dctleadlag_RWORK_g[2];        /* '<S36>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_n[2];       /* '<S36>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_j[2];        /* '<S37>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_k[2];       /* '<S37>/Dct1lowpass' */
  real_T Dctintegrator_RWORK_i[2];     /* '<S45>/Dctintegrator' */
  real_T Dctleadlag_RWORK_n[2];        /* '<S45>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_g[2];       /* '<S45>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_i[2];        /* '<S46>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_h[2];       /* '<S46>/Dct1lowpass' */
  real_T Dctintegrator3_RWORK[2];      /* '<S55>/Dctintegrator3' */
  real_T Dct1lowpass_RWORK_ay[2];      /* '<S55>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_o[2];        /* '<S55>/Dctleadlag' */
  real_T Dctintegrator3_RWORK_g[2];    /* '<S5>/Dctintegrator3' */
  real_T Dct1lowpass_RWORK_c[2];       /* '<S5>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_gp[2];       /* '<S5>/Dctleadlag' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S22>/Scope' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<S20>/Scope9' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S33>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  int32_T sfEvent;                     /* '<S23>/Supervisor' */
  int32_T sfEvent_o;                   /* '<S22>/Supervisor' */
  int32_T sfEvent_j;                   /* '<S21>/Supervisor2' */
  int32_T sfEvent_m;                   /* '<S20>/Supervisor' */
  int32_T sfEvent_a;                   /* '<S1>/Stateflow ' */
  uint32_T is_c1_robotarm_student_2021a_Ip;/* '<S23>/Supervisor' */
  uint32_T is_c18_robotarm_student_2021a_I;/* '<S22>/Supervisor' */
  uint32_T is_c16_robotarm_student_2021a_I;/* '<S21>/Supervisor2' */
  uint32_T is_c12_robotarm_student_2021a_I;/* '<S20>/Supervisor' */
  uint32_T is_Object_Detection;        /* '<S1>/Stateflow ' */
  uint32_T is_Belt;                    /* '<S1>/Stateflow ' */
  uint32_T is_Robot_Arm;               /* '<S1>/Stateflow ' */
  uint32_T is_Vacuum;                  /* '<S1>/Stateflow ' */
  uint16_T temporalCounter_i1;         /* '<S23>/Supervisor' */
  uint16_T temporalCounter_i1_d;       /* '<S22>/Supervisor' */
  uint16_T temporalCounter_i1_di;      /* '<S21>/Supervisor2' */
  uint16_T temporalCounter_i1_b;       /* '<S20>/Supervisor' */
  int8_T Subsystem3_SubsysRanBC;       /* '<S24>/Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S26>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S26>/If Action Subsystem' */
  int8_T Controller_SubsysRanBC;       /* '<Root>/Controller' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S4>/Enabled Subsystem' */
  uint8_T is_active_c1_robotarm_student_2;/* '<S23>/Supervisor' */
  uint8_T is_active_c18_robotarm_student_;/* '<S22>/Supervisor' */
  uint8_T is_active_c16_robotarm_student_;/* '<S21>/Supervisor2' */
  uint8_T is_active_c12_robotarm_student_;/* '<S20>/Supervisor' */
  uint8_T is_active_c3_robotarm_student_2;/* '<S1>/Stateflow ' */
  uint8_T is_active_Object_Detection;  /* '<S1>/Stateflow ' */
  uint8_T is_active_Belt;              /* '<S1>/Stateflow ' */
  uint8_T is_active_Robot_Arm;         /* '<S1>/Stateflow ' */
  uint8_T is_active_Vacuum;            /* '<S1>/Stateflow ' */
  boolean_T doneDoubleBufferReInit;    /* '<S1>/Stateflow ' */
  boolean_T Controller_MODE;           /* '<Root>/Controller' */
  DW_SerialWrite1_robotarm_stud_T SerialWrite;/* '<S27>/Serial Write1' */
  DW_SerialWrite1_robotarm_stud_T SerialWrite1;/* '<S27>/Serial Write1' */
} DW_robotarm_student_2021a_Ipos_T;

/* Parameters (default storage) */
struct P_robotarm_student_2021a_Ipos_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S54>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_e;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_e
                               * Referenced by: '<S44>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_h;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_h
                               * Referenced by: '<S35>/UD'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S16>/Constant'
                                       */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S11>/Delay Input1'
                                        */
  uint8_T CompareToConstant1_const;  /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S17>/Constant'
                                      */
  real_T Delays_Y0;                    /* Computed Parameter: Delays_Y0
                                        * Referenced by: '<S12>/Delay [s]'
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
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T FeedfowardRV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward R [V]'
                                        */
  real_T ReferenceXrad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Reference X [rad]'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T FeedfowardXV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward X [V]'
                                        */
  real_T ReferenceZrad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Reference Z [rad]'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 5
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T FeedfowardZV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward Z [V]'
                                        */
  real_T Conveyorspeedmms_Value;       /* Expression: -10
                                        * Referenced by: '<S1>/Conveyor speed [mm//s]'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 100
                                        * Referenced by: '<S1>/Saturation '
                                        */
  real_T Saturation_LowerSat;          /* Expression: -100
                                        * Referenced by: '<S1>/Saturation '
                                        */
  real_T ReferenceVacuumbar_Value;     /* Expression: 0.2
                                        * Referenced by: '<S1>/Reference Vacuum [bar]'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: -100
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
                                         * Referenced by: '<S19>/Homing Running Switch2'
                                         */
  real_T HomingRunningSwitch1_Threshold;/* Expression: 2.5
                                         * Referenced by: '<S19>/Homing Running Switch1'
                                         */
  real_T HomingRunningSwitch_Threshold;/* Expression: 0.5
                                        * Referenced by: '<S20>/Homing Running Switch'
                                        */
  real_T HomingRunningSwitch_Threshold_j;/* Expression: 0.5
                                          * Referenced by: '<S21>/Homing Running Switch'
                                          */
  real_T HomingRunningSwitch_Threshold_d;/* Expression: 0.5
                                          * Referenced by: '<S22>/Homing Running Switch'
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
                                        * Referenced by: '<S15>/ec_Ipos'
                                        */
  real_T ec_Ipos_P1;                   /* Expression: link_id
                                        * Referenced by: '<S15>/ec_Ipos'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 1/16000*9/150*2*pi
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S32>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_gainva_i;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                           * Referenced by: '<S20>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S20>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value;               /* Expression: -0.05
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 1/16000*9/100*2*pi
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_h;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_h
                           * Referenced by: '<S21>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_c;  /* Expression: 0
                                        * Referenced by: '<S21>/Discrete-Time Integrator'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_j;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
                           * Referenced by: '<S38>/Discrete-Time Integrator'
                           */
  real_T Constant_Value_f;             /* Expression: -0.1
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/16000*9/100*2*pi
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_o;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
                           * Referenced by: '<S22>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_o;  /* Expression: 0
                                        * Referenced by: '<S22>/Discrete-Time Integrator'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                           * Referenced by: '<S48>/Discrete-Time Integrator'
                           */
  real_T Constant_Value_o;             /* Expression: 0.05
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S14>/Unit Delay'
                                        */
  real_T set_robot_calibration_r_Value;/* Expression: 1.2614
                                        * Referenced by: '<S14>/set_robot_calibration_r'
                                        */
  real_T set_robot_calibration_x_Value;/* Expression: 0.5842
                                        * Referenced by: '<S14>/set_robot_calibration_x'
                                        */
  real_T set_robot_calibration_z_Value;/* Expression: -0.34865
                                        * Referenced by: '<S14>/set_robot_calibration_z'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 3
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/16000*2*pi*2.05*10
                                        * Referenced by: '<S13>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/65535
                                        * Referenced by: '<S13>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S13>/Gain5'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S14>/Unit Delay1'
                                        */
  real_T HomingRunningSwitch_Threshold_l;/* Expression: 0.5
                                          * Referenced by: '<S19>/Homing Running Switch'
                                          */
  real_T ResetEncoderR_P1_Size[2];  /* Computed Parameter: ResetEncoderR_P1_Size
                                     * Referenced by: '<S20>/Reset EncoderR'
                                     */
  real_T ResetEncoderR_P1;             /* Expression: ipos_id
                                        * Referenced by: '<S20>/Reset EncoderR'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 25
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Dctintegrator_P1_Size[2];  /* Computed Parameter: Dctintegrator_P1_Size
                                     * Referenced by: '<S29>/Dctintegrator'
                                     */
  real_T Dctintegrator_P1;             /* Expression: f_num
                                        * Referenced by: '<S29>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size[2];  /* Computed Parameter: Dctintegrator_P2_Size
                                     * Referenced by: '<S29>/Dctintegrator'
                                     */
  real_T Dctintegrator_P2;             /* Expression: 0.001
                                        * Referenced by: '<S29>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_m[2];    /* Computed Parameter: Dctleadlag_P1_Size_m
                                      * Referenced by: '<S29>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_g;              /* Expression: f_num
                                        * Referenced by: '<S29>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_p[2];    /* Computed Parameter: Dctleadlag_P2_Size_p
                                      * Referenced by: '<S29>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_g;              /* Expression: f_den
                                        * Referenced by: '<S29>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_h[2];    /* Computed Parameter: Dctleadlag_P3_Size_h
                                      * Referenced by: '<S29>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_e;              /* Expression: 0.001
                                        * Referenced by: '<S29>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_m[2];  /* Computed Parameter: Dct1lowpass_P1_Size_m
                                     * Referenced by: '<S29>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_e;             /* Expression: f_den
                                        * Referenced by: '<S29>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_o[2];  /* Computed Parameter: Dct1lowpass_P2_Size_o
                                     * Referenced by: '<S29>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_a;             /* Expression: 0.001
                                        * Referenced by: '<S29>/Dct1lowpass'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 25
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Dctleadlag_P1_Size_c[2];    /* Computed Parameter: Dctleadlag_P1_Size_c
                                      * Referenced by: '<S30>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_e;              /* Expression: f_num
                                        * Referenced by: '<S30>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_k[2];    /* Computed Parameter: Dctleadlag_P2_Size_k
                                      * Referenced by: '<S30>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_b;              /* Expression: f_den
                                        * Referenced by: '<S30>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_hn[2];  /* Computed Parameter: Dctleadlag_P3_Size_hn
                                     * Referenced by: '<S30>/Dctleadlag'
                                     */
  real_T Dctleadlag_P3_g;              /* Expression: 0.001
                                        * Referenced by: '<S30>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_a[2];  /* Computed Parameter: Dct1lowpass_P1_Size_a
                                     * Referenced by: '<S30>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_g;             /* Expression: f_den
                                        * Referenced by: '<S30>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_l[2];  /* Computed Parameter: Dct1lowpass_P2_Size_l
                                     * Referenced by: '<S30>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_i;             /* Expression: 0.001
                                        * Referenced by: '<S30>/Dct1lowpass'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 32
                                        * Referenced by: '<S20>/Gain1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 127
                                        * Referenced by: '<S20>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -127
                                        * Referenced by: '<S20>/Saturation1'
                                        */
  real_T ResetEncoderR1_P1_Size[2];/* Computed Parameter: ResetEncoderR1_P1_Size
                                    * Referenced by: '<S21>/Reset EncoderR1'
                                    */
  real_T ResetEncoderR1_P1;            /* Expression: ipos_id
                                        * Referenced by: '<S21>/Reset EncoderR1'
                                        */
  real_T Gain1_Gain_ov;                /* Expression: 20
                                        * Referenced by: '<S36>/Gain1'
                                        */
  real_T Dctintegrator_P1_Size_i[2];
                                  /* Computed Parameter: Dctintegrator_P1_Size_i
                                   * Referenced by: '<S36>/Dctintegrator'
                                   */
  real_T Dctintegrator_P1_j;           /* Expression: f_num
                                        * Referenced by: '<S36>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size_p[2];
                                  /* Computed Parameter: Dctintegrator_P2_Size_p
                                   * Referenced by: '<S36>/Dctintegrator'
                                   */
  real_T Dctintegrator_P2_n;           /* Expression: 0.001
                                        * Referenced by: '<S36>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_d[2];    /* Computed Parameter: Dctleadlag_P1_Size_d
                                      * Referenced by: '<S36>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_m;              /* Expression: f_num
                                        * Referenced by: '<S36>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_g[2];    /* Computed Parameter: Dctleadlag_P2_Size_g
                                      * Referenced by: '<S36>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_p;              /* Expression: f_den
                                        * Referenced by: '<S36>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_o[2];    /* Computed Parameter: Dctleadlag_P3_Size_o
                                      * Referenced by: '<S36>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_ge;             /* Expression: 0.001
                                        * Referenced by: '<S36>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_m3[2];/* Computed Parameter: Dct1lowpass_P1_Size_m3
                                    * Referenced by: '<S36>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P1_f;             /* Expression: f_den
                                        * Referenced by: '<S36>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_b[2];  /* Computed Parameter: Dct1lowpass_P2_Size_b
                                     * Referenced by: '<S36>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_k;             /* Expression: 0.001
                                        * Referenced by: '<S36>/Dct1lowpass'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 20
                                        * Referenced by: '<S37>/Gain1'
                                        */
  real_T Dctleadlag_P1_Size_b[2];    /* Computed Parameter: Dctleadlag_P1_Size_b
                                      * Referenced by: '<S37>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_p;              /* Expression: f_num
                                        * Referenced by: '<S37>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_m[2];    /* Computed Parameter: Dctleadlag_P2_Size_m
                                      * Referenced by: '<S37>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_a;              /* Expression: f_den
                                        * Referenced by: '<S37>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_p[2];    /* Computed Parameter: Dctleadlag_P3_Size_p
                                      * Referenced by: '<S37>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_c;              /* Expression: 0.001
                                        * Referenced by: '<S37>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_n[2];  /* Computed Parameter: Dct1lowpass_P1_Size_n
                                     * Referenced by: '<S37>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_h;             /* Expression: f_den
                                        * Referenced by: '<S37>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_g[2];  /* Computed Parameter: Dct1lowpass_P2_Size_g
                                     * Referenced by: '<S37>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_b;             /* Expression: 0.001
                                        * Referenced by: '<S37>/Dct1lowpass'
                                        */
  real_T Gain_Gain_cj;                 /* Expression: 32
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Saturation1_UpperSat_e;       /* Expression: 127
                                        * Referenced by: '<S21>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_p;       /* Expression: -127
                                        * Referenced by: '<S21>/Saturation1'
                                        */
  real_T ResetEncoderR1_P1_Size_d[2];
                                 /* Computed Parameter: ResetEncoderR1_P1_Size_d
                                  * Referenced by: '<S22>/Reset EncoderR1'
                                  */
  real_T ResetEncoderR1_P1_d;          /* Expression: ipos_id
                                        * Referenced by: '<S22>/Reset EncoderR1'
                                        */
  real_T Gain_Gain_cr;                 /* Expression: 20
                                        * Referenced by: '<S45>/Gain'
                                        */
  real_T Dctintegrator_P1_Size_p[2];
                                  /* Computed Parameter: Dctintegrator_P1_Size_p
                                   * Referenced by: '<S45>/Dctintegrator'
                                   */
  real_T Dctintegrator_P1_k;           /* Expression: f_num
                                        * Referenced by: '<S45>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size_o[2];
                                  /* Computed Parameter: Dctintegrator_P2_Size_o
                                   * Referenced by: '<S45>/Dctintegrator'
                                   */
  real_T Dctintegrator_P2_m;           /* Expression: 0.001
                                        * Referenced by: '<S45>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_ch[2];  /* Computed Parameter: Dctleadlag_P1_Size_ch
                                     * Referenced by: '<S45>/Dctleadlag'
                                     */
  real_T Dctleadlag_P1_h;              /* Expression: f_num
                                        * Referenced by: '<S45>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_h[2];    /* Computed Parameter: Dctleadlag_P2_Size_h
                                      * Referenced by: '<S45>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_l;              /* Expression: f_den
                                        * Referenced by: '<S45>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_f[2];    /* Computed Parameter: Dctleadlag_P3_Size_f
                                      * Referenced by: '<S45>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_a;              /* Expression: 0.001
                                        * Referenced by: '<S45>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_ni[2];/* Computed Parameter: Dct1lowpass_P1_Size_ni
                                    * Referenced by: '<S45>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P1_j;             /* Expression: f_den
                                        * Referenced by: '<S45>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_a[2];  /* Computed Parameter: Dct1lowpass_P2_Size_a
                                     * Referenced by: '<S45>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_j;             /* Expression: 0.001
                                        * Referenced by: '<S45>/Dct1lowpass'
                                        */
  real_T Gain_Gain_ly;                 /* Expression: 30
                                        * Referenced by: '<S46>/Gain'
                                        */
  real_T Dctleadlag_P1_Size_by[2];  /* Computed Parameter: Dctleadlag_P1_Size_by
                                     * Referenced by: '<S46>/Dctleadlag'
                                     */
  real_T Dctleadlag_P1_i;              /* Expression: f_num
                                        * Referenced by: '<S46>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_j[2];    /* Computed Parameter: Dctleadlag_P2_Size_j
                                      * Referenced by: '<S46>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_o;              /* Expression: f_den
                                        * Referenced by: '<S46>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_oi[2];  /* Computed Parameter: Dctleadlag_P3_Size_oi
                                     * Referenced by: '<S46>/Dctleadlag'
                                     */
  real_T Dctleadlag_P3_aa;             /* Expression: 0.001
                                        * Referenced by: '<S46>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_p[2];  /* Computed Parameter: Dct1lowpass_P1_Size_p
                                     * Referenced by: '<S46>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_j3;            /* Expression: f_den
                                        * Referenced by: '<S46>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_j[2];  /* Computed Parameter: Dct1lowpass_P2_Size_j
                                     * Referenced by: '<S46>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_c;             /* Expression: 0.001
                                        * Referenced by: '<S46>/Dct1lowpass'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 32
                                        * Referenced by: '<S22>/Gain'
                                        */
  real_T Saturation1_UpperSat_i;       /* Expression: 127
                                        * Referenced by: '<S22>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -127
                                        * Referenced by: '<S22>/Saturation1'
                                        */
  real_T ResetEncoderR1_P1_Size_b[2];
                                 /* Computed Parameter: ResetEncoderR1_P1_Size_b
                                  * Referenced by: '<S23>/Reset EncoderR1'
                                  */
  real_T ResetEncoderR1_P1_l;          /* Expression: ipos_id
                                        * Referenced by: '<S23>/Reset EncoderR1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_g;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                           * Referenced by: '<S23>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_co; /* Expression: 0
                                        * Referenced by: '<S23>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 10*2.5/500
                                        * Referenced by: '<S55>/Gain1'
                                        */
  real_T Dctintegrator3_P1_Size_m[2];
                                 /* Computed Parameter: Dctintegrator3_P1_Size_m
                                  * Referenced by: '<S55>/Dctintegrator3'
                                  */
  real_T Dctintegrator3_P1_j;          /* Expression: f_num
                                        * Referenced by: '<S55>/Dctintegrator3'
                                        */
  real_T Dctintegrator3_P2_Size_b[2];
                                 /* Computed Parameter: Dctintegrator3_P2_Size_b
                                  * Referenced by: '<S55>/Dctintegrator3'
                                  */
  real_T Dctintegrator3_P2_j;          /* Expression: 0.001
                                        * Referenced by: '<S55>/Dctintegrator3'
                                        */
  real_T Dct1lowpass_P1_Size_j[2];  /* Computed Parameter: Dct1lowpass_P1_Size_j
                                     * Referenced by: '<S55>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_ez;            /* Expression: f_den
                                        * Referenced by: '<S55>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_aj[2];/* Computed Parameter: Dct1lowpass_P2_Size_aj
                                    * Referenced by: '<S55>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P2_n;             /* Expression: 0.001
                                        * Referenced by: '<S55>/Dct1lowpass'
                                        */
  real_T Dctleadlag_P1_Size_l[2];    /* Computed Parameter: Dctleadlag_P1_Size_l
                                      * Referenced by: '<S55>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_m0;             /* Expression: f_num
                                        * Referenced by: '<S55>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_n[2];    /* Computed Parameter: Dctleadlag_P2_Size_n
                                      * Referenced by: '<S55>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_f;              /* Expression: f_den
                                        * Referenced by: '<S55>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_d[2];    /* Computed Parameter: Dctleadlag_P3_Size_d
                                      * Referenced by: '<S55>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_i;              /* Expression: 0.001
                                        * Referenced by: '<S55>/Dctleadlag'
                                        */
  real_T HomingRunningSwitch_Threshol_lq;/* Expression: 0.5
                                          * Referenced by: '<S23>/Homing Running Switch'
                                          */
  real_T Gain_Gain_j;                  /* Expression: 32
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 127
                                        * Referenced by: '<S23>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_g;       /* Expression: -127
                                        * Referenced by: '<S23>/Saturation1'
                                        */
  real_T LimitSpeed_RisingLim;         /* Expression: 0.2
                                        * Referenced by: '<S48>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim;        /* Expression: -0.2
                                        * Referenced by: '<S48>/Limit Speed'
                                        */
  real_T LimitSpeed_IC;                /* Expression: 0
                                        * Referenced by: '<S48>/Limit Speed'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S54>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim;  /* Expression: 0.5
                                        * Referenced by: '<S48>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim; /* Expression: -0.5
                                        * Referenced by: '<S48>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_IC;         /* Expression: 0
                                        * Referenced by: '<S48>/Limit Acceleration'
                                        */
  real_T LimitSpeed_RisingLim_i;       /* Expression: 0.4
                                        * Referenced by: '<S38>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim_k;      /* Expression: -0.4
                                        * Referenced by: '<S38>/Limit Speed'
                                        */
  real_T LimitSpeed_IC_a;              /* Expression: 0
                                        * Referenced by: '<S38>/Limit Speed'
                                        */
  real_T TSamp_WtEt_d;                 /* Computed Parameter: TSamp_WtEt_d
                                        * Referenced by: '<S44>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim_k;/* Expression: 0.5
                                        * Referenced by: '<S38>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim_m;/* Expression: -0.5
                                         * Referenced by: '<S38>/Limit Acceleration'
                                         */
  real_T LimitAcceleration_IC_k;       /* Expression: 0
                                        * Referenced by: '<S38>/Limit Acceleration'
                                        */
  real_T LimitSpeed_RisingLim_iu;      /* Expression: 0.6
                                        * Referenced by: '<S32>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim_j;      /* Expression: -0.6
                                        * Referenced by: '<S32>/Limit Speed'
                                        */
  real_T LimitSpeed_IC_e;              /* Expression: 0
                                        * Referenced by: '<S32>/Limit Speed'
                                        */
  real_T TSamp_WtEt_g;                 /* Computed Parameter: TSamp_WtEt_g
                                        * Referenced by: '<S35>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim_m;/* Expression: 0.8
                                        * Referenced by: '<S32>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim_k;/* Expression: -0.8
                                         * Referenced by: '<S32>/Limit Acceleration'
                                         */
  real_T LimitAcceleration_IC_i;       /* Expression: 0
                                        * Referenced by: '<S32>/Limit Acceleration'
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
                                    * Referenced by: '<S28>/String Constant3'
                                    */
  char_T StringConstant1_String[256];
                                   /* Computed Parameter: StringConstant1_String
                                    * Referenced by: '<S28>/String Constant1'
                                    */
  char_T StringConstant4_String[256];
                                   /* Computed Parameter: StringConstant4_String
                                    * Referenced by: '<S26>/String Constant4'
                                    */
  char_T ReadyGreen_String[256];       /* Computed Parameter: ReadyGreen_String
                                        * Referenced by: '<S14>/Ready Green'
                                        */
  char_T AirbagRed_String[256];        /* Computed Parameter: AirbagRed_String
                                        * Referenced by: '<S14>/Airbag Red'
                                        */
  char_T HomingOrange_String[256];    /* Computed Parameter: HomingOrange_String
                                       * Referenced by: '<S14>/Homing Orange'
                                       */
  char_T Delay_InitialCondition[256];
                                   /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S25>/Delay'
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
                                        * Referenced by: '<S27>/Constant1'
                                        */
  uint8_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S28>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_robotarm_student_2021a_Ipos_T {
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
extern P_robotarm_student_2021a_Ipos_T robotarm_student_2021a_Ipos_P;

/* Block signals (default storage) */
extern B_robotarm_student_2021a_Ipos_T robotarm_student_2021a_Ipos_B;

/* Block states (default storage) */
extern DW_robotarm_student_2021a_Ipos_T robotarm_student_2021a_Ipos_DW;

/* Model entry point functions */
extern void robotarm_student_2021a_Ipos_initialize(void);
extern void robotarm_student_2021a_Ipos_step(void);
extern void robotarm_student_2021a_Ipos_terminate(void);

/* Real-time Model object */
extern RT_MODEL_robotarm_student_2021a_Ipos_T *const
  robotarm_student_2021a_Ipos_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Saturation' : Unused code path elimination
 * Block '<S35>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'robotarm_student_2021a_Ipos'
 * '<S1>'   : 'robotarm_student_2021a_Ipos/Controller'
 * '<S2>'   : 'robotarm_student_2021a_Ipos/RobotArm'
 * '<S3>'   : 'robotarm_student_2021a_Ipos/Supervisor2'
 * '<S4>'   : 'robotarm_student_2021a_Ipos/Controller/Camera'
 * '<S5>'   : 'robotarm_student_2021a_Ipos/Controller/Controller Conveyor'
 * '<S6>'   : 'robotarm_student_2021a_Ipos/Controller/Controller R'
 * '<S7>'   : 'robotarm_student_2021a_Ipos/Controller/Controller Vacuum'
 * '<S8>'   : 'robotarm_student_2021a_Ipos/Controller/Controller X'
 * '<S9>'   : 'robotarm_student_2021a_Ipos/Controller/Controller Z'
 * '<S10>'  : 'robotarm_student_2021a_Ipos/Controller/Stateflow '
 * '<S11>'  : 'robotarm_student_2021a_Ipos/Controller/Camera/Detect Change'
 * '<S12>'  : 'robotarm_student_2021a_Ipos/Controller/Camera/Enabled Subsystem'
 * '<S13>'  : 'robotarm_student_2021a_Ipos/RobotArm/Subsystem'
 * '<S14>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor'
 * '<S15>'  : 'robotarm_student_2021a_Ipos/RobotArm/Subsystem/Ipos'
 * '<S16>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Compare To Constant'
 * '<S17>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Compare To Constant1'
 * '<S18>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/HomingBusyCheck'
 * '<S19>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Subsystem'
 * '<S20>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller R'
 * '<S21>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X'
 * '<S22>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z'
 * '<S23>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Conveyor1'
 * '<S24>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Subsystem/LED Ring'
 * '<S25>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem'
 * '<S26>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3'
 * '<S27>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3/If Action Subsystem'
 * '<S28>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3/If Action Subsystem1'
 * '<S29>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller R/ '
 * '<S30>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller R/   '
 * '<S31>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller R/Angle2Z'
 * '<S32>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory'
 * '<S33>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller R/Selector1'
 * '<S34>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller R/Supervisor'
 * '<S35>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory/Discrete Derivative'
 * '<S36>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X/Controller X1'
 * '<S37>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X/Controller X2'
 * '<S38>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory'
 * '<S39>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector'
 * '<S40>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector1'
 * '<S41>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector2'
 * '<S42>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X/Selector3'
 * '<S43>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X/Supervisor2'
 * '<S44>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory/Discrete Derivative'
 * '<S45>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/    '
 * '<S46>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/     '
 * '<S47>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Angle2Z'
 * '<S48>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory'
 * '<S49>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector'
 * '<S50>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector1'
 * '<S51>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector2'
 * '<S52>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Selector3'
 * '<S53>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Supervisor'
 * '<S54>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory/Discrete Derivative'
 * '<S55>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Conveyor1/Controller Conveyor'
 * '<S56>'  : 'robotarm_student_2021a_Ipos/RobotArm/Supervisor/Supervisory Conveyor1/Supervisor'
 */
#endif                           /* RTW_HEADER_robotarm_student_2021a_Ipos_h_ */
