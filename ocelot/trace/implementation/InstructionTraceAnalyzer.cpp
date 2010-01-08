/*!
	\file InstructionTraceAnalyzer.cpp
	\author Andrew Kerr
	\date Jan 2010
	\brief The header file for the InstructionTraceAnalyzer class
*/

// C++ stdlib includes
#include <map>
#include <deque>
#include <iostream>
#include <fstream>
#include <cfloat>

// Ocelot includes
#include <ocelot/trace/interface/InstructionTraceGenerator.h>

// Hydrazine includes
#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/Exception.h>

// Boost includes
#include <boost/archive/text_iarchive.hpp>

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::InstructionTraceAnalyzer::InstructionTraceAnalyzer() {

	std::ifstream stream(database.c_str());
	
	if( !stream.is_open() ) {
		throw hydrazine::Exception("Could not open database file " 
			+ database);
	}
	
	unsigned int count;
	
	boost::archive::text_iarchive archive(stream);
	archive >> count;
	
	for( unsigned int i = 0; i < count; ++i ) {
		KernelEntry entry;
		archive >> entry;
		if( entry.format == TraceGenerator::BranchTraceFormat ) {

			KernelMap::iterator kernel = _kernels.find( entry.program );

			if( kernel == _kernels.end() ) {
				kernel = _kernels.insert( std::make_pair( 
					entry.program, KernelVector() ) ).first;
			}
			kernel->second.push_back( entry );
		}
	}
}

void trace::InstructionTraceAnalyzer::list() const {

	std::cout << "There are " << _kernels.size() 
		<< " programs referenced in the database\n";

	for( KernelMap::const_iterator vector = _kernels.begin(); vector != _kernels.end(); ++vector ) {

		std::cout << " Program \"" << vector->first << "\" contains " 
			<< vector->second.size() << " kernels.\n";

		for( KernelVector::const_iterator kernel = vector->second.begin(); 
			kernel != vector->second.end(); ++kernel ){

			std::cout << "  " << kernel->header << "\n";
		}
	}
		
	std::cout << "\n";
}

/*!
	Produces: histogram of dynamic instruction counts for each application
		x-axis: functional units
		y-axis: number of dynamic instructions
*/
void trace::InstructionTraceAnalyzer::instructions_by_application() const {

	// sequence of functional units
	trace::InstructionTraceGenerator::FunctionalUnit funcUnits[] = {
		InstructionTraceGenerator::Integer_arithmetic,	//! integer arithmetic
		InstructionTraceGenerator::Integer_logical,		//! itneger logical
		InstructionTraceGenerator::Integer_comparison,	//! comparison
		InstructionTraceGenerator::Float_single,				//! floating-point single-precision
		InstructionTraceGenerator::Float_double,				//! floating-point, double-precision
		InstructionTraceGenerator::Float_comparison,		//! floating-point comparison
		InstructionTraceGenerator::Memory_offchip,			//! off-chip: {global, local}
		InstructionTraceGenerator::Memory_onchip,			//! cached or scratchpad: {texture, shared, constant}
		InstructionTraceGenerator::Control,						//! control-flow instructions
		InstructionTraceGenerator::Parallelism,				//! parallelism: sync, reduction, vote
		InstructionTraceGenerator::Special,						//! transcendental and special functions
		InstructionTraceGenerator::Other,							//! not categorized
		InstructionTraceGenerator::FunctionalUnit_invalid
	};

	for( KernelMap::const_iterator vector = _kernels.begin(); 
		vector != _kernels.end(); ++vector ) 
	{
		std::string program = vector->first;
		const KernelVector & kernels = vector->second;

		
	}
}

void trace::InstructionTraceAnalyzer::instructions_by_kernel() const {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, char** argv ) {

	hydrazine::ArgumentParser parser( argc, argv );
	
	parser.description("Provides the ability to inspect a database created by" 
		+ std::string( "a InstructionTraceGenerator" ) );
	
	bool help;
	bool list;
	bool instructions_by_kernel = false;
	bool instructions_by_app = false;
	std::string database;

	parser.parse( "-h", help, false, "Print this help message." );
	parser.parse( "-i", database, "traces/database.db", "Path to database file." );
	parser.parse( "-a", instructions_by_app, false,
		"Compute instruction histogram for each application over all its kernels");
	parser.parse( "-k", instructions_by_kernel, false,
		"Compute instruction histogram for each kernel" );
	parser.parse( "-l", list, false, "List all traces in the database." );
		
	if( help ) {
		std::cout << parser.help();
		return 0;
	}
	
	trace::InstructionTraceAnalyzer analyzer( database );
	
	if( list ) {
		analyzer.list();	
	}
	
	if( instructions_by_kernel ) {
		analyzer.instructions_by_kernel();
	}

	if( instructions_by_app ) {
		analyzer.instructions_by_application();
	}
	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

