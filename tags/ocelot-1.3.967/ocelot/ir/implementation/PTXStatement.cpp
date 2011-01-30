/*! \file PTXStatement.cpp
	\date Monday January 19, 2009
	\author Andrew Kerr
	\brief The header file for the PTXStatement class
*/

#ifndef IR_PTXSTATEMENT_CPP_INCLUDED
#define IR_PTXSTATEMENT_CPP_INCLUDED

#include <ocelot/ir/interface/PTXStatement.h>
#include <cstring>
#include <stack>
#include <hydrazine/implementation/debug.h>

namespace ir {

	std::string PTXStatement::StaticArray::dimensions() const {
		if( stride.size() == 0 ) {
			return "";
		}
		
		std::stringstream stream;
		for( ArrayStrideVector::const_iterator si = stride.begin(); 
			si != stride.end(); ++si ) {
			
			if( *si == 0 ) {
				stream << "[]";
				continue; 
			}
			
			stream << "[" << *si << "]";
		}
		
		return stream.str();
	}
	
	std::string PTXStatement::StaticArray::initializer( 
		PTXOperand::DataType t ) const {
		std::stringstream stream;
		if( stride.size() == 0 ) {
			assert( values.size() == 1 );
			stream << PTXStatement::toString( values.front(), t );
		}
		std::stack< unsigned int > stack;
		stream << "{ ";
		stack.push( 0 );
		ArrayStrideVector::const_iterator si = stride.begin();
		ArrayVector::const_iterator ai = values.begin();
		while( !stack.empty() ) {	
				
			if( si == --stride.end() ) {
			
				for( ; stack.top() < *si; ++stack.top() ) {
				
					if( vec == PTXOperand::v1 ) {
					
						assert( ai != values.end() );
						stream << PTXStatement::toString( *ai, t );
						++ai;
						
					}
					else if( vec == PTXOperand::v2 ) {
					
						assert( ai != values.end() );
						stream << "{ " 
							<< PTXStatement::toString( *ai, t ) << ", ";
						++ai;
						assert( ai != values.end() );
						stream << PTXStatement::toString( *ai, t ) << " }";
						++ai;
						
					}
					else {
					
						assert( ai != values.end() );
						stream << "{ " << 
							PTXStatement::toString( *ai, t ) << ", ";
						++ai;
						assert( ai != values.end() );
						stream << PTXStatement::toString( *ai, t ) << ", ";
						++ai;
						assert( ai != values.end() );
						stream << PTXStatement::toString( *ai, t ) << ", ";
						++ai;
						assert( ai != values.end() );
						stream << PTXStatement::toString( *ai, t ) << " }";
						++ai;				
					}
					
					if( stack.top() != ( *si - 1 ) ) {
						stream << ", ";
					}
					
				}
				
			}
			
			if( stack.top() < *si ) {
			
				if( stack.top() != 0 ) {
					stream << ", ";
				}
				stream << "{ ";
				++stack.top();
				stack.push( 0 );
				++si;
				
			}
			else {
			
				stream << " }";
				stack.pop();
				--si;
				
			}
			
		}
		
		assert( ai == values.end() );
		return stream.str();
		
	}
	
	std::string PTXStatement::toString( Attribute attribute ) {
		switch( attribute ) {
			case Visible: return "visible"; break;
			case Extern: return "extern"; break;
			default: break;
		}
		return "";
	}
	
	std::string PTXStatement::toString( Data d, PTXOperand::DataType t ) {
		std::stringstream stream;
		switch( t ) {
			case PTXOperand::s8: /*fall through*/
			case PTXOperand::s16: /*fall through*/
			case PTXOperand::s32: /*fall through*/
			case PTXOperand::s64: stream << d.s64; break;
			case PTXOperand::u8: /*fall through*/
			case PTXOperand::u16: /*fall through*/
			case PTXOperand::u32: /*fall through*/
			case PTXOperand::u64: /*fall through*/
			case PTXOperand::b8: /*fall through*/
			case PTXOperand::b16: /*fall through*/
			case PTXOperand::b32: /*fall through*/
			case PTXOperand::b64: stream << d.u64; break;
			case PTXOperand::f32: stream << d.f32; break;
			case PTXOperand::f64: stream << d.f64; break;
			default : assert("Invalid type" == 0);
		}
		return stream.str();
	}
	
