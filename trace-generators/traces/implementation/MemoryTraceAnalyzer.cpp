/*!
	\file MemoryTraceAnalayzer.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\brief Implementation of an analysis tool for memory traces
*/

#ifndef MEMORY_TRACE_ANALYZER_CPP_INCLUDED
#define MEMORY_TRACE_ANALYZER_CPP_INCLUDED

#include <ocelot/ir/interface/PTXInstruction.h>
#include <traces/interface/MemoryTraceAnalyzer.h>
#include <hydrazine/interface/ArgumentParser.h>
#include <hydrazine/interface/Exception.h>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>
#include <fstream>
#include <cfloat>
#include <unordered_map>

namespace trace {

	/*!
		Gets a list of all applications and their kernels in the order in which the kernels are called.

		If filter is true, only those applications in which some kernel is called more than once are
		returned.
	*/
	ApplicationMap GetApplications(MemoryTraceAnalyzer::KernelVector _kernels, bool filter) {
		using namespace std;
		
		ApplicationMap applications;

		for(MemoryTraceAnalyzer::KernelVector::const_iterator kernel = _kernels.begin(); 
			kernel != _kernels.end(); ++kernel)	{
		
			// open the kernel's archive and visit every ld/st instruction
			std::ifstream hstream( kernel->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );
		
			MemoryTraceGenerator::Header header;
		
			harchive >> header;
			assert( header.format == TraceGenerator::MemoryTraceFormat );
			hstream.close();	
		
			KernelData data;
			data.kernel = *kernel;
			data.header = header;
		
			applications[ kernel->program ].kernels.push_back( data );
			applications[ kernel->program ].name = kernel->program;
		}

		if (filter) {
			ApplicationMap applications_out;	
			for (ApplicationMap::iterator fi = applications.begin(); 
				fi != applications.end(); ++fi) {
				bool print = false;
				map< string, int > kernelCalls;
				for (int j = 0; j < (int)fi->second.kernels.size(); j++) {
					string name = fi->second.kernels[j].kernel.name;
					if (kernelCalls.find(name) == kernelCalls.end()) {
						kernelCalls[name] = 1;
					}
					else {
						print = true;
						kernelCalls[name]++;
					}
				}
				if (print) {
					applications_out.insert( *fi );
				}
			}
			return applications_out;
		}

		return applications;
	}
}

namespace trace
{

	MemoryTraceAnalyzer::MemoryTraceAnalyzer( 
		const std::string& database ) {
		std::ifstream stream(database.c_str());
		verbose = false;
		
		if (!stream.is_open()) {
			throw hydrazine::Exception("Could not open database file " 
				+ database);
		}
		
		unsigned int count;
		
		boost::archive::text_iarchive archive(stream);
		archive >> count;
		
		for( unsigned int i = 0; i < count; ++i) {
			KernelEntry entry;
			archive >> entry;
			if(entry.format == TraceGenerator::MemoryTraceFormat) {
				_kernels.push_back(entry);
			}
		}
	}
	
	void MemoryTraceAnalyzer::list(bool machine) const {
		using namespace std;
		if (machine) {
			cout << "(\n";
			for(KernelVector::const_iterator kernel = _kernels.begin(); 
				kernel != _kernels.end(); ++kernel)	{
			
				cout << "\t  '" << kernel->name << "',\n";
			}
			cout << "\t),\n";
		}
		else {
			std::cout << "There are " << _kernels.size() 
				<< " kernels referenced in the database\n";
			
			for( KernelVector::const_iterator kernel = _kernels.begin(); 
				kernel != _kernels.end(); ++kernel)	{
			
				std::cout << " " << kernel->path << "\n";
			}
			std::cout << "\n";
		}
	}

