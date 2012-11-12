/*!	\file   ConstantPropagationPass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Friday November 9, 2012
	\brief  The header file for the ConstantPropagationPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/ConstantPropagationPass.h>

#include <ocelot/analysis/interface/DataflowGraph.h>

#include <ocelot/ir/interface/IRKernel.h>

// Hydrazine Includes
#include <hydrazine/interface/debug.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define REPORT_PTX  0

namespace transforms
{

ConstantPropagationPass::ConstantPropagationPass()
: KernelPass(Analysis::DataflowGraphAnalysis
	| Analysis::StaticSingleAssignment, "ConstantPropagationPass")
{

}

typedef analysis::DataflowGraph::iterator iterator;
typedef std::unordered_set<iterator>      BlockSet;

static void eliminateRedundantInstructions(analysis::DataflowGraph& dfg,
	BlockSet& blocks, iterator block);

void ConstantPropagationPass::runOnKernel(ir::IRKernel& k)
{
	report("Running constant propagation on kernel " << k.name);
	
	Analysis* dfgAnalysis = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(dfgAnalysis != 0);
	
	analysis::DataflowGraph& dfg =
		*static_cast<analysis::DataflowGraph*>(dfgAnalysis);
	
	assert(dfg.ssa() != analysis::DataflowGraph::SsaType::None);
	
	BlockSet blocks;
	
	report(" Starting by scanning all basic blocks");
	
	for(iterator block = dfg.begin(); block != dfg.end(); ++block)
	{
		report("  Queueing up BB_" << block->id());
		blocks.insert(block);
	}
	
	while(!blocks.empty())
	{
		iterator block = *blocks.begin();
		blocks.erase(blocks.begin());
	
		eliminateRedundantInstructions(dfg, blocks, block);
	}
	
	report("Finished running dead code elimination on kernel " << k.name);
	reportE(REPORT_PTX, k);

}


typedef analysis::DataflowGraph::InstructionVector InstructionVector;

static bool canRemoveInstruction(iterator block,
	InstructionVector::iterator instruction);
static void propagateValueToSuccessors(analysis::DataflowGraph& dfg,
	BlockSet& blocks, InstructionVector::iterator instruction);

static void eliminateRedundantInstructions(analysis::DataflowGraph& dfg,
	BlockSet& blocks, iterator block)
{
	typedef std::vector<unsigned int> KillList;
	
	KillList killList;
	
	report("  Propagating constants through instructions");
	unsigned int index = 0;
	for(auto instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction)
	{
		propagateValueToSuccessors(dfg, blocks, instruction);

		if(canRemoveInstruction(block, instruction))
		{
			report("   removed '" << instruction->i->toString() << "'");
			killList.push_back(index);
			
			// schedule the block for more work
			// TODO: do this when we consider values in multiple blocks
		}
		else
		{
			++index;
		}
	}
	
	for(KillList::iterator killed = killList.begin();
		killed != killList.end(); ++killed)
	{
		dfg.erase(block, *killed);
	}
}

static bool canRemoveInstruction(iterator block,
	InstructionVector::iterator instruction)
{
	ir::PTXInstruction& ptx = *static_cast<ir::PTXInstruction*>(
		instruction->i);

	if(ptx.hasSideEffects()) return false;
	
	for(auto reg = instruction->d.begin(); reg != instruction->d.end(); ++reg)
	{
		// the reg is alive outside the block
		if(block->aliveOut().count(*reg) != 0) return false;
		
		auto next = instruction;
		for(++next; next != block->instructions().end(); ++next)
		{
			for(auto source = next->s.begin();
				source != next->s.end(); ++source)
			{
				// found a user in the block
				if(*source->pointer == *reg->pointer) return false;
			}
		}
	}
	
	// There are no users and the instruction has no side effects
	return true;
}

static bool isOutputConstant(InstructionVector::iterator instruction)
{
	auto ptx = static_cast<ir::PTXInstruction*>(instruction->i);

	if(ptx->hasSideEffects()) return false;

	// The output is not constant if there are register inputs
	if(!instruction->s.empty()) return false;

	ir::PTXOperand* operands[] = {&ptx->a, &ptx->b, &ptx->c, &ptx->pg};

	for(unsigned int i = 0; i < 4; ++i)
	{
		if(operands[i]->addressMode == ir::PTXOperand::Invalid) continue;

		if(operands[i]->addressMode != ir::PTXOperand::Immediate)
		{
			return false;
		}
	}

	return true;
}

static void replaceOperand(ir::PTXInstruction& ptx,
	ir::Instruction::RegisterType registerId,
	const ir::PTXOperand& immediate)
{
	ir::PTXOperand* operands[] = {&ptx.a, &ptx.b, &ptx.c, &ptx.pq,
		&ptx.d};

	unsigned int sources = 4;

	if(ptx.isStore()) ++sources;
	
	for(unsigned int i = 0; i < sources; ++i)
	{
		auto operand = operands[i];

		if(!operand->isRegister()) continue;

		if(operand->reg != registerId) continue;

		*operand = immediate;
	}
}

static uint64_t getMask(const ir::PTXOperand& operand)
{
	uint64_t mask = 1ULL << ((operand.bytes() * 8) - 1);

	return mask;
}

static uint64_t getValue(const ir::PTXOperand& operand)
{
	uint64_t value = operand.imm_uint;

	uint64_t mask = getMask(operand);;

	return value & mask;
}

static void setValue(ir::PTXOperand& operand, uint64_t value)
{
	uint64_t mask = getMask(operand);

	operand.imm_uint = value & mask;
}

static ir::PTXOperand computeValue(const ir::PTXInstruction& ptx)
{
	ir::PTXOperand result(ir::PTXOperand::Immediate, ptx.d.type);

	switch(ptx.opcode)
	{
	case ir::PTXInstruction::Add:
	{
		uint64_t a = getValue(ptx.a);
		uint64_t b = getValue(ptx.b);

		setValue(result, a + b);
		break;
	}
	default:
	{
		assertM(false, "Not implemented for " << ptx.toString());
	}
	}

	return result;
}

static void propagateValueToSuccessors(analysis::DataflowGraph& dfg,
	BlockSet& blocks, InstructionVector::iterator instruction)
{
	if(!isOutputConstant(instruction)) return;
	
	// TODO support instructions with multiple destinations
	if(instruction->d.size() != 1) return;
	
	for(auto reg = instruction->d.begin(); reg != instruction->d.end(); ++reg)
	{
		// the reg is alive outside the block
		if(instruction->block->aliveOut().count(*reg) != 0) return;
	}

	auto registerId = *instruction->d.back().pointer;

	auto ptx = static_cast<ir::PTXInstruction*>(instruction->i);

	// get the value 	
	auto value = computeValue(*ptx);

	auto block = instruction->block;

	// send it to all successors
	for(auto instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction)
	{
		auto ptx = static_cast<ir::PTXInstruction*>(instruction->i);
		
		for(auto source = instruction->s.begin(); source !=
			instruction->s.end(); ++source)
		{
			if(*source->pointer == registerId)
			{
				replaceOperand(*ptx, registerId, value);
			}
		}
	}

	// TODO handle successors in other blocks
}

}

