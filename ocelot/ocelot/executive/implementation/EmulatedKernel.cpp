/*! \file EmulatedKernel.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 19, 2009
	\brief implements the Kernel base class
*/

// C++ includes
#include <assert.h>
#include <math.h>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <cstring>

// Ocelot includes
#include <ocelot/ir/interface/Parameter.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/DominatorTree.h>
#include <ocelot/ir/interface/PostdominatorTree.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/executive/interface/RuntimeException.h>
#include <ocelot/executive/interface/CooperativeThreadArray.h>
#include <ocelot/ir/interface/HammockGraph.h>
#include <ocelot/trace/interface/TraceGenerator.h>

// Hydrazine includes
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define REPORT_KERNEL_INSTRUCTIONS 0
#define REPORT_LAUNCH_CONFIGURATION 0
#define REPORT_THREAD_FRONTIERS 1

#define IPDOM_RECONVERGENCE 1
#define BARRIER_RECONVERGENCE 2
#define GEN6_RECONVERGENCE 3
#define SORTED_PREDICATE_STACK_RECONVERGENCE 4

// specify reconvergence mechanism here
#define RECONVERGENCE_MECHANISM IPDOM_RECONVERGENCE

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::EmulatedKernel::EmulatedKernel(
	ir::Kernel* kernel, 
	Device* d, 
	bool _initialize) 
: 
	ExecutableKernel(*kernel, d),
	CTA(0)
{
	report("Created emulated kernel " << name);
	assertM(kernel->ISA == ir::Instruction::PTX, 
		"Can only build an emulated kernel from a PTXKernel.");
	
	ISA = ir::Instruction::Emulated;
	ConstMemory = ParameterMemory = 0;
	if (_initialize) {
		initialize();
	}
}

executive::EmulatedKernel::EmulatedKernel(
	Device* d): ExecutableKernel(d), CTA(0) {
	ISA = ir::Instruction::Emulated;
}

executive::EmulatedKernel::EmulatedKernel(): CTA(0) {
	ISA = ir::Instruction::Emulated;
}

executive::EmulatedKernel::~EmulatedKernel() {
	freeAll();
}

bool executive::EmulatedKernel::executable() {
	report("EmulatedKernel::executable() returns true");
	return true;
}

void executive::EmulatedKernel::launchGrid(int width, int height) {
	report("EmulatedKernel::launchGrid called for " << name);
	report("  " << _registerCount << " registers");

	_gridDim = ir::Dim3(width, height, 1);	
	
	// notify trace generator(s)
	for (TraceGeneratorVector::iterator it = _generators.begin(); 
		it != _generators.end(); ++it) {
		(*it)->initialize(*this);
	}

#if REPORT_LAUNCH_CONFIGURATION == 1
	report("EmulatedKernel::launchGrid(" << width << ", " << height << ")");
	report("  kernel: " << name);
	report("  const:  " << constMemorySize() << " bytes");
	report("  local:  " << localMemorySize() << " bytes");
	report("  static shared: " << sharedMemorySize() << " bytes");
	report("  extern shared: " << externSharedMemorySize() << " bytes");
	report("  total shared:  " << totalSharedMemorySize() << " bytes");
	report("  param: " << parameterMemorySize() << " bytes");
	report("  max threads: " << maxThreadsPerBlock() << " threads per block");
	report("  registers: " << registerCount() << " registers");
	report("  grid: " << gridDim().x << ", " << gridDim().y << ", " << gridDim().z);
	report("  block: " << blockDim().x << ", " << blockDim().y << ", " << blockDim().z);
#endif

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			ir::Dim3 block(x,y,0);
			CooperativeThreadArray cta(this);

			CTA = &cta;
			cta.initialize( _gridDim, !_generators.empty() );
			cta.execute(block);
		}
	}
	
	// notify trace generator(s)
	for (TraceGeneratorVector::iterator it = _generators.begin(); 
		it != _generators.end(); ++it) {
		(*it)->finish();
	}
	CTA = 0;
}

void executive::EmulatedKernel::setKernelShape(int x, int y, int z) {
	_blockDim.x = x;
	_blockDim.y = y;
	_blockDim.z = z;
}

ir::Dim3 executive::EmulatedKernel::getKernelShape() const {
	return _blockDim;
}

void executive::EmulatedKernel::setExternSharedMemorySize(unsigned int bytes) {
	report("Setting external shared memory size to " << bytes);
	_externSharedMemorySize = bytes;
}

