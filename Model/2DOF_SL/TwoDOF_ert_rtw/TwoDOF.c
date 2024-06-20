/*
 * File: TwoDOF.c
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
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
B_TwoDOF_T TwoDOF_B;

/* Block states (default storage) */
DW_TwoDOF_T TwoDOF_DW;

/* Real-time model */
static RT_MODEL_TwoDOF_T TwoDOF_M_;
RT_MODEL_TwoDOF_T *const TwoDOF_M = &TwoDOF_M_;

/* Model step function */
void TwoDOF_step(void)
{
  real_T rtb_DeadZone_k;
  real_T rtb_DeadZone_l;
  real_T rtb_FilterCoefficient_c;
  real_T rtb_FilterCoefficient_ln;
  real_T rtb_IntegralGain_e;
  real_T tmp;
  real_T tmp_0;
  int8_T tmp_1;
  int8_T tmp_2;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1' */
  TwoDOF_B.numAccum = TwoDOF_P.DiscreteTransferFcn1_NumCoef *
    TwoDOF_DW.DiscreteTransferFcn1_states;

  /* MATLABSystem: '<Root>/MATLAB System1' */
  if (TwoDOF_DW.obj_i.SampleTime != TwoDOF_P.MATLABSystem1_SampleTime) {
    TwoDOF_DW.obj_i.SampleTime = TwoDOF_P.MATLABSystem1_SampleTime;
  }

  /*         %% Define output properties */
  TwoDOF_B.IntegralGain = 0.0;
  TwoDOF_B.FilterCoefficient = 0.0;
  stepFunctionIMU(&TwoDOF_B.IntegralGain, 1.0, &TwoDOF_B.FilterCoefficient, 1.0);

  /* MATLABSystem: '<Root>/MATLAB System' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System1'
   * */
  if (TwoDOF_DW.obj.SampleTime != TwoDOF_P.MATLABSystem_SampleTime) {
    TwoDOF_DW.obj.SampleTime = TwoDOF_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  TwoDOF_B.DeadZone = 0.0;
  TwoDOF_B.IntegralGain_g = 0.0;
  TwoDOF_B.IntegralGain_m = 0.0;
  rtb_IntegralGain_e = 0.0;
  stepFunctionEncoders(&TwoDOF_B.DeadZone, 1.0, &TwoDOF_B.IntegralGain_g, 1.0,
                       &TwoDOF_B.IntegralGain_m, 1.0, &rtb_IntegralGain_e, 1.0,
                       TwoDOF_B.IntegralGain, 1.0, TwoDOF_B.FilterCoefficient,
                       1.0);

  /* Sum: '<Root>/Sum23' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  MATLABSystem: '<Root>/MATLAB System'
   * */
  TwoDOF_B.IntegralGain = TwoDOF_DW.DiscreteTimeIntegrator_DSTATE -
    TwoDOF_B.DeadZone;

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S33>/Filter'
   *  Gain: '<S32>/Derivative Gain'
   *  Sum: '<S33>/SumD'
   */
  TwoDOF_B.FilterCoefficient = (ixposkd * TwoDOF_B.IntegralGain -
    TwoDOF_DW.Filter_DSTATE) * FilterCoeffN;

  /* Sum: '<S47>/Sum' incorporates:
   *  DiscreteIntegrator: '<S38>/Integrator'
   *  Gain: '<S43>/Proportional Gain'
   */
  TwoDOF_B.DeadZone = (ixposkp * TwoDOF_B.IntegralGain +
                       TwoDOF_DW.Integrator_DSTATE) + TwoDOF_B.FilterCoefficient;

  /* Saturate: '<S45>/Saturation' */
  if (TwoDOF_B.DeadZone > TwoDOF_P.xPOSPID_UpperSaturationLimit) {
    tmp = TwoDOF_P.xPOSPID_UpperSaturationLimit;
  } else if (TwoDOF_B.DeadZone < TwoDOF_P.xPOSPID_LowerSaturationLimit) {
    tmp = TwoDOF_P.xPOSPID_LowerSaturationLimit;
  } else {
    tmp = TwoDOF_B.DeadZone;
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1'
   *  MATLABSystem: '<Root>/MATLAB System'
   *  Saturate: '<S45>/Saturation'
   * */
  TwoDOF_B.IntegralGain_g = (TwoDOF_B.numAccum + tmp) - TwoDOF_B.IntegralGain_g;

  /* Gain: '<S91>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S83>/Filter'
   *  Gain: '<S82>/Derivative Gain'
   *  Sum: '<S83>/SumD'
   */
  TwoDOF_B.FilterCoefficient_k = (ixvelkd * TwoDOF_B.IntegralGain_g -
    TwoDOF_DW.Filter_DSTATE_d) * FilterCoeffN;

  /* Sum: '<S97>/Sum' incorporates:
   *  DiscreteIntegrator: '<S88>/Integrator'
   *  Gain: '<S93>/Proportional Gain'
   */
  TwoDOF_B.DeadZone_j = (ixvelkp * TwoDOF_B.IntegralGain_g +
    TwoDOF_DW.Integrator_DSTATE_m) + TwoDOF_B.FilterCoefficient_k;

  /* DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  TwoDOF_B.numAccum_m = TwoDOF_P.DiscreteTransferFcn_NumCoef *
    TwoDOF_DW.DiscreteTransferFcn_states;

  /* Sum: '<Root>/Sum16' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
   *  MATLABSystem: '<Root>/MATLAB System'
   * */
  TwoDOF_B.IntegralGain_m = TwoDOF_DW.DiscreteTimeIntegrator1_DSTATE -
    TwoDOF_B.IntegralGain_m;

  /* Gain: '<S141>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S133>/Filter'
   *  Gain: '<S132>/Derivative Gain'
   *  Sum: '<S133>/SumD'
   */
  rtb_FilterCoefficient_ln = (iyposkd * TwoDOF_B.IntegralGain_m -
    TwoDOF_DW.Filter_DSTATE_dy) * FilterCoeffN;

  /* Sum: '<S147>/Sum' incorporates:
   *  DiscreteIntegrator: '<S138>/Integrator'
   *  Gain: '<S143>/Proportional Gain'
   */
  rtb_DeadZone_k = (iyposkp * TwoDOF_B.IntegralGain_m +
                    TwoDOF_DW.Integrator_DSTATE_mi) + rtb_FilterCoefficient_ln;

  /* Saturate: '<S145>/Saturation' */
  if (rtb_DeadZone_k > TwoDOF_P.yPOSPID_UpperSaturationLimit) {
    tmp = TwoDOF_P.yPOSPID_UpperSaturationLimit;
  } else if (rtb_DeadZone_k < TwoDOF_P.yPOSPID_LowerSaturationLimit) {
    tmp = TwoDOF_P.yPOSPID_LowerSaturationLimit;
  } else {
    tmp = rtb_DeadZone_k;
  }

  /* Sum: '<Root>/Sum3' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn'
   *  MATLABSystem: '<Root>/MATLAB System'
   *  Saturate: '<S145>/Saturation'
   * */
  rtb_IntegralGain_e = (TwoDOF_B.numAccum_m + tmp) - rtb_IntegralGain_e;

  /* Gain: '<S191>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S183>/Filter'
   *  Gain: '<S182>/Derivative Gain'
   *  Sum: '<S183>/SumD'
   */
  rtb_FilterCoefficient_c = (iyvelkd * rtb_IntegralGain_e -
    TwoDOF_DW.Filter_DSTATE_k) * FilterCoeffN;

  /* Sum: '<S197>/Sum' incorporates:
   *  DiscreteIntegrator: '<S188>/Integrator'
   *  Gain: '<S193>/Proportional Gain'
   */
  rtb_DeadZone_l = (iyvelkp * rtb_IntegralGain_e + TwoDOF_DW.Integrator_DSTATE_i)
    + rtb_FilterCoefficient_c;

  /* MATLABSystem: '<Root>/MATLAB System2' */
  if (TwoDOF_DW.obj_g.SampleTime != TwoDOF_P.MATLABSystem2_SampleTime) {
    TwoDOF_DW.obj_g.SampleTime = TwoDOF_P.MATLABSystem2_SampleTime;
  }

  /* Saturate: '<S95>/Saturation' */
  /*         %% Define output properties */
  if (TwoDOF_B.DeadZone_j > PitchXMotorSaturation) {
    tmp = PitchXMotorSaturation;
  } else if (TwoDOF_B.DeadZone_j < -PitchXMotorSaturation) {
    tmp = -PitchXMotorSaturation;
  } else {
    tmp = TwoDOF_B.DeadZone_j;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Saturate: '<S95>/Saturation'
   */
  tmp = floor(tmp);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  /* Saturate: '<S195>/Saturation' */
  if (rtb_DeadZone_l > RollYMotorSaturation) {
    tmp_0 = RollYMotorSaturation;
  } else if (rtb_DeadZone_l < -RollYMotorSaturation) {
    tmp_0 = -RollYMotorSaturation;
  } else {
    tmp_0 = rtb_DeadZone_l;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Saturate: '<S195>/Saturation'
   */
  tmp_0 = floor(tmp_0);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  /* MATLABSystem: '<Root>/MATLAB System2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  stepFunctionMotors_Propellers(tmp < 0.0 ? -(int32_T)(uint32_T)-tmp : (int32_T)
    (uint32_T)tmp, 1.0, tmp_0 < 0.0 ? -(int32_T)(uint32_T)-tmp_0 : (int32_T)
    (uint32_T)tmp_0, 1.0);

  /* DeadZone: '<S181>/DeadZone' */
  if (rtb_DeadZone_l > RollYMotorSaturation) {
    rtb_DeadZone_l -= RollYMotorSaturation;
  } else if (rtb_DeadZone_l >= -RollYMotorSaturation) {
    rtb_DeadZone_l = 0.0;
  } else {
    rtb_DeadZone_l -= -RollYMotorSaturation;
  }

  /* End of DeadZone: '<S181>/DeadZone' */

  /* Gain: '<S185>/Integral Gain' */
  rtb_IntegralGain_e *= iyvelki;

  /* DeadZone: '<S131>/DeadZone' */
  if (rtb_DeadZone_k > TwoDOF_P.yPOSPID_UpperSaturationLimit) {
    rtb_DeadZone_k -= TwoDOF_P.yPOSPID_UpperSaturationLimit;
  } else if (rtb_DeadZone_k >= TwoDOF_P.yPOSPID_LowerSaturationLimit) {
    rtb_DeadZone_k = 0.0;
  } else {
    rtb_DeadZone_k -= TwoDOF_P.yPOSPID_LowerSaturationLimit;
  }

  /* End of DeadZone: '<S131>/DeadZone' */

  /* Gain: '<S135>/Integral Gain' */
  TwoDOF_B.IntegralGain_m *= iyposki;

  /* DeadZone: '<S81>/DeadZone' */
  if (TwoDOF_B.DeadZone_j > PitchXMotorSaturation) {
    TwoDOF_B.DeadZone_j -= PitchXMotorSaturation;
  } else if (TwoDOF_B.DeadZone_j >= -PitchXMotorSaturation) {
    TwoDOF_B.DeadZone_j = 0.0;
  } else {
    TwoDOF_B.DeadZone_j -= -PitchXMotorSaturation;
  }

  /* End of DeadZone: '<S81>/DeadZone' */

  /* Gain: '<S85>/Integral Gain' */
  TwoDOF_B.IntegralGain_g *= ixvelki;

  /* DeadZone: '<S31>/DeadZone' */
  if (TwoDOF_B.DeadZone > TwoDOF_P.xPOSPID_UpperSaturationLimit) {
    TwoDOF_B.DeadZone -= TwoDOF_P.xPOSPID_UpperSaturationLimit;
  } else if (TwoDOF_B.DeadZone >= TwoDOF_P.xPOSPID_LowerSaturationLimit) {
    TwoDOF_B.DeadZone = 0.0;
  } else {
    TwoDOF_B.DeadZone -= TwoDOF_P.xPOSPID_LowerSaturationLimit;
  }

  /* End of DeadZone: '<S31>/DeadZone' */

  /* Gain: '<S35>/Integral Gain' */
  TwoDOF_B.IntegralGain *= ixposki;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
   *  Sum: '<Root>/Sum1'
   */
  TwoDOF_DW.DiscreteTransferFcn1_states = ((TwoDOF_P.Constant1_Value_m -
    TwoDOF_DW.DiscreteTimeIntegrator_DSTATE) -
    TwoDOF_P.DiscreteTransferFcn1_DenCoef[1] *
    TwoDOF_DW.DiscreteTransferFcn1_states) /
    TwoDOF_P.DiscreteTransferFcn1_DenCoef[0];

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1'
   */
  TwoDOF_DW.DiscreteTimeIntegrator_DSTATE +=
    TwoDOF_P.DiscreteTimeIntegrator_gainval * TwoDOF_B.numAccum;

  /* Switch: '<S29>/Switch1' incorporates:
   *  Constant: '<S29>/Clamping_zero'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S29>/Constant2'
   *  RelationalOperator: '<S29>/fix for DT propagation issue'
   */
  if (TwoDOF_B.DeadZone > TwoDOF_P.Clamping_zero_Value_f) {
    tmp_1 = TwoDOF_P.Constant_Value_l;
  } else {
    tmp_1 = TwoDOF_P.Constant2_Value;
  }

  /* Switch: '<S29>/Switch2' incorporates:
   *  Constant: '<S29>/Clamping_zero'
   *  Constant: '<S29>/Constant3'
   *  Constant: '<S29>/Constant4'
   *  RelationalOperator: '<S29>/fix for DT propagation issue1'
   */
  if (TwoDOF_B.IntegralGain > TwoDOF_P.Clamping_zero_Value_f) {
    tmp_2 = TwoDOF_P.Constant3_Value;
  } else {
    tmp_2 = TwoDOF_P.Constant4_Value;
  }

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Clamping_zero'
   *  Constant: '<S29>/Constant1'
   *  Logic: '<S29>/AND3'
   *  RelationalOperator: '<S29>/Equal1'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  Switch: '<S29>/Switch1'
   *  Switch: '<S29>/Switch2'
   */
  if ((TwoDOF_P.Clamping_zero_Value_f != TwoDOF_B.DeadZone) && (tmp_1 == tmp_2))
  {
    TwoDOF_B.IntegralGain = TwoDOF_P.Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S38>/Integrator' incorporates:
   *  Switch: '<S29>/Switch'
   */
  TwoDOF_DW.Integrator_DSTATE += TwoDOF_P.Integrator_gainval *
    TwoDOF_B.IntegralGain;

  /* Update for DiscreteIntegrator: '<S33>/Filter' */
  TwoDOF_DW.Filter_DSTATE += TwoDOF_P.Filter_gainval *
    TwoDOF_B.FilterCoefficient;

  /* Switch: '<S79>/Switch1' incorporates:
   *  Constant: '<S79>/Clamping_zero'
   *  Constant: '<S79>/Constant'
   *  Constant: '<S79>/Constant2'
   *  RelationalOperator: '<S79>/fix for DT propagation issue'
   */
  if (TwoDOF_B.DeadZone_j > TwoDOF_P.Clamping_zero_Value_d) {
    tmp_1 = TwoDOF_P.Constant_Value_a;
  } else {
    tmp_1 = TwoDOF_P.Constant2_Value_b;
  }

  /* Switch: '<S79>/Switch2' incorporates:
   *  Constant: '<S79>/Clamping_zero'
   *  Constant: '<S79>/Constant3'
   *  Constant: '<S79>/Constant4'
   *  RelationalOperator: '<S79>/fix for DT propagation issue1'
   */
  if (TwoDOF_B.IntegralGain_g > TwoDOF_P.Clamping_zero_Value_d) {
    tmp_2 = TwoDOF_P.Constant3_Value_k;
  } else {
    tmp_2 = TwoDOF_P.Constant4_Value_o;
  }

  /* Switch: '<S79>/Switch' incorporates:
   *  Constant: '<S79>/Clamping_zero'
   *  Constant: '<S79>/Constant1'
   *  Logic: '<S79>/AND3'
   *  RelationalOperator: '<S79>/Equal1'
   *  RelationalOperator: '<S79>/Relational Operator'
   *  Switch: '<S79>/Switch1'
   *  Switch: '<S79>/Switch2'
   */
  if ((TwoDOF_P.Clamping_zero_Value_d != TwoDOF_B.DeadZone_j) && (tmp_1 == tmp_2))
  {
    TwoDOF_B.IntegralGain_g = TwoDOF_P.Constant1_Value_b;
  }

  /* Update for DiscreteIntegrator: '<S88>/Integrator' incorporates:
   *  Switch: '<S79>/Switch'
   */
  TwoDOF_DW.Integrator_DSTATE_m += TwoDOF_P.Integrator_gainval_i *
    TwoDOF_B.IntegralGain_g;

  /* Update for DiscreteIntegrator: '<S83>/Filter' */
  TwoDOF_DW.Filter_DSTATE_d += TwoDOF_P.Filter_gainval_p *
    TwoDOF_B.FilterCoefficient_k;

  /* Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' incorporates:
   *  Constant: '<Root>/Constant'
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
   *  Sum: '<Root>/Sum'
   */
  TwoDOF_DW.DiscreteTransferFcn_states = ((TwoDOF_P.Constant_Value -
    TwoDOF_DW.DiscreteTimeIntegrator1_DSTATE) -
    TwoDOF_P.DiscreteTransferFcn_DenCoef[1] *
    TwoDOF_DW.DiscreteTransferFcn_states) /
    TwoDOF_P.DiscreteTransferFcn_DenCoef[0];

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
   *  DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn'
   */
  TwoDOF_DW.DiscreteTimeIntegrator1_DSTATE +=
    TwoDOF_P.DiscreteTimeIntegrator1_gainval * TwoDOF_B.numAccum_m;

  /* Switch: '<S129>/Switch1' incorporates:
   *  Constant: '<S129>/Clamping_zero'
   *  Constant: '<S129>/Constant'
   *  Constant: '<S129>/Constant2'
   *  RelationalOperator: '<S129>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_k > TwoDOF_P.Clamping_zero_Value_a) {
    tmp_1 = TwoDOF_P.Constant_Value_p;
  } else {
    tmp_1 = TwoDOF_P.Constant2_Value_c;
  }

  /* Switch: '<S129>/Switch2' incorporates:
   *  Constant: '<S129>/Clamping_zero'
   *  Constant: '<S129>/Constant3'
   *  Constant: '<S129>/Constant4'
   *  RelationalOperator: '<S129>/fix for DT propagation issue1'
   */
  if (TwoDOF_B.IntegralGain_m > TwoDOF_P.Clamping_zero_Value_a) {
    tmp_2 = TwoDOF_P.Constant3_Value_e;
  } else {
    tmp_2 = TwoDOF_P.Constant4_Value_k;
  }

  /* Switch: '<S129>/Switch' incorporates:
   *  Constant: '<S129>/Clamping_zero'
   *  Constant: '<S129>/Constant1'
   *  Logic: '<S129>/AND3'
   *  RelationalOperator: '<S129>/Equal1'
   *  RelationalOperator: '<S129>/Relational Operator'
   *  Switch: '<S129>/Switch1'
   *  Switch: '<S129>/Switch2'
   */
  if ((TwoDOF_P.Clamping_zero_Value_a != rtb_DeadZone_k) && (tmp_1 == tmp_2)) {
    TwoDOF_B.IntegralGain_m = TwoDOF_P.Constant1_Value_e;
  }

  /* Update for DiscreteIntegrator: '<S138>/Integrator' incorporates:
   *  Switch: '<S129>/Switch'
   */
  TwoDOF_DW.Integrator_DSTATE_mi += TwoDOF_P.Integrator_gainval_e *
    TwoDOF_B.IntegralGain_m;

  /* Update for DiscreteIntegrator: '<S133>/Filter' */
  TwoDOF_DW.Filter_DSTATE_dy += TwoDOF_P.Filter_gainval_j *
    rtb_FilterCoefficient_ln;

  /* Switch: '<S179>/Switch1' incorporates:
   *  Constant: '<S179>/Clamping_zero'
   *  Constant: '<S179>/Constant'
   *  Constant: '<S179>/Constant2'
   *  RelationalOperator: '<S179>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_l > TwoDOF_P.Clamping_zero_Value) {
    tmp_1 = TwoDOF_P.Constant_Value_n;
  } else {
    tmp_1 = TwoDOF_P.Constant2_Value_o;
  }

  /* Switch: '<S179>/Switch2' incorporates:
   *  Constant: '<S179>/Clamping_zero'
   *  Constant: '<S179>/Constant3'
   *  Constant: '<S179>/Constant4'
   *  RelationalOperator: '<S179>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain_e > TwoDOF_P.Clamping_zero_Value) {
    tmp_2 = TwoDOF_P.Constant3_Value_b;
  } else {
    tmp_2 = TwoDOF_P.Constant4_Value_oh;
  }

  /* Switch: '<S179>/Switch' incorporates:
   *  Constant: '<S179>/Clamping_zero'
   *  Constant: '<S179>/Constant1'
   *  Logic: '<S179>/AND3'
   *  RelationalOperator: '<S179>/Equal1'
   *  RelationalOperator: '<S179>/Relational Operator'
   *  Switch: '<S179>/Switch1'
   *  Switch: '<S179>/Switch2'
   */
  if ((TwoDOF_P.Clamping_zero_Value != rtb_DeadZone_l) && (tmp_1 == tmp_2)) {
    rtb_IntegralGain_e = TwoDOF_P.Constant1_Value_c;
  }

  /* Update for DiscreteIntegrator: '<S188>/Integrator' incorporates:
   *  Switch: '<S179>/Switch'
   */
  TwoDOF_DW.Integrator_DSTATE_i += TwoDOF_P.Integrator_gainval_b *
    rtb_IntegralGain_e;

  /* Update for DiscreteIntegrator: '<S183>/Filter' */
  TwoDOF_DW.Filter_DSTATE_k += TwoDOF_P.Filter_gainval_i *
    rtb_FilterCoefficient_c;
}

/* Model initialize function */
void TwoDOF_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn1' */
  TwoDOF_DW.DiscreteTransferFcn1_states =
    TwoDOF_P.DiscreteTransferFcn1_InitialSta;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  TwoDOF_DW.DiscreteTimeIntegrator_DSTATE = TwoDOF_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Integrator' */
  TwoDOF_DW.Integrator_DSTATE = TwoDOF_P.xPOSPID_InitialConditionForInte;

  /* InitializeConditions for DiscreteIntegrator: '<S33>/Filter' */
  TwoDOF_DW.Filter_DSTATE = TwoDOF_P.xPOSPID_InitialConditionForFilt;

  /* InitializeConditions for DiscreteIntegrator: '<S88>/Integrator' */
  TwoDOF_DW.Integrator_DSTATE_m = TwoDOF_P.xVELPID_InitialConditionForInte;

  /* InitializeConditions for DiscreteIntegrator: '<S83>/Filter' */
  TwoDOF_DW.Filter_DSTATE_d = TwoDOF_P.xVELPID_InitialConditionForFilt;

  /* InitializeConditions for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' */
  TwoDOF_DW.DiscreteTransferFcn_states =
    TwoDOF_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  TwoDOF_DW.DiscreteTimeIntegrator1_DSTATE = TwoDOF_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Integrator' */
  TwoDOF_DW.Integrator_DSTATE_mi = TwoDOF_P.yPOSPID_InitialConditionForInte;

  /* InitializeConditions for DiscreteIntegrator: '<S133>/Filter' */
  TwoDOF_DW.Filter_DSTATE_dy = TwoDOF_P.yPOSPID_InitialConditionForFilt;

  /* InitializeConditions for DiscreteIntegrator: '<S188>/Integrator' */
  TwoDOF_DW.Integrator_DSTATE_i = TwoDOF_P.yVELPID_InitialConditionForInte;

  /* InitializeConditions for DiscreteIntegrator: '<S183>/Filter' */
  TwoDOF_DW.Filter_DSTATE_k = TwoDOF_P.yVELPID_InitialConditionForFilt;

  /* Start for MATLABSystem: '<Root>/MATLAB System1' */
  /*  Constructor */
  TwoDOF_DW.obj_i.matlabCodegenIsDeleted = false;
  TwoDOF_DW.obj_i.SampleTime = TwoDOF_P.MATLABSystem1_SampleTime;
  TwoDOF_DW.obj_i.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionIMU();
  TwoDOF_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/MATLAB System' */
  /*  Constructor */
  TwoDOF_DW.obj.matlabCodegenIsDeleted = false;
  TwoDOF_DW.obj.SampleTime = TwoDOF_P.MATLABSystem_SampleTime;
  TwoDOF_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionEncoders();
  TwoDOF_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/MATLAB System2' */
  /*  Constructor */
  TwoDOF_DW.obj_g.matlabCodegenIsDeleted = false;
  TwoDOF_DW.obj_g.SampleTime = TwoDOF_P.MATLABSystem2_SampleTime;
  TwoDOF_DW.obj_g.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionMotors_Propellers();
  TwoDOF_DW.obj_g.isSetupComplete = true;
}

/* Model terminate function */
void TwoDOF_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System1' */
  if (!TwoDOF_DW.obj_i.matlabCodegenIsDeleted) {
    TwoDOF_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System1' */

  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!TwoDOF_DW.obj.matlabCodegenIsDeleted) {
    TwoDOF_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */

  /* Terminate for MATLABSystem: '<Root>/MATLAB System2' */
  if (!TwoDOF_DW.obj_g.matlabCodegenIsDeleted) {
    TwoDOF_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System2' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
