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

/* Computation of Gerschgorin interval for symmetric, tridiagonal matrix */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cfloat>

#include "util.h"
#include "gerschgorin.h"

////////////////////////////////////////////////////////////////////////////////
//! Compute Gerschgorin interval for symmetric, tridiagonal matrix
//! @param  d  diagonal elements
//! @param  s  superdiagonal elements
//! @param  n  size of matrix
//! @param  lg  lower limit of Gerschgorin interval
//! @param  ug  upper limit of Gerschgorin interval
////////////////////////////////////////////////////////////////////////////////
void
computeGerschgorin( float* d, float* s, unsigned int n, float& lg, float& ug) {

	lg = FLT_MAX;
  ug = -FLT_MAX; 

  // compute bounds
  for( unsigned int i = 1; i < (n - 1); ++i) {
    
    // sum over the absolute values of all elements of row i
    float sum_abs_ni = fabsf( s[i-1]) + fabsf( s[i]);
    
    lg = min( lg, d[i] - sum_abs_ni);
    ug = max( ug, d[i] + sum_abs_ni);
  }  

  // first and last row, only one superdiagonal element

  // first row
  lg = min( lg, d[0] - fabsf( s[0]));
  ug = max( ug, d[0] + fabsf( s[0]));

  // last row
  lg = min( lg, d[n-1] - fabsf( s[n-2]));
  ug = max( ug, d[n-1] + fabsf( s[n-2]));

  // increase interval to avoid side effects of fp arithmetic
  float bnorm = max( fabsf( ug), fabsf( lg));

  // these values depend on the implmentation of floating count that is
  // employed in the following
  float psi_0 = 11 * FLT_EPSILON * bnorm;
  float psi_n = 11 * FLT_EPSILON * bnorm;
  
  lg = lg - bnorm * 2 * n * FLT_EPSILON - psi_0;
  ug = ug + bnorm * 2 * n * FLT_EPSILON + psi_n;

  ug = max( lg, ug);
}

