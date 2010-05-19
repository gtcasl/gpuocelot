/*! \file DominatorTree.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 21 Jan 2009
	\brief computes a dominator tree from a control flow graph; a
		flag in the constructor permits reversing the edges to compute
		a postdominator tree
*/

#include <ocelot/ir/interface/DominatorTree.h>
#include <ocelot/ir/interface/Instruction.h>

ir::DominatorTree::~DominatorTree() {
	dominated.clear();
}

ir::DominatorTree::DominatorTree(ControlFlowGraph *c) {
	
	// form a vector of the basic blocks in reverse post-order
	cfg = c;
	ControlFlowGraph::BlockPointerVector 
		post_order = cfg->post_order_sequence();
	
	ControlFlowGraph::pointer_iterator it = post_order.begin();
	for (; it != post_order.end(); ++it) {
		blocks.push_back(*it);
		blocksToIndex[*it] = (int)blocks.size()-1;
		i_dom.push_back(-1);
	}
	
	computeDT();
}

std::ostream& ir::DominatorTree::write(std::ostream& out) {
	using namespace std;

	out << "digraph {\n";
	out << "  // basic blocks in post-order\n";

	for (int n = 0; n < (int)blocks.size(); n++) {
		out << "  bb_" << n << " [shape=record,label=\"{" << 
			ControlFlowGraph::make_label_dot_friendly(blocks[n]->label) 
			<< " | ";
		ControlFlowGraph::InstructionList::iterator 
			instr_it = blocks[n]->instructions.begin();
		for (int j = 0; instr_it != blocks[n]->instructions.end(); 
			++instr_it, ++j) {
			string str = (*instr_it)->toString();
			out << (j > 0 ? " | " : "") 
				<< ControlFlowGraph::make_label_dot_friendly(str);
		}
		out << "}\"];\n";
	}

	out << "\n  // tree structure\n";
	for (int n = 0; n < (int)blocks.size(); n++) {
		if (i_dom[n] >= 0 && i_dom[n] != n) {
			out << "  bb_" << i_dom[n] << " -> bb_" << n << ";\n";
		}
	}

	out << "}\n";

	return out;
}

/*! Computes the dominator tree from a CFG using algorithm __ */
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
			ControlFlowGraph::iterator b = blocks[b_ind];
			int new_idom = blocksToIndex[b->predecessors.front()];

			ControlFlowGraph::pointer_iterator 
				pred_it = b->predecessors.begin();
			++pred_it;
			for (; pred_it != b->predecessors.end(); ++pred_it) {
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

	dominated.resize(blocks.size());
	for (int n = 0; n < (int)blocks.size(); n++) {
		if (i_dom[n] >= 0) {
			dominated[i_dom[n]].push_back(n);
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
