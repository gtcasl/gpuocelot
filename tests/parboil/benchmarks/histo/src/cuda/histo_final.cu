/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#include "util.h"

/* Combine all the sub-histogram results into one final histogram */
__global__ void histo_final_kernel (
    unsigned int sm_range_min, 
    unsigned int sm_range_max,
    unsigned int histo_height, 
    unsigned int histo_width,
    unsigned int *global_subhisto,
    unsigned int *global_histo,
    unsigned int *global_overflow,
    unsigned int *final_histo) //final output
{
    unsigned int start_offset = threadIdx.x + blockIdx.x * blockDim.x;
    const ushort4 zero_short  = {0, 0, 0, 0};
    const uint4 zero_int      = {0, 0, 0, 0};

    unsigned int size_low_histo = sm_range_min * BINS_PER_BLOCK;
    unsigned int size_mid_histo = (sm_range_max - sm_range_min +1) * BINS_PER_BLOCK;

    /* Clear lower region of global histogram */
    for (unsigned int i = start_offset; i < size_low_histo/4; i += gridDim.x * blockDim.x)
    {
        ushort4 global_histo_data = ((ushort4*)global_histo)[i];
        ((ushort4*)global_histo)[i] = zero_short;

        global_histo_data.x = min (global_histo_data.x, 255);
        global_histo_data.y = min (global_histo_data.y, 255);
        global_histo_data.z = min (global_histo_data.z, 255);
        global_histo_data.w = min (global_histo_data.w, 255);

        uchar4 final_histo_data = {
            global_histo_data.x,
            global_histo_data.y,
            global_histo_data.z,
            global_histo_data.w
        };

        ((uchar4*)final_histo)[i] = final_histo_data;
    }

    /* Clear the middle region of the overflow buffer */
    for (unsigned int i = (size_low_histo/4) + start_offset; i < (size_low_histo+size_mid_histo)/4; i += gridDim.x * blockDim.x)
    {
        uint4 global_histo_data = ((uint4*)global_overflow)[i];
        ((uint4*)global_overflow)[i] = zero_int;

        uint4 internal_histo_data = {
            global_histo_data.x,
            global_histo_data.y,
            global_histo_data.z,
            global_histo_data.w
        };

/*
        #pragma unroll
        for (int j = 0; j < BLOCK_X; j++)
        {
            unsigned int bin4in = ((unsigned int*)global_subhisto)[i + j * histo_height * histo_width / 4];
            internal_histo_data.x += (bin4in >>  0) & 0xFF;
            internal_histo_data.y += (bin4in >>  8) & 0xFF;
            internal_histo_data.z += (bin4in >> 16) & 0xFF;
            internal_histo_data.w += (bin4in >> 24) & 0xFF;
        }

        internal_histo_data.x = min (internal_histo_data.x, 255);
        internal_histo_data.y = min (internal_histo_data.y, 255);
        internal_histo_data.z = min (internal_histo_data.z, 255);
        internal_histo_data.w = min (internal_histo_data.w, 255);
*/

        unsigned int bin4in0 = ((unsigned int*)global_subhisto)[i*4];
        unsigned int bin4in1 = ((unsigned int*)global_subhisto)[i*4+1];
        unsigned int bin4in2 = ((unsigned int*)global_subhisto)[i*4+2];
        unsigned int bin4in3 = ((unsigned int*)global_subhisto)[i*4+3];

        internal_histo_data.x = min (bin4in0, 255);
        internal_histo_data.y = min (bin4in1, 255);
        internal_histo_data.z = min (bin4in2, 255);
        internal_histo_data.w = min (bin4in3, 255);

        uchar4 final_histo_data = {
            internal_histo_data.x,
            internal_histo_data.y,
            internal_histo_data.z,
            internal_histo_data.w
        };

        ((uchar4*)final_histo)[i] = final_histo_data;
    }

    /* Clear the upper region of global histogram */
    for (unsigned int i = ((size_low_histo+size_mid_histo)/4) + start_offset; i < (histo_height*histo_width)/4; i += gridDim.x * blockDim.x)
    {
        ushort4 global_histo_data = ((ushort4*)global_histo)[i];
        ((ushort4*)global_histo)[i] = zero_short;

        global_histo_data.x = min (global_histo_data.x, 255);
        global_histo_data.y = min (global_histo_data.y, 255);
        global_histo_data.z = min (global_histo_data.z, 255);
        global_histo_data.w = min (global_histo_data.w, 255);

        uchar4 final_histo_data = {
            global_histo_data.x,
            global_histo_data.y,
            global_histo_data.z,
            global_histo_data.w
        };

        ((uchar4*)final_histo)[i] = final_histo_data;
    }
}