	PTXStatement::PTXStatement( Directive d ) {
		directive = d;
		alignment = 1;
		array.vec = PTXOperand::v1;
		attribute = NoAttribute;
	
	}
	
	PTXStatement::~PTXStatement() {
	
	}

	unsigned int PTXStatement::elements() const {
		unsigned int result = 1;
		for( ArrayStrideVector::const_iterator stride = array.stride.begin(); 
			stride != array.stride.end(); ++stride ) {
			result *= *stride;
		}
		result *= array.vec;
		return result;
	}

	unsigned int PTXStatement::bytes() const {
		unsigned int result = elements();
		unsigned int elementsize = PTXOperand::bytes(type);
		result *= elementsize;
		return result;
	}

	unsigned int PTXStatement::initializedBytes() const {
		unsigned int result = array.values.size();
		unsigned int elementsize = PTXOperand::bytes(type);
		result *= elementsize;
		return result;
	}

	void PTXStatement::copy(void* dest) const {
		char* d = (char*) dest;
		unsigned int bytes = PTXOperand::bytes(type);
		for (ArrayVector::const_iterator element = array.values.begin(); 
			element != array.values.end(); ++element, d += bytes) {
			memcpy(d, &element->b8, bytes);
		}
	}
	
	unsigned int PTXStatement::accessAlignment() const {
		return std::max( (unsigned int) alignment, 
			PTXOperand::bytes(type) * array.vec );
	}
	
