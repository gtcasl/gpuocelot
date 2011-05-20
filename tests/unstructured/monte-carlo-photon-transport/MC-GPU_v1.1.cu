
////////////////////////////////////////////////////////////////////////////////////////
//
//               ****************************
//               *** MC-GPU , version 1.1 ***
//               ****************************
//
/**
 *      \mainpage  MC-GPU v1.1
 *
 *
 * \b MC-GPU is an x ray transport simulation code that can generate radiographic
 * projection images and computed tomography (CT) scans of voxelized objects,
 * including realistic human anatomy phantoms.
 * 
 * The code implements a massively multi-threaded Monte Carlo simulation algorithm
 * for the transport of x rays in a voxelized geometry. The program has been
 * developed using the \b CUDA programming model and the simulation can be executed in
 * parallel in a state-of-the-art GPU from \b NVIDIA, giving an speed up of the order
 * of 15-25 times, compared to a CPU execution. The x ray interaction models and
 * cross sections have been adapted from \b PENELOPE \b 2006.
 * Currently, the code does not transport secondary electrons and the electrons
 * that would be created in photoelectric and Compton events are assumed to be
 * locally absorbed (dose is not reported).
 * 
 * The MC-GPU code has been described in different scientific publications. A brief
 * description of the code features is given below. This description has been taken
 * from the main paper that can be cited to refer to this code:
 *
 * \code
 *  Andreu Badal and Aldo Badano, "Accelerating Monte Carlo simulations of photon transport in a voxelized
 *  geometry using a massively parallel Graphics Processing Unit", Medical Physics 36, pp. 4878–4880 (2009)
 * \endcode
 *
 * This code is still in development, please report to the authors any issue/bug
 * that you may encounter. Feel free to suggest improvements to the code too. 
 *
 *
 *    \section  sec_disc  DISCLAIMER
 *
 *  This software and documentation (the "Software") were developed at the Food and
 *  Drug Administration (\b FDA) by employees of the Federal Government in the course
 *  of their official duties. Pursuant to Title 17, Section 105 of the United States
 *  Code, this work is not subject to copyright protection and is in the public
 *  domain. Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of the Software, to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish, distribute,
 *  sublicense, or sell copies of the Software or derivatives, and to permit persons
 *  to whom the Software is furnished to do so. FDA assumes no responsibility
 *  whatsoever for use by other parties of the Software, its source code,
 *  documentation or compiled executables, and makes no guarantees, expressed or
 *  implied, about its quality, reliability, or any other characteristic. Further,
 *  use of this code in no way implies endorsement by the FDA or confers any
 *  advantage in regulatory decisions.  Although this software can be redistributed
 *  and/or modified freely, we ask that any derivative works bear some notice that
 *  they are derived from it, and any modified versions bear some notice that they
 *  have been modified.
 * 
 *     \section sec_Intro Code features
 *  
 * MC-GPU does not currently simulate the transport of electrons.
 * The interactions between the photons and the material objects are simulated
 * using the well-known interaction sampling models from the PENELOPE 2006
 * subroutine package.
 * 
 * In order to speed up the ray-tracing of the code and minimize the access to the
 * slow GPU main memory, the photon trajectories across the voxels are computed
 * using the Woodcock tracking algorithm.
 * With this technique the photons perceive the geometry as a uniform medium
 * composed of the material of the most attenuating voxel.
 * In this way, the voxel boundaries do not have to be explicitly calculated and
 * multiple voxels can be crossed in a single step.
 * To keep the simulation unbiased, some of the interactions are considered
 * "virtual" (i.e., do not change the photon energy or direction of movement),
 * depending on the actual energy and the material at the interaction site.
 * In a typical simulation, several thousand threads are launched simultaneously in
 * the GPU, each one of them simulating a batch of 10000, or more, photon tracks.
 * 
 * The random number generator used in PENELOPE, ranecu, is also used in the GPU
 * program.
 * To ensure that the simulated tracks are not correlated, each thread initializes
 * the generator to a unique position in the random sequence, far enough from the
 * other threads, using the algorithm implemented in the seedsMLCG code.
 * 
 * The new code is currently used in the study of scatter in x-ray imaging and
 * includes a tally to generate radiographic images.
 * The image is formed by counting the energy that enters a user-defined 2D grid of
 * pixels, which is a simple approximation to a noise-free flat-panel detector with
 * 100% detection efficiency; the pixel values have units of eV/cm^2.
 * Four different images are reported at the end of the simulation, corresponding
 * to the signal produced by non-scattered, single Compton, single Rayleigh, and
 * multi-scattered photons.
 * The radiation source is implemented as a point source emitting monoenergetic
 * photons within a fan beam, producing a rectangular field on the detector
 * equivalent to a collimated cone beam.
 * 
 * 
 *    \section sec_CPU Code compilation and execution
 *
 *   MC-GPU has been tested only in the Linux operating system.
 *   A Makefile script is provided to compile the MC-GPU code in Linux.
 *   The CUDA libraries and the GNU GCC compiler must be previously installed.
 *   The Makefile may have to be edited to modify the library path.
 *
 *   A README text file is provided with the MC-GPU source code. Read this file for
 *   more information on the code usage. An example simulation input file is also
 *   provided.
 *
 *   MC-GPU uses CUDA to access the GPU but all the actual computations are coded
 *   in standard C code.
 *   All the CUDA specific commands are enclosed within preprocessor if statements.
 *   Defining the pre-processor variable "USING_CUDA" (i.e., compiling with
 *   "-DUSING_CUDA") the particle transport is executed in parallel in an
 *   NVIDIA GPU using CUDA. Otherwise, the code is sequentially executed in
 *   the CPU.
 * 
 * 
 *    \section sec_CT Parallel simulation of CT scans:
 * 
 *   From version 1.1, MC-GPU allows the simulation of a CT scan. The CT is
 *   simulated generating multiple projection images around the static voxelized
 *   geometry. To speed up the CT simulation, the MPI library is used to address
 *   multiple GPUs and obtain multiple projections in parallel. In order to
 *   activate the MPI code, the pre-processor variable "USING_MPI" has to be
 *   defined (ie, compiling with "-DUSING_MPI").
 *   To use the code in parallel in N GPUs (in a single computer), the user
 *   has to run the program with N MPI threads in the CPU (eg,
 *   "mpirun -np 4 ./MC-GPU.x MC-GPU.in"). Each thread will get a unique id in
 *   the CPU (myID=0->N) and will address a unique GPU. The CT simulation will
 *   then be split so that the threads simulate consecutive projections
 *   independently, avoiding any intercommunication between threads.
 * 
 * 
 * 
 * 
 * 
 *                      @file    MC-GPU_v1.1.cu
 *                      @author  Andreu Badal (Andreu.Badal-Soler@fda.hhs.gov)
 *                      @date    2010/06/25
 *                        -- First version:  2009/03/17
 */ 
////////////////////////////////////////////////////////////////////////////////////////







// *** Include header file with the structures and functions declarations
#include <MC-GPU_v1.1.h>

// *** Include the computing kernel:
#include <MC-GPU_kernel_v1.1.cu>


