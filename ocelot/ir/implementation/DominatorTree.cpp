/*!
	\file DominatorTree.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\date 21 Jan 2009
	
	\brief computes a dominator tree from a control flow graph; a
		flag in the constructor permits reversing the edges to compute
		a postdominator tree
*/

#include <ocelot/ir/interface/DominatorTree.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

ir::DominatorTree::~DominatorTree() {
	using namespace std;
	for (vector< vector<int>* >::iterator it = dominated.begin(); it != dominated.end(); ++it) {
		delete (*it);
	}
	dominated.clear();
}

ir::DominatorTree::DominatorTree(ControlFlowGraph *c) {
	
	// form a vector of the basic blocks in reverse post-order
	cfg = c;
	std::vector< BasicBlock* > post_order = cfg->post_order_sequence();
	
	std::vector< BasicBlock* >::iterator it = post_order.begin();
	for (; it != post_order.end(); ++it) {
		blocks.push_back(*it);
		blocksToIndex[*it] = (int)blocks.size()-1;
		i_dom.push_back(-1);
	}
	
	computeDT();
}

/*!
	Computes the dominator tree from a CFG using algorithm __
*/
void ir::DominatorTree::computeDT() {
	using namespace std;
	int start_node = blocksToIndex[cfg->get_entry_block()];

	bool changed = true;
	i_dom[start_node] = start_node;

	while (changed) {
		changed = false;

		// reverse post-order
		for (int b_ind = (int)blocks.size() - 1; b_ind >= 0 ; b_ind--) {
			if (b_ind == start_node) {
				continue;
			}
			BasicBlock *b = blocks[b_ind];
			list<BasicBlock *> pred = b->get_predecessors();
			int new_idom = blocksToIndex[pred.front()];

			list<BasicBlock *>::iterator pred_it = pred.begin();
			++pred_it;
			for (; pred_it != pred.end(); ++pred_it) {
				int p = blocksToIndex[*pred_it];
				if (i_dom[p] != -1) {
					new_idom = intersect(p, new_idom);
				}
			}
			
			if (i_dom[b_ind] != new_idom) {
				i_dom[b_ind] = new_idom;
				changed = true;
			}
		}
	}

	for (int n = 0; n < (int)blocks.size(); n++) {
		vector<int> *vec = new vector<int>;
		dominated.push_back(vec);
	}
	for (int n = 0; n < (int)blocks.size(); n++) {
		if (i_dom[n] >= 0) {
			dominated[i_dom[n]]->push_back(n);
		}
	}
}

int ir::DominatorTree::intersect(int b1, int b2) const {
	int finger1 = b1;
	int finger2 = b2;
	while (finger1 != finger2) {
		while (finger1 < finger2) {
			finger1 = i_dom[finger1];
		}
		while (finger2 < finger1) {
			finger2 = i_dom[finger2];
		}
	}
	return finger1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
