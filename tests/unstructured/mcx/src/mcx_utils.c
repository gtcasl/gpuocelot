/*******************************************************************************
**
**  Monte Carlo eXtreme (MCX)  - GPU accelerated 3D Monte Carlo transport simulation
**  Author: Qianqian Fang <fangq at nmr.mgh.harvard.edu>
**
**  Reference (Fang2009):
**        Qianqian Fang and David A. Boas, "Monte Carlo Simulation of Photon 
**        Migration in 3D Turbid Media Accelerated by Graphics Processing 
**        Units," Optics Express, vol. 17, issue 22, pp. 20178-20190 (2009)
**
**  mcx_utils.c: configuration and command line option processing unit
**
**  License: GNU General Public License v3, see LICENSE.txt for details
**
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mcx_utils.h"
#include "mcx_const.h"

const char shortopt[]={'h','i','f','n','t','T','s','a','g','b','B','z','u','H',
                 'd','r','S','p','e','U','R','l','L','I','o','G','M','A','E','v','\0'};
const char *fullopt[]={"--help","--interactive","--input","--photon",
                 "--thread","--blocksize","--session","--array",
                 "--gategroup","--reflect","--reflectin","--srcfrom0",
                 "--unitinmm","--maxdetphoton","--savedet",
                 "--repeat","--save2pt","--printlen","--minenergy",
                 "--normalize","--skipradius","--log","--listgpu",
                 "--printgpu","--root","--gpu","--dumpmask","--autopilot","--seed","--version",""};

void mcx_initcfg(Config *cfg){
     cfg->medianum=0;
     cfg->detnum=0;
     cfg->dim.x=0;
     cfg->dim.y=0;
     cfg->dim.z=0;
     cfg->steps.x=1.f;
     cfg->steps.y=1.f;
     cfg->steps.z=1.f;
     cfg->nblocksize=64;
     cfg->nphoton=0;
     cfg->nthread=2048;
     cfg->isrowmajor=0; /* default is Matlab array*/
     cfg->maxgate=1;
     cfg->isreflect=1;
     cfg->isref3=1;
     cfg->isrefint=0;
     cfg->isnormalized=1;
     cfg->issavedet=1;
     cfg->respin=1;
     cfg->issave2pt=1;
     cfg->isgpuinfo=0;
     cfg->prop=NULL;
     cfg->detpos=NULL;
     cfg->vol=NULL;
     cfg->session[0]='\0';
     cfg->printnum=0;
     cfg->minenergy=0.f;
     cfg->flog=stdout;
     cfg->sradius=0.f;
     cfg->rootpath[0]='\0';
     cfg->gpuid=0;
     cfg->issrcfrom0=0;
     cfg->unitinmm=1.f;
     cfg->isdumpmask=0;
     cfg->maxdetphoton=1000000; 
     cfg->autopilot=0;
     cfg->seed=0;
     cfg->exportfield=NULL;
     cfg->exportdetected=NULL;
     /*cfg->his=(History){{'M','C','X','H'},1,0,0,0,0,0,0,1.f,{0,0,0,0,0,0,0}};*/
     memset(&cfg->his,0,sizeof(History));
     memcpy(cfg->his.magic,"MCXH",4);     
     cfg->his.version=1;
     cfg->his.unitinmm=1.f;
}

void mcx_clearcfg(Config *cfg){
     if(cfg->medianum)
     	free(cfg->prop);
     if(cfg->detnum)
     	free(cfg->detpos);
     if(cfg->dim.x && cfg->dim.y && cfg->dim.z)
        free(cfg->vol);

     mcx_initcfg(cfg);
}

void mcx_savedata(float *dat, int len, int doappend, char *suffix, Config *cfg){
     FILE *fp;
     char name[MAX_PATH_LENGTH];
     sprintf(name,"%s.%s",cfg->session,suffix);
     if(doappend){
        fp=fopen(name,"ab");
     }else{
        fp=fopen(name,"wb");
     }
     if(fp==NULL){
	mcx_error(-2,"can not save data to disk",__FILE__,__LINE__);
     }
     if(strcmp(suffix,"mch")==0){
	fwrite(&(cfg->his),sizeof(History),1,fp);
     }
     fwrite(dat,sizeof(float),len,fp);
     fclose(fp);
}

