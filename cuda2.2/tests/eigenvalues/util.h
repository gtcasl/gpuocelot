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

/* Utility functions */

#ifndef _UTIL_H_
#define _UTIL_H_

////////////////////////////////////////////////////////////////////////////////
//! Safely free() for pointer
////////////////////////////////////////////////////////////////////////////////
template<class T>
inline void
freePtr( T* &ptr) {

  if( NULL != ptr) {
    free( ptr);
    ptr = NULL;
  }
}

////////////////////////////////////////////////////////////////////////////////
//! Minimum
////////////////////////////////////////////////////////////////////////////////
template<class T>
#ifdef __CUDACC__
__host__  __device__
#endif 
T
min( const T& lhs, const T& rhs) {

  return (lhs < rhs) ? lhs : rhs;
}

////////////////////////////////////////////////////////////////////////////////
//! Maximum
////////////////////////////////////////////////////////////////////////////////
template<class T>
#ifdef __CUDACC__
__host__  __device__
#endif
T
max( const T& lhs, const T& rhs) {

  return (lhs < rhs) ? rhs : lhs;
}

////////////////////////////////////////////////////////////////////////////////
//! Sign of number (integer data type)
////////////////////////////////////////////////////////////////////////////////
template<class T>
#ifdef __CUDACC__
__host__  __device__
#endif
T
sign_i( const T& val) {
  return (val < 0) ? -1 : 1; 
}

////////////////////////////////////////////////////////////////////////////////
//! Sign of number (float)
////////////////////////////////////////////////////////////////////////////////
#ifdef __CUDACC__
__host__  __device__
#endif
inline float
sign_f( const float& val) {
  return (val < 0.0f) ? -1.0f : 1.0f; 
}

////////////////////////////////////////////////////////////////////////////////
//! Sign of number (double)
////////////////////////////////////////////////////////////////////////////////
#ifdef __CUDACC__
__host__  __device__
#endif
inline double
sign_d( const double& val) {
  return (val < 0.0) ? -1.0 : 1.0; 
}

////////////////////////////////////////////////////////////////////////////////
//! Swap \a lhs and \a rhs
////////////////////////////////////////////////////////////////////////////////
template<class T>
#ifdef __CUDACC__
__host__  __device__
#endif
void
swap( T& lhs, T& rhs) {

  T temp = rhs;
  rhs = lhs;
  lhs = temp;
}

///////////////////////////////////////////////////////////////////////////////
//! Get the number of blocks that are required to process \a num_threads with
//! \a num_threads_blocks threads per block
///////////////////////////////////////////////////////////////////////////////
extern "C" 
inline 
unsigned int
getNumBlocksLinear( const unsigned int num_threads,
                    const unsigned int num_threads_block )
{
  const unsigned int block_rem =
    ((num_threads % num_threads_block) != 0) ? 1 : 0;
  return (num_threads / num_threads_block) + block_rem;
}

#endif // #ifndef _UTIL_H_
