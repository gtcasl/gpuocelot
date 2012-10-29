/*!	\file TestCallLatency.cpp
	\date Saturday November 21, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for a test for cuda call latency.
*/

#ifndef TEST_CALL_LATENCY_CPP_INCLUDED
#define TEST_CALL_LATENCY_CPP_INCLUDED

#include <tests/TestCallLatency/TestCallLatency.h>
#include <hydrazine/interface/ArgumentParser.h>
#include <cuda_runtime_api.h>
#include <ocelot/api/interface/ocelot.h>

namespace test
{
	bool TestCallLatency::testKernelLaunchLatency()
	{
		unsigned int* address;
		
		cudaMalloc( (void**) &address, sizeof( unsigned int ) );
		cudaMemset( address, 0, sizeof( unsigned int ) );
		
		std::stringstream program;
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry nop( .param .u64 pointer )\n";
		program << "{\n";
		program << " .reg .u64 %address;\n";
		program << " .reg .u16 %cta;\n";
		program << " .reg .u32 %value;\n";
		program << " .reg .u16 %thread;\n";
		program << " .reg .pred %writer;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %address, [pointer];\n";
		program << "  mov.u16 %cta, %ctaid.x;\n";
		program << "  mov.u16 %thread, %tid.x;\n";
		program << "  setp.eq.u16 %writer, %cta, 0;\n";
		program << "  setp.eq.and.u16 %writer, %thread, 0, %writer;\n";
		program << "  @!%writer bra Exit;\n";
		program << " Store:\n";
		program << "  ld.global.u32 %value, [%address];\n";
		program << "  add.u32 %value, %value, 1;\n";
		program << "  st.global.u32 [%address], %value;\n";
		program << " Exit:\n";
		program << "  exit;\n";
		program << "}";
		
		ocelot::registerPTXModule( program, "callLatency" );
		
		hydrazine::Timer timer;
		
		unsigned int value;
		
		timer.start();
		for( value = 0; value < iterations; )
		{
			cudaConfigureCall( dim3( ctas, 1, 1 ), 
				dim3( threads, 1, 1 ), 0, 0 );
			cudaSetupArgument( &address, sizeof( long long unsigned int ), 0 );
			ocelot::launch( "callLatency", "nop" );
			cudaMemcpy( &value, address, sizeof( unsigned int ), 
				cudaMemcpyDeviceToHost );
		}
		timer.stop();
		
		status << "Kernel launch latency: " 
			<< ( timer.seconds() / iterations ) << "s\n";
		
		cudaFree( address );
		
		if( value != iterations )
		{
			status << " Incorrect value " << value << "\n";
			return false;
		}
				
		return true;
	}

	bool TestCallLatency::doTest()
	{
		return testKernelLaunchLatency();
	}

	TestCallLatency::TestCallLatency()
	{
		name = "TestCallLatency";
		
		description = "A set of microbenchmarks to determine ";
		description += "CUDA function latencies.";
	}
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestCallLatency test;
	parser.description( test.testDescription() );
	
	parser.parse( "-s", "--seed", test.seed, 0, 
		"Random seed. 0 implies seed with time." );
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out info after the test has finished." );
	parser.parse( "-i", "--iterations", test.iterations, 100000, 
		"The number of iterations to run." );
	parser.parse( "-c", "--ctas", test.ctas, 16, 
		"The number of ctas to launch." );
	parser.parse( "-t", "--threads", test.threads, 128, 
		"The number of threads per cta to launch." );
	parser.parse();
	
	test.test();
	
	return test.passed();
}

#endif

