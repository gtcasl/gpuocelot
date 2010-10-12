/*! \file MemoryTraceAnalayzer.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief Implements an analysis tool for analyzing memory traces
*/

#ifndef MEMORY_TRACE_ANALYZER_H_INCLUDED
#define MEMORY_TRACE_ANALYZER_H_INCLUDED

#include <traces/interface/MemoryTraceGenerator.h>

#include <deque>
#include <string>
#include <map>

namespace trace
{

	class KernelData {
	public:
		KernelEntry kernel;
		MemoryTraceGenerator::Header header;
	};

	typedef std::vector< KernelData > KernelDataVector;

	class ApplicationData {
	public:
		std::string name;

		KernelDataVector kernels;
	};

	typedef std::map< std::string, ApplicationData > ApplicationMap;

	/*!
		\brief Provides the ability to inspect a database created by a MemoryTraceGenerator
	*/
	class MemoryTraceAnalyzer {
	public:
		typedef std::deque< KernelEntry > KernelVector;
		
	private:
		KernelVector _kernels; //! Entries for the kernel traces
	
	public:
	
		/*!
			\brief The constructor loads a database
		*/
		MemoryTraceAnalyzer(const std::string& database);
		
		/*!
			\brief List all of the kernel traces contained in the database.
			
			Print the results to stdout
		*/
		void list(bool machine=false) const;
		
		/*!
			Produces a comma-separated value of a histogram with a given segment size
			for each selected address space.
			
			\param prefix value to prefix each file name - _<space> is affixed to filename
			\param bin_size_pow2 (1 << bin_size_pow2) specifies number of bytes in each bin
		*/
		void histogram(std::string prefix = "memory", int bin_size_pow2 = 6);
		
		/*!
			Over all kernels, determines the number of global memory transactions needed to
			satisfy all ld and st instructions if the warp_size is given. Uses CUDA compute capability
			1.2 memory coalescing protocol.
		*/
		void global_transactions(int warp_size = 32, bool machine=false);
		
		/*!
			Presents intensity of accesses to global memory [tex, ld, st]
			
			\param machine flag to indicate whether output is meant to be machine-readable by
			the plotting tools or human-readable
		*/
		void global_access_fraction(bool machine=false);
		
		/*!

		*/
		void kernel_level_overlapped_global_memory(int segmentSize_pow2);
		
		/*!

		*/
		void application_list(bool filter = false);

		/*!
		
		*/
		void application_level_overlapped_global_memory(int segmentSize_pow2);

		void application_overlapped(ApplicationData application, int segmentSize_pow2);
		
	public:
	
		std::string spaces;
		
		bool verbose;
	};

}

int main( int argc, char** argv );

#endif

