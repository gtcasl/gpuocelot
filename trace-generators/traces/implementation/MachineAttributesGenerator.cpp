/*!
	\file MachineAttributesGenerator.cpp
	\author Gregory Diamos
	\date Monday April 13, 2009
	\brief The source file for the MachineAttributesGenerator class
*/

// C++ stdlib includes
#include <fstream>

// Ocelot includes
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <traces/interface/MachineAttributesGenerator.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>

// Boost includes
#include <boost/filesystem.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


unsigned int trace::MachineAttributesGenerator::MachineAttributesGenerator::_counter = 0;

trace::MachineAttributesGenerator::MachineAttributesGenerator() {
}

trace::MachineAttributesGenerator::~MachineAttributesGenerator() {
	
}

void trace::MachineAttributesGenerator::initialize(const ir::ExecutableKernel& kernel) {

	_entry.name = kernel.name;
	_entry.module = kernel.module->path();
	_entry.format = KernelDimensionsFormat;

	std::string name = kernel.name;
	
	if( name.size() > 20 )
	{
		name.resize( 20 );
	}

	std::stringstream stream;
	stream << _entry.format << "_" << _counter++;

	boost::filesystem::path path( database );
	path = path.parent_path();
	path /= _entry.program + "_" + name + "_" + stream.str() 
		+ ".header";
	path = boost::filesystem::system_complete( path );
	
	_entry.header = path.string();
	
	_header.format = MachineAttributesFormat;
	
}

void trace::MachineAttributesGenerator::event( const TraceEvent& event ) {
}

void trace::MachineAttributesGenerator::finish() {

	_entry.updateDatabase( database );

	std::ofstream hfile( _entry.header.c_str() );
	boost::archive::text_oarchive harchive( hfile );

	if( !hfile.is_open() )
	{
		throw hydrazine::Exception(
			"Failed to open MachineAttributesGenerator header file " 
			+ _entry.header );
	}
	
	harchive << _header;
	
	hfile.close();
}

