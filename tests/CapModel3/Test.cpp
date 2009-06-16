/*!
	\file Test.cpp
	\author Gregory Diamos
	\date July 4 2008
	\brief Contains the class implementation for the Test infertace
*/

#ifndef TEST_CPP_INCLUDED
#define TEST_CPP_INCLUDED

#include "Test.h"
#include <ctime>

namespace test
{

	void Test::_seed()
	{
		if( seed == 0 )
		{	
			seed = std::time( 0 );			
		}
		random.seed( seed );
	}

	Test::Test()
	{
		_testRun = false;
		_passed = false;
		verbose = false;
		seed = 0;
	}
	
	Test::~Test()
	{

	}
	
	void Test::test()
	{
		assert( !_testRun );
		hydrazine::Timer Timer;
		
		_seed();
		Timer.start();
		_passed = doTest( );
		Timer.stop();
		_time = Timer.seconds();
		_testRun = true;
		
		if( verbose )
		{
			std::cout << toString();
		}
	}
	
	std::string Test::toString() const
	{	
		std::stringstream stream;	
		if( _testRun )
		{
			if( _passed )
			{
				stream << "Pass/Fail : Pass\n\n"; 
			}
			else
			{
				stream << "Pass/Fail : Fail\n\n";
			}
		}
		
		stream << "\nName : " << name << "\n\n";
		stream << "Description : " << description << "\n\n";
		
		if( _testRun )
		{
			stream << "Test Seed : " << seed << "\n";
			stream << "Test time : " << _time << "\n\n";
			stream << "Status : " << status.str() << "\n\n";
		}
							
		return stream.str();
	}
	
	std::string Test::testStatus() const
	{
		assert( _testRun );
		return status.str();
	}
	
	const std::string& Test::testName() const
	{
		return name;
	}
	
	const std::string& Test::testDescription() const
	{
		return description;
	}
	
	bool Test::passed() const
	{
		assert( _testRun );
		return _passed;
	}
	
	bool Test::run() const
	{
		return _testRun;
	}
	
	hydrazine::Timer::Second Test::time() const
	{
		assert( _testRun );	
		return _time;
	}

}

#endif

