/*! \file   FlattenHyperblockPass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Sunday October 9, 2011
	\brief  The source file for the FlattenHyperblockPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/FlattenHyperblockPass.h>
#include <ocelot/ir/interface/PTXKernel.h>

// Standard Library Includes
#include <cassert>
#include <unordered_set>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace transforms
{

FlattenHyperblockPass::FlattenHyperblockPass()
: KernelPass(analysis::Analysis::HyperblockAnalysis, "FlattenHyperblockPass")
{

}

void FlattenHyperblockPass::initialize(const ir::Module& m)
{
	// do nothing
}

static ir::Instruction::RegisterType getNextRegisterId(ir::IRKernel& k)
{
	auto ptx = static_cast<ir::PTXKernel&>(k);
	
	auto usedRegisters = ptx.getReferencedRegisters();
	
	ir::Instruction::RegisterType id = 0;
	
	for(auto reg = usedRegisters.begin(); reg != usedRegisters.end(); ++reg)
	{
		id = std::max(id, reg->id);
	}
	
	return ++id;
}

void FlattenHyperblockPass::runOnKernel(ir::IRKernel& k)
{
	report("Flattenning hyperblocks in kernel \"" << k.name << "\"");
	
	ir::Instruction::RegisterType nextRegister = getNextRegisterId(k);

	analysis::Analysis* a = getAnalysis(analysis::Analysis::HyperblockAnalysis);

	assert(a != 0);

	analysis::HyperblockAnalysis& hyperblockGraph =
		*static_cast<analysis::HyperblockAnalysis*>(a);
	
	for(auto block = hyperblockGraph.begin();
		block != hyperblockGraph.end(); ++block)
	{
		_flattenBlock(*k.cfg(), nextRegister, block);
	}
	
	invalidateAnalysis(analysis::Analysis::HyperblockAnalysis);
}

void FlattenHyperblockPass::finalize()
{
	// do nothing
}

static void removeAllBranches(ir::ControlFlowGraph::iterator basicBlock)
{
	for(auto instruction = basicBlock->instructions.begin();
		instruction != basicBlock->instructions.end();)
	{
		auto ptx = static_cast<ir::PTXInstruction&>(**instruction);
	
		if(ptx.opcode == ir::PTXInstruction::Bra)
		{
			delete *instruction;
			instruction = basicBlock->instructions.erase(instruction);
		}
		else
		{
			++instruction;
		}
	}
}

static void invert(ir::PTXOperand::PredicateCondition& condition)
{
	switch(condition)
	{
	case ir::PTXOperand::Pred:    condition = ir::PTXOperand::InvPred; break;
	case ir::PTXOperand::InvPred: condition = ir::PTXOperand::Pred;    break;
	case ir::PTXOperand::PT:      condition = ir::PTXOperand::nPT;     break;
	case ir::PTXOperand::nPT:     condition = ir::PTXOperand::PT;      break;
	default: break;
	}
	
}

static FlattenHyperblockPass::PredicateEquation getEquation(
	ir::Instruction::RegisterType& nextRegister,
	ir::ControlFlowGraph::iterator block, bool fallthrough)
{
	typedef FlattenHyperblockPass::PredicateTerm PredicateTerm;
	FlattenHyperblockPass::PredicateEquation equation;
	
	for(auto instruction = block->instructions.rbegin();
		instruction != block->instructions.rend(); ++instruction)
	{
		auto ptx = static_cast<const ir::PTXInstruction&>(**instruction);
		
		if(ptx.isBranch())
		{
			ir::PTXOperand::PredicateCondition condition = ptx.pg.condition;
		
			if(fallthrough)
			{
				report("  Inverting predicate condition");
				invert(condition);
			}
			
			report("  Adding term p" << nextRegister
				<< " to equation from BB_" << block->id);
			equation.terms.push_back(PredicateTerm(ptx.pg.reg,
				condition, PredicateTerm::Invalid));
			
			break;		
		}
	}
	
	return equation;
}

typedef std::unordered_set<ir::ControlFlowGraph::iterator> BlockSet;

static bool wereAllPredecessorsVisited(const BlockSet& visited, 
	ir::ControlFlowGraph::iterator block)
{
	for(auto predecessor = block->predecessors.begin();
		predecessor != block->predecessors.end(); ++predecessor)
	{
		if(visited.count(*predecessor) == 0)
		{
			return false;
		}
	}
	
	return true;
}

static void sinkSideExits(ir::ControlFlowGraph::iterator block)
{
	typedef std::vector<ir::BasicBlock::instruction_iterator> InstructionList;
	
	InstructionList branches;
	
	for(auto instruction = block->instructions.begin();
		instruction != block->instructions.end(); ++instruction)
	{
		auto ptx = static_cast<const ir::PTXInstruction&>(**instruction);
	
		if(ptx.isBranch()) branches.push_back(instruction);
	}
	
	for(auto branch = branches.begin(); branch != branches.end(); ++branch)
	{
		ir::Instruction* instruction = **branch;
		
		block->instructions.erase(*branch);
		block->instructions.push_back(instruction);
	}
}

void FlattenHyperblockPass::_flattenBlock(
	ir::ControlFlowGraph& cfg,
	ir::Instruction::RegisterType& nextRegister,
	analysis::HyperblockAnalysis::iterator block)
{
	typedef std::unordered_map<ir::ControlFlowGraph::iterator,
		PredicateEquation> PredicateEquationMap;
	typedef analysis::HyperblockAnalysis::Block::bb_pointer_iterator
		bb_iterator;
	typedef std::deque<ir::ControlFlowGraph::iterator> BlockList;
	
	report(" Flattening hyperblock starting at basic block "
		<< block->block_begin()->id);
	
	// compute predicate conditions for each basic block
	PredicateEquationMap equations;

	BlockList frontier;
	BlockSet  visited;
	
	report("  Computing predicate equations");

	for(auto bb = block->block_begin(); bb != block->block_end(); ++bb)
	{
		// every block starts with PT
		equations.insert(std::make_pair(*(bb_iterator)bb, PredicateEquation()));
		
		report("   creating equation for BB_" << bb->id);
		
		// queue up every block for visitation
		frontier.push_back(*(bb_iterator) bb);
	}
	
	while(!frontier.empty())
	{
		ir::ControlFlowGraph::iterator currentBlock = frontier.front();
		frontier.pop_front();

		// the entry block does not need a predecessor, nor an equation
		if(currentBlock == *(bb_iterator)block->block_begin())
		{		
			visited.insert(currentBlock);
			continue;
		}
		
		if(!wereAllPredecessorsVisited(visited, currentBlock))
		{
			frontier.push_back(currentBlock);
			continue;
		}

		visited.insert(currentBlock);
		
		report("   computing equation for BB_" << currentBlock->id);
		
		auto equation = equations.find(currentBlock);
		assert(equation != equations.end());
		
		for(auto predecessor = currentBlock->predecessors.begin();
			predecessor != currentBlock->predecessors.end(); ++predecessor)
		{
			auto predecessorEquation = equations.find(*predecessor);
			assert(predecessorEquation != equations.end());
			
			equation->second.mergeEquations(predecessorEquation->second);
			
			bool fallthrough = false;
			
			if((*predecessor)->has_fallthrough_edge())
			{
				fallthrough = currentBlock ==
					(*predecessor)->get_fallthrough_edge()->tail;
			}
			
			equation->second.mergeEquations(
				getEquation(nextRegister, *predecessor, fallthrough));
		}
	}
	
	// predicate each instruction with its condition
	for(auto equation = equations.begin();
		equation != equations.end(); ++equation)
	{
		equation->second.createAndInsertInstructions(nextRegister,
			*equation->first);
	}
	
	// remove branches when all targets are contained in the block
	for(auto bb = block->block_begin(); bb != block->block_end(); ++bb)
	{
		bool allContained = true;
		
		for(auto successor = bb->successors.begin();
			successor != bb->successors.end(); ++successor)
		{
			if(!block->contains(*successor))
			{
				allContained = false;
				break;
			}
		}
		
		if(allContained)
		{
			removeAllBranches(*(bb_iterator)bb);
		}
	}
	
	report("  Merging basic block instruction streams");
	
	// merge basic block instruction lists together
	if(block->basicBlocks() > 1)
	{
		auto entry = block->block_begin();
		auto bb    = entry;
	
		for(++bb; bb != block->block_end(); ++bb)
		{
			entry->instructions.insert(entry->instructions.end(),
				bb->instructions.begin(), bb->instructions.end());
			
			bb->instructions.clear();
			
			// redirect edges that leave the hyperblock to the entry block
			ir::ControlFlowGraph::EdgePointerVector deletedEdges;
			ir::ControlFlowGraph::EdgeList          newEdges;
			
			for(auto edge = bb->out_edges.begin();
				edge != bb->out_edges.end(); ++edge)
			{
				if(!block->contains((*edge)->tail))
				{
					report("  replacing edge from BB_" << (*edge)->head->id
						<< " -> BB_" << (*edge)->tail->id
						<< " with edge from BB_" << entry->id
						<< " -> BB_" << (*edge)->tail->id);

					deletedEdges.push_back(*edge);
					newEdges.push_back(ir::Edge(*(bb_iterator)entry,
						(*edge)->tail, (*edge)->type));
				}
			}
			
			for(auto edge = deletedEdges.begin();
				edge != deletedEdges.end(); ++edge)
			{
				cfg.remove_edge(*edge);
			}
			
			for(auto edge = newEdges.begin(); edge != newEdges.end(); ++edge)
			{
				cfg.insert_edge(*edge);
			}
			
			cfg.remove_block(*(bb_iterator) bb);
		}
	}

	// sink all branches for out-edges to the end of the block
	sinkSideExits(*(bb_iterator)block->block_begin());
}

FlattenHyperblockPass::PredicateTerm::PredicateTerm(
	ir::Instruction::RegisterType r, ir::PTXOperand::PredicateCondition c,
	Operator o)
: reg(r), condition(c), op(o)
{

}

FlattenHyperblockPass::PredicateEquation::PredicateEquation()
{

}

void FlattenHyperblockPass::PredicateEquation::createAndInsertInstructions(
	ir::Instruction::RegisterType& nextRegister, ir::BasicBlock& bb)
{
	if(terms.empty()) return;

	// compute the predicate condition for the block
	// TODO simplify conditions
	auto term = terms.begin();
	PredicateTerm previous = *term;
	
	ir::BasicBlock::InstructionList added;

	report("  Inserting instructions to compute predicates");	
	if(terms.size() > 1)
	{
		for(++term; term != terms.end(); ++term)
		{
			auto setp = new ir::PTXInstruction(ir::PTXInstruction::SetP);
		
			setp->d = ir::PTXOperand(ir::PTXOperand::Register,
				ir::PTXOperand::pred, nextRegister++);
			setp->d.condition = ir::PTXOperand::Pred;
			
			setp->type = ir::PTXOperand::pred;
			
			setp->a = ir::PTXOperand(ir::PTXOperand::Register,
				ir::PTXOperand::pred, previous.reg);
			setp->a.condition = previous.condition;
			setp->b = ir::PTXOperand(ir::PTXOperand::Register,
				ir::PTXOperand::pred);
			setp->b.condition = ir::PTXOperand::PT;
			setp->c = ir::PTXOperand(ir::PTXOperand::Register,
				ir::PTXOperand::pred, term->reg);
			setp->c.condition = term->condition;
			
			report("   " << setp->toString());
			
			assert(previous.op != PredicateTerm::Invalid);

			if(previous.op == PredicateTerm::And)
			{
				setp->booleanOperator = ir::PTXInstruction::BoolAnd;
			}
			else
			{
				setp->booleanOperator = ir::PTXInstruction::BoolOr;
			}
		
			added.push_back(setp);
			
			previous = PredicateTerm(setp->d.reg, setp->d.condition,
				PredicateTerm::Or);
		}
	}
		
	for(auto instruction = bb.instructions.begin();
		instruction != bb.instructions.end(); ++instruction)
	{
		ir::PTXInstruction& ptx =
		static_cast<ir::PTXInstruction&>(**instruction);
		
		// don't predicate side exits
		if(ptx.isBranch()) continue;
		
		assertM(ptx.pg.condition == ir::PTXOperand::PT, "Instruction '"
			<< ptx.toString() << "' was already predicated.");
		
		ptx.pg.addressMode = ir::PTXOperand::Register;
		ptx.pg.condition   = previous.condition;
		ptx.pg.reg         = previous.reg;
	}
	
	bb.instructions.insert(bb.instructions.begin(), added.begin(), added.end());
}

void FlattenHyperblockPass::PredicateEquation::mergeEquations(
	const PredicateEquation& eq)
{
	report("  Merging predicate conditions...");

	if(terms.empty())
	{
		terms = eq.terms;
	}
	else if(!eq.terms.empty())
	{
		report("   ");
		TermVector::const_iterator mineBegin = terms.begin();
		TermVector::const_iterator theirsBegin = eq.terms.begin();
		
		for(; mineBegin != terms.end() && theirsBegin != eq.terms.end();
			++theirsBegin, ++mineBegin)
		{
			if(mineBegin->reg != theirsBegin->reg)
			{
				terms.back().op = PredicateTerm::Or;
				break;
			}
		}
		
		terms.insert(terms.end(), theirsBegin, eq.terms.end());
	}
}

}

