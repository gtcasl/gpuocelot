/*! \file PTXToILTranslator.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 19, 2010
 *  \brief The implementation file for the PTX to IL Translator class.
 */

// Ocelot includes
#include <ocelot/translator/interface/PTXToILTranslator.h>
#include <ocelot/ir/interface/PTXKernel.h>

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
			_tempRegisterCount(1000)
	{
	}

	ir::Kernel *PTXToILTranslator::translate(const ir::Kernel *k)
	{
		assertM(k->ISA == ir::Instruction::PTX,
				"Kernel must be a PTXKernel to translate to an ILKernel");

		ir::PTXKernel ptxKernel(*(static_cast<const ir::PTXKernel* >(k)));

		// do a pass of assignRegisters before translation
		ptxKernel.assignRegisters(*ptxKernel.cfg());

		report("Translating kernel " << ptxKernel.name);

		// translate iterating thru the control tree
		_ilKernel = new ir::ILKernel(ptxKernel);
		_translate(_ilKernel->ctrl_tree()->get_root_node());
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
			case ControlTree::Node::IfThenElse:
			{
				_translate(static_cast<const ControlTree::IfThenElseNode*>(node));
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
		ir::ControlFlowGraph::InstructionList::const_iterator ins;
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

		switch (bra.pg.condition)
		{
			case ir::PTXOperand::Pred:
			{
				ir::ILIfLogicalZ if_logicalz;
				if_logicalz.a = _translate(bra.pg);
				_add(if_logicalz);
				break;
			}
			case ir::PTXOperand::InvPred:
			{
				ir::ILIfLogicalNZ if_logicalnz;
				if_logicalnz.a = _translate(bra.pg);
				_add(if_logicalnz);
				break;
			}
			default: assertM(false, "Invalid predicate condition");

		}

		_translate(ifthen->ifTrue());

		_add(ir::ILEndIf());
	}

	void PTXToILTranslator::_translate(const ControlTree::IfThenElseNode* ifthenelse)
	{
		const ControlTree::Node* cond = ifthenelse->cond();

		assertM(cond->rtype() == ControlTree::Node::Inst, 
				"Invalid condition node");

		ir::Instruction* ins =
			static_cast<const ControlTree::InstNode*>(cond)->bb()->instructions.back();

		ir::PTXInstruction& bra = static_cast<ir::PTXInstruction&>(*ins);

		assertM(bra.opcode == ir::PTXInstruction::Bra, "Invalid instruction");
		
		_translate(cond);

		switch (bra.pg.condition)
		{
			case ir::PTXOperand::Pred:
			{
				ir::ILIfLogicalZ if_logicalz;
				if_logicalz.a = _translate(bra.pg);
				_add(if_logicalz);
				break;
			}
			case ir::PTXOperand::InvPred:
			{
				ir::ILIfLogicalNZ if_logicalnz;
				if_logicalnz.a = _translate(bra.pg);
				_add(if_logicalnz);
				break;
			}
			default: assertM(false, "Invalid predicate condition");

		}

		_translate(ifthenelse->ifTrue());

		_add(ir::ILElse());
		_translate(ifthenelse->ifFalse());

		_add(ir::ILEndIf());
	}

	ir::PTXInstruction* getLastIns(const ControlTree::Node* node)
	{
		switch (node->rtype())
		{
			case ControlTree::Node::Inst:
			{
				const ControlTree::InstNode* inode = 
					static_cast<const ControlTree::InstNode*>(node);

				return static_cast<ir::PTXInstruction*>(
						inode->bb()->instructions.back());
			}
			case ControlTree::Node::Block:
			{
				const ControlTree::BlockNode* bnode =
					static_cast<const ControlTree::BlockNode*>(node);

				return getLastIns(bnode->children().back());
			}
			default: assertM(false, "Invalid region type " << node->rtype());
		}
	}

	void PTXToILTranslator::_translate(const ControlTree::SelfLoopNode* selfloop)
	{
		_add(ir::ILWhileLoop());

		const ControlTree::Node* body = selfloop->body();
		_translate(body);

		// the last instruction of the body of a SeflLoop should be a branch
		// we need to translate that branch into an if_logicalz instruction
		ir::PTXInstruction* ins = getLastIns(body);
		assertM(ins->opcode == ir::PTXInstruction::Bra, "Invalid instruction");

		ir::ILIfLogicalZ if_logicalz;
		if_logicalz.a = _translate(ins->pg);
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
 			case ir::PTXInstruction::Abs:   _translateAbs(i);  break;
 			case ir::PTXInstruction::Add:   _translateAdd(i);  break;
			case ir::PTXInstruction::And:   _translateAnd(i);  break;
			case ir::PTXInstruction::Atom:  _translateAtom(i); break;
			case ir::PTXInstruction::Bar:   _translateBar(i);  break;
			case ir::PTXInstruction::Bra:   _translateBra(i);  break;
 			case ir::PTXInstruction::Cvt:   _translateCvt(i);  break;
			case ir::PTXInstruction::Div:   _translateDiv(i);  break;
			case ir::PTXInstruction::Ex2:   _translateEx2(i);  break;
 			case ir::PTXInstruction::Exit:  _translateExit(i); break;
 			case ir::PTXInstruction::Ld:    _translateLd(i);   break;
			case ir::PTXInstruction::Lg2:   _translateLg2(i);  break;
			case ir::PTXInstruction::Mad:   _translateMad(i);  break;
			case ir::PTXInstruction::Max:   _translateMax(i);  break;
			case ir::PTXInstruction::Min:   _translateMin(i);  break;
			case ir::PTXInstruction::Mov:   _translateMov(i);  break;
 			case ir::PTXInstruction::Mul:   _translateMul(i);  break;
			case ir::PTXInstruction::Mul24: _translateMul(i);  break;
			case ir::PTXInstruction::Neg:   _translateNeg(i);  break;
			case ir::PTXInstruction::Not:   _translateNot(i);  break;
			case ir::PTXInstruction::Or:    _translateOr(i);   break;
			case ir::PTXInstruction::Rcp:   _translateRcp(i);  break;
			case ir::PTXInstruction::Rem:   _translateRem(i);  break;
			case ir::PTXInstruction::SelP:  _translateSelP(i); break;
			case ir::PTXInstruction::Set:   _translateSet(i);  break;
			case ir::PTXInstruction::SetP:  _translateSetP(i); break;
			case ir::PTXInstruction::Shl:   _translateShl(i);  break;
			case ir::PTXInstruction::Shr:   _translateShr(i);  break;
 			case ir::PTXInstruction::St:    _translateSt(i);   break;
			case ir::PTXInstruction::Sub:   _translateSub(i);  break;
			case ir::PTXInstruction::Xor:   _translateXor(i);  break;
			default:
			{
				assertM(false, "Opcode \""
						<< i.toString()
						<< "\" not supported");
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
			case ir::PTXOperand::BitBucket:
			{
				op.addressMode = ir::ILOperand::Register;
				op.identifier = _translate(o.reg);
				break;
			}
			case ir::PTXOperand::Immediate:
			{
				switch (o.type)
				{
					case ir::PTXOperand::s32:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::u64:
					case ir::PTXOperand::b8:
					{
						//TODO Need to check for out-of-range literals
						op = _translateLiteral((int)o.imm_uint);
						break;
					}
					case ir::PTXOperand::f32:
					{
						op = _translateLiteral((float)o.imm_float);
						break;
					}
					default:
					{
						assertM(false, "Immediate operand type \""
							   << ir::PTXOperand::toString(o.type) 
							   << "\" not supported");
					}
				}
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
						<< o.toString(o.addressMode) << " not supported");
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
		assertM(reg < 1000, "Register name " << reg 
				<< " collides with temp registers");

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
			default: assertM(false, "Special Register " 
							 << ir::PTXOperand::toString(s) 
							 << " not supported");
		}

		return sr;
	}

	void PTXToILTranslator::_translateAbs(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::s32:
			{
				// There's no abs IL instruction for integers so we need
				// to use logical operations
				// mov r0x, i.a
				// mov r1x, 31
				// ishr r1x, r0x, r1x
				// iadd r0x, r0x, r1x
				// ixor r0x, r0x, r1x
				// mov i.d, r0x

				ir::ILOperand r0x = _tempRegister();
				ir::ILOperand r1x = _tempRegister();

				// mov r0x, i.a
				{
					ir::ILMov mov;
					mov.d = r0x; mov.a = _translate(i.a);
					_add(mov);
				}

				// mov r1x, 31
				{
					ir::ILMov mov;
					mov.d = r1x; mov.a = _translateLiteral(31);
					_add(mov);
				}

				// ishr r1x, r0x, r1x
				{
					ir::ILIshr ishr;
					ishr.d = r1x; ishr.a = r0x; ishr.b = r1x;
					_add(ishr);
				}

				// iadd r0x, r0x, r1x
				{
					ir::ILIadd iadd;
					iadd.d = r0x; iadd.a = r0x; iadd.b = r1x;
					_add(iadd);
				}

				// ixor r0x, r0x, r1x
				{
					ir::ILIxor ixor;
					ixor.d = r0x; ixor.a = r0x; ixor.b = r1x;
					_add(ixor);
				}

				// mov i.d, r0x
				{
					ir::ILMov mov;
					mov.d = _translate(i.d); mov.a = r0x;
					_add(mov);
				}

				break;
			}
			case ir::PTXOperand::f32:
			{
				ir::ILAbs abs;

				abs.d = _translate(i.d);
				abs.a = _translate(i.a);

				_add(abs);

				break;
			}
			default:
			{
				assertM(false, "Type "
						<< ir::PTXOperand::toString(i.type)
						<< " not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateAdd(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::s32:
			case ir::PTXOperand::s64:
			case ir::PTXOperand::u16:
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
						<< " not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateAnd(const ir::PTXInstruction &i)
	{
		ir::ILIand iand;

		iand.a = _translate(i.a);
		iand.b = _translate(i.b);
		iand.d = _translate(i.d);

		_add(iand);

	}

	void PTXToILTranslator::_translateAtom(const ir::PTXInstruction& i)
	{
		switch(i.addressSpace)
		{
			case ir::PTXInstruction::Global:
			{
				switch(i.atomicOperation)
				{
					case ir::PTXInstruction::AtomicAdd:
					{
						assertM(i.a.offset == 0, 
								"Atomic Add from offset not supported");

						ir::ILUav_Read_Add_Id uav_read_add_id;

						uav_read_add_id.d = _translate(i.d);
						uav_read_add_id.a = _translate(i.a);
						uav_read_add_id.b = _translate(i.b);

						_add(uav_read_add_id);

						break;
					}
					case ir::PTXInstruction::AtomicExch:
					{
						assertM(i.a.offset == 0, 
								"Atomic Xchg from offset not supported");

						ir::ILUav_Read_Xchg_Id uav_read_xchg_id;

						uav_read_xchg_id.d = _translate(i.d);
						uav_read_xchg_id.a = _translate(i.a);
						uav_read_xchg_id.b = _translate(i.b);

						_add(uav_read_xchg_id);

						break;
					}
					case ir::PTXInstruction::AtomicMax:
					{
						assertM(i.a.offset == 0, 
								"Atomic Max from offset not supported");

						ir::ILUav_Read_Max_Id uav_read_max_id;

						uav_read_max_id.d = _translate(i.d);
						uav_read_max_id.a = _translate(i.a);
						uav_read_max_id.b = _translate(i.b);

						_add(uav_read_max_id);

						break;
					}
					case ir::PTXInstruction::AtomicMin:
					{
						assertM(i.a.offset == 0, 
								"Atomic Min from offset not supported");

						ir::ILUav_Read_Min_Id uav_read_min_id;

						uav_read_min_id.d = _translate(i.d);
						uav_read_min_id.a = _translate(i.a);
						uav_read_min_id.b = _translate(i.b);

						_add(uav_read_min_id);

						break;
					}
					default:
					{
						assertM(false, "Atomic operation \"" 
								<< i.toString(i.atomicOperation) 
								<< "\" not supported in "
								<< i.toString());
					}
				}
				break;
			}
			case ir::PTXInstruction::Shared:
			{
				switch(i.atomicOperation)
				{
					case ir::PTXInstruction::AtomicAdd:
					{
						assertM(i.a.offset == 0, 
								"Atomic Add from offset not supported");

						ir::ILLds_Read_Add_Resource lds_read_add_resource;

						lds_read_add_resource.d = _translate(i.d).x();
						lds_read_add_resource.a = _translate(i.a).x();
						lds_read_add_resource.b = _translate(i.b).x();

						_add(lds_read_add_resource);

						break;
					}
					default:
					{
						assertM(false, "Atomic operation \"" 
								<< i.atomicOperation 
								<< "\" not supported in "
								<< i.toString());
					}
				}
				break;
			}
			default:
			{
				assertM(false, "Address Space \"" 
						<< ir::PTXInstruction::toString(i.addressSpace)
						<< "\" not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateBar(const ir::PTXInstruction &i)
	{
		ir::ILFence fence;
		fence.threads();
		_add(fence);
	}

	void PTXToILTranslator::_translateBra(const ir::PTXInstruction &i)
	{
		// do nothing (bra instructions are handled using the control tree)
	}

	void PTXToILTranslator::_convertSrc(const ir::PTXInstruction &i)
	{
	}

	void PTXToILTranslator::_convert(const ir::PTXInstruction &i)
	{
		switch (i.a.type)
		{
			case ir::PTXOperand::s32:
			{
				switch (i.type)
				{
					case ir::PTXOperand::s64:
					{
						// sext
						ir::ILMov mov;
						mov.a = _translate(i.a);
						mov.d = _translate(i.d);
						_add(mov);
						return;
					}
					case ir::PTXOperand::u64:
					{
						// sext
						ir::ILMov mov;
						mov.a = _translate(i.a);
						mov.d = _translate(i.d);
						_add(mov);
						return;
					}
					default: break;
				}
				break;
			}
			case ir::PTXOperand::u16:
			{
				switch (i.type)
				{
					case ir::PTXOperand::s32:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::u64:
					{
						// zext
						ir::ILMov mov;
						mov.a = _translate(i.a);
						mov.d = _translate(i.d);
						_add(mov);
						return;
					}
					default: break;
				}
				break;
			}
			case ir::PTXOperand::u32:
			{
				switch (i.type)
				{
					case ir::PTXOperand::s64:
					case ir::PTXOperand::u64:
					{
						// zext
						ir::ILMov mov;
						mov.a = _translate(i.a);
						mov.d = _translate(i.d);
						_add(mov);
						return;
					}
					case ir::PTXOperand::f32:
					{
						// utof
						if(i.modifier & ir::PTXInstruction::rn)
						{
							ir::ILUtoF utof;
							utof.d = _translate(i.d);
							utof.a = _translate(i.a);
							_add(utof);
							return;
						}
						break;
					}
					default: break;
				}
				break;
			}
			case ir::PTXOperand::u64:
			{
				switch (i.type)
				{
					case ir::PTXOperand::u32:
					{
						// chop
						ir::ILMov mov;
						mov.a = _translate(i.a);
						mov.d = _translate(i.d);
						_add(mov);
						return;
					}
					default: break;
				}
				break;
			}
			default: break;
		}

		assertM(false, "Opcode \"" << i.toString() << "\" not supported");
	}

	void PTXToILTranslator::_convertDst(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::s32:
			{
				switch (i.d.type)
				{
					case ir::PTXOperand::u32:
					{
						// allowed, no conversion needed
						break;
					}
					default:
					{
						assertM(false,
								"Destination operand conversion from \""
								<< ir::PTXOperand::toString(i.type)
								<< "\" to \""
								<< ir::PTXOperand::toString(i.d.type)
								<< "\" not supported");
					}
				}
				break;
			}
			case ir::PTXOperand::s64:
			{
				switch (i.d.type)
				{
					case ir::PTXOperand::u64: break;
					default:
					{
						assertM(false,
								"Destination operand conversion from \""
								<< ir::PTXOperand::toString(i.type)
								<< "\" to \""
								<< ir::PTXOperand::toString(i.d.type)
								<< "\" not supported");
					}
				}
				break;
			}
			case ir::PTXOperand::u32:
			{
				switch (i.d.type)
				{
					case ir::PTXOperand::u32: break;
					default:
					{
						assertM(false,
								"Destination operand conversion from \""
								<< ir::PTXOperand::toString(i.type)
								<< "\" to \""
								<< ir::PTXOperand::toString(i.d.type)
								<< "\" not supported");
					}
				}
				break;
			}
			case ir::PTXOperand::u64:
			{
				switch (i.d.type)
				{
					case ir::PTXOperand::u64: break;
					default:
					{
						assertM(false,
								"Destination operand conversion from \""
								<< ir::PTXOperand::toString(i.type)
								<< "\" to \""
								<< ir::PTXOperand::toString(i.d.type)
								<< "\" not supported");
					}
				}
				break;
			}
			case ir::PTXOperand::f32:
			{
				switch (i.d.type)
				{
					case ir::PTXOperand::f32: break;
					default:
					{
						assertM(false,
								"Destination operand conversion from \""
								<< ir::PTXOperand::toString(i.type)
								<< "\" to \""
								<< ir::PTXOperand::toString(i.d.type)
								<< "\" not supported");
					}
				}
				break;
			}
			default:
			{
				assertM(false,
						"Destination operand conversion from \""
						<< ir::PTXOperand::toString(i.type)
						<< "\" to \""
						<< ir::PTXOperand::toString(i.d.type)
						<< "\" not supported");
			}
		}
	}

	void PTXToILTranslator::_translateCvt(const ir::PTXInstruction &i)
	{
		_convertSrc(i);
		_convert(i);
		_convertDst(i);
	}

	void PTXToILTranslator::_translateDiv(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::s32: _translateIDiv(i); break;
			case ir::PTXOperand::f32: _translateFDiv(i); break;
			default:
			{
				assertM(false, "Opcode \"" << i.toString()
						<< "\" not supported");
			}
		}
	}

	void PTXToILTranslator::_translateIDiv(const ir::PTXInstruction &i)
	{
		// There is no signed integer division in IL so we need to use this 
		// macro based on unsigned integer division:
		//
		// (w/o operand modifiers)                // (with operand modifiers)
		// out0 = in0 / in1
		// mdef(222)_out(1)_in(2)
		// mov r0x, i.a                           // mov r0, in0
		// mov r1x, i.b                           // mov r1, in1
		// mov r0y, r1x                           // mov r0._y__, r1.x
		// ilt r1x, r0x, 0                        // ilt r1.xy, r0, 0
		// ilt r1y, r0y, 0
		// iadd r0x, r0x, r1x                     // iadd r0.xy, r0, r1
		// iadd r0y, r0y, r1y
		// ixor r0x, r0x, r1x                     // ixor r0.xy, r0, r1
		// ixor r1y, r0y, r1y
		// udiv r0x, r0x, r0y                     // udiv r0.x, r0.x, r0.y
		// ixor r1x, r1x, r1y                     // ixor r1.x, r1.x, r1.y
		// iadd r0x, r0x, r1x                     // iadd r0.x, r0.x, r1.x
		// ixor r0x, r0x, r1x                     // ixor r0.x, r0.x, r1.x
		// mov i.d, r0x                           // mov out0, r0
		// mend

		ir::ILOperand r0x = _tempRegister();
		ir::ILOperand r0y = _tempRegister();
		ir::ILOperand r1x = _tempRegister();
		ir::ILOperand r1y = _tempRegister();

		// mov r0x, i.a
		ir::ILMov mov1;
		mov1.d = r0x; mov1.a = _translate(i.a);
		_add(mov1);

		// mov r1x, i.b
		ir::ILMov mov2;
		mov2.d = r1x; mov2.a = _translate(i.b);
		_add(mov2);

		// mov r0y, r1x
		ir::ILMov mov3;
		mov3.d = r0y; mov3.a = r1x;
		_add(mov3);

		// ilt r1x, r0x, 0
		ir::ILIlt ilt1;
		ilt1.d = r1x; ilt1.a = r0x; ilt1.b = _translateLiteral(0);
		_add(ilt1);

		// ilt r1y, r0y, 0
		ir::ILIlt ilt2;
		ilt2.d = r1y; ilt2.a = r0y; ilt2.b = _translateLiteral(0);
		_add(ilt2);

		// iadd r0x, r0x, r1x
		ir::ILIadd iadd1;
		iadd1.d = r0x; iadd1.a = r0x; iadd1.b = r1x;
		_add(iadd1);

		// iadd r0y, r0y, r1y
		ir::ILIadd iadd2;
		iadd2.d = r0y; iadd2.a = r0y; iadd2.b = r1y;
		_add(iadd2);

		// ixor r0x, r0x, r1x
		ir::ILIxor ixor1;
		ixor1.d = r0x; ixor1.a = r0x; ixor1.b = r1x;
		_add(ixor1);

		// ixor r1y, r0y, r1y
		ir::ILIxor ixor2;
		ixor2.d = r1y; ixor2.a = r0y; ixor2.b = r1y;
		_add(ixor2);

		// udiv r0x, r0x, r0y
		ir::ILUdiv udiv1;
		udiv1.d = r0x; udiv1.a = r0x; udiv1.b = r0y;
		_add(udiv1);

		// ixor r1x, r1x, r1y
		ir::ILIxor ixor3;
		ixor3.d = r1x; ixor3.a = r1x; ixor3.b = r1y;
		_add(ixor3);

		// iadd r0x, r0x, r1x
		ir::ILIadd iadd3;
		iadd3.d = r0x; iadd3.a = r0x; iadd3.b = r1x;
		_add(iadd3);

		// ixor r0x, r0x, r1x
		ir::ILIxor ixor4;
		ixor4.d = r0x; ixor4.a = r0x; ixor4.b = r1x;
		_add(ixor4);

		// mov i.d, r0x
		ir::ILMov mov4;
		mov4.d = _translate(i.d); mov4.a = r0x;
		_add(mov4);
	}

	void PTXToILTranslator::_translateFDiv(const ir::PTXInstruction &i)
	{
		ir::ILDiv div;

		div.d = _translate(i.d);
		div.a = _translate(i.a);
		div.b = _translate(i.b);

		_add(div);
	}

	void PTXToILTranslator::_translateEx2(const ir::PTXInstruction &i)
	{
		ir::ILExp exp;

		exp.d = _translate(i.d);
		exp.a = _translate(i.a);

		_add(exp);
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
			case ir::PTXInstruction::Const:
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
						assertM(false, "Vector operation " << i.vec 
								<< " not supported");
					}
				}
				break;
			}
			case ir::PTXInstruction::Shared:
			{
				switch (i.vec)
				{
					case ir::PTXOperand::v1:
					{
						switch (ir::PTXOperand::bytes(i.type))
						{
							case 1: _translateLdSharedByte(i);  break;
							case 4: _translateLdSharedDword(i); break;
							default:
							{
								assertM(false, "Less-than-32-bits memory "
										" operation not supported");
							}
						}
						break;
					}
					case ir::PTXOperand::v2:
					case ir::PTXOperand::v4:
					{
						assertM(ir::PTXOperand::bytes(i.type) == 4,
								"Less-than-32-bits memory operation "
								"not supported");

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

							ir::ILLds_Load_Id lds_load_id;
							lds_load_id.a = temp;
							lds_load_id.d = _translate(*dst);
							_add(lds_load_id);

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
				assertM(false, "Address Space not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateLdSharedByte(const ir::PTXInstruction &i)
	{
		// LDS is byte-addressable and the result of a load is a dword. 
		// However, the two least significant bits of the address must be set to 
		// zero. Therefore, we need to extract the correct byte from the dword:
		//
		// and temp1, i.a, 3
		// imul temp1, temp1, 8
		// and temp2, i.a, 0xFFFFFFFC
		// lds_load_id(1) i.d, temp2
		// ishr i.d, i.d, temp1
		// ishl i.d, i.d, 24
		// ishr i.d, i.d, 24
		
		assertM(i.a.offset == 0, "Ld Shared Byte from offset not supported");

		ir::ILOperand temp1 = _tempRegister();
		ir::ILOperand temp2 = _tempRegister();

		// get the two lsb's of the address.
		ir::ILAnd iland1;
		iland1.d = temp1;
		iland1.a = _translate(i.a);
		iland1.b = _translateLiteral(3);
		_add(iland1);

		// calculate the offset inside the dword
		ir::ILImul imul;
		imul.d = temp1;
		imul.a = temp1;
		imul.b = _translateLiteral(8);
		_add(imul);

		// set the two lsb's of the address to zero
		ir::ILAnd iland2;
		iland2.d = temp2;
		iland2.a = _translate(i.a);
		iland2.b = _translateLiteral((int)0xFFFFFFFC);
		_add(iland2);

		// load dword
		ir::ILLds_Load_Id lds_load_id;
		lds_load_id.d = _translate(i.d);
		lds_load_id.a = temp2;
		_add(lds_load_id);

		// extract the correct byte from the dword
		ir::ILIshr ishr1;
		ishr1.d = _translate(i.d);
		ishr1.a = _translate(i.d);
		ishr1.b = temp1;
		_add(ishr1);

		ir::ILIshl ishl;
		ishl.d = _translate(i.d);
		ishl.a = _translate(i.d);
		ishl.b = _translateLiteral(24);
		_add(ishl);

		ir::ILIshr ishr2;
		ishr2.d = _translate(i.d);
		ishr2.a = _translate(i.d);
		ishr2.b = _translateLiteral(24);
		_add(ishr2);
	}

	void PTXToILTranslator::_translateLdSharedDword(const ir::PTXInstruction &i)
	{
		if (i.a.offset == 0)
		{
			ir::ILLds_Load_Id lds_load_id;
			lds_load_id.a = _translate(i.a);
			lds_load_id.d = _translate(i.d);
			_add(lds_load_id);
		} else
		{
			ir::ILOperand temp = _tempRegister();

			ir::ILIadd iadd;
			iadd.a = _translate(i.a);
			iadd.b = _translateLiteral(i.a.offset);
			iadd.d = temp;
			_add(iadd);

			ir::ILLds_Load_Id lds_load_id;
			lds_load_id.a = temp;
			lds_load_id.d = _translate(i.d);
			_add(lds_load_id);
		}
	}

	void PTXToILTranslator::_translateLg2(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::f32:
			{
				ir::ILLog_Vec log_vec;

				log_vec.d = _translate(i.d);
				log_vec.a = _translate(i.a);

				_add(log_vec);

				break;
			}
			default:
			{
				assertM(false, "Type "
						<< ir::PTXOperand::toString(i.type)
						<< " not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateMad(const ir::PTXInstruction &i)
	{
		ir::ILMad mad;

		mad.a = _translate(i.a);
		mad.b = _translate(i.b);
		mad.c = _translate(i.c);
		mad.d = _translate(i.d);

		_add(mad);
	}

	void PTXToILTranslator::_translateMax(const ir::PTXInstruction &i)
	{
		ir::ILImax imax;

		imax.d = _translate(i.d);
		imax.a = _translate(i.a);
		imax.b = _translate(i.b);

		_add(imax);
	}

	void PTXToILTranslator::_translateMin(const ir::PTXInstruction &i)
	{
		ir::ILImin imin;

		imin.d = _translate(i.d);
		imin.a = _translate(i.a);
		imin.b = _translate(i.b);

		_add(imin);
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
		switch (i.type)
		{
			case ir::PTXOperand::s32:
			{
				ir::ILImul imul;

				imul.a = _translate(i.a);
				imul.b = _translate(i.b);
				imul.d = _translate(i.d);

				_add(imul);

				break;
			}
			case ir::PTXOperand::u16:
			case ir::PTXOperand::u32:
			case ir::PTXOperand::u64:
			{
				ir::ILUmul umul;

				umul.a = _translate(i.a);
				umul.b = _translate(i.b);
				umul.d = _translate(i.d);

				_add(umul);

				break;
			}
			case ir::PTXOperand::f32:
			{
				ir::ILMul mul;

				mul.a = _translate(i.a);
				mul.b = _translate(i.b);
				mul.d = _translate(i.d);

				_add(mul);

				break;
			}
			default:
			{
				assertM(false, "Type "
						<< ir::PTXOperand::toString(i.type)
						<< " not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateNeg(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::s32:
			{
				ir::ILInegate inegate;

				inegate.a = _translate(i.a);
				inegate.d = _translate(i.d);

				_add(inegate);

				break;
			}
			case ir::PTXOperand::f32:
			{
				ir::ILMov mov;

				mov.d = _translate(i.d);
				mov.a = _translate(i.a).neg();

				_add(mov);

				break;
			}
			default:
			{
				assertM(false, "Type "
						<< ir::PTXOperand::toString(i.type)
						<< " not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateNot(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::b32:
			{
				ir::ILInot inot;

				inot.d = _translate(i.d);
				inot.a = _translate(i.a);

				_add(inot);

				break;
			}
			default:
			{
				assertM(false, "Type "
						<< ir::PTXOperand::toString(i.type)
						<< " not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateOr(const ir::PTXInstruction &i)
	{
		ir::ILIor ior;

		ior.a = _translate(i.a);
		ior.b = _translate(i.b);
		ior.d = _translate(i.d);

		_add(ior);
	}

	void PTXToILTranslator::_translateRcp(const ir::PTXInstruction &i)
	{
		// rcp operates on the fourth (w) component of a
		ir::ILRcp rcp;

		rcp.d = _translate(i.d);
		rcp.a = _translate(i.a).xxxx();

		_add(rcp);
	}

	void PTXToILTranslator::_translateRem(const ir::PTXInstruction &i)
	{
		assertM(i.type == ir::PTXOperand::s32, "Type " 
				<< ir::PTXOperand::toString(i.type) << " not supported");

		// out0 = in0 % in1
		// mdef(285)_out(1)_in(2)
		// mov r0, in0
		// mov r1, in1
		// dcl_literal l25, 0, 0, 0, 0
		// mov r0._y__, r1.x
		// ilt r1.xy, r0, l25
		// iadd r0.xy, r0, r1
		// ixor r0.xy, r0, r1
		// udiv r2.x, r0.x, r0.y
		// umul r2.x, r2.x, r0.y
		// iadd r0.x, r0.x, r2.x_neg(xyzw)
		// iadd r0.x, r0.x, r1.x
		// ixor r0.x, r0.x, r1.x
		// mov out0, r0
		// mend
		
		ir::ILOperand r0 = _tempRegister();
		ir::ILOperand r1 = _tempRegister();
		ir::ILOperand r2 = _tempRegister();

		// mov r0, in0
		{
			ir::ILMov mov;
			mov.d = r0; mov.a = _translate(i.a);
			_add(mov);
		}

		// mov r1, in1
		{
			ir::ILMov mov;
			mov.d = r1; mov.a = _translate(i.b);
			_add(mov);
		}

		// dcl_literal l25, 0, 0, 0, 0
		ir::ILOperand l25 = _translateLiteral(0);

		// mov r0._y__, r1.x
		{
			ir::ILMov mov;
			mov.d = r0._y__(); mov.a = r1.x();
			_add(mov);
		}

		// ilt r1.xy, r0, l25
		{
			ir::ILIlt ilt;
			ilt.d = r1.xy(); ilt.a = r0; ilt.b = l25;
			_add(ilt);
		}

		// iadd r0.xy, r0, r1
		{
			ir::ILIadd iadd;
			iadd.d = r0.xy(); iadd.a = r0; iadd.b = r1;
			_add(iadd);
		}

		// ixor r0.xy, r0, r1
		{
			ir::ILIxor ixor;
			ixor.d = r0.xy(); ixor.a = r0; ixor.b = r1;
			_add(ixor);
		}

		// udiv r2.x, r0.x, r0.y
		{
			ir::ILUdiv udiv;
			udiv.d = r2.x(); udiv.a = r0.x(); udiv.b = r0.y();
			_add(udiv);
		}

		// umul r2.x, r2.x, r0.y
		{
			ir::ILUmul umul;
			umul.d = r2.x(); umul.a = r2.x(); umul.b = r0.y();
			_add(umul);
		}

		// iadd r0.x, r0.x, r2.x_neg(xyzw)
		{
			ir::ILIadd iadd;
			iadd.d = r0.x(); iadd.a = r0.x(); iadd.b = r2.x().neg();
			_add(iadd);
		}

		// iadd r0.x, r0.x, r1.x
		{
			ir::ILIadd iadd;
			iadd.d = r0.x(); iadd.a = r0.x(); iadd.b = r1.x();
			_add(iadd);
		}

		// ixor r0.x, r0.x, r1.x
		{
			ir::ILIxor ixor;
			ixor.d = r0.x(); ixor.a = r0.x(); ixor.b = r1.x();
			_add(ixor);
		}

		// mov out0, r0
		{
			ir::ILMov mov;
			mov.d = _translate(i.d); mov.a = r0;
			_add(mov);
		}
	}

	void PTXToILTranslator::_translateSelP(const ir::PTXInstruction &i)
	{
		// Note that IL semantic is cmov_logical dest, pred, iftrue, iffalse
		// while PTX is selp dest, iftrue, iffalse, pred.
		ir::ILCmov_Logical cmov_logical;

		cmov_logical.d = _translate(i.d);
		cmov_logical.a = _translate(i.c);
		cmov_logical.b = _translate(i.a);
		cmov_logical.c = _translate(i.b);

		_add(cmov_logical);
	}

	void PTXToILTranslator::_translateSet(const ir::PTXInstruction &i)
	{
		// In IL there's no difference between predicate and normal registers
		_translateSetP(i);
	}

	void PTXToILTranslator::_translateSetP(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::s32:
			case ir::PTXOperand::u32:
			case ir::PTXOperand::u64: _translateISetP(i); break;
			case ir::PTXOperand::f32: _translateFSetP(i); break;
			default:
			{
				assertM(false, "Opcode \"" << i.toString()
						<< "\" not supported");
			}
		}
	}

	void PTXToILTranslator::_translateISetP(const ir::PTXInstruction &i)
	{
		switch (i.comparisonOperator)
		{
			case ir::PTXInstruction::Eq:
			{
				ir::ILIeq ieq;

				ieq.a = _translate(i.a);
				ieq.b = _translate(i.b);
				ieq.d = _translate(i.d);

				_add(ieq);

				break;
			}
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
			case ir::PTXInstruction::Ge:
			{
				ir::ILIge ige;

				ige.a = _translate(i.a);
				ige.b = _translate(i.b);
				ige.d = _translate(i.d);

				_add(ige);

				break;
			}
			case ir::PTXInstruction::Ne:
			{
				ir::ILIne ine;

				ine.a = _translate(i.a);
				ine.b = _translate(i.b);
				ine.d = _translate(i.d);

				_add(ine);

				break;
			}
			case ir::PTXInstruction::Gt:
			{
				// IL doesn't have gt but it has lt so switch a & b operands
				ir::ILIlt ilt;

				ilt.a = _translate(i.b);
				ilt.b = _translate(i.a);
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

	void PTXToILTranslator::_translateFSetP(const ir::PTXInstruction &i)
	{
		switch (i.comparisonOperator)
		{
			case ir::PTXInstruction::Lt:
			{
				ir::ILLt lt;

				lt.a = _translate(i.a);
				lt.b = _translate(i.b);
				lt.d = _translate(i.d);

				_add(lt);

				break;
			}
			case ir::PTXInstruction::Gt:
			{
				// IL doesn't have gt but it has lt so switch a & b operands
				ir::ILLt lt;

				lt.a = _translate(i.b);
				lt.b = _translate(i.a);
				lt.d = _translate(i.d);

				_add(lt);

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

	void PTXToILTranslator::_translateShl(const ir::PTXInstruction &i)
	{
		assertM(i.type == ir::PTXOperand::b32, 
				"Type " << ir::PTXOperand::toString(i.type) << " not supported");

		ir::ILIshl ishl;

		ishl.a = _translate(i.a);
		ishl.b = _translate(i.b);
		ishl.d = _translate(i.d);

		_add(ishl);
	}

	void PTXToILTranslator::_translateShr(const ir::PTXInstruction &i)
	{
		switch (i.type)
		{
			case ir::PTXOperand::s32:
			{
				ir::ILIshr ishr;

				ishr.a = _translate(i.a);
				ishr.b = _translate(i.b);
				ishr.d = _translate(i.d);

				_add(ishr);

				break;
			}
			case ir::PTXOperand::u32:
			{
				ir::ILUshr ushr;

				ushr.a = _translate(i.a);
				ushr.b = _translate(i.b);
				ushr.d = _translate(i.d);

				_add(ushr);

				break;
			}
			default:
			{
				assertM(false, "Type "
						<< ir::PTXOperand::toString(i.type)
						<< " not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateSt(const ir::PTXInstruction &i)
	{
		switch (i.addressSpace)
		{
			case ir::PTXInstruction::Global:
			{
				assertM(i.volatility != ir::PTXInstruction::Volatile,
						"Volatile global store operation not supported yet in " 
						<< i.toString());

				// TODO uav0 accesses should be aligned to 4
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
						assertM(false, "Vector operation " << i.vec 
								<< " not supported");
					}
				}
				break;
			}
			case ir::PTXInstruction::Shared:
			{
				switch (i.vec)
				{
					case ir::PTXOperand::v1:
					{
						switch(ir::PTXOperand::bytes(i.type))
						{
							case 1: _translateStSharedByte(i);  break;
							case 4: _translateStSharedDword(i); break;
							default:
							{
								assertM(false, "Less-than-32-bits memory "
										"operation not supported");
							}
						}
						break;
					}
					case ir::PTXOperand::v2:
					case ir::PTXOperand::v4:
					{
						assertM(ir::PTXOperand::bytes(i.type) == 4,
								"Less-than-32-bits memory operation "
								"not supported");

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

							ir::ILLds_Store_Id lds_store_id;
							lds_store_id.a = _translate(*src);
							lds_store_id.d = temp;
							_add(lds_store_id);

							offset += ir::PTXOperand::bytes(i.type);
						}
						break;
					}
					default:
					{
						assertM(false, "Vector operation " << i.vec 
								<< " not supported");
					}
				}

				// if volatile add fence after the store
				if (i.volatility == ir::PTXInstruction::Volatile)
				{
					ir::ILFence fence;
					fence.threads(false);
					fence.lds(true);
					_add(fence);
				}

				break;
			}
			default:
			{
				assertM(false, "Address Space " << i.addressSpace 
						<< " not supported");
			}
		}
	}

	void PTXToILTranslator::_translateStSharedByte(const ir::PTXInstruction& i)
	{
		// LDS is byte-addressable but the result of a store is a dword. 
		// Therefore, we need to merge the byte with the dword:
		//
		// and temp1, i.a, 0x000000FF
		// and temp2, i.d, 3
		// iadd temp3X, temp2, 0
		// iadd temp3Y, temp2, -1
		// iadd temp3Z, temp2, -2
		// iadd temp3W, temp2, -3
		// imul temp4, temp2, 8
		// cmov_logical temp5, temp3W, 0xFFFFFF00, 0x00FFFFFF
		// cmov_logical temp5, temp3Z, temp5, 0xFF00FFFF
		// cmov_logical temp5, temp3Y, temp5, 0xFFFF00FF
		// ishl temp2, temp1, temp4
		// lds_and_resource(1) i.d, temp5
		// lds_or_resource(1) i.d, temp2

		assertM(i.a.offset == 0, "St Shared Byte from offset not supported");

		ir::ILOperand temp1  = _tempRegister();
		ir::ILOperand temp2  = _tempRegister();
		ir::ILOperand temp3X = _tempRegister();
		ir::ILOperand temp3Y = _tempRegister();
		ir::ILOperand temp3Z = _tempRegister();
		ir::ILOperand temp3W = _tempRegister();
		ir::ILOperand temp4  = _tempRegister();
		ir::ILOperand temp5  = _tempRegister();

		// set the value to a byte
		ir::ILAnd iland1;
		iland1.d = temp1;
		iland1.a = _translate(i.a);
		iland1.b = _translateLiteral((int)0x000000FF);
		_add(iland1);

		// get the two lsb's of the address.
		ir::ILAnd iland2;
		iland2.d = temp2;
		iland2.a = _translate(i.d);
		iland2.b = _translateLiteral(3);
		_add(iland2);

		// calculate the mask to merge with the dword
		ir::ILIadd iaddX,iaddY, iaddZ, iaddW;
		iaddX.d = temp3X; iaddY.d = temp3Y; iaddZ.d = temp3Z; iaddW.d = temp3W;
		iaddX.a = iaddY.a = iaddZ.a = iaddW.a = temp2;
		iaddX.b = _translateLiteral(0);
		iaddY.b = _translateLiteral(-1);
		iaddZ.b = _translateLiteral(-2);
		iaddW.b = _translateLiteral(-3);
		_add(iaddX); _add(iaddY); _add(iaddZ); _add(iaddW);

		// calculate the offset inside the dword
		ir::ILImul imul;
		imul.d = temp4;
		imul.a = temp2;
		imul.b = _translateLiteral(8);
		_add(imul);

		ir::ILCmov_Logical cmov_logical1;
		cmov_logical1.d = temp5;
		cmov_logical1.a = temp3W;
		cmov_logical1.b = _translateLiteral((int)0xFFFFFF00);
		cmov_logical1.c = _translateLiteral((int)0x00FFFFFF);
		_add(cmov_logical1);

		ir::ILCmov_Logical cmov_logical2;
		cmov_logical2.d = temp5;
		cmov_logical2.a = temp3Z;
		cmov_logical2.b = temp5;
		cmov_logical2.c = _translateLiteral((int)0xFF00FFFF);
		_add(cmov_logical2);

		ir::ILCmov_Logical cmov_logical3;
		cmov_logical3.d = temp5;
		cmov_logical3.a = temp3Y;
		cmov_logical3.b = temp5;
		cmov_logical3.c = _translateLiteral((int)0xFFFF00FF);
		_add(cmov_logical3);

		ir::ILIshl ishl;
		ishl.d = temp2;
		ishl.a = temp1;
		ishl.b = temp4;
		_add(ishl);

		ir::ILLds_And_Resource lds_and_resource;
		lds_and_resource.d = _translate(i.d);
		lds_and_resource.a = temp5;
		_add(lds_and_resource);

		ir::ILLds_Or_Resource lds_or_resource;
		lds_or_resource.d = _translate(i.d);
		lds_or_resource.a = temp2;
		_add(lds_or_resource);
	}

	void PTXToILTranslator::_translateStSharedDword(const ir::PTXInstruction& i)
	{
		if (i.d.offset == 0)
		{
			ir::ILLds_Store_Id lds_store_id;
			lds_store_id.a = _translate(i.a);
			lds_store_id.d = _translate(i.d);
			_add(lds_store_id);
		} else
		{
			ir::ILOperand temp = _tempRegister();

			ir::ILIadd iadd;
			iadd.a = _translate(i.d);
			iadd.b = _translateLiteral(i.d.offset);
			iadd.d = temp;
			_add(iadd);

			ir::ILLds_Store_Id lds_store_id;
			lds_store_id.a = _translate(i.a);
			lds_store_id.d = temp;
			_add(lds_store_id);
		}
	}

	void PTXToILTranslator::_translateSub(const ir::PTXInstruction& i)
	{
		// There's no sub instruction in IL so we need to use add
		switch (i.type)
		{
			case ir::PTXOperand::s32:
			case ir::PTXOperand::u32:
			{
				switch (i.b.addressMode)
				{
					case ir::PTXOperand::Immediate:
					{
						ir::ILIadd iadd;
						ir::PTXOperand b;

						b.addressMode = ir::PTXOperand::Immediate;
						b.imm_int = -1 * i.b.imm_int;

						iadd.d = _translate(i.d);
						iadd.a = _translate(i.a);
						iadd.b = _translate(b);

						_add(iadd);

						break;
					}
					case ir::PTXOperand::Register:
					{
						ir::ILOperand temp = _tempRegister();

						ir::ILInegate inegate;
						inegate.d = temp;
						inegate.a = _translate(i.b);
						_add(inegate);

						ir::ILIadd iadd;
						iadd.d = _translate(i.d);
						iadd.a = _translate(i.a);
						iadd.b = temp;
						_add(iadd);

						break;
					}
					default:
					{
						assertM(i.b.addressMode == ir::PTXOperand::Immediate,
								"Subtract operation not supported");
					}
				}
				break;
			}
			case ir::PTXOperand::f32:
			{
				ir::ILSub sub;

				sub.a = _translate(i.a);
				sub.b = _translate(i.b);
				sub.d = _translate(i.d);

				_add(sub);

				break;
			}
			default:
			{
				assertM(false, "Type "
						<< ir::PTXOperand::toString(i.type)
						<< " not supported in "
						<< i.toString());
			}
		}
	}

	void PTXToILTranslator::_translateXor(const ir::PTXInstruction& i)
	{
		ir::ILIxor ixor;

		ixor.a = _translate(i.a);
		ixor.b = _translate(i.b);
		ixor.d = _translate(i.d);

		_add(ixor);
	}

	ir::ILOperand PTXToILTranslator::_translateLiteral(int l)
	{
		std::stringstream stream;

		const ILiteralMap::const_iterator it = _intLiterals.find(l);
		if (it != _intLiterals.end()) {
			stream << it->second;
		} else {
			stream << "l" << _intLiterals.size() + _floatLiterals.size();
			_intLiterals.insert(std::make_pair(l, stream.str()));
		}

		ir::ILOperand op;
		op.addressMode = ir::ILOperand::Literal;
		op.identifier = stream.str();

		return op;
	}

	ir::ILOperand PTXToILTranslator::_translateLiteral(float l)
	{
		std::stringstream stream;

		const FLiteralMap::const_iterator it = _floatLiterals.find(l);
		if (it != _floatLiterals.end()) {
			stream << it->second;
		} else {
			stream << "l" << _intLiterals.size() + _floatLiterals.size();
			_floatLiterals.insert(std::make_pair(l, stream.str()));
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
		if (_intLiterals.size() > 0) {
			ILiteralMap::const_iterator it;
			for (it = _intLiterals.begin() ; it != _intLiterals.end() ; it++) 
			{
				ir::ILStatement dcl_literal(ir::ILStatement::LiteralDcl);

				dcl_literal.operands.resize(2);
				dcl_literal.operands[0].identifier = it->second;
				dcl_literal.operands[0].addressMode = ir::ILOperand::Literal;

				dcl_literal.operands[1].imm_int = it->first;
				dcl_literal.operands[1].addressMode = ir::ILOperand::Immediate;
				dcl_literal.operands[1].type = ir::ILOperand::I32;

				_ilKernel->_statements.push_front(dcl_literal);

				report("Added statement \"" << dcl_literal.toString() << "\"");
			}
		}

		if (_floatLiterals.size() > 0) {
			FLiteralMap::const_iterator it;
			for (it = _floatLiterals.begin() ; it != _floatLiterals.end() ; it++) 
			{
				ir::ILStatement dcl_literal(ir::ILStatement::LiteralDcl);

				dcl_literal.operands.resize(2);
				dcl_literal.operands[0].identifier = it->second;
				dcl_literal.operands[0].addressMode = ir::ILOperand::Literal;

				dcl_literal.operands[1].imm_float = it->first;
				dcl_literal.operands[1].addressMode = ir::ILOperand::Immediate;
				dcl_literal.operands[1].type = ir::ILOperand::F32;

				_ilKernel->_statements.push_front(dcl_literal);

				report("Added statement \"" << dcl_literal.toString() << "\"");
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
		stream << "cb0[2]";
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
