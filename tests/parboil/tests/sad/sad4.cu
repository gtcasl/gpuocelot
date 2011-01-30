/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include "sad.h"
#include "sad4.h"

/* Macros to access temporary frame storage in shared memory */
#define FRAME_GET(n, x, y) \
  (frame_loc[((n) << 4) + ((y) << 2) + (x)])
#define FRAME_PUT_1(n, x, value) \
  (frame_loc[((n) << 4) + (x)] = value)

/* Macros to access temporary SAD storage in shared memory */
#define SAD_LOC_GET(blocknum, pos) \
  (sad_loc[(blocknum) * MAX_POS_PADDED + (pos)])
#define SAD_LOC_PUT(blocknum, pos, value) \
  (sad_loc[(blocknum) * MAX_POS_PADDED + (pos)] = (value))

/* When reading from this array, we use an "index" rather than a
   search position.  Also, the number of array elements is divided by
   four relative to SAD_LOC_GET() since this is an array of 8byte
   data, while SAD_LOC_GET() sees an array of 2byte data. */
#define SAD_LOC_8B_GET(blocknum, ix) \
  (sad_loc_8b[(blocknum) * (MAX_POS_PADDED/4) + (ix)])

/* The size of one row of sad_loc_8b.  This is the group of elements
 * holding SADs for all search positions for one 4x4 block. */
#define SAD_LOC_8B_ROW_SIZE (MAX_POS_PADDED/4)

/* The presence of this preprocessor variable controls which
 * of two means of computing the current search position is used. */
#define SEARCHPOS_RECURRENCE

/* A local copy of the current 4x4 block */
__shared__ unsigned short frame_loc[THREADS_W * THREADS_H * 16];

/* The part of the reference image that is in the search range */
texture<unsigned short, 2, cudaReadModeElementType> ref;

/* The local SAD array on the device.  This is an array of short ints.  It is
 * interpreted as an array of 8-byte data for global data transfers. */
