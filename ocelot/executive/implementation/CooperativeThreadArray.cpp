/*! \file CooperativeThreadArray.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 5 February 2009
	\brief defines the state of each cooperative thread array 
		with associated code for emulating its execution
*/

#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/PTXInstruction.h>

#include <ocelot/executive/interface/RuntimeException.h>
#include <ocelot/executive/interface/CooperativeThreadArray.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/CTAContext.h>
#include <ocelot/executive/interface/TextureOperations.h>

#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cfenv> 
#include <algorithm>

#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/math.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#define IPDOM_RECONVERGENCE 1
#define BARRIER_RECONVERGENCE 2
#define GEN6_RECONVERGENCE 3
#define SORTED_PREDICATE_STACK_RECONVERGENCE 4

// specify reconvergence mechanism here
#define RECONVERGENCE_MECHANISM IPDOM_RECONVERGENCE

/////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

// global control for enabling reporting within the emulator
#define REPORT_BASE 0

// reporting for kernel instructions
#define REPORT_STATIC_INSTRUCTIONS 1
#define REPORT_DYNAMIC_INSTRUCTIONS 0

// reporting for register accesses
#define REPORT_NTH_THREAD_ONLY 1
#define NTH_THREAD 0
#define REPORT_REGISTER_READS 0
#define REPORT_REGISTER_WRITES 0

// individually turn on or off reporting for particular instructions
#define REPORT_ABS 1
#define REPORT_ADD 1
#define REPORT_ADDC 1
#define REPORT_AND 1
#define REPORT_ATOM 1
#define REPORT_BAR 1
#define REPORT_BRA 0
#define REPORT_BRKPT 1
#define REPORT_CALL 1
#define REPORT_CNOT 1
#define REPORT_COS 1
#define REPORT_CVT 1
#define REPORT_DIV 1
#define REPORT_EX2 1
#define REPORT_EXIT 1
#define REPORT_LD 0
#define REPORT_LG2 1
#define REPORT_MAD24 1
#define REPORT_MAD 1
#define REPORT_MAX 1
#define REPORT_MIN 1
#define REPORT_MOV 1
#define REPORT_MUL24 1
#define REPORT_MUL 1
#define REPORT_NEG 1
#define REPORT_NOT 1
#define REPORT_OR 1
#define REPORT_RCP 1
#define REPORT_RECONVERGE 0
#define REPORT_RED 1
#define REPORT_REM 1
#define REPORT_RET 1
#define REPORT_RSQRT 1
#define REPORT_SAD 1
#define REPORT_SELP 0
#define REPORT_SETP 0
#define REPORT_SET 1
#define REPORT_SHL 1
#define REPORT_SHR 1
#define REPORT_SIN 1
#define REPORT_SLCT 1
#define REPORT_SQRT 1
#define REPORT_ST 0
#define REPORT_SUB 1
#define REPORT_SUBC 1
#define REPORT_TEX 1
#define REPORT_TRAP 1	
#define REPORT_VOTE 1
#define REPORT_XOR 1

using namespace ir;
using namespace std;

