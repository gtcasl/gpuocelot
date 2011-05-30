/*!
	\file LLVMDynamicExecutive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief executes one or more CTAs via a dynamic execution manager
*/

#ifndef OCELOT_EXECUTIVE_LLVMDYNAMICEXECUTIVE_H_INCLUDED
#define OCELOT_EXECUTIVE_LLVMDYNAMICEXECUTIVE_H_INCLUDED

// C++ includes
#include <map>
#include <vector>
#include <list>

// Ocelot includes
#include <ocelot/executive/interface/LLVMContext.h>
#include <ocelot/executive/interface/LLVMDynamicTranslationCache.h>
#include <ocelot/executive/interface/LLVMDynamicKernel.h>
#include <ocelot/analysis/interface/KernelPartitioningPass.h>

// Hydrazine includes
#include <hydrazine/implementation/Timer.h>

namespace executive {
	
	/*!
		\brief manages the executions of one or more CTAs on a single processor
	*/
	class LLVMDynamicExecutive {
	public:
		typedef std::map< int, size_t > EntryCounter;
		typedef ExecutableKernel::TextureVector TextureVector;
		typedef std::list< LLVMContext > ThreadContextQueue;
		typedef std::vector< char > ByteVector;
		
		//! maps CTA ID to a queue of waiting threads
		typedef std::map< unsigned int, ThreadContextQueue > CtaThreadQueue;
		
		typedef analysis::KernelPartitioningPass::EntryId EntryId;
		typedef analysis::KernelPartitioningPass::ThreadExitCode ThreadExitCode;
		typedef std::vector< LLVMContext > ThreadContextVector;
		
		typedef std::map< EntryId, LLVMDynamicTranslationCache::TranslationWarpMap > TranslationWarpCache;
		
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
			EntryId	nextEntryId;
			TextureVector textures;
			
		};
		
		/*!
			\brief a warp is a set of threads with the same hyperblock entry point
		*/
		class Warp {
		public:
			Warp(): entryId(0) { }
			size_t size() { return threads.size(); }
			
		public:
			//! \brief ordered sequence of threads
			ThreadContextVector threads;
			
			//! \brief 
			EntryId entryId;
		};
		
		class CooperativeThreadArray {
		public:
		
			void initialize(const LLVMDynamicKernel &kernel, const ir::Dim3 & ctaId, 
				EntryId entry, int localSize = 0, int sharedSize = 0);
		
			void resize(int localSize = 0, int sharedSize = 0, int constSize = 0, 
				int parameterSize = 0, int argumentSize = 0);
			
		public:
			ByteVector local;
			ByteVector shared;
			ByteVector constant;
			ByteVector parameter;
			ByteVector argument;
			
			ir::Dim3 blockId;
			ir::Dim3 blockDim;
						
			//! threads ready to execute
			ThreadContextQueue readyQueue;
			
			//! threads waiting on a barrier
			ThreadContextQueue barrierQueue;
		};
		typedef std::map< unsigned int, CooperativeThreadArray > CooperativeThreadArrayMap;
		
	public:
		//! \brief constructs a dynamic executive object
		LLVMDynamicExecutive(
			const LLVMDynamicKernel *kernel, 
			int procID, 
			const LLVMDynamicTranslationCache::TranslatedKernel *translatedKernel, 
			int sharedMemSize = 0);
		
		//! \brief executes all thread contexts and waits for termination before returning
		void execute();
		
		//! \brief adds a CTA to the dynamic executive's execution list
		void addCta(const ir::Dim3 &blockId);
		
	private:
	
		//! \brief searches for an existing translation and compiles it if it doesn't exist
		const LLVMDynamicTranslationCache::Translation *getOrInsertTranslationById(EntryId, int ws=1);
	
		//! \brief construct a warp
		void warpFormation(Warp &warp);
		
		//! \brief execute a warp
		void executeWarp(Warp &warp);
		
		//! \brief determine whether barriers have been reached
		void testBarriers(int &waiting, int &ready);
		
		//! \brief destroy a context before it is removed
		void finishContext(LLVMContext &context);
		
		//! \brief computes the CTA ID
		unsigned int ctaId(const ir::Dim3 &ctaId) const;
		
		//! \brief computes the CTA ID
		unsigned int ctaId(const LLVMContext &ctx) const;
		
		//! \brief computes the CTA ID
		unsigned int getThreadId(const LLVMContext &ctx) const;
		
		//! \brief gets the exit code of a thread
		static ThreadExitCode getExitCode(const LLVMContext &context);
				
		//! \brief determines a thread's next subkernel
		static EntryId getResumePoint(const LLVMContext &context);
		
		//! \brief sets the resume point of the context
		static void setResumePoint(const LLVMContext &context, EntryId resumeId);
		
	public:
	
		//! \brief kernel to execute
		const LLVMDynamicKernel *kernel;
		
		//! \brief procesor
		int processor;
		
		//! \brief 
		const LLVMDynamicTranslationCache::TranslatedKernel *translatedKernel;
		
		//! \brief dynamic shared memory size
		size_t sharedMemorySize;
		
		//! \brief set of active CTAs
		CooperativeThreadArrayMap ctaMap;
		
		//! \brief thread-local cache of translations
		TranslationWarpCache translationCache;
		
		EntryCounter entryCounter;
	};
}	
#endif

