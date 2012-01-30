/* (c) 2010 The Board of Trustees of the University of Illinois. */
/*
Author: Sara Baghsorkhi.
This implementation is partly based on the SC08 paper by Naga K. Govindaraju et al.
*/

#include <stdlib.h> 
#include <stdio.h>
#include <math.h>
#include <parboil.h>
#include "file.h"

struct float2{
    float x;
    float y;
};

float2 make_float2(float x, float y)
{
  float2 result; result.x = x; result.y = y; return result;
}

inline float2 operator*( float2 a, float2 b ) { return make_float2( a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x ); }
inline float2 operator+( float2 a, float2 b ) { return make_float2( a.x + b.x, a.y + b.y ); }
inline float2 operator-( float2 a, float2 b ) { return make_float2( a.x - b.x, a.y - b.y ); }
inline float2 operator*( float2 a, float b ) { return make_float2( b*a.x , b*a.y); }

void compute_reference( float2 *dst, float2 *src, int batch, int n)
{   
    float2 *X = (float2*) malloc( n*sizeof(float2) );
    float2 *Y = (float2*) malloc( n*sizeof(float2) );
    for( int ibatch = 0; ibatch < batch; ibatch++ )
    {
        // go to double precision
        for( int i = 0; i < n; i++ )
            X[i] = make_float2( src[i].x, src[i].y );
        
        // FFT in double precision
        for( int kmax = 1, jmax = n/2; kmax < n; kmax *= 2, jmax /= 2 )
        {
            for( int k = 0; k < kmax; k++ )
            {
                double phi = -2.*M_PI*k/(2.*kmax);
                float2 w = make_float2( cos(phi), sin(phi) ); 
                for( int j = 0; j < jmax; j++ )
                {
                    Y[j*2*kmax + k]        = X[j*kmax + k] + w * X[j*kmax + n/2 + k];
                    Y[j*2*kmax + kmax + k] = X[j*kmax + k] - w * X[j*kmax + n/2 + k];
                }
            }
            float2 *Z = X;
            X = Y;
            Y = Z;
        }
        
        // return to single precision
        for( int i = 0; i < n; i++ )
            dst[i] = make_float2( (float)X[i].x, (float)X[i].y );
        
        src += n;
        dst += n;
    }
    free( X );
    free( Y );
}   
 
int main( int argc, char **argv )
{	
  //8*1024*1024;
  int n_bytes; 
  int N, B;
  struct pb_TimerSet timers;
  struct pb_Parameters *params;
  params = pb_ReadParameters(&argc, argv);
  if ((params->inpFiles[0] == NULL) || (params->inpFiles[1] != NULL))
    {
      fprintf(stderr, "Expecting one input filename\n");
      exit(-1);
    }

  int err = 0;
  if(argc != 3)
    err |= 1;
  else {
    char* numend;
    N = strtol(argv[1], &numend, 10);
    if(numend == argv[1])
      err |= 2;
    B = strtol(argv[2], &numend, 10);
    if(numend == argv[2])
      err |= 4;
  }

  if(err)
  {
    fprintf(stderr, "Expecting two integers for N and B\n");
    exit(-1);
  }

  n_bytes = N*B*sizeof(float2);
    
  pb_InitializeTimerSet(&timers);
  pb_SwitchToTimer(&timers, pb_TimerID_IO);

  float2 *source    = (float2 *)malloc( n_bytes );
  float2 *result    = (float2 *)malloc( n_bytes );

  inputData(params->inpFiles[0],(float*)source,N*B*2);

  pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
  compute_reference(result, source, B, N);	
  if (params->outFile)
    {
      /* Write result to file */
      pb_SwitchToTimer(&timers, pb_TimerID_IO);
      outputData(params->outFile, (float*)result, N*B*2);
      pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
    }

  free(source);
  free(result);
  pb_SwitchToTimer(&timers, pb_TimerID_NONE);
  pb_PrintTimerSet(&timers);


}

