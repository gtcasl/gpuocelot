/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

void CUDA_interface (
  struct pb_TimerSet* timers,
  unsigned int n,       // Number of input elements
  parameters params,    // Parameter struct which defines output gridSize, cutoff distance, etc.
  ReconstructionSample* sample, // Array of input elements
  float* LUT,           // Precomputed LUT table of Kaiser-Bessel function. 
                          // Used for computation on CPU instead of using the function every time
  int sizeLUT,          // Size of LUT
  cmplx* gridData,      // Array of output grid points. Each element has a real and imaginary component
  float* sampleDensity  // Array of same size as gridData couting the number of contributions
                          // to each grid point in the gridData array
);
