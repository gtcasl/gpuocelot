/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/*############################################################################*/

#ifndef _LBM_H_
#define _LBM_H_

/*############################################################################*/


/*############################################################################*/

typedef enum {C = 0,
              N, S, E, W, T, B,
              NE, NW, SE, SW,
              NT, NB, ST, SB,
              ET, EB, WT, WB,
              FLAGS, N_CELL_ENTRIES} CELL_ENTRIES;
#define N_DISTR_FUNCS FLAGS

typedef enum {OBSTACLE    = 1 << 0,
              ACCEL       = 1 << 1,
              IN_OUT_FLOW = 1 << 2} CELL_FLAGS;


#include "layout_config.h"
#include "lbm_macros.h"

/*############################################################################*/

void LBM_allocateGrid( float** ptr );
void LBM_freeGrid( float** ptr );
void LBM_initializeGrid( LBM_Grid grid );
void LBM_initializeSpecialCellsForLDC( LBM_Grid grid );
void LBM_loadObstacleFile( LBM_Grid grid, const char* filename );
void LBM_swapGrids( LBM_GridPtr grid1, LBM_GridPtr grid2 );
void LBM_showGridStatistics( LBM_Grid Grid );
void LBM_storeVelocityField( LBM_Grid grid, const char* filename,
                           const BOOL binary );

/* CUDA ***********************************************************************/

void CUDA_LBM_allocateGrid( float** ptr );
void CUDA_LBM_freeGrid( float** ptr );
void CUDA_LBM_initializeGrid( float** d_grid, float** h_grid );
void CUDA_LBM_getDeviceGrid( float** d_grid, float** h_grid );
void CUDA_LBM_performStreamCollide( LBM_Grid srcGrid, LBM_Grid dstGrid );

/*############################################################################*/

#endif /* _LBM_H_ */
