/*!
	\file BasicBlock.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief Basic block class of the intermediate representation
*/

#ifndef IR_BASICBLOCK_H
#define IR_BASICBLOCK_H

#include <list>
#include <string>
#include "Instruction.h"

namespace ir {

// forward declared to support get_in_edges()
class Edge;

class ControlFlowGraph;

/*! Abstract base class for basic blocks */
class BasicBlock {
public:
	typedef std::list< const ir::Edge* > ConstEdgeList;
	typedef std::list< ir::Edge* > EdgeList;
	typedef std::list< BasicBlock* > BlockList;
	typedef std::list< const BasicBlock* > ConstBlockList;
	typedef std::list< unsigned int > InstructionList;
	typedef unsigned int Id;
	
public:
	BasicBlock();
	~BasicBlock();

	/*! Gets direct predecessors of a basic block */
	BlockList get_predecessors();

	/*!	Gets direct successors of a basic block */
	BlockList get_successors();

	/*!	Edges connecting predecessors to this block */
	EdgeList get_in_edges();

	/*!	Edges connecting this block to successors */
	EdgeList get_out_edges();

	/*!	Gets direct predecessors of a basic block */
	ConstBlockList get_predecessors() const;

	/*!	Gets direct successors of a basic block */
	ConstBlockList get_successors() const;

	/*!	Edges connecting predecessors to this block */
	ConstEdgeList get_in_edges() const;

	/*!	Edges connecting this block to successors */
	ConstEdgeList get_out_edges() const;
	
	/*! \brief Get the fallthrough edge */
	Edge* get_fallthrough_edge();

	/*! \brief Get the fallthrough edge */
	const Edge* get_fallthrough_edge() const;

	/*! \brief Get the edge connecting to the specified block */
	Edge* get_edge(BasicBlock* b);

	/*! \brief Get the edge connecting to the specified block */
	const Edge* get_edge(BasicBlock* b) const;

	/*!	list of instructions in BasicBlock. These are indices in a 
 		vector of instructions maintained outside the CFG */
	InstructionList instructions;

	/*!	\brief Basic block label */
	std::string label;

	/*!
		\brief a comment appearing in the emitted PTX source file
	*/
	std::string comment;

	/*! \brief Basic block unique identifier */
	Id id;
	
private:
	
	BlockList successors;
	BlockList predecessors;

	EdgeList in_edges;
	EdgeList out_edges;

	friend class ControlFlowGraph;
};

}

#endif

