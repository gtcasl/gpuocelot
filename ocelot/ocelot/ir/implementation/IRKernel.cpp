/*! \file IRKernel.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday January 22, 2011
	\brief The source file for the IRKernel class.
*/

#ifndef IR_KERNEL_CPP_INCLUDED
#define IR_KERNEL_CPP_INCLUDED

#include <ocelot/ir/interface/IRKernel.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>

#include <hydrazine/interface/Version.h>
#include <hydrazine/interface/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

ir::IRKernel::IRKernel(Instruction::Architecture isa, const std::string& n, 
	bool isFunction, const ir::Module* m, Id id)
: Kernel(isa, n, isFunction, m), _cfg(0), _id(id) {

}

ir::IRKernel::~IRKernel() {
	delete _cfg;
}

ir::IRKernel::IRKernel(const IRKernel &kernel) : Kernel(kernel) {
	// deep copy the elements from a kernel to this one

	_id = kernel.id();
	_cfg = new ControlFlowGraph(this);
	*_cfg = *kernel._cfg;
	
}

const ir::IRKernel& ir::IRKernel::operator=(const IRKernel &kernel) {
	// deep copy the elements from a kernel to this one
	if( &kernel == this ) return *this;
	
	Kernel::operator=(kernel);
	
	delete _cfg;
	
	_id = kernel.id();
	_cfg = new ControlFlowGraph(this);
	*_cfg = *kernel._cfg;

	return *this;	
}

ir::ControlFlowGraph* ir::IRKernel::cfg() {
	return _cfg;
}

const ir::ControlFlowGraph* ir::IRKernel::cfg() const {
	return _cfg;
}

ir::IRKernel::Id ir::IRKernel::id() const {
	return _id;
}

bool ir::IRKernel::executable() const {
	return false;
}

#endif

