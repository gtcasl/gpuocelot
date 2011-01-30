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

#if !defined(__SURFACE_FUNCTIONS_H__)
#define __SURFACE_FUNCTIONS_H__

#if defined(__cplusplus) && defined(__CUDACC__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "builtin_types.h"
#include "cuda_surface_types.h"
#include "host_defines.h"
#include "surface_types.h"
#include "vector_functions.h"
#include "vector_types.h"

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/*DEVICE_BUILTIN*/
extern __device__ uchar1     __surf1Dreadc1(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uchar2     __surf1Dreadc2(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uchar4     __surf1Dreadc4(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ushort1    __surf1Dreads1(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ushort2    __surf1Dreads2(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ushort4    __surf1Dreads4(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uint1      __surf1Dreadu1(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uint2      __surf1Dreadu2(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uint4      __surf1Dreadu4(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ulonglong1 __surf1Dreadl1(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ulonglong2 __surf1Dreadl2(surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);

#if __CUDA_ARCH__ >= 200

#define __surfModeSwitch(surf, x, mode, type)                                                   \
        ((mode == cudaBoundaryModeZero)  ? __surf1Dread##type(surf, x, cudaBoundaryModeZero ) : \
         (mode == cudaBoundaryModeClamp) ? __surf1Dread##type(surf, x, cudaBoundaryModeClamp) : \
                                           __surf1Dread##type(surf, x, cudaBoundaryModeTrap ))

#else /* __CUDA_ARCH__ >= 200 */

#define __surfModeSwitch(surf, x, mode, type) \
         __surf1Dread##type(surf, x, cudaBoundaryModeTrap)

#endif /* __CUDA_ARCH__ >= 200 */

template<class T>
static __inline__ __device__ void surf1Dread(T *res, surface<void, 1> surf, int x, int s, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  (s ==  1) ? (void)(*(uchar1 *)res = __surfModeSwitch(surf, x, mode, c1)) :
  (s ==  2) ? (void)(*(ushort1*)res = __surfModeSwitch(surf, x, mode, s1)) :
  (s ==  4) ? (void)(*(uint1  *)res = __surfModeSwitch(surf, x, mode, u1)) :
  (s ==  8) ? (void)(*(uint2  *)res = __surfModeSwitch(surf, x, mode, u2)) :
  (s == 16) ? (void)(*(uint4  *)res = __surfModeSwitch(surf, x, mode, u4)) :
              (void)0;
}

template<class T>
static __inline__ __device__ T surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  T tmp;
  
  surf1Dread(&tmp, surf, x, (int)sizeof(T), mode);
  
  return tmp;
}

template<class T>
static __inline__ __device__ void surf1Dread(T *res, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  *res = surf1Dread<T>(surf, x, mode);
}

template<>
__inline__ __device__ char surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return (char)__surfModeSwitch(surf, x, mode, c1).x;
}

template<>
__inline__ __device__ signed char surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return (signed char)__surfModeSwitch(surf, x, mode, c1).x;
}

template<>
__inline__ __device__ unsigned char surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, c1).x;
}

template<>
__inline__ __device__ char1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return make_char1((signed char)__surfModeSwitch(surf, x, mode, c1).x);
}

template<>
__inline__ __device__ uchar1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, c1);
}

template<>
__inline__ __device__ char2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uchar2 tmp = __surfModeSwitch(surf, x, mode, c2);
  
  return make_char2((signed char)tmp.x, (signed char)tmp.y);
}

template<>
__inline__ __device__ uchar2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, c2);
}

template<>
__inline__ __device__ char4 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uchar4 tmp = __surfModeSwitch(surf, x, mode, c4);
  
  return make_char4((signed char)tmp.x, (signed char)tmp.y, (signed char)tmp.z, (signed char)tmp.w);
}

template<>
__inline__ __device__ uchar4 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, c4);
}

template<>
__inline__ __device__ short surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return (short)__surfModeSwitch(surf, x, mode, s1).x;
}

template<>
__inline__ __device__ unsigned short surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, s1).x;
}

template<>
__inline__ __device__ short1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return make_short1((signed short)__surfModeSwitch(surf, x, mode, s1).x);
}

template<>
__inline__ __device__ ushort1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, s1);
}

template<>
__inline__ __device__ short2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  ushort2 tmp = __surfModeSwitch(surf, x, mode, s2);
  
  return make_short2((signed short)tmp.x, (signed short)tmp.y);
}

