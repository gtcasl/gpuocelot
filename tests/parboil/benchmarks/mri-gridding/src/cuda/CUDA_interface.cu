/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#include <stdio.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "parboil.h"

#include "UDTypes.h"
#include "scanLargeArray.h"
#include "GPU_kernels.cu"
#include "CPU_kernels.h"

#define USE_CUDPP 0
#if USE_CUDPP
#include "cudpp.h"
#else
#include "sort.h"
#include "scanLargeArray.h"
#endif

#define BLOCKSIZE 512
#define PI 3.14159265359

// Compare function used for Qsort for CPU computation
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

/***********************************************************************
 * CUDA_interface is the main function for GPU execution. This
 * implementation uses compact binning to distribute input elements
 * into unit-cubed sized bins. The bins are then visited by GPU
 * threads, where every thread computes the value of one (or small set)
 * of output elements by computing the contributions of elements in 
 * neighboring bins to these output elements.
 *
 * The bins have a limited bin size and everything beyond that bin size
 * is offloaded to the CPU to be computed in parallel with the GPU
 * gridding.
 ***********************************************************************/
void CUDA_interface (
  struct pb_TimerSet* timers,
  unsigned int n,       // Number of input elements
  parameters params,    // Parameter struct which defines output gridSize, cutoff distance, etc.
  ReconstructionSample* sample, // Array of input elements
  float* LUT,           // Precomputed LUT table of Kaiser-Bessel function. 
                          // Used for computation on CPU instead of using the function every time
  int sizeLUT,          // Size of LUT
  cmplx* gridData,      // Array of output grid points. Each element has a real and imaginary component
  float* sampleDensity  // Array of same size as gridData couting the number of contributions
                          // to each grid point in the gridData array
){

  /* Initializing all variables */
  dim3 dims (8,4,2); //size of a gridding block on the GPU

  /* x, y, z dimensions of the output grid (gridData) */
  int size_x = params.gridSize[0];
  int size_y = params.gridSize[1];
  int size_z = params.gridSize[2];
  int size_xy = size_y*size_x;

  int gridNumElems = size_x * size_y * size_z;  // Total number of grid points

  float beta = PI * sqrt(4*params.kernelWidth*params.kernelWidth/(params.oversample*params.oversample) * (params.oversample-.5)*(params.oversample-.5)-.8);

  float cutoff = float(params.kernelWidth)/2.0; // cutoff radius
  float cutoff2 = cutoff*cutoff;                // square of cutoff radius
  float _1overCutoff2 = 1/cutoff2;              // 1 over square of cutoff radius

  // Padding used to align the structure of arrays used for the sorted input elements
  int npad = 0;
  if (n % 64 != 0){
    npad = 64 - (n%64);
  }

  /* Declarations of host data structures */
  cmplx* gridData_CPU;
  float* sampleDensity_CPU;
  int* indices_CPU;

  /* Declarations of device data structures */
  ReconstructionSample* sample_d = NULL;    // Device array for original input array
  float* sortedSample_d = NULL;             // Device array of the sorted (into bins) input elements.
                                            // This array is accessed by sortedSampleSoA_d in a structure
                                            //   of arrays manner.
  float2* gridData_d = NULL;                // Device array for output grid
  float* sampleDensity_d = NULL;            // Device array for output sample density
  unsigned int* idxKey_d = NULL;            // Array of bin indeces generated in the binning kernel
                                            //   and used to sort the input elements into their
                                            //   corresponding bins
  unsigned int* idxValue_d = NULL;          // This array holds the indices of input elements in the
                                            //   the original array. This array is sorted using the
                                            //   the idxKey_d array, and once sorted, it is used in
                                            //   the reorder kernel to move the actual elements into
                                            //   their corresponding bins.
  sampleArrayStruct sortedSampleSoA_d;      // Structure of Arrays which holds the sorted input elements.
                                            //   Uses sortedSample_d as the underlying physical data
                                            //   structures
  unsigned int* binCount_d = NULL;          // Zero-initialized array which counts the number of elements
                                            //   put in each bin. Based on this array, we determine which
                                            //   elements get offloaded to the CPU
  unsigned int* binStartAddr_d = NULL;      // Array of start offset of each of the compact bins

  /* Allocating device memory */
  pb_SwitchToTimer(timers, pb_TimerID_COPY);

  cudaMalloc((void**)&sortedSample_d, (n+npad)*sizeof(ReconstructionSample));
  cudaMalloc((void**)&binStartAddr_d, (gridNumElems+1)*sizeof(unsigned int));
  cudaMalloc((void**)&sample_d, n*sizeof(ReconstructionSample));
  cudaMalloc((void**)&idxKey_d, (((n+3)/4)*4)*sizeof(unsigned int));   //Pad to nearest multiple of 4 to 
  cudaMalloc((void**)&idxValue_d, (((n+3)/4)*4)*sizeof(unsigned int)); //satisfy a property of the sorting kernel.

/*The CUDPP library features highly optimizes implementations for radix sort
  and prefix sum. However for portability reasons, we implemented our own,
  slightly less optimized versions of these operations. When performing
  prefix sum using CUDPP, the output array has to be different from the input
  array, which is why we would allocate an array for binCount_d. For our
  implementation, we allow the input and output arrays to be the same,
  therefore we reuse the binCount_d array to get the starting offset of each
  bin. */
#if USE_CUDPP
  cudaMalloc((void**)&binCount_d, (gridNumElems+1)*sizeof(unsigned int));
#else
  binCount_d = binStartAddr_d;
#endif

  /* Transfering data from Host to Device */
  cudaMemcpyToSymbol(cutoff2_c, &cutoff2, sizeof(float), 0);
  cudaMemcpyToSymbol(cutoff_c, &cutoff, sizeof(float), 0);
  cudaMemcpyToSymbol(gridSize_c, params.gridSize, 3*sizeof(int), 0);
  cudaMemcpyToSymbol(size_xy_c, &size_xy, sizeof(int), 0);
  cudaMemcpyToSymbol(_1overCutoff2_c, &_1overCutoff2, sizeof(float), 0);
  cudaMemcpy(sample_d, sample, n*sizeof(ReconstructionSample), cudaMemcpyHostToDevice);
  cudaMemset(binCount_d, 0, (gridNumElems+1)*sizeof(unsigned int));

  // Initialize padding to max integer value, so that when sorted,
  // these elements get pushed to the end of the array.
  cudaMemset(idxKey_d+n, 0xFF, (((n+3)&~(3))-n)*sizeof(unsigned int));

  sortedSampleSoA_d.data = (float2*)(sortedSample_d);
  sortedSampleSoA_d.loc = (float4*)(sortedSample_d+2*(n+npad));

  pb_SwitchToTimer(timers, pb_TimerID_GPU);

  /* STEP 1: Perform binning. This kernel determines which output bin each input element
   * goes into. Any excess (beyond binsize) is put in the CPU bin
   */
  dim3 block1 (BLOCKSIZE);
  dim3 grid1 ((n+BLOCKSIZE-1)/BLOCKSIZE);

  binning_kernel<<<grid1, block1>>>(n, sample_d, idxKey_d, idxValue_d, binCount_d, params.binsize, gridNumElems);

  /* STEP 2: Sort the index-value pair generate in the binning kernel */
#if USE_CUDPP
  CUDPPConfiguration config;
  config.datatype = CUDPP_UINT;
  config.algorithm = CUDPP_SORT_RADIX;
  config.options = CUDPP_OPTION_KEY_VALUE_PAIRS;

  CUDPPHandle sortplan = 0;
  CUDPPResult result = cudppPlan(&sortplan, config, n, 1, 0);

  int precision = 0;
  int numElems = gridNumElems;
  while (numElems > 0){
    numElems >>= 1;
    precision++;
  }

  cudppSort(sortplan, idxKey_d, idxValue_d, int(precision), n);
  result = cudppDestroyPlan(sortplan);
#else
  sort(n, gridNumElems+1, idxKey_d, idxValue_d);
#endif

  /* STEP 3: Reorder the input data, based on the sorted values from Step 2.
   * this step also involves changing the data from array of structs to a struct
   * of arrays. Also in this kernel, we populate an array with the starting index
   * of every output bin features in the input array, based on the sorted indices 
   * from Step 2.
   * At the end of this step, we copy the start address and list of input elements
   * that will be computed on the CPU.
   */
  reorder_kernel<<<grid1,block1>>>(n, idxValue_d, sample_d, sortedSampleSoA_d);

  pb_SwitchToTimer(timers, pb_TimerID_COPY);

  cudaFree(idxKey_d);
  cudaFree(sample_d);

  pb_SwitchToTimer(timers, pb_TimerID_GPU);

  /* STEP 4: In this step we generate the ADD scan of the array of starting indices
   * of the output bins. The result is an array that contains the starting address of
   * every output bin.
   */
#if USE_CUDPP
  config.datatype = CUDPP_UINT;
  config.algorithm = CUDPP_SCAN;
  config.options = CUDPP_OPTION_EXCLUSIVE;
  config.op=CUDPP_ADD;

  CUDPPHandle scanplan = 0;
  result = cudppPlan(&scanplan, config, gridNumElems+1, 1, 0);

  cudppScan(scanplan, binCount_d, binStartAddr_d, gridNumElems+1);
  result = cudppDestroyPlan(scanplan);
#else
  scanLargeArray(gridNumElems+1, binCount_d);
#endif

  pb_SwitchToTimer(timers, pb_TimerID_COPY);

  // Copy back to the CPU the indices of the input elements that will be processed on the CPU
  int cpuStart;
  cudaMemcpy(&cpuStart, binCount_d+gridNumElems, sizeof(unsigned int), cudaMemcpyDeviceToHost);

  int CPUbin_size = int(n)-int(cpuStart);

  int* CPUbin;
  cudaMallocHost((void**)&CPUbin,CPUbin_size*sizeof(unsigned int));
  cudaMemcpy(CPUbin, idxValue_d+cpuStart, CPUbin_size*sizeof(unsigned int), cudaMemcpyDeviceToHost);

  cudaFree(idxValue_d);
#if USE_CUDPP
  cudaFree(binCount_d);
#endif

  /* STEP 5: Perform the binning on the GPU. The results are computed in a gather fashion
   * where each thread computes the value of one output element by reading the relevant
   * bins.
   */
  cudaMalloc((void**)&gridData_d, gridNumElems*sizeof(float2));
  cudaMalloc((void**)&sampleDensity_d, gridNumElems*sizeof(float));

  cudaMemset(gridData_d, 0, gridNumElems*sizeof(float2));
  cudaMemset(sampleDensity_d, 0, gridNumElems*sizeof(float));

  pb_SwitchToTimer(timers, pb_TimerID_GPU);

  dim3 block2 (dims.x,dims.y,dims.z);
  dim3 grid2 (size_x/dims.x, (size_y*size_z)/(4*dims.y*dims.z));

  gridding_GPU<<<grid2, block2>>>(sortedSampleSoA_d, binStartAddr_d, gridData_d, sampleDensity_d, beta);

  pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);

  qsort(CPUbin, CPUbin_size, sizeof(int), compare); //Sorting helps cache locality of input element array
  int num = gridding_CPU(n, params, sample, CPUbin, CPUbin_size, LUT, sizeLUT, &gridData_CPU, &sampleDensity_CPU, &indices_CPU);

  pb_SwitchToTimer(timers, pb_TimerID_COPY);

  /* Copying the results from the Device to the Host */
  cudaMemcpy(sampleDensity, sampleDensity_d, gridNumElems*sizeof(float),cudaMemcpyDeviceToHost);
  cudaMemcpy(gridData, gridData_d, gridNumElems*sizeof(float2),cudaMemcpyDeviceToHost);

  pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);

  /* STEP 6: Computing the contributions of the sample points handled by the Host
   * and adding those to the GPU results.
   */
  for (int i=0; i< num; i++){
    gridData[indices_CPU[i]].real += gridData_CPU[i].real;
    gridData[indices_CPU[i]].imag += gridData_CPU[i].imag;
    sampleDensity[indices_CPU[i]] += sampleDensity_CPU[i];
  }

  if (gridData_CPU != NULL){
    free(indices_CPU);
    free(gridData_CPU);
    free(sampleDensity_CPU);
  }

  pb_SwitchToTimer(timers, pb_TimerID_COPY);

  cudaFreeHost(CPUbin);
  cudaFree(gridData_d);
  cudaFree(sampleDensity_d);
  cudaFree(binCount_d);
  cudaFree(sortedSample_d);

  pb_SwitchToTimer(timers, pb_TimerID_NONE);

  return;
}
