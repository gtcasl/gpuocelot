/*!
	\file EventTimer.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 11, 2011
	\brief
*/

#include <fstream>
#include <ocelot/executive/interface/EventTimer.h>

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::EventTimer::EventTimer(): cycleCount(0),accumulated(0),events(0),maxEvents(0) {

}

size_t executive::EventTimer::rdtsc() {
  uint32_t lo, hi;
  __asm__ __volatile__ (
  "        xorl %%eax,%%eax \n"
  "        cpuid"      // serialize
  ::: "%rax", "%rbx", "%rcx", "%rdx");
  __asm__ __volatile__ ("rdtsc" : "=a" (lo), "=d" (hi));
  return (size_t)(uint64_t)hi << 32 | lo;
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

