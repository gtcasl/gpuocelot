/**
 * @file kernel_profile.h
 * @author Naila Farooqui, naila@cc.gatech.edu
 * @date 2011-11-15
 * @brief API for kernel profile
 *
 */
 
#ifndef _KERNEL_PROFILE_H
#define _KERNEL_PROFILE_H

#include <shmgrp.h>

#define GRPLYNX "lynx"


/*-------------------------------------- DEFINITIONS -------------------------*/

typedef enum { NONE, KERNEL_RUNTIME, MEM_EFFICIENCY, INST_COUNT, BRANCH_DIVERGENCE } profile_type;

struct profile_cfg {
    profile_type type;
};

typedef struct _kernel_profile {
    profile_type type;
    union {
        unsigned long kernel_runtime;
        unsigned long memory_efficiency;
        unsigned long instruction_count;
        unsigned long branch_divergence;
    } data;
} kernel_profile;

/*-------------------------------------- PUBLIC INTERFACE --------------------*/

/**
 * Update kernel profile data in shared memory region
 *
 */
int update_kernel_profile(kernel_profile profile, int *id);

/**
 * Retrieve kernel profile
 *
 */
//kernel_profile get_kernel_profile(int id);

#endif /* _KERNEL_PROFILE_H */
