/*! \file DominatorTree.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 21 Jan 2009
	\brief computes a dominator tree from a control flow graph; a
		flag in the constructor permits reversing the edges to compute
		a postdominator tree
*/

#ifndef IR_DOMINATORTREE_H_INCLUDED
#define IR_DOMINATORTREE_H_INCLUDED

#include <vector>
#include <ocelot/ir/interface/ControlFlowGraph.h>

namespace ir {
	
	/*!
		A tree structure in which each node corresponds to a BasicBlock in the
		control flow graph such that each node's block is immediately dominated
		by its parent. Each node is owned by its parent.
	*/
	class DominatorTree {
		
	public:
		DominatorTree(ControlFlowGraph *cfg);
		~DominatorTree();
		
		/*! Writes a representation of the DominatorTree to an output stream */
		std::ostream& write(std::ostream &out);

		/*! Parent control flow graph */
		ControlFlowGraph *cfg;
	
		/*! the basic blocks in the CFG and dominator tree */
		ControlFlowGraph::BlockPointerVector blocks;
	
		/*! nth element stores the immediate 
			dominator of node n or -1 if undefined */
		std::vector< int > i_dom;

		/*! nth element stores a list of elements for which 
			n is the immediate dominator */
		std::vector< std::vector<int> > dominated;
	
		/*! Mapping from a BasicBlock to an index into the blocks vector */
		ControlFlowGraph::BlockMap blocksToIndex;
	
		/*! Does a particular block dominate another block? */
		bool dominates(ControlFlowGraph::iterator block, 
			ControlFlowGraph::iterator potentialSuccessor);
	
	private:
		void computeDT();
		int intersect(int b1, int b2) const;
	};
	
}

#endif
