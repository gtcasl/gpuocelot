/*! \file CToPTXTranslator.h
	\date Wednesday June 8, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the CToPTXTranslator class
*/

#ifndef C_TO_PTX_TRANSLATOR_H_INCLUDED
#define C_TO_PTX_TRANSLATOR_H_INCLUDED

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>

#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

#include "cod.h"
#include "dill.h"
#include "dill_internal.h"

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
#define INSTRUCTION_ID                  "instructionId"
#define INSTRUCTION_COUNT               "instructionCount"

#define COMPUTE_MASKED_ADDRESS          "computeMaskedAddress"

#define LEAST_ACTIVE_THREAD     "$leastActiveThread"
#define BEGIN_REDUCTION         "$beginReduction"
#define BEGIN_INST_COUNT_LOOP   "$beginInstCountLoop"
#define BEGIN_FIRST_LOOP        "$beginFirstLoop"
#define BEGIN_SECOND_LOOP       "$beginSecondLoop"
#define FIRST_LOOP              "$firstLoop"
#define SECOND_LOOP             "$secondLoop"
#define FIRST_LOOP_INC          "$firstLoopInc"
#define SECOND_LOOP_INC         "$secondLoopInc"
#define INST_COUNT_LOOP_INC     "$instCountLoopInc"
#define UPDATE_COUNTER          "$updateCounter"
#define STORE_RESULTS           "$storeResults"
#define EXIT                    "$exit"

namespace translator {

    class PredicateInfo {
    
        public:
        
            std::string id;
            bool set;
            bool inv;
            std::string branchLabel;
            
            enum Cond {
                TAKEN,
                NOT_TAKEN
            };
    
            Cond condition;
            
            PredicateInfo();
    
    };

    /*! \brief A class containing C-to-PTX translation data.
	*/
	class CToPTXData
	{
	    public:
	    
	        typedef std::vector<std::string> RegisterVector;
	        typedef std::vector<std::string> StringVector;
	        
	        ir::PTXKernel::PTXStatementVector statements;
		    ir::PTXKernel::PTXStatementVector globals;
		    RegisterVector registers;
		    StringVector newBlockLabels;
		    StringVector splitBlockLabels;
	
	};


	/*! \brief A class translating C-on-Demand (COD) IR to PTX.
	*/
	class CToPTXTranslator
	{
			
		public:
		    
		    enum SpecialSymbols {
			    clockCounterSymbol,
			    globalThreadIdSymbol,
			    threadIdxXSymbol,
			    threadIdxYSymbol,
			    threadIdxZSymbol,
			    blockThreadIdSymbol,
			    blockDimXSymbol,
			    blockDimYSymbol,
			    blockDimZSymbol,
			    blockDimSymbol,
			    blockIdxXSymbol,
			    blockIdxYSymbol,
			    blockIdxZSymbol,
			    blockIdSymbol,
			    gridDimXSymbol,
			    gridDimYSymbol,
			    gridDimZSymbol,
			    gridDimSymbol,
			    gridIdSymbol,
			    smIdSymbol,
			    syncThreadsSymbol,
			    basicBlockIdSymbol,
                basicBlockInstCountSymbol,
                basicBlockExecInstCountSymbol,
                instructionIdSymbol,
                instructionCountSymbol,
                warpCountSymbol,
                warpIdSymbol,
                predicateEvalWarpUniformSymbol,
                predicateEvalWarpDivergentSymbol,
                memoryTransactionCountSymbol,
                computeUniqueMemTransactionsSymbol
		    };
		    
		    SpecialSymbols symbols;
		
		    typedef std::map<std::string, std::string> RegisterMap;
		    typedef std::map<std::string, size_t> FunctionCallMap;
		    typedef std::vector<PredicateInfo> PredicateList;
		    typedef std::vector<std::string> RegisterVector;
		    typedef std::vector<std::string> StringVector;
		    
		    ir::PTXKernel *kernel;
		    ir::PTXKernel::PTXStatementVector statements;
		    ir::PTXKernel::PTXStatementVector globals;
		    RegisterMap registerMap;	
		    RegisterMap specialRegisterMap;
		    FunctionCallMap functionCalls;
		    PredicateList predicateList;
		    RegisterVector registers;
		    StringVector newBlockLabels;
		    StringVector splitBlockLabels;
		    StringVector specifierList;
		    StringVector specifiers;
		    StringVector targetList;
		    StringVector targets;
		    
		    unsigned int maxRegister;	
		    unsigned int maxPredicate;
		    
		    std::string baseReg;	
		    std::string sharedMemReg;  
		    
		    private:
		        void generateBlockId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateSMId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateWarpId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateWarpCount(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateClockCounter(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateThreadIndexX(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateBlockDim(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateGridDim(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateGlobalThreadId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateBlockThreadId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generateMemoryTransactionCount(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, std::string callName);
		        void generateComputeUniqueMemoryTransactions(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn);
		        void generatePredicateEvalWarpUniform(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, bool isUniform);
		        void generateSyncThreads(ir::PTXInstruction inst, ir::PTXStatement stmt);
		        void generateStaticAttributes(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, std::string callName);
		    
		    public: 
		    
		    /* default constructor */
		    CToPTXTranslator();
		    
		    std::string baseAddress() const;
		    void setPredicate(ir::PTXInstruction & instruction);
		    int translate(dill_stream c, void *info_ptr, void *i);
		    translator::CToPTXData generate(std::string resource);
		    
	};

}

#endif
