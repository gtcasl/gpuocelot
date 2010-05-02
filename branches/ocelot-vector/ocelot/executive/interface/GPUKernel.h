/*!
	\file GPUKernel.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 19, 2009

	\brief implements the GPU kernel callable by the executive
*/

#ifndef EXECUTIVE_GPUKERNEL_H_INCLUDED
#define EXECUTIVE_GPUKERNEL_H_INCLUDED


#if USE_CUDA_DRIVER_API
#include <ocelot/cuda/interface/cuda.h>
#endif

#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/ExecutableKernel.h>

namespace executive {
	
	class GPUKernel: public ir::ExecutableKernel {
	public:
		GPUKernel( ir::Kernel& kernel, const executive::Executive* c = 0 );
		GPUKernel();
		virtual ~GPUKernel();
	
		/*!
			Constructs a GPUKernel from a PTXKernel
		*/
//		static GPUKernel *fromKernel(ir::PTXKernel *source);
	
		/*!
			Launch a kernel on a 2D grid
		*/
		virtual void launchGrid(int width, int height);

		/*!
			Sets the shape of a kernel
		*/
		virtual void setKernelShape(int x, int y, int z);
		
	protected:
		/*!
			Configures the parameter block for the CUDA driver API
		*/
		void configureParameters();
		
		/*!
			Construct 
		*/
		bool initialize();
	
	protected:
		
		/*!
			PTX Kernel
		*/
		ir::PTXKernel *ptxKernel;

#if USE_CUDA_DRIVER_API
	//	CUmodule cuModule;
		CUfunction cuFunc;
#endif

	};
	
}

#endif
