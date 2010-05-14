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
	PTXToILTranslator::PTXToILTranslator() : literals(0), registers(0)
	{
	}

	std::string PTXToILTranslator::translate(const ir::Module *module)
	{
		assertM(module->kernels.size() == 1, 
				"Multiple kernels not supported yet");

		ir::Kernel *k = module->kernels.begin()->second;

		assertM(k->ISA == ir::Instruction::PTX,
				"Kernel must be a PTXKernel to translate to an ILKernel");

		_ilKernel = new ir::ILKernel(*k);

		_addKernelPrefix();

		for (ir::Module::StatementVector::const_iterator
				stmt = module->statements.begin() ;
				stmt != module->statements.end() ; stmt++) {
			if (stmt->directive == ir::PTXStatement::Instr)
				_translate(stmt->instruction);
			// Ugly hack to make vectorAdd pass. 
			if (stmt->directive == ir::PTXStatement::Label && 
					stmt->name == "$Lt_0_1026") {
				ir::ILEndIf endif;
				_add(endif);
			}

		}

		std::stringstream stream;
 		_ilKernel->write(stream);
		report("_ilKernel = " << std::endl << stream.str());

 		delete _ilKernel;

 		return stream.str();
  	}
  
 	void PTXToILTranslator::_addKernelPrefix()
 	{
		ir::ILStatement dcl_cb1(ir::ILStatement::ConstantBufferDcl);

		std::stringstream stream;
		stream << "cb1[" << _ilKernel->parameters.size() << "]";
		dcl_cb1.operand.identifier = stream.str();
		dcl_cb1.operand.addressMode = ir::ILOperand::ConstantBuffer;

 		_ilKernel->_statements.push_front(dcl_cb1);

 		_ilKernel->_statements.push_front(ir::ILStatement(
 					ir::ILStatement::OtherDeclarations));
 	}
 
	void PTXToILTranslator::_translate(const ir::PTXInstruction &i)
	{
		report("Translating: " << i.toString());
		switch(i.opcode) 
		{
 			case ir::PTXInstruction::Add:  _translateAdd(i);  break;
			case ir::PTXInstruction::Bra:  _translateBra(i);  break;
 			case ir::PTXInstruction::Cvt:  _translateCvt(i);  break;
 			case ir::PTXInstruction::Exit: _translateExit(i); break;
 			case ir::PTXInstruction::Ld:   _translateLd(i);   break;
			case ir::PTXInstruction::Mov:  _translateMov(i);  break;
 			case ir::PTXInstruction::Mul:  _translateMul(i);  break;
			case ir::PTXInstruction::SetP: _translateSetP(i); break;
 			case ir::PTXInstruction::St:   _translateSt(i);   break;
			default:
			{
				assertM(false, "Opcode "
						<< ir::PTXInstruction::toString(i.opcode)
						<< " not supported");
			}
		}
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

	void PTXToILTranslator::_translateBra(const ir::PTXInstruction &i)
	{
		ir::ILIfLogicalZ if_logicalz;

		if_logicalz.a = _translate(i.pg);

		_add(if_logicalz);
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
				op.identifier = _translateRegister(o.identifier);
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
				op.special = _translate(o.special);
				break;
			}
			default:
			{
				assertM(false, "Address Mode " << o.addressMode << " not supported");
			}
		}

		return op;
	}

	std::string PTXToILTranslator::_translateRegister(
			const std::string &ident)
	{
		std::stringstream stream;

		const RegisterMap::const_iterator it = registerMap.find(ident);

		if (it != registerMap.end()) {
			stream << it->second;
		} else {
			stream << "r" << registers++;
			registerMap.insert(std::make_pair(ident, stream.str()));
		}

		return stream.str();
	}

	std::string PTXToILTranslator::_translateLiteral(long long unsigned int l)
	{
		std::stringstream stream;

		const LiteralMap::const_iterator it = literalMap.find(l);

		if (it != literalMap.end()) {
			stream << it->second;
		} else {
			stream << "l" << literals++;
			literalMap.insert(std::make_pair(l, stream.str()));
		}

		return stream.str();
	}

	//TODO Rename to _translate(ir::PTXOperand::Address)
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

	ir::ILOperand::SpecialRegister PTXToILTranslator::_translate(
			const ir::PTXOperand::SpecialRegister &s)
	{
		ir::ILOperand::SpecialRegister sr;

		switch(s)
		{
			case ir::PTXOperand::tidX:   sr = ir::ILOperand::vTidInGrpX;    break;
			case ir::PTXOperand::tidY:   sr = ir::ILOperand::vTidInGrpY;    break;
			case ir::PTXOperand::tidZ:   sr = ir::ILOperand::vTidInGrpZ;    break;
			case ir::PTXOperand::ntidX:  sr = ir::ILOperand::vNTidInGrpX;   break;
			case ir::PTXOperand::ntidY:  sr = ir::ILOperand::vNTidInGrpY;   break;
			case ir::PTXOperand::ntidZ:  sr = ir::ILOperand::vNTidInGrpZ;   break;
			case ir::PTXOperand::ctaIdX: sr = ir::ILOperand::vThreadGrpIdX; break;
			case ir::PTXOperand::ctaIdY: sr = ir::ILOperand::vThreadGrpIdY; break;
			case ir::PTXOperand::ctaIdZ: sr = ir::ILOperand::vThreadGrpIdZ; break;
			default: assertM(false, "Special Register " << s << " not supported");
		}

		return sr;
	}

	void PTXToILTranslator::_add(const ir::ILInstruction &i)
	{
		report("Added instruction '" << i.toString() << "'");
		_ilKernel->_statements.push_back(ir::ILStatement(i));
	}
}
