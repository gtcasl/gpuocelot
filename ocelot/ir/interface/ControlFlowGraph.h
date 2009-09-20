/*!	\file ControlFlowGraph.h
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
#include <unordered_map>

#include <ocelot/ir/interface/BasicBlock.h>
#include <ocelot/ir/interface/Edge.h>

namespace ir {

/*! Control flow graph */
class ControlFlowGraph {
public:
	/*! \brief A vector of BasicBlock pointers */
	typedef std::vector< BasicBlock* > BlockPointerVector;
	/*! \brief A map from block to instruction ids */
	typedef std::unordered_map< BasicBlock*, int > BlockMap;

public:
	ControlFlowGraph();
	~ControlFlowGraph();

public:

	/*!	Gets the number of blocks within the graph */
	size_t size();

	/*!	Returns a list of BasicBlocks associated with the CFG */
	ir::BasicBlock::ConstBlockList get_blocks() const;

	/*!	Returns a list of BasicBlocks associated with the CFG */
	ir::BasicBlock::BlockList get_blocks();

	/*!	Returns a list of edges in the CFG

		\return a list of edge objects
	*/
	ir::BasicBlock::ConstEdgeList get_edges() const;

	/*!	Inserts a basic block into the CFG */
	void insert_block(ir::BasicBlock *block);
	
	/*!
		Removes a basic block and associated edges. Any blocks dominated by
		block are now unreachable but still part of the graph.
	
		\param block block to remove from graph
	*/
	void remove_block(ir::BasicBlock *block);

	/*!
		Creates an edge between given basic blocks
		\param edge edge to create
	*/
	void insert_edge(ir::Edge *edge);
	
	/*!
		Removes the edge which may exist from head->tail. This may render tail
		unreachable.
		
		\param edge to remove
	*/
	void remove_edge(ir::Edge *edge);
	
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
	ir::Edge* split_edge(ir::Edge* edge, ir::BasicBlock* newblock);

	/*! \brief Splits a basic block into two such that there is a fallthrough
		edge from the original block to the newly split block.
	
		This function will map all out_edges of the first block to the second
		block.
		
		\param block The block being split
		\param the instruction within the block to perform the split
		\return A pointer to the newly allocated second block
	*/
	ir::BasicBlock* split_block(ir::BasicBlock* block, 
		unsigned int instruction );

	/*!	Returns the entry block of a control flow graph */
	ir::BasicBlock* get_entry_block();

	/*!	Returns the exit block of a control flow graph */
	ir::BasicBlock* get_exit_block();
	
	/*! Returns the entry block of a control flow graph */
	const ir::BasicBlock* get_entry_block() const;

	/*!	Returns the exit block of a control flow graph */
	const ir::BasicBlock* get_exit_block() const;
	
	/*!	write a graphviz-compatible file for visualizing the CFG */
	template <typename IType>
	std::ostream& write(std::ostream &out, 
		const std::deque<IType>& instructions) {
		using namespace std;
	
		BlockMap blockIndices;
	
		out << "digraph {\n";
	
		// emit nodes
	
		out << "  // basic blocks\n\n";
	
		out << "  bb_0 [shape=Mdiamond,label=\"" << _entry->label << "\"];\n";
		out << "  bb_1 [shape=Msquare,label=\"" << _exit->label << "\"];\n";
	
		blockIndices[_entry] = 0;
		blockIndices[_exit] = 1;
	
		int n = 0;
		ir::BasicBlock::BlockList::iterator it = blocks.begin();
		for (; it != blocks.end(); ++it, ++n) {
			BasicBlock* block = *it;

			if (block == _entry || block == _exit) continue;

			blockIndices[block] = n;
		
			out << "  bb_" << n << " [shape=record,label=";
			out << "\"{" << make_label_dot_friendly( (*it)->label );
	
			ir::BasicBlock::InstructionList::const_iterator instrs 
				= block->instructions.begin();	
			for (; instrs != block->instructions.end(); ++instrs) {
				out << " | " << make_label_dot_friendly(
				instructions[*instrs].toString() );
			}
			out << "}\"];\n";
		}
	
		out << "\n\n  // edges\n\n";
	
		// emit edges
		ir::BasicBlock::EdgeList::iterator e_it = edges.begin();
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

	/*! Returns true if block is reachable from head */
	bool is_reachable(ir::BasicBlock* head, ir::BasicBlock* block);
	
	/*!
		\brief Clears all basic blocks and edges in the CFG. Note: the CFG 
		"owns" all blocks and edges, so if you don't want the CFG destructor 
		to delete all of the blocks and edges it owns, you should clear it 
		before deleting it.
	*/
	void clear();
	
	/* \brief Converts { to [ and } to ] for use in dot. */
	static std::string make_label_dot_friendly( const std::string& string );
	
	/*!
		returns an ordered sequence of the nodes of the CFG including entry 
		and exit that would be encountered by a pre order traversal
	*/
	BlockPointerVector pre_order_sequence();
	
	/*!
		returns an ordered sequence of the nodes of the CFG including entry 
		and exit that would be encountered by a post order traversal
	*/
	BlockPointerVector post_order_sequence();

	/*!
		Returns an ordered sequence of basic blocks such that the entry node 
		is first and all fall-through edges produce adjacencies
	*/
	BlockPointerVector executable_sequence();
	
	/*!	deep copy of ControlFlowGraph */
	ControlFlowGraph& operator=(const ControlFlowGraph &);

private:
	
	void pre_order_sequence_helper(
		BlockPointerVector &sequence, 
		BasicBlock* block,
		BlockMap& visited);

	void post_order_sequence_helper(
		BlockPointerVector &sequence, 
		BasicBlock* block,
		BlockMap& visited);

	ir::BasicBlock* _entry, *_exit;

	ir::BasicBlock::BlockList blocks;
	ir::BasicBlock::EdgeList edges;

};

}

#endif

