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
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PostdominatorTree.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/Executive.h>
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

executive::EmulatedKernel::EmulatedKernel(ir::Kernel* kernel, 
	const Executive* c) : ExecutableKernel(*kernel, c) {
	assertM( kernel->ISA == ir::Instruction::PTX, 
		"Can only build an emulated kernel from a PTXKernel." );
	
	ir::PTXKernel& ptxKernel = static_cast< ir::PTXKernel& >(*kernel);
	
	ConstMemory = ParameterMemory = 0;
	ConstMemorySize = ParameterMemorySize = SharedMemorySize = 0;

	ISA = ir::Instruction::Emulated;
	initialize(ptxKernel.instructions);
}

executive::EmulatedKernel::EmulatedKernel() {
	ISA = ir::Instruction::Emulated;
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

	gridDim = Dim3(width, height, 1);	
	
	updateParameterMemory();
	updateGlobals();
	
	// notify trace generator(s)
	for (std::list<trace::TraceGenerator*>::iterator it = Traces.begin(); 
		it != Traces.end(); ++it) {
		(*it)->initialize(this);
	}

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
	
			Dim3 block(x,y,0);
			CooperativeThreadArray cta(this);

			cta.initialize( gridDim, !Traces.empty() );

			cta.execute(block);
		}
	}
	
	// notify trace generator(s)
	for (std::list<trace::TraceGenerator*>::iterator it = Traces.begin(); 
		it != Traces.end(); ++it) {
		(*it)->finish();
	}

}

/*!
	Sets the shape of a kernel
*/
void executive::EmulatedKernel::setKernelShape(int x, int y, int z) {
	blockDim.x = x;
	blockDim.y = y;
	blockDim.z = z;

	threadCount = x*y*z;
}

