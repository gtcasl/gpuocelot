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

#include <math.h>
#include <stdio.h>

#define min(a,b) (a) < (b) ? (a) : (b)
#define max(a,b) (a) > (b) ? (a) : (b)

////////////////////////////////////////////////////////////////////////////////
// export C interface
extern "C" 
int computeGold( int* gpuData, const int len);

////////////////////////////////////////////////////////////////////////////////
//! Compute reference data set
//! Each element is multiplied with the number of threads / array length
//! @param reference  reference data, computed but preallocated
//! @param idata      input data as provided to device
//! @param len        number of elements in reference / idata
////////////////////////////////////////////////////////////////////////////////
int
computeGold(int* gpuData, const int len) 
{
    int val = 0;
    for( int i = 0; i < len; ++i) 
    {
        val += 10;
    }
    if (val != gpuData[0])
    {
        printf("atomicAdd failed\n");
        return false;
    }

    val = 0;
    for( int i = 0; i < len; ++i) 
    {
        val -= 10;
    }
    if (val != gpuData[1])
    {
        printf("atomicSub failed\n");
        return false;
    }

    bool found = false;
    for( int i = 0; i < len; ++i) 
    {
        // third element should be a member of [0, len)
        if (i == gpuData[2])
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        printf("atomicExch failed\n");
        return false;
    }
    
    val = -(1 << 8);
    for( int i = 0; i < len; ++i) 
    {
        // fourth element should be len-1
        val = max(val, i);
    }
    if (val != gpuData[3])
    {
        printf("atomicMax failed\n");
        return false;
    }

    val = 1 << 8;
    for( int i = 0; i < len; ++i) 
    {
        val = min(val, i);
    }
    if (val != gpuData[4])
    {
        printf("atomicMin failed\n");
        return false;
    }

    int limit = 17;
    val = 0;
    for( int i = 0; i < len; ++i) 
    {
        val = (val >= limit) ? 0 : val+1;
    }
    if (val != gpuData[5])
    {
        printf("atomicInc failed\n");
        return false;
    }

    limit = 137;
    val = 0;
    for( int i = 0; i < len; ++i) 
    {
        val = ((val == 0) || (val > limit)) ? limit : val-1;
    }
    if (val != gpuData[6])
    {
        printf("atomicDec failed\n");
        return false;
    }
    
    found = false;
    for( int i = 0; i < len; ++i) 
    {
        // eighth element should be a member of [0, len)
        if (i == gpuData[7])
        {
            found = true;
            break;
        }
    }
    if (!found)
    {
        printf("atomicCAS failed\n");
        return false;
    }
    
    val = 0xff;
    for( int i = 0; i < len; ++i) 
    {
        // 9th element should be 1
        val &= (2 * i + 7);
    }
    if (val != gpuData[8])
    {
        printf("atomicAnd failed\n");
        return false;
    }

    val = 0;
    for( int i = 0; i < len; ++i) 
    {
        // 10th element should be 0xff
        val |= (1 << i);
    }
    if (val != gpuData[9])
    {
        printf("atomicOr failed\n");
        return false;
    }

    val = 0xff;
    for( int i = 0; i < len; ++i) 
    {
        // 11th element should be 0xff
        val ^= i;
    }
    if (val != gpuData[10])
    {
        printf("atomicXor failed\n");
        return false;
    }

    return true;
}

