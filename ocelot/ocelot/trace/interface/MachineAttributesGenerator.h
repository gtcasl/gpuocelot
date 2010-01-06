/*!
	\file MachineAttributesGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date date Jan 5, 2010
	\brief captures static and dynamic instruction counts
*/

#ifndef OCELOT_KERNELDIM_TRACE_GENERATOR_H_INCLUDED
#define OCELOT_KERNELDIM_TRACE_GENERATOR_H_INCLUDED

// Ocelot includes
#include <ocelit/ir/interface/PTXInstruction.h>
#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/trace/interface/KernelEntry.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

namespace trace {

	/*!
		\brief kernel dimensions trace generator
	*/
	class MachineAttributesGenerator : public TraceGenerator {
	public:
	
		/*!
			header for InstructionTraceGenerator
		*/
		class Header {
		public:
			Header();
			
		public:
		
			TraceFormat format;

			ir::dim3 block;
			
			ir::dim3 grid;
			
		};	
	
	public:

		/*!
			default constructor
		*/
		InstructionTraceGenerator();

		/*!
			\brief destructs instruction trace generator
		*/
		virtual ~InstructionTraceGenerator();

		/*!
			\brief called when a traced kernel is launched to retrieve some 
				parameters from the kernel
		*/
		virtual void initialize(const ir::ExecutableKernel& kernel);

		/*!
			\brief Called whenever an event takes place.

			Note, the const reference 'event' is only valid until event() 
			returns
		*/
		virtual void event(const TraceEvent & event);
		
		/*! 
			\brief Called when a kernel is finished. There will be no more 
				events for this kernel.
		*/
		virtual void finish();
		
	public:
	
		Header _header;
		
		KernelEntry _entry;
	
	};
}


namespace boost
{
	namespace serialization
	{		
		template< class Archive >
		void serialize( Archive& ar, 
			trace::BranchTraceGenerator::Header& header, 
			const unsigned int version )
		{
			ar & header.format;
			
			ar & header.block.x;
			ar & header.block.y;
			ar & header.block.z;
			
			ar & header.grid.x;
			ar & header.grid.y;
			ar & header.grid.z;
		}
	}
}

#endif

