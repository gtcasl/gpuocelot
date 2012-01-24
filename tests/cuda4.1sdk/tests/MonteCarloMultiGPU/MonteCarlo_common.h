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



#ifndef MONTECARLO_COMMON_H
#define MONTECARLO_COMMON_H
#include "realtype.h"



////////////////////////////////////////////////////////////////////////////////
// Global types
////////////////////////////////////////////////////////////////////////////////
typedef struct{
    float S;
    float X;
    float T;
    float R;
    float V;
} TOptionData;

typedef struct
#ifdef __CUDACC__
__align__(8)
#endif
{
    float Expected;
    float Confidence;
} TOptionValue;

//GPU outputs before CPU postprocessing
typedef struct{
    real Expected;
    real Confidence;
} __TOptionValue;



typedef struct{
    //Device ID for multi-GPU version
    int device;
    //Option count for this plan
    int optionCount;

    //Host-side data source and result destination
    TOptionData  *optionData;
    TOptionValue *callValue;

    //Temporary Host-side pinned memory for async + faster data transfers
    __TOptionValue *h_CallValue;


    //Intermediate device-side buffers
    void *d_Buffer;

    //(Pseudo/quasirandom) number generator seed
    unsigned int seed;
    //(Pseudo/quasirandom) samples count
    int pathN;
    //(Pseudo/quasirandom) samples device storage
    float *d_Samples;

    //Time stamp
    float time;
} TOptionPlan;



#endif
