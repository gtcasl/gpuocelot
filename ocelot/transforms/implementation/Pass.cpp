/*! \file Pass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday September 15, 2009
	\brief The source file for the Pass class.
*/

#ifndef PASS_CPP_INCLUDED
#define PASS_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/transforms/interface/PassManager.h>
#include <ocelot/transforms/interface/Pass.h>

// Passes
#include <ocelot/transforms/interface/LinearScanRegisterAllocationPass.h>
#include <ocelot/transforms/interface/RemoveBarrierPass.h>
#include <ocelot/transforms/interface/StructuralTransform.h>
#include <ocelot/transforms/interface/ConvertPredicationToSelectPass.h>
#include <ocelot/transforms/interface/SubkernelFormationPass.h>
#include <ocelot/transforms/interface/MIMDThreadSchedulingPass.h>
#include <ocelot/transforms/interface/DeadCodeEliminationPass.h>
#include <ocelot/transforms/interface/SplitBasicBlockPass.h>
#include <ocelot/transforms/interface/SyncEliminationPass.h>
#include <ocelot/transforms/interface/FlattenHyperblockPass.h>
#include <ocelot/transforms/interface/ConvertPredicationToControlFlowPass.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

namespace transforms
{

Pass::Pass(Type t, int a, const std::string& n)
	: type(t), analyses(a), name(n), _manager(0)
{

}

Pass::~Pass()
{

}

void Pass::setPassManager(PassManager* m)
{
	_manager = m;
}

analysis::Analysis* Pass::getAnalysis(Analysis::Type type)
{
	assert(_manager != 0);

	return _manager->getAnalysis(type);
}

const analysis::Analysis* Pass::getAnalysis(Analysis::Type type) const
{
	assert(_manager != 0);

	return _manager->getAnalysis(type);
}

void Pass::invalidateAnalysis(Analysis::Type type)
{
	assert(_manager != 0);

	return _manager->invalidateAnalysis(type);
}

Pass::StringVector Pass::getDependentPasses() const
{
	// return nothing by default
	return StringVector();
}

std::string Pass::toString() const
{
	return name;
}

Pass* Pass::create(const std::string& name)
{
	if(name == "LinearScanRegisterAllocationPass")
	{
		return new LinearScanRegisterAllocationPass;
	}

	if(name == "SubkernelFormationPass")
	{
		return new SubkernelFormationPass;
	}
	
	if(name == "RemoveBarrierPass")
	{
		return new RemoveBarrierPass;
	}

	if(name == "StructuralTransform")
	{
		return new StructuralTransform;
	}

	if(name == "ConvertPredicationToSelectPass")
	{
		return new ConvertPredicationToSelectPass;
	}

	if(name == "MIMDThreadSchedulingPass")
	{
		return new MIMDThreadSchedulingPass;
	}

	if(name == "DeadCodeEliminationPass")
	{
		return new DeadCodeEliminationPass;
	}
	
	if(name == "SplitBasicBlockPass")
	{
		return new SplitBasicBlockPass;
	}
	
	if(name == "SyncEliminationPass")
	{
		return new SyncEliminationPass;
	}
	
	if(name == "FlattenHyperblockPass")
	{
		return new FlattenHyperblockPass;
	}

	if(name == "ConvertPredicationToControlFlowPass")
	{
		return new ConvertPredicationToControlFlowPass;
	}
	
	return 0;
}

ImmutablePass::ImmutablePass(int a, const std::string& n) 
	: Pass(Pass::ImmutablePass, a, n)
{

}

ImmutablePass::~ImmutablePass()
{

}

ModulePass::ModulePass(int a, const std::string& n) 
	: Pass( Pass::ModulePass, a, n)
{

}

ModulePass::~ModulePass()
{

}

KernelPass::KernelPass(int a, const std::string& n)
	: Pass(Pass::KernelPass, a, n)
{

}

KernelPass::~KernelPass()
{

}

ImmutableKernelPass::ImmutableKernelPass(int a, const std::string& n)
	: Pass(Pass::ImmutableKernelPass, a, n)
{

}

ImmutableKernelPass::~ImmutableKernelPass()
{

}

BasicBlockPass::BasicBlockPass(int a, const std::string& n)
	: Pass(Pass::BasicBlockPass, a, n)
{

}

BasicBlockPass::~BasicBlockPass()
{

}

}

#endif

