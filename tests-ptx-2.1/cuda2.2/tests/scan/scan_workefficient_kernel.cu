/*
 * Copyright 1993-2006 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and 
 * international Copyright laws.  
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE 
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR 
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.   
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS 
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE 
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE 
 * OR PERFORMANCE OF THIS SOURCE CODE.  
 *
 * U.S. Government End Users.  This source code is a "commercial item" as 
 * that term is defined at 48 C.F.R. 2.101 (OCT 1995), consisting  of 
 * "commercial computer software" and "commercial computer software 
 * documentation" as such terms are used in 48 C.F.R. 12.212 (SEPT 1995) 
 * and is provided to the U.S. Government only as a commercial end item.  
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through 
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the 
 * source code with only those rights set forth herein.
 */

#ifndef _SCAN_WORKEFFICIENT_KERNEL_H_
#define _SCAN_WORKEFFICIENT_KERNEL_H_

///////////////////////////////////////////////////////////////////////////////
//! Work-efficient compute implementation of scan, one thread per 2 elements
//! Work-efficient: O(log(n)) steps, and O(n) adds.
//! Also shared storage efficient: Uses n elements in shared mem -- no ping-ponging
//! Uses a balanced tree type algorithm.  See Blelloch, 1990 "Prefix Sums 
//! and Their Applications", or Prins and Chatterjee PRAM course notes:
//! http://www.cs.unc.edu/~prins/Classes/203/Handouts/pram.pdf
//!
//! Pro: Work Efficient
//! Con: Shared memory bank conflicts due to the addressing used.
//
//! @param g_odata  output data in global memory
//! @param g_idata  input data in global memory
//! @param n        input number of elements to scan from input data
///////////////////////////////////////////////////////////////////////////////
__global__ void scan_workefficient(float *g_odata, float *g_idata, int n)
{
    // Dynamically allocated shared memory for scan kernels
    extern  __shared__  float temp[];

    int thid = threadIdx.x;

    int offset = 1;

    // Cache the computational window in shared memory
    temp[2*thid]   = g_idata[2*thid];
    temp[2*thid+1] = g_idata[2*thid+1];

    // build the sum in place up the tree
    for (int d = n>>1; d > 0; d >>= 1)
    {
        __syncthreads();

        if (thid < d)      
        {
            int ai = offset*(2*thid+1)-1;
            int bi = offset*(2*thid+2)-1;

            temp[bi] += temp[ai];
        }

        offset *= 2;
    }

    // scan back down the tree

    // clear the last element
    if (thid == 0)
    {
        temp[n - 1] = 0;
    }   

    // traverse down the tree building the scan in place
    for (int d = 1; d < n; d *= 2)
    {
        offset >>= 1;
        __syncthreads();

        if (thid < d)
        {
            int ai = offset*(2*thid+1)-1;
            int bi = offset*(2*thid+2)-1;

            float t   = temp[ai];
            temp[ai]  = temp[bi];
            temp[bi] += t;
        }
    }

    __syncthreads();

    // write results to global memory
    g_odata[2*thid]   = temp[2*thid];
    g_odata[2*thid+1] = temp[2*thid+1];
}

#endif // #ifndef _SCAN_WORKEFFICIENT_KERNEL_H_
