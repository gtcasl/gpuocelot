/*!
	\file ControlFlowGraph.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\brief implementation for ControlFlowGraph
	
	\date 28 September 2008; 21 Jan 2009
*/

#include <map>
#include <assert.h>

#include <ocelot/ir/interface/ControlFlowGraph.h>

using namespace ir;

/*!
	construct an empty control flow graph
*/
ControlFlowGraph::ControlFlowGraph(): entry(new BasicBlock), exit(new BasicBlock) {
	entry->label = "entry";
	exit->label = "exit";
	blocks.push_back(entry);
	blocks.push_back(exit);
}

/*!
	destruct a control flow graph
*/
ControlFlowGraph::~ControlFlowGraph() {
	std::list< ir::BasicBlock * >::iterator block_it = blocks.begin();
	
	for (; block_it != blocks.end(); ++ block_it) {
		delete *block_it;
	}
	
	std::list< ir::Edge * >::iterator edge_it = edges.begin();
	for (; edge_it != edges.end(); ++ edge_it) {
		delete *edge_it;
	}
}

/*!
	returns the number of basic blocks in a CFG excluding the entry and exit dummy blocks
*/
size_t ControlFlowGraph::size() {
	return blocks.size();
}

/*!
	gets a list of all basic blocks in CFG including those with no edges
*/
std::list< const ir::BasicBlock *> ControlFlowGraph::get_blocks() const {
	std::list< const ir::BasicBlock *> c_blocks;
	std::list< ir::BasicBlock *>::const_iterator it = blocks.begin();
	for (; it != blocks.end(); ++it) {
		c_blocks.push_back(*it);
	}
	return c_blocks;
}

/*!
	gets a list of all edges in a CFG
*/
std::list< const ir::Edge *> ControlFlowGraph::get_edges() const {
	std::list< const ir::Edge *> c_edges;
	for (std::list< ir::Edge *>::const_iterator it = edges.begin(); it != edges.end(); ++it) {
		c_edges.push_back(*it);
	}
	return c_edges;
}

/*!
	inserts a basic block into a CFG. This block has no edges to it of course
*/
void ControlFlowGraph::insert_block(BasicBlock *block) {
	blocks.push_back(block);
	if (blocks.size() == 1) {
		// by definition, first block in CFG is successor to entry node
		Edge *edge = new Edge;
		edge->type = Edge::FallThrough;
		edge->head = entry;
		edge->tail = block;
		insert_edge(edge);
	}
}

/*!
	removes a block from a CFG if it is present
*/
void ControlFlowGraph::remove_block(ir::BasicBlock *block) {
	blocks.remove(block);
}

/*!
	adds an edge to a CFG
*/
void ControlFlowGraph::insert_edge(ir::Edge *edge) {
	if (edge->type == Edge::FallThrough) {
		// verify that tail is the tail of NO OTHER FallThrough edges
		std::list<Edge *>::const_iterator eit = edge->tail->in_edges.begin();
		for (; eit != edge->tail->in_edges.end(); ++eit) {
			// TODO: this should throw an exception
			assert((*eit)->type != Edge::FallThrough);
		}	
	}
	edges.push_back(edge);
	edge->head->out_edges.push_back(edge);
	edge->tail->in_edges.push_back(edge);
	edge->head->successors.push_back(edge->tail);
	edge->tail->predecessors.push_back(edge->head);
}

/*!
	removes an edge from a CFG if present
*/
void ControlFlowGraph::remove_edge(ir::Edge *edge) {
	edges.remove(edge);
	edge->head->out_edges.remove(edge);
	edge->tail->in_edges.remove(edge);
	edge->head->successors.remove(edge->tail);
	edge->tail->predecessors.remove(edge->head);
}

/*!
	splits an edge into two and inserts a basic block between the two edges. Returns the
	newly created edge
*/
ir::Edge * ControlFlowGraph::split_edge(ir::Edge *edge, ir::BasicBlock *newBlock) {
	ir::Edge *newEdge = new ir::Edge;
	newEdge->type = edge->type;
	newEdge->tail = edge->tail;
	newEdge->head = newBlock;
	edge->tail = newBlock;
	blocks.push_back(newBlock);
	insert_edge(newEdge);
	return newEdge;
}

/*!
	gets the entry dummy block of the CFG
*/
ir::BasicBlock *ControlFlowGraph::get_entry_block() {
	return entry;
}

/*!
	gets the exit dummy block of the CFG
*/
ir::BasicBlock *ControlFlowGraph::get_exit_block() {
	return exit;
}

/*!
	gets the entry dummy block of the CFG
*/
const ir::BasicBlock *ControlFlowGraph::get_entry_block() const {
	return entry;
}