void executive::EmulatedKernel::setWorkerThreads(unsigned int limit) {
}

void executive::EmulatedKernel::addTraceGenerator(
	trace::TraceGenerator *generator) {
	_generators.push_back(generator);
}

void executive::EmulatedKernel::removeTraceGenerator(
	trace::TraceGenerator *generator) {
	TraceGeneratorVector temp = std::move(_generators);
	for (TraceGeneratorVector::iterator gi = temp.begin(); 
		gi != temp.end(); ++gi) {
		if (*gi != generator) {
			_generators.push_back(*gi);
		}
	}
}

void executive::EmulatedKernel::freeAll() {
	delete [] ConstMemory;
	delete [] ParameterMemory;
	ParameterMemory = ConstMemory = 0;
}

void executive::EmulatedKernel::initialize() {
	registerAllocation();
	constructInstructionSequence();
	initializeTextureMemory();
	initializeSharedMemory();
	initializeParameterMemory();
	updateParamReferences();
	initializeLocalMemory();
}

class DotFormatterBlockLabel : public ir::BasicBlock::DotFormatter {
public:

	DotFormatterBlockLabel() { }
	~DotFormatterBlockLabel() { }

	/*!	\brief prints string representation of */
	std::string toString(const ir::BasicBlock *block) {
	std::stringstream out;

	out << "[shape=record,";
	out << "label=";
	out << "\"{" << hydrazine::toGraphVizParsableLabel(block->label);
	out << "}\"]";

	return out.str();
	}
};

