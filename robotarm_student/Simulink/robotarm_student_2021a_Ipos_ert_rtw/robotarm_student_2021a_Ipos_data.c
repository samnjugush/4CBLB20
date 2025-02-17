/*
 * robotarm_student_2021a_Ipos_data.c
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

#include "robotarm_student_2021a_Ipos.h"
#include "robotarm_student_2021a_Ipos_private.h"

/* Block parameters (default storage) */
P_robotarm_student_2021a_Ipos_T robotarm_student_2021a_Ipos_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S54>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_e
   * Referenced by: '<S44>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_h
   * Referenced by: '<S35>/UD'
   */
  0.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S16>/Constant'
   */
  4.0,

  /* Mask Parameter: DetectChange_vinit
   * Referenced by: '<S11>/Delay Input1'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S17>/Constant'
   */
  3U,

  /* Computed Parameter: Delays_Y0
   * Referenced by: '<S12>/Delay [s]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Suck'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/ Blow'
   */
  1.0,

  /* Computed Parameter: RobotV_Y0
   * Referenced by: '<S1>/Robot [V]'
   */
  0.0,

  /* Computed Parameter: ConveyorV_Y0
   * Referenced by: '<S1>/Conveyor [V] '
   */
  0.0,

  /* Computed Parameter: VacuumV_Y0
   * Referenced by: '<S1>/Vacuum [V] '
   */
  0.0,

  /* Computed Parameter: Blowsuck_Y0
   * Referenced by: '<S1>/Blow//suck [-]'
   */
  0.0,

  /* Expression: [0                    0                    0      1709314849.7653;0  0  0  0;0  0  0  0]
   * Referenced by: '<S4>/Object detection matrix'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.7093148497653E+9, 0.0, 0.0 },

  /* Computed Parameter: Discreteintegrator_gainval
   * Referenced by: '<S1>/Discrete  integrator'
   */
  0.00048828125,

  /* Expression: 0
   * Referenced by: '<S1>/Discrete  integrator'
   */
  0.0,

  /* Expression: 0.05
   * Referenced by: '<S5>/Gain1'
   */
  0.05,

  /* Computed Parameter: Dctintegrator3_P1_Size
   * Referenced by: '<S5>/Dctintegrator3'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S5>/Dctintegrator3'
   */
  0.05,

  /* Computed Parameter: Dctintegrator3_P2_Size
   * Referenced by: '<S5>/Dctintegrator3'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S5>/Dctintegrator3'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size
   * Referenced by: '<S5>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S5>/Dct1lowpass'
   */
  40.0,

  /* Computed Parameter: Dct1lowpass_P2_Size
   * Referenced by: '<S5>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S5>/Dct1lowpass'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size
   * Referenced by: '<S5>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S5>/Dctleadlag'
   */
  3.0,

  /* Computed Parameter: Dctleadlag_P2_Size
   * Referenced by: '<S5>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S5>/Dctleadlag'
   */
  30.0,

  /* Computed Parameter: Dctleadlag_P3_Size
   * Referenced by: '<S5>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S5>/Dctleadlag'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S1>/Reference R [rad]'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Feedfoward R [V]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Reference X [rad]'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S8>/Gain1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Feedfoward X [V]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Reference Z [rad]'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S9>/Gain'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S1>/Feedfoward Z [V]'
   */
  0.0,

  /* Expression: -10
   * Referenced by: '<S1>/Conveyor speed [mm//s]'
   */
  -10.0,

  /* Expression: 100
   * Referenced by: '<S1>/Saturation '
   */
  100.0,

  /* Expression: -100
   * Referenced by: '<S1>/Saturation '
   */
  -100.0,

  /* Expression: 0.2
   * Referenced by: '<S1>/Reference Vacuum [bar]'
   */
  0.2,

  /* Expression: -100
   * Referenced by: '<S7>/Gain1'
   */
  -100.0,

  /* Expression: 1
   * Referenced by: '<S1>/Object'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Plot'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Stop'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<S19>/Homing Running Switch2'
   */
  50.0,

  /* Expression: 2.5
   * Referenced by: '<S19>/Homing Running Switch1'
   */
  2.5,

  /* Expression: 0.5
   * Referenced by: '<S20>/Homing Running Switch'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S21>/Homing Running Switch'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S22>/Homing Running Switch'
   */
  0.5,

  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S3>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S3>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S3>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S3>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ipos_P1_Size
   * Referenced by: '<S15>/ec_Ipos'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S15>/ec_Ipos'
   */
  1.0,

  /* Expression: 1/16000*9/150*2*pi
   * Referenced by: '<S13>/Gain'
   */
  2.3561944901923453E-5,

  /* Expression: 0
   * Referenced by: '<S32>/Constant1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S32>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
   * Referenced by: '<S20>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0
   * Referenced by: '<S20>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: -0.05
   * Referenced by: '<S20>/Constant'
   */
  -0.05,

  /* Expression: 1/16000*9/100*2*pi
   * Referenced by: '<S13>/Gain1'
   */
  3.5342917352885178E-5,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_h
   * Referenced by: '<S21>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0
   * Referenced by: '<S21>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S38>/Constant1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_j
   * Referenced by: '<S38>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: -0.1
   * Referenced by: '<S21>/Constant'
   */
  -0.1,

  /* Expression: 1/16000*9/100*2*pi
   * Referenced by: '<S13>/Gain2'
   */
  3.5342917352885178E-5,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
   * Referenced by: '<S22>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0
   * Referenced by: '<S22>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S48>/Constant1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_n
   * Referenced by: '<S48>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0.05
   * Referenced by: '<S22>/Constant'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<S14>/Unit Delay'
   */
  0.0,

  /* Expression: 1.2614
   * Referenced by: '<S14>/set_robot_calibration_r'
   */
  1.2614,

  /* Expression: 0.5842
   * Referenced by: '<S14>/set_robot_calibration_x'
   */
  0.5842,

  /* Expression: -0.34865
   * Referenced by: '<S14>/set_robot_calibration_z'
   */
  -0.34865,

  /* Expression: 3
   * Referenced by: '<S14>/Gain'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S18>/Constant'
   */
  1.0,

  /* Expression: 1/16000*2*pi*2.05*10
   * Referenced by: '<S13>/Gain3'
   */
  0.0080503311748238437,

  /* Expression: 1/65535
   * Referenced by: '<S13>/Gain4'
   */
  1.5259021896696422E-5,

  /* Expression: 1/2
   * Referenced by: '<S13>/Gain5'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S14>/Unit Delay1'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S19>/Homing Running Switch'
   */
  0.5,

  /* Computed Parameter: ResetEncoderR_P1_Size
   * Referenced by: '<S20>/Reset EncoderR'
   */
  { 1.0, 1.0 },

  /* Expression: ipos_id
   * Referenced by: '<S20>/Reset EncoderR'
   */
  3.0,

  /* Expression: 25
   * Referenced by: '<S29>/Gain'
   */
  25.0,

  /* Computed Parameter: Dctintegrator_P1_Size
   * Referenced by: '<S29>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S29>/Dctintegrator'
   */
  0.5,

  /* Computed Parameter: Dctintegrator_P2_Size
   * Referenced by: '<S29>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S29>/Dctintegrator'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_m
   * Referenced by: '<S29>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S29>/Dctleadlag'
   */
  6.6667,

  /* Computed Parameter: Dctleadlag_P2_Size_p
   * Referenced by: '<S29>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S29>/Dctleadlag'
   */
  60.0,

  /* Computed Parameter: Dctleadlag_P3_Size_h
   * Referenced by: '<S29>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S29>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_m
   * Referenced by: '<S29>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S29>/Dct1lowpass'
   */
  100.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_o
   * Referenced by: '<S29>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S29>/Dct1lowpass'
   */
  0.001,

  /* Expression: 25
   * Referenced by: '<S30>/Gain'
   */
  25.0,

  /* Computed Parameter: Dctleadlag_P1_Size_c
   * Referenced by: '<S30>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S30>/Dctleadlag'
   */
  6.6667,

  /* Computed Parameter: Dctleadlag_P2_Size_k
   * Referenced by: '<S30>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S30>/Dctleadlag'
   */
  60.0,

  /* Computed Parameter: Dctleadlag_P3_Size_hn
   * Referenced by: '<S30>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S30>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_a
   * Referenced by: '<S30>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S30>/Dct1lowpass'
   */
  100.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_l
   * Referenced by: '<S30>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S30>/Dct1lowpass'
   */
  0.001,

  /* Expression: 32
   * Referenced by: '<S20>/Gain1'
   */
  32.0,

  /* Expression: 127
   * Referenced by: '<S20>/Saturation1'
   */
  127.0,

  /* Expression: -127
   * Referenced by: '<S20>/Saturation1'
   */
  -127.0,

  /* Computed Parameter: ResetEncoderR1_P1_Size
   * Referenced by: '<S21>/Reset EncoderR1'
   */
  { 1.0, 1.0 },

  /* Expression: ipos_id
   * Referenced by: '<S21>/Reset EncoderR1'
   */
  1.0,

  /* Expression: 20
   * Referenced by: '<S36>/Gain1'
   */
  20.0,

  /* Computed Parameter: Dctintegrator_P1_Size_i
   * Referenced by: '<S36>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S36>/Dctintegrator'
   */
  0.5,

  /* Computed Parameter: Dctintegrator_P2_Size_p
   * Referenced by: '<S36>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S36>/Dctintegrator'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_d
   * Referenced by: '<S36>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S36>/Dctleadlag'
   */
  10.0,

  /* Computed Parameter: Dctleadlag_P2_Size_g
   * Referenced by: '<S36>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S36>/Dctleadlag'
   */
  90.0,

  /* Computed Parameter: Dctleadlag_P3_Size_o
   * Referenced by: '<S36>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S36>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_m3
   * Referenced by: '<S36>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S36>/Dct1lowpass'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_b
   * Referenced by: '<S36>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S36>/Dct1lowpass'
   */
  0.001,

  /* Expression: 20
   * Referenced by: '<S37>/Gain1'
   */
  20.0,

  /* Computed Parameter: Dctleadlag_P1_Size_b
   * Referenced by: '<S37>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S37>/Dctleadlag'
   */
  10.0,

  /* Computed Parameter: Dctleadlag_P2_Size_m
   * Referenced by: '<S37>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S37>/Dctleadlag'
   */
  90.0,

  /* Computed Parameter: Dctleadlag_P3_Size_p
   * Referenced by: '<S37>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S37>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_n
   * Referenced by: '<S37>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S37>/Dct1lowpass'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_g
   * Referenced by: '<S37>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S37>/Dct1lowpass'
   */
  0.001,

  /* Expression: 32
   * Referenced by: '<S21>/Gain'
   */
  32.0,

  /* Expression: 127
   * Referenced by: '<S21>/Saturation1'
   */
  127.0,

  /* Expression: -127
   * Referenced by: '<S21>/Saturation1'
   */
  -127.0,

  /* Computed Parameter: ResetEncoderR1_P1_Size_d
   * Referenced by: '<S22>/Reset EncoderR1'
   */
  { 1.0, 1.0 },

  /* Expression: ipos_id
   * Referenced by: '<S22>/Reset EncoderR1'
   */
  2.0,

  /* Expression: 20
   * Referenced by: '<S45>/Gain'
   */
  20.0,

  /* Computed Parameter: Dctintegrator_P1_Size_p
   * Referenced by: '<S45>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S45>/Dctintegrator'
   */
  0.5,

  /* Computed Parameter: Dctintegrator_P2_Size_o
   * Referenced by: '<S45>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S45>/Dctintegrator'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_ch
   * Referenced by: '<S45>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S45>/Dctleadlag'
   */
  10.0,

  /* Computed Parameter: Dctleadlag_P2_Size_h
   * Referenced by: '<S45>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S45>/Dctleadlag'
   */
  90.0,

  /* Computed Parameter: Dctleadlag_P3_Size_f
   * Referenced by: '<S45>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S45>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_ni
   * Referenced by: '<S45>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S45>/Dct1lowpass'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_a
   * Referenced by: '<S45>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S45>/Dct1lowpass'
   */
  0.001,

  /* Expression: 30
   * Referenced by: '<S46>/Gain'
   */
  30.0,

  /* Computed Parameter: Dctleadlag_P1_Size_by
   * Referenced by: '<S46>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S46>/Dctleadlag'
   */
  10.0,

  /* Computed Parameter: Dctleadlag_P2_Size_j
   * Referenced by: '<S46>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S46>/Dctleadlag'
   */
  90.0,

  /* Computed Parameter: Dctleadlag_P3_Size_oi
   * Referenced by: '<S46>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S46>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_p
   * Referenced by: '<S46>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S46>/Dct1lowpass'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_j
   * Referenced by: '<S46>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S46>/Dct1lowpass'
   */
  0.001,

  /* Expression: 32
   * Referenced by: '<S22>/Gain'
   */
  32.0,

  /* Expression: 127
   * Referenced by: '<S22>/Saturation1'
   */
  127.0,

  /* Expression: -127
   * Referenced by: '<S22>/Saturation1'
   */
  -127.0,

  /* Computed Parameter: ResetEncoderR1_P1_Size_b
   * Referenced by: '<S23>/Reset EncoderR1'
   */
  { 1.0, 1.0 },

  /* Expression: ipos_id
   * Referenced by: '<S23>/Reset EncoderR1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_g
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 10*2.5/500
   * Referenced by: '<S55>/Gain1'
   */
  0.05,

  /* Computed Parameter: Dctintegrator3_P1_Size_m
   * Referenced by: '<S55>/Dctintegrator3'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S55>/Dctintegrator3'
   */
  0.01,

  /* Computed Parameter: Dctintegrator3_P2_Size_b
   * Referenced by: '<S55>/Dctintegrator3'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S55>/Dctintegrator3'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_j
   * Referenced by: '<S55>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S55>/Dct1lowpass'
   */
  30.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_aj
   * Referenced by: '<S55>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S55>/Dct1lowpass'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_l
   * Referenced by: '<S55>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S55>/Dctleadlag'
   */
  3.0,

  /* Computed Parameter: Dctleadlag_P2_Size_n
   * Referenced by: '<S55>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S55>/Dctleadlag'
   */
  20.0,

  /* Computed Parameter: Dctleadlag_P3_Size_d
   * Referenced by: '<S55>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S55>/Dctleadlag'
   */
  0.001,

  /* Expression: 0.5
   * Referenced by: '<S23>/Homing Running Switch'
   */
  0.5,

  /* Expression: 32
   * Referenced by: '<S23>/Gain'
   */
  32.0,

  /* Expression: 127
   * Referenced by: '<S23>/Saturation1'
   */
  127.0,

  /* Expression: -127
   * Referenced by: '<S23>/Saturation1'
   */
  -127.0,

  /* Expression: 0.2
   * Referenced by: '<S48>/Limit Speed'
   */
  0.2,

  /* Expression: -0.2
   * Referenced by: '<S48>/Limit Speed'
   */
  -0.2,

  /* Expression: 0
   * Referenced by: '<S48>/Limit Speed'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S54>/TSamp'
   */
  2048.0,

  /* Expression: 0.5
   * Referenced by: '<S48>/Limit Acceleration'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S48>/Limit Acceleration'
   */
  -0.5,

  /* Expression: 0
   * Referenced by: '<S48>/Limit Acceleration'
   */
  0.0,

  /* Expression: 0.4
   * Referenced by: '<S38>/Limit Speed'
   */
  0.4,

  /* Expression: -0.4
   * Referenced by: '<S38>/Limit Speed'
   */
  -0.4,

  /* Expression: 0
   * Referenced by: '<S38>/Limit Speed'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_d
   * Referenced by: '<S44>/TSamp'
   */
  2048.0,

  /* Expression: 0.5
   * Referenced by: '<S38>/Limit Acceleration'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S38>/Limit Acceleration'
   */
  -0.5,

  /* Expression: 0
   * Referenced by: '<S38>/Limit Acceleration'
   */
  0.0,

  /* Expression: 0.6
   * Referenced by: '<S32>/Limit Speed'
   */
  0.6,

  /* Expression: -0.6
   * Referenced by: '<S32>/Limit Speed'
   */
  -0.6,

  /* Expression: 0
   * Referenced by: '<S32>/Limit Speed'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_g
   * Referenced by: '<S35>/TSamp'
   */
  2048.0,

  /* Expression: 0.8
   * Referenced by: '<S32>/Limit Acceleration'
   */
  0.8,

  /* Expression: -0.8
   * Referenced by: '<S32>/Limit Acceleration'
   */
  -0.8,

  /* Expression: 0
   * Referenced by: '<S32>/Limit Acceleration'
   */
  0.0,

  /* Computed Parameter: LEDRing_Y0
   * Referenced by: '<S1>/LED Ring [-]'
   */
  "",

  /* Computed Parameter: Colorsetwithstringblackorwhite_
   * Referenced by: '<S1>/Color; set with string; black or white'
   */
  "black",

  /* Computed Parameter: Colorspecifiedin6hexdigitsrrggb
   * Referenced by: '<S1>/Color; specified in 6 hex digits, rrggbb'
   */
  "0072bd",

  /* Computed Parameter: StringConstant3_String
   * Referenced by: '<S28>/String Constant3'
   */
  "color ",

  /* Computed Parameter: StringConstant1_String
   * Referenced by: '<S28>/String Constant1'
   */
  " 0 16",

  /* Computed Parameter: StringConstant4_String
   * Referenced by: '<S26>/String Constant4'
   */
  "white",

  /* Computed Parameter: ReadyGreen_String
   * Referenced by: '<S14>/Ready Green'
   */
  "0000FF00",

  /* Computed Parameter: AirbagRed_String
   * Referenced by: '<S14>/Airbag Red'
   */
  "00FF0000",

  /* Computed Parameter: HomingOrange_String
   * Referenced by: '<S14>/Homing Orange'
   */
  "00FF3900",

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S25>/Delay'
   */
  "",

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<S1>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<S1>/Manual Switch1'
   */
  1U,

  /* Computed Parameter: Constant1_Value_j
   * Referenced by: '<S27>/Constant1'
   */
  13U,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S28>/Constant'
   */
  13U
};
