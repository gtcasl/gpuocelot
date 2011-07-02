/* Required definitions. */
#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include "config.h"

/* Various required header files. */
#include <linux/config.h> 
#include <linux/module.h> 
#include <linux/kernel.h> 
#include <linux/init.h> 
#include <linux/tty.h>
#include <linux/unistd.h>
#include <linux/socket.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <asm/semaphore.h>

#include "katl.h"
#include "kernel/kernel_defs.h"
#include <atl.h>

MODULE_AUTHOR("Eisenhauer/Poellabauer/Ganev");
MODULE_DESCRIPTION("DRISC Module");
MODULE_LICENSE("GPL");

/* Global variables. */
static frec_p * atl_frhead;
static frec_p * atl_frecs;
static frec_p * atl_orhead;
static addrs_t  atl_memptr;
static pid_t atl_dpid;
static DECLARE_MUTEX(katl_sem);
static DECLARE_MUTEX(katl_memory_sem);

/* ceiling function. */
static int atl_ceil(int x)
{
  if ((x % ALIGN) == 0)
	  return (x);
  else
	  return ((x/ALIGN)*ALIGN+ALIGN);
}

/* Memory management. */

addrs_t atl_DKmallocMM (addrs_t atl_memptr, size_t size, int priority) {

  atl_memptr = vmalloc(size);

  atl_frhead = (frec_p *)atl_memptr;
  atl_frecs  = (frec_p *)(atl_memptr + sizeof(frec_p *));
  atl_orhead = (frec_p *)(atl_memptr + 2*sizeof(frec_p *));

  return atl_memptr;
}

void atl_DKfreeMM (addrs_t atl_memptr) {

  vfree(atl_memptr);
}

void atl_DInitMM (addrs_t atl_memptr, size_t size) {
  
  frec_p frp;
  int maxentries;
  unsigned long aligner;

  *atl_frhead = (frec_p) (atl_memptr + size/2);  
  *atl_orhead = NULL;
  
  maxentries = (size/2)/sizeof(struct frec) - 10;

  for (frp = *atl_frhead; frp < *atl_frhead + maxentries; frp++) 
    frp->next = frp + 1;

  (*atl_frhead)->next = NULL;
  (*atl_frhead + maxentries - 1)->next = NULL;
  *atl_frecs = *atl_frhead + 1;
  (*atl_frhead)->fbp = atl_memptr + 3*sizeof(frec_p *) + 1;
  aligner = (unsigned long) ((*atl_frhead)->fbp);
  aligner = aligner%ALIGN;
  (*atl_frhead)->fbp += (ALIGN - aligner);
  (*atl_frhead)->size = size/2 - 3*sizeof(frec_p *) - 1 - (ALIGN - aligner);
}

addrs_t atl_DAllocMM (size_t size) {

  frec_p frp, prev_frp;
  addrs_t frstart;

  prev_frp = frp = *atl_frhead;

  down(&katl_memory_sem);
  while (frp) {
    if (frp->size >= atl_ceil(size)) {

      frstart = frp->fbp;
      frp->fbp += atl_ceil(size);
      frp->size -= atl_ceil(size);

      if (atl_DInsertEntry(frstart, size) == -1) {
        up(&katl_memory_sem);
        return NULL;
      }
      if (frp->size) {
        up(&katl_memory_sem);
	return (frstart);
      }
      
      atl_DDelRecord (prev_frp, frp);
      up(&katl_memory_sem);
      return (frstart);

    }
    prev_frp = frp;
    frp = frp->next;
  }
  up(&katl_memory_sem);
  return (addrs_t)NULL;
}

void atl_DDelRecord (frec_p prev_frp, frec_p frp) {

  if (frp == *atl_frhead)
    *atl_frhead = frp->next;
  else
    prev_frp->next = frp->next;

  frp->next = *atl_frecs;
  *atl_frecs = frp;
}

void atl_DFreeMM (addrs_t addr) {

  size_t size;
  frec_p frp, new_frp, prev_frp = NULL;
 
  down(&katl_memory_sem);
  size = atl_DFindEntry(addr);

  if (size == 0) {
    up(&katl_memory_sem);
    return;
  }
 
  if ((new_frp = *atl_frecs) == NULL) {
    up(&katl_memory_sem);
    return;
  }

  new_frp->fbp = addr;
  new_frp->size = atl_ceil(size);
  *atl_frecs = new_frp->next;
  frp = *atl_frhead;

  if (frp == NULL || addr <= frp->fbp) {
    new_frp->next = frp;
    *atl_frhead = new_frp;
    atl_DMergeRecords (new_frp);
    atl_DRemoveEntry(addr);
    up(&katl_memory_sem);
    return;
  }

  while (frp && addr > frp->fbp) {
    prev_frp = frp;
    frp = frp->next;
  }

  new_frp->next = prev_frp->next;
  prev_frp->next = new_frp;
  atl_DMergeRecords (prev_frp);

  atl_DRemoveEntry(addr);
  up(&katl_memory_sem);
}

