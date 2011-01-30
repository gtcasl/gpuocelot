/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
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

#if !defined(__VECTOR_TYPES_H__)
#define __VECTOR_TYPES_H__

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "host_defines.h"

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#if !defined(__cuda_assign_operators)

#define __cuda_assign_operators(tag)

#endif /* !__cuda_assign_operators */

#if !defined(__CUDACC__) && !defined(__CUDABE__) && \
    !defined (__MULTI_CORE__) && defined(_WIN32) && !defined(_WIN64)

#define __cuda_builtin_vector_align8(tag, ...) \
        struct tag {                           \
          union {                              \
            struct { __VA_ARGS__; };           \
            struct { long long int :1,:0; };   \
          };                                   \
          __cuda_assign_operators(tag)         \
        }

#else /* !__CUDACC__ && !__CUDABE__ && !__MULTI_CORE__ && _WIN32 && !_WIN64 */

#define __cuda_builtin_vector_align8(tag, ...) \
        struct __align__(8) tag {              \
          __VA_ARGS__;                         \
          __cuda_assign_operators(tag)         \
        }

#endif /* !__CUDACC__ && !__CUDABE__ && !__MULTI_CORE__ && _WIN32 && !_WIN64 */

/*DEVICE_BUILTIN*/
struct char1
{
  signed char x;
  __cuda_assign_operators(char1)
};

/*DEVICE_BUILTIN*/
struct uchar1 
{
  unsigned char x;
  __cuda_assign_operators(uchar1)
};

/*DEVICE_BUILTIN*/
struct __align__(2) char2
{
  signed char x, y;
  __cuda_assign_operators(char2)
};

/*DEVICE_BUILTIN*/
struct __align__(2) uchar2
{
  unsigned char x, y;
  __cuda_assign_operators(uchar2)
};

/*DEVICE_BUILTIN*/
struct char3
{
  signed char x, y, z;
  __cuda_assign_operators(char3)
};

/*DEVICE_BUILTIN*/
struct uchar3
{
  unsigned char x, y, z;
  __cuda_assign_operators(uchar3)
};

/*DEVICE_BUILTIN*/
struct __align__(4) char4
{
  signed char x, y, z, w;
  __cuda_assign_operators(char4)
};

/*DEVICE_BUILTIN*/
struct __align__(4) uchar4
{
  unsigned char x, y, z, w;
  __cuda_assign_operators(uchar4)
};

/*DEVICE_BUILTIN*/
struct short1
{
  short x;
  __cuda_assign_operators(short1)
};

/*DEVICE_BUILTIN*/
struct ushort1
{
  unsigned short x;
  __cuda_assign_operators(ushort1)
};

/*DEVICE_BUILTIN*/
struct __align__(4) short2
{
  short x, y;
  __cuda_assign_operators(short2)
};

/*DEVICE_BUILTIN*/
struct __align__(4) ushort2
{
  unsigned short x, y;
  __cuda_assign_operators(ushort2)
};

/*DEVICE_BUILTIN*/
struct short3
{
  short x, y, z;
  __cuda_assign_operators(short3)
};

/*DEVICE_BUILTIN*/
struct ushort3
{
  unsigned short x, y, z;
  __cuda_assign_operators(ushort3)
};

/*DEVICE_BUILTIN*/
__cuda_builtin_vector_align8(short4, short x, y, z, w);

/*DEVICE_BUILTIN*/
__cuda_builtin_vector_align8(ushort4, unsigned short x, y, z, w);

/*DEVICE_BUILTIN*/
struct int1
{
  int x;
  __cuda_assign_operators(int1)
};

/*DEVICE_BUILTIN*/
struct uint1
{
  unsigned int x;
  __cuda_assign_operators(uint1)
};

/*DEVICE_BUILTIN*/
__cuda_builtin_vector_align8(int2, int x, y);

/*DEVICE_BUILTIN*/
__cuda_builtin_vector_align8(uint2, unsigned int x, y);

/*DEVICE_BUILTIN*/
struct int3
{
  int x, y, z;
  __cuda_assign_operators(int3)
};

/*DEVICE_BUILTIN*/
struct uint3
{
  unsigned int x, y, z;
  __cuda_assign_operators(uint3)
};

/*DEVICE_BUILTIN*/
struct __builtin_align__(16) int4
{
  int x, y, z, w;
  __cuda_assign_operators(int4)
};

/*DEVICE_BUILTIN*/
struct __builtin_align__(16) uint4
{
  unsigned int x, y, z, w;
  __cuda_assign_operators(uint4)
};

/*DEVICE_BUILTIN*/
struct long1
{
  long int x;
  __cuda_assign_operators(long1)
};

/*DEVICE_BUILTIN*/
struct ulong1
{
  unsigned long x;
  __cuda_assign_operators(ulong1)
};

#if defined (_WIN32)

/*DEVICE_BUILTIN*/
__cuda_builtin_vector_align8(long2, long int x, y);

/*DEVICE_BUILTIN*/
__cuda_builtin_vector_align8(ulong2, unsigned long int x, y);

#else /* _WIN32 */

/*DEVICE_BUILTIN*/
struct __align__(2*sizeof(long int)) long2
{
  long int x, y;
  __cuda_assign_operators(long2)
};

/*DEVICE_BUILTIN*/
struct __align__(2*sizeof(unsigned long int)) ulong2
{
  unsigned long int x, y;
  __cuda_assign_operators(ulong2)
};

#endif /* _WIN32 */

#if !defined(__LP64__)

/*DEVICE_BUILTIN*/
struct long3
{
  long int x, y, z;
  __cuda_assign_operators(long3)
};

/*DEVICE_BUILTIN*/
struct ulong3
{
  unsigned long int x, y, z;
  __cuda_assign_operators(ulong3)
};

