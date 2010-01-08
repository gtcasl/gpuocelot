/*!
	\file InstructionTraceGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date date Jan 5, 2010
	\brief captures static and dynamic instruction counts
*/

#ifndef OCELOT_INSTRUCTION_TRACE_GENERATOR_H_INCLUDED
#define OCELOT_INSTRUCTION_TRACE_GENERATOR_H_INCLUDED

// C++ stdlib includes
#include <unordered_map>

// Ocelot includes
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/trace/interface/KernelEntry.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

namespace trace {

	class InstructionTraceGenerator : public TraceGenerator {
	public:

		/*!
			Indicates which functional unit a particular instruction utilizes
		*/
		enum FunctionalUnit {
			Integer_arithmetic,	//! integer arithmetic
			Integer_logical,		//! itneger logical
			Integer_comparison,	//! comparison
			Float_single,				//! floating-point single-precision
			Float_double,				//! floating-point, double-precision
			Float_comparison,		//! floating-point comparison
			Memory_offchip,			//! off-chip: {global, local}
			Memory_onchip,			//! cached or scratchpad: {texture, shared, constant}
			Control,						//! control-flow instructions
			Parallelism,				//! parallelism: sync, reduction, vote
			Special,						//! transcendental and special functions
			Other,							//! not categorized
			FunctionalUnit_invalid		//! invalid
		};

		/*!
			\brief gets the functional unit associated with a particular PTXInstruction
			\param instr PTXInstruction instance
			\return functional unit
		*/
		static FunctionalUnit getFunctionalUnit(const ir::PTXInstruction &instr);

	public:

		/*!
			\brief 
		*/
		class InstructionCounter {
		public:
			InstructionCounter();

			void count(const ir::PTXInstruction &instr, size_t active);

			InstructionCounter & operator+=( const InstructionCounter &counter);

		public:

			size_t dynamic_count;

			size_t static_count;
		};

		/*!
			header for InstructionTraceGenerator
		*/
		class Header {
		public:
			Header();
			
		public:
		
			TraceFormat format;

			size_t total_dynamic;
			
			size_t total_static;
		};

		/*!
			\brief maps a PTXInstruction::Opcode onto an instruction counter
		*/
		typedef std::unordered_map<int, InstructionCounter > OpcodeCountMap;

		/*!
			\brief maps a functional unit onto an OpcodeCountMap
		*/
		typedef std::unordered_map<int, OpcodeCountMap > FunctionalUnitCountMap;

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
	
		FunctionalUnitCountMap instructionCounter;
		
	private:
	
		static unsigned int _counter;
		
	};
}


namespace boost
{
	namespace serialization
	{		
	
		template< class Archive > void serialize(Archive & ar, 
			trace::InstructionTraceGenerator::Header & header, const unsigned int version) {
			
			ar & header.format;
			ar & header.total_dynamic;
			ar & header.total_static;
		}
		
		template< class Archive > void serialize(Archive & ar,
			trace::InstructionTraceGenerator::InstructionCounter & count, const unsigned int version) {
			
			ar & count.dynamic_count;
			ar & count.static_count;
		}
		
		template< class Archive > void serialize(Archive & ar, 
			trace::InstructionTraceGenerator::FunctionalUnitCountMap &map, const unsigned int version) {
		
			for (trace::InstructionTraceGenerator::FunctionalUnitCountMap::const_iterator fu_it = map.begin();
				fu_it != map.end(); ++fu_it) {
				
				for (trace::InstructionTraceGenerator::OpcodeCountMap::const_iterator op_it = fu_it->second.begin();
					op_it != fu_it->second.end(); ++op_it) {
					
					ar & fu_it->first & op_it->first & op_it->second;
				}
			}
		}
	}
}

#endif

