/*!
	\file HammockGraph.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief composes a CFG as a nested graph of hammocks
*/

#ifndef IR_HAMMOCKGRAPH_H_INCLUDED
#define IR_HAMMOCKGRAPH_H_INCLUDED

#include <vector>
#include <list>

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PostdominatorTree.h>
#include <ocelot/ir/interface/DominatorTree.h>

namespace ir {

	/*!
		\brief a Hammock graph can be either a basic block, or a graph with hammock graphs as nodes
	*/
	class HammockGraph {
	public:
		enum Type {
			BasicBlock,
			Subgraph,
			Type_invalid
		};
		
		typedef std::list< HammockGraph > HammockGraphList;
		typedef HammockGraphList::iterator HammockGraphPointer;
		
		class Edge {
		public:
		
			enum Type {
				ForwardEdge,
				BackEdge,
				Type_invalid
			};
		
		public:
			
			
		public:
		
			Type type;
			
			HammockGraphPointer predecessor;
			
			HammockGraphPointer successor;
		};
		typedef std::list< Edge > EdgeList;
	
	public:
		
		HammockGraph(ir::ControlFlowGraph * _cfg);
		
		~HammockGraph();
	
		ir::ControlFlowGraph::BlockPointerVector topological_sequence();
		
	private:
	
		void schedule_hammock(ir::ControlFlowGraph::BlockPointerVector & sequence, std::set<int> & scheduled,  int entry, int exit);
	
	public:
	
		/*! \brief indicates whether this is a subgraph or a basic block */
		Type type;
		
		/*! \brief pointer to original CFG that this HammockGraph overlays */
		ir::ControlFlowGraph *cfg;
		
		ir::DominatorTree domTree;
		
		ir::PostdominatorTree pdomTree;
	
		std::map< int, int > hammocks;
		
	
		/*! \brief set of nodes if this is a Subgraph */
		HammockGraphList subgraphNodes;
		
		/*! \brief set of edges between subgraphs if this is a Subgraph */
		EdgeList subgraphEdges;
		
		/*! \brief if this is a subgraph, this points to the entry node of type BasicBlock */
		HammockGraphPointer subgraphEntry;
		
		/*! \brief if this is a subgraph, this points to the exit node of type BasicBlock */
		HammockGraphPointer subgraphExit;
		
		/*!	\brief subgraph label */
		std::string label;
		
		/*! \brief subgraph comment */
		std::string comment;
		
		/*! \brief subgraph identifier */
		ir::BasicBlock::Id id;
	};

}

#endif

