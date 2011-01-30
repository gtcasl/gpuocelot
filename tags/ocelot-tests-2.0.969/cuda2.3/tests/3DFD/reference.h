
/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation and 
 * any modifications thereto.  Any use, reproduction, disclosure, or distribution 
 * of this software and related documentation without an express license 
 * agreement from NVIDIA Corporation is strictly prohibited.
 * 
 *
*/

#ifndef _3DFD_VERIFICATION
#define _3DFD_VERIFICATION

#include <stdio.h>

void init_data(float *data, const int dimx, const int dimy, const int dimz)
{
    for(int iz=0; iz<dimz; iz++)
        for(int iy=0; iy<dimy; iy++)
            for(int ix=0; ix<dimx; ix++)
            {
                *data = (float)iz;
                ++data;
            }
}

void random_data(float *data, const int dimx, const int dimy, const int dimz, const int lower_bound, const int upper_bound)
{
    srand(0);

    for(int iz=0; iz<dimz; iz++)
        for(int iy=0; iy<dimy; iy++)
            for(int ix=0; ix<dimx; ix++)
            {
                *data = (float) (lower_bound + (rand() % (upper_bound - lower_bound)));
                ++data;
            }
}

// note that this CPU implemenation is extremely naive and slow, NOT to be used for performance comparisons
void reference_3D(float *output, float *input, float *coeff, const int dimx, const int dimy, const int dimz, const int radius=4)
{
    int dimxy = dimx*dimy;

    for(int iz=0; iz<dimz; iz++)
    {
        for(int iy=0; iy<dimy; iy++)
        {
            for(int ix=0; ix<dimx; ix++)
            {
                if( ix>=radius && ix<(dimx-radius) && iy>=radius && iy<(dimy-radius) && iz>=radius && iz<(dimz-radius) )
                {
                    float value = (*input)*coeff[0];

                    for(int ir=1; ir<=radius; ir++)
                    {
                        value += coeff[ir] * (*(input+ir) + *(input-ir));				// horizontal
                        value += coeff[ir] * (*(input+ir*dimx) + *(input-ir*dimx));		// vertical
                        value += coeff[ir] * (*(input+ir*dimxy) + *(input-ir*dimxy));	// in front / behind
                    }

                    *output = value;
                }

                ++output;
                ++input;
            }
        }
    }
}

bool within_epsilon(float* output, float *reference, const int dimx, const int dimy, const int dimz, const int radius=4, const int zadjust=-1, const float delta=0.0001f )
{
    bool retval = true;

    for(int iz=0; iz<dimz; iz++)
    {
        for(int iy=0; iy<dimy; iy++)
        {
            for(int ix=0; ix<dimx; ix++)
            {
                if( ix>=radius && ix<(dimx-radius) && iy>=radius && iy<(dimy-radius) && iz>=radius && iz<(dimz-radius+zadjust) )
                {
                    float difference = abs( *reference - *output);

                    if( difference > delta )
                    {
                        retval = false;
                        printf(" ERROR: (%d,%d,%d)\t%.2f instead of %.2f\n", ix,iy,iz, *output, *reference);

                        return false;
                    }
                    //printf("%d %d %.2f\n", ix,iy, difference);
                }

                ++output;
                ++reference;
            }
        }
    }

    return retval;
}

#endif
