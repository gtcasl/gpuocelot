/*!
	\file DynamicMulticoreExecutive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 20, 2011
	\brief executes a kernel over one or more CTAs
*/

#ifndef OCELOT_EXECUTIVE_DYNAMICMULTICOREEXECUTIVE_H_INCLUDED
#define OCELOT_EXECUTIVE_DYNAMICMULTICOREEXECUTIVE_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/Dim3.h>
#include <ocelot/executive/interface/DynamicMulticoreKernel.h>
#include <ocelot/analysis/interface/KernelPartitioningPass.h>
#include <ocelot/executive/interface/LLVMContext.h>

namespace executive {

	class DynamicMulticoreExecutive {
	public:
		typedef analysis::KernelPartitioningPass::SubkernelId SubkernelId;
		typedef analysis::KernelPartitioningPass::ThreadExitType ThreadExitType;
		typedef executive::MetaData Metadata;
		
	public:
		DynamicMulticoreExecutive(executive::DynamicMulticoreKernel &kernel, size_t sharedMemory);
		~DynamicMulticoreExecutive();
		
		void execute(const ir::Dim3 &block);
	
	protected:
		
		void _initializeThreadContexts(const ir::Dim3 &blockId);
		
		SubkernelId _getResumePoint(const LLVMContext *context);
		void _setResumePoint(const LLVMContext *context, SubkernelId subkernel);
		ThreadExitType _getResumeStatus(const LLVMContext *context);
		void _setResumeStatus(const LLVMContext *context, ThreadExitType status);

		void _emitThreadLocalMemory(const LLVMContext *context);
		void _emitParameterMemory(const LLVMContext *context);
			
	protected:
	
		DynamicMulticoreKernel *kernel;
		
		char *localMemory;
		size_t localMemorySize;
		
		char *sharedMemory;
		size_t sharedMemorySize;
		
		char *parameterMemory;
		size_t parameterMemorySize;
		
		LLVMContext *contexts;
	};

}

#endif

