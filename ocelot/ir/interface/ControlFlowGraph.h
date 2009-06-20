/*!
	\file ControlFlowGraph.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief Interface for ControlFlowGraph
	\date 28 September 2008; 21 Jan 2009
*/

#ifndef IR_CONTROLFLOWGRAPH_H
#define IR_CONTROLFLOWGRAPH_H

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <map>

#include <ocelot/ir/interface/BasicBlock.h>
#include <ocelot/ir/interface/Edge.h>

namespace ir {

/*!
	Control flow graph
*/
class ControlFlowGraph {
public:
	ControlFlowGraph();
	virtual ~ControlFlowGraph();

public:

	/*!
		Gets the number of blocks within the graph
	*/
	virtual size_t size();

	/*!
		Returns a list of BasicBlocks associated with the CFG
	*/
	virtual std::list< const ir::BasicBlock * > get_blocks() const;

	/*!
		Returns a list of edges in the CFG

		\return a list of edge objects
	*/
	virtual std::list< const ir::Edge * > get_edges() const;

	/*!
		Inserts a basic block into the CFG
	*/
	virtual void insert_block(ir::BasicBlock *block);
	
	/*!
		Removes a basic block and associated edges. Any blocks dominated by
		block are now unreachable but still part of the graph.
	
		\param block block to remove from graph
	*/
	virtual void remove_block(ir::BasicBlock *block);

	/*!
		Creates an edge between given basic blocks
		\param edge edge to create
	*/
	virtual void insert_edge(ir::Edge *edge);

	/*!
		Removes the edge which may exist from head->tail. This may render tail
		unreachable.
		
		\param edge to remove
	*/
	virtual void remove_edge(ir::Edge *edge);
	
	/*!
		Given an edge head->tail, retargets edge and creates new edge such that 
		the path head->newblock->tail exists. Inserts newblock into CFG and 
		returns newly created edge
		
		\param edge existing edge to split
		\param newblock new BasicBlock to insert into CFG and create an edge 
			from
		\return implicily created edge from newblock->tail with same type as 
			edge [may need modifying]
	*/
	virtual ir::Edge *split_edge(ir::Edge *edge, ir::BasicBlock *newblock);

	/*!
		Returns the entry block of a control flow graph
	*/
	virtual ir::BasicBlock *get_entry_block();

	/*!
		Returns the exit block of a control flow graph
	*/
	virtual ir::BasicBlock *get_exit_block();
	
	/*!
		Returns the entry block of a control flow graph
	*/
	virtual const ir::BasicBlock *get_entry_block() const;

	/*!
		Returns the exit block of a control flow graph
	*/
	virtual const ir::BasicBlock *get_exit_block() const;
	
	/*!
		write a graphviz-compatible file for visualizing the CFG
	*/
	template <typename IType>
	std::ostream & write(std::ostream &out, const std::deque<IType> &instructions) {
		using namespace std;
	
		map< BasicBlock *, int > blockIndices;
	
		out << "digraph {\n";
	
		// emit nodes
	
		out << "  // basic blocks\n\n";
	
		out << "  bb_0 [shape=Mdiamond,label=\"" << entry->label << "\"];\n";
		out << "  bb_1 [shape=Msquare,label=\"" << exit->label << "\"];\n";
	
		blockIndices[entry] = 0;
		blockIndices[exit] = 1;
	
		int n = 0;
		list< BasicBlock *>::iterator it = blocks.begin();
		for (; it != blocks.end(); ++it, ++n) {
			BasicBlock *block = *it;

			if (block == entry || block == exit) continue;

			blockIndices[block] = n;
		
			out << "  bb_" << n << " [shape=record,label=";
			out << "\"{" << make_label_dot_friendly( (*it)->label );
	
			list<int>::const_iterator instrs = block->instructions.begin();	
			for (; instrs != block->instructions.end(); ++instrs) {
				out << " | " << make_label_dot_friendly(instructions[*instrs].toString() );
			}
			out << "}\"];\n";
		}
	
		out << "\n\n  // edges\n\n";
	
		// emit edges
		list< Edge *>::iterator e_it = edges.begin();
		for (; e_it != edges.end(); ++e_it) {
			const Edge *edge = *e_it;
			out << "  " << "bb_" << blockIndices[edge->head] << " -> "
				<< "bb_" << blockIndices[edge->tail];
			if (edge->type == Edge::Dummy) {
				out << " [style=dotted]";
			}
			else if (edge->type == Edge::Branch) {
				out << " [color=blue]";
			}
		
			out << ";\n";
		}
	
		out << "}\n";
	
		return out;
	}

	/*!
		Returns true if block is reachable from head
	*/
	virtual bool is_reachable(ir::BasicBlock *head, ir::BasicBlock *block);
	
	/*!
		\brief Clears all basic blocks and edges in the CFG. Note: the CFG "owns" all
		blocks and edges, so if you don't want the CFG destructor to delete all of
		the blocks and edges it owns, you should clear it before deleting it.
	*/
	virtual void clear();
	
	/*!
		\brief Converts { to [ and } to ] for use in dot.
	*/
	static std::string make_label_dot_friendly( const std::string& string );
	
	/*!
		returns an ordered sequence of the nodes of the CFG including entry and exit
		that would be encountered by a post order traversal
	*/
	std::vector< BasicBlock * > pre_order_sequence();
	
	/*!
		returns an ordered sequence of the nodes of the CFG including entry and exit
		that would be encountered by a post order traversal
	*/
	std::vector< BasicBlock * > post_order_sequence();

	/*!
		Returns an ordered sequence of basic blocks such that the entry node is first
		and all fall-through edges produce adjacencies
	*/
	std::vector< BasicBlock * > executable_sequence();
	

	/*!
		deep copy of ControlFlowGraph
	*/
	ControlFlowGraph & operator=(const ControlFlowGraph &);

private:
	
	void pre_order_sequence_helper(
		std::vector<BasicBlock*> &sequence, 
		BasicBlock *block,
		std::map< BasicBlock *, int> &visited);

	void post_order_sequence_helper(
		std::vector<BasicBlock*> &sequence, 
		BasicBlock *block,
		std::map< BasicBlock *, int> &visited);

	ir::BasicBlock *entry, *exit;

	std::list< ir::BasicBlock * > blocks;
	std::list< ir::Edge * > edges;

};

}

#endif

