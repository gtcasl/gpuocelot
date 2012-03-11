/*	\file   SimplifyControlFlowGraphPass.cpp
	\date   Tuesday January 31, 2012
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The source file for the SimplifyControlFlowGraphPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/SimplifyControlFlowGraphPass.h>

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/IRKernel.h>

// Hydrazine Includes
#include <hydrazine/interface/debug.h>

// Preprocessor Defines
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace transforms
{

SimplifyControlFlowGraphPass::SimplifyControlFlowGraphPass()
: KernelPass(Analysis::NoAnalysis, "SimplifyControlFlowGraphPass"),
	mergeExitBlocks(true), deleteEmptyBlocks(true)
{

}

void SimplifyControlFlowGraphPass::initialize(const ir::Module& m)
{

}

void SimplifyControlFlowGraphPass::runOnKernel(ir::IRKernel& k)
{
	bool changed = true;
	
	while(changed)
	{
		#if REPORT_BASE != 0
		k.cfg()->write(std::cout);
		#endif

		changed = _swapBranchAndFallthroughEdges(k);
		
		#if REPORT_BASE != 0
		k.cfg()->write(std::cout);
		#endif
		
		_mergeExitBlocks(k);
		
		#if REPORT_BASE != 0
		k.cfg()->write(std::cout);
		#endif

		_deleteEmptyBlocks(k);
		_deleteUnconnectedBlocks(k);
	}
}

void SimplifyControlFlowGraphPass::finalize()
{
	invalidateAnalysis(analysis::Analysis::DataflowGraphAnalysis);
	invalidateAnalysis(analysis::Analysis::DominatorTreeAnalysis);
	invalidateAnalysis(analysis::Analysis::PostDominatorTreeAnalysis);
	invalidateAnalysis(analysis::Analysis::ThreadFrontierAnalysis);
}

bool SimplifyControlFlowGraphPass::_mergeExitBlocks(ir::IRKernel& k)
{
	typedef std::unordered_map<ir::ControlFlowGraph::iterator,
		ir::ControlFlowGraph::instruction_iterator> BlockMap;
	
	report("Merging exit blocks...");
	
	BlockMap exitBlocks;
	
	// Find all blocks with exit instructions
	for(ir::ControlFlowGraph::iterator block = k.cfg()->begin();
		block != k.cfg()->end(); ++block)
	{
		for(ir::ControlFlowGraph::instruction_iterator
			instruction = block->instructions.begin();
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx =
				static_cast<ir::PTXInstruction&>(**instruction);
			
			if(ptx.isExit())
			{
				exitBlocks.insert(std::make_pair(block, instruction));
				break;
			}
		}
	}
	
	// If there is only one/zero blocks, then don't change anything
	if(exitBlocks.size() < 2)
	{
		if(exitBlocks.size() == 1)
		{
			ir::PTXInstruction& ptx =
				static_cast<ir::PTXInstruction&>(**exitBlocks.begin()->second);
			
			if(k.function())
			{
				ptx.opcode = ir::PTXInstruction::Ret;
			}
			else
			{
				ptx.opcode = ir::PTXInstruction::Exit;
			}
		}
		
		return false;
	}
	// Otherwise...
	
	// 1) create a new exit block
	ir::ControlFlowGraph::iterator newExit = k.cfg()->insert_block(
		ir::BasicBlock("Exit", k.cfg()->newId()));
	
	ir::BasicBlock::EdgePointerVector deletedEdges =
		k.cfg()->get_exit_block()->in_edges;
	
	// 1a) Create edges targetting the new block
	for(ir::ControlFlowGraph::edge_pointer_iterator edge = deletedEdges.begin();
		edge != deletedEdges.end(); ++edge)
	{
		k.cfg()->insert_edge(ir::Edge((*edge)->head, newExit, (*edge)->type));
		k.cfg()->remove_edge(*edge);
	}
	
	k.cfg()->insert_edge(ir::Edge(newExit, k.cfg()->get_exit_block(),
		ir::Edge::FallThrough));
	
	// 2) Delete the instructions from their blocks
	for(BlockMap::iterator block = exitBlocks.begin();
		block != exitBlocks.end(); ++block)
	{
		// 2a) Insert a branch from blocks with branch edges
		ir::ControlFlowGraph::edge_pointer_iterator edge =
			newExit->find_in_edge(block->first);
		
		if((*edge)->type == ir::Edge::Branch)
		{
			ir::PTXInstruction* newBranch = new ir::PTXInstruction(
				ir::PTXInstruction::Bra, ir::PTXOperand(newExit->label));
				
			newBranch->uni = true;
		
			block->first->instructions.push_back(newBranch);
		}
		
		delete *block->second;
		block->first->instructions.erase(block->second);
		
		report(" merging block " << block->first->label);
	}
	
	// 3 Add an appropriate exit instruction to the new exit block
	if(k.function())
	{
		newExit->instructions.push_back(
			new ir::PTXInstruction(ir::PTXInstruction::Ret));
	}
	else
	{
		newExit->instructions.push_back(
			new ir::PTXInstruction(ir::PTXInstruction::Exit));
	}
	
	return true;
}

bool SimplifyControlFlowGraphPass::_deleteEmptyBlocks(ir::IRKernel& k)
{
	report("Deleting empty blocks...");
	
	bool any = false;
	
	for(ir::ControlFlowGraph::iterator block = k.cfg()->begin();
		block != k.cfg()->end(); )
	{
		if(block == k.cfg()->get_entry_block()) { ++block; continue; }
		if(block == k.cfg()->get_exit_block())  { ++block; continue; }
	
		if(block->instructions.empty())
		{
			// redirect all in_edges to the target
			ir::BasicBlock::EdgePointerVector inEdges = block->in_edges;
		
			if(block->has_fallthrough_edge())
			{
				ir::ControlFlowGraph::iterator fallthrough =
					block->get_fallthrough_edge()->tail;

				k.cfg()->remove_edge(block->get_fallthrough_edge());

				for(ir::ControlFlowGraph::edge_pointer_iterator
					edge = inEdges.begin();	edge != inEdges.end(); ++edge)
				{
					if((*edge)->type == ir::Edge::FallThrough)
					{
						k.cfg()->insert_edge(ir::Edge((*edge)->head,
							fallthrough, ir::Edge::FallThrough));
					}
					else
					{
						k.cfg()->insert_edge(ir::Edge((*edge)->head,
							fallthrough, ir::Edge::Branch));
							
						ir::PTXInstruction& ptx =
							static_cast<ir::PTXInstruction&>(
							*(*edge)->head->instructions.back());
							
						ptx.d.identifier = fallthrough->label;
					}
				}
			}
		
			report(" " << block->label);
		
			// delete the block, should wipe out all edges
			k.cfg()->remove_block(block++);
		}
		else
		{
			++block;
		}
	}
	
	return any;
}

bool SimplifyControlFlowGraphPass::_deleteUnconnectedBlocks(ir::IRKernel& k)
{
	return false;
	// TODO implement this
}

bool SimplifyControlFlowGraphPass::_swapBranchAndFallthroughEdges(
	ir::IRKernel& k)
{
	return false;	
	// TODO implement this
}

}


