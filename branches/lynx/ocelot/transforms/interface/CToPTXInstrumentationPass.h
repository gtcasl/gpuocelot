/*! \file CToPTXInstrumentationPass.h
	\date Tuesday July 5, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the CToPTXInstrumentationPass class
*/

#ifndef C_TO_PTX_INSTRUMENTATION_PASS_H_INCLUDED
#define C_TO_PTX_INSTRUMENTATION_PASS_H_INCLUDED

#include <ocelot/transforms/interface/Pass.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/translator/interface/CToPTXTranslator.h>

/* special instrumentation labels */
#define ENTER_KERNEL        "ENTER_KERNEL"
#define EXIT_KERNEL         "EXIT_KERNEL"
#define ENTER_BASIC_BLOCK   "ENTER_BASIC_BLOCK"
#define EXIT_BASIC_BLOCK    "EXIT_BASIC_BLOCK"

/* basic block constructs */
#define BASIC_BLOCK_ID "basicBlockId"
#define BASIC_BLOCK_SIZE "instructionsPerBasicBlock"


namespace ir
{
	class Module;
    class PTXKernel;
}

namespace transforms
{

	/*! \brief A class for an instrumentation pass that adds generated PTX from
	    CToPTXTranslator to the kernel.
	*/
	class CToPTXInstrumentationPass : public KernelPass
	{
		private:
			translator::CToPTXData translation;
			
		protected:
		    analysis::DataflowGraph& dfg();
		
		public:
			CToPTXInstrumentationPass(std::string resource);
			
			std::map<std::string, analysis::DataflowGraph::RegisterId> newRegisterMap;
			std::string baseAddress;
			
	    private:
	        ir::PTXStatement prepareStatementToInsert(ir::PTXStatement statement, unsigned int basicBlockSize, unsigned int basicBlockId);
			
		public:
			/*! \brief Initialize the pass using a specific kernel */
			void initialize( ir::Module& m );
			/*! \brief Run the pass on a specific kernel */
			void runOnKernel(ir::IRKernel& k);
			/*! \brief Finalize the pass */
			void finalize( );		     
            
	};
}

#endif

