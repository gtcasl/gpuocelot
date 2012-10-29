/*!	\file TestBarriers.cpp
	\date Friday November 13, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief A test for barrier overheads.
*/

#ifndef TEST_BARRIERS_CPP_INCLUDED
#define TEST_BARRIERS_CPP_INCLUDED

#include <tests/TestBarriers/TestBarriers.h>
#include <hydrazine/interface/ArgumentParser.h>
#include <cuda_runtime_api.h>
#include <ocelot/api/interface/ocelot.h>

namespace test
{
	bool TestBarriers::testBarriers()
	{
		unsigned int* input;
		
		cudaMalloc( ( void** ) &input, sizeof( unsigned int ) );
		cudaMemset( input, 0, sizeof( unsigned int ) );

		cudaConfigureCall( dim3( 1, 1, 1 ), dim3( 1, 1, 1 ), 0, 0 );
		cudaSetupArgument( &input, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testBarriers( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<5>;\n";
		program << " .reg .u64 %rb<" << variables << ">;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		
		for( unsigned int i = 0; i < variables; ++i )
		{
			program << "  mov.u64 %rb" << i << ", " << i << ";\n";		
		}
		
		program << "  mov.u64 %r1, 0;\n";
		program << "  mov.u64 %r2, " << iterations << ";\n";

		program << "  setp.ge.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Writeback;\n";
		program << " Loop_Begin:\n";
		
		for( unsigned int i = 0; i < barriers; ++i )
		{
			program << "  bar.sync 0;\n";
		}
		
		program << "  add.u64 %r1, %r1, 1;\n";
		program << "  setp.lt.u64 %p0, %r1, %r2;\n";
		program << "  @%p0 bra Loop_Begin;\n";
		
		program << " Writeback:\n";
		program << "  mov.u64 %r3, 0;\n";
		
		for( unsigned int i = 0; i < variables; ++i )
		{
			program << "  add.u64 %r3, %r3, %rb" << i << ";\n";		
		}
		
		program << "  cvt.u32.u64 %r4, %r3;\n";
		program << "  st.global.u32 [%r0], %r4;\n";
		
		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
	
		ocelot::registerPTXModule( program, "barriers" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "barriers", "testBarriers" );
		cudaThreadSynchronize();
		timer.stop();
		
		unsigned int ops = barriers * iterations;
		status << "Barrier test:\n";
		status << " throughput: " << (ops/timer.seconds()) << " barriers/s\n";
		status << " time: " << timer.seconds() << "\n";

		unsigned int result;
	
		cudaMemcpy( &result, input, sizeof( unsigned int ), 
			cudaMemcpyDeviceToHost );
		
		bool pass = true;
		
		if( result != variables * ( variables - 1 ) / 2 )
		{
			status << "Program generated incorrect output " << result 
				<< ", expecting " << ( variables * ( variables - 1 ) / 2 ) 
				<< "\n";
			pass = false;
		}
		
		cudaFree( input );
		
		return pass;
	}

	bool TestBarriers::doTest()
	{
		return testBarriers();
	}

	TestBarriers::TestBarriers()
	{
		name = "TestBarriers";
		description = "A benchmark for PTX barriers.";
	}
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestBarriers test;
	parser.description( test.testDescription() );
	
	parser.parse( "-a", "--variables", test.variables, 16,
		"The number of live variables crossing each barrier." );
	parser.parse( "-b", "--barriers", test.barriers, 1,
		"The number of barriers per iteration." );
	parser.parse( "-i", "--iterations", test.iterations, 1000000,
		"The number of times to run through the barrier region." );
	parser.parse( "-s", "--seed", test.seed, 0,
		"Set the random seed, 0 implies seed with time." );
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out info after the test." );
	parser.parse();
	
	test.test();

	return test.passed();
}

#endif

