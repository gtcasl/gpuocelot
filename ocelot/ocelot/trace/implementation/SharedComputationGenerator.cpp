/*!
	\file SharedComputationGenerator.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief declares a SharedComputationGenerator class used in tracing memory operations in the
		emulator
*/

#include <ocelot/trace/interface/SharedComputationGenerator.h>
#include <ocelot/executive/interface/EmulatedKernel.h>

#include <ocelot/ir/interface/Module.h>
#include <hydrazine/implementation/Exception.h>
#include <boost/filesystem.hpp>
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
}

trace::SharedComputationGenerator::Header::~Header() {

}

/////////////////////////////////////////////////////////////////////////////

trace::SharedComputationGenerator::Event::Event() {

}
trace::SharedComputationGenerator::Event::~Event() {

}

/////////////////////////////////////////////////////////////////////////////

trace::SharedComputationGenerator::SharedComputationGenerator() {
	sharedMemoryOwners = 0;
	_file = 0;

	SharedMemoryMask = (16384 - 1);
}

trace::SharedComputationGenerator::~SharedComputationGenerator() {
	if (sharedMemoryOwners) {
		delete [] sharedMemoryOwners;
	}	
	if( _file ) {		
		_entry.updateDatabase( database );
		delete _archive;

		_file->close();	
		delete _file;
		
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
}

/*!
	called when a traced kernel is launched to retrieve some parameters from the kernel
*/
void trace::SharedComputationGenerator::initialize(const executive::EmulatedKernel *kernel) {
	using namespace ir;

	_entry.name = kernel->name;
	_entry.module = kernel->module->modulePath;
	_entry.format = SharedComputationTraceFormat;

	std::stringstream stream;
	stream << _entry.format << "_" << _counter++;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= kernel->name + "_" + stream.str() + ".trace";
	path = boost::filesystem::system_complete( path );

	_entry.path = path.string();

	path = path.parent_path();
	path /= kernel->name + "_" + stream.str() + ".header";
	path = boost::filesystem::system_complete( path );

	_entry.header = path.string();

	if( _file != 0 )
	{
		delete _archive;
		delete _file;
	}

	_file = new std::ofstream( _entry.path.c_str() );

	if( !_file->is_open() )
	{
		throw hydrazine::Exception(
			"Failed to open SharedComputationGenerator kernel trace file " 
			+ _entry.path );
	}

	_archive = new boost::archive::text_oarchive( *_file );
	
	_header = Header();	
	_header.threadCount = kernel->threadCount;

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
void trace::SharedComputationGenerator::selectMaskedStSet(const executive::EmulatedKernel *kernel) {
	using namespace std;
	using namespace ir;
	
	maskedStSet.clear();
	
	for (ir::Kernel::PTXInstructionVector::const_iterator instr_it = kernel->KernelInstructions.begin();
		instr_it != kernel->KernelInstructions.end(); ++instr_it) {
	
		if (instr_it->opcode == PTXInstruction::Ld && instr_it->addressSpace == PTXInstruction::Global) {
			// look for possible store instructions
			ir::Kernel::PTXInstructionVector::const_iterator next_instr = instr_it; 
			++next_instr;
			
			for (; next_instr != kernel->KernelInstructions.end(); ++next_instr) {
			
				// stop at control flow instructions
				if (next_instr->opcode == PTXInstruction::Bra || 
					next_instr->opcode == PTXInstruction::Reconverge ||
					next_instr->opcode == PTXInstruction::Bar ||
					next_instr->opcode == PTXInstruction::Exit) {
					
					break;
				}
				
				//
				// If data from a ld.global instruction is being stored to shared memory, mask this set
				//
				if (next_instr->opcode == PTXInstruction::St && 
					next_instr->addressSpace == PTXInstruction::Shared &&
					next_instr->a.identifier == instr_it->d.identifier ) {
				
					maskedStSet.insert((PTXU32)(next_instr - kernel->KernelInstructions.begin()));
					break;
				}
				
				// stop at first anti-dependency
				if (next_instr->d.addressMode == PTXOperand::Register && 
					next_instr->d.identifier == instr_it->d.identifier) {
					break;
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

		TraceEvent::U32Vector::const_iterator size_it = event.memory_sizes.begin();

		PTXS32 threadID = 0;
		for (TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin(); 
			addr_it != event.memory_addresses.end(); ++addr_it, ++size_it, ++threadID) {

			for (; threadID < (PTXS32)_header.threadCount && !event.active[threadID]; ++threadID) {
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
			for (PTXU64 offset = 0; offset < (PTXU64)*size_it; offset++) {
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

		Event _event;
		_event.blockId = blockId;
		_event.PC = event.PC;
		_event.opcode = event.instruction->opcode;
		_event.type = event.instruction->d.type;

		TraceEvent::U32Vector::const_iterator size_it = event.memory_sizes.begin();

		PTXS32 threadID = 0;
		for (TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin(); 
			addr_it != event.memory_addresses.end(); ++addr_it, ++size_it, ++threadID) {

			for (; threadID < (PTXS32)_header.threadCount && !event.active[threadID]; ++threadID) {
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

					// loading data written by another thread
					Access access;
					access.threadID = threadID;
					access.sourceThread = owningThread;
					access.address = (PTXU32)address;
					access.size = *size_it;
			
					_event.accesses.push_back(access);
				}
			}
			else {
				// bad news
				++_header.loadOutOfBoundsAccesses;
			}
		}

		if (_event.accesses.size()) {
			// emit event 
			*_archive << _event;
			++_header.sharedLoads;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////99

