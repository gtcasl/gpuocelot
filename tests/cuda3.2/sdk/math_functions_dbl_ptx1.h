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

#if !defined(__MATH_FUNCTIONS_DBL_PTX1_H__)
#define __MATH_FUNCTIONS_DBL_PTX1_H__

#if defined(__CUDABE__)

static __forceinline__ double fabs(double a)
{
  return (double)fabsf((float)a);
}

static __forceinline__ double fmax(double a, double b)
{
  return (double)fmaxf((float)a, (float)b);
}

static __forceinline__ double fmin(double a, double b)
{
  return (double)fminf((float)a, (float)b);
}

static __forceinline__ int __finite(double a)
{
  return __finitef((float)a);
}

static __forceinline__ int __isinf(double a)
{
  return __isinff((float)a);
}

static __forceinline__ int __isnan(double a)
{
  return __isnanf((float)a);
}

static __forceinline__ int __signbit(double a)
{
  return __signbitf((float)a);
}

static __forceinline__ double sqrt(double a)
{
  return (double)sqrtf((float)a);
}

static __forceinline__ double rsqrt(double a)
{
  return (double)rsqrtf((float)a);
}

static __forceinline__ double ceil(double a)
{
  return (double)ceilf((float)a);
}

static __forceinline__ double trunc(double a)
{
  return (double)truncf((float)a);
}

static __forceinline__ double floor(double a)
{
  return (double)floorf((float)a);
}

static __forceinline__ double copysign(double a, double b)
{
  return (double)copysignf((float)a, (float)b);
}

static __forceinline__ double sin(double a)
{
  return (double)sinf((float)a);
}

static __forceinline__ double sinpi(double a)
{
  return (double)sinpif((float)a);
}

static __forceinline__ double cos(double a)
{
  return (double)cosf((float)a);
}

static __forceinline__ void sincos(double a, double *sptr, double *cptr)
{
  float fs, fc;

  sincosf((float)a, &fs, &fc);

  *sptr = (double)fs;
  *cptr = (double)fc;
}

static __forceinline__ double tan(double a)
{
  return (double)tanf((float)a);
}

static __forceinline__ double exp(double a)
{
  return (double)expf((float)a);
}

static __forceinline__ double exp2(double a)
{
  return (double)exp2f((float)a);
}

static __forceinline__ double exp10(double a)
{
  return (double)exp10f((float)a);
}

static __forceinline__ double expm1(double a)
{
  return (double)expm1f((float)a);
}

static __forceinline__ double cosh(double a)
{
  return (double)coshf((float)a);
}

static __forceinline__ double sinh(double a)
{
  return (double)sinhf((float)a);
}

static __forceinline__ double tanh(double a)
{
  return (double)tanhf((float)a);
}

static __forceinline__ double asin(double a)
{
  return (double)asinf((float)a);
}

static __forceinline__ double acos(double a)
{
  return (double)acosf((float)a);
}

static __forceinline__ double atan(double a)
{
  return (double)atanf((float)a);
}

static __forceinline__ double atan2(double a, double b)
{
  return (double)atan2f((float)a, (float)b);
}

static __forceinline__ double log(double a)
{
  return (double)logf((float)a);
}

static __forceinline__ double log2(double a)
{
  return (double)log2f((float)a);
}

static __forceinline__ double log10(double a)
{
  return (double)log10f((float)a);
}

static __forceinline__ double log1p(double a)
{
  return (double)log1pf((float)a);
}

static __forceinline__ double acosh(double a)
{
  return (double)acoshf((float)a);
}

static __forceinline__ double asinh(double a)
{
  return (double)asinhf((float)a);
}

static __forceinline__ double atanh(double a)
{
  return (double)atanhf((float)a);
}

static __forceinline__ double hypot(double a, double b)
{
  return (double)hypotf((float)a, (float)b);
}

static __forceinline__ double cbrt(double a)
{
  return (double)cbrtf((float)a);
}

static __forceinline__ double rcbrt(double a)
{
  return (double)rcbrtf((float)a);
}

static __forceinline__ double erf(double a)
{
  return (double)erff((float)a);
}

static __forceinline__ double erfinv(double a)
{
  return (double)erfinvf((float)a);
}

static __forceinline__ double erfc(double a)
{
  return (double)erfcf((float)a);
}

static __forceinline__ double erfcinv(double a)
{
  return (double)erfcinvf((float)a);
}

static __forceinline__ double lgamma(double a)
{
  return (double)lgammaf((float)a);
}

static __forceinline__ double tgamma(double a)
{
  return (double)tgammaf((float)a);
}

static __forceinline__ double ldexp(double a, int b)
{
  return (double)ldexpf((float)a, b);
}

static __forceinline__ double scalbn(double a, int b)
{
  return (double)scalbnf((float)a, b);
}

static __forceinline__ double scalbln(double a, long b)
{
  return (double)scalblnf((float)a, b);
}

static __forceinline__ double frexp(double a, int *b)
{
  return (double)frexpf((float)a, b);
}

static __forceinline__ double modf(double a, double *b)
{
  float fb;
  float fa = modff((float)a, &fb);

  *b = (double)fb;

  return (double)fa;  
}

static __forceinline__ double fmod(double a, double b)
{
  return (double)fmodf((float)a, (float)b);
}

static __forceinline__ double remainder(double a, double b)
{
  return (double)remainderf((float)a, (float)b);
}

static __forceinline__ double remquo(double a, double b, int *c)
{
  return (double)remquof((float)a, (float)b, c);
}

static __forceinline__ double nextafter(double a, double b)
{
  return (double)nextafterf((float)a, (float)b);
}

static __forceinline__ double nan(const char *tagp)
{
  return (double)nanf(tagp);
}

static __forceinline__ double pow(double a, double b)
{
  return (double)powf((float)a, (float)b);
}

static __forceinline__ double round(double a)
{
  return (double)roundf((float)a);
}

static __forceinline__ long lround(double a)
{
  return lroundf((float)a);
}

static __forceinline__ long long llround(double a)
{
  return llroundf((float)a);
}

static __forceinline__ double rint(double a)
{
  return (double)rintf((float)a);
}

static __forceinline__ long lrint(double a)
{
  return lrintf((float)a);
}

static __forceinline__ long long llrint(double a)
{
  return llrintf((float)a);
}

static __forceinline__ double nearbyint(double a)
{
  return (double)nearbyintf((float)a);
}

static __forceinline__ double fdim(double a, double b)
{
  return (double)fdimf((float)a, (float)b);
}

static __forceinline__ int ilogb(double a)
{
  return ilogbf((float)a);
}

static __forceinline__ double logb(double a)
{
  return (double)logbf((float)a);
}

static __forceinline__ double fma(double a, double b, double c)
{
  return (double)fmaf((float)a, (float)b, (float)c);
}

#if defined(__APPLE__)

static __forceinline__ int __isfinited(double a)
{
  return (double)__finitef((float)a);
}

static __forceinline__ int __signbitd(double a)
{
  return (double)__signbitf((float)a);
}

#endif /* __APPLE__ */

#endif /* __CUDABE__ */

#endif /* __MATH_FUNCTIONS_DBL_PTX1_H__ */