////////////////////////////////////////////////////////////////////////////////
//!  Main program to transport x rays in a 3D voxel geometry using the GPU.
//!  This function reads the description of the simulation from an external file
//!  given in the command line. This input file defines the number of particles to
//!  simulate, the characteristics of the x-ray source and the detector, the number
//!  and spacing of the projections (if simulating a CT), the location of the
//!  material files containing the interaction mean free paths, and the location
//!  of the voxelized geometry file.
//!
//!                            @author  Andreu Badal
//!                            @date    2010/03/19
//!
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{

#ifdef USING_MPI
// -- Using MPI to address multiple GPUs in the same workstation (use only to simulate a CT scan).
  int myID = -88, numprocs = -99;
  MPI_Init(&argc, &argv);                   // Init MPI and get the current thread ID 
  MPI_Comm_rank(MPI_COMM_WORLD, &myID);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  printf("            *** MPI run:  myId=%d , numprocs=%d\n",myID,numprocs);
  fflush(stdout);   // Clear the screen output buffer
  MPI_Barrier(MPI_COMM_WORLD);   // Synchronize MPI threads  
#else
  int myID = 0, numprocs = 1;   // Only one CPU thread used when MPI is not activated (multiple projections will be simulated sequentially).
#endif
  

  // *** Declare the arrays and structures that will contain the simulation data:

  struct voxel_struct voxel_data;          // Define the geometric constants of the voxel file
  struct source_struct source_data;        // Define the particles source
  struct detector_struct detector_data;    // Define an x ray detector
  struct linear_interp mfp_table_data;     // Constant data for the linear interpolation

  struct compton_struct  compton_table;    // Structure containing Compton sampling data (to be copied to CONSTANT memory)
  struct rayleigh_struct rayleigh_table;   // Structure containing Rayleigh sampling data (to be copied to CONSTANT memory)
  
  float2 *voxel_mat_dens = NULL;           // Poiter where voxels array will be allocated
  unsigned int voxel_mat_dens_bytes = 0;   // Size (in bytes) of the voxels array (using unsigned int to allocate up to 4.2GBytes)
  float density_max[MAX_MATERIALS];
  float density_nominal[MAX_MATERIALS];
  unsigned long long int *image = NULL;    // Poiter where image array will be allocated
  int image_bytes = -1;                    // Size of the image array
  int mfp_table_bytes = -1, mfp_Woodcock_table_bytes = -1;   // Size of the table arrays
  float2 *mfp_Woodcock_table = NULL;                // Linear interpolation data for the Woodcock mean free path [cm]
  float3 *mfp_table_a = NULL, *mfp_table_b = NULL;  // Linear interpolation data for 3 different interactions:
                                              //  (1) inverse total mean free path (divided by density, cm^2/g)
                                              //  (2) inverse Compton mean free path (divided by density, cm^2/g)
                                              //  (3) inverse Rayleigh mean free path (divided by density, cm^2/g)
  
#ifdef USING_CUDA
  // - MASTER_THREAD == "if(0==myID)": macro to print the messages just once when using MPI threads; it has no effect if MPI is not used.
  MASTER_THREAD printf  ("\n             *** CUDA SIMULATION IN THE GPU ***\n");
#else
  MASTER_THREAD printf  ("\n             *** SIMULATION IN THE CPU ***\n");
#endif

  time_t current_time = time(NULL);     // Get current time (in seconds)
  MASTER_THREAD printf("\n****** Code execution started on: %s\n", ctime(&current_time));

  MASTER_THREAD printf("    -- INITIALIZATION phase:\n");

  // -- Start time counter:
  clock_t clock_start, clock_end;      // (requires standard header <time.h>)
  clock_start = clock();               // Get current clock counter


  unsigned long long int total_histories;
  int histories_per_thread, seed_input, num_threads_per_block, gpu_id, num_projections;
  double D_angle, angularROI_0, angularROI_1, initial_angle;
  char file_name_voxels[250], file_name_materials[MAX_MATERIALS][250], file_name_output[250];  

  // *** Read the input file given in the command line and return the significant data:
  read_input(argc, argv, myID, &total_histories, &seed_input, &gpu_id, &num_threads_per_block, &histories_per_thread, &detector_data, &image, &image_bytes, &source_data, file_name_voxels, file_name_materials, file_name_output, &num_projections, &D_angle, &angularROI_0, &angularROI_1, &initial_angle);

        float3 detector_center;
        detector_center.x = source_data.position[0].x + source_data.direction[0].x * detector_data.sdd;   // Set the center of the detector straight ahead of the focal spot.
        detector_center.y = source_data.position[0].y + source_data.direction[0].y * detector_data.sdd;
        detector_center.z = source_data.position[0].z + source_data.direction[0].z * detector_data.sdd;

  MASTER_THREAD
  {
        printf("                       total_histories = %lld\n", total_histories);
        printf("                           random seed = %d\n", seed_input);
        printf("                         source energy = %.3f keV\n", (source_data.energy/1.0e3f));
        
//         printf("            azimuthal, polar apertures = %.6f , %.6f degrees\n", 2.0*atan(source_data.tan_phi_semiaperture)*RAD2DEG, 2.0*atan(source_data.tan_theta_semiaperture)*RAD2DEG);
        printf("      azimuthal (phi), polar apertures = %.6f , %.6f degrees\n", source_data.D_phi*RAD2DEG, 2.0*(90.0 - acos(source_data.cos_theta_low)*RAD2DEG) );

         
        printf("                   focal spot position = (%f, %f, %f)\n", source_data.position[0].x, source_data.position[0].y, source_data.position[0].z);
        printf("                      source direction = (%f, %f, %f)\n", source_data.direction[0].x, source_data.direction[0].y, source_data.direction[0].z);
        printf("                  initial angle from X = %lf\n", initial_angle*RAD2DEG);
        printf("                       detector center = (%f, %f, %f)\n", detector_center.x, detector_center.y, detector_center.z);
        printf("           detector low corner (at +Y) = (%f, %f, %f)\n", detector_data.corner_min_rotated_to_Y[0].x, detector_data.corner_min_rotated_to_Y[0].y, detector_data.corner_min_rotated_to_Y[0].z);
        printf("              source-detector distance = %f cm\n", detector_data.sdd);
        printf("                number of pixels image = %dx%d\n", detector_data.num_pixels.x, detector_data.num_pixels.y);
        printf("                            pixel size = %.3fx%.3f cm\n", 1.0f/detector_data.inv_pixel_size_X, 1.0f/detector_data.inv_pixel_size_Z);
        printf("                 number of projections = %d\n", num_projections);
        if (num_projections!=1)
        {
          printf("             angle between projections = %lf\n", D_angle*RAD2DEG);
          printf("            angular region of interest = [%lf,%lf] degrees\n", angularROI_0*RAD2DEG, angularROI_1*RAD2DEG);
        }
        printf("                      Input voxel file = %s\n", file_name_voxels);
        printf("                     Output image file = %s\n", file_name_output);
        fflush(stdout);
}


  // *** Set the detectors and sources for the CT trajectory (if needed, ie, for more than one projection):
  if (num_projections != 1)
    set_CT_trajectory(myID, num_projections, D_angle, angularROI_0, angularROI_1, &source_data, &detector_data);

  fflush(stdout);
        

  // *** Read the voxel data and allocate the density map matrix. Return the maximum density:
  load_voxels(myID, file_name_voxels, density_max, &voxel_data, &voxel_mat_dens, &voxel_mat_dens_bytes);  
  MASTER_THREAD printf("       Total CPU memory allocated for voxels vector and data structures = %f Mbytes\n", (voxel_mat_dens_bytes+image_bytes+sizeof(struct voxel_struct)+sizeof(struct source_struct)+sizeof(struct detector_struct)+sizeof(struct linear_interp)+2*mfp_table_bytes+sizeof(struct rayleigh_struct)+sizeof(struct compton_struct))/(1024.f*1024.f));
  MASTER_THREAD fflush(stdout);

  // *** Read the material mean free paths and set the interaction table in a "linear_interp" structure:
  load_material(myID, file_name_materials, density_max, density_nominal, &mfp_table_data, &mfp_Woodcock_table, &mfp_Woodcock_table_bytes, &mfp_table_a, &mfp_table_b, &mfp_table_bytes, &rayleigh_table, &compton_table);

  // -- Check that the input material tables and the x-ray source are consistent:
  if ( (source_data.energy < mfp_table_data.e0) || (source_data.energy > (mfp_table_data.e0 + (mfp_table_data.num_values-1)/mfp_table_data.ide)) )
  {
    MASTER_THREAD printf("\n !!ERROR!! The input x-ray source energy (%f eV) is outside the tabulated energy interval (from %f to %f eV)!!\n\n", source_data.energy, mfp_table_data.e0, (mfp_table_data.e0+(mfp_table_data.num_values-1)/mfp_table_data.ide));
    exit(-1);
  }


#ifdef USING_MPI
  if (myID != gpu_id)
    gpu_id = myID;     // Use the GPU with the same number as the CPU thread number (from '0' to 'numprocs-1')
  else                 // but skip the GPU number given in the input file (useful if GPU 0 is attached to a display).
    gpu_id = numprocs;
#endif


#ifdef USING_CUDA
  // -- Declare the pointers to the device global memory, when using the GPU:
  float2 *voxel_mat_dens_device     = NULL,
         *mfp_Woodcock_table_device = NULL;
  float3 *mfp_table_a_device        = NULL,
         *mfp_table_b_device        = NULL;
  unsigned long long int *image_device          = NULL;
  struct rayleigh_struct *rayleigh_table_device = NULL;
  struct compton_struct  *compton_table_device  = NULL;

  // -- Sets the CUDA enabled GPU that will be used in the simulation, and allocate and copies the simulation data in the GPU global and constant memories.
  init_CUDA_device(&gpu_id, myID, &voxel_data, &source_data, &detector_data, &mfp_table_data,  /*Variables GPU constant memory*/
        voxel_mat_dens, &voxel_mat_dens_device, voxel_mat_dens_bytes,                          /*Variables GPU global memory*/
        image, &image_device, image_bytes,
        mfp_Woodcock_table, &mfp_Woodcock_table_device, mfp_Woodcock_table_bytes,
        mfp_table_a, mfp_table_b, &mfp_table_a_device, &mfp_table_b_device, mfp_table_bytes,
        &rayleigh_table, &rayleigh_table_device,
        &compton_table, &compton_table_device);
#endif

  clock_end = clock();
  double time_elapsed_1 = ((double)(clock_end-clock_start))/CLOCKS_PER_SEC;
  double time_elapsed_2 = 0.0, time_total = 0.0;
  MASTER_THREAD printf("\n    -- INITIALIZATION finished: elapsed time = %.3f s\n", time_elapsed_1);

#ifdef USING_MPI
  fflush(stdout);
  MPI_Barrier(MPI_COMM_WORLD);   // Synchronize MPI threads before starting the MC phase.
#endif

  MASTER_THREAD printf("\n\n    -- MONTE CARLO LOOP phase:\n\n");
  MASTER_THREAD fflush(stdout);   // Clear the screen output buffer

  // -- Scale the input number of particles taking into account that "histories_per_thread" tracks will be
  //    simulated for each call to "track_particles", ie, each GPU thread.
  //    The total number of particles simulated will be increased to the nearest multiple histories_per_thread.
  if(((unsigned long long int)(total_histories/histories_per_thread))>=2147483647)
  {
    MASTER_THREAD printf("\n\n   !!ERROR!! \"total_histories/histories_per_thread = %lld > 2147483647\": this value can not be represented with a 4 byte integer.\n     Please, increase histories_per_thread until the fraction is acceptable. Sorry about that.\n\n", ((unsigned long long int)(total_histories/histories_per_thread)));
    exit(-1);
  }
  int total_history_batch = (int)(total_histories/histories_per_thread);
  if (0!=(total_histories%histories_per_thread))
  {
    total_history_batch++;        // Input value is not multiple of HISTORIES_PER_THREAD: make an extra iteration
    total_histories = (unsigned long long int)total_history_batch*histories_per_thread;   // Total histories will be higher than input value
  }


  // *** CT simulation: simulate multiple projections if requested:

  double current_angle;
  int num_p;  // == current projection number
  for (num_p=0; num_p<num_projections; num_p++)
  {
    #ifdef USING_MPI
      // -- Distribute the projections to the multiple threads evenly: each thread simulates an angle and skip the following 'numprocs' angles
      if( (num_p % numprocs) != myID )
      {
        // printf(" ... Thread %d skipped projection=%d, modulo=%d\n", myID, num_p, (num_p % numprocs));
        continue;
      }
    #endif
    
    // -- Check if this projection is inside the angular region of interest
    current_angle = initial_angle + num_p * D_angle;    
    if (current_angle<0.0)
      current_angle += 2.0*PI;   // Make sure the angle is not negative.
    else if (current_angle>=(2.0*PI-0.0001))
      current_angle -= 2.0*PI;   // Make sure the angle is not above or equal to 360 degrees.

    if ((current_angle < angularROI_0) || (current_angle > angularROI_1))
    {
      printf("\n         << Skipping projection #%d >> Angle: %f degrees --> outside the angular region of interest.\n", num_p, current_angle*RAD2DEG);
      continue;   // Cycle loop: do not simulate this projection!
    }
      
    if (num_projections!=1)
      printf("\n   << Simulating Projection %d of %d >> Angle: %lf degrees.\n\n", num_p, num_projections-1, current_angle*RAD2DEG);
      
    #ifdef USING_CUDA
      // --Executing the kernel in the GPU:
      int total_history_batch_blocks = (int)(total_history_batch/num_threads_per_block);
      if (0!=(total_history_batch%num_threads_per_block))
      {
        total_history_batch_blocks++;        // Value is not multiple of num_threads: execute an extra block of threads
        total_histories = (unsigned long long int)total_history_batch_blocks*num_threads_per_block*histories_per_thread;   // Total histories will be higher than input value
      }
      // -- Setup the execution parameters, taking into account the current CUDA specifications:
      //    Warp size: 32, Max number threads per block: 512, Max sizes each dimension of block: 512x512x64, Max sizes each dimension of grid: 65535x65535x1
      if (total_history_batch_blocks>65535)
      {
        MASTER_THREAD printf("\n\n   !!ERROR!! \"total_histories/histories_per_thread/num_threads_per_block ~ %d > 65535\": the GPU can not simulate so many blocks (with a 1D grid).\n             Please, increase histories_per_thread or num_threads_per_block until the fraction is acceptable. Sorry about that.\n\n", total_history_batch_blocks);
        exit(-1);
      }
      dim3 blocks(total_history_batch_blocks, 1);
      dim3 threads(num_threads_per_block, 1);
      printf("       Executing %d blocks of %d threads, with %d histories in each thread: %lld histories in total.\n", total_history_batch_blocks, num_threads_per_block, histories_per_thread, total_histories);
      fflush(stdout); 

      // -- Execute the kernel
      unsigned int timer = 0;
      cutilCheckError(cutCreateTimer(&timer));
      cutilCheckError(cutStartTimer(timer));

      clock_start = clock();
      track_particles<<<blocks,threads>>>(histories_per_thread, num_p, seed_input, image_device, voxel_mat_dens_device, mfp_Woodcock_table_device, mfp_table_a_device, mfp_table_b_device, rayleigh_table_device, compton_table_device);
      cudaThreadSynchronize();    // Force the runtime to wait until all device tasks have completed

      // -- Check if kernel execution generated any error:
      cutilCheckMsg(" !!Kernel execution failed while simulating particle tracks!! ");

      cutilCheckError( cutStopTimer( timer));
      printf("       ==> CUDA: Kernel execution time in the device: %.3f s \n", 0.001f*cutGetTimerValue( timer));
      cutilCheckError( cutDeleteTimer( timer));
      cutilCheckError( cutCreateTimer( &timer));
      cutilCheckError( cutStartTimer( timer));
      cutilSafeCall( cudaMemcpy( image, image_device, image_bytes, cudaMemcpyDeviceToHost) );  // Copy final results to host
      cutilCheckError( cutStopTimer( timer));
      printf("                 Time copying results from device to host: %.3f s\n", 0.001f*cutGetTimerValue( timer));
      cutilCheckError( cutDeleteTimer( timer));

    #else
      // --Executing the kernel in the CPU:
      printf("       Executing %d history batches, with %d histories in each batch: %lld histories in total.\n", total_history_batch, histories_per_thread, total_histories);

      // -- Copy local structures to global struct variables accessible from "track_particles" (__constant__ variables in the GPU):
      source_data_CONST = source_data;
      detector_data_CONST = detector_data;
      voxel_data_CONST = voxel_data;
      mfp_table_data_CONST = mfp_table_data;

      clock_start = clock();
      int n;
      for(n=0; n<total_history_batch; n++)
      {
        // -- Simulate a particle track initializing the PRNG with the particle number 'n':
        track_particles(n, histories_per_thread, num_p, seed_input, image, voxel_mat_dens, mfp_Woodcock_table, mfp_table_a, mfp_table_b, &rayleigh_table, &compton_table);
      }
    #endif

    // Get final time and calculate loop execution time:
    clock_end = clock();
    time_elapsed_2 = ((double)(clock_end-clock_start))/CLOCKS_PER_SEC;
    time_total += time_elapsed_2;   // Count total time (in seconds).
        //  printf("\n    -- MONTE CARLO LOOP finished: time tallied in MAIN program: %.3f s\n\n", time_elapsed_2);

    // *** Report the final results:
    char file_name_output_num_p[253];
    if (1==num_projections)
      strcpy(file_name_output_num_p, file_name_output);   // Use the input name for single projection
    else
      sprintf(file_name_output_num_p, "%s_%03d", file_name_output, num_p);   // Create the output file name with the input name + projection number (3 digits, padding with 0)

    report_host(file_name_output_num_p, &detector_data, &source_data, image, time_elapsed_2, total_histories, num_p, num_projections, D_angle, initial_angle, myID, numprocs);

    // *** Clear the image after reporting, unless this is the last projection to simulate:
    if (num_p<(num_projections-1))
    {
      int pixels_per_image = detector_data.num_pixels.x * detector_data.num_pixels.y;
      #ifdef USING_CUDA
        printf("       ==> CUDA: Launching kernel to reset the device image to 0: number of blocks = %d, threads per block = 128\n", (int)ceil(pixels_per_image/128.0f) );
        init_image_array_GPU<<<(int)(ceil(pixels_per_image/128.0f)),128>>>(image_device, pixels_per_image);
        cudaThreadSynchronize();
        cutilCheckMsg(" !!Kernel execution failed initializing the image array!! ");  // Check if kernel execution generated any error:
      #else
        int j;
        for (j=0; j<pixels_per_image; j++)   // INIT IMAGE ARRAY IN THE CPU
        {
          image[j                   ] = (unsigned long long int)(0);
          image[j+  pixels_per_image] = (unsigned long long int)(0);
          image[j+2*pixels_per_image] = (unsigned long long int)(0);
          image[j+3*pixels_per_image] = (unsigned long long int)(0);
        }
      #endif
    }
  }  // [Loop end: iterate for next CT projection]

  MASTER_THREAD printf("\n    -- MONTE CARLO LOOP finished: total time tallied in MAIN program: %.3f s\n", time_total);


  // *** Clean up RAM memory:
  free(voxel_mat_dens);
  free(image);
  free(mfp_Woodcock_table);
  free(mfp_table_a);
  free(mfp_table_b);
  
#ifdef USING_CUDA
  unsigned int timer = 0;
  cutilCheckError( cutCreateTimer( &timer));
  cutilCheckError( cutStartTimer( timer));
  
  // -- Clean up GPU device memory:
  cutilSafeCall(cudaFree(voxel_mat_dens_device));
  cutilSafeCall(cudaFree(image_device));
  cutilSafeCall(cudaFree(mfp_Woodcock_table_device));
  cutilSafeCall(cudaFree(mfp_table_a_device));
  cutilSafeCall(cudaFree(mfp_table_b_device));

  cudaThreadExit();

  cutilCheckError( cutStopTimer( timer));
  MASTER_THREAD printf("       ==> CUDA: Time freeing the device memory and ending the GPU threads: %.6f s\n", 0.001f*cutGetTimerValue( timer));
  cutilCheckError( cutDeleteTimer( timer));
#endif

#ifdef USING_MPI
  current_time=time(NULL);     // Get current time (in seconds)
  printf("       MPI node %d done! Time: %s\n", myID, ctime(&current_time));
  fflush(stdout);   // Clear the screen output buffer
  MPI_Barrier(MPI_COMM_WORLD);   // Synchronize MPI threads
  MPI_Finalize();   // Finalize MPI library: no more MPI calls allowed below.
#endif

  current_time=time(NULL);     // Get current time (in seconds)
  MASTER_THREAD printf("\n****** Code execution finished on: %s\n", ctime(&current_time));
  
  return 0;
}



