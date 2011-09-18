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
#include <ocelot/executive/interface/LLVMDynamicExecutionMetrics.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/math.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_LOCAL_MEMORY 0
#define REPORT_SCHEDULE_OPERATIONS 1
#define REPORT_STATISTICS 0

#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {
  __inline__ size_t rdtsc(void) {
    uint32_t lo, hi;
    __asm__ __volatile__ (
    "xorl %%eax,%%eax \n        cpuid"
    ::: "%rax", "%rbx", "%rcx", "%rdx");
    __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
    return (size_t)hi << 32 | lo;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace executive {

/////////////////////////////////////////////////////////////////////////////////////////////////

LLVMDynamicExecutive::Metadata::Metadata() {

}

LLVMDynamicExecutive::Metadata::~Metadata() {

}

LLVMDynamicExecutive::SubkernelCycleTimer::SubkernelCycleTimer():
	subkernelCycles(0), entryCycles(0), entryLiveness(0), exitCycles(0), exitLiveness(0), 
	entryCount(0), exitCount(0) {

}

LLVMDynamicExecutive::SubkernelCycleTimer::SubkernelCycleTimer(
	size_t _subkernelCycles, 
	size_t _entryCycles, 
	size_t _entryLiveness, 
	size_t _exitCycles, 
	size_t _exitLiveness
):
	subkernelCycles(_subkernelCycles), entryCycles(_entryCycles), entryLiveness(_entryLiveness), 
		exitCycles(_exitCycles), exitLiveness(_exitLiveness), entryCount(1), exitCount(1) {

}

LLVMDynamicExecutive::SubkernelCycleTimer & 
	LLVMDynamicExecutive::SubkernelCycleTimer::operator+=(const SubkernelCycleTimer &timer) {
	
	subkernelCycles += timer.subkernelCycles;
	entryCycles += timer.entryCycles;
	entryLiveness += timer.entryLiveness;
	exitCycles += timer.exitCycles;
	exitLiveness += timer.exitLiveness;
	entryCount += timer.entryCount;
	exitCount += timer.exitCount;
	return *this;
}

void LLVMDynamicExecutive::SubkernelCycleTimer::reset() {
	subkernelCycles = 0;
	entryCycles = 0;
	entryLiveness = 0;
	exitCycles = 0;
	exitLiveness = 0;
	entryCount = 0;
	exitCount = 0;
}

std::ostream &
operator<<(std::ostream &out, LLVMDynamicExecutive::SubkernelCycleTimer &timer) {

	out << "{ subkernelCycles: " << timer.subkernelCycles 
		<< ", entryCycles: " << timer.entryCycles 
		<< ", entryLiveness: " << timer.entryLiveness
		<< ", exitCycles: " << timer.exitCycles
		<< ", exitLiveness: " << timer.exitLiveness
		<< ", entryCount: " << timer.entryCount
		<< "}";
	
	return out;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void LLVMDynamicExecutive::CooperativeThreadArray::initialize(
	const LLVMDynamicKernel &kernel, 
	const ir::Dim3 &ctaId,
	EntryId entry,
	int localMemorySize,
	int sharedMemorySize) {

	const ir::Dim3 gridDim = kernel.gridDim();
	const ir::Dim3 blockDim = kernel.blockDim();
	
	int totalThreads = blockDim.x * blockDim.y * blockDim.z;
		
	report("CTA::initialize() - localMemorySize: " << localMemorySize 
		<< ", total threads: " << totalThreads 
		<< ", shared memory size: " << sharedMemorySize);
		
	local.resize(localMemorySize * totalThreads, 0);
	shared.resize(sharedMemorySize, 0);

#if THREAD_SCHEDULER == SCHEDULER_WARP_LEVEL
	Warp warp;
#endif
	for (int threadId = 0; threadId < totalThreads; threadId++) {
	
		LLVMContext context;
		
		initializeContext(context, threadId, kernel, ctaId, localMemorySize);
		setResumePoint(context, entry);
		
#if THREAD_SCHEDULER == SCHEDULER_THREAD_LEVEL
		readyQueue.push_back(context);
#elif THREAD_SCHEDULER == SCHEDULER_WARP_LEVEL
		warp.threadStatuses[warp.threads.size()] = analysis::KernelPartitioningPass::Thread_entry;
		warp.threads.push_back(context);
		if (warp.threads.size() == api::OcelotConfiguration::get().executive.warpSize) {
			warps.push_back(warp);
		}
		warp.threads.clear();
#endif
	}
#if THREAD_SCHEDULER == SCHEDULER_WARP_LEVEL
	if (warp.threads.size()) {
		warps.push_back(warp);
	}
#endif
}


void LLVMDynamicExecutive::CooperativeThreadArray::initializeContext(
	LLVMContext &context, 
	int threadId,
	const LLVMDynamicKernel &kernel, 
	const ir::Dim3 &ctaId,
	int localMemorySize) {
	
	context.nctaid.x  = kernel.gridDim().x;
	context.nctaid.y  = kernel.gridDim().y;
	context.nctaid.z  = kernel.gridDim().z;
	context.ctaid.x   = ctaId.x;
	context.ctaid.y   = ctaId.y;
	context.ctaid.z   = ctaId.z;
	context.ntid.x    = kernel.blockDim().x;
	context.ntid.y    = kernel.blockDim().y;
	context.ntid.z    = kernel.blockDim().z;
	context.tid.x     = threadId % context.ntid.x;
	context.tid.y     = (threadId / context.ntid.x) % context.ntid.y;
	context.tid.z     = threadId / (context.ntid.x * context.ntid.y);
	context.shared    = reinterpret_cast<char*>(&shared[0]);
	context.argument  = kernel.argumentMemory();
	context.local     = &local[threadId * localMemorySize];
	context.parameter = 0;
	context.constant  = kernel.constantMemory();
	context.metadata  = 0;
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
	
	assert(LLVMDYNAMICEXECUTIVE_MAXIMUM_WARP_SIZE >= api::OcelotConfiguration::get().executive.warpSize);

	yieldOverheadInstrumentation = api::OcelotConfiguration::get().executive.yieldOverheadInstrumentation;
	
#if METRIC_ENTRYPOINT_LIVENESS
	for (analysis::KernelPartitioningPass::KernelTransitionPointMap::const_iterator 
		trans_it = translatedKernel->decomposition.transitionPoints.begin();
		trans_it != translatedKernel->decomposition.transitionPoints.end(); ++trans_it) {
		
		if (trans_it->second.type == analysis::KernelPartitioningPass::Thread_entry) {
			LivenessEntryCounter entry(trans_it->second.liveValues.size());
			livenessEntryCounter[trans_it->second.id] = entry;
		}
	}
#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////


//! \brief computes the CTA ID
unsigned int LLVMDynamicExecutive::ctaId(const ir::Dim3 &ctaId) const {
	return (unsigned int)(kernel->gridDim().x * ctaId.y + ctaId.x);
}


unsigned int LLVMDynamicExecutive::ctaId(const LLVMContext &ctx) const {
	return (unsigned int)(kernel->gridDim().x * ctx.ctaid.y + ctx.ctaid.x);
}

unsigned int LLVMDynamicExecutive::getThreadId(const LLVMContext &ctx) const {
	return (unsigned int)(ctx.tid.x + ctx.tid.y * ctx.ntid.x + ctx.tid.z * ctx.ntid.x * ctx.ntid.y);
}

//! \brief adds a CTA to the dynamic executive's execution list
void LLVMDynamicExecutive::addCta(const ir::Dim3 &blockId) {
	reportE(REPORT_SCHEDULE_OPERATIONS, "addCta() - " << ctaId(blockId));
	
	ctaMap[ctaId(blockId)].initialize(
		*kernel, 
		blockId, 
		translatedKernel->entryId, 
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


//! \brief gets the exit code of a thread
void LLVMDynamicExecutive::setExitCode(const LLVMContext &context, 
	ThreadExitCode status) {
	*((ThreadExitCode *)&context.local[0]) = status;
}

LLVMDynamicExecutive::EntryId LLVMDynamicExecutive::getResumePoint(
	const LLVMContext &context) {
	return *((EntryId *)&context.local[4]);
}

//! \brief sets the resume point of the context
void LLVMDynamicExecutive::setResumePoint(
	const LLVMContext &context, 
	LLVMDynamicExecutive::EntryId entryId) {
	*((EntryId *)&context.local[4]) = entryId;
}

//! \brief gets the initial entry cycle count
size_t LLVMDynamicExecutive::getEntryCycles(const LLVMContext &context) {
	return *((size_t *)&context.local[8]);
}

//! \brief sets the initial entry cycle count
void LLVMDynamicExecutive::setEntryCycles(const LLVMContext &context, size_t cycles) {
	*((size_t *)&context.local[8]) = cycles;
}

//! \brief gets the ID of the most recent exit
unsigned int LLVMDynamicExecutive::getEntryId(const LLVMContext &context) {
	return *((unsigned int *)&context.local[16]);
}

//! \brief gets the liveness count of the most recent exit
unsigned int LLVMDynamicExecutive::getEntryLiveness(const LLVMContext &context) {
	return *((unsigned int *)&context.local[20]);
}

//! \brief sets the initial exit cycle count
size_t LLVMDynamicExecutive::getExitCycles(const LLVMContext &context) {
	return rdtsc() - *((size_t *)&context.local[24]);
}

//! \brief sets the initial exit cycle count
size_t LLVMDynamicExecutive::getExitCycleNumber(const LLVMContext &context) {
	return *((size_t *)&context.local[24]);
}

//! \brief gets the initial entry cycle count
void LLVMDynamicExecutive::setExitCycles(const LLVMContext &context, size_t cycles) {
	*((size_t *)&context.local[24]) = cycles;
}

//! \brief gets the ID of the most recent exit
unsigned int LLVMDynamicExecutive::getExitId(const LLVMContext &context) {
	return *((unsigned int *)&context.local[32]);
}

//! \brief gets the liveness count of the most recent exit
unsigned int LLVMDynamicExecutive::getExitLiveness(const LLVMContext &context) {
	return *((unsigned int *)&context.local[36]);
}

//! \brief gets the start time of the subkernel
size_t LLVMDynamicExecutive::getSubkernelCycles(const LLVMContext &context) {
	return *((size_t *)&context.local[40]);
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
	
#if THREAD_SCHEDULER == SCHEDULER_THREAD_LEVEL
	int waitingThreads = 0;
	int readyThreads = 0;
	
	reportE(REPORT_SCHEDULE_OPERATIONS, "execute()");
	
	do {
		Warp warp;
		testBarriers(waitingThreads, readyThreads);
		
		if (readyThreads) {
			
			// construct a warp
			warpFormation(warp);
		
			// gratuitous debug messaging
			reportE(REPORT_SCHEDULE_OPERATIONS, " formed warp with " << warp.threads.size() << " threads");
			
			// execute a warp
			executeWarpThreadLevel(warp);
			
			// update the warp
			updateWarpThreadLevel(warp);
		}
	} while (waitingThreads || readyThreads);
			
#elif THREAD_SCHEDULER == SCHEDULER_WARP_LEVEL

	reportE(REPORT_SCHEDULE_OPERATIONS, "execute()");
	
	Warp *readyWarp = 0;
	do {
		
		// Warp formation:
		// look for more threads in the current warp
		readyWarp = warpFormationWarpLevel();
		
		if (readyWarp) {
			// Dispatch the warp
			executeWarpWarpLevel(*readyWarp);

			// now examine final state and update accordingly
			updateWarpWarpLevel(*readyWarp);
		}
	} while (readyWarp);
#endif

	if (yieldOverheadInstrumentation) {	
		std::ofstream result("yieldOverheadCycles.json", std::ios_base::app);
		const char *appName = getenv("APP_NAME");
		if (!appName) { appName = "unknown"; }
		
		result << "{ app: \"" << appName << "\", kernel:\"" << kernel->name << "\", cycles: ";
		result << yieldOverheadTimer;
		result << " },\n";
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*! 
	\brief execute a warp
	
*/
void LLVMDynamicExecutive::executeWarpThreadLevel(Warp &warp) {
	
	reportE(REPORT_SCHEDULE_OPERATIONS, "\n\nExecuting warp of size " << warp.size() 
		<< " on hyperblockId " << warp.entryId);

	
	//
	// lazily fetch translation
	//
	const LLVMDynamicTranslationCache::Translation *translation = 
		getOrInsertTranslationById(warp.entryId, warp.size());
	
	assert(translation && "failed to obtain translation");
	reportE(REPORT_SCHEDULE_OPERATIONS, " obtained translation. Executing warp on subkernel " << warp.entryId);
	
	//
	// Update context objects for the translation - hopefully this part isn't the slow part
	//
	unsigned int n = 0;
	for (ThreadContextVector::iterator ctx_it = warp.threads.begin(); 
		ctx_it != warp.threads.end(); 
		++ctx_it) {
		
		ctx_it->metadata = (char *)translation->metadata;
		warp.contextPointers[n++] = (& *ctx_it);
		
		assert(ctx_it->metadata);
	}
	
#if METRIC_ENTRYPOINT_LIVENESS
	livenessEntryCounter[warp.entryId].entries += warp.threads.size();
#endif

	//
	// Execute the warp for all threads
	//
	for (size_t tid = 0; tid < warp.threads.size(); tid += translation->warpSize) {
		if (yieldOverheadInstrumentation) {
			setEntryCycles(*warp.contextPointers[tid], rdtsc());
		}
		
		translation->execute(&warp.contextPointers[tid]);
		
		if (yieldOverheadInstrumentation) {
			size_t subkernelCycles = getExitCycleNumber(*warp.contextPointers[tid]) - 
				getSubkernelCycles(*warp.contextPointers[tid]);
			size_t exitCycles = getExitCycles(*warp.contextPointers[tid]);
			size_t entryCycles = getEntryCycles(*warp.contextPointers[tid]);
			//int exitId = getExitId(*warp.contextPointers[tid]);
			int exitLiveness = getExitLiveness(*warp.contextPointers[tid]);
			int entryLiveness = getEntryLiveness(*warp.contextPointers[tid]);
			
			SubkernelCycleTimer timer(subkernelCycles, entryCycles, entryLiveness, exitCycles, exitLiveness);
			yieldOverheadTimer += timer;
		}
	}
	
#if METRIC_WARPSIZE
	EntryCounter::iterator counter = entryCounter.find((int)warp.threads.size());
	if (counter == entryCounter.end()) {
		entryCounter[(int)warp.threads.size()] = 1;
	}
	else {
		counter->second ++;
	}
#endif
	
}

//! \brief execute a warp
void LLVMDynamicExecutive::executeWarpWarpLevel(Warp & warp) {
	reportE(REPORT_SCHEDULE_OPERATIONS, "\n\nExecuting warp of size " << warp.size() 
		<< " on hyperblockId " << warp.entryId);
	
	//
	// lazily fetch translation
	//
	const LLVMDynamicTranslationCache::Translation *translation = getOrInsertTranslationById(
		warp.entryId, warp.warpSize);
	
	assert(translation && "failed to obtain translation");
	reportE(REPORT_SCHEDULE_OPERATIONS, " obtained translation. Executing warp on subkernel " 
		<< warp.entryId);

	for (int tid = 0; tid < warp.warpSize; tid++) {
		warp.contextPointers[tid]->metadata = (char *)translation->metadata;
	}

	//
	// Execute the warp for all threads
	//
	for (int tid = 0; tid < warp.warpSize; tid += translation->warpSize) {
	
		if (yieldOverheadInstrumentation) {
			setEntryCycles(*warp.contextPointers[tid], rdtsc());
		}
		
		translation->execute(&warp.contextPointers[tid]);
		
		if (yieldOverheadInstrumentation) {
			size_t exitCycles = getExitCycles(*warp.contextPointers[tid]);
			size_t entryCycles = getEntryCycles(*warp.contextPointers[tid]);
			size_t subkernelCycles = getExitCycleNumber(*warp.contextPointers[tid]) - getSubkernelCycles(*warp.contextPointers[tid]);
			//int exitId = getExitId(*warp.contextPointers[tid]);
			int exitLiveness = getExitLiveness(*warp.contextPointers[tid]);
			int entryLiveness = getEntryLiveness(*warp.contextPointers[tid]);
			
			
			SubkernelCycleTimer timer(subkernelCycles, entryCycles, entryLiveness, exitCycles, exitLiveness);
			yieldOverheadTimer += timer;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief execute a warp
void LLVMDynamicExecutive::updateWarpThreadLevel(Warp &warp) {

	for (
		ThreadContextVector::iterator ctx_it = warp.threads.begin(); 
		ctx_it != warp.threads.end(); 
		++ctx_it) {
	
		ThreadExitCode exitCode = getExitCode(*ctx_it);
		unsigned int ctaId = LLVMDynamicExecutive::ctaId(*ctx_it);
		
		reportE(REPORT_SCHEDULE_OPERATIONS, 
			" thread(" << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
			<< ") [cta " << ctaId << "] exited with code " 
			<< analysis::KernelPartitioningPass::toString(exitCode) 
			<< " - resume point: " << getResumePoint(*ctx_it));
		
		assert(ctaMap.find(ctaId) != ctaMap.end() && "CtaID not present in ctaMap");
		
		CooperativeThreadArray & cta = ctaMap[ctaId];
		
		switch (exitCode) {
		case analysis::KernelPartitioningPass::Thread_fallthrough:
			// update its next thread Id
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
					<< " into ready queue of CTA " << ctaId);
			cta.readyQueue.push_back(*ctx_it);
			break;
		case analysis::KernelPartitioningPass::Thread_branch:
			// update its next thread Id
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
					<< " into ready queue of CTA " << ctaId);
			cta.readyQueue.push_back(*ctx_it);
			break;
		case analysis::KernelPartitioningPass::Thread_tailcall:
			// update its next thread Id
			assert(0 && "calls not implemented");
			break;
		case analysis::KernelPartitioningPass::Thread_call:
			// update its next thread Id
			assert(0 && "calls not implemented");
			break;
		case analysis::KernelPartitioningPass::Thread_barrier:
			// update its next thread Id, place into a waiting queue
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z 
					<< " into barrier queue of CTA " << ctaId);
			cta.barrierQueue.push_back(*ctx_it);
			break;
		case analysis::KernelPartitioningPass::Thread_exit:
			// kill off the thread
			break;
		case analysis::KernelPartitioningPass::Thread_exit_other:
			break;
		default: assert(0 && "invalid ThreadExitCode");
			break;
		}
	}
}

//! \brief execute a warp
void LLVMDynamicExecutive::updateWarpWarpLevel(Warp * warp) {
	for (int tid = 0; tid < warp->warpSize; ++tid) {
	
		LLVMContext &context = *warp->contextPointers[tid];
		ThreadExitCode exitCode = getExitCode(context);
		unsigned int ctaId = LLVMDynamicExecutive::ctaId(context);
		
		reportE(REPORT_SCHEDULE_OPERATIONS, 
			" thread(" << context.tid.x << ", " << context.tid.y << ", " << context.tid.z 
			<< ") [cta " << ctaId << "] exited with code " 
			<< analysis::KernelPartitioningPass::toString(exitCode) 
			<< " - resume point: " << getResumePoint(context));
				
		warp->threadStatus[warp->warpBase + tid] = exitCode;
				
#if THREAD_SCHEDULER == SCHEDULER_WARP_LEVEL
		switch (exitCode) {
		case analysis::KernelPartitioningPass::Thread_fallthrough:
			// update its next thread Id
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << context.tid.x << ", " << context.tid.y << ", " << context.tid.z 
					<< " into ready queue of CTA " << ctaId);
			break;
		case analysis::KernelPartitioningPass::Thread_branch:
			// update its next thread Id
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << context.tid.x << ", " << context.tid.y << ", " << context.tid.z 
					<< " into ready queue of CTA " << ctaId);
			break;
		case analysis::KernelPartitioningPass::Thread_tailcall:
			// update its next thread Id
			assert(0 && "calls not implemented");
			break;
		case analysis::KernelPartitioningPass::Thread_call:
			// update its next thread Id
			assert(0 && "calls not implemented");
			break;
		case analysis::KernelPartitioningPass::Thread_barrier:
			// update its next thread Id, place into a waiting queue
			reportE(REPORT_SCHEDULE_OPERATIONS, 
				"inserting thread " << context.tid.x << ", " << context.tid.y << ", " << context.tid.z 
					<< " into barrier queue of CTA " << ctaId);
			activeCta->barrierCount ++;
			break;
		case analysis::KernelPartitioningPass::Thread_exit:
			// kill off the thread
			activeCta->exitCount ++;
			break;
		case analysis::KernelPartitioningPass::Thread_exit_other:
			break;
		default: assert(0 && "invalid ThreadExitCode");
			break;
		}
#endif
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief construct a warp - for now, simply choose a ready thread
void LLVMDynamicExecutive::warpFormation(Warp &warp) {
	const size_t warpSize = api::OcelotConfiguration::get().executive.warpSize;
	bool dynamicWarpFormation = api::OcelotConfiguration::get().executive.dynamicWarpFormation;
	
	warp.threads.resize(0);
	warp.threads.reserve(warpSize);
	
	if (dynamicWarpFormation) {
		for (CooperativeThreadArrayMap::iterator cta_it = ctaMap.begin();
			cta_it != ctaMap.end() && warp.threads.size() < warpSize;
			++cta_it) {
		
			for (ThreadContextQueue::iterator ctx_it = cta_it->second.readyQueue.begin();
				ctx_it != cta_it->second.readyQueue.end() && warp.threads.size() < warpSize;) {
				EntryId entryId = getResumePoint(*ctx_it);
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
	}
	else {
		// statically choose warp<=>thread mapping
		bool earlyExit = true;
		for (CooperativeThreadArrayMap::iterator cta_it = ctaMap.begin();
			cta_it != ctaMap.end() && warp.threads.size() < warpSize && earlyExit;
			++cta_it) {
		
			for (ThreadContextQueue::iterator ctx_it = cta_it->second.readyQueue.begin();
				ctx_it != cta_it->second.readyQueue.end() && warp.threads.size() < warpSize  && earlyExit;) {
				EntryId entryId = getResumePoint(*ctx_it);
				
				reportE(REPORT_SCHEDULE_OPERATIONS, 
					"  ready thread " << getThreadId(*ctx_it) << " for entry " << entryId);
				
				if (!warp.threads.size()) {
					warp.entryId = entryId;
					warp.threads.push_back(*ctx_it);
					ctx_it = cta_it->second.readyQueue.erase(ctx_it);
				}
				else if (entryId == warp.entryId && 
					getThreadId(*ctx_it) == getThreadId(warp.threads.back()) + 1 &&
					ctx_it->tid.y == warp.threads.front().tid.y &&
					ctx_it->tid.z == warp.threads.front().tid.z) {
					warp.threads.push_back(*ctx_it);
					ctx_it = cta_it->second.readyQueue.erase(ctx_it);
				}
				else {
					earlyExit = false;
				}
			}
			if (warp.threads.size()) {
				earlyExit = false;
			}
		}
	}
	
	size_t p = warp.threads.size();
	while (!hydrazine::isPowerOfTwo((unsigned int)p)) {
		LLVMContext & ctx = warp.threads[p - 1];
	
		unsigned int ctaId = LLVMDynamicExecutive::ctaId(ctx);
		ctaMap[ctaId].readyQueue.push_back(ctx);
		--p;
	}
	if (p < warp.threads.size()) {
		warp.threads.resize(p);
	}
	reportE(REPORT_SCHEDULE_OPERATIONS, 
		"formed warp of size " << warp.threads.size() << " with entryId " << warp.entryId);
	
	assert(warp.threads.size() && " failed to choose threads to form warp");

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
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief construct a warp
LLVMDynamicExecutive::Warp *LLVMDynamicExecutive::warpFormationWarpLevel() {
	Warp *warp = 0;
#if THREAD_SCHEDULER == SCHEDULER_WARP_LEVEL
	
	if (activeCta->exitCount == activeCta->blockDim.size()) {
		warp = 0;
		return warp;
	}
	
	// if every thread is at a barrier, fix that
	if (activeCta->barrierCount == activeCta->blockDim.size()) {
		for (WarpVector::iterator warp_it = activeCta->warps.begin();
			warp_it != activeCta->warps.end(); ++warp_it) {
			for (int tid = 0; tid < warpSize; tid++) {
				setExitCode(warp_it->threads[tid], analysis::KernelPartitioningPass::Thread_entry);
			}
			warp_it->warpBase = 0;
		}
		activeCta->barrierCount = 0;
	}
	
	do {
		warp = & cta.warps[cta.warpIndex];
		warp->warpSize = 0;
		int tid = 0;
		for (tid = 0; tid < warpSize; tid++) {
			EntryId entryId = getResumePoint(warp->threads[tid]);
			ThreadExitCode exitStatus = getExitCode(warp->threads[tid]);			
			
			if (exitStatus < analysis::KernelPartitioningPass::Thread_barrier && 
				(!warp->warpSize || warp->entryId == entryId)) {
				warp.contextPointers[warp->warpSize] = &warp->threads[tid];
				warp->warpSize ++;
				warp->entryId = entryId;
			}
		}
		if (!warp->warpSize) {
			warp_it->warpBase = 0;
			activeCta->warpIndex++;
			if (activeCta->warpIndex > activeCta->warps.size()) {
				activeCta->warpIndex = 0;		
			}
		}
		else {
			int nextPowerOfTwo = hydrazine::powerOfTwo(warp->warpSize);
			if (nextPowerOfTwo > warp->warpSize) {
				warp->warpSize = (nextPowerOfTwo >> 1);
			}
		}
	}	while (!warp->warpSize);
	
#endif

	return warp;
}
		
////////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief searches for an existing translation and compiles it if it doesn't exist
const LLVMDynamicTranslationCache::Translation *
LLVMDynamicExecutive::getOrInsertTranslationById(EntryId id, int ws) {

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


//! \brief 
void LLVMDynamicExecutive::subkernelExecutionEvent(size_t subkernelCycles,
	size_t entryCycles, unsigned int entryId, unsigned int entryLiveness, 
	size_t exitCycles, unsigned int exitId, unsigned int exitLiveness) {

	std::ofstream result("yieldOverheadCycles.json", std::ios_base::app);
	
	result << "{ subkernelCycles: " << subkernelCycles << ", entryId: " << entryId << ", entryLiveness: " << entryLiveness 
		<< ", entryCycles: " << entryCycles
		<< ", exitId: " << exitId << ", exitLiveness: " << exitLiveness
		<< ", exitCycles: " << exitCycles << " },\n";
}

}