void mcx_printlog(Config *cfg, char *str){
     if(cfg->flog>0){ /*stdout is 1*/
         fprintf(cfg->flog,"%s\n",str);
     }
}

void mcx_normalize(float field[], float scale, int fieldlen){
     int i;
     for(i=0;i<fieldlen;i++){
         field[i]*=scale;
     }
}

void mcx_error(const int id,const char *msg,const char *file,const int linenum){
     fprintf(stdout,"\nMCX ERROR(%d):%s in unit %s:%d\n",id,msg,file,linenum);
#ifdef MCX_CONTAINER
     mcx_throw_exception(id,msg,file,linenum);
#else
     exit(id);
#endif
}

void mcx_assert(int ret){
     if(!ret) mcx_error(ret,"assert error",__FILE__,__LINE__);
}

void mcx_readconfig(char *fname, Config *cfg){
     if(fname[0]==0){
     	mcx_loadconfig(stdin,cfg);
        if(cfg->session[0]=='\0'){
		strcpy(cfg->session,"default");
	}
     }
     else{
     	FILE *fp=fopen(fname,"rt");
	if(fp==NULL) mcx_error(-2,"can not load the specified config file",__FILE__,__LINE__);
	mcx_loadconfig(fp,cfg); 
	fclose(fp);
        if(cfg->session[0]=='\0'){
		strcpy(cfg->session,fname);
	}
     }
}

void mcx_writeconfig(char *fname, Config *cfg){
     if(fname[0]==0)
     	mcx_saveconfig(stdout,cfg);
     else{
     	FILE *fp=fopen(fname,"wt");
	if(fp==NULL) mcx_error(-2,"can not write to the specified config file",__FILE__,__LINE__);
	mcx_saveconfig(fp,cfg);     
	fclose(fp);
     }
}


