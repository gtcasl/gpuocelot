/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#ifndef RANDOMC_H
#define RANDOMC_H

#include <math.h>          // default math function linrary

#include <assert.h>
#include <stdio.h>

// Define 32 bit signed and unsigned integers.
// Change these definitions, if necessary, on 64 bit computers
typedef   signed int int32; 
typedef unsigned int uint32; 

// constants for MT19937:
#define MERS_N   624
#define MERS_M   397
#define MERS_R   31
#define MERS_U   11
#define MERS_S   7
#define MERS_T   15
#define MERS_L   18
#define MERS_A   0x9908B0DF
#define MERS_B   0x9D2C5680
#define MERS_C   0xEFC60000

__device__ void RandomInit(uint32 seed);        // re-seed
__device__ void BRandom();                    // output random bits

__device__ __shared__ uint32 mt[MERS_N];                   // state vector

#endif


