/*! \file IRKernel.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday January 22, 2011
	\brief The source file for the IRKernel class.
*/

#ifndef IR_KERNEL_CPP_INCLUDED
#define IR_KERNEL_CPP_INCLUDED

#include <ocelot/ir/interface/IRKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/DivergenceAnalysis.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PostdominatorTree.h>
#include <ocelot/ir/interface/DominatorTree.h>
#include <ocelot/ir/interface/ControlTree.h>

#include <hydrazine/interface/Version.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

ir::IRKernel::IRKernel(Instruction::Architecture isa, const std::string& n, 
	bool isFunction, const ir::Module* m) : Kernel(isa, n, isFunction, m) {
	_cfg = 0;
	_dom_tree = 0;
	_pdom_tree = 0;
	_dfg = 0;
	_ct = 0;
	_dva = 0;
}

ir::IRKernel::~IRKernel() {
	delete _pdom_tree;
	delete _dom_tree;
	delete _cfg;
	delete _dfg;
	delete _ct;
	delete _dva;
}

ir::IRKernel::IRKernel(const IRKernel &kernel) {
	// deep copy the elements from a kernel to this one

	name = kernel.name;
	ISA = kernel.ISA;
	parameters = kernel.parameters;
	arguments = kernel.arguments;
	locals = kernel.locals;
	_function = kernel.function();

	_cfg = 0; _dom_tree = 0; _pdom_tree = 0; _dfg = 0; _ct = 0; _dva = 0;
	_cfg = new ControlFlowGraph;
	*_cfg = *kernel._cfg;
	
	module = kernel.module;
}

const ir::IRKernel& ir::IRKernel::operator=(const IRKernel &kernel) {
	// deep copy the elements from a kernel to this one
	if( &kernel == this ) return *this;
	
	Kernel::operator=(kernel);
	
	delete _cfg; delete _dom_tree; delete _pdom_tree; delete _dfg; delete _ct; delete _dva;

	_cfg = 0; _dom_tree = 0; _pdom_tree = 0; _dfg = 0; _ct = 0; _dva = 0;
	_cfg = new ControlFlowGraph;
	*_cfg = *kernel._cfg;
	
	module = kernel.module;

	return *this;	
}

ir::ControlFlowGraph* ir::IRKernel::cfg() {
	assertM(_cfg != 0, "CFG not created.");
	return _cfg;
}

const ir::ControlFlowGraph* ir::IRKernel::cfg() const {
	assertM(_cfg != 0, "CFG not created.");
	return _cfg;
}

ir::PostdominatorTree* ir::IRKernel::pdom_tree() {
	assertM(_cfg != 0, "Must create cfg before building postdominator tree.");
	if (_pdom_tree) return _pdom_tree;
	_pdom_tree = new PostdominatorTree(_cfg);
	return _pdom_tree;
}

ir::DominatorTree* ir::IRKernel::dom_tree() {
	assertM(_cfg != 0, "Must create cfg before building dominator tree.");
	if (_dom_tree) return _dom_tree;
	_dom_tree = new DominatorTree(_cfg);
	return _dom_tree;
}

const analysis::DataflowGraph* ir::IRKernel::dfg() const {
	assertM(_dfg != 0, "DFG not created.");
	return _dfg;
}

analysis::DataflowGraph* ir::IRKernel::dfg() {
	assertM(_dfg != 0, "DFG not created.");
	return _dfg;
}

analysis::DivergenceAnalysis* ir::IRKernel::div_analy() {
	assertM(_dva != 0, "Divergence Analysis not created.");
	return _dva;
}

const analysis::DivergenceAnalysis* ir::IRKernel::div_analy() const {
	assertM(_dva != 0, "Divergence Analysis not created.");
	return _dva;
}

ir::ControlTree* ir::IRKernel::ctrl_tree() {
	assertM(_cfg != 0, "Must create cfg before building control tree.");
	if (_ct) return _ct;
	_ct = new ControlTree(_cfg);
	return _ct;
}

void ir::IRKernel::clear_dfg() {
	delete _dfg;
	_dfg = 0;
}

void ir::IRKernel::clear_ctrl_tree() {
	delete _ct;
	_ct = 0;
}

void ir::IRKernel::clear_pdom_tree() {
	delete _pdom_tree;
	_pdom_tree = 0;
}

void ir::IRKernel::clear_dom_tree() {
	delete _dom_tree;
	_dom_tree = 0;
}

void ir::IRKernel::clear_div_analy() {
	delete _dva;
	_dva = 0;
}

bool ir::IRKernel::executable() const {
	return false;
}

#endif

