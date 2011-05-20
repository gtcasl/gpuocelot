
////////////////////////////////////////////////////////////////////////////////
//!
//!                ****************************                                  
//!                *** MC-GPU , version 1.1 ***
//!                ****************************
//!
//!
//!       ** DISCLAIMER **
//!
//! This software and documentation (the "Software") were developed at the Food and
//! Drug Administration (FDA) by employees of the Federal Government in the course
//! of their official duties. Pursuant to Title 17, Section 105 of the United States
//! Code, this work is not subject to copyright protection and is in the public
//! domain. Permission is hereby granted, free of charge, to any person obtaining a
//! copy of the Software, to deal in the Software without restriction, including
//! without limitation the rights to use, copy, modify, merge, publish, distribute,
//! sublicense, or sell copies of the Software or derivatives, and to permit persons
//! to whom the Software is furnished to do so. FDA assumes no responsibility
//! whatsoever for use by other parties of the Software, its source code,
//! documentation or compiled executables, and makes no guarantees, expressed or
//! implied, about its quality, reliability, or any other characteristic. Further,
//! use of this code in no way implies endorsement by the FDA or confers any
//! advantage in regulatory decisions.  Although this software can be redistributed
//! and/or modified freely, we ask that any derivative works bear some notice that
//! they are derived from it, and any modified versions bear some notice that they
//! have been modified.
//!
//!                        
//!                     @file    README_MC-GPU.txt
//!                     @author  Andreu Badal (Andreu.Badal-Soler@fda.hhs.gov)
//!                     @date    2010/07/08
//!
////////////////////////////////////////////////////////////////////////////////

MC-GPU is an x ray transport simulation code that can generate radiographic
projection images and computed tomography (CT) scans of voxelized objects,
including realistic human anatomy phantoms. The code implements a massively
multi-threaded Monte Carlo simulation algorithm for the transport of x rays in a
voxelized geometry. The program has been developed using the CUDA programming
model and the simulation can be executed in parallel in a state-of-the-art GPU
from NVIDIA, giving an speed up of the order of 15-25 times, compared to a CPU
execution. The x ray interaction models and cross sections have been adapted
from PENELOPE 2006. Currently, the code does not transport secondary electrons
and the electrons that would be created in photoelectric and Compton events are
assumed to be locally absorbed (dose is not reported).
 The MC-GPU code has been described in different scientific publications. A
brief description of the code features is given below. This description has been
taken from the main paper that can be cited to refer to this code:
 
     Andreu Badal and Aldo Badano, "Accelerating Monte Carlo simulations of 
     photon transport in a voxelized geometry using a massively parallel 
     Graphics Processing Unit", Medical Physics 36, pp. 4878–4880 (2009)

 This code is still in development, please report to the authors any issue/bug
that you may encounter. Feel free to suggest improvements to the code too.


 ** Code features **
 
 MC-GPU does not currently simulate the transport of electrons. The interactions
between the photons and the material objects are simulated using the well-known
interaction sampling models from the PENELOPE 2006 subroutine package.
 In order to speed up the ray-tracing of the code and minimize the access to the
slow GPU main memory, the photon trajectories across the voxels are computed
using the Woodcock tracking algorithm. With this technique the photons perceive
the geometry as a uniform medium composed of the material of the most
attenuating voxel. In this way, the voxel boundaries do not have to be
explicitly calculated and multiple voxels can be crossed in a single step. To
keep the simulation unbiased, some of the interactions are considered "virtual"
(i.e., do not change the photon energy or direction of movement), depending on
the actual energy and the material at the interaction site. In a typical
simulation, several thousand threads are launched simultaneously in the GPU,
each one of them simulating a batch of 10000, or more, photon tracks.
 The random number generator used in PENELOPE, ranecu, is also used in the GPU
program. To ensure that the simulated tracks are not correlated, each thread
initializes the generator to a unique position in the random sequence, far
enough from the other threads, using the algorithm implemented in the seedsMLCG
code.

 The new code is currently used in the study of scatter in x-ray imaging and
includes a tally to generate radiographic images. The image is formed by
counting the energy that enters a user-defined 2D grid of pixels, which is a
simple approximation to a noise-free flat-panel detector with 100% detection
efficiency; the pixel values have units of eV/cm^2. Four different images are
reported at the end of the simulation, corresponding to the signal produced by
non-scattered, single Compton, single Rayleigh, and multi-scattered photons. The
radiation source is implemented as a point source emitting monoenergetic photons
within a fan beam, producing a rectangular field on the detector equivalent to a
collimated cone beam.


 ** Code compilation and execution **
 
 MC-GPU has been tested only in the Linux operating system. A Makefile script is
