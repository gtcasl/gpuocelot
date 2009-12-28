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
	
	global_instructions = 0;
	texture_instructions = 0;
	
	global_bytes = 0;
	shared_bytes = 0;
	texture_bytes = 0;
	
	global_words = 0;
	texture_words = 0;
	
	global_segments = 0;
	halfwarps = 0;
	
	headerOnly = false;
	
}

trace::MemoryTraceGenerator::Header::~Header() {

}

void trace::MemoryTraceGenerator::Header::access(
	ir::PTXInstruction::AddressSpace space, ir::PTXU64 bytes) {
	
	using namespace ir;
	
	switch (space) {
	case PTXInstruction::Const: const_accesses++; break;
	case PTXInstruction::Global: 
		global_accesses++; 
		global_bytes += bytes; 
		++global_instructions; 
		break;
	case PTXInstruction::Local: local_accesses++; break;
	case PTXInstruction::Param: param_accesses++; break;
	case PTXInstruction::Shared: 
		shared_accesses++; shared_bytes += bytes; break;
	case PTXInstruction::Texture: 
		texture_accesses++; 
		texture_bytes += bytes;
		++texture_instructions;
		break;
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
	case PTXInstruction::Texture:
		{
			if (!global_min_address || addr < global_min_address) {
				global_min_address = addr;
			}
			if (!global_max_address || addr > global_max_address) {
				global_max_address = addr;
			}
			texture_words++;
		}
		break;
	case PTXInstruction::Global: 
		{
			if (!global_min_address || addr < global_min_address) {
				global_min_address = addr;
			}
			if (!global_max_address || addr > global_max_address) {
				global_max_address = addr;
			}
			global_words++;
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
	headerOnly = false;
}

trace::MemoryTraceGenerator::~MemoryTraceGenerator() {
}

void trace::MemoryTraceGenerator::initialize(
	const ir::ExecutableKernel& kernel) {
	_entry.name = kernel.name;
	_entry.module = kernel.module->modulePath;
	_entry.format = MemoryTraceFormat;

	std::string name = kernel.name;
		
	if( name.size() > 20 )
	{
		name.resize( 20 );
	}

	std::stringstream stream;
	stream << _entry.format << "_" << _counter++;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= name + "_" + stream.str() + ".trace";
	path = boost::filesystem::system_complete( path );

	_entry.path = path.string();

	path = path.parent_path();
	path /= name + "_" + stream.str() + ".header";
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
	_header.blockDimX = kernel.blockDim().x;
	_header.blockDimY = kernel.blockDim().y;
	_header.blockDimZ = kernel.blockDim().z;
	_header.thread_count = kernel.maxThreadsPerBlock();
	_header.headerOnly = headerOnly;
}

/*!
	Called when a TraceEvent is raised in the emulator
*/
void trace::MemoryTraceGenerator::event(const TraceEvent & event) {
	using namespace ir;

	_header.dynamic_instructions++;
	_header.dynamic_operations += (PTXU64)event.active.count();
	
	if (event.instruction->opcode == PTXInstruction::Ld 
		|| event.instruction->opcode == PTXInstruction::St) {
		
		if( !headerOnly )
		{
			_event = Event();
			_event.PC = event.PC;
			_event.opcode = event.instruction->opcode;
			_event.addressSpace = event.instruction->addressSpace;
			_event.ctaX = event.blockId.x;
			_event.ctaY = event.blockId.y;
			_event.ctaZ = event.blockId.z;
		}
		
		// form the accesses vector of the event
		PTXU64 bytes = 0;
		PTXU32 threadID = 0;
		PTXU64 starting_address = -1;
		PTXU32 halfwarpSize = _header.thread_count / 2;
		
		TraceEvent::U32Vector::const_iterator size_it = event.memory_sizes.begin();
		for (TraceEvent::U64Vector::const_iterator it = event.memory_addresses.begin();
			it != event.memory_addresses.end(); ++it, ++size_it, ++threadID) {
		
			if( !headerOnly )
			{
				for (; threadID < _header.thread_count 
					&& !event.active[threadID]; threadID++) { }
			
				Access access;
				access.address = *it;
				access.threadID = threadID;
				access.size = *size_it;

				_event.accesses.push_back(access);
			}
			
			_header.address(event.instruction->addressSpace, *it);
			bytes += *size_it;
			
			if( threadID > halfwarpSize )
			{
				++_header.global_segments;
				++_header.halfwarps;
				starting_address = *it + *size_it;
			}
			else if( starting_address != *it )
			{
				++_header.global_segments;
				starting_address = *it + *size_it;
			}
		}
		
		// memory operation
		_header.access(event.instruction->addressSpace, bytes);

		if( !headerOnly )
		{
			*_archive << _event;
		}
	}
	else if (event.instruction->opcode == PTXInstruction::Tex) {
		if( !headerOnly )
		{
			_event = Event();
			_event.PC = event.PC;
			_event.opcode = event.instruction->opcode;
			_event.addressSpace = PTXInstruction::Texture;
			_event.ctaX = event.blockId.x;
			_event.ctaY = event.blockId.y;
			_event.ctaZ = event.blockId.z;
		}
		
		PTXU64 bytes = 0;
		PTXU32 threadID = 0;
		PTXU64 starting_address = -1;
		PTXU32 halfwarpSize = _header.thread_count / 2;
		TraceEvent::U32Vector::const_iterator size_it = event.memory_sizes.begin();
		TraceEvent::U64Vector::const_iterator addr_it = event.memory_addresses.begin();
		for (; addr_it != event.memory_addresses.end(); ++threadID, ++addr_it,
			++size_it) {
			if( !headerOnly )
			{
				for (; threadID < _header.thread_count 
					&& !event.active[threadID]; ++threadID) { }
			
				for (int j = 0; j < 4; j++) {
					Access access;
					access.address = *addr_it;
					access.size = *size_it;
					access.threadID = threadID;
				
					_event.accesses.push_back(access);
				}
			}
			bytes += *size_it;
			_header.address(PTXInstruction::Texture, *addr_it);
			
			if( threadID > halfwarpSize )
			{
				++_header.global_segments;
				++_header.halfwarps;
				starting_address = *addr_it + *size_it;
			}
			else if( starting_address != *addr_it )
			{
				++_header.global_segments;
				starting_address = *addr_it + *size_it;
			}
			
		}
		
		_header.access(PTXInstruction::Texture, bytes);
		
		if( !headerOnly )
		{
			*_archive << _event;
		}
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
