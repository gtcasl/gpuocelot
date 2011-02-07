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



#ifndef REALTYPE_H
#define REALTYPE_H



//Throw out an error for unsupported target
#if defined(DOUBLE_PRECISION) && defined(__CUDACC__) && defined(CUDA_NO_SM_13_DOUBLE_INTRINSICS)
    #error -arch sm_13 nvcc flag is required to compile in double-precision mode
#endif


#ifndef DOUBLE_PRECISION
    typedef float real;
#else
    typedef double real;
#endif



#endif
