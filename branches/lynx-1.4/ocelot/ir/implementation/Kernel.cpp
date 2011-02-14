/*! \file Kernel.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 15 Jan 2009 ; 21 Jan 2009
	\brief implements the Kernel base class
*/

#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
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

ir::Kernel::Kernel(Instruction::Architecture isa, const std::string& n, 
	bool isFunction, const ir::Module* m) : 
	_function(isFunction), name(n), ISA(isa), module(m) {
	_cfg = 0;
	_dom_tree = 0;
	_pdom_tree = 0;
	_dfg = 0;
	_ct = 0;
}

ir::Kernel::~Kernel() {
	delete _pdom_tree;
	delete _dom_tree;
	delete _cfg;
	delete _dfg;
	delete _ct;
}

ir::Kernel::Kernel(const Kernel &kernel) {
	// deep copy the elements from a kernel to this one

	name = kernel.name;
	ISA = kernel.ISA;
	parameters = kernel.parameters;
	locals = kernel.locals;
	_function = kernel.function();

	_cfg = 0; _dom_tree = 0; _pdom_tree = 0; _dfg = 0; _ct = 0;
	_cfg = new ControlFlowGraph;
	*_cfg = *kernel._cfg;
	
	module = kernel.module;
}

const ir::Kernel& ir::Kernel::operator=(const Kernel &kernel) {
	// deep copy the elements from a kernel to this one
	if( &kernel == this ) return *this;
	name = kernel.name;
	ISA = kernel.ISA;
	parameters = kernel.parameters;
	locals = kernel.locals;
	_function = kernel.function();

	delete _cfg; delete _dom_tree; delete _pdom_tree; delete _dfg; delete _ct;

	_cfg = 0; _dom_tree = 0; _pdom_tree = 0; _dfg = 0; _ct = 0;
	_cfg = new ControlFlowGraph;
	*_cfg = *kernel._cfg;
	
	module = kernel.module;

	return *this;	
}

ir::Parameter* ir::Kernel::getParameter(const std::string& name) {
	using namespace std;
	for (vector<Parameter>::iterator p_it = parameters.begin(); 
		p_it != parameters.end(); ++p_it) {
		if (p_it->name == name) {
			return &*p_it;
		}
	}
	return 0;
}

const ir::Parameter* ir::Kernel::getParameter(const std::string& name) const {
	using namespace std;
	for (vector<Parameter>::const_iterator p_it = parameters.begin(); 
		p_it != parameters.end(); ++p_it) {
		if (p_it->name == name) {
			return &*p_it;
		}
	}
	return 0;
}

ir::ControlFlowGraph* ir::Kernel::cfg() {
	assertM(_cfg != 0, "CFG not created.");
	return _cfg;
}

const ir::ControlFlowGraph* ir::Kernel::cfg() const {
	assertM(_cfg != 0, "CFG not created.");
	return _cfg;
}

ir::PostdominatorTree* ir::Kernel::pdom_tree() {
	assertM(_cfg != 0, "Must create cfg before building postdominator tree.");
	if (_pdom_tree) return _pdom_tree;
	_pdom_tree = new PostdominatorTree(_cfg);
	return _pdom_tree;
}

ir::DominatorTree* ir::Kernel::dom_tree() {
	assertM(_cfg != 0, "Must create cfg before building dominator tree.");
	if (_dom_tree) return _dom_tree;
	_dom_tree = new DominatorTree(_cfg);
	return _dom_tree;
}

const analysis::DataflowGraph* ir::Kernel::dfg() const {
	assertM(_dfg != 0, "DFG not created.");
	return _dfg;
}

analysis::DataflowGraph* ir::Kernel::dfg() {
	assertM(_dfg != 0, "DFG not created.");
	return _dfg;
}

ir::ControlTree* ir::Kernel::ctrl_tree() {
	assertM(_cfg != 0, "Must create cfg before building control tree.");
	if (_ct) return _ct;
	_ct = new ControlTree(_cfg);
	return _ct;
}

void ir::Kernel::clear_dfg() {
	delete _dfg;
	_dfg = 0;
}

void ir::Kernel::clear_ctrl_tree() {
	delete _ct;
	_ct = 0;
}

void ir::Kernel::clear_pdom_tree() {
	delete _pdom_tree;
	_pdom_tree = 0;
}

void ir::Kernel::clear_dom_tree() {
	delete _dom_tree;
	_dom_tree = 0;
}

bool ir::Kernel::executable() const {
	return false;
}

bool ir::Kernel::function() const {
	return _function;
}

void ir::Kernel::write(std::ostream& stream) const {
	assertM(false, "Writing to a stream not possible from base Kernel class.");
}

std::ostream& operator<<(std::ostream& s, const ir::Kernel& k) {
	k.write(s);
	return s;
}

