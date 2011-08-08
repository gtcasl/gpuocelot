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
	        l = s->j->print_insn(s, &info, (void *)p);
	        printf("\n");
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

            if(pred->set && (instruction.opcode == ir::PTXInstruction::St || instruction.opcode == ir::PTXInstruction::Ld)){
                
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
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string ctaidX = inst.d.identifier;

        inst.d.type = type;
        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.vec = ir::PTXOperand::v1;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ctaId, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string ctaidY = inst.d.identifier;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::nctaId, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string nctaidX = inst.d.identifier;		 
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string ctaid = inst.d.identifier;		 
        
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
        
        registers.push_back(ctaidX);
        registers.push_back(ctaidY);
        registers.push_back(nctaidX);
        registers.push_back(ctaid);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = ctaid;
    
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
        
        stmt.instruction = inst;
        statements.push_back(stmt);        
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;    
    
    }
    
    void CToPTXTranslator::generateWarpId(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;
        setPredicate(inst);
        
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a = ir::PTXOperand(ir::PTXOperand::warpId);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.type = ir::PTXOperand::u32;
        
        stmt.instruction = inst;
        statements.push_back(stmt);        
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;    
    
    }
    
    void CToPTXTranslator::generateWarpCount(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;
        setPredicate(inst);
        
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a = ir::PTXOperand(ir::PTXOperand::nwarpId);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.type = ir::PTXOperand::u32;
        
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
        inst.a = ir::PTXOperand(ir::PTXOperand::clock64);
        inst.a.type = ir::PTXOperand::u64;

        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);	
        registers.push_back(inst.d.identifier);	      
                  
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);        
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;        
    }
    
    void CToPTXTranslator::generateThreadIndexX(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
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
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;    
    }
    
    void CToPTXTranslator::generateBlockDim(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        inst.opcode = ir::PTXInstruction::Cvt;  

        inst.d.addressMode = ir::PTXOperand::Register;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ntidX = inst.d.identifier;

        inst.d.type = type;
        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.vec = ir::PTXOperand::v1;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ntidY = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iz, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string ntidZ = inst.d.identifier;		 
        
        stmt.instruction = inst;
        statements.push_back(stmt);

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
        inst.a.identifier = ntidX;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = ntidY;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = ntid;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = ntidZ;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = ntid;
        
        specialRegisterMap["ntid"] = ntid;
        specialRegisterMap["ntidX"] = ntidX;
        specialRegisterMap["ntidY"] = ntidY;
        specialRegisterMap["ntidZ"] = ntidZ;
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
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string tidX = inst.d.identifier;

        inst.d.type = type;
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.addressMode = ir::PTXOperand::Special;
        inst.a.vec = ir::PTXOperand::v1;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string tidY = inst.d.identifier;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::tid, ir::PTXOperand::iz, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string tidZ = inst.d.identifier;		 
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::ix, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string ntidX = inst.d.identifier;		 
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.a = ir::PTXOperand(ir::PTXOperand::ntid, ir::PTXOperand::iy, ir::PTXOperand::u32);
        inst.a.vec = ir::PTXOperand::v1;       
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string ntidY = inst.d.identifier;		 
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);

        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string madTidYnTidXtidX = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = tidY;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = ntidX;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.type = type;
        inst.c.identifier = tidX;
         
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
        inst.a.identifier = tidZ;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = ntidX;
        
        stmt.instruction = inst;
        setPredicate(inst);
        statements.push_back(stmt);
        
        inst.d.identifier = mulTidZnTidXnTidY;
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = mulTidZnTidXnTidY;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = ntidY;
        
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
        
        registers.push_back(tidX);
        registers.push_back(tidY);
        registers.push_back(tidZ);
        registers.push_back(ntidX);
        registers.push_back(ntidY);
        registers.push_back(mulTidZnTidXnTidY);
        registers.push_back(madTidYnTidXtidX);
        registers.push_back(addResult);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = addResult;
    
    }
    
    void CToPTXTranslator::generatePredicateEvalWarpUniform(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, bool isUniform)
    {
    
        inst.opcode = ir::PTXInstruction::Vote;
        inst.vote = ir::PTXInstruction::Uni;
        inst.type = ir::PTXOperand::pred;
        
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        registers.push_back(inst.d.identifier);
        
        inst.a = inst.d;
        
        PredicateInfo predicateInfo;
        predicateInfo.id = inst.d.identifier;
        predicateInfo.set = false;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::SelP;
        inst.type = type;
        inst.d.type = type;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);  
        
        inst.a.type = inst.b.type = type;
        inst.a.addressMode = inst.b.addressMode = ir::PTXOperand::Immediate;
        if(isUniform)
        {
            inst.a.imm_int = 1;
            inst.b.imm_int = 0;
        }
        else
        {
            predicateInfo.inv = true;
            inst.a.imm_int = 0;
            inst.b.imm_int = 1;
        }
            
        inst.c.type = ir::PTXOperand::pred;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.identifier = predicateInfo.id;
        
        predicateList.push_back(predicateInfo);
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier;  
    }
    
    void CToPTXTranslator::generateSyncThreads(ir::PTXInstruction inst, ir::PTXStatement stmt)
    {
        inst.opcode = ir::PTXInstruction::Bar;
        setPredicate(inst);

        inst.d.addressMode = ir::PTXOperand::Immediate;
        inst.d.imm_int = 0;
        
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
        inst.a.imm_int = 0;
        
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
        inst.a.imm_int = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
    
        inst.opcode = ir::PTXInstruction::Not;
        inst.type = ir::PTXOperand::b64;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string notResult = inst.d.identifier;
        registers.push_back(inst.d.identifier);  
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.imm_uint = 63;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        inst.opcode = ir::PTXInstruction::And;
        inst.type = ir::PTXOperand::b64;
        inst.d.identifier = callName;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = callName;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = notResult;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);    
    
    }
    
    void CToPTXTranslator::generateLeastActiveThreadInWarp(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {

        ir::PTXStatement leastActiveThread(ir::PTXStatement::Label);
        leastActiveThread.name = LEAST_ACTIVE_THREAD;
        statements.push_back(leastActiveThread);
        
        generateSyncThreads(inst, stmt);
            
        //mov.u32 %lmask, %lanemask_lt;
        inst.opcode = ir::PTXInstruction::Mov;
        inst.type = ir::PTXOperand::u32;
                 
        inst.d.identifier = "lmask";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = ir::PTXOperand::u32;          
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
        inst.a.identifier = "bitmask";
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = "lmask";
        inst.b.type = ir::PTXOperand::u32;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);  
           
	    //setp.ne.b32 %p2, %rb0, 0;
	    inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string p2 = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Ne;
        inst.a.type = ir::PTXOperand::b32;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = rb0;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt); 
        
        PredicateInfo predicateInfo;
	    predicateInfo.id = inst.d.identifier;
	    predicateList.push_back(predicateInfo);  
	    
	    //mov.s32 %r0, %bitmask;
	    inst.opcode = ir::PTXInstruction::Mov;
            
        inst.d.type = ir::PTXOperand::s32;
        inst.type = ir::PTXOperand::s32;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string bitmask = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        inst.a.type = ir::PTXOperand::b32;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "bitmask";
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
	    
	    //@%p2 bra $exit;
	    inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = EXIT;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = p2;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
    
        blockLabels.push_back(LEAST_ACTIVE_THREAD);
    }
    
    void CToPTXTranslator::generateUniqueElementCount(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
        PredicateInfo predicateInfo;
    
        ir::PTXStatement beginReduction(ir::PTXStatement::Label);
        beginReduction.name = BEGIN_REDUCTION;
        statements.push_back(beginReduction);
    
        if(specialRegisterMap["ntid"].empty())
            generateBlockDim(inst, stmt, type, insn); 
        if(specialRegisterMap["nctaid"].empty())
            generateGridDim(inst, stmt, type, insn); 
    
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string sharedMemSize = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = specialRegisterMap["ntid"];
        
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = specialRegisterMap["nctaid"];
        
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        specialRegisterMap["sharedMemSize"] = sharedMemSize;
    
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "uniqueCount";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        generateStaticAttributes(inst, stmt, type, insn, INSTRUCTION_COUNT);
        
        inst.d.identifier = "k";
        registers.push_back(inst.d.identifier); 
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        inst.d.identifier = "i";
        registers.push_back(inst.d.identifier); 
        
        setPredicate(inst);
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
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string firstLoopPred = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "i";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = specialRegisterMap["sharedMemSize"];
        
        predicateInfo.id = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
          
        predicateList.push_back(predicateInfo);  
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = STORE_RESULTS;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = firstLoopPred;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        ir::PTXStatement firstLoop(ir::PTXStatement::Label);
        firstLoop.name = FIRST_LOOP;
        statements.push_back(firstLoop);
        
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "isUnique";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 1;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "j";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        ir::PTXStatement beginSecondLoop(ir::PTXStatement::Label);
        beginSecondLoop.name = BEGIN_SECOND_LOOP;
        statements.push_back(beginSecondLoop);
        
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string secondLoopPred = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "j";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = "uniqueCount";
        
        predicateInfo.id = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string i_offset = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "k";
        
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = specialRegisterMap["sharedMemSize"];
        
        inst.c.type = type;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.identifier = "i";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.c.addressMode = ir::PTXOperand::Invalid;
        
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string mul_i = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = i_offset;
        
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = sizeof(size_t);
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Add;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string add_i_to_base = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = mul_i;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = sharedMemReg;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Ld;
            
        inst.addressSpace = ir::PTXInstruction::Shared; 
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.a.addressMode = ir::PTXOperand::Indirect;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string rhs = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        inst.a.identifier = add_i_to_base;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = UPDATE_COUNTER;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = secondLoopPred;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        ir::PTXStatement secondLoop(ir::PTXStatement::Label);
        secondLoop.name = SECOND_LOOP;
        statements.push_back(secondLoop);
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string j_offset = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "k";
        
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = specialRegisterMap["sharedMemSize"];
        
        inst.c.type = type;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.identifier = "j";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.c.addressMode = ir::PTXOperand::Invalid;
        
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string mul_j = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = j_offset;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = sizeof(size_t);
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Add;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string add_j_to_base = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = mul_j;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = sharedMemReg;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Ld;
            
        inst.addressSpace = ir::PTXInstruction::Shared; 
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string lhs = inst.d.identifier;
        inst.a.identifier = add_j_to_base;
        inst.a.addressMode = ir::PTXOperand::Indirect;
        
        registers.push_back(inst.d.identifier);
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string isEqualPred = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = lhs;
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = rhs;
        
        predicateInfo.id = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "isUnique";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = isEqualPred;
        
        setPredicate(inst);
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
        setPredicate(inst);
           
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
        
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string isUniqueTrue = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "isUnique";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = 1;
        
        predicateInfo.id = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = isUniqueTrue;
        
        inst.opcode = ir::PTXInstruction::Add;     
        setPredicate(inst);
           
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
        setPredicate(inst);
           
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
        
        blockLabels.push_back(BEGIN_REDUCTION);
        blockLabels.push_back(BEGIN_INST_COUNT_LOOP);
        blockLabels.push_back(BEGIN_FIRST_LOOP);
        blockLabels.push_back(BEGIN_SECOND_LOOP);
        blockLabels.push_back(FIRST_LOOP);
        blockLabels.push_back(SECOND_LOOP);
        blockLabels.push_back(FIRST_LOOP_INC);
        blockLabels.push_back(SECOND_LOOP_INC);
        blockLabels.push_back(INST_COUNT_LOOP_INC);
        blockLabels.push_back(UPDATE_COUNTER);
        blockLabels.push_back(STORE_RESULTS);
    
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = "uniqueCount";  
    
    }
    
    void CToPTXTranslator::generateMemoryTransactionCount(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn, std::string callName)
    {
    
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = callName;
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = inst.d.identifier; 
        registers.push_back(inst.d.identifier);
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     

        ir::PTXStatement specifierLabel(ir::PTXStatement::Label);
        specifierLabel.name = ENTER_KERNEL;
        statements.push_back(specifierLabel);
        
        for(StringVector::const_iterator specifier = specifiers.begin(); specifier != specifiers.end();
            ++specifier)
        {
            specifierLabel.name = *specifier;
            statements.push_back(specifierLabel);
        }
        
        ir::PTXStatement shared(ir::PTXStatement::Shared);
        shared.name = "_Reduction";
        shared.array.stride = ir::PTXStatement::ArrayStrideVector(1, 4);
        shared.alignment = 64;
        shared.type = type;

        statements.push_back(shared);
        
        inst.opcode = ir::PTXInstruction::Mov;
         
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        sharedMemReg = inst.d.identifier;
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = shared.name;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Address;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        generateGlobalThreadId(inst, stmt, type, insn);
        
        if(specialRegisterMap["ntid"].empty())
            generateBlockDim(inst, stmt, type, insn); 
        if(specialRegisterMap["nctaid"].empty())
            generateGridDim(inst, stmt, type, insn); 

        specifierLabel.name = targets.back();
        statements.push_back(specifierLabel);

        for(StringVector::const_iterator specifier = specifiers.begin(); specifier != specifiers.end();
            ++specifier)
        {
            specifierLabel.name = *specifier;
            statements.push_back(specifierLabel);
        }
        
        inst.opcode = ir::PTXInstruction::Not;
        inst.type = ir::PTXOperand::b64;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string notResult = inst.d.identifier;
        registers.push_back(inst.d.identifier);  
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.imm_uint = 63;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        inst.opcode = ir::PTXInstruction::And;
        inst.type = ir::PTXOperand::b64;
        inst.d.identifier = callName;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = callName;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = notResult;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        inst.type = inst.d.type = inst.a.type = inst.b.type = type;
        
        //store in reduction shared buffer
        //Reduction[threads * instructionId() + globalThreadId()] = maskedAddress;
        
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string sharedMemSize = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = specialRegisterMap["ntid"];
        
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = specialRegisterMap["nctaid"];
        
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        specialRegisterMap["sharedMemSize"] = sharedMemSize;
       
        generateStaticAttributes(inst, stmt, type, insn, INSTRUCTION_ID);
       
        inst.opcode = ir::PTXInstruction::Mad;     
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string offset = inst.d.identifier;		 
        
        inst.c.type = type;
        inst.c.addressMode = ir::PTXOperand::Register;
        
        inst.a.identifier = sharedMemSize;
        inst.b.identifier = INSTRUCTION_ID;
        inst.c.identifier = specialRegisterMap["threadId"];
        
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string mul_offset = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = offset;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = sizeof(size_t);
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Add;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string computedAddress = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = sharedMemReg;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = mul_offset;
         
        stmt.instruction = inst;
        statements.push_back(stmt);

        
        inst.opcode = ir::PTXInstruction::St;
            
        inst.addressSpace = ir::PTXInstruction::Shared; 
        inst.d.addressMode = ir::PTXOperand::Indirect;
        inst.d.type = type;
        inst.d.identifier = computedAddress;
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = callName;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        specifierLabel.name = EXIT_KERNEL;
        statements.push_back(specifierLabel);
        
        for(StringVector::const_iterator specifier = specifiers.begin(); specifier != specifiers.end();
            ++specifier)
        {
            specifierLabel.name = *specifier;
            statements.push_back(specifierLabel);
        }
        
        generateComputeUniqueMemoryTransactions(inst, stmt, type, insn);
        
        registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.calli.src)] = "uniqueCount";  
        
    }
    
    
    void CToPTXTranslator::generateComputeUniqueMemoryTransactions(ir::PTXInstruction inst, ir::PTXStatement stmt, ir::PTXOperand::DataType type, virtual_insn *insn)
    {
    
        inst.type = type;
        inst.a.addressMode = ir::PTXOperand::Invalid; 
        inst.b.addressMode = ir::PTXOperand::Invalid;
        inst.c.addressMode = ir::PTXOperand::Invalid;
        inst.d.addressMode = ir::PTXOperand::Invalid;
        
        ir::PTXStatement leastActiveThread(ir::PTXStatement::Label);
        leastActiveThread.name = LEAST_ACTIVE_THREAD;
        statements.push_back(leastActiveThread);
        
        ir::PTXInstruction newInst;
        generateSyncThreads(newInst, stmt);
            
        //mov.u32 %lmask, %lanemask_lt;
        inst.opcode = ir::PTXInstruction::Mov;
        inst.type = ir::PTXOperand::u32;
                 
        inst.d.identifier = "lmask";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = ir::PTXOperand::u32;          
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
        inst.a.identifier = "bitmask";
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = "lmask";
        inst.b.type = ir::PTXOperand::u32;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);  
           
	    //setp.ne.b32 %p2, %rb0, 0;
	    inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string p2 = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Ne;
        inst.a.type = ir::PTXOperand::b32;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = rb0;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt); 
        
        PredicateInfo predicateInfo;
	    predicateInfo.id = inst.d.identifier;
	    predicateList.push_back(predicateInfo);  
	    
	    //mov.s32 %r0, %bitmask;
	    inst.opcode = ir::PTXInstruction::Mov;
            
        inst.d.type = ir::PTXOperand::s32;
        inst.type = ir::PTXOperand::s32;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string bitmask = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        inst.a.type = ir::PTXOperand::b32;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "bitmask";
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
	    
	    //@%p2 bra $exit;
	    inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = EXIT;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = p2;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
    
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
    
        inst.d.type = type;
        inst.a.type = type;
        inst.b.type = type;
        inst.type = type;
        
        ir::PTXStatement beginReduction(ir::PTXStatement::Label);
        beginReduction.name = BEGIN_REDUCTION;
        statements.push_back(beginReduction);
    
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "uniqueCount";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        generateStaticAttributes(inst, stmt, type, insn, INSTRUCTION_COUNT);
        
        inst.d.identifier = "k";
        registers.push_back(inst.d.identifier); 
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        inst.d.identifier = "i";
        registers.push_back(inst.d.identifier); 
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);    
        
        ir::PTXStatement beginInstCountLoop(ir::PTXStatement::Label);
        beginInstCountLoop.name = BEGIN_INST_COUNT_LOOP;
        statements.push_back(beginInstCountLoop);

        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string instCountPred = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "k";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = INSTRUCTION_COUNT;
        
        predicateInfo.id = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
          
        predicateList.push_back(predicateInfo);  
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = STORE_RESULTS;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = instCountPred;
        
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
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string firstLoopPred = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "i";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = specialRegisterMap["sharedMemSize"];
        
        predicateInfo.id = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
          
        predicateList.push_back(predicateInfo);  
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = STORE_RESULTS;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = firstLoopPred;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        ir::PTXStatement firstLoop(ir::PTXStatement::Label);
        firstLoop.name = FIRST_LOOP;
        statements.push_back(firstLoop);
        
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "isUnique";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 1;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "j";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);     
        
        ir::PTXStatement beginSecondLoop(ir::PTXStatement::Label);
        beginSecondLoop.name = BEGIN_SECOND_LOOP;
        statements.push_back(beginSecondLoop);
        
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string secondLoopPred = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "j";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = "uniqueCount";
        
        predicateInfo.id = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string i_offset = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "k";
        
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = specialRegisterMap["sharedMemSize"];
        
        inst.c.type = type;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.identifier = "i";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.c.addressMode = ir::PTXOperand::Invalid;
        
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string mul_i = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = i_offset;
        
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = sizeof(size_t);
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Add;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string add_i_to_base = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = mul_i;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = sharedMemReg;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Ld;
            
        inst.addressSpace = ir::PTXInstruction::Shared; 
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.a.addressMode = ir::PTXOperand::Indirect;
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string rhs = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        inst.a.identifier = add_i_to_base;
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = UPDATE_COUNTER;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = secondLoopPred;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        ir::PTXStatement secondLoop(ir::PTXStatement::Label);
        secondLoop.name = SECOND_LOOP;
        statements.push_back(secondLoop);
        
        inst.pg.condition = ir::PTXOperand::PT;
        inst.pg.identifier.clear();
        
        inst.opcode = ir::PTXInstruction::Mad;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string j_offset = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "k";
        
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = specialRegisterMap["sharedMemSize"];
        
        inst.c.type = type;
        inst.c.addressMode = ir::PTXOperand::Register;
        inst.c.identifier = "j";
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.c.addressMode = ir::PTXOperand::Invalid;
        
        inst.opcode = ir::PTXInstruction::Mul;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::lo;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string mul_j = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = j_offset;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = sizeof(size_t);
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Add;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        registers.push_back(inst.d.identifier);
        std::string add_j_to_base = inst.d.identifier;		 
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = mul_j;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.type = type;
        inst.b.identifier = sharedMemReg;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Ld;
            
        inst.addressSpace = ir::PTXInstruction::Shared; 
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
        std::string lhs = inst.d.identifier;
        inst.a.identifier = add_j_to_base;
        inst.a.addressMode = ir::PTXOperand::Indirect;
        
        registers.push_back(inst.d.identifier);
        
        setPredicate(inst);
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string isEqualPred = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = lhs;
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Register;
        inst.b.identifier = rhs;
        
        predicateInfo.id = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Mov;
                 
        inst.d.identifier = "isUnique";
        registers.push_back(inst.d.identifier); 
             
        inst.d.type = type;          
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.a.addressMode = ir::PTXOperand::Immediate;
        inst.a.type = type;
        inst.a.imm_int = 0;
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = isEqualPred;
        
        setPredicate(inst);
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
        setPredicate(inst);
           
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
        
        inst.opcode = ir::PTXInstruction::SetP;
            
        inst.d.type = ir::PTXOperand::pred;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
        std::string isUniqueTrue = inst.d.identifier;
        registers.push_back(inst.d.identifier);
        
        inst.comparisonOperator = ir::PTXInstruction::Eq;
        inst.a.type = type;
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.identifier = "isUnique";
        inst.b.type = type;
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.imm_uint = 1;
        
        predicateInfo.id = inst.d.identifier;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.pg.condition = ir::PTXOperand::Pred;
        inst.pg.identifier = isUniqueTrue;
        
        inst.opcode = ir::PTXInstruction::Add;     
        setPredicate(inst);
           
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
        setPredicate(inst);
           
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
        
        ir::PTXStatement instCountLoopInc(ir::PTXStatement::Label);
        instCountLoopInc.name = INST_COUNT_LOOP_INC;
        statements.push_back(instCountLoopInc);
        
        inst.opcode = ir::PTXInstruction::Add;     
        setPredicate(inst);
           
        inst.modifier = ir::PTXInstruction::Modifier_invalid;
        inst.d.addressMode = ir::PTXOperand::Register;
        inst.d.type = type;
        
        inst.d.identifier = "k";
        
        inst.a.addressMode = ir::PTXOperand::Register;
        inst.a.type = type;
        inst.a.identifier = "k";
        inst.b.addressMode = ir::PTXOperand::Immediate;
        inst.b.type = type;
        inst.b.imm_uint = 1;
         
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        inst.opcode = ir::PTXInstruction::Bra;
        inst.d.addressMode = ir::PTXOperand::Label;
        inst.d.identifier = BEGIN_INST_COUNT_LOOP;
        
        stmt.instruction = inst;
        statements.push_back(stmt);
        
        ir::PTXStatement storeResults(ir::PTXStatement::Label);
        storeResults.name = STORE_RESULTS;
        statements.push_back(storeResults);
        
        blockLabels.push_back(LEAST_ACTIVE_THREAD);
        blockLabels.push_back(BEGIN_REDUCTION);
        blockLabels.push_back(BEGIN_INST_COUNT_LOOP);
        blockLabels.push_back(BEGIN_FIRST_LOOP);
        blockLabels.push_back(BEGIN_SECOND_LOOP);
        blockLabels.push_back(FIRST_LOOP);
        blockLabels.push_back(SECOND_LOOP);
        blockLabels.push_back(FIRST_LOOP_INC);
        blockLabels.push_back(SECOND_LOOP_INC);
        blockLabels.push_back(INST_COUNT_LOOP_INC);
        blockLabels.push_back(UPDATE_COUNTER);
        blockLabels.push_back(STORE_RESULTS);
        
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
                shared.array.stride = ir::PTXStatement::ArrayStrideVector(1, 4);
                shared.alignment = 64;
                shared.type = type;

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
            inst.a.imm_int = insn->opnds.a3i.u.imm;
            
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
                    registerMap.erase(src1);
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
                inst.b.imm_int = insn->opnds.a3i.u.imm;
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
                    case predicateEvalWarpUniformSymbol:
                    {
                        generatePredicateEvalWarpUniform(inst, stmt, type, insn, true);
                    }
                    break;
                    case predicateEvalWarpDivergentSymbol:
                    {
                        generatePredicateEvalWarpUniform(inst, stmt, type, insn, false);
                    }
                    break;
                    case computeBaseAddressSymbol:
                    {
                        generateComputeBaseAddress(inst, stmt, type, insn, call_name);
                    }
                    break;
                    case memoryTransactionCountSymbol:
                    {
                        generateMemoryTransactionCount(inst, stmt, type, insn, call_name);
                    }
                    break;
                    case computeUniqueMemTransactionsSymbol:
                    {
                        generateComputeUniqueMemoryTransactions(inst, stmt, type, insn);
                    }
                    break;
                    case leastActiveThreadInWarpSymbol:
                    {
                        generateLeastActiveThreadInWarp(inst, stmt, type, insn);
                    }
                    break;
              
                    case basicBlockIdSymbol:
                    case basicBlockInstCountSymbol: 
                    case basicBlockExecInstCountSymbol:
                    case instructionIdSymbol:
                    case instructionCountSymbol:
                    case uniqueElementCountSymbol:
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
        {
            inst.opcode = ir::PTXInstruction::SetP;
            
            inst.d.type = ir::PTXOperand::pred;
            inst.d.addressMode = ir::PTXOperand::Register;
            inst.d.identifier = COD_PRED + boost::lexical_cast<std::string>(++maxPredicate);
            registers.push_back(inst.d.identifier);
            
            inst.comparisonOperator = ir::PTXInstruction::Eq;
            inst.a.type = type;
            inst.a.addressMode = ir::PTXOperand::Register;
            inst.a.identifier = registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.br.src1)];
            inst.b.type = type;
            inst.b.addressMode = ir::PTXOperand::Register;
            inst.b.identifier = registerMap[REG + boost::lexical_cast<std::string>(insn->opnds.br.src2)];
            
	        PredicateInfo predicateInfo;
	        predicateInfo.id = inst.d.identifier;
	        
	        std::string label;

	        int br_op = insn->insn_code;
	        struct branch_table *t = &c->p->branch_table;
            if (t->label_name[insn->opnds.br.label] != NULL) {
                label = t->label_name[insn->opnds.br.label];
	        }
	        else {
	            label = "L" + boost::lexical_cast<std::string>(insn->opnds.br.label);
	        }
	        
	        predicateInfo.branchLabel = label;
	        if(br_op >= 55 && br_op < 66){
	            predicateInfo.condition = PredicateInfo::NOT_TAKEN;
	            predicateInfo.set = true;
	        }
	        else if(br_op >= 0 && br_op < 11){
	            predicateInfo.condition = PredicateInfo::TAKEN;
	            predicateInfo.set = false;
	        }
	       
	        if(label == "loop end")
	        {
	            ir::PTXStatement loop(ir::PTXStatement::Label);
                loop.name = LOOP;
                statements.push_back(loop);
                blockLabels.push_back(LOOP);
	        }
	       
	       
	        stmt.instruction = inst;
	        statements.push_back(stmt);
	          
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
            
            if(memoryType == sharedMemory)
                inst.addressSpace = ir::PTXInstruction::Shared;
            else
                inst.addressSpace = ir::PTXInstruction::Global; 
            
            inst.type = type;
            
	        int store = (insn->insn_code & 0x10) && 0x10;
	        if(store) {
	            
	            inst.opcode = ir::PTXInstruction::St;
	            
                inst.d.identifier = registerMap[src1];		
                inst.a.identifier = registerMap[dst];	
                
                inst.d.addressMode = ir::PTXOperand::Indirect;
                inst.a.addressMode = ir::PTXOperand::Register;
                inst.a.type = type;
	        }
	        else {
	            
	            inst.opcode = ir::PTXInstruction::Ld;
	            
                inst.a.identifier = registerMap[src1];		
                inst.d.identifier = COD_REG + boost::lexical_cast<std::string>(++maxRegister);
                registers.push_back(inst.d.identifier);
                
                registerMap[dst] = inst.d.identifier;
                
                inst.a.addressMode = ir::PTXOperand::Indirect;
                inst.d.addressMode = ir::PTXOperand::Register;
                inst.d.type = type;
	        }
	           
	        ir::PTXInstruction prev = statements.back().instruction;
	        
            if(prev.opcode == ir::PTXInstruction::Add && (prev.d.identifier == inst.d.identifier || prev.d.identifier == inst.a.identifier)) {
            
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
                
                if(memoryType == sharedMemory)
                    prev.b.identifier = sharedMemReg;
                else    
                    prev.b.identifier = baseReg;
                
                statements.pop_back();
                stmt.instruction = prev;
                statements.push_back(stmt);
            }
               
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

            if(label == SHARED_MEM)
                memoryType = sharedMemory;
            else if(label == GLOBAL_MEM)
                memoryType = globalMemory;

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
                    targets.push_back(label);
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
        
	    case iclass_push:
        case iclass_pushi:
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
                                        unsigned long basicBlockId();\
                                        unsigned long basicBlockInstructionCount();\
                                        unsigned long basicBlockExecutedInstructionCount();\
                                        unsigned long instructionId();\
                                        unsigned long instructionCount();\
                                        unsigned long warpCount();\
                                        unsigned long warpId();\
                                        unsigned long predicateEvalWarpUniform();\
                                        unsigned long predicateEvalWarpDivergent();\
                                        unsigned long memoryTransactionCount();\
                                        void computeUniqueMemoryTransactions();\
                                        unsigned long leastActiveThreadInWarp();\
                                        unsigned long computeBaseAddress();\
                                        unsigned long uniqueElementCount(unsigned long *memBuffer);\
                                        unsigned long deviceMem[2];\
                                        unsigned long sharedMem[2];";
                        
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
            {(char *)"basicBlockId", (void*)(unsigned long)(*basicBlockId)},
            {(char *)"basicBlockInstructionCount", (void*)(unsigned long)(*basicBlockInstructionCount)},
            {(char *)"basicBlockExecutedInstructionCount", (void*)(unsigned long)(*basicBlockExecutedInstructionCount)},
            {(char *)"instructionId", (void*)(unsigned long)(*instructionId)},
            {(char *)"instructionCount", (void*)(unsigned long)(*instructionCount)},
            {(char *)"warpCount", (void*)(unsigned long)(*warpCount)},
            {(char *)"warpId", (void*)(unsigned long)(*warpId)},
            {(char *)"predicateEvalWarpUniform", (void*)(unsigned long)(*predicateEvalWarpUniform)},
            {(char *)"predicateEvalWarpDivergent", (void*)(unsigned long)(*predicateEvalWarpDivergent)},
            {(char *)"memoryTransactionCount", (void*)(unsigned long)(*memoryTransactionCount)},
            {(char *)"computeUniqueMemoryTransactions", (void*)(*computeUniqueMemoryTransactions)},
            {(char *)"leastActiveThreadInWarp", (void*)(unsigned long)(*leastActiveThreadInWarp)},
            {(char *)"computeBaseAddress", (void*)(*computeBaseAddress)},
            {(char *)"uniqueElementCount", (void*)(*uniqueElementCount)},
            {(char *)"deviceMem", (void *)deviceMem},
            {(char *)"sharedMem", (void *)deviceMem},
	        {NULL, (void*)0}
	    };
     
     
        cod_code gen_code;
	    void (*func)();
	
	    dill_set_foreign_cg(foreign_code_generator);

	    context = new_cod_parse_context();
	    cod_assoc_externs(context, externs);
	    cod_parse_for_context(extern_string, context);
	    gen_code = cod_code_gen((char *)code.c_str(), context);
	    ec = cod_create_exec_context(gen_code);
	    func = (void(*)()) gen_code->func;
        
        
	    cod_exec_context_free(ec);
	    cod_code_free(gen_code);
	    cod_free_parse_context(context);
	    
	    CToPTXData data;
	    
	    data.statements = translator.statements;
	    data.globals = translator.globals;
	    data.registers = translator.registers;
	    data.blockLabels = translator.blockLabels;
	    data.specialRegisterMap = translator.specialRegisterMap;
	    
	    return data;
    }
    
    CToPTXTranslator::CToPTXTranslator()
        : maxRegister(0), maxPredicate(0)
    {
        memoryType = globalMemory;
    
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
        functionCalls["basicBlockInstructionCount"] = basicBlockInstCountSymbol;
        functionCalls["basicBlockExecutedInstructionCount"] = basicBlockExecInstCountSymbol;
        functionCalls["instructionId"] = instructionIdSymbol;
        functionCalls["instructionCount"] = instructionCountSymbol;
        functionCalls["warpCount"] = warpCountSymbol;
        functionCalls["warpId"] = warpIdSymbol;
        functionCalls["predicateEvalWarpUniform"] = predicateEvalWarpUniformSymbol;
        functionCalls["predicateEvalWarpDivergent"] = predicateEvalWarpDivergentSymbol;
        functionCalls["computeBaseAddress"] = computeBaseAddressSymbol;
        functionCalls["memoryTransactionCount"] = memoryTransactionCountSymbol;
        functionCalls["computeUniqueMemoryTransactions"] = computeUniqueMemTransactionsSymbol;
        functionCalls["uniqueElementCount"] = uniqueElementCountSymbol;
        functionCalls["leastActiveThreadInWarp"] = leastActiveThreadInWarpSymbol;
        functionCalls["computeBaseAddress"] = computeBaseAddressSymbol;
        
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
