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

/*!
	Abstract base class for basic blocks
*/
class BasicBlock {
public:
	
	enum Type {
		Entry = 0,
		Exit = 1,
		Body = 2,
		Dummy
	};
	
public:
	BasicBlock();
	virtual ~BasicBlock();

	/*!
		Gets direct predecessors of a basic block
	*/
	virtual std::list< BasicBlock *> get_predecessors();

	/*!
		Gets direct successors of a basic block
	*/
	virtual std::list< BasicBlock *> get_successors();

	/*!
		Edges connecting predecessors to this block
	*/
	virtual std::list< ir::Edge *> get_in_edges();

	/*!
		Edges connecting this block to successors
	*/
	virtual std::list< ir::Edge *> get_out_edges();

	/*!
		Gets direct predecessors of a basic block
	*/
	virtual std::list< const BasicBlock *> get_predecessors() const;

	/*!
		Gets direct successors of a basic block
	*/
	virtual std::list< const BasicBlock *> get_successors() const;

	/*!
		Edges connecting predecessors to this block
	*/
	virtual std::list< const ir::Edge *> get_in_edges() const;

	/*!
		Edges connecting this block to successors
	*/
	virtual std::list< const ir::Edge *> get_out_edges() const;

	/*!
 		list of instructions in BasicBlock. These are indices in a vector of instructions
		maintained outside the CFG
	*/
	std::list< int > instructions;

	/*!
		\brief Basic block label
	*/
	std::string label;
	
private:
	
	std::list< BasicBlock * > successors;
	std::list< BasicBlock * > predecessors;

	std::list< Edge * > in_edges;
	std::list< Edge * > out_edges;

	friend class ControlFlowGraph;
};

}

#endif

