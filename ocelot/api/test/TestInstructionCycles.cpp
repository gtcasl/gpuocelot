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

    typedef std::vector<std::string> PTXInstructionsVector;

    PTXInstructionsVector warpInstructions = 
    {
        "",
        "cvt.u64.u32 %r16, %tid.x",
        "cvt.u64.u32 %r17, %tid.y",
        "cvt.u64.u32 %r18, %tid.z",
        "cvt.u64.u32 %r19, %ntid.x",
        "cvt.u64.u32 %r20, %ntid.y",
        "mad.lo.u64 %r22, %r17, %r19, %r16",
        "mul.lo.u64 %r21, %r18, %r19",
        "mul.lo.u64 %r21, %r21, %r20",
        "add.u64 %r23, %r22, %r21",
        "cvt.u64.u32 %r24, %ntid.x",
        "mul.lo.u64 %r25, %r25, %r24",
        "cvt.u64.u32 %r26, %ctaid.x",
        "cvt.u64.u32 %r27, %ctaid.y",
        "cvt.u64.u32 %r28, %nctaid.x",
        "mad.lo.u64 %r29, %r27, %r28, %r26",
        "mul.lo.u64 %r30, %r29, %r25",
        "add.u64 %r31, %r30, %r23",
        "div.u64 %r32, %r31, 32",

        "mov.u32 %r33, %lanemask_lt",
        "setp.eq.u32 %p34, 0, 0",
        "vote.ballot.b32 %r35, %p34",
        "and.b32 %r36, %r35, %r33",
        "setp.eq.u32 %p37, %r36, 0",
        "@%p37 popc.b32 %r38, %r35",
        "@%p37 cvt.u64.u32 %r39, %r38",
        "@%p37 mul.lo.u64 %r40, 7, %r39",
        "@%p37 mad.lo.u64 %r42, %r32, 8, %r13",
        "@%p37 ld.global.u64 %r43, [%r42 + 0]",
        "@%p37 add.u64 %r44, %r43, %r40",
        "@%p37 st.global.u64 [%r42 + 0], %r44"
    };

    PTXInstructionsVector threadInstructions = 
    {
        "",
        "cvt.u64.u32 %r15, %ntid.x",
        "cvt.u64.u32 %r16, %ntid.y",
        "cvt.u64.u32 %r17, %ntid.z",
        "mul.lo.u64 %r18, %r15, %r16",
        "mul.lo.u64 %r18, %r18, %r17",
        "cvt.u64.u32 %r19, %tid.x",
        "cvt.u64.u32 %r20, %tid.y",
        "cvt.u64.u32 %r21, %tid.z",
        "mad.lo.u64 %r23, %r20, %r15, %r19",
        "mul.lo.u64 %r22, %r21, %r15",
        "mul.lo.u64 %r22, %r22, %r16",
        "add.u64 %r24, %r23, %r22",
        "cvt.u64.u32 %r25, %ctaid.x",
        "cvt.u64.u32 %r26, %ctaid.y",
        "cvt.u64.u32 %r27, %nctaid.x",
        "mad.lo.u64 %r28, %r26, %r27, %r25",

        "mul.lo.u64 %r29, %r18, %r28",
        "mul.lo.u64 %r30, 3, 0",
        "add.u64 %r31, %r30, %r29",
        "add.u64 %r32, %r31, %r24",
        "mad.lo.u64 %r34, %r32, 8, %r13",
        "ld.global.u64 %r35, [%r34 + 0]",
        "add.u64 %r36, %r35, 7",
        "st.global.u64 [%r34 + 0], %r36"
    };

    static void registerKernel()
	{
		std::string ptx = ".version 2.1\n";
		ptx += ".target sm_20\n\n";
		ptx += ".global .u64 __ocelot_base_address_101;\n\n";
		
		
		ptx += ".entry warpInstCount( )\n";
		ptx += "{\n";
		ptx += "	.reg .u64 %r<33>;\n";
		ptx += "	.reg .u32 %r33;\n";
		ptx += "	.reg .pred %p34;\n";
		ptx += "	.reg .b32 %r35;\n";
		ptx += "	.reg .b32 %r36;\n";
		ptx += "	.reg .pred %p37;\n";
		ptx += "	.reg .b32 %r38;\n";
		ptx += "	.reg .u64 %r39;\n";
		ptx += "	.reg .u64 %r40;\n";
		ptx += "	.reg .u64 %r42;\n";
		ptx += "	.reg .u64 %r43;\n";
		ptx += "	.reg .u64 %r44;\n";
		ptx += "	Entry:\n";
		ptx += "        mov.u64 %r12, __ocelot_base_address_101;\n";
	    ptx += "        ld.global.u64 %r13, [%r12 + 0];\n";
	    
	    ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[1] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 8], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx += 		    warpInstructions[2] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 16], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[3] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 24], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[4] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 32], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[5] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 40], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[6] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 48], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[7] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 56], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[8] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 64], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[9] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 72], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[10] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 80], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[11] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 88], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[12] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 96], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[13] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 104], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[14] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 112], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[15] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 120], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[16] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 128], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[17] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 136], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[18] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 144], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[19] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 152], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[20] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 160], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[21] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 168], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[22] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 176], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[23] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 184], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[24] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 192], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[25] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 200], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[26] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 208], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[27] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 216], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[28] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 224], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[29] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 232], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          warpInstructions[30] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 240], %r1;\n";

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
		ptx +=          threadInstructions[1] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 8], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[2] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 16], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[3] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 24], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[4] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 32], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[5] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 40], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[6] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 48], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[7] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 56], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[8] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 64], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[9] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 72], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[10] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 80], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[11] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 88], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[12] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 96], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[13] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 104], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[14] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 112], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[15] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 120], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[16] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 128], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[17] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 136], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[18] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 144], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[19] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 152], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[20] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 160], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[21] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 176], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[22] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 184], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[23] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 192], %r1;\n";
		
		ptx += "        mov.u64 %r0, %clock64;\n";
		ptx +=          threadInstructions[24] + ";\n";
		ptx += "        mov.u64 %r1, %clock64;\n";
		ptx += "        sub.u64 %r1, %r1, %r0;\n";
		ptx += "		st.global.u64 [%r13 + 200], %r1;\n";
	
		
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

        //WarpInstCount
		
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
		
		size_t *info = new size_t[31];
        if(counter) {
            cudaMemcpy(info, counter, 31 * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }
		
        unsigned int clockCycleTotal = 0;

		for(unsigned int i = 1; i < 31; i++)
		{
		    std::cout << warpInstructions[i] << ": " << info[i] << std::endl;
            clockCycleTotal += info[i];
		}

        unsigned int repeatInstructionCycles = 0;

        for(unsigned int i = 19; i < 31; i++)
        {
            repeatInstructionCycles += info[i];
        }
		
        std::cout << "\nBasic Block Instructions Clock Cycle Total: " << repeatInstructionCycles << "\n\n";
		std::cout << "Clock Cycle Total: " << clockCycleTotal << "\n\n";

        //ThreadInstCount

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
		
        clockCycleTotal = 0;
		for(unsigned int i = 1; i < 25; i++)
		{
		    std::cout << threadInstructions[i] << ": " << info[i] << std::endl;
            clockCycleTotal += info[i];
		}

        repeatInstructionCycles = 0;
        for(unsigned int i = 17; i < 25; i++)
        {
            repeatInstructionCycles += info[i];
        }
		
        std::cout << "\nBasic Block Instructions Clock Cycle Total: " << repeatInstructionCycles << "\n\n";
		std::cout << "Clock Cycle Total: " << clockCycleTotal << "\n\n";

        
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
