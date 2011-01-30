/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include <cstdio>

#define PI   3.1415926535897932384626433832795029
#define PIx2 6.2831853071795864769252867665590058

/* Adjustable parameters */
#define KERNEL_RHO_PHI_THREADS_PER_BLOCK 512
#define KERNEL_FH_THREADS_PER_BLOCK 256
#define KERNEL_FH_K_ELEMS_PER_GRID 512

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

#define CUDA_ERRCK							\
  {cudaError_t err;							\
    if ((err = cudaGetLastError()) != cudaSuccess) {			\
      fprintf(stderr, "CUDA error on line %d: %s\n", __LINE__, cudaGetErrorString(err)); \
      exit(-1);								\
    }									\
  }

struct kValues {
  float Kx;
  float Ky;
  float Kz;
  float RhoPhiR;
  float RhoPhiI;
};

__constant__ __device__ kValues c[KERNEL_FH_K_ELEMS_PER_GRID];

void createDataStructs(int numK, int numX, 
                       float*& realRhoPhi, float*& imagRhoPhi, 
                       float*& outR, float*& outI)
{
  realRhoPhi = (float* ) calloc(numK, sizeof(float));
  imagRhoPhi = (float* ) calloc(numK, sizeof(float));
  outR = (float*) calloc (numX, sizeof (float));
  outI = (float*) calloc (numX, sizeof (float));
}

__global__ void
ComputeRhoPhiGPU(int numK,
                 float* phiR, float* phiI, 
                 float* dR, float* dI, 
                 float* realRhoPhi, float* imagRhoPhi)
{
  int indexK = blockIdx.x*KERNEL_RHO_PHI_THREADS_PER_BLOCK + threadIdx.x;
  if (indexK < numK) {
    float rPhiR = phiR[indexK];
    float rPhiI = phiI[indexK];
    float rDR = dR[indexK];
    float rDI = dI[indexK];
    realRhoPhi[indexK] = rPhiR * rDR + rPhiI * rDI;
    imagRhoPhi[indexK] = rPhiR * rDI - rPhiI * rDR;
  }
}

__global__ void
ComputeFH_GPU(int numK, int kGlobalIndex,
              float* x, float* y, float* z, 
              float* outR, float* outI)
{
  float sX;
  float sY;
  float sZ;
  float sOutR;
  float sOutI;

  // Determine the element of the X arrays computed by this thread
  int xIndex = blockIdx.x*KERNEL_FH_THREADS_PER_BLOCK + threadIdx.x;

  sX = x[xIndex];
  sY = y[xIndex];
  sZ = z[xIndex];
  sOutR = outR[xIndex];
  sOutI = outI[xIndex];

  // Loop over all elements of K in constant mem to compute a partial value
  // for X.
  int kIndex = 0;
  int kCnt = numK - kGlobalIndex;
  if (kCnt < KERNEL_FH_K_ELEMS_PER_GRID) {
    for (kIndex = 0;
	 (kIndex < (kCnt % 4)) && (kGlobalIndex < numK);
	 kIndex++, kGlobalIndex++) {
      float expArg = PIx2 *
	(c[kIndex].Kx * sX + c[kIndex].Ky * sY + c[kIndex].Kz * sZ);
      float cosArg = cos(expArg);
      float sinArg = sin(expArg);
      sOutR += c[kIndex].RhoPhiR * cosArg - c[kIndex].RhoPhiI * sinArg;
      sOutI += c[kIndex].RhoPhiI * cosArg + c[kIndex].RhoPhiR * sinArg;
    }
  }

  for (;
       (kIndex < KERNEL_FH_K_ELEMS_PER_GRID) && (kGlobalIndex < numK);
       kIndex += 4, kGlobalIndex += 4) {
    float expArg = PIx2 *
      (c[kIndex].Kx * sX + c[kIndex].Ky * sY + c[kIndex].Kz * sZ);
    float cosArg = cos(expArg);
    float sinArg = sin(expArg);
    sOutR += c[kIndex].RhoPhiR * cosArg - c[kIndex].RhoPhiI * sinArg;
    sOutI += c[kIndex].RhoPhiI * cosArg + c[kIndex].RhoPhiR * sinArg;
    
    int kIndex1 = kIndex + 1;
    float expArg1 = PIx2 *
      (c[kIndex1].Kx * sX + c[kIndex1].Ky * sY + c[kIndex1].Kz * sZ);
    float cosArg1 = cos(expArg1);
    float sinArg1 = sin(expArg1);
    sOutR += c[kIndex1].RhoPhiR * cosArg1 - c[kIndex1].RhoPhiI * sinArg1;
    sOutI += c[kIndex1].RhoPhiI * cosArg1 + c[kIndex1].RhoPhiR * sinArg1;

    int kIndex2 = kIndex + 2;
    float expArg2 = PIx2 *
      (c[kIndex2].Kx * sX + c[kIndex2].Ky * sY + c[kIndex2].Kz * sZ);
    float cosArg2 = cos(expArg2);
    float sinArg2 = sin(expArg2);
    sOutR += c[kIndex2].RhoPhiR * cosArg2 - c[kIndex2].RhoPhiI * sinArg2;
    sOutI += c[kIndex2].RhoPhiI * cosArg2 + c[kIndex2].RhoPhiR * sinArg2;

    int kIndex3 = kIndex + 3;
    float expArg3 = PIx2 *
      (c[kIndex3].Kx * sX + c[kIndex3].Ky * sY + c[kIndex3].Kz * sZ);
    float cosArg3 = cos(expArg3);
    float sinArg3 = sin(expArg3);
    sOutR += c[kIndex3].RhoPhiR * cosArg3 - c[kIndex3].RhoPhiI * sinArg3;
    sOutI += c[kIndex3].RhoPhiI * cosArg3 + c[kIndex3].RhoPhiR * sinArg3;    
  }

  outR[xIndex] = sOutR;
  outI[xIndex] = sOutI;
}

