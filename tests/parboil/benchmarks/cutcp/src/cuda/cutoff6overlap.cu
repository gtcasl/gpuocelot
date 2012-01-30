/***************************************************************************
 *cr
 *cr            (C) Copyright 2008-2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "atom.h"
#include "cutoff.h"
#include "parboil.h"

#ifdef __DEVICE_EMULATION__
#define DEBUG
/* define which grid block and which thread to examine */
#define BX  0
#define BY  0
#define TX  0
#define TY  0
#define TZ  0
#define EMU(code) do { \
  if (blockIdx.x==BX && blockIdx.y==BY && \
      threadIdx.x==TX && threadIdx.y==TY && threadIdx.z==TZ) { \
    code; \
  } \
} while (0)
#define INT(n)    printf("%s = %d\n", #n, n)
#define FLOAT(f)  printf("%s = %g\n", #f, (double)(f))
#define INT3(n)   printf("%s = %d %d %d\n", #n, (n).x, (n).y, (n).z)
#define FLOAT4(f) printf("%s = %g %g %g %g\n", #f, (double)(f).x, \
    (double)(f).y, (double)(f).z, (double)(f).w)
#else
#define EMU(code)
#define INT(n)
#define FLOAT(f)
#define INT3(n)
#define FLOAT4(f)
#endif

/* report error from CUDA */
#define CUERR \
  do { \
    cudaError_t err; \
    if ((err = cudaGetLastError()) != cudaSuccess) { \
      printf("CUDA error: %s, line %d\n", cudaGetErrorString(err), __LINE__); \
      return -1; \
    } \
  } while (0)

/*
 * neighbor list:
 * stored in constant memory as table of offsets
 * flat index addressing is computed by kernel
 *
 * reserve enough memory for 11^3 stencil of grid cells
 * this fits within 16K of memory
 */
#define NBRLIST_DIM  11
#define NBRLIST_MAXLEN (NBRLIST_DIM * NBRLIST_DIM * NBRLIST_DIM)
__constant__ int NbrListLen;
__constant__ int3 NbrList[NBRLIST_MAXLEN];


/* Normally, we're summing electrostatic potential.  However, for
 * profiling we may want to appropriate this storage to count the
 * number of nearby atoms, instead.
 */
#undef NEIGHBOR_COUNT
 
#ifndef NEIGHBOR_COUNT
typedef float ener_t;
#else
typedef int ener_t;
#endif

/*
 * atom bins cached into shared memory for processing
 *
 * this reserves 4K of shared memory for 32 atom bins each containing 8 atoms,
 * should permit scheduling of up to 3 thread blocks per SM
 */
#define BIN_DEPTH         8  /* max number of atoms per bin */
#define BIN_SIZE         32  /* size of bin in floats */
#define BIN_SHIFT         5  /* # of bits to shift for mul/div by BIN_SIZE */
#define BIN_CACHE_MAXLEN 32  /* max number of atom bins to cache */

#define BIN_LENGTH      4.f  /* spatial length in Angstroms */
#define BIN_INVLEN  (1.f / BIN_LENGTH)
/* assuming density of 1 atom / 10 A^3, expectation is 6.4 atoms per bin
 * so that bin fill should be 80% (for non-empty regions of space) */

#define REGION_SIZE     512  /* number of floats in lattice region */

/*
 * potential lattice is decomposed into size 8^3 lattice point "regions"
 *
 * THIS IMPLEMENTATION:  one thread per lattice point
 * thread block size 128 gives 4 thread blocks per region
 * kernel is invoked for each x-y plane of regions,
 * where gridDim.x is 4*(x region dimension) so that blockIdx.x 
 * can absorb the z sub-region index in its 2 lowest order bits
 *
 * Regions are stored contiguously in memory in row-major order
 *
 * The bins have to not only cover the region, but they need to surround
 * the outer edges so that region sides and corners can still use
 * neighbor list stencil.  The binZeroAddr is actually a shifted pointer into
 * the bin array (binZeroAddr = binBaseAddr + (c*binDim_y + c)*binDim_x + c)
 * where c = ceil(cutoff / binsize).  This allows for negative offsets to
 * be added to myBinIndex.
 *
 * The (0,0,0) spatial origin corresponds to lower left corner of both
 * regionZeroAddr and binZeroAddr.  The atom coordinates are translated
 * during binning to enforce this assumption.
 */
