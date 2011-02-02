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



#ifndef QUASIRANDOMGENERATOR_KERNEL_CUH
#define QUASIRANDOMGENERATOR_KERNEL_CUH



#include <stdlib.h>
#include <stdio.h>
#include <cutil_inline.h>
#include "realtype.h"



//Fast integer multiplication
#define MUL(a, b) __umul24(a, b)



////////////////////////////////////////////////////////////////////////////////
// Moro's Inverse Cumulative Normal Distribution function approximation
////////////////////////////////////////////////////////////////////////////////
#ifndef DOUBLE_PRECISION
__device__ inline float MoroInvCNDgpu(float P){
    const float a1 = 2.50662823884f;
    const float a2 = -18.61500062529f;
    const float a3 = 41.39119773534f;
    const float a4 = -25.44106049637f;
    const float b1 = -8.4735109309f;
    const float b2 = 23.08336743743f;
    const float b3 = -21.06224101826f;
    const float b4 = 3.13082909833f;
    const float c1 = 0.337475482272615f;
    const float c2 = 0.976169019091719f;
    const float c3 = 0.160797971491821f;
    const float c4 = 2.76438810333863E-02f;
    const float c5 = 3.8405729373609E-03f;
    const float c6 = 3.951896511919E-04f;
    const float c7 = 3.21767881768E-05f;
    const float c8 = 2.888167364E-07f;
    const float c9 = 3.960315187E-07f;
    float y, z;

    if(P <= 0 || P >= 1.0f)
        return __int_as_float(0x7FFFFFFF);

    y = P - 0.5f;
    if(fabsf(y) < 0.42f){
        z = y * y;
        z = y * (((a4 * z + a3) * z + a2) * z + a1) / ((((b4 * z + b3) * z + b2) * z + b1) * z + 1.0f);
    }else{
        if(y > 0)
            z = __logf(-__logf(1.0f - P));
        else
            z = __logf(-__logf(P));

        z = c1 + z * (c2 + z * (c3 + z * (c4 + z * (c5 + z * (c6 + z * (c7 + z * (c8 + z * c9)))))));
        if(y < 0) z = -z;
    }

    return z;
}
#else
__device__ inline double MoroInvCNDgpu(double P){
    const double a1 = 2.50662823884;
    const double a2 = -18.61500062529;
    const double a3 = 41.39119773534;
    const double a4 = -25.44106049637;
    const double b1 = -8.4735109309;
    const double b2 = 23.08336743743;
    const double b3 = -21.06224101826;
    const double b4 = 3.13082909833;
    const double c1 = 0.337475482272615;
    const double c2 = 0.976169019091719;
    const double c3 = 0.160797971491821;
    const double c4 = 2.76438810333863E-02;
    const double c5 = 3.8405729373609E-03;
    const double c6 = 3.951896511919E-04;
    const double c7 = 3.21767881768E-05;
    const double c8 = 2.888167364E-07;
    const double c9 = 3.960315187E-07;
    double y, z;

    if(P <= 0 || P >= 1.0)
        return __longlong_as_double(0xFFF8000000000000ULL);

    y = P - 0.5;
    if(fabs(y) < 0.42){
        z = y * y;
        z = y * (((a4 * z + a3) * z + a2) * z + a1) / ((((b4 * z + b3) * z + b2) * z + b1) * z + 1.0);
    }else{
        if(y > 0)
            z = log(-log(1.0 - P));
        else
            z = log(-log(P));

        z = c1 + z * (c2 + z * (c3 + z * (c4 + z * (c5 + z * (c6 + z * (c7 + z * (c8 + z * c9)))))));
        if(y < 0) z = -z;
    }

    return z;
}
#endif