////////////////////////////////////////////////////////////////////////////////
//! Read the input file given in the command line and return the significant data.
//! Example input file:
//!
//!    1000000          [Total number of histories to simulate]
//!    geometry.vox     [Voxelized geometry file name]
//!    material.mat     [Material data file name]
//!
//!       @param[in] argc   Command line parameters
//!       @param[in] argv   Command line parameters: name opf input file
//!       @param[out] total_histories  Total number of particles to simulate
//!       @param[out] seed_input   Input random number generator seed
//!       @param[out] num_threads_per_block   Number of CUDA threads for each GPU block
//!       @param[out] detector_data
//!       @param[out] image
//!       @param[out] source_data
//!       @param[out] file_name_voxels
//!       @param[out] file_name_materials
//!       @param[out] file_name_output
////////////////////////////////////////////////////////////////////////////////
void read_input(int argc, char** argv, int myID, unsigned long long int* total_histories, int* seed_input, int* gpu_id, int* num_threads_per_block, int* histories_per_thread, struct detector_struct* detector_data, unsigned long long int** image_ptr, int* image_bytes, struct source_struct* source_data, char* file_name_voxels, char file_name_materials[MAX_MATERIALS][250] , char* file_name_output, int* num_projections, double* D_angle, double* angularROI_0, double* angularROI_1, double* initial_angle)
{
  FILE* file_ptr = NULL;
  char new_line[250];
  char *new_line_ptr = NULL;
  double dummy_double;

  // -- Read the input file name from command line, if given (otherwise keep default value):
  if (2==argc)
  {
    file_ptr = fopen(argv[1], "r");
    if (NULL==file_ptr)
    {
      printf("\n\n   !!read_input ERROR!! Input file not found or not readable. Input file name: \'%s\'\n\n", argv[1]);
      exit(-1);
    }
  }
  else if (argc>2)
  {
    printf("\n\n   !!read_input ERROR!! Too many input parameter (argc=%d)!! Provide only the input file name.\n\n", argc);
    exit(-1);
  }
  else
  {
    printf("\n\n   !!read_input ERROR!! Input file name not given as an execution parameter!! Try again...\n\n");
    exit(-1);
  }

  MASTER_THREAD printf("\n    -- Reading the input file \'%s\':\n", argv[1]);

  do
  {
    new_line_ptr = fgets(new_line, 250, file_ptr);    // Read full line (max. 250 characters).
    if (new_line_ptr==NULL)
    {
      printf("\n\n   !!read_input ERROR!! Input file is not readable or does not contain the string \'SECTION SIMULATION\'!!\n");
      exit(-2);
    }
  }
  while(strstr(new_line,"SECTION SIMULATION")==NULL);   // Skip comments and empty lines until the section begins
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%lf", &dummy_double);
    *total_histories = (unsigned long long int) (dummy_double+0.0001);  // Maximum unsigned long long value: 18446744073709551615
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%d", seed_input);   // Set the RANECU PRNG seed (the same seed will be used to init the 2 MLCGs in RANECU)
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%d", gpu_id);       // GPU NUMBER WHERE SIMULATION WILL RUN
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%d", num_threads_per_block);  // GPU THREADS PER CUDA BLOCK
  if ((*num_threads_per_block%32)!=0)
  {
    printf("\n\n   !!read_input ERROR!! The input number of GPU threads per CUDA block must be a multiple of 32 (warp size). Input value: %d !!\n\n", *num_threads_per_block);
    exit(-2);
  }
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%d", histories_per_thread);   // HISTORIES PER GPU THREAD

  do
  {
    new_line_ptr = fgets(new_line, 250, file_ptr);
    if (new_line_ptr==NULL)
    {
      printf("\n\n   !!read_input ERROR!! Input file is not readable or does not contain the string \'SECTION SOURCE\'!!\n");
      exit(-2);
    }
  }
  while(strstr(new_line,"SECTION SOURCE")==NULL);   // Skip comments and empty lines until the section begins
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%f", &(source_data->energy));  // X-RAY ENERGY [eV]
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%f %f %f", &source_data->position[0].x, &source_data->position[0].y, &source_data->position[0].z);   // SOURCE POSITION: X Y Z [cm]
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%f %f %f", &source_data->direction[0].x, &source_data->direction[0].y, &source_data->direction[0].z);   // SOURCE DIRECTION COSINES: U V W
    // -- Normalize the input beam direction to 1:
    dummy_double = 1.0/sqrt((double)(source_data->direction[0].x*source_data->direction[0].x + source_data->direction[0].y*source_data->direction[0].y + source_data->direction[0].z*source_data->direction[0].z));
    source_data->direction[0].x = (float)(((double)source_data->direction[0].x)*dummy_double);
    source_data->direction[0].y = (float)(((double)source_data->direction[0].y)*dummy_double);
    source_data->direction[0].z = (float)(((double)source_data->direction[0].z)*dummy_double);
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
  

/* !!DeBuG!! OLD WRONG FAN BEAM:  
    sscanf(new_line, "%f %f", &source_data->tan_phi_semiaperture, &source_data->tan_theta_semiaperture);
    if ( (source_data->tan_phi_semiaperture>-1.0e-6) && (source_data->tan_theta_semiaperture>-1.0e-6) )   // If we enter a negative angle, the fan beam will cover exactly the detector surface (see below).
    {
      source_data->tan_phi_semiaperture   = tan(0.5 * source_data->tan_phi_semiaperture*DEG2RAD);    // Divide by 2 the input apertures to get semiapertures.
      source_data->tan_theta_semiaperture = tan(0.5 * source_data->tan_theta_semiaperture*DEG2RAD);  // The tan of the semiaperture is the size of the field at distance 1, where we will sample uniform points.
    }
*/


  // Read input fan beam polar (theta) and azimuthal (phi) aperture angles (deg):
  double phi_aperture, theta_aperture;
  sscanf(new_line, "%lf %lf", &phi_aperture, &theta_aperture);

  if (theta_aperture > 180.0)
  {
    printf("\n\n   !!read_input ERROR!! Input polar aperture must be in [0,180] deg.!\n");
    printf("                       theta_aperture = %lf, phi_aperture = %lf\n", theta_aperture, phi_aperture);
    exit(-2);
  }
  if (phi_aperture > 360.0)
  {
    printf("\n\n   !!read_input ERROR!! Input azimuthal aperture must be in [0,360] deg.!\n");
    printf("                       theta_aperture = %lf, phi_aperture = %lf\n", theta_aperture, phi_aperture);
    exit(-2);
  }
  // Entering a negative theta_aperture or phi_aperture, the emitted fan beam will cover exactly the detector: see below
  
  // *** RECTANGULAR BEAM INITIALIZATION: aperture initially centered at (0,1,0), ie, THETA_0=90, PHI_0=90
  //     Using the algorithm used in PENMAIN.f, from penelope 2008 (by F. Salvat).
  source_data->cos_theta_low = (float)( cos((90.0 - 0.5*theta_aperture)*DEG2RAD) );
  source_data->D_cos_theta   = (float)( -2.0*source_data->cos_theta_low );      // Theta aperture is symetric above and below 90 deg
  source_data->phi_low       = (float)( (90.0 - 0.5*phi_aperture)*DEG2RAD );
  source_data->D_phi         = (float)( phi_aperture*DEG2RAD );

  source_data->max_height_at_y1cm = (float) ( tan(0.5*theta_aperture*DEG2RAD) );
          
  do
  {
    new_line_ptr = fgets(new_line, 250, file_ptr);
    if (new_line_ptr==NULL)
    {
      printf("\n\n   !!read_input ERROR!! Input file is not readable or does not contain the string \'SECTION DETECTOR\'!!\n");
      exit(-2);
    }
  }
  while(strstr(new_line,"SECTION DETECTOR")==NULL);   // Skip comments and empty lines until the section begins
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    trim_name(new_line, file_name_output);   // OUTPUT IMAGE FILE NAME (no spaces)
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%d %d", &detector_data->num_pixels.x, &detector_data->num_pixels.y);   // NUMBER OF PIXELS IN THE IMAGE: Nx Nz
    detector_data->total_num_pixels = detector_data->num_pixels.x * detector_data->num_pixels.y;
  
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
  sscanf(new_line, "%f %f", &detector_data->width_X, &detector_data->height_Z);   // IMAGE SIZE (width, height): Dx Dz [cm]
    detector_data->inv_pixel_size_X = detector_data->num_pixels.x / detector_data->width_X;
    detector_data->inv_pixel_size_Z = detector_data->num_pixels.y / detector_data->height_Z;

  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    sscanf(new_line, "%f", &detector_data->sdd);            // SOURCE-TO-DETECTOR DISTANCE [cm] (detector set in front of the source, normal to the input direction)

    float3 detector_center;   // Center of the detector straight ahead of the focal spot.
    detector_center.x = source_data->position[0].x + source_data->direction[0].x * detector_data->sdd;
    detector_center.y = source_data->position[0].y + source_data->direction[0].y * detector_data->sdd;
    detector_center.z = source_data->position[0].z + source_data->direction[0].z * detector_data->sdd;
        
    if ((detector_data->sdd)<1.0e-6)
    {
      printf("\n\n   !!read_input ERROR!! The source-to-detector distance must be positive. Input: ssd=%f!!\n\n", detector_data->sdd);
      exit(-2);
    }

/* !!DeBuG!! OLD WRONG FAN BEAM:  
    if ( (source_data->tan_phi_semiaperture < -1.0e-5) || (source_data->tan_theta_semiaperture < -1.0e-5) )   // If we enter a negative angle, the fan beam will cover exactly the detector surface.
    {
      source_data->tan_phi_semiaperture   = 0.5 * detector_data->width_X  / (detector_data->sdd);  // Set the aperture to cover the whole detector exactly (detector is at distance ssd, move to 1cm).
      source_data->tan_theta_semiaperture = 0.5 * detector_data->height_Z / (detector_data->sdd);
    }
*/
  if ( (theta_aperture < -1.0e-7) || (phi_aperture < -1.0e-7) )   // If we enter a negative angle, the fan beam will cover exactly the detector surface.
  {
    theta_aperture= 2.0 * atan(0.5*detector_data->height_Z/(detector_data->sdd)) * RAD2DEG;   // Optimum angles
    phi_aperture  = 2.0 * atan(0.5*detector_data->width_X/(detector_data->sdd)) * RAD2DEG;

    source_data->cos_theta_low = (float)( cos((90.0 - 0.5*theta_aperture)*DEG2RAD) );
    source_data->D_cos_theta   = (float)( -2.0*source_data->cos_theta_low );      // Theta aperture is symetric above and below 90 deg
    source_data->phi_low       = (float)( (90.0 - 0.5*phi_aperture)*DEG2RAD );
    source_data->D_phi         = (float)( phi_aperture*DEG2RAD );
    source_data->max_height_at_y1cm = (float) ( tan(0.5*theta_aperture*DEG2RAD) ); 
  }

  do
  {
    new_line_ptr = fgets(new_line, 250, file_ptr);
    if (new_line_ptr==NULL)
    {
      printf("\n\n   !!read_input ERROR!! Input file is not readable or does not contain the string \'SECTION CT SCAN\'!!\n");
      exit(-2);
    }
  }
  while(strstr(new_line,"SECTION CT")==NULL);  // Skip comments and empty lines until the section begins
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
  sscanf(new_line, "%d", num_projections);     // NUMBER OF PROJECTIONS (beam must be perpendicular to Z axis)
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
  sscanf(new_line, "%lf", D_angle);   // ANGLE BETWEEN PROJECTIONS [degrees] (360/num_projections for full CT)
  *D_angle = (*D_angle)*DEG2RAD;      // store the angle in radians

  // Calculate initial source angle:
  *initial_angle = acos((double)(source_data->direction[0].x));
  if (source_data->direction[0].y<0)
    *initial_angle = -(*initial_angle);     // Correct for the fact that positive and negative angles have the same ACOS
  if (*initial_angle<0.0)
    *initial_angle = (*initial_angle) + 2.0*PI;   // Make sure the angle is not negative, between [0,360) degrees.
  *initial_angle = (*initial_angle) - PI;   // Correct the fact that the source is opposite to the detector (180 degrees difference).
  if (*initial_angle<0.0)
    *initial_angle = (*initial_angle) + 2.0*PI;   // Make sure the initial angle is not negative, between [0,360) degrees..

  
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
  sscanf(new_line, "%lf %lf", angularROI_0, angularROI_1);   // ANGLES OF INTEREST (projections outside this interval will be skipped)
  if (*angularROI_0<-0.001 || *angularROI_1>360.001)
  {
    printf("\n\n   !!read_input ERROR!! The angles in the angular region of interest must be in the interval [0,360]. Input: %f, %f.\n\n", *angularROI_0, *angularROI_1);   // The reconstructed planes are always parallel to the XY plane.\n");
    exit(-2);
  }
  *angularROI_0 = (*angularROI_0 - 0.0001)*DEG2RAD;   // Store the angles of interest in radians, increasing a little the interval to avoid precission problems
  *angularROI_1 = (*angularROI_1 + 0.0001)*DEG2RAD;

  
  if (0 == (*num_projections))
    *num_projections = 1;      // Zero projections has the same effect as 1 projection (ie, no CT scan rotation). Negative values are allowed and the source rotates in opposite rotation.
  if ( (fabs(*num_projections) > 1) && (fabs(source_data->direction[0].z)>0.00001f) )
  {
    printf("\n\n   !!read_input ERROR!! Sorry, but currently we can only simulate CT scans when the source direction is perpendicular to the Z axis (ie, w=0).\n\n");   // The reconstructed planes are always parallel to the XY plane.\n");
    exit(-2);
  }
  

  do
  {
    new_line_ptr = fgets(new_line, 250, file_ptr);
    if (new_line_ptr==NULL)
    {
      printf("\n\n   !!read_input ERROR!! Input file is not readable or does not contain the string \'SECTION VOXELIZED GEOMETRY FILE\'!!\n");
      exit(-2);
    }
  }
  while(strstr(new_line,"SECTION VOXEL")==NULL);   // Skip comments and empty lines until the section begins
  new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
  trim_name(new_line, file_name_voxels);   // VOXEL GEOMETRY FILE (penEasy 2008 format)

  do
  {
    new_line_ptr = fgets(new_line, 250, file_ptr);
    if (new_line_ptr==NULL)
    {
      printf("\n\n   !!read_input ERROR!! Input file is not readable or does not contain the string \'SECTION MATERIAL FILE LIST\'!!\n");
      exit(-2);
    }
  }
  while(strstr(new_line,"SECTION MATERIAL")==NULL);   // Skip comments and empty lines until the section begins

  int i;
  for (i=0; i<MAX_MATERIALS; i++)
  {
    new_line_ptr = fgets_trimmed(new_line, 250, file_ptr);
    if (new_line_ptr==NULL)
      file_name_materials[i][0]='\n';   // The input file is allowed to finish without defining all the materials
    else
      trim_name(new_line, file_name_materials[i]);
  }
  // [Finish reading input file]

  /////////////////////////////////////////////////////////////////////////////

  // *** Set the rotation that will bring particles from the detector plane to +Y=(0,+1,0) through a rotation around X and around Z (counter-clock):
  double rotX, rotZ, cos_rX, cos_rZ, sin_rX, sin_rZ;
      // rotX = 1.5*PI - acos(source_data->direction.z);  // Rotate to +Y = (0,+1,0) --> rotX_0 = 3/2*PI == -PI/2
    rotX = acos(source_data->direction[0].z) - 0.5*PI;  // Rotate to +Y = (0,+1,0) --> rotX_0 =  -PI/2
      // rotX = 0.5*PI - acos(source_data->direction.z);  // Rotate to +Y = (0,+1,0) --> rotX_0 =  PI/2
  if ( (source_data->direction[0].x*source_data->direction[0].x + source_data->direction[0].y*source_data->direction[0].y) > 1.0e-8 )   // == u^2+v^2 > 0
  {
      // rotZ = 0.5*PI - acos(source_data->direction.x/sqrt(source_data->direction.x*source_data->direction.x + source_data->direction.y*source_data->direction.y));
    if (source_data->direction[0].y >= 0.0f)
      rotZ = 0.5*PI - acos(source_data->direction[0].x/sqrt(source_data->direction[0].x*source_data->direction[0].x + source_data->direction[0].y*source_data->direction[0].y));
    else
      rotZ = 0.5*PI - (-acos(source_data->direction[0].x/sqrt(source_data->direction[0].x*source_data->direction[0].x + source_data->direction[0].y*source_data->direction[0].y)));
  }
  else
    rotZ = 0.0;   // Vector pointing to +Z, do not rotate around Z then.
 
  // -- Set the rotation matrix RzRx (called inverse because moves from the correct position to the reference at +Y):
  cos_rX = cos(rotX);
  cos_rZ = cos(rotZ);
  sin_rX = sin(rotX);
  sin_rZ = sin(rotZ);

  // Rotation matrix RxRz:
  detector_data->rot_inv[0][0] =  cos_rZ;
  detector_data->rot_inv[0][1] = -sin_rZ;
  detector_data->rot_inv[0][2] =  0.0f;
  detector_data->rot_inv[0][3] =  cos_rX*sin_rZ;
  detector_data->rot_inv[0][4] =  cos_rX*cos_rZ;
  detector_data->rot_inv[0][5] = -sin_rX;
  detector_data->rot_inv[0][6] =  sin_rX*sin_rZ;
  detector_data->rot_inv[0][7] =  sin_rX*cos_rZ;
  detector_data->rot_inv[0][8] =  cos_rX;



  if ((source_data->direction[0].y > 0.99995f) && (*num_projections==1))
  {
    // Simulating a single projection and initial beam pointing to +Y: no rotation needed!!
    detector_data->rotation_flag = 0;
    detector_data->corner_min_rotated_to_Y[0].x = detector_center.x;
    detector_data->corner_min_rotated_to_Y[0].y = detector_center.y;
    detector_data->corner_min_rotated_to_Y[0].z = detector_center.z;

    MASTER_THREAD printf("       Source pointing to (0,1,0): maximizing code efficiency -> detector not rotated, initial location in voxels found faster.\n");  // -> the simulation will be faster than for other angles.");

  }
  else
  { // Rotation needed to set the detector perpendicular to +Y:
    detector_data->rotation_flag = 1;
    // -- Rotate the detector center to +Y:
    detector_data->corner_min_rotated_to_Y[0].x = detector_center.x*detector_data->rot_inv[0][0] + detector_center.y*detector_data->rot_inv[0][1] + detector_center.z*detector_data->rot_inv[0][2];
    detector_data->corner_min_rotated_to_Y[0].y = detector_center.x*detector_data->rot_inv[0][3] + detector_center.y*detector_data->rot_inv[0][4] + detector_center.z*detector_data->rot_inv[0][5];
    detector_data->corner_min_rotated_to_Y[0].z = detector_center.x*detector_data->rot_inv[0][6] + detector_center.y*detector_data->rot_inv[0][7] + detector_center.z*detector_data->rot_inv[0][8];

    MASTER_THREAD printf("       Rotations from the input direction to +Y [deg]: rotZ = %f , rotX = %f\n", rotZ*RAD2DEG, rotX*RAD2DEG);
    
  }
  // -- Set the lower corner (minimum) coordinates at the normalized orientation: +Y. The detector has thickness 0.
  detector_data->corner_min_rotated_to_Y[0].x = detector_data->corner_min_rotated_to_Y[0].x - 0.5*detector_data->width_X;
  detector_data->corner_min_rotated_to_Y[0].y = detector_data->corner_min_rotated_to_Y[0].y;
  detector_data->corner_min_rotated_to_Y[0].z = detector_data->corner_min_rotated_to_Y[0].z - 0.5*detector_data->height_Z;

  /////////////////////////////////////////////////////////////////////////////

  // *** Init the fan beam source model:

  if (1 == detector_data->rotation_flag)
  {
    // Initial beam NOT pointing to +Y: rotation is needed to move the sampled vector from (0,1,0) to the given direction!!
    rotX = 0.5*PI - acos(source_data->direction[0].z);         // ! Rotation about X: acos(wsrc)==theta, theta=90 for alpha=0, ie, +Y.
    rotZ = atan2(source_data->direction[0].y, source_data->direction[0].x) - 0.5*PI;   // ! Rotation about Z:  initial phi = 90 (+Y).  [ATAN2(v,u) = TAN(v/u), with the angle in the correct quadrant.
    cos_rX = cos(rotX);
    cos_rZ = cos(rotZ);
    sin_rX = sin(rotX);
    sin_rZ = sin(rotZ);
    // --Rotation around X (alpha) and then around Z (phi): Rz*Rx (oposite of detector rotation)
    source_data->rot_fan[0][0] =  cos_rZ;
    source_data->rot_fan[0][1] = -cos_rX*sin_rZ;
    source_data->rot_fan[0][2] =  sin_rX*sin_rZ;
    source_data->rot_fan[0][3] =  sin_rZ;
    source_data->rot_fan[0][4] =  cos_rX*cos_rZ;
    source_data->rot_fan[0][5] = -sin_rX*cos_rZ;
    source_data->rot_fan[0][6] =  0.0f;
    source_data->rot_fan[0][7] =  sin_rX;
    source_data->rot_fan[0][8] =  cos_rX;
    
    MASTER_THREAD printf("       Rotations from +Y to the input direction for the fan beam source model [deg]: rotZ = %f , rotX = %f\n", rotZ*RAD2DEG, rotX*RAD2DEG);
  }      

  /////////////////////////////////////////////////////////////////////////////

  // *** Allocate array for the 4 detected images (non-scattered, Compton, Rayleigh, multiple-scatter):
  *image_bytes = 4 * sizeof(unsigned long long int)*(detector_data->num_pixels.x)*(detector_data->num_pixels.y);
  (*image_ptr) = (unsigned long long int*) malloc(*image_bytes);
  if (*image_ptr==NULL)
  {
    printf("\n\n   !!malloc ERROR!! Not enough memory to allocate %d pixels for the 4 scatter images (%f Mbytes)!!\n\n", ((detector_data->num_pixels.x)*(detector_data->num_pixels.y)), (*image_bytes)/(1024.f*1024.f));
    exit(-2);
  }
  else
  {
    MASTER_THREAD printf("       Array for 4 scatter images correctly allocated (%f Mbytes)\n", (*image_bytes)/(1024.f*1024.f));
  }

  // *** Initialize the images to 0 in the CPU.
  register int j, pixels_per_image = (detector_data->num_pixels.x * detector_data->num_pixels.y);
  for (j=0; j<pixels_per_image; j++)
  {
    (*image_ptr)[j                   ] = (unsigned long long int)(0);   // Initialize non-scattered image
    (*image_ptr)[j+  pixels_per_image] = (unsigned long long int)(0);   // Initialize Compton image
    (*image_ptr)[j+2*pixels_per_image] = (unsigned long long int)(0);   // Initialize Rayleigh image
    (*image_ptr)[j+3*pixels_per_image] = (unsigned long long int)(0);   // Initialize multiple scattering image
  }
}



