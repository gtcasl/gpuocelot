/*! \file BasicBlockInstrumentationPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Sunday November 14, 2010
	\brief The header file for the BasicBlockInstrumentationPass class.
*/

#ifndef BASIC_BLOCK_INSTRUMENTATION_PASS_H_INCLUDED
#define BASIC_BLOCK_INSTRUMENTATION_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>

#include <map>

namespace ir
{
	class Module;
}

namespace analysis
{
	/*! \brief Implements the generic basic block counter instrumentation */
	class BasicBlockInstrumentationPass 
	{
        public:            		
            std::map<std::string, DataflowGraph::RegisterId> _runOnEntryBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block);
			
	};
}

#endif

