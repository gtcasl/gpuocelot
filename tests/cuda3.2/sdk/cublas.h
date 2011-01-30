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

/*
 * This is the public header file for the CUBLAS library, defining the API
 *
 * CUBLAS is an implementation of BLAS (Basic Linear Algebra Subroutines) 
 * on top of the CUDA driver. It allows access to the computational resources
 * of NVIDIA GPUs. The library is self-contained at the API level, i.e. no 
 * direct interaction with the CUDA driver is necessary.
 *
 * The basic model by which applications use the CUBLAS library is to create 
 * matrix and vector object in GPU memory space, fill them with data, then
 * call a sequence of BLAS functions, and finally upload the results from GPU
 * memory space back to the host. To accomplish this, CUBLAS provides helper 
 * functions for creating and destroying objects in GPU space, and to write 
 * data to, and retrieve data from, these objects.
 *
 * For maximum compatibility with existing Fortran environments, 
 * CUBLAS uses column-major storage and 1-based indexing. Calls to
 * CUBLAS functions look very similar to calls to the original Fortran
 * BLAS functions. For example, the Fortran function call 
 *
 *    SDOT(KRANK+1-J,W(I,J),MDW,W(J,J),MDW)
 *
 * would map to the CUBLAS function call made from C/C++ code:
 *
 *    #define IDX2(i,j,lead_dim) (((j)*(lead_dim))+(i))
 *    sdot(krank+1-j,w[IDX2(i,j,ldw)], mdw, w[IDX2(i,j,ldw)], mdw)
 *
 * Since the BLAS core functions (as opposed to the helper functions) do 
 * not return error status directly (for reasons of compatibility with 
 * existing BLAS libraries) CUBLAS provides a separate function to 
 * retrieve the last error that was recorded, to aid in debugging.
 *
 * Currently, only a subset of the BLAS core functions is implemented.
 *
 * The interface to the CUBLAS library is the header file cublas.h. 
 * Applications using CUBLAS need to link against the DSO cublas.so 
 * (Linux) or the DLL cublas.dll (Win32).
 */

#if !defined(CUBLAS_H_)
#define CUBLAS_H_

#ifdef __MULTI_CORE__
#error CUBLAS not supported on multicore
#endif

#ifndef CUBLASAPI
#ifdef _WIN32
#define CUBLASAPI __stdcall
#else
#define CUBLASAPI 
#endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#include "driver_types.h"
#include "cuComplex.h"   /* import complex data type */

/* CUBLAS status returns */
#define CUBLAS_STATUS_SUCCESS           0x00000000
#define CUBLAS_STATUS_NOT_INITIALIZED   0x00000001
#define CUBLAS_STATUS_ALLOC_FAILED      0x00000003
#define CUBLAS_STATUS_INVALID_VALUE     0x00000007
#define CUBLAS_STATUS_ARCH_MISMATCH     0x00000008
#define CUBLAS_STATUS_MAPPING_ERROR     0x0000000B
#define CUBLAS_STATUS_EXECUTION_FAILED  0x0000000D
#define CUBLAS_STATUS_INTERNAL_ERROR    0x0000000E

/* CUBLAS data types */
typedef unsigned int cublasStatus;

/* CUBLAS helper functions */

/*
 * cublasStatus 
 * cublasInit (void)
 *
 * initializes the CUBLAS library and must be called before any other 
 * CUBLAS API function is invoked. It allocates hardware resources 
 * necessary for accessing the GPU.
 *
 * Return Values
 * -------------
 * CUBLAS_STATUS_ALLOC_FAILED     if resources could not be allocated
 * CUBLAS_STATUS_SUCCESS          if CUBLAS library initialized successfully
 */
cublasStatus CUBLASAPI cublasInit (void);

/*
 * cublasStatus 
 * cublasShutdown (void)
 *
 * releases CPU-side resources used by the CUBLAS library. The release of 
 * GPU-side resources may be deferred until the application shuts down.
 *
 * Return Values
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_SUCCESS          if CUBLAS library shut down successfully
 */
cublasStatus CUBLASAPI cublasShutdown (void);

/* 
 * cublasStatus 
 * cublasGetError (void)
 *
 * returns the last error that occurred on invocation of any of the
 * CUBLAS BLAS functions. While the CUBLAS helper functions return status
 * directly, the BLAS functions do not do so for improved 
 * compatibility with existing environments that do not expect BLAS
 * functions to return status. Reading the error status via 
 * cublasGetError() resets the internal error state to 
 * CUBLAS_STATUS_SUCCESS.
 */
cublasStatus CUBLASAPI cublasGetError (void);

/*
 * cublasStatus 
 * cublasAlloc (int n, int elemSize, void **devicePtr)
 *
 * creates an object in GPU memory space capable of holding an array of
 * n elements, where each element requires elemSize bytes of storage. If 
 * the function call is successful, a pointer to the object in GPU memory 
 * space is placed in devicePtr. Note that this is a device pointer that
 * cannot be dereferenced in host code.
 *
 * Return Values
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n <= 0, or elemSize <= 0
 * CUBLAS_STATUS_ALLOC_FAILED     if the object could not be allocated due to
 *                                lack of resources.
 * CUBLAS_STATUS_SUCCESS          if storage was successfully allocated
 */
cublasStatus CUBLASAPI cublasAlloc (int n, int elemSize, void **devicePtr);

/*
 * cublasStatus 
 * cublasFree (const void *devicePtr)
 *
 * destroys the object in GPU memory space pointed to by devicePtr.
 *
 * Return Values
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INTERNAL_ERROR   if the object could not be deallocated
 * CUBLAS_STATUS_SUCCESS          if object was destroyed successfully
 */
cublasStatus CUBLASAPI cublasFree (const void *devicePtr);

/* 
 * cublasStatus 
 * cublasSetVector (int n, int elemSize, const void *x, int incx, 
 *                  void *y, int incy) 
 *
 * copies n elements from a vector x in CPU memory space to a vector y 
 * in GPU memory space. Elements in both vectors are assumed to have a 
 * size of elemSize bytes. Storage spacing between consecutive elements
 * is incx for the source vector x and incy for the destination vector
 * y. In general, y points to an object, or part of an object, allocated
 * via cublasAlloc(). Column major format for two-dimensional matrices
 * is assumed throughout CUBLAS. Therefore, if the increment for a vector 
 * is equal to 1, this access a column vector while using an increment 
 * equal to the leading dimension of the respective matrix accesses a 
 * row vector.
 *
 * Return Values
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx, incy, or elemSize <= 0
 * CUBLAS_STATUS_MAPPING_ERROR    if an error occurred accessing GPU memory   
 * CUBLAS_STATUS_SUCCESS          if the operation completed successfully
 */
cublasStatus CUBLASAPI cublasSetVector (int n, int elemSize, const void *x, 
                                        int incx, void *devicePtr, int incy);

/* 
 * cublasStatus 
 * cublasGetVector (int n, int elemSize, const void *x, int incx, 
 *                  void *y, int incy)
 * 
 * copies n elements from a vector x in GPU memory space to a vector y 
 * in CPU memory space. Elements in both vectors are assumed to have a 
 * size of elemSize bytes. Storage spacing between consecutive elements
 * is incx for the source vector x and incy for the destination vector
 * y. In general, x points to an object, or part of an object, allocated
 * via cublasAlloc(). Column major format for two-dimensional matrices
 * is assumed throughout CUBLAS. Therefore, if the increment for a vector 
 * is equal to 1, this access a column vector while using an increment 
 * equal to the leading dimension of the respective matrix accesses a 
 * row vector.
 *
 * Return Values
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx, incy, or elemSize <= 0
 * CUBLAS_STATUS_MAPPING_ERROR    if an error occurred accessing GPU memory   
 * CUBLAS_STATUS_SUCCESS          if the operation completed successfully
 */
cublasStatus CUBLASAPI cublasGetVector (int n, int elemSize, const void *x, 
                                        int incx, void *y, int incy);

/*
 * cublasStatus 
 * cublasSetMatrix (int rows, int cols, int elemSize, const void *A, 
 *                  int lda, void *B, int ldb)
 *
 * copies a tile of rows x cols elements from a matrix A in CPU memory
 * space to a matrix B in GPU memory space. Each element requires storage
 * of elemSize bytes. Both matrices are assumed to be stored in column 
 * major format, with the leading dimension (i.e. number of rows) of 
 * source matrix A provided in lda, and the leading dimension of matrix B
 * provided in ldb. In general, B points to an object, or part of an 
 * object, that was allocated via cublasAlloc().
 *
 * Return Values 
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if rows or cols < 0, or elemSize, lda, or 
 *                                ldb <= 0
 * CUBLAS_STATUS_MAPPING_ERROR    if error occurred accessing GPU memory
 * CUBLAS_STATUS_SUCCESS          if the operation completed successfully
 */
cublasStatus CUBLASAPI cublasSetMatrix (int rows, int cols, int elemSize, 
                                        const void *A, int lda, void *B, 
                                        int ldb);

/*
 * cublasStatus 
 * cublasGetMatrix (int rows, int cols, int elemSize, const void *A, 
 *                  int lda, void *B, int ldb)
 *
 * copies a tile of rows x cols elements from a matrix A in GPU memory
 * space to a matrix B in CPU memory space. Each element requires storage
 * of elemSize bytes. Both matrices are assumed to be stored in column 
 * major format, with the leading dimension (i.e. number of rows) of 
 * source matrix A provided in lda, and the leading dimension of matrix B
 * provided in ldb. In general, A points to an object, or part of an 
 * object, that was allocated via cublasAlloc().
 *
 * Return Values 
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if rows, cols, eleSize, lda, or ldb <= 0
 * CUBLAS_STATUS_MAPPING_ERROR    if error occurred accessing GPU memory
 * CUBLAS_STATUS_SUCCESS          if the operation completed successfully
 */
cublasStatus CUBLASAPI cublasGetMatrix (int rows, int cols, int elemSize, 
                                        const void *A, int lda, void *B,
                                        int ldb);


/*
 * cublasStatus 
 * cublasSetKernelStream ( cudaStream_t stream )
 *
 * set the CUBLAS stream in which all subsequent CUBLAS kernel launches will run.
 * By default, if the CUBLAS stream is not set, all kernels will use the NULL
 * stream. This routine can be used to change the stream between kernels launches
 * and can be used also to set the CUBLAS stream back to NULL.
 *
 * Return Values
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_SUCCESS          if stream set successfully
 */
cublasStatus CUBLASAPI cublasSetKernelStream (cudaStream_t stream);


/* 
 * cublasStatus 
 * cublasSetVectorAsync ( int n, int elemSize, const void *x, int incx, 
 *                       void *y, int incy, cudaStream_t stream );
 *
 * cublasSetVectorAsync has the same functionnality as cublasSetVector
 * but the transfer is done asynchronously within the CUDA stream passed
 * in parameter.
 *
 * Return Values
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx, incy, or elemSize <= 0
 * CUBLAS_STATUS_MAPPING_ERROR    if an error occurred accessing GPU memory   
 * CUBLAS_STATUS_SUCCESS          if the operation completed successfully
 */
cublasStatus CUBLASAPI cublasSetVectorAsync (int n, int elemSize, 
                                             const void *hostPtr, int incx, 
                                             void *devicePtr, int incy,
                                             cudaStream_t stream);
/* 
 * cublasStatus 
 * cublasGetVectorAsync( int n, int elemSize, const void *x, int incx, 
 *                       void *y, int incy, cudaStream_t stream)
 * 
 * cublasGetVectorAsync has the same functionnality as cublasGetVector
 * but the transfer is done asynchronously within the CUDA stream passed
 * in parameter.
 *
 * Return Values
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx, incy, or elemSize <= 0
 * CUBLAS_STATUS_MAPPING_ERROR    if an error occurred accessing GPU memory   
 * CUBLAS_STATUS_SUCCESS          if the operation completed successfully
 */
cublasStatus CUBLASAPI cublasGetVectorAsync (int n, int elemSize,
                                             const void *devicePtr, int incx,
                                             void *hostPtr, int incy,
                                             cudaStream_t stream);

/*
 * cublasStatus 
 * cublasSetMatrixAsync (int rows, int cols, int elemSize, const void *A, 
 *                       int lda, void *B, int ldb, cudaStream_t stream)
 *
 * cublasSetMatrixAsync has the same functionnality as cublasSetMatrix
 * but the transfer is done asynchronously within the CUDA stream passed
 * in parameter.
 *
 * Return Values 
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if rows or cols < 0, or elemSize, lda, or 
 *                                ldb <= 0
 * CUBLAS_STATUS_MAPPING_ERROR    if error occurred accessing GPU memory
 * CUBLAS_STATUS_SUCCESS          if the operation completed successfully
 */
cublasStatus CUBLASAPI cublasSetMatrixAsync (int rows, int cols, int elemSize,
                                             const void *A, int lda, void *B,
                                             int ldb, cudaStream_t stream);

/*
 * cublasStatus 
 * cublasGetMatrixAsync (int rows, int cols, int elemSize, const void *A, 
 *                       int lda, void *B, int ldb, cudaStream_t stream)
 *
 * cublasGetMatrixAsync has the same functionnality as cublasGetMatrix
 * but the transfer is done asynchronously within the CUDA stream passed
 * in parameter.
 *
 * Return Values 
 * -------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if rows, cols, eleSize, lda, or ldb <= 0
 * CUBLAS_STATUS_MAPPING_ERROR    if error occurred accessing GPU memory
 * CUBLAS_STATUS_SUCCESS          if the operation completed successfully
 */
cublasStatus CUBLASAPI cublasGetMatrixAsync (int rows, int cols, int elemSize,
                                             const void *A, int lda, void *B,
                                             int ldb, cudaStream_t stream);

/* ---------------- CUBLAS single-precision BLAS1 functions ---------------- */

/*
 * int 
 * cublasIsamax (int n, const float *x, int incx)
 *
 * finds the smallest index of the maximum magnitude element of single
 * precision vector x; that is, the result is the first i, i = 0 to n - 1, 
 * that maximizes abs(x[1 + i * incx])).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the smallest index (0 if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/isamax.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
int CUBLASAPI cublasIsamax (int n, const float *x, int incx);

/*
 * int 
 * cublasIsamin (int n, const float *x, int incx)
 *
 * finds the smallest index of the minimum magnitude element of single
 * precision vector x; that is, the result is the first i, i = 0 to n - 1, 
 * that minimizes abs(x[1 + i * incx])).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the smallest index (0 if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/scilib/blass.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
int CUBLASAPI cublasIsamin (int n, const float *x, int incx);

/*
 * float 
 * cublasSasum (int n, const float *x, int incx)
 *
 * computes the sum of the absolute values of the elements of single 
 * precision vector x; that is, the result is the sum from i = 0 to n - 1 of 
 * abs(x[1 + i * incx]).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the single precision sum of absolute values
 * (0 if n <= 0 or incx <= 0, or if an error occurs)
 *
 * Reference: http://www.netlib.org/blas/sasum.f
 *
 * Error status for this function can be retrieved via cublasGetError(). 
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
float CUBLASAPI cublasSasum (int n, const float *x, int incx);

/*
 * void
 * cublasSaxpy (int n, float alpha, const float *x, int incx, float *y, 
 *              int incy)
 *
 * multiplies single precision vector x by single precision scalar alpha 
 * and adds the result to single precision vector y; that is, it overwrites 
 * single precision y with single precision alpha * x + y. For i = 0 to n - 1, 
 * it replaces y[ly + i * incy] with alpha * x[lx + i * incx] + y[ly + i *
 * incy], where lx = 1 if incx >= 0, else lx = 1 +(1 - n) * incx, and ly is 
 * defined in a similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  single precision scalar multiplier
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 * y      single precision vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * y      single precision result (unchanged if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/saxpy.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSaxpy (int n, float alpha, const float *x, int incx, 
                            float *y, int incy);

/*
 * void 
 * cublasScopy (int n, const float *x, int incx, float *y, int incy)
 *
 * copies the single precision vector x to the single precision vector y. For 
 * i = 0 to n-1, copies x[lx + i * incx] to y[ly + i * incy], where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and ly is defined in a similar 
 * way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 * y      single precision vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * y      contains single precision vector x
 *
 * Reference: http://www.netlib.org/blas/scopy.f
 *
 * Error status for this function can be retrieved via cublasGetError(). 
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasScopy (int n, const float *x, int incx, float *y, 
                            int incy);

/*
 * float 
 * cublasSdot (int n, const float *x, int incx, const float *y, int incy)
 *
 * computes the dot product of two single precision vectors. It returns the 
 * dot product of the single precision vectors x and y if successful, and
 * 0.0f otherwise. It computes the sum for i = 0 to n - 1 of x[lx + i * 
 * incx] * y[ly + i * incy], where lx = 1 if incx >= 0, else lx = 1 + (1 - n)
 * *incx, and ly is defined in a similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 * y      single precision vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * returns single precision dot product (zero if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/sdot.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has nor been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to execute on GPU
 */
float CUBLASAPI cublasSdot (int n, const float *x, int incx, const float *y, 
                            int incy);

/*
 * float 
 * cublasSnrm2 (int n, const float *x, int incx)
 *
 * computes the Euclidean norm of the single precision n-vector x (with
 * storage increment incx). This code uses a multiphase model of 
 * accumulation to avoid intermediate underflow and overflow.
 *
 * Input
 * -----
 * n      number of elements in input vector
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns Euclidian norm (0 if n <= 0 or incx <= 0, or if an error occurs)
 *
 * Reference: http://www.netlib.org/blas/snrm2.f
 * Reference: http://www.netlib.org/slatec/lin/snrm2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
float CUBLASAPI cublasSnrm2 (int n, const float *x, int incx);

/*
 * void 
 * cublasSrot (int n, float *x, int incx, float *y, int incy, float sc, 
 *             float ss)
 *
 * multiplies a 2x2 matrix ( sc ss) with the 2xn matrix ( transpose(x) )
 *                         (-ss sc)                     ( transpose(y) )
 *
 * The elements of x are in x[lx + i * incx], i = 0 ... n - 1, where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and similarly for y using ly and 
 * incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 * y      single precision vector with n elements
 * incy   storage spacing between elements of y
 * sc     element of rotation matrix
 * ss     element of rotation matrix
 *
 * Output
 * ------
 * x      rotated vector x (unchanged if n <= 0)
 * y      rotated vector y (unchanged if n <= 0)
 *
 * Reference  http://www.netlib.org/blas/srot.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSrot (int n, float *x, int incx, float *y, int incy, 
                           float sc, float ss);

/*
 * void 
 * cublasSrotg (float *host_sa, float *host_sb, float *host_sc, float *host_ss)
 *
 * constructs the Givens tranformation
 *
 *        ( sc  ss )
 *    G = (        ) ,  sc^2 + ss^2 = 1,
 *        (-ss  sc )
 *
 * which zeros the second entry of the 2-vector transpose(sa, sb).
 *
 * The quantity r = (+/-) sqrt (sa^2 + sb^2) overwrites sa in storage. The 
 * value of sb is overwritten by a value z which allows sc and ss to be 
 * recovered by the following algorithm:
 *
 *    if z=1          set sc = 0.0 and ss = 1.0
 *    if abs(z) < 1   set sc = sqrt(1-z^2) and ss = z
 *    if abs(z) > 1   set sc = 1/z and ss = sqrt(1-sc^2)
 *
 * The function srot (n, x, incx, y, incy, sc, ss) normally is called next
 * to apply the transformation to a 2 x n matrix.
 * Note that this function is provided for completeness and run exclusively 
 * on the Host.
 *
 * Input
 * -----
 * sa     single precision scalar
 * sb     single precision scalar
 *
 * Output
 * ------
 * sa     single precision r
 * sb     single precision z
 * sc     single precision result
 * ss     single precision result
 *
 * Reference: http://www.netlib.org/blas/srotg.f
 *
 * This function does not set any error status.
 */
void CUBLASAPI cublasSrotg (float *host_sa, float *host_sb, float *host_sc, float *host_ss);

/*
 * void 
 * cublasSrotm (int n, float *x, int incx, float *y, int incy, 
 *              const float* sparam)
 *
 * applies the modified Givens transformation, h, to the 2 x n matrix
 *
 *    ( transpose(x) )
 *    ( transpose(y) )
 *
 * The elements of x are in x[lx + i * incx], i = 0 to n-1, where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and similarly for y using ly and 
 * incy. With sparam[0] = sflag, h has one of the following forms:
 *
 *        sflag = -1.0f   sflag = 0.0f    sflag = 1.0f    sflag = -2.0f
 *
 *        (sh00  sh01)    (1.0f  sh01)    (sh00  1.0f)    (1.0f  0.0f)
 *    h = (          )    (          )    (          )    (          )
 *        (sh10  sh11)    (sh10  1.0f)    (-1.0f sh11)    (0.0f  1.0f)
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 * y      single precision vector with n elements
 * incy   storage spacing between elements of y
 * sparam 5-element vector. sparam[0] is sflag described above. sparam[1] 
 *        through sparam[4] contain the 2x2 rotation matrix h: sparam[1]
 *        contains sh00, sparam[2] contains sh10, sparam[3] contains sh01,
 *        and sprams[4] contains sh11.
 *
 * Output
 * ------
 * x     rotated vector x (unchanged if n <= 0)
 * y     rotated vector y (unchanged if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/srotm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSrotm(int n, float *x, int incx, float *y, int incy, 
                           const float* sparam);

/*
 * void 
 * cublasSrotmg (float *host_psd1, float *host_psd2, float *host_psx1, const float *host_psy1,
 *                float *host_sparam)
 *
 * constructs the modified Givens transformation matrix h which zeros
 * the second component of the 2-vector transpose(sqrt(sd1)*sx1,sqrt(sd2)*sy1).
 * With sparam[0] = sflag, h has one of the following forms:
 *
 *        sflag = -1.0f   sflag = 0.0f    sflag = 1.0f    sflag = -2.0f
 *
 *        (sh00  sh01)    (1.0f  sh01)    (sh00  1.0f)    (1.0f  0.0f)
 *    h = (          )    (          )    (          )    (          )
 *        (sh10  sh11)    (sh10  1.0f)    (-1.0f sh11)    (0.0f  1.0f)
 *
 * sparam[1] through sparam[4] contain sh00, sh10, sh01, sh11, 
 * respectively. Values of 1.0f, -1.0f, or 0.0f implied by the value 
 * of sflag are not stored in sparam.
 * Note that this function is provided for completeness and run exclusively 
 * on the Host. 
 *
 * Input
 * -----
 * sd1    single precision scalar
 * sd2    single precision scalar
 * sx1    single precision scalar
 * sy1    single precision scalar
 *
 * Output
 * ------
 * sd1    changed to represent the effect of the transformation
 * sd2    changed to represent the effect of the transformation
 * sx1    changed to represent the effect of the transformation
 * sparam 5-element vector. sparam[0] is sflag described above. sparam[1] 
 *        through sparam[4] contain the 2x2 rotation matrix h: sparam[1]
 *        contains sh00, sparam[2] contains sh10, sparam[3] contains sh01,
 *        and sprams[4] contains sh11.
 *
 * Reference: http://www.netlib.org/blas/srotmg.f
 *
 * This functions does not set any error status.
 */
void CUBLASAPI cublasSrotmg (float *host_sd1, float *host_sd2, float *host_sx1, 
                             const float *host_sy1, float* host_sparam);

/*
 * void
 * sscal (int n, float alpha, float *x, int incx)
 *
 * replaces single precision vector x with single precision alpha * x. For i 
 * = 0 to n - 1, it replaces x[ix + i * incx] with alpha * x[ix + i * incx], 
 * where ix = 1 if incx >= 0, else ix = 1 + (1 - n) * incx.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  single precision scalar multiplier
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * x      single precision result (unchanged if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/sscal.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSscal (int n, float alpha, float *x, int incx);

/*
 * void
 * cublasSswap (int n, float *x, int incx, float *y, int incy)
 *
 * replaces single precision vector x with single precision alpha * x. For i 
 * = 0 to n - 1, it replaces x[ix + i * incx] with alpha * x[ix + i * incx], 
 * where ix = 1 if incx >= 0, else ix = 1 + (1 - n) * incx.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  single precision scalar multiplier
 * x      single precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * x      single precision result (unchanged if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/sscal.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSswap (int n, float *x, int incx, float *y, int incy);

/* ----------------- CUBLAS single-complex BLAS1 functions ----------------- */

/*
 * void
 * cublasCaxpy (int n, cuComplex alpha, const cuComplex *x, int incx, 
 *              cuComplex *y, int incy)
 *
 * multiplies single-complex vector x by single-complex scalar alpha and adds 
 * the result to single-complex vector y; that is, it overwrites single-complex
 * y with single-complex alpha * x + y. For i = 0 to n - 1, it replaces 
 * y[ly + i * incy] with alpha * x[lx + i * incx] + y[ly + i * incy], where 
 * lx = 0 if incx >= 0, else lx = 1 + (1 - n) * incx, and ly is defined in a 
 * similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  single-complex scalar multiplier
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 * y      single-complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * y      single-complex result (unchanged if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/caxpy.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCaxpy (int n, cuComplex alpha, const cuComplex *x, 
                            int incx, cuComplex *y, int incy);

/*
 * void
 * cublasCcopy (int n, const cuComplex *x, int incx, cuComplex *y, int incy)
 *
 * copies the single-complex vector x to the single-complex vector y. For 
 * i = 0 to n-1, copies x[lx + i * incx] to y[ly + i * incy], where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and ly is defined in a similar 
 * way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 * y      single-complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * y      contains single complex vector x
 *
 * Reference: http://www.netlib.org/blas/ccopy.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCcopy (int n, const cuComplex *x, int incx, cuComplex *y,
                            int incy);

/*
 * void
 * cublasZcopy (int n, const cuDoubleComplex *x, int incx, cuDoubleComplex *y, int incy)
 *
 * copies the double-complex vector x to the double-complex vector y. For 
 * i = 0 to n-1, copies x[lx + i * incx] to y[ly + i * incy], where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and ly is defined in a similar 
 * way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 * y      double-complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * y      contains double complex vector x
 *
 * Reference: http://www.netlib.org/blas/zcopy.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZcopy (int n, const cuDoubleComplex *x, int incx, cuDoubleComplex *y,
                            int incy);

/*
 * void
 * cublasCscal (int n, cuComplex alpha, cuComplex *x, int incx)
 *
 * replaces single-complex vector x with single-complex alpha * x. For i 
 * = 0 to n - 1, it replaces x[ix + i * incx] with alpha * x[ix + i * incx], 
 * where ix = 1 if incx >= 0, else ix = 1 + (1 - n) * incx.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  single-complex scalar multiplier
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * x      single-complex result (unchanged if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/cscal.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCscal (int n, cuComplex alpha, cuComplex *x, int incx);

/*
 * void 
 * cublasCrotg (cuComplex *host_ca, cuComplex cb, float *host_sc, cuComplex *host_cs)
 *
 * constructs the complex Givens tranformation
 *
 *        ( sc  cs )
 *    G = (        ) ,  sc^2 + cabs(cs)^2 = 1,
 *        (-cs  sc )
 * 
 * which zeros the second entry of the complex 2-vector transpose(ca, cb).
 *
 * The quantity ca/cabs(ca)*norm(ca,cb) overwrites ca in storage. The 
 * function crot (n, x, incx, y, incy, sc, cs) is normally called next
 * to apply the transformation to a 2 x n matrix.
 * Note that this function is provided for completeness and run exclusively 
 * on the Host.
 *
 * Input
 * -----
 * ca     single-precision complex precision scalar
 * cb     single-precision complex scalar
 *
 * Output
 * ------
 * ca     single-precision complex ca/cabs(ca)*norm(ca,cb)
 * sc     single-precision cosine component of rotation matrix
 * cs     single-precision complex sine component of rotation matrix
 *
 * Reference: http://www.netlib.org/blas/crotg.f
 *
 * This function does not set any error status.
 */
__host__ void CUBLASAPI cublasCrotg (cuComplex *host_ca, cuComplex cb, float *host_sc,
                                     cuComplex *host_cs);

/*
 * void 
 * cublasCrot (int n, cuComplex *x, int incx, cuComplex *y, int incy, float sc,
 *             cuComplex cs)
 *
 * multiplies a 2x2 matrix ( sc       cs) with the 2xn matrix ( transpose(x) )
 *                         (-conj(cs) sc)                     ( transpose(y) )
 *
 * The elements of x are in x[lx + i * incx], i = 0 ... n - 1, where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and similarly for y using ly and 
 * incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single-precision complex vector with n elements
 * incx   storage spacing between elements of x
 * y      single-precision complex vector with n elements
 * incy   storage spacing between elements of y
 * sc     single-precision cosine component of rotation matrix
 * cs     single-precision complex sine component of rotation matrix
 *
 * Output
 * ------
 * x      rotated single-precision complex vector x (unchanged if n <= 0)
 * y      rotated single-precision complex vector y (unchanged if n <= 0)
 *
 * Reference: http://netlib.org/lapack/explore-html/crot.f.html
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCrot (int n, cuComplex *x, int incx, cuComplex *y, 
                           int incy, float c, cuComplex s);

/*
 * void 
 * csrot (int n, cuComplex *x, int incx, cuCumplex *y, int incy, float c, 
 *        float s)
 *
 * multiplies a 2x2 rotation matrix ( c s) with a 2xn matrix ( transpose(x) )
 *                                  (-s c)                   ( transpose(y) )
 *
 * The elements of x are in x[lx + i * incx], i = 0 ... n - 1, where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and similarly for y using ly and 
 * incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single-precision complex vector with n elements
 * incx   storage spacing between elements of x
 * y      single-precision complex vector with n elements
 * incy   storage spacing between elements of y
 * c      cosine component of rotation matrix
 * s      sine component of rotation matrix
 *
 * Output
 * ------
 * x      rotated vector x (unchanged if n <= 0)
 * y      rotated vector y (unchanged if n <= 0)
 *
 * Reference  http://www.netlib.org/blas/csrot.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCsrot (int n, cuComplex *x, int incx, cuComplex *y,
                            int incy, float c, float s);

/*
 * void
 * cublasCsscal (int n, float alpha, cuComplex *x, int incx)
 *
 * replaces single-complex vector x with single-complex alpha * x. For i 
 * = 0 to n - 1, it replaces x[ix + i * incx] with alpha * x[ix + i * incx], 
 * where ix = 1 if incx >= 0, else ix = 1 + (1 - n) * incx.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  single precision scalar multiplier
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * x      single-complex result (unchanged if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/csscal.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCsscal (int n, float alpha, cuComplex *x, int incx);

/*
 * void
 * cublasCswap (int n, const cuComplex *x, int incx, cuComplex *y, int incy)
 *
 * interchanges the single-complex vector x with the single-complex vector y. 
 * For i = 0 to n-1, interchanges x[lx + i * incx] with y[ly + i * incy], where
 * lx = 1 if incx >= 0, else lx = 1 + (1 - n) * incx, and ly is defined in a 
 * similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 * y      single-complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * x      contains-single complex vector y
 * y      contains-single complex vector x
 *
 * Reference: http://www.netlib.org/blas/cswap.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCswap (int n, cuComplex *x, int incx, cuComplex *y,
                            int incy);

/*
 * void
 * cublasZswap (int n, const cuDoubleComplex *x, int incx, cuDoubleComplex *y, int incy)
 *
 * interchanges the double-complex vector x with the double-complex vector y. 
 * For i = 0 to n-1, interchanges x[lx + i * incx] with y[ly + i * incy], where
 * lx = 1 if incx >= 0, else lx = 1 + (1 - n) * incx, and ly is defined in a 
 * similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 * y      double-complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * x      contains-double complex vector y
 * y      contains-double complex vector x
 *
 * Reference: http://www.netlib.org/blas/zswap.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZswap (int n, cuDoubleComplex *x, int incx, cuDoubleComplex *y,
                            int incy);

/*
 * cuComplex 
 * cdotu (int n, const cuComplex *x, int incx, const cuComplex *y, int incy)
 *
 * computes the dot product of two single-complex vectors. It returns the 
 * dot product of the single-complex vectors x and y if successful, and complex
 * zero otherwise. It computes the sum for i = 0 to n - 1 of x[lx + i * incx] *
 * y[ly + i * incy], where lx = 1 if incx >= 0, else lx = 1 + (1 - n) * incx; 
 * ly is defined in a similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 * y      single-complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * returns single-complex dot product (zero if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/cdotu.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has nor been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to execute on GPU
 */
cuComplex CUBLASAPI cublasCdotu (int n, const cuComplex *x, int incx, 
                                 const cuComplex *y, int incy);

/*
 * cuComplex 
 * cublasCdotc (int n, const cuComplex *x, int incx, const cuComplex *y, 
 *              int incy)
 *
 * computes the dot product of two single-complex vectors. It returns the 
 * dot product of the single-complex vectors x and y if successful, and complex
 * zero otherwise. It computes the sum for i = 0 to n - 1 of x[lx + i * incx] *
 * y[ly + i * incy], where lx = 1 if incx >= 0, else lx = 1 + (1 - n) * incx; 
 * ly is defined in a similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 * y      single-complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * returns single-complex dot product (zero if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/cdotc.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has nor been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to execute on GPU
 */
cuComplex CUBLASAPI cublasCdotc (int n, const cuComplex *x, int incx, 
                                 const cuComplex *y, int incy);

