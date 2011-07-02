#ifndef CERCS_ENV_H
#define CERCS_ENV_H

#include <stddef.h>

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif
  
  extern char *cercs_getenv(char *name);
  extern int cercs_putenv(char *name_value);
  
  typedef struct chr_time {
    double d1;
    double d2;
    double d3;
  } chr_time;
  
  extern void
  chr_get_time( chr_time *time);
  
  extern void
  chr_timer_diff( chr_time *diff_time, chr_time *src1, chr_time *src2);
  
  extern int
  chr_timer_eq_zero( chr_time *time);
  
  extern void
  chr_timer_sum( chr_time *sum_time, chr_time *src1, chr_time *src2);
  
  extern void
  chr_timer_start (chr_time *timer);
  
  extern void
  chr_timer_stop (chr_time *timer);
  
  extern double
  chr_time_to_nanosecs (chr_time *time);
  
  extern double
  chr_time_to_microsecs (chr_time *time);
  
  extern double
  chr_time_to_millisecs (chr_time *time);
  
  extern double
  chr_time_to_secs (chr_time *time);
  
  extern double 
  chr_approx_resolution();
  
  typedef size_t cercs_trace_t;

  extern size_t
  cercs_trace_init();
 
  extern void
  cercs_trace_reset();

  extern size_t
  cercs_trace_count();
  
  extern cercs_trace_t
  cercs_trace_on ( const char* env_var );
  
  extern void
  cercs_trace_off ( const cercs_trace_t trace );
  
  extern cercs_trace_t
  cercs_trace_group_on ( const char* env_var, const cercs_trace_t group[],
			 const size_t group_size );
  
  extern void 
  cercs_trace_out ( const cercs_trace_t trace, char const *format, ...);
  
  extern void
  cercs_trace_check ( const cercs_trace_t trace, const char* env_var );
  
#if defined(__cplusplus) || defined(c_plusplus)
}
#endif
#endif
