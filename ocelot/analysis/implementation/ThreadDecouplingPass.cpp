/*! 
	\file ThreadDecouplingPass.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date  21 February 2011
	\brief defines ThreadDecouplingPass which replaces uses of threadIdx.{x,y,z} with loads 
		from a .local variable
*/

// Ocelot includes
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/analysis/interface/ThreadDecouplingPass.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

static const char *getLocalVariableName(ir::PTXOperand::VectorIndex v) {
	switch (v) {
	case ir::PTXOperand::ix:
		return "local_threadIdx_x";
	case ir::PTXOperand::iy:
		return "local_threadIdx_y";
	case ir::PTXOperand::iz:
		return "local_threadIdx_z";
	default:
		break;
	}
	return "unknown";
}

//! constructs the pass
analysis::ThreadDecouplingPass::ThreadDecouplingPass() {

}

void analysis::ThreadDecouplingPass::initialize( ir::Module& m ) {

}

void analysis::ThreadDecouplingPass::initialize( ir::Kernel& k ) {
	//
	// TODO: kernels should not be const - the initialize function should be permitted
	//   to modify the kernel
	//
	ir::PTXStatement threadIdX(ir::PTXStatement::Local);
	threadIdX.name = getLocalVariableName(ir::PTXOperand::ix);
	threadIdx.type = ir::PTXOperand::u16;
	k.insertVariable(threadIdX);
	
	ir::PTXStatement threadIdY(ir::PTXStatement::Local);
	threadIdX.name = getLocalVariableName(ir::PTXOperand::iy);
	threadIdx.type = ir::PTXOperand::u16;
	k.insertVariable(threadIdY);
	
	ir::PTXStatement threadIdZ(ir::PTXStatement::Local);
	threadIdX.name = getLocalVariableName(ir::PTXOperand::iz);
	threadIdx.type = ir::PTXOperand::u16;
	k.insertVariable(threadIdZ);
}

void analysis::ThreadDecouplingPass::runOnBlock( ir::BasicBlock& block ) {
	for (InstructionList::iterator inst_it = b.instructions.begin(); 
		inst_it != b.instructions.end(); ++inst_it) {
		ir::PTXInstruction *instruction = static_cast<ir::PTXInstruction *>(*inst_it);
		
		ir::PTXOperand ir::PTXInstruction::*operands[] = { &ir::PTXInstruction::a, 
			&ir::PTXInstruction::b, &ir::PTXInstruction::c};
		for (int i = 0; i < 3; i++) {
			ir::PTXOperand &operand = instruction->*(operands[i]);
			if (operand.addressMode == ir::PTXOperand::Special && operand.special == ir::PTXOperand::tid) {
				
				ir::PTXInstruction mov(ir::PTXInstruction::Mov);
				mov.type = (sizeof(void*) > sizeof(int) ? ir::PTXOperand::u64 : ir::PTXOperand::u32);
				mov.d.addressMode = ir::PTXOperand::Register;
				mov.d.type  = move.type;
				mov.d.reg = _kernel->dfg()->newRegister();
				
				mov.a.addressMode = ir::PTXOperand::Register;
				mov.a.type  = move.type;
				mov.a.identifier = getLocalVariableName(operand.vIndex);
				
				// _kernel->dfg()->insert( block, move, block->instructions().size() - 1 );
				
				ir::PTXInstruction load ( ir::PTXInstruction::Ld );
				
				load.type = ir::PTXOperand::u16;
				load.addressSpace = ir::PTXInstruction::Local;
			
				load.d.addressMode = ir::PTXOperand::Register;
				load.d.type = load.type;
				load.d.reg = _kernel->dfg()->newRegister();
				
				load.a.addressMode = ir::PTXOperand::Indirect;
				load.a.type = mov.type;
				load.a.reg = mov.reg;
				
				// _kernel->dfg()->insert( block, load, block->instructions().size() - 1 );
			}
		}
	}
}

void analysis::ThreadDecouplingPass::finalizeKernel( ) {

}

void analysis::ThreadDecouplingPass::finalize( ) {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

