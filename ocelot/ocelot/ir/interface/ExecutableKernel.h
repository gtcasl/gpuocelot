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
	
	class ExecutableKernel : public Kernel {
	public:
		const executive::Executive* const context;
	public:
		ExecutableKernel(const Kernel& k, const executive::Executive* c = 0) 
			: Kernel(k), context(c) {}
		ExecutableKernel(const executive::Executive* c = 0) : context(c) {}
		virtual ~ExecutableKernel() {}
	
		/*!	\brief Determines whether kernel is executable */
		virtual bool executable() {
			return false;
		}
	
		/*!	\brief Launch a kernel on a 2D grid */
		virtual void launchGrid(int width, int height)=0;
	
		/*!	\brief Sets the shape of a kernel */
		virtual void setKernelShape(int x, int y, int z)=0;
		
		/*! \brief Describes the device used to execute the kernel */
		virtual void setDevice(const executive::Device* device,
			unsigned int limit)=0;
	};
	
}

#endif
