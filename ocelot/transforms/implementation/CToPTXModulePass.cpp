/*! \file CToPTXModulePass.cpp
	\date Tuesday July 1, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the CToPTXModulePass class
*/

#ifndef C_TO_PTX_MODULE_PASS_CPP_INCLUDED
#define C_TO_PTX_MODULE_PASS_CPP_INCLUDED

#include <ocelot/transforms/interface/CToPTXModulePass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace transforms
{

    void CToPTXModulePass::runOnModule(ir::Module& m)
    {
        ir::PTXKernel *kernel = uniqueElementCount();
        kernel->module = &m;
        m.insertKernel(kernel);
    }
	
    void CToPTXModulePass::initialize( ir::Module& m )
	{   

	}

    void CToPTXModulePass::finalize( )
	{
	
	}
	
	ir::PTXKernel * CToPTXModulePass::uniqueElementCount()
	{
	    ir::PTXKernel::PTXStatementVector statements;
	    ir::PTXInstruction inst;
	    ir::PTXStatement stmt = ir::PTXStatement(ir::PTXStatement::Instr);
	    
	    ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
	    inst.type = type;
	    
	    ir::PTXStatement reductionBuffer = ir::PTXStatement(ir::PTXStatement::Param);
	    reductionBuffer.name = "reductionBuffer";
        
        reductionBuffer.type = type;
        
        ir::PTXStatement uniqueCount = ir::PTXStatement(ir::PTXStatement::Param);
	    uniqueCount.name = "uniqueCount";
        
        uniqueCount.type = type;
        
        ir::PTXStatement startParam = ir::PTXStatement(ir::PTXStatement::StartParam);
        startParam.isReturnArgument = true;
        ir::PTXStatement endParam = ir::PTXStatement(ir::PTXStatement::EndParam);
        endParam.isReturnArgument = true;
        
        statements.push_back(startParam);
        statements.push_back(uniqueCount);
        statements.push_back(endParam);
        
        statements.push_back(ir::PTXStatement(ir::PTXStatement::StartParam));
        statements.push_back(reductionBuffer);
        statements.push_back(ir::PTXStatement(ir::PTXStatement::EndParam));

        ir::PTXStatement beginReduction(ir::PTXStatement::Label);
        beginReduction.name = BEGIN_REDUCTION;
        statements.push_back(beginReduction);
    
        //load reductionBuffer param
        inst.opcode = ir::PTXInstruction::Ld;
        inst.addressSpace = ir::PTXInstruction::Param;
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "sharedMemReg";
        inst.a.identifier = reductionBuffer.name;
        inst.a.addressMode = ir::PTXOperand::Address;
        inst.a.offset = 0;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
    
        //generate blockDim
        inst.opcode = ir::PTXInstruction::Cvt;  
        inst.d.addressMode = ir::PTXOperand::Register;

        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = "ntidx";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Cvt;  
        inst.d.addressMode = ir::PTXOperand::Register;

        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = "ntidy";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Cvt;  
        inst.d.addressMode = ir::PTXOperand::Register;

        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iz, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = "ntidz";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.d.identifier.clear();
        inst.a.identifier.clear();
        inst.b.identifier.clear();

        inst.opcode = ir::PTXInstruction::Mul;     
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "ntid";
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "ntidx";
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = "ntidy";
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "ntid";
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = "ntidz";
         
        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "uniqueCount";
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        
        inst.d.identifier = "i";
        
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        
        ir::PTXStatement beginFirstLoop(ir::PTXStatement::Label);
        beginFirstLoop.name = BEGIN_FIRST_LOOP;
        statements.push_back(beginFirstLoop);

        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = "firstLoopPred";
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "i";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = "ntid";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = STORE_RESULTS;
        inst.pg.addressMode = ir::PTXOperand::Register;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = "firstLoopPred";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        ir::PTXStatement firstLoop(ir::PTXStatement::Label);
        firstLoop.name = FIRST_LOOP;
        statements.push_back(firstLoop);
        
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "isUnique";
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 1;
        
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "j";
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        ir::PTXStatement beginSecondLoop(ir::PTXStatement::Label);
        beginSecondLoop.name = BEGIN_SECOND_LOOP;
        statements.push_back(beginSecondLoop);
        
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = "secondLoopPred";
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "j";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = "uniqueCount";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Mad;     
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "i_offset";
       
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "i";
        
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = sizeof(size_t);
        
        inst.c.type = type;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.identifier = "sharedMemReg";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.c.addressMode = ir::PTXOperand::Invalid;
        
        inst.opcode = ir::PTXInstruction::Ld;
            
        inst.addressSpace = ir::PTXInstruction::Shared; 
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.a.addressMode = ir::PTXOperand::Indirect;
        inst.d.identifier = "rhs";
        inst.a.identifier = "i_offset";
        inst.a.offset = 0;
        
        stmt.instruction = inst;
        statements.push_back(stmt);        
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = UPDATE_COUNTER;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = "secondLoopPred";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        ir::PTXStatement secondLoop(ir::PTXStatement::Label);
        secondLoop.name = SECOND_LOOP;
        statements.push_back(secondLoop);
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        inst.opcode = ir::PTXInstruction::Mad;     
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "j_offset";
       
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "j";
        
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = sizeof(size_t);
        
        inst.c.type = type;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.identifier = "sharedMemReg";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Ld;
            
        inst.addressSpace = ir::PTXInstruction::Shared; 
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "lhs";
        inst.a.identifier = "j_offset";
        inst.a.addressMode = ir::PTXOperand::Indirect;
        inst.a.offset = 0;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.a.addressMode = inst.b.addressMode = inst.c.addressMode = inst.d.addressMode = ir::PTXOperand::Invalid;
        
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = "isEqualPred";
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "lhs";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = "rhs";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "isUnique";
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = "isEqualPred";
        
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = UPDATE_COUNTER;

        stmt.instruction = inst;
        statements.push_back(stmt);
                
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        ir::PTXStatement secondLoopInc(ir::PTXStatement::Label);
        secondLoopInc.name = SECOND_LOOP_INC;
        statements.push_back(secondLoopInc);
        
        inst.opcode = ir::PTXInstruction::Add;     
        
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "j";
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "j";
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = 1;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = BEGIN_SECOND_LOOP;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        ir::PTXStatement updateCounter(ir::PTXStatement::Label);
        updateCounter.name = UPDATE_COUNTER;
        statements.push_back(updateCounter);
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        inst.d.identifier.clear();
        inst.a.identifier.clear();
        inst.b.identifier.clear();
        
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = "isUniqueTrue";
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "isUnique";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = 1;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = "isUniqueTrue";
        
        inst.opcode = ir::PTXInstruction::Add;     
           
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "uniqueCount";		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "uniqueCount";
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = 1;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        ir::PTXStatement firstLoopInc(ir::PTXStatement::Label);
        firstLoopInc.name = FIRST_LOOP_INC;
        statements.push_back(firstLoopInc);
        
        inst.opcode = ir::PTXInstruction::Add;     
           
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "i";
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "i";
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = 1;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = BEGIN_FIRST_LOOP;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        ir::PTXStatement storeResults(ir::PTXStatement::Label);
        storeResults.name = STORE_RESULTS;
        statements.push_back(storeResults);
        /*
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "globalMem";
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "__ocelot_base_address_101";
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Address;
        inst.a.offset = 0;
        
        stmt.instruction = inst;
        statements.push_back(stmt);     

        inst.opcode = ir::PTXInstruction::Ld;
        
        inst.addressSpace = ir::PTXInstruction::Global; 
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "globalMemReg";
        inst.a.identifier = "globalMem";
        inst.a.addressMode = ir::PTXOperand::Indirect;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Atom;
        inst.atomicOperation = ir::PTXInstruction::AtomicAdd;
            
        inst.addressSpace = ir::PTXInstruction::Global; 
        inst.a.addressMode = ir::PTXOperand::Indirect;
        inst.a.type = type;
        inst.a.identifier = "globalMem";
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        inst.d.identifier = "prevUniqueCount";
        
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = "sharedMemReg";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        */
        
        inst.opcode = ir::PTXInstruction::St;
        inst.addressSpace = ir::PTXInstruction::Param;
        
        inst.d.addressMode = ir::PTXOperand::Address;
        inst.d.identifier = uniqueCount.name;
        inst.d.type = type;
        inst.d.offset = 0;
        
        inst.a.identifier = "uniqueCount";
        inst.a.addressMode = ir::PTXOperand::Register;
        
        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Ret;
        inst.uni = false;
        stmt.instruction = inst;
        statements.push_back(stmt);
	    
	    ir::PTXKernel *kernel = new ir::PTXKernel(statements.begin(), statements.end(), true);
	    kernel->name = "uniqueElementCount";

	    return kernel;
	
	}
}


#endif
