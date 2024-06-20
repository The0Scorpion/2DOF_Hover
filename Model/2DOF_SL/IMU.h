/* Copyright 2023 The MathWorks, Inc. */
#ifndef EXAMPLE_H
#define EXAMPLE_H
#if !( defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER))
#ifdef __cplusplus
#include "rtwtypes.h"
extern "C" {
    #endif
    void stepFunctionIMU(double * IMU_X,int size_vector_1,double * IMU_Y,int size_vector_2);
    void setupFunctionIMU();
    #ifdef __cplusplus
}
#endif
#else
#define loop(void) (0)
#define setup(void) (0)
#endif
#endif