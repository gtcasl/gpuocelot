/*! \file TestInstructionCycles.cpp
	\date Thursday September 8, 2011
	\author Naila Farooqui
	\brief The source file for the TestInstructionCycles class.
*/

#ifndef TEST_INSTRUCTION_CYCLES_CPP_INCLUDED
#define TEST_INSTRUCTION_CYCLES_CPP_INCLUDED

#include <ocelot/api/test/TestInstructionCycles.h>
#include <ocelot/api/interface/ocelot.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <vector>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace test
{

    static void registerKernel()
	{
		std::string ptx = ".version 2.1\n";
		ptx += ".target sm_20\n\n";
		ptx += ".global .u64 __ocelot_base_address_101;\n\n";
		
		
		ptx += ".entry warpInstCount( )\n";
		ptx += "{\n";
		ptx += "	.reg .u64 %r<35>;\n";
		ptx += "	.reg .u32 %r35;\n";
		ptx += "	.reg .b32 %r37;\n";
		ptx += "	.reg .b32 %r38;\n";
		ptx += "	.reg .b32 %r40;\n";
		ptx += "	.reg .u64 %r41;\n";
		ptx += "	.reg .u64 %r42;\n";
		ptx += "	.reg .u64 %r43;\n";
		ptx += "	.reg .u64 %r44;\n";
		ptx += "	.reg .u64 %r45;\n";
		ptx += "	.reg .u64 %r46;\n";
		ptx += "	.reg .u64 %r47;\n";
		ptx += "	.reg .u64 %r48;\n";
		ptx += "	.reg .pred %p36;\n";
		ptx += "	.reg .pred %p39;\n";
		ptx += "	Entry:\n";
		ptx += "        mov.u64 %r12, __ocelot_base_address_101;\n";
	    ptx += "        ld.global.u64 %r13, [%r12 + 0];\n";
	    
	    ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r16, %tid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 8], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r17, %tid.y;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 16], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r18, %tid.z;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 24], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r19, %ntid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 32], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r20, %ntid.y;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 40], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mad.lo.u64 %r22, %r17, %r19, %r16;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 48], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r21, %r18, %r19;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 56], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r21, %r21, %r20;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 64], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		add.u64 %r23, %r22, %r21;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 72], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r24, %ntid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 80], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r25, %ntid.y;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 88], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r26, %ntid.z;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 96], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r27, %r24, %r25;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 104], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r27, %r27, %r26;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 112], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r28, %ctaid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 120], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r29, %ctaid.y;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 128], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r30, %nctaid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 136], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mad.lo.u64 %r31, %r29, %r30, %r28;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 144], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r32, %r31, %r27;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 152], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		add.u64 %r33, %r32, %r23;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 160], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		div.u64 %r34, %r33, 32;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 168], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mov.u32 %r35, %lanemask_lt;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 176], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		setp.eq.u32 %p36, 0, 0;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 184], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		vote.ballot.b32 %r37, %p36;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 192], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		and.b32 %r38, %r37, %r35;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 200], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		setp.eq.b32 %p39, %r38, 0;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 208], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		@%p39 popc.b32 %r40, %r37;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 216], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		@%p39 cvt.u64.u32 %r41, %r40;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 224], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		@%p39 mul.lo.u64 %r42, 7, %r41;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 232], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		@%p39 mad.lo.u64 %r44, %r34, 8, %r13;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 240], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		@%p39 ld.global.u64 %r45, [%r44 + 0];\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 248], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		@%p39 add.u64 %r46, %r45, %r42;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 256], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		@%p39 mad.lo.u64 %r48, %r34, 8, %r13;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 264], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		@%p39 st.global.u64 [%r48 + 0], %r46;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 272], %r1;\n";

		ptx += "	Exit:\n";
		ptx += "		exit;\n";
		ptx += "}\n";
		
		ptx += ".entry threadInstCount( )\n";
		ptx += "{\n";
		ptx += "	.reg .u64 %r<41>;\n";
		ptx += "	Entry:\n";
		ptx += "        mov.u64 %r12, __ocelot_base_address_101;\n";
	    ptx += "        ld.global.u64 %r13, [%r12 + 0];\n";
	    
	    ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r15, %ntid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 8], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r16, %ntid.y;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 16], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r17, %ntid.z;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 24], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r18, %r15, %r16;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 32], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r18, %r18, %r17;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 40], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r19, %tid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 48], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r20, %tid.y;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 56], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r21, %tid.z;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 64], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r22, %ntid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 72], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r23, %ntid.y;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 80], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mad.lo.u64 %r25, %r20, %r22, %r19;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 88], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r24, %r21, %r22;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 96], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r24, %r24, %r23;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 104], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		add.u64 %r26, %r25, %r24;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 112], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r27, %ctaid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 120], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r28, %ctaid.y;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 128], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		cvt.u64.u32 %r29, %nctaid.x;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 136], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mad.lo.u64 %r30, %r28, %r29, %r27;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 144], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r31, %r18, %r30;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 152], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mul.lo.u64 %r32, 3, 0;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 160], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		add.u64 %r33, %r32, %r31;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 176], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		add.u64 %r34, %r33, %r26;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 184], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mad.lo.u64 %r36, %r34, 8, %r13;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 192], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		ld.global.u64 %r37, [%r36 + 0];\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 200], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		add.u64 %r38, %r37, 7;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 208], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		mad.lo.u64 %r40, %r34, 8, %r13;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 216], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += "		st.global.u64 [%r40 + 0], %r38;\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 224], %r1;\n";
		
		ptx += "	Exit:\n";
		ptx += "		exit;\n";
		ptx += "}\n";

		
		std::stringstream stream( ptx );
		ocelot::registerPTXModule( stream, "instrumentationKernels" );
	}
	
	bool TestInstructionCycles::testCycles()
	{
		report("Running instruction cycles test.");
		report(" Resetting runtime state.");
		ocelot::reset();
		report(" Registering kernel.");
		registerKernel();
		
		size_t *counter = 0;
		
		if(cudaMalloc((void **) &counter, 35 * sizeof(size_t)) != cudaSuccess){
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, 35  * sizeof( size_t )) != cudaSuccess){
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        
        if(cudaMemcpyToSymbol("__ocelot_base_address_101", &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
		
			
		cudaConfigureCall( dim3( 1, 1, 1 ), dim3( 1, 1, 1 ), 0, 0 );
		ocelot::launch( "instrumentationKernels", "warpInstCount" );
		
		
		std::cout << "Warp Instruction Count Results\n\n";
		
		size_t *info = new size_t[35];
        if(counter) {
            cudaMemcpy(info, counter, 35 * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }
		
		for(unsigned int i = 1; i < 35; i++)
		{
		    std::cout << "instruction " << i << ": " << info[i] << std::endl;
		}
		
		if(cudaMalloc((void **) &counter, 35 * sizeof(size_t)) != cudaSuccess){
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, 35  * sizeof( size_t )) != cudaSuccess){
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        
        if(cudaMemcpyToSymbol("__ocelot_base_address_101", &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
		
			
		cudaConfigureCall( dim3( 1, 1, 1 ), dim3( 1, 1, 1 ), 0, 0 );
		ocelot::launch( "instrumentationKernels", "threadInstCount" );
		
		
		std::cout << "Thread Instruction Count Results\n\n";
		
        if(counter) {
            cudaMemcpy(info, counter, 35 * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }
		
		for(unsigned int i = 1; i < 29; i++)
		{
		    std::cout << "instruction " << i << ": " << info[i] << std::endl;
		}
		
		
		status << "Test Passed\n";
		return true;
	}
	
	bool TestInstructionCycles::doTest()
	{
		return testCycles();
	}

	TestInstructionCycles::TestInstructionCycles()
	{
		name = "TestInstructionCycles";
		
		description = "A unit test for the ability of the CUDA runtime to \
			count cycles for each instruction";
	}
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestInstructionCycles test;
	parser.description( test.testDescription() );

	parser.parse( "-s", "--seed", test.seed, 0, 
		"Random number generator seed, 0 implies seed with time." );
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out information after the test has finished." );
	parser.parse();
	
	test.test();
	
	return test.passed();	
}

#endif