template <typename T>
static T CTAAbs(T a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

bool isF32NaN(PTXF32 f) {
	return f != f;
}

bool isF64NaN(PTXF64 f) {
	return f != f;
}

#define max(a, b) ((a) < (b) ? (b) : (a))
#define min(a, b) ((a) > (b) ? (b) : (a))

//////////////////////////////////////////////////////////////////////////////////////////////////
/*!
	Constructs a cooperative thread array from an EmulatedKernel instance

	\param kernel pointer to EmulatedKernel to which this CTA belongs
*/
executive::CooperativeThreadArray::CooperativeThreadArray(const EmulatedKernel *k):
	kernel(k) {

	traceEvents = true;

	blockDim = k->blockDim();
	threadCount = blockDim.x*blockDim.y*blockDim.z;

	RegisterFilePitch = threadCount;
	RegisterFile = new PTXU64[RegisterFilePitch * (k->registerCount())];
	std::memset(RegisterFile, 0,
		RegisterFilePitch * (k->registerCount()) * sizeof(PTXU64));
	
	if(k->totalSharedMemorySize() > 0) {
		SharedMemory = new char[k->totalSharedMemorySize()];
	} else {
		SharedMemory = 0;
	}
	
	if(k->localMemorySize() > 0) {
		LocalMemory = new char[k->localMemorySize() * threadCount];
	} else {
		LocalMemory = 0;
	}

#if RECONVERGENCE_MECHANISM == IPDOM_RECONVERGENCE
	reconvergenceMechanism = new ReconvergenceIPDOM(kernel, this);
#elif RECONVERGENCE_MECHANISM == BARRIER_RECONVERGENCE
	reconvergenceMechanism = new ReconvergenceBarrier(kernel, this);
#elif RECONVERGENCE_MECHANISM == GEN6_RECONVERGENCE
	reconvergenceMechanism = new ReconvergenceTFGen6(kernel, this);
#elif RECONVERGENCE_MECHANISM == SORTED_PREDICATE_STACK_RECONVERGENCE
	reconvergenceMechanism = new ReconvergenceTFSortedStack(kernel, this);
#else
	assert(0 && "unimplemented thread reconvergence mechanism");
#endif

	initialize();
}

executive::CooperativeThreadArray::CooperativeThreadArray() : kernel(0), 
	RegisterFile(0), SharedMemory(0), LocalMemory(0) {
	
	reconvergenceMechanism = new ReconvergenceMechanism(this);
		
	initialize();
}

/*!
	Destroys state associated with CTA
*/
executive::CooperativeThreadArray::~CooperativeThreadArray() {
	delete [] RegisterFile;
	delete [] SharedMemory;
	delete [] LocalMemory;
	delete reconvergenceMechanism;
}

/*!
	Destroys state associated with CTA
*/
void executive::CooperativeThreadArray::clear() {
	RegisterFile = 0;
	SharedMemory = 0;
}

/*!
	Returns CTA to initial state
*/
void executive::CooperativeThreadArray::initialize(ir::Dim3 grid, bool trace ) {
	clock = 0;
	gridDim = grid;
	traceEvents = trace;
	
	reconvergenceMechanism->initialize();
}


/*!
	Gets current instruction
*/
const ir::PTXInstruction&
	executive::CooperativeThreadArray::currentInstruction(
	CTAContext & context) {
	return kernel->instructions[context.PC];
}

ir::PTXU32 executive::CooperativeThreadArray::getSpecialValue( 
	const int threadId, const ir::PTXOperand::SpecialRegister reg ) const
{
	assert( reg != ir::PTXOperand::SpecialRegister_invalid );
	assert( reg != ir::PTXOperand::laneId );
	assert( reg != ir::PTXOperand::pm0 );
	assert( reg != ir::PTXOperand::pm1 );
	assert( reg != ir::PTXOperand::pm2 );
	assert( reg != ir::PTXOperand::pm3 );
	assert( reg != ir::PTXOperand::smId );
	assert( reg != ir::PTXOperand::nsmId );
	assert( reg != ir::PTXOperand::gridId );

	switch( reg ) {
		case ir::PTXOperand::tidX: return ( threadId % blockDim.x ); break;
		case ir::PTXOperand::tidY: return ( ( threadId / blockDim.x ) 
			% blockDim.y ); break;
		case ir::PTXOperand::tidZ: return ( ( threadId 
			/ ( blockDim.x * blockDim.y ) ) ); break;
		case ir::PTXOperand::ntidX: return blockDim.x; break;
		case ir::PTXOperand::ntidY: return blockDim.y; break;
		case ir::PTXOperand::ntidZ: return blockDim.z; break;
		case ir::PTXOperand::warpId: return 0; break;
		case ir::PTXOperand::warpSize: 
			return blockDim.z * blockDim.y * blockDim.x; break;
		case ir::PTXOperand::ctaIdX: return blockId.x; break;
		case ir::PTXOperand::ctaIdY: return blockId.y; break;
		case ir::PTXOperand::ctaIdZ: return blockId.z; break;
		case ir::PTXOperand::nctaIdX: return gridDim.x; break;
		case ir::PTXOperand::nctaIdY: return gridDim.y; break;
		case ir::PTXOperand::nctaIdZ: return gridDim.z; break;
		case ir::PTXOperand::clock: return clock; break;
		default: break;
	}
	
	return 0;
}

ir::PTXF32 executive::CooperativeThreadArray::sat(int modifier, ir::PTXF32 f) {
	if (modifier & ir::PTXInstruction::sat) {
		return (f <= 0 ? 0 : (f >= 1.0f ? 1.0f : f));
	}
	return f;
}

void executive::CooperativeThreadArray::trace() {
	if (traceEvents) {
		currentEvent.contextStackSize = (ir::PTXU32)reconvergenceMechanism->stackSize();
		kernel->traceEvent(currentEvent);
	}
}

void executive::CooperativeThreadArray::postTrace() {
	if (traceEvents) {
		currentEvent.contextStackSize = (ir::PTXU32)reconvergenceMechanism->stackSize();
		kernel->tracePostEvent(currentEvent);
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Called by the worker thread to evaluate a block
*/
void executive::CooperativeThreadArray::execute(const ir::Dim3& block) {
	using namespace ir;

	bool running = true;

	counter = 0;
	blockId = block;

	currentEvent.blockId = blockId;
	currentEvent.gridDim = gridDim;
	currentEvent.blockDim = blockDim;
	
	reconvergenceMechanism->initialize();
	
	report("CooperativeThreadArray::execute called");
	report("  block is " << block.x << ", " << block.y << ", " << block.z);
	reportE(REPORT_STATIC_INSTRUCTIONS, "Running " << kernel->toString());

	do {
		assert(reconvergenceMechanism->stackSize());

		// get the context and advance the program counter
		CTAContext& context = reconvergenceMechanism->getContext();
		const PTXInstruction& instr = currentInstruction(context);

		reconvergenceMechanism->evalPredicate(context);

		reportE(REPORT_DYNAMIC_INSTRUCTIONS, " [PC: " << context.PC 
			<< ", counter: " << counter 
			<< "] " << instr.toString() << " [stack "
			<< reconvergenceMechanism->stackSize() << "] [active " 
			<< context.active.count() << "]" );

		if (traceEvents) {
			currentEvent.reset();
			currentEvent.PC = context.PC;
			currentEvent.instruction = &instr;
			currentEvent.active = context.active;
		}
		
		switch (instr.opcode) {
			case PTXInstruction::Abs:
				eval_Abs(context, instr); break;
			case PTXInstruction::Add:
				eval_Add(context, instr); break;
			case PTXInstruction::AddC:
				eval_AddC(context, instr); break;
			case PTXInstruction::And:
				eval_And(context, instr); break;
			case PTXInstruction::Atom:
				eval_Atom(context, instr); break;
			case PTXInstruction::Bar:
				eval_Bar(context, instr); break;
			case PTXInstruction::Bra:
				eval_Bra(context, instr); break;
			case PTXInstruction::Brkpt:
				eval_Brkpt(context, instr); break;
			case PTXInstruction::Call:
				eval_Call(context, instr); break;
			case PTXInstruction::CNot:
				eval_CNot(context, instr); break;
			case PTXInstruction::Cos:
				eval_Cos(context, instr); break;
			case PTXInstruction::Cvt:
				eval_Cvt(context, instr); break;
			case PTXInstruction::Div:
				eval_Div(context, instr); break;
			case PTXInstruction::Ex2:
				eval_Ex2(context, instr); break;
			case PTXInstruction::Exit:
				eval_Exit(context, instr); break;
			case PTXInstruction::Ld:
				eval_Ld(context, instr); break;
			case PTXInstruction::Lg2:
				eval_Lg2(context, instr); break;
			case PTXInstruction::Mad24:
				eval_Mad24(context, instr); break;
			case PTXInstruction::Mad:
				eval_Mad(context, instr); break;
			case PTXInstruction::Max:
				eval_Max(context, instr); break;
			case PTXInstruction::Membar:
				eval_Membar(context, instr); break;
			case PTXInstruction::Min:
				eval_Min(context, instr); break;
			case PTXInstruction::Mov:
				eval_Mov(context, instr); break;
			case PTXInstruction::Mul24:
				eval_Mul24(context, instr); break;
			case PTXInstruction::Mul:
				eval_Mul(context, instr); break;
			case PTXInstruction::Neg:
				eval_Neg(context, instr); break;
			case PTXInstruction::Not:
				eval_Not(context, instr); break;
			case PTXInstruction::Or:
				eval_Or(context, instr); break;
			case PTXInstruction::Pmevent:
				eval_Pmevent(context, instr); break;
			case PTXInstruction::Rcp:
				eval_Rcp(context, instr); break;
			case PTXInstruction::Red:
				eval_Red(context, instr); break;
			case PTXInstruction::Rem:
				eval_Rem(context, instr); break;
			case PTXInstruction::Ret:
				eval_Ret(context, instr); break;
			case PTXInstruction::Rsqrt:
				eval_Rsqrt(context, instr); break;
			case PTXInstruction::Sad:
				eval_Sad(context, instr); break;
			case PTXInstruction::SelP:
				eval_SelP(context, instr); break;
			case PTXInstruction::Set:
				eval_Set(context, instr); break;
			case PTXInstruction::SetP:
				eval_SetP(context, instr); break;
			case PTXInstruction::Shr:
				eval_Shr(context, instr); break;
			case PTXInstruction::Shl:
				eval_Shl(context, instr); break;
			case PTXInstruction::Sin:
				eval_Sin(context, instr); break;
			case PTXInstruction::SlCt:
				eval_SlCt(context, instr); break;
			case PTXInstruction::Sqrt:
				eval_Sqrt(context, instr); break;
			case PTXInstruction::St:
				eval_St(context, instr); break;
			case PTXInstruction::Sub:
				eval_Sub(context, instr); break;
			case PTXInstruction::SubC:
				eval_SubC(context, instr); break;
			case PTXInstruction::Tex:
				eval_Tex(context, instr); break;
			case PTXInstruction::Trap:
				eval_Trap(context, instr); break;
			case PTXInstruction::Vote:
				eval_Vote(context, instr); break;
			case PTXInstruction::Xor:
				eval_Xor(context, instr); break;
			case PTXInstruction::Reconverge:
				eval_Reconverge(context, instr); break;
			default:
				assertM(false, "Opcode at pc " 
					<< context.PC << " - " 
					<< PTXInstruction::toString(instr.opcode) 
					<< " not supported.");
				break;
		}
	
		running = reconvergenceMechanism->nextInstruction(context, instr);

		postTrace();

		clock += 4;
		++counter;

	} while (running);

	reconvergenceMechanism = 0;

	report("kernel finished in " << counter << " instructions");
}

void executive::CooperativeThreadArray::jumpToPC(int PC) {
	assert(!reconvergenceMechanism->runtimeStack.empty());
	assert(PC < (int)kernel->instructions.size());
	
	reconvergenceMechanism->runtimeStack.back().PC = PC;
}

executive::CooperativeThreadArray::RegisterFileType
	executive::CooperativeThreadArray::getCurrentRegisterFile() const {
	RegisterFileType file(threadCount * kernel->registerCount());	
	RegisterFileType::iterator ri = file.begin();
	for (int thread = 0; thread != threadCount; ++thread) {
		for (unsigned int reg = 0; reg != kernel->registerCount(); ++reg, ++ri) {
			*ri = RegisterFile[reg * RegisterFilePitch + thread];
		}
	}
	return file;
}

/*!
	gets the active context of the cooperative thread array
*/
executive::CTAContext & executive::CooperativeThreadArray::getActiveContext() {
	return reconvergenceMechanism->getContext();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Execution support


// Register accessors

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXU8 executive::CooperativeThreadArray::getRegAsU8(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXU8 r = *( (ir::PTXU8*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << (int)r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << (int)r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXU16 executive::CooperativeThreadArray::getRegAsU16(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXU16 r = *( (ir::PTXU16*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}
		
/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXU32 executive::CooperativeThreadArray::getRegAsU32(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXU32 r = *( (ir::PTXU32*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXU64 executive::CooperativeThreadArray::getRegAsU64(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXU64 r = *( (ir::PTXU64*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << (void*)r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << (void*)r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXS8 executive::CooperativeThreadArray::getRegAsS8(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXS8 r = *( (ir::PTXS8*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << (int)r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << (int)r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXS16 executive::CooperativeThreadArray::getRegAsS16(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXS16 r = *( (ir::PTXS16*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}
		
/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXS32 executive::CooperativeThreadArray::getRegAsS32(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXS32 r = *( (ir::PTXS32*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXS64 executive::CooperativeThreadArray::getRegAsS64(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXS64 r = *( (ir::PTXS64*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXF32 executive::CooperativeThreadArray::getRegAsF32(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXF32 r = *( (ir::PTXF32*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXF64 executive::CooperativeThreadArray::getRegAsF64(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXF64 r = *( (ir::PTXF64*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXB8 executive::CooperativeThreadArray::getRegAsB8(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXB8 r = *( (ir::PTXB8*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << (int)r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << (int)r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXB16 executive::CooperativeThreadArray::getRegAsB16(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXB16 r = *( (ir::PTXB16*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}
		
/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXB32 executive::CooperativeThreadArray::getRegAsB32(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXB32 r = *( (ir::PTXB32*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}

/*!
	Gets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
ir::PTXB64 executive::CooperativeThreadArray::getRegAsB64(int threadID, ir::PTXOperand::RegisterType reg) {
	ir::PTXB64 r = *( (ir::PTXB64*)( RegisterFile + reg * RegisterFilePitch + threadID ));
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << (void*)r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << (void*)r);
	#endif
	return r;
}

/*!
	Gets a register value
	
	\param threadID ID of the active thread
	\param reg index of register
*/
bool executive::CooperativeThreadArray::getRegAsPredicate(int threadID, ir::PTXOperand::RegisterType reg) {
	bool r = getRegAsU64(threadID, reg) != 0;
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_READS, "   thread " << threadID 
			<< " reg " << reg << " <= " << r);
	}
	#else
	reportE(REPORT_REGISTER_READS, "   thread " << threadID 
		<< " reg " << reg << " <= " << r);
	#endif
	return r;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsU8(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXU8 value) {
	ir::PTXU8* r = (ir::PTXU8*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << (int)value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << (int)value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsU16(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXU16 value) {
	ir::PTXU16* r = (ir::PTXU16*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}
		
/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsU32(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXU32 value) {
	ir::PTXU32* r = (ir::PTXU32*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsU64(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXU64 value) {
	ir::PTXU64* r = (ir::PTXU64*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << (void*)value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << (void*)value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsS8(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXS8 value) {
	ir::PTXS8* r = (ir::PTXS8*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << (int)value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << (int)value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsS16(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXS16 value) {
	ir::PTXS16* r = (ir::PTXS16*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}
		
/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsS32(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXS32 value) {
	ir::PTXS32* r = (ir::PTXS32*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsS64(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXS64 value) {
	ir::PTXS64* r = (ir::PTXS64*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsF32(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXF32 value) {
	ir::PTXF32* r = (ir::PTXF32*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsF64(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXF64 value) {
	ir::PTXF64* r = (ir::PTXF64*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsB8(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXB8 value) {
	ir::PTXB8* r = (ir::PTXB8*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << (int)value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << (int)value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsB16(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXB16 value) {
	ir::PTXB16* r = (ir::PTXB16*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}
		
/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsB32(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXB32 value) {
	ir::PTXB32* r = (ir::PTXB32*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}

/*!
	Sets a register value 

	\param threadID ID of the active thread
	\reg register index
*/
void  executive::CooperativeThreadArray::setRegAsB64(int threadID, ir::PTXOperand::RegisterType reg, ir::PTXB64 value) {
	ir::PTXB64* r = (ir::PTXB64*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}

/*!
	Sets a register value
	
	\param threadID ID of the active thread
	\param reg index of register
	\param value value of predicate register
*/
void executive::CooperativeThreadArray::setRegAsPredicate(int threadID, ir::PTXOperand::RegisterType reg, bool value) {
	ir::PTXB64* r = (ir::PTXB64*)( RegisterFile + reg * RegisterFilePitch + threadID );
	#if REPORT_NTH_THREAD_ONLY == 1
	if (threadID == NTH_THREAD) {
		reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
			<< " reg " << reg << " value " << " => " << value );
	}
	#else
	reportE(REPORT_REGISTER_WRITES, "   thread " << threadID 
		<< " reg " << reg << " value " << " => " << value );
	#endif
	*r = value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
ir::PTXU8 executive::CooperativeThreadArray::operandAsU8(int threadID, 
	const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsU8(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsU8(threadID, op.reg);
		case PTXOperand::Immediate:
			return (PTXU8)(op.imm_uint);
		case PTXOperand::Special:
			return (PTXU8)getSpecialValue(threadID, op.special);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXU16 executive::CooperativeThreadArray::operandAsU16(int threadID, 
	const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsU16(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsU16(threadID, op.reg);
		case PTXOperand::Immediate:
			return (PTXU16)(op.imm_uint);
		case PTXOperand::Special:
			return (PTXU16)getSpecialValue(threadID, op.special);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXU32 executive::CooperativeThreadArray::operandAsU32(int threadID, 
	const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsU32(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsU32(threadID, op.reg);
		case PTXOperand::Address:
			return (PTXU32)(op.imm_uint) + op.offset;
		case PTXOperand::Immediate:
			return (PTXU32)(op.imm_uint);
		case PTXOperand::Special:
			return (PTXU32)getSpecialValue(threadID, op.special);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXU64 executive::CooperativeThreadArray::operandAsU64(int threadID, 
	const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsU64(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsU64(threadID, op.reg);
		case PTXOperand::Immediate:
			return (PTXU64)(op.imm_uint);
		case PTXOperand::Address:
			return (PTXU64)(op.imm_uint) + op.offset;
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXS8 executive::CooperativeThreadArray::operandAsS8(int threadID, 
	const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsS8(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsS8(threadID, op.reg);
		case PTXOperand::Immediate:
			return (PTXS8)(op.imm_int);
		case PTXOperand::Special:
			return (PTXS8)getSpecialValue(threadID, op.special);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXS16 executive::CooperativeThreadArray::operandAsS16(int threadID, 
	const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsS16(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsS16(threadID, op.reg);
		case PTXOperand::Immediate:
			return (PTXS16)(op.imm_int);
		case PTXOperand::Special:
			return (PTXS16)getSpecialValue(threadID, op.special);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXS32 executive::CooperativeThreadArray::operandAsS32(int threadID, 
	const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsS32(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsS32(threadID, op.reg);
		case PTXOperand::Address:
		case PTXOperand::Immediate:
			return (PTXS32)(op.imm_int);
		case PTXOperand::Special:
			return (PTXS32)getSpecialValue(threadID, op.special);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXS64 executive::CooperativeThreadArray::operandAsS64(int threadID, 
	const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsS64(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsS64(threadID, op.reg);
		case PTXOperand::Address:
		case PTXOperand::Immediate:
			return (PTXS64)(op.imm_int);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXF32 executive::CooperativeThreadArray::operandAsF32(int threadID, const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Register:
			return getRegAsF32(threadID, op.reg);
		case PTXOperand::Immediate:
			return (PTXF32)(op.imm_float);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXF64 executive::CooperativeThreadArray::operandAsF64(int threadID, const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Register:
			return getRegAsF64(threadID, op.reg);
		case PTXOperand::Immediate:
			return (PTXF64)(op.imm_float);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXB8 executive::CooperativeThreadArray::operandAsB8(int threadID, const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsB8(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsB8(threadID, op.reg);
		case PTXOperand::Address:
		case PTXOperand::Immediate:
			return (PTXB8)(op.imm_uint);
		case PTXOperand::Special:
			return (PTXB8)getSpecialValue(threadID, op.special);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXB16 executive::CooperativeThreadArray::operandAsB16(int threadID, const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsB16(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsB16(threadID, op.reg);
		case PTXOperand::Address:
		case PTXOperand::Immediate:
			return (PTXB16)(op.imm_uint);
		case PTXOperand::Special:
			return (PTXB16)getSpecialValue(threadID, op.special);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXB32 executive::CooperativeThreadArray::operandAsB32(int threadID, const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsB32(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsB32(threadID, op.reg);
		case PTXOperand::Address:
		case PTXOperand::Immediate:
			return (PTXB32)(op.imm_uint);
		case PTXOperand::Special:
			return (PTXB32)getSpecialValue(threadID, op.special);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

ir::PTXB64 executive::CooperativeThreadArray::operandAsB64(int threadID, const PTXOperand &op) {
	switch (op.addressMode) {
		case PTXOperand::Indirect:
			return getRegAsB64(threadID, op.reg) + op.offset;
		case PTXOperand::Register:
			return getRegAsB64(threadID, op.reg);
		case PTXOperand::Address:
		case PTXOperand::Immediate:
			return (PTXB64)(op.imm_uint);
		default:
			assert(0 == "invalid address mode of operand");
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

/*!

*/
void executive::CooperativeThreadArray::eval_Abs(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {

			if (!context.predicated(threadID, instr)) continue;
			PTXF32 d, a = operandAsF32(threadID, instr.a);
			d = sat(instr.modifier, CTAAbs(a));
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXF64 d, a = operandAsF64(threadID, instr.a);
			d = CTAAbs(a);
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s8) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS8 d, a = operandAsS8(threadID, instr.a);
			d = CTAAbs(a);
			setRegAsS8(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS16 d, a = operandAsS16(threadID, instr.a);
			d = CTAAbs(a);
			setRegAsS16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS32 d, a = operandAsS32(threadID, instr.a);
			d = CTAAbs(a);
			setRegAsS32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS64 d, a = operandAsS64(threadID, instr.a);
			d = CTAAbs(a);
			setRegAsS64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Add(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXF32 d, a = operandAsF32(threadID, instr.a), 
				b = operandAsF32(threadID, instr.b);
			d = sat(instr.modifier, a + b);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXF64 d, a = operandAsF64(threadID, instr.a), 
				b = operandAsF64(threadID, instr.b);
			d = a + b;
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS16 d, a = operandAsS16(threadID, instr.a), 
				b = operandAsS16(threadID, instr.b);
			d = a + b;
			setRegAsS16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS32 d, a = operandAsS32(threadID, instr.a), 
				b = operandAsS32(threadID, instr.b);
			if (instr.modifier & ir::PTXInstruction::sat) {
				PTXS64 temp = (PTXS64)a + (PTXS64)b;
				temp = min(temp, (PTXS64)INT_MAX);
				temp = max(temp, (PTXS64)INT_MIN);
				d = (PTXS32)temp;
			}
			else if (instr.carry & ir::PTXInstruction::CC) {
				PTXS64 temp = (PTXS64)a + (PTXS64)b;
				d = (PTXS32)temp;
				PTXU32 carry = (temp & 0x100000000LLU) >> 32;
				setRegAsU32(threadID, instr.pq.reg, carry);
			}
			else {
				d = a + b;
			}
			setRegAsS32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS64 d, a = operandAsS64(threadID, instr.a), 
				b = operandAsS64(threadID, instr.b);
			d = a + b;
			setRegAsS64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU16 d, a = operandAsU16(threadID, instr.a), 
				b = operandAsU16(threadID, instr.b);
			d = a + b;
			setRegAsU16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU32 d, a = operandAsU32(threadID, instr.a), 
				b = operandAsU32(threadID, instr.b);
			if (instr.carry & ir::PTXInstruction::CC) {
				PTXS64 temp = (PTXS64)a + (PTXS64)b;
				d = (PTXS32)temp;
				PTXU32 carry = (temp & 0x100000000LLU) >> 32;
				setRegAsU32(threadID, instr.pq.reg, carry);
			}
			else {
				d = a + b;
			}
			setRegAsU32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU64 d, a = operandAsU64(threadID, instr.a), 
				b = operandAsU64(threadID, instr.b);
			d = a + b;
			setRegAsU64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_AddC(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();
	switch (instr.type) {

	case PTXOperand::u32:
	{
		for (int threadID = 0; threadID  < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU64 d = 0,
				a = operandAsU32(threadID, instr.a),
				b = operandAsU32(threadID, instr.b);

			d = a + b + getRegAsU32(threadID, instr.c.reg);
			setRegAsU32(threadID, instr.d.reg, (PTXU32)d);

			if (instr.carry & PTXInstruction::CC) {
				setRegAsU32(threadID, instr.pq.reg, (d & 0x100000000LLU) >> 32);
			}
		}
	} break;

	case PTXOperand::s32:
	{
		for (int threadID = 0; threadID  < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS64 d = 0,
				a = operandAsS32(threadID, instr.a),
				b = operandAsS32(threadID, instr.b);
			PTXS64 carry = getRegAsU32(threadID, instr.c.reg);

			d = a + b + carry;
			setRegAsS32(threadID, instr.d.reg, (PTXS32)d);

			if (instr.carry & PTXInstruction::CC) {
				setRegAsU32(threadID, instr.pq.reg, (d & 0x100000000LLU) >> 32);
			}
		}
	} break;

	default:
		throw RuntimeException("invalid datatype", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_And(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::pred) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			bool d, a = getRegAsPredicate(threadID, instr.a.reg), 
				b = getRegAsPredicate(threadID, instr.b.reg);
			d = b && a;
			setRegAsPredicate(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXB16 d, a = operandAsB16(threadID, instr.a), 
				b = operandAsB16(threadID, instr.b);
			d = a & b;
			setRegAsB16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXB32 d, a = operandAsB32(threadID, instr.a), 
				b = operandAsB32(threadID, instr.b);
			d = a & b;
			setRegAsB32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXB64 d, a = operandAsB64(threadID, instr.a), 
				b = operandAsB64(threadID, instr.b);
			d = a & b;
			setRegAsB64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Atom(CTAContext &context, const PTXInstruction &instr) {
	size_t elementSize = 0;
	
	switch (instr.type) {
		case PTXOperand::f32:		// fall through
		case PTXOperand::b32:		// fall through
		case PTXOperand::s32:		// fall through
		case PTXOperand::u32:
			{
				elementSize = sizeof(PTXU32);
			}
			break;
		case PTXOperand::b64:		// fall through
		case PTXOperand::u64:
			{
				elementSize = sizeof(PTXU64);
			}
			break;
		default:
			throw RuntimeException("unsupported data type", context.PC, instr);
	}

	if (traceEvents) {
		currentEvent.memory_size = elementSize;
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;

			const char *source = 0;

			switch (instr.a.addressMode) {
				case PTXOperand::Indirect:
					source += instr.a.offset;
				case PTXOperand::Register:
					source += getRegAsU64(threadID, instr.a.reg);				
					break;
				case PTXOperand::Address:
				case PTXOperand::Immediate:
					source += instr.a.imm_uint;
					source += instr.a.offset;
					break;
				default:
					throw RuntimeException(
						"unsupported address mode for source operand", 
						context.PC, instr);
			}

			currentEvent.memory_addresses.push_back((ir::PTXU64)source);
		}
	}

	trace();

	for (int threadID = 0; threadID < threadCount; threadID++) {
		if (!context.predicated(threadID, instr)) continue;

		const char *source = 0;

		switch (instr.a.addressMode) {
			case PTXOperand::Indirect:
				source += instr.a.offset;
			case PTXOperand::Register:
				source += getRegAsU64(threadID, instr.a.reg);				
				break;
			case PTXOperand::Address:
			case PTXOperand::Immediate:
				source += instr.a.imm_uint;
				source += instr.a.offset;
				break;
			default:
				throw RuntimeException(
					"unsupported address mode for source operand", 
					context.PC, instr);
		}

		switch (instr.addressSpace) {
			case PTXInstruction::Global:
				{	

				}
				break;
			case PTXInstruction::Shared:
				{
					source += (PTXU64) SharedMemory;
				}
				break;
			default:
				throw RuntimeException("unsupported address space", 
					context.PC, instr);
		}
		
		switch (instr.atomicOperation) {
			case PTXInstruction::AtomicAnd:
				{
					if(instr.type != PTXOperand::b32
						&& instr.type != PTXOperand::s32
						&& instr.type != PTXOperand::u32) {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}
					PTXB32 d = *((PTXB32*)source);
					setRegAsB32(threadID, instr.d.reg, d);
					PTXB32 b = operandAsB32(threadID, instr.b);
					*((PTXB32*)source) = d & b;
					reportE(REPORT_ATOM, "Atomically updated " << d << " to " 
						<< *((PTXB32*)source) );		
				}
				break;
			case PTXInstruction::AtomicOr:
				{
					if(instr.type != PTXOperand::b32
						&& instr.type != PTXOperand::s32
						&& instr.type != PTXOperand::u32) {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}
					PTXB32 d = *((PTXB32*)source);
					setRegAsB32(threadID, instr.d.reg, d);
					PTXB32 b = operandAsB32(threadID, instr.b);
					*((PTXB32*)source) = d | b;
					reportE(REPORT_ATOM, "Atomically updated " << d << " to " 
						<< *((PTXB32*)source) );		
				}
				break;
			case PTXInstruction::AtomicXor:
				{
					if(instr.type != PTXOperand::b32
						&& instr.type != PTXOperand::s32
						&& instr.type != PTXOperand::u32) {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}
					PTXB32 d = *((PTXB32*)source);
					setRegAsB32(threadID, instr.d.reg, d);
					PTXB32 b = operandAsB32(threadID, instr.b);
					*((PTXB32*)source) = d ^ b;				
					reportE(REPORT_ATOM, "Atomically updated " << d << " to " 
						<< *((PTXB32*)source) );		
				}
				break;
			case PTXInstruction::AtomicCas:
				{
					if (instr.type == PTXOperand::b32
						|| instr.type == PTXOperand::s32
						|| instr.type == PTXOperand::u32) {
						PTXB32 d = *((PTXB32*)source);
						setRegAsB32(threadID, instr.d.reg, d);
						PTXB32 b = operandAsB32(threadID, instr.b);
						PTXB32 c = operandAsB32(threadID, instr.c);
						*((PTXB32*)source) = (d==b) ? c : d;				
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXB32*)source) );		
					}
					else if (instr.type == PTXOperand::b64
						|| instr.type == PTXOperand::s64
						|| instr.type == PTXOperand::u64) {
						PTXB64 d = *((PTXB64*)source);
						setRegAsB64(threadID, instr.d.reg, d);
						PTXB64 b = operandAsB64(threadID, instr.b);
						PTXB64 c = operandAsB64(threadID, instr.c);
						*((PTXB64*)source) = (d==b) ? c : d;
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXB64*)source) );		
					}
					else {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}				
				}
				break;
			case PTXInstruction::AtomicExch:
				{
					if (instr.type == PTXOperand::b32
						|| instr.type == PTXOperand::s32
						|| instr.type == PTXOperand::u32) {
						PTXB32 d = *((PTXB32*)source);
						setRegAsB32(threadID, instr.d.reg, d);
						PTXB32 b = operandAsB32(threadID, instr.b);
						*((PTXB32*)source) = b;
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXB32*)source) );		
					}
					else if (instr.type == PTXOperand::b64
						|| instr.type == PTXOperand::s64
						|| instr.type == PTXOperand::u64) {
						PTXB64 d = *((PTXB64*)source);
						setRegAsB64(threadID, instr.d.reg, d);
						PTXB64 b = operandAsB64(threadID, instr.b);
						*((PTXB64*)source) = b;
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXB64*)source) );		
					}
					else {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}				
				}
				break;
			case PTXInstruction::AtomicAdd:
				{
					if (instr.type == PTXOperand::u32) {
						PTXU32 d = *((PTXU32*)source);
						setRegAsU32(threadID, instr.d.reg, d);
						PTXU32 b = operandAsU32(threadID, instr.b);
						*((PTXU32*)source) = b + d;
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXU32*)source) );		
					}
					else if (instr.type == PTXOperand::s32) {
						PTXS32 d = *((PTXS32*)source);
						setRegAsS32(threadID, instr.d.reg, d);
						PTXS32 b = operandAsS32(threadID, instr.b);
						*((PTXS32*)source) = b + d;
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXS32*)source) );		
					}
					else if (instr.type == PTXOperand::f32) {
						PTXF32 d = *((PTXF32*)source);
						setRegAsF32(threadID, instr.d.reg, d);
						PTXF32 b = operandAsF32(threadID, instr.b);
						*((PTXF32*)source) = b + d;
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXF32*)source) );		
					}
					else if (instr.type == PTXOperand::u64) {
						PTXU64 d = *((PTXU64*)source);
						setRegAsU64(threadID, instr.d.reg, d);
						PTXU64 b = operandAsU64(threadID, instr.b);
						*((PTXU64*)source) = b + d;
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXU64*)source) );		
					}
					else {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}				
				}
				break;
			case PTXInstruction::AtomicInc:
				{
					if(instr.type != PTXOperand::u32) {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}
					PTXU32 d = *((PTXU32*)source);
					setRegAsU32(threadID, instr.d.reg, d);
					PTXU32 b = operandAsU32(threadID, instr.b);
					*((PTXU32*)source) = (d >= b) ? 0 : d + 1;
					reportE(REPORT_ATOM, "Atomically updated " << d 
						<< " to " << *((PTXU32*)source) );		
				}
				break;
			case PTXInstruction::AtomicDec:
				{
					if(instr.type != PTXOperand::u32) {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}
					PTXU32 d = *((PTXU32*)source);
					setRegAsU32(threadID, instr.d.reg, d);
					PTXU32 b = operandAsU32(threadID, instr.b);
					*((PTXU32*)source) = ((d == 0) || (d > b)) ? b : d - 1;				
					reportE(REPORT_ATOM, "Atomically updated " << d 
						<< " to " << *((PTXU32*)source) );		
				}
				break; 
			case PTXInstruction::AtomicMin:
				{
					if (instr.type == PTXOperand::u32) {
						PTXU32 d = *((PTXU32*)source);
						setRegAsU32(threadID, instr.d.reg, d);
						PTXU32 b = operandAsU32(threadID, instr.b);
						*((PTXU32*)source) = min(b, d);
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXU32*)source) );		
					}
					else if (instr.type == PTXOperand::s32) {
						PTXS32 d = *((PTXS32*)source);
						setRegAsS32(threadID, instr.d.reg, d);
						PTXS32 b = operandAsS32(threadID, instr.b);
						*((PTXS32*)source) = min(b, d);
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXS32*)source) );		
					}
					else if (instr.type == PTXOperand::f32) {
						PTXF32 d = *((PTXF32*)source);
						setRegAsF32(threadID, instr.d.reg, d);
						PTXF32 b = operandAsF32(threadID, instr.b);
						*((PTXF32*)source) = min(b, d);
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXF32*)source) );		
					}
					else {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}				
				}
				break;
			case PTXInstruction::AtomicMax:
				{
					if (instr.type == PTXOperand::u32) {
						PTXU32 d = *((PTXU32*)source);
						setRegAsU32(threadID, instr.d.reg, d);
						PTXU32 b = operandAsU32(threadID, instr.b);
						*((PTXU32*)source) = max(b, d);
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXU32*)source) );		
					}
					else if (instr.type == PTXOperand::s32) {
						PTXS32 d = *((PTXS32*)source);
						setRegAsS32(threadID, instr.d.reg, d);
						PTXS32 b = operandAsS32(threadID, instr.b);
						*((PTXS32*)source) = max(b, d);
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXS32*)source) );		
					}
					else if (instr.type == PTXOperand::f32) {
						PTXF32 d = *((PTXF32*)source);
						setRegAsF32(threadID, instr.d.reg, d);
						PTXF32 b = operandAsF32(threadID, instr.b);
						*((PTXF32*)source) = max(b, d);
						reportE(REPORT_ATOM, "Atomically updated " << d 
							<< " to " << *((PTXF32*)source) );		
					}
					else {
						throw RuntimeException("invalid data type", 
							context.PC, instr);						
					}				
				}
				break;
			default:
				throw RuntimeException("Invalid atomic operation", 
					context.PC, instr);
		}
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Bar(CTAContext& context, 
	const PTXInstruction& instr) {
	trace();

	reconvergenceMechanism->eval_Bar(context, instr);
}

void executive::CooperativeThreadArray::eval_Bra(CTAContext &context, const PTXInstruction &instr) {

	using namespace boost;

	dynamic_bitset<> branch = context.active;
	dynamic_bitset<> fallthrough(branch.size(), 0);
	
	// determine divergence
	for (int i = 0; i < threadCount; i++) {
		if (context.predicated(i, instr)) {
			// typical branch
			branch[i] = context.active[i];
			fallthrough[i] = false;
		}
		else {
			fallthrough[i] = context.active[i];
			branch[i] = false;
		}
	}

	if (traceEvents) {
		currentEvent.fallthrough = fallthrough;
		currentEvent.taken = branch;
	}

#if REPORT_BRA
	report("  active threads       [" << context.active.count() << "] " << context.active);
	report("  branching threads    [" << branch.count() << "] " << branch);
	report("  fall-through threads [" << fallthrough.count() << "] " << fall_through);
	report("  branch target PC " << instr.branchTargetInstruction);
	report("  reconverge PC " << instr.reconvergeInstruction);
#endif

	// dispatch to reconvergence mechanism
	reconvergenceMechanism->eval_Bra(context, instr, branch, fallthrough);

	currentEvent.reconvergence = reconvergenceMechanism->currentEvent;
	trace();
}

/*!
	Reconverge instruction is inserted into the PTX during analysis and construction of the
	emulated kernel. 
*/
void executive::CooperativeThreadArray::eval_Reconverge(CTAContext &context, const PTXInstruction &instr) {
	using namespace std;
	trace();
	
	// dispatch
	reconvergenceMechanism->eval_Reconverge(context, instr);
}

/*!

*/
void executive::CooperativeThreadArray::eval_Brkpt(CTAContext &context, const PTXInstruction &instr) {
	trace();
	context.running = false;
}

/*!

*/
void executive::CooperativeThreadArray::eval_Call(CTAContext &context, const PTXInstruction &instr) {
	trace();
	throw RuntimeException("instruction not implemented", context.PC, instr);
}

/*!

*/
void executive::CooperativeThreadArray::eval_CNot(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::b16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXB16 d, a = operandAsB16(threadID, instr.a);
			d = (a == 0 ? 1 : 0);
			setRegAsB16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB32 d, a = operandAsB32(threadID, instr.a);
			d = (a == 0 ? 1 : 0);
			setRegAsB32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB64 d, a = operandAsB64(threadID, instr.a);
			d = (a == 0 ? 1 : 0);
			setRegAsB64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Cos(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a);
			d = (PTXF32)cos(a);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a);
			d = cos(a);
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

template< typename Int >
static ir::PTXF32 toF32(Int value, int modifier) {
	int mode = fegetround();
	if (modifier & PTXInstruction::rn) {
		fesetround(FE_TONEAREST);
	} else if (modifier & PTXInstruction::rz) {
		fesetround(FE_TOWARDZERO);
	} else if (modifier & PTXInstruction::rm) {
		fesetround(FE_DOWNWARD);
	} else if (modifier & PTXInstruction::rp) {
		fesetround(FE_UPWARD);
	}
	ir::PTXF32 d = value;
	fesetround(mode);
	return d;
}

template< typename Int >
static ir::PTXF64 toF64(Int value, int modifier) {
	int mode = fegetround();
	if (modifier & PTXInstruction::rn) {
		fesetround(FE_TONEAREST);
	} else if (modifier & PTXInstruction::rz) {
		fesetround(FE_TOWARDZERO);
	} else if (modifier & PTXInstruction::rm) {
		fesetround(FE_DOWNWARD);
	} else if (modifier & PTXInstruction::rp) {
		fesetround(FE_UPWARD);
	}
	ir::PTXF64 d = value;
	fesetround(mode);
	return d;
}

template< typename Float >
static Float round(Float a, int modifier) {
	Float fd = 0;
	if (modifier & PTXInstruction::rn) {
		fd = nearbyintf(a);
	} else if (modifier & PTXInstruction::rz) {
		fd = trunc(a);
	} else if (modifier & PTXInstruction::rm) {
		fd = floor(a);
	} else if (modifier & PTXInstruction::rp) {
		fd = ceil(a);
	} else {
		fd = a;
	}
	return fd;
}

static ir::PTXF32 round(ir::PTXF64 a, int modifier) { 
	int mode = fegetround();
	if (modifier & PTXInstruction::rn) {
		fesetround(FE_TONEAREST);
	} else if (modifier & PTXInstruction::rz) {
		fesetround(FE_TOWARDZERO);
	} else if (modifier & PTXInstruction::rm) {
		fesetround(FE_DOWNWARD);
	} else if (modifier & PTXInstruction::rp) {
		fesetround(FE_UPWARD);
	}
	ir::PTXF32 d = a;
	fesetround(mode);
	return d;
}

/*!

*/
void executive::CooperativeThreadArray::eval_Cvt(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();
	for (int threadID = 0; threadID < threadCount; threadID++) {
		if (!context.predicated(threadID, instr)) continue;
		switch (instr.a.type) {
			case PTXOperand::b8: // fall through
			case PTXOperand::u8:
			{
				switch (instr.type) {
					case PTXOperand::pred: // fall through
					case PTXOperand::b8: // fall through
					case PTXOperand::u8: // fall through
					case PTXOperand::s16: // fall through
					case PTXOperand::u16: // fall through
					case PTXOperand::s32: // fall through
					case PTXOperand::b32: // fall through
					case PTXOperand::u32: // fall through
					case PTXOperand::b64: // fall through
					case PTXOperand::s64: // fall through
					case PTXOperand::u64: // fall through
						{
							setRegAsU64(threadID, instr.d.reg, 
								operandAsB8(threadID, instr.a));
						}
						break;
					case PTXOperand::s8:
						{
							PTXU8 a = operandAsU8(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, CHAR_MAX);
							}
							PTXS8 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::f32:
						{
							setRegAsF32(threadID, instr.d.reg, 
								toF32(operandAsB8(threadID, instr.a), 
								instr.modifier));
						}
						break;
					case PTXOperand::f64:
						{
							setRegAsF64(threadID, instr.d.reg, 
								toF64(operandAsB8(threadID, instr.a), 
								instr.modifier));
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}
			}
			break;
			case PTXOperand::s8:
			{
				switch (instr.type) {
					case PTXOperand::s8: // fall through
					case PTXOperand::s16: // fall through
					case PTXOperand::s32: // fall through
					case PTXOperand::s64:
						{
							PTXS8 a = operandAsS8(threadID, instr.a);
							setRegAsS64(threadID, instr.d.reg, a);
						}
						break;
					case PTXOperand::pred: // fall through
					case PTXOperand::u8: // fall through
					case PTXOperand::b8: // fall through
					case PTXOperand::b16: // fall through
					case PTXOperand::u16: // fall through
					case PTXOperand::b32: // fall through
					case PTXOperand::u32: // fall through
					case PTXOperand::b64: // fall through
					case PTXOperand::u64:
						{
							PTXS8 a = operandAsS8(threadID, instr.a);
							if (instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							setRegAsU64(threadID, instr.d.reg, a);
						}
						break;
					case PTXOperand::f32:
						{
							setRegAsF32(threadID, instr.d.reg, 
								toF32(operandAsS8(threadID, instr.a), 
								instr.modifier));
						}
						break;
					case PTXOperand::f64:
						{
							setRegAsF64(threadID, instr.d.reg, 
								toF64(operandAsS8(threadID, instr.a), 
								instr.modifier));
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}
			}
			break;
			case PTXOperand::b16: // fall through
			case PTXOperand::u16:
			{
				switch (instr.type) {
					case PTXOperand::pred: // fall through
					case PTXOperand::b8: // fall through
					case PTXOperand::u8:
						{
							PTXU16 a = operandAsU16(threadID, instr.a);
							PTXU8 d = a;
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::u16: // fall through
					case PTXOperand::b16: // fall through
					case PTXOperand::s32: // fall through
					case PTXOperand::b32: // fall through
					case PTXOperand::u32: // fall through
					case PTXOperand::b64: // fall through
					case PTXOperand::s64: // fall through
					case PTXOperand::u64:
						{
							setRegAsU64(threadID, instr.d.reg, 
								operandAsB16(threadID, instr.a));
						}
						break;
					case PTXOperand::s8:
						{
							PTXU16 a = operandAsU16(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, CHAR_MAX);
							}
							PTXS8 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s16:
						{
							PTXU16 a = operandAsU16(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, SHRT_MAX);
							}
							PTXS16 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::f32:
						{
							setRegAsF32(threadID, instr.d.reg, 
								toF32(operandAsB16(threadID, instr.a),
								instr.modifier));
						}
						break;
					case PTXOperand::f64:
						{
							setRegAsF64(threadID, instr.d.reg, 
								toF64(operandAsB16(threadID, instr.a),
								instr.modifier));
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}
			}
			break;
			case PTXOperand::s16:
			{
				// s16 to one of the following
				switch (instr.type) {
					case PTXOperand::s8:
						{
							PTXS16 a = operandAsS16(threadID, instr.a);
							PTXS8 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s16: // fall through
					case PTXOperand::s32: // fall through
					case PTXOperand::s64:
						{
							PTXS16 a = operandAsS16(threadID, instr.a);
							setRegAsS64(threadID, instr.d.reg, a);
						}
						break;
					case PTXOperand::pred: // fall through
					case PTXOperand::u8: // fall through
					case PTXOperand::b8:
						{
							PTXS16 a = operandAsS16(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							PTXU8 d = a;
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b16: // fall through
					case PTXOperand::u16: // fall through
					case PTXOperand::b32: // fall through
					case PTXOperand::u32: // fall through
					case PTXOperand::b64: // fall through
					case PTXOperand::u64:
						{
							PTXS16 a = operandAsS16(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							setRegAsU64(threadID, instr.d.reg, a);
						}
						break;
					case PTXOperand::f32:
						{
							setRegAsF32(threadID, instr.d.reg, 
								toF32(operandAsS16(threadID, instr.a),
								instr.modifier));
						}
						break;
					case PTXOperand::f64:
						{
							setRegAsF64(threadID, instr.d.reg, 
								toF64(operandAsS16(threadID, instr.a),
								instr.modifier));
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}
			}
			break;
			case PTXOperand::b32: // fall through
			case PTXOperand::u32:
			{
				switch (instr.type) {
					case PTXOperand::pred: // fall through
					case PTXOperand::b8: // fall through
					case PTXOperand::u8:
						{
							PTXU32 a = operandAsU32(threadID, instr.a);
							PTXU8 d = a;
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::u16: // fall through
					case PTXOperand::b16:
						{
							PTXU32 a = operandAsU32(threadID, instr.a);
							PTXU16 d = a;
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b32: // fall through
					case PTXOperand::u32: // fall through
					case PTXOperand::s64: // fall through
					case PTXOperand::b64: // fall through
					case PTXOperand::u64:
						{
							setRegAsU64(threadID, instr.d.reg, 
								operandAsU32(threadID, instr.a));
						}
						break;
					case PTXOperand::s8:
						{
							PTXU32 a = operandAsU32(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, CHAR_MAX);
							}
							PTXS8 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s16:
						{
							PTXU32 a = operandAsU32(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, SHRT_MAX);
							}
							PTXS16 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s32:
						{
							PTXU32 a = operandAsU32(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, INT_MAX);
							}
							PTXS32 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::f32: 
						{
							setRegAsF32(threadID, instr.d.reg, 
								toF32(operandAsU32(threadID, instr.a),
								instr.modifier));
						}
						break;
					case PTXOperand::f64: 
						{
							setRegAsF64(threadID, instr.d.reg, 
								toF64(operandAsU32(threadID, instr.a),
								instr.modifier));
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}
			}
			break;
			case PTXOperand::s32:
			{
				switch (instr.type) {
					case PTXOperand::pred: // fall through
					case PTXOperand::b8: // fall through
					case PTXOperand::u8:
						{
							PTXS32 a = operandAsS32(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							PTXU8 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::u16: // fall through
					case PTXOperand::b16:
						{
							PTXS32 a = operandAsS32(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							PTXU16 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b32: // fall through
					case PTXOperand::u32: // fall through
					case PTXOperand::b64: // fall through
					case PTXOperand::u64: 
						{
							PTXS32 a = operandAsS32(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							setRegAsS64(threadID, instr.d.reg, a);
						}
						break;
					case PTXOperand::s8:
						{
							PTXS32 a = operandAsS32(threadID, instr.a);
							PTXS8 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s16:
						{
							PTXS32 a = operandAsS32(threadID, instr.a);
							PTXS16 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s32: // fall through
					case PTXOperand::s64: 
						{
							PTXS32 a = operandAsS32(threadID, instr.a);
							setRegAsS64(threadID, instr.d.reg, a);
						}
						break;
					case PTXOperand::f32: 
						{
							setRegAsF32(threadID, instr.d.reg, 
								toF32(operandAsS32(threadID, instr.a),
								instr.modifier));
						}
						break;
					case PTXOperand::f64: 
						{
							setRegAsF64(threadID, instr.d.reg, 
								toF64(operandAsS32(threadID, instr.a),
								instr.modifier));
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}
			}
			break;
			case PTXOperand::s64:
			{
				switch (instr.type) {
					case PTXOperand::pred: // fall through
					case PTXOperand::b8: // fall through
					case PTXOperand::u8: // fall through
						{
							PTXS64 a = operandAsS64(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							PTXU8 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::u16: // fall through
					case PTXOperand::b16: // fall through
						{
							PTXS64 a = operandAsS64(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							PTXU16 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b32: // fall through
					case PTXOperand::u32:
						{
							PTXS64 a = operandAsS64(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							PTXU32 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b64: // fall through
					case PTXOperand::u64: 
						{
							PTXS64 a = operandAsS64(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = max(a, 0);
							}
							setRegAsS64(threadID, instr.d.reg, a);
						}
						break;
					case PTXOperand::s8:
						{
							PTXS64 a = operandAsS64(threadID, instr.a);
							PTXS8 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s16:
						{
							PTXS64 a = operandAsS64(threadID, instr.a);
							PTXS16 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s32:
						{
							PTXS64 a = operandAsS64(threadID, instr.a);
							PTXS32 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s64: 
						{
							PTXS64 a = operandAsS64(threadID, instr.a);
							setRegAsS64(threadID, instr.d.reg, a);
						}
						break;
					case PTXOperand::f32: 
						{
							setRegAsF32(threadID, instr.d.reg, 
								toF32(operandAsS64(threadID, instr.a),
								instr.modifier));
						}
						break;
					case PTXOperand::f64: 
						{
							setRegAsF64(threadID, instr.d.reg, 
								toF64(operandAsS64(threadID, instr.a),
								instr.modifier));
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}
			}
			break;
			case PTXOperand::b64:
			case PTXOperand::u64:
			{
				switch (instr.type) {
					case PTXOperand::pred: // fall through
					case PTXOperand::b8: // fall through
					case PTXOperand::u8:
						{
							PTXU64 a = operandAsU64(threadID, instr.a);
							PTXU8 d = a;
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b16: // fall through
					case PTXOperand::u16:
						{
							PTXU64 a = operandAsU64(threadID, instr.a);
							PTXU16 d = a;
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b32: // fall through
					case PTXOperand::u32:
						{
							PTXU64 a = operandAsU64(threadID, instr.a);
							PTXU32 d = a;
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b64: // fall through
					case PTXOperand::u64:
						{
							setRegAsU64(threadID, instr.d.reg, 
								operandAsU64(threadID, instr.a));
						}
						break;
					case PTXOperand::s8:
						{
							PTXU64 a = operandAsU64(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, CHAR_MAX);
							}
							PTXS8 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s16:
						{
							PTXU64 a = operandAsU64(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, SHRT_MAX);
							}
							PTXS16 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s32:
						{
							PTXU64 a = operandAsU64(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, INT_MAX);
							}
							PTXS32 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s64:
						{
							PTXU64 a = operandAsU64(threadID, instr.a);
							if(instr.modifier & PTXInstruction::sat) {
								a = min(a, LONG_LONG_MAX);
							}
							PTXS64 d = a;
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::f32: 
						{
							setRegAsF32(threadID, instr.d.reg, 
								toF32(operandAsU64(threadID, instr.a),
								instr.modifier));
						}
						break;
					case PTXOperand::f64: 
						{
							setRegAsF64(threadID, instr.d.reg, 
								toF64(operandAsU64(threadID, instr.a),
								instr.modifier));
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}
			}
			break;
			case PTXOperand::f32:
			{
				switch (instr.type) {
					case PTXOperand::pred: // fall through
					case PTXOperand::b8: // fall through
					case PTXOperand::u8: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXF32 fd = round(a, instr.modifier);
							PTXU8 d = 0;
							if( fd > UCHAR_MAX ) {
								d = UCHAR_MAX;
							}
							else if( fd < 0 ) {
								d = 0;
							}
							else {
								d = fd;
							}
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b16: // fall through
					case PTXOperand::u16: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXF32 fd = round(a, instr.modifier);
							PTXU16 d = 0;
							if( fd > USHRT_MAX ) {
								d = USHRT_MAX;
							}
							else if( fd < 0 ) {
								d = 0;
							}
							else {
								d = fd;
							}
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b32: // fall through
					case PTXOperand::u32: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXF32 fd = round(a, instr.modifier);
							PTXU32 d = 0;
							if( fd > UINT_MAX ) {
								d = UINT_MAX;
							}
							else if( fd < 0 ) {
								d = 0;
							}
							else {
								d = fd;
							}
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b64: // fall through 
					case PTXOperand::u64: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXU64 d = round(a, instr.modifier);
							d = min(ULLONG_MAX, d);
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s8: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXS64 dd = round(a, instr.modifier);
							PTXS8 d = 0;
							dd = min(CHAR_MAX, dd);
							d = max(dd, CHAR_MIN);
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s16: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXS64 dd = round(a, instr.modifier);
							PTXS16 d = 0;
							dd = min(SHRT_MAX, dd);
							d = max(dd, SHRT_MIN);
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s32: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXS64 dd = round(a, instr.modifier);
							PTXS32 d = 0;
							dd = min(INT_MAX, dd);
							d = max(dd, INT_MIN);
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s64: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXS64 d = round(a, instr.modifier);
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::f32: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							a = round(a, instr.modifier);
							setRegAsF32(threadID, instr.d.reg, 
								sat(instr.modifier, a));
						}
						break;
					case PTXOperand::f64: 
						{
							PTXF32 a = operandAsF32(threadID, instr.a);
							PTXF64 d = round(a, instr.modifier);
							setRegAsF64(threadID, instr.d.reg, d);
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}					
			}
			break;
			case PTXOperand::f64:
			{
				switch (instr.type) {
					case PTXOperand::pred: // fall through
					case PTXOperand::b8: // fall through
					case PTXOperand::u8: 
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXF64 fd = round(a, instr.modifier);
							PTXU16 d = 0;
							if( fd > UCHAR_MAX ) {
								d = UCHAR_MAX;
							}
							else if( fd < 0 ) {
								d = 0;
							}
							else {
								d = fd;
							}
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b16: // fall through
					case PTXOperand::u16: 
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXF64 fd = round(a, instr.modifier);
							PTXU16 d = 0;
							if( fd > USHRT_MAX ) {
								d = USHRT_MAX;
							}
							else if( fd < 0 ) {
								d = 0;
							}
							else {
								d = fd;
							}
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b32: // fall through
					case PTXOperand::u32: 
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXF64 fd = round(a, instr.modifier);
							PTXU32 d = 0;
							if( fd > UINT_MAX ) {
								d = UINT_MAX;
							}
							else if( fd < 0 ) {
								d = 0;
							}
							else {
								d = fd;
							}
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::b64: // fall through 
					case PTXOperand::u64: 
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							if (a != a) a = 0.0f;
							PTXU64 d = round(a, instr.modifier);
							d = min(ULLONG_MAX, d);
							setRegAsU64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s8:
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							if (a != a) a = 0.0;
							a = round(a, instr.modifier);
							PTXS8 d = 0;
							a = min(CHAR_MAX, a);
							d = max(a, CHAR_MIN);
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s16:
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							if (a != a) a = 0.0;
							a = round(a, instr.modifier);
							PTXS16 d = 0;
							a = min(SHRT_MAX, a);
							d = max(a, SHRT_MIN);
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s32:
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							if (a != a) a = 0.0;
							a = round(a, instr.modifier);
							PTXS32 d = 0;
							a = min(INT_MAX, a);
							d = max(a, INT_MIN);
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::s64:
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							if (a != a) a = 0.0;
							PTXS64 d = round(a, instr.modifier);
							setRegAsS64(threadID, instr.d.reg, d);
						}
						break;
					case PTXOperand::f32: 
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							a = round(a, instr.modifier);
							if(instr.modifier & PTXInstruction::sat) {
								if (a != a) a = 0.0;
								a = min(1.0, a);
								a = max(a, 0.0);
							}
							setRegAsF32(threadID, instr.d.reg, 
								sat(instr.modifier, a));							
						}
						break;
					case PTXOperand::f64: 
						{
							PTXF64 a = operandAsF64(threadID, instr.a);
							a = round(a, instr.modifier);
							if(instr.modifier & PTXInstruction::sat) {
								if (a != a) a = 0.0;
								a = min(1.0, a);
								a = max(a, 0.0);
							}
							setRegAsF64(threadID, instr.d.reg, 
								sat(instr.modifier, a));
						}
						break;
					default:
						throw RuntimeException("conversion not implemented", 
							context.PC, instr);
						break;
				}
			}
			break;
			default:
				throw RuntimeException("conversion not implemented", 
					context.PC, instr);
				break;
		}
		
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Div(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a), b = operandAsF32(threadID, instr.b);
			d = sat(instr.modifier, a / b);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a), b = operandAsF64(threadID, instr.b);
			d = a / b;
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS16 d, a = operandAsS16(threadID, instr.a), b = operandAsS16(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Divide by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a / b;
			setRegAsS16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS32 d, a = operandAsS32(threadID, instr.a), b = operandAsS32(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Divide by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a / b;
			setRegAsS32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS64 d, a = operandAsS64(threadID, instr.a), b = operandAsS64(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Divide by zeroa at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a / b;
			setRegAsS64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU16 d, a = operandAsU16(threadID, instr.a), b = operandAsU16(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Divide by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a / b;
			setRegAsU16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU32 d, a = operandAsU32(threadID, instr.a), b = operandAsU32(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Divide by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a / b;
			setRegAsU32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU64 d, a = operandAsU64(threadID, instr.a), b = operandAsU64(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Divide by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a / b;
			setRegAsU64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Ex2(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a);
			d = exp(a * 0.693147f);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Exit(CTAContext &context,
	const PTXInstruction &instr) {
	trace();
	reconvergenceMechanism->eval_Exit(context, instr);
}

void executive::CooperativeThreadArray::normalLoad(int threadID, 
	const PTXInstruction &instr, const char* source) {
	switch (instr.type) {
		case PTXOperand::s8:
			{
				PTXS8 word = *((PTXS8*)source);
#if REPORT_LD
				report( "    Loaded " << word << " from " 
					<< (int*)source );
#endif
				setRegAsS64(threadID, instr.d.reg, word);
			}
			break;
		case PTXOperand::b8:		// fall through
		case PTXOperand::u8:
			{
				PTXU8 word = *((PTXU8*)source);
#if REPORT_LD
				report( "    Loaded " << word << " from " 
					<< (int*)source );
#endif
				setRegAsU64(threadID, instr.d.reg, word);
			}
			break;
		case PTXOperand::s16:		// fall through
			{
				PTXS16 word = *((PTXS16*)source);
#if REPORT_LD
				report( "    Loaded " << word << " from " 
					<< (int*)source );
#endif
				setRegAsS64(threadID, instr.d.reg, word);
			}
			break;
		case PTXOperand::b16:		// fall through
		case PTXOperand::u16:
			{
				PTXU16 word = *((PTXU16*)source);
#if REPORT_LD
				report( "    Loaded " << word << " from " 
					<< (int*)source );
#endif
				setRegAsU64(threadID, instr.d.reg, word);
			}
			break;
		case PTXOperand::f32:
			{
				PTXF32 word = *((PTXF32*)source);
#if REPORT_LD

				report( "    Loaded " << word << " from " 
					<< (int*)source );
#endif
				setRegAsF32(threadID, instr.d.reg, word);
			}
			break;
		case PTXOperand::s32:
			{
				PTXS32 word = *((PTXS32*)source);
#if REPORT_LD
				report( "    Loaded " << word << " from " 
					<< (int*)source );
#endif
				setRegAsS64(threadID, instr.d.reg, word);
			}
			break;
		case PTXOperand::b32:		// fall through
		case PTXOperand::u32:
			{
				PTXU32 word = *((PTXU32*)source);
#if REPORT_LD
				report( "    Loaded " << word << " from " 
					<< (int*)source );
#endif
				setRegAsU64(threadID, instr.d.reg, word);
			}
			break;
		case PTXOperand::f64:		// fall through
		case PTXOperand::b64:		// fall through
		case PTXOperand::s64:		// fall through
		case PTXOperand::u64:
			{
				PTXU64 word = *((PTXU64*)source);
#if REPORT_LD
				report( "    Loaded " << (void*)word << " from " 
					<< (int*)source );
#endif
				setRegAsU64(threadID, instr.d.reg, word);
			}
			break;
		default:
			break;
	}		
}

void executive::CooperativeThreadArray::vectorLoad(int threadID, 
	const PTXInstruction &instr, const char* source, unsigned int elementSize) {

	for (PTXOperand::Array::const_iterator i = instr.d.array.begin(); 
		i != instr.d.array.end(); ++i, source += elementSize) {

		switch (instr.type) {
			case PTXOperand::s8:
				{
					PTXS8 word = *((PTXS8*)source);

#if REPORT_LD
						report( "    Loaded " << word << " from " 
							<< (int*)source );
#endif

					setRegAsS64(threadID, i->reg, word);
				}
				break;
			case PTXOperand::b8:		// fall through
			case PTXOperand::u8:
				{
					PTXU8 word = *((PTXU8*)source);

#if REPORT_LD
						report( "    Loaded " << word << " from " 
							<< (int*)source );
#endif

					setRegAsU64(threadID, i->reg, word);
				}
				break;
			case PTXOperand::s16:
				{
					PTXS16 word = *((PTXS16*)source);

#if REPORT_LD
						report( "    Loaded " << word << " from " 
							<< (int*)source ); 
#endif

					setRegAsS64(threadID, i->reg, word);
				}
				break;
			case PTXOperand::b16:		// fall through
			case PTXOperand::u16:
				{
					PTXU16 word = *((PTXU16*)source);

#if REPORT_LD
						report( "    Loaded " << word << " from " 
							<< (int*)source ); 
#endif

					setRegAsU64(threadID, i->reg, word);
				}
				break;
			case PTXOperand::f32:
			{

				PTXF32 word = *((PTXF32*)((unsigned long long)source));

#if REPORT_LD
					report( "    Loaded " << word << " from " 
						<< (int*)source << " - register " << instr.d.reg << "; alternative " << i->reg); 
#endif

				setRegAsF32(threadID, i->reg, word);
			}
			break;
			case PTXOperand::s32:
				{
					PTXS32 word = *((PTXS32*)source);

#if REPORT_LD
						report( "    Loaded " << word << " from " 
							<< (int*)source ); 
#endif

					setRegAsS64(threadID, i->reg, word);
				}
				break;
			case PTXOperand::b32:		// fall through
			case PTXOperand::u32:
				{
					PTXU32 word = *((PTXU32*)source);

#if REPORT_LD
						report( "    Loaded " << word << " from " 
							<< (int*)source ); 
#endif

					setRegAsU64(threadID, i->reg, word);
				}
				break;
			case PTXOperand::f64:		// fall through
			case PTXOperand::b64:		// fall through
			case PTXOperand::s64:		// fall through
			case PTXOperand::u64:
				{
					PTXU64 word = *((PTXU64*)source);

#if REPORT_LD
						report( "    Loaded " << (void*)word << " from " 
							<< (int*)source ); 
#endif

					setRegAsU64(threadID, i->reg, word);
				}
				break;
			default:
				break;
		}	
	}
}


/*!

*/
void executive::CooperativeThreadArray::eval_Ld(CTAContext &context, 
	const PTXInstruction &instr) {

	size_t elementSize = 0;

	switch (instr.type) {
		case PTXOperand::b8:		// fall through
		case PTXOperand::s8:		// fall through
		case PTXOperand::u8:
			{
				elementSize = sizeof(PTXU8);
			}
			break;
		case PTXOperand::b16:		// fall through
		case PTXOperand::s16:		// fall through
		case PTXOperand::u16:
			{
				elementSize = sizeof(PTXU16);
			}
			break;
		case PTXOperand::f32:		// fall through
		case PTXOperand::b32:		// fall through
		case PTXOperand::s32:		// fall through
		case PTXOperand::u32:
			{
				elementSize = sizeof(PTXU32);
			}
			break;
		case PTXOperand::f64:		// fall through
		case PTXOperand::b64:		// fall through
		case PTXOperand::s64:		// fall through
		case PTXOperand::u64:
			{
				elementSize = sizeof(PTXU64);
			}
			break;
		default:
			throw RuntimeException("unsupported data type", context.PC, instr);
	}

	if (traceEvents) {
		currentEvent.memory_size = elementSize;
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) {
				continue;
			}

			const char *source = 0;

			switch (instr.a.addressMode) {
				case PTXOperand::Indirect:
					source += getRegAsU64(threadID, instr.a.reg);
					break;
				case PTXOperand::Address:
				case PTXOperand::Immediate:
					source += instr.a.imm_uint;
					break;
				default:
					throw RuntimeException(
						"unsupported address mode for source operand", 
						context.PC, instr);
			}

			source += instr.a.offset;
			currentEvent.memory_addresses.push_back((ir::PTXU64)source);
		}
	}

	trace();

	for (int threadID = 0; threadID < threadCount; threadID++) {
		if (!context.predicated(threadID, instr)) {
			continue;
		}

		const char *source = 0;

		switch (instr.a.addressMode) {
			case PTXOperand::Indirect:
				source += getRegAsU64(threadID, instr.a.reg);
				break;
			case PTXOperand::Address:
			case PTXOperand::Immediate:
				source += instr.a.imm_uint;
				break;
			default:
				throw RuntimeException(
					"unsupported address mode for source operand", 
					context.PC, instr);
		}

		source += instr.a.offset;
			
		switch (instr.addressSpace) {
			case PTXInstruction::Param:
				{
					source += (PTXU64) kernel->ParameterMemory;
				}
				break;
			case PTXInstruction::Const:
				{
					source += (PTXU64) kernel->ConstMemory;				
				}
				break;
			case PTXInstruction::Global:
				{	
				}
				break;
			case PTXInstruction::Shared:
				{
					source = (char*)(0xffffffff & (PTXU64) source);
					source += (PTXU64) SharedMemory;
				}
				break;
			case PTXInstruction::Local:
				{
					source += (PTXU64) LocalMemory 
						+ threadID * kernel->localMemorySize();
				}
				break;
			default:
				throw RuntimeException("unsupported address space", 
					context.PC, instr);
		}

		if(instr.d.vec == PTXOperand::v1) {
			normalLoad(threadID, instr, source);		
		}
		else {
			vectorLoad(threadID, instr, source, elementSize);
		}
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Lg2(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXF32 d, a = operandAsF32(threadID, instr.a);
			d = log2(a);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Mad24(CTAContext &context, const PTXInstruction &instr) {
	trace();
	throw RuntimeException("instruction not implemented", context.PC, instr);
}

/*!
	Mad:

		mad[.hi,.lo,.wide][.sat].itype d, a, b, c;
		mad[.rnd][.sat].ftype d, a, b, c;

		t = a * b;
		n = bitwidth of type;
		d = t + c;            // for floating-point and .wide
		d = t<2n-1..n> + c;   // for .hi variant
		d = t<n-1..0> + c;    // for .lo variant

*/
void executive::CooperativeThreadArray::eval_Mad(CTAContext &context, const PTXInstruction &instr) {
	trace();
	PTXOperand::DataType type = instr.type;

	switch (type) {
	case PTXOperand::u16:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU16 a = operandAsU16(threadID, instr.a); 
			PTXU16 b = operandAsU16(threadID, instr.b);

			if (instr.modifier & PTXInstruction::hi) {
				PTXU16 c = operandAsU16(threadID, instr.c);
				PTXU16 t = (PTXU16)(((PTXU32)a * (PTXU32)b) >> 16);
				PTXU16 d = t + c;
				setRegAsU16(threadID, instr.d.reg, d);
			}
			else if (instr.modifier & PTXInstruction::wide) {
				PTXU32 c = operandAsU32(threadID, instr.c);
				PTXU32 t = (PTXU32)a * (PTXU32)b;
				PTXU32 d = t + c;
				setRegAsU32(threadID, instr.d.reg, d);
			}
			else {
				PTXU16 c = operandAsU16(threadID, instr.c);
				PTXU16 t = a * b;
				PTXU16 d = t + c;
				setRegAsU16(threadID, instr.d.reg, d);
			}
		}
	} break;
	case PTXOperand::u32:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU32 a = operandAsU32(threadID, instr.a); 
			PTXU32 b = operandAsU32(threadID, instr.b);

			if (instr.modifier & PTXInstruction::hi) {
				PTXU32 c = operandAsU32(threadID, instr.c);
				PTXU32 t = (PTXU32)(((PTXU64)a * (PTXU64)b) >> 32);
				PTXU32 d = t + c;
				setRegAsU32(threadID, instr.d.reg, d);
			}
			else if (instr.modifier & PTXInstruction::wide) {
				PTXU64 c = operandAsU64(threadID, instr.c);
				PTXU64 t = (PTXU64)a * (PTXU64)b;
				PTXU64 d = t + c;
				setRegAsU64(threadID, instr.d.reg, d);
			}
			else {
				PTXU32 c = operandAsU32(threadID, instr.c);
				PTXU32 t = a * b;
				PTXU32 d = t + c;
				setRegAsU32(threadID, instr.d.reg, d);
			}
		}
	} break;
	case PTXOperand::u64:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU64 d = 0,
				a = operandAsU64(threadID, instr.a), 
				b = operandAsU64(threadID, instr.b), 
				c = operandAsU64(threadID, instr.c);

			if (instr.modifier & PTXInstruction::hi) {
				PTXU64 hi = 0;
				PTXU64 lo = 0;
				hydrazine::multiplyHiLo( hi, lo, a, b );
				d = hi + c;
			}
			else {
				PTXU64 t = a * b;
				d = t + c;
			}
			setRegAsU64(threadID, instr.d.reg, d);
		}
	} break;
	case PTXOperand::s16:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS16 a = operandAsS16(threadID, instr.a); 
			PTXS16 b = operandAsS16(threadID, instr.b);

			if (instr.modifier & PTXInstruction::hi) {
				PTXS16 c = operandAsS16(threadID, instr.c);
				PTXS16 t = (PTXS16)(((PTXS32)a * (PTXS32)b) >> 16);
				PTXS16 d = t + c;
				setRegAsS16(threadID, instr.d.reg, d);
			}
			else if (instr.modifier & PTXInstruction::wide) {
				PTXS32 c = operandAsS32(threadID, instr.c);
				PTXS32 t = (PTXS32)a * (PTXS32)b;
				PTXS32 d = t + c;
				setRegAsS32(threadID, instr.d.reg, d);
			}
			else {
				PTXS16 c = operandAsS16(threadID, instr.c);
				PTXS16 t = a * b;
				PTXS16 d = t + c;
				setRegAsS16(threadID, instr.d.reg, d);
			}
		}
	} break;
	case PTXOperand::s32:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS32 a = operandAsS32(threadID, instr.a); 
			PTXS32 b = operandAsS32(threadID, instr.b);

			if (instr.modifier & PTXInstruction::hi) {
				PTXS32 c = operandAsS32(threadID, instr.c);
				PTXS32 t = (PTXS32)(((PTXS64)a * (PTXS64)b) >> 32);
				PTXS32 d = 0;
				if (instr.modifier & PTXInstruction::sat) {
					PTXS64 td = (PTXS64)t + (PTXS64)c;
					td = max(td, (PTXS64)INT_MIN);
					td = min(td, (PTXS64)INT_MAX);
					d = td;
				}
				else {
					d = t + c;
				}
				setRegAsS32(threadID, instr.d.reg, d);
			}
			else if (instr.modifier & PTXInstruction::wide) {
				PTXS64 c = operandAsS64(threadID, instr.c);
				PTXS64 t = (PTXS64)a * (PTXS64)b;
				PTXS64 d = t + c;
				setRegAsS64(threadID, instr.d.reg, d);
			}
			else {
				PTXS32 c = operandAsS32(threadID, instr.c);
				PTXS32 t = a * b;
				PTXS32 d = t + c;
				setRegAsS32(threadID, instr.d.reg, d);
			}
		}
	} break;
	case PTXOperand::s64:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS64 d = 0,
				a = operandAsS64(threadID, instr.a), 
				b = operandAsS64(threadID, instr.b), 
				c = operandAsS64(threadID, instr.c);

			if (instr.modifier & PTXInstruction::hi) {
				PTXS64 hi = 0;
				PTXS64 lo = 0;
				hydrazine::multiplyHiLo( hi, lo, a, b );
				d = hi + c;
			}
			else {
				PTXS64 t = a * b;
				d = t + c;
			}
			setRegAsS64(threadID, instr.d.reg, d);
		}
	} break;
	case PTXOperand::f32:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXF32 d = 0,
				a = operandAsF32(threadID, instr.a), 
				b = operandAsF32(threadID, instr.b), 
				c = operandAsF32(threadID, instr.c);

			d = a * b + c;
			if (instr.modifier & PTXInstruction::sat) {
				if (d < 0) d = 0; else if (d > 1) d = 1;
			}
			setRegAsF32(threadID, instr.d.reg, d);
		}
	} break;
	case PTXOperand::f64:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXF64 d = 0,
				a = operandAsF64(threadID, instr.a), 
				b = operandAsF64(threadID, instr.b), 
				c = operandAsF64(threadID, instr.c);

			d = a * b + c;
			if (instr.modifier & PTXInstruction::sat) {
				if (d < 0) d = 0; else if (d > 1) d = 1;
			}
			setRegAsF64(threadID, instr.d.reg, d);
		}
	} break;

	default:
		throw RuntimeException("invalid datatype", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Max(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a), b = operandAsF32(threadID, instr.b);
			d = (a > b ? a : b);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a), b = operandAsF64(threadID, instr.b);
			d = (a > b ? a : b);
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS16 d, a = operandAsS16(threadID, instr.a), b = operandAsS16(threadID, instr.b);
			d = (a > b ? a : b);
			setRegAsS16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS32 d, a = operandAsS32(threadID, instr.a), b = operandAsS32(threadID, instr.b);
			d = (a > b ? a : b);
			setRegAsS32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS64 d, a = operandAsS64(threadID, instr.a), b = operandAsS64(threadID, instr.b);
			d = (a > b ? a : b);
			setRegAsS64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU16 d, a = operandAsU16(threadID, instr.a), b = operandAsU16(threadID, instr.b);
			d = (a > b ? a : b);
			setRegAsU16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU32 d, a = operandAsU32(threadID, instr.a), b = operandAsU32(threadID, instr.b);
			d = (a > b ? a : b);
			setRegAsU32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU64 d, a = operandAsU64(threadID, instr.a), b = operandAsU64(threadID, instr.b);
			d = (a > b ? a : b);
			setRegAsU64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Min(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a), b = operandAsF32(threadID, instr.b);
			d = (a < b ? a : b);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a), b = operandAsF64(threadID, instr.b);
			d = (a < b ? a : b);
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS16 d, a = operandAsS16(threadID, instr.a), b = operandAsS16(threadID, instr.b);
			d = (a < b ? a : b);
			setRegAsS16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS32 d, a = operandAsS32(threadID, instr.a), b = operandAsS32(threadID, instr.b);
			d = (a < b ? a : b);
			setRegAsS32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS64 d, a = operandAsS64(threadID, instr.a), b = operandAsS64(threadID, instr.b);
			d = (a < b ? a : b);
			setRegAsS64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU16 d, a = operandAsU16(threadID, instr.a), b = operandAsU16(threadID, instr.b);
			d = (a < b ? a : b);
			setRegAsU16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU32 d, a = operandAsU32(threadID, instr.a), b = operandAsU32(threadID, instr.b);
			d = (a < b ? a : b);
			setRegAsU32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU64 d, a = operandAsU64(threadID, instr.a), b = operandAsU64(threadID, instr.b);
			d = (a < b ? a : b);
			setRegAsU64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Membar(CTAContext &context, const PTXInstruction &instr) {
	trace();
	/*! No need to do anything here. */
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*!

*/
void executive::CooperativeThreadArray::eval_Mov(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();

	if (instr.a.addressMode == PTXOperand::Register) {
		eval_Mov_reg(context, instr);
	}
	else if (instr.a.addressMode == PTXOperand::Special) {
		eval_Mov_sreg(context, instr);		
	}
	else if (instr.a.addressMode == PTXOperand::Immediate) {
		eval_Mov_imm(context, instr);		
	}
	else if (instr.a.addressMode == PTXOperand::Address) {
		eval_Mov_addr(context, instr);
	}
	else {
		throw RuntimeException(std::string("unimplemented address mode ") 
			+ PTXOperand::toString(instr.a.addressMode), context.PC, instr);
	}
}

template<typename D, typename S>
static D gather(S s0, S s1)
{
	D result = s1;
	result <<= sizeof(S) * 8;
	result |= s0;
	return result;
}

template<typename D, typename S>
static D gather(S s0, S s1, S s2, S s3)
{
	D result = s3;
	result <<= sizeof(S) * 8;
	result |= s2;
	result <<= sizeof(S) * 8;
	result |= s1;
	result <<= sizeof(S) * 8;
	result |= s0;
	return result;
}

template<typename D, unsigned int index, unsigned int bytes, typename S>
static D scatter(S s)
{
	PTXU64 mask = 1;
	mask <<= bytes * 8;
	mask -= 1;
	s >>= index * bytes * 8;
	s &= mask;
	return s;
}

void executive::CooperativeThreadArray::eval_Mov_reg(CTAContext &context, 
	const ir::PTXInstruction &instr) {
	for (int threadID = 0; threadID < threadCount; threadID++) {
		if (!context.predicated(threadID, instr)) continue;
		
		switch (instr.type) {
		case PTXOperand::u16:
		case PTXOperand::s16:
			{
				PTXU16 a = operandAsU16(threadID, instr.a);
				setRegAsU16(threadID, instr.d.reg, a);
			}
			break;
		case PTXOperand::b16:
			{
				PTXU16 a = operandAsU16(threadID, instr.a);
				if (instr.a.array.size() == 0) {
					a = operandAsU32(threadID, instr.a);
				}
				else {
					assert(instr.a.array.size() == 2);
					a = gather<PTXB16>(operandAsB8(threadID, instr.a.array[0]), 
						operandAsB8(threadID, instr.a.array[1]));
				}
				if (instr.d.array.size() == 0) {
					setRegAsB16(threadID, instr.d.reg, a);
				}
				else {
					assert(instr.d.array.size() == 2);
					setRegAsB8(threadID, instr.d.array[0].reg, 
						scatter<PTXB8, 0, 1>(a));
					setRegAsB8(threadID, instr.d.array[1].reg, 
						scatter<PTXB8, 1, 1>(a));
				}
			}
			break;
		case PTXOperand::u32:
		case PTXOperand::s32:
			{
				PTXU32 a = operandAsU32(threadID, instr.a);
				setRegAsU32(threadID, instr.d.reg, a);
			}
			break;
		case PTXOperand::b32:
			{
				PTXU32 a = operandAsU32(threadID, instr.a);
				if (instr.a.array.size() == 0) {
					a = operandAsU32(threadID, instr.a);
				}
				else if (instr.a.array.size() == 2) {
					a = gather<PTXB32>(operandAsB16(threadID, 
						instr.a.array[0]), operandAsB16(threadID, 
						instr.a.array[1]));
				}
				else {
					assert(instr.a.array.size() == 4);
					a = gather<PTXB32>(operandAsB8(threadID, instr.a.array[0]), 
						operandAsB8(threadID, instr.a.array[1]), 
						operandAsB8(threadID, instr.a.array[2]), 
						operandAsB8(threadID, instr.a.array[3]));
				}
				if (instr.d.array.size() == 0) {
					setRegAsU32(threadID, instr.d.reg, a);
				}
				else if (instr.d.array.size() == 2) {
					setRegAsU16(threadID, instr.d.array[0].reg, 
						scatter<PTXB16, 0, 2>(a));
					setRegAsU16(threadID, instr.d.array[1].reg, 
						scatter<PTXB16, 1, 2>(a));
				}
				else {
					assert(instr.d.array.size() == 4);
					setRegAsB8(threadID, instr.d.array[0].reg, 
						scatter<PTXB8, 0, 1>(a));
					setRegAsB8(threadID, instr.d.array[1].reg, 
						scatter<PTXB8, 1, 1>(a));
					setRegAsB8(threadID, instr.d.array[2].reg, 
						scatter<PTXB8, 2, 1>(a));
					setRegAsB8(threadID, instr.d.array[3].reg, 
						scatter<PTXB8, 3, 1>(a));
				}
			}
			break;
		case PTXOperand::u64:
		case PTXOperand::s64:
			{
				PTXU64 a = operandAsU64(threadID, instr.a);
				setRegAsU64(threadID, instr.d.reg, a);
			}
			break;
		case PTXOperand::b64:
			{
				PTXU64 a;
				if (instr.a.array.size() == 0) {
					a = operandAsU64(threadID, instr.a);
				}
				else if (instr.a.array.size() == 2) {
					a = gather<PTXB64>(operandAsB32(threadID, 
						instr.a.array[0]), 
						operandAsB32(threadID, instr.a.array[1]));
				}
				else {
					assert(instr.a.array.size() == 4);
					a = gather<PTXB64>(
						operandAsB16(threadID, instr.a.array[0]), 
						operandAsB16(threadID, instr.a.array[1]), 
						operandAsB16(threadID, instr.a.array[2]), 
						operandAsB16(threadID, instr.a.array[3]));
				}
				if (instr.d.array.size() == 0) {
					setRegAsB64(threadID, instr.d.reg, a);
				}
				else if (instr.d.array.size() == 2) {
					setRegAsB32(threadID, instr.d.array[0].reg, 
						scatter<PTXB32, 0, 4>(a));
					setRegAsB32(threadID, instr.d.array[1].reg, 
						scatter<PTXB32, 1, 4>(a));
				}
				else {
					assert(instr.d.array.size() == 4);
					setRegAsB16(threadID, instr.d.array[0].reg, 
						scatter<PTXB16, 0, 2>(a));
					setRegAsB16(threadID, instr.d.array[1].reg, 
						scatter<PTXB16, 1, 2>(a));
					setRegAsB16(threadID, instr.d.array[2].reg, 
						scatter<PTXB16, 2, 2>(a));
					setRegAsB16(threadID, instr.d.array[3].reg, 
						scatter<PTXB16, 3, 2>(a));
				}
			}
			break;
		case PTXOperand::f32:
			{
				setRegAsF32(threadID, instr.d.reg,
					operandAsF32(threadID, instr.a));
			}
			break;
		case PTXOperand::f64:
			{
				setRegAsF64(threadID, instr.d.reg,
					operandAsF64(threadID, instr.a));
			}
			break;
		case PTXOperand::pred:
			{
				setRegAsPredicate(threadID, instr.d.reg,
					operandAsU64(threadID, instr.a));
			}
			break;
		default:
			break;
		}
	}
}

void executive::CooperativeThreadArray::eval_Mov_sreg(CTAContext &context, 
	const ir::PTXInstruction &instr) {
	
	if (instr.type == PTXOperand::u16) {
		int threadID = 0;
		for (PTXU16 z = 0; z < blockDim.z; z++) {
			for (PTXU16 y = 0; y < blockDim.y; y++) {
				for (PTXU16 x = 0; x < blockDim.x; x++, threadID++) {
					if (!context.predicated(threadID, instr)) continue;
					
					PTXU64 d;
					switch (instr.a.special) {
						case PTXOperand::tidX:
							d = x; break;
						case PTXOperand::tidY:
							d = y; break;
						case PTXOperand::tidZ:
							d = z; break;
						case PTXOperand::ntidX:
							d = blockDim.x; break;
						case PTXOperand::ntidY:
							d = blockDim.y; break;
						case PTXOperand::ntidZ:
							d = blockDim.z; break;
						case PTXOperand::ctaIdX:
							d = blockId.x; break;
						case PTXOperand::ctaIdY:
							d = blockId.y; break;
						case PTXOperand::ctaIdZ:
							d = blockId.z; break;
						case PTXOperand::nctaIdX:
							d = gridDim.x; break;
						case PTXOperand::nctaIdY:
							d = gridDim.y; break;
						case PTXOperand::clock:
							d = clock; break;
						default:
							throw RuntimeException("unimplemented special register class", context.PC, instr);
					}
					setRegAsU64(threadID, instr.d.reg, d);
				}
			}
		}
		
	}
	else if (instr.type == PTXOperand::u32) {
		int threadID = 0;
		for (PTXU16 z = 0; z < blockDim.z; z++) {
			for (PTXU16 y = 0; y < blockDim.y; y++) {
				for (PTXU16 x = 0; x < blockDim.x; x++, threadID++) {
					if (!context.predicated(threadID, instr)) continue;
					
					PTXU64 d;
					switch (instr.a.special) {
						case PTXOperand::clock:
							d = clock; break;
						case PTXOperand::warpSize:
							d = blockDim.z * blockDim.y * blockDim.x;
							break;
						default:
							throw RuntimeException("Special register not valid for U32 type", context.PC, instr);
					}
					setRegAsU64(threadID, instr.d.reg, d);
				}
			}
		}
		
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

void executive::CooperativeThreadArray::eval_Mov_imm(CTAContext &context,
	const ir::PTXInstruction &instr) {
	for (int threadID = 0; threadID < threadCount; threadID++) {
		if (!context.predicated(threadID, instr)) continue;
		
		switch (instr.d.type) {
		case PTXOperand::u16:
		case PTXOperand::s16:
		case PTXOperand::b16:
			{
				PTXU16 a = operandAsU16(threadID, instr.a);
				setRegAsU16(threadID, instr.d.reg, a);
			}
			break;
		case PTXOperand::u32:
		case PTXOperand::s32:
		case PTXOperand::b32:
			{
				PTXU32 a = operandAsU32(threadID, instr.a);
				setRegAsU32(threadID, instr.d.reg, a);
			}
			break;
		case PTXOperand::u64:
		case PTXOperand::s64:
		case PTXOperand::b64:
			{
				PTXU64 a = operandAsU64(threadID, instr.a);
				setRegAsU64(threadID, instr.d.reg, a);
			}
			break;
		case PTXOperand::f32:
			{
				setRegAsF32(threadID, instr.d.reg,
					operandAsF32(threadID, instr.a));
			}
			break;
		case PTXOperand::f64:
			{
				setRegAsF64(threadID, instr.d.reg,
					operandAsF64(threadID, instr.a));
			}
			break;
		case PTXOperand::pred:
			{
				setRegAsPredicate(threadID, instr.d.reg,
					operandAsU64(threadID, instr.a));
			}
			break;
		default:
			break;
		}
	}
}

void executive::CooperativeThreadArray::eval_Mov_indirect(CTAContext &context,
	const ir::PTXInstruction &instr) {
	
}

void executive::CooperativeThreadArray::eval_Mov_addr(CTAContext &context,
	const ir::PTXInstruction &instr) {
	eval_Mov_imm(context, instr);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*!

*/
void executive::CooperativeThreadArray::eval_Mul24(CTAContext &context, const PTXInstruction &instr) {
	trace();

	if (instr.type == PTXOperand::u32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU64 a = operandAsU32(threadID, instr.a), b = operandAsU32(threadID, instr.b);
			PTXU64 dw = ( a & 0x00ffffff ) * ( b & 0x00ffffff );
			PTXU32 d;
			if (instr.modifier & PTXInstruction::hi) {
				d = ((dw >> 12) & 0xffffffff);
			}
			else {
				d = (dw & 0xffffffff);
			}
			setRegAsU32(threadID, instr.d.reg, d);
		
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS64 a = operandAsS32(threadID, instr.a), b = operandAsS32(threadID, instr.b);
			
			if( a < 0 )
			{
				a |= 0xffffffffff000000ULL;
			}
			else
			{
				a &= 0x00ffffff;
			}
			if( b < 0 )
			{
				b |= 0xffffffffff000000ULL;
			}
			else
			{
				b &= 0x00ffffff;
			}
			
			PTXS64 dw = a * b;
			PTXS32 d;
			if (instr.modifier & PTXInstruction::hi) {
				d = ((dw >> 12) & 0xffffffff);
			}
			else {
				d = dw;
			}
			setRegAsS32(threadID, instr.d.reg, d);

		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Mul(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a), b = operandAsF32(threadID, instr.b);
			d = sat(instr.modifier, a * b);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a), b = operandAsF64(threadID, instr.b);
			d = a * b;
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU32 a = operandAsU16(threadID, instr.a), b = operandAsU16(threadID, instr.b);
			if (instr.modifier & PTXInstruction::wide) {
				PTXU32 d = a * b;
				setRegAsU32(threadID, instr.d.reg, d);
			}
			else {
				PTXU32 dw = a * b;
				PTXU16 d;
				if (instr.modifier & PTXInstruction::hi) {
					d = ((dw >> 16) & 0x0ffff);
				}
				else {
					d = (dw & 0x0ffff);
				}
				setRegAsU16(threadID, instr.d.reg, d);
			}
		}
	}
	else if (instr.type == PTXOperand::u32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU64 a = operandAsU32(threadID, instr.a), b = operandAsU32(threadID, instr.b);
			if (instr.modifier & PTXInstruction::wide) {
				PTXU64 d = a * b;
				setRegAsU64(threadID, instr.d.reg, d);
			}
			else {
				PTXU64 dw = a * b;
				PTXU32 d;
				if (instr.modifier & PTXInstruction::hi) {
					d = ((dw >> 32) & 0x0ffffffff);
				}
				else {
					d = (dw & 0x0ffffffff);
				}
				setRegAsU32(threadID, instr.d.reg, d);
			}
		}
	}
	else if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS32 a = operandAsS16(threadID, instr.a), b = operandAsS16(threadID, instr.b);
			if (instr.modifier & PTXInstruction::wide) {
				PTXS32 d = a * b;
				setRegAsS32(threadID, instr.d.reg, d);
			}
			else {
				PTXS32 dw = a * b;
				PTXS16 d;
				if (instr.modifier & PTXInstruction::hi) {
					d = ((dw >> 16) & 0x0ffff);
				}
				else {
					d = (dw & 0x0ffff);
				}
				setRegAsS16(threadID, instr.d.reg, d);
			}
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS64 a = operandAsS32(threadID, instr.a), b = operandAsS32(threadID, instr.b);
			if (instr.modifier & PTXInstruction::wide) {
				PTXS64 d = a * b;
				setRegAsS64(threadID, instr.d.reg, d);
			}
			else {
				PTXS64 dw = a * b;
				PTXS32 d;
				if (instr.modifier & PTXInstruction::hi) {
					d = ((dw >> 32) & 0x0ffffffff);
				}
				else {
					d = dw;
				}
				setRegAsS32(threadID, instr.d.reg, d);
			}
		}
	}
	else if (instr.type == PTXOperand::s64) {
		if (instr.modifier & PTXInstruction::lo) {
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				PTXS64 d, a = operandAsS64(threadID, instr.a), 
					b = operandAsS64(threadID, instr.b);
				d = a * b;
				setRegAsS64(threadID, instr.d.reg, d);
			}
		}
		else {
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				PTXS64 d, a = operandAsS64(threadID, instr.a), 
					b = operandAsS64(threadID, instr.b);
				PTXS64 hi = 0;
				PTXS64 lo = 0;
				hydrazine::multiplyHiLo( hi, lo, a, b );
				d = hi;
				setRegAsS64(threadID, instr.d.reg, d);
			}
		}
	} 
	else if (instr.type == PTXOperand::u64) {
		if (instr.modifier & PTXInstruction::lo) {
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				PTXU64 d, a = operandAsU64(threadID, instr.a), 
					b = operandAsU64(threadID, instr.b);
				d = a * b;
				setRegAsU64(threadID, instr.d.reg, d);
			}
		}
		else {
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				PTXU64 d, a = operandAsU64(threadID, instr.a), 
					b = operandAsU64(threadID, instr.b);
				PTXU64 hi = 0;
				PTXU64 lo = 0;
				hydrazine::multiplyHiLo( hi, lo, a, b );
				d = hi;
				setRegAsU64(threadID, instr.d.reg, d);
			}
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Neg(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a);
			d = -a;
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a);
			d = -a;
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS16 d, a = operandAsS16(threadID, instr.a);
			d = -a;
			setRegAsS16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS32 d, a = operandAsS32(threadID, instr.a);
			d = -a;
			setRegAsS32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS64 d, a = operandAsS64(threadID, instr.a);
			d = -a;
			setRegAsS64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Not(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::pred) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			bool d, a = getRegAsPredicate(threadID, instr.a.reg);
			d = !a;
			setRegAsPredicate(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB16 d, a = operandAsB16(threadID, instr.a);
			d = ~a;
			setRegAsB16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB32 d, a = operandAsB32(threadID, instr.a);
			d = ~a;
			setRegAsB32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB64 d, a = operandAsB64(threadID, instr.a);
			d = ~a;
			setRegAsB64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Or(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::pred) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			bool d, a = getRegAsPredicate(threadID, instr.a.reg), 
				b = getRegAsPredicate(threadID, instr.b.reg);
			d = b || a;
			setRegAsPredicate(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB16 d, a = operandAsB16(threadID, instr.a), 
				b = operandAsB16(threadID, instr.b);
			d = a | b;
			setRegAsB16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB32 d, a = operandAsB32(threadID, instr.a), 
				b = operandAsB32(threadID, instr.b);
			d = a | b;
			setRegAsB32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB64 d, a = operandAsB64(threadID, instr.a), 
				b = operandAsB64(threadID, instr.b);
			d = a | b;
			setRegAsB64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Pmevent(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();
	/*! No need to do anything here. */
}

/*!

*/
void executive::CooperativeThreadArray::eval_Rcp(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a);
			d = 1.0f/a;
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a);
			d = 1.0/a;
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_Red(CTAContext &context, const PTXInstruction &instr) {
	trace();
	throw RuntimeException("instruction not implemented", context.PC, instr);
}

/*!

*/
void executive::CooperativeThreadArray::eval_Rem(CTAContext &context,
	const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS16 d, a = operandAsS16(threadID, instr.a),
				b = operandAsS16(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Modulus by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a % b;
			setRegAsS16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS32 d, a = operandAsS32(threadID, instr.a),
				b = operandAsS32(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Modulus by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a % b;
			setRegAsS32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS64 d, a = operandAsS64(threadID, instr.a),
				b = operandAsS64(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Modulus by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a % b;
			setRegAsS64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU16 d, a = operandAsU16(threadID, instr.a),
				b = operandAsU16(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Modulus by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a % b;
			setRegAsU16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU32 d, a = operandAsU32(threadID, instr.a),
				b = operandAsU32(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Modulus by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a % b;
			setRegAsU32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU64 d, a = operandAsU64(threadID, instr.a), 
				b = operandAsU64(threadID, instr.b);
			if(b == 0) {
				throw RuntimeException("Modulus by zero at: " 
					+ kernel->location(context.PC), context.PC, instr);
			}
			d = a % b;
			setRegAsU64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Ret(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();
	throw RuntimeException("instruction not implemented", context.PC, instr);
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Rsqrt(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a);
			d = 1.0f/(PTXF32)sqrt(a);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a);
			d = 1.0/sqrt(a);
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!
	sad.type d, a, b, c;

	d = c + ((a<b) ? b-a : a-b);

.type = { .u16, .u32, .u64,
          .s16, .s32, .s64 };

*/		
void executive::CooperativeThreadArray::eval_Sad(CTAContext &context, const PTXInstruction &instr) {
	trace();
	switch (instr.type) {
	case PTXOperand::u16:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU16 d, a = operandAsU16(threadID, instr.a),
				b = operandAsU16(threadID, instr.b),
				c = operandAsU16(threadID, instr.c);

			d = c + ((a < b) ? b-a : a-b);

			setRegAsU16(threadID, instr.d.reg, d);
		}
	} break;
	case PTXOperand::u32:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU32 d, a = operandAsU32(threadID, instr.a),
				b = operandAsU32(threadID, instr.b),
				c = operandAsU32(threadID, instr.c);

			d = c + ((a < b) ? b-a : a-b);

			setRegAsU32(threadID, instr.d.reg, d);
		}
	} break;
	case PTXOperand::u64:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU64 d, a = operandAsU64(threadID, instr.a),
				b = operandAsU64(threadID, instr.b),
				c = operandAsU64(threadID, instr.c);

			d = c + ((a < b) ? b-a : a-b);

			setRegAsU64(threadID, instr.d.reg, d);
		}
	} break;
	case PTXOperand::s16:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS16 d, a = operandAsS16(threadID, instr.a),
				b = operandAsS16(threadID, instr.b),
				c = operandAsS16(threadID, instr.c);

			d = c + ((a < b) ? b-a : a-b);

			setRegAsS16(threadID, instr.d.reg, d);
		}
	} break;
	case PTXOperand::s32:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS32 d, a = operandAsS32(threadID, instr.a),
				b = operandAsS32(threadID, instr.b),
				c = operandAsS32(threadID, instr.c);

			d = c + ((a < b) ? b-a : a-b);

			setRegAsS32(threadID, instr.d.reg, d);
		}
	} break;
	case PTXOperand::s64:
	{
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS64 d, a = operandAsS64(threadID, instr.a),
				b = operandAsS64(threadID, instr.b),
				c = operandAsS64(threadID, instr.c);

			d = c + ((a < b) ? b-a : a-b);

			setRegAsS64(threadID, instr.d.reg, d);
		}
	} break;
	default:
		throw RuntimeException("invalid datatype", context.PC, instr);
	}
}

/*!
	Select between source operands according to the predicate value
selp.type d, a, b, c;

.type = { .b16, .b32, .b64,
          .u16, .u32, .u64,
          .s16, .s32, .s64,
                .f32, .f64 };

*/
void executive::CooperativeThreadArray::eval_SelP(CTAContext &context, const PTXInstruction &instr) {
	trace();

	switch (instr.type) {
		case PTXOperand::b16:	// fall through
		case PTXOperand::s16:	// fall through
		case PTXOperand::u16:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				PTXU16 a = operandAsU16(threadID, instr.a), b = operandAsU16(threadID, instr.b);
				bool c = getRegAsPredicate(threadID, instr.c.reg);	// read the predicate register
				PTXU16 d = (c ? a : b);
				
				setRegAsU16(threadID, instr.d.reg, d);
			}
		}
			break;
		
		case PTXOperand::s32:	// fall through
		case PTXOperand::b32:	// fall through
		case PTXOperand::f32:	// fall through
		case PTXOperand::u32:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				PTXU32 a = operandAsU32(threadID, instr.a), b = operandAsU32(threadID, instr.b);
				bool c = getRegAsPredicate(threadID, instr.c.reg);	// read the predicate register
				PTXU32 d = (c ? a : b);
				
				setRegAsU32(threadID, instr.d.reg, d);
			}
		}
			break;
		
		case PTXOperand::f64:	// fall through
		case PTXOperand::s64:	// fall through
		case PTXOperand::b64:	// fall through
		case PTXOperand::u64:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				PTXU64 a = operandAsU64(threadID, instr.a), b = operandAsU64(threadID, instr.b);
				bool c = getRegAsPredicate(threadID, instr.c.reg);	// read the predicate register
				PTXU64 d = (c ? a : b);

				reportE( REPORT_SELP, "  thread[" << threadID << "] d = 0x" << hex << d << ", " 
					<< instr.d.identifier << " = " << getRegAsU64(threadID, instr.d.reg) << dec);
				
				setRegAsU64(threadID, instr.d.reg, d);
			}
		}
			break;
		default:
			throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!
	Compare two numeric values with a relational operator and [optionally] combine this result
	with a predicate value by applying a boolean operator

setp.CmpOp.type p[|q], a, b;
setp.CmpOp.BoolOp.type p[|q], a, b, [!]c;

.type = { .b16, .b32, .b64,
	.u16, .u32, .u64,
	.s16, .s32, .s64,
	.f32, .f64 };

*/
void executive::CooperativeThreadArray::eval_SetP(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();
	
	switch (instr.type) {
		
		// unsigned int types [extended to 64-bit uint]
		case PTXOperand::b16:
		case PTXOperand::b32:
		case PTXOperand::b64:
		case PTXOperand::u16:
		case PTXOperand::u32:
		case PTXOperand::u64:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				bool c = true;	// read predicate somehow
				bool t = false;
				
				PTXU64 a, b;

				switch (instr.type) {
					case PTXOperand::s16:
					case PTXOperand::b16:
					case PTXOperand::u16:
						a = (PTXU64)operandAsU16(threadID, instr.a) & 0x0ffff;
						b = (PTXU64)operandAsU16(threadID, instr.b) & 0x0ffff;
						break;
					case PTXOperand::s32:
					case PTXOperand::u32:
					case PTXOperand::b32:
						a = (PTXU64)operandAsU32(threadID, instr.a) & 0x0ffffffff;
						b = (PTXU64)operandAsU32(threadID, instr.b) & 0x0ffffffff;
						break;
					default:
						a = operandAsU64(threadID, instr.a);
						b = operandAsU64(threadID, instr.b);
						break;
				}

				if (instr.c.addressMode == PTXOperand::Register) {
					c = getRegAsPredicate(threadID, instr.c.reg);
				}
				
				// any branch predictor worth its salt will get this wrong twice or less
				switch (instr.comparisonOperator) {
					case PTXInstruction::Eq:
						t = (a == b);
						break;
					case PTXInstruction::Ne:
						t = (a != b);
						break;
					
					case PTXInstruction::Lo:	// fall through
					case PTXInstruction::Lt:
						t = (a < b);
						break;

					case PTXInstruction::Ls:	// fall through
					case PTXInstruction::Le:
						t = (a <= b);
						break;
					case PTXInstruction::Hi:	// fall through
					case PTXInstruction::Gt:
						t = (a > b);
						break;
					case PTXInstruction::Hs:	// fall through
					case PTXInstruction::Ge:
						t = (a >= b);
						break;
					default:
						throw RuntimeException(
							"invalid comparison operator for unsigned int type",
							context.PC, instr);
				}
				
				// now apply the bool op
				bool p = false, q = false;
				
				switch (instr.booleanOperator) {
					case PTXInstruction::BoolAnd:
						p = (t && c);
						q = (!t && c);
						break;
					case PTXInstruction::BoolOr:
						p = (t || c);
						q = (!t ||c);
						break;
					case PTXInstruction::BoolXor:
						p = (t && !c) || (!t && c);
						q = (!t && !c) || (t && c);
						break;
					default:
						p = t;
						q = !t;
						break;
				}

				reportE(REPORT_SETP, "    " << instr.a.identifier << " = " << a 
					<< ", " << instr.b.identifier << " = " << b 
					<< " condition = " << t << ", input = " << c << " " 
					<< instr.d.identifier << " = " << p << ", q = " << q );
									
				setRegAsPredicate(threadID, instr.d.reg, p);
				if (instr.pq.addressMode != PTXOperand::Invalid) {
					setRegAsPredicate(threadID, instr.pq.reg, q);
				}
			}
		}
		break;
		
		// signed int types [extended to 64-bit int]
		case PTXOperand::s16:
		case PTXOperand::s32:
		case PTXOperand::s64:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				bool c = true;	// read operator somehow
				bool t = false;

				PTXS64 a, b;

				switch (instr.type) {
					case PTXOperand::s16:
						a = (PTXS64)operandAsS16(threadID, instr.a);
						b = (PTXS64)operandAsS16(threadID, instr.b);
						break;
					case PTXOperand::s32:
						a = (PTXS64)operandAsS32(threadID, instr.a);
						b = (PTXS64)operandAsS32(threadID, instr.b);
						break;
					default:
						a = operandAsS64(threadID, instr.a);
						b = operandAsS64(threadID, instr.b);
						break;
				}			
				
				if (instr.c.addressMode == PTXOperand::Register) {
					c = getRegAsPredicate(threadID, instr.c.reg);
				}
				
				// any branch predictor worth its salt will get this wrong twice or less
				switch (instr.comparisonOperator) {
				
					case PTXInstruction::Eq:
						t = (a == b);
						break;
					
					case PTXInstruction::Ne:
						t = (a != b);
						break;
					
					case PTXInstruction::Lo:	// fall through
					case PTXInstruction::Lt:
						t = (a < b);
						break;

					case PTXInstruction::Ls:	// fall through
					case PTXInstruction::Le:
						t = (a <= b);
						break;
					
					case PTXInstruction::Hi:	// fall through
					case PTXInstruction::Gt:
						t = (a > b);
						break;
					
					case PTXInstruction::Hs:	// fall through
					case PTXInstruction::Ge:
						t = (a >= b);
						break;
					
					default:
						throw RuntimeException("invalid comparison operator for unsigned int type", context.PC, instr);
				}
				
				// now apply the bool op
				bool p = false, q = false;
				switch (instr.booleanOperator) {
					case PTXInstruction::BoolAnd:
						p = (t && c);
						q = (!t && c);
						break;
					case PTXInstruction::BoolOr:
						p = (t || c);
						q = (!t || c);
						break;
					case PTXInstruction::BoolXor:
						p = (t && !c) || (!t && c);
						q = (!t && !c) || (t && c);
						break;
					default:
						p = t;
						q = !t;
						break;
				}

				reportE(REPORT_SETP, "    " << instr.a.identifier << " = " << a 
					<< ", " << instr.b.identifier << " = " << b 
					<< " condition = " << t << ", input = " << c << " " 
					<< instr.d.identifier << " = " << p << ", q = " << q );
				
				setRegAsPredicate(threadID, instr.d.reg, p);
				if (instr.pq.addressMode != PTXOperand::Invalid) {
					setRegAsPredicate(threadID, instr.pq.reg, q);
				}
			}
		}
		break;
		
		// single-precision float
		case PTXOperand::f32:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				PTXF32 a = operandAsF32(threadID, instr.a), b = operandAsF32(threadID, instr.b);
				bool c = true;	// read operator somehow
				bool t = false;
				
				if (instr.c.addressMode == PTXOperand::Register) {
					c = getRegAsPredicate(threadID, instr.c.reg);
				}
				
				// any branch predictor worth its salt will get this wrong twice or less
				switch (instr.comparisonOperator) {
					case PTXInstruction::Equ:
					case PTXInstruction::Eq:
						t = (a == b);
						break;
					case PTXInstruction::Neu:
					case PTXInstruction::Ne:
						t = (a != b);
						break;
					
					case PTXInstruction::Ltu:
					case PTXInstruction::Lo:	// fall through
					case PTXInstruction::Lt:
						t = (a < b);
						break;

					case PTXInstruction::Leu:
					case PTXInstruction::Ls:	// fall through
					case PTXInstruction::Le:
						t = (a <= b);
						break;
					
					case PTXInstruction::Gtu:
					case PTXInstruction::Hi:	// fall through
					case PTXInstruction::Gt:
						t = (a > b);
						break;
					
					case PTXInstruction::Geu:
					case PTXInstruction::Hs:	// fall through
					case PTXInstruction::Ge:
						t = (a >= b);
						break;

					case PTXInstruction::Num:
						t = !isF32NaN(a) && !isF32NaN(a);
						break;
					case PTXInstruction::Nan:
						t = isF32NaN(a) || isF32NaN(a);					
						break;

					default:
						throw RuntimeException("invalid comparison operator for unsigned int type", context.PC, instr);
				}
								
				// now apply the bool op
				bool p = false, q = false;
				switch (instr.booleanOperator) {
					case PTXInstruction::BoolAnd:
						p = (t && c);
						q = (!t && c);
						break;
					case PTXInstruction::BoolOr:
						p = (t || c);
						q = (!t || c);
						break;
					case PTXInstruction::BoolXor:
						p = (t && !c) || (!t && c);
						q = (!t && !c) || (t && c);
						break;
					default:
						p = t;
						q = !t;
						break;
				}

				reportE(REPORT_SETP, "    " << instr.a.identifier << " = " << a 
					<< ", " << instr.b.identifier << " = " << b 
					<< " condition = " << t << ", input = " << c << " " 
					<< instr.d.identifier << " = " << p << ", q = " << q );
				
				setRegAsPredicate(threadID, instr.d.reg, p);
				if (instr.pq.addressMode != PTXOperand::Invalid) {
					setRegAsPredicate(threadID, instr.pq.reg, q);
				}
			}
		}
		break;
		
		// double-precision float
		case PTXOperand::f64:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				PTXF64 a = operandAsF64(threadID, instr.a), b = operandAsF64(threadID, instr.b);
				bool c = true;
				bool t = false;
				
				if (instr.c.addressMode == PTXOperand::Register) {
					c = getRegAsPredicate(threadID, instr.c.reg);
				}
				
				// any branch predictor worth its salt will get this wrong twice or less
				switch (instr.comparisonOperator) {
				
					case PTXInstruction::Equ:
					case PTXInstruction::Eq:
						t = (a == b);
						break;
					
					case PTXInstruction::Neu:
					case PTXInstruction::Ne:
						t = (a != b);
						break;
					
					case PTXInstruction::Ltu:
					case PTXInstruction::Lo:	// fall through
					case PTXInstruction::Lt:
						t = (a < b);
						break;

					case PTXInstruction::Leu:
					case PTXInstruction::Ls:	// fall through
					case PTXInstruction::Le:
						t = (a <= b);
						break;
					
					case PTXInstruction::Gtu:
					case PTXInstruction::Hi:	// fall through
					case PTXInstruction::Gt:
						t = (a > b);
						break;
					
					case PTXInstruction::Geu:
					case PTXInstruction::Hs:	// fall through
					case PTXInstruction::Ge:
						t = (a >= b);
						break;

					case PTXInstruction::Num:
						t = !isF64NaN(a) && !isF64NaN(a);
						break;
					case PTXInstruction::Nan:
						t = isF64NaN(a) || isF64NaN(a);					
						break;

					default:
						throw RuntimeException("invalid comparison operator for unsigned int type", context.PC, instr);
				}				

				
				// now apply the bool op
				bool p = false, q = false;
				switch (instr.booleanOperator) {
					case PTXInstruction::BoolAnd:
						p = (t && c);
						q = (!t && c);
						break;
					case PTXInstruction::BoolOr:
						p = (t || c);
						q = (!t || c);
						break;
					case PTXInstruction::BoolXor:
						p = (t && !c) || (!t && c);
						q = (!t && !c) || (t && c);
						break;
					default:
						p = t;
						q = !t;
						break;
				}

				reportE(REPORT_SETP, "    " << instr.a.identifier << " = " << a 
					<< ", " << instr.b.identifier << " = " << b 
					<< " condition = " << t << ", input = " << c << " " 
					<< instr.d.identifier << " = " << p << ", q = " << q );
				
				setRegAsPredicate(threadID, instr.d.reg, p);
				if (instr.pq.addressMode != PTXOperand::Invalid) {
					setRegAsPredicate(threadID, instr.pq.reg, q);
				}
			}
		}
		break;
		
		default:
			throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!
	PTX set instruction

	t = (a CmpOp b) ? 1 : 0;
	if (isFloat(dtype))
		d = BoolOp(t, c) ? 1.0f : 0x00000000;
	else
		d = BoolOp(t, c) ? 0xFFFFFFFF : 0x00000000;

*/
void executive::CooperativeThreadArray::eval_Set(CTAContext &context, const PTXInstruction &instr) {
	trace();
	
	switch (instr.a.type) {
		
		// unsigned int types [extended to 64-bit uint]
		case PTXOperand::b16:
		case PTXOperand::b32:
		case PTXOperand::b64:
		case PTXOperand::u16:
		case PTXOperand::u32:
		case PTXOperand::u64:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				bool c = true;	// read predicate somehow
				bool t = false;
				
				PTXU64 a, b;

				switch (instr.a.type) {
					case PTXOperand::u16:
					case PTXOperand::b16:
					case PTXOperand::s16:
						a = (PTXU64)operandAsU16(threadID, instr.a);
						b = (PTXU64)operandAsU16(threadID, instr.b);
						break;
					case PTXOperand::b32:
					case PTXOperand::s32:
					case PTXOperand::u32:
						a = (PTXU64)operandAsU32(threadID, instr.a);
						b = (PTXU64)operandAsU32(threadID, instr.b);
						break;
					default:
						a = operandAsU64(threadID, instr.a);
						b = operandAsU64(threadID, instr.b);
						break;
				}	

				if (instr.c.addressMode == PTXOperand::Register) {
					c = getRegAsPredicate(threadID, instr.c.reg);
				}
				
				// any branch predictor worth its salt will get this wrong twice or less
				switch (instr.comparisonOperator) {
					case PTXInstruction::Eq:
						t = (a == b);
						break;
					case PTXInstruction::Ne:
						t = (a != b);
						break;
					
					case PTXInstruction::Lo:	// fall through
					case PTXInstruction::Lt:
						t = (a < b);
						break;

					case PTXInstruction::Ls:	// fall through
					case PTXInstruction::Le:
						t = (a <= b);
						break;
					case PTXInstruction::Hi:	// fall through
					case PTXInstruction::Gt:
						t = (a > b);
						break;
					case PTXInstruction::Hs:	// fall through
					case PTXInstruction::Ge:
						t = (a >= b);
						break;
					default:
						throw RuntimeException("invalid comparison operator for unsigned int type", context.PC, instr);
				}
				
				// now apply the bool op
				switch (instr.booleanOperator) {
					case PTXInstruction::BoolAnd:
						t = (t && c);
						break;
					case PTXInstruction::BoolOr:
						t = (t || c);
						break;
					case PTXInstruction::BoolXor:
						t = (t && !c) || (!t && c);
						break;
					default:
						break;
				}

				switch (instr.type) {
					case PTXOperand::s32:
					case PTXOperand::u32:
						setRegAsU32(threadID, instr.d.reg, (t ? 0xFFFFFFFF : 0x00));
						break;
					case PTXOperand::f32:
						setRegAsF32(threadID, instr.d.reg, (t ? 1.0f : 0.0f));
						break;
					default:
						break;
				}
			}
		}
		break;
		
		// signed int types [extended to 64-bit int]
		case PTXOperand::s16:
		case PTXOperand::s32:
		case PTXOperand::s64:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				bool c = true;	// read operator somehow
				bool t = false;

				PTXS64 a, b;

				switch (instr.a.type) {
					case PTXOperand::s16:
					case PTXOperand::u16:
					case PTXOperand::b16:
						a = (PTXS64)operandAsS16(threadID, instr.a);
						b = (PTXS64)operandAsS16(threadID, instr.b);
						break;
					case PTXOperand::b32:
					case PTXOperand::u32:
					case PTXOperand::s32:
						a = (PTXS64)operandAsS32(threadID, instr.a);
						b = (PTXS64)operandAsS32(threadID, instr.b);
						break;
					default:
						a = operandAsS64(threadID, instr.a);
						b = operandAsS64(threadID, instr.b);
						break;
				}			
				
				if (instr.c.addressMode == PTXOperand::Register) {
					c = getRegAsPredicate(threadID, instr.c.reg);
				}
				
				// any branch predictor worth its salt will get this wrong twice or less
				switch (instr.comparisonOperator) {
				
					case PTXInstruction::Eq:
						t = (a == b);
						break;
					
					case PTXInstruction::Ne:
						t = (a != b);
						break;
					
					case PTXInstruction::Lo:	// fall through
					case PTXInstruction::Lt:
						t = (a < b);
						break;

					case PTXInstruction::Ls:	// fall through
					case PTXInstruction::Le:
						t = (a <= b);
						break;
					
					case PTXInstruction::Hi:	// fall through
					case PTXInstruction::Gt:
						t = (a > b);
						break;
					
					case PTXInstruction::Hs:	// fall through
					case PTXInstruction::Ge:
						t = (a >= b);
						break;
					
					default:
						throw RuntimeException("invalid comparison operator for unsigned int type", context.PC, instr);
				}
				
				// now apply the bool op
				switch (instr.booleanOperator) {
					case PTXInstruction::BoolAnd:
						t = (t && c);
						break;
					case PTXInstruction::BoolOr:
						t = (t || c);
						break;
					case PTXInstruction::BoolXor:
						t = (t && !c) || (!t && c);
						break;
					default:
						break;
				}

				switch (instr.type) {
					case PTXOperand::s32:
					case PTXOperand::u32:
						setRegAsU32(threadID, instr.d.reg, (t ? 0xFFFFFFFF : 0x00));
						break;
					case PTXOperand::f32:
						setRegAsF32(threadID, instr.d.reg, (t ? 1.0f : 0.0f));
						break;
					default:
						break;
				}
			}
		}
		break;
		
		// single-precision float
		case PTXOperand::f32:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				PTXF32 a = operandAsF32(threadID, instr.a), b = operandAsF32(threadID, instr.b);
				bool c = true;	// read operator somehow
				bool t = false;
				
				if (instr.c.addressMode == PTXOperand::Register) {
					c = getRegAsPredicate(threadID, instr.c.reg);
				}
				
				// any branch predictor worth its salt will get this wrong twice or less
				switch (instr.comparisonOperator) {
					case PTXInstruction::Equ:
					case PTXInstruction::Eq:
						t = (a == b);
						break;
					case PTXInstruction::Neu:
					case PTXInstruction::Ne:
						t = (a != b);
						break;
					
					case PTXInstruction::Ltu:
					case PTXInstruction::Lo:	// fall through
					case PTXInstruction::Lt:
						t = (a < b);
						break;

					case PTXInstruction::Leu:
					case PTXInstruction::Ls:	// fall through
					case PTXInstruction::Le:
						t = (a <= b);
						break;
					
					case PTXInstruction::Gtu:
					case PTXInstruction::Hi:	// fall through
					case PTXInstruction::Gt:
						t = (a > b);
						break;
					
					case PTXInstruction::Geu:
					case PTXInstruction::Hs:	// fall through
					case PTXInstruction::Ge:
						t = (a >= b);
						break;

					case PTXInstruction::Num:
					case PTXInstruction::Nan:
						break;

					default:
						throw RuntimeException("invalid comparison operator for unsigned int type", context.PC, instr);
				}
				
				switch (instr.comparisonOperator) {
					case PTXInstruction::Equ:
					case PTXInstruction::Neu:
					case PTXInstruction::Ltu:
					case PTXInstruction::Leu:
					case PTXInstruction::Gtu:
					case PTXInstruction::Geu:
					case PTXInstruction::Num:
					case PTXInstruction::Nan:
						// if either is NaN, set t to true
						t = (isF32NaN(a) || isF32NaN(b) || t);
						break;
					default:
						break;
				}
				
				// now apply the bool op
				switch (instr.booleanOperator) {
					case PTXInstruction::BoolAnd:
						t = (t && c);
						break;
					case PTXInstruction::BoolOr:
						t = (t || c);
						break;
					case PTXInstruction::BoolXor:
						t = (t && !c) || (!t && c);
						break;
					default:
						break;
				}

				switch (instr.type) {
					case PTXOperand::s32:
					case PTXOperand::u32:
						setRegAsU32(threadID, instr.d.reg, (t ? 0xFFFFFFFF : 0x00));
						break;
					case PTXOperand::f32:
						setRegAsF32(threadID, instr.d.reg, (t ? 1.0f : 0.0f));
						break;
					default:
						break;
				}
			}
		}
		break;
		
		// double-precision float
		case PTXOperand::f64:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				
				PTXF64 a = operandAsF64(threadID, instr.a), b = operandAsF64(threadID, instr.b);
				bool c = true;
				bool t = false;
				
				if (instr.c.addressMode == PTXOperand::Register) {
					c = getRegAsPredicate(threadID, instr.c.reg);
				}
				
				// any branch predictor worth its salt will get this wrong twice or less
				switch (instr.comparisonOperator) {
				
					case PTXInstruction::Equ:
					case PTXInstruction::Eq:
						t = (a == b);
						break;
					
					case PTXInstruction::Neu:
					case PTXInstruction::Ne:
						t = (a != b);
						break;
					
					case PTXInstruction::Ltu:
					case PTXInstruction::Lo:	// fall through
					case PTXInstruction::Lt:
						t = (a < b);
						break;

					case PTXInstruction::Leu:
					case PTXInstruction::Ls:	// fall through
					case PTXInstruction::Le:
						t = (a <= b);
						break;
					
					case PTXInstruction::Gtu:
					case PTXInstruction::Hi:	// fall through
					case PTXInstruction::Gt:
						t = (a > b);
						break;
					
					case PTXInstruction::Geu:
					case PTXInstruction::Hs:	// fall through
					case PTXInstruction::Ge:
						t = (a >= b);
						break;

					case PTXInstruction::Num:
					case PTXInstruction::Nan:
						break;

					default:
						throw RuntimeException("invalid comparison operator for unsigned int type", context.PC, instr);
				}				
				
				switch (instr.comparisonOperator) {
					case PTXInstruction::Equ:
					case PTXInstruction::Neu:
					case PTXInstruction::Ltu:
					case PTXInstruction::Leu:
					case PTXInstruction::Gtu:
					case PTXInstruction::Geu:
					case PTXInstruction::Num:
					case PTXInstruction::Nan:
						// if either is NaN, set t to true
						t = (isF64NaN(a) || isF64NaN(b) || t);
						break;
					default:
						break;
				}
				
				
				// now apply the bool op
				switch (instr.booleanOperator) {
					case PTXInstruction::BoolAnd:
						t = (t && c);
						break;
					case PTXInstruction::BoolOr:
						t = (t || c);
						break;
					case PTXInstruction::BoolXor:
						t = (t && !c) || (!t && c);
						break;
					default:
						break;
				}

				switch (instr.type) {
					case PTXOperand::s32:
					case PTXOperand::u32:
						setRegAsU32(threadID, instr.d.reg, (t ? 0xFFFFFFFF : 0x00));
						break;
					case PTXOperand::f32:
						setRegAsF32(threadID, instr.d.reg, (t ? 1.0f : 0.0f));
						break;
					default:
						break;
				}
			}
		}
		break;
		
		default:
			throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Shl(CTAContext &context, const PTXInstruction &instr) {
	trace();
	unsigned int b = 0;
	if (instr.type == PTXOperand::b16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB16 d, a;
			
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_uint;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsB16(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}		
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 16 )
			{
				b = 16;
			}
			d = a << b;
			setRegAsB16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB32 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_uint;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsB32(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 32 )
			{
				b = 32;
			}
			d = a << b;
			setRegAsB32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB64 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_uint;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsB64(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 64 )
			{
				b = 64;
			}
			d = a << b;
			setRegAsB64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Shr(CTAContext &context, const PTXInstruction &instr) {
	trace();
	unsigned int b = 0;
	if (instr.type == PTXOperand::b16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB16 d, a;
			
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_uint;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsB16(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 16 )
			{
				b = 16;
			}
			d = a >> b;
			setRegAsB16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB32 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_uint;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsB32(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 32 )
			{
				b = 32;
			}
			d = a >> b;
			setRegAsB32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB64 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_uint;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsB64(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 64 )
			{
				b = 64;
			}
			d = a >> b;
			setRegAsB64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS16 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_int;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsS16(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 16 )
			{
				b = 16;
			}
			d = a >> b;
			setRegAsS16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS32 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_int;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsS32(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 32 )
			{
				b = 32;
			}
			d = a >> b;
			setRegAsS32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS64 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_int;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsS64(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 64 )
			{
				b = 64;
			}
			d = a >> b;
			setRegAsS64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU16 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_uint;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsU16(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 16 )
			{
				b = 16;
			}
			d = a >> b;
			setRegAsU16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU32 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_uint;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsU32(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 32 )
			{
				b = 32;
			}
			d = a >> b;
			setRegAsU32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU64 d, a;
			if (instr.a.addressMode == PTXOperand::Immediate) {
				a = instr.a.imm_uint;
			}
			else if (instr.a.addressMode == PTXOperand::Register) {
				a = getRegAsU64(threadID, instr.a.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if (instr.b.addressMode == PTXOperand::Immediate) {
				b = instr.b.imm_int;
			}
			else if (instr.b.addressMode == PTXOperand::Register) {
				b = getRegAsU32(threadID, instr.b.reg);
			}
			else {
				throw RuntimeException("unsupported data type", 
					context.PC, instr);
			}
			if( b > 64 )
			{
				b = 64;
			}
			d = a >> b;
			setRegAsU64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Sin(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a);
			d = (PTXF32)sin(a);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a);
			d = sin(a);
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!
	slct.dtype.ctype d, a, b, c;

	.dtype = { .b16, .b32, .b64,
		         .u16, .u32, .u64,
		         .s16, .s32, .s64,
		               .f32, .f64 };

	.ctype = { .s32, .f32 };

	d = (c >= 0) ? a : b;
*/
void executive::CooperativeThreadArray::eval_SlCt(CTAContext &context, const PTXInstruction &instr) {
	trace();

	assert(instr.opcode == PTXInstruction::SlCt);

	switch (instr.c.type) {
		case PTXOperand::u32:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				PTXU64 a = operandAsU64(threadID, instr.a), b = operandAsU64(threadID, instr.b);
				PTXS32 c = operandAsU32(threadID, instr.c);

				PTXU64 d = ((c >= 0) ? a : b);

				setRegAsU64(threadID, instr.d.reg, d);
			}
		}
		break;
		case PTXOperand::s32:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				PTXU64 a = operandAsU64(threadID, instr.a), b = operandAsU64(threadID, instr.b);
				PTXS32 c = operandAsS32(threadID, instr.c);

				PTXU64 d = ((c >= 0) ? a : b);

				setRegAsU64(threadID, instr.d.reg, d);
			}
		}
		break;
		case PTXOperand::f32:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				PTXU64 a = operandAsU64(threadID, instr.a), b = operandAsU64(threadID, instr.b);
				PTXF32 c = operandAsF32(threadID, instr.c);

				PTXU64 d = ((c >= 0) ? a : b);

				setRegAsU64(threadID, instr.d.reg, d);
			}
		}
		break;
		default:
			throw RuntimeException("source data type not permitted in PTX 1.3", context.PC, instr);
			break;
	}
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Sqrt(CTAContext &context, const PTXInstruction &instr) {
	trace();

	assert(instr.opcode == PTXInstruction::Sqrt);

	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a);
			d = (PTXF32)sqrt(a);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a);
			d = sqrt(a);
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void executive::CooperativeThreadArray::normalStore(int threadID, 
	const PTXInstruction &instr, char* source) {
	switch (instr.type) {
		case PTXOperand::b8:		// fall through
		case PTXOperand::s8:		// fall through
		case PTXOperand::u8:
			{
				PTXU8 word = getRegAsU8(threadID, instr.a.reg);
#if REPORT_ST
				report( "    Storing " << word << " to " 
					<< (int*)source );
#endif
				*((PTXU8*)source) = word;
			}
			break;
		case PTXOperand::b16:		// fall through
		case PTXOperand::s16:		// fall through
		case PTXOperand::u16:
			{
				PTXU16 word = getRegAsU16(threadID, instr.a.reg);
#if REPORT_ST
				report( "    Storing " << word << " to " 
					<< (int*)source );
#endif
				*((PTXU16*)source) = word;
			}
			break;
		case PTXOperand::f32:
			{
				PTXF32 word = getRegAsF32(threadID, instr.a.reg);
#if REPORT_ST
				report( "    Storing " << word << " to " 
					<< (int*)source );
#endif
				*((PTXF32*)source) = word;
			}
			break;
		case PTXOperand::b32:		// fall through
		case PTXOperand::s32:		// fall through
		case PTXOperand::u32:
			{
				PTXU32 word = getRegAsU32(threadID, instr.a.reg);
#if REPORT_ST
				report( "    Storing " << word << " to " 
					<< (int*)source );
#endif
				*((PTXU32*)source) = word;
			}
			break;
		case PTXOperand::f64:		// fall through
		case PTXOperand::b64:		// fall through
		case PTXOperand::s64:		// fall through
		case PTXOperand::u64:
			{
				PTXU64 word = getRegAsU64(threadID, instr.a.reg);
#if REPORT_ST
				report( "    Storing " << (void*)word << " to " 
					<< (int*)source );
#endif
				*((PTXU64*)source) = word;
			}
			break;
		default:
			break;
	}
		
}

void executive::CooperativeThreadArray::vectorStore(int threadID, 
	const PTXInstruction &instr, char* source, unsigned int elementSize) {
	for (PTXOperand::Array::const_iterator i = instr.a.array.begin(); 
		i != instr.a.array.end(); ++i, source += elementSize) {
		switch (instr.type) {
			case PTXOperand::b8:		// fall through
			case PTXOperand::s8:		// fall through
			case PTXOperand::u8:
				{
					PTXU8 word = getRegAsU8(threadID, i->reg);
#if REPORT_ST
					report( "    Storing " << word << " to " 
						<< (int*)source );
#endif
					*((PTXU8*)source) = word;
				}
				break;
			case PTXOperand::b16:		// fall through
			case PTXOperand::s16:		// fall through
			case PTXOperand::u16:
				{
					PTXU16 word = getRegAsU16(threadID, i->reg);
#if REPORT_ST
					report( "    Storing " << word << " to " 
						<< (int*)source );
#endif
					*((PTXU16*)source) = word;
				}
				break;
		case PTXOperand::f32:
			{
				PTXF32 word = getRegAsF32(threadID, i->reg);
#if REPORT_ST
				report( "    Storing " << word << " to " 
					<< (int*)source << " - from register " << i->reg );
#endif
				*((PTXF32*)source) = word;
			}
			break;
			case PTXOperand::b32:		// fall through
			case PTXOperand::s32:		// fall through
			case PTXOperand::u32:
				{
					PTXU32 word = getRegAsU32(threadID, i->reg);
#if REPORT_ST
					report( "    Storing " << word << " to " 
						<< (int*)source );
#endif
					*((PTXU32*)source) = word;
				}
				break;
			case PTXOperand::f64:		// fall through
			case PTXOperand::b64:		// fall through
			case PTXOperand::s64:		// fall through
			case PTXOperand::u64:
				{
					PTXU64 word = getRegAsU64(threadID, i->reg);
#if REPORT_ST
					report( "    Storing " << (void*)word << " to " 
						<< (int*)source );
#endif
					*((PTXU64*)source) = word;
				}
				break;
			default:
				break;
		}
	}
}

/*!

*/		
void executive::CooperativeThreadArray::eval_St(CTAContext &context, 
	const PTXInstruction &instr) {
	size_t elementSize = 0;

	switch (instr.type) {
		case PTXOperand::b8:		// fall through
		case PTXOperand::s8:		// fall through
		case PTXOperand::u8:
			{
				elementSize = sizeof(PTXU8);
			}
			break;
		case PTXOperand::b16:		// fall through
		case PTXOperand::s16:		// fall through
		case PTXOperand::u16:
			{
				elementSize = sizeof(PTXU16);
			}
			break;
		case PTXOperand::f32:		// fall through
		case PTXOperand::b32:		// fall through
		case PTXOperand::s32:		// fall through
		case PTXOperand::u32:
			{
				elementSize = sizeof(PTXU32);
			}
			break;
		case PTXOperand::f64:		// fall through
		case PTXOperand::b64:		// fall through
		case PTXOperand::s64:		// fall through
		case PTXOperand::u64:
			{
				elementSize = sizeof(PTXU64);
			}
			break;
		default:
			throw RuntimeException("unsupported data type", context.PC, instr);
	}

	if (traceEvents) {
		currentEvent.memory_size = elementSize;
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) {
				continue;
			}

			char *source = 0;

			switch (instr.d.addressMode) {
			case PTXOperand::Register:
			case PTXOperand::Indirect:
				switch (instr.d.type) {
					case PTXOperand::b8:		// fall through
					case PTXOperand::s8:		// fall through
					case PTXOperand::u8:
						{
							source += getRegAsU8(threadID, instr.d.reg );
						}
						break;
					case PTXOperand::b16:		// fall through
					case PTXOperand::s16:		// fall through
					case PTXOperand::u16:
						{
							source += getRegAsU16(threadID, instr.d.reg );
						}
						break;
					case PTXOperand::f32:		// fall through
					case PTXOperand::b32:		// fall through
					case PTXOperand::s32:		// fall through
					case PTXOperand::u32:
						{
							source += getRegAsU32(threadID, instr.d.reg );
						}
						break;
					case PTXOperand::f64:		// fall through
					case PTXOperand::b64:		// fall through
					case PTXOperand::s64:		// fall through
					case PTXOperand::u64:
						{
							source += getRegAsU64(threadID, instr.d.reg );
						}
						break;
					default:
						break;
				}
				break;
			case PTXOperand::Address:
			case PTXOperand::Immediate:
				source += instr.d.imm_uint;
				break;
			default:
				throw RuntimeException(
					"unsupported address mode for source operand", 
						context.PC, instr);
			}

			source += instr.d.offset;		

			currentEvent.memory_addresses.push_back((ir::PTXU64)source);
		}
	}

	trace();

	for (int threadID = 0; threadID < threadCount; threadID++) {
		if (!context.predicated(threadID, instr)) {
			continue;
		}

		char *source = 0;

		switch (instr.d.addressMode) {
		case PTXOperand::Register:
		case PTXOperand::Indirect:
			switch (instr.d.type) {
				case PTXOperand::b8:		// fall through
				case PTXOperand::s8:		// fall through
				case PTXOperand::u8:
					{
						source += getRegAsU8(threadID, instr.d.reg );
					}
					break;
				case PTXOperand::b16:		// fall through
				case PTXOperand::s16:		// fall through
				case PTXOperand::u16:
					{
						source += getRegAsU16(threadID, instr.d.reg );
					}
					break;
				case PTXOperand::f32:		// fall through
				case PTXOperand::b32:		// fall through
				case PTXOperand::s32:		// fall through
				case PTXOperand::u32:
					{
						source += getRegAsU32(threadID, instr.d.reg );
					}
					break;
				case PTXOperand::f64:		// fall through
				case PTXOperand::b64:		// fall through
				case PTXOperand::s64:		// fall through
				case PTXOperand::u64:
					{
						source += getRegAsU64(threadID, instr.d.reg );
					}
					break;
				default:
					break;
			}
			break;
		case PTXOperand::Address:
		case PTXOperand::Immediate:
			source += instr.d.imm_uint;
			break;
		default:
			throw RuntimeException(
				"unsupported address mode for source operand", 
					context.PC, instr);
		}

		source += instr.d.offset;		
		
		switch (instr.addressSpace) {
			case PTXInstruction::Param:
				{
					source += (PTXU64) kernel->ParameterMemory;
				}
				break;
			case PTXInstruction::Global:			
				{	
				}
				break;
			case PTXInstruction::Shared:
				{
					source = (char*)(0xffffffff & (PTXU64)source);
					source += (PTXU64) SharedMemory;
				}
				break;
			case PTXInstruction::Local:
				{
					source += (PTXU64) LocalMemory 
						+ kernel->localMemorySize() * threadID;
				}
				break;
			default:
				throw RuntimeException("unsupported address space", 
					context.PC, instr);
		}

		if (instr.a.vec == PTXOperand::v1) {
			normalStore(threadID, instr, source);
		}
		else {
			vectorStore(threadID, instr, source, elementSize);
		}
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////////

/*!

*/		
void executive::CooperativeThreadArray::eval_Sub(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::f32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF32 d, a = operandAsF32(threadID, instr.a), 
				b = operandAsF32(threadID, instr.b);
			d = sat(instr.modifier, a - b);
			setRegAsF32(threadID, instr.d.reg, d);
		}
	}	
	else if (instr.type == PTXOperand::f64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXF64 d, a = operandAsF64(threadID, instr.a), 
				b = operandAsF64(threadID, instr.b);
			d = a - b;
			setRegAsF64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS16 d, a = operandAsS16(threadID, instr.a), 
				b = operandAsS16(threadID, instr.b);
			d = a - b;
			setRegAsS16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS32 d, a = operandAsS32(threadID, instr.a), 
				b = operandAsS32(threadID, instr.b);
				
			if (instr.modifier & ir::PTXInstruction::sat) {
				PTXS64 la = a;
				PTXS64 lb = b;

				PTXS64 ld = la - lb;
				
				ld = max((PTXS64)INT_MIN, ld);
				ld = min((PTXS64)INT_MAX, ld);
				
				d = ld;
			}
			else if (instr.carry & ir::PTXInstruction::CC) {
				PTXS64 la = a;
				PTXS64 lb = b;

				PTXS64 ld = la - lb;

				PTXU32 carry = (0x100000000LLU & ld) >> 32;
				setRegAsU32(threadID, instr.pq.reg, carry);
			
				d = ld;
			}
			else {
				d = a - b;
			}
			
			setRegAsS32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::s64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXS64 d, a = operandAsS64(threadID, instr.a), 
				b = operandAsS64(threadID, instr.b);
			d = a - b;
			setRegAsS64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU16 d, a = operandAsU16(threadID, instr.a), 
				b = operandAsU16(threadID, instr.b);
			d = a - b;
			setRegAsU16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU32 d, a = operandAsU32(threadID, instr.a), 
				b = operandAsU32(threadID, instr.b);

			if (instr.carry & ir::PTXInstruction::CC) {
				PTXS64 la = a;
				PTXS64 lb = b;

				PTXS64 ld = la - lb;

				PTXU32 carry = (0x100000000LLU & ld) >> 32;
				setRegAsU32(threadID, instr.pq.reg, carry);
			
				d = ld;
			}
			else {
				d = a - b;
			}
			
			setRegAsU32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::u64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXU64 d, a = operandAsU64(threadID, instr.a), 
				b = operandAsU64(threadID, instr.b);
			d = a - b;
			setRegAsU64(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

/*!

*/
void executive::CooperativeThreadArray::eval_SubC(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();
	switch (instr.type) {

	case PTXOperand::u32:
	{
		for (int threadID = 0; threadID  < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXU64 d = 0,
				a = operandAsU32(threadID, instr.a),
				b = operandAsU32(threadID, instr.b);

			d = a - b + getRegAsU32(threadID, instr.c.reg);
			setRegAsU32(threadID, instr.d.reg, (PTXU32)d);

			if (instr.carry & PTXInstruction::CC) {
				setRegAsU32(threadID, instr.pq.reg, (d & 0x100000000LLU) >> 32);
			}
		}
	} break;

	case PTXOperand::s32:
	{
		for (int threadID = 0; threadID  < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			PTXS64 d = 0,
				a = operandAsS32(threadID, instr.a),
				b = operandAsS32(threadID, instr.b);

			d = a - b + getRegAsU32(threadID, instr.c.reg);
			setRegAsS32(threadID, instr.d.reg, (PTXS32)d);

			if (instr.carry & PTXInstruction::CC) {
				setRegAsU32(threadID, instr.pq.reg, (d & 0x100000000LLU) >> 32);
			}
		}
	} break;

	default:
		throw RuntimeException("invalid datatype", context.PC, instr);
	}
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Tex(CTAContext &context, 
	const PTXInstruction &instr) {
	const ir::Texture& texture = *kernel->textures[instr.a.reg];
	if (traceEvents) {
		currentEvent.memory_size = 4;
	}
	for (int threadID = 0; threadID < threadCount; threadID++) {
		if (!context.predicated(threadID, instr)) continue;
		PTXB8 *address = 0;
		
		switch (instr.geometry) {
			case ir::PTXInstruction::_1d:
				switch (instr.d.type) {
					case ir::PTXOperand::u32:
						if (instr.c.type == ir::PTXOperand::s32
							|| instr.c.type == ir::PTXOperand::u32) {
							assert(!instr.c.array.empty());
							assert(instr.d.array.size()==4);
							PTXS32 c = getRegAsS32(threadID, 
								instr.c.array[0].reg);
							PTXU32 d0 = tex::sample<0,PTXU32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXU32 d1 = tex::sample<1,PTXU32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXU32 d2 = tex::sample<2,PTXU32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXU32 d3 = tex::sample<3,PTXU32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							setRegAsU32(threadID, instr.d.array[0].reg, d0);
							setRegAsU32(threadID, instr.d.array[1].reg, d1);
							setRegAsU32(threadID, instr.d.array[2].reg, d2);
							setRegAsU32(threadID, instr.d.array[3].reg, d3);
						}
						else if (instr.c.type == ir::PTXOperand::f32) {
							assert(!instr.c.array.empty());
							assert(instr.d.array.size()==4);
							PTXF32 c = getRegAsF32(threadID, 
								instr.c.array[0].reg);
							PTXU32 d0 = tex::sample<0,PTXU32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXU32 d1 = tex::sample<1,PTXU32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXU32 d2 = tex::sample<2,PTXU32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXU32 d3 = tex::sample<3,PTXU32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							setRegAsU32(threadID, instr.d.array[0].reg, d0);
							setRegAsU32(threadID, instr.d.array[1].reg, d1);
							setRegAsU32(threadID, instr.d.array[2].reg, d2);
							setRegAsU32(threadID, instr.d.array[3].reg, d3);
						}
						else {
							throw RuntimeException(
								"invalid texture source type", 
								context.PC, instr);
						}
						break;
						
					case ir::PTXOperand::s32:
						if (instr.c.type == ir::PTXOperand::s32
							|| instr.c.type == ir::PTXOperand::u32) {
							assert(!instr.c.array.empty());
							assert(instr.d.array.size()==4);
							PTXS32 c = getRegAsS32(threadID, 
								instr.c.array[0].reg);
							PTXS32 d0 = tex::sample<0,PTXS32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXS32 d1 = tex::sample<1,PTXS32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXS32 d2 = tex::sample<2,PTXS32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXS32 d3 = tex::sample<3,PTXS32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							setRegAsS32(threadID, instr.d.array[0].reg, d0);
							setRegAsS32(threadID, instr.d.array[1].reg, d1);
							setRegAsS32(threadID, instr.d.array[2].reg, d2);
							setRegAsS32(threadID, instr.d.array[3].reg, d3);
						}
						else if (instr.c.type == ir::PTXOperand::f32) {
							assert(!instr.c.array.empty());
							assert(instr.d.array.size()==4);
							PTXF32 c = getRegAsF32(threadID, 
								instr.c.array[0].reg);
							PTXS32 d0 = tex::sample<0,PTXS32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXS32 d1 = tex::sample<1,PTXS32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXS32 d2 = tex::sample<2,PTXS32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXS32 d3 = tex::sample<3,PTXS32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							setRegAsS32(threadID, instr.d.array[0].reg, d0);
							setRegAsS32(threadID, instr.d.array[1].reg, d1);
							setRegAsS32(threadID, instr.d.array[2].reg, d2);
							setRegAsS32(threadID, instr.d.array[3].reg, d3);
						}
						else {
							throw RuntimeException(
								"invalid texture source type", 
								context.PC, instr);
						}
						break;
						
					case ir::PTXOperand::f32:
						if (instr.c.type == ir::PTXOperand::s32
							|| instr.c.type == ir::PTXOperand::u32) {
							assert(!instr.c.array.empty());
							assert(instr.d.array.size()==4);
							PTXS32 c = getRegAsS32(threadID, 
								instr.c.array[0].reg);
							PTXF32 d0 = tex::sample<0,PTXF32>(texture, c);
							PTXF32 d1 = tex::sample<1,PTXF32>(texture, c);
							PTXF32 d2 = tex::sample<2,PTXF32>(texture, c);
							PTXF32 d3 = tex::sample<3,PTXF32>(texture, c);
							setRegAsF32(threadID, instr.d.array[0].reg, d0);
							setRegAsF32(threadID, instr.d.array[1].reg, d1);
							setRegAsF32(threadID, instr.d.array[2].reg, d2);
							setRegAsF32(threadID, instr.d.array[3].reg, d3);
						}
						else if (instr.c.type == ir::PTXOperand::f32) {
							assert(!instr.c.array.empty());
							assert(instr.d.array.size()==4);
							PTXF32 c = getRegAsF32(threadID, 
								instr.c.array[0].reg);
							PTXF32 d0 = tex::sample<0,PTXF32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXF32 d1 = tex::sample<1,PTXF32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXF32 d2 = tex::sample<2,PTXF32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							PTXF32 d3 = tex::sample<3,PTXF32>(texture, c, address);
							if (traceEvents) {
								currentEvent.memory_addresses.push_back((PTXU64)address);
							}
							setRegAsF32(threadID, instr.d.array[0].reg, d0);
							setRegAsF32(threadID, instr.d.array[1].reg, d1);
							setRegAsF32(threadID, instr.d.array[2].reg, d2);
							setRegAsF32(threadID, instr.d.array[3].reg, d3);
						}
						else {
							throw RuntimeException(
								"invalid texture source type", 
								context.PC, instr);
						}
						break;

					default:
						throw RuntimeException(
							"invalid texture destination type", 
							context.PC, instr);
				}
				break;

			case ir::PTXInstruction::_2d:
				switch (instr.d.type) {
					case ir::PTXOperand::u32:
						if (instr.c.type == ir::PTXOperand::s32
							|| instr.c.type == ir::PTXOperand::u32) {
							assert(instr.c.array.size()>=2);
							assert(instr.d.array.size()==4);
							PTXS32 c0 = getRegAsS32(threadID, 
								instr.c.array[0].reg);
							PTXS32 c1 = getRegAsS32(threadID, 
								instr.c.array[1].reg);
							PTXU32 d0 = tex::sample<0,PTXU32>(texture, c0, c1);
							PTXU32 d1 = tex::sample<1,PTXU32>(texture, c0, c1);
							PTXU32 d2 = tex::sample<2,PTXU32>(texture, c0, c1);
							PTXU32 d3 = tex::sample<3,PTXU32>(texture, c0, c1);
							setRegAsU32(threadID, instr.d.array[0].reg, d0);
							setRegAsU32(threadID, instr.d.array[1].reg, d1);
							setRegAsU32(threadID, instr.d.array[2].reg, d2);
							setRegAsU32(threadID, instr.d.array[3].reg, d3);
						}
						else if (instr.c.type == ir::PTXOperand::f32) {
							assert(instr.c.array.size()>=2);
							assert(instr.d.array.size()==4);
							PTXF32 c0 = getRegAsF32(threadID, 
								instr.c.array[0].reg);
							PTXF32 c1 = getRegAsF32(threadID, 
								instr.c.array[1].reg);
							PTXU32 d0 = tex::sample<0,PTXU32>(texture, c0, c1);
							PTXU32 d1 = tex::sample<1,PTXU32>(texture, c0, c1);
							PTXU32 d2 = tex::sample<2,PTXU32>(texture, c0, c1);
							PTXU32 d3 = tex::sample<3,PTXU32>(texture, c0, c1);
							setRegAsU32(threadID, instr.d.array[0].reg, d0);
							setRegAsU32(threadID, instr.d.array[1].reg, d1);
							setRegAsU32(threadID, instr.d.array[2].reg, d2);
							setRegAsU32(threadID, instr.d.array[3].reg, d3);
						}
						else {
							throw RuntimeException(
								"invalid texture source type", 
								context.PC, instr);
						}
						break;
						
					case ir::PTXOperand::s32:
						if (instr.c.type == ir::PTXOperand::s32
							|| instr.c.type == ir::PTXOperand::u32) {
							assert(instr.c.array.size()>=2);
							assert(instr.d.array.size()==4);
							PTXS32 c0 = getRegAsS32(threadID, 
								instr.c.array[0].reg);
							PTXS32 c1 = getRegAsS32(threadID, 
								instr.c.array[1].reg);
							PTXS32 d0 = tex::sample<0,PTXS32>(texture, c0, c1);
							PTXS32 d1 = tex::sample<1,PTXS32>(texture, c0, c1);
							PTXS32 d2 = tex::sample<2,PTXS32>(texture, c0, c1);
							PTXS32 d3 = tex::sample<3,PTXS32>(texture, c0, c1);
							setRegAsS32(threadID, instr.d.array[0].reg, d0);
							setRegAsS32(threadID, instr.d.array[1].reg, d1);
							setRegAsS32(threadID, instr.d.array[2].reg, d2);
							setRegAsS32(threadID, instr.d.array[3].reg, d3);
						}
						else if (instr.c.type == ir::PTXOperand::f32) {
							assert(instr.c.array.size()>=2);
							assert(instr.d.array.size()==4);
							PTXF32 c0 = getRegAsF32(threadID, 
								instr.c.array[0].reg);
							PTXF32 c1 = getRegAsF32(threadID, 
								instr.c.array[1].reg);
							PTXS32 d0 = tex::sample<0,PTXS32>(texture, c0, c1);
							PTXS32 d1 = tex::sample<1,PTXS32>(texture, c0, c1);
							PTXS32 d2 = tex::sample<2,PTXS32>(texture, c0, c1);
							PTXS32 d3 = tex::sample<3,PTXS32>(texture, c0, c1);
							setRegAsS32(threadID, instr.d.array[0].reg, d0);
							setRegAsS32(threadID, instr.d.array[1].reg, d1);
							setRegAsS32(threadID, instr.d.array[2].reg, d2);
							setRegAsS32(threadID, instr.d.array[3].reg, d3);
						}
						else {
							throw RuntimeException(
								"invalid texture source type", 
								context.PC, instr);
						}
						break;
						
					case ir::PTXOperand::f32:
						if (instr.c.type == ir::PTXOperand::s32
							|| instr.c.type == ir::PTXOperand::u32) {
							assert(instr.c.array.size()>=2);
							assert(instr.d.array.size()==4);
							PTXS32 c0 = getRegAsS32(threadID, 
								instr.c.array[0].reg);
							PTXS32 c1 = getRegAsS32(threadID, 
								instr.c.array[1].reg);
							PTXF32 d0 = tex::sample<0,PTXF32>(texture, c0, c1);
							PTXF32 d1 = tex::sample<1,PTXF32>(texture, c0, c1);
							PTXF32 d2 = tex::sample<2,PTXF32>(texture, c0, c1);
							PTXF32 d3 = tex::sample<3,PTXF32>(texture, c0, c1);
							setRegAsF32(threadID, instr.d.array[0].reg, d0);
							setRegAsF32(threadID, instr.d.array[1].reg, d1);
							setRegAsF32(threadID, instr.d.array[2].reg, d2);
							setRegAsF32(threadID, instr.d.array[3].reg, d3);
						}
						else if (instr.c.type == ir::PTXOperand::f32) {
							assert(instr.c.array.size()>=2);
							assert(instr.d.array.size()==4);
							PTXF32 c0 = getRegAsF32(threadID, 
								instr.c.array[0].reg);
							PTXF32 c1 = getRegAsF32(threadID, 
								instr.c.array[1].reg);
							PTXF32 d0 = tex::sample<0,PTXF32>(texture, c0, c1);
							PTXF32 d1 = tex::sample<1,PTXF32>(texture, c0, c1);
							PTXF32 d2 = tex::sample<2,PTXF32>(texture, c0, c1);
							PTXF32 d3 = tex::sample<3,PTXF32>(texture, c0, c1);
							setRegAsF32(threadID, instr.d.array[0].reg, d0);
							setRegAsF32(threadID, instr.d.array[1].reg, d1);
							setRegAsF32(threadID, instr.d.array[2].reg, d2);
							setRegAsF32(threadID, instr.d.array[3].reg, d3);
						}
						else {
							throw RuntimeException(
								"invalid texture source type", 
								context.PC, instr);
						}
						break;

					default:
						throw RuntimeException(
							"invalid texture destination type", 
							context.PC, instr);
				}
				break;

			case ir::PTXInstruction::_3d:
				switch (instr.d.type) {
					case ir::PTXOperand::u32:
						if (instr.c.type == ir::PTXOperand::s32
							|| instr.c.type == ir::PTXOperand::u32) {
							assert(instr.c.array.size()==4);
							assert(instr.d.array.size()==4);
							PTXS32 c0 = getRegAsS32(threadID, 
								instr.c.array[0].reg);
							PTXS32 c1 = getRegAsS32(threadID, 
								instr.c.array[1].reg);
							PTXS32 c2 = getRegAsS32(threadID, 
								instr.c.array[2].reg);
							PTXU32 d0 = tex::sample<0,PTXU32>(texture, c0, c1, c2);
							PTXU32 d1 = tex::sample<1,PTXU32>(texture, c0, c1, c2);
							PTXU32 d2 = tex::sample<2,PTXU32>(texture, c0, c1, c2);
							PTXU32 d3 = tex::sample<3,PTXU32>(texture, c0, c1, c2);
							setRegAsU32(threadID, instr.d.array[0].reg, d0);
							setRegAsU32(threadID, instr.d.array[1].reg, d1);
							setRegAsU32(threadID, instr.d.array[2].reg, d2);
							setRegAsU32(threadID, instr.d.array[3].reg, d3);
						}
						else if (instr.c.type == ir::PTXOperand::f32) {
							assert(instr.c.array.size()==4);
							assert(instr.d.array.size()==4);
							PTXF32 c0 = getRegAsF32(threadID, 
								instr.c.array[0].reg);
							PTXF32 c1 = getRegAsF32(threadID, 
								instr.c.array[1].reg);
							PTXF32 c2 = getRegAsF32(threadID, 
								instr.c.array[2].reg);
							PTXU32 d0 = tex::sample<0,PTXU32>(texture, c0, c1, c2);
							PTXU32 d1 = tex::sample<1,PTXU32>(texture, c0, c1, c2);
							PTXU32 d2 = tex::sample<2,PTXU32>(texture, c0, c1, c2);
							PTXU32 d3 = tex::sample<3,PTXU32>(texture, c0, c1, c2);
							setRegAsU32(threadID, instr.d.array[0].reg, d0);
							setRegAsU32(threadID, instr.d.array[1].reg, d1);
							setRegAsU32(threadID, instr.d.array[2].reg, d2);
							setRegAsU32(threadID, instr.d.array[3].reg, d3);
						}
						else {
							throw RuntimeException(
								"invalid texture source type", 
								context.PC, instr);
						}
						break;
						
					case ir::PTXOperand::s32:
						if (instr.c.type == ir::PTXOperand::s32
							|| instr.c.type == ir::PTXOperand::u32) {
							assert(instr.c.array.size()==4);
							assert(instr.d.array.size()==4);
							PTXS32 c0 = getRegAsS32(threadID, 
								instr.c.array[0].reg);
							PTXS32 c1 = getRegAsS32(threadID, 
								instr.c.array[1].reg);
							PTXS32 c2 = getRegAsS32(threadID, 
								instr.c.array[2].reg);
							PTXS32 d0 = tex::sample<0,PTXS32>(texture, c0, c1, c2);
							PTXS32 d1 = tex::sample<1,PTXS32>(texture, c0, c1, c2);
							PTXS32 d2 = tex::sample<2,PTXS32>(texture, c0, c1, c2);
							PTXS32 d3 = tex::sample<3,PTXS32>(texture, c0, c1, c2);
							setRegAsS32(threadID, instr.d.array[0].reg, d0);
							setRegAsS32(threadID, instr.d.array[1].reg, d1);
							setRegAsS32(threadID, instr.d.array[2].reg, d2);
							setRegAsS32(threadID, instr.d.array[3].reg, d3);
						}
						else if (instr.c.type == ir::PTXOperand::f32) {
							assert(instr.c.array.size()==4);
							assert(instr.d.array.size()==4);
							PTXF32 c0 = getRegAsF32(threadID, 
								instr.c.array[0].reg);
							PTXF32 c1 = getRegAsF32(threadID, 
								instr.c.array[1].reg);
							PTXF32 c2 = getRegAsF32(threadID, 
								instr.c.array[2].reg);
							PTXS32 d0 = tex::sample<0,PTXS32>(texture, c0, c1, c2);
							PTXS32 d1 = tex::sample<1,PTXS32>(texture, c0, c1, c2);
							PTXS32 d2 = tex::sample<2,PTXS32>(texture, c0, c1, c2);
							PTXS32 d3 = tex::sample<3,PTXS32>(texture, c0, c1, c2);
							setRegAsS32(threadID, instr.d.array[0].reg, d0);
							setRegAsS32(threadID, instr.d.array[1].reg, d1);
							setRegAsS32(threadID, instr.d.array[2].reg, d2);
							setRegAsS32(threadID, instr.d.array[3].reg, d3);
						}
						else {
							throw RuntimeException(
								"invalid texture source type", 
								context.PC, instr);
						}
						break;
						
					case ir::PTXOperand::f32:
						if (instr.c.type == ir::PTXOperand::s32
							|| instr.c.type == ir::PTXOperand::u32) {
							assert(instr.c.array.size()==4);
							assert(instr.d.array.size()==4);
							PTXS32 c0 = getRegAsS32(threadID, 
								instr.c.array[0].reg);
							PTXS32 c1 = getRegAsS32(threadID, 
								instr.c.array[1].reg);
							PTXS32 c2 = getRegAsS32(threadID, 
								instr.c.array[2].reg);
							PTXF32 d0 = tex::sample<0,PTXF32>(texture, c0, c1, c2);
							PTXF32 d1 = tex::sample<1,PTXF32>(texture, c0, c1, c2);
							PTXF32 d2 = tex::sample<2,PTXF32>(texture, c0, c1, c2);
							PTXF32 d3 = tex::sample<3,PTXF32>(texture, c0, c1, c2);
							setRegAsF32(threadID, instr.d.array[0].reg, d0);
							setRegAsF32(threadID, instr.d.array[1].reg, d1);
							setRegAsF32(threadID, instr.d.array[2].reg, d2);
							setRegAsF32(threadID, instr.d.array[3].reg, d3);
						}
						else if (instr.c.type == ir::PTXOperand::f32) {
							assert(instr.c.array.size()==4);
							assert(instr.d.array.size()==4);
							PTXF32 c0 = getRegAsF32(threadID, 
								instr.c.array[0].reg);
							PTXF32 c1 = getRegAsF32(threadID, 
								instr.c.array[1].reg);
							PTXF32 c2 = getRegAsF32(threadID, 
								instr.c.array[2].reg);
							PTXF32 d0 = tex::sample<0,PTXF32>(texture, c0, c1, c2);
							PTXF32 d1 = tex::sample<1,PTXF32>(texture, c0, c1, c2);
							PTXF32 d2 = tex::sample<2,PTXF32>(texture, c0, c1, c2);
							PTXF32 d3 = tex::sample<3,PTXF32>(texture, c0, c1, c2);
							setRegAsF32(threadID, instr.d.array[0].reg, d0);
							setRegAsF32(threadID, instr.d.array[1].reg, d1);
							setRegAsF32(threadID, instr.d.array[2].reg, d2);
							setRegAsF32(threadID, instr.d.array[3].reg, d3);
						}
						else {
							throw RuntimeException(
								"invalid texture source type", 
								context.PC, instr);
						}
						break;

					default:
						throw RuntimeException(
							"invalid texture destination type", 
							context.PC, instr);
				}
				break;

			default:
				throw RuntimeException("invalid texture geometry", 
					context.PC, instr);
				break;
		}
	}	
	trace();
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Trap(CTAContext &context, const PTXInstruction &instr) {
	trace();
	context.running = false;
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Vote(CTAContext &context, const PTXInstruction &instr) {
	trace();
	if (instr.type != PTXOperand::pred || instr.d.type != PTXOperand::pred 
		|| instr.a.type != PTXOperand::pred ) {
		throw RuntimeException("Vote only supports predicates", 
			context.PC, instr);
	}
	
	bool a = true;
	
	switch (instr.vote) {
		case ir::PTXInstruction::All:
		{
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				bool local = getRegAsPredicate(threadID, instr.a.reg);
				if (instr.a.condition == ir::PTXOperand::InvPred) {
					local = !local;
				}
				if (!local) {
					a = false;
					break;
				}	
			}
			break;
		}
		case ir::PTXInstruction::Uni:
		{
			bool set = false;
			bool value = false;
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				bool local = getRegAsPredicate(threadID, instr.a.reg);
				if (instr.a.condition == ir::PTXOperand::InvPred) {
					local = !local;
				}
				if (!set) {
					set = true;
					value = local;
				}
				else {
					if (value != local) {
						a = false;
					}
				}
			}
			break;
		}
		case ir::PTXInstruction::Any:
		{
			a = false;
			for (int threadID = 0; threadID < threadCount; threadID++) {
				if (!context.predicated(threadID, instr)) continue;
				bool local = getRegAsPredicate(threadID, instr.a.reg);
				if (instr.a.condition == ir::PTXOperand::InvPred) {
					local = !local;
				}
				if (local) {
					a = true;
					break;
				}
			}
			break;
		}
		default:
			throw RuntimeException("Invalid vote mode", 
				context.PC, instr);
	}

	for (int threadID = 0; threadID < threadCount; threadID++) {
		if (!context.predicated(threadID, instr)) continue;
		setRegAsPredicate(threadID, instr.d.reg, a);
	}	
}

/*!

*/		
void executive::CooperativeThreadArray::eval_Xor(CTAContext &context, 
	const PTXInstruction &instr) {
	trace();
	if (instr.type == PTXOperand::pred) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			bool d, a = getRegAsPredicate(threadID, instr.a.reg), 
				b = getRegAsPredicate(threadID, instr.b.reg);
			d = b ^ a;
			setRegAsPredicate(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b16) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB16 d, a = operandAsB16(threadID, instr.a),
				b = operandAsB16(threadID, instr.b);
			d = a ^ b;
			setRegAsB16(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b32) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB32 d, a = operandAsB32(threadID, instr.a),
				b = operandAsB32(threadID, instr.b);
			d = a ^ b;
			setRegAsB32(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::b64) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			PTXB64 d, a = operandAsB64(threadID, instr.a),
				b = operandAsB64(threadID, instr.b);
			d = a ^ b;
			setRegAsB64(threadID, instr.d.reg, d);
		}
	}
	else if (instr.type == PTXOperand::pred) {
		for (int threadID = 0; threadID < threadCount; threadID++) {
			if (!context.predicated(threadID, instr)) continue;
			
			bool d, a = getRegAsPredicate(threadID, instr.a.reg), 
				b = getRegAsPredicate(threadID, instr.b.reg);
			d = a ^ b;
			setRegAsPredicate(threadID, instr.d.reg, d);
		}
	}
	else {
		throw RuntimeException("unsupported data type", context.PC, instr);
	}
}

