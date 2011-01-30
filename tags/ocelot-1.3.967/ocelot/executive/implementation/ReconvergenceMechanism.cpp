/*!
	\file ReconvergenceMechanism.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 15, 2010
	\brief extracts the reconvergence mechanism from CooperativeThreadArray
*/

// C++ includes
#include <cassert>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cfenv> 
#include <algorithm>

// Ocelot includes
#include <ocelot/executive/interface/ReconvergenceMechanism.h>
#include <ocelot/executive/interface/RuntimeException.h>
#include <ocelot/executive/interface/EmulatedKernel.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/math.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

// global control for enabling reporting within the emulator
#define REPORT_BASE 0

#define REPORT_BAR 1

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::ReconvergenceMechanism::ReconvergenceMechanism(
	const EmulatedKernel *_kernel, CooperativeThreadArray *_cta)
: 
	type(Reconverge_default),
	kernel(_kernel),
	cta(_cta)
{
}

executive::ReconvergenceMechanism::ReconvergenceMechanism(
	 CooperativeThreadArray *_cta)
: 
	type(Reconverge_default),
	kernel(0),
	cta(_cta)
{

}

void executive::ReconvergenceMechanism::initialize() {
	CTAContext context(cta->blockDim, cta);
	runtimeStack.clear();
	runtimeStack.push_back(context);
}

//! \brief gets the active context
executive::CTAContext & executive::ReconvergenceMechanism::getContext() {
	return runtimeStack.back();
}

//! \brief updates the predicate mask of the active context before instructions execute
void executive::ReconvergenceMechanism::evalPredicate(executive::CTAContext &context) {
	return;
}

/*! 
	\brief implements branch instruction and updates CooperativeThreadArray state
	\return true on divergent branch
*/
bool executive::ReconvergenceMechanism::eval_Bra(executive::CTAContext &context, 
	const ir::PTXInstruction &instr, 
	const boost::dynamic_bitset<> & branch, 
	const boost::dynamic_bitset<> & fallthrough) {

	return false;
}

