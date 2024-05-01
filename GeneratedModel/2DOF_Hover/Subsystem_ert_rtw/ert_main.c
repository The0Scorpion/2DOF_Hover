#include <stddef.h>
#include <stdio.h>
#include "Subsystem.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

#define B_l 0.5
#define B_u 0.5
#define FilterCoeffN 10.0
#define J_l 0.071440709
#define J_u 0.049103
double JointX_InitialPositionCondition = 0.27;
double JointY_InitialPositionCondition = -0.33;
#define L_cg_l 0.102366
#define L_cg_u 0.066301
#define L_l 0.223793
#define L_u 0.227293
#define PitchLowerLimit -0.37
#define PitchUpperLimit 0.27
#define PitchXMotorSaturation 50.0
#define PitchXStartThrust 50.0
#define RollLowerLimit -0.33
#define RollUpperLimit 0.4
#define RollYMotorSaturation 30.0
#define RollYStartThrust 40.0
#define g 9.81
#define ixposkd 0.0
#define ixposki 1.0
#define ixposkp 12.0
#define ixvelkd 0.0
#define ixvelki 5.0
#define ixvelkp 30.0
#define iyposkd 0.0
#define iyposki 1.0
#define iyposkp 10.0
#define iyvelkd 0.0
#define iyvelki 5.0
#define iyvelkp 20.0
#define mass_l 2.495
#define mass_u 2.024

typedef struct tag_RTM_Subsystem_T RT_MODEL_Subsystem_T;

typedef struct
{
  double Delay1_DSTATE[4];
  double DiscreteTimeIntegrator1_DSTATE;
  double Integrator_DSTATE;
  double Filter_DSTATE;
  double Delay_DSTATE[4];
  double DiscreteTransferFcn_states;
  double Integrator_DSTATE_h;
  double Filter_DSTATE_p;
  double Delay3_DSTATE[4];
  double DiscreteTimeIntegrator_DSTATE;
  double Integrator_DSTATE_o;
  double Filter_DSTATE_m;
  double Delay2_DSTATE[4];
  double DiscreteTransferFcn1_states;
  double Integrator_DSTATE_b;
  double Filter_DSTATE_h;
  double DiscreteTimeIntegrator4_DSTATE;
  double DiscreteTimeIntegrator3_DSTATE;
  double FrontMotor_states;
  double BackMotor_states;
  double LeftMotor_states;
  double RightMotor_states;
  double DiscreteTimeIntegrator5_DSTATE;
  double DiscreteTimeIntegrator2_DSTATE;
} DW_Subsystem_T;
DW_Subsystem_T Subsystem_DW;
typedef struct
{
  double target;
  double In2;
} ExtU_Subsystem_T;

typedef struct
{
  double thetaY;
  double Y_posPID_ControlAction;
  double Y_velPID_ControlAction;
  double thetaY_h;
  double thetaX;
  double X_posPID_ControlAction;
  double X_velPID_ControlAction;
  double thetaX_j;
} ExtY_Subsystem_T;
ExtY_Subsystem_T Subsystem_Y;
struct tag_RTM_Subsystem_T
{
  const char *volatile errorStatus;
};

ExtU_Subsystem_T Subsystem_U = {0, 0};

static RT_MODEL_Subsystem_T Subsystem_M_;
RT_MODEL_Subsystem_T *const Subsystem_M = &Subsystem_M_;

void Subsystem_initialize(void)
{
  Subsystem_DW.DiscreteTimeIntegrator3_DSTATE = JointY_InitialPositionCondition;
  Subsystem_DW.DiscreteTimeIntegrator2_DSTATE = JointX_InitialPositionCondition;
}

void Subsystem_terminate(void)
{
}

