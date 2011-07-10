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

namespace translator {

    class PredicateInfo {
    
        public:
        
            std::string id;
            bool set;
            std::string branchLabel;
            
            enum Cond {
                TAKEN,
                NOT_TAKEN
            };
    
            Cond condition;
    
    };

    /*! \brief A class containing C-to-PTX translation data.
	*/
	class CToPTXData
	{
	    public:
	    
	        typedef std::vector<std::string> RegisterVector;
	        
	        ir::PTXKernel::PTXStatementVector statements;
		    ir::PTXKernel::PTXStatementVector globals;
		    RegisterVector registers;
	
	};


	/*! \brief A class translating C-on-Demand (COD) IR to PTX.
	*/
	class CToPTXTranslator
	{
			
		public:
		    
		    enum SpecialSymbols {
			    clock64,
			    tidx,
			    tidy,
			    tidz,
			    tid,
			    ntidx,
			    ntidy,
			    ntidz,
			    ntid,
			    ctaidx,
			    ctaidy,
			    ctaidz,
			    ctaid,
			    nctaidx,
			    nctaidy,
			    nctaidz,
			    nctaid,
			    gridid,
			    smid,
			    bar
		    };
		
		    SpecialSymbols symbols;
		
		    typedef std::map<std::string, std::string> RegisterMap;
		    typedef std::map<std::string, size_t> FunctionCallMap;
		    typedef std::vector<PredicateInfo> PredicateList;
		    typedef std::vector<std::string> RegisterVector;
		    
		    ir::PTXKernel *kernel;
		    ir::PTXKernel::PTXStatementVector statements;
		    ir::PTXKernel::PTXStatementVector globals;
		    RegisterMap registerMap;	
		    FunctionCallMap functionCalls;
		    PredicateList predicateList;
		    RegisterVector registers;
		    
		    unsigned int maxRegister;	
		    unsigned int maxPredicate;
		    
		    std::string baseReg;	  
		    
		    public: 
		    
		    /* default constructor */
		    CToPTXTranslator();
		    
		    std::string baseAddress() const;
		    void setPredicate(ir::PTXInstruction & instruction);
		    int translate(dill_stream c, void *info_ptr, void *i);
		    translator::CToPTXData generate();
		    
	};

}

#endif