/*
 * int 
 * cublasIcamax (int n, const float *x, int incx)
 *
 * finds the smallest index of the element having maximum absolute value
 * in single-complex vector x; that is, the result is the first i, i = 0 
 * to n - 1 that maximizes abs(real(x[1+i*incx]))+abs(imag(x[1 + i * incx])).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the smallest index (0 if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/icamax.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
int CUBLASAPI cublasIcamax (int n, const cuComplex *x, int incx);

/*
 * int 
 * cublasIcamin (int n, const float *x, int incx)
 *
 * finds the smallest index of the element having minimum absolute value
 * in single-complex vector x; that is, the result is the first i, i = 0 
 * to n - 1 that minimizes abs(real(x[1+i*incx]))+abs(imag(x[1 + i * incx])).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the smallest index (0 if n <= 0 or incx <= 0)
 *
 * Reference: see ICAMAX.
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
int CUBLASAPI cublasIcamin (int n, const cuComplex *x, int incx);

/*
 * float 
 * cublasScasum (int n, const cuDouble *x, int incx)
 *
 * takes the sum of the absolute values of a complex vector and returns a
 * single precision result. Note that this is not the L1 norm of the vector.
 * The result is the sum from 0 to n-1 of abs(real(x[ix+i*incx])) +
 * abs(imag(x(ix+i*incx))), where ix = 1 if incx <= 0, else ix = 1+(1-n)*incx.
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the single precision sum of absolute values of real and imaginary
 * parts (0 if n <= 0 or incx <= 0, or if an error occurs)
 *
 * Reference: http://www.netlib.org/blas/scasum.f
 *
 * Error status for this function can be retrieved via cublasGetError(). 
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
float CUBLASAPI cublasScasum (int n, const cuComplex *x, int incx);

/*
 * float 
 * cublasScnrm2 (int n, const cuComplex *x, int incx)
 *
 * computes the Euclidean norm of the single-complex n-vector x. This code 
 * uses simple scaling to avoid intermediate underflow and overflow.
 *
 * Input
 * -----
 * n      number of elements in input vector
 * x      single-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns Euclidian norm (0 if n <= 0 or incx <= 0, or if an error occurs)
 *
 * Reference: http://www.netlib.org/blas/scnrm2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
float CUBLASAPI cublasScnrm2 (int n, const cuComplex *x, int incx);

/* ----------------- CUBLAS double-complex BLAS1 functions ----------------- */

/*
 * void
 * cublasZaxpy (int n, cuDoubleComplex alpha, const cuDoubleComplex *x, int incx, 
 *              cuDoubleComplex *y, int incy)
 *
 * multiplies double-complex vector x by double-complex scalar alpha and adds 
 * the result to double-complex vector y; that is, it overwrites double-complex
 * y with double-complex alpha * x + y. For i = 0 to n - 1, it replaces 
 * y[ly + i * incy] with alpha * x[lx + i * incx] + y[ly + i * incy], where 
 * lx = 0 if incx >= 0, else lx = 1 + (1 - n) * incx, and ly is defined in a 
 * similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  double-complex scalar multiplier
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 * y      double-complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * y      double-complex result (unchanged if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/zaxpy.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZaxpy (int n, cuDoubleComplex alpha, const cuDoubleComplex *x, 
                            int incx, cuDoubleComplex *y, int incy);

/*
 * cuDoubleComplex 
 * zdotu (int n, const cuDoubleComplex *x, int incx, const cuDoubleComplex *y, int incy)
 *
 * computes the dot product of two double-complex vectors. It returns the 
 * dot product of the double-complex vectors x and y if successful, and double-complex
 * zero otherwise. It computes the sum for i = 0 to n - 1 of x[lx + i * incx] *
 * y[ly + i * incy], where lx = 1 if incx >= 0, else lx = 1 + (1 - n) * incx; 
 * ly is defined in a similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 * y      double-complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * returns double-complex dot product (zero if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/zdotu.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has nor been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support   
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to execute on GPU
 */
cuDoubleComplex CUBLASAPI cublasZdotu (int n, const cuDoubleComplex *x, int incx, 
                                 const cuDoubleComplex *y, int incy);

/*
 * cuDoubleComplex 
 * cublasZdotc (int n, const cuDoubleComplex *x, int incx, const cuDoubleComplex *y, int incy)
 *
 * computes the dot product of two double-precision complex vectors. It returns the 
 * dot product of the double-precision complex vectors conjugate(x) and y if successful,
 * and double-precision complex zero otherwise. It computes the
 * sum for i = 0 to n - 1 of conjugate(x[lx + i * incx]) *  y[ly + i * incy],
 * where lx = 1 if incx >= 0, else lx = 1 + (1 - n) * incx; 
 * ly is defined in a similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-precision complex vector with n elements
 * incx   storage spacing between elements of x
 * y      double-precision complex vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * returns double-complex dot product (zero if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/zdotc.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has nor been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to execute on GPU
 */
cuDoubleComplex CUBLASAPI cublasZdotc( int n, const cuDoubleComplex *x, int incx,
                                       const cuDoubleComplex *y, int incy );

/*
 * void
 * cublasZscal (int n, cuComplex alpha, cuComplex *x, int incx)
 *
 * replaces double-complex vector x with double-complex alpha * x. For i 
 * = 0 to n - 1, it replaces x[ix + i * incx] with alpha * x[ix + i * incx], 
 * where ix = 1 if incx >= 0, else ix = 1 + (1 - n) * incx.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  double-complex scalar multiplier
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * x      double-complex result (unchanged if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/zscal.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZscal (int n, cuDoubleComplex alpha, cuDoubleComplex *x, int incx);

/*
 * void
 * cublasZdscal (int n, double alpha, cuDoubleComplex *x, int incx)
 *
 * replaces double-complex vector x with double-complex alpha * x. For i 
 * = 0 to n - 1, it replaces x[ix + i * incx] with alpha * x[ix + i * incx], 
 * where ix = 1 if incx >= 0, else ix = 1 + (1 - n) * incx.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  double precision scalar multiplier
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * x      double-complex result (unchanged if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/zdscal.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support   
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZdscal (int n, double alpha, cuDoubleComplex *x,
                             int incx);
                                      
/*
 * double 
 * cublasDznrm2 (int n, const cuDoubleComplex *x, int incx)
 *
 * computes the Euclidean norm of the double precision complex n-vector x. This code 
 * uses simple scaling to avoid intermediate underflow and overflow.
 *
 * Input
 * -----
 * n      number of elements in input vector
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns Euclidian norm (0 if n <= 0 or incx <= 0, or if an error occurs)
 *
 * Reference: http://www.netlib.org/blas/dznrm2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
double CUBLASAPI cublasDznrm2 (int n, const cuDoubleComplex *x, int incx);

/*
 * void 
 * cublasZrotg (cuDoubleComplex *host_ca, cuDoubleComplex cb, double *host_sc, double *host_cs)
 *
 * constructs the complex Givens tranformation
 *
 *        ( sc  cs )
 *    G = (        ) ,  sc^2 + cabs(cs)^2 = 1,
 *        (-cs  sc )
 * 
 * which zeros the second entry of the complex 2-vector transpose(ca, cb).
 *
 * The quantity ca/cabs(ca)*norm(ca,cb) overwrites ca in storage. The 
 * function crot (n, x, incx, y, incy, sc, cs) is normally called next
 * to apply the transformation to a 2 x n matrix.
 * Note that this function is provided for completeness and run exclusively 
 * on the Host. 
 *
 * Input
 * -----
 * ca     double-precision complex precision scalar
 * cb     double-precision complex scalar
 *
 * Output
 * ------
 * ca     double-precision complex ca/cabs(ca)*norm(ca,cb)
 * sc     double-precision cosine component of rotation matrix
 * cs     double-precision complex sine component of rotation matrix
 *
 * Reference: http://www.netlib.org/blas/zrotg.f
 *
 * This function does not set any error status.
 */
void CUBLASAPI cublasZrotg (cuDoubleComplex *host_ca, cuDoubleComplex cb, double *host_sc,
                            cuDoubleComplex *host_cs);
                            
/*
 * cublasZrot (int n, cuDoubleComplex *x, int incx, cuDoubleComplex *y, int incy, double sc,
 *             cuDoubleComplex cs)
 *
 * multiplies a 2x2 matrix ( sc       cs) with the 2xn matrix ( transpose(x) )
 *                         (-conj(cs) sc)                     ( transpose(y) )
 *
 * The elements of x are in x[lx + i * incx], i = 0 ... n - 1, where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and similarly for y using ly and 
 * incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-precision complex vector with n elements
 * incx   storage spacing between elements of x
 * y      double-precision complex vector with n elements
 * incy   storage spacing between elements of y
 * sc     double-precision cosine component of rotation matrix
 * cs     double-precision complex sine component of rotation matrix
 *
 * Output
 * ------
 * x      rotated double-precision complex vector x (unchanged if n <= 0)
 * y      rotated double-precision complex vector y (unchanged if n <= 0)
 *
 * Reference: http://netlib.org/lapack/explore-html/zrot.f.html
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support    
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZrot (int n, cuDoubleComplex *x, int incx, 
                           cuDoubleComplex *y, int incy, double sc, 
                           cuDoubleComplex cs);                            

/*
 * void 
 * zdrot (int n, cuDoubleComplex *x, int incx, cuCumplex *y, int incy, double c, 
 *        double s)
 *
 * multiplies a 2x2 matrix ( c s) with the 2xn matrix ( transpose(x) )
 *                         (-s c)                     ( transpose(y) )
 *
 * The elements of x are in x[lx + i * incx], i = 0 ... n - 1, where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and similarly for y using ly and 
 * incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-precision complex vector with n elements
 * incx   storage spacing between elements of x
 * y      double-precision complex vector with n elements
 * incy   storage spacing between elements of y
 * c      cosine component of rotation matrix
 * s      sine component of rotation matrix
 *
 * Output
 * ------
 * x      rotated vector x (unchanged if n <= 0)
 * y      rotated vector y (unchanged if n <= 0)
 *
 * Reference  http://www.netlib.org/blas/zdrot.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support    
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZdrot (int n, cuDoubleComplex *x, int incx, 
                            cuDoubleComplex *y, int incy, double c, double s);
                            
/*
 * int 
 * cublasIzamax (int n, const double *x, int incx)
 *
 * finds the smallest index of the element having maximum absolute value
 * in double-complex vector x; that is, the result is the first i, i = 0 
 * to n - 1 that maximizes abs(real(x[1+i*incx]))+abs(imag(x[1 + i * incx])).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the smallest index (0 if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/izamax.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
int CUBLASAPI cublasIzamax (int n, const cuDoubleComplex *x, int incx);                            
                            
/*
 * int 
 * cublasIzamin (int n, const cuDoubleComplex *x, int incx)
 *
 * finds the smallest index of the element having minimum absolute value
 * in double-complex vector x; that is, the result is the first i, i = 0 
 * to n - 1 that minimizes abs(real(x[1+i*incx]))+abs(imag(x[1 + i * incx])).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the smallest index (0 if n <= 0 or incx <= 0)
 *
 * Reference: Analogous to IZAMAX, see there.
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
int CUBLASAPI cublasIzamin (int n, const cuDoubleComplex *x, int incx);  

/*
 * double 
 * cublasDzasum (int n, const cuDoubleComplex *x, int incx)
 *
 * takes the sum of the absolute values of a complex vector and returns a
 * double precision result. Note that this is not the L1 norm of the vector.
 * The result is the sum from 0 to n-1 of abs(real(x[ix+i*incx])) +
 * abs(imag(x(ix+i*incx))), where ix = 1 if incx <= 0, else ix = 1+(1-n)*incx.
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      double-complex vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the double precision sum of absolute values of real and imaginary
 * parts (0 if n <= 0 or incx <= 0, or if an error occurs)
 *
 * Reference: http://www.netlib.org/blas/dzasum.f
 *
 * Error status for this function can be retrieved via cublasGetError(). 
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
double CUBLASAPI cublasDzasum (int n, const cuDoubleComplex *x, int incx);                          

/* --------------- CUBLAS single precision BLAS2 functions  ---------------- */

/*
 * void 
 * cublasSgbmv (char trans, int m, int n, int kl, int ku, float alpha,
 *              const float *A, int lda, const float *x, int incx, float beta,
 *              float *y, int incy)
 *
 * performs one of the matrix-vector operations
 *
 *    y = alpha*op(A)*x + beta*y,  op(A)=A or op(A) = transpose(A)
 *
 * alpha and beta are single precision scalars. x and y are single precision
 * vectors. A is an m by n band matrix consisting of single precision elements
 * with kl sub-diagonals and ku super-diagonals.
 *
 * Input
 * -----
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T', 
 *        't', 'C', or 'c', op(A) = transpose(A)
 * m      specifies the number of rows of the matrix A. m must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. n must be at least
 *        zero.
 * kl     specifies the number of sub-diagonals of matrix A. It must be at 
 *        least zero.
 * ku     specifies the number of super-diagonals of matrix A. It must be at 
 *        least zero.
 * alpha  single precision scalar multiplier applied to op(A).
 * A      single precision array of dimensions (lda, n). The leading
 *        (kl + ku + 1) x n part of the array A must contain the band matrix A,
 *        supplied column by column, with the leading diagonal of the matrix 
 *        in row (ku + 1) of the array, the first super-diagonal starting at 
 *        position 2 in row ku, the first sub-diagonal starting at position 1
 *        in row (ku + 2), and so on. Elements in the array A that do not 
 *        correspond to elements in the band matrix (such as the top left 
 *        ku x ku triangle) are not referenced.
 * lda    leading dimension of A. lda must be at least (kl + ku + 1).
 * x      single precision array of length at least (1+(n-1)*abs(incx)) when 
 *        trans == 'N' or 'n' and at least (1+(m-1)*abs(incx)) otherwise.
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   single precision scalar multiplier applied to vector y. If beta is 
 *        zero, y is not read.
 * y      single precision array of length at least (1+(m-1)*abs(incy)) when 
 *        trans == 'N' or 'n' and at least (1+(n-1)*abs(incy)) otherwise. If 
 *        beta is zero, y is not read.
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*op(A)*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/sgbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n, kl, or ku < 0; if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSgbmv (char trans, int m, int n, int kl, int ku, 
                            float alpha, const float *A, int lda, 
                            const float *x, int incx, float beta, float *y, 
                            int incy);

/*
 * cublasSgemv (char trans, int m, int n, float alpha, const float *A, int lda,
 *              const float *x, int incx, float beta, float *y, int incy)
 *
 * performs one of the matrix-vector operations
 *
 *    y = alpha * op(A) * x + beta * y,
 *
 * where op(A) is one of
 *
 *    op(A) = A   or   op(A) = transpose(A)
 *
 * where alpha and beta are single precision scalars, x and y are single 
 * precision vectors, and A is an m x n matrix consisting of single precision
 * elements. Matrix A is stored in column major format, and lda is the leading
 * dimension of the two-dimensional array in which A is stored.
 *
 * Input
 * -----
 * trans  specifies op(A). If transa = 'n' or 'N', op(A) = A. If trans =
 *        trans = 't', 'T', 'c', or 'C', op(A) = transpose(A)
 * m      specifies the number of rows of the matrix A. m must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. n must be at least 
 *        zero.
 * alpha  single precision scalar multiplier applied to op(A).
 * A      single precision array of dimensions (lda, n) if trans = 'n' or 
 *        'N'), and of dimensions (lda, m) otherwise. lda must be at least 
 *        max(1, m) and at least max(1, n) otherwise.
 * lda    leading dimension of two-dimensional array used to store matrix A
 * x      single precision array of length at least (1 + (n - 1) * abs(incx))
 *        when trans = 'N' or 'n' and at least (1 + (m - 1) * abs(incx)) 
 *        otherwise.
 * incx   specifies the storage spacing between elements of x. incx must not 
 *        be zero.
 * beta   single precision scalar multiplier applied to vector y. If beta 
 *        is zero, y is not read.
 * y      single precision array of length at least (1 + (m - 1) * abs(incy))
 *        when trans = 'N' or 'n' and at least (1 + (n - 1) * abs(incy)) 
 *        otherwise.
 * incy   specifies the storage spacing between elements of x. incx must not
 *        be zero.
 *
 * Output
 * ------
 * y      updated according to alpha * op(A) * x + beta * y
 *
 * Reference: http://www.netlib.org/blas/sgemv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0, or if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSgemv (char trans, int m, int n, float alpha,
                            const float *A, int lda, const float *x, int incx,
                            float beta, float *y, int incy);

/*
 * cublasSger (int m, int n, float alpha, const float *x, int incx, 
 *             const float *y, int incy, float *A, int lda)
 *
 * performs the symmetric rank 1 operation
 *
 *    A = alpha * x * transpose(y) + A,
 *
 * where alpha is a single precision scalar, x is an m element single 
 * precision vector, y is an n element single precision vector, and A 
 * is an m by n matrix consisting of single precision elements. Matrix A
 * is stored in column major format, and lda is the leading dimension of
 * the two-dimensional array used to store A.
 * 
 * Input
 * -----
 * m      specifies the number of rows of the matrix A. It must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. It must be at 
 *        least zero.
 * alpha  single precision scalar multiplier applied to x * transpose(y)
 * x      single precision array of length at least (1 + (m - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must not
 *        be zero.
 * y      single precision array of length at least (1 + (n - 1) * abs(incy))
 * incy   specifies the storage spacing between elements of y. incy must not 
 *        be zero.
 * A      single precision array of dimensions (lda, n).
 * lda    leading dimension of two-dimensional array used to store matrix A
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * transpose(y) + A
 *
 * Reference: http://www.netlib.org/blas/sger.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSger (int m, int n, float alpha, const float *x, int incx,
                           const float *y, int incy, float *A, int lda);

/*
 * void 
 * cublasSsbmv (char uplo, int n, int k, float alpha, const float *A, int lda,
 *              const float *x, int incx, float beta, float *y, int incy)
 *
 * performs the matrix-vector operation
 *
 *     y := alpha*A*x + beta*y
 *
 * alpha and beta are single precision scalars. x and y are single precision
 * vectors with n elements. A is an n x n symmetric band matrix consisting 
 * of single precision elements, with k super-diagonals and the same number
 * of sub-diagonals.
 *
 * Input
 * -----
 * uplo   specifies whether the upper or lower triangular part of the symmetric
 *        band matrix A is being supplied. If uplo == 'U' or 'u', the upper 
 *        triangular part is being supplied. If uplo == 'L' or 'l', the lower 
 *        triangular part is being supplied.
 * n      specifies the number of rows and the number of columns of the
 *        symmetric matrix A. n must be at least zero.
 * k      specifies the number of super-diagonals of matrix A. Since the matrix
 *        is symmetric, this is also the number of sub-diagonals. k must be at
 *        least zero.
 * alpha  single precision scalar multiplier applied to A*x.
 * A      single precision array of dimensions (lda, n). When uplo == 'U' or 
 *        'u', the leading (k + 1) x n part of array A must contain the upper
 *        triangular band of the symmetric matrix, supplied column by column,
 *        with the leading diagonal of the matrix in row (k+1) of the array,
 *        the first super-diagonal starting at position 2 in row k, and so on.
 *        The top left k x k triangle of the array A is not referenced. When
 *        uplo == 'L' or 'l', the leading (k + 1) x n part of the array A must
 *        contain the lower triangular band part of the symmetric matrix, 
 *        supplied column by column, with the leading diagonal of the matrix in
 *        row 1 of the array, the first sub-diagonal starting at position 1 in
 *        row 2, and so on. The bottom right k x k triangle of the array A is
 *        not referenced.
 * lda    leading dimension of A. lda must be at least (k + 1).
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   single precision scalar multiplier applied to vector y. If beta is 
 *        zero, y is not read.
 * y      single precision array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read.
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/ssbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_INVALID_VALUE    if k or n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */

void CUBLASAPI cublasSsbmv (char uplo, int n, int k, float alpha, 
                            const float *A, int lda, const float *x, int incx, 
                            float beta, float *y, int incy);
/*
 * void 
 * cublasSspmv (char uplo, int n, float alpha, const float *AP, const float *x,
 *              int incx, float beta, float *y, int incy)
 *
 * performs the matrix-vector operation
 * 
 *    y = alpha * A * x + beta * y
 *
 * Alpha and beta are single precision scalars, and x and y are single 
 * precision vectors with n elements. A is a symmetric n x n matrix 
 * consisting of single precision elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array AP. If uplo == 'U' or 'u', then the upper 
 *        triangular part of A is supplied in AP. If uplo == 'L' or 'l', then 
 *        the lower triangular part of A is supplied in AP.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  single precision scalar multiplier applied to A*x.
 * AP     single precision array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   single precision scalar multiplier applied to vector y;
 * y      single precision array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read. 
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/sspmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSspmv (char uplo, int n, float alpha, const float *AP, 
                            const float *x, int incx, float beta, float *y,
                            int incy);

/*
 * void 
 * cublasSspr (char uplo, int n, float alpha, const float *x, int incx, 
 *             float *AP)
 *
 * performs the symmetric rank 1 operation
 * 
 *    A = alpha * x * transpose(x) + A,
 * 
 * where alpha is a single precision scalar and x is an n element single 
 * precision vector. A is a symmetric n x n matrix consisting of single 
 * precision elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array AP. If uplo == 'U' or 'u', then the upper 
 *        triangular part of A is supplied in AP. If uplo == 'L' or 'l', then 
 *        the lower triangular part of A is supplied in AP.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  single precision scalar multiplier applied to x * transpose(x).
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * AP     single precision array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * transpose(x) + A
 *
 * Reference: http://www.netlib.org/blas/sspr.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or incx == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSspr (char uplo, int n, float alpha, const float *x,
                           int incx, float *AP);

/* 
 * void 
 * cublasSspr2 (char uplo, int n, float alpha, const float *x, int incx, 
 *              const float *y, int incy, float *AP)
 *
 * performs the symmetric rank 2 operation
 *
 *    A = alpha*x*transpose(y) + alpha*y*transpose(x) + A,
 *
 * where alpha is a single precision scalar, and x and y are n element single 
 * precision vectors. A is a symmetric n x n matrix consisting of single 
 * precision elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array A. If uplo == 'U' or 'u', then only the 
 *        upper triangular part of A may be referenced and the lower triangular
 *        part of A is inferred. If uplo == 'L' or 'l', then only the lower 
 *        triangular part of A may be referenced and the upper triangular part
 *        of A is inferred.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  single precision scalar multiplier applied to x * transpose(y) + 
 *        y * transpose(x).
 * x      single precision array of length at least (1 + (n - 1) * abs (incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * y      single precision array of length at least (1 + (n - 1) * abs (incy)).
 * incy   storage spacing between elements of y. incy must not be zero.
 * AP     single precision array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *
 * Output
 * ------
 * A      updated according to A = alpha*x*transpose(y)+alpha*y*transpose(x)+A
 *
 * Reference: http://www.netlib.org/blas/sspr2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSspr2 (char uplo, int n, float alpha, const float *x, 
                            int incx, const float *y, int incy, float *AP);

/*
 * void 
 * cublasSsymv (char uplo, int n, float alpha, const float *A, int lda, 
 *              const float *x, int incx, float beta, float *y, int incy)
 *
 * performs the matrix-vector operation
 *
 *     y = alpha*A*x + beta*y
 *
 * Alpha and beta are single precision scalars, and x and y are single 
 * precision vectors, each with n elements. A is a symmetric n x n matrix 
 * consisting of single precision elements that is stored in either upper or 
 * lower storage mode.
 *
 * Input
 * -----
 * uplo   specifies whether the upper or lower triangular part of the array A 
 *        is to be referenced. If uplo == 'U' or 'u', the symmetric matrix A 
 *        is stored in upper storage mode, i.e. only the upper triangular part
 *        of A is to be referenced while the lower triangular part of A is to 
 *        be inferred. If uplo == 'L' or 'l', the symmetric matrix A is stored
 *        in lower storage mode, i.e. only the lower triangular part of A is 
 *        to be referenced while the upper triangular part of A is to be 
 *        inferred.
 * n      specifies the number of rows and the number of columns of the 
 *        symmetric matrix A. n must be at least zero.
 * alpha  single precision scalar multiplier applied to A*x.
 * A      single precision array of dimensions (lda, n). If uplo == 'U' or 'u',
 *        the leading n x n upper triangular part of the array A must contain
 *        the upper triangular part of the symmetric matrix and the strictly
 *        lower triangular part of A is not referenced. If uplo == 'L' or 'l',
 *        the leading n x n lower triangular part of the array A must contain
 *        the lower triangular part of the symmetric matrix and the strictly
 *        upper triangular part of A is not referenced. 
 * lda    leading dimension of A. It must be at least max (1, n).
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   single precision scalar multiplier applied to vector y.
 * y      single precision array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read. 
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/ssymv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSsymv (char uplo, int n, float alpha, const float *A,
                            int lda, const float *x, int incx, float beta, 
                            float *y, int incy);

/*
 * void 
 * cublasSsyr (char uplo, int n, float alpha, const float *x, int incx,
 *             float *A, int lda)
 *
 * performs the symmetric rank 1 operation
 *
 *    A = alpha * x * transpose(x) + A,
 *
 * where alpha is a single precision scalar, x is an n element single 
 * precision vector and A is an n x n symmetric matrix consisting of 
 * single precision elements. Matrix A is stored in column major format,
 * and lda is the leading dimension of the two-dimensional array 
 * containing A.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or 
 *        the lower triangular part of array A. If uplo = 'U' or 'u',
 *        then only the upper triangular part of A may be referenced.
 *        If uplo = 'L' or 'l', then only the lower triangular part of
 *        A may be referenced.
 * n      specifies the number of rows and columns of the matrix A. It
 *        must be at least 0.
 * alpha  single precision scalar multiplier applied to x * transpose(x)
 * x      single precision array of length at least (1 + (n - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must 
 *        not be zero.
 * A      single precision array of dimensions (lda, n). If uplo = 'U' or 
 *        'u', then A must contain the upper triangular part of a symmetric 
 *        matrix, and the strictly lower triangular part is not referenced. 
 *        If uplo = 'L' or 'l', then A contains the lower triangular part 
 *        of a symmetric matrix, and the strictly upper triangular part is 
 *        not referenced.
 * lda    leading dimension of the two-dimensional array containing A. lda
 *        must be at least max(1, n).
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * transpose(x) + A
 *
 * Reference: http://www.netlib.org/blas/ssyr.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or incx == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSsyr (char uplo, int n, float alpha, const float *x,
                           int incx, float *A, int lda);

/*
 * void 
 * cublasSsyr2 (char uplo, int n, float alpha, const float *x, int incx, 
 *              const float *y, int incy, float *A, int lda)
 *
 * performs the symmetric rank 2 operation
 *
 *    A = alpha*x*transpose(y) + alpha*y*transpose(x) + A,
 *
 * where alpha is a single precision scalar, x and y are n element single 
 * precision vector and A is an n by n symmetric matrix consisting of single 
 * precision elements.
 * 
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array A. If uplo == 'U' or 'u', then only the 
 *        upper triangular part of A may be referenced and the lower triangular
 *        part of A is inferred. If uplo == 'L' or 'l', then only the lower 
 *        triangular part of A may be referenced and the upper triangular part
 *        of A is inferred.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  single precision scalar multiplier applied to x * transpose(y) + 
 *        y * transpose(x).
 * x      single precision array of length at least (1 + (n - 1) * abs (incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * y      single precision array of length at least (1 + (n - 1) * abs (incy)).
 * incy   storage spacing between elements of y. incy must not be zero.
 * A      single precision array of dimensions (lda, n). If uplo == 'U' or 'u',
 *        then A must contains the upper triangular part of a symmetric matrix,
 *        and the strictly lower triangular parts is not referenced. If uplo ==
 *        'L' or 'l', then A contains the lower triangular part of a symmetric 
 *        matrix, and the strictly upper triangular part is not referenced.
 * lda    leading dimension of A. It must be at least max(1, n).
 *
 * Output
 * ------
 * A      updated according to A = alpha*x*transpose(y)+alpha*y*transpose(x)+A
 *
 * Reference: http://www.netlib.org/blas/ssyr2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSsyr2 (char uplo, int n, float alpha, const float *x, 
                            int incx, const float *y, int incy, float *A, 
                            int lda);
/*
 * void 
 * cublasStbmv (char uplo, char trans, char diag, int n, int k, const float *A,
 *              int lda, float *x, int incx)
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = A
 * or op(A) = transpose(A). x is an n-element single precision vector, and A is
 * an n x n, unit or non-unit upper or lower triangular band matrix consisting
 * of single precision elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular band
 *        matrix. If uplo == 'U' or 'u', A is an upper triangular band matrix.
 *        If uplo == 'L' or 'l', A is a lower triangular band matrix.
 * trans  specifies op(A). If transa == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', 'C', or 'c', op(A) = transpose(A).
 * diag   specifies whether or not matrix A is unit triangular. If diag == 'U'
 *        or 'u', A is assumed to be unit triangular. If diag == 'N' or 'n', A
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero. In the current implementation n must not exceed 4070.
 * k      specifies the number of super- or sub-diagonals. If uplo == 'U' or 
 *        'u', k specifies the number of super-diagonals. If uplo == 'L' or 
 *        'l', k specifies the number of sub-diagonals. k must at least be 
 *        zero.
 * A      single precision array of dimension (lda, n). If uplo == 'U' or 'u',
 *        the leading (k + 1) x n part of the array A must contain the upper 
 *        triangular band matrix, supplied column by column, with the leading
 *        diagonal of the matrix in row (k + 1) of the array, the first 
 *        super-diagonal starting at position 2 in row k, and so on. The top
 *        left k x k triangle of the array A is not referenced. If uplo == 'L'
 *        or 'l', the leading (k + 1) x n part of the array A must constain the
 *        lower triangular band matrix, supplied column by column, with the
 *        leading diagonal of the matrix in row 1 of the array, the first 
 *        sub-diagonal startingat position 1 in row 2, and so on. The bottom
 *        right k x k triangle of the array is not referenced.
 * lda    is the leading dimension of A. It must be at least (k + 1).
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the source vector. On exit, x is overwritten
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x
 *
 * Reference: http://www.netlib.org/blas/stbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, k < 0, or incx == 0
 * CUBLAS_STATUS_ALLOC_FAILED     if function cannot allocate enough internal scratch vector memory 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasStbmv (char uplo, char trans, char diag, int n, int k, 
                            const float *A, int lda, float *x, int incx);

/*
 * void cublasStbsv (char uplo, char trans, char diag, int n, int k,
 *                   const float *A, int lda, float *X, int incx)
 *
 * solves one of the systems of equations op(A)*x = b, where op(A) is either 
 * op(A) = A or op(A) = transpose(A). b and x are n-element vectors, and A is
 * an n x n unit or non-unit, upper or lower triangular band matrix with k + 1
 * diagonals. No test for singularity or near-singularity is included in this
 * function. Such tests must be performed before calling this function.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix is an upper or lower triangular band 
 *        matrix as follows: If uplo == 'U' or 'u', A is an upper triangular
 *        band matrix. If uplo == 'L' or 'l', A is a lower triangular band
 *        matrix.
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', 'C', or 'c', op(A) = transpose(A).
 * diag   specifies whether A is unit triangular. If diag == 'U' or 'u', A is
 *        assumed to be unit triangular; thas is, diagonal elements are not
 *        read and are assumed to be unity. If diag == 'N' or 'n', A is not
 *        assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * k      specifies the number of super- or sub-diagonals. If uplo == 'U' or
 *        'u', k specifies the number of super-diagonals. If uplo == 'L' or
 *        'l', k specifies the number of sub-diagonals. k must be at least
 *        zero.
 * A      single precision array of dimension (lda, n). If uplo == 'U' or 'u',
 *        the leading (k + 1) x n part of the array A must contain the upper
 *        triangular band matrix, supplied column by column, with the leading
 *        diagonal of the matrix in row (k + 1) of the array, the first super-
 *        diagonal starting at position 2 in row k, and so on. The top left 
 *        k x k triangle of the array A is not referenced. If uplo == 'L' or 
 *        'l', the leading (k + 1) x n part of the array A must constain the
 *        lower triangular band matrix, supplied column by column, with the
 *        leading diagonal of the matrix in row 1 of the array, the first
 *        sub-diagonal starting at position 1 in row 2, and so on. The bottom
 *        right k x k triangle of the array is not referenced.
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)). 
 *        On entry, x contains the n-element right-hand side vector b. On exit,
 *        it is overwritten with the solution vector x.
 * incx   storage spacing between elements of x. incx must not be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/stbsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0, n < 0 or n > 4070
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasStbsv (char uplo, char trans, char diag, int n, int k, 
                            const float *A, int lda, float *x, int incx);

/*
 * void 
 * cublasStpmv (char uplo, char trans, char diag, int n, const float *AP, 
 *              float *x, int incx);
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = A,
 * or op(A) = transpose(A). x is an n element single precision vector, and A 
 * is an n x n, unit or non-unit, upper or lower triangular matrix composed 
 * of single precision elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix. If uplo == 'U' or 'u', then A is an upper triangular matrix.
 *        If uplo == 'L' or 'l', then A is a lower triangular matrix.
 * trans  specifies op(A). If transa == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', 'C', or 'c', op(A) = transpose(A)
 * diag   specifies whether or not matrix A is unit triangular. If diag == 'U'
 *        or 'u', A is assumed to be unit triangular. If diag == 'N' or 'n', A 
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be 
 *        at least zero.
 * AP     single precision array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored in AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the source vector. On exit, x is overwritten 
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x,
 *
 * Reference: http://www.netlib.org/blas/stpmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0
 * CUBLAS_STATUS_ALLOC_FAILED     if function cannot allocate enough internal scratch vector memory 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasStpmv (char uplo, char trans, char diag, int n,
                            const float *AP, float *x, int incx);

/*
 * void 
 * cublasStpsv (char uplo, char trans, char diag, int n, const float *AP,
 *              float *X, int incx)
 *
 * solves one of the systems of equations op(A)*x = b, where op(A) is either 
 * op(A) = A or op(A) = transpose(A). b and x are n element vectors, and A is
 * an n x n unit or non-unit, upper or lower triangular matrix. No test for
 * singularity or near-singularity is included in this function. Such tests 
 * must be performed before calling this function.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix is an upper or lower triangular matrix
 *        as follows: If uplo == 'U' or 'u', A is an upper triangluar matrix.
 *        If uplo == 'L' or 'l', A is a lower triangular matrix.
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', 'C', or 'c', op(A) = transpose(A).
 * diag   specifies whether A is unit triangular. If diag == 'U' or 'u', A is
 *        assumed to be unit triangular; thas is, diagonal elements are not
 *        read and are assumed to be unity. If diag == 'N' or 'n', A is not
 *        assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero. In the current implementation n must not exceed 4070.
 * AP     single precision array with at least ((n*(n+1))/2) elements. If uplo
 *        == 'U' or 'u', the array AP contains the upper triangular matrix A,
 *        packed sequentially, column by column; that is, if i <= j, then 
 *        A[i,j] is stored is AP[i+(j*(j+1)/2)]. If uplo == 'L' or 'L', the 
 *        array AP contains the lower triangular matrix A, packed sequentially,
 *        column by column; that is, if i >= j, then A[i,j] is stored in 
 *        AP[i+((2*n-j+1)*j)/2]. When diag = 'U' or 'u', the diagonal elements
 *        of A are not referenced and are assumed to be unity.
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)). 
 *        On entry, x contains the n-element right-hand side vector b. On exit,
 *        it is overwritten with the solution vector x.
 * incx   storage spacing between elements of x. It must not be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/stpsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0, n < 0, or n > 4070
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
*/
void CUBLASAPI cublasStpsv (char uplo, char trans, char diag, int n,
                            const float *AP, float *x, int incx);

