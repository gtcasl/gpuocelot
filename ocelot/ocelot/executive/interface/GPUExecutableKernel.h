/*!
	\file GPUExecutableKernel.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 19, 2009

	\brief implements the GPU kernel callable by the executive
*/

#ifndef EXECUTIVE_GPUKERNEL_H_INCLUDED
#define EXECUTIVE_GPUKERNEL_H_INCLUDED
#include <ocelot/cuda/include/cuda.h>

#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/ExecutableKernel.h>

namespace executive {

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

		/*!
			Sets the device used to execute the kernel
		*/
		virtual void setDevice(const Device* device);

		/*!
			sets the size of shared memory in bytes
		*/
		virtual void setSharedMemorySize(unsigned int bytes);

		virtual void updateParameterMemory();

		virtual void updateGlobalMemory();

		virtual void updateConstantMemory();
		
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