int atl_DInsertEntry (addrs_t addr, size_t size) {

  frec_p n_frp;

  if ((n_frp = *atl_frecs) == NULL) {
    return -1;
  }

  n_frp->fbp = addr;
  n_frp->size = atl_ceil(size);
  *atl_frecs = n_frp->next;
  n_frp->next = *atl_orhead;
  *atl_orhead = n_frp;

  return 0;
}

int atl_DFindEntry (addrs_t addr) {

  frec_p frp;

  frp = *atl_orhead;

  while (frp) {
    if (frp->fbp == addr)
      return frp->size;
    frp = frp->next;
  }

  return 0;
}

void atl_DRemoveEntry (addrs_t addr) {

  frec_p frp, prev_frp;
  
  frp = *atl_orhead;
  prev_frp = *atl_orhead;

  while (frp) {
    if (frp->fbp == addr) {
      if (frp == *atl_orhead)
        *atl_orhead = frp->next;
      else
        prev_frp->next = frp->next;

      frp->next = *atl_frecs;
      *atl_frecs = frp;
      return;
    }
    prev_frp = frp;
    frp = frp->next;
  }
}

addrs_t atl_DReallocMM (addrs_t oldmem, size_t bytes) {

  size_t size;
  addrs_t newmem;

  if ((size = atl_DFindEntry(oldmem)) == 0)
    return NULL;

  atl_DFreeMM(oldmem);

  newmem = atl_DAllocMM(bytes);

  if (bytes > size)
    memcpy(newmem, oldmem, size);
  else
    memcpy(newmem, oldmem, bytes);

  return(newmem);
}

void atl_DMergeRecords (frec_p frp) {

  frec_p next_frp;

  if ((next_frp = frp->next) == NULL)
    return;

  if (frp->fbp + frp->size == next_frp->fbp) {
    frp->size += next_frp->size;
    atl_DDelRecord (frp, next_frp);
  }
  else
    frp = next_frp;

  if ((next_frp = frp->next) == NULL)
    return;

  if (frp->fbp + frp->size == next_frp->fbp) {
    frp->size += next_frp->size;
    atl_DDelRecord (frp, next_frp);
  }
}

/*
int sys_gethostname(char *name, int len)
{
  int i, errno;

  if (len < 0)
    return -EINVAL;
  down_read(&uts_sem);
  i = 1 + strlen(system_utsname.nodename);
  if (i > len)
    i = len;
  errno = 0;
  memcpy(name, system_utsname.nodename, i);
  up_read(&uts_sem);
  return errno;
}
*/

/* strdup function */
char * atl_strdup(char *s)
{
  char *p;

  p = (char *)kmalloc(strlen(s)+1, GFP_KERNEL);
  if (p != NULL)
    strcpy(p, s);
  return p;
}

extern void *sys_call_table[];
int (*atl_sys_exit)(int error_code);
ssize_t (*atl_sys_write)(unsigned int, char *, size_t);

/* Initialize module. */
static int __init katl_init(void) 
{
  /* Announce our entry */
  printk(KERN_INFO "ATL: ATtribute List module loading...\n");

  atl_sys_exit  = sys_call_table[__NR_exit];
  atl_sys_write = sys_call_table[__NR_write];

  /* Allocate free pages. */
  atl_memptr = atl_DKmallocMM(atl_memptr, MEM_SIZE, MEM_PRIORITY);

  /* Initialize kernel memory. */
  atl_DInitMM(atl_memptr, MEM_SIZE);


#if 0
  /* Trivial and non-comprehensive functional testing... */
  do {
      attr_list one;
      attr_list two;
      char * string;

      printk(KERN_INFO "ATL: --- Begin Diagnostic Test ---\n");

      printk(KERN_INFO "ATL:\n");
      printk(KERN_INFO "ATL: Test ATL creation\n");

      one = create_attr_list();
      set_attr(one, 2000, Attr_String, "test string");
      set_attr(one, 2001, Attr_Int4, (attr_value)2001);
      dump_attr_list(one);

      
      printk(KERN_INFO "ATL:\n");
      printk(KERN_INFO "ATL: Test ATL stringification\n");

      string = attr_list_to_string(one);
      printk(KERN_INFO "ATL: \"%s\" @ 0x%p\n", string, string);


      printk(KERN_INFO "ATL:\n");
      printk(KERN_INFO "ATL: Test ATL destringification\n");

      two = attr_list_from_string(string);
      dump_attr_list(two);

      
      /* Release it */
      free_attr_list(one);
      printk(KERN_INFO "after 1st free: 0x%p\n", string);
      free_attr_list(two);
      printk(KERN_INFO "after 2nd free: 0x%p\n", string);

      /*
       * Strings get allocated in base64_encode() using malloc() so we
       * need to release their memory with free(). Both in fact get
       * overridden by kernel_defs.h
       */
      free(string);
      printk(KERN_INFO "after 3rd free: 0x%p\n", string);

      printk(KERN_INFO "ATL: --- End Diagnostic Test ---\n");
  } while(0);
#endif

  return 0;
}

/* Remove module. */
static void __exit katl_cleanup(void) 
{
  /* Announce our exit */
  printk(KERN_INFO "ATL: ATtribute List module exiting...\n");

  /* Free memory pages. */
  atl_DKfreeMM(atl_memptr);
}

module_init(katl_init);
module_exit(katl_cleanup); 

