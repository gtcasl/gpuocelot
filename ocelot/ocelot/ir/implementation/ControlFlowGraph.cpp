/*!
	\file ControlFlowGraph.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implementation for ControlFlowGraph
	\date 28 September 2008; 21 Jan 2009
*/

#include <map>

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

using namespace ir;

ControlFlowGraph::ControlFlowGraph(): 
	_entry(new BasicBlock), _exit(new BasicBlock) {
	_entry->label = "entry";
	_exit->label = "exit";
	blocks.push_back(_entry);
	blocks.push_back(_exit);
}

ControlFlowGraph::~ControlFlowGraph() {
	BasicBlock::BlockList::iterator block_it = blocks.begin();
	
	for (; block_it != blocks.end(); ++ block_it) {
		delete *block_it;
	}
	
	BasicBlock::EdgeList::iterator edge_it = edges.begin();
	for (; edge_it != edges.end(); ++ edge_it) {
		delete *edge_it;
	}
}

size_t ControlFlowGraph::size() {
	return blocks.size();
}

BasicBlock::ConstBlockList ControlFlowGraph::get_blocks() const {
	BasicBlock::ConstBlockList c_blocks;
	BasicBlock::BlockList::const_iterator it = blocks.begin();
	for (; it != blocks.end(); ++it) {
		c_blocks.push_back(*it);
	}
	return std::move( c_blocks );
}

BasicBlock::BlockList ControlFlowGraph::get_blocks() {
	BasicBlock::BlockList c_blocks;
	BasicBlock::BlockList::const_iterator it = blocks.begin();
	for (; it != blocks.end(); ++it) {
		c_blocks.push_back(*it);
	}
	return std::move( c_blocks );
}
BasicBlock::ConstEdgeList ControlFlowGraph::get_edges() const {
	BasicBlock::ConstEdgeList c_edges;
	for (BasicBlock::EdgeList::const_iterator it = edges.begin(); 
		it != edges.end(); ++it) {
		c_edges.push_back(*it);
	}
	return std::move( c_edges );
}

void ControlFlowGraph::insert_block(BasicBlock *block) {
	blocks.push_back(block);
}

void ControlFlowGraph::remove_block(BasicBlock *block) {
	BasicBlock::EdgeList::const_iterator eit 
		= block->in_edges.begin();
	for (; eit != block->in_edges.end(); ++eit) {
		remove_edge( *eit );
	}

	eit = block->out_edges.begin();
	for (; eit != block->out_edges.end(); ++eit) {
		remove_edge( *eit );
	}
	
	delete block;
	blocks.remove(block);
}

void ControlFlowGraph::insert_edge(Edge *edge) {
	#ifndef NDEBUG
	if (edge->type == Edge::FallThrough) {
		// verify that tail is the tail of NO OTHER FallThrough edges
		BasicBlock::EdgeList::const_iterator eit 
			= edge->tail->in_edges.begin();
		for (; eit != edge->tail->in_edges.end(); ++eit) {
			// TODO: this should throw an exception
			assert((*eit)->type != Edge::FallThrough);
		}	
	}
	#endif
	report( "Created edge from " << edge->head->label 
		<< " -> " << edge->tail->label );
	edges.push_back(edge);
	edge->head->out_edges.push_back(edge);
	edge->tail->in_edges.push_back(edge);
	edge->head->successors.push_back(edge->tail);
	edge->tail->predecessors.push_back(edge->head);
}

void ControlFlowGraph::remove_edge(Edge *edge) {
	report( "Removed edge from " << edge->head->label 
		<< " -> " << edge->tail->label );
	edges.remove(edge);
	edge->head->out_edges.remove(edge);
	edge->tail->in_edges.remove(edge);
	edge->head->successors.remove(edge->tail);
	edge->tail->predecessors.remove(edge->head);
	delete edge;
}

Edge* ControlFlowGraph::split_edge(Edge *edge, 
	BasicBlock *newBlock) {
	Edge *newEdge = new Edge;
	newEdge->type = edge->type;
	newEdge->tail = edge->tail;
	newEdge->head = newBlock;
	edge->tail = newBlock;
	blocks.push_back(newBlock);
	insert_edge(newEdge);
	return newEdge;
}

