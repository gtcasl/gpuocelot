/*
 *
 *  $Id$
 *
 */


#include "config.h"

#include <stdlib.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>

#ifdef STDC_HEADERS
#include <stdarg.h>
#else
#include <varargs.h>
#endif
#include <errno.h>
#ifndef vfprintf
/* really don't need a decl if there's a macro of that name */
extern int vfprintf();
#endif

#include "cercs_env.h"
#include "bitarray.h"

static short int trace_init = 0;
static size_t trace_count = 0;
static const size_t max_traces = 128;
static bit_array_t* trace_bits;

size_t
cercs_trace_init ()
{
  if (!trace_init) {
    trace_bits = BitArrayCreate ( max_traces );
    BitArrayClearAll ( trace_bits );
    trace_count = 0;
    trace_init++;
  }
  return max_traces;
}

extern void
cercs_trace_reset()
{
  trace_init = 0;
  BitArrayDestroy ( trace_bits );
  cercs_trace_init();
}

extern size_t
cercs_trace_count()
{
  return trace_count;
}

/*
  takes env_var string, returns pos in bitarray
   checks env_var and sets pos if env_var is set
 */
cercs_trace_t
cercs_trace_on (const char* env_var)
{
  if (!trace_init) cercs_trace_init();
  
  if ( getenv ( env_var ) ) {
    BitArraySetBit ( trace_bits, trace_count );
  }
  
  return trace_count++;
}

extern void
cercs_trace_off (const cercs_trace_t trace_var)
{
  if (!trace_init) cercs_trace_init();

  BitArrayClearBit ( trace_bits, trace_var );
}

cercs_trace_t
cercs_trace_group_on ( const char* env_var, const cercs_trace_t group[], 
		       const size_t group_size )
{
  size_t v;

  if (!trace_init) cercs_trace_init();
  
  if ( getenv ( env_var ) ) {
    BitArraySetBit ( trace_bits, trace_count );
    
    for ( v = 0; v < group_size; v++ ) {
      BitArraySetBit ( trace_bits, group[v] );
    }
  }

  return trace_count++;
}
    
  
void
cercs_trace_out (const cercs_trace_t trace_type,  char const *format, ...)
{
    va_list ap;
 
    if ( BitArrayTestBit ( trace_bits, trace_type ) ) {
     
#ifdef STDC_HEADERS
      va_start(ap, format);
#else
      va_start(ap);
#endif
      vfprintf(stdout, format, ap);
      va_end(ap);
      printf("\n");
    }
}

void
cercs_trace_check ( const cercs_trace_t trace, const char* env_var )
{
  if (!trace_init) cercs_trace_init();
  
  if (trace > trace_count) return;

  if ( getenv ( env_var ) ) {
    BitArraySetBit ( trace_bits, trace );
  }

  return;
}  


/*
 *
 *  $Log$
 *
 */
