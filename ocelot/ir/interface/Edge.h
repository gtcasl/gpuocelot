/*!
	\file Edge.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief Edge class of the intermediate representation
*/

#ifndef IR_EDGE_H
#define IR_EDGE_H

#include "BasicBlock.h"

namespace ir {
	
	/*!
		\brief Object to denote an edge between basic blocks in the CFG
		
		Edges start at the head and end at the tail. 
	*/
	class Edge {
	public:
		
		enum Type {
			Branch,					//< edge created during conditional branch/jump when condition is true
			FallThrough,		//< edge created when bb continues execution to next bb without jump
			Dummy,					//< edge that does not actually represent true control flow
			Invalid					//< edge is not valid
		};
		
	public:
		
		Edge();
	
		virtual ~Edge();
	
		/*!
			pointer to head node of edge
		*/
		ir::BasicBlock *head;
	
		/*!
			pointer to tail node of edge
		*/
		ir::BasicBlock *tail;
	
		/*!
			Edge properties
		*/
		Type type;
	};
}

#endif
