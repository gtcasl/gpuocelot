/*! \file ControlTree.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date June 10, 2010
 *  \brief The source file for the ControlTree class.
 */

// Ocelot includes
#include <ocelot/ir/interface/ControlTree.h>
#include <ocelot/ir/interface/Instruction.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace ir
{
	ControlTree::ControlTree(ControlFlowGraph *cfg) 
		: 
			_nodes(NodeList()),
			_post(NodeList()),
			_postCtr(0),
			_visit(NodeSet()),
			_root(0),
			_size(0)
	{
		Node* start = 0;
		Node* end = 0;
		std::unordered_map<ControlFlowGraph::const_iterator, Node*> bmap;

		ControlFlowGraph::const_iterator bb;
		for (bb = cfg->begin() ; bb != cfg->end() ; bb++)
		{
			report("Inserting node " << bb->label);
			Node *node = insert_node(new InstNode(bb));
			bmap[bb] = node;

			if (bb == cfg->get_entry_block()) start = node;
			if (bb == cfg->get_exit_block()) end = node;
		}

		ControlFlowGraph::const_edge_iterator e;
		for (e = cfg->edges_begin() ; e != cfg->edges_end() ; e++)
		{
			report("Add edge " << e->head->label << " -> " << e->tail->label);
			bmap[e->head]->succs().insert(bmap[e->tail]);
			bmap[e->tail]->preds().insert(bmap[e->head]);
		}

		assertM(start->preds().size() == 0, "Start shouldn't have predecessor");
		assertM(end->succs().size() == 0, "End shouldn't have successor");

		structural_analysis(start);
	}

	ControlTree::~ControlTree()
	{
		NodeList::iterator i;
		for (i = _nodes.begin() ; i != _nodes.end() ; i++) delete *i;
		_nodes.clear();
	}

	ControlTree::Node* ControlTree::insert_node(Node* node)
	{
		_size++;
		_nodes.push_back(node);
		return node;
	}

	ControlTree::Node::Node(const std::string& label, RegionType rtype, 
			const NodeList& children) 
		: _label(label), _rtype(rtype), _children(children)
	{
	}

	ControlTree::Node::~Node()
	{
	}

	const std::string ControlTree::Node::label() const
	{
		return _label;
	}

	ControlTree::Node::RegionType ControlTree::Node::rtype() const
	{
		return _rtype;
	}

	const ControlTree::NodeList& ControlTree::Node::children() const
	{
		return _children;
	}

	ControlTree::NodeSet& ControlTree::Node::succs()
	{
		return _successors;
	}

	ControlTree::NodeSet& ControlTree::Node::preds()
	{
		return _predecessors;
	}

	std::ostream& ControlTree::write(std::ostream& out) const
	{
		//std::unordered_map<NodeList::const_iterator, unsigned int> bmap;
		std::unordered_map<Node*, unsigned int> bmap;

		out << "digraph {" << endl;

		// emit nodes
		out << "  // nodes" << endl;

		int i;
		NodeList::const_iterator n;
		for (n = _nodes.begin(), i = 0 ; n != _nodes.end() ; n++, i++)
		{
			bmap[*n] = i;
			if ((*n)->rtype() == Node::Inst)
			{
				out << "  bb_" << i;
				out	<< " [shape=record,label=\"{" << (*n)->label();

				// emit instructions
				ControlFlowGraph::InstructionList insts = 
					static_cast<InstNode*>(*n)->bb()->instructions;
				ControlFlowGraph::InstructionList::const_iterator ins;
				for (ins = insts.begin() ; ins != insts.end() ; ins++)
				{
					out << " | " << (*ins)->toString();
				} 

				out << "}\"];";
			} else 
			{
				out << "  bb_" << i;
				out << " [label=\"" << (*n)->label() << "\"];";
			}
			out << endl;
		}

		// emit edges
		out << endl << "  // edges" << endl;

		for (n = _nodes.begin() ; n != _nodes.end() ; n++)
		{
			NodeList children = (*n)->children();
			NodeList::const_iterator child;
			for (child = children.begin() ; child != children.end() ; child++)
			{
				out << "  bb_" << bmap[*n];
				out	<< " -> ";
				out	<< "bb_" << bmap[*child];
				out << ";" << endl;
			}
		}
		out << "}" << endl;

		return out;
	}

	const ControlTree::Node* ControlTree::get_root_node() const
	{
		return _root;
	}

	ControlTree::InstNode::InstNode(const ControlFlowGraph::const_iterator& bb)
		: Node(bb->label, Inst, NodeList()), _bb(bb)
	{
	}

	const ControlFlowGraph::const_iterator ControlTree::InstNode::bb() const
	{
		return _bb;
	}

	ControlTree::BlockNode::BlockNode(const std::string& label, 
			const NodeList& children) : Node(label, Block, children)
	{
	}

	ControlTree::IfThenNode::IfThenNode(const std::string& label, Node *cond, 
			Node *ifTrue) : Node(label, IfThen, buildChildren(cond, ifTrue))
	{
	}

	const ControlTree::NodeList ControlTree::IfThenNode::buildChildren(
			Node *cond, Node *ifTrue) const
	{
		NodeList nodes;

		nodes.push_back(cond);
		nodes.push_back(ifTrue);

		return nodes;
	}

	const ControlTree::Node* ControlTree::IfThenNode::cond() const
	{
		return children().front();
	}

	const ControlTree::Node* ControlTree::IfThenNode::ifTrue() const
	{
		return children().back();
	}

	ControlTree::SelfLoopNode::SelfLoopNode(const std::string& l, Node* body) 
		: Node(l, SelfLoop, NodeList(1, body))
	{
	}

	const ControlTree::Node* ControlTree::SelfLoopNode::body() const
	{
		return children().front();
	}

	ControlTree::InvalidNode::InvalidNode() : Node("", Invalid, NodeList())
	{
	}

	void ControlTree::dfs_postorder(Node* x)
	{
		_visit.insert(x);

		NodeSet::iterator y;
		for (y = x->succs().begin() ; y != x->succs().end() ; y++)
		{
			if (_visit.find(*y) != _visit.end()) continue;
			dfs_postorder(*y);
		}
		_post.push_back(x);
		report("dfs_postorder: Added " << x->label());
	}

	ControlTree::Node* ControlTree::acyclic_region_type(Node* node, 
			NodeSet& nset)
	{
		Node* n;
		bool p, s;
		NodeList nodes;

		nset.clear();

		// check for a Block containing node
		n = node;
		p = true;
		s = (n->succs().size() == 1);

		while (p && s)
		{
			if (nset.insert(n).second) nodes.push_back(n);
			n = *(n->succs().begin());
			p = (n->preds().size() == 1);
			s = (n->succs().size() == 1);
		}

		if (p)
		{
			if (nset.insert(n).second) nodes.push_back(n);
		}

		n = node;
		p = (n->preds().size() == 1);
		s = true;

		while (p && s)
		{
			if (nset.insert(n).second) nodes.push_front(n);
			n = *(n->preds().begin());
			p = (n->preds().size() == 1);
			s = (n->succs().size() == 1);
		}

		if (s)
		{
			if (nset.insert(n).second) nodes.push_front(n);
		}

		node = n;
		if (nodes.size() >= 2)
		{
			std::string label("BlockNode_");

			std::stringstream ss;
			ss << _nodes.size();
			label += ss.str();

			report("Found " << label << ": " << nodes.front()->label() << "..."
					<< nodes.back()->label());

			return new BlockNode(label, nodes);
		} else if (node->succs().size() == 2)
		{
			Node *m;

			m = *(node->succs().begin());
			n = *(++(node->succs().begin()));

			// check for an IfThen (if node then n)
			if (n->succs().size() == 1 && n->preds().size() == 1 &&
					m->preds().size() == 2 && *(n->succs().begin()) == m)
			{
				nset.clear(); nset.insert(node); nset.insert(n);

				std::string label("IfThenNode_");

				std::stringstream ss;
				ss << _nodes.size();
				label += ss.str();

				report("Found " << label << ":" << " if " << node->label() 
						<< " then " << n->label());

				return new IfThenNode(label, node, n);
			}

			// check for an IfThen (if node then m)
			if (m->succs().size() == 1 && m->preds().size() == 1 &&
					n->preds().size() == 2 && *(m->succs().begin()) == n)
			{
				nset.clear(); nset.insert(node); nset.insert(m);

				std::string label("IfThenNode_");

				std::stringstream ss;
				ss << _nodes.size();
				label += ss.str();

				report("Found " << label << ":" << " if " << node->label()
						<< " then " << m->label());

				return new IfThenNode(label, node, m);
			}
		}

		report("Couldn't find any acyclic regions");
		return new InvalidNode();
	}

	void ControlTree::compact(Node* node, NodeSet nodeSet)
	{
		insert_node(node);

		NodeList::iterator n, pos;
		for (n = _post.begin() ; n != _post.end() && !nodeSet.empty() ; )
		{
			if (!nodeSet.erase(*n))
			{
				n++;
				continue;
			}

			n = _post.erase(n);
			pos = n;
			_size--;
		}

		_postCtr = _post.insert(pos, node);
	}

	void ControlTree::reduce(Node* node, NodeSet nodeSet)
	{
		// link region node into abstract flowgraph, adjust the post order
		// traversal and predecessor and successor functions, and augment the
		// control tree
		compact(node, nodeSet);

		NodeSet::iterator n;
		for (n = nodeSet.begin() ; n != nodeSet.end() ; n++)
		{
			NodeSet::iterator p;
			for (p = (*n)->preds().begin() ; p != (*n)->preds().end() ; p++)
			{
				if (nodeSet.find(*p) != nodeSet.end()) continue;

				report("Rem edge " << (*p)->label() << " -> " << (*n)->label());
				(*p)->succs().erase(*n);

				report("Add edge " << (*p)->label() << " -> " << node->label());
				(*p)->succs().insert(node);
				node->preds().insert(*p);
			}

			NodeSet::iterator s;
			for (s = (*n)->succs().begin() ; s != (*n)->succs().end() ; s++)
			{
				if (nodeSet.find(*s) != nodeSet.end()) continue;

				report("Rem edge " << (*n)->label() << " -> " << (*s)->label());
				(*s)->preds().erase(*n);

				report("Add edge " << node->label() << " -> " << (*s)->label());
				(*s)->preds().insert(node);
				node->succs().insert(*s);
			}
		}
	}

	ControlTree::Node* ControlTree::cyclic_region_type(Node* node, 
			NodeSet& nset)
	{
		if (nset.size() == 1)
		{
			if (node->succs().find(node) != node->succs().end())
			{
				std::string label("SelfLoopNode_");

				std::stringstream ss;
				ss << _nodes.size();
				label += ss.str();

				report("Found " << label << ": " << node->label());
				return new SelfLoopNode(label, node);
			} else
			{
				report("Couldn't find any cyclic regions");
				return new InvalidNode();
			}
		}

		report("Couldn't find any cyclic regions");
		return new InvalidNode();
	}

	void ControlTree::structural_analysis(Node* entry)
	{
		Node* n;
		NodeSet nodeSet, reachUnder;
		bool changed;

		report("Starting Structural Analysis...");
		do
		{
			changed = false;

			_post.clear(); 
			_visit.clear();

			report("DFS Postorder");
			dfs_postorder(entry);

			_postCtr = _post.begin();

			while (_size > 1 && _postCtr != _post.end())
			{
				n = *_postCtr;

				// locate an acyclic region, if present
				report("Looking for acyclic region from " << n->label());
				Node* region = acyclic_region_type(n, nodeSet);

				if (region->rtype() != Node::Invalid)
				{
					report("Replacing nodeSet for " << region->label());
					reduce(region, nodeSet);

					changed = true;

					if (nodeSet.find(entry) != nodeSet.end())
					{
						entry = region;
					}
				} else
				{
					// locate a cyclic region, if present
					reachUnder.clear(); reachUnder.insert(n);

					// TODO cyclic control structure with multiples nodes are
					// not handled yet
					report("Looking for cyclic region from " << n->label());
					region = cyclic_region_type(n, reachUnder);

					if (region->rtype() != Node::Invalid)
					{
						report("Replacing nodeSet for " << region->label());
						reduce(region, reachUnder);

						changed = true;

						if (reachUnder.find(entry) != reachUnder.end())
						{
							entry = region;
						}
					} else
					{
						_postCtr++;
					}
				}
			}

			assertM(changed, "Irreducible CFG");
		} while (_size > 1);

		_root = entry;
	}
}
