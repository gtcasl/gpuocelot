/*!
	\file TestLLVMKernels.cpp
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the TestLLVMKernels unit test.
*/

#ifndef TEST_LLVM_KERNELS_CPP_INCLUDED
#define TEST_LLVM_KERNELS_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/executive/test/TestLLVMKernels.h>
#include <ocelot/executive/interface/Device.h>

// Hydrazine Includes
#include <hydrazine/implementation/ArgumentParser.h>

// Standard Library Includes
#include <cmath>

namespace test
{
	bool TestLLVMKernels::_loadKernels()
	{
		bool loaded = false;
		try 
		{
			loaded = _module.load(kernelFile);
		}
		catch( const hydrazine::Exception& e )
		{
			status << " error - " << e.what() << "\n";
		}

		if( !loaded ) 
		{
			status << "Failed to load module '" << kernelFile << "'\n";
			return false;
		}
		
		ir::Kernel* kernel = _module.getKernel( "_Z19k_sequenceDivergentPf" );
		if( !kernel )
		{
			status << "Failed to get kernel _Z19k_sequenceDivergentPf\n";
			return false;
		}
		
		_divergentKernel = new executive::LLVMExecutableKernel( *kernel, 0, 
			translator::Translator::BasicOptimization );
		_divergentKernel->setKernelShape( 8, 1, 1 );

		kernel = _module.getKernel( "_Z17k_sequenceLoopingPfi" );
		if( !kernel )
		{
			status << "Failed to get kernel _Z17k_sequenceLoopingPfi\n";
			return false;
		}
		
		_loopingKernel = new executive::LLVMExecutableKernel( *kernel, 0, 
			translator::Translator::BasicOptimization );
		_loopingKernel->setKernelShape( 8, 1, 1 );

		kernel = _module.getKernel( "_Z7barrierPiS_" );
		if( !kernel )
		{
			status << "Failed to get kernel _Z7barrierPiS_\n";
			return false;
		}
		
		_barrierKernel = new executive::LLVMExecutableKernel( *kernel, 0, 
			translator::Translator::BasicOptimization );
		_barrierKernel->setKernelShape( 8, 1, 1 );
		
		kernel = _module.getKernel( "_Z21k_matrixVectorProductPKfS0_Pfii" );
		if( !kernel )
		{
			status << "Failed to get kernel " 
				<< "_Z21k_matrixVectorProductPKfS0_Pfii\n";
			return false;
		}
		
		_matrixMultiplyKernel = new executive::LLVMExecutableKernel( *kernel, 0, 
			translator::Translator::BasicOptimization );
		_matrixMultiplyKernel->setKernelShape( 8, 1, 1 );
		
		return true;
	}

	bool TestLLVMKernels::testDivergent()
	{
		executive::LLVMExecutableKernel* kernel = _divergentKernel;
		
		unsigned int N = 8;
		
		float* sequence = new float[ N ];

		for( unsigned int i = 0; i < N; ++i ) 
		{
			sequence[ i ] = -2.0;
		}

		// configure parameters
		ir::Parameter& param_A = *kernel->getParameter(
			"__cudaparm__Z19k_sequenceDivergentPf_ptr" );

		// set parameter values
		param_A.arrayValues.resize( 1 );
		param_A.arrayValues[ 0 ].val_u64 = (ir::PTXU64)sequence;
		kernel->updateParameterMemory();

		// launch the kernel
		kernel->setKernelShape( N, 1, 1 );
		kernel->launchGrid( 1, 1 );
	
		for( unsigned int i = 0; i < N; i++ )
		{
			float w = i * 0.0625f;
			if( i % 2 ) 
			{
				if( fabs( cos( w ) - sequence[ i ] ) > 0.001f ) 
				{
					status << "error on element " << i << " - cos(" 
						<< w << ") = " << cos( w ) << ", encountered " 
						<< sequence[ i ] << "\n";
					return false;
				}
			}
			else
			{
				if( fabs( sin( w ) - sequence[ i ] ) > 0.001f ) 
				{
					status << "error on element " << i << " - sin(" 
						<< w << ") = " << sin( w ) << ", encountered " 
						<< sequence[ i ] << "\n";
					return false;
				}
			}
		}

		delete[] sequence;
	
		return true;
	}

