/*!
	\file BranchEvent.cpp
	\date Friday July 24, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the BranchEvent class.
*/

#ifndef BRANCH_EVENT_CPP_INCLUDED
#define BRANCH_EVENT_CPP_INCLUDED

#include <ocelot/trace/interface/BranchEvent.h>

namespace trace
{
	BranchEvent::BranchEvent()
	{
	
	}
	
	BranchEvent::BranchEvent( 
		const TraceEvent::BitMask& _taken, 
		const TraceEvent::BitMask& _fallthrough,
		const unsigned int _pc,
		const unsigned int _counter ) : 
		taken( _taken ), fallthrough( _fallthrough ), pc( _pc ), 
		counter( _counter )
	{
	
	}
}

#endif


