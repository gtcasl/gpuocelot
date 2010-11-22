#if !defined(CURAND_KERNEL_H_)
#define CURAND_KERNEL_H_

/**
 * \file
 * \name CURAND Device API
 * \author NVIDIA Corporation
 */

/**
 * \defgroup DEVICE Device API
 *
 * @{
 */
/** @} */

#include "curand.h"
#include "curand_precalc.h"
#include <math.h>

#define MAX_XOR_N (5)
#define SKIPAHEAD_BLOCKSIZE (4)
#define SKIPAHEAD_MASK ((1<<SKIPAHEAD_BLOCKSIZE)-1)
#define CURAND_2POW32_INV (2.3283064e-10f)
#define CURAND_2POW32_INV_DOUBLE (2.3283064365386963e-10)
#define CURAND_2POW53_INV_DOUBLE (1.1102230246251565e-16)
#define CURAND_2POW32_INV_2PI (2.3283064e-10f * 6.2831855f)
#define CURAND_2POW53_INV_2PI_DOUBLE (1.1102230246251565e-16 * 6.2831853071795860)
#define CURAND_SQRT2 (-1.4142135f)
#define CURAND_SQRT2_DOUBLE (-1.4142135623730951)

#if !defined(QUALIFIERS)
#define QUALIFIERS static inline __device__
#endif

/* Test RNG */
/* This generator uses the formula:
   x_n = x_(n-1) + 1 mod 2^32
   x_0 = (unsigned int)seed * 3
   Subsequences are spaced 31337 steps apart.
*/
struct curandStateTest {
    unsigned int v;
};

typedef struct curandStateTest curandStateTest_t;

/* XORSHIFT FAMILY RNGs */
/* These generators are a family proposed by Marsaglia.  They keep state
   in 32 bit chunks, then use repeated shift and xor operations to scramble
   the bits.  The following generators are a combination of a simple Weyl
   generator with an N variable XORSHIFT generator.
*/

/* XORSHIFT RNG */
/* This generator uses the xorwow formula of
www.jstatsoft.org/v08/i14/paper page 5
Has period 2^192 - 2^32.
*/
/**
 * CURAND XORWOW state 
 */
struct curandStateXORWOW;

/**
 * CURAND XORWOW state 
 */
typedef struct curandStateXORWOW curandStateXORWOW_t;

/* Implementation details not in reference documentation */
struct curandStateXORWOW {
    unsigned int d, v[5];
    int boxmuller_flag;
    float boxmuller_extra;
    double boxmuller_extra_double;
};

/* SOBOL QRNG */
/**
 * CURAND Sobol32 state 
 */
struct curandStateSobol32;

/* Implementation details not in reference documentation */
struct curandStateSobol32 {
    unsigned int i, x;
    unsigned int direction_vectors[32];
};

/**
 * CURAND Sobol32 state 
 */
typedef struct curandStateSobol32 curandStateSobol32_t;

/**
 * Default RNG
 */
typedef struct curandStateXORWOW curandState_t;
typedef struct curandStateXORWOW curandState;

/****************************************************************************/
/* Utility functions needed by RNGs */
/****************************************************************************/

/* multiply vector by matrix, store in result
   matrix is n x n, measured in 32 bit units
   matrix is stored in row major order
   vector and result cannot be same pointer
*/
QUALIFIERS void __curand_matvec(unsigned int *vector, unsigned int *matrix, 
                                unsigned int *result, int n)
{
    for(int i = 0; i < n; i++) {
        result[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 32; j++) {
            if(vector[i] & (1 << j)) {
                for(int k = 0; k < n; k++) {
                    result[k] ^= matrix[n * (i * 32 + j) + k];
                }
            }
        }
    }
}

/* generate identity matrix */
QUALIFIERS void __curand_matidentity(unsigned int *matrix, int n)
{
    int r;
    for(int i = 0; i < n * 32; i++) {
        for(int j = 0; j < n; j++) {
            r = i & 31;
            if(i / 32 == j) {
                matrix[i * n + j] = (1 << r);
            } else {
                matrix[i * n + j] = 0;
            }
        }
    }
}

/* multiply matrixA by matrixB, store back in matrixA
   matrixA and matrixB must not be same matrix */
