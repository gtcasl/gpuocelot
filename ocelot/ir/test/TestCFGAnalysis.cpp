/*!
	\file TestCFGAnalysis.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief tests CFG analysis by forming a CFG from a sequence of instructions known to produce
		a certain CFG and then comparing output
*/

#include <sstream>
#include <hydrazine/interface/Test.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/implementation/debug.h>

#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>

#include <ocelot/ir/test/SamplePTX.h>

/*!
	\brief A namespace for unit tests
*/
namespace test {

class TestCFGAnalysis: public Test {
public:
	bool verbose;
	std::stringstream output;

	TestCFGAnalysis() {
		verbose = false;
		Name = "TestCFGAnalysis";

		Description = "Analyzes a sequence of statements to form a PTX control flow graph.\n";
		Description += " Compares expected basic block structure to what is produced.";

		output << "Test output:\n";
	}

	bool doTest( std::string & status ) {
		using namespace std;
		using namespace ir;

		bool result = true;

		ir::Kernel::PTXInstructionVector instructions;

		ir::Kernel::PTXStatementVector statements = Sample_cfg();

		cfg = new ControlFlowGraph;

		Kernel::constructCFG(*cfg, instructions, statements.begin(), statements.end());
		
		if (!validate_cfg()) {
			result = false;
		}
	
		delete cfg;

		return result;
	}

private:
	
	bool validate_cfg() {
		using namespace std;
		using namespace ir;
		/*
		<entry>

		<unnamed>
			add r2
			sub r2
			bra L_01

		<unnamed>
			add r3

		L_01
			sub r2

		L_02
			add r7
			bra L_01

		<unnamed
			add r2

		<exit>
		*/
		
		// examine the above structure
		if (!cfg) {
			return false;
		}

		list< const ir::BasicBlock *> all_blocks = cfg->get_blocks();
		list< BasicBlock *> blocks;
		list< ir::Edge *> edges;
		Edge *fall_through, *branch;

		if (verbose) {
			int n = 0;
			output << "Basic blocks:\n";
			for (list<const ir::BasicBlock *>::iterator it = all_blocks.begin(); it != all_blocks.end(); ++it) {
				output << "[" << (n++) << "] - " << (*it)->label << "\n";
			}
		}

		BasicBlock *block = cfg->get_entry_block();

		blocks = block->get_successors();

		if (blocks.size() != 1) {
			if (verbose) {
				output << "entry node does not have one successor\n";
			}
			return false;
		}

		block = blocks.front();
		if (block->instructions.size() != 3) {
			if (verbose) {
				output << "first block does not have 3 instructions\n";
			}
			return false;
		}

		blocks = block->get_successors();
		if (blocks.size() != 2) {
			if (verbose) {
				output << "first block does not have 2 successors\n";
			}
			return false;
		}
		edges = block->get_out_edges();

		if (edges.front()->type == Edge::FallThrough) {
			fall_through = edges.front();
			branch = edges.back();
		} else {
			fall_through = edges.back();
			branch = edges.front();
		}
		if (branch->tail->label != "$L_01") {
			if (verbose) {
				output << "branch edge does not point to correct BB\n" << flush;
			}
			return false;
		}
		block = branch->tail;
		fall_through = block->get_out_edges().front();
		if (fall_through->type != Edge::FallThrough || fall_through->tail->label != "$L_02") {
			if (verbose) {
				output << "successor to branch block fails\n" << flush;
			}
			return false;
		}
		block = fall_through->tail;
		edges = block->get_out_edges();
		if (edges.size() != 2) {
			if (verbose) {
				output << "L_02 block does not have 2 out edges\n" << flush;
			}
			return false;
		}
		if (edges.front()->type == Edge::FallThrough) {
			fall_through = edges.front();
			branch = edges.back();
		} else {
			fall_through = edges.back();
			branch = edges.front();
		}

		return true;
	}

	std::vector< ir::PTXStatement > statements;

	ir::ControlFlowGraph *cfg;
};

}

int main(int argc, char **argv) {
	using namespace std;
	using namespace ir;
	using namespace test;

	hydrazine::ArgumentParser parser( argc, argv );
	test::TestCFGAnalysis test;

	parser.description( test.description() );

	bool help;

	parser.parse( "-h", help, "Display this help message." );
	parser.parse( "-v", test.verbose, "Print out info after the test." );

	if( help ) {
		std::cout << parser.help();
		return 2;
	}

	test.test();

	if( test.verbose )	{
		std::cout << test.toString();

		std::cout << test.output.str();
	}

	return test.passed();
}

