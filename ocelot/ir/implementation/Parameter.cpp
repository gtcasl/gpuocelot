/*! \file Parameter.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief describes a parameter declaration
*/

#include <ocelot/ir/interface/Parameter.h>
#include <hydrazine/implementation/debug.h>

std::string ir::Parameter::value( const Parameter& p ) {
	std::stringstream stream;
	switch (p.type) {
		case PTXOperand::u8: break;
		case PTXOperand::s8: break;
		case PTXOperand::b8: stream << "0x" << std::hex; stream.width(2); 
			break;
		case PTXOperand::u16: break;
		case PTXOperand::s16: break;
		case PTXOperand::b16: stream << "0x" << std::hex; stream.width(4); 
			break;
		case PTXOperand::u32: break;
		case PTXOperand::s32: break;
		case PTXOperand::b32: stream << "0x" << std::hex; stream.width(8); 
			break;
		case PTXOperand::f32: break;
		case PTXOperand::u64: stream << "0x" << std::hex; stream.width(16); 
			break;
		case PTXOperand::s64: break;
		case PTXOperand::b64: stream << "0x" << std::hex; stream.width(16); 
			break;
		case PTXOperand::f64: break;
		default: break;
	}

	stream.fill('0');
	stream << std::right;

	for (ValueVector::const_reverse_iterator fi = p.arrayValues.rbegin(); 
		fi != p.arrayValues.rend(); ++fi) {
		switch (p.type) {
			case PTXOperand::u8: stream << (int)fi->val_u8; break;
			case PTXOperand::s8: stream << (int)fi->val_s8; break;
			case PTXOperand::b8: stream.width(2); stream << (int)fi->val_b8; 
				break;
			case PTXOperand::u16: stream << fi->val_u16; break;
			case PTXOperand::s16: stream << fi->val_s16; break;
			case PTXOperand::b16: stream.width(4); stream << fi->val_b16; break;
			case PTXOperand::u32: stream << fi->val_u32; break;
			case PTXOperand::s32: stream << fi->val_s32; break;
			case PTXOperand::b32: stream.width(8); stream << fi->val_b32; break;
			case PTXOperand::f32: stream << fi->val_f32; break;
			case PTXOperand::u64: stream.width(16); stream << fi->val_u64; 
				break;
			case PTXOperand::s64: stream << fi->val_s64; break;
			case PTXOperand::b64: stream.width(16); stream << fi->val_b64; 
				break;
			case PTXOperand::f64: stream << fi->val_f64; break;
			default: break;
		}
	}
	return stream.str();
}

ir::Parameter::Parameter() {
	type = PTXOperand::u64;
	offset = 0;
	vector = PTXOperand::v1;
}

ir::Parameter::~Parameter() {

}

ir::Parameter::Parameter(const PTXStatement& statement) {
	type = PTXOperand::u64;
	offset = 0;
	
	assertM( statement.directive == PTXStatement::Param, 
		"Can only build Paramater out of a parameter statement." ) 
	type = statement.type;
	name = statement.name;
	alignment = statement.alignment;
	arrayValues.resize(statement.elements());
	vector = statement.array.vec;
}

unsigned int ir::Parameter::getSize() const {
	return getElementSize() * arrayValues.size();
}

unsigned int ir::Parameter::getElementSize() const {
	switch (type) {
		case PTXOperand::pred: /* fall through */
		case PTXOperand::b8: /* fall through */
		case PTXOperand::u8: /* fall through */
		case PTXOperand::s8: /* fall through */
			return sizeof(PTXB8) * vector;
		case PTXOperand::u16: /* fall through */
		case PTXOperand::s16: /* fall through */
		case PTXOperand::b16: /* fall through */
			return sizeof(PTXU16) * vector;
		case PTXOperand::u32: /* fall through */
		case PTXOperand::s32: /* fall through */
		case PTXOperand::b32: /* fall through */
		case PTXOperand::f32: /* fall through */
			return sizeof(PTXU32) * vector;
		case PTXOperand::u64: /* fall through */
		case PTXOperand::s64: /* fall through */
		case PTXOperand::b64: /* fall through */
		case PTXOperand::f64: /* fall through */
			return sizeof(PTXU64) * vector;
		default:
			break;
	}
	return 0;
}

unsigned int ir::Parameter::getAlignment() const {
	return std::max( getElementSize(), alignment );
}

std::string ir::Parameter::toString() const {
	std::stringstream stream;
	stream << ".param ";
	if( alignment != 1 ) {
		stream << ".align " << alignment;
	}
	if( vector != PTXOperand::v1 ) {
		stream << "." << PTXInstruction::toString( vector );
	}
	stream << " ." << PTXOperand::toString( type ) << " " << name;
	if (arrayValues.size() > 1 && vector == ir::PTXOperand::v1) {
		stream << "[" << arrayValues.size() << "]";
	}
	return stream.str();
}

