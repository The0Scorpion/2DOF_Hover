/* Copyright 2023 The MathWorks, Inc. */
#ifndef EXAMPLE_H
#define EXAMPLE_H
#if !( defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER))
#ifdef __cplusplus
#include "rtwtypes.h"
extern "C" {
    #endif
    void stepFunctionEncoders(double * X,int size_vector_1,double * Xdot,int size_vector_2,double * Y,int size_vector_3,double * Ydot,int size_vector_4,double IMU_X,int size_vector_a,double IMU_Y,int size_vector_b);
    void setupFunctionEncoders(uint8_T  EncXA,int size_vector__1,int8_T  EncXB,int size_vector__2,int8_T  EncYA,int size_vector__3,int8_T  EncYB,int size_vector__4);
    #ifdef __cplusplus
}
#endif
#else
#define loop(void) (0)
#define setup(void) (0)
#endif
#endif