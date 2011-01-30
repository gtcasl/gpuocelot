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

#if !defined(__SM_13_DOUBLE_FUNCTIONS_H__)
#define __SM_13_DOUBLE_FUNCTIONS_H__

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#if defined(__cplusplus) && defined(__CUDACC__)

#if !defined(__CUDA_ARCH__) || __CUDA_ARCH__ >= 130

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "builtin_types.h"
#include "device_types.h"
#include "host_defines.h"

extern "C"
{

/*DEVICE_BUILTIN*/
extern __device__ long long int         __double_as_longlong(double);
/*DEVICE_BUILTIN*/
extern __device__ double                __longlong_as_double(long long int);

/*DEVICE_BUILTIN*/
extern __device__ double                __fma_rn(double, double, double);
/*DEVICE_BUILTIN*/
extern __device__ double                __fma_rz(double, double, double);
/*DEVICE_BUILTIN*/
extern __device__ double                __fma_ru(double, double, double);
/*DEVICE_BUILTIN*/
extern __device__ double                __fma_rd(double, double, double);

/*DEVICE_BUILTIN*/
extern __device__ double                __dadd_rn(double, double);
/*DEVICE_BUILTIN*/
extern __device__ double                __dadd_rz(double, double);
/*DEVICE_BUILTIN*/
extern __device__ double                __dadd_ru(double, double);
/*DEVICE_BUILTIN*/
extern __device__ double                __dadd_rd(double, double);

/*DEVICE_BUILTIN*/
extern __device__ double                __dmul_rn(double, double);
/*DEVICE_BUILTIN*/
extern __device__ double                __dmul_rz(double, double);
/*DEVICE_BUILTIN*/
extern __device__ double                __dmul_ru(double, double);
/*DEVICE_BUILTIN*/
extern __device__ double                __dmul_rd(double, double);

/*DEVICE_BUILTIN*/
extern __device__ float                 __double2float_rn(double);
/*DEVICE_BUILTIN*/
extern __device__ float                 __double2float_rz(double);
/*DEVICE_BUILTIN*/
extern __device__ float                 __double2float_ru(double);
/*DEVICE_BUILTIN*/
extern __device__ float                 __double2float_rd(double);

/*DEVICE_BUILTIN*/
extern __device__ int                   __double2int_rn(double);
/*DEVICE_BUILTIN*/
extern __device__ int                   __double2int_ru(double);
/*DEVICE_BUILTIN*/
extern __device__ int                   __double2int_rd(double);

/*DEVICE_BUILTIN*/
extern __device__ unsigned int          __double2uint_rn(double);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int          __double2uint_ru(double);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int          __double2uint_rd(double);

/*DEVICE_BUILTIN*/
extern __device__ long long int          __double2ll_rn(double);
/*DEVICE_BUILTIN*/
extern __device__ long long int          __double2ll_ru(double);
/*DEVICE_BUILTIN*/
extern __device__ long long int          __double2ll_rd(double);

/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __double2ull_rn(double);
/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __double2ull_ru(double);
/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __double2ull_rd(double);

/*DEVICE_BUILTIN*/
extern __device__ double                 __int2double_rn(int);

/*DEVICE_BUILTIN*/
extern __device__ double                 __uint2double_rn(unsigned int);

/*DEVICE_BUILTIN*/
extern __device__ double                 __ll2double_rn(long long int);
/*DEVICE_BUILTIN*/
extern __device__ double                 __ll2double_rz(long long int);
/*DEVICE_BUILTIN*/
extern __device__ double                 __ll2double_ru(long long int);
/*DEVICE_BUILTIN*/
extern __device__ double                 __ll2double_rd(long long int);

/*DEVICE_BUILTIN*/
extern __device__ double                 __ull2double_rn(unsigned long long int);
/*DEVICE_BUILTIN*/
extern __device__ double                 __ull2double_rz(unsigned long long int);
/*DEVICE_BUILTIN*/
extern __device__ double                 __ull2double_ru(unsigned long long int);
/*DEVICE_BUILTIN*/
extern __device__ double                 __ull2double_rd(unsigned long long int);

/*DEVICE_BUILTIN*/
extern __device__ int                    __double2hiint(double);
/*DEVICE_BUILTIN*/
extern __device__ int                    __double2loint(double);
/*DEVICE_BUILTIN*/
extern __device__ double                 __hiloint2double(int, int);

}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ double fma(double a, double b, double c, enum cudaRoundMode mode)
{
  return mode == cudaRoundZero   ? __fma_rz(a, b, c) :
         mode == cudaRoundPosInf ? __fma_ru(a, b, c) :
         mode == cudaRoundMinInf ? __fma_rd(a, b, c) :
                                   __fma_rn(a, b, c);
}

