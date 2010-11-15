/*! \file BasicBlockSMIDPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Sunday November 14, 2010
	\brief The header file for the BasicBlockSMIDPass class.
*/

#ifndef BASIC_BLOCK_SMID_PASS_H_INCLUDED
#define BASIC_BLOCK_SMID_PASS_H_INCLUDED

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
	class BasicBlockSMIDPass : public BasicBlockInstrumentationPass
	{
	    public:
            /*! \brief default constructor */
            BasicBlockSMIDPass();

        protected:
            void _runOnBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId counterPtrRegId, DataflowGraph::RegisterId registerId, unsigned int offset );
			
	};
}

#endif

