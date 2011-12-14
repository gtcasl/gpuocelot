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

/* Helper structures to simplify variable handling */

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

struct InputData {

  //! host side representation of diagonal
  float*  a;
  //! host side representation superdiagonal
  float*  b;

  //! device side representation of diagonal
  float*  g_a;
  //! device side representation of superdiagonal
  float*  g_b;
  //! helper variable pointing to the mem allocated for g_b which provides
  //! space for one additional element of padding at the beginning
  float*  g_b_raw;

};

struct ResultDataSmall {
  
  //! eigenvalues (host side)
  float* eigenvalues;

  // left interval limits at the end of the computation
  float* g_left;

  // right interval limits at the end of the computation
  float* g_right;

  // number of eigenvalues smaller than the left interval limit
  unsigned int* g_left_count;

  // number of eigenvalues bigger than the right interval limit
  unsigned int* g_right_count;

  //! flag if algorithm converged
  unsigned int* g_converged;

  // helper variables

  unsigned int mat_size_f;
  unsigned int mat_size_ui;

  float*         zero_f;
  unsigned int*  zero_ui;
};


struct ResultDataLarge {

  // number of intervals containing one eigenvalue after the first step
  unsigned int* g_num_one;

  // number of (thread) blocks of intervals containing multiple eigenvalues
  // after the first steo
  unsigned int* g_num_blocks_mult;

  //! left interval limits of intervals containing one eigenvalue after the 
  //! first iteration step
  float* g_left_one;

  //! right interval limits of intervals containing one eigenvalue after the 
  //! first iteration step
  float* g_right_one;

  //! interval indices (position in sorted listed of eigenvalues)
  //! of intervals containing one eigenvalue after the first iteration step
  unsigned int* g_pos_one;

  //! left interval limits of intervals containing multiple eigenvalues
  //! after the first iteration step
  float* g_left_mult;

  //! right interval limits of intervals containing multiple eigenvalues
  //! after the first iteration step
  float* g_right_mult;

  //! number of eigenvalues less than the left limit of the eigenvalue 
  //! intervals containing multiple eigenvalues
  unsigned int* g_left_count_mult;

  //! number of eigenvalues less than the right limit of the eigenvalue 
  //! intervals containing multiple eigenvalues
  unsigned int* g_right_count_mult;

  //! start addresses in g_left_mult etc. of blocks of intervals containing
  //! more than one eigenvalue after the first step
  unsigned int*  g_blocks_mult;

  //! accumulated number of intervals in g_left_mult etc. of blocks of
  //! intervals containing more than one eigenvalue after the first step
  unsigned int*  g_blocks_mult_sum;

  //! eigenvalues that have been generated in the second step from intervals
  //! that still contained multiple eigenvalues after the first step
  float* g_lambda_mult;

  //! eigenvalue index of intervals that have been generated in the second 
  //! processing step
  unsigned int* g_pos_mult;

};

#endif // #ifndef _STRUCTS_H_

