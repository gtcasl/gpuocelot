////////////////////////////////////////////////////////////////////////////////
//
//  Monte Carlo eXtreme (MCX)  - GPU accelerated 3D Monte Carlo transport simulation                                                                                                
//  Author: Qianqian Fang <fangq at nmr.mgh.harvard.edu>
//
//  Reference (Fang2009):
//        Qianqian Fang and David A. Boas, "Monte Carlo Simulation of Photon 
//        Migration in 3D Turbid Media Accelerated by Graphics Processing 
//        Units," Optics Express, vol. 17, issue 22, pp. 20178-20190 (2009)
//
//  mcx_core.cu: GPU kernels and CUDA host code
//
//  License: GNU General Public License v3, see LICENSE.txt for details
//
////////////////////////////////////////////////////////////////////////////////

#include "br2cu.h"
#include "mcx_core.h"
#include "tictoc.h"
#include "mcx_const.h"

#ifdef USE_MT_RAND
#include "mt_rand_s.cu"     // use Mersenne Twister RNG (MT)
#else
#include "logistic_rand.cu" // use Logistic Lattice ring 5 RNG (LL5)
#endif

// optical properties saved in the constant memory
// {x}:mua,{y}:mus,{z}:anisotropy (g),{w}:refractive index (n)
__constant__ float4 gproperty[MAX_PROP];

__constant__ float4 gdetpos[MAX_DETECTORS];

// kernel constant parameters
__constant__ MCXParam gcfg[1];

extern __shared__ float sharedmem[]; //max 64 tissue types when block size=64

// tested with texture memory for media, only improved 1% speed
// to keep code portable, use global memory for now
// also need to change all media[idx1d] to tex1Dfetch() below
//texture<uchar, 1, cudaReadModeElementType> texmedia;

__device__ inline void atomicadd(float* address, float value){

#if __CUDA_ARCH__ >= 200 // for Fermi, atomicAdd supports floats

  atomicAdd(address,value);

#elif __CUDA_ARCH__ >= 110

// float-atomic-add from 
// http://forums.nvidia.com/index.php?showtopic=158039&view=findpost&p=991561
  float old = value;  
  while ((old = atomicExch(address, atomicExch(address, 0.0f)+old))!=0.0f);

#endif

}

__device__ inline void clearpath(float *p,int maxmediatype){
      uint i;
      for(i=0;i<maxmediatype;i++)
      	   p[i]=0.f;
}

__device__ inline void clearcache(float *p,int len){
      uint i;
      if(threadIdx.x==0)
        for(i=0;i<len;i++)
      	   p[i]=0.f;
}

#ifdef  USE_CACHEBOX
__device__ inline void savecache(float *data,float *cache){
      uint x,y,z;
      if(threadIdx.x==0){
        for(z=gcfg->cp0.z;z<=gcfg->cp1.z;z++)
           for(y=gcfg->cp0.y;y<=gcfg->cp1.y;y++)
              for(x=gcfg->cp0.x;x<=gcfg->cp1.x;x++){
                 atomicadd(data+z*gcfg->dimlen.y+y*gcfg->dimlen.x+x,
		    cache[(z-gcfg->cp0.z)*gcfg->cachebox.y+(y-gcfg->cp0.y)*gcfg->cachebox.x+(x-gcfg->cp0.x)]);
	      }
      }
}
#endif

#ifdef SAVE_DETECTORS
__device__ inline uint finddetector(MCXpos *p0){
      uint i;
      for(i=0;i<gcfg->detnum;i++){
      	if((gdetpos[i].x-p0->x)*(gdetpos[i].x-p0->x)+
	   (gdetpos[i].y-p0->y)*(gdetpos[i].y-p0->y)+
	   (gdetpos[i].z-p0->z)*(gdetpos[i].z-p0->z) < gdetpos[i].w){
	        return i+1;
	   }
      }
      return 0;
}

__device__ inline void savedetphoton(float n_det[],uint *detectedphoton,float weight,float *ppath,MCXpos *p0){
      uint j,baseaddr=0;
      j=finddetector(p0);
      if(j){
	 baseaddr=atomicAdd(detectedphoton,1);
	 if(baseaddr<gcfg->maxdetphoton){
	    baseaddr*=gcfg->maxmedia+2;
	    n_det[baseaddr++]=j;
	    n_det[baseaddr++]=weight;
	    for(j=0;j<gcfg->maxmedia;j++){
		n_det[baseaddr+j]=ppath[j]; // save partial pathlength to the memory
	    }
	 }
      }
}
#endif

__device__ inline void launchnewphoton(MCXpos *p,MCXdir *v,MCXtime *f,Medium *prop,uint *idx1d,
           uchar *mediaid,uchar isdet, float ppath[],float energyloss[],float n_det[],uint *dpnum){

      *energyloss+=p->w;  // sum all the remaining energy
#ifdef SAVE_DETECTORS
      // let's handle detectors here
      if(gcfg->savedet){
         if(*mediaid==0 && isdet)
	      savedetphoton(n_det,dpnum,v->nscat,ppath,p);
	 clearpath(ppath,gcfg->maxmedia);
      }
#endif
      *((float4*)p)=gcfg->ps;
      *((float4*)v)=gcfg->c0;
      *((float4*)f)=float4(0.f,0.f,gcfg->minaccumtime,f->ndone+1);
      *idx1d=gcfg->idx1dorig;
      *mediaid=gcfg->mediaidorig;
      *((float4*)(prop))=gproperty[*mediaid]; //always use mediaid to read gproperty[]
}