	/*!
		Produces a comma-separated value of a histogram with a given segment size
		for each selected address space aggregated across kernels.
		
		\param prefix value to prefix each file name - _<space> is affixed to filename
		\param bin_size_pow2 (1 << bin_size_pow2) specifies number of bytes in each bin

	*/
	void MemoryTraceAnalyzer::histogram(std::string prefix, int bin_size_pow2) {
		using namespace std;
		typedef std::map< ir::PTXU64, ir::PTXU64 > Histogram; 

		map< ir::PTXInstruction::AddressSpace, ir::PTXU64 > addressMask;
		map< ir::PTXInstruction::AddressSpace, Histogram > histograms;
		for (unsigned int i = 0; i < (unsigned int)spaces.size(); i++) {
			// cglspt
			ir::PTXInstruction::AddressSpace 
				space = ir::PTXInstruction::AddressSpace_Invalid;
			switch (spaces[i]) {
				case 'c': space = ir::PTXInstruction::Const; break;
				case 'g': space = ir::PTXInstruction::Global; break;
				case 'l': space = ir::PTXInstruction::Local; break;
				case 's': space = ir::PTXInstruction::Shared; break;
				case 'p': space = ir::PTXInstruction::Param; break;
				case 't': space = ir::PTXInstruction::Texture; break;
				default:
					break;
			}
			histograms[space] = Histogram();
		}

		// enables of masking address bits
		addressMask[ir::PTXInstruction::Const] = ~(0);
		addressMask[ir::PTXInstruction::Global] = ~(0);
		addressMask[ir::PTXInstruction::Local] = ~(0);
		addressMask[ir::PTXInstruction::Shared] = (16384-1);
		addressMask[ir::PTXInstruction::Param] = ~(0);
		addressMask[ir::PTXInstruction::Texture] = ~(0);		
		
		// iterates over kernels in archive
		for( KernelVector::const_iterator kernel = _kernels.begin(); 
			kernel != _kernels.end(); ++kernel)	{
						
			// open the kernel's archive and visit every ld/st instruction
			std::ifstream hstream( kernel->header.c_str() );
			boost::archive::text_iarchive harchive( hstream );
		
			MemoryTraceGenerator::Header header;
		
			harchive >> header;
			assert( header.format == TraceGenerator::MemoryTraceFormat );
			hstream.close();	
		
			if( header.headerOnly )
			{
				std::stringstream error;
				error << "Trace for Kernel " << kernel->name 
					<< " was generated without support for recording " 
					<< "individual accesses requried for histogram generation.";
				throw hydrazine::Exception( error.str() );
			}
			
			std::ifstream stream( kernel->path.c_str() );
			boost::archive::text_iarchive archive( stream );
						
			for(; true; ) {
				try {
					MemoryTraceGenerator::Event event;
					archive >> event;

					if (histograms.find(event.addressSpace) != histograms.end()) {
						Histogram &hist = histograms[event.addressSpace];

						for (MemoryTraceGenerator::AccessVector::iterator acc_it = event.accesses.begin();
							acc_it != event.accesses.end(); ++acc_it) {

							ir::PTXU64 address = (acc_it->address & addressMask[event.addressSpace]);

							ir::PTXU64 binNumber = ((address >> bin_size_pow2) << bin_size_pow2);
							if (hist.find(binNumber) == hist.end()) {
								hist[binNumber] = 1;
							}
							else {
								++hist[binNumber];
							}

						}	// end for(accesses)
					}
				}
				catch( const boost::archive::archive_exception& e ) {
					break;			
				}
			}	// end for(events)

		}	// end for(kernels)

		// now emit the histogram
		for (map< ir::PTXInstruction::AddressSpace, Histogram >::iterator hist_it = histograms.begin();
			hist_it != histograms.end(); ++hist_it) {

			string filename = prefix + "_" + ir::PTXInstruction::toString(hist_it->first) + ".csv";
			std::ofstream file(filename.c_str());

			for (Histogram::iterator h_it = hist_it->second.begin(); h_it != hist_it->second.end(); ++h_it) {
				file << "0x" << hex << h_it->first << "," << dec << h_it->second << "\n";
			}
			hist_it->second.clear();
		}
	}
	