/*
 * void 
 * cublasStrmv (char uplo, char trans, char diag, int n, const float *A,
 *              int lda, float *x, int incx);
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = 
 = A, or op(A) = transpose(A). x is an n-element single precision vector, and 
 * A is an n x n, unit or non-unit, upper or lower, triangular matrix composed 
 * of single precision elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular 
 *        matrix. If uplo = 'U' or 'u', then A is an upper triangular matrix. 
 *        If uplo = 'L' or 'l', then A is a lower triangular matrix.
 * trans  specifies op(A). If transa = 'N' or 'n', op(A) = A. If trans = 'T', 
 *        't', 'C', or 'c', op(A) = transpose(A)
 * diag   specifies whether or not matrix A is unit triangular. If diag = 'U' 
 *        or 'u', A is assumed to be unit triangular. If diag = 'N' or 'n', A 
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be 
 *        at least zero.
 * A      single precision array of dimension (lda, n). If uplo = 'U' or 'u', 
 *        the leading n x n upper triangular part of the array A must contain 
 *        the upper triangular matrix and the strictly lower triangular part 
 *        of A is not referenced. If uplo = 'L' or 'l', the leading n x n lower
 *        triangular part of the array A must contain the lower triangular 
 *        matrix and the strictly upper triangular part of A is not referenced.
 *        When diag = 'U' or 'u', the diagonal elements of A are not referenced
 *        either, but are are assumed to be unity.
 * lda    is the leading dimension of A. It must be at least max (1, n).
 * x      single precision array of length at least (1 + (n - 1) * abs(incx) ).
 *        On entry, x contains the source vector. On exit, x is overwritten 
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x,
 *
 * Reference: http://www.netlib.org/blas/strmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasStrmv (char uplo, char trans, char diag, int n, 
                            const float *A, int lda, float *x, int incx);

/*
 * void 
 * cublasStrsv (char uplo, char trans, char diag, int n, const float *A,
 *              int lda, float *x, int incx)
 *
 * solves a system of equations op(A) * x = b, where op(A) is either A or 
 * transpose(A). b and x are single precision vectors consisting of n
 * elements, and A is an n x n matrix composed of a unit or non-unit, upper
 * or lower triangular matrix. Matrix A is stored in column major format,
 * and lda is the leading dimension of the two-dimensional array containing
 * A.
 *
 * No test for singularity or near-singularity is included in this function. 
 * Such tests must be performed before calling this function.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the 
 *        lower triangular part of array A. If uplo = 'U' or 'u', then only 
 *        the upper triangular part of A may be referenced. If uplo = 'L' or 
 *        'l', then only the lower triangular part of A may be referenced.
 * trans  specifies op(A). If transa = 'n' or 'N', op(A) = A. If transa = 't',
 *        'T', 'c', or 'C', op(A) = transpose(A)
 * diag   specifies whether or not A is a unit triangular matrix like so:
 *        if diag = 'U' or 'u', A is assumed to be unit triangular. If 
 *        diag = 'N' or 'n', then A is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. It
 *        must be at least 0. 
 * A      is a single precision array of dimensions (lda, n). If uplo = 'U' 
 *        or 'u', then A must contains the upper triangular part of a symmetric
 *        matrix, and the strictly lower triangular parts is not referenced. 
 *        If uplo = 'L' or 'l', then A contains the lower triangular part of 
 *        a symmetric matrix, and the strictly upper triangular part is not 
 *        referenced. 
 * lda    is the leading dimension of the two-dimensional array containing A.
 *        lda must be at least max(1, n).
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the n element right-hand side vector b. On exit,
 *        it is overwritten with the solution vector x.
 * incx   specifies the storage spacing between elements of x. incx must not 
 *        be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/strsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasStrsv (char uplo, char trans, char diag, int n, 
                            const float *A, int lda, float *x, int incx);
                            
/* ----------------- CUBLAS double complex BLAS2 functions ----------------- */

/*
 * void 
 * cublasZtrmv (char uplo, char trans, char diag, int n, const cuDoubleComplex *A, 
 *              int lda, cuDoubleComplex *x, int incx);
 *
 * performs one of the matrix-vector operations x = op(A) * x, 
 * where op(A) = A, or op(A) = transpose(A) or op(A) = conjugate(transpose(A)). 
 * x is an n-element double precision complex vector, and 
 * A is an n x n, unit or non-unit, upper or lower, triangular matrix composed 
 * of double precision complex elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular 
 *        matrix. If uplo = 'U' or 'u', then A is an upper triangular matrix. 
 *        If uplo = 'L' or 'l', then A is a lower triangular matrix.
 * trans  specifies op(A). If trans = 'n' or 'N', op(A) = A. If trans = 't' or
 *        'T', op(A) = transpose(A).  If trans = 'c' or 'C', op(A) =
 *        conjugate(transpose(A)).
 * diag   specifies whether or not matrix A is unit triangular. If diag = 'U' 
 *        or 'u', A is assumed to be unit triangular. If diag = 'N' or 'n', A 
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be 
 *        at least zero.
 * A      double precision array of dimension (lda, n). If uplo = 'U' or 'u', 
 *        the leading n x n upper triangular part of the array A must contain 
 *        the upper triangular matrix and the strictly lower triangular part 
 *        of A is not referenced. If uplo = 'L' or 'l', the leading n x n lower
 *        triangular part of the array A must contain the lower triangular 
 *        matrix and the strictly upper triangular part of A is not referenced.
 *        When diag = 'U' or 'u', the diagonal elements of A are not referenced
 *        either, but are are assumed to be unity.
 * lda    is the leading dimension of A. It must be at least max (1, n).
 * x      double precision array of length at least (1 + (n - 1) * abs(incx) ).
 *        On entry, x contains the source vector. On exit, x is overwritten 
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x,
 *
 * Reference: http://www.netlib.org/blas/ztrmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZtrmv (char uplo, char trans, char diag, int n, 
                            const cuDoubleComplex *A, int lda, cuDoubleComplex *x,
                            int incx);

/*
 * void 
 * cublasZgbmv (char trans, int m, int n, int kl, int ku, cuDoubleComplex alpha,
 *              const cuDoubleComplex *A, int lda, const cuDoubleComplex *x, int incx, cuDoubleComplex beta,
 *              cuDoubleComplex *y, int incy);
 *
 * performs one of the matrix-vector operations
 *
 *    y = alpha*op(A)*x + beta*y,  op(A)=A or op(A) = transpose(A)
 *
 * alpha and beta are double precision complex scalars. x and y are double precision
 * complex vectors. A is an m by n band matrix consisting of double precision complex elements
 * with kl sub-diagonals and ku super-diagonals.
 *
 * Input
 * -----
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T', 
 *        or 't', op(A) = transpose(A). If trans == 'C' or 'c',
 *        op(A) = conjugate(transpose(A)).
 * m      specifies the number of rows of the matrix A. m must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. n must be at least
 *        zero.
 * kl     specifies the number of sub-diagonals of matrix A. It must be at 
 *        least zero.
 * ku     specifies the number of super-diagonals of matrix A. It must be at
 *        least zero.
 * alpha  double precision complex scalar multiplier applied to op(A).
 * A      double precision complex array of dimensions (lda, n). The leading
 *        (kl + ku + 1) x n part of the array A must contain the band matrix A,
 *        supplied column by column, with the leading diagonal of the matrix 
 *        in row (ku + 1) of the array, the first super-diagonal starting at 
 *        position 2 in row ku, the first sub-diagonal starting at position 1
 *        in row (ku + 2), and so on. Elements in the array A that do not 
 *        correspond to elements in the band matrix (such as the top left 
 *        ku x ku triangle) are not referenced.
 * lda    leading dimension of A. lda must be at least (kl + ku + 1).
 * x      double precision complex array of length at least (1+(n-1)*abs(incx)) when 
 *        trans == 'N' or 'n' and at least (1+(m-1)*abs(incx)) otherwise.
 * incx   specifies the increment for the elements of x. incx must not be zero.
 * beta   double precision complex scalar multiplier applied to vector y. If beta is 
 *        zero, y is not read.
 * y      double precision complex array of length at least (1+(m-1)*abs(incy)) when 
 *        trans == 'N' or 'n' and at least (1+(n-1)*abs(incy)) otherwise. If 
 *        beta is zero, y is not read.
 * incy   On entry, incy specifies the increment for the elements of y. incy 
 *        must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*op(A)*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/zgbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZgbmv (char trans, int m, int n, int kl, int ku, 
                            cuDoubleComplex alpha, const cuDoubleComplex *A, int lda, 
                            const cuDoubleComplex *x, int incx, cuDoubleComplex beta, 
                            cuDoubleComplex *y, int incy);
                            
           /*
 * void 
 * cublasZtbmv (char uplo, char trans, char diag, int n, int k, const cuDoubleComplex *A,
 *              int lda, cuDoubleComplex *x, int incx)
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = A,
 * op(A) = transpose(A) or op(A) = conjugate(transpose(A)). x is an n-element 
 * double precision complex vector, and A is an n x n, unit or non-unit, upper 
 * or lower triangular band matrix composed of double precision complex elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular band
 *        matrix. If uplo == 'U' or 'u', A is an upper triangular band matrix.
 *        If uplo == 'L' or 'l', A is a lower triangular band matrix.
 * trans  specifies op(A). If transa == 'N' or 'n', op(A) = A. If trans == 'T',
 *        or 't', op(A) = transpose(A). If trans == 'C' or 'c',
 *        op(A) = conjugate(transpose(A)).
 * diag   specifies whether or not matrix A is unit triangular. If diag == 'U'
 *        or 'u', A is assumed to be unit triangular. If diag == 'N' or 'n', A
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * k      specifies the number of super- or sub-diagonals. If uplo == 'U' or 
 *        'u', k specifies the number of super-diagonals. If uplo == 'L' or 
 *        'l', k specifies the number of sub-diagonals. k must at least be 
 *        zero.
 * A      double precision complex array of dimension (lda, n). If uplo == 'U' or 'u',
 *        the leading (k + 1) x n part of the array A must contain the upper 
 *        triangular band matrix, supplied column by column, with the leading
 *        diagonal of the matrix in row (k + 1) of the array, the first 
 *        super-diagonal starting at position 2 in row k, and so on. The top
 *        left k x k triangle of the array A is not referenced. If uplo == 'L'
 *        or 'l', the leading (k + 1) x n part of the array A must constain the
 *        lower triangular band matrix, supplied column by column, with the
 *        leading diagonal of the matrix in row 1 of the array, the first 
 *        sub-diagonal startingat position 1 in row 2, and so on. The bottom
 *        right k x k triangle of the array is not referenced.
 * lda    is the leading dimension of A. It must be at least (k + 1).
 * x      double precision complex array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the source vector. On exit, x is overwritten
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x
 *
 * Reference: http://www.netlib.org/blas/ztbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n or k < 0, or if incx == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZtbmv (char uplo, char trans, char diag, int n,
                           int k, const cuDoubleComplex *A, int lda, cuDoubleComplex *x,
                           int incx);
                           
/*
 * void cublasZtbsv (char uplo, char trans, char diag, int n, int k,
 *                   const cuDoubleComplex *A, int lda, cuDoubleComplex *X, int incx)
 *
 * solves one of the systems of equations op(A)*x = b, where op(A) is either 
 * op(A) = A , op(A) = transpose(A) or op(A) = conjugate(transpose(A)).
 * b and x are n element vectors, and A is an n x n unit or non-unit,
 * upper or lower triangular band matrix with k + 1 diagonals. No test
 * for singularity or near-singularity is included in this function.
 * Such tests must be performed before calling this function.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix is an upper or lower triangular band 
 *        matrix as follows: If uplo == 'U' or 'u', A is an upper triangular
 *        band matrix. If uplo == 'L' or 'l', A is a lower triangular band
 *        matrix.
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', op(A) = transpose(A). If trans == 'C' or 'c',
 *        op(A) = conjugate(transpose(A)). 
 * diag   specifies whether A is unit triangular. If diag == 'U' or 'u', A is
 *        assumed to be unit triangular; thas is, diagonal elements are not
 *        read and are assumed to be unity. If diag == 'N' or 'n', A is not
 *        assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * k      specifies the number of super- or sub-diagonals. If uplo == 'U' or
 *        'u', k specifies the number of super-diagonals. If uplo == 'L' or
 *        'l', k specifies the number of sub-diagonals. k must at least be 
 *        zero.
 * A      double precision complex array of dimension (lda, n). If uplo == 'U' or 'u',
 *        the leading (k + 1) x n part of the array A must contain the upper
 *        triangular band matrix, supplied column by column, with the leading
 *        diagonal of the matrix in row (k + 1) of the array, the first super-
 *        diagonal starting at position 2 in row k, and so on. The top left 
 *        k x k triangle of the array A is not referenced. If uplo == 'L' or 
 *        'l', the leading (k + 1) x n part of the array A must constain the
 *        lower triangular band matrix, supplied column by column, with the
 *        leading diagonal of the matrix in row 1 of the array, the first
 *        sub-diagonal starting at position 1 in row 2, and so on. The bottom
 *        right k x k triangle of the array is not referenced.
 * x      double precision complex array of length at least (1+(n-1)*abs(incx)).
 * incx   storage spacing between elements of x. It must not be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/ztbsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0, n < 0 or n > 1016
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support   
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZtbsv (char uplo, char trans, char diag, int n,
                            int k, const cuDoubleComplex *A, int lda, cuDoubleComplex *x,
                            int incx);  
                            

/*
 * void 
 * cublasZhemv (char uplo, int n, cuDoubleComplex alpha, const cuDoubleComplex *A, int lda, 
 *              const cuDoubleComplex *x, int incx, cuDoubleComplex beta, cuDoubleComplex *y, int incy)
 *
 * performs the matrix-vector operation
 *
 *     y = alpha*A*x + beta*y
 *
 * Alpha and beta are double precision complex scalars, and x and y are double 
 * precision complex vectors, each with n elements. A is a hermitian n x n matrix 
 * consisting of double precision complex elements that is stored in either upper or 
 * lower storage mode.
 *
 * Input
 * -----
 * uplo   specifies whether the upper or lower triangular part of the array A 
 *        is to be referenced. If uplo == 'U' or 'u', the hermitian matrix A 
 *        is stored in upper storage mode, i.e. only the upper triangular part
 *        of A is to be referenced while the lower triangular part of A is to 
 *        be inferred. If uplo == 'L' or 'l', the hermitian matrix A is stored
 *        in lower storage mode, i.e. only the lower triangular part of A is 
 *        to be referenced while the upper triangular part of A is to be 
 *        inferred.
 * n      specifies the number of rows and the number of columns of the 
 *        hermitian matrix A. n must be at least zero.
 * alpha  double precision complex scalar multiplier applied to A*x.
 * A      double precision complex array of dimensions (lda, n). If uplo == 'U' or 'u',
 *        the leading n x n upper triangular part of the array A must contain
 *        the upper triangular part of the hermitian matrix and the strictly
 *        lower triangular part of A is not referenced. If uplo == 'L' or 'l',
 *        the leading n x n lower triangular part of the array A must contain
 *        the lower triangular part of the hermitian matrix and the strictly
 *        upper triangular part of A is not referenced. The imaginary parts
 *        of the diagonal elements need not be set, they are assumed to be zero. 
 * lda    leading dimension of A. It must be at least max (1, n).
 * x      double precision complex array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   double precision complex scalar multiplier applied to vector y.
 * y      double precision complex array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read. 
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/zhemv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZhemv (char uplo, int n, cuDoubleComplex alpha,
                            const cuDoubleComplex *A, int lda, const cuDoubleComplex *x,
                            int incx, cuDoubleComplex beta, cuDoubleComplex *y, int incy);
                            
/*
 * void 
 * cublasZhpmv (char uplo, int n, cuDoubleComplex alpha, const cuDoubleComplex *AP, const cuDoubleComplex *x,
 *              int incx, cuDoubleComplex beta, cuDoubleComplex *y, int incy)
 *
 * performs the matrix-vector operation
 * 
 *    y = alpha * A * x + beta * y
 *
 * Alpha and beta are double precision complex scalars, and x and y are double 
 * precision complex vectors with n elements. A is an hermitian n x n matrix 
 * consisting of double precision complex elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array AP. If uplo == 'U' or 'u', then the upper 
 *        triangular part of A is supplied in AP. If uplo == 'L' or 'l', then 
 *        the lower triangular part of A is supplied in AP.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  double precision complex scalar multiplier applied to A*x.
 * AP     double precision complex array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *        The imaginary parts of the diagonal elements need not be set, they
 *        are assumed to be zero. 
 * x      double precision complex array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   double precision complex scalar multiplier applied to vector y;
 * y      double precision array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read. 
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/zhpmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support   
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZhpmv (char uplo, int n, cuDoubleComplex alpha,
                            const cuDoubleComplex *AP, const cuDoubleComplex *x,
                            int incx, cuDoubleComplex beta, cuDoubleComplex *y, int incy);                            
                                                     
/* ----------------- CUBLAS double complex BLAS3 functions ----------------- */

