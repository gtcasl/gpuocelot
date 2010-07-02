/*!	\file ControlFlowGraph.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief Interface for ControlFlowGraph
	\date 28 September 2008; 21 Jan 2009
*/

#ifndef IR_CONTROL_FLOW_GRAPH_H
#define IR_CONTROL_FLOW_GRAPH_H

#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <unordered_map>

namespace ir {

class Instruction;

/*! Control flow graph */
class ControlFlowGraph {
public:
	/*! \brief A basic block contains a series of instructions 
		terminated by contorl flow */
	class BasicBlock {
	public:
		/*! \brief A list of blocks */
		typedef std::list< BasicBlock > BlockList;
	
		/*! \brief An edge connects two basic blocks */
		class Edge {
		public:
			enum Type {
				Branch,	//< target of a branch
				FallThrough, //< edge when bb continues execution without jump
				Dummy, //< does not actually represent true control flow
				Invalid //< edge is not valid
			};
		
		public:
			Edge( BlockList::iterator h = BlockList::iterator(), 
				BlockList::iterator t = BlockList::iterator(), 
				Type y = FallThrough );
	
			/*!	pointer to head node of edge */
			BlockList::iterator head;
			/*!	pointer to tail node of edge */
			BlockList::iterator tail;
			/*!	Edge properties */
			Type type;
		};

		typedef std::list< Edge > EdgeList;
		typedef std::vector< BlockList::iterator > BlockPointerVector;
		typedef std::vector< EdgeList::iterator > EdgePointerVector;
		typedef std::list< Instruction* > InstructionList;
		typedef unsigned int Id;
	
	public:
		BasicBlock(const std::string& l = "", Id i = 0, 
			const InstructionList& instructions = InstructionList());
		~BasicBlock();
	
		/*! \brief Get the fallthrough edge */
		EdgeList::iterator get_fallthrough_edge();
		/*! \brief Get the fallthrough edge */
		EdgeList::const_iterator get_fallthrough_edge() const;
		/*! \brief Does this have a fallthrough edge */
		bool has_fallthrough_edge() const;

		/*! \brief Get the branch edge */
		EdgeList::iterator get_branch_edge();
		/*! \brief Get the branch edge */
		EdgeList::const_iterator get_branch_edge() const;
		/*! \brief Does this have a branch edge */
		bool has_branch_edge() const;


		/*! \brief Get the edge connecting to the specified block */
		EdgeList::iterator get_edge(BlockList::iterator b);

		/*! \brief Get the edge connecting to the specified block */
		EdgeList::const_iterator get_edge(BlockList::const_iterator b) const;

	public:
		/*! \brief Find an in-edge with specific head and tail pointers */
		EdgePointerVector::iterator find_in_edge(
			BlockList::const_iterator head);
		/*! \brief Find an out-edge with specific head and tail pointers */
		EdgePointerVector::iterator find_out_edge(
			BlockList::const_iterator tail);

	public:
		/*!	list of instructions in BasicBlock. */
		InstructionList instructions;

		/*!	\brief Basic block label */
		std::string label;
		/*! \brief a comment appearing in the emitted PTX source file */
		std::string comment;
		/*! \brief Basic block unique identifier */
		Id id;
	
		/*! \brief Direct successor blocks */
		BlockPointerVector successors;
		/*! \brief Direct predecessor blocks */
		BlockPointerVector predecessors;

		/*! \brief Edges from direct predecessors */
		EdgePointerVector in_edges;
		/*! \brief Edges to direct successors */
		EdgePointerVector out_edges;

	public:

		/*! \brief an object that formats the string representation of a 
				basic block used in the DOT output of the graph
		*/
		class DotFormatter {
		public:
			DotFormatter();
			virtual ~DotFormatter();

			static std::string dotFriendly(const std::string &str);

		public:		
			/*! \brief emits label for entry block */
			virtual std::string entryLabel(const BasicBlock *block);
			
			/*! \brief emits label for exit block */
			virtual std::string exitLabel(const BasicBlock *block);
		
			/*!	\brief prints string representation of */
			virtual std::string toString(const BasicBlock *block);

			/*! \brief emits DOT representation of an edge	*/
			virtual std::string toString(const Edge *edge);
		};
	};

	/*! \brief A list of basic blocks */
	typedef BasicBlock::BlockList BlockList;
	/*! \brief A list of edges */
	typedef BasicBlock::EdgeList EdgeList;
	/*! \brief A vector of edge pointers */
	typedef BasicBlock::EdgePointerVector EdgePointerVector;
	/*! \brief A vector of block pointers */
	typedef BasicBlock::BlockPointerVector BlockPointerVector;
	
	/*! \brief An iterator over basic blocks */
	typedef BlockList::iterator iterator;
	/*! \brief A const iterator over basic blocks */
	typedef BlockList::const_iterator const_iterator;
	
	/*! \brief A pointer to an iterator */
	typedef BlockPointerVector::iterator pointer_iterator;
	/*! \brief A pointer to an iterator */
	typedef BlockPointerVector::reverse_iterator reverse_pointer_iterator;	
	
	/*! \brief An iterator over edges */
	typedef EdgeList::iterator edge_iterator;
	/*! \brief A const iterator over edges */
	typedef EdgeList::const_iterator const_edge_iterator;

	/*! \brief A pointer to an edge iterator */
	typedef EdgePointerVector::iterator edge_pointer_iterator;

