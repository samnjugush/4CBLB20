/*
 * robotarm_student_2021a_Ebox_private.h
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

#ifndef RTW_HEADER_robotarm_student_2021a_Ebox_private_h_
#define RTW_HEADER_robotarm_student_2021a_Ebox_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "robotarm_student_2021a_Ebox.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void getSystemClockTimeval_Start_wrapper(void);
  extern void getSystemClockTimeval_Outputs_wrapper(real_T *y2);
  extern void getSystemClockTimeval_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

extern void dweakint(SimStruct *rts);
extern void dlowpass1(SimStruct *rts);
extern void dleadlag(SimStruct *rts);
extern void ec_Supervisor(SimStruct *rts);
extern void ec_Ebox(SimStruct *rts);
extern void ec_EboxResetEnc(SimStruct *rts);
extern void robotarm_stu_SerialWrite1_Start(DW_SerialWrite1_robotarm_stud_T
  *localDW);
extern void robotarm_student_2_SerialWrite1(const uint8_T rtu_0[32],
  DW_SerialWrite1_robotarm_stud_T *localDW);
extern void robotarm_stud_SerialWrite1_Term(DW_SerialWrite1_robotarm_stud_T
  *localDW);

#endif                   /* RTW_HEADER_robotarm_student_2021a_Ebox_private_h_ */
