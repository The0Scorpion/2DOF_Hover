/*
 * File: RVG0.c
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

#include "RVG0.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_RVG0_T RVG0_DW;  //DW_RVG0_T has integrator and transfer function in it, each of type double
ExtU_RVG0_T RVG0_U; //input has Y1target of type double
ExtY_RVG0_T RVG0_Y; //output has Y1ref and Y2ref of types double

/* Real-time model */
static RT_MODEL_RVG0_T RVG0_M_;
RT_MODEL_RVG0_T *const RVG0_M = &RVG0_M_; //pointer to Model object, note model object only has error status

/* Model step function */
void RVG0_step(void)
{
  double Sum;

  /* Outport: '<Root>/Y1ref' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   */
  RVG0_Y.Y1ref = RVG0_DW.DiscreteTimeIntegrator_DSTATE;

  /* Sum: '<S1>/Sum' incorporates:
   *  DiscreteIntegrator: '<S1>/Discrete-Time Integrator'
   *  Inport: '<Root>/Y1target'
   */
  Sum = RVG0_U.Y1target - RVG0_DW.DiscreteTimeIntegrator_DSTATE;

  /* DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  RVG0_Y.Y2ref = 0.01653 * RVG0_DW.DiscreteTransferFcn_states;

  /* Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator' incorporates:
   *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
   */
  RVG0_DW.DiscreteTimeIntegrator_DSTATE += 0.005 * RVG0_Y.Y2ref;

  /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  RVG0_DW.DiscreteTransferFcn_states = Sum - -0.9835 * RVG0_DW.DiscreteTransferFcn_states;
}
