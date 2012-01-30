/*
 * (c) 2007 The Board of Trustees of the University of Illinois.
 */

#include <parboil.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef __MCUDA__
#include <cuda_runtime_api.h>
#else
#include <mcuda.h>
#endif

#if _POSIX_VERSION >= 200112L
# include <sys/time.h>
#endif

/* Free an array of owned strings. */
static void
free_string_array(char **string_array)
{
  char **p;

  if (!string_array) return;
  for (p = string_array; *p; p++) free(*p);
  free(string_array);
}

/* Parse a comma-delimited list of strings into an
 * array of strings. */
static char ** 
read_string_array(char *in)
{
  char **ret;
  int i;
  int count;			/* Number of items in the input */
  char *substring;		/* Current substring within 'in' */

  /* Count the number of items in the string */
  count = 1;
  for (i = 0; in[i]; i++) if (in[i] == ',') count++;

  /* Allocate storage */
  ret = (char **)malloc((count + 1) * sizeof(char *));

  /* Create copies of the strings from the list */
  substring = in;
  for (i = 0; i < count; i++) {
    char *substring_end;
    int substring_length;

    /* Find length of substring */
    for (substring_end = substring;
	 (*substring_end != ',') && (*substring_end != 0);
	 substring_end++);

    substring_length = substring_end - substring;

    /* Allocate memory and copy the substring */
    ret[i] = (char *)malloc(substring_length + 1);
    memcpy(ret[i], substring, substring_length);
    ret[i][substring_length] = 0;

    /* go to next substring */
    substring = substring_end + 1;
  }
  ret[i] = NULL;		/* Write the sentinel value */

  return ret;
}

struct argparse {
  int argc;			/* Number of arguments.  Mutable. */
  char **argv;			/* Argument values.  Immutable. */

  int argn;			/* Current argument number. */
  char **argv_get;		/* Argument value being read. */
  char **argv_put;		/* Argument value being written.
				 * argv_put <= argv_get. */
};

static void
initialize_argparse(struct argparse *ap, int argc, char **argv)
{
  ap->argc = argc;
  ap->argn = 0;
  ap->argv_get = ap->argv_put = ap->argv = argv;
}

static void
finalize_argparse(struct argparse *ap)
{
  /* Move the remaining arguments */
  for(; ap->argn < ap->argc; ap->argn++)
    *ap->argv_put++ = *ap->argv_get++;
}

/* Delete the current argument. */
static void
delete_argument(struct argparse *ap)
{
  if (ap->argn >= ap->argc) {
    fprintf(stderr, "delete_argument\n");
  }
  ap->argc--;
  ap->argv_get++;
}

/* Go to the next argument.  Also, move the current argument to its
 * final location in argv. */
static void
next_argument(struct argparse *ap)
{
  if (ap->argn >= ap->argc) {
    fprintf(stderr, "next_argument\n");
  }
  /* Move argument to its new location. */
  *ap->argv_put++ = *ap->argv_get++;
  ap->argn++;
}

static int
is_end_of_arguments(struct argparse *ap)
{
  return ap->argn == ap->argc;
}

static char *
get_argument(struct argparse *ap)
{
  return *ap->argv_get;
}

static char *
consume_argument(struct argparse *ap)
{
  char *ret = get_argument(ap);
  delete_argument(ap);
  return ret;
}

