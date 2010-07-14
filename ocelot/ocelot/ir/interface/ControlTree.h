/*! \file ControlTree.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date June 10, 2010
 *  \brief The header file for the ControlTree class.
 *
 *  Computes the control tree as defined in Muchnick's textbook (sec 7.7):
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
#include <unordered_set>

using namespace std;

namespace ir
{
	class ControlTree
	{
		public:
			/*! \brief Construct ControlTree given the CFG */
			ControlTree(ControlFlowGraph* cfg);
			/*! \brief Default destructor */
			~ControlTree();

			/*! \brief A polymorphic base class that represents any node */
			class Node
			{
				public:
					/*! \brief Region type */
					enum RegionType
					{
						Inst,           // Instructions (e.g. basic block)
						Block,          // Block of nodes
						IfThen,         // If-then
						SelfLoop,       // Loop of only one node
						Invalid
					};

					typedef std::list<Node*> NodeList;
					typedef std::unordered_set<Node*> NodeSet;

					/*! \brief Get the label */
					const string label() const;
					/*! \brief Get the region type */
					const RegionType rtype() const;
					/*! \brief Get the children */
					const NodeList& children() const;
					/*! \brief Get successors from the abstract flowgraph */
					NodeSet& succs();
					/*! \brief Get predecessors from the abstract flowgraph */
					NodeSet& preds();

					/*! \brief Destructor (virtual because polymorphic) */
					virtual ~Node();

				protected:
					/*! \brief Constructor (protected to avoid instantiation) */
					Node(const string& label, RegionType rtype, 
							const NodeList& children);

				private:
					/*! \brief Node label */
					const string _label;
					/*! \brief Region type */
					const RegionType _rtype;
					/*! \brief Children in the control tree */
					const NodeList _children;
					/*! \brief Successors in the abstract flowgraph */
					NodeSet _successors;
					/*! \brief Predecessors in the abstract flowgraph */
					NodeSet _predecessors;
			};

			typedef Node::NodeList NodeList;
			typedef Node::NodeSet NodeSet;

			/*! \brief A representation of the cfg basic block */
			class InstNode : public Node
			{
				public:
					/*! \brief Constructor */
					InstNode(const ControlFlowGraph::const_iterator& bb);

					/*! /brief Get iterator to the basic block in the cfg */
					const ControlFlowGraph::const_iterator bb() const;

				private:
					/*! \brief Iterator to the basic block in the cfg */
					const ControlFlowGraph::const_iterator _bb;
			};

			/*! \brief A sequence of nodes */
			class BlockNode : public Node
			{
				public:
					/*! \brief Constructor */
					BlockNode(const string& label, const NodeList& children);
			};

			/*! \brief If-then node */
			class IfThenNode : public Node
			{
				public:
					/*! \brief Constructor */
					IfThenNode(const string& label, Node* cond, Node* ifTrue);

					/*! \brief Get condition node */
					const Node* cond() const;
					/*! \brief Get if-true node */
					const Node* ifTrue() const;

				private:
					const NodeList buildChildren(Node* cond, 
							Node* ifTrue) const;
			};

			/*! \brief Loop with only one node */
			class SelfLoopNode : public Node
			{
				public:
					/*! \brief Constructor */
					SelfLoopNode(const string& label, Node* body);

					/*! \brief Get the node for the body loop */
					const Node* body() const;
			};

			/*! \brief Invalid node */
			class InvalidNode : public Node
			{
				public:
					/*! \brief Constructor */
					InvalidNode();
			};

			/*! \brief write a graphviz-compatible file for visualizing the 
			 * control tree */
			std::ostream& write(std::ostream& out) const;

			/*! \brief Returns the root node of the control tree */
			const Node* const get_root_node() const;

		private:
			Node* insert_node(Node* node);
			void dfs_postorder(Node* x);
			Node* acyclic_region_type(Node* node, NodeSet& nset);
			void compact(Node* node, NodeSet nodeSet);
			void reduce(Node* node, NodeSet nodeSet);
			Node* cyclic_region_type(Node* node, NodeSet& nset);
			void structural_analysis(Node* entry);

			NodeList _nodes;
			NodeList _post;
			NodeList::iterator _postCtr;
			NodeSet _visit;
			Node* _root;
			unsigned int _size;
	};
}

namespace std
{
	template<> inline size_t hash< 
		ir::ControlTree::NodeList::iterator >::operator()( 
		ir::ControlTree::NodeList::iterator it ) const
	{
		return ( size_t )&( *it );
	}

	template<> inline size_t hash< 
		ir::ControlTree::NodeList::const_iterator >::operator()( 
		ir::ControlTree::NodeList::const_iterator it ) const
	{
		return ( size_t )&( *it );
	}
}
#endif
