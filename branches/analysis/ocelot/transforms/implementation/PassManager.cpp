/*! \file PassManager.cpp
	\date Thursday September 16, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the PassManager class
*/

#ifndef PASS_MANAGER_CPP_INCLUDED
#define PASS_MANAGER_CPP_INCLUDED

//! Ocelot Includes
#include <ocelot/transforms/interface/PassManager.h>
#include <ocelot/transforms/interface/Pass.h>

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/DivergenceAnalysis.h>
#include <ocelot/analysis/interface/ControlTree.h>
#include <ocelot/analysis/interface/DominatorTree.h>
#include <ocelot/analysis/interface/PostdominatorTree.h>

#include <ocelot/ir/interface/IRKernel.h>
#include <ocelot/ir/interface/Module.h>

//! Hydrazine Includes
#include <hydrazine/implementation/debug.h>

//! Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace transforms
{

static void freeUnusedDataStructures(PassManager::AnalysisMap& analyses,
	ir::IRKernel* k, int type)
{
	typedef std::vector<int> TypeVector;
	
	TypeVector types = {analysis::Analysis::DivergenceAnalysis,
		analysis::Analysis::DataflowGraphAnalysis,
		analysis::Analysis::PostDominatorTreeAnalysis,
		analysis::Analysis::DominatorTreeAnalysis,
		analysis::Analysis::ControlTreeAnalysis};
	
	for(TypeVector::const_iterator t = types.begin(); t != types.end(); ++t)
	{
		if(type < *t)
		{
			PassManager::AnalysisMap::iterator structure = analyses.find(*t);
			
			if(structure != analyses.end())
			{
				report("Destroying " << structure->second->name
					<< " for kernel" << k->name);
				delete structure->second;
				analyses.erase(structure);
			}
		}
	}
}

static void allocateNewDataStructures(PassManager::AnalysisMap& analyses,
	ir::IRKernel* k, int type)
{
	if(type & analysis::Analysis::ControlTreeAnalysis)
	{
		if(analyses.count(analysis::Analysis::ControlTreeAnalysis) == 0)
		{
			report("Allocating control tree for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::ControlTreeAnalysis,
				new analysis::ControlTree(k->cfg())));
		}
	}
	if(type & analysis::Analysis::DominatorTreeAnalysis)
	{
		if(analyses.count(analysis::Analysis::DominatorTreeAnalysis) == 0)
		{
			report("Allocating dominator tree for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::DominatorTreeAnalysis,
				new analysis::DominatorTree(k->cfg())));
		}
	}
	if(type & analysis::Analysis::PostDominatorTreeAnalysis)
	{
		if(analyses.count(analysis::Analysis::PostDominatorTreeAnalysis) == 0)
		{
			report("Allocating post-dominator tree for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::PostDominatorTreeAnalysis,
				new analysis::PostdominatorTree(k->cfg())));
		}
	}
	if(type & analysis::Analysis::DataflowGraphAnalysis)
	{
		PassManager::AnalysisMap::iterator dom = analyses.find(
			analysis::Analysis::DataFlowGraphAnalysis);
		
		if(analyses.end() == dom)
		{
			report("Allocating dataflow graph for kernel " << k->name);
			dom = analyses.insert(std::make_pair(
				analysis::Analysis::DataflowGraph,
				new analysis::DataflowGraph(k->cfg()))).first;
		}
		if(type & analysis::Analysis::StaticSingleAssignment)
		{
			report("Converting DFG into SSA for " << k->name);
			static_cast<analysis::DataflowGraph*>(dom->second)->toSsa();
		}
	}
	if(type & analysis::Analysis::DivergenceAnalysis)
	{
		if(analyses.count(analysis::Analysis::DivergenceAnalysis) == 0)
		{
			report("Allocating divergence analysis for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::DivergenceAnalysis,
				new analysis::DivergenceAnalysis(*k)));
		}
	}
}

static void runKernelPass(ir::IRKernel* kernel, Pass* pass)
{
	report("  Running pass '" << pass->toString() << "' on kernel '"
		<< kernel->name << "'" );
	switch(pass->type)
	{
	case Pass::ImmutablePass:
	{
		assertM(false, "Immutable passes cannot be run on single kernels.");
	}
	break;
	case Pass::ModulePass:
	{
		assertM(false, "Module passes cannot be run on single kernels.");
	}
	break;
	case Pass::KernelPass:
	{
		KernelPass* kernelPass = static_cast<KernelPass*>(pass);
		kernelPass->runOnKernel(*kernel);
	}
	break;
	case Pass::BasicBlockPass:
	{
		BasicBlockPass* bbPass = static_cast<BasicBlockPass*>(pass);
		bbPass->initialize(*kernel);
		for(ir::ControlFlowGraph::iterator 
			block = kernel->cfg()->begin(); 
			block != kernel->cfg()->end(); ++block)
		{
			bbPass->runOnBlock(*block);
		}
		bbPass->finalizeKernel();
	}
	break;
	case Pass::InvalidPass: assertM(false, "Invalid pass type.");
	}
}

static void runKernelPass(ir::Module* module, ir::IRKernel* kernel, Pass* pass)
{
	switch(pass->type)
	{
	case Pass::ImmutablePass: /* fall through */
	case Pass::ModulePass:
	break;
	case Pass::KernelPass:
	{
		report("  Running kernel pass '" << pass->toString() << "' on kernel '"
			<< kernel->name << "'" );
		KernelPass* kernelPass = static_cast<KernelPass*>(pass);
		kernelPass->runOnKernel(*kernel);
	}
	break;
	case Pass::BasicBlockPass:
	{
		report("  Running basic block pass '" << pass->toString() 
			<< "' on kernel '" << kernel->name << "'" );
		BasicBlockPass* bbPass = static_cast<BasicBlockPass*>(pass);
		bbPass->initialize(*kernel);
		for(ir::ControlFlowGraph::iterator 
			block = kernel->cfg()->begin(); 
			block != kernel->cfg()->end(); ++block)
		{
			bbPass->runOnBlock( *block );
		}
		bbPass->finalizeKernel();
	}
	break;
	case Pass::InvalidPass: assertM(false, "Invalid pass type.");
	}
}

