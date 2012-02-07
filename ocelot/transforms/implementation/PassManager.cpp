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
#include <ocelot/analysis/interface/StructuralAnalysis.h>
#include <ocelot/analysis/interface/ThreadFrontierAnalysis.h>
#include <ocelot/analysis/interface/HyperblockAnalysis.h>
#include <ocelot/analysis/interface/SuperblockAnalysis.h>

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

typedef PassManager::AnalysisMap              AnalysisMap;
typedef std::unordered_map<int, unsigned int> AnalysisUseMap;
typedef PassManager::PassList                 PassList;
	
static void allocateNewDataStructures(AnalysisMap& analyses,
	ir::IRKernel* k, int type, PassManager* manager)
{
	if(type & analysis::Analysis::ControlTreeAnalysis)
	{
		if(analyses.count(analysis::Analysis::ControlTreeAnalysis) == 0)
		{
			report("   Allocating control tree for kernel " << k->name);
			AnalysisMap::iterator analysis = analyses.insert(std::make_pair(
				analysis::Analysis::ControlTreeAnalysis,
				new analysis::ControlTree(k->cfg()))).first;
			
			analysis->second->setPassManager(manager);
		}
	}
	if(type & analysis::Analysis::DominatorTreeAnalysis)
	{
		if(analyses.count(analysis::Analysis::DominatorTreeAnalysis) == 0)
		{
			report("   Allocating dominator tree for kernel " << k->name);
			AnalysisMap::iterator analysis = analyses.insert(std::make_pair(
				analysis::Analysis::DominatorTreeAnalysis,
				new analysis::DominatorTree(k->cfg()))).first;
			
			analysis->second->setPassManager(manager);
		}
	}
	if(type & analysis::Analysis::PostDominatorTreeAnalysis)
	{
		if(analyses.count(analysis::Analysis::PostDominatorTreeAnalysis) == 0)
		{
			report("   Allocating post-dominator tree for kernel " << k->name);
			AnalysisMap::iterator analysis = analyses.insert(std::make_pair(
				analysis::Analysis::PostDominatorTreeAnalysis,
				new analysis::PostdominatorTree(k->cfg()))).first;
			
			analysis->second->setPassManager(manager);
		}
	}
	if(type & analysis::Analysis::DataflowGraphAnalysis)
	{
		AnalysisMap::iterator dfg = analyses.find(
			analysis::Analysis::DataflowGraphAnalysis);
		
		if(analyses.end() == dfg)
		{
			report("   Allocating dataflow graph for kernel " << k->name);
			analysis::DataflowGraph* graph = new analysis::DataflowGraph;

			dfg = analyses.insert(std::make_pair(
				analysis::Analysis::DataflowGraphAnalysis, graph)).first;
			
			graph->setPassManager(manager);
			allocateNewDataStructures(analyses, k, graph->required, manager);
			graph->analyze(*k);
		}
		if( (type & analysis::Analysis::StaticSingleAssignment) &&
		  !(static_cast<analysis::DataflowGraph*>(dfg->second)->ssa()))
		{
			report("   Converting DFG into SSA for " << k->name);
			static_cast<analysis::DataflowGraph*>(dfg->second)->toSsa();
		}
	}
	if(type & analysis::Analysis::DivergenceAnalysis)
	{
		if(analyses.count(analysis::Analysis::DivergenceAnalysis) == 0)
		{
			report("   Allocating divergence analysis for kernel " << k->name);
			AnalysisMap::iterator analysis = analyses.insert(std::make_pair(
				analysis::Analysis::DivergenceAnalysis,
				new analysis::DivergenceAnalysis())).first;
			
			analysis->second->setPassManager(manager);
			allocateNewDataStructures(analyses, k,
				analysis->second->required, manager);
			static_cast<analysis::DivergenceAnalysis*>(
				analysis->second)->analyze(*k);
		}
	}
	if(type & analysis::Analysis::StructuralAnalysis)
	{
		if(analyses.count(analysis::Analysis::StructuralAnalysis) == 0)
		{
			analysis::StructuralAnalysis* structuralAnalysis =
				new analysis::StructuralAnalysis;
			
			report("   Allocating structural analysis for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::StructuralAnalysis,
				structuralAnalysis));
			
			structuralAnalysis->setPassManager(manager);
			allocateNewDataStructures(analyses, k,
				structuralAnalysis->required, manager);
			structuralAnalysis->analyze(*k);
		}
	}
	if(type & analysis::Analysis::ThreadFrontierAnalysis)
	{
		if(analyses.count(analysis::Analysis::ThreadFrontierAnalysis) == 0)
		{
			analysis::ThreadFrontierAnalysis* frontierAnalysis =
				new analysis::ThreadFrontierAnalysis;
			
			report("   Allocating thread frontier analysis"
				" for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::ThreadFrontierAnalysis,
				frontierAnalysis));
			
			frontierAnalysis->setPassManager(manager);
			allocateNewDataStructures(analyses, k,
				frontierAnalysis->required, manager);
			frontierAnalysis->analyze(*k);
		}
	}
	if(type & analysis::Analysis::SuperblockAnalysis)
	{
		if(analyses.count(analysis::Analysis::SuperblockAnalysis) == 0)
		{
			analysis::SuperblockAnalysis* superblockAnalysis =
				new analysis::SuperblockAnalysis;
			
			report("   Allocating superblock analysis "
				" for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::SuperblockAnalysis,
				superblockAnalysis));
			
			superblockAnalysis->setPassManager(manager);
			allocateNewDataStructures(analyses, k,
				superblockAnalysis->required, manager);
			superblockAnalysis->analyze(*k);
		}
	}
	if(type & analysis::Analysis::HyperblockAnalysis)
	{
		if(analyses.count(analysis::Analysis::HyperblockAnalysis) == 0)
		{
			analysis::HyperblockAnalysis* hyperblockAnalysis =
				new analysis::HyperblockAnalysis;
			
			report("   Allocating hyperblock analysis "
				" for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::HyperblockAnalysis,
				hyperblockAnalysis));
			
			hyperblockAnalysis->setPassManager(manager);
			allocateNewDataStructures(analyses, k,
				hyperblockAnalysis->required, manager);
			hyperblockAnalysis->analyze(*k);
		}
	}
}

