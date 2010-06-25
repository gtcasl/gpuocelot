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

		ControlFlowGraph::const_iterator bb;
		for (bb = cfg->begin() ; bb != cfg->end() ; bb++)
		{
			iterator node = insert_node(InstNode(bb));
			bmap[bb] = node;

			if (bb == cfg->get_entry_block()) _entry = node;
		}

		ControlFlowGraph::const_edge_iterator edge;
		for (edge = cfg->edges_begin() ; edge != cfg->edges_end() ; edge++)
		{
			bmap[edge->head]->add_successor(bmap[edge->tail]);
			bmap[edge->tail]->add_predecessor(bmap[edge->head]);
		}

		structural_analysis(_entry);
	}

	ControlTree::~ControlTree()
	{
		_nodes.clear();
	}

	// TODO rename to add_node
	ControlTree::iterator ControlTree::insert_node(const Node& node)
	{
		return _nodes.insert(end(), node);
	}

	// TODO rename to remove_node
	ControlTree::iterator ControlTree::erase_node(iterator node)
	{
		return _nodes.erase(node);
	}

	ControlTree::Node::Node(const std::string& l, RegionType rtype) 
		: _label(l), _rtype(rtype)
	{
	}

	std::string& ControlTree::Node::label()
	{
		return _label;
	}

	const ControlTree::RegionType& ControlTree::Node::rtype() const
	{
		return _rtype;
	}

	ControlTree::Node::NodePointerVector& ControlTree::Node::successors()
	{
		return _successors;
	}

	ControlTree::Node::NodePointerVector& ControlTree::Node::predecessors()
	{
		return _predecessors;
	}

	void ControlTree::Node::add_successor(iterator succ)
	{
		successors().push_back(succ);
	}

	void ControlTree::Node::remove_successor(iterator succ)
	{
		pointer_iterator pnode;
		for (pnode = successors().begin() ; 
				pnode != successors().end() ; pnode++)
		{
			if (*pnode == succ)
			{
				successors().erase(pnode);
				break;
			}
		}
	}

	void ControlTree::Node::add_predecessor(iterator pred)
	{
		predecessors().push_back(pred);
	}

	void ControlTree::Node::remove_predecessor(iterator pred)
	{
		pointer_iterator pnode;
		for (pnode = predecessors().begin() ;
				pnode != predecessors().end() ; pnode++)
		{
			if (*pnode == pred)
			{
				predecessors().erase(pnode);
				break;
			}
		}
	}

	std::ostream& ControlTree::write(std::ostream& out) const
	{
		using namespace std;

		std::unordered_map<const_iterator, unsigned int> bmap;

		out << "digraph {" << endl;

		// emit nodes
		out << "  // nodes" << endl;

		int n;
		const_pointer_iterator pnode;
		for (pnode = _post.begin(), n = 0 ; pnode != _post.end() ; pnode++, n++)
		{
			bmap[*pnode] = n;
			out << "  bb_" << n << " [label=\"" << (*pnode)->label() << "\"];";
			out << endl;
		}

		// emit edges
		out << endl << "  // edges" << endl;

		for (pnode = _post.begin() ; pnode != _post.end() ; pnode++)
		{
			const_pointer_iterator tail = pnode + 1;
			if (tail != _post.end())
			{
				out << "  bb_" << bmap[*pnode];
				out	<< " -> ";
				out	<< "bb_" << bmap[*tail];
				out << ";" << endl;
			}
		}

		out << "}" << endl;

		return out;
	}

	std::ostream& ControlTree::writeCFG(std::ostream& out)
	{
		using namespace std;

		std::unordered_map<const_iterator, unsigned int> bmap;

		out << "digraph {" << endl;

		// emit nodes
		out << "  // nodes" << endl;

		int n;
		iterator node;
		for (node = begin(), n = 0 ; node != end() ; node++, n++)
		{
			bmap[node] = n;
			out << "  bb_" << n << " [label=\"" << node->label() << "\"];";
			out << endl;
		}

		// emit edges
		out << endl << "  // edges" << endl;

		for (node = begin() ; node != end() ; node++)
		{
			const_pointer_iterator succ;
			for (succ = node->successors().begin() ; 
					succ != node->successors().end() ; succ++)
			{
				out << "  bb_" << bmap[node] << " -> " << "bb_" << bmap[*succ];
				out << ";" << endl;
			}
		}

		out << "}" << endl;

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

	ControlTree::const_iterator ControlTree::get_entry_block() const
	{
		return _entry;
	}

	ControlTree::InstNode::InstNode(const ControlFlowGraph::const_iterator& bb)
		: Node(bb->label, Inst)
	{
		// copy the instructions except for the branches
		ControlFlowGraph::InstructionList::const_iterator first;
		ControlFlowGraph::InstructionList::const_reverse_iterator last;
	   
		first = bb->instructions.begin();
		last = bb->instructions.rbegin();

		//if ((*last)->opcode == PTXInstruction::Bra) last++;
		//_instructions.assign(first, last);
	}

	ControlTree::InstNode::const_iterator ControlTree::InstNode::begin() const
	{
		return _instructions.begin();
	}

	ControlTree::InstNode::const_iterator ControlTree::InstNode::end() const
	{
		return _instructions.end();
	}

	ControlTree::BlockNode::BlockNode(const NodePointerVector& nodes, 
			const std::string& l) : Node(l, Block)
	{
		const_pointer_iterator pnode;
		for (pnode = nodes.begin() ; pnode != nodes.end() ; pnode++)
		{
			_nodes.push_back(**pnode);
		}
	}

	ControlTree::const_iterator ControlTree::BlockNode::begin() const
	{
		return _nodes.begin();
	}

	ControlTree::const_iterator ControlTree::BlockNode::end() const
	{
		return _nodes.end();
	}

	ControlTree::IfThenNode::IfThenNode(const Node& cond, const Node& ifTrue, 
			const std::string& l) 
		: Node(l, IfThen), _cond(cond), _ifTrue(ifTrue)
	{
	}

	ControlTree::SelfLoopNode::SelfLoopNode(const std::string& l) 
		: Node(l, SelfLoop)
	{
	}

	void ControlTree::dfs_postorder(iterator x)
	{
		_visit.insert(x);

		const_pointer_iterator y;
		for (y = x->successors().begin() ; y != x->successors().end() ; y++)
		{
			if (_visit.find(*y) != _visit.end()) continue;
			dfs_postorder(*y);
		}
		_postMax++;
		_post.push_back(x);
	}

	ControlTree::Node ControlTree::acyclic_region_type
		(iterator& node, NodeSet& nset)
	{
		iterator n;
		bool p, s;
		NodePointerVector nodes;

		// check for a Block containing node
		n = node;
		p = true;
		s = (n->successors().size() == 1);

		while (p && s)
		{
			nodes.push_back(n);
			n = *(n->successors().begin());
			p = (n->predecessors().size() == 1);
			s = (n->successors().size() == 1);
		}

		if (p) nodes.push_back(n);

		n = node;
		p = (n->predecessors().size() == 1);
		s = true;

		while (p && s)
		{
			n = *(n->predecessors().begin());
			p = (n->predecessors().size() == 1);
			s = (n->successors().size() == 1);
			nodes.insert(nodes.begin(), n);
		}

		//if (s) nlist.push_front(*n);

		node = n;
		if (nodes.size() >= 2)
		{
			nset.clear();
			for (pointer_iterator i = nodes.begin() ; i != nodes.end() ; i++)
			{
				nset.insert(*i);
			}
			return BlockNode(nodes);
		} else if (node->successors().size() == 2)
		{
			iterator m;
		   
			m = node->successors()[0];
			n = node->successors()[1];

			// check for an IfThen (if node then n)
			if (n->successors().size() == 1 && n->predecessors().size() == 1 &&
					m->predecessors().size() == 2 && 
					*(n->successors().begin()) == m)
			{
				nset.clear();
				nset.insert(node);
				nset.insert(n);
				return IfThenNode(*node, *n);
			}

			// check for an IfThen (if node then m)
			if (m->successors().size() == 1 && m->predecessors().size() == 1 &&
					n->predecessors().size() == 2 && 
					*(m->successors().begin()) == n)
			{
				nset.clear();
				nset.insert(node);
				nset.insert(m);
				return IfThenNode(*node, *m);
			}
		}

		return Node(); 
	}

	/*
	ControlTree::Node ControlTree::create_node(RegionType rtype)
	{
		switch (rtype)
		{
			case Inst:     return InstNode();
			case Block:    return BlockNode();
			case IfThen:   return IfThenNode();
			case SelfLoop: return SelfLoopNode();
			default:       assertM(false, "Invalid region type");
		}
	}
	*/

	ControlTree::iterator ControlTree::compact(Node n, NodeSet nodeSet)
	{
		iterator node = insert_node(n);

		pointer_iterator pnode;
		pointer_iterator pos;
		for (pnode = _post.begin() ; pnode != _post.end() && !nodeSet.empty() ;)
		{
			// find if there's an iterator in nodeSet that points to the same
			// object as pnode (is there a better way to do this?)
			NodeSet::iterator ns;
			for (ns = nodeSet.begin() ; ns != nodeSet.end() ; ns++)
			{
				if (*ns == *pnode) break;
			}

			if (ns == nodeSet.end())
			{
				pnode++;
				continue;
			}

			nodeSet.erase(ns);
			pnode = _post.erase(pnode);
			pos = pnode;
			_postMax--;
		}

		_postMax++;
		_post.insert(pos, node);
		_postCtr = pos - _post.begin();

		return node;
	}

	ControlTree::iterator ControlTree::replace(Node n, NodeSet nodeSet)
	{
		// link region node into abstract flowgraph, adjust the post order
		// traversal and predecessor and successor functions, and augment the
		// control tree
		iterator node = compact(n, nodeSet);

		NodeSet::iterator ns;
		for (ns = nodeSet.begin() ; ns != nodeSet.end() ; ns++)
		{
			pointer_iterator pred;
			for (pred = (*ns)->predecessors().begin() ; 
					pred != (*ns)->predecessors().end() ; pred++)
			{
				// if (!nodeSet.find(pred))
				(*pred)->remove_successor(*ns);
				(*pred)->add_successor(node);
			}

			pointer_iterator succ;
			for (succ = (*ns)->successors().begin() ;
					succ != (*ns)->successors().end() ; succ++)
			{
				// if (!nodeSet.find(succ))
				(*succ)->remove_predecessor(*ns);
				(*succ)->add_predecessor(node);
			}

			erase_node(*ns);
		}

		return node;
	}

	// TODO reduce can disappear
	ControlTree::iterator ControlTree::reduce(Node node, NodeSet nodeSet)
	{
		// replace nodeSet by an abstract region node
		return replace(node, nodeSet);
	}

	void ControlTree::structural_analysis(iterator entry)
	{
		iterator n;
		NodeSet nodeSet;

		do
		{
			_post.clear(); 
			_visit.clear();

			_postMax = 0; 
			_postCtr = 0;

			dfs_postorder(entry);

			while (_nodes.size() > 1 && _postCtr < _postMax)
			{
				n = _post[_postCtr];

				// locate an acyclic region, if present
				Node region = acyclic_region_type(n, nodeSet);
				if (region.rtype() != Invalid)
				{
					iterator p = reduce(region, nodeSet);
					if (nodeSet.find(_entry) != nodeSet.end())
					{
						_entry = p;
					}
				}
			}
		} while (_nodes.size() > 1);
	}
}
