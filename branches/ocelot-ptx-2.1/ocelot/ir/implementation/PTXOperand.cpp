/*! \file PTXOperand.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief internal representation of a PTX operand
*/

#include <ocelot/ir/interface/PTXOperand.h>

#include <hydrazine/implementation/debug.h>

#include <cassert>
#include <sstream>
#include <iomanip>

std::string ir::PTXOperand::toString( VectorIndex index ) {
	switch( index ) {
		case ix:   return "x"; break;
		case iy:   return "y"; break;
		case iz:   return "z"; break;
		case iw:   return "w"; break;
		case iAll: return "";  break;
	}
	return "";
}

std::string ir::PTXOperand::toString( DataType type ) {
	switch( type ) {
		case s8:   return "s8";   break;
		case s16:  return "s16";  break;
		case s32:  return "s32";  break;
		case s64:  return "s64";  break;
		case u8:   return "u8";   break;
		case u16:  return "u16";  break;
		case u32:  return "u32";  break;
		case u64:  return "u64";  break;
		case b8:   return "b8";   break;
		case b16:  return "b16";  break;
		case b32:  return "b32";  break;
		case b64:  return "b64";  break;
		case f16:  return "f16";  break;
		case f32:  return "f32";  break;
		case f64:  return "f64";  break;
		case pred: return "pred"; break;
		default: break;
	}
	return "Invalid";
}

std::string ir::PTXOperand::toString( SpecialRegister reg ) {
	switch( reg ) {
		case tid:      return "%tid";    break;
		case ntid:     return "%ntid";   break;
		case laneId:   return "%laneid"; break;
		case warpId:   return "%warpid"; break;
		case warpSize: return "WARP_SZ"; break;
		case ctaId:    return "%ctaid";  break;
		case nctaId:   return "%nctaid"; break;
		case smId:     return "%smid";   break;
		case nsmId:    return "%nsmid";  break;
		case gridId:   return "%gridid"; break;
		case clock:    return "%clock";  break;
		case pm0:      return "%pm0";    break;
		case pm1:      return "%pm1";    break;
		case pm2:      return "%pm2";    break;
		case pm3:      return "%pm3";    break;
		default: break;
	}
	return "SpecialRegister_invalid";
}

std::string ir::PTXOperand::toString( AddressMode mode ) {
	switch( mode ) {
		case Register:  return "Register";  break;
		case Indirect:  return "Indirect";  break;
		case Immediate: return "Immediate"; break;
		case Address:   return "Address";   break;
		case Label:     return "Label";     break;
		case Special:   return "Special";   break;
		default: break;
	}
	return "Invalid";
}

std::string ir::PTXOperand::toString( DataType type, RegisterType reg ) {
	std::stringstream stream;
	if( type == pred ) {
		stream << "%p" << reg;
	}
	else {
		stream << "%r_" << toString( type ) << "_" << reg;
	}
	return stream.str();
}

bool ir::PTXOperand::isFloat( DataType type ) {
	bool result = false;
	switch( type ) {
		case f16: /* fall through */
		case f32: /* fall through */
		case f64: result = true;
		default: break;
	}
	return result;
}

bool ir::PTXOperand::isInt( DataType type ) {
	bool result = false;
	switch( type ) {
		case s8:  /* fall through */
		case s16: /* fall through */
		case s32: /* fall through */
		case s64: /* fall through */
		case u8:  /* fall through */
		case u16: /* fall through */
		case u32: /* fall through */
		case u64: result = true; break;
		default: break;
	}
	return result;
}

bool ir::PTXOperand::isSigned( DataType type ) {
	bool result = false;
	switch( type ) {
		case s8:  /* fall through */
		case s16: /* fall through */
		case s32: /* fall through */
		case s64: result = true; break;
		default: break;
	}
	return result;
}

