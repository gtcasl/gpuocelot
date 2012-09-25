/*!
	\file SharedComputationAnalyzer.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\brief Implementation of an analysis tool for shared computation traces
*/

//////////////////////////////////////////////////////////////////////////////////////////////////

#include <traces/interface/SharedComputationAnalyzer.h>

#include <ocelot/ir/interface/PTXInstruction.h>
#include <hydrazine/interface/ArgumentParser.h>
#include <hydrazine/interface/Exception.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <fstream>
#include <cfloat>

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::SharedComputationAnalyzer::~SharedComputationAnalyzer( ) {

}

trace::SharedComputationAnalyzer::SharedComputationAnalyzer(const std::string& database) {
	std::ifstream stream(database.c_str());
	
	if( !stream.is_open() )
	{
		throw hydrazine::Exception("Could not open database file " 
			+ database);
	}
	
	unsigned int count;
	
	boost::archive::text_iarchive archive(stream);
	archive >> count;
	
	for( unsigned int i = 0; i < count; ++i )
	{
		KernelEntry entry;
		archive >> entry;
		if( entry.format == TraceGenerator::SharedComputationTraceFormat )
		{
			KernelMap::iterator kernel = _kernels.find( entry.program );
			if( kernel == _kernels.end() )
			{
				kernel = _kernels.insert( std::make_pair( 
					entry.program, KernelVector() ) ).first;
			}
			kernel->second.push_back( entry );
		}
	}
}

void trace::SharedComputationAnalyzer::list() const {
	std::cout << "There are " << _kernels.size() 
		<< " programs referenced in the database\n";

	for( KernelMap::const_iterator vector = _kernels.begin(); 
		vector != _kernels.end(); ++vector ) 
	{
		std::cout << " Program \"" << vector->first << "\" contains " 
			<< vector->second.size() << " kernels.\n";
		for( KernelVector::const_iterator kernel = vector->second.begin(); 
			kernel != vector->second.end(); ++kernel )	
		{
			std::cout << "  " << kernel->header << "\n";
		}
	}
		
	std::cout << "\n";
}

/*!
	Prints shared computation statistics for each kernel and aggreages the result.
*/
void trace::SharedComputationAnalyzer::shared_computation(bool machine_readable) {
	using namespace ir;
	using namespace std;
	
	ostream &out = cout;
	
	PTXU64 agg_storeCount = 0;
	PTXU64 agg_loadCount = 0;
	PTXU64 agg_crossLdCount = 0;
	PTXU64 agg_Instr = 0;

	out << "sharedComputation = (\n";
	
	// iterates over kernels in archive
	for( KernelMap::const_iterator application = _kernels.begin(); 
		application != _kernels.end(); ++application ) {

		PTXU64 app_storeCount = 0;
		PTXU64 app_loadCount = 0;
		PTXU64 app_crossLdCount = 0;
		PTXU64 app_Instr = 0;
		
		for( KernelVector::const_iterator kernel = application->second.begin(); 
			kernel != application->second.end(); ++kernel)	{
		
			std::ifstream hstream( kernel->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );
	
			SharedComputationGenerator::Header header;
	
			harchive >> header;
			assert( header.format == TraceGenerator::SharedComputationTraceFormat );
		
			hstream.close();	
	
			agg_storeCount += header.storeSharedCount;
			agg_loadCount += header.loadSharedCount;
			agg_crossLdCount += header.crossThreadLds;
			agg_Instr += header.dynamic_instructions;

			app_storeCount += header.storeSharedCount;
			app_loadCount += header.loadSharedCount;
			app_crossLdCount += header.crossThreadLds;
			app_Instr += header.dynamic_instructions;

			if (machine_readable) {
				out << "\t('" << kernel->name << "' , " << header.storeSharedCount << " , " 
					<< header.loadSharedCount << " , " << header.crossThreadLds
					<< " , " << header.dynamic_instructions << "),\n";
			}
			else {
				out << "Kernel " << kernel->name << "\n";
				out << "           st.shared count: " << header.storeSharedCount << "\n";
				out << "           ld.shared count: " << header.loadSharedCount << "\n";
				out << "  x-thread ld.shared count: " << header.crossThreadLds << "\n";
				if (header.loadSharedCount) {
					out << "                fraction: " 
						<< (double)header.crossThreadLds 
						/ (double)header.loadSharedCount << "\n";
				}
			}
		}	// end for(kernels)

		if (machine_readable) {
			// (kernelName, storeCount, loadCount, xCtaLdCount, dynamic_instructions) = result
			out << "\t( '" << application->first << "' , " << app_storeCount 
				<< " , " << app_loadCount << " , " << app_crossLdCount 
				<< " , " << app_Instr << ")\n";
		}
		else {
			out << "\n" << application->first << "Aggregate:\n";
			out << "  st.shared count: " << app_storeCount << "\n";
			out << "  ld.shared count: " << app_loadCount << "\n";
			out << "   x-thread count: " << app_crossLdCount << "\n";
			if (app_loadCount) {
				out << "         fraction: " << (double)app_crossLdCount 
					/ (double)app_loadCount << "\n";
			}
		}
	
	}
	
	if (machine_readable) {
		// (kernelName, storeCount, loadCount, xCtaLdCount, dynamic_instructions) = result
		out << "\t( 'aggregate' , " << agg_storeCount << " , " << agg_loadCount << " , " << agg_crossLdCount 
			<< " , " << agg_Instr << ")\n";
		out << ")\n\n";
	}
	else {
		out << "\nAggregate:\n";
		out << "  st.shared count: " << agg_storeCount << "\n";
		out << "  ld.shared count: " << agg_loadCount << "\n";
		out << "   x-thread count: " << agg_crossLdCount << "\n";
		if (agg_loadCount) {
			out << "         fraction: " << (double)agg_crossLdCount / (double)agg_loadCount << "\n";
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, char** argv) {
	using namespace std;
	
	hydrazine::ArgumentParser parser( argc, argv );
	
	parser.description("Provides the ability to inspect and analyze a database created by" 
		+ std::string( " a MemoryTraceGenerator" ) );
	
	bool list = false;
	bool verbose = false;
	bool shared = false;
	bool machine_readable = false;

	string database;

	parser.parse( "-l", list, false, "List all traces in the database." );
	parser.parse( "-i", database, 
		"traces/database.trace", "Path to database file." );
	parser.parse( "-v", verbose, false, 
		"Prints an unmanagable amount of information.");

	parser.parse( "-s", shared, false, 
		"Examines traces from each kernel and determines the number of cross-thread words shared");
	parser.parse( "-m", machine_readable, false, 
		" Indicates output must be machine-readable");
	parser.parse();
	
	trace::SharedComputationAnalyzer analyzer( database );
	analyzer.verbose = verbose;
	
	if (list) {
		analyzer.list();
	}
	if (shared) {
		analyzer.shared_computation(machine_readable);
	}

	return 0;
}

