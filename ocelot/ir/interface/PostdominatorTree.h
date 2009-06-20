/*!
	\file PostdominatorTree.h
	
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
		control flow graph such that each node's block is immediately dominated
		by its parent. Each node is owned by its parent.
	*/
	class PostdominatorTree {
		
	public:
		PostdominatorTree(ControlFlowGraph *cfg);
		~PostdominatorTree();

		/*!
			Writes a representation of the DominatorTree to an output stream
		*/
		template <typename IType>
		std::ostream & write(std::ostream &out, const std::deque<IType> &instructions) {
			using namespace std;

			out << "digraph {\n";
			out << "  // basic blocks in post-order\n";
	
			for (int n = 0; n < (int)blocks.size(); n++) {
				out << "  bb_" << n << " [shape=record,label=\"{" << blocks[n]->label << " | ";
				list<int>::iterator instr_it = blocks[n]->instructions.begin();
				for (int j = 0; instr_it != blocks[n]->instructions.end(); ++instr_it, ++j) {
					out << (j > 0 ? " | " : "") << ControlFlowGraph::make_label_dot_friendly(
						instructions[*instr_it].toString());
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

		/*!
			Parent control flow graph
		*/
		ControlFlowGraph *cfg;
	
		/*!
			store of the basic blocks in the CFG and dominator tree in post-order
		*/
		std::vector< BasicBlock * > blocks;
	
		/*!
			nth element stores the immediate post-dominator of node n or -1 if undefined
		*/
		std::vector< int > p_dom;
	
		/*!
			Mapping from a BasicBlock pointer to an index into the blocks vector
		*/
		std::map< BasicBlock *, int > blocksToIndex;

		/*!
			Given a block known to be in the control flow graph, return the post dominator
		*/
		BasicBlock * getPostDominator(BasicBlock *block) {
			int n = blocksToIndex[block];
			return blocks[p_dom[n]];
		}
	
	private:
		void computeDT();
		int intersect(int b1, int b2) const;
	};
	
}

#endif
