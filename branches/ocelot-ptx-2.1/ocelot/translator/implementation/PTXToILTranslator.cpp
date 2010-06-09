/*! \file PTXToILTranslator.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 19, 2010
 *  \brief The implementation file for the PTX to IL Translator class.
 */

// Ocelot includes
#include <ocelot/translator/interface/PTXToILTranslator.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace translator
{
	PTXToILTranslator::PTXToILTranslator(OptimizationLevel l)
		:
			Translator(ir::Instruction::PTX, ir::Instruction::CAL, l),
			_ilKernel(0)
	{
	}

	ir::Kernel *PTXToILTranslator::translate(const ir::Kernel *k)
	{
		assertM(k->ISA == ir::Instruction::PTX,
				"Kernel must be a PTXKernel to translate to an ILKernel");

		_ilKernel = new ir::ILKernel(*k);

		_translateInstructions();
		_addKernelPrefix();

 		return _ilKernel;
  	}

	void PTXToILTranslator::_translateInstructions()
	{
		ir::ControlFlowGraph::iterator blockIt;
		for (blockIt = _ilKernel->cfg()->begin() ; 
				blockIt != _ilKernel->cfg()->end(); blockIt++) 
		{
			ir::ControlFlowGraph::BasicBlock block = *blockIt;
			_translate(&block);
		}
	}

	void PTXToILTranslator::_translate(ir::ControlFlowGraph::BasicBlock *block)
	{
		if (block->visited) return;
		block->visited = true;

		ir::ControlFlowGraph::InstructionList::const_iterator ins;
		for (ins = block->instructions.begin() ; 
				ins != block->instructions.end() ; ins++) {
			_translate(static_cast<ir::PTXInstruction &>(**ins), block);
		}
	}
  
	void PTXToILTranslator::_translate(const ir::PTXInstruction &i, 
		   ir::ControlFlowGraph::BasicBlock *b)
	{
		report("Translating: " << i.toString());
		switch(i.opcode) 
		{
 			case ir::PTXInstruction::Add:  _translateAdd(i);     break;
			case ir::PTXInstruction::Bra:  _translateBra(i, b);  break;
 			case ir::PTXInstruction::Cvt:  _translateCvt(i);     break;
 			case ir::PTXInstruction::Exit: _translateExit(i);    break;
 			case ir::PTXInstruction::Ld:   _translateLd(i);      break;
			case ir::PTXInstruction::Mov:  _translateMov(i);     break;
 			case ir::PTXInstruction::Mul:  _translateMul(i);     break;
			case ir::PTXInstruction::SetP: _translateSetP(i);    break;
 			case ir::PTXInstruction::St:   _translateSt(i);      break;
			default:
			{
				assertM(false, "Opcode "
						<< ir::PTXInstruction::toString(i.opcode)
						<< " not supported");
			}
		}
	}

	ir::ILOperand PTXToILTranslator::_translate(const ir::PTXOperand &o)
	{
		ir::ILOperand op;

		// TODO asserM(o.is64bits, "64-bit operands not supported yet");
		switch(o.addressMode)
		{
			case ir::PTXOperand::Register:
			case ir::PTXOperand::Indirect:
			{
				op.addressMode = ir::ILOperand::Register;
				op.identifier = _translate(o.reg);
				break;
			}
			case ir::PTXOperand::Immediate:
			{
				op.addressMode = ir::ILOperand::Literal;
				op.identifier = _translateLiteral(o.imm_uint);
				break;
			}
			case ir::PTXOperand::Address:
			{
				op.addressMode = ir::ILOperand::ConstantBuffer;
				op.identifier = _translateConstantBuffer(o.identifier);
				break;
			}
			case ir::PTXOperand::Special:
			{
				op.addressMode = ir::ILOperand::Special;
				op.special = _translate(o.special, o.vIndex);
				break;
			}
			default:
			{
				assertM(false, "Address Mode " << o.addressMode << " not supported");
			}
		}

		return op;
	}

	std::string PTXToILTranslator::_translate(
			const ir::PTXOperand::RegisterType &reg)
	{
		std::stringstream stream;
		stream << "r" << reg;
		return stream.str();
	}

	ir::ILOperand::SpecialRegister PTXToILTranslator::_translate(
			const ir::PTXOperand::SpecialRegister &s, 
			const ir::PTXOperand::VectorIndex &i)
	{
		ir::ILOperand::SpecialRegister sr;

		switch(s)
		{
			case ir::PTXOperand::tid:
			{
				switch(i)
				{
					case ir::PTXOperand::ix:
					{
						sr = ir::ILOperand::vTidInGrpX;
						break;
					}
					case ir::PTXOperand::iy:
					{
						sr = ir::ILOperand::vTidInGrpY;
						break;
					}
					case ir::PTXOperand::iz:
					{
						sr = ir::ILOperand::vTidInGrpZ;
						break;
					}
					default: assertM(false, "Special Register " 
						<< s << " not supported");
				}
				break;
			}
			case ir::PTXOperand::ntid:
			{
				switch(i)
				{
					case ir::PTXOperand::ix:
					{
						sr = ir::ILOperand::vNTidInGrpX;
						break;
					}
					case ir::PTXOperand::iy:
					{
						sr = ir::ILOperand::vNTidInGrpY;
						break;
					}
					case ir::PTXOperand::iz:
					{
						sr = ir::ILOperand::vNTidInGrpZ;
						break;
					}
					default: assertM(false, "Special Register " 
						<< s << " not supported");
				}
				break;
			}		
			case ir::PTXOperand::ctaId: 
			{
				switch(i)
				{
					case ir::PTXOperand::ix:
					{
						sr = ir::ILOperand::vThreadGrpIdX;
						break;
					}
					case ir::PTXOperand::iy:
					{
						sr = ir::ILOperand::vThreadGrpIdY;
						break;
					}
					case ir::PTXOperand::iz:
					{
						sr = ir::ILOperand::vThreadGrpIdZ;
						break;
					}
					default: assertM(false, "Special Register " 
						<< s << " not supported");
				}
				break;
			}
			default: assertM(false, "Special Register " << s 
				<< " not supported");
		}

		return sr;
	}

	void PTXToILTranslator::_translateAdd(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::u32:
			case ir::PTXOperand::u64:
			{
				ir::ILIadd iadd;

				iadd.a = _translate(i.a);
				iadd.b = _translate(i.b);
				iadd.d = _translate(i.d);

				_add(iadd);

				break;
			}
			case ir::PTXOperand::f32:
			{
				ir::ILAdd add;

				add.a = _translate(i.a);
				add.b = _translate(i.b);
				add.d = _translate(i.d);

				_add(add);

				break;
			}
			default:
			{
				assertM(false, "Type "
						<< ir::PTXOperand::toString(i.type)
						<< " not supported");
			}
		}
	}

	void PTXToILTranslator::_translateBra(const ir::PTXInstruction &i,
			ir::ControlFlowGraph::BasicBlock *b)
	{
		// Only supports single forward branches (as in vectorAdd) for now
		ir::ILIfLogicalZ if_logicalz;
		ir::ILEndIf endif;

		if_logicalz.a = _translate(i.pg);

		_add(if_logicalz);

		// Add fall-through as the body of if_logicalz
		_translate(&(*b->get_fallthrough_edge()->tail));

		_add(endif);
	}

	void PTXToILTranslator::_translateCvt(const ir::PTXInstruction &i)
	{
		ir::ILMov mov;

		mov.a = _translate(i.a);
		mov.d = _translate(i.d);

		_add(mov);
	}

	void PTXToILTranslator::_translateExit(const ir::PTXInstruction &i)
	{
		ir::ILEnd end;

		_add(end);
	}

	void PTXToILTranslator::_translateLd(const ir::PTXInstruction &i)
	{
		switch(i.addressSpace)
		{
			case ir::PTXInstruction::Param:
			{
				ir::ILMov mov;

				mov.a = _translate(i.a);
				mov.d = _translate(i.d);

				_add(mov);

				break;
			}
			case ir::PTXInstruction::Global:
			{
				ir::ILUav_Raw_Load_Id uav_raw_load_id;

				uav_raw_load_id.a = _translate(i.a);
				uav_raw_load_id.d = _translate(i.d);

				_add(uav_raw_load_id);

				break;
			}
			default:
			{
				assertM(false, "Address Space "
						<< i.addressSpace 
						<< " not supported");
			}
		}
	}

	void PTXToILTranslator::_translateMov(const ir::PTXInstruction &i)
	{
		ir::ILMov mov;

		mov.a = _translate(i.a);
		mov.d = _translate(i.d);

		_add(mov);
	}

	void PTXToILTranslator::_translateMul(const ir::PTXInstruction &i)
	{
		ir::ILImul imul;

		// TODO assertM(mul.wide.u32, "32-bit multiplication not supported yet");
		imul.a = _translate(i.a);
		imul.b = _translate(i.b);
		imul.d = _translate(i.d);

		_add(imul);
	}

	void PTXToILTranslator::_translateSetP(const ir::PTXInstruction &i)
	{
		switch(i.comparisonOperator)
		{
			case ir::PTXInstruction::Le:
			{
				// IL doesn't have le but it has ge so switch a & b operands
				ir::ILIge ige;

				ige.a = _translate(i.b);
				ige.b = _translate(i.a);
				ige.d = _translate(i.d);

				_add(ige);

				break;
			}
			default:
			{
				assertM(false, "comparisonOperator "
						<< ir::PTXInstruction::toString(i.comparisonOperator)
						<< " not supported");
			}
		}
	}

	void PTXToILTranslator::_translateSt(const ir::PTXInstruction &i)
	{
		ir::ILUav_Raw_Store_Id uav_raw_store_id;

		uav_raw_store_id.a = _translate(i.a);
		uav_raw_store_id.d = _translate(i.d);

		_add(uav_raw_store_id);
	}

	std::string PTXToILTranslator::_translateLiteral(long long unsigned int l)
	{
		std::stringstream stream;

		const LiteralMap::const_iterator it = _literals.find(l);

		if (it != _literals.end()) {
			stream << it->second;
		} else {
			stream << "l" << _literals.size();
			_literals.insert(std::make_pair(l, stream.str()));
		}

		return stream.str();
	}

	std::string PTXToILTranslator::_translateConstantBuffer(
			const std::string &ident)
	{
		std::stringstream stream;

		int i = 0;
		ir::Kernel::ParameterVector::const_iterator it;
		for (it = _ilKernel->parameters.begin() ; 
				it != _ilKernel->parameters.end() ; it++, i++) {
			if (it->name == ident) break;
		}

		if (it != _ilKernel->parameters.end()) {
			stream << "cb1[" << i << "]";
		} else {
			assertM(false, "Parameter "
					<< ident
					<< " not declared");
		}

		return stream.str();
	}

 	void PTXToILTranslator::_addKernelPrefix()
 	{
		report("Adding Kernel Prefix");

		report("Adding dcl_literals");
		if (_literals.size() > 0) {
			LiteralMap::const_iterator it;
			for (it = _literals.begin() ; it != _literals.end() ; it++) 
			{
				ir::ILStatement dcl_literal(ir::ILStatement::LiteralDcl);

				dcl_literal.operands.resize(2);
				dcl_literal.operands[0].identifier = it->second;
				dcl_literal.operands[0].addressMode = ir::ILOperand::Literal;

				dcl_literal.operands[1].imm_uint = it->first;
				dcl_literal.operands[1].addressMode = ir::ILOperand::Immediate;

				_ilKernel->_statements.push_front(dcl_literal);
			}
		}

		report("Adding dcl_cb1");
		if (_ilKernel->parameters.size() > 0) {
			ir::ILStatement dcl_cb1(ir::ILStatement::ConstantBufferDcl);

			std::stringstream stream;
			stream << "cb1[" << _ilKernel->parameters.size() << "]";
			dcl_cb1.operands.resize(1);
			dcl_cb1.operands[0].identifier = stream.str();
			dcl_cb1.operands[0].addressMode = ir::ILOperand::ConstantBuffer;

			_ilKernel->_statements.push_front(dcl_cb1);
		}

		report("Adding dcl_cb0");
		ir::ILStatement dcl_cb0(ir::ILStatement::ConstantBufferDcl);

		std::stringstream stream;
		stream << "cb0[1]";
		dcl_cb0.operands.resize(1);
		dcl_cb0.operands[0].identifier = stream.str();
		dcl_cb0.operands[0].addressMode = ir::ILOperand::ConstantBuffer;

		_ilKernel->_statements.push_front(dcl_cb0);

 		_ilKernel->_statements.push_front(ir::ILStatement(
 					ir::ILStatement::OtherDeclarations));
 	}

	void PTXToILTranslator::_add(const ir::ILInstruction &i)
	{
		report("Added instruction '" << i.toString() << "'");
		_ilKernel->_statements.push_back(ir::ILStatement(i));
	}

	void PTXToILTranslator::addProfile(const ProfilingData &d)
	{
		assertM(false, "Not implemented yet");
	}
}