void rt_OneStep(void)
{
  static bool OverrunFlag = false;
  if (OverrunFlag)
  {
    rtmSetErrorStatus(Subsystem_M, "Overrun");
    return;
  }

  OverrunFlag = true;
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
                                        Subsystem_DW.Integrator_DSTATE) +
                                       rtb_FilterCoefficient;
  if (Subsystem_Y.Y_posPID_ControlAction > 1.0)
  {
    rtb_Filter_m = Subsystem_Y.Y_posPID_ControlAction - 1.0;
    tmp = 1;
  }
  else
  {
    if (Subsystem_Y.Y_posPID_ControlAction >= -1.0)
    {
      rtb_Filter_m = 0.0;
    }
    else
    {
      rtb_Filter_m = Subsystem_Y.Y_posPID_ControlAction - -1.0;
    }

    tmp = -1;
  }

  rtb_RelationalOperator = (rtb_Filter_m != 0.0);
  if (Subsystem_Y.Y_posPID_ControlAction > 1.0)
  {
    Subsystem_Y.Y_posPID_ControlAction = 1.0;
  }
  else if (Subsystem_Y.Y_posPID_ControlAction < -1.0)
  {
    Subsystem_Y.Y_posPID_ControlAction = -1.0;
  }

  numAccum = 0.0165 * Subsystem_DW.DiscreteTransferFcn_states;
  rtb_Filter_m = (numAccum + Subsystem_Y.Y_posPID_ControlAction) -
                 Subsystem_DW.Delay_DSTATE[0];
  rtb_FilterCoefficient_d = (iyvelkd * rtb_Filter_m -
                             Subsystem_DW.Filter_DSTATE_p) *
                            FilterCoeffN;
  Subsystem_Y.Y_velPID_ControlAction = (iyvelkp * rtb_Filter_m +
                                        Subsystem_DW.Integrator_DSTATE_h) +
                                       rtb_FilterCoefficient_d;
  if (Subsystem_Y.Y_velPID_ControlAction > RollYMotorSaturation)
  {
    rtb_Filter_b = Subsystem_Y.Y_velPID_ControlAction - RollYMotorSaturation;
  }
  else if (Subsystem_Y.Y_velPID_ControlAction >= -RollYMotorSaturation)
  {
    rtb_Filter_b = 0.0;
  }
  else
  {
    rtb_Filter_b = Subsystem_Y.Y_velPID_ControlAction - (-RollYMotorSaturation);
  }

  rtb_Filter_m *= iyvelki;
  if (rtb_Filter_b > 0.0)
  {
    tmp_0 = 1;
  }
  else
  {
    tmp_0 = -1;
  }

  if (rtb_Filter_m > 0.0)
  {
    tmp_1 = 1;
  }
  else
  {
    tmp_1 = -1;
  }

  if ((rtb_Filter_b != 0.0) && (tmp_0 == tmp_1))
  {
    rtb_Switch_b = 0.0;
  }
  else
  {
    rtb_Switch_b = rtb_Filter_m;
  }

  if (Subsystem_Y.Y_velPID_ControlAction > RollYMotorSaturation)
  {
    Subsystem_Y.Y_velPID_ControlAction = RollYMotorSaturation;
  }
  else if (Subsystem_Y.Y_velPID_ControlAction < -RollYMotorSaturation)
  {
    Subsystem_Y.Y_velPID_ControlAction = -RollYMotorSaturation;
  }

  Sum = Subsystem_U.target - Subsystem_DW.DiscreteTimeIntegrator1_DSTATE;
  Add21 = PitchXStartThrust - Subsystem_Y.X_velPID_ControlAction;
  Add22 = PitchXStartThrust + Subsystem_Y.X_velPID_ControlAction;
  rtb_Filter_b = Subsystem_DW.DiscreteTimeIntegrator_DSTATE -
                 Subsystem_DW.Delay3_DSTATE[0];
  rtb_Filter_m = ixposki * rtb_Filter_b;
  rtb_FilterCoefficient_h = (ixposkd * rtb_Filter_b -
                             Subsystem_DW.Filter_DSTATE_m) *
                            FilterCoeffN;
  Subsystem_Y.X_posPID_ControlAction = (ixposkp * rtb_Filter_b +
                                        Subsystem_DW.Integrator_DSTATE_o) +
                                       rtb_FilterCoefficient_h;
  if (Subsystem_Y.X_posPID_ControlAction > 1.0)
  {
    rtb_Filter_b = Subsystem_Y.X_posPID_ControlAction - 1.0;
    tmp_0 = 1;
  }
  else
  {
    if (Subsystem_Y.X_posPID_ControlAction >= -1.0)
    {
      rtb_Filter_b = 0.0;
    }
    else
    {
      rtb_Filter_b = Subsystem_Y.X_posPID_ControlAction - -1.0;
    }

    tmp_0 = -1;
  }

  rtb_RelationalOperator_m = (rtb_Filter_b != 0.0);
  if (Subsystem_Y.X_posPID_ControlAction > 1.0)
  {
    Subsystem_Y.X_posPID_ControlAction = 1.0;
  }
  else if (Subsystem_Y.X_posPID_ControlAction < -1.0)
  {
    Subsystem_Y.X_posPID_ControlAction = -1.0;
  }

  numAccum_0 = 0.0165 * Subsystem_DW.DiscreteTransferFcn1_states;
  rtb_Filter_b = (numAccum_0 + Subsystem_Y.X_posPID_ControlAction) -
                 Subsystem_DW.Delay2_DSTATE[0];
  rtb_FilterCoefficient_b = (ixvelkd * rtb_Filter_b -
                             Subsystem_DW.Filter_DSTATE_h) *
                            FilterCoeffN;
  Subsystem_Y.X_velPID_ControlAction = (ixvelkp * 0.4 * rtb_Filter_b +
                                        Subsystem_DW.Integrator_DSTATE_b) +
                                       rtb_FilterCoefficient_b;
  if (Subsystem_Y.X_velPID_ControlAction > PitchXMotorSaturation)
  {
    rtb_Cos = Subsystem_Y.X_velPID_ControlAction - PitchXMotorSaturation;
  }
  else if (Subsystem_Y.X_velPID_ControlAction >= -PitchXMotorSaturation)
  {
    rtb_Cos = 0.0;
  }
  else
  {
    rtb_Cos = Subsystem_Y.X_velPID_ControlAction - (-PitchXMotorSaturation);
  }

  rtb_Filter_b *= ixvelki * 0.4;
  if (rtb_Cos > 0.0)
  {
    tmp_1 = 1;
  }
  else
  {
    tmp_1 = -1;
  }

  if (rtb_Filter_b > 0.0)
  {
    tmp_2 = 1;
  }
  else
  {
    tmp_2 = -1;
  }

  rtb_AND3_p = ((rtb_Cos != 0.0) && (tmp_1 == tmp_2));
  if (Subsystem_Y.X_velPID_ControlAction > PitchXMotorSaturation)
  {
    Subsystem_Y.X_velPID_ControlAction = PitchXMotorSaturation;
  }
  else if (Subsystem_Y.X_velPID_ControlAction < -PitchXMotorSaturation)
  {
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
  if (rtb_Filter > 0.0)
  {
    tmp_1 = 1;
  }
  else
  {
    tmp_1 = -1;
  }

  if (rtb_RelationalOperator && (tmp == tmp_1))
  {
    rtb_Filter = 0.0;
  }

  Subsystem_DW.Integrator_DSTATE += 0.005 * rtb_Filter;
  Subsystem_DW.Filter_DSTATE += 0.005 * rtb_FilterCoefficient;
  Subsystem_DW.DiscreteTransferFcn_states = Sum - 0.9835 *
                                                      Subsystem_DW.DiscreteTransferFcn_states;
  Subsystem_DW.Integrator_DSTATE_h += 0.005 * rtb_Switch_b;
  Subsystem_DW.Filter_DSTATE_p += 0.005 * rtb_FilterCoefficient_d;
  Subsystem_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * numAccum_0;
  if (rtb_Filter_m > 0.0)
  {
    tmp = 1;
  }
  else
  {
    tmp = -1;
  }

  if (rtb_RelationalOperator_m && (tmp_0 == tmp))
  {
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
  if (rtb_AND3_p)
  {
    rtb_Filter_b = 0.0;
  }

  Subsystem_DW.Integrator_DSTATE_b += 0.005 * rtb_Filter_b;
  Subsystem_DW.Filter_DSTATE_h += 0.005 * rtb_FilterCoefficient_b;
  Subsystem_DW.DiscreteTimeIntegrator4_DSTATE += ((mass_u * g * L_cg_u * sin(Subsystem_DW.DiscreteTimeIntegrator3_DSTATE) - B_u *
                                                                                                                                Subsystem_DW.DiscreteTimeIntegrator4_DSTATE) +
                                                  (0.00634 *
                                                       Subsystem_DW.BackMotor_states -
                                                   0.00634 * Subsystem_DW.FrontMotor_states) *
                                                      L_u) *
                                                 (1.0 / J_u) * 0.005;
  Subsystem_DW.DiscreteTimeIntegrator3_DSTATE += 0.005 * Subsystem_Y.thetaY;
  if (Subsystem_DW.DiscreteTimeIntegrator3_DSTATE > RollUpperLimit)
  {
    Subsystem_DW.DiscreteTimeIntegrator3_DSTATE = RollUpperLimit;
  }
  else if (Subsystem_DW.DiscreteTimeIntegrator3_DSTATE < RollLowerLimit)
  {
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
  Subsystem_DW.DiscreteTimeIntegrator5_DSTATE += ((mass_l * g * L_cg_l * sin(Subsystem_DW.DiscreteTimeIntegrator2_DSTATE) - B_l *
                                                                                                                                Subsystem_DW.DiscreteTimeIntegrator5_DSTATE) +
                                                  (numAccum_2 * rtb_Cos -
                                                   numAccum_1 * rtb_Cos) *
                                                      L_l) *
                                                 (1.0 / J_l) * 0.005;
  Subsystem_DW.DiscreteTimeIntegrator2_DSTATE += 0.005 * Subsystem_Y.thetaX_j;
  if (Subsystem_DW.DiscreteTimeIntegrator2_DSTATE > PitchUpperLimit)
  {
    Subsystem_DW.DiscreteTimeIntegrator2_DSTATE = PitchUpperLimit;
  }
  else if (Subsystem_DW.DiscreteTimeIntegrator2_DSTATE < PitchLowerLimit)
  {
    Subsystem_DW.DiscreteTimeIntegrator2_DSTATE = PitchLowerLimit;
  }
  OverrunFlag = false;
}

int main(int argc, const char *argv[])
{
  (void)(argc);
  (void)(argv);
  Subsystem_initialize();
  while (rtmGetErrorStatus(Subsystem_M) == (NULL))
  {
    for (int i = 0; i < 1000; i++)
    {
      rt_OneStep();
      printf("%f, %f\n", Subsystem_Y.thetaX, Subsystem_Y.thetaY);
    }
    break;
  }

  Subsystem_terminate();
  return 0;
}