void executive::EmulatedKernel::constructInstructionSequence() {
	typedef std::unordered_map<ir::ControlFlowGraph::InstructionList::iterator, 
		ir::ControlFlowGraph::InstructionList::iterator > InstructionMap;
	typedef std::unordered_map<ir::ControlFlowGraph::InstructionList::iterator,
		unsigned int> InstructionIdMap;
	typedef std::unordered_map<ir::ControlFlowGraph::InstructionList::iterator,
		ir::ControlFlowGraph::iterator> ReconvergeToBlockMap;
	report("Constructing emulated instruction sequence.");

	// visit basic blocks and add reconverge instructions
	ir::ControlFlowGraph::BlockPointerVector bb_sequence = cfg()->executable_sequence();
	
	InstructionMap reconvergeTargets;
	ReconvergeToBlockMap reconvergeSources;
	
	threadFrontiers.clear();
	
	report(" Adding reconverge instructions");
	// Create reconverge instructions
	for (ir::ControlFlowGraph::pointer_iterator bb_it = bb_sequence.begin(); 
		bb_it != bb_sequence.end(); ++bb_it) {
#if RECONVERGENCE_MECHANISM == IPDOM_RECONVERGENCE
		ir::ControlFlowGraph::InstructionList::iterator 
			i_it = (*bb_it)->instructions.begin();
		for (; i_it != (*bb_it)->instructions.end(); ++i_it) {

			ir::PTXInstruction &ptx_instr = static_cast<
				ir::PTXInstruction&>(**i_it);
			if (ptx_instr.opcode == ir::PTXInstruction::Bra && !ptx_instr.uni) {
				ir::ControlFlowGraph::iterator 
					pdom = pdom_tree()->getPostDominator(*bb_it);

				// only add a new reconverge point if all other reconverge 
				// points originate from branches that dominate this branch
				bool allDominate = true;
				ir::ControlFlowGraph::InstructionList::iterator 
					reconverge = pdom->instructions.begin();
				for ( ; reconverge != pdom->instructions.end(); ++reconverge) {
					ir::PTXInstruction& ptx = static_cast<
						ir::PTXInstruction&>(**reconverge);
					if (ptx.opcode != ir::PTXInstruction::Reconverge) {
						break;
					}
					
					if( !dom_tree()->dominates(
						reconvergeSources[reconverge], *bb_it) ) {
						allDominate = false;
						break;
					}
				}
				
				if (allDominate) {
					pdom->instructions.push_front(ir::PTXInstruction(
						ir::PTXInstruction::Reconverge).clone());
					report( "  Getting post dominator block " << pdom->label 
						<< " of instruction " << ptx_instr.toString() );
					reconvergeTargets.insert(std::make_pair(i_it, 
						pdom->instructions.begin()));
					reconvergeSources.insert(std::make_pair(
						pdom->instructions.begin(), *bb_it));
				}
				else {
					reconvergeTargets.insert(std::make_pair(i_it, reconverge));
				}
			}
		}
		
#elif RECONVERGENCE_MECHANISM == SORTED_PREDICATE_STACK_RECONVERGENCE
		// every basic block with multiple predecessors gets a reconverge instruction
		if ((*bb_it)->predecessors.size() > 1) {
			report("inserted reconverge into " << (*bb_it)->label);
			(*bb_it)->instructions.push_back(ir::PTXInstruction(ir::PTXInstruction::Reconverge).clone());
		}
#endif
	}

	InstructionIdMap ids;

	report(" Packing instructions into a vector");
	size_t lastPC = 0;
	for (ir::ControlFlowGraph::pointer_iterator bb_it = bb_sequence.begin(); 
		bb_it != bb_sequence.end(); ++bb_it) {
		branchTargetsToBlock[(int)instructions.size()] = (*bb_it)->label;
		int n = 0;
		blockPCRange[(*bb_it)->label].first = (int)instructions.size();
		for (ir::ControlFlowGraph::InstructionList::iterator 
			i_it = (*bb_it)->instructions.begin(); 
			i_it != (*bb_it)->instructions.end(); ++i_it, ++n) {
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**i_it);
			if (ptx.opcode == ir::PTXInstruction::Reconverge 
				|| i_it == (*bb_it)->instructions.begin()) {
				ids.insert(std::make_pair(i_it, instructions.size()));
			}
			ptx.pc = instructions.size();
#if REPORT_KERNEL_INSTRUCTIONS
			report("  pc " << ptx.pc << ": " << ptx.toString() );
#endif
			lastPC = ptx.pc;
			if (!n) { basicBlockPC[ptx.pc] = (*bb_it)->label; }
			instructions.push_back(ptx);
		}
		blockPCRange[(*bb_it)->label].second = (int)lastPC;
		
		report("  blockPCRange[" << (*bb_it)->label << "] = " << lastPC);
		
		// trivial TF
		threadFrontiers[(int)lastPC] = std::make_pair<int,int>((int)lastPC+1, (int)lastPC+1);

		if (n) {
			basicBlockMap[lastPC] = (*bb_it)->label;
		}
	}


	std::set< int > targets;	// set of branch targets

	report( "\n\n    Updating branch targets and reconverge points" );
	unsigned int id = 0;
	for (ir::ControlFlowGraph::pointer_iterator bb_it = bb_sequence.begin();
		bb_it != bb_sequence.end(); ++bb_it) {
		for (ir::ControlFlowGraph::InstructionList::iterator 
			i_it = (*bb_it)->instructions.begin(); 
			i_it != (*bb_it)->instructions.end(); ++i_it, ++id) {
			ir::PTXInstruction& ptx = static_cast<ir::PTXInstruction&>(**i_it);				
			
			// thread frontier algorithm
			std::pair<int,int> blockRange = blockPCRange[(*bb_it)->label];
			std::set< int >::iterator target_it = targets.find(blockRange.first);
			if (target_it != targets.end()) {
				targets.erase(target_it);
			}
				
			if (ptx.opcode == ir::PTXInstruction::Bra) {
#if RECONVERGENCE_MECHANISM == IPDOM_RECONVERGENCE
				//report( "  Instruction " << ptx.toString() );
				if (!ptx.uni) {
					InstructionMap::iterator 
						reconverge = reconvergeTargets.find(i_it);
					assert(reconverge != reconvergeTargets.end());
					InstructionIdMap::iterator 
						target = ids.find(reconverge->second);
					assert(target != ids.end());
					instructions[id].reconvergeInstruction = target->second;
					//report("   reconverge at " << target->second);
				}
#endif
				
				InstructionIdMap::iterator branch = ids.find(
					(*bb_it)->get_branch_edge()->tail->instructions.begin());
				assert(branch != ids.end());
				instructions[id].branchTargetInstruction = branch->second;
				//report("   target at " << branch->second);

				int successors[2] = { instructions[id].branchTargetInstruction, blockPCRange[(*bb_it)->label].second + 1 };
				
				if (targets.size()) {
					threadFrontiers[blockRange.second].first = *std::min_element(targets.begin(), targets.end()) ; // min of targets
					threadFrontiers[blockRange.second].second = *std::max_element(targets.begin(), targets.end()) ; // max of targets
#if REPORT_THREAD_FRONTIERS == 1
					report("  frontier: " << threadFrontiers[blockRange.second].first << " - "
						<< threadFrontiers[blockRange.second].second << "\n");
#endif
				}
				
				for (int i = 0; i < 2; i++) {
					if (successors[i] > blockRange.first) {
						targets.insert(successors[i]);
					}
				}
			}
		}
	}
	
}

