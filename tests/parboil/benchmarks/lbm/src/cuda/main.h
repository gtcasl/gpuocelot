/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#ifndef _MAIN_H_
#define _MAIN_H_

/*############################################################################*/

#include "parboil.h"

/*############################################################################*/

typedef struct {
	int nTimeSteps;
	char* resultFilename;
	char* obstacleFilename;
} MAIN_Param;

/*############################################################################*/

void MAIN_parseCommandLine( int nArgs, char* arg[], MAIN_Param* param, struct pb_Parameters* );
void MAIN_printInfo( const MAIN_Param* param );
void MAIN_initialize( const MAIN_Param* param );
void MAIN_finalize( const MAIN_Param* param );

/*############################################################################*/

#ifndef __MCUDA__
#define CUDA_ERRCK                                                      \
  {cudaError_t err;                                                     \
    if ((err = cudaGetLastError()) != cudaSuccess) {                    \
      fprintf(stderr, "CUDA error on line %d: %s\n", __LINE__, cudaGetErrorString(err)); \
      exit(-1);                                                         \
    }                                                                   \
  }
#else
#define CUDA_ERRCK
#endif

#endif /* _MAIN_H_ */
