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

#include <hydrazine/implementation/Exception.h>

namespace transforms
{

    void CToPTXModulePass::runOnModule(ir::Module& m)
    {
        ir::PTXKernel *kernel;
        if(functionName == UNIQUE_ELEMENT_COUNT)
        {
            kernel = uniqueElementCount();
        }
        else 
        {
            throw hydrazine::Exception( "No function name specified for module pass!");
        }

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
	    bool overHalfWarp = parameterMap[UNIQUE_ELEMENT_COUNT] == 1 ? true : false;

        ir::PTXKernel::PTXStatementVector statements;
        ir::PTXInstruction inst;
        ir::PTXStatement stmt = ir::PTXStatement(ir::PTXStatement::Instr);

        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        inst.type = type;

        ir::PTXStatement reductionBuffer = ir::PTXStatement(ir::PTXStatement::Param);
        reductionBuffer.name = "reductionBuffer";
        reductionBuffer.type = type;

        ir::PTXStatement bitMask = ir::PTXStatement(ir::PTXStatement::Param);
        bitMask.name = "bitMask";
        bitMask.type = ir::PTXOperand::b32;

        ir::PTXStatement uniqueCount = ir::PTXStatement(ir::PTXStatement::Param);
        uniqueCount.name = "uniqueCount";
        uniqueCount.type = type;


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

        inst.opcode = ir::PTXInstruction::Ld;
        inst.addressSpace = ir::PTXInstruction::Param;

        inst.type = ir::PTXOperand::b32;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = ir::PTXOperand::b32;

        inst.d.identifier = "bitmask";
        inst.a.identifier = bitMask.name;
        inst.a.addressMode = ir::PTXOperand::Address;
        inst.a.offset = 0;

        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.type = type;

        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "uniqueCountTotal";
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;

        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        if(overHalfWarp)
        {
        
            inst.opcode = ir::PTXInstruction::Mov;
            inst.d.identifier = "halfWarp";
            
            inst.d.type = type;          
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.addressMode = ir::PTXOperand::Immediate;
            inst.a.type = type;
            inst.a.imm_int = 0;


            stmt.instruction = inst;
            statements.push_back(stmt);            
        
            ir::PTXStatement beginHalfWarpLoop(ir::PTXStatement::Label);
            beginHalfWarpLoop.name = BEGIN_HALF_WARP_LOOP;
            statements.push_back(beginHalfWarpLoop);

            inst.opcode = ir::PTXInstruction::Mul;
            inst.modifier = ir::PTXInstruction::lo;
            inst.d.addressMode = inst.a.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = "offset";
            inst.a.identifier = "halfWarp";
            inst.d.type = inst.a.type = inst.b.type = type;
            inst.b.addressMode = ir::PTXOperand::Immediate;
            inst.b.imm_uint = 16;        

            stmt.instruction = inst;
            statements.push_back(stmt);    

            inst.modifier = ir::PTXInstruction::Modifier_invalid;

            inst.opcode = ir::PTXInstruction::Mov;
                     
            inst.d.identifier = "i";
                 
            inst.d.type = type;          
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.addressMode = ir::PTXOperand::Immediate;
            inst.a.type = type;
            inst.a.imm_int = 0;

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


            inst.pg.condition = ir::PTXOperand::PT;
            inst.pg.identifier.clear();

            ir::PTXStatement halfWarpLoop(ir::PTXStatement::Label);
            halfWarpLoop.name = HALF_WARP_LOOP;
            statements.push_back(halfWarpLoop);

            inst.opcode = ir::PTXInstruction::SetP;
                
            inst.d.type = ir::PTXOperand::pred;
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = "halfWarpLoopPred";

            inst.comparisonOperator = ir::PTXInstruction::Eq;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Register;
            inst.a.identifier = "halfWarp";
            inst.b.type = type;
            inst.b.addressMode = ir::PTXOperand::Immediate;
            inst.b.imm_uint = 2;

            stmt.instruction = inst;
            statements.push_back(stmt);

            inst.opcode = ir::PTXInstruction::Bra;
            inst.d.addressMode = ir::PTXOperand::Label;
            inst.d.identifier = STORE_RESULTS;
            inst.pg.addressMode = ir::PTXOperand::Register;
            inst.pg.condition = ir::PTXOperand::Pred;
            inst.pg.identifier = "halfWarpLoopPred";

            stmt.instruction = inst;
            statements.push_back(stmt);

            inst.pg.condition = ir::PTXOperand::PT;
            inst.pg.identifier.clear();

        }
        else 
        {
            inst.opcode = ir::PTXInstruction::Mov;
                     
            inst.d.identifier = "i";
                 
            inst.d.type = type;          
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.addressMode = ir::PTXOperand::Immediate;
            inst.a.type = type;
            inst.a.imm_int = 0;

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

        }

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
        inst.b.addressMode = ir::PTXOperand::Immediate;
        if(overHalfWarp)
        {
            inst.b.imm_uint = 16;
        }
        else
        {
            inst.b.imm_uint = 32;
        }
        
        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        
        if(overHalfWarp)
        {
            inst.d.identifier = HALF_WARP_LOOP_INC;
        }
        else
        {
            inst.d.identifier = STORE_RESULTS;
        }
        
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

        if(overHalfWarp)
        {

            inst.opcode = ir::PTXInstruction::Add;
            inst.d.type = inst.a.type = inst.b.type = type;
            inst.d.addressMode = inst.a.addressMode = inst.b.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = "i_offset";
            inst.a.identifier = "i";
            inst.b.identifier = "offset";

            stmt.instruction = inst;
            statements.push_back(stmt);
        }
 
      
        //cvt.u32.u64
        inst.opcode = ir::PTXInstruction::Cvt;  
        inst.type = ir::PTXOperand::u32;
        inst.d.type = ir::PTXOperand::u32;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = "i_b32";
        if(overHalfWarp)
            inst.a.identifier = "i_offset";
        else
            inst.a.identifier = "i";
        inst.a.type = type;

        stmt.instruction = inst;
        statements.push_back(stmt);

        //shl.b32 %rb2, 1, i;
        inst.opcode = ir::PTXInstruction::Shl;
        inst.type = ir::PTXOperand::b32;
        inst.d.type = ir::PTXOperand::b32;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = "rb2";
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.imm_uint = 1;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = ir::PTXOperand::b32;        
        inst.b.identifier = "i_b32";

        stmt.instruction = inst;
        statements.push_back(stmt);

        //and %rb3, bitmask, %rb2
        inst.opcode = ir::PTXInstruction::And;
        inst.type = ir::PTXOperand::b32;
        inst.d.identifier = "rb3";
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "bitmask";
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = "rb2";

        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.type = ir::PTXOperand::s32;
        inst.d.type = ir::PTXOperand::s32;

        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = "isNotActive";

        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "rb3";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = 0;

        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = FIRST_LOOP_INC;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = "isNotActive";

        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.type = type; 
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();

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

        inst.comparisonOperator = ir::PTXInstruction::CmpOp_Invalid;

        inst.opcode = ir::PTXInstruction::Mad;     
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;

        inst.d.identifier = "i_offset";

        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        
        if(overHalfWarp)
        {
            inst.a.identifier = "i_offset";
        }
        else
        {
            inst.a.identifier = "i";
        }

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
        
        inst.pg.condition = ir::PTXOperand::PT;

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

        inst.modifier = ir::PTXInstruction::Modifier_invalid;
    
        if(overHalfWarp)
        {

            inst.opcode = ir::PTXInstruction::Add;
            inst.d.type = inst.a.type = inst.b.type = type;
            inst.d.addressMode = inst.a.addressMode = inst.b.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = "j_offset";
            inst.a.identifier = "j";
            inst.b.identifier = "offset";

            stmt.instruction = inst;
            statements.push_back(stmt);
        }

        inst.opcode = ir::PTXInstruction::Mad;     
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;

        inst.d.identifier = "j_offset";

        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        
        if(overHalfWarp)
        {
            inst.a.identifier = "j_offset";
        }
        else
        {
            inst.a.identifier = "j";
        }

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

        if(overHalfWarp)
        {

            inst.opcode = ir::PTXInstruction::Add;
            inst.d.type = inst.a.type = inst.b.type = type;
            inst.d.addressMode = inst.a.addressMode = inst.b.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = "uniqueCount_offset";
            inst.a.identifier = "uniqueCount";
            inst.b.identifier = "offset";

            stmt.instruction = inst;
            statements.push_back(stmt);
        }    

        inst.opcode = ir::PTXInstruction::Mad;     
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;

        inst.d.identifier = "uniqueCount_offset";

        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        
        if(overHalfWarp)
        {
            inst.a.identifier = "uniqueCount_offset";
        }
        else
        {
            inst.a.identifier = "uniqueCount";
        }

        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = sizeof(size_t);

        inst.c.type = type;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.identifier = "sharedMemReg";

        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.c.addressMode = ir::PTXOperand::Invalid;

        inst.opcode = ir::PTXInstruction::St;
            
        inst.addressSpace = ir::PTXInstruction::Shared; 
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;

        inst.d.addressMode = ir::PTXOperand::Indirect;
        inst.a.identifier = "rhs";
        inst.d.identifier = "uniqueCount_offset";
        inst.d.offset = 0;

        stmt.instruction = inst;
        statements.push_back(stmt);        

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

        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();

        if(overHalfWarp)
        {
            ir::PTXStatement halfWarpLoopInc(ir::PTXStatement::Label);
            halfWarpLoopInc.name = HALF_WARP_LOOP_INC;
            statements.push_back(halfWarpLoopInc);

            inst.opcode = ir::PTXInstruction::Add;     
               
            inst.modifier = ir::PTXInstruction::Modifier_invalid;
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.type = type;

            inst.d.identifier = "halfWarp";

            inst.a.addressMode = ir::PTXOperand::Register;
            inst.a.type = type;
            inst.a.identifier = "halfWarp";
            inst.b.addressMode = ir::PTXOperand::Immediate;
            inst.b.type = type;
            inst.b.imm_uint = 1;
             
            stmt.instruction = inst;
            statements.push_back(stmt);

            inst.opcode = ir::PTXInstruction::Add;
            inst.d.type = inst.a.type = inst.b.type = type;
            inst.d.addressMode = inst.a.addressMode = inst.b.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = "uniqueCountTotal";
            inst.a.identifier = "uniqueCountTotal";
            inst.b.identifier = "uniqueCount";

            stmt.instruction = inst;
            statements.push_back(stmt);

    
            inst.opcode = ir::PTXInstruction::Bra;
            inst.d.addressMode = ir::PTXOperand::Label;
            inst.d.identifier = BEGIN_HALF_WARP_LOOP;

            stmt.instruction = inst;
            statements.push_back(stmt);
        }

        ir::PTXStatement storeResults(ir::PTXStatement::Label);
        storeResults.name = STORE_RESULTS;
        statements.push_back(storeResults);

        inst.opcode = ir::PTXInstruction::St;
        inst.addressSpace = ir::PTXInstruction::Param;

        inst.d.addressMode = ir::PTXOperand::Address;
        inst.d.identifier = uniqueCount.name;
        inst.d.type = type;
        inst.d.offset = 0;

        inst.a.identifier = "uniqueCountTotal";
        inst.a.addressMode = ir::PTXOperand::Register;

        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.pg.condition = ir::PTXOperand::PT;

        inst.opcode = ir::PTXInstruction::Ret;
        inst.uni = false;
        stmt.instruction = inst;
        statements.push_back(stmt);

        ir::PTXKernel *kernel = new ir::PTXKernel(statements.begin(), statements.end(), true);
        kernel->name = "uniqueElementCount";

        kernel->arguments.push_back(ir::Parameter(reductionBuffer, true, false));
        kernel->arguments.push_back(ir::Parameter(bitMask, true, false));
        kernel->arguments.push_back(ir::Parameter(uniqueCount, true, true));

        return kernel;
	
	}

    CToPTXModulePass::CToPTXModulePass(std::string functionName)
        : functionName(functionName)
    {

    }
}


#endif
