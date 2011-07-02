/*! \file BasicBlockInstrumentationPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Sunday November 14, 2010
	\brief The header file for the BasicBlockInstrumentationPass class.
*/

#ifndef BASIC_BLOCK_INSTRUMENTATION_PASS_H_INCLUDED
#define BASIC_BLOCK_INSTRUMENTATION_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/transforms/interface/Pass.h>

#include <map>

namespace ir
{
	class Module;
}

namespace transforms
{
	/*! \brief Implements the generic basic block counter instrumentation */
	class BasicBlockInstrumentationPass : public KernelPass
	{
        public:
        /*! brief The number of entries per basic block */
        size_t entries;

        protected:
            std::map<std::string, analysis::DataflowGraph::RegisterId> registerMap;
          
        public:           
            BasicBlockInstrumentationPass();
            /*! \brief The id of the basic block counter base pointer */			
             std::string basicBlockCounterBase() const;
 		    analysis::DataflowGraph& dfg();

 		
        protected:
            size_t calculateThreadId(analysis::DataflowGraph::iterator block, size_t location );
			size_t calculateBasicBlockCounterOffset(analysis::DataflowGraph::iterator block, size_t basicBlockId, size_t location );

        public:
			/*! \brief Initialize the pass using a specific module */
			void initialize(ir::Module& m );
			/*! \brief Run the pass on a specific kernel */
			void runOnKernel( ir::IRKernel& k );
			/*! \brief Finalize the pass */
			void finalize( );
	};
}

#endif