/*
 * cublasZgemv (char trans, int m, int n, cuDoubleComplex alpha, const cuDoubleComplex *A, int lda,
 *              const cuDoubleComplex *x, int incx, cuDoubleComplex beta, cuDoubleComplex *y, int incy)
 *
 * performs one of the matrix-vector operations
 *
 *    y = alpha * op(A) * x + beta * y,
 *
 * where op(A) is one of
 *
 *    op(A) = A   or   op(A) = transpose(A)
 *
 * where alpha and beta are double precision scalars, x and y are double 
 * precision vectors, and A is an m x n matrix consisting of double precision
 * elements. Matrix A is stored in column major format, and lda is the leading
 * dimension of the two-dimensional array in which A is stored.
 *
 * Input
 * -----
 * trans  specifies op(A). If transa = 'n' or 'N', op(A) = A. If trans =
 *        trans = 't', 'T', 'c', or 'C', op(A) = transpose(A)
 * m      specifies the number of rows of the matrix A. m must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. n must be at least 
 *        zero.
 * alpha  double precision scalar multiplier applied to op(A).
 * A      double precision array of dimensions (lda, n) if trans = 'n' or 
 *        'N'), and of dimensions (lda, m) otherwise. lda must be at least 
 *        max(1, m) and at least max(1, n) otherwise.
 * lda    leading dimension of two-dimensional array used to store matrix A
 * x      double precision array of length at least (1 + (n - 1) * abs(incx))
 *        when trans = 'N' or 'n' and at least (1 + (m - 1) * abs(incx)) 
 *        otherwise.
 * incx   specifies the storage spacing between elements of x. incx must not 
 *        be zero.
 * beta   double precision scalar multiplier applied to vector y. If beta 
 *        is zero, y is not read.
 * y      double precision array of length at least (1 + (m - 1) * abs(incy))
 *        when trans = 'N' or 'n' and at least (1 + (n - 1) * abs(incy)) 
 *        otherwise.
 * incy   specifies the storage spacing between elements of x. incx must not
 *        be zero.
 *
 * Output
 * ------
 * y      updated according to alpha * op(A) * x + beta * y
 *
 * Reference: http://www.netlib.org/blas/zgemv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0, or if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZgemv (char trans, int m, int n, cuDoubleComplex alpha,
                            const cuDoubleComplex *A, int lda, const cuDoubleComplex *x, int incx,
                            cuDoubleComplex beta, cuDoubleComplex *y, int incy);
                            

/*
 * void 
 * cublasZtpmv (char uplo, char trans, char diag, int n, const cuDoubleComplex *AP, 
 *              cuDoubleComplex *x, int incx);
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = A,
 * op(A) = transpose(A) or op(A) = conjugate(transpose(A)) . x is an n element 
 * double precision complex vector, and A is an n x n, unit or non-unit, upper
 * or lower triangular matrix composed of double precision complex elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix. If uplo == 'U' or 'u', then A is an upper triangular matrix.
 *        If uplo == 'L' or 'l', then A is a lower triangular matrix.
 * trans  specifies op(A). If transa == 'N' or 'n', op(A) = A. If trans == 'T',
 *        or 't', op(A) = transpose(A). If trans == 'C' or 'c', 
 *        op(A) = conjugate(transpose(A)).
 *
 * diag   specifies whether or not matrix A is unit triangular. If diag == 'U'
 *        or 'u', A is assumed to be unit triangular. If diag == 'N' or 'n', A 
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be 
 *        at least zero. In the current implementation n must not exceed 4070.
 * AP     double precision complex array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored in AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 * x      double precision complex array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the source vector. On exit, x is overwritten 
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x,
 *
 * Reference: http://www.netlib.org/blas/ztpmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or n < 0
 * CUBLAS_STATUS_ALLOC_FAILED     if function cannot allocate enough internal scratch vector memory 
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZtpmv (char uplo, char trans, char diag, int n, 
                            const cuDoubleComplex *AP, cuDoubleComplex *x, int incx);                            
                            

/*
 * void 
 * cublasZtpsv (char uplo, char trans, char diag, int n, const cuDoubleComplex *AP, 
 *              cuDoubleComplex *X, int incx)
 *
 * solves one of the systems of equations op(A)*x = b, where op(A) is either 
 * op(A) = A , op(A) = transpose(A) or op(A) = conjugate(transpose)). b and
 * x are n element complex vectors, and A is an n x n unit or non-unit,
 * upper or lower triangular matrix. No test for singularity or near-singularity
 * is included in this routine. Such tests must be performed before calling this routine.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix is an upper or lower triangular matrix
 *        as follows: If uplo == 'U' or 'u', A is an upper triangluar matrix.
 *        If uplo == 'L' or 'l', A is a lower triangular matrix.
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T'
 *        or 't', op(A) = transpose(A). If trans == 'C' or 'c', op(A) = 
 *        conjugate(transpose(A)).
 * diag   specifies whether A is unit triangular. If diag == 'U' or 'u', A is
 *        assumed to be unit triangular; thas is, diagonal elements are not
 *        read and are assumed to be unity. If diag == 'N' or 'n', A is not
 *        assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * AP     double precision complex array with at least ((n*(n+1))/2) elements.
 *        If uplo == 'U' or 'u', the array AP contains the upper triangular
 *        matrix A, packed sequentially, column by column; that is, if i <= j, then 
 *        A[i,j] is stored is AP[i+(j*(j+1)/2)]. If uplo == 'L' or 'L', the 
 *        array AP contains the lower triangular matrix A, packed sequentially,
 *        column by column; that is, if i >= j, then A[i,j] is stored in 
 *        AP[i+((2*n-j+1)*j)/2]. When diag = 'U' or 'u', the diagonal elements
 *        of A are not referenced and are assumed to be unity.
 * x      double precision complex array of length at least (1+(n-1)*abs(incx)).
 * incx   storage spacing between elements of x. It must not be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/ztpsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0 or n > 2035
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support    
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZtpsv (char uplo, char trans, char diag, int n,
                            const cuDoubleComplex *AP, cuDoubleComplex *x, int incx);                            


/* ----------------- CUBLAS single complex BLAS2 functions ----------------- */
/*
 * cublasCgemv (char trans, int m, int n, cuComplex alpha, const cuComplex *A, 
 *              int lda, const cuComplex *x, int incx, cuComplex beta, cuComplex *y, 
 *              int incy)
 *
 * performs one of the matrix-vector operations
 *
 *    y = alpha * op(A) * x + beta * y,
 *
 * where op(A) is one of
 *
 *    op(A) = A   or   op(A) = transpose(A) or op(A) = conjugate(transpose(A))
 *
 * where alpha and beta are single precision scalars, x and y are single 
 * precision vectors, and A is an m x n matrix consisting of single precision
 * elements. Matrix A is stored in column major format, and lda is the leading
 * dimension of the two-dimensional array in which A is stored.
 *
 * Input
 * -----
 * trans  specifies op(A). If transa = 'n' or 'N', op(A) = A. If trans =
 *        trans = 't' or 'T', op(A) = transpose(A). If trans = 'c' or 'C', 
 *        op(A) = conjugate(transpose(A))
 * m      specifies the number of rows of the matrix A. m must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. n must be at least 
 *        zero.
 * alpha  single precision scalar multiplier applied to op(A).
 * A      single precision array of dimensions (lda, n) if trans = 'n' or 
 *        'N'), and of dimensions (lda, m) otherwise. lda must be at least 
 *        max(1, m) and at least max(1, n) otherwise.
 * lda    leading dimension of two-dimensional array used to store matrix A
 * x      single precision array of length at least (1 + (n - 1) * abs(incx))
 *        when trans = 'N' or 'n' and at least (1 + (m - 1) * abs(incx)) 
 *        otherwise.
 * incx   specifies the storage spacing between elements of x. incx must not 
 *        be zero.
 * beta   single precision scalar multiplier applied to vector y. If beta 
 *        is zero, y is not read.
 * y      single precision array of length at least (1 + (m - 1) * abs(incy))
 *        when trans = 'N' or 'n' and at least (1 + (n - 1) * abs(incy)) 
 *        otherwise.
 * incy   specifies the storage spacing between elements of y. incy must not
 *        be zero.
 *
 * Output
 * ------
 * y      updated according to alpha * op(A) * x + beta * y
 *
 * Reference: http://www.netlib.org/blas/cgemv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0, or if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCgemv (char trans, int m, int n, cuComplex alpha,
                            const cuComplex *A, int lda, const cuComplex *x, 
                            int incx, cuComplex beta, cuComplex *y, int incy);
/*
 * void 
 * cublasCgbmv (char trans, int m, int n, int kl, int ku, cuComplex alpha,
 *              const cuComplex *A, int lda, const cuComplex *x, int incx, cuComplex beta,
 *              cuComplex *y, int incy);
 *
 * performs one of the matrix-vector operations
 *
 *    y = alpha*op(A)*x + beta*y,  op(A)=A or op(A) = transpose(A)
 *
 * alpha and beta are single precision complex scalars. x and y are single precision
 * complex vectors. A is an m by n band matrix consisting of single precision complex elements
 * with kl sub-diagonals and ku super-diagonals.
 *
 * Input
 * -----
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T', 
 *        or 't', op(A) = transpose(A). If trans == 'C' or 'c',
 *        op(A) = conjugate(transpose(A)).
 * m      specifies the number of rows of the matrix A. m must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. n must be at least
 *        zero.
 * kl     specifies the number of sub-diagonals of matrix A. It must be at 
 *        least zero.
 * ku     specifies the number of super-diagonals of matrix A. It must be at
 *        least zero.
 * alpha  single precision complex scalar multiplier applied to op(A).
 * A      single precision complex array of dimensions (lda, n). The leading
 *        (kl + ku + 1) x n part of the array A must contain the band matrix A,
 *        supplied column by column, with the leading diagonal of the matrix 
 *        in row (ku + 1) of the array, the first super-diagonal starting at 
 *        position 2 in row ku, the first sub-diagonal starting at position 1
 *        in row (ku + 2), and so on. Elements in the array A that do not 
 *        correspond to elements in the band matrix (such as the top left 
 *        ku x ku triangle) are not referenced.
 * lda    leading dimension of A. lda must be at least (kl + ku + 1).
 * x      single precision complex array of length at least (1+(n-1)*abs(incx)) when 
 *        trans == 'N' or 'n' and at least (1+(m-1)*abs(incx)) otherwise.
 * incx   specifies the increment for the elements of x. incx must not be zero.
 * beta   single precision complex scalar multiplier applied to vector y. If beta is 
 *        zero, y is not read.
 * y      single precision complex array of length at least (1+(m-1)*abs(incy)) when 
 *        trans == 'N' or 'n' and at least (1+(n-1)*abs(incy)) otherwise. If 
 *        beta is zero, y is not read.
 * incy   On entry, incy specifies the increment for the elements of y. incy 
 *        must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*op(A)*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/cgbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI cublasCgbmv (char trans, int m, int n, int kl, int ku,
                            cuComplex alpha, const cuComplex *A, int lda,
                            const cuComplex *x, int incx, cuComplex beta,
                            cuComplex *y, int incy);
/*
 * void 
 * cublasChemv (char uplo, int n, cuComplex alpha, const cuComplex *A, int lda, 
 *              const cuComplex *x, int incx, cuComplex beta, cuComplex *y, int incy)
 *
 * performs the matrix-vector operation
 *
 *     y = alpha*A*x + beta*y
 *
 * Alpha and beta are single precision complex scalars, and x and y are single 
 * precision complex vectors, each with n elements. A is a hermitian n x n matrix 
 * consisting of single precision complex elements that is stored in either upper or 
 * lower storage mode.
 *
 * Input
 * -----
 * uplo   specifies whether the upper or lower triangular part of the array A 
 *        is to be referenced. If uplo == 'U' or 'u', the hermitian matrix A 
 *        is stored in upper storage mode, i.e. only the upper triangular part
 *        of A is to be referenced while the lower triangular part of A is to 
 *        be inferred. If uplo == 'L' or 'l', the hermitian matrix A is stored
 *        in lower storage mode, i.e. only the lower triangular part of A is 
 *        to be referenced while the upper triangular part of A is to be 
 *        inferred.
 * n      specifies the number of rows and the number of columns of the 
 *        hermitian matrix A. n must be at least zero.
 * alpha  single precision complex scalar multiplier applied to A*x.
 * A      single precision complex array of dimensions (lda, n). If uplo == 'U' or 'u',
 *        the leading n x n upper triangular part of the array A must contain
 *        the upper triangular part of the hermitian matrix and the strictly
 *        lower triangular part of A is not referenced. If uplo == 'L' or 'l',
 *        the leading n x n lower triangular part of the array A must contain
 *        the lower triangular part of the hermitian matrix and the strictly
 *        upper triangular part of A is not referenced. The imaginary parts
 *        of the diagonal elements need not be set, they are assumed to be zero. 
 * lda    leading dimension of A. It must be at least max (1, n).
 * x      single precision complex array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   single precision complex scalar multiplier applied to vector y.
 * y      single precision complex array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read. 
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/chemv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
                      
void CUBLASAPI cublasChemv (char uplo, int n, cuComplex alpha, 
                            const cuComplex *A, int lda, const cuComplex *x,
                            int incx, cuComplex beta, cuComplex *y, int incy);
/*
 * void 
 * cublasChbmv (char uplo, int n, int k, cuComplex alpha, const cuComplex *A, int lda,
 *              const cuComplex *x, int incx, cuComplex beta, cuComplex *y, int incy)
 *
 * performs the matrix-vector operation
 *
 *     y := alpha*A*x + beta*y
 *
 * alpha and beta are single precision complex scalars. x and y are single precision
 * complex vectors with n elements. A is an n by n hermitian band matrix consisting 
 * of single precision complex elements, with k super-diagonals and the same number
 * of subdiagonals.
 *
 * Input
 * -----
 * uplo   specifies whether the upper or lower triangular part of the hermitian
 *        band matrix A is being supplied. If uplo == 'U' or 'u', the upper 
 *        triangular part is being supplied. If uplo == 'L' or 'l', the lower 
 *        triangular part is being supplied.
 * n      specifies the number of rows and the number of columns of the
 *        hermitian matrix A. n must be at least zero.
 * k      specifies the number of super-diagonals of matrix A. Since the matrix
 *        is hermitian, this is also the number of sub-diagonals. k must be at
 *        least zero.
 * alpha  single precision complex scalar multiplier applied to A*x.
 * A      single precision complex array of dimensions (lda, n). When uplo == 'U' or 
 *        'u', the leading (k + 1) x n part of array A must contain the upper
 *        triangular band of the hermitian matrix, supplied column by column,
 *        with the leading diagonal of the matrix in row (k+1) of the array,
 *        the first super-diagonal starting at position 2 in row k, and so on.
 *        The top left k x k triangle of the array A is not referenced. When
 *        uplo == 'L' or 'l', the leading (k + 1) x n part of the array A must
 *        contain the lower triangular band part of the hermitian matrix, 
 *        supplied column by column, with the leading diagonal of the matrix in
 *        row 1 of the array, the first sub-diagonal starting at position 1 in
 *        row 2, and so on. The bottom right k x k triangle of the array A is
 *        not referenced. The imaginary parts of the diagonal elements need 
 *        not be set, they are assumed to be zero. 
 * lda    leading dimension of A. lda must be at least (k + 1).
 * x      single precision complex array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   single precision complex scalar multiplier applied to vector y. If beta is 
 *        zero, y is not read.
 * y      single precision complex array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read.
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/chbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized 
 * CUBLAS_STATUS_INVALID_VALUE    if k or n < 0, or if incx or incy == 0  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI cublasChbmv (char uplo, int n, int k, cuComplex alpha,
                            const cuComplex *A, int lda, const cuComplex *x,
                            int incx, cuComplex beta, cuComplex *y, int incy);

/*
 * void 
 * cublasChpmv (char uplo, int n, cuComplex alpha, const cuComplex *AP, const cuComplex *x,
 *              int incx, cuComplex beta, cuComplex *y, int incy)
 *
 * performs the matrix-vector operation
 * 
 *    y = alpha * A * x + beta * y
 *
 * Alpha and beta are single precision complex scalars, and x and y are single 
 * precision complex vectors with n elements. A is an hermitian n x n matrix 
 * consisting of single precision complex elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array AP. If uplo == 'U' or 'u', then the upper 
 *        triangular part of A is supplied in AP. If uplo == 'L' or 'l', then 
 *        the lower triangular part of A is supplied in AP.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  single precision complex scalar multiplier applied to A*x.
 * AP     single precision complex array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *        The imaginary parts of the diagonal elements need not be set, they
 *        are assumed to be zero. 
 * x      single precision complex array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   single precision complex scalar multiplier applied to vector y;
 * y      single precision array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read. 
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/chpmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasChpmv (char uplo, int n, cuComplex alpha,
                            const cuComplex *AP, const cuComplex *x, int incx,
                            cuComplex beta, cuComplex *y, int incy);
                            
/*
 * 
 * cublasCtrmv (char uplo, char trans, char diag, int n, const cuComplex *A, 
 *              int lda, cuComplex *x, int incx);
 *
 * performs one of the matrix-vector operations x = op(A) * x, 
 * where op(A) = A, or op(A) = transpose(A) or op(A) = conjugate(transpose(A)). 
 * x is an n-element signle precision complex vector, and 
 * A is an n x n, unit or non-unit, upper or lower, triangular matrix composed 
 * of single precision complex elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular 
 *        matrix. If uplo = 'U' or 'u', then A is an upper triangular matrix. 
 *        If uplo = 'L' or 'l', then A is a lower triangular matrix.
 * trans  specifies op(A). If trans = 'n' or 'N', op(A) = A. If trans = 't' or
 *        'T', op(A) = transpose(A).  If trans = 'c' or 'C', op(A) =
 *        conjugate(transpose(A)).
 * diag   specifies whether or not matrix A is unit triangular. If diag = 'U' 
 *        or 'u', A is assumed to be unit triangular. If diag = 'N' or 'n', A 
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be 
 *        at least zero.
 * A      single precision array of dimension (lda, n). If uplo = 'U' or 'u', 
 *        the leading n x n upper triangular part of the array A must contain 
 *        the upper triangular matrix and the strictly lower triangular part 
 *        of A is not referenced. If uplo = 'L' or 'l', the leading n x n lower
 *        triangular part of the array A must contain the lower triangular 
 *        matrix and the strictly upper triangular part of A is not referenced.
 *        When diag = 'U' or 'u', the diagonal elements of A are not referenced
 *        either, but are are assumed to be unity.
 * lda    is the leading dimension of A. It must be at least max (1, n).
 * x      single precision array of length at least (1 + (n - 1) * abs(incx) ).
 *        On entry, x contains the source vector. On exit, x is overwritten 
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x,
 *
 * Reference: http://www.netlib.org/blas/ctrmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI  cublasCtrmv (char uplo, char trans, char diag, int n,
                             const cuComplex *A, int lda, cuComplex *x,
                             int incx);
                             
/*
 * void 
 * cublasCtbmv (char uplo, char trans, char diag, int n, int k, const cuComplex *A,
 *              int lda, cuComplex *x, int incx)
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = A,
 * op(A) = transpose(A) or op(A) = conjugate(transpose(A)). x is an n-element 
 * single precision complex vector, and A is an n x n, unit or non-unit, upper 
 * or lower triangular band matrix composed of single precision complex elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular band
 *        matrix. If uplo == 'U' or 'u', A is an upper triangular band matrix.
 *        If uplo == 'L' or 'l', A is a lower triangular band matrix.
 * trans  specifies op(A). If transa == 'N' or 'n', op(A) = A. If trans == 'T',
 *        or 't', op(A) = transpose(A). If trans == 'C' or 'c',
 *        op(A) = conjugate(transpose(A)).
 * diag   specifies whether or not matrix A is unit triangular. If diag == 'U'
 *        or 'u', A is assumed to be unit triangular. If diag == 'N' or 'n', A
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * k      specifies the number of super- or sub-diagonals. If uplo == 'U' or 
 *        'u', k specifies the number of super-diagonals. If uplo == 'L' or 
 *        'l', k specifies the number of sub-diagonals. k must at least be 
 *        zero.
 * A      single precision complex array of dimension (lda, n). If uplo == 'U' or 'u',
 *        the leading (k + 1) x n part of the array A must contain the upper 
 *        triangular band matrix, supplied column by column, with the leading
 *        diagonal of the matrix in row (k + 1) of the array, the first 
 *        super-diagonal starting at position 2 in row k, and so on. The top
 *        left k x k triangle of the array A is not referenced. If uplo == 'L'
 *        or 'l', the leading (k + 1) x n part of the array A must constain the
 *        lower triangular band matrix, supplied column by column, with the
 *        leading diagonal of the matrix in row 1 of the array, the first 
 *        sub-diagonal startingat position 1 in row 2, and so on. The bottom
 *        right k x k triangle of the array is not referenced.
 * lda    is the leading dimension of A. It must be at least (k + 1).
 * x      single precision complex array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the source vector. On exit, x is overwritten
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x
 *
 * Reference: http://www.netlib.org/blas/ctbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n or k < 0, or if incx == 0
 * CUBLAS_STATUS_ALLOC_FAILED     if function cannot allocate enough internal scratch vector memory 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                             
void CUBLASAPI cublasCtbmv (char uplo, char trans, char diag, int n, int k, 
                            const cuComplex *A, int lda, cuComplex *x,
                            int incx);
/*
 * void 
 * cublasCtpmv (char uplo, char trans, char diag, int n, const cuComplex *AP, 
 *              cuComplex *x, int incx);
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = A,
 * op(A) = transpose(A) or op(A) = conjugate(transpose(A)) . x is an n element 
 * single precision complex vector, and A is an n x n, unit or non-unit, upper
 * or lower triangular matrix composed of single precision complex elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix. If uplo == 'U' or 'u', then A is an upper triangular matrix.
 *        If uplo == 'L' or 'l', then A is a lower triangular matrix.
 * trans  specifies op(A). If transa == 'N' or 'n', op(A) = A. If trans == 'T',
 *        or 't', op(A) = transpose(A). If trans == 'C' or 'c', 
 *        op(A) = conjugate(transpose(A)).
 *
 * diag   specifies whether or not matrix A is unit triangular. If diag == 'U'
 *        or 'u', A is assumed to be unit triangular. If diag == 'N' or 'n', A 
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be 
 *        at least zero. In the current implementation n must not exceed 4070.
 * AP     single precision complex array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored in AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 * x      single precision complex array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the source vector. On exit, x is overwritten 
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x,
 *
 * Reference: http://www.netlib.org/blas/ctpmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or n < 0
 * CUBLAS_STATUS_ALLOC_FAILED     if function cannot allocate enough internal scratch vector memory 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                             
void CUBLASAPI cublasCtpmv (char uplo, char trans, char diag, int n,
                            const cuComplex *AP, cuComplex *x, int incx);
/*
 * void 
 * cublasCtrsv (char uplo, char trans, char diag, int n, const cuComplex *A, 
 *              int lda, cuComplex *x, int incx)
 *
 * solves a system of equations op(A) * x = b, where op(A) is either A,  
 * transpose(A) or conjugate(transpose(A)). b and x are single precision 
 * complex vectors consisting of n elements, and A is an n x n matrix 
 * composed of a unit or non-unit, upper or lower triangular matrix.
 * Matrix A is stored in column major format, and lda is the leading 
 * dimension of the two-dimensional array containing A.
 *
 * No test for singularity or near-singularity is included in this function. 
 * Such tests must be performed before calling this function.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the 
 *        lower triangular part of array A. If uplo = 'U' or 'u', then only 
 *        the upper triangular part of A may be referenced. If uplo = 'L' or 
 *        'l', then only the lower triangular part of A may be referenced.
 * trans  specifies op(A). If transa = 'n' or 'N', op(A) = A. If transa = 't',
 *        'T', 'c', or 'C', op(A) = transpose(A)
 * diag   specifies whether or not A is a unit triangular matrix like so:
 *        if diag = 'U' or 'u', A is assumed to be unit triangular. If 
 *        diag = 'N' or 'n', then A is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. It
 *        must be at least 0. 
 * A      is a single precision complex array of dimensions (lda, n). If uplo = 'U' 
 *        or 'u', then A must contains the upper triangular part of a symmetric
 *        matrix, and the strictly lower triangular parts is not referenced. 
 *        If uplo = 'L' or 'l', then A contains the lower triangular part of 
 *        a symmetric matrix, and the strictly upper triangular part is not 
 *        referenced. 
 * lda    is the leading dimension of the two-dimensional array containing A.
 *        lda must be at least max(1, n).
 * x      single precision complex array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the n element right-hand side vector b. On exit,
 *        it is overwritten with the solution vector x.
 * incx   specifies the storage spacing between elements of x. incx must not 
 *        be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/ctrsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI cublasCtrsv (char uplo, char trans, char diag, int n,
                            const cuComplex *A, int lda, cuComplex *x,
                            int incx);
/*
 * void cublasCtbsv (char uplo, char trans, char diag, int n, int k,
 *                   const cuComplex *A, int lda, cuComplex *X, int incx)
 *
 * solves one of the systems of equations op(A)*x = b, where op(A) is either 
 * op(A) = A , op(A) = transpose(A) or op(A) = conjugate(transpose(A)).
 * b and x are n element vectors, and A is an n x n unit or non-unit,
 * upper or lower triangular band matrix with k + 1 diagonals. No test
 * for singularity or near-singularity is included in this function.
 * Such tests must be performed before calling this function.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix is an upper or lower triangular band 
 *        matrix as follows: If uplo == 'U' or 'u', A is an upper triangular
 *        band matrix. If uplo == 'L' or 'l', A is a lower triangular band
 *        matrix.
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', op(A) = transpose(A). If trans == 'C' or 'c',
 *        op(A) = conjugate(transpose(A)). 
 * diag   specifies whether A is unit triangular. If diag == 'U' or 'u', A is
 *        assumed to be unit triangular; thas is, diagonal elements are not
 *        read and are assumed to be unity. If diag == 'N' or 'n', A is not
 *        assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * k      specifies the number of super- or sub-diagonals. If uplo == 'U' or
 *        'u', k specifies the number of super-diagonals. If uplo == 'L' or
 *        'l', k specifies the number of sub-diagonals. k must at least be 
 *        zero.
 * A      single precision complex array of dimension (lda, n). If uplo == 'U' or 'u',
 *        the leading (k + 1) x n part of the array A must contain the upper
 *        triangular band matrix, supplied column by column, with the leading
 *        diagonal of the matrix in row (k + 1) of the array, the first super-
 *        diagonal starting at position 2 in row k, and so on. The top left 
 *        k x k triangle of the array A is not referenced. If uplo == 'L' or 
 *        'l', the leading (k + 1) x n part of the array A must constain the
 *        lower triangular band matrix, supplied column by column, with the
 *        leading diagonal of the matrix in row 1 of the array, the first
 *        sub-diagonal starting at position 1 in row 2, and so on. The bottom
 *        right k x k triangle of the array is not referenced.
 * x      single precision complex array of length at least (1+(n-1)*abs(incx)).
 * incx   storage spacing between elements of x. It must not be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/ctbsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0, n < 0 or n > 2035
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                                                                
void CUBLASAPI cublasCtbsv (char uplo, char trans, char diag, int n, int k, 
                            const cuComplex *A, int lda, cuComplex *x,
                            int incx);
/*
 * void 
 * cublasCtpsv (char uplo, char trans, char diag, int n, const cuComplex *AP, 
 *              cuComplex *X, int incx)
 *
 * solves one of the systems of equations op(A)*x = b, where op(A) is either 
 * op(A) = A , op(A) = transpose(A) or op(A) = conjugate(transpose)). b and
 * x are n element complex vectors, and A is an n x n unit or non-unit,
 * upper or lower triangular matrix. No test for singularity or near-singularity
 * is included in this routine. Such tests must be performed before calling this routine.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix is an upper or lower triangular matrix
 *        as follows: If uplo == 'U' or 'u', A is an upper triangluar matrix.
 *        If uplo == 'L' or 'l', A is a lower triangular matrix.
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T'
 *        or 't', op(A) = transpose(A). If trans == 'C' or 'c', op(A) = 
 *        conjugate(transpose(A)).
 * diag   specifies whether A is unit triangular. If diag == 'U' or 'u', A is
 *        assumed to be unit triangular; thas is, diagonal elements are not
 *        read and are assumed to be unity. If diag == 'N' or 'n', A is not
 *        assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * AP     single precision complex array with at least ((n*(n+1))/2) elements.
 *        If uplo == 'U' or 'u', the array AP contains the upper triangular
 *        matrix A, packed sequentially, column by column; that is, if i <= j, then 
 *        A[i,j] is stored is AP[i+(j*(j+1)/2)]. If uplo == 'L' or 'L', the 
 *        array AP contains the lower triangular matrix A, packed sequentially,
 *        column by column; that is, if i >= j, then A[i,j] is stored in 
 *        AP[i+((2*n-j+1)*j)/2]. When diag = 'U' or 'u', the diagonal elements
 *        of A are not referenced and are assumed to be unity.
 * x      single precision complex array of length at least (1+(n-1)*abs(incx)).
 * incx   storage spacing between elements of x. It must not be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/ctpsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0 or n > 2035 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI cublasCtpsv (char uplo, char trans, char diag, int n,
                            const cuComplex *AP, cuComplex *x, int incx);
                            
/*
 * cublasCgeru (int m, int n, cuComplex alpha, const cuComplex *x, int incx, 
 *             const cuComplex *y, int incy, cuComplex *A, int lda)
 *
 * performs the symmetric rank 1 operation
 *
 *    A = alpha * x * transpose(y) + A,
 *
 * where alpha is a single precision complex scalar, x is an m element single 
 * precision complex vector, y is an n element single precision complex vector, and A 
 * is an m by n matrix consisting of single precision complex elements. Matrix A
 * is stored in column major format, and lda is the leading dimension of
 * the two-dimensional array used to store A.
 * 
 * Input
 * -----
 * m      specifies the number of rows of the matrix A. It must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. It must be at 
 *        least zero.
 * alpha  single precision complex scalar multiplier applied to x * transpose(y)
 * x      single precision complex array of length at least (1 + (m - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must not
 *        be zero.
 * y      single precision complex array of length at least (1 + (n - 1) * abs(incy))
 * incy   specifies the storage spacing between elements of y. incy must not 
 *        be zero.
 * A      single precision complex array of dimensions (lda, n).
 * lda    leading dimension of two-dimensional array used to store matrix A
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * transpose(y) + A
 *
 * Reference: http://www.netlib.org/blas/cgeru.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m <0, n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI cublasCgeru (int m, int n, cuComplex alpha, const cuComplex *x,
                            int incx, const cuComplex *y, int incy,
                            cuComplex *A, int lda);
/*
 * cublasCgerc (int m, int n, cuComplex alpha, const cuComplex *x, int incx, 
 *             const cuComplex *y, int incy, cuComplex *A, int lda)
 *
 * performs the symmetric rank 1 operation
 *
 *    A = alpha * x * conjugate(transpose(y)) + A,
 *
 * where alpha is a single precision complex scalar, x is an m element single 
 * precision complex vector, y is an n element single precision complex vector, and A 
 * is an m by n matrix consisting of single precision complex elements. Matrix A
 * is stored in column major format, and lda is the leading dimension of
 * the two-dimensional array used to store A.
 * 
 * Input
 * -----
 * m      specifies the number of rows of the matrix A. It must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. It must be at 
 *        least zero.
 * alpha  single precision complex scalar multiplier applied to x * transpose(y)
 * x      single precision complex array of length at least (1 + (m - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must not
 *        be zero.
 * y      single precision complex array of length at least (1 + (n - 1) * abs(incy))
 * incy   specifies the storage spacing between elements of y. incy must not 
 *        be zero.
 * A      single precision complex array of dimensions (lda, n).
 * lda    leading dimension of two-dimensional array used to store matrix A
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * conjugate(transpose(y)) + A
 *
 * Reference: http://www.netlib.org/blas/cgerc.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m <0, n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI cublasCgerc (int m, int n, cuComplex alpha, const cuComplex *x,
                            int incx, const cuComplex *y, int incy,
                            cuComplex *A, int lda);
/*
 * void 
 * cublasCher (char uplo, int n, float alpha, const cuComplex *x, int incx, 
 *             cuComplex *A, int lda)
 *
 * performs the hermitian rank 1 operation
 *
 *    A = alpha * x * conjugate(transpose(x)) + A,
 *
 * where alpha is a single precision real scalar, x is an n element single 
 * precision complex vector and A is an n x n hermitian matrix consisting of 
 * single precision complex elements. Matrix A is stored in column major format,
 * and lda is the leading dimension of the two-dimensional array 
 * containing A.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or 
 *        the lower triangular part of array A. If uplo = 'U' or 'u',
 *        then only the upper triangular part of A may be referenced.
 *        If uplo = 'L' or 'l', then only the lower triangular part of
 *        A may be referenced.
 * n      specifies the number of rows and columns of the matrix A. It
 *        must be at least 0.
 * alpha  single precision real scalar multiplier applied to 
 *        x * conjugate(transpose(x))
 * x      single precision complex array of length at least (1 + (n - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must 
 *        not be zero.
 * A      single precision complex array of dimensions (lda, n). If uplo = 'U' or 
 *        'u', then A must contain the upper triangular part of a hermitian 
 *        matrix, and the strictly lower triangular part is not referenced. 
 *        If uplo = 'L' or 'l', then A contains the lower triangular part 
 *        of a hermitian matrix, and the strictly upper triangular part is 
 *        not referenced. The imaginary parts of the diagonal elements need
 *        not be set, they are assumed to be zero, and on exit they
 *        are set to zero. 
 * lda    leading dimension of the two-dimensional array containing A. lda
 *        must be at least max(1, n).
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * conjugate(transpose(x)) + A
 *
 * Reference: http://www.netlib.org/blas/cher.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or incx == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI cublasCher (char uplo, int n, float alpha, 
                           const cuComplex *x, int incx, cuComplex *A, 
                           int lda);
/*
 * void 
 * cublasChpr (char uplo, int n, float alpha, const cuComplex *x, int incx, 
 *             cuComplex *AP)
 *
 * performs the hermitian rank 1 operation
 * 
 *    A = alpha * x * conjugate(transpose(x)) + A,
 * 
 * where alpha is a single precision real scalar and x is an n element single 
 * precision complex vector. A is a hermitian n x n matrix consisting of single 
 * precision complex elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array AP. If uplo == 'U' or 'u', then the upper 
 *        triangular part of A is supplied in AP. If uplo == 'L' or 'l', then 
 *        the lower triangular part of A is supplied in AP.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  single precision real scalar multiplier applied to x * conjugate(transpose(x)).
 * x      single precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * AP     single precision complex array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *        The imaginary parts of the diagonal elements need not be set, they
 *        are assumed to be zero, and on exit they are set to zero. 
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * conjugate(transpose(x)) + A
 *
 * Reference: http://www.netlib.org/blas/chpr.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or incx == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                           
void CUBLASAPI cublasChpr (char uplo, int n, float alpha,
                           const cuComplex *x, int incx, cuComplex *AP);
                           
/* 
 * void 
 * cublasChpr2 (char uplo, int n, cuComplex alpha, const cuComplex *x, int incx, 
 *              const cuComplex *y, int incy, cuComplex *AP)
 *
 * performs the hermitian rank 2 operation
 *
 *    A = alpha*x*conjugate(transpose(y)) + conjugate(alpha)*y*conjugate(transpose(x)) + A,
 *
 * where alpha is a single precision complex scalar, and x and y are n element single 
 * precision complex vectors. A is a hermitian n x n matrix consisting of single 
 * precision complex elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array A. If uplo == 'U' or 'u', then only the 
 *        upper triangular part of A may be referenced and the lower triangular
 *        part of A is inferred. If uplo == 'L' or 'l', then only the lower 
 *        triangular part of A may be referenced and the upper triangular part
 *        of A is inferred.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  single precision complex scalar multiplier applied to x * conjugate(transpose(y)) + 
 *        y * conjugate(transpose(x)).
 * x      single precision complex array of length at least (1 + (n - 1) * abs (incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * y      single precision complex array of length at least (1 + (n - 1) * abs (incy)).
 * incy   storage spacing between elements of y. incy must not be zero.
 * AP     single precision complex array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *        The imaginary parts of the diagonal elements need not be set, they
 *        are assumed to be zero, and on exit they are set to zero.  
 *
 * Output
 * ------
 * A      updated according to A = alpha*x*conjugate(transpose(y))
 *                               + conjugate(alpha)*y*conjugate(transpose(x))+A
 *
 * Reference: http://www.netlib.org/blas/chpr2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasChpr2 (char uplo, int n, cuComplex alpha,
                            const cuComplex *x, int incx, const cuComplex *y,
                            int incy, cuComplex *AP);                           

/*
 * void cublasCher2 (char uplo, int n, cuComplex alpha, const cuComplex *x, int incx, 
 *                   const cuComplex *y, int incy, cuComplex *A, int lda)
 *
 * performs the hermitian rank 2 operation
 *
 *    A = alpha*x*conjugate(transpose(y)) + conjugate(alpha)*y*conjugate(transpose(x)) + A,
 *
 * where alpha is a single precision complex scalar, x and y are n element single 
 * precision complex vector and A is an n by n hermitian matrix consisting of single 
 * precision complex elements.
 * 
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array A. If uplo == 'U' or 'u', then only the 
 *        upper triangular part of A may be referenced and the lower triangular
 *        part of A is inferred. If uplo == 'L' or 'l', then only the lower 
 *        triangular part of A may be referenced and the upper triangular part
 *        of A is inferred.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  single precision complex scalar multiplier applied to x * conjugate(transpose(y)) + 
 *        y * conjugate(transpose(x)).
 * x      single precision array of length at least (1 + (n - 1) * abs (incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * y      single precision array of length at least (1 + (n - 1) * abs (incy)).
 * incy   storage spacing between elements of y. incy must not be zero.
 * A      single precision complex array of dimensions (lda, n). If uplo == 'U' or 'u',
 *        then A must contains the upper triangular part of a hermitian matrix,
 *        and the strictly lower triangular parts is not referenced. If uplo ==
 *        'L' or 'l', then A contains the lower triangular part of a hermitian 
 *        matrix, and the strictly upper triangular part is not referenced.
 *        The imaginary parts of the diagonal elements need not be set, 
 *        they are assumed to be zero, and on exit they are set to zero. 
 *
 * lda    leading dimension of A. It must be at least max(1, n).
 *
 * Output
 * ------
 * A      updated according to A = alpha*x*conjugate(transpose(y))
 *                               + conjugate(alpha)*y*conjugate(transpose(x))+A
 *
 * Reference: http://www.netlib.org/blas/cher2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                         
void CUBLASAPI cublasCher2 (char uplo, int n, cuComplex alpha,
                            const cuComplex *x, int incx, const cuComplex *y,
                            int incy, cuComplex *A, int lda);
void CUBLASAPI cublasChpr2 (char uplo, int n, cuComplex alpha,
                            const cuComplex *x, int incx, const cuComplex *y,
                            int incy, cuComplex *AP);
                            
/* ---------------- CUBLAS single precision BLAS3 functions ---------------- */

/*
 * void 
 * cublasSgemm (char transa, char transb, int m, int n, int k, float alpha, 
 *              const float *A, int lda, const float *B, int ldb, float beta, 
 *              float *C, int ldc)
 *
 * computes the product of matrix A and matrix B, multiplies the result 
 * by a scalar alpha, and adds the sum to the product of matrix C and
 * scalar beta. sgemm() performs one of the matrix-matrix operations:
 *
 *     C = alpha * op(A) * op(B) + beta * C,
 *
 * where op(X) is one of
 *
 *     op(X) = X   or   op(X) = transpose(X)
 *
 * alpha and beta are single precision scalars, and A, B and C are 
 * matrices consisting of single precision elements, with op(A) an m x k 
 * matrix, op(B) a k x n matrix, and C an m x n matrix. Matrices A, B, 
 * and C are stored in column major format, and lda, ldb, and ldc are
 * the leading dimensions of the two-dimensional arrays containing A, 
 * B, and C.
 *
 * Input
 * -----
 * transa specifies op(A). If transa = 'n' or 'N', op(A) = A. If 
 *        transa = 't', 'T', 'c', or 'C', op(A) = transpose(A)
 * transb specifies op(B). If transb = 'n' or 'N', op(B) = B. If 
 *        transb = 't', 'T', 'c', or 'C', op(B) = transpose(B)
 * m      number of rows of matrix op(A) and rows of matrix C
 * n      number of columns of matrix op(B) and number of columns of C
 * k      number of columns of matrix op(A) and number of rows of op(B) 
 * alpha  single precision scalar multiplier applied to op(A)op(B)
 * A      single precision array of dimensions (lda, k) if transa = 
 *        'n' or 'N'), and of dimensions (lda, m) otherwise. When transa =
 *        'N' or 'n' then lda must be at least  max( 1, m ), otherwise lda
 *        must be at least max(1, k).
 * lda    leading dimension of two-dimensional array used to store matrix A
 * B      single precision array of dimensions  (ldb, n) if transb =
 *        'n' or 'N'), and of dimensions (ldb, k) otherwise. When transb =
 *        'N' or 'n' then ldb must be at least  max (1, k), otherwise ldb
 *        must be at least max (1, n).
 * ldb    leading dimension of two-dimensional array used to store matrix B
 * beta   single precision scalar multiplier applied to C. If 0, C does
 *        not have to be a valid input
 * C      single precision array of dimensions (ldc, n). ldc must be at 
 *        least max (1, m).
 * ldc    leading dimension of two-dimensional array used to store matrix C
 *
 * Output
 * ------
 * C      updated based on C = alpha * op(A)*op(B) + beta * C
 *
 * Reference: http://www.netlib.org/blas/sgemm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if any of m, n, or k are < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSgemm (char transa, char transb, int m, int n, int k, 
                            float alpha, const float *A, int lda, 
                            const float *B, int ldb, float beta, float *C, 
                            int ldc);

/*
 * void 
 * cublasSsymm (char side, char uplo, int m, int n, float alpha, 
 *              const float *A, int lda, const float *B, int ldb, 
 *              float beta, float *C, int ldc);
 *
 * performs one of the matrix-matrix operations
 * 
 *   C = alpha * A * B + beta * C, or 
 *   C = alpha * B * A + beta * C,
 *
 * where alpha and beta are single precision scalars, A is a symmetric matrix
 * consisting of single precision elements and stored in either lower or upper 
 * storage mode, and B and C are m x n matrices consisting of single precision
 * elements.
 *
 * Input
 * -----
 * side   specifies whether the symmetric matrix A appears on the left side 
 *        hand side or right hand side of matrix B, as follows. If side == 'L' 
 *        or 'l', then C = alpha * A * B + beta * C. If side = 'R' or 'r', 
 *        then C = alpha * B * A + beta * C.
 * uplo   specifies whether the symmetric matrix A is stored in upper or lower 
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * m      specifies the number of rows of the matrix C, and the number of rows
 *        of matrix B. It also specifies the dimensions of symmetric matrix A 
 *        when side == 'L' or 'l'. m must be at least zero.
 * n      specifies the number of columns of the matrix C, and the number of 
 *        columns of matrix B. It also specifies the dimensions of symmetric 
 *        matrix A when side == 'R' or 'r'. n must be at least zero.
 * alpha  single precision scalar multiplier applied to A * B, or B * A
 * A      single precision array of dimensions (lda, ka), where ka is m when 
 *        side == 'L' or 'l' and is n otherwise. If side == 'L' or 'l' the 
 *        leading m x m part of array A must contain the symmetric matrix, 
 *        such that when uplo == 'U' or 'u', the leading m x m part stores the 
 *        upper triangular part of the symmetric matrix, and the strictly lower
 *        triangular part of A is not referenced, and when uplo == 'U' or 'u', 
 *        the leading m x m part stores the lower triangular part of the 
 *        symmetric matrix and the strictly upper triangular part is not 
 *        referenced. If side == 'R' or 'r' the leading n x n part of array A 
 *        must contain the symmetric matrix, such that when uplo == 'U' or 'u',
 *        the leading n x n part stores the upper triangular part of the 
 *        symmetric matrix and the strictly lower triangular part of A is not 
 *        referenced, and when uplo == 'U' or 'u', the leading n x n part 
 *        stores the lower triangular part of the symmetric matrix and the 
 *        strictly upper triangular part is not referenced.
 * lda    leading dimension of A. When side == 'L' or 'l', it must be at least 
 *        max(1, m) and at least max(1, n) otherwise.
 * B      single precision array of dimensions (ldb, n). On entry, the leading
 *        m x n part of the array contains the matrix B.
 * ldb    leading dimension of B. It must be at least max (1, m).
 * beta   single precision scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input
 * C      single precision array of dimensions (ldc, n)
 * ldc    leading dimension of C. Must be at least max(1, m)
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * B + beta * C, or C = alpha * 
 *        B * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/ssymm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSsymm (char side, char uplo, int m, int n, float alpha, 
                            const float *A, int lda, const float *B, int ldb,
                            float beta, float *C, int ldc);

/*
 * void 
 * cublasSsyrk (char uplo, char trans, int n, int k, float alpha, 
 *              const float *A, int lda, float beta, float *C, int ldc)
 *
 * performs one of the symmetric rank k operations
 * 
 *   C = alpha * A * transpose(A) + beta * C, or 
 *   C = alpha * transpose(A) * A + beta * C.
 *
 * Alpha and beta are single precision scalars. C is an n x n symmetric matrix 
 * consisting of single precision elements and stored in either lower or 
 * upper storage mode. A is a matrix consisting of single precision elements
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the symmetric matrix C is stored in upper or lower 
 *        storage mode as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', C = 
 *        alpha * transpose(A) + beta * C. If trans == 'T', 't', 'C', or 'c', 
 *        C = transpose(A) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  single precision scalar multiplier applied to A * transpose(A) or 
 *        transpose(A) * A.
 * A      single precision array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contains the 
 *        matrix A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at
 *        least max(1, n). Otherwise lda must be at least max(1, k).
 * beta   single precision scalar multiplier applied to C. If beta izs zero, C
 *        does not have to be a valid input
 * C      single precision array of dimensions (ldc, n). If uplo == 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the symmetric matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo == 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the symmetric matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 * ldc    leading dimension of C. It must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * transpose(A) + beta * C, or C = 
 *        alpha * transpose(A) * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/ssyrk.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSsyrk (char uplo, char trans, int n, int k, float alpha, 
                            const float *A, int lda, float beta, float *C, 
                            int ldc);

/*
 * void 
 * cublasSsyr2k (char uplo, char trans, int n, int k, float alpha, 
 *               const float *A, int lda, const float *B, int ldb, 
 *               float beta, float *C, int ldc)
 *
 * performs one of the symmetric rank 2k operations
 * 
 *    C = alpha * A * transpose(B) + alpha * B * transpose(A) + beta * C, or 
 *    C = alpha * transpose(A) * B + alpha * transpose(B) * A + beta * C.
 *
 * Alpha and beta are single precision scalars. C is an n x n symmetric matrix
 * consisting of single precision elements and stored in either lower or upper 
 * storage mode. A and B are matrices consisting of single precision elements 
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the symmetric matrix C is stored in upper or lower
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be references, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', 
 *        C = alpha * A * transpose(B) + alpha * B * transpose(A) + beta * C, 
 *        If trans == 'T', 't', 'C', or 'c', C = alpha * transpose(A) * B + 
 *        alpha * transpose(B) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  single precision scalar multiplier.
 * A      single precision array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at 
 *        least max(1, n). Otherwise lda must be at least max(1,k).
 * B      single precision array of dimensions (lda, kb), where kb is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array B must contain the matrix B, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        B.
 * ldb    leading dimension of N. When trans == 'N' or 'n' then ldb must be at
 *        least max(1, n). Otherwise ldb must be at least max(1, k).
 * beta   single precision scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input.
 * C      single precision array of dimensions (ldc, n). If uplo == 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the symmetric matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo == 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the symmetric matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 * ldc    leading dimension of C. Must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to alpha*A*transpose(B) + alpha*B*transpose(A) + 
 *        beta*C or alpha*transpose(A)*B + alpha*transpose(B)*A + beta*C
 *
 * Reference:   http://www.netlib.org/blas/ssyr2k.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasSsyr2k (char uplo, char trans, int n, int k, float alpha, 
                             const float *A, int lda, const float *B, int ldb, 
                             float beta, float *C, int ldc);

/*
 * void 
 * cublasStrmm (char side, char uplo, char transa, char diag, int m, int n, 
 *              float alpha, const float *A, int lda, const float *B, int ldb)
 *
 * performs one of the matrix-matrix operations
 *
 *   B = alpha * op(A) * B,  or  B = alpha * B * op(A)
 *
 * where alpha is a single-precision scalar, B is an m x n matrix composed
 * of single precision elements, and A is a unit or non-unit, upper or lower, 
 * triangular matrix composed of single precision elements. op(A) is one of
 *
 *   op(A) = A  or  op(A) = transpose(A)
 *
 * Matrices A and B are stored in column major format, and lda and ldb are 
 * the leading dimensions of the two-dimensonials arrays that contain A and 
 * B, respectively.
 *
 * Input
 * -----
 * side   specifies whether op(A) multiplies B from the left or right.
 *        If side = 'L' or 'l', then B = alpha * op(A) * B. If side =
 *        'R' or 'r', then B = alpha * B * op(A).
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix. If uplo = 'U' or 'u', A is an upper triangular matrix.
 *        If uplo = 'L' or 'l', A is a lower triangular matrix.
 * transa specifies the form of op(A) to be used in the matrix 
 *        multiplication. If transa = 'N' or 'n', then op(A) = A. If
 *        transa = 'T', 't', 'C', or 'c', then op(A) = transpose(A).
 * diag   specifies whether or not A is unit triangular. If diag = 'U'
 *        or 'u', A is assumed to be unit triangular. If diag = 'N' or
 *        'n', A is not assumed to be unit triangular.
 * m      the number of rows of matrix B. m must be at least zero.
 * n      the number of columns of matrix B. n must be at least zero.
 * alpha  single precision scalar multiplier applied to op(A)*B, or
 *        B*op(A), respectively. If alpha is zero no accesses are made
 *        to matrix A, and no read accesses are made to matrix B.
 * A      single precision array of dimensions (lda, k). k = m if side =
 *        'L' or 'l', k = n if side = 'R' or 'r'. If uplo = 'U' or 'u'
 *        the leading k x k upper triangular part of the array A must
 *        contain the upper triangular matrix, and the strictly lower
 *        triangular part of A is not referenced. If uplo = 'L' or 'l'
 *        the leading k x k lower triangular part of the array A must
 *        contain the lower triangular matrix, and the strictly upper
 *        triangular part of A is not referenced. When diag = 'U' or 'u'
 *        the diagonal elements of A are no referenced and are assumed
 *        to be unity.
 * lda    leading dimension of A. When side = 'L' or 'l', it must be at
 *        least max(1,m) and at least max(1,n) otherwise
 * B      single precision array of dimensions (ldb, n). On entry, the 
 *        leading m x n part of the array contains the matrix B. It is
 *        overwritten with the transformed matrix on exit.
 * ldb    leading dimension of B. It must be at least max (1, m).
 *
 * Output
 * ------
 * B      updated according to B = alpha * op(A) * B  or B = alpha * B * op(A)
 *
 * Reference: http://www.netlib.org/blas/strmm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasStrmm (char side, char uplo, char transa, char diag,
                            int m, int n, float alpha, const float *A, int lda,
                            float *B, int ldb);

/*
 * void 
 * cublasStrsm (char side, char uplo, char transa, char diag, int m, int n, 
 *              float alpha, const float *A, int lda, float *B, int ldb)
 *
 * solves one of the matrix equations
 *
 *    op(A) * X = alpha * B,   or   X * op(A) = alpha * B,
 *
 * where alpha is a single precision scalar, and X and B are m x n matrices 
 * that are composed of single precision elements. A is a unit or non-unit,
 * upper or lower triangular matrix, and op(A) is one of 
 *
 *    op(A) = A  or  op(A) = transpose(A)
 *
 * The result matrix X overwrites input matrix B; that is, on exit the result 
 * is stored in B. Matrices A and B are stored in column major format, and
 * lda and ldb are the leading dimensions of the two-dimensonials arrays that
 * contain A and B, respectively.
 *
 * Input
 * -----
 * side   specifies whether op(A) appears on the left or right of X as
 *        follows: side = 'L' or 'l' indicates solve op(A) * X = alpha * B.
 *        side = 'R' or 'r' indicates solve X * op(A) = alpha * B.
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix as follows: uplo = 'U' or 'u' indicates A is an upper
 *        triangular matrix. uplo = 'L' or 'l' indicates A is a lower
 *        triangular matrix.
 * transa specifies the form of op(A) to be used in matrix multiplication
 *        as follows: If transa = 'N' or 'N', then op(A) = A. If transa =
 *        'T', 't', 'C', or 'c', then op(A) = transpose(A).
 * diag   specifies whether or not A is a unit triangular matrix like so:
 *        if diag = 'U' or 'u', A is assumed to be unit triangular. If 
 *        diag = 'N' or 'n', then A is not assumed to be unit triangular.
 * m      specifies the number of rows of B. m must be at least zero.
 * n      specifies the number of columns of B. n must be at least zero.
 * alpha  is a single precision scalar to be multiplied with B. When alpha is 
 *        zero, then A is not referenced and B need not be set before entry.
 * A      is a single precision array of dimensions (lda, k), where k is
 *        m when side = 'L' or 'l', and is n when side = 'R' or 'r'. If
 *        uplo = 'U' or 'u', the leading k x k upper triangular part of
 *        the array A must contain the upper triangular matrix and the
 *        strictly lower triangular matrix of A is not referenced. When
 *        uplo = 'L' or 'l', the leading k x k lower triangular part of
 *        the array A must contain the lower triangular matrix and the 
 *        strictly upper triangular part of A is not referenced. Note that
 *        when diag = 'U' or 'u', the diagonal elements of A are not
 *        referenced, and are assumed to be unity.
 * lda    is the leading dimension of the two dimensional array containing A.
 *        When side = 'L' or 'l' then lda must be at least max(1, m), when 
 *        side = 'R' or 'r' then lda must be at least max(1, n).
 * B      is a single precision array of dimensions (ldb, n). ldb must be
 *        at least max (1,m). The leading m x n part of the array B must 
 *        contain the right-hand side matrix B. On exit B is overwritten 
 *        by the solution matrix X.
 * ldb    is the leading dimension of the two dimensional array containing B.
 *        ldb must be at least max(1, m).
 *
 * Output
 * ------
 * B      contains the solution matrix X satisfying op(A) * X = alpha * B, 
 *        or X * op(A) = alpha * B
 *
 * Reference: http://www.netlib.org/blas/strsm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasStrsm (char side, char uplo, char transa, char diag,
                            int m, int n, float alpha, const float *A, int lda,
                            float *B, int ldb);

/* ----------------- CUBLAS single complex BLAS3 functions ----------------- */

