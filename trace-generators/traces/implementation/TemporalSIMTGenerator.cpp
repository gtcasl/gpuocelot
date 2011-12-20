/*!
	\file TemporalSIMTGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Dec 2011
	\brief counts dynamic instructions issued for a SIMT processor
*/

#include <cstdlib>
#include <fstream>

#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/ExecutableKernel.h>

#include <traces/interface/TemporalSIMTGenerator.h>

trace::TemporalSIMTGenerator::TemporalSIMTGenerator() {

	// GF100 configuration
	warpSize = 32;
	simdWidth = 16;
	simdIssueCount = 2;
}

trace::TemporalSIMTGenerator::~TemporalSIMTGenerator() {

}

/*! \brief called when a traced kernel is launched to retrieve some 
		parameters from the kernel
*/
void trace::TemporalSIMTGenerator::initialize(const executive::ExecutableKernel& kernel) {
	warpActiveCount = 0;
	warpIssueCount = 0;
	threadActiveCount = 0;
	
	kernelName = kernel.name;
}

/*! \brief Called whenever an event takes place.

	Note, the const reference 'event' is only valid until event() 
	returns
*/
void trace::TemporalSIMTGenerator::event(const TraceEvent & event) {
	size_t threads = event.blockDim.size();
	for (size_t wtid = 0; wtid < threads; wtid += warpSize) {
		size_t warpIssue = 0;
		for (size_t tid = 0; tid < warpSize; tid += simdWidth) {
			size_t issueActive = 0;
			for (size_t i = 0; i < simdWidth; i++) {
				size_t tidx = i + tid + wtid;
				if (tidx < threads && event.active[tidx]) {
					issueActive ++;
				}
			}
			if (issueActive) {
				threadActiveCount += issueActive;
				warpIssue ++;
			}
		}
		if (warpIssue) {
			warpIssueCount += warpIssue;
			warpActiveCount ++;
		}
	}
}

/*! \brief called when an event is committed
*/
void trace::TemporalSIMTGenerator::postEvent(const TraceEvent & event) {

}

/*! \brief Called when a kernel is finished. There will be no more 
		events for this kernel.
*/
void trace::TemporalSIMTGenerator::finish() {
	std::ofstream resultFile("temporalSIMT.json", std::ios_base::app);
	
	const char *appname = std::getenv("APPNAME");
	if (!appname) {
		appname = "UnknownApplication";
	}
	
	resultFile << "{ app: \"" << appname << "\", kernel: \"" << kernelName << "\", "
		<< "warpActiveCount: " << warpActiveCount 
		<< ", warpIssueCount: " << warpIssueCount
		<< ", threadActiveCount: " << threadActiveCount << " },\n";
}

