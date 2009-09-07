/*!
	\file LLVMExecutableKernel.h
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMRuntime class
*/

#ifndef LLVM_EXECUTABLE_KERNEL_H_INCLUDED
#define LLVM_EXECUTABLE_KERNEL_H_INCLUDED

#include <ocelot/ir/interface/LLVMKernel.h>
#include <ocelot/ir/interface/ExecutableKernel.h>

namespace executive
{
	/*! \brief Executes an LLVMKernel using the LLVM JIT */
	class LLVMExecutableKernel : public ir::ExecutableKernel
	{
		private:
			/*! \brief The CTA dimensions */
			ir::dim3 _ctaDimensions;
			/*! \brief The kernel dimensions */
			ir::dim3 _kernelDimensions;

		public:
			/*! \brief Creates a new instance of the runtime bound to a kernel*/
			LLVMExecutableKernel( ir::LLVMKernel& kernel, 
				const executive::Executive* c = 0 );
			/*! \brief Creates a new instance of the runtime bound to a kernel*/
			LLVMExecutableKernel( ir::Kernel& kernel, 
				const executive::Executive* c = 0 );
			/*! \brief Clean up the runtime */
			~LLVMExecutableKernel();

		public:
			/*! \brief Launch a kernel on a 2D grid */
			void launchGrid( int width, int height );
			/*! \brief Sets the shape of a cta in the kernel */
			void setKernelShape( int x, int y, int z );
			
		public:
			/*! \brief Update parameter memory */
			void updateParameterMemory();
	};
}

#endif