__global__ static void cuda_cutoff_potential_lattice6overlap(
    int binDim_x,
    int binDim_y,
    float4 *binZeroAddr,    /* address of atom bins starting at origin */
    float h,                /* lattice spacing */
    float cutoff2,          /* square of cutoff distance */
    float inv_cutoff2,
    ener_t *regionZeroAddr, /* address of lattice regions starting at origin */
    int zRegionIndex
    )
{
  __shared__ float AtomBinCache[BIN_CACHE_MAXLEN * BIN_DEPTH * 4];
  __shared__ ener_t *myRegionAddr;
  __shared__ int3 myBinIndex;

  const int xRegionIndex = blockIdx.x;
  const int yRegionIndex = blockIdx.y;

  /* thread id */
  const int tid = (threadIdx.z*blockDim.y + threadIdx.y)*blockDim.x
    + threadIdx.x;
  /* blockDim.x == 8, blockDim.y == 2, blockDim.z == 8 */

  /* neighbor index */
  int nbrid;

  /* this is the start of the sub-region indexed by tid */
  myRegionAddr = regionZeroAddr + ((zRegionIndex*gridDim.y
        + yRegionIndex)*gridDim.x + xRegionIndex)*REGION_SIZE;
    
  /* spatial coordinate of this lattice point */
  float x = (8 * xRegionIndex + threadIdx.x) * h;
  float y = (8 * yRegionIndex + threadIdx.y) * h;
  float z = (8 * zRegionIndex + threadIdx.z) * h;

  int totalbins = 0;
  int numbins;

  /* bin number determined by center of region */
  myBinIndex.x = (int) floorf((8 * xRegionIndex + 4) * h * BIN_INVLEN);
  myBinIndex.y = (int) floorf((8 * yRegionIndex + 4) * h * BIN_INVLEN);
  myBinIndex.z = (int) floorf((8 * zRegionIndex + 4) * h * BIN_INVLEN);

  /* first neighbor in list for me to cache */
  nbrid = (tid >> 4);

  numbins = BIN_CACHE_MAXLEN;

#ifndef NEIGHBOR_COUNT
  ener_t energy0 = 0.f;
  ener_t energy1 = 0.f;
  ener_t energy2 = 0.f;
  ener_t energy3 = 0.f;
#else
  ener_t energy0 = 0, energy1 = 0, energy2 = 0, energy3 = 0;
#endif

  for (totalbins = 0;  totalbins < NbrListLen;  totalbins += numbins) {
    int bincnt;

    /* start of where to write in shared memory */
    int startoff = BIN_SIZE * (tid >> 4);

    /* each half-warp to cache up to 4 atom bins */
    for (bincnt = 0;  bincnt < 4 && nbrid < NbrListLen;  bincnt++, nbrid += 8) {
      int i = myBinIndex.x + NbrList[nbrid].x;
      int j = myBinIndex.y + NbrList[nbrid].y;
      int k = myBinIndex.z + NbrList[nbrid].z;

      /* determine global memory location of atom bin */
      float *p_global = ((float *) binZeroAddr)
        + (((__mul24(k, binDim_y) + j)*binDim_x + i) << BIN_SHIFT);

      /* coalesced read from global memory -
       * retain same ordering in shared memory for now */
      int binIndex = startoff + (bincnt << (3 + BIN_SHIFT));
      int tidmask = tid & 15;

      AtomBinCache[binIndex + tidmask   ] = p_global[tidmask   ];
      AtomBinCache[binIndex + tidmask+16] = p_global[tidmask+16];
    }
    __syncthreads();

    /* no warp divergence */
    if (totalbins + BIN_CACHE_MAXLEN > NbrListLen) {
      numbins = NbrListLen - totalbins;
    }

    int stopbin = (numbins << BIN_SHIFT);
    for (bincnt = 0; bincnt < stopbin; bincnt+=BIN_SIZE) {
      int i;

      for (i = 0;  i < BIN_DEPTH;  i++) {
        int off = bincnt + (i<<2);

        float aq = AtomBinCache[off + 3];
        if (0.f == aq) 
          break;  /* no more atoms in bin */

        float dx = AtomBinCache[off    ] - x;
        float dz = AtomBinCache[off + 2] - z;
        float dxdz2 = dx*dx + dz*dz;
        float dy = AtomBinCache[off + 1] - y;
        float r2 = dy*dy + dxdz2;

#ifndef NEIGHBOR_COUNT
        if (r2 < cutoff2)
	  {
          float s = (1.f - r2 * inv_cutoff2);
          energy0 += aq * rsqrtf(r2) * s * s;
        }
#else
	energy0 += (r2 < cutoff2);
#endif
        dy -= 2.0f*h;
        r2 = dy*dy + dxdz2;
#ifndef NEIGHBOR_COUNT
	if (r2 < cutoff2)
	  {
          float s = (1.f - r2 * inv_cutoff2);
          energy1 += aq * rsqrtf(r2) * s * s;
        }
#else
	energy1 += (r2 < cutoff2);
#endif
        dy -= 2.0f*h;
        r2 = dy*dy + dxdz2;
#ifndef NEIGHBOR_COUNT
        if (r2 < cutoff2)
	  {
          float s = (1.f - r2 * inv_cutoff2);
          energy2 += aq * rsqrtf(r2) * s * s;
        }
#else
	energy2 += (r2 < cutoff2);
#endif
        dy -= 2.0f*h;
        r2 = dy*dy + dxdz2;
#ifndef NEIGHBOR_COUNT
        if (r2 < cutoff2)
	  {
          float s = (1.f - r2 * inv_cutoff2);
          energy3 += aq * rsqrtf(r2) * s * s;
        }
#else
	energy3 += (r2 < cutoff2);
#endif
      } /* end loop over atoms in bin */
    } /* end loop over cached atom bins */
    __syncthreads();

  } /* end loop over neighbor list */

  /* store into global memory */
  myRegionAddr[(tid>>4)*64 + (tid&15)     ] = energy0;
  myRegionAddr[(tid>>4)*64 + (tid&15) + 16] = energy1;
  myRegionAddr[(tid>>4)*64 + (tid&15) + 32] = energy2;
  myRegionAddr[(tid>>4)*64 + (tid&15) + 48] = energy3;
}




