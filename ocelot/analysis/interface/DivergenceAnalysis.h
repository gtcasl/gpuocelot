/*! \file DivergenceAnalysis.h
	\date Jun 1, 2010
	\author Diogo Sampaio <dnsampaio@gmail.com>
	\brief The header file for the DivergenceAnalysis class
*/

#ifndef DIVERGINGENCEANALYSIS_H_
#define DIVERGINGENCEANALYSIS_H_

#include <ocelot/ir/interface/Module.h>
//#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/BranchInfo.h>
#include <ocelot/analysis/interface/Pass.h>
//#include <ocelot/analysis/interface/DataflowGraph.h>
//#include <ocelot/graphs/interface/DivergenceGraph.h>

namespace analysis {
/*!\brief DivergenceAnalysis implements divergence analysis. The divergence
   analysis goes over the program dataflow graph and finds all the variables
   that will always hold the same values for every thread.
 */
class DivergenceAnalysis : public KernelPass
{
	public:
		typedef std::set<BranchInfo> branch_set;

	private:
		ir::PTXKernel *_kernel;
		/*!\brief Holds the variables marks of divergent blocks */
		graph_utils::DivergenceGraph _divergGraph;
		/*!\brief A set with all branch instruction considered divergent of the kernel */
		branch_set _divergentBranches;
		/*!\brief A set with all branch instruction considered not divergent of the kernel */
		branch_set _notDivergentBranches;
		bool _doCFGanalysis;

		/*!\brief Make the initial data-flow analysis */
		void _analyzeDataFlow();
		/*!\brief Makes the control-flow analysis, dependent of the results of the data-flow analysis */
		void _analyzeControlFlow();
		/*!\brief Taints the destiny variable of a phi instruction with a predicate */
		void _addPredicate(const DataflowGraph::PhiInstruction &phi, const graph_utils::DivergenceGraph::node_type &predicate);

		bool doControlFlowAnalysis() const { return _doCFGanalysis; };
	public:
		DivergenceAnalysis();
		/* inherit from KernelPass */
		virtual void initialize( const ir::Module& m ) {};
		/* inherit from KernelPass */
		virtual void runOnKernel( ir::Kernel& k );
		/* inherit from KernelPass */
		virtual void finalize() {};

		// TODO: see if it is possible to use only the call on block,
		// eliminating the call on iterator.
		/*!\brief Tests if a block ends with a divergent branch instruction */
		bool isDivBlock( DataflowGraph::const_iterator &block ) const;
		/*!\brief Tests if a block ends with a divergent branch instruction */
		bool isDivBlock( DataflowGraph::iterator &block ) const;
		/*!\brief Tests if a block ends with a divergent branch instruction */

		/*!\brief Tests if a branch instruction is divergent */
		bool isDivBranch(const DataflowGraph::InstructionVector::const_iterator &instruction ) const;
		/*!\brief Tests if a instruction uses divergent variables */
		bool isDivInstruction( const DataflowGraph::Instruction &instruction ) const;
		/*!\brief Tests if a instruction is a branch instruction with possibility of divergence */
		bool isPossibleDivBranch(const DataflowGraph::InstructionVector::const_iterator &instruction ) const;

		/*!\brief Returns a set of all possible divergent branches of the kernel */
		branch_set &getDivergentBranches() {return _divergentBranches;};
		/*!\brief Returns a set of all not divergent branches of the kernel */
		branch_set &getNonDivergentBranches() {return _notDivergentBranches;};

		/*!\brief Returns the data-flow/divergence graph build by the analysis */
		const graph_utils::DivergenceGraph &getDivergenceGraph() const { return _divergGraph;};
		/*!\brief Returns the kernel dataflow graph */
		const DataflowGraph *getDFG() const {return _kernel->dfg();};
        /*! If doControlFlowAnalysis is set to false, then we have the
            variance analysis of Straton et al..
            Use it only for experiments.
          */
		void setControlFlowAnalysis(const bool doControlFlowAnalysis) {_doCFGanalysis = doControlFlowAnalysis;};
};
}

namespace std{
bool operator<(const analysis::BranchInfo x, const analysis::BranchInfo y);
bool operator<=(const analysis::BranchInfo x, const analysis::BranchInfo y);
bool operator>(const analysis::BranchInfo x, const analysis::BranchInfo y);
bool operator>=(const analysis::BranchInfo x, const analysis::BranchInfo y);
}

#endif /* DIVERGINGENCEANALYSIS_H_ */