QUALIFIERS void __curand_matmat(unsigned int *matrixA, unsigned int *matrixB, int n)
{
    unsigned int result[MAX_XOR_N];
    for(int i = 0; i < n * 32; i++) {
        __curand_matvec(matrixA + i * n, matrixB, result, n);
        for(int j = 0; j < n; j++) {
            matrixA[i * n + j] = result[j];
        }
    }
}

/* copy vectorA to vector */
QUALIFIERS void __curand_veccopy(unsigned int *vector, unsigned int *vectorA, int n)
{
    for(int i = 0; i < n; i++) {
        vector[i] = vectorA[i];
    }
}

/* copy matrixA to matrix */
QUALIFIERS void __curand_matcopy(unsigned int *matrix, unsigned int *matrixA, int n)
{
    for(int i = 0; i < n * n * 32; i++) {
        matrix[i] = matrixA[i];
    }
}

/* compute matrixA to power p, store result in matrix */
QUALIFIERS void __curand_matpow(unsigned int *matrix, unsigned int *matrixA, 
                                unsigned long long p, int n)
{
    unsigned int matrixR[MAX_XOR_N * MAX_XOR_N * 32];
    unsigned int matrixS[MAX_XOR_N * MAX_XOR_N * 32];
    __curand_matidentity(matrix, n);
    __curand_matcopy(matrixR, matrixA, n);
    while(p) {
        if(p & 1) {
            __curand_matmat(matrix, matrixR, n);
        }
        __curand_matcopy(matrixS, matrixR, n);
        __curand_matmat(matrixR, matrixS, n);
        p >>= 1;
    }
}

/* Convert unsigned int to float, use no intrinsics */
QUALIFIERS float __curand_uint32AsFloat (unsigned int i)
{
    union {
        float f;
        unsigned int i;
    } xx;
    xx.i = i;
    return xx.f;
}

/* Convert two unsigned ints to double, use no intrinsics */
QUALIFIERS double __curand_hilouint32AsDouble (unsigned int hi, unsigned int lo)
{
    union {
        double f;
        unsigned int hi;
        unsigned int lo;
    } xx;
    xx.hi = hi;
    xx.lo = lo;
    return xx.f;
}

/* Convert unsigned int to float, as efficiently as possible */
QUALIFIERS float __curand_uint32_as_float(unsigned int x)
{
#if __CUDA_ARCH__ > 0
    return __int_as_float(x);
#elif !defined(__CUDA_ARCH__)
    return __curand_uint32AsFloat(x);
#endif
}

/*
QUALIFIERS double __curand_hilouint32_as_double(unsigned int hi, unsigned int lo)
{
#if __CUDA_ARCH__ > 0
    return __hiloint2double(hi, lo);
#elif !defined(__CUDA_ARCH__)
    return hilouint32AsDouble(hi, lo);
#endif
}
*/

/****************************************************************************/
/* Kernel implementations of RNGs */
/****************************************************************************/

/* Test RNG */

QUALIFIERS void curand_init(unsigned long long seed, 
                                            unsigned long long subsequence, 
                                            unsigned long long offset, 
                                            curandStateTest_t *state)
{
    state->v = (unsigned int)(seed * 3) + (unsigned int)(subsequence * 31337) + \
                     (unsigned int)offset;
}

QUALIFIERS unsigned int curand(curandStateTest_t *state)
{
    unsigned int r = state->v++;
    return r;
}

QUALIFIERS void skipahead(unsigned long long n, curandStateTest_t *state)
{
    state->v += (unsigned int)n;
}

/* XORWOW RNG */

template <typename T, int n>
QUALIFIERS void __curand_generate_skipahead_matrix_xor(unsigned int matrix[])
{
    T state;
    // Generate matrix that advances one step
    // matrix has n * n * 32 32-bit elements
    // solve for matrix by stepping single bit states
    for(int i = 0; i < 32 * n; i++) {
        state.d = 0;
        for(int j = 0; j < n; j++) {
            state.v[j] = 0;
        }
        state.v[i / 32] = (1 << (i & 31));
        curand(&state);
        for(int j = 0; j < n; j++) {
            matrix[i * n + j] = state.v[j];
        }
    }
}

