/*!
	\file LLVMExecutableKernel.h
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMRuntime class
*/

#ifndef LLVM_EXECUTABLE_KERNEL_H_INCLUDED
#define LLVM_EXECUTABLE_KERNEL_H_INCLUDED

#include <ocelot/ir/interface/LLVMKernel.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/executive/interface/LLVMContext.h>

#include <stack>

namespace llvm
{
	class ExistingModuleProvider;
	class ExecutionEngine;
	class Module;
	class Context;
}

namespace executive
{
	/*! \brief Executes an LLVMKernel using the LLVM JIT */
	class LLVMExecutableKernel : public ir::ExecutableKernel
	{
		private:
			/*! \brief A map from a variable identifier to its allocation */
			typedef std::unordered_map< std::string, size_t > AllocationMap;
			/*! \brief A type for referring to a specific PTX thread */
			typedef unsigned int ThreadContext;
			/*! \brief A function pointer to the translated kernel */
			typedef unsigned int (*Function)( LLVMContext* );
			/*! \brief Shorthand for a PTX instruction vector */
			typedef ir::PTXKernel::PTXInstructionVector PTXInstructionVector;
			
			/*! \brief A class for managing global llvm state */
			class LLVMState
			{
				public:
					/*! \brief LLVM module */
					llvm::Module* module;
					/*! \brief Module provider */
					llvm::ExistingModuleProvider* moduleProvider;
					/*! \brief LLVM JIT Engine */
					llvm::ExecutionEngine* jit;

				public:
					/*! \brief Build the jit */
					LLVMState();
					/*! \brief Destroy the jit */
					~LLVMState();
			};

		private:
			/*! \brief Contains the LLVM JIT for all LLVM kernels */
			static LLVMState _state;		
		
		private:
			/*! \brief The memory requirements and execution context */
			LLVMContext _context;
	
		private:
			/*! \brief LLVM module */
			llvm::Module* _module;
			/*! \brief Module provider */
			llvm::ExistingModuleProvider* _moduleProvider;
			/*! \brief The translated function */
			Function _function;
			/*! \brief The stored ptx kernel used for translation */
			ir::PTXKernel* _ptx;
			/*! \brief Does this kernel require barrier support? */
			bool _barrierSupport;
			/*! \brief The barrier resume point variable */
			std::string _resumePoint;
			/*! \brief The resume point offset */
			unsigned int _resumePointOffset;
			/*! \brief External shared memory */
			unsigned int _externalSharedSize;
			/*! \brief Constant memory mapping */
			AllocationMap _constants;
			
			
		private:
			/*! \brief Determine the padding required to satisfy alignment */
			unsigned int _pad( size_t& size, unsigned int alignment );
		
		private:
			/*! \brief Run various PTX optimizer passes on the kernel */
			void _optimizePtx();
			
			/*! \brief Create the LLVM module from the code */
			void _translateKernel();
			
			/*! \brief Run various LLVM optimizer passes on the kernel */
			void _optimize();
			
			/*! \brief Launch the CTA without barrier support */
			void _launchCtaNoBarriers( );
			
			/*! \brief Launch the CTA with barrier support */
			void _launchCtaWithBarriers( );
			
			/*! \brief Launch a specific CTA within a kernel */
			void _launchCta( unsigned int x, unsigned int y );
			
			/*! \brief Allocate parameter memory */
			void _allocateParameterMemory( );

			/*! \brief Allocate shared memory */
			void _allocateSharedMemory( );
			
			/*! \brief Allocate global memory */
			void _allocateGlobalMemory( );
			
			/*! \brief Allocate local memory */
			void _allocateLocalMemory( );
			
			/*! \brief Allocate constant memory */
			void _allocateConstantMemory( );
			
			/*! \brief Allocate texture memory */
			void _allocateTextureMemory( );
			
			/*! \brief Scan the kernel and determine memory requirements */
			void _allocateMemory( );

		public:
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
			/*! \brief Get the number of threads per cta */
			unsigned int threads() const;
			/*! \brief Get the local id of the current thread */
			unsigned int threadId() const;
		public:
			/*! \brief Get the constant memory size */
			unsigned int constantMemorySize() const;
			/*! \brief Get the shared memory size */
			unsigned int sharedMemorySize() const;
			
		public:
			/*! \brief Declare an amount of external shared memory */
			void externSharedMemory( unsigned int bytes );
			/*! \brief Reload parameter memory */
			void updateParameterMemory();
			/*! \brief Reload global memory */
			void updateGlobalMemory();
			/*! \brief Reload constant memory */
			void updateConstantMemory();
	};
}

#endif

