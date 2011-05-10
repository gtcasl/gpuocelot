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
#include <hydrazine/implementation/math.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_LOCAL_MEMORY 0

#define REPORT_SCHEDULE_OPERATIONS 0

#define REPORT_STATISTICS 1

#define REPORT_BASE 1

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
		
	local.resize(localMemorySize * totalThreads, 0);
	shared.resize(sharedMemorySize, 0);
	
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
	
	iterations = 0;
	size_t scheduleCycles = 0;
	
	translationTime = managerTime = 0;
	managerTimer.start();
	
	hydrazine::Timer testBarriersTimer;
	hydrazine::Timer warpFormationTimer;
	hydrazine::Timer warpExecutionTimer;
	
	double testBarriersTime = 0;
	double warpFormationTime = 0;
	double warpExecutionTime = 0;
	
	eTime0 = eTime1 = eTime2 = 0;
	
	reportE(REPORT_STATISTICS, "\nCTA");
	
	do {
		Warp warp;
		
		testBarriersTimer.start();
		
		testBarriers(waitingThreads, readyThreads);
		
		testBarriersTimer.stop();
		testBarriersTime += testBarriersTimer.seconds();
		
		if (readyThreads) {
			
			warpFormationTimer.start();
			
			// construct a warp
			warpFormation(warp);
			
			warpFormationTimer.stop();
			warpFormationTime += warpFormationTimer.seconds();
		
			reportE(REPORT_SCHEDULE_OPERATIONS, " formed warp with " << warp.threads.size() << " threads");
			
			warpExecutionTimer.start();
			
			// execute a warp
			executeWarp(warp);
			
			warpExecutionTimer.stop();
			warpExecutionTime += warpExecutionTimer.seconds();
			
			++scheduleCycles;
		}
	} while (waitingThreads || readyThreads);
	
	managerTimer.stop();
	managerTime += managerTimer.seconds();
	
	reportE(REPORT_STATISTICS,
		"Time spent in manager: " << managerTime << " seconds");
	reportE(REPORT_STATISTICS,
		"Time spent in translation: " << translationTime << " seconds");
		
	reportE(REPORT_STATISTICS,
		"Test barriers time: " << testBarriersTime << " seconds");
	reportE(REPORT_STATISTICS,
		"Warp formation time: " << warpFormationTime << " seconds");
	reportE(REPORT_STATISTICS,
		"Warp execution time: " << warpExecutionTime << " seconds");
		
	reportE(REPORT_STATISTICS,
		"Accumulated time 0: " << eTime0 << " seconds");
	reportE(REPORT_STATISTICS,
		"Accumulated time 1: " << eTime1 << " seconds");
	reportE(REPORT_STATISTICS,
		"Accumulated time 2: " << eTime2 << " seconds");
	
	if (scheduleCycles) {
		reportE(REPORT_STATISTICS, 
			"Average number of iterations to form a warp: " << (double)iterations / (double)scheduleCycles);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! 
	\brief execute a warp
	
*/
void LLVMDynamicExecutive::executeWarp(Warp &warp) {
	
	hydrazine::Timer genTimer;
	
	reportE(REPORT_SCHEDULE_OPERATIONS, "Executing warp of size " << warp.size() 
		<< " on hyperblockId " << warp.entryId);
	
	genTimer.start();
	
	// lazily fetch translation
	const LLVMDynamicTranslationCache::Translation *translation = 
		getOrInsertTranslationById(warp.entryId, warp.size());
	
	assert(translation && "failed to obtain translation");
	reportE(REPORT_SCHEDULE_OPERATIONS, " obtained translation. Executing warp.");
	
	genTimer.stop();
	eTime0 += genTimer.seconds();
	
	genTimer.start();
	
	for (ThreadContextVector::iterator ctx_it = warp.threads.begin(); 
		ctx_it != warp.threads.end(); 
		++ctx_it) {
		
		ctx_it->metadata = (char *)translation->metadata;
		assert(ctx_it->metadata);
	}
	
	genTimer.stop();
	eTime1 += genTimer.seconds();
	
	managerTimer.stop();
	managerTime += managerTimer.seconds();
	
	translationTimer.start();
	
	// primitive warp scheduler
	for (size_t tid = 0; tid < warp.threads.size(); tid += translation->warpSize) {
		translation->execute(&warp.threads[tid]);
	}
	
	translationTimer.stop();
	translationTime += translationTimer.seconds();
	
	managerTimer.start();

		genTimer.start();
		
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
		
		assert(ctaMap.find(ctaId) != ctaMap.end() && "CtaID not present in ctaMap");
		
		CooperativeThreadArray & cta = ctaMap[ctaId];
		
		switch (exitCode) {
		case analysis::HyperblockFormation::Thread_fallthrough:
			// update its next thread Id
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
					<< " into ready queue of CTA " << ctaId);
			cta.readyQueue.push_back(*ctx_it);
			break;
		case analysis::HyperblockFormation::Thread_branch:
			// update its next thread Id
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
					<< " into ready queue of CTA " << ctaId);
			cta.readyQueue.push_back(*ctx_it);
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
			cta.barrierQueue.push_back(*ctx_it);
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
		genTimer.stop();
		eTime2 += genTimer.seconds();
	
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
			
			++iterations;
		}
	}
	reportE(REPORT_SCHEDULE_OPERATIONS, 
		"formed warp of size " << warp.threads.size() << " with entryId " << warp.entryId);
		
	assert(warp.threads.size() && " failed to choose threads to form warp");
	
	size_t p = warp.threads.size();
	while (!hydrazine::isPowerOfTwo((unsigned int)p)) {
		LLVMContext & ctx = warp.threads[p - 1];
		
		unsigned int ctaId = LLVMDynamicExecutive::ctaId(ctx);
		ctaMap[ctaId].readyQueue.push_back(ctx);
		--p;
		
		++iterations;
	}
	if (p < warp.threads.size()) {
		warp.threads.resize(p);
	}
	assert(hydrazine::isPowerOfTwo((unsigned int)warp.threads.size()) && "warp size must be power of two");
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
		
		++iterations;
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