/*
 * void cublasCgemm (char transa, char transb, int m, int n, int k, 
 *                   cuComplex alpha, const cuComplex *A, int lda, 
 *                   const cuComplex *B, int ldb, cuComplex beta, 
 *                   cuComplex *C, int ldc)
 *
 * performs one of the matrix-matrix operations
 *
 *    C = alpha * op(A) * op(B) + beta*C,
 *
 * where op(X) is one of
 *
 *    op(X) = X   or   op(X) = transpose  or  op(X) = conjg(transpose(X))
 *
 * alpha and beta are single-complex scalars, and A, B and C are matrices
 * consisting of single-complex elements, with op(A) an m x k matrix, op(B)
 * a k x n matrix and C an m x n matrix.
 *
 * Input
 * -----
 * transa specifies op(A). If transa == 'N' or 'n', op(A) = A. If transa == 
 *        'T' or 't', op(A) = transpose(A). If transa == 'C' or 'c', op(A) = 
 *        conjg(transpose(A)).
 * transb specifies op(B). If transa == 'N' or 'n', op(B) = B. If transb == 
 *        'T' or 't', op(B) = transpose(B). If transb == 'C' or 'c', op(B) = 
 *        conjg(transpose(B)).
 * m      number of rows of matrix op(A) and rows of matrix C. It must be at
 *        least zero.
 * n      number of columns of matrix op(B) and number of columns of C. It 
 *        must be at least zero.
 * k      number of columns of matrix op(A) and number of rows of op(B). It 
 *        must be at least zero.
 * alpha  single-complex scalar multiplier applied to op(A)op(B)
 * A      single-complex array of dimensions (lda, k) if transa ==  'N' or 
 *        'n'), and of dimensions (lda, m) otherwise.
 * lda    leading dimension of A. When transa == 'N' or 'n', it must be at 
 *        least max(1, m) and at least max(1, k) otherwise.
 * B      single-complex array of dimensions (ldb, n) if transb == 'N' or 'n', 
 *        and of dimensions (ldb, k) otherwise
 * ldb    leading dimension of B. When transb == 'N' or 'n', it must be at 
 *        least max(1, k) and at least max(1, n) otherwise.
 * beta   single-complex scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input.
 * C      single precision array of dimensions (ldc, n)
 * ldc    leading dimension of C. Must be at least max(1, m).
 *
 * Output
 * ------
 * C      updated according to C = alpha*op(A)*op(B) + beta*C
 *
 * Reference: http://www.netlib.org/blas/cgemm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if any of m, n, or k are < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCgemm (char transa, char transb, int m, int n, int k, 
                            cuComplex alpha, const cuComplex *A, int lda,
                            const cuComplex *B, int ldb, cuComplex beta,
                            cuComplex *C, int ldc);
/*
 * void 
 * cublasCsymm (char side, char uplo, int m, int n, cuComplex alpha, 
 *              const cuComplex *A, int lda, const cuComplex *B, int ldb, 
 *              cuComplex beta, cuComplex *C, int ldc);
 *
 * performs one of the matrix-matrix operations
 * 
 *   C = alpha * A * B + beta * C, or 
 *   C = alpha * B * A + beta * C,
 *
 * where alpha and beta are single precision complex scalars, A is a symmetric matrix
 * consisting of single precision complex elements and stored in either lower or upper 
 * storage mode, and B and C are m x n matrices consisting of single precision
 * complex elements.
 *
 * Input
 * -----
 * side   specifies whether the symmetric matrix A appears on the left side 
 *        hand side or right hand side of matrix B, as follows. If side == 'L' 
 *        or 'l', then C = alpha * A * B + beta * C. If side = 'R' or 'r', 
 *        then C = alpha * B * A + beta * C.
 * uplo   specifies whether the symmetric matrix A is stored in upper or lower 
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * m      specifies the number of rows of the matrix C, and the number of rows
 *        of matrix B. It also specifies the dimensions of symmetric matrix A 
 *        when side == 'L' or 'l'. m must be at least zero.
 * n      specifies the number of columns of the matrix C, and the number of 
 *        columns of matrix B. It also specifies the dimensions of symmetric 
 *        matrix A when side == 'R' or 'r'. n must be at least zero.
 * alpha  single precision scalar multiplier applied to A * B, or B * A
 * A      single precision array of dimensions (lda, ka), where ka is m when 
 *        side == 'L' or 'l' and is n otherwise. If side == 'L' or 'l' the 
 *        leading m x m part of array A must contain the symmetric matrix, 
 *        such that when uplo == 'U' or 'u', the leading m x m part stores the 
 *        upper triangular part of the symmetric matrix, and the strictly lower
 *        triangular part of A is not referenced, and when uplo == 'U' or 'u', 
 *        the leading m x m part stores the lower triangular part of the 
 *        symmetric matrix and the strictly upper triangular part is not 
 *        referenced. If side == 'R' or 'r' the leading n x n part of array A 
 *        must contain the symmetric matrix, such that when uplo == 'U' or 'u',
 *        the leading n x n part stores the upper triangular part of the 
 *        symmetric matrix and the strictly lower triangular part of A is not 
 *        referenced, and when uplo == 'U' or 'u', the leading n x n part 
 *        stores the lower triangular part of the symmetric matrix and the 
 *        strictly upper triangular part is not referenced.
 * lda    leading dimension of A. When side == 'L' or 'l', it must be at least 
 *        max(1, m) and at least max(1, n) otherwise.
 * B      single precision array of dimensions (ldb, n). On entry, the leading
 *        m x n part of the array contains the matrix B.
 * ldb    leading dimension of B. It must be at least max (1, m).
 * beta   single precision scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input
 * C      single precision array of dimensions (ldc, n)
 * ldc    leading dimension of C. Must be at least max(1, m)
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * B + beta * C, or C = alpha * 
 *        B * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/csymm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCsymm (char side, char uplo, int m, int n,
                            cuComplex alpha, const cuComplex *A, int lda,
                            const cuComplex *B, int ldb, cuComplex beta,
                            cuComplex *C, int ldc);
/*
 * void 
 * cublasChemm (char side, char uplo, int m, int n, cuComplex alpha, 
 *              const cuComplex *A, int lda, const cuComplex *B, int ldb, 
 *              cuComplex beta, cuComplex *C, int ldc);
 *
 * performs one of the matrix-matrix operations
 * 
 *   C = alpha * A * B + beta * C, or 
 *   C = alpha * B * A + beta * C,
 *
 * where alpha and beta are single precision complex scalars, A is a hermitian matrix
 * consisting of single precision complex elements and stored in either lower or upper 
 * storage mode, and B and C are m x n matrices consisting of single precision
 * complex elements.
 *
 * Input
 * -----
 * side   specifies whether the hermitian matrix A appears on the left side 
 *        hand side or right hand side of matrix B, as follows. If side == 'L' 
 *        or 'l', then C = alpha * A * B + beta * C. If side = 'R' or 'r', 
 *        then C = alpha * B * A + beta * C.
 * uplo   specifies whether the hermitian matrix A is stored in upper or lower 
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the hermitian matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the hermitian matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * m      specifies the number of rows of the matrix C, and the number of rows
 *        of matrix B. It also specifies the dimensions of hermitian matrix A 
 *        when side == 'L' or 'l'. m must be at least zero.
 * n      specifies the number of columns of the matrix C, and the number of 
 *        columns of matrix B. It also specifies the dimensions of hermitian 
 *        matrix A when side == 'R' or 'r'. n must be at least zero.
 * alpha  single precision complex scalar multiplier applied to A * B, or B * A
 * A      single precision complex array of dimensions (lda, ka), where ka is m when 
 *        side == 'L' or 'l' and is n otherwise. If side == 'L' or 'l' the 
 *        leading m x m part of array A must contain the hermitian matrix, 
 *        such that when uplo == 'U' or 'u', the leading m x m part stores the 
 *        upper triangular part of the hermitian matrix, and the strictly lower
 *        triangular part of A is not referenced, and when uplo == 'U' or 'u', 
 *        the leading m x m part stores the lower triangular part of the 
 *        hermitian matrix and the strictly upper triangular part is not 
 *        referenced. If side == 'R' or 'r' the leading n x n part of array A 
 *        must contain the hermitian matrix, such that when uplo == 'U' or 'u',
 *        the leading n x n part stores the upper triangular part of the 
 *        hermitian matrix and the strictly lower triangular part of A is not 
 *        referenced, and when uplo == 'U' or 'u', the leading n x n part 
 *        stores the lower triangular part of the hermitian matrix and the 
 *        strictly upper triangular part is not referenced. The imaginary parts
 *        of the diagonal elements need not be set, they are assumed to be zero.
 * lda    leading dimension of A. When side == 'L' or 'l', it must be at least 
 *        max(1, m) and at least max(1, n) otherwise.
 * B      single precision complex array of dimensions (ldb, n). On entry, the leading
 *        m x n part of the array contains the matrix B.
 * ldb    leading dimension of B. It must be at least max (1, m).
 * beta   single precision complex scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input
 * C      single precision complex array of dimensions (ldc, n)
 * ldc    leading dimension of C. Must be at least max(1, m)
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * B + beta * C, or C = alpha * 
 *        B * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/chemm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI cublasChemm (char side, char uplo, int m, int n,
                            cuComplex alpha, const cuComplex *A, int lda,
                            const cuComplex *B, int ldb, cuComplex beta,
                            cuComplex *C, int ldc);
/*
 * void 
 * cublasCsyrk (char uplo, char trans, int n, int k, cuComplex alpha, 
 *              const cuComplex *A, int lda, cuComplex beta, cuComplex *C, int ldc)
 *
 * performs one of the symmetric rank k operations
 * 
 *   C = alpha * A * transpose(A) + beta * C, or 
 *   C = alpha * transpose(A) * A + beta * C.
 *
 * Alpha and beta are single precision complex scalars. C is an n x n symmetric matrix 
 * consisting of single precision complex elements and stored in either lower or 
 * upper storage mode. A is a matrix consisting of single precision complex elements
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the symmetric matrix C is stored in upper or lower 
 *        storage mode as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', C = 
 *        alpha * transpose(A) + beta * C. If trans == 'T', 't', 'C', or 'c', 
 *        C = transpose(A) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  single precision complex scalar multiplier applied to A * transpose(A) or 
 *        transpose(A) * A.
 * A      single precision complex array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contains the 
 *        matrix A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at
 *        least max(1, n). Otherwise lda must be at least max(1, k).
 * beta   single precision complex scalar multiplier applied to C. If beta izs zero, C
 *        does not have to be a valid input
 * C      single precision complex array of dimensions (ldc, n). If uplo = 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the symmetric matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo = 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the symmetric matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 * ldc    leading dimension of C. It must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * transpose(A) + beta * C, or C = 
 *        alpha * transpose(A) * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/csyrk.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            

void CUBLASAPI cublasCsyrk (char uplo, char trans, int n, int k,
                            cuComplex alpha, const cuComplex *A, int lda,
                            cuComplex beta, cuComplex *C, int ldc);
/*
 * void 
 * cublasCherk (char uplo, char trans, int n, int k, float alpha, 
 *              const cuComplex *A, int lda, float beta, cuComplex *C, int ldc)
 *
 * performs one of the hermitian rank k operations
 * 
 *   C = alpha * A * conjugate(transpose(A)) + beta * C, or 
 *   C = alpha * conjugate(transpose(A)) * A + beta * C.
 *
 * Alpha and beta are single precision real scalars. C is an n x n hermitian matrix 
 * consisting of single precision complex elements and stored in either lower or 
 * upper storage mode. A is a matrix consisting of single precision complex elements
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the hermitian matrix C is stored in upper or lower 
 *        storage mode as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the hermitian matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the hermitian matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', C = 
 *        alpha * A * conjugate(transpose(A)) + beta * C. If trans == 'T', 't', 'C', or 'c', 
 *        C = alpha * conjugate(transpose(A)) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of columns of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  single precision scalar multiplier applied to A * conjugate(transpose(A)) or 
 *        conjugate(transpose(A)) * A.
 * A      single precision complex array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contains the 
 *        matrix A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at
 *        least max(1, n). Otherwise lda must be at least max(1, k).
 * beta   single precision scalar multiplier applied to C. If beta is zero, C
 *        does not have to be a valid input.
 * C      single precision complex array of dimensions (ldc, n). If uplo = 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the hermitian matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo = 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the hermitian matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 *        The imaginary parts of the diagonal elements need
 *        not be set,  they are assumed to be zero,  and on exit they
 *        are set to zero.
 * ldc    leading dimension of C. It must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * conjugate(transpose(A)) + beta * C, or C = 
 *        alpha * conjugate(transpose(A)) * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/cherk.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                       
void CUBLASAPI cublasCherk (char uplo, char trans, int n, int k,
                            float alpha, const cuComplex *A, int lda,
                            float beta, cuComplex *C, int ldc);
                            
/*
 * void 
 * cublasCsyr2k (char uplo, char trans, int n, int k, cuComplex alpha, 
 *               const cuComplex *A, int lda, const cuComplex *B, int ldb, 
 *               cuComplex beta, cuComplex *C, int ldc)
 *
 * performs one of the symmetric rank 2k operations
 * 
 *    C = alpha * A * transpose(B) + alpha * B * transpose(A) + beta * C, or 
 *    C = alpha * transpose(A) * B + alpha * transpose(B) * A + beta * C.
 *
 * Alpha and beta are single precision complex scalars. C is an n x n symmetric matrix
 * consisting of single precision complex elements and stored in either lower or upper 
 * storage mode. A and B are matrices consisting of single precision complex elements 
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the symmetric matrix C is stored in upper or lower
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be references, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', 
 *        C = alpha * A * transpose(B) + alpha * B * transpose(A) + beta * C, 
 *        If trans == 'T', 't', 'C', or 'c', C = alpha * transpose(A) * B + 
 *        alpha * transpose(B) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  single precision complex scalar multiplier.
 * A      single precision complex array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at 
 *        least max(1, n). Otherwise lda must be at least max(1,k).
 * B      single precision complex array of dimensions (lda, kb), where kb is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array B must contain the matrix B, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        B.
 * ldb    leading dimension of N. When trans == 'N' or 'n' then ldb must be at
 *        least max(1, n). Otherwise ldb must be at least max(1, k).
 * beta   single precision complex scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input.
 * C      single precision complex array of dimensions (ldc, n). If uplo == 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the symmetric matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo == 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the symmetric matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 * ldc    leading dimension of C. Must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to alpha*A*transpose(B) + alpha*B*transpose(A) + 
 *        beta*C or alpha*transpose(A)*B + alpha*transpose(B)*A + beta*C
 *
 * Reference:   http://www.netlib.org/blas/csyr2k.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                            
void CUBLASAPI cublasCsyr2k (char uplo, char trans, int n, int k,
                             cuComplex alpha, const cuComplex *A, int lda,
                             const cuComplex *B, int ldb, cuComplex beta,
                             cuComplex *C, int ldc);
                             
/*
 * void 
 * cublasCher2k (char uplo, char trans, int n, int k, cuComplex alpha, 
 *               const cuComplex *A, int lda, const cuComplex *B, int ldb, 
 *               float beta, cuComplex *C, int ldc)
 *
 * performs one of the hermitian rank 2k operations
 * 
 *    C =   alpha * A * conjugate(transpose(B)) 
 *        + conjugate(alpha) * B * conjugate(transpose(A))  
 *        + beta * C , 
 *    or 
 *    C =  alpha * conjugate(transpose(A)) * B 
 *       + conjugate(alpha) * conjugate(transpose(B)) * A 
 *       + beta * C.
 *
 * Alpha is single precision complex scalar whereas Beta is a single preocision real scalar. 
 * C is an n x n hermitian matrix consisting of single precision complex elements 
 * and stored in either lower or upper storage mode. A and B are matrices consisting
 * of single precision complex elements with dimension of n x k in the first case,
 * and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the hermitian matrix C is stored in upper or lower
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the hermitian matrix is to be referenced, and the
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the hermitian matrix is to be references, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', 
 *        C =   alpha * A * conjugate(transpose(B)) 
 *            + conjugate(alpha) * B * conjugate(transpose(A))  
 *            + beta * C .
 *        If trans == 'T', 't', 'C', or 'c',
 *        C =  alpha * conjugate(transpose(A)) * B 
 *          + conjugate(alpha) * conjugate(transpose(B)) * A 
 *          + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  single precision complex scalar multiplier.
 * A      single precision complex array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at 
 *        least max(1, n). Otherwise lda must be at least max(1,k).
 * B      single precision complex array of dimensions (lda, kb), where kb is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array B must contain the matrix B, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        B.
 * ldb    leading dimension of N. When trans == 'N' or 'n' then ldb must be at
 *        least max(1, n). Otherwise ldb must be at least max(1, k).
 * beta   single precision scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input.
 * C      single precision complex array of dimensions (ldc, n). If uplo == 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the hermitian matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo == 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the hermitian matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 *        The imaginary parts of the diagonal elements need
 *        not be set,  they are assumed to be zero,  and on exit they
 *        are set to zero.
 * ldc    leading dimension of C. Must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to alpha*A*conjugate(transpose(B)) + 
 *        + conjugate(alpha)*B*conjugate(transpose(A)) + beta*C or
 *        alpha*conjugate(transpose(A))*B + conjugate(alpha)*conjugate(transpose(B))*A
 *        + beta*C.
 *
 * Reference:   http://www.netlib.org/blas/cher2k.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                              
void CUBLASAPI cublasCher2k (char uplo, char trans, int n, int k,
                             cuComplex alpha, const cuComplex *A, int lda,
                             const cuComplex *B, int ldb, float beta,
                             cuComplex *C, int ldc);
/*
 * void 
 * cublasCtrmm (char side, char uplo, char transa, char diag, int m, int n, 
 *              cuComplex alpha, const cuComplex *A, int lda, const cuComplex *B, 
 *              int ldb)
 *
 * performs one of the matrix-matrix operations
 *
 *   B = alpha * op(A) * B,  or  B = alpha * B * op(A)
 *
 * where alpha is a single-precision complex scalar, B is an m x n matrix composed
 * of single precision complex elements, and A is a unit or non-unit, upper or lower, 
 * triangular matrix composed of single precision complex elements. op(A) is one of
 *
 *   op(A) = A  , op(A) = transpose(A) or op(A) = conjugate(transpose(A))
 *
 * Matrices A and B are stored in column major format, and lda and ldb are 
 * the leading dimensions of the two-dimensonials arrays that contain A and 
 * B, respectively.
 *
 * Input
 * -----
 * side   specifies whether op(A) multiplies B from the left or right.
 *        If side = 'L' or 'l', then B = alpha * op(A) * B. If side =
 *        'R' or 'r', then B = alpha * B * op(A).
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix. If uplo = 'U' or 'u', A is an upper triangular matrix.
 *        If uplo = 'L' or 'l', A is a lower triangular matrix.
 * transa specifies the form of op(A) to be used in the matrix 
 *        multiplication. If transa = 'N' or 'n', then op(A) = A. If
 *        transa = 'T' or 't', then op(A) = transpose(A).
 *        If transa = 'C' or 'c', then op(A) = conjugate(transpose(A)).
 * diag   specifies whether or not A is unit triangular. If diag = 'U'
 *        or 'u', A is assumed to be unit triangular. If diag = 'N' or
 *        'n', A is not assumed to be unit triangular.
 * m      the number of rows of matrix B. m must be at least zero.
 * n      the number of columns of matrix B. n must be at least zero.
 * alpha  single precision complex scalar multiplier applied to op(A)*B, or
 *        B*op(A), respectively. If alpha is zero no accesses are made
 *        to matrix A, and no read accesses are made to matrix B.
 * A      single precision complex array of dimensions (lda, k). k = m if side =
 *        'L' or 'l', k = n if side = 'R' or 'r'. If uplo = 'U' or 'u'
 *        the leading k x k upper triangular part of the array A must
 *        contain the upper triangular matrix, and the strictly lower
 *        triangular part of A is not referenced. If uplo = 'L' or 'l'
 *        the leading k x k lower triangular part of the array A must
 *        contain the lower triangular matrix, and the strictly upper
 *        triangular part of A is not referenced. When diag = 'U' or 'u'
 *        the diagonal elements of A are no referenced and are assumed
 *        to be unity.
 * lda    leading dimension of A. When side = 'L' or 'l', it must be at
 *        least max(1,m) and at least max(1,n) otherwise
 * B      single precision complex array of dimensions (ldb, n). On entry, the 
 *        leading m x n part of the array contains the matrix B. It is
 *        overwritten with the transformed matrix on exit.
 * ldb    leading dimension of B. It must be at least max (1, m).
 *
 * Output
 * ------
 * B      updated according to B = alpha * op(A) * B  or B = alpha * B * op(A)
 *
 * Reference: http://www.netlib.org/blas/ctrmm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                             
void CUBLASAPI cublasCtrmm (char side, char uplo, char transa, char diag,
                            int m, int n, cuComplex alpha, const cuComplex *A,
                            int lda, cuComplex *B, int ldb);
/*
 * void
 * cublasCtrsm (char side, char uplo, char transa, char diag, int m, int n,
 *              cuComplex alpha, const cuComplex *A, int lda,
 *              cuComplex *B, int ldb)
 *
 * solves one of the matrix equations
 *
 *    op(A) * X = alpha * B,   or   X * op(A) = alpha * B,
 *
 * where alpha is a single precision complex scalar, and X and B are m x n matrices
 * that are composed of single precision complex elements. A is a unit or non-unit,
 * upper or lower triangular matrix, and op(A) is one of
 *
 *    op(A) = A  or  op(A) = transpose(A)  or  op( A ) = conj( A' ).
 *
 * The result matrix X overwrites input matrix B; that is, on exit the result
 * is stored in B. Matrices A and B are stored in column major format, and
 * lda and ldb are the leading dimensions of the two-dimensonials arrays that
 * contain A and B, respectively.
 *
 * Input
 * -----
 * side   specifies whether op(A) appears on the left or right of X as
 *        follows: side = 'L' or 'l' indicates solve op(A) * X = alpha * B.
 *        side = 'R' or 'r' indicates solve X * op(A) = alpha * B.
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix as follows: uplo = 'U' or 'u' indicates A is an upper
 *        triangular matrix. uplo = 'L' or 'l' indicates A is a lower
 *        triangular matrix.
 * transa specifies the form of op(A) to be used in matrix multiplication
 *        as follows: If transa = 'N' or 'N', then op(A) = A. If transa =
 *        'T', 't', 'C', or 'c', then op(A) = transpose(A).
 * diag   specifies whether or not A is a unit triangular matrix like so:
 *        if diag = 'U' or 'u', A is assumed to be unit triangular. If
 *        diag = 'N' or 'n', then A is not assumed to be unit triangular.
 * m      specifies the number of rows of B. m must be at least zero.
 * n      specifies the number of columns of B. n must be at least zero.
 * alpha  is a single precision complex scalar to be multiplied with B. When alpha is
 *        zero, then A is not referenced and B need not be set before entry.
 * A      is a single precision complex array of dimensions (lda, k), where k is
 *        m when side = 'L' or 'l', and is n when side = 'R' or 'r'. If
 *        uplo = 'U' or 'u', the leading k x k upper triangular part of
 *        the array A must contain the upper triangular matrix and the
 *        strictly lower triangular matrix of A is not referenced. When
 *        uplo = 'L' or 'l', the leading k x k lower triangular part of
 *        the array A must contain the lower triangular matrix and the
 *        strictly upper triangular part of A is not referenced. Note that
 *        when diag = 'U' or 'u', the diagonal elements of A are not
 *        referenced, and are assumed to be unity.
 * lda    is the leading dimension of the two dimensional array containing A.
 *        When side = 'L' or 'l' then lda must be at least max(1, m), when
 *        side = 'R' or 'r' then lda must be at least max(1, n).
 * B      is a single precision complex array of dimensions (ldb, n). ldb must be
 *        at least max (1,m). The leading m x n part of the array B must
 *        contain the right-hand side matrix B. On exit B is overwritten
 *        by the solution matrix X.
 * ldb    is the leading dimension of the two dimensional array containing B.
 *        ldb must be at least max(1, m).
 *
 * Output
 * ------
 * B      contains the solution matrix X satisfying op(A) * X = alpha * B,
 *        or X * op(A) = alpha * B
 *
 * Reference: http://www.netlib.org/blas/ctrsm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasCtrsm (char side, char uplo, char transa, char diag,
                            int m, int n, cuComplex alpha, const cuComplex *A,
                            int lda, cuComplex *B, int ldb);

void CUBLASAPI cublasXerbla (const char *srName, int info);

/* ---------------- CUBLAS double-precision BLAS1 functions ---------------- */

/*
 * double 
 * cublasDasum (int n, const double *x, int incx)
 *
 * computes the sum of the absolute values of the elements of double 
 * precision vector x; that is, the result is the sum from i = 0 to n - 1 of 
 * abs(x[1 + i * incx]).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the double-precision sum of absolute values
 * (0 if n <= 0 or incx <= 0, or if an error occurs)
 *
 * Reference: http://www.netlib.org/blas/dasum.f
 *
 * Error status for this function can be retrieved via cublasGetError(). 
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
double CUBLASAPI cublasDasum (int n, const double *x, int incx);

/*
 * void
 * cublasDaxpy (int n, double alpha, const double *x, int incx, double *y, 
 *              int incy)
 *
 * multiplies double-precision vector x by double-precision scalar alpha 
 * and adds the result to double-precision vector y; that is, it overwrites 
 * double-precision y with double-precision alpha * x + y. For i = 0 to n-1,
 * it replaces y[ly + i * incy] with alpha * x[lx + i * incx] + y[ly + i*incy],
 * where lx = 1 if incx >= 0, else lx = 1 + (1 - n) * incx; ly is defined in a 
 * similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  double-precision scalar multiplier
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 * y      double-precision vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * y      double-precision result (unchanged if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/daxpy.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library was not initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDaxpy (int n, double alpha, const double *x, int incx, 
                            double *y, int incy);

/*
 * void 
 * cublasDcopy (int n, const double *x, int incx, double *y, int incy)
 *
 * copies the double-precision vector x to the double-precision vector y. For 
 * i = 0 to n-1, copies x[lx + i * incx] to y[ly + i * incy], where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and ly is defined in a similar 
 * way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 * y      double-precision vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * y      contains double precision vector x
 *
 * Reference: http://www.netlib.org/blas/dcopy.f
 *
 * Error status for this function can be retrieved via cublasGetError(). 
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDcopy (int n, const double *x, int incx, double *y, 
                            int incy);

/*
 * double 
 * cublasDdot (int n, const double *x, int incx, const double *y, int incy)
 *
 * computes the dot product of two double-precision vectors. It returns the 
 * dot product of the double precision vectors x and y if successful, and
 * 0.0f otherwise. It computes the sum for i = 0 to n - 1 of x[lx + i * 
 * incx] * y[ly + i * incy], where lx = 1 if incx >= 0, else lx = 1 + (1 - n)
 * *incx, and ly is defined in a similar way using incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 * y      double-precision vector with n elements
 * incy   storage spacing between elements of y
 *
 * Output
 * ------
 * returns double-precision dot product (zero if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/ddot.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has nor been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to execute on GPU
 */