void executive::EmulatedKernel::setDevice(const Device* device,
	unsigned int limit) {
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
void executive::EmulatedKernel::initialize(
	PTXKernel::PTXInstructionVector& instructions) {
	constructInstructionSequence(instructions);
	registerAllocation();
	initializeSharedMemory();
	initializeParameterMemory();
	updateParamReferences();
	initializeLocalMemory();
}

void executive::EmulatedKernel::configureParameters() {

}

/*!
	Produces a packed vector of instructions, updates each operand, and changes labels
	to indices.
*/
void executive::EmulatedKernel::constructInstructionSequence(
	PTXKernel::PTXInstructionVector& instructions) {
	using namespace std;
	report("Constructing instruction sequence.");

	// visit basic blocks and add reconverge instructions
	ir::ControlFlowGraph::BlockPointerVector 
		bb_sequence = cfg()->executable_sequence();
	ir::ControlFlowGraph::BlockPointerVector::iterator 
		bb_it = bb_sequence.begin();

	for (; bb_it != bb_sequence.end(); ++bb_it) {
		ir::BasicBlock::InstructionList::iterator 
			i_it = (*bb_it)->instructions.begin();
		for (; i_it != (*bb_it)->instructions.end(); ++i_it) {
			PTXInstruction &ptx_instr = instructions[*i_it];
			if (ptx_instr.opcode == PTXInstruction::Bra && !ptx_instr.uni) {
				// find post-dominator and insert reconverge instruction into head if one does not
				// already exist

				BasicBlock *pdom = pdom_tree()->getPostDominator(*bb_it);

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
			label_to_instruction[(*bb_it)->label] 
				= (int)KernelInstructions.size();
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
	for (ir::PTXKernel::PTXInstructionVector::iterator 
		i_it = KernelInstructions.begin();
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
		//align parameter memory
		unsigned int padding = i_it->getAlignment() 
			- ( ParameterMemorySize % i_it->getAlignment() );
		padding = (i_it->getAlignment() == padding) ? 0 : padding;
		ParameterMemorySize += padding;
		i_it->offset = ParameterMemorySize;
		ParameterMemorySize += i_it->getSize();
	}	
}

bool executive::EmulatedKernel::checkMemoryAccess(const void* base, 
	size_t size) const {
	if(context == 0) return false;
	return context->checkMemoryAccess(context->getSelectedDevice(), base, size);
}

void executive::EmulatedKernel::updateParameterMemory() {
	using namespace std;

	if(ParameterMemory != 0) {
		delete[] ParameterMemory;
	}
	
	ParameterMemory = new char[ParameterMemorySize];
	
	report("EmulatedKernel::updateParameterMemory()");
	
	unsigned int size = 0;
	for(std::vector<ir::Parameter>::iterator i_it = parameters.begin();
		i_it != parameters.end(); ++i_it ) {
		unsigned int padding = i_it->getAlignment()
			- ( size % i_it->getAlignment() );
		padding = (i_it->getAlignment() == padding) ? 0 : padding;
		size += padding;
		for(ir::Parameter::ValueVector::iterator 
			v_it = i_it->arrayValues.begin(); 
			v_it != i_it->arrayValues.end(); ++v_it) {
			assert( size < ParameterMemorySize );
			memcpy( ParameterMemory + size, &v_it->val_b16, 
				i_it->getElementSize() );
			size += i_it->getElementSize();
			
			report("  " << ir::Parameter::value(*i_it));
		}
	}	

}

/*!
	On construction, allocates registers by computing live ranges
	This assumes that the PTX compiler did a good job at register allocation
*/
void executive::EmulatedKernel::registerAllocation() {
	using namespace std;
	report("Allocating registers");
	registerMap = ir::PTXKernel::assignRegisters( KernelInstructions );
	_registerCount = RegisterCount = (int)registerMap.size();
	_maxThreadsPerBlock = 512;
}

void executive::EmulatedKernel::_computeOffset(
	const PTXStatement& statement, unsigned int& offset, 
	unsigned int& totalOffset) {
	
	unsigned int padding = statement.accessAlignment() - 
		(totalOffset % statement.accessAlignment());
	padding = ( padding == (unsigned int) statement.accessAlignment() ) 
		? 0 : padding;
	offset = totalOffset + padding;

	totalOffset = offset;
	if(statement.array.stride.empty()) {
		totalOffset += statement.array.vec * 
			ir::PTXOperand::bytes(statement.type);
	}
	else {
		for (int i = 0; i < (int)statement.array.stride.size(); i++) {
			totalOffset += statement.array.stride[i] * statement.array.vec * 
				ir::PTXOperand::bytes(statement.type);
		}
	}
}

/*!
	Allocates arrays in shared memory and maps identifiers to allocations.
*/
void executive::EmulatedKernel::initializeSharedMemory() {
	using namespace std;
	typedef unordered_map<string, unsigned int> Map;
	typedef unordered_map<std::string, 
		ir::Module::GlobalMap::const_iterator> GlobalMap;
	typedef unordered_set<std::string> StringSet;
	typedef std::deque<PTXOperand*> OperandVector;
	unsigned int sharedOffset = 0;
	unsigned int externalAlignment = 1;

	report( "Initializing shared memory for kernel " << name );
	Map label_map;
	GlobalMap sharedGlobals;
	StringSet external;
	OperandVector externalOperands;
	
	if(module != 0) {
		for(ir::Module::GlobalMap::const_iterator it = module->globals.begin(); 
			it != module->globals.end(); ++it) {
			if (it->second.statement.directive == PTXStatement::Shared) {
				if(it->second.statement.attribute == PTXStatement::Extern) {
					report("Found global external shared variable " 
						<< it->second.statement.name);
					assert(external.count(it->second.statement.name) == 0);
					external.insert(it->second.statement.name);
					externalAlignment = std::max( externalAlignment, 
						(unsigned int) it->second.statement.accessAlignment() );
					externalAlignment = std::max( externalAlignment, 
						ir::PTXOperand::bytes( it->second.statement.type ) );
				} 
				else {
					report("Found global shared variable " 
						<< it->second.statement.name);
					sharedGlobals.insert( std::make_pair( 
						it->second.statement.name, it ) );
				}
			}
		}
	}
	
	LocalMap::const_iterator it = locals.begin();
	for (; it != locals.end(); ++it) {
		if (it->second.space == PTXInstruction::Shared) {
			if(it->second.attribute == PTXStatement::Extern) {
				report("Found local external shared variable " 
					<< it->second.name);
				assert(external.count(it->second.name) == 0);
					external.insert(it->second.name);
				externalAlignment = std::max( externalAlignment, 
					(unsigned int) it->second.getAlignment() );
				externalAlignment = std::max( externalAlignment, 
					ir::PTXOperand::bytes( it->second.type ) );
			}
			else {
				unsigned int offset;

				_computeOffset(it->second.statement(), offset, sharedOffset);
				label_map[it->second.name] = offset;
				report("Found local shared variable " << it->second.name 
					<< " at offset " << offset << " with alignment " 
					<< it->second.getAlignment() << " of size " 
					<< (sharedOffset - offset ));
			}
		}
	}

	// now visit every instruction and change the address mode from 
	// label to immediate, and assign the offset as an immediate value 
	PTXOperand PTXInstruction:: *operands[] = { &PTXInstruction::d,
		&PTXInstruction::a, &PTXInstruction::b, &PTXInstruction::c
	};
	ir::PTXKernel::PTXInstructionVector::iterator 
		i_it = KernelInstructions.begin();
	for (; i_it != KernelInstructions.end(); ++i_it) {
		PTXInstruction &instr = *i_it;

		// look for mov and ld/st instructions
		if (instr.opcode == PTXInstruction::Mov) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode == PTXOperand::Address) {
					StringSet::iterator si = external.find(
						(instr.*operands[n]).identifier);
					if (si != external.end()) {
						externalOperands.push_back(&(instr.*operands[n]));
						continue;
					}
					
					GlobalMap::iterator gi = sharedGlobals.find(
							(instr.*operands[n]).identifier);
					if (gi != sharedGlobals.end()) {
						ir::Module::GlobalMap::const_iterator 
							it = gi->second;
						sharedGlobals.erase(gi);
						unsigned int offset;

						report("Found global shared variable " 
							<< it->second.statement.name);
						_computeOffset(it->second.statement, 
							offset, sharedOffset);						
						label_map[it->second.statement.name] = offset;
					}
					
					Map::iterator l_it 
						= label_map.find((instr.*operands[n]).identifier);
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
					StringSet::iterator si = external.find(
						(instr.*operands[n]).identifier);
					if (si != external.end()) {
						externalOperands.push_back(&(instr.*operands[n]));
						continue;
					}
					
					GlobalMap::iterator gi = sharedGlobals.find(
							(instr.*operands[n]).identifier);
					if (gi != sharedGlobals.end()) {
						ir::Module::GlobalMap::const_iterator it = gi->second;
						sharedGlobals.erase(gi);
						unsigned int offset;

						report("Found global shared variable " 
							<< it->second.statement.name);
						_computeOffset(it->second.statement, 
							offset, sharedOffset);						
						label_map[it->second.statement.name] = offset;
					}
					
					Map::iterator l_it 
						= label_map.find((instr.*operands[n]).identifier);
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
	
	// compute necessary padding for alignment of external shared memory
	unsigned int padding = externalAlignment 
		- ( sharedOffset % externalAlignment );
	padding = ( padding == externalAlignment ) ? 0 : padding;
	sharedOffset += padding;

	report( "Padding shared memory by " << padding << " bytes to handle " 
		<< externalAlignment << " byte alignment requirement." );
		
	for (OperandVector::iterator operand = externalOperands.begin(); 
		operand != externalOperands.end(); ++operand) {
		report( "Mapping external shared label " << (*operand)->identifier 
			<< " to " << sharedOffset );
		(*operand)->type = PTXOperand::u64;
		(*operand)->imm_uint = sharedOffset;
	}

	// allocate shared memory object
	_sharedMemorySize = SharedMemorySize = sharedOffset;
	
	report("Total shared memory size is " << SharedMemorySize);
}

void executive::EmulatedKernel::setSharedMemorySize(size_t bytes) {
	_sharedMemorySize = SharedMemorySize = bytes;
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
				unsigned int offset;

				report("Found global local variable " 
					<< it->second.statement.name);
				_computeOffset(it->second.statement, 
					offset, localOffset);						
				label_map[it->second.statement.name] = offset;
			}
		}
	}
	
	LocalMap::const_iterator it = locals.begin();
	for (; it != locals.end(); ++it) {
		if (it->second.space == ir::PTXInstruction::Local) {
			unsigned int offset;

			report("Found local local variable " 
				<< it->second.name);
			_computeOffset(it->second.statement(), 
				offset, localOffset);						
			label_map[it->second.name] = offset;
		}
	}

	// now visit every instruction and change the address mode from label to immediate, and assign
	// the offset as an immediate value 
	PTXOperand PTXInstruction:: *operands[] = { &PTXInstruction::d,
		&PTXInstruction::a, &PTXInstruction::b, &PTXInstruction::c
	};
	ir::PTXKernel::PTXInstructionVector::iterator 
		i_it = KernelInstructions.begin();
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
	_localMemorySize = LocalMemorySize = localOffset;
	
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
			unsigned int offset;

			report("Found global const variable " 
				<< it->second.statement.name);
			_computeOffset(it->second.statement, 
				offset, constantOffset);						
			constant[it->second.statement.name] = offset;
		}
	}
	
	report( "Total constant memory size is " << constantOffset );

	// now visit every instruction and change the address mode from label to immediate, and assign
	// the offset as an immediate value 
	PTXOperand PTXInstruction:: *operands[] = {
		&PTXInstruction::d, &PTXInstruction::a, &PTXInstruction::b, 
		&PTXInstruction::c
	};
	ir::PTXKernel::PTXInstructionVector::iterator 
		i_it = KernelInstructions.begin();
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
	
	_constMemorySize = ConstMemorySize = constantOffset;
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

	// now visit every instruction and change the address mode from label 
	// to immediate, and assign the offset as an immediate value 
	PTXOperand PTXInstruction:: *operands[] = {
		&PTXInstruction::d, &PTXInstruction::a, &PTXInstruction::b, 
		&PTXInstruction::c };
	ir::PTXKernel::PTXInstructionVector::iterator 
		i_it = KernelInstructions.begin();
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

void executive::EmulatedKernel::initializeTextureMemory() {
	typedef std::unordered_map<std::string, unsigned int> IndexMap;
	if (module == 0) {
		return;
	}
	report("Initializing texture variables for kernel " << name);
	textures.clear();
	IndexMap indicies;
	unsigned int next = 0;
	for (ir::PTXKernel::PTXInstructionVector::iterator 
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
	for( ir::PTXKernel::PTXInstructionVector::const_iterator 
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

std::string executive::EmulatedKernel::fileName() const {
	assert(module != 0);
	return module->modulePath;
}

std::string executive::EmulatedKernel::location( unsigned int PC ) const {
	assert(module != 0 );
	assert(PC < KernelInstructions.size());
	unsigned int statement = KernelInstructions[PC].statementIndex;
	ir::Module::StatementVector::const_iterator s_it 
		= module->statements.begin();
	std::advance(s_it, statement);
	ir::Module::StatementVector::const_reverse_iterator s_rit 
		= ir::Module::StatementVector::const_reverse_iterator(s_it);
	unsigned int program = 0;
	unsigned int line = 0;
	unsigned int col = 0;
	for ( ; s_rit != module->statements.rend(); ++s_rit) {
		if (s_rit->directive == ir::PTXStatement::Loc) {
			line = s_rit->sourceLine;
			col = s_rit->sourceColumn;
			program = s_rit->sourceFile;
			break;
		}
	}
	
	std::string fileName;
	for ( s_it = module->statements.begin(); 
		s_it != module->statements.end(); ++s_it ) {
		if (s_it->directive == ir::PTXStatement::File) {
			if (s_it->sourceFile == program) {
				fileName = s_it->name;
				break;
			}
		}
	}
	
	std::stringstream stream;
	stream << fileName << ":" << line << ":" << col;
	return stream.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