////////////////////////////////////////////////////////////////////////////////
//! Extract a file name from an input text line, trimming the initial blanks,
//! trailing comment (#) and stopping at the first blank (the file name should
//! not contain blanks).
//!
//!       @param[in] input_line   Input sentence with blanks and a trailing comment
//!       @param[out] file_name   Trimmed file name
////////////////////////////////////////////////////////////////////////////////
void trim_name(char* input_line, char* file_name)
{
  int a=0, b=0;
  
  // Discard initial blanks:
  while(' '==input_line[a])
  {
    a++;
  }

  // Read file name until a blank or a comment symbol (#) is found:
  while ((' '!=input_line[a])&&('#'!=input_line[a]))
  {
    file_name[b] = input_line[a];
    b++;
    a++;
  }
  
  file_name[b] = '\0';    // Terminate output string
}

////////////////////////////////////////////////////////////////////////////////
//! Read a line of text and trim initial blancks and trailing comments (#).
//!
//!       @param[in] num   Characters to read
//!       @param[in] file_ptr   Pointer to the input file stream
//!       @param[out] trimmed_line   Trimmed line from input file, skipping empty lines and comments
////////////////////////////////////////////////////////////////////////////////
char* fgets_trimmed(char* trimmed_line, int num, FILE* file_ptr)
{
  char  new_line[250];
  char *new_line_ptr = NULL;
  int a=0, b=0;
  trimmed_line[0] = '\0';   //  Init with a mark that means no file input
  
  do
  {
    a=0; b=0;
    new_line_ptr = fgets(new_line, num, file_ptr);   // Read new line
    if (new_line_ptr != NULL)
    {
      // Discard initial blanks:
      while(' '==new_line[a])
      {
        a++;
      }
      // Read file until a comment symbol (#) or end-of-line are found:
      while (('\n'!=new_line[a])&&('#'!=new_line[a]))
      {
        trimmed_line[b] = new_line[a];
        b++;
        a++;
      }
    }
  } while(new_line_ptr!=NULL &&  '\0'==trimmed_line[0]);   // Keep reading lines until end-of-file or a line that is not empty or only comment is found
  
  trimmed_line[b] = '\0';    // Terminate output string
  return new_line_ptr;
}



