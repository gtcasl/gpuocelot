/*!
	\file GPUKernel.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 19, 2009

	\brief implements the GPU kernel callable by the executive
*/

#ifdef EXECUTIVE_GPUKERNEL_H_INCLUDED
#define EXECUTIVE_GPUKERNEL_H_INCLUDED

#include <cuda.h>

#include <ocelot/ir/interface/ExecutableKernel.h>

namespace executive {
	
	class GPUKernel: public ir::ExecutableKernel {
	public:
		GPUKernel();
		virtual ~GPUKernel();
	
		/*!
			Constructs a GPUKernel from a PTXKernel
		*/
		static GPUKernel *fromKernel(ir::PTXKernel *source);
	
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
	
		CUmodule cuModule;
		CUfunction cuFunc;
	};
	
}

#endif
