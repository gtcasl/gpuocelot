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

/* algorithm
    1) start at a kernel entry point that dominates all remaining blocks
    2) create a connected subgraph with N instructions and no barriers
      a) This is a new kernel
    3) For all edges leaving the graph
      a) save all live registers
      b) save the target block's id
      c) create a new scheduler block includes an indirect branch to each 
         of the targets
      d) redirect each edge to the kernel exit point
      e) create a new kernel rooted in the new scheduler block, goto 1
*/
void SubkernelFormationPass::ExtractKernelPass::runOnKernel(ir::Kernel& k)
{
	typedef std::unordered_set<ir::ControlFlowGraph::const_iterator> BlockSet;
	typedef std::queue<ir::ControlFlowGraph::const_iterator> BlockQueue;
	typedef std::vector<ir::ControlFlowGraph::const_iterator> BlockVector;
	report("Splitting kernel '" << k.name << "' into sub-kernel regions.");
	
	BlockQueue queue;
	KernelVector splitKernels;
	BlockVector region;
	BlockSet encountered;
	BlockSet inEdges;
	unsigned int currentRegionSize = 0;
	
	const ir::PTXKernel& ptx = static_cast<const ir::PTXKernel&>(k);
	
	// This is the new kernel entry point
	kernels.push_back(new ir::PTXKernel(k.name, false));

	ir::PTXKernel& newKernel = static_cast<ir::PTXKernel&>(
		*splitKernels.back());

	// Start at the entry block	
	queue.push(ptx.cfg().get_entry_block());
	
	while(true)
	{
		// The front of the queue becomes part of the region
		ir::ControlFlowGraph::const_iterator block = queue.front();
		queue.pop();

		// Remove this block from the entering list (if it exists)
		inEdges.erase(block);

		// Keep track of all blocks entering the region
		for(ir::ControlFlowGraph::const_edge_pointer_iterator 
			edge = current->in_edges.begin(); 
			edge != current->in_edges.end(); ++edge)
		{
			inEdges.insert((*edge)->head);
		}

		// Blocks leaving the region become candidates for the next block
		for(ir::ControlFlowGraph::const_edge_pointer_iterator 
			edge = current->out_edges.begin(); 
			edge != current->out_edges.end(); ++edge)
		{
			ir::ControlFlowGraph::const_iterator tail = (*edge)->tail;

			// skip the exit block
			if(tail == ptx.cfg().get_exit_block()) continue;
			
			// skip already encountered blocks
			if(!encountered.insert(tail).second) continue;
			
			// push successor blocks
			queue.push(tail);
		}

		// Add the block to the new kernel (skip the entry)
		if(block == ptx.cfg().get_entry_block()) continue;

		currentRegionSize += block->instructions.size();
		region.push_back(block);
		
		// create a new region if there are enough blocks
		if(currentRegionSize < expectedRegionSize && !queue.empty()) continue;
		
		_createRegion(newKernel, region, inEdges);
		
		// restart with a new kernel if there are any blocks left
		if(queue.empty()) break;

		currentRegionSize = 0;
		splitKernels.push_back(new ir::PTXKernel(k.name, false));
		encountered.clear();
		inEdges.clear();

		newKernel = static_cast<ir::PTXKernel&>(*splitKernels.back());
	}
	
	kernels.insert(std::make_pair(k.name, std::move(splitKernels)));
}

void SubkernelFormationPass::ExtractKernelPass::finalize()
{
	
}

}

#endif

