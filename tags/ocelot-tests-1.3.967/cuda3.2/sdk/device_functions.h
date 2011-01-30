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

#if !defined(__DEVICE_FUNCTIONS_H__)
#define __DEVICE_FUNCTIONS_H__

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#if defined(__cplusplus) && defined(__CUDACC__)

#include "builtin_types.h"
#include "device_types.h"
#include "host_defines.h"

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern "C"
{

/*DEVICE_BUILTIN*/
extern __device__ int                    __mulhi(int, int);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __umulhi(unsigned int, unsigned int);

/*DEVICE_BUILTIN*/
extern __device__ long long int          __mul64hi(long long int, long long int);
/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __umul64hi(unsigned long long int, unsigned long long int);

/*DEVICE_BUILTIN*/
extern __device__ float                  __int_as_float(int);
/*DEVICE_BUILTIN*/
extern __device__ int                    __float_as_int(float);

/*DEVICE_BUILTIN*/
extern __device__ void                   __syncthreads(void);
/*DEVICE_BUILTIN*/
extern __device__ void                   __prof_trigger(int);
/*DEVICE_BUILTIN*/
extern __device__ void                   __threadfence(void);
/*DEVICE_BUILTIN*/
extern __device__ void                   __threadfence_block(void);
/*DEVICE_BUILTIN*/
extern __device__ void                   __trap(void);
/*DEVICE_BUILTIN*/
extern __device__ void                   __brkpt(int);

/*DEVICE_BUILTIN*/
extern __device__ float                  __saturatef(float);

/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __sad(int, int, unsigned int);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __usad(unsigned int, unsigned int, unsigned int);

/*DEVICE_BUILTIN*/
extern __device__ int                    __mul24(int, int);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __umul24(unsigned int, unsigned int);

/*DEVICE_BUILTIN*/
extern __device__ float                  fdividef(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fdividef(float, float);

/*DEVICE_BUILTIN*/
extern __device__ double                 fdivide(double, double);

/*DEVICE_BUILTIN*/
extern __device__ float                  __sinf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ float                  __cosf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ float                  __tanf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ void                   __sincosf(float, float*, float*) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ float                  __expf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ float                  __exp10f(float) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ float                  __log2f(float) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ float                  __log10f(float) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ float                  __logf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ float                  __powf(float, float) __THROW;

/*DEVICE_BUILTIN*/
extern __device__ int                    __float2int_rn(float);
/*DEVICE_BUILTIN*/
extern __device__ int                    __float2int_rz(float);
/*DEVICE_BUILTIN*/
extern __device__ int                    __float2int_ru(float);
/*DEVICE_BUILTIN*/
extern __device__ int                    __float2int_rd(float);

/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __float2uint_rn(float);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __float2uint_rz(float);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __float2uint_ru(float);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __float2uint_rd(float);

/*DEVICE_BUILTIN*/
extern __device__ float                  __int2float_rn(int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __int2float_rz(int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __int2float_ru(int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __int2float_rd(int);

/*DEVICE_BUILTIN*/
extern __device__ float                  __uint2float_rn(unsigned int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __uint2float_rz(unsigned int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __uint2float_ru(unsigned int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __uint2float_rd(unsigned int);

/*DEVICE_BUILTIN*/
extern __device__ long long int          __float2ll_rn(float);
/*DEVICE_BUILTIN*/
extern __device__ long long int          __float2ll_rz(float);
/*DEVICE_BUILTIN*/
extern __device__ long long int          __float2ll_ru(float);
/*DEVICE_BUILTIN*/
extern __device__ long long int          __float2ll_rd(float);

/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __float2ull_rn(float);
/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __float2ull_rz(float);
/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __float2ull_ru(float);
/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __float2ull_rd(float);

/*DEVICE_BUILTIN*/
extern __device__ float                  __ll2float_rn(long long int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __ll2float_rz(long long int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __ll2float_ru(long long int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __ll2float_rd(long long int);

/*DEVICE_BUILTIN*/
extern __device__ float                  __ull2float_rn(unsigned long long int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __ull2float_rz(unsigned long long int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __ull2float_ru(unsigned long long int);
/*DEVICE_BUILTIN*/
extern __device__ float                  __ull2float_rd(unsigned long long int);

/*DEVICE_BUILTIN*/
extern __device__ unsigned short         __float2half_rn(float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __half2float(unsigned short);

/*DEVICE_BUILTIN*/
extern __device__ float                  __fadd_rn(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fadd_rz(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fadd_ru(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fadd_rd(float, float);

/*DEVICE_BUILTIN*/
extern __device__ float                  __fmul_rn(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fmul_rz(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fmul_ru(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fmul_rd(float, float);

/*DEVICE_BUILTIN*/
extern __device__ float                  __fmaf_rn(float, float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fmaf_rz(float, float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fmaf_ru(float, float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fmaf_rd(float, float, float);

/*DEVICE_BUILTIN*/
extern __device__ float                  __frcp_rn(float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __frcp_rz(float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __frcp_ru(float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __frcp_rd(float);

/*DEVICE_BUILTIN*/
extern __device__ float                  __fsqrt_rn(float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fsqrt_rz(float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fsqrt_ru(float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fsqrt_rd(float);

/*DEVICE_BUILTIN*/
extern __device__ float                  __fdiv_rn(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fdiv_rz(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fdiv_ru(float, float);
/*DEVICE_BUILTIN*/
extern __device__ float                  __fdiv_rd(float, float);

/*DEVICE_BUILTIN*/
extern __device__ int                    __clz(int);
/*DEVICE_BUILTIN*/
extern __device__ int                    __ffs(int);
/*DEVICE_BUILTIN*/
extern __device__ int                    __popc(unsigned int);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __brev(unsigned int);

/*DEVICE_BUILTIN*/
extern __device__ int                    __clzll(long long int);
/*DEVICE_BUILTIN*/
extern __device__ int                    __ffsll(long long int);
/*DEVICE_BUILTIN*/
extern __device__ int                    __popcll(unsigned long long int);
/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __brevll(unsigned long long int);

/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __byte_perm(unsigned int, unsigned int, unsigned int);

#if !defined(__CUDA_ARCH__) || __CUDA_ARCH__ >= 130

/*DEVICE_BUILTIN*/
extern __device__ int                    __double2int_rz(double);

/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __double2uint_rz(double);

/*DEVICE_BUILTIN*/
extern __device__ long long int          __double2ll_rz(double);

/*DEVICE_BUILTIN*/
extern __device__ unsigned long long int __double2ull_rz(double);

/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __pm0(void);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __pm1(void);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __pm2(void);
/*DEVICE_BUILTIN*/
extern __device__ unsigned int           __pm3(void);

#endif /* !__CUDA_ARCH__ || __CUDA_ARCH__ >= 130 */

}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __inline__ __device__ int mulhi(int a, int b)
{
  return __mulhi(a, b);
}

static __inline__ __device__ unsigned int mulhi(unsigned int a, unsigned int b)
{
  return __umulhi(a, b);
}

static __inline__ __device__ unsigned int mulhi(int a, unsigned int b)
{
  return __umulhi((unsigned int)a, b);
}

static __inline__ __device__ unsigned int mulhi(unsigned int a, int b)
{
  return __umulhi(a, (unsigned int)b);
}

static __inline__ __device__ long long int mul64hi(long long int a, long long int b)
{
  return __mul64hi(a, b);
}

static __inline__ __device__ unsigned long long int mul64hi(unsigned long long int a, unsigned long long int b)
{
  return __umul64hi(a, b);
}

static __inline__ __device__ unsigned long long int mul64hi(long long int a, unsigned long long int b)
{
  return __umul64hi((unsigned long long int)a, b);
}

static __inline__ __device__ unsigned long long int mul64hi(unsigned long long int a, long long int b)
{
  return __umul64hi(a, (unsigned long long int)b);
}

static __inline__ __device__ int float_as_int(float a)
{
  return __float_as_int(a);
}

static __inline__ __device__ float int_as_float(int a)
{
  return __int_as_float(a);
}

static __inline__ __device__ float saturate(float a)
{
  return __saturatef(a);
}

static __inline__ __device__ int mul24(int a, int b)
{
  return __mul24(a, b);
}

static __inline__ __device__ unsigned int umul24(unsigned int a, unsigned int b)
{
  return __umul24(a, b);
}

static __inline__ __device__ void trap(void)
{
  __trap();
}

static __inline__ __device__ void brkpt(int c)
{
  __brkpt(c);
}

static __inline__ __device__ void syncthreads(void)
{
  __syncthreads();
}

static __inline__ __device__ void prof_trigger(int e)
{
       if (e ==  0) __prof_trigger( 0);
  else if (e ==  1) __prof_trigger( 1);
  else if (e ==  2) __prof_trigger( 2);
  else if (e ==  3) __prof_trigger( 3);
  else if (e ==  4) __prof_trigger( 4);
  else if (e ==  5) __prof_trigger( 5);
  else if (e ==  6) __prof_trigger( 6);
  else if (e ==  7) __prof_trigger( 7);
  else if (e ==  8) __prof_trigger( 8);
  else if (e ==  9) __prof_trigger( 9);
  else if (e == 10) __prof_trigger(10);
  else if (e == 11) __prof_trigger(11);
  else if (e == 12) __prof_trigger(12);
  else if (e == 13) __prof_trigger(13);
  else if (e == 14) __prof_trigger(14);
  else if (e == 15) __prof_trigger(15);
}

static __inline__ __device__ void threadfence(bool global = true)
{
  global ? __threadfence() : __threadfence_block();
}

static __inline__ __device__ int float2int(float a, enum cudaRoundMode mode = cudaRoundZero)
{
  return mode == cudaRoundNearest ? __float2int_rn(a) :
         mode == cudaRoundPosInf  ? __float2int_ru(a) :
         mode == cudaRoundMinInf  ? __float2int_rd(a) :
                                    __float2int_rz(a);
}

static __inline__ __device__ unsigned int float2uint(float a, enum cudaRoundMode mode = cudaRoundZero)
{
  return mode == cudaRoundNearest ? __float2uint_rn(a) :
         mode == cudaRoundPosInf  ? __float2uint_ru(a) :
         mode == cudaRoundMinInf  ? __float2uint_rd(a) :
                                    __float2uint_rz(a);
}

static __inline__ __device__ float int2float(int a, enum cudaRoundMode mode = cudaRoundNearest)
{
  return mode == cudaRoundZero   ? __int2float_rz(a) :
         mode == cudaRoundPosInf ? __int2float_ru(a) :
         mode == cudaRoundMinInf ? __int2float_rd(a) :
                                   __int2float_rn(a);
}

static __inline__ __device__ float uint2float(unsigned int a, enum cudaRoundMode mode = cudaRoundNearest)
{
  return mode == cudaRoundZero   ? __uint2float_rz(a) :
         mode == cudaRoundPosInf ? __uint2float_ru(a) :
         mode == cudaRoundMinInf ? __uint2float_rd(a) :
                                   __uint2float_rn(a);
}

#elif defined(__CUDABE__)

/*******************************************************************************
*                                                                              *
* DEVICE IMPLEMENTATIONS FOR FUNCTIONS WITH BUILTIN NVOPENCC OPERATIONS        *
*                                                                              *
*******************************************************************************/

static __forceinline__ float __sinf(float a)
{
  return __builtin_sinf(a);
}

static __forceinline__ float __cosf(float a)
{
  return __builtin_cosf(a);
}

static __forceinline__ float __log2f(float a)
{
  return __builtin_log2f(a);
}

/*******************************************************************************
*                                                                              *
* DEVICE IMPLEMENTATIONS FOR FUNCTIONS WITHOUT BUILTIN NVOPENCC OPERATIONS     *
*                                                                              *
*******************************************************************************/

static __forceinline__ float __tanf(float a)
{
  return __fdividef (__sinf(a), __cosf(a));
}

static __forceinline__ void __sincosf(float a, float *sptr, float *cptr)
{
  *sptr = __sinf(a);
  *cptr = __cosf(a);
}

static __forceinline__ float __expf(float a)
{
  return exp2f(a * CUDART_L2E_F);
}

static __forceinline__ float __exp10f(float a)
{
  return exp2f(a * CUDART_L2T_F);
}

static __forceinline__ float __log10f(float a)
{
  return CUDART_LG2_F * __log2f(a);
}

static __forceinline__ float __logf(float a)
{
  return CUDART_LN2_F * __log2f(a);
}

static __forceinline__ float __powf(float a, float b)
{
  return exp2f(b * __log2f(a));
}

static __forceinline__ float fdividef(float a, float b)
{
#if defined(__USE_FAST_MATH__) && !defined(__CUDA_PREC_DIV)
  return __fdividef(a, b);
#else /* __USE_FAST_MATH__ && !__CUDA_PREC_DIV */
  return a / b;
#endif /* __USE_FAST_MATH__ && !__CUDA_PREC_DIV */
}

#if defined(CUDA_FLOAT_MATH_FUNCTIONS)

static __forceinline__ double fdivide(double a, double b)
{
  return (double)fdividef((float)a, (float)b);
}

#endif /* CUDA_FLOAT_MATH_FUNCTIONS */

#if defined(CUDA_DOUBLE_MATH_FUNCTIONS)

static __forceinline__ double fdivide(double a, double b)
{
  return a / b;
}

#endif /* CUDA_DOUBLE_MATH_FUNCTIONS */

#if __CUDA_ARCH__ < 200

static __forceinline__ float __frcp_rn (float x)
{
  unsigned int expo;
  unsigned f, y;
  unsigned int argi;
  float t;
    
  argi = __float_as_int(x);
  expo = (argi >> 23);
  expo = expo & 0xff;
  f = expo - 1;
  if (f <= 0xFD) {
    y = (argi & 0x00ffffff) | 0x00800000;
    expo = (2 * 127) - expo - 2;
    t = 1.0f / x;
    argi = __float_as_int(t);
    argi = (argi & 0x00ffffff) | 0x00800000;
    if ((int)expo >= 0) {
      /* compute remainder1 */
      f = __umul24(y, argi);
      /* remainder1 must be negative. Fix if neccessary */
      if ((int)f > 0) { 
        t = __int_as_float(__float_as_int(t)-1);
        f -= y; 
      }
      /* compute remainder2 */
      expo = f + y;
      /* round result based on which remainder is smaller in magnitude */
      f = (unsigned)(-(int)f);
      if (expo < f) {
        t = __int_as_float(__float_as_int(t)+1);
      }
      return t;
    }
  }
  return 1.0f / x;
}
 
static __forceinline__ float __frcp_rz (float x)
{
  unsigned int expo;
  unsigned f, y;
  unsigned int argi;
  float t;
    
  argi = __float_as_int(x);
  expo = (argi >> 23);
  expo = expo & 0xff;
  f = expo - 1;
  if (f <= 0xFD) {
    y = (argi & 0x00ffffff) | 0x00800000;
    expo = (2 * 127) - expo - 2;
    t = 1.0f / x;
    argi = __float_as_int(t);
    argi = (argi & 0x00ffffff) | 0x00800000;
    if ((int)expo >= 0) {
      f = __umul24(y, argi);
      if ((int)f > 0) { 
        t = __int_as_float(__float_as_int(t)-1);
      }
      return t;
    }
  }
  return 1.0f / x;
}

static __forceinline__ float __frcp_rd (float x)
{
  unsigned int expo;
  unsigned f, y;
  unsigned int argi;
  float t;
    
  argi = __float_as_int(x);
  expo = (argi >> 23);
  expo = expo & 0xff;
  f = expo - 1;
  if (f <= 0xFD) {
    y = (argi & 0x00ffffff) | 0x00800000;
    expo = (2 * 127) - expo - 2;
    t = 1.0f / x;
    argi = __float_as_int(t);
    argi = (argi & 0x00ffffff) | 0x00800000;
    if ((int)expo >= 0) {
      f = __umul24(y, argi);
      if (((int)f > 0) && (x > 0.0f)) { 
        t = __int_as_float(__float_as_int(t)-1);
      }
      if (((int)f < 0) && (x < 0.0f)) { 
        t = __int_as_float(__float_as_int(t)+1);
      }
      return t;
    }
  }
  return 1.0f / x;
}

static __forceinline__ float __frcp_ru (float x)
{
  unsigned int expo;
  unsigned f, y;
  unsigned int argi;
  float t;
    
  argi = __float_as_int(x);
  expo = (argi >> 23);
  expo = expo & 0xff;
  f = expo - 1;
  if (f <= 0xFD) {
    y = (argi & 0x00ffffff) | 0x00800000;
    expo = (2 * 127) - expo - 2;
    t = 1.0f / x;
    argi = __float_as_int(t);
    argi = (argi & 0x00ffffff) | 0x00800000;
    if ((int)expo >= 0) {
      f = __umul24(y, argi);
      if (((int)f > 0) && (x < 0.0f)) { 
        t = __int_as_float(__float_as_int(t)-1);
      }
      if (((int)f < 0) && (x > 0.0f)) { 
        t = __int_as_float(__float_as_int(t)+1);
      }
      return t;
    }
  }
  return 1.0f / x;
}

static __forceinline__ float __fsqrt_rn (float radicand)
{
  unsigned int expo, argi;
  unsigned int s, f, x;

  argi = __float_as_int(radicand);
  expo = argi >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((argi <= 0x80000000) && (f <= 0xFD)) {
    x = (argi << 8) | 0x80000000;
    x = x >> (expo & 1);
    argi = (((__float_as_int(rsqrtf(__int_as_float(
              __float_as_int(radicand)|1)))&0x00ffffff)|0x00800000)<<7);
    /* second NR iteration */
    s = __umulhi(argi,argi);
    f = 0x30000000 - __umulhi(x,s);
    argi = __umulhi(f,argi);
    /* compute sqrt_rn(x) as x * 1/sqrt_rn(x) */
    argi = __umulhi(x,argi);
    argi = argi >> 3;
    x = (x << 16) - (argi * argi);
    /* round to nearest based on remainder; tie case impossible */
    f = x - (2 * argi + 1);
    if ((int)f < 0) f = (unsigned)(-(int)f);
    if ((int)x < 0) x = (unsigned)(-(int)x);
    if (f < x) argi ++;
    argi = argi + (((expo + 125) & ~0x1) << 22);
    return __int_as_float(argi);
  }
  return sqrtf(radicand);
}

static __forceinline__ float __fsqrt_rz (float radicand)
{
  unsigned int expo, argi;
  unsigned int s, f, x;

  argi = __float_as_int(radicand);
  expo = argi >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((argi <= 0x80000000) && (f <= 0xFD)) {
    x = (argi << 8) | 0x80000000;
    x = x >> (expo & 1);
    argi = (((__float_as_int(rsqrtf(__int_as_float(
              __float_as_int(radicand)|1)))&0x00ffffff)|0x00800000)<<7);
    /* NR iteration */
    s = __umulhi(argi,argi);
    f = 0x30000000 - __umulhi(x,s);
    argi = __umulhi(f,argi);
    /* compute sqrt_rz(x) as x * 1/sqrt_rz(x) */
    argi = __umulhi(x,argi);
    /* compute truncated result */
    argi = (argi + 4) >> 3;
    x = (x << 16) - (argi * argi);
    if ((int)x < 0) argi--;
    argi = argi + (((expo + 125) & ~0x1) << 22);
    return __int_as_float(argi);
  }
  return sqrtf(radicand);
}

static __forceinline__ float __fsqrt_ru (float radicand)
{
  unsigned int expo, argi;
  unsigned int s, f, x;

  argi = __float_as_int(radicand);
  expo = argi >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((argi <= 0x80000000) && (f <= 0xFD)) {
    x = (argi << 8) | 0x80000000;
    x = x >> (expo & 1);
    argi = (((__float_as_int(rsqrtf(__int_as_float(
              __float_as_int(radicand)|1)))&0x00ffffff)|0x00800000)<<7);
    /* NR iteration */
    s = __umulhi(argi,argi);
    f = 0x30000000 - __umulhi(x,s);
    argi = __umulhi(f,argi);
    /* compute sqrt_ru(x) as x * 1/sqrt_ru(x) */
    argi = __umulhi(x,argi);
    argi = (argi + 4) >> 3;
    x = (x << 16) - (argi * argi);
    if ((int)x > 0) argi++;
    argi = argi + (((expo + 125) & ~0x1) << 22);
    return __int_as_float(argi);
  }
  return sqrtf(radicand);
}

static __forceinline__ float __fsqrt_rd (float radicand)
{
  unsigned int expo, argi;
  unsigned int s, f, x;

  argi = __float_as_int(radicand);
  expo = argi >> 23;
  expo = expo & 0xff;
  f = expo - 1;

  if ((argi <= 0x80000000) && (f <= 0xFD)) {
    x = (argi << 8) | 0x80000000;
    x = x >> (expo & 1);
    argi = (((__float_as_int(rsqrtf(__int_as_float(
              __float_as_int(radicand)|1)))&0x00ffffff)|0x00800000)<<7);
    /* NR iteration */
    s = __umulhi(argi,argi);
    f = 0x30000000 - __umulhi(x,s);
    argi = __umulhi(f,argi);
    /* compute sqrt_rd(x) as x * 1/sqrt_rd(x) */
    argi = __umulhi(x,argi);
    /* compute truncated result */
    argi = (argi + 4) >> 3;
    x = (x << 16) - (argi * argi);
    if ((int)x < 0) argi--;
    argi = argi + (((expo + 125) & ~0x1) << 22);
    return __int_as_float(argi);
  }
  return sqrtf(radicand);
}

static __forceinline__ float __fdiv_rn (float dividend, float divisor)
{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  unsigned expo_res;
  unsigned resi, cvtxi, cvtyi;
  float t;

  cvtxi = __float_as_int(dividend);
  cvtyi = __float_as_int(divisor);
  expox = (cvtxi >> 23) & 0xff;
  expoy = (cvtyi >> 23) & 0xff;
  sign  = ((cvtxi ^ cvtyi) & 0x80000000);

  if (((expox - 1) <= 0xFD) && ((expoy - 1) <= 0xFD)) {
    expo_res = expox - expoy + 127 - 1;
    /* extract mantissas */
    y = (cvtyi << 8) | 0x80000000;
    x = (cvtxi & 0x00ffffff) | 0x00800000;
    t =__int_as_float((cvtyi & 0x00ffffff) | 0x3f800001);
    r = ((__float_as_int(1.0f / t) & 0x00ffffff) | 0x00800000) << 7;
    /* NR iteration */  
    f = (unsigned)-(int)__umulhi (y, r << 1);
    r = __umulhi (f, r << 1);
    /* produce quotient */
    prod = ((unsigned long long)x) * (r << 1);
    /* normalize mantissa */
    if (((int)((prod >> 32) << 8)) > 0) {
      expo_res--;
      prod = prod + prod;
    }
    /* preliminary mantissa */
    r = (unsigned)(prod >> 32);
    y = y >> 8;
    /* result is a normal */
    if (expo_res <= 0xFD) {
      int rem0, rem1, inc;
      /* round mantissa to nearest even */
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      rem0 = rem1 - y;
      inc = abs(rem0) < abs(rem1);
      /* merge sign, mantissa, exponent for final result */
      resi = sign | ((expo_res << 23) + r + inc);
      return __int_as_float(resi);
    } else if ((int)expo_res >= 254) {
      /* overflow: return infinity */
      resi = sign | 0x7f800000;
      return __int_as_float(resi);
    } else {
      /* underflow, may still round to normal */
      int rem0, rem1, inc;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      rem0 = rem1 - y;
      inc = abs(rem0) < abs(rem1);
      resi = ((expo_res << 23) + r + inc);
      if (resi != 0x00800000) resi = 0;
      return __int_as_float(sign | resi);
    }
  }
  if (fabsf(divisor) > CUDART_TWO_TO_126_F) {
    divisor  *= 0.25f;
    dividend *= 0.25f;
  }
  return __fdividef (dividend, divisor);
}

static __forceinline__ float __fdiv_rz (float dividend, float divisor)
{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  unsigned expo_res;
  unsigned resi, cvtxi, cvtyi;
  float t;

  cvtxi = __float_as_int(dividend);
  cvtyi = __float_as_int(divisor);
  expox = (cvtxi >> 23) & 0xff;
  expoy = (cvtyi >> 23) & 0xff;
  sign  = ((cvtxi ^ cvtyi) & 0x80000000);

  if (((expox - 1) <= 0xFD) && ((expoy - 1) <= 0xFD)) {
    expo_res = expox - expoy + 127 - 1;
    /* extract mantissas */
    y = (cvtyi << 8) | 0x80000000;
    x = (cvtxi & 0x00ffffff) | 0x00800000;
    t =__int_as_float((cvtyi & 0x00ffffff) | 0x3f800001);
    r = ((__float_as_int(1.0f / t) & 0x00ffffff) | 0x00800000) << 7;
    /* NR iteration */  
    f = (unsigned)-(int)__umulhi (y, r << 1);
    r = __umulhi (f, r << 1);
    /* produce quotient */
    prod = ((unsigned long long)x) * (r << 1);
    /* normalize mantissa */
    if (((int)((prod >> 32) << 8)) > 0) {
      expo_res--;
      prod = prod + prod;
    }
    /* preliminary mantissa */
    prod += 0x0000000080000000ULL;
    r = (unsigned)(prod >> 32);
    y = y >> 8;
    if (expo_res <= 0xFD) {
      /* result is a normal */
      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if (rem1 < 0) r--;
      resi = (expo_res << 23) + r;
      if (resi == 0x7f800000) resi = 0x7f7fffff;
      return __int_as_float(sign | resi);
    } else if ((int)expo_res >= 254) {
      /* overflow: return largest normal */
      resi = 0x7f7fffff;
      return __int_as_float(sign |resi);
    } else {
      /* underflow: result is smallest normal or zero */
      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if (rem1 < 0) r--;
      resi = ((expo_res << 23) + r);
      if (resi != 0x00800000) resi = 0;
      return __int_as_float(sign | resi);
    }
  }
  if (fabsf(divisor) > CUDART_TWO_TO_126_F) {
    divisor  *= 0.25f;
    dividend *= 0.25f;
  }
  return __fdividef (dividend, divisor);
}

static __forceinline__ float __fdiv_ru (float dividend, float divisor)
{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  unsigned expo_res;
  unsigned resi, cvtxi, cvtyi;
  float t;

  cvtxi = __float_as_int(dividend);
  cvtyi = __float_as_int(divisor);
  expox = (cvtxi >> 23) & 0xff;
  expoy = (cvtyi >> 23) & 0xff;
  sign  = ((cvtxi ^ cvtyi) & 0x80000000);

  if (((expox - 1) <= 0xFD) && ((expoy - 1) <= 0xFD)) {
    expo_res = expox - expoy + 127 - 1;
    /* extract mantissas */
    y = (cvtyi << 8) | 0x80000000;
    x = (cvtxi & 0x00ffffff) | 0x00800000;
    t =__int_as_float((cvtyi & 0x00ffffff) | 0x3f800001);
    r = ((__float_as_int(1.0f / t) & 0x00ffffff) | 0x00800000) << 7;
    /* NR iteration */  
    f = (unsigned)-(int)__umulhi (y, r << 1);
    r = __umulhi (f, r << 1);
    /* produce quotient */
    prod = ((unsigned long long)x) * (r << 1);
    /* normalize mantissa */
    if (((int)((prod >> 32) << 8)) > 0) {
      expo_res--;
      prod = prod + prod;
    }
    /* preliminary mantissa */
    prod += 0x0000000080000000ULL;
    r = (unsigned)(prod >> 32);
    y = y >> 8;
    if (expo_res <= 0xFD) {
      /* result is a normal */
      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if ((rem1 < 0) &&  (sign)) r--;
      if ((rem1 > 0) && (!sign)) r++;
      resi = (expo_res << 23) + r;
      if ((resi == 0x7f800000) && (sign)) resi = 0x7f7fffff;
      return __int_as_float(sign | resi);
    } else if ((int)expo_res >= 254) {
      /* overflow: return largest normal */
      resi = sign ? 0x7f7fffff : 0x7f800000;
      return __int_as_float(sign | resi);
    } else {
      /* underflow: result is smallest normal or zero */
      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if ((rem1 < 0) &&  (sign)) r--;
      if ((rem1 > 0) && (!sign)) r++;
      resi = ((expo_res << 23) + r);
      if (resi != 0x00800000) resi = 0;
      return __int_as_float(sign | resi);
    }
  }
  if (fabsf(divisor) > CUDART_TWO_TO_126_F) {
    divisor  *= 0.25f;
    dividend *= 0.25f;
  }
  return __fdividef (dividend, divisor);
}

static __forceinline__ float __fdiv_rd (float dividend, float divisor)
{
  unsigned long long prod;
  unsigned r, f, x, y, expox, expoy, sign;
  unsigned expo_res;
  unsigned resi, cvtxi, cvtyi;
  float t;

  cvtxi = __float_as_int(dividend);
  cvtyi = __float_as_int(divisor);
  expox = (cvtxi >> 23) & 0xff;
  expoy = (cvtyi >> 23) & 0xff;
  sign  = ((cvtxi ^ cvtyi) & 0x80000000);

  if (((expox - 1) <= 0xFD) && ((expoy - 1) <= 0xFD)) {
    expo_res = expox - expoy + 127 - 1;
    /* extract mantissas */
    y = (cvtyi << 8) | 0x80000000;
    x = (cvtxi & 0x00ffffff) | 0x00800000;
    t =__int_as_float((cvtyi & 0x00ffffff) | 0x3f800001);
    r = ((__float_as_int(1.0f / t) & 0x00ffffff) | 0x00800000) << 7;
    /* NR iteration */  
    f = (unsigned)-(int)__umulhi (y, r << 1);
    r = __umulhi (f, r << 1);
    /* produce quotient */
    prod = ((unsigned long long)x) * (r << 1);
    /* normalize mantissa */
    if (((int)((prod >> 32) << 8)) > 0) {
      expo_res--;
      prod = prod + prod;
    }
    /* preliminary mantissa */
    prod += 0x0000000080000000ULL;
    r = (unsigned)(prod >> 32);
    y = y >> 8;
    if (expo_res <= 0xFD) {
      /* result is a normal */
      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if ((rem1 < 0) && (!sign)) r--;
      if ((rem1 > 0) &&  (sign)) r++;
      resi = (expo_res << 23) + r;
      if ((resi == 0x7f800000) && (!sign)) resi = 0x7f7fffff;
      return __int_as_float(sign | resi);
    } else if ((int)expo_res >= 254) {
      /* overflow: return largest normal */
      resi = sign ? 0x7f800000 : 0x7f7fffff;
      return __int_as_float(sign |resi);
    } else {
      /* underflow: result is smallest normal or zero */
      int rem1;
      prod = ((unsigned long long)y) * r;
      x = x << (23 + ((prod >> 32) >> 15));
      rem1 = x - (unsigned)(prod & 0xffffffff);
      if ((rem1 < 0) && (!sign)) r--;
      if ((rem1 > 0) &&  (sign)) r++;
      resi = ((expo_res << 23) + r);
      if (resi != 0x00800000) resi = 0;
      return __int_as_float(sign | resi);
    }
  }
  if (fabsf(divisor) > CUDART_TWO_TO_126_F) {
    divisor  *= 0.25f;
    dividend *= 0.25f;
  }
  return __fdividef (dividend, divisor);
}

static __forceinline__ float __fadd_ru (float a, float b)
{
  unsigned int expo_x, expo_y;
  unsigned int xxi, yyi, temp;
    
  xxi = __float_as_int(a);
  yyi = __float_as_int(b);

  /* make bigger operand the augend */
  expo_y = yyi << 1;
  if (expo_y > (xxi << 1)) {
    expo_y = xxi;
    xxi    = yyi;
    yyi    = expo_y;
  }
    
  temp = 0xff;
  expo_x = temp & (xxi >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yyi >> 23);
  expo_y = expo_y - 1;
    
  if ((expo_x <= 0xFD) && 
      (expo_y <= 0xFD)) {
        
    expo_y = expo_x - expo_y;
    if (expo_y > 25) {
      expo_y = 31;
    }
    temp = xxi ^ yyi;
    xxi = xxi & ~0x7f000000;
    xxi = xxi |  0x00800000;
    yyi = yyi & ~0xff000000;
    yyi = yyi |  0x00800000;
        
    if ((int)temp < 0) {
      /* signs differ, effective subtraction */
      temp = 32 - expo_y;
      temp = (expo_y) ? (yyi << temp) : 0;
      temp = (unsigned int)(-((int)temp));
      xxi = xxi - (yyi >> expo_y) - (temp ? 1 : 0);
      if (xxi & 0x00800000) {
        if (expo_x <= 0xFD) {
          xxi = (xxi + (expo_x << 23));
          xxi += (temp && !(xxi & 0x80000000));
          return __int_as_float(xxi);
        }
      } else {
        if ((temp | (xxi << 1)) == 0) {
          /* operands cancelled, resulting in a clean zero */
          xxi = 0;
          return __int_as_float(xxi);
        }
        /* normalize result */
        yyi = xxi & 0x80000000;
        do {
          xxi = (xxi << 1) | (temp >> 31);
          temp <<= 1;
          expo_x--;
        } while (!(xxi & 0x00800000));
        xxi = xxi | yyi;
      }
    } else {
      /* signs are the same, effective addition */
      temp = 32 - expo_y;
      temp = (expo_y) ? (yyi << temp) : 0;
      xxi = xxi + (yyi >> expo_y);
      if (!(xxi & 0x01000000)) {
        if (expo_x <= 0xFD) {
          xxi = xxi + (expo_x << 23);
          xxi += (temp && !(xxi & 0x80000000));
          return __int_as_float(xxi);
        }
      } else {
        /* normalize result */
        temp = (xxi << 31) | (temp >> 1);
        xxi = ((xxi & 0x80000000) | (xxi >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
    if (expo_x <= 0xFD) {
      xxi += (temp && !(xxi & 0x80000000));
      xxi = xxi + (expo_x << 23);
      return __int_as_float(xxi);
    }
    if ((int)expo_x >= 254) {
      /* overflow: return infinity or largest normal */
      temp = xxi & 0x80000000;
      xxi = (temp ? 0xff7fffff : 0x7F800000);
      return __int_as_float(xxi);
    }
    /* underflow: zero or smallest normal */
    yyi = xxi &  0x80000000;
    xxi = xxi & ~0xff000000;
    expo_x = (unsigned int)(-((int)expo_x));
    xxi = (xxi >> expo_x);
    if ((expo_x > 25) || (xxi != 0x00800000)) xxi = 0;
    return __int_as_float(yyi | xxi);
  } else {
    return a + b;
  }
}

static __forceinline__ float __fadd_rd (float a, float b)
{
  unsigned int expo_x, expo_y;
  unsigned int xxi, yyi, temp;
    
  xxi = __float_as_int(a);
  yyi = __float_as_int(b);

  /* make bigger operand the augend */
  expo_y = yyi << 1;
  if (expo_y > (xxi << 1)) {
    expo_y = xxi;
    xxi    = yyi;
    yyi    = expo_y;
  }
    
  temp = 0xff;
  expo_x = temp & (xxi >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yyi >> 23);
  expo_y = expo_y - 1;
    
  if ((expo_x <= 0xFD) && 
      (expo_y <= 0xFD)) {
        
    expo_y = expo_x - expo_y;
    if (expo_y > 25) {
      expo_y = 31;
    }
    temp = xxi ^ yyi;
    xxi = xxi & ~0x7f000000;
    xxi = xxi |  0x00800000;
    yyi = yyi & ~0xff000000;
    yyi = yyi |  0x00800000;
        
    if ((int)temp < 0) {
      /* signs differ, effective subtraction */
      temp = 32 - expo_y;
      temp = (expo_y) ? (yyi << temp) : 0;
      temp = (unsigned int)(-((int)temp));
      xxi = xxi - (yyi >> expo_y) - (temp ? 1 : 0);
      if (xxi & 0x00800000) {
        if (expo_x <= 0xFD) {
          xxi = xxi & ~0x00800000; /* lop off integer bit */
          xxi = (xxi + (expo_x << 23)) + 0x00800000;
          xxi += (temp && (xxi & 0x80000000));
          return __int_as_float(xxi);
        }
      } else {
        if ((temp | (xxi << 1)) == 0) {
          /* operands cancelled, resulting in a clean zero */
          xxi = 0x80000000;
          return __int_as_float(xxi);
        }
        /* normalize result */
        yyi = xxi & 0x80000000;
        do {
          xxi = (xxi << 1) | (temp >> 31);
          temp <<= 1;
          expo_x--;
        } while (!(xxi & 0x00800000));
        xxi = xxi | yyi;
      }
    } else {
      /* signs are the same, effective addition */
      temp = 32 - expo_y;
      temp = (expo_y) ? (yyi << temp) : 0;
      xxi = xxi + (yyi >> expo_y);
      if (!(xxi & 0x01000000)) {
        if (expo_x <= 0xFD) {
          expo_y = xxi & 1;
          xxi = xxi + (expo_x << 23);
          xxi += (temp && (xxi & 0x80000000));
          return __int_as_float(xxi);
        }
      } else {
        /* normalize result */
        temp = (xxi << 31) | (temp >> 1);
        xxi = ((xxi & 0x80000000) | (xxi >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
    if (expo_x <= 0xFD) {
      xxi += (temp && (xxi & 0x80000000));
      xxi = xxi + (expo_x << 23);
      return __int_as_float(xxi);
    }
    if ((int)expo_x >= 254) {
      /* overflow: return infinity or largest normal */
      temp = xxi & 0x80000000;
      xxi = (temp ? 0xFF800000 : 0x7f7fffff);
      return __int_as_float(xxi);
    }
    /* underflow: zero or smallest normal */
    yyi = xxi &  0x80000000;
    xxi = xxi & ~0xff000000;
    expo_x = (unsigned int)(-((int)expo_x));
    xxi = (xxi >> expo_x);
    if ((expo_x > 25) || (xxi != 0x00800000)) xxi = 0;
    return __int_as_float(yyi | xxi);
  } else {
    a = a + b;
    xxi = xxi ^ yyi;
    if ((a == 0.0f) && ((int)xxi < 0)) a = __int_as_float(0x80000000);
    return a;
  }
}

static __forceinline__ float __fmul_ru (float a, float b)
{
  unsigned long long product;
  unsigned int expo_x, expo_y;
  unsigned int xxi, yyi;
    
  xxi = __float_as_int(a);
  yyi = __float_as_int(b);

  expo_y = 0xFF;
  expo_x = expo_y & (xxi >> 23);
  expo_x = expo_x - 1;
  expo_y = expo_y & (yyi >> 23);
  expo_y = expo_y - 1;
    
  if ((expo_x <= 0xFD) && 
      (expo_y <= 0xFD)) {
    expo_x = expo_x + expo_y;
    expo_y = xxi ^ yyi;
    xxi = xxi & 0x00ffffff;
    yyi = yyi << 8;
    xxi = xxi | 0x00800000;
    yyi = yyi | 0x80000000;
    /* compute product */
    product = ((unsigned long long)xxi) * yyi;
    expo_x = expo_x - 127 + 2;
    expo_y = expo_y & 0x80000000;
    xxi = (unsigned int)(product >> 32);
    yyi = (unsigned int)(product & 0xffffffff);
    /* normalize mantissa */
    if (xxi < 0x00800000) {
      xxi = (xxi << 1) | (yyi >> 31);
      yyi = (yyi << 1);
      expo_x--;
    }
    if (expo_x <= 0xFD) {
      xxi = xxi | expo_y;          /* OR in sign bit */
      xxi = xxi + (expo_x << 23);  /* add in exponent */
      /* round result */
      xxi += (yyi && !expo_y);
      return __int_as_float(xxi);
    } else if ((int)expo_x >= 254) {
      /* overflow: return infinity or largest normal */
      xxi = (expo_y ? 0xff7fffff : 0x7F800000);
      return __int_as_float(xxi);
    } else {
      /* underflow: zero, or smallest normal */
      expo_x = ((unsigned int)-((int)expo_x));
      xxi += (yyi && !expo_y);
      xxi = (xxi >> expo_x);
      if ((expo_x > 25) || (xxi != 0x00800000)) xxi = 0;
      return __int_as_float(expo_y | xxi);
    }
  } else {
    return a * b;
  }
}

static __forceinline__ float __fmul_rd (float a, float b)
{
  unsigned long long product;
  unsigned int expo_x, expo_y;
  unsigned int xxi, yyi;
    
  xxi = __float_as_int(a);
  yyi = __float_as_int(b);

  expo_y = 0xFF;
  expo_x = expo_y & (xxi >> 23);
  expo_x = expo_x - 1;
  expo_y = expo_y & (yyi >> 23);
  expo_y = expo_y - 1;
    
  if ((expo_x <= 0xFD) && 
      (expo_y <= 0xFD)) {
    expo_x = expo_x + expo_y;
    expo_y = xxi ^ yyi;
    xxi = xxi & 0x00ffffff;
    yyi = yyi << 8;
    xxi = xxi | 0x00800000;
    yyi = yyi | 0x80000000;
    /* compute product */
    product = ((unsigned long long)xxi) * yyi;
    expo_x = expo_x - 127 + 2;
    expo_y = expo_y & 0x80000000;
    xxi = (unsigned int)(product >> 32);
    yyi = (unsigned int)(product & 0xffffffff);
    /* normalize mantissa */
    if (xxi < 0x00800000) {
      xxi = (xxi << 1) | (yyi >> 31);
      yyi = (yyi << 1);
      expo_x--;
    }
    if (expo_x <= 0xFD) {
      xxi = xxi | expo_y;          /* OR in sign bit */
      xxi = xxi + (expo_x << 23);  /* add in exponent */
      /* round result */
      xxi += (yyi && expo_y);
      return __int_as_float(xxi);
    } else if ((int)expo_x >= 254) {
      /* overflow: return infinity or largest normal */
      xxi = expo_y | (expo_y ?0x7F800000 : 0x7f7fffff);
      return __int_as_float(xxi);
    } else {
      /* underflow: zero, or smallest normal */
      expo_x = ((unsigned int)-((int)expo_x));
      xxi += (yyi && expo_y);
      xxi = (xxi >> expo_x);
      if ((expo_x > 25) || (xxi != 0x00800000)) xxi = 0;
      return __int_as_float(expo_y | xxi);
    }
  } else {
    return a * b;
  }
}

static __forceinline__ float __fmaf_rn (float a, float b, float c)
{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;

  xx = __float_as_int(a);
  yy = __float_as_int(b);
  zz = __float_as_int(c);

  /* Match 'denormals are zero' behavior of the GPU */
  if ((xx << 1) < 0x01000000) xx &= 0x80000000;
  if ((yy << 1) < 0x01000000) yy &= 0x80000000;
  if ((zz << 1) < 0x01000000) zz &= 0x80000000;
   
  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) && 
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {
    /* fmad (nan, y, z) --> nan
       fmad (x, nan, z) --> nan
       fmad (x, y, nan) --> nan 
    */
    if ((yy << 1) > 0xff000000) {
      return rsqrtf(b);
    }
    if ((zz << 1) > 0xff000000) {
      return rsqrtf(c);
    }
    if ((xx << 1) > 0xff000000) {
      return rsqrtf(a);
    }
    /* fmad (0, inf, z) --> NaN
       fmad (inf, 0, z) --> NaN
       fmad (-inf,+y,+inf) --> NaN
       fmad (+x,-inf,+inf) --> NaN
       fmad (+inf,-y,+inf) --> NaN
       fmad (-x,+inf,+inf) --> NaN
       fmad (-inf,-y,-inf) --> NaN
       fmad (-x,-inf,-inf) --> NaN
       fmad (+inf,+y,-inf) --> NaN
       fmad (+x,+inf,-inf) --> NaN
    */
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      return rsqrtf(__int_as_float(0xffc00000));
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          return rsqrtf(__int_as_float(0xffc00000));
        }
      }
    }
    /* fmad (inf, y, z) --> inf
       fmad (x, inf, z) --> inf
       fmad (x, y, inf) --> inf
    */
    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      return __int_as_float(xx);
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      return __int_as_float(yy);
    }
    if ((zz << 1) == 0xff000000) {
      return __int_as_float(zz);
    }
    /* fmad (+0, -y, -0) --> -0
       fmad (-0, +y, -0) --> -0
       fmad (+x, -0, -0) --> -0
       fmad (-x, +0, -0) --> -0
    */
    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          return __int_as_float(zz);
        }
      }
    }
    /* fmad (0, y, 0) --> +0
       fmad (x, 0, 0) --> +0
    */
    if (((zz << 1) == 0) && 
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      zz &= 0x7fffffff;
      return __int_as_float(zz);
    }
    /* fmad (0, y, z) --> z
       fmad (x, 0, z) --> z
     */
    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      return __int_as_float(zz);
    }
    /* normalize x, if denormal */
    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }
    /* normalize y, if denormal */
    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }
    /* normalize z, if denormal */
    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }
    
  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;
  /* normalize mantissa */
  if (xx < 0x00800000) {
    xx = (xx << 1) | (yy >> 31);
    yy = (yy << 1);
    expo_x--;
  }
  temp = 0;

  if ((zz << 1) != 0) { /* z is not zero */
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;
    /* compare and swap. put augend into xx:yy */
    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }
    /* augend_sign = expo_y, augend_mant = xx:yy, augend_expo = expo_x */
    /* addend_sign = s, addend_mant = zz:ww, addend_expo = expo_z */
    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {
      /* denormalize addend */
      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) | 
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }
      
    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }            
    if ((int)u < 0) {
      /* signs differ, effective subtraction */
      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {
        /* complete cancelation, return 0 */
        return __int_as_float(xx);
      }
      if ((int)xx < 0) {
        /* ooops, augend had smaller mantissa. Negate mantissa and flip
           sign of result*/
        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }
      /* normalize mantissa, if necessary */
      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {
      /* signs are the same, effective addition */
      yy = yy + ww;
      s =  yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {
    /* normal */
    xx |= expo_y; /* or in sign bit */
    s = xx & 1; /* mantissa lsb */
    xx += (temp == 0x80000000) ? s : (temp >> 31);
    xx = xx + (expo_x << 23); /* add in exponent */
    return __int_as_float(xx);
  } else if ((int)expo_x >= 126) {
    /* overflow */
    xx = expo_y | 0x7f800000;
    return __int_as_float(xx);
  }
  /* subnormal */
  expo_x = (unsigned int)(-(int)expo_x);
  /* Match 'flush to zero' response of the GPU */
  xx += (temp >= 0x80000000);
  if (xx >= 0x01000000) {
    xx = xx >> 1;
    expo_x--;
  }
  if (expo_x > 0) xx = 0;
  xx = expo_y | xx;
  return __int_as_float(xx);
}

static __forceinline__ float __fmaf_rz (float a, float b, float c)
{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;

  xx = __float_as_int(a);
  yy = __float_as_int(b);
  zz = __float_as_int(c);

  /* Match 'denormals are zero' behavior of the GPU */
  if ((xx << 1) < 0x01000000) xx &= 0x80000000;
  if ((yy << 1) < 0x01000000) yy &= 0x80000000;
  if ((zz << 1) < 0x01000000) zz &= 0x80000000;
   
  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) && 
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {
    /* fmad (nan, y, z) --> nan
       fmad (x, nan, z) --> nan
       fmad (x, y, nan) --> nan 
    */
    if ((yy << 1) > 0xff000000) {
      return rsqrtf(b);
    }
    if ((zz << 1) > 0xff000000) {
      return rsqrtf(c);
    }
    if ((xx << 1) > 0xff000000) {
      return rsqrtf(a);
    }
    /* fmad (0, inf, z) --> NaN
       fmad (inf, 0, z) --> NaN
       fmad (-inf,+y,+inf) --> NaN
       fmad (+x,-inf,+inf) --> NaN
       fmad (+inf,-y,+inf) --> NaN
       fmad (-x,+inf,+inf) --> NaN
       fmad (-inf,-y,-inf) --> NaN
       fmad (-x,-inf,-inf) --> NaN
       fmad (+inf,+y,-inf) --> NaN
       fmad (+x,+inf,-inf) --> NaN
    */
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      return rsqrtf(__int_as_float(0xffc00000));
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          return rsqrtf(__int_as_float(0xffc00000));
        }
      }
    }
    /* fmad (inf, y, z) --> inf
       fmad (x, inf, z) --> inf
       fmad (x, y, inf) --> inf
    */
    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      return __int_as_float(xx);
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      return __int_as_float(yy);
    }
    if ((zz << 1) == 0xff000000) {
      return __int_as_float(zz);
    }
    /* fmad (+0, -y, -0) --> -0
       fmad (-0, +y, -0) --> -0
       fmad (+x, -0, -0) --> -0
       fmad (-x, +0, -0) --> -0
    */
    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          return __int_as_float(zz);
        }
      }
    }
    /* fmad (0, y, 0) --> +0
       fmad (x, 0, 0) --> +0
    */
    if (((zz << 1) == 0) && 
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      zz &= 0x7fffffff;
      return __int_as_float(zz);
    }
    /* fmad (0, y, z) --> z
       fmad (x, 0, z) --> z
     */
    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      return __int_as_float(zz);
    }
    /* normalize x, if denormal */
    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }
    /* normalize y, if denormal */
    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }
    /* normalize z, if denormal */
    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }
    
  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;
  /* normalize mantissa */
  if (xx < 0x00800000) {
    xx = (xx << 1) | (yy >> 31);
    yy = (yy << 1);
    expo_x--;
  }
  temp = 0;

  if ((zz << 1) != 0) { /* z is not zero */
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;
    /* compare and swap. put augend into xx:yy */
    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }
    /* augend_sign = expo_y, augend_mant = xx:yy, augend_expo = expo_x */
    /* addend_sign = s, addend_mant = zz:ww, addend_expo = expo_z */
    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {
      /* denormalize addend */
      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) | 
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }
      
    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }            
    if ((int)u < 0) {
      /* signs differ, effective subtraction */
      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {
        /* complete cancelation, return 0 */
        return __int_as_float(xx);
      }
      if ((int)xx < 0) {
        /* ooops, augend had smaller mantissa. Negate mantissa and flip
           sign of result*/
        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }
      /* normalize mantissa, if necessary */
      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {
      /* signs are the same, effective addition */
      yy = yy + ww;
      s =  yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {
    /* normal */
    xx |= expo_y; /* or in sign bit */
    xx = xx + (expo_x << 23); /* add in exponent */
    return __int_as_float(xx);
  } else if ((int)expo_x >= 126) {
    /* overflow */
    xx = expo_y | 0x7f7fffff;
    return __int_as_float(xx);
  }
  /* subnormal */
  return __int_as_float(expo_y);
}

static __forceinline__ float __fmaf_ru (float a, float b, float c)
{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;

  xx = __float_as_int(a);
  yy = __float_as_int(b);
  zz = __float_as_int(c);

  /* Match 'denormals are zero' behavior of the GPU */
  if ((xx << 1) < 0x01000000) xx &= 0x80000000;
  if ((yy << 1) < 0x01000000) yy &= 0x80000000;
  if ((zz << 1) < 0x01000000) zz &= 0x80000000;
   
  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) && 
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {
    /* fmad (nan, y, z) --> nan
       fmad (x, nan, z) --> nan
       fmad (x, y, nan) --> nan 
    */
    if ((yy << 1) > 0xff000000) {
      return rsqrtf(b);
    }
    if ((zz << 1) > 0xff000000) {
      return rsqrtf(c);
    }
    if ((xx << 1) > 0xff000000) {
      return rsqrtf(a);
    }
    /* fmad (0, inf, z) --> NaN
       fmad (inf, 0, z) --> NaN
       fmad (-inf,+y,+inf) --> NaN
       fmad (+x,-inf,+inf) --> NaN
       fmad (+inf,-y,+inf) --> NaN
       fmad (-x,+inf,+inf) --> NaN
       fmad (-inf,-y,-inf) --> NaN
       fmad (-x,-inf,-inf) --> NaN
       fmad (+inf,+y,-inf) --> NaN
       fmad (+x,+inf,-inf) --> NaN
    */
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      return rsqrtf(__int_as_float(0xffc00000));
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          return rsqrtf(__int_as_float(0xffc00000));
        }
      }
    }
    /* fmad (inf, y, z) --> inf
       fmad (x, inf, z) --> inf
       fmad (x, y, inf) --> inf
    */
    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      return __int_as_float(xx);
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      return __int_as_float(yy);
    }
    if ((zz << 1) == 0xff000000) {
      return __int_as_float(zz);
    }
    /* fmad (+0, -y, -0) --> -0
       fmad (-0, +y, -0) --> -0
       fmad (+x, -0, -0) --> -0
       fmad (-x, +0, -0) --> -0
    */
    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          return __int_as_float(zz);
        }
      }
    }
    /* fmad (0, y, 0) --> +0
       fmad (x, 0, 0) --> +0
    */
    if (((zz << 1) == 0) && 
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      zz &= 0x7fffffff;
      return __int_as_float(zz);
    }
    /* fmad (0, y, z) --> z
       fmad (x, 0, z) --> z
     */
    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      return __int_as_float(zz);
    }
    /* normalize x, if denormal */
    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }
    /* normalize y, if denormal */
    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }
    /* normalize z, if denormal */
    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }
    
  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;
  /* normalize mantissa */
  if (xx < 0x00800000) {
    xx = (xx << 1) | (yy >> 31);
    yy = (yy << 1);
    expo_x--;
  }
  temp = 0;

  if ((zz << 1) != 0) { /* z is not zero */
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;
    /* compare and swap. put augend into xx:yy */
    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }
    /* augend_sign = expo_y, augend_mant = xx:yy, augend_expo = expo_x */
    /* addend_sign = s, addend_mant = zz:ww, addend_expo = expo_z */
    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {
      /* denormalize addend */
      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) | 
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }
      
    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }            
    if ((int)u < 0) {
      /* signs differ, effective subtraction */
      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {
        /* complete cancelation, return 0 */
        return __int_as_float(xx);
      }
      if ((int)xx < 0) {
        /* ooops, augend had smaller mantissa. Negate mantissa and flip
           sign of result*/
        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }
      /* normalize mantissa, if necessary */
      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {
      /* signs are the same, effective addition */
      yy = yy + ww;
      s =  yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {
    /* normal */
    xx |= expo_y; /* or in sign bit */
    xx += (temp && !expo_y); /* round result */
    xx = xx + (expo_x << 23); /* add in exponent */
    return __int_as_float(xx);
  } else if ((int)expo_x >= 126) {
    /* overflow */
    xx = expo_y | (expo_y ? 0x7f7fffff : 0x7F800000);
    return __int_as_float(xx);
  }
  /* subnormal */
  expo_x = ((unsigned int)-((int)expo_x));
  xx += (temp && !expo_y);
  xx = (xx >> expo_x);
  if ((expo_x > 25) || (xx != 0x00800000)) xx = 0;
  return __int_as_float(expo_y | xx);
}

static __forceinline__ float __fmaf_rd (float a, float b, float c)
{
  unsigned long long product;
  unsigned int xx, yy, zz, ww;
  unsigned int temp, s, u;
  unsigned int expo_x, expo_y, expo_z;

  xx = __float_as_int(a);
  yy = __float_as_int(b);
  zz = __float_as_int(c);

  /* Match 'denormals are zero' behavior of the GPU */
  if ((xx << 1) < 0x01000000) xx &= 0x80000000;
  if ((yy << 1) < 0x01000000) yy &= 0x80000000;
  if ((zz << 1) < 0x01000000) zz &= 0x80000000;
   
  temp = 0xff;
  expo_x = temp & (xx >> 23);
  expo_x = expo_x - 1;
  expo_y = temp & (yy >> 23);
  expo_y = expo_y - 1;
  expo_z = temp & (zz >> 23);
  expo_z = expo_z - 1;

  if (!((expo_x <= 0xFD) && 
        (expo_y <= 0xFD) &&
        (expo_z <= 0xFD))) {
    /* fmad (nan, y, z) --> nan
       fmad (x, nan, z) --> nan
       fmad (x, y, nan) --> nan 
    */
    if ((yy << 1) > 0xff000000) {
      return rsqrtf(b);
    }
    if ((zz << 1) > 0xff000000) {
      return rsqrtf(c);
    }
    if ((xx << 1) > 0xff000000) {
      return rsqrtf(a);
    }
    /* fmad (0, inf, z) --> NaN
       fmad (inf, 0, z) --> NaN
       fmad (-inf,+y,+inf) --> NaN
       fmad (+x,-inf,+inf) --> NaN
       fmad (+inf,-y,+inf) --> NaN
       fmad (-x,+inf,+inf) --> NaN
       fmad (-inf,-y,-inf) --> NaN
       fmad (-x,-inf,-inf) --> NaN
       fmad (+inf,+y,-inf) --> NaN
       fmad (+x,+inf,-inf) --> NaN
    */
    if ((((xx << 1) == 0) && ((yy << 1) == 0xff000000)) ||
        (((yy << 1) == 0) && ((xx << 1) == 0xff000000))) {
      return rsqrtf(__int_as_float(0xffc00000));
    }
    if ((zz << 1) == 0xff000000) {
      if (((yy << 1) == 0xff000000) || ((xx << 1) == 0xff000000)) {
        if ((int)(xx ^ yy ^ zz) < 0) {
          return rsqrtf(__int_as_float(0xffc00000));
        }
      }
    }
    /* fmad (inf, y, z) --> inf
       fmad (x, inf, z) --> inf
       fmad (x, y, inf) --> inf
    */
    if ((xx << 1) == 0xff000000) {
      xx = xx ^ (yy & 0x80000000);
      return __int_as_float(xx);
    }
    if ((yy << 1) == 0xff000000) {
      yy = yy ^ (xx & 0x80000000);
      return __int_as_float(yy);
    }
    if ((zz << 1) == 0xff000000) {
      return __int_as_float(zz);
    }
    /* fmad (+0, -y, -0) --> -0
       fmad (-0, +y, -0) --> -0
       fmad (+x, -0, -0) --> -0
       fmad (-x, +0, -0) --> -0
    */
    if (zz == 0x80000000) {
      if (((xx << 1) == 0) || ((yy << 1) == 0)) {
        if ((int)(xx ^ yy) < 0) {
          return __int_as_float(zz);
        }
      }
    }
    /* fmad (0, y, 0) --> +0
       fmad (x, 0, 0) --> +0
    */
    if (((zz << 1) == 0) && 
        (((xx << 1) == 0) || ((yy << 1) == 0))) {
      zz = (xx ^ yy ^ zz) & 0x80000000;
      return __int_as_float(zz);
    }
    /* fmad (0, y, z) --> z
       fmad (x, 0, z) --> z
     */
    if (((xx << 1) == 0) || ((yy << 1) == 0)) {
      return __int_as_float(zz);
    }
    /* normalize x, if denormal */
    if (expo_x == (unsigned)-1) {
      temp = xx & 0x80000000;
      xx = xx << 8;
      while (!(xx & 0x80000000)) {
        xx <<= 1;
        expo_x--;
      }
      expo_x++;
      xx = (xx >> 8) | temp;
    }
    /* normalize y, if denormal */
    if (expo_y == (unsigned)-1) {
      temp = yy & 0x80000000;
      yy = yy << 8;
      while (!(yy & 0x80000000)) {
        yy <<= 1;
        expo_y--;
      }
      expo_y++;
      yy = (yy >> 8) | temp;
    }
    /* normalize z, if denormal */
    if ((expo_z == (unsigned)-1) && ((zz << 1) != 0)) {
      temp = zz & 0x80000000;
      zz = zz << 8;
      while (!(zz & 0x80000000)) {
        zz <<= 1;
        expo_z--;
      }
      expo_z++;
      zz = (zz >> 8) | temp;
    }
  }
    
  expo_x = expo_x + expo_y;
  expo_y = xx ^ yy;
  xx = xx & 0x00ffffff;
  yy = yy << 8;
  xx = xx | 0x00800000;
  yy = yy | 0x80000000;

  product = ((unsigned long long)xx) * yy;
  xx = (unsigned)(product >> 32);
  yy = (unsigned)(product & 0xffffffff);

  expo_x = expo_x - 127 + 2;
  expo_y = expo_y & 0x80000000;
  /* normalize mantissa */
  if (xx < 0x00800000) {
    xx = (xx << 1) | (yy >> 31);
    yy = (yy << 1);
    expo_x--;
  }
  temp = 0;

  if ((zz << 1) != 0) { /* z is not zero */
    s = zz & 0x80000000;
    zz &= 0x00ffffff;
    zz |= 0x00800000;
    ww = 0;
    /* compare and swap. put augend into xx:yy */
    if ((int)expo_z > (int)expo_x) {
      temp = expo_z;
      expo_z = expo_x;
      expo_x = temp;
      temp = zz;
      zz = xx;
      xx = temp;
      temp = ww;
      ww = yy;
      yy = temp;
      temp = expo_y;
      expo_y = s;
      s = temp;
    }
    /* augend_sign = expo_y, augend_mant = xx:yy, augend_expo = expo_x */
    /* addend_sign = s, addend_mant = zz:ww, addend_expo = expo_z */
    expo_z = expo_x - expo_z;
    u = expo_y ^ s;
    if (expo_z <= 49) {
      /* denormalize addend */
      temp = 0;
      while (expo_z >= 32) {
        temp = ww | (temp != 0);
        ww = zz;
        zz = 0;
        expo_z -= 32;
      }
      if (expo_z) {
        temp = ((temp >> expo_z) | (ww << (32 - expo_z)) | 
                ((temp << (32 - expo_z)) != 0));
        ww = (ww >> expo_z) | (zz << (32 - expo_z));
        zz = (zz >> expo_z);
      }
      
    } else {
      temp = 1;
      ww = 0;
      zz = 0;
    }            
    if ((int)u < 0) {
      /* signs differ, effective subtraction */
      temp = (unsigned)(-(int)temp);
      s = (temp != 0);
      u = yy - s;
      s = u > yy;
      yy = u - ww;
      s += yy > u;
      xx = (xx - zz) - s;
      if (!(xx | yy | temp)) {
        /* complete cancelation, return -0 */
        return __int_as_float(0x80000000);
      }
      if ((int)xx < 0) {
        /* ooops, augend had smaller mantissa. Negate mantissa and flip
           sign of result*/
        temp = ~temp;
        yy = ~yy;
        xx = ~xx;
        if (++temp == 0) {
          if (++yy == 0) {
            ++xx;
          }
        }
        expo_y ^= 0x80000000;
      }
      /* normalize mantissa, if necessary */
      while (!(xx & 0x00800000)) {
        xx = (xx << 1) | (yy >> 31);
        yy = (yy << 1);
        expo_x--;
      }
    } else {
      /* signs are the same, effective addition */
      yy = yy + ww;
      s =  yy < ww;
      xx = xx + zz + s;
      if (xx & 0x01000000) {
        temp = temp | (yy << 31);
        yy = (yy >> 1) | (xx << 31);
        xx = ((xx & 0x80000000) | (xx >> 1)) & ~0x40000000;
        expo_x++;
      }
    }
  }
  temp = yy | (temp != 0);
  if (expo_x <= 0xFD) {
    /* normal */
    xx |= expo_y; /* or in sign bit */
    xx += (temp && expo_y); /* round result */
    xx = xx + (expo_x << 23); /* add in exponent */
    return __int_as_float(xx);
  } else if ((int)expo_x >= 126) {
    /* overflow */
    xx = expo_y | (expo_y ? 0x7f800000 : 0x7F7FFFFF);
    return __int_as_float(xx);
  }
  /* subnormal */
  expo_x = ((unsigned int)-((int)expo_x));
  xx += (temp && expo_y);
  xx = (xx >> expo_x);
  if ((expo_x > 25) || (xx != 0x00800000)) xx = 0;
  return __int_as_float(expo_y | xx);
}

static __forceinline__ int __clz(int a)
{
  return (a)?(158-(__float_as_int(__uint2float_rz((unsigned int)a))>>23)):32;
}

static __forceinline__ int __clzll(long long int a)
{
  int ahi = ((int)((unsigned long long)a >> 32));
  int alo = ((int)((unsigned long long)a & 0xffffffffULL));
  int res;
  if (ahi) {
    res = 0;
  } else {
    res = 32;
    ahi = alo;
  }
  res = res + __clz(ahi);
  return res;
}

static __forceinline__ int __popc(unsigned int a)
{
  a = a - ((a >> 1) & 0x55555555);
  a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
  a = (a + (a >> 4)) & 0x0f0f0f0f;
  a = ((__umul24(a, 0x808080) << 1) + a) >> 24;
  return a;
}

static __forceinline__ int __popcll(unsigned long long int a)
{
  unsigned int ahi = ((unsigned int)(a >> 32));
  unsigned int alo = ((unsigned int)(a & 0xffffffffULL));
  alo = alo - ((alo >> 1) & 0x55555555);
  alo = (alo & 0x33333333) + ((alo >> 2) & 0x33333333);
  ahi = ahi - ((ahi >> 1) & 0x55555555);
  ahi = (ahi & 0x33333333) + ((ahi >> 2) & 0x33333333);
  alo = alo + ahi;
  alo = (alo & 0x0f0f0f0f) + ((alo >> 4) & 0x0f0f0f0f);
  alo = ((__umul24(alo, 0x808080) << 1) + alo) >> 24;
  return alo;
}

static __forceinline__ unsigned int __brev(unsigned int a)
{
  /* Use Knuth's algorithm from http://www.hackersdelight.org/revisions.pdf */
  unsigned int t;
  a = (a << 15) | (a >> 17);
  t = (a ^ (a >> 10)) & 0x003f801f; 
  a = (t + (t << 10)) ^ a;
  t = (a ^ (a >>  4)) & 0x0e038421; 
  a = (t + (t <<  4)) ^ a;
  t = (a ^ (a >>  2)) & 0x22488842; 
  a = (t + (t <<  2)) ^ a;
  return a;
}

static __forceinline__ unsigned long long int __brevll(unsigned long long int a)
{
  unsigned int hi = (unsigned int)(a >> 32);
  unsigned int lo = (unsigned int)(a & 0xffffffffULL);
  unsigned int t;
  t  = __brev(lo);
  lo = __brev(hi);
  return ((unsigned long long int)t << 32) + (unsigned long long int)lo;
}

static __forceinline__ unsigned int __byte_perm(unsigned int a, unsigned int b, unsigned int slct)
{
  unsigned int i0 = (slct >>  0) & 0x7;
  unsigned int i1 = (slct >>  4) & 0x7;
  unsigned int i2 = (slct >>  8) & 0x7;
  unsigned int i3 = (slct >> 12) & 0x7;

  return (((((i0 < 4) ? (a >> (i0*8)) : (b >> ((i0-4)*8))) & 0xff) <<  0) +
          ((((i1 < 4) ? (a >> (i1*8)) : (b >> ((i1-4)*8))) & 0xff) <<  8) +
          ((((i2 < 4) ? (a >> (i2*8)) : (b >> ((i2-4)*8))) & 0xff) << 16) +
          ((((i3 < 4) ? (a >> (i3*8)) : (b >> ((i3-4)*8))) & 0xff) << 24));
}

#endif /* __CUDA_ARCH__ < 200 */ 

static __forceinline__ int __ffs(int a)
{
  return 32 - __clz(a & -a);
}

static __forceinline__ int __ffsll(long long int a)
{
  return 64 - __clzll(a & -a);
}

#endif /* __cplusplus && __CUDACC__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "sm_11_atomic_functions.h"
#include "sm_12_atomic_functions.h"
#include "sm_13_double_functions.h"
#include "sm_20_atomic_functions.h"
#include "sm_20_intrinsics.h"
#include "surface_functions.h"
#include "texture_fetch_functions.h"

#endif /* !__DEVICE_FUNCTIONS_H__ */
