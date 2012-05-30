/*! \file DynamicInstructionCountPass.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date Friday, April 1, 2011
	\brief The header file for the DynamicInstructionCountPass class.
*/

#ifndef DYNAMIC_INSTRUCTION_COUNT_PASS_H_INCLUDED
#define DYNAMIC_INSTRUCTION_COUNT_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/transforms/interface/InstructionCountPass.h>


namespace ir
{
	class Module;
}

namespace transforms
{
	/*! \brief Implements the dynamic instruction count instrumentation */
	class DynamicInstructionCountPass : public InstructionCountPass
	{
	    public:
            /*! \brief default constructor */
            DynamicInstructionCountPass();

        public:
			/*! \brief Run the pass on a specific kernel */
			void runOnKernel( ir::IRKernel& k );
	};
}

#endif

