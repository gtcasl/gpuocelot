/*!
	\file InstructionTraceGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date date Jan 5, 2010
	\brief captures static and dynamic instruction counts
*/

#ifndef OCELOT_INSTRUCTION_TRACE_GENERATOR_H_INCLUDED
#define OCELOT_INSTRUCTION_TRACE_GENERATOR_H_INCLUDED

#include <ocelit/ir/interface/PTXInstruction.h>
#include <ocelot/trace/interface/TraceGenerator.h>

namespace trace {

	class InstructionTraceGenerator : public TraceGenerator {
	public:

		/*!
			Indicates which functional unit a particular instruction utilizes
		*/
		enum FunctionalUnit {
			Integer_arithmetic,	//! integer arithmetic
			Integer_logical,		//! itneger logical
			Float_single,				//! floating-point single-precision
			Float_double,				//! floating-point, double-precision
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

			void count(const ir::PTXInstruction &instr);

		public:

			size_t bytes_loaded;

			size_t bytes_stored;

			size_t dynamic_count;

			size_t static_count;
		};

		/*!
			header for InstructionTraceGenerator
		*/
		class Header {
		public:
			TraceFormat format;

			
		};

		/*!
			\brief maps a PTXInstruction::Opcode onto an instruction counter
		*/
		typedef std::unordered_map<ir::PTXInstruction::Opcode, InstructionCounter > OpcodeCountMap;

		/*!
			\brief maps a functional unit onto an OpcodeCountMap
		*/
		typdef std::unordered_map<FunctionalUnit, OpcodeCountMap > FunctionalUnitCountMap;

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
	};


}

#endif

