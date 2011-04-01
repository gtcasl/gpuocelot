/*! \file DynamicInstructionCountPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Friday, April 1, 2011
	\brief The header file for the DynamicInstructionCountPass class.
*/

#ifndef DYNAMIC_INSTRUCTION_COUNT_PASS_H_INCLUDED
#define DYNAMIC_INSTRUCTION_EXECUTION_COUNT_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/Pass.h>

namespace ir
{
	class Module;
}

namespace analysis
{
	/*! \brief Implements the dynamic instruction count instrumentation */
	class DynamicInstructionCountPass : public ModulePass
	{
	    public:
            /*! \brief default constructor */
            DynamicInstructionCountPass();

        protected:

            void countInstructions( ir::PTXKernel *kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId, std::map<std::string, DataflowGraph::RegisterId> registerMap, size_t instructionCount);

        public:
			/*! \brief Initialize the pass using a specific module */
			void initialize( const ir::Module& m );
			/*! \brief Run the pass on a specific module */
			void runOnModule( ir::Module& m );
			/*! \brief Finalize the pass */
			void finalize( );

	};
}

#endif

