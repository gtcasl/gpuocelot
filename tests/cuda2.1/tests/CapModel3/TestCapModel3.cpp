/*!

	\file TestCapModel3.cpp
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>

	\date Saturday December 13, 2008

	\brief The source file for the TestCapModel3 class.

*/

#ifndef TEST_CAP_MODEL_3_CPP_INCLUDED
#define TEST_CAP_MODEL_3_CPP_INCLUDED

#include "TestCapModel3.h"
#include "CapModel3.h"
#include "ArgumentParser.h"
#include <cuda_runtime_api.h>
#include "CudaException.h"

namespace test
{

	/*!
	
		\brief A test for the CapModel3 class.
		
		Test Points:
		
			1) Run the simulation using the CPU C version and the GPU CUDA
				version, comparing the results.
	
	*/

	bool TestCapModel3::_testCpuGpu( )
	{
	
		sim::CapModel3 simulation( parameters, ratingsFileName,  
			industryFileName, portfolioFileName, obligorsFileName, 
			twistersFileName );
		
		simulation.useGpu = useGpu;
		
		simulation.run();
		
		return true;
	
	}

	bool TestCapModel3::doTest( )
	{
	
		int devices;
		
		hydrazine::cudaCheck( cudaGetDeviceCount( &devices ) );
		
		device = MIN( devices - 1, device );
		
		report( "Binding to device " << ( device ) );
		hydrazine::cudaCheck( cudaSetDevice( device ) );
	
		if( !_testCpuGpu( ) )
		{
		
			status << "Test Point 1 (cpu/gpu): failed.\n";
			return false;
		
		}

		status << "Test Point 1 (cpu/gpu): passed.\n";
		status << "Test Passed.\n";
	
		return true;
	
	}

	TestCapModel3::TestCapModel3()
	{
	
		name = "TestCapModel3";
		
		description = "A test for the CapModel3 class. Test Points: 1) Run the";
		description += " simulation using the CPU C version and the GPU CUDA";
		description += " version, comparing the results.";
	
	}
	
}

int main( int argc, char** argv )
{

	hydrazine::ArgumentParser parser( argc, argv );
	test::TestCapModel3 test;
	parser.description( test.testDescription() );

	parser.parse( "-s", test.seed, 0, 
		"Random seed for repeatibility, 0 implies seed with clock." );
	parser.parse( "-v", test.verbose, false, 
		"Print out info after the test." );

	parser.parse( "-c", "--cpu", test.useGpu, false,
		"Use the cpu simulation instead of the gpu." );
	test.useGpu = !test.useGpu;
	parser.parse( "-d", "--device", test.device, 0,
		"The id of the gpu to use." );
	parser.parse( "-s", "--simulations", test.parameters.numberOfSimulations, 1000, 
		"Number of monte carlo simulations to run." );
	parser.parse( "-c", "--month", test.parameters.date.month, 9, 
		"Starting month." );
	parser.parse( "-c", "--day", test.parameters.date.day, 19, 
		"Starting day." );
	parser.parse( "-c", "--year", test.parameters.date.year, 2008, 
		"Starting year." );
	parser.parse( "-c", "--chunkSize", test.parameters.chunkSize, 1000, 
		"Number of monte carlo simulations to per chunk." );
	parser.parse( "-c", "--investRate", test.parameters.investRate, .05, 
		"Investment rate." );
	parser.parse( "-c", "--initialEquity", test.parameters.initialEquity, 90000, 
		"Initial equity." );
	parser.parse( "-c", "--debtParameter", test.parameters.debtParameter, 0.0, 
		"Debt parameter." );
	parser.parse( "-c", "--debtRate", test.parameters.debtRate, 0.0, 
		"Debt rate." );
	parser.parse( "-c", "--optionExpense", test.parameters.optionExpense, 3000, 
		"Option expense." );
	parser.parse( "-c", "--optionInflation", test.parameters.optionInflation, 0.05, 
		"Option inflation." );
	parser.parse( "-c", "--managementFeeRate", test.parameters.managementFeeRate, 
		0.001, "Management fee rate." );
	parser.parse( "-c", "--assetManagementFeeRate", 
		test.parameters.assetManagementFeeRate, 0.0005, 
		"Asset management fee rate" );
	parser.parse( "-c", "--managementFeeCap", test.parameters.managementFeeCap, 15000, 
		"Management fee cap." );
	parser.parse( "-c", "--lgdMean", test.parameters.lgdMean, .55, 
		"lgd mean." );
	parser.parse( "-c", "--lgdStdev", test.parameters.lgdStdev, .25, 
		"lgd standard deviation." );
	parser.parse( "-c", "--targetPointSpread", test.parameters.targetPointSpread, 40, 
		"Target point spread." );
	
	parser.parse( "-c", "--ratings", test.ratingsFileName, 
		"data/ratings.csv", "Ratings input file name." );
	parser.parse( "-c", "--industry", test.industryFileName, 
		"data/industry.csv", "Industry input file name." );
	parser.parse( "-c", "--portfolio", test.portfolioFileName, 
		"data/portfolio.csv", "Portfolio input file name." );
	parser.parse( "-c", "--obligors", test.obligorsFileName, 
		"data/obligors.csv", "Obligor input file name." );
	parser.parse( "-c", "--twisters", test.twistersFileName, 
		"data/mersenneTwisters.dat", "Mersenne Twister input file name." );
	parser.parse();
	
	test.test();
	return test.passed();

}

#endif

