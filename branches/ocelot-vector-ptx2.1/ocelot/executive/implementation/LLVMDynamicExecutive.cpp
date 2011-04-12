/*!
	\file LLVMDynamicExecutive.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief executes one or more CTAs via a dynamic execution manager
*/

// C++ includes
#include <fstream>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/executive/interface/LLVMDynamicExecutive.h>
#include <ocelot/executive/interface/LLVMDynamicExecutionManager.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_LOCAL_MEMORY 0

#define REPORT_SCHEDULE_OPERATIONS 1

#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace executive {

/////////////////////////////////////////////////////////////////////////////////////////////////

LLVMDynamicExecutive::Metadata::Metadata() {

}

LLVMDynamicExecutive::Metadata::~Metadata() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

void LLVMDynamicExecutive::CooperativeThreadArray::initialize(
	const LLVMDynamicKernel &kernel, 
	const ir::Dim3 &ctaId,
	HyperblockId entry,
	int localMemorySize,
	int sharedMemorySize) {

	const ir::Dim3 blockDim = kernel.blockDim();
	
	int totalThreads = blockDim.x * blockDim.y * blockDim.z;

	report("Initializing CTA (" << ctaId.x << ", " << ctaId.y << ", " << ctaId.z << ") with " << totalThreads << " threads");
	report("  local memory size " << localMemorySize << " bytes");
	report("  shared memory size: " << sharedMemorySize << " bytes");
		
	local.resize(localMemorySize * totalThreads, 0);
	shared.resize(sharedMemorySize, 0);

	if (localMemorySize) {	
		report("  local memory range: " << (const void *)&local[0] 
			<< " - " << (const void *)&local[local.size()-1]);
	}
	if (sharedMemorySize) {
		report("  shared memory range: " << (const void *)&shared[0] 
			<< " - " << (const void *)&shared[shared.size()-1]);
	}
	
	for (int threadId = 0; threadId < totalThreads; threadId++) {
		LLVMContext context;
		context.nctaid.x  = kernel.gridDim().x;
		context.nctaid.y  = kernel.gridDim().y;
		context.nctaid.z  = kernel.gridDim().z;
		context.ctaid.x   = ctaId.x;
		context.ctaid.y   = ctaId.y;
		context.ctaid.z   = ctaId.z;
		context.ntid.x    = blockDim.x;
		context.ntid.y    = blockDim.y;
		context.ntid.z    = blockDim.z;
		context.tid.x     = threadId % context.ntid.x;
		context.tid.y     = (threadId / context.ntid.x) % context.ntid.y;
		context.tid.z     = threadId / (context.ntid.x * context.ntid.y);
		context.shared    = reinterpret_cast<char*>(&shared[0]);
		context.argument  = kernel.argumentMemory();	//stack.argumentMemory();
		context.local     = &local[threadId * localMemorySize];	//stack.localMemory();
		context.parameter = 0;	//stack.parameterMemory();
		context.constant  = kernel.constantMemory();
		context.metadata  = 0;
		
		setResumePoint(context, entry);
		readyQueue.push_back(context);
	}
}

void LLVMDynamicExecutive::CooperativeThreadArray::resize(
	int localSize, 
	int sharedSize, 
	int constSize,
	int parameterSize, 
	int argumentSize) {
	
	local.resize(localSize, 0);
	shared.resize(sharedSize, 0);
	constant.resize(constSize, 0);
	parameter.resize(parameterSize, 0);
	argument.resize(argumentSize, 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////


LLVMDynamicExecutive::LLVMDynamicExecutive(
	const LLVMDynamicKernel *_kernel, 
	int _procID, 
	const LLVMDynamicTranslationCache::TranslatedKernel *_translatedKernel, 
	int _sharedMemSize)
:
	kernel(_kernel),
	processor(_procID),
	translatedKernel(_translatedKernel),
	sharedMemorySize(_sharedMemSize + _translatedKernel->sharedMemorySize) {
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////


//! \brief computes the CTA ID
unsigned int LLVMDynamicExecutive::ctaId(const ir::Dim3 &ctaId) {
	return (unsigned int)(kernel->gridDim().x * ctaId.y + ctaId.x);
}


unsigned int LLVMDynamicExecutive::ctaId(const LLVMContext &ctx) {
	return (unsigned int)(kernel->gridDim().x * ctx.ctaid.y + ctx.ctaid.x);
}

//! \brief adds a CTA to the dynamic executive's execution list
void LLVMDynamicExecutive::addCta(const ir::Dim3 &blockId) {
	ctaMap[ctaId(blockId)].initialize(
		*kernel, 
		blockId, 
		translatedKernel->entryBlockId, 
		translatedKernel->localMemorySize, 
		sharedMemorySize);
}


//! \brief destroy a context before it is removed
void LLVMDynamicExecutive::finishContext(LLVMContext &context) {

}


//! \brief gets the exit code of a thread
LLVMDynamicExecutive::ThreadExitCode LLVMDynamicExecutive::getExitCode(
	const LLVMContext &context) {

	return (ThreadExitCode)*((int *)&context.local[0]);
}

LLVMDynamicExecutive::HyperblockId LLVMDynamicExecutive::getResumePoint(
	const LLVMContext &context) {
	
	return *((HyperblockId *)&context.local[4]);
}

//! \brief sets the resume point of the context
void LLVMDynamicExecutive::setResumePoint(
	const LLVMContext &context, 
	LLVMDynamicExecutive::HyperblockId hbId) {
	*((HyperblockId *)&context.local[4]) = hbId;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! 
	\brief executes all thread contexts and waits for termination before returning
	
	Algorithm;
	
	- 1.) if no threads are in the ready queue, then all non-exited threads should be waiting on a barrier.
			Copy waiting threadQueues into ready thread queues
	
	- 2.) if no threads are in the waiting queues or ready queues corresponding to a particular
		CTA, consider requesting additional CTAs before proceeding
		
	- 3.) form a warp from threads in the ready queue (choose from same CTA or different CTA),
		dispatch threads to their indicated hyperblock
		
	- 4.) on return from hyperblock scheduling, update each thread's next hyperblock:
		- threads may exit on:
			- function call: not handled at present
			- tail call: treat as branch
			
			- branch: check for divergence, update targets based on hyperblock formation
			- exit:   remove context
			- barrier: remove from ready queue, place in wait queue

