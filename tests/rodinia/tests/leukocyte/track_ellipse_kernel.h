#ifndef _TRACK_ELLIPSE_KERNEL_H_
#define _TRACK_ELLIPSE_KERNEL_H_

#include "matrix.h"

#ifdef __cplusplus
extern "C" {
#endif
extern void IMGVF_cuda_init(MAT **I, int Nc);
extern void IMGVF_cuda_cleanup(MAT **IMGVF_out, int Nc);
extern void IMGVF_cuda(MAT **I, MAT **IMGVF, double vx, double vy, double e, int max_iterations, double cutoff, int Nc);
#ifdef __cplusplus
}
#endif


#endif