void mcx_loadconfig(FILE *in, Config *cfg){
     uint i,gates,idx1d,itmp;
     char filename[MAX_PATH_LENGTH]={0}, comment[MAX_PATH_LENGTH],*comm;
     
     if(in==stdin)
     	fprintf(stdout,"Please specify the total number of photons: [1000000]\n\t");
     mcx_assert(fscanf(in,"%d", &(i) )==1); 
     if(cfg->nphoton==0) cfg->nphoton=i;
     comm=fgets(comment,MAX_PATH_LENGTH,in);
     if(in==stdin)
     	fprintf(stdout,"%d\nPlease specify the random number generator seed: [1234567]\n\t",cfg->nphoton);
     if(cfg->seed==0)
        mcx_assert(fscanf(in,"%d", &(cfg->seed) )==1);
     else
        mcx_assert(fscanf(in,"%d", &itmp )==1);
     comm=fgets(comment,MAX_PATH_LENGTH,in);
     if(in==stdin)
     	fprintf(stdout,"%d\nPlease specify the position of the source: [10 10 5]\n\t",cfg->seed);
     mcx_assert(fscanf(in,"%f %f %f", &(cfg->srcpos.x),&(cfg->srcpos.y),&(cfg->srcpos.z) )==3);
     comm=fgets(comment,MAX_PATH_LENGTH,in);
     if(in==stdin)
     	fprintf(stdout,"%f %f %f\nPlease specify the normal direction of the source fiber: [0 0 1]\n\t",
                                   cfg->srcpos.x,cfg->srcpos.y,cfg->srcpos.z);
     if(!cfg->issrcfrom0){
        cfg->srcpos.x--;cfg->srcpos.y--;cfg->srcpos.z--; /*convert to C index, grid center*/
     }
     mcx_assert(fscanf(in,"%f %f %f", &(cfg->srcdir.x),&(cfg->srcdir.y),&(cfg->srcdir.z) )==3);
     comm=fgets(comment,MAX_PATH_LENGTH,in);
     if(in==stdin)
     	fprintf(stdout,"%f %f %f\nPlease specify the time gates in seconds (start end and step) [0.0 1e-9 1e-10]\n\t",
                                   cfg->srcdir.x,cfg->srcdir.y,cfg->srcdir.z);
     mcx_assert(fscanf(in,"%f %f %f", &(cfg->tstart),&(cfg->tend),&(cfg->tstep) )==3);
     comm=fgets(comment,MAX_PATH_LENGTH,in);

     if(in==stdin)
     	fprintf(stdout,"%f %f %f\nPlease specify the path to the volume binary file:\n\t",
                                   cfg->tstart,cfg->tend,cfg->tstep);
     if(cfg->tstart>cfg->tend || cfg->tstep==0.f){
         mcx_error(-9,"incorrect time gate settings",__FILE__,__LINE__);
     }
     gates=(uint)((cfg->tend-cfg->tstart)/cfg->tstep+0.5);
     if(cfg->maxgate>gates)
	 cfg->maxgate=gates;

     mcx_assert(fscanf(in,"%s", filename)==1);
     if(cfg->rootpath[0]){
#ifdef WIN32
         sprintf(comment,"%s\\%s",cfg->rootpath,filename);
#else
         sprintf(comment,"%s/%s",cfg->rootpath,filename);
#endif
         strncpy(filename,comment,MAX_PATH_LENGTH);
     }
     comm=fgets(comment,MAX_PATH_LENGTH,in);

     if(in==stdin)
     	fprintf(stdout,"%s\nPlease specify the x voxel size (in mm), x dimension, min and max x-index [1.0 100 1 100]:\n\t",filename);
     mcx_assert(fscanf(in,"%f %d %d %d", &(cfg->steps.x),&(cfg->dim.x),&(cfg->crop0.x),&(cfg->crop1.x))==4);
     comm=fgets(comment,MAX_PATH_LENGTH,in);

     if(in==stdin)
     	fprintf(stdout,"%f %d %d %d\nPlease specify the y voxel size (in mm), y dimension, min and max y-index [1.0 100 1 100]:\n\t",
                                  cfg->steps.x,cfg->dim.x,cfg->crop0.x,cfg->crop1.x);
     mcx_assert(fscanf(in,"%f %d %d %d", &(cfg->steps.y),&(cfg->dim.y),&(cfg->crop0.y),&(cfg->crop1.y))==4);
     comm=fgets(comment,MAX_PATH_LENGTH,in);

     if(in==stdin)
     	fprintf(stdout,"%f %d %d %d\nPlease specify the z voxel size (in mm), z dimension, min and max z-index [1.0 100 1 100]:\n\t",
                                  cfg->steps.y,cfg->dim.y,cfg->crop0.y,cfg->crop1.y);
     mcx_assert(fscanf(in,"%f %d %d %d", &(cfg->steps.z),&(cfg->dim.z),&(cfg->crop0.z),&(cfg->crop1.z))==4);
     comm=fgets(comment,MAX_PATH_LENGTH,in);

     if(cfg->sradius>0.f){
     	cfg->crop0.x=MAX((uint)(cfg->srcpos.x-cfg->sradius),0);
     	cfg->crop0.y=MAX((uint)(cfg->srcpos.y-cfg->sradius),0);
     	cfg->crop0.z=MAX((uint)(cfg->srcpos.z-cfg->sradius),0);
     	cfg->crop1.x=MIN((uint)(cfg->srcpos.x+cfg->sradius),cfg->dim.x-1);
     	cfg->crop1.y=MIN((uint)(cfg->srcpos.y+cfg->sradius),cfg->dim.y-1);
     	cfg->crop1.z=MIN((uint)(cfg->srcpos.z+cfg->sradius),cfg->dim.z-1);
     }else if(cfg->sradius==0.f){
     	memset(&(cfg->crop0),0,sizeof(uint3));
     	memset(&(cfg->crop1),0,sizeof(uint3));
     }else{
        /*
           if I define -R with a negative radius, I will use crop0/crop1 to set the cachebox
           nothing need to change here.
        */
     }
     if(in==stdin)
     	fprintf(stdout,"%f %d %d %d\nPlease specify the total types of media:\n\t",
                                  cfg->steps.z,cfg->dim.z,cfg->crop0.z,cfg->crop1.z);
     mcx_assert(fscanf(in,"%d", &(cfg->medianum))==1);
     cfg->medianum++;
     if(cfg->medianum>MAX_PROP)
         mcx_error(-4,"input media types exceed the maximum (255)",__FILE__,__LINE__);
     comm=fgets(comment,MAX_PATH_LENGTH,in);

     if(in==stdin)
     	fprintf(stdout,"%d\n",cfg->medianum);
     cfg->prop=(Medium*)malloc(sizeof(Medium)*cfg->medianum);
     cfg->prop[0].mua=0.f; /*property 0 is already air*/
     cfg->prop[0].mus=0.f;
     cfg->prop[0].g=1.f;
     cfg->prop[0].n=1.f;
     for(i=1;i<cfg->medianum;i++){
        if(in==stdin)
		fprintf(stdout,"Please define medium #%d: mus(1/mm), anisotropy, mua(1/mm) and refractive index: [1.01 0.01 0.04 1.37]\n\t",i);
     	mcx_assert(fscanf(in, "%f %f %f %f", &(cfg->prop[i].mus),&(cfg->prop[i].g),&(cfg->prop[i].mua),&(cfg->prop[i].n))==4);
        comm=fgets(comment,MAX_PATH_LENGTH,in);
        if(in==stdin)
		fprintf(stdout,"%f %f %f %f\n",cfg->prop[i].mus,cfg->prop[i].g,cfg->prop[i].mua,cfg->prop[i].n);
     }
     if(cfg->unitinmm!=1.f){
         for(i=1;i<cfg->medianum;i++){
		cfg->prop[i].mus*=cfg->unitinmm;
		cfg->prop[i].mua*=cfg->unitinmm;
         }
     }
     if(in==stdin)
     	fprintf(stdout,"Please specify the total number of detectors and fiber diameter (in grid unit):\n\t");
     mcx_assert(fscanf(in,"%d %f", &(cfg->detnum), &(cfg->detradius))==2);
     comm=fgets(comment,MAX_PATH_LENGTH,in);
     if(in==stdin)
     	fprintf(stdout,"%d %f\n",cfg->detnum,cfg->detradius);
     cfg->detpos=(float4*)malloc(sizeof(float4)*cfg->detnum);
     if(cfg->issavedet && cfg->detnum==0) 
      	cfg->issavedet=0;
     for(i=0;i<cfg->detnum;i++){
        if(in==stdin)
		fprintf(stdout,"Please define detector #%d: x,y,z (in grid unit): [5 5 5 1]\n\t",i);
     	mcx_assert(fscanf(in, "%f %f %f", &(cfg->detpos[i].x),&(cfg->detpos[i].y),&(cfg->detpos[i].z))==3);
	cfg->detpos[i].w=cfg->detradius*cfg->detradius;
        if(!cfg->issrcfrom0){
		cfg->detpos[i].x--;cfg->detpos[i].y--;cfg->detpos[i].z--;  /*convert to C index*/
	}
        comm=fgets(comment,MAX_PATH_LENGTH,in);
        if(in==stdin)
		fprintf(stdout,"%f %f %f\n",cfg->detpos[i].x,cfg->detpos[i].y,cfg->detpos[i].z);
     }
     if(filename[0]){
        mcx_loadvolume(filename,cfg);
	if(cfg->isrowmajor){
		/*from here on, the array is always col-major*/
		mcx_convertrow2col(&(cfg->vol), &(cfg->dim));
		cfg->isrowmajor=0;
	}
	if(cfg->issavedet)
		mcx_maskdet(cfg);
	if(cfg->srcpos.x<0.f || cfg->srcpos.y<0.f || cfg->srcpos.z<0.f || 
	   cfg->srcpos.x>=cfg->dim.x || cfg->srcpos.y>=cfg->dim.y || cfg->srcpos.z>=cfg->dim.z)
		mcx_error(-4,"source position is outside of the volume",__FILE__,__LINE__);
	idx1d=(int)(floor(cfg->srcpos.z)*cfg->dim.y*cfg->dim.x+floor(cfg->srcpos.y)*cfg->dim.x+floor(cfg->srcpos.x));

        /* if the specified source position is outside the domain, move the source
	   along the initial vector until it hit the domain */
	if(cfg->vol && cfg->vol[idx1d]==0){
                printf("source (%f %f %f) is located outside the domain, vol[%d]=%d\n",
		      cfg->srcpos.x,cfg->srcpos.y,cfg->srcpos.z,idx1d,cfg->vol[idx1d]);
		while(cfg->vol[idx1d]==0){
			cfg->srcpos.x+=cfg->srcdir.x;
			cfg->srcpos.y+=cfg->srcdir.y;
			cfg->srcpos.z+=cfg->srcdir.z;
			idx1d=(int)(floor(cfg->srcpos.z)*cfg->dim.y*cfg->dim.x+floor(cfg->srcpos.y)*cfg->dim.x+floor(cfg->srcpos.x));
		}
		printf("fixing source position to (%f %f %f)\n",cfg->srcpos.x,cfg->srcpos.y,cfg->srcpos.z);
	}
     }else{
     	mcx_error(-4,"one must specify a binary volume file in order to run the simulation",__FILE__,__LINE__);
     }
     cfg->his.maxmedia=cfg->medianum-1; /*skip media 0*/
     cfg->his.detnum=cfg->detnum;
     cfg->his.colcount=cfg->medianum+1; /*column count=maxmedia+2*/
}

