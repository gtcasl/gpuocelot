/*! \file MemoryIntensityPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Wednesday, April 13, 2011
	\brief The header file for the MemoryIntensityPass class.
*/

#ifndef MEMORY_INTENSITY_PASS_H_INCLUDED
#define MEMORY_INTENSITY_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/transforms/interface/InstructionCountPass.h>

namespace ir
{
	class Module;
}

namespace transforms
{
	/*! \brief Implements the memory intensity instrumentation */
	class MemoryIntensityPass : public InstructionCountPass
	{
	    public:
            /*! \brief default constructor */
            MemoryIntensityPass();

        protected:

            void countMemoryOperations( analysis::DataflowGraph::iterator block, analysis::DataflowGraph::RegisterId registerId, std::map<std::string, analysis::DataflowGraph::RegisterId> registerMap, size_t memOpsCount);

        public:
			/*! \brief Run the pass on a specific kernel */
			void runOnKernel( ir::IRKernel& k );


        private:
            size_t _memOpsCount(analysis::DataflowGraph::iterator block);

	};
}

#endif

