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

public:
	DivergenceAnalysis();
	
	virtual void analyze( ir::IRKernel& k );

	/*!\brief Tests if a block ends with a divergent branch instruction */
	bool isDivBlock(const DataflowGraph::const_iterator &block) const;
	/*!\brief Tests if a block ends with a divergent branch instruction */
	bool isDivBlock(const DataflowGraph::iterator &block) const;

	/*!\brief Tests if all threads enter the block in a convergent state */
	bool isEntryDiv(const DataflowGraph::iterator &block) const;
			
	/*!\brief Tests if a branch instruction is divergent */
	bool isDivBranch(const DataflowGraph::Instruction &instruction) const;
	/*!\brief Tests if a instruction uses divergent variables */
	bool isDivInstruction(
		const DataflowGraph::Instruction &instruction) const;
	/*!\brief Tests if a instruction is a possibly divergent branch */
	bool isPossibleDivBranch(const DataflowGraph::Instruction
		&instruction) const;

	const DivergenceGraph& getDivergenceGraph() const;
	const DataflowGraph* getDFG() const;

    /*! If doControlFlowAnalysis is set to false, then we have the
        variance analysis of Straton et al..
        Use it only for experiments.
    */
	void setControlFlowAnalysis(bool doControlFlowAnalysis);
    /*! Mark blocks as convergent even if they depend on a divergent branch
    	as long as doing so does not introduce conflicts.
    */
	void setConditionalConvergence(bool includeConditionalConvergence);
	
private:
	/*!\brief Performs convergence analysis, identifies blocks that can
		never be divergent */
	void _convergenceAnalysis();
	/*!\brief Make the initial data-flow analysis */
	void _analyzeDataFlow();
	/*!\brief Makes the control-flow analysis, dependent on the results
		of the data-flow analysis */
	void _analyzeControlFlow();
	/*!\brief Updates convergence analysis, using current divergence
		analysis results */
	void _updateConvergenceAnalysis();
	/*!\brief Taints the destination of a phi instr with a predicate */
	void _addPredicate(const DataflowGraph::PhiInstruction &phi,
		const DivergenceGraph::node_type &predicate);
	/*!\brief Removes the dependence */
	void _removePredicate(const DataflowGraph::PhiInstruction &phi,
		const DivergenceGraph::node_type &predicate);
	
private:
	/*! \brief Is an operand a function call operand? */
	bool _isOperandAnArgument( const ir::PTXOperand& operand );
	/*! \brief Does an operand reference local memory? */
	bool _doesOperandUseLocalMemory( const ir::PTXOperand& operand );
	/*! \brief Tests if a block can end with a divergent branch instruction,
		without using control dependence analysis */
	bool _isPossibleDivBlock(const DataflowGraph::iterator &block) const;
	/*! \brief Tests if this block has at most 1 path that does not reach
		the exit without executing another instruction */
	bool _hasTrivialPathToExit(const DataflowGraph::iterator &block) const;
	/*! \brief Tests if all paths hit convergent blocks before the
		reconvergence point */
	bool _doAllPathsConvergeBeforeReconvergencePoint(
		const DataflowGraph::iterator &block) const;
	
	/*!\brief Marks a block as never-divergent and propagates
		this property */
	bool _assignAndPropagateConvergence(
		const DataflowGraph::iterator &block);
	/*!\brief Marks a block as never-divergent if all predecessors
			are convergent */
	bool _discoverBlocksWithConvergentPredecessors(
		const DataflowGraph::iterator &block);
	/*!\brief Marks a block as never-divergent if all predecessors
			are convergent, not using control dependence analysis */
	bool _discoverBlocksWithSimpleConvergentPredecessors(
		const DataflowGraph::iterator &block);
	/*!\brief Marks a block as never-divergent if the predecessor
		is convergent, and the other block is the exit */
	bool _discoverBlocksWithSimplePathsToTheExit(
		const DataflowGraph::iterator &block);

private:
	/*! \brief Get the set of possibly divergent branches */
	void _findBranches(branch_set& branches);
	/*! \brief Add divergence graph edges for control dependences */
	void _propagateDivergenceAlongControlDependences(branch_set& branches);
	/*! \brief Convert divergent blocks to convergent by examining
		control dependences, consider all blocks */
	void _discoverNewConvergentBlocks();

	/*! \brief Convert divergent blocks to convergent by examining
		control dependences, only consider blocks influenced by
		divergent branches */
	void _discoverNewConvergentBlocksUsingBranchInfo(branch_set& branches);
	/*! \brief Attempt to prove that divergent branches are actually convergent,
		update the divergence graph on success */
	bool _promoteDivergentBranchesToConvergent(branch_set& branches);

private:
	ir::IRKernel *_kernel;
	/*!\brief Holds the variables marks of divergent blocks */
	DivergenceGraph _divergGraph;
	/*!\brief Set with all not divergent blocks in the kernel*/
	block_set  _notDivergentBlocks;
	bool _doCFGanalysis;
	bool _includeConditionalConvergence;

};

}

#endif /* DIVERGINGENCEANALYSIS_H_ */

