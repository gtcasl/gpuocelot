/*!
	\file PTXOperand.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief internal representation of a PTX operand
*/

#include <ocelot/ir/interface/PTXOperand.h>
#include <cassert>
#include <sstream>
#include <iomanip>

std::string ir::PTXOperand::toString( DataType type ) {
	assert( type != TypeSpecifier_invalid );
	switch( type ) {
		case s8: return "s8"; break;
		case s16: return "s16"; break;
		case s32: return "s32"; break;
		case s64: return "s64"; break;
		case u8: return "u8"; break;
		case u16: return "u16"; break;
		case u32: return "u32"; break;
		case u64: return "u64"; break;
		case b8: return "b8"; break;
		case b16: return "b16"; break;
		case b32: return "b32"; break;
		case b64: return "b64"; break;
		case f16: return "f16"; break;
		case f32: return "f32"; break;
		case f64: return "f64"; break;
		case pred: return "pred"; break;
		default: break;
	}
	return "Invalid";
}

std::string ir::PTXOperand::toString( SpecialRegister reg ) {
	assert( reg != SpecialRegister_invalid );
	switch( reg ) {
		case tidX: return "%tid.x"; break;
		case tidY: return "%tid.y"; break;
		case tidZ: return "%tid.z"; break;
		case ntidX: return "%ntid.x"; break;
		case ntidY: return "%ntid.y"; break;
		case ntidZ: return "%ntid.z"; break;
		case laneId: return "%laneid"; break;
		case warpId: return "%warpid"; break;
		case warpSize: return "WARP_SZ"; break;
		case ctaIdX: return "%ctaid.x"; break;
		case ctaIdY: return "%ctaid.y"; break;
		case ctaIdZ: return "%ctaid.z"; break;
		case nctaIdX: return "%nctaid.x"; break;
		case nctaIdY: return "%nctaid.y"; break;
		case nctaIdZ: return "%nctaid.z"; break;
		case smId: return "%smid"; break;
		case nsmId: return "%nsmid"; break;
		case gridId: return "%gridid"; break;
		case clock: return "%clock"; break;
		case pm0: return "%pm0"; break;
		case pm1: return "%pm1"; break;
		case pm2: return "%pm2"; break;
		case pm3: return "%pm3"; break;
		default: break;
	}
	return "SpecialRegister_invalid";
}

std::string ir::PTXOperand::toString( AddressMode mode ) {
	assert( mode != Invalid );
	switch( mode ) {
		case Register: return "Register"; break;
		case Indirect: return "Indirect"; break;
		case Immediate: return "Immediate"; break;
		case Address: return "Address"; break;
		case Label: return "Label"; break;
		case Special: return "Special"; break;
		default: break;
	}
	return "Invalid";
}

bool ir::PTXOperand::isFloat( DataType type ) {
	assert( type != TypeSpecifier_invalid );
	switch( type ) {
		case f16: /* fall through */
		case f32: /* fall through */
		case f64: return true; break;
		default: break;
	}
	return false;
}

bool ir::PTXOperand::isInt( DataType type ) {
	assert( type != TypeSpecifier_invalid );
	switch( type ) {
		case s8:  /* fall through */
		case s16: /* fall through */
		case s32: /* fall through */
		case s64: /* fall through */
		case u8:  /* fall through */
		case u16: /* fall through */
		case u32: /* fall through */
		case u64: return true; break;
		default: break;
	}
	return false;
}

unsigned int ir::PTXOperand::bytes( DataType type ) {
	assert( type != TypeSpecifier_invalid );
	switch( type ) {
		case b8: /* fall through */
		case u8: /* fall through */
		case s8: return 1; break;
		case u16: /* fall through */
		case f16: /* fall through */
		case b16: /* fall through */
		case s16: return 2; break;
		case u32: /* fall through */
		case b32: /* fall through */
		case f32: /* fall through */
		case s32: return 4; break;
		case f64: /* fall through */
		case u64: /* fall through */
		case b64: /* fall through */
		case s64: return 8; break;
		default: return 0; break;
	}
	return 0;	
}

