

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "backprop.h"
#include "omp.h"

extern char *strcpy();
extern void exit();

backprop_face()
{
  BPNN *net;
  int i, layer_size;
  float out_err, hid_err;
  layer_size = NPOINTS;
  net = bpnn_create(layer_size, 16, 1); // (16, 1 can not be changed)
  printf("Input layer size : %d\n", layer_size);
  load(net);
  //entering the training kernel, only one iteration
  bpnn_train_cuda(net, 0.3, 0.3, &out_err, &hid_err);
  bpnn_free(net);
}

int setup(argc, argv)
int argc;
char *argv[];
{

  int seed;

  seed = 7;   
  bpnn_initialize(seed);
  backprop_face();

  exit(0);
}
