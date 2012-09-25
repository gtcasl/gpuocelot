/*!
	\file BranchTraceAnalayzer.cpp
	\author Gregory Diamos
	\date Monday April 13, 2009
	\brief The source file for the BranchTraceAnalayzer class
*/

#ifndef BRANCH_TRACE_ANALYZER_CPP_INCLUDED
#define BRANCH_TRACE_ANALYZER_CPP_INCLUDED

#include <traces/interface/BranchTraceAnalyzer.h>
#include <hydrazine/interface/ArgumentParser.h>
#include <hydrazine/interface/Exception.h>
#include <fstream>
#include <cfloat>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>


namespace trace
{

	BranchTraceAnalyzer::BranchTraceAnalyzer( 
		const std::string& database )
	{
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
			if( entry.format == TraceGenerator::BranchTraceFormat )
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
	
	void BranchTraceAnalyzer::list() const
	{
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
	
	void BranchTraceAnalyzer::divergence() const
	{
		long long unsigned int totalDivergence = 0;
		long long unsigned int totalBranches = 0;
		long long unsigned int totalInstructions = 0;
		long long unsigned int totalKernels = 0;
		double averageActive = 0;
		double averageThreads = 0;

		for( KernelMap::const_iterator vector = _kernels.begin(); 
			vector != _kernels.end(); ++vector ) 
		{	
			long long unsigned int localDivergence = 0;
			long long unsigned int localBranches = 0;
			long long unsigned int localInstructions = 0;
			double localActive = 0;
			double localThreads = 0;
		
			std::cout << "Program " << vector->first << "\n\n";
		
			for( KernelVector::const_iterator kernel = vector->second.begin(); 
				kernel != vector->second.end(); ++kernel )	
			{
				std::ifstream hstream( kernel->header.c_str() );
				boost::archive::text_iarchive harchive( hstream );
			
				BranchTraceGenerator::Header header;
			
				harchive >> header;
				assert( header.format == TraceGenerator::BranchTraceFormat );
			
				hstream.close();

				unsigned int divergence = header.divergent;
			
				std::cout << " From file " << kernel->path << "\n";
				std::cout << "  kernel: " << kernel->name << "\n";
				std::cout << "  module: " << kernel->module << "\n";
				std::cout << "  statistics:\n";
				std::cout << "   max branch depth: " 
					<< header.maxContextStackSize << "\n";
				std::cout << "   average branch depth: " 
					<< ((float)header.totalContextStackSize / header.instructions)
					<< "\n";
				std::cout << "   branches: " << header.branches << "\n";
				std::cout << "   instructions: " << header.instructions << "\n";

				localBranches += header.branches;
			
				double active = ( ( header.activeThreads * 100.0 ) 
					/ ( header.instructions * header.threads + DBL_EPSILON ) );
			
				std::cout << "   threads : " << header.threads << "\n";		
				std::cout << "   divergent branches: " 
					<< ( ( divergence * 100.0 ) 
					/ ( header.branches + DBL_EPSILON ) ) << "%\n";
				std::cout << "   average active: " << active << "%\n\n";

				localActive = ( localActive * localInstructions 
					+ active * header.instructions ) 
					/ ( localInstructions + header.instructions );
				localThreads = ( localThreads * localInstructions 
					+ header.threads * header.instructions ) 
					/ ( localInstructions + header.instructions );
				localDivergence += divergence;
				localInstructions += header.instructions;
									
			}
		
			averageActive = ( averageActive * totalInstructions 
				+ localActive * localInstructions ) 
				/ ( totalInstructions + localInstructions );
			averageThreads = ( averageThreads * totalInstructions 
				+ localThreads * localInstructions ) 
				/ ( totalInstructions + localInstructions );
			totalDivergence += localDivergence;
			totalInstructions += localInstructions;
			totalBranches += localBranches;
			totalKernels += vector->second.size();

			std::cout << "Program " << vector->first << " statistics:\n";
			std::cout << " kernels: " << vector->second.size() << "\n";
			std::cout << " instructions: " << localInstructions << "\n";
			std::cout << " branches: " << localBranches << "\n";
			std::cout << " average threads: " << localThreads << "\n";
			std::cout << " divergent branches: " 
				<< ( ( localDivergence * 100.0 ) 
				/ ( localBranches + DBL_EPSILON ) ) << "%\n";
			std::cout << " average active: " << localActive	<< "%\n\n";
		
		}
		
		std::cout << "Aggregate statistics:\n";
		std::cout << " total kernels: " << totalKernels << "\n";
		std::cout << " total instructions: " << totalInstructions << "\n";
		std::cout << " total branches: " << totalBranches << "\n";
		std::cout << " average threads: " << averageThreads << "\n";
		std::cout << " divergent branches: " << ( ( totalDivergence * 100.0 ) 
			/ ( totalBranches + DBL_EPSILON ) ) << "%\n";
		std::cout << " average active: " << averageActive	<< "%\n\n";
	}
	
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	
	parser.description("Provides the ability to inspect a database created by" 
		+ std::string( "a BranchTraceGenerator" ) );
	
	bool help;
	bool list;
	bool divergence;
	std::string database;

	parser.parse( "-h", help, false, "Print this help message." );

	parser.parse( "-l", list, false, "List all traces in the database." );
	parser.parse( "-d", divergence, false,
		"Compute branch divergence for each trace." );

	parser.parse( "-i", database, "traces/database.trace", 
		"Path to database file." );
		
	if( help )
	{
		std::cout << parser.help();
		return 0;
	}
	
	trace::BranchTraceAnalyzer analyzer( database );
	
	if( list )
	{
		analyzer.list();	
	}
	
	if( divergence )
	{
		analyzer.divergence();
	}
	
	return 0;

}

#endif

