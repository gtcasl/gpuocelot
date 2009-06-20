/*!
	\file Kernel.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\date 15 Jan 2009 ; 21 Jan 2009

	\brief implements the Kernel base class
*/

#include <ocelot/ir/interface/Kernel.h>
#include <map>
#include <assert.h>

#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////

ir::Kernel::Kernel() {
	ptxCFG = 0;
	dom_tree = 0;
	pdom_tree = 0;
	module = 0;
}

ir::Kernel::~Kernel() {
	if (ptxCFG) {
		delete pdom_tree;
		delete dom_tree;
		delete ptxCFG;
	}
}

ir::Kernel::Kernel(
			PTXStatementVector::const_iterator start,
			PTXStatementVector::const_iterator end): 
	start_iterator(start), end_iterator(end) {

	using namespace std;
	int Icount = 0;
	unsigned int paramOffset = 0;

	ptxCFG = 0;
	dom_tree = 0;
	pdom_tree = 0;

	// count instructions, get parameters, extract kernel name
	for (PTXStatementVector::const_iterator it = start; it != end; ++it) {
		if ((*it).directive == PTXStatement::Instr) {
			++Icount;
		}
		else if ((*it).directive == PTXStatement::Param) {
			Parameter param(*it);
			param.offset = paramOffset;
			parameters.push_back(param);
			paramOffset += param.getSize();
		}
		else if ((*it).directive == PTXStatement::Entry) {
			name = (*it).name;
		}
	}
	
	ptxCFG = new ControlFlowGraph;

	if (constructCFG(*ptxCFG, instructions, start, end)) {
		dom_tree = new DominatorTree(ptxCFG);
		pdom_tree = new PostdominatorTree(ptxCFG);
	}
}

/*!
	Constructs a control flow graph from a kernel represented as a sequence
	of instructions
*/
bool ir::Kernel::constructCFG(
	ControlFlowGraph &cfg,
	PTXInstructionVector &instructions,
	PTXStatementVector::const_iterator kernelStart,
	PTXStatementVector::const_iterator kernelEnd) {
			
	using namespace ir;
	using namespace std;
		
	map< string, BasicBlock *> blocksByLabel;
	vector< BasicBlock *> branchBlocks;

	BasicBlock *last_inserted_block = 0;
	BasicBlock *block = new BasicBlock;
	Edge *edge = new Edge;
	edge->head = cfg.get_entry_block();
	edge->tail = block;
	edge->type = Edge::FallThrough;
	
	for (int n = 0; kernelStart != kernelEnd; ++kernelStart) {
		const PTXStatement &statement = *kernelStart;
		
		if (statement.directive == PTXStatement::Label) {
			// a label indicates the termination of a previous block
			//
			// This implementation of CFG does not store any empty basic blocks.
			if (block->instructions.size()) {
				//
				// insert old block
				//
				cfg.insert_block(last_inserted_block = block);
				if (edge) {
					cfg.insert_edge(edge);
				}
				
				edge = new Edge;
				edge->head = block;
				block = new BasicBlock;
				edge->tail = block;
				edge->type = Edge::FallThrough;
				
			}
			else {

			}
			block->label = statement.name;
			blocksByLabel[block->label] = block;
		}
		else if (statement.directive == PTXStatement::Instr) {

			block->instructions.push_back((int)instructions.size());
			instructions.push_back(statement.instruction);

			if (statement.instruction.opcode == PTXInstruction::Bra) {
				cfg.insert_block(last_inserted_block = block);
				if (edge) {
					cfg.insert_edge(edge);
				}
				edge = new Edge;
				edge->head = block;
				branchBlocks.push_back(block);

				block = new BasicBlock;
				edge->tail = block;
				edge->type = Edge::FallThrough;
			}
			else if (statement.instruction.opcode == PTXInstruction::Exit) {
				cfg.insert_block(last_inserted_block = block);
				cfg.insert_edge(edge);
				edge = new Edge;
				edge->head = block;
				edge->tail = cfg.get_exit_block();
				edge->type = Edge::FallThrough;
				cfg.insert_edge(edge);

				block = new BasicBlock;
				edge = 0;
			}
			else if (statement.instruction.opcode == PTXInstruction::Call) {
				assert(0 == "unhandled control flow instruction");
				return false;
			}
			else {
				// any special handling with respect to control flow?
			}
			n++;
		}
	}

	if (block->instructions.size()) {
		cfg.insert_block(block);
		if (edge) {
			cfg.insert_edge(edge);
		}
		edge = new Edge;
		edge->head = block;
		edge->tail = cfg.get_exit_block();
		edge->type = Edge::FallThrough;
		cfg.insert_edge(edge);
	}
	else {
		if (last_inserted_block) {
			// make sure there is a fall through edge from the last inserted block
			// to the exit node
			list<Edge *> out_edges = last_inserted_block->get_out_edges();
			Edge *ft_e = 0;
			for (list<Edge*>::iterator it = out_edges.begin(); it != out_edges.end(); ++it) {
				if ((*it)->type == Edge::FallThrough && (*it)->tail == cfg.get_exit_block()) {
					ft_e = (*it);
					break;
				}
			}
			if (!ft_e) {
				Edge *edge = new Edge;
				edge->type = Edge::FallThrough;
				edge->head = last_inserted_block;
				edge->tail = cfg.get_exit_block();
				cfg.insert_edge(edge);
			}
		}
		delete block;
		if (edge) {
			delete edge;
		}
	}

	// go back and add edges for basic blocks terminating in branches
	for (vector< BasicBlock *>::iterator it = branchBlocks.begin();
		it != branchBlocks.end(); ++it) {

		PTXInstruction bra = instructions[(*it)->instructions.back()];
		map< string, BasicBlock* >::iterator labeledBlockIt = 
			blocksByLabel.find(bra.d.identifier);
		
		if (labeledBlockIt != blocksByLabel.end()) {
			Edge *edge = new Edge;
			edge->head = (*it);
			edge->tail = labeledBlockIt->second;
			edge->type = Edge::Branch;
			cfg.insert_edge(edge);
		}
		else {
			// undefined reference
			assert(0 == "undefined reference");
			return false;
		}
	}
	
	// now, anneal the CFG by looking for pairs of basic blocks joined by a fall through
	// edge, the first not terminated by a branch, and the second with only one predecessor.
	
	branchBlocks.clear();
	blocksByLabel.clear();
	
	return true;
}