static void freeUnusedDataStructures(AnalysisMap& analyses,
	AnalysisUseMap& uses, int types)
{
	for(unsigned int i = 0; i < 8 * sizeof(int); ++i)
	{
		int type = 1 << i;
		
		if(types & type)
		{
			AnalysisUseMap::iterator use = uses.find(type);
			assert(use != uses.end());
			
			--use->second;
			
			if(use->second == 0)
			{
				uses.erase(use);
				
				AnalysisMap::iterator analysis = analyses.find(type);
				if(analysis != analyses.end())
				{				
					delete analysis->second;
					analyses.erase(analysis);
				}
			}
		}
	}
}

static void freeAllDataStructures(AnalysisMap& analyses)
{
	for(auto analysis = analyses.begin();
		analysis != analyses.end(); ++analysis)
	{
		delete analysis->second;
	}
	
	analyses.clear();
}

static AnalysisUseMap initializeAnalysisUses(const PassList& passes)
{
	AnalysisUseMap uses;
	
	for(auto pass = passes.begin(); pass != passes.end(); ++pass)
	{
		for(unsigned int i = 0; i < 8 * sizeof(int); ++i)
		{
			int type = 1 << i;
			
			if((*pass)->analyses & type)
			{
				AnalysisUseMap::iterator use = uses.find(type);
				
				if(use == uses.end())
				{
					use = uses.insert(std::make_pair(type, 0)).first;
				}
				
				use->second++;
			}
		}
	}
	
	return uses;
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
	case Pass::ImmutableKernelPass:
	{
		ImmutableKernelPass* k = static_cast<ImmutableKernelPass*>(pass);
		k->runOnKernel(*kernel);
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
	case Pass::ImmutableKernelPass:
	{
		report("  Running immutable kernel pass '" << pass->toString()
			<< "' on kernel '" << kernel->name << "'" );
		ImmutableKernelPass* k = static_cast<ImmutableKernelPass*>(pass);
		k->runOnKernel(*kernel);
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
	case Pass::ImmutableKernelPass:
	{
		report("  Initializing immutable kernel pass '"
			<< pass->toString() << "'" );
		ImmutableKernelPass* k = static_cast<ImmutableKernelPass*>(pass);
		k->initialize(*module);
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
	case Pass::ImmutableKernelPass:
	{
		report("  Finalizing immutable kernel pass '"
			<< pass->toString() << "'" );
		ImmutableKernelPass* k = static_cast<ImmutableKernelPass*>(pass);
		k->finalize();
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
	case Pass::KernelPass:     /* fall through */
	case Pass::BasicBlockPass: /* fall through */
	case Pass::ImmutableKernelPass:
	break;
	case Pass::InvalidPass: assertM(false, "Invalid pass type.");
	}
}

PassManager::PassManager(ir::Module* module) :
	_module(module), _analyses(0)
{
	assert(_module != 0);
}

static PassList getDependentPasses(const Pass& pass)
{
	Pass::StringVector dependentPasses = pass.getDependentPasses();
	
	PassList passes;
	
	for(auto dependentPass = dependentPasses.begin();
		dependentPass != dependentPasses.end(); ++dependentPass)
	{
		Pass* newPass = Pass::create(*dependentPass);
		assert(newPass != 0);
	
		passes.push_back(newPass);
	}
	
	return passes;
}

void PassManager::addPass(Pass& pass)
{
	report("Adding pass '" << pass.toString() << "'");

	PassList dependentPasses = getDependentPasses(pass);

	_tempPasses.insert(_tempPasses.end(), dependentPasses.begin(),
		dependentPasses.end());

	dependentPasses.push_back(&pass);

	_passes.insert(_passes.end(), dependentPasses.begin(),
		dependentPasses.end());
		
	pass.setPassManager(this);
}

void PassManager::clear()
{
	for(PassList::iterator pass = _passes.begin();
		pass != _passes.end(); ++pass)
	{
		(*pass)->setPassManager(0);
	}

	for(PassList::iterator pass = _tempPasses.begin();
		pass != _tempPasses.end(); ++pass)
	{
		delete *pass;
	}

	_passes.clear();
	_tempPasses.clear();
}

void PassManager::destroyPasses()
{
	clear();
}

void PassManager::runOnKernel(const std::string& name)
{
	_module->loadNow();
	
	ir::IRKernel* kernel = dynamic_cast<ir::IRKernel*>(
		_module->getKernel(name));

	runOnKernel(*kernel);
}

void PassManager::runOnKernel(ir::IRKernel& kernel)
{
	assert(_module->loaded());

	report("Running pass manager on kernel " << kernel.name);

	for(PassList::iterator pass = _passes.begin();
		pass != _passes.end(); ++pass)
	{
		initializeKernelPass(_module, *pass);
	}
	
	AnalysisMap    analyses;
	AnalysisUseMap uses = initializeAnalysisUses(_passes);
	
	_analyses = &analyses;
	_kernel   = &kernel;
	
	for(PassList::iterator pass = _passes.begin();
		pass != _passes.end(); ++pass)
	{
		allocateNewDataStructures(analyses, &kernel,
			(*pass)->analyses, this);
		
		runKernelPass(&kernel, *pass);
		
		freeUnusedDataStructures(analyses, uses, (*pass)->analyses);
	}

	freeAllDataStructures(analyses);

	_analyses = 0;
	_kernel   = 0;

	for(PassList::iterator pass = _passes.begin();
		pass != _passes.end(); ++pass)
	{
		finalizeKernelPass(_module, *pass);
	}
}

void PassManager::runOnModule()
{
	report("Running pass manager on module " << _module->path());

	_module->loadNow();
	
	typedef std::vector<AnalysisMap>    AnalysisMapVector;
	typedef std::vector<AnalysisUseMap> AnalysisUseMapVector;
	
	AnalysisMapVector   kernelAnalyses(_module->kernels().size());
	AnalysisUseMapVector kernelAnalysesUses(_module->kernels().size());
	
	// Run all module passes first
	for(PassList::iterator pass = _passes.begin();
		pass != _passes.end(); ++pass)
	{
		if((*pass)->type == Pass::KernelPass)     continue;
		if((*pass)->type == Pass::BasicBlockPass) continue;
		
		AnalysisMapVector::iterator analyses = kernelAnalyses.begin();
		for(ir::Module::KernelMap::const_iterator 
			kernel = _module->kernels().begin();
			kernel != _module->kernels().end(); ++kernel, ++analyses)
		{
			allocateNewDataStructures(*analyses,
				kernel->second, (*pass)->analyses, this);
		}
		
		runModulePass(_module, *pass);
	}
	
	// Run all kernel and bb passes
	AnalysisMapVector::iterator analyses = kernelAnalyses.begin();
	AnalysisUseMapVector::iterator uses = kernelAnalysesUses.begin();
	for(ir::Module::KernelMap::const_iterator 
		kernel = _module->kernels().begin();
		kernel != _module->kernels().end(); ++kernel, ++analyses, ++uses)
	{
		for(PassList::iterator pass = _passes.begin();
			pass != _passes.end(); ++pass)
		{
			initializeKernelPass(_module, *pass);
		}
		
		_analyses = &*analyses;
		_kernel   = kernel->second;
		*uses     = initializeAnalysisUses(_passes);

		for(PassList::iterator pass = _passes.begin();
			pass != _passes.end(); ++pass)
		{
			if((*pass)->type == Pass::ImmutablePass) continue;
			if((*pass)->type == Pass::ModulePass)    continue;
			
			allocateNewDataStructures(*analyses, kernel->second,
				(*pass)->analyses, this);
		
			runKernelPass(_module, kernel->second, *pass);
		
			freeUnusedDataStructures(*analyses, *uses, (*pass)->analyses);
		}

		freeAllDataStructures(*analyses);
				
		_analyses = 0;
		_kernel   = 0;

		for(PassList::iterator pass = _passes.begin();
			pass != _passes.end(); ++pass)
		{
			finalizeKernelPass(_module, *pass);
		}
	}
}

analysis::Analysis* PassManager::getAnalysis(int type)
{
	assert(_analyses != 0);

	AnalysisMap::iterator analysis = _analyses->find(type);
	if(analysis == _analyses->end())
	{
		assert(_kernel != 0);
		allocateNewDataStructures(*_analyses, _kernel, type, this);
		
		analysis = _analyses->find(type);
	}
	
	if(analysis == _analyses->end()) return 0;
	
	return analysis->second;
}

const analysis::Analysis* PassManager::getAnalysis(int type) const
{
	assert(_analyses != 0);

	AnalysisMap::const_iterator analysis = _analyses->find(type);
	if(analysis == _analyses->end()) return 0;
	
	return analysis->second;
}

void PassManager::invalidateAnalysis(int type)
{
	assert(_analyses != 0);

	AnalysisMap::iterator analysis = _analyses->find(type);
	if(analysis != _analyses->end())
	{
		delete analysis->second;
		_analyses->erase(analysis);
	}
}

}

#endif

