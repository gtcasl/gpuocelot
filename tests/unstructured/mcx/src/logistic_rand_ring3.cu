/*********************************************************************
*A Random Number Generator based on coupled chaotic Logistic lattice *
*                                                                    *
*  (both double and single precision random numbers are supported)   *
*                                                                    *
*  Author: Qianqian Fang <fangq at nmr.mgh.harvard.edu>              *
*                                                                    *
*  History: 2009/03/02  CUDA version based on Neal Wagner1 1993      *
*         http://www.cs.utsa.edu/~wagner/pubs/logistic/logistic.pdf  *
*                                                                    *
*********************************************************************/

#ifndef _MCEXTREME_LOGISTIC_RAND_H
#define _MCEXTREME_LOGISTIC_RAND_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RAND_BUF_LEN 3     /*use 5 or 7 will be better*/
#define R_PI 0.318309886183791f
#define INIT_LOGISTIC 100
#define R_MAX_C_RAND (1./RAND_MAX)

#ifndef DOUBLE_PREC_LOGISTIC
  typedef float RandType;
  #define FUN(x)               (4.f*(x)*(1.f-(x)))
  #define NU 1e-8f
  #define NU2 (1.f-2.f*NU)
  #define MIN_INVERSE_LIMIT 1e-7f
  #define logistic_uniform(v)  (acosf(1.f-2.f*(v))*R_PI)
#else
  typedef double RandType;
  #define FUN(x)               (4.0*(x)*(1.0-(x)))
  #define NU 1e-14
  #define NU2 (1.0-2.0*NU)
  #define MIN_INVERSE_LIMIT 1e-12
  #define logistic_uniform(v)  (acos(1.0-2.0*(v))*R_PI)
#endif

#define RING_FUN(x,y,z)      (NU2*(x)+NU*((y)+(z)))


__device__ void logistic_step(RandType *t, RandType *tnew, int len_1){
/*
    int i;
    for(i=0;i<=len_1;i++)
       t[i]=FUN(t[i]);
    tnew[0]=RING_FUN(t[0],t[1],t[len_1]);
    for(i=1;i<len_1;i++)
       tnew[i]=RING_FUN(t[i],t[i-1],t[i+1]);
    tnew[len_1]=RING_FUN(t[len_1],t[0],t[len_1-1]);
*/
    RandType tmp;
    t[0]=FUN(t[0]);
    t[1]=FUN(t[1]);
    t[2]=FUN(t[2]);
    tnew[2]=RING_FUN(t[0],t[2],t[1]);
    tnew[0]=RING_FUN(t[1],t[0],t[2]);
    tnew[1]=RING_FUN(t[2],t[1],t[0]);
    tmp=t[0];
    t[0]=t[1];
    t[1]=t[2];
    t[2]=tmp;
}

__device__ void logistic_rand(RandType *t,RandType *tnew,int len_1){
    logistic_step(t,tnew,len_1);
    logistic_step(tnew,t,len_1);
}

//__device__ RandType logistic_uniform(RandType v){
//    return acosf(1.0-2.0*v)*R_PI;
//}

__device__ void logistic_init(RandType *t,RandType *tnew,uint seed[],uint idx){
     int i;
     for(i=0;i<RAND_BUF_LEN;i++)
           t[i]=(RandType)seed[idx*RAND_BUF_LEN+i]*R_MAX_C_RAND;

     for(i=0;i<INIT_LOGISTIC;i++)  /*initial randomization*/
           logistic_rand(t,tnew,RAND_BUF_LEN-1);
}

#endif
