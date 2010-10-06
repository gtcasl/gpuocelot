/*! \file   LLVMCooperativeThreadArray.cpp
	\date   Monday September 27, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMCooperativeThreadArray class.
*/

#ifndef LLVM_COOPERATIVE_THREAD_ARRAY_CPP_INCLUDED
#define LLVM_COOPERATIVE_THREAD_ARRAY_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/executive/interface/LLVMCooperativeThreadArray.h>
#include <ocelot/executive/interface/LLVMModuleManager.h>
#include <ocelot/executive/interface/LLVMExecutableKernel.h>

#include <ocelot/executive/implementation/LLVMRuntimeLibrary.inl>

#include <ocelot/api/interface/OcelotConfiguration.h>

#include <ocelot/ir/interface/Module.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace executive
{

////////////////////////////////////////////////////////////////////////////////
// Helper Functions
static unsigned int threadId(LLVMContext& context)
{
	return context.tid.x + context.tid.y * context.ntid.x
		+ context.tid.z * context.ntid.y * context.ntid.z;
}
////////////////////////////////////////////////////////////////////////////////

LLVMCooperativeThreadArray::LLVMCooperativeThreadArray(LLVMWorkerThread* w) :
	_warpSize(std::max(api::OcelotConfiguration::get().executive.warpSize, 4)),
	_worker(w)
{

}

void LLVMCooperativeThreadArray::setup(const LLVMExecutableKernel& kernel)
{
	report("Setting up LLVM-CTA to execute kernel " << kernel.name);
	_functions.resize(LLVMModuleManager::totalFunctionCount(), 0);
	_queuedThreads.resize(_functions.size());

	_nextFunction = _worker->getFunctionId(kernel.module->path(), kernel.name);
	report(" Entry point is function " << _nextFunction);

	if(_functions[_nextFunction] == 0)
	{
		report("  Loading entry point into cache.");
		_functions[_nextFunction] = _worker->getFunctionMetaData(_nextFunction);
		_functionBase = _nextFunction;
	}

	const unsigned int threads = kernel.blockDim().x *
		kernel.blockDim().y * kernel.blockDim().z;
	report(" Creating contexts for " << threads << " threads.");

	_contexts.resize(threads);
	_stacks.resize(threads);
	_sharedMemory.resize(kernel.totalSharedMemorySize());
	_kernel = &kernel;

	_freeContexts.resize(threads);
	for(ThreadList::iterator context = _freeContexts.begin();
		context != _freeContexts.end(); ++context)
	{
		*context = std::distance(_freeContexts.begin(), context);
	}
}

/* We want to execute the CTA as quickly as possibly. Speed is the only 
	concern here, but it requires careful thread scheduling and state 
	management to maximize the opportunities for locality and vector 
	execution. The current algorithm is as follows:
	
	Always issue threads with the widest vector width available.
	
	1) Start by launching threads in order, if they finish before exiting 
		the subkernel, then they die here and their state is reclaimed.  If they
		bail out due to divergence or hit a context switch point, then allocate
		a new thread context for the next thread and save the current thread
		context's id for scheduling in a queue for the next subkernel.  
	2) Sort the queues by thread count.  Pick the queue with the most waiting
		threads.
		a) If it has not been jitted yet, do so now.
		b) Group threads together into warps of fused kernel width 
			(possibly by sorting but FCFS should require less overhead).  
			Launch them all.
		c) If a thread exits, kill it and reclaim the state, otherwise move 
			it to another queue.
		d) If a thread hits a barrier, put it into a barrier queue.
		d) Once all threads have been launched we are done with this sub-kernel.
	3) Reorganize the threads
		a) If all threads are in the barrier queue, move them back into their
			correspoding queues.
		b) If there is at least one thread left in at least one queue, goto 2.
		c) If all threads are finished, the CTA is done.

*/
void LLVMCooperativeThreadArray::executeCta(unsigned int id)
{
	report("Executing LLVM-CTA " << id);
	const unsigned int threads  = _contexts.size();

	const unsigned int warps   = threads / _warpSize;
	const unsigned int remains = threads % _warpSize;

	report(" warp size:        " << _warpSize);
	report(" full warps:       " << warps);
	report(" remaining threas: " << remains);

	ThreadList warpList;

	unsigned int threadId = 0;

	for(unsigned int warp = 0; warp < warps; ++warp)
	{
		for(unsigned int thread = 0; thread != _warpSize; ++thread)
		{
			warpList.push_back(_initializeNewContext(threadId++, id));
		}
		
		_executeWarp(warpList.begin(), warpList.end());
		
		for(ThreadList::const_iterator context = warpList.begin();
			context != warpList.end(); ++context)
		{
			_reclaimContext(*context);
		}
		warpList.clear();
	}
	
	for(unsigned int thread = 0; thread != remains; ++thread)
	{
		warpList.push_back(_initializeNewContext(threadId++, id));
	}
	
	_executeWarp(warpList.begin(), warpList.end());
	
	for(ThreadList::const_iterator context = warpList.begin();
		context != warpList.end(); ++context)
	{
		_reclaimContext(*context);
	}
	warpList.clear();
	
	while(_freeContexts.size() != threads)
	{
		_computeNextFunction();
		
		warpList = std::move(_queuedThreads[_nextFunction]);
		
		const unsigned int threads = warpList.size();
		const unsigned int warps   = threads / _warpSize;
		const unsigned int remains = threads % _warpSize;

		report("Next sub-kernel is " << _nextFunction);

		report(" threads:          " << threads);
		report(" full warps:       " << warps);
		report(" remaining threas: " << remains);
		
		ThreadList::const_iterator begin = warpList.begin();

		for(unsigned int warp = 0; warp != warps; ++warp)
		{
			ThreadList::const_iterator end = begin;
			std::advance(end, _warpSize);
			_executeWarp(begin, end);
			begin = end;
		}
	
		ThreadList::const_iterator end = begin;
		std::advance(end, remains);
		_executeWarp(begin, end);
		
		for(ThreadList::const_iterator context = warpList.begin();
			context != warpList.end(); ++context)
		{
			_destroyContext(*context);
		}
		warpList.clear();
	}
	
	_destroyContexts();
}

void LLVMCooperativeThreadArray::flushTranslatedKernels()
{
	_functions.clear();
}

void LLVMCooperativeThreadArray::_executeThread(unsigned int contextId)
{
	LLVMContext& context = _contexts[contextId];
	LLVMModuleManager::MetaData* metadata = _functions[_nextFunction];
	context.metadata = (char*) metadata;
	
	report("   executing thread " << threadId(context) 
		<< " in context " << contextId);
	
	metadata->function(&context);
}

void LLVMCooperativeThreadArray::_executeWarp(ThreadList::const_iterator begin,
	ThreadList::const_iterator end)
{
	report("  executing warp");
	// this is a stupid implementation of a warp that just loops over threads
	for(ThreadList::const_iterator i = begin; i != end; ++i)
	{
		_executeThread(*i);
	}
}

unsigned int LLVMCooperativeThreadArray::_initializeNewContext(
	unsigned int threadId, unsigned int ctaId)
{
	unsigned int contextId = 0;

	if(_reclaimedContexts.empty())
	{
		contextId = _freeContexts.back();
		_freeContexts.pop_back();
	
		LLVMContext& context                  = _contexts[contextId];
		LLVMFunctionCallStack& stack          = _stacks[contextId];
		LLVMModuleManager::MetaData& metadata = *_functions[_nextFunction];
		
		stack.call(metadata.localSize, metadata.parameterSize);

		context.nctaid.x  = _kernel->gridDim().x;
		context.nctaid.y  = _kernel->gridDim().y;
		context.nctaid.z  = _kernel->gridDim().z;
		context.ctaid.x   = ctaId % _kernel->gridDim().x;
		context.ctaid.y   = ctaId / _kernel->gridDim().y;
		context.ctaid.z   = 0;
		context.ntid.x    = _kernel->blockDim().x;
		context.ntid.y    = _kernel->blockDim().y;
		context.ntid.z    = _kernel->blockDim().z;
		context.tid.x     = threadId % context.nctaid.x;
		context.tid.y     = (threadId / context.nctaid.x) % context.nctaid.y;
		context.tid.z     = threadId / (context.nctaid.x * context.nctaid.y);
		context.shared    = reinterpret_cast<char*>(_sharedMemory.data());
		context.argument  = _kernel->argumentMemory();
		context.local     = stack.localMemory();
		context.parameter = stack.parameterMemory();
		context.constant  = _kernel->constantMemory();
	}
	else
	{
		contextId = _reclaimedContexts.back();
		_reclaimedContexts.pop_back();
	
		LLVMContext& context = _contexts[contextId];
	
		context.tid.x = threadId % context.nctaid.x;
		context.tid.y = (threadId / context.nctaid.x) % context.nctaid.y;
		context.tid.z = threadId / (context.nctaid.x * context.nctaid.y);
	}	
	
	return contextId;
}

void LLVMCooperativeThreadArray::_computeNextFunction()
{
	if(_queuedThreads[0].size() == _contexts.size())
	{
		_nextFunction = 0;
	}
	else if(_queuedThreads[_guessFunction].size() >= _contexts.size()/2)
	{
		_nextFunction = _guessFunction;
	}
	else
	{
		_nextFunction        = 1;
		unsigned int total   = 0;
		unsigned int count   = _queuedThreads[1].size();
		
		ThreadListVector::iterator queue = _queuedThreads.begin();
		
		for(std::advance(queue, 2); queue != _queuedThreads.end(); ++queue)
		{
			if(queue->size() > count)
			{
				_nextFunction = std::distance(_queuedThreads.begin(), queue);
				count = queue->size();
			}
			
			total += queue->size();
			if(total > _contexts.size() / 2) break;
		}
	}

	// Possibly lazily compile the function
	if(_functions[_nextFunction] == 0)
	{
		_functions[_nextFunction] = _worker->getFunctionMetaData(_nextFunction);
	}
	
	assert(!_queuedThreads[_nextFunction].empty());
}

void LLVMCooperativeThreadArray::_reclaimContext(unsigned int contextId)
{
	if(_finishContext(contextId))
	{
		_reclaimedContexts.push_back(contextId);
	}
}

void LLVMCooperativeThreadArray::_destroyContext(unsigned int contextId)
{
	if(_finishContext(contextId))
	{
		_freeContexts.push_back(contextId);
	}
}

bool LLVMCooperativeThreadArray::_finishContext(unsigned int contextId)
{
	LLVMContext& context         = _contexts[contextId];
	LLVMFunctionCallStack& stack = _stacks[contextId];

	unsigned int* localMemory = reinterpret_cast<unsigned int*>(context.local);
	
	unsigned int nextFunction = localMemory[0];
	
	report("   thread context " << contextId  << " finished.");
	
	if(nextFunction == (unsigned int)-1)
	{
		report("    hit program exit point, destroying context.");
		return true;
	}
	
	nextFunction += _functionBase;
	
	_guessFunction = nextFunction;

	_queuedThreads[nextFunction].push_back(contextId);

	if(nextFunction == 0)
	{
		return false;
	}

	unsigned int callType = localMemory[1];
	switch(callType)
	{
	case LLVMExecutableKernel::TailCall:
	{
		// nothing happens here, we reuse the existing stack
		report("     hit tail call, saving thread context at resume point "
			<< nextFunction << ".");
	}
	break;
	case LLVMExecutableKernel::NormalCall:
	{
		stack.call(localMemory[2], localMemory[3]);
		context.local = stack.localMemory();
		report("     hit function call, saving thread context at resume point "
			<< nextFunction << ", pushing stack.");
	}
	break;
	case LLVMExecutableKernel::ReturnCall:
	{
		stack.returned();
		context.local = stack.localMemory();
		report("     hit return, saving thread context at resume point "
			<< nextFunction << ", popping stack.");
	}
	break;
	}
	
	return false;
}

void LLVMCooperativeThreadArray::_destroyContexts()
{
	_freeContexts.insert(_freeContexts.end(), _reclaimedContexts.begin(), 
		_reclaimedContexts.end());

	_reclaimedContexts.clear();
}

}

#endif

