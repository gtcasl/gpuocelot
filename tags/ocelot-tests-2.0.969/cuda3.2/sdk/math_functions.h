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

#if !defined(__MATH_FUNCTIONS_H__)
#define __MATH_FUNCTIONS_H__

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#if defined(__cplusplus) && defined(__CUDACC__)

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#include "builtin_types.h"
#include "host_defines.h"

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern "C"
{

/*DEVICE_BUILTIN*/
extern __host__ __device__ int            __cdecl abs(int) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ long int       __cdecl labs(long int) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ long long int          llabs(long long int) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl fabs(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  fabsf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    min(int, int);
/*DEVICE_BUILTIN*/
extern __host__ __device__ unsigned int           umin(unsigned int, unsigned int);
/*DEVICE_BUILTIN*/
extern __host__ __device__ long long int          llmin(long long int, long long int);
/*DEVICE_BUILTIN*/
extern __host__ __device__ unsigned long long int ullmin(unsigned long long int, unsigned long long int);
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  fminf(float, float) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 fmin(double, double) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    max(int, int);
/*DEVICE_BUILTIN*/
extern __host__ __device__ unsigned int           umax(unsigned int, unsigned int);
/*DEVICE_BUILTIN*/
extern __host__ __device__ long long int          llmax(long long int, long long int);
/*DEVICE_BUILTIN*/
extern __host__ __device__ unsigned long long int ullmax(unsigned long long int, unsigned long long int);
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  fmaxf(float, float) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 fmax(double, double) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl sin(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  sinf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl cos(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  cosf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ void                   sincos(double, double*, double*) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ void                   sincosf(float, float*, float*) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl tan(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  tanf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl sqrt(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  sqrtf(float) __THROW;         

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 rsqrt(double);                
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  rsqrtf(float);                

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 exp2(double) __THROW;         
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  exp2f(float) __THROW;         

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 exp10(double) __THROW;        
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  exp10f(float) __THROW;        

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 expm1(double) __THROW;        
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  expm1f(float) __THROW;        

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 log2(double) __THROW;         
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  log2f(float) __THROW;         

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl log10(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  log10f(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl log(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  logf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 log1p(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  log1pf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl floor(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  floorf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl exp(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  expf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl cosh(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                 coshf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl sinh(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  sinhf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl tanh(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  tanhf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 acosh(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  acoshf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 asinh(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  asinhf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 atanh(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  atanhf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl ldexp(double, int) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  ldexpf(float, int) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 logb(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  logbf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    ilogb(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    ilogbf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 scalbn(double, int) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  scalbnf(float, int) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 scalbln(double, long int) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  scalblnf(float, long int) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl frexp(double, int*) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  frexpf(float, int*) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 round(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  roundf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ long int               lround(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ long int               lroundf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ long long int          llround(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ long long int          llroundf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 rint(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  rintf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ long int               lrint(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ long int               lrintf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ long long int          llrint(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ long long int          llrintf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 nearbyint(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  nearbyintf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl ceil(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  ceilf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 trunc(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  truncf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 fdim(double, double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  fdimf(float, float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl atan2(double, double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  atan2f(float, float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl atan(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  atanf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl asin(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  asinf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl acos(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  acosf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl hypot(double, double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  hypotf(float, float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 cbrt(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  cbrtf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 rcbrt(double);
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  rcbrtf(float);

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 sinpi(double);
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  sinpif(float);

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl pow(double, double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  powf(float, float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl modf(double, double*) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  modff(float, float*) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double         __cdecl fmod(double, double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  fmodf(float, float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 remainder(double, double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  remainderf(float, float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 remquo(double, double, int*) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  remquof(float, float, int*) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 erf(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  erff(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 erfinv(double);
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  erfinvf(float);

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 erfc(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  erfcf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 erfcinv(double);
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  erfcinvf(float);

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 lgamma(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  lgammaf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 tgamma(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  tgammaf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 copysign(double, double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  copysignf(float, float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 nextafter(double, double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  nextafterf(float, float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 nan(const char*) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  nanf(const char*) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __isinf(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __isinff(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __isnan(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __isnanf(float) __THROW;

#if defined(__APPLE__)

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __isfinited(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __isfinitef(float) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __signbitd(double) __THROW;

#else /* __APPLE__ */

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __finite(double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __finitef(float) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __signbit(double) __THROW;

#endif /* __APPLE__ */

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __signbitf(float) __THROW;

/*DEVICE_BUILTIN*/
extern __host__ __device__ double                 fma(double, double, double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ float                  fmaf(float, float, float) __THROW;


/* these are here to avoid warnings on the call graph.
   long double is not supported on the device */
#if defined(__GNUC__)

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __signbitl(long double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __isinfl(long double) __THROW;
/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __isnanl(long double) __THROW;

#if defined(__APPLE__)

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __isfinite(long double) __THROW;

#else /* __APPLE__ */

/*DEVICE_BUILTIN*/
extern __host__ __device__ int                    __finitel(long double) __THROW;

#endif /* __APPLE__ */

#endif /* __GNUC__ */

}

#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <cstdlib>

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#if defined(__GNUC__)

#if defined(__APPLE__)

#define signbit(x) \
        (sizeof(x) == sizeof(float) ? __signbitf(x) : sizeof(x) == sizeof(double) ? __signbitd(x) : __signbitl(x))
#define isfinite(x) \
        (sizeof(x) == sizeof(float) ? __isfinitef(x) : sizeof(x) == sizeof(double) ? __isfinited(x) : __isfinite(x))

#else /* __APPLE__ */

#define signbit(x) \
        (sizeof(x) == sizeof(float) ? __signbitf(x) : sizeof(x) == sizeof(double) ? __signbit(x) : __signbitl(x))
#define isfinite(x) \
        (sizeof(x) == sizeof(float) ? __finitef(x) : sizeof(x) == sizeof(double) ? __finite(x) : __finitel(x))

#endif /* __APPLE__ */

#define isnan(x) \
        (sizeof(x) == sizeof(float) ? __isnanf(x) : sizeof(x) == sizeof(double) ? __isnan(x) : __isnanl(x))
#define isinf(x) \
        (sizeof(x) == sizeof(float) ? __isinff(x) : sizeof(x) == sizeof(double) ? __isinf(x) : __isinfl(x))

namespace __gnu_cxx
{
  extern __host__ __device__ long long int abs(long long int);
}

namespace std
{
  template<typename T> extern __host__ __device__ T __pow_helper(T, int);
  template<typename T> extern __host__ __device__ T __cmath_power(T, unsigned int);
}

using std::abs;
using std::fabs;
using std::ceil;
using std::floor;
using std::sqrt;
using std::pow;
using std::log;
using std::log10;
using std::fmod;
using std::modf;
using std::exp;
using std::frexp;
using std::ldexp;
using std::asin;
using std::sin;
using std::sinh;
using std::acos;
using std::cos;
using std::cosh;
using std::atan;
using std::atan2;
using std::tan;
using std::tanh;

#elif defined(_WIN32)

static __inline__ __host__ __device__ long long int abs(long long int a)
{
  return llabs(a);
}

static __inline__ __host__ __device__ int signbit(double a)
{
  return __signbit(a);
}

static __inline__ __host__ __device__ int signbit(float a)
{
  return __signbitf(a);
}

static __inline__ __host__ __device__ int isinf(double a)
{
  return __isinf(a);
}

static __inline__ __host__ __device__ int isinf(float a)
{
  return __isinff(a);
}

static __inline__ __host__ __device__ int isnan(double a)
{
  return __isnan(a);
}

static __inline__ __host__ __device__ int isnan(float a)
{
  return __isnanf(a);
}

static __inline__ __host__ __device__ int isfinite(double a)
{
  return __finite(a);
}

static __inline__ __host__ __device__ int isfinite(float a)
{
  return __finitef(a);
}

template<class T> extern __host__ __device__ T _Pow_int(T, int);

#endif /* __GNUC__ */

#if defined(__GNUC__)
namespace std {
#endif /* __GNUC__ */

extern __host__ __device__ long int __cdecl abs(long int);
extern __host__ __device__ float    __cdecl abs(float);
extern __host__ __device__ double   __cdecl abs(double);
extern __host__ __device__ float    __cdecl fabs(float);
extern __host__ __device__ float    __cdecl ceil(float);
extern __host__ __device__ float    __cdecl floor(float);
extern __host__ __device__ float    __cdecl sqrt(float);
extern __host__ __device__ float    __cdecl pow(float, float);
extern __host__ __device__ float    __cdecl pow(float, int);
extern __host__ __device__ double   __cdecl pow(double, int);
extern __host__ __device__ float    __cdecl log(float);
extern __host__ __device__ float    __cdecl log10(float);
extern __host__ __device__ float    __cdecl fmod(float, float);
extern __host__ __device__ float    __cdecl modf(float, float*);
extern __host__ __device__ float    __cdecl exp(float);
extern __host__ __device__ float    __cdecl frexp(float, int*);
extern __host__ __device__ float    __cdecl ldexp(float, int);
extern __host__ __device__ float    __cdecl asin(float);
extern __host__ __device__ float    __cdecl sin(float);
extern __host__ __device__ float    __cdecl sinh(float);
extern __host__ __device__ float    __cdecl acos(float);
extern __host__ __device__ float    __cdecl cos(float);
extern __host__ __device__ float    __cdecl cosh(float);
extern __host__ __device__ float    __cdecl atan(float);
extern __host__ __device__ float    __cdecl atan2(float, float);
extern __host__ __device__ float    __cdecl tan(float);
extern __host__ __device__ float    __cdecl tanh(float);

#if defined(__GNUC__)
}
#endif /* __GNUC__ */

static __inline__ __host__ __device__ float logb(float a)
{
  return logbf(a);
}

static __inline__ __host__ __device__ int ilogb(float a)
{
  return ilogbf(a);
}

static __inline__ __host__ __device__ float scalbn(float a, int b)
{
  return scalbnf(a, b);
}

static __inline__ __host__ __device__ float scalbln(float a, long int b)
{
  return scalblnf(a, b);
}

static __inline__ __host__ __device__ float exp2(float a)
{
  return exp2f(a);
}

static __inline__ __host__ __device__ float exp10(float a)
{
  return exp10f(a);
}

static __inline__ __host__ __device__ float expm1(float a)
{
  return expm1f(a);
}

static __inline__ __host__ __device__ float log2(float a)
{
  return log2f(a);
}

static __inline__ __host__ __device__ float log1p(float a)
{
  return log1pf(a);
}

static __inline__ __host__ __device__ float rsqrt(float a)
{
  return rsqrtf(a);
}

static __inline__ __host__ __device__ float acosh(float a)
{
  return acoshf(a);
}

static __inline__ __host__ __device__ float asinh(float a)
{
  return asinhf(a);
}

static __inline__ __host__ __device__ float atanh(float a)
{
  return atanhf(a);
}

static __inline__ __host__ __device__ float hypot(float a, float b)
{
  return hypotf(a, b);
}

static __inline__ __host__ __device__ float cbrt(float a)
{
  return cbrtf(a);
}

static __inline__ __host__ __device__ float rcbrt(float a)
{
  return rcbrtf(a);
}

static __inline__ __host__ __device__ float sinpi(float a)
{
  return sinpif(a);
}

static __inline__ __host__ __device__ void sincos(float a, float *sptr, float *cptr)
{
  sincosf(a, sptr, cptr);
}

static __inline__ __host__ __device__ float erf(float a)
{
  return erff(a);
}

static __inline__ __host__ __device__ float erfinv(float a)
{
  return erfinvf(a);
}

static __inline__ __host__ __device__ float erfc(float a)
{
  return erfcf(a);
}

static __inline__ __host__ __device__ float erfcinv(float a)
{
  return erfcinvf(a);
}

static __inline__ __host__ __device__ float lgamma(float a)
{
  return lgammaf(a);
}

static __inline__ __host__ __device__ float tgamma(float a)
{
  return tgammaf(a);
}

static __inline__ __host__ __device__ float copysign(float a, float b)
{
  return copysignf(a, b);
}

static __inline__ __host__ __device__ double copysign(double a, float b)
{
  return copysign(a, (double)b);
}

static __inline__ __host__ __device__ float copysign(float a, double b)
{
  return copysignf(a, (float)b);
}

static __inline__ __host__ __device__ float nextafter(float a, float b)
{
  return nextafterf(a, b);
}

static __inline__ __host__ __device__ float remainder(float a, float b)
{
  return remainderf(a, b);
}

static __inline__ __host__ __device__ float remquo(float a, float b, int *quo)
{
  return remquof(a, b, quo);
}

static __inline__ __host__ __device__ float round(float a)
{
  return roundf(a);
}

static __inline__ __host__ __device__ long int lround(float a)
{
  return lroundf(a);
}

static __inline__ __host__ __device__ long long int llround(float a)
{
  return llroundf(a);
}

static __inline__ __host__ __device__ float trunc(float a)
{
  return truncf(a);
}

static __inline__ __host__ __device__ float rint(float a)
{
  return rintf(a);
}

static __inline__ __host__ __device__ long int lrint(float a)
{
  return lrintf(a);
}

static __inline__ __host__ __device__ long long int llrint(float a)
{
  return llrintf(a);
}

static __inline__ __host__ __device__ float nearbyint(float a)
{
  return nearbyintf(a);
}

static __inline__ __host__ __device__ float fdim(float a, float b)
{
  return fdimf(a, b);
}

static __inline__ __host__ __device__ float fma(float a, float b, float c)
{
  return fmaf(a, b, c);
}

static __inline__ __host__ __device__ float fmax(float a, float b)
{
  return fmaxf(a, b);
}

static __inline__ __host__ __device__ float fmin(float a, float b)
{
  return fminf(a, b);
}

static __inline__ __host__ __device__ unsigned int min(unsigned int a, unsigned int b)
{
  return umin(a, b);
}

static __inline__ __host__ __device__ unsigned int min(int a, unsigned int b)
{
  return umin((unsigned int)a, b);
}

static __inline__ __host__ __device__ unsigned int min(unsigned int a, int b)
{
  return umin(a, (unsigned int)b);
}

static __inline__ __host__ __device__ long long int min(long long int a, long long int b)
{
  return llmin(a, b);
}

static __inline__ __host__ __device__ unsigned long long int min(unsigned long long int a, unsigned long long int b)
{
  return ullmin(a, b);
}

static __inline__ __host__ __device__ unsigned long long int min(long long int a, unsigned long long int b)
{
  return ullmin((unsigned long long int)a, b);
}

static __inline__ __host__ __device__ unsigned long long int min(unsigned long long int a, long long int b)
{
  return ullmin(a, (unsigned long long int)b);
}

static __inline__ __host__ __device__ float min(float a, float b)
{
  return fminf(a, b);
}

static __inline__ __host__ __device__ double min(double a, double b)
{
  return fmin(a, b);
}

static __inline__ __host__ __device__ double min(float a, double b)
{
  return fmin((double)a, b);
}

static __inline__ __host__ __device__ double min(double a, float b)
{
  return fmin(a, (double)b);
}

static __inline__ __host__ __device__ unsigned int max(unsigned int a, unsigned int b)
{
  return umax(a, b);
}

static __inline__ __host__ __device__ unsigned int max(int a, unsigned int b)
{
  return umax((unsigned int)a, b);
}

static __inline__ __host__ __device__ unsigned int max(unsigned int a, int b)
{
  return umax(a, (unsigned int)b);
}

static __inline__ __host__ __device__ long long int max(long long int a, long long int b)
{
  return llmax(a, b);
}

static __inline__ __host__ __device__ unsigned long long int max(unsigned long long int a, unsigned long long int b)
{
  return ullmax(a, b);
}

static __inline__ __host__ __device__ unsigned long long int max(long long int a, unsigned long long int b)
{
  return ullmax((unsigned long long int)a, b);
}

static __inline__ __host__ __device__ unsigned long long int max(unsigned long long int a, long long int b)
{
  return ullmax(a, (unsigned long long int)b);
}

static __inline__ __host__ __device__ float max(float a, float b)
{
  return fmaxf(a, b);
}

static __inline__ __host__ __device__ double max(double a, double b)
{
  return fmax(a, b);
}

static __inline__ __host__ __device__ double max(float a, double b)
{
  return fmax((double)a, b);
}

static __inline__ __host__ __device__ double max(double a, float b)
{
  return fmax(a, (double)b);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

#elif !defined(__CUDACC__)

#include "host_defines.h"
#include "math_constants.h"

#define __cuda_INT_MAX \
        ((int)((unsigned int)-1 >> 1))

#if defined(__CUDABE__)

#include "device_functions.h"

/*******************************************************************************
*                                                                              *
* DEVICE                                                                       *
*                                                                              *
*******************************************************************************/

#if defined(__GNUC__)

int __cuda_error_not_implememted(void);

#define __cuda___signbitl(a) \
        __cuda_error_not_implememted()
#define __cuda___isinfl(a) \
        __cuda_error_not_implememted()
#define __cuda___isnanl(a) \
        __cuda_error_not_implememted()

#if defined(__APPLE__)

#define __cuda___isfinite(a) \
        __cuda_error_not_implememted()

#else /* __APPLE__ */

#define __cuda___finitel(a) \
        __cuda_error_not_implememted()

#endif /* __APPLE__ */

#endif /* __GNUC__ */

/*******************************************************************************
*                                                                              *
* DEVICE IMPLEMENTATIONS FOR FUNCTIONS WITH BUILTIN NVOPENCC OPERATIONS        *
*                                                                              *
*******************************************************************************/

static __forceinline__ float rintf(float a)
{
  return __builtin_roundf(a);
}

static __forceinline__ long int lrintf(float a)
{
#if defined(__LP64__)
  return (long int)__float2ll_rn(a);
#else /* __LP64__ */
  return (long int)__float2int_rn(a);
#endif /* __LP64__ */
}

static __forceinline__ long long int llrintf(float a)
{
  return __float2ll_rn(a);
}

static __forceinline__ float nearbyintf(float a)
{
  return __builtin_roundf(a);
}

/*******************************************************************************
*                                                                              *
* DEVICE IMPLEMENTATIONS FOR FUNCTIONS WITHOUT BUILTIN NVOPENCC OPERATIONS     *
*                                                                              *
*******************************************************************************/

static __forceinline__ int __signbitf(float a)
{
  return (int)((unsigned int)__float_as_int(a) >> 31);
}

/* The copysign() function returns a with its sign changed to 
 * match the sign of b.
 */
static __forceinline__ float copysignf(float a, float b)
{
  return __int_as_float((__float_as_int(b) &  0x80000000) | 
                        (__float_as_int(a) & ~0x80000000));
}

static __forceinline__ int __finitef(float a)
{
  return fabsf(a) < CUDART_INF_F;
}

#if defined(__APPLE__)

static __forceinline__ int __isfinitef(float a)
{
  return __finitef(a);
}

#endif /* __APPLE__ */

static __forceinline__ int __isinff(float a)
{
  return fabsf(a) == CUDART_INF_F;
}

static __forceinline__ int __isnanf(float a)
{
  return !(fabsf(a) <= CUDART_INF_F);
}

static __forceinline__ float nextafterf(float a, float b)
{
  unsigned int ia;
  unsigned int ib;
  ia = __float_as_int(a);
  ib = __float_as_int(b);
#if defined(__CUDA_FTZ)
  if ((ia << 1) < 0x01000000) ia &= 0x80000000; /* DAZ */
  if ((ib << 1) < 0x01000000) ib &= 0x80000000; /* DAZ */
#endif
  if (__isnanf(a) || __isnanf(b)) return a + b; /*NaN*/
  if (__int_as_float (ia | ib) == 0.0f) return __int_as_float(ib);
#if defined(__CUDA_FTZ)
  if (__int_as_float(ia) == 0.0f) {
    return __int_as_float (0x00800000 | (__float_as_int(b) & 0x80000000));
  }
#else
  if (__int_as_float(ia) == 0.0f) {
    return __int_as_float (0x00000001 | (__float_as_int(b) & 0x80000000));
  }
#endif
  if ((a < b) && (a < 0.0f)) ia--;
  if ((a < b) && (a > 0.0f)) ia++;
  if ((a > b) && (a < 0.0f)) ia++;
  if ((a > b) && (a > 0.0f)) ia--;
  a = __int_as_float(ia);
#if defined(__CUDA_FTZ)
  if (a == 0.0f) {
    a = __int_as_float(ia & 0x80000000); /* FTZ */
  }
#endif
  return a;
}

static __forceinline__ unsigned long long int __internal_nan_kernel(const char *s)
{
  unsigned long long i = 0;
  int c;
  int ovfl = 0;
  int invld = 0;
  if (s && (*s == '0')) {
    s++;
    if ((*s == 'x') || (*s == 'X')) {
      s++; 
      while (*s == '0') s++;
      while (*s) {
        if (i > 0x0fffffffffffffffULL) {
          ovfl = 1;
        }
        c = (((*s) >= 'A') && ((*s) <= 'F')) ? (*s + 'a' - 'A') : (*s);
        if ((c >= 'a') && (c <= 'f')) { 
          c = c - 'a' + 10;
          i = i * 16 + c;
        } else if ((c >= '0') && (c <= '9')) { 
          c = c - '0';
          i = i * 16 + c;
        } else {
          invld = 1;
        }
        s++;
      }
    } else {
      while (*s == '0') s++;
      while (*s) {
        if (i > 0x1fffffffffffffffULL) {
          ovfl = 1;
        }
        c = *s;
        if ((c >= '0') && (c <= '7')) { 
          c = c - '0';
          i = i * 8 + c;
        } else {
          invld = 1; 
        }
        s++;
      }
    }
  } else if (s) {
    while (*s) {
      c = *s;
      if ((i > 1844674407370955161ULL) || 
          ((i == 1844674407370955161ULL) && (c > '5'))) {
        ovfl = 1;
      }
      if ((c >= '0') && (c <= '9')) { 
        c = c - '0';
        i = i * 10 + c;
      } else {
        invld = 1;
      }
      s++;
    }
  }
  if (ovfl) {
    i = ~0ULL;
  }
  if (invld) {
    i = 0ULL;
  }
  i = (i & 0x000fffffffffffffULL) | 0x7ff8000000000000ULL;
  return i;
}

static __forceinline__ float nanf(const char *tagp)
{
  return CUDART_NAN_F;
}

static __forceinline__ float __internal_fmad(float a, float b, float c)
{
#if __CUDA_ARCH__ >= 200
  return __fmaf_rn (a, b, c);
#else /* __CUDA_ARCH__ >= 200 */
  return a * b + c;
#endif /* __CUDA_ARCH__ >= 200 */
}

/* approximate 2*atanh(a/2) for |a| < 0.245 */
static __forceinline__ float __internal_atanhf_kernel(float a_1, float a_2)
{
  float a, a2, t;

  a = a_1 + a_2;
  a2 = a * a;    
  t =                         1.566305595598990E-001f/64.0f;
  t = __internal_fmad (t, a2, 1.995081856004762E-001f/16.0f);
  t = __internal_fmad (t, a2, 3.333382699617026E-001f/4.0f);
  t = t * a2;
  t = __internal_fmad (t, a, a_2);
  t = t + a_1;
  return t;
}  

/* compute atan(a) in first octant, i.e. 0 <= a <= 1
 * eps ~= 2.16e-7
 */
static __forceinline__ float __internal_atanf_kernel(float a)
{
  float t4, t0, t1;

  t4 = a * a;
  t0 = -5.674867153f;
  t0 = __internal_fmad (t4, -0.823362947f, t0);
  t0 = __internal_fmad (t0, t4, -6.565555096f);
  t0 = t0 * t4;
  t0 = t0 * a;
  t1 = t4 + 11.33538818f;
  t1 = __internal_fmad (t1, t4, 28.84246826f);
  t1 = __internal_fmad (t1, t4, 19.69667053f);
  t1 = 1.0f / t1;
  a = __internal_fmad (t0, t1, a);
  return a;
}

/* approximate tangent on -pi/4...+pi/4 */
static __forceinline__ float __internal_tan_kernel(float a)
{
  float a2, s, t;

  a2 = a * a;
  t  = __internal_fmad (4.114678393115178E-003f, a2, -8.231194034909670E-001f);
  s  = a2 - 2.469348886157666E+000f;
  s  = 1.0f / s;
  t  = t * s;
  t  = t * a2;
  t  = __internal_fmad (t, a, a);
  return t;
}

static __forceinline__ float __internal_accurate_logf(float a)
{
  float t;
  float z;
  float m;
  int ia;
  ia = __float_as_int(a);

  if ((a > CUDART_ZERO_F) && (a < CUDART_INF_F)) {
    int e = -127;
#if !defined(__CUDA_FTZ)
    /* normalize denormals */
    if ((unsigned)ia < (unsigned)0x00800000) {
      a = a * CUDART_TWO_TO_24_F;
      e -= 24;
      ia = __float_as_int(a);
    }
#endif
    /* log(a) = 2 * atanh((a-1)/(a+1)) */
    m = __int_as_float((ia & 0x807fffff) | 0x3f800000);
    e += ((unsigned)ia >> 23);
    if (m > CUDART_SQRT_TWO_F) {
      m = m * 0.5f;
      e = e + 1;
    }      
    t = m - 1.0f;
    z = m + 1.0f;
    z = __fdividef (t, z);
    z = -t * z;
    z = __internal_atanhf_kernel(t, z);
    z = __internal_fmad ((float)e, CUDART_LN2_F, z);
    return z;
  } else {
    /* handle special cases */
    return __logf(a);
  }
}  

static __forceinline__ float2 __internal_log_ep(float a)
{
  float2 res;
  int expo;
  float m;
  float log_hi, log_lo;
  float t_hi, t_lo;
  float f, g, u, v, q;
  float r, s, e;
  expo = (__float_as_int(a) >> 23) & 0xff;
#if !defined(__CUDA_FTZ)
  /* convert denormals to normals for computation of log(a) */
  if (expo == 0) {
    a *= CUDART_TWO_TO_24_F;
    expo = (__float_as_int(a) >> 23) & 0xff;
    expo -= 24;
  }  
#endif
  expo -= 127;
  m = __int_as_float((__float_as_int(a) & 0x807fffff) | 0x3f800000);
  if (m > CUDART_SQRT_TWO_F) {
    m = m * 0.5f;
    expo = expo + 1;
  }

  /* compute log(m) with extended precision using an algorithm from P.T.P.
   * Tang, "Table Driven Implementation of the Logarithm Function", TOMS, 
   * Vol. 16., No. 4, December 1990, pp. 378-400. A modified polynomial 
   * approximation to atanh(x) on the interval [-0.1716, 0.1716] is utilized.
   */
  f = m - 1.0f;
  g = m + 1.0f;
  g = 1.0f / g;
  u = 2.0f * f * g;
  v = u * u;
  q = 1.49356810919559350E-001f/64.0f;
  q = __internal_fmad (q, v, 1.99887797540072460E-001f/16.0f);
  q = __internal_fmad (q, v, 3.33333880955515580E-001f/4.0f);
  q = q * v;
  q = q * u;
  log_hi = __int_as_float(__float_as_int(u) & 0xfffff000);
  v = __int_as_float(__float_as_int(f) & 0xfffff000);
  u = 2.0f * (f - log_hi);
  f = f - v;
  u = __internal_fmad (-log_hi, v, u);
  u = __internal_fmad (-log_hi, f, u);
  u = g * u;
  /* compute log(m) = log_hi + u + q in double-single format*/

  /* log += u; |log| > |u| */
  r = log_hi + u;
  s = u - (r - log_hi);
  log_hi = r;
  log_lo = s;
  /* log += q; |log| > |q| */
  r = log_hi + q;
  s = ((log_hi - r) + q) + log_lo;
  log_hi = e = r + s;
  log_lo = (r - e) + s;

  /* log(2)*expo in double-single format */
  t_hi = expo * 0.6931457519f;    /* multiplication is exact */
  t_lo = expo * 1.4286067653e-6f;

  /* log(a) = log(m) + log(2)*expo;  if expo != 0, |log(2)*expo| > |log(m)| */
  r = t_hi + log_hi;
  s = (((t_hi - r) + log_hi) + log_lo) + t_lo;
  res.y = e = r + s;
  res.x = (r - e) + s;
  return res;
}

static __forceinline__ float __internal_accurate_log2f(float a)
{
  return CUDART_L2E_F * __internal_accurate_logf(a);
}

/* Based on: Guillaume Da Graça, David Defour. Implementation of Float-Float 
 * Operators on Graphics Hardware. RNC'7, pp. 23-32, 2006.
 */
static __forceinline__ float2 __internal_dsmul (float2 x, float2 y)
{
    float2 z;
#if __CUDA_ARCH__ < 200
    float up, vp, u1, u2, v1, v2, mh, ml;
    up  = x.y * 4097.0f;
    u1  = (x.y - up) + up;
    u2  = x.y - u1;
    vp  = y.y * 4097.0f;
    v1  = (y.y - vp) + vp;
    v2  = y.y - v1;
    mh  = __fmul_rn(x.y,y.y);
    ml  = (((u1 * v1 - mh) + u1 * v2) + u2 * v1) + u2 * v2;
    ml  = (__fmul_rn(x.y,y.x) + __fmul_rn(x.x,y.y)) + ml;
    z.y = up = mh + ml;
    z.x = (mh - up) + ml;
#else /* __CUDA_ARCH__ < 200 */
    float up, mh, ml;
    ml = __fmul_rn (x.y, y.y);
    mh = __fmaf_rn (x.y, y.y, -ml);
    mh = __fmaf_rn (x.x, y.x, mh);
    mh = __fmaf_rn (x.y, y.x, mh);
    mh = __fmaf_rn (x.x, y.y, mh);
    z.y = up = __fadd_rn (ml, mh);
    z.x = __fadd_rn(__fadd_rn(ml, -up), mh);
#endif /* __CUDA_ARCH__ < 200 */
    return z;
}

/* 160 bits of 2/PI for Payne-Hanek style argument reduction. */
static __constant__ unsigned int __cudart_i2opi_f [] = {
  0x3c439041,
  0xdb629599,
  0xf534ddc0,
  0xfc2757d1,
  0x4e441529,
  0xa2f9836e,
};

/* reduce argument to trig function to -pi/4...+pi/4 */
static __forceinline__ float __internal_trig_reduction_kernel(float a, int *quadrant)
{
  float j;
  int q;
  if (fabsf(a) > CUDART_TRIG_PLOSS_F) {
    /* Payne-Hanek style argument reduction. */
    unsigned int ia = __float_as_int(a);
    unsigned int s = ia & 0x80000000;
    unsigned int result[7];
    unsigned int phi, plo;
    unsigned int hi, lo;
    unsigned int e;
    int idx;
    e = ((ia >> 23) & 0xff) - 128;
    ia = (ia << 8) | 0x80000000;
    /* compute x * 2/pi */
    idx = 4 - (e >> 5);
    hi = 0;
#pragma unroll 1
    for (q = 0; q < 6; q++) {
      plo = __cudart_i2opi_f[q] * ia;
      phi = __umulhi (__cudart_i2opi_f[q], ia);
      lo = hi + plo;
      hi = phi + (lo < plo);
      result[q] = lo;
    }
    result[q] = hi;
    e = e & 31;
    /* shift result such that hi:lo<63:62> are the least significant
       integer bits, and hi:lo<61:0> are the fractional bits of the result
     */
    hi = result[idx+2];
    lo = result[idx+1];
    if (e) {
      q = 32 - e;
      hi = (hi << e) + (lo >> q);
      lo = (lo << e) + (result[idx] >> q);
    }
    q = hi >> 30;
    /* fraction */
    hi = (hi << 2) + (lo >> 30);
    lo = (lo << 2);
    e = (hi + (lo > 0)) > 0x80000000; /* fraction >= 0.5 */
    q += e;
    if (s) q = -q;
    if (e) {
      unsigned int t;
      hi = ~hi;
      lo = -(int)lo;
      t = (lo == 0);
      hi += t;
      s = s ^ 0x80000000;
    }
    *quadrant = q;
    /* normalize fraction */
    e = 0;
    while ((int)hi > 0) {
      hi = (hi << 1) + (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    lo = hi * 0xc90fdaa2;
    hi = __umulhi(hi, 0xc90fdaa2);
    if ((int)hi > 0) {
      hi = (hi << 1) + (lo >> 31);
      lo = (lo << 1);
      e--;
    }
    hi = hi + (lo > 0);
    ia = s | (((e + 126) << 23) + (hi >> 8) + ((hi << 24) >= 0x80000000));
    return __int_as_float(ia);
  }
  q = __float2int_rn (a * CUDART_2_OVER_PI_F);
  j = (float)q;
  a = __internal_fmad (-j, 1.5703125000000000e+000f, a);
#if __CUDA_ARCH__ >= 200
  /* take advantage of FMA by combining two constants */
  a = __fmaf_rn (-j, 4.8382673412561417e-004f, a);
#else /* __CUDA_ARCH__ >= 200 */
  a = __internal_fmad (-j, 4.8351287841796875e-004f, a);
  a = __internal_fmad (-j, 3.1385570764541626e-007f, a);
#endif /* __CUDA_ARCH__ >= 200 */
  a = __internal_fmad (-j, 6.0771005065061922e-011f, a);
  *quadrant = q;
  return a;
}

/* High quality implementation of expf(). A naive implementation, expf(x) =
 * exp2f (x * log2(e)), loses significant accuracy for large arguments, and
 * may return results with only 15 to 16 good bits (out of 24). The present
 * implementation limits the error to about 2 ulps across the entire argument
 * range. It does so by employing an extended precision representation for
 * ln(2) which is composited from ln2_hi = 0.6931457519f which provides the
 * most significant 16-bit of ln(2), and ln2_lo = 1.4286067653e-6f, which
 * provides the least significant 24 bits.
 */
static __forceinline__ float __internal_expf_kernel(float a, float scale)
{
  float j, z;

  j = truncf(a * CUDART_L2E_F);
  z = __internal_fmad (j, -0.6931457519f,    a);
  z = __internal_fmad (j, -1.4286067653e-6f, z);
  z = z * CUDART_L2E_F;
  z = exp2f(z) * exp2f(j + scale);
  return z;
}

static __forceinline__ float __internal_accurate_expf(float a)
{
  float z;

  z = __internal_expf_kernel(a, 0.0f);
  if (a < -105.0f) z = 0.0f;
  if (a >  105.0f) z = CUDART_INF_F;
  return z;
}

static __forceinline__ float __internal_accurate_exp10f(float a)
{
  float j, z;

  j = truncf(a * CUDART_L2T_F);
  z = __internal_fmad (j, -3.0102920532226563e-001f, a);
  z = __internal_fmad (j, -7.9034171557301747e-007f, z);
  z = z * CUDART_L2T_F;
  z = exp2f(z) * exp2f(j);
  if (a < -46.0f) z = 0.0f;
  if (a >  46.0f) z = CUDART_INF_F;
  return z;
}

static __forceinline__ float __internal_lgammaf_pos(float a)
{
  float sum;
  float s, t;

  if (a == CUDART_INF_F) {
    return a;
  }
  if (a >= 3.0f) {
    if (a >= 7.8f) {
      /* Stirling approximation for a >= 8; coefficients from Hart et al, 
       * "Computer Approximations", Wiley 1968. Approximation 5401
       */
      s = __fdividef (1.0f, a);
      t = s * s;
      sum =                           0.77783067e-3f;
      sum = __internal_fmad (sum, t, -0.2777655457e-2f);
      sum = __internal_fmad (sum, t,  0.83333273853e-1f);
      sum = __internal_fmad (sum, s,  0.918938533204672f);
      s = 0.5f * __internal_accurate_logf(a);
      t = a - 0.5f;
      s = s * t;
      t = s - a;
      s = __fadd_rn(s, sum); /* prevent FMAD merging */
      t = t + s;
      return t;
    } else {
      a = a - 3.0f;
      s =                        -7.488903254816711E+002f;
      s = __internal_fmad (s, a, -1.234974215949363E+004f);
      s = __internal_fmad (s, a, -4.106137688064877E+004f);
      s = __internal_fmad (s, a, -4.831066242492429E+004f);
      s = __internal_fmad (s, a, -1.430333998207429E+005f);
      t =                     a - 2.592509840117874E+002f;
      t = __internal_fmad (t, a, -1.077717972228532E+004f);
      t = __internal_fmad (t, a, -9.268505031444956E+004f);
      t = __internal_fmad (t, a, -2.063535768623558E+005f);
      t = __fdividef (s, t);
      t = t + a;
      return t;
    }
  } else if (a >= 1.5f) {
    a = a - 2.0f;
    t =                         4.959849168282574E-005f;
    t = __internal_fmad (t, a, -2.208948403848352E-004f);
    t = __internal_fmad (t, a,  5.413142447864599E-004f);
    t = __internal_fmad (t, a, -1.204516976842832E-003f);
    t = __internal_fmad (t, a,  2.884251838546602E-003f);
    t = __internal_fmad (t, a, -7.382757963931180E-003f);
    t = __internal_fmad (t, a,  2.058131963026755E-002f);
    t = __internal_fmad (t, a, -6.735248600734503E-002f);
    t = __internal_fmad (t, a,  3.224670187176319E-001f);
    t = __internal_fmad (t, a,  4.227843368636472E-001f);
    t = t * a;
    return t;
  } else if (a >= 0.7f) {
    a = 1.0f - a;
    t =                        4.588266515364258E-002f;
    t = __internal_fmad (t, a, 1.037396712740616E-001f);
    t = __internal_fmad (t, a, 1.228036339653591E-001f);
    t = __internal_fmad (t, a, 1.275242157462838E-001f);
    t = __internal_fmad (t, a, 1.432166835245778E-001f);
    t = __internal_fmad (t, a, 1.693435824224152E-001f);
    t = __internal_fmad (t, a, 2.074079329483975E-001f);
    t = __internal_fmad (t, a, 2.705875136435339E-001f);
    t = __internal_fmad (t, a, 4.006854436743395E-001f);
    t = __internal_fmad (t, a, 8.224669796332661E-001f);
    t = __internal_fmad (t, a, 5.772156651487230E-001f);
    t = t * a;
    return t;
  } else {
    t =                         3.587515669447039E-003f;
    t = __internal_fmad (t, a, -5.471285428060787E-003f);
    t = __internal_fmad (t, a, -4.462712795343244E-002f);
    t = __internal_fmad (t, a,  1.673177015593242E-001f);
    t = __internal_fmad (t, a, -4.213597883575600E-002f);
    t = __internal_fmad (t, a, -6.558672843439567E-001f);
    t = __internal_fmad (t, a,  5.772153712885004E-001f);
    t = t * a;
    t = __internal_fmad (t, a, a);
    return -__internal_accurate_logf(t);
  }
}

/* approximate sine on -pi/4...+pi/4 */
static __forceinline__ float __internal_sin_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z  =                         -1.95152959e-4f;
  z  = __internal_fmad (z, x2,  8.33216087e-3f);
  z  = __internal_fmad (z, x2, -1.66666546e-1f);
  z  = z * x2;
  z  = __internal_fmad (z, x, x);
  return z;
}

/* approximate cosine on -pi/4...+pi/4 */
static __forceinline__ float __internal_cos_kernel(float x)
{
  float x2, z;

  x2 = x * x;
  z  =                          2.44331571e-5f;
  z  = __internal_fmad (z, x2, -1.38873163e-3f);
  z  = __internal_fmad (z, x2,  4.16666457e-2f);
  z  = __internal_fmad (z, x2, -5.00000000e-1f);
  z  = __internal_fmad (z, x2,  1.00000000e+0f);
  return z;
}

static __forceinline__ float __internal_accurate_sinf(float a)
{
  float z;
  int   i;

  if ((__isinff(a)) || (a == CUDART_ZERO_F)) {
    return __fmul_rn (a, CUDART_ZERO_F);
  }
  z = __internal_trig_reduction_kernel(a, &i);
  /* here, abs(z) <= pi/4, and i has the quadrant */
  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

static __forceinline__ float sinf(float a)
{
#if defined(__USE_FAST_MATH__)
  return __sinf(a);
#else /* __USE_FAST_MATH__ */
  return __internal_accurate_sinf(a);
#endif /* __USE_FAST_MATH__ */
}

static __forceinline__ float sinpif(float a)
{
  float z;
  int   i;

  if ((__isinff(a)) || (a == CUDART_ZERO_F)) {
    return __fmul_rn (a, CUDART_ZERO_F);
  }
  if (a == floorf(a)) {
    return __int_as_float(__float_as_int(a) & 0x80000000);
  }
  i = (int)rintf (a * 2.0f);
  z = __internal_fmad ((float)i, -0.5f, a);
  z = z * CUDART_PI_F;
  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
}

static __forceinline__ float cosf(float a)
{
#if defined(__USE_FAST_MATH__)
  return __cosf(a);
#else /* __USE_FAST_MATH__ */
  float z;
  int i;

  if (__isinff(a)) {
    return __fadd_rn (a, -a); /* return NaN */
  }
  z = __internal_trig_reduction_kernel(a, &i);
  /* here, abs(z) <= pi/4, and i has the quadrant */
  i++;
  if (i & 1) {
    z = __internal_cos_kernel(z);
  } else {
    z = __internal_sin_kernel(z);
  }
  if (i & 2) {
    z = -z;
  }
  return z;
#endif /* __USE_FAST_MATH__ */
}

static __forceinline__ float tanf(float a)
{
#if defined(__USE_FAST_MATH__)
  return __tanf(a);
#else /* __USE_FAST_MATH__ */
  float z;
  int   i;

  if (__isinff(a)) {
    return __fadd_rn (a, -a); /* return NaN */
  }
  z = __internal_trig_reduction_kernel(a, &i);
  /* here, abs(z) <= pi/4, and i has the quadrant */
  z = __internal_tan_kernel(z);
  if (i & 1) {
    z = - (1.0f / z);
  }
  return z;
#endif /* __USE_FAST_MATH__ */
}

static __forceinline__ float log2f(float a)
{
#if defined(__USE_FAST_MATH__)
  return __log2f(a);
#else /* __USE_FAST_MATH__ */
  return __internal_accurate_log2f(a);
#endif /* __USE_FAST_MATH__ */
}

static __forceinline__ float expf(float a)
{
#if defined(__USE_FAST_MATH__)
  return __expf(a);
#else /* __USE_FAST_MATH__ */
  return __internal_accurate_expf(a);
#endif /* __USE_FAST_MATH__ */
}

static __forceinline__ float exp10f(float a)
{
#if defined(__USE_FAST_MATH__)
  return __exp10f(a);
#else /* __USE_FAST_MATH__ */
  return __internal_accurate_exp10f(a);
#endif /* __USE_FAST_MATH__ */
}

static __forceinline__ float coshf(float a)
{
  float z;

  a = fabsf(a);
  z = __internal_expf_kernel(a, -2.0f);
  z = __internal_fmad (2.0f, z,  __fdividef (0.125f, z));
  if (a >= 90.0f) {
    z = CUDART_INF_F;     /* overflow -> infinity */
  }
  return z;
}

static __forceinline__ float sinhf(float a)
{
  float s, z;

  s = a;
  a = fabsf(a);
  if (a >= 1.0f) {         /* no danger of catastrophic cancellation */
    z = __internal_expf_kernel(a, -2.0f);
    z = __internal_fmad (2.0f, z, -__fdividef (0.125f, z));
    if (a >= 90.0f) {
      z = CUDART_INF_F;     /* overflow -> infinity */
    }
    z =  __int_as_float(__float_as_int(z) | (__float_as_int(s) & 0x80000000));
  } else {
    float a2 = s * s;
    /* approximate sinh(x) on [0,1] with a polynomial */
    z =                         2.816951222e-6f;
    z = __internal_fmad (z, a2, 1.983615978e-4f);
    z = __internal_fmad (z, a2, 8.333350058e-3f);
    z = __internal_fmad (z, a2, 1.666666650e-1f);
    z = z * a2;
    z = __internal_fmad (z, s, s);
  }
  return z;
}

static __forceinline__ float tanhf(float a)
{
  float s, t;

  t = fabsf(a);
  if (t >= 0.55f) {
    s = 1.0f - __fdividef(2.0f,(__internal_expf_kernel(2.0f * t, 0.0f)+1.0f));
    if (t >= 88.0f) {
      s = 1.0f;
    }
    s = __int_as_float(__float_as_int(s) | (__float_as_int(a) & 0x80000000));
  } else {
    float z2;
    z2 = a * a;
    t =                          1.643758066599993e-2f;
    t = __internal_fmad (t, z2, -5.267181327760551e-2f);
    t = __internal_fmad (t, z2,  1.332072505223051e-1f);
    t = __internal_fmad (t, z2, -3.333294663641083e-1f);
    t = t * z2;
    s = __internal_fmad (t, a, a);
    if (a == 0.0f) {   /* preserve negative zero */
      s = a + a;
    }
  }
  return s;
}

static __forceinline__ float atan2f(float a, float b)
{
  float t0, t1, fa, fb;

  fb = fabsf(b);
  fa = fabsf(a);
  if ((fa == 0.0f) && (fb == 0.0f)) {
    t0 = (__float_as_int(b) < 0) ? CUDART_PI_F : CUDART_ZERO_F;
    t0 = __int_as_float(__float_as_int(t0) | (__float_as_int(a) & 0x80000000));
  } else if ((fa == CUDART_INF_F) && (fb == CUDART_INF_F)) {
    t0 = (__float_as_int(b) < 0) ? CUDART_3PIO4_F : CUDART_PIO4_F;
    t0 = __int_as_float(__float_as_int(t0) | (__float_as_int(a) & 0x80000000));
  } else {
    /* reduce arguments to first octant */
    /* t0 = (|a| < |b|) ? (|a| / |b|) : (|a| / |b|) */
    t0 = fminf(fa, fb);
    t1 = fmaxf(fa, fb);
    t0 = t0 / t1;
    t0 = __internal_atanf_kernel(t0);
    /* Map result according to octant. */
    if (fa > fb) t0 = CUDART_PIO2_F - t0;
    if (b < 0.0f) t0 = CUDART_PI_F - t0;
    t0 = __int_as_float(__float_as_int(t0) | (__float_as_int(a) & 0x80000000));
    t1 = a + b;
    if (!(t1 <= CUDART_INF_F)) {
      /* fixup result in case of NaN inputs */
        t0 = t1;
    }
  }
  return t0;
}

static __forceinline__ float atanf(float a)
{
  float t0, t1;

  /* reduce argument to first octant */
  t0 = fabsf(a);
  t1 = t0;
  if (t0 > 1.0f) {
    t1 = 1.0f / t1;
  }
  /* approximate atan(a) in first octant */
  t1 = __internal_atanf_kernel(t1);
  /* map result according to octant. */
  if (t0 > 1.0f) {
    t1 = CUDART_PIO2_F - t1;
  }
  if (t0 <= CUDART_INF_F) {
    t1 = __int_as_float(__float_as_int(t1) | (__float_as_int(a) & 0x80000000));
  }
  return t1;
}

/* approximate asin(a) on [0, 0.57] */
static __forceinline__ float __internal_asinf_kernel(float a)
{
  float a2, t;
  a2 = a * a;
  t =                         5.175137819e-002f;
  t = __internal_fmad (t, a2, 1.816697683e-002f);
  t = __internal_fmad (t, a2, 4.675685871e-002f);
  t = __internal_fmad (t, a2, 7.484657646e-002f);
  t = __internal_fmad (t, a2, 1.666701424e-001f);
  t = t * a2;
  a = __internal_fmad (t, a, a);
  return a;
}

static __forceinline__ float asinf(float a)
{
  float t0, t1, t2;

  t0 = fabsf(a);
  t2 = 1.0f - t0;
  t2 = 0.5f * t2;
  t2 = sqrtf(t2);
  t1 = t0 > 0.57f ? t2 : t0;
  t1 = __internal_asinf_kernel(t1);
  t2 = __internal_fmad (-2.0f, t1, CUDART_PIO2_F);
  if (t0 > 0.57f) {
    t1 = t2;
  }
  if (t1 <= CUDART_INF_F) {
    t1 = __int_as_float(__float_as_int(t1) | (__float_as_int(a) & 0x80000000));
  }
  return t1;
}

static __forceinline__ float acosf(float a)
{
  float t0, t1, t2;

  t0 = fabsf(a);
  t2 = 1.0f - t0;
  t2 = 0.5f * t2;
  t2 = sqrtf(t2);
  t1 = t0 > 0.57f ? t2 : t0;
  t1 = __internal_asinf_kernel(t1);
  t1 = t0 > 0.57f ? 2.0f * t1 : CUDART_PIO2_F - t1;
  if (__float_as_int(a) < 0) {
    t1 = CUDART_PI_F - t1;
  }
  return t1;
}

static __forceinline__ float logf(float a)
{
#if defined(__USE_FAST_MATH__)
  return __logf(a);
#else /* __USE_FAST_MATH__ */
  return __internal_accurate_logf(a);
#endif /* __USE_FAST_MATH__ */
}

static __forceinline__ float log10f(float a)
{
#if defined(__USE_FAST_MATH__)
  return __log10f(a);
#else /* __USE_FAST_MATH__ */
  return CUDART_LGE_F * __internal_accurate_logf(a);
#endif /* __USE_FAST_MATH__ */
}

static __forceinline__ float log1pf(float a)
{
  float t;
  if (a >= -0.394f && a <= 0.65f) {
    /* log(a+1) = 2*atanh(a/(a+2)) */
    t = a + 2.0f;
    t = __fdividef (a, t);
    t = -a * t;
    t = __internal_atanhf_kernel (a, t);
  } else {
    t = __internal_accurate_logf (CUDART_ONE_F + a);
  }
  return t;
}

static __forceinline__ float acoshf(float a)
{
  float t;

  t = a - 1.0f;
  if (fabsf(t) > CUDART_TWO_TO_23_F) {
    /* for large a, acosh = log(2*a) */
    return CUDART_LN2_F + __internal_accurate_logf(a);
  } else {
    t = t + sqrtf(__fadd_rn(__fmul_rz(a, t), t));
    return log1pf(t);
  }
}

static __forceinline__ float asinhf(float a)
{
  float fa, oofa, t;

  fa = fabsf(a);
  if (fa > CUDART_TWO_TO_126_F) {   /* prevent intermediate underflow */
    t = CUDART_LN2_F + __logf(fa);  /* fast version is safe here */
  } else {
    oofa = 1.0f / fa;
    t =fa+__fdividef (fa,(oofa+sqrtf(__internal_fmad(oofa,oofa,1.0f))));
    t = log1pf(t);
  }
  if (fa <= CUDART_INF_F) {
    t = __int_as_float(__float_as_int(t) | (__float_as_int(a) & 0x80000000));
  }
  return t;
}

static __forceinline__ float atanhf(float a)
{
  float fa, t;

  fa = fabsf(a);
  t = __fdividef ((2.0f * fa), (1.0f - fa));
  t = 0.5f * log1pf(t);
  if (fabsf(t) <= CUDART_INF_F) {
    t = __int_as_float(__float_as_int(t) | (__float_as_int(a) & 0x80000000));
  }
  return t;
}

static __forceinline__ float expm1f(float a)
{
  float t, z, j, u;
  /* expm1(a) = 2^t*(expm1(z)+1)-1 */
  t = rintf (a * CUDART_L2E_F);
  /* prevent loss of accuracy for args a tad outside [-0.5*log(2),0.5*log(2)]*/
  if (fabsf(a) < 0.41f) {
    t = CUDART_ZERO_F;
  }  
  z = __internal_fmad (-t, 0.6931457519f, a);
  z = __internal_fmad (-t, 1.4286067653e-6f, z);
  /* prevent intermediate overflow in computation of 2^t */
  j = t;
  if (t == 128.0f) j = j - 1.0f; 
  /* expm1(z) on [log(2/3), log(3/2)] */
  u =                        1.38795078474044430E-003f;
  u = __internal_fmad (u, z, 8.38241261853264930E-003f);
  u = __internal_fmad (u, z, 4.16678317762833940E-002f);
  u = __internal_fmad (u, z, 1.66663978874356580E-001f);
  u = __internal_fmad (u, z, 4.99999940395997040E-001f);
  u = u * z;
  u = __internal_fmad (u, z, z);
  /* 2^j*[exmp1(z)+1]-1 = 2^j*expm1(z)+2^j-1 */
  z = exp2f (j);
  u = __internal_fmad (u, z, z - 1.0f);
  if (t == 128.0f) u = u + u; /* work around intermediate overflow */
  /* handle massive overflow and underflow */
  if (j > 128.0f) u = CUDART_INF_F;
  if (j < -25.0f) u = -1.0f;
  /* take care of denormal and zero inputs */
  if (a == 0.0f) {
    u = __int_as_float(__float_as_int(a) & 0x80000000);
  }
  return u;
}

static __forceinline__ float hypotf(float a, float b)
{
  float v, w, s, t, fa, fb;

  fa = fabsf(a);
  fb = fabsf(b);
  v = s = fmaxf(fa, fb);
  w = t = fminf(fa, fb);
  if (v > CUDART_TWO_TO_126_F) {
    s = s * 0.25f;
    t = t * 0.25f;
  }
  t = __fdividef(t, s);
  t = __internal_fmad (t, t, 1.0f);
  t = v * sqrtf(t);
  if (v == 0.0f) {
    t = v + w;         /* fixup for zero divide */
  }
  if ((!(fa <= CUDART_INF_F)) || (!(fb <= CUDART_INF_F))) {
    t = a + b;         /* fixup for NaNs */
  }
  if (v == CUDART_INF_F) {
    t = v + w;         /* fixup for infinities */
  }
  return t;
}

static __forceinline__ float cbrtf(float a)
{
  float s, t;

  s = fabsf(a);
  t = exp2f(CUDART_THIRD_F * __log2f(s));           /* initial approx */
  t = t - (t - (__fdividef (s, t * t))) * CUDART_THIRD_F;  /* refine approx */
  if (__float_as_int(a) < 0) {
    t = -t;
  }
  s = a + a;
  if (s == a) t = s; /* handle special cases */
  return t;
}

static __forceinline__ float rcbrtf(float a)
{
  float s, t;

  s = fabsf(a);
  t = exp2f(-CUDART_THIRD_F * __log2f(s));          /* initial approx */
  t = __internal_fmad(__internal_fmad(t*t, -s*t, 1.0f), CUDART_THIRD_F*t, t);
  if (__float_as_int(a) < 0) {
    t = -t;
  }
  s = a + a;
  if (s == a) t = __fdividef (1.0f, a); /* handle special cases */
  return t;
}

static __forceinline__ float erff(float a)
{
  float t, r, q;

  t = fabsf(a);
  if (t >= 1.0f) { 
    /* coefficients from Hastings, "Approximations for Digital Computers",
     * Princeton University Press 1955. Sheet 45.
     */
    q = __internal_fmad (t, 0.3275911f, 1.0f);
    q = 1.0f / q;
    r =                         1.061405429f;
    r = __internal_fmad (r, q, -1.453152027f);
    r = __internal_fmad (r, q,  1.421413741f);
    r = __internal_fmad (r, q, -0.284496736f);
    r = __internal_fmad (r, q,  0.254829592f);
    r = r * q;
    q = __internal_expf_kernel(-a * a, 0.0f);
    r = __internal_fmad (-q, r, 1.0f);
    if (t >= 5.5f) {
      r = 1.0f;
    }
    a = __int_as_float (__float_as_int(r) | (__float_as_int(a) & 0x80000000));
  } else {
    t = a * a;
    r =                        -5.58510127926029810E-004f;
    r = __internal_fmad (r, t,  4.90688891415893070E-003f);
    r = __internal_fmad (r, t, -2.67027980930150640E-002f);
    r = __internal_fmad (r, t,  1.12799056505903940E-001f);
    r = __internal_fmad (r, t, -3.76122956138427440E-001f);
    r = __internal_fmad (r, t,  1.12837911712623450E+000f);
    a = a * r;
  }
  return a;
}

/* 
 * This implementation of erfinvf() adopts algorithmic techniques from a 
 * variety of sources. The transformation of the argument into log space 
 * follows Strecok [1], the transformation of the argument into reciprocal 
 * square root space for arguments near unity follows Blair et. al. [2], 
 * and the aggressive widening of the primary approximation interval around 
 * zero to minimize divergence as well as the use of a CUDA device function 
 * for the computation of the logarithm follows work by professor Mike Giles 
 * (Oxford University, UK). 
 * 
 * [1] Anthony J. Strecok, On the Calculation of the Inverse of the Error 
 * Function. Mathematics of Computation, Vol. 22, No. 101 (Jan. 1968), 
 * pp. 144-158 
 * [2] J. M. Blair, C. A. Edwards and J. H. Johnson, Rational Chebyshev 
 * Approximations for the Inverse of the Error Function. Mathematics 
 * of Computation, Vol. 30, No. 136 (Oct. 1976), pp. 827-830 
 */ 
static __forceinline__ float erfinvf(float a)
{
  float s, t, r;

#if __CUDA_ARCH__ >= 200
  s = __fmaf_rn (a, -a, 1.0f);
#else
  s = 1.0f + a;
  t = 1.0f - a;
  s = s * t;
#endif
  t = - __log2f (s);
  if (t > 8.2f) {
    t = rsqrtf (t);
    r =                        -5.8991436871681446E-001f;
    r = __internal_fmad (r, t, -6.6300422537735360E-001f);
    r = __internal_fmad (r, t,  1.5970110948817704E+000f);
    r = __internal_fmad (r, t, -6.7521557026467416E-001f);
    r = __internal_fmad (r, t, -9.5224791160399669E-002f);
    r = __internal_fmad (r, t,  8.3535343797791939E-001f);
    t = 1.0f / t;
    t = r * t;
    if (a < 0.0f) t = -t;
    return t;
  } else {
    r =                        -2.5172707606685652E-010f; 
    r = __internal_fmad (r, t,  9.4274289432374619E-009f); 
    r = __internal_fmad (r, t, -1.2054753059594516E-007f); 
    r = __internal_fmad (r, t,  2.1697004698667657E-007f); 
    r = __internal_fmad (r, t,  8.0621488510822390E-006f); 
    r = __internal_fmad (r, t, -3.1675491789646913E-005f); 
    r = __internal_fmad (r, t, -7.7436312951712784E-004f); 
    r = __internal_fmad (r, t,  5.5465877941375773E-003f); 
    r = __internal_fmad (r, t,  1.6082022430967846E-001f); 
    r = __internal_fmad (r, t,  8.8622690039402130E-001f); 
    return r * a;
  }
}

static __forceinline__ float erfcf(float a)
{
  if (a <= 0.813f) {
    return 1.0f - erff(a);
  } else {
    float p;
    float q;
    float h;
    float l;
    float t;

    /* On the interval [0.813, 10.055] the following approximation is used:
       erfc(a) = (1.0 + 1/a * r(1/a)) * 1/a * 0.5 * exp(-a*a), where the range 
       of r(1/a) is approximately [-0.12, 0.27]. r(1/a) is computed by rational
       approximation. Problematic is the accurate computation of exp(-a*a).
       Despite the accuracy-enhancing techniques being used, this computation
       adds almost 3 ulps to the total error for compute capability < sm_20.
       IEEE-rounded divisions don't help improve the accuracy of the rational
       approximation, so force approximate operations for best performance.
    */
    t = __fdividef(1.0f, a);

    p =                        - 9.9910025099425892E-001f;
    p = __internal_fmad (p, t, - 2.6108451215634448E-001f);
    p = __internal_fmad (p, t, + 1.2460347155371844E-001f);
    p = __internal_fmad (p, t, + 1.3243909814778765E-001f);
    p = __internal_fmad (p, t, + 3.3477599162629441E-002f);
    q =                     t  + 2.2542670016875404E+000f;
    q = __internal_fmad (q, t, + 2.1514433559696009E+000f);
    q = __internal_fmad (q, t, + 1.0284106806050302E+000f);
    q = __internal_fmad (q, t, + 2.6094298761636442E-001f);
    q = __internal_fmad (q, t, - 3.9951461024063317E-006f);
    
    p = __fdividef(p, q);
    p = p * t;

#if __CUDA_ARCH__ < 200
    h = __int_as_float(__float_as_int(a) & 0xfffff000);
    l = a - h;
    q = -h * h;
    q = __internal_expf_kernel(q, 0.0f);
    h = a + h;
    l = l * h;
    h = __internal_expf_kernel(-l, -1.0f);
    q = q * h;
#else /* __CUDA_ARCH__ < 200 */
    h = -a * a;
    l = __fmaf_rn (a, a, h);
    q = __internal_expf_kernel(h, -1.0f);
    q = __fmaf_rn (q, -l, q);
#endif /* __CUDA_ARCH__ < 200 */
    p = __internal_fmad (p, q, q);
    p = p * t;
    if (a > 10.055f) {
      p = 0.0f;
    }
    return p;
  }
}

static __forceinline__ float erfcinvf(float a)
{
  float t;
  if (a <= 0.0f) {
    t = rsqrtf (__int_as_float (0xffc00000));  /* NaN */
    if (a == 0.0f) {
      t = (1.0f - a) * CUDART_INF_F;
    }
  } 
  else if (a >= 0.0625f) {
    t = erfinvf (1.0f - a);
  }
  else {
    float p, q;
    t = __internal_accurate_logf(a);
    t = rsqrtf(-t);
    p =                        -1.64441567910e-1f;
    p = __internal_fmad (p, t,  6.80544246825e-1f);
    p = __internal_fmad (p, t, -1.12808139162e+0f);
    p = __internal_fmad (p, t,  6.90969348887e-1f);
    p = __internal_fmad (p, t,  1.38271964963e+0f);
    p = __internal_fmad (p, t,  1.55047000312e-1f);
    q =                     t + 1.38522814199e+0f;
    q = __internal_fmad (q, t,  1.55024849822e-1f);
    q = q * t;
    t = __fdividef (p, q);
  }
  return t;
}

static __forceinline__ float lgammaf(float a)
{
  float t;
  float i;
  int quot;
  t = __internal_lgammaf_pos(fabsf(a));
  if (a >= 0.0f) return t;
  a = fabsf(a);
  i = floorf(a);                   
  if (a == i) return CUDART_INF_F; /* a is an integer: return infinity */
  if (a < 1e-19f) return -__internal_accurate_logf(a);
  i = rintf (2.0f * a);
  quot = (int)i;
  i = __internal_fmad (-i, 0.5f, a);
  i = i * CUDART_PI_F;
  if (quot & 1) {
    i = __internal_cos_kernel(i);
  } else {
    i = __internal_sin_kernel(i);
  }
  i = fabsf(i);
  t = CUDART_LNPI_F - __internal_accurate_logf(i * a) - t;
  return t;
}

static __forceinline__ float ldexpf(float a, int b)
{
  float fa = fabsf(a);

  if ((fa == CUDART_ZERO_F) || (fa == CUDART_INF_F) || (b == 0)) {
    if (!(fa > CUDART_ZERO_F)) a = a + a;
    return a;
  } else if (abs(b) < 126) {
    return a * exp2f((float)b);
  } else if (abs(b) < 252) {
    int bhalf = b / 2;
    return a * exp2f((float)bhalf) * exp2f((float)(b - bhalf));
  } else {
    int bquarter = b / 4;
    float t = exp2f((float)bquarter);
    return a * t * t * t * exp2f((float)(b - 3 * bquarter));
  }
}

static __forceinline__ float scalbnf(float a, int b)
{
  /* On binary systems, ldexp(x,exp) is equivalent to scalbn(x,exp) */
  return ldexpf(a, b);
}

static __forceinline__ float scalblnf(float a, long int b)
{
  int t;
  if (b > 2147483647L) {
    t = 2147483647;
  } else if (b < (-2147483647 - 1)) {
    t = (-2147483647 - 1);
  } else {
    t = (int)b;
  }
  return scalbnf(a, t);
}

static __forceinline__ float frexpf(float a, int *b)
{
  float fa = fabsf(a);
  unsigned int expo;
  unsigned int denorm;

  if (fa < CUDART_TWO_TO_M126_F) {
    a *= CUDART_TWO_TO_24_F;
    denorm = 24;
  } else {
    denorm = 0;
  }
  expo = ((__float_as_int(a) >> 23) & 0xff);
  if ((fa == 0.0f) || (expo == 0xff)) {
    expo = 0;
    a = a + a;
  } else {  
    expo = expo - denorm - 126;
    a = __int_as_float(((__float_as_int(a) & 0x807fffff) | 0x3f000000));
  }
  *b = expo;
  return a;
}

static __forceinline__ float modff(float a, float *b)
{
  float t;
  if (__finitef(a)) {
    t = truncf(a);
    *b = t;
    t = a - t;
    t = __int_as_float(__float_as_int(t) | (__float_as_int(a) & 0x80000000));
    return t;
  } else if (__isinff(a)) {
    *b = a;
    return __int_as_float(__float_as_int(a) & 0x80000000);
  } else {
    *b = a + a; 
    return a + a;
  }
}

static __forceinline__ float fmodf(float a, float b)
{
  float orig_a = a;
  float orig_b = b;
  a = fabsf(a);
  b = fabsf(b);
  if (!((a <= CUDART_INF_F) && (b <= CUDART_INF_F))) {
    return orig_a + orig_b;
  }
  if ((a == CUDART_INF_F) || (b == CUDART_ZERO_F)) {
    return rsqrtf (__int_as_float (0xffc00000));
  } else if (a >= b) {
#if !defined(__CUDA_FTZ)
    /* Need to be able to handle denormals correctly */
    int expoa = (a < CUDART_TWO_TO_M126_F) ? 
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < CUDART_TWO_TO_M126_F) ? 
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }
#else /* !defined(__CUDA_FTZ) */
    float scaled_b = __int_as_float ((__float_as_int(b) & 0x007fffff) | 
                                     (__float_as_int(a) & 0x7f800000));
    if (scaled_b > a) {
      scaled_b *= 0.5f;
    }
#endif /* !defined(__CUDA_FTZ) */
    while (scaled_b >= b) {
      if (a >= scaled_b) {
        a -= scaled_b;
      }
      scaled_b *= 0.5f;
    }
    return __int_as_float (__float_as_int(a) | 
                           (__float_as_int(orig_a) & 0x80000000));
  } else {
    if (!(a > CUDART_ZERO_F)) orig_a = orig_a + orig_a;
    return orig_a;
  }
}

static __forceinline__ float remainderf(float a, float b)
{

  float twoa = 0.0f;
  unsigned int quot0 = 0;  /* quotient bit 0 */
  float orig_a = a;
  float orig_b = b;

  a = fabsf(a);
  b = fabsf(b);
  if (!((a <= CUDART_INF_F) && (b <= CUDART_INF_F))) {
    return orig_a + orig_b;
  }
  if ((a == CUDART_INF_F) || (b == CUDART_ZERO_F)) {
    return rsqrtf (__int_as_float (0xffc00000));
  } else if (a >= b) {
#if !defined(__CUDA_FTZ)
    int expoa = (a < CUDART_TWO_TO_M126_F) ? 
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < CUDART_TWO_TO_M126_F) ? 
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }
#else
    float scaled_b = __int_as_float ((__float_as_int(b) & 0x007fffff) | 
                                     (__float_as_int(a) & 0x7f800000));
    if (scaled_b > a) {
      scaled_b *= 0.5f;
    }
    /* check wether divisor is a power of two */
    if (a == scaled_b) {
      return __int_as_float(__float_as_int(orig_a) & 0x80000000);
    }    
#endif /* !__CUDA_FTZ */
    while (scaled_b >= b) {
      quot0 = 0;
      if (a >= scaled_b) {
        twoa = __internal_fmad (a, 2.0f, -scaled_b) - scaled_b;
        a = a - scaled_b;
        quot0 = 1;
      }
      scaled_b *= 0.5f;
    }
  }
  /* round quotient to nearest even */
#if !defined(__CUDA_FTZ)
  twoa = 2.0f * a;
  if ((twoa > b) || ((twoa == b) && quot0)) {
    a -= b;
    a = __int_as_float(__float_as_int(a) | 0x80000000);
  }
#else
  if (a >= CUDART_TWO_TO_M126_F) {
    twoa = 2.0f * a;
    if ((twoa > b) || ((twoa == b) && quot0)) {
      a -= b;
      a = __int_as_float(__float_as_int(a) | 0x80000000);
    }
  } else {
    /* a already got flushed to zero, so use twoa instead */
    if ((twoa > b) || ((twoa == b) && quot0)) {
      a = 0.5f * __internal_fmad(b, -2.0f, twoa);
      a = __int_as_float(__float_as_int(a) | 0x80000000);
    }
  }
#endif /* !__CUDA_FTZ */
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  return a;
}

static __forceinline__ float remquof(float a, float b, int* quo)
{
  float twoa = 0.0f;
  unsigned int quot = 0;  /* trailing quotient bits */
  unsigned int sign;
  float orig_a = a;
  float orig_b = b;

  /* quo has a value whose sign is the sign of x/y */
  sign = 0 - ((__float_as_int(a) ^ __float_as_int(b)) < 0);
  a = fabsf(a);
  b = fabsf(b);
  if (!((a <= CUDART_INF_F) && (b <= CUDART_INF_F))) {
    *quo = quot;
    return orig_a + orig_b;
  }
  if ((a == CUDART_INF_F) || (b == CUDART_ZERO_F)) {
    *quo = quot;
    return rsqrtf (__int_as_float (0xffc00000));
  } else if (a >= b) {
#if !defined(__CUDA_FTZ)
    /* Need to be able to handle denormals correctly */
    int expoa = (a < CUDART_TWO_TO_M126_F) ? 
        ((int)__log2f(a)) : (((__float_as_int(a) >> 23) & 0xff) - 127);
    int expob = (b < CUDART_TWO_TO_M126_F) ? 
        ((int)__log2f(b)) : (((__float_as_int(b) >> 23) & 0xff) - 127);
    int scale = expoa - expob;
    float scaled_b = ldexpf(b, scale);
    if (scaled_b <= 0.5f * a) {
      scaled_b *= 2.0f;
    }
#else /* !__CUDA_FTZ */
    float scaled_b = __int_as_float ((__float_as_int(b) & 0x007fffff) | 
                                     (__float_as_int(a) & 0x7f800000));
    if (scaled_b > a) {
      scaled_b *= 0.5f;
    }
    /* check wether divisor is a power of two */
    if (a == scaled_b) {
      if (__float_as_int(b) > 0x7e800000) {
          a *= 0.25f;
          b *= 0.25f;
      }
      a = __fdividef(a,b) + 0.5f;
      quot = (a < 8.0f) ? (int)a : 0;
      quot = quot ^ sign;
      quot = quot - sign;
      *quo = quot;
      return __int_as_float(__float_as_int(orig_a) & 0x80000000);
    }    
#endif /* !__CUDA_FTZ */
    while (scaled_b >= b) {
      quot <<= 1;
      if (a >= scaled_b) {
        twoa = (2.0f * a - scaled_b) - scaled_b;
        a -= scaled_b;
        quot += 1;
      }
      scaled_b *= 0.5f;
    }
  }
  /* round quotient to nearest even */
#if !defined(__CUDA_FTZ)
  twoa = 2.0f * a;
  if ((twoa > b) || ((twoa == b) && (quot & 1))) {
    quot++;
    a -= b;
    a = __int_as_float(__float_as_int(a) | 0x80000000);
  }
#else /* !__CUDA_FTZ */
  if (a >= CUDART_TWO_TO_M126_F) {
    twoa = 2.0f * a;
    if ((twoa > b) || ((twoa == b) && (quot & 1))) {
      quot++;
      a -= b;
      a = __int_as_float(__float_as_int(a) | 0x80000000);
    }
  } else {
    /* a already got flushed to zero, so use twoa instead */
    if ((twoa > b) || ((twoa == b) && (quot & 1))) {
      quot++;
      a = 0.5f * (twoa - 2.0f * b);
      a = __int_as_float(__float_as_int(a) | 0x80000000);
    }
  }
#endif /* !__CUDA_FTZ */
  a = __int_as_float((__float_as_int(orig_a) & 0x80000000)^
                     __float_as_int(a));
  quot = quot & CUDART_REMQUO_MASK_F;
  quot = quot ^ sign;
  quot = quot - sign;
  *quo = quot;
  return a;
}

static __forceinline__ float fmaf(float a, float b, float c)
{
  return __fmaf_rn(a, b, c);
}

static __forceinline__ float __internal_accurate_powf(float a, float b)
{
  float2 loga, prod;
  float t;

  /* compute log(a) in double-single format*/
  loga = __internal_log_ep(a);

  /* prevent overflow during extended precision multiply */
  if (fabsf(b) > 1.0e34f) b *= 1.220703125e-4f;
  prod.y = b;
  prod.x = 0.0f;
  prod = __internal_dsmul (prod, loga);

  /* prevent intermediate overflow in exponentiation */
  if (__float_as_int(prod.y) == 0x42b17218) {
    prod.y = __int_as_float(__float_as_int(prod.y) - 1);
    prod.x = prod.x + __int_as_float(0x37000000);
  }

  /* compute pow(a,b) = exp(b*log(a)) */
  t = __internal_accurate_expf(prod.y);
  /* prevent -INF + INF = NaN */
  if (t != CUDART_INF_F) {
    /* if prod.x is much smaller than prod.y, then exp(prod.y+prod.x) ~= 
     * exp(prod.y) + prod.x * exp(prod.y) 
     */
    t = __internal_fmad (t, prod.x, t);
  }
  return t;
}

static __forceinline__ float powif(float a, int b)
{
  unsigned int e = abs(b);
  float r = 1.0f;

  while (1) {
    if ((e & 1) != 0) {
      r = __fmul_rn (r, a);
    }
    e = e >> 1;
    if (e == 0) {
      r = (b < 0) ? 1.0f / r : r;
      return r;
    }
    a = __fmul_rn (a, a);
  }
}

static __forceinline__ double powi(double a, int b)
{
  unsigned int e = abs(b);
  double       r = 1.0;

  while (1) {
    if ((e & 1) != 0) {
      r = r * a;
    }
    e = e >> 1;
    if (e == 0) {
      return b < 0 ? 1.0 / r : r;
    }
    a = a * a;
  }
}

static __forceinline__ float powf(float a, float b)
{
#if defined(__USE_FAST_MATH__)
  return __powf(a, b);
#else /* __USE_FAST_MATH__ */
  int bIsOddInteger;
  float t;
  if (a == 1.0f || b == 0.0f) {
    return 1.0f;
  } 
  if (__isnanf(a) || __isnanf(b)) {
    return a + b;
  }
  if (a == CUDART_INF_F) {
    return (__float_as_int(b) < 0) ? CUDART_ZERO_F : CUDART_INF_F;
  }
  if (__isinff(b)) {
    if (a == -1.0f) {
      return 1.0f;
    }
    t = (fabsf(a) > 1.0f) ? CUDART_INF_F : CUDART_ZERO_F;
    if (b < CUDART_ZERO_F) {
      t = 1.0f / t;
    }
    return t + t;
  }  
  bIsOddInteger = fabsf(b - (2.0f * truncf(0.5f * b))) == 1.0f;
  if (a == CUDART_ZERO_F) {
    t = bIsOddInteger ? a : CUDART_ZERO_F;
    if (b < CUDART_ZERO_F) {
      t = 1.0f / t;
    }
    return t + t;
  } 
  if (a == -CUDART_INF_F) {
    t = - ((b < CUDART_ZERO_F) ? (1.0f / a) : a);
    if (bIsOddInteger) {
      t = __int_as_float(__float_as_int(t) ^ 0x80000000);
    }
    return t;
  } 
  if ((a < CUDART_ZERO_F) && (b != truncf(b))) {
    return rsqrtf(__int_as_float(0xffc00000));
  }
  t = fabsf(a);
  t = __internal_accurate_powf(t, b);
  if ((a < CUDART_ZERO_F) && bIsOddInteger) {
    t = __int_as_float(__float_as_int(t) ^ 0x80000000);
  }
  return t;
#endif /* __USE_FAST_MATH__ */
}

/* approximate 1.0/(x*gamma(x)) on [-0.5,0.5] */
static __forceinline__ float __internal_tgammaf_kernel(float a)
{
  float t;
  t =                        -1.05767296987211380E-003f;
  t = __internal_fmad (t, a,  7.09279059435508670E-003f);
  t = __internal_fmad (t, a, -9.65347121958557050E-003f);
  t = __internal_fmad (t, a, -4.21736613253687960E-002f);
  t = __internal_fmad (t, a,  1.66542401247154280E-001f);
  t = __internal_fmad (t, a, -4.20043267827838460E-002f);
  t = __internal_fmad (t, a, -6.55878234051332940E-001f);
  t = __internal_fmad (t, a,  5.77215696929794240E-001f);
  t = __internal_fmad (t, a,  1.00000000000000000E+000f);
  return t;
}

/* Based on: Kraemer, W.: "Berechnung der Gammafunktion G(x) fuer reelle Punkt-
   und Intervallargumente". Zeitschrift fuer angewandte Mathematik und 
   Mechanik, Vol. 70 (1990), No. 6, pp. 581-584
*/
static __forceinline__ float tgammaf(float a)
{
  float s, xx, x=a;
  if (x >= 0.0f) {
    if (x > 36.0f) x = 36.0f; /* clamp */
    s = 1.0f;
    xx = x;
    if (x > 34.03f) { /* prevent premature overflow */
      xx -= 1.0f;
    }
    while (xx > 1.5f) {
      xx = xx - 1.0f;
      s = s * xx;
    }
    if (x >= 0.5f) {
      xx = xx - 1.0f;
    }
    xx = __internal_tgammaf_kernel(xx);
    if (x < 0.5f) {
      xx = xx * x;
    }
    s = __fdividef(s, xx);
    if (x > 34.03f) {
      /* Cannot use s = s * x - s due to intermediate overflow! */
      xx = x - 1.0f;
      s = s * xx;
    }
    return s;
  } else {
    if (x == floorf(x)) {  /* x is negative integer */
      x = rsqrtf (__int_as_float (0xffc00000));  /* NaN */
    } 
    if (x < -41.1f) x = -41.1f; /* clamp */
    xx = x;
    if (x < -34.03f) {   /* prevent overflow in intermediate result */        
      xx += 6.0f;
    } 
    s = xx;
    while (xx < -0.5f) {
      xx = xx + 1.0f;
      s = s * xx;
    }
    xx = __internal_tgammaf_kernel(xx);
    s = s * xx;
    s = 1.0f / s;
    if (x < -34.03f) {
      xx = x;
      xx *= (x + 1.0f);
      xx *= (x + 2.0f);
      xx *= (x + 3.0f);
      xx *= (x + 4.0f);
      xx *= (x + 5.0f);
      xx = 1.0f / xx;
      s = s * xx;
      if ((a < -42.0f) && !(((int)a)&1)) {
        s = CUDART_NEG_ZERO_F;
      }
    }    
    return s;
  }
}

static __forceinline__ float roundf(float a)
{
  float fa = fabsf(a);
  float u = __int_as_float (0x3f000000 | (__float_as_int(a) & 0x80000000));
  u = truncf (a + u);
  if (fa > CUDART_TWO_TO_23_F) u = a;
  if (fa < 0.5f) u = truncf (a);
  return u;
}

static __forceinline__ long long int __internal_llroundf_kernel(float a)
{
  unsigned long long int res, t = 0ULL;
  int shift;
  unsigned int ia = __float_as_int(a);
  /* Make NaN response identical to the hardware response for llrintf() */
  if ((ia << 1) > 0xff000000) return 0x8000000000000000LL;
  if ((int)ia >= 0x5f000000) return 0x7fffffffffffffffLL;
  if (ia >= 0xdf000000) return 0x8000000000000000LL;
  shift = 189 - ((ia >> 23) & 0xff);
  res = ((long long int)(((ia << 8) | 0x80000000) >> 1)) << 32;
  if (shift >= 64) {
    t = res;
    res = 0;
  } else if (shift) {
    t = res << (64 - shift);
    res = res >> shift;
  }
  if (t >= 0x8000000000000000ULL) {
    res++;
  }
  if ((int)ia < 0) res = (unsigned long long int)(-(long long int)res);
  return (long long int)res;
}

static __forceinline__ long long int llroundf(float a)
{
  return __internal_llroundf_kernel(a);
}

static __forceinline__ long int lroundf(float a)
{
#if defined(__LP64__)
  return (long int)llroundf(a);
#else /* __LP64__ */
  return (long int)(roundf(a));
#endif /* __LP64__ */
}

static __forceinline__ float fdimf(float a, float b)
{
  float t;
  t = a - b;    /* default also handles NaNs */
  if (a <= b) {
    t = 0.0f;
  }
  return t;
}

static __forceinline__ int ilogbf(float a)
{
  unsigned int i;
  int expo;
  float fa;
  fa = fabsf(a);
  i = __float_as_int(fa);
  if (i < 0x00800000) {
    /* handle zero and denormals */
    expo = -118 - __clz(i);
    if (i == 0x00000000) {
      expo = -__cuda_INT_MAX-1;
    }
  } else {
    expo = ((int)((i >> 23) & 0xff)) - 127;
    if ((i == 0x7f800000)) {
      expo = __cuda_INT_MAX;
    }
    if ((i > 0x7f800000)) {
      expo = -__cuda_INT_MAX-1;
    }
  } 
  return expo;
}

static __forceinline__ float logbf(float a)
{
  unsigned int i;
  int expo;
  float fa, res;
  fa = fabsf(a);
  i = __float_as_int(fa);
  if (i < 0x00800000) {
    /* handle zero and denormals */
    expo = -118 - __clz(i);
    res = (float)expo;
    if (a == 0.0f) {
      res = -CUDART_INF_F;
    }
  } else {
    expo = ((int)((i >> 23) & 0xff)) - 127;
    res = (float)expo;
    if ((i >= 0x7f800000)) {  
      /* return +INF or NaN */
      res = a * a;
    }
  } 
  return res;
}

static __forceinline__ void sincosf(float a, float *sptr, float *cptr)
{
#if defined(__USE_FAST_MATH__)
  __sincosf(a, sptr, cptr);
#else /* __USE_FAST_MATH__ */
  float t, s, c;
  volatile float t2, u2;
  int quadrant;
  t = fabsf(a);
  if ((t == CUDART_INF_F) || (t == CUDART_ZERO_F)) {
    s = __fmul_rn (a, CUDART_ZERO_F); /* generate NaN, zero */
    c = 1.0f + s;                     /* generate NaN, one */
    *sptr = s;
    *cptr = c;
    return;
  }
  t = __internal_trig_reduction_kernel(a, &quadrant);
  u2 = __internal_cos_kernel(t);
  t2 = __internal_sin_kernel(t);
  if (quadrant & 1) {
    s = u2;
    c = t2;
  } else {
    s = t2;
    c = u2;
  }
  if (quadrant & 2) {
    s = -s;
  }
  quadrant++;
  if (quadrant & 2) {
    c = -c;
  }
  *sptr = s;
  *cptr = c;
#endif /* __USE_FAST_MATH__ */
}

#else /* __CUDABE__ */

/*******************************************************************************
*                                                                              *
* ONLY FOR HOST CODE! NOT FOR DEVICE EXECUTION                                 *
*                                                                              *
*******************************************************************************/

#include <crt/func_macro.h>

#if defined(_WIN32) || defined(__APPLE__)

/*******************************************************************************
*                                                                              *
* HOST IMPLEMENTATION FOR DOUBLE ROUTINES FOR WINDOWS & APPLE PLATFORMS        *
*                                                                              *
*******************************************************************************/

__func__(double exp10(double a))
{
  return pow(10.0, a);
}

__func__(float exp10f(float a))
{
    return (float)exp10((double)a);
}

__func__(void sincos(double a, double *sptr, double *cptr))
{
  *sptr = sin(a);
  *cptr = cos(a);
}

__func__(void sincosf(float a, float *sptr, float *cptr))
{
  double s, c;

  sincos((double)a, &s, &c);
  *sptr = (float)s;
  *cptr = (float)c;
}

__func__(int __isnan(double a))
{
  volatile union {
    double                 d;
    unsigned long long int l;
  } cvt;

  cvt.d = a;

  return cvt.l << 1 > 0xffe0000000000000ull;
}

__func__(int __isinf(double a))
{
  volatile union {
    double                 d;
    unsigned long long int l;
  } cvt;

  cvt.d = a;

  return cvt.l << 1 == 0xffe0000000000000ull;
}

#endif /* _WIN32 || __APPLE__ */

#if defined(_WIN32)

__func__(long long int llabs(long long int a))
{
  return a < 0ll ? -a : a;
}

/*******************************************************************************
*                                                                              *
* HOST IMPLEMENTATION FOR DOUBLE ROUTINES FOR WINDOWS PLATFORM                 *
*                                                                              *
*******************************************************************************/

__func__(int __signbit(double a))
{
  volatile union {
    double               d;
    signed long long int l;
  } cvt;

  cvt.d = a;
  return cvt.l < 0ll;
}

__func__(double copysign(double a, double b))
{
  volatile union {
    double                 d;
    unsigned long long int l;
  } cvta, cvtb;

  cvta.d = a;
  cvtb.d = b;
  cvta.l = (cvta.l & 0x7fffffffffffffffULL) | (cvtb.l & 0x8000000000000000ULL);
  return cvta.d;
}

__func__(int __finite(double a))
{
  volatile union {
    double                 d;
    unsigned long long int l;
  } cvt;

  cvt.d = a;
  return cvt.l << 1 < 0xffe0000000000000ull;
}

__func__(double fmax(double a, double b))
{
  if (__isnan(a) && __isnan(b)) return a + b;
  if (__isnan(a)) return b;
  if (__isnan(b)) return a;
  if ((a == 0.0) && (b == 0.0) && __signbit(b)) return a;
  return a > b ? a : b;
}

__func__(double fmin(double a, double b))
{
  if (__isnan(a) && __isnan(b)) return a + b;
  if (__isnan(a)) return b;
  if (__isnan(b)) return a;
  if ((a == 0.0) && (b == 0.0) && __signbit(a)) return a;
  return a < b ? a : b;
}

__func__(double trunc(double a))
{
  return a < 0.0 ? ceil(a) : floor(a);
}

__func__(double round(double a))
{
  double fa = fabs(a);

  if (fa > CUDART_TWO_TO_52) {
    return a;
  } else {
    double u = floor(fa + 0.5);
    if (fa < 0.5) u = 0;
    u = copysign (u, a);
    return u;
  }
}

__func__(long int lround(double a))
{
  return (long int)round(a);
}

__func__(long long int llround(double a))
{
  return (long long int)round(a);
}

__func__(double rint(double a))
{
  double fa = fabs(a);
  double u = CUDART_TWO_TO_52 + fa;
  if (fa >= CUDART_TWO_TO_52) {
    u = a;
  } else {
    u = u - CUDART_TWO_TO_52;
    u = copysign (u, a);
  }
  return u;  
}
__func__(double nearbyint(double a))
{
  return rint(a);
}

__func__(long int lrint(double a))
{
  return (long int)rint(a);
}

__func__(long long int llrint(double a))
{
  return (long long int)rint(a);
}

__func__(double fdim(double a, double b))
{
  if (a > b) {
    return (a - b);
  } else if (a <= b) {
    return 0.0;
  } else if (__isnan(a)) {
    return a;
  } else {
    return b;
  }
}

__func__(double scalbn(double a, int b))
{
  return ldexp(a, b);
}

__func__(double scalbln(double a, long int b))
{
  int t;

  if (b > 2147483647L) {
    t = 2147483647;
  } else if (b < (-2147483647 - 1)) {
    t = (-2147483647 - 1);
  } else {
    t = (int)b;
  }
  return scalbn(a, t);
}

__func__(double log2(double a))
{
  return log(a) * 1.44269504088896340;
}

__func__(double exp2(double a))
{
  return pow(2.0, a);
}

/*  
 * The following is based on: David Goldberg, "What every computer scientist 
 * should know about floating-point arithmetic", ACM Computing Surveys, Volume 
 * 23, Issue 1, March 1991.
 */
__func__(double log1p(double a))
{
  volatile double u, m;

  u = 1.0 + a;
  if (u == 1.0) {
    /* a very close to zero */
    u = a;
  } else {
    m = u - 1.0;
    u = log(u);
    if (a < 1.0) {
      /* a somewhat close to zero */
      u = a * u;
      u = u / m;
    }
  }
  return u;
}

/*
 * This code based on: http://www.cs.berkeley.edu/~wkahan/Math128/Sumnfp.pdf
 */
__func__(double expm1(double a))
{
  volatile double u, m;

  u = exp(a);
  m = u - 1.0;
  if (m == 0.0) {
    /* a very close zero */
    m = a;
  } 
  else if (fabs(a) < 1.0) {
    /* a somewhat close zero */
    u = log(u);
    m = m * a;
    m = m / u;
  }
  return m;
}

__func__(double cbrt(double a))
{
  double s, t;

  if (a == 0.0 || __isinf(a)) {
    return a;
  } 
  s = fabs(a);
  t = exp2(CUDART_THIRD * log2(s));           /* initial approximation */
  t = t - (t - (s / (t * t))) * CUDART_THIRD; /* refine approximation */
  t = copysign(t, a);
  return t;
}

__func__(double acosh(double a))
{
  double s, t;

  t = a - 1.0;
  if (t == a) {
    return log(2.0) + log(a);
  } else {
    s = a + 1.0;
    t = t + sqrt(s * t);
    return log1p(t);
  }
}

__func__(double asinh(double a))
{
  double fa, oofa, t;

  fa = fabs(a);
  if (fa > 1e18) {
    t = log(2.0) + log(fa);
  } else {
    oofa = 1.0 / fa;
    t = fa + fa / (oofa + sqrt(1.0 + oofa * oofa));
    t = log1p(t);
  }
  t = copysign(t, a);
  return t;
}

__func__(double atanh(double a))
{
  double fa, t;

  if (__isnan(a)) {
    return a + a;
  }
  fa = fabs(a);
  t = (2.0 * fa) / (1.0 - fa);
  t = 0.5 * log1p(t);
  if (__isnan(t) || !__signbit(a)) {
    return t;
  }
  return -t;
}

__func__(int ilogb(double a))
{
  volatile union {
    double                 d;
    unsigned long long int l;
  } x;
  unsigned long long int i;
  int expo = -1022;

  if (__isnan(a)) return -__cuda_INT_MAX-1;
  if (__isinf(a)) return __cuda_INT_MAX;
  x.d = a;
  i = x.l & 0x7fffffffffffffffull;
  if (i == 0) return -__cuda_INT_MAX-1;
  if (i >= 0x0010000000000000ull) {
    return (int)(((i >> 52) & 0x7ff) - 1023);
  }
  while (i < 0x0010000000000000ull) {
    expo--;
    i <<= 1;
  }
  return expo;
}

__func__(double logb(double a))
{
  volatile union {
    double                 d;
    unsigned long long int l;
  } x;
  unsigned long long int i;
  int expo = -1022;

  if (__isnan(a)) return a + a;
  if (__isinf(a)) return fabs(a);
  x.d = a;
  i = x.l & 0x7fffffffffffffffull;
  if (i == 0) return -1.0/fabs(a);
  if (i >= 0x0010000000000000ull) {
    return (double)((int)((i >> 52) & 0x7ff) - 1023);
  }
  while (i < 0x0010000000000000ull) {
    expo--;
    i <<= 1;
  }
  return (double)expo;
}

__func__(double remquo(double a, double b, int *quo))
{
  volatile union {
    double                 d;
    unsigned long long int l;
  } cvt;
  int rem1 = 1; /* do FPREM1, a.k.a IEEE remainder */
  int expo_a;
  int expo_b;
  unsigned long long mant_a;
  unsigned long long mant_b;
  unsigned long long mant_c;
  unsigned long long temp;
  int sign_a;
  int sign_b;
  int sign_c;
  int expo_c;
  int expodiff;
  int quot = 0;                 /* initialize quotient */
  int l;
  int iter;

  cvt.d = a;
  mant_a = (cvt.l << 11) | 0x8000000000000000ULL;
  expo_a = (int)((cvt.l >> 52) & 0x7ff) - 1023;
  sign_a = (int)(cvt.l >> 63);

  cvt.d = b;
  mant_b = (cvt.l << 11) | 0x8000000000000000ULL;
  expo_b = (int)((cvt.l >> 52) & 0x7ff) - 1023;
  sign_b = (int)(cvt.l >> 63);

  sign_c = sign_a;  /* remainder has sign of dividend */
  expo_c = expo_a;  /* default */
      
  /* handled NaNs and infinities */
  if (__isnan(a) || __isnan(b)) {
    *quo = quot;
    return a + b;
  }
  if (__isinf(a) || (b == 0.0)) {
    *quo = quot;
    cvt.l = 0xfff8000000000000ULL;
    return cvt.d;
  }
  if ((a == 0.0) || (__isinf(b))) {
    *quo = quot;
    return a;
  }
  /* normalize denormals */
  if (expo_a < -1022) {
    mant_a = mant_a + mant_a;
    while (mant_a < 0x8000000000000000ULL) {
      mant_a = mant_a + mant_a;
      expo_a--;
    }
  } 
  if (expo_b < -1022) {
    mant_b = mant_b + mant_b;
    while (mant_b < 0x8000000000000000ULL) {
      mant_b = mant_b + mant_b;
      expo_b--;
    }
  }
  expodiff = expo_a - expo_b;
  /* clamp iterations if exponent difference negative */
  if (expodiff < 0) {
    iter = -1;
  } else {
    iter = expodiff;
  }
  /* Shift dividend and divisor right by one bit to prevent overflow
     during the division algorithm.
   */
  mant_a = mant_a >> 1;
  mant_b = mant_b >> 1;
  expo_c = expo_a - iter; /* default exponent of result   */

  /* Use binary longhand division (restoring) */
  for (l = 0; l < (iter + 1); l++) {
    mant_a = mant_a - mant_b;
    if (mant_a & 0x8000000000000000ULL) {
      mant_a = mant_a + mant_b;
      quot = quot + quot;
    } else {
      quot = quot + quot + 1;
    }
    mant_a = mant_a + mant_a;
  }

  /* Save current remainder */
  mant_c = mant_a;
  /* If remainder's mantissa is all zeroes, final result is zero. */
  if (mant_c == 0) {
    quot = quot & 7;
    *quo = (sign_a ^ sign_b) ? -quot : quot;
    cvt.l = (unsigned long long int)sign_c << 63;
    return cvt.d;
  }
  /* Normalize result */
  while (!(mant_c & 0x8000000000000000ULL)) {
    mant_c = mant_c + mant_c;
    expo_c--;
  }
  /* For IEEE remainder (quotient rounded to nearest-even we might need to 
     do a final subtraction of the divisor from the remainder.
  */
  if (rem1 && ((expodiff+1) >= 0)) {
    temp = mant_a - mant_b;
    /* round quotient to nearest even */
    if (((temp != 0ULL) && (!(temp & 0x8000000000000000ULL))) ||
        ((temp == 0ULL) && (quot & 1))) {
      mant_a = mant_a >> 1;
      quot++;
      /* Since the divisor is greater than the remainder, the result will
         have opposite sign of the dividend. To avoid a negative mantissa
         when subtracting the divisor from remainder, reverse subtraction
      */
      sign_c = 1 ^ sign_c;
      expo_c = expo_a - iter + 1;
      mant_c = mant_b - mant_a;
      /* normalize result */
      while (!(mant_c & 0x8000000000000000ULL)) {
        mant_c = mant_c + mant_c;
        expo_c--;
      }
    }
  }
  /* package up result */
  if (expo_c >= -1022) { /* normal */
    mant_c = ((mant_c >> 11) + 
              ((((unsigned long long)sign_c) << 63) +
               (((unsigned long long)(expo_c + 1022)) << 52)));
  } else { /* denormal */
    mant_c = ((((unsigned long long)sign_c) << 63) + 
              (mant_c >> (11 - expo_c - 1022)));
  }
  quot = quot & 7; /* mask quotient down to least significant three bits */
  *quo = (sign_a ^ sign_b) ? -quot : quot;
  cvt.l = mant_c;
  return cvt.d;
}

__func__(double remainder(double a, double b))
{
  int quo;
  return remquo (a, b, &quo);
}

__func__(double fma (double a, double b, double c))
{
  volatile union {
    struct {
      unsigned int lo;
      unsigned int hi;
    };
    double d;
  } xx, yy, zz, ww;
  unsigned int s, t, u, prod0, prod1, prod2, prod3, expo_x, expo_y, expo_z;
  
  xx.d = a;
  yy.d = b;
  zz.d = c;

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
      return yy.d;
    }
    if (((zz.hi << 1) | (zz.lo != 0)) > 0xffe00000) {
      zz.hi |= 0x00080000;
      return zz.d;
    }
    if (((xx.hi << 1) | (xx.lo != 0)) > 0xffe00000) {
      xx.hi |= 0x00080000;
      return xx.d;
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
      return xx.d;
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      if ((((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) ||
          (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000)) {
        if ((int)(xx.hi ^ yy.hi ^ zz.hi) < 0) {
          xx.hi = 0xfff80000;
          xx.lo = 0x00000000;
          return xx.d;
        }
      }
    }
    /* fma (inf, y, z) --> inf
       fma (x, inf, z) --> inf
       fma (x, y, inf) --> inf
    */
    if (((xx.hi << 1) | (xx.lo != 0)) == 0xffe00000) {
      xx.hi = xx.hi ^ (yy.hi & 0x80000000);
      return xx.d;
    }
    if (((yy.hi << 1) | (yy.lo != 0)) == 0xffe00000) {
      yy.hi = yy.hi ^ (xx.hi & 0x80000000);
      return yy.d;
    }
    if (((zz.hi << 1) | (zz.lo != 0)) == 0xffe00000) {
      return zz.d;
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
          return zz.d;
        }
      }
    }
    /* fma (0, y, 0) --> +0  (-0 if round down and signs of addend differ)
       fma (x, 0, 0) --> +0  (-0 if round down and signs of addend differ)
    */
    if ((((zz.hi << 1) | zz.lo) == 0) &&
        ((((xx.hi << 1) | xx.lo) == 0) ||
         (((yy.hi << 1) | yy.lo) == 0))) {
      zz.hi &= 0x7fffffff;
      return zz.d;
    }
    
    /* fma (0, y, z) --> z
       fma (x, 0, z) --> z
    */
    if ((((xx.hi << 1) | xx.lo) == 0) ||
        (((yy.hi << 1) | yy.lo) == 0)) {
      return zz.d;
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
  prod1 =(unsigned)(((unsigned long long)xx.lo*(unsigned long long)yy.lo)>>32);
  prod2 = xx.hi * yy.lo;
  prod3 = xx.lo * yy.hi;
  prod1 += prod2;
  t = prod1 < prod2;
  prod1 += prod3;
  t += prod1 < prod3;
  prod2 =(unsigned)(((unsigned long long)xx.hi*(unsigned long long)yy.lo)>>32);
  prod3 =(unsigned)(((unsigned long long)xx.lo*(unsigned long long)yy.hi)>>32);
  prod2 += prod3;
  s = prod2 < prod3;
  prod3 = xx.hi * yy.hi;
  prod2 += prod3;
  s += prod2 < prod3;
  prod2 += t;
  s += prod2 < t;
  prod3 =(unsigned)(((unsigned long long)xx.hi*(unsigned long long)yy.hi)>>32);
  prod3 = prod3 + s;
  
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
        return xx.d;
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
    xx.lo += (t == 0x80000000) ? s : (t >> 31);
    xx.hi += (u > xx.lo);
    xx.hi += ((expo_x + 1) << 20);
    return xx.d;
  } else if ((int)expo_x >= 2046) {      
    /* overflow */
    xx.hi = (xx.hi & 0x80000000) | 0x7ff00000;
    xx.lo = 0;
    return xx.d;
  }
  /* subnormal */
  expo_x = (unsigned)(-(int)expo_x);
  if (expo_x > 54) {
    xx.hi = xx.hi & 0x80000000;
    xx.lo = 0;
    return xx.d;
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
  xx.lo += (t == 0x80000000) ? expo_x : (t >> 31);
  xx.hi += (u > xx.lo);
  xx.hi |= yy.hi;
  return xx.d;
}

__func__(double nextafter(double a, double b))
{
  volatile union {
    double d;
    unsigned long long int l;
  } cvt;
  unsigned long long int ia;
  unsigned long long int ib;
  cvt.d = a;
  ia = cvt.l;
  cvt.d = b;
  ib = cvt.l;
  if (__isnan(a) || __isnan(b)) return a + b; /* NaN */
  if (((ia | ib) << 1) == 0ULL) return b;
  if (a == 0.0) {
    return copysign (4.9406564584124654e-324, b); /* crossover */
  }
  if ((a < b) && (a < 0.0)) ia--;
  if ((a < b) && (a > 0.0)) ia++;
  if ((a > b) && (a < 0.0)) ia++;
  if ((a > b) && (a > 0.0)) ia--;
  cvt.l = ia;
  return cvt.d;
}

__func__(double erf(double a))
{
  double t, r, q;

  t = fabs(a);
  if (t >= 1.0) {
    r =        -1.28836351230756500E-019;
    r = r * t + 1.30597472161093370E-017;
    r = r * t - 6.33924401259620500E-016;
    r = r * t + 1.96231865908940140E-014;
    r = r * t - 4.35272243559990750E-013;
    r = r * t + 7.37083927929352150E-012;
    r = r * t - 9.91402142550461630E-011;
    r = r * t + 1.08817017167760820E-009;
    r = r * t - 9.93918713097634620E-009;
    r = r * t + 7.66739923255145500E-008;
    r = r * t - 5.05440278302806720E-007;
    r = r * t + 2.87474157099000620E-006;
    r = r * t - 1.42246725399722510E-005;
    r = r * t + 6.16994555079419460E-005;
    r = r * t - 2.36305221938908790E-004;
    r = r * t + 8.05032844055371070E-004;
    r = r * t - 2.45833366629108140E-003;
    r = r * t + 6.78340988296706120E-003;
    r = r * t - 1.70509103597554640E-002;
    r = r * t + 3.93322852515666300E-002;
    r = r * t - 8.37271292613764040E-002;
    r = r * t + 1.64870423707623280E-001;
    r = r * t - 2.99729521787681470E-001;
    r = r * t + 4.99394435612628580E-001;
    r = r * t - 7.52014596480123030E-001;
    r = r * t + 9.99933138314926250E-001;
    r = r * t - 1.12836725321102670E+000;
    r = r * t + 9.99998988715182450E-001;
    q = exp (-t * t);
    r = 1.0 - r * q;
    if (t >= 6.5) {
      r = 1.0;
    }    
    a = copysign (r, a);
  } else {
    q = a * a;
    r =        -7.77946848895991420E-010;
    r = r * q + 1.37109803980285950E-008;
    r = r * q - 1.62063137584932240E-007;
    r = r * q + 1.64471315712790040E-006;
    r = r * q - 1.49247123020098620E-005;
    r = r * q + 1.20552935769006260E-004;
    r = r * q - 8.54832592931448980E-004;
    r = r * q + 5.22397760611847340E-003;
    r = r * q - 2.68661706431114690E-002;
    r = r * q + 1.12837916709441850E-001;
    r = r * q - 3.76126389031835210E-001;
    r = r * q + 1.12837916709551260E+000;
    a = r * a;
  }
  return a;
}

__func__(double erfc(double a))
{
  double p, q, h, l;

  if (a < 0.75) {
    return 1.0 - erf(a);
  } 
  if (a > 27.3) {
    return 0.0;
  }
  if (a < 5.0) {
    double t;
    t = 1.0 / a;
    p =         1.9759923722227928E-008;
    p = p * t - 1.0000002670474897E+000;
    p = p * t - 7.4935303236347828E-001;
    p = p * t - 1.5648136328071860E-001;
    p = p * t + 1.2871196242447239E-001;
    p = p * t + 1.1126459974811195E-001;
    p = p * t + 4.0678642255914332E-002;
    p = p * t + 7.9915414156678296E-003;
    p = p * t + 7.1458332107840234E-004;
    q =     t + 2.7493547525030619E+000;
    q = q * t + 3.3984254815725423E+000;
    q = q * t + 2.4635304979947761E+000;
    q = q * t + 1.1405284734691286E+000;
    q = q * t + 3.4130157606195649E-001;
    q = q * t + 6.2250967676044953E-002;
    q = q * t + 5.5661370941268700E-003;
    q = q * t + 1.0575248365468671E-009;
    p = p / q;
    p = p * t;
    h = ((int)(a * 16.0)) * 0.0625;
    l = (a - h) * (a + h);
    q = exp(-h * h) * exp(-l);
    q = q * 0.5;
    p = p * q + q;
    p = p * t;
  } else {
    double ooa, ooasq;

    ooa = 1.0 / a;
    ooasq = ooa * ooa;
    p =            -4.0025406686930527E+005;
    p = p * ooasq + 1.4420582543942123E+005;
    p = p * ooasq - 2.7664185780951841E+004;
    p = p * ooasq + 4.1144611644767283E+003;
    p = p * ooasq - 5.8706000519209351E+002;
    p = p * ooasq + 9.1490086446323375E+001;
    p = p * ooasq - 1.6659491387740221E+001;
    p = p * ooasq + 3.7024804085481784E+000;
    p = p * ooasq - 1.0578553994424316E+000;
    p = p * ooasq + 4.2314218745087778E-001;
    p = p * ooasq - 2.8209479177354962E-001;
    p = p * ooasq + 5.6418958354775606E-001;
    h = a * a;
    h = ((int)(a * 16.0)) * 0.0625;
    l = (a - h) * (a + h);
    q = exp(-h * h) * exp(-l);
    p = p * ooa;
    p = p * q;
  }
  return p;
}

__func__(double lgamma(double a))
{
  double s;
  double t;
  double i;
  double fa;
  double sum;
  long long int quot;
  if (__isnan(a) || __isinf(a)) {
    return a * a;
  }
  fa = fabs(a);
  if (fa >= 3.0) {
    if (fa >= 8.0) {
      /* Stirling approximation; coefficients from Hart et al, "Computer 
       * Approximations", Wiley 1968. Approximation 5404. 
       */
      s = 1.0 / fa;
      t = s * s;
      sum =          -0.1633436431e-2;
      sum = sum * t + 0.83645878922e-3;
      sum = sum * t - 0.5951896861197e-3;
      sum = sum * t + 0.793650576493454e-3;
      sum = sum * t - 0.277777777735865004e-2;
      sum = sum * t + 0.833333333333331018375e-1;
      sum = sum * s + 0.918938533204672;
      s = 0.5 * log (fa);
      t = fa - 0.5;
      s = s * t;
      t = s - fa;
      s = s + sum;
      t = t + s;
    } else {
      i = fa - 3.0;
      s =        -4.02412642744125560E+003;
      s = s * i - 2.97693796998962000E+005;
      s = s * i - 6.38367087682528790E+006;
      s = s * i - 5.57807214576539320E+007;
      s = s * i - 2.24585140671479230E+008;
      s = s * i - 4.70690608529125090E+008;
      s = s * i - 7.62587065363263010E+008;
      s = s * i - 9.71405112477113250E+008;
      t =     i - 1.02277248359873170E+003;
      t = t * i - 1.34815350617954480E+005;
      t = t * i - 4.64321188814343610E+006;
      t = t * i - 6.48011106025542540E+007;
      t = t * i - 4.19763847787431360E+008;
      t = t * i - 1.25629926018000720E+009;
      t = t * i - 1.40144133846491690E+009;
      t = s / t;
      t = t + i;
    }
  } else if (fa >= 1.5) {
    i = fa - 2.0;
    t =         9.84839283076310610E-009;
    t = t * i - 6.69743850483466500E-008;
    t = t * i + 2.16565148880011450E-007;
    t = t * i - 4.86170275781575260E-007;
    t = t * i + 9.77962097401114400E-007;
    t = t * i - 2.03041287574791810E-006;
    t = t * i + 4.36119725805364580E-006;
    t = t * i - 9.43829310866446590E-006;
    t = t * i + 2.05106878496644220E-005;
    t = t * i - 4.49271383742108440E-005;
    t = t * i + 9.94570466342226000E-005;
    t = t * i - 2.23154589559238440E-004;
    t = t * i + 5.09669559149637430E-004;
    t = t * i - 1.19275392649162300E-003;
    t = t * i + 2.89051032936815490E-003;
    t = t * i - 7.38555102806811700E-003;
    t = t * i + 2.05808084278121250E-002;
    t = t * i - 6.73523010532073720E-002;
    t = t * i + 3.22467033424113040E-001;
    t = t * i + 4.22784335098467190E-001;
    t = t * i;
  } else if (fa >= 0.7) {
    i = 1.0 - fa;
    t =         1.17786911519331130E-002;  
    t = t * i + 3.89046747413522300E-002;
    t = t * i + 5.90045711362049900E-002;
    t = t * i + 6.02143305254344420E-002;
    t = t * i + 5.61652708964839180E-002;
    t = t * i + 5.75052755193461370E-002;
    t = t * i + 6.21061973447320710E-002;
    t = t * i + 6.67614724532521880E-002;
    t = t * i + 7.14856037245421020E-002;
    t = t * i + 7.69311251313347100E-002;
    t = t * i + 8.33503129714946310E-002;
    t = t * i + 9.09538288991182800E-002;
    t = t * i + 1.00099591546322310E-001;
    t = t * i + 1.11334278141734510E-001;
    t = t * i + 1.25509666613462880E-001;
    t = t * i + 1.44049896457704160E-001;
    t = t * i + 1.69557177031481600E-001;
    t = t * i + 2.07385551032182120E-001;
    t = t * i + 2.70580808427600350E-001;
    t = t * i + 4.00685634386517050E-001;
    t = t * i + 8.22467033424113540E-001;
    t = t * i + 5.77215664901532870E-001;
    t = t * i;
  } else {
    t =         -9.04051686831357990E-008;
    t = t * fa + 7.06814224969349250E-007;
    t = t * fa - 3.80702154637902830E-007;
    t = t * fa - 2.12880892189316100E-005;
    t = t * fa + 1.29108470307156190E-004;
    t = t * fa - 2.15932815215386580E-004;
    t = t * fa - 1.16484324388538480E-003;
    t = t * fa + 7.21883433044470670E-003;
    t = t * fa - 9.62194579514229560E-003;
    t = t * fa - 4.21977386992884450E-002;
    t = t * fa + 1.66538611813682460E-001;
    t = t * fa - 4.20026350606819980E-002;
    t = t * fa - 6.55878071519427450E-001;
    t = t * fa + 5.77215664901523870E-001;
    t = t * fa;
    t = t * fa + fa;
    t = -log (t);
  }
  if (a >= 0.0) return t;
  if (fa < 1e-19) return -log(fa);
  i = floor(fa);       
  if (fa == i) return 1.0 / (fa - i); /* a is an integer: return infinity */
  i = rint (2.0 * fa);
  quot = (long long int)i;
  i = fa - 0.5 * i;
  i = i * CUDART_PI;
  if (quot & 1) {
    i = cos(i);
  } else {
    i = sin(i);
  }
  i = fabs(i);
  t = log(CUDART_PI / (i * fa)) - t;
  return t;
}

__func__(unsigned long long int __internal_host_nan_kernel(const char *s))
{
  unsigned long long i = 0;
  int c;
  int ovfl = 0;
  int invld = 0;
  if (s && (*s == '0')) {
    s++;
    if ((*s == 'x') || (*s == 'X')) {
      s++; 
      while (*s == '0') s++;
      while (*s) {
        if (i > 0x0fffffffffffffffULL) {
          ovfl = 1;
        }
        c = (((*s) >= 'A') && ((*s) <= 'F')) ? (*s + 'a' - 'A') : (*s);
        if ((c >= 'a') && (c <= 'f')) { 
          c = c - 'a' + 10;
          i = i * 16 + c;
        } else if ((c >= '0') && (c <= '9')) { 
          c = c - '0';
          i = i * 16 + c;
        } else {
          invld = 1;
        }
        s++;
      }
    } else {
      while (*s == '0') s++;
      while (*s) {
        if (i > 0x1fffffffffffffffULL) {
          ovfl = 1;
        }
        c = *s;
        if ((c >= '0') && (c <= '7')) { 
          c = c - '0';
          i = i * 8 + c;
        } else {
          invld = 1; 
        }
        s++;
      }
    }
  } else if (s) {
    while (*s) {
      c = *s;
      if ((i > 1844674407370955161ULL) || 
          ((i == 1844674407370955161ULL) && (c > '5'))) {
        ovfl = 1;
      }
      if ((c >= '0') && (c <= '9')) { 
        c = c - '0';
        i = i * 10 + c;
      } else {
        invld = 1;
      }
      s++;
    }
  }
  if (ovfl) {
    i = ~0ULL;
  }
  if (invld) {
    i = 0ULL;
  }
  i = (i & 0x000fffffffffffffULL) | 0x7ff8000000000000ULL;
  return i;
}

__func__(double nan(const char *tagp))
{
  volatile union {
    unsigned long long l;
    double d;
  } cvt;

  cvt.l = __internal_host_nan_kernel(tagp);
  return cvt.d;
}

__func__(double __host_tgamma_kernel(double a))
{
  double t;
  t =       - 4.4268934071252475E-010;
  t = t * a - 2.0266591846658954E-007;
  t = t * a + 1.1381211721119527E-006;
  t = t * a - 1.2507734816630748E-006;
  t = t * a - 2.0136501740408771E-005;
  t = t * a + 1.2805012607354486E-004;
  t = t * a - 2.1524140811527418E-004;
  t = t * a - 1.1651675459704604E-003;
  t = t * a + 7.2189432248466381E-003;
  t = t * a - 9.6219715326862632E-003;
  t = t * a - 4.2197734554722394E-002;
  t = t * a + 1.6653861138250356E-001;
  t = t * a - 4.2002635034105444E-002;
  t = t * a - 6.5587807152025712E-001;
  t = t * a + 5.7721566490153287E-001;
  t = t * a + 1.0000000000000000E+000;
  return t;
}

__func__(double __host_stirling_poly(double a))
{
  double x = 1.0 / a;
  double z = 0.0;
  z =       + 8.3949872067208726e-004;
  z = z * x - 5.1717909082605919e-005;
  z = z * x - 5.9216643735369393e-004;
  z = z * x + 6.9728137583658571e-005;
  z = z * x + 7.8403922172006662e-004;
  z = z * x - 2.2947209362139917e-004;
  z = z * x - 2.6813271604938273e-003;
  z = z * x + 3.4722222222222220e-003;
  z = z * x + 8.3333333333333329e-002;
  z = z * x + 1.0000000000000000e+000;
  return z;
}

__func__(double __host_tgamma_stirling(double a))
{
  double z;
  double x;
  z = __host_stirling_poly (a);
  if (a < 142.0) {
    x = pow (a, a - 0.5);
    a = x * exp (-a);
    a = a * CUDART_SQRT_2PI;
    return a * z;
  } else if (a < 172.0) {
    x = pow (a, 0.5 * a - 0.25);
    a = x * exp (-a);
    a = a * CUDART_SQRT_2PI;
    a = a * z;
    return a * x;
  } else {
    return exp(1000.0); /* INF */
  }
}

__func__(double tgamma(double a))
{
  double s, xx, x = a;
  if (__isnan(a)) {
    return a + a;
  }
  if (fabs(x) < 20.0) {
    if (x >= 0.0) {
      s = 1.0;
      xx = x;
      while (xx > 1.5) {
        xx = xx - 1.0;
        s = s * xx;
      }
      if (x >= 0.5) {
        xx = xx - 1.0;
      }
      xx = __host_tgamma_kernel (xx);
      if (x < 0.5) {
        xx = xx * x;
      }
      s = s / xx;
    } else {
      xx = x;
      s = xx;
      if (x == floor(x)) {
        return 0.0 / (x - floor(x));
      }
      while (xx < -0.5) {
        xx = xx + 1.0;
        s = s * xx;
      }
      xx = __host_tgamma_kernel (xx);
      s = s * xx;
      s = 1.0 / s;
    }
    return s;
  } else {
    if (x >= 0.0) {
      return __host_tgamma_stirling (x);
    } else {
      double t;
      int quot;
      if (x == floor(x)) {
        return 0.0 / (x - floor(x));
      }
      if (x < -185.0) {
        int negative;
        x = floor(x);
        negative = ((x - (2.0 * floor(0.5 * x))) == 1.0);
        return negative ? (-1.0 / 1e308 / 1e308) : CUDART_ZERO;
      }
      /* compute sin(pi*x) accurately */
      xx = rint (2.0 * x);
      quot = (int)xx;
      xx = -0.5 * xx + x;
      xx = xx * CUDART_PI;
      if (quot & 1) {
        xx = cos (xx);
      } else {
        xx = sin (xx);
      }
      if (quot & 2) {
        xx = -xx;
      }
      x = fabs (x);
      s = exp (-x);
      t = x - 0.5;
      if (x > 140.0) t = 0.5 * t;
      t = pow (x, t);
      if (x > 140.0) s = s * t;
      s = s * __host_stirling_poly (x);
      s = s * x;
      s = s * xx;
      s = 1.0 / s;
      s = s * CUDART_SQRT_PIO2;
      s = s / t;
      return s;
    }
  }
}

/*******************************************************************************
*                                                                              *
* HOST IMPLEMENTATION FOR FLOAT ROUTINES FOR WINDOWS PLATFORM                  *
* MAP FLOAT ROUTINES TO DOUBLE ROUTINES                                        *
*                                                                              *
*******************************************************************************/

__func__(int __signbitf(float a))
{
  return __signbit((double)a);
}

__func__(int __finitef(float a))
{
  return __finite((double)a);
}

__func__(int __isinff(float a))
{
  return __isinf((double)a);
}

__func__(int __isnanf(float a))
{
  return __isnan((double)a);
}

__func__(float fmaxf(float a, float b))
{
  return (float)fmax((double)a, (double)b);
}

__func__(float fminf(float a, float b))
{
  return (float)fmin((double)a, (double)b);
}

__func__(float roundf(float a))
{
  return (float)round((double)a);
}

__func__(long int lroundf(float a))
{
  return lround((double)a);
}

__func__(long long int llroundf(float a))
{
  return llround((double)a);
}

__func__(float truncf(float a))
{
  return (float)trunc((double)a);
}

__func__(float rintf(float a))
{
  return (float)rint((double)a);
}

__func__(float nearbyintf(float a))
{
  return (float)nearbyint((double)a);
}

__func__(long int lrintf(float a))
{
  return lrint((double)a);
}

__func__(long long int llrintf(float a))
{
  return llrint((double)a);
}

__func__(float logbf(float a))
{
  return (float)logb((double)a);
}

__func__(float scalblnf(float a, long int b))
{
  return (float)scalbln((double)a, b);
}

__func__(float log2f(float a))
{
  return (float)log2((double)a);
}

__func__(float exp2f(float a))
{
  return (float)exp2((double)a);
}

__func__(float acoshf(float a))
{
  return (float)acosh((double)a);
}

__func__(float asinhf(float a))
{
  return (float)asinh((double)a);
}

__func__(float atanhf(float a))
{
  return (float)atanh((double)a);
}

__func__(float cbrtf(float a))
{
  return (float)cbrt((double)a);
}

__func__(float expm1f(float a))
{
  return (float)expm1((double)a);
}

__func__(float fdimf(float a, float b))
{
  return (float)fdim((double)a, (double)b);
}

__func__(float hypotf(float a, float b))
{
  return (float)hypot((double)a, (double)b);
}

__func__(float log1pf(float a))
{
  return (float)log1p((double)a);
}

__func__(float scalbnf(float a, int b))
{
  return (float)scalbn((double)a, b);
}

__func__(float fmaf(float a, float b, float c))
{
  return (float)fma((double)a, (double)b, (double)c);
}

__func__(int ilogbf(float a))
{
  return ilogb((double)a);
}

__func__(float erff(float a))
{
  return (float)erf((double)a);
}

__func__(float erfcf(float a))
{
  return (float)erfc((double)a);
}

__func__(float lgammaf(float a))
{
  return (float)lgamma((double)a);
}

__func__(float tgammaf(float a))
{
  return (float)tgamma((double)a);
}

__func__(float remquof(float a, float b, int *quo))
{
  return (float)remquo((double)a, (double)b, quo);
}

__func__(float remainderf(float a, float b))
{
  return (float)remainder((double)a, (double)b);
}

/*******************************************************************************
*                                                                              *
* HOST IMPLEMENTATION FOR FLOAT ROUTINES FOR WINDOWS PLATFORM                  *
*                                                                              *
*******************************************************************************/

__func__(float copysignf(float a, float b))
{
  volatile union {
    float f;
    unsigned int i;
  } aa, bb;

  aa.f = a;
  bb.f = b;
  aa.i = (aa.i & ~0x80000000) | (bb.i & 0x80000000);
  return aa.f;
}

__func__(float nextafterf(float a, float b))
{
  volatile union {
    float f;
    unsigned int i;
  } cvt;
  unsigned int ia;
  unsigned int ib;
  cvt.f = a;
  ia = cvt.i;
  cvt.f = b;
  ib = cvt.i;
  if (__isnanf(a) || __isnanf(b)) return a + b; /*NaN*/
  if (((ia | ib) << 1) == 0) return b;
  if (a == 0.0f) {
    return copysignf(1.401298464e-045f, b); /*crossover*/
  }
  if ((a < b) && (a < 0.0f)) ia--;
  if ((a < b) && (a > 0.0f)) ia++;
  if ((a > b) && (a < 0.0f)) ia++;
  if ((a > b) && (a > 0.0f)) ia--;
  cvt.i = ia;
  return cvt.f;
}

__func__(float nanf(const char *tagp))
{
  volatile union {
    float f;
    unsigned int i;
  } cvt;
  
  cvt.i = (unsigned int)__internal_host_nan_kernel(tagp);
  cvt.i = (cvt.i & 0x007fffff) | 0x7fc00000;
  return cvt.f;
}

#endif /* _WIN32 */

/*******************************************************************************
*                                                                              *
* HOST IMPLEMENTATION FOR DOUBLE AND FLOAT ROUTINES. ALL PLATFORMS             *
*                                                                              *
*******************************************************************************/

__func__(double rsqrt(double a))
{
  return 1.0 / sqrt(a);
}

__func__(double rcbrt(double a))
{
  double s, t;

  if (__isnan(a)) {
    return a + a;
  }
  if (a == 0.0 || __isinf(a)) {
    return 1.0 / a;
  } 
  s = fabs(a);
  t = exp2(-CUDART_THIRD * log2(s));                /* initial approximation */
  t = ((t*t) * (-s*t) + 1.0) * (CUDART_THIRD*t) + t;/* refine approximation */
#if defined(__APPLE__)
  if (__signbitd(a))
#else /* __APPLE__ */
  if (__signbit(a))
#endif /* __APPLE__ */
  {
    t = -t;
  }
  return t;
}

__func__(double sinpi(double a))
{
  int n;

  if (__isnan(a)) {
    return a + a;
  }
  if (a == 0.0 || __isinf(a)) {
    return sin (a);
  } 
  if (a == floor(a)) {
    return ((a / 1.0e308) / 1.0e308) / 1.0e308;
  }
  a = remquo (a, 0.5, &n);
  a = a * CUDART_PI;
  if (n & 1) {
    a = cos (a);
  } else {
    a = sin (a);
  }
  if (n & 2) {
    a = -a;
  }
  return a;
}

__func__(double erfinv(double a))
{
  double p, q, t, fa;
  volatile union {
    double d;
    unsigned long long int l;
  } cvt;

  fa = fabs(a);
  if (fa >= 1.0) {
    cvt.l = 0xfff8000000000000ull;
    t = cvt.d;                    /* INDEFINITE */
    if (fa == 1.0) {
      t = a * exp(1000.0);        /* Infinity */
    }
  } else if (fa >= 0.9375) {
    /* Based on: J.M. Blair, C.A. Edwards, J.H. Johnson: Rational Chebyshev
       Approximations for the Inverse of the Error Function. Mathematics of
       Computation, Vol. 30, No. 136 (Oct. 1976), pp. 827-830. Table 59
     */
    t = log1p(-fa);
    t = 1.0 / sqrt(-t);
    p =         2.7834010353747001060e-3;
    p = p * t + 8.6030097526280260580e-1;
    p = p * t + 2.1371214997265515515e+0;
    p = p * t + 3.1598519601132090206e+0;
    p = p * t + 3.5780402569085996758e+0;
    p = p * t + 1.5335297523989890804e+0;
    p = p * t + 3.4839207139657522572e-1;
    p = p * t + 5.3644861147153648366e-2;
    p = p * t + 4.3836709877126095665e-3;
    p = p * t + 1.3858518113496718808e-4;
    p = p * t + 1.1738352509991666680e-6;
    q =     t + 2.2859981272422905412e+0;
    q = q * t + 4.3859045256449554654e+0;
    q = q * t + 4.6632960348736635331e+0;
    q = q * t + 3.9846608184671757296e+0;
    q = q * t + 1.6068377709719017609e+0;
    q = q * t + 3.5609087305900265560e-1;
    q = q * t + 5.3963550303200816744e-2;
    q = q * t + 4.3873424022706935023e-3;
    q = q * t + 1.3858762165532246059e-4;
    q = q * t + 1.1738313872397777529e-6;
    t = p / (q * t);
    if (a < 0.0) t = -t;
  } else if (fa >= 0.75) {
    /* Based on: J.M. Blair, C.A. Edwards, J.H. Johnson: Rational Chebyshev
       Approximations for the Inverse of the Error Function. Mathematics of
       Computation, Vol. 30, No. 136 (Oct. 1976), pp. 827-830. Table 39
    */
    t = a * a - .87890625;
    p =         .21489185007307062000e+0;
    p = p * t - .64200071507209448655e+1;
    p = p * t + .29631331505876308123e+2;
    p = p * t - .47644367129787181803e+2;
    p = p * t + .34810057749357500873e+2;
    p = p * t - .12954198980646771502e+2;
    p = p * t + .25349389220714893917e+1;
    p = p * t - .24758242362823355486e+0;
    p = p * t + .94897362808681080020e-2;
    q =     t - .12831383833953226499e+2;
    q = q * t + .41409991778428888716e+2;
    q = q * t - .53715373448862143349e+2;
    q = q * t + .33880176779595142685e+2;
    q = q * t - .11315360624238054876e+2;
    q = q * t + .20369295047216351160e+1;
    q = q * t - .18611650627372178511e+0;
    q = q * t + .67544512778850945940e-2;
    p = p / q;
    t = a * p;
  } else {
    /* Based on: J.M. Blair, C.A. Edwards, J.H. Johnson: Rational Chebyshev
       Approximations for the Inverse of the Error Function. Mathematics of
       Computation, Vol. 30, No. 136 (Oct. 1976), pp. 827-830. Table 18
    */
    t = a * a - .5625;
    p =       - .23886240104308755900e+2;
    p = p * t + .45560204272689128170e+3;
    p = p * t - .22977467176607144887e+4;
    p = p * t + .46631433533434331287e+4;
    p = p * t - .43799652308386926161e+4;
    p = p * t + .19007153590528134753e+4;
    p = p * t - .30786872642313695280e+3;
    q =     t - .83288327901936570000e+2;
    q = q * t + .92741319160935318800e+3;
    q = q * t - .35088976383877264098e+4;
    q = q * t + .59039348134843665626e+4;
    q = q * t - .48481635430048872102e+4;
    q = q * t + .18997769186453057810e+4;
    q = q * t - .28386514725366621129e+3;
    p = p / q;
    t = a * p;
  }
  return t;
}

__func__(double erfcinv(double a))
{
  double t;
  volatile union {
    double d;
    unsigned long long int l;
  } cvt;

  if (__isnan(a)) {
    return a + a;
  }
  if (a <= 0.0) {
    cvt.l = 0xfff8000000000000ull;
    t = cvt.d;                        /* INDEFINITE */
    if (a == 0.0) {
        t = (1.0 - a) * exp(1000.0);  /* Infinity */
    }
  } 
  else if (a >= 0.0625) {
    t = erfinv (1.0 - a);
  }
  else if (a >= 1e-100) {
    /* Based on: J.M. Blair, C.A. Edwards, J.H. Johnson: Rational Chebyshev
       Approximations for the Inverse of the Error Function. Mathematics of
       Computation, Vol. 30, No. 136 (Oct. 1976), pp. 827-830. Table 59
    */
    double p, q;
    t = log(a);
    t = 1.0 / sqrt(-t);
    p =         2.7834010353747001060e-3;
    p = p * t + 8.6030097526280260580e-1;
    p = p * t + 2.1371214997265515515e+0;
    p = p * t + 3.1598519601132090206e+0;
    p = p * t + 3.5780402569085996758e+0;
    p = p * t + 1.5335297523989890804e+0;
    p = p * t + 3.4839207139657522572e-1;
    p = p * t + 5.3644861147153648366e-2;
    p = p * t + 4.3836709877126095665e-3;
    p = p * t + 1.3858518113496718808e-4;
    p = p * t + 1.1738352509991666680e-6;
    q =     t + 2.2859981272422905412e+0;
    q = q * t + 4.3859045256449554654e+0;
    q = q * t + 4.6632960348736635331e+0;
    q = q * t + 3.9846608184671757296e+0;
    q = q * t + 1.6068377709719017609e+0;
    q = q * t + 3.5609087305900265560e-1;
    q = q * t + 5.3963550303200816744e-2;
    q = q * t + 4.3873424022706935023e-3;
    q = q * t + 1.3858762165532246059e-4;
    q = q * t + 1.1738313872397777529e-6;
    t = p / (q * t);
  }
  else {
    /* Based on: J.M. Blair, C.A. Edwards, J.H. Johnson: Rational Chebyshev
       Approximations for the Inverse of the Error Function. Mathematics of
       Computation, Vol. 30, No. 136 (Oct. 1976), pp. 827-830. Table 82
    */
    double p, q;
    t = log(a);
    t = 1.0 / sqrt(-t);
    p =         6.9952990607058154858e-1;
    p = p * t + 1.9507620287580568829e+0;
    p = p * t + 8.2810030904462690216e-1;
    p = p * t + 1.1279046353630280005e-1;
    p = p * t + 6.0537914739162189689e-3;
    p = p * t + 1.3714329569665128933e-4;
    p = p * t + 1.2964481560643197452e-6;
    p = p * t + 4.6156006321345332510e-9;
    p = p * t + 4.5344689563209398450e-12;
    q =     t + 1.5771922386662040546e+0;
    q = q * t + 2.1238242087454993542e+0;
    q = q * t + 8.4001814918178042919e-1;
    q = q * t + 1.1311889334355782065e-1;
    q = q * t + 6.0574830550097140404e-3;
    q = q * t + 1.3715891988350205065e-4;
    q = q * t + 1.2964671850944981713e-6;
    q = q * t + 4.6156017600933592558e-9;
    q = q * t + 4.5344687377088206783e-12;
    t = p / (q * t);
  }
  return t;
}

__func__(float rsqrtf(float a))
{
  return (float)rsqrt((double)a);
}

__func__(float rcbrtf(float a))
{
  return (float)rcbrt((double)a);
}

__func__(float sinpif(float a))
{
  return (float)sinpi((double)a);
}

__func__(float erfinvf(float a))
{
  return (float)erfinv((double)a);
}

__func__(float erfcinvf(float a))
{
  return (float)erfcinv((double)a);
}

/*******************************************************************************
*                                                                              *
* HOST IMPLEMENTATION FOR UTILITY ROUTINES. ALL PLATFORMS                      *
*                                                                              *
*******************************************************************************/

__func__(int min(int a, int b))
{
  return a < b ? a : b;
}

__func__(unsigned int umin(unsigned int a, unsigned int b))
{
  return a < b ? a : b;
}

__func__(long long int llmin(long long int a, long long int b))
{
  return a < b ? a : b;
}

__func__(unsigned long long int ullmin(unsigned long long int a, unsigned long long int b))
{
  return a < b ? a : b;
}

__func__(int max(int a, int b))
{
  return a > b ? a : b;
}

__func__(unsigned int umax(unsigned int a, unsigned int b))
{
  return a > b ? a : b;
}

__func__(long long int llmax(long long int a, long long int b))
{
  return a > b ? a : b;
}

__func__(unsigned long long int ullmax(unsigned long long int a, unsigned long long int b))
{
  return a > b ? a : b;
}

#endif /* __CUDABE__ */

#endif /* __cplusplus && __CUDACC__ */

#if defined(CUDA_DOUBLE_MATH_FUNCTIONS) && defined(CUDA_FLOAT_MATH_FUNCTIONS)

#error -- conflicting mode for double math routines

#endif /* CUDA_DOUBLE_MATH_FUNCTIONS && CUDA_FLOAT_MATH_FUNCTIONS */

#if defined(CUDA_FLOAT_MATH_FUNCTIONS)

#include "math_functions_dbl_ptx1.h"

#endif /* CUDA_FLOAT_MATH_FUNCTIONS */

#if defined(CUDA_DOUBLE_MATH_FUNCTIONS)

#include "math_functions_dbl_ptx3.h"

#endif /* CUDA_DOUBLE_MATH_FUNCTIONS */

#endif /* !__MATH_FUNCTIONS_H__ */
