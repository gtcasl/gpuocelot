
#include <stdio.h>
#include <stdlib.h>
#include "backprop.h"



load(net)
BPNN *net;
{
  float *units;
  int nr, nc, imgsize, i, j, k;

  nr = NPOINTS;

  imgsize = nr * nc;
  units = net->input_units;

  k = 1;
  for (i = 0; i < nr; i++) {
	  units[k] = (float) rand()/RAND_MAX ;
	  k++;
    }
}
