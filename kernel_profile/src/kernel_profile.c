/**
 * @file kernel_profile.c
 * @author Naila Farooqui, naila@cc.gatech.edu
 * @date 2011-11-15
 * @brief Kernel Profile Implementation
 */
 
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <kernel_profile.h>

/*-------------------------------------- PUBLIC INTERFACE -------------*/

int update_kernel_profile(kernel_profile profile, int *id)
{
    int err;
    struct shmgrp_region region;

    err = shmgrp_init();
    if (err < 0) {
        fprintf(stderr, "Error: shmgrp_init: %s\n", strerror(-err));
        return -1;
    }
    
    printf("Joining group %s\n", GRPLYNX);
    err = shmgrp_join(GRPLYNX);
    if (err < 0) {
            fprintf(stderr, "Error: shmgrp_join(%s): %s\n",
                            GRPLYNX, strerror(-err));
            return -1;
    }

    printf("Creating new memory region with group %s\n", GRPLYNX);
    err = shmgrp_mkreg(GRPLYNX, 4096, id);
    if (err < 0) {
        fprintf(stderr, "Error: shmgrp_mkreg(%s): %s\n",
                            GRPLYNX, strerror(-err));
            return -1;
    }
    
    printf("Got region %d, let's see where it is mapped\n", *id);
    err = shmgrp_leader_region(GRPLYNX, *id, &region);
    if (err < 0) {
            fprintf(stderr, "Error: shmgrp_leader_region: %s\n",
                            strerror(-(err)));
            return -1;
    }
    
    ((kernel_profile *)region.addr)->type = profile.type;
    if(((kernel_profile *)region.addr)->type == KERNEL_RUNTIME)
        ((kernel_profile *)region.addr)->data.kernel_runtime = profile.data.kernel_runtime;
    
    printf("kernel profile type: %d\n", ((kernel_profile *)region.addr)->type);
    printf("kernel profile data: %lu\n", ((kernel_profile *)region.addr)->data.kernel_runtime);
   
    printf("Removing memory region %d from group %s\n",
                        *id, GRPLYNX);
    err = shmgrp_rmreg(GRPLYNX, *id);
    if (err < 0) {
            fprintf(stderr, "Error: shmgrp_rmreg(%s): %s\n",
                            GRPLYNX, strerror(-err));
            return -1;
    }

    printf("Leaving group %s\n", GRPLYNX);
    err = shmgrp_leave(GRPLYNX);
    if (err < 0) {
            fprintf(stderr, "Error: shmgrp_leave(%s): %s\n",
                            GRPLYNX, strerror(-err));
            return -1;
    }
    err = shmgrp_tini();
    if (err < 0) {
            fprintf(stderr, "Error: shmgrp_tini: %s\n", strerror(-err));
            return -1;
    }


    return 0;
}


