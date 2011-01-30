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

/* Computation of eigenvalues of a small bidiagonal matrix */

#ifndef _BISECT_SMALL_CUH_
#define _BISECT_SMALL_CUH_

extern "C" {

////////////////////////////////////////////////////////////////////////////////
//! Determine eigenvalues for matrices smaller than MAX_SMALL_MATRIX
//! @param TimingIterations  number of iterations for timing
//! @param  input  handles to input data of kernel
//! @param  result handles to result of kernel
//! @param  mat_size  matrix size
//! @param  lg  lower limit of Gerschgorin interval
//! @param  ug  upper limit of Gerschgorin interval
//! @param  precision  desired precision of eigenvalues
//! @param  iterations  number of iterations for timing 
////////////////////////////////////////////////////////////////////////////////
void
computeEigenvaluesSmallMatrix( const InputData& input, ResultDataSmall& result, 
                               const unsigned int mat_size,
                               const float lg, const float ug,
                               const float precision,
                               const unsigned int iterations );

////////////////////////////////////////////////////////////////////////////////
//! Initialize variables and memory for the result for small matrices
//! @param result  handles to the necessary memory
//! @param  mat_size  matrix_size
////////////////////////////////////////////////////////////////////////////////
void 
initResultSmallMatrix( ResultDataSmall& result, const unsigned int mat_size);

////////////////////////////////////////////////////////////////////////////////
//! Cleanup memory and variables for result for small matrices
//! @param  result  handle to variables
////////////////////////////////////////////////////////////////////////////////
void 
cleanupResultSmallMatrix( ResultDataSmall& result);

////////////////////////////////////////////////////////////////////////////////
//! Process the result obtained on the device, that is transfer to host and
//! perform basic sanity checking
//! @param  input   handles to input data
//! @param  result  handles to result variables
//! @param  mat_size   matrix size
//! @param  filename  output filename
////////////////////////////////////////////////////////////////////////////////
void
processResultSmallMatrix( const InputData& input, const ResultDataSmall& result,
                    const unsigned int mat_size, const char* filename);

}
  
#endif // #ifndef _BISECT_SMALL_CUH_
