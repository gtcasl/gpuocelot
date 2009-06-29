/*!
	\file EmulatedKernel.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 19, 2009

	\brief implements the Kernel base class
*/

#include <vector>
#include <map>
#include <unordered_set>

#include <ocelot/ir/interface/Parameter.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/RuntimeException.h>
#include <ocelot/executive/interface/CooperativeThreadArray.h>

#include <ocelot/trace/interface/TraceGenerator.h>

#include <assert.h>
#include <math.h>

#include <cstring>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

using namespace ir;

executive::EmulatedKernel::EmulatedKernel(ir::Kernel *kernel) {
	ConstMemory = ParameterMemory = 0;
	ConstMemorySize = ParameterMemorySize = SharedMemorySize = 0;

	clone(*kernel);
	initialize();
}

executive::EmulatedKernel::EmulatedKernel() {
	this->ISA = ir::Instruction::Emulated;

}

executive::EmulatedKernel::~EmulatedKernel() {
	freeAll();
}

/*!
	Launch a kernel on a 2D grid
*/
void executive::EmulatedKernel::launchGrid(int width, int height) {
	report("EmulatedKernel::launchGrid called");
	report("  " << RegisterCount << " registers");

	gridDim = dim3( width, height, 1 );	
	
	// notify trace generator(s)
	for (std::list<trace::TraceGenerator*>::iterator it = Traces.begin(); 
		it != Traces.end(); ++it) {
		(*it)->initialize(this);
	}

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
	
			dim3 block(x,y,0);
			CooperativeThreadArray cta(this);

			cta.initialize( gridDim, !Traces.empty() );

			cta.execute(block);
		}
	}

}

/*!
	Sets the shape of a kernel
*/
void executive::EmulatedKernel::setKernelShape(int x, int y, int z) {
	typedef unsigned int uint;

	freeRegions();

	blockDim.x = x;
	blockDim.y = y;
	blockDim.z = z;

	threadCount = x*y*z;
}

void executive::EmulatedKernel::freeRegions() {

}

/*!
	adds a trace generator to the EmulatedKernel
*/
void executive::EmulatedKernel::addTraceGenerator(trace::TraceGenerator *generator) {
	Traces.push_back(generator);
}

/*!
	removes a trace generator from an EmulatedKernel
*/
void executive::EmulatedKernel::removeTraceGenerator(trace::TraceGenerator *generator) {
	Traces.remove(generator);
}