provided to compile the codex. The CUDA libraries and the GNU GCC compiler 
must be previously installed. The Makefile may have to be edited to
modify the library path.

 MC-GPU uses the CUDA library to access the GPU, but all the actual computations are 
coded in standard C. All the CUDA specific commands are enclosed within preprocessor
if statements. Defining the pre-processor variable "USING_CUDA" (i.e., compiling
with "-DUSING_CUDA") the particle transport is executed in parallel in an NVIDIA
GPU using CUDA. Otherwise, the code is sequentially executed in the CPU.
 
 
 ** Parallel simulation of CT scans **
 
 From version 1.1, MC-GPU allows the simulation of a CT scan. The CT is
simulated generating multiple projection images around the static voxelized
geometry. To speed up the CT simulation, the MPI library is used to address
multiple GPUs and obtain multiple projections in parallel. In order to activate
the MPI code, the pre-processor variable "USING_MPI" must be defined (ie,
compiling with "-DUSING_MPI"). To use the code in parallel in N GPUs (in a
single computer), the user must run the program with N MPI threads in the CPU
(eg, "mpirun -np 4 ./MC-GPU.x MC-GPU.in"). Each thread will get a unique id in
the CPU (myID=0->N) and will address a unique GPU. The CT simulation will then
be split so that the threads simulate consecutive projections independently,
avoiding any intercommunication between threads.
The MPICH2 library can be found at:
   http://www.mcs.anl.gov/research/projects/mpich2/


 ** DISTRIBUTED FILES **

The current MC-GPU distribution is composed of the following elements:

  MC-GPU_v1.1.cu ------------- Main function and simulation initialization routines.
  MC-GPU_kernel_v1.1.cu ------ CUDA kernel: particle tracking, x-ray source, detector model.
  MC-GPU_v1.1.h -------------- Header file with declarations.  

  make_MC-GPU_v1.1.sh -------- Sample compilation script. Must be edited to locate the CUDA libraries and
                               also to compile using the MPI libraries (uncomment appropriate code).
  Makefile ------------------- Simple make script to compile the code for the GPU.
  Makefile_MPI --------------- Make script to compile the code with MPI (rename to Makefile).
  
  MC-GPU_v1.1.x -------------- Sample executable for the GPU (compute capabilities 1.3 and 2.0).
  MC-GPU_v1.1_MPI.x ---------- Sample executable compiled with MPI support.
  MC-GPU_v1.1_CPU_intel.x ---- Sample executable for an Intel i7 CPU.

  doc/ ----------------------- Doxygen documentation describing the MC-GPU code.
  
  sample_simulation/ --------- Folder with an example projection image setting.
    6voxels.vox -------------- Example 6-voxel geometry file.
    MC-GPU_v1.1.in ----------- Sample input file: define the number of particles to simulate,
                               the characteristics of the x-ray source and the detector, the
                               number and spacing of the projections (if simulating a CT), the
                               location of the material files containing the interaction mean
                               free paths, and the location of the voxelized geometry file.
                               A whole body detector with large pixels is defined in this example.
   gnuplot_images_MC-GPU.gpl - Sample GNUPLOT script to visualize the simulated images.
                               The expected image name is "mc-gpu_image.dat", press 'l' for log scale.  
  
  MC-GPU_material_files/ ----- Folder with material data files for MC-GPU. The data for the most
                               common biological materials is provided (*.mcgpu files). 
    MC-GPU_create_material_data.f --- Code to create MC-GPU material data files from PENELOPE 2006 
                               material files. This program has to be compiled with the penelope.f 
                               file (version 2006) not provided here.



  ** KNOWN ISSUES **

The following problems are being addressed and may be fixed in following updates:

   1) Only mono-energetic beams allowed.
         
   2) In very long simulation it is possible that the signal tallied for all the particles
      in a single pixel will be higher than 1e13. In this case the 'unsigned long long int'
      counters may overflow and provide bogus results (much lower than expected).

   3) Executing the code on the CPU, three warnings from the function sampling Compton events will appear 
      (the same issues happen in the GPU but warnings are not displayed). The warnings are related to the 
      use of single instead of double precision for some calculations and should not affect the results.

      

