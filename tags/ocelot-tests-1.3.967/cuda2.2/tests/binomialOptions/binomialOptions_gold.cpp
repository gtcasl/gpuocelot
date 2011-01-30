/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and
 * international Copyright laws.  Users and possessors of this source code
 * are hereby granted a nonexclusive, royalty-free license to use this code
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 *
 * U.S. Government End Users.   This source code is a "commercial item" as
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
 * "commercial computer  software"  and "commercial computer software
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
 * and is provided to the U.S. Government only as a commercial end item.
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
 * source code with only those rights set forth herein.
 *
 * Any use of this source code in individual and commercial software must
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */



#include <stdio.h>
#include <math.h>
#include "binomialOptions_common.h"




///////////////////////////////////////////////////////////////////////////////
// Polynomial approximation of cumulative normal distribution function
///////////////////////////////////////////////////////////////////////////////
static double CND(double d){
    const double       A1 = 0.31938153;
    const double       A2 = -0.356563782;
    const double       A3 = 1.781477937;
    const double       A4 = -1.821255978;
    const double       A5 = 1.330274429;
    const double RSQRT2PI = 0.39894228040143267793994605993438;

    double
        K = 1.0 / (1.0 + 0.2316419 * fabs(d));

    double
        cnd = RSQRT2PI * exp(- 0.5 * d * d) * 
        (K * (A1 + K * (A2 + K * (A3 + K * (A4 + K * A5)))));

    if(d > 0)
        cnd = 1.0 - cnd;

    return cnd;
}

extern "C" void BlackScholesCall(
    float& callResult,
    TOptionData optionData
){
    double S = optionData.S;
    double X = optionData.X;
    double T = optionData.T;
    double R = optionData.R;
    double V = optionData.V;

    double sqrtT = sqrt(T);
    double    d1 = (log(S / X) + (R + 0.5 * V * V) * T) / (V * sqrtT);
    double    d2 = d1 - V * sqrtT;
    double CNDD1 = CND(d1);
    double CNDD2 = CND(d2);

    //Calculate Call and Put simultaneously
    double expRT = exp(- R * T);
    callResult   = (float)(S * CNDD1 - X * expRT * CNDD2);
}



////////////////////////////////////////////////////////////////////////////////
// Process an array of OptN options on CPU
// Note that CPU code is for correctness testing only and not for benchmarking.
////////////////////////////////////////////////////////////////////////////////
static double expiryCallValue(double S, double X, double vDt, int i){
    double d = S * exp(vDt * (2.0 * i - NUM_STEPS)) - X;
    return (d > 0) ? d : 0;
}

extern "C" void binomialOptionsCPU(
    float& callResult,
    TOptionData optionData
){
    static double Call[NUM_STEPS + 1];

    const double       S = optionData.S;
    const double       X = optionData.X;
    const double       T = optionData.T;
    const double       R = optionData.R;
    const double       V = optionData.V;

    const double      dt = T / (double)NUM_STEPS;
    const double     vDt = V * sqrt(dt);
    const double     rDt = R * dt;
    //Per-step interest and discount factors
    const double      If = exp(rDt);
    const double      Df = exp(-rDt);
    //Values and pseudoprobabilities of upward and downward moves
    const double       u = exp(vDt);
    const double       d = exp(-vDt);
    const double      pu = (If - d) / (u - d);
    const double      pd = 1.0 - pu;
    const double  puByDf = pu * Df;
    const double  pdByDf = pd * Df;

    ///////////////////////////////////////////////////////////////////////
    // Compute values at expiration date:
    // call option value at period end is V(T) = S(T) - X
    // if S(T) is greater than X, or zero otherwise.
    // The computation is similar for put options.
    ///////////////////////////////////////////////////////////////////////
    for(int i = 0; i <= NUM_STEPS; i++)
        Call[i] = expiryCallValue(S, X, vDt, i);

    ////////////////////////////////////////////////////////////////////////
    // Walk backwards up binomial tree
    ////////////////////////////////////////////////////////////////////////
    for(int i = NUM_STEPS; i > 0; i--)
        for(int j = 0; j <= i - 1; j++)
            Call[j] = puByDf * Call[j + 1] + pdByDf * Call[j];

    callResult = (float)Call[0];
}
