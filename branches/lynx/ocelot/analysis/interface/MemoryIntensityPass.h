/*! \file MemoryIntensityPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Wednesday, April 13, 2011
	\brief The header file for the MemoryIntensityPass class.
*/

#ifndef MEMORY_INTENSITY_PASS_H_INCLUDED
#define MEMORY_INTENSITY_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/BasicBlockInstrumentationPass.h>

namespace ir
{
	class Module;
}

namespace analysis
{
	/*! \brief Implements the memory intensity instrumentation */
	class MemoryIntensityPass : public BasicBlockInstrumentationPass
	{
	    public:
            /*! \brief default constructor */
            MemoryIntensityPass();

        protected:

            void countMemoryOperations( ir::PTXKernel *kernel, DataflowGraph::iterator block, DataflowGraph::RegisterId registerId, std::map<std::string, DataflowGraph::RegisterId> registerMap, size_t memOpsCount);

        public:
			/*! \brief Run the pass on a specific module */
			void runOnModule( ir::Module& m );


        private:
            size_t _memOpsCount(DataflowGraph::iterator block);

	};
}

#endif

