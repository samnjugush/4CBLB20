/*
 * robotarm_student_2021a_Ebox_dt.h
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
  "codertarget_raspi_internal_SC_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&robotarm_student_2021a_Ebox_B.ec_Ebox_o2[0]), 0, 0, 37 },

  { (char_T *)(&robotarm_student_2021a_Ebox_B.ManualSwitch1[0]), 15, 0, 256 },

  { (char_T *)(&robotarm_student_2021a_Ebox_B.SFunction), 0, 0, 134 },

  { (char_T *)(&robotarm_student_2021a_Ebox_B.RelationalOperator), 8, 0, 7 }
  ,

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.DiscreteTimeIntegrator_DSTATE), 0,
    0, 25 },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.Delay_DSTATE[0]), 15, 0, 1 },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.PrevY), 0, 0, 51 },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.sfEvent), 6, 0, 5 },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.is_c4_robotarm_student_2021a_Eb),
    7, 0, 8 },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.temporalCounter_i1), 5, 0, 4 },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.Subsystem3_SubsysRanBC), 2, 0, 5
  },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.is_active_c4_robotarm_student_2),
    3, 0, 9 },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.doneDoubleBufferReInit), 8, 0, 2
  },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.SerialWrite.obj), 16, 0, 1 },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.SerialWrite.objisempty), 8, 0, 1
  },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.SerialWrite1.obj), 16, 0, 1 },

  { (char_T *)(&robotarm_student_2021a_Ebox_DW.SerialWrite1.objisempty), 8, 0, 1
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  17U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&robotarm_student_2021a_Ebox_P.DiscreteDerivative_ICPrevScaled),
    0, 0, 328 },

  { (char_T *)(&robotarm_student_2021a_Ebox_P.LEDRing_Y0[0]), 14, 0, 2560 },

  { (char_T *)(&robotarm_student_2021a_Ebox_P.ManualSwitch_CurrentSetting), 3, 0,
    4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] robotarm_student_2021a_Ebox_dt.h */
