/*!

	\file ActiveTimer.cpp

	\date Wednesday September 24, 2008
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	
	\brief The source file for the ActiveTimer class.

*/

#ifndef ACTIVE_TIMER_CPP_INCLUDED
#define ACTIVE_TIMER_CPP_INCLUDED

#include "ActiveTimer.h"
#include <hydrazine/implementation/debug.h>
#include <cassert>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace hydrazine
{

	////////////////////////////////////////////////////////////////////////////			
	// ActiveTimer::SharedData

	ActiveTimer::SharedData ActiveTimer::_sharedData;

	ActiveTimer::SharedData::SharedData()
	{
	
		report( "Creating shared data." );
		pthread_mutex_init( &mutex, 0 );
		pthread_cond_init( &condition, 0 );
		pthread_attr_init( &attribute );
		pthread_attr_setstacksize( &attribute, ACTIVE_TIMER_STACK_SIZE );
		pthread_attr_setdetachstate( &attribute, PTHREAD_CREATE_DETACHED );		
		thread = 0;
		connections = 0;
		alive = false;
		timer.start();
	
	}
	
	ActiveTimer::SharedData::~SharedData()
	{
	
		report( "Destroying shared data." );
		assert( connections == 0 );
		pthread_mutex_destroy( &mutex );
		pthread_cond_destroy( &condition );
		pthread_attr_destroy( &attribute );
	
	}
	
	void ActiveTimer::SharedData::next()
	{
	
		pthread_mutex_lock( &mutex );

		//report( " Locked mutex, firing expired timers." );
		for( TimerMap::iterator fi = timers.begin(); fi != timers.end(); )
		{
		
			if( fi->first < timer.seconds() )
			{
		
				fi->second->_done = true;
				fi->second->fired();
				pthread_cond_signal( &fi->second->_condition );
				report( "  Fired ActiveTimer " << fi->second
					<< " at " << fi->first );
				TimerMap::iterator next = fi;
				++next;
				timers.erase( fi );
				fi = next;
		
			}
			else
			{
		
				//report( "  Checked ActiveTimer " << fi->second.second << 
				//	", remaining time is " 
				//	<< ( fi->first - timer.seconds() ) );
				++fi;
		
			}
		
		}
				
		if( timers.empty() )
		{
		
			//report( " No active timers, waiting." );		
			pthread_cond_wait( &condition, &mutex );
			//report( " Unlocking mutex." );
			pthread_mutex_unlock( &mutex );
		
		}
		else
		{
		
			//report( " Unlocking mutex, yielding." );
			pthread_mutex_unlock( &mutex );
			pthread_yield();
		
		}
		
	}
	
	void* ActiveTimer::SharedData::run( void* argument )
	{
	
		report( "Thread is alive." );
		ActiveTimer::SharedData& data = ActiveTimer::_sharedData;
		pthread_mutex_lock( &data.mutex );
		report( " Locked mutex" );
		assert( !data.alive );
		assert( argument == 0 );
		data.alive = true;
		report( " Signalled alive" );
		pthread_cond_signal( &data.condition );
		report( " Signalled creator, waiting for signal." );
		pthread_cond_wait( &data.condition, &data.mutex );
		report( " Signal received, unlocking mutex." );
		pthread_mutex_unlock( &data.mutex );
		
		while( data.connections > 0 )
		{
		
			data.next();
		
		}
		
		assert( data.timers.empty() );
		report( " Thread is dying." );
		data.alive = false;
		pthread_cond_signal( &data.condition );
		report( " Thread is dead." );
		pthread_exit( argument );
		
		return 0;
	}
	////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////
	// ActiveTimer
	ActiveTimer::ActiveTimer()
	{
	
		report( "Creating new ActiveTimer " << this );
		pthread_cond_init( &_condition, 0 );
		pthread_mutex_lock( &_sharedData.mutex );
		++_sharedData.connections;
		
		if( _sharedData.connections == 1 )
		{
		
			assert( _sharedData.thread == 0 );
			pthread_create( &_sharedData.thread, &_sharedData.attribute, 
				SharedData::run, 0 );
			report( " Waiting on condition " << this );
			pthread_cond_wait( &_sharedData.condition, &_sharedData.mutex );
			report( " Signalling " << this );
			pthread_cond_signal( &_sharedData.condition );
		
		}
		
		assert( _sharedData.alive );
		pthread_mutex_unlock( &_sharedData.mutex );
		_done = true;
	
	}
	
	ActiveTimer::~ActiveTimer()
	{
	
		report( "Destroying ActiveTimer " << this );
		pthread_mutex_lock( &_sharedData.mutex );
		assert( _sharedData.alive );
		
		if( !_done )
		{
		
			report("Timer not finished, waiting for signal.");
			pthread_cond_wait( &_condition, &_sharedData.mutex );
		
		}		
		
		--_sharedData.connections;
		
		if( _sharedData.connections == 0 )
		{
		
			pthread_cond_signal( &_sharedData.condition );
			pthread_cond_wait( &_sharedData.condition, &_sharedData.mutex );
			assert( !_sharedData.alive );
			_sharedData.thread = 0;
			
		}
		
		pthread_mutex_unlock( &_sharedData.mutex );
		pthread_cond_destroy( &_condition );
		report( "Destroyed ActiveTimer " << this );
	
	}

	ActiveTimer::ActiveTimer( const ActiveTimer& timer )
	{
	
		report( "Creating new ActiveTimer " << this << " from " << &timer );
		pthread_cond_init( &_condition, 0 );
		pthread_mutex_lock( &_sharedData.mutex );
		++_sharedData.connections;
		
		if( _sharedData.connections == 1 )
		{
		
			assert( _sharedData.thread == 0 );
			pthread_create( &_sharedData.thread, &_sharedData.attribute, 
				SharedData::run, 0 );
			pthread_cond_wait( &_sharedData.condition, &_sharedData.mutex );
			pthread_cond_signal( &_sharedData.condition );
		
		}
		
		assert( _sharedData.alive );
		pthread_mutex_unlock( &_sharedData.mutex );
		_done = true;
	
	}
	
	const ActiveTimer& ActiveTimer::operator=( const ActiveTimer& timer )
	{
	
		assert( this == &timer );
		return *this;
	
	}

	void ActiveTimer::start( Timer::Second seconds )
	{
	
		pthread_mutex_lock( &_sharedData.mutex );
		
		if( _sharedData.timers.empty() )
		{
		
			pthread_cond_signal( &_sharedData.condition );
		
		}
		
		_done = false;
		seconds += _sharedData.timer.seconds();
		_sharedData.timers.insert( std::make_pair( seconds, this ) );
		
		pthread_mutex_unlock( &_sharedData.mutex );
	
	}

	void ActiveTimer::wait()
	{
	
		pthread_mutex_lock( &_sharedData.mutex );
		
		if( !_done )
		{
			
			pthread_cond_wait( &_condition, &_sharedData.mutex );
		
		}
		
		pthread_mutex_unlock( &_sharedData.mutex );
	
	}
	////////////////////////////////////////////////////////////////////////////
		
}

#endif

