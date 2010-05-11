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
        std::stringstream stream;
        _ilKernel = new ir::ILKernel;

        _addKernelPrefix();

		for (ir::Module::StatementVector::const_iterator
				stmt = module->statements.begin() ;
				stmt != module->statements.end() ; stmt++) {
			if (stmt->directive == ir::PTXStatement::Instr)
				_translate(stmt->instruction);
		}

 		_ilKernel->write(stream);
  
 		delete _ilKernel;
 
 		return stream.str();
  	}
  
 	void PTXToILTranslator::_addKernelPrefix()
 	{
 		//.param .u64 A
 		//.param .u64 B
 		// Support only for (int *, int *) for now
 		constbufMap.insert(std::make_pair("__cudaparm__Z11vectorScalePiS__A", 0));
 		constbufMap.insert(std::make_pair("__cudaparm__Z11vectorScalePiS__B", 1));

 		_ilKernel->_statements.push_front(ir::ILStatement(
 					ir::ILStatement::Declaration));
 	}
 
	void PTXToILTranslator::_translate(const ir::PTXInstruction &i)
	{
		report("Translating: " << i.toString());
		switch(i.opcode) 
		{
 			case ir::PTXInstruction::Add:  _translateAdd(i);  break;
 			case ir::PTXInstruction::Cvt:  _translateCvt(i);  break;
 			case ir::PTXInstruction::Exit: _translateExit(i); break;
 			case ir::PTXInstruction::Ld:   _translateLd(i);   break;
 			case ir::PTXInstruction::Mul:  _translateMul(i);  break;
 			case ir::PTXInstruction::St:   _translateSt(i);   break;
			default:
			{
				assertM(false, "Opcode "
						<< ir::PTXInstruction::toString(i.opcode)
						<< " not supported");
				break;
			}
		}
	}

	void PTXToILTranslator::_translateAdd(const ir::PTXInstruction &i)
	{
		ir::ILIadd iadd;

		iadd.a = _translate(i.a);
		iadd.b = _translate(i.b);
		iadd.d = _translate(i.d);

		_add(iadd);
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
				break;
			}
		}
	}

	void PTXToILTranslator::_translateMul(const ir::PTXInstruction &i)
	{
		ir::ILImul imul;

		imul.a = _translate(i.a);
		imul.b = _translate(i.b);
		imul.d = _translate(i.d);

		_add(imul);
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
				assertM(false, "Address Mode "
						<< o.addressMode 
						<< " not supported");
				break;
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

	std::string PTXToILTranslator::_translateConstantBuffer(
			const std::string &ident)
	{
		std::stringstream stream;

		const ConstBufMap::const_iterator it = constbufMap.find(ident);

		if (it != constbufMap.end()) {
			stream << "cb1[" << it->second << "]";
		} else {
			assertM(false, "Parameter "
					<< ident
					<< "not declared");
		}

		return stream.str();
	}

	ir::ILOperand::SpecialRegister PTXToILTranslator::_translate(
			const ir::PTXOperand::SpecialRegister &s)
	{
		ir::ILOperand::SpecialRegister sr;

		switch(s)
		{
			case ir::PTXOperand::tidX: sr = ir::ILOperand::vAbsTidFlatX; break;
			default:
			{
				assertM(false, "Special Register "
						<< s
						<< " not supported");
				break;
			}
		}

		return sr;
	}

	void PTXToILTranslator::_add(const ir::ILInstruction &i)
	{
		report("Added instruction '" << i.toString() << "'");
		_ilKernel->_statements.push_back(ir::ILStatement(i));
	}
}
