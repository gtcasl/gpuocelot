/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#define PI   3.1415926535897932384626433832795029f
#define PIx2 6.2831853071795864769252867665590058f

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define K_ELEMS_PER_GRID 2048

// #define __restrict__ restrict

struct kValues {
  float Kx;
  float Ky;
  float Kz;
  float PhiMag;
};

void 
ComputePhiMagCPU(int numK, 
                 float* __restrict__ phiR,
		 float* __restrict__ phiI,
		 float* __restrict__ phiMag) {
  int indexK = 0;
  for (indexK = 0; indexK < numK; indexK++) {
    float real = phiR[indexK];
    float imag = phiI[indexK];
    phiMag[indexK] = real*real + imag*imag;
  }
}

void
ComputeQCPU(int numK, int numX,
            struct kValues* __restrict__ kVals,
            float* __restrict__ x,
	    float* __restrict__ y,
	    float* __restrict__ z, 
            float * __restrict__ Qr,
	    float * __restrict__ Qi) {
  float expArg;
  float cosArg;
  float sinArg;

  int kTiles = (numK + K_ELEMS_PER_GRID - 1) / K_ELEMS_PER_GRID;

  for (int kTile = 0; kTile < kTiles; kTile++) {
    for (int indexX = 0; indexX < numX; indexX++) {
      float regQr = Qr[indexX];
      float regQi = Qi[indexX];
      float regX = x[indexX];
      float regY = y[indexX];
      float regZ = z[indexX];

      int kTileBase = kTile * K_ELEMS_PER_GRID;
      int numElems = MIN(K_ELEMS_PER_GRID, numK - kTileBase);
      for (int indexK = kTileBase; indexK < kTileBase+numElems; indexK++) {
        expArg = PIx2 * (kVals[indexK].Kx * regX + 
                         kVals[indexK].Ky * regY + 
                         kVals[indexK].Kz * regZ);

        cosArg = cosf(expArg);
        sinArg = sinf(expArg);

        float phi = kVals[indexK].PhiMag;
        regQr += phi * cosArg;
        regQi += phi * sinArg;
      }
      Qr[indexX] = regQr;
      Qi[indexX] = regQi;
    }
  }
}

void createDataStructsCPU(int numK, int numX, float** phiMag,
	 float** Qr, float** Qi)
{
  *phiMag = (float* ) memalign(16, numK * sizeof(float));
  *Qr = (float*) memalign(16, numX * sizeof (float));
  memset((void *)*Qr, 0, numX * sizeof(float));
  *Qi = (float*) memalign(16, numX * sizeof (float));
  memset((void *)*Qi, 0, numX * sizeof(float));
}
