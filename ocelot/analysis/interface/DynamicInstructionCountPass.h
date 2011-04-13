/*! \file DynamicInstructionCountPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Friday, April 1, 2011
	\brief The header file for the DynamicInstructionCountPass class.
*/

#ifndef DYNAMIC_INSTRUCTION_COUNT_PASS_H_INCLUDED
#define DYNAMIC_INSTRUCTION_COUNT_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/BasicBlockInstrumentationPass.h>


namespace ir
{
	class Module;
}

namespace analysis
{
	/*! \brief Implements the dynamic instruction count instrumentation */
	class DynamicInstructionCountPass : public BasicBlockInstrumentationPass
	{
	    public:
            /*! \brief default constructor */
            DynamicInstructionCountPass();

        public:

            void countInstructions( ir::PTXKernel *kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId, std::map<std::string, DataflowGraph::RegisterId> registerMap, size_t instructionCount);

        public:
			/*! \brief Run the pass on a specific module */
			void runOnModule( ir::Module& m );
	};
}

#endif

