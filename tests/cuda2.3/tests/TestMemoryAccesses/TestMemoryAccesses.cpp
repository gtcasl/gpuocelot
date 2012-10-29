/*!	\file TestMemoryAccesses.h
	\date Thursday November 12, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief A test for memory access patterns.
*/

#ifndef TEST_MEMORY_ACCESSES_CPP_INCLUDED
#define TEST_MEMORY_ACCESSES_CPP_INCLUDED

#include <tests/TestMemoryAccesses/TestMemoryAccesses.h>
#include <hydrazine/interface/ArgumentParser.h>
#include <cuda_runtime_api.h>
#include <ocelot/api/interface/ocelot.h>

namespace test
{
	bool TestMemoryAccesses::testStridedAccess()
	{
		int* device1;
		int* device2;
		
		cudaMalloc( (void**) &device1, bytes );
		cudaMalloc( (void**) &device2, bytes );
		
		cudaMemset( device1, 1, bytes );
		cudaMemset( device2, 0, bytes );
		
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &device2, sizeof( long long unsigned int ), 0 );
		cudaSetupArgument( &device1, sizeof( long long unsigned int ), 
			sizeof( long long unsigned int ) );
		
		unsigned int ints = bytes / sizeof(int);
		
		cudaSetupArgument( &ints, sizeof( unsigned int ), 
			2 * sizeof( long long unsigned int ) );

		std::string program = ".version 2.1\n";
	
		program += ".target sm_21, map_f64_to_f32\n\n";
		program += ".entry stridedAccess( .param .u64 out, ";
		program += ".param .u64 in, .param .u32 size )\n";
		program += "{\n";
		program += " .reg .u64 %r<18>;\n";
		program += " .reg .pred %p0;\n";
		program += " Entry:\n";
		program += "  ld.param.u64 %r0, [in];\n";
		program += "  ld.param.u64 %r1, [out];\n";
		program += "  ld.param.u32 %r2, [size];\n";
		program += "  cvt.u64.s32 %r3, %ctaid.x;\n";
		program += "  cvt.u64.s32 %r4, %tid.x;\n";
		program += "  cvt.u64.s32 %r5, %ntid.x;\n";
		program += "  cvt.u64.s32 %r6, %nctaid.x;\n";
		
		program += "  mul.lo.u64 %r7, %r3, %r5;\n";
		program += "  add.u64 %r8, %r7, %r4;\n";
		program += "  mul.lo.u64 %r9, %r5, %r6;\n";

		program += "  mov.u64 %r10, %r8;\n"; // global id
		program += "  mov.u64 %r11, %r9;\n"; // thread count
		program += "  mov.u64 %r12, %r10;\n"; // counter
		program += "  mov.u64 %r13, %r2;\n"; // size

		program += "  setp.ge.u64 %p0, %r12, %r13;\n";
		program += "  @%p0 bra Exit;\n";
		program += " Loop_Begin:\n";
		program += "  mul.lo.u64 %r17, %r12, 4;\n";
		program += "  add.u64 %r14, %r17, %r0;\n";
		program += "  add.u64 %r15, %r17, %r1;\n";
		program += "  ld.global.u32 %r16, [%r14];\n";
		program += "  st.global.u32 [%r15], %r16;\n";
		program += "  add.u64 %r12, %r12, %r11;\n";
		program += "  setp.lt.u64 %p0, %r12, %r13;\n";
		program += "  @%p0 bra Loop_Begin;\n";
		program += " Exit:\n";
		program += "  exit;";
		program += "}\n";
	
		std::stringstream stream( program );
	
		ocelot::registerPTXModule( stream, "memory" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "memory", "stridedAccess" );
		cudaThreadSynchronize();
		timer.stop();
		
		double gb = bytes / 1073741824.0;
		
		status << "Strided copy test (" << gb << " GB):\n";
		status << " time: " << timer.seconds() << "s\n";
		status << " strided bandwidth: " 
			<< ( gb / timer.seconds() ) << " GB/s\n";
		
		int* host = new int[ ints ];

		cudaMemcpy( host, device2, bytes, cudaMemcpyDeviceToHost );
		
		bool pass = true;
		
		for( unsigned int i = 0; i < ints; ++i )
		{
			if( host[ i ] != 0x01010101 )
			{
				pass = false;
				status << "At index " << i 
					<< ", copied data " << host[ i ] 
					<< " does not match reference.\n";
				status << "Strided test failed.\n";
				break;
			}
		}
		
		delete[] host;
		cudaFree( device1 );
		cudaFree( device2 );
		
