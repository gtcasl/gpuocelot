/*
 * (c) 2010 The Board of Trustees of the University of Illinois.
 */
#ifndef PARBOIL_HEADER
#define PARBOIL_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#include <unistd.h>
#include <driver_types.h>

/* Command line parameters for benchmarks */
struct pb_Parameters {
  char *outFile;		/* If not NULL, the raw output of the
				 * computation should be saved to this
				 * file. The string is owned. */
  char **inpFiles;		/* A NULL-terminated array of strings
				 * holding the input file(s) for the
				 * computation.  The array and strings
				 * are owned. */
	int synchronizeGpu;
};

/* Read command-line parameters.
 *
 * The argc and argv parameters to main are read, and any parameters
 * interpreted by this function are removed from the argument list.
 *
 * A new instance of struct pb_Parameters is returned.
 * If there is an error, then an error message is printed on stderr
 * and NULL is returned.
 */
struct pb_Parameters *
pb_ReadParameters(int *_argc, char **argv);

/* Free an instance of struct pb_Parameters.
 */
void
pb_FreeParameters(struct pb_Parameters *p);

/* Count the number of input files in a pb_Parameters instance.
 */
int
pb_Parameters_CountInputs(struct pb_Parameters *p);

/* A time or duration. */
#if _POSIX_VERSION >= 200112L
typedef unsigned long long pb_Timestamp; /* time in microseconds */
#else
# error "Timestamps not implemented"
#endif

enum pb_TimerState {
  pb_Timer_STOPPED,
  pb_Timer_RUNNING,
};

struct pb_Timer {
  enum pb_TimerState state;
  pb_Timestamp elapsed;		/* Amount of time elapsed so far */
  pb_Timestamp init;		/* Beginning of the current time interval,
				 * if state is RUNNING.  End of the last 
				 * recorded time interfal otherwise.  */
};

/* Reset a timer.
 * Use this to initialize a timer or to clear
 * its elapsed time.  The reset timer is stopped.
 */
void
pb_ResetTimer(struct pb_Timer *timer);

/* Start a timer.  The timer is set to RUNNING mode and
 * time elapsed while the timer is running is added to
 * the timer.
 * The timer should not already be running.
 */
void
pb_StartTimer(struct pb_Timer *timer);

/* Stop a timer.
 * This stops adding elapsed time to the timer.
 * The timer should not already be stopped.
 */
void
pb_StopTimer(struct pb_Timer *timer);

/* Get the elapsed time in seconds. */
double
pb_GetElapsedTime(struct pb_Timer *timer);

/* Execution time is assigned to one of these categories. */
enum pb_TimerID {
  pb_TimerID_NONE = 0,
  pb_TimerID_IO,		/* Time spent in input/output */
  pb_TimerID_GPU,		/* Time spent computing on the GPU, 
				 * recorded asynchronously */
  pb_TimerID_COPY,		/* Time spent synchronously moving data 
				 * to/from GPU and allocating/freeing 
				 * memory on the GPU */
  pb_TimerID_DRIVER,		/* Time spent in the host interacting with the 
				 * driver, primarily for recording the time 
                                 * spent queueing asynchronous operations */
  pb_TimerID_COPY_ASYNC,	/* Time spent in asynchronous transfers */
  pb_TimerID_COMPUTE,		/* Time for all program execution other
				 * than parsing command line arguments,
				 * I/O, GPU, and copy */
  pb_TimerID_OVERLAP,		/* Time double-counted in asynchronous and 
				 * host activity: automatically filled in, 
				 * not intended for direct usage */
  pb_TimerID_LAST		/* Number of timer IDs */
};

/* Dynamic list of asynchronously tracked times between events */
struct pb_async_time_marker_list {
  enum pb_TimerID timerID;	/* The ID to which the interval beginning 
                                 * with this marker should be attributed */
  cudaEvent_t marker; 		/* The driver event for this marker */
  struct pb_async_time_marker_list *next; 
};

/* A set of timers for recording execution times. */
struct pb_TimerSet {
  enum pb_TimerID current;
  struct pb_async_time_marker_list* async_markers;
  pb_Timestamp async_begin;
  struct pb_Timer timers[pb_TimerID_LAST];
};

/* Reset all timers in the set. */
void
pb_InitializeTimerSet(struct pb_TimerSet *timers);

/* Select which timer the next interval of time should be accounted
 * to. The selected timer is started and other timers are stopped.
 * Using pb_TimerID_NONE stops all timers. */
void
pb_SwitchToTimer(struct pb_TimerSet *timers, enum pb_TimerID timer);

/* Print timer values to standard output. */
void
pb_PrintTimerSet(struct pb_TimerSet *timers);

/* Release timer resources */
void
pb_DestroyTimerSet(struct pb_TimerSet * timers);

#ifdef __cplusplus
}
#endif

#endif //PARBOIL_HEADER