/*!
	After emitting the instruction sequence, visit each memory move operation 
	and replace references to parameters with offsets into parameter memory.

	Data movement instructions: ld, st
*/
void executive::EmulatedKernel::updateParamReferences() {
	using namespace std;
	for (PTXInstructionVector::iterator 
		i_it = instructions.begin();
		i_it != instructions.end(); ++i_it) {
		ir::PTXInstruction & instr = *i_it;
		if (instr.addressSpace == ir::PTXInstruction::Param 
			&& instr.a.addressMode == ir::PTXOperand::Address) {
			if (instr.opcode == ir::PTXInstruction::Ld
				|| instr.opcode == ir::PTXInstruction::St) {
				ir::Parameter* param = getParameter(instr.a.identifier);
				instr.a.offset += param->offset;
				instr.a.imm_uint = 0;
			}
		}
	}
}

void executive::EmulatedKernel::initializeParameterMemory() {
	report( "Initializing parameter memory for kernel " << name );
	delete[] ParameterMemory;
	ParameterMemory = 0;
	_parameterMemorySize = 0;
	for(ParameterVector::iterator i_it = parameters.begin();
		i_it != parameters.end(); ++i_it ) {
		report( " Initializing memory for paramter " << i_it->name 
			<< " of size " << i_it->getSize() );
		//align parameter memory
		unsigned int padding = i_it->getAlignment() 
			- ( _parameterMemorySize % i_it->getAlignment() );
		padding = (i_it->getAlignment() == padding) ? 0 : padding;
		_parameterMemorySize += padding;
		i_it->offset = _parameterMemorySize;
		_parameterMemorySize += i_it->getSize();
	}	
}

bool executive::EmulatedKernel::checkMemoryAccess(const void* base, 
	size_t size) const {
	if(device == 0) return false;
	return device->checkMemoryAccess(base, size);
}

void executive::EmulatedKernel::updateParameterMemory() {
	using namespace std;

	delete[] ParameterMemory;	
	ParameterMemory = new char[_parameterMemorySize];
	
	unsigned int size = 0;
	for(ParameterVector::iterator i_it = parameters.begin();
		i_it != parameters.end(); ++i_it ) {
		unsigned int padding = i_it->getAlignment()
			- ( size % i_it->getAlignment() );
		padding = (i_it->getAlignment() == padding) ? 0 : padding;
		size += padding;
		for(ir::Parameter::ValueVector::iterator 
			v_it = i_it->arrayValues.begin(); 
			v_it != i_it->arrayValues.end(); ++v_it) {
			assert( size < _parameterMemorySize );
			memcpy( ParameterMemory + size, &v_it->val_b16, 
				i_it->getElementSize() );
			size += i_it->getElementSize();
		}
	}	

}

void executive::EmulatedKernel::updateMemory() {
	updateGlobals();
}

executive::ExecutableKernel::TextureVector 
	executive::EmulatedKernel::textureReferences() const {
	return textures;
}


void executive::EmulatedKernel::registerAllocation() {
	using namespace std;
	report("Allocating registers");
	registerMap = ir::PTXKernel::assignRegisters( *cfg() );
	_registerCount = registerMap.size();
	report(" Allocated " << _registerCount << " registers");
}

