/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#ifndef _UDTYPES_H__
#define _UDTYPES_H__

typedef struct{
  int numSamples;
  int aquisitionMatrixSize[3];
  int reconstructionMatrixSize[3];
  float kMax[3];
  int gridSize[3];
  float oversample;
  float kernelWidth;
  int binsize;
  int useLUT;
}parameters;

typedef struct{
  float real;
  float imag;
  float kX;
  float kY;
  float kZ;
  float sdc;
} ReconstructionSample;

typedef struct{
  float real;
  float imag;
} cmplx;

#endif