/*
   this is the core Monte Carlo simulation kernel, please see Fig. 1 in Fang2009
   everything in the GPU kernels is in grid-unit. To convert back to length, use
   cfg->unitinmm (scattering/absorption coeff, T, speed etc)
*/
kernel void mcx_main_loop(int nphoton,int ophoton,uchar media[],float field[],
     float genergy[],uint n_seed[],float4 n_pos[],float4 n_dir[],float4 n_len[],
     float n_det[], uint *detectedphoton){

     int idx= blockDim.x * blockIdx.x + threadIdx.x;

     MCXpos  p,p0;//{x,y,z}: coordinates in grid unit, w:packet weight
     MCXdir  v;   //{x,y,z}: unitary direction vector in grid unit, nscat:total scat event
     MCXtime f;   //pscat: remaining scattering probability,t: photon elapse time, 
                  //tnext: next accumulation time, ndone: completed photons
     float  energyloss=genergy[idx<<1];
     float  energyabsorbed=genergy[(idx<<1)+1];

     uint idx1d, idx1dold;   //idx1dold is related to reflection

#ifdef TEST_RACING
     int cc=0;
#endif
     uchar  mediaid,mediaidold;
     char   medid=-1;
     float  atten;         //can be taken out to minimize registers
     float  n1;   //reflection var

     //for MT RNG, these will be zero-length arrays and be optimized out
     RandType t[RAND_BUF_LEN],tnew[RAND_BUF_LEN];
     Medium prop;    //can become float2 if no reflection (mua/musp is in 1/grid unit)

     float len,cphi,sphi,theta,stheta,ctheta,tmp0,tmp1;

     float *ppath=sharedmem;
#ifdef  USE_CACHEBOX
  #ifdef  SAVE_DETECTORS
     float *cachebox=sharedmem+(gcfg->savedet ? blockDim.x*gcfg->maxmedia: 0);
  #else
     float *cachebox=sharedmem;
  #endif
     if(gcfg->skipradius2>EPS) clearcache(cachebox,(gcfg->cp1.x-gcfg->cp0.x+1)*(gcfg->cp1.y-gcfg->cp0.y+1)*(gcfg->cp1.z-gcfg->cp0.z+1));
#else
     float accumweight=0.f;
#endif

#ifdef  SAVE_DETECTORS
     ppath=sharedmem+threadIdx.x*gcfg->maxmedia;
#endif
     *((float4*)(&p))=n_pos[idx];
     *((float4*)(&v))=n_dir[idx];
     *((float4*)(&f))=n_len[idx];

     gpu_rng_init(t,tnew,n_seed,idx);
     if(gcfg->savedet) clearpath(ppath,gcfg->maxmedia);

     // assuming the initial position is within the domain (mcx_config is supposed to ensure)
     idx1d=gcfg->idx1dorig;
     mediaid=gcfg->mediaidorig;

     if(mediaid==0) {
          return; // the initial position is not within the medium
     }
     *((float4*)(&prop))=gproperty[mediaid]; //always use mediaid to read gproperty[]

     /*
      using a while-loop to terminate a thread by np will cause MT RNG to be 3.5x slower
      LL5 RNG will only be slightly slower than for-loop with photon-move criterion

      we have switched to while-loop since v0.4.9, as LL5 was only minimally effected
      and we do not use MT as the default RNG.
     */

     while(f.ndone<(idx<ophoton?nphoton+1:nphoton)) {

          GPUDEBUG(("*i= (%d) L=%f w=%e a=%f\n",(int)f.ndone,f.pscat,p.w,f.t));

          // dealing with scattering

	  if(f.pscat<=0.f) {  // if this photon has finished his current jump, get next scat length & angles
               rand_need_more(t,tnew);
   	       f.pscat=rand_next_scatlen(t); // random scattering probability, unit-less

               GPUDEBUG(("next scat len=%20.16e \n",f.pscat));
	       if(p.w<1.f){ // if this is not my first jump
                       //random arimuthal angle
                       tmp0=TWO_PI*rand_next_aangle(t); //next arimuth angle
                       sincosf(tmp0,&sphi,&cphi);
                       GPUDEBUG(("next angle phi %20.16e\n",tmp0));

                       //Henyey-Greenstein Phase Function, "Handbook of Optical 
                       //Biomedical Diagnostics",2002,Chap3,p234, also see Boas2002

                       if(prop.g>EPS){  //if prop.g is too small, the distribution of theta is bad
		           tmp0=(1.f-prop.g*prop.g)/(1.f-prop.g+2.f*prop.g*rand_next_zangle(t));
		           tmp0*=tmp0;
		           tmp0=(1.f+prop.g*prop.g-tmp0)/(2.f*prop.g);

                           // when ran=1, CUDA gives me 1.000002 for tmp0 which produces nan later
                           // detected by Ocelot,thanks to Greg Diamos,see http://bit.ly/cR2NMP
                           tmp0=max(-1.f, min(1.f, tmp0));

		           theta=acosf(tmp0);
		           stheta=sinf(theta);
		           ctheta=tmp0;
                       }else{
			   theta=ONE_PI*rand_next_zangle(t);
                           sincosf(theta,&stheta,&ctheta);
                       }
                       GPUDEBUG(("next scat angle theta %20.16e\n",theta));

		       if( v.z>-1.f+EPS && v.z<1.f-EPS ) {
		           tmp0=1.f-v.z*v.z;   //reuse tmp to minimize registers
		           tmp1=rsqrtf(tmp0);
		           tmp1=stheta*tmp1;
		           *((float4*)(&v))=float4(
				tmp1*(v.x*v.z*cphi - v.y*sphi) + v.x*ctheta,
				tmp1*(v.y*v.z*cphi + v.x*sphi) + v.y*ctheta,
				-tmp1*tmp0*cphi                + v.z*ctheta,
				v.nscat
			   );
                           GPUDEBUG(("new dir: %10.5e %10.5e %10.5e\n",v.x,v.y,v.z));
		       }else{
			   *((float4*)(&v))=float4(stheta*cphi,stheta*sphi,(v.z>0.f)?ctheta:-ctheta,v.nscat);
                           GPUDEBUG(("new dir-z: %10.5e %10.5e %10.5e\n",v.x,v.y,v.z));
 		       }
                       v.nscat++;
	       }
	  }

          n1=prop.n;
	  *((float4*)(&prop))=gproperty[mediaid];
	  len=gcfg->minstep*prop.mus; //unitless (minstep=grid, mus=1/grid)

          // dealing with absorption

          p0=p;
	  if(len>f.pscat){  //scattering ends in this voxel: mus*gcfg->minstep > s 
               tmp0=f.pscat/prop.mus; // unit=grid
   	       *((float4*)(&p))=float4(p.x+v.x*tmp0,p.y+v.y*tmp0,p.z+v.z*tmp0,
                           p.w*expf(-prop.mua*tmp0)); //mua=1/grid, tmp0=grid
	       f.pscat=SAME_VOXEL;
	       f.t+=tmp0*prop.n*gcfg->oneoverc0;  //propagation time (unit=s)
               if(gcfg->savedet) ppath[mediaid-1]+=tmp0; //(unit=grid)
               GPUDEBUG((">>ends in voxel %f<%f %f [%d]\n",f.pscat,len,prop.mus,idx1d));
	  }else{                      //otherwise, move gcfg->minstep
               if(mediaid!=medid)
                  atten=expf(-prop.mua*gcfg->minstep);

   	       *((float4*)(&p))=float4(p.x+v.x,p.y+v.y,p.z+v.z,p.w*atten);
               medid=mediaid;
	       f.pscat-=len;     //remaining probability: sum(s_i*mus_i), unit-less
	       f.t+=gcfg->minaccumtime*prop.n; //propagation time  (unit=s)
               if(gcfg->savedet) ppath[mediaid-1]+=gcfg->minstep; //(unit=grid)
               GPUDEBUG((">>keep going %f<%f %f [%d] %e %e\n",f.pscat,len,prop.mus,idx1d,f.t,f.tnext));
	  }

          mediaidold=media[idx1d];
          idx1dold=idx1d;
          idx1d=(int(floorf(p.z))*gcfg->dimlen.y+int(floorf(p.y))*gcfg->dimlen.x+int(floorf(p.x)));
          GPUDEBUG(("old and new voxels: %d<->%d\n",idx1dold,idx1d));
          if(p.x<0||p.y<0||p.z<0||p.x>=gcfg->maxidx.x||p.y>=gcfg->maxidx.y||p.z>=gcfg->maxidx.z){
	      mediaid=0;
	  }else{
	      mediaid=(media[idx1d] & MED_MASK);
          }

          // dealing with boundaries

          //if it hits the boundary, exceeds the max time window or exits the domain, rebound or launch a new one
	  if(mediaid==0||f.t>gcfg->tmax||f.t>gcfg->twin1||(gcfg->dorefint && n1!=gproperty[mediaid].w) ){
	      float flipdir=0.f;
              float3 htime;            //reflection var

              if(gcfg->doreflect) {
                //time-of-flight to hit the wall in each direction
                htime.x=(v.x>EPS||v.x<-EPS)?(floorf(p0.x)+(v.x>0.f)-p0.x)/v.x:VERY_BIG;
                htime.y=(v.y>EPS||v.y<-EPS)?(floorf(p0.y)+(v.y>0.f)-p0.y)/v.y:VERY_BIG;
                htime.z=(v.z>EPS||v.z<-EPS)?(floorf(p0.z)+(v.z>0.f)-p0.z)/v.z:VERY_BIG;
                //get the direction with the smallest time-of-flight
                tmp0=fminf(fminf(htime.x,htime.y),htime.z);
                flipdir=(tmp0==htime.x?1.f:(tmp0==htime.y?2.f:(tmp0==htime.z&&idx1d!=idx1dold)?3.f:0.f));

                //move to the 1st intersection pt
                tmp0*=JUST_ABOVE_ONE;
                htime.x=floorf(p0.x+tmp0*v.x);
       	        htime.y=floorf(p0.y+tmp0*v.y);
       	        htime.z=floorf(p0.z+tmp0*v.z);

                if(htime.x>=0&&htime.y>=0&&htime.z>=0&&htime.x<gcfg->maxidx.x&&htime.y<gcfg->maxidx.y&&htime.z<gcfg->maxidx.z){
                    if(media[int(htime.z*gcfg->dimlen.y+htime.y*gcfg->dimlen.x+htime.x)]==mediaidold){ //if the first vox is not air

                     GPUDEBUG((" first try failed: [%.1f %.1f,%.1f] %d (%.1f %.1f %.1f)\n",htime.x,htime.y,htime.z,
                           media[int(htime.z*gcfg->dimlen.y+htime.y*gcfg->dimlen.x+htime.x)], gcfg->maxidx.x, gcfg->maxidx.y,gcfg->maxidx.z));

                     htime.x=(v.x>EPS||v.x<-EPS)?(floorf(p.x)+(v.x<0.f)-p.x)/(-v.x):VERY_BIG;
                     htime.y=(v.y>EPS||v.y<-EPS)?(floorf(p.y)+(v.y<0.f)-p.y)/(-v.y):VERY_BIG;
                     htime.z=(v.z>EPS||v.z<-EPS)?(floorf(p.z)+(v.z<0.f)-p.z)/(-v.z):VERY_BIG;
                     tmp0=fminf(fminf(htime.x,htime.y),htime.z);
                     tmp1=flipdir;   //save the previous ref. interface id
                     flipdir=(tmp0==htime.x?1.f:(tmp0==htime.y?2.f:(tmp0==htime.z&&idx1d!=idx1dold)?3.f:0.f));

                     //if(gcfg->doreflect3){
                       tmp0*=JUST_ABOVE_ONE;
                       htime.x=floorf(p.x-tmp0*v.x); //move to the last intersection pt
                       htime.y=floorf(p.y-tmp0*v.y);
                       htime.z=floorf(p.z-tmp0*v.z);

                       if(tmp1!=flipdir&&htime.x>=0&&htime.y>=0&&htime.z>=0&&htime.x<gcfg->maxidx.x&&htime.y<gcfg->maxidx.y&&htime.z<gcfg->maxidx.z){
                           if(media[int(htime.z*gcfg->dimlen.y+htime.y*gcfg->dimlen.x+htime.x)]!=mediaidold){ //this is an air voxel

                               GPUDEBUG((" second try failed: [%.1f %.1f,%.1f] %d (%.1f %.1f %.1f)\n",htime.x,htime.y,htime.z,
                                   media[int(htime.z*gcfg->dimlen.y+htime.y*gcfg->dimlen.x+htime.x)], gcfg->maxidx.x, gcfg->maxidx.y,gcfg->maxidx.z));

                               /*to compute the remaining interface, we used the following fact to accelerate: 
                                 if there exist 3 intersections, photon must pass x/y/z interface exactly once,
                                 we solve the coeff of the following equation to find the last interface:
                                    a*1+b*2+c=3
       	       	       	       	    a*1+b*3+c=2 -> [a b c]=[-1 -1 6], this will give the remaining interface id
       	       	       	       	    a*2+b*3+c=1
                               */
                               flipdir=-tmp1-flipdir+6.f;
                           }
                       }
                     //}
                  }
                }
              }

              *((float4*)(&prop))=gproperty[mediaid]; // optical property across the interface

              GPUDEBUG(("->ID%d J%d C%d tlen %e flip %d %.1f!=%.1f dir=%f %f %f pos=%f %f %f\n",idx,(int)v.nscat,
                  (int)f.ndone,f.t, (int)flipdir, n1,prop.n,v.x,v.y,v.z,p.x,p.y,p.z));

              //recycled some old register variables to save memory
	      //if hit boundary within the time window and is n-mismatched, rebound

              if(gcfg->doreflect&&f.t<gcfg->tmax&&f.t<gcfg->twin1&& flipdir>0.f && n1!=prop.n &&p.w>gcfg->minenergy){
	          float Rtotal=1.f;

                  tmp0=n1*n1;
                  tmp1=prop.n*prop.n;
                  if(flipdir>=3.f) { //flip in z axis
                     cphi=fabs(v.z);
                     sphi=v.x*v.x+v.y*v.y;
                  }else if(flipdir>=2.f){ //flip in y axis
                     cphi=fabs(v.y);
       	       	     sphi=v.x*v.x+v.z*v.z;
                  }else if(flipdir>=1.f){ //flip in x axis
                     cphi=fabs(v.x);                //cos(si)
                     sphi=v.y*v.y+v.z*v.z; //sin(si)^2
                  }
                  len=1.f-tmp0/tmp1*sphi;   //1-[n1/n2*sin(si)]^2 = cos(ti)^2
	          GPUDEBUG((" ref len=%f %f+%f=%f w=%f\n",len,cphi,sphi,cphi*cphi+sphi,p.w));

                  if(len>0.f) { // if not total internal reflection
                     ctheta=tmp0*cphi*cphi+tmp1*len;
                     stheta=2.f*n1*prop.n*cphi*sqrtf(len);
                     Rtotal=(ctheta-stheta)/(ctheta+stheta);
       	       	     ctheta=tmp1*cphi*cphi+tmp0*len;
       	       	     Rtotal=(Rtotal+(ctheta-stheta)/(ctheta+stheta))*0.5f;
	             GPUDEBUG(("  dir=%f %f %f htime=%f %f %f Rs=%f\n",v.x,v.y,v.z,htime.x,htime.y,htime.z,Rtotal));
	             GPUDEBUG(("  ID%d J%d C%d flip=%3f (%d %d) cphi=%f sphi=%f p=%f %f %f p0=%f %f %f\n",
                         idx,(int)v.nscat,(int)f.tnext,
	                 flipdir,idx1dold,idx1d,cphi,sphi,p.x,p.y,p.z,p0.x,p0.y,p0.z));
                  } // else, total internal reflection
	          if(Rtotal<1.f && rand_next_reflect(t)>Rtotal){ // do transmission
                        if(mediaid==0){ // transmission to external boundary
		    	    launchnewphoton(&p,&v,&f,&prop,&idx1d,&mediaid,(mediaidold & DET_MASK),
			        ppath,&energyloss,n_det,detectedphoton);
			    continue;
			}
			tmp0=n1/prop.n;
                	if(flipdir>=3.f) { //transmit through z plane
                	   v.x=tmp0*v.x;
                	   v.y=tmp0*v.y;
                	}else if(flipdir>=2.f){ //transmit through y plane
                	   v.x=tmp0*v.x;
                	   v.z=tmp0*v.z;
                	}else if(flipdir>=1.f){ //transmit through x plane
                	   v.y=tmp0*v.y;
                	   v.z=tmp0*v.z;
                	}
			tmp0=rsqrtf(v.x*v.x+v.y*v.y+v.z*v.z);
			v.x=v.x*tmp0;
			v.y=v.y*tmp0;
			v.z=v.z*tmp0;
		  }else{ //do reflection
                	if(flipdir>=3.f) { //flip in z axis
                	   v.z=-v.z;
                	}else if(flipdir>=2.f){ //flip in y axis
                	   v.y=-v.y;
                	}else if(flipdir>=1.f){ //flip in x axis
                	   v.x=-v.x;
                	}
                        p=p0;   //move back
                	idx1d=idx1dold;
		 	mediaid=(media[idx1d] & MED_MASK);
        	  	*((float4*)(&prop))=gproperty[mediaid];
                  	n1=prop.n;
		  }
              }else{  // launch a new photon
		  launchnewphoton(&p,&v,&f,&prop,&idx1d,&mediaid,(mediaidold & DET_MASK),ppath,
		      &energyloss,n_det,detectedphoton);
		  continue;
              }
	  }

          // saving fluence to the memory

	  if(f.t>=f.tnext){
             GPUDEBUG(("field add to %d->%f(%d)  t(%e)>t0(%e)\n",idx1d,p.w,(int)f.ndone,f.t,f.tnext));
             // if t is within the time window, which spans cfg->maxgate*cfg->tstep wide
             if(gcfg->save2pt && f.t>=gcfg->twin0 && f.t<gcfg->twin1){
                  energyabsorbed+=p.w*prop.mua;
#ifdef TEST_RACING
                  // enable TEST_RACING to determine how many missing accumulations due to race
                  if( (p.x-gcfg->ps.x)*(p.x-gcfg->ps.x)+(p.y-gcfg->ps.y)*(p.y-gcfg->ps.y)+(p.z-gcfg->ps.z)*(p.z-gcfg->ps.z)>gcfg->skipradius2) {
                      field[idx1d+(int)(floorf((f.t-gcfg->twin0)*gcfg->Rtstep))*gcfg->dimlen.z]+=1.f;
		      cc++;
                  }
#else
  #ifndef USE_ATOMIC
                  // set gcfg->skipradius2 to only start depositing energy when dist^2>gcfg->skipradius2 
                  if(gcfg->skipradius2>EPS){
  #ifdef  USE_CACHEBOX
                      if(p.x<gcfg->cp1.x+1.f && p.x>=gcfg->cp0.x &&
		         p.y<gcfg->cp1.y+1.f && p.y>=gcfg->cp0.y &&
			 p.z<gcfg->cp1.z+1.f && p.z>=gcfg->cp0.z){
                         atomicadd(cachebox+(int(p.z-gcfg->cp0.z)*gcfg->cachebox.y
			      +int(p.y-gcfg->cp0.y)*gcfg->cachebox.x+int(p.x-gcfg->cp0.x)),p.w);
  #else
                      if((p.x-gcfg->ps.x)*(p.x-gcfg->ps.x)+(p.y-gcfg->ps.y)*(p.y-gcfg->ps.y)+(p.z-gcfg->ps.z)*(p.z-gcfg->ps.z)<=gcfg->skipradius2){
                          accumweight+=p.w*prop.mua; // weight*absorption
  #endif
                      }else{
                          field[idx1d+(int)(floorf((f.t-gcfg->twin0)*gcfg->Rtstep))*gcfg->dimlen.z]+=p.w;
                      }
                  }else{
                      field[idx1d+(int)(floorf((f.t-gcfg->twin0)*gcfg->Rtstep))*gcfg->dimlen.z]+=p.w;
                  }
  #else
                  // ifndef CUDA_NO_SM_11_ATOMIC_INTRINSICS
		  atomicadd(& field[idx1d+(int)(floorf((f.t-gcfg->twin0)*gcfg->Rtstep))*gcfg->dimlen.z], p.w);
  #endif
#endif
	     }
             f.tnext+=gcfg->minaccumtime*prop.n; // fluence is a temporal-integration, unit=s
	  }
     }
     // cachebox saves the total absorbed energy of all time in the sphere r<sradius.
     // in non-atomic mode, cachebox is more accurate than saving to the grid
     // as it is not influenced by race conditions.
     // now I borrow f.tnext to pass this value back
#ifdef  USE_CACHEBOX
     if(gcfg->skipradius2>EPS){
     	f.tnext=0.f;
        savecache(field,cachebox);
     }
#else
     f.tnext=accumweight;
#endif

     genergy[idx<<1]=energyloss;
     genergy[(idx<<1)+1]=energyabsorbed;

#ifdef TEST_RACING
     n_seed[idx]=cc;
#endif
     n_pos[idx]=*((float4*)(&p));
     n_dir[idx]=*((float4*)(&v));
     n_len[idx]=*((float4*)(&f));
}

kernel void mcx_sum_trueabsorption(float energy[],uchar media[], float field[], int maxgate,uint3 dimlen){
     int i;
     float phi=0.f;
     int idx= blockIdx.x*dimlen.y+blockIdx.y*dimlen.x+ threadIdx.x;

     for(i=0;i<maxgate;i++){
        phi+=field[i*dimlen.z+idx];
     }
     energy[2]+=phi*gproperty[media[idx] & MED_MASK ].x;
}


/*
   assert cuda memory allocation result
*/
void mcx_cu_assess(cudaError_t cuerr,const char *file, const int linenum){
     if(cuerr!=cudaSuccess){
         mcx_error(-(int)cuerr,(char *)cudaGetErrorString(cuerr),file,linenum);
     }
}


/*
  query GPU info and set active GPU
*/
int mcx_set_gpu(Config *cfg){

#if __DEVICE_EMULATION__
    return 1;
#else
    int dev;
    int deviceCount;
    cudaGetDeviceCount(&deviceCount);
    if (deviceCount == 0){
        fprintf(stderr,"No CUDA-capable GPU device found\n");
        return 0;
    }
    if (cfg->gpuid && cfg->gpuid > deviceCount){
        fprintf(stderr,"Specified GPU ID is out of range\n");
        return 0;
    }
    // scan from the first device
    for (dev = 0; dev<deviceCount; dev++) {
        cudaDeviceProp dp;
        cudaGetDeviceProperties(&dp, dev);
	if(cfg->autopilot && ((cfg->gpuid && dev==cfg->gpuid-1)
	 ||(cfg->gpuid==0 && dev==deviceCount-1) )){
                unsigned int needmem=cfg->dim.x*cfg->dim.y*cfg->dim.z; /*for mediam*/
		if(cfg->autopilot==1){
			cfg->nblocksize=64;
			cfg->nthread=256*dp.multiProcessorCount*dp.multiProcessorCount;
			needmem+=cfg->nthread*sizeof(float4)*4+sizeof(float)*cfg->maxdetphoton*(cfg->medianum+1)+10*1024*1024; /*keep 10M for other things*/
			cfg->maxgate=((unsigned int)dp.totalGlobalMem-needmem)/(cfg->dim.x*cfg->dim.y*cfg->dim.z);
			cfg->maxgate=MIN((int)((cfg->tend-cfg->tstart)/cfg->tstep+0.5),cfg->maxgate);
			fprintf(cfg->flog,"autopilot mode: setting thread number to %d, block size to %d and time gates to %d\n",cfg->nthread,cfg->nblocksize,cfg->maxgate);
		}else if(cfg->autopilot==2){
			cfg->nblocksize=64;
			cfg->nthread=dp.multiProcessorCount*128;
                        fprintf(cfg->flog,"autopilot mode: setting thread number to %d and block size to %d\n",cfg->nthread,cfg->nblocksize);
		}
	}
        if (strncmp(dp.name, "Device Emulation", 16)) {
	  if(cfg->isgpuinfo){
	    printf("=============================   GPU Infomation  ================================\n");
	    printf("Device %d of %d:\t\t%s\n",dev+1,deviceCount,dp.name);
	    printf("Compute Capability:\t%u.%u\n",dp.major,dp.minor);
	    printf("Global Memory:\t\t%u B\nConstant Memory:\t%u B\n\
Shared Memory:\t\t%u B\nRegisters:\t\t%u\nClock Speed:\t\t%.2f GHz\n",
               (unsigned int)dp.totalGlobalMem,(unsigned int)dp.totalConstMem,
               (unsigned int)dp.sharedMemPerBlock,(unsigned int)dp.regsPerBlock,dp.clockRate*1e-6f);
	  #if CUDART_VERSION >= 2000
	       printf("Number of MPs:\t\t%u\nNumber of Cores:\t%u\n",
	          dp.multiProcessorCount,dp.multiProcessorCount<<3);
	  #endif
	  }
	}
    }
    if(cfg->isgpuinfo==2 && cfg->exportfield==NULL){ //list GPU info only
          exit(0);
    }
    if (cfg->gpuid==0)
        mcx_cu_assess(cudaSetDevice(deviceCount-1),__FILE__,__LINE__);
    else
        mcx_cu_assess(cudaSetDevice(cfg->gpuid-1),__FILE__,__LINE__);

    return 1;
#endif
}


/*
   host code for MCX kernels
*/
void mcx_run_simulation(Config *cfg){

     int i,iter;
     float  minstep=MIN(MIN(cfg->steps.x,cfg->steps.y),cfg->steps.z);
     float4 p0=float4(cfg->srcpos.x,cfg->srcpos.y,cfg->srcpos.z,1.f);
     float4 c0=float4(cfg->srcdir.x,cfg->srcdir.y,cfg->srcdir.z,0.f);
     float3 maxidx=float3(cfg->dim.x,cfg->dim.y,cfg->dim.z);
     float t;
     float energyloss=0.f,energyabsorbed=0.f;
     float *energy;
     int threadphoton, oddphotons;

     unsigned int photoncount=0,printnum;
     unsigned int tic,tic0,tic1,toc=0,fieldlen;
     uint3 cp0=cfg->crop0,cp1=cfg->crop1;
     uint2 cachebox;
     uint3 dimlen;
     float Vvox,scale,eabsorp;

     dim3 mcgrid, mcblock;
     dim3 clgrid, clblock;
     
     int dimxyz=cfg->dim.x*cfg->dim.y*cfg->dim.z;
     
     uchar  *media=(uchar *)(cfg->vol);
     float  *field;
     MCXParam param={cfg->steps,minstep,0,0,cfg->tend,R_C0*cfg->unitinmm,cfg->isrowmajor,
                     cfg->issave2pt,cfg->isreflect,cfg->isrefint,cfg->issavedet,1.f/cfg->tstep,
		     p0,c0,maxidx,uint3(0,0,0),cp0,cp1,uint2(0,0),cfg->minenergy,
                     cfg->sradius*cfg->sradius,minstep*R_C0*cfg->unitinmm,cfg->maxdetphoton,
		     cfg->medianum-1,cfg->detnum,0,0};

     if(cfg->respin>1){
         field=(float *)calloc(sizeof(float)*dimxyz,cfg->maxgate*2);
     }else{
         field=(float *)calloc(sizeof(float)*dimxyz,cfg->maxgate); //the second half will be used to accumulate
     }

     float4 *Ppos;
     float4 *Pdir;
     float4 *Plen,*Plen0;
     uint   *Pseed;
     float  *Pdet;
     uint    detected=0,sharedbuf=0;

     if(cfg->nthread%cfg->nblocksize)
     	cfg->nthread=(cfg->nthread/cfg->nblocksize)*cfg->nblocksize;
     threadphoton=cfg->nphoton/cfg->nthread/cfg->respin;
     oddphotons=cfg->nphoton/cfg->respin-threadphoton*cfg->nthread;

     mcgrid.x=cfg->nthread/cfg->nblocksize;
     mcblock.x=cfg->nblocksize;

     clgrid.x=cfg->dim.x;
     clgrid.y=cfg->dim.y;
     clblock.x=cfg->dim.z;
	
     Ppos=(float4*)malloc(sizeof(float4)*cfg->nthread);
     Pdir=(float4*)malloc(sizeof(float4)*cfg->nthread);
     Plen=(float4*)malloc(sizeof(float4)*cfg->nthread);
     Plen0=(float4*)malloc(sizeof(float4)*cfg->nthread);
     Pseed=(uint*)malloc(sizeof(uint)*cfg->nthread*RAND_SEED_LEN);
     energy=(float*)calloc(cfg->nthread*2,sizeof(float));
     Pdet=(float*)calloc(cfg->maxdetphoton,sizeof(float)*(cfg->medianum+1));

     uchar *gmedia;
     mcx_cu_assess(cudaMalloc((void **) &gmedia, sizeof(uchar)*(dimxyz)),__FILE__,__LINE__);
     float *gfield;
     mcx_cu_assess(cudaMalloc((void **) &gfield, sizeof(float)*(dimxyz)*cfg->maxgate),__FILE__,__LINE__);

     //cudaBindTexture(0, texmedia, gmedia);

     float4 *gPpos;
     mcx_cu_assess(cudaMalloc((void **) &gPpos, sizeof(float4)*cfg->nthread),__FILE__,__LINE__);
     float4 *gPdir;
     mcx_cu_assess(cudaMalloc((void **) &gPdir, sizeof(float4)*cfg->nthread),__FILE__,__LINE__);
     float4 *gPlen;
     mcx_cu_assess(cudaMalloc((void **) &gPlen, sizeof(float4)*cfg->nthread),__FILE__,__LINE__);
     uint   *gPseed;
     mcx_cu_assess(cudaMalloc((void **) &gPseed, sizeof(uint)*cfg->nthread*RAND_SEED_LEN),__FILE__,__LINE__);
     float  *gPdet;
     mcx_cu_assess(cudaMalloc((void **) &gPdet, sizeof(float)*cfg->maxdetphoton*(cfg->medianum+1)),__FILE__,__LINE__);
     uint   *gdetected;
     mcx_cu_assess(cudaMalloc((void **) &gdetected, sizeof(uint)),__FILE__,__LINE__);

     float *genergy;
     cudaMalloc((void **) &genergy, sizeof(float)*cfg->nthread*2);
     
     /*volume is assumbed to be col-major*/
     cachebox.x=(cp1.x-cp0.x+1);
     cachebox.y=(cp1.y-cp0.y+1)*(cp1.x-cp0.x+1);
     dimlen.x=cfg->dim.x;
     dimlen.y=cfg->dim.y*cfg->dim.x;

     dimlen.z=cfg->dim.x*cfg->dim.y*cfg->dim.z;
     param.dimlen=dimlen;
     param.cachebox=cachebox;
     param.idx1dorig=(int(floorf(p0.z))*dimlen.y+int(floorf(p0.y))*dimlen.x+int(floorf(p0.x)));
     param.mediaidorig=(cfg->vol[param.idx1dorig] & MED_MASK);

     Vvox=cfg->steps.x*cfg->steps.y*cfg->steps.z;

     if(cfg->seed>0)
     	srand(cfg->seed);
     else
        srand(time(0));
	
     for (i=0; i<cfg->nthread; i++) {
	   Ppos[i]=p0;  // initial position
           Pdir[i]=c0;
           Plen[i]=float4(0.f,0.f,param.minaccumtime,0.f);
     }

     fprintf(cfg->flog,"\
###############################################################################\n\
#                      Monte Carlo eXtreme (MCX) -- CUDA                      #\n\
#     Copyright (c) 2009-2011 Qianqian Fang <fangq at nmr.mgh.harvard.edu>    #\n\
#                                                                             #\n\
#    Martinos Center for Biomedical Imaging, Massachusetts General Hospital   #\n\
###############################################################################\n\
$MCX $Rev:: 247 $ Last Commit $Date:: 2011-05-03 20:50:55#$ by $Author:: fangq$\n\
###############################################################################\n");

     tic=StartTimer();
#ifdef MCX_TARGET_NAME
     fprintf(cfg->flog,"- variant name: [%s] compiled for GPU Capability [%d] with CUDA [%d]\n",
             MCX_TARGET_NAME,MCX_CUDA_ARCH,CUDART_VERSION);
#else
     fprintf(cfg->flog,"- code name: [Vanilla MCX] compiled for GPU Capacity [%d] with CUDA [%d]\n",
             MCX_CUDA_ARCH,CUDART_VERSION);
#endif
     fprintf(cfg->flog,"- compiled with: RNG [%s] Seed Length [%d]\n",MCX_RNG_NAME,RAND_SEED_LEN);
#ifdef SAVE_DETECTORS
     fprintf(cfg->flog,"- this version CAN save photons at the detectors\n\n");
#else
     fprintf(cfg->flog,"- this version CAN NOT save photons at the detectors\n\n");
#endif
     fprintf(cfg->flog,"threadph=%d oddphotons=%d np=%d nthread=%d repetition=%d\n",threadphoton,oddphotons,
           cfg->nphoton,cfg->nthread,cfg->respin);
     fprintf(cfg->flog,"initializing streams ...\t");
     fflush(cfg->flog);
     fieldlen=dimxyz*cfg->maxgate;

     cudaMemcpy(gmedia, media, sizeof(uchar) *dimxyz, cudaMemcpyHostToDevice);
     cudaMemcpy(genergy,energy,sizeof(float) *cfg->nthread*2, cudaMemcpyHostToDevice);

     cudaMemcpyToSymbol(gproperty, cfg->prop,  cfg->medianum*sizeof(Medium), 0, cudaMemcpyHostToDevice);
     cudaMemcpyToSymbol(gdetpos, cfg->detpos,  cfg->detnum*sizeof(float4), 0, cudaMemcpyHostToDevice);

     fprintf(cfg->flog,"init complete : %d ms\n",GetTimeMillis()-tic);

     /*
         if one has to simulate a lot of time gates, using the GPU global memory
	 requires extra caution. If the total global memory is bigger than the total
	 memory to save all the snapshots, i.e. size(field)*(tend-tstart)/tstep, one
	 simply sets cfg->maxgate to the total gate number; this will run GPU kernel
	 once. If the required memory is bigger than the video memory, set cfg->maxgate
	 to a number which fits, and the snapshot will be saved with an increment of 
	 cfg->maxgate snapshots. In this case, the later simulations will restart from
	 photon launching and exhibit redundancies.
	 
	 The calculation of the energy conservation will only reflect the last simulation.
     */
#ifdef  USE_CACHEBOX
     if(cfg->sradius>EPS || cfg->sradius<0.f)
        sharedbuf+=sizeof(float)*((cp1.x-cp0.x+1)*(cp1.y-cp0.y+1)*(cp1.z-cp0.z+1));
#endif
     if(cfg->issavedet)
        sharedbuf+=cfg->nblocksize*sizeof(float)*(cfg->medianum-1);

     fprintf(cfg->flog,"requesting %d bytes of shared memory\n",sharedbuf);

     //simulate for all time-gates in maxgate groups per run
     for(t=cfg->tstart;t<cfg->tend;t+=cfg->tstep*cfg->maxgate){

       param.twin0=t;
       param.twin1=t+cfg->tstep*cfg->maxgate;
       cudaMemcpyToSymbol(gcfg,   &param,     sizeof(MCXParam), 0, cudaMemcpyHostToDevice);

       fprintf(cfg->flog,"lauching mcx_main_loop for time window [%.2ens %.2ens] ...\n"
           ,param.twin0*1e9,param.twin1*1e9);

       //total number of repetition for the simulations, results will be accumulated to field
       for(iter=0;iter<cfg->respin;iter++){
           cudaMemset(gfield,0,sizeof(float)*fieldlen); // cost about 1 ms
           cudaMemset(gPdet,0,sizeof(float)*cfg->maxdetphoton*(cfg->medianum+1));
           cudaMemset(gdetected,0,sizeof(float));

 	   cudaMemcpy(gPpos,  Ppos,  sizeof(float4)*cfg->nthread,  cudaMemcpyHostToDevice);
	   cudaMemcpy(gPdir,  Pdir,  sizeof(float4)*cfg->nthread,  cudaMemcpyHostToDevice);
	   cudaMemcpy(gPlen,  Plen,  sizeof(float4)*cfg->nthread,  cudaMemcpyHostToDevice);
           for (i=0; i<cfg->nthread*RAND_SEED_LEN; i++)
		Pseed[i]=rand();
	   cudaMemcpy(gPseed, Pseed, sizeof(uint)*cfg->nthread*RAND_SEED_LEN,  cudaMemcpyHostToDevice);

           tic0=GetTimeMillis();
           fprintf(cfg->flog,"simulation run#%2d ... \t",iter+1); fflush(cfg->flog);
           mcx_main_loop<<<mcgrid,mcblock,sharedbuf>>>(threadphoton,oddphotons,gmedia,gfield,genergy,
	                                               gPseed,gPpos,gPdir,gPlen,gPdet,gdetected);

           cudaThreadSynchronize();
	   cudaMemcpy(&detected, gdetected,sizeof(uint),cudaMemcpyDeviceToHost);
           tic1=GetTimeMillis();
	   toc+=tic1-tic0;
           fprintf(cfg->flog,"kernel complete:  \t%d ms\nretrieving fields ... \t",tic1-tic);
           mcx_cu_assess(cudaGetLastError(),__FILE__,__LINE__);

           cudaMemcpy(Plen0,  gPlen,  sizeof(float4)*cfg->nthread, cudaMemcpyDeviceToHost);
           cfg->his.totalphoton=0;
           for(i=0;i<cfg->nthread;i++)
	      cfg->his.totalphoton+=int(Plen0[i].w+0.5f);
           photoncount+=cfg->his.totalphoton;

#ifdef SAVE_DETECTORS
           if(cfg->issavedet){
           	cudaMemcpy(Pdet, gPdet,sizeof(float)*cfg->maxdetphoton*(cfg->medianum+1),cudaMemcpyDeviceToHost);
	        mcx_cu_assess(cudaGetLastError(),__FILE__,__LINE__);
		if(detected>cfg->maxdetphoton){
			fprintf(cfg->flog,"WARNING: the detected photon (%d) \
is more than what your have specified (%d), please use the -H option to specify a greater number\t"
                           ,detected,cfg->maxdetphoton);
		}else{
			fprintf(cfg->flog,"detected %d photons\t",detected);
		}
		cfg->his.unitinmm=cfg->unitinmm;
		cfg->his.detected=detected;
		cfg->his.savedphoton=MIN(detected,cfg->maxdetphoton);
		if(cfg->exportdetected) //you must allocate the buffer long enough
	                memcpy(cfg->exportdetected,Pdet,cfg->his.savedphoton*(cfg->medianum+1)*sizeof(float));
		else
			mcx_savedata(Pdet,cfg->his.savedphoton*(cfg->medianum+1),
		             photoncount>cfg->his.totalphoton,"mch",cfg);
	   }
#endif

	   //handling the 2pt distributions
           if(cfg->issave2pt){
               cudaMemcpy(field, gfield,sizeof(float) *dimxyz*cfg->maxgate,cudaMemcpyDeviceToHost);
               fprintf(cfg->flog,"transfer complete:\t%d ms\n",GetTimeMillis()-tic);  fflush(cfg->flog);

               if(cfg->respin>1){
                   for(i=0;i<fieldlen;i++)  //accumulate field, can be done in the GPU
                      field[fieldlen+i]+=field[i];
               }
               if(iter+1==cfg->respin){
                   if(cfg->respin>1)  //copy the accumulated fields back
                       memcpy(field,field+fieldlen,sizeof(float)*fieldlen);

                   if(cfg->isnormalized){
                       //normalize field if it is the last iteration, temporarily do it in CPU
                       //mcx_sum_trueabsorption<<<clgrid,clblock>>>(genergy,gmedia,gfield,
                       //  	cfg->maxgate,threaddim);

                       fprintf(cfg->flog,"normalizing raw data ...\t");

                       cudaMemcpy(energy,genergy,sizeof(float)*cfg->nthread*2,cudaMemcpyDeviceToHost);
                       eabsorp=0.f;
                       for(i=1;i<cfg->nthread;i++){
                           energy[0]+=energy[i<<1];
       	       	       	   energy[1]+=energy[(i<<1)+1];
                       }
		       for(i=0;i<cfg->nthread;i++)
                           eabsorp+=Plen0[i].z;  // the accumulative absorpted energy near the source
                       eabsorp+=energy[1];
                       scale=(cfg->nphoton-energy[0])/(cfg->nphoton*Vvox*cfg->tstep*eabsorp);
		       if(cfg->unitinmm!=1.f) 
		          scale/=(cfg->unitinmm*cfg->unitinmm); /* Vvox*(U*U*U) * (Tstep) * (Eabsorp/U) */
                       fprintf(cfg->flog,"normalization factor alpha=%f\n",scale);  fflush(cfg->flog);
                       mcx_normalize(field,scale,fieldlen);
                   }
                   fprintf(cfg->flog,"data normalization complete : %d ms\n",GetTimeMillis()-tic);

		   if(cfg->exportfield) //you must allocate the buffer long enough
	                   memcpy(cfg->exportfield,field,fieldlen*sizeof(float));
		   else{
                           fprintf(cfg->flog,"saving data to file ...\t");
	                   mcx_savedata(field,fieldlen,t>cfg->tstart,"mc2",cfg);
                           fprintf(cfg->flog,"saving data complete : %d ms\n\n",GetTimeMillis()-tic);
                           fflush(cfg->flog);
                   }
               }
           }
       }
       if(param.twin1<cfg->tend){
            cudaMemset(genergy,0,sizeof(float)*cfg->nthread*2);
       }
     }

     cudaMemcpy(Ppos,  gPpos, sizeof(float4)*cfg->nthread, cudaMemcpyDeviceToHost);
     cudaMemcpy(Pdir,  gPdir, sizeof(float4)*cfg->nthread, cudaMemcpyDeviceToHost);
     cudaMemcpy(Plen,  gPlen, sizeof(float4)*cfg->nthread, cudaMemcpyDeviceToHost);
     cudaMemcpy(Pseed, gPseed,sizeof(uint)  *cfg->nthread*RAND_SEED_LEN,   cudaMemcpyDeviceToHost);
     cudaMemcpy(energy,genergy,sizeof(float)*cfg->nthread*2,cudaMemcpyDeviceToHost);

     for (i=0; i<cfg->nthread; i++) {
          energyloss+=energy[i<<1];
          energyabsorbed+=energy[(i<<1)+1];
     }

#ifdef TEST_RACING
     {
       float totalcount=0.f,hitcount=0.f;
       for (i=0; i<fieldlen; i++)
          hitcount+=field[i];
       for (i=0; i<cfg->nthread; i++)
	  totalcount+=Pseed[i];
     
       fprintf(cfg->flog,"expected total recording number: %f, got %f, missed %f\n",
          totalcount,hitcount,(totalcount-hitcount)/totalcount);
     }
#endif

     printnum=cfg->nthread<cfg->printnum?cfg->nthread:cfg->printnum;
     for (i=0; i<printnum; i++) {
           fprintf(cfg->flog,"% 4d[A% f % f % f]C%3d J%5d W% 8f(P%6.3f %6.3f %6.3f)T% 5.3e L% 5.3f %.0f\n", i,
            Pdir[i].x,Pdir[i].y,Pdir[i].z,(int)Plen[i].w,(int)Pdir[i].w,Ppos[i].w, 
            Ppos[i].x,Ppos[i].y,Ppos[i].z,Plen[i].y,Plen[i].x,(float)Pseed[i]);
     }
     // total energy here equals total simulated photons+unfinished photons for all threads
     fprintf(cfg->flog,"simulated %d photons (%d) with %d threads (repeat x%d)\nMCX simulation speed: %.2f photon/ms\n",
             photoncount,cfg->nphoton,cfg->nthread,cfg->respin,(double)photoncount/toc); fflush(cfg->flog);
     fprintf(cfg->flog,"exit energy:%16.8e + absorbed energy:%16.8e = total: %16.8e\n",
             energyloss,cfg->nphoton-energyloss,(float)cfg->nphoton);fflush(cfg->flog);
     fflush(cfg->flog);

     cudaFree(gmedia);
     cudaFree(gfield);
     cudaFree(gPpos);
     cudaFree(gPdir);
     cudaFree(gPlen);
     cudaFree(gPseed);
     cudaFree(genergy);
     cudaFree(gPdet);
     cudaFree(gdetected);

     cudaThreadExit();

     free(Ppos);
     free(Pdir);
     free(Plen);
     free(Plen0);
     free(Pseed);
     free(Pdet);
     free(energy);
     free(field);
}
