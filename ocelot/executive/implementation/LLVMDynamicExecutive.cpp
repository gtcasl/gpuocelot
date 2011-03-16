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

std::string LLVMDynamicExecutive::Metadata::toString(const ThreadExitCode &code) {
	switch (code) {
	case Thread_fallthrough: return "fallthrough";
	case Thread_branch: return "branch";
	case Thread_tailcall: return "tailcall";
	case Thread_call: return "call";
	case Thread_barrier: return "barrier";
	case Thread_exit: return "exit";
	case Thread_exit_other: return "other";
	case ThreadExitCode_invalid: break;
	default: break;
	}
	return "invalid";
}


LLVMDynamicExecutive::Metadata::Metadata() {

}

LLVMDynamicExecutive::Metadata::~Metadata() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

LLVMDynamicExecutive::LLVMDynamicExecutive(
	const LLVMDynamicKernel *_kernel, 
	int procID)
:
	kernel(_kernel),
	processor(procID)
{

}


/////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief adds a CTA to the dynamic executive's execution list
void LLVMDynamicExecutive::addCta(const ir::Dim3 &blockId) {
	int totalThreads = kernel->blockDim().size();
	int ctaId = 0; //kernel->gridDim().x * kernel->blockIdx().y + kernel->blockIdx().x;
	for (int tid = 0; tid < totalThreads; ++tid) {
		LLVMContext context;
		
		// TODO: initialize context
		
		readyQueue[ctaId].push_back(context);
	}
	waitingQueue[ctaId].clear();
}


//! \brief destroy a context before it is removed
void LLVMDynamicExecutive::finishContext(LLVMContext &context) {

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
	
	do {
		Warp warp;
		
		// test barriers
		testBarriers(waitingThreads, readyThreads);
		if (readyThreads) {
			// construct a warp
			warpFormation(warp);
		
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
		LLVMDynamicExecutionManager::get().getOrInsertTranslationById(warp.entryId, warp.size());
	
	assert(translation && "failed to obtain translation");
	report(" obtained translation. Executing warp.");
	
	translation->execute(&warp.threads[0]);
	
	report(" warp execution completed.");
	for (
		ThreadContextVector::iterator ctx_it = warp.threads.begin(); 
		ctx_it != warp.threads.end(); 
		++ctx_it) {
	
		Metadata::ThreadExitCode exitCode = Metadata::ThreadExitCode_invalid;
		report(" thread(" << ctx_it->tid.x << ", " << ctx_it->tid.y << ", " << ctx_it->tid.z << ") [cta ] exited with code " 
			<< Metadata::toString(exitCode));
		
		switch (exitCode) {
		case Metadata::Thread_fallthrough:
			// update its next thread Id
			break;
		case Metadata::Thread_branch:
			// update its next thread Id
			break;
		case Metadata::Thread_tailcall:
			// update its next thread Id
			break;
		case Metadata::Thread_call:
			// update its next thread Id
			break;
		case Metadata::Thread_barrier:
			// update its next thread Id, place into a waiting queue
			break;
		case Metadata::Thread_exit:
			// kill off the thread
			break;
		case Metadata::Thread_exit_other:
			break;
		default: assert(0 && "invalid ThreadExitCode");
			break;
		}
		assert("unimplemented" && 0);
	}
}

//! \brief construct a warp - for now, simply choose a ready thread
void LLVMDynamicExecutive::warpFormation(Warp &warp) {
	warp.threads.resize(1);
	for (CtaThreadQueue::iterator cta_it = readyQueue.begin(); cta_it != readyQueue.end(); ++cta_it) {
		if (cta_it->second.size()) {
			warp.threads[0] = cta_it->second.front();
			cta_it->second.pop_front();
		}
	}
}

//! \brief determine if any barriers have been reached
void LLVMDynamicExecutive::testBarriers(int &waiting, int &ready) {
	ready = waiting = 0;
	for (CtaThreadQueue::iterator cta_it = readyQueue.begin(); cta_it != readyQueue.end(); ++cta_it) {
		CtaThreadQueue::iterator waiting_it = waitingQueue.find(cta_it->first);
		assert(waiting_it != waitingQueue.end());
		
		if (!cta_it->second.size()) {
			cta_it->second = waiting_it->second;
			waiting_it->second.clear();
		}
		ready += (int)cta_it->second.size();
		waiting += (int)waiting_it->second.size();
	}
}

}

