/*!
	\file SharedComputationGenerator.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief declares a SharedComputationGenerator class used in tracing memory operations in the
		emulator
*/

#ifndef TRACE_SHAREDCOMPUTATIONGENERATOR_H_INCLUDED
#define TRACE_SHAREDCOMPUTATIONGENERATOR_H_INCLUDED

#include <set>
#include <vector>
#include <string>
#include <fstream>

#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/trace/interface/TraceGenerator.h>

#include <ocelot/trace/interface/KernelEntry.h>

namespace trace {

	class SharedComputationGenerator: public TraceGenerator {
	public:
	
		class Header {
		public:
			Header();
			~Header();
		
		public:
			TraceFormat format;

			ir::PTXU64 dynamic_instructions;

			/*!
				Number of ld.shared instructions in which the source data came from another
				thread.
			*/
			ir::PTXU64 sharedLoads;

			/*!
				Number of threads executing on the kernel
			*/
			ir::PTXU32 threadCount;
			
			/*!
				Number of accesses that are outside addressable shared memory
			*/
			ir::PTXU32 storeOutOfBoundsAccesses;
			
			/*!
				Number of accesses that are outside addressable shared memory
			*/
			ir::PTXU32 loadOutOfBoundsAccesses;
			
			/*!
				Number of bytes in shared memory
			*/
			ir::PTXU32 sharedMemorySize;
			
			/*!
			
			*/
			ir::PTXU64 storeSharedCount;
			
			/*!
			
			*/
			ir::PTXU64 loadSharedCount;
		};

		class Access {
		public:

			ir::PTXS32 threadID;			//! thread performing the load

			ir::PTXS32 sourceThread;	//! last thread to write to the location being accessed

			ir::PTXU32 address;				//! address in shared mem being accessed

			ir::PTXU32 size;					//! size of load
		};

		typedef std::vector< Access > AccessVector;
		
		class Event {
		private:
			friend class boost::serialization::access;

			template< class Archive > void save( Archive& ar, const unsigned int version ) const {

				ir::PTXU32 accessCount = (ir::PTXU32)accesses.size();
				
				ar & PC;
				ar & opcode;
				ar & type;
				ar & blockId;
				ar & accessCount;
			
				for (std::vector<trace::SharedComputationGenerator::Access>::const_iterator it = accesses.begin(); 
					it != accesses.end(); ++it) {
					const trace::SharedComputationGenerator::Access &acc = *it;
					ar & acc.threadID;
					ar & acc.sourceThread;
					ar & acc.address;
					ar & acc.size;
				}
			}

			template< class Archive > void load( Archive& ar, const unsigned int version ) {
				ir::PTXU32 accessCount = 0;
				
				ar & PC;
				ar & opcode;
				ar & type;
				ar & blockId;
				ar & accessCount;
			
				for (ir::PTXU32 n = 0; n < accessCount; n++) {
					SharedComputationGenerator::Access acc;
					ar & acc.threadID;
					ar & acc.sourceThread;
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
			
			ir::PTXInstruction::Opcode opcode;		//! type of instruction performing the access

			ir::PTXOperand::DataType type;				//! data type of access

			ir::PTXU32 blockId;										//! CTA id of the block that created the event

			AccessVector accesses;								//! set of accesses (1 or more)

		};	// end Event

		
	private:
		
		/*!
			ar & header.outOfBoundsAccesses;
			\brief Counter for creating unique file names.
		*/
		static unsigned int _counter;
	
	public:

		/*!
			Constructs a trace generator with path './' recording *all* address spaces
		*/
		SharedComputationGenerator();

		/*!
			Destructs the trace generator
		*/
		~SharedComputationGenerator();

		/*!
			called when a traced kernel is launched to retrieve some parameters from the kernel
		*/
		void initialize(const executive::EmulatedKernel *kernel);

		/*!
			Called whenever an event takes place.

			Note, the const reference 'event' is only valid until event() returns
		*/
		void event(const TraceEvent & event);

	protected:

			ir::PTXU32 SharedMemoryMask;
	
			/*!
				\brief Pointer to the trace file being written to
			*/
			std::ofstream* _file;
			
			/*!
				\brief Pointer to the archive being saved to the file.
			*/
			boost::archive::text_oarchive* _archive;
			
			/*!
				\brief Entry for the current kernel
			*/
			KernelEntry _entry;
			
			/*!
				\brief Header for the current kernel
			*/
			Header _header;

			/*!
				Id of the current block
			*/
			ir::PTXU32 blockId;

			/*!
				Contains the threadID of the last thread to write to each byte of shared memory
			*/
			ir::PTXS32 *sharedMemoryOwners;
			
	public:
	
			std::set< ir::PTXU32 > maskedStSet;
			
	private:
			void selectMaskedStSet(const executive::EmulatedKernel *kernel);
	};
}


namespace boost
{
	namespace serialization
	{		
		template< class Archive >
		void serialize( Archive& ar, 
			trace::SharedComputationGenerator::Header& header, 
			const unsigned int version )
		{
			ar & header.format;
			ar & header.dynamic_instructions;
			ar & header.sharedLoads;
			ar & header.threadCount;
			ar & header.storeOutOfBoundsAccesses;
			ar & header.loadOutOfBoundsAccesses;
			ar & header.sharedMemorySize;
			ar & header.storeSharedCount;
			ar & header.loadSharedCount;
		}
	}
}

#endif

