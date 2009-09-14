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
			/*! \brief A set of PTX threads */
			typedef std::stack< unsigned int > ThreadSet;
			/*! \brief A function pointer to the translated kernel */
			typedef unsigned int (*Function)( LLVMContext* );
			
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
			
		private:
			/*! \brief Determine the padding required to satisfy alignment */
			unsigned int _pad( size_t& size, unsigned int alignment );
		
		private:
			/*! \brief Create the LLVM module from the code */
			void _translateKernel();
			
			/*! \brief Run various LLVM optimizer passes on the kernel */
			void _optimize();
			
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
			void _allocateMemory();

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
			/*! \brief Update parameter memory */
			void updateParameterMemory();
	};
}

#endif

