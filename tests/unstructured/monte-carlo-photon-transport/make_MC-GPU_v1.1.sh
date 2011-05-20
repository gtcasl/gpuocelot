#!/bin/bash
# 
#   ** Simple script to compile the code MC-GPU v1.1 **
#
#      The installations paths to the CUDA toolkit and SDK (http://www.nvidia.com/cuda) and the MPI libraries 
#      (MPICH2: http://www.mcs.anl.gov/research/projects/mpich2/) have to be modified by the user!
# 
#      Default paths:
#           /usr/local/cuda
#           /opt/cuda_SDK_3.0
#           /usr/mpich2-1.0.8p1
#
# 
#                      @file    make_MC-GPU_v1.1.sh
#                      @author  Andreu Badal (Andreu.Badal-Soler@fda.hhs.gov)
#                      @date    2010/06/25
#   


# -- Compile GPU code for compute capability 2.0 and 1.3, without MPI:

echo " -- Compiling with CUDA 3.0 for both compute capability 1.3 and 2.0 (64 bits), MPI not used:"

echo "nvcc -O3 -use_fast_math -DUSING_CUDA -D_NOT_USING_MPI MC-GPU_v1.1.cu -o MC-GPU_v1.1.x -I/usr/local/cuda/include -I/opt/cuda_SDK_3.0/C/common/inc/ -L/opt/cuda_SDK_3.0/C/lib/ -L/usr/local/cuda/lib64/ -lcutil_x86_64 -lcudart -lm --ptxas-options=-v -gencode=arch=compute_13,code=sm_13 -gencode=arch=compute_13,code=compute_13 -gencode=arch=compute_20,code=sm_20 -gencode=arch=compute_20,code=compute_20"
nvcc -O3 -use_fast_math -DUSING_CUDA -D_NOT_USING_MPI MC-GPU_v1.1.cu -o MC-GPU_v1.1.x -I/usr/local/cuda/include -I/opt/cuda_SDK_3.0/C/common/inc/ -L/opt/cuda_SDK_3.0/C/lib/ -L/usr/local/cuda/lib64/ -lcutil_x86_64 -lcudart -lm --ptxas-options=-v -gencode=arch=compute_13,code=sm_13 -gencode=arch=compute_13,code=compute_13 -gencode=arch=compute_20,code=sm_20 -gencode=arch=compute_20,code=compute_20


# -- Compile for compute capability 2.0 and 1.3, with MPI enabled:

# echo " -- Compiling with CUDA 3.0 for both compute capability 1.3 and 2.0, with MPI enabled:"
# echo "nvcc -O3 -use_fast_math -DUSING_MPI -DUSING_CUDA MC-GPU_v1.1.cu -o MC-GPU_v1.1_MPI.x -I/usr/local/cuda/include -I/opt/cuda_SDK_3.0/C/common/inc/ -L/opt/cuda_SDK_3.0/C/lib/ -L/usr/local/cuda/lib64/ -lcutil_x86_64 -lcudart -lm --ptxas-options=-v -gencode=arch=compute_13,code=sm_13 -gencode=arch=compute_13,code=compute_13 -gencode=arch=compute_20,code=sm_20 -gencode=arch=compute_20,code=compute_20 -L/opt/mpich2-1.2.1p1/lib/ -I/opt/mpich2-1.2.1p1/src/include/ -lmpich"
# nvcc -O3 -use_fast_math -DUSING_MPI -DUSING_CUDA MC-GPU_v1.1.cu -o MC-GPU_v1.1_MPI.x -I/opt/cuda/include -I/usr/local/cuda_SDK_3.0/C/common/inc/ -L/opt/cuda_SDK_3.0/C/lib/ -L/usr/local/cuda/lib64/ -lcutil_x86_64 -lcudart -lm --ptxas-options=-v -gencode=arch=compute_13,code=sm_13 -gencode=arch=compute_13,code=compute_13 -gencode=arch=compute_20,code=sm_20 -gencode=arch=compute_20,code=compute_20 -L/opt/mpich2-1.2.1p1/lib/ -I/opt/mpich2-1.2.1p1/src/include/ -lmpich

# Run a CT simulation in parallel:
# 
#  -DUSING_MPI -L/usr/mpich2-1.0.8p1/lib/ -I/usr/mpich2-1.0.8p1/src/include/ -lmpich
# 
#     echo " "
#     echo "   --Example command to run the program in parallel (with MPICH2):"
#     echo "     $ mpd&"
#     echo "     $ mpirun -l -np 2 ./MC-GPU_v1.1_MPI.x < /dev/null MC-GPU_v1.1.in > MC-GPU_v1.1.out &"
#     echo " "

# -- Other compiler parameters for the GPU (nvcc):
     # -use_fast_math
     # --verbose
     # --device-emulation
     # -arch sm_13  ==> specify the compute capability 1.3 to use atomic intrinsics!
     # --ptxas-options=-v  ==> reports the number of registers a kernel compiles to 
     # --maxrregcount 42  ==> force compilation with maximum "42" registers
     # -Xcompiler -fopenmp ==> Pass option to enable openMP to gcc


# -- CPU compilation:
# 
# ** GCC, no MPI:
# gcc -x c -O3 -Wall -msse3 -ffast-math -ftree-vectorize -ftree-vectorizer-verbose=1 -funroll-loops -Wall -static -static-libgcc MC-GPU_v1.1.cu -I./ -lm -o MC-GPU_v1.1__CPU_gcc.x

# ** GCC, MPI:
# mpicxx -x c -O3 -Wall -msse3 -ffast-math -ftree-vectorize -ftree-vectorizer-verbose=1 -funroll-loops -Wall -static -static-libgcc MC-GPU_v1.1.cu -I./ -lm -o MC-GPU_v1.1__CPU_MPI_gcc.x -DUSING_MPI  -L/usr/mpich2-1.0.8p1/lib/ -I/usr/mpich2-1.0.8p1/src/include/ -lmpich

# ** Intel compiler:
# icc -x c -fast -static  -ipo -axSSSE3 -parallel -Wall MC-GPU_v1.1.cu -I./ -lm -o MC-GPU_v1.1_CPU_intel.x

# ** PGI compiler:
# pgcc -fast,sse -O3 -Mipa=fast -Minfo -csuffix=cu -Mconcur MC-GPU_v1.1.cu -I./ -lm -o MC-GPU_v1.1__CPU_PGI.x



