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

/* Macros for accessing real-time model data structure */
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



extern DW_RVG0_T RVG0_DW;
extern ExtU_RVG0_T RVG0_U;
extern ExtY_RVG0_T RVG0_Y;

/* Model entry point functions */
extern void RVG0_step(void);


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

  /* Outport: '<Root>/Y1ref' incorporates:
      DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
  */
  XRVG0_Y.Y1ref = XRVG0_DW.DiscreteTimeIntegrator_DSTATE;
  YRVG0_Y.Y1ref = YRVG0_DW.DiscreteTimeIntegrator_DSTATE;

  /* Sum: '<S1>/Sum' incorporates:
      DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
      Inport: '<Root>/Y1target'
  */

  XSum = XRVG0_U.Y1target - XRVG0_DW.DiscreteTimeIntegrator_DSTATE;
  YSum = YRVG0_U.Y1target - YRVG0_DW.DiscreteTimeIntegrator_DSTATE;
  /* DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */

  XRVG0_Y.Y2ref = 0.01653 * XRVG0_DW.DiscreteTransferFcn_states;
  YRVG0_Y.Y2ref = 0.01653 * YRVG0_DW.DiscreteTransferFcn_states;
  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
      DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
  */
  XRVG0_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * XRVG0_Y.Y2ref;
  YRVG0_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * YRVG0_Y.Y2ref;
  
  /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  XRVG0_DW.DiscreteTransferFcn_states = XSum - -0.9835 * XRVG0_DW.DiscreteTransferFcn_states;
  YRVG0_DW.DiscreteTransferFcn_states = YSum - -0.9835 * YRVG0_DW.DiscreteTransferFcn_states;
}
/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('RVG/RVG')    - opens subsystem RVG/RVG
 * hilite_system('RVG/RVG/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RVG'
 * '<S1>'   : 'RVG/RVG'
 */
#endif                                 /* RTW_HEADER_RVG0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
