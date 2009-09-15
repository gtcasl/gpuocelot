/*!
	\file Kernel.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 15 Jan 2009 ; 21 Jan 2009
	\brief implements the Kernel base class
*/

#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

#include <hydrazine/interface/Version.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

//////////////////////////////////////////////////////////////////////////////////////////////////

ir::Kernel::Kernel() {
	ptxCFG = 0;
	dom_tree = 0;
	pdom_tree = 0;
	dfg = 0;
	module = 0;
}

ir::Kernel::~Kernel() {
	delete pdom_tree;
	delete dom_tree;
	delete ptxCFG;
	delete dfg;
}

ir::Kernel::Kernel(
			PTXStatementVector::const_iterator start,
			PTXStatementVector::const_iterator end): 
	start_iterator(start), end_iterator(end) {

	using namespace std;
	
	ptxCFG = 0;
	dom_tree = 0;
	pdom_tree = 0;
	dfg = 0;

	// count instructions, get parameters, extract kernel name
	for (PTXStatementVector::const_iterator it = start; it != end; ++it) {
		if ((*it).directive == PTXStatement::Param) {
			Parameter param(*it);
			parameters.push_back(param);
		}
		else if ((*it).directive == PTXStatement::Entry) {
			name = (*it).name;
		}
	}
	ptxCFG = new ControlFlowGraph;
	constructCFG(*ptxCFG, instructions, start_iterator, end_iterator);
}

ir::Kernel::Kernel(const Kernel &kernel) {
	// deep copy the elements from a kernel to this one

	name = kernel.name;
	ISA = kernel.ISA;
	globalStatements = kernel.globalStatements;
	parameters = kernel.parameters;
	start_iterator = kernel.start_iterator;
	end_iterator = kernel.end_iterator;
	instructions = kernel.instructions;
	module = kernel.module;

	ptxCFG = 0; dom_tree = 0; pdom_tree = 0; dfg = 0;
	ptxCFG = new ControlFlowGraph;
	*ptxCFG = *kernel.ptxCFG;
	if (kernel.dom_tree) buildDominatorTree();
	if (kernel.pdom_tree) buildPostDominatorTree();
	if (kernel.dfg) buildDataflowGraph();
}

const ir::Kernel& ir::Kernel::operator=(const Kernel &kernel) {
	// deep copy the elements from a kernel to this one
	if( &kernel == this ) return *this;
	name = kernel.name;
	ISA = kernel.ISA;
	globalStatements = kernel.globalStatements;
	parameters = kernel.parameters;
	start_iterator = kernel.start_iterator;
	end_iterator = kernel.end_iterator;
	instructions = kernel.instructions;
	module = kernel.module;

	delete dom_tree; delete pdom_tree;
	delete ptxCFG; delete dfg;

	ptxCFG = 0; dom_tree = 0; pdom_tree = 0; dfg = 0;
	assert(kernel.ptxCFG);
	ptxCFG = new ControlFlowGraph;
	*ptxCFG = *kernel.ptxCFG;
	if (kernel.dom_tree) buildDominatorTree();
	if (kernel.pdom_tree) buildPostDominatorTree();
	if (kernel.dfg) buildDataflowGraph();

	return *this;	
}

bool ir::Kernel::executable() const {
	return false;
}

ir::Parameter& ir::Kernel::getParameter(const std::string& name) {
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

const ir::Parameter& ir::Kernel::getParameter(const std::string& name) const {
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

void ir::Kernel::buildPostDominatorTree() {
	assertM(ptxCFG != 0, "Must create cfg before building postdominator tree.");
	if (pdom_tree) return;
	pdom_tree = new PostdominatorTree(ptxCFG);
}

void ir::Kernel::buildDominatorTree() {
	assertM(ptxCFG != 0, "Must create cfg before building dominator tree.");
	if (dom_tree) return;
	dom_tree = new DominatorTree(ptxCFG);	
}

void ir::Kernel::buildDataflowGraph() {
	assertM(ptxCFG != 0, "Must create cfg before building dataflow graph.");
	if (dfg) return;
	dfg = new analysis::DataflowGraph(*ptxCFG, instructions);
}

void ir::Kernel::constructCFG(
	ControlFlowGraph &cfg,
	PTXInstructionVector &instructions,
	PTXStatementVector::const_iterator kernelStart,
	PTXStatementVector::const_iterator kernelEnd) {
			
	using namespace ir;
	using namespace std;
	
	typedef std::unordered_map< string, BasicBlock *> BlockToLabelMap;
	
	BlockToLabelMap blocksByLabel;
	vector< BasicBlock *> branchBlocks;

	BasicBlock *last_inserted_block = 0;
	BasicBlock *block = new BasicBlock;
	Edge *edge = new Edge;
	edge->head = cfg.get_entry_block();
	edge->tail = block;
	edge->type = Edge::FallThrough;
	
	for (; kernelStart != kernelEnd; ++kernelStart) {
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
				assertM(false, "Unhandled control flow instruction call");
			}
			else {
				// any special handling with respect to control flow?
			}
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
		BlockToLabelMap::iterator labeledBlockIt = 
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
			assertM(false, "undefined label " << bra.d.identifier);
		}
	}
}

