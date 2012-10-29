/*!	\file TestInstructionThroughput.cpp
	\date Saturday November 14, 2009
	\author Sudnya Padalikar <sudnya.padalikar@gatech.edu>
	\brief A test for instruction throughput.
*/

#ifndef TEST_INSTRUCTION_THROUGHPUT_CPP_INCLUDED
#define TEST_INSTRUCTION_THROUGHPUT_CPP_INCLUDED

#include <tests/TestInstructionThroughput/TestInstructionThroughput.h>
#include <hydrazine/interface/ArgumentParser.h>
#include <cuda_runtime_api.h>
#include <ocelot/api/interface/ocelot.h>

namespace test
{
	bool TestInstructionThroughput::testu64InstructionThroughput()
	{
		unsigned int* input;
		unsigned int k=5;
		
		cudaMalloc( ( void** ) &input, sizeof( unsigned int ) );
		cudaMemcpy( input, &k, sizeof( unsigned int ), cudaMemcpyHostToDevice );

		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &input, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testInstructionThroughput( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<7>;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.u32 %r1, [%r0];\n";
		program << " mov.u64 %r2,  " << iterations <<";\n";
		program << " mov.u64 %r3, 0; \n";
		program << " mov.u64 %r6, 0; \n";
		program << " setp.eq.u64 %p0, %r3, %r2;\n";
		program << " @%p0 bra Exit;\n";
		
		program << " Begin_iter:\n";
		for(int i=0; i<unroll; ++i )
		{
			program << "  add.u64 %r6, %r6, %r1;\n";
		}
		
		program << " add.u64 %r3, %r3, 1; \n";
		program << " setp.lt.u64 %p0, %r3, %r2;\n";
		program << " @%p0 bra Begin_iter;\n";
		
		program << " End_loop:";
		program << "  st.global.u32 [%r0], %r6;\n";

		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
			
		ocelot::registerPTXModule( program, "throughput" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "throughput", "testInstructionThroughput" );
		cudaThreadSynchronize();
		timer.stop();
		
		status << "u64 Operations/sec " 
			<< ( (threads * ctas * iterations * unroll) / timer.seconds() ) 
			<< " seconds. \n"; 
		unsigned int result;
		
		cudaMemcpy( &result, input, sizeof( unsigned int ), 
			cudaMemcpyDeviceToHost );
		
		bool pass = true;
		
		if( result != k * iterations * unroll && threads == 1 && ctas == 1 )
		{
			status << "Program generated incorrect output " << result 
				<< ", expecting " << (k * iterations * unroll ) << "\n";
			pass = false;
		}
		
		cudaFree( input );

		return pass;
	}

	bool TestInstructionThroughput::testu32InstructionThroughput()
	{
		unsigned int* input;
		unsigned int k=5;
		
		cudaMalloc( ( void** ) &input, sizeof( unsigned int ) );
		cudaMemcpy( input, &k, sizeof( unsigned int ), cudaMemcpyHostToDevice );

		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &input, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testu32InstructionThroughput( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<7>;\n";
		program << " .reg .u32 %sum;\n";
		program << " .reg .u32 %initial;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.u32 %initial, [%r0];\n";
		program << " mov.u64 %r2,  " << iterations <<";\n";
		program << " mov.u64 %r3, 0; \n";
		program << " mov.u32 %sum, 0; \n";
		program << " setp.eq.u64 %p0, %r3, %r2;\n";
		program << " @%p0 bra Exit;\n";
		
		program << " Begin_iter:\n";
		for(int i=0; i<unroll; ++i )
		{
			program << "  add.u32 %sum, %sum, %initial;\n";
		}
		
		program << " add.u64 %r3, %r3, 1; \n";
		program << " setp.lt.u64 %p0, %r3, %r2;\n";
		program << " @%p0 bra Begin_iter;\n";
		
		program << " End_loop:";
		program << "  st.global.u32 [%r0], %sum;\n";

		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
			
		ocelot::registerPTXModule( program, "u32throughput" );

		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "u32throughput", "testu32InstructionThroughput" );
		cudaThreadSynchronize();
		timer.stop();
		
		status << "u32 Operations/sec " 
			<< ( (threads * ctas * iterations * unroll) / timer.seconds() ) 
			<< " seconds. \n"; 
		unsigned int result;
		
		cudaMemcpy( &result, input, sizeof( unsigned int ), 
			cudaMemcpyDeviceToHost );
		
		bool pass = true;
		
		if( result != k * iterations * unroll && threads == 1 && ctas == 1 )
		{
			status << "Program generated incorrect output " << result 
				<< ", expecting " << (k * iterations * unroll ) << "\n";
			pass = false;
		}
		
		cudaFree( input );

		return pass;
	}


	bool TestInstructionThroughput::testf32InstructionThroughput()
	{
		unsigned int* input;
		float k=5;
		
		cudaMalloc( ( void** ) &input, sizeof( unsigned int ) );
		cudaMemcpy( input, &k, sizeof( unsigned int ), cudaMemcpyHostToDevice );

		cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1 ), 0, 0 );
		cudaSetupArgument( &input, sizeof( long long unsigned int ), 0 );
		
