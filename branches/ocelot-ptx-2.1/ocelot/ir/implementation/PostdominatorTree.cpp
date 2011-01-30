/*! \file PostdominatorTree.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 21 Jan 2009
	
	\brief computes a dominator tree from a control flow graph; a
		flag in the constructor permits reversing the edges to compute
		a postdominator tree
*/

#include <ocelot/ir/interface/PostdominatorTree.h>
#include <ocelot/ir/interface/Instruction.h>

#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

ir::PostdominatorTree::~PostdominatorTree() {

}

ir::PostdominatorTree::PostdominatorTree(ControlFlowGraph *c) {
	// form a vector of the basic blocks in post-order
	report("Building post-dominator tree.");
	cfg = c;
	report(" Starting with post order sequence");
	// form a vector of the basic blocks in post-order
	ControlFlowGraph::BlockPointerVector 
		post_order = cfg->reverse_topological_sequence();
	
	ControlFlowGraph::reverse_pointer_iterator it = post_order.rbegin();
	ControlFlowGraph::reverse_pointer_iterator end = post_order.rend();
	for (; it != end; ++it) {
		blocks.push_back(*it);
		blocksToIndex[*it] = (int)blocks.size()-1;
		p_dom.push_back(-1);
		report("  " << (*it)->label);
	}
	
	computeDT();
}

ir::ControlFlowGraph::iterator ir::PostdominatorTree::getPostDominator(
	ControlFlowGraph::iterator block) {
	int n = blocksToIndex[block];
	return blocks[p_dom[n]];
}

/*! Computes the dominator tree from a CFG using algorithm __*/
void ir::PostdominatorTree::computeDT() {
	using namespace std;
	int end_node = blocksToIndex[cfg->get_exit_block()];

	bool changed = true;
	p_dom[end_node] = end_node;

	report( " Computing tree" );

	while (changed) {
		changed = false;

		// post-order
		for (int b_ind = 0; b_ind < (int)blocks.size(); b_ind++) {
			if (b_ind == end_node)  continue;

			ControlFlowGraph::iterator b = blocks[b_ind];
			assert(!b->successors.empty());
			int new_pdom = 0;
			bool processed = false;

			ControlFlowGraph::pointer_iterator 
				succ_it = b->successors.begin();
			for (; succ_it != b->successors.end(); ++succ_it) {
				int p = blocksToIndex[*succ_it];
				assert(p<(int)p_dom.size());
				if (p_dom[p] != -1) {
					if( !processed ) {
						new_pdom = p;
						processed = true;
					}
					else {
						new_pdom = intersect(p, new_pdom);
					}
				}
			}
		
			if( processed ) {			
				if (p_dom[b_ind] != new_pdom) {
					p_dom[b_ind] = new_pdom;
					changed = true;
				}
			}
		}
	}
	
	dominated.resize(blocks.size());
	for (int n = 0; n < (int)blocks.size(); n++) {
		if (p_dom[n] >= 0) {
			dominated[p_dom[n]].push_back(n);
		}
	}
}

int ir::PostdominatorTree::intersect(int b1, int b2) const {
	int finger1 = b1;
	int finger2 = b2;
	while (finger1 != finger2) {
		report( "finger1 " << finger1 << " finger2 " << finger2 );
		while (finger1 < finger2) {
			finger1 = p_dom[finger1];
		}
		while (finger2 < finger1) {
			finger2 = p_dom[finger2];
		}
	}
	return finger1;
}

std::ostream& ir::PostdominatorTree::write(std::ostream& out) {
	using namespace std;

	out << "digraph {\n";
	out << "  // basic blocks in post-order\n";

	for (int n = 0; n < (int)blocks.size(); n++) {
		out << "  bb_" << n << " [shape=record,label=\"{" 
			<< blocks[n]->label << " | ";
		ControlFlowGraph::InstructionList::iterator 
			instr_it = blocks[n]->instructions.begin();
		for (int j = 0; instr_it != blocks[n]->instructions.end(); 
			++instr_it, ++j) {
			out << (j > 0 ? " | " : "") 
			<< hydrazine::toGraphVizParsableLabel((*instr_it)->toString());
		}
		out << "}\"];\n";
	}

	out << "\n  // tree structure\n";
	for (int n = 0; n < (int)blocks.size(); n++) {
		if (p_dom[n] >= 0 && n != p_dom[n]) {
			out << "  bb_" << n << " -> bb_" << p_dom[n] << ";\n";
		}
	}

	out << "}\n";

	return out;
}


