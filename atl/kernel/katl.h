/* Required definitions. */
#ifndef MODULE
#define MODULE
#endif
#ifndef __KERNEL__
#define __KERNEL__
#endif

#define katl_h 1

/* Various required header files. */
#include <linux/config.h>
#include <linux/kernel.h>
#include <linux/kbd_ll.h>
#include <linux/types.h> 
#include <linux/utsname.h>
#include <linux/unistd.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <asm/segment.h> 
#include <asm/signal.h> 

#define MEM_SIZE (unsigned) (1<<21)
#define MEM_PRIORITY GFP_KERNEL
#define ALIGN 8

extern struct semaphore katl_sem;

extern char * atl_getenv(const char *name);

extern int    (* atl_sys_exit)(int error_code);
extern ssize_t (* atl_sys_write)(unsigned int, char *, size_t);

/* Stdlib functions */
extern char * atl_strdup(char *);
extern int    atl_strtol(char *, char **, int);

typedef struct frec *frec_p;
typedef char *addrs_t;
typedef void *any_t;
typedef void *thr_mutex_t;

typedef struct frec {
  addrs_t fbp;			/* Free block pointer. */
  size_t size;
  frec_p next;
} frec_t;			/* Free record type. */

/* Global variables. */
extern frec_p * atl_frhead;
extern frec_p * atl_frecs;
extern frec_p * atl_orhead;
extern addrs_t atl_p_memptr;

/* Prototypes. */
extern addrs_t atl_DKmallocMM (addrs_t p_memptr, size_t size, int priority);
extern addrs_t atl_DAllocMM (size_t size);
extern void    atl_DKfreeMM (addrs_t p_memptr);
extern void    atl_DMergeRecords (frec_p frp);
extern void    atl_DDelRecord (frec_p prev_frp, frec_p frp);
extern void    atl_DInitMM (addrs_t p_memptr, size_t size);
extern addrs_t atl_DReallocMM (addrs_t oldmem, size_t bytes);
extern int     atl_DInsertEntry (addrs_t addr, size_t size);
extern int     atl_DFindEntry (addrs_t addr);
extern void    atl_DRemoveEntry (addrs_t addr);
extern void    atl_DFreeMM (addrs_t addr);