void executive::EmulatedKernel::traceEvent( const trace::TraceEvent & event ) const {
	// notify trace generator(s)
	if (Traces.size()) {
		for (std::list<trace::TraceGenerator*>::const_iterator 
			it = Traces.begin(); it != Traces.end(); ++it) {
			(*it)->event(event);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Cleans up the EmulatedKernel instance
*/
void executive::EmulatedKernel::freeAll() {
	if (ConstMemory) {
		delete [] ConstMemory;
	}
	if (ParameterMemory) {
		delete [] ParameterMemory;
	}
	ParameterMemory = ConstMemory = 0;
}

/*!
	From Kernel, analyze application and construct data structures necessary 
	for emulation
*/
void executive::EmulatedKernel::initialize() {
	constructInstructionSequence();
	updateParamReferences();
	registerAllocation();
	initializeSharedMemory();
	initializeParameterMemory();
	initializeLocalMemory();
}

void executive::EmulatedKernel::configureParameters() {

}

/*!
	Produces a packed vector of instructions, updates each operand, and changes labels
	to indices.
*/
void executive::EmulatedKernel::constructInstructionSequence() {
	using namespace std;

	// visit basic blocks and add reconverge instructions
	vector< BasicBlock * > bb_sequence = ptxCFG->executable_sequence();
	vector<BasicBlock *>::iterator bb_it = bb_sequence.begin();

	for (; bb_it != bb_sequence.end(); ++bb_it) {
		ir::BasicBlock::InstructionList::iterator i_it = (*bb_it)->instructions.begin();
		for (; i_it != (*bb_it)->instructions.end(); ++i_it) {
			PTXInstruction &ptx_instr = instructions[*i_it];
			if (ptx_instr.opcode == PTXInstruction::Bra && !ptx_instr.uni) {
				// find post-dominator and insert reconverge instruction into head if one does not
				// already exist

				BasicBlock *pdom = pdom_tree->getPostDominator(*bb_it);

				PTXInstruction reconverge;
				int n = (int)instructions.size();

				reconverge.opcode = PTXInstruction::Reconverge;
				instructions.push_back(reconverge);

				pdom->instructions.push_front(n);
				instructions[*i_it].reconvergeInstruction = n;

			}
		}
	}

	// form the output instruction sequence then update the branch target instructions
	map<int,int> reconverge_map;
	map<string, int> label_to_instruction;
	vector<int> branch_instructions;
	map< BasicBlock *, int > basicBlockMap; // map between pointers to basic blocks and their
																					// first instruction
	map< int, const Edge * > branchEdgeMap;

	// visit instructions and pack into KernelInstructions vector
	bb_it = bb_sequence.begin();

	for (; bb_it != bb_sequence.end(); ++bb_it) {
		if (!(*bb_it)->instructions.size()) continue;

		ir::BasicBlock::InstructionList::iterator i_it = (*bb_it)->instructions.begin();

		basicBlockMap[*bb_it] = (int)KernelInstructions.size();

		if ((*bb_it)->label != "") {
			label_to_instruction[(*bb_it)->label] = (int)KernelInstructions.size();
		}

		for (; i_it != (*bb_it)->instructions.end(); ++i_it) {
			const PTXInstruction &ptx_instr = instructions[*i_it];
			if (ptx_instr.opcode == PTXInstruction::Bra) {
				branch_instructions.push_back((int)KernelInstructions.size());

				// find the branch edge and push it to a map
				list< ir::Edge *> out_edges = (*bb_it)->get_out_edges();

				for (list< ir::Edge *>::iterator oe_it = out_edges.begin();
					oe_it != out_edges.end(); ++oe_it ) {
					const ir::Edge *edge = (*oe_it);
					if (edge->type == ir::Edge::Branch) {
						branchEdgeMap[(int)KernelInstructions.size()] = edge;
					}
				}
			}
			else if (ptx_instr.opcode == PTXInstruction::Reconverge) {
				reconverge_map[*i_it] = (int)KernelInstructions.size();
			}
			KernelInstructions.push_back(ptx_instr);
		}
	}

	// replace branch targets with indices and assign reconvergeInstruction indices
	for (vector<int>::iterator br_it = branch_instructions.begin(); 
		br_it != branch_instructions.end(); ++br_it) {

		PTXInstruction &bra = KernelInstructions[*br_it];

		if (branchEdgeMap.find(*br_it) != branchEdgeMap.end()) {
			bra.branchTargetInstruction = basicBlockMap[branchEdgeMap[*br_it]->tail];
		}
		else {
			// this really shouldn't ever get called
			//bra.branchTargetInstruction = label_to_instruction[bra.d.identifier];
		}
		bra.reconvergeInstruction = reconverge_map[bra.reconvergeInstruction];
		
	}
	
	initializeTextureMemory();

}

/*!
	After emitting the instruction sequence, visit each memory move operation and replace
	references to parameters with offsets into parameter memory.

	Data movement instructions: ld, st
*/
void executive::EmulatedKernel::updateParamReferences() {
	using namespace std;
	for (vector<PTXInstruction>::iterator i_it = KernelInstructions.begin();
		i_it != KernelInstructions.end(); ++i_it) {
		PTXInstruction & instr = *i_it;
		if (instr.addressSpace == PTXInstruction::Param) {
			if (instr.opcode == PTXInstruction::Ld) {
				Parameter &param = getParameter(instr.a.identifier);
				instr.a.offset += param.offset;
				instr.a.imm_uint = 0;
			}
			else if (instr.opcode == PTXInstruction::St) {
				Parameter &param = getParameter(instr.d.identifier);
				instr.d.offset += param.offset;
				instr.d.imm_uint = 0;
			}
		}
	}
}

/*!
	Allocate parameter memory by determining the sizes used by each parameter
*/
void executive::EmulatedKernel::initializeParameterMemory() {
	using namespace std;
	report( "Initializing parameter memory for kernel " << name );
	if( ParameterMemory ) {
		delete[] ParameterMemory;
		ParameterMemory = 0;
	}
	ParameterMemorySize = 0;
	for(std::vector<ir::Parameter>::iterator i_it = parameters.begin();
		i_it != parameters.end(); ++i_it ) {
		report( " Initializing memory for paramter " << i_it->name 
			<< " of size " << i_it->getSize() );
		ParameterMemorySize += i_it->getSize();
	}	
}

void executive::EmulatedKernel::updateParameterMemory() {
	using namespace std;

	if(ParameterMemory != 0)
	{
	
		delete[] ParameterMemory;
	
	}
	
	ParameterMemory = new char[ParameterMemorySize];
	
	unsigned int size = 0;
	for(std::vector<ir::Parameter>::iterator i_it = parameters.begin();
		i_it != parameters.end(); ++i_it ) {
		for(ir::Parameter::ValueVector::iterator 
			v_it = i_it->arrayValues.begin(); 
			v_it != i_it->arrayValues.end(); ++v_it) {
			assert( size < ParameterMemorySize );
			memcpy( ParameterMemory + size, &v_it->val_b16, 
				i_it->getElementSize() );
			size += i_it->getElementSize();
		}
	}	

}

/*!
	On construction, allocates registers by computing live ranges
	This assumes that the PTX compiler did a good job at register allocation
*/
void executive::EmulatedKernel::registerAllocation() {
	using namespace std;

	for (vector<PTXInstruction>::iterator i_it = KernelInstructions.begin();
		i_it != KernelInstructions.end(); ++i_it) {
		PTXInstruction & instr = *i_it;
		PTXOperand PTXInstruction:: * operands[] = { 
			&PTXInstruction::a, &PTXInstruction::b, &PTXInstruction::c, 
			&PTXInstruction::d, &PTXInstruction::pg, &PTXInstruction::pq
		};
		
		for (int i = 0; i < 6; i++) {
			if ((instr.*operands[i]).addressMode == PTXOperand::Invalid) {
				continue;
			}
			if ((instr.*operands[i]).addressMode == PTXOperand::Register 
				|| (instr.*operands[i]).addressMode == PTXOperand::Indirect )  {
				if ((instr.*operands[i]).vec != PTXOperand::v1) {
					for (PTXOperand::Array::iterator 
						a_it = (instr.*operands[i]).array.begin(); 
						a_it != (instr.*operands[i]).array.end(); ++a_it) {
						RegisterMap::iterator it = 
							registerMap.find(a_it->identifier);

						PTXOperand::RegisterType reg = 0;
						if (it == registerMap.end()) {
							reg = (PTXOperand::RegisterType)registerMap.size();
							registerMap[a_it->identifier] = reg;
						}
						else {
							reg = it->second;
						}
						a_it->reg = reg;
					}
				}
				RegisterMap::iterator it = 
					registerMap.find((instr.*operands[i]).identifier);

				PTXOperand::RegisterType reg = 0;
				if (it == registerMap.end()) {
					reg = (PTXOperand::RegisterType)registerMap.size();
					registerMap[(instr.*operands[i]).identifier] = reg;
				}
				else {
					reg = it->second;
				}
				(instr.*operands[i]).reg = reg;
			}
		}
	}
	RegisterCount = (int)registerMap.size();
}

/*!
	Allocates arrays in shared memory and maps identifiers to allocations.
*/
void executive::EmulatedKernel::initializeSharedMemory() {
	using namespace std;

	unsigned int sharedOffset = 0;

	map<string, unsigned int> label_map;
	
	if(module != 0) {
		for(ir::Module::GlobalMap::const_iterator it = module->globals.begin(); 
			it != module->globals.end(); ++it) {
			if (it->second.statement.directive == PTXStatement::Shared) {
				// compute address given alignment requirements
				unsigned int padding = ((it->second.statement.alignment - 
					(sharedOffset % it->second.statement.alignment)) 
					% it->second.statement.alignment);
				unsigned int offset = sharedOffset + padding;

				report("Found global shared variable " 
					<< it->second.statement.name);
				label_map[it->second.statement.name] = offset;

				sharedOffset = offset;
				if(it->second.statement.array.stride.empty()) {
					sharedOffset += it->second.statement.array.vec * 
						ir::PTXOperand::bytes(it->second.statement.type);
				}
				else {
					for (int i = 0; 
						i < (int)it->second.statement.array.stride.size(); 
						i++) {
						sharedOffset += it->second.statement.array.stride[i] 
							* it->second.statement.array.vec 
							* ir::PTXOperand::bytes(it->second.statement.type);
					}
				}
			}	
		}
	}
	
	PTXStatementVector::const_iterator it = start_iterator;
	for (; it != end_iterator; ++it) {
		if (it->directive == PTXStatement::Shared) {
			// compute address given alignment requirements
			unsigned int padding = ((it->alignment - 
				(sharedOffset % it->alignment)) % it->alignment);
			unsigned int offset = sharedOffset + padding;

			report("Found local shared variable " << it->name);
			label_map[it->name] = offset;

			sharedOffset = offset;
			if(it->array.stride.empty()) {
				sharedOffset += it->array.vec * 
					ir::PTXOperand::bytes(it->type);
			}
			else {
				for (int i = 0; i < (int)it->array.stride.size(); i++) {
					sharedOffset += it->array.stride[i] * it->array.vec * 
						ir::PTXOperand::bytes(it->type);
				}
			}
		}
	}

	// now visit every instruction and change the address mode from label to immediate, and assign
	// the offset as an immediate value 
	PTXOperand PTXInstruction:: *operands[] = { &PTXInstruction::d,
		&PTXInstruction::a, &PTXInstruction::b, &PTXInstruction::c
	};
	vector<PTXInstruction>::iterator i_it = KernelInstructions.begin();
	for (; i_it != KernelInstructions.end(); ++i_it) {
		PTXInstruction &instr = *i_it;

		// look for mov and ld/st instructions
		if (instr.opcode == PTXInstruction::Mov) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode == PTXOperand::Address) {
					map<string, unsigned int>::iterator 
						l_it = label_map.find((instr.*operands[n]).identifier);
					if (label_map.end() != l_it) {
						(instr.*operands[n]).type = PTXOperand::u64;
						(instr.*operands[n]).imm_uint = l_it->second;
						report("For instruction " << instr.toString() 
							<< ", mapping shared label " << l_it->first 
							<< " to " << l_it->second );
					}
				}
			}
		}
		else if (instr.opcode == PTXInstruction::Ld 
			|| instr.opcode == PTXInstruction::St) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode == PTXOperand::Address) {
					map<string, unsigned int>::iterator 
						l_it = label_map.find((instr.*operands[n]).identifier);
					if (label_map.end() != l_it) {
						report("For instruction " << instr.toString() 
							<< ", mapping shared label " << l_it->first 
							<< " to " << l_it->second );
						(instr.*operands[n]).type = PTXOperand::u64;
						(instr.*operands[n]).imm_uint = l_it->second;
					}
				}
			}			
		}
	}

	// allocate shared memory object
	SharedMemorySize = sharedOffset;
	
	report("Total shared memory size is " << SharedMemorySize);
}

