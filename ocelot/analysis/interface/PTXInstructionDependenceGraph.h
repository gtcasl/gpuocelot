/*! \file   PTXInstructionDependenceGraph.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Friday June 29, 2013
	\file   The header file for the PTXInstructionDependenceGraph class.
*/

#pragma once

// Standard Library Includes
#include <list>
#include <unordered_map>

// Forward Declarations
namespace ir { class PTXInstruction; }

namespace analysis
{

/*! \brief Discover all data dependences in a kernel */
class PTXInstructionDependenceGraph
{
public:
	typedef ir::PTXInstruction PTXInstruction;
	
	class Node
	{
	public:
		typedef std::list<Node>           NodeList;
		typedef NodeList::iterator              iterator;
		typedef NodeList::const_iterator  const_iterator;

		typedef std::list<iterator> IteratorList;
		
	public:
		Node(PTXInstruction* instruction);
		
	public:
		PTXInstruction* instruction;
		
		IteratorList successors;
		IteratorList predecessors;
	};

	typedef Node::NodeList NodeList;
	
	typedef Node::iterator             iterator;
	typedef Node::const_iterator const_iterator;
	
	typedef std::unordered_map<const PTXInstruction*, iterator>
		InstructionToNodeMap;
	
public:
	/*! \brief Query if an instruction is dependent on another */
	bool dependsOn(const PTXInstruction* instruction,
		const PTXInstruction* dependee);
		
public:
	iterator       begin();
	const_iterator begin() const;

	iterator       end();
	const_iterator end() const;
	
public:
	/*! \brief Get the node for the specified instruction */
	iterator getNode(const PTXInstruction*);	
	/*! \brief Get the node for the specified instruction */
	const_iterator getNode(const PTXInstruction*) const;	
	
protected:
	NodeList             _nodes;
	InstructionToNodeMap _instructionToNodes;

};

}


