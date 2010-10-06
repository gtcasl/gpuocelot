/*! \file PTXToLLVMTranslator.cpp
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
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/Module.h>

#include <climits>

#include <hydrazine/implementation/debug.h>

#ifdef __i386__
#define USE_VECTOR_INSTRUCTIONS 0
#else
#define USE_VECTOR_INSTRUCTIONS 1
#endif

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace translator
{
	ir::LLVMInstruction::DataType PTXToLLVMTranslator::_translate( 
		ir::PTXOperand::DataType type )
	{
		switch( type )
		{
			case ir::PTXOperand::pred:
			{
				return ir::LLVMInstruction::I1;
				break;
			}			
			case ir::PTXOperand::b8: /* fall through */
			case ir::PTXOperand::u8: /* fall through */
			case ir::PTXOperand::s8:
			{
				return ir::LLVMInstruction::I8;
				break;
			}
			case ir::PTXOperand::b16: /* fall through */
			case ir::PTXOperand::s16: /* fall through */
			case ir::PTXOperand::u16:
			{
				return ir::LLVMInstruction::I16;
				break;
			}
			case ir::PTXOperand::b32: /* fall through */
			case ir::PTXOperand::u32: /* fall through */
			case ir::PTXOperand::s32:
			{
				return ir::LLVMInstruction::I32;
				break;
			}
			case ir::PTXOperand::b64: /* fall through */
			case ir::PTXOperand::s64: /* fall through */
			case ir::PTXOperand::u64:
			{
				return ir::LLVMInstruction::I64;
				break;
			}
			case ir::PTXOperand::f32:
			{
				return ir::LLVMInstruction::F32;
				break;
			}
			case ir::PTXOperand::f64:
			{
				return ir::LLVMInstruction::F64;
				break;
			}
			default:
			{
				assertM( false, "PTXOperand datatype " 
					+ ir::PTXOperand::toString( type ) 
					+ " not supported." );
			}
		}
		return ir::LLVMInstruction::InvalidDataType;
	}

	void PTXToLLVMTranslator::_doubleWidth( ir::LLVMInstruction::DataType& t )
	{
		switch( t )
		{
			case ir::LLVMInstruction::I1:
			{
				assertM( false, "Cannot double i1" );
				break;
			}
			case ir::LLVMInstruction::I8:
			{
				t = ir::LLVMInstruction::I16;
				break;
			}
			case ir::LLVMInstruction::I16:
			{
				t = ir::LLVMInstruction::I32;
				break;
			}
			case ir::LLVMInstruction::I32:
			{
				t = ir::LLVMInstruction::I64;
				break;
			}
			case ir::LLVMInstruction::I64:
			{
				t = ir::LLVMInstruction::I128;
				break;
			}
			case ir::LLVMInstruction::I128:
			{
				assertM( false, "Cannot double i128" );
				break;
			}
			case ir::LLVMInstruction::F32:
			{
				t = ir::LLVMInstruction::F64;
				break;
			}
			case ir::LLVMInstruction::F64:
			{
				t = ir::LLVMInstruction::F128;
				break;
			}
			case ir::LLVMInstruction::F128:
			{
				assertM( false, "Cannot double fp128" );
				break;
			}
			case ir::LLVMInstruction::InvalidDataType:
			{
				assertM( false, "Cannot double invalid data type" );
				break;
			}
		}
	}

	ir::LLVMInstruction::Comparison PTXToLLVMTranslator::_translate( 
		ir::PTXInstruction::CmpOp op, bool isInt, bool isSigned )
	{
		if( isInt )
		{
			if( isSigned )
			{
				switch( op )
				{
					case ir::PTXInstruction::Eq: 
						return ir::LLVMInstruction::Eq; break;
					case ir::PTXInstruction::Ne: 
						return ir::LLVMInstruction::Ne; break;
					case ir::PTXInstruction::Lo: /* fall through */
					case ir::PTXInstruction::Lt: 
						return ir::LLVMInstruction::Slt; break;
					case ir::PTXInstruction::Ls: /* fall through */
					case ir::PTXInstruction::Le: 
						return ir::LLVMInstruction::Sle; break;
					case ir::PTXInstruction::Hi: /* fall through */
					case ir::PTXInstruction::Gt: 
						return ir::LLVMInstruction::Sgt; break;
					case ir::PTXInstruction::Hs: /* fall through */
					case ir::PTXInstruction::Ge: 
						return ir::LLVMInstruction::Sge; break;
					default: assertM( false, "Invalid comparison " 
						<< ir::PTXInstruction::toString( op ) 
						<< " for integer operand." );
				}
			}
			else
			{
				switch( op )
				{
					case ir::PTXInstruction::Eq: 
						return ir::LLVMInstruction::Eq; break;
					case ir::PTXInstruction::Ne: 
						return ir::LLVMInstruction::Ne; break;
					case ir::PTXInstruction::Lo: /* fall through */
					case ir::PTXInstruction::Lt: 
						return ir::LLVMInstruction::Ult; break;
					case ir::PTXInstruction::Ls: /* fall through */
					case ir::PTXInstruction::Le: 
						return ir::LLVMInstruction::Ule; break;
					case ir::PTXInstruction::Hi: /* fall through */
					case ir::PTXInstruction::Gt: 
						return ir::LLVMInstruction::Ugt; break;
					case ir::PTXInstruction::Hs: /* fall through */
					case ir::PTXInstruction::Ge: 
						return ir::LLVMInstruction::Uge; break;
					default: assertM( false, "Invalid comparison " 
						<< ir::PTXInstruction::toString( op ) 
						<< " for integer operand." );
				}
			}
		}
		else
		{
			switch( op )
			{
				case ir::PTXInstruction::Eq: 
					return ir::LLVMInstruction::Oeq; break;
				case ir::PTXInstruction::Ne: 
					return ir::LLVMInstruction::One; break;
				case ir::PTXInstruction::Lt: 
					return ir::LLVMInstruction::Olt; break;
				case ir::PTXInstruction::Le: 
					return ir::LLVMInstruction::Ole; break;
				case ir::PTXInstruction::Gt: 
					return ir::LLVMInstruction::Ogt; break;
				case ir::PTXInstruction::Ge: 
					return ir::LLVMInstruction::Oge; break;
				case ir::PTXInstruction::Lo: 
					return ir::LLVMInstruction::Olt; break;
				case ir::PTXInstruction::Ls: 
					return ir::LLVMInstruction::Ole; break;
				case ir::PTXInstruction::Hi: 
					return ir::LLVMInstruction::Ogt; break;
				case ir::PTXInstruction::Hs: 
					return ir::LLVMInstruction::Oge; break;
				case ir::PTXInstruction::Equ: 
					return ir::LLVMInstruction::Ueq; break;
				case ir::PTXInstruction::Neu: 
					return ir::LLVMInstruction::Une; break;
				case ir::PTXInstruction::Ltu: 
					return ir::LLVMInstruction::Ult; break;
				case ir::PTXInstruction::Leu: 
					return ir::LLVMInstruction::Ule; break;
				case ir::PTXInstruction::Gtu: 
					return ir::LLVMInstruction::Ugt; break;
				case ir::PTXInstruction::Geu: 
					return ir::LLVMInstruction::Uge; break;
				case ir::PTXInstruction::Num: 
					return ir::LLVMInstruction::Ord; break;
				case ir::PTXInstruction::Nan: 
					return ir::LLVMInstruction::Uno; break;
				default: assertM( false, "Invalid comparison " 
					<< ir::PTXInstruction::toString( op ) 
					<< " for floating point operand." );
			}
		}
		
		return ir::LLVMInstruction::True;
	}

	ir::LLVMInstruction::Type PTXToLLVMTranslator::_getCtaContextType()
	{
		ir::LLVMInstruction::Type context;
		
		context.category = ir::LLVMInstruction::Type::Structure;
		context.members.resize( 13 );

		context.members[0].category = ir::LLVMInstruction::Type::Structure;
		context.members[0].label = "%Dimension";

		context.members[1] = context.members[0];
		context.members[2] = context.members[0];
		context.members[3] = context.members[0];

		context.members[4].category = ir::LLVMInstruction::Type::Pointer;
		context.members[4].type = ir::LLVMInstruction::I8;

		context.members[5] = context.members[4];
		context.members[6] = context.members[4];
		context.members[7] = context.members[4];
		
		context.members[8].category = ir::LLVMInstruction::Type::Element;
		context.members[8].type = ir::LLVMInstruction::I64;

		context.members[9] = context.members[8];
		context.members[10] = context.members[8];
		context.members[11] = context.members[8];
		
		context.members[12].category = ir::LLVMInstruction::Type::Pointer;
		context.members[12].type = ir::LLVMInstruction::I8;		
		
		return context;
	}

	ir::LLVMInstruction::Operand PTXToLLVMTranslator::_context()
	{
		ir::LLVMInstruction::Operand context;
		
		context.type.category = ir::LLVMInstruction::Type::Pointer;
		context.type.members.resize(1);
		context.type.members[0].category 
			= ir::LLVMInstruction::Type::Structure;
		context.type.members[0].label = "%LLVMContext";
		context.name = "%__ctaContext";
		
		return context;
	}

	void PTXToLLVMTranslator::_debug( const analysis::DataflowGraph::Block& b )
	{
		if( optimizationLevel != DebugOptimization
			&& optimizationLevel != ReportOptimization ) return;
				
		ir::LLVMCall call;
		
		call.name = "@__ocelot_debug_block";
		
		call.parameters.resize( 2 );

		call.parameters[0] = _context();

		call.parameters[1].type.type = ir::LLVMInstruction::I32;
		call.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[1].constant = true;
		call.parameters[1].i32 = b.id();
		
		_add( call );
	}

	void PTXToLLVMTranslator::_debug( 
		const analysis::DataflowGraph::Instruction& i )
	{
		if( optimizationLevel != DebugOptimization
			&& optimizationLevel != ReportOptimization ) return;

		ir::LLVMCall call;

		call.name = "@__ocelot_debug_instruction";
		
		call.parameters.resize( 2 );

		call.parameters[0] = _context();

		call.parameters[1].type.type = ir::LLVMInstruction::I64;
		call.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[1].constant = true;
		call.parameters[1].i64 = (long long unsigned int)i.i;

		_add( call );
	}

	void PTXToLLVMTranslator::_reportReads( 
		const analysis::DataflowGraph::Instruction& i )
	{
		if( optimizationLevel != ReportOptimization ) return;

		ir::LLVMCall call;
		
		call.parameters.resize( 2 );

		call.parameters[0] = _context();
		
		for( analysis::DataflowGraph::RegisterPointerVector::const_iterator 
			r = i.s.begin(); r != i.s.end(); ++r )
		{
			call.parameters[1].type.type = _translate( r->type );
			call.parameters[1].type.category 
				= ir::LLVMInstruction::Type::Element;

			std::stringstream stream;
			stream << "%r" << *r->pointer;

			call.parameters[1].name = stream.str();

			switch( r->type )
			{
				case ir::PTXOperand::s8:
				{
					call.name = "@__ocelot_register_read_s8";
					break;
				}
				case ir::PTXOperand::s16:
				{
					call.name = "@__ocelot_register_read_s16";
					break;
				}
				case ir::PTXOperand::s32:
				{
					call.name = "@__ocelot_register_read_s32";
					break;
				}
				case ir::PTXOperand::s64:
				{
					call.name = "@__ocelot_register_read_s64";
					break;
				}
				case ir::PTXOperand::pred: /* fall through */
				{
					ir::LLVMZext extend;
					
					extend.a = call.parameters[1];
					call.parameters[1].name = _tempRegister();
					call.parameters[1].type.type = ir::LLVMInstruction::I8;
					extend.d = call.parameters[1];
					
					_add( extend );
				}
				case ir::PTXOperand::u8: /* fall through */
				case ir::PTXOperand::b8:
				{
					call.name = "@__ocelot_register_read_u8";
					break;
				}
				case ir::PTXOperand::u16: /* fall through */
				case ir::PTXOperand::b16:
				{
					call.name = "@__ocelot_register_read_u16";
					break;
				}
				case ir::PTXOperand::u32: /* fall through */
				case ir::PTXOperand::b32:
				{
					call.name = "@__ocelot_register_read_u32";
					break;
				}
				case ir::PTXOperand::u64: /* fall through */
				case ir::PTXOperand::b64:
				{
					call.name = "@__ocelot_register_read_u64";
					break;
				}
				case ir::PTXOperand::f32:
				{
					call.name = "@__ocelot_register_read_f32";
					break;
				}
				case ir::PTXOperand::f64:
				{
					call.name = "@__ocelot_register_read_f64";
					break;
				}
				default: assertM(false, "Invalid data type " 
					<< ir::PTXOperand::toString( r->type ) << ".");
			}

			_add( call );
		}
	}

	void PTXToLLVMTranslator::_reportWrites( 
		const analysis::DataflowGraph::Instruction& i )
	{
		if( optimizationLevel != ReportOptimization ) return;

		ir::LLVMCall call;
		
		call.parameters.resize( 2 );

		call.parameters[0] = _context();
		
		for( analysis::DataflowGraph::RegisterPointerVector::const_iterator 
			r = i.d.begin(); r != i.d.end(); ++r )
		{
			call.parameters[1].type.type = _translate( r->type );
			call.parameters[1].type.category 
				= ir::LLVMInstruction::Type::Element;

			std::stringstream stream;
			stream << "%r" << *r->pointer;

			call.parameters[1].name = stream.str();

			switch( r->type )
			{
				case ir::PTXOperand::s8:
				{
					call.name = "@__ocelot_register_write_s8";
					break;
				}
				case ir::PTXOperand::s16:
				{
					call.name = "@__ocelot_register_write_s16";
					break;
				}
				case ir::PTXOperand::s32:
				{
					call.name = "@__ocelot_register_write_s32";
					break;
				}
				case ir::PTXOperand::s64:
				{
					call.name = "@__ocelot_register_write_s64";
					break;
				}
				case ir::PTXOperand::pred: /* fall through */
				{
					ir::LLVMZext extend;
					
					extend.a = call.parameters[1];
					call.parameters[1].name = _tempRegister();
					call.parameters[1].type.type = ir::LLVMInstruction::I8;
					extend.d = call.parameters[1];
					
					_add( extend );
				}
				case ir::PTXOperand::u8: /* fall through */
				case ir::PTXOperand::b8:
				{
					call.name = "@__ocelot_register_write_u8";
					break;
				}
				case ir::PTXOperand::u16: /* fall through */
				case ir::PTXOperand::b16:
				{
					call.name = "@__ocelot_register_write_u16";
					break;
				}
				case ir::PTXOperand::u32: /* fall through */
				case ir::PTXOperand::b32:
				{
					call.name = "@__ocelot_register_write_u32";
					break;
				}
				case ir::PTXOperand::u64: /* fall through */
				case ir::PTXOperand::b64:
				{
					call.name = "@__ocelot_register_write_u64";
					break;
				}
				case ir::PTXOperand::f32:
				{
					call.name = "@__ocelot_register_write_f32";
					break;
				}
				case ir::PTXOperand::f64:
				{
					call.name = "@__ocelot_register_write_f64";
					break;
				}
				default: assertM(false, "Invalid data type " 
					<< ir::PTXOperand::toString( r->type ) << ".");
			}

			_add( call );
		}
	}

	void PTXToLLVMTranslator::_check( ir::PTXInstruction::AddressSpace space,
		const ir::LLVMInstruction::Operand& address, unsigned int bytes,
		unsigned int statement )
	{
		if( optimizationLevel != MemoryCheckOptimization 
			&& optimizationLevel != ReportOptimization
			&& optimizationLevel != DebugOptimization) return;

		ir::LLVMCall call;

		switch( space )
		{
			case ir::PTXInstruction::Shared:
			{
				call.name = "@__ocelot_check_shared_memory_access";
				break;
			}
			case ir::PTXInstruction::Global:
			{
				call.name = "@__ocelot_check_global_memory_access";
				break;
			}
			case ir::PTXInstruction::Local:
			{
				call.name = "@__ocelot_check_local_memory_access";
				break;
			}
			case ir::PTXInstruction::Const:
			{
				call.name = "@__ocelot_check_constant_memory_access";
				break;
			}
			case ir::PTXInstruction::Param:
			{
				call.name = "@__ocelot_check_param_memory_access";
				break;
			}
			default: assertM(false, "Invalid space " 
				<< ir::PTXInstruction::toString( space ) 
				<< " for memory checking.");
		}
		
		call.parameters.resize( 4 );

		call.parameters[0] = _context();

		call.parameters[1].name = _tempRegister();
		call.parameters[1].type.type = ir::LLVMInstruction::I64;
		call.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		
		call.parameters[2].type.type = ir::LLVMInstruction::I32;
		call.parameters[2].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[2].constant = true;
		call.parameters[2].i32 = bytes;
		
		call.parameters[3].type.type = ir::LLVMInstruction::I32;
		call.parameters[3].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[3].constant = true;
		call.parameters[3].i32 = statement;
		
		ir::LLVMPtrtoint convert;
		
		convert.a = address;
		convert.d = call.parameters[1];
		
		_add( convert );
		_add( call );
	}

	void PTXToLLVMTranslator::_addMemoryCheckingDeclarations()
	{
		if( optimizationLevel != MemoryCheckOptimization
			&& optimizationLevel != ReportOptimization
			&& optimizationLevel != DebugOptimization ) return;		
		
		ir::LLVMStatement check( ir::LLVMStatement::FunctionDeclaration );

		check.label = "__ocelot_check_global_memory_access";
		check.linkage = ir::LLVMStatement::InvalidLinkage;
		check.convention = ir::LLVMInstruction::DefaultCallingConvention;
		check.visibility = ir::LLVMStatement::Default;
		
		check.parameters.resize( 4 );

		check.parameters[0].type.category = ir::LLVMInstruction::Type::Pointer;
		check.parameters[0].type.members.resize(1);
		check.parameters[0].type.members[0].category 
			= ir::LLVMInstruction::Type::Structure;
		check.parameters[0].type.members[0].label = "%LLVMContext";

		check.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		check.parameters[1].type.type = ir::LLVMInstruction::I64;
	
		check.parameters[2].type.category = ir::LLVMInstruction::Type::Element;
		check.parameters[2].type.type = ir::LLVMInstruction::I32;
	
		check.parameters[3].type.category = ir::LLVMInstruction::Type::Element;
		check.parameters[3].type.type = ir::LLVMInstruction::I32;
	
		_llvmKernel->_statements.push_front( check );		

		check.label = "__ocelot_check_global_memory_access";
		_llvmKernel->_statements.push_front( check );		

		check.label = "__ocelot_check_shared_memory_access";
		_llvmKernel->_statements.push_front( check );		

		check.label = "__ocelot_check_constant_memory_access";
		_llvmKernel->_statements.push_front( check );		

		check.label = "__ocelot_check_local_memory_access";
		_llvmKernel->_statements.push_front( check );
		
		check.label = "__ocelot_check_param_memory_access";
		_llvmKernel->_statements.push_front( check );
	}

	void PTXToLLVMTranslator::_insertDebugSymbols()
	{
		if( optimizationLevel != DebugOptimization
			&& optimizationLevel != ReportOptimization ) return;		

		ir::LLVMStatement block( ir::LLVMStatement::FunctionDeclaration );

		block.label = "__ocelot_debug_block";
		block.linkage = ir::LLVMStatement::InvalidLinkage;
		block.convention = ir::LLVMInstruction::DefaultCallingConvention;
		block.visibility = ir::LLVMStatement::Default;
		
		block.parameters.resize(2);

		block.parameters[0].type.category = ir::LLVMInstruction::Type::Pointer;
		block.parameters[0].type.members.resize(1);
		block.parameters[0].type.members[0].category 
			= ir::LLVMInstruction::Type::Structure;
		block.parameters[0].type.members[0].label = "%LLVMContext";

		block.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		block.parameters[1].type.type = ir::LLVMInstruction::I32;
	
		_llvmKernel->_statements.push_front( block );

		ir::LLVMStatement instruction( ir::LLVMStatement::FunctionDeclaration );

		instruction.label = "__ocelot_debug_instruction";
		instruction.linkage = ir::LLVMStatement::InvalidLinkage;
		instruction.convention = ir::LLVMInstruction::DefaultCallingConvention;
		instruction.visibility = ir::LLVMStatement::Default;
		
		instruction.parameters.resize( 2 );
		instruction.parameters[0].type.category 
			= ir::LLVMInstruction::Type::Pointer;
		instruction.parameters[0].type.members.resize(1);
		instruction.parameters[0].type.members[0].category 
			= ir::LLVMInstruction::Type::Structure;
		instruction.parameters[0].type.members[0].label = "%LLVMContext";

		instruction.parameters[1].type.category 
			= ir::LLVMInstruction::Type::Element;
		instruction.parameters[1].type.type = ir::LLVMInstruction::I64;
	
		_llvmKernel->_statements.push_front( instruction );

		if( optimizationLevel != ReportOptimization ) return;		

		instruction.parameters.resize( 2 );
		instruction.parameters[0].type.category 
			= ir::LLVMInstruction::Type::Pointer;
		instruction.parameters[0].type.members.resize(1);
		instruction.parameters[0].type.members[0].category 
			= ir::LLVMInstruction::Type::Structure;
		instruction.parameters[0].type.members[0].label = "%LLVMContext";

		instruction.parameters[1].type.type = ir::LLVMInstruction::I8;
		instruction.label = "__ocelot_register_write_u8";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_write_s8";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_u8";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_s8";
		_llvmKernel->_statements.push_front( instruction );

		instruction.parameters[1].type.type = ir::LLVMInstruction::I16;
		instruction.label = "__ocelot_register_write_u16";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_write_s16";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_u16";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_s16";
		_llvmKernel->_statements.push_front( instruction );

		instruction.parameters[1].type.type = ir::LLVMInstruction::I32;
		instruction.label = "__ocelot_register_write_u32";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_write_s32";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_u32";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_s32";
		_llvmKernel->_statements.push_front( instruction );

		instruction.parameters[1].type.type = ir::LLVMInstruction::I64;
		instruction.label = "__ocelot_register_write_u64";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_write_s64";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_u64";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_s64";
		_llvmKernel->_statements.push_front( instruction );

		instruction.parameters[1].type.type = ir::LLVMInstruction::F32;
		instruction.label = "__ocelot_register_write_f32";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_f32";
		_llvmKernel->_statements.push_front( instruction );
		instruction.parameters[1].type.type = ir::LLVMInstruction::F64;
		instruction.label = "__ocelot_register_write_f64";
		_llvmKernel->_statements.push_front( instruction );
		instruction.label = "__ocelot_register_read_f64";
		_llvmKernel->_statements.push_front( instruction );
	}
			
	void PTXToLLVMTranslator::_yield( unsigned int continuation )
	{
		ir::LLVMRet ret;
		
		ret.d.constant = true;
		ret.d.type.category = ir::LLVMInstruction::Type::Element;
		ret.d.type.type = ir::LLVMInstruction::I32;
		ret.d.i32 = continuation;
		
		_add( ret );
	}

	ir::LLVMInstruction::Operand PTXToLLVMTranslator::_translate( 
		const ir::PTXOperand& o )
	{
		ir::LLVMInstruction::Operand op( o.identifier );
		op.constant = o.addressMode == ir::PTXOperand::Immediate;
		
		op.type.type = _translate( o.type );
		
		if( o.vec == ir::PTXOperand::v1 )
		{
			op.type.category = ir::LLVMInstruction::Type::Element;
		}
		else
		{
			op.type.category = ir::LLVMInstruction::Type::Vector;
		}
		
		switch( o.addressMode )
		{
			case ir::PTXOperand::Register: /* fall through */
			case ir::PTXOperand::Indirect:
			{
				std::stringstream stream;
				stream << "%r" << o.reg;
				op.name = stream.str();
				break;
			}
			case ir::PTXOperand::Immediate:
			{
				switch( o.type )
				{
					case ir::PTXOperand::s8:  /* fall through */
					case ir::PTXOperand::s16: /* fall through */
					case ir::PTXOperand::s32: /* fall through */
					case ir::PTXOperand::s64: /* fall through */
					case ir::PTXOperand::u8:  /* fall through */
					case ir::PTXOperand::u16: /* fall through */
					case ir::PTXOperand::u32: /* fall through */
					case ir::PTXOperand::u64: /* fall through */
					case ir::PTXOperand::b8:  /* fall through */
					case ir::PTXOperand::b16: /* fall through */
					case ir::PTXOperand::b32: /* fall through */
					case ir::PTXOperand::b64:
					{
						op.i64 = o.imm_uint;
						break;
					}
					case ir::PTXOperand::f32:
					{
						op.f32 = (float) o.imm_float;
						break;
					}
					case ir::PTXOperand::f64:
					{
						op.f64 = o.imm_float;
						break;
					}
					default:
					{
						assertM( false, "PTXOperand datatype " 
							+ ir::PTXOperand::toString( o.type ) 
							+ " not supported for immediate operand." );
					}				
				}
				break;
			}
			case ir::PTXOperand::Address:
			{
				assertM( false, 
					"Addressable variables require context" 
					<< " sensitive translation.  This is a bug in Ocelot." );
				break;
			}
			case ir::PTXOperand::Label:
			{
				assertM( false, "PTXOperand datatype " 
					+ ir::PTXOperand::toString( o.type ) 
					+ " not supported." );
				break;
			}
			case ir::PTXOperand::Special:
			{
				op.name = _loadSpecialRegister( o.special );
				break;
			}
			case ir::PTXOperand::BitBucket:
			{
				std::stringstream stream;
				stream << "%r_" << o.reg;
				op.name = stream.str();
				break;
			}
			case ir::PTXOperand::Invalid:
			{
				assertM( false, "Cannot translate invalid PTX operand." );
			}
		}
		
		op.type.vector = o.vec;
		
		return op;
	}

	void PTXToLLVMTranslator::_swapAllExceptName( 
		ir::LLVMInstruction::Operand& o, const ir::PTXOperand& i )
	{
		std::string temp = o.name;
		o = _translate( i );
		o.name = temp;
	}

	void PTXToLLVMTranslator::_translateInstructions()
	{
		for( analysis::DataflowGraph::const_iterator 
			block = ++_ptx->dfg()->begin(); 
			block != _ptx->dfg()->end(); ++block )
		{
			_newBlock( block->label() );
			report( "  Translating Phi Instructions" );
			for( analysis::DataflowGraph::PhiInstructionVector::const_iterator 
				phi = block->phis().begin(); 
				phi != block->phis().end(); ++phi )
			{
				ir::LLVMPhi p;
				analysis::DataflowGraph::RegisterVector::const_iterator 
					s = phi->s.begin();
				for( ; s != phi->s.end(); ++s )
				{			
					ir::LLVMPhi::Node node;
					
					try
					{
						node.label = "%" + block->producer( *s );
					}
					catch( analysis::DataflowGraph::NoProducerException& )
					{
						node.label = "%$OcelotRegisterInitializerBlock";
						_uninitialized.push_back( *s );
						node.reg = s->id;

						std::stringstream stream;
						stream << "%ri" << s->id;
					
						node.operand.name = stream.str();
						node.operand.type.category 
							= ir::LLVMInstruction::Type::Element;
						node.operand.type.type = _translate( s->type );
					
						p.nodes.push_back( node );
						continue;
					}
					
					node.reg = s->id;

					std::stringstream stream;
					stream << "%r" << s->id;
					
					node.operand.name = stream.str();
					node.operand.type.category 
						= ir::LLVMInstruction::Type::Element;
					node.operand.type.type = _translate( s->type );
					
					p.nodes.push_back( node );
				}

				assert( !p.nodes.empty() );
				
				std::stringstream stream;
				stream << "%r" << phi->d.id;
				p.d.name = stream.str();
				p.d.type.category = ir::LLVMInstruction::Type::Element;
				p.d.type.type = _translate( phi->d.type );
				
				_add( p );
			}

			_debug( *block );

			report( "  Translating Instructions" );
			for( analysis::DataflowGraph::InstructionVector::const_iterator 
				instruction = block->instructions().begin();
				instruction != block->instructions().end(); ++instruction )
			{
				_translate( *instruction, *block );
			}
			
			if( block->targets().empty() )
			{
				if( block->fallthrough() != _ptx->dfg()->end() )
				{
					ir::LLVMBr branch;
				
					branch.iftrue = "%" + block->fallthrough()->label();
					_add( branch );
				}
				else
				{
					_yield( 0 );
				}
			}
		}
	}

	void PTXToLLVMTranslator::_newBlock( const std::string& name )
	{
		report( " Translating basic block: " << name );
		_llvmKernel->_statements.push_back( ir::LLVMStatement( name ) );
	}

	void PTXToLLVMTranslator::_translate( 
		const analysis::DataflowGraph::Instruction& i, 
		const analysis::DataflowGraph::Block& block )
	{
		_debug( i );
		_reportReads( i );
		_translate( static_cast<ir::PTXInstruction&>(*i.i), block );
		_reportWrites( i );
	}

	void PTXToLLVMTranslator::_translate( const ir::PTXInstruction& i, 
		const analysis::DataflowGraph::Block& block )
	{
		report( "   Translating: " << i.toString() );
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
			case ir::PTXInstruction::Bra: _translateBra( i, block ); break;
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
		ir::LLVMInstruction::Operand destination = _destination( i );
		
		if( ir::PTXOperand::isFloat( i.type ) )
		{
			ir::LLVMFcmp compare;
			
			compare.comparison = ir::LLVMInstruction::Olt;
			compare.d.type.category = ir::LLVMInstruction::Type::Element;
			compare.d.type.type = ir::LLVMInstruction::I1;
			compare.d.name = _tempRegister();
			compare.a = _translate( i.a );
			compare.b = compare.a;
			compare.b.constant = true;
			
			if( ir::PTXOperand::f64 == i.a.type )
			{
				compare.b.f64 = 0;
			}
			else
			{
				compare.b.f32 = 0;
			}
			
			_add( compare );
			
			ir::LLVMFsub sub;
			
			sub.d = destination;
			sub.d.name = _tempRegister();
			sub.a = compare.a;
			sub.a.constant = true;
			
			if( ir::PTXOperand::f64 == i.a.type )
			{
				sub.a.f64 = 0;
			}
			else
			{
				sub.a.f32 = 0;
			}			
			
			sub.b = compare.a;
			
			_add( sub );
			
			ir::LLVMSelect select;
			
			select.d = destination;
			select.condition = compare.d;
			select.a = sub.d;
			select.b = compare.a;
			
			_add( select );
		}
		else
		{
			ir::LLVMIcmp compare;
			
			compare.comparison = ir::LLVMInstruction::Slt;
			compare.d.type.category = ir::LLVMInstruction::Type::Element;
			compare.d.type.type = ir::LLVMInstruction::I1;
			compare.d.name = _tempRegister();
			compare.a = _translate( i.a );
			compare.b = compare.a;
			compare.b.constant = true;
			
			if( ir::PTXOperand::s64 == i.a.type )
			{
				compare.b.i64 = 0;
			}
			else
			{
				compare.b.i32 = 0;
			}
			
			_add( compare );
			
			ir::LLVMSub sub;
			
			sub.d = destination;
			sub.d.name = _tempRegister();
			sub.a = compare.a;
			sub.a.constant = true;
			
			if( ir::PTXOperand::s64 == i.a.type )
			{
				sub.a.i64 = 0;
			}
			else
			{
				sub.a.i32 = 0;
			}			
			
			sub.b = compare.a;
			
			_add( sub );
			
			ir::LLVMSelect select;
			
			select.d = destination;
			select.condition = compare.d;
			select.a = sub.d;
			select.b = compare.a;
			
			_add( select );
		}
	}

	void PTXToLLVMTranslator::_translateAdd( const ir::PTXInstruction& i )
	{
		if( ir::PTXOperand::isFloat( i.type ) )
		{
			ir::LLVMFadd add;
			
			ir::LLVMInstruction::Operand result = _destination( i );

			add.a = _translate( i.a );
			add.b = _translate( i.b );

			if( i.modifier & ir::PTXInstruction::sat )
			{
				add.d = add.a;
				add.a.name = _tempRegister();
			}
			else
			{
				add.d = result;
			}
		
			_add( add );	
			
			if( i.modifier & ir::PTXInstruction::sat )
			{
				ir::LLVMFcmp compare;
				
				compare.d.name = _tempRegister();
				compare.d.type.type = ir::LLVMInstruction::I1;
				compare.d.type.category = ir::LLVMInstruction::Type::Element;
				compare.comparison = ir::LLVMInstruction::Ule;
				compare.a = add.d;
				compare.b.type.type = compare.a.type.type;
				compare.b.type.category = ir::LLVMInstruction::Type::Element;
				compare.b.constant = true;
				if( compare.b.type.type == ir::LLVMInstruction::F32 )
				{
					compare.b.f32 = 0;
				}
				else
				{
					compare.b.f64 = 0;
				}
				
				ir::LLVMSelect select;
				
				select.d = result;
				select.condition = compare.d;
				select.a = compare.b;
				select.b = add.d;
				
				_add( compare );
				_add( select );
			}
		}
		else
		{
			if( i.modifier & ir::PTXInstruction::sat )
			{
				assert( i.type == ir::PTXOperand::s32 );
				
				ir::LLVMSext extendA;
				ir::LLVMSext extendB;
								
				extendA.a = _translate( i.a );
				extendA.d.type.type = ir::LLVMInstruction::I64;
				extendA.d.type.category = ir::LLVMInstruction::Type::Element;
				extendA.d.name = _tempRegister();
				
				_add( extendA );
				
				extendB.a = _translate( i.b );
				extendB.d.type.type = ir::LLVMInstruction::I64;
				extendB.d.type.category = ir::LLVMInstruction::Type::Element;
				extendB.d.name = _tempRegister();
				
				_add( extendB );
				
				ir::LLVMAdd add;
				
				add.a = extendA.d;
				add.b = extendB.d;
				add.d.name = _tempRegister();
				add.d.type.type = ir::LLVMInstruction::I64;
				add.d.type.category = ir::LLVMInstruction::Type::Element;
				
				_add( add );
				
				ir::LLVMIcmp compare;
				
				compare.d.name = _tempRegister();
				compare.d.type.type = ir::LLVMInstruction::I1;
				compare.d.type.category = ir::LLVMInstruction::Type::Element;
				compare.comparison = ir::LLVMInstruction::Slt;
				compare.a = add.d;
				compare.b.type.type = ir::LLVMInstruction::I64;
				compare.b.type.category = ir::LLVMInstruction::Type::Element;
				compare.b.constant = true;
				compare.b.i64 = INT_MIN;

				_add( compare );
				
				ir::LLVMSelect select;
				
				select.d.name = _tempRegister();
				select.d.type.type = ir::LLVMInstruction::I64;
				select.d.type.category = ir::LLVMInstruction::Type::Element;

				select.condition = compare.d;
				select.a = compare.b;
				select.b = compare.a;
				
				_add( select );
				
				compare.d.name = _tempRegister();
				compare.comparison = ir::LLVMInstruction::Sgt;
				compare.b.i64 = INT_MAX;
				compare.a = select.d;
				
				_add( compare );

				select.condition = compare.d;
				select.a = compare.b;
				select.b = compare.a;
				select.d.name = _tempRegister();

				_add( select );
				
				ir::LLVMTrunc truncate;
				
				truncate.a = select.d;
				truncate.d = _destination( i );
				
				_add( truncate );
			}
			else if ( i.carry & ir::PTXInstruction::CC )
			{
				ir::LLVMInstruction::Operand extendedA( _tempRegister(), 
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				ir::LLVMInstruction::Operand extendedB( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				
				if( ir::PTXOperand::isSigned( i.type ) )
				{
					ir::LLVMSext sext;
					
					sext.d = extendedA;
					sext.a = _translate( i.a );
					
					_add( sext );
					
					sext.d = extendedB;
					sext.a = _translate( i.b );
					
					_add( sext );
				}
				else
				{
					ir::LLVMZext zext;
					
					zext.d = extendedA;
					zext.a = _translate( i.a );
					
					_add( zext );
					
					zext.d = extendedB;
					zext.a = _translate( i.b );
					
					_add( zext );					
				}
				
				ir::LLVMInstruction::Operand extendedD( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				
				ir::LLVMAdd add;
				
				add.a = extendedA;
				add.b = extendedB;
				add.d = extendedD;
				
				_add( add );
				
				ir::LLVMTrunc truncate;
				
				truncate.d = _destination( i );
				truncate.a = extendedD;
				
				_add( truncate );
				
				ir::LLVMLshr shift;
				
				shift.d = ir::LLVMInstruction::Operand ( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				shift.a = extendedD;
				shift.b.type = ir::LLVMInstruction::Type( 
					ir::LLVMInstruction::I32, 
					ir::LLVMInstruction::Type::Element );
				shift.b.constant = true;
				shift.b.i32 = 32;
				
				_add( shift );
				
				ir::LLVMAnd mask;
				
				mask.d = ir::LLVMInstruction::Operand ( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				mask.a = shift.d;
				mask.b.type = ir::LLVMInstruction::Type( 
					ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element );
				mask.b.constant = true;
				mask.b.i64 = 1;
				
				_add( mask );
				
				truncate.d = _translate( i.pq );
				truncate.a = mask.d;
				
				_add( truncate );
			}
			else
			{
				ir::LLVMAdd add;

				add.d = _destination( i );
				add.a = _translate( i.a );
				add.b = _translate( i.b );
				
				_add( add );
			}
		}		
	}

	void PTXToLLVMTranslator::_translateAddC( const ir::PTXInstruction& i )
	{
		if( i.carry & ir::PTXInstruction::CC )
		{
				ir::LLVMInstruction::Operand extendedA( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				ir::LLVMInstruction::Operand extendedB( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				ir::LLVMInstruction::Operand extendedC( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				
				if( ir::PTXOperand::isSigned( i.type ) )
				{
					ir::LLVMSext sext;
					
					sext.d = extendedA;
					sext.a = _translate( i.a );
					
					_add( sext );
					
					sext.d = extendedB;
					sext.a = _translate( i.b );
					
					_add( sext );

					sext.d = extendedC;
					sext.a = _translate( i.c );
					
					_add( sext );
				}
				else
				{
					ir::LLVMZext zext;
					
					zext.d = extendedA;
					zext.a = _translate( i.a );
					
					_add( zext );
					
					zext.d = extendedB;
					zext.a = _translate( i.b );
					
					_add( zext );					

					zext.d = extendedC;
					zext.a = _translate( i.c );
					
					_add( zext );					
				}
				
				ir::LLVMInstruction::Operand extendedDt( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				ir::LLVMInstruction::Operand extendedD( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				
				ir::LLVMAdd add;
				
				add.a = extendedA;
				add.b = extendedB;
				add.d = extendedDt;
				
				_add( add );

				add.a = extendedDt;
				add.b = extendedC;
				add.d = extendedD;
				
				_add( add );
				
				ir::LLVMTrunc truncate;
				
				truncate.d = _destination( i );
				truncate.a = extendedD;
				
				_add( truncate );
				
				ir::LLVMLshr shift;
				
				shift.d = ir::LLVMInstruction::Operand ( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				shift.a = extendedD;
				shift.b.type = ir::LLVMInstruction::Type( 
					ir::LLVMInstruction::I32, 
					ir::LLVMInstruction::Type::Element );
				shift.b.constant = true;
				shift.b.i32 = 32;
				
				_add( shift );
				
				ir::LLVMAnd mask;
				
				mask.d = ir::LLVMInstruction::Operand ( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				mask.a = shift.d;
				mask.b.type = ir::LLVMInstruction::Type( 
					ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element );
				mask.b.constant = true;
				mask.b.i64 = 1;
				
				_add( mask );
				
				truncate.d = _translate( i.pq );
				truncate.a = mask.d;
				
				_add( truncate );
		}
		else
		{
			ir::LLVMInstruction::Operand destination = _destination( i );
		
			ir::LLVMAdd add;
			
			add.d = destination;
			add.d.name = _tempRegister();
			add.a = _translate( i.a );
			add.b = _translate( i.b );
			
			_add( add );
			
			add.a = add.d;
			add.d = destination;
			add.b = _translate( i.c );
			
			_add( add );
		}	
	}

	void PTXToLLVMTranslator::_translateAnd( const ir::PTXInstruction& i )
	{						
		ir::LLVMAnd And;
		
		And.d = _destination( i );
		And.a = _translate( i.a );
		And.b = _translate( i.b );

		_add( And );
	}

	void PTXToLLVMTranslator::_translateAtom( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		call.d = _destination( i );

		if( i.atomicOperation == ir::PTXInstruction::AtomicCas )
		{
			if( i.type == ir::PTXOperand::b32 
				|| i.type == ir::PTXOperand::u32 )
			{
				call.name = "@__ocelot_atomcas_b32";
			}
			else
			{
				call.name = "@__ocelot_atomcas_b64";				
			}
			call.parameters.resize( 6 );
		}
		else
		{
			if( i.type == ir::PTXOperand::b32
				|| i.type == ir::PTXOperand::u32 )
			{
				call.name = "@__ocelot_atom_b32";
			}
			else if( i.type == ir::PTXOperand::f32 )
			{
				call.name = "@__ocelot_atom_f32";
			}
			else if( i.type == ir::PTXOperand::s32 )
			{
				call.name = "@__ocelot_atom_s32";
			}
			else
			{
				call.name = "@__ocelot_atom_b64";
			}
			call.parameters.resize( 5 );
		}
		
		call.parameters[0] = _context();

		call.parameters[1].type.type = ir::LLVMInstruction::I32;
		call.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[1].i32 = i.addressSpace;
		call.parameters[1].constant = true;

		call.parameters[2].type.type = ir::LLVMInstruction::I32;
		call.parameters[2].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[2].i32 = i.atomicOperation;
		call.parameters[2].constant = true;

		if( ir::PTXOperand::bytes(i.a.type) == 8 )
		{
			call.parameters[3] = _translate( i.a );
		}
		else
		{
			call.parameters[3].type.type = ir::LLVMInstruction::I64;
			call.parameters[3].type.category 
				= ir::LLVMInstruction::Type::Element;
			call.parameters[3].name = _tempRegister();
			_bitcast( call.parameters[3], _translate( i.a ), false );
		}
		
		call.parameters[4] = _translate( i.b );
		
		if( i.atomicOperation == ir::PTXInstruction::AtomicCas )
		{
			call.parameters[5] = _translate( i.c );
		}
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateBar( const ir::PTXInstruction& i )
	{
		_yield( i.reentryPoint );
	}

	void PTXToLLVMTranslator::_translateBra( const ir::PTXInstruction& i, 
		const analysis::DataflowGraph::Block& block )
	{
		ir::LLVMBr branch;
		
		if( block.targets().empty() )
		{
			branch.iftrue = "%" + block.fallthrough()->label();
		}
		else
		{
			branch.iftrue = "%" + (*block.targets().begin())->label();
			if( block.fallthrough() != _ptx->dfg()->end() )
			{
				if( (*block.targets().begin()) != block.fallthrough() )
				{
					if( ir::PTXOperand::PT != i.pg.condition 
						&& ir::PTXOperand::nPT != i.pg.condition )
					{
						branch.condition = _translate( i.pg );
					}
					else
					{
						branch.condition.type.category 
							= ir::LLVMInstruction::Type::Element;
						branch.condition.type.type = ir::LLVMInstruction::I1;
						branch.condition.constant = true;
			
						if( ir::PTXOperand::PT == i.pg.condition )
						{
							branch.condition.i1 = true;
						}
						else
						{
							branch.condition.i1 = false;
						}
					}
					branch.iffalse = "%" + block.fallthrough()->label();
				}
				if( i.pg.condition == ir::PTXOperand::InvPred )
				{
					std::swap( branch.iftrue, branch.iffalse );
				}
			}
			
		}
		_add( branch );
	}

	void PTXToLLVMTranslator::_translateBrkpt( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		call.name = "@breakpoint";
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateCall( const ir::PTXInstruction& i )
	{
		assertM( false, "Opcode " 
			<< ir::PTXInstruction::toString( i.opcode ) 
			<< " not supported." );
	}

	void PTXToLLVMTranslator::_translateCNot( const ir::PTXInstruction& i )
	{
		ir::LLVMSelect select;
		select.d = _destination( i );
		select.condition = _translate( i.a );
		select.a = select.condition;
		select.a.constant = true;
		select.a.i64 = 0;
		select.b = select.a;		
		select.b.i64 = -1;
	
		_add( select );
	}

	void PTXToLLVMTranslator::_translateCos( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		if( i.modifier & ir::PTXInstruction::ftz )
		{
			call.name = "@__ocelot_cosFtz";
		}
		else
		{
			call.name = "@__ocelot_cosf";
		}
		
		call.d = _destination( i );
		call.parameters.resize( 1 );
		call.parameters[0] = _translate( i.a );
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateCvt( const ir::PTXInstruction& i )
	{
		ir::LLVMInstruction::Operand destination;
		ir::LLVMInstruction::Operand source = _translate( i.a );
		
		if( _translate( i.d.type ) != _translate( i.type ) )
		{
			destination.name = _tempRegister();
			destination.type.category = ir::LLVMInstruction::Type::Element;
			destination.type.type = _translate( i.type );
		}
		else
		{
			destination = _translate( i.d );
		}

		_convert( destination, i.type, source, i.a.type, i.modifier );

		if( _translate( i.d.type ) != _translate( i.type ) )
		{
			_bitcast( _translate( i.d ), destination, 
				ir::PTXOperand::isSigned( i.type ) );
		}
	}

	void PTXToLLVMTranslator::_translateDiv( const ir::PTXInstruction& i )
	{
		if( ir::PTXOperand::isFloat( i.type ) )
		{
			ir::LLVMFdiv div;
			
			div.d = _destination( i );
			div.a = _translate( i.a );
			div.b = _translate( i.b );
			
			_add( div );
		}
		else if( ir::PTXOperand::isSigned( i.type ) )
		{
			ir::LLVMSdiv div;
			
			div.d = _destination( i );
			div.a = _translate( i.a );
			div.b = _translate( i.b );
			
			_add( div );
		}
		else
		{
			ir::LLVMUdiv div;
			
			div.d = _destination( i );
			div.a = _translate( i.a );
			div.b = _translate( i.b );
			
			_add( div );
		}
	}

	void PTXToLLVMTranslator::_translateEx2( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		if( i.modifier & ir::PTXInstruction::ftz )
		{
			call.name = "@__ocelot_ex2Ftz";
		}
		else
		{
			call.name = "@__ocelot_ex2";
		}
		
		call.d = _destination( i );
		call.parameters.resize( 1 );
		call.parameters[0] = _translate( i.a );
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateExit( const ir::PTXInstruction& i )
	{
		_yield( 0 );
	}

	void PTXToLLVMTranslator::_translateLd( const ir::PTXInstruction& i )
	{
		#if(USE_VECTOR_INSTRUCTIONS == 1)
		ir::LLVMLoad load;
		
		if( i.d.vec != ir::PTXOperand::v1 )
		{
			load.d = _translate( i.d.array.front() );
			load.d.type.category = ir::LLVMInstruction::Type::Vector;
			load.d.type.vector = i.d.vec;
			load.d.type.type = _translate( i.type );
			load.d.name = _tempRegister();
		}
		else
		{
			load.d = _destination( i );
			load.d.type.type = _translate( i.type );
		}

		load.a = _getLoadOrStorePointer( i.a, i.addressSpace, 
			_translate( i.type ), i.vec );
		
		if( i.volatility == ir::PTXInstruction::Volatile )
		{
			load.isVolatile = true;
		}
		
		load.alignment = i.vec * ir::PTXOperand::bytes( i.type );
		
		if( i.d.array.empty() )
		{
			if( _translate( i.d.type ) != _translate( i.type ) )
			{
				ir::LLVMInstruction::Operand temp = load.d;
				temp.type.type = _translate( i.d.type );
				load.d.name = _tempRegister();
				_check( i.addressSpace, load.a, load.alignment,
					i.statementIndex );
				_add( load );
				_convert( temp, i.d.type, load.d, i.type );				
			}
			else
			{
				_check( i.addressSpace, load.a, load.alignment,
					i.statementIndex );
				_add( load );
			}
		}
		else
		{
			_check( i.addressSpace, load.a, load.alignment,
					i.statementIndex );
			_add( load );
		}
		
		for( ir::PTXOperand::Array::const_iterator 
			destination = i.d.array.begin(); 
			destination != i.d.array.end(); ++destination )
		{
			ir::LLVMInstruction::Operand target = _translate( *destination );
			
			ir::LLVMExtractelement extract;
			
			extract.d = target;
			extract.d.type.type = load.d.type.type;
			extract.a = load.d;
			extract.b.type.type = ir::LLVMInstruction::I32;
			extract.b.type.category = ir::LLVMInstruction::Type::Element;
			extract.b.constant = true;
			extract.b.i32 = std::distance( i.d.array.begin(), destination );
			
			if( destination->type != i.type )
			{
				ir::LLVMInstruction::Operand temp = target;
				extract.d.name = _tempRegister();
				_add( extract );
				_convert( temp, destination->type, extract.d, i.type );				
			}
			else
			{
				_add( extract );
			}
		}
		#else
		ir::LLVMLoad load;
		
		if( i.volatility == ir::PTXInstruction::Volatile )
		{
			load.isVolatile = true;
		}

		ir::LLVMInstruction::Operand address = _getLoadOrStorePointer( i.a, 
			i.addressSpace, _translate( i.type ), ir::PTXOperand::v1 );		
				
		if( i.d.array.empty() )
		{
			load.d = _destination( i );
			load.d.type.type = _translate( i.type );
			load.a = address;
			load.alignment = ir::PTXOperand::bytes( i.type );

			if( _translate( i.d.type ) != _translate( i.type ) )
			{
				ir::LLVMInstruction::Operand temp = load.d;
				temp.type.type = _translate( i.d.type );
				load.d.name = _tempRegister();
				_check( i.addressSpace, load.a, load.alignment,
					i.statementIndex );
				_add( load );
				_convert( temp, i.d.type, load.d, i.type );				
			}
			else
			{
				_check( i.addressSpace, load.a, load.alignment,
					i.statementIndex );
				_add( load );
			}
		}
		else
		{
			unsigned int index = 0;
			for( ir::PTXOperand::Array::const_iterator 
				destination = i.d.array.begin(); 
				destination != i.d.array.end(); ++destination, ++index )
			{
				ir::LLVMGetelementptr get;
			
				get.a = address;
				get.d = get.a;
				get.d.name = _tempRegister();
				get.indices.push_back( index );
			
				_add( get );
			
				load.d = _translate( *destination );
				load.d.type.type = _translate( i.type );
				load.alignment = ir::PTXOperand::bytes( i.type );
				load.a = get.d;
				_check( i.addressSpace, load.a, load.alignment,
						i.statementIndex );

				if( _translate( i.d.type ) != _translate( i.type ) )
				{
					ir::LLVMInstruction::Operand temp = load.d;
					temp.type.type = _translate( i.d.type );
					load.d.name = _tempRegister();
					_add( load );
					_convert( temp, i.d.type, load.d, i.type );				
				}
				else
				{
					_add( load );
				}
			}
		}
		#endif
	}

	void PTXToLLVMTranslator::_translateLg2( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		if( i.modifier & ir::PTXInstruction::ftz )
		{
			call.name = "@__ocelot_log2Ftz";
		}
		else
		{
			call.name = "@__ocelot_log2f";
		}
		
		call.d = _destination( i );
		call.parameters.resize( 1 );
		call.parameters[0] = _translate( i.a );
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateMad24( const ir::PTXInstruction& i )
	{
		assertM( !( i.modifier & ir::PTXInstruction::sat ), 
			"No support for saturation in mad24" );
		assertM( !( i.modifier & ir::PTXInstruction::hi ), 
			"No support for hi multiply in mad24" );
		
		ir::LLVMInstruction::Operand destination = _destination( i );
		
		ir::LLVMMul multiply;
		
		multiply.d = destination;
		multiply.d.type.type = ir::LLVMInstruction::I64;
		multiply.d.name = _tempRegister();
		multiply.a = _translate( i.a );
		multiply.b = _translate( i.b );
		
		_add( multiply );
		
		ir::LLVMInstruction::Operand c = _translate( i.c );
		
		if( ir::PTXOperand::isSigned( i.c.type ) )
		{
			ir::LLVMSext extend;
			
			extend.d = c;
			extend.d.name = _tempRegister();
			extend.d.type = ir::LLVMInstruction::I64;
			extend.a = c;
			
			c = extend.d;
			_add( extend );
		}
		else
		{
			ir::LLVMZext extend;
			
			extend.d = c;
			extend.d.name = _tempRegister();
			extend.d.type = ir::LLVMInstruction::I64;
			extend.a = c;
			
			c = extend.d;
			_add( extend );
		}
		
		ir::LLVMAdd add;
		
		add.d = destination;
		add.d.name = _tempRegister();
		add.a = multiply.d;
		add.b = c;
		
		ir::LLVMTrunc truncate;
		
		truncate.d = destination;
		truncate.a = add.d;

		_add( truncate );
	}

	void PTXToLLVMTranslator::_translateMad( const ir::PTXInstruction& i )
	{
		if( ir::PTXOperand::isFloat( i.type ) )
		{
			ir::LLVMFmul mul;
			ir::LLVMFadd add;
			
			_setFloatingPointRoundingMode( i );

			add.d = _destination( i );			
			mul.d = add.d;
			mul.d.name = _tempRegister();
			mul.a = _translate( i.a );
			mul.b = _translate( i.b );

			_add( mul );

			add.a = mul.d;
			add.b = _translate( i.c );
			
			_add( add );
		}
		else
		{
			if( i.modifier & ir::PTXInstruction::wide )
			{
				ir::LLVMInstruction::Operand extendedA = _translate( i.a );
				ir::LLVMInstruction::Operand extendedB = _translate( i.b );
				
				if( ir::PTXOperand::isSigned( i.a.type ) )
				{
					if( i.a.addressMode != ir::PTXOperand::Immediate )
					{
						ir::LLVMSext sextA;
					
						sextA.a = extendedA;
						_doubleWidth( extendedA.type.type );
						extendedA.name = _tempRegister();
						sextA.d = extendedA;
					
						_add( sextA );
					}
					else
					{
						_doubleWidth( extendedA.type.type );
					}
					
					if( i.b.addressMode != ir::PTXOperand::Immediate )
					{
						ir::LLVMSext sextB;
					
						sextB.a = extendedB;
						_doubleWidth( extendedB.type.type );
						extendedB.name = _tempRegister();
						sextB.d = extendedB;
					
						_add( sextB );
					}
					else
					{
						_doubleWidth( extendedB.type.type );
					}
				}
				else
				{
					if( i.a.addressMode != ir::PTXOperand::Immediate )
					{
						ir::LLVMZext sextA;
					
						sextA.a = extendedA;
						_doubleWidth( extendedA.type.type );
						extendedA.name = _tempRegister();
						sextA.d = extendedA;
					
						_add( sextA );

					}
					else
					{
						_doubleWidth( extendedA.type.type );
					}
					
					if( i.b.addressMode != ir::PTXOperand::Immediate )
					{
						ir::LLVMZext sextB;
					
						sextB.a = extendedB;
						_doubleWidth( extendedB.type.type );
						extendedB.name = _tempRegister();
						sextB.d = extendedB;
					
						_add( sextB );
					}
					else
					{
						_doubleWidth( extendedB.type.type );
					}
				}
				
				ir::LLVMMul mul;
				ir::LLVMAdd add;
				
				add.d = _destination( i );
				
				mul.d = add.d;
				mul.d.name = _tempRegister();	
				mul.a = extendedA;
				mul.b = extendedB;
			
				_add( mul );
				
				add.a = _translate( i.c );
				add.b = mul.d;
				
				_add( add );
			}
			else if( i.modifier & ir::PTXInstruction::lo )
			{
				ir::LLVMMul mul;
				ir::LLVMAdd add;
				
				add.d = _destination( i );
				
				mul.d = add.d;
				mul.d.name = _tempRegister();	
				mul.a = _translate( i.a );
				mul.b = _translate( i.b );
			
				_add( mul );
				
				add.a = _translate( i.c );
				add.b = mul.d;
				
				_add( add );
			}
			else
			{
				if( ir::PTXOperand::s64 == i.type )
				{
					ir::LLVMCall call;
					ir::LLVMAdd add;
					
					call.name = "@__ocelot_mul_hi_s64";
				
					add.d = _destination( i );
					call.d = add.d;
					call.d.name = _tempRegister();
					call.parameters.push_back( _translate( i.a ) );
					call.parameters.push_back( _translate( i.b ) );
					
					_add( call );
					
					add.a = call.d;
					add.b = _translate( i.c );
					
					_add( add );
				}
				else if( ir::PTXOperand::u64 == i.type )
				{
					ir::LLVMCall call;
					ir::LLVMAdd add;
					
					call.name = "@__ocelot_mul_hi_u64";
				
					add.d = _destination( i );
					call.d = add.d;
					call.d.name = _tempRegister();
					call.parameters.push_back( _translate( i.a ) );
					call.parameters.push_back( _translate( i.b ) );
					
					_add( call );
					
					add.a = call.d;
					add.b = _translate( i.c );
					
					_add( add );
				}
				else if( i.modifier & ir::PTXInstruction::sat )
				{
					assert( i.type == ir::PTXOperand::s32 );
			
					ir::LLVMSext extendA;
					ir::LLVMSext extendB;
					ir::LLVMSext extendC;
							
					extendA.a = _translate( i.a );
					extendA.d.type.type = ir::LLVMInstruction::I64;
					extendA.d.type.category = 
						ir::LLVMInstruction::Type::Element;
					extendA.d.name = _tempRegister();
			
					_add( extendA );
			
					extendB.a = _translate( i.b );
					extendB.d.type.type = ir::LLVMInstruction::I64;
					extendB.d.type.category = 
						ir::LLVMInstruction::Type::Element;
					extendB.d.name = _tempRegister();
			
					_add( extendB );

					extendC.a = _translate( i.c );
					extendC.d.type.type = ir::LLVMInstruction::I64;
					extendC.d.type.category = 
						ir::LLVMInstruction::Type::Element;
					extendC.d.name = _tempRegister();
			
					_add( extendC );
			
					ir::LLVMMul mul;
			
					mul.a = extendA.d;
					mul.b = extendB.d;
					mul.d.name = _tempRegister();
					mul.d.type.type = ir::LLVMInstruction::I64;
					mul.d.type.category = ir::LLVMInstruction::Type::Element;
					
					_add( mul );
					
					ir::LLVMAshr shift;
				
					shift.d.name = _tempRegister();
					shift.d.type.type = ir::LLVMInstruction::I64;
					shift.d.type.category = ir::LLVMInstruction::Type::Element;
					shift.a = mul.d;
					shift.b.constant = true;
					shift.b.type.category = ir::LLVMInstruction::Type::Element;
					shift.b.type.type = ir::LLVMInstruction::I32;
					shift.b.i32 = 32;
				
					_add( shift );
			
					ir::LLVMAdd add;
					
					add.a = shift.d;
					add.b = extendC.d;
					add.d.name = _tempRegister();
					add.d.type.type = ir::LLVMInstruction::I64;
					add.d.type.category = ir::LLVMInstruction::Type::Element;
					
					_add( add );
					
					ir::LLVMIcmp compare;
			
					compare.d.name = _tempRegister();
					compare.d.type.type = ir::LLVMInstruction::I1;
					compare.d.type.category = 
						ir::LLVMInstruction::Type::Element;
					compare.comparison = ir::LLVMInstruction::Slt;
					compare.a = add.d;
					compare.b.type.type = ir::LLVMInstruction::I64;
					compare.b.type.category = 
						ir::LLVMInstruction::Type::Element;
					compare.b.constant = true;
					compare.b.i64 = INT_MIN;

					_add( compare );
			
					ir::LLVMSelect select;
			
					select.d.name = _tempRegister();
					select.d.type.type = ir::LLVMInstruction::I64;
					select.d.type.category = ir::LLVMInstruction::Type::Element;

					select.condition = compare.d;
					select.a = compare.b;
					select.b = compare.a;
			
					_add( select );
			
					compare.d.name = _tempRegister();
					compare.comparison = ir::LLVMInstruction::Sgt;
					compare.b.i64 = INT_MAX;
					compare.a = select.d;
			
					_add( compare );

					select.condition = compare.d;
					select.a = compare.b;
					select.b = compare.a;
					select.d.name = _tempRegister();

					_add( select );
			
					ir::LLVMTrunc truncate;
			
					truncate.a = select.d;
					truncate.d = _destination( i );
			
					_add( truncate );
				}
				else
				{
					ir::LLVMInstruction::Operand 
						destination = _destination( i );
					ir::LLVMInstruction::Operand extendedA = _translate( i.a );
					ir::LLVMInstruction::Operand extendedB = _translate( i.b );
				
					if( ir::PTXOperand::isSigned( i.a.type ) )
					{
						if( i.a.addressMode != ir::PTXOperand::Immediate )
						{
							ir::LLVMSext sextA;
					
							sextA.a = extendedA;
							_doubleWidth( extendedA.type.type );
							extendedA.name = _tempRegister();
							sextA.d = extendedA;
					
							_add( sextA );
						}
						else
						{
							_doubleWidth( extendedA.type.type );
						}
					
						if( i.b.addressMode != ir::PTXOperand::Immediate )
						{
							ir::LLVMSext sextB;
					
							sextB.a = extendedB;
							_doubleWidth( extendedB.type.type );
							extendedB.name = _tempRegister();
							sextB.d = extendedB;
					
							_add( sextB );
						}
						else
						{
							_doubleWidth( extendedB.type.type );
						}
					
					}
					else
					{
						if( i.a.addressMode != ir::PTXOperand::Immediate )
						{
							ir::LLVMZext sextA;
					
							sextA.a = extendedA;
							_doubleWidth( extendedA.type.type );
							extendedA.name = _tempRegister();
							sextA.d = extendedA;
					
							_add( sextA );

						}
						else
						{
							_doubleWidth( extendedA.type.type );
						}
					
						if( i.b.addressMode != ir::PTXOperand::Immediate )
						{
							ir::LLVMZext sextB;
					
							sextB.a = extendedB;
							_doubleWidth( extendedB.type.type );
							extendedB.name = _tempRegister();
							sextB.d = extendedB;
					
							_add( sextB );
						}
						else
						{
							_doubleWidth( extendedB.type.type );
						}
					}
				
					ir::LLVMMul mul;
						
					mul.d = extendedA;
					mul.d.name = _tempRegister();
					mul.a = extendedA;
					mul.b = extendedB;
			
					_add( mul );
				
					ir::LLVMInstruction::Operand 
						shiftedDestination = destination;
					shiftedDestination.name = _tempRegister();
					_doubleWidth( shiftedDestination.type.type );
				
					if( ir::PTXOperand::isSigned( i.a.type ) )
					{
						ir::LLVMAshr shift;
					
						shift.d = shiftedDestination;
						shift.a = mul.d;
						shift.b.constant = true;
						shift.b.type.category = 
							ir::LLVMInstruction::Type::Element;
						shift.b.type.type = ir::LLVMInstruction::I32;
						shift.b.i32 = ir::PTXOperand::bytes( i.a.type ) * 8;
					
						_add( shift );
					}
					else
					{
						ir::LLVMLshr shift;
					
						shift.d = shiftedDestination;
						shift.a = mul.d;
						shift.b.constant = true;
						shift.b.type.category = 
							ir::LLVMInstruction::Type::Element;
						shift.b.type.type = ir::LLVMInstruction::I32;
						shift.b.i32 = ir::PTXOperand::bytes( i.a.type ) * 8;
					
						_add( shift );
					}
				
					ir::LLVMTrunc truncate;
				
					truncate.d = destination;
					truncate.d.name = _tempRegister();
					truncate.a = shiftedDestination;
					
					_add( truncate );
					
					ir::LLVMAdd add;
					
					add.d = destination;
					add.a = truncate.d;
					add.b = _translate( i.c );
					
					_add( add );
				}
			}
		}
	}

	void PTXToLLVMTranslator::_translateMax( const ir::PTXInstruction& i )
	{
		ir::LLVMInstruction::Operand destination = _destination( i );
		ir::LLVMInstruction::Operand comparison;
		
		comparison.type.category = ir::LLVMInstruction::Type::Element;
		comparison.type.type = ir::LLVMInstruction::I1;
		comparison.name = _tempRegister();
		
		if( ir::PTXOperand::isFloat( i.a.type ) )
		{
			ir::LLVMFcmp compare;
			
			compare.d = comparison;
			compare.a = _translate( i.a );
			compare.b = _translate( i.b );
			compare.comparison = ir::LLVMInstruction::Ogt;
			
			ir::LLVMSelect select; 
			
			select.condition = compare.d;
			select.a = compare.a;
			select.b = compare.b;
			select.d = destination;
			
			_add( compare );
			_add( select );
		}
		else
		{
			ir::LLVMIcmp compare;
			
			compare.d = comparison;
			compare.a = _translate( i.a );
			compare.b = _translate( i.b );
			
			if( ir::PTXOperand::isSigned( i.type ) )
			{
				compare.comparison = ir::LLVMInstruction::Sgt;
			}
			else
			{
				compare.comparison = ir::LLVMInstruction::Ugt;
			}
			
			ir::LLVMSelect select; 
			
			select.condition = compare.d;
			select.a = compare.a;
			select.b = compare.b;
			select.d = destination;
			
			_add( compare );
			_add( select );
		}
		
	}

	void PTXToLLVMTranslator::_translateMembar( const ir::PTXInstruction& i )
	{
		// This is a nop right now
	}

	void PTXToLLVMTranslator::_translateMin( const ir::PTXInstruction& i )
	{
		ir::LLVMInstruction::Operand destination = _destination( i );
		ir::LLVMInstruction::Operand comparison;
		
		comparison.type.category = ir::LLVMInstruction::Type::Element;
		comparison.type.type = ir::LLVMInstruction::I1;
		comparison.name = _tempRegister();
		
		if( ir::PTXOperand::isFloat( i.a.type ) )
		{
			ir::LLVMFcmp compare;
			
			compare.d = comparison;
			compare.a = _translate( i.a );
			compare.b = _translate( i.b );
			compare.comparison = ir::LLVMInstruction::Olt;
			
			ir::LLVMSelect select; 
			
			select.condition = compare.d;
			select.a = compare.a;
			select.b = compare.b;
			select.d = destination;
			
			_add( compare );
			_add( select );
		}
		else
		{
			ir::LLVMIcmp compare;
			
			compare.d = comparison;
			compare.a = _translate( i.a );
			compare.b = _translate( i.b );
			
			if( ir::PTXOperand::isSigned( i.type ) )
			{
				compare.comparison = ir::LLVMInstruction::Slt;
			}
			else
			{
				compare.comparison = ir::LLVMInstruction::Ult;
			}
			
			ir::LLVMSelect select; 
			
			select.condition = compare.d;
			select.a = compare.a;
			select.b = compare.b;
			select.d = destination;
			
			_add( compare );
			_add( select );
		}
		
	}

	void PTXToLLVMTranslator::_translateMov( const ir::PTXInstruction& i )
	{
		switch( i.d.vec )
		{
			case ir::PTXOperand::v1:
			{
				switch( i.a.vec )
				{
					case ir::PTXOperand::v1:
					{
						if( i.a.addressMode == ir::PTXOperand::Address )
						{
							if( i.addressSpace == ir::PTXInstruction::Global )
							{
								ir::LLVMPtrtoint toint;
				
								toint.a = _getAddressableGlobalPointer( i.a );
								toint.d = _destination( i );
				
								_add( toint );
							}
							else
							{
								ir::LLVMBitcast cast;
			
								cast.d = _destination( i );
								cast.a.type.category = cast.d.type.category;
								cast.a.type.type = cast.d.type.type;
								cast.a.constant = true;
								cast.a.i64 = i.a.offset;
			
								_add( cast );
							}
						}
						else if( i.d.type == i.a.type 
							|| i.type == ir::PTXOperand::b32 
							|| i.type == ir::PTXOperand::b64 
							|| i.type == ir::PTXOperand::b16 
							|| i.type == ir::PTXOperand::b8 )
						{
							_bitcast( i );
						}
						else
						{
							_translateCvt( i );
						}
						break;
					}
					case ir::PTXOperand::v2:
					{
						assertM( i.a.addressMode != ir::PTXOperand::Address, 
							"Addressable variables not supported" 
							<< " for vector moves." );
						
						ir::LLVMInstruction::Operand temp;
						
						temp.name = _tempRegister();
						temp.type.category 
							= ir::LLVMInstruction::Type::Element;
						temp.type.type = ir::LLVMInstruction::getIntOfSize( 
							ir::PTXOperand::bytes( i.d.type ) * 8 );
						
						_bitcast( temp, _translate( i.a.array[ 1 ] ) );
						
						ir::LLVMShl shift;
						
						shift.d = temp;
						shift.d.name = _tempRegister();
						shift.a = temp;
						
						shift.b.type.category 
							= ir::LLVMInstruction::Type::Element;
						shift.b.type.type = ir::LLVMInstruction::I32;
						shift.b.constant = true;
						shift.b.i32 = ir::PTXOperand::bytes( 
							i.a.array[ 1 ].type ) * 8;
						
						_add( shift );
						
						temp.name = _tempRegister();
						_bitcast( temp, _translate( i.a.array[ 0 ] ) );
						
						ir::LLVMOr combine;
						
						combine.d = temp;
						combine.d.name = _tempRegister();
						combine.a = temp;
						combine.b = shift.d;
						
						_add( combine );
						
						_bitcast( _destination( i ), combine.d );
						
						break;
					}
					case ir::PTXOperand::v4:
					{
						assertM( i.a.addressMode != ir::PTXOperand::Address, 
							"Addressable variables not supported" 
							<< " for vector moves." );
						assertM( false, 
							"Vector move from v" << i.a.vec << " to v" 
							<< i.d.vec << " not implemented." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::v2:
			{
				switch( i.a.vec )
				{
					case ir::PTXOperand::v1:
					{
						assertM( i.a.addressMode != ir::PTXOperand::Address, 
							"Addressable variables not supported" 
							<< " for vector moves." );
						ir::LLVMInstruction::Operand temp;
						
						temp.name = _tempRegister();
						temp.type.category 
							= ir::LLVMInstruction::Type::Element;
						temp.type.type = ir::LLVMInstruction::getIntOfSize( 
							ir::PTXOperand::bytes( i.a.type ) * 8 );
						
						_bitcast( temp, _translate( i.a ) );
						
						ir::LLVMTrunc truncate;
						
						truncate.a = temp;
						truncate.d.name = _tempRegister();
						truncate.d.type.category 
							= ir::LLVMInstruction::Type::Element;
						truncate.d.type.type 
							= ir::LLVMInstruction::getIntOfSize( 
							ir::PTXOperand::bytes( i.d.array[0].type ) * 8 );
						
						_add( truncate );
						_bitcast( _translate( i.d.array[0] ), truncate.d );
						
						ir::LLVMLshr shift;
						
						shift.a = temp;
						shift.d = temp;
						shift.d.name = _tempRegister();
						
						shift.b.type.category 
							= ir::LLVMInstruction::Type::Element;
						shift.b.type.type = ir::LLVMInstruction::I32;
						shift.b.constant = true;
						shift.b.i32 = ir::PTXOperand::bytes( 
							i.d.array[ 0 ].type ) * 8;
						
						_add( shift );
						
						truncate.a = shift.d;
						truncate.d.name = _tempRegister();
						
						_add( truncate );
						_bitcast( _translate( i.d.array[1] ), truncate.d );
						
						break;
					}
					case ir::PTXOperand::v2:
					{
						assertM( i.a.addressMode != ir::PTXOperand::Address, 
							"Addressable variables not supported" 
							<< " for vector moves." );
						assertM( false, 
							"Vector move from v" << i.a.vec << " to v" 
							<< i.d.vec << " not implemented." );
						break;
					}
					case ir::PTXOperand::v4:
					{
						assertM( i.a.addressMode != ir::PTXOperand::Address, 
							"Addressable variables not supported" 
							<< " for vector moves." );
						assertM( false, 
							"Vector move from v" << i.a.vec << " to v" 
							<< i.d.vec << " not implemented." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::v4:
			{
				switch( i.a.vec )
				{
					case ir::PTXOperand::v1:
					{
						assertM( i.a.addressMode != ir::PTXOperand::Address, 
							"Addressable variables not supported" 
							<< " for vector moves." );
						assertM( false, 
							"Vector move from v" << i.a.vec << " to v" 
							<< i.d.vec << " not implemented." );
						break;
					}
					case ir::PTXOperand::v2:
					{
						assertM( i.a.addressMode != ir::PTXOperand::Address, 
							"Addressable variables not supported" 
							<< " for vector moves." );
						assertM( false, 
							"Vector move from v" << i.a.vec << " to v" 
							<< i.d.vec << " not implemented." );
						break;
					}
					case ir::PTXOperand::v4:
					{
						assertM( i.a.addressMode != ir::PTXOperand::Address, 
							"Addressable variables not supported" 
							<< " for vector moves." );
						assertM( false, 
							"Vector move from v" << i.a.vec << " to v" 
							<< i.d.vec << " not implemented." );
						break;
					}
				}
				break;
			}
		}
	}

	void PTXToLLVMTranslator::_translateMul24( const ir::PTXInstruction& i )
	{
		if( i.modifier & ir::PTXInstruction::lo )
		{
			// 24-bit lo is the same as 32-bit lo
			ir::LLVMMul mul;
					
			mul.d = _destination( i );
			mul.a = _translate( i.a );
			mul.b = _translate( i.b );
		
			_add( mul );
		}
		else
		{
			assertM( false, "No support for hi 24-bit multiply" );
		}
	}

	void PTXToLLVMTranslator::_translateMul( const ir::PTXInstruction& i )
	{
		if( ir::PTXOperand::isFloat( i.type ) )
		{
			ir::LLVMFmul mul;
			
			_setFloatingPointRoundingMode( i );
			
			mul.d = _destination( i );
			mul.a = _translate( i.a );
			mul.b = _translate( i.b );

			if( i.modifier & ir::PTXInstruction::sat )
			{
				assertM( false, "Saturate not supported for " << i.toString() );
			}

			_add( mul );
		}
		else
		{
			if( i.modifier & ir::PTXInstruction::wide )
			{
				ir::LLVMInstruction::Operand extendedA = _translate( i.a );
				ir::LLVMInstruction::Operand extendedB = _translate( i.b );
				
				if( ir::PTXOperand::isSigned( i.a.type ) )
				{
					if( i.a.addressMode != ir::PTXOperand::Immediate )
					{
						ir::LLVMSext sextA;
					
						sextA.a = extendedA;
						_doubleWidth( extendedA.type.type );
						extendedA.name = _tempRegister();
						sextA.d = extendedA;
					
						_add( sextA );
					}
					else
					{
						_doubleWidth( extendedA.type.type );
					}
					
					if( i.b.addressMode != ir::PTXOperand::Immediate )
					{
						ir::LLVMSext sextB;
					
						sextB.a = extendedB;
						_doubleWidth( extendedB.type.type );
						extendedB.name = _tempRegister();
						sextB.d = extendedB;
					
						_add( sextB );
					}
					else
					{
						_doubleWidth( extendedB.type.type );
					}
				}
				else
				{
					if( i.a.addressMode != ir::PTXOperand::Immediate )
					{
						ir::LLVMZext sextA;
					
						sextA.a = extendedA;
						_doubleWidth( extendedA.type.type );
						extendedA.name = _tempRegister();
						sextA.d = extendedA;
					
						_add( sextA );

					}
					else
					{
						_doubleWidth( extendedA.type.type );
					}
					
					if( i.b.addressMode != ir::PTXOperand::Immediate )
					{
						ir::LLVMZext sextB;
					
						sextB.a = extendedB;
						_doubleWidth( extendedB.type.type );
						extendedB.name = _tempRegister();
						sextB.d = extendedB;
					
						_add( sextB );
					}
					else
					{
						_doubleWidth( extendedB.type.type );
					}
				}
				
				ir::LLVMMul mul;
						
				mul.d = _destination( i );
				mul.a = extendedA;
				mul.b = extendedB;
			
				_add( mul );
			}
			else if( i.modifier & ir::PTXInstruction::lo )
			{
				ir::LLVMMul mul;
						
				mul.d = _destination( i );
				mul.a = _translate( i.a );
				mul.b = _translate( i.b );
			
				_add( mul );
			}
			else
			{
				if( ir::PTXOperand::s64 == i.type )
				{
					ir::LLVMCall call;
					call.name = "@__ocelot_mul_hi_s64";
				
					call.d = _destination( i );
					call.parameters.push_back( _translate( i.a ) );
					call.parameters.push_back( _translate( i.b ) );
					
					_add( call );
				}
				else if( ir::PTXOperand::u64 == i.type )
				{
					ir::LLVMCall call;
					call.name = "@__ocelot_mul_hi_u64";
				
					call.d = _destination( i );
					call.parameters.push_back( _translate( i.a ) );
					call.parameters.push_back( _translate( i.b ) );
					
					_add( call );
				}
				else
				{
					ir::LLVMInstruction::Operand 
						destination = _destination( i );
					ir::LLVMInstruction::Operand extendedA = _translate( i.a );
					ir::LLVMInstruction::Operand extendedB = _translate( i.b );
				
					if( ir::PTXOperand::isSigned( i.a.type ) )
					{
						if( i.a.addressMode != ir::PTXOperand::Immediate )
						{
							ir::LLVMSext sextA;
					
							sextA.a = extendedA;
							_doubleWidth( extendedA.type.type );
							extendedA.name = _tempRegister();
							sextA.d = extendedA;
					
							_add( sextA );
						}
						else
						{
							_doubleWidth( extendedA.type.type );
						}
					
						if( i.b.addressMode != ir::PTXOperand::Immediate )
						{
							ir::LLVMSext sextB;
					
							sextB.a = extendedB;
							_doubleWidth( extendedB.type.type );
							extendedB.name = _tempRegister();
							sextB.d = extendedB;
					
							_add( sextB );
						}
						else
						{
							_doubleWidth( extendedB.type.type );
						}
					}
					else
					{
						if( i.a.addressMode != ir::PTXOperand::Immediate )
						{
							ir::LLVMZext sextA;
					
							sextA.a = extendedA;
							_doubleWidth( extendedA.type.type );
							extendedA.name = _tempRegister();
							sextA.d = extendedA;
					
							_add( sextA );

						}
						else
						{
							_doubleWidth( extendedA.type.type );
						}
					
						if( i.b.addressMode != ir::PTXOperand::Immediate )
						{
							ir::LLVMZext sextB;
					
							sextB.a = extendedB;
							_doubleWidth( extendedB.type.type );
							extendedB.name = _tempRegister();
							sextB.d = extendedB;
					
							_add( sextB );
						}
						else
						{
							_doubleWidth( extendedB.type.type );
						}
					}
				
					ir::LLVMMul mul;
						
					mul.d = extendedA;
					mul.d.name = _tempRegister();
					mul.a = extendedA;
					mul.b = extendedB;
			
					_add( mul );
				
					ir::LLVMInstruction::Operand 
						shiftedDestination = destination;
					shiftedDestination.name = _tempRegister();
					_doubleWidth( shiftedDestination.type.type );
				
					if( ir::PTXOperand::isSigned( i.a.type ) )
					{
						ir::LLVMAshr shift;
					
						shift.d = shiftedDestination;
						shift.a = mul.d;
						shift.b.constant = true;
						shift.b.type.category = 
							ir::LLVMInstruction::Type::Element;
						shift.b.type.type = ir::LLVMInstruction::I32;
						shift.b.i32 = ir::PTXOperand::bytes( i.a.type ) * 8;
					
						_add( shift );
					}
					else
					{
						ir::LLVMLshr shift;
					
						shift.d = shiftedDestination;
						shift.a = mul.d;
						shift.b.constant = true;
						shift.b.type.category = 
							ir::LLVMInstruction::Type::Element;
						shift.b.type.type = ir::LLVMInstruction::I32;
						shift.b.i32 = ir::PTXOperand::bytes( i.a.type ) * 8;
					
						_add( shift );
					}
				
					ir::LLVMTrunc truncate;
				
					truncate.d = destination;
					truncate.a = shiftedDestination;
				
					_add( truncate );
				}
			}
		}
	}

	void PTXToLLVMTranslator::_translateNeg( const ir::PTXInstruction& i )
	{
		if( ir::PTXOperand::isFloat( i.type ) )
		{
			ir::LLVMFsub sub;
		
			sub.d = _destination( i );
			sub.b = _translate( i.a );
			sub.a = sub.b;
			sub.a.constant = true;
			sub.a.i64 = 0;
		
			_add( sub );
		}
		else
		{
			ir::LLVMSub sub;
		
			sub.d = _destination( i );
			sub.b = _translate( i.a );
			sub.a = sub.b;
			sub.a.constant = true;
			sub.a.i64 = 0;
		
			_add( sub );
		}
	}

	void PTXToLLVMTranslator::_translateNot( const ir::PTXInstruction& i )
	{
		ir::LLVMXor Not;
		
		Not.d = _destination( i );
		Not.a = _translate( i.a );
		Not.b = Not.a;
		Not.b.constant = true;
		Not.b.i64 = -1;
		
		_add( Not );
	}

	void PTXToLLVMTranslator::_translateOr( const ir::PTXInstruction& i )
	{
		ir::LLVMOr Or;
		
		Or.d = _destination( i );
		Or.a = _translate( i.a );
		Or.b = _translate( i.b );

		_add( Or );
	}

	void PTXToLLVMTranslator::_translatePmevent( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		call.name = "@pmevent";
		
		call.parameters.resize( 1 );
		call.parameters[0] = _translate( i.a );
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateRcp( const ir::PTXInstruction& i )
	{
		ir::LLVMFdiv div;
		
		div.d = _destination( i );
		div.b = _translate( i.a );
		div.a = div.b;
		div.a.constant = true;
		
		if( i.a.type == ir::PTXOperand::f32 )
		{
			div.a.f32 = 1.0;
		}
		else
		{
			div.a.f64 = 1.0;
		}
		
		_add( div );
	}

	void PTXToLLVMTranslator::_translateRed( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		call.name = "@reduction";
		
		call.parameters.resize( 4 );
		call.parameters[0].type.type = ir::LLVMInstruction::I32;
		call.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[0].i32 = i.addressSpace;

		call.parameters[1].type.type = ir::LLVMInstruction::I32;
		call.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[1].i32 = i.reductionOperation;

		call.parameters[2] = _translate( i.a );
		call.parameters[3] = _translate( i.b );
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateRem( const ir::PTXInstruction& i )
	{
		ir::LLVMInstruction::Operand destination = _destination( i );
		
		if( ir::PTXOperand::isSigned( i.type ) )
		{
			ir::LLVMSrem rem;
			
			rem.d = destination;
			rem.a = _translate( i.a );
			rem.b = _translate( i.b );
			
			_add( rem );
		}
		else
		{
			ir::LLVMUrem rem;
			
			rem.d = destination;
			rem.a = _translate( i.a );
			rem.b = _translate( i.b );
			
			_add( rem );			
		}
	}

	void PTXToLLVMTranslator::_translateRet( const ir::PTXInstruction& i )
	{
		_yield( i.reentryPoint );
	}

	void PTXToLLVMTranslator::_translateRsqrt( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		if( i.modifier & ir::PTXInstruction::ftz )
		{
			call.name = "@__ocelot_rsqrtFtz";
		}
		else
		{
			call.name = "@__ocelot_rsqrt";
		}
		
		call.d = _destination( i );
		call.parameters.resize( 1 );
		call.parameters[0] = _translate( i.a );
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateSad( const ir::PTXInstruction& i )
	{
		ir::LLVMInstruction::Operand destination = _destination( i );
		
		if( ir::PTXOperand::isFloat( i.type ) )
		{
			ir::LLVMFcmp compare;
			
			compare.d.name = _tempRegister();
			compare.d.type.category = ir::LLVMInstruction::Type::Element;
			compare.d.type.type = ir::LLVMInstruction::I1;
			compare.a = _translate( i.a );
			compare.b = _translate( i.b );
			compare.comparison = ir::LLVMInstruction::Olt;
			
			_add( compare );
			
			ir::LLVMSub subtract;
			
			subtract.d = destination;
			subtract.d.name = _tempRegister();
			subtract.a = compare.b;
			subtract.b = compare.a;
			
			_add( subtract );

			ir::LLVMSub subtract1;
			
			subtract1.d = destination;
			subtract1.d.name = _tempRegister();
			subtract1.a = compare.a;
			subtract1.b = compare.b;
			
			_add( subtract1 );
			
			ir::LLVMSelect select;
			
			select.condition = compare.d;
			select.d = destination;
			select.d.name = _tempRegister();
			select.a = subtract.d;
			select.b = subtract1.d;
			
			_add( select );
			
			ir::LLVMFadd add;
			
			add.d = destination;
			add.a = _translate( i.c );
			add.b = select.d;
			
			_add( add );
		}
		else
		{
			ir::LLVMIcmp compare;
			
			compare.d.name = _tempRegister();
			compare.d.type.category = ir::LLVMInstruction::Type::Element;
			compare.d.type.type = ir::LLVMInstruction::I1;
			compare.a = _translate( i.a );
			compare.b = _translate( i.b );
			
			if( ir::PTXOperand::isSigned( i.type ) )
			{
				compare.comparison = ir::LLVMInstruction::Slt;
			}
			else
			{
				compare.comparison = ir::LLVMInstruction::Ult;			
			}
			
			_add( compare );
			
			ir::LLVMSub subtract;
			
			subtract.d = destination;
			subtract.d.name = _tempRegister();
			subtract.a = compare.b;
			subtract.b = compare.a;
			
			_add( subtract );

			ir::LLVMSub subtract1;
			
			subtract1.d = destination;
			subtract1.d.name = _tempRegister();
			subtract1.a = compare.a;
			subtract1.b = compare.b;
			
			_add( subtract1 );
			
			ir::LLVMSelect select;
			
			select.condition = compare.d;
			select.d = destination;
			select.d.name = _tempRegister();
			select.a = subtract.d;
			select.b = subtract1.d;
			
			_add( select );
			
			ir::LLVMAdd add;
			
			add.d = destination;
			add.a = _translate( i.c );
			add.b = select.d;
			
			_add( add );		
		}
	}

	void PTXToLLVMTranslator::_translateSelP( const ir::PTXInstruction& i )
	{
		ir::LLVMSelect select;
		
		select.d = _destination( i );
		select.a = _translate( i.a );
		select.b = _translate( i.b );
		select.condition = _translate( i.c );
		
		_add( select );
	}

	void PTXToLLVMTranslator::_translateSet( const ir::PTXInstruction& i )
	{
		ir::LLVMInstruction::Operand d = _destination( i );

		ir::LLVMInstruction::Operand comparison; 
		comparison.name = _tempRegister();
		comparison.type.category = ir::LLVMInstruction::Type::Element;
		comparison.type.type = ir::LLVMInstruction::I1;

		if( ir::PTXOperand::isFloat( i.a.type ) )
		{
			ir::LLVMFcmp fcmp;
			
			fcmp.d = comparison;
			fcmp.a = _translate( i.a );
			fcmp.b = _translate( i.b );
			fcmp.comparison = _translate( i.comparisonOperator, false, false );
			
			_add( fcmp );
		}
		else
		{
			ir::LLVMIcmp icmp;
					
			icmp.d = comparison;
			icmp.a = _translate( i.a );
			icmp.b = _translate( i.b );
			icmp.comparison = _translate( i.comparisonOperator, true, 
				ir::PTXOperand::isSigned( i.a.type ) );
			
			_add( icmp );		
		}
		
		if( i.c.addressMode == ir::PTXOperand::Register )
		{
			ir::LLVMInstruction::Operand c = _translate( i.c );
		
			if( i.c.condition == ir::PTXOperand::InvPred )
			{
				ir::LLVMXor Not;
				
				Not.d = c;
				Not.d.name = _tempRegister();
				Not.a = c;
				Not.b = c;
				Not.b.constant = true;
				Not.b.i1 = 1;
			
				_add( Not );

				c = Not.d;
			}
					
			switch( i.booleanOperator )
			{
				case ir::PTXInstruction::BoolAnd:
				{
					ir::LLVMAnd And;
					
					And.d = comparison;
					And.d.name = _tempRegister();
					And.a = c;
					And.b = comparison;
					
					_add( And );
					
					comparison.name = And.d.name;
					
					break;
				}
				case ir::PTXInstruction::BoolOr:
				{
					ir::LLVMOr Or;
					
					Or.d = comparison;
					Or.d.name = _tempRegister();
					Or.a = c;
					Or.b = comparison;
					
					_add( Or );
					
					comparison.name = Or.d.name;
					
					break;
				}
				case ir::PTXInstruction::BoolXor:
				{
					ir::LLVMXor Xor;
					
					Xor.d = d;
					Xor.d.name = _tempRegister();
					Xor.a = c;
					Xor.b = comparison;
					
					_add( Xor );
					
					comparison.name = Xor.d.name;

					break;
				}
				default:
				{
					break;
				}
			}
		}

		ir::LLVMSelect select;
		
		select.condition = comparison;
		select.d = d;
		select.a = d;
		select.b = d;
		select.a.constant = true;
		select.b.constant = true;
		
		if( ir::PTXOperand::f64 == i.type )
		{
			select.a.f64 = 1.0;
			select.b.f64 = 0.0;
		}
		else if( ir::PTXOperand::f32 == i.type )
		{
			select.a.f32 = 1.0;
			select.b.f32 = 0.0;		
		}
		else
		{
			select.a.i64 = -1;
			select.b.f64 = 0;		
		}
		
		_add( select );
	}

	void PTXToLLVMTranslator::_translateSetP( const ir::PTXInstruction& i )
	{
		ir::LLVMInstruction::Operand d = _destination( i );
		ir::LLVMInstruction::Operand tempD = d;

		if( i.c.addressMode == ir::PTXOperand::Register )
		{
			tempD.name = _tempRegister();
		}

		if( ir::PTXOperand::isFloat( i.a.type ) )
		{
			ir::LLVMFcmp fcmp;
			
			fcmp.d = tempD;
			fcmp.a = _translate( i.a );
			fcmp.b = _translate( i.b );
			fcmp.comparison = _translate( i.comparisonOperator, false, false );
			
			_add( fcmp );
		}
		else
		{
			ir::LLVMIcmp icmp;
					
			icmp.d = tempD;
			icmp.a = _translate( i.a );
			icmp.b = _translate( i.b );
			icmp.comparison = _translate( i.comparisonOperator, true, 
				ir::PTXOperand::isSigned( i.type ) );
			
			_add( icmp );
		}
		
		ir::LLVMInstruction::Operand pd = d;
		ir::LLVMInstruction::Operand pq;
		
		if( i.pq.addressMode != ir::PTXOperand::Invalid )
		{
			pq = _translate( i.pq );
		}
		
		if( i.c.addressMode == ir::PTXOperand::Register )
		{
			ir::LLVMXor Not;

			if( i.pq.addressMode != ir::PTXOperand::Invalid )
			{
				Not.d = tempD;
				Not.d.name = _tempRegister();
				Not.a = tempD;
				Not.b.type.category = ir::LLVMInstruction::Type::Element;
				Not.b.type.type = ir::LLVMInstruction::I1;
				Not.b.constant = true;
				Not.b.i1 = true;
			
				_add( Not );
			}
					
			switch( i.booleanOperator )
			{
				case ir::PTXInstruction::BoolAnd:
				{
					ir::LLVMAnd And;
					
					And.d = pd;
					And.a = _translate( i.c );
					And.b = tempD;
					
					_add( And );
					
					if( i.pq.addressMode != ir::PTXOperand::Invalid )
					{
						And.d = pq;
						And.b = Not.d;
					
						_add( And );
					}
					break;
				}
				case ir::PTXInstruction::BoolOr:
				{
					ir::LLVMOr Or;
					
					Or.d = pd;
					Or.a = _translate( i.c );
					Or.b = tempD;
					
					_add( Or );
					
					if( i.pq.addressMode != ir::PTXOperand::Invalid )
					{
						Or.d = pq;
						Or.b = Not.d;
					
						_add( Or );
					}
					break;
				}
				case ir::PTXInstruction::BoolXor:
				{
					ir::LLVMXor Xor;
					
					Xor.d = pd;
					Xor.a = _translate( i.c );
					Xor.b = tempD;
					
					_add( Xor );

					if( i.pq.addressMode != ir::PTXOperand::Invalid )
					{
						Xor.d = pq;
						Xor.b = Not.d;
					
						_add( Xor );
					}
					break;
				}
				default:
				{
					break;
				}
			}
		}
	}

	void PTXToLLVMTranslator::_translateShl( const ir::PTXInstruction& i )
	{
		ir::LLVMShl shift;
		
		shift.d = _destination( i );
		shift.a = _translate( i.a );
		shift.b = _translate( i.b );
		
		_add( shift );
	}

	void PTXToLLVMTranslator::_translateShr( const ir::PTXInstruction& i )
	{
		if( ir::PTXOperand::isSigned( i.type ) )
		{
			ir::LLVMAshr shift;
			
			shift.d = _destination( i );
			shift.a = _translate( i.a );
			shift.b = _translate( i.b );
			
			_add( shift );
		}
		else
		{
			ir::LLVMLshr shift;
			
			shift.d = _destination( i );
			shift.a = _translate( i.a );
			shift.b = _translate( i.b );
			
			_add( shift );
		}
	}

	void PTXToLLVMTranslator::_translateSin( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		if( i.modifier & ir::PTXInstruction::ftz )
		{
			call.name = "@__ocelot_sinFtz";
		}
		else
		{
			call.name = "@__ocelot_sinf";
		}
		
		call.d = _destination( i );
		call.parameters.resize( 1 );
		call.parameters[0] = _translate( i.a );
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateSlCt( const ir::PTXInstruction& i )
	{
	
		ir::LLVMInstruction::Operand comparison;
		
		comparison.type.category = ir::LLVMInstruction::Type::Element;
		comparison.type.type = ir::LLVMInstruction::I1;
		comparison.name = _tempRegister();
	
		if( ir::PTXOperand::isFloat( i.c.type ) )
		{
			ir::LLVMFcmp compare;
			
			compare.d = comparison;
			compare.a = _translate( i.c );
			compare.b = compare.a;
			compare.b.constant = true;
			compare.b.f32 = 0;
			compare.comparison = ir::LLVMInstruction::Oge;
			
			_add( compare );
		}
		else
		{
			ir::LLVMIcmp compare;
			
			compare.d = comparison;
			compare.a = _translate( i.c );
			compare.b = compare.a;
			compare.b.constant = true;
			compare.b.i32 = 0;
			compare.comparison = ir::LLVMInstruction::Sge;
			
			_add( compare );		
		}
		
		ir::LLVMSelect select;
		select.d = _destination( i );
		select.condition = comparison;
		select.a = _translate( i.a );
		select.b = _translate( i.b );
		
		_add( select );
	}

	void PTXToLLVMTranslator::_translateSqrt( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		if( i.modifier & ir::PTXInstruction::ftz )
		{
			call.name = "@__ocelot_sqrtFtz";
		}
		else if( i.a.type == ir::PTXOperand::f64 )
		{
			call.name = "@__ocelot_sqrt";
		}
		else
		{
			call.name = "@__ocelot_sqrtf";
		}
		
		call.d = _destination( i );
		call.parameters.resize( 1 );
		call.parameters[0] = _translate( i.a );
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateSt( const ir::PTXInstruction& i )
	{
		#if(USE_VECTOR_INSTRUCTIONS == 1)
		ir::LLVMStore store;

		if( i.vec == ir::PTXOperand::v1 )
		{
			if( _translate( i.type ) != _translate( i.a.type ) )
			{
				ir::LLVMInstruction::Operand temp = _translate( i.a );
				temp.name = _tempRegister();
				temp.type.type = _translate( i.type );
				_convert( temp, i.type, _translate( i.a ), i.a.type );
				store.a = temp;		
			}
			else
			{
				store.a = _translate( i.a );
			}
		}
		else
		{
			store.a = _translate( i.a.array.front() );
			store.a.type.vector = i.vec;
			store.a.type.category = ir::LLVMInstruction::Type::Vector;
			store.a.type.type = _translate( i.type );
		}

		store.d = _getLoadOrStorePointer( i.d, i.addressSpace, 
			_translate( i.type ), i.vec );
		
		if( i.volatility == ir::PTXInstruction::Volatile )
		{
			store.isVolatile = true;
		}
		
		store.alignment = i.vec * ir::PTXOperand::bytes( i.type );

		if( i.vec != ir::PTXOperand::v1 )
		{
			store.a = _translate( i.a.array.front() );
			store.a.type.vector = i.vec;
			store.a.type.category = ir::LLVMInstruction::Type::Vector;
			store.a.type.type = _translate( i.type );

			ir::PTXOperand::Array::const_iterator 
				source = i.a.array.begin();

			ir::LLVMInsertelement insertOne;
		
			insertOne.d = store.a;
			insertOne.d.name = _tempRegister();
			insertOne.a = store.a;
			insertOne.a.constant = true;
			
			ir::LLVMInstruction::Value value;
			value.i64 = 0;
			
			insertOne.a.values.assign( i.vec, value );
			
			if( i.type != source->type )
			{
				ir::LLVMInstruction::Operand temp = _translate( *source );
				temp.name = _tempRegister();
				temp.type.type = _translate( i.type );
				_convert( temp, i.type, _translate( *source ), source->type );
				insertOne.b = temp;
			}
			else
			{
				insertOne.b = _translate( *source );
			}

			insertOne.c.type.category = ir::LLVMInstruction::Type::Element;
			insertOne.c.type.type = ir::LLVMInstruction::I32;
			insertOne.c.constant = true;
			insertOne.c.i32 = 0;
			
			_add( insertOne );
			
			std::string currentSource = insertOne.d.name;
			
			for( ++source; source != i.a.array.end(); ++source )
			{
				ir::LLVMInsertelement insert;

				insert.d = store.a;
				insert.d.name = _tempRegister();
				if( ++ir::PTXOperand::Array::const_iterator( source ) 
					== i.a.array.end() )
				{
					store.a.name = insert.d.name;
				}
				insert.a = store.a;
				insert.a.name = currentSource;
				if( i.type != source->type )
				{
					ir::LLVMInstruction::Operand temp = _translate( *source );
					temp.name = _tempRegister();
					temp.type.type = _translate( i.type );
					_convert( temp, i.type, _translate( *source ), 
						source->type );
					insert.b = temp;
				}
				else
				{
					insert.b = _translate( *source );
				}
				insert.c.type.category = ir::LLVMInstruction::Type::Element;
				insert.c.type.type = ir::LLVMInstruction::I32;
				insert.c.constant = true;
				insert.c.i32 = std::distance( i.a.array.begin(), source );
				
				_add( insert );
				currentSource = insert.d.name;
			}
		}
		
		_check( i.addressSpace, store.d, store.alignment, i.statementIndex );
		_add( store );
		#else
		ir::LLVMStore store;

		if( i.volatility == ir::PTXInstruction::Volatile )
		{
			store.isVolatile = true;
		}
	
		store.alignment = ir::PTXOperand::bytes( i.type );
		ir::LLVMInstruction::Operand address = _getLoadOrStorePointer( 
			i.d, i.addressSpace, _translate( i.type ), ir::PTXOperand::v1 );

		if( i.vec == ir::PTXOperand::v1 )
		{
			store.d = address;

			if( _translate( i.type ) != _translate( i.a.type ) )
			{
				ir::LLVMInstruction::Operand temp = _translate( i.a );
				temp.name = _tempRegister();
				temp.type.type = _translate( i.type );
				_convert( temp, i.type, _translate( i.a ), i.a.type );
				store.a = temp;
			}
			else
			{
				store.a = _translate( i.a );
			}

			_check( i.addressSpace, store.d, 
				store.alignment, i.statementIndex );
			_add( store );
		}
		else
		{
			unsigned int index = 0;
			for( ir::PTXOperand::Array::const_iterator 
				source = i.a.array.begin(); 
				source != i.a.array.end(); ++source, ++index)
			{
				ir::LLVMGetelementptr get;
			
				get.a = address;
				get.d = get.a;
				get.d.name = _tempRegister();
				get.indices.push_back( index );
			
				_add( get );

				store.d = get.d;

				if( _translate( i.type ) != _translate( source->type ) )
				{
					ir::LLVMInstruction::Operand temp = _translate( *source );
					temp.name = _tempRegister();
					temp.type.type = _translate( i.type );
					_convert( temp, i.type, _translate( *source ), source->type );
					store.a = temp;
				}
				else
				{
					store.a = _translate( *source );
				}

				_check( i.addressSpace, store.d, 
					store.alignment, i.statementIndex );
				_add( store );
			}
		}
		#endif
	}

	void PTXToLLVMTranslator::_translateSub( const ir::PTXInstruction& i )
	{
		if( ir::PTXOperand::isFloat( i.type ) )
		{
			ir::LLVMFsub sub;
		
			sub.d = _destination( i );
			sub.a = _translate( i.a );
			sub.b = _translate( i.b );
		
			_add( sub );
			
			if( i.modifier & ir::PTXInstruction::sat )
			{
				ir::LLVMFcmp compare;
				
				compare.d.name = _tempRegister();
				compare.d.type.type = ir::LLVMInstruction::I1;
				compare.d.type.category = ir::LLVMInstruction::Type::Element;
				compare.comparison = ir::LLVMInstruction::Ule;
				compare.a = sub.d;
				compare.b.type.type = compare.a.type.type;
				compare.b.type.category = ir::LLVMInstruction::Type::Element;
				compare.b.constant = true;
				if( compare.b.type.type == ir::LLVMInstruction::F32 )
				{
					compare.b.f32 = 0;
				}
				else
				{
					compare.b.f64 = 0;
				}
				
				ir::LLVMSelect select;
				
				select.d.name = _tempRegister();
				select.d.type.type = sub.d.type.type;
				select.d.type.category = sub.d.type.category;
				select.condition = compare.d;
				select.a = compare.b;
				select.b = sub.d;
				
				_add( compare );
				_add( select );
			}
		}
		else
		{
			if( i.modifier & ir::PTXInstruction::sat )
			{
				assert( i.type == ir::PTXOperand::s32 );
				
				ir::LLVMSext extendA;
				ir::LLVMSext extendB;
								
				extendA.a = _translate( i.a );
				extendA.d.type.type = ir::LLVMInstruction::I64;
				extendA.d.type.category = ir::LLVMInstruction::Type::Element;
				extendA.d.name = _tempRegister();
				
				_add( extendA );
				
				extendB.a = _translate( i.b );
				extendB.d.type.type = ir::LLVMInstruction::I64;
				extendB.d.type.category = ir::LLVMInstruction::Type::Element;
				extendB.d.name = _tempRegister();
				
				_add( extendB );
				
				ir::LLVMSub sub;
				
				sub.a = extendA.d;
				sub.b = extendB.d;
				sub.d.name = _tempRegister();
				sub.d.type.type = ir::LLVMInstruction::I64;
				sub.d.type.category = ir::LLVMInstruction::Type::Element;
				
				_add( sub );
				
				ir::LLVMIcmp compare;
				
				compare.d.name = _tempRegister();
				compare.d.type.type = ir::LLVMInstruction::I1;
				compare.d.type.category = ir::LLVMInstruction::Type::Element;
				compare.comparison = ir::LLVMInstruction::Slt;
				compare.a = sub.d;
				compare.b.type.type = ir::LLVMInstruction::I64;
				compare.b.type.category = ir::LLVMInstruction::Type::Element;
				compare.b.constant = true;
				compare.b.i64 = INT_MIN;

				_add( compare );
				
				ir::LLVMSelect select;
				
				select.d.name = _tempRegister();
				select.d.type.type = ir::LLVMInstruction::I64;
				select.d.type.category = ir::LLVMInstruction::Type::Element;

				select.condition = compare.d;
				select.a = compare.b;
				select.b = compare.a;
				
				_add( select );
				
				compare.d.name = _tempRegister();
				compare.comparison = ir::LLVMInstruction::Sgt;
				compare.b.i64 = INT_MAX;
				compare.a = select.d;
				
				_add( compare );

				select.condition = compare.d;
				select.a = compare.b;
				select.b = compare.a;
				select.d.name = _tempRegister();

				_add( select );
				
				ir::LLVMTrunc truncate;
				
				truncate.a = select.d;
				truncate.d = _destination( i );
				
				_add( truncate );
			}
			else if( i.carry & ir::PTXInstruction::CC )
			{
				ir::LLVMInstruction::Operand extendedA( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				ir::LLVMInstruction::Operand extendedB( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				
				if( ir::PTXOperand::isSigned( i.type ) )
				{
					ir::LLVMSext sext;
					
					sext.d = extendedA;
					sext.a = _translate( i.a );
					
					_add( sext );
					
					sext.d = extendedB;
					sext.a = _translate( i.b );
					
					_add( sext );
				}
				else
				{
					ir::LLVMZext zext;
					
					zext.d = extendedA;
					zext.a = _translate( i.a );
					
					_add( zext );
					
					zext.d = extendedB;
					zext.a = _translate( i.b );
					
					_add( zext );					
				}
				
				ir::LLVMInstruction::Operand extendedD( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				
				ir::LLVMSub sub;
				
				sub.a = extendedA;
				sub.b = extendedB;
				sub.d = extendedD;
				
				_add( sub );
				
				ir::LLVMTrunc truncate;
				
				truncate.d = _destination( i );
				truncate.a = extendedD;
				
				_add( truncate );
				
				ir::LLVMLshr shift;
				
				shift.d = ir::LLVMInstruction::Operand ( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				shift.a = extendedD;
				shift.b.type = ir::LLVMInstruction::Type( 
					ir::LLVMInstruction::I32, 
					ir::LLVMInstruction::Type::Element );
				shift.b.constant = true;
				shift.b.i32 = 32;
				
				_add( shift );
				
				ir::LLVMAnd mask;
				
				mask.d = ir::LLVMInstruction::Operand ( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				mask.a = shift.d;
				mask.b.type = ir::LLVMInstruction::Type( 
					ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element );
				mask.b.constant = true;
				mask.b.i64 = 1;
				
				_add( mask );
				
				truncate.d = _translate( i.pq );
				truncate.a = mask.d;
				
				_add( truncate );			
			}
			else
			{
				ir::LLVMSub sub;

				sub.d = _destination( i );
				sub.a = _translate( i.a );
				sub.b = _translate( i.b );
				
				_add( sub );
			}
		}
	}

	void PTXToLLVMTranslator::_translateSubC( const ir::PTXInstruction& i )
	{	
		if( i.carry & ir::PTXInstruction::CC )
		{
				ir::LLVMInstruction::Operand extendedA( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				ir::LLVMInstruction::Operand extendedB( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				ir::LLVMInstruction::Operand extendedC( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				
				if( ir::PTXOperand::isSigned( i.type ) )
				{
					ir::LLVMSext sext;
					
					sext.d = extendedA;
					sext.a = _translate( i.a );
					
					_add( sext );
					
					sext.d = extendedB;
					sext.a = _translate( i.b );
					
					_add( sext );

					sext.d = extendedC;
					sext.a = _translate( i.c );
					
					_add( sext );
				}
				else
				{
					ir::LLVMZext zext;
					
					zext.d = extendedA;
					zext.a = _translate( i.a );
					
					_add( zext );
					
					zext.d = extendedB;
					zext.a = _translate( i.b );
					
					_add( zext );					

					zext.d = extendedC;
					zext.a = _translate( i.c );
					
					_add( zext );					
				}
				
				ir::LLVMInstruction::Operand extendedDt( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				ir::LLVMInstruction::Operand extendedD( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				
				ir::LLVMSub sub;
				
				sub.a = extendedA;
				sub.b = extendedB;
				sub.d = extendedDt;
				
				_add( sub );

				ir::LLVMAdd add;

				add.a = extendedDt;
				add.b = extendedC;
				add.d = extendedD;
				
				_add( add );
				
				ir::LLVMTrunc truncate;
				
				truncate.d = _destination( i );
				truncate.a = extendedD;
				
				_add( truncate );
				
				ir::LLVMLshr shift;
				
				shift.d = ir::LLVMInstruction::Operand ( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				shift.a = extendedD;
				shift.b.type = ir::LLVMInstruction::Type( 
					ir::LLVMInstruction::I32, 
					ir::LLVMInstruction::Type::Element );
				shift.b.constant = true;
				shift.b.i32 = 32;
				
				_add( shift );
				
				ir::LLVMAnd mask;
				
				mask.d = ir::LLVMInstruction::Operand ( _tempRegister(),
					ir::LLVMInstruction::Type( ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element ) );
				mask.a = shift.d;
				mask.b.type = ir::LLVMInstruction::Type( 
					ir::LLVMInstruction::I64, 
					ir::LLVMInstruction::Type::Element );
				mask.b.constant = true;
				mask.b.i64 = 1;
				
				_add( mask );
				
				truncate.d = _translate( i.pq );
				truncate.a = mask.d;
				
				_add( truncate );
		}
		else
		{
			ir::LLVMInstruction::Operand destination = _destination( i );
		
			ir::LLVMSub sub;
			
			sub.d = destination;
			sub.d.name = _tempRegister();
			sub.a = _translate( i.a );
			sub.b = _translate( i.b );
			
			_add( sub );
			
			ir::LLVMAdd add;
			
			add.a = sub.d;
			add.d = destination;
			add.b = _translate( i.c );
			
			_add( add );
		}	
	}

	void PTXToLLVMTranslator::_translateTex( const ir::PTXInstruction& i )
	{
		_usesTextures = true;
	
		ir::LLVMCall call;
		
		ir::LLVMInstruction::Operand d1 = _translate( i.d.array[0] );
		ir::LLVMInstruction::Operand d2 = _translate( i.d.array[1] );
		ir::LLVMInstruction::Operand d3 = _translate( i.d.array[2] );
		ir::LLVMInstruction::Operand d4 = _translate( i.d.array[3] );
		
		ir::LLVMInstruction::Operand d;
		d.type.category = ir::LLVMInstruction::Type::Pointer;
		
		switch( i.d.type )
		{
			case ir::PTXOperand::u32: /* fall through */
			case ir::PTXOperand::s32:
			{
				d.name = "%integerTexture";
				d.type.type = ir::LLVMInstruction::I32;
				break;
			}
			case ir::PTXOperand::f32:
			{
				d.name = "%floatingPointTexture";
				d.type.type = ir::LLVMInstruction::F32;
				break;
			}
			default : assertM( false, "Invalid destination type " 
				<< ir::PTXOperand::toString( i.d.type ) << " for tex" );
		}
		
		switch( i.geometry )
		{
			case ir::PTXInstruction::_1d:
			{
				call.name = "@__ocelot_tex_1d";
				call.parameters.resize( 4 );
				call.parameters[0] = d;
				call.parameters[3] = _translate( i.c.array[0] );
				break;
			}
			case ir::PTXInstruction::_2d:
				call.name = "@__ocelot_tex_2d";
				call.parameters.resize( 5 );
				call.parameters[0] = d;
				call.parameters[3] = _translate( i.c.array[0] );
				call.parameters[4] = _translate( i.c.array[1] );
				break;
			case ir::PTXInstruction::_3d:
				call.name = "@__ocelot_tex_3d";
				call.parameters.resize( 7 );
				call.parameters[0] = d;
				call.parameters[3] = _translate( i.c.array[0] );
				call.parameters[4] = _translate( i.c.array[1] );
				call.parameters[5] = _translate( i.c.array[2] );
				call.parameters[6] = _translate( i.c.array[3] );
				break;
			default: assertM( false, "Invalid texture geometry" );
		}
		
		call.parameters[1] = _context();
		
		call.parameters[2].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[2].type.type = ir::LLVMInstruction::I32;
		call.parameters[2].constant = true;
		call.parameters[2].i32 = i.a.reg;
		
		switch( i.d.type )
		{
			case ir::PTXOperand::u32:
			{
				switch( i.type )
				{
					case ir::PTXOperand::u32:
					{
						call.name += "_uu";
						break;
					}
					case ir::PTXOperand::f32:
					{
						call.name += "_uf";
						break;
					}
					case ir::PTXOperand::s32:
					{
						call.name += "_us";
						break;
					}
					default : assertM( false, "Invalid source type " 
						<< ir::PTXOperand::toString( i.c.type ) << " for tex" );
				}
				break;
			}
			case ir::PTXOperand::s32:
			{
				switch( i.type )
				{
					case ir::PTXOperand::u32:
					{
						call.name += "_su";
						break;
					}
					case ir::PTXOperand::f32:
					{
						call.name += "_sf";
						break;
					}
					case ir::PTXOperand::s32:
					{
						call.name += "_ss";
						break;
					}
					default : assertM( false, "Invalid source type " 
						<< ir::PTXOperand::toString( i.c.type ) << " for tex" );
				}
				break;
			}
			case ir::PTXOperand::f32:
			{
				switch( i.type )
				{
					case ir::PTXOperand::u32:
					{
						call.name += "_fu";
						break;
					}
					case ir::PTXOperand::f32:
					{
						call.name += "_ff";
						break;
					}
					case ir::PTXOperand::s32:
					{
						call.name += "_fs";
						break;
					}
					default : assertM( false, "Invalid source type " 
						<< ir::PTXOperand::toString( i.c.type ) << " for tex" );
				}
				break;
			}
			default : assertM( false, "Invalid destination type " 
				<< ir::PTXOperand::toString( i.d.type ) << " for tex" );
		}
		
		_add( call );
		
		ir::LLVMLoad load;
			
		load.d = d1;
		load.a = d;
	
		_add( load );
	
		ir::LLVMGetelementptr get;
		
		get.d = d;
		get.d.name = _tempRegister();
		get.a = d;
		get.indices.push_back( 1 );
		
		_add( get );

		load.d = d2;
		load.a = get.d;
	
		_add( load );
	
		get.d = d;
		get.d.name = _tempRegister();
		get.a = d;
		get.indices.back() = 2;
		
		_add( get );

		load.d = d3;
		load.a = get.d;
	
		_add( load );		
		
		get.d = d;
		get.d.name = _tempRegister();
		get.a = d;
		get.indices.back() = 3;
		
		_add( get );

		load.d = d4;
		load.a = get.d;
	
		_add( load );
	}

	void PTXToLLVMTranslator::_translateTrap( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		call.name = "@trap";
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateVote( const ir::PTXInstruction& i )
	{
		ir::LLVMCall call;
		
		call.name = "@__ocelot_vote";
		
		call.d = _destination( i );
		call.parameters.resize( 3 );
		call.parameters[0] = _translate( i.a );
		call.parameters[1].type.type = ir::LLVMInstruction::I32;
		call.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[1].i32 = i.vote;
		call.parameters[1].constant = true;
		call.parameters[2].type.type = ir::LLVMInstruction::I1;
		call.parameters[2].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[2].i1 = i.b.condition == ir::PTXOperand::InvPred;
		call.parameters[2].constant = true;
		
		_add( call );
	}

	void PTXToLLVMTranslator::_translateXor( const ir::PTXInstruction& i )
	{
		ir::LLVMXor Xor;
		
		Xor.d = _destination( i );
		Xor.a = _translate( i.a );
		Xor.b = _translate( i.b );

		_add( Xor );
	}
	
	void PTXToLLVMTranslator::_bitcast( const ir::PTXInstruction& i )
	{
		_bitcast( i.d, i.a );
	}
	
	void PTXToLLVMTranslator::_bitcast( const ir::PTXOperand& d, 
		const ir::PTXOperand& a )
	{
		_bitcast( _translate( d ), _translate( a ), 
			ir::PTXOperand::isSigned( d.type ) );
	}
	
	void PTXToLLVMTranslator::_bitcast( const ir::LLVMInstruction::Operand& d, 
		const ir::LLVMInstruction::Operand& a, bool isSigned )
	{
		if( ir::LLVMInstruction::bits( d.type.type ) 
			== ir::LLVMInstruction::bits( a.type.type ) )
		{
			ir::LLVMBitcast cast;
			cast.d = d;
			cast.a = a;
		
			_add( cast );
		}
		else
		{
			ir::LLVMInstruction::Operand temp;
			
			temp.name = _tempRegister();
			temp.type.category = ir::LLVMInstruction::Type::Element;
			temp.type.type = ir::LLVMInstruction::getIntOfSize( 
				ir::LLVMInstruction::bits( a.type.type ) );
			
			_bitcast( temp, a );
			
			if( ir::LLVMInstruction::bits( d.type.type ) 
				< ir::LLVMInstruction::bits( a.type.type ) )
			{
				ir::LLVMTrunc truncate;
				
				truncate.d.name = _tempRegister();
				truncate.d.type.category = ir::LLVMInstruction::Type::Element;
				truncate.d.type.type = ir::LLVMInstruction::getIntOfSize( 
					ir::LLVMInstruction::bits( d.type.type ) );
				
				truncate.a = temp;
				
				_add( truncate );
				
				temp = truncate.d;
			}
			else
			{
				if( isSigned )
				{
					ir::LLVMSext extend;
				
					extend.d.name = _tempRegister();
					extend.d.type.category = ir::LLVMInstruction::Type::Element;
					extend.d.type.type = ir::LLVMInstruction::getIntOfSize( 
						ir::LLVMInstruction::bits( d.type.type ) );
				
					extend.a = temp;
				
					_add( extend );
				
					temp = extend.d;				
				}
				else
				{
					ir::LLVMZext extend;
				
					extend.d.name = _tempRegister();
					extend.d.type.category = ir::LLVMInstruction::Type::Element;
					extend.d.type.type = ir::LLVMInstruction::getIntOfSize( 
						ir::LLVMInstruction::bits( d.type.type ) );
				
					extend.a = temp;
				
					_add( extend );
				
					temp = extend.d;				
				}

			}
			
			_bitcast( d, temp );
		}
	}
		
	void PTXToLLVMTranslator::_convert( const ir::LLVMInstruction::Operand& d, 
		ir::PTXOperand::DataType dType, const ir::LLVMInstruction::Operand& a, 
		ir::PTXOperand::DataType aType, int modifier )
	{
		switch( aType )
		{
			case ir::PTXOperand::s8:
			{
				switch( dType )
				{
					case ir::PTXOperand::pred:
					case ir::PTXOperand::s16:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::s32:
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::b64:
					case ir::PTXOperand::s64:
					case ir::PTXOperand::u64:
					{
						ir::LLVMSext sext;
						sext.d = d;
						sext.a = a;
	
						_add( sext );
						break;
					}
					case ir::PTXOperand::s8:
					case ir::PTXOperand::u8:
					case ir::PTXOperand::b8:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::f16:
					case ir::PTXOperand::f64:
					case ir::PTXOperand::f32:
					{
						ir::LLVMSitofp sitofp;
						sitofp.d = d;
						sitofp.a = a;
						
						_add( sitofp );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::s16:
			{
				switch( dType )
				{
					case ir::PTXOperand::s8:
					case ir::PTXOperand::pred:
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					{
						ir::LLVMTrunc trunc;
						trunc.d = d;
						trunc.a = a;
	
						_add( trunc );
						break;
					}
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::s32:
					case ir::PTXOperand::b64:
					case ir::PTXOperand::u64:
					case ir::PTXOperand::s64:
					{
						ir::LLVMSext sext;
						sext.d = d;
						sext.a = a;
						
						_add( sext );
						break;
					}
					case ir::PTXOperand::s16:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::f16:
					case ir::PTXOperand::f64:
					case ir::PTXOperand::f32:
					{
						ir::LLVMSitofp sitofp;
						sitofp.d = d;
						sitofp.a = a;
						
						_add( sitofp );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::s32:
			{
				switch( dType )
				{
					case ir::PTXOperand::pred:
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					case ir::PTXOperand::s8:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::s16:
					{
						ir::LLVMTrunc trunc;
						trunc.d = d;
						trunc.a = a;
	
						_add( trunc );
						break;
					}
					case ir::PTXOperand::s32:
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::s64:
					case ir::PTXOperand::b64:
					case ir::PTXOperand::u64:
					{
						ir::LLVMSext sext;
						sext.d = d;
						sext.a = a;
						
						_add( sext );
						break;
					}
					case ir::PTXOperand::f16:
					case ir::PTXOperand::f64:
					case ir::PTXOperand::f32:
					{
						ir::LLVMSitofp sitofp;
						sitofp.d = d;
						sitofp.a = a;
						
						_add( sitofp );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::s64:
			{
				switch( dType )
				{
					case ir::PTXOperand::pred:
					case ir::PTXOperand::s8:
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					case ir::PTXOperand::s16:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::s32:
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					{
						ir::LLVMTrunc trunc;
						trunc.d = d;
						trunc.a = a;
	
						_add( trunc );
						break;
					}
					case ir::PTXOperand::s64:
					case ir::PTXOperand::b64:
					case ir::PTXOperand::u64:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::f16:
					case ir::PTXOperand::f64:
					case ir::PTXOperand::f32:
					{
						ir::LLVMSitofp sitofp;
						sitofp.d = d;
						sitofp.a = a;
						
						_add( sitofp );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::pred:
			case ir::PTXOperand::b8:
			case ir::PTXOperand::u8:
			{
				switch( dType )
				{
					case ir::PTXOperand::s16:
					case ir::PTXOperand::s32:
					case ir::PTXOperand::s64:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::b64:
					case ir::PTXOperand::u64:
					{
						ir::LLVMZext zext;
						zext.d = d;
						zext.a = a;
						
						_add( zext );
						break;
					}
					case ir::PTXOperand::pred:
					case ir::PTXOperand::s8:
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::f16:
					case ir::PTXOperand::f64:
					case ir::PTXOperand::f32:
					{
						ir::LLVMUitofp uitofp;
						uitofp.d = d;
						uitofp.a = a;
						
						_add( uitofp );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::b16:
			case ir::PTXOperand::u16:
			{
				switch( dType )
				{
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					case ir::PTXOperand::s8:
					case ir::PTXOperand::pred:
					{
						ir::LLVMTrunc trunc;
						trunc.d = d;
						trunc.a = a;
	
						_add( trunc );
						break;
					}
					case ir::PTXOperand::s32:
					case ir::PTXOperand::s64:
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::b64:
					case ir::PTXOperand::u64:
					{
						ir::LLVMZext zext;
						zext.d = d;
						zext.a = a;
						
						_add( zext );
						break;
					}
					case ir::PTXOperand::s16:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::f16:
					{
						assertM( false, "F16 type not supported" );
						break;
					}
					case ir::PTXOperand::f64:
					case ir::PTXOperand::f32:
					{
						ir::LLVMUitofp uitofp;
						uitofp.d = d;
						uitofp.a = a;
						
						_add( uitofp );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::b32:
			case ir::PTXOperand::u32:
			{
				switch( dType )
				{
					case ir::PTXOperand::pred:
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					case ir::PTXOperand::s8:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::s16:
					{
						ir::LLVMTrunc trunc;
						trunc.d = d;
						trunc.a = a;
	
						_add( trunc );
						break;
					}
					case ir::PTXOperand::b64:
					case ir::PTXOperand::u64:
					case ir::PTXOperand::s64:
					{
						ir::LLVMZext zext;
						zext.d = d;
						zext.a = a;
						
						_add( zext );
						break;
					}
					case ir::PTXOperand::b32:
					case ir::PTXOperand::s32:
					case ir::PTXOperand::u32:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::f16:
					{
						assertM( false, "F16 type not supported" );
						break;
					}
					case ir::PTXOperand::f64:
					case ir::PTXOperand::f32:
					{
						ir::LLVMUitofp uitofp;
						uitofp.d = d;
						uitofp.a = a;
						
						_add( uitofp );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::b64:
			case ir::PTXOperand::u64:
			{
				switch( dType )
				{
					case ir::PTXOperand::pred:
					case ir::PTXOperand::s8:
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::s16:
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::s32:
					{
						ir::LLVMTrunc trunc;
						trunc.d = d;
						trunc.a = a;
	
						_add( trunc );
						break;
					}
					case ir::PTXOperand::b64:
					case ir::PTXOperand::s64:
					case ir::PTXOperand::u64:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::f16:
					{
						assertM( false, "F16 type not supported" );
						break;
					}
					case ir::PTXOperand::f64:
					case ir::PTXOperand::f32:
					{
						ir::LLVMUitofp uitofp;
						uitofp.d = d;
						uitofp.a = a;
						
						_add( uitofp );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::f16:
			{
				switch( dType )
				{
					case ir::PTXOperand::s8:
					case ir::PTXOperand::s16:
					case ir::PTXOperand::s32:
					case ir::PTXOperand::s64:
					{
						ir::LLVMFptosi fptosi;
						fptosi.d = d;
						fptosi.a = a;
						
						_add( fptosi );
						break;
					}
					case ir::PTXOperand::pred:
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::b64:
					case ir::PTXOperand::u64:
					{
						ir::LLVMFptoui fptoui;
						fptoui.d = d;
						fptoui.a = a;
						
						_add( fptoui );
						break;
					}
					case ir::PTXOperand::f16:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::f32:
					case ir::PTXOperand::f64:
					{
						ir::LLVMFpext fpext;
						fpext.d = d;
						fpext.a = a;
						
						_add( fpext );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::f32:
			{
				ir::LLVMInstruction::Operand tempA = a;
				
				if( modifier & ir::PTXInstruction::rn )
				{
					ir::LLVMFcmp compare;
					
					compare.d.type.category 
						= ir::LLVMInstruction::Type::Element;
					compare.d.type.type = ir::LLVMInstruction::I1;
					compare.d.name = _tempRegister();
					compare.comparison = ir::LLVMInstruction::Olt;

					compare.a = tempA;
					compare.b.constant = true;
					compare.b.f32 = 0.0;
					compare.b.type.category 
						= ir::LLVMInstruction::Type::Element;
					compare.b.type.type = ir::LLVMInstruction::F32;
					
					_add( compare );
					
					ir::LLVMSelect select;
					
					select.d = tempA;
					select.d.name = _tempRegister();
					
					select.condition = compare.d;
					select.a = compare.b;
					select.a.f32 = -0.5;
					select.b = compare.b;
					select.b.f32 = 0.5;
					
					_add( select );
					
					ir::LLVMFadd add;
					
					add.d = tempA;
					add.d.name = _tempRegister();
					add.a = tempA;
					
					add.b = select.d;
					
					_add( add );

					ir::LLVMFptosi fptosi;
					
					fptosi.d.name = _tempRegister();
					fptosi.d.type.category = ir::LLVMInstruction::Type::Element;
					fptosi.d.type.type = ir::LLVMInstruction::I32;

					fptosi.a = add.d;
					
					_add( fptosi );

					ir::LLVMSitofp sitofp;
					
					sitofp.d.name = _tempRegister();
					sitofp.d.type.category = ir::LLVMInstruction::Type::Element;
					sitofp.d.type.type = ir::LLVMInstruction::F32;

					sitofp.a = fptosi.d;
					
					_add( sitofp );
					
					tempA = sitofp.d;
				}
				else if( modifier & ir::PTXInstruction::rm )
				{
					ir::LLVMFsub subtract;
					
					subtract.d.name = _tempRegister();
					subtract.d.type.category = ir::LLVMInstruction::Type::Element;
					subtract.d.type.type = ir::LLVMInstruction::F32;

					subtract.a = tempA;
					
					subtract.b.constant = true;
					subtract.b.f32 = 0.5;
					subtract.b.type.category 
						= ir::LLVMInstruction::Type::Element;
					subtract.b.type.type = ir::LLVMInstruction::F32;
					
					_add( subtract );
					
					tempA = subtract.d;
				}
				else if( modifier & ir::PTXInstruction::rp )
				{
					ir::LLVMFadd add;
					
					add.d.name = _tempRegister();
					add.d.type.category = ir::LLVMInstruction::Type::Element;
					add.d.type.type = ir::LLVMInstruction::F32;

					add.a = tempA;
					
					add.b.constant = true;
					add.b.f32 = 0.5;
					add.b.type.category 
						= ir::LLVMInstruction::Type::Element;
					add.b.type.type = ir::LLVMInstruction::F32;
					
					_add( add );
					
					tempA = add.d;
				}
				
				if( ir::PTXInstruction::sat & modifier )
				{
					ir::LLVMFcmp compare;
					
					compare.d.type.category 
						= ir::LLVMInstruction::Type::Element;
					compare.d.type.type = ir::LLVMInstruction::I1;
					compare.d.name = _tempRegister();
					compare.comparison = ir::LLVMInstruction::Olt;

					compare.a = tempA;
					compare.b.constant = true;
					compare.b.f32 = 1.0;
					compare.b.type.category 
						= ir::LLVMInstruction::Type::Element;
					compare.b.type.type = ir::LLVMInstruction::F32;
					
					_add( compare );
					
					ir::LLVMSelect select;
					
					select.d = tempA;
					select.d.name = _tempRegister();
					
					select.condition = compare.d;
					select.a = tempA;
					select.b = compare.b;
					
					_add( select );
					
					compare.d.name = _tempRegister();
					compare.a = select.d;
					compare.b.f32 = 0.0;
					
					_add( compare );
					
					select.d.name = _tempRegister();
					
					select.condition = compare.d;
					select.a = compare.b;
					select.b = compare.a;
					
					_add( select );
					
					tempA = select.d;			
				}
				
				switch( dType )
				{
					case ir::PTXOperand::s8:
					case ir::PTXOperand::s16:
					case ir::PTXOperand::s32:
					case ir::PTXOperand::s64:
					{
						ir::LLVMFptosi fptosi;
						fptosi.d = d;
						fptosi.a = tempA;
						
						_add( fptosi );
						break;
					}
					case ir::PTXOperand::pred:
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::b64:
					case ir::PTXOperand::u64:
					{
						ir::LLVMFptoui fptoui;
						fptoui.d = d;
						fptoui.a = tempA;
						
						_add( fptoui );
						break;
					}
					case ir::PTXOperand::f16:
					{
						ir::LLVMFptrunc fptrunc;
						fptrunc.d = d;
						fptrunc.a = tempA;
						
						_add( fptrunc );
						break;
					}
					case ir::PTXOperand::f32:
					{
						_bitcast( d, tempA );
						break;
					}
					case ir::PTXOperand::f64:
					{
						ir::LLVMFpext fpext;
						fpext.d = d;
						fpext.a = tempA;
						
						_add( fpext );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false, "Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::f64:
			{
				switch( dType )
				{
					case ir::PTXOperand::s8:
					case ir::PTXOperand::s16:
					case ir::PTXOperand::s32:
					case ir::PTXOperand::s64:
					{
						ir::LLVMFptosi fptosi;
						fptosi.d = d;
						fptosi.a = a;
						
						_add( fptosi );
						break;
					}
					case ir::PTXOperand::pred:
					case ir::PTXOperand::b8:
					case ir::PTXOperand::u8:
					case ir::PTXOperand::b16:
					case ir::PTXOperand::u16:
					case ir::PTXOperand::b32:
					case ir::PTXOperand::u32:
					case ir::PTXOperand::b64:
					case ir::PTXOperand::u64:
					{
						ir::LLVMFptoui fptoui;
						fptoui.d = d;
						fptoui.a = a;
						
						_add( fptoui );
						break;
					}
					case ir::PTXOperand::f16:
					{
						ir::LLVMFptrunc fptrunc;
						fptrunc.d = d;
						fptrunc.a = a;
						
						_add( fptrunc );
						break;
					}
					case ir::PTXOperand::f32:
					{
						ir::LLVMFptrunc fptrunc;
						fptrunc.d = d;
						fptrunc.a = a;
						
						_add( fptrunc );
						break;
					}
					case ir::PTXOperand::f64:
					{
						_bitcast( d, a );
						break;
					}
					case ir::PTXOperand::TypeSpecifier_invalid:
					{
						assertM( false,"Invalid convert." );
						break;
					}
				}
				break;
			}
			case ir::PTXOperand::TypeSpecifier_invalid:
			{
				assertM( false, "Invalid convert." );
				break;
			}
		}
	}

	std::string PTXToLLVMTranslator::_tempRegister()
	{
		std::stringstream stream;
		stream << "%rt" << _tempRegisterCount++;
		return stream.str();
	}

	std::string PTXToLLVMTranslator::_loadSpecialRegister( 
		ir::PTXOperand::SpecialRegister s )
	{
		std::string reg;

		ir::LLVMGetelementptr get;
			
		get.d.type.category = ir::LLVMInstruction::Type::Pointer;
		get.d.type.type = ir::LLVMInstruction::I16;
		get.a = _context();
		get.indices.push_back( 0 );
		
		switch( s )
		{
			case ir::PTXOperand::tidX:
			{
				get.indices.push_back( 0 );
				get.indices.push_back( 0 );
				break;
			}
			case ir::PTXOperand::tidY:
			{
				get.indices.push_back( 0 );
				get.indices.push_back( 1 );
				break;
			}
			case ir::PTXOperand::tidZ:
			{
				get.indices.push_back( 0 );
				get.indices.push_back( 2 );
				break;
			}
			case ir::PTXOperand::ntidX:
			{
				get.indices.push_back( 1 );
				get.indices.push_back( 0 );
				break;
			}
			case ir::PTXOperand::ntidY:
			{
				get.indices.push_back( 1 );
				get.indices.push_back( 1 );
				break;
			}
			case ir::PTXOperand::ntidZ:
			{
				get.indices.push_back( 1 );
				get.indices.push_back( 2 );
				break;
			}
			case ir::PTXOperand::laneId:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			case ir::PTXOperand::warpId:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			case ir::PTXOperand::warpSize:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			case ir::PTXOperand::ctaIdX:
			{
				get.indices.push_back( 2 );
				get.indices.push_back( 0 );
				break;
			}
			case ir::PTXOperand::ctaIdY:
			{
				get.indices.push_back( 2 );
				get.indices.push_back( 1 );
				break;
			}
			case ir::PTXOperand::ctaIdZ:
			{
				get.indices.push_back( 2 );
				get.indices.push_back( 2 );
				break;
			}
			case ir::PTXOperand::nctaIdX:
			{
				get.indices.push_back( 3 );
				get.indices.push_back( 0 );
				break;
			}
			case ir::PTXOperand::nctaIdY:
			{
				get.indices.push_back( 3 );
				get.indices.push_back( 1 );
				break;
			}
			case ir::PTXOperand::nctaIdZ:
			{
				get.indices.push_back( 3 );
				get.indices.push_back( 2 );
				break;
			}
			case ir::PTXOperand::smId:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			case ir::PTXOperand::nsmId:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			case ir::PTXOperand::gridId:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			case ir::PTXOperand::clock:
			{
				ir::LLVMCall call;
				
				call.name = "@__ocelot_clock";
				call.d.type.category = ir::LLVMInstruction::Type::Element;
				call.d.type.type = ir::LLVMInstruction::I32;
				call.d.name = _tempRegister();
				
				call.parameters.resize( 1 );
				call.parameters[0] = _context();
				
				_add( call );
				
				return call.d.name;
				break;
			}
			case ir::PTXOperand::pm0:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			case ir::PTXOperand::pm1:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			case ir::PTXOperand::pm2:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			case ir::PTXOperand::pm3:
			{
				assertM( false, "Special register " 
					<< ir::PTXOperand::toString( s ) << " not supported." );
				break;
			}
			default: break;
		}
		
		get.d.name = _tempRegister();
		
		_add( get );
		
		ir::LLVMLoad load;
		
		load.d.name = _tempRegister();;
		load.d.type.category = ir::LLVMInstruction::Type::Element;
		load.d.type.type = ir::LLVMInstruction::I16;
		load.a = get.d;
		
		_add( load );
		
		return load.d.name;
	}
	
	ir::LLVMInstruction::Operand PTXToLLVMTranslator::_getMemoryBasePointer( 
		ir::PTXInstruction::AddressSpace space )
	{
		ir::LLVMGetelementptr get;
		
		get.d.name = _tempRegister();
		get.d.type.category = ir::LLVMInstruction::Type::Pointer;
		get.d.type.members.resize( 1 );
		get.d.type.members[0].category = ir::LLVMInstruction::Type::Pointer;
		get.d.type.members[0].type = ir::LLVMInstruction::I8;
		
		get.a = _context();
		get.indices.push_back( 0 );
		
		switch( space )
		{
			case ir::PTXInstruction::Const:
			{
				get.indices.push_back( 6 );
				break;
			}
			case ir::PTXInstruction::Shared:
			{
				get.indices.push_back( 5 );
				break;
			}
			case ir::PTXInstruction::Local:
			{
				get.indices.push_back( 4 );
				break;
			}
			case ir::PTXInstruction::Param:
			{
				get.indices.push_back( 7 );
				break;
			}
			default:
			{
				assertM( false, "Invalid memory space." );
			}			
		}
				
		_add( get );
		
		ir::LLVMLoad load;
		
		load.d.name = _tempRegister();
		load.d.type.category = ir::LLVMInstruction::Type::Pointer;
		load.d.type.type = ir::LLVMInstruction::I8;
		
		load.a = get.d;
		
		_add( load );
		
		return load.d;
	}
			
	ir::LLVMInstruction::Operand 
		PTXToLLVMTranslator::_getAddressableVariablePointer( 
		ir::PTXInstruction::AddressSpace space, const ir::PTXOperand& o )
	{		
		ir::LLVMInstruction::Operand index;
		
		if( o.offset != 0 )
		{
			ir::LLVMGetelementptr getIndex;
		
			getIndex.d.name = _tempRegister();
			getIndex.d.type.category = ir::LLVMInstruction::Type::Pointer;
			getIndex.d.type.type = ir::LLVMInstruction::I8;
		
			getIndex.a = _getMemoryBasePointer( space );
			getIndex.indices.push_back( o.offset );
		
			_add( getIndex );
			
			index = getIndex.d;
		}
		else
		{
			index = _getMemoryBasePointer( space );
		}
		
		return index;
	}

	ir::LLVMInstruction::Operand 
		PTXToLLVMTranslator::_getAddressableGlobalPointer( 
		const ir::PTXOperand& o )
	{
		ir::Module::GlobalMap::const_iterator 
			global = _llvmKernel->module->globals().find( o.identifier );
		assert( global != _llvmKernel->module->globals().end() );
		
		if( global->second.statement.elements() == 1 )
		{
			ir::LLVMInstruction::Operand result;
			
			result.type.category = ir::LLVMInstruction::Type::Pointer;
			result.type.type = _translate( global->second.statement.type );
			result.name = "@" + o.identifier;
			
			return result;
		}
		
		ir::LLVMGetelementptr get;
		get.a.type.category = ir::LLVMInstruction::Type::Pointer;
		get.a.name = "@" + o.identifier;
		
		get.a.type.members.resize( 1 );
		get.a.type.members[0].category 
			= ir::LLVMInstruction::Type::Array;
		get.a.type.members[0].vector 
			= global->second.statement.elements();
		
		get.a.type.members[0].type = _translate( 
			global->second.statement.type );
		
		get.d.type.category = ir::LLVMInstruction::Type::Pointer;
		get.d.type.type = get.a.type.members[0].type;
		get.d.name = _tempRegister();
		get.indices.push_back( 0 );
		get.indices.push_back( 0 );
		
		_add( get );
		
		return get.d;
	}
	
	ir::LLVMInstruction::Operand PTXToLLVMTranslator::_getLoadOrStorePointer( 
		const ir::PTXOperand& o, ir::PTXInstruction::AddressSpace space, 
		ir::LLVMInstruction::DataType type, unsigned int vector )
	{
		ir::LLVMInstruction::Operand pointer;
		
		if( o.addressMode == ir::PTXOperand::Address )
		{
			if( space == ir::PTXInstruction::Global )
			{
				pointer = _getAddressableGlobalPointer( o );
			}
			else
			{
				pointer = _getAddressableVariablePointer( space, o );
			}
			
			if( type == ir::LLVMInstruction::I8 )
			{
				return pointer;
			}
			
			ir::LLVMBitcast cast;
			
			cast.d.name = _tempRegister();
			cast.d.type.category = ir::LLVMInstruction::Type::Pointer;
			cast.a = pointer;
		
			if( vector == ir::PTXOperand::v1 )
			{
				cast.d.type.type = type;
			}
			else
			{
				cast.d.type.members.resize( 1 );
				cast.d.type.members[ 0 ].category 
					= ir::LLVMInstruction::Type::Vector;
				cast.d.type.members[ 0 ].type = type;
				cast.d.type.members[ 0 ].vector = vector;		
			}
		
			_add( cast );
		
			return cast.d;
		}
		else
		{
			assert( o.addressMode == ir::PTXOperand::Register 
				|| o.addressMode == ir::PTXOperand::Indirect );

			ir::LLVMInstruction::Operand reg = _translate( o );
			
			if( o.offset != 0 )
			{
				ir::LLVMAdd add;
			
				add.d.name = _tempRegister();
				add.d.type.category = ir::LLVMInstruction::Type::Element;
				add.d.type.type = reg.type.type;
				
				add.a = reg;
				
				add.b.type.category = ir::LLVMInstruction::Type::Element;
				add.b.type.type = reg.type.type;
				add.b.constant = true;
				add.b.i64 = o.offset;
		
				_add( add );
				
				reg = add.d;
			}
			
			if( space == ir::PTXInstruction::Shared )
			{
				ir::LLVMAnd mask;
				
				mask.d.name = _tempRegister();
				mask.d.type.category = ir::LLVMInstruction::Type::Element;
				mask.d.type.type = reg.type.type;
				
				mask.a = reg;
				mask.b.type.category = ir::LLVMInstruction::Type::Element;
				mask.b.type.type = reg.type.type;
				mask.b.constant = true;
				mask.b.i64 = 0x000000000000FFFFULL;
				
				_add( mask );
				
				reg = mask.d;
			}
			
			if( space == ir::PTXInstruction::Global )
			{
				pointer = reg;
			}
			else
			{
				ir::LLVMPtrtoint toint;
			
				toint.a = _getMemoryBasePointer( space );
				toint.d.name = _tempRegister();
				toint.d.type.category = ir::LLVMInstruction::Type::Element;
				toint.d.type.type = reg.type.type;
			
				_add( toint );
			
				ir::LLVMAdd add;
			
				add.d.name = _tempRegister();
				add.d.type.category = ir::LLVMInstruction::Type::Element;
				add.d.type.type = reg.type.type;
			
				add.a = reg;	
				add.b = toint.d;
	
				_add( add );
			
				pointer = add.d;
			}
			
			ir::LLVMInttoptr toptr;
			
			toptr.d.name = _tempRegister();
			toptr.d.type.category = ir::LLVMInstruction::Type::Pointer;
			toptr.a = pointer;
		
			if( vector == ir::PTXOperand::v1 )
			{
				toptr.d.type.type = type;
			}
			else
			{
				toptr.d.type.members.resize( 1 );
				toptr.d.type.members[ 0 ].category 
					= ir::LLVMInstruction::Type::Vector;
				toptr.d.type.members[ 0 ].type = type;
				toptr.d.type.members[ 0 ].vector = vector;		
			}
		
			_add( toptr );
		
			return toptr.d;
		}
	}
	
	void PTXToLLVMTranslator::_setFloatingPointRoundingMode( 
		const ir::PTXInstruction& i )
	{
		#if USE_SPECIFIED_ROUNDING_MODES
		ir::LLVMCall call;
		
		call.name = "@setRoundingMode";
		
		call.parameters.resize( 1 );
		call.parameters[0].type.type = ir::LLVMInstruction::I32;
		call.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		call.parameters[0].i32 = i.modifier;
		call.parameters[0].constant = true;

		if( ir::PTXOperand::PT != i.pg.condition )
		{
			call.parameters.resize( 2 );
			call.parameters[1] = _translate( i.pg );
		}
		
		_add( call );
		#endif
	}

	ir::LLVMInstruction::Operand PTXToLLVMTranslator::_destination( 
		const ir::PTXInstruction& i, bool pq )
	{
		ir::LLVMInstruction::Operand destination;
		if( pq )
		{
			destination = _translate( i.pq );
		}
		else
		{
			destination = _translate( i.d );
		}

		assertM( i.pg.condition == ir::PTXOperand::PT, 
			"Predication not supported." )

		return destination;
	}
	
	ir::LLVMInstruction::Operand PTXToLLVMTranslator::_destinationCC( 
		const ir::PTXInstruction& i )
	{
		ir::LLVMInstruction::Operand destination;
		destination.type.category = ir::LLVMInstruction::Type::Element;
		destination.type.type = ir::LLVMInstruction::I64;
		
		assertM( i.pg.condition == ir::PTXOperand::PT, 
			"Predication not supported." );
		std::stringstream stream;
		stream << "rcc" << _tempCCRegisterCount++;
		destination.name = stream.str();
		
		return destination;
	}
	
	ir::LLVMInstruction::Operand PTXToLLVMTranslator::_conditionCodeRegister( 
		const ir::PTXOperand& op )
	{
		ir::LLVMInstruction::Operand cc;

		std::stringstream stream;
		stream << "rcc" << op.reg;
		
		cc.name = stream.str();
		cc.type.category = ir::LLVMInstruction::Type::Element;
		cc.type.type = ir::LLVMInstruction::I64;
	
		return cc;
	}

	void PTXToLLVMTranslator::_add( const ir::LLVMInstruction& i )
	{
		assertM( i.valid() == "", "Instruction " << i.toString() 
			<< " is not valid: " << i.valid() );
		report( "    Added instruction '" << i.toString() << "'" );
		_llvmKernel->_statements.push_back( ir::LLVMStatement( i ) );	
	}

	void PTXToLLVMTranslator::_initializeRegisters()
	{
		report( " Adding initialization instructions." );

		if( !_uninitialized.empty() )
		{
			ir::LLVMBr branch;
			branch.iftrue = "%" + (++_ptx->dfg()->begin())->label();
		
			_llvmKernel->_statements.push_front( 
				ir::LLVMStatement( branch ) );
		}

		for( RegisterVector::const_iterator reg = _uninitialized.begin(); 
			reg != _uninitialized.end(); ++reg )
		{
			ir::LLVMBitcast move;
			
			std::stringstream stream;
			
			stream << "%ri" << reg->id;
			
			move.d.name = stream.str();
			move.d.type.category = ir::LLVMInstruction::Type::Element;
			move.d.type.type = _translate( reg->type );
			
			move.a = move.d;
			move.a.constant = true;
			move.a.i64 = 0;
			
			report( "  Adding instruction '" << move.toString() << "'" );		
			
			_llvmKernel->_statements.push_front( ir::LLVMStatement( move ) );
		}
		
		if( !_uninitialized.empty() )
		{
			_llvmKernel->_statements.push_front( 
				ir::LLVMStatement( "$OcelotRegisterInitializerBlock" ) );
		}
	}

	void PTXToLLVMTranslator::_addGlobalDeclarations()
	{
		for( ir::Module::GlobalMap::const_iterator 
			global = _llvmKernel->module->globals().begin(); 
			global != _llvmKernel->module->globals().end(); ++global )
		{
			if( global->second.statement.directive 
				!= ir::PTXStatement::Global ) continue;
		
			ir::LLVMStatement statement( 
				ir::LLVMStatement::VariableDeclaration );

			statement.label = global->second.statement.name;
			statement.linkage = ir::LLVMStatement::External;
			statement.visibility = ir::LLVMStatement::Default;
		
			if( global->second.statement.elements() == 1 )
			{
				statement.operand.type.category 
					= ir::LLVMInstruction::Type::Element;
			}
			else
			{
				statement.operand.type.category 
					= ir::LLVMInstruction::Type::Array;
				if( global->second.statement.attribute 
					== ir::PTXStatement::Extern )
				{
					statement.operand.type.vector = 0;
				}
				else
				{
					assert( global->second.statement.elements() > 0 );
					statement.operand.type.vector 
						= global->second.statement.elements();
				}
			}
			
			statement.operand.type.type = _translate( 
				global->second.statement.type );
			statement.alignment = ir::PTXOperand::bytes( 
				global->second.statement.type );
		
			_llvmKernel->_statements.push_front( statement );
		}
	}

	void PTXToLLVMTranslator::_addStackAllocations()
	{
		if( !_usesTextures ) return;
		
		ir::LLVMBr branch;
		
		if( _uninitialized.empty() )
		{
			branch.iftrue = "%" + (++_ptx->dfg()->begin())->label();
		}
		else
		{
			branch.iftrue = "%$OcelotRegisterInitializerBlock";
		}
		
		_llvmKernel->_statements.push_front( ir::LLVMStatement( branch ) );
		
		ir::LLVMAlloca allocate( 4, 16 );
		
		allocate.d.name = "%floatingPointTexture";
		allocate.d.type.category = ir::LLVMInstruction::Type::Pointer;
		allocate.d.type.type = ir::LLVMInstruction::F32;
		
		_llvmKernel->_statements.push_front( 
			ir::LLVMStatement( allocate ) );

		allocate.d.name = "%integerTexture";
		allocate.d.type.type = ir::LLVMInstruction::I32;

		_llvmKernel->_statements.push_front( ir::LLVMStatement( allocate ) );

		_llvmKernel->_statements.push_front( 
			ir::LLVMStatement( "$OcelotTextureAllocateBlock" ) );
	}

	void PTXToLLVMTranslator::_addTextureCalls()
	{
		ir::LLVMStatement tex( ir::LLVMStatement::FunctionDeclaration );

		tex.label = "__ocelot_tex_1d_uu";
		tex.linkage = ir::LLVMStatement::InvalidLinkage;
		tex.convention = ir::LLVMInstruction::DefaultCallingConvention;
		tex.visibility = ir::LLVMStatement::Default;
		
		tex.parameters.resize( 4 );
		tex.parameters[0].type.category = ir::LLVMInstruction::Type::Pointer;
		tex.parameters[0].type.type = ir::LLVMInstruction::I32;
		
		tex.parameters[1].type.category = ir::LLVMInstruction::Type::Pointer;
		tex.parameters[1].type.members.resize(1);
		tex.parameters[1].type.members[0].category 
			= ir::LLVMInstruction::Type::Structure;
		tex.parameters[1].type.members[0].label = "%LLVMContext";
		
		tex.parameters[2].type.category = ir::LLVMInstruction::Type::Element;
		tex.parameters[2].type.type = ir::LLVMInstruction::I32;

		tex.parameters[3].type.category = ir::LLVMInstruction::Type::Element;
		tex.parameters[3].type.type = ir::LLVMInstruction::I32;
		
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_1d_us";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_1d_su";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_1d_ss";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_1d_uf";
		tex.parameters[3].type.type = ir::LLVMInstruction::F32;
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_1d_sf";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_1d_ff";
		tex.parameters[0].type.type = ir::LLVMInstruction::F32;
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_1d_fu";
		tex.parameters[3].type.type = ir::LLVMInstruction::I32;
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_1d_fs";
		_llvmKernel->_statements.push_front( tex );
		

		tex.label = "__ocelot_tex_2d_uu";
		tex.parameters[0].type.type = ir::LLVMInstruction::I32;
		
		tex.parameters.resize( 5 );
		
		tex.parameters[3].type.type = ir::LLVMInstruction::I32;

		tex.parameters[4].type.category = ir::LLVMInstruction::Type::Element;
		tex.parameters[4].type.type = ir::LLVMInstruction::I32;
		
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_2d_us";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_2d_su";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_2d_ss";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_2d_uf";
		tex.parameters[3].type.type = ir::LLVMInstruction::F32;
		tex.parameters[4].type.type = ir::LLVMInstruction::F32;
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_2d_sf";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_2d_ff";
		tex.parameters[0].type.type = ir::LLVMInstruction::F32;
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_2d_fu";
		tex.parameters[3].type.type = ir::LLVMInstruction::I32;
		tex.parameters[4].type.type = ir::LLVMInstruction::I32;
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_2d_fs";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_3d_uu";
		tex.parameters[0].type.type = ir::LLVMInstruction::I32;
		
		tex.parameters.resize( 7 );
		
		tex.parameters[3].type.type = ir::LLVMInstruction::I32;

		tex.parameters[4].type.type = ir::LLVMInstruction::I32;

		tex.parameters[5].type.category = ir::LLVMInstruction::Type::Element;
		tex.parameters[5].type.type = ir::LLVMInstruction::I32;

		tex.parameters[6].type.category = ir::LLVMInstruction::Type::Element;
		tex.parameters[6].type.type = ir::LLVMInstruction::I32;
		
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_3d_us";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_3d_su";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_3d_ss";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_3d_uf";
		tex.parameters[3].type.type = ir::LLVMInstruction::F32;
		tex.parameters[4].type.type = ir::LLVMInstruction::F32;
		tex.parameters[5].type.type = ir::LLVMInstruction::F32;
		tex.parameters[6].type.type = ir::LLVMInstruction::F32;
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_3d_sf";
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_3d_ff";
		tex.parameters[0].type.type = ir::LLVMInstruction::F32;
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_3d_fu";
		tex.parameters[3].type.type = ir::LLVMInstruction::I32;
		tex.parameters[4].type.type = ir::LLVMInstruction::I32;
		tex.parameters[5].type.type = ir::LLVMInstruction::I32;
		tex.parameters[6].type.type = ir::LLVMInstruction::I32;
		_llvmKernel->_statements.push_front( tex );

		tex.label = "__ocelot_tex_3d_fs";
		_llvmKernel->_statements.push_front( tex );		
	}

	void PTXToLLVMTranslator::_addAtomicCalls()
	{
		ir::LLVMStatement atom( ir::LLVMStatement::FunctionDeclaration );

		atom.label = "__ocelot_atom_b32";
		atom.linkage = ir::LLVMStatement::InvalidLinkage;
		atom.convention = ir::LLVMInstruction::DefaultCallingConvention;
		atom.visibility = ir::LLVMStatement::Default;
		
		atom.operand.type.category = ir::LLVMInstruction::Type::Element;
		atom.operand.type.type = ir::LLVMInstruction::I32;
		
		atom.parameters.resize( 5 );

		atom.parameters[0].type.category = ir::LLVMInstruction::Type::Pointer;
		atom.parameters[0].type.members.resize(1);
		atom.parameters[0].type.members[0].category 
			= ir::LLVMInstruction::Type::Structure;
		atom.parameters[0].type.members[0].label = "%LLVMContext";

		atom.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		atom.parameters[1].type.type = ir::LLVMInstruction::I32;

		atom.parameters[2].type.category = ir::LLVMInstruction::Type::Element;
		atom.parameters[2].type.type = ir::LLVMInstruction::I32;

		atom.parameters[3].type.category = ir::LLVMInstruction::Type::Element;
		atom.parameters[3].type.type = ir::LLVMInstruction::I64;

		atom.parameters[4].type.category = ir::LLVMInstruction::Type::Element;
		atom.parameters[4].type.type = ir::LLVMInstruction::I32;

		_llvmKernel->_statements.push_front( atom );		

		atom.label = "__ocelot_atom_s32";
		
		_llvmKernel->_statements.push_front( atom );

		atom.parameters.resize( 6 );

		atom.label = "__ocelot_atomcas_b32";
		atom.parameters[5].type.category = ir::LLVMInstruction::Type::Element;
		atom.parameters[5].type.type = ir::LLVMInstruction::I32;

		_llvmKernel->_statements.push_front( atom );	

		atom.label = "__ocelot_atomcas_b64";
		atom.operand.type.type = ir::LLVMInstruction::I64;
		atom.parameters[4].type.type = ir::LLVMInstruction::I64;
		atom.parameters[5].type.type = ir::LLVMInstruction::I64;

		_llvmKernel->_statements.push_front( atom );	

		atom.label = "__ocelot_atom_b64";
		atom.parameters.resize( 5 );

		_llvmKernel->_statements.push_front( atom );

		atom.label = "__ocelot_atom_f32";
		atom.operand.type.type = ir::LLVMInstruction::F32;
		atom.parameters[4].type.type = ir::LLVMInstruction::F32;
			
		_llvmKernel->_statements.push_front( atom );	
	}

	void PTXToLLVMTranslator::_addMathCalls()
	{
		ir::LLVMStatement mul( ir::LLVMStatement::FunctionDeclaration );

		mul.label = "__ocelot_mul_hi_u64";
		mul.linkage = ir::LLVMStatement::InvalidLinkage;
		mul.convention = ir::LLVMInstruction::DefaultCallingConvention;
		mul.visibility = ir::LLVMStatement::Default;
		
		mul.operand.type.category = ir::LLVMInstruction::Type::Element;
		mul.operand.type.type = ir::LLVMInstruction::I64;
		
		mul.parameters.resize( 2 );

		mul.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		mul.parameters[0].type.type = ir::LLVMInstruction::I64;

		mul.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		mul.parameters[1].type.type = ir::LLVMInstruction::I64;

		_llvmKernel->_statements.push_front( mul );		

		mul.label = "__ocelot_mul_hi_s64";
		
		_llvmKernel->_statements.push_front( mul );
	}
	
	void PTXToLLVMTranslator::_addKernelPrefix()
	{
		_llvmKernel->_statements.push_front( 
			ir::LLVMStatement( ir::LLVMStatement::BeginFunctionBody ) );

		ir::LLVMStatement kernel( ir::LLVMStatement::FunctionDefinition );

		kernel.label = "_Z_ocelotTranslated_" + _llvmKernel->name;
		kernel.linkage = ir::LLVMStatement::InvalidLinkage;
		kernel.convention = ir::LLVMInstruction::DefaultCallingConvention;
		kernel.visibility = ir::LLVMStatement::Default;
		kernel.functionAttributes = ir::LLVMInstruction::NoUnwind;
	
		kernel.operand.type.category = ir::LLVMInstruction::Type::Element;
		kernel.operand.type.type = ir::LLVMInstruction::I32;
		
		kernel.parameters.resize( 1 );
		kernel.parameters[ 0 ].attribute = ir::LLVMInstruction::NoAlias;
		kernel.parameters[ 0 ].type.label = "%LLVMContext";
		kernel.parameters[ 0 ].type.category 
			= ir::LLVMInstruction::Type::Pointer;
		kernel.parameters[ 0 ].name = "%__ctaContext";
		
		_llvmKernel->_statements.push_front( kernel );

		ir::LLVMStatement dim3( ir::LLVMStatement::TypeDeclaration );
		
		dim3.label = "%Dimension";
		dim3.operand.type.category = ir::LLVMInstruction::Type::Structure;
		dim3.operand.type.members.resize( 3 );
		dim3.operand.type.members[0].category 
			= ir::LLVMInstruction::Type::Element;
		dim3.operand.type.members[0].type = ir::LLVMInstruction::I16;
		dim3.operand.type.members[1] = dim3.operand.type.members[0];
		dim3.operand.type.members[2] = dim3.operand.type.members[0];
		
		_llvmKernel->_statements.push_front( dim3 );

		_llvmKernel->_statements.push_front( 
			ir::LLVMStatement( ir::LLVMStatement::NewLine ) );		

		ir::LLVMStatement cosf( ir::LLVMStatement::FunctionDeclaration );

		cosf.label = "__ocelot_cosf";
		cosf.linkage = ir::LLVMStatement::InvalidLinkage;
		cosf.convention = ir::LLVMInstruction::DefaultCallingConvention;
		cosf.visibility = ir::LLVMStatement::Default;
		
		cosf.operand.type.category = ir::LLVMInstruction::Type::Element;
		cosf.operand.type.type = ir::LLVMInstruction::F32;
		
		cosf.parameters.resize( 1 );
		cosf.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		cosf.parameters[0].type.type = ir::LLVMInstruction::F32;
	
		_llvmKernel->_statements.push_front( cosf );		
		cosf.label = "__ocelot_cosFtz";
		_llvmKernel->_statements.push_front( cosf );

		ir::LLVMStatement sinf( ir::LLVMStatement::FunctionDeclaration );

		sinf.label = "__ocelot_sinf";
		sinf.linkage = ir::LLVMStatement::InvalidLinkage;
		sinf.convention = ir::LLVMInstruction::DefaultCallingConvention;
		sinf.visibility = ir::LLVMStatement::Default;
		
		sinf.operand.type.category = ir::LLVMInstruction::Type::Element;
		sinf.operand.type.type = ir::LLVMInstruction::F32;
		
		sinf.parameters.resize( 1 );
		sinf.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		sinf.parameters[0].type.type = ir::LLVMInstruction::F32;
	
		_llvmKernel->_statements.push_front( sinf );		
		sinf.label = "__ocelot_sinFtz";
		_llvmKernel->_statements.push_front( sinf );		

		ir::LLVMStatement ex2( ir::LLVMStatement::FunctionDeclaration );

		ex2.label = "__ocelot_ex2";
		ex2.linkage = ir::LLVMStatement::InvalidLinkage;
		ex2.convention = ir::LLVMInstruction::DefaultCallingConvention;
		ex2.visibility = ir::LLVMStatement::Default;
		
		ex2.operand.type.category = ir::LLVMInstruction::Type::Element;
		ex2.operand.type.type = ir::LLVMInstruction::F32;
		
		ex2.parameters.resize( 1 );
		ex2.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		ex2.parameters[0].type.type = ir::LLVMInstruction::F32;
	
		_llvmKernel->_statements.push_front( ex2 );		
		ex2.label = "__ocelot_ex2Ftz";
		_llvmKernel->_statements.push_front( ex2 );
		
		ir::LLVMStatement log2f( ir::LLVMStatement::FunctionDeclaration );

		log2f.label = "__ocelot_log2f";
		log2f.linkage = ir::LLVMStatement::InvalidLinkage;
		log2f.convention = ir::LLVMInstruction::DefaultCallingConvention;
		log2f.visibility = ir::LLVMStatement::Default;
		
		log2f.operand.type.category = ir::LLVMInstruction::Type::Element;
		log2f.operand.type.type = ir::LLVMInstruction::F32;
		
		log2f.parameters.resize( 1 );
		log2f.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		log2f.parameters[0].type.type = ir::LLVMInstruction::F32;
	
		_llvmKernel->_statements.push_front( log2f );		
		log2f.label = "__ocelot_log2Ftz";
		_llvmKernel->_statements.push_front( log2f );

		ir::LLVMStatement sqrtf( ir::LLVMStatement::FunctionDeclaration );

		sqrtf.label = "__ocelot_sqrtf";
		sqrtf.linkage = ir::LLVMStatement::InvalidLinkage;
		sqrtf.convention = ir::LLVMInstruction::DefaultCallingConvention;
		sqrtf.visibility = ir::LLVMStatement::Default;
		
		sqrtf.operand.type.category = ir::LLVMInstruction::Type::Element;
		sqrtf.operand.type.type = ir::LLVMInstruction::F32;
		
		sqrtf.parameters.resize( 1 );
		sqrtf.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		sqrtf.parameters[0].type.type = ir::LLVMInstruction::F32;
	
		_llvmKernel->_statements.push_front( sqrtf );		
		sqrtf.label = "__ocelot_sqrtFtz";
		_llvmKernel->_statements.push_front( sqrtf );

		ir::LLVMStatement sqrt( ir::LLVMStatement::FunctionDeclaration );

		sqrt.label = "__ocelot_sqrt";
		sqrt.linkage = ir::LLVMStatement::InvalidLinkage;
		sqrt.convention = ir::LLVMInstruction::DefaultCallingConvention;
		sqrt.visibility = ir::LLVMStatement::Default;
		
		sqrt.operand.type.category = ir::LLVMInstruction::Type::Element;
		sqrt.operand.type.type = ir::LLVMInstruction::F64;
		
		sqrt.parameters.resize( 1 );
		sqrt.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		sqrt.parameters[0].type.type = ir::LLVMInstruction::F64;
	
		_llvmKernel->_statements.push_front( sqrt );		

		ir::LLVMStatement rsqrt( ir::LLVMStatement::FunctionDeclaration );

		rsqrt.label = "__ocelot_rsqrt";
		rsqrt.linkage = ir::LLVMStatement::InvalidLinkage;
		rsqrt.convention = ir::LLVMInstruction::DefaultCallingConvention;
		rsqrt.visibility = ir::LLVMStatement::Default;
		
		rsqrt.operand.type.category = ir::LLVMInstruction::Type::Element;
		rsqrt.operand.type.type = ir::LLVMInstruction::F32;
		
		rsqrt.parameters.resize( 1 );
		rsqrt.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		rsqrt.parameters[0].type.type = ir::LLVMInstruction::F32;
	
		_llvmKernel->_statements.push_front( rsqrt );		
		rsqrt.label = "__ocelot_rsqrtFtz";
		_llvmKernel->_statements.push_front( rsqrt );		

		ir::LLVMStatement setRoundingMode( 
			ir::LLVMStatement::FunctionDeclaration );

		setRoundingMode.label = "setRoundingMode";
		setRoundingMode.linkage = ir::LLVMStatement::InvalidLinkage;
		setRoundingMode.convention 
			= ir::LLVMInstruction::DefaultCallingConvention;
		setRoundingMode.visibility = ir::LLVMStatement::Default;
		
		setRoundingMode.parameters.resize( 1 );
		setRoundingMode.parameters[0].type.category 
			= ir::LLVMInstruction::Type::Element;
		setRoundingMode.parameters[0].type.type = ir::LLVMInstruction::I32;
	
		_llvmKernel->_statements.push_front( setRoundingMode );

		ir::LLVMStatement clock( ir::LLVMStatement::FunctionDeclaration );

		clock.label = "__ocelot_clock";
		clock.linkage = ir::LLVMStatement::InvalidLinkage;
		clock.convention = ir::LLVMInstruction::DefaultCallingConvention;
		clock.visibility = ir::LLVMStatement::Default;
		
		clock.operand.type.category = ir::LLVMInstruction::Type::Element;
		clock.operand.type.type = ir::LLVMInstruction::I32;	
		
		clock.parameters.resize( 1 );
		clock.parameters[0].type.category = ir::LLVMInstruction::Type::Pointer;
		clock.parameters[0].type.members.resize(1);
		clock.parameters[0].type.members[0].category 
			= ir::LLVMInstruction::Type::Structure;
		clock.parameters[0].type.members[0].label = "%LLVMContext";

		_llvmKernel->_statements.push_front( ir::LLVMStatement( clock ) );

		ir::LLVMStatement vote( ir::LLVMStatement::FunctionDeclaration );

		vote.label = "__ocelot_vote";
		vote.linkage = ir::LLVMStatement::InvalidLinkage;
		vote.convention = ir::LLVMInstruction::DefaultCallingConvention;
		vote.visibility = ir::LLVMStatement::Default;
		
		vote.operand.type.category = ir::LLVMInstruction::Type::Element;
		vote.operand.type.type = ir::LLVMInstruction::I1;
		
		vote.parameters.resize( 3 );
		vote.parameters[0].type.category = ir::LLVMInstruction::Type::Element;
		vote.parameters[0].type.type = ir::LLVMInstruction::I1;
		vote.parameters[1].type.category = ir::LLVMInstruction::Type::Element;
		vote.parameters[1].type.type = ir::LLVMInstruction::I32;
		vote.parameters[2].type.category = ir::LLVMInstruction::Type::Element;
		vote.parameters[2].type.type = ir::LLVMInstruction::I1;
	
		_llvmKernel->_statements.push_front( vote );		

		_addMemoryCheckingDeclarations();
		_insertDebugSymbols();
		_addTextureCalls();
		_addAtomicCalls();
		_addMathCalls();

		_llvmKernel->_statements.push_back( 
			ir::LLVMStatement( ir::LLVMStatement::NewLine ) );
		
		ir::LLVMStatement contextType( ir::LLVMStatement::TypeDeclaration );
		
		contextType.label = "%LLVMContext";
		contextType.operand.type = _getCtaContextType();
		
		_llvmKernel->_statements.push_front( contextType );

		_llvmKernel->_statements.push_front( 
			ir::LLVMStatement( ir::LLVMStatement::NewLine ) );
	}
	
	void PTXToLLVMTranslator::_addKernelSuffix()
	{
		_llvmKernel->_statements.push_back( 
			ir::LLVMStatement( ir::LLVMStatement::EndFunctionBody ) );	
	}

	PTXToLLVMTranslator::PTXToLLVMTranslator( OptimizationLevel l ) 
		: Translator( ir::Instruction::PTX, ir::Instruction::LLVM, l ),
		_tempRegisterCount( 0 ), _tempCCRegisterCount( 0 ),
		_tempBlockCount( 0 ), _usesTextures( false )
	{
	
	}
	
	PTXToLLVMTranslator::~PTXToLLVMTranslator()
	{
	
	}
	
	ir::Kernel* PTXToLLVMTranslator::translate( const ir::Kernel* k )
	{
		report( "Translating PTX kernel " << k->name );
		
		assertM( k->ISA == ir::Instruction::PTX, 
			"Kernel must a PTXKernel to translate to an LLVMKernel" );
		
		_ptx = static_cast< const ir::PTXKernel* >( k );
		_llvmKernel = new ir::LLVMKernel( *k );
				
		assert(_ptx->dfg()->ssa());
		_translateInstructions();
		_initializeRegisters();
		_addStackAllocations();
		_addKernelPrefix();
		_addKernelSuffix();
		_addGlobalDeclarations();
		
		_tempRegisterCount = 0;
		_tempBlockCount = 0;
		_uninitialized.clear();
		_usesTextures = false;
				
		return _llvmKernel;
	}
	
	void PTXToLLVMTranslator::addProfile( const ProfilingData& d )
	{
		// profiling not yet implemented
	}
}

#endif

