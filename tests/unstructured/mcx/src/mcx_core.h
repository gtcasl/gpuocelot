#ifndef _MCEXTREME_GPU_LAUNCH_H
#define _MCEXTREME_GPU_LAUNCH_H

#include "mcx_utils.h"

#ifdef  __cplusplus
extern "C" {
#endif


#define ABS(a)  ((a)<0?-(a):(a))
#define DETINC	32

#ifdef __DEVICE_EMULATION__
#define GPUDEBUG(x)        printf x             // enable debugging in CPU mode
#else
#define GPUDEBUG(x)
#endif

typedef float4 MCXpos;

typedef struct MCXDir{
        float x; /*directional vector of the photon, unit-less*/
	float y;
	float z;
        float nscat; /*total number of scattering events*/
}MCXdir;

typedef struct MCXTimer{
        float pscat; /*remaining scattering probability, unit-less*/
        float t;     /*photon elapse time, unit=s*/
	float tnext; /*time for the next accumulation,unit=s*/
	float ndone; /*number of completed photons*/
}MCXtime;

typedef union GPosition{
	MCXpos d;
	float4 v;
}Gpos;

typedef union GDirection{
        MCXdir d;
        float4 v;
}Gdir;

typedef union GLength{
        MCXtime d;
        float4 v;
}Glen;

typedef union GProperty{
        Medium d; /*defined in mcx_utils.h*/
        float4 v;
}Gprop;

typedef unsigned char uchar;

typedef struct  __align__(16) KernelParams {
  float3 vsize;
  float  minstep;
  float  twin0,twin1,tmax;
  float  oneoverc0;
  unsigned int isrowmajor,save2pt,doreflect,dorefint,savedet;
  float  Rtstep;
  float4 ps,c0;
  float3 maxidx;
  uint3  dimlen,cp0,cp1;
  uint2  cachebox;
  float  minenergy;
  float  skipradius2;
  float  minaccumtime;
  unsigned int maxdetphoton;
  unsigned int maxmedia;
  unsigned int detnum;
  unsigned int idx1dorig;
  unsigned int mediaidorig;
}MCXParam;

void mcx_run_simulation(Config *cfg);
int  mcx_set_gpu(Config *cfg);

#ifdef  __cplusplus
}
#endif

#endif