void mcx_saveconfig(FILE *out, Config *cfg){
     uint i;

     fprintf(out,"%d\n", (cfg->nphoton) ); 
     fprintf(out,"%d\n", (cfg->seed) );
     fprintf(out,"%f %f %f\n", (cfg->srcpos.x),(cfg->srcpos.y),(cfg->srcpos.z) );
     fprintf(out,"%f %f %f\n", (cfg->srcdir.x),(cfg->srcdir.y),(cfg->srcdir.z) );
     fprintf(out,"%e %e %e\n", (cfg->tstart),(cfg->tend),(cfg->tstep) );
     fprintf(out,"%f %d %d %d\n", (cfg->steps.x),(cfg->dim.x),(cfg->crop0.x),(cfg->crop1.x));
     fprintf(out,"%f %d %d %d\n", (cfg->steps.y),(cfg->dim.y),(cfg->crop0.y),(cfg->crop1.y));
     fprintf(out,"%f %d %d %d\n", (cfg->steps.z),(cfg->dim.z),(cfg->crop0.z),(cfg->crop1.z));
     fprintf(out,"%d\n", (cfg->medianum));
     for(i=0;i<cfg->medianum;i++){
     	fprintf(out, "%f %f %f %f\n", (cfg->prop[i].mus),(cfg->prop[i].g),(cfg->prop[i].mua),(cfg->prop[i].n));
     }
     fprintf(out,"%d", (cfg->detnum));
     for(i=0;i<cfg->detnum;i++){
     	fprintf(out, "%f %f %f %f\n", (cfg->detpos[i].x),(cfg->detpos[i].y),(cfg->detpos[i].z),(cfg->detpos[i].w));
     }
}