/*DEVICE_BUILTIN*/
struct __builtin_align__(16) long4
{
  long int x, y, z, w;
  __cuda_assign_operators(long4)
};

/*DEVICE_BUILTIN*/
struct __builtin_align__(16) ulong4
{
  unsigned long int x, y, z, w;
  __cuda_assign_operators(ulong4)
};

#endif /* !__LP64__ */

/*DEVICE_BUILTIN*/
struct float1
{
  float x;
  __cuda_assign_operators(float1)
};

/*DEVICE_BUILTIN*/
__cuda_builtin_vector_align8(float2, float x, y);

/*DEVICE_BUILTIN*/
struct float3
{
  float x, y, z;
  __cuda_assign_operators(float3)
};

/*DEVICE_BUILTIN*/
struct __builtin_align__(16) float4
{
  float x, y, z, w;
  __cuda_assign_operators(float4)
};

/*DEVICE_BUILTIN*/
struct longlong1
{
  long long int x;
  __cuda_assign_operators(longlong1)
};

/*DEVICE_BUILTIN*/
struct ulonglong1
{
  unsigned long long int x;
  __cuda_assign_operators(ulonglong1)
};

/*DEVICE_BUILTIN*/
struct __builtin_align__(16) longlong2
{
  long long int x, y;
  __cuda_assign_operators(longlong2)
};

/*DEVICE_BUILTIN*/
struct __builtin_align__(16) ulonglong2
{
  unsigned long long int x, y;
  __cuda_assign_operators(ulonglong2)
};

/*DEVICE_BUILTIN*/
struct double1
{
  double x;
  __cuda_assign_operators(double1)
};

/*DEVICE_BUILTIN*/
struct __builtin_align__(16) double2
{
  double x, y;
  __cuda_assign_operators(double2)
};

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/*DEVICE_BUILTIN*/
typedef struct char1 char1;
/*DEVICE_BUILTIN*/
typedef struct uchar1 uchar1;
/*DEVICE_BUILTIN*/
typedef struct char2 char2;
/*DEVICE_BUILTIN*/
typedef struct uchar2 uchar2;
/*DEVICE_BUILTIN*/
typedef struct char3 char3;
/*DEVICE_BUILTIN*/
typedef struct uchar3 uchar3;
/*DEVICE_BUILTIN*/
typedef struct char4 char4;
/*DEVICE_BUILTIN*/
typedef struct uchar4 uchar4;
/*DEVICE_BUILTIN*/
typedef struct short1 short1;
/*DEVICE_BUILTIN*/
typedef struct ushort1 ushort1;
/*DEVICE_BUILTIN*/
typedef struct short2 short2;
/*DEVICE_BUILTIN*/
typedef struct ushort2 ushort2;
/*DEVICE_BUILTIN*/
typedef struct short3 short3;
/*DEVICE_BUILTIN*/
typedef struct ushort3 ushort3;
/*DEVICE_BUILTIN*/
typedef struct short4 short4;
/*DEVICE_BUILTIN*/
typedef struct ushort4 ushort4;
/*DEVICE_BUILTIN*/
typedef struct int1 int1;
/*DEVICE_BUILTIN*/
typedef struct uint1 uint1;
/*DEVICE_BUILTIN*/
typedef struct int2 int2;
/*DEVICE_BUILTIN*/
typedef struct uint2 uint2;
/*DEVICE_BUILTIN*/
typedef struct int3 int3;
/*DEVICE_BUILTIN*/
typedef struct uint3 uint3;
/*DEVICE_BUILTIN*/
typedef struct int4 int4;
/*DEVICE_BUILTIN*/
typedef struct uint4 uint4;
/*DEVICE_BUILTIN*/
typedef struct long1 long1;
/*DEVICE_BUILTIN*/
typedef struct ulong1 ulong1;
/*DEVICE_BUILTIN*/
typedef struct long2 long2;
/*DEVICE_BUILTIN*/
typedef struct ulong2 ulong2;
/*DEVICE_BUILTIN*/
typedef struct long3 long3;
/*DEVICE_BUILTIN*/
typedef struct ulong3 ulong3;
/*DEVICE_BUILTIN*/
typedef struct long4 long4;
/*DEVICE_BUILTIN*/
typedef struct ulong4 ulong4;
/*DEVICE_BUILTIN*/
typedef struct float1 float1;
/*DEVICE_BUILTIN*/
typedef struct float2 float2;
/*DEVICE_BUILTIN*/
typedef struct float3 float3;
/*DEVICE_BUILTIN*/
typedef struct float4 float4;
/*DEVICE_BUILTIN*/
typedef struct longlong1 longlong1;
/*DEVICE_BUILTIN*/
typedef struct ulonglong1 ulonglong1;
/*DEVICE_BUILTIN*/
typedef struct longlong2 longlong2;
/*DEVICE_BUILTIN*/
typedef struct ulonglong2 ulonglong2;
/*DEVICE_BUILTIN*/
typedef struct double1 double1;
/*DEVICE_BUILTIN*/
typedef struct double2 double2;

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/*DEVICE_BUILTIN*/
struct dim3
{
    unsigned int x, y, z;
#if defined(__cplusplus)
    __host__ __device__ dim3(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1) : x(x), y(y), z(z) {}
    __host__ __device__ dim3(uint3 v) : x(v.x), y(v.y), z(v.z) {}
    __host__ __device__ operator uint3(void) { uint3 t; t.x = x; t.y = y; t.z = z; return t; }
#endif /* __cplusplus */
};

/*DEVICE_BUILTIN*/
typedef struct dim3 dim3;

#undef  __cuda_assign_operators
#undef  __cuda_builtin_vector_align8

#endif /* !__VECTOR_TYPES_H__ */
