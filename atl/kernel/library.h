/*
 *  library.h
 *
 *  Copyright (C) 1999  Christian Poellabauer
 */

/*
 * library routines... 
 */

#include <linux/slab.h>
#include <linux/string.h>
#include <linux/socket.h>
#include <linux/fs.h>

#ifndef errno
int errno;
#endif

#ifndef __P
#ifdef __STDC__
#define __P(x)  x
#else
#define __P(x)  ()
#endif
#endif

#if (defined __cplusplus || (defined __STDC__ && __STDC__) \
      || defined WINDOWS32)
#define __ptr_t    void *
#if !defined __GNUC__ || __GNUC__ < 2
#define __const const
#endif
#else
#define __const
#define __ptr_t char *
#endif

#ifdef __GNUC__
#define __alloca(size) __builtin_alloca (size)
#define alloca(size)   __alloca (size)
#endif

#ifndef __COMPAR_FN_T
#define __COMPAR_FN_T
typedef int (*__compar_fn_t) __P ((__const __ptr_t, __const __ptr_t));
#endif

struct hostent
{
  char *h_name;
  char **h_aliases;
  int h_addrtype;
  int h_length;
  char **h_addr_list;
  #define h_addr h_addr_list[0]
};

extern void _quicksort __P ((void *const pbase, size_t total_elems,
                             size_t size, __compar_fn_t cmp));

extern char  *getenv(const char *name);
extern int    setenv(const char *name, const char *value, int overwrite);

extern int (*sys_socket)    (int family, int type, int protocol);

extern int (*sys_connect)   (int fd, struct sockaddr *uservaddr, int addrlen);

#if 0
extern struct hostent *lookup_name(const char *name);
#else
#define lookup_name(n)      (NULL)
#endif

extern int socket (int family, int type, int protocol);
extern int setsockopt (int fd, int level, int optname, 
                                  char *optval, int optlen);
extern int accept (int fd, struct sockaddr *upeer_sockaddr,
                                  int *upeer_addrlen); 
extern int connect (int fd, struct sockaddr *uservaddr,
                                  int addrlen); 
extern int listen (int fd, int backlog);
extern int bind (int fd, struct sockaddr *umyaddr, 
                                  int addrlen);
extern int socket (int family, int type, int protocol);
extern int setsockname (int fd, struct sockaddr *usockaddr,
                                   int *usockaddr_len);
extern int getsockname (int fd, struct sockaddr *usockaddr,
                                   int *usockaddr_len);






