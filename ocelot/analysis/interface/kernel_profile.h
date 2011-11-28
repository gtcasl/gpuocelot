/**
 * @file kernel_profile.h
 * @author Naila Farooqui, naila@cc.gatech.edu
 * @date 2011-11-15
 * @brief API for kernel profile
 *
 */
 
#ifndef _KERNEL_PROFILE_H
#define _KERNEL_PROFILE_H

#define MSG_QUEUE "/lynx"
#define MQ_MAX_MESSAGES 8 // EVPath is hardcoded to this value.
#define MQ_MAX_MSG_SIZE (sizeof(kernel_profile))
#define MQ_OPEN_OWNER_FLAGS		(O_RDWR | O_CREAT | O_EXCL | O_NONBLOCK)

#define MAX_KERNEL_NAME_SIZE    256 // EVPath is hardcoded to this value.


/*-------------------------------------- DEFINITIONS -------------------------*/

typedef enum { NONE, KERNEL_RUNTIME, MEM_EFFICIENCY, INST_COUNT, EXECUTION_COUNT, BRANCH_DIVERGENCE } profile_type;

typedef struct _kernel_profile {
    
	// Modifying the layout of this data structure (names, types, ordering)
	// requires modification of EVPath descriptors in kidron/dsimons code, file
	// ffs_common.h, structure gpu_monitoring_format_list

    int pid;
    int device;

    profile_type type;
    union {
        double kernel_runtime;
        double memory_efficiency;
        double instruction_count;
        double branch_divergence;
    } data;
    
    char name[MAX_KERNEL_NAME_SIZE]; // don't change macro unless you also want to change EVPath
    
} kernel_profile;

#endif /* _KERNEL_PROFILE_H */


