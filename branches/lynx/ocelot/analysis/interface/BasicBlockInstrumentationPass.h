/*! \file BasicBlockInstrumentationPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Sunday November 14, 2010
	\brief The header file for the BasicBlockInstrumentationPass class.
*/

#ifndef BASIC_BLOCK_INSTRUMENTATION_PASS_H_INCLUDED
#define BASIC_BLOCK_INSTRUMENTATION_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/Pass.h>

#include <map>

namespace ir
{
	class Module;
}

namespace analysis
{
	/*! \brief Implements the generic basic block counter instrumentation */
	class BasicBlockInstrumentationPass : public ModulePass
	{
        public:
        /*! brief The number of entries per basic block */
        size_t entries;

        protected:
            std::map<std::string, DataflowGraph::RegisterId> registerMap;

        public:           
            /*! \brief The id of the basic block counter base pointer */			
             std::string basicBlockCounterBase() const;
 		
        protected:
            size_t calculateThreadId( ir::PTXKernel* kernel, DataflowGraph::iterator block, size_t location );
			size_t calculateBasicBlockCounterOffset( ir::PTXKernel *kernel, DataflowGraph::iterator block, size_t basicBlockId, size_t location );

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

