/////////////////////////////////////////////////////////////////////
//
//  Monte-Carlo Extreme (MCX) - a GPU accelerated Monte-Carlo Simulation
//  Random Number Generator Benchmark
//
//  Author: Qianqian Fang <fangq at nmr.mgh.harvard.edu>
//  History: 
//     2009/04/16 test for the speed of the two RNG in MCX
//
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "br2cu.h"

#define USE_OS_TIMER  /* use MT19937 RNG */
#include "tictoc.c"

#define RAND_TEST_LEN 5

#ifdef USE_MT_RAND  /* use MT19937 RNG */

//===================================================================
// GPU kernels for MT19937
//===================================================================

#include "mt_rand_s.cu"

kernel void bench_rng(uint seed[],float output[],int loop){
     int idx= blockDim.x * blockIdx.x + threadIdx.x;
     int base=idx*loop;
     uint ran;
     float res;
     int i;

     mt19937si(seed,idx);
     for(i=0;i<loop;i++){
          ran=mt19937s();
	  res=ran*R_MAX_MT_RAND;
#ifdef GLOBAL_WRITE
	  output[base+i]=res;
    #ifdef __DEVICE_EMULATION__
          printf("%d = %d %f\n",i,base+i,output[base+i]);
    #endif
#endif
     }
#ifndef GLOBAL_WRITE  /*to prevent the compiler from optimizing the rand*/
     output[base]=  res;
#endif     
}

#else   /* use Logistic-map lattice RNG */

//===================================================================
// GPU kernels for Logistic-map lattice LL3 and LL5
//===================================================================
//#include "logistic_rand_ring3.cu" // for LL3 RNG

#include "logistic_rand.cu"

kernel void bench_rng(uint seed[],float output[],int loop){
     int idx= blockDim.x * blockIdx.x + threadIdx.x;
     int base=idx*loop;
     int i;
     float c=0.f;
     
     RandType t[RAND_TEST_LEN],tnew[RAND_TEST_LEN];
     RandType ran[RAND_TEST_LEN];
     logistic_init(t,tnew,seed,idx);

     for(i=0;i<loop;i+=5){
          logistic_step(t,tnew,RAND_TEST_LEN-1); /*create 3 random numbers*/
	  ran[0]=logistic_uniform(t[0]);
	  ran[1]=logistic_uniform(t[1]);
	  ran[2]=logistic_uniform(t[2]);
	  ran[3]=logistic_uniform(t[3]);
	  ran[4]=logistic_uniform(t[4]);
	  c+=ran[0];
#ifdef GLOBAL_WRITE
	  output[base+i]=  ran[0];
	  output[base+i+1]=ran[1];
	  output[base+i+2]=ran[2];
	  output[base+i+3]=ran[3];
	  output[base+i+4]=ran[4];
    #ifdef __DEVICE_EMULATION__
          printf("%d = %d %f %f %f\n",i,base+i,ran[0],ran[1],ran[2]);
    #endif
#endif
     }
#ifndef GLOBAL_WRITE  /*to prevent the compiler from optimizing the rand*/
     output[base+i]=  c;
#endif
}

#endif

//===================================================================
// utility functions
//===================================================================

void usage(char *exename){
	printf("usage: %s <num_block|128> <num_thread|128> <rand_per_thread|10000> <num_repeat|10>\n",exename);
}

void mcx_savedata(float *dat,int len,char *name){
     FILE *fp;
     fp=fopen(name,"wb");
     fwrite(dat,sizeof(float),len,fp);
     fclose(fp);
}

//===================================================================
// main program
//===================================================================

int main(int argc, char *argv[]){
    dim3 griddim=128, blockdim=128;
    int count=999,repeat=10, threadnum,tic,tic2,toc;
    uint   *Pseed;
    uint   *gPseed;
    float  *Poutput;
    float  *gPoutput;
    double totalrand;
    int i;

    // parse arguments
    
    if(argc==1){
	usage(argv[0]);
	exit(0);
    }
    if(argc>=2) griddim.x=atoi(argv[1]);
    if(argc>=3) blockdim.x=atoi(argv[2]);
    if(argc>=4) count=atoi(argv[3]);
    if(argc>=5) repeat=atoi(argv[4]);
    
    if(RAND_TEST_LEN>0)
        count=(count/RAND_TEST_LEN)*RAND_TEST_LEN; // make count modulo of 5

    threadnum=griddim.x*blockdim.x;

    // allocate CPU and GPU arrays
    
    Pseed=(uint*)malloc(sizeof(uint)*threadnum*RAND_TEST_LEN);
    cudaMalloc((void **) &gPseed, sizeof(uint)*threadnum*RAND_TEST_LEN);
    Poutput=(float*)malloc(sizeof(float)*threadnum*count);
    cudaMalloc((void **) &gPoutput, sizeof(float)*threadnum*count);

    // initialize seeds
        
    srand(time(0));
    for (i=0; i<threadnum*RAND_TEST_LEN; i++){
	   Pseed[i]=rand();
    }

    // copy CPU data to GPU
    
    tic=StartTimer();
    totalrand=(double)threadnum*count*repeat;
    printf("total thread=%d, total rand num=%f\n",threadnum,totalrand);
    cudaMemcpy(gPseed, Pseed, sizeof(uint)*threadnum*RAND_TEST_LEN,cudaMemcpyHostToDevice);

    printf("init complete : %d ms\n",GetTimeMillis()-tic);

    // begin benchmark
    
    tic2=StartTimer();
    for(i=0;i<repeat;i++)
        bench_rng<<<griddim,blockdim>>>(gPseed,gPoutput,count);

    // get only one element to make sure all kernels are complete
    
    cudaMemcpy(Pseed,gPseed, sizeof(uint),cudaMemcpyDeviceToHost);
    toc=GetTimeMillis()-tic2;

    // take results back to CPU
        
    printf("kernel complete: %d ms\nspeed: %f random numbers per second\n",\
        toc, (1000./toc)*totalrand);
//    cudaMemcpy(Pseed, gPseed,sizeof(uint)*threadnum*RAND_TEST_LEN,cudaMemcpyDeviceToHost);
#ifdef GLOBAL_WRITE
    cudaMemcpy(Poutput,gPoutput, sizeof(float)*threadnum*count,cudaMemcpyDeviceToHost);
#endif

#ifdef GLOBAL_WRITE
    // dump random numbers to disk
    mcx_savedata(Poutput,threadnum*count,"randomnum.bin");
    printf("dump data complete: %d ms\n",GetTimeMillis()-tic);
#endif

    // memory clean-up
    
    cudaFree(gPseed);
    cudaFree(gPoutput);
    free(Pseed);
    free(Poutput);
    return 0;
}
