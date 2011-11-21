/*!
	\file DynamicMulticoreKernel.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 11, 2011
	\brief implements a dynamic multicore kernel
*/

#ifndef OCELOT_EXECUTIVE_DYNAMICMULTICOREKERNEL_H_INCLUDED
#define OCELOT_EXECUTIVE_DYNAMICMULTICOREKERNEL_H_INCLUDED

// C++ includes
#include <map>

// Ocelot includes
#include <ocelot/executive/interface/ExecutableKernel.h>

namespace executive {

	class DynamicMulticoreKernel: public ExecutableKernel {
	public:
	
	public:
		DynamicMulticoreKernel(const ir::IRKernel& k, executive::Device* d = 0);
		DynamicMulticoreKernel(executive::Device* d = 0);
		virtual ~DynamicMulticoreKernel();
	
		
		/*!	\brief Launch a kernel on a 2D grid */
		virtual void launchGrid(int width, int height, int depth);
		
		/*!	\brief Sets the shape of a kernel */
		virtual void setKernelShape(int x, int y, int z);

		/*! \brief Changes the amount of external shared memory */
		virtual void setExternSharedMemorySize(unsigned int);
		
		/*! \brief Sets the max number of pthreads this kernel can use */
		virtual void setWorkerThreads(unsigned int workerThreadLimit);
			
		/*! \brief Indicate that the kernels arguments have been updated */
		virtual void updateArgumentMemory();
		
		/*! \brief Indicate that other memory has been updated */
		virtual void updateMemory();

		/*! sets an external function table for the emulated kernel */
		virtual void setExternalFunctionSet(
			const ir::ExternalFunctionSet& s);
		
		/*! clear the external function table for the emulated kernel */
		virtual void clearExternalFunctionSet();
		
		/*! \brief Get a vector of all textures references by the kernel */
		virtual TextureVector textureReferences() const;
	
	private:
	
		void _allocateConstantMemory();
		void _allocateArgumentMemory();
		void _allocateMemory();
	
	private:
		const ir::PTXKernel* _ptxKernel;
		const Device *_device;
		char *_argumentMemory;
		char *_constantMemory;
	};
	typedef std::map< std::string, DynamicMulticoreKernel *> DynamicMulticoreKernelMap;
	
}

#endif

