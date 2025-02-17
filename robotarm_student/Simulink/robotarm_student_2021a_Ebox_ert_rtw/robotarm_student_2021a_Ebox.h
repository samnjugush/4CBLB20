/*
 * robotarm_student_2021a_Ebox.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "robotarm_student_2021a_Ebox".
 *
 * Model version              : 2.2
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Fri Jan 24 13:11:34 2025
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_robotarm_student_2021a_Ebox_h_
#define RTW_HEADER_robotarm_student_2021a_Ebox_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <float.h>
#ifndef robotarm_student_2021a_Ebox_COMMON_INCLUDES_
#define robotarm_student_2021a_Ebox_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_SCI.h"
#endif                        /* robotarm_student_2021a_Ebox_COMMON_INCLUDES_ */

#include "robotarm_student_2021a_Ebox_types.h"

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

/* Block states (default storage) for system '<S28>/Serial Write1' */
typedef struct {
  codertarget_raspi_internal_SC_T obj; /* '<S28>/Serial Write1' */
  boolean_T objisempty;                /* '<S28>/Serial Write1' */
} DW_SerialWrite1_robotarm_stud_T;

/* Block signals (default storage) */
typedef struct {
  char_T rtb_StringConcatenate_m[256];
  char_T HomingRunningSwitch_c[256];   /* '<S20>/Homing Running Switch' */
  uint8_T MatrixConcatenate1[32];      /* '<S28>/Matrix Concatenate1' */
  uint8_T MatrixConcatenate[32];       /* '<S29>/Matrix Concatenate' */
  char_T cv[31];
  real_T ec_Ebox_o2[2];                /* '<S14>/ec_Ebox' */
  real_T ec_Ebox_o3[8];                /* '<S14>/ec_Ebox' */
  real_T ec_Ebox_o1_h[2];              /* '<S15>/ec_Ebox' */
  real_T ec_Ebox_o2_o[2];              /* '<S15>/ec_Ebox' */
  real_T ec_Ebox_o3_p[8];              /* '<S15>/ec_Ebox' */
  real_T ec_Ebox_o1_o[2];              /* '<S16>/ec_Ebox' */
  real_T ec_Ebox_o2_p[2];              /* '<S16>/ec_Ebox' */
  real_T ec_Ebox_o3_j[8];              /* '<S16>/ec_Ebox' */
  real_T HomingRunningSwitch[3];       /* '<S12>/Homing Running Switch' */
  boolean_T FixPtRelationalOperator[12];/* '<S10>/FixPt Relational Operator' */
  char_T ManualSwitch1[256];           /* '<S1>/Manual Switch1' */
  real_T SFunction;                    /* '<S17>/S-Function' */
  real_T ec_Ebox_o1[2];                /* '<S14>/ec_Ebox' */
  real_T Gain3;                        /* '<S12>/Gain3' */
  real_T Gain6;                        /* '<S12>/Gain6' */
  real_T Constant1;                    /* '<S33>/Constant1' */
  real_T Sum;                          /* '<S21>/Sum' */
  real_T set_robot_calibration_r;      /* '<S13>/set_robot_calibration_r' */
  real_T Constant1_c;                  /* '<S39>/Constant1' */
  real_T Sum_a;                        /* '<S22>/Sum' */
  real_T set_robot_calibration_x;      /* '<S13>/set_robot_calibration_x' */
  real_T Constant1_k;                  /* '<S49>/Constant1' */
  real_T Sum_g;                        /* '<S23>/Sum' */
  real_T set_robot_calibration_z;      /* '<S13>/set_robot_calibration_z' */
  real_T Add1;                         /* '<S19>/Add1' */
  real_T Assignment[8];                /* '<S12>/Assignment' */
  real_T Gain[2];                      /* '<S14>/Gain' */
  real_T Gain_c;                       /* '<S30>/Gain' */
  real_T Dctintegrator;                /* '<S30>/Dctintegrator' */
  real_T Dctleadlag;                   /* '<S30>/Dctleadlag' */
  real_T Dct1lowpass;                  /* '<S30>/Dct1lowpass' */
  real_T Saturation;                   /* '<S21>/Saturation' */
  real_T Gain_f;                       /* '<S31>/Gain' */
  real_T Dctleadlag_j;                 /* '<S31>/Dctleadlag' */
  real_T Dct1lowpass_n;                /* '<S31>/Dct1lowpass' */
  real_T Gain1;                        /* '<S37>/Gain1' */
  real_T Dctintegrator_i;              /* '<S37>/Dctintegrator' */
  real_T Dctleadlag_n;                 /* '<S37>/Dctleadlag' */
  real_T Dct1lowpass_f;                /* '<S37>/Dct1lowpass' */
  real_T Product;                      /* '<S22>/Product' */
  real_T Gain1_p;                      /* '<S38>/Gain1' */
  real_T Dctleadlag_e;                 /* '<S38>/Dctleadlag' */
  real_T Dct1lowpass_o;                /* '<S38>/Dct1lowpass' */
  real_T Saturation_p[2];              /* '<S14>/Saturation' */
  real_T Gain_j[2];                    /* '<S15>/Gain' */
  real_T Gain_e;                       /* '<S46>/Gain' */
  real_T Dctintegrator_g;              /* '<S46>/Dctintegrator' */
  real_T Dctleadlag_eg;                /* '<S46>/Dctleadlag' */
  real_T Dct1lowpass_ft;               /* '<S46>/Dct1lowpass' */
  real_T Product_b;                    /* '<S23>/Product' */
  real_T Gain_i;                       /* '<S47>/Gain' */
  real_T Dctleadlag_i;                 /* '<S47>/Dctleadlag' */
  real_T Dct1lowpass_a;                /* '<S47>/Dct1lowpass' */
  real_T DiscreteTimeIntegrator;       /* '<S24>/Discrete-Time Integrator' */
  real_T Gain1_n;                      /* '<S56>/Gain1' */
  real_T Dctintegrator3;               /* '<S56>/Dctintegrator3' */
  real_T Dct1lowpass_p;                /* '<S56>/Dct1lowpass' */
  real_T Dctleadlag_f;                 /* '<S56>/Dctleadlag' */
  real_T Sum1;                         /* '<S12>/Sum1' */
  real_T Saturation_f[2];              /* '<S15>/Saturation' */
  real_T Gain_n[2];                    /* '<S16>/Gain' */
  real_T Saturation_h[2];              /* '<S16>/Saturation' */
  real_T jogSpeed;                     /* '<S24>/Supervisor' */
  real_T homeControllerEnabled;        /* '<S24>/Supervisor' */
  real_T resetEnc;                     /* '<S24>/Supervisor' */
  real_T homingBusy;                   /* '<S24>/Supervisor' */
  real_T Ready;                        /* '<S24>/Supervisor' */
  real_T StopSim;                      /* '<S24>/Supervisor' */
  real_T jogSpeed_f;                   /* '<S23>/Supervisor' */
  real_T toPoint;                      /* '<S23>/Supervisor' */
  real_T homeControllerEnabled_j;      /* '<S23>/Supervisor' */
  real_T resetEnc_j;                   /* '<S23>/Supervisor' */
  real_T homingBusy_j;                 /* '<S23>/Supervisor' */
  real_T airBagEnabled;                /* '<S23>/Supervisor' */
  real_T airBagRef;                    /* '<S23>/Supervisor' */
  real_T controlEnabled;               /* '<S23>/Supervisor' */
  real_T Ready_c;                      /* '<S23>/Supervisor' */
  real_T StopSim_n;                    /* '<S23>/Supervisor' */
  real_T y;                            /* '<S23>/Angle2Z' */
  real_T jogSpeed_o;                   /* '<S22>/Supervisor' */
  real_T toPoint_h;                    /* '<S22>/Supervisor' */
  real_T homeControllerEnabled_f;      /* '<S22>/Supervisor' */
  real_T resetEnc_n;                   /* '<S22>/Supervisor' */
  real_T homingBusy_d;                 /* '<S22>/Supervisor' */
  real_T airBagEnabled_a;              /* '<S22>/Supervisor' */
  real_T airBagRef_p;                  /* '<S22>/Supervisor' */
  real_T controlEnabled_b;             /* '<S22>/Supervisor' */
  real_T Ready_l;                      /* '<S22>/Supervisor' */
  real_T StopSim_p;                    /* '<S22>/Supervisor' */
  real_T jogSpeed_p;                   /* '<S21>/Supervisor' */
  real_T toPoint_i;                    /* '<S21>/Supervisor' */
  real_T homeControllerEnabled_i;      /* '<S21>/Supervisor' */
  real_T resetEnc_l;                   /* '<S21>/Supervisor' */
  real_T homingBusy_n;                 /* '<S21>/Supervisor' */
  real_T airBagEnabled_ab;             /* '<S21>/Supervisor' */
  real_T airBagRef_pn;                 /* '<S21>/Supervisor' */
  real_T controlEnabled_e;             /* '<S21>/Supervisor' */
  real_T Ready_n;                      /* '<S21>/Supervisor' */
  real_T StopSim_np;                   /* '<S21>/Supervisor' */
  real_T y_j;                          /* '<S21>/Angle2Z' */
  real_T Selector2[9];                 /* '<S3>/Selector2' */
  real_T Selector[3];                  /* '<S3>/Selector' */
  real_T Conveyorreferencemm;          /* '<S1>/Discrete  integrator' */
  real_T Gain1_g;                      /* '<S4>/Gain1' */
  real_T Dctintegrator3_n;             /* '<S4>/Dctintegrator3' */
  real_T Dct1lowpass_ab;               /* '<S4>/Dct1lowpass' */
  real_T Dctleadlag_d;                 /* '<S4>/Dctleadlag' */
  real_T SFunctionBuilder;             /* '<S3>/S-Function Builder' */
  real_T Sum_m;                        /* '<S3>/Sum' */
  real_T SignalConversion2;            /* '<S1>/Signal Conversion2' */
  real_T Sum4;                         /* '<S1>/Sum4' */
  real_T SignalConversion1;            /* '<S1>/Signal Conversion1' */
  real_T Sum5;                         /* '<S1>/Sum5' */
  real_T SignalConversion;             /* '<S1>/Signal Conversion' */
  real_T Sum6;                         /* '<S1>/Sum6' */
  real_T Gain1_o;                      /* '<S6>/Gain1' */
  real_T Doubleclickswitch;            /* '<S1>/Manual Switch' */
  real_T Object;                       /* '<S1>/Object' */
  real_T Plot;                         /* '<S1>/Plot' */
  real_T Stop;                         /* '<S1>/Stop' */
  real_T In1;                          /* '<S11>/In1' */
  real_T d12;
  real_T Sum3_f;                       /* '<S12>/Sum3' */
  real_T Sum4_k;                       /* '<S12>/Sum4' */
  real_T HomingRunningSwitch1_l;       /* '<S12>/Homing Running Switch1' */
  real_T fx1_tmp;
  real_T fy2_tmp;
  real_T d12_tmp;
  real_T d13_tmp;
  real_T d13_tmp_c;
  real_T LimitAcceleration_b;          /* '<S49>/Limit Acceleration' */
  real_T TSamp;                        /* '<S36>/TSamp' */
  real_T TSamp_m;                      /* '<S45>/TSamp' */
  real_T TSamp_j;                      /* '<S55>/TSamp' */
  real_T LimitAcceleration;            /* '<S33>/Limit Acceleration' */
  real_T LimitAcceleration_c;          /* '<S39>/Limit Acceleration' */
  real_T Add;                          /* '<S13>/Add' */
  boolean_T RelationalOperator;        /* '<S21>/Relational Operator' */
  boolean_T Compare;                   /* '<S18>/Compare' */
  boolean_T RelationalOperator_o;      /* '<S22>/Relational Operator' */
  boolean_T RelationalOperator_n;      /* '<S23>/Relational Operator' */
  boolean_T LogicalOperator1;          /* '<S21>/Logical Operator1' */
  boolean_T LogicalOperator1_d;        /* '<S22>/Logical Operator1' */
  boolean_T LogicalOperator1_o;        /* '<S23>/Logical Operator1' */
} B_robotarm_student_2021a_Ebox_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S21>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S33>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S13>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S22>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTAT_pn;/* '<S39>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_c;/* '<S23>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_i;/* '<S49>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S24>/Discrete-Time Integrator' */
  real_T UnitDelay1_DSTATE;            /* '<S13>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S36>/UD' */
  real_T UD_DSTATE_n;                  /* '<S45>/UD' */
  real_T UD_DSTATE_e;                  /* '<S55>/UD' */
  real_T DelayInput1_DSTATE[12];       /* '<S10>/Delay Input1' */
  real_T Discreteintegrator_DSTATE;    /* '<S1>/Discrete  integrator' */
  char_T Delay_DSTATE[256];            /* '<S26>/Delay' */
  real_T PrevY;                        /* '<S33>/Limit Speed' */
  real_T PrevY_n;                      /* '<S33>/Limit Acceleration' */
  real_T PrevY_h;                      /* '<S39>/Limit Speed' */
  real_T PrevY_m;                      /* '<S39>/Limit Acceleration' */
  real_T PrevY_c;                      /* '<S49>/Limit Speed' */
  real_T PrevY_mz;                     /* '<S49>/Limit Acceleration' */
  real_T currentcarPos;                /* '<S23>/Supervisor' */
  real_T currentcarPos_f;              /* '<S22>/Supervisor' */
  real_T currentcarPos_k;              /* '<S21>/Supervisor' */
  real_T Dctintegrator_RWORK[2];       /* '<S30>/Dctintegrator' */
  real_T Dctleadlag_RWORK[2];          /* '<S30>/Dctleadlag' */
  real_T Dct1lowpass_RWORK[2];         /* '<S30>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_b[2];        /* '<S31>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_g[2];       /* '<S31>/Dct1lowpass' */
  real_T Dctintegrator_RWORK_b[2];     /* '<S37>/Dctintegrator' */
  real_T Dctleadlag_RWORK_a[2];        /* '<S37>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_m[2];       /* '<S37>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_f[2];        /* '<S38>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_k[2];       /* '<S38>/Dct1lowpass' */
  real_T Dctintegrator_RWORK_m[2];     /* '<S46>/Dctintegrator' */
  real_T Dctleadlag_RWORK_p[2];        /* '<S46>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_p[2];       /* '<S46>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_o[2];        /* '<S47>/Dctleadlag' */
  real_T Dct1lowpass_RWORK_gb[2];      /* '<S47>/Dct1lowpass' */
  real_T Dctintegrator3_RWORK[2];      /* '<S56>/Dctintegrator3' */
  real_T Dct1lowpass_RWORK_n[2];       /* '<S56>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_l[2];        /* '<S56>/Dctleadlag' */
  real_T Dctintegrator3_RWORK_g[2];    /* '<S4>/Dctintegrator3' */
  real_T Dct1lowpass_RWORK_c[2];       /* '<S4>/Dct1lowpass' */
  real_T Dctleadlag_RWORK_g[2];        /* '<S4>/Dctleadlag' */
  int32_T sfEvent;                     /* '<S24>/Supervisor' */
  int32_T sfEvent_j;                   /* '<S23>/Supervisor' */
  int32_T sfEvent_jk;                  /* '<S22>/Supervisor' */
  int32_T sfEvent_f;                   /* '<S21>/Supervisor' */
  int32_T sfEvent_b;                   /* '<S1>/Stateflow ' */
  uint32_T is_c4_robotarm_student_2021a_Eb;/* '<S24>/Supervisor' */
  uint32_T is_c7_robotarm_student_2021a_Eb;/* '<S23>/Supervisor' */
  uint32_T is_c6_robotarm_student_2021a_Eb;/* '<S22>/Supervisor' */
  uint32_T is_c5_robotarm_student_2021a_Eb;/* '<S21>/Supervisor' */
  uint32_T is_Object_Detection;        /* '<S1>/Stateflow ' */
  uint32_T is_Belt;                    /* '<S1>/Stateflow ' */
  uint32_T is_Robot_Arm;               /* '<S1>/Stateflow ' */
  uint32_T is_Vacuum;                  /* '<S1>/Stateflow ' */
  uint16_T temporalCounter_i1;         /* '<S24>/Supervisor' */
  uint16_T temporalCounter_i1_k;       /* '<S23>/Supervisor' */
  uint16_T temporalCounter_i1_a;       /* '<S22>/Supervisor' */
  uint16_T temporalCounter_i1_p;       /* '<S21>/Supervisor' */
  int8_T Subsystem3_SubsysRanBC;       /* '<S25>/Subsystem3' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S27>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S27>/If Action Subsystem' */
  int8_T Controller_SubsysRanBC;       /* '<Root>/Controller' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S3>/Enabled Subsystem' */
  uint8_T is_active_c4_robotarm_student_2;/* '<S24>/Supervisor' */
  uint8_T is_active_c7_robotarm_student_2;/* '<S23>/Supervisor' */
  uint8_T is_active_c6_robotarm_student_2;/* '<S22>/Supervisor' */
  uint8_T is_active_c5_robotarm_student_2;/* '<S21>/Supervisor' */
  uint8_T is_active_c3_robotarm_student_2;/* '<S1>/Stateflow ' */
  uint8_T is_active_Object_Detection;  /* '<S1>/Stateflow ' */
  uint8_T is_active_Belt;              /* '<S1>/Stateflow ' */
  uint8_T is_active_Robot_Arm;         /* '<S1>/Stateflow ' */
  uint8_T is_active_Vacuum;            /* '<S1>/Stateflow ' */
  boolean_T doneDoubleBufferReInit;    /* '<S1>/Stateflow ' */
  boolean_T Controller_MODE;           /* '<Root>/Controller' */
  DW_SerialWrite1_robotarm_stud_T SerialWrite;/* '<S28>/Serial Write1' */
  DW_SerialWrite1_robotarm_stud_T SerialWrite1;/* '<S28>/Serial Write1' */
} DW_robotarm_student_2021a_Ebox_T;

