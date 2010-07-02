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

#include <unordered_set>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace ir
{
	ControlTree::ControlTree(ControlFlowGraph *cfg) : _size(0)
	{
		iterator entryNode, exitNode;
		std::unordered_map<ControlFlowGraph::const_iterator, iterator> bmap;

		ControlFlowGraph::const_iterator bb;
		for (bb = cfg->begin() ; bb != cfg->end() ; bb++)
		{
			report("Inserting node " << bb->label);
			iterator node = insert_node(new InstNode(bb));
			bmap[bb] = node;

			if (bb == cfg->get_entry_block()) entryNode = node;
			if (bb == cfg->get_exit_block()) exitNode = node;
		}

		ControlFlowGraph::const_edge_iterator edge;
		for (edge = cfg->edges_begin() ; edge != cfg->edges_end() ; edge++)
		{
			report("Adding edge " 
					<< edge->head->label << " -> " << edge->tail->label);
			(*bmap[edge->head])->add_successor(bmap[edge->tail]);
			(*bmap[edge->tail])->add_predecessor(bmap[edge->head]);
		}

		assertM((*entryNode)->predecessors().size() == 0,
				"Entry node should have no predecessors");

		assertM((*exitNode)->successors().size() == 0,
				"Exit node should have no successors");

		structural_analysis(entryNode);
	}

	ControlTree::~ControlTree()
	{
		const_iterator i;
		for (i = _nodes.begin() ; i != _nodes.end() ; i++) delete *i;
		_nodes.clear();
	}

	ControlTree::iterator ControlTree::insert_node(Node* node)
	{
		_size++;
		return _nodes.insert(_nodes.end(), node);
	}

	ControlTree::Node::Node(const std::string& l, RegionType rtype, 
			const NodePointerVector& children) 
		: _label(l), _rtype(rtype), _children(children)
	{
	}

	const std::string& ControlTree::Node::label() const
	{
		return _label;
	}

	const ControlTree::RegionType& ControlTree::Node::rtype() const
	{
		return _rtype;
	}

	ControlTree::NodePointerVector& ControlTree::Node::children()
	{
		return _children;
	}

	const ControlTree::NodePointerVector& ControlTree::Node::children() const
	{
		return _children;
	}

	ControlTree::NodeSet& ControlTree::Node::successors()
	{
		return _successors;
	}

	ControlTree::NodeSet& ControlTree::Node::predecessors()
	{
		return _predecessors;
	}

	void ControlTree::Node::add_successor(iterator succ)
	{
		successors().insert(succ);
	}

	void ControlTree::Node::remove_successor(iterator succ)
	{
		successors().erase(successors().find(succ));
	}

	void ControlTree::Node::add_predecessor(iterator pred)
	{
		predecessors().insert(pred);
	}

	void ControlTree::Node::remove_predecessor(iterator pred)
	{
		predecessors().erase(predecessors().find(pred));
	}

	std::ostream& ControlTree::write(std::ostream& out) const
	{
		using namespace std;

		std::unordered_map<const_iterator, unsigned int> bmap;

		out << "digraph {" << endl;

		// emit nodes
		out << "  // nodes" << endl;

		int n = 0;
		const_iterator nodeIt;
		for (nodeIt = _nodes.begin() ; nodeIt != _nodes.end() ; nodeIt++, n++)
		{
			bmap[nodeIt] = n;
			Node* node = *nodeIt;
			if (node->rtype() != Inst)
			{
				out << "  bb_" << n << " [label=\"" << node->label() << "\"];";
			} else 
			{
				out << "  bb_" << n << " [shape=record,label=\"{" << node->label();

				InstNode::const_iterator ins;
				const InstNode inode = static_cast<const InstNode&>(*node);
				for (ins = inode.begin() ; ins != inode.end() ; ins++)
				{
					out << " | " << (*ins)->toString();
				} 

				out << "}\"];";
			}
			out << endl;
		}

		// emit edges
		out << endl << "  // edges" << endl;

		for (nodeIt = _nodes.begin() ; nodeIt != _nodes.end() ; nodeIt++)
		{
			Node *node = *nodeIt;
			const_pointer_iterator child;
			for (child = node->children().begin() ; 
					child != node->children().end() ; child++)
			{
				out << "  bb_" << bmap[nodeIt];
				out	<< " -> ";
				out	<< "bb_" << bmap[*child];
				out << ";" << endl;
			}
		}

		out << "}" << endl;

		return out;
	}

	ControlTree::const_iterator ControlTree::get_root_node() const
	{
		return _root;
	}

	ControlTree::InstNode::InstNode(const ControlFlowGraph::const_iterator& bb)
		: Node(bb->label, Inst)
	{
		_instructions = bb->instructions;
	}

	ControlTree::InstNode::const_iterator ControlTree::InstNode::begin() const
	{
		return _instructions.begin();
	}

	ControlTree::InstNode::const_iterator ControlTree::InstNode::end() const
	{
		return _instructions.end();
	}

	ControlTree::InstNode::InstructionList& 
		ControlTree::InstNode::instructions()
	{
		return _instructions;
	}

	ControlTree::BlockNode::BlockNode(const NodePointerVector& children, 
			const std::string& l) : Node(l, Block, children)
	{
	}

	ControlTree::const_pointer_iterator ControlTree::BlockNode::begin() const
	{
		return children().begin();
	}

	ControlTree::const_pointer_iterator ControlTree::BlockNode::end() const
	{
		return children().end();
	}

	ControlTree::IfThenNode::IfThenNode(iterator cond, 
			iterator ifTrue, const std::string& l) 
		: Node(l, IfThen)
	{
		children().push_back(cond);
		children().push_back(ifTrue);
	}

	ControlTree::Node* ControlTree::IfThenNode::cond() const
	{
		return *children().front();
	}

	ControlTree::Node* ControlTree::IfThenNode::ifTrue() const
	{
		return *children().back();
	}

	ControlTree::SelfLoopNode::SelfLoopNode(iterator body, const std::string& l) 
		: Node(l, SelfLoop)
	{
		children().push_back(body);
	}

	ControlTree::Node* ControlTree::SelfLoopNode::body() const
	{
		return *children().front();
	}

	void ControlTree::dfs_postorder(iterator x)
	{
		_visit.insert(x);

		NodeSet::iterator y;
		for (y = (*x)->successors().begin() ; y != (*x)->successors().end() ; y++)
		{
			if (_visit.find(*y) != _visit.end()) continue;
			dfs_postorder(*y);
		}
		_postMax++;
		_post.push_back(x);
		report("dfs_postorder: Added " << (*x)->label());
	}

	ControlTree::Node* ControlTree::acyclic_region_type(iterator& node, 
			NodeSet& nset)
	{
		iterator n;
		bool p, s;
		NodePointerVector nodes;

		nset.clear();

		// check for a Block containing node
		n = node;
		p = true;
		s = ((*n)->successors().size() == 1);

		while (p && s)
		{
			if (nset.insert(n).second) nodes.push_back(n);
			n = *((*n)->successors().begin());
			p = ((*n)->predecessors().size() == 1);
			s = ((*n)->successors().size() == 1);
		}

		if (p)
		{
			if (nset.insert(n).second) nodes.push_back(n);
		}

		n = node;
		p = ((*n)->predecessors().size() == 1);
		s = true;

		while (p && s)
		{
			if (nset.insert(n).second) nodes.insert(nodes.begin(), n);
			n = *((*n)->predecessors().begin());
			p = ((*n)->predecessors().size() == 1);
			s = ((*n)->successors().size() == 1);
		}

		if (s)
		{
			if (nset.insert(n).second) nodes.insert(nodes.begin(), n);
		}

		node = n;
		if (nodes.size() >= 2)
		{
			std::stringstream label;
			label << "BlockNode_" << _nodes.size();

			report("Found " << label.str() << ": "
					<< (*(nodes.front()))->label()
					<< " ... "
					<< (*(nodes.back()))->label());

			return new BlockNode(nodes, label.str());
		} else if ((*node)->successors().size() == 2)
		{
			iterator m;

			m = *((*node)->successors().begin());
			n = *(++((*node)->successors().begin()));

			// check for an IfThen (if node then n)
			if ((*n)->successors().size() == 1 && (*n)->predecessors().size() == 1 &&
					(*m)->predecessors().size() == 2 && 
					*((*n)->successors().begin()) == m)
			{
				nset.clear(); nset.insert(node); nset.insert(n);
				std::stringstream label;
				label << "IfThenNode_" << _nodes.size();

				report("Found " << label.str() << ":"
						<< " if " << (*node)->label()
						<< " then " << (*n)->label()
						);

				return new IfThenNode(node, n, label.str());
			}

			// check for an IfThen (if node then m)
			if ((*m)->successors().size() == 1 && (*m)->predecessors().size() == 1 &&
					(*n)->predecessors().size() == 2 && 
					*((*m)->successors().begin()) == n)
			{
				nset.clear(); nset.insert(node); nset.insert(m);
				std::stringstream label;
				label << "IfThenNode_" << _nodes.size();

				report("Found " << label.str() << ":"
						<< " if " << (*node)->label()
						<< " then " << (*m)->label()
						);

				return new IfThenNode(node, m, label.str());
			}
		}

		report("Couldn't find any acyclic regions");
		return new Node(); 
	}

	ControlTree::iterator ControlTree::compact(Node* n, NodeSet nodeSet)
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
			_size--;
		}

		_postMax++;
		_post.insert(pos, node);
		_postCtr = pos - _post.begin();

		return node;
	}

	ControlTree::iterator ControlTree::replace(Node* n, NodeSet nodeSet)
	{
		// link region node into abstract flowgraph, adjust the post order
		// traversal and predecessor and successor functions, and augment the
		// control tree
		iterator node = compact(n, nodeSet);

		NodeSet::iterator ns;
		for (ns = nodeSet.begin() ; ns != nodeSet.end() ; ns++)
		{
			NodeSet::iterator pred;
			for (pred = (**ns)->predecessors().begin() ; 
					pred != (**ns)->predecessors().end() ; pred++)
			{
				if (nodeSet.find(*pred) != nodeSet.end()) continue;

				(**pred)->remove_successor(*ns);
				(**pred)->add_successor(node);
				(*node)->add_predecessor(*pred);
			}

			NodeSet::iterator succ;
			for (succ = (**ns)->successors().begin() ;
					succ != (**ns)->successors().end() ; succ++)
			{
				if (nodeSet.find(*succ) != nodeSet.end()) continue;

				(**succ)->remove_predecessor(*ns);
				(**succ)->add_predecessor(node);
				(*node)->add_successor(*succ);
			}
		}

		return node;
	}

	ControlTree::Node* ControlTree::cyclic_region_type(iterator& node, 
			NodeSet& nset)
	{
		if (nset.size() == 1)
		{
			if ((*node)->successors().find(node) != (*node)->successors().end())
			{
				std::stringstream label;
				label << "SelfLoopNode_" << _nodes.size();

				report("Found " << label.str() << ": "
						<< (*node)->label());

				return new SelfLoopNode(node, label.str());
			} else
			{
				report("Couldn't find any cyclic regions");
				return new Node();
			}
		}

		report("Couldn't find any cyclic regions");
		return new Node(); 
	}

	void ControlTree::structural_analysis(iterator entry)
	{
		iterator n;
		NodeSet nodeSet, reachUnder;
		bool changed;

		report("Starting Structural Analysis...");
		do
		{
			changed = false;

			_post.clear(); 
			_visit.clear();

			_postMax = 0; 
			_postCtr = 0;

			report("DFS Postorder");
			dfs_postorder(entry);

			while (_size > 1 && _postCtr < _postMax)
			{
				n = _post[_postCtr];

				// locate an acyclic region, if present
				report("Looking for acyclic region from " << (*n)->label());
				Node* region = acyclic_region_type(n, nodeSet);

				if (region->rtype() != Invalid)
				{
					report("Replacing nodeSet for " << region->label());
					iterator p = replace(region, nodeSet);

					changed = true;

					if (nodeSet.find(entry) != nodeSet.end())
					{
						entry = p;
					}
				} else
				{
					// locate a cyclic region, if present
					reachUnder.clear(); reachUnder.insert(n);

					// TODO cyclic control structure with multiples nodes are
					// not handled yet
					region = cyclic_region_type(n, reachUnder);

					if (region->rtype() != Invalid)
					{
						report("Replacing nodeSet for " << region->label());
						iterator p = replace(region, reachUnder);

						changed = true;

						if (reachUnder.find(entry) != reachUnder.end())
						{
							entry = p;
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
