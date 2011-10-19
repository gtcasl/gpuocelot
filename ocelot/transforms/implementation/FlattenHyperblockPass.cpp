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
#include <stack>

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
				report("    Inverting predicate condition");
				invert(condition);
			}
			
			report("    Adding term p" << nextRegister
				<< " to equation from predecessor BB_" << block->id);
			equation.andTerm(PredicateTerm(ptx.pg.reg, condition));
			
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
			
			auto equationForPathHere = predecessorEquation->second;
			
			bool fallthrough = false;
			
			if((*predecessor)->has_fallthrough_edge())
			{
				fallthrough = currentBlock ==
					(*predecessor)->get_fallthrough_edge()->tail;
			}
			
			equationForPathHere.andEquation(getEquation(nextRegister,
				*predecessor, fallthrough));
			
			if(equation->second.isAlwaysTrue())
			{
				equation->second = equationForPathHere;
			}
			else
			{
				equation->second.orEquation(equationForPathHere);
			}
		}

		equation->second.simplify();
		
		report("    " << equation->second.toString());
	}
	
	// predicate each instruction with its condition
	for(auto equation = equations.begin();
		equation != equations.end(); ++equation)
	{
		report("   predicating instructions in BB_" << equation->first->id);
		
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
	ir::Instruction::RegisterType r, ir::PTXOperand::PredicateCondition c)
: reg(r), condition(c)
{

}

std::string FlattenHyperblockPass::PredicateTerm::toString() const
{
	std::stringstream stream;

	switch(condition)
	{
	case ir::PTXOperand::PT:
	{
		stream << "pt";
		break;
	}
	case ir::PTXOperand::nPT:
	{
		stream << "pt";
		break;
	}
	case ir::PTXOperand::Pred:
	{
		stream << "p" << reg;
		break;
	}
	case ir::PTXOperand::InvPred:
	{
		stream << "!p" << reg;
		break;
	}
	}
	
	return stream.str();
}

FlattenHyperblockPass::PredicateEquation::PredicateEquation()
: left(0), op(Invalid), right(0)
{

}

FlattenHyperblockPass::PredicateEquation::~PredicateEquation()
{
	clear();
}

FlattenHyperblockPass::PredicateEquation::PredicateEquation(
	const PredicateEquation& eq)
: left(0), op(eq.op), right(0), term(eq.term)
{
	if(eq.left != 0)  left  = new PredicateEquation(*eq.left);
	if(eq.right != 0) right = new PredicateEquation(*eq.right);
}

FlattenHyperblockPass::PredicateEquation&
	FlattenHyperblockPass::PredicateEquation::operator=(
	const PredicateEquation& eq)
{
	clear();
	
	if(eq.left)  left  = new PredicateEquation(*eq.left);
	if(eq.right) right = new PredicateEquation(*eq.right);

	op   = eq.op;
	term = eq.term;
	
	return *this;
}

ir::Instruction::RegisterType
	FlattenHyperblockPass::PredicateEquation::createAndInsertInstructions(
	ir::Instruction::RegisterType& nextRegister, ir::BasicBlock& bb,
	bool insert, ir::BasicBlock::InstructionList* addedList)
{
	// compute the predicate condition for the block
	// TODO simplify conditions
	ir::BasicBlock::InstructionList added;

	if(insert)
	{
		addedList = &added;
	}

	PredicateTerm resultTerm = term;

	if(op != Invalid)
	{
		auto setp = new ir::PTXInstruction(ir::PTXInstruction::SetP);

		setp->d = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::pred, nextRegister++);
		setp->d.condition = ir::PTXOperand::Pred;
	
		setp->type = ir::PTXOperand::pred;
	
		setp->a = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::pred,
			left->createAndInsertInstructions(nextRegister, bb,
			false, addedList));
		setp->a.condition = left->condition();

		setp->b = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::pred);
		setp->b.condition = ir::PTXOperand::PT;

		setp->c = ir::PTXOperand(ir::PTXOperand::Register,
			ir::PTXOperand::pred,
			right->createAndInsertInstructions(nextRegister, bb,
			false, addedList));
		setp->c.condition = right->condition();
	
		report("   " << setp->toString());
	
		if(op == And)
		{
			setp->booleanOperator = ir::PTXInstruction::BoolAnd;
		}
		else
		{
			setp->booleanOperator = ir::PTXInstruction::BoolOr;
		}

		addedList->push_back(setp);
		
		resultTerm.condition = setp->d.condition;
		resultTerm.reg       = setp->d.reg;
	}
	
	if(insert)
	{
		report("    adding predicate " << resultTerm.toString());	
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
			ptx.pg.condition   = resultTerm.condition;
			ptx.pg.reg         = resultTerm.reg;
		}

		bb.instructions.insert(bb.instructions.begin(),
			added.begin(), added.end());
	}
	
	return resultTerm.reg;
}

