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

	/*!
		\brief SSA Graph
	*/
	class SSAGraph
	{
		private:
			class Block
			{
				public:
					typedef std::unordered_map< DataflowGraph::RegisterId, 
						DataflowGraph::RegisterId > RegisterMap;
					typedef std::unordered_map< DataflowGraph::RegisterId, 
						DataflowGraph::Instruction > PhiMap;
		
				public:
					RegisterMap regs;
					PhiMap phi;
			
				public:
					bool process();
			};
		
			typedef std::unordered_map< DataflowGraph::iterator, 
				Block > BlockMap;
		
		private:
			DataflowGraph& _graph;
			BlockMap _blocks;
		
		public:
			SSAGraph( DataflowGraph& graph );
			void toSsa();
			void fromSsa();
	};

}

#endif

