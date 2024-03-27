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

/* Real-time Model Data Structure */
struct tag_RTM_RVG0_T {
  const char_T * volatile errorStatus;
};

typedef struct tag_RTM_RVG0_T RT_MODEL_RVG0_T;

extern DW_RVG0_T RVG0_DW;
extern ExtU_RVG0_T RVG0_U;
extern ExtY_RVG0_T RVG0_Y;

/* Model entry point functions */
extern void RVG0_step(void);

/* Real-time Model object */
extern RT_MODEL_RVG0_T *const RVG0_M;

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