template<>
__inline__ __device__ ushort2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, s2);
}

template<>
__inline__ __device__ short4 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  ushort4 tmp = __surfModeSwitch(surf, x, mode, s4);
  
  return make_short4((signed short)tmp.x, (signed short)tmp.y, (signed short)tmp.z, (signed short)tmp.w);
}

template<>
__inline__ __device__ ushort4 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, s4);
}

template<>
__inline__ __device__ int surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return (int)__surfModeSwitch(surf, x, mode, u1).x;
}

template<>
__inline__ __device__ unsigned int surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, u1).x;
}

template<>
__inline__ __device__ int1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return make_int1((signed int)__surfModeSwitch(surf, x, mode, u1).x);
}

template<>
__inline__ __device__ uint1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, u1);
}

template<>
__inline__ __device__ int2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uint2 tmp = __surfModeSwitch(surf, x, mode, u2);
  
  return make_int2((int)tmp.x, (int)tmp.y);
}

template<>
__inline__ __device__ uint2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, u2);
}

template<>
__inline__ __device__ int4 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uint4 tmp = __surfModeSwitch(surf, x, mode, u4);
  
  return make_int4((int)tmp.x, (int)tmp.y, (int)tmp.z, (int)tmp.w);
}

template<>
__inline__ __device__ uint4 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, u4);
}

template<>
__inline__ __device__ long long int surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return (long long int)__surfModeSwitch(surf, x, mode, l1).x;
}

template<>
__inline__ __device__ unsigned long long int surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, l1).x;
}

template<>
__inline__ __device__ longlong1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return make_longlong1((long long int)__surfModeSwitch(surf, x, mode, l1).x);
}

template<>
__inline__ __device__ ulonglong1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, l1);
}

template<>
__inline__ __device__ longlong2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  ulonglong2 tmp = __surfModeSwitch(surf, x, mode, l2);
  
  return make_longlong2((long long int)tmp.x, (long long int)tmp.y);
}

template<>
__inline__ __device__ ulonglong2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, mode, l2);
}

#if !defined(__LP64__)

template<>
__inline__ __device__ long int surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return (long int)__surfModeSwitch(surf, x, mode, u1).x;
}

template<>
__inline__ __device__ unsigned long int surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return (unsigned long int)__surfModeSwitch(surf, x, mode, u1).x;
}

template<>
__inline__ __device__ long1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return make_long1((long int)__surfModeSwitch(surf, x, mode, u1).x);
}

template<>
__inline__ __device__ ulong1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return make_ulong1((unsigned long int)__surfModeSwitch(surf, x, mode, u1).x);
}

template<>
__inline__ __device__ long2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uint2 tmp = __surfModeSwitch(surf, x, mode, u2);
  
  return make_long2((long int)tmp.x, (long int)tmp.y);
}

template<>
__inline__ __device__ ulong2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uint2 tmp = __surfModeSwitch(surf, x, mode, u2);
  
  return make_ulong2((unsigned long int)tmp.x, (unsigned long int)tmp.y);
}

template<>
__inline__ __device__ long4 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uint4 tmp = __surfModeSwitch(surf, x, mode, u4);
  
  return make_long4((long int)tmp.x, (long int)tmp.y, (long int)tmp.z, (long int)tmp.w);
}

template<>
__inline__ __device__ ulong4 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uint4 tmp = __surfModeSwitch(surf, x, mode, u4);
  
  return make_ulong4((unsigned long int)tmp.x, (unsigned long int)tmp.y, (unsigned long int)tmp.z, (unsigned long int)tmp.w);
}

#endif /* !__LP64__ */

template<>
__inline__ __device__ float surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return __int_as_float((int)__surfModeSwitch(surf, x, mode, u1).x);
}

template<>
__inline__ __device__ float1 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  return make_float1(__int_as_float((int)__surfModeSwitch(surf, x, mode, u1).x));
}

template<>
__inline__ __device__ float2 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uint2 tmp = __surfModeSwitch(surf, x, mode, u2);
  
  return make_float2(__int_as_float((int)tmp.x), __int_as_float((int)tmp.y));
}

template<>
__inline__ __device__ float4 surf1Dread(surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode)
{
  uint4 tmp = __surfModeSwitch(surf, x, mode, u4);
  
  return make_float4(__int_as_float((int)tmp.x), __int_as_float((int)tmp.y), __int_as_float((int)tmp.z), __int_as_float((int)tmp.w));
}