/*!
	Allocates arrays in local memory and maps identifiers to allocations.
*/
void executive::EmulatedKernel::initializeLocalMemory() {
	using namespace std;

	unsigned int localOffset = 0;

	map<string, unsigned int> label_map;
	
	if(module != 0) {
		for(ir::Module::GlobalMap::const_iterator it = module->globals.begin(); 
			it != module->globals.end(); ++it) {
			if (it->second.statement.directive == PTXStatement::Local) {
				// compute address given alignment requirements
				unsigned int padding = ((it->second.statement.alignment - 
					(localOffset % it->second.statement.alignment)) 
					% it->second.statement.alignment);
				unsigned int offset = localOffset + padding;

				report("Found global local variable " 
					<< it->second.statement.name);
				label_map[it->second.statement.name] = offset;

				localOffset = offset;
				if(it->second.statement.array.stride.empty()) {
					localOffset += it->second.statement.array.vec * 
						ir::PTXOperand::bytes(it->second.statement.type);
				}
				else {
					for (int i = 0; 
						i < (int)it->second.statement.array.stride.size(); 
						i++) {
						localOffset += it->second.statement.array.stride[i] 
							* it->second.statement.array.vec 
							* ir::PTXOperand::bytes(it->second.statement.type);
					}
				}
			}	
		}
	}
	
	PTXStatementVector::const_iterator it = start_iterator;
	for (; it != end_iterator; ++it) {
		if (it->directive == PTXStatement::Local) {
			// compute address given alignment requirements
			unsigned int padding = ((it->alignment - 
				(localOffset % it->alignment)) % it->alignment);
			unsigned int offset = localOffset + padding;

			report("Found local local variable " << it->name);
			label_map[it->name] = offset;

			localOffset = offset;
			if(it->array.stride.empty()) {
				localOffset += it->array.vec * 
					ir::PTXOperand::bytes(it->type);
			}
			else {
				for (int i = 0; i < (int)it->array.stride.size(); i++) {
					localOffset += it->array.stride[i] * it->array.vec * 
						ir::PTXOperand::bytes(it->type);
				}
			}
		}
	}

	// now visit every instruction and change the address mode from label to immediate, and assign
	// the offset as an immediate value 
	PTXOperand PTXInstruction:: *operands[] = { &PTXInstruction::d,
		&PTXInstruction::a, &PTXInstruction::b, &PTXInstruction::c
	};
	vector<PTXInstruction>::iterator i_it = KernelInstructions.begin();
	for (; i_it != KernelInstructions.end(); ++i_it) {
		PTXInstruction &instr = *i_it;

		// look for mov and ld/st instructions
		if (instr.opcode == PTXInstruction::Mov) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode == PTXOperand::Address) {
					map<string, unsigned int>::iterator 
						l_it = label_map.find((instr.*operands[n]).identifier);
					if (label_map.end() != l_it) {
						(instr.*operands[n]).type = PTXOperand::u64;
						(instr.*operands[n]).imm_uint = l_it->second;
						report("For instruction " << instr.toString() 
							<< ", mapping local label " << l_it->first 
							<< " to " << l_it->second );
					}
				}
			}
		}
		else if (instr.opcode == PTXInstruction::Ld 
			|| instr.opcode == PTXInstruction::St) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode == PTXOperand::Address) {
					map<string, unsigned int>::iterator 
						l_it = label_map.find((instr.*operands[n]).identifier);
					if (label_map.end() != l_it) {
						report("For instruction " << instr.toString() 
							<< ", mapping local label " << l_it->first 
							<< " to " << l_it->second );
						(instr.*operands[n]).type = PTXOperand::u64;
						(instr.*operands[n]).imm_uint = l_it->second;
					}
				}
			}			
		}
	}

	// allocate local memory object
	LocalMemorySize = localOffset;
	
}

