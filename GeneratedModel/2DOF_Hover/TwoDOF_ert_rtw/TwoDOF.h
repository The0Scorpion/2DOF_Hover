#ifndef RTW_HEADER_TwoDOF_h_
#define RTW_HEADER_TwoDOF_h_
#ifndef TwoDOF_COMMON_INCLUDES_
#define TwoDOF_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define B_l                            0.5
#define B_u                            0.5
#define FilterCoeffN                   10.0
#define J_l                            0.071440709
#define J_u                            0.049103
#define JointX_InitialPositionCondition 0.27
#define JointY_InitialPositionCondition -0.33
#define L_cg_l                         0.102366
#define L_cg_u                         0.066301
#define L_l                            0.223793
#define L_u                            0.227293
#define PitchLowerLimit                -0.37
#define PitchUpperLimit                0.27
#define PitchXMotorSaturation          50.0
#define PitchXStartThrust              50.0
#define RollLowerLimit                 -0.33
#define RollUpperLimit                 0.4
#define RollYMotorSaturation           30.0
#define RollYStartThrust               40.0
#define g                              9.81
#define ixposkd                        0.0
#define ixposki                        1.0
#define ixposkp                        9.6
#define ixvelkd                        0.0
#define ixvelki                        2.0
#define ixvelkp                        12.0
#define iyposkd                        0.0
#define iyposki                        1.0
#define iyposkp                        10.0
#define iyvelkd                        0.0
#define iyvelki                        5.0
#define iyvelkp                        20.0
#define mass_l                         2.495
#define mass_u                         2.024

typedef struct tag_RTM_TwoDOF_T RT_MODEL_TwoDOF_T;
typedef struct {
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
} DW_TwoDOF_T;

typedef struct {
  double Y_setpoint;
  double X_setpoint;
} ExtU_TwoDOF_T;

typedef struct {
  double thetaYDot;
  double Y_posPID_ControlAction;
  double Y_velPID_ControlAction;
  double thetaY;
  double thetaX;
  double X_posPID_ControlAction;
  double X_velPID_ControlAction;
  double thetaXDot;
} ExtY_TwoDOF_T;

struct tag_RTM_TwoDOF_T {
  const char * volatile errorStatus;
};

extern DW_TwoDOF_T TwoDOF_DW;
extern ExtU_TwoDOF_T TwoDOF_U;
extern ExtY_TwoDOF_T TwoDOF_Y;
extern void TwoDOF_initialize(void);
extern void TwoDOF_step(void);
extern void TwoDOF_terminate(void);
extern RT_MODEL_TwoDOF_T *const TwoDOF_M;

#endif