#undef __surfModeSwitch

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/*DEVICE_BUILTIN*/
extern __device__ uchar1     __surf2Dreadc1(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uchar2     __surf2Dreadc2(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uchar4     __surf2Dreadc4(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ushort1    __surf2Dreads1(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ushort2    __surf2Dreads2(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ushort4    __surf2Dreads4(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uint1      __surf2Dreadu1(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uint2      __surf2Dreadu2(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ uint4      __surf2Dreadu4(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ulonglong1 __surf2Dreadl1(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ ulonglong2 __surf2Dreadl2(surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);

#if __CUDA_ARCH__ >= 200

#define __surfModeSwitch(surf, x, y, mode, type)                                                   \
        ((mode == cudaBoundaryModeZero)  ? __surf2Dread##type(surf, x, y, cudaBoundaryModeZero ) : \
         (mode == cudaBoundaryModeClamp) ? __surf2Dread##type(surf, x, y, cudaBoundaryModeClamp) : \
                                           __surf2Dread##type(surf, x, y, cudaBoundaryModeTrap ))

#else /* __CUDA_ARCH__ >= 200 */

#define __surfModeSwitch(surf, x, y, mode, type) \
        __surf2Dread##type(surf, x, y, cudaBoundaryModeTrap)

#endif /* __CUDA_ARCH__ >= 200 */

template<class T>
static __inline__ __device__ void surf2Dread(T *res, surface<void, 2> surf, int x, int y, int s, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  (s ==  1) ? (void)(*(uchar1 *)res = __surfModeSwitch(surf, x, y, mode, c1)) :
  (s ==  2) ? (void)(*(ushort1*)res = __surfModeSwitch(surf, x, y, mode, s1)) :
  (s ==  4) ? (void)(*(uint1  *)res = __surfModeSwitch(surf, x, y, mode, u1)) :
  (s ==  8) ? (void)(*(uint2  *)res = __surfModeSwitch(surf, x, y, mode, u2)) :
  (s == 16) ? (void)(*(uint4  *)res = __surfModeSwitch(surf, x, y, mode, u4)) :
              (void)0;
}

template<class T>
static __inline__ __device__ T surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  T tmp;
  
  surf2Dread(&tmp, surf, x, y, (int)sizeof(T), mode);
  
  return tmp;
}

template<class T>
static __inline__ __device__ void surf2Dread(T *res, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  *res = surf2Dread<T>(surf, x, y, mode);
}

template<>
__inline__ __device__ char surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return (char)__surfModeSwitch(surf, x, y, mode, c1).x;
}

template<>
__inline__ __device__ signed char surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return (signed char)__surfModeSwitch(surf, x, y, mode, c1).x;
}

template<>
__inline__ __device__ unsigned char surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, c1).x;
}

template<>
__inline__ __device__ char1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return make_char1((signed char)__surfModeSwitch(surf, x, y, mode, c1).x);
}

template<>
__inline__ __device__ uchar1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, c1);
}

template<>
__inline__ __device__ char2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uchar2 tmp = __surfModeSwitch(surf, x, y, mode, c2);
  
  return make_char2((signed char)tmp.x, (signed char)tmp.y);
}

template<>
__inline__ __device__ uchar2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, c2);
}

template<>
__inline__ __device__ char4 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uchar4 tmp = __surfModeSwitch(surf, x, y, mode, c4);
  
  return make_char4((signed char)tmp.x, (signed char)tmp.y, (signed char)tmp.z, (signed char)tmp.w);
}

template<>
__inline__ __device__ uchar4 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, c4);
}

template<>
__inline__ __device__ short surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return (short)__surfModeSwitch(surf, x, y, mode, s1).x;
}

template<>
__inline__ __device__ unsigned short surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, s1).x;
}

template<>
__inline__ __device__ short1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return make_short1((signed short)__surfModeSwitch(surf, x, y, mode, s1).x);
}

template<>
__inline__ __device__ ushort1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, s1);
}

template<>
__inline__ __device__ short2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  ushort2 tmp = __surfModeSwitch(surf, x, y, mode, s2);
  
  return make_short2((signed short)tmp.x, (signed short)tmp.y);
}

template<>
__inline__ __device__ ushort2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, s2);
}

template<>
__inline__ __device__ short4 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  ushort4 tmp = __surfModeSwitch(surf, x, y, mode, s4);
  
  return make_short4((signed short)tmp.x, (signed short)tmp.y, (signed short)tmp.z, (signed short)tmp.w);
}

