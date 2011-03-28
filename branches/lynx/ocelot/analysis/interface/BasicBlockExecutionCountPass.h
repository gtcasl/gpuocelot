/*! \file BasicBlockExecutionCountPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Wednesday October 6, 2010
	\brief The header file for the BasicBlockExecutionCountPass class.
*/

#ifndef BASIC_BLOCK_EXECUTION_COUNT_PASS_H_INCLUDED
#define BASIC_BLOCK_EXECUTION_COUNT_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/Pass.h>

namespace ir
{
	class Module;
}

namespace analysis
{
	/*! \brief Implements the basic block execution count instrumentation */
	class BasicBlockExecutionCountPass : public ModulePass
	{
	    public:
            /*! \brief default constructor */
            BasicBlockExecutionCountPass();

        protected:

            void _runOnEntryBlock( ir::PTXKernel *kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId, std::map<std::string, DataflowGraph::RegisterId> registerMap);

            void _runOnBlock( ir::PTXKernel* kernel, DataflowGraph::iterator block, std::map<std::string, DataflowGraph::RegisterId> registerMap, DataflowGraph::RegisterId registerId, unsigned int offset);
			
        public:
			/*! \brief The id of the basic block counter base pointer */			
             std::string basicBlockCounterBase() const;

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

