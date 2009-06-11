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
 
// Math functions and operators to be used with vector types.

#ifndef CUDAMATH_H
#define CUDAMATH_H

/*
#include <float.h>


inline __device__ __host__ float3 operator *(float3 a, float3 b)
{
    return make_float3(a.x*b.x, a.y*b.y, a.z*b.z);
}

inline __device__ __host__ float3 operator *(float f, float3 v)
{
    return make_float3(v.x*f, v.y*f, v.z*f);
}

inline __device__ __host__ float3 operator *(float3 v, float f)
{
    return make_float3(v.x*f, v.y*f, v.z*f);
}

inline __device__ __host__ void operator *=(float3 & b, float f)
{
    b.x *= f;
    b.y *= f;
    b.z *= f;
}

inline __device__ __host__ float3 operator +(float3 a, float3 b)
{
    return make_float3(a.x+b.x, a.y+b.y, a.z+b.z);
}

inline __device__ __host__ void operator +=(float3 & b, float3 a)
{
    b.x += a.x;
    b.y += a.y;
    b.z += a.z;
}

inline __device__ __host__ float3 operator -(float3 a, float3 b)
{
    return make_float3(a.x-b.x, a.y-b.y, a.z-b.z);
}

inline __device__ __host__ void operator -=(float3 & b, float3 a)
{
    b.x -= a.x;
    b.y -= a.y;
    b.z -= a.z;
}

inline __device__ __host__ float3 operator /(float3 v, float f)
{
    float inv = 1.0f / f;
    return v * inv;
}

inline __device__ __host__ void operator /=(float3 & b, float f)
{
    float inv = 1.0f / f;
    b.x *= inv;
    b.y *= inv;
    b.z *= inv;
}


inline __device__ __host__ float dot(float3 a, float3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline __device__ __host__ float dot(float4 a, float4 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline __device__ __host__ float clamp(float f, float a, float b)
{
    return max(a, min(f, b));
}

inline __device__ __host__ float3 clamp(float3 v, float a, float b)
{
    return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}

inline __device__ __host__ float3 clamp(float3 v, float3 a, float3 b)
{
    return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}


inline __device__ __host__ float3 normalize(float3 v)
{
    float len = 1.0f / sqrtf(dot(v, v));
    return make_float3(v.x * len, v.y * len, v.z * len);
}
*/



// Use power method to find the first eigenvector.
// http://www.miislita.com/information-retrieval-tutorial/matrix-tutorial-3-eigenvalues-eigenvectors.html
inline __device__ __host__ float3 firstEigenVector( float matrix[6] )
{
    // 8 iterations seems to be more than enough.

    float3 v = make_float3(1.0f, 1.0f, 1.0f);
    for(int i = 0; i < 8; i++) {
        float x = v.x * matrix[0] + v.y * matrix[1] + v.z * matrix[2];
        float y = v.x * matrix[1] + v.y * matrix[3] + v.z * matrix[4];
        float z = v.x * matrix[2] + v.y * matrix[4] + v.z * matrix[5];
        float m = max(max(x, y), z);        
        float iv = 1.0f / m;
        #if __DEVICE_EMULATION__
        if (m == 0.0f) iv = 0.0f;
        #endif
        v = make_float3(x*iv, y*iv, z*iv);
    }

    return v;
}

inline __device__ void colorSums(const float3 * colors, float3 * sums)
{
#if __DEVICE_EMULATION__
    float3 color_sum = make_float3(0.0f, 0.0f, 0.0f);
    for (int i = 0; i < 16; i++)
    {
        color_sum += colors[i];
    }

    for (int i = 0; i < 16; i++)
    {
        sums[i] = color_sum;
    }
#else

    const int idx = threadIdx.x;

    sums[idx] = colors[idx];
    sums[idx] += sums[idx^8];
    sums[idx] += sums[idx^4];
    sums[idx] += sums[idx^2];
    sums[idx] += sums[idx^1];

#endif
}


inline __device__ float3 bestFitLine(const float3 * colors, float3 color_sum)
{
    // Compute covariance matrix of the given colors.
#if __DEVICE_EMULATION__
    float covariance[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 16; i++)
    {
        float3 a = colors[i] - color_sum * (1.0f / 16.0f);
        covariance[0] += a.x * a.x;
        covariance[1] += a.x * a.y;
        covariance[2] += a.x * a.z;
        covariance[3] += a.y * a.y;
        covariance[4] += a.y * a.z;
        covariance[5] += a.z * a.z;
    }
#else

    const int idx = threadIdx.x;

    float3 diff = colors[idx] - color_sum * (1.0f / 16.0f);

    // @@ Eliminate two-way bank conflicts here.
    // @@ It seems that doing that and unrolling the reduction doesn't help...
    __shared__ float covariance[16*6];

    covariance[6 * idx + 0] = diff.x * diff.x;    // 0, 6, 12, 2, 8, 14, 4, 10, 0
    covariance[6 * idx + 1] = diff.x * diff.y;
    covariance[6 * idx + 2] = diff.x * diff.z;
    covariance[6 * idx + 3] = diff.y * diff.y;
    covariance[6 * idx + 4] = diff.y * diff.z;
    covariance[6 * idx + 5] = diff.z * diff.z;

    for(int d = 8; d > 0; d >>= 1)
    {
        if (idx < d)
        {
            covariance[6 * idx + 0] += covariance[6 * (idx+d) + 0];
            covariance[6 * idx + 1] += covariance[6 * (idx+d) + 1];
            covariance[6 * idx + 2] += covariance[6 * (idx+d) + 2];
            covariance[6 * idx + 3] += covariance[6 * (idx+d) + 3];
            covariance[6 * idx + 4] += covariance[6 * (idx+d) + 4];
            covariance[6 * idx + 5] += covariance[6 * (idx+d) + 5];
        }
    }

#endif

    // Compute first eigen vector.
    return firstEigenVector(covariance);
}


#endif // CUDAMATH_H