template<>
__inline__ __device__ ushort4 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, s4);
}

template<>
__inline__ __device__ int surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return (int)__surfModeSwitch(surf, x, y, mode, u1).x;
}

template<>
__inline__ __device__ unsigned int surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, u1).x;
}

template<>
__inline__ __device__ int1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return make_int1((signed int)__surfModeSwitch(surf, x, y, mode, u1).x);
}

template<>
__inline__ __device__ uint1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, u1);
}

template<>
__inline__ __device__ int2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uint2 tmp = __surfModeSwitch(surf, x, y, mode, u2);
  
  return make_int2((int)tmp.x, (int)tmp.y);
}

template<>
__inline__ __device__ uint2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, u2);
}

template<>
__inline__ __device__ int4 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uint4 tmp = __surfModeSwitch(surf, x, y, mode, u4);
  
  return make_int4((int)tmp.x, (int)tmp.y, (int)tmp.z, (int)tmp.w);
}

template<>
__inline__ __device__ uint4 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, u4);
}

template<>
__inline__ __device__ long long int surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return (long long int)__surfModeSwitch(surf, x, y, mode, l1).x;
}

template<>
__inline__ __device__ unsigned long long int surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, l1).x;
}

template<>
__inline__ __device__ longlong1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return make_longlong1((long long int)__surfModeSwitch(surf, x, y, mode, l1).x);
}

template<>
__inline__ __device__ ulonglong1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, l1);
}

template<>
__inline__ __device__ longlong2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  ulonglong2 tmp = __surfModeSwitch(surf, x, y, mode, l2);
  
  return make_longlong2((long long int)tmp.x, (long long int)tmp.y);
}

template<>
__inline__ __device__ ulonglong2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __surfModeSwitch(surf, x, y, mode, l2);
}

#if !defined(__LP64__)

template<>
__inline__ __device__ long int surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return (long int)__surfModeSwitch(surf, x, y, mode, u1).x;
}

template<>
__inline__ __device__ unsigned long int surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return (unsigned long int)__surfModeSwitch(surf, x, y, mode, u1).x;
}

template<>
__inline__ __device__ long1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return make_long1((long int)__surfModeSwitch(surf, x, y, mode, u1).x);
}

template<>
__inline__ __device__ ulong1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return make_ulong1((unsigned long int)__surfModeSwitch(surf, x, y, mode, u1).x);
}

template<>
__inline__ __device__ long2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uint2 tmp = __surfModeSwitch(surf, x, y, mode, u2);
  
  return make_long2((long int)tmp.x, (long int)tmp.y);
}

template<>
__inline__ __device__ ulong2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uint2 tmp = __surfModeSwitch(surf, x, y, mode, u2);
  
  return make_ulong2((unsigned long int)tmp.x, (unsigned long int)tmp.y);
}

template<>
__inline__ __device__ long4 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uint4 tmp = __surfModeSwitch(surf, x, y, mode, u4);
  
  return make_long4((long int)tmp.x, (long int)tmp.y, (long int)tmp.z, (long int)tmp.w);
}

template<>
__inline__ __device__ ulong4 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uint4 tmp = __surfModeSwitch(surf, x, y, mode, u4);
  
  return make_ulong4((unsigned long int)tmp.x, (unsigned long int)tmp.y, (unsigned long int)tmp.z, (unsigned long int)tmp.w);
}

#endif /* !__LP64__ */

template<>
__inline__ __device__ float surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return __int_as_float((int)__surfModeSwitch(surf, x, y, mode, u1).x);
}

template<>
__inline__ __device__ float1 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  return make_float1(__int_as_float((int)__surfModeSwitch(surf, x, y, mode, u1).x));
}

template<>
__inline__ __device__ float2 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uint2 tmp = __surfModeSwitch(surf, x, y, mode, u2);
  
  return make_float2(__int_as_float((int)tmp.x), __int_as_float((int)tmp.y));
}

template<>
__inline__ __device__ float4 surf2Dread(surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode)
{
  uint4 tmp = __surfModeSwitch(surf, x, y, mode, u4);
  
  return make_float4(__int_as_float((int)tmp.x), __int_as_float((int)tmp.y), __int_as_float((int)tmp.z), __int_as_float((int)tmp.w));
}

