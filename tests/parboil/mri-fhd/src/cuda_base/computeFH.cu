/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#define PI   3.1415926535897932384626433832795029
#define PIx2 6.2831853071795864769252867665590058

/* Adjustable parameters */
#define KERNEL_RHO_PHI_THREADS_PER_BLOCK 512
#define KERNEL_FH_THREADS_PER_BLOCK 256
#define KERNEL_FH_K_ELEMS_PER_GRID 512
#define KERNEL_FH_X_ELEMS_PER_THREAD 1

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
                       float*& outR, float*& outI)
{
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
              float* cKx, float* cKy, float* cKz,
              float* x, float* y, float* z,
              float* cRhoPhiR, float* cRhoPhiI,
              float* outR, float* outI) {
  float sX;
  float sY;
  float sZ;
  float sOutR;
  float sOutI;

  // Determine the element of the X arrays computed by this thread
  int xIndex = blockIdx.x*KERNEL_FH_THREADS_PER_BLOCK + threadIdx.x;

  // Read block's X values from global mem to shared mem
  sX = x[xIndex];
  sY = y[xIndex];
  sZ = z[xIndex];
  sOutR = outR[xIndex];
  sOutI = outI[xIndex];

  // Loop over all elements of K in constant mem to compute a partial value
  // for X.
  for (int kIndex = 0;
       (kIndex < KERNEL_FH_K_ELEMS_PER_GRID) && (kGlobalIndex < numK);
       kIndex++, kGlobalIndex++) {
    float exponentArg = PIx2 * (cKx[kIndex] * sX +
				cKy[kIndex] * sY +
				cKz[kIndex] * sZ);

    float cosArg = cos(exponentArg);
    float sinArg = sin(exponentArg);

    sOutR += cRhoPhiR[kIndex] * cosArg - cRhoPhiI[kIndex] * sinArg;
    sOutI += cRhoPhiI[kIndex] * cosArg + cRhoPhiR[kIndex] * sinArg;
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

  ComputeRhoPhiGPU <<< DimRhoPhiGrid, DimRhoPhiBlock >>> 
      (numK, phiR_d, phiI_d, dR_d, dI_d, realRhoPhi_d, imagRhoPhi_d);
}

void computeFH_GPU(int numK, int numX, 
                   float* kx_d, float* ky_d, float* kz_d,
                   float* realRhoPhi_d, float* imagRhoPhi_d,
                   float* x_d, float* y_d, float* z_d,
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

  for (int FHGrid = 0; FHGrid < FHGrids; FHGrid++) {
    int FHGridBase = FHGrid * KERNEL_FH_K_ELEMS_PER_GRID;
    float *rhoPhiRTile = realRhoPhi_d + FHGridBase;
    float *rhoPhiITile = imagRhoPhi_d + FHGridBase;
    float *kxTile = kx_d + FHGridBase;
    float *kyTile = ky_d + FHGridBase;
    float *kzTile = kz_d + FHGridBase;

    ComputeFH_GPU <<< DimFHGrid, DimFHBlock >>>
      (numK, FHGridBase, kxTile, kyTile, kzTile, x_d, y_d, z_d,
       rhoPhiRTile, rhoPhiITile, outR_d, outI_d);
    CUDA_ERRCK;
  }
}
