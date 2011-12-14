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
#include <stdlib.h>

#include <cutil_inline.h>

#include "bitonic_kernel.cu"

//
// A sorting network is a sorting algorith, where the sequence of comparisons
// is not data-dependent. That makes them suitable for parallel implementations.
//
// Bitonic sort is one of the fastest sorting networks, consisting of o(n log^2 n)
// comparators. It has a simple implemention and it's very efficient when sorting 
// a small number of elements:
//
// http://citeseer.ist.psu.edu/blelloch98experimental.html
//
// This implementation is based on:
//
// http://www.tools-of-computing.com/tc/CS/Sorts/bitonic_sort.htm
//

int main(int argc, char** argv)
{
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
		cutilDeviceInit(argc, argv);
	else
		cudaSetDevice( cutGetMaxGflopsDeviceId() );

    int values[NUM];

    for(int i = 0; i < NUM; i++)
    {
        values[i] = rand();
    }

    int * dvalues;
    cutilSafeCall(cudaMalloc((void**)&dvalues, sizeof(int) * NUM));
    cutilSafeCall(cudaMemcpy(dvalues, values, sizeof(int) * NUM, cudaMemcpyHostToDevice));

    bitonicSort<<<1, NUM, sizeof(int) * NUM>>>(dvalues);

    // check for any errors
    cutilCheckMsg("Kernel execution failed");

    cutilSafeCall(cudaMemcpy(values, dvalues, sizeof(int) * NUM, cudaMemcpyDeviceToHost));

    cutilSafeCall(cudaFree(dvalues));

    bool passed = true;
    for(int i = 1; i < NUM; i++)
    {
        if (values[i-1] > values[i])
        {
            passed = false;
        }
    }

    printf( "Test %s\n", passed ? "PASSED" : "FAILED");

    cudaThreadExit();

    cutilExit(argc, argv);
}