	void MemoryTraceAnalyzer::global_access_fraction(bool machine) {
		using namespace std;
		using namespace ir;
		
		PTXU64 agg_globalMemInstructions = 0;
		PTXU64 agg_globalMemWords = 0;
		PTXU64 agg_Instructions = 0;
		PTXU64 agg_Operations = 0;
		PTXU64 agg_Extent = 0;
		
		int kernelIndex = 0;

		if (machine) {
			cout << "memIntensity = (\n";
		}
		
		ApplicationMap applications = GetApplications(_kernels, false);
		
		for( ApplicationMap::const_iterator application = applications.begin(); 
			application != applications.end(); ++application ) {

			PTXU64 app_globalMemInstructions = 0;
			PTXU64 app_globalMemWords = 0;
			PTXU64 app_Instructions = 0;
			PTXU64 app_Operations = 0;
			PTXU64 app_Extent = 0;
			
			// iterates over kernels in archive
			for( KernelDataVector::const_iterator 
				kernel = application->second.kernels.begin(); 
				kernel != application->second.kernels.end(); 
				++kernel, ++kernelIndex )	{
			
				MemoryTraceGenerator::Header header = kernel->header;
		
			
				PTXU64 kernel_globalMemInstructions 
					= header.global_instructions + header.texture_instructions;
				PTXU64 kernel_globalMemWords = header.global_words 
					+ header.texture_words;
								
				// accumulate statistics over the aggregate of kernels
				agg_globalMemInstructions += kernel_globalMemInstructions;
				agg_Instructions += header.dynamic_instructions;
				agg_Operations += header.dynamic_operations;
				agg_globalMemWords += kernel_globalMemWords;
				agg_Extent += header.global_extent;

				app_globalMemInstructions += kernel_globalMemInstructions;
				app_Instructions += header.dynamic_instructions;
				app_Operations += header.dynamic_operations;
				app_globalMemWords += kernel_globalMemWords;	
				app_Extent += header.global_extent;				

				if (machine) {
					// kernel->name , kernel index , mem instructions , instructions , mem words , operations
					cout << "  (" << kernelIndex << " , '" << dec <<  kernel->kernel.name << "' , "
						<< kernel_globalMemInstructions << " , " 
						<< header.dynamic_instructions << " , "
						<< kernel_globalMemWords << " , " << header.dynamic_operations << "),\n";
				}
				else {
					cout << "Kernel " << kernel->kernel.name << dec << "\n";
					cout << "  texture ops " << header.texture_accesses << "\n";
					cout << "  module " << kernel->kernel.module << "\n";
					cout << "  path " << kernel->kernel.path << "\n";
					cout << "  mem instructions " << kernel_globalMemInstructions 
						<< "\n";
					cout << "  instructions " << header.dynamic_instructions 
						<< "\n";
					cout << "  extent " << header.global_extent << "\n";
					cout << "  memory instruction fraction " 
						<< (double)kernel_globalMemInstructions 
						/ (double)header.dynamic_instructions << "\n";
					cout << "  mem words " << kernel_globalMemWords << "\n";
					cout << "  operations " << header.dynamic_operations << "\n";
					cout << "  words / operations " << (double)kernel_globalMemWords
						/ (double)header.dynamic_operations << "\n";
				}
			
			}	// end for(kernels)

			if (machine) {
				cout << "  (0, '" << application->first << "' , "
					<< app_globalMemInstructions << " , " << app_Instructions << " , "
					<< app_globalMemWords << " , " << app_Operations << ")\n";
			}
			else {		
				cout << "\nAggregate for '" << application->first << "'\n";
				cout << "    mem instructions: " << app_globalMemInstructions << "\n";
				cout << "  extent: " 
					<< ( app_Extent / application->second.kernels.size() ) 
					<< "\n";
				cout << "  dynamic instructions: " << app_Instructions << "\n";
				cout << "    mem instr fraction: " << (double)app_globalMemInstructions / (double)agg_Instructions << "\n";
				cout << " glob mem words: " << app_globalMemWords << "\n";
				cout << "   operations: " << app_Operations << "\n";
				cout << "   words / operations: " << (double)app_globalMemWords / (double)agg_Operations << "\n";
			}
			

		}

		if (machine) {
			cout << "  (" << dec << kernelIndex << " , 'aggregate'"  << " , "
				<< agg_globalMemInstructions << " , " << agg_Instructions << " , "
				<< agg_globalMemWords << " , " << agg_Operations << ")\n";
			cout << ")\n\n";
		}
		else {		
			cout << "\nAggregate\n";
			cout << "    mem instructions: " << agg_globalMemInstructions << "\n";
			cout << "  dynamic instructions: " << agg_Instructions << "\n";
			cout << "  extent: " << ( agg_Extent / kernelIndex ) << "\n";
			cout << "    mem instr fraction: " << (double)agg_globalMemInstructions / (double)agg_Instructions << "\n";
			cout << " glob mem words: " << agg_globalMemWords << "\n";
			cout << "   operations: " << agg_Operations << "\n";
			cout << "   words / operations: " << (double)agg_globalMemWords / (double)agg_Operations << "\n";
		}
	}
	
