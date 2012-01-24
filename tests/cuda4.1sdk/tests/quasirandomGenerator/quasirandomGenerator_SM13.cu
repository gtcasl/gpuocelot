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



#define DOUBLE_PRECISION
#include "quasirandomGenerator_kernel.cuh"



extern "C" void initTable_SM13(unsigned int tableCPU[QRNG_DIMENSIONS][QRNG_RESOLUTION]){
    initTableGPU(tableCPU);
}

extern "C" void quasirandomGenerator_SM13(float *d_Output, unsigned int seed, unsigned int N){
    quasirandomGeneratorGPU(d_Output, seed, N);
}

extern "C" void inverseCND_SM13(float *d_Output, unsigned int *d_Input, unsigned int N){
    inverseCNDgpu(d_Output, d_Input, N);
}
