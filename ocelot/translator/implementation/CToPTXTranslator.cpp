/*! \file CToPTXTranslator.cpp
	\date Wednesday June 8, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the CToPTXTranslator class
*/

#ifndef C_TO_PTX_TRANSLATOR_CPP_INCLUDED
#define C_TO_PTX_TRANSLATOR_CPP_INCLUDED

#include <ocelot/translator/interface/CToPTXTranslator.h>
#include <ocelot/translator/interface/CToPTXInterface.h>

#include <hydrazine/implementation/Exception.h>

#include <boost/lexical_cast.hpp>

#define REG         "r"
#define COD_REG     "\%codr"
#define COD_PRED    "\%codp"

#define EMIT_COD    0

namespace translator
{

    std::string arith3_name[] = {"addi", "addu", "addul", "addl", "subi", "subu", "subul", "subl", "muli", "mulu", "mulul", "mull", "divi", "divu", "divul", "divl", "modi",        "modu", "modul", "modl", "xori", "xoru", "xorul", "xorl", "andi", "andu", "andul", "andl", "ori", "oru", "orul", "orl", "lshi", "lshu", "lshul", "lshl", "rshi", "rshu", "rshul", "rshl", "addp", "subp", "addf", "addd", "subf", "subd", "mulf", "muld", "divf", "divd"};

    std::string branch_op_names[] = {"eqc", "equc", "eqs", "equs", "eqi", "equ", "eql", "equl", "eqp", "eqf", "eqd", "gec", "geuc", "ges", "geus", "gei", "geu", "gel", "geul", "gep", "gef", "ged", "gtc", "gtuc", "gts", "gtus", "gti", "gtu", "gtl", "gtul", "gtp", "gtf", "gtd", "lec", "leuc", "les", "leus", "lei", "leu", "lel", "leul", "lep", "lef", "led", "ltc", "ltuc", "lts", "ltus", "lti", "ltu", "ltl", "ltul", "ltp", "ltf", "ltd", "nec", "neuc", "nes", "neus", "nei", "neu", "nel", "neul", "nep", "nef", "ned"};

    translator::CToPTXTranslator translator;

    void foreign_code_generator(dill_stream s, virtual_insn *start, virtual_insn *end)
    {
        void *info;
        void *base = s->p->code_base;
        if (base == NULL) {
	        base = s->p->native.code_base;
        }
        if (base == NULL) {
	        return;
        }
     
        void *p;
	    int l;
	    int insn_count = 0;

	    if ((s->j != s->p->_virtual.mach_jump) && (s->p->fp != NULL) )
	        base = s->p->fp;
	
	    for (p =base; (char*) p < s->p->cur_ip;) {
	      
	        l = translator.translate(s, &info, (void *)p);
	        #if EMIT_COD
	        l = s->j->print_insn(s, &info, (void *)p);
	        printf("\n");
	        #endif
	        if (l <= 0) return;
	        p = (char*)p + l;
	        insn_count++;
	    }
    }


    std::string CToPTXTranslator::baseAddress() const
	{
		return "__ocelot_base_address_";
	}

    void CToPTXTranslator::setPredicate(ir::PTXInstruction & instruction) {

        for (PredicateList::const_iterator pred = predicateList.begin(); 
	        pred != predicateList.end(); ++pred) {
            
            if(pred->targetId == targetId)
            {

                if(pred->inv)
                    instruction.pg.condition = ir::PTXOperand::InvPred;
                else    
                    instruction.pg.condition = ir::PTXOperand::Pred;
                
                instruction.pg.identifier = pred->id;
                instruction.pg.type = ir::PTXOperand::pred;
                instruction.pg.addressMode = ir::PTXOperand::Register;   
            }            
        }
    }
    
    void CToPTXTranslator::generateBlockId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;  
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Special;
            
        
        if(specialRegisterMap["ctaidX"].empty())
        {
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            std::string ctaidX = inst.d.identifier;
            registers.push_back(ctaidX);
        
            specialRegisterMap["ctaidX"] = ctaidX;
        
            inst.d.type = type;
            inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;
            
            stmt.instruction = inst;
            setPredicate(inst);
            statements.push_back(stmt);
        }
            
        if(specialRegisterMap["ctaidY"].empty())
        {    
            inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;       
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            std::string ctaidY = inst.d.identifier;
            registers.push_back(ctaidY);
            
            specialRegisterMap["ctaidY"] = ctaidY;
               
            stmt.instruction = inst;
            setPredicate(inst);
            statements.push_back(stmt);
        
        }
        
        if(specialRegisterMap["nctaidX"].empty())
        {
            inst.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;       
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            std::string nctaidX = inst.d.identifier;		 
            registers.push_back(nctaidX);
            
            specialRegisterMap["nctaidX"] = nctaidX;   
               
            stmt.instruction = inst;
            setPredicate(inst);
            statements.push_back(stmt);
        }

        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string ctaid = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = specialRegisterMap["ctaidY"];
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["nctaidX"];
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = specialRegisterMap["ctaidX"];
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        registers.push_back(ctaid);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = ctaid;
        
