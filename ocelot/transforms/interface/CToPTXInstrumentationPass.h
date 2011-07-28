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
#include <ocelot/ir/interface/PTXOperand.h>

#include <map>
#include <algorithm>
#include <vector>

/* Instrumentation Target Specifiers */

#define ENTER_KERNEL            "ON_KERNEL_ENTRY"
#define EXIT_KERNEL             "ON_KERNEL_EXIT"
#define ENTER_BASIC_BLOCK       "ON_BASIC_BLOCK_ENTRY"
#define EXIT_BASIC_BLOCK        "ON_BASIC_BLOCK_EXIT"
#define ON_INSTRUCTION          "ON_INSTRUCTION"

/* Instruction classes */
#define ON_MEM_READ         "MEM_READ"
#define ON_MEM_WRITE        "MEM_WRITE"
#define ON_PREDICATED       "PREDICATED"
#define ON_BRANCH           "BRANCH"
#define ON_CALL             "CALL"
#define ON_BARRIER          "BARRIER"
#define ON_ATOMIC           "ATOMIC"
#define ON_ARITH_OP         "ARITHMETIC"

/* Types of address space */
#define GLOBAL              "GLOBAL"
#define LOCAL               "LOCAL"
#define SHARED              "SHARED"
#define CONST               "CONST"
#define PARAM               "PARAM"
#define TEXTURE             "TEXTURE"

/* Types of arithmetic operation */
#define TYPE_INT            "INTEGER"
#define TYPE_FP             "FLOATING_POINT"


/* basic block constructs */
#define BASIC_BLOCK_ID                  "basicBlockId"
#define BASIC_BLOCK_INST_COUNT          "basicBlockInstructionCount"
#define BASIC_BLOCK_EXEC_INST_COUNT     "basicBlockExecutedInstructionCount"
#define INSTRUCTION_ID          "instructionId"

namespace ir
{
	class Module;
    class PTXKernel;
}

namespace transforms
{

    class InstrumentationSpecifier {
    
        public:
            
            typedef std::vector<std::string> StringVector;
  
            std::string id;
            bool checkForPredication;
            bool isPredicated;
            StringVector instructionClassVector;
            StringVector addressSpaceVector;
            StringVector dataTypeVector;
            StringVector predicateVector;
            
            InstrumentationSpecifier();
    };

    class TranslationBlock {
    
        public:
        
            typedef std::vector<ir::PTXStatement> StatementVector;
            
            enum InstrumentationTarget {
                KERNEL,
                BASIC_BLOCK,
                INSTRUCTION
            };
    
            InstrumentationTarget target;
            
            StatementVector statements; 
            std::string label;
            InstrumentationSpecifier specifier;
    };
    
    class StaticAttributes {
    
        public:
        
            unsigned int basicBlockId;
            unsigned int basicBlockInstructionCount;
            unsigned int basicBlockExecutedInstructionCount;
            unsigned int instructionId;
            unsigned int kernelInstructionCount;
            ir::PTXOperand predicateGuard;
    };

	/*! \brief A class for an instrumentation pass that adds generated PTX from
	    CToPTXTranslator to the kernel.
	*/
	class CToPTXInstrumentationPass : public KernelPass
	{
		private:
			
			typedef std::map<ir::PTXInstruction::Opcode, std::string> OpcodeMap; 
            typedef std::map<std::string, ir::PTXInstruction::AddressSpace> AddressSpaceMap;   
            typedef std::map<ir::PTXOperand::DataType, std::string> DataTypeMap; 
			
			OpcodeMap opcodeMap;
            AddressSpaceMap addressSpaceMap;
            DataTypeMap dataTypeMap;
			translator::CToPTXData translation;
			std::vector<std::string> instructionClasses;
			std::vector<std::string> addressSpaceSpecifiers;
			std::vector<std::string> types;
			
		protected:
		    analysis::DataflowGraph& dfg();
		
		public:
			CToPTXInstrumentationPass(std::string resource);
			
			std::map<std::string, analysis::DataflowGraph::RegisterId> newRegisterMap;
			std::string baseAddress;
			
	    private:
	        ir::PTXStatement prepareStatementToInsert(ir::PTXStatement statement, StaticAttributes attributes);
	        void instrumentInstruction(TranslationBlock translationBlock); 
	        void instrumentBasicBlock(TranslationBlock translationBlock);
	        void instrumentKernel(TranslationBlock translationBlock);
	        bool instrumentationConditionsMet(ir::PTXInstruction instruction, TranslationBlock translationBlock);
			void insertBefore(TranslationBlock translationBlock, StaticAttributes attributes, analysis::DataflowGraph::iterator basicBlock, unsigned int loc);
			void insertAfter(TranslationBlock translationBlock, StaticAttributes attributes, analysis::DataflowGraph::iterator basicBlock, unsigned int loc);
			
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

