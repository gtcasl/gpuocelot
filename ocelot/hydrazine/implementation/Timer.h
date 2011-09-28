/*!	\file Timer.h
*
*	\brief Header file for the Timer class
*
*	\author Gregory Diamos
*
*	\date : 9/27/2007
*
*/

#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <hydrazine/implementation/LowLevelTimer.h>
#include <hydrazine/interface/Stringable.h>

/*!
	\brief a namespace for hydrazine classes and functions
*/
namespace hydrazine
{


	class Timer : public LowLevelTimer, public Stringable
	{
		public:	
			std::string toString() const;
	};

}

#endif