void mcx_loadvolume(char *filename,Config *cfg){
     unsigned int i,datalen,res;
     FILE *fp=fopen(filename,"rb");
     if(fp==NULL){
     	     mcx_error(-5,"the specified binary volume file does not exist",__FILE__,__LINE__);
     }
     if(cfg->vol){
     	     free(cfg->vol);
     	     cfg->vol=NULL;
     }
     datalen=cfg->dim.x*cfg->dim.y*cfg->dim.z;
     cfg->vol=(unsigned char*)malloc(sizeof(unsigned char)*datalen);
     res=fread(cfg->vol,sizeof(unsigned char),datalen,fp);
     fclose(fp);
     if(res!=datalen){
     	 mcx_error(-6,"file size does not match specified dimensions",__FILE__,__LINE__);
     }
     for(i=0;i<datalen;i++){
         if(cfg->vol[i]>=cfg->medianum)
            mcx_error(-6,"medium index exceeds the specified medium types",__FILE__,__LINE__);
     }
}

void  mcx_convertrow2col(unsigned char **vol, uint3 *dim){
     uint x,y,z;
     unsigned int dimxy,dimyz;
     unsigned char *newvol=NULL;
     
     if(*vol==NULL || dim->x==0 || dim->y==0 || dim->z==0){
     	return;
     }     
     newvol=(unsigned char*)malloc(sizeof(unsigned char)*dim->x*dim->y*dim->z);
     dimxy=dim->x*dim->y;
     dimyz=dim->y*dim->z;
     for(x=0;x<dim->x;x++)
      for(y=0;y<dim->y;y++)
       for(z=0;z<dim->z;z++){
       		newvol[z*dimxy+y*dim->x+x]=*vol[x*dimyz+y*dim->z+z];
       }
     free(*vol);
     *vol=newvol;
}