/*!
	Maps identifiers to const memory allocations.
*/
void executive::EmulatedKernel::initializeConstMemory() {
	using namespace std;
	if (module == 0) {
		return;
	}

	report("Initializing constant variables for kernel " << name);

	unsigned int constantOffset = 0;

	map<string, unsigned int> constant;
	ir::Module::GlobalMap::const_iterator it = module->globals.begin();
	for (; it != module->globals.end(); ++it) {
		if (it->second.statement.directive == ir::PTXStatement::Const) {
			assert(it->second.registered || it->second.local);
			report("Found global const variable " << it->first);
			unsigned int padding = ((it->second.statement.alignment - 
				(constantOffset % it->second.statement.alignment)) 
				% it->second.statement.alignment);
			unsigned int offset = constantOffset + padding;
			assert( constant.count(it->first) == 0 );
			constant[it->first] = offset;

			constantOffset = offset;
			
			if(it->second.statement.array.stride.empty()) {
				constantOffset += it->second.statement.array.vec * 
					ir::PTXOperand::bytes(it->second.statement.type);
			}
			else {
				for (int i = 0; 
					i < (int)it->second.statement.array.stride.size(); i++) {
					constantOffset += it->second.statement.array.stride[i] 
						* it->second.statement.array.vec 
						* ir::PTXOperand::bytes(it->second.statement.type);
				}
			}
		}
	}
	
	report( "Total constant memory size is " << constantOffset );

	// now visit every instruction and change the address mode from label to immediate, and assign
	// the offset as an immediate value 
	PTXOperand PTXInstruction:: *operands[] = {
		&PTXInstruction::d, &PTXInstruction::a, &PTXInstruction::b, 
		&PTXInstruction::c
	};
	vector<PTXInstruction>::iterator i_it = KernelInstructions.begin();
	for (; i_it != KernelInstructions.end(); ++i_it) {
		PTXInstruction &instr = *i_it;

		// look for mov instructions or ld/st instruction
		if (instr.opcode == PTXInstruction::Mov) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode == PTXOperand::Address) {
					map<string, unsigned int>::iterator 
						l_it = constant.find((instr.*operands[n]).identifier);
					if (constant.end() != l_it) {
						report("For instruction " << instr.toString() 
							<< ", mapping constant label " << l_it->first 
							<< " to " << l_it->second );
						(instr.*operands[n]).type = PTXOperand::u64;
						(instr.*operands[n]).imm_uint = l_it->second;
					}
				}
			}
		}
		else if ( instr.opcode == PTXInstruction::Ld 
			|| instr.opcode == PTXInstruction::St ) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode == PTXOperand::Address) {
					map<string, unsigned int>::iterator 
						l_it = constant.find((instr.*operands[n]).identifier);
					if (constant.end() != l_it) {
						report("For instruction " << instr.toString() 
							<< ", mapping constant label " << l_it->first 
							<< " to " << l_it->second );
						(instr.*operands[n]).type = PTXOperand::u64;
						(instr.*operands[n]).imm_uint = l_it->second;
					}
				}
			}
		}
	}

	// allocate constant memory object
	if (ConstMemory) {
		delete[] ConstMemory;
	}
	
	ConstMemorySize = constantOffset;
	if (ConstMemorySize > 0) {
		ConstMemory = new char[ConstMemorySize];
	}
	else {
		ConstMemory = 0;
	}
	
	// copy globals into constant memory
	for (map<string, unsigned int>::iterator l_it = constant.begin(); 
		l_it != constant.end(); ++l_it) {
		ir::Module::GlobalMap::const_iterator 
			g_it = module->globals.find(l_it->first);
		assert(g_it != module->globals.end());
		assert(g_it->second.statement.directive == ir::PTXStatement::Const);
		assert(g_it->second.statement.bytes() 
			+ l_it->second <= ConstMemorySize);
		memcpy( ConstMemory + l_it->second, g_it->second.pointer, 
			g_it->second.statement.bytes() );
	}

}