struct pb_Parameters *
pb_ReadParameters(int *_argc, char **argv)
{
  char *err_message;
  struct argparse ap;
  struct pb_Parameters *ret =
    (struct pb_Parameters *)malloc(sizeof(struct pb_Parameters));

  /* Initialize the parameters structure */
  ret->outFile = NULL;
  ret->inpFiles = (char **)malloc(sizeof(char *));
  ret->inpFiles[0] = NULL;

  /* Each argument */
  initialize_argparse(&ap, *_argc, argv);
  while(!is_end_of_arguments(&ap)) {
    char *arg = get_argument(&ap);

    /* Single-character flag */
    if ((arg[0] == '-') && (arg[1] != 0) && (arg[2] == 0)) {
      delete_argument(&ap);	/* This argument is consumed here */

      switch(arg[1]) {
      case 'o':			/* Output file name */
	if (is_end_of_arguments(&ap))
	  {
	    err_message = "Expecting file name after '-o'\n";
	    goto error;
	  }
	free(ret->outFile);
	ret->outFile = strdup(consume_argument(&ap));
	break;
      case 'i':			/* Input file name */
	if (is_end_of_arguments(&ap))
	  {
	    err_message = "Expecting file name after '-i'\n";
	    goto error;
	  }
	ret->inpFiles = read_string_array(consume_argument(&ap));
	break;
      case '-':			/* End of options */
	goto end_of_options;
      default:
	err_message = "Unexpected command-line parameter\n";
	goto error;
      }
    }
    else {
      /* Other parameters are ignored */
      next_argument(&ap);
    }
  } /* end for each argument */

 end_of_options:
  *_argc = ap.argc;		/* Save the modified argc value */
  finalize_argparse(&ap);

  return ret;

 error:
  fputs(err_message, stderr);
  pb_FreeParameters(ret);
  return NULL;
}

void
pb_FreeParameters(struct pb_Parameters *p)
{
  char **cpp;

  free(p->outFile);
  free_string_array(p->inpFiles);
  free(p);
}

int
pb_Parameters_CountInputs(struct pb_Parameters *p)
{
  int n;

  for (n = 0; p->inpFiles[n]; n++);
  return n;
}

/*****************************************************************************/
/* Timer routines */

static int is_async(enum pb_TimerID timer)
{
  return (timer == pb_TimerID_GPU) || 
             (timer == pb_TimerID_COPY_ASYNC);
}

static int is_blocking(enum pb_TimerID timer)
{
  return (timer == pb_TimerID_COPY) || (timer == pb_TimerID_NONE);
}

#define INVALID_TIMERID pb_TimerID_LAST

static int asyncs_outstanding(struct pb_TimerSet* timers)
{
  return (timers->async_markers != NULL) && 
           (timers->async_markers->timerID != INVALID_TIMERID);
}

static struct pb_async_time_marker_list * 
get_last_async(struct pb_TimerSet* timers)
{
  /* Find the last event recorded thus far */
  struct pb_async_time_marker_list * last_event = timers->async_markers;
  if(last_event != NULL && last_event->timerID != INVALID_TIMERID) {
    while(last_event->next != NULL && 
            last_event->next->timerID != INVALID_TIMERID)
      last_event = last_event->next;
    return last_event;
  } else
    return NULL;
} 

static void insert_marker(struct pb_TimerSet* tset, enum pb_TimerID timer)
{
  struct pb_async_time_marker_list ** new_event = &(tset->async_markers);

  while(*new_event != NULL && (*new_event)->timerID != INVALID_TIMERID)
    new_event = &((*new_event)->next);

  if(*new_event == NULL) {
    *new_event = (struct pb_async_time_marker_list *) 
      			malloc(sizeof(struct pb_async_time_marker_list));
    cudaEventCreate(&((*new_event)->marker));
    (*new_event)->next = NULL;
  }

  /* valid event handle now aquired: insert the event record */
  (*new_event)->timerID = timer;
  cudaEventRecord((*new_event)->marker, 0);
}