void ir::Kernel::clone(const Kernel &kernel) {
	// deep copy the elements from a kernel to this one

	name = kernel.name;
	ISA = kernel.ISA;
	globalStatements = kernel.globalStatements;
	parameters = kernel.parameters;
	start_iterator = kernel.start_iterator;
	end_iterator = kernel.end_iterator;
	instructions = kernel.instructions;
	module = kernel.module;

	if (ptxCFG) {
		delete dom_tree; delete pdom_tree;
		delete ptxCFG;
	}
	ptxCFG = 0; dom_tree = 0; pdom_tree = 0;
	if (kernel.ptxCFG) {
		ptxCFG = new ControlFlowGraph;
		*ptxCFG = *kernel.ptxCFG;
		dom_tree = new DominatorTree(ptxCFG);
		pdom_tree = new PostdominatorTree(ptxCFG);
	}
}

/*!
	Gets a parameter named by 'name.' Undefined result returned if parameter 
		doesn't exist
*/
ir::Parameter & ir::Kernel::getParameter(const std::string& name) {
	using namespace std;
	for (vector<Parameter>::iterator p_it = parameters.begin(); 
		p_it != parameters.end(); ++p_it) {
		if (p_it->name == name) {
			return *p_it;
		}
	}
	assert( "Invalid parameter" == 0 );
	return parameters.front();
}
/*!
	Gets a parameter named by 'name.' Undefined result returned if parameter 
		doesn't exist
*/
const ir::Parameter & ir::Kernel::getParameter(const std::string& name) const {
	using namespace std;
	for (vector<Parameter>::const_iterator p_it = parameters.begin(); 
		p_it != parameters.end(); ++p_it) {
		if (p_it->name == name) {
			return *p_it;
		}
	}
	assert( "Invalid parameter" == 0 );
	return parameters.front();
}