#undef __surfModeSwitch

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwritec1(    uchar1 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwritec2(    uchar2 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwritec4(    uchar4 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwrites1(   ushort1 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwrites2(   ushort2 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwrites4(   ushort4 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwriteu1(     uint1 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwriteu2(     uint2 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwriteu4(     uint4 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwritel1(ulonglong1 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf1Dwritel2(ulonglong2 val, surface<void, 1> t, int x, enum cudaSurfaceBoundaryMode mode);

#if __CUDA_ARCH__ >= 200

#define __surfModeSwitch(val, surf, x, mode, type)                                                    \
        ((mode == cudaBoundaryModeZero)  ? __surf1Dwrite##type(val, surf, x, cudaBoundaryModeZero ) : \
         (mode == cudaBoundaryModeClamp) ? __surf1Dwrite##type(val, surf, x, cudaBoundaryModeClamp) : \
                                           __surf1Dwrite##type(val, surf, x, cudaBoundaryModeTrap ))

#else /* __CUDA_ARCH__ >= 200 */

#define __surfModeSwitch(val, surf, x, mode, type) \
        __surf1Dwrite##type(val, surf, x, cudaBoundaryModeTrap)

#endif /* __CUDA_ARCH__ >= 200 */

template<class T>
static __inline__ __device__ void surf1Dwrite(T val, surface<void, 1> surf, int x, int s, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  union {
    T       val;
    uchar1  c1;
    ushort1 s1;
    uint1   u1;
    uint2   u2;
    uint4   u4;
  } tmp;
  
  tmp.val = val;
  
  (s ==  1) ? (void)(__surfModeSwitch(tmp.c1, surf, x, mode, c1)) :
  (s ==  2) ? (void)(__surfModeSwitch(tmp.s1, surf, x, mode, s1)) :
  (s ==  4) ? (void)(__surfModeSwitch(tmp.u1, surf, x, mode, u1)) :
  (s ==  8) ? (void)(__surfModeSwitch(tmp.u2, surf, x, mode, u2)) :
  (s == 16) ? (void)(__surfModeSwitch(tmp.u4, surf, x, mode, u4)) :
              (void)0;
}

template<class T>
static __inline__ __device__ void surf1Dwrite(T val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{;
  surf1Dwrite(val, surf, x, (int)sizeof(T), mode);
}


static __inline__ __device__ void surf1Dwrite(char val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar1((unsigned char)val), surf, x, mode, c1);
}

static __inline__ __device__ void surf1Dwrite(signed char val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar1((unsigned char)val), surf, x, mode, c1);
}

static __inline__ __device__ void surf1Dwrite(unsigned char val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar1(val), surf, x, mode, c1);
}

static __inline__ __device__ void surf1Dwrite(char1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar1((unsigned char)val.x), surf, x, mode, c1);
}

static __inline__ __device__ void surf1Dwrite(uchar1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, c1);
}

static __inline__ __device__ void surf1Dwrite(char2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar2((unsigned char)val.x, (unsigned char)val.y), surf, x, mode, c2);
}

static __inline__ __device__ void surf1Dwrite(uchar2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, c2);
}

static __inline__ __device__ void surf1Dwrite(char4 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar4((unsigned char)val.x, (unsigned char)val.y, (unsigned char)val.z, (unsigned char)val.w), surf, x, mode, c4);
}

static __inline__ __device__ void surf1Dwrite(uchar4 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, c4);
}

static __inline__ __device__ void surf1Dwrite(short val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort1((unsigned short)val), surf, x, mode, s1);
}

static __inline__ __device__ void surf1Dwrite(unsigned short val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort1(val), surf, x, mode, s1);
}

static __inline__ __device__ void surf1Dwrite(short1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort1((unsigned short)val.x), surf, x, mode, s1);
}

static __inline__ __device__ void surf1Dwrite(ushort1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, s1);
}

static __inline__ __device__ void surf1Dwrite(short2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort2((unsigned short)val.x, (unsigned short)val.y), surf, x, mode, s2);
}

static __inline__ __device__ void surf1Dwrite(ushort2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, s2);
}

static __inline__ __device__ void surf1Dwrite(short4 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort4((unsigned short)val.x, (unsigned short)val.y, (unsigned short)val.z, (unsigned short)val.w), surf, x, mode, s4);
}

static __inline__ __device__ void surf1Dwrite(ushort4 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, s4);
}

