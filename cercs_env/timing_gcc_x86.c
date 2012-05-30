#include "config.h"
#include "stdlib.h"
#include "cercs_env.h"

#include <sys/time.h>
#include <stdio.h>
#include <string.h>

typedef struct cercs_env_time {
      union rdtsc_union {
	    long long t;
	    struct {
		  int low;
		  int high;
	    } ints;
      } rdtsc_union;
      struct timeval tv;
} *rdtsc_time;

extern void
chr_get_time( chr_time *time)
{
    rdtsc_time t = (rdtsc_time) time;
    gettimeofday(&t->tv, NULL);
    __asm__ __volatile__ ("rdtsc" : "=a" (t->rdtsc_union.ints.low), "=d" (t->rdtsc_union.ints.high));
}

static int
get_resolution()
{
    register int tick1;
    register int tick2;
    int junk;
    __asm__ __volatile__ ("rdtsc" : "=a" (tick1), "=d" (junk));
    __asm__ __volatile__ ("rdtsc" : "=a" (tick2), "=d" (junk));
    return tick2 - tick1;
}

extern void
chr_timer_start( chr_time *time)
{
    chr_get_time(time);
}

extern void
chr_timer_stop( chr_time *time)
{
    struct cercs_env_time now;
    struct cercs_env_time duration;

    chr_get_time((chr_time*)&now);
    chr_timer_diff((chr_time*)&duration, (chr_time*)&now, time);
    *((struct cercs_env_time*) time) = duration;
}

extern int
chr_timer_eq_zero (chr_time *time)
{
    struct rdtsc_time *t = (struct rdtsc_time *) time; 
    return (((rdtsc_time)t)->rdtsc_union.t == 0);
}

extern void
chr_timer_diff( chr_time *diff, chr_time *src1, chr_time *src2)
{
    long long d;
    rdtsc_time s1 = (rdtsc_time)src1;
    rdtsc_time s2 = (rdtsc_time)src2;
    rdtsc_time dd = (rdtsc_time)diff;
    d = s1->rdtsc_union.t - s2->rdtsc_union.t;
    ((rdtsc_time)diff)->rdtsc_union.t = d;
/*    fprintf(stderr, "Timer diff ticks diff is %lld \n", d);
    fprintf(stderr, "S1 sec is %ld, S2 sec is %ld\n", s1->tv.tv_sec, 
	    s2->tv.tv_sec);
    fprintf(stderr, "S1 usec is %ld, S2 usec is %ld\n", s1->tv.tv_usec, 
    s2->tv.tv_usec);*/
    dd->tv.tv_sec = s1->tv.tv_sec - s2->tv.tv_sec;
    dd->tv.tv_usec = s1->tv.tv_usec - s2->tv.tv_usec;
    if (dd->tv.tv_usec < 0) {
       dd->tv.tv_sec--;
       dd->tv.tv_usec += 1000000;
    }
}

extern void
chr_timer_sum( chr_time *sum, chr_time *src1, chr_time *src2)
{
    long long s;
    rdtsc_time s1 = (rdtsc_time)src1;
    rdtsc_time s2 = (rdtsc_time)src2;
    s = s1->rdtsc_union.t + s2->rdtsc_union.t;
    ((rdtsc_time)sum)->rdtsc_union.t = s;
    ((rdtsc_time)sum)->tv.tv_sec = s1->tv.tv_sec + s2->tv.tv_sec;
    ((rdtsc_time)sum)->tv.tv_usec = s1->tv.tv_usec + s2->tv.tv_usec;
    if (((rdtsc_time)sum)->tv.tv_usec >= 1000000) {
	((rdtsc_time)sum)->tv.tv_sec++;
	((rdtsc_time)sum)->tv.tv_usec -= 1000000;
    }
}


static double clock_frequency = 0.0;

static void
frequency_init()
{
    FILE *f;
    char line[128];
    if (clock_frequency == 0.0) {
	clock_frequency = -1.0;
	f = fopen("/proc/cpuinfo", "r");
	if (!f) return;

	while(fgets(line, sizeof(line), f)) {
	    if (strncasecmp(line, "cpu mhz", 7) == 0) {
		char *colon = strchr(line, ':');
		double mhz;
		colon++;
		if (sscanf(colon, "%lf", &mhz) == 1) {
		    clock_frequency = mhz * 1000000.0 ;
		    fclose(f);
		    return;
		}
	    }
	}
	fclose(f);
    }
}

extern double
chr_time_to_secs(chr_time *time)
{
    rdtsc_time t = (rdtsc_time)time;
    double ticks = (double) t->rdtsc_union.t;
    double tick_time, tod_time;
    int use_tod = 0;
    if (clock_frequency == 0.0) {
       frequency_init();
    }
    tick_time = ticks / clock_frequency;
    tod_time = t->tv.tv_sec;
    tod_time += (double)t->tv.tv_usec / 1000000.0;
    use_tod = 0;
    if (tick_time < 0.0) use_tod++;
    if (tod_time > 60.0) use_tod++;
    if (tick_time > 60.0) use_tod++;
    if (use_tod) {
/*       fprintf(stderr, "Using TOD time %g, instead of ticks %g\n", tod_time, tick_time);*/
       return tod_time;
    } else {
/*       fprintf(stderr, "Using tick time %g, instead of TOD %g\n", tick_time, tod_time);*/
       return tick_time;
    }
}

extern double
chr_time_to_millisecs(chr_time *time)
{
    return chr_time_to_secs(time) * 1000.0;
}

extern double
chr_time_to_microsecs(chr_time *time)
{
    return chr_time_to_secs(time) * 1000000.0;
}

extern double
chr_time_to_nanosecs(chr_time *time)
{
    return chr_time_to_secs(time) * 1000000000.0;
}

extern double
chr_approx_resolution()
{
    long long res = get_resolution();
    int i;
    for (i=0; i < 5; i++) {
	if ((res < 0) || (res > 1024)) {
	    res = get_resolution();
	}
    }
    if (clock_frequency == 0.0) {
	frequency_init();
    }
    return chr_time_to_secs((chr_time*)&res);
}