////////////////////////////////////////////////////////////////////////////////
//! Read the voxel data and allocate the material and density matrix.
//! Also find and report the maximum density defined in the geometry.
//!
// -- Sample voxel geometry file:
//
//   #  (comment lines...)
//   #
//   #   Voxel order: X runs first, then Y, then Z.
//   #
//   [SECTION VOXELS HEADER v.2008-04-13]
//   411  190  113      No. OF VOXELS IN X,Y,Z
//   5.000e-02  5.000e-02  5.000e-02    VOXEL SIZE (cm) ALONG X,Y,Z
//   1                  COLUMN NUMBER WHERE MATERIAL ID IS LOCATED
//   2                  COLUMN NUMBER WHERE THE MASS DENSITY IS LOCATED
//   1                  BLANK LINES AT END OF X,Y-CYCLES (1=YES,0=NO)
//   [END OF VXH SECTION]
//   1 0.00120479
//   1 0.00120479
//   ...
//
//!       @param[in] file_name_voxels  Name of the voxelized geometry file.
//!       @param[out] density_max  Array with the maximum density for each material in the voxels.
//!       @param[out] voxel_data   Pointer to a structure containing the voxel number and size.
//!       @param[out] voxel_mat_dens_ptr   Pointer to the vector with the voxel materials and densities.
////////////////////////////////////////////////////////////////////////////////
void load_voxels(int myID, char* file_name_voxels, float* density_max, struct voxel_struct* voxel_data, float2** voxel_mat_dens_ptr, unsigned int* voxel_mat_dens_bytes)
{
  char new_line[250];
  char *new_line_ptr = NULL;
  
  FILE* file_ptr = fopen(file_name_voxels, "r");
  if (file_ptr==NULL)
  {
    printf("\n\n   !!fopen ERROR!! File %s does not exist!!\n", file_name_voxels);
    exit(-2);
  }
  MASTER_THREAD printf("\n    -- Reading voxel file \'%s\':\n",file_name_voxels);
  MASTER_THREAD fflush(stdout);
  do
  {
    new_line_ptr = fgets(new_line, 250, file_ptr);
    if (new_line_ptr==NULL)
    {
      printf("\n\n   !!Reading ERROR!! File is not readable or does not contain the string \'[SECTION VOXELS HEADER\'!!\n");
      exit(-2);
    }
  }
  while(strstr(new_line,"[SECTION VOXELS")==NULL);   // Skip comments and empty lines until the header begins

  new_line_ptr = fgets(new_line, 250, file_ptr);   // Read full line (max. 250 characters).
  sscanf(new_line, "%d %d %d",&voxel_data->num_voxels.x, &voxel_data->num_voxels.y, &voxel_data->num_voxels.z);
  new_line_ptr = fgets(new_line, 250, file_ptr);
  sscanf(new_line, "%f %f %f", &voxel_data->inv_voxel_size.x, &voxel_data->inv_voxel_size.y, &voxel_data->inv_voxel_size.z);
  do
  {
    new_line_ptr = fgets(new_line, 250, file_ptr);
    if (new_line_ptr==NULL)
    {
      printf("\n\n   !!Reading ERROR!! File is not readable or does not contain the string \'[END OF VXH SECTION]\'!!\n");
      exit(-2);
    }
  }
  while(strstr(new_line,"[END OF VXH SECTION")==NULL);   // Skip rest of the header

  // -- Store the size of the voxel bounding box (used in the source function):
  voxel_data->size_bbox.x = voxel_data->num_voxels.x * voxel_data->inv_voxel_size.x;
  voxel_data->size_bbox.y = voxel_data->num_voxels.y * voxel_data->inv_voxel_size.y;
  voxel_data->size_bbox.z = voxel_data->num_voxels.z * voxel_data->inv_voxel_size.z;

  
  MASTER_THREAD printf("       Number of voxels in the input geometry file: %d x %d x %d =  %d\n", voxel_data->num_voxels.x, voxel_data->num_voxels.y, voxel_data->num_voxels.z, (voxel_data->num_voxels.x*voxel_data->num_voxels.y*voxel_data->num_voxels.z));
  MASTER_THREAD printf("       Size of the input voxels: %f x %f x %f cm\n", voxel_data->inv_voxel_size.x, voxel_data->inv_voxel_size.y, voxel_data->inv_voxel_size.z);
  MASTER_THREAD printf("       Voxel bounding box size: %f x %f x %f cm\n", voxel_data->size_bbox.x, voxel_data->size_bbox.y,  voxel_data->size_bbox.z);
  // printf("       The geometry must be given in two columns, with the voxel density in the second column.\n");
  // printf("       The  X,Y-cycles may, or may not, be separated by blank lines.\n");

  
  // -- Store the inverse of the pixel sides (in cm) to speed up the particle location in voxels.
  voxel_data->inv_voxel_size.x = 1.0f/(voxel_data->inv_voxel_size.x);
  voxel_data->inv_voxel_size.y = 1.0f/(voxel_data->inv_voxel_size.y);
  voxel_data->inv_voxel_size.z = 1.0f/(voxel_data->inv_voxel_size.z);

  // -- Allocate the voxel matrix and store array size:
  *voxel_mat_dens_bytes = sizeof(float2)*(voxel_data->num_voxels.x)*(voxel_data->num_voxels.y)*(voxel_data->num_voxels.z);
  *voxel_mat_dens_ptr    = (float2*) malloc(*voxel_mat_dens_bytes);
  if (*voxel_mat_dens_ptr==NULL)
  {
    printf("\n\n   !!malloc ERROR!! Not enough memory to allocate %d voxels (%f Mbytes)!!\n\n", (voxel_data->num_voxels.x*voxel_data->num_voxels.y*voxel_data->num_voxels.z), (*voxel_mat_dens_bytes)/(1024.f*1024.f));
    exit(-2);
  }
  MASTER_THREAD printf("\n    -- Initializing the voxel material and density vector (%f Mbytes)\n", (*voxel_mat_dens_bytes)/(1024.f*1024.f));

  // -- Read the voxel densities:
  MASTER_THREAD printf("       Reading the voxel densities... ");
      
  int i, j, k, read_lines=0, dummy_material, read_items;
  float dummy_density;
  float2 *voxels_ptr = *voxel_mat_dens_ptr;

  for (k=0; k<MAX_MATERIALS; k++)
    density_max[k] = -999.0f;   // Init array with an impossible low density value
  

  for(k=0; k<(voxel_data->num_voxels.z); k++)
  {
    for(j=0; j<(voxel_data->num_voxels.y); j++)
    {
      for(i=0; i<(voxel_data->num_voxels.x); i++)
      {
        read_items = fscanf(file_ptr,"%d %f", &dummy_material, &dummy_density);    // Read the next 2 numbers
        if (read_items!=2)
          printf("\n   !!WARNING!! Expecting to read 2 items (material and density). read_items=%d, read_lines=%d \n", read_items, read_lines);
          
        new_line_ptr = fgets(new_line, 250, file_ptr);                             // Continue reading until end-of-line

        if (dummy_material>MAX_MATERIALS)
        {
          printf("\n\n   !!ERROR!! Voxel material number too high: #mat=%d, MAX_MATERIALS=%d\n\n", dummy_material, MAX_MATERIALS);
          exit(-2);
        }
        
        if (dummy_density > density_max[dummy_material-1])
          density_max[dummy_material-1] = dummy_density;  // Store maximum density for each material

        (*voxels_ptr).x = (float)(dummy_material)+0.0001f;  // Assign material value as float (the integer value will be recovered by truncation)
        (*voxels_ptr).y = dummy_density;      // Assign density value
        voxels_ptr++;                         // Move to next voxel

        read_lines++;
      }
    }
  }
  MASTER_THREAD printf("Total number of voxels read: %d\n",read_lines);
  fclose(file_ptr);     // Close input file
}


