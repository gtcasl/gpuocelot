/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#include <stdio.h>
#include <cuda.h>

#include "util.h"

__device__ void testIncrementGlobal (
        unsigned int *global_histo,
        unsigned int sm_range_min,
        unsigned int sm_range_max,
        const uchar4 sm)
{
        const unsigned int range = sm.x;
        const unsigned int indexhi = sm.y;
        const unsigned int indexlo = sm.z;
        const unsigned int offset  = sm.w;

        /* Scan for inputs that are outside the central region of histogram */
        if (range < sm_range_min || range > sm_range_max)
        {
                const unsigned int bin = range * BINS_PER_BLOCK + offset / 8 + (indexlo << 2) + (indexhi << 10);
                const unsigned int bin_div2 = bin / 2;
                const unsigned int bin_offset = (bin % 2 == 1) ? 16 : 0;

                unsigned int old_val = global_histo[bin_div2];
                unsigned short old_bin = (old_val >> bin_offset) & 0xFFFF;

                if (old_bin < 255)
                {
                        atomicAdd (&global_histo[bin_div2], 1 << bin_offset);
                }
        }
}

__device__ void testIncrementLocal (
        unsigned int *global_overflow,
        unsigned int smem[KB][256],
        const unsigned int myRange,
        const uchar4 sm)
{
        const unsigned int range = sm.x;
        const unsigned int indexhi = sm.y;
        const unsigned int indexlo = sm.z;
        const unsigned int offset  = sm.w;

        /* Scan for inputs that are inside the central region of histogram */
        if (range == myRange)
        {
                /* Atomically increment shared memory */
                unsigned int add = (unsigned int)(1 << offset);
                unsigned int prev = atomicAdd (&smem[indexhi][indexlo], add);

                /* Check if current bin overflowed */
                unsigned int prev_bin_val = (prev >> offset) & 0x000000FF;

                /* If there was an overflow, record it and record if it cascaded into other bins */
                if (prev_bin_val == 0x000000FF)
                {
                        const unsigned int bin =
                                range * BINS_PER_BLOCK +
                                offset / 8 + (indexlo << 2) + (indexhi << 10);

                        bool can_overflow_to_bin_plus_1 = (offset < 24) ? true : false;
                        bool can_overflow_to_bin_plus_2 = (offset < 16) ? true : false;
                        bool can_overflow_to_bin_plus_3 = (offset <  8) ? true : false;

                        bool overflow_into_bin_plus_1 = false;
                        bool overflow_into_bin_plus_2 = false;
                        bool overflow_into_bin_plus_3 = false;

                        unsigned int prev_bin_plus_1_val = (prev >> (offset +  8)) & 0x000000FF;
                        unsigned int prev_bin_plus_2_val = (prev >> (offset + 16)) & 0x000000FF;
                        unsigned int prev_bin_plus_3_val = (prev >> (offset + 24)) & 0x000000FF;

                        if (can_overflow_to_bin_plus_1 &&        prev_bin_val == 0x000000FF) overflow_into_bin_plus_1 = true;
                        if (can_overflow_to_bin_plus_2 && prev_bin_plus_1_val == 0x000000FF) overflow_into_bin_plus_2 = true;
                        if (can_overflow_to_bin_plus_3 && prev_bin_plus_2_val == 0x000000FF) overflow_into_bin_plus_3 = true;

                        unsigned int bin_plus_1_add;
                        unsigned int bin_plus_2_add;
                        unsigned int bin_plus_3_add;

                        if (overflow_into_bin_plus_1) bin_plus_1_add = (prev_bin_plus_1_val < 0x000000FF) ? 0xFFFFFFFF : 0x000000FF;
                        if (overflow_into_bin_plus_2) bin_plus_2_add = (prev_bin_plus_2_val < 0x000000FF) ? 0xFFFFFFFF : 0x000000FF;
                        if (overflow_into_bin_plus_3) bin_plus_3_add = (prev_bin_plus_3_val < 0x000000FF) ? 0xFFFFFFFF : 0x000000FF;

                                                      atomicAdd (&global_overflow[bin],   256);
                        if (overflow_into_bin_plus_1) atomicAdd (&global_overflow[bin+1], bin_plus_1_add);
                        if (overflow_into_bin_plus_2) atomicAdd (&global_overflow[bin+2], bin_plus_2_add);
                        if (overflow_into_bin_plus_3) atomicAdd (&global_overflow[bin+3], bin_plus_3_add);
                }
        }
}

__device__ void clearMemory (unsigned int smem[KB][256])
{
        for (int i = threadIdx.x; i < BINS_PER_BLOCK / 4; i += blockDim.x)
        {
                ((unsigned int*)smem)[i] = 0;
        }
}

__device__ void copyMemory (unsigned int *dst, unsigned int src[KB][256])
{
        for (int i = threadIdx.x; i < BINS_PER_BLOCK/4; i += blockDim.x)
        {
                atomicAdd(dst+i*4, (((unsigned int*)src)[i] >> 0) & 0xFF);
                atomicAdd(dst+i*4+1, (((unsigned int*)src)[i] >> 8) & 0xFF);
                atomicAdd(dst+i*4+2, (((unsigned int*)src)[i] >> 16) & 0xFF);
                atomicAdd(dst+i*4+3, (((unsigned int*)src)[i] >> 24) & 0xFF);
//                dst[i] = ((unsigned int*)src)[i];
        }
}

__global__ void histo_main_kernel (
        uchar4 *sm_mappings,
        unsigned int num_elements,
        unsigned int sm_range_min,
        unsigned int sm_range_max,
        unsigned int histo_height,
        unsigned int histo_width,
        unsigned int *global_subhisto,
        unsigned int *global_histo,
        unsigned int *global_overflow)
{
        /* Most optimal solution uses 24 * 1024 bins per threadblock */
        __shared__ unsigned int sub_histo[KB][256];

        /* Each threadblock contributes to a specific 24KB range of histogram,
         * and also scans every N-th line for interesting data.  N = gridDim.x
         */
        unsigned int local_scan_range = sm_range_min + blockIdx.y;
        unsigned int local_scan_load = blockIdx.x * blockDim.x + threadIdx.x;

        clearMemory (sub_histo);
        __syncthreads();

        if (blockIdx.y == 0)
        {
                /* Loop through and scan the input */
                while (local_scan_load < num_elements)
                {
                        /* Read buffer */
                        uchar4 sm = sm_mappings[local_scan_load];
                        local_scan_load += blockDim.x * gridDim.x;

                        /* Check input */
                        testIncrementLocal (
                                global_overflow,
                                sub_histo,
                                local_scan_range,
                                sm
                        );
                        testIncrementGlobal (
                                global_histo,
                                sm_range_min,
                                sm_range_max,
                                sm
                        );
                }
        }
        else
        {
                /* Loop through and scan the input */
                while (local_scan_load < num_elements)
                {
                        /* Read buffer */
                        uchar4 sm = sm_mappings[local_scan_load];
                        local_scan_load += blockDim.x * gridDim.x;

                        /* Check input */
                        testIncrementLocal (
                                global_overflow,
                                sub_histo,
                                local_scan_range,
                                sm
                        );
                }
        }

        /* Store sub histogram to global memory */
        unsigned int store_index = (local_scan_range * BINS_PER_BLOCK);

        __syncthreads();
        copyMemory (&(global_subhisto[store_index]), sub_histo);
}
