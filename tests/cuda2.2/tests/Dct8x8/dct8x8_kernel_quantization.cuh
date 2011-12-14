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

/**
**************************************************************************
* \file dct8x8_kernel_quantization.cu
* \brief Contains unoptimized quantization routines. Device code.
*
* This code implements CUDA versions of quantization of Discrete Cosine 
* Transform coefficients with 8x8 blocks for float and short arrays. 
*/

#pragma once

#include "Common.h"


/**
*  JPEG quality=0_of_12 quantization matrix
*/
__constant__ short Q[] = {  
	32,  33,  51,  81,  66,  39,  34,  17,
	33,  36,  48,  47,  28,  23,  12,  12,
	51,  48,  47,  28,  23,  12,  12,  12,
	81,  47,  28,  23,  12,  12,  12,  12,
	66,  28,  23,  12,  12,  12,  12,  12,
	39,  23,  12,  12,  12,  12,  12,  12,
	34,  12,  12,  12,  12,  12,  12,  12,
	17,  12,  12,  12,  12,  12,  12,  12 
};


/**
**************************************************************************
*  Performs in-place quantization of given DCT coefficients plane using 
*  predefined quantization matrices (for floats plane). Unoptimized.
*
* \param SrcDst			[IN/OUT] - DCT coefficients plane
* \param Stride			[IN] - Stride of SrcDst
*  
* \return None
*/
__global__ void CUDAkernelQuantizationFloat(float *SrcDst, int Stride)
{
    // Block index
    int bx = blockIdx.x;
    int by = blockIdx.y;

    // Thread index (current coefficient)
    int tx = threadIdx.x;
    int ty = threadIdx.y;

	//copy current coefficient to the local variable
	float curCoef = SrcDst[ (by * BLOCK_SIZE + ty) * Stride + (bx * BLOCK_SIZE + tx) ];
	float curQuant = (float)Q[ ty * BLOCK_SIZE + tx ];

	//quantize the current coefficient
	float quantized = round( curCoef / curQuant );
	curCoef = quantized * curQuant;

	//copy quantized coefficient back to the DCT-plane
	SrcDst[ (by * BLOCK_SIZE + ty) * Stride + (bx * BLOCK_SIZE + tx) ] = curCoef;
}


/**
**************************************************************************
*  Performs in-place quantization of given DCT coefficients plane using 
*  predefined quantization matrices (for shorts plane). Unoptimized.
*
* \param SrcDst			[IN/OUT] - DCT coefficients plane
* \param Stride			[IN] - Stride of SrcDst
*  
* \return None
*/
__global__ void CUDAkernelQuantizationShort(short *SrcDst, int Stride)
{
	// Block index
	int bx = blockIdx.x;
	int by = blockIdx.y;

	// Thread index (current coefficient)
	int tx = threadIdx.x;
	int ty = threadIdx.y;

	//copy current coefficient to the local variable
	short curCoef = SrcDst[ (by * BLOCK_SIZE + ty) * Stride + (bx * BLOCK_SIZE + tx) ];
	short curQuant = Q[ty * BLOCK_SIZE + tx];

	//quantize the current coefficient
	if (curCoef < 0)
	{
		curCoef = -curCoef;
		curCoef += curQuant>>1;
		curCoef /= curQuant;
		curCoef = -curCoef;
	}
	else
	{
		curCoef += curQuant>>1;
		curCoef /= curQuant;
	}
	__syncthreads();

	curCoef = curCoef * curQuant;

	//copy quantized coefficient back to the DCT-plane
	SrcDst[ (by * BLOCK_SIZE + ty) * Stride + (bx * BLOCK_SIZE + tx) ] = curCoef;
}