static __inline__ __device__ double dmul(double a, double b, enum cudaRoundMode mode = cudaRoundNearest)
{
  return mode == cudaRoundZero   ? __dmul_rz(a, b) :
         mode == cudaRoundPosInf ? __dmul_ru(a, b) :
         mode == cudaRoundMinInf ? __dmul_rd(a, b) :
                                   __dmul_rn(a, b);
}

static __inline__ __device__ double dadd(double a, double b, enum cudaRoundMode mode = cudaRoundNearest)
{
  return mode == cudaRoundZero   ? __dadd_rz(a, b) :
         mode == cudaRoundPosInf ? __dadd_ru(a, b) :
         mode == cudaRoundMinInf ? __dadd_rd(a, b) :
                                   __dadd_rn(a, b);
}

static __inline__ __device__ int double2int(double a, enum cudaRoundMode mode = cudaRoundZero)
{
  return mode == cudaRoundNearest ? __double2int_rn(a) :
         mode == cudaRoundPosInf  ? __double2int_ru(a) :
         mode == cudaRoundMinInf  ? __double2int_rd(a) :
                                    __double2int_rz(a);
}

static __inline__ __device__ unsigned int double2uint(double a, enum cudaRoundMode mode = cudaRoundZero)
{
  return mode == cudaRoundNearest ? __double2uint_rn(a) :
         mode == cudaRoundPosInf  ? __double2uint_ru(a) :
         mode == cudaRoundMinInf  ? __double2uint_rd(a) :
                                    __double2uint_rz(a);
}

static __inline__ __device__ long long int double2ll(double a, enum cudaRoundMode mode = cudaRoundZero)
{
  return mode == cudaRoundNearest ? __double2ll_rn(a) :
         mode == cudaRoundPosInf  ? __double2ll_ru(a) :
         mode == cudaRoundMinInf  ? __double2ll_rd(a) :
                                    __double2ll_rz(a);
}

static __inline__ __device__ unsigned long long int double2ull(double a, enum cudaRoundMode mode = cudaRoundZero)
{
  return mode == cudaRoundNearest ? __double2ull_rn(a) :
         mode == cudaRoundPosInf  ? __double2ull_ru(a) :
         mode == cudaRoundMinInf  ? __double2ull_rd(a) :
                                    __double2ull_rz(a);
}

static __inline__ __device__ double ll2double(long long int a, enum cudaRoundMode mode = cudaRoundNearest)
{
  return mode == cudaRoundZero   ? __ll2double_rz(a) :
         mode == cudaRoundPosInf ? __ll2double_ru(a) :
         mode == cudaRoundMinInf ? __ll2double_rd(a) :
                                   __ll2double_rn(a);
}

static __inline__ __device__ double ull2double(unsigned long long int a, enum cudaRoundMode mode = cudaRoundNearest)
{
  return mode == cudaRoundZero   ? __ull2double_rz(a) :
         mode == cudaRoundPosInf ? __ull2double_ru(a) :
         mode == cudaRoundMinInf ? __ull2double_rd(a) :
                                   __ull2double_rn(a);
}

