/*!
	\file InstructionTraceAnalyzer.cpp
	\author Andrew Kerr
	\date Jan 2010
	\brief The header file for the InstructionTraceAnalyzer class
*/

// C++ stdlib includes
#include <map>
#include <set>
#include <deque>
#include <iostream>
#include <fstream>
#include <cfloat>

// Ocelot includes
#include <traces/interface/InstructionTraceAnalyzer.h>
#include <traces/interface/InstructionTraceGenerator.h>

// Hydrazine includes
#include <hydrazine/interface/ArgumentParser.h>
#include <hydrazine/interface/Exception.h>

// Boost includes
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

#undef REPORT_BASE
#define REPORT_BASE 1

//////////////////////////////////////////////////////////////////////////////////////////////////

static const char * toString(boost::archive::archive_exception::exception_code code) {
	switch (code) {
    case boost::archive::archive_exception::unregistered_class:
			return "unregistered_class";
    case boost::archive::archive_exception::invalid_signature:
			return "invalid_signature";
    case boost::archive::archive_exception::unsupported_version:
			return "unsupported_version";
    case boost::archive::archive_exception::pointer_conflict:
			return "pointer_conflict";
    case boost::archive::archive_exception::incompatible_native_format:
			return "incompatible_native_format";
    case boost::archive::archive_exception::array_size_too_short:
			return "array_size_too_short";
		/*
    case boost::archive::archive_exception::stream_error:
			return "stream_error";
			*/
    case boost::archive::archive_exception::invalid_class_name:
			return "invalid_class_name";
    case boost::archive::archive_exception::unregistered_cast:
			return "unregistered_cast";
		default:
			break;
	}
	return "boost::archive::archive_exception::exception_code_invalid";
}

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
	const trace::InstructionTraceGenerator::FunctionalUnitCountMap &count, bool appendStatic) {
	
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
//					appCounter[count_it->first][oc_it->first].activity *= appCounter[count_it->first][oc_it->first].dynamic_count;
				}
				else {
					appCounter[count_it->first][oc_it->first].dynamic_count += oc_it->second.dynamic_count;
					if (appendStatic) {
						appCounter[count_it->first][oc_it->first].static_count += oc_it->second.static_count;
					}
					appCounter[count_it->first][oc_it->first].activity += oc_it->second.activity /** oc_it->second.dynamic_count*/;
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
void trace::InstructionTraceAnalyzer::instructions_by_application(bool pyList) const {

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

		std::set< std::string > visitedKernels;
		
		std::string program = vector->first;
		const KernelVector & kernels = vector->second;
		InstructionTraceGenerator::FunctionalUnitCountMap appCounter;

		// loop over the kernels
		for (KernelVector::const_iterator k_it = kernels.begin(); k_it != kernels.end(); ++k_it) {
			InstructionTraceGenerator::Header header;
			report("Open header file " << k_it->header.c_str());
			std::ifstream hstream( k_it->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );
			InstructionTraceGenerator::FunctionalUnitCountMap counter;

			try {
				harchive >> header;
				assert(header.format == TraceGenerator::InstructionTraceFormat);
				harchive >> counter;
			}
			catch (boost::archive::archive_exception &exp) {
				std::cout << "### Exception: application '" << program << "' kernel '" << k_it->name << "' ";
				std::cout << " (exception code: " << toString(exp.code) << ") - stream: '" << k_it->header.c_str() << "'\n";
				continue;
			}

	
			// aggregate counts
			append(appCounter, counter, visitedKernels.find(k_it->name) == visitedKernels.end());
			visitedKernels.insert(k_it->name);
		}

		std::stringstream ssDynamic, ssStatic, ssDynamicComments, ssStaticComments;
		
		if (pyList) {
			ssDynamic << " '" << program << "': [";
			ssStatic <<  " '" << program << "': [";
		}
		else {
			// print the program name
			std::cout << "  '" << program << "': {" << std::endl;
		}

		size_t totalDynamicCount = 0;
		size_t totalStaticCount = 0;
		double totalActiveCount = 0;

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

			totalDynamicCount += dynamicCount;
			totalStaticCount += staticCount;
			totalActiveCount += activity;

			if(dynamicCount != 0)
				activity /= (double)dynamicCount;
			
			if (pyList) {
				ssDynamic << (n ? ", " : " ") << dynamicCount;
				ssStatic << (n ? ", " : " ") << staticCount;
				ssDynamicComments << " " << trace::InstructionTraceGenerator::toString(funcUnits[n]);
				ssStaticComments << " " << trace::InstructionTraceGenerator::toString(funcUnits[n]);
			}
			else {
				// write to stdout
				std::cout << "    '" << trace::InstructionTraceGenerator::toString(funcUnits[n]) << "': ( " 
					<< dynamicCount << ", " << staticCount << ", " << activity << " )," << std::endl;
			}
		}

		if (pyList) {
			std::cout << "# " << program << " sequence: " << ssDynamicComments.str() << "\n";
			std::cout << ssDynamic.str() << " ]  # dynamic\n";
			std::cout << ssStatic.str() << " ]  # static\n";
		}

		if(totalDynamicCount != 0)
			totalActiveCount /= (double)totalDynamicCount; 
		std::cout << "    '" << "total" << "': ( " 
			<< totalDynamicCount << ", " << totalStaticCount << ", " << totalActiveCount << " )," << std::endl;

		std::cout << "  },\n";
	}
	std::cout << "}\n";
}

