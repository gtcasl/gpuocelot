/*!	\file LowLevelTimer.cpp
*
*	\brief Source file for the LowLevelTimer class
*
*	Author: Gregory Diamos
*
*
*/

#ifndef LOW_LEVEL_TIMER_CPP_INCLUDED
#define LOW_LEVEL_TIMER_CPP_INCLUDED

#include "LowLevelTimer.h"

namespace hydrazine
{

	////////////////////////////////////////////////////////////////////////////////
	// Precise Timer

	LowLevelTimer::LowLevelTimer()
	{
	
		start();
	
	}

	void LowLevelTimer::start()
	{
	
		beginning = rdtsc();
	    beginningS = ( beginning + 0.0 ) * 1.0e-9;        
		running = true;
		
	}

	void LowLevelTimer::stop()
	{

		ending = rdtsc();

		endingS = ( ending + 0.0 ) * 1.0e-9;

		running = false;

	}

	LowLevelTimer::Cycle LowLevelTimer::cycles() const
	{
		
		if( running )
		{
		
			return ( rdtsc() - beginning );
		
		}
		else
		{
		
			return ( ending - beginning );
		
		}
		
	}

	LowLevelTimer::Second LowLevelTimer::seconds() const
	{

        if( running )
        {
        
            return ( ( ( rdtsc() + 0.0 ) * 1.0e-9 ) - beginningS );
        
        }
        else
        {
        
            return endingS - beginningS;
        
        }
		
	}

	LowLevelTimer::Second LowLevelTimer::absolute() const
	{

        if( running )
        {
        
            return ( ( ( rdtsc() + 0.0 ) * 1.0e-9 ) );
        
        }
        else
        {
        
            return endingS;
        
        }
		
	}
	
	extern "C" 
	{
	
		LowLevelTimer::Cycle LowLevelTimer::rdtsc()
		{
	
			timespec spec;
		
			clock_gettime( CLOCK_REALTIME, &spec );
		
			return spec.tv_nsec + spec.tv_sec * 1000000000;
					
		}
		
	}
	////////////////////////////////////////////////////////////////////////////////

}

#endif