		std::stringstream program;
		
		program << ".version 2.1\n";

		program << ".target sm_21, map_f64_to_f32\n\n";
		program << ".entry testf32InstructionThroughput( .param .u64 input )\n";
		program << "{\n";
		program << " .reg .u64 %r<7>;\n";
		program << " .reg .f32 %sum;\n";
		program << " .reg .f32 %initial;\n";
		program << " .reg .pred %p0;\n";
		program << " Entry:\n";
		program << "  ld.param.u64 %r0, [input];\n";
		program << "  ld.global.f32 %initial, [%r0];\n";
		program << " mov.u64 %r2,  " << iterations <<";\n";
		program << " mov.u64 %r3, 0; \n";
		program << " mov.f32 %sum, 0; \n";
		program << " setp.eq.u64 %p0, %r3, %r2;\n";
		program << " @%p0 bra Exit;\n";
		
		program << " Begin_iter:\n";
		for(int i=0; i<unroll; ++i )
		{
			program << "  mad.f32 %sum, 0f3f800000, %initial, %sum;\n";
		}
		
		program << " add.u64 %r3, %r3, 1; \n";
		program << " setp.lt.u64 %p0, %r3, %r2;\n";
		program << " @%p0 bra Begin_iter;\n";
		
		program << " End_loop:";
		program << "  st.global.f32 [%r0], %sum;\n";

		program << " Exit:\n";
		program << "  exit;";
		program << "}\n";
			
		ocelot::registerPTXModule( program, "f32throughput" );
		hydrazine::Timer timer;
		
		timer.start();
		ocelot::launch( "f32throughput", "testf32InstructionThroughput" );
		cudaThreadSynchronize();
		timer.stop();
		
		status << "f32 Operations/sec " 
			<< ( (threads * ctas * iterations * unroll * 2) / timer.seconds() ) 
			<< " seconds. \n"; 
		float result;
		
		cudaMemcpy( &result, input, sizeof( float ), 
			cudaMemcpyDeviceToHost );
		
		bool pass = true;
		
		if( result != k * iterations * unroll && threads == 1 && ctas == 1 )
		{
			status << "Program generated incorrect output " << result 
				<< ", expecting " << (k * iterations * unroll ) << "\n";
			pass = false;
		}
		
		cudaFree( input );

		return pass;
	}



	bool TestInstructionThroughput::doTest()
	{
		return testu64InstructionThroughput() && testu32InstructionThroughput()
			&& testf32InstructionThroughput();
	}

	TestInstructionThroughput::TestInstructionThroughput()
	{
		name = "TestInstructionThroughput";
		description = "A benchmark for PTX Instruction Throughput.";
	}
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestInstructionThroughput test;
	parser.description( test.testDescription() );
	
	//threads, ctas, unroll, iter
	parser.parse( "-t", "--threads", test.threads, 8, 
		"The number of threads." );
	parser.parse( "-c", "--ctas", test.ctas, 1, "The number of CTAs." );
	parser.parse("-u", "--unroll", test.unroll, 10, "The unrolled times");
	parser.parse( "-i", "--iterations", test.iterations, 10000,
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

