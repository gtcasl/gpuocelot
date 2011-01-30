/***************************************************************************
 *cr
 *cr            (C) Copyright 2007 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/
#ifndef _PETRI_H_
#define _PETRI_H_

#define MAX_DEVICE_MEM 750000000

__global__ void PetrinetKernel(int* g_places, int n, int s, int t);


#endif // _PETRI_H_

