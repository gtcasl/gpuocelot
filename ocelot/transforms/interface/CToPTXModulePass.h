/*! \file CToPTXModulePass.h
	\date Tuesday July 5, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the CToPTXModulePass class
*/

#ifndef C_TO_PTX_MODULE_PASS_H_INCLUDED
#define C_TO_PTX_MODULE_PASS_H_INCLUDED

#include <ocelot/transforms/interface/Pass.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/PTXOperand.h>

#include <map>
#include <algorithm>
#include <vector>

namespace ir
{
	class Module;
    class PTXKernel;
}

namespace transforms
{

	class CToPTXModulePass : public ModulePass
	{			
		public:
			
			void initialize(ir::Module& m);
			/*! \brief Run the pass on a specific module */
			void runOnModule(ir::Module& m);
			void finalize();
	};
}

#endif