/*!
	Maps identifiers to global memory allocations.
*/
void executive::EmulatedKernel::initializeGlobalMemory() {
	using namespace std;
	if (module == 0) {
		return;
	}

	report("Initializing global variables for kernel " << name);

	unordered_set<string> global;
	
	ir::Module::GlobalMap::const_iterator it = module->globals.begin();
	for (; it != module->globals.end(); ++it) {
		if (it->second.statement.directive == ir::PTXStatement::Global) {
			assert(it->second.registered || it->second.local);
			report(" Found global variable " << it->second.statement.name);
			global.insert(it->second.statement.name);
		}
	}

	// now visit every instruction and change the address mode from label to immediate, and assign
	// the offset as an immediate value 
	PTXOperand PTXInstruction:: *operands[] = {
		&PTXInstruction::d, &PTXInstruction::a, &PTXInstruction::b, 
		&PTXInstruction::c };
	vector<PTXInstruction>::iterator i_it = KernelInstructions.begin();
	for (; i_it != KernelInstructions.end(); ++i_it) {
		PTXInstruction &instr = *i_it;

		// look for mov instructions or ld/st instruction
		if (instr.opcode == PTXInstruction::Mov) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode == PTXOperand::Address) {
					unordered_set<string>::iterator 
						l_it = global.find((instr.*operands[n]).identifier);
					if (global.end() != l_it) {
						(instr.*operands[n]).type = PTXOperand::u64;
						ir::Module::GlobalMap::const_iterator 
							g_it = module->globals.find(*l_it);
						assert(g_it != module->globals.end());
						(instr.*operands[n]).imm_uint = 
							(PTXU64)g_it->second.pointer;
						report("Mapping global label " 
							<< (instr.*operands[n]).identifier << " to " 
							<< (instr.*operands[n]).imm_uint 
							<< " for instruction " << instr.toString() );
					}
				}
			}
		}
		else if ( instr.opcode == PTXInstruction::Ld 
			|| instr.opcode == PTXInstruction::St ) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode == PTXOperand::Address) {
					unordered_set<string>::iterator 
						l_it = global.find((instr.*operands[n]).identifier);
					if (global.end() != l_it) {
						(instr.*operands[n]).type = PTXOperand::u64;
						ir::Module::GlobalMap::const_iterator 
							g_it = module->globals.find(*l_it);
						assert(g_it != module->globals.end());
						(instr.*operands[n]).imm_uint = 
							(PTXU64)g_it->second.pointer;
						report("Mapping ld/st global label " 
							<< (instr.*operands[n]).identifier << " to " 
							<< (instr.*operands[n]).imm_uint
							<< " for instruction " << instr.toString() );
					}
				}
			}
		}
	}
}

