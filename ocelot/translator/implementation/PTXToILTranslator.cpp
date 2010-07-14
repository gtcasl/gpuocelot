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
			_ilKernel(0),
			_tempRegisterCount(100)
	{
	}

	ir::Kernel *PTXToILTranslator::translate(const ir::Kernel *k)
	{
		assertM(k->ISA == ir::Instruction::PTX,
				"Kernel must be a PTXKernel to translate to an ILKernel");

		_ilKernel = new ir::ILKernel(*k);

		report("Translating kernel " << k->name);

		// translate iterating thru the control tree
		_translate(_ilKernel->ctrl_tree()->get_root_node());

		//_translateInstructions();
		_addKernelPrefix();

 		return _ilKernel;
  	}

	void PTXToILTranslator::_translate(const ControlTree::Node* node)
	{
		report("Translating " << node->label());

		switch (node->rtype())
		{
			case ControlTree::Node::Inst:
			{
				_translate(static_cast<const ControlTree::InstNode*>(node));
				break;
			}
			case ControlTree::Node::Block:
			{
				_translate(static_cast<const ControlTree::BlockNode*>(node));
				break;
			}
			case ControlTree::Node::IfThen:
			{
				_translate(static_cast<const ControlTree::IfThenNode*>(node));
				break;
			}
			case ControlTree::Node::SelfLoop:
			{
				_translate(static_cast<const ControlTree::SelfLoopNode*>(node));
				break;
			}
			default: assertM(false, "Invalid region type " << node->rtype());
		}
	}

	void PTXToILTranslator::_translate(const ControlTree::InstNode* insts)
	{
		//ControlTree::InstNode::const_iterator ins;
		ir::ControlFlowGraph::InstructionList::const_iterator ins;
		//for (ins = insts->begin() ; ins != insts->end() ; ins++)
		for (ins = insts->bb()->instructions.begin() ; 
				ins != insts->bb()->instructions.end() ; ins++)
		{
			_translate(static_cast<ir::PTXInstruction &>(**ins));
		}
	}

	void PTXToILTranslator::_translate(const ControlTree::BlockNode* block)
	{
		ControlTree::NodeList::const_iterator node;
		for (node = block->children().begin() ; 
				node != block->children().end() ; node++)
		{
			_translate(*node);
		}	
	}

	void PTXToILTranslator::_translate(const ControlTree::IfThenNode* ifthen)
	{
		const ControlTree::Node* cond = ifthen->cond();

		assertM(cond->rtype() == ControlTree::Node::Inst, 
				"Invalid condition node");

		ir::Instruction* ins =
			static_cast<const ControlTree::InstNode*>(cond)->bb()->instructions.back();

		ir::PTXInstruction& bra = static_cast<ir::PTXInstruction&>(*ins);

		assertM(bra.opcode == ir::PTXInstruction::Bra, "Invalid instruction");
		
		_translate(cond);

		ir::ILIfLogicalZ if_logicalz;
		if_logicalz.a = _translate(bra.pg);
		_add(if_logicalz);

		_translate(ifthen->ifTrue());

		_add(ir::ILEndIf());
	}

	void PTXToILTranslator::_translate(const ControlTree::SelfLoopNode* selfloop)
	{
		_add(ir::ILWhileLoop());

		const ControlTree::Node* body = selfloop->body();

		//TODO only simple InstNode bodies are handled for now
		assertM(body->rtype() == ControlTree::Node::Inst, 
				"Invalid loop body node");

		_translate(body);

		ir::Instruction* ins =
			static_cast<const ControlTree::InstNode*>(body)->bb()->instructions.back();

		ir::PTXInstruction& bra = static_cast<ir::PTXInstruction&>(*ins);

		assertM(bra.opcode == ir::PTXInstruction::Bra, "Invalid instruction");
		
		ir::ILIfLogicalZ if_logicalz;
		if_logicalz.a = _translate(bra.pg);
		_add(if_logicalz);
		_add(ir::ILBreak());
		_add(ir::ILEndIf());
		_add(ir::ILEndLoop());
	}

	void PTXToILTranslator::_translate(const ir::PTXInstruction &i)
	{
		report("Translating: " << i.toString());
		switch (i.opcode) 
		{
 			case ir::PTXInstruction::Add:  _translateAdd(i);     break;
			case ir::PTXInstruction::Bra:  _translateBra(i);     break;
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

		switch (o.addressMode)
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
				op = _translateLiteral(o.imm_uint);
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
						<< o.addressMode << " not supported");
			}
		}

		return op;
	}

	ir::ILInstruction::DataType PTXToILTranslator::_translate(
			const ir::PTXOperand::DataType d)
	{
		switch(ir::PTXOperand::bytes(d))
		{
			case 1: return ir::ILInstruction::Byte;
			case 2: return ir::ILInstruction::Short;
			case 8: return ir::ILInstruction::Dword;
			default:
			{
				assertM(false, "DataType " << d << " not supported");
			}
		}
	}

	ir::ILOperand PTXToILTranslator::_tempRegister()
	{
		std::stringstream stream;
		stream << "r" << _tempRegisterCount++;

		ir::ILOperand r;
		r.addressMode = ir::ILOperand::Register;
		r.identifier = stream.str();

		return r;
	}

	std::string PTXToILTranslator::_translate(
			const ir::PTXOperand::RegisterType &reg)
	{
		assertM(reg < 100, "Register name collides with temp registers");

		std::stringstream stream;
		stream << "r" << reg;
		return stream.str();
	}

	ir::ILOperand::SpecialRegister PTXToILTranslator::_translate(
			const ir::PTXOperand::SpecialRegister &s)
	{
		ir::ILOperand::SpecialRegister sr;

		switch (s)
		{
			case ir::PTXOperand::tidX:    sr = ir::ILOperand::vTidInGrpX;     break;
			case ir::PTXOperand::tidY:    sr = ir::ILOperand::vTidInGrpY;     break;
			case ir::PTXOperand::tidZ:    sr = ir::ILOperand::vTidInGrpZ;     break;
			case ir::PTXOperand::ntidX:   sr = ir::ILOperand::vNTidInGrpX;    break;
			case ir::PTXOperand::ntidY:   sr = ir::ILOperand::vNTidInGrpY;    break;
			case ir::PTXOperand::ntidZ:   sr = ir::ILOperand::vNTidInGrpZ;    break;
			case ir::PTXOperand::ctaIdX:  sr = ir::ILOperand::vThreadGrpIdX;  break;
			case ir::PTXOperand::ctaIdY:  sr = ir::ILOperand::vThreadGrpIdY;  break;
			case ir::PTXOperand::ctaIdZ:  sr = ir::ILOperand::vThreadGrpIdZ;  break;
			case ir::PTXOperand::nctaIdX: sr = ir::ILOperand::vNThreadGrpIdX; break;
			case ir::PTXOperand::nctaIdY: sr = ir::ILOperand::vNThreadGrpIdY; break;
			case ir::PTXOperand::nctaIdZ: sr = ir::ILOperand::vNThreadGrpIdZ; break;
			default: assertM(false, "Special Register " << s << " not supported");
		}

		return sr;
	}

	void PTXToILTranslator::_translateAdd(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::u32:
			case ir::PTXOperand::u64:
			case ir::PTXOperand::s32:
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
		// do nothing (bra instructions are handled using the control tree)
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
		switch (i.addressSpace)
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
				switch (i.vec)
				{
					case ir::PTXOperand::v1:
					{
						if (i.a.offset == 0)
						{
							if (ir::PTXOperand::bytes(i.type) == 4)
							{
								ir::ILUav_Raw_Load_Id uav_raw_load_id;
								uav_raw_load_id.a = _translate(i.a);
								uav_raw_load_id.d = _translate(i.d);
								_add(uav_raw_load_id);
							} else
							{
								ir::ILUav_Arena_Load_Id uav_arena_load_id;
								uav_arena_load_id.a = _translate(i.a);
								uav_arena_load_id.d = _translate(i.d);
								uav_arena_load_id.type = _translate(i.type);
								_add(uav_arena_load_id);
							}
						} else
						{
							ir::ILOperand temp = _tempRegister();

							ir::ILIadd iadd;
							iadd.a = _translate(i.a);
							iadd.b = _translateLiteral(i.a.offset);
							iadd.d = temp;
							_add(iadd);

							if (ir::PTXOperand::bytes(i.type) == 4)
							{
								ir::ILUav_Raw_Load_Id uav_raw_load_id;
								uav_raw_load_id.a = temp;
								uav_raw_load_id.d = _translate(i.d);
								_add(uav_raw_load_id);
							}
							else
							{
								ir::ILUav_Arena_Load_Id uav_arena_load_id;
								uav_arena_load_id.a = temp;
								uav_arena_load_id.d = _translate(i.d);
								uav_arena_load_id.type = _translate(i.type);
								_add(uav_arena_load_id);
							}
						}

						break;
					}
					case ir::PTXOperand::v2:
					case ir::PTXOperand::v4:
					{
						ir::ILOperand temp = _tempRegister();
						ir::PTXOperand::Array::const_iterator dst;
						int offset = i.a.offset;
						for (dst = i.d.array.begin() ;
								dst != i.d.array.end() ; dst++)
						{
							ir::ILIadd iadd;
							iadd.a = _translate(i.a);
							iadd.b = _translateLiteral(offset);
							iadd.d = temp;
							_add(iadd);

							if (ir::PTXOperand::bytes(i.type) == 4)
							{
								ir::ILUav_Raw_Load_Id uav_raw_load_id;
								uav_raw_load_id.a = temp;
								uav_raw_load_id.d = _translate(*dst);
								_add(uav_raw_load_id);
							} else
							{
								ir::ILUav_Arena_Load_Id uav_arena_load_id;
								uav_arena_load_id.a = temp;
								uav_arena_load_id.d = _translate(*dst);
								uav_arena_load_id.type = _translate(i.type);
								_add(uav_arena_load_id);
							}

							offset += ir::PTXOperand::bytes(i.type);
						}

						break;
					}
					default:
					{
						assertM(false, "Vector operation " 
								<< i.vec 
								<< " not supported");
					}
				}
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

		imul.a = _translate(i.a);
		imul.b = _translate(i.b);
		imul.d = _translate(i.d);

		_add(imul);
	}

	void PTXToILTranslator::_translateSetP(const ir::PTXInstruction &i)
	{
		switch (i.comparisonOperator)
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
			case ir::PTXInstruction::Lt:
			{
				ir::ILIlt ilt;

				ilt.a = _translate(i.a);
				ilt.b = _translate(i.b);
				ilt.d = _translate(i.d);

				_add(ilt);

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
		switch (i.vec)
		{
			case ir::PTXOperand::v1:
			{
				if (i.d.offset == 0)
				{
					if (ir::PTXOperand::bytes(i.type) == 4)
					{
						ir::ILUav_Raw_Store_Id uav_raw_store_id;
						uav_raw_store_id.a = _translate(i.a);
						uav_raw_store_id.d = _translate(i.d);
						_add(uav_raw_store_id);
					} else
					{
						ir::ILUav_Arena_Store_Id uav_arena_store_id;
						uav_arena_store_id.a = _translate(i.a);
						uav_arena_store_id.d = _translate(i.d);
						uav_arena_store_id.type = _translate(i.type);
						_add(uav_arena_store_id);
					}
				} else
				{
					ir::ILOperand temp = _tempRegister();

					ir::ILIadd iadd;
					iadd.a = _translate(i.d);
					iadd.b = _translateLiteral(i.d.offset);
					iadd.d = temp;
					_add(iadd);

					if (ir::PTXOperand::bytes(i.type) == 4)
					{
						ir::ILUav_Raw_Store_Id uav_raw_store_id;
						uav_raw_store_id.a = _translate(i.a);
						uav_raw_store_id.d = temp;
						_add(uav_raw_store_id);
					} else
					{
						ir::ILUav_Arena_Store_Id uav_arena_store_id;
						uav_arena_store_id.a = _translate(i.a);
						uav_arena_store_id.d = temp;
						uav_arena_store_id.type = _translate(i.type);
						_add(uav_arena_store_id);
					}
				}

				break;
			}
			case ir::PTXOperand::v2:
			case ir::PTXOperand::v4:
			{
				ir::ILOperand temp = _tempRegister();
				ir::PTXOperand::Array::const_iterator src;
				int offset = i.d.offset;
				for (src = i.a.array.begin() ;
						src != i.a.array.end() ; src++)
				{
					ir::ILIadd iadd;
					iadd.a = _translate(i.d);
					iadd.b = _translateLiteral(offset);
					iadd.d = temp;
					_add(iadd);

					if (ir::PTXOperand::bytes(i.type) == 4)
					{
						ir::ILUav_Raw_Store_Id uav_raw_store_id;
						uav_raw_store_id.a = _translate(*src);
						uav_raw_store_id.d = temp;
						_add(uav_raw_store_id);
					} else
					{
						ir::ILUav_Arena_Store_Id uav_arena_store_id;
						uav_arena_store_id.a = _translate(*src);
						uav_arena_store_id.d = temp;
						uav_arena_store_id.type = _translate(i.type);
						_add(uav_arena_store_id);
					}

					offset += ir::PTXOperand::bytes(i.type);
				}

				break;
			}
			default:
			{
				assertM(false, "Vector operation " 
						<< i.vec 
						<< " not supported");
			}
		}
	}

	ir::ILOperand PTXToILTranslator::_translateLiteral(long long unsigned int l)
	{
		std::stringstream stream;

		const LiteralMap::const_iterator it = _literals.find(l);

		if (it != _literals.end()) {
			stream << it->second;
		} else {
			stream << "l" << _literals.size();
			_literals.insert(std::make_pair(l, stream.str()));
		}

		ir::ILOperand op;
		op.addressMode = ir::ILOperand::Literal;
		op.identifier = stream.str();

		return op;
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
				report("Added statement 'dcl_literal " << it->second
						<< ", " << it->first << "'");
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