/*!
	gets the exit dummy block of the CFG
*/
const ir::BasicBlock *ControlFlowGraph::get_exit_block() const {
	return exit;
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

/*!
	returns true if tail is reachable from head
*/
bool ControlFlowGraph::is_reachable(ir::BasicBlock *head, 
	ir::BasicBlock *tail) {
	
	return false;
}

/*!
	removes all edges and basic blocks
*/
void ControlFlowGraph::clear() {
	blocks.clear();
	blocks.push_back(entry);
	blocks.push_back(exit);
	edges.clear();
}

void ControlFlowGraph::post_order_sequence_helper(
	std::vector<BasicBlock*> &sequence, 
	BasicBlock *block, 
	std::map< BasicBlock *, int> &visited) {
	
	std::list< BasicBlock * > succ = block->get_successors();
	std::list< BasicBlock * >::iterator succ_it = succ.begin();
	visited[block] = 1;
	for (; succ_it != succ.end(); ++succ_it) {
		if (!visited[*succ_it]) {
			post_order_sequence_helper(sequence, *succ_it, visited);
		}
	}
	sequence.push_back(block);
}

std::vector< BasicBlock * > ControlFlowGraph::post_order_sequence() {
	using namespace std;
	map< BasicBlock *, int> visited;
	vector< BasicBlock * > sequence;
	list< ir::BasicBlock *>::iterator it = blocks.begin();
	for (; it != blocks.end(); ++it) {
		visited[*it] = 0;
	}
	post_order_sequence_helper(sequence, get_entry_block(), visited);
	
	return sequence;
}

void ControlFlowGraph::pre_order_sequence_helper(
	std::vector<BasicBlock*> &sequence, 
	BasicBlock *block, 
	std::map< BasicBlock *, int> &visited) {
	
	std::list< BasicBlock * > succ = block->get_successors();
	std::list< BasicBlock * >::iterator succ_it = succ.begin();
	
	visited[block] = 1;
	sequence.push_back(block);
	
	for (; succ_it != succ.end(); ++succ_it) {
		if (!visited[*succ_it]) {
			post_order_sequence_helper(sequence, *succ_it, visited);
		}
	}
}

std::vector< BasicBlock * > ControlFlowGraph::pre_order_sequence() {
	using namespace std;
	map< BasicBlock *, int> visited;
	vector< BasicBlock * > sequence;
	list< ir::BasicBlock *>::iterator it = blocks.begin();
	for (; it != blocks.end(); ++it) {
		visited[*it] = 0;
	}
	pre_order_sequence_helper(sequence, get_entry_block(), visited);
	
	return sequence;
}


std::list< BasicBlock * > vector_to_list(std::vector< BasicBlock * > vec) {
	std::list< BasicBlock * > lst;
	for (	std::vector<BasicBlock *>::iterator it = vec.begin(); it != vec.end(); ++it) {
		lst.push_back(*it);
	}
	return lst;
}

/*!
		Returns an ordered sequence of basic blocks such that the entry node is first
		and all fall-through edges produce adjacencies
*/
std::vector< BasicBlock * > ControlFlowGraph::executable_sequence() {
	using namespace std;

	list< BasicBlock *> blocks = vector_to_list(pre_order_sequence());
	list< BasicBlock *> kill;
	vector< BasicBlock * > seq;

	while (blocks.size()) {
		BasicBlock *target = blocks.front();
		kill.clear();

		// trace sequences of fall through edges in pre-order sequence of basic blocks
		for (list< BasicBlock* >::iterator it = blocks.begin(); target && it != blocks.end(); ++it) {
			if ((*it) == target) {
				kill.push_back(*it);
				seq.push_back(*it);

				target = 0;

				list< Edge *> out_edges = (*it)->get_out_edges();
				for (list<Edge*>::iterator e_it = out_edges.begin(); e_it != out_edges.end(); ++e_it) {
					if ((*e_it)->type == Edge::FallThrough) {
						target = (*e_it)->tail;
						it = blocks.begin();		// reset iterator to beginning of sequence; the increment operator
																		// pushes it past the first element. This is acceptable since
																		// the front element is guaranteed to have been visited once, and
																		// cycles consisting entirely of fall through edges do not exist.
						break;
					}
				}
			}
		}

		// remove selected blocks
		for (list<BasicBlock*>::iterator it = kill.begin(); it != kill.end(); ++it) {
			blocks.remove(*it);
		}	
	}

	return seq;
}

ControlFlowGraph & ir::ControlFlowGraph::operator=(const ControlFlowGraph &cfg) {
	// copy basic blocks
	using namespace std;
	map<BasicBlock *, BasicBlock *> block_map; // (old, new)

	/* 
	std::list< ir::BasicBlock * > blocks;
	std::list< ir::Edge * > edges;
	*/
	for (list<BasicBlock*>::const_iterator bl_it = cfg.blocks.begin(); bl_it != cfg.blocks.end(); ++bl_it) {
		BasicBlock *newBlock = new BasicBlock;
		newBlock->label = (*bl_it)->label;
		newBlock->instructions = (*bl_it)->instructions;
		block_map[*bl_it] = newBlock;
		insert_block(newBlock);

		if (cfg.entry == (*bl_it)) {
			entry = newBlock;
		}
		else if (cfg.exit == (*bl_it)) {
			exit = newBlock;
		}
	}

	// duplicate edges using the block_map
	for (list<Edge *>::const_iterator e_it = cfg.edges.begin(); e_it != cfg.edges.end(); ++e_it) {
		Edge *edge = new Edge;
		edge->type = (*e_it)->type;
		edge->head = block_map[(*e_it)->head];
		edge->tail = block_map[(*e_it)->tail];
		insert_edge(edge);
	}

	block_map.clear();
	
	return *this;
}



