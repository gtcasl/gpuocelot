/*! \file   ConvertPredicationToControlFlowPass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Saturday December 3, 2011
	\brief  The source file for the ConvertPredicationToControlFlowPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/ConvertPredicationToControlFlowPass.h>

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/IRKernel.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace transforms
{

ConvertPredicationToControlFlowPass::ConvertPredicationToControlFlowPass()
: KernelPass(analysis::Analysis::NoAnalysis,
	"ConvertPredicationToControlFlowPass")
{

}

void ConvertPredicationToControlFlowPass::initialize(const ir::Module& m)
{

}

static void invert(ir::PTXOperand::PredicateCondition& c)
{
	switch(c)
	{
	case ir::PTXOperand::PT:      c = ir::PTXOperand::nPT;     break;
	case ir::PTXOperand::nPT:     c = ir::PTXOperand::PT;      break;
	case ir::PTXOperand::Pred:    c = ir::PTXOperand::InvPred; break;
	case ir::PTXOperand::InvPred: c = ir::PTXOperand::Pred;    break;
	}
}

static void removePredicates(ir::ControlFlowGraph& cfg,
	ir::ControlFlowGraph::iterator block)
{
	ir::ControlFlowGraph::iterator nextBlock = block;
	
	while(nextBlock != cfg.end())
	{
		block = nextBlock;
		nextBlock = cfg.end();

		for(auto instruction = block->instructions.begin();
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx =
				static_cast<ir::PTXInstruction&>(**instruction);
		
			if(ptx.opcode == ir::PTXInstruction::Bra)  continue;
			if(ptx.pg.condition == ir::PTXOperand::PT) continue;
			
			report("  splitting BB_" << block->id);
			
			// a split is needed
			unsigned int end = std::distance(instruction,
				block->instructions.end());
				
			ir::PTXOperand predicate = ptx.pg;
			ptx.pg.condition = ir::PTXOperand::PT;
						
			// determine if the entire block should be predicated 
			auto endOfNewBlock = instruction;
			for(++endOfNewBlock;
				endOfNewBlock != block->instructions.end(); ++endOfNewBlock)
			{
				ir::PTXInstruction& potentialEnd =
					static_cast<ir::PTXInstruction&>(**endOfNewBlock);
			
				if(potentialEnd.pg.condition != predicate.condition)
				{
					end = std::distance(instruction, endOfNewBlock);
					potentialEnd.pg.condition = ir::PTXOperand::PT;
					break;
				}
				
				if((potentialEnd.pg.condition == ir::PTXOperand::Pred ||
					potentialEnd.pg.condition == ir::PTXOperand::InvPred) &&
					potentialEnd.pg.reg != predicate.reg)
				{
					end = std::distance(instruction, endOfNewBlock);
					potentialEnd.pg.condition = ir::PTXOperand::PT;
					break;
				}
			}
			
			if(end == std::distance(instruction, block->instructions.end()))
			{
				// if all remaining instructions are predicated
				// the branch jumps to the fallthrough target
				ir::ControlFlowGraph::iterator target = cfg.split_block(block,
					std::distance(block->instructions.begin(), instruction),
					ir::Edge::FallThrough);

				report("  into BB_" << target->id << " ("
					<< target->instructions.size() << " instructions)");
			
				ir::PTXInstruction* branch = new ir::PTXInstruction(
					ir::PTXInstruction::Bra);
					
				branch->pg = predicate;
				invert(branch->pg.condition);
				
				branch->d.addressMode = ir::PTXOperand::Label;
				
				block->instructions.push_back(branch);
				
				cfg.insert_edge(ir::Edge(block,
					target->get_fallthrough_edge()->tail, ir::Edge::Branch));
			}
			else
			{
				// if only some instructions are predicated,
				// two splits are needed
				ir::ControlFlowGraph::iterator hammock = cfg.split_block(block,
					std::distance(block->instructions.begin(), instruction),
					ir::Edge::FallThrough);
				
				nextBlock = cfg.split_block(hammock, end,
					ir::Edge::FallThrough);

				report("  into BB_" << hammock->id << " ("
					<< hammock->instructions.size() << " instructions)"
					<< " and BB_" << nextBlock->id << " ("
					<< nextBlock->instructions.size() << " instructions)");

				ir::PTXInstruction* branch = new ir::PTXInstruction(
					ir::PTXInstruction::Bra);
					
				branch->pg = predicate;
				invert(branch->pg.condition);
				
				branch->d.addressMode = ir::PTXOperand::Label;
				
				block->instructions.push_back(branch);
				
				cfg.insert_edge(ir::Edge(block, nextBlock, ir::Edge::Branch));
			}
			
			break;
		}
		
	}
}

void ConvertPredicationToControlFlowPass::runOnKernel(ir::IRKernel& k)
{
	report("Removing predicates from kernel " << k.name);
	for(auto block = k.cfg()->begin(); block != k.cfg()->end(); ++block)
	{
		report(" Removing predicates from basic block BB_" << block->id);
		removePredicates(*k.cfg(), block);
	}
}

void ConvertPredicationToControlFlowPass::finalize()
{

}

}


