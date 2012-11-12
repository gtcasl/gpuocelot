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

#define REPORT_BASE 1
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
		report("   checking " << instruction->i->toString());
		propagateValueToSuccessors(dfg, blocks, instruction);

		if(canRemoveInstruction(block, instruction))
		{
			report("    value is not used, removed it.");
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

		if(operands[i]->isRegister() && operands[i]->type == ir::PTXOperand::pred)
		{
			if(operands[i]->condition == ir::PTXOperand::PT ||
				operands[i]->condition == ir::PTXOperand::nPT)
			{
				continue;
			}
		}

		if(operands[i]->addressMode != ir::PTXOperand::Immediate)
		{
			report("    operand " << operands[i]->toString()
				<< " is not constant.");
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
		
		int offset = 0;
		
		if(operand->addressMode == ir::PTXOperand::Indirect)
		{
			offset = operand->offset;
		}
	
		*operand = immediate;
		
		operand->imm_uint += offset;
	}
}

static uint64_t getMask(const ir::PTXOperand& operand)
{
	uint64_t mask = (1ULL << (operand.bytes() * 8)) - 1;

	if(mask == 0) mask = 0xffffffffffffffffULL;

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

static ir::PTXOperand computeCvtValue(const ir::PTXInstruction& ptx);
static ir::PTXOperand computeSetPValue(const ir::PTXInstruction& ptx);

static bool computeValue(ir::PTXOperand& result, const ir::PTXInstruction& ptx)
{
	result = ir::PTXOperand(ir::PTXOperand::Immediate, ptx.d.type);

	switch(ptx.opcode)
	{
	case ir::PTXInstruction::Add:
	{
		uint64_t a = getValue(ptx.a);
		uint64_t b = getValue(ptx.b);

		setValue(result, a + b);
		break;
	}
	case ir::PTXInstruction::And:
	{
		uint64_t a = getValue(ptx.a);
		uint64_t b = getValue(ptx.b);

		setValue(result, a & b);
		break;
	}
	case ir::PTXInstruction::Cvt:
	{
		result = computeCvtValue(ptx);
		break;
	}
	case ir::PTXInstruction::Mov:
	{
		setValue(result, getValue(ptx.a));
		break;
	}
	case ir::PTXInstruction::Mul:
	{
		uint64_t a = getValue(ptx.a);
		uint64_t b = getValue(ptx.b);

		assertM(ptx.modifier & ir::PTXInstruction::Lo,
			"Multiply modifier not implemented.");

		setValue(result, a * b);
		break;
	}
	case ir::PTXInstruction::SetP:
	{
		result = computeSetPValue(ptx);
		break;
	}
	case ir::PTXInstruction::Shr:
	{
		uint64_t a = getValue(ptx.a);
		uint64_t b = getValue(ptx.b);

		setValue(result, a >> b);
		break;
	}
	default:
	{
		return false;
	}
	}

	return true;
}

static void propagateValueToSuccessors(analysis::DataflowGraph& dfg,
	BlockSet& blocks, InstructionVector::iterator instruction)
{
	typedef analysis::DataflowGraph::RegisterPointerVector RegisterPointerVector;

	if(!isOutputConstant(instruction))
	{
		report("    output is not constant.");
		return;
	}
	
	auto ptx = static_cast<ir::PTXInstruction*>(instruction->i);
	
	if(ptx->isLoad())
	{
		report("    not allowed for loads.");
		return;
	}

	// TODO support instructions with multiple destinations
	if(instruction->d.size() != 1)
	{
		report("    no support for instructions with multiple destinations.");
		return;
	}

	// get the value 	
	ir::PTXOperand value;

	bool success = computeValue(value, *ptx);

	if(!success)
	{
		report("    could not determine the resulting value.");
		return;
	}

	// send it to successors	
	auto registerId = *instruction->d.back().pointer;

	auto block = instruction->block;

	for(auto instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction)
	{
		auto ptx = static_cast<ir::PTXInstruction*>(instruction->i);
	
		RegisterPointerVector newSources;
	
		for(auto source = instruction->s.begin(); source !=
			instruction->s.end(); ++source)
		{
			if(*source->pointer == registerId)
			{
				report("    updated use by '" << ptx->toString()
					<< "', of r" << registerId); 
		
				replaceOperand(*ptx, registerId, value);
			}
			else
			{
				newSources.push_back(*source);
			}
		}

		instruction->s = std::move(newSources);
	}

	// TODO handle successors in other blocks
}

static bool isTrivialCvt(const ir::PTXInstruction& ptx)
{
	if(ptx.a.type == ptx.type) return true;

	if(ptx.modifier != 0) return false; 

	if(ir::PTXOperand::isInt(ptx.type))
	{
		if(ir::PTXOperand::isInt(ptx.type))
		{
			if(ir::PTXOperand::bytes(ptx.type) <=
				ir::PTXOperand::bytes(ptx.a.type))
			{
				return true;
			}
			
			if(!ir::PTXOperand::isSigned(ptx.type) &&
				!ir::PTXOperand::isSigned(ptx.a.type))
			{
				return true;
			}
		}
	}

	return false;
}

static ir::PTXOperand computeCvtValue(const ir::PTXInstruction& ptx)
{
	ir::PTXOperand result(ir::PTXOperand::Immediate, ptx.d.type);

	if(isTrivialCvt(ptx))
	{
		setValue(result, getValue(ptx.a));
	}

	return result;
}

static ir::PTXOperand computeSetPValue(const ir::PTXInstruction& ptx)
{
	ir::PTXOperand result(ir::PTXOperand::Immediate, ptx.d.type);

	uint64_t a = getValue(ptx.a);
	uint64_t b = getValue(ptx.b);

	switch(ptx.comparisonOperator)
	{
	case ir::PTXInstruction::Eq:
	{
		setValue(result, a == b);
		break;
	}
	default:
	{
		assertM(false, "Not implemented.");
	}
	}

	return result;
}

}

