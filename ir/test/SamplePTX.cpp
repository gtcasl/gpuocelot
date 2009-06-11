/*!
	\file SamplePTX.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief defines PTX programs useful for testing

	\date 24 Jan 2009
*/

#include <string>
#include <ocelot/ir/test/SamplePTX.h>

using namespace std;
using namespace ir;

//////////////////////////////////////////////////////////////////////////////////////////////////

static ir::PTXStatement i_add(string d, string a, string b, ir::PTXOperand::DataType type = PTXOperand::f32) {

	PTXStatement state;
	state.directive = PTXStatement::Instr;
	state.instruction.opcode = PTXInstruction::Add;
	state.instruction.d.addressMode = PTXOperand::Register;
	state.instruction.d.identifier = d;
	state.instruction.d.type = type;

	state.instruction.a.addressMode = PTXOperand::Register;
	state.instruction.a.identifier = a;
	state.instruction.a.type = type;

	state.instruction.b.addressMode = PTXOperand::Register;
	state.instruction.b.identifier = b;
	state.instruction.b.type = type;

	return state;
}

static ir::PTXStatement i_mul(string d, string a, string b, ir::PTXOperand::DataType type = PTXOperand::f32) {

	PTXStatement state;
	state.directive = PTXStatement::Instr;
	state.instruction.opcode = PTXInstruction::Mul;
	state.instruction.d.addressMode = PTXOperand::Register;
	state.instruction.d.identifier = d;
	state.instruction.d.type = type;

	state.instruction.a.addressMode = PTXOperand::Register;
	state.instruction.a.identifier = a;
	state.instruction.a.type = type;

	state.instruction.b.addressMode = PTXOperand::Register;
	state.instruction.b.identifier = b;
	state.instruction.b.type = type;

	return state;
}

static ir::PTXStatement i_sub(string d, string a, string b, ir::PTXOperand::DataType type = PTXOperand::f32) {
	PTXStatement state;
	state.directive = PTXStatement::Instr;
	state.instruction.opcode = PTXInstruction::Sub;
	state.instruction.d.addressMode = PTXOperand::Register;
	state.instruction.d.identifier = d;
	state.instruction.d.type = type;

	state.instruction.a.addressMode = PTXOperand::Register;
	state.instruction.a.identifier = a;
	state.instruction.a.type = type;

	state.instruction.b.addressMode = PTXOperand::Register;
	state.instruction.b.identifier = b;
	state.instruction.b.type = type;

	return state;
}

static ir::PTXStatement i_bra(string target) {
	PTXStatement state;

	state.directive = PTXStatement::Instr;
	state.instruction.opcode = PTXInstruction::Bra;
	//state.instruction.target.identifier = target;

	return state;
}

static ir::PTXStatement label(string name) {
	PTXStatement state;

	state.directive = PTXStatement::Label;
	state.name = name;

	return state;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!

*/
ir::Kernel::PTXStatementVector test::Sample_cfg() {

	ir::Kernel::PTXStatementVector ptx;

	ptx.push_back( i_add("$r2", "$r0", "$r1") );
	ptx.push_back( i_sub("$r2", "$r0", "$r1") );
	ptx.push_back( i_bra("$L_01") );
	
	ptx.push_back( i_add("$r3", "$r2", "$r1") );

	ptx.push_back( label("$L_01") );
	ptx.push_back( i_sub("$r2", "$r3", "$r1") );

	ptx.push_back( label("$L_02") );
	ptx.push_back( i_add("$r7", "$r2", "$r2") );
	ptx.push_back( i_bra("$L_01") );

	ptx.push_back( i_add("$r2", "$r7", "$r7") );

	return ptx;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Constructs a kernel with divergent control flow
*/
ir::Kernel::PTXStatementVector test::Sample_Divergence() {
	ir::Kernel::PTXStatementVector ptx;
	
	ptx.push_back( label("L01") );
	ptx.push_back( i_add("r1", "r2", "r3"));
	ptx.push_back( i_sub("r1", "r1", "r1"));
	ptx.push_back(i_bra("L02"));
	
	ptx.push_back( label("L03") );
	ptx.push_back( i_add("r3", "r2", "r1"));
	ptx.push_back( i_bra("L07"));
	
	ptx.push_back( label("L02"));
	ptx.push_back( i_add("r2", "r2", "r2"));
	ptx.push_back( i_add("r2", "r3", "r3"));
	ptx.push_back( i_bra("L05"));
	
	ptx.push_back( label("L04") );
	ptx.push_back( i_sub("r4", "r2", "r1"));
	ptx.push_back( i_bra("L06"));
	
	ptx.push_back(label("L05"));
	ptx.push_back(i_sub("r5", "r5", "r5"));
	ptx.push_back(i_mul("r5", "r5", "r6"));
	
	ptx.push_back(label("L06"));
	ptx.push_back(i_mul("r6", "r6", "r6"));
	
	ptx.push_back( label("L07") );
	ptx.push_back(i_add("r7", "r7", "r7"));
	ptx.push_back(i_bra("L01"));
	
	return ptx;	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

