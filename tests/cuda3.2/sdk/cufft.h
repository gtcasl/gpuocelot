/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
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

/*
* cufft.h  
* Public header file for the NVIDIA Cuda FFT library (CUFFT)  
*/ 
#ifndef _CUFFT_H_
#define _CUFFT_H_


#include <stdio.h>
#include "cuComplex.h"
#include "driver_types.h"

#ifndef CUFFTAPI
#ifdef _WIN32
#define CUFFTAPI __stdcall
#else
#define CUFFTAPI 
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

// CUFFT API function return values 
typedef enum cufftResult_t {
  CUFFT_SUCCESS        = 0x0,
  CUFFT_INVALID_PLAN   = 0x1,
  CUFFT_ALLOC_FAILED   = 0x2,
  CUFFT_INVALID_TYPE   = 0x3,
  CUFFT_INVALID_VALUE  = 0x4,
  CUFFT_INTERNAL_ERROR = 0x5,
  CUFFT_EXEC_FAILED    = 0x6,
  CUFFT_SETUP_FAILED   = 0x7,
  CUFFT_INVALID_SIZE   = 0x8,
  CUFFT_UNALIGNED_DATA = 0x9
} cufftResult;
    
// CUFFT defines and supports the following data types

// cufftHandle is a handle type used to store and access CUFFT plans.
typedef unsigned int cufftHandle;

// cufftReal is a single-precision, floating-point real data type.
// cufftDoubleReal is a double-precision, real data type.
typedef float cufftReal;
typedef double cufftDoubleReal;

// cufftComplex is a single-precision, floating-point complex data type that 
// consists of interleaved real and imaginary components.
// cufftDoubleComplex is the double-precision equivalent.
typedef cuComplex cufftComplex;
typedef cuDoubleComplex cufftDoubleComplex;

// CUFFT transform directions 
#define CUFFT_FORWARD -1 // Forward FFT
#define CUFFT_INVERSE  1 // Inverse FFT

// CUFFT supports the following transform types 
typedef enum cufftType_t {
  CUFFT_R2C = 0x2a,     // Real to Complex (interleaved)
  CUFFT_C2R = 0x2c,     // Complex (interleaved) to Real
  CUFFT_C2C = 0x29,     // Complex to Complex, interleaved
  CUFFT_D2Z = 0x6a,     // Double to Double-Complex
  CUFFT_Z2D = 0x6c,     // Double-Complex to Double
  CUFFT_Z2Z = 0x69      // Double-Complex to Double-Complex
} cufftType;

// Certain R2C and C2R transforms go much more slowly when FFTW memory
// layout and behaviour is required. The default is "best performance",
// which means not-compatible-with-fftw. Use the cufftSetCompatibilityMode
// API to enable exact FFTW-like behaviour.
//
// These flags can be ORed together to select precise FFTW compatibility
// behaviour. The two levels presently supported are:
//
//  CUFFT_COMPATIBILITY_FFTW_PADDING
//      Inserts extra padding between packed in-place transforms for
//      batched transforms with power-of-2 size.
//
//  CUFFT_COMPATIBILITY_FFTW_C2R_ASYMMETRIC
//      Guarantees FFTW-compatible output for non-symmetric complex inputs
//      for transforms with power-of-2 size. This is only useful for
//      artificial (i.e. random) datasets as actual data will always be
//      symmetric if it has come from the real plane. If you don't
//      understand what this means, you probably don't have to use it.
//
//  CUFFT_COMPATIBILITY_FFTW
//      For convenience, enables all FFTW compatibility modes at once.
//
typedef enum cufftCompatibility_t {
    CUFFT_COMPATIBILITY_NATIVE          = 0x00, 
    CUFFT_COMPATIBILITY_FFTW_PADDING    = 0x01,    // The default value
    CUFFT_COMPATIBILITY_FFTW_ASYMMETRIC = 0x02,
    CUFFT_COMPATIBILITY_FFTW_ALL        = 0x03
} cufftCompatibility;

#define CUFFT_COMPATIBILITY_DEFAULT   CUFFT_COMPATIBILITY_FFTW_PADDING

cufftResult CUFFTAPI cufftPlan1d(cufftHandle *plan, 
                                 int nx, 
                                 cufftType type, 
                                 int batch /* deprecated - use cufftPlanMany */);

cufftResult CUFFTAPI cufftPlan2d(cufftHandle *plan, 
                                 int nx, int ny,
                                 cufftType type);

cufftResult CUFFTAPI cufftPlan3d(cufftHandle *plan, 
                                 int nx, int ny, int nz, 
                                 cufftType type);

cufftResult CUFFTAPI cufftPlanMany(cufftHandle *plan,
                                   int rank,
                                   int *n,
                                   int *inembed, int istride, int idist,    // Unused: pass "NULL, 1, 0"
                                   int *onembed, int ostride, int odist,    // Unused: pass "NULL, 1, 0"
                                   cufftType type,
                                   int batch);

cufftResult CUFFTAPI cufftDestroy(cufftHandle plan);

cufftResult CUFFTAPI cufftExecC2C(cufftHandle plan, 
                                  cufftComplex *idata,
                                  cufftComplex *odata,
                                  int direction);

cufftResult CUFFTAPI cufftExecR2C(cufftHandle plan, 
                                  cufftReal *idata,
                                  cufftComplex *odata);

cufftResult CUFFTAPI cufftExecC2R(cufftHandle plan, 
                                  cufftComplex *idata,
                                  cufftReal *odata);

cufftResult CUFFTAPI cufftExecZ2Z(cufftHandle plan, 
                                  cufftDoubleComplex *idata,
                                  cufftDoubleComplex *odata,
                                  int direction);

cufftResult CUFFTAPI cufftExecD2Z(cufftHandle plan, 
                                  cufftDoubleReal *idata,
                                  cufftDoubleComplex *odata);

cufftResult CUFFTAPI cufftExecZ2D(cufftHandle plan, 
                                  cufftDoubleComplex *idata,
                                  cufftDoubleReal *odata);

cufftResult CUFFTAPI cufftSetStream(cufftHandle plan,
                                    cudaStream_t stream);

cufftResult CUFFTAPI cufftSetCompatibilityMode(cufftHandle plan,
                                               cufftCompatibility mode);
#ifdef __cplusplus
}
#endif

#endif /* _CUFFT_H_ */
