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

#if !defined(__TEXTURE_FETCH_FUNCTIONS_H__)
#define __TEXTURE_FETCH_FUNCTIONS_H__

#if defined(__cplusplus) && defined(__CUDACC__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "builtin_types.h"
#include "cuda_texture_types.h"
#include "host_defines.h"
#include "texture_types.h"
#include "vector_functions.h"
#include "vector_types.h"

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/*DEVICE_BUILTIN*/
template<class T, enum cudaTextureReadMode readMode> extern __device__  uint4 __utexfetchi(texture<T, 1, readMode> t, int4 i);
/*DEVICE_BUILTIN*/
template<class T, enum cudaTextureReadMode readMode> extern __device__   int4 __itexfetchi(texture<T, 1, readMode> t, int4 i);
/*DEVICE_BUILTIN*/
template<class T, enum cudaTextureReadMode readMode> extern __device__ float4 __ftexfetchi(texture<T, 1, readMode> t, int4 i);

/*DEVICE_BUILTIN*/
template<class T, int dim, enum cudaTextureReadMode readMode> extern __device__  uint4 __utexfetch(texture<T, dim, readMode> t, float4 i, int d = dim);
/*DEVICE_BUILTIN*/
template<class T, int dim, enum cudaTextureReadMode readMode> extern __device__   int4 __itexfetch(texture<T, dim, readMode> t, float4 i, int d = dim);
/*DEVICE_BUILTIN*/
template<class T, int dim, enum cudaTextureReadMode readMode> extern __device__ float4 __ftexfetch(texture<T, dim, readMode> t, float4 i, int d = dim);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex1Dfetch(texture<char, 1, cudaReadModeElementType> t, int x)
{
#if __SIGNED_CHARS__
  int4 v  = __itexfetchi(t, make_int4(x, 0, 0, 0));
#else
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));
#endif

  return (char)v.x;
}

