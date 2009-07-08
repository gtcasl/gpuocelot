/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>

#include "args.h"
#include "model.h"

int main( int argc, char **argv )
{
  struct pb_TimerSet timers;
  struct pb_Parameters *params;
  int rf, k, nbins, npd, npr;
  float *binb, w;
  long long *DD, *RRS, *DRS;
  size_t memsize;
  struct cartesian *data, *random;
  FILE *outfile;

  pb_InitializeTimerSet( &timers );
  params = pb_ReadParameters( &argc, argv );

  options args;
  parse_args( argc, argv, &args );
    
  pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );
  nbins = (int)floor(bins_per_dec * (log10(max_arcmin) - 
					 log10(min_arcmin)));
  memsize = (nbins+2)*sizeof(long long);
    
  // memory for bin boundaries
  binb = (float *)malloc((nbins+1)*sizeof(float));
  if (binb == NULL)
    {
      fprintf(stderr, "Unable to allocate memory\n");
      exit(-1);
    }
  for (k = 0; k < nbins+1; k++)
    {
      binb[k] = cos(pow(10, log10(min_arcmin) + 
			k*1.0/bins_per_dec) / 60.0*D2R);
      printf("%f\n", binb[k]);
    }
    
  // memory for DD
  DD = (long long*)malloc(memsize);
  if (DD == NULL)
    {
      fprintf(stderr, "Unable to allocate memory\n");
      exit(-1);
    }
  bzero(DD, memsize);
    
  // memory for RR
  RRS = (long long*)malloc(memsize);
  if (RRS == NULL)
    {
      fprintf(stderr, "Unable to allocate memory\n");
      exit(-1);
    }
  bzero(RRS, memsize);
    
  // memory for DR
  DRS = (long long*)malloc(memsize);
  if (DRS == NULL)
    {
      fprintf(stderr, "Unable to allocate memory\n");
      exit(-1);
    }
  bzero(DRS, memsize);
    
  // memory for input data
  data = (struct cartesian*)malloc
    (args.npoints* sizeof(struct cartesian));
  if (data == NULL)
    {
      fprintf(stderr, 
	      "Unable to allocate memory for % data points (#1)\n", 
	      args.npoints);
      return(0);
    }
    
  random = (struct cartesian*)malloc
    (args.npoints*sizeof(struct cartesian));
  if (random == NULL)
    {
      fprintf(stderr, 
	      "Unable to allocate memory for % data points (#2)\n", 
	      args.npoints);
      return(0);
    }

  printf("Min distance: %f arcmin\n", min_arcmin);
  printf("Max distance: %f arcmin\n", max_arcmin);
  printf("Bins per dec: %i\n", bins_per_dec);
  printf("Total bins  : %i\n", nbins);

  // read data file
  pb_SwitchToTimer( &timers, pb_TimerID_IO );
  npd = readdatafile(params->inpFiles[0], data, args.npoints);
  pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );
  if (npd != args.npoints)
    {
      fprintf(stderr, 
	      "Error: read %i data points out of %i\n", 
	      npd, args.npoints);
      return(0);
    }

  // compute DD
  doCompute(data, npd, NULL, 0, 1, DD, nbins, binb);

  // loop through random data files
  for (rf = 0; rf < args.random_count; rf++)
    {
      // read random file
      pb_SwitchToTimer( &timers, pb_TimerID_IO );
      npr = readdatafile(params->inpFiles[rf+1], random, args.npoints);
      pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );
      if (npr != args.npoints)
        {
	  fprintf(stderr, 
		  "Error: read %i random points out of %i in file %s\n", 
		  npr, args.npoints, params->inpFiles[rf+1]);
	  return(0);
        }

      // compute RR
      doCompute(random, npr, NULL, 0, 1, RRS, nbins, binb);

      // compute DR
      doCompute(data, npd, random, npr, 0, DRS, nbins, binb);
    }

  // compute and output results
  if ((outfile = fopen(params->outFile, "w")) == NULL)
    {
      fprintf(stderr, 
	      "Unable to open output file %s for writing, assuming stdout\n", 
	      params->outFile);
      outfile = stdout;
    }

  for (k = 1; k < nbins+1; k++)
    {
      w = (100.0 * DD[k] - DRS[k]) / RRS[k] + 1.0;
      pb_SwitchToTimer( &timers, pb_TimerID_IO );
      fprintf(outfile, "%f\n", w);
      pb_SwitchToTimer( &timers, pb_TimerID_COMPUTE );
    }

  if(outfile != stdout)
    fclose(outfile);

  // free memory
  free(data);
  free(random);
  free(binb);
  free(DD);
  free(RRS);
  free(DRS);
  
  pb_SwitchToTimer( &timers, pb_TimerID_NONE );
  pb_PrintTimerSet( &timers );
  pb_FreeParameters( params );
}

