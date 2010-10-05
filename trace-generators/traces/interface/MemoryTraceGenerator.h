/*! \file MemoryTraceGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief declares a MemoryTraceGenerator class used in tracing memory 
		operations in the emulator
		
		Reimplemented MemoryTraceGenerator class to be consistent with 
		ParallelismTraceGenerator and BranchTraceGenerator approaches 
		to trace recording.
*/

#ifndef TRACE_MEMORYTRACEGENERATOR_H_INCLUDED
#define TRACE_MEMORYTRACEGENERATOR_H_INCLUDED

#include <vector>
#include <string>
#include <fstream>

#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/trace/interface/TraceGenerator.h>
#include <traces/interface/KernelEntry.h>

#include <boost/serialization/split_member.hpp>

namespace boost
{
	namespace archive
	{
		class text_oarchive;
	}
}


namespace trace {

	class MemoryTraceGenerator: public TraceGenerator {
	public:
		class Header {
		public:
			Header();
			~Header();
			
		public:
			void access(ir::PTXInstruction::AddressSpace space, 
				ir::PTXU64 bytes);
			void address(ir::PTXInstruction::AddressSpace space, 
				ir::PTXU64 addr);
		
		public:
			TraceFormat format;
			
			ir::PTXU32 blockDimX, blockDimY, blockDimZ;
			
			ir::PTXU32 thread_count;
			
			ir::PTXU64 dynamic_instructions;
			
			ir::PTXU64 dynamic_operations; //! dynamic_instructions * avg_activity_factor
			
			ir::PTXU64 const_accesses;
			ir::PTXU64 global_accesses;
			ir::PTXU64 local_accesses;
			ir::PTXU64 param_accesses;
			ir::PTXU64 shared_accesses;
			ir::PTXU64 texture_accesses;

			ir::PTXU64 global_min_address;			
			ir::PTXU64 global_max_address;
			
			ir::PTXU64 global_instructions;
			ir::PTXU64 texture_instructions;
			
			ir::PTXU64 shared_bytes;
			ir::PTXU64 global_bytes;
			ir::PTXU64 texture_bytes;
			
			ir::PTXU64 global_words;
			ir::PTXU64 texture_words;
			
			ir::PTXU64 global_segments;
			ir::PTXU64 halfwarps;
			
			ir::PTXU64 global_extent;
			
			bool headerOnly;
		};
		
		class Access {
		public:
			int threadID;
			ir::PTXU64 address;
			ir::PTXU32 size;
		};
		
		typedef std::vector<Access> AccessVector;
		
		class Event {
		private:
			friend class boost::serialization::access;

			template< class Archive > void save( Archive& ar, 
				const unsigned int version ) const {
				/*
				std::string takenString;
				std::string fallthroughString;

				boost::to_string( taken, takenString );
				boost::to_string( fallthrough, fallthroughString );

				ar & pc;
				ar & counter;
				ar & takenString;
				ar & fallthroughString;
				*/
				ir::PTXU32 accessCount = (ir::PTXU32)accesses.size();
				
				ar & PC;
				ar & opcode;
				ar & addressSpace;
				ar & ctaX;
				ar & ctaY;
				ar & ctaZ;
				ar & accessCount;
			
				for (AccessVector::const_iterator it = accesses.begin(); 
					it != accesses.end(); ++it) {
					const trace::MemoryTraceGenerator::Access &acc = *it;
					ar & acc.threadID;
					ar & acc.address;
					ar & acc.size;
				}
			}

			template< class Archive > 
			void load( Archive& ar, const unsigned int version ) {
				ir::PTXU32 accessCount = 0;
				
				ar & PC;
				ar & opcode;
				ar & addressSpace;
				ar & ctaX;
				ar & ctaY;
				ar & ctaZ;
				ar & accessCount;
			
				for (ir::PTXU32 n = 0; n < accessCount; n++) {
					MemoryTraceGenerator::Access acc;
					ar & acc.threadID;
					ar & acc.address;
					ar & acc.size;
					accesses.push_back(acc);
				}
			}
			BOOST_SERIALIZATION_SPLIT_MEMBER()
			
		public:
			Event( );
			~Event();
			
			ir::PTXU32 PC;
			ir::PTXInstruction::Opcode opcode;
			ir::PTXInstruction::AddressSpace addressSpace;
			ir::PTXU32 ctaX, ctaY, ctaZ;
			AccessVector accesses;

		};	// end Event

		
	private:
		
		/*! \brief Counter for creating unique file names. */
		static unsigned int _counter;
		
	public:
		/*! \brief Record the header only */
		bool headerOnly;
	
	public:

		/*!
			Constructs a trace generator with path './' recording *all* address spaces
		*/
		MemoryTraceGenerator();

		/*!
			Destructs the trace generator
		*/
		~MemoryTraceGenerator();

		/*!
			called when a traced kernel is launched to retrieve some 
				parameters from the kernel
		*/
		void initialize(const executive::ExecutableKernel& kernel);

		/*!
			Called whenever an event takes place.

			Note, the const reference 'event' is only valid until event() returns
		*/
		void event(const TraceEvent & event);
			
		void finish();

	protected:
			/*!	\brief Pointer to the trace file being written to */
			std::ofstream* _file;
			
			/*!	\brief Pointer to the archive being saved to the file. */
			boost::archive::text_oarchive* _archive;
			
			/*!	\brief Entry for the current kernel */
			KernelEntry _entry;
			
			/*!	\brief Header for the current kernel */
			Header _header;
			
			/*!	\brief The current event */
			Event _event;
	};
}


namespace boost
{
	namespace serialization
	{		
		template< class Archive >
		void serialize( Archive& ar, 
			trace::MemoryTraceGenerator::Header& header, 
			const unsigned int version )
		{
			ar & header.format;
			ar & header.blockDimX;
			ar & header.blockDimY;
			ar & header.blockDimZ;
			ar & header.thread_count;
			ar & header.dynamic_instructions;
			ar & header.dynamic_operations;
			ar & header.const_accesses;
			ar & header.global_accesses;
			ar & header.local_accesses;
			ar & header.param_accesses;
			ar & header.shared_accesses;
			ar & header.texture_accesses;
			
			ar & header.global_min_address;
			ar & header.global_max_address;
			
			ar & header.halfwarps;
			ar & header.global_segments;
			
			ar & header.global_instructions;
			ar & header.texture_instructions;
			
			ar & header.global_bytes;
			ar & header.texture_bytes;
			
			ar & header.global_words;
			ar & header.texture_words;
			ar & header.global_extent;
			
			ar & header.headerOnly;
		}
	}
}

#endif