void executive::EmulatedKernel::_computeOffset(
	const ir::PTXStatement& statement, unsigned int& offset, 
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
	typedef std::unordered_map<string, unsigned int> Map;
	typedef std::unordered_map<std::string, 
		ir::Module::GlobalMap::const_iterator> GlobalMap;
	typedef std::
	unordered_set<std::string> StringSet;
	typedef std::deque<ir::PTXOperand*> OperandVector;
	unsigned int sharedOffset = 0;
	unsigned int externalAlignment = 1;

	report( "Initializing shared memory for kernel " << name );
	Map label_map;
	GlobalMap sharedGlobals;
	StringSet external;
	OperandVector externalOperands;
	
	if(module != 0) {
		for(ir::Module::GlobalMap::const_iterator 
			it = module->globals().begin(); 
			it != module->globals().end(); ++it) {
			if (it->second.statement.directive == ir::PTXStatement::Shared) {
				if(it->second.statement.attribute == ir::PTXStatement::Extern) {
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
		if (it->second.space == ir::PTXInstruction::Shared) {
			if(it->second.attribute == ir::PTXStatement::Extern) {
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
	ir::PTXOperand ir::PTXInstruction:: *operands[] = { &ir::PTXInstruction::d,
		&ir::PTXInstruction::a, &ir::PTXInstruction::b, &ir::PTXInstruction::c
	};
	PTXInstructionVector::iterator 
		i_it = instructions.begin();
	for (; i_it != instructions.end(); ++i_it) {
		ir::PTXInstruction &instr = *i_it;

		// look for mov and ld/st instructions
		if (instr.opcode == ir::PTXInstruction::Mov
			|| instr.opcode == ir::PTXInstruction::Ld 
			|| instr.opcode == ir::PTXInstruction::St
			|| instr.opcode == ir::PTXInstruction::Atom) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode 
					== ir::PTXOperand::Address) {
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
						(instr.*operands[n]).type = ir::PTXOperand::u64;
						(instr.*operands[n]).imm_uint = l_it->second;
						report("For instruction " << instr.toString() 
							<< ", mapping shared label " << l_it->first 
							<< " to " << l_it->second);
					}
				}
			}
		}
	}
	
	// compute necessary padding for alignment of external shared memory
	unsigned int padding = externalAlignment 
		- (sharedOffset % externalAlignment);
	padding = (padding == externalAlignment) ? 0 : padding;
	sharedOffset += padding;

	report("Padding shared memory by " << padding << " bytes to handle " 
		<< externalAlignment << " byte alignment requirement.");
		
	for (OperandVector::iterator operand = externalOperands.begin(); 
		operand != externalOperands.end(); ++operand) {
		report( "Mapping external shared label " << (*operand)->identifier 
			<< " to " << sharedOffset );
		(*operand)->type = ir::PTXOperand::u64;
		(*operand)->imm_uint = sharedOffset;
	}

	// allocate shared memory object
	_sharedMemorySize = sharedOffset;
	
	report("Total shared memory size is " << _sharedMemorySize);
}

/*!
	Allocates arrays in local memory and maps identifiers to allocations.
*/
void executive::EmulatedKernel::initializeLocalMemory() {
	using namespace std;

	unsigned int localOffset = 0;

	map<string, unsigned int> label_map;
	
	if(module != 0) {
		for(ir::Module::GlobalMap::const_iterator 
			it = module->globals().begin(); 
			it != module->globals().end(); ++it) {
			if (it->second.statement.directive == ir::PTXStatement::Local) {
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

	ir::PTXOperand ir::PTXInstruction:: *operands[] = {&ir::PTXInstruction::d,
		&ir::PTXInstruction::a, &ir::PTXInstruction::b, &ir::PTXInstruction::c};
	PTXInstructionVector::iterator 
		i_it = instructions.begin();
	for (; i_it != instructions.end(); ++i_it) {
		ir::PTXInstruction &instr = *i_it;

		// look for mov and ld/st instructions
		if (instr.opcode == ir::PTXInstruction::Mov
			|| instr.opcode == ir::PTXInstruction::Ld 
			|| instr.opcode == ir::PTXInstruction::St) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode 
					== ir::PTXOperand::Address) {
					map<string, unsigned int>::iterator 
						l_it = label_map.find((instr.*operands[n]).identifier);
					if (label_map.end() != l_it) {
						(instr.*operands[n]).type = ir::PTXOperand::u64;
						(instr.*operands[n]).imm_uint = l_it->second;
						report("For instruction " << instr.toString() 
							<< ", mapping local label " << l_it->first 
							<< " to " << l_it->second);
					}
				}
			}
		}
	}

	// allocate local memory object
	_localMemorySize = localOffset;
}

/*! Maps identifiers to const memory allocations. */
void executive::EmulatedKernel::initializeConstMemory() {
	using namespace std;
	assert(module != 0);

	report("Initializing constant variables for kernel " << name);

	unsigned int constantOffset = 0;

	typedef map<string, unsigned int> ConstantOffsetMap;

	ConstantOffsetMap constant;
	ir::Module::GlobalMap::const_iterator it = module->globals().begin();
	for (; it != module->globals().end(); ++it) {
		if (it->second.statement.directive == ir::PTXStatement::Const) {
			unsigned int offset;

			report("  Found global const variable " 
				<< it->second.statement.name);
			_computeOffset(it->second.statement, 
				offset, constantOffset);						
			constant[it->second.statement.name] = offset;
		}
	}
	
	report( "Total constant memory size is " << constantOffset );

	ir::PTXOperand ir::PTXInstruction:: *operands[] = {
		&ir::PTXInstruction::d, &ir::PTXInstruction::a, &ir::PTXInstruction::b, 
		&ir::PTXInstruction::c
	};
	PTXInstructionVector::iterator i_it = instructions.begin();
	for (; i_it != instructions.end(); ++i_it) {
		ir::PTXInstruction &instr = *i_it;

		// look for mov instructions or ld/st instruction
		if (instr.opcode == ir::PTXInstruction::Mov
			|| instr.opcode == ir::PTXInstruction::Ld 
			|| instr.opcode == ir::PTXInstruction::St) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode 
					== ir::PTXOperand::Address) {
					ConstantOffsetMap::iterator	l_it 
						= constant.find((instr.*operands[n]).identifier);
					if (constant.end() != l_it) {
						report("For instruction " << instr.toString() 
							<< ", mapping constant label " << l_it->first 
							<< " to " << l_it->second );
						(instr.*operands[n]).type = ir::PTXOperand::u64;
						(instr.*operands[n]).imm_uint = l_it->second;
					}
				}
			}
		}
	}

	// allocate constant memory object
	delete[] ConstMemory;
	
	_constMemorySize = constantOffset;
	if (_constMemorySize > 0) {
		ConstMemory = new char[_constMemorySize];
	}
	else {
		ConstMemory = 0;
	}
	
	// copy globals into constant memory
	for (ConstantOffsetMap::iterator l_it = constant.begin(); 
		l_it != constant.end(); ++l_it) {

		assert(device != 0);
		Device::MemoryAllocation* global = device->getGlobalAllocation(
			module->path(), l_it->first);

		assert(global != 0);
		assert(global->size() + l_it->second <= _constMemorySize);

		memcpy(ConstMemory + l_it->second, global->pointer(), global->size());
	}

}

