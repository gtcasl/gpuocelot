/*******************************************************************************
**
**  Monte Carlo eXtreme (MCX)  - GPU accelerated Monte Carlo 3D photon migration
**  Author: Qianqian Fang <fangq at nmr.mgh.harvard.edu>
**
**  Reference (Fang2009):
**        Qianqian Fang and David A. Boas, "Monte Carlo Simulation of Photon 
**        Migration in 3D Turbid Media Accelerated by Graphics Processing 
**        Units," Optics Express, vol. 17, issue 22, pp. 20178-20190 (2009)
**
**  tictoc.c: timing functions
**
**  License: GNU General Public License v3, see LICENSE.txt for details
**
*******************************************************************************/

#include "tictoc.h"

#ifndef USE_OS_TIMER
#include <cuda.h>
#include <driver_types.h>
#include <cuda_runtime_api.h>
/* use CUDA timer */
static cudaEvent_t timerStart, timerStop;

unsigned int GetTimeMillis () {
  float elapsedTime;
  cudaEventRecord(timerStop,0);
  cudaEventSynchronize(timerStop);
  cudaEventElapsedTime(&elapsedTime, timerStart, timerStop);
  return (unsigned int)(elapsedTime);
}

unsigned int StartTimer () {
  cudaEventCreate(&timerStart);
  cudaEventCreate(&timerStop);

  cudaEventRecord(timerStart,0);
  return 0;
}

#else

static unsigned int timerRes;
#ifndef _WIN32
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
void SetupMillisTimer(void) {}
void CleanupMillisTimer(void) {}
long GetTime (void) {
  struct timeval tv;
  timerRes = 1000;
  gettimeofday(&tv,NULL);
  long temp = tv.tv_usec;
  temp+=tv.tv_sec*1000000;
  return temp;
}
unsigned int GetTimeMillis () {
  return (unsigned int)(GetTime ()/1000);
}
unsigned int StartTimer () {
   return GetTimeMillis();
}

#else
#include <windows.h>
#include <stdio.h>
/*
 * GetTime --
 *
 *      Returns the curent time (from some uninteresting origin) in usecs
 *      based on the performance counters.
 */

int GetTime(void)
{
   static double cycles_per_usec;
   LARGE_INTEGER counter;

   if (cycles_per_usec == 0) {
      static LARGE_INTEGER lFreq;
      if (!QueryPerformanceFrequency(&lFreq)) {
         fprintf(stderr, "Unable to read the performance counter frquency!\n");
         return 0;
      }

      cycles_per_usec = 1000000 / ((double) lFreq.QuadPart);
   }

   if (!QueryPerformanceCounter(&counter)) {
      fprintf(stderr,"Unable to read the performance counter!\n");
      return 0;
   }

   return ((long) (((double) counter.QuadPart) * cycles_per_usec));
}

#pragma comment(lib,"winmm.lib")

unsigned int GetTimeMillis(void) {
  return (unsigned int)timeGetTime();
}

/*
  By default in 2000/XP, the timeGetTime call is set to some resolution
  between 10-15 ms query for the range of value periods and then set timer
  to the lowest possible.  Note: MUST make call to corresponding
  CleanupMillisTimer
*/
void SetupMillisTimer(void) {

  TIMECAPS timeCaps;
  timeGetDevCaps(&timeCaps, sizeof(TIMECAPS)); 

  if (timeBeginPeriod(timeCaps.wPeriodMin) == TIMERR_NOCANDO) {
    fprintf(stderr,"WARNING: Cannot set timer precision.  Not sure what precision we're getting!\n");
  }else {
    timerRes = timeCaps.wPeriodMin;
    fprintf(stderr,"(* Set timer resolution to %d ms. *)\n",timeCaps.wPeriodMin);
  }
}
unsigned int StartTimer () {
   SetupMillisTimer();
   return 0;
}
void CleanupMillisTimer(void) {
  if (timeEndPeriod(timerRes) == TIMERR_NOCANDO) {
    fprintf(stderr,"WARNING: bad return value of call to timeEndPeriod.\n");
  }
}

#endif

#endif
