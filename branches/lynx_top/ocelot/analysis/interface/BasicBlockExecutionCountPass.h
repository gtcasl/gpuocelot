/*! \file BasicBlockExecutionCountPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Wednesday October 6, 2010
	\brief The header file for the BasicBlockExecutionCountPass class.
*/

#ifndef BASIC_BLOCK_EXECUTION_COUNT_PASS_H_INCLUDED
#define BASIC_BLOCK_EXECUTION_COUNT_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/BasicBlockInstrumentationPass.h>

namespace ir
{
	class Module;
}

namespace analysis
{
	/*! \brief Implements the basic block execution count instrumentation */
	class BasicBlockExecutionCountPass : public BasicBlockInstrumentationPass
	{
	    public:
            /*! \brief default constructor */
            BasicBlockExecutionCountPass();

        protected:
            void _runOnBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId counterPtrRegId, DataflowGraph::RegisterId registerId, unsigned int offset );
			
	};
}

#endif

