/*! \file BasicBlockExecutionCountPass.cpp
	\date Sunday November 14, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockExecutionCountPass class
*/

#ifndef BASIC_BLOCK_EXECUTION_COUNT_PASS_CPP_INCLUDED
#define BASIC_BLOCK_EXECUTION_COUNT_PASS_CPP_INCLUDED

#include <ocelot/transforms/interface/BasicBlockExecutionCountPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1



namespace transforms
{
	void BasicBlockExecutionCountPass::initialize(ir::Module &m) {
		report("Adding global variable to " << m.path() );
     
        ir::PTXStatement counter = ir::PTXStatement(ir::PTXStatement::Global);
        counter.name = kernelReportInfo();
        counter.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
         
        /* inserting the global counter array into the module */
        m.insertGlobalAsStatement(counter);
    }
 
    size_t BasicBlockExecutionCountPass::incrementBasicBlockCounter(analysis::DataflowGraph::iterator block, analysis::DataflowGraph::RegisterId registerId, std::map<std::string, analysis::DataflowGraph::RegisterId> registerMap, size_t location ) {

        /* Load, increment, and store back the result into the
            global counter */
        
        size_t initial = location;

        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);

        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
        ld.addressSpace = ir::PTXInstruction::Global; 
        ld.type = type;  
	    ld.a.type = type;     
        ld.a.addressMode = ir::PTXOperand::Indirect;
        ld.a.reg = registerMap["counterPtrReg"];
        ld.d.reg = registerId;
        ld.d.addressMode = ir::PTXOperand::Register;
	    ld.d.type = type;		
        
        ir::PTXInstruction add(ir::PTXInstruction::Add);
        add.addressSpace = ir::PTXInstruction::Global; 
        add.type = type;
        add.d = ld.d;
        add.a = ld.d;
        add.b.type = type;	
        add.b.addressMode = ir::PTXOperand::Immediate;
        add.b.imm_int = block->instructions().size(); //1; //FIXME

        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;       
        st.d = ld.a;
        st.a = ld.d;

        dfg().insert( block, ld, location++ );  
        dfg().insert( block, add, location++ ); 
        dfg().insert( block, st, location++ ); 

        return location - initial;

    }

    void BasicBlockExecutionCountPass::runOnKernel( ir::IRKernel& k )
	{
		
        analysis::DataflowGraph::RegisterId registerId = dfg().newRegister();		//FIXME
		report("non predicate register: " << registerId);
        /* ensure that there is at least one basic block -- otherwise, skip this kernel */
        if(dfg().empty())
            return;
            
        analysis::DataflowGraph::iterator entry = dfg().begin();
        ++entry;

        /* instrumenting ptx at the beginning of the first basic block. */
        size_t count = calculateThreadId(entry, 0);
        size_t location = count;
        count = calculateBasicBlockCounterOffset(entry, 0, location); //FIXME
        location += count;  
        count = incrementBasicBlockCounter(entry, registerId, registerMap, location); //FIXME temp comment for debugging ld error
  		//registerId++; //to get rid of unused warning: FIXME

        unsigned int basicBlockId = 1;
        for( analysis::DataflowGraph::iterator block = ++(entry); 
		    block != dfg().end(); ++block )
	        {
               if(!block->instructions().empty()){
                    count = calculateBasicBlockCounterOffset(block, basicBlockId, 0);		//FIXME
                    count = incrementBasicBlockCounter(block, registerId, registerMap, count);	//FIXME
                    basicBlockId++;        
                } 
	        } 
	}
 
	BasicBlockExecutionCountPass::BasicBlockExecutionCountPass() 
        
    {
        baseAddress = kernelReportInfo();
		entries = 1;
    }
    
    void BasicBlockExecutionCountPass::finalize() {

    }
    
    std::string BasicBlockExecutionCountPass::kernelReportInfo() const
    {
        return basicBlockCounterBase();//"__align_error_table";
    }

}


#endif
