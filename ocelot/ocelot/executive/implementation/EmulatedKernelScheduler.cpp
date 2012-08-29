/*	\file   EmulatedKernelScheduler.cpp
	\date   Friday July 6, 2012
	\author Gregory Diamos <gdiamos@nvidia.com>
	\brief  The source file for the EmulatedKernelScheduler class.
*/

// Ocelot Includes
#include <ocelot/executive/interface/EmulatedKernelScheduler.h>
#include <ocelot/executive/interface/EmulatedKernel.h>

// Hydrazine Includes
#include <hydrazine/interface/debug.h>

// Preprocessor Macros

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0 

namespace executive
{

EmulatedKernelScheduler::EmulatedKernelScheduler(EmulatorDevice* owningDevice)
: _device(owningDevice)
{

}

void EmulatedKernelScheduler::launch(EmulatedKernel* kernel,
	const ir::Dim3& dimensions,
	ExecutableKernel::TraceGeneratorVector* generators)
{
	report("Launching kernel " << kernel->name << " over grid (" << dimensions.x
		<< ", " << dimensions.y << ", " << dimensions.z << ")");
	
	kernel->scheduler = this;
	_generators = generators;
	
	auto context = _contexts.insert(_contexts.end(),
		Context(kernel, dimensions, kernel->blockDim(), _contexts.end(),
		this, 0));
	
	_executingContexts.insert(std::make_pair(context->priority, context));

	_scheduler();

	kernel->scheduler = 0;
}

void EmulatedKernelScheduler::launch(ir::PTXU64 pc, ir::PTXU64 parameterBuffer,
	const ir::Dim3& gridDim, const ir::Dim3& ctaDim, ir::PTXU32 sharedMemory,
	ir::PTXU64 stream)
{
	auto kernel = _getKernelAtPC(pc);

	report(" Launching nested kernel " << kernel->name << " over grid ("
		<< gridDim.x << ", " << gridDim.y << ", " << gridDim.z
		<< ") at PC " << pc);
	
	auto context = _contexts.insert(_contexts.end(), Context(kernel, pc, gridDim,
		ctaDim, (const void*) parameterBuffer, kernel->argumentMemorySize(),
		_getExecutingContext(), this, _getExecutingContext()->priority + 1));

	_executingContexts.insert(std::make_pair(context->priority, context));
}

ir::PTXU64 EmulatedKernelScheduler::argumentMemory() const
{
	return (ir::PTXU64)_getExecutingContext()->argumentMemory.data();
}

void EmulatedKernelScheduler::_scheduler()
{
	while(!_executingContexts.empty())
	{
		// Highest priority context
		auto contextIterator = _executingContexts.begin();
		auto context         = contextIterator->second;

		context->executeUntilYield();

		_executingContexts.erase(contextIterator);
			
		if(context->exited())
		{
			bool hasParent = context->hasParent();

			if(hasParent)
			{
				auto parent     = context->parent;
				bool wasBlocked = parent->blockedOnChildren();

				auto child = std::find(parent->children.begin(),
					parent->children.end(), context);
				assert(child != parent->children.end());
				
				parent->children.erase(child);
				
				if(wasBlocked && !parent->blockedOnChildren())
				{
					_executingContexts.insert(std::make_pair(
						parent->priority, parent));
				}
			}

			_contexts.erase(context);
		}
	}
}

EmulatedKernelScheduler::Context::iterator
	EmulatedKernelScheduler::_getExecutingContext() const
{
	assert(!_executingContexts.empty());
	return _executingContexts.begin()->second;
}

const EmulatedKernel* EmulatedKernelScheduler::_getKernelAtPC(
	unsigned int pc) const
{
	return _getExecutingContext()->kernel->getKernel(pc);
}

EmulatedKernelScheduler::Context::Context(EmulatedKernel* k,
	const ir::Dim3& g, const ir::Dim3& c, iterator p,
	EmulatedKernelScheduler* s, Priority pr)
: kernel(k), startingPC(0), gridDimensions(g), argumentMemory(k->ArgumentMemory,
		k->ArgumentMemory + k->argumentMemorySize()),
	 parent(p), priority(pr),  _scheduler(s),
	_cta(new CooperativeThreadArray(k, g, c, k->argumentMemorySize(),
		k->parameterMemorySize(), k->registerCount(), k->localMemorySize(),
		k->globalLocalMemorySize(), k->totalSharedMemorySize(),
		s->_generators)),
	_positionInGrid(ir::Dim3(0, 0, 0))
{
	
}
		
EmulatedKernelScheduler::Context::Context(const EmulatedKernel* k,
	uint64_t pc, const ir::Dim3& g, const ir::Dim3& c, const void* d,
	size_t size, iterator p, EmulatedKernelScheduler* s, Priority pr)
: kernel(p->kernel), startingPC(pc), gridDimensions(g),
	argumentMemory((uint8_t*)d, (uint8_t*)d + size), parent(p),
	priority(pr), _scheduler(s),
	_cta(new CooperativeThreadArray(p->kernel, g, c, k->argumentMemorySize(),
		k->parameterMemorySize(), k->registerCount(), k->localMemorySize(),
		k->globalLocalMemorySize(), k->totalSharedMemorySize(),
		s->_generators)),
	_positionInGrid(ir::Dim3(0, 0, 0))
{

}

void EmulatedKernelScheduler::Context::executeUntilYield()
{
	kernel->setCTA(_cta);

	ir::Dim3 grid          = gridDimensions;
	ir::Dim3 startingPoint = _positionInGrid;	

	for(int z = startingPoint.z; z < grid.z; ++z)
	{
		for(int y = startingPoint.y; y < grid.y; ++y)
		{
			for(int x = startingPoint.x; x < grid.x; ++x)
			{
				report("  cta: " << x << ", " << y << ", " << z);	
				_cta->execute(ir::Dim3(x, y, z), startingPC);
				
				CTAContext::ExecutionState state = _cta->getExecutionState();

				if(state != CTAContext::Exit)
				{
					assert(state != CTAContext::Running);

					if(state == CTAContext::Barrier)
					{
						_positionInGrid = ir::Dim3(x, y, z);
						
						_yieldBarrier();

						return;
					}
					else
					{
						assertM(false, "Not implemented.");
					}
				}
			}
		}
	}

	_yieldExit();
}

bool EmulatedKernelScheduler::Context::exited() const
{
	return _cta == 0;
}

bool EmulatedKernelScheduler::Context::hasParent() const
{
	return parent != _scheduler->_contexts.end();
}

bool EmulatedKernelScheduler::Context::blockedOnChildren() const
{
	return !exited() && !children.empty();
}
		
void EmulatedKernelScheduler::Context::_yieldExit()
{
	delete _cta;
	kernel->setCTA(0);
}

void EmulatedKernelScheduler::Context::_yieldBarrier()
{
	kernel->setCTA(0);
}

}


