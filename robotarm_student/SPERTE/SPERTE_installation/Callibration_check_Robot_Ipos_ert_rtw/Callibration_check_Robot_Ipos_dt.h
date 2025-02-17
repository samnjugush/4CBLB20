/*
 * Callibration_check_Robot_Ipos_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(void*),
  sizeof(action_T),
  2*sizeof(uint32_T),
  8,
  256,
  sizeof(FILE *),
  sizeof(codertarget_raspi_internal_SC_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "string",
  "char_T",
  "FILE *",
  "codertarget_raspi_internal_SC_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Callibration_check_Robot_Ipos_B.ManualSwitch1[0]), 15, 0, 256 },

  { (char_T *)(&Callibration_check_Robot_Ipos_B.SFunction), 0, 0, 138 },

  { (char_T *)(&Callibration_check_Robot_Ipos_B.RelationalOperator), 8, 0, 5 },

  { (char_T *)(&Callibration_check_Robot_Ipos_B.sf_MATLABFunction1.path), 0, 0,
    1 },

  { (char_T *)(&Callibration_check_Robot_Ipos_B.sf_MATLABFunction.path), 0, 0, 1
  },

  { (char_T *)(&Callibration_check_Robot_Ipos_B.sf_MATLABFunction2.path), 0, 0,
    1 }
  ,

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.DiscreteTimeIntegrator_DSTATE),
    0, 0, 31 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.Delay_DSTATE[0]), 15, 0, 1 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.PrevY), 0, 0, 52 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.Scope16_PWORK.LoggedData), 11,
    0, 40 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.sfEvent), 6, 0, 5 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.is_c1_Callibration_check_Robot_),
    7, 0, 9 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.NF), 4, 0, 1 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.temporalCounter_i1), 5, 0, 4 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.Subsystem3_SubsysRanBC), 2, 0,
    5 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.is_active_c1_Callibration_check),
    3, 0, 10 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.doneDoubleBufferReInit), 8, 0,
    21 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.eml_openfiles[0]), 16, 0, 20 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.Controller_MODE), 8, 0, 1 },

  { (char_T *)
    (&Callibration_check_Robot_Ipos_DW.sf_MATLABFunction1.previous_value_reference_start),
    0, 0, 3 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.sf_MATLABFunction1.path_array),
    11, 0, 1 },

  { (char_T *)
    (&Callibration_check_Robot_Ipos_DW.sf_MATLABFunction1.path_array_not_empty),
    8, 0, 1 },

  { (char_T *)
    (&Callibration_check_Robot_Ipos_DW.sf_MATLABFunction.previous_value_reference_start),
    0, 0, 3 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.sf_MATLABFunction.path_array),
    11, 0, 1 },

  { (char_T *)
    (&Callibration_check_Robot_Ipos_DW.sf_MATLABFunction.path_array_not_empty),
    8, 0, 1 },

  { (char_T *)
    (&Callibration_check_Robot_Ipos_DW.sf_MATLABFunction2.previous_value_reference_start),
    0, 0, 3 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.sf_MATLABFunction2.path_array),
    11, 0, 1 },

  { (char_T *)
    (&Callibration_check_Robot_Ipos_DW.sf_MATLABFunction2.path_array_not_empty),
    8, 0, 1 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.SerialWrite.obj), 17, 0, 1 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.SerialWrite.objisempty), 8, 0,
    1 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.SerialWrite1.obj), 17, 0, 1 },

  { (char_T *)(&Callibration_check_Robot_Ipos_DW.SerialWrite1.objisempty), 8, 0,
    1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  32U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Callibration_check_Robot_Ipos_P.DiscreteDerivative_ICPrevScaled),
    0, 0, 8 },

  { (char_T *)(&Callibration_check_Robot_Ipos_P.MeasurementBlock_N_samples), 7,
    0, 1 },

  { (char_T *)(&Callibration_check_Robot_Ipos_P.CompareToConstant1_const), 3, 0,
    3 },

  { (char_T *)(&Callibration_check_Robot_Ipos_P.Delays_Y0), 0, 0, 302 },

  { (char_T *)(&Callibration_check_Robot_Ipos_P.LEDRing_Y0[0]), 14, 0, 2560 },

  { (char_T *)(&Callibration_check_Robot_Ipos_P.ManualSwitch_CurrentSetting), 3,
    0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] Callibration_check_Robot_Ipos_dt.h */