	std::string PTXStatement::toString() const {
	
		switch( directive ) {
			case Instr: {
				return instruction.toString() + ";";
				break;
			}
			case Const: {
				std::stringstream stream;
				if( attribute != NoAttribute ) {
					stream << "." << toString( attribute ) << " ";
				}
				stream << ".const";
				assert( alignment != 0);
				if( alignment != 1 ) {
					stream << " .align " << alignment;
				}
				if( array.vec != PTXOperand::v1 ) {
					stream << " ." << PTXInstruction::toString( array.vec );
				}
				stream << " ." << PTXOperand::toString( type ) << " " << name;
				stream << array.dimensions();
				if( !array.values.empty() ) { 
					stream << " = " << array.initializer( type );
				}
				stream << ";";
				return stream.str();
				break;
			}
			case Entry: {
				return ".entry " + name;
				break;
			}
			case File: {
				std::stringstream stream;
				stream << ".file " << sourceFile << " \"" << name << "\"";
				return stream.str();
				break;
			}
			case Func:
				return ".func " + name;
				break;
			case Global: {
				std::stringstream stream;
				if( attribute != NoAttribute ) {
					stream << "." << toString( attribute ) << " ";
				}
				stream << ".global";
				assert( alignment != 0);
				if( alignment != 1 ) {
					stream << " .align " << alignment;
				}
				if( array.vec != PTXOperand::v1 ) {
					stream << " ." << PTXInstruction::toString( array.vec );
				}
				stream << " ." << PTXOperand::toString( type ) << " " << name;
				stream << array.dimensions();
				if( !array.values.empty() ) { 
					stream << " = " << array.initializer( type );
				}
				stream << ";";
				return stream.str();
				break;
			}
			case Label: {
				return name + ":";
				break;
			}
			case Local: {
				std::stringstream stream;
				if( attribute != NoAttribute ) {
					stream << "." << toString( attribute ) << " ";
				}
				stream << ".local";
				assert( alignment != 0);
				if( alignment != 1 ) {
					stream << " .align " << alignment;
				}
				if( array.vec != PTXOperand::v1 ) {
					stream << " ." << PTXInstruction::toString( array.vec );
				}
				stream << " ." << PTXOperand::toString( type ) << " " << name;
				stream << array.dimensions();
				stream << ";";
				return stream.str();
				break;
			}
			case Loc: {
				std::stringstream stream;
				stream << ".loc " << sourceFile << " " 
					<< sourceLine << " " << sourceColumn;
				return stream.str();
				break;
			}
			case Param: {
				assert( array.values.empty() );
				std::stringstream stream;
				if( attribute != NoAttribute ) {
					stream << "." << toString( attribute ) << " ";
				}
				stream << ".param";
				assert( alignment != 0);
				if( alignment != 1 ) {
					stream << " .align " << alignment;
				}
				if( array.vec != PTXOperand::v1 ) {
					stream << " ." << PTXInstruction::toString( array.vec );
				}
				stream << " ." << PTXOperand::toString( type ) << " " << name;
				stream << array.dimensions();
				return stream.str();
				break;
			}
			case Reg: {
				std::stringstream stream;
				if( attribute != NoAttribute ) {
					stream << "." << toString( attribute ) << " ";
				}
				stream << ".reg";
				if( array.vec != PTXOperand::v1 ) {
					stream << " ." << PTXInstruction::toString( array.vec );
				}
				stream << " ." << PTXOperand::toString( type ) << " " << name;
				assert( array.stride.size() == 1 );
				if( array.stride[0] != 0 )
				{
					stream << "<" << array.stride[0] << ">";
				}
				stream << ";";
				return stream.str();
				break;
			}
			case Section:
				return ".section " + section_type + ", " + section_name;
				break;
			case Shared: {
				std::stringstream stream;
				if( attribute != NoAttribute ) {
					stream << "." << toString( attribute ) << " ";
				}
				stream << ".shared";
				assert( alignment != 0);
				stream << " .align " << alignment;
				if( array.vec != PTXOperand::v1 ) {
					stream << " ." << PTXInstruction::toString( array.vec );
				}
				stream << " ." << PTXOperand::toString( type ) << " " << name;
				stream << array.dimensions();
				stream << ";";
				return stream.str();
				break;
			}
			case Sreg:
				return ".sreg " + PTXInstruction::toString( array.vec ) + 
					" ." + PTXOperand::toString( type ) + " " + name + ";";
				break;
			case Struct:
				assert( " The current version of PTX does not implement structures or unions." == 0 );
				break;
			case Surf:
				assert( "No support for Surf" == 0 );
				break;
			case Target: {
				return ".target " + hydrazine::toString( targets.begin(), 
					targets.end(), ", " );
				break;
			}
			case Tex: {
				std::stringstream stream;
				if( attribute != NoAttribute ) {
					stream << "." << toString( attribute ) << " ";
				}
				stream << ".tex";
				assert( alignment != 0);
				if( alignment != 1 ) {
					stream << " .align " << alignment;
				}
				if( array.vec != PTXOperand::v1 ) {
					stream << " ." << PTXInstruction::toString( array.vec );
				}
				stream << " ." << PTXOperand::toString( type ) << " " << name;
				stream << array.dimensions();
				if( !array.values.empty() ) { 
					stream << " = " << array.initializer( type );
				}
				stream << ";";
				return stream.str();
				break;
			}
			case Union:
				assert( " The current version of PTX does not implement structures or unions." == 0 );
				break;
			case Version: {
				return ".version 1.4";
				break;
			}
			case StartEntry:
				return "{";
				break;		
			case EndEntry:
				return "}";
				break;			
			case StartParam:
				return "(";
				break;		
			case EndParam:
				return ")";
				break;				
			case Directive_invalid:
				return "";
				break;		
		}
		return "";
	
	}
	
}

#endif

