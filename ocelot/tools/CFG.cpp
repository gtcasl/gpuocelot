/*! \file CFG.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief tests CFG analysis by forming a CFG from a sequence of instructions known to produce
		a certain CFG and then comparing output
*/

#include <iostream>
#include <string>
#include <fstream>
#include <string>

#include <hydrazine/interface/ArgumentParser.h>
#include <hydrazine/interface/macros.h>
#include <hydrazine/interface/debug.h>

#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/DominatorTree.h>
#include <ocelot/ir/interface/PostdominatorTree.h>
#include <ocelot/ir/interface/ControlTree.h>
#include <ocelot/parser/interface/PTXParser.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

void analyze(const char *filename) {
	using namespace std;
	using namespace ir;

	ir::Module module(filename);

	Module::KernelMap::const_iterator k_it = module.kernels().begin();

	for (; k_it != module.kernels().end(); ++k_it) {

		ir::PTXKernel* kernel = static_cast< ir::PTXKernel* >(k_it->second);

		string filename = kernel->name;
		string cfg_fname = filename + "_cfg.dot";
		string dom_fname = filename + "_dom.dot";
		string pdom_fname = filename + "_pdom.dot";
		string ct_fname = filename + "_ct.dot";

		ofstream cfg_file(cfg_fname.c_str());
		ofstream dom_file(dom_fname.c_str());
		ofstream pdom_file(pdom_fname.c_str());
		ofstream ct_file(ct_fname.c_str());
		
		cfg_file << "// Kernel: " << kernel->name << "\n";
		cfg_file << "// Control flow graph\n";
		kernel->cfg()->write(cfg_file);
		cfg_file.close();

		dom_file << "// Kernel: " << kernel->name << "\n";
		dom_file << "// Dominator tree\n";
		kernel->dom_tree()->write(dom_file);
		dom_file.close();
		
		pdom_file << "// Kernel: " << kernel->name << "\n";
		pdom_file << "// Post dominator tree\n";
		kernel->pdom_tree()->write(pdom_file);
		pdom_file.close();
		
		ct_file << "// Kernel: " << kernel->name << "\n";
		ct_file << "// Control tree\n";
		kernel->ctrl_tree()->write(ct_file);
		ct_file.close();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

static void print_usage() {
	using namespace std;

	cout << "CFG <input path>:\n\n";
	cout << " - parses the input file, performs control flow analysis on each kernel\n";
	cout << "   and emits .dot files for the CFG, dominator tree, and post dominator tree\n";

	cout << "\n  To construct graphs of them, use the following command:\n\n";
	cout << "    for f in *.dot; do dot -Tpdf -o $f.pdf $f; done\n\n";
}

int main(int argc, char **argv) {
	using namespace std;
	using namespace ir;

	if (argc == 1) {
		print_usage();
	}
	else {
		for (int i = 1; i < argc; i++) {
			analyze(argv[i]);
		}
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

