/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */



#include "MonteCarlo_kernel.cuh"
#include "quasirandomGenerator_kernel.cuh"



extern "C" void initMonteCarlo_SM10(TOptionPlan *plan){
    initMonteCarloGPU(plan);
}

extern "C" void closeMonteCarlo_SM10(TOptionPlan *plan){
    closeMonteCarloGPU(plan);
}

extern "C" void MonteCarlo_SM10(TOptionPlan *plan){
    MonteCarloGPU(plan);
}

extern "C" void inverseCND_SM10(float *d_Output, float *d_Input, unsigned int N){
    inverseCNDgpu(d_Output, d_Input, N);
}