/* Parameters (default storage) */
struct P_robotarm_student_2021a_Ebox_T_ {
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S36>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_p;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_p
                               * Referenced by: '<S45>/UD'
                               */
  real_T DiscreteDerivative_ICPrevScal_i;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScal_i
                               * Referenced by: '<S55>/UD'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S18>/Constant'
                                       */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S10>/Delay Input1'
                                        */
  real_T Delays_Y0;                    /* Computed Parameter: Delays_Y0
                                        * Referenced by: '<S11>/Delay [s]'
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
                               /* Expression: [0  0  0  0;0  0  0  0;0  0  0  0]
                                * Referenced by: '<S3>/Object detection matrix'
                                */
  real_T Discreteintegrator_gainval;
                               /* Computed Parameter: Discreteintegrator_gainval
                                * Referenced by: '<S1>/Discrete  integrator'
                                */
  real_T Discreteintegrator_IC;        /* Expression: 0
                                        * Referenced by: '<S1>/Discrete  integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: 10*2.5/500
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Dctintegrator3_P1_Size[2];/* Computed Parameter: Dctintegrator3_P1_Size
                                    * Referenced by: '<S4>/Dctintegrator3'
                                    */
  real_T Dctintegrator3_P1;            /* Expression: f_num
                                        * Referenced by: '<S4>/Dctintegrator3'
                                        */
  real_T Dctintegrator3_P2_Size[2];/* Computed Parameter: Dctintegrator3_P2_Size
                                    * Referenced by: '<S4>/Dctintegrator3'
                                    */
  real_T Dctintegrator3_P2;            /* Expression: 0.001
                                        * Referenced by: '<S4>/Dctintegrator3'
                                        */
  real_T Dct1lowpass_P1_Size[2];      /* Computed Parameter: Dct1lowpass_P1_Size
                                       * Referenced by: '<S4>/Dct1lowpass'
                                       */
  real_T Dct1lowpass_P1;               /* Expression: f_den
                                        * Referenced by: '<S4>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size[2];      /* Computed Parameter: Dct1lowpass_P2_Size
                                       * Referenced by: '<S4>/Dct1lowpass'
                                       */
  real_T Dct1lowpass_P2;               /* Expression: 0.001
                                        * Referenced by: '<S4>/Dct1lowpass'
                                        */
  real_T Dctleadlag_P1_Size[2];        /* Computed Parameter: Dctleadlag_P1_Size
                                        * Referenced by: '<S4>/Dctleadlag'
                                        */
  real_T Dctleadlag_P1;                /* Expression: f_num
                                        * Referenced by: '<S4>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size[2];        /* Computed Parameter: Dctleadlag_P2_Size
                                        * Referenced by: '<S4>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2;                /* Expression: f_den
                                        * Referenced by: '<S4>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size[2];        /* Computed Parameter: Dctleadlag_P3_Size
                                        * Referenced by: '<S4>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3;                /* Expression: 0.001
                                        * Referenced by: '<S4>/Dctleadlag'
                                        */
  real_T ReferenceRrad_Value;          /* Expression: 1
                                        * Referenced by: '<S1>/Reference R [rad]'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T FeedfowardRV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward R [V]'
                                        */
  real_T ReferenceXrad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Reference X [rad]'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T FeedfowardXV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward X [V]'
                                        */
  real_T ReferenceZrad_Value;          /* Expression: 0
                                        * Referenced by: '<S1>/Reference Z [rad]'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T FeedfowardZV_Value;           /* Expression: 0
                                        * Referenced by: '<S1>/Feedfoward Z [V]'
                                        */
  real_T Conveyorspeedmms_Value;       /* Expression: -30
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
  real_T Gain1_Gain_b;                 /* Expression: -10
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Object_Value;                 /* Expression: 2
                                        * Referenced by: '<S1>/Object'
                                        */
  real_T Plot_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Plot'
                                        */
  real_T Stop_Value;                   /* Expression: 0
                                        * Referenced by: '<S1>/Stop'
                                        */
  real_T Gain5_Gain;                   /* Expression: 0.25
                                        * Referenced by: '<S12>/Gain5'
                                        */
  real_T HomingRunningSwitch2_Threshold;/* Expression: 50
                                         * Referenced by: '<S20>/Homing Running Switch2'
                                         */
  real_T HomingRunningSwitch1_Threshold;/* Expression: 2.5
                                         * Referenced by: '<S20>/Homing Running Switch1'
                                         */
  real_T HomingRunningSwitch_Threshold;/* Expression: 0.5
                                        * Referenced by: '<S21>/Homing Running Switch'
                                        */
  real_T HomingRunningSwitch_Threshold_o;/* Expression: 0.5
                                          * Referenced by: '<S22>/Homing Running Switch'
                                          */
  real_T HomingRunningSwitch_Threshold_j;/* Expression: 0.5
                                          * Referenced by: '<S23>/Homing Running Switch'
                                          */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S17>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: portid
                                        * Referenced by: '<S17>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S17>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: ectimeout
                                        * Referenced by: '<S17>/S-Function'
                                        */
  real_T ec_Ebox_P1_Size[2];           /* Computed Parameter: ec_Ebox_P1_Size
                                        * Referenced by: '<S14>/ec_Ebox'
                                        */
  real_T ec_Ebox_P1;                   /* Expression: link_id
                                        * Referenced by: '<S14>/ec_Ebox'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 1/4000*9/150*2*pi
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: -1/4000*9/100*2*pi
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T ec_Ebox_P1_Size_d[2];         /* Computed Parameter: ec_Ebox_P1_Size_d
                                        * Referenced by: '<S15>/ec_Ebox'
                                        */
  real_T ec_Ebox_P1_e;                 /* Expression: link_id
                                        * Referenced by: '<S15>/ec_Ebox'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/4000*9/100*2*pi
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real_T ec_Ebox_P1_Size_du[2];        /* Computed Parameter: ec_Ebox_P1_Size_du
                                        * Referenced by: '<S16>/ec_Ebox'
                                        */
  real_T ec_Ebox_P1_i;                 /* Expression: link_id
                                        * Referenced by: '<S16>/ec_Ebox'
                                        */
  real_T HomingRunningSwitch_Threshold_d;/* Expression: 2
                                          * Referenced by: '<S12>/Homing Running Switch'
                                          */
  real_T Gain3_Gain;                   /* Expression: -1/16000*2*pi*2.07*10
                                        * Referenced by: '<S12>/Gain3'
                                        */
  real_T Gain6_Gain;                   /* Expression: -0.1
                                        * Referenced by: '<S12>/Gain6'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S21>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S21>/Discrete-Time Integrator'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                           * Referenced by: '<S33>/Discrete-Time Integrator'
                           */
  real_T Constant_Value_g;             /* Expression: -0.1
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S13>/Unit Delay'
                                        */
  real_T set_robot_calibration_r_Value;/* Expression: 1.2844
                                        * Referenced by: '<S13>/set_robot_calibration_r'
                                        */
  real_T DiscreteTimeIntegrator_gainva_a;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                           * Referenced by: '<S22>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_i;  /* Expression: 0
                                        * Referenced by: '<S22>/Discrete-Time Integrator'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_i;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                           * Referenced by: '<S39>/Discrete-Time Integrator'
                           */
  real_T Constant_Value_n;             /* Expression: -0.1
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T set_robot_calibration_x_Value;/* Expression: 0.6434
                                        * Referenced by: '<S13>/set_robot_calibration_x'
                                        */
  real_T DiscreteTimeIntegrator_gainv_ip;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainv_ip
                           * Referenced by: '<S23>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: 0
                                        * Referenced by: '<S23>/Discrete-Time Integrator'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S49>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_n;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
                           * Referenced by: '<S49>/Discrete-Time Integrator'
                           */
  real_T Constant_Value_p;             /* Expression: 0.1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T set_robot_calibration_z_Value;/* Expression: -0.4237
                                        * Referenced by: '<S13>/set_robot_calibration_z'
                                        */
  real_T EnableVentiel_Value[8];       /* Expression: [1,0,0,0,0,0,0,0]
                                        * Referenced by: '<S12>/Enable//Ventiel'
                                        */
  real_T Constant1_Value_f;            /* Expression: 5
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 1/100
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Gain_Gain_ph;                 /* Expression: 25
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Dctintegrator_P1_Size[2];  /* Computed Parameter: Dctintegrator_P1_Size
                                     * Referenced by: '<S30>/Dctintegrator'
                                     */
  real_T Dctintegrator_P1;             /* Expression: f_num
                                        * Referenced by: '<S30>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size[2];  /* Computed Parameter: Dctintegrator_P2_Size
                                     * Referenced by: '<S30>/Dctintegrator'
                                     */
  real_T Dctintegrator_P2;             /* Expression: 0.001
                                        * Referenced by: '<S30>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_p[2];    /* Computed Parameter: Dctleadlag_P1_Size_p
                                      * Referenced by: '<S30>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_c;              /* Expression: f_num
                                        * Referenced by: '<S30>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_p[2];    /* Computed Parameter: Dctleadlag_P2_Size_p
                                      * Referenced by: '<S30>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_i;              /* Expression: f_den
                                        * Referenced by: '<S30>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_c[2];    /* Computed Parameter: Dctleadlag_P3_Size_c
                                      * Referenced by: '<S30>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_m;              /* Expression: 0.001
                                        * Referenced by: '<S30>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_f[2];  /* Computed Parameter: Dct1lowpass_P1_Size_f
                                     * Referenced by: '<S30>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_m;             /* Expression: f_den
                                        * Referenced by: '<S30>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_g[2];  /* Computed Parameter: Dct1lowpass_P2_Size_g
                                     * Referenced by: '<S30>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_l;             /* Expression: 0.001
                                        * Referenced by: '<S30>/Dct1lowpass'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 0.7
                                        * Referenced by: '<S21>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: -0.7
                                        * Referenced by: '<S21>/Saturation'
                                        */
  real_T Gain_Gain_ju;                 /* Expression: 25
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T Dctleadlag_P1_Size_n[2];    /* Computed Parameter: Dctleadlag_P1_Size_n
                                      * Referenced by: '<S31>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_p;              /* Expression: f_num
                                        * Referenced by: '<S31>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_b[2];    /* Computed Parameter: Dctleadlag_P2_Size_b
                                      * Referenced by: '<S31>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_o;              /* Expression: f_den
                                        * Referenced by: '<S31>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_d[2];    /* Computed Parameter: Dctleadlag_P3_Size_d
                                      * Referenced by: '<S31>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_c;              /* Expression: 0.001
                                        * Referenced by: '<S31>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_p[2];  /* Computed Parameter: Dct1lowpass_P1_Size_p
                                     * Referenced by: '<S31>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_d;             /* Expression: f_den
                                        * Referenced by: '<S31>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_gi[2];/* Computed Parameter: Dct1lowpass_P2_Size_gi
                                    * Referenced by: '<S31>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P2_n;             /* Expression: 0.001
                                        * Referenced by: '<S31>/Dct1lowpass'
                                        */
  real_T Voltagemiddle_Value;          /* Expression: 2.5
                                        * Referenced by: '<S12>/Voltage middle'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 20
                                        * Referenced by: '<S37>/Gain1'
                                        */
  real_T Dctintegrator_P1_Size_c[2];
                                  /* Computed Parameter: Dctintegrator_P1_Size_c
                                   * Referenced by: '<S37>/Dctintegrator'
                                   */
  real_T Dctintegrator_P1_h;           /* Expression: f_num
                                        * Referenced by: '<S37>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size_j[2];
                                  /* Computed Parameter: Dctintegrator_P2_Size_j
                                   * Referenced by: '<S37>/Dctintegrator'
                                   */
  real_T Dctintegrator_P2_c;           /* Expression: 0.001
                                        * Referenced by: '<S37>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_ph[2];  /* Computed Parameter: Dctleadlag_P1_Size_ph
                                     * Referenced by: '<S37>/Dctleadlag'
                                     */
  real_T Dctleadlag_P1_f;              /* Expression: f_num
                                        * Referenced by: '<S37>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_l[2];    /* Computed Parameter: Dctleadlag_P2_Size_l
                                      * Referenced by: '<S37>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_p;              /* Expression: f_den
                                        * Referenced by: '<S37>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_j[2];    /* Computed Parameter: Dctleadlag_P3_Size_j
                                      * Referenced by: '<S37>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_f;              /* Expression: 0.001
                                        * Referenced by: '<S37>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_m[2];  /* Computed Parameter: Dct1lowpass_P1_Size_m
                                     * Referenced by: '<S37>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_do;            /* Expression: f_den
                                        * Referenced by: '<S37>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_i[2];  /* Computed Parameter: Dct1lowpass_P2_Size_i
                                     * Referenced by: '<S37>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_nr;            /* Expression: 0.001
                                        * Referenced by: '<S37>/Dct1lowpass'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 20
                                        * Referenced by: '<S38>/Gain1'
                                        */
  real_T Dctleadlag_P1_Size_b[2];    /* Computed Parameter: Dctleadlag_P1_Size_b
                                      * Referenced by: '<S38>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_j;              /* Expression: f_num
                                        * Referenced by: '<S38>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_o[2];    /* Computed Parameter: Dctleadlag_P2_Size_o
                                      * Referenced by: '<S38>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_b;              /* Expression: f_den
                                        * Referenced by: '<S38>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_a[2];    /* Computed Parameter: Dctleadlag_P3_Size_a
                                      * Referenced by: '<S38>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_g;              /* Expression: 0.001
                                        * Referenced by: '<S38>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_i[2];  /* Computed Parameter: Dct1lowpass_P1_Size_i
                                     * Referenced by: '<S38>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_db;            /* Expression: f_den
                                        * Referenced by: '<S38>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_j[2];  /* Computed Parameter: Dct1lowpass_P2_Size_j
                                     * Referenced by: '<S38>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_ns;            /* Expression: 0.001
                                        * Referenced by: '<S38>/Dct1lowpass'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 5
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: 0
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 10
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: -10
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Gain_Gain_ll;                 /* Expression: 1/100
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 25
                                        * Referenced by: '<S46>/Gain'
                                        */
  real_T Dctintegrator_P1_Size_j[2];
                                  /* Computed Parameter: Dctintegrator_P1_Size_j
                                   * Referenced by: '<S46>/Dctintegrator'
                                   */
  real_T Dctintegrator_P1_d;           /* Expression: f_num
                                        * Referenced by: '<S46>/Dctintegrator'
                                        */
  real_T Dctintegrator_P2_Size_n[2];
                                  /* Computed Parameter: Dctintegrator_P2_Size_n
                                   * Referenced by: '<S46>/Dctintegrator'
                                   */
  real_T Dctintegrator_P2_f;           /* Expression: 0.001
                                        * Referenced by: '<S46>/Dctintegrator'
                                        */
  real_T Dctleadlag_P1_Size_o[2];    /* Computed Parameter: Dctleadlag_P1_Size_o
                                      * Referenced by: '<S46>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_g;              /* Expression: f_num
                                        * Referenced by: '<S46>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_o4[2];  /* Computed Parameter: Dctleadlag_P2_Size_o4
                                     * Referenced by: '<S46>/Dctleadlag'
                                     */
  real_T Dctleadlag_P2_e;              /* Expression: f_den
                                        * Referenced by: '<S46>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_l[2];    /* Computed Parameter: Dctleadlag_P3_Size_l
                                      * Referenced by: '<S46>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_mc;             /* Expression: 0.001
                                        * Referenced by: '<S46>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_g[2];  /* Computed Parameter: Dct1lowpass_P1_Size_g
                                     * Referenced by: '<S46>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_a;             /* Expression: f_den
                                        * Referenced by: '<S46>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_p[2];  /* Computed Parameter: Dct1lowpass_P2_Size_p
                                     * Referenced by: '<S46>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_o;             /* Expression: 0.001
                                        * Referenced by: '<S46>/Dct1lowpass'
                                        */
  real_T Gain_Gain_pq;                 /* Expression: 30
                                        * Referenced by: '<S47>/Gain'
                                        */
  real_T Dctleadlag_P1_Size_f[2];    /* Computed Parameter: Dctleadlag_P1_Size_f
                                      * Referenced by: '<S47>/Dctleadlag'
                                      */
  real_T Dctleadlag_P1_h;              /* Expression: f_num
                                        * Referenced by: '<S47>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_d[2];    /* Computed Parameter: Dctleadlag_P2_Size_d
                                      * Referenced by: '<S47>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_l;              /* Expression: f_den
                                        * Referenced by: '<S47>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_p[2];    /* Computed Parameter: Dctleadlag_P3_Size_p
                                      * Referenced by: '<S47>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_l;              /* Expression: 0.001
                                        * Referenced by: '<S47>/Dctleadlag'
                                        */
  real_T Dct1lowpass_P1_Size_d[2];  /* Computed Parameter: Dct1lowpass_P1_Size_d
                                     * Referenced by: '<S47>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P1_g;             /* Expression: f_den
                                        * Referenced by: '<S47>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_k[2];  /* Computed Parameter: Dct1lowpass_P2_Size_k
                                     * Referenced by: '<S47>/Dct1lowpass'
                                     */
  real_T Dct1lowpass_P2_f;             /* Expression: 0.001
                                        * Referenced by: '<S47>/Dct1lowpass'
                                        */
  real_T DiscreteTimeIntegrator_gainva_c;
                          /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                           * Referenced by: '<S24>/Discrete-Time Integrator'
                           */
  real_T DiscreteTimeIntegrator_IC_f;  /* Expression: 0
                                        * Referenced by: '<S24>/Discrete-Time Integrator'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 10*2.5/500
                                        * Referenced by: '<S56>/Gain1'
                                        */
  real_T Dctintegrator3_P1_Size_e[2];
                                 /* Computed Parameter: Dctintegrator3_P1_Size_e
                                  * Referenced by: '<S56>/Dctintegrator3'
                                  */
  real_T Dctintegrator3_P1_e;          /* Expression: f_num
                                        * Referenced by: '<S56>/Dctintegrator3'
                                        */
  real_T Dctintegrator3_P2_Size_i[2];
                                 /* Computed Parameter: Dctintegrator3_P2_Size_i
                                  * Referenced by: '<S56>/Dctintegrator3'
                                  */
  real_T Dctintegrator3_P2_a;          /* Expression: 0.001
                                        * Referenced by: '<S56>/Dctintegrator3'
                                        */
  real_T Dct1lowpass_P1_Size_ph[2];/* Computed Parameter: Dct1lowpass_P1_Size_ph
                                    * Referenced by: '<S56>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P1_j;             /* Expression: f_den
                                        * Referenced by: '<S56>/Dct1lowpass'
                                        */
  real_T Dct1lowpass_P2_Size_p0[2];/* Computed Parameter: Dct1lowpass_P2_Size_p0
                                    * Referenced by: '<S56>/Dct1lowpass'
                                    */
  real_T Dct1lowpass_P2_p;             /* Expression: 0.001
                                        * Referenced by: '<S56>/Dct1lowpass'
                                        */
  real_T Dctleadlag_P1_Size_pu[2];  /* Computed Parameter: Dctleadlag_P1_Size_pu
                                     * Referenced by: '<S56>/Dctleadlag'
                                     */
  real_T Dctleadlag_P1_je;             /* Expression: f_num
                                        * Referenced by: '<S56>/Dctleadlag'
                                        */
  real_T Dctleadlag_P2_Size_n[2];    /* Computed Parameter: Dctleadlag_P2_Size_n
                                      * Referenced by: '<S56>/Dctleadlag'
                                      */
  real_T Dctleadlag_P2_m;              /* Expression: f_den
                                        * Referenced by: '<S56>/Dctleadlag'
                                        */
  real_T Dctleadlag_P3_Size_f[2];    /* Computed Parameter: Dctleadlag_P3_Size_f
                                      * Referenced by: '<S56>/Dctleadlag'
                                      */
  real_T Dctleadlag_P3_i;              /* Expression: 0.001
                                        * Referenced by: '<S56>/Dctleadlag'
                                        */
  real_T HomingRunningSwitch_Threshold_c;/* Expression: 0.5
                                          * Referenced by: '<S24>/Homing Running Switch'
                                          */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S12>/Gain4'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 5
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S12>/Saturation1'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: 10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -10
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 1/100
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T HomingRunningSwitch1_Threshol_k;/* Expression: 0.5
                                          * Referenced by: '<S12>/Homing Running Switch1'
                                          */
  real_T Saturation2_UpperSat;         /* Expression: 5
                                        * Referenced by: '<S12>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S12>/Saturation2'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -10
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S13>/Unit Delay1'
                                        */
  real_T HomingRunningSwitch_Threshold_f;/* Expression: 0.5
                                          * Referenced by: '<S20>/Homing Running Switch'
                                          */
  real_T Gain_Gain_lr;                 /* Expression: 3
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T ResetEncoderR_P1_Size[2];  /* Computed Parameter: ResetEncoderR_P1_Size
                                     * Referenced by: '<S21>/Reset EncoderR'
                                     */
  real_T ResetEncoderR_P1;             /* Expression: link_id
                                        * Referenced by: '<S21>/Reset EncoderR'
                                        */
  real_T ResetEncoderR_P2_Size[2];  /* Computed Parameter: ResetEncoderR_P2_Size
                                     * Referenced by: '<S21>/Reset EncoderR'
                                     */
  real_T ResetEncoderR_P2;             /* Expression: chan_id
                                        * Referenced by: '<S21>/Reset EncoderR'
                                        */
  real_T LimitSpeed_RisingLim;         /* Expression: 0.6
                                        * Referenced by: '<S33>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim;        /* Expression: -0.6
                                        * Referenced by: '<S33>/Limit Speed'
                                        */
  real_T LimitSpeed_IC;                /* Expression: 0
                                        * Referenced by: '<S33>/Limit Speed'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S36>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim;  /* Expression: 0.8
                                        * Referenced by: '<S33>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim; /* Expression: -0.8
                                        * Referenced by: '<S33>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_IC;         /* Expression: 0
                                        * Referenced by: '<S33>/Limit Acceleration'
                                        */
  real_T ResetEncoderX_P1_Size[2];  /* Computed Parameter: ResetEncoderX_P1_Size
                                     * Referenced by: '<S22>/Reset EncoderX'
                                     */
  real_T ResetEncoderX_P1;             /* Expression: link_id
                                        * Referenced by: '<S22>/Reset EncoderX'
                                        */
  real_T ResetEncoderX_P2_Size[2];  /* Computed Parameter: ResetEncoderX_P2_Size
                                     * Referenced by: '<S22>/Reset EncoderX'
                                     */
  real_T ResetEncoderX_P2;             /* Expression: chan_id
                                        * Referenced by: '<S22>/Reset EncoderX'
                                        */
  real_T LimitSpeed_RisingLim_d;       /* Expression: 0.4
                                        * Referenced by: '<S39>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim_j;      /* Expression: -0.4
                                        * Referenced by: '<S39>/Limit Speed'
                                        */
  real_T LimitSpeed_IC_g;              /* Expression: 0
                                        * Referenced by: '<S39>/Limit Speed'
                                        */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S45>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim_c;/* Expression: 0.5
                                        * Referenced by: '<S39>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim_m;/* Expression: -0.5
                                         * Referenced by: '<S39>/Limit Acceleration'
                                         */
  real_T LimitAcceleration_IC_f;       /* Expression: 0
                                        * Referenced by: '<S39>/Limit Acceleration'
                                        */
  real_T ResetEncoderX_P1_Size_k[2];
                                  /* Computed Parameter: ResetEncoderX_P1_Size_k
                                   * Referenced by: '<S23>/Reset EncoderX'
                                   */
  real_T ResetEncoderX_P1_j;           /* Expression: link_id
                                        * Referenced by: '<S23>/Reset EncoderX'
                                        */
  real_T ResetEncoderX_P2_Size_k[2];
                                  /* Computed Parameter: ResetEncoderX_P2_Size_k
                                   * Referenced by: '<S23>/Reset EncoderX'
                                   */
  real_T ResetEncoderX_P2_j;           /* Expression: chan_id
                                        * Referenced by: '<S23>/Reset EncoderX'
                                        */
  real_T LimitSpeed_RisingLim_m;       /* Expression: 0.2
                                        * Referenced by: '<S49>/Limit Speed'
                                        */
  real_T LimitSpeed_FallingLim_jw;     /* Expression: -0.2
                                        * Referenced by: '<S49>/Limit Speed'
                                        */
  real_T LimitSpeed_IC_j;              /* Expression: 0
                                        * Referenced by: '<S49>/Limit Speed'
                                        */
  real_T TSamp_WtEt_i;                 /* Computed Parameter: TSamp_WtEt_i
                                        * Referenced by: '<S55>/TSamp'
                                        */
  real_T LimitAcceleration_RisingLim_j;/* Expression: 0.5
                                        * Referenced by: '<S49>/Limit Acceleration'
                                        */
  real_T LimitAcceleration_FallingLim_h;/* Expression: -0.5
                                         * Referenced by: '<S49>/Limit Acceleration'
                                         */
  real_T LimitAcceleration_IC_j;       /* Expression: 0
                                        * Referenced by: '<S49>/Limit Acceleration'
                                        */
  real_T ResetEncoderConv_P1_Size[2];
                                 /* Computed Parameter: ResetEncoderConv_P1_Size
                                  * Referenced by: '<S24>/Reset EncoderConv'
                                  */
  real_T ResetEncoderConv_P1;          /* Expression: link_id
                                        * Referenced by: '<S24>/Reset EncoderConv'
                                        */
  real_T ResetEncoderConv_P2_Size[2];
                                 /* Computed Parameter: ResetEncoderConv_P2_Size
                                  * Referenced by: '<S24>/Reset EncoderConv'
                                  */
  real_T ResetEncoderConv_P2;          /* Expression: chan_id
                                        * Referenced by: '<S24>/Reset EncoderConv'
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
                                    * Referenced by: '<S29>/String Constant3'
                                    */
  char_T StringConstant4_String[256];
                                   /* Computed Parameter: StringConstant4_String
                                    * Referenced by: '<S27>/String Constant4'
                                    */
  char_T StringConstant1_String[256];
                                   /* Computed Parameter: StringConstant1_String
                                    * Referenced by: '<S27>/String Constant1'
                                    */
  char_T ReadyGreen_String[256];       /* Computed Parameter: ReadyGreen_String
                                        * Referenced by: '<S13>/Ready Green'
                                        */
  char_T AirbagRed_String[256];        /* Computed Parameter: AirbagRed_String
                                        * Referenced by: '<S13>/Airbag Red'
                                        */
  char_T HomingOrange_String[256];    /* Computed Parameter: HomingOrange_String
                                       * Referenced by: '<S13>/Homing Orange'
                                       */
  char_T Delay_InitialCondition[256];
                                   /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S26>/Delay'
                                    */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S1>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<S1>/Manual Switch1'
                              */
  uint8_T Constant1_Value_b;           /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S28>/Constant1'
                                        */
  uint8_T Constant_Value_c;            /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S29>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_robotarm_student_2021a_Ebox_T {
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
    SimStruct childSFunctions[29];
    SimStruct *childSFunctionPtrs[29];
    struct _ssBlkInfo2 blkInfo2[29];
    struct _ssSFcnModelMethods2 methods2[29];
    struct _ssSFcnModelMethods3 methods3[29];
    struct _ssSFcnModelMethods4 methods4[29];
    struct _ssStatesInfo2 statesInfo2[29];
    ssPeriodicStatesInfo periodicStatesInfo[29];
    struct _ssPortInfo2 inputOutputPortInfo2[29];
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
      struct _ssPortInputs inputPortInfo[3];
      struct _ssInPortUnit inputPortUnits[3];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[3];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[8];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssInPortUnit inputPortUnits[3];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[3];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[8];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssInPortUnit inputPortUnits[3];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[3];
      real_T const *UPtrs0[2];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[8];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[1];
      mxArray *params[1];
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
      uint_T attribs[2];
      mxArray *params[2];
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
      uint_T attribs[3];
      mxArray *params[3];
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
      uint_T attribs[2];
      mxArray *params[2];
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
      uint_T attribs[3];
      mxArray *params[3];
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
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
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
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
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
      uint_T attribs[3];
      mxArray *params[3];
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
      uint_T attribs[2];
      mxArray *params[2];
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
      uint_T attribs[3];
      mxArray *params[3];
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
      uint_T attribs[2];
      mxArray *params[2];
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
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
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
      uint_T attribs[3];
      mxArray *params[3];
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
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn25;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn26;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn27;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn28;
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
extern P_robotarm_student_2021a_Ebox_T robotarm_student_2021a_Ebox_P;

/* Block signals (default storage) */
extern B_robotarm_student_2021a_Ebox_T robotarm_student_2021a_Ebox_B;

/* Block states (default storage) */
extern DW_robotarm_student_2021a_Ebox_T robotarm_student_2021a_Ebox_DW;

/* External data declarations for dependent source files */
extern const real_T robotarm_student_2021a_Ebox_RGND;/* real_T ground */

/* Model entry point functions */
extern void robotarm_student_2021a_Ebox_initialize(void);
extern void robotarm_student_2021a_Ebox_step(void);
extern void robotarm_student_2021a_Ebox_terminate(void);

/* Real-time Model object */
extern RT_MODEL_robotarm_student_2021a_Ebox_T *const
  robotarm_student_2021a_Ebox_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Signal Conversion' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'robotarm_student_2021a_Ebox'
 * '<S1>'   : 'robotarm_student_2021a_Ebox/Controller'
 * '<S2>'   : 'robotarm_student_2021a_Ebox/RobotArm'
 * '<S3>'   : 'robotarm_student_2021a_Ebox/Controller/Camera'
 * '<S4>'   : 'robotarm_student_2021a_Ebox/Controller/Controller Conveyor'
 * '<S5>'   : 'robotarm_student_2021a_Ebox/Controller/Controller R'
 * '<S6>'   : 'robotarm_student_2021a_Ebox/Controller/Controller Vacuum'
 * '<S7>'   : 'robotarm_student_2021a_Ebox/Controller/Controller X'
 * '<S8>'   : 'robotarm_student_2021a_Ebox/Controller/Controller Z'
 * '<S9>'   : 'robotarm_student_2021a_Ebox/Controller/Stateflow '
 * '<S10>'  : 'robotarm_student_2021a_Ebox/Controller/Camera/Detect Change'
 * '<S11>'  : 'robotarm_student_2021a_Ebox/Controller/Camera/Enabled Subsystem'
 * '<S12>'  : 'robotarm_student_2021a_Ebox/RobotArm/IO'
 * '<S13>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor'
 * '<S14>'  : 'robotarm_student_2021a_Ebox/RobotArm/IO/Ebox'
 * '<S15>'  : 'robotarm_student_2021a_Ebox/RobotArm/IO/Ebox1'
 * '<S16>'  : 'robotarm_student_2021a_Ebox/RobotArm/IO/Ebox2'
 * '<S17>'  : 'robotarm_student_2021a_Ebox/RobotArm/IO/Supervisor'
 * '<S18>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Compare To Constant'
 * '<S19>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/HomingBusyCheck'
 * '<S20>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Subsystem'
 * '<S21>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller R'
 * '<S22>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X'
 * '<S23>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z'
 * '<S24>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Conveyor'
 * '<S25>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Subsystem/LED Ring'
 * '<S26>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem'
 * '<S27>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3'
 * '<S28>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3/If Action Subsystem'
 * '<S29>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Subsystem/LED Ring/Subsystem3/If Action Subsystem1'
 * '<S30>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller R/ '
 * '<S31>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller R/   '
 * '<S32>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller R/Angle2Z'
 * '<S33>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory'
 * '<S34>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller R/Selector1'
 * '<S35>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller R/Supervisor'
 * '<S36>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller R/Point-to-point trajectory/Discrete Derivative'
 * '<S37>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X/Controller X1'
 * '<S38>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X/Controller X2'
 * '<S39>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory'
 * '<S40>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X/Selector'
 * '<S41>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X/Selector1'
 * '<S42>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X/Selector2'
 * '<S43>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X/Selector3'
 * '<S44>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X/Supervisor'
 * '<S45>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller X/Point-to-point trajectory/Discrete Derivative'
 * '<S46>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/    '
 * '<S47>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/     '
 * '<S48>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/Angle2Z'
 * '<S49>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory'
 * '<S50>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/Selector'
 * '<S51>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/Selector1'
 * '<S52>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/Selector2'
 * '<S53>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/Selector3'
 * '<S54>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/Supervisor'
 * '<S55>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Controller Z/Point-to-point trajectory/Discrete Derivative'
 * '<S56>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Conveyor/Controller Conveyor'
 * '<S57>'  : 'robotarm_student_2021a_Ebox/RobotArm/Supervisor/Supervisory Conveyor/Supervisor'
 */
#endif                           /* RTW_HEADER_robotarm_student_2021a_Ebox_h_ */
