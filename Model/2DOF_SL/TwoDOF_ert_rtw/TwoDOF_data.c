/*
 * File: TwoDOF_data.c
 *
 * Code generated for Simulink model 'TwoDOF'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jun 20 21:06:06 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "TwoDOF.h"

/* Block parameters (default storage) */
P_TwoDOF_T TwoDOF_P = {
  /* Mask Parameter: xPOSPID_InitialConditionForFilt
   * Referenced by: '<S33>/Filter'
   */
  0.0,

  /* Mask Parameter: xVELPID_InitialConditionForFilt
   * Referenced by: '<S83>/Filter'
   */
  0.0,

  /* Mask Parameter: yPOSPID_InitialConditionForFilt
   * Referenced by: '<S133>/Filter'
   */
  0.0,

  /* Mask Parameter: yVELPID_InitialConditionForFilt
   * Referenced by: '<S183>/Filter'
   */
  0.0,

  /* Mask Parameter: xPOSPID_InitialConditionForInte
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: xVELPID_InitialConditionForInte
   * Referenced by: '<S88>/Integrator'
   */
  0.0,

  /* Mask Parameter: yPOSPID_InitialConditionForInte
   * Referenced by: '<S138>/Integrator'
   */
  0.0,

  /* Mask Parameter: yVELPID_InitialConditionForInte
   * Referenced by: '<S188>/Integrator'
   */
  0.0,

  /* Mask Parameter: xPOSPID_LowerSaturationLimit
   * Referenced by:
   *   '<S45>/Saturation'
   *   '<S31>/DeadZone'
   */
  -1.0,

  /* Mask Parameter: yPOSPID_LowerSaturationLimit
   * Referenced by:
   *   '<S145>/Saturation'
   *   '<S131>/DeadZone'
   */
  -1.0,

  /* Mask Parameter: xPOSPID_UpperSaturationLimit
   * Referenced by:
   *   '<S45>/Saturation'
   *   '<S31>/DeadZone'
   */
  1.0,

  /* Mask Parameter: yPOSPID_UpperSaturationLimit
   * Referenced by:
   *   '<S145>/Saturation'
   *   '<S131>/DeadZone'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/MATLAB System'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/MATLAB System1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/MATLAB System2'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S29>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S79>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S129>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S179>/Constant1'
   */
  0.0,

  /* Expression: [0.0165]
   * Referenced by: '<Root>/Discrete Transfer Fcn1'
   */
  0.0165,

  /* Expression: [1 -0.9835]
   * Referenced by: '<Root>/Discrete Transfer Fcn1'
   */
  { 1.0, -0.9835 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete Transfer Fcn1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S38>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S33>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_i
   * Referenced by: '<S88>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_p
   * Referenced by: '<S83>/Filter'
   */
  0.005,

  /* Expression: [0.0165]
   * Referenced by: '<Root>/Discrete Transfer Fcn'
   */
  0.0165,

  /* Expression: [1 -0.9835]
   * Referenced by: '<Root>/Discrete Transfer Fcn'
   */
  { 1.0, -0.9835 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete Transfer Fcn'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_e
   * Referenced by: '<S138>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_j
   * Referenced by: '<S133>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_b
   * Referenced by: '<S188>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_i
   * Referenced by: '<S183>/Filter'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S179>/Clamping_zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S129>/Clamping_zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S79>/Clamping_zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Clamping_zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S29>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S29>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S29>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S29>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S79>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_b
   * Referenced by: '<S79>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_k
   * Referenced by: '<S79>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_o
   * Referenced by: '<S79>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S129>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_c
   * Referenced by: '<S129>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_e
   * Referenced by: '<S129>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_k
   * Referenced by: '<S129>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S179>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_o
   * Referenced by: '<S179>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_b
   * Referenced by: '<S179>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_oh
   * Referenced by: '<S179>/Constant4'
   */
  -1
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
