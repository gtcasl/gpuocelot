/*!
	\file MemoryTraceGenerator.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief declares a MemoryTraceGenerator class used in tracing memory operations in the
		emulator
*/

#include <ocelot/trace/interface/MemoryTraceGenerator.h>
#include <ocelot/executive/interface/EmulatedKernel.h>

#include <ocelot/ir/interface/Module.h>
#include <hydrazine/implementation/Exception.h>
#include <boost/filesystem.hpp>
#include <fstream>
#include <cfloat>
#include <boost/archive/text_oarchive.hpp>

/////////////////////////////////////////////////////////////////////////////

/*
const
global
local
param
shared
texture
*/


unsigned int trace::MemoryTraceGenerator::_counter = 0;

trace::MemoryTraceGenerator::Header::Header() {
	format = MemoryTraceFormat;
	
	thread_count = 0;
	dynamic_instructions = 0;
	dynamic_operations = 0;
	
	const_accesses = 0;
	global_accesses = 0;
	local_accesses = 0;
	param_accesses = 0;
	shared_accesses = 0;
	texture_accesses = 0;
	
	global_min_address = 0;
	global_max_address = 0;
}

trace::MemoryTraceGenerator::Header::~Header() {

}

void trace::MemoryTraceGenerator::Header::access(
	ir::PTXInstruction::AddressSpace space) {
	
	using namespace ir;
	
	switch (space) {
	case PTXInstruction::Const: const_accesses ++; break;
	case PTXInstruction::Global: 
		global_accesses ++;	
		break;
	case PTXInstruction::Local: local_accesses++; break;
	case PTXInstruction::Param: param_accesses++; break;
	case PTXInstruction::Shared: shared_accesses ++; break;
	case PTXInstruction::Texture: texture_accesses ++; break;
	default: break;
	}
}

void trace::MemoryTraceGenerator::Header::address(
	ir::PTXInstruction::AddressSpace space,
	ir::PTXU64 addr) {
	
	using namespace ir;
	
	switch (space) {
	case PTXInstruction::Const: 
		break;
	case PTXInstruction::Texture: // fall through
	case PTXInstruction::Global: 
		{
			if (!global_min_address || addr < global_min_address) {
				global_min_address = addr;
			}
			if (!global_max_address || addr > global_max_address) {
				global_max_address = addr;
			}
		}
		break;
	case PTXInstruction::Local: 
		break;
	case PTXInstruction::Param: 
		break;
	case PTXInstruction::Shared: 
		break;
	default: break;
	}
}


trace::MemoryTraceGenerator::Event::Event() {

}
trace::MemoryTraceGenerator::Event::~Event() {

}

/////////////////////////////////////////////////////////////////////////////

trace::MemoryTraceGenerator::MemoryTraceGenerator() {
	_file = 0;
}

trace::MemoryTraceGenerator::~MemoryTraceGenerator() {
}

void trace::MemoryTraceGenerator::initialize(const executive::EmulatedKernel *kernel) {
	_entry.name = kernel->name;
	_entry.module = kernel->module->modulePath;
	_entry.format = MemoryTraceFormat;

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
			"Failed to open MemoryTraceGenerator kernel trace file " 
			+ _entry.path );
	}

	_archive = new boost::archive::text_oarchive( *_file );

	_event = Event();
	
	_header = Header();	
	_header.blockDimX = kernel->getBlockDim().x;
	_header.blockDimY = kernel->getBlockDim().y;
	_header.blockDimZ = kernel->getBlockDim().z;
	_header.thread_count = kernel->threadCount;
}

/*!
	Called when a TraceEvent is raised in the emulator
*/
void trace::MemoryTraceGenerator::event(const TraceEvent & event) {
	using namespace ir;

	_header.dynamic_instructions ++;
	_header.dynamic_operations += (PTXU64)event.active.count();
	
	if (event.instruction->opcode == PTXInstruction::Ld || event.instruction->opcode == PTXInstruction::St) {
		_event = Event();
		_event.PC = event.PC;
		_event.opcode = event.instruction->opcode;
		_event.addressSpace = event.instruction->addressSpace;
		_event.ctaX = event.blockId.x;
		_event.ctaY = event.blockId.y;
		_event.ctaZ = event.blockId.z;
		
		// memory operation
		PTXInstruction::AddressSpace addressSpace = event.instruction->addressSpace;
		_header.access(addressSpace);

		// form the accesses vector of the event
		PTXU32 threadID = 0;
		TraceEvent::U32Vector::const_iterator size_it = event.memory_sizes.begin();
		for (TraceEvent::U64Vector::const_iterator it = event.memory_addresses.begin();
			it != event.memory_addresses.end(); ++it, ++size_it, ++threadID) {
		
			for (; threadID < _header.thread_count && !event.active[threadID]; threadID++) { }
			
			Access access;
			access.address = *it;
			access.threadID = threadID;
			access.size = *size_it;
			
			_header.address(event.instruction->addressSpace, access.address);
			
			_event.accesses.push_back(access);
		}
		
		*_archive << _event;
	}
	else if (event.instruction->opcode == PTXInstruction::Tex) {
		_event = Event();
		_event.PC = event.PC;
		_event.opcode = event.instruction->opcode;
		_event.addressSpace = PTXInstruction::Texture;
		_event.ctaX = event.blockId.x;
		_event.ctaY = event.blockId.y;
		_event.ctaZ = event.blockId.z;
		
		_header.access(PTXInstruction::Texture);
		PTXU32 threadID = 0;
		TraceEvent::U32Vector::const_iterator size_it = event.memory_sizes.begin();
		TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin();
		for (; addr_it != event.memory_addresses.end(); ++threadID) {
			for (; threadID < _header.thread_count && !event.active[threadID]; ++threadID) { }
			
			for (int j = 0; j < 4; j++) {
				Access access;
				access.address = *addr_it;
				access.size = *size_it;
				access.threadID = threadID;
				
				_header.address(PTXInstruction::Texture, access.address);
				
				_event.accesses.push_back(access);
				++addr_it;
				++size_it;
			}
		}
		
		*_archive << _event;
	}
}

void trace::MemoryTraceGenerator::finish() {
	if( _file ) {		
		_entry.updateDatabase( database );
		delete _archive;

		_file->close();	
		delete _file;
		_file = 0;
		
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
