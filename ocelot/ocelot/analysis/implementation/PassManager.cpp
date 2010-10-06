/*! \file PassManager.cpp
	\date Thursday September 16, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the PassManager class
*/

#ifndef PASS_MANAGER_CPP_INCLUDED
#define PASS_MANAGER_CPP_INCLUDED

//! Ocelot Includes
#include <ocelot/analysis/interface/PassManager.h>
#include <ocelot/analysis/interface/Pass.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/ir/interface/Module.h>

//! Hydrazine Includes
#include <hydrazine/implementation/debug.h>

//! Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{

static void freeUnusedDataStructures(ir::Kernel* k, int type)
{
	if(type < Pass::StaticSingleAssignment)
	{
		if(k->dfg()->ssa())
		{
			report("Converting out of SSA form for kernel " << k->name);
			k->dfg()->fromSsa();
		}
	}
	if(type < Pass::DataflowGraphAnalysis)
	{
		report("Destroying dataflow graph for kernel " << k->name);
		k->clear_dfg();
	}
	if(type < Pass::PostDominatorTreeAnalysis)
	{
		report("Destroying post-dominator tree for kernel " << k->name);
		k->clear_pdom_tree();
	}
	if(type < Pass::DominatorTreeAnalysis)
	{
		report("Destroying dominator tree for kernel " << k->name);
		k->clear_dom_tree();
	}
	if(type < Pass::ControlTreeAnalysis)
	{
		report("Destroying control tree for kernel " << k->name);
		k->clear_ctrl_tree();
	}
}

static void allocateNewDataStructures(ir::Kernel* k, int type)
{
	if(type & Pass::ControlTreeAnalysis)
	{
		report("Allocating control tree for kernel " << k->name);
		k->ctrl_tree();
	}
	if(type & Pass::DominatorTreeAnalysis)
	{
		report("Allocating dominator tree for kernel " << k->name);
		k->dom_tree();
	}
	if(type & Pass::PostDominatorTreeAnalysis)
	{
		report("Allocating post-dominator tree for kernel " << k->name);
		k->pdom_tree();
	}
	if(type & Pass::DataflowGraphAnalysis)
	{
		report("Allocating dataflow graph for kernel " << k->name);
		k->dfg();
	}
	if(type & Pass::StaticSingleAssignment)
	{
		if(!k->dfg()->ssa())
		{
			report("Converting to SSA for kernel " << k->name);
			k->dfg()->toSsa();
		}
	}
}

static void runKernelPass(ir::Kernel* kernel, Pass* pass)
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
		for( ir::ControlFlowGraph::iterator 
			block = kernel->cfg()->begin(); 
			block != kernel->cfg()->end(); ++block )
		{
			bbPass->runOnBlock( *block );
		}
		bbPass->finalizeKernel();
	}
	break;
	case Pass::InvalidPass: assertM(false, "Invalid pass type.");
	}
}

static void runKernelPass(ir::Module* module, ir::Kernel* kernel, Pass* pass)
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
		for( ir::ControlFlowGraph::iterator 
			block = kernel->cfg()->begin(); 
			block != kernel->cfg()->end(); ++block )
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
	
	ir::Kernel* kernel = _module->getKernel(name);

	for(PassMap::iterator pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		initializeKernelPass(_module, pass->second);
	}
	
	for(PassMap::iterator pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		freeUnusedDataStructures(kernel, pass->first);
		allocateNewDataStructures(kernel, pass->first);
		
		runKernelPass(kernel, pass->second);
	}

	freeUnusedDataStructures(kernel, Pass::NoAnalysis);

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
			allocateNewDataStructures(kernel->second, pass->first);
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

			freeUnusedDataStructures(kernel->second, pass->first);
			allocateNewDataStructures(kernel->second, pass->first);
		
			runKernelPass(_module, kernel->second, pass->second);
		}

		freeUnusedDataStructures(kernel->second, Pass::NoAnalysis);

		for(PassMap::iterator pass = _passes.begin();
			pass != _passes.end(); ++pass)
		{
			finalizeKernelPass(_module, pass->second);
		}
	}
}

}

#endif

