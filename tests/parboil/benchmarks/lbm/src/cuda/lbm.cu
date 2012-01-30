/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/*############################################################################*/

// includes, system
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <float.h>

// includes, project
#include "lbm.h"
#ifndef __MCUDA__
#include <cuda.h>
#else
#include <mcuda.h>
#endif

#define DFL1 (1.0f/ 3.0f)
#define DFL2 (1.0f/18.0f)
#define DFL3 (1.0f/36.0f)

// includes, kernels
#include "lbm_kernel.cu"

#define REAL_MARGIN (CALC_INDEX(0, 0, 2, 0) - CALC_INDEX(0,0,0,0))
#define TOTAL_MARGIN (2*PADDED_X*PADDED_Y*N_CELL_ENTRIES)

/******************************************************************************/
void CUDA_LBM_performStreamCollide( LBM_Grid srcGrid, LBM_Grid dstGrid ) {
	dim3 dimBlock, dimGrid;
        dimBlock.x = SIZE_X;
	dimGrid.x = SIZE_Y;
	dimGrid.y = SIZE_Z;
	dimBlock.y = dimBlock.z = dimGrid.z = 1;
	performStreamCollide_kernel<<<dimGrid, dimBlock>>>(srcGrid, dstGrid);
  CUDA_ERRCK;
}

/*############################################################################*/

void LBM_allocateGrid( float** ptr ) {
	const size_t size   = TOTAL_PADDED_CELLS*N_CELL_ENTRIES*sizeof( float ) + 2*TOTAL_MARGIN*sizeof( float );

	*ptr = (float*)malloc( size );
	if( ! *ptr ) {
		printf( "LBM_allocateGrid: could not allocate %.1f MByte\n",
				size / (1024.0*1024.0) );
		exit( 1 );
	}

	memset( *ptr, 0, size );

	printf( "LBM_allocateGrid: allocated %.1f MByte\n",
			size / (1024.0*1024.0) );
	*ptr += REAL_MARGIN;
}

/******************************************************************************/

void CUDA_LBM_allocateGrid( float** ptr ) {
	const size_t size = TOTAL_PADDED_CELLS*N_CELL_ENTRIES*sizeof( float ) + 2*TOTAL_MARGIN*sizeof( float );
	cudaMalloc((void**)ptr, size);
        CUDA_ERRCK;
	*ptr += REAL_MARGIN;
}

/*############################################################################*/

void LBM_freeGrid( float** ptr ) {
	free( *ptr-REAL_MARGIN );
	*ptr = NULL;
}

/******************************************************************************/

void CUDA_LBM_freeGrid( float** ptr ) {
	cudaFree( *ptr-REAL_MARGIN );
	*ptr = NULL;
}

/*############################################################################*/

void LBM_initializeGrid( LBM_Grid grid ) {
	SWEEP_VAR

	SWEEP_START( 0, 0, 0, 0, 0, SIZE_Z )
	SRC_C( grid  ) = DFL1;
	SRC_N( grid  ) = DFL2;
	SRC_S( grid  ) = DFL2;
	SRC_E( grid  ) = DFL2;
	SRC_W( grid  ) = DFL2;
	SRC_T( grid  ) = DFL2;
	SRC_B( grid  ) = DFL2;
	SRC_NE( grid ) = DFL3;
	SRC_NW( grid ) = DFL3;
	SRC_SE( grid ) = DFL3;
	SRC_SW( grid ) = DFL3;
	SRC_NT( grid ) = DFL3;
	SRC_NB( grid ) = DFL3;
	SRC_ST( grid ) = DFL3;
	SRC_SB( grid ) = DFL3;
	SRC_ET( grid ) = DFL3;
	SRC_EB( grid ) = DFL3;
	SRC_WT( grid ) = DFL3;
	SRC_WB( grid ) = DFL3;

	CLEAR_ALL_FLAGS_SWEEP( grid );
	SWEEP_END
}

/******************************************************************************/

void CUDA_LBM_initializeGrid( float** d_grid, float** h_grid ) {
	const size_t size   = TOTAL_PADDED_CELLS*N_CELL_ENTRIES*sizeof( float ) + 2*TOTAL_MARGIN*sizeof( float );

	cudaMemcpy(*d_grid - REAL_MARGIN, *h_grid - REAL_MARGIN, size, cudaMemcpyHostToDevice);
        CUDA_ERRCK;
}

void CUDA_LBM_getDeviceGrid( float** d_grid, float** h_grid ) {
	const size_t size   = TOTAL_PADDED_CELLS*N_CELL_ENTRIES*sizeof( float ) + 2*TOTAL_MARGIN*sizeof( float );
        cudaThreadSynchronize();
        CUDA_ERRCK;
	cudaMemcpy(*h_grid - REAL_MARGIN, *d_grid - REAL_MARGIN, size, cudaMemcpyDeviceToHost);
        CUDA_ERRCK;
}

