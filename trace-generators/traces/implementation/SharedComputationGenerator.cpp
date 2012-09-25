/*!
	\file SharedComputationGenerator.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief declares a SharedComputationGenerator class used in tracing memory operations in the
		emulator
*/

#include <traces/interface/SharedComputationGenerator.h>
#include <ocelot/executive/interface/EmulatedKernel.h>

#include <ocelot/ir/interface/Module.h>
#include <hydrazine/interface/Exception.h>
#include <boost/filesystem.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <cfloat>

/////////////////////////////////////////////////////////////////////////////

unsigned int trace::SharedComputationGenerator::_counter = 0;

trace::SharedComputationGenerator::Header::Header(): 
	format(SharedComputationTraceFormat),
	sharedLoads(0) {
	
	sharedLoads = 0;
	threadCount = 0;
	storeOutOfBoundsAccesses = 0;
	loadOutOfBoundsAccesses = 0;
	sharedMemorySize = 0;
	storeSharedCount = 0;
	loadSharedCount = 0;
	crossThreadLds = 0;
}

trace::SharedComputationGenerator::Header::~Header() {

}

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////

trace::SharedComputationGenerator::SharedComputationGenerator() {
	sharedMemoryOwners = 0;
	SharedMemoryMask = (16384 - 1);
}

trace::SharedComputationGenerator::~SharedComputationGenerator() {

}

/*!
	called when a traced kernel is launched to retrieve some parameters from the kernel
*/
void trace::SharedComputationGenerator::initialize(
	const executive::ExecutableKernel& kernel) {
	using namespace ir;

	_entry.name = kernel.name;
	_entry.module = kernel.module->path();
	_entry.format = SharedComputationTraceFormat;

	std::stringstream stream;
	stream << _entry.format << "_" << _counter++;

	std::string name = kernel.name;
		
	if( name.size() > 20 )
	{
		name.resize( 20 );
	}

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= name + "_" + stream.str() + ".trace";
	path = boost::filesystem::system_complete( path );

	_entry.path = path.string();

	path = path.parent_path();
	path /= name + "_" + stream.str() + ".header";
	path = boost::filesystem::system_complete( path );

	_entry.header = path.string();

	_header = Header();	
	_header.threadCount = kernel.maxThreadsPerBlock();

	if (sharedMemoryOwners) {
		delete [] sharedMemoryOwners;
	}

	_header.sharedMemorySize = 16384; //kernel->SharedMemorySize;

	blockId = 0; // for now - in real life, compute the actual blockId

	sharedMemoryOwners = new ir::PTXS32[_header.sharedMemorySize];
	for (PTXU32 i = 0; i < _header.sharedMemorySize; i++) {
		sharedMemoryOwners[i] = -1;
	}
	
	// examine kernel's basic blocks and look for ld.global <reg> ; st.shared [], <reg>; pairs. Add
	// st.shared [], reg program counters to mask set so these result in writing -1 to sharedMemoryOwners
	selectMaskedStSet(kernel);
}

/*!

*/
void trace::SharedComputationGenerator::selectMaskedStSet(
	const executive::ExecutableKernel& kernel) {
	maskedStSet.clear();
	
	for (ir::ControlFlowGraph::const_iterator 
		block = kernel.cfg()->begin(); block != kernel.cfg()->end(); ++block) {

		for (ir::ControlFlowGraph::InstructionList::const_iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction) {
			const ir::PTXInstruction& ptx = static_cast<
				const ir::PTXInstruction&>(**instruction);
	
			if (ptx.opcode == ir::PTXInstruction::Ld 
				&& ptx.addressSpace == ir::PTXInstruction::Global) {
				// look for possible store instructions
				ir::ControlFlowGraph::InstructionList::const_iterator 
					next_instr = instruction; 
				++next_instr;
			
				for (; next_instr != block->instructions.end(); ++next_instr) {
					const ir::PTXInstruction& next = static_cast<
						const ir::PTXInstruction&>(**next_instr);
				
					//
					// If data from a ld.global instruction is being stored 
					// to shared memory, mask this set
					//
					if (next.opcode == ir::PTXInstruction::St && 
						next.addressSpace == ir::PTXInstruction::Shared &&
						next.a.identifier == ptx.d.identifier ) {
				
						maskedStSet.insert((ir::PTXU32)(next.pc));
						break;
					}
				
					// stop at first anti-dependency
					if (next.d.addressMode == ir::PTXOperand::Register && 
						next.d.identifier == ptx.d.identifier) {
						break;
					}
				}
			}
		}
	}
}

