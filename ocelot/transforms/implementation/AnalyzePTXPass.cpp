/*! \file   AnalyzePTXPass.cpp
	\author Gregory Diamos <gdiamos@nvidia.com>
	\date   Monday February 6, 2012
	\brief  The source file for the AnalyzePTXPass
	
*/

// Ocelot Includes
#include <ocelot/transforms/interface/AnalyzePTXPass.h>

#include <ocelot/analysis/interface/DataflowGraph.h>

#include <ocelot/ir/interface/Module.h>

namespace transforms
{

AnalyzePTXPass::AnalyzePTXPass()
: ImmutableKernelPass(Analysis::DataflowGraphAnalysis, "AnalyzePTXPass")
{

}

void AnalyzePTXPass::initialize(const ir::Module& m)
{
	std::cout << "Analyzing module " << m.path() << "...\n";
}

typedef analysis::DataflowGraph::InstructionIteratorList::const_iterator
	const_du_iterator;
typedef analysis::DataflowGraph::const_instruction_iterator
	const_instruction_iterator;

static unsigned int getTotalCycles(const analysis::DataflowGraph::Block& block)
{
	unsigned int cycles = 0;
	
	typedef std::unordered_set<const_instruction_iterator> IntSet;
	typedef std::vector<const_instruction_iterator>        IntVector;
	
	IntSet    unscheduled;
	IntVector canBeScheduled;
	
	for(const_instruction_iterator i = block.instructions().begin();
		i != block.instructions().end(); ++i)
	{
		unscheduled.insert(i);
	}
	
	while(!unscheduled.empty())
	{
		for(IntSet::const_iterator instruction = unscheduled.begin();
			instruction != unscheduled.end(); ++instruction)
		{
			const analysis::DataflowGraph::Instruction& ptx = **instruction;
		
			bool anyUnscheduledUses = false;
			
			for(const_du_iterator use = ptx.uses.begin();
				use != ptx.uses.end(); ++use)
			{
				if(unscheduled.count(*use) != 0)
				{
					anyUnscheduledUses = true;
					break;
				}
			}
			
			if(anyUnscheduledUses) continue;
			
			canBeScheduled.push_back(*instruction);
		}
		
		for(IntVector::const_iterator instruction = canBeScheduled.begin();
			instruction != canBeScheduled.end(); ++instruction)
		{
			IntSet::iterator i = unscheduled.find(*instruction);
			assert(i != unscheduled.end());
			unscheduled.erase(i);
		}
		
		canBeScheduled.clear();
		++cycles;
	}
	
	return cycles;
}

static unsigned int getMoves(const analysis::DataflowGraph::Block& block)
{
	unsigned int moves = 0;
	
	for(const_instruction_iterator i = block.instructions().begin();
		i != block.instructions().end(); ++i)
	{
		moves += i->s.size() + i->d.size();
	}
	
	return moves;
}

static unsigned int getCoalescedMoves(
	const analysis::DataflowGraph::Block& block)
{
	typedef analysis::DataflowGraph::RegisterPointerVector::const_iterator
		const_register_iterator;
	
	unsigned int moves = 0;
	
	typedef std::unordered_set<unsigned int> RegisterSet;

	RegisterSet usedRegisters;
	
	for(const_instruction_iterator i = block.instructions().begin();
		i != block.instructions().end(); ++i)
	{
		for(const_register_iterator s = i->s.begin(); s != i->s.end(); ++s)
		{
			usedRegisters.insert(*s->pointer);
		}
		
		for(const_register_iterator s = i->s.begin(); s != i->s.end(); ++s)
		{
			RegisterSet::iterator current = usedRegisters.find(*s->pointer);
			if(current != usedRegisters.end())
			{
				RegisterSet::iterator left = usedRegisters.find(*s->pointer - 1);
			
				if(left != usedRegisters.end())
				{
					usedRegisters.erase(left);
					usedRegisters.erase(current);
				
					moves += 2;
				}
				else
				{
					RegisterSet::iterator right =
						usedRegisters.find(*s->pointer + 1);
			
					if(right != usedRegisters.end())
					{
						usedRegisters.erase(right);
						usedRegisters.erase(current);
				
						moves += 2;
					}
				}
			}
		}
		
		usedRegisters.clear();
		
		for(const_register_iterator d = i->d.begin(); d != i->d.end(); ++d)
		{
			usedRegisters.insert(*d->pointer);
		}
		
		for(const_register_iterator d = i->d.begin(); d != i->d.end(); ++d)
		{
			RegisterSet::iterator current = usedRegisters.find(*d->pointer);
			if(current != usedRegisters.end())
			{
				RegisterSet::iterator left =
					usedRegisters.find(*d->pointer - 1);
			
				if(left != usedRegisters.end())
				{
					usedRegisters.erase(left);
					usedRegisters.erase(current);
				
					moves += 2;
				}
				else
				{
					RegisterSet::iterator right =
						usedRegisters.find(*d->pointer + 1);
			
					if(right != usedRegisters.end())
					{
						usedRegisters.erase(right);
						usedRegisters.erase(current);
				
						moves += 2;
					}
				}
			}
		}
		
		usedRegisters.clear();
	}
	
	return moves;
}

void AnalyzePTXPass::_analyzeILP(const ir::PTXKernel& ptx)
{
	std::cout << " Analyzing ILP for Kernel " << ptx.name << ":\n";
	
	Analysis* a = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(a != 0);
	
	analysis::DataflowGraph* dfg = static_cast<analysis::DataflowGraph*>(a);
	
	dfg->constructDUChains();
	
	unsigned int totalCycles       = 0;
	unsigned int totalInstructions = 0;
	unsigned int blocks            = 0;
	
	for(analysis::DataflowGraph::const_iterator block = dfg->begin();
		block != dfg->end(); ++block)
	{
		if(block->block() == ptx.cfg()->get_entry_block()) continue;
		if(block->block() == ptx.cfg()->get_exit_block())  continue;
		
		unsigned int cycles       = getTotalCycles(*block);
		unsigned int instructions = block->instructions().size();
		
		std::cout << "  Basic Block " << block->label()
			<< " (" << block->id() << "):\n";
		std::cout << "   Ideal Cycles: " << cycles       << "\n";
		std::cout << "   Instructions: " << instructions << "\n";
		std::cout << "   Ideal IPC:    " 
			<< (instructions / (cycles + 0.0)) << "\n";
		
		totalCycles       += cycles;
		totalInstructions += block->instructions().size();
		++blocks;
	}
	
	std::cout << "\n  Totals:\n";
	std::cout << "   Total Ideal Cycles: " << totalCycles       << "\n";
	std::cout << "   Total Instructions: " << totalInstructions << "\n";
	std::cout << "   Total Blocks:       " << blocks            << "\n";
	std::cout << "   Average Ideal IPC:  " 
		<< (totalInstructions / (totalCycles + 0.0)) << "\n";
}

void AnalyzePTXPass::_analyzeRegisterAlignment(const ir::PTXKernel& ptx)
{
	std::cout << " Analyzing register alignment for Kernel "
		<< ptx.name << ":\n";
	
	Analysis* a = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(a != 0);
	
	analysis::DataflowGraph* dfg = static_cast<analysis::DataflowGraph*>(a);
	
	unsigned int totalMoves          = 0;
	unsigned int totalCoalescedMoves = 0;
	unsigned int blocks              = 0;
	
	for(analysis::DataflowGraph::const_iterator block = dfg->begin();
		block != dfg->end(); ++block)
	{
		if(block->block() == ptx.cfg()->get_entry_block()) continue;
		if(block->block() == ptx.cfg()->get_exit_block())  continue;
		
		unsigned int moves          = getMoves(*block);
		unsigned int coalescedMoves = getCoalescedMoves(*block);
		
		std::cout << "  Basic Block " << block->label()
			<< " (" << block->id() << "):\n";
		std::cout << "   Moves:           " << moves          << "\n";
		std::cout << "   Coalesced Moves: " << coalescedMoves << "\n";
		
		totalMoves       += moves;
		totalCoalescedMoves += coalescedMoves;
		++blocks;
	}
	
	std::cout << "\n  Totals:\n";
	std::cout << "   Total Moves:           " << totalMoves       << "\n";
	std::cout << "   Total Coalesced Moves: " << totalCoalescedMoves << "\n";
	std::cout << "   Average Ratio:         "
		<< ((totalCoalescedMoves + 0.0) / totalMoves) << "\n";
	
}

void AnalyzePTXPass::runOnKernel(const ir::IRKernel& k)
{
	const ir::PTXKernel& ptx = static_cast<const ir::PTXKernel&>(k);

	_analyzeILP(ptx);
	_analyzeRegisterAlignment(ptx);
}

void AnalyzePTXPass::finalize()
{
	// nothing
}

}


