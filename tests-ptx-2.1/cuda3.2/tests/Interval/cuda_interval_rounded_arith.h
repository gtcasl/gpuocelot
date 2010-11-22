/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

// Type-specific implementation of rounded arithmetic operators.
// Thin layer over the CUDA intrinsics.

#ifndef CUDA_INTERVAL_ROUNDED_ARITH_H
#define CUDA_INTERVAL_ROUNDED_ARITH_H

// Temporary workaround for CUDA 3.0/3.1 on SM 1.3 devices:
// missing double-precision div/sqrt with directed rounding
#if defined(__CUDA_ARCH__) && __CUDA_ARCH__ <= 130
#define NO_DOUBLE_DIV
#endif

// Generic class, no actual implementation yet
template<class T>
struct rounded_arith
{
    __device__ T add_down (const T& x, const T& y);
    __device__ T add_up   (const T& x, const T& y);
    __device__ T sub_down (const T& x, const T& y);
    __device__ T sub_up   (const T& x, const T& y);
    __device__ T mul_down (const T& x, const T& y);
    __device__ T mul_up   (const T& x, const T& y);
    __device__ T div_down (const T& x, const T& y);
    __device__ T div_up   (const T& x, const T& y);
    __device__ T median   (const T& x, const T& y);
    __device__ T sqrt_down(const T& x);
    __device__ T sqrt_up  (const T& x);
    __device__ T int_down (const T& x);
    __device__ T int_up   (const T& x);
    
    __device__ T pos_inf();
    __device__ T neg_inf();
    __device__ __host__ T nan();
    __device__ T min(T const & x, T const & y);
    __device__ T max(T const & x, T const & y);
};


// Specialization for float
template<>
struct rounded_arith<float>
{
    __device__ float add_down (const float& x, const float& y) {
        return __fadd_rd(x, y);
    }

    __device__ float add_up   (const float& x, const float& y) {
        return __fadd_ru(x, y);
    }
    
    __device__ float sub_down (const float& x, const float& y) {
        return __fadd_rd(x, -y);
    }
    
    __device__ float sub_up   (const float& x, const float& y) {
        return __fadd_ru(x, -y);
    }
    
    __device__ float mul_down (const float& x, const float& y) {
        return __fmul_rd(x, y);
    }
    
    __device__ float mul_up   (const float& x, const float& y) {
        return __fmul_ru(x, y);
    }
    
    __device__ float div_down (const float& x, const float& y) {
        return __fdiv_rd(x, y);
    }
    
    __device__ float div_up   (const float& x, const float& y) {
        return __fdiv_ru(x, y);
    }
    
    __device__ float median   (const float& x, const float& y) {
        return (x + y) * .5f;
    }
    
    __device__ float sqrt_down(const float& x) {
        return __fsqrt_rd(x);
    }
    
    __device__ float sqrt_up  (const float& x) {
        return __fsqrt_ru(x);
    }
    
    __device__ float int_down (const float& x) {
        return floorf(x);
    }
    
    __device__ float int_up   (const float& x) {
        return ceilf(x);
    }

    __device__ float neg_inf() {
        return __int_as_float(0xff800000);
    }

    __device__ float pos_inf() {
        return __int_as_float(0x7f800000);
    }

    __device__ __host__ float nan() {
        return nanf("");
    }
    
    __device__ float min(float const & x, float const & y) {
        return fminf(x, y);
    }

    __device__ float max(float const & x, float const & y) {
        return fmaxf(x, y);
    }
};

__device__ double my_div_ru(double a, double b)
{
    int expo;
    b = frexp(b, &expo);
    double y0 = (double)(1.0f / __double2float_rn(b));    // y0 22 bits

    // Cubic iteration from Alex
    double e1 = __fma_rn(-b, y0, 1.0);
    double e2 = __fma_rn(e1, e1, e1);
    double y2 = __fma_rn(y0, e2, y0);        // y2 ~ 1/b 66 bits + rounding RN => faithful

    double e3 = __fma_rn(-b, y2, 1.0);       // M
    double y3 = __fma_rn(y2, e3, y2);        // y3 ~ 1/b correct except for 1/(2-eps)

    double q0 = __dmul_rn(a, y0);
    double r0 = __fma_rn(-q0, b, a);         // M
    double q1 = __fma_rn(r0, y2, q0);        // q1 ~ a/b faithful
    
    double r1 = __fma_ru(-q1, b, a);         // M
    double q2 = __fma_ru(r1, y3, q1);        // q2 = a/b correct
    return ldexp(q2, -expo);
}

__device__ double my_div_rd(double a, double b)
{
    int expo;
    b = frexp(b, &expo);
    double y0 = (double)(1.0f / __double2float_rn(b));    // y0 22 bits

    double e1 = __fma_rn(-b, y0, 1.0);
    double e2 = __fma_rn(e1, e1, e1);
    double y2 = __fma_rn(y0, e2, y0);        // y2 ~ 1/b 66 bits + rounding RN => faithful

    double e3 = __fma_rn(-b, y2, 1.0);       // M
    double y3 = __fma_rn(y2, e3, y2);        // y3 ~ 1/b correct except for 1/(2-eps)

    double q0 = __dmul_rn(a, y0);
    double r0 = __fma_rn(-q0, b, a);         // M
    double q1 = __fma_rn(r0, y2, q0);        // q1 ~ a/b faithful
    
    double r1 = __fma_rd(-q1, b, a);         // M
    double q2 = __fma_rd(r1, y3, q1);
    return ldexp(q2, -expo);
}

// Specialization for double
template<>
struct rounded_arith<double>
{
    __device__ double add_down (const double& x, const double& y) {
        return __dadd_rd(x, y);
    }

    __device__ double add_up   (const double& x, const double& y) {
        return __dadd_ru(x, y);
    }
    
    __device__ double sub_down (const double& x, const double& y) {
        return __dadd_rd(x, -y);
    }
    
    __device__ double sub_up   (const double& x, const double& y) {
        return __dadd_ru(x, -y);
    }
    
    __device__ double mul_down (const double& x, const double& y) {
        return __dmul_rd(x, y);
    }
    
    __device__ double mul_up   (const double& x, const double& y) {
        return __dmul_ru(x, y);
    }
    
    __device__ double div_down (const double& x, const double& y) {
#ifndef NO_DOUBLE_DIV
        return __ddiv_rd(x, y);
#else
        return my_div_rd(x, y);
#endif
    }
    
    __device__ double div_up   (const double& x, const double& y) {
#ifndef NO_DOUBLE_DIV
        return __ddiv_ru(x, y);
#else
        return my_div_ru(x, y);
#endif    
    }
    __device__ double median   (const double& x, const double& y) {
        return (x + y) * .5;
    }
    
#ifndef NO_DOUBLE_DIV
    __device__ double sqrt_down(const double& x) {
        return __dsqrt_rd(x);
    }
    
    __device__ double sqrt_up  (const double& x) {
        return __dsqrt_ru(x);
    }
#endif    
    __device__ double int_down (const double& x) {
        return floor(x);
    }
    
    __device__ double int_up   (const double& x) {
        return ceil(x);
    }

    __device__ double neg_inf() {
        return __longlong_as_double(0xfff0000000000000ull);
    }

    __device__ double pos_inf() {
        return __longlong_as_double(0x7ff0000000000000ull);
    }
    __device__ __host__ double nan() {
        return ::nan("");
    }

    __device__ double min(double const & x, double const & y) {
        return fmin(x, y);
    }

    __device__ double max(double const & x, double const & y) {
        return fmax(x, y);
    }
};

#endif
