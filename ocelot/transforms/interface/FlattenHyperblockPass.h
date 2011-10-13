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

public:
	/*! \brief A predicate term */
	class PredicateTerm
	{
	public:
		enum Operator
		{
			Or,
			And,
			Invalid
		};
		
	public:
		PredicateTerm(ir::Instruction::RegisterType r = 0,
			ir::PTXOperand::PredicateCondition c = ir::PTXOperand::PT,
			Operator o = Invalid);
		
	public:
		ir::Instruction::RegisterType      reg;
		ir::PTXOperand::PredicateCondition condition;
		Operator                           op;
	};
	
	/*! \brief A predicate equation */
	class PredicateEquation
	{
	public:
		typedef std::vector<PredicateTerm> TermVector;
	
	public:
		PredicateEquation();
		
	public:
		void createAndInsertInstructions(ir::Instruction::RegisterType& regId,
			ir::BasicBlock& bb);
		void mergeEquations(const PredicateEquation& eq);
	
	public:
		TermVector terms;
		
	};
	
private:
	void _flattenBlock(ir::ControlFlowGraph& cfg,
		ir::Instruction::RegisterType& regId, 
		analysis::HyperblockAnalysis::iterator block);
};

}