/*############################################################################*/

void LBM_swapGrids( LBM_GridPtr grid1, LBM_GridPtr grid2 ) {
	LBM_Grid aux = *grid1;
	*grid1 = *grid2;
	*grid2 = aux;
}

/*############################################################################*/

void LBM_loadObstacleFile( LBM_Grid grid, const char* filename ) {
	int x,  y,  z;

	FILE* file = fopen( filename, "rb" );

	for( z = 0; z < SIZE_Z; z++ ) {
		for( y = 0; y < SIZE_Y; y++ ) {
			for( x = 0; x < SIZE_X; x++ ) {
				if( fgetc( file ) != '.' ) SET_FLAG( grid, x, y, z, OBSTACLE );
			}
			fgetc( file );
		}
		fgetc( file );
	}

	fclose( file );
}

/*############################################################################*/

void LBM_initializeSpecialCellsForLDC( LBM_Grid grid ) {
	int x,  y,  z;

	for( z = -2; z < SIZE_Z+2; z++ ) {
		for( y = 0; y < SIZE_Y; y++ ) {
			for( x = 0; x < SIZE_X; x++ ) {
				if( x == 0 || x == SIZE_X-1 ||
						y == 0 || y == SIZE_Y-1 ||
						z == 0 || z == SIZE_Z-1 ) {
					SET_FLAG( grid, x, y, z, OBSTACLE );
				}
				else {
					if( (z == 1 || z == SIZE_Z-2) &&
							x > 1 && x < SIZE_X-2 &&
							y > 1 && y < SIZE_Y-2 ) {
						SET_FLAG( grid, x, y, z, ACCEL );
					}
				}
			}
		}
	}
}

/*############################################################################*/

void LBM_showGridStatistics( LBM_Grid grid ) {
	int nObstacleCells = 0,
	    nAccelCells    = 0,
	    nFluidCells    = 0;
	float ux, uy, uz;
	float minU2  = 1e+30, maxU2  = -1e+30, u2;
	float minRho = 1e+30, maxRho = -1e+30, rho;
	float mass = 0;

	SWEEP_VAR

		SWEEP_START( 0, 0, 0, 0, 0, SIZE_Z )
		rho = LOCAL( grid, C  ) + LOCAL( grid, N  )
		+ LOCAL( grid, S  ) + LOCAL( grid, E  )
		+ LOCAL( grid, W  ) + LOCAL( grid, T  )
		+ LOCAL( grid, B  ) + LOCAL( grid, NE )
		+ LOCAL( grid, NW ) + LOCAL( grid, SE )
		+ LOCAL( grid, SW ) + LOCAL( grid, NT )
		+ LOCAL( grid, NB ) + LOCAL( grid, ST )
		+ LOCAL( grid, SB ) + LOCAL( grid, ET )
		+ LOCAL( grid, EB ) + LOCAL( grid, WT )
		+ LOCAL( grid, WB );
	if( rho < minRho ) minRho = rho;
	if( rho > maxRho ) maxRho = rho;
	mass += rho;

	if( TEST_FLAG_SWEEP( grid, OBSTACLE )) {
		nObstacleCells++;
	}
	else {
		if( TEST_FLAG_SWEEP( grid, ACCEL ))
			nAccelCells++;
		else
			nFluidCells++;

		ux = + LOCAL( grid, E  ) - LOCAL( grid, W  )
			+ LOCAL( grid, NE ) - LOCAL( grid, NW )
			+ LOCAL( grid, SE ) - LOCAL( grid, SW )
			+ LOCAL( grid, ET ) + LOCAL( grid, EB )
			- LOCAL( grid, WT ) - LOCAL( grid, WB );
		uy = + LOCAL( grid, N  ) - LOCAL( grid, S  )
			+ LOCAL( grid, NE ) + LOCAL( grid, NW )
			- LOCAL( grid, SE ) - LOCAL( grid, SW )
			+ LOCAL( grid, NT ) + LOCAL( grid, NB )
			- LOCAL( grid, ST ) - LOCAL( grid, SB );
		uz = + LOCAL( grid, T  ) - LOCAL( grid, B  )
			+ LOCAL( grid, NT ) - LOCAL( grid, NB )
			+ LOCAL( grid, ST ) - LOCAL( grid, SB )
			+ LOCAL( grid, ET ) - LOCAL( grid, EB )
			+ LOCAL( grid, WT ) - LOCAL( grid, WB );
		u2 = (ux*ux + uy*uy + uz*uz) / (rho*rho);
		if( u2 < minU2 ) minU2 = u2;
		if( u2 > maxU2 ) maxU2 = u2;
	}
	SWEEP_END

		printf( "LBM_showGridStatistics:\n"
				"\tnObstacleCells: %7i nAccelCells: %7i nFluidCells: %7i\n"
				"\tminRho: %8.4f maxRho: %8.4f mass: %e\n"
				"\tminU: %e maxU: %e\n\n",
				nObstacleCells, nAccelCells, nFluidCells,
				minRho, maxRho, mass,
				sqrt( minU2 ), sqrt( maxU2 ) );

}

