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
	  kValues * __restrict__ kVals,
          float * __restrict__ x,
	  float * __restrict__ y,
	  float * __restrict__ z,
          float * __restrict__ outR, float * __restrict__ outI)
{
  float expArg;
  float cosArg;
  float sinArg;

  for (int indexK = 0; indexK < numK; indexK++) {
    for (int indexX = 0; indexX < numX; indexX++) {
      expArg = PIx2 * (kVals[indexK].Kx * x[indexX] + 
                       kVals[indexK].Ky * y[indexX] + 
                       kVals[indexK].Kz * z[indexX]);

      cosArg = cosf(expArg);
      sinArg = sinf(expArg);

      float rRhoPhi = kVals[indexK].RealRhoPhi;
      float iRhoPhi = kVals[indexK].ImagRhoPhi;
      outR[indexX] += rRhoPhi * cosArg - iRhoPhi * sinArg;
      outI[indexX] += iRhoPhi * cosArg + rRhoPhi * sinArg;
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
