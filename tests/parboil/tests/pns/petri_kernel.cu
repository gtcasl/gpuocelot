/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#ifndef _PETRINET_KERNEL_H_
#define _PETRINET_KERNEL_H_

#include <stdio.h>
#include "petri.h"

#define BLOCK_SIZE 256
#define BLOCK_SIZE_BITS 8

__device__ 
void fire_transition(char* g_places, int* conflict_array, int tr, 
		     int tc, int step, int N, int thd_thrd) 
{
  int val1, val2, val3, to_update;
  int mark1, mark2;
	
  to_update = 0;
  if (threadIdx.x<thd_thrd) 
    {
      // check if the transition is enabled and conflict-free
      val1 = (tr==0)? (N+N)-1: tr-1;
      val2 = (tr & 0x1)? (tc==N-1? 0: tc+1): tc;
      val3 = (tr==(N+N)-1)? 0: tr+1;
      mark1 = g_places[val1*N+val2];
      mark2 = g_places[tr*N+tc];
      if ( (mark1>0) && (mark2>0) ) 
	{
	  to_update = 1;
	  conflict_array[tr*N+tc] = step;
	}
    }
  __syncthreads();

  if (to_update) 
    {
      // If there are conflicts, transitions on even/odd rows are 
      // kept when the step is even/odd
      to_update = ((step & 0x01) == (tr & 0x01) ) || 
	( (conflict_array[val1*N+val2]!=step) && 
	  (conflict_array[val3*N+((val2==0)? N-1: val2-1)]!=step) );
    }

  // now update state
  // 6 kernel memory accesses 
  if (to_update) 
    {
      g_places[val1*N+val2] = mark1-1;  // the place above
      g_places[tr*N+tc] = mark2-1; // the place on the left
    }
  __syncthreads();
  if (to_update) 
    {
      g_places[val3*N+val2]++;  // the place below
      g_places[tr*N+(tc==N-1? 0: tc+1)]++; // the place on the right
    }
  __syncthreads();
}


__device__ 
void initialize_grid(int* g_places, int NSQUARE2, int seed) 
{
  // N is an even number
  int i;
  int loop_num = NSQUARE2 >> (BLOCK_SIZE_BITS+2);
	
  for (i=0; i<loop_num; i++) 
    {
      g_places[threadIdx.x+(i<<BLOCK_SIZE_BITS)] = 0x01010101;
    }
    
  if (threadIdx.x < (NSQUARE2>>2)-(loop_num<<BLOCK_SIZE_BITS)) 
    {
      g_places[threadIdx.x+(loop_num<<BLOCK_SIZE_BITS)] = 0x01010101;
    }
	
  RandomInit(blockIdx.x+seed);
}

__device__ 
void run_trajectory(int* g_places, int N, int max_steps) 
{
  int step, NSQUARE2, val;

  step = 0;
  NSQUARE2 = (N+N)*N;
	
  while (step<max_steps) 
    {
      BRandom(); // select the next MERS_N (624) transitions

      // process 256 transitions
      val = mt[threadIdx.x]%NSQUARE2;
      fire_transition((char*)g_places, g_places+(NSQUARE2>>2), 
		      val/N, val%N, step+7, N, BLOCK_SIZE);
      
      // process 256 transitions
      val = mt[threadIdx.x+BLOCK_SIZE]%NSQUARE2;
      fire_transition((char*)g_places, g_places+(NSQUARE2>>2), 
		      val/N, val%N, step+11, N, BLOCK_SIZE);
		                
      // process 112 transitions
      if (  threadIdx.x < MERS_N-(BLOCK_SIZE<<1)  ) 
	{
	  val = mt[threadIdx.x+(BLOCK_SIZE<<1)]%NSQUARE2;
	}
      fire_transition((char*)g_places, g_places+(NSQUARE2>>2), 
		      val/N, val%N, step+13, N, MERS_N-(BLOCK_SIZE<<1));

      step += MERS_N>>1; 
      // experiments show that for N>2000 and max_step<20000, 
      // the step increase is larger than 320
    }
}


__device__ 
void compute_reward_stat(int* g_places, float* g_vars, int* g_maxs, 
			 int NSQUARE2) 
{
  float sum = 0;
  int i;
  int max = 0;
  int temp, data; 
  int loop_num = NSQUARE2 >> (BLOCK_SIZE_BITS+2);
  for (i=0; i<=loop_num-1; i++) 
    {  // a bug. i<loop_num should be changed to i<=loop_num-1
      data = g_places[threadIdx.x+(i<<BLOCK_SIZE_BITS)];
	    
      temp = data & 0x0FF;
      sum += temp*temp;
      max = max<temp? temp: max;
      temp = (data>>8) & 0x0FF;
      sum += temp*temp;
      max = max<temp? temp: max;
      temp = (data>>16) & 0x0FF;
      sum += temp*temp;
      max = max<temp? temp: max;
      temp = (data>>24) & 0x0FF;
      sum += temp*temp;
      max = max<temp? temp: max;
    }

  i = NSQUARE2>>2;
  i &= 0x0FF;
  loop_num *= BLOCK_SIZE; 
  // I do not know why loop_num<<=BLOCK_SIZE_BITS does not work
  if (threadIdx.x <= i-1) 
    {
      data = g_places[threadIdx.x+loop_num];
	    
      temp = data & 0x0FF;
      sum += temp*temp;
      max = max<temp? temp: max;
      temp = (data>>8) & 0x0FF;
      sum += temp*temp;
      max = max<temp? temp: max;
      temp = (data>>16) & 0x0FF;
      sum += temp*temp;
      max = max<temp? temp: max;
      temp = (data>>24) & 0x0FF;
      sum += temp*temp;
      max = max<temp? temp: max;
    }
	
  ((float*)mt)[threadIdx.x] = (float)sum;
  mt[threadIdx.x+BLOCK_SIZE] = (uint32)max;
  __syncthreads();
		
  for (i=(BLOCK_SIZE>>1); i>0; i = (i>>1) ) 
    {
      if (threadIdx.x<i) 
	{
	  ((float*)mt)[threadIdx.x] += ((float*)mt)[threadIdx.x+i];
	  if (mt[threadIdx.x+BLOCK_SIZE]<mt[threadIdx.x+i+BLOCK_SIZE])
	    mt[threadIdx.x+BLOCK_SIZE] = mt[threadIdx.x+i+BLOCK_SIZE];
	}
      __syncthreads();
    }
		
  if (threadIdx.x==0) 
    {
      g_vars[blockIdx.x] = (((float*)mt)[0])/NSQUARE2-1; 
      // D(X)=E(X^2)-E(X)^2, E(X)=1
      g_maxs[blockIdx.x] = (int)mt[BLOCK_SIZE];
    }
}

// Kernel function for simulating Petri Net for a defined grid
// n: the grid has 2nX2n places and transitions together
// s: steps in each trajectory
// t: number of trajectories
__global__ 
void PetrinetKernel(int* g_s, float* g_v, int* g_m, int n, int s, int seed) 
{
  // block size must be 256
  // n is an even number
  int NSQUARE2 = n*n*2;
  int* g_places = g_s+blockIdx.x*((NSQUARE2>>2)+NSQUARE2);   
  // place numbers, conflict_array
  initialize_grid(g_places, NSQUARE2, seed);
  
  run_trajectory(g_places, n, s);
  compute_reward_stat(g_places, g_v, g_m, NSQUARE2);
}

#endif // #ifndef _PETRINET_KERNEL_H_