/*############################################################################*/

static void storeValue( FILE* file, OUTPUT_PRECISION* v ) {
	const int litteBigEndianTest = 1;
	if( (*((unsigned char*) &litteBigEndianTest)) == 0 ) {         /* big endian */
		const char* vPtr = (char*) v;
		char buffer[sizeof( OUTPUT_PRECISION )];
		int i;

		for (i = 0; i < sizeof( OUTPUT_PRECISION ); i++)
			buffer[i] = vPtr[sizeof( OUTPUT_PRECISION ) - i - 1];

		fwrite( buffer, sizeof( OUTPUT_PRECISION ), 1, file );
	}
	else {                                                     /* little endian */
		fwrite( v, sizeof( OUTPUT_PRECISION ), 1, file );
	}
}

/*############################################################################*/

static void loadValue( FILE* file, OUTPUT_PRECISION* v ) {
	const int litteBigEndianTest = 1;
	if( (*((unsigned char*) &litteBigEndianTest)) == 0 ) {         /* big endian */
		char* vPtr = (char*) v;
		char buffer[sizeof( OUTPUT_PRECISION )];
		int i;

		fread( buffer, sizeof( OUTPUT_PRECISION ), 1, file );

		for (i = 0; i < sizeof( OUTPUT_PRECISION ); i++)
			vPtr[i] = buffer[sizeof( OUTPUT_PRECISION ) - i - 1];
	}
	else {                                                     /* little endian */
		fread( v, sizeof( OUTPUT_PRECISION ), 1, file );
	}
}

/*############################################################################*/

void LBM_storeVelocityField( LBM_Grid grid, const char* filename,
		const int binary ) {
	OUTPUT_PRECISION rho, ux, uy, uz;

	FILE* file = fopen( filename, (binary ? "wb" : "w") );

	SWEEP_VAR
	SWEEP_START(0,0,0,SIZE_X,SIZE_Y,SIZE_Z)
				rho = + SRC_C( grid ) + SRC_N( grid )
					+ SRC_S( grid ) + SRC_E( grid )
					+ SRC_W( grid ) + SRC_T( grid )
					+ SRC_B( grid ) + SRC_NE( grid )
					+ SRC_NW( grid ) + SRC_SE( grid )
					+ SRC_SW( grid ) + SRC_NT( grid )
					+ SRC_NB( grid ) + SRC_ST( grid )
					+ SRC_SB( grid ) + SRC_ET( grid )
					+ SRC_EB( grid ) + SRC_WT( grid )
					+ SRC_WB( grid );
				ux = + SRC_E( grid ) - SRC_W( grid ) 
					+ SRC_NE( grid ) - SRC_NW( grid ) 
					+ SRC_SE( grid ) - SRC_SW( grid ) 
					+ SRC_ET( grid ) + SRC_EB( grid ) 
					- SRC_WT( grid ) - SRC_WB( grid );
				uy = + SRC_N( grid ) - SRC_S( grid ) 
					+ SRC_NE( grid ) + SRC_NW( grid ) 
					- SRC_SE( grid ) - SRC_SW( grid ) 
					+ SRC_NT( grid ) + SRC_NB( grid ) 
					- SRC_ST( grid ) - SRC_SB( grid );
				uz = + SRC_T( grid ) - SRC_B( grid ) 
					+ SRC_NT( grid ) - SRC_NB( grid ) 
					+ SRC_ST( grid ) - SRC_SB( grid ) 
					+ SRC_ET( grid ) - SRC_EB( grid ) 
					+ SRC_WT( grid ) - SRC_WB( grid );
				ux /= rho;
				uy /= rho;
				uz /= rho;

				if( binary ) {
					/*
					   fwrite( &ux, sizeof( ux ), 1, file );
					   fwrite( &uy, sizeof( uy ), 1, file );
					   fwrite( &uz, sizeof( uz ), 1, file );
					   */
					storeValue( file, &ux );
					storeValue( file, &uy );
					storeValue( file, &uz );
				} else
					fprintf( file, "%e %e %e\n", ux, uy, uz );

	SWEEP_END;

	fclose( file );
}

