/*! \file CTAContext.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements a CTAContext
*/

#include <ocelot/executive/interface/CTAContext.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/CooperativeThreadArray.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

executive::CTAContext::CTAContext(const ir::Dim3 blockDim, executive::CooperativeThreadArray *c): cta(c) {
	using namespace boost;
	using namespace std;
		
	active = dynamic_bitset<>(blockDim.x * blockDim.y * blockDim.z, 1);
	PC = 0;
	running = true;
	for (int i = 0; i < blockDim.x*blockDim.y*blockDim.z; i++) {
		active[i] = 1;
	}
}

executive::CTAContext::~CTAContext() {

}

bool executive::CTAContext::predicated(int threadID, const ir::PTXInstruction &instr) {
	using namespace ir;
	
	bool on = false;
	if (active[threadID]) {
		ir::PTXOperand::PredicateCondition condition = instr.pg.condition;
		switch (condition) {
		case PTXOperand::PT:
			on = true;
			break;
		case PTXOperand::nPT:
			on = false;
			break;
		default:
			{
				report("CTAContext::predicated is actually inspecting a predicate register ..");

				bool pred = cta->getRegAsPredicate(threadID, instr.pg.reg);
				report("  with value " << pred);

				on = ((pred && condition == PTXOperand::Pred) 
					|| (!pred && condition == PTXOperand::InvPred));
			}
			break;
		}
	}
	return on;
}