*/
void LLVMDynamicExecutive::execute() {
	int waitingThreads = 0;
	int readyThreads = 0;
	
	reportE(REPORT_SCHEDULE_OPERATIONS, "execute()");
	
	do {
		Warp warp;
		
		testBarriers(waitingThreads, readyThreads);
		
		if (readyThreads) {
			
			// construct a warp
			warpFormation(warp);
		
			reportE(REPORT_SCHEDULE_OPERATIONS, " formed warp with " << warp.threads.size() << " threads");
			// execute a warp
			executeWarp(warp);
		}
	} while (waitingThreads || readyThreads);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! 
	\brief execute a warp
	
*/
void LLVMDynamicExecutive::executeWarp(Warp &warp) {
	
	reportE(REPORT_SCHEDULE_OPERATIONS, "Executing warp of size " << warp.size() 
		<< " on hyperblockId " << warp.entryId);
	
	// lazily fetch translation
	const LLVMDynamicTranslationCache::Translation *translation = 
		getOrInsertTranslationById(warp.entryId, warp.size());
	
	assert(translation && "failed to obtain translation");
	reportE(REPORT_SCHEDULE_OPERATIONS, " obtained translation. Executing warp.");
	
	for (ThreadContextVector::iterator ctx_it = warp.threads.begin(); 
		ctx_it != warp.threads.end(); 
		++ctx_it) {
		
		ctx_it->metadata = (char *)translation->metadata;
		assert(ctx_it->metadata);
		
#if REPORT_BASE && REPORT_LOCAL_MEMORY
		reportE(REPORT_SCHEDULE_OPERATIONS, 
			"thread (" << ctx_it->tid.x << "," << ctx_it->tid.y << "," << ctx_it->tid.z 
			<< ") - entering block " << warp.entryId);
		
		report("Before: ");
		unsigned int localSize = 352;
		for (unsigned int i = 0; i < (localSize & (~0x03)); i+=4) {
			unsigned int word = *(const unsigned int *)&ctx_it->local[i];
			if (word) {
				std::cout << ".local[" << i << "]: " << (const void *)word << "\n";
			}
		}
		std::cout << std::endl;
#endif
	}
	
	// primitive warp scheduler
	for (size_t tid = 0; tid < warp.threads.size(); tid += translation->warpSize) {
		translation->execute(&warp.threads[tid]);
	}

	for (
		ThreadContextVector::iterator ctx_it = warp.threads.begin(); 
		ctx_it != warp.threads.end(); 
		++ctx_it) {
	
		ThreadExitCode exitCode = getExitCode(*ctx_it);
		unsigned int ctaId = LLVMDynamicExecutive::ctaId(*ctx_it);
		
		reportE(REPORT_SCHEDULE_OPERATIONS, 
			" thread(" << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
			<< ") [cta " << ctaId << "] exited with code " 
			<< analysis::HyperblockFormation::toString(exitCode) 
			<< " - resume point: " << getResumePoint(*ctx_it));
		
#if REPORT_BASE && REPORT_LOCAL_MEMORY
		unsigned int localSize = 352;
		reportE(REPORT_SCHEDULE_OPERATIONS, "After: ");
		for (unsigned int i = 0; i < (localSize & (~0x03)); i+=4) {
			unsigned int word = *(const unsigned int *)&ctx_it->local[i];
			if (word) {
				std::cout << ".local[" << i << "]: " << (const void *)word << "\n";
			}
		}
		std::cout << std::endl;
#endif
		
		assert(ctaMap.find(ctaId) != ctaMap.end() && "CtaID not present in ctaMap");
		
		switch (exitCode) {
		case analysis::HyperblockFormation::Thread_fallthrough:
			// update its next thread Id
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
					<< " into ready queue of CTA " << ctaId);
			ctaMap[ctaId].readyQueue.push_back(*ctx_it);
			break;
		case analysis::HyperblockFormation::Thread_branch:
			// update its next thread Id
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
					<< " into ready queue of CTA " << ctaId);
			ctaMap[ctaId].readyQueue.push_back(*ctx_it);
			break;
		case analysis::HyperblockFormation::Thread_tailcall:
			// update its next thread Id
			assert(0 && "calls not implemented");
			break;
		case analysis::HyperblockFormation::Thread_call:
			// update its next thread Id
			assert(0 && "calls not implemented");
			break;
		case analysis::HyperblockFormation::Thread_barrier:
			// update its next thread Id, place into a waiting queue
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
					<< " into barrier queue of CTA " << ctaId);
			ctaMap[ctaId].barrierQueue.push_back(*ctx_it);
			break;
		case analysis::HyperblockFormation::Thread_exit:
			// kill off the thread
			break;
		case analysis::HyperblockFormation::Thread_exit_other:
			break;
		default: assert(0 && "invalid ThreadExitCode");
			break;
		}
	}
}

