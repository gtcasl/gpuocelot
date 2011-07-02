#ifdef LINUX_KERNEL_MODULE
#  ifndef __KERNEL__
#    define __KERNEL__
#  endif
#  ifndef MODULE
#    define MODULE
#  endif
#endif

#ifdef ATL_H
#  define MAX_STR 256
#endif

#define printf                printk
#define perror                printk
#define fprintf(fmt, args...) printk (args) 
#define malloc                (void *)atl_DAllocMM
#define free(a)               atl_DFreeMM((addrs_t)a)
#define realloc(a,b)          (void *)atl_DReallocMM((addrs_t)a,b)
#define atoi(p)               strtol(p, (char **)NULL, 10)
#define qsort                 _quicksort
#define getpid()              current->pid
#define signal(a,b)    
#define gethostname           sys_gethostname
#define gethostbyname         lookup_name
#define exit                  atl_sys_exit
#define select                atl_sys_select
#define write                 atl_sys_write
#define thr_mutex_lock(a)
#define thr_mutex_unlock(b)
#define thr_mutex_alloc() NULL
#define gen_thr_initialized() 0
