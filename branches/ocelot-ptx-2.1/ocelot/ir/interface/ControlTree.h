/*! \file ControlTree.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date June 10, 2010
 *  \brief The header file for the ControlTree class.
 *
 *  Computes the Control Tree as defined in Muchnick's textbook (sec 7.7):
 *
 *  1. The root of the control tree is an abstract graph representing the
 *  original flowgraph.
 *  2. The leaves of the control tree are individual basic blocks.
 *  3. The nodes between the root and the leaves are abstract nodes
 *  representing regions of the flowgraph.
 *  4. The edges of the tree represent the relationship between each abstract
 *  node and the regions that are its descendants (and that were abstracted to
 *  form it).
 */

#ifndef IR_CONTROLTREE_H_INCLUDED
#define IR_CONTROLTREE_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PTXInstruction.h>

// STL includes
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>

namespace ir
{
	class ControlTree
	{
		public:
			/*! \brief Construct ControlTree given the cfg */
			ControlTree(ControlFlowGraph *cfg);
			/*! \brief Default destructor */
			~ControlTree();

			enum RegionType
			{
				Inst,
				Block,
				IfThen,
				SelfLoop,
				Invalid
			};

			class Node
			{
				public:
					typedef std::list<Node> NodeList;
					typedef std::vector<NodeList::iterator> NodePointerVector;

					std::string label() const;
					NodePointerVector& successors();
					NodePointerVector& predecessors();

					Node(const std::string& l = "", RegionType rtype = Invalid);

				private:
					std::string _label;
					RegionType _rtype;
					NodePointerVector _successors;
					NodePointerVector _predecessors;
			};

			typedef Node::NodeList NodeList;
			typedef Node::NodePointerVector NodePointerVector;
			typedef NodeList::iterator iterator;
			typedef NodeList::const_iterator const_iterator;
			typedef NodePointerVector::iterator pointer_iterator;
			typedef std::unordered_set<iterator> NodeSet;

			/*!	\brief write a graphviz-compatible file for visualizing the 
			 * control tree */
			std::ostream& write(std::ostream& out) const;

			/*! \brief Get an iterator to the first node */
			iterator begin();
			/*! \brief Get an iterator to the last node */
			iterator end();

			/*! \brief Get an const iterator to the first node */
			const_iterator begin() const;
			/*! \brief Get an const iterator to the last node */
			const_iterator end() const;

		private:
			class InstNode : public Node
			{
				public:
					InstNode(const std::string& l = "");

				private:
					typedef std::list<PTXInstruction*> InstructionList;
					InstructionList _instructions;
			};

			class BlockNode : public Node
			{
				public:
					BlockNode(const std::string& l = "");

				private:
					NodeList _nodes;
			};

			class IfThenNode : public Node
			{
				public:
					IfThenNode(const std::string& l = "");

				private:
					InstNode _cond;
					NodeList _ifTrue;
					NodeList _ifFalse;
			};

			class SelfLoopNode : public Node
			{
				public:
					SelfLoopNode(const std::string& l = "");

				private:
					NodeList _body;
					InstNode _cond;
			};

			iterator insert_node(const Node& node);
			void insert_edge(iterator head, iterator tail);
			void dfs_postorder(iterator x);
			void structural_analysis(iterator entry);

			/*! \brief Node list */
			NodeList _nodes;
			iterator _entry;
			iterator _exit;

			/******************************************//**
			 * \name Postorder traversal of the flowgraph
			 *********************************************/
			//@{
			int _postCtr, _postMax;
			NodePointerVector _post;
			NodeSet _visit;
			//@}
	};
}

namespace std
{
	template<> inline size_t hash< 
		ir::ControlTree::iterator >::operator()( 
		ir::ControlTree::iterator it ) const
	{
		return ( size_t )&( *it );
	}
}
#endif