//! \brief construct a warp - for now, simply choose a ready thread
void LLVMDynamicExecutive::warpFormation(Warp &warp) {
	const size_t warpSize = api::OcelotConfiguration::get().executive.warpSize;
	warp.threads.resize(0);
	warp.threads.reserve(warpSize);
	
	for (CooperativeThreadArrayMap::iterator cta_it = ctaMap.begin();
		cta_it != ctaMap.end() && warp.threads.size() < warpSize;
		++cta_it) {
		
		for (ThreadContextQueue::iterator ctx_it = cta_it->second.readyQueue.begin();
			ctx_it != cta_it->second.readyQueue.end() && warp.threads.size() < warpSize;) {
			HyperblockId entryId = getResumePoint(*ctx_it);
			if (!warp.threads.size() || entryId == warp.entryId) {
				warp.entryId = entryId;
				warp.threads.push_back(*ctx_it);
				ctx_it = cta_it->second.readyQueue.erase(ctx_it);
			}
			else {
				++ctx_it;
			}
		}
	}
	reportE(REPORT_SCHEDULE_OPERATIONS, 
		"formed warp of size " << warp.threads.size() << " with entryId " << warp.entryId);
	assert(warp.threads.size() && " failed to choose threads to form warp");
}

//! \brief determine if any barriers have been reached
void LLVMDynamicExecutive::testBarriers(int &waiting, int &ready) {
	ready = waiting = 0;
	for (CooperativeThreadArrayMap::iterator cta_it = ctaMap.begin();
		cta_it != ctaMap.end();
		++cta_it) {
		
		if (cta_it->second.barrierQueue.size() && !cta_it->second.readyQueue.size()) {
			cta_it->second.readyQueue = cta_it->second.barrierQueue;
			cta_it->second.barrierQueue.clear();
		}
		
		ready += (int)cta_it->second.readyQueue.size();
		waiting += (int)cta_it->second.barrierQueue.size();
	}
}

//! \brief searches for an existing translation and compiles it if it doesn't exist
const LLVMDynamicTranslationCache::Translation *
LLVMDynamicExecutive::getOrInsertTranslationById(HyperblockId id, int ws) {

	const LLVMDynamicTranslationCache::Translation *translation =0;
	TranslationWarpCache::iterator hb_it = translationCache.find(id);
	
	reportE(REPORT_SCHEDULE_OPERATIONS, 
		" getOrInsertTranslationById( id: " << id << ", ws: " << ws << ")");
	
	if (hb_it != translationCache.end()) {
		LLVMDynamicTranslationCache::TranslationWarpMap::iterator tr_it = hb_it->second.find(ws);
		if (tr_it != hb_it->second.end()) {
			translation = tr_it->second;
			reportE(REPORT_SCHEDULE_OPERATIONS, "hit local translation cache");
		}
		else {
			// not found for this warp size. query the singleton translation cache
			translation = LLVMDynamicExecutionManager::get().getOrInsertTranslationById(id, ws);
			hb_it->second[ws] = translation;
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"no translation found for this warp size. Querying global translation cache.");
		}
	}
	else {
		// not found for any warp size. query the singleton translation cache
		reportE(REPORT_SCHEDULE_OPERATIONS, 
			"no translation found for hyperblock id. Querying global translation cache.");
		translation = LLVMDynamicExecutionManager::get().getOrInsertTranslationById(id, ws);
		LLVMDynamicTranslationCache::TranslationWarpMap warpMap;
		warpMap[ws] = translation;
		translationCache[id] = warpMap;
	}
	return translation;
}

}

