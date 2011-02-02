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



#include "binomialOptions_kernel.cuh"


extern "C" void binomialOptions_SM10(
    float *callValue,
    TOptionData  *optionData,
    int optN
){
    binomialOptionsGPU(callValue, optionData, optN);
}

extern "C" int deviceEmulation(void){
    #ifdef __DEVICE_EMULATION__
        return 1;
    #else
        return 0;
    #endif
}