double CUBLASAPI cublasDdot (int n, const double *x, int incx, const double *y,
                             int incy);

/*
 * double 
 * dnrm2 (int n, const double *x, int incx)
 *
 * computes the Euclidean norm of the double-precision n-vector x (with
 * storage increment incx). This code uses a multiphase model of 
 * accumulation to avoid intermediate underflow and overflow.
 *
 * Input
 * -----
 * n      number of elements in input vector
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns Euclidian norm (0 if n <= 0 or incx <= 0, or if an error occurs)
 *
 * Reference: http://www.netlib.org/blas/dnrm2.f
 * Reference: http://www.netlib.org/slatec/lin/dnrm2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
double CUBLASAPI cublasDnrm2 (int n, const double *x, int incx);

/*
 * void 
 * cublasDrot (int n, double *x, int incx, double *y, int incy, double sc, 
 *             double ss)
 *
 * multiplies a 2x2 matrix ( sc ss) with the 2xn matrix ( transpose(x) )
 *                         (-ss sc)                     ( transpose(y) )
 *
 * The elements of x are in x[lx + i * incx], i = 0 ... n - 1, where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and similarly for y using ly and 
 * incy.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 * y      double-precision vector with n elements
 * incy   storage spacing between elements of y
 * sc     element of rotation matrix
 * ss     element of rotation matrix
 *
 * Output
 * ------
 * x      rotated vector x (unchanged if n <= 0)
 * y      rotated vector y (unchanged if n <= 0)
 *
 * Reference  http://www.netlib.org/blas/drot.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDrot (int n, double *x, int incx, double *y, int incy, 
                           double sc, double ss);

/*
 * void 
 * cublasDrotg (double *host_sa, double *host_sb, double *host_sc, double *host_ss)
 *
 * constructs the Givens tranformation
 *
 *        ( sc  ss )
 *    G = (        ) ,  sc^2 + ss^2 = 1,
 *        (-ss  sc )
 *
 * which zeros the second entry of the 2-vector transpose(sa, sb).
 *
 * The quantity r = (+/-) sqrt (sa^2 + sb^2) overwrites sa in storage. The 
 * value of sb is overwritten by a value z which allows sc and ss to be 
 * recovered by the following algorithm:
 *
 *    if z=1          set sc = 0.0 and ss = 1.0
 *    if abs(z) < 1   set sc = sqrt(1-z^2) and ss = z
 *    if abs(z) > 1   set sc = 1/z and ss = sqrt(1-sc^2)
 *
 * The function drot (n, x, incx, y, incy, sc, ss) normally is called next
 * to apply the transformation to a 2 x n matrix.
 * Note that this function is provided for completeness and run exclusively 
 * on the Host.
 *
 * Input
 * -----
 * sa     double-precision scalar
 * sb     double-precision scalar
 *
 * Output
 * ------
 * sa     double-precision r
 * sb     double-precision z
 * sc     double-precision result
 * ss     double-precision result
 *
 * Reference: http://www.netlib.org/blas/drotg.f
 *
 * This function does not set any error status.
 */
void CUBLASAPI cublasDrotg (double *host_sa, double *host_sb, double *host_sc, double *host_ss);

/*
 * void 
 * cublasDrotm (int n, double *x, int incx, double *y, int incy, 
 *              const double* sparam)
 *
 * applies the modified Givens transformation, h, to the 2 x n matrix
 *
 *    ( transpose(x) )
 *    ( transpose(y) )
 *
 * The elements of x are in x[lx + i * incx], i = 0 to n-1, where lx = 1 if 
 * incx >= 0, else lx = 1 + (1 - n) * incx, and similarly for y using ly and 
 * incy. With sparam[0] = sflag, h has one of the following forms:
 *
 *        sflag = -1.0    sflag = 0.0     sflag = 1.0     sflag = -2.0
 *
 *        (sh00  sh01)    (1.0   sh01)    (sh00   1.0)    (1.0    0.0)
 *    h = (          )    (          )    (          )    (          )
 *        (sh10  sh11)    (sh10   1.0)    (-1.0  sh11)    (0.0    1.0)
 *
 * Note that this function is provided for completeness and run exclusively 
 * on the Host.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 * y      double-precision vector with n elements
 * incy   storage spacing between elements of y
 * sparam 5-element vector. sparam[0] is sflag described above. sparam[1] 
 *        through sparam[4] contain the 2x2 rotation matrix h: sparam[1]
 *        contains sh00, sparam[2] contains sh10, sparam[3] contains sh01,
 *        and sprams[4] contains sh11.
 *
 * Output
 * ------
 * x     rotated vector x (unchanged if n <= 0)
 * y     rotated vector y (unchanged if n <= 0)
 *
 * Reference: http://www.netlib.org/blas/drotm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDrotm(int n, double *x, int incx, double *y, int incy, 
                           const double* sparam);

/*
 * void 
 * cublasDrotmg (double *host_sd1, double *host_sd2, double *host_sx1, const double *host_sy1,
 *               double *host_sparam)
 *
 * constructs the modified Givens transformation matrix h which zeros
 * the second component of the 2-vector transpose(sqrt(sd1)*sx1,sqrt(sd2)*sy1).
 * With sparam[0] = sflag, h has one of the following forms:
 *
 *        sflag = -1.0    sflag = 0.0     sflag = 1.0     sflag = -2.0
 *
 *        (sh00  sh01)    (1.0   sh01)    (sh00   1.0)    (1.0    0.0)
 *    h = (          )    (          )    (          )    (          )
 *        (sh10  sh11)    (sh10   1.0)    (-1.0  sh11)    (0.0    1.0)
 *
 * sparam[1] through sparam[4] contain sh00, sh10, sh01, sh11, 
 * respectively. Values of 1.0, -1.0, or 0.0 implied by the value 
 * of sflag are not stored in sparam.
 * Note that this function is provided for completeness and run exclusively 
 * on the Host.
 *
 * Input
 * -----
 * sd1    single precision scalar
 * sd2    single precision scalar
 * sx1    single precision scalar
 * sy1    single precision scalar
 *
 * Output
 * ------
 * sd1    changed to represent the effect of the transformation
 * sd2    changed to represent the effect of the transformation
 * sx1    changed to represent the effect of the transformation
 * sparam 5-element vector. sparam[0] is sflag described above. sparam[1] 
 *        through sparam[4] contain the 2x2 rotation matrix h: sparam[1]
 *        contains sh00, sparam[2] contains sh10, sparam[3] contains sh01,
 *        and sprams[4] contains sh11.
 *
 * Reference: http://www.netlib.org/blas/drotmg.f
 *
 * This functions does not set any error status.
 */
void CUBLASAPI cublasDrotmg (double *host_sd1, double *host_sd2, double *host_sx1, 
                             const double *host_sy1, double* host_sparam);

/*
 * void
 * cublasDscal (int n, double alpha, double *x, int incx)
 *
 * replaces double-precision vector x with double-precision alpha * x. For 
 * i = 0 to n-1, it replaces x[lx + i * incx] with alpha * x[lx + i * incx],
 * where lx = 1 if incx >= 0, else lx = 1 + (1 - n) * incx.
 *
 * Input
 * -----
 * n      number of elements in input vector
 * alpha  double-precision scalar multiplier
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * x      double-precision result (unchanged if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/dscal.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library was not initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDscal (int n, double alpha, double *x, int incx);

/*
 * void
 * cublasDswap (int n, double *x, int incx, double *y, int incy)
 *
 * replaces double-precision vector x with double-precision alpha * x. For i 
 * = 0 to n - 1, it replaces x[ix + i * incx] with alpha * x[ix + i * incx], 
 * where ix = 1 if incx >= 0, else ix = 1 + (1 - n) * incx.
 *
 * Input
 * -----
 * n      number of elements in input vectors
 * alpha  double-precision scalar multiplier
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * x      double precision result (unchanged if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/dswap.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDswap (int n, double *x, int incx, double *y, int incy);

/*
 * int 
 * idamax (int n, const double *x, int incx)
 *
 * finds the smallest index of the maximum magnitude element of double-
 * precision vector x; that is, the result is the first i, i = 0 to n - 1, 
 * that maximizes abs(x[1 + i * incx])).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the smallest index (0 if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/blas/idamax.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
int CUBLASAPI cublasIdamax (int n, const double *x, int incx);

/*
 * int 
 * idamin (int n, const double *x, int incx)
 *
 * finds the smallest index of the minimum magnitude element of double-
 * precision vector x; that is, the result is the first i, i = 0 to n - 1, 
 * that minimizes abs(x[1 + i * incx])).
 * 
 * Input
 * -----
 * n      number of elements in input vector
 * x      double-precision vector with n elements
 * incx   storage spacing between elements of x
 *
 * Output
 * ------
 * returns the smallest index (0 if n <= 0 or incx <= 0)
 *
 * Reference: http://www.netlib.org/scilib/blass.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
int CUBLASAPI cublasIdamin (int n, const double *x, int incx);


/* ---------------- CUBLAS double precision BLAS2 functions ---------------- */

/*
 * cublasDgemv (char trans, int m, int n, double alpha, const double *A, 
 *              int lda, const double *x, int incx, double beta, double *y, 
 *              int incy)
 *
 * performs one of the matrix-vector operations
 *
 *    y = alpha * op(A) * x + beta * y,
 *
 * where op(A) is one of
 *
 *    op(A) = A   or   op(A) = transpose(A)
 *
 * where alpha and beta are double precision scalars, x and y are double 
 * precision vectors, and A is an m x n matrix consisting of double precision
 * elements. Matrix A is stored in column major format, and lda is the leading
 * dimension of the two-dimensional array in which A is stored.
 *
 * Input
 * -----
 * trans  specifies op(A). If transa = 'n' or 'N', op(A) = A. If trans =
 *        trans = 't', 'T', 'c', or 'C', op(A) = transpose(A)
 * m      specifies the number of rows of the matrix A. m must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. n must be at least 
 *        zero.
 * alpha  double precision scalar multiplier applied to op(A).
 * A      double precision array of dimensions (lda, n) if trans = 'n' or 
 *        'N'), and of dimensions (lda, m) otherwise. lda must be at least 
 *        max(1, m) and at least max(1, n) otherwise.
 * lda    leading dimension of two-dimensional array used to store matrix A
 * x      double precision array of length at least (1 + (n - 1) * abs(incx))
 *        when trans = 'N' or 'n' and at least (1 + (m - 1) * abs(incx)) 
 *        otherwise.
 * incx   specifies the storage spacing between elements of x. incx must not 
 *        be zero.
 * beta   double precision scalar multiplier applied to vector y. If beta 
 *        is zero, y is not read.
 * y      double precision array of length at least (1 + (m - 1) * abs(incy))
 *        when trans = 'N' or 'n' and at least (1 + (n - 1) * abs(incy)) 
 *        otherwise.
 * incy   specifies the storage spacing between elements of x. incx must not
 *        be zero.
 *
 * Output
 * ------
 * y      updated according to alpha * op(A) * x + beta * y
 *
 * Reference: http://www.netlib.org/blas/dgemv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0, or if incx or incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDgemv (char trans, int m, int n, double alpha, 
                            const double *A, int lda, const double *x, 
                            int incx, double beta, double *y, int incy);

/*
 * cublasDger (int m, int n, double alpha, const double *x, int incx,
 *             const double *y, int incy, double *A, int lda)
 *
 * performs the symmetric rank 1 operation
 *
 *    A = alpha * x * transpose(y) + A,
 *
 * where alpha is a double precision scalar, x is an m element double
 * precision vector, y is an n element double precision vector, and A
 * is an m by n matrix consisting of double precision elements. Matrix A
 * is stored in column major format, and lda is the leading dimension of
 * the two-dimensional array used to store A.
 *
 * Input
 * -----
 * m      specifies the number of rows of the matrix A. It must be at least
 *        zero.
 * n      specifies the number of columns of the matrix A. It must be at
 *        least zero.
 * alpha  double precision scalar multiplier applied to x * transpose(y)
 * x      double precision array of length at least (1 + (m - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must not
 *        be zero.
 * y      double precision array of length at least (1 + (n - 1) * abs(incy))
 * incy   specifies the storage spacing between elements of y. incy must not
 *        be zero.
 * A      double precision array of dimensions (lda, n).
 * lda    leading dimension of two-dimensional array used to store matrix A
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * transpose(y) + A
 *
 * Reference: http://www.netlib.org/blas/dger.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDger (int m, int n, double alpha, const double *x,
                           int incx, const double *y, int incy,
                           double *A, int lda);

/*
 * void 
 * cublasDsyr (char uplo, int n, double alpha, const double *x, int incx, 
 *             double *A, int lda)
 *
 * performs the symmetric rank 1 operation
 *
 *    A = alpha * x * transpose(x) + A,
 *
 * where alpha is a double precision scalar, x is an n element double 
 * precision vector and A is an n x n symmetric matrix consisting of 
 * double precision elements. Matrix A is stored in column major format,
 * and lda is the leading dimension of the two-dimensional array 
 * containing A.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or 
 *        the lower triangular part of array A. If uplo = 'U' or 'u',
 *        then only the upper triangular part of A may be referenced.
 *        If uplo = 'L' or 'l', then only the lower triangular part of
 *        A may be referenced.
 * n      specifies the number of rows and columns of the matrix A. It
 *        must be at least 0.
 * alpha  double precision scalar multiplier applied to x * transpose(x)
 * x      double precision array of length at least (1 + (n - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must 
 *        not be zero.
 * A      double precision array of dimensions (lda, n). If uplo = 'U' or 
 *        'u', then A must contain the upper triangular part of a symmetric 
 *        matrix, and the strictly lower triangular part is not referenced. 
 *        If uplo = 'L' or 'l', then A contains the lower triangular part 
 *        of a symmetric matrix, and the strictly upper triangular part is 
 *        not referenced.
 * lda    leading dimension of the two-dimensional array containing A. lda
 *        must be at least max(1, n).
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * transpose(x) + A
 *
 * Reference: http://www.netlib.org/blas/dsyr.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or incx == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDsyr (char uplo, int n, double alpha,
                           const double *x, int incx, double *A, 
                           int lda);
                           
/*
 * void cublasDsyr2 (char uplo, int n, double alpha, const double *x, int incx, 
 *                   const double *y, int incy, double *A, int lda)
 *
 * performs the symmetric rank 2 operation
 *
 *    A = alpha*x*transpose(y) + alpha*y*transpose(x) + A,
 *
 * where alpha is a double precision scalar, x and y are n element double 
 * precision vector and A is an n by n symmetric matrix consisting of double 
 * precision elements.
 * 
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array A. If uplo == 'U' or 'u', then only the 
 *        upper triangular part of A may be referenced and the lower triangular
 *        part of A is inferred. If uplo == 'L' or 'l', then only the lower 
 *        triangular part of A may be referenced and the upper triangular part
 *        of A is inferred.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  double precision scalar multiplier applied to x * transpose(y) + 
 *        y * transpose(x).
 * x      double precision array of length at least (1 + (n - 1) * abs (incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * y      double precision array of length at least (1 + (n - 1) * abs (incy)).
 * incy   storage spacing between elements of y. incy must not be zero.
 * A      double precision array of dimensions (lda, n). If uplo == 'U' or 'u',
 *        then A must contains the upper triangular part of a symmetric matrix,
 *        and the strictly lower triangular parts is not referenced. If uplo ==
 *        'L' or 'l', then A contains the lower triangular part of a symmetric 
 *        matrix, and the strictly upper triangular part is not referenced.
 * lda    leading dimension of A. It must be at least max(1, n).
 *
 * Output
 * ------
 * A      updated according to A = alpha*x*transpose(y)+alpha*y*transpose(x)+A
 *
 * Reference: http://www.netlib.org/blas/dsyr2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDsyr2 (char uplo, int n, double alpha,
                            const double *x, int incx, const double *y,
                            int incy, double *A, int lda);                           
                           
/*
 * void 
 * cublasDspr (char uplo, int n, double alpha, const double *x, int incx, 
 *             double *AP)
 *
 * performs the symmetric rank 1 operation
 * 
 *    A = alpha * x * transpose(x) + A,
 * 
 * where alpha is a double precision scalar and x is an n element double 
 * precision vector. A is a symmetric n x n matrix consisting of double 
 * precision elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array AP. If uplo == 'U' or 'u', then the upper 
 *        triangular part of A is supplied in AP. If uplo == 'L' or 'l', then 
 *        the lower triangular part of A is supplied in AP.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  double precision scalar multiplier applied to x * transpose(x).
 * x      double precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * AP     double precision array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * transpose(x) + A
 *
 * Reference: http://www.netlib.org/blas/dspr.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or incx == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDspr (char uplo, int n, double alpha,
                           const double *x, int incx, double *AP);                           
/* 
 * void 
 * cublasDspr2 (char uplo, int n, double alpha, const double *x, int incx, 
 *              const double *y, int incy, double *AP)
 *
 * performs the symmetric rank 2 operation
 *
 *    A = alpha*x*transpose(y) + alpha*y*transpose(x) + A,
 *
 * where alpha is a double precision scalar, and x and y are n element double 
 * precision vectors. A is a symmetric n x n matrix consisting of double 
 * precision elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array A. If uplo == 'U' or 'u', then only the 
 *        upper triangular part of A may be referenced and the lower triangular
 *        part of A is inferred. If uplo == 'L' or 'l', then only the lower 
 *        triangular part of A may be referenced and the upper triangular part
 *        of A is inferred.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  double precision scalar multiplier applied to x * transpose(y) + 
 *        y * transpose(x).
 * x      double precision array of length at least (1 + (n - 1) * abs (incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * y      double precision array of length at least (1 + (n - 1) * abs (incy)).
 * incy   storage spacing between elements of y. incy must not be zero.
 * AP     double precision array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *
 * Output
 * ------
 * A      updated according to A = alpha*x*transpose(y)+alpha*y*transpose(x)+A
 *
 * Reference: http://www.netlib.org/blas/dspr2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDspr2 (char uplo, int n, double alpha,
                            const double *x, int incx, const double *y,
                            int incy, double *AP);
                            
/*
 * void 
 * cublasDtrsv (char uplo, char trans, char diag, int n, const double *A, 
 *              int lda, double *x, int incx)
 *
 * solves a system of equations op(A) * x = b, where op(A) is either A or 
 * transpose(A). b and x are double precision vectors consisting of n
 * elements, and A is an n x n matrix composed of a unit or non-unit, upper
 * or lower triangular matrix. Matrix A is stored in column major format,
 * and lda is the leading dimension of the two-dimensional array containing
 * A.
 *
 * No test for singularity or near-singularity is included in this function. 
 * Such tests must be performed before calling this function.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the 
 *        lower triangular part of array A. If uplo = 'U' or 'u', then only 
 *        the upper triangular part of A may be referenced. If uplo = 'L' or 
 *        'l', then only the lower triangular part of A may be referenced.
 * trans  specifies op(A). If transa = 'n' or 'N', op(A) = A. If transa = 't',
 *        'T', 'c', or 'C', op(A) = transpose(A)
 * diag   specifies whether or not A is a unit triangular matrix like so:
 *        if diag = 'U' or 'u', A is assumed to be unit triangular. If 
 *        diag = 'N' or 'n', then A is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. It
 *        must be at least 0. 
 * A      is a double precision array of dimensions (lda, n). If uplo = 'U' 
 *        or 'u', then A must contains the upper triangular part of a symmetric
 *        matrix, and the strictly lower triangular parts is not referenced. 
 *        If uplo = 'L' or 'l', then A contains the lower triangular part of 
 *        a symmetric matrix, and the strictly upper triangular part is not 
 *        referenced. 
 * lda    is the leading dimension of the two-dimensional array containing A.
 *        lda must be at least max(1, n).
 * x      double precision array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the n element right-hand side vector b. On exit,
 *        it is overwritten with the solution vector x.
 * incx   specifies the storage spacing between elements of x. incx must not 
 *        be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/dtrsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDtrsv (char uplo, char trans, char diag, int n, 
                            const double *A, int lda, double *x, 
                            int incx);

/*
 * void 
 * cublasDtrmv (char uplo, char trans, char diag, int n, const double *A,
 *              int lda, double *x, int incx);
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = 
 = A, or op(A) = transpose(A). x is an n-element single precision vector, and 
 * A is an n x n, unit or non-unit, upper or lower, triangular matrix composed 
 * of single precision elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular 
 *        matrix. If uplo = 'U' or 'u', then A is an upper triangular matrix. 
 *        If uplo = 'L' or 'l', then A is a lower triangular matrix.
 * trans  specifies op(A). If transa = 'N' or 'n', op(A) = A. If trans = 'T', 
 *        't', 'C', or 'c', op(A) = transpose(A)
 * diag   specifies whether or not matrix A is unit triangular. If diag = 'U' 
 *        or 'u', A is assumed to be unit triangular. If diag = 'N' or 'n', A 
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be 
 *        at least zero.
 * A      single precision array of dimension (lda, n). If uplo = 'U' or 'u', 
 *        the leading n x n upper triangular part of the array A must contain 
 *        the upper triangular matrix and the strictly lower triangular part 
 *        of A is not referenced. If uplo = 'L' or 'l', the leading n x n lower
 *        triangular part of the array A must contain the lower triangular 
 *        matrix and the strictly upper triangular part of A is not referenced.
 *        When diag = 'U' or 'u', the diagonal elements of A are not referenced
 *        either, but are are assumed to be unity.
 * lda    is the leading dimension of A. It must be at least max (1, n).
 * x      single precision array of length at least (1 + (n - 1) * abs(incx) ).
 *        On entry, x contains the source vector. On exit, x is overwritten 
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x,
 *
 * Reference: http://www.netlib.org/blas/dtrmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDtrmv (char uplo, char trans, char diag, int n, 
                            const double *A, int lda, double *x, int incx);


/*
 * void 
 * cublasDgbmv (char trans, int m, int n, int kl, int ku, double alpha,
 *              const double *A, int lda, const double *x, int incx, double beta,
 *              double *y, int incy);
 *
 * performs one of the matrix-vector operations
 *
 *    y = alpha*op(A)*x + beta*y,  op(A)=A or op(A) = transpose(A)
 *
 * alpha and beta are double precision scalars. x and y are double precision
 * vectors. A is an m by n band matrix consisting of double precision elements
 * with kl sub-diagonals and ku super-diagonals.
 *
 * Input
 * -----
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T', 
 *        't', 'C', or 'c', op(A) = transpose(A)
 * m      specifies the number of rows of the matrix A. m must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. n must be at least
 *        zero.
 * kl     specifies the number of sub-diagonals of matrix A. It must be at 
 *        least zero.
 * ku     specifies the number of super-diagonals of matrix A. It must be at
 *        least zero.
 * alpha  double precision scalar multiplier applied to op(A).
 * A      double precision array of dimensions (lda, n). The leading
 *        (kl + ku + 1) x n part of the array A must contain the band matrix A,
 *        supplied column by column, with the leading diagonal of the matrix 
 *        in row (ku + 1) of the array, the first super-diagonal starting at 
 *        position 2 in row ku, the first sub-diagonal starting at position 1
 *        in row (ku + 2), and so on. Elements in the array A that do not 
 *        correspond to elements in the band matrix (such as the top left 
 *        ku x ku triangle) are not referenced.
 * lda    leading dimension of A. lda must be at least (kl + ku + 1).
 * x      double precision array of length at least (1+(n-1)*abs(incx)) when 
 *        trans == 'N' or 'n' and at least (1+(m-1)*abs(incx)) otherwise.
 * incx   specifies the increment for the elements of x. incx must not be zero.
 * beta   double precision scalar multiplier applied to vector y. If beta is 
 *        zero, y is not read.
 * y      double precision array of length at least (1+(m-1)*abs(incy)) when 
 *        trans == 'N' or 'n' and at least (1+(n-1)*abs(incy)) otherwise. If 
 *        beta is zero, y is not read.
 * incy   On entry, incy specifies the increment for the elements of y. incy 
 *        must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*op(A)*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/dgbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDgbmv (char trans, int m, int n, int kl, int ku, 
                            double alpha, const double *A, int lda, 
                            const double *x, int incx, double beta, 
                            double *y, int incy);
 
/*
 * void 
 * cublasDtbmv (char uplo, char trans, char diag, int n, int k, const double *A,
 *              int lda, double *x, int incx)
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = A,
 * or op(A) = transpose(A). x is an n-element double precision vector, and A is
 * an n x n, unit or non-unit, upper or lower triangular band matrix composed
 * of double precision elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular band
 *        matrix. If uplo == 'U' or 'u', A is an upper triangular band matrix.
 *        If uplo == 'L' or 'l', A is a lower triangular band matrix.
 * trans  specifies op(A). If transa == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', 'C', or 'c', op(A) = transpose(A)
 * diag   specifies whether or not matrix A is unit triangular. If diag == 'U'
 *        or 'u', A is assumed to be unit triangular. If diag == 'N' or 'n', A
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * k      specifies the number of super- or sub-diagonals. If uplo == 'U' or 
 *        'u', k specifies the number of super-diagonals. If uplo == 'L' or 
 *        'l', k specifies the number of sub-diagonals. k must at least be 
 *        zero.
 * A      double precision array of dimension (lda, n). If uplo == 'U' or 'u',
 *        the leading (k + 1) x n part of the array A must contain the upper 
 *        triangular band matrix, supplied column by column, with the leading
 *        diagonal of the matrix in row (k + 1) of the array, the first 
 *        super-diagonal starting at position 2 in row k, and so on. The top
 *        left k x k triangle of the array A is not referenced. If uplo == 'L'
 *        or 'l', the leading (k + 1) x n part of the array A must constain the
 *        lower triangular band matrix, supplied column by column, with the
 *        leading diagonal of the matrix in row 1 of the array, the first 
 *        sub-diagonal startingat position 1 in row 2, and so on. The bottom
 *        right k x k triangle of the array is not referenced.
 * lda    is the leading dimension of A. It must be at least (k + 1).
 * x      double precision array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the source vector. On exit, x is overwritten
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x
 *
 * Reference: http://www.netlib.org/blas/dtbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n or k < 0, or if incx == 0
 * CUBLAS_STATUS_ALLOC_FAILED     if function cannot allocate enough internal scratch vector memory 
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDtbmv (char uplo, char trans, char diag, int n,
                            int k, const double *A, int lda, double *x,
                            int incx);                                     
                            
/*
 * void 
 * cublasDtpmv (char uplo, char trans, char diag, int n, const double *AP, 
 *              double *x, int incx);
 *
 * performs one of the matrix-vector operations x = op(A) * x, where op(A) = A,
 * or op(A) = transpose(A). x is an n element double precision vector, and A 
 * is an n x n, unit or non-unit, upper or lower triangular matrix composed 
 * of double precision elements.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix. If uplo == 'U' or 'u', then A is an upper triangular matrix.
 *        If uplo == 'L' or 'l', then A is a lower triangular matrix.
 * trans  specifies op(A). If transa == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', 'C', or 'c', op(A) = transpose(A)
 * diag   specifies whether or not matrix A is unit triangular. If diag == 'U'
 *        or 'u', A is assumed to be unit triangular. If diag == 'N' or 'n', A 
 *        is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be 
 *        at least zero. In the current implementation n must not exceed 4070.
 * AP     double precision array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored in AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 * x      double precision array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the source vector. On exit, x is overwritten 
 *        with the result vector.
 * incx   specifies the storage spacing for elements of x. incx must not be 
 *        zero.
 *
 * Output
 * ------
 * x      updated according to x = op(A) * x,
 *
 * Reference: http://www.netlib.org/blas/dtpmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or n < 0
 * CUBLAS_STATUS_ALLOC_FAILED     if function cannot allocate enough internal scratch vector memory 
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDtpmv (char uplo, char trans, char diag, int n, 
                            const double *AP, double *x, int incx);  
                            

/*
 * void 
 * cublasDtpsv (char uplo, char trans, char diag, int n, const double *AP, 
 *              double *X, int incx)
 *
 * solves one of the systems of equations op(A)*x = b, where op(A) is either 
 * op(A) = A or op(A) = transpose(A). b and x are n element vectors, and A is
 * an n x n unit or non-unit, upper or lower triangular matrix. No test for
 * singularity or near-singularity is included in this routine. Such tests 
 * must be performed before calling this routine.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix is an upper or lower triangular matrix
 *        as follows: If uplo == 'U' or 'u', A is an upper triangluar matrix.
 *        If uplo == 'L' or 'l', A is a lower triangular matrix.
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', 'C', or 'c', op(A) = transpose(A).
 * diag   specifies whether A is unit triangular. If diag == 'U' or 'u', A is
 *        assumed to be unit triangular; thas is, diagonal elements are not
 *        read and are assumed to be unity. If diag == 'N' or 'n', A is not
 *        assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * AP     double precision array with at least ((n*(n+1))/2) elements. If uplo
 *        == 'U' or 'u', the array AP contains the upper triangular matrix A,
 *        packed sequentially, column by column; that is, if i <= j, then 
 *        A[i,j] is stored is AP[i+(j*(j+1)/2)]. If uplo == 'L' or 'L', the 
 *        array AP contains the lower triangular matrix A, packed sequentially,
 *        column by column; that is, if i >= j, then A[i,j] is stored in 
 *        AP[i+((2*n-j+1)*j)/2]. When diag = 'U' or 'u', the diagonal elements
 *        of A are not referenced and are assumed to be unity.
 * x      double precision array of length at least (1+(n-1)*abs(incx)).
 * incx   storage spacing between elements of x. It must not be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/dtpsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0 or n > 2035
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support    
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDtpsv (char uplo, char trans, char diag, int n,
                            const double *AP, double *x, int incx);                            
                            
/*
 * void cublasDtbsv (char uplo, char trans, char diag, int n, int k,
 *                   const double *A, int lda, double *X, int incx)
 *
 * solves one of the systems of equations op(A)*x = b, where op(A) is either 
 * op(A) = A or op(A) = transpose(A). b and x are n element vectors, and A is
 * an n x n unit or non-unit, upper or lower triangular band matrix with k + 1
 * diagonals. No test for singularity or near-singularity is included in this
 * function. Such tests must be performed before calling this function.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix is an upper or lower triangular band 
 *        matrix as follows: If uplo == 'U' or 'u', A is an upper triangular
 *        band matrix. If uplo == 'L' or 'l', A is a lower triangular band
 *        matrix.
 * trans  specifies op(A). If trans == 'N' or 'n', op(A) = A. If trans == 'T',
 *        't', 'C', or 'c', op(A) = transpose(A).
 * diag   specifies whether A is unit triangular. If diag == 'U' or 'u', A is
 *        assumed to be unit triangular; thas is, diagonal elements are not
 *        read and are assumed to be unity. If diag == 'N' or 'n', A is not
 *        assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. n must be
 *        at least zero.
 * k      specifies the number of super- or sub-diagonals. If uplo == 'U' or
 *        'u', k specifies the number of super-diagonals. If uplo == 'L' or
 *        'l', k specifies the number of sub-diagonals. k must at least be 
 *        zero.
 * A      double precision array of dimension (lda, n). If uplo == 'U' or 'u',
 *        the leading (k + 1) x n part of the array A must contain the upper
 *        triangular band matrix, supplied column by column, with the leading
 *        diagonal of the matrix in row (k + 1) of the array, the first super-
 *        diagonal starting at position 2 in row k, and so on. The top left 
 *        k x k triangle of the array A is not referenced. If uplo == 'L' or 
 *        'l', the leading (k + 1) x n part of the array A must constain the
 *        lower triangular band matrix, supplied column by column, with the
 *        leading diagonal of the matrix in row 1 of the array, the first
 *        sub-diagonal starting at position 1 in row 2, and so on. The bottom
 *        right k x k triangle of the array is not referenced.
 * x      double precision array of length at least (1+(n-1)*abs(incx)).
 * incx   storage spacing between elements of x. It must not be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/dtbsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0, n < 0 or n > 2035
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support   
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDtbsv (char uplo, char trans, char diag, int n,
                            int k, const double *A, int lda, double *x,
                            int incx);                                                     

/*
 * void 
 * cublasDsymv (char uplo, int n, double alpha, const double *A, int lda, 
 *              const double *x, int incx, double beta, double *y, int incy)
 *
 * performs the matrix-vector operation
 *
 *     y = alpha*A*x + beta*y
 *
 * Alpha and beta are double precision scalars, and x and y are double 
 * precision vectors, each with n elements. A is a symmetric n x n matrix 
 * consisting of double precision elements that is stored in either upper or 
 * lower storage mode.
 *
 * Input
 * -----
 * uplo   specifies whether the upper or lower triangular part of the array A 
 *        is to be referenced. If uplo == 'U' or 'u', the symmetric matrix A 
 *        is stored in upper storage mode, i.e. only the upper triangular part
 *        of A is to be referenced while the lower triangular part of A is to 
 *        be inferred. If uplo == 'L' or 'l', the symmetric matrix A is stored
 *        in lower storage mode, i.e. only the lower triangular part of A is 
 *        to be referenced while the upper triangular part of A is to be 
 *        inferred.
 * n      specifies the number of rows and the number of columns of the 
 *        symmetric matrix A. n must be at least zero.
 * alpha  double precision scalar multiplier applied to A*x.
 * A      double precision array of dimensions (lda, n). If uplo == 'U' or 'u',
 *        the leading n x n upper triangular part of the array A must contain
 *        the upper triangular part of the symmetric matrix and the strictly
 *        lower triangular part of A is not referenced. If uplo == 'L' or 'l',
 *        the leading n x n lower triangular part of the array A must contain
 *        the lower triangular part of the symmetric matrix and the strictly
 *        upper triangular part of A is not referenced. 
 * lda    leading dimension of A. It must be at least max (1, n).
 * x      double precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   double precision scalar multiplier applied to vector y.
 * y      double precision array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read. 
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/dsymv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDsymv (char uplo, int n, double alpha,
                            const double *A, int lda, const double *x,
                            int incx, double beta, double *y, int incy);
                            
/*
 * void 
 * cublasDsbmv (char uplo, int n, int k, double alpha, const double *A, int lda,
 *              const double *x, int incx, double beta, double *y, int incy)
 *
 * performs the matrix-vector operation
 *
 *     y := alpha*A*x + beta*y
 *
 * alpha and beta are double precision scalars. x and y are double precision
 * vectors with n elements. A is an n by n symmetric band matrix consisting 
 * of double precision elements, with k super-diagonals and the same number
 * of subdiagonals.
 *
 * Input
 * -----
 * uplo   specifies whether the upper or lower triangular part of the symmetric
 *        band matrix A is being supplied. If uplo == 'U' or 'u', the upper 
 *        triangular part is being supplied. If uplo == 'L' or 'l', the lower 
 *        triangular part is being supplied.
 * n      specifies the number of rows and the number of columns of the
 *        symmetric matrix A. n must be at least zero.
 * k      specifies the number of super-diagonals of matrix A. Since the matrix
 *        is symmetric, this is also the number of sub-diagonals. k must be at
 *        least zero.
 * alpha  double precision scalar multiplier applied to A*x.
 * A      double precision array of dimensions (lda, n). When uplo == 'U' or 
 *        'u', the leading (k + 1) x n part of array A must contain the upper
 *        triangular band of the symmetric matrix, supplied column by column,
 *        with the leading diagonal of the matrix in row (k+1) of the array,
 *        the first super-diagonal starting at position 2 in row k, and so on.
 *        The top left k x k triangle of the array A is not referenced. When
 *        uplo == 'L' or 'l', the leading (k + 1) x n part of the array A must
 *        contain the lower triangular band part of the symmetric matrix, 
 *        supplied column by column, with the leading diagonal of the matrix in
 *        row 1 of the array, the first sub-diagonal starting at position 1 in
 *        row 2, and so on. The bottom right k x k triangle of the array A is
 *        not referenced.
 * lda    leading dimension of A. lda must be at least (k + 1).
 * x      double precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   double precision scalar multiplier applied to vector y. If beta is 
 *        zero, y is not read.
 * y      double precision array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read.
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/dsbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized 
 * CUBLAS_STATUS_INVALID_VALUE    if k or n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support   
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDsbmv (char uplo, int n, int k, double alpha, 
                            const double *A, int lda, const double *x, 
                            int incx, double beta, double *y, int incy);  
                            
/*
 * void 
 * cublasDspmv (char uplo, int n, double alpha, const double *AP, const double *x,
 *              int incx, double beta, double *y, int incy)
 *
 * performs the matrix-vector operation
 * 
 *    y = alpha * A * x + beta * y
 *
 * Alpha and beta are double precision scalars, and x and y are double 
 * precision vectors with n elements. A is a symmetric n x n matrix 
 * consisting of double precision elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array AP. If uplo == 'U' or 'u', then the upper 
 *        triangular part of A is supplied in AP. If uplo == 'L' or 'l', then 
 *        the lower triangular part of A is supplied in AP.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  double precision scalar multiplier applied to A*x.
 * AP     double precision array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the symmetric matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 * x      double precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   double precision scalar multiplier applied to vector y;
 * y      double precision array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read. 
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to y = alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/dspmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support    
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDspmv (char uplo, int n, double alpha,
                            const double *AP, const double *x,
                            int incx, double beta, double *y, int incy);                                                      
                            
/* ---------------- CUBLAS double precision BLAS3 functions ---------------- */