static __inline__ __device__ double int2double(int a, enum cudaRoundMode mode = cudaRoundNearest)
{
  return (double)a;
}

static __inline__ __device__ double uint2double(unsigned int a, enum cudaRoundMode mode = cudaRoundNearest)
{
  return (double)a;
}

static __inline__ __device__ double float2double(float a, enum cudaRoundMode mode = cudaRoundNearest)
{
  return (double)a;
}

#endif /* !__CUDA_ARCH__ || __CUDA_ARCH__ >= 130 */

#elif defined(__CUDABE__)

#if __CUDA_ARCH__ < 130

static __forceinline__ double __internal_fma_kernel(double x, double y, double z, enum cudaRoundMode rndMode)
{
  struct __cudart_UintUint {
    unsigned int lo;
    unsigned int hi;
  } xx, yy, zz, ww;
  unsigned int s, t, u, prod0, prod1, prod2, prod3, expo_x, expo_y, expo_z;
  
  xx.hi = __double2hiint(x);
  xx.lo = __double2loint(x);
  yy.hi = __double2hiint(y);
  yy.lo = __double2loint(y);
  zz.hi = __double2hiint(z);
  zz.lo = __double2loint(z);

  expo_z = 0x7FF;
  t =  xx.hi >> 20;
  expo_x = expo_z & t;
  expo_x = expo_x - 1;    /* expo(x) - 1 */
  t =  yy.hi >> 20;
  expo_y = expo_z & t;
  expo_y = expo_y - 1;    /* expo(y) - 1 */
  t =  zz.hi >> 20;
  expo_z = expo_z & t;
  expo_z = expo_z - 1;    /* expo(z) - 1 */

  if (!((expo_x <= 0x7FD) &&
        (expo_y <= 0x7FD) &&
        (expo_z <= 0x7FD))) {
    
    /* fma (nan, y, z) --> nan
       fma (x, nan, z) --> nan
       fma (x, y, nan) --> nan 
    */
    if (((yy.hi << 1) | (yy.lo != 0)) > 0xffe00000) {
      yy.hi |= 0x00080000;
      return __hiloint2double(yy.hi, yy.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) > 0xffe00000) {
      zz.hi |= 0x00080000;
      return __hiloint2double(zz.hi, zz.lo);
    }
    if (((xx.hi << 1) | (xx.lo != 0)) > 0xffe00000) {
      xx.hi |= 0x00080000;
      return __hiloint2double(xx.hi, xx.lo);
    }
    
    /* fma (0, inf, z) --> INDEFINITE
       fma (inf, 0, z) --> INDEFINITE
       fma (-inf,+y,+inf) --> INDEFINITE
       fma (+x,-inf,+inf) --> INDEFINITE
       fma (+inf,-y,+inf) --> INDEFINITE
       fma (-x,+inf,+inf) --> INDEFINITE
       fma (-inf,-y,-inf) --> INDEFINITE
       fma (-x,-inf,-inf) --> INDEFINITE
       fma (+inf,+y,-inf) --> INDEFINITE
       fma (+x,+inf,-inf) --> INDEFINITE
    */
    if (((((xx.hi << 1) | xx.lo) == 0) && 
         (((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000)) ||
        ((((yy.hi << 1) | yy.lo) == 0) && 
         (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000))) {
      xx.hi = 0xfff80000;
      xx.lo = 0x00000000;
      return __hiloint2double(xx.hi, xx.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      if ((((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) ||
          (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000)) {
        if ((int)(xx.hi ^ yy.hi ^ zz.hi) < 0) {
          xx.hi = 0xfff80000;
          xx.lo = 0x00000000;
          return __hiloint2double(xx.hi, xx.lo);
        }
      }
    }
    /* fma (inf, y, z) --> inf
       fma (x, inf, z) --> inf
       fma (x, y, inf) --> inf
    */
    if (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000) {
      xx.hi = xx.hi ^ (yy.hi & 0x80000000);
      return __hiloint2double(xx.hi, xx.lo);
    }
    if (((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) {
      yy.hi = yy.hi ^ (xx.hi & 0x80000000);
      return __hiloint2double(yy.hi, yy.lo);
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      return __hiloint2double(zz.hi, zz.lo);
    }
    /* fma (+0, -y, -0) --> -0
       fma (-0, +y, -0) --> -0
       fma (+x, -0, -0) --> -0
       fma (-x, +0, -0) --> -0
    */
    if ((zz.hi == 0x80000000) && (zz.lo == 0)) {
      if ((((xx.hi << 1) | xx.lo) == 0) ||
          (((yy.hi << 1) | yy.lo) == 0)) {
        if ((int)(xx.hi ^ yy.hi) < 0) {
          return __hiloint2double(zz.hi, zz.lo);
        }
      }
    }
    /* fma (0, y, 0) --> +0  (-0 if round down and signs of addend differ)
       fma (x, 0, 0) --> +0  (-0 if round down and signs of addend differ)
    */
    if ((((zz.hi << 1) | zz.lo) == 0) &&
        ((((xx.hi << 1) | xx.lo) == 0) ||
         (((yy.hi << 1) | yy.lo) == 0))) {
      if (rndMode == cudaRoundMinInf) {
        return __hiloint2double((xx.hi ^ yy.hi ^ zz.hi) & 0x80000000, zz.lo);
      } else {
        zz.hi &= 0x7fffffff;
        return __hiloint2double(zz.hi, zz.lo);
      }
    }
    
    /* fma (0, y, z) --> z
       fma (x, 0, z) --> z
    */
    if ((((xx.hi << 1) | xx.lo) == 0) ||
        (((yy.hi << 1) | yy.lo) == 0)) {
      return __hiloint2double(zz.hi, zz.lo);
    }
    
    if (expo_x == 0xffffffff) {
      expo_x++;
      t = xx.hi & 0x80000000;
      s = xx.lo >> 21;
      xx.lo = xx.lo << 11;
      xx.hi = xx.hi << 11;
      xx.hi = xx.hi | s;
      if (!xx.hi) {
        xx.hi = xx.lo;
        xx.lo = 0;
        expo_x -= 32;
      }
      while ((int)xx.hi > 0) {
        s = xx.lo >> 31;
        xx.lo = xx.lo + xx.lo;
        xx.hi = xx.hi + xx.hi;
        xx.hi = xx.hi | s;
        expo_x--;
      }
      xx.lo = (xx.lo >> 11);
      xx.lo |= (xx.hi << 21);
      xx.hi = (xx.hi >> 11) | t;
    }
    if (expo_y == 0xffffffff) {
      expo_y++;
      t = yy.hi & 0x80000000;
      s = yy.lo >> 21;
      yy.lo = yy.lo << 11;
      yy.hi = yy.hi << 11;
      yy.hi = yy.hi | s;
      if (!yy.hi) {
        yy.hi = yy.lo;
        yy.lo = 0;
        expo_y -= 32;
      }
      while ((int)yy.hi > 0) {
        s = yy.lo >> 31;
        yy.lo = yy.lo + yy.lo;
        yy.hi = yy.hi + yy.hi;
        yy.hi = yy.hi | s;
        expo_y--;
      }
      yy.lo = (yy.lo >> 11);
      yy.lo |= (yy.hi << 21);
      yy.hi = (yy.hi >> 11) | t;
    }
    if (expo_z == 0xffffffff) {
      expo_z++;
      t = zz.hi & 0x80000000;
      s = zz.lo >> 21;
      zz.lo = zz.lo << 11;
      zz.hi = zz.hi << 11;
      zz.hi = zz.hi | s;
      if (!zz.hi) {
        zz.hi = zz.lo;
        zz.lo = 0;
        expo_z -= 32;
      }
      while ((int)zz.hi > 0) {
        s = zz.lo >> 31;
        zz.lo = zz.lo + zz.lo;
        zz.hi = zz.hi + zz.hi;
        zz.hi = zz.hi | s;
        expo_z--;
      }
      zz.lo = (zz.lo >> 11);
      zz.lo |= (zz.hi << 21);
      zz.hi = (zz.hi >> 11) | t;
    }
  }
  
  expo_x = expo_x + expo_y;
  expo_y = xx.hi ^ yy.hi;
  t = xx.lo >> 21;
  xx.lo = xx.lo << 11;
  xx.hi = xx.hi << 11;
  xx.hi = xx.hi | t;
  yy.hi = yy.hi & 0x000fffff;
  xx.hi = xx.hi | 0x80000000; /* set mantissa hidden bit */
  yy.hi = yy.hi | 0x00100000; /* set mantissa hidden bit */

  prod0 = xx.lo * yy.lo;
  prod1 = __umulhi (xx.lo, yy.lo);
  prod2 = xx.hi * yy.lo;
  prod3 = xx.lo * yy.hi;
  prod1 += prod2;
  t = prod1 < prod2;
  prod1 += prod3;
  t += prod1 < prod3;
  prod2 = __umulhi (xx.hi, yy.lo);
  prod3 = __umulhi (xx.lo, yy.hi);
  prod2 += prod3;
  s = prod2 < prod3;
  prod3 = xx.hi * yy.hi;
  prod2 += prod3;
  s += prod2 < prod3;
  prod2 += t;
  s += prod2 < t;
  prod3 = __umulhi (xx.hi, yy.hi) + s;
  
  yy.lo = prod0;                 /* mantissa */
  yy.hi = prod1;                 /* mantissa */
  xx.lo = prod2;                 /* mantissa */
  xx.hi = prod3;                 /* mantissa */
  expo_x = expo_x - (1023 - 2);  /* expo-1 */
  expo_y = expo_y & 0x80000000;  /* sign */

  if (xx.hi < 0x00100000) {
    s = xx.lo >> 31;
    s = (xx.hi << 1) + s;
    xx.hi = s;
    s = yy.hi >> 31;
    s = (xx.lo << 1) + s;
    xx.lo = s;
    s = yy.lo >> 31;
    s = (yy.hi << 1) + s;
    yy.hi = s;
    s = yy.lo << 1;
    yy.lo = s;
    expo_x--;
  }

  t = 0;
  if (((zz.hi << 1) | zz.lo) != 0) { /* z is not zero */
    
    s = zz.hi & 0x80000000;
    
    zz.hi &= 0x000fffff;
    zz.hi |= 0x00100000;
    ww.hi = 0;
    ww.lo = 0;
    
    /* compare and swap. put augend into xx:yy */
    if ((int)expo_z > (int)expo_x) {
      t = expo_z;
      expo_z = expo_x;
      expo_x = t;
      t = zz.hi;
      zz.hi = xx.hi;
      xx.hi = t;
      t = zz.lo;
      zz.lo = xx.lo;
      xx.lo = t;
      t = ww.hi;
      ww.hi = yy.hi;
      yy.hi = t;
      t = ww.lo;
      ww.lo = yy.lo;
      yy.lo = t;
      t = expo_y;
      expo_y = s;
      s = t;
    }
    
    /* augend_sign = expo_y, augend_mant = xx:yy, augend_expo = expo_x */
    /* addend_sign = s, addend_mant = zz:ww, addend_expo = expo_z */
    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 107) {
      /* denormalize addend */
      t = 0;
      while (expo_z >= 32) {
        t     = ww.lo | (t != 0);
        ww.lo = ww.hi;
        ww.hi = zz.lo;
        zz.lo = zz.hi;
        zz.hi = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        t     = (t     >> expo_z) | (ww.lo << (32 - expo_z)) | 
                ((t << (32 - expo_z)) != 0);
        ww.lo = (ww.lo >> expo_z) | (ww.hi << (32 - expo_z));
        ww.hi = (ww.hi >> expo_z) | (zz.lo << (32 - expo_z));
        zz.lo = (zz.lo >> expo_z) | (zz.hi << (32 - expo_z));
        zz.hi = (zz.hi >> expo_z);
      }
    } else {
      t = 1;
      ww.lo = 0;
      ww.hi = 0;
      zz.lo = 0;
      zz.hi = 0;
    }
    if ((int)u < 0) {
      /* signs differ, effective subtraction */
      t = (unsigned)(-(int)t);
      s = (t != 0);
      u = yy.lo - s;
      s = u > yy.lo;
      yy.lo = u - ww.lo;
      s += yy.lo > u;
      u = yy.hi - s;
      s = u > yy.hi;
      yy.hi = u - ww.hi;
      s += yy.hi > u;
      u = xx.lo - s;
      s = u > xx.lo;
      xx.lo = u - zz.lo;
      s += xx.lo > u;
      xx.hi = (xx.hi - zz.hi) - s;
      if (!(xx.hi | xx.lo | yy.hi | yy.lo | t)) {
        /* complete cancelation, return 0 */
        if (rndMode == cudaRoundMinInf) {
          return __hiloint2double(0x80000000, xx.lo);
        } else {
          return __hiloint2double(xx.hi, xx.lo);
        }
      }
      if ((int)xx.hi < 0) {
        /* Oops, augend had smaller mantissa. Negate mantissa and flip
           sign of result
        */
        t = ~t;
        yy.lo = ~yy.lo;
        yy.hi = ~yy.hi;
        xx.lo = ~xx.lo;
        xx.hi = ~xx.hi;
        if (++t == 0) {
          if (++yy.lo == 0) {
            if (++yy.hi == 0) {
              if (++xx.lo == 0) {
              ++xx.hi;
              }
            }
          }
        }
        expo_y ^= 0x80000000;
      }
        
      /* normalize mantissa, if necessary */
      while (!(xx.hi & 0x00100000)) {
        xx.hi = (xx.hi << 1) | (xx.lo >> 31);
        xx.lo = (xx.lo << 1) | (yy.hi >> 31);
        yy.hi = (yy.hi << 1) | (yy.lo >> 31);
        yy.lo = (yy.lo << 1);
        expo_x--;
      }
    } else {
      /* signs are the same, effective addition */
      yy.lo = yy.lo + ww.lo;
      s = yy.lo < ww.lo;
      yy.hi = yy.hi + s;
      u = yy.hi < s;
      yy.hi = yy.hi + ww.hi;
      u += yy.hi < ww.hi;
      xx.lo = xx.lo + u;
      s = xx.lo < u;
      xx.lo = xx.lo + zz.lo;
      s += xx.lo < zz.lo;
      xx.hi = xx.hi + zz.hi + s;
      if (xx.hi & 0x00200000) {
        t = t | (yy.lo << 31);
        yy.lo = (yy.lo >> 1) | (yy.hi << 31);
        yy.hi = (yy.hi >> 1) | (xx.lo << 31);
        xx.lo = (xx.lo >> 1) | (xx.hi << 31);
        xx.hi = ((xx.hi & 0x80000000) | (xx.hi >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  t = yy.lo | (t != 0);
  t = yy.hi | (t != 0);
        
  xx.hi |= expo_y; /* or in sign bit */
  if (expo_x <= 0x7FD) {
    /* normal */
    xx.hi = xx.hi & ~0x00100000; /* lop off integer bit */
    s = xx.lo & 1; /* mantissa lsb */
    u = xx.lo;
    if (rndMode == cudaRoundNearest) {
      xx.lo += (t == 0x80000000) ? s : (t >> 31);
    } else if (((rndMode == cudaRoundPosInf) && t && (!expo_y)) ||
               ((rndMode == cudaRoundMinInf) && t && expo_y)) {
      xx.lo += 1;
    }
    xx.hi += (u > xx.lo);
    xx.hi += ((expo_x + 1) << 20);
    return __hiloint2double(xx.hi, xx.lo);
  } else if ((int)expo_x >= 2046) {      
    /* overflow */
    if ((rndMode == cudaRoundNearest) || 
        ((rndMode == cudaRoundPosInf) && (!expo_y)) ||
        ((rndMode == cudaRoundMinInf) && expo_y)) {
      xx.hi = (xx.hi & 0x80000000) | 0x7ff00000;
      xx.lo = 0;
    } else {
      xx.hi = (xx.hi & 0x80000000) | 0x7fefffff;
      xx.lo = 0xffffffff;
    }
    return __hiloint2double(xx.hi, xx.lo);
  }
  /* subnormal */
  expo_x = (unsigned)(-(int)expo_x);
  if (expo_x > 54) {
    /* massive underflow: return 0 or smallest denormal */
    if (((rndMode == cudaRoundPosInf) && (!expo_y)) ||
        ((rndMode == cudaRoundMinInf) && expo_y)) {
      return __hiloint2double(xx.hi & 0x80000000, 1);
    } else {
      return __hiloint2double(xx.hi & 0x80000000, 0);
    }
  }  
  yy.hi = xx.hi &  0x80000000;   /* save sign bit */
  xx.hi = xx.hi & ~0xffe00000;
  if (expo_x >= 32) {
    t = xx.lo | (t != 0);
    xx.lo = xx.hi;
    xx.hi = 0;
    expo_x -= 32;
  }
  if (expo_x) {
    t     = (t     >> expo_x) | (xx.lo << (32 - expo_x)) | (t != 0);
    xx.lo = (xx.lo >> expo_x) | (xx.hi << (32 - expo_x));
    xx.hi = (xx.hi >> expo_x);
  }
  expo_x = xx.lo & 1; 
  u = xx.lo;
  if (rndMode == cudaRoundNearest) {
    xx.lo += (t == 0x80000000) ? expo_x : (t >> 31);
  } else if (((rndMode == cudaRoundPosInf) && t && (!expo_y)) ||
             ((rndMode == cudaRoundMinInf) && t && expo_y)) {
    xx.lo += 1;
  }
  xx.hi += (u > xx.lo);
  xx.hi |= yy.hi;
  return __hiloint2double(xx.hi, xx.lo);
}

static __forceinline__ double __fma_rn(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundNearest);
}

static __forceinline__ double __fma_rd(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundMinInf);
}

static __forceinline__ double __fma_ru(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundPosInf);
}

static __forceinline__ double __fma_rz(double x, double y, double z)
{
  return __internal_fma_kernel(x, y, z, cudaRoundZero);
}

static __forceinline__ double __dadd_rz(double a, double b)
{
  return __fma_rz(a, CUDART_ONE, b); 
}

static __forceinline__ double __dadd_ru(double a, double b)
{
  return __fma_ru(a, CUDART_ONE, b); 
}

static __forceinline__ double __dadd_rd(double a, double b)
{
  return __fma_rd(a, CUDART_ONE, b); 
}

static __forceinline__ double __dmul_rz(double a, double b)
{
  return __fma_rz(a, b, CUDART_NEG_ZERO); 
}

static __forceinline__ double __dmul_ru(double a, double b)
{
  return __fma_ru(a, b, CUDART_NEG_ZERO); 
}

static __forceinline__ double __dmul_rd(double a, double b)
{
  return __fma_rd(a, b, CUDART_ZERO); 
}

static __forceinline__ double __dadd_rn(double a, double b)
{
  return __fma_rn(a, CUDART_ONE, b); 
}

static __forceinline__ double __dmul_rn(double a, double b)
{
  return __fma_rn(a, b, CUDART_NEG_ZERO); 
}

#endif /* __CUDA_ARCH__ < 130 */

#endif /* __cplusplus && __CUDACC__ */

#endif /* !__SM_13_DOUBLE_FUNCTIONS_H__ */