void computeRhoPhi_GPU(int numK, 
                       float* phiR_d, float* phiI_d, float* dR_d, float* dI_d,
                       float* realRhoPhi_d, float* imagRhoPhi_d)
{
  int rhoPhiBlocks = numK / KERNEL_RHO_PHI_THREADS_PER_BLOCK;

  if (numK % KERNEL_RHO_PHI_THREADS_PER_BLOCK)
    rhoPhiBlocks++;

  dim3 DimRhoPhiBlock(KERNEL_RHO_PHI_THREADS_PER_BLOCK, 1);
  dim3 DimRhoPhiGrid(rhoPhiBlocks, 1);
  printf("Launch RhoPhi Kernel on GPU: Blocks (%d, %d), Threads Per Block %d\n",
         rhoPhiBlocks, 1, KERNEL_RHO_PHI_THREADS_PER_BLOCK);

  ComputeRhoPhiGPU <<< DimRhoPhiGrid, DimRhoPhiBlock >>> 
      (numK, phiR_d, phiI_d, dR_d, dI_d, realRhoPhi_d, imagRhoPhi_d);
}

void computeFH_GPU(int numK, int numX, 
                   float* x_d, float* y_d, float* z_d,
                   kValues* kVals,
                   float* outR_d, float* outI_d)
{
  int FHGrids = numK / KERNEL_FH_K_ELEMS_PER_GRID;
  if (numK % KERNEL_FH_K_ELEMS_PER_GRID)
    FHGrids++;
  int FHBlocks = numX / KERNEL_FH_THREADS_PER_BLOCK;
  if (numX % KERNEL_FH_THREADS_PER_BLOCK)
    FHBlocks++;
  dim3 DimFHBlock(KERNEL_FH_THREADS_PER_BLOCK, 1);
  dim3 DimFHGrid(FHBlocks, 1);

  printf("Launch GPU Kernel: Grids %d, Blocks Per Grid (%d, %d), Threads Per Block (%d, %d), K Elems Per Thread %d\n",
         FHGrids, DimFHGrid.x, DimFHGrid.y, DimFHBlock.x, DimFHBlock.y, KERNEL_FH_K_ELEMS_PER_GRID);

  for (int FHGrid = 0; FHGrid < FHGrids; FHGrid++) {
    // Put the tile of K values into constant mem
    int FHGridBase = FHGrid * KERNEL_FH_K_ELEMS_PER_GRID;

    kValues* kValsTile = kVals + FHGridBase;
    int numElems = MIN(KERNEL_FH_K_ELEMS_PER_GRID, numK - FHGridBase);
	printf("Copying %d bytes to constant memory\n", numElems * sizeof(kValues));
    cudaMemcpyToSymbol(c, kValsTile, numElems * sizeof(kValues), 0);
    CUDA_ERRCK;

    ComputeFH_GPU <<< DimFHGrid, DimFHBlock >>>
      (numK, FHGridBase, x_d, y_d, z_d, outR_d, outI_d);
    CUDA_ERRCK;
  }
}
