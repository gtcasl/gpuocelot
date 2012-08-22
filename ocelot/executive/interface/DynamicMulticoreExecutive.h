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
#include <ocelot/executive/interface/DynamicTranslationCache.h>
#include <ocelot/executive/interface/EventTimer.h>

namespace executive {

	class DynamicMulticoreExecutive {
	public:
		typedef analysis::KernelPartitioningPass::SubkernelId SubkernelId;
		typedef analysis::KernelPartitioningPass::ThreadExitType ThreadExitType;
		typedef executive::MetaData Metadata;
		typedef executive::DynamicTranslationCache::Translation Translation;	
		
		class CTAEventTimer {
		public:
			CTAEventTimer();
			void write(std::ostream &out) const;
		public:
			EventTimer total;
			EventTimer initialize;
			EventTimer scheduling;
			EventTimer subkernelExecution;
			EventTimer compilation;
		};
		
		class EventsCache {
		public:
			enum Cache {
				L1_data, L1_instruction, L2, L3
			};
		public:
		
			EventsCache(Cache _cache = L1_data);
			void start();
			void stop();
		
			Cache cache;
			size_t accesses, misses;
			bool valid;
		};
		
		class CacheEventSet {
		public:
			CacheEventSet();
		public:
			EventsCache eventsL1D;
			EventsCache eventsL1I;
			EventsCache eventsL2;
			EventsCache eventsL3;
		};
		
	public:
		DynamicMulticoreExecutive(const executive::DynamicMulticoreKernel &kernel, size_t sharedMemory);
		~DynamicMulticoreExecutive();
		
		void execute(const ir::Dim3 &block);
		
	protected:
	
		void _executeDefault(const ir::Dim3 &block);
		void _executeIterateSubkernelBarriers(const ir::Dim3 &block);
		void _executeWarp(LLVMContext *contexts, size_t threads);
	
	protected:
		
		void _initializeThreadContexts(const ir::Dim3 &blockId);
		
		SubkernelId _getResumePoint(const LLVMContext *context);
		void _setResumePoint(const LLVMContext *context, SubkernelId subkernel);
		ThreadExitType _getResumeStatus(const LLVMContext *context);
		void _setResumeStatus(const LLVMContext *context, ThreadExitType status);

		void _emitThreadLocalMemory(const LLVMContext *context);
		void _emitParameterMemory(const LLVMContext *context);
			
		const Translation *_getOrInsertTranslation(int warpsize, SubkernelId subkernel, 
			unsigned int specialization = 0);
		
	public:
		EventTimer getFirstKernelExecutionTimer() const { return _timerFirstKernelExecution; }
		CTAEventTimer getCtaTimer() const { return _ctaEvents; }
	protected:
	
		EventTimer _timerFirstKernelExecution;
		
		CTAEventTimer _ctaEvents;
		
	protected:
	
		DynamicTranslationCache::WarpTranslationVector translationVector;
	
		const DynamicMulticoreKernel *kernel;
		
		char *localMemory;
		size_t localMemorySize;
		
		char *sharedMemory;
		size_t sharedMemorySize;
		
		char *parameterMemory;
		size_t parameterMemorySize;
		
		LLVMContext *contexts;
		
		unsigned int maximumWarpSize;
	};

}

#endif

