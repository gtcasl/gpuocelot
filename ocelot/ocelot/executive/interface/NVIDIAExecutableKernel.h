/*! \file NVIDIAExecutableKernel.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 19, 2009
	\brief implements the GPU kernel callable by the executive
*/

#ifndef EXECUTIVE_NVIDIAKERNEL_H_INCLUDED
#define EXECUTIVE_NVIDIAKERNEL_H_INCLUDED

#include <ocelot/cuda/interface/CudaDriver.h>

#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/executive/interface/ExecutableKernel.h>

namespace executive {

	class NVIDIAExecutableKernel: public executive::ExecutableKernel {
	public:
		NVIDIAExecutableKernel( ir::Kernel& kernel, const CUfunction& function, 
			executive::Device* d = 0 );
		NVIDIAExecutableKernel();
		~NVIDIAExecutableKernel();
	
		/*!
			Launch a kernel on a 2D grid
		*/
		void launchGrid(int width, int height);

		/*!
			Sets the shape of a kernel
		*/
		void setKernelShape(int x, int y, int z);

		/*!
			Sets the device used to execute the kernel
		*/
		void setDevice(const Device* device, unsigned int limit);

		/*!
			sets the size of shared memory in bytes
		*/
		void setExternSharedMemorySize(unsigned int bytes);

		void updateParameterMemory();
		
		/*! \brief Indicate that other memory has been updated */
		void updateMemory();
		
		/*! \brief Get a vector of all textures references by the kernel */
		TextureVector textureReferences() const;

		void updateGlobalMemory();

		void updateConstantMemory();

		/*!	adds a trace generator to the EmulatedKernel */
		void addTraceGenerator(trace::TraceGenerator *generator);
		/*!	removes a trace generator from an EmulatedKernel */
		void removeTraceGenerator(trace::TraceGenerator *generator);
		
		void setWorkerThreads(unsigned int limit);
		
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
			CUDA function refering to this kernel
		*/
		CUfunction cuFunction;

	};
	
}

#endif
