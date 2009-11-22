/*!	\file TestCallLatency.cpp
	\date Saturday November 21, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for a test for cuda call latency.
*/

#ifndef TEST_CALL_LATENCY_CPP_INCLUDED
#define TEST_CALL_LATENCY_CPP_INCLUDED

#include <tests/TestCallLatency/TestCallLatency.h>
#include <hydrazine/implementation/ArgumentParser.h>
#include <cuda_runtime_api.h>
#include <ocelot/api/interface/ocelot.h>

namespace test
{
	bool TestCallLatency::testKernelLaunchLatency()
	{
		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );

		std::stringstream program;
		program << ".version 1.4\n";

		program << ".target sm_10, map_f64_to_f32\n\n";
		program << ".entry nop( )\n";
		program << "{\n";
		program << " exit;\n";
		program << "}";
		
		ocelot::registerPTXModule( program, "callLatency" );
		const char* kernelPointer = ocelot::getKernelPointer( 
			"nop", "callLatency" );
		
		hydrazine::Timer timer;
		
		timer.start();
		for( unsigned int i = 0; i < iterations; ++i )
		{
			cudaLaunch( kernelPointer );
			cudaThreadSynchronize();
		}
		timer.stop();
		
		status << "Kernel launch latency: " 
			<< ( timer.seconds() / iterations ) << "s\n";
		
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
	parser.parse( "-i", "--iterations", test.iterations, 10, 
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

