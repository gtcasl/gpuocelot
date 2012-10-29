/*! \file atomics.cpp
	\date Tuesday November 10, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the set of atomic operation benchmarks
*/

#ifndef ATOMICS_CPP_INCLUDED
#define ATOMICS_CPP_INCLUDED

#include <hydrazine/interface/ArgumentParser.h>
#include <cuda_runtime_api.h>

#include "atomics.h"

namespace test
{
	bool TestAtomics::doTest()
	{
		hydrazine::Timer timer;
		
		timer.start();
		long long unsigned int atomic = atomic_increment( iterations, 
			threads, ctas );
		timer.stop();
		
		hydrazine::Timer::Second atomic_time = timer.seconds();
		
		timer.start();
		long long unsigned int serial = serial_increment( iterations );
		timer.stop();
		
		hydrazine::Timer::Second serial_time = timer.seconds();
		
		status << "Serial Time: " << serial_time << " seconds \n";
		status << "Atomic Time: " << atomic_time << " seconds \n";
		status << "Serial Speedup: " << ( atomic_time / serial_time ) << "x\n";
		
		if( serial > atomic )
		{
			status << "Serial result " << serial 
				<< " is greater than atomic result " << atomic << "\n";
			return false;
		}
		
		return true;
	}
	
	TestAtomics::TestAtomics()
	{
		name = "TestAtomics";
		description = "A performance test of the atomic implementation.\n";
	}
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestAtomics test;
	parser.description( test.testDescription() );
	
	parser.parse( "-i", "--iterations", test.iterations, 1000000,
		"The number of iterations to increment for." );
	parser.parse( "-t", "--threads", test.threads, 128,
		"The number of threads to launch for the atomic test." );
	parser.parse( "-c", "--ctas", test.ctas, 10,
		"The number of CTAs to launch for the atomic test." );
	parser.parse( "-s", "--seed", test.seed, 0,
		"Set the random seed, 0 implies seed with time." );
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out info after the test." );
	parser.parse();
	
	test.test();

	return test.passed();	
}

#endif
