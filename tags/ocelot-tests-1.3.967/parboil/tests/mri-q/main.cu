/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/* 
 * C code for creating the Q data structure for fast convolution-based 
 * Hessian multiplication for arbitrary k-space trajectories.
 *
 * Inputs:
 * kx - VECTOR of kx values, same length as ky and kz
 * ky - VECTOR of ky values, same length as kx and kz
 * kz - VECTOR of kz values, same length as kx and ky
 * x  - VECTOR of x values, same length as y and z
 * y  - VECTOR of y values, same length as x and z
 * z  - VECTOR of z values, same length as x and y
 * phi - VECTOR of the Fourier transform of the spatial basis 
 *      function, evaluated at [kx, ky, kz].  Same length as kx, ky, and kz.
 *
 * recommended g++ options:
 *  -O3 -lm -ffast-math -funroll-all-loops
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include <malloc.h>

#include <parboil.h>

#include "file.h"
#include "computeQ.cu"

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
main (int argc, char *argv[]) {
  int numX, numK;		/* Number of X and K values */
  int original_numK;		/* Number of K values in input file */
  float *kx, *ky, *kz;		/* K trajectory (3D vectors) */
  float *x, *y, *z;		/* X coordinates (3D vectors) */
  float *phiR, *phiI;		/* Phi values (complex) */
  float *phiMag;		/* Magnitude of Phi */
  float *Qr, *Qi;		/* Q signal (complex) */

  struct kValues* kVals;

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
	    &phiR, &phiI);

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
  createDataStructsCPU(numK, numX, &phiMag, &Qr, &Qi);

  /* GPU section 1 (precompute PhiMag) */
  {
    /* Mirror several data structures on the device */
    float *phiR_d, *phiI_d;
    float *phiMag_d;

    pb_SwitchToTimer(&timers, pb_TimerID_COPY);
    setupMemoryGPU(numK, sizeof(float), phiR_d, phiR);
    setupMemoryGPU(numK, sizeof(float), phiI_d, phiI);
    cudaMalloc((void **)&phiMag_d, numK * sizeof(float));
    CUDA_ERRCK;

    if (params->synchronizeGpu) cudaThreadSynchronize();
    pb_SwitchToTimer(&timers, pb_TimerID_GPU);

    computePhiMag_GPU(numK, phiR_d, phiI_d, phiMag_d);

    if (params->synchronizeGpu) cudaThreadSynchronize();
    pb_SwitchToTimer(&timers, pb_TimerID_COPY);

    cleanupMemoryGPU(numK, sizeof(float), phiMag_d, phiMag);
    cudaFree(phiR_d);
    cudaFree(phiI_d);
  }

  pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);

  kVals = (struct kValues*)calloc(numK, sizeof (struct kValues));
  for (int k = 0; k < numK; k++) {
    kVals[k].Kx = kx[k];
    kVals[k].Ky = ky[k];
    kVals[k].Kz = kz[k];
    kVals[k].PhiMag = phiMag[k];
  }

  free(phiMag);

  /* GPU section 2 */
  {
    float *x_d, *y_d, *z_d;
    float *Qr_d, *Qi_d;

    pb_SwitchToTimer(&timers, pb_TimerID_COPY);

    setupMemoryGPU(numX, sizeof(float), x_d, x);
    setupMemoryGPU(numX, sizeof(float), y_d, y);
    setupMemoryGPU(numX, sizeof(float), z_d, z);
    cudaMalloc((void **)&Qr_d, numX * sizeof(float));
    CUDA_ERRCK;
    cudaMemset((void *)Qr_d, 0, numX * sizeof(float));
    cudaMalloc((void **)&Qi_d, numX * sizeof(float));
    CUDA_ERRCK;
    cudaMemset((void *)Qi_d, 0, numX * sizeof(float));

    if (params->synchronizeGpu) cudaThreadSynchronize();
    pb_SwitchToTimer(&timers, pb_TimerID_GPU);

    computeQ_GPU(numK, numX, x_d, y_d, z_d, kVals, Qr_d, Qi_d);

    if (params->synchronizeGpu) cudaThreadSynchronize();
    pb_SwitchToTimer(&timers, pb_TimerID_COPY);

    cudaFree(x_d);
    cudaFree(y_d);
    cudaFree(z_d);
    cleanupMemoryGPU(numX, sizeof(float), Qr_d, Qr);
    cleanupMemoryGPU(numX, sizeof(float), Qi_d, Qi);
  }

  pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);

  if (params->outFile)
    {
      /* Write Q to file */
      pb_SwitchToTimer(&timers, pb_TimerID_IO);
      outputData(params->outFile, Qr, Qi, numX);
      pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
    }

  if( compareData("data/mriQOut.bin", Qr, Qi, numX, 1) )
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
  free (kVals);
  free (Qr);
  free (Qi);

  pb_SwitchToTimer(&timers, pb_TimerID_NONE);
  pb_PrintTimerSet(&timers);

  pb_FreeParameters(params);

  return 0;
}
