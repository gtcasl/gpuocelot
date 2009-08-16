/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/*
 * CUDA code for creating the FHD data structure for fast convolution-based 
 * Hessian multiplication for arbitrary k-space trajectories.
 * 
 * recommended g++ options:
 *   -O3 -lm -ffast-math -funroll-all-loops
 *
 * Inputs:
 * kx - VECTOR of kx values, same length as ky and kz
 * ky - VECTOR of ky values, same length as kx and kz
 * kz - VECTOR of kz values, same length as kx and ky
 * x  - VECTOR of x values, same length as y and z
 * y  - VECTOR of y values, same length as x and z
 * z  - VECTOR of z values, same length as x and y
 * phi - VECTOR of the Fourier transform of the spatial basis 
 *     function, evaluated at [kx, ky, kz].  Same length as kx, ky, and kz.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

#include <parboil.h>

#include "file.h"
#include "computeFH.cu"

static void
setupMemoryGPU(int num, int size, float*& dev_ptr, float*& host_ptr)
{
  cudaMalloc ((void **) &dev_ptr, num * size);
  CUDA_ERRCK;
  cudaMemcpy (dev_ptr, host_ptr, num * size, cudaMemcpyHostToDevice);
  CUDA_ERRCK;
}

static void
cleanupMemoryGPU(int num, int size, float *& dev_ptr, float * host_ptr)
{
  cudaMemcpy (host_ptr, dev_ptr, num * size, cudaMemcpyDeviceToHost);
  CUDA_ERRCK;
  cudaFree(dev_ptr);
  CUDA_ERRCK;
}

int
main (int argc, char *argv[])
{
  int numX, numK;		/* Number of X and K values */
  int original_numK;		/* Number of K values in input file */
  float *kx, *ky, *kz;		/* K trajectory (3D vectors) */
  float *x, *y, *z;		/* X coordinates (3D vectors) */
  float *phiR, *phiI;		/* Phi values (complex) */
  float *dR, *dI;		/* D values (complex) */
  float *realRhoPhi, *imagRhoPhi;  /* RhoPhi values (complex) */
  float *outI, *outR;		/* Output signal (complex) */
  kValues* kVals;		/* Copy of X and RhoPhi.  Its
				 * data layout has better cache
				 * performance. */

  struct pb_Parameters *params;
  struct pb_TimerSet timers;

  pb_InitializeTimerSet(&timers);

  /* Read command line */
  params = pb_ReadParameters(&argc, argv);
  if ((params->inpFiles[0] == NULL) || (params->inpFiles[1] != NULL))
    {
      fprintf(stderr, "Expecting one input filename\n");
      exit(-1);
    }

  /* Read in data */
  pb_SwitchToTimer(&timers, pb_TimerID_IO);
  inputData(params->inpFiles[0],
	    &original_numK, &numX,
	    &kx, &ky, &kz,
	    &x, &y, &z,
	    &phiR, &phiI,
	    &dR, &dI);

  /* Reduce the number of k-space samples if a number is given
   * on the command line */
  if (argc < 2)
    numK = original_numK;
  else
    {
      int inputK;
      char *end;
      inputK = strtol(argv[1], &end, 10);
      if (end == argv[1])
	{
	  fprintf(stderr, "Expecting an integer parameter\n");
	  exit(-1);
	}

      numK = MIN(inputK, original_numK);
    }

  printf("%d pixels in output; %d samples in trajectory; using %d samples\n",
         numX, original_numK, numK);

  pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);

  /* Create CPU data structures */
  createDataStructs(numK, numX, realRhoPhi, imagRhoPhi, outR, outI);
  kVals = (kValues*)calloc(numK, sizeof (kValues));

  /* GPU section 1 (precompute Rho, Phi)*/
  {
    /* Mirror several data structures on the device */
    float *phiR_d, *phiI_d;
    float *dR_d, *dI_d;
    float *realRhoPhi_d, *imagRhoPhi_d;

    pb_SwitchToTimer(&timers, pb_TimerID_COPY);
    setupMemoryGPU(numK, sizeof(float), phiR_d, phiR);
    setupMemoryGPU(numK, sizeof(float), phiI_d, phiI);
    setupMemoryGPU(numK, sizeof(float), dR_d, dR);
    printf( "First dR %f, %x, %x\n", *dR, dR, dR_d );
    setupMemoryGPU(numK, sizeof(float), dI_d, dI);
    cudaMalloc((void **)&realRhoPhi_d, numK * sizeof(float));
    CUDA_ERRCK;
    cudaMalloc((void **)&imagRhoPhi_d, numK * sizeof(float));
    CUDA_ERRCK;

    if (params->synchronizeGpu) cudaThreadSynchronize();
    pb_SwitchToTimer(&timers, pb_TimerID_GPU);

    /* Pre-compute the values of rhoPhi on the GPU */
    computeRhoPhi_GPU(numK, phiR_d, phiI_d, dR_d, dI_d, 
		      realRhoPhi_d, imagRhoPhi_d);

    if (params->synchronizeGpu) cudaThreadSynchronize();
    pb_SwitchToTimer(&timers, pb_TimerID_COPY);

    cleanupMemoryGPU(numK, sizeof(float), realRhoPhi_d, realRhoPhi);
    cleanupMemoryGPU(numK, sizeof(float), imagRhoPhi_d, imagRhoPhi);
    cudaFree(phiR_d);
    cudaFree(phiI_d);
    cudaFree(dR_d);
    cudaFree(dI_d);
  }

  pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);

  /* Fill in kVals values */
  for (int k = 0; k < numK; k++) {
    kVals[k].Kx = kx[k];
    kVals[k].Ky = ky[k];
    kVals[k].Kz = kz[k];
    kVals[k].RhoPhiR = realRhoPhi[k];
    kVals[k].RhoPhiI = imagRhoPhi[k];
  }

  pb_SwitchToTimer(&timers, pb_TimerID_COPY);

  /* GPU section 2 (compute FH)*/
  {
    float *x_d, *y_d, *z_d;
    float *outI_d, *outR_d;

    /* Mirror several data structures on the device */
    setupMemoryGPU(numX, sizeof(float), x_d, x);
    setupMemoryGPU(numX, sizeof(float), y_d, y);
    setupMemoryGPU(numX, sizeof(float), z_d, z);

    // Zero out initial values of outR and outI.
    // GPU veiws these arrays as initialized (cleared) accumulators.
    cudaMalloc((void **)&outR_d, numX * sizeof(float));
    CUDA_ERRCK;
    cudaMemset(outR_d, 0, numX * sizeof(float));
    CUDA_ERRCK;
    cudaMalloc((void **)&outI_d, numX * sizeof(float));
    CUDA_ERRCK;
    cudaMemset(outI_d, 0, numX * sizeof(float));
    CUDA_ERRCK;

    if (params->synchronizeGpu) cudaThreadSynchronize();
    pb_SwitchToTimer(&timers, pb_TimerID_GPU);

    /* Compute FH on the GPU (main computation) */
    computeFH_GPU(numK, numX, x_d, y_d, z_d, kVals, outR_d, outI_d);

    if (params->synchronizeGpu) cudaThreadSynchronize();
    pb_SwitchToTimer(&timers, pb_TimerID_COPY);

    /* Release memory on GPU */
    cleanupMemoryGPU(numX, sizeof(float), outR_d, outR);
    cleanupMemoryGPU(numX, sizeof(float), outI_d, outI);

    cudaFree(x_d);
    cudaFree(y_d);
    cudaFree(z_d);
  }

  pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);

  if (params->outFile)
    {
      /* Write result to file */
      pb_SwitchToTimer(&timers, pb_TimerID_IO);
      outputData(params->outFile, outR, outI, numX);
      pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
    }

  if( compareData("data/mriFhdOut.bin", outR, outI, numX, 1) )
  {
    printf("TEST PASSED\n");
  }
  else
  {
  	printf("TEST FAILED\n");
  }

  free (kx);
  free (ky);
  free (kz);
  free (x);
  free (y);
  free (z);
  free (phiR);
  free (phiI);
  free (dR);
  free (dI);
  free (realRhoPhi);
  free (imagRhoPhi);
  free (kVals);
  free (outR);
  free (outI);

  pb_SwitchToTimer(&timers, pb_TimerID_NONE);
  pb_PrintTimerSet(&timers);
  pb_FreeParameters(params);

  return 0;
}
