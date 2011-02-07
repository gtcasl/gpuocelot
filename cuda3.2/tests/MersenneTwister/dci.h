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
 
 /* dci.h */

/* Copyright (C) 2001-2010 Makoto Matsumoto and Takuji Nishimura.  */
/* This library is free software; you can redistribute it and/or   */
/* modify it under the terms of the GNU Library General Public     */
/* License as published by the Free Software Foundation; either    */
/* version 2 of the License, or (at your option) any later         */
/* version.                                                        */
/* This library is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of  */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            */
/* See the GNU Library General Public License for more details.    */
/* You should have received a copy of the GNU Library General      */
/* Public License along with this library; if not, write to the    */
/* Free Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA   */ 
/* 02111-1307  USA                                                 */



/*
 * Victor Podlozhnyuk @ 05/13/2007:
 * Introduced typedef for uint32_t instead of C99-only #include<inttypes.h>
 */



#ifndef DC_IMPLEMENT
#define DC_IMPLEMENT

typedef unsigned int uint32_t;
#define UINT32_C(a) ((uint32_t)a)

typedef struct {
    uint32_t aaa;
    int mm,nn,rr,ww;
    uint32_t wmask,umask,lmask;
    int shift0, shift1, shiftB, shiftC;
    uint32_t maskB, maskC;
    int i;
    uint32_t *state;
}mt_struct;


////////////////////////////////////////////////////////////////////////////////
// Prototypes for original Matsumoto & Nishimura code
////////////////////////////////////////////////////////////////////////////////
#if defined(__cplusplus)
extern "C" 
#endif
void sgenrand_mt(uint32_t seed, mt_struct *mts);
#if defined(__cplusplus)
extern "C" 
#endif
uint32_t genrand_mt(mt_struct *mts);

#endif
