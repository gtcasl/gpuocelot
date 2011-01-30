/*! \file atomics.cu
	\date Tuesday November 10, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the set of atomic operation benchmarks
*/

#ifndef ATOMICS_CU_INCLUDED
#define ATOMICS_CU_INCLUDED

#include <ocelot/api/interface/ocelot.h>
#include <cuda_runtime_api.h>
#include <sstream>

long long unsigned int atomic_increment(long long unsigned int iterations, 
	unsigned int threads, unsigned int ctas)
{
	long long unsigned int* counter;
	
	cudaMalloc( (void**)&counter, sizeof(long long unsigned int) );
	cudaMemset( counter, 0, sizeof(long long unsigned int) );

	cudaConfigureCall( dim3( ctas, 1, 1 ), dim3( threads, 1, 1), 0, 0 );
	cudaSetupArgument( &iterations, sizeof(long long unsigned int), 0 );
	cudaSetupArgument( &counter, sizeof(long long unsigned int),
		sizeof(long long unsigned int) );
	
	std::string program = ".version 2.1\n";
	
	program += ".target sm_21, map_f64_to_f32\n\n";
	program += ".entry atomic_increment( .param .u64 iterations, .param .u64 counter )\n";
	program += "{\n";
	program += " .reg .u64 %r<3>;\n";
	program += " .reg .pred %p0;\n";
	program += " Entry:\n";
	program += "  ld.param.u64 %r0, [iterations];\n";
	program += "  mov.u64 %r1, 0;\n";
	program += "  ld.param.u64 %r2, [counter];\n";
	program += "  setp.ge.u64 %p0, %r1, %r0;\n";
	program += "  @%p0 bra Exit;\n";
	program += " Loop_Begin:\n";
	program += "  atom.global.add.u64 %r1, [%r2], 1;\n";
	program += "  setp.lt.u64 %p0, %r1, %r0;\n";
	program += "  @%p0 bra Loop_Begin;\n";
	program += " Exit:\n";
	program += "  exit;";
	program += "}\n";
	
	std::stringstream stream( program );
	
	ocelot::registerPTXModule( stream, "atomics" );
	ocelot::launch("atomics", "atomic_increment");
	
	long long unsigned int counterValue;
	
	cudaMemcpy( &counterValue, counter, sizeof(long long unsigned int), 
		cudaMemcpyDeviceToHost );
	cudaFree( counter );
	
	return counterValue;
}

long long unsigned int serial_increment(long long unsigned int iterations)
{
	long long unsigned int* counter;
	
	cudaMalloc( (void**)&counter, sizeof(long long unsigned int) );
	cudaMemset( counter, 0, sizeof(long long unsigned int) );

	cudaConfigureCall( dim3( 1, 1, 1 ), dim3( 1, 1, 1), 0, 0 );
	cudaSetupArgument( &iterations, sizeof(long long unsigned int), 0 );
	cudaSetupArgument( &counter, sizeof(long long unsigned int),
		sizeof(long long unsigned int) );
	
	std::string program = ".version 2.1\n";
	
	program += ".target sm_21, map_f64_to_f32\n\n";
	program += ".entry serial_increment( .param .u64 iterations, .param .u64 counter )\n";
	program += "{\n";
	program += " .reg .u64 %r<3>;\n";
	program += " .reg .pred %p0;\n";
	program += " Entry:\n";
	program += "  ld.param.u64 %r0, [iterations];\n";
	program += "  ld.param.u64 %r2, [counter];\n";
	program += "  mov.u64 %r1, 0;\n";
	program += "  setp.ge.u64 %p0, %r1, %r0;\n";
	program += "  @%p0 bra Store;\n";
	program += " Loop_Begin:\n";
	program += "  add.u64 %r1, %r1, 1;\n";
	program += "  setp.ge.u64 %p0, %r1, %r0;\n";
	program += "  @%p0 bra Store;\n";
	program += "  bra.uni Loop_Begin;\n";
	program += " Store:\n";
	program += "  st.global.u64 [%r2], %r1;\n";
	program += " Exit:\n";
	program += "  exit;";
	program += "}\n";
	
	std::stringstream stream( program );
	
	ocelot::registerPTXModule( stream, "serial" );

	ocelot::launch("serial", "serial_increment");
	
	long long unsigned int counterValue;
	
	cudaMemcpy( &counterValue, counter, sizeof(long long unsigned int), 
		cudaMemcpyDeviceToHost );
	cudaFree( counter );
	
	return counterValue;
}

#endif