/*!
	Maps identifiers to global memory allocations.
*/
void executive::EmulatedKernel::initializeGlobalMemory() {
	using namespace std;
	if(module == 0) return;
	
	report("Initializing global variables for kernel " << name);

	unordered_set<string> global;
	
	ir::Module::GlobalMap::const_iterator it = module->globals().begin();
	for (; it != module->globals().end(); ++it) {
		if (it->second.statement.directive == ir::PTXStatement::Global) {
			report(" Found global variable " << it->second.statement.name);
			global.insert(it->second.statement.name);
		}
	}

	// now visit every instruction and change the address mode from label 
	// to immediate, and assign the offset as an immediate value 
	ir::PTXOperand ir::PTXInstruction:: *operands[] = {
		&ir::PTXInstruction::d, &ir::PTXInstruction::a, &ir::PTXInstruction::b, 
		&ir::PTXInstruction::c };
	PTXInstructionVector::iterator 
		i_it = instructions.begin();
	for (; i_it != instructions.end(); ++i_it) {
		ir::PTXInstruction &instr = *i_it;

		// look for mov instructions or ld/st/atom instruction
		if (instr.opcode == ir::PTXInstruction::Mov
			|| instr.opcode == ir::PTXInstruction::Ld 
			|| instr.opcode == ir::PTXInstruction::St
			|| instr.opcode == ir::PTXInstruction::Atom) {
			for (int n = 0; n < 4; n++) {
				if ((instr.*operands[n]).addressMode 
					== ir::PTXOperand::Address) {
					unordered_set<string>::iterator l_it = 
						global.find((instr.*operands[n]).identifier);
					if (global.end() != l_it) {
						(instr.*operands[n]).type = ir::PTXOperand::u64;
						assert( device != 0);
						Device::MemoryAllocation* allocation = 
							device->getGlobalAllocation(
							module->path(), *l_it);
						assert(allocation != 0);
						(instr.*operands[n]).imm_uint = 
							(ir::PTXU64)allocation->pointer();
						report("Mapping global label " 
							<< (instr.*operands[n]).identifier << " to " 
							<< (void *)(instr.*operands[n]).imm_uint 
							<< " for instruction " << instr.toString() );
					}
				}
			}
		}
	}
}

