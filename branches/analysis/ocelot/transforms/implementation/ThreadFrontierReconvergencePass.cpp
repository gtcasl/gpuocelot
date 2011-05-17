/*! \file   ThreadFrontierReconvergencePass.cpp
	\author Gregory Diamso <gregory.diamos@gatech.edu>
	\date   Monday May 16, 2011
	\brief  The source file for the ThreadFrontierReconvergencePass class.
*/

#ifndef THREAD_FRONTIER_RECONVERGENCE_PASS_CPP_INCLUDED
#define THREAD_FRONTIER_RECONVERGENCE_PASS_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/transforms/interface/ThreadFrontierReconvergencePass.h>

#include <ocelot/analysis/interface/ThreadFrontierAnalysis.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

namespace transforms
{

ThreadFrontierReconvergencePass::ThreadFrontierReconvergencePass(bool g)
: ImmutableKernelPass(Analysis::ThreadFrontierAnalysis,
	"ThreadFrontierReconvergencePass"), _gen6(g)
{

}

void ThreadFrontierReconvergencePass::initialize(const ir::Module& m)
{
	instructions.clear();
}

void ThreadFrontierReconvergencePass::runOnKernel(const ir::IRKernel& k)
{
	report("Running thread frontier reconvergence pass");
	typedef analysis::ThreadFrontierAnalysis::Priority Priority;
	typedef std::map<Priority, ir::ControlFlowGraph::const_iterator,
		std::greater<Priority>> PriorityMap;
	typedef std::vector<ir::ControlFlowGraph::const_iterator> BlockVector;

	ReversePriorityMap priorityToBlocks;

	report("Computing basic block thread frontiers.");
	
	// sort by priority (high to low)
	for(ir::ControlFlowGraph::const_iterator block = k.cfg()->begin();
		block != k.cfg()->end(); ++block)
	{
		priorityToBlocks.insert(std::make_pair(tfAnalysis->getPriority(block),
			block));
	}
	
	BlockVector blocks;
	
	// lay the code out in priority order
	for(ReversePriorityMap::const_iterator
		priorityAndBlock = priorityToBlocks.begin();
		priorityAndBlock != priorityToBlocks.end(); ++priorityAndBlock)
	{
		blocks->push_back(priorityAndBlock->second);
	}
	
	typedef std::unordered_map<ir::BasicBlock::Id, unsigned int> IdToPCMap;

	IdToPCMap pcs;
	
	report(" Packing instructions into a vector");
	for(BlockVector::const_iterator block = blocks.begin();
		block != blocks.end(); ++block)
	{
		for(ir::ControlFlowGraph::InstructionList::const_iterator 
			instruction = (*block)->instructions.begin();
			instruction != (*block)->instructions.end(); ++instruction)
		{
			const ir::PTXInstruction& ptx = static_cast<
				const ir::PTXInstruction&>(**instruction);
				
			report("  [" << instructions.size() << "] '" << ptx.toString());
				
			if(instruction == (*block)->instructions.begin())
			{
				pcs.insert(std::make_pair((*block)->id, instructions.size()));
			}
			
			instructions.push_back(ptx);
			instructions.back().pc = instructions.size() - 1;

			if(instruction == --(*block)->instructions.end())
			{
				if(!ptx.isBranch() && block->has_fallthrough_edge())
				{
					// if the original layout assumed a fallthrough, but the
					//  priority changed it, we need a branch
					bool needsBranch = false;
					if(block != --blocks.end())
					{
						BlockVector::const_iterator next = block;
						++next;
						
						needsBranch =
							next->id != block->get_fallthrough_edge()->tail->id;
					}
					else
					{
						needsBranch = true;
					}
					
					if(needsBranch)
					{
						instructions.push_back(ir::PTXInstruction(
							ir::PTXInstruction::Bra));
						instructions.back().pc = instructions.size() - 1;
					}
				}
			}
		}
	}
	
	report(" Updating branch targets");
	unsigned int pc = 0;
	for(BlockVector::const_iterator block = blocks.begin();
		block != blocks.end(); ++block)
	{
		for(ir::ControlFlowGraph::InstructionList::iterator 
			instruction = (*block)->instructions.begin();
			instruction != (*block)->instructions.end(); ++instruction, ++pc)
		{
			const ir::PTXInstruction& ptx = static_cast<
				const ir::PTXInstruction&>(**instruction);
			if(ptx.opcode == ir::PTXInstruction::Bra)
			{
				IdToPCMap::const_iterator target = pcs.find(
					(*block)->get_branch_edge()->tail->id);
				assert(target != pcs.end());
				
				report("  setting branch target of '" << ptx.toString()
					<< "' to " << target->second);
				
				instructions[pc].branchTargetInstruction = target->second;
				
				ir::ControlFlowGraph::const_iterator firstBlock = k.end();
				
				// set the reconverge point to the first block in the frontier
				if(firstBlock != k.end())
				{
					IdToPCMap::const_iterator target = pcs.find(firstBlock->id);
					assert(target != pcs.end());
					instructions[pc].reconvergeInstruction = target->second;
				}
			}
		}
	}
}

void ThreadFrontierReconvergencePass::finalize()
{

}

}

#endif

