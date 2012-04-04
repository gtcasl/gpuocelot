/*! \file DivergenceAnalysis.h
	\date Jun 1, 2010
	\author Diogo Sampaio <dnsampaio@gmail.com>
	\brief The header file for the DivergenceAnalysis class
*/

#ifndef DIVERGINGENCEANALYSIS_H_
#define DIVERGINGENCEANALYSIS_H_

#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/BranchInfo.h>
#include <ocelot/transforms/interface/Pass.h>

namespace analysis 
{
/*!\brief DivergenceAnalysis implements divergence analysis. The divergence
   analysis goes over the program dataflow graph and finds all the variables
   that will always hold the same values for every thread.
 */
class DivergenceAnalysis : public KernelAnalysis
{
	public:
		typedef std::set<BranchInfo>              branch_set;
		typedef std::unordered_set<DataflowGraph::iterator> block_set;
		typedef DataflowGraph::InstructionVector::const_iterator
			const_instruction_iterator;

	private:
		ir::IRKernel *_kernel;
		/*!\brief Holds the variables marks of divergent blocks */
		DivergenceGraph _divergGraph;
		/*!\brief A set with all divergent branch instructions of the kernel */
		branch_set _divergentBranches;
		/*!\brief Set with all not divergent branch instructions of the kernel*/
		branch_set _notDivergentBranches;
		/*!\brief Set with all not divergent blocks in the kernel*/
		block_set  _notDivergentBlocks;
		bool _doCFGanalysis;

		/*! \brief Is an operand a function call operand? */
		bool _isOperandAnArgument( const ir::PTXOperand& operand );
		/*! \brief Does an operand reference local memory? */
		bool _doesOperandUseLocalMemory( const ir::PTXOperand& operand );

		/*!\brief Make the initial data-flow analysis */
		void _analyzeDataFlow();
		/*!\brief Makes the control-flow analysis, dependent on the results
			of the data-flow analysis */
		void _analyzeControlFlow();
		/*!\brief Taints the destination of a phi instr with a predicate */
		void _addPredicate(const DataflowGraph::PhiInstruction &phi,
			const DivergenceGraph::node_type &predicate);

		bool doControlFlowAnalysis() const { return _doCFGanalysis; };

	public:
		DivergenceAnalysis();
		
		virtual void analyze( ir::IRKernel& k );

		/*!\brief Tests if a block ends with a divergent branch instruction */
		bool isDivBlock( const DataflowGraph::const_iterator &block ) const;
		/*!\brief Tests if a block ends with a divergent branch instruction */
		bool isDivBlock( const DataflowGraph::iterator &block ) const;

		/*!\brief Tests if all threads enter the block in a convergent state */
		bool isEntryDiv( const DataflowGraph::iterator &block ) const;
				
		/*!\brief Tests if a branch instruction is divergent */
		bool isDivBranch( const const_instruction_iterator &instruction ) const;
		/*!\brief Tests if a instruction uses divergent variables */
		bool isDivInstruction(
			const DataflowGraph::Instruction &instruction ) const;
		/*!\brief Tests if a instruction is a possibly divergent branch */
		bool isPossibleDivBranch(const const_instruction_iterator
		    &instruction) const;

		/*!\brief Returns set of all divergent branches of the kernel */
		branch_set &getDivergentBranches();
		/*!\brief Returns a set of all not divergent branches of the kernel */
		branch_set &getNonDivergentBranches();

		/*!\brief Get the data-flow/divergence graph built by the analysis */
		const DivergenceGraph& getDivergenceGraph() const;
		/*!\brief Returns the kernel dataflow graph */
		const DataflowGraph *getDFG() const;
        /*! If doControlFlowAnalysis is set to false, then we have the
            variance analysis of Straton et al..
            Use it only for experiments.
        */
		void setControlFlowAnalysis(bool doControlFlowAnalysis);
};
}

#endif /* DIVERGINGENCEANALYSIS_H_ */

