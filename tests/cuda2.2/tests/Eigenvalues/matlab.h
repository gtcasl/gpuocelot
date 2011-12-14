/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
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

/* Header for utility functionality.
* Host code.
*/

#ifndef _MATLAB_H_
#define _MATLAB_H_

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project

///////////////////////////////////////////////////////////////////////////////
//! Write a tridiagonal, symmetric matrix in vector representation and
//! it's eigenvalues
//! @param  filename  name of output file
//! @param  d  diagonal entries of the matrix
//! @param  s  superdiagonal entries of the matrix (len = n - 1)
//! @param  eigenvals  eigenvalues of the matrix
//! @param  indices  vector of len n containing the position of the eigenvalues
//!                  if these are sorted in ascending order
//! @param  n  size of the matrix
///////////////////////////////////////////////////////////////////////////////
extern "C"
void
writeTridiagSymMatlab( const char* filename,
                       float* d, float* s, 
                       float* eigenvals, 
                       const unsigned int n );

///////////////////////////////////////////////////////////////////////////////
//! Write matrix to a file in Matlab format
//! @param  file  file handle to which to write he matrix
//! @param  mat_name  name of matrix in Matlab
//! @param  mat  matrix to write to the file
//! @param  mat_size  size of the (square) matrix \a mat
///////////////////////////////////////////////////////////////////////////////
template<class T, class S>
void
writeMatrixMatlab( T& file,  const char* mat_name, 
                   S* &mat, const unsigned int mat_size  );

///////////////////////////////////////////////////////////////////////////////
//! Write vector to a file in Matlab format
//! @param  file  file handle to which to write he matrix
//! @param  vec_name  name of vector in Matlab
//! @param  vec  matrix to write to the file
//! @param  vec_len  length of the vector
///////////////////////////////////////////////////////////////////////////////
template<class T, class S>
void
writeVectorMatlab( T& file,  const char* vec_name, 
                   S* &vec, const unsigned int vec_len );

// implementations

///////////////////////////////////////////////////////////////////////////////
//! Write matrix to a file in Matlab format
//! @param  file  file handle to which to write he matrix
//! @param  mat_name  name of matrix in Matlab
//! @param  mat  matrix to write to the file
//! @param  mat_size  size of the (square) matrix \a mat
///////////////////////////////////////////////////////////////////////////////
template<class T, class S>
void
writeMatrixMatlab( T& file,  const char* mat_name, 
                   S* &mat, const unsigned int mat_size  )  {
  
  const unsigned int pitch = sizeof(S) * mat_size;

  file << mat_name << " = [";
  for( unsigned int i = 0; i < mat_size; ++i) {
    for( unsigned int j = 0; j < mat_size; ++j) {

      file << getMatrix( mat, pitch, i, j)  << " ";
    }
    if( i != mat_size - 1) {
      file << "; ";
    }
  }
  file << "];\n";
}

///////////////////////////////////////////////////////////////////////////////
//! Write vector to a file in Matlab format
//! @param  file  file handle to which to write he matrix
//! @param  vec_name  name of vector in Matlab
//! @param  vec  matrix to write to the file
//! @param  vec_len  length of the vector
///////////////////////////////////////////////////////////////////////////////
template<class T, class S>
void
writeVectorMatlab( T& file,  const char* vec_name, 
                   S* &vec, const unsigned int vec_len )
{
  file << vec_name << " = [";
  for( unsigned int i = 0; i < vec_len; ++i) {
    file << vec[i] << " ";
  }
  file << "];\n";
}

#endif // _MATLAB_H_


