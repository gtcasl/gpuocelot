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

#ifndef SIMPLEVOTE_KERNEL_CU
#define SIMPLEVOTE_KERNEL_CU

////////////////////////////////////////////////////////////////////////////////
// Vote Any/All intrinsic kernel function tests are supported only by CUDA 
// capable devices that are CUDA hardware that has SM1.2 or later
// Vote Functions (refer to section 4.4.5 in the CUDA Orogramming Guide)
////////////////////////////////////////////////////////////////////////////////

// Kernel #1 tests the across-the-warp vote(any) intrinsic.  
// If ANY one of the threads (within the warp) of the predicated condition returns 
// a non-zero value, then all threads within this warp will return a non-zero value
__global__ void VoteAnyKernel1(unsigned int *input, unsigned int *result, int size)
{
	int tx = threadIdx.x + blockDim.x * blockIdx.x;

	result[tx] = any(input[tx]);
}

// Kernel #2 tests the across-the-warp vote(all) intrinsic.  
// If ALL of the threads (within the warp) of the predicated condition returns 
// a non-zero value, then all threads within this warp will return a non-zero value
__global__ void VoteAllKernel2(unsigned int *input, unsigned int *result, int size)
{
	int tx = threadIdx.x + blockDim.x * blockIdx.x;

	result[tx] = all(input[tx]);
}

// Kernel #3 is a directed test for the across-the-warp vote(all) intrinsic.
// This kernel will test for conditions across warps, and within half warps
__global__ void VoteAnyKernel3(bool *info, int warp_size) 
{ 
    int tx = threadIdx.x + blockDim.x * blockIdx.x;
    bool *offs = info + (tx * 3);

    // The following should hold true for the second and third warp
    *offs = any((tx >= (warp_size * 3) / 2));
    // The following should hold true for the "upper half" of the second warp, 
    // and all of the third warp	
    *(offs + 1) = (tx >= (warp_size * 3) / 2? true: false);
    // The following should hold true for the third warp only
    if(all((tx >= (warp_size * 3) / 2))) {
      *(offs + 2) = true;
    }
}

#endif