template <typename T, int n>
QUALIFIERS void skipahead(unsigned long long x, T *state)
{
    unsigned int matrix[n * n * 32], matrixA[n * n * 32], vector[n], result[n];
    unsigned long long p = x;
    for(int i = 0; i < n; i++) {
        vector[i] = state->v[i];
    }
    if(p) {
        __curand_generate_skipahead_matrix_xor<T, n>(matrixA);
        __curand_matcopy(matrix, matrixA, n);
    }
    while(p) {
        for(unsigned int t = 0; t < (p & SKIPAHEAD_MASK); t++) {
            __curand_matvec(vector, matrixA, result, n);
            __curand_veccopy(vector, result, n);
        }
        p >>= SKIPAHEAD_BLOCKSIZE;
        if(p) {
            for(int i = 0; i < SKIPAHEAD_BLOCKSIZE; i++) {
                __curand_matmat(matrix, matrixA, n);
                __curand_matcopy(matrixA, matrix, n);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        state->v[i] = vector[i];
    }
    state->d += 362437 * (unsigned int)x;
}

template <typename T, int n>
QUALIFIERS void skipahead_sequence(unsigned long long x, T *state)
{
    unsigned int matrix[n * n * 32], matrixA[n * n * 32], vector[n], result[n];
    unsigned long long p = x;
    for(int i = 0; i < n; i++) {
        vector[i] = state->v[i];
    }
    int matrix_num = 0;
    while(p && matrix_num < PRECALC_NUM_MATRICES - 1) {
        for(unsigned int t = 0; t < (p & PRECALC_BLOCK_MASK); t++) {
#ifdef __CUDA_ARCH__
            __curand_matvec(vector, precalc_xorwow_matrix[matrix_num], result, n);
#else
            __curand_matvec(vector, precalc_xorwow_matrix_host[matrix_num], result, n);
#endif
            __curand_veccopy(vector, result, n);
        }
        p >>= PRECALC_BLOCK_SIZE;
        matrix_num++;
    }
    if(p) {
#ifdef __CUDA_ARCH__
        __curand_matcopy(matrix, precalc_xorwow_matrix[PRECALC_NUM_MATRICES - 1], n);
        __curand_matcopy(matrixA, precalc_xorwow_matrix[PRECALC_NUM_MATRICES - 1], n);
#else
        __curand_matcopy(matrix, precalc_xorwow_matrix_host[PRECALC_NUM_MATRICES - 1], n);
        __curand_matcopy(matrixA, precalc_xorwow_matrix_host[PRECALC_NUM_MATRICES - 1], n);
#endif
    }
    while(p) {
        for(unsigned int t = 0; t < (p & SKIPAHEAD_MASK); t++) {
            __curand_matvec(vector, matrixA, result, n);
            __curand_veccopy(vector, result, n);
        }
        p >>= SKIPAHEAD_BLOCKSIZE;
        if(p) {
            for(int i = 0; i < SKIPAHEAD_BLOCKSIZE; i++) {
                __curand_matmat(matrix, matrixA, n);
                __curand_matcopy(matrixA, matrix, n);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        state->v[i] = vector[i];
    }
    /* No update of state->d needed, guaranteed to be a multiple of 2^32 */
}

/**
 * \brief Update XORWOW state to skip \p n elements.
 *
 * Update the XORWOW state in \p state to skip ahead \p n elements.
 *
 * All values of \p n are valid.  Large values require more computation and so
 * will take more time to complete.
 *
 * \param n - Number of elements to skip
 * \param state - Pointer to state to update
 */
QUALIFIERS void skipahead(unsigned long long n, curandStateXORWOW_t *state)
{
    skipahead<curandStateXORWOW_t, 5>(n, state);
}

/**
 * \brief Update XORWOW state to skip ahead \p n subsequences.
 *
 * Update the XORWOW state in \p state to skip ahead \p n subsequences.  Each
 * subsequence is \f$ 2^{67} \f$ elements long, so this means the function will skip ahead
 * \f$ 2^{67} \cdot n\f$ elements.
 *
 * All values of \p n are valid.  Large values require more computation and so
 * will take more time to complete.
 *
 * \param n - Number of subsequences to skip
 * \param state - Pointer to state to update
 */
QUALIFIERS void skipahead_sequence(unsigned long long n, curandStateXORWOW_t *state)
{
    skipahead_sequence<curandStateXORWOW_t, 5>(n, state);
}

/**
 * \brief Initialize XORWOW state.
 *
 * Initialize XORWOW state in \p state with the given \p seed, \p subsequence,
 * and \p offset.
 *
 * All input values of \p seed, \p subsequence, and \p offset are legal.  Large
 * values for \p subsequence and \p offset require more computation and so will
 * take more time to complete.
 *
 * A value of 0 for \p seed sets the state to the values of the original
 * published version of the \p xorwow algorithm.
 *
 * \param seed - Arbitrary bits to use as a seed
 * \param subsequence - Subsequence to start at
 * \param offset - Absolute offset into sequence
 * \param state - Pointer to state to initialize
 */
QUALIFIERS void curand_init(unsigned long long seed, 
                                            unsigned long long subsequence, 
                                            unsigned long long offset, 
                                            curandStateXORWOW_t *state)
{
    // Break up seed, apply salt
    unsigned int s0 = ((unsigned int)seed) ^ 0xaad26b49UL;
    unsigned int s1 = (unsigned int)(seed >> 32) ^ 0xf7dcefddUL;
    // Simple multiplication to mix up bits
    unsigned int t0 = 1099087573UL * s0;
    unsigned int t1 = 2591861531UL * s1;
    state->d = 6615241 + t1 + t0;
    state->v[0] = 123456789UL + t0;
    state->v[1] = 362436069UL ^ t0;
    state->v[2] = 521288629UL + t1;
    state->v[3] = 88675123UL ^ t1;
    state->v[4] = 5783321UL + t0;
    skipahead(offset, state);
    skipahead_sequence(subsequence, state);
    state->boxmuller_flag = 0;
}

/**
 * \brief Return 32-bits of pseudorandomness from an XORWOW generator.
 *
 * Return 32-bits of pseudorandomness from the XORWOW generator in \p state,
 * increment position of generator by one.
 *
 * \param state - Pointer to state to update
 *
 * \return 32-bits of pseudorandomness as an unsigned int, all bits valid to use.
 */
QUALIFIERS unsigned int curand(curandStateXORWOW_t *state)
{
    unsigned int t;
    t = (state->v[0] ^ (state->v[0] >> 2));
    state->v[0] = state->v[1];
    state->v[1] = state->v[2];
    state->v[2] = state->v[3];
    state->v[3] = state->v[4];
    state->v[4] = (state->v[4] ^ (state->v[4] <<4)) ^ (t ^ (t << 1));
    state->d += 362437;
    return state->v[4] + state->d;
}

/**
 * \brief Update Sobol32 state to skip \p n elements.
 *
 * Update the Sobol32 state in \p state to skip ahead \p n elements.
 *
 * All values of \p n are valid.
 *
 * \param n - Number of elements to skip
 * \param state - Pointer to state to update
 */

QUALIFIERS void skipahead(unsigned int n, curandStateSobol32_t *state)
{
    unsigned int i_gray;
    state->i += n;
    /* Convert state->i to gray code */
    i_gray = state->i ^ (state->i >> 1);
    state->x = 0;
    for(unsigned int k = 0; k < 32; k++) {
        if(i_gray & (1 << k)) {
            state->x ^= state->direction_vectors[k];
        }
    }
    return;
}

/**
 * \brief Initialize Sobol32 state.
 *
 * Initialize Sobol32 state in \p state with the given \p direction \p vectors and 
 * \p offset.
 *
 * The direction vector is a device pointer to an array of 32 unsigned ints.
 * All input values of \p offset are legal.
 *
 * \param direction vectors - Pointer to array of 32 unsigned ints representing the
 direction vectors for the desired dimension
 * \param offset - Absolute offset into sequence
 * \param state - Pointer to state to initialize
 */
QUALIFIERS void curand_init(curandDirectionVectors32_t direction_vectors,
                                            unsigned int offset, 
                                            curandStateSobol32_t *state)
{
    state->i = 0;
    for(int i = 0; i < 32; i++) {
        state->direction_vectors[i] = direction_vectors[i];
    }
    state->x = 0;
    skipahead(offset, state);
}

QUALIFIERS int __curand_find_trailing_zero(unsigned int x)
{
#if __CUDA_ARCH__ > 0
    int y = __ffs(~x);
    return y > 0 ? y - 1 : 31;
#else
    int i = 0;
    while(x & 1) {
        i ++;
        x >>= 1;
    }
    return i < 32 ? i : 31;
#endif
}    

QUALIFIERS void _skipahead_stride(int n_log2, curandStateSobol32_t *state)
{
    /* Moving from i to i+2^n_log2 element in gray code is flipping two bits */
    unsigned int shifted_i = state->i >> n_log2;
    state->x ^= state->direction_vectors[n_log2 - 1];
    state->x ^= state->direction_vectors[
        __curand_find_trailing_zero(shifted_i) + n_log2];
    state->i += 1 << n_log2;
}

/**
 * \brief Return 32-bits of quasirandomness from a Sobol32 generator.
 *
 * Return 32-bits of quasirandomness from the Sobol32 generator in \p state,
 * increment position of generator by one.
 *
 * \param state - Pointer to state to update
 *
 * \return 32-bits of quasirandomness as an unsigned int, all bits valid to use.
 */
QUALIFIERS unsigned int curand(curandStateSobol32_t *state)
{
    /* Moving from i to i+1 element in gray code is flipping one bit,
       the trailing zero bit of i
    */
    unsigned int res = state->x;
    state->x ^= state->direction_vectors[__curand_find_trailing_zero(state->i)];
    state->i ++;
    return res;
}


/******************************************************/

QUALIFIERS float _curand_uniform(unsigned int x)
{
    return x * CURAND_2POW32_INV + (CURAND_2POW32_INV/2.0f);
}

QUALIFIERS double _curand_uniform_double(unsigned int x)
{
    return x * CURAND_2POW32_INV_DOUBLE + (CURAND_2POW32_INV_DOUBLE/2.0);
}

QUALIFIERS double _curand_uniform_double_hq(unsigned int x, unsigned int y)
{
    unsigned long long z = (unsigned long long)x ^ 
        ((unsigned long long)y << (53 - 32));
    return z * CURAND_2POW53_INV_DOUBLE + (CURAND_2POW53_INV_DOUBLE/2.0);
}

QUALIFIERS float curand_uniform(curandStateTest_t *state)
{
    return _curand_uniform(curand(state));
}

QUALIFIERS double curand_uniform_double(curandStateTest_t *state)
{
    return _curand_uniform_double(curand(state));
}

/**
 * \brief Return a uniformly distributed float from an XORWOW generator.
 *
 * Return a uniformly distributed float between \p 0.0f and \p 1.0f 
 * from the XORWOW generator in \p state, increment position of generator.
 * Output range excludes \p 0.0f but includes \p 1.0f.  Denormalized floating
 * point outputs are never returned.
 *
 * The implementation may use any number of calls to \p curand() to
 * get enough random bits to create the return value.  The current
 * implementation uses one call.
 *
 * \param state - Pointer to state to update
 *
 * \return uniformly distributed float between \p 0.0f and \p 1.0f
 */
QUALIFIERS float curand_uniform(curandStateXORWOW_t *state)
{
    return _curand_uniform(curand(state));
}

/**
 * \brief Return a uniformly distributed double from an XORWOW generator.
 *
 * Return a uniformly distributed double between \p 0.0 and \p 1.0 
 * from the XORWOW generator in \p state, increment position of generator.
 * Output range excludes \p 0.0 but includes \p 1.0.  Denormalized floating
 * point outputs are never returned.
 *
 * The implementation may use any number of calls to \p curand() to
 * get enough random bits to create the return value.  The current
 * implementation uses exactly two calls.
 *
 * \param state - Pointer to state to update
 *
 * \return uniformly distributed double between \p 0.0 and \p 1.0
 */
QUALIFIERS double curand_uniform_double(curandStateXORWOW_t *state)
{
    unsigned int x, y;
    x = curand(state);
    y = curand(state);
    return _curand_uniform_double_hq(x, y);
}

/**
 * \brief Return a uniformly distributed float from a Sobol32 generator.
 *
 * Return a uniformly distributed float between \p 0.0f and \p 1.0f 
 * from the Sobol32 generator in \p state, increment position of generator.
 * Output range excludes \p 0.0f but includes \p 1.0f.  Denormalized floating
 * point outputs are never returned.
 *
 * The implementation is guaranteed to use a single call to \p curand().
 *
 * \param state - Pointer to state to update
 *
 * \return uniformly distributed float between \p 0.0f and \p 1.0f
 */
QUALIFIERS float curand_uniform(curandStateSobol32_t *state)
{
    return _curand_uniform(curand(state));
}

/**
 * \brief Return a uniformly distributed double from a Sobol32 generator.
 *
 * Return a uniformly distributed double between \p 0.0 and \p 1.0 
 * from the Sobol32 generator in \p state, increment position of generator.
 * Output range excludes \p 0.0 but includes \p 1.0.  Denormalized floating
 * point outputs are never returned.
 *
 * The implementation is guaranteed to use a single call to \p curand()
 * to preserve the quasirandom properties of the sequence.
 *
 * \param state - Pointer to state to update
 *
 * \return uniformly distributed double between \p 0.0 and \p 1.0
 */
QUALIFIERS double curand_uniform_double(curandStateSobol32_t *state)
{
    return _curand_uniform_double(curand(state));
}

QUALIFIERS float2 _curand_box_muller(unsigned int x, unsigned int y)
{
    float2 result;
    float u = x * CURAND_2POW32_INV + (CURAND_2POW32_INV/2);
    float v = y * CURAND_2POW32_INV_2PI + (CURAND_2POW32_INV_2PI/2);
#if __CUDA_ARCH__ > 0
    float s = sqrtf(-2.0f * __logf(u));
    result.x = s * __sinf(v);
    result.y = s * __cosf(v);
#else
    float s = sqrtf(-2.0f * logf(u));
    result.x = s * sinf(v);
    result.y = s * cosf(v);
#endif
    return result;
}

QUALIFIERS double2 
_curand_box_muller_double(unsigned int x0, unsigned int x1, 
                          unsigned int y0, unsigned int y1)
{
    double2 result;
    unsigned long long zx = (unsigned long long)x0 ^ 
        ((unsigned long long)x1 << (53 - 32));
    double u = zx * CURAND_2POW53_INV_DOUBLE + (CURAND_2POW53_INV_DOUBLE/2.0);
    unsigned long long zy = (unsigned long long)y0 ^ 
        ((unsigned long long)y1 << (53 - 32));
    double v = zy * CURAND_2POW53_INV_2PI_DOUBLE + (CURAND_2POW53_INV_2PI_DOUBLE/2.0);
    double s = sqrt(-2.0 * log(u));
    result.x = s * sin(v);
    result.y = s * cos(v);
    return result;
}

template <typename R>
QUALIFIERS float2 curand_box_muller(R *state)
{
    float2 result;
    unsigned int x = curand(state);
    unsigned int y = curand(state);
    result = _curand_box_muller(x, y);
    return result;
}

template <typename R>
QUALIFIERS double2 curand_box_muller_double(R *state)
{
    double2 result;
    unsigned int x0 = curand(state);
    unsigned int x1 = curand(state);
    unsigned int y0 = curand(state);
    unsigned int y1 = curand(state);
    result = _curand_box_muller_double(x0, x1, y0, y1);
    return result;
}

QUALIFIERS float _curand_normal_icdf(unsigned int x)
{
#if __CUDA_ARCH__ > 0 || defined(HOST_HAVE_ERFCINVF)
    float s = CURAND_SQRT2;
    // Mirror to avoid loss of precision
    if(x > 0x80000000UL) {
        x = 0xffffffffUL - x;
        s = -s;
    }
    float p = x * CURAND_2POW32_INV + (CURAND_2POW32_INV/2.0f);
    // p is in (0, 0.5], 2p is in (0, 1]
    return s * erfcinvf(2.0f * p);
#else
    return 0.0f;
#endif
}

QUALIFIERS double _curand_normal_icdf_double(unsigned int x)
{
#if __CUDA_ARCH__ > 0 || defined(HOST_HAVE_ERFCINVF)
    double s = CURAND_SQRT2_DOUBLE;
    // Mirror to avoid loss of precision
    if(x > 0x80000000UL) {
        x = 0xffffffffUL - x;
        s = -s;
    }
    double p = x * CURAND_2POW32_INV_DOUBLE + (CURAND_2POW32_INV_DOUBLE/2.0);
    // p is in (0, 0.5], 2p is in (0, 1]
    return s * erfcinv(2.0 * p);
#else
    return 0.0;
#endif
}

/**
 * \brief Return a normally distributed float from an XORWOW generator.
 *
 * Return a single normally distributed float with mean \p 0.0f and
 * standard deviation \p 1.0f from the XORWOW generator in \p state,
 * increment position of generator by one.
 *
 * The implementation uses a Box-Muller transform to generate two
 * normally distributed results, then returns them one at a time.
 * See ::curand_normal2() for a more efficient version that returns
 * both results at once.
 *
 * \param state - Pointer to state to update
 *
 * \return Normally distributed float with mean \p 0.0f and standard deviation \p 1.0f
 */
QUALIFIERS float curand_normal(curandStateXORWOW_t *state)
{
    if(state->boxmuller_flag == 0) {
        unsigned int x, y;
        x = curand(state);
        y = curand(state);
        float2 v = _curand_box_muller(x, y);
        state->boxmuller_extra = v.y;
        state->boxmuller_flag = 1;
        return v.x;
    }
    state->boxmuller_flag = 0;
    return state->boxmuller_extra;
}

/**
 * \brief Return two normally distributed floats from an XORWOW generator.
 *
 * Return two normally distributed floats with mean \p 0.0f and
 * standard deviation \p 1.0f from the XORWOW generator in \p state,
 * increment position of generator by two.
 *
 * The implementation uses a Box-Muller transform to generate two
 * normally distributed results.
 *
 * \param state - Pointer to state to update
 *
 * \return Normally distributed float2 where each element is from a
 * distribution with mean \p 0.0f and standard deviation \p 1.0f
 */
QUALIFIERS float2 curand_normal2(curandStateXORWOW_t *state)
{
    return curand_box_muller(state);
}

/**
 * \brief Return a normally distributed float from an Sobol32 generator.
 *
 * Return a single normally distributed float with mean \p 0.0f and
 * standard deviation \p 1.0f from the Sobol32 generator in \p state,
 * increment position of generator by one.
 *
 * The implementation uses the inverse cumulative distribution function
 * to generate normally distributed results.
 *
 * \param state - Pointer to state to update
 *
 * \return Normally distributed float with mean \p 0.0f and standard deviation \p 1.0f
 */
QUALIFIERS float curand_normal(curandStateSobol32_t *state)
{
    return _curand_normal_icdf(curand(state));
}

/**
 * \brief Return a normally distributed double from an XORWOW generator.
 *
 * Return a single normally distributed double with mean \p 0.0 and
 * standard deviation \p 1.0 from the XORWOW generator in \p state,
 * increment position of generator.
 *
 * The implementation uses a Box-Muller transform to generate two
 * normally distributed results, then returns them one at a time.
 * See ::curand_normal2_double() for a more efficient version that returns
 * both results at once.
 *
 * \param state - Pointer to state to update
 *
 * \return Normally distributed double with mean \p 0.0 and standard deviation \p 1.0
 */
QUALIFIERS double curand_normal_double(curandStateXORWOW_t *state)
{
    if(state->boxmuller_flag == 0) {
        unsigned int x0, x1, y0, y1;
        x0 = curand(state);
        x1 = curand(state);
        y0 = curand(state);
        y1 = curand(state);
        double2 v = _curand_box_muller_double(x0, x1, y0, y1);
        state->boxmuller_extra_double = v.y;
        state->boxmuller_flag = 1;
        return v.x;
    }
    state->boxmuller_flag = 0;
    return state->boxmuller_extra_double;
}

/**
 * \brief Return two normally distributed doubles from an XORWOW generator.
 *
 * Return two normally distributed doubles with mean \p 0.0 and
 * standard deviation \p 1.0 from the XORWOW generator in \p state,
 * increment position of generator.
 *
 * The implementation uses a Box-Muller transform to generate two
 * normally distributed results.
 *
 * \param state - Pointer to state to update
 *
 * \return Normally distributed double2 where each element is from a
 * distribution with mean \p 0.0 and standard deviation \p 1.0
 */
QUALIFIERS double2 curand_normal2_double(curandStateXORWOW_t *state)
{
    return curand_box_muller_double(state);
}

/**
 * \brief Return a normally distributed double from an Sobol32 generator.
 *
 * Return a single normally distributed double with mean \p 0.0 and
 * standard deviation \p 1.0 from the Sobol32 generator in \p state,
 * increment position of generator by one.
 *
 * The implementation uses the inverse cumulative distribution function
 * to generate normally distributed results.
 *
 * \param state - Pointer to state to update
 *
 * \return Normally distributed double with mean \p 0.0 and standard deviation \p 1.0
 */
QUALIFIERS double curand_normal_double(curandStateSobol32_t *state)
{
    return _curand_normal_icdf_double(curand(state));
}


__host__ __device__ static unsigned int *__get_precalculated_matrix(int n)
{
    if(n > 0) {
        return precalc_xorwow_matrix[n];
    } else {
        return precalc_xorwow_matrix_host[n];
    }
}

#endif // !defined(CURAND_KERNEL_H_)
