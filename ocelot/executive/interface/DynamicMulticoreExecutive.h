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
#include <ocelot/api/interface/OcelotConfiguration.h>
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
		
		class CacheEvents {
		public:
			typedef api::OcelotConfiguration::TraceGeneration::PerformanceCounters PC;
			typedef api::OcelotConfiguration::TraceGeneration::PerformanceCounters::Set Set;
		public:
		
			CacheEvents(Set _cache = 
				api::OcelotConfiguration::TraceGeneration::PerformanceCounters::Cache_L1D);
			void start(Set _cache = 
				api::OcelotConfiguration::TraceGeneration::PerformanceCounters::Set_unknown);
			void stop();
			void clear();
			void write(std::ostream &out) const;
			static std::string toString(Set set);
		
		public:
			Set cache;
			size_t accesses, misses;
			bool valid;
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
		CacheEvents getCacheEvents() const { return _ctaCacheEvents; }
	protected:
	
		EventTimer _timerFirstKernelExecution;
		
		CTAEventTimer _ctaEvents;
		CacheEvents _ctaCacheEvents;
		
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

