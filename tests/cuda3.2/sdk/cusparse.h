/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and
 * international Copyright laws.  
 *
 * This software and the information contained herein is being provided 
 * under the terms and conditions of a Source Code License Agreement.     
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
 */
 
#if !defined(CUSPARSE_H_)
#define CUSPARSE_H_

#ifndef CUSPARSEAPI
#ifdef _WIN32
#define CUSPARSEAPI __stdcall
#else
#define CUSPARSEAPI 
#endif
#endif

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#include "driver_types.h"
#include "cuComplex.h"   /* import complex data type */

/* CUSPARSE status type returns */
typedef enum{
    CUSPARSE_STATUS_SUCCESS=0,
    CUSPARSE_STATUS_NOT_INITIALIZED=1,
    CUSPARSE_STATUS_ALLOC_FAILED=2,
    CUSPARSE_STATUS_INVALID_VALUE=3,
    CUSPARSE_STATUS_ARCH_MISMATCH=4,
    CUSPARSE_STATUS_MAPPING_ERROR=5,
    CUSPARSE_STATUS_EXECUTION_FAILED=6,
    CUSPARSE_STATUS_INTERNAL_ERROR=7,
    CUSPARSE_STATUS_MATRIX_TYPE_NOT_SUPPORTED=8
} cusparseStatus_t;

/* Opaque structure */
struct cusparseContext;
typedef struct cusparseContext *cusparseHandle_t;

cusparseStatus_t CUSPARSEAPI cusparseCreate (cusparseHandle_t *handle);
cusparseStatus_t CUSPARSEAPI cusparseDestroy (cusparseHandle_t handle);
cusparseStatus_t CUSPARSEAPI cusparseGetVersion(cusparseHandle_t handle, int *version);
cusparseStatus_t CUSPARSEAPI cusparseSetKernelStream (cusparseHandle_t handle, cudaStream_t streamId); 

/* In general (for details please refer to documentation of every function):  
   m,n,k represent the dimensions of the input matrix and vectors, 
   nnz represents the number of non-zero elements in the input matrix,
   idxBase indicates if one- or zero-based indices are used, and 
   copyValues indicates if the array of values is touched.  
*/    


/* Types definitions */

//General matrix descriptor similar to other sparse APIs, where we currently
//support only a subset of the allowed values.

typedef enum {
    CUSPARSE_MATRIX_TYPE_GENERAL=0, 
    CUSPARSE_MATRIX_TYPE_SYMMETRIC=1,     
    CUSPARSE_MATRIX_TYPE_HERMITIAN=2, 
    CUSPARSE_MATRIX_TYPE_TRIANGULAR=3, 
} cusparseMatrixType_t;

typedef enum {
    CUSPARSE_FILL_MODE_LOWER=0, 
    CUSPARSE_FILL_MODE_UPPER=1
} cusparseFillMode_t;

typedef enum {
    CUSPARSE_DIAG_TYPE_NON_UNIT=0, 
    CUSPARSE_DIAG_TYPE_UNIT=1
} cusparseDiagType_t; 

typedef enum {
    CUSPARSE_INDEX_BASE_ZERO=0, 
    CUSPARSE_INDEX_BASE_ONE=1
} cusparseIndexBase_t;

typedef enum {
    CUSPARSE_OPERATION_NON_TRANSPOSE=0,  
    CUSPARSE_OPERATION_TRANSPOSE=1,  
    CUSPARSE_OPERATION_CONJUGATE_TRANSPOSE=2  
} cusparseOperation_t;

typedef enum {
    CUSPARSE_DIRECTION_ROW=0,  
    CUSPARSE_DIRECTION_COLUMN=1  
} cusparseDirection_t;


struct cusparseMatDescr;
typedef struct cusparseMatDescr *cusparseMatDescr_t;

 
// Returns a matrix descriptor initialized to: CUSPARSE_MATRIX_TYPE_GENERAL, CUSPARSE_INDEX_BASE_ZERO
// Other fields are uninitialized                                   
cusparseStatus_t CUSPARSEAPI cusparseCreateMatDescr(cusparseMatDescr_t *descrA);
cusparseStatus_t CUSPARSEAPI cusparseDestroyMatDescr (cusparseMatDescr_t descrA);

cusparseStatus_t CUSPARSEAPI cusparseSetMatType(cusparseMatDescr_t descrA, cusparseMatrixType_t type);
cusparseMatrixType_t CUSPARSEAPI cusparseGetMatType(const cusparseMatDescr_t descrA);

