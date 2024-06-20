/*
 * File: TwoDOF.h
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

#ifndef RTW_HEADER_TwoDOF_h_
#define RTW_HEADER_TwoDOF_h_
#ifndef TwoDOF_COMMON_INCLUDES_
#define TwoDOF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "Encoders.h"
#include "IMU.h"
#include "Motors_Propellers.h"
#endif                                 /* TwoDOF_COMMON_INCLUDES_ */

#include "TwoDOF_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define FilterCoeffN                   10.0                      /* Referenced by:
                                                                  * '<S41>/Filter Coefficient'
                                                                  * '<S91>/Filter Coefficient'
                                                                  * '<S141>/Filter Coefficient'
                                                                  * '<S191>/Filter Coefficient'
                                                                  */
#define PitchXMotorSaturation          50.0                      /* Referenced by:
                                                                  * '<S95>/Saturation'
                                                                  * '<S81>/DeadZone'
                                                                  */
#define RollYMotorSaturation           30.0                      /* Referenced by:
                                                                  * '<S195>/Saturation'
                                                                  * '<S181>/DeadZone'
                                                                  */
#define ixposkd                        0.0                       /* Referenced by: '<S32>/Derivative Gain' */
#define ixposki                        1.0                       /* Referenced by: '<S35>/Integral Gain' */
#define ixposkp                        9.6                       /* Referenced by: '<S43>/Proportional Gain' */
#define ixvelkd                        0.0                       /* Referenced by: '<S82>/Derivative Gain' */
#define ixvelki                        2.0                       /* Referenced by: '<S85>/Integral Gain' */
#define ixvelkp                        12.0                      /* Referenced by: '<S93>/Proportional Gain' */
#define iyposkd                        0.0                       /* Referenced by: '<S132>/Derivative Gain' */
#define iyposki                        1.0                       /* Referenced by: '<S135>/Integral Gain' */
#define iyposkp                        10.0                      /* Referenced by: '<S143>/Proportional Gain' */
#define iyvelkd                        0.0                       /* Referenced by: '<S182>/Derivative Gain' */
#define iyvelki                        5.0                       /* Referenced by: '<S185>/Integral Gain' */
#define iyvelkp                        20.0                      /* Referenced by: '<S193>/Proportional Gain' */

/* Block signals (default storage) */
typedef struct {
  real_T numAccum;
  real_T numAccum_m;
  real_T IntegralGain;                 /* '<S35>/Integral Gain' */
  real_T FilterCoefficient;            /* '<S41>/Filter Coefficient' */
  real_T DeadZone;                     /* '<S31>/DeadZone' */
  real_T IntegralGain_g;               /* '<S85>/Integral Gain' */
  real_T FilterCoefficient_k;          /* '<S91>/Filter Coefficient' */
  real_T DeadZone_j;                   /* '<S81>/DeadZone' */
  real_T IntegralGain_m;               /* '<S135>/Integral Gain' */
} B_TwoDOF_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Encoders_TwoDOF_T obj;               /* '<Root>/MATLAB System' */
  IMU_TwoDOF_T obj_i;                  /* '<Root>/MATLAB System1' */
  Motors_Propellers_TwoDOF_T obj_g;    /* '<Root>/MATLAB System2' */
  real_T DiscreteTransferFcn1_states;  /* '<Root>/Discrete Transfer Fcn1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S38>/Integrator' */
  real_T Filter_DSTATE;                /* '<S33>/Filter' */
  real_T Integrator_DSTATE_m;          /* '<S88>/Integrator' */
  real_T Filter_DSTATE_d;              /* '<S83>/Filter' */
  real_T DiscreteTransferFcn_states;   /* '<Root>/Discrete Transfer Fcn' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  real_T Integrator_DSTATE_mi;         /* '<S138>/Integrator' */
  real_T Filter_DSTATE_dy;             /* '<S133>/Filter' */
  real_T Integrator_DSTATE_i;          /* '<S188>/Integrator' */
  real_T Filter_DSTATE_k;              /* '<S183>/Filter' */
} DW_TwoDOF_T;

