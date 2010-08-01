/*! \file SubkernelFormationPass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday July 27, 2010
	\brief The source file for the SubkernelFormationPass class.

	Notes:
	The motivation here is fourfold:
		 1) Create natural boundaries for context switching between threads.
		 2) Enforce that all threads in a CTA execute loosely in lock-step to 
		 	improve data/instruction locality.
		 3) Coarsen regions between barriers to amortize their cost.
		 4) Create well-defined regions for performing local optimizations.  
		 	Reduce the complexity of subsequent operations with complexities 
		 	that depend on the kernel size.
*/

#ifndef SUBKERNEL_FORMATION_PASS_CPP_INCLUDED
#define SUBKERNEL_FORMATION_PASS_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/SubkernelFormationPass.h>
#include <ocelot/ir/interface/Module.h>

namespace analysis
{

void SubkernelFormationPass::runOnModule(ir::Module& m)
{
	// This pass requires all kernels to be loaded
	m.loadNow();

	SubkernelFormationPass pass;
	
	pass.initialize(m);

	for(ir::Module::KernelMap::const_iterator kernel = m.kernels().begin(); 
		kernel != m.kernels().end(); ++kernel)
	{
		pass.runOnKernel(*kernel->second);
	}

	pass.finalize();
	
	for(SubkernelFormationPass::KernelMap::const_iterator 
		kernel = pass.kernels.begin(); kernel != pass.kernels.end(); ++kernel)
	{
		m.replace(kernel->first, kernel->second);
	}
}

void SubkernelFormationPass::ExtractKernelPass::initialize(const ir::Module& m)
{
	
}

void SubkernelFormationPass::ExtractKernelPass::runOnKernel(ir::Kernel& k)
{
	report("Splitting kernel '" << k.name << "' into sub-kernel regions.");
	
	KernelVector splitKernels;
	
	ir::PTXKernel& ptx = static_cast<ir::PTXKernel&>(k);
	
	// This is the new kernel entry point
	splitKernels.push_back(new ir::PTXKernel(k.name, false));
	
	for(ir::ControlFlowGraph::const_iterator 
		block = ptx.cfg().get_entry_block(); 
		block != ptx.cfg().get_exit_block(); /* empty */)
	{
		ir::ControlFlowGraph::const_iterator 
			pdom = ptx.pdom().getPostDominator(block);
		
		
		
		block = pdom;
	}
	
	kernels.insert(std::make_pair(k.name, std::move(splitKernels)));
}

void SubkernelFormationPass::ExtractKernelPass::finalize()
{
	
}

}

#endif

