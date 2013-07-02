/*! \file   MIMDThreadSchedulingPass.cpp
	\date   Friday February 18, 2011
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The source file for the MIMDThreadSchedulingPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/MIMDThreadSchedulingPass.h>

#include <ocelot/ir/interface/PTXKernel.h>

#include <ocelot/analysis/interface/CycleAnalysis.h>
#include <ocelot/analysis/interface/DependenceAnalysis.h>

// Standard Library Includes
#include <unordered_set>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace transforms
{

MIMDThreadSchedulingPass::MIMDThreadSchedulingPass()
: KernelPass({"DependenceAnalysis", "CycleAnalysis"}, 
		"MIMDThreadSchedulingPass")
{

}

typedef ir::PTXInstruction PTXInstruction;
typedef std::unordered_set<PTXInstruction*> InstructionSet;

static InstructionSet getBackwardsBranches(analysis::CycleAnalysis* c);
static InstructionSet getInstructionsThatCanObserveSideEffects(ir::IRKernel& k);
static InstructionSet getBranchesThatDependOn(const InstructionSet& branches,
	const InstructionSet& instructions, analysis::DependenceAnalysis*);

static InstructionSet getCallsToFuctionsThatObserveSideEffects(ir::IRKernel& k);
static void insertYieldsBefore(ir::IRKernel& k,
	const InstructionSet& instructions);
	
void MIMDThreadSchedulingPass::runOnKernel(ir::IRKernel& k)
{
	report("Discovering branches that require scheduler yields.");
	
	// Get analyses
	auto cycleAnalysis = static_cast<analysis::CycleAnalysis*>(
		getAnalysis("CycleAnalysis"));
	auto dependenceAnalysis = static_cast<analysis::DependenceAnalysis*>(
		getAnalysis("DependenceAnalysis"));

	// Discover branches that require yields
	auto backwardsBranches = getBackwardsBranches(cycleAnalysis);
	
	auto instructionsThatCanObserveSideEffects =
		getInstructionsThatCanObserveSideEffects(k);
	
	auto branchesThatRequireYields = getBranchesThatDependOn(
		backwardsBranches, instructionsThatCanObserveSideEffects,
		dependenceAnalysis);

	auto functionCallsThatRequireYields =
		getCallsToFuctionsThatObserveSideEffects(k);

	// Insert yields before branches
	report(" Found the following instructions ("
		<< branchesThatRequireYields.size() << " branches) ("
		<< functionCallsThatRequireYields.size() << " function calls):");
	insertYieldsBefore(k, branchesThatRequireYields     );
	insertYieldsBefore(k, functionCallsThatRequireYields);
}

static InstructionSet getBackwardsBranches(
	analysis::CycleAnalysis* cycleAnalysis)
{
	auto edges = cycleAnalysis->getAllBackEdges();
	
	report(" Getting backwards branches");
	
	InstructionSet backwardsBranches;
	
	for(auto& edge : edges)
	{
		if(edge->type != ir::Edge::Branch) continue;
		
		auto block = edge->head;
		
		assert(!block->instructions.empty());
		
		auto ptxBranch = static_cast<ir::PTXInstruction*>(
			block->instructions.back());
		
		assert(ptxBranch->isBranch());
		
		report("  " << ptxBranch->toString());
				
		backwardsBranches.insert(ptxBranch);
	}
	
	return backwardsBranches;
}

static InstructionSet getInstructionsThatCanObserveSideEffects(ir::IRKernel& k)
{
	InstructionSet instructions;
	
	report(" Getting instructions that can observe side-effects");
	
	for(auto& block : *k.cfg())
	{
		for(auto instruction : block.instructions)
		{
			auto ptxInstruction = static_cast<ir::PTXInstruction*>(instruction);
		
			if(ptxInstruction->canObserveSideEffects())
			{
				report("  " << ptxInstruction->toString());
				
				instructions.insert(ptxInstruction);
			}
		}
	}
	
	return instructions;
}

static InstructionSet getBranchesThatDependOn(const InstructionSet& branches,
	const InstructionSet& instructions,
	analysis::DependenceAnalysis* dependenceAnalysis)
{
	InstructionSet dependentBranches;
	
	for(auto branch : branches)
	{
		for(auto instruction : instructions)
		{
			if(dependenceAnalysis->dependsOn(branch, instruction))
			{
				dependentBranches.insert(branch);
				break;
			}
		}
	}
	
	return dependentBranches;
}

static InstructionSet getCallsToFuctionsThatObserveSideEffects(ir::IRKernel& k)
{
	InstructionSet instructions;

	for(auto& block : *k.cfg())
	{
		for(auto instruction : block.instructions)
		{
			auto ptxInstruction = static_cast<ir::PTXInstruction*>(instruction);
		
			// TODO: Check that the target can observe side effects
			if(ptxInstruction->isCall())
			{
				instructions.insert(ptxInstruction);
			}
		}
	}
	
	return instructions;
}

typedef ir::ControlFlowGraph::iterator iterator;
typedef std::unordered_map<PTXInstruction*, iterator> InstructionToBlocks;

static InstructionToBlocks getBlocks(ir::IRKernel& k)
{
	InstructionToBlocks blocks;
	
	for(auto block = k.cfg()->begin(); block != k.cfg()->end(); ++block)
	{
		for(auto instruction : block->instructions)
		{
			auto ptx = static_cast<PTXInstruction*>(instruction);
		
			blocks.insert(std::make_pair(ptx, block));
		}
	}
	
	return blocks;
}

typedef ir::BasicBlock::instruction_iterator instruction_iterator;

static instruction_iterator getIterator(iterator block,
	const PTXInstruction* ptx)
{
	for(auto instruction = block->instructions.begin();
		instruction != block->instructions.end(); ++instruction)
	{
		if(*instruction == ptx) return instruction;
	}
	
	return block->instructions.end();
}

typedef ir::PTXOperand PTXOperand;

static void insertYield(iterator block, instruction_iterator position)
{
	PTXInstruction* yield = new PTXInstruction(PTXInstruction::Call);

	yield->a = PTXOperand("_Zintrinsic_yield");

	block->instructions.insert(position, yield);
}

static void insertYieldsBefore(ir::IRKernel& k, const InstructionSet& branches)
{
	auto blocks = getBlocks(k);
	
	for(auto branch : branches)
	{
		auto block = blocks.find(branch);
		assert(block != blocks.end());
	
		auto position = getIterator(block->second, branch);
		
		report("  " << branch->toString());
		
		insertYield(block->second, position);
	}
}

}


