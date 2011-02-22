/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <parboil.h>

#define CUDA_ERRCK \
  {cudaError_t err = cudaGetLastError(); \
    if (err) fprintf(stderr, "CUDA error: %s\n", cudaGetErrorString(err)); \
  }

/*
// Place and Transition are implicitly included in the code
// as the grid is a fixed one
typedef struct {
        float mark;
} Place;

typedef struct {
        int from1, from2;
        int to1, to2;
} Transition;

// this starts from row 0 and col 0
P(r,c)    -> T(r,c)   -> P(r,c+1)  ->
  |            |            |
 \/           \/           \/
T(r+1,c-1)-> P(r+1,c) -> T(r+1,c)  ->
  |            |            |
 \/           \/           \/
P(r+2,c)  -> T(r+2,c) -> P(r+2,c+1)->
  |            |            |
 \/           \/           \/
T(r+3,c-1)-> P(r+3,c) -> T(r+3,c)->
  |            |            |
 \/           \/           \/

*/

#include "rand_gen.cuh"
#include "petri_kernel.cuh"

static int N, s, t, N2, NSQUARE2;
uint32 host_mt[MERS_N];


void* AllocateDeviceMemory(int size);
void CopyFromDeviceMemory(void* h_p, void* d_p, int size);
void CopyFromHostMemory(void* d_p, void* h_p, int size);
void FreeDeviceMemory(void* mem);
void PetrinetOnDevice(struct pb_TimerSet *timers, 
                      struct pb_Parameters *params);
void compute_statistics();

float results[4];
float* h_vars;
int* h_maxs;

int main(int argc, char** argv) 
{
  struct pb_TimerSet timers;
  struct pb_Parameters *params;

  pb_InitializeTimerSet( &timers );
  params = pb_ReadParameters( &argc, argv );

  if (argc<4) 
    {
      printf("Usage: petri n s t\n"
	     "n: the place-transition grid is 2nX2n\n"
	     "s: the maximum steps in a trajectory\n"
	     "t: number of trajectories\n");
      return -1;
    }

  pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );
  N = atoi(argv[1]);
  if (N<1)
    return -1;
  s = atoi(argv[2]);
  if (s<1)
    return -1;

  t = atoi(argv[3]);
  if (t<1)
    return -1;

  N2 = N+N;
  NSQUARE2 = N*N2;
  
  h_vars = (float*)malloc(t*sizeof(float));
  h_maxs = (int*)malloc(t*sizeof(int));
  
  // compute the simulation on the GPU
  PetrinetOnDevice( &timers, params );
  pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );

  compute_statistics();

  free(h_vars);
  free(h_maxs);
    
  pb_SwitchToTimer( &timers, pb_TimerID_IO );

  printf("petri N=%d s=%d t=%d\n", N, s, t);
  printf("mean_vars: %f    var_vars: %f\n", results[0], results[1]);
  printf("mean_maxs: %f    var_maxs: %f\n", results[2], results[3]);

  if(params->outFile)
    {
      FILE *out;
      out = fopen(params->outFile, "w");
      fprintf(out, "%f %f %f %f\n", results[0], results[1], results[2],
              results[3]);
      fclose(out);
    }

  if( pb_compareFiles(params->outFile, "data/pns.out", 1) )
  {
    printf("TEST PASSED\n");
  }
  else
  {
  	printf("TEST FAILED\n");
  }

  pb_SwitchToTimer ( &timers, pb_TimerID_NONE );
  pb_PrintTimerSet( &timers );
  pb_FreeParameters( params );

  return 0;
}

void compute_statistics() 
{
  float sum = 0;
  float sum_vars = 0;
  float sum_max = 0;
  float sum_max_vars = 0;
  int i;
  for (i=0; i<t; i++) 
    {
      sum += h_vars[i];
      sum_vars += h_vars[i]*h_vars[i];
      sum_max += h_maxs[i];
      sum_max_vars += h_maxs[i]*h_maxs[i];
    }
  results[0] = sum/t;
  results[1] = sum_vars/t - results[0]*results[0];
  results[2] = sum_max/t;
  results[3] = sum_max_vars/t - results[2]*results[2];
}

