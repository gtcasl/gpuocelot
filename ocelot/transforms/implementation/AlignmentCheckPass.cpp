/*! \file AlignmentCheckPass.cpp
    \date Friday April 1, 2011
    \author Naila Farooqui <naila@cc.gatech.edu>
    \brief The source file for the AlignmentCheckPass class
*/

#ifndef ALIGNMENT_CHECK_PASS_CPP_INCLUDED
#define ALIGNMENT_CHECK_PASS_CPP_INCLUDED

#include <ocelot/transforms/interface/AlignmentCheckPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace transforms
{
    analysis::DataflowGraph& AlignmentCheckPass::dfg()
    {
        analysis::Analysis* graph = getAnalysis(
            analysis::Analysis::DataflowGraphAnalysis);
        assert(graph != 0);
        
        return static_cast<analysis::DataflowGraph&>(*graph);
    }
    
    void AlignmentCheckPass::initialize(ir::Module &m) {
        report( "Adding global variable to " << m.path() );
     
        ir::PTXStatement counter = ir::PTXStatement(ir::PTXStatement::Global);
        counter.name = kernelReportInfo();
        counter.type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
         
        /* inserting the global counter array into the module */
        m.insertGlobalAsStatement(counter);
    }
    
    void AlignmentCheckPass::calcOffset( analysis::DataflowGraph::iterator block, 
        size_t& location)
    {
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        
        analysis::DataflowGraph::RegisterId offset = dfg().newRegister();
        
        // mul offset, offset, sizeof(size_t) 
	    ir::PTXInstruction mul(ir::PTXInstruction::Mul);
        mul.type = type;
        mul.modifier = ir::PTXInstruction::lo;
        mul.type = type;
        mul.d.reg = offset;
        mul.d.addressMode = ir::PTXOperand::Register;
	    mul.d.type = type;
	    mul.a.addressMode = ir::PTXOperand::Register;
	    mul.a.reg = registerMap["threadId"];
        mul.b.type = type;
        mul.b.addressMode = ir::PTXOperand::Immediate;
        mul.b.imm_int = entries * sizeof(size_t);

        dfg().insert(block, mul, location++);
        
        // add counterPtrReg, counterPtr, offset      
        ir::PTXInstruction add(ir::PTXInstruction::Add);   
        add.type = type;
        add.d.type = type;
	    add.d.addressMode = ir::PTXOperand::Register;
        add.d.reg = registerMap["counterPtrReg"];
        add.a.type = type;
	    add.a.addressMode = ir::PTXOperand::Register;
        add.a.reg = registerMap["counterPtr"];
        add.b.type = type;
	    add.b.addressMode = ir::PTXOperand::Register;
        add.b.reg = offset;

        dfg().insert(block, add, location++);
    }
    
    void AlignmentCheckPass::runOnKernel( ir::IRKernel& k )
    {
        /* ensure that there is at least one basic block -- otherwise, skip this kernel */
        if( dfg().empty() )
        {
            return;
        }
        
        //compute address offset
        analysis::DataflowGraph::iterator entry = dfg().begin();

        /* instrumenting ptx at the beginning of the first basic block. */
        size_t location = calculateThreadId(entry, 0);
        calcOffset(entry, location);
        //count = calculateBasicBlockCounterOffset(entry, 0, location);
        //location += count;  
   
        for( analysis::DataflowGraph::iterator block = (entry); 
		    block != dfg().end(); ++block )
        {
            _runOnBlock( block, location );
            location = 0;
        }
    }

    void AlignmentCheckPass::_runOnBlock( analysis::DataflowGraph::iterator block,
        size_t location )
    {
        typedef analysis::DataflowGraph::InstructionVector::const_iterator
            const_iterator;
            unsigned long int loc = 0;
        const_iterator _instruction = block->instructions().begin();
        for( ; loc < location; ++loc, ++_instruction ) {}   //skip instructions of insertion
        
        for( ; _instruction != block->instructions().end(); 
            ++_instruction, ++loc )
        {
            report("testing testing testing location is ");
            ir::PTXInstruction& instruction = static_cast< 
                ir::PTXInstruction& >( *_instruction->i );
            if( instruction.opcode == ir::PTXInstruction::Ld
                || instruction.opcode == ir::PTXInstruction::Ldu
                || instruction.opcode == ir::PTXInstruction::St )
            {
                checkAlignment(block, instruction, loc);
            }
        }
    }
    
    /* ! find final memory address, mask to see if zero, report if not */
    void AlignmentCheckPass::checkAlignment( 
        const analysis::DataflowGraph::iterator block, 
        const ir::PTXInstruction& memInst, 
        unsigned long &loc ) 
    {
//        //reportInfoAddr is calculated by threadID+offset func from BasicBlockInstrumentationPass
//        mov.u64 finalAddr, addr (memInst.a or memInst.d, reg or identifier)
//        (optional) add finalAddr, finalAddr, offset
//        and.u64 masked, finalAddr, mask
//        setp.eq.u64 %p, masked, 0
//        cvt.u64.u32 tidX, special reg tid X
//        @%p st.global.u64 [reportInfoAddr + 0], tidX
//        @%p st.global.u64 [reportInfoAddr + 1], offset
//        @%p st.global.u64 [reportInfoAddr + 2], finalAddr
//        @%p st.global.u64 [reportInfoAddr + 3], addressSpace
        
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        
        analysis::DataflowGraph::RegisterId finalAddr = dfg().newRegister();
        
        ir::PTXOperand ir::PTXInstruction:: *operands[] = {&ir::PTXInstruction::d,
            &ir::PTXInstruction::a, &ir::PTXInstruction::b, &ir::PTXInstruction::c};
        
        int opId = -1;
        
        //for (int n = 0; n < 4; n++) 
        switch( memInst.opcode )
        {
            case ir::PTXInstruction::Ld:
            case ir::PTXInstruction::Ldu:
                opId = 1;
                break;
            case ir::PTXInstruction::St:
                opId = 0;
                break;
            default:
                assert(false);
                break;
        }
        
        //if 8, 16, 32, 64, 
        unsigned short mask=0;
        
        
        switch(memInst.type)
        {
            case ir::PTXOperand::s8:
            case ir::PTXOperand::u8:
            case ir::PTXOperand::b8:
                mask = 0x0;
                break;
            case ir::PTXOperand::s16:
            case ir::PTXOperand::u16:
            case ir::PTXOperand::b16:
            case ir::PTXOperand::f16:
                mask = 0x1;
                break;
            case ir::PTXOperand::s32:
            case ir::PTXOperand::u32:
            case ir::PTXOperand::f32:
            case ir::PTXOperand::b32:
                mask = 0x3;
                break;
            case ir::PTXOperand::u64:
            case ir::PTXOperand::s64:
            case ir::PTXOperand::f64:
            case ir::PTXOperand::b64:
                mask = 0x07;
                break;
            case ir::PTXOperand::pred:
            default:
                //error
                assert(false);
                break;
        }
            
//        mov.u64 finalAddr, addr (memInst.a or memInst.d, reg or identifier)
//        (optional) add finalAddr, finalAddr, offset
        ir::PTXInstruction mov(ir::PTXInstruction::Mov);
        mov.type = type;
        
        switch( (memInst.*operands[opId]).addressMode )
        {
            case ir::PTXOperand::Indirect:          //! content points to register contains address, use offset
                //move register to finalAddress -- juse use add by default?
                mov.d.type = type;      
                mov.d.addressMode = ir::PTXOperand::Register;
                mov.d.reg = finalAddr;    
                mov.a.type = type;
                mov.a.addressMode = ir::PTXOperand::Register;
                mov.a.reg = (memInst.*operands[opId]).reg;
                
                dfg().insert( block, mov, loc++ );
                
                if( (memInst.*operands[opId]).offset > 0 
                    && (memInst.*operands[opId]).offset & mask )
                {
                    ir::PTXInstruction add(ir::PTXInstruction::Add);
                    
                    add.type = type;
                    add.d.type = type;      
                    add.d.addressMode = ir::PTXOperand::Register;
                    add.d.reg = finalAddr;    
                    add.a.type = type;      
                    add.a.addressMode = ir::PTXOperand::Register;
                    add.a.reg = finalAddr;
                    add.b.addressMode = ir::PTXOperand::Immediate;
                    add.b.imm_int = (memInst.*operands[opId]).offset;
                    
                    dfg().insert( block, add, loc++ );
                }
                break;
            case ir::PTXOperand::Register:            //! use as register variable
                //move said register to finalAddress
                mov.d.type = type;          
                mov.d.addressMode = ir::PTXOperand::Register;
                mov.d.reg = finalAddr;
                mov.a.type = type;
                mov.a.addressMode = ir::PTXOperand::Register;
                mov.a.reg = (memInst.*operands[opId]).reg;
                
                dfg().insert( block, mov, loc++ );
                break;
            case ir::PTXOperand::Address:            //! treat as address, use offset
                //move said address to finalAddress
                mov.d.type = type;          
                mov.d.addressMode = ir::PTXOperand::Register;
                mov.d.reg = finalAddr;
                mov.a.type = type;
                if( memInst.addressSpace == ir::PTXInstruction::Param )
                {
                    if( (memInst.*operands[opId]).offset == 0)
                        return;
                        
                    mov.a.addressMode = ir::PTXOperand::Immediate;
                    mov.a.imm_uint = 0;
                } else {
                    mov.a.addressMode = ir::PTXOperand::Address;
                    mov.a.identifier = (memInst.*operands[opId]).identifier;
                }
                
                dfg().insert( block, mov, loc++ );
                mov.a.identifier.clear();
                
                if( (memInst.*operands[opId]).offset > 0 
                    && (memInst.*operands[opId]).offset & mask )
                {
                    ir::PTXInstruction add(ir::PTXInstruction::Add);
                    
                    add.type = type;
                    add.d.type = type;      
                    add.d.addressMode = ir::PTXOperand::Register;
                    add.d.reg = finalAddr;    
                    add.a.type = type;      
                    add.a.addressMode = ir::PTXOperand::Register;
                    add.a.reg = finalAddr;
                    add.b.addressMode = ir::PTXOperand::Immediate;
                    add.b.imm_int = (memInst.*operands[opId]).offset;
                    
                    dfg().insert( block, add, loc++ );
                }
                break;
             default:
                //error
                break;
        }
        
//        and.u64 masked, finalAddr, mask
        analysis::DataflowGraph::RegisterId masked = dfg().newRegister();
        ir::PTXInstruction _and(ir::PTXInstruction::And);
        
        _and.type = ir::PTXOperand::b64;  
        _and.d.type = ir::PTXOperand::b64;
        _and.d.addressMode = ir::PTXOperand::Register;
        _and.d.reg = masked;
        _and.a.type = ir::PTXOperand::u64;
        _and.a.addressMode = ir::PTXOperand::Register; 
        _and.a.reg = finalAddr;
        _and.b.type = ir::PTXOperand::b64;
        _and.b.addressMode = ir::PTXOperand::Immediate;
        _and.b.imm_int = mask;
        
        dfg().insert( block, _and, loc++ );
        
//        setp.eq.u64 %p, masked, 0
        analysis::DataflowGraph::RegisterId pred = dfg().newRegister();
        
        ir::PTXInstruction setp(ir::PTXInstruction::SetP);
        setp.type = type;
        setp.comparisonOperator = ir::PTXInstruction::Ne;
        setp.d.reg = pred;
        setp.d.type = ir::PTXOperand::pred;
        setp.d.addressMode = ir::PTXOperand::Register;
        setp.a.addressMode = ir::PTXOperand::Register;
        setp.a.reg = masked;
        setp.b.addressMode = ir::PTXOperand::Immediate;
        setp.b.imm_int = 0;
        
        dfg().insert( block, setp, loc++ );
        
        /////////////////////////////////////////////////////////////////////
//        instruction.opcode = ir::PTXInstruction::Call;
//		instruction.tailCall = true;
//		instruction.branchTargetInstruction = -1;
//		instruction.a = ir::PTXOperand(
//			ir::PTXOperand::FunctionName, "_ZOcelotBarrierKernel");
//		instruction.d.addressMode = ir::PTXOperand::Invalid;
//        
        
        //find thread id: x, y, z, blockx, blocky, blockz
        analysis::DataflowGraph::RegisterId tidX = dfg().newRegister();

        ir::PTXInstruction cvt(ir::PTXInstruction::Cvt);
        cvt.type = type;
        cvt.d.addressMode = ir::PTXOperand::Register;
        cvt.d.reg = tidX;
        cvt.d.type = type;
        cvt.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        cvt.a.addressMode = ir::PTXOperand::Special;
        cvt.a.vec = ir::PTXOperand::v1;
        
        dfg().insert( block, cvt, loc++ );
        
//        ld.global.u64 %reportInfo, [reportinfoaddr]
//        analysis::DataflowGraph::RegisterId reportInfo = dfg().newRegister();
//        
//        ir::PTXInstruction ld(ir::PTXInstruction::Ld);
//        ld.addressSpace = ir::PTXInstruction::Global; 
//        ld.type = type;
//        ld.d.type = type;
//        ld.d.addressMode = ir::PTXOperand::Register;
//        ld.d.reg = reportInfo;
//        ld.a.type = type;
//        ld.a.addressMode = ir::PTXOperand::Indirect;
//        ld.a.identifier = kernelReportInfo(); //"__cudaparm__Z12square_arrayPi_a";//
//        ld.a.offset = 0;
//        
//        dfg().insert( block, ld, loc++ );
        
//        @%p st.global.u64 [reportInfoAddr + 0], tidX
        ir::PTXInstruction st(ir::PTXInstruction::St);
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;
        st.d.reg = registerMap["counterPtrReg"];//reportInfo;
        st.d.addressMode = ir::PTXOperand::Indirect;
        st.d.offset = 0;
        st.a.type = type;
        st.a.addressMode = ir::PTXOperand::Register;
        st.a.reg = tidX;
        st.pg.condition = ir::PTXOperand::Pred;
        st.pg.reg = pred;  
        
        dfg().insert( block, st, loc++ );
        
        //        @%p st.global.u64 [reportInfoAddr + 0], finalAddr
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;
        st.d.reg = registerMap["counterPtrReg"];//reportInfo;
        st.d.addressMode = ir::PTXOperand::Indirect;
        st.d.offset = sizeof(size_t);
        st.a.type = type;
        st.a.addressMode = ir::PTXOperand::Register;
        st.a.reg = finalAddr;//tidX;
        st.pg.condition = ir::PTXOperand::Pred;
        st.pg.reg = pred;  
        
        dfg().insert( block, st, loc++ );
        
        //@%p st.global.u64 [reportInfoAddr + 1], offset
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;
        st.d.reg = registerMap["counterPtrReg"];//reportInfo;
        st.d.addressMode = ir::PTXOperand::Indirect;
        st.d.offset = sizeof(size_t)*2;
        st.a.type = type;
        st.a.addressMode = ir::PTXOperand::Register;
        st.a.reg = masked;
        st.pg.condition = ir::PTXOperand::Pred;
        st.pg.reg = pred;  
        
        dfg().insert( block, st, loc++ );

        //@%p st.global.u64 [reportInfoAddr + 1], addressSpace
        st.addressSpace = ir::PTXInstruction::Global; 
        st.type = type;
        st.d.reg = registerMap["counterPtrReg"];//reportInfo;
        st.d.addressMode = ir::PTXOperand::Indirect;
        st.d.offset = sizeof(size_t)*3;
        st.a.type = type;
        st.a.addressMode = ir::PTXOperand::Immediate;
        st.a.imm_uint = 42;
        st.pg.condition = ir::PTXOperand::Pred;
        st.pg.reg = pred;  
        
        dfg().insert( block, st, loc++ );
        
        ir::PTXInstruction exit(ir::PTXInstruction::Exit);
        exit.pg.condition = ir::PTXOperand::Pred;
        exit.pg.reg = pred;
        
        //dfg().insert( block, exit, loc++ );

    }
    
    AlignmentCheckPass::AlignmentCheckPass() 
        : entries(4) 
//        KernelPass( Analysis::DataflowGraphAnalysis,
//            "Alignment Check Pass" )
    {
        baseAddress = kernelReportInfo();
		name = "Alignment Check Pass";
    }
    
    void AlignmentCheckPass::finalize() {

    }
    
    std::string AlignmentCheckPass::kernelReportInfo() const
    {
        return basicBlockCounterBase();//"__align_error_table";
    }
}


#endif
