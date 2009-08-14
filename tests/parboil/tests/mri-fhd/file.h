/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

void inputData(char* fName, int* _numK, int* _numX,
               float** kx, float** ky, float** kz,
               float** x, float** y, float** z,
               float** phiR, float** phiI,
               float** dR, float** dI);

void outputData(char* fName, float* outR, float* outI, int numX);

int compareData(char* fName, float* outR, float* outI, int numX, float error);

