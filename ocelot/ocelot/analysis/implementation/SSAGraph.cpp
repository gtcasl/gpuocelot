/*!
	\file SSAGraph.cpp
	\date Saturday June 27, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the SSAGraph class.	
*/

#ifndef SSA_GRAPH_CPP_INCLUDED
#define SSA_GRAPH_CPP_INCLUDED

#include <ocelot/analysis/interface/SSAGraph.h>

namespace analysis
{
	bool SSAGraph::Block::process()
	{
		return false;
	}
	
	SSAGraph::SSAGraph( DataflowGraph& graph ) : _graph( graph )
	{
	
	}
	
	void SSAGraph::toSsa()
	{
		assert( !_graph._ssa );
		_graph._ssa = true;
	}
	
	void SSAGraph::fromSsa()
	{
		assert( _graph._ssa );
		_graph._ssa = false;
	
	}
}

#endif

