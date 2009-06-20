/*!
	\file Parameter.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 15, 2009

	\brief describes a parameter declaration
*/

#include <ocelot/ir/interface/Parameter.h>

std::string ir::Parameter::value( const Parameter& p ) {
	std::stringstream stream;
	switch (p.type) {
		case PTXOperand::u8: break;
		case PTXOperand::s8: break;
		case PTXOperand::b8: stream << "0x" << std::hex; stream.width(2); break;
		case PTXOperand::u16: break;
		case PTXOperand::s16: break;
		case PTXOperand::b16: stream << "0x" << std::hex; stream.width(4); break;
		case PTXOperand::u32: break;
		case PTXOperand::s32: break;
		case PTXOperand::b32: stream << "0x" << std::hex; stream.width(8); break;
		case PTXOperand::f32: break;
		case PTXOperand::u64: stream << "0x" << std::hex; stream.width(16); break;
		case PTXOperand::s64: break;
		case PTXOperand::b64: stream << "0x" << std::hex; stream.width(16); break;
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
			case PTXOperand::b8: stream.width(2); stream << (int)fi->val_b8; break;
			case PTXOperand::u16: stream << fi->val_u16; break;
			case PTXOperand::s16: stream << fi->val_s16; break;
			case PTXOperand::b16: stream.width(4); stream << fi->val_b16; break;
			case PTXOperand::u32: stream << fi->val_u32; break;
			case PTXOperand::s32: stream << fi->val_s32; break;
			case PTXOperand::b32: stream.width(8); stream << fi->val_b32; break;
			case PTXOperand::f32: stream << fi->val_f32; break;
			case PTXOperand::u64: stream.width(16); stream << fi->val_u64; break;
			case PTXOperand::s64: stream << fi->val_s64; break;
			case PTXOperand::b64: stream.width(16); stream << fi->val_b64; break;
			case PTXOperand::f64: stream << fi->val_f64; break;
			default: break;
		}
	}
	return stream.str();
}

ir::Parameter::Parameter() {
	type = PTXOperand::u64;
	offset = 0;
}

ir::Parameter::~Parameter() {

}

ir::Parameter::Parameter(const PTXStatement& statement) {
	type = PTXOperand::u64;
	offset = 0;
	
	if (statement.directive == PTXStatement::Param) {
		type = statement.type;
		name = statement.name;
		arrayValues.resize(statement.elements());
	}
}

unsigned int ir::Parameter::getSize() const {
	return getElementSize() * arrayValues.size();
}

unsigned int ir::Parameter::getElementSize() const {
	switch (type) {
		case PTXOperand::b8:
		case PTXOperand::u8:
		case PTXOperand::s8:
			return sizeof(PTXB8);
		case PTXOperand::u16:
		case PTXOperand::s16:
		case PTXOperand::b16:
			return sizeof(PTXU16);
		case PTXOperand::u32:
		case PTXOperand::s32:
		case PTXOperand::b32:
		case PTXOperand::f32:
			return sizeof(PTXU32);
		case PTXOperand::u64:
		case PTXOperand::s64:
		case PTXOperand::b64:
		case PTXOperand::f64:
			return sizeof(PTXU64);
		default:
			break;
	}
	return 0;
}

