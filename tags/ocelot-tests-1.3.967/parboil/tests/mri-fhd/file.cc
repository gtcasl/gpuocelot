/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include <endian.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include <string.h>

#if __BYTE_ORDER != __LITTLE_ENDIAN
# error "File I/O is not implemented for this system: wrong endianness."
#endif

void inputData(char* fName, int* _numK, int* _numX,
               float** kx, float** ky, float** kz,
               float** x, float** y, float** z,
               float** phiR, float** phiI,
               float** dR, float** dI)
{
  int numK, numX;
  FILE* fid = fopen(fName, "r");

  if (fid == NULL)
    {
      fprintf(stderr, "Cannot open input file\n");
      exit(-1);
    }
  size_t count;
  
  count = fread (&numK, sizeof (int), 1, fid);
  assert( count == 1 );
  *_numK = numK;
  count = fread (&numX, sizeof (int), 1, fid);
  assert( count == 1 );
  *_numX = numX;
  *kx = (float *) memalign(16, numK * sizeof (float));
  count = fread (*kx, sizeof (float), numK, fid);
  assert( count == numK );
  *ky = (float *) memalign(16, numK * sizeof (float));
  count = fread (*ky, sizeof (float), numK, fid);
  assert( count == numK );
  *kz = (float *) memalign(16, numK * sizeof (float));
  count = fread (*kz, sizeof (float), numK, fid);
  assert( count == numK );
  *x = (float *) memalign(16, numX * sizeof (float));
  count = fread (*x, sizeof (float), numX, fid);
  assert( count == numX );
  *y = (float *) memalign(16, numX * sizeof (float));
  count = fread (*y, sizeof (float), numX, fid);
  assert( count == numX );
  *z = (float *) memalign(16, numX * sizeof (float));
  count = fread (*z, sizeof (float), numX, fid);
  assert( count == numX );
  *phiR = (float *) memalign(16, numK * sizeof (float));
  count = fread (*phiR, sizeof (float), numK, fid);
  assert( count == numK );
  *phiI = (float *) memalign(16, numK * sizeof (float));
  count = fread (*phiI, sizeof (float), numK, fid);
  assert( count == numK );
  *dR = (float *) memalign(16, numK * sizeof (float));
  //count = fread (*dR, sizeof (float), numK, fid);
  //assert( count == numK );
  memset( *dR, 0, sizeof( float ) * numK );
  *dI = (float *) memalign(16, numK * sizeof (float));
  //count = fread (*dI, sizeof (float), numK, fid);
  //assert( count == numK );
  memset( *dI, 0, sizeof( float ) * numK );
  fclose (fid); 
}

void outputData(char* fName, float* outR, float* outI, int numX)
{
  FILE* fid = fopen(fName, "w");
  uint32_t tmp32;

  if (fid == NULL)
    {
      fprintf(stderr, "Cannot open output file\n");
      exit(-1);
    }

  /* Write the data size */
  tmp32 = numX;
  fwrite(&tmp32, sizeof(uint32_t), 1, fid);

  /* Write the reconstructed data */
  fwrite (outR, sizeof (float), numX, fid);
  fwrite (outI, sizeof (float), numX, fid);
  fclose (fid);
}

int compareData(char* fName, float* outR, float* outI, int numX, float thold)
{
  FILE* fid = fopen(fName, "r");
  uint32_t tmp32;

  if (fid == NULL)
    {
      fprintf(stderr, "Cannot open output file\n");
      exit(-1);
    }

  /* Write the data size */
  tmp32 = 0;
  fread(&tmp32, sizeof(uint32_t), 1, fid);

  if( tmp32 != numX ) return 0;

  float* tmpR = (float*) malloc(sizeof (float) * numX);
  float* tmpI = (float*) malloc(sizeof (float) * numX);

  int pass = 1;
  float error = 0;
  float errorI = 0;

  /* Write the reconstructed data */
  fread (tmpR, sizeof (float), numX, fid);
  fread (tmpI, sizeof (float), numX, fid);
  
  for( unsigned int i = 0; i < numX; ++i)
  {
    error += ( tmpR[i] - outR[i] ) * ( tmpR[i] - outR[i] );
    errorI += ( tmpI[i] - outI[i] ) * ( tmpI[i] - outI[i] );
  }
  
  if( error > thold )
  {
  	printf("Real error is %f, greater than threshold %f\n", error, thold);
  	pass = 0;
  }
  
  if( errorI > thold )
  {
  	printf("Imaginary error is %f, greater than threshold %f\n", errorI, thold);
  	pass = 0;
  }
  
  fclose (fid);
  free(tmpR);
  free(tmpI);
  
  return pass;
}
