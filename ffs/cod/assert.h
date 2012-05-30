/*
** Cthreads version of assert.h.  Using gcc version of assert.h *requires*
** the final program to be linked with GNU libc.a.  This is an unacceptable
** restriction (or at least the cause of much confusion in the use of this 
** library.  By using this version of assert.h we avoid much pain.
*/
#undef assert
#undef __assert

#ifdef NDEBUG
#define assert(ignore) ((void) 0)
#else

#define assert(expression)  \
  ((void) ((expression) ? 0 : __assert (expression, __FILE__, __LINE__)))

#ifdef LINUX_KERNEL_MODULE
#define ABORT
#else
#if !defined(_MSC_VER)
extern void abort(void);
#endif
#define ABORT abort(),
#endif
#define __assert(expression, file, lineno)  \
  (printf ("%s:%u: failed assertion\n", file, lineno),	\
   ABORT 0)

#endif