/*! 
	\brief implements a barrier instruction
*/
void executive::ReconvergenceMechanism::eval_Bar(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {

}

/*!
	\brief implements reconverge instructions
*/
void executive::ReconvergenceMechanism::eval_Reconverge(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {

}

void executive::ReconvergenceMechanism::eval_Exit(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	context.running = false;
}

/*! 
	\brief updates the active context to the next instruction
*/
bool executive::ReconvergenceMechanism::nextInstruction(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {

	if (instr.opcode != ir::PTXInstruction::Reconverge) {
		context.PC ++;
	}
	return context.running;
}

/*!
	\brief gets the stack size
*/
const size_t executive::ReconvergenceMechanism::stackSize() const {
	return runtimeStack.size();
}


//! \brief gets a string-representation of the type
std::string executive::ReconvergenceMechanism::toString(Type type) {
	switch (type) {
	case Reconverge_IPDOM: return "ipdom";
	case Reconverge_Barrier: return "barrier";
	case Reconverge_TFGen6: return "tf-gen6";
	case Reconverge_TFSortedStack: return "tf-sorted-stack";
	case Reconverge_default: return "default-reconverge";
	case Reconverge_unknown:
	default:
		break;
	}
	return "unknown-reconverge";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::ReconvergenceIPDOM::ReconvergenceIPDOM(const EmulatedKernel *_kernel, 
	CooperativeThreadArray *cta)
: 
	ReconvergenceMechanism(_kernel, cta)
{
	type = Reconverge_IPDOM;
}

bool executive::ReconvergenceIPDOM::eval_Bra(executive::CTAContext &context, 
	const ir::PTXInstruction &instr, 
	const boost::dynamic_bitset<> & branch, 
	const boost::dynamic_bitset<> & fallthrough) {

	bool isDivergent = false;
	if (instr.uni) {

		// unfiorm
		if (branch.count()) {
			// all threads branch
			context.PC = instr.branchTargetInstruction;
		}
		else {
			// all threads fall through
			context.PC ++;
		}
	}
	else {
			// divergence - complicated
		CTAContext branchContext(context), fallthroughContext(context), reconvergeContext(context);

		branchContext.active = branch;
		branchContext.PC = instr.branchTargetInstruction;

		fallthroughContext.active = fallthrough;
		fallthroughContext.PC++;
		
		reconvergeContext.PC = instr.reconvergeInstruction + 1;
		
		runtimeStack.pop_back();

		bool reconvergeContextAlreadyExists = false;
		for(RuntimeStack::reverse_iterator si = runtimeStack.rbegin(); 
			si != runtimeStack.rend(); ++si ) {
			if(si->PC == reconvergeContext.PC) {
				reconvergeContextAlreadyExists = true;
				break;
			}
		}

		if(!reconvergeContextAlreadyExists) {
			runtimeStack.push_back(reconvergeContext);
		}
		
		if (branchContext.active.any()) {
			runtimeStack.push_back(branchContext);
		}
		
		if (fallthroughContext.active.any()) {
			runtimeStack.push_back(fallthroughContext);		
		}
	}

	return isDivergent;
}

void executive::ReconvergenceIPDOM::eval_Bar(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	
	if (context.active.count() < context.active.size()) {
		// deadlock - not all threads reach synchronization barrier
#if REPORT_BAR
		report(" Bar called - " << context.active.count() << " of " 
			<< context.active.size() << " threads active");
#endif
/*
		throw RuntimeException("barrier deadlock at: " 
			+ kernel->location(context.PC), context.PC, instr);
			*/
		throw RuntimeException("barrier deadlock at: ", context.PC, instr);
	}
}

void executive::ReconvergenceIPDOM::eval_Reconverge(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	if(runtimeStack.size() > 1)	{
		runtimeStack.pop_back();
	}
	else {
		context.PC ++;
	}
}

void executive::ReconvergenceIPDOM::eval_Exit(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	eval_Bar(context, instr);
	context.running = false;
}

bool executive::ReconvergenceIPDOM::nextInstruction(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {

	// advance to next instruction if the current instruction wasn't a branch
	if (instr.opcode != ir::PTXInstruction::Bra && instr.opcode != ir::PTXInstruction::Reconverge ) {
		context.PC++;
	}
	return context.running;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::ReconvergenceBarrier::ReconvergenceBarrier(const EmulatedKernel *_kernel, 
	CooperativeThreadArray *cta)
: 
	ReconvergenceMechanism(_kernel, cta)
{
	type = Reconverge_Barrier;
}

bool executive::ReconvergenceBarrier::eval_Bra(executive::CTAContext &context, 
	const ir::PTXInstruction &instr, 
	const boost::dynamic_bitset<> & branch, 
	const boost::dynamic_bitset<> & fallthrough) {
	
	bool isDivergent = false;
	
	if (instr.uni) {
		// unfiorm
		if (branch.count()) {
			// all threads branch
			context.PC = instr.branchTargetInstruction;
		}
		else {
			// all threads fall through
			context.PC ++;
		}
	}
	else {
		// divergence - complicated
		CTAContext branchContext(context), fallthroughContext(context), 
			reconvergeContext(context);

		branchContext.active = branch;
		branchContext.PC = instr.branchTargetInstruction;

		fallthroughContext.active = fallthrough;
		fallthroughContext.PC++;
		
		reconvergeContext.PC = instr.reconvergeInstruction + 1;
		
		runtimeStack.pop_back();

		if (branchContext.active.any()) {
			runtimeStack.push_back(branchContext);
		}
		
		if (fallthroughContext.active.any()) {
			runtimeStack.push_back(fallthroughContext);		
		}
		
		isDivergent = true;
	}
	
	return isDivergent;
}

void executive::ReconvergenceBarrier::eval_Bar(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	
	CTAContext continuation(context);
	runtimeStack.pop_back();
	if (runtimeStack.size() == 0) {
		continuation.active.set();
		continuation.PC = context.PC + 1;
		runtimeStack.push_back(continuation);
	}
}

void executive::ReconvergenceBarrier::eval_Reconverge(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
}

void executive::ReconvergenceBarrier::eval_Exit(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	if (context.active.count() == context.active.size() || runtimeStack.size() == 1) {
		context.running = false;
	}
	else {
		eval_Bar(context, instr);
	}
}

bool executive::ReconvergenceBarrier::nextInstruction(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {

	// advance to next instruction if the current instruction wasn't a branch
	if (instr.opcode != ir::PTXInstruction::Bra && instr.opcode != ir::PTXInstruction::Bar) {
		context.PC++;
	}
	return context.running;
}

		
/////////////////////////////////////////////////////////////////////////////////////////////////

executive::ReconvergenceTFGen6::ReconvergenceTFGen6(const EmulatedKernel *_kernel, 
	CooperativeThreadArray *cta)
: 
	ReconvergenceMechanism(_kernel, cta)
{
	type = Reconverge_TFGen6;
}

void executive::ReconvergenceTFGen6::initialize() {
	ReconvergenceMechanism::initialize();
	threadPCs.resize(runtimeStack.back().active.size(), runtimeStack.back().PC);
}

void executive::ReconvergenceTFGen6::evalPredicate(executive::CTAContext &context) {
	for (size_t tid = 0; tid < context.active.size(); tid++) {
		context.active[tid] = (threadPCs[tid] == context.PC);
	}
}

bool executive::ReconvergenceTFGen6::eval_Bra(executive::CTAContext &context, 
	const ir::PTXInstruction &instr, 
	const boost::dynamic_bitset<> & branch, 
	const boost::dynamic_bitset<> & fallthrough) {

	bool isDivergent = true;

	report("eval_Bra([PC " << context.PC << "])");

	if (!context.active.count()) { 
		context.PC ++;
		return false;
	}

	CTAContext branchContext(context), fallthroughContext(context), 
		reconvergeContext(context);

	branchContext.active = branch;
	branchContext.PC = instr.branchTargetInstruction;

	fallthroughContext.active = fallthrough;
	fallthroughContext.PC++;
	
	reconvergeContext.PC = instr.reconvergeInstruction + 1;
	
	//
	// assign PCs for participating threads then compute the minimum PC for the warp
	//
	int minPC = 0;
	for (size_t tid = 0; tid < runtimeStack.back().active.size(); tid++) {
		if (runtimeStack.back().active[tid]) {
			threadPCs[tid] = (fallthrough[tid] ? runtimeStack.back().PC + 1 : instr.branchTargetInstruction);
		}
		if (!tid || minPC > threadPCs[tid]) {
			minPC = threadPCs[tid];
		}
	}
	
	report("   again? eval_Bra([PC " << context.PC << "])");
	EmulatedKernel::ThreadFrontierMap::const_iterator tf_it = kernel->threadFrontiers.find(context.PC);
	if (tf_it != kernel->threadFrontiers.end()) {
		// conservative branch here?
		report("thread frontier of block with divergent branch at PC: " << context.PC);
		report("  earliest: " << tf_it->second.first);
		report("  latest:   " << tf_it->second.second);
		
		int currentPC = runtimeStack.back().PC;
		int branchTargetPC = instr.branchTargetInstruction;
		int fallthroughTargetPC = currentPC + 1;
		int targetPC = fallthroughTargetPC;			
		
		if (branch.count() && branchTargetPC < targetPC) {
			// taken backward branch
			if (branchTargetPC > tf_it->second.first) {
				targetPC = tf_it->second.first;
			}
			else {
				targetPC = branchTargetPC;
			}
		}
		else {
			// forward branch
			bool activeAtFallthrough = (fallthrough.count());
			for (size_t tid=0; !activeAtFallthrough && tid < runtimeStack.back().active.size(); tid++) {
				if (threadPCs[tid] == fallthroughTargetPC) {
					activeAtFallthrough = true;
					break;
				}
			}
			if (activeAtFallthrough) {
				targetPC = fallthroughTargetPC;
			}
			else if (branchTargetPC > tf_it->second.first) {
				targetPC = tf_it->second.first;
			}
			else {
				targetPC = branchTargetPC;
			}
		}
		
		if (targetPC != minPC) {
			// this is a conservative branch and will result in no-ops
			currentEvent.conservativeBranch = true;
			report(" conservative branch ");
		}
		
		runtimeStack.back().PC = targetPC;
	}
	else {
		report("Thread frontier not found at divergent branch for PC " << context.PC);
		throw RuntimeException("Thread frontier not found  at divergent branch", context.PC, instr);
	}

	return isDivergent;
}

void executive::ReconvergenceTFGen6::eval_Bar(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {

	if (!context.active.count()) { 
		context.PC ++;
		return;
	}
	
	size_t activeThreads = context.active.count();
	if (activeThreads && activeThreads != context.active.size()) {
		report("warp PC: " << context.PC);
		for (size_t tid = 0; tid < context.active.size(); tid++) {
			report(" " << threadPCs[tid]);
		}
		throw RuntimeException(
			"GEN6 reconvergence mechanism hasn't reconverged by barrier.synchronization",
			context.PC, instr);
	}
}

void executive::ReconvergenceTFGen6::eval_Reconverge(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	context.PC ++;
}

void executive::ReconvergenceTFGen6::eval_Exit(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	if (!context.active.count()) { 
		context.PC ++;
		return;
	}
	if (runtimeStack.size() == 1 || context.active.count() == context.active.size()) {
		context.running = false;
	}
	else {
		runtimeStack.pop_back();
	}
}

bool executive::ReconvergenceTFGen6::nextInstruction(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	
	// advance to next instruction if the current instruction wasn't a branch
	if (instr.opcode != ir::PTXInstruction::Bra && instr.opcode != ir::PTXInstruction::Reconverge 
		&& instr.opcode != ir::PTXInstruction::Exit) {
		
		context.PC++;
	}
	
	// GEN6 must manually increment the warp PC if instructions are branch or reconverge
	if (instr.opcode != ir::PTXInstruction::Bra && instr.opcode != ir::PTXInstruction::Exit) {
		//
		// these instruction handlers will have to update each thread's PC individually
		//
		for (size_t tid = 0; tid < context.active.size(); tid++) {
			if (context.active[tid]) {
				threadPCs[tid] = context.PC;
			}
		}
	}
	return context.running;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::ReconvergenceTFSortedStack::ReconvergenceTFSortedStack(const EmulatedKernel *_kernel, 
	CooperativeThreadArray *cta)
: 
	ReconvergenceMechanism(_kernel, cta)
{
	type = Reconverge_TFSortedStack;
}

void executive::ReconvergenceTFSortedStack::evalPredicate(executive::CTAContext &context) {

}

bool executive::ReconvergenceTFSortedStack::eval_Bra(executive::CTAContext &context, 
	const ir::PTXInstruction &instr, 
	const boost::dynamic_bitset<> & branch, 
	const boost::dynamic_bitset<> & fallthrough) {

	bool isDivergent = false;
	
	CTAContext branchContext(context), fallthroughContext(context), 
		reconvergeContext(context);

	branchContext.active = branch;
	branchContext.PC = instr.branchTargetInstruction;

	fallthroughContext.active = fallthrough;
	fallthroughContext.PC++;
	
	reconvergeContext.PC = instr.reconvergeInstruction + 1;
	
	runtimeStack.pop_back();
	
	//
	// insert branch target with greatest PC onto stack, and resume with branch target with
	// least PC
	//
	CTAContext branchContexts[3];
	int ctxCount = 0, ctxStart = 1;
	
	// insert the largest PC first
	if (branchContext.active.any()) {
		branchContexts[ctxStart+ctxCount] = branchContext;
		ctxCount ++;
	}
	if (fallthroughContext.active.any()) {
		int ctxInsert = ctxStart;
		if (ctxCount) {
			if (branchContext.PC > fallthroughContext.PC) {
				ctxInsert = 2;
			}
			else {
				ctxInsert = 0;
				ctxStart = 0;
			}
		}
		branchContexts[ctxInsert] = fallthroughContext;
		ctxCount ++;
	}
	
	isDivergent = (ctxCount > 1);

	currentEvent.stackVisitNodes = 0;
	currentEvent.stackVisitEnd = 0;
	currentEvent.stackVisitMiddle = 0;
	currentEvent.stackInsert = 0;
	currentEvent.stackMerge = 0;
	currentEvent.conservativeBranch = false;
	
	//
	// preserve invariant runtimeStack is in descending order
	//
	// insert sorted
	for (int ctx = 0; ctx < ctxCount; ctx++) {
		size_t nodes = 1;
		for (RuntimeStack::iterator s_it = runtimeStack.begin(); true; ++s_it, nodes++) {
			if (s_it == runtimeStack.end()) {
				runtimeStack.insert(s_it, branchContexts[ctxStart+ctx]);
				++currentEvent.stackVisitEnd;
				nodes = 1;
				++currentEvent.stackInsert;
				break;
			}
			else if (s_it->PC < branchContexts[ctxStart+ctx].PC) {
				if (s_it == runtimeStack.begin()) {
					++currentEvent.stackVisitEnd;
					nodes = 1;
				}
				else {
					++currentEvent.stackVisitMiddle;
				}
				++currentEvent.stackInsert;
				runtimeStack.insert(s_it, branchContexts[ctxStart+ctx]);
				break;
			}
			else if (s_it->PC == branchContexts[ctxStart+ctx].PC) {
				// merge with existing contexts if one exists
				s_it->active |= branchContexts[ctxStart+ctx].active;
				
				RuntimeStack::iterator next_it = s_it;
				++next_it;
				if (next_it == runtimeStack.end() || s_it == runtimeStack.begin()) {
					++currentEvent.stackVisitEnd;
					nodes = 1;
				}
				else {
					++currentEvent.stackVisitMiddle;
				}
				++currentEvent.stackMerge;
				break;
			}
		}
		currentEvent.stackVisitNodes += nodes;
	}
	
	if (currentEvent.stackVisitMiddle) {
		report("\n[PC " << context.PC << "]  " << instr.toString());
		report("insert into the middle of the context stack:");
		for (RuntimeStack::iterator s_it = runtimeStack.begin(); s_it != runtimeStack.end(); ++s_it) {
			report("   " << s_it->PC);
			if (branchContext.active.any() && s_it->PC == branchContext.PC) {
				report("  [branch target]"); 
			}
			if (fallthroughContext.active.any() && s_it->PC == fallthroughContext.PC) {
				report("  [fallthrough target]");
			}
		}
		report(" ");
	}
	return isDivergent;
}

void executive::ReconvergenceTFSortedStack::eval_Bar(executive::CTAContext &context,
	const ir::PTXInstruction &instr) {
	// barrier reconvergence with the sorted predicate stack
	CTAContext continuation(context);
	runtimeStack.pop_back();
	if (runtimeStack.size() == 0) {
		continuation.active.set();
		continuation.PC = context.PC + 1;
		runtimeStack.push_back(continuation);
	}
}

void executive::ReconvergenceTFSortedStack::eval_Reconverge(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	// attempt to merge top TWO CTAContext with current context 'picking up' additional threads
	if (runtimeStack.size() > 1) {	
		CTAContext activeContext = runtimeStack.back();
		runtimeStack.pop_back();
		
		if (runtimeStack.back().PC == activeContext.PC) {
			// merge contexts
			activeContext.active |= runtimeStack.back().active;
			runtimeStack.pop_back();
		}
		else {
			// otherwise, we assume all PCs are greater than current and continue
		}
		runtimeStack.push_back(activeContext);
	}
	runtimeStack.back().PC ++;
}

void executive::ReconvergenceTFSortedStack::eval_Exit(executive::CTAContext &context, 
	const ir::PTXInstruction &instr) {
	if (runtimeStack.size() == 1 || context.active.count() == context.active.size()) {
		context.running = false;
	}
	else {
		runtimeStack.pop_back();
	}
}

bool executive::ReconvergenceTFSortedStack::nextInstruction(executive::CTAContext &context,
	const ir::PTXInstruction &instr) {

	// advance to next instruction if the current instruction wasn't a branch
	if (instr.opcode != ir::PTXInstruction::Bra && 
		instr.opcode != ir::PTXInstruction::Bar &&
		instr.opcode != ir::PTXInstruction::Reconverge ) {
		context.PC++;
	}
	return context.running;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