static void initializeKernelPass(ir::Module* module, Pass* pass)
{
	switch(pass->type)
	{
	case Pass::ImmutablePass: /* fall through */
	case Pass::ModulePass:
	break;
	case Pass::KernelPass:
	{
		report("  Initializing kernel pass '" << pass->toString() << "'" );
		KernelPass* kernelPass = static_cast<KernelPass*>(pass);
		kernelPass->initialize(*module);
	}
	break;
	case Pass::BasicBlockPass:
	{
		report("  Initializing basic block pass '" << pass->toString() << "'" );
		BasicBlockPass* bbPass = static_cast<BasicBlockPass*>(pass);
		bbPass->initialize(*module);
	}
	break;
	case Pass::InvalidPass: assertM(false, "Invalid pass type.");
	}
}

static void finalizeKernelPass(ir::Module* module, Pass* pass)
{
	switch(pass->type)
	{
	case Pass::ImmutablePass: /* fall through */
	case Pass::ModulePass:
	break;
	case Pass::KernelPass:
	{
		report("  Finalizing kernel pass '" << pass->toString() << "'" );
		KernelPass* kernelPass = static_cast<KernelPass*>(pass);
		kernelPass->finalize();
	}
	break;
	case Pass::BasicBlockPass:
	{
		report("  Finalizing basic block pass '" << pass->toString() << "'" );
		BasicBlockPass* bbPass = static_cast<BasicBlockPass*>(pass);
		bbPass->finalize();
	}
	break;
	case Pass::InvalidPass: assertM(false, "Invalid pass type.");
	}
}

static void runModulePass(ir::Module* module, Pass* pass)
{
	report("  Running module pass '" << pass->toString() << "'" );
	switch(pass->type)
	{
	case Pass::ImmutablePass:
	{
		ImmutablePass* immutablePass = static_cast<ImmutablePass*>(pass);
		immutablePass->runOnModule(*module);
	}
	break;
	case Pass::ModulePass:
	{
		ModulePass* modulePass = static_cast<ModulePass*>(pass);
		modulePass->runOnModule(*module);
	}
	break;
	case Pass::KernelPass: /* fall through */
	case Pass::BasicBlockPass:
	break;
	case Pass::InvalidPass: assertM(false, "Invalid pass type.");
	}
}

PassManager::PassManager(ir::Module* module) :
	_module(module)
{
	assert(_module != 0);
}

void PassManager::addPass(Pass& pass)
{
	report("Adding pass '" << pass.toString() << "'");
	_passes.insert(std::make_pair(pass.analyses, &pass));
}

void PassManager::clear()
{
	_passes.clear();
}

void PassManager::destroyPasses()
{
	for(PassMap::iterator pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		delete pass->second;
	}
}

void PassManager::runOnKernel(const std::string& name)
{
	_module->loadNow();
	
	ir::IRKernel* kernel = dynamic_cast<ir::IRKernel*>(
		_module->getKernel(name));

	for(PassMap::iterator pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		initializeKernelPass(_module, pass->second);
	}
	
	for(PassMap::iterator pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		freeUnusedDataStructures(_analyses, kernel, pass->first);
		allocateNewDataStructures(_analyses, kernel, pass->first);
		
		runKernelPass(kernel, pass->second);
	}

	freeUnusedDataStructures(_analyses, kernel, analysis::Analysis::NoAnalysis);

	for(PassMap::iterator pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		finalizeKernelPass(_module, pass->second);
	}
}

void PassManager::runOnModule()
{
	_module->loadNow();
	
	// Run all module passes first
	for(PassMap::iterator pass = _passes.begin();
		pass != _passes.end(); ++pass)
	{
		if(pass->second->type == Pass::KernelPass) continue;
		if(pass->second->type == Pass::BasicBlockPass) continue;
		
		for(ir::Module::KernelMap::const_iterator 
			kernel = _module->kernels().begin();
			kernel != _module->kernels().end(); ++kernel)
		{
			allocateNewDataStructures(_analyses, kernel->second, pass->first);
		}
		
		runModulePass(_module, pass->second);
	}
	
	// Run all kernel and bb passes
	for(ir::Module::KernelMap::const_iterator 
		kernel = _module->kernels().begin();
		kernel != _module->kernels().end(); ++kernel)
	{
		for(PassMap::iterator pass = _passes.begin();
			pass != _passes.end(); ++pass)
		{
			initializeKernelPass(_module, pass->second);
		}
		
		for(PassMap::iterator pass = _passes.begin();
			pass != _passes.end(); ++pass)
		{
			if(pass->second->type == Pass::ImmutablePass) continue;
			if(pass->second->type == Pass::ModulePass) continue;

			freeUnusedDataStructures(_analyses, kernel->second, pass->first);
			allocateNewDataStructures(_analyses, kernel->second, pass->first);
		
			runKernelPass(_module, kernel->second, pass->second);
		}

		freeUnusedDataStructures(_analyses, kernel->second,
			analysis::Analysis::NoAnalysis);

		for(PassMap::iterator pass = _passes.begin();
			pass != _passes.end(); ++pass)
		{
			finalizeKernelPass(_module, pass->second);
		}
	}
}

}

#endif

