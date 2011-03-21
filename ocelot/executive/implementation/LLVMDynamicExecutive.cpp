/*!
	\file LLVMDynamicExecutive.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief executes one or more CTAs via a dynamic execution manager
*/

// C++ includes

// Ocelot includes
#include <fstream>
#include <ocelot/executive/interface/LLVMDynamicExecutive.h>
#include <ocelot/executive/interface/LLVMDynamicExecutionManager.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_BASE 1

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace executive {

LLVMDynamicExecutive::Metadata::Metadata() {

}

LLVMDynamicExecutive::Metadata::~Metadata() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

LLVMDynamicExecutive::LLVMDynamicExecutive(
	const LLVMDynamicKernel *_kernel, 
	int procID,
	HyperblockId _entryId)
:
	kernel(_kernel),
	processor(procID),
	entryId(_entryId)
{
	report("LLVMDynamicExecutive");
	report(" local memory size: " << _kernel->localMemorySize());
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
	ctaMap[ctaId(blockId)].initialize(*kernel, blockId, entryId);
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
	
	report("execute()");
	
	do {
		Warp warp;
		
		testBarriers(waitingThreads, readyThreads);
		
		if (readyThreads) {
			
			// construct a warp
			warpFormation(warp);
		
			report(" formed warp with " << warp.threads.size() << " threads");
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
	
	report("Executing warp of size " << warp.size() << " on hyperblockId " << warp.entryId);
	
	// lazily fetch translation
	const LLVMDynamicTranslationCache::Translation *translation = 
		getOrInsertTranslationById(warp.entryId, warp.size());
	
	assert(translation && "failed to obtain translation");
	report(" obtained translation. Executing warp.");
	
	for (ThreadContextVector::iterator ctx_it = warp.threads.begin(); 
		ctx_it != warp.threads.end(); 
		++ctx_it) {
		ctx_it->metadata = (char *)translation->metadata;
		
		report("thread (" << ctx_it->tid.x << "," << ctx_it->tid.y << "," << ctx_it->tid.z << ") - entering block " << warp.entryId);
	}
	
	translation->execute(&warp.threads[0]);
	
	for (
		ThreadContextVector::iterator ctx_it = warp.threads.begin(); 
		ctx_it != warp.threads.end(); 
		++ctx_it) {
	
		ThreadExitCode exitCode = getExitCode(*ctx_it);
		report(" thread(" << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z << ") [cta ] exited with code " 
			<< analysis::HyperblockFormation::toString(exitCode) << " - resume point: " << getResumePoint(*ctx_it));
		unsigned int ctaId = LLVMDynamicExecutive::ctaId(*ctx_it);
		
		switch (exitCode) {
		case analysis::HyperblockFormation::Thread_fallthrough:
			// update its next thread Id
			ctaMap[ctaId].readyQueue.push_back(*ctx_it);
			break;
		case analysis::HyperblockFormation::Thread_branch:
			// update its next thread Id
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
	warp.threads.resize(1);
	for (CooperativeThreadArrayMap::iterator cta_it = ctaMap.begin();
		cta_it != ctaMap.end();
		++cta_it) {
		
		if (cta_it->second.readyQueue.size()) {
			warp.threads[0] = cta_it->second.readyQueue.front();
			cta_it->second.readyQueue.pop_front();
			warp.entryId = getResumePoint(warp.threads[0]);
			return; 
		}
	}
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

void LLVMDynamicExecutive::CooperativeThreadArray::initialize(
	const LLVMDynamicKernel &kernel, 
	const ir::Dim3 &ctaId,
	HyperblockId entry) {

	const ir::Dim3 blockDim = kernel.blockDim();
	
	int totalThreads = blockDim.x * blockDim.y * blockDim.z;
	unsigned int localMemorySize = 256;
	local.resize(localMemorySize * totalThreads, 0);
	shared.resize(1024, 0);
	
	report("Initializing CTA with " << totalThreads << " threads");
	report("  local memory size " << local.size() << " bytes");
	report("  shared memory size: " << shared.size() << " bytes");
	
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


//! \brief searches for an existing translation and compiles it if it doesn't exist
const LLVMDynamicTranslationCache::Translation *
LLVMDynamicExecutive::getOrInsertTranslationById(HyperblockId id, int ws) {

	const LLVMDynamicTranslationCache::Translation *translation =0;
	TranslationWarpCache::iterator hb_it = translationCache.find(id);
	
	report(" getOrInsertTranslationById( id: " << id << ", ws: " << ws << ")");
	
	if (hb_it != translationCache.end()) {
		LLVMDynamicTranslationCache::TranslationWarpMap::iterator tr_it = hb_it->second.find(ws);
		if (tr_it != hb_it->second.end()) {
			translation = tr_it->second;
			report("hit local translation cache");
		}
		else {
			// not found for this warp size. query the singleton translation cache
			translation = LLVMDynamicExecutionManager::get().getOrInsertTranslationById(id, ws);
			hb_it->second[ws] = translation;
			report("no translation found for this warp size. Querying global translation cache.");
		}
	}
	else {
		// not found for any warp size. query the singleton translation cache
		report("no translation found for hyperblock id. Querying global translation cache.");
		translation = LLVMDynamicExecutionManager::get().getOrInsertTranslationById(id, ws);
		LLVMDynamicTranslationCache::TranslationWarpMap warpMap;
		warpMap[ws] = translation;
		translationCache[id] = warpMap;
	}
	return translation;
}

}