void executive::EmulatedKernel::jumpToPC(int PC) {
	assert(CTA != 0);
	
	CTA->jumpToPC(PC);
}

executive::EmulatedKernel::RegisterFile 
	executive::EmulatedKernel::getCurrentRegisterFile() const {
	assert(CTA != 0);
	return CTA->getCurrentRegisterFile();		
}

const char* executive::EmulatedKernel::getSharedMemory() const {
	assert(CTA != 0);
	return CTA->SharedMemory;		
}

void executive::EmulatedKernel::initializeTextureMemory() {
	typedef std::unordered_map<std::string, unsigned int> IndexMap;
	if(module == 0) return;

	report("\n\nInitializing texture variables for kernel " << name);

	textures.clear();
	IndexMap indices;

	unsigned int next = 0;

	for (PTXInstructionVector::iterator fi = instructions.begin(); 
		fi != instructions.end(); ++fi) {
		if (fi->opcode == ir::PTXInstruction::Tex) {
			assert(device != 0);
			ir::Texture* texture = (ir::Texture*)device->getTextureReference(
				module->path(), fi->a.identifier);
			assert(texture != 0);

			IndexMap::iterator index = indices.find(fi->a.identifier);

			if (index == indices.end()) {
				index = indices.insert(std::make_pair(fi->a.identifier,
					next++)).first;
				textures.push_back(texture);
			}

			fi->a.reg = index->second;
			report("updated fi->a.reg = " << fi->a.reg);
		}
	}

	report("Registered indices:");
	#if(REPORT_BASE > 0)
	for (IndexMap::const_iterator ind_it = indices.begin(); 
		ind_it != indices.end(); ++ind_it) {
		report("  " << ind_it->first << ": " << ind_it->second 
			<< " - type: " << textures[ind_it->second]->type 
			<< " - data: " << textures[ind_it->second]->data);
	}
	#endif
}

void executive::EmulatedKernel::updateGlobals() {
	initializeConstMemory();
	initializeGlobalMemory();
}

std::string executive::EmulatedKernel::toString() const {
	std::stringstream stream;
	stream << "Kernel " << name << "\n";
	for( PTXInstructionVector::const_iterator 
		fi = instructions.begin(); 
		fi != instructions.end(); ++fi ) {
		const ir::PTXInstruction &instr = *fi;
		stream << "[PC " << fi - instructions.begin() << "] " << 
			fi->toString();
		if (instr.opcode == ir::PTXInstruction::Bra) {
			stream << " [target: " << instr.branchTargetInstruction 
				<< ", reconverge: " << instr.reconvergeInstruction << "]";
		}
		stream << "\n";
	}
	return stream.str();
}

std::string executive::EmulatedKernel::fileName() const {
	assert(module != 0);
	return module->path();
}

std::string executive::EmulatedKernel::location( unsigned int PC ) const {
	assert(module != 0 );
	assert(PC < instructions.size());
	unsigned int statement = instructions[PC].statementIndex;
	ir::Module::StatementVector::const_iterator s_it 
		= module->statements().begin();
	std::advance(s_it, statement);
	ir::Module::StatementVector::const_reverse_iterator s_rit 
		= ir::Module::StatementVector::const_reverse_iterator(s_it);
	unsigned int program = 0;
	unsigned int line = 0;
	unsigned int col = 0;
	for ( ; s_rit != module->statements().rend(); ++s_rit) {
		if (s_rit->directive == ir::PTXStatement::Loc) {
			line = s_rit->sourceLine;
			col = s_rit->sourceColumn;
			program = s_rit->sourceFile;
			break;
		}
	}
	
	std::string fileName;
	for ( s_it = module->statements().begin(); 
		s_it != module->statements().end(); ++s_it ) {
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

std::string executive::EmulatedKernel::getInstructionBlock(int PC) const {

	ProgramCounterBlockMap::const_iterator 
		bt_it = basicBlockMap.lower_bound(PC);
	if (bt_it != basicBlockMap.end()) {
		return bt_it->second;
	}
	
	return "";
}

/*! \brief accessor for obtaining PCs of first and last instructions in a block */
std::pair<int,int> executive::EmulatedKernel::getBlockRange(const std::string &label) const { 
	return blockPCRange.at(label); 
}


