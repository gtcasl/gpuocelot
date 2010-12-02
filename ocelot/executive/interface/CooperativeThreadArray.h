/*! \file CooperativeThreadArray.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\date 5 February 2009

	\brief defines the state of each cooperative thread array with associated 
		code for emulating its execution
*/

#ifndef EXECUTIVE_COOPERATIVETHREADARRAY_H_INCLUDED
#define EXECUTIVE_COOPERATIVETHREADARRAY_H_INCLUDED

#include <deque>
#include <ocelot/executive/interface/CTAContext.h>
#include <ocelot/executive/interface/ReconvergenceMechanism.h>
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/ir/interface/Texture.h>
#include <ocelot/trace/interface/TraceEvent.h>

namespace executive {

	class EmulatedKernel;

	/*! Defines state of cooperative thread array */
	class CooperativeThreadArray {
	public:
		typedef std::deque <CTAContext> Stack;
		typedef std::vector <int> ThreadIdVector;
		typedef std::vector<ir::PTXU64> RegisterFileType;
		
		
	private:
	
		CooperativeThreadArray & operator=(const CooperativeThreadArray &);

	public:
		/*!
			Constructs a cooperative thread array from an EmulatedKernel instance

			\param kernel pointer to EmulatedKernel to which this CTA belongs
		*/
		CooperativeThreadArray(const EmulatedKernel *kernel);

		CooperativeThreadArray();

		/*! Destroys state associated with CTA */
		~CooperativeThreadArray();

		/*!
			Returns CTA to initial state
		*/
		void initialize(ir::Dim3 grid = ir::Dim3(0,0,0), bool trace = false);

		/*!
			Initializes the CTA and executes the kernel for a given block
		*/
		void execute(const ir::Dim3& block);

		/*! Jump to a specific PC for the current context */
		void jumpToPC(int PC);

		/* Get a snapshot of the current register file */
		RegisterFileType getCurrentRegisterFile() const;

		/*!
			Overwrites member pointers to allocated memory with zero so 
			that ~CooperativeThreadArray()
			
			does not attempt to delete them.
		*/
		void clear();
		
		/*!
			gets the active context of the cooperative thread array
		*/
		CTAContext & getActiveContext();

	public:
	
		/*!
			Dimensions of the kernel
		*/
		ir::Dim3 gridDim;

		/*!
			Dimensions of the cooperative thread array
		*/
		ir::Dim3 blockDim;

		/*!
			Number of threads in CTA 
				(equal to blockDim.x * blockDim.y * blockDim.z)
		*/
		int threadCount;

		/*!
			Pointer to EmulatedKernel instance that this CTA is executing
		*/
		const EmulatedKernel *kernel;

		/*!
			ID of block implemented by this CooperativeThreadArray instance
		*/
		ir::Dim3 blockId;

		/*!
			Row-major matrix of registers; 
				each row corresponds to an alloated register
		*/
		ir::PTXU64 *RegisterFile;

		/*!
			Number of elements in RegisterFile between successive registers 
			in a thread
		*/
		int RegisterFilePitch;

		/*!
			CC register
		*/
		ir::PTXOperand::RegisterType CC_register;

		/*!
			Pointer to byte-addressable shared memory
		*/
		char *SharedMemory;
		
		/*! \brief The last writer for each byte in shared memory */
		ThreadIdVector sharedMemoryWriters;

		/*!
			Pointer to byte-addressable local memory
		*/
		char *LocalMemory;

		/*!
			\brief abstraction for reconvergence mechanism
		*/
		ReconvergenceMechanism *reconvergenceMechanism;
		
		/*!
			Counter incremented 4 times per instruction
		*/
		ir::PTXU64 clock;

		/*!
			Flag to enable or disable tracing of events
		*/
		bool traceEvents;

		/*!
			Number of dynamic instructions executed
		*/
		int counter;

		/*!
			An object used to trace execution of the CooperativeThreadArray
		*/
		trace::TraceEvent currentEvent;

	protected:
		// internal functions for execution

		/*!
			Gets current instruction
		*/
		const ir::PTXInstruction& currentInstruction(CTAContext & context);

		/*!
			Gets special value
		*/
		ir::PTXU32 getSpecialValue( const int threadId,
			const ir::PTXOperand::SpecialRegister ) const;
		
	protected:
		// execution helper functions

		ir::PTXF32 sat(int modifier, ir::PTXF32 f);
		
		/*!
			\brief invokes TraceGenerator::event() on all trace generators
		*/
		void trace();

		/*!
			\brief invokes TraceGenerator::postEvent() on all trace generators
		*/		
		void postTrace();

