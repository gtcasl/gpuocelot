/*!
	\file EventTimer.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date May 2012
	\brief 
*/

#ifndef OCELOT_TRACE_EVENTTIMER_H_INCLUDED
#define OCELOT_TRACE_EVENTTIMER_H_INCLUDED

namespace executive {

	//! \brief timer for measuring performance of various types of execution-time events
	class EventTimer {
	public:
		EventTimer();
		void start(size_t startCycles = 0);
		void stop();
		size_t getAccumulated() const { return accumulated; }
		void clearAccumulated() { accumulated = 0; }
		size_t cycles() const;
		static size_t rdtsc();
		void setEvents(size_t _events) { events = _events; }
		size_t getEvents() const { return events; }
		void setMaxEvents(size_t _max) { maxEvents = _max; }
	protected:
		size_t cycleCount;
		size_t accumulated;
		size_t events;
		size_t maxEvents;
	};
}
std::ostream & operator<<(std::ostream &out, const executive::EventTimer & timer);
	
#endif

