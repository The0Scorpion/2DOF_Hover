#line 1 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\RVG0.h"
/*
 * File: RVG0.h
 *
 * Code generated for Simulink model 'RVG0'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Mar 25 05:56:17 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
 
#ifndef RTW_HEADER_RVG0_h_
#define RTW_HEADER_RVG0_h_

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif



/* Block states (default storage) for system '<Root>' */
typedef struct {
  double DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  double DiscreteTransferFcn_states;   /* '<S1>/Discrete Transfer Fcn' */
} DW_RVG0_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  double Y1target;                     /* '<Root>/Y1target' */
} ExtU_RVG0_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  double Y1ref;                        /* '<Root>/Y1ref' */
  double Y2ref;                        /* '<Root>/Y2ref' */
} ExtY_RVG0_T;



//extern DW_RVG0_T RVG0_DW;
//extern ExtU_RVG0_T RVG0_U;
//extern ExtY_RVG0_T RVG0_Y;
//
///* Model entry point functions */
//extern void RVG0_step(void);


/* Block states (default storage) */
DW_RVG0_T XRVG0_DW;  //DW_RVG0_T has integrator and transfer function in it, each of type double
ExtU_RVG0_T XRVG0_U; //input has Y1target of type double
ExtY_RVG0_T XRVG0_Y; //output has Y1ref and Y2ref of types double

DW_RVG0_T YRVG0_DW;  //DW_RVG0_T has integrator and transfer function in it, each of type double
ExtU_RVG0_T YRVG0_U; //input has Y1target of type double
ExtY_RVG0_T YRVG0_Y; //output has Y1ref and Y2ref of types double


/* Model step function */
void RVG0_step(void)
{
  double XSum, YSum;

  XRVG0_Y.Y1ref = XRVG0_DW.DiscreteTimeIntegrator_DSTATE;
  YRVG0_Y.Y1ref = YRVG0_DW.DiscreteTimeIntegrator_DSTATE;

  XSum = XRVG0_U.Y1target - XRVG0_DW.DiscreteTimeIntegrator_DSTATE;
  YSum = YRVG0_U.Y1target - YRVG0_DW.DiscreteTimeIntegrator_DSTATE;

  XRVG0_Y.Y2ref = 0.01653 * XRVG0_DW.DiscreteTransferFcn_states;
  YRVG0_Y.Y2ref = 0.01653 * YRVG0_DW.DiscreteTransferFcn_states;

  XRVG0_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * XRVG0_Y.Y2ref;
  YRVG0_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * YRVG0_Y.Y2ref;
  
  XRVG0_DW.DiscreteTransferFcn_states = XSum - -0.9835 * XRVG0_DW.DiscreteTransferFcn_states;
  YRVG0_DW.DiscreteTransferFcn_states = YSum - -0.9835 * YRVG0_DW.DiscreteTransferFcn_states;
}

#endif
