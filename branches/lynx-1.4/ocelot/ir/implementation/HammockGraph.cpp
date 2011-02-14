
#include <map>
#include <set>

#include <ocelot/ir/interface/HammockGraph.h>
#include <ocelot/ir/interface/Instruction.h>

#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

/////////////////////////////////////////////////////////////////////////////////////////////////

ir::HammockGraph::~HammockGraph() {

}

ir::HammockGraph::HammockGraph(ir::ControlFlowGraph * _cfg): type(Subgraph), cfg(_cfg), domTree(_cfg), pdomTree(_cfg) {
	// compute dominance relations
	
	typedef std::vector< std::vector<int> > BasicBlockTree;
	typedef std::multimap< int, int > DomTreeEdges;
	std::map< int, int > DomToIDomMap;
	
	DomTreeEdges idom;
	DomTreeEdges ipdom;
		
	// enumerate immediate dominator edges
	int n = 0;
	for (BasicBlockTree::iterator dom_it = domTree.dominated.begin();
		dom_it != domTree.dominated.end(); ++dom_it, n++ ) {
		for (std::vector< int >::iterator dom_it_it = dom_it->begin(); dom_it_it != dom_it->end(); ++dom_it_it) {
			idom.insert(std::make_pair(n, *dom_it_it));
		}
	}
	
	// enumerage immediate post-dominator edges
	int p = 0;
	for (BasicBlockTree::iterator pdom_it = pdomTree.dominated.begin();
		pdom_it != pdomTree.dominated.end(); ++pdom_it, p++ ) {
		for (std::vector< int >::iterator pdom_it_it = pdom_it->begin(); pdom_it_it != pdom_it->end(); ++pdom_it_it) {
			ipdom.insert(std::make_pair((int)pdomTree.dominated.size() - 1 - p, (int)pdomTree.dominated.size() - 1 - *pdom_it_it));
		}
	}
	
	// duplicates indicate hammocks
	for (DomTreeEdges::iterator idom_it = idom.begin(); idom_it != idom.end(); ++idom_it) {
		std::pair<DomTreeEdges::iterator, DomTreeEdges::iterator> ipdom_it = ipdom.equal_range(idom_it->second);
		for (; ipdom_it.first != ipdom_it.second; ++(ipdom_it.first)) {
			if ((ipdom_it.first)->first == idom_it->second) {
				
				//
				// found a hammock graph
				//
				// (idom_it->first, idom_it->second) is a hammock 
				
				int u = idom_it->first, v = idom_it->second;
				
				// TODO - ignore 2-node hammocks (i.e. u has exactly one out-edge [to v])
				if (domTree.blocks[u]->successors.size() > 1) {			
					hammocks.insert(std::make_pair(u,v));
				}
			}
		}
	}
	
#if REPORT_BASE
	report(hammocks.size() << " hammocks");
	for (std::map< int, int >::iterator h_it = hammocks.begin(); h_it != hammocks.end(); ++h_it) {
		report("subgraph (" << domTree.blocks[h_it->first]->label << ", " << domTree.blocks[h_it->second]->label 
			<< ") is a hammock - {" << h_it->first << ", " << h_it->second << "}");
	}
#endif
	
	// now recursively partition - this part could be challenging
	
	topological_sequence();
}

