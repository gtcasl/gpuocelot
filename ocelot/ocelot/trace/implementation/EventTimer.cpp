/*!
	\file EventTimer.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 11, 2011
	\brief
*/

#include <fstream>
#include <ocelot/trace/interface/EventTimer.h>


#ifdef _WIN32
	#include <windows.h>
#elif __APPLE__
	#include <mach/mach_time.h>
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::EventTimer::EventTimer(): cycleCount(0),accumulated(0),events(0),maxEvents(0) {

}

size_t executive::EventTimer::rdtsc() {
	// revisit later today
	return 0;
}
			
void executive::EventTimer::start(size_t startCycles) {
	if (!maxEvents || events < maxEvents) {
		cycleCount = startCycles;
		if (!startCycles) {
			cycleCount = rdtsc();
		}
	}
}

void executive::EventTimer::stop() {
	if (!maxEvents || events < maxEvents) {
		cycleCount = rdtsc() - cycleCount;
		accumulated += cycleCount;
		++events;
	}
}

size_t executive::EventTimer::cycles() const {
	return cycleCount;
}

std::ostream & operator<<(std::ostream &out, 
	const executive::EventTimer & timer) {
	out << "{ \"elapsed\": " << timer.getAccumulated() << ", \"events\": " << timer.getEvents() << " }";
	return out;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

