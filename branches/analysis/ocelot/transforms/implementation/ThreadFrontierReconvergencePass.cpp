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

#include <ocelot/ir/interface/IRKernel.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Standard Library Includes
#include <map>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

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
		std::greater<Priority>> ReversePriorityMap;
	typedef std::vector<ir::ControlFlowGraph::const_iterator> BlockVector;
	typedef analysis::ThreadFrontierAnalysis TFAnalysis;

	Analysis* analysis = getAnalysis(Analysis::ThreadFrontierAnalysis);
	assert(analysis != 0);
	
	TFAnalysis* tfAnalysis = static_cast<TFAnalysis*>(analysis);

	ReversePriorityMap priorityToBlocks;
	
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
		blocks.push_back(priorityAndBlock->second);
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
				if(!ptx.isBranch() && (*block)->has_fallthrough_edge())
				{
					// if the original layout assumed a fallthrough, but the
					//  priority changed it, we need a branch
					bool needsBranch = false;
					if(block != --blocks.end())
					{
						BlockVector::const_iterator next = block;
						++next;
						
						needsBranch = (*next)->id !=
							(*block)->get_fallthrough_edge()->tail->id;
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
		for(ir::ControlFlowGraph::InstructionList::const_iterator 
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
				
				ir::ControlFlowGraph::const_iterator firstBlock =
					k.cfg()->end();
				
				TFAnalysis::BlockVector frontier =
					tfAnalysis->getThreadFrontier(*block);
				
				TFAnalysis::Priority highest = 0;
				
				if(_gen6)
				{
					// gen6 re-converges at the block with the highest priority
					for(TFAnalysis::BlockVector::const_iterator
						stalledBlock = frontier.begin();
						stalledBlock != frontier.end(); ++stalledBlock)
					{
						TFAnalysis::Priority priority =
							tfAnalysis->getPriority(*stalledBlock);
						if(priority >= highest)
						{
							highest    = priority;
							firstBlock = *stalledBlock;
						}
					}
				}
				else
				{
					assertM(false, "Not implemented.");
				}
				
				// set the reconverge point to the first block in the frontier
				if(firstBlock != k.cfg()->end())
				{
					IdToPCMap::const_iterator target = pcs.find(firstBlock->id);
					assert(target != pcs.end());
					instructions[pc].reconvergeInstruction = target->second;
					report("   re-converge point "  << target->second);
				}
				else
				{
					// if there is no TF, set it to the target
					instructions[pc].reconvergeInstruction = target->second;
					report("   re-converge point "  << target->second);
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

