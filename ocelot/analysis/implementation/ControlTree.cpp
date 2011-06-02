/*! \file ControlTree.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date June 10, 2010
 *  \brief The source file for the ControlTree class.
 */

// Ocelot includes
#include <ocelot/analysis/interface/ControlTree.h>
#include <ocelot/ir/interface/Instruction.h>

// Hydrazine includes
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

// STL includes
#include <algorithm>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{
	ControlTree::ControlTree(CFG *cfg) 
		: 
			_nodes(NodeList()),
			_post(NodeList()),
			_visit(NodeSet()),
			_root(0),
			_size(0)
	{
		Node* start = 0;
		Node* end = 0;
		std::unordered_map<CFG::const_iterator, Node*> bmap;

		CFG::const_iterator bb;
		for (bb = cfg->begin() ; bb != cfg->end() ; bb++)
		{
			report("Inserting node " << bb->label);
			Node *node = _insert_node(new InstNode(bb));
			bmap[bb] = node;
		}

		start = bmap[cfg->get_entry_block()];
		end = bmap[cfg->get_exit_block()];

		CFG::const_edge_iterator e;
		for (e = cfg->edges_begin() ; e != cfg->edges_end() ; e++)
		{
			CFG::const_iterator h = e->head;
			CFG::const_iterator t = e->tail;

			bmap[h]->succs().insert(bmap[t]);
			bmap[t]->preds().insert(bmap[h]);

			if (e->type == CFG::Edge::FallThrough)
			{
				report("Add edge " << h->label << " --> " << t->label);
				bmap[h]->fallthrough() = bmap[t];
			} else
			{
				report("Add edge " << h->label << " -> " << t->label);
			}
		}

		assertM(start->preds().size() == 0, "Start shouldn't have predecessor");
		assertM(end->succs().size() == 0, "End shouldn't have successor");

		_structural_analysis(start);
	}

	ControlTree::~ControlTree()
	{
		NodeList::iterator i;
		for (i = _nodes.begin() ; i != _nodes.end() ; i++) delete *i;
		_nodes.clear();
	}

	ControlTree::Node* ControlTree::_insert_node(Node* node)
	{
		_size++;
		_nodes.push_back(node);
		return node;
	}

	ControlTree::Node::Node(const std::string& label, RegionType rtype, 
			const NodeList& children) 
		: _label(label), _rtype(rtype), _children(children), _fallthrough(0)
	{
	}

	ControlTree::Node::~Node()
	{
	}

	const std::string& ControlTree::Node::label() const
	{
		return _label;
	}

	ControlTree::RegionType ControlTree::Node::rtype() const
	{
		return _rtype;
	}

	const ControlTree::NodeList& ControlTree::Node::children() const
	{
		return _children;
	}

	ControlTree::NodeSet& ControlTree::Node::succs()
	{
		return _succs;
	}

	ControlTree::NodeSet& ControlTree::Node::preds()
	{
		return _preds;
	}

	ControlTree::Node*& ControlTree::Node::fallthrough()
	{
		return _fallthrough;
	}

	std::ostream& ControlTree::write(std::ostream& out) const
	{
		std::unordered_map<Node*, unsigned int> bmap;

		out << "digraph {" << std::endl;

		// emit nodes
		out << "  // nodes" << std::endl;

		int i;
		NodeList::const_iterator n;
		for (n = _nodes.begin(), i = 0 ; n != _nodes.end() ; n++, i++)
		{
			bmap[*n] = i;
			if ((*n)->rtype() == Inst)
			{
				out << "  bb_" << i;
				out	<< " [shape=record,label=\"{" << (*n)->label();

				// emit instructions
				InstNode* m = static_cast<InstNode *>(*n);
				for (InstructionList::const_iterator 
						ins = m->insts().begin(), end = m->insts().end() ;
						ins != end ; ins++)
				{
					out << " | " << 
						hydrazine::toGraphVizParsableLabel((*ins)->toString());
				}

				out << "}\"];";
			} else 
			{
				out << "  bb_" << i;
				out << " [label=\"" << (*n)->label() << "\"];";
			}
			out << std::endl;
		}

		// emit edges
		out << std::endl << "  // edges" << std::endl;

		for (n = _nodes.begin() ; n != _nodes.end() ; n++)
		{
			NodeList children = (*n)->children();
			NodeList::const_iterator child;
			for (child = children.begin() ; child != children.end() ; child++)
			{
				out << "  bb_" << bmap[*n];
				out	<< " -> ";
				out	<< "bb_" << bmap[*child];
				out << ";" << std::endl;
			}
		}
		out << "}" << std::endl;

		return out;
	}

	const ControlTree::Node* ControlTree::get_root_node() const
	{
		return _root;
	}

	ControlTree::InstNode::InstNode(const CFG::const_iterator& bb)
		: Node(bb->label, Inst, NodeList()), _bb(bb)
	{
	}

	const ControlTree::InstructionList& ControlTree::InstNode::insts() const
	{
		return _bb->instructions;
	}

	ControlTree::BlockNode::BlockNode(const std::string& label, 
			const NodeList& children) : Node(label, Block, children)
	{
	}

	ControlTree::IfThenNode::IfThenNode(const std::string& label, 
			Node* cond, Node* ifTrue, Node* ifFalse) 
		: Node(label, IfThen, buildChildren(cond, ifTrue, ifFalse))
	{
	}

	const ControlTree::NodeList ControlTree::IfThenNode::buildChildren(
			Node* cond, Node* ifTrue, Node* ifFalse) const
	{
		NodeList nodes;

		nodes.push_back(cond);
		nodes.push_back(ifTrue);
		nodes.push_back(ifFalse);

		return nodes;
	}

	const ControlTree::Node* ControlTree::IfThenNode::cond() const
	{
		return children().front();
	}

	const ControlTree::Node* ControlTree::IfThenNode::ifTrue() const
	{
		return *(++(children().begin()));
	}

	const ControlTree::Node* ControlTree::IfThenNode::ifFalse() const
	{
		return children().back();
	}

	ControlTree::WhileNode::WhileNode(const std::string& label, 
			const NodeList& children) : Node(label, While, children)
	{
	}

	ControlTree::NaturalNode::NaturalNode(const std::string& label, 
			const NodeList& children) : Node(label, Natural, children)
	{
	}

	ControlTree::InvalidNode::InvalidNode() : Node("", Invalid, NodeList())
	{
	}

	void ControlTree::_dfs_postorder(Node* x)
	{
		_visit.insert(x);

		NodeSet::iterator y;
		for (y = x->succs().begin() ; y != x->succs().end() ; y++)
		{
			if (_visit.find(*y) != _visit.end()) continue;
			_dfs_postorder(*y);
		}
		_post.push_back(x);
		report("_dfs_postorder: Added " << x->label());
	}

	ControlTree::Node* ControlTree::_acyclic_region_type(Node* node, 
			NodeSet& nset)
	{
		Node* n;
		bool p, s;
		NodeList nodes; // TODO Implement nodes as an ordered set

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
					*(n->succs().begin()) == m)
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
					*(m->succs().begin()) == n)
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

			// check for an IfThen (if node then n else m)
			if (m->succs().size() == 1 && n->succs().size() == 1 &&
					m->preds().size() == 1 && n->preds().size() == 1 &&
					*(m->succs().begin()) == *(n->succs().begin()) &&
					node->fallthrough() == n)
			{
				nset.clear(); nset.insert(node); nset.insert(n); nset.insert(m);

				std::string label("IfThenNode_");

				std::stringstream ss;
				ss << _nodes.size();
				label += ss.str();

				report("Found " << label << ":" << " if " << node->label()
						<< " then " << n->label() << " else " << m->label());

				return new IfThenNode(label, node, n, m);
			}

			// check for an IfThen (if node then m else n)
			if (m->succs().size() == 1 && n->succs().size() == 1 &&
					m->preds().size() == 1 && n->preds().size() == 1 &&
					*(m->succs().begin()) == *(n->succs().begin()) &&
					node->fallthrough() == m)
			{
				nset.clear(); nset.insert(node); nset.insert(m); nset.insert(n);

				std::string label("IfThenNode_");

				std::stringstream ss;
				ss << _nodes.size();
				label += ss.str();

				report("Found " << label << ":" << " if " << node->label()
						<< " then " << m->label() << " else " << n->label());

				return new IfThenNode(label, node, m, n);
			}
		}

		report("Couldn't find any acyclic regions");
		return new InvalidNode();
	}

	bool ControlTree::_isCyclic(Node* node)
	{
		if (node->rtype() == While) return true;
		if (node->rtype() == Natural) return true;

		return false;
	}

	bool ControlTree::_backedge(Node* head, Node* tail)
	{
		// head->tail is a back-edge if tail dominates head
		// (tail dominates head if head appears first in the _post list)
		Node* match[] = {head, tail};
		NodeList::iterator n = 
			find_first_of(_post.begin(), _post.end(), match, match + 2);
		
		if (*n == head) return true;
		if (*n == tail) return false;

		assertM(false, "Neither head nor tail are valid nodes");
		
		return false;
	}

	void ControlTree::_compact(Node* node, NodeSet nodeSet)
	{
		_insert_node(node);

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

	void ControlTree::_reduce(Node* node, NodeSet nodeSet)
	{
		// link region node into abstract flowgraph, adjust the predecessor and 
		// successor functions, and augment the control tree
		NodeSet::iterator n;
		for (n = nodeSet.begin() ; n != nodeSet.end() ; n++)
		{
			NodeSet::iterator p;
			for (p = (*n)->preds().begin() ; p != (*n)->preds().end() ; p++)
			{
				// ignore edges between nodeSet nodes
				// (except for back-edges which we check below)
				if (nodeSet.find(*p) != nodeSet.end()) continue;

				report("Del " << (*p)->label() << " -> " << (*n)->label());
				(*p)->succs().erase(*n);

				(*p)->succs().insert(node);
				node->preds().insert(*p);

				if ((*p)->fallthrough() == *n)
				{
					report("Add " << (*p)->label() << " --> " << node->label());
					(*p)->fallthrough() = node;
				} else 
				{
					report("Add " << (*p)->label() << " -> " << node->label());
				}
			}

			NodeSet::iterator s;
			for (s = (*n)->succs().begin() ; s != (*n)->succs().end() ; s++)
			{
				// ignore edges between nodeSet nodes
				// (except for back-edges which we check below)
				if (nodeSet.find(*s) != nodeSet.end()) continue;

				report("Del " << (*n)->label() << " -> " << (*s)->label());
				(*s)->preds().erase(*n);

				(*s)->preds().insert(node);
				node->succs().insert(*s);

				if ((*n)->fallthrough() == *s) 
				{
					report("Add " << node->label() << " --> " << (*s)->label());
					node->fallthrough() = *s;
				} else
				{
					report("Add " << node->label() << " -> " << (*s)->label());
				}
			}
		}

		// if not cyclic then check for back-edges between nodeSet nodes
		if (!_isCyclic(node))
		{
			for (n = nodeSet.begin() ; n != nodeSet.end() ; n++)
			{
				bool shouldbreak = false;
				NodeSet::iterator p;
				for (p = (*n)->preds().begin() ; p != (*n)->preds().end() ; p++)
				{
					if (nodeSet.find(*p) == nodeSet.end()) continue;

					if (_backedge(*p, *n)) 
					{
						// add back-edge region->region
						report("Add " << node->label() << " -> " << node->label());
						node->preds().insert(node);
						node->succs().insert(node);

						// no need to add more than one back-edge
						shouldbreak = true;
						break;
					}
				}
				if (shouldbreak) break;
			}
		}

		// adjust the postorder traversal
		_compact(node, nodeSet);
	}

	// returns true if there is a (possibly empty) path from m to k that does
	// not pass through n
	bool ControlTree::_path(Node* m, Node* k, Node* n)
	{
		if (m == n || _visit.find(m) != _visit.end()) return false;
		if (m == k) return true;

		_visit.insert(m);

		for (NodeSet::const_iterator s = m->succs().begin() ;
				s != m->succs().end() ; s++)
		{
			if (_path(*s, k, n)) return true;
		}

		return false;
	}

	// returns true if there is a node k such that there is a (possibly empty)
	// path from m to k that does not pass through n and an edge k->n that is a
	// back edge, and false otherwise.
	bool ControlTree::_path_back(Node* m, Node* n)
	{
		for (NodeSet::const_iterator k = n->preds().begin() ;
				k != n->preds().end() ; k++)
		{
			if (_backedge(*k, n))
			{
				_visit.clear();
				if (_path(m, *k, n)) return true;
			}
		}

		return false;
	}

	ControlTree::Node* ControlTree::_cyclic_region_type(Node* node, 
			NodeList& nset)
	{
		if (nset.size() == 1)
		{
			if (node->succs().find(node) != node->succs().end())
			{
				// Self loop is a special case of a Natural loop
				std::string label("NaturalNode_");

				std::stringstream ss;
				ss << _nodes.size();
				label += ss.str();

				report("Found " << label << ": " << node->label());
				return new NaturalNode(label, NodeList(1, node));
			} else
			{
				report("Couldn't find any cyclic regions");
				return new InvalidNode();
			}
		}

		for (NodeList::const_iterator m = nset.begin() ;
				m != nset.end() ; m++)
		{
			_visit.clear();
			if (!_path(node, *m)) {
				// it's an Improper region
				// TODO Improper regions are not supported yet
				report("Found Improper region");
				return new InvalidNode();
			}
		}

		// check for a While loop
		Node* m = *(++nset.begin());

		if (node->succs().size() == 2 && m->succs().size() == 1 
				&& node->preds().size() == 2 && m->preds().size() == 1)
		{
			std::string label("WhileNode_");

			std::stringstream ss;
			ss << _nodes.size();
			label += ss.str();

			report("Found " << label << ": " << nset.front()->label() << "..."
					<< nset.back()->label());

			return new WhileNode(label, nset);
		}

		// it's a Natural loop
		std::string label("NaturalNode_");

		std::stringstream ss;
		ss << _nodes.size();
		label += ss.str();

		report("Found " << label << ": " << nset.front()->label() << "..."
				<< nset.back()->label());

		return new NaturalNode(label, nset);
	}

	void ControlTree::_structural_analysis(Node* entry)
	{
		Node* n;
		NodeSet nodeSet;
		NodeList reachUnder; // TODO Implement reachUnder as an ordered set
		bool changed;

		report("Starting Structural Analysis...");
		do
		{
			changed = false;

			_post.clear(); 
			_visit.clear();

			report("DFS Postorder");
			_dfs_postorder(entry);

			_postCtr = _post.begin();

			while (_size > 1 && _postCtr != _post.end())
			{
				n = *_postCtr;

				// locate an acyclic region, if present
				report("Looking for acyclic region from " << n->label());
				Node* region = _acyclic_region_type(n, nodeSet);

				if (region->rtype() != Invalid)
				{
					report("Replacing nodeSet for " << region->label());
					_reduce(region, nodeSet);

					changed = true;

					if (nodeSet.find(entry) != nodeSet.end())
					{
						entry = region;
					}
				} else
				{
					// locate a cyclic region, if present
					reachUnder.clear(); nodeSet.clear();

					for (NodeList::const_iterator m = _post.begin() ;
							m != _post.end() ; m++)
					{
						if (*m != n && _path_back(*m, n)) 
						{
							report("Add " << (*m)->label() << " to reachUnder");
							reachUnder.push_front(*m); nodeSet.insert(*m);
						}
					}
					reachUnder.push_front(n); nodeSet.insert(n);

					report("Looking for cyclic region from " << n->label());
					region = _cyclic_region_type(n, reachUnder);

					if (region->rtype() != Invalid)
					{
						report("Replacing nodeSet for " << region->label());
						_reduce(region, nodeSet);

						changed = true;

						if (nodeSet.find(entry) != nodeSet.end())
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
