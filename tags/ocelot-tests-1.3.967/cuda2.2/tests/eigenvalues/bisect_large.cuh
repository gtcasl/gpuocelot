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

#ifndef _BISECT_LARGE_CUH_
#define _BISECT_LARGE_CUH_

extern "C" {

////////////////////////////////////////////////////////////////////////////////
//! Run the kernels to compute the eigenvalues for large matrices
//! @param  input   handles to input data
//! @param  result  handles to result data 
//! @param  mat_size  matrix size
//! @param  precision  desired precision of eigenvalues
//! @param  lg  lower limit of Gerschgorin interval
//! @param  ug  upper limit of Gerschgorin interval
//! @param  iterations  number of iterations (for timing)
////////////////////////////////////////////////////////////////////////////////
void
computeEigenvaluesLargeMatrix( const InputData& input, const ResultDataLarge& result,
                               const unsigned int mat_size, const float precision,
                               const float lg, const float ug,
                               const unsigned int iterations );

////////////////////////////////////////////////////////////////////////////////
//! Initialize variables and memory for result
//! @param  result handles to memory
//! @param  matr_size  size of the matrix
////////////////////////////////////////////////////////////////////////////////
void
initResultDataLargeMatrix( ResultDataLarge& result, const unsigned int mat_size);

////////////////////////////////////////////////////////////////////////////////
//! Cleanup result memory
//! @param result  handles to memory
////////////////////////////////////////////////////////////////////////////////
void
cleanupResultDataLargeMatrix( ResultDataLarge& result);

////////////////////////////////////////////////////////////////////////////////
//! Process the result, that is obtain result from device and do simple sanity
//! checking
//! @param  input   handles to input data
//! @param  result  handles to result data
//! @param  mat_size  matrix size
//! @param  filename  output filename
////////////////////////////////////////////////////////////////////////////////
void
processResultDataLargeMatrix( const InputData& input, const ResultDataLarge& result,
                        const unsigned int mat_size, 
                        const char* filename,
                        const unsigned int user_defined, char* exec_path);

};
  
#endif // #ifndef _BISECT_LARGE_CUH_