/* Assumes that all recorded events have completed */
static pb_Timestamp record_async_times(struct pb_TimerSet* tset)
{
  struct pb_async_time_marker_list * next_interval = NULL;
  struct pb_async_time_marker_list * last_marker = get_last_async(tset);
  pb_Timestamp total_async_time = 0;
  enum pb_TimerID timer;
  for(next_interval = tset->async_markers; next_interval != last_marker; 
      next_interval = next_interval->next) {
    float interval_time_ms;
    cudaEventElapsedTime(&interval_time_ms, next_interval->marker, 
                                         next_interval->next->marker);
    pb_Timestamp interval = (pb_Timestamp) (interval_time_ms * 1e3);
    tset->timers[next_interval->timerID].elapsed += interval;
    total_async_time += interval;
    next_interval->timerID = INVALID_TIMERID;
  }

  if(next_interval != NULL)
    next_interval->timerID = INVALID_TIMERID;
  
  return total_async_time;
}

static void
accumulate_time(pb_Timestamp *accum,
		pb_Timestamp start,
		pb_Timestamp end)
{
#if _POSIX_VERSION >= 200112L
  *accum += end - start;
#else
# error "Timestamps not implemented for this system"
#endif
}

#if _POSIX_VERSION >= 200112L
static pb_Timestamp get_time()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (pb_Timestamp) (tv.tv_sec * 1000000LL + tv.tv_usec);
}
#else
# error "no supported time libraries are available on this platform
#endif

void
pb_ResetTimer(struct pb_Timer *timer)
{
  timer->state = pb_Timer_STOPPED;

#if _POSIX_VERSION >= 200112L
  timer->elapsed = 0;
#else
# error "pb_ResetTimer: not implemented for this system"
#endif
}

void
pb_StartTimer(struct pb_Timer *timer)
{
  if (timer->state != pb_Timer_STOPPED) {
    fputs("Ignoring attempt to start a running timer\n", stderr);
    return;
  }

  timer->state = pb_Timer_RUNNING;

#if _POSIX_VERSION >= 200112L
  {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    timer->init = tv.tv_sec * 1000000LL + tv.tv_usec;
  }
#else
# error "pb_StartTimer: not implemented for this system"
#endif
}

void
pb_StopTimer(struct pb_Timer *timer)
{
  pb_Timestamp fini;

  if (timer->state != pb_Timer_RUNNING) {
    fputs("Ignoring attempt to stop a stopped timer\n", stderr);
    return;
  }

  timer->state = pb_Timer_STOPPED;

#if _POSIX_VERSION >= 200112L
  {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    fini = tv.tv_sec * 1000000LL + tv.tv_usec;
  }
#else
# error "pb_StopTimer: not implemented for this system"
#endif

  accumulate_time(&timer->elapsed, timer->init, fini);
  timer->init = fini;
}

/* Get the elapsed time in seconds. */
double
pb_GetElapsedTime(struct pb_Timer *timer)
{
  double ret;

  if (timer->state != pb_Timer_STOPPED) {
    fputs("Elapsed time from a running timer is inaccurate\n", stderr);
  }

#if _POSIX_VERSION >= 200112L
  ret = timer->elapsed / 1e6;
#else
# error "pb_GetElapsedTime: not implemented for this system"
#endif
  return ret;
}

void
pb_InitializeTimerSet(struct pb_TimerSet *timers)
{
  int n;

  timers->current = pb_TimerID_NONE;

  timers->async_markers = NULL;

  for (n = 0; n < pb_TimerID_LAST; n++)
    pb_ResetTimer(&timers->timers[n]);
}

