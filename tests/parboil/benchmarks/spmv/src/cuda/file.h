/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

void inputData(char* fName, int* len, int* depth, int* dim,int *nzcnt_len,int *pad,
               float** h_data, int** h_indices, int** h_ptr,
               int** h_perm, int** h_nzcnt);

void outputData(char* fName, float *h_Ax_vector,int dim);
