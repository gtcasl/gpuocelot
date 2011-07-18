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
#include <ocelot/ir/interface/PTXInstruction.h>

#include <map>

/* Instrumentation Target Specifiers */

#define ENTER_KERNEL        "ON_KERNEL_ENTRY"
#define EXIT_KERNEL         "ON_KERNEL_EXIT"
#define ENTER_BASIC_BLOCK   "ON_BASIC_BLOCK_ENTRY"
#define EXIT_BASIC_BLOCK    "ON_BASIC_BLOCK_EXIT"

#define ON_INSTRUCTION      "ON_INSTRUCTION"

/* Instruction classes */
#define ON_MEM_RW           "ON_MEM_RW"
#define ON_MEM_READ         "ON_MEM_READ"
#define ON_MEM_WRITE        "ON_MEM_WRITE"
#define ON_PREDICATE        "ON_PREDICATE"
#define ON_BRANCH           "ON_BRANCH"
#define ON_CALL             "ON_CALL"
#define ON_BARRIER          "ON_BARRIER"
#define ON_ATOMIC           "ON_ATOMIC_INSTRUCTION"
#define ON_ARITH_OP         "ON_ARITH_OPERATION"

/* Types of arithmetic operation */
#define TYPE_INT            "TYPE_INT"
#define TYPE_FP             "TYPE_FP"


/* basic block constructs */
#define BASIC_BLOCK_ID          "basicBlockId"
#define BASIC_BLOCK_INST_COUNT  "basicBlockInstructionCount"


namespace ir
{
	class Module;
    class PTXKernel;
}

namespace transforms
{

    class InstrumentationSpecifier {
    
        public:
            
            typedef std::multimap<std::string, ir::PTXInstruction::Opcode> InstructionClassMap;    
        
            std::string id;
            InstructionClassMap instructionClassMap;
            
            InstrumentationSpecifier();
    };

    class TranslationBlock {
    
        public:
        
            typedef std::vector<ir::PTXStatement> StatementVector;
            
            StatementVector statements; 
            std::string label;
            InstrumentationSpecifier specifier;
    };
    
    class StaticAttributes {
    
        public:
        
            unsigned int basicBlockId;
            unsigned int basicBlockInstructionCount;
            unsigned int instructionId;
            unsigned int kernelInstructionCount;
    
    };

	/*! \brief A class for an instrumentation pass that adds generated PTX from
	    CToPTXTranslator to the kernel.
	*/
	class CToPTXInstrumentationPass : public KernelPass
	{
		private:
			translator::CToPTXData translation;
			std::vector<std::string> instructionClasses;
			
		protected:
		    analysis::DataflowGraph& dfg();
		
		public:
			CToPTXInstrumentationPass(std::string resource);
			
			std::map<std::string, analysis::DataflowGraph::RegisterId> newRegisterMap;
			std::string baseAddress;
			
	    private:
	        ir::PTXStatement prepareStatementToInsert(ir::PTXStatement statement, StaticAttributes attributes);
	        void instrumentInstruction(std::vector<TranslationBlock> translationBlocks); 
	        void instrumentBasicBlock(std::vector<TranslationBlock> translationBlocks);
	        void instrumentKernel(std::vector<TranslationBlock> translationBlocks);
			
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