	bool TestLLVMKernels::testLooping()
	{
		executive::LLVMExecutableKernel* kernel = _loopingKernel;
		
		unsigned int N = 8 * 5;
		float* sequence = new float[ N ];

		for( unsigned int i = 0; i < N; ++i ) 
		{
			sequence[ i ] = -2;	
		}

		ir::Parameter& param_A = *kernel->getParameter(
			"__cudaparm__Z17k_sequenceLoopingPfi_ptr");
		ir::Parameter& param_B = *kernel->getParameter(
			"__cudaparm__Z17k_sequenceLoopingPfi_N");

		param_A.arrayValues.resize( 1 );
		param_A.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) sequence;
		param_B.arrayValues.resize( 1 );
		param_B.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) N;
		kernel->updateParameterMemory();

		kernel->setKernelShape( 8, 1, 1 );
		kernel->launchGrid( 1, 1 );

		for( unsigned int i = 0; i < N; ++i ) 
		{
			float w = i * 0.0625f;
			if( i % 2 )
			{
				if( fabs( cos( w ) - sequence[ i ] ) > 0.001f ) 
				{
					status << "error on element " << i 
						<< " - cos(" << w << ") = " << cos( w ) 
						<< ", encountered " << sequence[ i ] << "\n";
					return false;
				}
			}
			else 
			{
				if( fabs( sin( w ) - sequence[ i ] ) > 0.001f ) 
				{
					status << "error on element " << i 
						<< " - sin(" << w << ") = " << sin(w) 
						<< ", encountered " << sequence[i] << "\n";
					return false;
				}
			}
		}
		
		delete[] sequence;
		
		return true;
	}

	bool TestLLVMKernels::testBarrier()
	{
		executive::LLVMExecutableKernel* kernel = _barrierKernel;
		
		unsigned int N = 8;
		int* in = new int[ N ];
		int* out = new int[ N ];

		for( unsigned int i = 0; i < N; ++i ) 
		{
			in[ i ] = i;
			out[ i ] = -2;
		}

		ir::Parameter& param_A = *kernel->getParameter(
			"__cudaparm__Z7barrierPiS__in");
		ir::Parameter& param_B = *kernel->getParameter(
			"__cudaparm__Z7barrierPiS__out");

		param_A.arrayValues.resize( 1 );
		param_A.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) in;
		param_B.arrayValues.resize( 1 );
		param_B.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) out;
		kernel->updateParameterMemory();

		kernel->setKernelShape( 8, 1, 1 );
		kernel->launchGrid( 1, 1 );

		for( unsigned int i = 0; i < N; ++i ) 
		{
			if( in[i] != out[ ( i + 1 ) % N ] )
			{
				status << "At index " << i << " input " 
					<< in[ i ] 
					<< " does not match output " 
					<< out[ ( i + 1 ) % N ] << "\n";
				return false;
			}
		}
		
		delete[] in;
		delete[] out;
		
		return true;
	}
	
	bool TestLLVMKernels::testMatrixMultiply()
	{
		executive::LLVMExecutableKernel* kernel = _matrixMultiplyKernel;

		const unsigned int M = 8, N = 8;

		float* A = new float[ M * N ];
		float* V = new float[ N ];
		float* R = new float[ M ];

		status << "A = [\n";
		for( unsigned int i = 0; i < M; i++ ) 
		{
			status << " ";
			for( unsigned int j = 0; j < N; j++ ) 
			{
				A[ i + j * N ] = 0;
				if ( i >= j )
				{
					A[ i + j * N ] = 1.0f / ( float )( 1 + i - j );
				}
				V[ j ] = ( float )( 1 + j );
				status << A[ i + j * N ] << " ";
			}
			R[ i ] = -2;
			status << ";\n";
		}

		status << "];\n";

		status << "V = [\n";
		for (unsigned int j = 0; j < N; j++) {
			status << " " << V[j] << " ;\n";
		}
		status << "];\n";
			
		ir::Parameter &param_A = *kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii___val_paramA" );
		ir::Parameter &param_V = *kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii___val_paramV" );
		ir::Parameter &param_R = *kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii_R" );
		ir::Parameter &param_M = *kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii_M" );
		ir::Parameter &param_N = *kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii_N" );

		param_A.arrayValues.resize( 1 );
		param_A.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) A;
		param_V.arrayValues.resize( 1 );
		param_V.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) V;
		param_R.arrayValues.resize( 1 );
		param_R.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) R;
		param_M.arrayValues.resize( 1 );
		param_M.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) M;
		param_N.arrayValues.resize( 1 );
		param_N.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) N;
		
		kernel->updateParameterMemory();

		kernel->setKernelShape( 8, 1, 1 );
		kernel->launchGrid( 1, 1 );

		bool pass = true;
		status << "R = [\n";
		for( unsigned int i = 0; i < M; i++ ) 
		{
			float r_ref = 0;
			for( unsigned int j = 0 ; j < N; j++ ) 
			{
				r_ref += V[ j ] * A[ i + j * N ];
			}
			if( fabs( r_ref - R[ i ] ) > 0.01f ) 
			{
				pass = false;
			}
			status << " " << R[i] << " ;\n";
		}
		status << "];\n";
		
		if( !pass )
		{
			status << "Computed and reference results do not match.\n";
			return false;		
		}

		delete[] R;
		delete[] V;
		delete[] A;
		
		return true;
	}
	
	bool TestLLVMKernels::doTest()
	{
		if( executive::Device::deviceCount( ir::Instruction::LLVM ) == 0 )
		{
			status << "No LLVM device present.\n";
			return true;
		}
		
		bool result = _loadKernels();
		
		return result && testDivergent() && testLooping()
			&& testBarrier() 
			&& testMatrixMultiply();
	}
	
	TestLLVMKernels::TestLLVMKernels()
	{
		name = "TestLLVMKernels";

		description = "A unit test for the LLVM executive runtime.";
		description += " Test Points: 1) Execute a kernel with divergent ";
		description += "control flow. 2) Execute a kernel with a loop. ";
		description += "3) Execute a matrix multiply kernel.";

		_divergentKernel = 0;
		_loopingKernel = 0;
		_barrierKernel = 0;
		_matrixMultiplyKernel = 0;
	}
	
	TestLLVMKernels::~TestLLVMKernels()
	{
		delete _divergentKernel;
		delete _loopingKernel;
		delete _barrierKernel;
		delete _matrixMultiplyKernel;
	}
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestLLVMKernels test;

	parser.description( test.testDescription() );

	parser.parse( "-i", test.kernelFile, "ocelot/executive/test/kernels.ptx", 
		"The input file containing the kernels being tested." );
	parser.parse( "-s", test.seed, 0,
		"Set the random seed, 0 implies seed with time." );
	parser.parse( "-v", test.verbose, false, "Print out info after the test." );
	parser.parse();

	test.test();

	return test.passed();
}

#endif

