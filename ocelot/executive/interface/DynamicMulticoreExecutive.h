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
		
		/*!
			\brief per kernel data structure accessible to the translation
		*/
		class Metadata {
		public:
			Metadata();
			~Metadata();
			
		public:		
			unsigned int sharedSize;
			unsigned int localSize;
			unsigned int parameterSize;
			unsigned int argumentSize;
			unsigned int constantSize;
			unsigned int warpSize;
			
		public:
			const ir::PTXKernel* kernel;
			
			SubkernelId	nextEntryId;
			
			executive::ExecutableKernel::TextureVector textures;
		};
		
	public:
		DynamicMulticoreExecutive(executive::DynamicMulticoreKernel &kernel, size_t sharedMemory);
		~DynamicMulticoreExecutive();
		
		void execute(const ir::Dim3 &block);
	
	protected:
		
		void _initializeThreadContexts(const ir::Dim3 &blockId);
		
		SubkernelId _getResumePoint(const LLVMContext *context, int tid);
		void _setResumePoint(const LLVMContext *context, int tid, SubkernelId subkernel);
		ThreadExitType _getResumeStatus(const LLVMContext *context, int tid);
		void _setResumeStatus(const LLVMContext *context, int tid, ThreadExitType status);

			
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

