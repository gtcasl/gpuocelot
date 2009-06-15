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

/* Determine eigenvalues for large matrices for intervals that contained after
 * the first step one eigenvalue
 */

#ifndef _BISECT_KERNEL_LARGE_ONEI_H_
#define _BISECT_KERNEL_LARGE_ONEI_H_

// includes, project
#include "config.h"
#include "util.h"

// additional kernel
#include "bisect_util.cu"

////////////////////////////////////////////////////////////////////////////////
//! Determine eigenvalues for large matrices for intervals that after
//! the first step contained one eigenvalue
//! @param  g_d  diagonal elements of symmetric, tridiagonal matrix
//! @param  g_s  superdiagonal elements of symmetric, tridiagonal matrix
//! @param  n    matrix size
//! @param  num_intervals  total number of intervals containing one eigenvalue 
//!                         after the first step
//! @param g_left  left interval limits
//! @param g_right  right interval limits
//! @param g_pos  index of interval / number of intervals that are smaller than
//!               right interval limit
//! @param  precision  desired precision of eigenvalues
////////////////////////////////////////////////////////////////////////////////
__global__
void
bisectKernelLarge_OneIntervals( float* g_d, float* g_s, const unsigned int n,
                                unsigned int num_intervals,
                                float* g_left, float* g_right,
                                unsigned int* g_pos,
                                float  precision )
{
  const unsigned int gtid = (blockDim.x * blockIdx.x) + threadIdx.x;

  __shared__  float  s_left_scratch[MAX_THREADS_BLOCK];
  __shared__  float  s_right_scratch[MAX_THREADS_BLOCK];

  // active interval of thread
  // left and right limit of current interval
  float left, right;
  // number of threads smaller than the right limit (also corresponds to the
  // global index of the eigenvalues contained in the active interval)
  unsigned int right_count;
  // flag if current thread converged
  unsigned int converged = 0;
  // midpoint when current interval is subdivided
  float mid = 0.0f;
  // number of eigenvalues less than mid
  unsigned int mid_count = 0;

  // read data from global memory
  if( gtid < num_intervals) {
    left = g_left[gtid];
    right = g_right[gtid];
    right_count = g_pos[gtid];
  }


  // flag to determine if all threads converged to eigenvalue
  __shared__  unsigned int  converged_all_threads;

  // initialized shared flag
  if( 0 == threadIdx.x) {
    converged_all_threads = 0;
  }
  __syncthreads();

  // process until all threads converged to an eigenvalue
  // while( 0 == converged_all_threads) {
  while( true) {

    converged_all_threads = 1;

    // update midpoint for all active threads
    if((gtid < num_intervals) && ( 0 == converged)) {

      mid = computeMidpoint( left, right);
    }

    // find number of eigenvalues that are smaller than midpoint
    mid_count = computeNumSmallerEigenvalsLarge( g_d, g_s, n,
                                                 mid, gtid, num_intervals,
                                                 s_left_scratch,
                                                 s_right_scratch,
                                                 converged );

     __syncthreads();

     // for all active threads
     if( (gtid < num_intervals) && ( 0 == converged)) {

       // udpate intervals -- always one child interval survives
       if( right_count == mid_count) {     
         right = mid;      
       }
       else {
         left = mid;
       }

       // check for convergence
       float t0 = right - left;
       float t1 = max( abs(right), abs(left)) * precision;
       if( t0 < min( precision, t1)) {

         float lambda = computeMidpoint( left, right);
         left = lambda;
         right = lambda;

         converged = 1;
       }
       else {
         converged_all_threads = 0;
       }
     }

     __syncthreads();

     if( 1 == converged_all_threads) {
       break;
     }

     __syncthreads();
  }

  // write data back to global memory
  __syncthreads();
  if( gtid < num_intervals) {
    // intervals converged so left and right interval limit are both identical
    // and identical to the eigenvalue
    g_left[gtid] = left;
  }

}

#endif // #ifndef _BISECT_KERNEL_LARGE_ONEI_H_
