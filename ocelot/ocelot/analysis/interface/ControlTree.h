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

#ifndef ANALYSIS_CONTROLTREE_H_INCLUDED
#define ANALYSIS_CONTROLTREE_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/ControlFlowGraph.h>

#include <ocelot/analysis/interface/Analysis.h>

// STL includes
#include <list>
#include <unordered_set>

typedef ir::ControlFlowGraph CFG;

namespace analysis
{

/*! \brief Computes the Control Tree as defined in Muchnick's textbook */
class ControlTree : public Analysis
{
	public:
		/*! \brief Construct ControlTree given the CFG */
		ControlTree(CFG* cfg);
		/*! \brief Default destructor */
		~ControlTree();

		/*! \brief Region type */
		enum RegionType
		{
			Inst,           // Instructions (e.g. basic block)
			Block,          // Block of nodes
			IfThen,         // If-Then
			While,          // While loop
			Natural,        // Natural loop with side exits
			Invalid
		};

		/*! \brief A polymorphic base class that represents any node */
		class Node
		{
			public:
				typedef std::list<Node*> NodeList;
				typedef std::unordered_set<Node*> NodeSet;

				/*! \brief Get the label */
				const std::string& label() const;
				/*! \brief Get the region type */
				RegionType rtype() const;
				/*! \brief Get the children */
				const NodeList& children() const;
				/*! \brief Get successors from the abstract flowgraph */
				NodeSet& succs();
				/*! \brief Get predecessors from the abstract flowgraph */
				NodeSet& preds();
				/*! \brief Get fallthrough node */
				Node*& fallthrough();

				/*! \brief Destructor (virtual because polymorphic) */
				virtual ~Node();

			protected:
				/*! \brief Constructor (protected to avoid instantiation) */
				Node(const std::string& label, RegionType rtype, 
						const NodeList& children);

			private:
				/*! \brief Node label */
				const std::string _label;
				/*! \brief Region type */
				const RegionType _rtype;
				/*! \brief Children in the control tree */
				const NodeList _children;
				/*! \brief Successors in the abstract flowgraph */
				NodeSet _succs;
				/*! \brief Predecessors in the abstract flowgraph */
				NodeSet _preds;
				/*! \brief Fallthrough node */
				Node* _fallthrough;
		};

		typedef Node::NodeList NodeList;
		typedef Node::NodeSet NodeSet;

		/*! \brief A representation of the cfg basic block */
		class InstNode : public Node
		{
			public:
				typedef CFG::InstructionList InstructionList;

				/*! \brief Constructor */
				InstNode(const CFG::const_iterator& bb);

				/*! /brief Get the instruction list */
				const InstructionList& insts() const;

			private:
				/*! \brief Iterator to the basic block in the cfg */
				const CFG::const_iterator _bb;
		};

		typedef InstNode::InstructionList InstructionList;

		/*! \brief A sequence of nodes */
		class BlockNode : public Node
		{
			public:
				/*! \brief Constructor */
				BlockNode(const std::string& label, 
					const NodeList& children);
		};

		/*! \brief If-Then node */
		class IfThenNode : public Node
		{
			public:
				/*! \brief Constructor */
				IfThenNode(const std::string& label, Node* cond, 
						Node* ifTrue, Node* ifFalse = NULL);

				/*! \brief Get condition node */
				const Node* cond() const;
				/*! \brief Get if-true node */
				const Node* ifTrue() const;
				/*! \brief Get if-false node */
				const Node* ifFalse() const;

			private:
				const NodeList buildChildren(Node* cond, 
						Node* ifTrue, Node* ifFalse) const;
		};

		class WhileNode : public Node
		{
			public:
				/*! \brief Constructor */
				WhileNode(const std::string& label, 
					const NodeList& children);
		};

		class NaturalNode : public Node
		{
			public:
				/*! \brief Constructor */
				NaturalNode(const std::string& label, 
					const NodeList& children);
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

		/*! \brief returns the root node of the control tree */
		const Node* get_root_node() const;

	private:
		Node* _insert_node(Node* node);
		void _dfs_postorder(Node* x);
		Node* _acyclic_region_type(Node* node, NodeSet& nset);
		bool _isCyclic(Node* node);
		bool _backedge(Node* head, Node* tail);
		void _compact(Node* node, NodeSet nodeSet);
		void _reduce(Node* node, NodeSet nodeSet);
		bool _path(Node* m, Node* k, Node* n = NULL);
		bool _path_back(Node* m, Node* n);
		Node* _cyclic_region_type(Node* node, NodeList& nset);
		void _structural_analysis(Node* entry);

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
	template<> struct hash<
		ir::ControlTree::NodeList::iterator >
	{
		inline size_t operator()(
				ir::ControlTree::NodeList::iterator it ) const
		{
			return ( size_t)&( *it );
		}
	};

	template<> struct hash<
		ir::ControlTree::NodeList::const_iterator >
	{
		inline size_t operator()(
				ir::ControlTree::NodeList::const_iterator it ) const
		{
			return ( size_t)&( *it );
		}
	};
}
#endif