void PetrinetOnDevice(struct pb_TimerSet *timers, 
                      struct pb_Parameters *params)
{
  // Allocate memory
  int i;
  int unit_size = NSQUARE2*(sizeof(int)+sizeof(char))+
    sizeof(float)+sizeof(int);
  int block_num = MAX_DEVICE_MEM/unit_size;
  int *p_hmaxs;
  float *p_hvars;
  int* g_places;
  float* g_vars;
  int* g_maxs;
  
  pb_SwitchToTimer( timers, pb_TimerID_COPY );
  g_places = (int*)AllocateDeviceMemory((unit_size- sizeof(float)-
					      sizeof(int))*block_num);
  CUDA_ERRCK
  g_vars = (float*)AllocateDeviceMemory(block_num*sizeof(float));
  CUDA_ERRCK
  g_maxs = (int*)AllocateDeviceMemory(block_num*sizeof(int));
  CUDA_ERRCK

  // Setup the execution configuration
  dim3  grid(block_num);  // number of blocks
  dim3  threads(256);  // each block has 256 threads

  p_hmaxs = h_maxs;
  p_hvars = h_vars;

  // Launch the device computation threads!
  for (i = 0; i<t-block_num; i+=block_num) 
    {
      if (params->synchronizeGpu) cudaThreadSynchronize();
      pb_SwitchToTimer( timers, pb_TimerID_GPU );
      PetrinetKernel<<< grid, threads>>>
	(g_places, g_vars, g_maxs, N, s, 5489*(i+1));
      CUDA_ERRCK

      if (params->synchronizeGpu) cudaThreadSynchronize();
      pb_SwitchToTimer( timers, pb_TimerID_COPY );
      CopyFromDeviceMemory(p_hmaxs, g_maxs, block_num*sizeof(int));
      CUDA_ERRCK
      CopyFromDeviceMemory(p_hvars, g_vars, block_num*sizeof(float));
      CUDA_ERRCK
      if (params->synchronizeGpu) cudaThreadSynchronize();

      pb_SwitchToTimer( timers, pb_TimerID_COMPUTE );
      p_hmaxs += block_num;
      p_hvars += block_num;
    }
	
  dim3 grid1(t-i);
  pb_SwitchToTimer( timers, pb_TimerID_GPU );
  PetrinetKernel<<< grid1, threads>>>
    (g_places, g_vars, g_maxs, N, s, time(NULL));
  CUDA_ERRCK

  // Read result from the device
  if (params->synchronizeGpu) cudaThreadSynchronize();
  pb_SwitchToTimer( timers, pb_TimerID_COPY );
  CopyFromDeviceMemory(p_hmaxs, g_maxs, (t-i)*sizeof(int));
  CUDA_ERRCK
  CopyFromDeviceMemory(p_hvars, g_vars, (t-i)*sizeof(float));
  CUDA_ERRCK

  // Free device matrices
  FreeDeviceMemory(g_places);
  CUDA_ERRCK
  FreeDeviceMemory(g_vars);
  CUDA_ERRCK
  FreeDeviceMemory(g_maxs);
  CUDA_ERRCK
}

// Allocate a device matrix of same size as M.
void* AllocateDeviceMemory(int size)
{
  int* mem;
  cudaMalloc((void**)&mem, size);
  return mem;
}

// Copy device memory to host memory
void CopyFromDeviceMemory(void* h_p, void* d_p, int size)
{
  cudaMemcpy(h_p, d_p, size, cudaMemcpyDeviceToHost);
}

// Copy device memory from host memory
void CopyFromHostMemory(void* d_p, void* h_p, int size)
{
  cudaMemcpy(d_p, h_p, size, cudaMemcpyHostToDevice);
}

// Free a device matrix.
void FreeDeviceMemory(void* mem)
{
  if (mem!=NULL)
    cudaFree(mem);
}