// type must be _GENERAL, _SYMMETRIC, _HERMITIAN, or _TRIANGULAR
cusparseStatus_t CUSPARSEAPI cusparseSetMatFillMode(cusparseMatDescr_t descrA, cusparseFillMode_t fillMode);
cusparseFillMode_t CUSPARSEAPI cusparseGetMatFillMode(const cusparseMatDescr_t descrA);
 
// type must be _TRIANGULAR
cusparseStatus_t CUSPARSEAPI cusparseSetMatDiagType(cusparseMatDescr_t  descrA, cusparseDiagType_t diagType);
cusparseDiagType_t CUSPARSEAPI cusparseGetMatDiagType(const cusparseMatDescr_t descrA);

cusparseStatus_t CUSPARSEAPI cusparseSetMatIndexBase(cusparseMatDescr_t descrA, cusparseIndexBase_t base);
cusparseIndexBase_t CUSPARSEAPI cusparseGetMatIndexBase(const cusparseMatDescr_t descrA);


/* Sparse Level 1 functions */

//Adds a scalar multiple of compressed sparse vector to a 
//full-storage vector 
cusparseStatus_t CUSPARSEAPI cusparseSaxpyi(cusparseHandle_t handle, 
                                            int nnz, 
                                            float alpha, 
                                            const float *xVal, 
                                            const int *xInd, 
                                            float *y, 
                                            cusparseIndexBase_t idxBase);
    