ir::Kernel::RegisterMap ir::Kernel::assignRegisters( 
	PTXInstructionVector& instructions ) {
	RegisterMap map;
	
	report( "Allocating registers" );
	
	for (PTXInstructionVector::iterator i_it = instructions.begin();
		i_it != instructions.end(); ++i_it) {
		PTXInstruction & instr = *i_it;
		PTXOperand PTXInstruction:: * operands[] = { 
			&PTXInstruction::a, &PTXInstruction::b, &PTXInstruction::c, 
			&PTXInstruction::d, &PTXInstruction::pg, &PTXInstruction::pq
		};
		
		report( " For instruction '" << instr.toString() << "'" );
		
		for (int i = 0; i < 6; i++) {
			if ((instr.*operands[i]).addressMode == PTXOperand::Invalid) {
				continue;
			}
			if ((instr.*operands[i]).type == PTXOperand::pred
				&& (instr.*operands[i]).condition == PTXOperand::PT ) {
				continue;
			}
			if ((instr.*operands[i]).addressMode == PTXOperand::Register 
				|| (instr.*operands[i]).addressMode == PTXOperand::Indirect )  {
				if ((instr.*operands[i]).vec != PTXOperand::v1) {
					for (PTXOperand::Array::iterator 
						a_it = (instr.*operands[i]).array.begin(); 
						a_it != (instr.*operands[i]).array.end(); ++a_it) {
						RegisterMap::iterator it = map.find(a_it->identifier);

						PTXOperand::RegisterType reg = 0;
						if (it == map.end()) {
							reg = (PTXOperand::RegisterType)map.size();
							map.insert( std::make_pair( 
								a_it->identifier, reg ) );
						}
						else {
							reg = it->second;
						}
						a_it->reg = reg;
						report( "  Assigning register " << a_it->identifier 
							<< " to " << a_it->reg );
					}
				}
				RegisterMap::iterator it 
					= map.find((instr.*operands[i]).identifier);

				PTXOperand::RegisterType reg = 0;
				if (it == map.end()) {
					reg = (PTXOperand::RegisterType)map.size();
					map.insert( std::make_pair( 
						(instr.*operands[i]).identifier, reg ) );
				}
				else {
					reg = it->second;
				}
				(instr.*operands[i]).reg = reg;
				report( "  Assigning register " 
					<< (instr.*operands[i]).identifier << " to " << reg );
			}
		}
	}
	return std::move( map );
}

std::ostream& operator<<( std::ostream& stream, const ir::Kernel& k ) {
	stream << "/*\n* Ocelot Version : " 
		<< hydrazine::Version().toString() << "\n";
	stream << "*/\n";
	
	ir::PTXStatement::Directive previous = ir::PTXStatement::Directive_invalid;
	
	if( k.start_iterator->version == ir::PTXInstruction::ptx1_4 ) {
		for( ir::Kernel::PTXStatementVector::const_iterator 
			statement = k.start_iterator; 
			statement != k.end_iterator; ++statement ) {
			report( "Line " << ( statement - k.start_iterator ) 
				<< ": " << statement->toString() );
			if( statement->directive == ir::PTXStatement::Param )
			{
				if( previous != ir::PTXStatement::StartParam )
				{
					stream << ",\n\t" << statement->toString();
				}
				else
				{
					stream << "\n\t" << statement->toString();
				}
			}
			else
			{
				stream << "\n";
				if( statement->directive == ir::PTXStatement::Instr 
					|| statement->directive == ir::PTXStatement::Loc ) {
					stream << "\t";
				}
				stream << statement->toString();
			}
			previous = statement->directive;
		}
		stream << "\n";
	}
	else {
		for( ir::Kernel::PTXStatementVector::const_iterator 
			statement = k.start_iterator; 
			statement != k.end_iterator; ++statement ) {
			report( "Line " << ( statement - k.start_iterator ) 
				<< ": " << statement->toString() );
			stream << statement->toString() << "\n";
		}
		stream << "\n";
	}
	return stream;
}


