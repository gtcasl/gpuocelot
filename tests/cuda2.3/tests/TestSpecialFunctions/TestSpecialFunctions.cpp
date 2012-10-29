/*!	\file TestSpecialFunctions.cpp
	\date Friday November 13, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief A test for special function throughput.
*/

#ifndef TEST_BARRIERS_CPP_INCLUDED
#define TEST_BARRIERS_CPP_INCLUDED

#include <tests/TestSpecialFunctions/TestSpecialFunctions.h>
#include <hydrazine/interface/ArgumentParser.h>
#include <cuda_runtime_api.h>
#include <ocelot/api/interface/ocelot.h>

namespace test
{
	bool TestSpecialFunctions::testRcp()
	{
		float value = random() / (random.max() + 0.0);
		
		float* inout;
		
		cudaMalloc( (void**) &inout, sizeof( float ) );
		cudaMemcpy( inout, &value, sizeof( float ), cudaMemcpyHostToDevice );
		
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &inout, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testRcp( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<5>;\n";
		program << " .reg .f32 %rf<2>;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.f32 %rf0, [%r0];\n";
		program << "  mov.u64 %r1, 0;\n";
		program << "  mov.u64 %r2, " << iterations << ";\n";
		program << "  mov.f32 %rf1, %rf0;\n";
		program << "  setp.ge.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Exit;\n";
		program << " Loop_Begin:\n";
		for( unsigned int i = 0; i < unroll; ++i )
		{
			program << "  rcp.approx.ftz.f32 %rf1, %rf1;\n";
		}
		
		program << "  add.u64 %r1, %r1, 1;\n";
		program << "  setp.lt.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Loop_Begin;\n";
		
		program << " Writeback:\n";
		program << "  st.global.f32 [%r0], %rf1;\n";
		
		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
		
		ocelot::registerPTXModule( program, "rcp" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "rcp", "testRcp" );
		cudaThreadSynchronize();
		timer.stop();

		long long unsigned int ops = threads * ctas * iterations * unroll;

		status << "Test RCP (" << ops << " operations):\n";
		status << " RCP throughput: " << ( ops / timer.seconds() ) 
			<< " ops/s\n";

		float result;

		cudaMemcpy( &result, inout, sizeof( float ), cudaMemcpyDeviceToHost );
				
		cudaFree( inout );
		
		return true;
	}
	
	bool TestSpecialFunctions::testSqrt()
	{
		float value = random() / (random.max() + 0.0);
		
		float* inout;
		
		cudaMalloc( (void**) &inout, sizeof( float ) );
		cudaMemcpy( inout, &value, sizeof( float ), cudaMemcpyHostToDevice );
		
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &inout, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testSqrt( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<5>;\n";
		program << " .reg .f32 %rf<2>;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.f32 %rf0, [%r0];\n";
		program << "  mov.u64 %r1, 0;\n";
		program << "  mov.u64 %r2, " << iterations << ";\n";
		program << "  mov.f32 %rf1, %rf0;\n";
		program << "  setp.ge.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Exit;\n";
		program << " Loop_Begin:\n";
		for( unsigned int i = 0; i < unroll; ++i )
		{
			program << "  sqrt.approx.ftz.f32 %rf1, %rf1;\n";
		}
		
		program << "  add.u64 %r1, %r1, 1;\n";
		program << "  setp.lt.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Loop_Begin;\n";
		
		program << "  cvt.u64.s32 %r3, %tid.x;\n";
		program << "  cvt.u64.s32 %r4, %ctaid.x;\n";
		
		program << "  setp.eq.u64 %p0, %r3, 0;\n";
		program << "  setp.eq.and.u64 %p0, %r4, 0, %p0;\n";
		
		program << "  @!%p0 bra Exit;\n";

		program << " Writeback:\n";
		program << "  st.global.f32 [%r0], %rf1;\n";
		
		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
		
		ocelot::registerPTXModule( program, "sqrt" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "sqrt", "testSqrt" );
		cudaThreadSynchronize();
		timer.stop();

		long long unsigned int ops = threads * ctas * iterations * unroll;

		status << "Test SQRT (" << ops << " operations):\n";
		status << " SQRT throughput: " << ( ops / timer.seconds() ) << " ops/s\n";

		float result;

		cudaMemcpy( &result, inout, sizeof( float ), cudaMemcpyDeviceToHost );
				
		cudaFree( inout );
		
		return true;
	}
	
	bool TestSpecialFunctions::testRsqrt()
	{
		float value = random() / (random.max() + 0.0);
		
		float* inout;
		
		cudaMalloc( (void**) &inout, sizeof( float ) );
		cudaMemcpy( inout, &value, sizeof( float ), cudaMemcpyHostToDevice );
		
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &inout, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testRsqrt( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<5>;\n";
		program << " .reg .f32 %rf<2>;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.f32 %rf0, [%r0];\n";
		program << "  mov.u64 %r1, 0;\n";
		program << "  mov.u64 %r2, " << iterations << ";\n";
		program << "  mov.f32 %rf1, %rf0;\n";
		program << "  setp.ge.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Exit;\n";
		program << " Loop_Begin:\n";
		for( unsigned int i = 0; i < unroll; ++i )
		{
			program << "  rsqrt.approx.ftz.f32 %rf1, %rf1;\n";
		}
		
		program << "  add.u64 %r1, %r1, 1;\n";
		program << "  setp.lt.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Loop_Begin;\n";
		
		program << "  cvt.u64.s32 %r3, %tid.x;\n";
		program << "  cvt.u64.s32 %r4, %ctaid.x;\n";
		
		program << "  setp.eq.u64 %p0, %r3, 0;\n";
		program << "  setp.eq.and.u64 %p0, %r4, 0, %p0;\n";
		
		program << "  @!%p0 bra Exit;\n";

		program << " Writeback:\n";
		program << "  st.global.f32 [%r0], %rf1;\n";
		
		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
		
		ocelot::registerPTXModule( program, "rsqrt" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "rsqrt", "testRsqrt" );
		cudaThreadSynchronize();
		timer.stop();

		long long unsigned int ops = threads * ctas * iterations * unroll;

		status << "Test RSQRT (" << ops << " operations):\n";
		status << " RSQRT throughput: " << ( ops / timer.seconds() ) << " ops/s\n";

		float result;

		cudaMemcpy( &result, inout, sizeof( float ), cudaMemcpyDeviceToHost );
				
		cudaFree( inout );
		
		return true;
	}
	
	bool TestSpecialFunctions::testSin()
	{
		float value = random() / (random.max() + 0.0);
		
		float* inout;
		
		cudaMalloc( (void**) &inout, sizeof( float ) );
		cudaMemcpy( inout, &value, sizeof( float ), cudaMemcpyHostToDevice );
		
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &inout, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testSin( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<5>;\n";
		program << " .reg .f32 %rf<2>;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.f32 %rf0, [%r0];\n";
		program << "  mov.u64 %r1, 0;\n";
		program << "  mov.u64 %r2, " << iterations << ";\n";
		program << "  mov.f32 %rf1, %rf0;\n";
		program << "  setp.ge.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Exit;\n";
		program << " Loop_Begin:\n";
		for( unsigned int i = 0; i < unroll; ++i )
		{
			program << "  sin.approx.ftz.f32 %rf1, %rf1;\n";
		}
		
		program << "  add.u64 %r1, %r1, 1;\n";
		program << "  setp.lt.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Loop_Begin;\n";
		
		program << "  cvt.u64.s32 %r3, %tid.x;\n";
		program << "  cvt.u64.s32 %r4, %ctaid.x;\n";
		
		program << "  setp.eq.u64 %p0, %r3, 0;\n";
		program << "  setp.eq.and.u64 %p0, %r4, 0, %p0;\n";
		
		program << "  @!%p0 bra Exit;\n";

		program << " Writeback:\n";
		program << "  st.global.f32 [%r0], %rf1;\n";
		
		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
		
		ocelot::registerPTXModule( program, "sin" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "sin", "testSin" );
		cudaThreadSynchronize();
		timer.stop();

		long long unsigned int ops = threads * ctas * iterations * unroll;

		status << "Test SIN (" << ops << " operations):\n";
		status << " SIN throughput: " << ( ops / timer.seconds() ) << " ops/s\n";

		float result;

		cudaMemcpy( &result, inout, sizeof( float ), cudaMemcpyDeviceToHost );
				
		cudaFree( inout );
		
		return true;
	}
	
	bool TestSpecialFunctions::testCos()
	{
		float value = random() / (random.max() + 0.0);
		
		float* inout;
		
		cudaMalloc( (void**) &inout, sizeof( float ) );
		cudaMemcpy( inout, &value, sizeof( float ), cudaMemcpyHostToDevice );
		
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &inout, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testCos( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<5>;\n";
		program << " .reg .f32 %rf<2>;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.f32 %rf0, [%r0];\n";
		program << "  mov.u64 %r1, 0;\n";
		program << "  mov.u64 %r2, " << iterations << ";\n";
		program << "  mov.f32 %rf1, %rf0;\n";
		program << "  setp.ge.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Exit;\n";
		program << " Loop_Begin:\n";
		for( unsigned int i = 0; i < unroll; ++i )
		{
			program << "  cos.approx.ftz.f32 %rf1, %rf1;\n";
		}
		
		program << "  add.u64 %r1, %r1, 1;\n";
		program << "  setp.lt.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Loop_Begin;\n";
		
		program << "  cvt.u64.s32 %r3, %tid.x;\n";
		program << "  cvt.u64.s32 %r4, %ctaid.x;\n";
		
		program << "  setp.eq.u64 %p0, %r3, 0;\n";
		program << "  setp.eq.and.u64 %p0, %r4, 0, %p0;\n";
		
		program << "  @!%p0 bra Exit;\n";

		program << " Writeback:\n";
		program << "  st.global.f32 [%r0], %rf1;\n";
		
		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
		
		ocelot::registerPTXModule( program, "cos" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "cos", "testCos" );
		cudaThreadSynchronize();
		timer.stop();

		long long unsigned int ops = threads * ctas * iterations * unroll;

		status << "Test COS (" << ops << " operations):\n";
		status << " COS throughput: " << ( ops / timer.seconds() ) << " ops/s\n";

		float result;

		cudaMemcpy( &result, inout, sizeof( float ), cudaMemcpyDeviceToHost );
				
		cudaFree( inout );
		
		return true;
	}
	
	bool TestSpecialFunctions::testLg2()
	{
		float value = random() / (random.max() + 0.0);
		
		float* inout;
		
		cudaMalloc( (void**) &inout, sizeof( float ) );
		cudaMemcpy( inout, &value, sizeof( float ), cudaMemcpyHostToDevice );
		
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &inout, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testLg2( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<5>;\n";
		program << " .reg .f32 %rf<2>;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.f32 %rf0, [%r0];\n";
		program << "  mov.u64 %r1, 0;\n";
		program << "  mov.u64 %r2, " << iterations << ";\n";
		program << "  mov.f32 %rf1, %rf0;\n";
		program << "  setp.ge.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Exit;\n";
		program << " Loop_Begin:\n";
		for( unsigned int i = 0; i < unroll; ++i )
		{
			program << "  lg2.approx.ftz.f32 %rf1, %rf1;\n";
		}
		
		program << "  add.u64 %r1, %r1, 1;\n";
		program << "  setp.lt.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Loop_Begin;\n";
		
		program << "  cvt.u64.s32 %r3, %tid.x;\n";
		program << "  cvt.u64.s32 %r4, %ctaid.x;\n";
		
		program << "  setp.eq.u64 %p0, %r3, 0;\n";
		program << "  setp.eq.and.u64 %p0, %r4, 0, %p0;\n";
		
		program << "  @!%p0 bra Exit;\n";

		program << " Writeback:\n";
		program << "  st.global.f32 [%r0], %rf1;\n";
		
		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
		
		ocelot::registerPTXModule( program, "lg2" );
		
		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "lg2", "testLg2" );
		cudaThreadSynchronize();
		timer.stop();

		long long unsigned int ops = threads * ctas * iterations * unroll;

		status << "Test LG2 (" << ops << " operations):\n";
		status << " LG2 throughput: " << ( ops / timer.seconds() ) << " ops/s\n";

		float result;

		cudaMemcpy( &result, inout, sizeof( float ), cudaMemcpyDeviceToHost );
				
		cudaFree( inout );
		
		return true;
	}
	
	bool TestSpecialFunctions::testEx2()
	{
		float value = random() / (random.max() + 0.0);
		
		float* inout;
		
		cudaMalloc( (void**) &inout, sizeof( float ) );
		cudaMemcpy( inout, &value, sizeof( float ), cudaMemcpyHostToDevice );
		
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &inout, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testEx2( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<5>;\n";
		program << " .reg .f32 %rf<2>;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.f32 %rf0, [%r0];\n";
		program << "  mov.u64 %r1, 0;\n";
		program << "  mov.u64 %r2, " << iterations << ";\n";
		program << "  mov.f32 %rf1, %rf0;\n";
		program << "  setp.ge.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Exit;\n";
		program << " Loop_Begin:\n";
		for( unsigned int i = 0; i < unroll; ++i )
		{
			program << "  ex2.approx.ftz.f32 %rf1, %rf1;\n";
		}
		
		program << "  add.u64 %r1, %r1, 1;\n";
		program << "  setp.lt.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Loop_Begin;\n";
		
		program << "  cvt.u64.s32 %r3, %tid.x;\n";
		program << "  cvt.u64.s32 %r4, %ctaid.x;\n";
		
		program << "  setp.eq.u64 %p0, %r3, 0;\n";
		program << "  setp.eq.and.u64 %p0, %r4, 0, %p0;\n";
		
		program << "  @!%p0 bra Exit;\n";

		program << " Writeback:\n";
		program << "  st.global.f32 [%r0], %rf1;\n";
		
		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
		
		ocelot::registerPTXModule( program, "ex2" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "ex2", "testEx2" );
		cudaThreadSynchronize();
		timer.stop();

		long long unsigned int ops = threads * ctas * iterations * unroll;

		status << "Test EX2 (" << ops << " operations):\n";
		status << " EX2 throughput: " << ( ops / timer.seconds() ) << " ops/s\n";

		float result;

		cudaMemcpy( &result, inout, sizeof( float ), cudaMemcpyDeviceToHost );
				
		cudaFree( inout );
		
		return true;
	}
		
	bool TestSpecialFunctions::doTest()
	{
		return testRcp() && testSqrt() && testRsqrt() && testSin() 
			&& testCos() && testLg2() && testEx2();
	}

	TestSpecialFunctions::TestSpecialFunctions()
	{
		name = "TestSpecialFunctions";
		description = "Benchmark for special function and texture throughput.";
	}
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestSpecialFunctions test;
	parser.description( test.testDescription() );
	
	parser.parse( "-t", "--threads", test.threads, 8,
		"The number of threads per cta." );
	parser.parse( "-c", "--ctas", test.ctas, 8,
		"The number of ctas to launch." );
	parser.parse( "-u", "--unroll", test.unroll, 100,
		"The number of times to unroll the inner loop." );
	parser.parse( "-i", "--iterations", test.iterations, 100,
		"The number of times to run each operation for." );
	parser.parse( "-s", "--seed", test.seed, 0,
		"Set the random seed, 0 implies seed with time." );
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out info after the test." );
	parser.parse();
	
	test.test();

	return test.passed();
}

#endif

