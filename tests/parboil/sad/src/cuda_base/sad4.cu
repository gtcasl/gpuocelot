/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include "sad.h"
#include "sad4.h"

/* The part of the reference image that is in the search range */
texture<unsigned short, 2, cudaReadModeElementType> ref;

/* The compute kernel. */
/* The macros THREADS_W and THREADS_H specify the width and height of the
 * area to be processed by one thread, measured in 4-by-4 pixel blocks.
 * Larger numbers mean more computation per thread block.
 *
 * The macro POS_PER_THREAD specifies the number of search positions for which
 * an SAD is computed.  A larger value indicates more computation per thread,
 * and fewer threads per thread block.  It must be a multiple of 3 and also
 * must be at most 33 because the loop to copy from shared memory uses
 * 32 threads per 4-by-4 pixel block.
 *
 */
__global__ void mb_sad_calc(unsigned short *blk_sad,
                            unsigned short *frame,
                            int mb_width,
                            int mb_height)
{
  int tx = (threadIdx.x / CEIL(MAX_POS, POS_PER_THREAD)) % THREADS_W;
  int ty = (threadIdx.x / CEIL(MAX_POS, POS_PER_THREAD)) / THREADS_W;
  int bx = blockIdx.x;
  int by = blockIdx.y;
  int img_width = mb_width*16;

  /* Macroblock and sub-block coordinates */
  int mb_x = (tx + bx * THREADS_W) >> 2;
  int mb_y = (ty + by * THREADS_H) >> 2;
  int block_x = (tx + bx * THREADS_W) & 0x03;
  int block_y = (ty + by * THREADS_H) & 0x03;

  /* If this thread is assigned to an invalid 4x4 block, do nothing */
  if ((mb_x < mb_width) && (mb_y < mb_height))
    {
      /* Pixel offset of the origin of the current 4x4 block */
      int frame_x = ((mb_x << 2) + block_x) << 2;
      int frame_y = ((mb_y << 2) + block_y) << 2;

      /* Origin of the search area for this 4x4 block */
      int ref_x = frame_x - SEARCH_RANGE;
      int ref_y = frame_y - SEARCH_RANGE;

      /* Origin in the current frame for this 4x4 block */
      int cur_o = frame_y * img_width + frame_x;

      int search_pos;
      int search_pos_base =
        (threadIdx.x % CEIL(MAX_POS, POS_PER_THREAD)) * POS_PER_THREAD;
      int search_pos_end = search_pos_base + POS_PER_THREAD;

      /* All SADs from this thread are stored in a contiguous chunk
       * of memory starting at this offset */
      blk_sad += mb_width * mb_height * MAX_POS_PADDED * (9 + 16) +
        (mb_y * mb_width + mb_x) * MAX_POS_PADDED * 16 +
        (4 * block_y + block_x) * MAX_POS_PADDED;

      /* Don't go past bounds */
      if (search_pos_end > MAX_POS)
        search_pos_end = MAX_POS;

      /* For each search position, within the range allocated to this thread */
      for (search_pos = search_pos_base;
           search_pos < search_pos_end;
           search_pos++) {
        unsigned short sad4x4 = 0;
        int search_off_x = ref_x + (search_pos % SEARCH_DIMENSION);
        int search_off_y = ref_y + (search_pos / SEARCH_DIMENSION);

        /* 4x4 SAD computation */
        for(int y=0; y<4; y++) {
          for (int x=0; x<4; x++) {
            sad4x4 +=
              abs(tex2D(ref, search_off_x + x, search_off_y + y) -
                  frame[cur_o + y * img_width + x]);
          }
        }

        /* Save this value into the local SAD array */
        blk_sad[search_pos] = sad4x4;
      }
    }
}

texture<unsigned short, 2, cudaReadModeElementType> &get_ref(void)
{
  return ref;
}
