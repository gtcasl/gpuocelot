/*! \file   MIMDThreadSchedulingPass.cpp
	\date   Friday February 18, 2011
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The source file for the MIMDThreadSchedulingPass class.
*/

#ifndef MIMD_THREAD_SCHEDULING_PASS_CPP_INCLUDED
#define MIMD_THREAD_SCHEDULING_PASS_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/MIMDThreadSchedulingPass.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/DominatorTree.h>
#include <ocelot/ir/interface/PostdominatorTree.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace analysis
{

MIMDThreadSchedulingPass::MIMDThreadSchedulingPass()
	: KernelPass(DataflowGraphAnalysis, "MIMDThreadSchedulingPass")
{

}

void MIMDThreadSchedulingPass::initialize(const ir::Module& m)
{
	// none needed, intentionally empty
}

static void sinkBarrier(ir::PTXKernel& ptx, 
	ir::ControlFlowGraph::iterator block, ir::ControlFlowGraph::iterator dom,
	ir::ControlFlowGraph::iterator pdom)
{
/*	bool split = true;
	ir::ControlFlowGraph::iterator currentBlock = block;
	
	while(split)
	{
	
	}
	*/
}

void MIMDThreadSchedulingPass::runOnKernel(ir::Kernel& k)
{
	assertM(k.ISA == ir::Instruction::PTX,
		"This pass is valid for PTX kernels only.");

	ir::PTXKernel* kernel = static_cast<ir::PTXKernel*>(&k);
	ir::ControlFlowGraph::BlockPointerVector schedulingPoints;
	ir::ControlFlowGraph::BlockPointerVector postDominators;
	ir::ControlFlowGraph::BlockPointerVector dominators;

	// identify scheduling points
	//  - blocks with barriers
	for(ir::ControlFlowGraph::iterator block = kernel->cfg()->begin();
		block != kernel->cfg()->end(); ++block)
	{
		// skip blocks that are post dominators of the entry point	
		if(kernel->pdom_tree()->postDominates(
			block, kernel->cfg()->get_entry_block()))
		{
			report("Skipping block " << block->id);
			continue;
		}
	
		for(ir::ControlFlowGraph::InstructionList::const_iterator
			instruction = block->instructions.begin();
			instruction != block->instructions.end(); ++instruction)
		{
			const ir::PTXInstruction& ptx =
				*static_cast<const ir::PTXInstruction*>(*instruction);
			if(ptx.opcode == ir::PTXInstruction::Bar)
			{
				ir::ControlFlowGraph::iterator
					pdom = kernel->pdom_tree()->getPostDominator(block);
				ir::ControlFlowGraph::iterator
					dom = kernel->dom_tree()->getDominator(block);
				report("Found barrier " << ptx.toString()
					<< " in block " << block->id << " (postdominator "
					<< pdom->id << ") (dominator " << dom->id << ")");
				schedulingPoints.push_back(block);
				postDominators.push_back(pdom);
				dominators.push_back(dom);
				break;
			}
		}
	}
	
	ir::ControlFlowGraph::pointer_iterator block = schedulingPoints.begin();
	ir::ControlFlowGraph::pointer_iterator dom   = dominators.begin();
	ir::ControlFlowGraph::pointer_iterator pdom  = postDominators.begin();
	for( ; block != schedulingPoints.end(); ++block, ++dom, ++pdom)
	{
		sinkBarrier(*kernel, *block, *dom, *pdom);
	}
}

void MIMDThreadSchedulingPass::finalize()
{
	// none needed, intentionall empty
}

}

#endif

