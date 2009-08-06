/*!
	\file PTXToLLVMTranslator.cpp
	\date Wednesday July 29, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the PTXToLLVMTranslator class
	\comment : Written with subdued haste
*/

#ifndef PTX_TO_LLVM_TRANSLATOR_CPP_INCLUDED
#define PTX_TO_LLVM_TRANSLATOR_CPP_INCLUDED

#include <ocelot/translator/interface/PTXToLLVMTranslator.h>
#include <ocelot/ir/interface/LLVMInstruction.h>
#include <ocelot/ir/interface/LLVMKernel.h>
#include <ocelot/ir/interface/PTXInstruction.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace translator
{
	ir::LLVMInstruction::Operand 
		PTXToLLVMTranslator::_translate( const ir::PTXOperand& o )
	{
		ir::LLVMInstruction::Operand op( o.identifier, 
			o.addressMode == ir::PTXOperand::Immediate );
		
		switch( o.addressMode )
		{
			case ir::PTXOperand::Register: /* fall through */
			case ir::PTXOperand::Indirect:
			{
				std::stringstream stream;
				stream << "$r" << o.reg;
				op.name = stream.str();
				break;
			}
			case ir::PTXOperand::Immediate:
			{
				switch( o.type )
				{
					case ir::PTXOperand::s8: /* fall through */
					case ir::PTXOperand::s16: /* fall through */
					case ir::PTXOperand::s32: /* fall through */
					case ir::PTXOperand::s64: /* fall through */
					case ir::PTXOperand::u8: /* fall through */
					case ir::PTXOperand::u16: /* fall through */
					case ir::PTXOperand::u32: /* fall through */
					case ir::PTXOperand::u64:
					{
						op.i64 = o.imm_uint;
						break;
					}
					case ir::PTXOperand::f32:
					{
						op.f32 = o.imm_float;
						break;
					}
					case ir::PTXOperand::f64:
					{
						op.f64 = o.imm_float;
						break;
					}
					default:
					{
						throw Exception( "PTXOperand datatype " 
							+ ir::PTXOperand::toString( o.type ) 
							+ " not supported for immediate operand." );
					}				
				}
				break;
			}
			case ir::PTXOperand::Address:
			{
				break;
			}
			case ir::PTXOperand::Label:
			{
				throw Exception( "PTXOperand datatype " 
					+ ir::PTXOperand::toString( o.type ) 
					+ " not supported." );
				break;
			}
			case ir::PTXOperand::Special:
			{
				op.name = ir::PTXOperand::toString( o.special );
			}
			case ir::PTXOperand::Invalid:
			{
				throw Exception( "Cannot translate invalid PTX operand." );
			}
		}

		switch( o.type )
		{
			case ir::PTXOperand::u8:
			case ir::PTXOperand::s8:
			{
				op.type.type = ir::LLVMInstruction::I8;
				break;
			}
			case ir::PTXOperand::s16:
			case ir::PTXOperand::u16:
			{
				op.type.type = ir::LLVMInstruction::I16;
				break;
			}
			case ir::PTXOperand::u32:
			case ir::PTXOperand::s32:
			{
				op.type.type = ir::LLVMInstruction::I32;
				break;
			}
			case ir::PTXOperand::s64:
			case ir::PTXOperand::u64:
			{
				op.type.type = ir::LLVMInstruction::I64;
				break;
			}
			case ir::PTXOperand::f32:
			{
				op.type.type = ir::LLVMInstruction::F32;
				break;
			}
			case ir::PTXOperand::f64:
			{
				op.type.type = ir::LLVMInstruction::F64;
				break;
			}
			default:
			{
				throw Exception( "PTXOperand datatype " 
					+ ir::PTXOperand::toString( o.type ) 
					+ " not support for immediate operand." );
			}				
		}

		if( o.vec == ir::PTXOperand::v1 )
		{
			op.type.category = ir::LLVMInstruction::Type::Element;
		}
		else
		{
			op.type.category = ir::LLVMInstruction::Type::Vector;
		}
		
		op.type.vector = o.vec;
		
		return op;
	}

	std::string PTXToLLVMTranslator::_tempRegister()
	{
		std::stringstream stream;
		stream << "$rt" << _tempRegisterCount++;
		return stream.str();
	}

	void PTXToLLVMTranslator::_translateInstructions()
	{
		for( ir::Kernel::PTXInstructionVector::const_iterator 
			fi = _llvmKernel->instructions.begin(); 
			fi != _llvmKernel->instructions.end(); ++fi )
		{
			_translate( *fi );
		}
	}

	void PTXToLLVMTranslator::_translate( const ir::PTXInstruction& i )
	{
		report( " Translating: " << i.toString() );
		assertM( i.valid() == "", "Instruction " << i.toString() 
			<< " is not valid: " << i.valid() );
		switch( i.opcode )
		{
			case ir::PTXInstruction::Abs: _translateAbs( i ); break;
			case ir::PTXInstruction::Add: _translateAdd( i ); break;
			case ir::PTXInstruction::AddC: _translateAddC( i ); break;
			case ir::PTXInstruction::And: _translateAnd( i ); break;
			case ir::PTXInstruction::Atom: _translateAtom( i ); break;
			case ir::PTXInstruction::Bar: _translateBar( i ); break;
			case ir::PTXInstruction::Bra: _translateBra( i ); break;
			case ir::PTXInstruction::Brkpt: _translateBrkpt( i ); break;
			case ir::PTXInstruction::Call: _translateCall( i ); break;
			case ir::PTXInstruction::CNot: _translateCNot( i ); break;
			case ir::PTXInstruction::Cos: _translateCos( i ); break;
			case ir::PTXInstruction::Cvt: _translateCvt( i ); break;
			case ir::PTXInstruction::Div: _translateDiv( i ); break;
			case ir::PTXInstruction::Ex2: _translateEx2( i ); break;
			case ir::PTXInstruction::Exit: _translateExit( i ); break;
			case ir::PTXInstruction::Ld: _translateLd( i ); break;
			case ir::PTXInstruction::Lg2: _translateLg2( i ); break;
			case ir::PTXInstruction::Mad24: _translateMad24( i ); break;
			case ir::PTXInstruction::Mad: _translateMad( i ); break;
			case ir::PTXInstruction::Max: _translateMax( i ); break;
			case ir::PTXInstruction::Membar: _translateMembar( i ); break;
			case ir::PTXInstruction::Min: _translateMin( i ); break;
			case ir::PTXInstruction::Mov: _translateMov( i ); break;
			case ir::PTXInstruction::Mul24: _translateMul24( i ); break;
			case ir::PTXInstruction::Mul: _translateMul( i ); break;
			case ir::PTXInstruction::Neg: _translateNeg( i ); break;
			case ir::PTXInstruction::Not: _translateNot( i ); break;
			case ir::PTXInstruction::Or: _translateOr( i ); break;
			case ir::PTXInstruction::Pmevent: _translatePmevent( i ); break;
			case ir::PTXInstruction::Rcp: _translateRcp( i ); break;
			case ir::PTXInstruction::Red: _translateRed( i ); break;
			case ir::PTXInstruction::Rem: _translateRem( i ); break;
			case ir::PTXInstruction::Ret: _translateRet( i ); break;
			case ir::PTXInstruction::Rsqrt: _translateRsqrt( i ); break;
			case ir::PTXInstruction::Sad: _translateSad( i ); break;
			case ir::PTXInstruction::SelP: _translateSelP( i ); break;
			case ir::PTXInstruction::Set: _translateSet( i ); break;
			case ir::PTXInstruction::SetP: _translateSetP( i ); break;
			case ir::PTXInstruction::Shl: _translateShl( i ); break;
			case ir::PTXInstruction::Shr: _translateShr( i ); break;
			case ir::PTXInstruction::Sin: _translateSin( i ); break;
			case ir::PTXInstruction::SlCt: _translateSlCt( i ); break;
			case ir::PTXInstruction::Sqrt: _translateSqrt( i ); break;
			case ir::PTXInstruction::St: _translateSt( i ); break;
			case ir::PTXInstruction::Sub: _translateSub( i ); break;
			case ir::PTXInstruction::SubC: _translateSubC( i ); break;
			case ir::PTXInstruction::Tex: _translateTex( i ); break;
			case ir::PTXInstruction::Trap: _translateTrap( i ); break;
			case ir::PTXInstruction::Vote: _translateVote( i ); break;
			case ir::PTXInstruction::Xor: _translateXor( i ); break;
			default:
			{
				assertM( false, "Opcode " 
					<< ir::PTXInstruction::toString( i.opcode ) 
					<< " not supported." );
				break;
			}
		}
	}

	void PTXToLLVMTranslator::_translateAbs( const ir::PTXInstruction& i )
	{
		ir::LLVMSub sub;
	}

	void PTXToLLVMTranslator::_translateAdd( const ir::PTXInstruction& i )
	{
		if( ir::PTXOperand::isFloat( i.type ) )
		{
			ir::LLVMFadd add;
		
			add.d = _destination( i );
			add.a = _translate( i.a );
			add.b = _translate( i.b );
		
			_add( add );	
			
			if( i.modifier & ir::PTXInstruction::sat )
			{
				ir::LLVMFcmp compare;
				
				compare.d.name = _tempRegister();
				compare.d.type.type = ir::LLVMInstruction::I1;
				compare.d.type.category = ir::LLVMInstruction::Type::Element;
				compare.comparison = ir::LLVMInstruction::Ule;
				compare.a = add.d;
//				compare.b.type.
				
			}
				
			_predicateEpilogue( i, add.d );
		}
		else
		{
			ir::LLVMAdd add;
			
			add.d = _destination( i );
			add.a = _translate( i.a );
			add.b = _translate( i.b );
		
			_add( add );
			_predicateEpilogue( i, add.d );
		}
		
	}

	void PTXToLLVMTranslator::_translateAddC( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateAnd( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateAtom( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateBar( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateBra( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateBrkpt( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateCall( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateCNot( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateCos( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateCvt( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateDiv( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateEx2( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateExit( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateLd( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateLg2( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateMad24( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateMad( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateMax( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateMembar( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateMin( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateMov( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateMul24( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateMul( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateNeg( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateNot( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateOr( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translatePmevent( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateRcp( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateRed( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateRem( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateRet( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateRsqrt( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSad( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSelP( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSet( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSetP( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateShl( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateShr( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSin( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSlCt( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSqrt( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSt( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSub( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateSubC( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateTex( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateTrap( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateVote( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateXor( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	ir::LLVMInstruction::Operand PTXToLLVMTranslator::_destination( 
		const ir::PTXInstruction& i )
	{
		ir::LLVMInstruction::Operand destination = _translate( i.d );
		if( i.pg.condition != ir::PTXOperand::PT )
		{
			destination.name = _tempRegister();			
		}
		return destination;
	}
	
	void PTXToLLVMTranslator::_predicateEpilogue( const ir::PTXInstruction& i,
		const ir::LLVMInstruction::Operand& temp )
	{
		if( i.pg.condition == ir::PTXOperand::PT ) return;
		
		ir::LLVMSelect select;
		select.condition = _translate( i.pg );
		select.d = _translate( i.d );
	
		if( i.pg.condition == ir::PTXOperand::nPT )
		{
			select.a = select.d;
			select.b = select.d;
		}
		else if( i.pg.condition == ir::PTXOperand::Pred )
		{
			select.a = temp;
			select.b = select.d;
		}
		else
		{
			select.a = select.d;
			select.b = temp;
		}
		
		_add( select );
	}

	void PTXToLLVMTranslator::_add( const ir::LLVMInstruction& i )
	{
		assertM( i.valid() == "", "Instruction " << i.toString() 
			<< " is not valid " << i.valid() );
		_llvmKernel->_statements.push_back( ir::LLVMStatement( i ) );	
	}

	PTXToLLVMTranslator::PTXToLLVMTranslator( OptimizationLevel l ) 
		: Translator( ir::Instruction::PTX, ir::Instruction::LLVM, l ),
		_tempRegisterCount( 0 )
	{
	
	}
	
	PTXToLLVMTranslator::~PTXToLLVMTranslator()
	{
	
	}
	
	ir::Kernel* PTXToLLVMTranslator::translate( const ir::Kernel* k )
	{
		report( "Translating PTX kernel " << k->name );
		_llvmKernel = new ir::LLVMKernel( *k );	
		
		_translateInstructions();
		
		return _llvmKernel;
	}
	
	void PTXToLLVMTranslator::addProfile( const ProfilingData& d )
	{
		// profiling not yet implemented
	}
}

#endif

