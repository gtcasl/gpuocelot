/*!
	\file PostdominatorTree.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\date 21 Jan 2009
	
	\brief computes a dominator tree from a control flow graph; a
		flag in the constructor permits reversing the edges to compute
		a postdominator tree
*/

#include <ocelot/ir/interface/PostdominatorTree.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

ir::PostdominatorTree::~PostdominatorTree() {

}

ir::PostdominatorTree::PostdominatorTree(ControlFlowGraph *c) {
	// form a vector of the basic blocks in reverse post-order
	cfg = c;
	std::vector< BasicBlock* > order = cfg->pre_order_sequence();
	
	std::vector< BasicBlock* >::iterator it = order.begin();
	for (; it != order.end(); ++it) {
		blocks.push_back(*it);
		blocksToIndex[*it] = (int)blocks.size()-1;
		p_dom.push_back(-1);
	}
	
	computeDT();
}


/*!
	Computes the dominator tree from a CFG using algorithm __
*/
void ir::PostdominatorTree::computeDT() {
	using namespace std;
	int end_node = blocksToIndex[cfg->get_exit_block()];

	bool changed = true;
	p_dom[end_node] = end_node;

	while (changed) {
		changed = false;

		// post-order
		for (int b_ind = 0; b_ind < (int)blocks.size(); b_ind++) {
			if (b_ind == end_node) {
				continue;
			}
			BasicBlock *b = blocks[b_ind];
			list<BasicBlock *> succ = b->get_successors();
			int new_pdom = blocksToIndex[succ.front()];

			list<BasicBlock *>::iterator succ_it = succ.begin();
			++succ_it;
			for (; succ_it != succ.end(); ++succ_it) {
				int p = blocksToIndex[*succ_it];
				if (p_dom[p] != -1) {
					new_pdom = intersect(p, new_pdom);
				}
			}
			
			if (p_dom[b_ind] != new_pdom) {
				p_dom[b_ind] = new_pdom;
				changed = true;
			}
		}
	}
}

int ir::PostdominatorTree::intersect(int b1, int b2) const {
	int finger1 = b1;
	int finger2 = b2;
	while (finger1 != finger2) {
		while (finger1 > finger2) {
			finger1 = p_dom[finger1];
		}
		while (finger2 > finger1) {
			finger2 = p_dom[finger2];
		}
	}
	return finger1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