BasicBlock* ControlFlowGraph::split_block(BasicBlock* block, 
	unsigned int instruction) {	assert( instruction < block->instructions.size() );
	
	BasicBlock* newBlock = new BasicBlock;
	BasicBlock::InstructionList::iterator 
		begin = block->instructions.begin();
	std::advance(begin, instruction);
	BasicBlock::InstructionList::iterator end = block->instructions.end();
	
	newBlock->instructions.insert(newBlock->instructions.begin(), begin, end);
	block->instructions.erase(begin, end);

	for (BasicBlock::EdgeList::iterator edge = block->out_edges.begin(); 
		edge != block->out_edges.end(); ) {
		Edge* e = new Edge;
		e->type = (*edge)->type;
		e->head = newBlock;
		e->tail = (*edge)->tail;
		Edge* erase = *edge;
		++edge;
		remove_edge( erase );
		insert_edge( e );
	}

	Edge* edge = new Edge;
	
	edge->type = Edge::FallThrough;
	edge->head = block;
	edge->tail = newBlock;

	newBlock->label = block->label + "_split";

	insert_edge( edge );
	insert_block(newBlock);

	return newBlock;
}

BasicBlock* ControlFlowGraph::get_entry_block() {
	return _entry;
}

BasicBlock* ControlFlowGraph::get_exit_block() {
	return _exit;
}

const BasicBlock* ControlFlowGraph::get_entry_block() const {
	return _entry;
}

const BasicBlock* ControlFlowGraph::get_exit_block() const {
	return _exit;
}

std::string ControlFlowGraph::make_label_dot_friendly( 
	const std::string& string ) {
	
	std::string result;
	for(std::string::const_iterator fi = string.begin(); 
		fi != string.end(); ++fi) {
		
		if( *fi == '{' ) {
			result.push_back('[');
		}
		else if( *fi == '}' ) {
			result.push_back(']');
		}
		else {
			result.push_back(*fi);
		}	
	}
	return result;
}

bool ControlFlowGraph::is_reachable(BasicBlock *head, 
	BasicBlock *tail) {
	assertM( false, "Not implemented." );
}

void ControlFlowGraph::clear() {
	blocks.clear();
	blocks.push_back(_entry);
	blocks.push_back(_exit);
	edges.clear();
}

void ControlFlowGraph::post_order_sequence_helper(
	BlockPointerVector &sequence, 
	BasicBlock *block, 
	BlockMap &visited) {
	
	BasicBlock::BlockList succ = block->get_successors();
	BasicBlock::BlockList::iterator succ_it = succ.begin();
	visited[block] = 1;
	for (; succ_it != succ.end(); ++succ_it) {
		if (!visited[*succ_it]) {
			post_order_sequence_helper(sequence, *succ_it, visited);
		}
	}
	sequence.push_back(block);
}

ControlFlowGraph::BlockPointerVector ControlFlowGraph::post_order_sequence() {
	using namespace std;
	BlockMap visited;
	BlockPointerVector sequence;
	BasicBlock::BlockList::iterator it = blocks.begin();
	for (; it != blocks.end(); ++it) {
		visited[*it] = 0;
	}
	post_order_sequence_helper(sequence, get_entry_block(), visited);
	
	return sequence;
}

void ControlFlowGraph::pre_order_sequence_helper(
	BlockPointerVector &sequence, 
	BasicBlock *block, 
	BlockMap &visited) {
	
	BasicBlock::BlockList succ = block->get_successors();
	BasicBlock::BlockList::iterator succ_it = succ.begin();
	
	visited[block] = 1;
	sequence.push_back(block);
	
	for (; succ_it != succ.end(); ++succ_it) {
		if (!visited[*succ_it]) {
			post_order_sequence_helper(sequence, *succ_it, visited);
		}
	}
}