        specialRegisterMap["ctaid"] = ctaid;
    
    }
    
    void CToPTXTranslator::generateSMId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;
        setPredicate(inst);
        
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a = ir::PTXOperand(ir::PTXOperand::smId);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.type = ir::PTXOperand::u32;
        inst.a.vec = ir::PTXOperand::v1;
        inst.a.vIndex = ir::PTXOperand::ix;
        
        stmt.instruction = inst;
        statements.push_back(stmt);        
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;    
    
    }
    
    void CToPTXTranslator::generateWarpId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        generateBlockId(inst, stmt, type, insn);
        generateBlockDim(inst, stmt, type, insn);
        generateBlockThreadId(inst, stmt, type, insn);
        
        inst.opcode = ir::PTXInstruction::Mad;
        inst.modifier = ir::PTXInstruction::lo;
        inst.type = inst.d.type = inst.a.type = inst.b.type = inst.c.type = type;
        inst.a.addressMode = inst.b.addressMode = inst.c.addressMode = inst.d.addressMode = ir::PTXOperand::Register;
        
        std::string madResult = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        inst.d.identifier = madResult;
        registers.push_back(inst.d.identifier);
        
        inst.a.identifier = specialRegisterMap["ctaid"];
        inst.b.identifier = specialRegisterMap["ntid"];
        inst.c.identifier = specialRegisterMap["blockThreadId"];
        
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        inst.opcode = ir::PTXInstruction::Div;
        inst.c.addressMode = ir::PTXOperand::Invalid;
        
        std::string warpId = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        inst.d.identifier = warpId;
        registers.push_back(inst.d.identifier);
        
        inst.a.identifier = madResult;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = 32; //warpSize
        
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;    
    }
    
    void CToPTXTranslator::generateWarpCount(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        if(specialRegisterMap["ntid"].empty())
            generateBlockDim(inst, stmt, type, insn);
            
        if(specialRegisterMap["nctaid"].empty())
            generateGridDim(inst, stmt, type, insn);
    
        inst.opcode = ir::PTXInstruction::Mul;
        inst.modifier = ir::PTXInstruction::lo;
        setPredicate(inst);
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        
        inst.d.type = inst.a.type = inst.b.type = type;
        inst.d.addressMode = inst.a.addressMode = inst.b.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = specialRegisterMap["ntid"];
        inst.b.identifier = specialRegisterMap["nctaid"];
        
        stmt.instruction = inst;
        statements.push_back(stmt);        
        
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.opcode = ir::PTXInstruction::Shr;
        inst.a.identifier = inst.d.identifier;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = 5;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;    
    
    }
    
    void CToPTXTranslator::generateClockCounter(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.type = ir::PTXOperand::u64;
        inst.d.type = ir::PTXOperand::u64;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a = ir::PTXOperand(ir::PTXOperand::clock64, ir::PTXOperand::ix);
        inst.a.type = ir::PTXOperand::u64;
	    inst.a.vec = ir::PTXOperand::v1;

        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);	
        registers.push_back(inst.d.identifier);	      
                  
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);        
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;        
    }
    
    void CToPTXTranslator::generateThreadIndexX(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        if(specialRegisterMap["tidX"].empty())
        {
            inst.opcode = ir::PTXInstruction::Cvt;
            setPredicate(inst);

            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            registers.push_back(inst.d.identifier);
            
            inst.d.type = type;
            inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
            inst.a.addressMode = ir::PTXOperand::Special;
            inst.a.vec = ir::PTXOperand::v1;
            
            stmt.instruction = inst;
            statements.push_back(stmt);    
            
            specialRegisterMap["tidX"] = inst.d.identifier;       
        }
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = specialRegisterMap["tidX"]; 
    }
    
    void CToPTXTranslator::generateBlockDim(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;  
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;    
        inst.a.addressMode = ir::PTXOperand::Special;
            
        if(specialRegisterMap["ntidX"].empty())
        {
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            registers.push_back(inst.d.identifier);
            std::string ntidX = inst.d.identifier;

            specialRegisterMap["ntidX"] = ntidX;
        
            inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::ix, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;
            
            stmt.instruction = inst;
            statements.push_back(stmt);
        }
        
        if(specialRegisterMap["ntidY"].empty())
        {
            inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iy, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;       
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            registers.push_back(inst.d.identifier);
            std::string ntidY = inst.d.identifier;
        
            specialRegisterMap["ntidY"] = ntidY;
            
            stmt.instruction = inst;
            statements.push_back(stmt);
        }
        
        
        if(specialRegisterMap["ntidZ"].empty())
        {
            inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iz, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;       
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            registers.push_back(inst.d.identifier);
            std::string ntidZ = inst.d.identifier;		 
        
            specialRegisterMap["ntidZ"] = ntidZ;
    
            stmt.instruction = inst;
            statements.push_back(stmt);
        }
        
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ntid = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = specialRegisterMap["ntidX"];
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["ntidY"];
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = ntid;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["ntidZ"];
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = ntid;
        
        specialRegisterMap["ntid"] = ntid;
    }

    void CToPTXTranslator::generateGridDim(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;  

        inst.d.addressMode = ir::PTXOperand::Register;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string nctaidX = inst.d.identifier;

        inst.d.type = type;
        inst.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.vec = ir::PTXOperand::v1;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string nctaidY = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::iz, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string nctaidZ = inst.d.identifier;		 
        
        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string nctaid = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = nctaidX;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = nctaidY;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = nctaid;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = nctaidZ;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = nctaid;
        
        specialRegisterMap["nctaid"] = nctaid;
        specialRegisterMap["nctaidX"] = nctaidX;
        specialRegisterMap["nctaidY"] = nctaidY;
        specialRegisterMap["nctaidZ"] = nctaidZ;
    }

    void CToPTXTranslator::generateGlobalThreadId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        if(specialRegisterMap["ntidX"].empty())
            generateBlockDim(inst, stmt, type, insn);        
    
        inst.opcode = ir::PTXInstruction::Cvt;  

        inst.d.addressMode = ir::PTXOperand::Register;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string tidX = inst.d.identifier;

        inst.d.type = type;
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.vec = ir::PTXOperand::v1;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string tidY = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iz, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string tidZ = inst.d.identifier;		 
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ctaidX = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ctaidY = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string nctaidX = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        //mad tid.y * ntid.x + tid.x
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string madA = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = tidY;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["ntidX"];
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = tidX;
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        //mul ntid.x * ntid.y * tid.z
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string mulA = inst.d.identifier;	 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = specialRegisterMap["ntidX"];
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["ntidY"];
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a.identifier = inst.d.identifier;
        inst.b.identifier = tidZ;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        
        //add (tid.y * ntid.x + tid.x) + (ntid.x * ntid.y * tid.z)
        inst.opcode = ir::PTXInstruction::Add;     
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        setPredicate(inst);
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string tid = inst.d.identifier;	 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = madA;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = mulA;
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        //mad ctaid.y * nctaid.x + ctaid.x
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string madB = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = ctaidY;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = nctaidX;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = ctaidX;
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        //mad ntid * (ctaid.y * nctaid.x + ctaid.x) + tid
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string globalThreadId = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = mulA;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = madB;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = tid;
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);    
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;  
        
        specialRegisterMap["threadId"] = globalThreadId;
    }
    
    void CToPTXTranslator::generateBlockThreadId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;  
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;    
        inst.a.addressMode = ir::PTXOperand::Special;            

        if(specialRegisterMap["tidX"].empty())
        {
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            std::string tidX = inst.d.identifier;
            
            registers.push_back(tidX);
            specialRegisterMap["tidX"] = tidX;
                
            inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;
            
            stmt.instruction = inst;
            setPredicate(inst);
            statements.push_back(stmt);
        }
        
        
        if(specialRegisterMap["tidY"].empty())
        {
            inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iy, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;       
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            std::string tidY = inst.d.identifier;
         
            registers.push_back(tidY);
            specialRegisterMap["tidY"] = tidY;
            
            stmt.instruction = inst;
            setPredicate(inst);
            statements.push_back(stmt);
        }
            
        if(specialRegisterMap["tidZ"].empty())
        {    
            inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iz, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;       
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            std::string tidZ = inst.d.identifier;		 
         
            registers.push_back(tidZ);
            specialRegisterMap["tidZ"]  = tidZ;
            
            stmt.instruction = inst;
            setPredicate(inst);
            statements.push_back(stmt);
        }
            
        if(specialRegisterMap["ntidX"].empty())
        {    
            inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::ix, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;       
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            std::string ntidX = inst.d.identifier;		 
         
            registers.push_back(ntidX);
            specialRegisterMap["ntidX"] = ntidX;      
                  
            stmt.instruction = inst;
            setPredicate(inst);
            statements.push_back(stmt);
        }    
        
        if(specialRegisterMap["ntidY"].empty())
        {
            inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iy, ir::PTXOperand::u32);
            inst.a.vec = ir::PTXOperand::v1;       
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            std::string ntidY = inst.d.identifier;		 
            registers.push_back(ntidY);
         
            specialRegisterMap["ntidY"] = ntidY;  
                  
            stmt.instruction = inst;
            setPredicate(inst);
            statements.push_back(stmt);
        }

        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string madTidYnTidXtidX = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = specialRegisterMap["tidY"];
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["ntidX"];
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = specialRegisterMap["tidX"];
         
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string mulTidZnTidXnTidY = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = specialRegisterMap["tidZ"];
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["ntidX"];
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.d.identifier = mulTidZnTidXnTidY;
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = mulTidZnTidXnTidY;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = specialRegisterMap["ntidY"];
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Add;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string addResult = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = madTidYnTidXtidX;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = mulTidZnTidXnTidY;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        registers.push_back(mulTidZnTidXnTidY);
        registers.push_back(madTidYnTidXtidX);
        registers.push_back(addResult);
        
        specialRegisterMap["blockThreadId"] = addResult;
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = addResult;
    
    }
    
    void CToPTXTranslator::generateSyncThreads(ir::PTXInstruction inst, ir::PTXStatement stmt)
    {
        inst.opcode = ir::PTXInstruction::Bar;
        setPredicate(inst);

        inst.d.addressMode = ir::PTXOperand::Immediate;
        inst.d.imm_uint = 0;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
    }
    
    void CToPTXTranslator::generateStaticAttributes(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, std::string callName)
    {
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = callName;
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier; 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_uint = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
    }
    
    void CToPTXTranslator::generateComputeBaseAddress(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, std::string callName)
    {
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = callName;
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier; 
        registers.push_back(inst.d.identifier);
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_uint = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
    
        inst.opcode = ir::PTXInstruction::And;
        inst.type = ir::PTXOperand::b64;
        inst.d.identifier = callName;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = callName;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_int = ~0x3f;

	    specialRegisterMap["andResult"] = callName;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);    
    
    }
    
    void CToPTXTranslator::generateLeastActiveThreadInWarp(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {

        //mov.u32 %lmask, %lanemask_lt;
        inst.opcode = ir::PTXInstruction::Mov;
        inst.type = inst.d.type = ir::PTXOperand::u32; 
                 
        inst.d.identifier = "lmask";
        registers.push_back(inst.d.identifier); 
                     
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a = ir::PTXOperand(ir::PTXOperand::lanemask_lt, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        //mov.pred %p0, 1;
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string p0 = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.imm_uint = 0;
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt); 

        //vote.ballot.b32 %bitmask, %p0;
	    inst.opcode = ir::PTXInstruction::Vote;
        inst.vote = ir::PTXInstruction::Ballot;
        inst.type = ir::PTXOperand::b32;
        
        inst.d.type = ir::PTXOperand::b32;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = "bitmask";
	    specialRegisterMap["bitmask"] = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = ir::PTXOperand::pred;
        inst.a.identifier = p0;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.vote = ir::PTXInstruction::VoteMode_Invalid;
        
	    //and.b32 %rb0, %bitmask, %lmask;
	    inst.opcode = ir::PTXInstruction::And;
        inst.type = ir::PTXOperand::b32;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string rb0 = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = ir::PTXOperand::b32;
        inst.a.identifier = specialRegisterMap["bitmask"];
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = "lmask";
        inst.b.type = type;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);  
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = rb0;       
    }

    void CToPTXTranslator::generateActiveThreadCount(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, 
        virtual_insn *insn)
    {
        if(specialRegisterMap["bitmask"].empty())
        {
            //mov.pred %p0, 1;
            inst.opcode = ir::PTXInstruction::SetP;
                
            inst.d.type = ir::PTXOperand::pred;
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
            std::string p0 = inst.d.identifier;
            registers.push_back(inst.d.identifier);
            
            inst.comparisonOperator = ir::PTXInstruction::Eq;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Immediate;
            inst.a.imm_uint = 0;
            inst.b.type = type;
            inst.b.addressMode = ir::PTXOperand::Immediate;
            inst.b.imm_uint = 0;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt); 

            //vote.ballot.b32 %bitmask, %p0;
	        inst.opcode = ir::PTXInstruction::Vote;
            inst.vote = ir::PTXInstruction::Ballot;
            inst.type = ir::PTXOperand::b32;
            
            inst.d.type = ir::PTXOperand::b32;
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = "bitmask";
	        specialRegisterMap["bitmask"] = inst.d.identifier;
            registers.push_back(inst.d.identifier);
            inst.a.addressMode = ir::PTXOperand::Register;
            inst.a.type = ir::PTXOperand::pred;
            inst.a.identifier = p0;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);
        }

        inst.vote = ir::PTXInstruction::VoteMode_Invalid;
        
        inst.opcode = ir::PTXInstruction::Popc;
        inst.type = inst.a.type = ir::PTXOperand::b32;
        inst.d.type = ir::PTXOperand::u32;
        inst.d.addressMode = inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = specialRegisterMap["bitmask"];

        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string popcResult = inst.d.identifier;
        registers.push_back(inst.d.identifier);  

        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Cvt;
        inst.type = inst.d.type = type;
        inst.a.type = ir::PTXOperand::u32;
        inst.a.identifier = popcResult;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);  

        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);

        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;  
    }

    void CToPTXTranslator::generateUniqueElementCount(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, 
        virtual_insn *insn, std::string callName, unsigned long uInput)
    {
    
        parameterMap[callName] = uInput;

        inst.opcode = ir::PTXInstruction::And;
        inst.type = ir::PTXOperand::b64;
        inst.d.type = ir::PTXOperand::b64;
        inst.b.type = ir::PTXOperand::b64;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string andResult = inst.d.identifier;
        registers.push_back(inst.d.identifier);  
        
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = specialRegisterMap["blockThreadId"];
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_int = ~0x1f;

        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);    

        inst.opcode = ir::PTXInstruction::Mad;
        inst.modifier = ir::PTXInstruction::lo;
        inst.type = type;
        inst.d.type = type;
        inst.a.type = type;
        inst.b.type = type;

        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string madResult = inst.d.identifier;
        registers.push_back(inst.d.identifier);  
        inst.a.identifier = andResult;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = sizeof(size_t);
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.identifier = sharedMemReg;
        inst.c.type = type;

        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.a.addressMode = inst.b.addressMode = inst.c.addressMode = ir::PTXOperand::Invalid;
        inst.a.identifier.clear();
        inst.b.identifier.clear();
        inst.c.identifier.clear();

        ir::PTXStatement reductionBuffer = ir::PTXStatement(ir::PTXStatement::Param);
        reductionBuffer.name = "reductionBuffer";
        reductionBuffer.type = type;
        reductionBuffer.array.stride = ir::PTXStatement::ArrayStrideVector(1, 1);
        statements.push_back(reductionBuffer);

        ir::PTXStatement uniqueCount = ir::PTXStatement(ir::PTXStatement::Param);
        uniqueCount.name = "uniqueCount";
        uniqueCount.type = type;
        statements.push_back(uniqueCount);

        ir::PTXStatement bitMask = ir::PTXStatement(ir::PTXStatement::Param);
        bitMask.name = "bitMask";
        bitMask.type = ir::PTXOperand::b32;
        statements.push_back(bitMask);

        inst.type = ir::PTXOperand::b32;
        inst.opcode = ir::PTXInstruction::St;
        inst.addressSpace = ir::PTXInstruction::Param;

        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = ir::PTXOperand::b32;

        inst.a.identifier = specialRegisterMap["bitmask"];
        inst.d.identifier = bitMask.name;
        inst.d.addressMode = ir::PTXOperand::Address;
        inst.d.offset = 0;

        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.type = type;
        inst.opcode = ir::PTXInstruction::St;
        inst.addressSpace = ir::PTXInstruction::Param;

        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;

        inst.a.identifier = madResult;
        inst.d.identifier = reductionBuffer.name;
        inst.d.addressMode = ir::PTXOperand::Address;
        inst.d.offset = 0;

        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Call;
        inst.tailCall = false;
        inst.a.addressMode = ir::PTXOperand::Label;
        inst.a.identifier = callName;

        inst.b.addressMode = ir::PTXOperand::ArgumentList;
        ir::PTXOperand input1 = ir::PTXOperand(ir::PTXOperand::Register, reductionBuffer.name);
        input1.type = type;
        inst.b.array.push_back(input1);
        ir::PTXOperand input2 = ir::PTXOperand(ir::PTXOperand::Register, bitMask.name);
        input2.type = ir::PTXOperand::b32;
        inst.b.array.push_back(input2);

        inst.d.addressMode = ir::PTXOperand::ArgumentList;
        ir::PTXOperand retVal = ir::PTXOperand(ir::PTXOperand::Register, uniqueCount.name);
        retVal.type = type;
        inst.d.array.push_back(retVal);

        setPredicate(inst);       
        stmt.instruction = inst;
        statements.push_back(stmt);    

        inst.opcode = ir::PTXInstruction::Ld;
        inst.addressSpace = ir::PTXInstruction::Param;

        inst.d.identifier = madResult;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;

        inst.a.identifier = uniqueCount.name;
        inst.a.addressMode = ir::PTXOperand::Address;
        inst.a.offset = 0;

        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);

        specialRegisterMap["uniqueElementCount"] = inst.d.identifier;

        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;  
    
    }
    
    void CToPTXTranslator::generateDivergentWarp(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, 
        virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Vote;
        inst.vote = ir::PTXInstruction::Uni;
        inst.type = inst.d.type = inst.a.type = ir::PTXOperand::pred;
        inst.d.addressMode = inst.a.addressMode = ir::PTXOperand::Register;

        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string pred = inst.d.identifier;
        registers.push_back(inst.d.identifier);

        inst.a.identifier = pred;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);
	    
	    inst.vote = ir::PTXInstruction::VoteMode_Invalid;
	    
	    inst.opcode = ir::PTXInstruction::SelP;
        inst.type = inst.d.type = inst.a.type = inst.b.type = type;
      
        inst.d.addressMode = inst.c.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);

        inst.a.addressMode = inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.a.imm_uint = 0;
        inst.b.imm_uint = 1;

        inst.c.type = ir::PTXOperand::pred;
        inst.c.identifier = pred;

        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);

        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;  
    }
    
    void CToPTXTranslator::generateAtomicIncrement(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, unsigned int uInput)
    {
        inst.opcode = ir::PTXInstruction::Atom;
        inst.atomicOperation = ir::PTXInstruction::AtomicAdd;
            
        inst.addressSpace = ir::PTXInstruction::Global; 
        inst.a.addressMode = ir::PTXOperand::Indirect;
        inst.a.type = type;
        inst.a.identifier = baseReg;
        inst.a.offset = uInput * sizeof(size_t);
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = 1;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;  
    
    }
    
    void CToPTXTranslator::generateAtomicAdd(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, std::string regInput)
    {
        inst.opcode = ir::PTXInstruction::Atom;
        inst.atomicOperation = ir::PTXInstruction::AtomicAdd;
            
        inst.addressSpace = ir::PTXInstruction::Global; 
        inst.a.addressMode = ir::PTXOperand::Indirect;
        inst.a.type = type;
        inst.a.identifier = baseReg;
        inst.a.offset = 0;
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = registerMap[regInput];
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;  
    
    }
     
    int CToPTXTranslator::translate(dill_stream c, void *info_ptr, void *i)
    {
        ir::PTXOperand::DataType type = (sizeof(size_t) == 8 ? ir::PTXOperand::u64: ir::PTXOperand::u32);
        
        virtual_insn *insn = (virtual_insn *)i;
        
        ir::PTXInstruction inst;
        ir::PTXStatement stmt;
        
        stmt.directive = ir::PTXStatement::Instr;
        
        inst.type = type;
        
        switch(insn->class_code) {
        case iclass_lea:
        {
            std::string baseAddressId = boost::lexical_cast<std::string>(insn->opnds.a3.src1);
            
            if(baseAddressId == "103")
            {
                ir::PTXStatement shared(ir::PTXStatement::Shared);
                shared.name = baseAddress() + baseAddressId;
                shared.array.stride = ir::PTXStatement::ArrayStrideVector(1, 512);
                shared.alignment = 64;
                shared.type = type;
                //shared.attribute = ir::PTXStatement::Extern;

                statements.push_back(shared);
                
                inst.opcode = ir::PTXInstruction::Mov;
                 
                inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
                registers.push_back(inst.d.identifier);
                sharedMemReg = inst.d.identifier;
                
                specialRegisterMap["sharedMemReg"] = sharedMemReg;
                     
                inst.d.type = type;          
                inst.d.addressMode = ir::PTXOperand::Register;
                inst.a.identifier = shared.name;
                inst.a.type = type;
                inst.a.addressMode = ir::PTXOperand::Address;
                
                setPredicate(inst);
                stmt.instruction = inst;
                statements.push_back(stmt);    
                
                break; 
            
            }
           
            ir::PTXStatement global(ir::PTXStatement::Global);
            global.name = baseAddress() + baseAddressId;
            global.type = type;
            globals.push_back(global);
            
            inst.opcode = ir::PTXInstruction::Mov;
                 
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            registers.push_back(inst.d.identifier);
                 
            inst.d.type = type;          
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.identifier = global.name;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Address;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);     

            inst.opcode = ir::PTXInstruction::Ld;
            
            inst.addressSpace = ir::PTXInstruction::Global; 
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.type = type;
            
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            inst.a.identifier = statements.back().instruction.d.identifier;
            inst.a.addressMode = ir::PTXOperand::Indirect;
            
            baseReg = inst.d.identifier;
            registers.push_back(inst.d.identifier);
            specialRegisterMap["baseReg"] = baseReg;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);
            
            break;
        }
        
        case iclass_set:
        {
            inst.opcode = ir::PTXInstruction::Mov;
            inst.d.type = type;
       
            inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            registers.push_back(inst.d.identifier);
            
            registerMap[(REG + boost::lexical_cast<std::string>(insn->opnds.a3i.dest))] = inst.d.identifier;
                      
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Immediate;
            inst.a.imm_uint = insn->opnds.a3i.u.imm;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);     

            break;
        }
        case iclass_mov:
        case iclass_convert:
        {
            std::string src1 = (REG + boost::lexical_cast<std::string>(insn->opnds.a2.src));
            std::map<std::string,std::string>::iterator it = registerMap.find(src1);
            if(it != registerMap.end()) {
                registerMap[(REG + boost::lexical_cast<std::string>(insn->opnds.a2.dest))] = it->second;
                if(insn->class_code == iclass_mov)
                {
                    registerMap.erase(src1);
                }
            }

            break;
        }
        case iclass_arith3:
        case iclass_arith3i:
        {
            std::string src1, src2, dst;
            
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.a.addressMode = ir::PTXOperand::Register;
            inst.b.addressMode = ir::PTXOperand::Register;
            
            inst.d.type = type;
            inst.a.type = type;
            inst.b.type = type;
        
            if(insn->class_code == iclass_arith3){
                src1 = REG + boost::lexical_cast<std::string>(insn->opnds.a3.src1);
                src2 = REG + boost::lexical_cast<std::string>(insn->opnds.a3.src2);
                dst = REG + boost::lexical_cast<std::string>(insn->opnds.a3.dest);
            }
            else {
                inst.b.addressMode = ir::PTXOperand::Immediate;
                src1 = REG + boost::lexical_cast<std::string>(insn->opnds.a3i.src);
                dst = REG + boost::lexical_cast<std::string>(insn->opnds.a3i.dest);
                inst.b.imm_uint = insn->opnds.a3i.u.imm;
            }
        
            if(registerMap[dst].empty())
            {
                inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
            }
            else {
                inst.d.identifier = registerMap[dst];
            }
            registers.push_back(inst.d.identifier);
            
            inst.a.identifier = registerMap[src1];	
            inst.b.identifier = registerMap[src2];	
            
            registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.a3.dest)] = inst.d.identifier;
            
            if(arith3_name[(unsigned int)insn->insn_code].find("add") != std::string::npos){

                inst.opcode = ir::PTXInstruction::Add;
            }
            else if(arith3_name[(unsigned int)insn->insn_code].find("sub") != std::string::npos){
                
                inst.opcode = ir::PTXInstruction::Sub;
            }
            else if(arith3_name[(unsigned int)insn->insn_code].find("mul") != std::string::npos){
                
                inst.opcode = ir::PTXInstruction::Mul;
                inst.modifier = ir::PTXInstruction::lo;
            }
            else if(arith3_name[(unsigned int)insn->insn_code].find("div") != std::string::npos){
                
                inst.opcode = ir::PTXInstruction::Div;
                inst.modifier = ir::PTXInstruction::lo;
            }
            else if(arith3_name[(unsigned int)insn->insn_code].find("rsh") != std::string::npos){
            
                inst.opcode = ir::PTXInstruction::Shr;
            }
            else if(arith3_name[(unsigned int)insn->insn_code].find("lsh") != std::string::npos){
                
                inst.opcode = ir::PTXInstruction::Shl;
            }
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);     
            
            break;
        }
        case iclass_call:
        {
            std::string call_name = insn->opnds.calli.xfer_name;
            if(!call_name.empty() && functionCalls.find(call_name) != functionCalls.end()){
                        
                       
                switch(functionCalls[call_name]) {
                    case blockIdSymbol:
                    {  
                        generateBlockId(inst, stmt, type, insn);
                    }
                    break;                  
                    case smIdSymbol:
                    {    
                        generateSMId(inst, stmt, type, insn);
                    }            
                    break;
                    case warpIdSymbol: 
                    {
                        generateWarpId(inst, stmt, type, insn);
                    }
                    break;
                    case warpCountSymbol: 
                    {
                        generateWarpCount(inst, stmt, type, insn);
                    }
                    break;
                    case clockCounterSymbol:
                    {   
                        generateClockCounter(inst, stmt, type, insn);    
                    }
                    break;
                    case syncThreadsSymbol:
                    {
                        
                        generateSyncThreads(inst, stmt);
                    }
                    break;
                    case threadIdxXSymbol:
                    {
                        generateThreadIndexX(inst, stmt, type, insn);      
                    }
                    break;
                    case blockDimSymbol:
                    {
                        generateBlockDim(inst, stmt, type, insn);
                    }
                    break;
                    case gridDimSymbol:
                    {
                        generateGridDim(inst, stmt, type, insn);
                    }
                    break;
                    case globalThreadIdSymbol: 
                    {
                        generateGlobalThreadId(inst, stmt, type, insn);
                    
                    }
                    break;
                    case blockThreadIdSymbol: 
                    {
                        generateBlockThreadId(inst, stmt, type, insn);
                    
                    }
                    break;
                    case computeBaseAddressSymbol:
                    {
                        generateComputeBaseAddress(inst, stmt, type, insn, call_name);
                    }
                    break;
                    case leastActiveThreadInWarpSymbol:
                    {
                        generateLeastActiveThreadInWarp(inst, stmt, type, insn);
                    }
                    break;
                    case uniqueElementCountSymbol:
                    {
                        generateUniqueElementCount(inst, stmt, type, insn, call_name, uInput);
                    }
                    break;
                     case activeThreadCountSymbol:
                    {
                        generateActiveThreadCount(inst, stmt, type, insn);
                    }
                    break;
                    case atomicIncrementSymbol:
                    {
                        generateAtomicIncrement(inst, stmt, type, insn, uInput);
                    }
                    break;
                    case atomicAddSymbol:
                    {
                        generateAtomicAdd(inst, stmt, type, insn, regInput);
                    }
                    break;
                    case divergentWarpSymbol:
                    {
                        generateDivergentWarp(inst, stmt, type, insn);
                    }
                    break;
                    case basicBlockCountSymbol:
                    case basicBlockIdSymbol:
                    case basicBlockInstCountSymbol: 
                    case basicBlockExecInstCountSymbol:
                    case instructionIdSymbol:
                    case instructionCountSymbol:
                    case getPredicateValueSymbol:
                    case basicBlockPredInstCountSymbol:    
                    {
                        generateStaticAttributes(inst, stmt, type, insn, call_name);
                    }
                    break;
                    default:
                    break;
                }
            }
        
            break;
        }
        case iclass_branch:
        case iclass_branchi:
        {
            inst.opcode = ir::PTXInstruction::SetP;
            
            inst.d.type = ir::PTXOperand::pred;
            inst.d.addressMode = ir::PTXOperand::Register;
            std::string pred = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
            inst.d.identifier = pred;
            registers.push_back(inst.d.identifier);
            
            inst.comparisonOperator = ir::PTXInstruction::Eq;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Register;
            inst.b.type = type;
            inst.b.addressMode = ir::PTXOperand::Register;
            
            std::string label;
            int br_op = insn->insn_code;
	        struct branch_table *t = &c->p->branch_table;

            if(insn->class_code == iclass_branch)
            {
                inst.a.identifier = registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.br.src1)];
                inst.b.identifier = registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.br.src2)];

                if (t->label_name[insn->opnds.br.label] != NULL) {
                    label = t->label_name[insn->opnds.br.label];
	            }
	            else {
	                label = "L" + boost::lexical_cast<std::string>(insn->opnds.br.label);
	            }
            }   
            else
            {
                inst.a.identifier = registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.bri.src)];
                inst.b.addressMode = ir::PTXOperand::Immediate;                
                inst.b.imm_uint = insn->opnds.bri.imm_l;

                if (t->label_name[insn->opnds.bri.label] != NULL) {
                    label = t->label_name[insn->opnds.bri.label];
	            }
	            else {
	                label = "L" + boost::lexical_cast<std::string>(insn->opnds.bri.label);
	            }
            }         

	        PredicateInfo predicateInfo;
	        predicateInfo.id = inst.d.identifier;
	        
	        predicateInfo.branchLabel = label;
	        if(br_op >= 55 && br_op < 66){
	            predicateInfo.condition = PredicateInfo::NOT_TAKEN;
	            predicateInfo.set = true;
	        }
	        else if(br_op >= 0 && br_op < 11){
	            predicateInfo.condition = PredicateInfo::TAKEN;
	            inst.type = ir::PTXOperand::u32;
		        inst.b.addressMode = ir::PTXOperand::Immediate;
		        inst.b.imm_uint = 0;
	            predicateInfo.set = true;
	        }
            else if(br_op >= 33 && br_op < 44){
                predicateInfo.condition = PredicateInfo::TAKEN;
                inst.comparisonOperator = ir::PTXInstruction::Gt; 
                predicateInfo.set = true;
            }
	       
	        if(label == "loop end")
	        {
	            ir::PTXStatement loop(ir::PTXStatement::Label);
                loop.name = LOOP;
                statements.push_back(loop);
                blockLabels.push_back(LOOP);
	        }
	       
	        setPredicate(inst);
	        
	        /* if a predicate condition is set on the SetP instruction, 
	            initialize the destination predicate to 0 to make sure it does not have an undefined value for some threads */
	        if(inst.pg.condition == ir::PTXOperand::Pred || inst.pg.condition == ir::PTXOperand::InvPred)
	        {
	            ir::PTXInstruction initPred = ir::PTXInstruction(ir::PTXInstruction::SetP);
	            inst.comparisonOperator = ir::PTXInstruction::Eq;
	            initPred.type = type;
	            initPred.d.addressMode = ir::PTXOperand::Register;
	            initPred.d.type = ir::PTXOperand::pred;
	            initPred.a.type = initPred.b.type = type;
	            initPred.a.addressMode = initPred.b.addressMode = ir::PTXOperand::Immediate;
	            initPred.a.imm_uint = 1;
	            initPred.b.imm_uint = 0;
	            initPred.d.identifier = pred;
	            initPred.pg.condition = ir::PTXOperand::PT;
	            stmt.instruction = initPred;
	            statements.push_back(stmt);
	        }
	        
	        stmt.instruction = inst;
	        statements.push_back(stmt);
	          
	        predicateInfo.targetId = targetId;
	        predicateList.push_back(predicateInfo);  
	        
	        if(label == "loop end")
	        {
	            inst.opcode = ir::PTXInstruction::Bra;
                inst.d.addressMode = ir::PTXOperand::Label;
                inst.d.identifier = LOOP_END;
                inst.pg.condition = ir::PTXOperand::Pred;
                inst.pg.identifier = predicateInfo.id;
                
                setPredicate(inst);
                stmt.instruction = inst;
                statements.push_back(stmt);     
	        
	        }
	        
	        break;
        }
       
        case iclass_loadstore:
        case iclass_loadstorei:
        {
            std::string src1, dst;
        
            if(insn->class_code == iclass_loadstorei)
            {
                src1 = REG + boost::lexical_cast<std::string>(insn->opnds.a3i.src);
                dst = REG + boost::lexical_cast<std::string>(insn->opnds.a3i.dest);
                inst.d.offset = insn->opnds.a3i.u.imm;
            }
            
            inst.type = type;
            inst.d.type = type;
            inst.a.type = type;
            
	        int store = (insn->insn_code & 0x10) && 0x10;
	        if(store) {
	            
	            inst.opcode = ir::PTXInstruction::St;
	            
                inst.d.identifier = registerMap[src1];		
                inst.a.identifier = registerMap[dst];	
                
                inst.d.addressMode = ir::PTXOperand::Indirect;
                inst.a.addressMode = ir::PTXOperand::Register;
	        }
	        else {
	            
	            inst.opcode = ir::PTXInstruction::Ld;
	            
                inst.a.identifier = registerMap[src1];		
                inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
                registers.push_back(inst.d.identifier);
                
                registerMap[dst] = inst.d.identifier;
                
                inst.a.addressMode = ir::PTXOperand::Indirect;
                inst.d.addressMode = ir::PTXOperand::Register;
	        }
	           
	        ir::PTXInstruction prev = statements.back().instruction;
	        
            if(prev.opcode == ir::PTXInstruction::Add
                && (prev.d.identifier == inst.d.identifier || prev.d.identifier == inst.a.identifier)) {
            
                memoryType = prev.b.imm_uint;
                
                for(ir::PTXKernel::PTXStatementVector::iterator s = statements.begin(); s != statements.end(); ++s)
                { 
                    if(s->instruction.opcode == ir::PTXInstruction::Mov && (s->instruction.d.identifier == prev.d.identifier || 
                        s->instruction.d.identifier == prev.a.identifier || s->instruction.d.identifier == prev.b.identifier))
                        {
                            statements.erase(s);
                            break;
                        }
                }
            
                prev.b.addressMode = ir::PTXOperand::Register;
                
                if(memoryType == SHARED_MEM)
                {
                    prev.b.identifier = sharedMemReg;
                }
                else
                {    
                    prev.b.identifier = baseReg;
                }
                
                statements.pop_back();
                stmt.instruction = prev;
                statements.push_back(stmt);
            }
            
            if(prev.opcode == ir::PTXInstruction::Mov
                && (prev.d.identifier == inst.d.identifier || prev.d.identifier == inst.a.identifier)) {
            
                memoryType = prev.b.imm_uint;
                    
                for(ir::PTXKernel::PTXStatementVector::iterator s = statements.begin(); s != statements.end(); ++s)
                { 
                    if(s->instruction.opcode == ir::PTXInstruction::Mov && (s->instruction.d.identifier == prev.d.identifier || 
                        s->instruction.d.identifier == prev.a.identifier || s->instruction.d.identifier == prev.b.identifier))
                        {
                            statements.erase(s);
                            break;
                        }
                }
                
                if(inst.opcode == ir::PTXInstruction::Ld)
                {
                    if(memoryType == SHARED_MEM)
                    {
                        inst.a.identifier = sharedMemReg;
                    }
                    else
                    {
                        inst.a.identifier = baseReg;
                    }
                }
                else
                {
                    if(memoryType == SHARED_MEM)
                    {
                        inst.d.identifier = sharedMemReg;
                    }
                    else
                    {
                        inst.d.identifier = baseReg;
                    }
                
                }
            }
            
            if(memoryType == SHARED_MEM)
                inst.addressSpace = ir::PTXInstruction::Shared;
            else
                inst.addressSpace = ir::PTXInstruction::Global;
               
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);   
	           
            break;
        }
        case iclass_jump_to_label:
        {
            struct branch_table *t = &c->p->branch_table;
            std::string label = "L" + boost::lexical_cast<std::string>(insn->opnds.br.label); 
            
	        if (t->label_name[insn->opnds.br.label] != NULL) {
	            label = t->label_name[insn->opnds.br.label];
	        }
	        
	        inst.opcode = ir::PTXInstruction::Bra;
            inst.d.addressMode = ir::PTXOperand::Label;
            
            if(label == "loop begin")
                inst.d.identifier = LOOP;
            else 
                inst.d.identifier = label;
            
            setPredicate(inst);
            stmt.instruction = inst;
            statements.push_back(stmt);     
	        
            break;
        }
        case iclass_mark_label:
        {
            std::string label;
            
            struct branch_table *t = &c->p->branch_table;
            if (t->label_name[insn->opnds.label.label] != NULL) {
	            label = t->label_name[insn->opnds.label.label];
	        }
	        else {
	            label = "L" + boost::lexical_cast<std::string>(insn->opnds.label.label);
	        }

            if(label == "loop begin")
            {
                ir::PTXInstruction prev = statements.back().instruction;
                statements.pop_back();
            
                ir::PTXStatement loopBegin(ir::PTXStatement::Label);
                loopBegin.name = LOOP_BEGIN;
                statements.push_back(loopBegin);
                blockLabels.push_back(LOOP_BEGIN);
                
                stmt.instruction = prev;
                statements.push_back(stmt);
            }
            else if(label == "loop end")
            {
                ir::PTXStatement loopEnd(ir::PTXStatement::Label);
                loopEnd.name = LOOP_END;
                statements.push_back(loopEnd);
                blockLabels.push_back(LOOP_END);
            }

            for(StringVector::const_iterator specifier = specifierList.begin(); 
                specifier != specifierList.end(); ++specifier)
            {
                if(label == *specifier)
                    specifiers.push_back(label);
            }
            
            for(StringVector::const_iterator target = targetList.begin(); 
                target != targetList.end(); ++target)
            {
                if(label == *target)
                { 
                    targets.push_back(label);
                    targetId = *target;
                }
            }
            
            stmt.directive = ir::PTXStatement::Label;
            stmt.name = label;
            statements.push_back(stmt);
            
            for (PredicateList::iterator pred = predicateList.begin(); 
            pred != predicateList.end(); ++pred) {
            
                if(pred->branchLabel == stmt.name){ 
                    if(pred->condition == PredicateInfo::TAKEN){
                        pred->set = true;
                    }
                    else {
                        pred->set = false;
                    }
                }
            }
                
	        break;
        }
        
        case iclass_pushi:
        {
            int typ = insn->insn_code & 0xf;
            if(typ == 7)
                uInput = insn->opnds.a3i.u.imm;
            /* pushing pointer type */
            else if(typ == 8) 
                memoryType = insn->opnds.a3i.u.imm;

                
            break;
        }
        case iclass_push:
        {
            int typ = insn->insn_code & 0xf;
            if(typ == 7)
                regInput = REG + boost::lexical_cast<std::string>(insn->opnds.a1.src);

            break;
        }
        case iclass_pushf:
        case iclass_nop:
	        break;
        }
        
        return sizeof(*insn);
    }
    
    CToPTXData CToPTXTranslator::generate(std::string resource) {
    
        
        std::string code;
        std::string line;
        std::ifstream codeFile( resource );

        if(codeFile.is_open()){
            while(codeFile.good()){
                getline(codeFile, line);
                code.append(line + "\n");
            }
            codeFile.close();
        }
        else {
            throw hydrazine::Exception( "No code specification found for this instrumentation!");
        }
        
	    cod_parse_context context;
	    cod_exec_context ec;
	
	    static char extern_string[] =  "unsigned long clockCounter();\
                                        unsigned long globalThreadId();\
                                        unsigned long blockThreadId();\
                                        unsigned long threadIndexX();\
                                        unsigned long threadIndexY();\
                                        unsigned long threadIndexZ();\
                                        unsigned long blockId();\
                                        unsigned long blockIndexX();\
                                        unsigned long blockIndexY();\
                                        unsigned long blockIndexZ();\
                                        unsigned long blockDim();\
                                        unsigned long blockDimX();\
                                        unsigned long blockDimY();\
                                        unsigned long blockDimZ();\
                                        unsigned long gridDim();\
                                        unsigned long gridDimX();\
                                        unsigned long gridDimY();\
                                        unsigned long gridDimZ();\
                                        unsigned long gridId();\
                                        unsigned long smId();\
                                        void syncThreads();\
                                        unsigned long basicBlockCount();\
                                        unsigned long basicBlockId();\
                                        unsigned long basicBlockInstructionCount();\
                                        unsigned long basicBlockExecutedInstructionCount();\
                                        unsigned long basicBlockPredicatedInstructionCount();\
                                        unsigned long instructionId();\
                                        unsigned long instructionCount();\
                                        unsigned long warpCount();\
                                        unsigned long warpId();\
                                        unsigned long getPredicateValue();\
                                        unsigned long leastActiveThreadInWarp();\
                                        unsigned long computeBaseAddress();\
                                        void atomicIncrement(unsigned long *memBuffer, unsigned long offset);\
                                        void atomicAdd(unsigned long *memBuffer, unsigned long offset, unsigned long toAdd);\
                                        unsigned long uniqueElementCount(unsigned long *memBuffer, unsigned long overHalfWarp);\
                                        unsigned long activeThreadCount();\
                                        unsigned long divergentWarp();\
                                        unsigned long globalMem[1];\
                                        unsigned long sharedMem[1];";
                        
	    static cod_extern_entry externs[] = 
	    {
            {(char *)"clockCounter", (void*)(unsigned long)(*clockCounter)},
            {(char *)"globalThreadId", (void*)(unsigned long)(*globalThreadId)},
            {(char *)"blockThreadId", (void*)(unsigned long)(*blockThreadId)},
            {(char *)"threadIndexX", (void*)(unsigned long)(*threadIndexX)},
            {(char *)"threadIndexY", (void*)(unsigned long)(*threadIndexY)},
            {(char *)"threadIndexZ", (void*)(unsigned long)(*threadIndexZ)},
            {(char *)"blockId", (void*)(unsigned long)(*blockId)},
            {(char *)"blockIndexX", (void*)(unsigned long)(*blockIndexX)},
            {(char *)"blockIndexY", (void*)(unsigned long)(*blockIndexY)},
            {(char *)"blockIndexZ", (void*)(unsigned long)(*blockIndexZ)},
            {(char *)"blockDim", (void*)(unsigned long)(*blockDim)},
            {(char *)"blockDimX", (void*)(unsigned long)(*blockDimX)},
            {(char *)"blockDimY", (void*)(unsigned long)(*blockDimY)},
            {(char *)"blockDimZ", (void*)(unsigned long)(*blockDimZ)},
            {(char *)"gridDim", (void*)(unsigned long)(*gridDim)},
            {(char *)"gridDimX", (void*)(unsigned long)(*gridDimX)},
            {(char *)"gridDimY", (void*)(unsigned long)(*gridDimY)},
            {(char *)"gridDimZ", (void*)(unsigned long)(*gridDimZ)},
            {(char *)"gridId", (void*)(unsigned long)(*gridId)},
            {(char *)"smId", (void*)(unsigned long)(*smId)},
            {(char *)"syncThreads", (void *)(*syncThreads)},
            {(char *)"basicBlockCount", (void*)(unsigned long)(*basicBlockCount)},            
            {(char *)"basicBlockId", (void*)(unsigned long)(*basicBlockId)},
            {(char *)"basicBlockInstructionCount", (void*)(unsigned long)(*basicBlockInstructionCount)},
            {(char *)"basicBlockExecutedInstructionCount", (void*)(unsigned long)(*basicBlockExecutedInstructionCount)},
            {(char *)"basicBlockPredicatedInstructionCount", (void*)(unsigned long)(*basicBlockPredicatedInstructionCount)},
            {(char *)"instructionId", (void*)(unsigned long)(*instructionId)},
            {(char *)"instructionCount", (void*)(unsigned long)(*instructionCount)},
            {(char *)"warpCount", (void*)(unsigned long)(*warpCount)},
            {(char *)"warpId", (void*)(unsigned long)(*warpId)},
            {(char *)"getPredicateValue", (void*)(unsigned long)(*getPredicateValue)},
            {(char *)"leastActiveThreadInWarp", (void*)(unsigned long)(*leastActiveThreadInWarp)},
            {(char *)"computeBaseAddress", (void*)(unsigned long)(*computeBaseAddress)},
            {(char *)"uniqueElementCount", (void*)(unsigned long)(*uniqueElementCount)},
            {(char *)"activeThreadCount", (void*)(unsigned long)(*activeThreadCount)},
            {(char *)"divergentWarp", (void*)(unsigned long)(*divergentWarp)},
            {(char *)"atomicIncrement", (void*)(*atomicIncrement)},
            {(char *)"atomicAdd", (void*)(*atomicAdd)},
            {(char *)"globalMem", (void *)GLOBAL_MEM},
            {(char *)"sharedMem", (void *)SHARED_MEM},
            {NULL, (void*)0}
	    };
     
     
        cod_code gen_code;
	
	    dill_set_foreign_cg(foreign_code_generator);

	    context = new_cod_parse_context();
	    cod_assoc_externs(context, externs);
	    cod_parse_for_context(extern_string, context);
	    gen_code = cod_code_gen((char *)code.c_str(), context);
	    ec = cod_create_exec_context(gen_code);
        
	    cod_exec_context_free(ec);
	    cod_code_free(gen_code);
	    cod_free_parse_context(context);
	    
	    CToPTXData data;
	    
	    data.statements = translator.statements;
	    data.globals = translator.globals;
	    data.registers = translator.registers;
	    data.blockLabels = translator.blockLabels;
	    data.specialRegisterMap = translator.specialRegisterMap;
	    data.parameterMap = translator.parameterMap;
	    
	    return data;
    }
    
    CToPTXTranslator::CToPTXTranslator()
        : maxRegister(0), maxPredicate(0), uInput(0)
    {
        memoryType = GLOBAL_MEM;
    
        functionCalls["clockCounter"] = clockCounterSymbol;
        functionCalls["globalThreadId"] = globalThreadIdSymbol;
        functionCalls["threadIndexX"] = threadIdxXSymbol;
        functionCalls["threadIndexY"] = threadIdxYSymbol;
        functionCalls["threadIndexZ"] = threadIdxZSymbol;
        functionCalls["blockThreadId"] = blockThreadIdSymbol;
        functionCalls["blockDimX"] = blockDimXSymbol;
        functionCalls["blockDimY"] = blockDimYSymbol;
        functionCalls["blockDimZ"] = blockDimZSymbol;
        functionCalls["blockDim"] = blockDimSymbol;
        functionCalls["blockIdxX"] = blockIdxXSymbol;
        functionCalls["blockIdxY"] = blockIdxYSymbol;
        functionCalls["blockIdxZ"] = blockIdxZSymbol;
        functionCalls["blockId"] = blockIdSymbol;
        functionCalls["gridDimX"] = gridDimXSymbol;
        functionCalls["gridDimY"] = gridDimYSymbol;
        functionCalls["gridDimZ"] = gridDimZSymbol;
        functionCalls["gridDim"] = gridDimSymbol;
        functionCalls["gridId"] = gridIdSymbol;
        functionCalls["smId"] = smIdSymbol;
        functionCalls["syncThreads"] = syncThreadsSymbol;
        functionCalls["basicBlockId"] = basicBlockIdSymbol;
        functionCalls["basicBlockCount"] = basicBlockCountSymbol;
        functionCalls["basicBlockInstructionCount"] = basicBlockInstCountSymbol;
        functionCalls["basicBlockExecutedInstructionCount"] = basicBlockExecInstCountSymbol;
        functionCalls["basicBlockPredicatedInstructionCount"] = basicBlockPredInstCountSymbol;
        functionCalls["instructionId"] = instructionIdSymbol;
        functionCalls["instructionCount"] = instructionCountSymbol;
        functionCalls["warpCount"] = warpCountSymbol;
        functionCalls["warpId"] = warpIdSymbol;
        functionCalls["getPredicateValue"] = getPredicateValueSymbol;        
        functionCalls["computeBaseAddress"] = computeBaseAddressSymbol;
        functionCalls["uniqueElementCount"] = uniqueElementCountSymbol;
        functionCalls["activeThreadCount"] = activeThreadCountSymbol;
        functionCalls["leastActiveThreadInWarp"] = leastActiveThreadInWarpSymbol;
        functionCalls["atomicIncrement"] = atomicIncrementSymbol;
        functionCalls["atomicAdd"] = atomicAddSymbol;
        functionCalls["divergentWarp"] = divergentWarpSymbol;
                
        specifierList = { ON_MEM_READ, ON_MEM_WRITE, ON_PREDICATED, ON_BRANCH, ON_CALL, ON_BARRIER, ON_ATOMIC, ON_ARITH_OP,
            GLOBAL, LOCAL, SHARED, CONST, PARAM, TEXTURE, TYPE_INT, TYPE_FP };
            
        targetList = { ENTER_KERNEL, EXIT_KERNEL, ENTER_BASIC_BLOCK, EXIT_BASIC_BLOCK, ON_INSTRUCTION };
    }
    
    PredicateInfo::PredicateInfo()
        :set(false), inv(false)
    {
    
    }
}

#endif
