/*! \file ControlTree.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date June 10, 2010
 *  \brief The source file for the ControlTree class.
 */

// Ocelot includes
#include <ocelot/ir/interface/ControlTree.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

namespace ir
{
	ControlTree::ControlTree(ControlFlowGraph *cfg)
	{
		std::unordered_map<ControlFlowGraph::const_iterator, iterator> bmap;

		_entry = insert_node(InstNode("entry"));
		_exit = insert_node(InstNode("exit"));

		ControlFlowGraph::const_iterator bb;
		for (bb = cfg->begin() ; bb != cfg->end() ; bb++)
		{
			iterator node = insert_node(InstNode(bb->label));
			bmap[bb] = node;
		}

		ControlFlowGraph::const_edge_iterator edge;
		for (edge = cfg->edges_begin() ; edge != cfg->edges_end() ; edge++)
		{
			insert_edge(bmap[edge->head], bmap[edge->tail]);
		}
	}

	ControlTree::~ControlTree()
	{
		_nodes.clear();
	}

	ControlTree::iterator ControlTree::insert_node(const Node& node)
	{
		return _nodes.insert(end(), node);
	}

	void ControlTree::insert_edge(iterator head, iterator tail)
	{
		head->successors().push_back(tail);
		tail->predecessors().push_back(head);
	}

	ControlTree::Node::Node(const std::string& l, RegionType rtype) 
		: _label(l), _rtype(rtype)
	{
	}

	std::string ControlTree::Node::label() const { return _label; }

	ControlTree::NodePointerVector& ControlTree::Node::successors()
	{
		return _successors;
	}

	ControlTree::NodePointerVector& ControlTree::Node::predecessors()
	{
		return _predecessors;
	}

	std::ostream& ControlTree::write(std::ostream& out) const
	{
		using namespace std;

		out << "digraph {\n";

		// emit nodes
		out << "  // nodes\n\n";

		out << "  bb_0 [label=\"" << _entry->label() << "\"];" << endl;
		out << "  bb_1 [label=\"" << _exit->label() << "\"];" << endl;

		int n = 0;
		for (const_iterator node = begin() ; node != end() ; node++, n++)
		{
			out << "  bb_" << n << " [label=\"" << node->label() << "\"];" << endl;
		}

		// emit edges
		out << "}\n";

		return out;
	}

	ControlTree::iterator ControlTree::begin()
	{
		return _nodes.begin();
	}

	ControlTree::iterator ControlTree::end()
	{
		return _nodes.end();
	}

	ControlTree::const_iterator ControlTree::begin() const
	{
		return _nodes.begin();
	}

	ControlTree::const_iterator ControlTree::end() const
	{
		return _nodes.end();
	}

	ControlTree::InstNode::InstNode(const std::string& l) : Node(l, Inst)
	{
	}

	ControlTree::BlockNode::BlockNode(const std::string& l) : Node(l, Block)
	{
	}

	ControlTree::IfThenNode::IfThenNode(const std::string& l) : Node(l, IfThen)
	{
	}

	ControlTree::SelfLoopNode::SelfLoopNode(const std::string& l) 
		: Node(l, SelfLoop)
	{
	}

	void ControlTree::dfs_postorder(iterator x)
	{
		pointer_iterator y;

		_visit.insert(x);
		for (y = x->successors().begin() ; y != x->successors().end() ; y++)
		{
			if (_visit.find(*y) != _visit.end()) continue;
			dfs_postorder(*y);
		}
		_postMax++;
		_post.push_back(x);
	}

	void ControlTree::structural_analysis(iterator entry)
	{
		do
		{
			_post.clear(); _visit.clear();
			_postMax = 0; _postCtr = 0;
			dfs_postorder(entry);

			while (_nodes.size() > 1 && _postCtr <= _postMax)
			{
			}
		} while (_nodes.size() > 1);
	}
}
