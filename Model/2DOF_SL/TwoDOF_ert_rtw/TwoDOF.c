/*
 * File: TwoDOF.c
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

#include "TwoDOF.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_TwoDOF_T TwoDOF_DW;

/* Real-time model */
static RT_MODEL_TwoDOF_T TwoDOF_M_;
RT_MODEL_TwoDOF_T *const TwoDOF_M = &TwoDOF_M_;

/* Model step function */
void TwoDOF_step(void)
{
  real_T b_varargout_1;
  real_T b_varargout_2;

  /* MATLABSystem: '<Root>/MATLAB System1' */
  if (TwoDOF_DW.obj.SampleTime != TwoDOF_P.MATLABSystem1_SampleTime) {
    TwoDOF_DW.obj.SampleTime = TwoDOF_P.MATLABSystem1_SampleTime;
  }

  /*         %% Define output properties */
  b_varargout_1 = 0.0;
  b_varargout_2 = 0.0;
  stepFunctionIMU(&b_varargout_1, 1.0, &b_varargout_2, 1.0);

  /* End of MATLABSystem: '<Root>/MATLAB System1' */
}

/* Model initialize function */
void TwoDOF_initialize(void)
{
  /* Start for MATLABSystem: '<Root>/MATLAB System1' */
  /*  Constructor */
  TwoDOF_DW.obj.matlabCodegenIsDeleted = false;
  TwoDOF_DW.obj.SampleTime = TwoDOF_P.MATLABSystem1_SampleTime;
  TwoDOF_DW.obj.isInitialized = 1;

  /*         %% Define output properties */
  /*   Check the input size */
  setupFunctionIMU();
  TwoDOF_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void TwoDOF_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/MATLAB System1' */
  if (!TwoDOF_DW.obj.matlabCodegenIsDeleted) {
    TwoDOF_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