	/*! \brief A map from a block pointer to an int */
	typedef std::unordered_map<const_iterator, unsigned int> BlockMap;
	/*! \brief The edge */
	typedef BasicBlock::Edge Edge;

	/*! \brief An instruction list */
	typedef BasicBlock::InstructionList InstructionList;

	/*! \brief maps a basic block [by label] to a coloring */
	typedef std::unordered_map< std::string, unsigned int > BasicBlockColorMap;

public:
	ControlFlowGraph();
	~ControlFlowGraph();

public:
	/*!	Gets the number of blocks within the graph */
	size_t size() const;
	
	/*! \brie Is the graph empty? */
	bool empty() const;

	/*!	Inserts a basic block into the CFG */
	iterator insert_block(const BasicBlock& b);
	
	/*! Removes a basic block and associated edges. Any blocks dominated by
		block are now unreachable but still part of the graph.
	
		\param block block to remove from graph
	*/
	void remove_block(iterator block);

	/*! Creates an edge between given basic blocks
		\param edge edge to create
	*/
	edge_iterator insert_edge(const Edge& e);
	
	/*! Removes the edge which may exist from head->tail. This may render tail
		unreachable.
		
		\param edge to remove
	*/
	void remove_edge(edge_iterator edge);
	
	/*! Given an edge head->tail, retargets edge and creates new edge such that 
		the path head->newblock->tail exists. Inserts newblock into CFG and 
		returns newly created edge
		
		\param edge existing edge to split
		\param newblock new BasicBlock to insert into CFG and create an edge 
			from
		\return implicily created edge from newblock->tail with same type as 
			edge [may need modifying]
	*/
	edge_iterator split_edge(edge_iterator edge, const BasicBlock& newBlock);

	/*! \brief Splits a basic block into two such that there is a fallthrough
		edge from the original block to the newly split block.
	
		This function will map all out_edges of the first block to the second
		block.
		
		\param block The block being split
		\param the instruction within the block to perform the split
		\return A pointer to the newly allocated second block
	*/
	iterator split_block(iterator block, unsigned int instruction, 
		Edge::Type type);

	/*!	Returns the entry block of a control flow graph */
	iterator get_entry_block();

	/*!	Returns the exit block of a control flow graph */
	iterator get_exit_block();
	
	/*! Returns the entry block of a control flow graph */
	const_iterator get_entry_block() const;

	/*!	Returns the exit block of a control flow graph */
	const_iterator get_exit_block() const;
	
	/* \brief Converts { to [ and } to ] for use in dot. */
	static std::string make_label_dot_friendly( const std::string& string );

	/*!	write a graphviz-compatible file for visualizing the CFG */
	std::ostream& write(std::ostream& out) const;

	/*!	\brief write a graphviz-compatible file for visualizing the CFG
	*/
	std::ostream& write(std::ostream& out, 
		BasicBlock::DotFormatter &blockFormatter) const;
	
	/*! \brief Clears all basic blocks and edges in the CFG.*/
	void clear();
	
	/*! \brief Get the name of an edge type */
	static std::string toString( Edge::Type t );
	
	/*! returns an ordered sequence of the nodes of the CFG including entry 
		and exit that would be encountered by a pre order traversal
	*/
	BlockPointerVector pre_order_sequence();
	
	/*! returns an ordered sequence of the nodes of the CFG including entry 
		and exit that would be encountered by a post order traversal
	*/
	BlockPointerVector post_order_sequence();

	/*! Returns an ordered sequence of basic blocks such that the entry node 
		is first and all fall-through edges produce adjacencies
	*/
	BlockPointerVector executable_sequence();
	
	/*!	deep copy of ControlFlowGraph */
	ControlFlowGraph& operator=(const ControlFlowGraph &);

public:
	/*! \brief Get an iterator to the first block */
	iterator begin();
	/*! \brief Get an iterator to the last block */
	iterator end();
	
	/*! \brief Get a const iterator to the first block */
	const_iterator begin() const;
	/*! \brief Get a const iterator the last block */
	const_iterator end() const;

	/*! \brief Get an iterator to the first edge */
	edge_iterator edges_begin();
	/*! \brief Get an iterator to the last edge */
	edge_iterator edges_end();

	/*! \brief Get a const iterator to the first edge */
	const_edge_iterator edges_begin() const;
	/*! \brief Get a const iterator to the last edge */
	const_edge_iterator edges_end() const;

private:
	BlockList _blocks;
	EdgeList _edges;

	iterator _entry;
	iterator _exit;
};

}

namespace std
{
	template<> inline size_t hash< 
		ir::ControlFlowGraph::iterator >::operator()( 
		ir::ControlFlowGraph::iterator it ) const
	{
		return ( size_t )&( *it );
	}

	template<> inline size_t hash< 
		ir::ControlFlowGraph::const_iterator >::operator()( 
		ir::ControlFlowGraph::const_iterator it ) const
	{
		return ( size_t )&( *it );
	}

	template<> inline size_t hash< 
		ir::ControlFlowGraph::InstructionList::iterator >::operator()( 
		ir::ControlFlowGraph::InstructionList::iterator it ) const
	{
		return ( size_t )&( *it );
	}

	template<> inline size_t hash< 
		ir::ControlFlowGraph::InstructionList::const_iterator >::operator()( 
		ir::ControlFlowGraph::InstructionList::const_iterator it ) const
	{
		return ( size_t )&( *it );
	}
}


#endif