static __inline__ __device__ void surf1Dwrite(int val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val), surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(unsigned int val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1(val), surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(int1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val.x), surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(uint1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(int2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint2((unsigned int)val.x, (unsigned int)val.y), surf, x, mode, u2);
}

static __inline__ __device__ void surf1Dwrite(uint2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, u2);
}

static __inline__ __device__ void surf1Dwrite(int4 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint4((unsigned int)val.x, (unsigned int)val.y, (unsigned int)val.z, (unsigned int)val.w), surf, x, mode, u4);
}

static __inline__ __device__ void surf1Dwrite(uint4 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, u4);
}

static __inline__ __device__ void surf1Dwrite(long long int val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ulonglong1((unsigned long long int)val), surf, x, mode, l1);
}

static __inline__ __device__ void surf1Dwrite(unsigned long long int val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ulonglong1(val), surf, x, mode, l1);
}

static __inline__ __device__ void surf1Dwrite(longlong1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ulonglong1((unsigned long long int)val.x), surf, x, mode, l1);
}

static __inline__ __device__ void surf1Dwrite(ulonglong1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, l1);
}

static __inline__ __device__ void surf1Dwrite(longlong2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ulonglong2((unsigned long long int)val.x, (unsigned long long int)val.y), surf, x, mode, l2);
}

static __inline__ __device__ void surf1Dwrite(ulonglong2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, mode, l2);
}

#if !defined(__LP64__)

static __inline__ __device__ void surf1Dwrite(long int val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val), surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(unsigned long int val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val), surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(long1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val.x), surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(ulong1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val.x), surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(long2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint2((unsigned int)val.x, (unsigned int)val.y), surf, x, mode, u2);
}

static __inline__ __device__ void surf1Dwrite(ulong2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint2((unsigned int)val.x, (unsigned int)val.y), surf, x, mode, u2);
}

static __inline__ __device__ void surf1Dwrite(long4 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint4((unsigned int)val.x, (unsigned int)val.y, (unsigned int)val.z, (unsigned int)val.w), surf, x, mode, u4);
}

static __inline__ __device__ void surf1Dwrite(ulong4 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint4((unsigned int)val.x, (unsigned int)val.y, (unsigned int)val.z, (unsigned int)val.w), surf, x, mode, u4);
}

#endif /* !__LP64__ */

static __inline__ __device__ void surf1Dwrite(float val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)__float_as_int(val)), surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(float1 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)__float_as_int(val.x)), surf, x, mode, u1);
}

static __inline__ __device__ void surf1Dwrite(float2 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint2((unsigned int)__float_as_int(val.x), __float_as_int((unsigned int)val.y)), surf, x, mode, u2);
}

static __inline__ __device__ void surf1Dwrite(float4 val, surface<void, 1> surf, int x, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint4((unsigned int)__float_as_int(val.x), (unsigned int)__float_as_int(val.y), (unsigned int)__float_as_int(val.z), (unsigned int)__float_as_int(val.w)), surf, x, mode, u4);
}

