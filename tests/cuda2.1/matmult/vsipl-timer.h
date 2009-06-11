/*!
	\file vsipl-timer.h
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\brief common set of routines, mainly for platform-independent high-resolution
	timing, to be included in C and CUDA programs. Windows users should -DWIN32 for
	files that include this
*/

#ifndef gpuvsip
#define gpuvsip


/* ////////////////////////////////////////////////////////////////////////////
//
// milisecond timer
*/

#ifdef WIN32
#include <windows.h>

typedef LARGE_INTEGER gpuvsip_timer;

/*!

*/
static void gpuvsip_start_timer(gpuvsip_timer *timer) {
	QueryPerformanceCounter(timer);
}

/*!

*/
static void gpuvsip_stop_timer(gpuvsip_timer *timer) {
	LARGE_INTEGER end_time;
	__int64 x;
	QueryPerformanceCounter(&end_time);
	x = (*((__int64 *)&end_time) - *((__int64 *)timer));
	*timer = *((LARGE_INTEGER *)&x);
}

/*!

*/
static double gpuvsip_timer_duration(gpuvsip_timer *timer) {
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	
	return (double)(*((__int64 *)timer)) / (double)(*((__int64 *)&freq));
}

#else

// linux timer

#include <sys/time.h>


typedef struct {
	struct timeval start_time,
		end_time;
} gpuvsip_timer;

static void gpuvsip_start_timer(gpuvsip_timer *timer) {
	gettimeofday(&timer->start_time, 0);
}

static void gpuvsip_stop_timer(gpuvsip_timer *timer) {
	gettimeofday(&timer->end_time, 0);
}

static double gpuvsip_timer_duration(gpuvsip_timer *timer) {
	return ((double)timer->end_time.tv_sec - (double)timer->start_time.tv_sec) +
		((double)timer->end_time.tv_usec - (double)timer->start_time.tv_usec)*1.0e-6;
}

#endif

/*!
	selects the indexed device

static int gpuvsip_selectdevice(int device) {
	cudaDeviceProp prop = {0};
	cudaGetDeviceProperties(&prop, device);
	
	printf(" %i - %s (%i MB)", 
		device, prop.name, (prop.totalGlobalMem >> 20));
	if (cudaSetDevice(device) != cudaSuccess) {
		printf("\n ** failed to set device.\n");
		return 1;
	}
	else {
		printf(" [selected]\n");
		return 0;
	}
}
*/
#endif