cusparseStatus_t CUSPARSEAPI cusparseDaxpyi(cusparseHandle_t handle, 
                                            int nnz, 
                                            double alpha, 
                                            const double *xVal, 
                                            const int *xInd, 
                                            double *y, 
                                            cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseCaxpyi(cusparseHandle_t handle, 
                                            int nnz, 
                                            cuComplex alpha, 
                                            const cuComplex *xVal, 
                                            const int *xInd, 
                                            cuComplex *y, 
                                            cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseZaxpyi(cusparseHandle_t handle, 
                                            int nnz, 
                                            cuDoubleComplex alpha, 
                                            const cuDoubleComplex *xVal, 
                                            const int *xInd, 
                                            cuDoubleComplex *y, 
                                            cusparseIndexBase_t idxBase);

//Computes the dot product of a compressed sparse real vector 
//with a full-storage real vector.
cusparseStatus_t CUSPARSEAPI cusparseSdoti(cusparseHandle_t handle,  
                                           int nnz, 
                                           const float *xVal, 
                                           const int *xInd, 
                                           const float *y,
                                           float *resultHostPtr, 
                                           cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseDdoti(cusparseHandle_t handle, 
                                           int nnz, 
                                           const double *xVal, 
                                           const int *xInd, 
                                           const double *y, 
                                           double *resultHostPtr, 
                                           cusparseIndexBase_t idxBase);

//Computes the dot product of a compressed sparse complex vector with 
//a full-storage complex vector.
cusparseStatus_t CUSPARSEAPI cusparseCdoti(cusparseHandle_t handle, 
                                            int nnz, 
                                            const cuComplex *xVal, 
                                            const int *xInd, 
                                            const cuComplex *y, 
                                            cuComplex *resultHostPtr, 
                                            cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseZdoti(cusparseHandle_t handle, 
                                            int nnz, 
                                            const cuDoubleComplex *xVal, 
                                            const int *xInd, 
                                            const cuDoubleComplex *y, 
                                            cuDoubleComplex *resultHostPtr, 
                                            cusparseIndexBase_t idxBase);

//Computes the conjugated dot product of a compressed sparse complex 
//vector with a full-storage complex vector.
cusparseStatus_t CUSPARSEAPI cusparseCdotci(cusparseHandle_t handle, 
                                            int nnz, 
                                            const cuComplex *xVal, 
                                            const int *xInd, 
                                            const cuComplex *y, 
                                            cuComplex *resultHostPtr, 
                                            cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseZdotci(cusparseHandle_t handle, 
                                            int nnz, 
                                            const cuDoubleComplex *xVal, 
                                            const int *xInd, 
                                            const cuDoubleComplex *y, 
                                            cuDoubleComplex *resultHostPtr, 
                                            cusparseIndexBase_t idxBase);


//Gathers a full-storage sparse vector's elements into compressed form.
cusparseStatus_t CUSPARSEAPI cusparseSgthr(cusparseHandle_t handle, 
                                           int nnz, 
                                           const float *y, 
                                           float *xVal, 
                                           const int *xInd, 
                                           cusparseIndexBase_t idxBase);
    
cusparseStatus_t CUSPARSEAPI cusparseDgthr(cusparseHandle_t handle, 
                                           int nnz, 
                                           const double *y, 
                                           double *xVal, 
                                           const int *xInd, 
                                           cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseCgthr(cusparseHandle_t handle, 
                                           int nnz, 
                                           const cuComplex *y, 
                                           cuComplex *xVal, 
                                           const int *xInd, 
                                           cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseZgthr(cusparseHandle_t handle, 
                                           int nnz, 
                                           const cuDoubleComplex *y, 
                                           cuDoubleComplex *xVal, 
                                           const int *xInd, 
                                           cusparseIndexBase_t idxBase);

//Gathers a non-zero elements from full-storage vector y into 
//compressed sparse vector x, and replaces these elements in y by zeros.
cusparseStatus_t CUSPARSEAPI cusparseSgthrz(cusparseHandle_t handle, 
                                            int nnz, 
                                            float *y, 
                                            float *xVal, 
                                            const int *xInd, 
                                            cusparseIndexBase_t idxBase);
    
cusparseStatus_t CUSPARSEAPI cusparseDgthrz(cusparseHandle_t handle, 
                                            int nnz, 
                                            double *y, 
                                            double *xVal, 
                                            const int *xInd, 
                                            cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseCgthrz(cusparseHandle_t handle, 
                                            int nnz, 
                                            cuComplex *y, 
                                            cuComplex *xVal, 
                                            const int *xInd, 
                                            cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseZgthrz(cusparseHandle_t handle, 
                                            int nnz, 
                                            cuDoubleComplex *y, 
                                            cuDoubleComplex *xVal, 
                                            const int *xInd, 
                                            cusparseIndexBase_t idxBase);

//Scatters elements od compressed sparse vector x into 
//full-storage vector y.
cusparseStatus_t CUSPARSEAPI cusparseSsctr(cusparseHandle_t handle, 
                                           int nnz, 
                                           const float *xVal, 
                                           const int *xInd, 
                                           float *y, 
                                           cusparseIndexBase_t idxBase);
    
cusparseStatus_t CUSPARSEAPI cusparseDsctr(cusparseHandle_t handle, 
                                           int nnz, 
                                           const double *xVal, 
                                           const int *xInd, 
                                           double *y, 
                                           cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseCsctr(cusparseHandle_t handle, 
                                           int nnz, 
                                           const cuComplex *xVal, 
                                           const int *xInd, 
                                           cuComplex *y, 
                                           cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseZsctr(cusparseHandle_t handle, 
                                           int nnz, 
                                           const cuDoubleComplex *xVal, 
                                           const int *xInd, 
                                           cuDoubleComplex *y, 
                                           cusparseIndexBase_t idxBase);


//Performs Givens rotation
cusparseStatus_t CUSPARSEAPI cusparseSroti(cusparseHandle_t handle, 
                                           int nnz, 
                                           float *xVal, 
                                           const int *xInd, 
                                           float *y, 
                                           float c, 
                                           float s, 
                                           cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseDroti(cusparseHandle_t handle, 
                                           int nnz, 
                                           double *xVal, 
                                           const int *xInd, 
                                           double *y, 
                                           double c, 
                                           double s, 
                                           cusparseIndexBase_t idxBase);


/* Sparse Level 2 functions */

//Matrix-vector multiplication  y = alpha * op(A) * x  + beta * y, 
//where A is a sparse matrix, x and y are dense vectors     
cusparseStatus_t CUSPARSEAPI cusparseScsrmv(cusparseHandle_t handle,
                                            cusparseOperation_t transA, 
                                            int m, 
                                            int n, 
                                            float alpha,
                                            const cusparseMatDescr_t descrA, 
                                            const float *csrValA, 
                                            const int *csrRowPtrA, 
                                            const int *csrColIndA, 
                                            const float *x, 
                                            float beta, 
                                            float *y);
    
cusparseStatus_t CUSPARSEAPI cusparseDcsrmv(cusparseHandle_t handle,
                                            cusparseOperation_t transA, 
                                            int m, 
                                            int n, 
                                            double alpha,
                                            const cusparseMatDescr_t descrA, 
                                            const double *csrValA, 
                                            const int *csrRowPtrA, 
                                            const int *csrColIndA, 
                                            const double *x, 
                                            double beta,  
                                            double *y);

cusparseStatus_t CUSPARSEAPI cusparseCcsrmv(cusparseHandle_t handle,
                                            cusparseOperation_t transA, 
                                            int m, 
                                            int n, 
                                            cuComplex alpha,
                                            const cusparseMatDescr_t descrA, 
                                            const cuComplex *csrValA, 
                                            const int *csrRowPtrA, 
                                            const int *csrColIndA, 
                                            const cuComplex *x, 
                                            cuComplex beta, 
                                            cuComplex *y);

cusparseStatus_t CUSPARSEAPI cusparseZcsrmv(cusparseHandle_t handle,
                                            cusparseOperation_t transA, 
                                            int m, 
                                            int n, 
                                            cuDoubleComplex alpha,
                                            const cusparseMatDescr_t descrA, 
                                            const cuDoubleComplex *csrValA, 
                                            const int *csrRowPtrA, 
                                            const int *csrColIndA, 
                                            const cuDoubleComplex *x, 
                                            cuDoubleComplex beta, 
                                            cuDoubleComplex *y);                    
                 
/* Sparse Level 3 functions */           
 
//Matrix-matrix multiplication C = alpha * op(A) * B  + beta * C, 
//where A is a sparse matrix, B and C are dense matrices                 
cusparseStatus_t CUSPARSEAPI cusparseScsrmm(cusparseHandle_t handle,
                                            cusparseOperation_t transA, 
                                            int m, 
                                            int n, 
                                            int k,  
                                            float alpha,
                                            const cusparseMatDescr_t descrA, 
                                            const float  *csrValA, 
                                            const int *csrRowPtrA, 
                                            const int *csrColIndA, 
                                            const float *B, 
                                            int ldb, 
                                            float beta, 
                                            float *C, 
                                            int ldc);
                     
cusparseStatus_t CUSPARSEAPI cusparseDcsrmm(cusparseHandle_t handle,
                                            cusparseOperation_t transA, 
                                            int m, 
                                            int n, 
                                            int k,  
                                            double alpha,
                                            const cusparseMatDescr_t descrA, 
                                            const double *csrValA, 
                                            const int *csrRowPtrA, 
                                            const int *csrColIndA, 
                                            const double *B, 
                                            int ldb, 
                                            double beta, 
                                            double *C, 
                                            int ldc);
                     
cusparseStatus_t CUSPARSEAPI cusparseCcsrmm(cusparseHandle_t handle,
                                            cusparseOperation_t transA, 
                                            int m, 
                                            int n, 
                                            int k,  
                                            cuComplex alpha,
                                            const cusparseMatDescr_t descrA, 
                                            const cuComplex  *csrValA, 
                                            const int *csrRowPtrA, 
                                            const int *csrColIndA, 
                                            const cuComplex *B, 
                                            int ldb, 
                                            cuComplex beta, 
                                            cuComplex *C, 
                                            int ldc);
                     
cusparseStatus_t CUSPARSEAPI cusparseZcsrmm(cusparseHandle_t handle,
                                            cusparseOperation_t transA, 
                                            int m, 
                                            int n, 
                                            int k,  
                                            cuDoubleComplex alpha,
                                            const cusparseMatDescr_t descrA, 
                                            const cuDoubleComplex  *csrValA, 
                                            const int *csrRowPtrA, 
                                            const int *csrColIndA, 
                                            const cuDoubleComplex *B, 
                                            int ldb, 
                                            cuDoubleComplex beta, 
                                            cuDoubleComplex *C, 
                                            int ldc);                                                               
                    
/* Sparse Format Conversion */
cusparseStatus_t CUSPARSEAPI cusparseSnnz(cusparseHandle_t handle, 
                                          cusparseDirection_t dirA, 
                                          int m, 
                                          int n, 
                                          const cusparseMatDescr_t  descrA,
                                          const float *A, 
                                          int lda, 
                                          int *nnzPerRowCol, 
                                          int *nnzHostPtr);

cusparseStatus_t CUSPARSEAPI cusparseDnnz(cusparseHandle_t handle, 
                                          cusparseDirection_t dirA,  
                                          int m, 
                                          int n, 
                                          const cusparseMatDescr_t  descrA,
                                          const double *A, 
                                          int lda, 
                                          int *nnzPerRowCol, 
                                          int *nnzHostPtr);

cusparseStatus_t CUSPARSEAPI cusparseCnnz(cusparseHandle_t handle, 
                                          cusparseDirection_t dirA,  
                                          int m, 
                                          int n, 
                                          const cusparseMatDescr_t  descrA,
                                          const cuComplex *A,
                                          int lda, 
                                          int *nnzPerRowCol, 
                                          int *nnzHostPtr);

cusparseStatus_t CUSPARSEAPI cusparseZnnz(cusparseHandle_t handle, 
                                          cusparseDirection_t dirA,  
                                          int m, 
                                          int n, 
                                          const cusparseMatDescr_t  descrA,
                                          const cuDoubleComplex *A,
                                          int lda, 
                                          int *nnzPerRowCol, 
                                          int *nnzHostPtr);
                                                                                                        
//Dense to CSR                           
cusparseStatus_t CUSPARSEAPI cusparseSdense2csr(cusparseHandle_t handle,
                                                int m, 
                                                int n,  
                                                const cusparseMatDescr_t descrA,                            
                                                const float *A, 
                                                int lda,
                                                const int *nnzPerRow,                                                 
                                                float *csrValA, 
                                                int *csrRowPtrA, 
                                                int *csrColIndA);
 
cusparseStatus_t CUSPARSEAPI cusparseDdense2csr(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA,                                     
                                                const double *A, 
                                                int lda, 
                                                const int *nnzPerRow,                                                 
                                                double *csrValA, 
                                                int *csrRowPtrA, 
                                                int *csrColIndA);
    
cusparseStatus_t CUSPARSEAPI cusparseCdense2csr(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA,                                     
                                                const cuComplex *A, 
                                                int lda, 
                                                const int *nnzPerRow,                                                 
                                                cuComplex *csrValA, 
                                                int *csrRowPtrA, 
                                                int *csrColIndA);
 
cusparseStatus_t CUSPARSEAPI cusparseZdense2csr(cusparseHandle_t handle,
                                                int m, 
                                                int n,  
                                                const cusparseMatDescr_t descrA,                                    
                                                const cuDoubleComplex *A, 
                                                int lda, 
                                                const int *nnzPerRow,                                                 
                                                cuDoubleComplex *csrValA, 
                                                int *csrRowPtrA, 
                                                int *csrColIndA);

//CSR to Dense                          
cusparseStatus_t CUSPARSEAPI cusparseScsr2dense(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA,  
                                                const float *csrValA, 
                                                const int *csrRowPtrA, 
                                                const int *csrColIndA,
                                                float *A, 
                                                int lda);

cusparseStatus_t CUSPARSEAPI cusparseDcsr2dense(cusparseHandle_t handle, 
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA, 
                                                const double *csrValA, 
                                                const int *csrRowPtrA, 
                                                const int *csrColIndA,
                                                double *A, 
                                                int lda);

cusparseStatus_t CUSPARSEAPI cusparseCcsr2dense(cusparseHandle_t handle, 
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA, 
                                                const cuComplex *csrValA, 
                                                const int *csrRowPtrA, 
                                                const int *csrColIndA,
                                                cuComplex *A, 
                                                int lda);

cusparseStatus_t CUSPARSEAPI cusparseZcsr2dense(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA, 
                                                const cuDoubleComplex *csrValA, 
                                                const int *csrRowPtrA, 
                                                const int *csrColIndA,
                                                cuDoubleComplex *A, 
                                                int lda); 
                                 
//Dense to CSC                           
cusparseStatus_t CUSPARSEAPI cusparseSdense2csc(cusparseHandle_t handle,
                                                int m, 
                                                int n,  
                                                const cusparseMatDescr_t descrA,                            
                                                const float *A, 
                                                int lda,
                                                const int *nnzPerCol,                                                 
                                                float *cscValA, 
                                                int *cscRowIndA, 
                                                int *cscColPtrA);
 
cusparseStatus_t CUSPARSEAPI cusparseDdense2csc(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA,                                     
                                                const double *A, 
                                                int lda,
                                                const int *nnzPerCol,                                                
                                                double *cscValA, 
                                                int *cscRowIndA, 
                                                int *cscColPtrA); 

cusparseStatus_t CUSPARSEAPI cusparseCdense2csc(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA,                                     
                                                const cuComplex *A, 
                                                int lda, 
                                                const int *nnzPerCol,                                                 
                                                cuComplex *cscValA, 
                                                int *cscRowIndA, 
                                                int *cscColPtrA);
 
cusparseStatus_t CUSPARSEAPI cusparseZdense2csc(cusparseHandle_t handle,
                                                int m, 
                                                int n,  
                                                const 
                                                cusparseMatDescr_t descrA,                                    
                                                const cuDoubleComplex *A, 
                                                int lda, 
                                                const int *nnzPerCol,
                                                cuDoubleComplex *cscValA, 
                                                int *cscRowIndA, 
                                                int *cscColPtrA);

//CSC to Dense                          
cusparseStatus_t CUSPARSEAPI cusparseScsc2dense(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA,  
                                                const float *cscValA, 
                                                const int *cscRowIndA, 
                                                const int *cscColPtrA,
                                                float *A, 
                                                int lda);
    
cusparseStatus_t CUSPARSEAPI cusparseDcsc2dense(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA, 
                                                const double *cscValA, 
                                                const int *cscRowIndA, 
                                                const int *cscColPtrA,
                                                double *A, 
                                                int lda);

cusparseStatus_t CUSPARSEAPI cusparseCcsc2dense(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA, 
                                                const cuComplex *cscValA, 
                                                const int *cscRowIndA, 
                                                const int *cscColPtrA,
                                                cuComplex *A, 
                                                int lda);

cusparseStatus_t CUSPARSEAPI cusparseZcsc2dense(cusparseHandle_t handle,
                                                int m, 
                                                int n, 
                                                const cusparseMatDescr_t descrA, 
                                                const cuDoubleComplex *cscValA, 
                                                const int *cscRowIndA, 
                                                const int *cscColPtrA,
                                                cuDoubleComplex *A, 
                                                int lda);                                                                                                                                    

//COO to CSR, CSR to COO                         
cusparseStatus_t CUSPARSEAPI cusparseXcoo2csr(cusparseHandle_t handle,
                                              const int *cooRowInd, 
                                              int nnz, 
                                              int m, 
                                              int *csrRowPtr, 
                                              cusparseIndexBase_t idxBase);
    
cusparseStatus_t CUSPARSEAPI cusparseXcsr2coo(cusparseHandle_t handle,
                                              const int *csrRowPtr, 
                                              int nnz, 
                                              int m, 
                                              int *cooRowInd, 
                                              cusparseIndexBase_t idxBase);     

//CSR to CSC  (transpose)       
cusparseStatus_t CUSPARSEAPI cusparseScsr2csc(cusparseHandle_t handle,
                                              int m, 
                                              int n, 
                                              const float  *csrVal, 
                                              const int *csrRowPtr, 
                                              const int *csrColInd, 
                                              float *cscVal, 
                                              int *cscRowInd, 
                                              int *cscColPtr, 
                                              int copyValues, 
                                              cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseDcsr2csc(cusparseHandle_t handle,
                                              int m, 
                                              int n,
                                              const double  *csrVal, 
                                              const int *csrRowPtr, 
                                              const int *csrColInd,
                                              double *cscVal, 
                                              int *cscRowInd, 
                                              int *cscColPtr,
                                              int copyValues, 
                                              cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseCcsr2csc(cusparseHandle_t handle,
                                              int m, 
                                              int n,
                                              const cuComplex  *csrVal, 
                                              const int *csrRowPtr, 
                                              const int *csrColInd,
                                              cuComplex *cscVal, 
                                              int *cscRowInd, 
                                              int *cscColPtr, 
                                              int copyValues, 
                                              cusparseIndexBase_t idxBase);

cusparseStatus_t CUSPARSEAPI cusparseZcsr2csc(cusparseHandle_t handle,
                                              int m, 
                                              int n, 
                                              const cuDoubleComplex *csrVal, 
                                              const int *csrRowPtr, 
                                              const int *csrColInd, 
                                              cuDoubleComplex *cscVal, 
                                              int *cscRowInd, 
                                              int *cscColPtr,
                                              int copyValues, 
                                              cusparseIndexBase_t idxBase);
                                                     

#if defined(__cplusplus)
}
#endif /* __cplusplus */                         
                         
                         
#endif /* CUSPARSE_H_ */
