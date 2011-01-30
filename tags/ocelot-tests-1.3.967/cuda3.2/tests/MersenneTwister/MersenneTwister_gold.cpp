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

#ifdef _WIN32
#   pragma warning( disable : 4996 ) // disable deprecated warning 
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <shrUtils.h>
#include "MersenneTwister.h"
#include "dci.h"




static mt_struct MT[MT_RNG_COUNT];
static uint32_t state[MT_NN];



extern "C" void initMTRef(const char *fname){
    
    FILE *fd = fopen(fname, "rb");
    if(!fd){
        shrLog("initMTRef(): failed to open %s\n", fname);
        shrLog("FAILED\n");
        exit(0);
    }

    for (int i = 0; i < MT_RNG_COUNT; i++){
        //Inline structure size for compatibility,
        //since pointer types are 8-byte on 64-bit systems (unused *state variable)
        if( !fread(MT + i, 16 /* sizeof(mt_struct) */ * sizeof(int), 1, fd) ){
            shrLog("initMTRef(): failed to load %s\n", fname);
            shrLog("FAILED\n");
            exit(0);
        }
    }

    fclose(fd);
}



extern "C" void RandomRef(
    float *h_Random,
    int NPerRng,
    unsigned int seed
){
    int iRng, iOut;

    for(iRng = 0; iRng < MT_RNG_COUNT; iRng++){
        MT[iRng].state = state;
        sgenrand_mt(seed, &MT[iRng]);

        for(iOut = 0; iOut < NPerRng; iOut++)
           h_Random[iRng * NPerRng + iOut] = ((float)genrand_mt(&MT[iRng]) + 1.0f) / 4294967296.0f;
    }
}


#define PI 3.14159265358979f
static void BoxMuller(float& u1, float& u2){
    float   r = sqrtf(-2.0f * logf(u1));
    float phi = 2 * PI * u2;
    u1 = r * cosf(phi);
    u2 = r * sinf(phi);
}

extern "C" void BoxMullerRef(float *h_Random, int NPerRng){
    int i;

    for(i = 0; i < MT_RNG_COUNT * NPerRng; i += 2)
        BoxMuller(h_Random[i + 0], h_Random[i + 1]);
}
