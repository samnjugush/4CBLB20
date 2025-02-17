/*
 * Callibration_check_Robot_Ipos_data.c
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

#include "Callibration_check_Robot_Ipos.h"
#include "Callibration_check_Robot_Ipos_private.h"

/* Block parameters (default storage) */
P_Callibration_check_Robot_Ipos_T Callibration_check_Robot_Ipos_P = {
  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S64>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_b
   * Referenced by: '<S65>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_n
   * Referenced by: '<S51>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevSca_bn
   * Referenced by: '<S52>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_o
   * Referenced by: '<S39>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScal_c
   * Referenced by: '<S40>/UD'
   */
  0.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S18>/Constant'
   */
  4.0,

  /* Mask Parameter: DetectChange_vinit
   * Referenced by: '<S12>/Delay Input1'
   */
  0.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S10>/SPERTE_measurement_samples'
   */
  1U,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S19>/Constant'
   */
  3U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S10>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S10>/SPERTE_measurement_function'
   */
  1U,

  /* Computed Parameter: Delays_Y0
   * Referenced by: '<S13>/Delay [s]'
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

  /* Expression: 5
   * Referenced by: '<S6>/Gain'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S1>/Feedfoward R [V]'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Reference X [rad]'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S8>/Gain1'
   */
  5.0,

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

  /* Expression: 0
   * Referenced by: '<S1>/Conveyor speed [mm//s]'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S1>/Saturation '
   */
  100.0,

  /* Expression: -100
   * Referenced by: '<S1>/Saturation '
   */
  -100.0,

  /* Expression: -1
   * Referenced by: '<S1>/Reference Vacuum [bar]'
   */
  -1.0,

  /* Expression: -10
   * Referenced by: '<S7>/Gain1'
   */
  -10.0,

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
   * Referenced by: '<S21>/Homing Running Switch2'
   */
  50.0,

  /* Expression: 2.5
   * Referenced by: '<S21>/Homing Running Switch1'
   */
  2.5,

  /* Expression: 0
   * Referenced by: '<S22>/Constant2'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S23>/Homing Running Switch'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S23>/Constant1'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S24>/Homing Running Switch'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S24>/Constant1'
   */
  0.0,

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
   * Referenced by: '<S17>/ec_Ipos'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S17>/ec_Ipos'
   */
  1.0,

  /* Expression: 1/16000*9/150*2*pi
   * Referenced by: '<S15>/Gain'
   */
  2.3561944901923453E-5,

  /* Expression: 1.2633
   * Referenced by: '<S16>/set_robot_calibration_r'
   */
  1.2633,

  /* Expression: 0
   * Referenced by: '<S36>/Constant1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S36>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0.5
   * Referenced by: '<S22>/Homing Running Switch1'
   */
  0.5,

  /* Expression: 3
   * Referenced by: '<S22>/Constant3'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S22>/Constant4'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_p
   * Referenced by: '<S22>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0
   * Referenced by: '<S22>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: -0.05
   * Referenced by: '<S22>/Constant'
   */
  -0.05,

  /* Expression: 1/16000*9/100*2*pi
   * Referenced by: '<S15>/Gain1'
   */
  3.5342917352885178E-5,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_o
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0
   * Referenced by: '<S23>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: -0.60692
   * Referenced by: '<S16>/set_robot_calibration_x'
   */
  -0.60692,

  /* Expression: 0
   * Referenced by: '<S45>/Constant1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_m
   * Referenced by: '<S45>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0.5
   * Referenced by: '<S23>/Homing Running Switch1'
   */
  0.5,

  /* Expression: 2
   * Referenced by: '<S23>/Constant2'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S23>/Constant3'
   */
  0.0,

  /* Expression: 0.05
   * Referenced by: '<S23>/Constant'
   */
  0.05,

  /* Expression: 1/16000*9/100*2*pi
   * Referenced by: '<S15>/Gain2'
   */
  3.5342917352885178E-5,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_i
   * Referenced by: '<S24>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0
   * Referenced by: '<S24>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: -0.39487
   * Referenced by: '<S16>/set_robot_calibration_z'
   */
  -0.39487,

  /* Expression: 0
   * Referenced by: '<S58>/Constant1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_a
   * Referenced by: '<S58>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0.5
   * Referenced by: '<S24>/Homing Running Switch1'
   */
  0.5,

  /* Expression: 2
   * Referenced by: '<S24>/Constant5'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S24>/Constant6'
   */
  0.0,

  /* Expression: 0.05
   * Referenced by: '<S24>/Constant'
   */
  0.05,

  /* Expression: 0
   * Referenced by: '<S16>/Unit Delay'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S16>/Gain'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S20>/Constant'
   */
  1.0,

  /* Expression: 1/16000*2*pi*2.05*10
   * Referenced by: '<S15>/Gain3'
   */
  0.0080503311748238437,

  /* Expression: 0
   * Referenced by: '<S16>/Unit Delay1'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S21>/Homing Running Switch'
   */
  0.5,

  /* Computed Parameter: ResetEncoderR_P1_Size
   * Referenced by: '<S22>/Reset EncoderR'
   */
  { 1.0, 1.0 },

  /* Expression: ipos_id
   * Referenced by: '<S22>/Reset EncoderR'
   */
  3.0,

  /* Expression: 25
   * Referenced by: '<S31>/Gain'
   */
  25.0,

  /* Computed Parameter: Dctintegrator_P1_Size
   * Referenced by: '<S31>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S31>/Dctintegrator'
   */
  0.5,

  /* Computed Parameter: Dctintegrator_P2_Size
   * Referenced by: '<S31>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S31>/Dctintegrator'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_h
   * Referenced by: '<S31>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S31>/Dctleadlag'
   */
  6.6667,

  /* Computed Parameter: Dctleadlag_P2_Size_j
   * Referenced by: '<S31>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S31>/Dctleadlag'
   */
  60.0,

  /* Computed Parameter: Dctleadlag_P3_Size_k
   * Referenced by: '<S31>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S31>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_b
   * Referenced by: '<S31>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S31>/Dct1lowpass'
   */
  100.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_c
   * Referenced by: '<S31>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S31>/Dct1lowpass'
   */
  0.001,

  /* Expression: 0.5
   * Referenced by: '<S22>/Homing Running Switch'
   */
  0.5,

  /* Expression: 25
   * Referenced by: '<S32>/Gain'
   */
  25.0,

  /* Computed Parameter: Dctleadlag_P1_Size_c
   * Referenced by: '<S32>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S32>/Dctleadlag'
   */
  6.6667,

  /* Computed Parameter: Dctleadlag_P2_Size_i
   * Referenced by: '<S32>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S32>/Dctleadlag'
   */
  60.0,

  /* Computed Parameter: Dctleadlag_P3_Size_n
   * Referenced by: '<S32>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S32>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_p
   * Referenced by: '<S32>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S32>/Dct1lowpass'
   */
  100.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_h
   * Referenced by: '<S32>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S32>/Dct1lowpass'
   */
  0.001,

  /* Expression: 40
   * Referenced by: '<S22>/Gain1'
   */
  40.0,

  /* Computed Parameter: ResetEncoderR1_P1_Size
   * Referenced by: '<S23>/Reset EncoderR1'
   */
  { 1.0, 1.0 },

  /* Expression: ipos_id
   * Referenced by: '<S23>/Reset EncoderR1'
   */
  1.0,

  /* Expression: 20
   * Referenced by: '<S41>/Gain1'
   */
  20.0,

  /* Computed Parameter: Dctintegrator_P1_Size_a
   * Referenced by: '<S41>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S41>/Dctintegrator'
   */
  0.5,

  /* Computed Parameter: Dctintegrator_P2_Size_p
   * Referenced by: '<S41>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S41>/Dctintegrator'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_o
   * Referenced by: '<S41>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S41>/Dctleadlag'
   */
  10.0,

  /* Computed Parameter: Dctleadlag_P2_Size_p
   * Referenced by: '<S41>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S41>/Dctleadlag'
   */
  90.0,

  /* Computed Parameter: Dctleadlag_P3_Size_e
   * Referenced by: '<S41>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S41>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_g
   * Referenced by: '<S41>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S41>/Dct1lowpass'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_hw
   * Referenced by: '<S41>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S41>/Dct1lowpass'
   */
  0.001,

  /* Expression: 20
   * Referenced by: '<S42>/Gain1'
   */
  20.0,

  /* Computed Parameter: Dctleadlag_P1_Size_j
   * Referenced by: '<S42>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S42>/Dctleadlag'
   */
  10.0,

  /* Computed Parameter: Dctleadlag_P2_Size_g
   * Referenced by: '<S42>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S42>/Dctleadlag'
   */
  90.0,

  /* Computed Parameter: Dctleadlag_P3_Size_j
   * Referenced by: '<S42>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S42>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_pc
   * Referenced by: '<S42>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S42>/Dct1lowpass'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_f
   * Referenced by: '<S42>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S42>/Dct1lowpass'
   */
  0.001,

  /* Expression: 40
   * Referenced by: '<S23>/Gain'
   */
  40.0,

  /* Expression: 1000
   * Referenced by: '<S23>/Saturation1'
   */
  1000.0,

  /* Expression: -1000
   * Referenced by: '<S23>/Saturation1'
   */
  -1000.0,

  /* Computed Parameter: ResetEncoderR1_P1_Size_p
   * Referenced by: '<S24>/Reset EncoderR1'
   */
  { 1.0, 1.0 },

  /* Expression: ipos_id
   * Referenced by: '<S24>/Reset EncoderR1'
   */
  2.0,

  /* Expression: 20
   * Referenced by: '<S53>/Gain'
   */
  20.0,

  /* Computed Parameter: Dctintegrator_P1_Size_d
   * Referenced by: '<S53>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S53>/Dctintegrator'
   */
  0.5,

  /* Computed Parameter: Dctintegrator_P2_Size_b
   * Referenced by: '<S53>/Dctintegrator'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S53>/Dctintegrator'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_b
   * Referenced by: '<S53>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S53>/Dctleadlag'
   */
  10.0,

  /* Computed Parameter: Dctleadlag_P2_Size_pu
   * Referenced by: '<S53>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S53>/Dctleadlag'
   */
  90.0,

  /* Computed Parameter: Dctleadlag_P3_Size_ja
   * Referenced by: '<S53>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S53>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_n
   * Referenced by: '<S53>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S53>/Dct1lowpass'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_e
   * Referenced by: '<S53>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S53>/Dct1lowpass'
   */
  0.001,

  /* Expression: 30
   * Referenced by: '<S54>/Gain'
   */
  30.0,

  /* Computed Parameter: Dctleadlag_P1_Size_p
   * Referenced by: '<S54>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S54>/Dctleadlag'
   */
  10.0,

  /* Computed Parameter: Dctleadlag_P2_Size_e
   * Referenced by: '<S54>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S54>/Dctleadlag'
   */
  90.0,

  /* Computed Parameter: Dctleadlag_P3_Size_p
   * Referenced by: '<S54>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S54>/Dctleadlag'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_a
   * Referenced by: '<S54>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S54>/Dct1lowpass'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_p
   * Referenced by: '<S54>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S54>/Dct1lowpass'
   */
  0.001,

  /* Expression: 40
   * Referenced by: '<S24>/Gain'
   */
  40.0,

  /* Expression: 1000
   * Referenced by: '<S24>/Saturation'
   */
  1000.0,

  /* Expression: -1000
   * Referenced by: '<S24>/Saturation'
   */
  -1000.0,

  /* Computed Parameter: ResetEncoderR1_P1_Size_j
   * Referenced by: '<S25>/Reset EncoderR1'
   */
  { 1.0, 1.0 },

  /* Expression: ipos_id
   * Referenced by: '<S25>/Reset EncoderR1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainv_mz
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Expression: 0
   * Referenced by: '<S25>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 10*2.5/500
   * Referenced by: '<S66>/Gain1'
   */
  0.05,

  /* Computed Parameter: Dctintegrator3_P1_Size_c
   * Referenced by: '<S66>/Dctintegrator3'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S66>/Dctintegrator3'
   */
  0.01,

  /* Computed Parameter: Dctintegrator3_P2_Size_h
   * Referenced by: '<S66>/Dctintegrator3'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S66>/Dctintegrator3'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass_P1_Size_i
   * Referenced by: '<S66>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S66>/Dct1lowpass'
   */
  30.0,

  /* Computed Parameter: Dct1lowpass_P2_Size_d
   * Referenced by: '<S66>/Dct1lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S66>/Dct1lowpass'
   */
  0.001,

  /* Computed Parameter: Dctleadlag_P1_Size_d
   * Referenced by: '<S66>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S66>/Dctleadlag'
   */
  3.0,

  /* Computed Parameter: Dctleadlag_P2_Size_g5
   * Referenced by: '<S66>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S66>/Dctleadlag'
   */
  20.0,

  /* Computed Parameter: Dctleadlag_P3_Size_i
   * Referenced by: '<S66>/Dctleadlag'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S66>/Dctleadlag'
   */
  0.001,

  /* Expression: 0.5
   * Referenced by: '<S25>/Homing Running Switch'
   */
  0.5,

  /* Expression: 32
   * Referenced by: '<S25>/Gain'
   */
  32.0,

  /* Expression: 0
   * Referenced by: '<S57>/Constant1'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S57>/Limit Speed'
   */
  0.2,

  /* Expression: -0.2
   * Referenced by: '<S57>/Limit Speed'
   */
  -0.2,

  /* Expression: 0
   * Referenced by: '<S57>/Limit Speed'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S64>/TSamp'
   */
  2048.0,

  /* Expression: 0.5
   * Referenced by: '<S57>/Limit Acceleration'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S57>/Limit Acceleration'
   */
  -0.5,

  /* Expression: 0
   * Referenced by: '<S57>/Limit Acceleration'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_f
   * Referenced by: '<S57>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Computed Parameter: TSamp_WtEt_h
   * Referenced by: '<S65>/TSamp'
   */
  2048.0,

  /* Expression: 0
   * Referenced by: '<S44>/Constant1'
   */
  0.0,

  /* Expression: 0.4
   * Referenced by: '<S44>/Limit Speed'
   */
  0.4,

  /* Expression: -0.4
   * Referenced by: '<S44>/Limit Speed'
   */
  -0.4,

  /* Expression: 0
   * Referenced by: '<S44>/Limit Speed'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_f
   * Referenced by: '<S51>/TSamp'
   */
  2048.0,

  /* Expression: 0.5
   * Referenced by: '<S44>/Limit Acceleration'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S44>/Limit Acceleration'
   */
  -0.5,

  /* Expression: 0
   * Referenced by: '<S44>/Limit Acceleration'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
   * Referenced by: '<S44>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Computed Parameter: TSamp_WtEt_k
   * Referenced by: '<S52>/TSamp'
   */
  2048.0,

  /* Expression: 0
   * Referenced by: '<S35>/Constant1'
   */
  0.0,

  /* Expression: 0.6
   * Referenced by: '<S35>/Limit Speed'
   */
  0.6,

  /* Expression: -0.6
   * Referenced by: '<S35>/Limit Speed'
   */
  -0.6,

  /* Expression: 0
   * Referenced by: '<S35>/Limit Speed'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt_p
   * Referenced by: '<S39>/TSamp'
   */
  2048.0,

  /* Expression: 0.8
   * Referenced by: '<S35>/Limit Acceleration'
   */
  0.8,

  /* Expression: -0.8
   * Referenced by: '<S35>/Limit Acceleration'
   */
  -0.8,

  /* Expression: 0
   * Referenced by: '<S35>/Limit Acceleration'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
   * Referenced by: '<S35>/Discrete-Time Integrator'
   */
  0.00048828125,

  /* Computed Parameter: TSamp_WtEt_g
   * Referenced by: '<S40>/TSamp'
   */
  2048.0,

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
   * Referenced by: '<S30>/String Constant3'
   */
  "color ",

  /* Computed Parameter: StringConstant1_String
   * Referenced by: '<S30>/String Constant1'
   */
  " 0 16",

  /* Computed Parameter: StringConstant4_String
   * Referenced by: '<S28>/String Constant4'
   */
  "white",

  /* Computed Parameter: ReadyGreen_String
   * Referenced by: '<S16>/Ready Green'
   */
  "0000FF00",

  /* Computed Parameter: AirbagRed_String
   * Referenced by: '<S16>/Airbag Red'
   */
  "00FF0000",

  /* Computed Parameter: HomingOrange_String
   * Referenced by: '<S16>/Homing Orange'
   */
  "00FF3900",

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S27>/Delay'
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

  /* Computed Parameter: Constant1_Value_l
   * Referenced by: '<S29>/Constant1'
   */
  13U,

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S30>/Constant'
   */
  13U
};