static __inline__ __device__ signed char tex1Dfetch(texture<signed char, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex1Dfetch(texture<unsigned char, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex1Dfetch(texture<char1, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex1Dfetch(texture<uchar1, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex1Dfetch(texture<char2, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex1Dfetch(texture<uchar2, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex1Dfetch(texture<char4, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex1Dfetch(texture<uchar4, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex1Dfetch(texture<short, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex1Dfetch(texture<unsigned short, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex1Dfetch(texture<short1, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex1Dfetch(texture<ushort1, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex1Dfetch(texture<short2, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex1Dfetch(texture<ushort2, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex1Dfetch(texture<short4, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex1Dfetch(texture<ushort4, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex1Dfetch(texture<int, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex1Dfetch(texture<unsigned int, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex1Dfetch(texture<int1, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex1Dfetch(texture<uint1, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex1Dfetch(texture<int2, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex1Dfetch(texture<uint2, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex1Dfetch(texture<int4, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex1Dfetch(texture<uint4, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex1Dfetch(texture<long, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex1Dfetch(texture<unsigned long, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex1Dfetch(texture<long1, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex1Dfetch(texture<ulong1, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex1Dfetch(texture<long2, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex1Dfetch(texture<ulong2, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex1Dfetch(texture<long4, 1, cudaReadModeElementType> t, int x)
{
  int4 v = __itexfetchi(t, make_int4(x, 0, 0, 0));

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex1Dfetch(texture<ulong4, 1, cudaReadModeElementType> t, int x)
{
  uint4 v = __utexfetchi(t, make_int4(x, 0, 0, 0));

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1Dfetch(texture<float, 1, cudaReadModeElementType> t, int x)
{
  float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0));

  return v.x;
}

static __inline__ __device__ float1 tex1Dfetch(texture<float1, 1, cudaReadModeElementType> t, int x)
{
  float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0));

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex1Dfetch(texture<float2, 1, cudaReadModeElementType> t, int x)
{
  float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0));

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex1Dfetch(texture<float4, 1, cudaReadModeElementType> t, int x)
{
  float4 v = __ftexfetchi(t, make_int4(x, 0, 0, 0));

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1Dfetch(texture<char, 1, cudaReadModeNormalizedFloat> t, int x)
{
#if __SIGNED_CHARS__
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
#else
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
#endif
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1Dfetch(texture<signed char, 1, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1Dfetch(texture<unsigned char, 1, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1Dfetch(texture<char1, 1, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1Dfetch(texture<uchar1, 1, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1Dfetch(texture<char2, 1, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1Dfetch(texture<uchar2, 1, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1Dfetch(texture<char4, 1, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1Dfetch(texture<uchar4, 1, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1Dfetch(texture<short, 1, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1Dfetch(texture<unsigned short, 1, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1Dfetch(texture<short1, 1, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1Dfetch(texture<ushort1, 1, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1Dfetch(texture<short2, 1, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1Dfetch(texture<ushort2, 1, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v  = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1Dfetch(texture<short4, 1, cudaReadModeNormalizedFloat> t, int x)
{
  int4 v   = __itexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1Dfetch(texture<ushort4, 1, cudaReadModeNormalizedFloat> t, int x)
{
  uint4 v   = __utexfetchi(t, make_int4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex1D(texture<char, 1, cudaReadModeElementType> t, float x)
{
#if __SIGNED_CHARS__
  int4 v  = __itexfetch(t, make_float4(x, 0, 0, 0));
#else
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));
#endif

  return (char)v.x;
}

static __inline__ __device__ signed char tex1D(texture<signed char, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex1D(texture<unsigned char, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex1D(texture<char1, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex1D(texture<uchar1, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex1D(texture<char2, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex1D(texture<uchar2, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex1D(texture<char4, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex1D(texture<uchar4, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex1D(texture<short, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex1D(texture<unsigned short, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex1D(texture<short1, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex1D(texture<ushort1, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex1D(texture<short2, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex1D(texture<ushort2, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex1D(texture<short4, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex1D(texture<ushort4, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex1D(texture<int, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex1D(texture<unsigned int, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex1D(texture<int1, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex1D(texture<uint1, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex1D(texture<int2, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex1D(texture<uint2, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex1D(texture<int4, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex1D(texture<uint4, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_uint4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex1D(texture<long, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex1D(texture<unsigned long, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex1D(texture<long1, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex1D(texture<ulong1, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex1D(texture<long2, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex1D(texture<ulong2, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex1D(texture<long4, 1, cudaReadModeElementType> t, float x)
{
  int4 v = __itexfetch(t, make_float4(x, 0, 0, 0));

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex1D(texture<ulong4, 1, cudaReadModeElementType> t, float x)
{
  uint4 v = __utexfetch(t, make_float4(x, 0, 0, 0));

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1D(texture<float, 1, cudaReadModeElementType> t, float x)
{
  float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0));

  return v.x;
}

static __inline__ __device__ float1 tex1D(texture<float1, 1, cudaReadModeElementType> t, float x)
{
  float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0));

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex1D(texture<float2, 1, cudaReadModeElementType> t, float x)
{
  float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0));

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex1D(texture<float4, 1, cudaReadModeElementType> t, float x)
{
  float4 v = __ftexfetch(t, make_float4(x, 0, 0, 0));

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1D(texture<char, 1, cudaReadModeNormalizedFloat> t, float x)
{
#if __SIGNED_CHARS__
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
#else
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
#endif
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1D(texture<signed char, 1, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1D(texture<unsigned char, 1, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1D(texture<char1, 1, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1D(texture<uchar1, 1, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1D(texture<char2, 1, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1D(texture<uchar2, 1, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1D(texture<char4, 1, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1D(texture<uchar4, 1, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex1D(texture<short, 1, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex1D(texture<unsigned short, 1, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex1D(texture<short1, 1, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex1D(texture<ushort1, 1, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex1D(texture<short2, 1, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex1D(texture<ushort2, 1, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v  = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex1D(texture<short4, 1, cudaReadModeNormalizedFloat> t, float x)
{
  int4 v   = __itexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex1D(texture<ushort4, 1, cudaReadModeNormalizedFloat> t, float x)
{
  uint4 v   = __utexfetch(t, make_float4(x, 0, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
* 2D Texture functions                                                         *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex2D(texture<char, 2, cudaReadModeElementType> t, float x, float y)
{
#if __SIGNED_CHARS__
  int4 v  = __itexfetch(t, make_float4(x, y, 0, 0));
#else
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));
#endif

  return (char)v.x;
}

static __inline__ __device__ signed char tex2D(texture<signed char, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex2D(texture<unsigned char, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex2D(texture<char1, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex2D(texture<uchar1, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex2D(texture<char2, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex2D(texture<uchar2, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex2D(texture<char4, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex2D(texture<uchar4, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex2D(texture<short, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex2D(texture<unsigned short, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex2D(texture<short1, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex2D(texture<ushort1, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex2D(texture<short2, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex2D(texture<ushort2, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex2D(texture<short4, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex2D(texture<ushort4, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex2D(texture<int, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex2D(texture<unsigned int, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex2D(texture<int1, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex2D(texture<uint1, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex2D(texture<int2, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex2D(texture<uint2, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex2D(texture<int4, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex2D(texture<uint4, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex2D(texture<long, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex2D(texture<unsigned long, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex2D(texture<long1, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex2D(texture<ulong1, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex2D(texture<long2, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex2D(texture<ulong2, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex2D(texture<long4, 2, cudaReadModeElementType> t, float x, float y)
{
  int4 v = __itexfetch(t, make_float4(x, y, 0, 0));

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex2D(texture<ulong4, 2, cudaReadModeElementType> t, float x, float y)
{
  uint4 v = __utexfetch(t, make_float4(x, y, 0, 0));

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex2D(texture<float, 2, cudaReadModeElementType> t, float x, float y)
{
  float4 v = __ftexfetch(t, make_float4(x, y, 0, 0));

  return v.x;
}

static __inline__ __device__ float1 tex2D(texture<float1, 2, cudaReadModeElementType> t, float x, float y)
{
  float4 v = __ftexfetch(t, make_float4(x, y, 0, 0));

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex2D(texture<float2, 2, cudaReadModeElementType> t, float x, float y)
{
  float4 v = __ftexfetch(t, make_float4(x, y, 0, 0));

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex2D(texture<float4, 2, cudaReadModeElementType> t, float x, float y)
{
  float4 v = __ftexfetch(t, make_float4(x, y, 0, 0));

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex2D(texture<char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
#if __SIGNED_CHARS__
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
#else
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
#endif
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex2D(texture<signed char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex2D(texture<unsigned char, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex2D(texture<char1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex2D(texture<uchar1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex2D(texture<char2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex2D(texture<uchar2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex2D(texture<char4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex2D(texture<uchar4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex2D(texture<short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex2D(texture<unsigned short, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex2D(texture<short1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex2D(texture<ushort1, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex2D(texture<short2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex2D(texture<ushort2, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex2D(texture<short4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  int4 v   = __itexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex2D(texture<ushort4, 2, cudaReadModeNormalizedFloat> t, float x, float y)
{
  uint4 v   = __utexfetch(t, make_float4(x, y, 0, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
* 3D Texture functions                                                         *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ char tex3D(texture<char, 3, cudaReadModeElementType> t, float x, float y, float z)
{
#if __SIGNED_CHARS__
  int4 v  = __itexfetch(t, make_float4(x, y, z, 0));
#else
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));
#endif

  return (char)v.x;
}

static __inline__ __device__ signed char tex3D(texture<signed char, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return (signed char)v.x;
}

static __inline__ __device__ unsigned char tex3D(texture<unsigned char, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return (unsigned char)v.x;
}

static __inline__ __device__ char1 tex3D(texture<char1, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_char1(v.x);
}

static __inline__ __device__ uchar1 tex3D(texture<uchar1, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uchar1(v.x);
}

static __inline__ __device__ char2 tex3D(texture<char2, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_char2(v.x, v.y);
}

static __inline__ __device__ uchar2 tex3D(texture<uchar2, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uchar2(v.x, v.y);
}

static __inline__ __device__ char4 tex3D(texture<char4, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_char4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uchar4 tex3D(texture<uchar4, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uchar4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ short tex3D(texture<short, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return (short)v.x;
}

static __inline__ __device__ unsigned short tex3D(texture<unsigned short, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return (unsigned short)v.x;
}

static __inline__ __device__ short1 tex3D(texture<short1, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_short1(v.x);
}

static __inline__ __device__ ushort1 tex3D(texture<ushort1, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ushort1(v.x);
}

static __inline__ __device__ short2 tex3D(texture<short2, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_short2(v.x, v.y);
}

static __inline__ __device__ ushort2 tex3D(texture<ushort2, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ushort2(v.x, v.y);
}

static __inline__ __device__ short4 tex3D(texture<short4, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_short4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ushort4 tex3D(texture<ushort4, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ushort4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int tex3D(texture<int, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return (int)v.x;
}

static __inline__ __device__ unsigned int tex3D(texture<unsigned int, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return (unsigned int)v.x;
}

static __inline__ __device__ int1 tex3D(texture<int1, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_int1(v.x);
}

static __inline__ __device__ uint1 tex3D(texture<uint1, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uint1(v.x);
}

static __inline__ __device__ int2 tex3D(texture<int2, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_int2(v.x, v.y);
}

static __inline__ __device__ uint2 tex3D(texture<uint2, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uint2(v.x, v.y);
}

static __inline__ __device__ int4 tex3D(texture<int4, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_int4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ uint4 tex3D(texture<uint4, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_uint4(v.x, v.y, v.z, v.w);
}

#if !defined(__LP64__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ long tex3D(texture<long, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return (long)v.x;
}

static __inline__ __device__ unsigned long tex3D(texture<unsigned long, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return (unsigned long)v.x;
}

static __inline__ __device__ long1 tex3D(texture<long1, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_long1(v.x);
}

static __inline__ __device__ ulong1 tex3D(texture<ulong1, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ulong1(v.x);
}

static __inline__ __device__ long2 tex3D(texture<long2, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_long2(v.x, v.y);
}

static __inline__ __device__ ulong2 tex3D(texture<ulong2, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ulong2(v.x, v.y);
}

static __inline__ __device__ long4 tex3D(texture<long4, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  int4 v = __itexfetch(t, make_float4(x, y, z, 0));

  return make_long4(v.x, v.y, v.z, v.w);
}

static __inline__ __device__ ulong4 tex3D(texture<ulong4, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  uint4 v = __utexfetch(t, make_float4(x, y, z, 0));

  return make_ulong4(v.x, v.y, v.z, v.w);
}

#endif /* !__LP64__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex3D(texture<float, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetch(t, make_float4(x, y, z, 0));

  return v.x;
}

static __inline__ __device__ float1 tex3D(texture<float1, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetch(t, make_float4(x, y, z, 0));

  return make_float1(v.x);
}

static __inline__ __device__ float2 tex3D(texture<float2, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetch(t, make_float4(x, y, z, 0));

  return make_float2(v.x, v.y);
}

static __inline__ __device__ float4 tex3D(texture<float4, 3, cudaReadModeElementType> t, float x, float y, float z)
{
  float4 v = __ftexfetch(t, make_float4(x, y, z, 0));

  return make_float4(v.x, v.y, v.z, v.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex3D(texture<char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
#if __SIGNED_CHARS__
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
#else
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
#endif
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex3D(texture<signed char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex3D(texture<unsigned char, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex3D(texture<char1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex3D(texture<uchar1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex3D(texture<char2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex3D(texture<uchar2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex3D(texture<char4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex3D(texture<uchar4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ float tex3D(texture<short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float tex3D(texture<unsigned short, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return w.x;
}

static __inline__ __device__ float1 tex3D(texture<short1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float1 tex3D(texture<ushort1, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float1(w.x);
}

static __inline__ __device__ float2 tex3D(texture<short2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float2 tex3D(texture<ushort2, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v  = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float2(w.x, w.y);
}

static __inline__ __device__ float4 tex3D(texture<short4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  int4 v   = __itexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

static __inline__ __device__ float4 tex3D(texture<ushort4, 3, cudaReadModeNormalizedFloat> t, float x, float y, float z)
{
  uint4 v   = __utexfetch(t, make_float4(x, y, z, 0));
  float4 w = make_float4(__int_as_float(v.x), __int_as_float(v.y), __int_as_float(v.z), __int_as_float(v.w));

  return make_float4(w.x, w.y, w.z, w.w);
}

#define __utexfetchi \
        000 incorect invocation of builtin __utexfetchi 000
#define __itexfetchi \
        000 incorect invocation of builtin __itexfetchi 000
#define __ftexfetchi \
        000 incorect invocation of builtin __ftexfetchi 000
#define __utexfetch \
        000 incorect invocation of builtin __utexfetch 000
#define __itexfetch \
        000 incorect invocation of builtin __itexfetch 000
#define __ftexfetch \
        000 incorect invocation of builtin __ftexfetch 000

#elif defined(__CUDABE__)

extern  uint4 __utexfetchi1D(const void*, int4);
extern   int4 __itexfetchi1D(const void*, int4);
extern float4 __ftexfetchi1D(const void*, int4);
extern  uint4 __utexfetch1D(const void*, float4);
extern   int4 __itexfetch1D(const void*, float4);
extern float4 __ftexfetch1D(const void*, float4);
extern  uint4 __utexfetch2D(const void*, float4);
extern   int4 __itexfetch2D(const void*, float4);
extern float4 __ftexfetch2D(const void*, float4);
extern  uint4 __utexfetch3D(const void*, float4);
extern   int4 __itexfetch3D(const void*, float4);
extern float4 __ftexfetch3D(const void*, float4);

#define __utexfetchi(t, i) \
        __utexfetchi1D(t, i)
#define __itexfetchi(t, i) \
        __itexfetchi1D(t, i)
#define __ftexfetchi(t, i) \
        __ftexfetchi1D(t, i)
#define __utexfetch(t, i, d) \
        __utexfetch##d##D(t, i)
#define __itexfetch(t, i, d) \
        __itexfetch##d##D(t, i)
#define __ftexfetch(t, i, d) \
        __ftexfetch##d##D(t, i)

#endif /* __cplusplus && __CUDACC__ */

#if defined(__cplusplus) && defined(__CUDACC__)

#if !defined(__CUDA_ARCH__) || __CUDA_ARCH__ >= 200

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/*DEVICE_BUILTIN*/
template<int comp, class T> extern __device__   int4 __itex2Dgather(texture<T, 2, cudaReadModeElementType> t, float2 i, int c = comp);
/*DEVICE_BUILTIN*/
template<int comp, class T> extern __device__  uint4 __utex2Dgather(texture<T, 2, cudaReadModeElementType> t, float2 i, int c = comp);
/*DEVICE_BUILTIN*/
template<int comp, class T> extern __device__ float4 __ftex2Dgather(texture<T, 2, cudaReadModeElementType> t, float2 i, int c = comp);

#define __tex2DgatherUtil(T, f, r, c) \
        { T v = f<c>(t, make_float2(x, y)); return r; }

#define __tex2DgatherUtil1(T, f, r) \
        __tex2DgatherUtil(T, f, r, 0)

#define __tex2DgatherUtil2(T, f, r)                  \
        if (comp == 1) __tex2DgatherUtil(T, f, r, 1) \
        else __tex2DgatherUtil1(T, f, r)

#define __tex2DgatherUtil3(T, f, r)                  \
        if (comp == 2) __tex2DgatherUtil(T, f, r, 2) \
        else __tex2DgatherUtil2(T, f, r)

#define __tex2DgatherUtil4(T, f, r)                  \
        if (comp == 3) __tex2DgatherUtil(T, f, r, 3) \
        else __tex2DgatherUtil3(T, f, r)

static __inline__ __device__ char4 tex2Dgather(texture<char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<signed char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<unsigned char, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<char1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<uchar1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<char2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<uchar2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<char3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<uchar3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ char4 tex2Dgather(texture<char4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(int4, __itex2Dgather, make_char4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ uchar4 tex2Dgather(texture<uchar4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(uint4, __utex2Dgather, make_uchar4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<signed short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<unsigned short, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<short1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<ushort1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<short2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<ushort2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<short3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<ushort3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ short4 tex2Dgather(texture<short4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(int4, __itex2Dgather, make_short4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ ushort4 tex2Dgather(texture<ushort4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(uint4, __utex2Dgather, make_ushort4(v.x, v.y, v.z, v.w));
}

static __inline__ __device__ int4 tex2Dgather(texture<signed int, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<unsigned int, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, v);
}

static __inline__ __device__ int4 tex2Dgather(texture<int1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<uint1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(uint4, __utex2Dgather, v);
}

static __inline__ __device__ int4 tex2Dgather(texture<int2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<uint2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(uint4, __utex2Dgather, v);
}

static __inline__ __device__ int4 tex2Dgather(texture<int3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<uint3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(uint4, __utex2Dgather, v);
}

static __inline__ __device__ int4 tex2Dgather(texture<int4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(int4, __itex2Dgather, v);
}

static __inline__ __device__ uint4 tex2Dgather(texture<uint4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(uint4, __utex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(float4, __ftex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float1, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil1(float4, __ftex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float2, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil2(float4, __ftex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float3, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil3(float4, __ftex2Dgather, v);
}

static __inline__ __device__ float4 tex2Dgather(texture<float4, 2, cudaReadModeElementType> t, float x, float y, int comp = 0)
{
  __tex2DgatherUtil4(float4, __ftex2Dgather, v);
}

#undef __tex2DgatherUtil
#undef __tex2DgatherUtil1
#undef __tex2DgatherUtil2
#undef __tex2DgatherUtil3
#undef __tex2DgatherUtil4

#define __utex2Dgather \
        000 incorect invocation of builtin __utex2Dgather 000
#define __itex2Dgather \
        000 incorect invocation of builtin __itex2Dgather 000
#define __ftex2Dgather \
        000 incorect invocation of builtin __ftex2Dgather 000

#endif /* !__CUDA_ARCH__ || __CUDA_ARCH__ >= 200 */

#elif defined(__CUDABE__)

extern  uint4 __utex2Dgather0(const void*, float2);
extern  uint4 __utex2Dgather1(const void*, float2);
extern  uint4 __utex2Dgather2(const void*, float2);
extern  uint4 __utex2Dgather3(const void*, float2);
extern   int4 __itex2Dgather0(const void*, float2);
extern   int4 __itex2Dgather1(const void*, float2);
extern   int4 __itex2Dgather2(const void*, float2);
extern   int4 __itex2Dgather3(const void*, float2);
extern float4 __ftex2Dgather0(const void*, float2);
extern float4 __ftex2Dgather1(const void*, float2);
extern float4 __ftex2Dgather2(const void*, float2);
extern float4 __ftex2Dgather3(const void*, float2);

#define __utex2Dgather(t, i, c) \
        __utex2Dgather##c(t, i)
#define __itex2Dgather(t, i, c) \
        __itex2Dgather##c(t, i)
#define __ftex2Dgather(t, i, c) \
        __ftex2Dgather##c(t, i)

#endif /* __cplusplus && __CUDACC__ */

#endif /* !__TEXTURE_FETCH_FUNCTIONS_H__ */

