/*! \file InstructionCountPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Friday, July 1, 2011
	\brief The header file for the InstructionCountPass class.
*/

#ifndef INSTRUCTION_COUNT_H_INCLUDED
#define INSTRUCTION_COUNT_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/transforms/interface/BasicBlockInstrumentationPass.h>

namespace ir
{
	class Module;
}

namespace transforms
{
	/*! \brief Implements instruction count pass */
	class InstructionCountPass : public BasicBlockInstrumentationPass
	{
	    public:
            /*! \brief default constructor */
            InstructionCountPass();

        protected:

            void countInstructions(analysis::DataflowGraph::iterator block, analysis::DataflowGraph::RegisterId registerId, std::map<std::string, analysis::DataflowGraph::RegisterId> registerMap, size_t instructionCount);

        public:
			/*! \brief Run the pass on a specific kernel */
			void runOnKernel( ir::IRKernel& k );

	};
}

#endif