void
pb_SwitchToTimer(struct pb_TimerSet *timers, enum pb_TimerID timer)
{
  /* Stop the currently running timer */
  if (timers->current != pb_TimerID_NONE) {
    if (!is_async(timers->current) ) {
      pb_StopTimer(&timers->timers[timers->current]);
    } else {
      /* Record the end of the previous asynchronous interval */
      insert_marker(timers, timer);
      pb_StopTimer(&timers->timers[pb_TimerID_DRIVER]);
    }
  }
  pb_Timestamp currentTime = get_time();

  /* The only cases we check for asynchronous task completion is 
   * when an overlapping CPU operation completes, or the next 
   * segment blocks on completion of previous async operations */
  if( asyncs_outstanding(timers) && 
      (!is_async(timers->current) || is_blocking(timer) ) ) {

    struct pb_async_time_marker_list * last_event = get_last_async(timers);
    /* cudaSuccess if completed */
    cudaError_t async_done = cudaEventQuery(last_event->marker);

    if(is_blocking(timer)) {
      /* Async operations completed after previous CPU operations: 
       * overlapped time is the total CPU time since this set of async 
       * operations were first issued */
      if(async_done != cudaSuccess) 
        accumulate_time(&(timers->timers[pb_TimerID_OVERLAP].elapsed), 
	                  timers->async_begin,currentTime);

      /* Wait on async operation completion */
      cudaEventSynchronize(last_event->marker);
      pb_Timestamp total_async_time = record_async_times(timers);

      /* Async operations completed before previous CPU operations: 
       * overlapped time is the total async time */
      if(async_done == cudaSuccess)
        timers->timers[pb_TimerID_OVERLAP].elapsed += total_async_time;

    } else 
    /* implies (!is_async(timers->current) && asyncs_outstanding(timers)) */
    if(async_done == cudaSuccess) {
      /* Async operations completed before previous CPU operations: 
       * overlapped time is the total async time */
      timers->timers[pb_TimerID_OVERLAP].elapsed += record_async_times(timers);
    }   
  }

  /* Start the new timer */
  if (timer != pb_TimerID_NONE) {
    if(!is_async(timer)) {
      pb_StartTimer(&timers->timers[timer]);
    } else {
      if (!asyncs_outstanding(timers)) {
        /* No asyncs outstanding, insert a fresh async marker */
        insert_marker(timers, timer);
        timers->async_begin = currentTime;
      } else if(!is_async(timers->current)) {
        /* Previous asyncs still in flight, but a previous SwitchTo
         * already marked the end of the most recent async operation, 
         * so we can rename that marker as the beginning of this async 
         * operation */
        struct pb_async_time_marker_list * last_event = get_last_async(timers);
        last_event->timerID = timer;
      }
      pb_StartTimer(&timers->timers[pb_TimerID_DRIVER]);
    }
  }
  timers->current = timer;
}

void
pb_PrintTimerSet(struct pb_TimerSet *timers)
{
  struct pb_Timer *t = timers->timers;
  /* Presumably every application will have an I/O component */
  printf("IO:      %f\n", pb_GetElapsedTime(&t[pb_TimerID_IO]));
  if(pb_GetElapsedTime(&t[pb_TimerID_GPU]) != 0)
    printf("GPU:     %f\n", pb_GetElapsedTime(&t[pb_TimerID_GPU]));
  if(pb_GetElapsedTime(&t[pb_TimerID_COPY]) != 0)
    printf("Copy:    %f\n", pb_GetElapsedTime(&t[pb_TimerID_COPY]));
  if(pb_GetElapsedTime(&t[pb_TimerID_DRIVER]) != 0)
    printf("Driver:  %f\n", pb_GetElapsedTime(&t[pb_TimerID_DRIVER]));
  /* Presumably every application will have a CPU compute component */
  printf("Compute: %f\n", pb_GetElapsedTime(&t[pb_TimerID_COMPUTE]));
  if(pb_GetElapsedTime(&t[pb_TimerID_OVERLAP]) != 0)
    printf("CPU/GPU Overlap: %f\n", pb_GetElapsedTime(&t[pb_TimerID_OVERLAP]));
}

void pb_DestroyTimerSet(struct pb_TimerSet * timers)
{
  /* clean up all of the async event markers */
  struct pb_async_time_marker_list ** event = &(timers->async_markers);
  while( *event != NULL) {
    cudaEventSynchronize((*event)->marker);
    cudaEventDestroy((*event)->marker);
    struct pb_async_time_marker_list ** next = &((*event)->next);
    free(*event);
    (*event) = NULL;
    event = next;
  }
}