/* Parameters (default storage) */
struct P_TwoDOF_T_ {
  real_T xPOSPID_InitialConditionForFilt;
                              /* Mask Parameter: xPOSPID_InitialConditionForFilt
                               * Referenced by: '<S33>/Filter'
                               */
  real_T xVELPID_InitialConditionForFilt;
                              /* Mask Parameter: xVELPID_InitialConditionForFilt
                               * Referenced by: '<S83>/Filter'
                               */
  real_T yPOSPID_InitialConditionForFilt;
                              /* Mask Parameter: yPOSPID_InitialConditionForFilt
                               * Referenced by: '<S133>/Filter'
                               */
  real_T yVELPID_InitialConditionForFilt;
                              /* Mask Parameter: yVELPID_InitialConditionForFilt
                               * Referenced by: '<S183>/Filter'
                               */
  real_T xPOSPID_InitialConditionForInte;
                              /* Mask Parameter: xPOSPID_InitialConditionForInte
                               * Referenced by: '<S38>/Integrator'
                               */
  real_T xVELPID_InitialConditionForInte;
                              /* Mask Parameter: xVELPID_InitialConditionForInte
                               * Referenced by: '<S88>/Integrator'
                               */
  real_T yPOSPID_InitialConditionForInte;
                              /* Mask Parameter: yPOSPID_InitialConditionForInte
                               * Referenced by: '<S138>/Integrator'
                               */
  real_T yVELPID_InitialConditionForInte;
                              /* Mask Parameter: yVELPID_InitialConditionForInte
                               * Referenced by: '<S188>/Integrator'
                               */
  real_T xPOSPID_LowerSaturationLimit;
                                 /* Mask Parameter: xPOSPID_LowerSaturationLimit
                                  * Referenced by:
                                  *   '<S45>/Saturation'
                                  *   '<S31>/DeadZone'
                                  */
  real_T yPOSPID_LowerSaturationLimit;
                                 /* Mask Parameter: yPOSPID_LowerSaturationLimit
                                  * Referenced by:
                                  *   '<S145>/Saturation'
                                  *   '<S131>/DeadZone'
                                  */
  real_T xPOSPID_UpperSaturationLimit;
                                 /* Mask Parameter: xPOSPID_UpperSaturationLimit
                                  * Referenced by:
                                  *   '<S45>/Saturation'
                                  *   '<S31>/DeadZone'
                                  */
  real_T yPOSPID_UpperSaturationLimit;
                                 /* Mask Parameter: yPOSPID_UpperSaturationLimit
                                  * Referenced by:
                                  *   '<S145>/Saturation'
                                  *   '<S131>/DeadZone'
                                  */
  real_T MATLABSystem_SampleTime;      /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T MATLABSystem1_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System1'
                                        */
  real_T MATLABSystem2_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/MATLAB System2'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T Constant1_Value_e;            /* Expression: 0
                                        * Referenced by: '<S129>/Constant1'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S179>/Constant1'
                                        */
  real_T DiscreteTransferFcn1_NumCoef; /* Expression: [0.0165]
                                        * Referenced by: '<Root>/Discrete Transfer Fcn1'
                                        */
  real_T DiscreteTransferFcn1_DenCoef[2];/* Expression: [1 -0.9835]
                                          * Referenced by: '<Root>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTransferFcn1_InitialSta;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S38>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S33>/Filter'
                                        */
  real_T Integrator_gainval_i;       /* Computed Parameter: Integrator_gainval_i
                                      * Referenced by: '<S88>/Integrator'
                                      */
  real_T Filter_gainval_p;             /* Computed Parameter: Filter_gainval_p
                                        * Referenced by: '<S83>/Filter'
                                        */
  real_T DiscreteTransferFcn_NumCoef;  /* Expression: [0.0165]
                                        * Referenced by: '<Root>/Discrete Transfer Fcn'
                                        */
  real_T DiscreteTransferFcn_DenCoef[2];/* Expression: [1 -0.9835]
                                         * Referenced by: '<Root>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  real_T Integrator_gainval_e;       /* Computed Parameter: Integrator_gainval_e
                                      * Referenced by: '<S138>/Integrator'
                                      */
  real_T Filter_gainval_j;             /* Computed Parameter: Filter_gainval_j
                                        * Referenced by: '<S133>/Filter'
                                        */
  real_T Integrator_gainval_b;       /* Computed Parameter: Integrator_gainval_b
                                      * Referenced by: '<S188>/Integrator'
                                      */
  real_T Filter_gainval_i;             /* Computed Parameter: Filter_gainval_i
                                        * Referenced by: '<S183>/Filter'
                                        */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S179>/Clamping_zero'
                                        */
  real_T Clamping_zero_Value_a;        /* Expression: 0
                                        * Referenced by: '<S129>/Clamping_zero'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Clamping_zero_Value_d;        /* Expression: 0
                                        * Referenced by: '<S79>/Clamping_zero'
                                        */
  real_T Clamping_zero_Value_f;        /* Expression: 0
                                        * Referenced by: '<S29>/Clamping_zero'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  int8_T Constant_Value_l;             /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S29>/Constant'
                                        */
  int8_T Constant2_Value;              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S29>/Constant2'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S29>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S29>/Constant4'
                                        */
  int8_T Constant_Value_a;             /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S79>/Constant'
                                        */
  int8_T Constant2_Value_b;            /* Computed Parameter: Constant2_Value_b
                                        * Referenced by: '<S79>/Constant2'
                                        */
  int8_T Constant3_Value_k;            /* Computed Parameter: Constant3_Value_k
                                        * Referenced by: '<S79>/Constant3'
                                        */
  int8_T Constant4_Value_o;            /* Computed Parameter: Constant4_Value_o
                                        * Referenced by: '<S79>/Constant4'
                                        */
  int8_T Constant_Value_p;             /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S129>/Constant'
                                        */
  int8_T Constant2_Value_c;            /* Computed Parameter: Constant2_Value_c
                                        * Referenced by: '<S129>/Constant2'
                                        */
  int8_T Constant3_Value_e;            /* Computed Parameter: Constant3_Value_e
                                        * Referenced by: '<S129>/Constant3'
                                        */
  int8_T Constant4_Value_k;            /* Computed Parameter: Constant4_Value_k
                                        * Referenced by: '<S129>/Constant4'
                                        */
  int8_T Constant_Value_n;             /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S179>/Constant'
                                        */
  int8_T Constant2_Value_o;            /* Computed Parameter: Constant2_Value_o
                                        * Referenced by: '<S179>/Constant2'
                                        */
  int8_T Constant3_Value_b;            /* Computed Parameter: Constant3_Value_b
                                        * Referenced by: '<S179>/Constant3'
                                        */
  int8_T Constant4_Value_oh;           /* Computed Parameter: Constant4_Value_oh
                                        * Referenced by: '<S179>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_TwoDOF_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_TwoDOF_T TwoDOF_P;

/* Block signals (default storage) */
extern B_TwoDOF_T TwoDOF_B;

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
 * '<S1>'   : 'TwoDOF/xPOSPID'
 * '<S2>'   : 'TwoDOF/xVELPID'
 * '<S3>'   : 'TwoDOF/yPOSPID'
 * '<S4>'   : 'TwoDOF/yVELPID'
 * '<S5>'   : 'TwoDOF/xPOSPID/Anti-windup'
 * '<S6>'   : 'TwoDOF/xPOSPID/D Gain'
 * '<S7>'   : 'TwoDOF/xPOSPID/Filter'
 * '<S8>'   : 'TwoDOF/xPOSPID/Filter ICs'
 * '<S9>'   : 'TwoDOF/xPOSPID/I Gain'
 * '<S10>'  : 'TwoDOF/xPOSPID/Ideal P Gain'
 * '<S11>'  : 'TwoDOF/xPOSPID/Ideal P Gain Fdbk'
 * '<S12>'  : 'TwoDOF/xPOSPID/Integrator'
 * '<S13>'  : 'TwoDOF/xPOSPID/Integrator ICs'
 * '<S14>'  : 'TwoDOF/xPOSPID/N Copy'
 * '<S15>'  : 'TwoDOF/xPOSPID/N Gain'
 * '<S16>'  : 'TwoDOF/xPOSPID/P Copy'
 * '<S17>'  : 'TwoDOF/xPOSPID/Parallel P Gain'
 * '<S18>'  : 'TwoDOF/xPOSPID/Reset Signal'
 * '<S19>'  : 'TwoDOF/xPOSPID/Saturation'
 * '<S20>'  : 'TwoDOF/xPOSPID/Saturation Fdbk'
 * '<S21>'  : 'TwoDOF/xPOSPID/Sum'
 * '<S22>'  : 'TwoDOF/xPOSPID/Sum Fdbk'
 * '<S23>'  : 'TwoDOF/xPOSPID/Tracking Mode'
 * '<S24>'  : 'TwoDOF/xPOSPID/Tracking Mode Sum'
 * '<S25>'  : 'TwoDOF/xPOSPID/Tsamp - Integral'
 * '<S26>'  : 'TwoDOF/xPOSPID/Tsamp - Ngain'
 * '<S27>'  : 'TwoDOF/xPOSPID/postSat Signal'
 * '<S28>'  : 'TwoDOF/xPOSPID/preSat Signal'
 * '<S29>'  : 'TwoDOF/xPOSPID/Anti-windup/Disc. Clamping Parallel'
 * '<S30>'  : 'TwoDOF/xPOSPID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S31>'  : 'TwoDOF/xPOSPID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S32>'  : 'TwoDOF/xPOSPID/D Gain/Internal Parameters'
 * '<S33>'  : 'TwoDOF/xPOSPID/Filter/Disc. Forward Euler Filter'
 * '<S34>'  : 'TwoDOF/xPOSPID/Filter ICs/Internal IC - Filter'
 * '<S35>'  : 'TwoDOF/xPOSPID/I Gain/Internal Parameters'
 * '<S36>'  : 'TwoDOF/xPOSPID/Ideal P Gain/Passthrough'
 * '<S37>'  : 'TwoDOF/xPOSPID/Ideal P Gain Fdbk/Disabled'
 * '<S38>'  : 'TwoDOF/xPOSPID/Integrator/Discrete'
 * '<S39>'  : 'TwoDOF/xPOSPID/Integrator ICs/Internal IC'
 * '<S40>'  : 'TwoDOF/xPOSPID/N Copy/Disabled'
 * '<S41>'  : 'TwoDOF/xPOSPID/N Gain/Internal Parameters'
 * '<S42>'  : 'TwoDOF/xPOSPID/P Copy/Disabled'
 * '<S43>'  : 'TwoDOF/xPOSPID/Parallel P Gain/Internal Parameters'
 * '<S44>'  : 'TwoDOF/xPOSPID/Reset Signal/Disabled'
 * '<S45>'  : 'TwoDOF/xPOSPID/Saturation/Enabled'
 * '<S46>'  : 'TwoDOF/xPOSPID/Saturation Fdbk/Disabled'
 * '<S47>'  : 'TwoDOF/xPOSPID/Sum/Sum_PID'
 * '<S48>'  : 'TwoDOF/xPOSPID/Sum Fdbk/Disabled'
 * '<S49>'  : 'TwoDOF/xPOSPID/Tracking Mode/Disabled'
 * '<S50>'  : 'TwoDOF/xPOSPID/Tracking Mode Sum/Passthrough'
 * '<S51>'  : 'TwoDOF/xPOSPID/Tsamp - Integral/TsSignalSpecification'
 * '<S52>'  : 'TwoDOF/xPOSPID/Tsamp - Ngain/Passthrough'
 * '<S53>'  : 'TwoDOF/xPOSPID/postSat Signal/Forward_Path'
 * '<S54>'  : 'TwoDOF/xPOSPID/preSat Signal/Forward_Path'
 * '<S55>'  : 'TwoDOF/xVELPID/Anti-windup'
 * '<S56>'  : 'TwoDOF/xVELPID/D Gain'
 * '<S57>'  : 'TwoDOF/xVELPID/Filter'
 * '<S58>'  : 'TwoDOF/xVELPID/Filter ICs'
 * '<S59>'  : 'TwoDOF/xVELPID/I Gain'
 * '<S60>'  : 'TwoDOF/xVELPID/Ideal P Gain'
 * '<S61>'  : 'TwoDOF/xVELPID/Ideal P Gain Fdbk'
 * '<S62>'  : 'TwoDOF/xVELPID/Integrator'
 * '<S63>'  : 'TwoDOF/xVELPID/Integrator ICs'
 * '<S64>'  : 'TwoDOF/xVELPID/N Copy'
 * '<S65>'  : 'TwoDOF/xVELPID/N Gain'
 * '<S66>'  : 'TwoDOF/xVELPID/P Copy'
 * '<S67>'  : 'TwoDOF/xVELPID/Parallel P Gain'
 * '<S68>'  : 'TwoDOF/xVELPID/Reset Signal'
 * '<S69>'  : 'TwoDOF/xVELPID/Saturation'
 * '<S70>'  : 'TwoDOF/xVELPID/Saturation Fdbk'
 * '<S71>'  : 'TwoDOF/xVELPID/Sum'
 * '<S72>'  : 'TwoDOF/xVELPID/Sum Fdbk'
 * '<S73>'  : 'TwoDOF/xVELPID/Tracking Mode'
 * '<S74>'  : 'TwoDOF/xVELPID/Tracking Mode Sum'
 * '<S75>'  : 'TwoDOF/xVELPID/Tsamp - Integral'
 * '<S76>'  : 'TwoDOF/xVELPID/Tsamp - Ngain'
 * '<S77>'  : 'TwoDOF/xVELPID/postSat Signal'
 * '<S78>'  : 'TwoDOF/xVELPID/preSat Signal'
 * '<S79>'  : 'TwoDOF/xVELPID/Anti-windup/Disc. Clamping Parallel'
 * '<S80>'  : 'TwoDOF/xVELPID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S81>'  : 'TwoDOF/xVELPID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S82>'  : 'TwoDOF/xVELPID/D Gain/Internal Parameters'
 * '<S83>'  : 'TwoDOF/xVELPID/Filter/Disc. Forward Euler Filter'
 * '<S84>'  : 'TwoDOF/xVELPID/Filter ICs/Internal IC - Filter'
 * '<S85>'  : 'TwoDOF/xVELPID/I Gain/Internal Parameters'
 * '<S86>'  : 'TwoDOF/xVELPID/Ideal P Gain/Passthrough'
 * '<S87>'  : 'TwoDOF/xVELPID/Ideal P Gain Fdbk/Disabled'
 * '<S88>'  : 'TwoDOF/xVELPID/Integrator/Discrete'
 * '<S89>'  : 'TwoDOF/xVELPID/Integrator ICs/Internal IC'
 * '<S90>'  : 'TwoDOF/xVELPID/N Copy/Disabled'
 * '<S91>'  : 'TwoDOF/xVELPID/N Gain/Internal Parameters'
 * '<S92>'  : 'TwoDOF/xVELPID/P Copy/Disabled'
 * '<S93>'  : 'TwoDOF/xVELPID/Parallel P Gain/Internal Parameters'
 * '<S94>'  : 'TwoDOF/xVELPID/Reset Signal/Disabled'
 * '<S95>'  : 'TwoDOF/xVELPID/Saturation/Enabled'
 * '<S96>'  : 'TwoDOF/xVELPID/Saturation Fdbk/Disabled'
 * '<S97>'  : 'TwoDOF/xVELPID/Sum/Sum_PID'
 * '<S98>'  : 'TwoDOF/xVELPID/Sum Fdbk/Disabled'
 * '<S99>'  : 'TwoDOF/xVELPID/Tracking Mode/Disabled'
 * '<S100>' : 'TwoDOF/xVELPID/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'TwoDOF/xVELPID/Tsamp - Integral/TsSignalSpecification'
 * '<S102>' : 'TwoDOF/xVELPID/Tsamp - Ngain/Passthrough'
 * '<S103>' : 'TwoDOF/xVELPID/postSat Signal/Forward_Path'
 * '<S104>' : 'TwoDOF/xVELPID/preSat Signal/Forward_Path'
 * '<S105>' : 'TwoDOF/yPOSPID/Anti-windup'
 * '<S106>' : 'TwoDOF/yPOSPID/D Gain'
 * '<S107>' : 'TwoDOF/yPOSPID/Filter'
 * '<S108>' : 'TwoDOF/yPOSPID/Filter ICs'
 * '<S109>' : 'TwoDOF/yPOSPID/I Gain'
 * '<S110>' : 'TwoDOF/yPOSPID/Ideal P Gain'
 * '<S111>' : 'TwoDOF/yPOSPID/Ideal P Gain Fdbk'
 * '<S112>' : 'TwoDOF/yPOSPID/Integrator'
 * '<S113>' : 'TwoDOF/yPOSPID/Integrator ICs'
 * '<S114>' : 'TwoDOF/yPOSPID/N Copy'
 * '<S115>' : 'TwoDOF/yPOSPID/N Gain'
 * '<S116>' : 'TwoDOF/yPOSPID/P Copy'
 * '<S117>' : 'TwoDOF/yPOSPID/Parallel P Gain'
 * '<S118>' : 'TwoDOF/yPOSPID/Reset Signal'
 * '<S119>' : 'TwoDOF/yPOSPID/Saturation'
 * '<S120>' : 'TwoDOF/yPOSPID/Saturation Fdbk'
 * '<S121>' : 'TwoDOF/yPOSPID/Sum'
 * '<S122>' : 'TwoDOF/yPOSPID/Sum Fdbk'
 * '<S123>' : 'TwoDOF/yPOSPID/Tracking Mode'
 * '<S124>' : 'TwoDOF/yPOSPID/Tracking Mode Sum'
 * '<S125>' : 'TwoDOF/yPOSPID/Tsamp - Integral'
 * '<S126>' : 'TwoDOF/yPOSPID/Tsamp - Ngain'
 * '<S127>' : 'TwoDOF/yPOSPID/postSat Signal'
 * '<S128>' : 'TwoDOF/yPOSPID/preSat Signal'
 * '<S129>' : 'TwoDOF/yPOSPID/Anti-windup/Disc. Clamping Parallel'
 * '<S130>' : 'TwoDOF/yPOSPID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S131>' : 'TwoDOF/yPOSPID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S132>' : 'TwoDOF/yPOSPID/D Gain/Internal Parameters'
 * '<S133>' : 'TwoDOF/yPOSPID/Filter/Disc. Forward Euler Filter'
 * '<S134>' : 'TwoDOF/yPOSPID/Filter ICs/Internal IC - Filter'
 * '<S135>' : 'TwoDOF/yPOSPID/I Gain/Internal Parameters'
 * '<S136>' : 'TwoDOF/yPOSPID/Ideal P Gain/Passthrough'
 * '<S137>' : 'TwoDOF/yPOSPID/Ideal P Gain Fdbk/Disabled'
 * '<S138>' : 'TwoDOF/yPOSPID/Integrator/Discrete'
 * '<S139>' : 'TwoDOF/yPOSPID/Integrator ICs/Internal IC'
 * '<S140>' : 'TwoDOF/yPOSPID/N Copy/Disabled'
 * '<S141>' : 'TwoDOF/yPOSPID/N Gain/Internal Parameters'
 * '<S142>' : 'TwoDOF/yPOSPID/P Copy/Disabled'
 * '<S143>' : 'TwoDOF/yPOSPID/Parallel P Gain/Internal Parameters'
 * '<S144>' : 'TwoDOF/yPOSPID/Reset Signal/Disabled'
 * '<S145>' : 'TwoDOF/yPOSPID/Saturation/Enabled'
 * '<S146>' : 'TwoDOF/yPOSPID/Saturation Fdbk/Disabled'
 * '<S147>' : 'TwoDOF/yPOSPID/Sum/Sum_PID'
 * '<S148>' : 'TwoDOF/yPOSPID/Sum Fdbk/Disabled'
 * '<S149>' : 'TwoDOF/yPOSPID/Tracking Mode/Disabled'
 * '<S150>' : 'TwoDOF/yPOSPID/Tracking Mode Sum/Passthrough'
 * '<S151>' : 'TwoDOF/yPOSPID/Tsamp - Integral/TsSignalSpecification'
 * '<S152>' : 'TwoDOF/yPOSPID/Tsamp - Ngain/Passthrough'
 * '<S153>' : 'TwoDOF/yPOSPID/postSat Signal/Forward_Path'
 * '<S154>' : 'TwoDOF/yPOSPID/preSat Signal/Forward_Path'
 * '<S155>' : 'TwoDOF/yVELPID/Anti-windup'
 * '<S156>' : 'TwoDOF/yVELPID/D Gain'
 * '<S157>' : 'TwoDOF/yVELPID/Filter'
 * '<S158>' : 'TwoDOF/yVELPID/Filter ICs'
 * '<S159>' : 'TwoDOF/yVELPID/I Gain'
 * '<S160>' : 'TwoDOF/yVELPID/Ideal P Gain'
 * '<S161>' : 'TwoDOF/yVELPID/Ideal P Gain Fdbk'
 * '<S162>' : 'TwoDOF/yVELPID/Integrator'
 * '<S163>' : 'TwoDOF/yVELPID/Integrator ICs'
 * '<S164>' : 'TwoDOF/yVELPID/N Copy'
 * '<S165>' : 'TwoDOF/yVELPID/N Gain'
 * '<S166>' : 'TwoDOF/yVELPID/P Copy'
 * '<S167>' : 'TwoDOF/yVELPID/Parallel P Gain'
 * '<S168>' : 'TwoDOF/yVELPID/Reset Signal'
 * '<S169>' : 'TwoDOF/yVELPID/Saturation'
 * '<S170>' : 'TwoDOF/yVELPID/Saturation Fdbk'
 * '<S171>' : 'TwoDOF/yVELPID/Sum'
 * '<S172>' : 'TwoDOF/yVELPID/Sum Fdbk'
 * '<S173>' : 'TwoDOF/yVELPID/Tracking Mode'
 * '<S174>' : 'TwoDOF/yVELPID/Tracking Mode Sum'
 * '<S175>' : 'TwoDOF/yVELPID/Tsamp - Integral'
 * '<S176>' : 'TwoDOF/yVELPID/Tsamp - Ngain'
 * '<S177>' : 'TwoDOF/yVELPID/postSat Signal'
 * '<S178>' : 'TwoDOF/yVELPID/preSat Signal'
 * '<S179>' : 'TwoDOF/yVELPID/Anti-windup/Disc. Clamping Parallel'
 * '<S180>' : 'TwoDOF/yVELPID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S181>' : 'TwoDOF/yVELPID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S182>' : 'TwoDOF/yVELPID/D Gain/Internal Parameters'
 * '<S183>' : 'TwoDOF/yVELPID/Filter/Disc. Forward Euler Filter'
 * '<S184>' : 'TwoDOF/yVELPID/Filter ICs/Internal IC - Filter'
 * '<S185>' : 'TwoDOF/yVELPID/I Gain/Internal Parameters'
 * '<S186>' : 'TwoDOF/yVELPID/Ideal P Gain/Passthrough'
 * '<S187>' : 'TwoDOF/yVELPID/Ideal P Gain Fdbk/Disabled'
 * '<S188>' : 'TwoDOF/yVELPID/Integrator/Discrete'
 * '<S189>' : 'TwoDOF/yVELPID/Integrator ICs/Internal IC'
 * '<S190>' : 'TwoDOF/yVELPID/N Copy/Disabled'
 * '<S191>' : 'TwoDOF/yVELPID/N Gain/Internal Parameters'
 * '<S192>' : 'TwoDOF/yVELPID/P Copy/Disabled'
 * '<S193>' : 'TwoDOF/yVELPID/Parallel P Gain/Internal Parameters'
 * '<S194>' : 'TwoDOF/yVELPID/Reset Signal/Disabled'
 * '<S195>' : 'TwoDOF/yVELPID/Saturation/Enabled'
 * '<S196>' : 'TwoDOF/yVELPID/Saturation Fdbk/Disabled'
 * '<S197>' : 'TwoDOF/yVELPID/Sum/Sum_PID'
 * '<S198>' : 'TwoDOF/yVELPID/Sum Fdbk/Disabled'
 * '<S199>' : 'TwoDOF/yVELPID/Tracking Mode/Disabled'
 * '<S200>' : 'TwoDOF/yVELPID/Tracking Mode Sum/Passthrough'
 * '<S201>' : 'TwoDOF/yVELPID/Tsamp - Integral/TsSignalSpecification'
 * '<S202>' : 'TwoDOF/yVELPID/Tsamp - Ngain/Passthrough'
 * '<S203>' : 'TwoDOF/yVELPID/postSat Signal/Forward_Path'
 * '<S204>' : 'TwoDOF/yVELPID/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_TwoDOF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