////////////////////////////////////////////////////////////////////////////////
//! Read the material input files and set the mean free paths and the "linear_interp" structures.
//! Find the material nominal density. Set the Woodcock trick data.
//
// -- Sample material data file (data obtained from the PENELOPE 2006 database and models):
//
//    [MATERIAL NAME]
//     Water
//    [NOMINAL DENSITY (g/cm^3)]
//     1.000
//    [NUMBER OF DATA VALUES]
//     4096
//    [MEAN FREE PATHS :: Energy (eV) || Rayleigh | Compton | Photoelectric | Pair-production | TOTAL (cm)]
//     1.00000E+03  7.27451E-01  9.43363E+01  2.45451E-04  1.00000E+35  2.45367E-04
//     5.00000E+03  1.80004E+00  8.35996E+00  2.38881E-02  1.00000E+35  2.35089E-02
//     1.00000E+04  4.34941E+00  6.26746E+00  2.02568E-01  1.00000E+35  1.87755E-01
//     ...
//     #[RAYLEIGH INTERACTIONS (RITA sampling  of atomic form factor from EPDL database)]
//     ...
//     #[COMPTON INTERACTIONS (relativistic impulse model with approximated one-electron analytical profiles)]
//     ...
//
//!       @param[in] file_name_materials    Array with the names of the material files.
//!       @param[in] density_max   maximum density in the geometry (needed to set Woodcock trick)
//!       @param[out] density_nominal   Array with the nominal density of the materials read
//!       @param[out] mfp_table_data   Constant values for the linear interpolation
//!       @param[out] mfp_table_a_ptr   First element for the linear interpolation.
//!       @param[out] mfp_table_b_ptr   Second element for the linear interpolation.
////////////////////////////////////////////////////////////////////////////////
void load_material(int myID, char file_name_materials[MAX_MATERIALS][250], float* density_max, float* density_nominal, struct linear_interp* mfp_table_data, float2** mfp_Woodcock_table_ptr, int* mfp_Woodcock_table_bytes, float3** mfp_table_a_ptr, float3** mfp_table_b_ptr, int* mfp_table_bytes, struct rayleigh_struct *rayleigh_table_ptr, struct compton_struct *compton_table_ptr)
{
  char new_line[250];
  char *new_line_ptr = NULL;
  int mat, i, bin, input_num_values = 0, input_rayleigh_values = 0, input_num_shells = 0;
  double delta_e=-99999.0;

  // -- Init the number of shells to 0 for all materials
  for (mat=0; mat<MAX_MATERIALS; mat++)
    compton_table_ptr->noscco[mat] = 0;
    
          
  // --Read the material data files:
  MASTER_THREAD printf("\n    -- Reading the material data files (MAX_MATERIALS=%d):\n", MAX_MATERIALS);
  for (mat=0; mat<MAX_MATERIALS; mat++)
  {
    if ((file_name_materials[mat][0]=='\0') || (file_name_materials[mat][0]=='\n') || (density_max[mat]<0))  //  Empty file name, or material not found in the voxels
       continue;   // Re-start loop for next material

    MASTER_THREAD printf("         Mat %d: File \'%s\'\n", mat, file_name_materials[mat]);
//     printf("    -- Reading material file #%d: \'%s\'\n", mat, file_name_materials[mat]);

    FILE* file_ptr = fopen(file_name_materials[mat], "r");
    if (file_ptr==NULL)
    {
      printf("\n\n   !!fopen ERROR!! File %d \'%s\' does not exist!!\n", mat, file_name_materials[mat]);
      exit(-2);
    }
    do
    {
      new_line_ptr = fgets(new_line, 250, file_ptr);   // Read full line (max. 250 characters).
      if (new_line_ptr==NULL)
      {
        printf("\n\n   !!Reading ERROR!! File is not readable or does not contain the string \'[NOMINAL DENSITY\'!!\n");
        exit(-2);
      }
    }
    while(strstr(new_line,"[NOMINAL DENSITY")==NULL);   // Skip rest of the header

    // Read the material nominal density:
    new_line_ptr = fgets(new_line, 250, file_ptr);
    sscanf(new_line, "# %f", &density_nominal[mat]);
    MASTER_THREAD printf("                Nominal density = %f g/cm^3; Max mat density in voxels = %f\n", density_nominal[mat], density_max[mat]);

    // --For the first material, set the number of energy values and allocate table arrays:
    new_line_ptr = fgets(new_line, 250, file_ptr);
    new_line_ptr = fgets(new_line, 250, file_ptr);
    sscanf(new_line, "# %d", &input_num_values);
    if (0==mat)
    {
      mfp_table_data->num_values = input_num_values;
      MASTER_THREAD printf("                Number of energy values in the mean free path database: %d.\n", input_num_values);

      // Allocate memory for the linear interpolation arrays:
      *mfp_Woodcock_table_bytes = sizeof(float2)*input_num_values;
      *mfp_Woodcock_table_ptr   = (float2*) malloc(*mfp_Woodcock_table_bytes);  // Allocate space for the 2 parameter table
      *mfp_table_bytes = sizeof(float3)*input_num_values*MAX_MATERIALS;
      *mfp_table_a_ptr = (float3*) malloc(*mfp_table_bytes);  // Allocate space for the 4 MFP tables
      *mfp_table_b_ptr = (float3*) malloc(*mfp_table_bytes);
      *mfp_table_bytes = sizeof(float3)*input_num_values*MAX_MATERIALS;

      if (input_num_values>MAX_ENERGYBINS)
      {
        printf("\n\n   !!load_material ERROR!! Too many energy bins (Input bins=%d): increase parameter MAX_ENERGYBINS=%d!!\n\n", input_num_values, MAX_ENERGYBINS);
        exit(-2);
      }
      
      if ((NULL==*mfp_Woodcock_table_ptr)||(NULL==*mfp_table_a_ptr)||(NULL==*mfp_table_b_ptr))
      {
        printf("\n\n   !!malloc ERROR!! Not enough memory to allocate the linear interpolation data: %d bytes!!\n\n", (*mfp_Woodcock_table_bytes+2*(*mfp_table_bytes)));
        exit(-2);
      }
      else
      {
        MASTER_THREAD printf("                Linear interpolation data correctly allocated (%f Mbytes)\n", (*mfp_Woodcock_table_bytes+2*(*mfp_table_bytes))/(1024.f*1024.f));
      }
      for (i=0; i<input_num_values; i++)
      {
        (*mfp_Woodcock_table_ptr)[i].x = 99999999.99f;    // Init this array with a huge MFP, the minimum values are calculated below
      }
    }
    else   // Materials after first
    {
      if (input_num_values != mfp_table_data->num_values)
      {
        printf("\n\n   !!load_material ERROR!! Incorrect number of energy values given in material \'%s\': input=%d, expected=%d\n",file_name_materials[mat], input_num_values, mfp_table_data->num_values);
        exit(-2);
      }
    }

    // -- Read the mean free paths (and Rayleigh cumulative prob):
    new_line_ptr = fgets(new_line, 250, file_ptr);
    new_line_ptr = fgets(new_line, 250, file_ptr);
    double d_energy, d_rayleigh, d_compton, d_photelectric, d_total_mfp, d_pmax, e_last=-1.0;
    
    for (i=0; i<input_num_values; i++)
    {

      new_line_ptr = fgets(new_line, 250, file_ptr);
      sscanf(new_line,"  %le  %le  %le  %le  %le  %le", &d_energy, &d_rayleigh, &d_compton, &d_photelectric, &d_total_mfp, &d_pmax);

      // Find and store the minimum total MFP at the current energy, for every material's maximum density:
      float temp_mfp = d_total_mfp*(density_nominal[mat])/(density_max[mat]);
      if (temp_mfp < (*mfp_Woodcock_table_ptr)[i].x)
        (*mfp_Woodcock_table_ptr)[i].x = temp_mfp;       // Store minimum total mfp [cm]

      // Store the inverse MFP data points with [num_values rows]*[MAX_MATERIALS columns]
      (*mfp_table_a_ptr)[i*(MAX_MATERIALS)+mat].x = 1.0/(d_total_mfp*density_nominal[mat]);   // inverse TOTAL mfp * nominal density
      (*mfp_table_a_ptr)[i*(MAX_MATERIALS)+mat].y = 1.0/(d_compton  *density_nominal[mat]);   // inverse Compton mfp * nominal density
      (*mfp_table_a_ptr)[i*(MAX_MATERIALS)+mat].z = 1.0/(d_rayleigh *density_nominal[mat]);   // inverse Rayleigh mfp * nominal density

      rayleigh_table_ptr->pmax[i*(MAX_MATERIALS)+mat] = d_pmax;    // Store the maximum cumulative probability of atomic form factor F^2 for

      if (0==i && 0==mat)
      {
        mfp_table_data->e0  = d_energy;   // Store the first energy of the first material
      }

      if (0==i)
      {
        if (fabs(d_energy-mfp_table_data->e0)>1.0e-9)
        {
          printf("\n\n   !!load_material ERROR!! Incorrect first energy value given in material \'%s\': input=%f, expected=%f\n", file_name_materials[mat], d_energy, mfp_table_data->e0);
          exit(-2);
        }
      }
      else if (1==i)
      {
        delta_e = d_energy-e_last;
      }
      else if (i>1)
      {
        if (((fabs((d_energy-e_last)-delta_e))/delta_e)>0.001)  // Tolerate up to a 0.1% relative variation in the delta e (for each bin) to account for possible precission errors reading the energy values
        {
          printf("  !!ERROR reading material data!! The energy step between mean free path values is not constant!!\n      (maybe not enough decimals given for the energy values)\n      #value = %d, First delta: %f , New delta: %f, Energy: %f ; Rel.Dif=%f\n", i, delta_e, (d_energy-e_last), d_energy,((fabs((d_energy-e_last)-delta_e))/delta_e));
          exit(-2);
        }
      }
      e_last = d_energy;
    }
    
    if (0==mat) MASTER_THREAD printf("                Minimum energy = %f, Maximum = %f; Delta E (1st bin) = %f\n", (mfp_table_data->e0), e_last, delta_e);

    // -- Store the inverse of delta energy:
    mfp_table_data->ide = 1.0f/delta_e;

    // -- Store MFP data slope 'b' (.y for Woodcock):
    for (i=0; i<(input_num_values-1); i++)
    {
      bin = i*MAX_MATERIALS+mat;                   // Set current bin, skipping MAX_MATERIALS columns
      (*mfp_table_b_ptr)[bin].x = ((*mfp_table_a_ptr)[bin+MAX_MATERIALS].x - (*mfp_table_a_ptr)[bin].x) / delta_e;
      (*mfp_table_b_ptr)[bin].y = ((*mfp_table_a_ptr)[bin+MAX_MATERIALS].y - (*mfp_table_a_ptr)[bin].y) / delta_e;
      (*mfp_table_b_ptr)[bin].z = ((*mfp_table_a_ptr)[bin+MAX_MATERIALS].z - (*mfp_table_a_ptr)[bin].z) / delta_e;
    }
    // After maximum energy (last bin), assume constant slope:
    (*mfp_table_b_ptr)[(input_num_values-1)*MAX_MATERIALS+mat] = (*mfp_table_b_ptr)[(input_num_values-2)*MAX_MATERIALS+mat];

    // -- Rescale the 'a' parameter (.x for Woodcock) as if the bin started at energy = 0: we will not have to rescale to the bin minimum energy every time
    for (i=0; i<input_num_values; i++)
    {
      d_energy = mfp_table_data->e0 + i*delta_e;   // Set current bin lowest energy value
      bin = i*MAX_MATERIALS+mat;                   // Set current bin, skipping MAX_MATERIALS columns
      (*mfp_table_a_ptr)[bin].x = (*mfp_table_a_ptr)[bin].x - d_energy*(*mfp_table_b_ptr)[bin].x;
      (*mfp_table_a_ptr)[bin].y = (*mfp_table_a_ptr)[bin].y - d_energy*(*mfp_table_b_ptr)[bin].y;
      (*mfp_table_a_ptr)[bin].z = (*mfp_table_a_ptr)[bin].z - d_energy*(*mfp_table_b_ptr)[bin].z;
    }

    // -- Reading data for RAYLEIGH INTERACTIONS (RITA sampling  of atomic form factor from EPDL database):
    do
    {
      new_line_ptr = fgets(new_line, 250, file_ptr);
      if (feof(file_ptr)!=0)
      {
        printf("\n\n   !!End-of-file ERROR!! Rayleigh data not found: \"#[DATA VALUES...\" in file \'%s\'. Last line read: %s\n\n", file_name_materials[mat], new_line);
        exit(-2);
      }
    }
    while(strstr(new_line,"[DATA VALUES")==NULL);   // Skip all lines until this text is found
      
    new_line_ptr = fgets(new_line, 250, file_ptr);     // Read the number of data points in Rayleigh
    sscanf(new_line, "# %d", &input_rayleigh_values);
        
    if (input_rayleigh_values != NP_RAYLEIGH)
    {
      printf("\n\n   !!ERROR!! The number of values for Rayleigh sampling is different than the allocated space: input=%d, NP_RAYLEIGH=%d. File=\'%s\'\n", input_rayleigh_values, NP_RAYLEIGH, file_name_materials[mat]);
      exit(-2);
    }
    new_line_ptr = fgets(new_line, 250, file_ptr);    // Comment line:  #[SAMPLING DATA FROM COMMON/CGRA/: X, P, A, B, ITL, ITU]
    for (i=0; i<input_rayleigh_values; i++)
    {
      int itlco_tmp, ituco_tmp;
      bin = NP_RAYLEIGH*mat + i;

      new_line_ptr = fgets(new_line, 250, file_ptr);
      sscanf(new_line,"  %e  %e  %e  %e  %d  %d", &(rayleigh_table_ptr->xco[bin]), &(rayleigh_table_ptr->pco[bin]),
                                                  &(rayleigh_table_ptr->aco[bin]), &(rayleigh_table_ptr->bco[bin]),
                                                  &itlco_tmp, &ituco_tmp);

      rayleigh_table_ptr->itlco[bin] = (unsigned char) itlco_tmp;
      rayleigh_table_ptr->ituco[bin] = (unsigned char) ituco_tmp;
                                                  
    }
    //  printf("    -- Rayleigh sampling data read. Input values = %d\n",input_rayleigh_values);

    // -- Reading COMPTON INTERACTIONS data (relativistic impulse model with approximated one-electron analytical profiles):
    do
    {
      new_line_ptr = fgets(new_line, 250, file_ptr);
      if (feof(file_ptr)!=0)
      {
        printf("\n\n   !!End-of-file ERROR!! Compton data not found: \"[NUMBER OF SHELLS]\" in file \'%s\'. Last line read: %s\n\n", file_name_materials[mat], new_line);
        exit(-2);
      }
    }
    while(strstr(new_line,"[NUMBER OF SHELLS")==NULL);   // Skip all lines until this text is found
    new_line_ptr = fgets(new_line, 250, file_ptr);
    sscanf(new_line, "# %d", &input_num_shells);      // Read the NUMBER OF SHELLS
    if (input_num_shells>MAX_SHELLS)
    {
      printf("\n\n   !!ERROR!! Too many shells for Compton interactions in file \'%s\': input=%d, MAX_SHELLS=%d\n", file_name_materials[mat], input_num_shells, MAX_SHELLS);
      exit(-2);
    }
    compton_table_ptr->noscco[mat] = input_num_shells;   // Store number of shells for this material in structure
    new_line_ptr = fgets(new_line, 250, file_ptr);    // Comment line:  #[SHELL INFORMATION FROM COMMON/CGCO/: FCO, UICO, FJ0, KZCO, KSCO]
    int kzco_dummy, ksco_dummy;
    for (i=0; i<input_num_shells; i++)
    {

      bin = mat + i*MAX_MATERIALS;

      new_line_ptr = fgets(new_line, 250, file_ptr);
      sscanf(new_line," %e  %e  %e  %d  %d", &(compton_table_ptr->fco[bin]), &(compton_table_ptr->uico[bin]),
                                              &(compton_table_ptr->fj0[bin]), &kzco_dummy, &ksco_dummy);
    }
  
    fclose(file_ptr);    // Material data read. Close the current material input file
    
  }  // ["for" loop: continue with next material]


  // -- Store Woodcock MFP slope in component '.y':
  for (i=0; i<(mfp_table_data->num_values-1); i++)
    (*mfp_Woodcock_table_ptr)[i].y = ((*mfp_Woodcock_table_ptr)[i+1].x - (*mfp_Woodcock_table_ptr)[i].x)/delta_e;

  // -- Rescale the first parameter in component .x for Woodcock
  for (i=0; i<mfp_table_data->num_values; i++)
  {
    (*mfp_Woodcock_table_ptr)[i].x = (*mfp_Woodcock_table_ptr)[i].x - (mfp_table_data->e0 + i*delta_e)*(*mfp_Woodcock_table_ptr)[i].y;
  }
  
}
////////////////////////////////////////////////////////////////////////////////



#ifdef USING_CUDA
////////////////////////////////////////////////////////////////////////////////
//!  Sets the CUDA enabled GPU that will be used in the simulation.
//!  Allocates and copies the simulation data in the GPU global and constant memories.
//!
////////////////////////////////////////////////////////////////////////////////
void init_CUDA_device( int* gpu_id, int myID,
      /*Variables to GPU constant memory:*/ struct voxel_struct* voxel_data, struct source_struct* source_data, struct detector_struct* detector_data, struct linear_interp* mfp_table_data,
      /*Variables to GPU global memory:*/ float2* voxel_mat_dens, float2** voxel_mat_dens_device, unsigned int voxel_mat_dens_bytes,
        unsigned long long int* image, unsigned long long int** image_device, int image_bytes,
        float2* mfp_Woodcock_table, float2** mfp_Woodcock_table_device, int mfp_Woodcock_table_bytes,
        float3* mfp_table_a, float3* mfp_table_b, float3** mfp_table_a_device, float3** mfp_table_b_device, int mfp_table_bytes,
        struct rayleigh_struct* rayleigh_table, struct rayleigh_struct** rayleigh_table_device,
        struct compton_struct* compton_table, struct compton_struct** compton_table_device )
{
  int deviceCount, coresPerSM;
  cutilSafeCall(cudaGetDeviceCount(&deviceCount));
  if (0==deviceCount)
  {
    printf("\n  !!ERROR!! No CUDA enabled GPU detected!!\n\n");
    exit(-1);
  }
  if ( ((*gpu_id)>(deviceCount-1)) || ((*gpu_id)<0) )
  {
    printf("\n  !!WARNING!! The input GPU number is not valid: input_GPU=%d, maximum GPU number=%d.\n", (*gpu_id), deviceCount-1);
    // printf("              The device with the maximum Gflop count will be automatically selected.\n");
    // (*gpu_id) = cutGetMaxGflopsDeviceId();
    exit(-3);
  }