unsigned int ir::PTXOperand::bytes( DataType type ) {
	assert( type != TypeSpecifier_invalid );
	switch( type ) {
		case pred: /* fall through */
		case b8:   /* fall through */
		case u8:   /* fall through */
		case s8:   return 1; break;
		case u16:  /* fall through */
		case f16:  /* fall through */
		case b16:  /* fall through */
		case s16:  return 2; break;
		case u32:  /* fall through */
		case b32:  /* fall through */
		case f32:  /* fall through */
		case s32:  return 4; break;
		case f64:  /* fall through */
		case u64:  /* fall through */
		case b64:  /* fall through */
		case s64:  return 8; break;
		default:   return 0; break;
	}
	return 0;	
}

bool ir::PTXOperand::valid( DataType destination, DataType source ) {
	switch( destination ) {
		case b64: {
			switch( source ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case f64: /* fall through */
				case b64: return true; break;
				default: break;
			}
			break;
		}
		case b32: {
			switch( source ) {
				case s32: /* fall through */
				case u32: /* fall through */
				case f32: /* fall through */
				case b32: return true; break;
				default: break;
			}
			break;
		}
		case b16: {
			switch( source ) {
				case s16: /* fall through */
				case u16: /* fall through */
				case f16: /* fall through */
				case b16: return true; break;
				default: break;
			}
			break;
		}
		case b8: {
			switch( source ) {
				case s8: /* fall through */
				case u8: /* fall through */
				case b8: return true; break;
				default: break;
			}
			break;
		}
		case u64: {
			switch( source ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: return true; break;
				default: break;
			}
			break;
		}
		case u32: {
			switch( source ) {
				case s32: /* fall through */
				case u32: /* fall through */
				case b32: return true; break;
				default: break;
			}
			break;
		}
		case u16: {
			switch( source ) {
				case s16: /* fall through */
				case u16: /* fall through */
				case b16: return true; break;
				default: break;
			}
			break;
		}
		case u8: {
			switch( source ) {
				case s8: /* fall through */
				case u8: /* fall through */
				case b8: return true; break;
				default: break;
			}
			break;
		}
		case s64: {
			switch( source ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: return true; break;
				default: break;
			}
			break;
		}
		case s32: {
			switch( source ) {
				case s32: /* fall through */
				case u32: /* fall through */
				case b32: return true; break;
				default: break;
			}
			break;
		}
		case s16: {
			switch( source ) {
				case s16: /* fall through */
				case u16: /* fall through */
				case b16: return true; break;
				default: break;
			}
			break;
		}
		case s8: {
			switch( source ) {
				case s8: /* fall through */
				case u8: /* fall through */
				case b8: return true; break;
				default: break;
			}
			break;
		}
		case f64: {
			switch( source ) {
				case b64: /* fall through */
				case f64: return true; break;
				default: break;
			}
			break;
		}
		case f32: {
			switch( source ) {
				case b32: /* fall through */
				case f32: return true; break;
				default: break;
			}
			break;
		}
		case f16: {
			switch( source ) {
				case b16: /* fall through */
				case f16: return true; break;
				default: break;
			}
			break;
		}
		case pred: {
			return source == pred;
			break;
		}
		default: break;
		
	}
	return false;
}