#undef __surfModeSwitch

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwritec1(    uchar1 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwritec2(    uchar2 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwritec4(    uchar4 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwrites1(   ushort1 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwrites2(   ushort2 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwrites4(   ushort4 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwriteu1(     uint1 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwriteu2(     uint2 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwriteu4(     uint4 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwritel1(ulonglong1 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);
/*DEVICE_BUILTIN*/
extern __device__ void __surf2Dwritel2(ulonglong2 val, surface<void, 2> t, int x, int y, enum cudaSurfaceBoundaryMode mode);

#if __CUDA_ARCH__ >= 200

#define __surfModeSwitch(val, surf, x, y, mode, type)                                                    \
        ((mode == cudaBoundaryModeZero)  ? __surf2Dwrite##type(val, surf, x, y, cudaBoundaryModeZero ) : \
         (mode == cudaBoundaryModeClamp) ? __surf2Dwrite##type(val, surf, x, y, cudaBoundaryModeClamp) : \
                                           __surf2Dwrite##type(val, surf, x, y, cudaBoundaryModeTrap ))

#else /* __CUDA_ARCH__ >= 200 */

#define __surfModeSwitch(val, surf, x, y, mode, type) \
        __surf2Dwrite##type(val, surf, x, y, cudaBoundaryModeTrap)

#endif /* __CUDA_ARCH__ >= 200 */

template<class T>
static __inline__ __device__ void surf2Dwrite(T val, surface<void, 2> surf, int x, int y, int s, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  union {
    T       val;
    uchar1  c1;
    ushort1 s1;
    uint1   u1;
    uint2   u2;
    uint4   u4;
  } tmp;
  
  tmp.val = val;
  
  (s ==  1) ? (void)(__surfModeSwitch(tmp.c1, surf, x, y, mode, c1)) :
  (s ==  2) ? (void)(__surfModeSwitch(tmp.s1, surf, x, y, mode, s1)) :
  (s ==  4) ? (void)(__surfModeSwitch(tmp.u1, surf, x, y, mode, u1)) :
  (s ==  8) ? (void)(__surfModeSwitch(tmp.u2, surf, x, y, mode, u2)) :
  (s == 16) ? (void)(__surfModeSwitch(tmp.u4, surf, x, y, mode, u4)) :
              (void)0;
}

template<class T>
static __inline__ __device__ void surf2Dwrite(T val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{;
  surf2Dwrite(val, surf, x, y, (int)sizeof(T), mode);
}


static __inline__ __device__ void surf2Dwrite(char val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar1((unsigned char)val), surf, x, y, mode, c1);
}

static __inline__ __device__ void surf2Dwrite(signed char val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar1((unsigned char)val), surf, x, y, mode, c1);
}

static __inline__ __device__ void surf2Dwrite(unsigned char val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar1(val), surf, x, y, mode, c1);
}

static __inline__ __device__ void surf2Dwrite(char1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar1((unsigned char)val.x), surf, x, y, mode, c1);
}

static __inline__ __device__ void surf2Dwrite(uchar1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, c1);
}

static __inline__ __device__ void surf2Dwrite(char2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar2((unsigned char)val.x, (unsigned char)val.y), surf, x, y, mode, c2);
}

static __inline__ __device__ void surf2Dwrite(uchar2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, c2);
}

static __inline__ __device__ void surf2Dwrite(char4 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uchar4((unsigned char)val.x, (unsigned char)val.y, (unsigned char)val.z, (unsigned char)val.w), surf, x, y, mode, c4);
}

static __inline__ __device__ void surf2Dwrite(uchar4 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, c4);
}

static __inline__ __device__ void surf2Dwrite(short val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort1((unsigned short)val), surf, x, y, mode, s1);
}

static __inline__ __device__ void surf2Dwrite(unsigned short val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort1(val), surf, x, y, mode, s1);
}

static __inline__ __device__ void surf2Dwrite(short1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort1((unsigned short)val.x), surf, x, y, mode, s1);
}

static __inline__ __device__ void surf2Dwrite(ushort1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, s1);
}

static __inline__ __device__ void surf2Dwrite(short2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort2((unsigned short)val.x, (unsigned short)val.y), surf, x, y, mode, s2);
}

static __inline__ __device__ void surf2Dwrite(ushort2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, s2);
}

static __inline__ __device__ void surf2Dwrite(short4 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ushort4((unsigned short)val.x, (unsigned short)val.y, (unsigned short)val.z, (unsigned short)val.w), surf, x, y, mode, s4);
}

static __inline__ __device__ void surf2Dwrite(ushort4 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, s4);
}

static __inline__ __device__ void surf2Dwrite(int val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val), surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(unsigned int val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1(val), surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(int1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val.x), surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(uint1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(int2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint2((unsigned int)val.x, (unsigned int)val.y), surf, x, y, mode, u2);
}

static __inline__ __device__ void surf2Dwrite(uint2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, u2);
}

static __inline__ __device__ void surf2Dwrite(int4 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint4((unsigned int)val.x, (unsigned int)val.y, (unsigned int)val.z, (unsigned int)val.w), surf, x, y, mode, u4);
}

static __inline__ __device__ void surf2Dwrite(uint4 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, u4);
}

static __inline__ __device__ void surf2Dwrite(long long int val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ulonglong1((unsigned long long int)val), surf, x, y, mode, l1);
}

static __inline__ __device__ void surf2Dwrite(unsigned long long int val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ulonglong1(val), surf, x, y, mode, l1);
}

static __inline__ __device__ void surf2Dwrite(longlong1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ulonglong1((unsigned long long int)val.x), surf, x, y, mode, l1);
}

static __inline__ __device__ void surf2Dwrite(ulonglong1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, l1);
}

static __inline__ __device__ void surf2Dwrite(longlong2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_ulonglong2((unsigned long long int)val.x, (unsigned long long int)val.y), surf, x, y, mode, l2);
}

static __inline__ __device__ void surf2Dwrite(ulonglong2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(val, surf, x, y, mode, l2);
}

