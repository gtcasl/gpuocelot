#include <sys/types.h>
#if defined(FUNCPROTO) || defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
#ifndef ARGS
#define ARGS(args) args
#endif
#ifndef	NULL
#define NULL	((void *) 0)
#endif
#else
#ifndef ARGS
#define ARGS(args) (/*args*/)
#endif
#ifndef	NULL
#define NULL	0
#endif
#endif
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif

#ifndef FPRINTF_DEFINED
extern int fprintf ARGS((FILE *, const char *, ...));
#endif
#ifndef PERROR_DEFINED
extern void perror ARGS((const char *));
#endif
#ifndef PRINTF_DEFINED
extern int printf ARGS((const char *, ...));
#endif
#ifndef SSCANF_DEFINED
extern int sscanf ARGS((const char *, const char *, ...));
#endif
#ifndef PRINTF_DEFINED
extern int printf ARGS((const char *, ...));
#endif
#ifndef PUTENV_DEFINED
extern int putenv ARGS((const char *));
#endif
extern pid_t getpid();
extern char *getlogin();