/*!
	Called whenever an event takes place.

	Note, the const reference 'event' is only valid until event() returns
*/
void trace::SharedComputationGenerator::event(const TraceEvent & event) {
	using namespace ir;

	_header.dynamic_instructions += (PTXU64)event.active.count();

	if (event.instruction->opcode == PTXInstruction::St && 
		event.instruction->addressSpace == PTXInstruction::Shared) {

		PTXS32 threadID = 0;
		for (TraceEvent::U64Vector::const_iterator 
			addr_it = event.memory_addresses.begin(); 
			addr_it != event.memory_addresses.end(); ++addr_it, ++threadID) {

			for (; threadID < (PTXS32)_header.threadCount 
				&& !event.active[threadID]; ++threadID) {
				// do nothing - find the next active thread
			}
			if (threadID >= (PTXS32)_header.threadCount) {
				return;
			}
			
			++_header.storeSharedCount;

			PTXS32 threadIdentifier = threadID;
			if (maskedStSet.find(event.PC) != maskedStSet.end()) {
				threadIdentifier = -1;
			}
			
			PTXU64 baseAddress = *addr_it;
			for (PTXU64 offset = 0; 
				offset < (PTXU64)event.memory_size; offset++) {
				PTXU64 address = (baseAddress + offset) & SharedMemoryMask;
				if (address < _header.sharedMemorySize) {
					sharedMemoryOwners[address] = threadIdentifier;
				}
				else {
					++_header.storeOutOfBoundsAccesses;
				}
			}
		}		
	}
	else if (event.instruction->opcode == PTXInstruction::Ld && 
		event.instruction->addressSpace == PTXInstruction::Shared) {

		PTXS32 threadID = 0;
		for (TraceEvent::U64Vector::const_iterator 
			addr_it = event.memory_addresses.begin(); 
			addr_it != event.memory_addresses.end(); ++addr_it, ++threadID) {

			for (; threadID < (PTXS32)_header.threadCount 
				&& !event.active[threadID]; ++threadID) {
				// do nothing - find the next active thread
			}
			if (threadID >= (PTXS32)_header.threadCount) {
				return;
			}
			++_header.loadSharedCount;

			PTXU64 address = (*addr_it & SharedMemoryMask);
			if (address < _header.sharedMemorySize) {
				PTXS32 owningThread = sharedMemoryOwners[address];
				if (owningThread >= 0 && owningThread != threadID) {
					++_header.crossThreadLds;
				}
			}
			else {
				// bad news
				++_header.loadOutOfBoundsAccesses;
			}
		}

		if (event.memory_addresses.size()) {
			++_header.sharedLoads;
		}
	}
}

void trace::SharedComputationGenerator::finish() {
	if (sharedMemoryOwners) {
		delete [] sharedMemoryOwners;
		sharedMemoryOwners = 0;
	}
	
	_entry.updateDatabase( database );

	std::ofstream hfile( _entry.header.c_str() );
	boost::archive::text_oarchive harchive( hfile );

	if( !hfile.is_open() )
	{
		throw hydrazine::Exception(
			"Failed to open MemoryTraceGenerator header file " 
			+ _entry.header );
	}
	
	harchive << _header;
	
	hfile.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////99