  cutilSafeCall(cudaSetDevice(*gpu_id));   // Set the GPU device.

  cudaDeviceProp deviceProp;
  cutilSafeCall(cudaGetDeviceProperties(&deviceProp, *gpu_id));
  if (deviceProp.major>99 || deviceProp.minor>99)
  {
    printf("\n  !!ERROR!! The selected GPU device does not support CUDA!! GPU_id=%d, deviceCount=%d, compute capability=%d.%d\n\n", (*gpu_id), deviceCount, deviceProp.major,deviceProp.minor);
    exit(-1);
  }

  if (deviceProp.major>1)
  {
    coresPerSM = 32;   // Set number of cores per microprocessor for Fermi GPUs (compute capability 2.x)
    
#ifdef LARGE_CACHE  
    // -- Compute capability > 1: set a large L1 cache for the global memory, reducing the size of the shared memory:
    //       cudaFuncCachePreferShared: shared memory is 48 KB
    //       cudaFuncCachePreferL1: shared memory is 16 KB
    //       cudaFuncCachePreferNone: no preference
    printf("\n       ==> CUDA: LARGE_CACHE defined --> setting a large global memory cache (L1) and a small shared memory (cudaFuncCachePreferL1).\n");
    cudaFuncSetCacheConfig(track_particles, cudaFuncCachePreferL1);            // !!DeBuG!! Set a large cache instead of a large shared memory.
// #else
// -- Using default:
// printf("\n       ==> CUDA: LARGE_CACHE not defined --> setting a large shared memory and a small global memory cache (cudaFuncCachePreferShared).\n");
//    cudaFuncSetCacheConfig(track_particles, cudaFuncCachePreferShared);            //!!DeBuG!! Setting size of shared memory/global cache
#endif

  }
  else
    coresPerSM = 8;   // Set number of cores per microprocessor before Fermi (compute capability 1.x)

  // -- Reading the device properties as shown in NVIDIA's SDK sample code "deviceQuery"
  printf("\n       ==> CUDA: %d CUDA enabled GPU detected! Using device #%d: \"%s\"\n", deviceCount, (*gpu_id), deviceProp.name);    
  printf("                 Compute capability: %d.%d, Number multiprocessors: %d, Number cores: %d\n", deviceProp.major, deviceProp.minor, deviceProp.multiProcessorCount, coresPerSM*deviceProp.multiProcessorCount);
  printf("                 Clock rate: %.2f GHz, Global memory: %.3f Mbyte, Constant memory: %.2f kbyte\n", deviceProp.clockRate*1.0e-6f, deviceProp.totalGlobalMem/(1024.f*1024.f), deviceProp.totalConstMem/1024.f);
  printf("                 Shared memory per block: %.2f kbyte, Registers per block: %.2f kbyte\n", deviceProp.sharedMemPerBlock/1024.f, deviceProp.regsPerBlock/1024.f);
  int driverVersion = 0, runtimeVersion = 0;  
  cudaDriverGetVersion(&driverVersion);
  cudaRuntimeGetVersion(&runtimeVersion);
  printf("                 CUDA Driver Version: %d.%d, Runtime Version: %d.%d\n", driverVersion/1000, driverVersion%100, runtimeVersion/1000, runtimeVersion%100);

  if (0!=deviceProp.kernelExecTimeoutEnabled)
  {
    printf("\n   !!ERROR!! The selected GPU is connected to an X-Win server and the kernel run time is limited to 5 sec. Aborting execution!!");
    exit(-1);
  }    

  unsigned int timer = 0;
  cutilCheckError(cutCreateTimer(&timer));
  cutilCheckError(cutStartTimer(timer));

  // -- Allocate the constant variables in the device:
  cutilSafeCall(cudaMemcpyToSymbol("voxel_data_CONST",     voxel_data,     sizeof(struct voxel_struct)));
  cutilSafeCall(cudaMemcpyToSymbol("source_data_CONST",    source_data,    sizeof(struct source_struct)));
  cutilSafeCall(cudaMemcpyToSymbol("detector_data_CONST",  detector_data,  sizeof(struct detector_struct)));
  cutilSafeCall(cudaMemcpyToSymbol("mfp_table_data_CONST", mfp_table_data, sizeof(struct linear_interp)));

  double total_mem = sizeof(struct voxel_struct)+sizeof(struct source_struct)+sizeof(struct detector_struct)+sizeof(struct linear_interp);
  MASTER_THREAD printf("       ==> CUDA: Structures successfully copied to the device. CONSTANT memory used: %lf kbytes (%.1lf%%)\n", total_mem/1024.0, 100.0*total_mem/deviceProp.totalConstMem);

  // -- Allocate the device memory:
  cutilSafeCall(cudaMalloc((void**) voxel_mat_dens_device, voxel_mat_dens_bytes));
  cutilSafeCall(cudaMalloc((void**) image_device, image_bytes));
  cutilSafeCall(cudaMalloc((void**) mfp_Woodcock_table_device, mfp_Woodcock_table_bytes));
  cutilSafeCall(cudaMalloc((void**) mfp_table_a_device, mfp_table_bytes));
  cutilSafeCall(cudaMalloc((void**) mfp_table_b_device, mfp_table_bytes));
  cutilSafeCall(cudaMalloc((void**) rayleigh_table_device, sizeof(struct rayleigh_struct)));
  cutilSafeCall(cudaMalloc((void**) compton_table_device,  sizeof(struct compton_struct)));

  total_mem = voxel_mat_dens_bytes+image_bytes+mfp_Woodcock_table_bytes+2*mfp_table_bytes+sizeof(struct compton_struct)+sizeof(struct rayleigh_struct);
  if (*voxel_mat_dens_device==NULL || *image_device==NULL || *mfp_Woodcock_table_device==NULL ||
      *mfp_table_a_device==NULL || *mfp_table_a_device==NULL || *rayleigh_table_device==NULL || *compton_table_device==NULL)
  {
    printf("\n cudaMalloc ERROR!! Device global memory not correctly allocated!! (%lf Mbytes)\n", total_mem/(1024.0*1024.0));
    exit(-1);
  }
  else
  {
    MASTER_THREAD printf("       ==> CUDA: Device global memory correctly allocated. GLOBAL memory used: %lf Mbytes (%.1lf%%)\n", total_mem/(1024.0*1024.0), 100.0*total_mem/deviceProp.totalGlobalMem);
  }

  // --Copy the host memory to the device:
  cutilSafeCall(cudaMemcpy(*voxel_mat_dens_device, voxel_mat_dens, voxel_mat_dens_bytes, cudaMemcpyHostToDevice));
  cutilSafeCall(cudaMemcpy(*mfp_Woodcock_table_device, mfp_Woodcock_table, mfp_Woodcock_table_bytes, cudaMemcpyHostToDevice));
  cutilSafeCall(cudaMemcpy(*mfp_table_a_device, mfp_table_a, mfp_table_bytes, cudaMemcpyHostToDevice));
  cutilSafeCall(cudaMemcpy(*mfp_table_b_device, mfp_table_b, mfp_table_bytes, cudaMemcpyHostToDevice));
  cutilSafeCall(cudaMemcpy(*rayleigh_table_device, rayleigh_table, sizeof(struct rayleigh_struct), cudaMemcpyHostToDevice));
  cutilSafeCall(cudaMemcpy(*compton_table_device, compton_table, sizeof(struct compton_struct), cudaMemcpyHostToDevice));


  //   --Init the image array to 0 using a GPU kernel instead of cudaMemcpy:
  //     Simple version: cutilSafeCall( cudaMemcpy( image_device, image, image_bytes, cudaMemcpyHostToDevice) );

  int pixels_per_image = detector_data->num_pixels.x * detector_data->num_pixels.y;
  MASTER_THREAD printf("       ==> CUDA: Launching kernel to initialize device image to 0: number of blocks = %d, threads per block = 128\n", (int)ceil(pixels_per_image/128.0f) );

  init_image_array_GPU<<<(int)(ceil(pixels_per_image/128.0f)),128>>>(*image_device, pixels_per_image);
    cudaThreadSynchronize();      // Force the runtime to wait until all device tasks have completed
    cutilCheckMsg(" !!Kernel execution failed initializing the image array!! ");  // Check if kernel execution generated any error:

