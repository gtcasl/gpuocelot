/*!
	\file SSAGraph.h
	\date Saturday June 27, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the SSAGraph class.	
*/

#ifndef SSA_GRAPH_H_INCLUDED
#define SSA_GRAPH_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis
{
	/*! \brief SSA Graph */
	class SSAGraph
	{
		private:
			typedef std::unordered_map< DataflowGraph::Register, 
				DataflowGraph::Register > RegisterMap;

			class Block
			{
				public:
					RegisterMap regs;
					RegisterMap aliveInMap;
			};
		
			typedef std::unordered_map< DataflowGraph::iterator, 
				Block > BlockMap;
		
		private:
			DataflowGraph& _graph;
			BlockMap _blocks;

			void _initialize( Block& b, DataflowGraph::iterator it, 
				DataflowGraph::RegisterId& current );		
			void _insertPhis();
			void _updateIn();
			void _updateOut();
			
		public:
			SSAGraph( DataflowGraph& graph );
			void toSsa();
			void fromSsa();
	};

}

#endif