ControlFlowGraph::BlockPointerVector ControlFlowGraph::pre_order_sequence() {
	using namespace std;
	BlockMap visited;
	BlockPointerVector sequence;
	BasicBlock::BlockList::iterator it = blocks.begin();
	for (; it != blocks.end(); ++it) {
		visited[*it] = 0;
	}
	pre_order_sequence_helper(sequence, get_entry_block(), visited);
	
	return sequence;
}


BasicBlock::BlockList vector_to_list(
	ControlFlowGraph::BlockPointerVector vec) {
	BasicBlock::BlockList lst;
	for ( ControlFlowGraph::BlockPointerVector::iterator it = vec.begin(); 
		it != vec.end(); ++it) {
		lst.push_back(*it);
	}
	return lst;
}

ControlFlowGraph::BlockPointerVector ControlFlowGraph::executable_sequence() {
	using namespace std;

	BasicBlock::BlockList blocks = vector_to_list(pre_order_sequence());
	BasicBlock::BlockList kill;
	BlockPointerVector seq;

	while (blocks.size()) {
		BasicBlock *target = blocks.front();
		kill.clear();

		// trace sequences of fall through edges in pre-order sequence of 
		// basic blocks
		for (BasicBlock::BlockList::iterator it = blocks.begin(); 
			target && it != blocks.end(); ++it) {
			if ((*it) == target) {
				kill.push_back(*it);
				seq.push_back(*it);

				target = 0;

				BasicBlock::EdgeList out_edges = (*it)->get_out_edges();
				for (BasicBlock::EdgeList::iterator e_it 
					= out_edges.begin(); 
					e_it != out_edges.end(); ++e_it) {
					if ((*e_it)->type == Edge::FallThrough) {
						target = (*e_it)->tail;
						it = blocks.begin();		
						/* 	reset iterator to beginning of sequence; the 
							increment operator pushes it past the first element.
							This is acceptable since the front element is 
							guaranteed to have been visited once, and cycles 
							consisting entirely of fall through edges do not 
							exist.
						*/
						break;
					}
				}
			}
		}

		// remove selected blocks
		for (BasicBlock::BlockList::iterator it = kill.begin(); 
			it != kill.end(); ++it) {
			blocks.remove(*it);
		}	
	}

	return seq;
}

ControlFlowGraph & ControlFlowGraph::operator=(const 
	ControlFlowGraph &cfg) {
	report( "Copying cfg" );
	// copy basic blocks
	using namespace std;
	map<BasicBlock *, BasicBlock *> block_map; // (old, new)

	BasicBlock::BlockList::iterator block_it = blocks.begin();
	for (; block_it != blocks.end(); ++ block_it) {
		delete *block_it;
	}
	
	BasicBlock::EdgeList::iterator edge_it = edges.begin();
	for (; edge_it != edges.end(); ++ edge_it) {
		delete *edge_it;
	}

	_entry = new BasicBlock;
	_exit = new BasicBlock;
	_entry->label = "entry";
	_exit->label = "exit";
	
	clear();

	for (BasicBlock::BlockList::const_iterator bl_it = cfg.blocks.begin(); 
		bl_it != cfg.blocks.end(); ++bl_it) {
		if (cfg._entry == (*bl_it) ) {
			block_map[*bl_it] = _entry;
		}
		else if( cfg._exit == (*bl_it)) {
			block_map[*bl_it] = _exit;
		}
		else {
			BasicBlock *newBlock = new BasicBlock;
			newBlock->label = (*bl_it)->label;
			newBlock->instructions = (*bl_it)->instructions;
			block_map[*bl_it] = newBlock;
			blocks.push_back(newBlock);
		}
	}

	// duplicate edges using the block_map
	for (BasicBlock::EdgeList::const_iterator e_it = cfg.edges.begin(); 
		e_it != cfg.edges.end(); ++e_it) {
		assert( block_map.count( (*e_it)->head ) );
		assert( block_map.count( (*e_it)->tail ) );
		Edge *edge = new Edge;
		edge->type = (*e_it)->type;
		edge->head = block_map[(*e_it)->head];
		edge->tail = block_map[(*e_it)->tail];
		insert_edge(edge);
	}
	
	return *this;
}