void trace::InstructionTraceAnalyzer::instructions_by_kernel(bool pyList) const {


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

		std::map< std::string, int > kernelCount;
		
		for (KernelVector::const_iterator k_it = kernels.begin(); k_it != kernels.end(); ++k_it) {
			if (kernelCount.find(k_it->name) == kernelCount.end()) {
				kernelCount[k_it->name] = 0;
				std::cout << "  '" << program << ":" << k_it->name << "',\n";
			}
			kernelCount[k_it->name] ++;
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
		std::map< std::string, int > kernelCount;

		// loop over the kernels
		for (KernelVector::const_iterator k_it = kernels.begin(); k_it != kernels.end(); ++k_it) {
			InstructionTraceGenerator::Header header;
			std::ifstream hstream( k_it->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );

			if (kernelCount.find(k_it->name) == kernelCount.end()) {
				kernelCount[k_it->name] = 0;
			}

			InstructionTraceGenerator::FunctionalUnitCountMap counter;
	
			try {
				harchive >> header;
				assert(header.format == TraceGenerator::InstructionTraceFormat);
			
				harchive >> counter;
			}
			catch (boost::archive::archive_exception &exp) {
				std::cout << "### boost::archive::archive_exception: application '" << program << "' kernel '" << k_it->name << "' ";
				std::cout << " (exception code: " << toString(exp.code) << ") - stream: '" << k_it->header.c_str() << "'\n";
				continue;
			}

			// print the program name
			std::cout << "  '" << program << ":" << k_it->name << ":" << kernelCount[k_it->name] << "': {" << std::endl;
			
			std::cout << "    'blockDim': [" << header.blockDim.x << ", " << header.blockDim.y << ", " << header.blockDim.z << "],\n";
			std::cout << "    'gridDim': [" << header.gridDim.x << ", " << header.gridDim.y << ", " << header.gridDim.z << "],\n";
		
			kernelCount[k_it->name] ++;
			size_t totalDynamicCount = 0;
			size_t totalStaticCount = 0;
			double totalActivity = 0;

			// print out one bar per functional unit
			for (int n = 0; funcUnits[n] != InstructionTraceGenerator::FunctionalUnit_invalid; n++) {		

				size_t dynamicCount = 0;
				size_t staticCount = 0;
				double activity = 0;
//				int activeFU = 0;
			
				typedef trace::InstructionTraceGenerator::OpcodeCountMap OC;
				for (OC::iterator op_it = counter[funcUnits[n]].begin(); op_it != counter[funcUnits[n]].end();
					++op_it) {
				
					dynamicCount += op_it->second.dynamic_count;
					staticCount += op_it->second.static_count;
					
					if (op_it->second.dynamic_count) {
						activity += op_it->second.activity;
//						activeFU++;
					}
				}

				totalDynamicCount += dynamicCount;
				totalStaticCount += staticCount;
				totalActivity += activity;
			
//				if (activeFU) {
//					activity /= (double)activeFU;
//				}
				if(dynamicCount)
					activity /= (double)dynamicCount;
			
				// write to stdout
				std::cout << "    '" << trace::InstructionTraceGenerator::toString(funcUnits[n]) << "': ( " 
					<< dynamicCount << ", " << staticCount << ", " << activity << " )," << std::endl;
			}
			if(totalDynamicCount)
				totalActivity /= (double)totalDynamicCount;
			std::cout << "    '" << "total" << "': ( " 
				<< totalDynamicCount << ", " << totalStaticCount << ", " << totalActivity << " )," << std::endl;
		
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
	bool pyList = false;
	std::string database;

	parser.parse( "-h", help, false, "Print this help message." );
	parser.parse( "-i", database, "traces/database.trace", "Path to database file." );
	parser.parse( "-a", instructions_by_app, false,
		"Compute instruction histogram for each application over all its kernels");
	parser.parse( "-k", instructions_by_kernel, false,
		"Compute instruction histogram for each kernel" );
	parser.parse( "-l", list, false, "List all traces in the database." );
	parser.parse( "-r", pyList, false, "Print results as a Python list rather than Pyson");
		
	if( help ) {
		std::cout << parser.help();
		return 0;
	}
	
	trace::InstructionTraceAnalyzer analyzer( database );
	
	if( list ) {
		analyzer.list();	
	}
	
	if( instructions_by_kernel ) {
		analyzer.instructions_by_kernel(pyList);
	}

	if( instructions_by_app ) {
		analyzer.instructions_by_application(pyList);
	}
	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

