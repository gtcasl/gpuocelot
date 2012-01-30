/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#define WARP_BITS 5
__global__ void spmv_jds_texture(float *dst_vector,
							   const float *d_data,const int *d_index, const int *d_perm,
							   const float *x_vec,const int *d_nzcnt,const int dim)
{
	int ix=blockIdx.x*blockDim.x+threadIdx.x;
	int warp_id= ix>>WARP_BITS;
	const int jump=gridDim.x*blockDim.x;
	const int jump_warp=(gridDim.x*blockDim.x)>>WARP_BITS;

	while(ix<dim)
	{
		float sum=0.0f;	
		int pt =d_perm[ix];
		int	bound=sh_zcnt_int[warp_id];
		//prefetch 0
		int j=jds_ptr_int[0]+ix;   
		float d = d_data[j]; 
		int i = d_index[j]; 
		float t =tex1Dfetch(tex_x_float,i);  
		
		if (bound>1)  //bound >=2
		{
			//prefetch 1
			j=jds_ptr_int[1]+ix;    
			i =  d_index[j];  
			int in;
			float dn;
			float tn;
			
			for(int k=2;k<bound;k++ )
			{	
				//prefetch k-1
				dn = d_data[j]; 
				//prefetch k
				j=jds_ptr_int[k]+ix;     
				in = d_index[j]; 
				//prefetch k-1
				tn =tex1Dfetch(tex_x_float,i);  
				
				//compute k-2 data
				sum += d*t;    
				//sweep to k
				i = in; 
				//sweep to k-1
				d = dn;  
				t =tn;   
			}	
			
			//fetch last
			dn = d_data[j];   
			//fetch last 
			tn =tex1Dfetch(tex_x_float,i); 
			//compute last -1
			sum += d*t;  
			//sweep to last
			d=dn;
			t=tn;
		}
		//compute last one
		sum += d*t; 
		
		//write out data 
		dst_vector[pt]=sum; 
		
		//update
		warp_id+=jump_warp;
		ix+=jump;
	}
}


__global__ void spmv_jds(float *dst_vector,
						const float *d_data,const int *d_index, const int *d_perm,
						const float *x_vec,const int *d_nzcnt,const int dim)
{
	int ix=blockIdx.x*blockDim.x+threadIdx.x;
	int warp_id=ix>>WARP_BITS;
	const int jump=gridDim.x*blockDim.x;
	const int jump_warp=(gridDim.x*blockDim.x)>>WARP_BITS;
	while(ix<dim)
	{
		float sum=0.0f;
		int	bound=sh_zcnt_int[warp_id];
		//prefetch 0
		int j=jds_ptr_int[0]+ix;  
		float d = d_data[j]; 
		int i = d_index[j];  
		float t = x_vec[i];
		
		if (bound>1)  //bound >=2
		{
			//prefetch 1
			j=jds_ptr_int[1]+ix;    
			i =  d_index[j];  
			int in;
			float dn;
			float tn;
			for(int k=2;k<bound;k++ )
			{	
				//prefetch k-1
				dn = d_data[j]; 
				//prefetch k
				j=jds_ptr_int[k]+ix;    
				in = d_index[j]; 
				//prefetch k-1
				tn = x_vec[i];
				
				//compute k-2
				sum += d*t; 
				//sweep to k
				i = in;  
				//sweep to k-1
				d = dn;
				t =tn; 
			}	
		
			//fetch last
			dn = d_data[j];
			tn = x_vec[i];
	
			//compute last-1
			sum += d*t; 
			//sweep to last
			d=dn;
			t=tn;
		}
		//compute last
		sum += d*t;  // 3 3
		
		//write out data
		dst_vector[d_perm[ix]]=sum; 
		ix+=jump;
		warp_id+=jump_warp;
	}

}

