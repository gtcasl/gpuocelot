/*!
	\file ParallelismTraceAnalyzer.cpp
	
	\author Gregory Diamos
	\date Monday April 13, 2009
	
	\brief The source file for the ParallelismTraceAnalayzer class
*/

#ifndef PARALLELISM_TRACE_ANALYZER_CPP_INCLUDED
#define PARALLELISM_TRACE_ANALYZER_CPP_INCLUDED

#include <traces/interface/ParallelismTraceAnalyzer.h>
#include <hydrazine/interface/ArgumentParser.h>
#include <hydrazine/interface/Exception.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <fstream>
#include <cfloat>
#include <set>
#include <vector>

namespace trace
{

	ParallelismTraceAnalyzer::ParallelismTraceAnalyzer( 
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
			if( entry.format == TraceGenerator::ParallelismTraceFormat )
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
	
	void ParallelismTraceAnalyzer::list() const
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
				std::cout << "  " << kernel->path << "\n";
			}
		}
			
		std::cout << "\n";
	}
	
	void ParallelismTraceAnalyzer::parallelism() const
	{
	
		typedef std::vector< ParallelismTraceGenerator::Event > EventVector;
		typedef std::set< long long unsigned int > InstructionSet;
	
		double averageSIMD = 0;
		double averageMIMD = 0;
		double averageCTAs = 0;
		
		for( KernelMap::const_iterator vector = _kernels.begin(); 
			vector != _kernels.end(); ++vector ) 
		{
			std::cout << " From program \"" << vector->first << "\".\n";

			double localSIMD = 0;
			double localMIMD = 0;
			double localCTAs = 0;

			for( KernelVector::const_iterator kernel = vector->second.begin(); 
				kernel != vector->second.end(); ++kernel )	
			{

				std::ifstream hstream( kernel->header.c_str() );
				boost::archive::text_iarchive harchive( hstream );
			
				ParallelismTraceGenerator::Header header;
			
				harchive >> header;
				assert( header.format 
					== TraceGenerator::ParallelismTraceFormat );
			
				hstream.close();

				std::ifstream stream( kernel->path.c_str() );
			
				if( !stream.is_open() )
				{
					throw hydrazine::Exception(
						"Failed to open ParallelismTrace kernel trace file " 
						+ kernel->path );
				}
			
				boost::archive::text_iarchive archive( stream );
			
				EventVector events( header.dimensions );
			
				for( EventVector::iterator event = events.begin(); 
					event != events.end(); ++event )
				{
					archive >> *event;
				}

				std::cout << " From file " << kernel->path << "\n";
				std::cout << "  kernel: " << kernel->name << "\n";
				std::cout << "  module: " << kernel->module << "\n";
				std::cout << "  statistics:\n";
				std::cout << "   ctas: " << header.dimensions << "\n";
				std::cout << "   threads: " << header.threads << "\n";
			
				InstructionSet instructions;
				long long unsigned int totalInstructions = 0;
				double activity = 0;
			
				for( EventVector::iterator event = events.begin(); 
					event != events.end(); ++event )
				{
					totalInstructions += event->instructions;
					instructions.insert( event->instructions );
					activity += event->activity * event->instructions;
				
				}
			
				activity /= totalInstructions + DBL_EPSILON;
			
				unsigned int previous = 0;
				unsigned int count = header.dimensions;
				double mimd = 0;
			
				for( InstructionSet::iterator 
					instruction = instructions.begin();
					instruction != instructions.end(); ++instruction )
				{
					mimd += (*instruction - previous) * count;
					previous = *instruction;
					--count;
				}
			
				if( !instructions.empty() )
				{
					mimd /= *(--instructions.end()) + DBL_EPSILON;
				}
				
				std::cout << "   SIMD parallelism: " << activity 
					<< "\n";		
				std::cout << "   MIMD parallelism: " << mimd << "\n";
			
				localSIMD += activity;
				localMIMD += mimd;
				localCTAs += header.dimensions;
			
			}

			localSIMD /= vector->second.size() + DBL_EPSILON;
			localMIMD /= vector->second.size() + DBL_EPSILON;
			localCTAs /= vector->second.size() + DBL_EPSILON;

			std::cout << " Kernel " << vector->first << " statistics:\n";
			std::cout << "  average CTAs: " << localCTAs << "\n";
			std::cout << "  average SIMD parallelism: " << localSIMD << "\n";
			std::cout << "  average MIMD parallelism: " << localMIMD << "\n";
			
			averageSIMD += localSIMD;
			averageMIMD += localMIMD;
			averageCTAs += localCTAs;
		}
				
		averageSIMD /= _kernels.size() + DBL_EPSILON;
		averageMIMD /= _kernels.size() + DBL_EPSILON;
		averageCTAs /= _kernels.size() + DBL_EPSILON;
		
		std::cout << "Aggregate statistics:\n";
		std::cout << " average CTAs: " << averageCTAs << "\n";
		std::cout << " average SIMD parallelism: " << averageSIMD << "\n";
		std::cout << " average MIMD parallelism: " << averageMIMD << "\n";
	}
	
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	
	parser.description("Provides the ability to inspect a database created by" 
		+ std::string( "a BranchTraceGenerator" ) );
	
	bool help;
	bool list;
	bool parallelism;
	std::string database;

	parser.parse( "-h", help, false, "Print this help message." );

	parser.parse( "-l", list, false, "List all traces in the database." );
	parser.parse( "-p", parallelism, false, 
		"Compute parallelism for each trace." );

	parser.parse( "-i", database, "traces/database.trace", 
		"Path to database file." );
		
	if( help )
	{
		std::cout << parser.help();
		return 0;	
	}
	
	trace::ParallelismTraceAnalyzer analyzer( database );
	
	if( list )
	{
		analyzer.list();	
	}
	
	if( parallelism )
	{
		analyzer.parallelism();
	}
	
	return 0;

}

#endif

