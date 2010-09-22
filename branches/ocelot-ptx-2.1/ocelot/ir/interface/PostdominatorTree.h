/*! \file PostdominatorTree.h
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\date 21 Jan 2009
	
	\brief computes a dominator tree from a control flow graph; a
		flag in the constructor permits reversing the edges to compute
		a postdominator tree
*/

#ifndef IR_POSTDOMINATORTREE_H_INCLUDED
#define IR_POSTDOMINATORTREE_H_INCLUDED

#include <vector>
#include <ocelot/ir/interface/ControlFlowGraph.h>

namespace ir {
	
	/*!
		A tree structure in which each node corresponds to a BasicBlock in the
		control flow graph such that each node's block is immediately 
		post-dominated by its parent. Each node is owned by its parent.
	*/
	class PostdominatorTree {
	public:
		typedef std::vector<int> IndexVector;
		typedef std::vector<IndexVector> IndexArrayVector;
		
	public:
		PostdominatorTree(ControlFlowGraph *cfg);
		~PostdominatorTree();

		/*! Writes a representation of the DominatorTree to an output stream */
		std::ostream& write(std::ostream& out);

		/*! Parent control flow graph */
		ControlFlowGraph* cfg;
	
		/*! store of the basic blocks in the dominator tree in post-order */
		ControlFlowGraph::BlockPointerVector blocks;
	
		/*! nth element stores the immediate post-dominator 
			of node n or -1 if undefined */
		IndexVector p_dom;
	
		/*!  nth element stores a list of elements for which 
			n is the immediate post-dominator */
		IndexArrayVector dominated;
	
		/*! Map from a BasicBlock pointer to an index into the blocks vector */
		ControlFlowGraph::BlockMap blocksToIndex;

		/*! Given a block known to be in the control flow graph, 
			return the post dominator */
		ControlFlowGraph::iterator getPostDominator(
			ControlFlowGraph::iterator block);
	
	private:
		void computeDT();
		int intersect(int b1, int b2) const;
	};
	
}

#endif