bool ir::PTXOperand::relaxedValid( DataType instructionType, 
	DataType operand ) {
	switch( instructionType ) {
		case b64: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case f64: /* fall through */
				case b64: return true; break;
				default: break;
			}
			break;
		}
		case b32: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case f64: /* fall through */
				case b64: /* fall through */
				case s32: /* fall through */
				case u32: /* fall through */
				case f32: /* fall through */
				case b32: return true; break;
				default: break;
			}
			break;
		}
		case b16: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case f64: /* fall through */
				case b64: /* fall through */
				case s32: /* fall through */
				case u32: /* fall through */
				case f32: /* fall through */
				case b32: /* fall through */
				case s16: /* fall through */
				case u16: /* fall through */
				case f16: /* fall through */
				case b16: return true; break;
				default: break;
			}
			break;
		}
		case b8: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case f64: /* fall through */
				case b64: /* fall through */
				case s32: /* fall through */
				case u32: /* fall through */
				case f32: /* fall through */
				case b32: /* fall through */
				case s16: /* fall through */
				case u16: /* fall through */
				case f16: /* fall through */
				case b16: /* fall through */
				case s8: /* fall through */
				case u8: /* fall through */
				case b8: return true; break;
				default: break;
			}
			break;
		}
		case u64: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: return true; break;
				default: break;
			}
			break;
		}
		case u32: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: /* fall through */
				case s32: /* fall through */
				case u32: /* fall through */
				case b32: return true; break;
				default: break;
			}
			break;
		}
		case u16: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: /* fall through */
				case s32: /* fall through */
				case u32: /* fall through */
				case b32: /* fall through */
				case s16: /* fall through */
				case u16: /* fall through */
				case b16: return true; break;
				default: break;
			}
			break;
		}
		case u8: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: /* fall through */
				case s32: /* fall through */
				case u32: /* fall through */
				case b32: /* fall through */
				case s16: /* fall through */
				case u16: /* fall through */
				case b16: /* fall through */
				case s8: /* fall through */
				case u8: /* fall through */
				case b8: return true; break;
				default: break;
			}
			break;
		}
		case s64: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: return true; break;
				default: break;
			}
			break;
		}
		case s32: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: /* fall through */
				case s32: /* fall through */
				case u32: /* fall through */
				case b32: return true; break;
				default: break;
			}
			break;
		}
		case s16: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: /* fall through */
				case s32: /* fall through */
				case u32: /* fall through */
				case b32: /* fall through */
				case s16: /* fall through */
				case u16: /* fall through */
				case b16: return true; break;
				default: break;
			}
			break;
		}
		case s8: {
			switch( operand ) {
				case s64: /* fall through */
				case u64: /* fall through */
				case b64: /* fall through */
				case s32: /* fall through */
				case u32: /* fall through */
				case b32: /* fall through */
				case s16: /* fall through */
				case u16: /* fall through */
				case b16: /* fall through */
				case s8: /* fall through */
				case u8: /* fall through */
				case b8: return true; break;
				default: break;
			}
			break;
		}
		case f64: {
			switch( operand ) {
				case b64: /* fall through */
				case f64: return true; break;
				default: break;
			}
			break;
		}
		case f32: {
			switch( operand ) {
				case b32: /* fall through */
				case f32: return true; break;
				default: break;
			}
			break;
		}
		case f16: {
			switch( operand ) {
				case b16: /* fall through */
				case f16: return true; break;
				default: break;
			}
			break;
		}
		case pred: {
			return operand == pred;
			break;
		}
		default: break;
		
	}
	return false;
}


ir::PTXOperand::PTXOperand() {
	identifier = "";
	addressMode = Invalid;
	type = PTXOperand::s32;
	offset = 0;
	imm_int = 0;
	vec = v1;
}

ir::PTXOperand::PTXOperand(SpecialRegister r, VectorIndex i) : 
	addressMode(Special), vIndex(i), special(r) {
}

ir::PTXOperand::PTXOperand(const std::string& l) : identifier(l), 
	addressMode(Label) {
}

ir::PTXOperand::PTXOperand(AddressMode m, DataType t, RegisterType r, 
	int o, Vec v) : addressMode(m), type(t), offset(o), reg(r), vec(v) {
}

ir::PTXOperand::PTXOperand(AddressMode m, DataType t, 
	const std::string& i, int o, Vec v) : identifier(i), 
	addressMode(m), type(t), offset(o), vec(v) {
}

ir::PTXOperand::~PTXOperand() {

}

/*!
	Displays a binary represetation of a 32-bit floating-point value
*/
static std::ostream & write(std::ostream &stream, float value) {
	union {
		unsigned int imm_uint;
		float value;
	} float_union;
	float_union.value = value;
	stream << "0f" << std::setw(8) << std::setfill('0') 
		<< std::hex << float_union.imm_uint << std::dec;
	return stream;
}