void  mcx_maskdet(Config *cfg){
     uint d,dx,dy,dz,idx1d,zi,yi;
     float x,y,z,ix,iy,iz;
     unsigned char *padvol;
     
     dx=cfg->dim.x+2;
     dy=cfg->dim.y+2;
     dz=cfg->dim.z+2;

     /*handling boundaries in a volume search is tedious, I first pad vol by a layer of zeros,
       then I don't need to worry about boundaries any more*/

     padvol=(unsigned char*)calloc(dx*dy,dz);

     for(zi=1;zi<=cfg->dim.z;zi++)
        for(yi=1;yi<=cfg->dim.y;yi++)
	        memcpy(padvol+zi*dy*dx+yi*dx+1,cfg->vol+(zi-1)*cfg->dim.y*cfg->dim.x+(yi-1)*cfg->dim.x,cfg->dim.x);

     for(d=0;d<cfg->detnum;d++)                              /*loop over each detector*/
        for(z=-cfg->detpos[d].w;z<=cfg->detpos[d].w;z++){   /*search in a sphere*/
           iz=z+cfg->detpos[d].z; /*1.5=1+0.5, 1 comes from the padding layer, 0.5 move to voxel center*/
           for(y=-cfg->detpos[d].w;y<=cfg->detpos[d].w;y++){
              iy=y+cfg->detpos[d].y;
              for(x=-cfg->detpos[d].w;x<=cfg->detpos[d].w;x++){
	         ix=x+cfg->detpos[d].x;

		 if(iz<0||ix<0||iy<0||ix>=cfg->dim.x||iy>=cfg->dim.y||iz>=cfg->dim.z||
		    x*x+y*y+z*z > (cfg->detpos[d].w+1.f)*(cfg->detpos[d].w+1.f))
		    continue;

		 idx1d=(int)((iz+1.f)*dy*dx+(iy+1.f)*dx+(ix+1.f));

		 if(padvol[idx1d])  /*looking for a voxel on the interface or bounding box*/
                  if(!(padvol[idx1d+1]&&padvol[idx1d-1]&&padvol[idx1d+dx]&&padvol[idx1d-dx]&&padvol[idx1d+dy*dx]&&padvol[idx1d-dy*dx]&&
		     padvol[idx1d+dx+1]&&padvol[idx1d+dx-1]&&padvol[idx1d-dx+1]&&padvol[idx1d-dx-1]&&
		     padvol[idx1d+dy*dx+1]&&padvol[idx1d+dy*dx-1]&&padvol[idx1d-dy*dx+1]&&padvol[idx1d-dy*dx-1]&&
		     padvol[idx1d+dy*dx+dx]&&padvol[idx1d+dy*dx-dx]&&padvol[idx1d-dy*dx+dx]&&padvol[idx1d-dy*dx-dx]&&
		     padvol[idx1d+dy*dx+dx+1]&&padvol[idx1d+dy*dx+dx-1]&&padvol[idx1d+dy*dx-dx+1]&&padvol[idx1d+dy*dx-dx-1]&&
		     padvol[idx1d-dy*dx+dx+1]&&padvol[idx1d-dy*dx+dx-1]&&padvol[idx1d-dy*dx-dx+1]&&padvol[idx1d-dy*dx-dx-1])){
		          cfg->vol[(int)(iz*cfg->dim.y*cfg->dim.x+iy*cfg->dim.x+ix)]|=(1<<7);/*set the highest bit to 1*/
	          }
	      }
	  }
     }

     if(cfg->isdumpmask){
     	 char fname[MAX_PATH_LENGTH];
	 FILE *fp;
	 sprintf(fname,"%s.mask",cfg->session);
	 if((fp=fopen(fname,"wb"))==NULL){
	 	mcx_error(-10,"can not save mask file",__FILE__,__LINE__);
	 }
	 if(fwrite(cfg->vol,cfg->dim.x*cfg->dim.y,cfg->dim.z,fp)!=cfg->dim.z){
	 	mcx_error(-10,"can not save mask file",__FILE__,__LINE__);
	 }
	 fclose(fp);
         free(padvol);
	 exit(0);
     }
     free(padvol);
}

