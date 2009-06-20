/*!
	\file Instruction.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 15, 2009

	\brief base class for all instructions
*/

#include <ocelot/ir/interface/Instruction.h>

ir::Instruction::Instruction() {
	ISA = Instruction::PTX;
}

ir::Instruction::~Instruction() {

}