bool ir::PTXOperand::valid( DataType destination, DataType source ) {
	switch( destination ) {
		case b64: {
			switch( source ) {
				case s8: /* fall through */
				case s16: /* fall through */
				case s32: /* fall through */
				case s64: /* fall through */
				case u8: /* fall through */
				case u16: /* fall through */
				case u32: /* fall through */
				case u64: /* fall through */
				case b8: /* fall through */
				case b16: /* fall through */
				case b32: /* fall through */
				case b64: return true; break;
				default: break;
			}
			break;
		}
		case b32: {
			switch( source ) {
				case s8: /* fall through */
				case s16: /* fall through */
				case s32: /* fall through */
				case u8: /* fall through */
				case u16: /* fall through */
				case u32: /* fall through */
				case b8: /* fall through */
				case b16: /* fall through */
				case b32: return true; break;
				default: break;
			}
			break;
		}
		case b16: {
			switch( source ) {
				case s8: /* fall through */
				case s16: /* fall through */
				case u8: /* fall through */
				case u16: /* fall through */
				case b8: /* fall through */
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
				case u8: /* fall through */
				case u16: /* fall through */
				case u32: /* fall through */
				case u64: /* fall through */
				case b8: /* fall through */
				case b16: /* fall through */
				case b32: /* fall through */
				case b64: return true; break;
				default: break;
			}
			break;
		}
		case u32: {
			switch( source ) {
				case u8: /* fall through */
				case u16: /* fall through */
				case u32: /* fall through */
				case b8: /* fall through */
				case b16: /* fall through */
				case b32: return true; break;
				default: break;
			}
			break;
		}
		case u16: {
			switch( source ) {
				case u8: /* fall through */
				case u16: /* fall through */
				case b8: /* fall through */
				case b16: return true; break;
				default: break;
			}
			break;
		}
		case u8: {
			switch( source ) {
				case u8: /* fall through */
				case b8: return true; break;
				default: break;
			}
			break;
		}
		case s64: {
			switch( source ) {
				case s8: /* fall through */
				case s16: /* fall through */
				case s32: /* fall through */
				case s64: /* fall through */
				case u8: /* fall through */
				case u16: /* fall through */
				case u32: /* fall through */
				case u64: /* fall through */
				case b8: /* fall through */
				case b16: /* fall through */
				case b32: /* fall through */
				case b64: return true; break;
				default: break;
			}
			break;
		}
		case s32: {
			switch( source ) {
				case s8: /* fall through */
				case s16: /* fall through */
				case s32: /* fall through */
				case u8: /* fall through */
				case u16: /* fall through */
				case u32: /* fall through */
				case b8: /* fall through */
				case b16: /* fall through */
				case b32: return true; break;
				default: break;
			}
			break;
		}
		case s16: {
			switch( source ) {
				case s8: /* fall through */
				case s16: /* fall through */
				case u8: /* fall through */
				case u16: /* fall through */
				case b8: /* fall through */
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
				case f16: /* fall through */
				case f32: /* fall through */
				case f64: return true; break;
				default: break;
			}
			break;
		}
		case f32: {
			switch( source ) {
				case f16: /* fall through */
				case f32: return true; break;
				default: break;
			}
			break;
		}
		case f16: {
			switch( source ) {
				case f16: return true; break;
				default: break;
			}
			break;
		}
		case pred: {
			break;
			return source == pred;
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

ir::PTXOperand::~PTXOperand() {

}

std::string ir::PTXOperand::toString() const {
	if( addressMode == Indirect ) {
		std::stringstream stream;
		if( offset < 0 ) {
			stream << ( -offset );
			return identifier + " - " + stream.str();
		} else {
			stream << offset;
			return identifier + " + " + stream.str();
		}
	} if( addressMode == Address ) {
		std::stringstream stream;
		if( offset == 0 ) {
			return identifier;
		}
		else if( offset < 0 ) {
			stream << ( -offset );
			return identifier + " - " + stream.str();
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
			case b64: stream << imm_uint; break;
			case f16: /* fall through */
			case f32: /* fall through */
			case f64:stream << "0f" << std::setw(16) << std::setfill('0') 
				<< std::hex << imm_uint; break;
			case pred: /* fall through */
			default: assert( "Invalid immediate type" == 0 ); break;
		}
		return stream.str();
	} else if( addressMode == Special ) {
		return toString( special );
	} else if( type == pred ) {
		switch( condition ) {
			case InvPred: return "!" + identifier; break;
			case PT: return "%pt"; break;
			case nPT: return "!%pt"; break;
			default: break;
		}
	} else if( vec != v1 && !array.empty() ) {
		assert( ( vec == v2 && array.size() == 2 ) 
			|| ( vec == v4 && array.size() == 4 ) );
		std::string result = "{";
		for( Array::const_iterator fi = array.begin(); 
			fi != array.end(); ++fi ) {
			result += fi->identifier;
			if( fi != --array.end() ) {
				result += ", ";
			}
		}
		return result + "}";
	}
	
	return identifier;
}

unsigned int ir::PTXOperand::bytes() const {
	return bytes( type ) * vec;
}