  cutilCheckError(cutStopTimer(timer));
  MASTER_THREAD printf("                 Time spent allocating and copying memory to the device: %.6f s\n", 0.001f*cutGetTimerValue( timer));
  cutilCheckError(cutDeleteTimer(timer));

}
#endif
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
//! Report the final results, from the host CPU.
//!
//!       @param[in] file_name_output   File where tallied image is reported
//!       @param[in] detector_data   Detector description read from the input file (pointer to detector_struct)
//!       @param[in] image  Tallied image (in meV per pixel)
//!       @param[in] time_elapsed   Time elapsed during the main loop execution (in seconds)
//!       @param[in] total_histories   Total number of x-rays simulated
////////////////////////////////////////////////////////////////////////////////
int report_host(char* file_name_output, struct detector_struct* detector_data, struct source_struct* source_data, unsigned long long int* image, double time_elapsed, unsigned long long int total_histories, int current_projection, int num_projections, double D_angle, double initial_angle, int myID, int numprocs)
{
    // printf("\n           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    // printf("           ~~ Simulation performance quick report ~~\n");
    // printf("           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


  //  -Find current angle
  double current_angle = initial_angle+current_projection*D_angle;
    if (current_angle<0.0)
    current_angle += 2.0*PI;   // Make sure the angle is not negative.
  else if (current_angle>=2.0*PI)
    current_angle -= 2.0*PI;   // Make sure the angle is not above 360 degrees.

  // -- Report data:
  printf("\n          *** SIMULATION PERFORMANCE REPORT ***\n");
  if(num_projections!=1)   // Output the projection angle when simulating a CT:
    printf("              Projection %d of %d. Angle from X axis: %lf\n", current_projection, num_projections-1, current_angle*RAD2DEG);
#ifdef USING_MPI
  printf("              Computed by the MPI thread %d of %d\n", myID+1, numprocs);
#endif
  printf("              Simulated x rays:    %lld\n", total_histories);
  printf("              Simulation time [s]: %.2f\n", time_elapsed);
  if (time_elapsed>0.000001)
    printf("              Speed [x-rays/s]:    %.2f\n", ((double)total_histories)/time_elapsed);

  FILE* file_ptr = fopen(file_name_output, "w");
  
  if (file_ptr==NULL)
  {
    printf("\n\n   !!fopen ERROR!! File %s can not be opened!!\n", file_name_output);
    exit(-3);
  }

  fprintf(file_ptr, "# \n");
#ifdef USING_CUDA
  fprintf(file_ptr, "#  *** SIMULATION IN THE GPU USING CUDA ***\n");
#else
  fprintf(file_ptr, "#  *** SIMULATION IN THE CPU ***\n");
#endif
  fprintf(file_ptr, "#\n");
  fprintf(file_ptr, "#  Image created counting the energy arriving at each pixel.\n");
  fprintf(file_ptr, "#  Pixel value units: eV/cm^2 per history\n");
  if(num_projections!=1)   // Output the projection angle when simulating a CT:
    fprintf(file_ptr, "#  CT projection %d of %d. Angle from X axis: %lf\n", current_projection, num_projections-1, current_angle*RAD2DEG);
#ifdef USING_MPI
  fprintf(file_ptr, "#  Computed by the MPI thread %d of %d\n", myID+1, numprocs);
#endif    
  fprintf(file_ptr, "#  Pixel size:  %lf x %lf = %lf cm^2\n", 1.0/(double)(detector_data->inv_pixel_size_X), 1.0/(double)(detector_data->inv_pixel_size_Z), 1.0/(double)(detector_data->inv_pixel_size_X*detector_data->inv_pixel_size_Z));
  
  fprintf(file_ptr, "#  Number of pixels in X and Z:  %d  %d\n", detector_data->num_pixels.x, detector_data->num_pixels.y);
  fprintf(file_ptr, "#  (X rows given first, a blank line separates the different Z values)\n");
  fprintf(file_ptr, "# \n");
  fprintf(file_ptr, "#  [NON-SCATTERED] [COMPTON] [RAYLEIGH] [MULTIPLE-SCATTING]\n");
  fprintf(file_ptr, "# ==========================================================\n");

  const double SCALE = 1.0/SCALE_eV;    // conversion to eV using the inverse of the constant used in the "tally_image" kernel function (defined in the header file)
  const double NORM = SCALE * detector_data->inv_pixel_size_X * detector_data->inv_pixel_size_Z / ((double)total_histories);  // ==> [eV/cm^2 per history]
  double energy_noScatter, energy_compton, energy_rayleigh, energy_multiscatter;
  double energy_integral = 0.0;   // Integrate (add) the energy in the image pixels [meV]

  int pixels_per_image = (detector_data->num_pixels.x*detector_data->num_pixels.y), pixel=0;
  int i, j;
  for(j=0; j<detector_data->num_pixels.y; j++)
  {
    for(i=0; i<detector_data->num_pixels.x; i++)
    {
      energy_noScatter    = (double)(image[pixel]);
      energy_compton      = (double)(image[pixel +   pixels_per_image]);
      energy_rayleigh     = (double)(image[pixel + 2*pixels_per_image]);
      energy_multiscatter = (double)(image[pixel + 3*pixels_per_image]);

      // -- Write the results in an external file; the image corresponding to all particles not written: it has to be infered adding all images
      fprintf(file_ptr, "%.8lf %.8lf %.8lf %.8lf\n", NORM*energy_noScatter, NORM*energy_compton, NORM*energy_rayleigh, NORM*energy_multiscatter);

      energy_integral += energy_noScatter + energy_compton + energy_rayleigh + energy_multiscatter;
      pixel++;
    }
    fprintf(file_ptr, "\n");     // Separate rows with an empty line for visualization with gnuplot.
  }
  fprintf(file_ptr, "#   *** Simulation REPORT: ***\n");
  fprintf(file_ptr, "#       Fraction energy detected: %.3lf%%\n", 100.0*SCALE*(energy_integral/(double)(total_histories))/(double)(source_data->energy));
  fprintf(file_ptr, "#       Simulated x rays:    %lld\n", total_histories);
  fprintf(file_ptr, "#       Simulation time [s]: %.2f\n", time_elapsed);
  if (time_elapsed>0.000001)
    fprintf(file_ptr, "#       Speed [x-rays/sec]:  %.2f\n\n", ((double)total_histories)/time_elapsed);

  fclose(file_ptr);  // Close output file and flush stream

  printf("              Fraction of initial energy arriving at the detector (for a monoenergetic beam):  %.3lf%%\n\n", 100.0*SCALE*(energy_integral/(double)(total_histories))/(double)(source_data->energy));  // !!DeBuG!! Caution: Only valid for a monoenergetic beam!
  fflush(stdout);
  
  return 0;   // Report could return not 0 to continue the simulation...  !!DeBuG!!
}
///////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
//!  Sets the CT trajectory: store in memory the source and detector rotations
//!  that are needed to calculate the multiple projections.
//!  The first projection (0) was previously initialized in function "read_input".
//!  
//!
//!  ASSUMPTIONS: the CT scan plane must be perpendicular to the Z axis, ie,
//!               the initial direction of the particles must have w=0!
//!
///////////////////////////////////////////////////////////////////////////////
void set_CT_trajectory(int myID, int num_projections, double D_angle, double angularROI_0, double angularROI_1, struct source_struct* source_data, struct detector_struct* detector_data)
{
  MASTER_THREAD printf("\n    -- Setting the sources and detectors for the %d CT projections:\n", num_projections);
  double cos_rX, cos_rZ, sin_rX, sin_rZ, current_angle;

  // --Set center of rotation exactly half way between source and detector
  float3 center_rotation, detector_center;
  center_rotation.x =  source_data->position[0].x + source_data->direction[0].x * (0.5*detector_data->sdd);
  center_rotation.y =  source_data->position[0].y + source_data->direction[0].y * (0.5*detector_data->sdd);
  center_rotation.z =  source_data->position[0].z;    //  + source_data->direction.z * (0.5*detector_data->sdd);   // !!DeBuG!! w=0 all the time!!

  // --Angular span between projections:

  //  -Set initial angle for the source (180 degress less than the detector pointed by the direction vector; the zero angle is the X axis, increasing to +Y axis).
  current_angle = acos((double)source_data->direction[0].x);
  if (source_data->direction[0].y<0)
    current_angle = -current_angle;     // Correct for the fact that positive and negative angles have the same ACOS
  if (current_angle<0.0)
    current_angle += 2.0*PI;   // Make sure the angle is not negative, between [0,360) degrees.
  current_angle = current_angle - PI;   // Correct the fact that the source is opposite to the detector (180 degrees difference).
  if (current_angle<0.0)
    current_angle += 2.0*PI;   // Make sure the angle is not negative, between [0,360) degrees..

  MASTER_THREAD printf("         << Projection #0 >> initial_angle=%f , D_angle=%f\n", current_angle*RAD2DEG, D_angle*RAD2DEG); 
  MASTER_THREAD printf("                             Source direction=(%f,%f,%f), position=(%f,%f,%f)\n", source_data->direction[0].x,source_data->direction[0].y,source_data->direction[0].z, source_data->position[0].x,source_data->position[0].y,source_data->position[0].z);  // !!DeBuG!! Verbose

  int i;
  for (i=1; i<num_projections; i++)   // The first projection (i=0) was initialized in function "read_input".
  {
    // --Set the new source location and direction, for the current CT projection:
    current_angle += D_angle;
    if (current_angle>=(2.0*PI-0.0001))
      current_angle -= 2.0*PI;   // Make sure the angle is not above or equal to 360 degrees.

      // -- Check if this projection is inside the angular region of interest
      //   if ((current_angle < angularROI_0) || (current_angle > angularROI_1))
      //   {
      //     printf("            Skipping projection #%d: angle %f outside the angular region of interest.\n", i, current_angle*RAD2DEG);  // !!DeBuG!! Verbose
      //     continue;
      //   }

    source_data->position[i].x = center_rotation.x + (0.5*detector_data->sdd)*cos(current_angle);
    source_data->position[i].y = center_rotation.y + (0.5*detector_data->sdd)*sin(current_angle);
    source_data->position[i].z = source_data->position[0].z;   //  !!DeBuG!! The Z position must be constant (w=0)!!   !!DeBuG!!

    source_data->direction[i].x = center_rotation.x - source_data->position[i].x;
    source_data->direction[i].y = center_rotation.y - source_data->position[i].y;
    source_data->direction[i].z = 0.0f;    //  center_rotation.z - source_data->position.z;   !!DeBuG!! w=0 all the time!!   !!DeBuG!!

    double norm = 1.0/sqrt((double)source_data->direction[i].x*(double)source_data->direction[i].x + (double)source_data->direction[i].y*(double)source_data->direction[i].y /* + source_data->direction[i].z*source_data->direction[i].z*/);
    source_data->direction[i].x = (float)(((double)source_data->direction[i].x)*norm);
    source_data->direction[i].y = (float)(((double)source_data->direction[i].y)*norm);
      // source_data->direction[i].z = (float)(((double)source_data->direction[i].z)*norm);

    // --Set the new detector in front of the new source:
    detector_center.x = source_data->position[i].x + source_data->direction[i].x * detector_data->sdd;   // Set the center of the detector straight ahead of the focal spot.
    detector_center.y = source_data->position[i].y + source_data->direction[i].y * detector_data->sdd;
    detector_center.z = source_data->position[i].z;    //  + source_data->direction[i].z * detector_data->sdd;   !!DeBuG!! w=0 all the time!!

    double rotX, rotZ;

      //  detector_data->rotation_flag = 1;   // !!DeBuG!! Already set in read_input!

    // -- Rotate the detector center to +Y:
    //    Set the rotation that will bring particles from the detector plane to +Y=(0,+1,0) through a rotation around X and around Z (counter-clock):
    rotX = 0.0;   // !!DeBuG!! w=0 all the time!!  CORRECT CALCULATION:  acos(source_data->direction.z) - 0.5*PI;  // Rotate to +Y = (0,+1,0) --> rotX_0 =  -PI/2

    if ( (source_data->direction[i].x*source_data->direction[i].x + source_data->direction[i].y*source_data->direction[i].y) > 1.0e-8 )   // == u^2+v^2 > 0
      if (source_data->direction[i].y >= 0.0f)
        rotZ = 0.5*PI - acos(source_data->direction[i].x/sqrt(source_data->direction[i].x*source_data->direction[i].x + source_data->direction[i].y*source_data->direction[i].y));
      else
        rotZ = 0.5*PI - (-acos(source_data->direction[i].x/sqrt(source_data->direction[i].x*source_data->direction[i].x + source_data->direction[i].y*source_data->direction[i].y)));
    else
      rotZ = 0.0;   // Vector pointing to +Z, do not rotate around Z then.

    MASTER_THREAD printf("         << Projection #%d >> current_angle=%f, rotation around Z = %f\n", i, current_angle*RAD2DEG, rotZ*RAD2DEG);  // !!DeBuG!! Verbose
    MASTER_THREAD printf("                             Source direction=(%f,%f,%f), position=(%f,%f,%f)\n", source_data->direction[i].x,source_data->direction[i].y,source_data->direction[i].z, source_data->position[i].x,source_data->position[i].y,source_data->position[i].z);  // !!DeBuG!! Verbose

    cos_rX = cos(rotX);
    cos_rZ = cos(rotZ);
    sin_rX = sin(rotX);
    sin_rZ = sin(rotZ);
    detector_data->rot_inv[i][0] =  cos_rZ;    // Rotation matrix RxRz:
    detector_data->rot_inv[i][1] = -sin_rZ;
    detector_data->rot_inv[i][2] =  0.0f;
    detector_data->rot_inv[i][3] =  cos_rX*sin_rZ;
    detector_data->rot_inv[i][4] =  cos_rX*cos_rZ;
    detector_data->rot_inv[i][5] = -sin_rX;
    detector_data->rot_inv[i][6] =  sin_rX*sin_rZ;
    detector_data->rot_inv[i][7] =  sin_rX*cos_rZ;
    detector_data->rot_inv[i][8] =  cos_rX;


    detector_data->corner_min_rotated_to_Y[i].x = detector_center.x*detector_data->rot_inv[i][0] + detector_center.y*detector_data->rot_inv[i][1] + detector_center.z*detector_data->rot_inv[i][2];
    detector_data->corner_min_rotated_to_Y[i].y = detector_center.x*detector_data->rot_inv[i][3] + detector_center.y*detector_data->rot_inv[i][4] + detector_center.z*detector_data->rot_inv[i][5];
    detector_data->corner_min_rotated_to_Y[i].z = detector_center.x*detector_data->rot_inv[i][6] + detector_center.y*detector_data->rot_inv[i][7] + detector_center.z*detector_data->rot_inv[i][8];

    // -- Set the lower corner (minimum) coordinates at the normalized orientation: +Y. The detector has thickness 0.
    detector_data->corner_min_rotated_to_Y[i].x = detector_data->corner_min_rotated_to_Y[i].x - 0.5*detector_data->width_X;
    detector_data->corner_min_rotated_to_Y[i].y = detector_data->corner_min_rotated_to_Y[i].y;
    detector_data->corner_min_rotated_to_Y[i].z = detector_data->corner_min_rotated_to_Y[i].z - 0.5*detector_data->height_Z;

    // *** Init the fan beam source model:

      rotZ = -rotZ;   // The source rotation is the inverse of the detector.
      cos_rX = cos(rotX);
      cos_rZ = cos(rotZ);
      sin_rX = sin(rotX);
      sin_rZ = sin(rotZ);
      // --Rotation around X (alpha) and then around Z (phi): Rz*Rx (oposite of detector rotation)
      source_data->rot_fan[i][0] =  cos_rZ;
      source_data->rot_fan[i][1] = -cos_rX*sin_rZ;
      source_data->rot_fan[i][2] =  sin_rX*sin_rZ;
      source_data->rot_fan[i][3] =  sin_rZ;
      source_data->rot_fan[i][4] =  cos_rX*cos_rZ;
      source_data->rot_fan[i][5] = -sin_rX*cos_rZ;
      source_data->rot_fan[i][6] =  0.0f;
      source_data->rot_fan[i][7] =  sin_rX;
      source_data->rot_fan[i][8] =  cos_rX;

        // printf("\n    -- Source location and direction for the following CT projection:\n");   // !!DeBuG!! Verbose
        // printf("                 angle between projections = %lf degrees\n", D_angle*RAD2DEG);
        // printf("                             current angle = %lf degrees\n", current_angle*RAD2DEG);
        // printf("                   new focal spot position = (%f, %f, %f)\n", source_data->position[i].x, source_data->position[i].y, source_data->position[i].z);
        // printf("                      new source direction = (%f, %f, %f)\n", source_data->direction[i].x, source_data->direction[i].y, source_data->direction[i].z);
        // printf("                       new detector center = (%f, %f, %f)\n", detector_center.x, detector_center.y, detector_center.z);
        // printf("           new detector low corner (at +Y) = (%f, %f, %f)\n", detector_data->corner_min_rotated_to_Y[i].x, detector_data->corner_min_rotated_to_Y[i].y, detector_data->corner_min_rotated_to_Y[i].z);
        // printf("                        center of rotation = (%f, %f, %f)\n", center_rotation.x, center_rotation.y, center_rotation.z);
        // printf("         detector width (X) and height (Z) = %f , %f cm\n", detector_data->width_X, detector_data->height_Z);
        // printf("            rotations to +Y around Z and X = %f , %f degrees\n", rotZ*RAD2DEG, rotX*RAD2DEG);
  }
}
///////////////////////////////////////////////////////////////////////////////

