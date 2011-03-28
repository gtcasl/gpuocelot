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
            std::map<std::string, DataflowGraph::RegisterId> registerMap;

        public:           
            /*! \brief The id of the basic block counter base pointer */			
             std::string basicBlockCounterBase() const;
 		
            size_t calculateThreadId( ir::PTXKernel* kernel, DataflowGraph::iterator block, size_t location );
			size_t calculateBasicBlockCounterOffset( ir::PTXKernel *kernel, DataflowGraph::iterator block, size_t basicBlockId, size_t location );
	};
}

#endif

