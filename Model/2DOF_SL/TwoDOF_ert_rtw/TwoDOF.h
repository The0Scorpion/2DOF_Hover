/*
 * File: TwoDOF.h
 *
 * Code generated for Simulink model 'TwoDOF'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jun 20 15:45:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TwoDOF_h_
#define RTW_HEADER_TwoDOF_h_
#ifndef TwoDOF_COMMON_INCLUDES_
#define TwoDOF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "IMU.h"
#endif                                 /* TwoDOF_COMMON_INCLUDES_ */

#include "TwoDOF_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  IMU_TwoDOF_T obj;                    /* '<Root>/MATLAB System1' */
} DW_TwoDOF_T;

/* Parameters (default storage) */
struct P_TwoDOF_T_ {
  real_T MATLABSystem1_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TwoDOF_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_TwoDOF_T TwoDOF_P;

/* Block states (default storage) */
extern DW_TwoDOF_T TwoDOF_DW;

/* Model entry point functions */
extern void TwoDOF_initialize(void);
extern void TwoDOF_step(void);
extern void TwoDOF_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TwoDOF_T *const TwoDOF_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<S1>/Reshape' : Unused code path elimination
 * Block '<S2>/Reshape' : Unused code path elimination
 * Block '<Root>/Discrete Transfer Fcn' : Unused code path elimination
 * Block '<Root>/Discrete Transfer Fcn1' : Unused code path elimination
 * Block '<Root>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<Root>/Discrete-Time Integrator1' : Unused code path elimination
 * Block '<Root>/Sum' : Unused code path elimination
 * Block '<Root>/Sum1' : Unused code path elimination
 * Block '<Root>/Sum16' : Unused code path elimination
 * Block '<Root>/Sum2' : Unused code path elimination
 * Block '<Root>/Sum23' : Unused code path elimination
 * Block '<Root>/Sum3' : Unused code path elimination
 * Block '<S31>/AND3' : Unused code path elimination
 * Block '<S31>/Clamping_zero' : Unused code path elimination
 * Block '<S31>/Constant' : Unused code path elimination
 * Block '<S31>/Constant1' : Unused code path elimination
 * Block '<S31>/Constant2' : Unused code path elimination
 * Block '<S31>/Constant3' : Unused code path elimination
 * Block '<S31>/Constant4' : Unused code path elimination
 * Block '<S33>/DeadZone' : Unused code path elimination
 * Block '<S31>/Equal1' : Unused code path elimination
 * Block '<S31>/Relational Operator' : Unused code path elimination
 * Block '<S31>/Switch' : Unused code path elimination
 * Block '<S31>/Switch1' : Unused code path elimination
 * Block '<S31>/Switch2' : Unused code path elimination
 * Block '<S31>/fix for DT propagation issue' : Unused code path elimination
 * Block '<S31>/fix for DT propagation issue1' : Unused code path elimination
 * Block '<S34>/Derivative Gain' : Unused code path elimination
 * Block '<S35>/Filter' : Unused code path elimination
 * Block '<S35>/SumD' : Unused code path elimination
 * Block '<S37>/Integral Gain' : Unused code path elimination
 * Block '<S40>/Integrator' : Unused code path elimination
 * Block '<S43>/Filter Coefficient' : Unused code path elimination
 * Block '<S45>/Proportional Gain' : Unused code path elimination
 * Block '<S47>/Saturation' : Unused code path elimination
 * Block '<S49>/Sum' : Unused code path elimination
 * Block '<S81>/AND3' : Unused code path elimination
 * Block '<S81>/Clamping_zero' : Unused code path elimination
 * Block '<S81>/Constant' : Unused code path elimination
 * Block '<S81>/Constant1' : Unused code path elimination
 * Block '<S81>/Constant2' : Unused code path elimination
 * Block '<S81>/Constant3' : Unused code path elimination
 * Block '<S81>/Constant4' : Unused code path elimination
 * Block '<S83>/DeadZone' : Unused code path elimination
 * Block '<S81>/Equal1' : Unused code path elimination
 * Block '<S81>/Relational Operator' : Unused code path elimination
 * Block '<S81>/Switch' : Unused code path elimination
 * Block '<S81>/Switch1' : Unused code path elimination
 * Block '<S81>/Switch2' : Unused code path elimination
 * Block '<S81>/fix for DT propagation issue' : Unused code path elimination
 * Block '<S81>/fix for DT propagation issue1' : Unused code path elimination
 * Block '<S84>/Derivative Gain' : Unused code path elimination
 * Block '<S85>/Filter' : Unused code path elimination
 * Block '<S85>/SumD' : Unused code path elimination
 * Block '<S87>/Integral Gain' : Unused code path elimination
 * Block '<S90>/Integrator' : Unused code path elimination
 * Block '<S93>/Filter Coefficient' : Unused code path elimination
 * Block '<S95>/Proportional Gain' : Unused code path elimination
 * Block '<S97>/Saturation' : Unused code path elimination
 * Block '<S99>/Sum' : Unused code path elimination
 * Block '<S131>/AND3' : Unused code path elimination
 * Block '<S131>/Clamping_zero' : Unused code path elimination
 * Block '<S131>/Constant' : Unused code path elimination
 * Block '<S131>/Constant1' : Unused code path elimination
 * Block '<S131>/Constant2' : Unused code path elimination
 * Block '<S131>/Constant3' : Unused code path elimination
 * Block '<S131>/Constant4' : Unused code path elimination
 * Block '<S133>/DeadZone' : Unused code path elimination
 * Block '<S131>/Equal1' : Unused code path elimination
 * Block '<S131>/Relational Operator' : Unused code path elimination
 * Block '<S131>/Switch' : Unused code path elimination
 * Block '<S131>/Switch1' : Unused code path elimination
 * Block '<S131>/Switch2' : Unused code path elimination
 * Block '<S131>/fix for DT propagation issue' : Unused code path elimination
 * Block '<S131>/fix for DT propagation issue1' : Unused code path elimination
 * Block '<S134>/Derivative Gain' : Unused code path elimination
 * Block '<S135>/Filter' : Unused code path elimination
 * Block '<S135>/SumD' : Unused code path elimination
 * Block '<S137>/Integral Gain' : Unused code path elimination
 * Block '<S140>/Integrator' : Unused code path elimination
 * Block '<S143>/Filter Coefficient' : Unused code path elimination
 * Block '<S145>/Proportional Gain' : Unused code path elimination
 * Block '<S147>/Saturation' : Unused code path elimination
 * Block '<S149>/Sum' : Unused code path elimination
 * Block '<S181>/AND3' : Unused code path elimination
 * Block '<S181>/Clamping_zero' : Unused code path elimination
 * Block '<S181>/Constant' : Unused code path elimination
 * Block '<S181>/Constant1' : Unused code path elimination
 * Block '<S181>/Constant2' : Unused code path elimination
 * Block '<S181>/Constant3' : Unused code path elimination
 * Block '<S181>/Constant4' : Unused code path elimination
 * Block '<S183>/DeadZone' : Unused code path elimination
 * Block '<S181>/Equal1' : Unused code path elimination
 * Block '<S181>/Relational Operator' : Unused code path elimination
 * Block '<S181>/Switch' : Unused code path elimination
 * Block '<S181>/Switch1' : Unused code path elimination
 * Block '<S181>/Switch2' : Unused code path elimination
 * Block '<S181>/fix for DT propagation issue' : Unused code path elimination
 * Block '<S181>/fix for DT propagation issue1' : Unused code path elimination
 * Block '<S184>/Derivative Gain' : Unused code path elimination
 * Block '<S185>/Filter' : Unused code path elimination
 * Block '<S185>/SumD' : Unused code path elimination
 * Block '<S187>/Integral Gain' : Unused code path elimination
 * Block '<S190>/Integrator' : Unused code path elimination
 * Block '<S193>/Filter Coefficient' : Unused code path elimination
 * Block '<S195>/Proportional Gain' : Unused code path elimination
 * Block '<S197>/Saturation' : Unused code path elimination
 * Block '<S199>/Sum' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TwoDOF'
 * '<S1>'   : 'TwoDOF/Convert 1-D to 2-D'
 * '<S2>'   : 'TwoDOF/Convert 1-D to 2-D1'
 * '<S3>'   : 'TwoDOF/xPOSPID'
 * '<S4>'   : 'TwoDOF/xVELPID'
 * '<S5>'   : 'TwoDOF/yPOSPID'
 * '<S6>'   : 'TwoDOF/yVELPID'
 * '<S7>'   : 'TwoDOF/xPOSPID/Anti-windup'
 * '<S8>'   : 'TwoDOF/xPOSPID/D Gain'
 * '<S9>'   : 'TwoDOF/xPOSPID/Filter'
 * '<S10>'  : 'TwoDOF/xPOSPID/Filter ICs'
 * '<S11>'  : 'TwoDOF/xPOSPID/I Gain'
 * '<S12>'  : 'TwoDOF/xPOSPID/Ideal P Gain'
 * '<S13>'  : 'TwoDOF/xPOSPID/Ideal P Gain Fdbk'
 * '<S14>'  : 'TwoDOF/xPOSPID/Integrator'
 * '<S15>'  : 'TwoDOF/xPOSPID/Integrator ICs'
 * '<S16>'  : 'TwoDOF/xPOSPID/N Copy'
 * '<S17>'  : 'TwoDOF/xPOSPID/N Gain'
 * '<S18>'  : 'TwoDOF/xPOSPID/P Copy'
 * '<S19>'  : 'TwoDOF/xPOSPID/Parallel P Gain'
 * '<S20>'  : 'TwoDOF/xPOSPID/Reset Signal'
 * '<S21>'  : 'TwoDOF/xPOSPID/Saturation'
 * '<S22>'  : 'TwoDOF/xPOSPID/Saturation Fdbk'
 * '<S23>'  : 'TwoDOF/xPOSPID/Sum'
 * '<S24>'  : 'TwoDOF/xPOSPID/Sum Fdbk'
 * '<S25>'  : 'TwoDOF/xPOSPID/Tracking Mode'
 * '<S26>'  : 'TwoDOF/xPOSPID/Tracking Mode Sum'
 * '<S27>'  : 'TwoDOF/xPOSPID/Tsamp - Integral'
 * '<S28>'  : 'TwoDOF/xPOSPID/Tsamp - Ngain'
 * '<S29>'  : 'TwoDOF/xPOSPID/postSat Signal'
 * '<S30>'  : 'TwoDOF/xPOSPID/preSat Signal'
 * '<S31>'  : 'TwoDOF/xPOSPID/Anti-windup/Disc. Clamping Parallel'
 * '<S32>'  : 'TwoDOF/xPOSPID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S33>'  : 'TwoDOF/xPOSPID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S34>'  : 'TwoDOF/xPOSPID/D Gain/Internal Parameters'
 * '<S35>'  : 'TwoDOF/xPOSPID/Filter/Disc. Forward Euler Filter'
 * '<S36>'  : 'TwoDOF/xPOSPID/Filter ICs/Internal IC - Filter'
 * '<S37>'  : 'TwoDOF/xPOSPID/I Gain/Internal Parameters'
 * '<S38>'  : 'TwoDOF/xPOSPID/Ideal P Gain/Passthrough'
 * '<S39>'  : 'TwoDOF/xPOSPID/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'TwoDOF/xPOSPID/Integrator/Discrete'
 * '<S41>'  : 'TwoDOF/xPOSPID/Integrator ICs/Internal IC'
 * '<S42>'  : 'TwoDOF/xPOSPID/N Copy/Disabled'
 * '<S43>'  : 'TwoDOF/xPOSPID/N Gain/Internal Parameters'
 * '<S44>'  : 'TwoDOF/xPOSPID/P Copy/Disabled'
 * '<S45>'  : 'TwoDOF/xPOSPID/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'TwoDOF/xPOSPID/Reset Signal/Disabled'
 * '<S47>'  : 'TwoDOF/xPOSPID/Saturation/Enabled'
 * '<S48>'  : 'TwoDOF/xPOSPID/Saturation Fdbk/Disabled'
 * '<S49>'  : 'TwoDOF/xPOSPID/Sum/Sum_PID'
 * '<S50>'  : 'TwoDOF/xPOSPID/Sum Fdbk/Disabled'
 * '<S51>'  : 'TwoDOF/xPOSPID/Tracking Mode/Disabled'
 * '<S52>'  : 'TwoDOF/xPOSPID/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'TwoDOF/xPOSPID/Tsamp - Integral/TsSignalSpecification'
 * '<S54>'  : 'TwoDOF/xPOSPID/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'TwoDOF/xPOSPID/postSat Signal/Forward_Path'
 * '<S56>'  : 'TwoDOF/xPOSPID/preSat Signal/Forward_Path'
 * '<S57>'  : 'TwoDOF/xVELPID/Anti-windup'
 * '<S58>'  : 'TwoDOF/xVELPID/D Gain'
 * '<S59>'  : 'TwoDOF/xVELPID/Filter'
 * '<S60>'  : 'TwoDOF/xVELPID/Filter ICs'
 * '<S61>'  : 'TwoDOF/xVELPID/I Gain'
 * '<S62>'  : 'TwoDOF/xVELPID/Ideal P Gain'
 * '<S63>'  : 'TwoDOF/xVELPID/Ideal P Gain Fdbk'
 * '<S64>'  : 'TwoDOF/xVELPID/Integrator'
 * '<S65>'  : 'TwoDOF/xVELPID/Integrator ICs'
 * '<S66>'  : 'TwoDOF/xVELPID/N Copy'
 * '<S67>'  : 'TwoDOF/xVELPID/N Gain'
 * '<S68>'  : 'TwoDOF/xVELPID/P Copy'
 * '<S69>'  : 'TwoDOF/xVELPID/Parallel P Gain'
 * '<S70>'  : 'TwoDOF/xVELPID/Reset Signal'
 * '<S71>'  : 'TwoDOF/xVELPID/Saturation'
 * '<S72>'  : 'TwoDOF/xVELPID/Saturation Fdbk'
 * '<S73>'  : 'TwoDOF/xVELPID/Sum'
 * '<S74>'  : 'TwoDOF/xVELPID/Sum Fdbk'
 * '<S75>'  : 'TwoDOF/xVELPID/Tracking Mode'
 * '<S76>'  : 'TwoDOF/xVELPID/Tracking Mode Sum'
 * '<S77>'  : 'TwoDOF/xVELPID/Tsamp - Integral'
 * '<S78>'  : 'TwoDOF/xVELPID/Tsamp - Ngain'
 * '<S79>'  : 'TwoDOF/xVELPID/postSat Signal'
 * '<S80>'  : 'TwoDOF/xVELPID/preSat Signal'
 * '<S81>'  : 'TwoDOF/xVELPID/Anti-windup/Disc. Clamping Parallel'
 * '<S82>'  : 'TwoDOF/xVELPID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S83>'  : 'TwoDOF/xVELPID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S84>'  : 'TwoDOF/xVELPID/D Gain/Internal Parameters'
 * '<S85>'  : 'TwoDOF/xVELPID/Filter/Disc. Forward Euler Filter'
 * '<S86>'  : 'TwoDOF/xVELPID/Filter ICs/Internal IC - Filter'
 * '<S87>'  : 'TwoDOF/xVELPID/I Gain/Internal Parameters'
 * '<S88>'  : 'TwoDOF/xVELPID/Ideal P Gain/Passthrough'
 * '<S89>'  : 'TwoDOF/xVELPID/Ideal P Gain Fdbk/Disabled'
 * '<S90>'  : 'TwoDOF/xVELPID/Integrator/Discrete'
 * '<S91>'  : 'TwoDOF/xVELPID/Integrator ICs/Internal IC'
 * '<S92>'  : 'TwoDOF/xVELPID/N Copy/Disabled'
 * '<S93>'  : 'TwoDOF/xVELPID/N Gain/Internal Parameters'
 * '<S94>'  : 'TwoDOF/xVELPID/P Copy/Disabled'
 * '<S95>'  : 'TwoDOF/xVELPID/Parallel P Gain/Internal Parameters'
 * '<S96>'  : 'TwoDOF/xVELPID/Reset Signal/Disabled'
 * '<S97>'  : 'TwoDOF/xVELPID/Saturation/Enabled'
 * '<S98>'  : 'TwoDOF/xVELPID/Saturation Fdbk/Disabled'
 * '<S99>'  : 'TwoDOF/xVELPID/Sum/Sum_PID'
 * '<S100>' : 'TwoDOF/xVELPID/Sum Fdbk/Disabled'
 * '<S101>' : 'TwoDOF/xVELPID/Tracking Mode/Disabled'
 * '<S102>' : 'TwoDOF/xVELPID/Tracking Mode Sum/Passthrough'
 * '<S103>' : 'TwoDOF/xVELPID/Tsamp - Integral/TsSignalSpecification'
 * '<S104>' : 'TwoDOF/xVELPID/Tsamp - Ngain/Passthrough'
 * '<S105>' : 'TwoDOF/xVELPID/postSat Signal/Forward_Path'
 * '<S106>' : 'TwoDOF/xVELPID/preSat Signal/Forward_Path'
 * '<S107>' : 'TwoDOF/yPOSPID/Anti-windup'
 * '<S108>' : 'TwoDOF/yPOSPID/D Gain'
 * '<S109>' : 'TwoDOF/yPOSPID/Filter'
 * '<S110>' : 'TwoDOF/yPOSPID/Filter ICs'
 * '<S111>' : 'TwoDOF/yPOSPID/I Gain'
 * '<S112>' : 'TwoDOF/yPOSPID/Ideal P Gain'
 * '<S113>' : 'TwoDOF/yPOSPID/Ideal P Gain Fdbk'
 * '<S114>' : 'TwoDOF/yPOSPID/Integrator'
 * '<S115>' : 'TwoDOF/yPOSPID/Integrator ICs'
 * '<S116>' : 'TwoDOF/yPOSPID/N Copy'
 * '<S117>' : 'TwoDOF/yPOSPID/N Gain'
 * '<S118>' : 'TwoDOF/yPOSPID/P Copy'
 * '<S119>' : 'TwoDOF/yPOSPID/Parallel P Gain'
 * '<S120>' : 'TwoDOF/yPOSPID/Reset Signal'
 * '<S121>' : 'TwoDOF/yPOSPID/Saturation'
 * '<S122>' : 'TwoDOF/yPOSPID/Saturation Fdbk'
 * '<S123>' : 'TwoDOF/yPOSPID/Sum'
 * '<S124>' : 'TwoDOF/yPOSPID/Sum Fdbk'
 * '<S125>' : 'TwoDOF/yPOSPID/Tracking Mode'
 * '<S126>' : 'TwoDOF/yPOSPID/Tracking Mode Sum'
 * '<S127>' : 'TwoDOF/yPOSPID/Tsamp - Integral'
 * '<S128>' : 'TwoDOF/yPOSPID/Tsamp - Ngain'
 * '<S129>' : 'TwoDOF/yPOSPID/postSat Signal'
 * '<S130>' : 'TwoDOF/yPOSPID/preSat Signal'
 * '<S131>' : 'TwoDOF/yPOSPID/Anti-windup/Disc. Clamping Parallel'
 * '<S132>' : 'TwoDOF/yPOSPID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S133>' : 'TwoDOF/yPOSPID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S134>' : 'TwoDOF/yPOSPID/D Gain/Internal Parameters'
 * '<S135>' : 'TwoDOF/yPOSPID/Filter/Disc. Forward Euler Filter'
 * '<S136>' : 'TwoDOF/yPOSPID/Filter ICs/Internal IC - Filter'
 * '<S137>' : 'TwoDOF/yPOSPID/I Gain/Internal Parameters'
 * '<S138>' : 'TwoDOF/yPOSPID/Ideal P Gain/Passthrough'
 * '<S139>' : 'TwoDOF/yPOSPID/Ideal P Gain Fdbk/Disabled'
 * '<S140>' : 'TwoDOF/yPOSPID/Integrator/Discrete'
 * '<S141>' : 'TwoDOF/yPOSPID/Integrator ICs/Internal IC'
 * '<S142>' : 'TwoDOF/yPOSPID/N Copy/Disabled'
 * '<S143>' : 'TwoDOF/yPOSPID/N Gain/Internal Parameters'
 * '<S144>' : 'TwoDOF/yPOSPID/P Copy/Disabled'
 * '<S145>' : 'TwoDOF/yPOSPID/Parallel P Gain/Internal Parameters'
 * '<S146>' : 'TwoDOF/yPOSPID/Reset Signal/Disabled'
 * '<S147>' : 'TwoDOF/yPOSPID/Saturation/Enabled'
 * '<S148>' : 'TwoDOF/yPOSPID/Saturation Fdbk/Disabled'
 * '<S149>' : 'TwoDOF/yPOSPID/Sum/Sum_PID'
 * '<S150>' : 'TwoDOF/yPOSPID/Sum Fdbk/Disabled'
 * '<S151>' : 'TwoDOF/yPOSPID/Tracking Mode/Disabled'
 * '<S152>' : 'TwoDOF/yPOSPID/Tracking Mode Sum/Passthrough'
 * '<S153>' : 'TwoDOF/yPOSPID/Tsamp - Integral/TsSignalSpecification'
 * '<S154>' : 'TwoDOF/yPOSPID/Tsamp - Ngain/Passthrough'
 * '<S155>' : 'TwoDOF/yPOSPID/postSat Signal/Forward_Path'
 * '<S156>' : 'TwoDOF/yPOSPID/preSat Signal/Forward_Path'
 * '<S157>' : 'TwoDOF/yVELPID/Anti-windup'
 * '<S158>' : 'TwoDOF/yVELPID/D Gain'
 * '<S159>' : 'TwoDOF/yVELPID/Filter'
 * '<S160>' : 'TwoDOF/yVELPID/Filter ICs'
 * '<S161>' : 'TwoDOF/yVELPID/I Gain'
 * '<S162>' : 'TwoDOF/yVELPID/Ideal P Gain'
 * '<S163>' : 'TwoDOF/yVELPID/Ideal P Gain Fdbk'
 * '<S164>' : 'TwoDOF/yVELPID/Integrator'
 * '<S165>' : 'TwoDOF/yVELPID/Integrator ICs'
 * '<S166>' : 'TwoDOF/yVELPID/N Copy'
 * '<S167>' : 'TwoDOF/yVELPID/N Gain'
 * '<S168>' : 'TwoDOF/yVELPID/P Copy'
 * '<S169>' : 'TwoDOF/yVELPID/Parallel P Gain'
 * '<S170>' : 'TwoDOF/yVELPID/Reset Signal'
 * '<S171>' : 'TwoDOF/yVELPID/Saturation'
 * '<S172>' : 'TwoDOF/yVELPID/Saturation Fdbk'
 * '<S173>' : 'TwoDOF/yVELPID/Sum'
 * '<S174>' : 'TwoDOF/yVELPID/Sum Fdbk'
 * '<S175>' : 'TwoDOF/yVELPID/Tracking Mode'
 * '<S176>' : 'TwoDOF/yVELPID/Tracking Mode Sum'
 * '<S177>' : 'TwoDOF/yVELPID/Tsamp - Integral'
 * '<S178>' : 'TwoDOF/yVELPID/Tsamp - Ngain'
 * '<S179>' : 'TwoDOF/yVELPID/postSat Signal'
 * '<S180>' : 'TwoDOF/yVELPID/preSat Signal'
 * '<S181>' : 'TwoDOF/yVELPID/Anti-windup/Disc. Clamping Parallel'
 * '<S182>' : 'TwoDOF/yVELPID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S183>' : 'TwoDOF/yVELPID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S184>' : 'TwoDOF/yVELPID/D Gain/Internal Parameters'
 * '<S185>' : 'TwoDOF/yVELPID/Filter/Disc. Forward Euler Filter'
 * '<S186>' : 'TwoDOF/yVELPID/Filter ICs/Internal IC - Filter'
 * '<S187>' : 'TwoDOF/yVELPID/I Gain/Internal Parameters'
 * '<S188>' : 'TwoDOF/yVELPID/Ideal P Gain/Passthrough'
 * '<S189>' : 'TwoDOF/yVELPID/Ideal P Gain Fdbk/Disabled'
 * '<S190>' : 'TwoDOF/yVELPID/Integrator/Discrete'
 * '<S191>' : 'TwoDOF/yVELPID/Integrator ICs/Internal IC'
 * '<S192>' : 'TwoDOF/yVELPID/N Copy/Disabled'
 * '<S193>' : 'TwoDOF/yVELPID/N Gain/Internal Parameters'
 * '<S194>' : 'TwoDOF/yVELPID/P Copy/Disabled'
 * '<S195>' : 'TwoDOF/yVELPID/Parallel P Gain/Internal Parameters'
 * '<S196>' : 'TwoDOF/yVELPID/Reset Signal/Disabled'
 * '<S197>' : 'TwoDOF/yVELPID/Saturation/Enabled'
 * '<S198>' : 'TwoDOF/yVELPID/Saturation Fdbk/Disabled'
 * '<S199>' : 'TwoDOF/yVELPID/Sum/Sum_PID'
 * '<S200>' : 'TwoDOF/yVELPID/Sum Fdbk/Disabled'
 * '<S201>' : 'TwoDOF/yVELPID/Tracking Mode/Disabled'
 * '<S202>' : 'TwoDOF/yVELPID/Tracking Mode Sum/Passthrough'
 * '<S203>' : 'TwoDOF/yVELPID/Tsamp - Integral/TsSignalSpecification'
 * '<S204>' : 'TwoDOF/yVELPID/Tsamp - Ngain/Passthrough'
 * '<S205>' : 'TwoDOF/yVELPID/postSat Signal/Forward_Path'
 * '<S206>' : 'TwoDOF/yVELPID/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_TwoDOF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
