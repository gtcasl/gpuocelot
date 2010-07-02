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

// STL includes
#include <list>
#include <vector>
#include <unordered_set>

namespace ir
{
	class ControlTree
	{
		public:
			/*! \brief Construct ControlTree given the CFG */
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
					typedef std::list<Node*> NodeList;
					typedef NodeList::iterator iterator;
					typedef NodeList::const_iterator const_iterator;

					typedef std::vector<iterator> NodePointerVector;
					typedef NodePointerVector::iterator pointer_iterator;
					typedef NodePointerVector::const_iterator const_pointer_iterator;

					typedef std::unordered_set<iterator> NodeSet;

					Node(const std::string& l = "", 
							RegionType rtype = Invalid, 
							const NodePointerVector& children = NodePointerVector());

					const std::string& label() const;
					const RegionType& rtype() const;
					NodePointerVector& children();
					const NodePointerVector& children() const;
					NodeSet& successors();
					NodeSet& predecessors();

					void add_successor(iterator succ);
					void remove_successor(iterator succ);
					void add_predecessor(iterator pred);
					void remove_predecessor(iterator pred);

				private:
					std::string _label;
					RegionType _rtype;
					NodePointerVector _children;
					NodeSet _successors;
					NodeSet _predecessors;
			};

			/*! \brief A version of the cfg basic block with branches removed */
			class InstNode : public Node
			{
				public:
					typedef ControlFlowGraph::InstructionList InstructionList;
					typedef InstructionList::const_iterator const_iterator;

					InstNode(const ControlFlowGraph::const_iterator& bb);

					const_iterator begin() const;
					const_iterator end() const;

					InstructionList& instructions();

				private:
					InstructionList _instructions;
			};

			class BlockNode : public Node
			{
				public:
					BlockNode(const NodePointerVector& children, 
							const std::string& l = "");

					const_pointer_iterator begin() const;
					const_pointer_iterator end() const;
			};

			class IfThenNode : public Node
			{
				public:
					IfThenNode(iterator cond, iterator ifTrue, 
							const std::string& l = "");

					Node* cond() const;
					Node* ifTrue() const;
			};

			class SelfLoopNode : public Node
			{
				public:
					SelfLoopNode(iterator body, const std::string& l = "");

					Node* body() const;
			};

			typedef Node::NodeList NodeList;
			typedef Node::iterator iterator;
			typedef NodeList::const_iterator const_iterator;

			typedef Node::NodePointerVector NodePointerVector;
			typedef Node::pointer_iterator pointer_iterator;
			typedef NodePointerVector::const_iterator const_pointer_iterator;

			typedef Node::NodeSet NodeSet;

			/*! \brief write a graphviz-compatible file for visualizing the 
			 * control tree */
			std::ostream& write(std::ostream& out) const;

			/*! \brief Returns the entry block of a control tree */
			const_iterator get_root_node() const;

		private:
			iterator insert_node(Node* node);
			void dfs_postorder(iterator x);
			Node* acyclic_region_type(iterator& node, NodeSet& nset);
			iterator compact(Node* node, NodeSet nodeSet);
			iterator replace(Node* node, NodeSet nodeSet);
			Node* cyclic_region_type(iterator& node, NodeSet& nset);
			void structural_analysis(iterator entry);

			/*! \brief Node list */
			NodeList _nodes;
			/*! \brief Control Tree entry node */
			iterator _root;
			/*! \brief Current number of nodes in the CFG */
			unsigned int _size;

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

	template<> inline size_t hash< 
		ir::ControlTree::const_iterator >::operator()( 
		ir::ControlTree::const_iterator it ) const
	{
		return ( size_t )&( *it );
	}
}
#endif
