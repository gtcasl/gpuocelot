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
#define K_ELEMS_PER_GRID 1024

struct kValues {
  float Kx;
  float Ky;
  float Kz;
  float RealRhoPhi;
  float ImagRhoPhi;
};

void 
ComputeRhoPhi(int numK,
              float* __restrict__ phiR, float* __restrict__ phiI,
              float* __restrict__ dR, float* __restrict__ dI,
              float* __restrict__ realRhoPhi, float* __restrict__ imagRhoPhi)
{
  int indexK = 0;
  for (indexK = 0; indexK < numK; indexK++) {
    realRhoPhi[indexK] = phiR[indexK] * dR[indexK] + phiI[indexK] * dI[indexK];
    imagRhoPhi[indexK] = phiR[indexK] * dI[indexK] - phiI[indexK] * dR[indexK];
  }
}

void
ComputeFH(int numK, int numX,
          kValues* __restrict__ kVals,
          float*  __restrict__ x,
	  float*  __restrict__ y,
	  float*  __restrict__ z, 
          float * __restrict__ outR,
	  float * __restrict__ outI)
{
  float expArg;
  float cosArg;
  float sinArg;

  int kTiles = numK / K_ELEMS_PER_GRID;
  if (numK % K_ELEMS_PER_GRID)
    kTiles++;

  for (int kTile = 0; kTile < kTiles; kTile++) {
    int kTileBase = kTile * K_ELEMS_PER_GRID;
    int numElems = MIN(K_ELEMS_PER_GRID, numK - kTileBase);

    //printf("Tile %d-%d\n", kTileBase, kTileBase+numElems-1);

    for (int indexX = 0; indexX < numX; indexX++) {
      float regOutR = outR[indexX];
      float regOutI = outI[indexX];
      float regX = x[indexX];
      float regY = y[indexX];
      float regZ = z[indexX];

      for (int indexK = kTileBase; indexK < kTileBase+numElems; indexK++) {
        expArg = PIx2 * (kVals[indexK].Kx * regX + 
                         kVals[indexK].Ky * regY + 
                         kVals[indexK].Kz * regZ);

        cosArg = cosf(expArg);
        sinArg = sinf(expArg);

        float rRhoPhi = kVals[indexK].RealRhoPhi;
        float iRhoPhi = kVals[indexK].ImagRhoPhi;
        regOutR += rRhoPhi * cosArg - iRhoPhi * sinArg;
        regOutI += iRhoPhi * cosArg + rRhoPhi * sinArg;
      }

      outR[indexX] = regOutR;
      outI[indexX] = regOutI;
    }
  }
}

void createDataStructs(int numK, int numX, 
                       float*& realRhoPhi, float*& imagRhoPhi, 
                       float*& outR, float*& outI) {
  realRhoPhi = (float* ) memalign(16, numK * sizeof(float));
  imagRhoPhi = (float* ) memalign(16, numK * sizeof(float));
  outR = (float*) memalign(16, numX * sizeof (float));
  outI = (float*) memalign(16, numX * sizeof (float));
}