/*!
	Displays a binary represetation of a 64-bit floating-point value
*/
static std::ostream & write(std::ostream &stream, double value) {
	union {
		long long unsigned int imm_uint;
		double value;
	} double_union;
	double_union.value = value;
	stream << "0d" << std::setw(16) << std::setfill('0') << std::hex 
		<< double_union.imm_uint;
	return stream;
}

std::string ir::PTXOperand::toString() const {
	if( addressMode == Indirect ) {
		std::stringstream stream;
		if( offset < 0 ) {
			if ( identifier != "" ) {
				stream << identifier;
			}
			else {
				stream << "%r" << reg;
			}
			stream << " + " << ( offset );
			return stream.str();
		} else {
			if ( identifier != "" ) {
				stream << identifier;
			}
			else {
				stream << "%r" << reg;
			}
			stream << " + " << offset;
			return stream.str();
		}
	} if( addressMode == Address ) {
		std::stringstream stream;
		if( offset == 0 ) {
			return identifier;
		}
		else if( offset < 0 ) {
			stream << ( offset );
			return identifier + " + " + stream.str();
		} else {
			stream << offset;
			return identifier + " + " + stream.str();
		}
	} else if( addressMode == Immediate ) {
		std::stringstream stream;
		switch( type ) {
			case s8:  /* fall through */
			case s16: /* fall through */
			case s32: /* fall through */
			case s64: stream << imm_int; break;
			case u8:  /* fall through */
			case u16: /* fall through */
			case u32: /* fall through */
			case u64: /* fall through */
			case b8:  /* fall through */
			case b16: /* fall through */
			case b32: /* fall through */
			case b64: stream << imm_int; break;
			case f16: /* fall through */
			case f32: {
				write(stream, (float)imm_float);
			} break;
			case f64: {
				write(stream, imm_float);
			} break;
			case pred: /* fall through */
			default: assertM( false, "Invalid immediate type " 
				+ PTXOperand::toString( type ) ); break;
		}
		return stream.str();
	} 
	else if( addressMode == Special ) {
		if( vec == v1 ) {
			return toString( special );
		}
		else {
			assert( array.empty() );
			return toString( special ) + "." + toString( vIndex );
		}
	} 
	else if( type == pred ) {
		switch( condition ) {
			case PT: return "%pt"; break;
			case nPT: return "%pt"; break;
			default:
			{
				if( !identifier.empty() ) {
					return identifier;
				}
				else {
					std::stringstream stream;
					stream << "%p" << reg;
					return stream.str();
				}
				break;
			}
		}
	} 
	else if( vec != v1 ) {
		if( !array.empty() ) {
			assert( ( vec == v2 && array.size() == 2 ) 
				|| ( vec == v4 && array.size() == 4 ) );
			std::string result = "{";
			for( Array::const_iterator fi = array.begin(); 
				fi != array.end(); ++fi ) {
				result += fi->toString();
				if( fi != --array.end() ) {
					result += ", ";
				}
			}
			return result + "}";
		}
		else {
			assert( vIndex != iAll );
			std::stringstream stream;
			if( !identifier.empty() ) {
				stream << identifier;
			}
			else {
				stream << "%r" << reg;
			}
			stream << "." << toString(vIndex);
			return stream.str();
		}
	}
	
	if( !identifier.empty() ) {
		return identifier;
	}
	else {
		std::stringstream stream;
		stream << "%r" << reg;
		return stream.str();
	}
}

std::string ir::PTXOperand::registerName() const {
	assert( addressMode == Indirect || addressMode == Register );
	
	if( !identifier.empty() ) {
		return identifier;
	}
	else {
		std::stringstream stream;
		if(type == pred) {
			switch( condition ) {
				case PT: return "%pt"; break;
				case nPT: return "%pt"; break;
				default:
				{
					std::stringstream stream;
					stream << "%p" << reg;
					return stream.str();
					break;
				}
			}
		}
		else {
			stream << "%r" << reg;
		}
		return stream.str();
	}
}

unsigned int ir::PTXOperand::bytes() const {
	return bytes( type ) * vec;
}