void executive::EmulatedKernel::initializeTextureMemory( ) {
	typedef std::unordered_map<std::string, unsigned int> IndexMap;
	if (module == 0) {
		return;
	}
	report("Initializing texture variables for kernel " << name);
	textures.clear();
	IndexMap indicies;
	unsigned int next = 0;
	for (std::vector< ir::PTXInstruction >::iterator 
		fi = KernelInstructions.begin(); 
		fi != KernelInstructions.end(); ++fi) {
		if (fi->opcode == ir::PTXInstruction::Tex) {
			ir::Module::TextureMap::const_iterator 
				texture = module->textures.find(fi->a.identifier);
			assert(texture != module->textures.end());
			IndexMap::iterator index = indicies.find(fi->a.identifier);
			if (index == indicies.end()) {
				index = indicies.insert(
					std::make_pair(fi->a.identifier,next++)).first;
				textures.push_back(&texture->second);
			}
			fi->a.reg = index->second;
		}
	}
}

void executive::EmulatedKernel::updateGlobals() {
	initializeConstMemory();
	initializeGlobalMemory();
}

std::string executive::EmulatedKernel::toString() const {
	std::stringstream stream;
	stream << "Kernel " << name << "\n";
	for( std::vector< ir::PTXInstruction >::const_iterator 
		fi = KernelInstructions.begin(); 
		fi != KernelInstructions.end(); ++fi ) {
		const PTXInstruction &instr = *fi;
		stream << "[PC " << fi - KernelInstructions.begin() << "] " << 
			fi->toString();
		if (instr.opcode == PTXInstruction::Bra) {
			stream << " [target: " << instr.branchTargetInstruction 
				<< ", reconverge: " << instr.reconvergeInstruction << "]";
		}
		stream << "\n";
	}
	return stream.str();
}
//////////////////////////////////////////////////////////////////////////////////////////////////

