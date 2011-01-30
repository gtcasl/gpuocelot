/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
#include <math.h>

#include "model.h"

int readdatafile(char *fname, struct cartesian *data, int npoints)
{
  FILE *infile;
  int lcount = 0;
  float ra, dec;

  if(fname == 0)
  {
      fprintf(stderr, "Unable to open data file for reading\n");
      exit(0);	
  }

  if ((infile = fopen(fname, "r")) == NULL)
    {
      fprintf(stderr, "Unable to open data file %s for reading\n", fname);
      exit(0);
    }

  for (lcount = 0; lcount < npoints; lcount++)
    {
      if (fscanf(infile, "%f %f", &ra, &dec) != 2)
	break;

      {
        // data conversion
        float rarad = D2R * ra;
        float decrad = D2R * dec;
        float cd = cos(decrad);
	
	data[lcount].x = cos(rarad) * cd;
	data[lcount].y = sin(rarad) * cd;
	data[lcount].z = sin(decrad);
      }
    }

  fclose(infile);
  
  return lcount;
}

