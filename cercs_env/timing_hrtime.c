#include "config.h"
#include "cercs_env.h"

#include <sys/time.h>

extern void
chr_get_time( chr_time *time)
{
    *((hrtime_t*)time) = gethrtime();
}

extern void
chr_timer_start( chr_time *time)
{
    chr_get_time(time);
}

extern void
chr_timer_stop( chr_time *time)
{
    hrtime_t now = gethrtime();
    hrtime_t duration;
    if (*((hrtime_t*)time) == 0) {
	printf("Warning, timer not started  -- chr_timer_stop()\n");
    }
    chr_timer_diff((chr_time*)&duration, (chr_time*)&now, time);
    *((hrtime_t*) time) = duration;
}

extern int
chr_timer_eq_zero (chr_time *time)
{
    return (*((hrtime_t*)time) == 0);
}

extern void
chr_timer_diff( chr_time *diff, chr_time *src1, chr_time *src2)
{
    *((hrtime_t*)diff) = *((hrtime_t*)src1) - *((hrtime_t*)src2);
}

extern void
chr_timer_sum( chr_time *sum, chr_time *src1, chr_time *src2)
{
    *((hrtime_t*)sum) = *((hrtime_t*)src1) + *((hrtime_t*)src2);
}


extern double
chr_time_to_secs(chr_time *time)
{
  return ((double) *((hrtime_t*)time)) / 1000000000.0;
}

extern double
chr_time_to_millisecs(chr_time *time)
{
  return ((double) *((hrtime_t*)time)) / 1000000.0;
}

extern double
chr_time_to_microsecs(chr_time *time)
{
  return ((double) *((hrtime_t*)time)) / 1000.0;
}

extern double
chr_time_to_nanosecs(chr_time *time)
{
  return ((double) *((hrtime_t*)time));
}

extern double
chr_approx_resolution()
{
    hrtime_t start, stop, diff;
    start = gethrtime();
    stop = gethrtime();
    diff = stop - start;
    return chr_time_to_secs((chr_time*)&diff);
}
