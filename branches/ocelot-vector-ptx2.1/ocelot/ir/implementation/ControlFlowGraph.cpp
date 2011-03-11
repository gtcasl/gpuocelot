/*! \file ControlFlowGraph.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implementation for ControlFlowGraph
	\date 28 September 2008; 21 Jan 2009
*/

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PTXInstruction.h>

#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define FAST_RANDOM_LAYOUT 1
#define PRESERVE_SOURCE_LAYOUT 2

#define LAYOUT_SCHEME PRESERVE_SOURCE_LAYOUT

namespace ir {


////////////////////////////////////////////////////////////////////////////////

class BlockSetCompare {
public:
	bool operator()(const ir::ControlFlowGraph::iterator &a_it,
		const ir::ControlFlowGraph::iterator &b_it) const {
		return a_it->label < b_it->label;
	}
};

BasicBlock::DotFormatter::DotFormatter() { }
BasicBlock::DotFormatter::~DotFormatter() { }

/*!
	\brief emits label for entry block
*/
std::string BasicBlock::DotFormatter::entryLabel(
	const BasicBlock *block) {
	std::stringstream out;
	out << "[shape=Mdiamond,label=\"" << block->label << "\"]";	
	return out.str();
}

/*!
	\brief emits label for exit block
*/
std::string BasicBlock::DotFormatter::exitLabel(
	const BasicBlock *block) {
	std::stringstream out;
	out << "[shape=Msquare,label=\"" << block->label << "\"]";	
	return out.str();
}

std::string BasicBlock::DotFormatter::toString(
	const BasicBlock *block) {
	std::stringstream out;

	out << "[shape=record,";
	out << "label=";
	out << "\"{" << hydrazine::toGraphVizParsableLabel(block->label);

	BasicBlock::InstructionList::const_iterator instrs 
		= block->instructions.begin();	
	for (; instrs != block->instructions.end(); ++instrs) {
		out << " | " 
		<< hydrazine::toGraphVizParsableLabel((*instrs)->toString());
	}
	out << "}\"]";

	return out.str();
}

std::string BasicBlock::DotFormatter::toString(
	const Edge *edge) {
	std::stringstream out;

	if (edge->type == Edge::Dummy) {
		out << "[style=dotted]";
	}
	else if (edge->type == Edge::Branch) {
		out << "[color=blue]";
	}

	return out.str();
}

////////////////////////////////////////////////////////////////////////////////

BasicBlock::Edge::Edge(BlockList::iterator h, 
	BlockList::iterator t, Type y) : head(h), tail(t), type(y) {

}

BasicBlock::BasicBlock(const std::string& l, Id i, 
	const InstructionList& is) : label(l), id(i) {
	for (InstructionList::const_iterator instruction = is.begin();
		instruction != is.end(); ++instruction ) {
		instructions.push_back((*instruction)->clone(true));
	}
}

BasicBlock::~BasicBlock() {

}

void BasicBlock::clear() {
	for (InstructionList::iterator instruction = instructions.begin();
		instruction != instructions.end(); ++instruction ) {
		delete *instruction;
	}
	instructions.clear();
}

BasicBlock::EdgeList::iterator 
	BasicBlock::get_fallthrough_edge() {
	for (EdgePointerVector::iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge) {
		if ((*edge)->type == Edge::FallThrough) return *edge;
	}
	assertM(false, "No fallthrough edge in block " << label);
	return EdgeList::iterator();
}

BasicBlock::EdgeList::const_iterator 
	BasicBlock::get_fallthrough_edge() const {
	for (EdgePointerVector::const_iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge) {
		if ((*edge)->type == Edge::FallThrough) return *edge;
	}
	assertM(false, "No fallthrough edge in block " << label);
	return EdgeList::const_iterator();
}

bool BasicBlock::has_fallthrough_edge() const {
	for (EdgePointerVector::const_iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge) {
		if ((*edge)->type == Edge::FallThrough) return true;
	}
	return false;
}

BasicBlock::EdgeList::iterator 
	BasicBlock::get_branch_edge() {
	for (EdgePointerVector::iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge) {
		if ((*edge)->type == Edge::Branch) return *edge;
	}
	assertM(false, "No branch edge in block " << label);
	return EdgeList::iterator();
}

BasicBlock::EdgeList::const_iterator 
	BasicBlock::get_branch_edge() const {
	for (EdgePointerVector::const_iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge) {
		if ((*edge)->type == Edge::Branch) return *edge;
	}
	assertM(false, "No branch edge in block " << label);
	return EdgeList::const_iterator();
}

bool BasicBlock::has_branch_edge() const {
	for (EdgePointerVector::const_iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge) {
		if ((*edge)->type == Edge::Branch) return true;
	}
	return false;
}

BasicBlock::EdgeList::iterator 
	BasicBlock::get_edge(BlockList::iterator b) {
	for (EdgePointerVector::iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge) {
		if ((*edge)->tail == b) return *edge;
	}
	assertM(false, "No edge from " << label << " to " << b->label);
	return EdgeList::iterator();
}

BasicBlock::EdgeList::const_iterator 
	BasicBlock::get_edge(BlockList::const_iterator b) const {
	for (EdgePointerVector::const_iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge) {
		if ((*edge)->tail == b) return *edge;
	}
	assertM(false, "No edge from " << label << " to " << b->label);
	return EdgeList::const_iterator();
}

ControlFlowGraph::EdgePointerVector::iterator 
	BasicBlock::find_in_edge(
	BlockList::const_iterator head) {
	for (EdgePointerVector::iterator edge = in_edges.begin(); 
		edge != in_edges.end(); ++edge) {
		if ((*edge)->head == head) return edge;
	}
	return in_edges.end();
}

ControlFlowGraph::EdgePointerVector::iterator 
	BasicBlock::find_out_edge(
	BlockList::const_iterator tail) {
	for (EdgePointerVector::iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge) {
		if ((*edge)->tail == tail) return edge;
	}
	return out_edges.end();
}

/////////////////////////////////////////////////////////////////////////////////////////////////

ControlFlowGraph::ControlFlowGraph(): 
	_entry(_blocks.insert(end(), BasicBlock("entry", 0))),
	_exit(_blocks.insert(end(), BasicBlock("exit", 1))),
	_nextId(2) {
}

ControlFlowGraph::~ControlFlowGraph() {
	clear();
}

void ControlFlowGraph::computeNewBlockId() {
	_nextId = 0;
	for(const_iterator block = begin(); block != end(); ++block) {
		_nextId = std::max(_nextId, block->id);
	}
	++_nextId;
}

BasicBlock::Id ControlFlowGraph::newId() {
	return _nextId++;
}

size_t ControlFlowGraph::size() const {
	return _blocks.size();
}

bool ControlFlowGraph::empty() const {
	return _blocks.empty();
}

ControlFlowGraph::iterator ControlFlowGraph::insert_block(
	const BasicBlock& block) {
	report("Inserting block '" << block.label << "' (" << block.id << ")" );
	return _blocks.insert(end(), block);
}

/*!
	\brief creates and inserts a new block into the CFG
*/
ControlFlowGraph::iterator ControlFlowGraph::insert_new_block(const std::string &name) {
	return _blocks.insert(end(), BasicBlock(name, newId()));
}
	
ControlFlowGraph::iterator ControlFlowGraph::clone_block(iterator block, std::string suffix)
{
	return insert_block(BasicBlock(block->label + "_cloned" + suffix,
		newId(), block->instructions));
}

void ControlFlowGraph::remove_block(iterator block) {
	
	while (!block->in_edges.empty()) {
		remove_edge(*block->in_edges.begin());
	}

	while (!block->out_edges.empty()) {
		remove_edge(*block->out_edges.begin());
	}
	
	block->clear();
	_blocks.erase(block);
}

ControlFlowGraph::edge_iterator 
	ControlFlowGraph::insert_edge(const Edge& edge) {
	report( "Created " << toString(edge.type) << " edge from " 
		<< edge.head->label << " -> " << edge.tail->label );
	#ifndef NDEBUG
	if (edge.type == Edge::FallThrough) {
		// verify that tail is the tail of NO OTHER FallThrough edges
		edge_pointer_iterator eit = edge.tail->in_edges.begin();
		for (; eit != edge.tail->in_edges.end(); ++eit) {
			assertM((*eit)->type != Edge::FallThrough, 
				"Duplicate fallthrough edge added for block " 
				<< edge.tail->label );
		}
	}
	#endif
	edge_iterator e = _edges.insert(edges_end(), edge);
	edge.head->out_edges.push_back(e);
	edge.tail->in_edges.push_back(e);
	edge.head->successors.push_back(edge.tail);
	edge.tail->predecessors.push_back(edge.head);
	
	return e;
}

void ControlFlowGraph::remove_edge(edge_iterator edge) {
	report( "Removed edge from " << edge->head->label 
		<< " -> " << edge->tail->label );
	edge_pointer_iterator out = std::find(edge->head->out_edges.begin(), 
		edge->head->out_edges.end(), edge);
	assert(out != edge->head->out_edges.end());
	edge->head->out_edges.erase(out);

	edge_pointer_iterator in = std::find(edge->tail->in_edges.begin(), 
		edge->tail->in_edges.end(), edge);
	assert(in != edge->tail->in_edges.end());
	edge->tail->in_edges.erase(in);

	pointer_iterator head = std::find(edge->head->successors.begin(), 
		edge->head->successors.end(), edge->tail);
	assert(head != edge->head->successors.end());
	edge->head->successors.erase(head);

	pointer_iterator tail = std::find(edge->tail->predecessors.begin(), 
		edge->tail->predecessors.end(), edge->head);
	assert(tail != edge->tail->predecessors.end());
	edge->tail->predecessors.erase(tail);

	_edges.erase(edge);
}

ControlFlowGraph::EdgePair ControlFlowGraph::split_edge(edge_iterator edge,
	const BasicBlock& newBlock) {
	iterator head = edge->head;
	iterator tail = edge->tail;
	Edge::Type type = edge->type;

	remove_edge(edge);	

	iterator block = insert_block(newBlock);
	edge_iterator firstEdge = insert_edge(Edge(head, block, type));
	edge_iterator secondEdge = insert_edge(Edge(block, tail, type));	
	
	return std::make_pair(firstEdge, secondEdge);
}

ControlFlowGraph::iterator ControlFlowGraph::split_block(iterator block, 
	unsigned int instruction, Edge::Type type, const std::string& l) {
	assert( instruction <= block->instructions.size() );
	report("Splitting block " << block->label 
		<< " at instruction " << instruction);
	
	std::string label;
	
	if(l.empty())
	{
		label = block->label + "_split";
	}
	else
	{
		label = l;
	}
	
	iterator newBlock = insert_block(BasicBlock(label, newId()));
	BasicBlock::InstructionList::iterator 
		begin = block->instructions.begin();
	std::advance(begin, instruction);
	BasicBlock::InstructionList::iterator end = block->instructions.end();
	
	newBlock->instructions.insert(newBlock->instructions.begin(), begin, end);
	block->instructions.erase(begin, end);

	EdgePointerVector out_edges = block->out_edges;

	for (EdgePointerVector::iterator edge = out_edges.begin(); 
		edge != out_edges.end(); ++edge ) {
		Edge e(newBlock, (*edge)->tail, (*edge)->type);
		edge_iterator erase = *edge;
		remove_edge( erase );
		insert_edge( e );
	}

	insert_edge(Edge(block, newBlock, type));

	return newBlock;
}

ControlFlowGraph::iterator ControlFlowGraph::get_entry_block() {
	return _entry;
}

ControlFlowGraph::iterator ControlFlowGraph::get_exit_block() {
	return _exit;
}

ControlFlowGraph::const_iterator ControlFlowGraph::get_entry_block() const {
	return _entry;
}

ControlFlowGraph::const_iterator ControlFlowGraph::get_exit_block() const {
	return _exit;
}

std::ostream& ControlFlowGraph::write(std::ostream &out) const { 
	BasicBlock::DotFormatter defaultFormatter;
	return write(out, defaultFormatter);
}

std::ostream& ControlFlowGraph::write(std::ostream &out, 
	BasicBlock::DotFormatter & blockFormatter) const {

	using namespace std;

	BlockMap blockIndices;

	out << "digraph {\n";

	// emit nodes
	out << "  // basic blocks\n\n";
	out << "  bb_0 " << blockFormatter.entryLabel(&*_entry) << ";\n";
	out << "  bb_1 " << blockFormatter.exitLabel(&*_exit) << ";\n";

	blockIndices[_entry] = 0;
	blockIndices[_exit] = 1;

	int n = 0;
	for (const_iterator block = begin(); block != end(); ++block, ++n) {
		if (block == _entry || block == _exit) continue;

		blockIndices[block] = n;
		const BasicBlock *blockPtr = &*block;
		out << "  bb_" << n << " " << blockFormatter.toString(blockPtr) << ";\n";
	}

	out << "\n\n  // edges\n\n";

	// emit edges
	for (const_edge_iterator edge = edges_begin(); 
		edge != edges_end(); ++edge) {
		const Edge *edgePtr = &*edge;

		out << "  " << "bb_" << blockIndices[edge->head] << " -> "
			<< "bb_" << blockIndices[edge->tail];
		out << " " << blockFormatter.toString(edgePtr);
	
		out << ";\n";
	}

	out << "}\n";

	return out;
}

std::string ControlFlowGraph::toString( Edge::Type t ) {
	switch( t )
	{
		case Edge::FallThrough: return "fallthrough"; break;
		case Edge::Branch: return "branch"; break;
		default: break;
	}
	return "Invalid";
}


void ControlFlowGraph::clear() {
	for (iterator block = begin(); block != end(); ++block) {
		block->clear();
	}
	_blocks.clear();
	_edges.clear();
	_entry = insert_block(BasicBlock("entry", 0));
	_exit = insert_block(BasicBlock("exit", 1));
	_nextId = 2;
}

ControlFlowGraph::BlockPointerVector ControlFlowGraph::topological_sequence() {
	typedef std::set<iterator, BlockSetCompare> BlockSet;
	typedef std::queue<iterator> Queue;
	
	report("Creating topological order traversal");
	BlockSet visited;
	BlockPointerVector sequence;
	Queue queue;
	
	queue.push(get_entry_block());

	while (sequence.size() != size()) {
		if(queue.empty()) {
			for (pointer_iterator block = sequence.begin();
				block != sequence.end(); ++block) {
				for (pointer_iterator successor = (*block)->successors.begin();
					successor != (*block)->successors.end(); ++successor) {
					
					if (visited.count(*successor) == 0) {
						queue.push(*successor);
						break;
					}		
				}
				if(!queue.empty()) {
					break;
				}
			}
			
			if(queue.empty()) break; // The remaining blocks are unreachable
		}
		
		iterator current = queue.front();
		queue.pop();
		if(!visited.insert(current).second) continue;
		sequence.push_back(current);
		report(" Adding block " << current->label);

		for (pointer_iterator block = current->successors.begin();
			block != current->successors.end(); ++block) {
			bool noDependencies = true;
		
			for (pointer_iterator pred = (*block)->predecessors.begin(); 
				pred != (*block)->predecessors.end(); ++pred) {
				if (visited.count(*pred) == 0) {
					noDependencies = false;
					break;
				}
			}
			
			if(noDependencies) {
				queue.push(*block);
			}
		}
	}

	return sequence;
}


ControlFlowGraph::BlockPointerVector
	ControlFlowGraph::reverse_topological_sequence() {
	typedef std::set<iterator, BlockSetCompare> BlockSet;
	typedef std::queue<iterator> Queue;
	
	report("Creating reverse topological order traversal");
	BlockSet visited;
	BlockPointerVector sequence;
	Queue queue;
	
	queue.push(get_exit_block());

	while (sequence.size() != size()) {
		if(queue.empty()) {
			for (pointer_iterator block = sequence.begin();
				block != sequence.end(); ++block) {
				for (pointer_iterator pred = (*block)->predecessors.begin();
					pred != (*block)->predecessors.end(); ++pred) {
					
					if (visited.count(*pred) == 0) {
						queue.push(*pred);
						break;
					}		
				}
				if(!queue.empty()) {
					break;
				}
			}
			
			if(queue.empty()) break; // The remaining blocks are unreachable
		}
		
		iterator current = queue.front();
		queue.pop();
		if(!visited.insert(current).second) continue;
		sequence.push_back(current);
		report(" Adding block " << current->label);

		for (pointer_iterator block = current->predecessors.begin();
			block != current->predecessors.end(); ++block) {
			bool noDependencies = true;
		
			for (pointer_iterator successor = (*block)->successors.begin(); 
				successor != (*block)->successors.end(); ++successor) {
				if (visited.count(*successor) == 0) {
					noDependencies = false;
					break;
				}
			}
			
			if(noDependencies) {
				queue.push(*block);
			}
		}
	}

	return sequence;
}

ControlFlowGraph::BlockPointerVector ControlFlowGraph::post_order_sequence() {
	typedef std::unordered_set<iterator> BlockSet;
	typedef std::stack<iterator> Stack;
	
	report("Creating post order traversal");
	BlockSet visited;
	BlockPointerVector sequence;
	Stack stack;
	
	if (!empty()) {
		for (pointer_iterator 
			block = get_entry_block()->successors.begin(); 
			block != get_entry_block()->successors.end(); ++block) {
			if (visited.insert(*block).second) {
				stack.push(*block);
			}
		}
	}
	
	while (!stack.empty()) {
		iterator current = stack.top();

		bool one = false;
		for (pointer_iterator block = current->successors.begin(); 
			block != current->successors.end(); ++block) {
			if (visited.insert(*block).second) {
				stack.push(*block);
				one = true;
			}
		}
		
		if(!one) {
			stack.pop();
			sequence.push_back(current);
			report(" Adding block " << current->label);
		}
	}

	report(" Adding block " << get_entry_block()->label);
	sequence.push_back(get_entry_block());

	return sequence;
}

ControlFlowGraph::BlockPointerVector ControlFlowGraph::pre_order_sequence() {
	typedef std::unordered_set<iterator> BlockSet;
	typedef std::stack<iterator> Stack;
	
	BlockSet visited;
	BlockPointerVector sequence;
	Stack stack;
	
	if (!empty()) {
		stack.push(get_entry_block());
		visited.insert(get_entry_block());
	}
	
	while (!stack.empty()) {
		iterator current = stack.top();
		stack.pop();
		
		sequence.push_back(current);
		for (pointer_iterator block = current->successors.begin(); 
			block != current->successors.end(); ++block) {
			if (visited.insert(*block).second) {
				stack.push(*block);
			}
		}
	}
	
	return sequence;
}

ControlFlowGraph::BlockPointerVector ControlFlowGraph::executable_sequence() {
	typedef std::unordered_set<iterator> BlockSet;
	BlockPointerVector sequence;
	BlockSet unscheduled;

	for(iterator i = begin(); i != end(); ++i)
	{
		unscheduled.insert(i);
	}

	report("Getting executable sequence.");

	sequence.push_back(get_entry_block());
	unscheduled.erase(get_entry_block());
	report(" added " << get_entry_block()->label);

	while (!unscheduled.empty()) {
		if (sequence.back()->has_fallthrough_edge()) {
			edge_iterator fallthroughEdge 	
				= sequence.back()->get_fallthrough_edge();
			sequence.push_back(fallthroughEdge->tail);
			unscheduled.erase(fallthroughEdge->tail);
		}
		else {
			// find a new block, favor branch targets over random blocks
			iterator next = *unscheduled.begin();
			
			for(edge_pointer_iterator edge = sequence.back()->out_edges.begin();
				edge != sequence.back()->out_edges.end(); ++edge)
			{
				if(unscheduled.count((*edge)->tail) != 0)
				{
					next = (*edge)->tail;
				}
			}
			
			// rewind through fallthrough edges to find the beginning of the 
			// next chain of fall throughs
			report("  restarting at " << next->label);
			bool rewinding = true;
			while (rewinding) {
				rewinding = false;
				for (edge_pointer_iterator edge = next->in_edges.begin(); 
					edge != next->in_edges.end(); ++edge) {
					if ((*edge)->type == Edge::FallThrough) {
						assertM(unscheduled.count((*edge)->head) != 0, 
							(*edge)->head->label 
							<< " has multiple fallthrough branches.");
						next = (*edge)->head;
						report("   rewinding to " << next->label );
						rewinding = true;
						break;
					}
				}
			}
			sequence.push_back(next);
			unscheduled.erase(next);
		}
		
		report(" added " << sequence.back()->label);
	}

	return sequence;
}

ControlFlowGraph & ControlFlowGraph::operator=(const 
	ControlFlowGraph &cfg) {
	report( "Copying cfg" );
	
	report("\nControlFlowGraph::operator=()");
	
	typedef std::unordered_map<const_iterator, iterator> BlockMap;
	BlockMap block_map;
	
	clear();
	
	_entry->id = cfg._entry->id;
	_exit->id = cfg._exit->id;
	
	for (const_iterator bl_it = cfg.begin(); bl_it != cfg.end(); ++bl_it) {
		if (cfg._entry == bl_it) {
			block_map[bl_it] = _entry;
		}
		else if(cfg._exit == bl_it) {
			block_map[bl_it] = _exit;
		}
		else {
			iterator newBlock = insert_block(
				BasicBlock(bl_it->label, bl_it->id, bl_it->instructions));
			block_map[bl_it] = newBlock;
		}
	}

	report("Edges:");
	
	// duplicate edges using the block_map
	for (const_edge_iterator e_it = cfg.edges_begin(); 
		e_it != cfg.edges_end(); ++e_it) {
		assert( block_map.count( e_it->head ) );
		assert( block_map.count( e_it->tail ) );
		
		report("\n  " << e_it->head->label << " -> " << e_it->tail->label << " [" << e_it->type << "]");
		
		insert_edge(Edge(block_map[e_it->head], 
			block_map[e_it->tail], e_it->type));
		report("\n");
	}
	
	return *this;
}

ControlFlowGraph::iterator ControlFlowGraph::begin() {
	return _blocks.begin();
}

ControlFlowGraph::iterator ControlFlowGraph::end() {
	return _blocks.end();
}

ControlFlowGraph::const_iterator ControlFlowGraph::begin() const {
	return _blocks.begin();
}

ControlFlowGraph::const_iterator ControlFlowGraph::end() const {
	return _blocks.end();
}

ControlFlowGraph::edge_iterator ControlFlowGraph::edges_begin() {
	return _edges.begin();
}

ControlFlowGraph::edge_iterator ControlFlowGraph::edges_end() {
	return _edges.end();
}

ControlFlowGraph::const_edge_iterator ControlFlowGraph::edges_begin() const {
	return _edges.begin();
}

ControlFlowGraph::const_edge_iterator ControlFlowGraph::edges_end() const {
	return _edges.end();
}

}

