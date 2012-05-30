#if defined(FUNCPROTO) || defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
#ifndef ARGS
#define ARGS(args) args
#endif
#else
#ifndef ARGS
#define ARGS(args) (/*args*/)
#endif
#endif

#include <stdio.h>
#include "config.h"

static char *DILL_version = "DILL Version 1.0.115 rev. 9803  -- 2011-03-22 13:57:23 -0400 (Tue, 22 Mar 2011)\n";

void DILLprint_version(){
    printf("%s",DILL_version);
}

