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

#if !defined(__SM_11_ATOMIC_FUNCTIONS_H__)
#define __SM_11_ATOMIC_FUNCTIONS_H__

#if defined(__cplusplus) && defined(__CUDACC__)

#if !defined(__CUDA_ARCH__) || __CUDA_ARCH__ >= 110

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "builtin_types.h"
#include "host_defines.h"

extern "C"
{

/*DEVICE_BUILTIN*/
extern __device__ int          __iAtomicAdd(int *address, int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicAdd(unsigned int *address, unsigned int val);
/*DEVICE_BUILTIN*/
extern __device__ int          __iAtomicExch(int *address, int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicExch(unsigned int *address, unsigned int val);
/*DEVICE_BUILTIN*/
extern __device__ float        __fAtomicExch(float *address, float val);
/*DEVICE_BUILTIN*/
extern __device__ int          __iAtomicMin(int *address, int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicMin(unsigned int *address, unsigned int val);
/*DEVICE_BUILTIN*/
extern __device__ int          __iAtomicMax(int *address, int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicMax(unsigned int *address, unsigned int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicInc(unsigned int *address, unsigned int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicDec(unsigned int *address, unsigned int val);
/*DEVICE_BUILTIN*/
extern __device__ int          __iAtomicAnd(int *address, int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicAnd(unsigned int *address, unsigned int val);
/*DEVICE_BUILTIN*/
extern __device__ int          __iAtomicOr(int *address, int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicOr(unsigned int *address, unsigned int val);
/*DEVICE_BUILTIN*/
extern __device__ int          __iAtomicXor(int *address, int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicXor(unsigned int *address, unsigned int val);
/*DEVICE_BUILTIN*/
extern __device__ int          __iAtomicCAS(int *address, int compare, int val);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int __uAtomicCAS(unsigned int *address, unsigned int compare, unsigned int val);

}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int atomicAdd(int *address, int val)
{
  return __iAtomicAdd(address, val);
}

static __inline__ __device__ unsigned int atomicAdd(unsigned int *address, unsigned int val)
{
  return __uAtomicAdd(address, val);
}

static __inline__ __device__ int atomicSub(int *address, int val)
{
  return __iAtomicAdd(address, (unsigned int)-(int)val);
}

static __inline__ __device__ unsigned int atomicSub(unsigned int *address, unsigned int val)
{
  return __uAtomicAdd(address, (unsigned int)-(int)val);
}

static __inline__ __device__ int atomicExch(int *address, int val)
{
  return __iAtomicExch(address, val);
}

static __inline__ __device__ unsigned int atomicExch(unsigned int *address, unsigned int val)
{
  return __uAtomicExch(address, val);
}

static __inline__ __device__ float atomicExch(float *address, float val)
{
  return __fAtomicExch(address, val);
}

static __inline__ __device__ int atomicMin(int *address, int val)
{
  return __iAtomicMin(address, val);
}

static __inline__ __device__ unsigned int atomicMin(unsigned int *address, unsigned int val)
{
  return __uAtomicMin(address, val);
}

static __inline__ __device__ int atomicMax(int *address, int val)
{
  return __iAtomicMax(address, val);
}

static __inline__ __device__ unsigned int atomicMax(unsigned int *address, unsigned int val)
{
  return __uAtomicMax(address, val);
}

static __inline__ __device__ unsigned int atomicInc(unsigned int *address, unsigned int val)
{
  return __uAtomicInc(address, val);
}

static __inline__ __device__ unsigned int atomicDec(unsigned int *address, unsigned int val)
{
  return __uAtomicDec(address, val);
}

static __inline__ __device__ int atomicAnd(int *address, int val)
{
  return __iAtomicAnd(address, val);
}

static __inline__ __device__ unsigned int atomicAnd(unsigned int *address, unsigned int val)
{
  return __uAtomicAnd(address, val);
}

static __inline__ __device__ int atomicOr(int *address, int val)
{
  return __iAtomicOr(address, val);
}

static __inline__ __device__ unsigned int atomicOr(unsigned int *address, unsigned int val)
{
  return __uAtomicOr(address, val);
}

static __inline__ __device__ int atomicXor(int *address, int val)
{
  return __iAtomicXor(address, val);
}

static __inline__ __device__ unsigned int atomicXor(unsigned int *address, unsigned int val)
{
  return __uAtomicXor(address, val);
}

static __inline__ __device__ int atomicCAS(int *address, int compare, int val)
{
  return __iAtomicCAS(address, compare, val);
}

static __inline__ __device__ unsigned int atomicCAS(unsigned int *address, unsigned int compare, unsigned int val)
{
  return __uAtomicCAS(address, compare, val);
}

#endif /* !__CUDA_ARCH__ || __CUDA_ARCH__ >= 110 */

#endif /* __cplusplus && __CUDACC__ */

#endif /* !__SM_11_ATOMIC_FUNCTIONS_H__ */