int mcx_readarg(int argc, char *argv[], int id, void *output,const char *type){
     /*
         when a binary option is given without a following number (0~1), 
         we assume it is 1
     */
     if(strcmp(type,"char")==0 && (id>=argc-1||(argv[id+1][0]<'0'||argv[id+1][0]>'9'))){
	*((char*)output)=1;
	return id;
     }
     if(id<argc-1){
         if(strcmp(type,"char")==0)
             *((char*)output)=atoi(argv[id+1]);
	 else if(strcmp(type,"int")==0)
             *((int*)output)=atoi(argv[id+1]);
	 else if(strcmp(type,"float")==0)
             *((float*)output)=atof(argv[id+1]);
	 else if(strcmp(type,"string")==0)
	     strcpy((char *)output,argv[id+1]);
     }else{
     	 mcx_error(-1,"incomplete input",__FILE__,__LINE__);
     }
     return id+1;
}
int mcx_remap(char *opt){
    int i=0;
    while(shortopt[i]!='\0'){
	if(strcmp(opt,fullopt[i])==0){
		opt[1]=shortopt[i];
		opt[2]='\0';
		return 0;
	}
	i++;
    }
    return 1;
}
void mcx_parsecmd(int argc, char* argv[], Config *cfg){
     int i=1,isinteractive=1,issavelog=0;
     char filename[MAX_PATH_LENGTH]={0};
     char logfile[MAX_PATH_LENGTH]={0};
     float np=0.f;

     if(argc<=1){
     	mcx_usage(argv[0]);
     	exit(0);
     }
     while(i<argc){
     	    if(argv[i][0]=='-'){
		if(argv[i][1]=='-'){
			if(mcx_remap(argv[i])){
				mcx_error(-2,"unknown verbose option",__FILE__,__LINE__);
			}
		}
	        switch(argv[i][1]){
		     case 'h': 
		                mcx_usage(argv[0]);
				exit(0);
		     case 'i':
				if(filename[0]){
					mcx_error(-2,"you can not specify both interactive mode and config file",__FILE__,__LINE__);
				}
		     		isinteractive=1;
				break;
		     case 'f': 
		     		isinteractive=0;
		     	        i=mcx_readarg(argc,argv,i,filename,"string");
				break;
		     case 'm':
                                /*from rev 191, we have enabled -n and disabled -m*/
				mcx_error(-2,"specifying photon move is not supported any more, please use -n",__FILE__,__LINE__);
		     	        i=mcx_readarg(argc,argv,i,&(cfg->nphoton),"int");
		     	        break;
		     case 'n':
		     	        i=mcx_readarg(argc,argv,i,&(np),"float");
				cfg->nphoton=(int)np;
		     	        break;
		     case 't':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->nthread),"int");
		     	        break;
                     case 'T':
                               	i=mcx_readarg(argc,argv,i,&(cfg->nblocksize),"int");
                               	break;
		     case 's':
		     	        i=mcx_readarg(argc,argv,i,cfg->session,"string");
		     	        break;
		     case 'a':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->isrowmajor),"char");
		     	        break;
		     case 'g':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->maxgate),"int");
		     	        break;
		     case 'b':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->isreflect),"char");
				cfg->isref3=cfg->isreflect;
		     	        break;
                     case 'B':
                                i=mcx_readarg(argc,argv,i,&(cfg->isrefint),"char");
                               	break;
		     case 'd':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->issavedet),"char");
		     	        break;
		     case 'r':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->respin),"int");
		     	        break;
		     case 'S':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->issave2pt),"char");
		     	        break;
		     case 'p':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->printnum),"int");
		     	        break;
                     case 'e':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->minenergy),"float");
                                break;
		     case 'U':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->isnormalized),"char");
		     	        break;
                     case 'R':
                                i=mcx_readarg(argc,argv,i,&(cfg->sradius),"float");
                                break;
                     case 'u':
                                i=mcx_readarg(argc,argv,i,&(cfg->unitinmm),"float");
                                break;
                     case 'l':
                                issavelog=1;
                                break;
		     case 'L':
                                cfg->isgpuinfo=2;
		                break;
		     case 'I':
                                cfg->isgpuinfo=1;
		                break;
		     case 'o':
		     	        i=mcx_readarg(argc,argv,i,cfg->rootpath,"string");
		     	        break;
                     case 'G':
                                i=mcx_readarg(argc,argv,i,&(cfg->gpuid),"int");
                                break;
                     case 'z':
                                i=mcx_readarg(argc,argv,i,&(cfg->issrcfrom0),"char");
                                break;
		     case 'M':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->isdumpmask),"char");
		     	        break;
		     case 'H':
		     	        i=mcx_readarg(argc,argv,i,&(cfg->maxdetphoton),"int");
		     	        break;
                     case 'A':
                                i=mcx_readarg(argc,argv,i,&(cfg->autopilot),"char");
                                break;
                     case 'E':
                                i=mcx_readarg(argc,argv,i,&(cfg->seed),"int");
                                break;
                     case 'v':
                                mcx_version(cfg);
				break;
		}
	    }
	    i++;
     }
     if(issavelog && cfg->session){
          sprintf(logfile,"%s.log",cfg->session);
          cfg->flog=fopen(logfile,"wt");
          if(cfg->flog==NULL){
		cfg->flog=stdout;
		fprintf(cfg->flog,"unable to save to log file, will print from stdout\n");
          }
     }
     if(cfg->isgpuinfo!=2){ /*print gpu info only*/
       if(isinteractive){
          mcx_readconfig((char*)"",cfg);
       }else{
     	  mcx_readconfig(filename,cfg);
       }
     }
}