	ir::PTXU64 next_power_two(ir::PTXU64 n) {
		n |= (n >> 1);
		n |= (n >> 2);
		n |= (n >> 4);
		n |= (n >> 8);
		n |= (n >> 16);
		n |= (n >> 32);
		return (n + 1);
	}
	
	/*!
		Over all kernels, determines the number of global memory transactions needed to
		satisfy all ld and st instructions if the warp_size is given. Uses CUDA compute capability
		1.2 memory coalescing protocol.
	*/
	void MemoryTraceAnalyzer::global_transactions(int warp_size, bool machine) {
		using namespace ir;
		
		std::ostream &out = std::cout;
		
		ir::PTXU64 global_instructions = 0;
		ir::PTXU64 global_halfwarps = 0;
		ir::PTXU64 global_transactions = 0;
		
		if (machine) {
			out << "memEfficiency = (\n";
		}

		ApplicationMap applications = GetApplications(_kernels, false);
		
		for( ApplicationMap::const_iterator application = applications.begin(); 
			application != applications.end(); ++application ) {

			ir::PTXU64 app_instructions = 0;
			ir::PTXU64 app_halfwarps = 0;
			ir::PTXU64 app_transactions = 0;
		
			for( KernelDataVector::const_iterator 
				kernel = application->second.kernels.begin(); 
				kernel != application->second.kernels.end(); ++kernel)	{
			
				MemoryTraceGenerator::Header header = kernel->header;
			
				ir::PTXU64 kernel_instructions 
					= header.global_instructions + header.texture_instructions;
				ir::PTXU64 kernel_halfwarps = header.halfwarps;
				ir::PTXU64 kernel_transactions = header.global_segments;
				ir::PTXU64 kernel_size = header.global_bytes + header.shared_bytes;
				ir::PTXU64 kernel_access_counter 
					= header.global_accesses + header.texture_accesses;
			
				global_instructions += kernel_instructions;
				global_halfwarps += kernel_halfwarps;
				global_transactions += kernel_transactions;

				app_instructions += kernel_instructions;
				app_halfwarps += kernel_halfwarps;
				app_transactions += kernel_transactions;
			
				if (machine) {
					// (kernelName, threadCount, instructions, halfwarps, transactions) = result
					out << "  ('" << kernel->kernel.name << "', " 
						<< header.thread_count << " , " 
						<< kernel_instructions << " , "
						<< kernel_halfwarps << " , " 
						<< kernel_transactions << "),\n";
				}
				else {
					// finish kernel
					out << "\nKernel " << kernel->kernel.name << "\n";
					out << "         thread count: " << header.thread_count << "\n";
					out << "  memory instructions: " << kernel_instructions << "\n"
							<< "            halfwarps: " << kernel_halfwarps << "\n"
							<< "         transactions: " << kernel_transactions << "\n";
					if (kernel_halfwarps) {
						out << "  average access size: " 
							<< (double)kernel_size / (double)kernel_access_counter 
							<< " bytes\n";
						out	<< "                  t/h: " 
							<< (double)kernel_transactions 
							/ (double)kernel_halfwarps << "\n";
					}
				}
			}
			// finished all kernels
			if (machine) {
				// (kernelName, threadCount, instructions, halfwarps, transactions) = result
				out << "  ('" << application->first << "', " << 0 << " , " 
					<< app_instructions << " , "
					<< app_halfwarps << " , " << app_transactions << "),\n";
			}
			else {
				out << "\nAggregate '" << application->first << "'results:\n";
				out << "            warp size: " << warp_size << "\n";
				out << "  memory instructions: " << app_instructions << "\n"
						<< "            halfwarps: " << app_halfwarps << "\n"
						<< "         transactions: " << app_transactions << "\n";
				if (app_halfwarps) {
					out << "                  t/h: " 
						<< (double)app_transactions 
						/ (double)app_halfwarps << "\n";
				}
			}
		}
				
		// finished all kernels
		if (machine) {
			// (kernelName, threadCount, instructions, halfwarps, transactions) = result
			out << "  ('SDK Average', " << 0 << " , " << global_instructions << " , "
				<< global_halfwarps << " , " << global_transactions << "),\n";
			out << ")\n\n";
		}
		else {
			out << "\nAggregate results:\n";
			out << "            warp size: " << warp_size << "\n";
			out << "  memory instructions: " << global_instructions << "\n"
					<< "            halfwarps: " << global_halfwarps << "\n"
					<< "         transactions: " << global_transactions << "\n";
			if (global_halfwarps) {
				out << "                  t/h: " 
					<< (double)global_transactions 
					/ (double)global_halfwarps << "\n";
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	For each kernel, examines how each CTA references the same memory segments
*/
void trace::MemoryTraceAnalyzer::kernel_level_overlapped_global_memory(int segmentSize_pow2) {
	using namespace ir;
	using namespace std;
	
	for( KernelVector::const_iterator kernel = _kernels.begin(); 
		kernel != _kernels.end(); ++kernel)	{
		
		// open the kernel's archive and visit every ld/st instruction
		std::ifstream hstream( kernel->header.c_str() );
		boost::archive::text_iarchive harchive( hstream );
		
		MemoryTraceGenerator::Header header;
		
		harchive >> header;
		assert( header.format == TraceGenerator::MemoryTraceFormat );
		hstream.close();	
		
		if( header.headerOnly )
		{
			std::stringstream error;
			error << "Trace for Kernel " << kernel->name 
				<< " was generated without support for recording " 
				<< "individual accesses requried for computing " 
				<< "kernel global memory overlaps.";
			throw hydrazine::Exception( error.str() );
		}
		
		std::ifstream stream( kernel->path.c_str() );
		boost::archive::text_iarchive archive( stream );
		
		if (!stream.is_open()) {
			throw hydrazine::Exception(
				"Failed to open MemoryTrace kernel trace file " 
				+ kernel->path );
		}
		
		PTXU64 globalWorkingSetSize = (header.global_max_address - header.global_min_address);
		PTXU64 globalSegmentCount = (globalWorkingSetSize >> segmentSize_pow2) +
			((globalWorkingSetSize & ((1<<segmentSize_pow2)-1)) ? 1 : 0);
		PTXS32 *globalSegmentOwners = new PTXS32[globalSegmentCount];
		
		for (PTXU64 n = 0; n < globalSegmentCount; n++) {
			globalSegmentOwners[n] = -1;
		}

		PTXU64 global_Lds = 0, 
			global_crossCta_Lds = 0,
			global_Sts = 0,
			global_OOB = 0;

		PTXU64 observed_min_address = 0, 
			observed_max_address = 0;
		
		while (true) {
			try {
				MemoryTraceGenerator::Event event;
				archive >> event;
				
				if (event.addressSpace == PTXInstruction::Global) {
					PTXS32 ctaID = event.ctaX + event.ctaY * header.blockDimX + 
						event.ctaZ * (header.blockDimX * header.blockDimY);

					for (MemoryTraceGenerator::AccessVector::const_iterator acc_it = event.accesses.begin();
						acc_it != event.accesses.end(); ++acc_it) {
					
						PTXU64 segmentNumber = ((acc_it->address - header.global_min_address) >> segmentSize_pow2);

						if (!observed_min_address || acc_it->address < observed_min_address) {
							observed_min_address = acc_it->address;
						}
						if (!observed_max_address || acc_it->address > observed_max_address) {
							observed_max_address = acc_it->address;
						}
						
						if (segmentNumber < globalSegmentCount) {
							if (event.opcode == PTXInstruction::St) {
								for (PTXU64 n = 0; n < (PTXU64)acc_it->size; n++) {
									PTXU64 seg = (((acc_it->address + n) - header.global_min_address) >> segmentSize_pow2);
									globalSegmentOwners[seg] = ctaID;
								}
								++global_Sts;
							}
							else if (event.opcode == PTXInstruction::Ld) {
								if (globalSegmentOwners[segmentNumber] >= 0 && globalSegmentOwners[segmentNumber] != ctaID) {
									// event of interest
									//
									// record statistics
									++global_crossCta_Lds;
								}
								++global_Lds;
							}
						}
						else {
							// bad news
							++ global_OOB;
						}
					}
				}
			}
			catch( const boost::archive::archive_exception& e ) {
				break;			
			}
		}
		
		delete [] globalSegmentOwners;

		cout << "\nKernel " << kernel->name << "\n";
		cout << " path: " << kernel->path << "\n";
		cout << " module: " << kernel->module << "\n";
		cout << "     global addr range: 0x" << hex << header.global_min_address << " - 0x" << header.global_max_address << dec << "\n";
		cout << "      working set size: " << (header.global_max_address - header.global_min_address) << " bytes\n";
		cout << " segments of " << (1<<segmentSize_pow2) << " bytes: " << globalSegmentCount << "\n";
		cout << "       global OOB refs: " << global_OOB << "\n";
		cout << "   global stored words: " << global_Sts << "\n";
		cout << "     global load words: " << global_Lds << "\n";
		cout << "      x-cta load words: " << global_crossCta_Lds << "\n";
	}
}

/*!
	Print a list of applications and their kernels. If filter is true, only display applications
	that call at least one kernel more than once
*/
void trace::MemoryTraceAnalyzer::application_list(bool filter) {
	using namespace ir;
	using namespace std;

	ApplicationMap applications = GetApplications(_kernels, filter);

	cout << "--\nKernels grouped by application:\n";

	// list kernels by application
	for (ApplicationMap::iterator fi = applications.begin(); 
		fi != applications.end(); ++fi) {
		cout << "\nApplication: '" << fi->second.name << "' with " 
			<< fi->second.kernels.size() << " kernels\n";
		for (int j = 0; j < (int)fi->second.kernels.size(); j++) {
			cout << "  kernel " << fi->second.kernels[j].kernel.name << hex
				<< " - 0x" << fi->second.kernels[j].header.global_min_address 
				<< " : 0x" << fi->second.kernels[j].header.global_max_address 
				<< dec << "\n";
		}
	}
	cout << "\n";
}

/*!

	class KernelData {
	public:
		KernelEntry kernel;
		MemoryTraceGenerator::Header header;
	};

	class ApplicationData {
	public:
		std::string name;

		std::vector< KernelData > kernels;
	};
*/

class CTAData {
public:
	CTAData() {
		count_Stores = 0;
		count_Loads = 0;
		count_crossCtaLoads = 0;
	}
	~CTAData()
	{
	
	}

	void clear() {
		globalOwners.clear();
	}

	void initialize(ir::PTXU64 addressSpaceSize, ir::PTXU64 addressBase, int segmentSize_pow2) {
		this->addressBase = addressBase;
		this->segmentSize_pow2 = segmentSize_pow2;
		clear();
	}

	void store(ir::PTXU64 base, int size, int ctaID) {
		++count_Stores;

		for (int n = 0; n < size; n++) {
			ir::PTXU64 offset = (base + (ir::PTXU64)n) - addressBase;
			ir::PTXU64 segmentNumber = (offset >> segmentSize_pow2);
			globalOwners[segmentNumber] = ctaID;
		}
	}

	ir::PTXS32 load(ir::PTXU64 address) {
		++count_Loads;
		ir::PTXU64 segmentNumber = ((address - addressBase) >> segmentSize_pow2);
		GlobalMap::iterator segment = globalOwners.find( segmentNumber );
		if( segment == globalOwners.end() )
		{
			return -1;
		}
		else
		{
			return segment->second;
		}
	}

public:
	typedef std::unordered_map< ir::PTXU64, ir::PTXS32 > GlobalMap;
	ir::PTXU64 addressBase;
	GlobalMap globalOwners;
	int segmentSize_pow2;

public:
	ir::PTXU64 count_Stores;
	ir::PTXU64 count_Loads;
	ir::PTXU64 count_crossCtaLoads;
};

void trace::MemoryTraceAnalyzer::application_overlapped(
	ApplicationData application, 
	int segmentSize_pow2) {

	using namespace ir;
	using namespace std;

	map< string, CTAData > kernelsCtaData;

	cout << "Application: " << application.name << "\n" << flush;

	for( vector< KernelData >::const_iterator kernel = application.kernels.begin(); 
		kernel != application.kernels.end(); ++kernel)	{
		
		std::ifstream stream( kernel->kernel.path.c_str() );
		boost::archive::text_iarchive archive( stream );
		
		if (!stream.is_open()) {
			throw hydrazine::Exception(
				"Failed to open MemoryTrace kernel trace file " 
				+ kernel->kernel.path );
		}

		if( kernel->header.headerOnly )
		{
			std::stringstream error;
			error << "Trace for Kernel " << kernel->kernel.name 
				<< " was generated without support for recording " 
				<< "individual accesses requried for computing " 
				<< "application global memory overlaps.";
			throw hydrazine::Exception( error.str() );
		}
		
		cout << "\nKernel " << kernel->kernel.name << "\n" << flush;

		cout << " new base address: 0x" << hex << kernel->header.global_min_address << dec << "\n";
		cout << "      max address: 0x" << hex << kernel->header.global_max_address << dec << "\n";

		if (kernelsCtaData.find(kernel->kernel.name) == kernelsCtaData.end()) {
			CTAData ctaGlobalOwners;
			ctaGlobalOwners.initialize( kernel->header.global_max_address - kernel->header.global_min_address, 
				kernel->header.global_min_address, segmentSize_pow2);
			kernelsCtaData[kernel->kernel.name] = ctaGlobalOwners;
		}
		else {
			cout << "Former base address: 0x" << hex << kernelsCtaData[kernel->kernel.name].addressBase << dec << "\n";
		}

		CTAData &ctaGlobalOwners = kernelsCtaData[kernel->kernel.name];
		
		while (true) {
			try {
				MemoryTraceGenerator::Event event;
				archive >> event;

				PTXS32 ctaID = event.ctaX + event.ctaY * kernel->header.blockDimX + 
					event.ctaZ * (kernel->header.blockDimX * kernel->header.blockDimY);

				if (event.addressSpace == PTXInstruction::Global || 
					event.opcode == PTXInstruction::Ld || event.opcode == PTXInstruction::St) {

					//cout << " global operation encountered\n" << flush;
					
					for (MemoryTraceGenerator::AccessVector::const_iterator acc_it = event.accesses.begin();
						acc_it != event.accesses.end(); ++acc_it) {
						if (event.opcode == PTXInstruction::St) {
							//cout << "  store to 0x" << hex << acc_it->address << dec << " " << flush;
							ctaGlobalOwners.store(acc_it->address, acc_it->size, ctaID);
							//cout << "done\n" << flush;
						}
						else {
							//cout << "  load from 0x" << hex << acc_it->address << dec << " " <<  flush;
							PTXS32 owningCtaID = ctaGlobalOwners.load(acc_it->address);
							//cout << "done\n" << flush;

							if (owningCtaID >= 0 && owningCtaID != ctaID) {
								// loading from a segment written to by another CTA
								++ ctaGlobalOwners.count_crossCtaLoads;
							}
						}
					}
				}
			}
			catch( const boost::archive::archive_exception& e ) {
				break;			
			}
		}
	}

	cout << "Application " << application.name << "\n";

	// free ownership information for kernels
	for (map<string,CTAData>::iterator it = kernelsCtaData.begin(); 
		it != kernelsCtaData.end(); ++it) {
		it->second.clear();

		cout << "  kernel " << it->first << "\n";
		cout << "         stores: " << it->second.count_Stores << "\n";
		cout << "          loads: " << it->second.count_Loads << "\n";
		cout << "    x-cta loads: " << it->second.count_crossCtaLoads << "\n";
	}
	kernelsCtaData.clear();
}

/*!
	For each application, examines how many times kernels refer to the same memory segments
*/
void trace::MemoryTraceAnalyzer::application_level_overlapped_global_memory(int segmentSize_pow2) {
	CTAData data;
	using namespace std;
	
	ApplicationMap applications = GetApplications(_kernels, false);
	
	for( ApplicationMap::iterator app = applications.begin(); 
		app != applications.end(); ++app )
	{
		ir::PTXU64 minAddress = -1;
		ir::PTXU64 maxAddress = 0;
	
		for( vector< KernelData >::const_iterator 
			kernel = app->second.kernels.begin(); 
			kernel != app->second.kernels.end(); ++kernel)	{
			minAddress = std::min( minAddress, 
				kernel->header.global_min_address );
			maxAddress = std::max( maxAddress, 
				kernel->header.global_min_address );
		}
	
		data.initialize( maxAddress - minAddress, minAddress, segmentSize_pow2 );
		application_overlapped(app->second, segmentSize_pow2);
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, char** argv) {
	hydrazine::ArgumentParser parser( argc, argv );
	
	parser.description("Provides the ability to inspect and analyze a database created by" 
		+ std::string( "a MemoryTraceGenerator" ) );
	
	bool list = false;
	bool histogram = false;
	bool global = false;
	bool kernel_overlapped = false;
	bool app_overlapped = false;
	bool list_apps = false;
	bool filter_apps_list = false;
	bool mem_intensity = false;
	bool verbose = false;
	bool machine_readable = false;
	
	std::string database;
	std::string spaces;
	std::string prepend;
	
	int binsize;
	int warpsize;
	int segment_size_pow2;

	parser.parse( "-l", "--list", list, false, 
		"List all traces in the database." );
	
	parser.parse( "-z", "--machine", machine_readable, false, 
		"Indicates output is intended to be machine-readable");
	parser.parse( "-i", "--input", database, "traces/database.trace", 
		"Path to database file." );	
	parser.parse( "-v", "--verbose", verbose, false, 
		"Prints an unmanagable amount of information.");
	parser.parse("-s", "--spaces", spaces, "cglspt", 
		"Selects address spaces of interest [cglspt]");
		
	parser.parse( "", "--histogram", histogram, false, 
		"Constructs a histogram document for each selected address space over all kernels");
	parser.parse( "", "--prepend", prepend, "memory", 
		"String prepended to generated filenames for histogram and other analysis");
	parser.parse( "", "--binsize", binsize, 6, 
		"Exponent to which 2 must be raised to specify bin size in bytes for histogram.");

	parser.parse( "-g", "--Global", global, false, 
		"Print global load/store statistics to stdout");
	parser.parse( "", "--warpsize", warpsize, 32, 
		"Number of threads per warp");
		
	parser.parse( "", "--Koverlapped", kernel_overlapped, false, 
		"Analyzes overlapped working sets across CTAs within each kernel");
	
	parser.parse( "", "--Apps", list_apps, false, 
		"Lists kernels grouped by application");
	parser.parse( "-f", "--filter", filter_apps_list, false, 
		"Only print apps that call the same kernel more than once");

	parser.parse( "", "--Aoverlapped", app_overlapped, false, 
		"[DOESN'T WORK] Analyzes overlapped working sets across kernels within each application");
	parser.parse( "", "--segsize", segment_size_pow2, 7, 
		"Exponent to which 2 must be raised to specify segment size in Koverlapped and Aoverlapped metrics");
		
	parser.parse( "-m", "--MemIntensity", mem_intensity, false, 
		"Computes [ld+st]/dynamic instructions for each kernel and aggregates, weighting by dynamic instructions");
	parser.parse();
	
	trace::MemoryTraceAnalyzer analyzer( database );
	analyzer.spaces = spaces;
	analyzer.verbose = verbose;
	if (list) {
		analyzer.list(machine_readable);
	}
	
	if (histogram) {
		analyzer.histogram(prepend, binsize);
	}
	
	if (global) {
		analyzer.global_transactions(warpsize, machine_readable);
	}
	
	if (kernel_overlapped) {
		analyzer.kernel_level_overlapped_global_memory(segment_size_pow2);
	}
	if (list_apps) {
		analyzer.application_list(filter_apps_list);
	}
	if (app_overlapped) {
		analyzer.application_level_overlapped_global_memory(segment_size_pow2);
	}
	if (mem_intensity) {
		analyzer.global_access_fraction(machine_readable);
	}
	
	return 0;
}

#endif

