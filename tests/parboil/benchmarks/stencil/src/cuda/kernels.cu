/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include "common.h"

__global__ void block2D_hybrid_coarsen_x(float c0,float c1,float *A0,float *Anext, int nx, int ny, int nz)
{

	//thread coarsening along x direction
	const int i = blockIdx.x*blockDim.x*2+threadIdx.x;
	const int i2= blockIdx.x*blockDim.x*2+threadIdx.x+blockDim.x;
    const int j = blockIdx.y*blockDim.y+threadIdx.y;
	const int sh_id=threadIdx.x + threadIdx.y*blockDim.x*2;
	const int sh_id2=threadIdx.x +blockDim.x+ threadIdx.y*blockDim.x*2;
	
	//shared memeory
	extern __shared__ float sh_A0[];
	sh_A0[sh_id]=0.0f;
	sh_A0[sh_id2]=0.0f;
	__syncthreads();
	
	//get available region for load and store
	const bool w_region =  i>0 && j>0 &&(i<nx-1) &&(j<ny-1) ;
	const bool w_region2 =  j>0 &&(i2<nx-1) &&(j<ny-1) ;
	const bool x_l_bound = (threadIdx.x==0);
	const bool x_h_bound = ((threadIdx.x+blockDim.x)==(blockDim.x*2-1));
	const bool y_l_bound = (threadIdx.y==0);
	const bool y_h_bound = (threadIdx.y==(blockDim.y-1));

	//register for bottom and top planes
	//because of thread coarsening, we need to doulbe registers
	float bottom=0.0f,bottom2=0.0f,top=0.0f,top2=0.0f;
	
	//load data for bottom and current 
	if((i<nx) &&(j<ny))
	{
		bottom=A0[Index3D (nx, ny, i, j, 0)];
		sh_A0[sh_id]=A0[Index3D (nx, ny, i, j, 1)];
	}
	if((i2<nx) &&(j<ny))
	{
		bottom2=A0[Index3D (nx, ny, i2, j, 0)];
		sh_A0[sh_id2]=A0[Index3D (nx, ny, i2, j, 1)];
	}

	__syncthreads();
	
	for(int k=1;k<nz-1;k++)
	{


		float a_left_right,a_top,a_down;		
		
		//load required data on xy planes
		//if it on shared memory, load from shared memory
		//if not, load from global memory
		if((i<nx) &&(j<ny))
			top=A0[Index3D (nx, ny, i, j, k+1)];
			
		if(w_region)
		{
			

			a_left_right=x_l_bound?A0[Index3D (nx, ny, i-1, j, k )]:sh_A0[sh_id-1];
	
			a_down=y_l_bound?A0[Index3D (nx, ny, i, j-1, k )]:sh_A0[sh_id-2*blockDim.x];
	
			a_top=y_h_bound?A0[Index3D (nx, ny, i, j+1, k )]:sh_A0[sh_id+2*blockDim.x];
		
			Anext[Index3D (nx, ny, i, j, k)] = (a_left_right + sh_A0[sh_id+1] + a_top + a_down 
			                                  + top + bottom)*c1 - sh_A0[sh_id]*c0 ;	


		}
		
		
		//load another block 
		if((i2<nx) &&(j<ny))
			top2=A0[Index3D (nx, ny, i2, j, k+1)];
			
		if(w_region2)
		{
			
			a_left_right=x_h_bound?A0[Index3D (nx, ny, i2+1, j, k )]:sh_A0[sh_id2+1];

			a_down=y_l_bound?A0[Index3D (nx, ny, i2, j-1, k )]:sh_A0[sh_id2-2*blockDim.x];
			
			a_top=y_h_bound?A0[Index3D (nx, ny, i2, j+1, k )]:sh_A0[sh_id2+2*blockDim.x];
			
			Anext[Index3D (nx, ny, i2, j, k)] = (a_left_right + sh_A0[sh_id2-1] + a_top + a_down +  top2 
												+bottom2)*c1 - sh_A0[sh_id2]*c0;
		}

		//swap data
		__syncthreads();
		bottom=sh_A0[sh_id];
		sh_A0[sh_id]=top;
		bottom2=sh_A0[sh_id2];
		sh_A0[sh_id2]=top2;
		__syncthreads();
	}


}