void mcx_version(Config *cfg){
    const char ver[]="$Rev:: 237  $";
    int v=0;
    sscanf(ver,"$Rev::%d",&v);
    fprintf(cfg->flog, "MCX Revision %d\n",v);
    exit(0);
}

void mcx_usage(char *exename){
     printf("\
###############################################################################\n\
#                      Monte Carlo eXtreme (MCX) -- CUDA                      #\n\
#     Copyright (c) 2009-2011 Qianqian Fang <fangq at nmr.mgh.harvard.edu>    #\n\
#                                                                             #\n\
#    Martinos Center for Biomedical Imaging, Massachusetts General Hospital   #\n\
###############################################################################\n\
$MCX $Rev:: 237 $ Last Commit $Date:: 2011-04-26 05:48:22#$ by $Author:: fangq$\n\
###############################################################################\n\
\n\
usage: %s <param1> <param2> ...\n\
where possible parameters include (the first item in [] is the default value)\n\
 -i 	       (--interactive) interactive mode\n\
 -s sessionid  (--session)     a string to label all output file names\n\
 -f config     (--input)       read config from a file\n\
 -n [0|int]    (--photon)      total photon number (exponential form accepted)\n\
 -m [0|int]    (--move)        photon moves/thread(not supported, use -n only)\n\
 -t [2048|int] (--thread)      total thread number\n\
 -T [64|int]   (--blocksize)   thread number per block\n\
 -A [0|int]    (--autopilot)   auto thread config:1-dedicated GPU,2-non-dedic.\n\
 -G [0|int]    (--gpu)         specify which GPU to use, list GPU by -L, 0 auto\n\
 -r [1|int]    (--repeat)      number of repetitions\n\
 -a [0|1]      (--array)       1 for C array (row-major), 0 for Matlab array\n\
 -z [0|1]      (--srcfrom0)    1 src/detector coord. start from 0, 0 go from 1\n\
 -g [1|int]    (--gategroup)   number of time gates per run\n\
 -b [1|0]      (--reflect)     1 to reflect photons at ext. boundary,0 to exit\n\
 -B [0|1]      (--reflectin)   1 to reflect photons at int. boundary, 0 do not\n\
 -e [0.|float] (--minenergy)   minimum energy level to terminate a photon\n\
 -R [0.|float] (--skipradius)  zone half-edge from source for improved accuracy\n\
 -u [1.|float] (--unitinmm)    defines the length unit for the grid edge\n\
 -U [1|0]      (--normalize)   1 to normalize flux to unitary, 0 save raw\n\
 -d [1|0]      (--savedet)     1 to save photon info at detectors, 0 not save\n\
 -M [0|1]      (--dumpmask)    1 to dump detector volume masks, 0 do not save\n\
 -H [1000000]  (--maxdetphoton)max number of detected photons\n\
 -S [1|0]      (--save2pt)     1 to save the flux field, 0 do not save\n\
 -E [0|int]    (--seed)        set random-number-generator seed\n\
 -h            (--help)        print this message\n\
 -l            (--log)         print messages to a log file instead\n\
 -L            (--listgpu)     print GPU information only\n\
 -I            (--printgpu)    print GPU information and run program\n\
 -v            (--version)     print MCX revision number\n\
example:\n\
       %s -t 2048 -T 64 -n 1e7 -f input.inp -s test -r 2 -g 10 -U 0 -d 1 -G 1\n",exename,exename);
}