#if !defined(__LP64__)

static __inline__ __device__ void surf2Dwrite(long int val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val), surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(unsigned long int val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val), surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(long1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val.x), surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(ulong1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)val.x), surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(long2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint2((unsigned int)val.x, (unsigned int)val.y), surf, x, y, mode, u2);
}

static __inline__ __device__ void surf2Dwrite(ulong2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint2((unsigned int)val.x, (unsigned int)val.y), surf, x, y, mode, u2);
}

static __inline__ __device__ void surf2Dwrite(long4 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint4((unsigned int)val.x, (unsigned int)val.y, (unsigned int)val.z, (unsigned int)val.w), surf, x, y, mode, u4);
}

static __inline__ __device__ void surf2Dwrite(ulong4 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint4((unsigned int)val.x, (unsigned int)val.y, (unsigned int)val.z, (unsigned int)val.w), surf, x, y, mode, u4);
}

#endif /* !__LP64__ */

static __inline__ __device__ void surf2Dwrite(float val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)__float_as_int(val)), surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(float1 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint1((unsigned int)__float_as_int(val.x)), surf, x, y, mode, u1);
}

static __inline__ __device__ void surf2Dwrite(float2 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint2((unsigned int)__float_as_int(val.x), __float_as_int((unsigned int)val.y)), surf, x, y, mode, u2);
}

static __inline__ __device__ void surf2Dwrite(float4 val, surface<void, 2> surf, int x, int y, enum cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap)
{
  __surfModeSwitch(make_uint4((unsigned int)__float_as_int(val.x), (unsigned int)__float_as_int(val.y), (unsigned int)__float_as_int(val.z), (unsigned int)__float_as_int(val.w)), surf, x, y, mode, u4);
}

#undef __surfModeSwitch

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#elif defined(__CUDABE__)

extern uchar1     __surf1Dreadc1(const void*, int, enum cudaSurfaceBoundaryMode);
extern uchar2     __surf1Dreadc2(const void*, int, enum cudaSurfaceBoundaryMode);
extern uchar4     __surf1Dreadc4(const void*, int, enum cudaSurfaceBoundaryMode);
extern ushort1    __surf1Dreads1(const void*, int, enum cudaSurfaceBoundaryMode);
extern ushort2    __surf1Dreads2(const void*, int, enum cudaSurfaceBoundaryMode);
extern ushort4    __surf1Dreads4(const void*, int, enum cudaSurfaceBoundaryMode);
extern uint1      __surf1Dreadu1(const void*, int, enum cudaSurfaceBoundaryMode);
extern uint2      __surf1Dreadu2(const void*, int, enum cudaSurfaceBoundaryMode);
extern uint4      __surf1Dreadu4(const void*, int, enum cudaSurfaceBoundaryMode);
extern ulonglong1 __surf1Dreadl1(const void*, int, enum cudaSurfaceBoundaryMode);
extern ulonglong2 __surf1Dreadl2(const void*, int, enum cudaSurfaceBoundaryMode);
extern uchar1     __surf2Dreadc1(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern uchar2     __surf2Dreadc2(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern uchar4     __surf2Dreadc4(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern ushort1    __surf2Dreads1(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern ushort2    __surf2Dreads2(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern ushort4    __surf2Dreads4(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern uint1      __surf2Dreadu1(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern uint2      __surf2Dreadu2(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern uint4      __surf2Dreadu4(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong1 __surf2Dreadl1(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong2 __surf2Dreadl2(const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwritec1(    uchar1, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwritec2(    uchar2, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwritec4(    uchar4, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwrites1(   ushort1, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwrites2(   ushort2, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwrites4(   ushort4, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwriteu1(     uint1, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwriteu2(     uint2, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwriteu4(     uint4, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwritel1(ulonglong1, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf1Dwritel2(ulonglong2, const void*, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwritec1(    uchar1, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwritec2(    uchar2, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwritec4(    uchar4, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwrites1(   ushort1, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwrites2(   ushort2, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwrites4(   ushort4, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwriteu1(     uint1, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwriteu2(     uint2, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwriteu4(     uint4, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwritel1(ulonglong1, const void*, int, int, enum cudaSurfaceBoundaryMode);
extern void       __surf2Dwritel2(ulonglong2, const void*, int, int, enum cudaSurfaceBoundaryMode);

#endif /* __cplusplus && __CUDACC__ */

#endif /* !__SURFACE_FUNCTIONS_H__ */