ir::PTXOperand::PredicateCondition
	FlattenHyperblockPass::PredicateEquation::condition() const
{
	if(op == Invalid)
	{
		return term.condition;
	}
	
	return ir::PTXOperand::Pred;
}
	
void FlattenHyperblockPass::PredicateEquation::andEquation(
	const PredicateEquation& eq)
{
	if(op == Invalid && term.condition == ir::PTXOperand::PT &&
		eq.op == Invalid)
	{
		term = eq.term;
	}
	else
	{
		left  = new PredicateEquation(*this);
		right = new PredicateEquation(eq);
		op    = And;
	}
}

void FlattenHyperblockPass::PredicateEquation::orEquation(
	const PredicateEquation& eq)
{
	if(op == Invalid && term.condition == ir::PTXOperand::PT &&
		eq.op == Invalid)
	{
		term = eq.term;
	}
	else
	{
		left  = new PredicateEquation(*this);
		right = new PredicateEquation(eq);
		op    = Or;
	}
}

void FlattenHyperblockPass::PredicateEquation::andTerm(const PredicateTerm& term)
{
	PredicateEquation temp;
	
	temp.term = term;
	
	andEquation(temp);
}

typedef std::vector<bool> BitVector;
typedef std::unordered_map<ir::Instruction::RegisterType,
	unsigned int> IndexMap;

bool evaluate(const BitVector& bitvector, IndexMap& indexes,
	const FlattenHyperblockPass::PredicateEquation& equation)
{	
	bool result = true;
	
	if(equation.op == FlattenHyperblockPass::PredicateEquation::Invalid)
	{
		switch(equation.term.condition)
		{
		case ir::PTXOperand::PT:
		{
			result = true;
			break;
		}
		case ir::PTXOperand::nPT:
		{
			result = false;
			break;
		}
		case ir::PTXOperand::Pred:
		{
			result = bitvector[indexes[equation.term.reg]];
			break;
		}
		case ir::PTXOperand::InvPred:
		{
			result = !bitvector[indexes[equation.term.reg]];
			break;
		}
		}
	}
	else
	{
		if(equation.op == FlattenHyperblockPass::PredicateEquation::Or)
		{
			result = evaluate(bitvector, indexes, *equation.left) ||
				evaluate(bitvector, indexes, *equation.right);
		}
		else
		{
			result = evaluate(bitvector, indexes, *equation.left) &&
				evaluate(bitvector, indexes, *equation.right);
		}
	}
	
	return result;
}

