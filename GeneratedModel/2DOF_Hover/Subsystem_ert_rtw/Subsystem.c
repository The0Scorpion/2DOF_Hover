#include "Subsystem.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

DW_Subsystem_T Subsystem_DW;
ExtU_Subsystem_T Subsystem_U;
ExtY_Subsystem_T Subsystem_Y;
static RT_MODEL_Subsystem_T Subsystem_M_;
RT_MODEL_Subsystem_T *const Subsystem_M = &Subsystem_M_;
void Subsystem_step(void)
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
  Add17 = RollYStartThrust - Subsystem_Y.Y_velPID_ControlAction;
  Add18 = RollYStartThrust + Subsystem_Y.Y_velPID_ControlAction;
  rtb_Filter_m = Subsystem_DW.DiscreteTimeIntegrator1_DSTATE -
    Subsystem_DW.Delay1_DSTATE[0];
  rtb_Filter = iyposki * rtb_Filter_m;
  rtb_FilterCoefficient = (iyposkd * rtb_Filter_m - Subsystem_DW.Filter_DSTATE) *
    FilterCoeffN;
  Subsystem_Y.Y_posPID_ControlAction = (iyposkp * rtb_Filter_m +
    Subsystem_DW.Integrator_DSTATE) + rtb_FilterCoefficient;
  if (Subsystem_Y.Y_posPID_ControlAction > 1.0) {
    rtb_Filter_m = Subsystem_Y.Y_posPID_ControlAction - 1.0;
    tmp = 1;
  } else {
    if (Subsystem_Y.Y_posPID_ControlAction >= -1.0) {
      rtb_Filter_m = 0.0;
    } else {
      rtb_Filter_m = Subsystem_Y.Y_posPID_ControlAction - -1.0;
    }

    tmp = -1;
  }

  rtb_RelationalOperator = (rtb_Filter_m != 0.0);
  if (Subsystem_Y.Y_posPID_ControlAction > 1.0) {
    Subsystem_Y.Y_posPID_ControlAction = 1.0;
  } else if (Subsystem_Y.Y_posPID_ControlAction < -1.0) {
    Subsystem_Y.Y_posPID_ControlAction = -1.0;
  }

  numAccum = 0.0165 * Subsystem_DW.DiscreteTransferFcn_states;
  rtb_Filter_m = (numAccum + Subsystem_Y.Y_posPID_ControlAction) -
    Subsystem_DW.Delay_DSTATE[0];
  rtb_FilterCoefficient_d = (iyvelkd * rtb_Filter_m -
    Subsystem_DW.Filter_DSTATE_p) * FilterCoeffN;
  Subsystem_Y.Y_velPID_ControlAction = (iyvelkp * rtb_Filter_m +
    Subsystem_DW.Integrator_DSTATE_h) + rtb_FilterCoefficient_d;
  if (Subsystem_Y.Y_velPID_ControlAction > RollYMotorSaturation) {
    rtb_Filter_b = Subsystem_Y.Y_velPID_ControlAction - RollYMotorSaturation;
  } else if (Subsystem_Y.Y_velPID_ControlAction >= -RollYMotorSaturation) {
    rtb_Filter_b = 0.0;
  } else {
    rtb_Filter_b = Subsystem_Y.Y_velPID_ControlAction - (-RollYMotorSaturation);
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

  if (Subsystem_Y.Y_velPID_ControlAction > RollYMotorSaturation) {
    Subsystem_Y.Y_velPID_ControlAction = RollYMotorSaturation;
  } else if (Subsystem_Y.Y_velPID_ControlAction < -RollYMotorSaturation) {
    Subsystem_Y.Y_velPID_ControlAction = -RollYMotorSaturation;
  }

  Sum = Subsystem_U.target - Subsystem_DW.DiscreteTimeIntegrator1_DSTATE;
  Add21 = PitchXStartThrust - Subsystem_Y.X_velPID_ControlAction;
  Add22 = PitchXStartThrust + Subsystem_Y.X_velPID_ControlAction;
  rtb_Filter_b = Subsystem_DW.DiscreteTimeIntegrator_DSTATE -
    Subsystem_DW.Delay3_DSTATE[0];
  rtb_Filter_m = ixposki * rtb_Filter_b;
  rtb_FilterCoefficient_h = (ixposkd * rtb_Filter_b -
    Subsystem_DW.Filter_DSTATE_m) * FilterCoeffN;
  Subsystem_Y.X_posPID_ControlAction = (ixposkp * rtb_Filter_b +
    Subsystem_DW.Integrator_DSTATE_o) + rtb_FilterCoefficient_h;
  if (Subsystem_Y.X_posPID_ControlAction > 1.0) {
    rtb_Filter_b = Subsystem_Y.X_posPID_ControlAction - 1.0;
    tmp_0 = 1;
  } else {
    if (Subsystem_Y.X_posPID_ControlAction >= -1.0) {
      rtb_Filter_b = 0.0;
    } else {
      rtb_Filter_b = Subsystem_Y.X_posPID_ControlAction - -1.0;
    }

    tmp_0 = -1;
  }

  rtb_RelationalOperator_m = (rtb_Filter_b != 0.0);
  if (Subsystem_Y.X_posPID_ControlAction > 1.0) {
    Subsystem_Y.X_posPID_ControlAction = 1.0;
  } else if (Subsystem_Y.X_posPID_ControlAction < -1.0) {
    Subsystem_Y.X_posPID_ControlAction = -1.0;
  }

  numAccum_0 = 0.0165 * Subsystem_DW.DiscreteTransferFcn1_states;
  rtb_Filter_b = (numAccum_0 + Subsystem_Y.X_posPID_ControlAction) -
    Subsystem_DW.Delay2_DSTATE[0];
  rtb_FilterCoefficient_b = (ixvelkd * rtb_Filter_b -
    Subsystem_DW.Filter_DSTATE_h) * FilterCoeffN;
  Subsystem_Y.X_velPID_ControlAction = (ixvelkp * 0.4 * rtb_Filter_b +
    Subsystem_DW.Integrator_DSTATE_b) + rtb_FilterCoefficient_b;
  if (Subsystem_Y.X_velPID_ControlAction > PitchXMotorSaturation) {
    rtb_Cos = Subsystem_Y.X_velPID_ControlAction - PitchXMotorSaturation;
  } else if (Subsystem_Y.X_velPID_ControlAction >= -PitchXMotorSaturation) {
    rtb_Cos = 0.0;
  } else {
    rtb_Cos = Subsystem_Y.X_velPID_ControlAction - (-PitchXMotorSaturation);
  }

  rtb_Filter_b *= ixvelki * 0.4;
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
  if (Subsystem_Y.X_velPID_ControlAction > PitchXMotorSaturation) {
    Subsystem_Y.X_velPID_ControlAction = PitchXMotorSaturation;
  } else if (Subsystem_Y.X_velPID_ControlAction < -PitchXMotorSaturation) {
    Subsystem_Y.X_velPID_ControlAction = -PitchXMotorSaturation;
  }

  Sum1 = Subsystem_U.In2 - Subsystem_DW.DiscreteTimeIntegrator_DSTATE;
  Subsystem_Y.thetaY = Subsystem_DW.DiscreteTimeIntegrator4_DSTATE;
  Subsystem_Y.thetaY_h = Subsystem_DW.DiscreteTimeIntegrator3_DSTATE;
  rtb_Cos = cos(Subsystem_DW.DiscreteTimeIntegrator3_DSTATE);
  numAccum_1 = 0.00634 * Subsystem_DW.LeftMotor_states;
  numAccum_2 = 0.00634 * Subsystem_DW.RightMotor_states;
  Subsystem_Y.thetaX_j = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE;
  Subsystem_Y.thetaX = Subsystem_DW.DiscreteTimeIntegrator2_DSTATE;
  Subsystem_DW.DiscreteTimeIntegrator1_DSTATE += 0.005 * numAccum;
  if (rtb_Filter > 0.0) {
    tmp_1 = 1;
  } else {
    tmp_1 = -1;
  }

  if (rtb_RelationalOperator && (tmp == tmp_1)) {
    rtb_Filter = 0.0;
  }

  Subsystem_DW.Integrator_DSTATE += 0.005 * rtb_Filter;
  Subsystem_DW.Filter_DSTATE += 0.005 * rtb_FilterCoefficient;
  Subsystem_DW.DiscreteTransferFcn_states = Sum - 0.9835 *
    Subsystem_DW.DiscreteTransferFcn_states;
  Subsystem_DW.Integrator_DSTATE_h += 0.005 * rtb_Switch_b;
  Subsystem_DW.Filter_DSTATE_p += 0.005 * rtb_FilterCoefficient_d;
  Subsystem_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * numAccum_0;
  if (rtb_Filter_m > 0.0) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  if (rtb_RelationalOperator_m && (tmp_0 == tmp)) {
    rtb_Filter_m = 0.0;
  }

  Subsystem_DW.Integrator_DSTATE_o += 0.005 * rtb_Filter_m;
  Subsystem_DW.Filter_DSTATE_m += 0.005 * rtb_FilterCoefficient_h;
  Subsystem_DW.Delay1_DSTATE[0] = Subsystem_DW.Delay1_DSTATE[1];
  Subsystem_DW.Delay_DSTATE[0] = Subsystem_DW.Delay_DSTATE[1];
  Subsystem_DW.Delay3_DSTATE[0] = Subsystem_DW.Delay3_DSTATE[1];
  Subsystem_DW.Delay2_DSTATE[0] = Subsystem_DW.Delay2_DSTATE[1];
  Subsystem_DW.Delay1_DSTATE[1] = Subsystem_DW.Delay1_DSTATE[2];
  Subsystem_DW.Delay_DSTATE[1] = Subsystem_DW.Delay_DSTATE[2];
  Subsystem_DW.Delay3_DSTATE[1] = Subsystem_DW.Delay3_DSTATE[2];
  Subsystem_DW.Delay2_DSTATE[1] = Subsystem_DW.Delay2_DSTATE[2];
  Subsystem_DW.Delay1_DSTATE[2] = Subsystem_DW.Delay1_DSTATE[3];
  Subsystem_DW.Delay_DSTATE[2] = Subsystem_DW.Delay_DSTATE[3];
  Subsystem_DW.Delay3_DSTATE[2] = Subsystem_DW.Delay3_DSTATE[3];
  Subsystem_DW.Delay2_DSTATE[2] = Subsystem_DW.Delay2_DSTATE[3];
  Subsystem_DW.Delay1_DSTATE[3] = Subsystem_DW.DiscreteTimeIntegrator3_DSTATE;
  Subsystem_DW.Delay_DSTATE[3] = Subsystem_DW.DiscreteTimeIntegrator4_DSTATE;
  Subsystem_DW.Delay3_DSTATE[3] = Subsystem_DW.DiscreteTimeIntegrator2_DSTATE;
  Subsystem_DW.Delay2_DSTATE[3] = Subsystem_DW.DiscreteTimeIntegrator5_DSTATE;
  Subsystem_DW.DiscreteTransferFcn1_states = Sum1 - 0.9835 *
    Subsystem_DW.DiscreteTransferFcn1_states;
  if (rtb_AND3_p) {
    rtb_Filter_b = 0.0;
  }

  Subsystem_DW.Integrator_DSTATE_b += 0.005 * rtb_Filter_b;
  Subsystem_DW.Filter_DSTATE_h += 0.005 * rtb_FilterCoefficient_b;
  Subsystem_DW.DiscreteTimeIntegrator4_DSTATE += ((mass_u * g * L_cg_u * sin
    (Subsystem_DW.DiscreteTimeIntegrator3_DSTATE) - B_u *
    Subsystem_DW.DiscreteTimeIntegrator4_DSTATE) + (0.00634 *
    Subsystem_DW.BackMotor_states - 0.00634 * Subsystem_DW.FrontMotor_states) *
    L_u) * (1.0 / J_u) * 0.005;
  Subsystem_DW.DiscreteTimeIntegrator3_DSTATE += 0.005 * Subsystem_Y.thetaY;
  if (Subsystem_DW.DiscreteTimeIntegrator3_DSTATE > RollUpperLimit) {
    Subsystem_DW.DiscreteTimeIntegrator3_DSTATE = RollUpperLimit;
  } else if (Subsystem_DW.DiscreteTimeIntegrator3_DSTATE < RollLowerLimit) {
    Subsystem_DW.DiscreteTimeIntegrator3_DSTATE = RollLowerLimit;
  }

  Subsystem_DW.FrontMotor_states = Add17 - -0.9512 *
    Subsystem_DW.FrontMotor_states;
  Subsystem_DW.BackMotor_states = Add18 - -0.9512 *
    Subsystem_DW.BackMotor_states;
  Subsystem_DW.LeftMotor_states = Add21 - -0.9512 *
    Subsystem_DW.LeftMotor_states;
  Subsystem_DW.RightMotor_states = Add22 - -0.9512 *
    Subsystem_DW.RightMotor_states;
  Subsystem_DW.DiscreteTimeIntegrator5_DSTATE += ((mass_l * g * L_cg_l * sin
    (Subsystem_DW.DiscreteTimeIntegrator2_DSTATE) - B_l *
    Subsystem_DW.DiscreteTimeIntegrator5_DSTATE) + (numAccum_2 * rtb_Cos -
    numAccum_1 * rtb_Cos) * L_l) * (1.0 / J_l) * 0.005;
  Subsystem_DW.DiscreteTimeIntegrator2_DSTATE += 0.005 * Subsystem_Y.thetaX_j;
  if (Subsystem_DW.DiscreteTimeIntegrator2_DSTATE > PitchUpperLimit) {
    Subsystem_DW.DiscreteTimeIntegrator2_DSTATE = PitchUpperLimit;
  } else if (Subsystem_DW.DiscreteTimeIntegrator2_DSTATE < PitchLowerLimit) {
    Subsystem_DW.DiscreteTimeIntegrator2_DSTATE = PitchLowerLimit;
  }
}

void Subsystem_initialize(void)
{
  Subsystem_DW.DiscreteTimeIntegrator3_DSTATE = JointY_InitialPositionCondition;
  Subsystem_DW.DiscreteTimeIntegrator2_DSTATE = JointX_InitialPositionCondition;
}

void Subsystem_terminate(void)
{
}
