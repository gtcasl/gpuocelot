/*!
	\file ExecutableKernel.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 19, 2009
	\brief implements a kernel that is executable on some device
*/

#ifndef IR_EXECUTABLEKERNEL_H_INCLUDED
#define IR_EXECUTABLEKERNEL_H_INCLUDED

#include <ocelot/ir/interface/Kernel.h>

namespace executive {
	class Executive;
	class Device;
}

namespace ir {
	
	/*!
		\brief base class for all executable kernel classes
	*/
	class ExecutableKernel : public Kernel {
	public:
	
		const executive::Executive* const context;
		
	public:
		ExecutableKernel(const Kernel& k, const executive::Executive* c = 0) 
			: Kernel(k), context(c) {}
		ExecutableKernel(const executive::Executive* c = 0) : context(c) {}
		virtual ~ExecutableKernel();
	
		/*!	\brief Determines whether kernel is executable */
		virtual bool executable() { return false; }

		/*!
			attribute accessors - things every executable kernel should know about itself
		*/
		int getConstMemorySize() const { return _constMemorySize; }
		int getLocalMemorySize() const { return _localMemorySize; }
		int getMaxThreadsPerBlock() const { return _maxThreadsPerBlock; }
		int getRegisterCount() const { return _registerCount; }
		int getSharedMemorySize() const { return _sharedMemorySize; }
		
		//! maps parameters to offsets in the block of parameter memory and returns size of this block
		size_t mapParameters();
		
		//! sets parameter values from a block of parameter data
		virtual void setParameterBlock(const void *param, size_t size);
		
		//! gets a dense representation of parameter memory given current values of parameters
		virtual void getParameterBlock(void *param, size_t size) const;

		/*!	\brief Launch a kernel on a 2D grid */
		virtual void launchGrid(int width, int height)=0;
	
		/*!	\brief Sets the shape of a kernel */
		virtual void setKernelShape(int x, int y, int z)=0;
		
		/*! \brief Describes the device used to execute the kernel */
		virtual void setDevice(const executive::Device* device, unsigned int limit)=0;

	protected:
		int _constMemorySize;
		int _localMemorySize;
		int _maxThreadsPerBlock;
		int _registerCount;
		int _sharedMemorySize;
	};
	
}

#endif