void FlattenHyperblockPass::PredicateEquation::simplify()
{
	typedef std::vector<PredicateTerm>                 EquationVector;
	typedef std::stack<PredicateEquation*>             EquationStack;
	typedef std::vector<EquationVector>                MinTermVector;
	typedef std::vector<ir::Instruction::RegisterType> RegisterVector;

	report("    Simplifying boolean equations...");
	report("     before min terms: " << toString());

	MinTermVector  minterms;
	EquationStack  stack;
	IndexMap       indexes;
	RegisterVector reverseIndexes;

	// fan out to minterms
	stack.push(this);
	
	report("     finding all uses registers");
	while(!stack.empty())
	{
		PredicateEquation* eq = stack.top();
		stack.pop();
		
		if(eq->op == Invalid)
		{
			if(eq->term.condition == ir::PTXOperand::Pred ||
				eq->term.condition == ir::PTXOperand::InvPred)
			{
				if(indexes.count(eq->term.reg) == 0)
				{
					report("      used p" << eq->term.reg);
					indexes.insert(std::make_pair(
						eq->term.reg, indexes.size()));
					reverseIndexes.push_back(eq->term.reg);
				}
			}
		}
		else
		{
			stack.push(eq->left);
			stack.push(eq->right);
		}
	}
	
	assert(indexes.size() < 30);

	BitVector bitvector(indexes.size());
	
	for(unsigned int i = 0; i < (1 << indexes.size()); ++i)
	{
		unsigned int key = i;
		for(unsigned int j = 0; j < indexes.size(); ++j)
		{
			bitvector[j] = key & 0x1;
			key >>= 1;
		}
		
		// evaluate the equation to create a minterm
		if(evaluate(bitvector, indexes, *this))
		{
			EquationVector minterm;

			for(unsigned int j = 0; j < indexes.size(); ++j)
			{
				if(bitvector[j])
				{
					minterm.push_back(PredicateTerm(reverseIndexes[j],
						ir::PTXOperand::Pred));
				}
				else
				{
					minterm.push_back(PredicateTerm(reverseIndexes[j],
						ir::PTXOperand::InvPred));
				}
			}

			minterms.push_back(minterm);
		}
	}
	
	clear();
	
	for(auto minterm = minterms.begin(); minterm != minterms.end(); ++minterm)
	{
		PredicateEquation equation;
		
		for(auto eq = minterm->begin(); eq != minterm->end(); ++eq)
		{
			equation.andTerm(*eq);
		}
		
		orEquation(equation);
	}
	
	report("     after min terms: " << toString());

	bool changed = true;
	
	while(changed)
	{
		stack.push(this);
		changed = false;
		
		while(!stack.empty())
		{
			PredicateEquation* eq = stack.top();
			stack.pop();
		
			if(eq->op != Invalid)
			{
				if(eq->left->term.condition == ir::PTXOperand::PT)
				{
					delete eq->left; eq->left = 0;
					eq->op = Invalid;
					eq->term = eq->right->term;
					delete eq->right; eq->right = 0;
					
					changed = true;
				}
				else if(eq->right->term.condition == ir::PTXOperand::PT)
				{
					delete eq->right; eq->right = 0;
					eq->op = Invalid;
					eq->term = eq->left->term;
					delete eq->left; eq->left = 0;
					
					changed = true;
				}
				else if(eq->left->op == Invalid && eq->right->op == Invalid)
				{
					if(eq->right->term.condition == ir::PTXOperand::Pred &&
						eq->left->term.condition == ir::PTXOperand::InvPred)
					{
						delete eq->right; eq->right = 0;
						delete eq->left;  eq->left  = 0;
						eq->op = Invalid;
						eq->term.condition = ir::PTXOperand::PT;
						
						changed = true;
					}
					else if(eq->left->term.condition == ir::PTXOperand::Pred &&
						eq->right->term.condition == ir::PTXOperand::InvPred)
					{
						delete eq->right; eq->right = 0;
						delete eq->left;  eq->left  = 0;
						eq->op = Invalid;
						eq->term.condition = ir::PTXOperand::PT;
						
						changed = true;
					}
					
					if(changed) break;
				}
				else
				{
					stack.push(eq->left);
					stack.push(eq->right);
				}
			}
		}
			
	}
		
	report("     after collection: " << toString());
}

void FlattenHyperblockPass::PredicateEquation::clear()
{
	delete left;  left  = 0;
	delete right; right = 0;
	
	op   = Invalid;
	term = PredicateTerm();
}

std::string FlattenHyperblockPass::PredicateEquation::toString() const
{
	if(op == Invalid)
	{
		return term.toString();
	}

	std::string l = left->toString();
	std::string r = right->toString();
	
	if(op == And)
	{
		return "(" + l + ") & (" + r + ")";
	}
	else
	{
		return "(" + l + ") | (" + r + ")";
	}
}

bool FlattenHyperblockPass::PredicateEquation::isAlwaysTrue() const
{
	return op == Invalid && term.condition == ir::PTXOperand::PT;
}

}