/*!
	\brief 
*/
void ir::HammockGraph::schedule_hammock(ir::ControlFlowGraph::BlockPointerVector & sequence, 
	std::set<int> & scheduled,  int entry, int exit) {
	
	typedef std::vector< std::vector<int> > BasicBlockTree;
	typedef ir::ControlFlowGraph::BlockPointerVector BlockPointerVector;

/*
Algorithm for scheduling a hammock
	
1.) reverse post-order DFS traversal of the graph
2.) if the current node has already been scheduled, skip it
3.) pop the current node from the front of the sequence and schedule it.
4.) If it is the entry to a hammock, schedule the hammock.

*/
	
	report("  schedule_hammock(" << domTree.blocks[entry]->label << ", " << domTree.blocks[exit]->label << ")");
	
	report("  scheduling " << domTree.blocks[entry]->label);
	sequence.push_back(domTree.blocks[entry]);
	scheduled.insert(entry);
	
	std::deque< int > worklist;
	//
	// visit successors and push onto work-list [checking to avoid re-scheduling]
	//
	for (BlockPointerVector::const_iterator succ_it = domTree.blocks[entry]->successors.begin(); 
		succ_it != domTree.blocks[entry]->successors.end(); ++succ_it) {
		int p = (int)domTree.blocksToIndex[*succ_it];
		if (scheduled.find(p) == scheduled.end()) {
			worklist.push_back(p);
		}
	}
	
	while (worklist.size()) {
		int node = worklist.front(); worklist.pop_front();
		
		std::map< int, int >::iterator h_it = hammocks.find(node);
		if (h_it != hammocks.end()) {
		
			schedule_hammock(sequence, scheduled, h_it->first, h_it->second);
			
			if (scheduled.find(h_it->second) == scheduled.end()) {
				report("  scheduling " << domTree.blocks[h_it->second]->label);
				sequence.push_back(domTree.blocks[h_it->second]);
				scheduled.insert(h_it->second);
			}
			
			//
			// visit successors and push onto work-list [checking to avoid re-scheduling]
			//
			BlockPointerVector & succ = domTree.blocks[h_it->second]->successors;
			for (BlockPointerVector::const_iterator succ_it = succ.begin(); succ_it != succ.end(); ++succ_it) {
				int p = (int)domTree.blocksToIndex[*succ_it];
				if (scheduled.find(p) == scheduled.end()) {
					worklist.push_back(p);
				}
			}
		}
		else {
		
			if (scheduled.find(node) == scheduled.end()) {
				report("  scheduling " << domTree.blocks[node]->label);
				sequence.push_back(domTree.blocks[node]);
				scheduled.insert(node);
			}
			
			//
			// visit successors and push onto work-list [checking to avoid re-scheduling]
			//
			BlockPointerVector & succ = domTree.blocks[node]->successors;
			for (BlockPointerVector::const_iterator succ_it = succ.begin(); succ_it != succ.end(); ++succ_it) {
				int p = (int)domTree.blocksToIndex[*succ_it];
				if (scheduled.find(p) == scheduled.end()) {
					worklist.push_back(p);
				}
			}
		}
	}
	
	
	report("  end schedule_hammock(" << domTree.blocks[entry]->label << ", " << domTree.blocks[exit]->label << ")");
}

/*!
	\brief performs a topological sort to maximize reconvergence opportunities and ensure forward progress
*/
ir::ControlFlowGraph::BlockPointerVector ir::HammockGraph::topological_sequence() {
	
	typedef ir::ControlFlowGraph::BlockPointerVector BlockPointerVector;
	
	std::set< int > scheduled;
	BlockPointerVector sequence;

	schedule_hammock(sequence, scheduled, domTree.blocksToIndex[ domTree.blocks[0] ],
		domTree.blocksToIndex[ pdomTree.blocks[0] ]);
	
	// tests:
	// are all blocks scheduled exactly once?
	// is the entry node the first block?
	// are hammocks scheduled correctly?
	
	report("schedule:");
	for (BlockPointerVector::iterator bb_it = sequence.begin(); bb_it != sequence.end(); ++bb_it) {
		report("  " << (*bb_it)->label);
	}
	
	return sequence;
}

/*
1) Do no consider any edges that leave or entry the hammock.

2) Attempt a topological sort. This is done by starting with the entry
node, adding all successors to a set, then picking the next node to
schedule from the successor set such that all of it's predecessors are
either not contained in the hammock, or are already scheduled.

3) If the sort fails, there is a cycle that ends with at least one node
in the successor set.  Discover the cycle and remove all edges that
cycle exit the cycle.  This can be accomplished by performing a
traversal starting from each node in the successor list. If the
traversal ever ends with the starting node, then there is a cycle ending
in that node.  Ignore the edge that completes the cycle. Resume the
topological sort.

Consider the following example:

A -> B
A -> C
B -> D
C -> D
C -> E
D -> F
E -> C
E -> F

This algorithm could produce the following schedules:

1) A, B, C, D, E, F
2) A, B, C, E, D, F

In these cases, 2) has the potential to be faster than 1) because the
node E that is part of the cycle C -> E -> C is given priority over D.
So if threads iterate over the cycle multiple times then some threads
could be peeled off on every iteration and branch to D.  Schedule 1)
would push these one at a time to F, while schedule 2) would accumulate
them at D and then push them to F all at once.  This leads me to another
rule of thumb: during scheduling, nodes that are part of a cycle should
be given scheduling priority over nodes that are not.

So let me modify the algorithm as follows:

1) Do no consider any edges that leave or entry the hammock.

2) Attempt a topological sort.  Stop if the sort fails.

3) Detect a cycle as follows.  For ever node in the successor set,
compute the set of predecessor nodes that are reachable from in-edges
that have not been scheduled as well as the set of successor nodes that
are reachable through out-edges and have not been scheduled.  The
intersection of these two sets is a new set of nodes that form a cycle.
  Set a cycle bit for these nodes and remove edges from this set of
nodes that end in the node being considered.  Resume the topological
sort, giving priority to nodes with the cycle bit set if there is a choice.

This forces the algorithm to always select:

1) A, B, C, E, D, F

Note that it is still not optimal in cases where there are multiple
interacting loops because the iteration count for each loop is not
known.  If we had profiling information, we could give priority to nodes
that are part of loops that exit the loop frequently.
	*/
	
/////////////////////////////////////////////////////////////////////////////////////////////////