/*
 * void 
 * cublasDgemm (char transa, char transb, int m, int n, int k, double alpha,
 *              const double *A, int lda, const double *B, int ldb, 
 *              double beta, double *C, int ldc)
 *
 * computes the product of matrix A and matrix B, multiplies the result 
 * by scalar alpha, and adds the sum to the product of matrix C and
 * scalar beta. It performs one of the matrix-matrix operations:
 *
 * C = alpha * op(A) * op(B) + beta * C,  
 * where op(X) = X or op(X) = transpose(X),
 *
 * and alpha and beta are double-precision scalars. A, B and C are matrices
 * consisting of double-precision elements, with op(A) an m x k matrix, 
 * op(B) a k x n matrix, and C an m x n matrix. Matrices A, B, and C are 
 * stored in column-major format, and lda, ldb, and ldc are the leading 
 * dimensions of the two-dimensional arrays containing A, B, and C.
 *
 * Input
 * -----
 * transa specifies op(A). If transa == 'N' or 'n', op(A) = A. 
 *        If transa == 'T', 't', 'C', or 'c', op(A) = transpose(A).
 * transb specifies op(B). If transb == 'N' or 'n', op(B) = B. 
 *        If transb == 'T', 't', 'C', or 'c', op(B) = transpose(B).
 * m      number of rows of matrix op(A) and rows of matrix C; m must be at
 *        least zero.
 * n      number of columns of matrix op(B) and number of columns of C; 
 *        n must be at least zero.
 * k      number of columns of matrix op(A) and number of rows of op(B);
 *        k must be at least zero.
 * alpha  double-precision scalar multiplier applied to op(A) * op(B).
 * A      double-precision array of dimensions (lda, k) if transa == 'N' or 
 *        'n', and of dimensions (lda, m) otherwise. If transa == 'N' or 
 *        'n' lda must be at least max(1, m), otherwise lda must be at
 *        least max(1, k).
 * lda    leading dimension of two-dimensional array used to store matrix A.
 * B      double-precision array of dimensions (ldb, n) if transb == 'N' or
 *        'n', and of dimensions (ldb, k) otherwise. If transb == 'N' or 
 *        'n' ldb must be at least max (1, k), otherwise ldb must be at
 *        least max(1, n).
 * ldb    leading dimension of two-dimensional array used to store matrix B.
 * beta   double-precision scalar multiplier applied to C. If zero, C does not 
 *        have to be a valid input
 * C      double-precision array of dimensions (ldc, n); ldc must be at least
 *        max(1, m).
 * ldc    leading dimension of two-dimensional array used to store matrix C.
 * 
 * Output
 * ------
 * C      updated based on C = alpha * op(A)*op(B) + beta * C.
 *
 * Reference: http://www.netlib.org/blas/sgemm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS was not initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m < 0, n < 0, or k < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDgemm (char transa, char transb, int m, int n, int k,
                            double alpha, const double *A, int lda, 
                            const double *B, int ldb, double beta, double *C, 
                            int ldc);

/*
 * void
 * cublasDtrsm (char side, char uplo, char transa, char diag, int m, int n,
 *              double alpha, const double *A, int lda, double *B, int ldb)
 *
 * solves one of the matrix equations
 *
 *    op(A) * X = alpha * B,   or   X * op(A) = alpha * B,
 *
 * where alpha is a double precision scalar, and X and B are m x n matrices
 * that are composed of double precision elements. A is a unit or non-unit,
 * upper or lower triangular matrix, and op(A) is one of
 *
 *    op(A) = A  or  op(A) = transpose(A)
 *
 * The result matrix X overwrites input matrix B; that is, on exit the result
 * is stored in B. Matrices A and B are stored in column major format, and
 * lda and ldb are the leading dimensions of the two-dimensonials arrays that
 * contain A and B, respectively.
 *
 * Input
 * -----
 * side   specifies whether op(A) appears on the left or right of X as
 *        follows: side = 'L' or 'l' indicates solve op(A) * X = alpha * B.
 *        side = 'R' or 'r' indicates solve X * op(A) = alpha * B.
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix as follows: uplo = 'U' or 'u' indicates A is an upper
 *        triangular matrix. uplo = 'L' or 'l' indicates A is a lower
 *        triangular matrix.
 * transa specifies the form of op(A) to be used in matrix multiplication
 *        as follows: If transa = 'N' or 'N', then op(A) = A. If transa =
 *        'T', 't', 'C', or 'c', then op(A) = transpose(A).
 * diag   specifies whether or not A is a unit triangular matrix like so:
 *        if diag = 'U' or 'u', A is assumed to be unit triangular. If
 *        diag = 'N' or 'n', then A is not assumed to be unit triangular.
 * m      specifies the number of rows of B. m must be at least zero.
 * n      specifies the number of columns of B. n must be at least zero.
 * alpha  is a double precision scalar to be multiplied with B. When alpha is
 *        zero, then A is not referenced and B need not be set before entry.
 * A      is a double precision array of dimensions (lda, k), where k is
 *        m when side = 'L' or 'l', and is n when side = 'R' or 'r'. If
 *        uplo = 'U' or 'u', the leading k x k upper triangular part of
 *        the array A must contain the upper triangular matrix and the
 *        strictly lower triangular matrix of A is not referenced. When
 *        uplo = 'L' or 'l', the leading k x k lower triangular part of
 *        the array A must contain the lower triangular matrix and the
 *        strictly upper triangular part of A is not referenced. Note that
 *        when diag = 'U' or 'u', the diagonal elements of A are not
 *        referenced, and are assumed to be unity.
 * lda    is the leading dimension of the two dimensional array containing A.
 *        When side = 'L' or 'l' then lda must be at least max(1, m), when
 *        side = 'R' or 'r' then lda must be at least max(1, n).
 * B      is a double precision array of dimensions (ldb, n). ldb must be
 *        at least max (1,m). The leading m x n part of the array B must
 *        contain the right-hand side matrix B. On exit B is overwritten
 *        by the solution matrix X.
 * ldb    is the leading dimension of the two dimensional array containing B.
 *        ldb must be at least max(1, m).
 *
 * Output
 * ------
 * B      contains the solution matrix X satisfying op(A) * X = alpha * B,
 *        or X * op(A) = alpha * B
 *
 * Reference: http://www.netlib.org/blas/dtrsm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDtrsm (char side, char uplo, char transa,
                            char diag, int m, int n, double alpha,
                            const double *A, int lda, double *B,
                            int ldb);

/*
 * void
 * cublasZtrsm (char side, char uplo, char transa, char diag, int m, int n,
 *              cuDoubleComplex alpha, const cuDoubleComplex *A, int lda,
 *              cuDoubleComplex *B, int ldb)
 *
 * solves one of the matrix equations
 *
 *    op(A) * X = alpha * B,   or   X * op(A) = alpha * B,
 *
 * where alpha is a double precision complex scalar, and X and B are m x n matrices
 * that are composed of double precision complex elements. A is a unit or non-unit,
 * upper or lower triangular matrix, and op(A) is one of
 *
 *    op(A) = A  or  op(A) = transpose(A)  or  op( A ) = conj( A' ).
 *
 * The result matrix X overwrites input matrix B; that is, on exit the result
 * is stored in B. Matrices A and B are stored in column major format, and
 * lda and ldb are the leading dimensions of the two-dimensonials arrays that
 * contain A and B, respectively.
 *
 * Input
 * -----
 * side   specifies whether op(A) appears on the left or right of X as
 *        follows: side = 'L' or 'l' indicates solve op(A) * X = alpha * B.
 *        side = 'R' or 'r' indicates solve X * op(A) = alpha * B.
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix as follows: uplo = 'U' or 'u' indicates A is an upper
 *        triangular matrix. uplo = 'L' or 'l' indicates A is a lower
 *        triangular matrix.
 * transa specifies the form of op(A) to be used in matrix multiplication
 *        as follows: If transa = 'N' or 'N', then op(A) = A. If transa =
 *        'T', 't', 'C', or 'c', then op(A) = transpose(A).
 * diag   specifies whether or not A is a unit triangular matrix like so:
 *        if diag = 'U' or 'u', A is assumed to be unit triangular. If
 *        diag = 'N' or 'n', then A is not assumed to be unit triangular.
 * m      specifies the number of rows of B. m must be at least zero.
 * n      specifies the number of columns of B. n must be at least zero.
 * alpha  is a double precision complex scalar to be multiplied with B. When alpha is
 *        zero, then A is not referenced and B need not be set before entry.
 * A      is a double precision complex array of dimensions (lda, k), where k is
 *        m when side = 'L' or 'l', and is n when side = 'R' or 'r'. If
 *        uplo = 'U' or 'u', the leading k x k upper triangular part of
 *        the array A must contain the upper triangular matrix and the
 *        strictly lower triangular matrix of A is not referenced. When
 *        uplo = 'L' or 'l', the leading k x k lower triangular part of
 *        the array A must contain the lower triangular matrix and the
 *        strictly upper triangular part of A is not referenced. Note that
 *        when diag = 'U' or 'u', the diagonal elements of A are not
 *        referenced, and are assumed to be unity.
 * lda    is the leading dimension of the two dimensional array containing A.
 *        When side = 'L' or 'l' then lda must be at least max(1, m), when
 *        side = 'R' or 'r' then lda must be at least max(1, n).
 * B      is a double precision complex array of dimensions (ldb, n). ldb must be
 *        at least max (1,m). The leading m x n part of the array B must
 *        contain the right-hand side matrix B. On exit B is overwritten
 *        by the solution matrix X.
 * ldb    is the leading dimension of the two dimensional array containing B.
 *        ldb must be at least max(1, m).
 *
 * Output
 * ------
 * B      contains the solution matrix X satisfying op(A) * X = alpha * B,
 *        or X * op(A) = alpha * B
 *
 * Reference: http://www.netlib.org/blas/ztrsm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZtrsm (char side, char uplo, char transa,
                            char diag, int m, int n, cuDoubleComplex alpha,
                            const cuDoubleComplex *A, int lda,
                            cuDoubleComplex *B, int ldb);

/*
 * void 
 * cublasDtrmm (char side, char uplo, char transa, char diag, int m, int n, 
 *              double alpha, const double *A, int lda, const double *B, int ldb)
 *
 * performs one of the matrix-matrix operations
 *
 *   B = alpha * op(A) * B,  or  B = alpha * B * op(A)
 *
 * where alpha is a double-precision scalar, B is an m x n matrix composed
 * of double precision elements, and A is a unit or non-unit, upper or lower, 
 * triangular matrix composed of double precision elements. op(A) is one of
 *
 *   op(A) = A  or  op(A) = transpose(A)
 *
 * Matrices A and B are stored in column major format, and lda and ldb are 
 * the leading dimensions of the two-dimensonials arrays that contain A and 
 * B, respectively.
 *
 * Input
 * -----
 * side   specifies whether op(A) multiplies B from the left or right.
 *        If side = 'L' or 'l', then B = alpha * op(A) * B. If side =
 *        'R' or 'r', then B = alpha * B * op(A).
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix. If uplo = 'U' or 'u', A is an upper triangular matrix.
 *        If uplo = 'L' or 'l', A is a lower triangular matrix.
 * transa specifies the form of op(A) to be used in the matrix 
 *        multiplication. If transa = 'N' or 'n', then op(A) = A. If
 *        transa = 'T', 't', 'C', or 'c', then op(A) = transpose(A).
 * diag   specifies whether or not A is unit triangular. If diag = 'U'
 *        or 'u', A is assumed to be unit triangular. If diag = 'N' or
 *        'n', A is not assumed to be unit triangular.
 * m      the number of rows of matrix B. m must be at least zero.
 * n      the number of columns of matrix B. n must be at least zero.
 * alpha  double precision scalar multiplier applied to op(A)*B, or
 *        B*op(A), respectively. If alpha is zero no accesses are made
 *        to matrix A, and no read accesses are made to matrix B.
 * A      double precision array of dimensions (lda, k). k = m if side =
 *        'L' or 'l', k = n if side = 'R' or 'r'. If uplo = 'U' or 'u'
 *        the leading k x k upper triangular part of the array A must
 *        contain the upper triangular matrix, and the strictly lower
 *        triangular part of A is not referenced. If uplo = 'L' or 'l'
 *        the leading k x k lower triangular part of the array A must
 *        contain the lower triangular matrix, and the strictly upper
 *        triangular part of A is not referenced. When diag = 'U' or 'u'
 *        the diagonal elements of A are no referenced and are assumed
 *        to be unity.
 * lda    leading dimension of A. When side = 'L' or 'l', it must be at
 *        least max(1,m) and at least max(1,n) otherwise
 * B      double precision array of dimensions (ldb, n). On entry, the 
 *        leading m x n part of the array contains the matrix B. It is
 *        overwritten with the transformed matrix on exit.
 * ldb    leading dimension of B. It must be at least max (1, m).
 *
 * Output
 * ------
 * B      updated according to B = alpha * op(A) * B  or B = alpha * B * op(A)
 *
 * Reference: http://www.netlib.org/blas/dtrmm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDtrmm (char side, char uplo, char transa,
                            char diag, int m, int n, double alpha,
                            const double *A, int lda, double *B,
                            int ldb);

/*
 * void
 * cublasDsymm (char side, char uplo, int m, int n, double alpha,
 *              const double *A, int lda, const double *B, int ldb,
 *              double beta, double *C, int ldc);
 *
 * performs one of the matrix-matrix operations
 *
 *   C = alpha * A * B + beta * C, or
 *   C = alpha * B * A + beta * C,
 *
 * where alpha and beta are double precision scalars, A is a symmetric matrix
 * consisting of double precision elements and stored in either lower or upper
 * storage mode, and B and C are m x n matrices consisting of double precision
 * elements.
 *
 * Input
 * -----
 * side   specifies whether the symmetric matrix A appears on the left side
 *        hand side or right hand side of matrix B, as follows. If side == 'L'
 *        or 'l', then C = alpha * A * B + beta * C. If side = 'R' or 'r',
 *        then C = alpha * B * A + beta * C.
 * uplo   specifies whether the symmetric matrix A is stored in upper or lower
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper
 *        triangular part of the symmetric matrix is to be referenced, and the
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the
 *        lower triangular part of the symmetric matrix is to be referenced,
 *        and the elements of the strictly upper triangular part are to be
 *        infered from those in the lower triangular part.
 * m      specifies the number of rows of the matrix C, and the number of rows
 *        of matrix B. It also specifies the dimensions of symmetric matrix A
 *        when side == 'L' or 'l'. m must be at least zero.
 * n      specifies the number of columns of the matrix C, and the number of
 *        columns of matrix B. It also specifies the dimensions of symmetric
 *        matrix A when side == 'R' or 'r'. n must be at least zero.
 * alpha  double precision scalar multiplier applied to A * B, or B * A
 * A      double precision array of dimensions (lda, ka), where ka is m when
 *        side == 'L' or 'l' and is n otherwise. If side == 'L' or 'l' the
 *        leading m x m part of array A must contain the symmetric matrix,
 *        such that when uplo == 'U' or 'u', the leading m x m part stores the
 *        upper triangular part of the symmetric matrix, and the strictly lower
 *        triangular part of A is not referenced, and when uplo == 'U' or 'u',
 *        the leading m x m part stores the lower triangular part of the
 *        symmetric matrix and the strictly upper triangular part is not
 *        referenced. If side == 'R' or 'r' the leading n x n part of array A
 *        must contain the symmetric matrix, such that when uplo == 'U' or 'u',
 *        the leading n x n part stores the upper triangular part of the
 *        symmetric matrix and the strictly lower triangular part of A is not
 *        referenced, and when uplo == 'U' or 'u', the leading n x n part
 *        stores the lower triangular part of the symmetric matrix and the
 *        strictly upper triangular part is not referenced.
 * lda    leading dimension of A. When side == 'L' or 'l', it must be at least
 *        max(1, m) and at least max(1, n) otherwise.
 * B      double precision array of dimensions (ldb, n). On entry, the leading
 *        m x n part of the array contains the matrix B.
 * ldb    leading dimension of B. It must be at least max (1, m).
 * beta   double precision scalar multiplier applied to C. If beta is zero, C
 *        does not have to be a valid input
 * C      double precision array of dimensions (ldc, n)
 * ldc    leading dimension of C. Must be at least max(1, m)
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * B + beta * C, or C = alpha *
 *        B * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/dsymm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDsymm (char side, char uplo, int m, int n,
                            double alpha, const double *A, int lda,
                            const double *B, int ldb, double beta,
                            double *C, int ldc);

/*
 * void 
 * cublasZsymm (char side, char uplo, int m, int n, cuDoubleComplex alpha, 
 *              const cuDoubleComplex *A, int lda, const cuDoubleComplex *B, int ldb, 
 *              cuDoubleComplex beta, cuDoubleComplex *C, int ldc);
 *
 * performs one of the matrix-matrix operations
 * 
 *   C = alpha * A * B + beta * C, or 
 *   C = alpha * B * A + beta * C,
 *
 * where alpha and beta are double precision complex scalars, A is a symmetric matrix
 * consisting of double precision complex elements and stored in either lower or upper 
 * storage mode, and B and C are m x n matrices consisting of double precision
 * complex elements.
 *
 * Input
 * -----
 * side   specifies whether the symmetric matrix A appears on the left side 
 *        hand side or right hand side of matrix B, as follows. If side == 'L' 
 *        or 'l', then C = alpha * A * B + beta * C. If side = 'R' or 'r', 
 *        then C = alpha * B * A + beta * C.
 * uplo   specifies whether the symmetric matrix A is stored in upper or lower 
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * m      specifies the number of rows of the matrix C, and the number of rows
 *        of matrix B. It also specifies the dimensions of symmetric matrix A 
 *        when side == 'L' or 'l'. m must be at least zero.
 * n      specifies the number of columns of the matrix C, and the number of 
 *        columns of matrix B. It also specifies the dimensions of symmetric 
 *        matrix A when side == 'R' or 'r'. n must be at least zero.
 * alpha  double precision scalar multiplier applied to A * B, or B * A
 * A      double precision array of dimensions (lda, ka), where ka is m when 
 *        side == 'L' or 'l' and is n otherwise. If side == 'L' or 'l' the 
 *        leading m x m part of array A must contain the symmetric matrix, 
 *        such that when uplo == 'U' or 'u', the leading m x m part stores the 
 *        upper triangular part of the symmetric matrix, and the strictly lower
 *        triangular part of A is not referenced, and when uplo == 'U' or 'u', 
 *        the leading m x m part stores the lower triangular part of the 
 *        symmetric matrix and the strictly upper triangular part is not 
 *        referenced. If side == 'R' or 'r' the leading n x n part of array A 
 *        must contain the symmetric matrix, such that when uplo == 'U' or 'u',
 *        the leading n x n part stores the upper triangular part of the 
 *        symmetric matrix and the strictly lower triangular part of A is not 
 *        referenced, and when uplo == 'U' or 'u', the leading n x n part 
 *        stores the lower triangular part of the symmetric matrix and the 
 *        strictly upper triangular part is not referenced.
 * lda    leading dimension of A. When side == 'L' or 'l', it must be at least 
 *        max(1, m) and at least max(1, n) otherwise.
 * B      double precision array of dimensions (ldb, n). On entry, the leading
 *        m x n part of the array contains the matrix B.
 * ldb    leading dimension of B. It must be at least max (1, m).
 * beta   double precision scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input
 * C      double precision array of dimensions (ldc, n)
 * ldc    leading dimension of C. Must be at least max(1, m)
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * B + beta * C, or C = alpha * 
 *        B * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/zsymm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZsymm (char side, char uplo, int m, int n,
                            cuDoubleComplex alpha, const cuDoubleComplex *A, int lda,
                            const cuDoubleComplex *B, int ldb, cuDoubleComplex beta,
                            cuDoubleComplex *C, int ldc);


/*
 * void 
 * cublasDsyrk (char uplo, char trans, int n, int k, double alpha, 
 *              const double *A, int lda, double beta, double *C, int ldc)
 *
 * performs one of the symmetric rank k operations
 * 
 *   C = alpha * A * transpose(A) + beta * C, or 
 *   C = alpha * transpose(A) * A + beta * C.
 *
 * Alpha and beta are double precision scalars. C is an n x n symmetric matrix 
 * consisting of double precision elements and stored in either lower or 
 * upper storage mode. A is a matrix consisting of double precision elements
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the symmetric matrix C is stored in upper or lower 
 *        storage mode as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', C = 
 *        alpha * transpose(A) + beta * C. If trans == 'T', 't', 'C', or 'c', 
 *        C = transpose(A) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  double precision scalar multiplier applied to A * transpose(A) or 
 *        transpose(A) * A.
 * A      double precision array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contains the 
 *        matrix A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at
 *        least max(1, n). Otherwise lda must be at least max(1, k).
 * beta   double precision scalar multiplier applied to C. If beta izs zero, C
 *        does not have to be a valid input
 * C      double precision array of dimensions (ldc, n). If uplo = 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the symmetric matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo = 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the symmetric matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 * ldc    leading dimension of C. It must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * transpose(A) + beta * C, or C = 
 *        alpha * transpose(A) * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/dsyrk.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDsyrk (char uplo, char trans, int n, int k,
                            double alpha, const double *A, int lda,
                            double beta, double *C, int ldc);

/*
 * void 
 * cublasZsyrk (char uplo, char trans, int n, int k, cuDoubleComplex alpha, 
 *              const cuDoubleComplex *A, int lda, cuDoubleComplex beta, cuDoubleComplex *C, int ldc)
 *
 * performs one of the symmetric rank k operations
 * 
 *   C = alpha * A * transpose(A) + beta * C, or 
 *   C = alpha * transpose(A) * A + beta * C.
 *
 * Alpha and beta are double precision complex scalars. C is an n x n symmetric matrix 
 * consisting of double precision complex elements and stored in either lower or 
 * upper storage mode. A is a matrix consisting of double precision complex elements
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the symmetric matrix C is stored in upper or lower 
 *        storage mode as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', C = 
 *        alpha * transpose(A) + beta * C. If trans == 'T', 't', 'C', or 'c', 
 *        C = transpose(A) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  double precision complex scalar multiplier applied to A * transpose(A) or 
 *        transpose(A) * A.
 * A      double precision complex array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contains the 
 *        matrix A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at
 *        least max(1, n). Otherwise lda must be at least max(1, k).
 * beta   double precision complex scalar multiplier applied to C. If beta izs zero, C
 *        does not have to be a valid input
 * C      double precision complex array of dimensions (ldc, n). If uplo = 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the symmetric matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo = 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the symmetric matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 * ldc    leading dimension of C. It must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * transpose(A) + beta * C, or C = 
 *        alpha * transpose(A) * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/zsyrk.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZsyrk (char uplo, char trans, int n, int k,
                            cuDoubleComplex alpha,
                            const cuDoubleComplex *A, int lda,
                            cuDoubleComplex beta,
                            cuDoubleComplex *C, int ldc);
/*
 * void 
 * cublasZsyr2k (char uplo, char trans, int n, int k, cuDoubleComplex alpha, 
 *               const cuDoubleComplex *A, int lda, const cuDoubleComplex *B, int ldb, 
 *               cuDoubleComplex beta, cuDoubleComplex *C, int ldc)
 *
 * performs one of the symmetric rank 2k operations
 * 
 *    C = alpha * A * transpose(B) + alpha * B * transpose(A) + beta * C, or 
 *    C = alpha * transpose(A) * B + alpha * transpose(B) * A + beta * C.
 *
 * Alpha and beta are double precision complex scalars. C is an n x n symmetric matrix
 * consisting of double precision complex elements and stored in either lower or upper 
 * storage mode. A and B are matrices consisting of double precision complex elements 
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the symmetric matrix C is stored in upper or lower
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the symmetric matrix is to be referenced, and the
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the symmetric matrix is to be references, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', 
 *        C = alpha * A * transpose(B) + alpha * B * transpose(A) + beta * C, 
 *        If trans == 'T', 't', 'C', or 'c', C = alpha * transpose(A) * B + 
 *        alpha * transpose(B) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  double precision scalar multiplier.
 * A      double precision array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at 
 *        least max(1, n). Otherwise lda must be at least max(1,k).
 * B      double precision array of dimensions (lda, kb), where kb is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array B must contain the matrix B, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        B.
 * ldb    leading dimension of N. When trans == 'N' or 'n' then ldb must be at
 *        least max(1, n). Otherwise ldb must be at least max(1, k).
 * beta   double precision scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input.
 * C      double precision array of dimensions (ldc, n). If uplo == 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the symmetric matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo == 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the symmetric matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 * ldc    leading dimension of C. Must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to alpha*A*transpose(B) + alpha*B*transpose(A) + 
 *        beta*C or alpha*transpose(A)*B + alpha*transpose(B)*A + beta*C
 *
 * Reference:   http://www.netlib.org/blas/zsyr2k.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZsyr2k (char uplo, char trans, int n, int k,
                             cuDoubleComplex alpha, const cuDoubleComplex *A, int lda,
                             const cuDoubleComplex *B, int ldb, cuDoubleComplex beta,
                             cuDoubleComplex *C, int ldc);
/*
 * void 
 * cublasZher2k (char uplo, char trans, int n, int k, cuDoubleComplex alpha, 
 *               const cuDoubleComplex *A, int lda, const cuDoubleComplex *B, int ldb, 
 *               double beta, cuDoubleComplex *C, int ldc)
 *
 * performs one of the hermitian rank 2k operations
 * 
 *    C =   alpha * A * conjugate(transpose(B)) 
 *        + conjugate(alpha) * B * conjugate(transpose(A))  
 *        + beta * C , 
 *    or 
 *    C =  alpha * conjugate(transpose(A)) * B 
 *       + conjugate(alpha) * conjugate(transpose(B)) * A 
 *       + beta * C.
 *
 * Alpha is double precision complex scalar whereas Beta is a double precision real scalar.
 * C is an n x n hermitian matrix consisting of double precision complex elements and 
 * stored in either lower or upper storage mode. A and B are matrices consisting of 
 * double precision complex elements with dimension of n x k in the first case, 
 * and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the hermitian matrix C is stored in upper or lower
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the hermitian matrix is to be referenced, and the
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the hermitian matrix is to be references, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', 
 *        C =   alpha * A * conjugate(transpose(B)) 
 *            + conjugate(alpha) * B * conjugate(transpose(A))  
 *            + beta * C .
 *        If trans == 'T', 't', 'C', or 'c',
 *        C =  alpha * conjugate(transpose(A)) * B 
 *          + conjugate(alpha) * conjugate(transpose(B)) * A 
 *          + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  double precision scalar multiplier.
 * A      double precision array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at 
 *        least max(1, n). Otherwise lda must be at least max(1,k).
 * B      double precision array of dimensions (lda, kb), where kb is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array B must contain the matrix B, 
 *        otherwise the leading k x n part of the array must contain the matrix
 *        B.
 * ldb    leading dimension of N. When trans == 'N' or 'n' then ldb must be at
 *        least max(1, n). Otherwise ldb must be at least max(1, k).
 * beta   double precision scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input.
 * C      double precision array of dimensions (ldc, n). If uplo == 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the hermitian matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo == 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the hermitian matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 *        The imaginary parts of the diagonal elements need
 *        not be set,  they are assumed to be zero,  and on exit they
 *        are set to zero. 
 * ldc    leading dimension of C. Must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to alpha*A*conjugate(transpose(B)) + 
 *        + conjugate(alpha)*B*conjugate(transpose(A)) + beta*C or
 *        alpha*conjugate(transpose(A))*B + conjugate(alpha)*conjugate(transpose(B))*A
 *        + beta*C.
 *
 * Reference:   http://www.netlib.org/blas/zher2k.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */                             
void CUBLASAPI cublasZher2k (char uplo, char trans, int n, int k,
                             cuDoubleComplex alpha, const cuDoubleComplex *A, int lda,
                             const cuDoubleComplex *B, int ldb, double beta,
                             cuDoubleComplex *C, int ldc);  
                             
