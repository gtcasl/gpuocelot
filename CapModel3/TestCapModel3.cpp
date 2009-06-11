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
#include <common/implementation/ArgumentParser.h>
#include <cuda_runtime_api.h>
#include <common/cuda/Cuda.h>

namespace test
{

	/*!
	
		\brief A test for the CapModel3 class.
		
		Test Points:
		
			1) Run the simulation using the CPU C version and the GPU CUDA
				version, comparing the results.
	
	*/

	bool TestCapModel3::_testCpuGpu( std::string& status )
	{
	
		sim::CapModel3 simulation( parameters, ratingsFileName,  
			industryFileName, portfolioFileName, obligorsFileName, 
			twistersFileName );
		
		simulation.useGpu = useGpu;
		
		simulation.run();
		
		return true;
	
	}

	bool TestCapModel3::doTest( std::string& status )
	{
	
		int devices;
		
		cudaCheck( cudaGetDeviceCount( &devices ) );
		
		device = MIN( devices - 1, device );
		
		report( "Binding to device " << ( device ) );
		cudaCheck( cudaSetDevice( device ) );
	
		if( !_testCpuGpu( status ) )
		{
		
			status += "Test Point 1 (cpu/gpu): failed.\n";
			return false;
		
		}

		status += "Test Point 1 (cpu/gpu): passed.\n";
		status += "Test Passed.\n";
	
		return true;
	
	}

	TestCapModel3::TestCapModel3()
	{
	
		Name = "TestCapModel3";
		
		Description = "A test for the CapModel3 class. Test Points: 1) Run the";
		Description += " simulation using the CPU C version and the GPU CUDA";
		Description += " version, comparing the results.";
	
	}
	
}

int main( int argc, char** argv )
{

	common::ArgumentParser parser( argc, argv );
	test::TestCapModel3 test;
	parser.description( test.description() );

	bool help;
	bool verbose;

	parser.parse( "-h", help, "Display this help message." );
	parser.parse( "-s", test.seed, 0, 
		"Random seed for repeatibility, 0 implies seed with clock." );
	parser.parse( "-v", verbose, 
		"Print out info after the test." );

	parser.parse( "-cpu", test.useGpu, 
		"Use the cpu simulation instead of the gpu." );
	test.useGpu = !test.useGpu;
	parser.parse( "-device", test.device, 0,
		"The id of the gpu to use." );
	parser.parse( "-simulations", test.parameters.numberOfSimulations, 10000, 
		"Number of monte carlo simulations to run." );
	parser.parse( "-month", test.parameters.date.month, 9, 
		"Starting month." );
	parser.parse( "-day", test.parameters.date.day, 19, 
		"Starting day." );
	parser.parse( "-year", test.parameters.date.year, 2008, 
		"Starting year." );
	parser.parse( "-chunkSize", test.parameters.chunkSize, 1000, 
		"Number of monte carlo simulations to per chunk." );
	parser.parse( "-investRate", test.parameters.investRate, .05, 
		"Investment rate." );
	parser.parse( "-initialEquity", test.parameters.initialEquity, 90000, 
		"Initial equity." );
	parser.parse( "-debtParameter", test.parameters.debtParameter, 0.0, 
		"Debt parameter." );
	parser.parse( "-debtRate", test.parameters.debtRate, 0.0, 
		"Debt rate." );
	parser.parse( "-optionExpense", test.parameters.optionExpense, 3000, 
		"Option expense." );
	parser.parse( "-optionInflation", test.parameters.optionInflation, 0.05, 
		"Option inflation." );
	parser.parse( "-managementFeeRate", test.parameters.managementFeeRate, 
		0.001, "Management fee rate." );
	parser.parse( "-assetManagementFeeRate", 
		test.parameters.assetManagementFeeRate, 0.0005, 
		"Asset management fee rate" );
	parser.parse( "-managementFeeCap", test.parameters.managementFeeCap, 15000, 
		"Management fee cap." );
	parser.parse( "-lgdMean", test.parameters.lgdMean, .55, 
		"lgd mean." );
	parser.parse( "-lgdStdev", test.parameters.lgdStdev, .25, 
		"lgd standard deviation." );
	parser.parse( "-targetPointSpread", test.parameters.targetPointSpread, 40, 
		"Target point spread." );
	
	parser.parse( "-ratings", test.ratingsFileName, 
		"data/ratings.csv", "Ratings input file name." );
	parser.parse( "-industry", test.industryFileName, 
		"data/industry.csv", "Industry input file name." );
	parser.parse( "-portfolio", test.portfolioFileName, 
		"data/portfolio.csv", "Portfolio input file name." );
	parser.parse( "-obligors", test.obligorsFileName, 
		"data/obligors.csv", "Obligor input file name." );
	parser.parse( "-twisters", test.twistersFileName, 
		"data/mersenneTwisters.dat", "Mersenne Twister input file name." );
		
	if( help )
	{
	
		std::cout << parser.help();
		return 2;
	
	}

	test.test();

	if( verbose )
	{
	
		std::cout << test.toString();
	
	}

	return test.passed();

}

#endif

