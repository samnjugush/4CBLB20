/*
 * Callibration_check_Robot_Ipos_private.h
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

#ifndef RTW_HEADER_Callibration_check_Robot_Ipos_private_h_
#define RTW_HEADER_Callibration_check_Robot_Ipos_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Callibration_check_Robot_Ipos.h"

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

extern real_T rt_roundd_snf(real_T u);
extern void dweakint(SimStruct *rts);
extern void dlowpass1(SimStruct *rts);
extern void dleadlag(SimStruct *rts);
extern void ec_Supervisor(SimStruct *rts);
extern void Ipos360(SimStruct *rts);
extern void ec_IposResetEnc(SimStruct *rts);
extern void Callibration_SerialWrite1_Start(DW_SerialWrite1_Callibration__T
  *localDW);
extern void Callibration_check_SerialWrite1(const uint8_T rtu_0[32],
  DW_SerialWrite1_Callibration__T *localDW);
extern void Callibrati_MATLABFunction2_Init(DW_MATLABFunction2_Callibrati_T
  *localDW);
extern void Call_MATLABFunction2_CleanupRTR(DW_MATLABFunction2_Callibrati_T
  *localDW);
extern void Callibration_ch_MATLABFunction2(real_T rtu_reference_end, real_T
  rtu_end_time, real_T rtu_measured_position, B_MATLABFunction2_Callibratio_T
  *localB, DW_MATLABFunction2_Callibrati_T *localDW);
extern void Callibration__SerialWrite1_Term(DW_SerialWrite1_Callibration__T
  *localDW);

#endif                 /* RTW_HEADER_Callibration_check_Robot_Ipos_private_h_ */