////////////////////////////////////////////////////////////////////////////////
// Acklam's Inverse Cumulative Normal Distribution function approximation
////////////////////////////////////////////////////////////////////////////////
#ifndef DOUBLE_PRECISION
__device__ inline float AcklamInvCNDgpu(float P){
    const float   a1 = -39.6968302866538f;
    const float   a2 = 220.946098424521f;
    const float   a3 = -275.928510446969f;
    const float   a4 = 138.357751867269f;
    const float   a5 = -30.6647980661472f;
    const float   a6 = 2.50662827745924f;
    const float   b1 = -54.4760987982241f;
    const float   b2 = 161.585836858041f;
    const float   b3 = -155.698979859887f;
    const float   b4 = 66.8013118877197f;
    const float   b5 = -13.2806815528857f;
    const float   c1 = -7.78489400243029E-03f;
    const float   c2 = -0.322396458041136f;
    const float   c3 = -2.40075827716184f;
    const float   c4 = -2.54973253934373f;
    const float   c5 = 4.37466414146497f;
    const float   c6 = 2.93816398269878f;
    const float   d1 = 7.78469570904146E-03f;
    const float   d2 = 0.32246712907004f;
    const float   d3 = 2.445134137143f;
    const float   d4 = 3.75440866190742f;
    const float  low = 0.02425f;
    const float high = 1.0f - low;
    float z, R;

    if(P <= 0 || P >= 1.0f)
        return __int_as_float(0x7FFFFFFF);

    if(P < low){
        z = sqrtf(-2.0f * __logf(P));
        z = (((((c1 * z + c2) * z + c3) * z + c4) * z + c5) * z + c6) /
            ((((d1 * z + d2) * z + d3) * z + d4) * z + 1.0f);
    }else{
        if(P > high){
            z = sqrtf(-2.0 * __logf(1.0 - P));
            z = -(((((c1 * z + c2) * z + c3) * z + c4) * z + c5) * z + c6) /
                 ((((d1 * z + d2) * z + d3) * z + d4) * z + 1.0f);
        }else{
            z = P - 0.5f;
            R = z * z;
            z = (((((a1 * R + a2) * R + a3) * R + a4) * R + a5) * R + a6) * z /
                (((((b1 * R + b2) * R + b3) * R + b4) * R + b5) * R + 1.0f);
        }
    }

    return z;
}
#else
__device__ inline double AcklamInvCNDgpu(double P){
    const double   a1 = -39.6968302866538;
    const double   a2 = 220.946098424521;
    const double   a3 = -275.928510446969;
    const double   a4 = 138.357751867269;
    const double   a5 = -30.6647980661472;
    const double   a6 = 2.50662827745924;
    const double   b1 = -54.4760987982241;
    const double   b2 = 161.585836858041;
    const double   b3 = -155.698979859887;
    const double   b4 = 66.8013118877197;
    const double   b5 = -13.2806815528857;
    const double   c1 = -7.78489400243029E-03;
    const double   c2 = -0.322396458041136;
    const double   c3 = -2.40075827716184;
    const double   c4 = -2.54973253934373;
    const double   c5 = 4.37466414146497;
    const double   c6 = 2.93816398269878;
    const double   d1 = 7.78469570904146E-03;
    const double   d2 = 0.32246712907004;
    const double   d3 = 2.445134137143;
    const double   d4 = 3.75440866190742;
    const double  low = 0.02425;
    const double high = 1.0 - low;
    double z, R;

    if(P <= 0 || P >= 1.0)
        return __longlong_as_double(0xFFF8000000000000ULL);

    if(P < low){
        z = sqrt(-2.0 * log(P));
        z = (((((c1 * z + c2) * z + c3) * z + c4) * z + c5) * z + c6) /
            ((((d1 * z + d2) * z + d3) * z + d4) * z + 1.0);
    }else{
        if(P > high){
            z = sqrt(-2.0 * log(1.0 - P));
            z = -(((((c1 * z + c2) * z + c3) * z + c4) * z + c5) * z + c6) /
                 ((((d1 * z + d2) * z + d3) * z + d4) * z + 1.0);
        }else{
            z = P - 0.5;
            R = z * z;
            z = (((((a1 * R + a2) * R + a3) * R + a4) * R + a5) * R + a6) * z /
                (((((b1 * R + b2) * R + b3) * R + b4) * R + b5) * R + 1.0);
        }
    }

    return z;
}
#endif


////////////////////////////////////////////////////////////////////////////////
// Main kernel. Choose between transforming
// input sequence and uniform ascending (0, 1) sequence
////////////////////////////////////////////////////////////////////////////////
static __global__ void inverseCNDKernel(
    float *d_Output,
    float *d_Input,
    unsigned int pathN
){
    real q = (real)1.0 / (real)(pathN + 1);
    unsigned int     tid = MUL(blockDim.x, blockIdx.x) + threadIdx.x;
    unsigned int threadN = MUL(blockDim.x, gridDim.x);

    //Transform input number sequence if it's supplied
    if(d_Input){
        for(unsigned int pos = tid; pos < pathN; pos += threadN){
            real d = d_Input[pos];
            d_Output[pos] = (float)MoroInvCNDgpu(d);
        }
    }
    //Else generate input uniformly placed samples on the fly
    //and write to destination
    else{
        for(unsigned int pos = tid; pos < pathN; pos += threadN){
            real d = (real)(pos + 1) * q;
            d_Output[pos] = (float)MoroInvCNDgpu(d);
        }
    }
}

static void inverseCNDgpu(float *d_Output, float *d_Input, unsigned int N){
    inverseCNDKernel<<<128, 128>>>(d_Output, d_Input, N);
    cutilCheckMsg("inverseCNDKernel() execution failed.\n");
}



#endif
