/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#ifndef _PRESCAN_CU_
#define _PRESCAN_CU_

#include <assert.h>
#include "model.h"
#include <math.h>

#define WARP_SIZE 32
#define NUM_BANKS 16
#define LOG_NUM_BANKS 4

#define BLOCK_SIZE 256
#define NUM_WARPS (BLOCK_SIZE/WARP_SIZE)
#define HISTS_PER_WARP 16
#define NUM_HISTOGRAMS  (NUM_WARPS*HISTS_PER_WARP)
#define THREADS_PER_HIST (WARP_SIZE/HISTS_PER_WARP)

float** g_scanBlockSums;
unsigned int g_numEltsAllocated = 0;
unsigned int g_numLevelsAllocated = 0;

__constant__ float dev_binb[NUM_BINS+1];

unsigned int NUM_SETS;
unsigned int NUM_ELEMENTS;

// create the bin boundaries
void initBinB( struct pb_TimerSet *timers )
{
  float *binb = (float*)malloc((NUM_BINS+1)*sizeof(float));
  for (int k = 0; k < NUM_BINS+1; k++)
    {
      binb[k] = cos(pow(10.0, (log10(min_arcmin) + k*1.0/bins_per_dec)) 
		    / 60.0*D2R);
    }
  pb_SwitchToTimer( timers, pb_TimerID_COPY );
  cudaMemcpyToSymbol(dev_binb, binb, (NUM_BINS+1)*sizeof(float));
  pb_SwitchToTimer( timers, pb_TimerID_COMPUTE );
  free(binb);
}

__global__ 
void gen_hists( hist_t* histograms, float* all_x_data, float* all_y_data, 
		float* all_z_data, int NUM_SETS, int NUM_ELEMENTS )
{
  unsigned int bx = blockIdx.x;
  unsigned int tid = threadIdx.x;
  bool do_self = (bx < (NUM_SETS + 1));

  float* data_x;
  float* data_y;
  float* data_z;
  float* random_x;
  float* random_y;
  float* random_z;

  volatile __shared__ unsigned int
    warp_hists[NUM_BINS][NUM_HISTOGRAMS]; // 640B <1k  
    
  for(unsigned int w = 0; w < NUM_BINS*NUM_HISTOGRAMS; w += BLOCK_SIZE )
    {
      if(w+tid < NUM_BINS*NUM_HISTOGRAMS)
	{
	  warp_hists[(w+tid)/NUM_HISTOGRAMS][(w+tid)%NUM_HISTOGRAMS] = 0;
	}
    }
    
  // Get stuff into shared memory to kick off the loop.
  if( !do_self)
    {
      data_x = all_x_data;
      data_y = all_y_data;
      data_z = all_z_data;
      random_x = all_x_data + NUM_ELEMENTS * (bx - NUM_SETS);
      random_y = all_y_data + NUM_ELEMENTS * (bx - NUM_SETS);
      random_z = all_z_data + NUM_ELEMENTS * (bx - NUM_SETS);
    }
  else
    {
      random_x = all_x_data + NUM_ELEMENTS * (bx);
      random_y = all_y_data + NUM_ELEMENTS * (bx);
      random_z = all_z_data + NUM_ELEMENTS * (bx);
      
      data_x = random_x;
      data_y = random_y;
      data_z = random_z;
    }
    
  // Iterate over all data points
  for(unsigned int i = 0; i < NUM_ELEMENTS; i += BLOCK_SIZE )
    {
      // Iterate over all random points
      for(unsigned int j = (do_self ? i+1 : 0); j < NUM_ELEMENTS; 
	  j += BLOCK_SIZE)
	{
	  // load current random point values
	  float random_x_s;
	  float random_y_s;
	  float random_z_s;
	  
	  if(tid + j < NUM_ELEMENTS)
	    {
	      random_x_s = random_x[tid + j];
	      random_y_s = random_y[tid + j];
	      random_z_s = random_z[tid + j];
	    }

	  // Iterate for all elements of current set of data points 
	  // (BLOCK_SIZE iterations per thread)
	  // Each thread calcs against 1 random point within cur set of random
	  // (so BLOCK_SIZE threads covers all random points within cur set)
	  for(unsigned int k = 0; (k < BLOCK_SIZE) && (k+i < NUM_ELEMENTS);
	      k++)
	    {
	      // do actual calculations on the values:
	      float distance = data_x[k+i] * random_x_s + 
		data_y[k+i] * random_y_s + 
		data_z[k+i] * random_z_s ;

	      // run binary search
	      unsigned int bin_index;
	      unsigned int min = 0;
	      unsigned int max = NUM_BINS;
	      unsigned int k2;
	      
	      while (max > min+1)
		{
		  k2 = (min + max) / 2;
		  if (distance >= dev_binb[k2]) 
		    max = k2;
		  else 
		    min = k2;
		}

	      unsigned int warpnum = tid / (WARP_SIZE/HISTS_PER_WARP);
	      if(distance < dev_binb[min] && distance >= dev_binb[max] && 
		 (!do_self || tid + j > i + k) && tid + j < NUM_ELEMENTS)
		{
		  bin_index = max-1;
	    
		  // Write into the mini histogram
		  // do this until update is not overwritten:
		  unsigned long myVal;
		  do 
		    {
		      // read the current bin val
		      myVal = warp_hists[bin_index][warpnum] & 0x07FFFFFF;
		      
		      // increment and put thread tag in top bits
		      myVal = ((tid & 0x1F) << 27) | (myVal + 1);
		      
		      // attempt to write the bin
		      warp_hists[bin_index][warpnum] = myVal; 
		      
		      // while updates overwritten, keep retrying
		    } while (warp_hists[bin_index][warpnum] != myVal);
		}
	      __syncthreads();
	    }
	}
    }
    
  // coalesce the histograms in a block
  unsigned int warp_index = tid & ( (NUM_HISTOGRAMS>>1) - 1);
  unsigned int bin_index = tid / (NUM_HISTOGRAMS>>1);
  for(unsigned int offset = NUM_HISTOGRAMS >> 1; offset > 0; 
      offset >>= 1)
    {
      for(unsigned int bin_base = 0; bin_base < NUM_BINS; 
	  bin_base += BLOCK_SIZE/ (NUM_HISTOGRAMS>>1))
	{
	  __syncthreads();
	  if(warp_index < offset && bin_base+bin_index < NUM_BINS )
	    {
	      unsigned long sum = (warp_hists[bin_base +
					      bin_index][warp_index] + 
				   warp_hists[bin_base + 
					      bin_index][warp_index+offset]);
	      warp_hists[bin_base + bin_index][warp_index] = sum;
	    }
	}
    }
    
  __syncthreads();
    
  // Put the results back in the real histogram
  // warp_hists[x][0] holds sum of all locations of bin x
  hist_t* hist_base = histograms + NUM_BINS * bx;
  if(tid < NUM_BINS)
    {
      hist_base[tid] = warp_hists[tid][0]&0x07ffffff;
    }
}

void TPACF(hist_t * histograms, float* d_x_data, float* d_y_data, 
	   float* d_z_data)
{
  dim3 dimBlock(BLOCK_SIZE);
  dim3 dimGrid(NUM_SETS*2 + 1);

  gen_hists <<< dimGrid, dimBlock >>> ( histograms, d_x_data, 
					d_y_data, d_z_data, NUM_SETS, 
					NUM_ELEMENTS);
}
// **===-----------------------------------------------------------===**


#endif // _PRESCAN_CU_
