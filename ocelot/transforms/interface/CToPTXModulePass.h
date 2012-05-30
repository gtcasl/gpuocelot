/*! \file CToPTXModulePass.h
	\date Tuesday July 5, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the CToPTXModulePass class
*/

#ifndef C_TO_PTX_MODULE_PASS_H_INCLUDED
#define C_TO_PTX_MODULE_PASS_H_INCLUDED

#include <ocelot/transforms/interface/Pass.h>
#include <ocelot/translator/interface/CToPTXTranslator.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/PTXOperand.h>

#include <map>
#include <algorithm>
#include <vector>


/* function names */

#define UNIQUE_ELEMENT_COUNT            "uniqueElementCount"

/* label names */

#define LEAST_ACTIVE_THREAD             "$leastActiveThread"
#define BEGIN_REDUCTION                 "$beginReduction"
#define BEGIN_INST_COUNT_LOOP           "$beginInstCountLoop"
#define BEGIN_FIRST_LOOP                "$beginFirstLoop"
#define BEGIN_SECOND_LOOP               "$beginSecondLoop"
#define BEGIN_HALF_WARP_LOOP            "$beginHalfWarpLoop"
#define HALF_WARP_LOOP    	            "$halfWarpLoop"
#define FIRST_LOOP                      "$firstLoop"
#define SECOND_LOOP                     "$secondLoop"
#define HALF_WARP_LOOP_INC              "$halfWarpLoopInc"
#define FIRST_LOOP_INC                  "$firstLoopInc"
#define SECOND_LOOP_INC                 "$secondLoopInc"
#define INST_COUNT_LOOP_INC             "$instCountLoopInc"
#define UPDATE_COUNTER                  "$updateCounter"
#define STORE_RESULTS                   "$storeResults"

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
	    
	        typedef std::map<std::string, size_t> FunctionParameterMap;
			
			FunctionParameterMap parameterMap;
            std::string functionName;
	
		public:
        			
            CToPTXModulePass(std::string functionName);

			void initialize(ir::Module& m);
			/*! \brief Run the pass on a specific module */
			void runOnModule(ir::Module& m);
			void finalize();
			
        private:
			ir::PTXKernel * uniqueElementCount();
	};
}

#endif