/*
 * void 
 * cublasZher (char uplo, int n, double alpha, const cuDoubleComplex *x, int incx, 
 *             cuDoubleComplex *A, int lda)
 *
 * performs the hermitian rank 1 operation
 *
 *    A = alpha * x * conjugate(transpose(x)) + A,
 *
 * where alpha is a double precision real scalar, x is an n element double 
 * precision complex vector and A is an n x n hermitian matrix consisting of 
 * double precision complex elements. Matrix A is stored in column major format,
 * and lda is the leading dimension of the two-dimensional array 
 * containing A.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or 
 *        the lower triangular part of array A. If uplo = 'U' or 'u',
 *        then only the upper triangular part of A may be referenced.
 *        If uplo = 'L' or 'l', then only the lower triangular part of
 *        A may be referenced.
 * n      specifies the number of rows and columns of the matrix A. It
 *        must be at least 0.
 * alpha  double precision real scalar multiplier applied to 
 *        x * conjugate(transpose(x))
 * x      double precision complex array of length at least (1 + (n - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must 
 *        not be zero.
 * A      double precision complex array of dimensions (lda, n). If uplo = 'U' or 
 *        'u', then A must contain the upper triangular part of a hermitian 
 *        matrix, and the strictly lower triangular part is not referenced. 
 *        If uplo = 'L' or 'l', then A contains the lower triangular part 
 *        of a hermitian matrix, and the strictly upper triangular part is 
 *        not referenced. The imaginary parts of the diagonal elements need
 *        not be set, they are assumed to be zero, and on exit they
 *        are set to zero. 
 * lda    leading dimension of the two-dimensional array containing A. lda
 *        must be at least max(1, n).
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * conjugate(transpose(x)) + A
 *
 * Reference: http://www.netlib.org/blas/zher.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or incx == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZher (char uplo, int n, double alpha,
                           const cuDoubleComplex *x, int incx, cuDoubleComplex *A, 
                           int lda); 

/*
 * void 
 * cublasZher (char uplo, int n, double alpha, const cuDoubleComplex *x, int incx, 
 *             cuDoubleComplex *A, int lda)
 *
 * performs the hermitian rank 1 operation
 *
 *    A = alpha * x * conjugate(transpose(x) + A,
 *
 * where alpha is a double precision real scalar, x is an n element double 
 * precision complex vector and A is an n x n hermitian matrix consisting of 
 * double precision complex elements. Matrix A is stored in column major format,
 * and lda is the leading dimension of the two-dimensional array 
 * containing A.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or 
 *        the lower triangular part of array A. If uplo = 'U' or 'u',
 *        then only the upper triangular part of A may be referenced.
 *        If uplo = 'L' or 'l', then only the lower triangular part of
 *        A may be referenced.
 * n      specifies the number of rows and columns of the matrix A. It
 *        must be at least 0.
 * alpha  double precision real scalar multiplier applied to 
 *        x * conjugate(transpose(x))
 * x      double precision complex array of length at least (1 + (n - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must 
 *        not be zero.
 * A      double precision complex array of dimensions (lda, n). If uplo = 'U' or 
 *        'u', then A must contain the upper triangular part of a hermitian 
 *        matrix, and the strictly lower triangular part is not referenced. 
 *        If uplo = 'L' or 'l', then A contains the lower triangular part 
 *        of a hermitian matrix, and the strictly upper triangular part is 
 *        not referenced. The imaginary parts of the diagonal elements need
 *        not be set, they are assumed to be zero, and on exit they
 *        are set to zero. 
 * lda    leading dimension of the two-dimensional array containing A. lda
 *        must be at least max(1, n).
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * conjugate(transpose(x) + A
 *
 * Reference: http://www.netlib.org/blas/zher.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or incx == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZher (char uplo, int n, double alpha, const cuDoubleComplex *x,
                             int incx, cuDoubleComplex *A, int lda); 

/*
 * void 
 * cublasZhpr (char uplo, int n, double alpha, const cuDoubleComplex *x, int incx, 
 *             cuDoubleComplex *AP)
 *
 * performs the hermitian rank 1 operation
 * 
 *    A = alpha * x * conjugate(transpose(x)) + A,
 * 
 * where alpha is a double precision real scalar and x is an n element double 
 * precision complex vector. A is a hermitian n x n matrix consisting of double 
 * precision complex elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array AP. If uplo == 'U' or 'u', then the upper 
 *        triangular part of A is supplied in AP. If uplo == 'L' or 'l', then 
 *        the lower triangular part of A is supplied in AP.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  double precision real scalar multiplier applied to x * conjugate(transpose(x)).
 * x      double precision array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * AP     double precision complex array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *        The imaginary parts of the diagonal elements need not be set, they
 *        are assumed to be zero, and on exit they are set to zero. 
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * conjugate(transpose(x)) + A
 *
 * Reference: http://www.netlib.org/blas/zhpr.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, or incx == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZhpr (char uplo, int n, double alpha,
                           const cuDoubleComplex *x, int incx, cuDoubleComplex *AP); 
                           
/* 
 * void 
 * cublasZhpr2 (char uplo, int n, cuDoubleComplex alpha, const cuDoubleComplex *x, int incx, 
 *              const cuDoubleComplex *y, int incy, cuDoubleComplex *AP)
 *
 * performs the hermitian rank 2 operation
 *
 *    A = alpha*x*conjugate(transpose(y)) + conjugate(alpha)*y*conjugate(transpose(x)) + A,
 *
 * where alpha is a double precision complex scalar, and x and y are n element double 
 * precision complex vectors. A is a hermitian n x n matrix consisting of double 
 * precision complex elements that is supplied in packed form.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array A. If uplo == 'U' or 'u', then only the 
 *        upper triangular part of A may be referenced and the lower triangular
 *        part of A is inferred. If uplo == 'L' or 'l', then only the lower 
 *        triangular part of A may be referenced and the upper triangular part
 *        of A is inferred.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  double precision complex scalar multiplier applied to x * conjugate(transpose(y)) + 
 *        y * conjugate(transpose(x)).
 * x      double precision complex array of length at least (1 + (n - 1) * abs (incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * y      double precision complex array of length at least (1 + (n - 1) * abs (incy)).
 * incy   storage spacing between elements of y. incy must not be zero.
 * AP     double precision complex array with at least ((n * (n + 1)) / 2) elements. If
 *        uplo == 'U' or 'u', the array AP contains the upper triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i <= j, then A[i,j] is stored is AP[i+(j*(j+1)/2)]. If 
 *        uplo == 'L' or 'L', the array AP contains the lower triangular part 
 *        of the hermitian matrix A, packed sequentially, column by column; 
 *        that is, if i >= j, then A[i,j] is stored in AP[i+((2*n-j+1)*j)/2].
 *        The imaginary parts of the diagonal elements need not be set, they
 *        are assumed to be zero, and on exit they are set to zero.  
 *
 * Output
 * ------
 * A      updated according to A = alpha*x*conjugate(transpose(y))
 *                               + conjugate(alpha)*y*conjugate(transpose(x))+A
 *
 * Reference: http://www.netlib.org/blas/zhpr2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZhpr2 (char uplo, int n, cuDoubleComplex alpha,
                            const cuDoubleComplex *x, int incx, const cuDoubleComplex *y,
                            int incy, cuDoubleComplex *AP);                           
                           
/*
 * void cublasZher2 (char uplo, int n, cuDoubleComplex alpha, const cuDoubleComplex *x, int incx, 
 *                   const cuDoubleComplex *y, int incy, cuDoubleComplex *A, int lda)
 *
 * performs the hermitian rank 2 operation
 *
 *    A = alpha*x*conjugate(transpose(y)) + conjugate(alpha)*y*conjugate(transpose(x)) + A,
 *
 * where alpha is a double precision complex scalar, x and y are n element double 
 * precision complex vector and A is an n by n hermitian matrix consisting of double 
 * precision complex elements.
 * 
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the lower
 *        triangular part of array A. If uplo == 'U' or 'u', then only the 
 *        upper triangular part of A may be referenced and the lower triangular
 *        part of A is inferred. If uplo == 'L' or 'l', then only the lower 
 *        triangular part of A may be referenced and the upper triangular part
 *        of A is inferred.
 * n      specifies the number of rows and columns of the matrix A. It must be
 *        at least zero.
 * alpha  double precision complex scalar multiplier applied to x * conjugate(transpose(y)) + 
 *        y * conjugate(transpose(x)).
 * x      double precision array of length at least (1 + (n - 1) * abs (incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * y      double precision array of length at least (1 + (n - 1) * abs (incy)).
 * incy   storage spacing between elements of y. incy must not be zero.
 * A      double precision complex array of dimensions (lda, n). If uplo == 'U' or 'u',
 *        then A must contains the upper triangular part of a hermitian matrix,
 *        and the strictly lower triangular parts is not referenced. If uplo ==
 *        'L' or 'l', then A contains the lower triangular part of a hermitian 
 *        matrix, and the strictly upper triangular part is not referenced.
 *        The imaginary parts of the diagonal elements need not be set, 
 *        they are assumed to be zero, and on exit they are set to zero. 
 *
 * lda    leading dimension of A. It must be at least max(1, n).
 *
 * Output
 * ------
 * A      updated according to A = alpha*x*conjugate(transpose(y))
 *                               + conjugate(alpha)*y*conjugate(transpose(x))+A
 *
 * Reference: http://www.netlib.org/blas/zher2.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support  
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
 void CUBLASAPI cublasZher2 (char uplo, int n, cuDoubleComplex alpha,
                             const cuDoubleComplex *x, int incx, const cuDoubleComplex *y,
                             int incy, cuDoubleComplex *A, int lda);
                                                                                                                                         
/*
 * void
 * cublasDsyr2k (char uplo, char trans, int n, int k, double alpha,
 *               const double *A, int lda, const double *B, int ldb,
 *               double beta, double *C, int ldc)
 *
 * performs one of the symmetric rank 2k operations
 *
 *    C = alpha * A * transpose(B) + alpha * B * transpose(A) + beta * C, or
 *    C = alpha * transpose(A) * B + alpha * transpose(B) * A + beta * C.
 *
 * Alpha and beta are double precision scalars. C is an n x n symmetric matrix
 * consisting of double precision elements and stored in either lower or upper
 * storage mode. A and B are matrices consisting of double precision elements
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the symmetric matrix C is stored in upper or lower
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper
 *        triangular part of the symmetric matrix is to be referenced, and the
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the
 *        lower triangular part of the symmetric matrix is to be references,
 *        and the elements of the strictly upper triangular part are to be
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n',
 *        C = alpha * A * transpose(B) + alpha * B * transpose(A) + beta * C,
 *        If trans == 'T', 't', 'C', or 'c', C = alpha * transpose(A) * B +
 *        alpha * transpose(B) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A.
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of rows of matrix A.
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of
 *        matrix A. k must be at least zero.
 * alpha  double precision scalar multiplier.
 * A      double precision array of dimensions (lda, ka), where ka is k when
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n',
 *        the leading n x k part of array A must contain the matrix A,
 *        otherwise the leading k x n part of the array must contain the matrix
 *        A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at
 *        least max(1, n). Otherwise lda must be at least max(1,k).
 * B      double precision array of dimensions (lda, kb), where kb is k when
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n',
 *        the leading n x k part of array B must contain the matrix B,
 *        otherwise the leading k x n part of the array must contain the matrix
 *        B.
 * ldb    leading dimension of N. When trans == 'N' or 'n' then ldb must be at
 *        least max(1, n). Otherwise ldb must be at least max(1, k).
 * beta   double precision scalar multiplier applied to C. If beta is zero, C
 *        does not have to be a valid input.
 * C      double precision array of dimensions (ldc, n). If uplo == 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the
 *        upper triangular part of the symmetric matrix C and the strictly
 *        lower triangular part of C is not referenced. On exit, the upper
 *        triangular part of C is overwritten by the upper triangular part of
 *        the updated matrix. If uplo == 'L' or 'l', the leading n x n
 *        triangular part of the array C must contain the lower triangular part
 *        of the symmetric matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is
 *        overwritten by the lower triangular part of the updated matrix.
 * ldc    leading dimension of C. Must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to alpha*A*transpose(B) + alpha*B*transpose(A) +
 *        beta*C or alpha*transpose(A)*B + alpha*transpose(B)*A + beta*C
 *
 * Reference:   http://www.netlib.org/blas/dsyr2k.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasDsyr2k (char uplo, char trans, int n, int k,
                             double alpha, const double *A, int lda,
                             const double *B, int ldb, double beta,
                             double *C, int ldc);

/*
 * void cublasZgemm (char transa, char transb, int m, int n, int k,
 *                   cuDoubleComplex alpha, const cuDoubleComplex *A, int lda,
 *                   const cuDoubleComplex *B, int ldb, cuDoubleComplex beta,
 *                   cuDoubleComplex *C, int ldc)
 *
 * zgemm performs one of the matrix-matrix operations
 *
 *    C = alpha * op(A) * op(B) + beta*C,
 *
 * where op(X) is one of
 *
 *    op(X) = X   or   op(X) = transpose  or  op(X) = conjg(transpose(X))
 *
 * alpha and beta are double-complex scalars, and A, B and C are matrices
 * consisting of double-complex elements, with op(A) an m x k matrix, op(B)
 * a k x n matrix and C an m x n matrix.
 *
 * Input
 * -----
 * transa specifies op(A). If transa == 'N' or 'n', op(A) = A. If transa ==
 *        'T' or 't', op(A) = transpose(A). If transa == 'C' or 'c', op(A) =
 *        conjg(transpose(A)).
 * transb specifies op(B). If transa == 'N' or 'n', op(B) = B. If transb ==
 *        'T' or 't', op(B) = transpose(B). If transb == 'C' or 'c', op(B) =
 *        conjg(transpose(B)).
 * m      number of rows of matrix op(A) and rows of matrix C. It must be at
 *        least zero.
 * n      number of columns of matrix op(B) and number of columns of C. It
 *        must be at least zero.
 * k      number of columns of matrix op(A) and number of rows of op(B). It
 *        must be at least zero.
 * alpha  double-complex scalar multiplier applied to op(A)op(B)
 * A      double-complex array of dimensions (lda, k) if transa ==  'N' or
 *        'n'), and of dimensions (lda, m) otherwise.
 * lda    leading dimension of A. When transa == 'N' or 'n', it must be at
 *        least max(1, m) and at least max(1, k) otherwise.
 * B      double-complex array of dimensions (ldb, n) if transb == 'N' or 'n',
 *        and of dimensions (ldb, k) otherwise
 * ldb    leading dimension of B. When transb == 'N' or 'n', it must be at
 *        least max(1, k) and at least max(1, n) otherwise.
 * beta   double-complex scalar multiplier applied to C. If beta is zero, C
 *        does not have to be a valid input.
 * C      double precision array of dimensions (ldc, n)
 * ldc    leading dimension of C. Must be at least max(1, m).
 *
 * Output
 * ------
 * C      updated according to C = alpha*op(A)*op(B) + beta*C
 *
 * Reference: http://www.netlib.org/blas/zgemm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if any of m, n, or k are < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZgemm (char transa, char transb, int m, int n,
                            int k, cuDoubleComplex alpha,
                            const cuDoubleComplex *A, int lda,
                            const cuDoubleComplex *B, int ldb,
                            cuDoubleComplex beta, cuDoubleComplex *C,
                            int ldc);
                            
/*
 * void 
 * cublasZtrmm (char side, char uplo, char transa, char diag, int m, int n, 
 *              cuDoubleComplex alpha, const cuDoubleComplex *A, int lda, const cuDoubleComplex *B, 
 *              int ldb)
 *
 * performs one of the matrix-matrix operations
 *
 *   B = alpha * op(A) * B,  or  B = alpha * B * op(A)
 *
 * where alpha is a double-precision complex scalar, B is an m x n matrix composed
 * of double precision complex elements, and A is a unit or non-unit, upper or lower, 
 * triangular matrix composed of double precision complex elements. op(A) is one of
 *
 *   op(A) = A  , op(A) = transpose(A) or op(A) = conjugate(transpose(A))
 *
 * Matrices A and B are stored in column major format, and lda and ldb are 
 * the leading dimensions of the two-dimensonials arrays that contain A and 
 * B, respectively.
 *
 * Input
 * -----
 * side   specifies whether op(A) multiplies B from the left or right.
 *        If side = 'L' or 'l', then B = alpha * op(A) * B. If side =
 *        'R' or 'r', then B = alpha * B * op(A).
 * uplo   specifies whether the matrix A is an upper or lower triangular
 *        matrix. If uplo = 'U' or 'u', A is an upper triangular matrix.
 *        If uplo = 'L' or 'l', A is a lower triangular matrix.
 * transa specifies the form of op(A) to be used in the matrix 
 *        multiplication. If transa = 'N' or 'n', then op(A) = A. If
 *        transa = 'T' or 't', then op(A) = transpose(A).
 *        If transa = 'C' or 'c', then op(A) = conjugate(transpose(A)).
 * diag   specifies whether or not A is unit triangular. If diag = 'U'
 *        or 'u', A is assumed to be unit triangular. If diag = 'N' or
 *        'n', A is not assumed to be unit triangular.
 * m      the number of rows of matrix B. m must be at least zero.
 * n      the number of columns of matrix B. n must be at least zero.
 * alpha  double precision complex scalar multiplier applied to op(A)*B, or
 *        B*op(A), respectively. If alpha is zero no accesses are made
 *        to matrix A, and no read accesses are made to matrix B.
 * A      double precision complex array of dimensions (lda, k). k = m if side =
 *        'L' or 'l', k = n if side = 'R' or 'r'. If uplo = 'U' or 'u'
 *        the leading k x k upper triangular part of the array A must
 *        contain the upper triangular matrix, and the strictly lower
 *        triangular part of A is not referenced. If uplo = 'L' or 'l'
 *        the leading k x k lower triangular part of the array A must
 *        contain the lower triangular matrix, and the strictly upper
 *        triangular part of A is not referenced. When diag = 'U' or 'u'
 *        the diagonal elements of A are no referenced and are assumed
 *        to be unity.
 * lda    leading dimension of A. When side = 'L' or 'l', it must be at
 *        least max(1,m) and at least max(1,n) otherwise
 * B      double precision complex array of dimensions (ldb, n). On entry, the 
 *        leading m x n part of the array contains the matrix B. It is
 *        overwritten with the transformed matrix on exit.
 * ldb    leading dimension of B. It must be at least max (1, m).
 *
 * Output
 * ------
 * B      updated according to B = alpha * op(A) * B  or B = alpha * B * op(A)
 *
 * Reference: http://www.netlib.org/blas/ztrmm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZtrmm (char side, char uplo, char transa,
                            char diag, int m, int n, cuDoubleComplex alpha,
                            const cuDoubleComplex *A, int lda, cuDoubleComplex *B,
                            int ldb);

/*
 * cublasZgeru (int m, int n, cuDoubleComplex alpha, const cuDoubleComplex *x, int incx, 
 *             const cuDoubleComplex *y, int incy, cuDoubleComplex *A, int lda)
 *
 * performs the symmetric rank 1 operation
 *
 *    A = alpha * x * transpose(y) + A,
 *
 * where alpha is a double precision complex scalar, x is an m element double 
 * precision complex vector, y is an n element double precision complex vector, and A 
 * is an m by n matrix consisting of double precision complex elements. Matrix A
 * is stored in column major format, and lda is the leading dimension of
 * the two-dimensional array used to store A.
 * 
 * Input
 * -----
 * m      specifies the number of rows of the matrix A. It must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. It must be at 
 *        least zero.
 * alpha  double precision complex scalar multiplier applied to x * transpose(y)
 * x      double precision complex array of length at least (1 + (m - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must not
 *        be zero.
 * y      double precision complex array of length at least (1 + (n - 1) * abs(incy))
 * incy   specifies the storage spacing between elements of y. incy must not 
 *        be zero.
 * A      double precision complex array of dimensions (lda, n).
 * lda    leading dimension of two-dimensional array used to store matrix A
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * transpose(y) + A
 *
 * Reference: http://www.netlib.org/blas/zgeru.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m < 0, n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZgeru (int m, int n, cuDoubleComplex alpha, 
                            const cuDoubleComplex *x, int incx, const cuDoubleComplex *y,
                            int incy, cuDoubleComplex *A, int lda);
                            
 
/*
 * cublasZgerc (int m, int n, cuDoubleComplex alpha, const cuDoubleComplex *x, int incx, 
 *             const cuDoubleComplex *y, int incy, cuDoubleComplex *A, int lda)
 *
 * performs the symmetric rank 1 operation
 *
 *    A = alpha * x * conjugate(transpose(y)) + A,
 *
 * where alpha is a double precision complex scalar, x is an m element double 
 * precision complex vector, y is an n element double precision complex vector, and A 
 * is an m by n matrix consisting of double precision complex elements. Matrix A
 * is stored in column major format, and lda is the leading dimension of
 * the two-dimensional array used to store A.
 * 
 * Input
 * -----
 * m      specifies the number of rows of the matrix A. It must be at least 
 *        zero.
 * n      specifies the number of columns of the matrix A. It must be at 
 *        least zero.
 * alpha  double precision complex scalar multiplier applied to x * conjugate(transpose(y))
 * x      double precision array of length at least (1 + (m - 1) * abs(incx))
 * incx   specifies the storage spacing between elements of x. incx must not
 *        be zero.
 * y      double precision complex array of length at least (1 + (n - 1) * abs(incy))
 * incy   specifies the storage spacing between elements of y. incy must not 
 *        be zero.
 * A      double precision complex array of dimensions (lda, n).
 * lda    leading dimension of two-dimensional array used to store matrix A
 *
 * Output
 * ------
 * A      updated according to A = alpha * x * conjugate(transpose(y)) + A
 *
 * Reference: http://www.netlib.org/blas/zgerc.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 * 
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m < 0, n < 0, incx == 0, incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZgerc (int m, int n, cuDoubleComplex alpha, 
                            const cuDoubleComplex *x, int incx, const cuDoubleComplex *y,
                            int incy, cuDoubleComplex *A, int lda);    
                            
/*
 * void 
 * cublasZherk (char uplo, char trans, int n, int k, double alpha, 
 *              const cuDoubleComplex *A, int lda, double beta, cuDoubleComplex *C, int ldc)
 *
 * performs one of the hermitian rank k operations
 * 
 *   C = alpha * A * conjugate(transpose(A)) + beta * C, or 
 *   C = alpha * conjugate(transpose(A)) * A + beta * C.
 *
 * Alpha and beta are double precision scalars. C is an n x n hermitian matrix 
 * consisting of double precision complex elements and stored in either lower or 
 * upper storage mode. A is a matrix consisting of double precision complex elements
 * with dimension of n x k in the first case, and k x n in the second case.
 *
 * Input
 * -----
 * uplo   specifies whether the hermitian matrix C is stored in upper or lower 
 *        storage mode as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the hermitian matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the hermitian matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * trans  specifies the operation to be performed. If trans == 'N' or 'n', C = 
 *        alpha * A * conjugate(transpose(A)) + beta * C. If trans == 'T', 't', 'C', or 'c', 
 *        C = alpha * conjugate(transpose(A)) * A + beta * C.
 * n      specifies the number of rows and the number columns of matrix C. If 
 *        trans == 'N' or 'n', n specifies the number of rows of matrix A. If 
 *        trans == 'T', 't', 'C', or 'c', n specifies the columns of matrix A. 
 *        n must be at least zero.
 * k      If trans == 'N' or 'n', k specifies the number of columns of matrix A. 
 *        If trans == 'T', 't', 'C', or 'c', k specifies the number of rows of 
 *        matrix A. k must be at least zero.
 * alpha  double precision scalar multiplier applied to A * conjugate(transpose(A)) or 
 *        conjugate(transpose(A)) * A.
 * A      double precision complex array of dimensions (lda, ka), where ka is k when 
 *        trans == 'N' or 'n', and is n otherwise. When trans == 'N' or 'n', 
 *        the leading n x k part of array A must contain the matrix A, 
 *        otherwise the leading k x n part of the array must contains the 
 *        matrix A.
 * lda    leading dimension of A. When trans == 'N' or 'n' then lda must be at
 *        least max(1, n). Otherwise lda must be at least max(1, k).
 * beta   double precision scalar multiplier applied to C. If beta is zero, C
 *        does not have to be a valid input
 * C      double precision complex array of dimensions (ldc, n). If uplo = 'U' or 'u',
 *        the leading n x n triangular part of the array C must contain the 
 *        upper triangular part of the hermitian matrix C and the strictly 
 *        lower triangular part of C is not referenced. On exit, the upper 
 *        triangular part of C is overwritten by the upper triangular part of 
 *        the updated matrix. If uplo = 'L' or 'l', the leading n x n 
 *        triangular part of the array C must contain the lower triangular part
 *        of the hermitian matrix C and the strictly upper triangular part of C
 *        is not referenced. On exit, the lower triangular part of C is 
 *        overwritten by the lower triangular part of the updated matrix.
 *        The imaginary parts of the diagonal elements need
 *        not be set,  they are assumed to be zero,  and on exit they
 *        are set to zero.
 * ldc    leading dimension of C. It must be at least max(1, n).
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * conjugate(transpose(A)) + beta * C, or C = 
 *        alpha * conjugate(transpose(A)) * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/zherk.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if n < 0 or k < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZherk (char uplo, char trans, int n, int k,
                            double alpha,
                            const cuDoubleComplex *A, int lda,
                            double beta,
                            cuDoubleComplex *C, int ldc);                                                    

/*
 * void 
 * cublasZhemm (char side, char uplo, int m, int n, cuDoubleComplex alpha, 
 *              const cuDoubleComplex *A, int lda, const cuDoubleComplex *B, int ldb, 
 *              cuDoubleComplex beta, cuDoubleComplex *C, int ldc);
 *
 * performs one of the matrix-matrix operations
 * 
 *   C = alpha * A * B + beta * C, or 
 *   C = alpha * B * A + beta * C,
 *
 * where alpha and beta are double precision complex scalars, A is a hermitian matrix
 * consisting of double precision complex elements and stored in either lower or upper 
 * storage mode, and B and C are m x n matrices consisting of double precision
 * complex elements.
 *
 * Input
 * -----
 * side   specifies whether the hermitian matrix A appears on the left side 
 *        hand side or right hand side of matrix B, as follows. If side == 'L' 
 *        or 'l', then C = alpha * A * B + beta * C. If side = 'R' or 'r', 
 *        then C = alpha * B * A + beta * C.
 * uplo   specifies whether the hermitian matrix A is stored in upper or lower 
 *        storage mode, as follows. If uplo == 'U' or 'u', only the upper 
 *        triangular part of the hermitian matrix is to be referenced, and the 
 *        elements of the strictly lower triangular part are to be infered from
 *        those in the upper triangular part. If uplo == 'L' or 'l', only the 
 *        lower triangular part of the hermitian matrix is to be referenced, 
 *        and the elements of the strictly upper triangular part are to be 
 *        infered from those in the lower triangular part.
 * m      specifies the number of rows of the matrix C, and the number of rows
 *        of matrix B. It also specifies the dimensions of hermitian matrix A 
 *        when side == 'L' or 'l'. m must be at least zero.
 * n      specifies the number of columns of the matrix C, and the number of 
 *        columns of matrix B. It also specifies the dimensions of hermitian 
 *        matrix A when side == 'R' or 'r'. n must be at least zero.
 * alpha  double precision scalar multiplier applied to A * B, or B * A
 * A      double precision complex array of dimensions (lda, ka), where ka is m when 
 *        side == 'L' or 'l' and is n otherwise. If side == 'L' or 'l' the 
 *        leading m x m part of array A must contain the hermitian matrix, 
 *        such that when uplo == 'U' or 'u', the leading m x m part stores the 
 *        upper triangular part of the hermitian matrix, and the strictly lower
 *        triangular part of A is not referenced, and when uplo == 'U' or 'u', 
 *        the leading m x m part stores the lower triangular part of the 
 *        hermitian matrix and the strictly upper triangular part is not 
 *        referenced. If side == 'R' or 'r' the leading n x n part of array A 
 *        must contain the hermitian matrix, such that when uplo == 'U' or 'u',
 *        the leading n x n part stores the upper triangular part of the 
 *        hermitian matrix and the strictly lower triangular part of A is not 
 *        referenced, and when uplo == 'U' or 'u', the leading n x n part 
 *        stores the lower triangular part of the hermitian matrix and the 
 *        strictly upper triangular part is not referenced. The imaginary parts
 *        of the diagonal elements need not be set, they are assumed to be zero.
 *
 * lda    leading dimension of A. When side == 'L' or 'l', it must be at least 
 *        max(1, m) and at least max(1, n) otherwise.
 * B      double precision complex array of dimensions (ldb, n). On entry, the leading
 *        m x n part of the array contains the matrix B.
 * ldb    leading dimension of B. It must be at least max (1, m).
 * beta   double precision complex scalar multiplier applied to C. If beta is zero, C 
 *        does not have to be a valid input
 * C      double precision complex array of dimensions (ldc, n)
 * ldc    leading dimension of C. Must be at least max(1, m)
 *
 * Output
 * ------
 * C      updated according to C = alpha * A * B + beta * C, or C = alpha * 
 *        B * A + beta * C
 *
 * Reference: http://www.netlib.org/blas/zhemm.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if m or n are < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZhemm (char side, char uplo, int m, int n,
                            cuDoubleComplex alpha, const cuDoubleComplex *A, int lda,
                            const cuDoubleComplex *B, int ldb, cuDoubleComplex beta,
                            cuDoubleComplex *C, int ldc);     
                            

/*
 * void 
 * cublasZtrsv (char uplo, char trans, char diag, int n, const cuDoubleComplex *A, 
 *              int lda, cuDoubleComplex *x, int incx)
 *
 * solves a system of equations op(A) * x = b, where op(A) is either A,  
 * transpose(A) or conjugate(transpose(A)). b and x are double precision 
 * complex vectors consisting of n elements, and A is an n x n matrix 
 * composed of a unit or non-unit, upper or lower triangular matrix.
 * Matrix A is stored in column major format, and lda is the leading 
 * dimension of the two-dimensional array containing A.
 *
 * No test for singularity or near-singularity is included in this function. 
 * Such tests must be performed before calling this function.
 *
 * Input
 * -----
 * uplo   specifies whether the matrix data is stored in the upper or the 
 *        lower triangular part of array A. If uplo = 'U' or 'u', then only 
 *        the upper triangular part of A may be referenced. If uplo = 'L' or 
 *        'l', then only the lower triangular part of A may be referenced.
 * trans  specifies op(A). If transa = 'n' or 'N', op(A) = A. If transa = 't',
 *        'T', 'c', or 'C', op(A) = transpose(A)
 * diag   specifies whether or not A is a unit triangular matrix like so:
 *        if diag = 'U' or 'u', A is assumed to be unit triangular. If 
 *        diag = 'N' or 'n', then A is not assumed to be unit triangular.
 * n      specifies the number of rows and columns of the matrix A. It
 *        must be at least 0. 
 * A      is a double precision complex array of dimensions (lda, n). If uplo = 'U' 
 *        or 'u', then A must contains the upper triangular part of a symmetric
 *        matrix, and the strictly lower triangular parts is not referenced. 
 *        If uplo = 'L' or 'l', then A contains the lower triangular part of 
 *        a symmetric matrix, and the strictly upper triangular part is not 
 *        referenced. 
 * lda    is the leading dimension of the two-dimensional array containing A.
 *        lda must be at least max(1, n).
 * x      double precision complex array of length at least (1 + (n - 1) * abs(incx)).
 *        On entry, x contains the n element right-hand side vector b. On exit,
 *        it is overwritten with the solution vector x.
 * incx   specifies the storage spacing between elements of x. incx must not 
 *        be zero.
 *
 * Output
 * ------
 * x      updated to contain the solution vector x that solves op(A) * x = b.
 *
 * Reference: http://www.netlib.org/blas/ztrsv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized
 * CUBLAS_STATUS_INVALID_VALUE    if incx == 0 or if n < 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support 
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZtrsv (char uplo, char trans, char diag, int n, 
                            const cuDoubleComplex *A, int lda, cuDoubleComplex *x, 
                            int incx);
                            
/*
 * void 
 * cublasZhbmv (char uplo, int n, int k, cuDoubleComplex alpha, const cuDoubleComplex *A, int lda,
 *              const cuDoubleComplex *x, int incx, cuDoubleComplex beta, cuDoubleComplex *y, int incy)
 *
 * performs the matrix-vector operation
 *
 *     y := alpha*A*x + beta*y
 *
 * alpha and beta are double precision complex scalars. x and y are double precision
 * complex vectors with n elements. A is an n by n hermitian band matrix consisting 
 * of double precision complex elements, with k super-diagonals and the same number
 * of subdiagonals.
 *
 * Input
 * -----
 * uplo   specifies whether the upper or lower triangular part of the hermitian
 *        band matrix A is being supplied. If uplo == 'U' or 'u', the upper 
 *        triangular part is being supplied. If uplo == 'L' or 'l', the lower 
 *        triangular part is being supplied.
 * n      specifies the number of rows and the number of columns of the
 *        hermitian matrix A. n must be at least zero.
 * k      specifies the number of super-diagonals of matrix A. Since the matrix
 *        is hermitian, this is also the number of sub-diagonals. k must be at
 *        least zero.
 * alpha  double precision complex scalar multiplier applied to A*x.
 * A      double precision complex array of dimensions (lda, n). When uplo == 'U' or 
 *        'u', the leading (k + 1) x n part of array A must contain the upper
 *        triangular band of the hermitian matrix, supplied column by column,
 *        with the leading diagonal of the matrix in row (k+1) of the array,
 *        the first super-diagonal starting at position 2 in row k, and so on.
 *        The top left k x k triangle of the array A is not referenced. When
 *        uplo == 'L' or 'l', the leading (k + 1) x n part of the array A must
 *        contain the lower triangular band part of the hermitian matrix, 
 *        supplied column by column, with the leading diagonal of the matrix in
 *        row 1 of the array, the first sub-diagonal starting at position 1 in
 *        row 2, and so on. The bottom right k x k triangle of the array A is
 *        not referenced. The imaginary parts of the diagonal elements need 
 *        not be set, they are assumed to be zero. 
 * lda    leading dimension of A. lda must be at least (k + 1).
 * x      double precision complex array of length at least (1 + (n - 1) * abs(incx)).
 * incx   storage spacing between elements of x. incx must not be zero.
 * beta   double precision complex scalar multiplier applied to vector y. If beta is 
 *        zero, y is not read.
 * y      double precision complex array of length at least (1 + (n - 1) * abs(incy)). 
 *        If beta is zero, y is not read.
 * incy   storage spacing between elements of y. incy must not be zero.
 *
 * Output
 * ------
 * y      updated according to alpha*A*x + beta*y
 *
 * Reference: http://www.netlib.org/blas/zhbmv.f
 *
 * Error status for this function can be retrieved via cublasGetError().
 *
 * Error Status
 * ------------
 * CUBLAS_STATUS_NOT_INITIALIZED  if CUBLAS library has not been initialized 
 * CUBLAS_STATUS_INVALID_VALUE    if k or n < 0, or if incx or incy == 0
 * CUBLAS_STATUS_ARCH_MISMATCH    if invoked on device without DP support   
 * CUBLAS_STATUS_EXECUTION_FAILED if function failed to launch on GPU
 */
void CUBLASAPI cublasZhbmv (char uplo, int n, int k, cuDoubleComplex alpha, 
                            const cuDoubleComplex *A, int lda, const cuDoubleComplex *x, 
                            int incx, cuDoubleComplex beta, cuDoubleComplex *y, int incy);                                                                                                                                       
#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* !defined(CUBLAS_H_) */
