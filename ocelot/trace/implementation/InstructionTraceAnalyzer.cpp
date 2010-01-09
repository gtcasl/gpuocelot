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
#include <ocelot/trace/interface/InstructionTraceAnalyzer.h>
#include <ocelot/trace/interface/InstructionTraceGenerator.h>

// Hydrazine includes
#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/Exception.h>

// Boost includes
#include <boost/archive/text_iarchive.hpp>

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::InstructionTraceAnalyzer::InstructionTraceAnalyzer(const std::string & database) {

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
		if( entry.format == TraceGenerator::InstructionTraceFormat ) {

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

static void append(trace::InstructionTraceGenerator::FunctionalUnitCountMap & appCounter,
	const trace::InstructionTraceGenerator::FunctionalUnitCountMap &count) {
	
	typedef trace::InstructionTraceGenerator::OpcodeCountMap OC;
	typedef trace::InstructionTraceGenerator::FunctionalUnitCountMap IC;

	for (IC::const_iterator count_it = count.begin(); count_it != count.end(); ++count_it) {
		IC::iterator app_it = appCounter.find(count_it->first);
		if (app_it == appCounter.end()) {
			appCounter[count_it->first] = count_it->second;
		}
		else {
			for (OC::const_iterator oc_it = count_it->second.begin(); oc_it != count_it->second.end();
				++oc_it) {
				
				if (appCounter[count_it->first].find(oc_it->first) == appCounter[count_it->first].end()) {
					appCounter[count_it->first][oc_it->first] = oc_it->second;
					appCounter[count_it->first][oc_it->first].activity *= appCounter[count_it->first][oc_it->first].dynamic_count;
				}
				else {
					appCounter[count_it->first][oc_it->first].dynamic_count += oc_it->second.dynamic_count;
					appCounter[count_it->first][oc_it->first].static_count += oc_it->second.static_count;
					appCounter[count_it->first][oc_it->first].activity += oc_it->second.activity * oc_it->second.dynamic_count;
				}
			}
		}	
	}
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

	std::cout << "# InstructionTraceAnalyzer - by application\n#" << std::endl;

	std::cout << "\n";
	std::cout << "# Python object notation:\n";
	std::cout << "#  \n";
	std::cout << "#  map<program name, \n";
	std::cout << "#    map<functional unit, tuple<dynamic count, static count, activity> > >\n\n";
	
	std::cout << "applications = [\n";
	for( KernelMap::const_iterator vector = _kernels.begin(); 
		vector != _kernels.end(); ++vector ) {
		std::string program = vector->first;
		std::cout << "  '" << program << "',\n";
	}
	std::cout << "]\n\n";
	
	std::cout << "functional_units = [\n";
	for (int n = 0; funcUnits[n] != InstructionTraceGenerator::FunctionalUnit_invalid; n++) {
		std::cout << "  '" << trace::InstructionTraceGenerator::toString(funcUnits[n]) << "',\n";
	}
	std::cout << "]\n\n";
	
	std::cout << "results = {\n";

	for( KernelMap::const_iterator vector = _kernels.begin(); 
		vector != _kernels.end(); ++vector ) {
		
		std::string program = vector->first;
		const KernelVector & kernels = vector->second;
		InstructionTraceGenerator::FunctionalUnitCountMap appCounter;

		// loop over the kernels
		for (KernelVector::const_iterator k_it = kernels.begin(); k_it != kernels.end(); ++k_it) {
			InstructionTraceGenerator::Header header;
			std::ifstream hstream( k_it->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );
	
			harchive >> header;
			assert(header.format == TraceGenerator::InstructionTraceFormat);
			
			InstructionTraceGenerator::FunctionalUnitCountMap counter;
			harchive >> counter;

			// aggregate counts
			append(appCounter, counter);
		}
		
		// print the program name
		std::cout << "  '" << program << "': {" << std::endl;
		
		// print out one bar per functional unit
		for (int n = 0; funcUnits[n] != InstructionTraceGenerator::FunctionalUnit_invalid; n++) {		

			size_t dynamicCount = 0;
			size_t staticCount = 0;
			double activity = 0;
			int activeFU = 0;
			
			typedef trace::InstructionTraceGenerator::OpcodeCountMap OC;
			for (OC::iterator op_it = appCounter[funcUnits[n]].begin(); op_it != appCounter[funcUnits[n]].end();
				++op_it) {
				
				dynamicCount += op_it->second.dynamic_count;
				staticCount += op_it->second.static_count;
				if (op_it->second.dynamic_count) {
					activity += op_it->second.activity;
					activeFU ++;
				}
			}
			
			if (activeFU) {
				activity /= (double)activeFU * (double)dynamicCount;
			}
			
			// write to stdout
			std::cout << "    '" << trace::InstructionTraceGenerator::toString(funcUnits[n]) << "': ( " 
				<< dynamicCount << ", " << staticCount << ", " << 0 << " )," << std::endl;
		}
		
		std::cout << "  },\n";
	}
	std::cout << "}\n";
}

void trace::InstructionTraceAnalyzer::instructions_by_kernel() const {


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

	std::cout << "# InstructionTraceAnalyzer - by kernel\n#" << std::endl;

	std::cout << "\n";
	std::cout << "# Python object notation:\n";
	std::cout << "#  \n";
	std::cout << "#  map<program name.kernel name, \n";
	std::cout << "#    map<functional unit, pair<dynamic count, static count, activity> > >\n\n";
	
	std::cout << "kernels = [\n";
	for( KernelMap::const_iterator vector = _kernels.begin(); 
		vector != _kernels.end(); ++vector ) {
		
		std::string program = vector->first;
		const KernelVector & kernels = vector->second;
		
		for (KernelVector::const_iterator k_it = kernels.begin(); k_it != kernels.end(); ++k_it) {
			std::cout << "  '" << program << ":" << k_it->name << "',\n";
		}
	}
	std::cout << "]\n\n";
	
	std::cout << "functional_units = [\n";
	for (int n = 0; funcUnits[n] != InstructionTraceGenerator::FunctionalUnit_invalid; n++) {
	
		std::cout << "  '" << trace::InstructionTraceGenerator::toString(funcUnits[n]) << "',\n";
	}
	std::cout << "]\n\n";
	
	std::cout << "results = {\n";

	for( KernelMap::const_iterator vector = _kernels.begin(); 
		vector != _kernels.end(); ++vector ) {
		
		std::string program = vector->first;
		const KernelVector & kernels = vector->second;
		InstructionTraceGenerator::FunctionalUnitCountMap appCounter;

		// loop over the kernels
		for (KernelVector::const_iterator k_it = kernels.begin(); k_it != kernels.end(); ++k_it) {
			InstructionTraceGenerator::Header header;
			std::ifstream hstream( k_it->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );
	
			harchive >> header;
			assert(header.format == TraceGenerator::InstructionTraceFormat);
			
			InstructionTraceGenerator::FunctionalUnitCountMap counter;
			harchive >> counter;

			// print the program name
			std::cout << "  '" << program << ":" << k_it->name << "': {" << std::endl;
		
			// print out one bar per functional unit
			for (int n = 0; funcUnits[n] != InstructionTraceGenerator::FunctionalUnit_invalid; n++) {		

				size_t dynamicCount = 0;
				size_t staticCount = 0;
				double activity = 0;
				int activeFU = 0;
			
				typedef trace::InstructionTraceGenerator::OpcodeCountMap OC;
				for (OC::iterator op_it = counter[funcUnits[n]].begin(); op_it != counter[funcUnits[n]].end();
					++op_it) {
				
					dynamicCount += op_it->second.dynamic_count;
					staticCount += op_it->second.static_count;
					
					if (op_it->second.dynamic_count) {
						activity += op_it->second.activity;
						activeFU++;
					}
				}
			
				if (activeFU) {
					activity /= (double)activeFU;
				}
			
				// write to stdout
				std::cout << "    '" << trace::InstructionTraceGenerator::toString(funcUnits[n]) << "': ( " 
					<< dynamicCount << ", " << staticCount << ", " << activity << " )," << std::endl;
			}
		
			std::cout << "  },\n";
		}
		

	}
	std::cout << "}\n";

}

//////////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, char** argv ) {

	hydrazine::ArgumentParser parser( argc, argv );
	
	parser.description("Provides the ability to inspect a database created by" 
		+ std::string( "a InstructionTraceGenerator - output is in Python object notation on stdout" ) );
	
	bool help;
	bool list;
	bool instructions_by_kernel = false;
	bool instructions_by_app = false;
	std::string database;

	parser.parse( "-h", help, false, "Print this help message." );
	parser.parse( "-i", database, "traces/database.trace", "Path to database file." );
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