extern "C" int gpu_compute_cutoff_potential_lattice6overlap(
    struct pb_TimerSet *timers,        /* for measuring execution time */
    Lattice *lattice,
    float cutoff,                      /* cutoff distance */
    Atoms *atoms,                      /* array of atoms */
    int verbose                        /* print info/debug messages */
    )
{
  int nx = lattice->dim.nx;
  int ny = lattice->dim.ny;
  int nz = lattice->dim.nz;
  float xlo = lattice->dim.lo.x;
  float ylo = lattice->dim.lo.y;
  float zlo = lattice->dim.lo.z;
  float h = lattice->dim.h;
  int natoms = atoms->size;
  Atom *atom = atoms->atoms;

  int3 nbrlist[NBRLIST_MAXLEN];
  int nbrlistlen = 0;

  int binHistoFull[BIN_DEPTH+1] = { 0 };   /* clear every array element */
  int binHistoCover[BIN_DEPTH+1] = { 0 };  /* clear every array element */
  int num_excluded = 0;

  int xRegionDim, yRegionDim, zRegionDim;
  int xRegionIndex, yRegionIndex, zRegionIndex;
  int xOffset, yOffset, zOffset;
  int lnx, lny, lnz, lnall;
  ener_t *regionZeroAddr, *thisRegion;
  ener_t *regionZeroCuda;
  int index, indexRegion;

  int c;
  int3 binDim;
  int nbins;
  float4 *binBaseAddr, *binZeroAddr;
  float4 *binBaseCuda, *binZeroCuda;
  int *bincntBaseAddr, *bincntZeroAddr;
  Atoms *extra = NULL;

  int i, j, k, n;
  int sum, total;

  float avgFillFull, avgFillCover;
  const float cutoff2 = cutoff * cutoff;
  const float inv_cutoff2 = 1.f / cutoff2;

  dim3 gridDim, blockDim;

#ifdef NEIGHBOR_COUNT
  double neighbor_count = 0;	/* used to profile the number of atoms near a
				 * lattice point */
#endif

  pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);

  /* pad lattice to be factor of 8 in each dimension */
  xRegionDim = (int) ceilf(nx/8.f);
  yRegionDim = (int) ceilf(ny/8.f);
  zRegionDim = (int) ceilf(nz/8.f);

  lnx = 8 * xRegionDim;
  lny = 8 * yRegionDim;
  lnz = 8 * zRegionDim;
  lnall = lnx * lny * lnz;

  /* will receive energies from CUDA */
  regionZeroAddr = (ener_t *) malloc(lnall * sizeof(float));

  /* create bins */
  c = (int) ceil(cutoff * BIN_INVLEN);  /* count extra bins around lattice */
  binDim.x = (int) ceil(lnx * h * BIN_INVLEN) + 2*c;
  binDim.y = (int) ceil(lny * h * BIN_INVLEN) + 2*c;
  binDim.z = (int) ceil(lnz * h * BIN_INVLEN) + 2*c;
  nbins = binDim.x * binDim.y * binDim.z;
  binBaseAddr = (float4 *) calloc(nbins * BIN_DEPTH, sizeof(float4));
  binZeroAddr = binBaseAddr + ((c * binDim.y + c) * binDim.x + c) * BIN_DEPTH;

  bincntBaseAddr = (int *) calloc(nbins, sizeof(int));
  bincntZeroAddr = bincntBaseAddr + (c * binDim.y + c) * binDim.x + c;

  /* create neighbor list */
  if (ceilf(BIN_LENGTH / (8*h)) == floorf(BIN_LENGTH / (8*h))) {
    float s = sqrtf(3);
    float r2 = (cutoff + s*BIN_LENGTH) * (cutoff + s*BIN_LENGTH);
    int cnt = 0;
    /* develop neighbor list around 1 cell */
    if (2*c + 1 > NBRLIST_DIM) {
      fprintf(stderr, "must have cutoff <= %f\n",
          (NBRLIST_DIM-1)/2 * BIN_LENGTH);
      return -1;
    }
    for (k = -c;  k <= c;  k++) {
      for (j = -c;  j <= c;  j++) {
        for (i = -c;  i <= c;  i++) {
          if ((i*i + j*j + k*k)*BIN_LENGTH*BIN_LENGTH >= r2) continue;
          nbrlist[cnt].x = i;
          nbrlist[cnt].y = j;
          nbrlist[cnt].z = k;
          cnt++;
        }
      }
    }
    nbrlistlen = cnt;
  }
  else if (8*h <= 2*BIN_LENGTH) {
    float s = 2.f*sqrtf(3);
    float r2 = (cutoff + s*BIN_LENGTH) * (cutoff + s*BIN_LENGTH);
    int cnt = 0;
    /* develop neighbor list around 3-cube of cells */
    if (2*c + 3 > NBRLIST_DIM) {
      fprintf(stderr, "must have cutoff <= %f\n",
          (NBRLIST_DIM-3)/2 * BIN_LENGTH);
      return -1;
    }
    for (k = -c;  k <= c;  k++) {
      for (j = -c;  j <= c;  j++) {
        for (i = -c;  i <= c;  i++) {
          if ((i*i + j*j + k*k)*BIN_LENGTH*BIN_LENGTH >= r2) continue;
          nbrlist[cnt].x = i;
          nbrlist[cnt].y = j;
          nbrlist[cnt].z = k;
          cnt++;
        }
      }
    }
    nbrlistlen = cnt;
  }
  else {
    fprintf(stderr, "must have h <= %f\n", 0.25 * BIN_LENGTH);
    return -1;
  }

  /* perform geometric hashing of atoms into bins */
  {
    /* array of extra atoms, permit average of one extra per bin */
    Atom *extra_atoms = (Atom *) calloc(nbins, sizeof(Atom));
    int extra_len = 0;
    
    for (n = 0;  n < natoms;  n++) {
      float4 p;
      p.x = atom[n].x - xlo;
      p.y = atom[n].y - ylo;
      p.z = atom[n].z - zlo;
      p.w = atom[n].q;
      i = (int) floorf(p.x * BIN_INVLEN);
      j = (int) floorf(p.y * BIN_INVLEN);
      k = (int) floorf(p.z * BIN_INVLEN);
      if (i >= -c && i < binDim.x - c &&
	  j >= -c && j < binDim.y - c &&
	  k >= -c && k < binDim.z - c &&
	  atom[n].q != 0) {
	int index = (k * binDim.y + j) * binDim.x + i;
	float4 *bin = binZeroAddr + index * BIN_DEPTH;
	int bindex = bincntZeroAddr[index];
	if (bindex < BIN_DEPTH) {
	  /* copy atom into bin and increase counter for this bin */
	  bin[bindex] = p;
	  bincntZeroAddr[index]++;
	}
	else {
	  /* add index to array of extra atoms to be computed with CPU */
	  if (extra_len >= nbins) {
	    fprintf(stderr, "exceeded space for storing extra atoms\n");
	    return -1;
	  }
	  extra_atoms[extra_len] = atom[n];
	  extra_len++;
	}
      }
      else {
	/* excluded atoms are either outside bins or neutrally charged */
	num_excluded++;
      }
    }

    /* Save result */
    extra = (Atoms *)malloc(sizeof(Atoms));
    extra->atoms = extra_atoms;
    extra->size = extra_len;
  }

  /* bin stats */
  sum = total = 0;
  for (n = 0;  n < nbins;  n++) {
    binHistoFull[ bincntBaseAddr[n] ]++;
    sum += bincntBaseAddr[n];
    total += BIN_DEPTH;
  }
  avgFillFull = sum / (float) total;
  sum = total = 0;
  for (k = 0;  k < binDim.z - 2*c;  k++) {
    for (j = 0;  j < binDim.y - 2*c;  j++) {
      for (i = 0;  i < binDim.x - 2*c;  i++) {
        int index = (k * binDim.y + j) * binDim.x + i;
        binHistoCover[ bincntZeroAddr[index] ]++;
        sum += bincntZeroAddr[index];
        total += BIN_DEPTH;
      }
    }
  }
  avgFillCover = sum / (float) total;

  if (verbose) {
    /* report */
    printf("number of atoms = %d\n", natoms);
    printf("lattice spacing = %g\n", h);
    printf("cutoff distance = %g\n", cutoff);
    printf("\n");
    printf("requested lattice dimensions = %d %d %d\n", nx, ny, nz);
    printf("requested space dimensions = %g %g %g\n", nx*h, ny*h, nz*h);
    printf("expanded lattice dimensions = %d %d %d\n", lnx, lny, lnz);
    printf("expanded space dimensions = %g %g %g\n", lnx*h, lny*h, lnz*h);
    printf("number of bytes for lattice data = %u\n", lnall*sizeof(float));
    printf("\n");
    printf("bin padding thickness = %d\n", c);
    printf("bin cover dimensions = %d %d %d\n",
        binDim.x - 2*c, binDim.y - 2*c, binDim.z - 2*c);
    printf("bin full dimensions = %d %d %d\n", binDim.x, binDim.y, binDim.z);
    printf("number of bins = %d\n", nbins);
    printf("total number of atom slots = %d\n", nbins * BIN_DEPTH);
    printf("%% overhead space = %g\n",
        (natoms / (double) (nbins * BIN_DEPTH)) * 100);
    printf("number of bytes for bin data = %u\n",
        nbins * BIN_DEPTH * sizeof(float4));
    printf("\n");
    printf("bin histogram with padding:\n");
    sum = 0;
    for (n = 0;  n <= BIN_DEPTH;  n++) {
      printf("     number of bins with %d atoms:  %d\n", n, binHistoFull[n]);
      sum += binHistoFull[n];
    }
    printf("     total number of bins:  %d\n", sum);
    printf("     %% average fill:  %g\n", avgFillFull * 100);
    printf("\n");
    printf("bin histogram excluding padding:\n");
    sum = 0;
    for (n = 0;  n <= BIN_DEPTH;  n++) {
      printf("     number of bins with %d atoms:  %d\n", n, binHistoCover[n]);
      sum += binHistoCover[n];
    }
    printf("     total number of bins:  %d\n", sum);
    printf("     %% average fill:  %g\n", avgFillCover * 100);
    printf("\n");
    printf("number of extra atoms = %d\n", extra->size);
    printf("%% atoms that are extra = %g\n", (extra->size / (double) natoms) * 100);
    printf("\n");

    /* sanity check on bins */
    sum = 0;
    for (n = 0;  n <= BIN_DEPTH;  n++) {
      sum += n * binHistoFull[n];
    }
    sum += extra->size + num_excluded;
    printf("sanity check on bin histogram with edges:  "
        "sum + others = %d\n", sum);
    sum = 0;
    for (n = 0;  n <= BIN_DEPTH;  n++) {
      sum += n * binHistoCover[n];
    }
    sum += extra->size + num_excluded;
    printf("sanity check on bin histogram excluding edges:  "
        "sum + others = %d\n", sum);
    printf("\n");

    /* neighbor list */
    printf("neighbor list length = %d\n", nbrlistlen);
    printf("\n");
  }

  /* setup CUDA kernel parameters */
  gridDim.x = xRegionDim;
  gridDim.y = yRegionDim;
  gridDim.z = 1;
  blockDim.x = 8;
  blockDim.y = 2;
  blockDim.z = 8;

  /* allocate and initialize memory on CUDA device */
  pb_SwitchToTimer(timers, pb_TimerID_COPY);
  if (verbose) {
    printf("Allocating %.2fMB on CUDA device for potentials\n",
           lnall * sizeof(float) / (double) (1024*1024));
  }
  cudaMalloc((void **) &regionZeroCuda, lnall * sizeof(ener_t));
  CUERR;
  cudaMemset(regionZeroCuda, 0, lnall * sizeof(ener_t));
  CUERR;
  if (verbose) {
    printf("Allocating %.2fMB on CUDA device for atom bins\n",
           nbins * BIN_DEPTH * sizeof(float4) / (double) (1024*1024));
  }
  cudaMalloc((void **) &binBaseCuda, nbins * BIN_DEPTH * sizeof(float4));
  CUERR;
  cudaMemcpy(binBaseCuda, binBaseAddr, nbins * BIN_DEPTH * sizeof(float4),
      cudaMemcpyHostToDevice);
  CUERR;
  binZeroCuda = binBaseCuda + ((c * binDim.y + c) * binDim.x + c) * BIN_DEPTH;
  cudaMemcpyToSymbol(NbrListLen, &nbrlistlen, sizeof(int), 0);
  CUERR;
  cudaMemcpyToSymbol(NbrList, nbrlist, nbrlistlen * sizeof(int3), 0);
  CUERR;

  if (verbose) 
    printf("\n");


  cudaStream_t cutoffstream;
  cudaStreamCreate(&cutoffstream);

  /* loop over z-dimension, invoke CUDA kernel for each x-y plane */
  pb_SwitchToTimer(timers, pb_TimerID_GPU);
  printf("Invoking CUDA kernel on %d region planes...\n", zRegionDim);
  for (zRegionIndex = 0;  zRegionIndex < zRegionDim;  zRegionIndex++) {
    printf("  computing plane %d\r", zRegionIndex);
    fflush(stdout);
    cuda_cutoff_potential_lattice6overlap<<<gridDim, blockDim, 0>>>(binDim.x, binDim.y,
        binZeroCuda, h, cutoff2, inv_cutoff2, regionZeroCuda, zRegionIndex);
  }


  /* 
   * handle extra atoms on the CPU, concurrently with the GPU calculations
   */
  pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);
  if (extra->size > 0) {
    printf("computing extra atoms on CPU\n");
    if (cpu_compute_cutoff_potential_lattice(lattice, cutoff, extra)) {
      fprintf(stderr, "cpu_compute_cutoff_potential_lattice() failed "
          "for extra atoms\n");
      return -1;
    }
    printf("\n");
  }

  cudaStreamSynchronize(cutoffstream);
  CUERR;
  cudaThreadSynchronize();
  cudaStreamDestroy(cutoffstream);
  printf("Finished CUDA kernel calls                        \n");

  /* copy result regions from CUDA device */
  pb_SwitchToTimer(timers, pb_TimerID_COPY);
  cudaMemcpy(regionZeroAddr, regionZeroCuda, lnall * sizeof(ener_t),
      cudaMemcpyDeviceToHost);
  CUERR;

  /* free CUDA memory allocations */
  cudaFree(regionZeroCuda);
  cudaFree(binBaseCuda);

  /*
   * transpose on CPU, updating, producing the final lattice
   */
  /* transpose regions back into lattice */
  pb_SwitchToTimer(timers, pb_TimerID_COMPUTE);
  for (k = 0;  k < nz;  k++) {
    zRegionIndex = (k >> 3);
    zOffset = (k & 7);

    for (j = 0;  j < ny;  j++) {
      yRegionIndex = (j >> 3);
      yOffset = (j & 7);

      for (i = 0;  i < nx;  i++) {
        xRegionIndex = (i >> 3);
        xOffset = (i & 7);

        thisRegion = regionZeroAddr
          + ((zRegionIndex * yRegionDim + yRegionIndex) * xRegionDim
              + xRegionIndex) * REGION_SIZE;

        indexRegion = (zOffset * 8 + yOffset) * 8 + xOffset;
        index = (k * ny + j) * nx + i;

#ifndef NEIGHBOR_COUNT
        lattice->lattice[index] += thisRegion[indexRegion];
#else
	neighbor_count += thisRegion[indexRegion];
#endif
      }
    }
  }

#ifdef NEIGHBOR_COUNT
  printf("Neighbor count: %f\n", (float)neighbor_count);
#endif


  /* cleanup memory allocations */
  free(regionZeroAddr);
  free(binBaseAddr);
  free(bincntBaseAddr);
  free_atom(extra);

  return 0;
}