	public:
		// Register accessors

		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXU8 getRegAsU8(int threadID, ir::PTXOperand::RegisterType reg);
		
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXU16 getRegAsU16(int threadID, ir::PTXOperand::RegisterType reg);
				
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXU32 getRegAsU32(int threadID, ir::PTXOperand::RegisterType reg);
		
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXU64 getRegAsU64(int threadID, ir::PTXOperand::RegisterType reg);

		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXS8 getRegAsS8(int threadID, ir::PTXOperand::RegisterType reg);
				
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXS16 getRegAsS16(int threadID, ir::PTXOperand::RegisterType reg);
				
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXS32 getRegAsS32(int threadID, ir::PTXOperand::RegisterType reg);
		
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXS64 getRegAsS64(int threadID, ir::PTXOperand::RegisterType reg);

		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXF32 getRegAsF32(int threadID, ir::PTXOperand::RegisterType reg);
		
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXF64 getRegAsF64(int threadID, ir::PTXOperand::RegisterType reg);

		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXB8 getRegAsB8(int threadID, ir::PTXOperand::RegisterType reg);
		
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXB16 getRegAsB16(int threadID, ir::PTXOperand::RegisterType reg);
				
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXB32 getRegAsB32(int threadID, ir::PTXOperand::RegisterType reg);
		
		/*!
			Gets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		ir::PTXB64 getRegAsB64(int threadID, ir::PTXOperand::RegisterType reg);
		
		/*!
			Gets a register value
			
			\param threadID ID of the active thread
			\param reg index of register
		*/
		bool getRegAsPredicate(int threadID, ir::PTXOperand::RegisterType reg);
		
	public:

		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsU8(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXU8 value);
			
		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsU16(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXU16 value);
				
		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsU32(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXU32 value);
		
		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsU64(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXU64 value);

		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsS8(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXS8 value);
					
		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsS16(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXS16 value);
				
		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsS32(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXS32 value);
		
		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsS64(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXS64 value);

		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsF32(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXF32 value);
		
		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsF64(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXF64 value);

		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsB8(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXB8 value);

		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsB16(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXB16 value);
				
		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsB32(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXB32 value);
		
		/*!
			Sets a register value 

			\param threadID ID of the active thread
			\reg register index
		*/
		void setRegAsB64(int threadID, ir::PTXOperand::RegisterType reg, 
			ir::PTXB64 value);
		
		/*!
			Sets a register value
			
			\param threadID ID of the active thread
			\param reg index of register
			\param value value of predicate register
		*/
		void setRegAsPredicate(int threadID, ir::PTXOperand::RegisterType reg, 
			bool value);
	
	public:
		ir::PTXU8 operandAsU8(int, const ir::PTXOperand &);
		ir::PTXU16 operandAsU16(int, const ir::PTXOperand &);
		ir::PTXU32 operandAsU32(int, const ir::PTXOperand &);
		ir::PTXU64 operandAsU64(int, const ir::PTXOperand &);

		ir::PTXS8 operandAsS8(int, const ir::PTXOperand &);
		ir::PTXS16 operandAsS16(int, const ir::PTXOperand &);
		ir::PTXS32 operandAsS32(int, const ir::PTXOperand &);
		ir::PTXS64 operandAsS64(int, const ir::PTXOperand &);

		ir::PTXF32 operandAsF32(int, const ir::PTXOperand &);
		ir::PTXF64 operandAsF64(int, const ir::PTXOperand &);

		ir::PTXB8 operandAsB8(int, const ir::PTXOperand &);
		ir::PTXB16 operandAsB16(int, const ir::PTXOperand &);
		ir::PTXB32 operandAsB32(int, const ir::PTXOperand &);
		ir::PTXB64 operandAsB64(int, const ir::PTXOperand &);

	private:
		void normalStore(int, const ir::PTXInstruction &, char*);
		void vectorStore(int, const ir::PTXInstruction &, char*, unsigned int);
		void normalLoad(int, const ir::PTXInstruction &, const char*);
		void vectorLoad(int, const ir::PTXInstruction &, const char*, 
			unsigned int);

	public:
		/*Handlers for each instruction */
		void eval_Abs(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Add(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_AddC(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_And(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Atom(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Bar(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Bra(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Brkpt(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Call(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_CNot(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Cos(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Cvt(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Div(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Ex2(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Exit(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Ld(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Lg2(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Mad24(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Mad(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Max(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Membar(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Min(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Mov(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Mul24(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Mul(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Neg(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Not(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Or(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Pmevent(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Rcp(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Red(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Rem(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Ret(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Rsqrt(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Sad(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_SelP(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_SetP(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Set(CTAContext &context, const ir::PTXInstruction &instr);
		void eval_Shl(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Shr(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Sin(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_SlCt(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Sqrt(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_St(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Sub(CTAContext &context, const ir::PTXInstruction &instr);	
		void eval_SubC(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Tex(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Trap(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Vote(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Xor(CTAContext &context, const ir::PTXInstruction &instr);		
		void eval_Reconverge(CTAContext &context, const ir::PTXInstruction &instr);	

	protected:
		
		void eval_Mov_reg(CTAContext &context,
			const ir::PTXInstruction &instr);
		void eval_Mov_sreg(CTAContext &context, 
			const ir::PTXInstruction &instr);
		void eval_Mov_imm(CTAContext &context,
			const ir::PTXInstruction &instr);
		void eval_Mov_indirect(CTAContext &context, 
			const ir::PTXInstruction &instr);
		void eval_Mov_addr(CTAContext &context,
			const ir::PTXInstruction &instr);

	};

}

#endif