		return pass;
	}
	
	bool TestMemoryAccesses::testLinearAccess()
	{
		int* device1;
		int* device2;
		
		cudaMalloc( (void**) &device1, bytes );
		cudaMalloc( (void**) &device2, bytes );
		
		cudaMemset( device1, 1, bytes );
		cudaMemset( device2, 0, bytes );
		
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( 1, 1, 1 ), 0, 0 );
		cudaSetupArgument( &device2, sizeof( long long unsigned int ), 0 );
		cudaSetupArgument( &device1, sizeof( long long unsigned int ), 
			sizeof( long long unsigned int ) );
		
		unsigned int ints = bytes / sizeof(int);
		unsigned int stride = ( ints % ctas == 0 ) ? ints / ctas 
			: (ints / ctas) + 1;
		
		cudaSetupArgument( &ints, sizeof( unsigned int ), 
			2 * sizeof( long long unsigned int ) );
		cudaSetupArgument( &stride, sizeof( unsigned int ), 
			2 * sizeof( long long unsigned int ) + sizeof( unsigned int ) );

		std::string program = ".version 2.1\n";
	
		program += ".target sm_21, map_f64_to_f32\n\n";
		program += ".entry linearAccess( .param .u64 out, ";
		program += ".param .u64 in, .param .u32 size, .param .u32 stride )\n";
		program += "{\n";
		program += " .reg .u64 %r<18>;\n";
		program += " .reg .pred %p0;\n";
		program += " Entry:\n";
		program += "  ld.param.u64 %r0, [in];\n";
		program += "  ld.param.u64 %r1, [out];\n";
		program += "  ld.param.u32 %r2, [size];\n";
		program += "  ld.param.u32 %r3, [stride];\n";
		program += "  cvt.u64.s32 %r4, %ctaid.x;\n";
		
		program += "  mul.lo.u64 %r5, %r3, %r4;\n"; //begin
		program += "  add.u64 %r6, %r5, %r3;\n";
		program += "  min.u64 %r7, %r6, %r2;\n"; //end
		
		program += "  setp.ge.u64 %p0, %r5, %r7;\n";
		program += "  @%p0 bra Exit;\n";
		program += " Loop_Begin:\n";
		program += "  mul.lo.u64 %r8, %r5, 4;\n";
		program += "  add.u64 %r9, %r8, %r0;\n";
		program += "  add.u64 %r10, %r8, %r1;\n";
		program += "  ld.global.u32 %r11, [%r9];\n";
		program += "  st.global.u32 [%r10], %r11;\n";
		program += "  add.u64 %r5, %r5, 1;\n";
		program += "  setp.lt.u64 %p0, %r5, %r7;\n";
		program += "  @%p0 bra Loop_Begin;\n";
		program += " Exit:\n";
		program += "  exit;";
		program += "}\n";
	
		std::stringstream stream( program );
	
		ocelot::registerPTXModule( stream, "memory2" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "memory2", "linearAccess" );
		cudaThreadSynchronize();
		timer.stop();
		
		double gb = bytes / 1073741824.0;
		
		status << "Linear copy test (" << gb << " GB):\n";
		status << " time: " << timer.seconds() << "s\n";
		status << " linear bandwidth: " 
			<< ( gb / timer.seconds() ) << " GB/s\n";
		
		int* host = new int[ ints ];

		cudaMemcpy( host, device2, bytes, cudaMemcpyDeviceToHost );
		
		bool pass = true;
		
		for( unsigned int i = 0; i < ints; ++i )
		{
			if( host[ i ] != 0x01010101 )
			{
				pass = false;
				status << "At index " << i 
					<< ", copied data " << host[ i ] 
					<< " does not match reference.\n";
				status << "Linear test failed.\n";
				break;
			}
		}
		
		delete[] host;
		cudaFree( device1 );
		cudaFree( device2 );
		
		return pass;
	}

	bool TestMemoryAccesses::doTest()
	{
		return testStridedAccess() && testLinearAccess();
	}

	TestMemoryAccesses::TestMemoryAccesses()
	{
		name = "TestMemoryAccesses";
		description = "A benchmark for PTX memory operations.";
	}
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestMemoryAccesses test;
	parser.description( test.testDescription() );
	
	parser.parse( "-b", "--bytes", test.bytes, 1000000,
		"The number of bytes to copy." );
	parser.parse( "-t", "--threads", test.threads, 128,
		"The number of threads to launch for the atomic test." );
	parser.parse( "-c", "--ctas", test.ctas, 10,
		"The number of CTAs to launch for the atomic test." );
	parser.parse( "-s", "--seed", test.seed, 0,
		"Set the random seed, 0 implies seed with time." );
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out info after the test." );
	parser.parse();
	
	test.stride = test.threads;

	test.test();

	return test.passed();	
}

#endif

