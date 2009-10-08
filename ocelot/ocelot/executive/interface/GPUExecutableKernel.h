/*!
	\file GPUExecutableKernel.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 19, 2009

	\brief implements the GPU kernel callable by the executive
*/

#ifndef EXECUTIVE_GPUKERNEL_H_INCLUDED
#define EXECUTIVE_GPUKERNEL_H_INCLUDED
#include <ocelot/cuda/interface/cuda.h>

#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/ExecutableKernel.h>

namespace executive {

	class Executive;
	
	class GPUExecutableKernel: public ir::ExecutableKernel {
	public:
		GPUExecutableKernel( ir::Kernel& kernel, const executive::Executive* c = 0 );
		GPUExecutableKernel();
		virtual ~GPUExecutableKernel();
	
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
		
		/*!
			CUDA function refering to this kernel
		*/
		CUfunction cuFunction;
		
		friend class executive::Executive;

	};
	
}

#endif
