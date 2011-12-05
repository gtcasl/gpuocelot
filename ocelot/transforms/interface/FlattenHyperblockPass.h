/*! \file   FlattenHyperblockPass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Saturday October 8, 2011
	\brief  The header file for the FlattenHyperblockPass class.
*/

#pragma once

// Ocelot Includes
#include <ocelot/transforms/interface/Pass.h>
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/analysis/interface/HyperblockAnalysis.h>

namespace transforms
{

/*! \brief Merge all basic blocks in a hyperblock together using predication */
class FlattenHyperblockPass : public KernelPass
{
public:
	FlattenHyperblockPass();

public:
	/*! \brief Initialize the pass using a specific module */
	void initialize(const ir::Module& m);
	/*! \brief Run the pass on a specific kernel in the module */
	void runOnKernel(ir::IRKernel& k);
	/*! \brief Finalize the pass */
	void finalize();
	/*! \brief Return a list of passes (by name) that this pass depends on */
	StringVector getDependentPasses() const;

public:
	/*! \brief A predicate term */
	class PredicateTerm
	{
	public:
		PredicateTerm(ir::Instruction::RegisterType r = 0,
			ir::PTXOperand::PredicateCondition c = ir::PTXOperand::PT);
	
	public:
		std::string toString() const;
	
	public:
		ir::Instruction::RegisterType      reg;
		ir::PTXOperand::PredicateCondition condition;
	};
	
	/*! \brief A predicate equation */
	class PredicateEquation
	{
	public:
		enum Operator
		{
			Or,
			And,
			Invalid,
			Uninitialized
		};
	
	public:
		PredicateEquation(Operator o = Uninitialized);
		~PredicateEquation();
		
		PredicateEquation(const PredicateEquation& eq);
		PredicateEquation& operator=(const PredicateEquation& eq);
		
	public:
		ir::Instruction::RegisterType createAndInsertInstructions(
			ir::Instruction::RegisterType& regId, ir::BasicBlock& bb,
			bool insert = true, ir::BasicBlock::InstructionList* addedList = 0);
		ir::PTXOperand::PredicateCondition condition() const;
		void andEquation(const PredicateEquation& eq);
		void orEquation(const PredicateEquation& eq);
		void andTerm(const PredicateTerm& term);
		void simplify();
		void clear();
	
	public:
		bool isAlwaysTrue() const;
		std::string toString() const;
	
	public:
		PredicateEquation* left;
		Operator           op;
		PredicateEquation* right;
		PredicateTerm      term;
		
	};
	
private:
	void _flattenBlock(ir::ControlFlowGraph& cfg,
		ir::Instruction::RegisterType& regId, 
		analysis::HyperblockAnalysis::iterator block);
};

}


