/*! \file   GlobalValueNumberingPass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Tuesday July 10, 2012
	\brief  The source file for the GlobalValueNumberingPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/GlobalValueNumberingPass.h>

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/DominatorTree.h>

#include <ocelot/ir/interface/IRKernel.h>

// Hydrazine Includes
#include <hydrazine/interface/debug.h>

// Standard Library Includes
#include <cassert>
#include <stack>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace transforms
{


GlobalValueNumberingPass::GlobalValueNumberingPass()
:  KernelPass(Analysis::DataflowGraphAnalysis |
	Analysis::DominatorTreeAnalysis, "GlobalValueNumberingPass")
{

}

void GlobalValueNumberingPass::initialize(const ir::Module& m)
{
	
}

void GlobalValueNumberingPass::runOnKernel(ir::IRKernel& k)
{
	report("Running GlobalValueNumberingPass on '" << k.name << "'");
	
	#if 0
	// identify identical values
	bool changed = true;
	
	//  iterate until there is no change
	while(changed)
	{
		changed = _numberThenMergeIdenticalValues(k);
	}
	#endif
	// convert to and out of SSA, this renumbers registers
	auto analysis = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(analysis != 0);
	
	auto dfg = static_cast<analysis::DataflowGraph*>(analysis);

	if(dfg->ssa() == analysis::DataflowGraph::None)
	{
		dfg->toSsa();
	}
	
	assert(dfg->ssa() != analysis::DataflowGraph::None);
	
	dfg->fromSsa();
	
	invalidateAnalysis(Analysis::StaticSingleAssignment);
	invalidateAnalysis(Analysis::DataflowGraphAnalysis);
}

void GlobalValueNumberingPass::finalize()
{
	
}

bool GlobalValueNumberingPass::_numberThenMergeIdenticalValues(ir::IRKernel& k)
{
	report(" Starting new iteration.");
	
	// Depth first traversal of the dominator tree
	auto depthFirstTraversal = _depthFirstTraversal(k);
	
	report(" Walking blocks depth first along the dominator tree.");

	bool changed = false;
	for(auto block = depthFirstTraversal.begin();
		block != depthFirstTraversal.end(); ++block)
	{
		changed |= _processBlock(*block);
	}
	
	// Resets the state after processing all blocks
	_clearValueAssignments();
	
	return changed;
}

analysis::DataflowGraph::BlockPointerVector
	GlobalValueNumberingPass::_depthFirstTraversal(ir::IRKernel& k)
{
	typedef std::stack<analysis::DataflowGraph::iterator>         BlockStack;
	typedef std::unordered_set<analysis::DataflowGraph::iterator> BlockSet;	
	typedef analysis::DataflowGraph::BlockPointerVector           BlockVector;

	auto analysis = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(analysis != 0);
	
	auto dfg = static_cast<analysis::DataflowGraph*>(analysis);

	analysis = getAnalysis(Analysis::DominatorTreeAnalysis);
	assert(analysis != 0);
	
	auto domTree = static_cast<analysis::DominatorTree*>(analysis);

	BlockStack  dfsStack;
	BlockSet    visited;
	BlockVector blocks;
	
	dfsStack.push(dfg->begin());
	visited.insert(dfg->begin());
	
	auto cfgToDfgMap = dfg->getCFGtoDFGMap();
	
	while(!dfsStack.empty())
	{
		auto current = dfsStack.top();
		dfsStack.pop();
				
		blocks.push_back(current);
		
		auto dominated = domTree->getDominatedBlocks(current->block());
		
		for(auto block = dominated.begin(); block != dominated.end(); ++block)
		{
			auto dfgBlock = cfgToDfgMap.find(*block);
			assert(dfgBlock != cfgToDfgMap.end());
			
			if(visited.insert(dfgBlock->second).second)
			{
				dfsStack.push(dfgBlock->second);
			}
		}
	}
	
	return blocks;
}

bool GlobalValueNumberingPass::_processBlock(const BlockIterator& block)
{
	report("  Processing block '" << block->label() << "'");

	bool changed = false;
	
	for(auto instruction = block->instructions().begin();
		instruction != block->instructions().end(); ++instruction)
	{
		changed |= _processInstruction(instruction);
	}
	
	_processEliminatedInstructions();
	
	return changed;
}

bool GlobalValueNumberingPass::_processInstruction(
	const InstructionIterator& instruction)
{
	auto ptx = static_cast<ir::PTXInstruction*>(instruction->i);
	
	report("   Processing instruction '" << ptx->toString() << "'");

	// TODO attempt to simplify the instruction
	
	// handle loads (complex)
	if(ptx->isLoad()) return _processLoad(instruction);
	
	Number nextNumber = _getNextNumber();
	Number number     = _lookupExistingOrCreateNewNumber(instruction);
	
	// if a new number was created, just insert it
	if(nextNumber <= number)
	{
		report("    this instruction generates the number.");
		_setGeneratingInstruction(number, instruction);
		return false;
	}
	
	// try to find a generating instruction that dominates this one
	auto generatingInstruction = _findGeneratingInstruction(number,
		instruction);
	
	report("    finding a dominating instruction that "
		"generates the same number.");
	if(generatingInstruction == instruction->block->instructions().end())
	{
		// None exists, set this one in case another instruction is
		//  dominated by it
		_setGeneratingInstruction(number, instruction);

		report("     couldn't find one...");
		
		return false;
	}
	
	report("     found " << generatingInstruction->i->toString());
	
	// Success, eliminate the instruction
	_eliminateInstruction(generatingInstruction, instruction);
	
	return true;
}

bool GlobalValueNumberingPass::_processLoad(
	const InstructionIterator& instruction)
{
	// TODO implement this
	return false;
}

GlobalValueNumberingPass::Number GlobalValueNumberingPass::_getNextNumber()
{
	return _nextNumber;
}

GlobalValueNumberingPass::Number
	GlobalValueNumberingPass::_lookupExistingOrCreateNewNumber(
		const InstructionIterator& instruction)
{
	// Ignore instructions with multiple or no defs
	if(instruction->d.size() != 1) return InvalidNumber;
	
	// number the expression
	auto expression = _createExpression(instruction);
	
	auto numberedExpression = _numberedExpressions.find(expression);

	if(numberedExpression != _numberedExpressions.end())
	{
		return numberedExpression->second;
	}

	report("    assigning number " << _nextNumber
		<< " to instruction '" << instruction->i->toString()
		<< "', register r" << *instruction->d.back().pointer << "");

	_numberedExpressions.insert(std::make_pair(expression, _nextNumber));
	
	// number the generated value
	_numberedValues.insert(std::make_pair(
		*instruction->d.back().pointer, _nextNumber));
	
	return _nextNumber++;
}

GlobalValueNumberingPass::Number
	GlobalValueNumberingPass::_lookupExistingOrCreateNewNumber(
		const ir::PTXOperand& operand)
{
	if(operand.isRegister())
	{
		auto value = _numberedValues.find(operand.reg);
		
		if(value != _numberedValues.end())
		{
			return value->second;
		}
	}
	else if(operand.addressMode == ir::PTXOperand::Immediate)
	{
		auto immediate = _createImmediate(operand);
	
		auto value = _numberedImmediates.find(immediate);
		
		if(value != _numberedImmediates.end())
		{
			return value->second;
		}
		
		_numberedImmediates.insert(std::make_pair(immediate, _nextNumber));
		
		++_nextNumber;
	}

	// TODO handle other types of operands
	
	return InvalidNumber;
}

void GlobalValueNumberingPass::_setGeneratingInstruction(Number n,
	const InstructionIterator& instruction)
{
	auto generatingInstructionList = _generatingInstructions.find(n);
	
	if(generatingInstructionList == _generatingInstructions.end())
	{
		generatingInstructionList = _generatingInstructions.insert(
			std::make_pair(n, GeneratingInstructionList())).first;
	}
	
	generatingInstructionList->second.push_back(
		GeneratingInstruction(instruction));
}

GlobalValueNumberingPass::InstructionIterator
	GlobalValueNumberingPass::_findGeneratingInstruction(
	Number n, const InstructionIterator& instruction)
{
	auto generatingInstructionList = _generatingInstructions.find(n);
	
	if(generatingInstructionList == _generatingInstructions.end())
	{
		return instruction->block->instructions().end();
	}
	
	auto analysis = getAnalysis(Analysis::DominatorTreeAnalysis);
	assert(analysis != 0);
	
	auto dominatorTree = static_cast<analysis::DominatorTree*>(analysis);
	
	for(auto generatingInstruction = generatingInstructionList->second.begin();
		generatingInstruction != generatingInstructionList->second.end();
		++generatingInstruction)
	{
		if(dominatorTree->dominates(
			generatingInstruction->instruction->block->block(),
			instruction->block->block()))
		{
			return generatingInstruction->instruction;
		}
	}
	
	return instruction->block->instructions().end();
}

void GlobalValueNumberingPass::_eliminateInstruction(
	const InstructionIterator& generatingInstruction,
	const InstructionIterator& instruction)
{
	assert(generatingInstruction->d.size() == instruction->d.size());

	report("    eliminating the instruction...");

	// Replace all of the uses with the generated value
	for(auto generatedValue = generatingInstruction->d.begin(),
		replacedValue = instruction->d.begin();
		generatedValue != generatingInstruction->d.end();
		++generatedValue, ++replacedValue)
	{
		report("    replacing all uses of value r" << *replacedValue->pointer);

		for(auto use = instruction->uses.begin();
			use != instruction->uses.end(); ++use)
		{
			auto usedValue = (*use)->s.end();
		
			report("     checking " << (*use)->i->toString());

			for(auto potentiallyUsedValue = (*use)->s.begin();
				potentiallyUsedValue != (*use)->s.end(); ++potentiallyUsedValue)
			{
				if(*potentiallyUsedValue->pointer == *replacedValue->pointer)
				{
					usedValue = potentiallyUsedValue;
					break;
				}
			}
			
			// TODO fix this when we actually handle SSA
			if(usedValue != (*use)->s.end())
			{
				assertM(usedValue != (*use)->s.end(),
					"Invalid def-use chain, no uses of r"
					<< *replacedValue->pointer);
			
				*usedValue->pointer = *generatedValue->pointer;
			}
		}
	}
	
	instruction->uses.clear();
	
	// Add the instruction to the pool of deleted
	_eliminatedInstructions.push_back(instruction);
}

GlobalValueNumberingPass::Expression
	GlobalValueNumberingPass::_createExpression(
	const InstructionIterator& instruction)
{
	auto ptx = static_cast<ir::PTXInstruction&>(*instruction->i);

	Expression expression(ptx.opcode, ptx.type);

	ir::PTXOperand* sources[] = { &ptx.pg, &ptx.a, &ptx.b, &ptx.c, &ptx.d };
	unsigned int limit = ptx.opcode == ir::PTXInstruction::St ? 5 : 4;
	
	unsigned int argumentId = 0;
	for(unsigned int i = 0; i < limit; ++i)
	{
		if(sources[i]->addressMode == ir::PTXOperand::Invalid) continue;

		expression.arguments[argumentId++] =
			_lookupExistingOrCreateNewNumber(*sources[i]);
	}

	// TODO sort arguments to commutative instructions

	return expression;
}

GlobalValueNumberingPass::Immediate GlobalValueNumberingPass::_createImmediate(
	const ir::PTXOperand& operand)
{
	assert(operand.addressMode == ir::PTXOperand::Immediate);

	return Immediate(operand.type, operand.imm_uint);
}
	

void GlobalValueNumberingPass::_processEliminatedInstructions()
{
	auto analysis = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(analysis != 0);
	
	auto dfg = static_cast<analysis::DataflowGraph*>(analysis);

	for(auto killed = _eliminatedInstructions.begin();
		killed != _eliminatedInstructions.end(); ++killed)
	{
		dfg->erase(*killed);
	}

	_eliminatedInstructions.clear();
}

void GlobalValueNumberingPass::_clearValueAssignments()
{
	_numberedValues.clear();
	_numberedExpressions.clear();
	_numberedImmediates.clear();
	_nextNumber = 0;
	_generatingInstructions.clear();
}

GlobalValueNumberingPass::Expression::Expression(ir::PTXInstruction::Opcode o,
	ir::PTXOperand::DataType t)
: opcode(o), type(t)
{
	for(unsigned int i = 0; i < 5; ++i)
	{
		arguments[i] = UnsetNumber;
	}
}

bool GlobalValueNumberingPass::Expression::operator==(const Expression& e) const
{
	return opcode == e.opcode && type == e.type &&
		(arguments[0] == e.arguments[0] && arguments[0] != InvalidNumber ) &&
		(arguments[1] == e.arguments[1] && arguments[1] != InvalidNumber ) &&
		(arguments[2] == e.arguments[2] && arguments[2] != InvalidNumber ) &&
		(arguments[3] == e.arguments[3] && arguments[3] != InvalidNumber ) &&
		(arguments[4] == e.arguments[4] && arguments[4] != InvalidNumber );
}

GlobalValueNumberingPass::GeneratingInstruction::GeneratingInstruction(
	const InstructionIterator& it)
: instruction(it)
{
	
}

GlobalValueNumberingPass::Immediate::Immediate(
	ir::PTXOperand::DataType t, ir::PTXU64 v)
: type(t), value(v)
{

}

bool GlobalValueNumberingPass::Immediate::operator==(const Immediate& imm) const
{
	return type == imm.type && value == imm.value;
}


}

