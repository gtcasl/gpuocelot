/*! \file PassManager.cpp
	\date Thursday September 16, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the PassManager class
*/

#ifndef PASS_MANAGER_CPP_INCLUDED
#define PASS_MANAGER_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/transforms/interface/PassManager.h>
#include <ocelot/transforms/interface/PassFactory.h>
#include <ocelot/transforms/interface/Pass.h>

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/DivergenceAnalysis.h>
#include <ocelot/analysis/interface/AffineAnalysis.h>
#include <ocelot/analysis/interface/ControlTree.h>
#include <ocelot/analysis/interface/DominatorTree.h>
#include <ocelot/analysis/interface/PostdominatorTree.h>
#include <ocelot/analysis/interface/StructuralAnalysis.h>
#include <ocelot/analysis/interface/ThreadFrontierAnalysis.h>
#include <ocelot/analysis/interface/LoopAnalysis.h>
#include <ocelot/analysis/interface/ConvergentRegionAnalysis.h>

#include <ocelot/ir/interface/IRKernel.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine Includes
#include <hydrazine/interface/debug.h>

// Standard Library Includes
#include <stdexcept>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace transforms
{

typedef PassManager::AnalysisMap AnalysisMap;

static void freeUnusedDataStructures(AnalysisMap& analyses,
	ir::IRKernel* k, int type)
{
	typedef std::vector<int> TypeVector;
	
	#if defined(__clang__) || defined(_WIN32)
	// clang/win32 doesn't support initializer lists yet
	TypeVector types;
	
	types.push_back(analysis::Analysis::DivergenceAnalysis);
	types.push_back(analysis::Analysis::AffineAnalysis);
	types.push_back(analysis::Analysis::DataflowGraphAnalysis);
	types.push_back(analysis::Analysis::PostDominatorTreeAnalysis);
	types.push_back(analysis::Analysis::DominatorTreeAnalysis);
	types.push_back(analysis::Analysis::ControlTreeAnalysis);
	types.push_back(analysis::Analysis::StructuralAnalysis);
	types.push_back(analysis::Analysis::ThreadFrontierAnalysis);
	types.push_back(analysis::Analysis::LoopAnalysis);
	types.push_back(analysis::Analysis::ConvergentRegionAnalysis);
	
	#else
	TypeVector types =
	{
		analysis::Analysis::AffineAnalysis,
		analysis::Analysis::DivergenceAnalysis,
		analysis::Analysis::DataflowGraphAnalysis,
		analysis::Analysis::PostDominatorTreeAnalysis,
		analysis::Analysis::DominatorTreeAnalysis,
		analysis::Analysis::ControlTreeAnalysis,
		analysis::Analysis::StructuralAnalysis,
		analysis::Analysis::ThreadFrontierAnalysis,
		analysis::Analysis::LoopAnalysis,
		analysis::Analysis::ConvergentRegionAnalysis
	};
	#endif
	
	for(TypeVector::const_iterator t = types.begin(); t != types.end(); ++t)
	{
		if(type < *t)
		{
			AnalysisMap::iterator structure = analyses.find(*t);
			
			if(structure != analyses.end())
			{
				report("   Destroying " << structure->second->name
					<< " for kernel " << k->name);
				delete structure->second;
				analyses.erase(structure);
			}
		}
	}
}

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
			analysis::PostdominatorTree* pdomTree =
				new analysis::PostdominatorTree;
			
			report("   Allocating post-dominator tree for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::PostDominatorTreeAnalysis, pdomTree));
			
			pdomTree->setPassManager(manager);
			allocateNewDataStructures(analyses, k, pdomTree->required, manager);
				
			pdomTree->analyze(*k);
		}
	}
	if(type & (analysis::Analysis::DataflowGraphAnalysis
	    |analysis::Analysis::StaticSingleAssignment
	    |analysis::Analysis::MinimalStaticSingleAssignment
	    |analysis::Analysis::GatedStaticSingleAssignment))
	{
    if(analyses.count(analysis::Analysis::DataflowGraphAnalysis) == 0)
		{
      report("   Allocating dataflow graph for kernel " << k->name);
      analysis::DataflowGraph* graph = new analysis::DataflowGraph;

			analyses.insert(std::make_pair(
				analysis::Analysis::DataflowGraphAnalysis, graph)).first;

      graph->setPassManager(manager);
      allocateNewDataStructures(analyses, k, graph->required, manager);
      graph->analyze(*k);
    }

    AnalysisMap::iterator dfg = analyses.find(analysis::Analysis::DataflowGraphAnalysis);

    analysis::DataflowGraph *dfgp = static_cast<analysis::DataflowGraph*>(dfg->second);
    if (type & analysis::Analysis::StaticSingleAssignment) {
      assertM(!(type &
          (analysis::Analysis::MinimalStaticSingleAssignment |
          analysis::Analysis::GatedStaticSingleAssignment)),
          "Cannot ask for more than one SSA form at once");
      if (dfgp->ssa() != analysis::DataflowGraph::SsaType::Default) {
        if (dfgp->ssa() != analysis::DataflowGraph::SsaType::None) {
          dfgp->fromSsa();
        }
        dfgp->toSsa();
      }
    } else if (type & analysis::Analysis::MinimalStaticSingleAssignment) {
      assertM(!(type & analysis::Analysis::GatedStaticSingleAssignment),
          "Cannot ask for more than one SSA form at once");
      if (dfgp->ssa() != analysis::DataflowGraph::SsaType::Minimal) {
        if (dfgp->ssa() != analysis::DataflowGraph::SsaType::None) {
          dfgp->fromSsa();
        }
        dfgp->toSsa(analysis::DataflowGraph::SsaType::Minimal);
      }
    } else if(type & analysis::Analysis::GatedStaticSingleAssignment){
      if (dfgp->ssa() != analysis::DataflowGraph::SsaType::Gated) {
        if (dfgp->ssa() != analysis::DataflowGraph::SsaType::None) {
          dfgp->fromSsa();
        }
        dfgp->toSsa(analysis::DataflowGraph::SsaType::Gated);
      }
    }
  }

  if (type & analysis::Analysis::DivergenceAnalysis)
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
		
			if(type & analysis::Analysis::ConditionalDivergenceAnalysis)
			{
				static_cast<analysis::DivergenceAnalysis*>(
					analysis->second)->setConditionalConvergence(true);
			}
			
			static_cast<analysis::DivergenceAnalysis*>(
				analysis->second)->analyze(*k);
		}
	}
	if(type & analysis::Analysis::AffineAnalysis)
	{
		if(analyses.count(analysis::Analysis::AffineAnalysis) == 0)
		{
			report("   Allocating affine analysis for kernel " << k->name);

			AnalysisMap::iterator analysis = analyses.insert(std::make_pair(
			analysis::Analysis::AffineAnalysis, new analysis::AffineAnalysis )).first;

			analysis->second->setPassManager(manager);
			allocateNewDataStructures(analyses, k, analysis->second->required, manager);
			static_cast<analysis::AffineAnalysis*>(analysis->second)->analyze(*k);
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
	if(type & analysis::Analysis::LoopAnalysis)
	{
		if(analyses.count(analysis::Analysis::LoopAnalysis) == 0)
		{
			analysis::LoopAnalysis* loopAnalysis =
				new analysis::LoopAnalysis;
			
			report("   Allocating loop analysis"
				" for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::LoopAnalysis,
				loopAnalysis));
			
			loopAnalysis->setPassManager(manager);
			allocateNewDataStructures(analyses, k,
				loopAnalysis->required, manager);
			loopAnalysis->analyze(*k);
		}
	}
	if(type & analysis::Analysis::ConvergentRegionAnalysis)
	{
		if(analyses.count(analysis::Analysis::ConvergentRegionAnalysis) == 0)
		{
			analysis::ConvergentRegionAnalysis* regionAnalysis =
				new analysis::ConvergentRegionAnalysis;
			
			report("   Allocating convergent region analysis"
				" for kernel " << k->name);
			analyses.insert(std::make_pair(
				analysis::Analysis::ConvergentRegionAnalysis,
				regionAnalysis));
			
			regionAnalysis->setPassManager(manager);
			allocateNewDataStructures(analyses, k,
				regionAnalysis->required, manager);
			regionAnalysis->analyze(*k);
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

PassManager::~PassManager()
{
	clear();
}

void PassManager::addPass(Pass& pass)
{
	report("Adding pass '" << pass.toString() << "'");
	_passes.insert(std::make_pair(pass.analyses, &pass));
	pass.setPassManager(this);
}

void PassManager::clear()
{
	for(PassMap::iterator pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		pass->second->setPassManager(0);
	}
	
	for(auto pass = _ownedTemporaryPasses.begin();
		pass != _ownedTemporaryPasses.end(); ++pass)
	{
		delete *pass;
	}
	
	_ownedTemporaryPasses.clear();
	_passes.clear();
}

void PassManager::destroyPasses()
{
	for(PassMap::iterator pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		delete pass->second;
	}
		
	_passes.clear();
	_ownedTemporaryPasses.clear();
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

	PassVector passes = _schedulePasses();

	for(auto pass = passes.begin(); pass != passes.end(); ++pass)
	{
		initializeKernelPass(_module, *pass);
	}
	
	AnalysisMap analyses;
	
	_analyses = &analyses;
	_kernel = &kernel;
	
	for(auto pass = passes.begin(); pass != passes.end(); ++pass)
	{
		freeUnusedDataStructures(analyses, &kernel, (*pass)->analyses);
		allocateNewDataStructures(analyses, &kernel, (*pass)->analyses, this);
		
		runKernelPass(&kernel, *pass);
	}

	freeUnusedDataStructures(analyses, &kernel, analysis::Analysis::NoAnalysis);

	for(auto pass = passes.begin(); pass != passes.end(); ++pass)
	{
		finalizeKernelPass(_module, *pass);
	}

	_analyses = 0;
	_kernel   = 0;
}

void PassManager::runOnModule()
{
	report("Running pass manager on module " << _module->path());

	_module->loadNow();
	
	typedef std::vector<AnalysisMap> AnalysisMapVector;
	
	AnalysisMapVector kernelAnalyses(_module->kernels().size());
	
	PassVector passes = _schedulePasses();

	// Run all module passes first
	for(auto pass = passes.begin(); pass != passes.end(); ++pass)
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
	for(ir::Module::KernelMap::const_iterator 
		kernel = _module->kernels().begin();
		kernel != _module->kernels().end(); ++kernel, ++analyses)
	{
		for(auto pass = passes.begin(); pass != passes.end(); ++pass)
		{
			initializeKernelPass(_module, *pass);
		}
		
		_analyses = &*analyses;
		_kernel = kernel->second;
		
		for(auto pass = passes.begin(); pass != passes.end(); ++pass)
		{
			if((*pass)->type == Pass::ImmutablePass) continue;
			if((*pass)->type == Pass::ModulePass)    continue;
			
			freeUnusedDataStructures( *analyses, kernel->second,
				(*pass)->analyses);
			allocateNewDataStructures(*analyses, kernel->second,
				(*pass)->analyses, this);
			
			runKernelPass(_module, kernel->second, *pass);
		}
		
		freeUnusedDataStructures(*analyses, kernel->second,
			analysis::Analysis::NoAnalysis);

		for(auto pass = passes.begin(); pass != passes.end(); ++pass)
		{
			finalizeKernelPass(_module, *pass);
		}
		
		_analyses = 0;
		_kernel   = 0;
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

PassManager::PassVector PassManager::_schedulePasses()
{
	typedef std::unordered_map<std::string, Pass*> PassMap;
	
	report(" Scheduling passes...");
	
	PassVector scheduled;
	PassMap    unscheduled;
	PassMap    needDependencyCheck;
	
	report("  Initial list:");
	for(auto pass = _passes.begin(); pass != _passes.end(); ++pass)
	{
		report("   " << pass->second->name);
		unscheduled.insert(std::make_pair(pass->second->name, pass->second));
		needDependencyCheck.insert(std::make_pair(pass->second->name,
			pass->second));
	}
	
	report("  Adding dependent passes:");
	while(!needDependencyCheck.empty())
	{
		auto pass = needDependencyCheck.begin();

		report("   for pass '" << pass->first << "'");
		
		auto dependentPasses = pass->second->getDependentPasses();
		
		needDependencyCheck.erase(pass);
		
		for(auto dependentPass = dependentPasses.begin();
			dependentPass != dependentPasses.end(); ++dependentPass)
		{
			if(unscheduled.count(*dependentPass) == 0)
			{
				report("    adding '" << *dependentPass << "'");
				auto newPass = PassFactory::createPass(*dependentPass);
				addPass(*newPass);
				_ownedTemporaryPasses.push_back(newPass);
				unscheduled.insert(std::make_pair(*dependentPass, newPass));
				needDependencyCheck.insert(
					std::make_pair(*dependentPass, newPass));
			}
		}
	}
	
	report("  Final schedule:");
	
	while(!unscheduled.empty())
	{
		bool dependenciesSatisfied = false;
		for(auto pass = unscheduled.begin(); pass != unscheduled.end(); ++pass)
		{
			auto dependentPasses = pass->second->getDependentPasses();
			
			dependenciesSatisfied = true;
			
			for(auto dependentPass = dependentPasses.begin();
				dependentPass != dependentPasses.end(); ++dependentPass)
			{
				for(auto pass = unscheduled.begin();
					pass != unscheduled.end(); ++pass)
				{
					if(*dependentPass == pass->second->name)
					{
						dependenciesSatisfied = false;
						break;
					}
				}
				
				if(!dependenciesSatisfied) break;
			}
			
			if(dependenciesSatisfied)
			{
				report("   " << pass->second->name);
				scheduled.push_back(pass->second);
				unscheduled.erase(pass);
				break;
			}
		}
		
		if(!dependenciesSatisfied)
		{
			throw std::runtime_error("Passes have circular dependencies!");
		}
	}
	
	report("  Finished scheduling");
	
	return scheduled;
}


}

#endif

