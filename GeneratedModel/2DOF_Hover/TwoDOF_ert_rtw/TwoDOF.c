#include "TwoDOF.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

DW_TwoDOF_T TwoDOF_DW;
ExtU_TwoDOF_T TwoDOF_U;
ExtY_TwoDOF_T TwoDOF_Y;
static RT_MODEL_TwoDOF_T TwoDOF_M_;
RT_MODEL_TwoDOF_T *const TwoDOF_M = &TwoDOF_M_;
void TwoDOF_step(void)
{
  double Add17;
  double Add18;
  double Add21;
  double Add22;
  double Sum;
  double Sum1;
  double numAccum;
  double numAccum_0;
  double numAccum_1;
  double numAccum_2;
  double rtb_Cos;
  double rtb_Filter;
  double rtb_FilterCoefficient;
  double rtb_FilterCoefficient_b;
  double rtb_FilterCoefficient_d;
  double rtb_FilterCoefficient_h;
  double rtb_Filter_b;
  double rtb_Filter_m;
  double rtb_Switch_b;
  int8_t tmp;
  int8_t tmp_0;
  int8_t tmp_1;
  int8_t tmp_2;
  bool rtb_AND3_p;
  bool rtb_RelationalOperator;
  bool rtb_RelationalOperator_m;
  Add17 = RollYStartThrust - TwoDOF_Y.Y_velPID_ControlAction;
  Add18 = RollYStartThrust + TwoDOF_Y.Y_velPID_ControlAction;
  rtb_Filter_m = TwoDOF_DW.DiscreteTimeIntegrator1_DSTATE -
    TwoDOF_DW.Delay1_DSTATE[0];
  rtb_Filter = iyposki * rtb_Filter_m;
  rtb_FilterCoefficient = (iyposkd * rtb_Filter_m - TwoDOF_DW.Filter_DSTATE) *
    FilterCoeffN;
  TwoDOF_Y.Y_posPID_ControlAction = (iyposkp * rtb_Filter_m +
    TwoDOF_DW.Integrator_DSTATE) + rtb_FilterCoefficient;
  if (TwoDOF_Y.Y_posPID_ControlAction > 1.0) {
    rtb_Filter_m = TwoDOF_Y.Y_posPID_ControlAction - 1.0;
    tmp = 1;
  } else {
    if (TwoDOF_Y.Y_posPID_ControlAction >= -1.0) {
      rtb_Filter_m = 0.0;
    } else {
      rtb_Filter_m = TwoDOF_Y.Y_posPID_ControlAction - -1.0;
    }

    tmp = -1;
  }

  rtb_RelationalOperator = (rtb_Filter_m != 0.0);
  if (TwoDOF_Y.Y_posPID_ControlAction > 1.0) {
    TwoDOF_Y.Y_posPID_ControlAction = 1.0;
  } else if (TwoDOF_Y.Y_posPID_ControlAction < -1.0) {
    TwoDOF_Y.Y_posPID_ControlAction = -1.0;
  }

  numAccum = 0.0165 * TwoDOF_DW.DiscreteTransferFcn_states;
  rtb_Filter_m = (numAccum + TwoDOF_Y.Y_posPID_ControlAction) -
    TwoDOF_DW.Delay_DSTATE[0];
  rtb_FilterCoefficient_d = (iyvelkd * rtb_Filter_m - TwoDOF_DW.Filter_DSTATE_p)
    * FilterCoeffN;
  TwoDOF_Y.Y_velPID_ControlAction = (iyvelkp * rtb_Filter_m +
    TwoDOF_DW.Integrator_DSTATE_h) + rtb_FilterCoefficient_d;
  if (TwoDOF_Y.Y_velPID_ControlAction > RollYMotorSaturation) {
    rtb_Filter_b = TwoDOF_Y.Y_velPID_ControlAction - RollYMotorSaturation;
  } else if (TwoDOF_Y.Y_velPID_ControlAction >= -RollYMotorSaturation) {
    rtb_Filter_b = 0.0;
  } else {
    rtb_Filter_b = TwoDOF_Y.Y_velPID_ControlAction - (-RollYMotorSaturation);
  }

  rtb_Filter_m *= iyvelki;
  if (rtb_Filter_b > 0.0) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  if (rtb_Filter_m > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  if ((rtb_Filter_b != 0.0) && (tmp_0 == tmp_1)) {
    rtb_Switch_b = 0.0;
  } else {
    rtb_Switch_b = rtb_Filter_m;
  }

  if (TwoDOF_Y.Y_velPID_ControlAction > RollYMotorSaturation) {
    TwoDOF_Y.Y_velPID_ControlAction = RollYMotorSaturation;
  } else if (TwoDOF_Y.Y_velPID_ControlAction < -RollYMotorSaturation) {
    TwoDOF_Y.Y_velPID_ControlAction = -RollYMotorSaturation;
  }

  Sum = TwoDOF_U.Y_setpoint - TwoDOF_DW.DiscreteTimeIntegrator1_DSTATE;
  Add21 = PitchXStartThrust - TwoDOF_Y.X_velPID_ControlAction;
  Add22 = PitchXStartThrust + TwoDOF_Y.X_velPID_ControlAction;
  rtb_Filter_b = TwoDOF_DW.DiscreteTimeIntegrator_DSTATE -
    TwoDOF_DW.Delay3_DSTATE[0];
  rtb_Filter_m = ixposki * rtb_Filter_b;
  rtb_FilterCoefficient_h = (ixposkd * rtb_Filter_b - TwoDOF_DW.Filter_DSTATE_m)
    * FilterCoeffN;
  TwoDOF_Y.X_posPID_ControlAction = (ixposkp * rtb_Filter_b +
    TwoDOF_DW.Integrator_DSTATE_o) + rtb_FilterCoefficient_h;
  if (TwoDOF_Y.X_posPID_ControlAction > 1.0) {
    rtb_Filter_b = TwoDOF_Y.X_posPID_ControlAction - 1.0;
    tmp_0 = 1;
  } else {
    if (TwoDOF_Y.X_posPID_ControlAction >= -1.0) {
      rtb_Filter_b = 0.0;
    } else {
      rtb_Filter_b = TwoDOF_Y.X_posPID_ControlAction - -1.0;
    }

    tmp_0 = -1;
  }

  rtb_RelationalOperator_m = (rtb_Filter_b != 0.0);
  if (TwoDOF_Y.X_posPID_ControlAction > 1.0) {
    TwoDOF_Y.X_posPID_ControlAction = 1.0;
  } else if (TwoDOF_Y.X_posPID_ControlAction < -1.0) {
    TwoDOF_Y.X_posPID_ControlAction = -1.0;
  }

  numAccum_0 = 0.0165 * TwoDOF_DW.DiscreteTransferFcn1_states;
  rtb_Filter_b = (numAccum_0 + TwoDOF_Y.X_posPID_ControlAction) -
    TwoDOF_DW.Delay2_DSTATE[0];
  rtb_FilterCoefficient_b = (ixvelkd * rtb_Filter_b - TwoDOF_DW.Filter_DSTATE_h)
    * FilterCoeffN;
  TwoDOF_Y.X_velPID_ControlAction = (ixvelkp * rtb_Filter_b +
    TwoDOF_DW.Integrator_DSTATE_b) + rtb_FilterCoefficient_b;
  if (TwoDOF_Y.X_velPID_ControlAction > PitchXMotorSaturation) {
    rtb_Cos = TwoDOF_Y.X_velPID_ControlAction - PitchXMotorSaturation;
  } else if (TwoDOF_Y.X_velPID_ControlAction >= -PitchXMotorSaturation) {
    rtb_Cos = 0.0;
  } else {
    rtb_Cos = TwoDOF_Y.X_velPID_ControlAction - (-PitchXMotorSaturation);
  }

  rtb_Filter_b *= ixvelki;
  if (rtb_Cos > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  if (rtb_Filter_b > 0.0) {
    tmp_2 = 1;
  } else {
    tmp_2 = -1;
  }

  rtb_AND3_p = ((rtb_Cos != 0.0) && (tmp_1 == tmp_2));
  if (TwoDOF_Y.X_velPID_ControlAction > PitchXMotorSaturation) {
    TwoDOF_Y.X_velPID_ControlAction = PitchXMotorSaturation;
  } else if (TwoDOF_Y.X_velPID_ControlAction < -PitchXMotorSaturation) {
    TwoDOF_Y.X_velPID_ControlAction = -PitchXMotorSaturation;
  }

  Sum1 = TwoDOF_U.X_setpoint - TwoDOF_DW.DiscreteTimeIntegrator_DSTATE;
  TwoDOF_Y.thetaYDot = TwoDOF_DW.DiscreteTimeIntegrator4_DSTATE;
  TwoDOF_Y.thetaY = TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE;
  rtb_Cos = cos(TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE);
  numAccum_1 = 0.00634 * TwoDOF_DW.LeftMotor_states;
  numAccum_2 = 0.00634 * TwoDOF_DW.RightMotor_states;
  TwoDOF_Y.thetaXDot = TwoDOF_DW.DiscreteTimeIntegrator5_DSTATE;
  TwoDOF_Y.thetaX = TwoDOF_DW.DiscreteTimeIntegrator2_DSTATE;
  TwoDOF_DW.DiscreteTimeIntegrator1_DSTATE += 0.005 * numAccum;
  if (rtb_Filter > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  if (rtb_RelationalOperator && (tmp == tmp_1)) {
    rtb_Filter = 0.0;
  }

  TwoDOF_DW.Integrator_DSTATE += 0.005 * rtb_Filter;
  TwoDOF_DW.Filter_DSTATE += 0.005 * rtb_FilterCoefficient;
  TwoDOF_DW.DiscreteTransferFcn_states = Sum - -0.9835 *
    TwoDOF_DW.DiscreteTransferFcn_states;
  TwoDOF_DW.Integrator_DSTATE_h += 0.005 * rtb_Switch_b;
  TwoDOF_DW.Filter_DSTATE_p += 0.005 * rtb_FilterCoefficient_d;
  TwoDOF_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * numAccum_0;
  if (rtb_Filter_m > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (rtb_RelationalOperator_m && (tmp_0 == tmp)) {
    rtb_Filter_m = 0.0;
  }

  TwoDOF_DW.Integrator_DSTATE_o += 0.005 * rtb_Filter_m;
  TwoDOF_DW.Filter_DSTATE_m += 0.005 * rtb_FilterCoefficient_h;
  TwoDOF_DW.Delay1_DSTATE[0] = TwoDOF_DW.Delay1_DSTATE[1];
  TwoDOF_DW.Delay_DSTATE[0] = TwoDOF_DW.Delay_DSTATE[1];
  TwoDOF_DW.Delay3_DSTATE[0] = TwoDOF_DW.Delay3_DSTATE[1];
  TwoDOF_DW.Delay2_DSTATE[0] = TwoDOF_DW.Delay2_DSTATE[1];
  TwoDOF_DW.Delay1_DSTATE[1] = TwoDOF_DW.Delay1_DSTATE[2];
  TwoDOF_DW.Delay_DSTATE[1] = TwoDOF_DW.Delay_DSTATE[2];
  TwoDOF_DW.Delay3_DSTATE[1] = TwoDOF_DW.Delay3_DSTATE[2];
  TwoDOF_DW.Delay2_DSTATE[1] = TwoDOF_DW.Delay2_DSTATE[2];
  TwoDOF_DW.Delay1_DSTATE[2] = TwoDOF_DW.Delay1_DSTATE[3];
  TwoDOF_DW.Delay_DSTATE[2] = TwoDOF_DW.Delay_DSTATE[3];
  TwoDOF_DW.Delay3_DSTATE[2] = TwoDOF_DW.Delay3_DSTATE[3];
  TwoDOF_DW.Delay2_DSTATE[2] = TwoDOF_DW.Delay2_DSTATE[3];
  TwoDOF_DW.Delay1_DSTATE[3] = TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE;
  TwoDOF_DW.Delay_DSTATE[3] = TwoDOF_DW.DiscreteTimeIntegrator4_DSTATE;
  TwoDOF_DW.Delay3_DSTATE[3] = TwoDOF_DW.DiscreteTimeIntegrator2_DSTATE;
  TwoDOF_DW.Delay2_DSTATE[3] = TwoDOF_DW.DiscreteTimeIntegrator5_DSTATE;
  TwoDOF_DW.DiscreteTransferFcn1_states = Sum1 - -0.9835 *
    TwoDOF_DW.DiscreteTransferFcn1_states;
  if (rtb_AND3_p) {
    rtb_Filter_b = 0.0;
  }

  TwoDOF_DW.Integrator_DSTATE_b += 0.005 * rtb_Filter_b;
  TwoDOF_DW.Filter_DSTATE_h += 0.005 * rtb_FilterCoefficient_b;
  TwoDOF_DW.DiscreteTimeIntegrator4_DSTATE += ((mass_u * g * L_cg_u * sin
    (TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE) - B_u *
    TwoDOF_DW.DiscreteTimeIntegrator4_DSTATE) + (0.00634 *
    TwoDOF_DW.BackMotor_states - 0.00634 * TwoDOF_DW.FrontMotor_states) * L_u) *
    (1.0 / J_u) * 0.005;
  TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE += 0.005 * TwoDOF_Y.thetaYDot;
  if (TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE > RollUpperLimit) {
    TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE = RollUpperLimit;
  } else if (TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE < RollLowerLimit) {
    TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE = RollLowerLimit;
  }

  TwoDOF_DW.FrontMotor_states = Add17 - -0.9512 * TwoDOF_DW.FrontMotor_states;
  TwoDOF_DW.BackMotor_states = Add18 - -0.9512 * TwoDOF_DW.BackMotor_states;
  TwoDOF_DW.LeftMotor_states = Add21 - -0.9512 * TwoDOF_DW.LeftMotor_states;
  TwoDOF_DW.RightMotor_states = Add22 - -0.9512 * TwoDOF_DW.RightMotor_states;
  TwoDOF_DW.DiscreteTimeIntegrator5_DSTATE += ((mass_l * g * L_cg_l * sin
    (TwoDOF_DW.DiscreteTimeIntegrator2_DSTATE) - B_l *
    TwoDOF_DW.DiscreteTimeIntegrator5_DSTATE) + (numAccum_2 * rtb_Cos -
    numAccum_1 * rtb_Cos) * L_l) * (1.0 / J_l) * 0.005;
  TwoDOF_DW.DiscreteTimeIntegrator2_DSTATE += 0.005 * TwoDOF_Y.thetaXDot;
  if (TwoDOF_DW.DiscreteTimeIntegrator2_DSTATE > PitchUpperLimit) {
    TwoDOF_DW.DiscreteTimeIntegrator2_DSTATE = PitchUpperLimit;
  } else if (TwoDOF_DW.DiscreteTimeIntegrator2_DSTATE < PitchLowerLimit) {
    TwoDOF_DW.DiscreteTimeIntegrator2_DSTATE = PitchLowerLimit;
  }
}

void TwoDOF_initialize(void)
{
  TwoDOF_DW.DiscreteTimeIntegrator3_DSTATE = JointY_InitialPositionCondition;
  TwoDOF_DW.DiscreteTimeIntegrator2_DSTATE = JointX_InitialPositionCondition;
}

void TwoDOF_terminate(void)
{
}