extern __shared__ unsigned short sad_loc[];
extern __shared__ vec8b sad_loc_8b[];

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
  int txy_tmp = threadIdx.x / CEIL(MAX_POS, POS_PER_THREAD);
  int ty = txy_tmp / THREADS_W;
  int tx = txy_tmp - __umul24(ty, THREADS_W);
  int bx = blockIdx.x;
  int by = blockIdx.y;

  /* Macroblock and sub-block coordinates */
  int mb_x = (tx + __umul24(bx, THREADS_W)) >> 2;
  int mb_y = (ty + __umul24(by, THREADS_H)) >> 2;
  int block_x = (tx + __umul24(bx, THREADS_W)) & 0x03;
  int block_y = (ty + __umul24(by, THREADS_H)) & 0x03;

  /* Block-copy data into shared memory.
   * Threads are grouped into sets of 16, leaving some threads idle. */
  if ((threadIdx.x >> 4) < (THREADS_W * THREADS_H))
  {
    int ty = (threadIdx.x >> 4) / THREADS_W;
    int tx = (threadIdx.x >> 4) - __umul24(ty, THREADS_W);
    int tgroup = threadIdx.x & 15;

    /* Width of the image in pixels */
    int img_width = mb_width*16;

    /* Pixel offset of the origin of the current 4x4 block */
    int frame_x = (tx + __umul24(bx, THREADS_W)) << 2;
    int frame_y = (ty + __umul24(by, THREADS_H)) << 2;

    /* Origin in the current frame for this 4x4 block */
    int cur_o = frame_y * img_width + frame_x;

    /* If this is an invalid 4x4 block, do nothing */
    if (((frame_x >> 4) < mb_width) && ((frame_y >> 4) < mb_height))
      {
	/* Copy one pixel into 'frame' */
	FRAME_PUT_1(__umul24(ty, THREADS_W) + tx, tgroup,
		    frame[cur_o + (tgroup >> 2) * img_width + (tgroup & 3)]);
      }
  }

  __syncthreads();

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
      int cur_o = ty * THREADS_W + tx;

      int search_pos;
      int search_pos_base =
	(threadIdx.x % CEIL(MAX_POS, POS_PER_THREAD)) * POS_PER_THREAD;
      int search_pos_end = search_pos_base + POS_PER_THREAD;

      int sotmp = search_pos_base / SEARCH_DIMENSION;
      int local_search_off_x = search_pos_base - TIMES_DIM_POS(sotmp);
      int search_off_y = ref_y + sotmp;

      /* Don't go past bounds */
      if (search_pos_end > MAX_POS)
	search_pos_end = MAX_POS;

      /* For each search position, within the range allocated to this thread */
      for (search_pos = search_pos_base;
	   search_pos < search_pos_end;
	   search_pos += 3) {
	/* It is also beneficial to fuse (jam) the enclosed loops if this loop
	 * is unrolled. */
	unsigned short sad1 = 0, sad2 = 0, sad3 = 0;
	int search_off_x = ref_x + local_search_off_x;

	/* 4x4 SAD computation */
	for(int y=0; y<4; y++) {
	  int t;
	  t = tex2D(ref, search_off_x, search_off_y + y);
	  sad1 += abs(t - FRAME_GET(cur_o, 0, y));

	  t = tex2D(ref, search_off_x + 1, search_off_y + y);
	  sad1 += abs(t - FRAME_GET(cur_o, 1, y));
	  sad2 += abs(t - FRAME_GET(cur_o, 0, y));

	  t = tex2D(ref, search_off_x + 2, search_off_y + y);
	  sad1 += abs(t - FRAME_GET(cur_o, 2, y));
	  sad2 += abs(t - FRAME_GET(cur_o, 1, y));
	  sad3 += abs(t - FRAME_GET(cur_o, 0, y));

	  t = tex2D(ref, search_off_x + 3, search_off_y + y);
	  sad1 += abs(t - FRAME_GET(cur_o, 3, y));
	  sad2 += abs(t - FRAME_GET(cur_o, 2, y));
	  sad3 += abs(t - FRAME_GET(cur_o, 1, y));

	  t = tex2D(ref, search_off_x + 4, search_off_y + y);
	  sad2 += abs(t - FRAME_GET(cur_o, 3, y));
	  sad3 += abs(t - FRAME_GET(cur_o, 2, y));

	  t = tex2D(ref, search_off_x + 5, search_off_y + y);
	  sad3 += abs(t - FRAME_GET(cur_o, 3, y));
	}

	/* Save this value into the local SAD array */
	SAD_LOC_PUT(__umul24(ty, THREADS_W) + tx, search_pos, sad1);
	SAD_LOC_PUT(__umul24(ty, THREADS_W) + tx, search_pos+1, sad2);
	SAD_LOC_PUT(__umul24(ty, THREADS_W) + tx, search_pos+2, sad3);

	local_search_off_x += 3;
	if (local_search_off_x >= SEARCH_DIMENSION)
	  {
	    local_search_off_x -= SEARCH_DIMENSION;
	    search_off_y++;
	  }
      }
    }

  __syncthreads();

  /* Block-copy data into global memory.
   * Threads are grouped into sets of 32, leaving some threads idle. */
  if ((threadIdx.x >> 5) < (THREADS_W * THREADS_H))
  {
    int tgroup = threadIdx.x & 31;
    int ty = (threadIdx.x >> 5) / THREADS_W;
    int tx = (threadIdx.x >> 5) - __umul24(ty, THREADS_W);
    int index;

    /* Macroblock and sub-block coordinates */
    int mb_x = (tx + __umul24(bx, THREADS_W)) >> 2;
    int mb_y = (ty + __umul24(by, THREADS_H)) >> 2;
    int block_x = (tx + __umul24(bx, THREADS_W)) & 0x03;
    int block_y = (ty + __umul24(by, THREADS_H)) & 0x03;

    if ((mb_x < mb_width) && (mb_y < mb_height))
      {
	/* All SADs from this thread are stored in a contiguous chunk
	 * of memory starting at this offset */
	blk_sad += (__umul24(__umul24(mb_width, mb_height), 25) +
		    (__umul24(mb_y, mb_width) + mb_x) * 16 +
		    (4 * block_y + block_x)) *
	  MAX_POS_PADDED;

	/* Block copy, 32 threads at a time */
	for (index = tgroup; index < SAD_LOC_8B_ROW_SIZE; index += 32)
	  ((vec8b *)blk_sad)[index] 
	    = SAD_LOC_8B_GET(__umul24(ty, THREADS_W) + tx, index);
      }
  }
}

texture<unsigned short, 2, cudaReadModeElementType> &get_ref(void)
{
  return ref;
}
