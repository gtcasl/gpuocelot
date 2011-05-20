= MCXLAB: MCX for MATLAB and GNU Octave =

Author: Qianqian Fang <fangq at nmr.mgh.harvard.edu>
License: GNU General Public License version 3 (GPLv3)
Version: this package is part of Monte Carlo eXtreme (MCX) 0.5.0

<toc>


== # Introduction ==

MCXLAB is the native MEX version of MCX for Matlab and GNU Octave. It compiles
the entire MCX code into a MEX function which can be called directly inside
Matlab or Octave. The input and output files in MCX are replaced by convenient
in-memory struct variables in MCXLAB, thus, making it much easier to use 
and interact. Matlab/Octave also provides convenient plotting and data
analysis functions. With MCXLAB, your analysis can be streamlined and speed-
up without involving disk files.

Because MCXLAB contains the exact computational codes for the GPU calculations
as in the MCX binaries, MCXLAB is expected to have identical performance when
running simulations. By default, we compile MCXLAB with the support of recording
detected photon partial path-lengths (i.e. the "make det" option). 


== # Installation ==

The system requirements for MCXLAB are the same as MCX: you have to make
sure that you have a CUDA-capable graphics card with properly configured 
CUDA driver (you can run the standard MCX binary first to test if your 
system is capable to run MCXLAB). Of course, you need to have either Matlab
or Octave installed.

MCXLAB needs libcudart.so.3 (for Unix-like systems) or cudart.dll 
(for Windows). For Linux/Mac, you need to set your LD_LIBRARY_PATH
environment variable to contain the path to this library file. 

To simplify the installation, we highly recommend you to link the libraries
to your /usr/lib directory. For 64bit Linux, you can use the following 
command:

  sudo ln -s /usr/local/cuda/lib64/libcudart.so.3 /usr/lib64

For windows, you simply copy the cudart.dll file to Windows\System32 folder.
This file is typically stored under the C:\CUDA\bin directory.

Once you set up the CUDA library path, you can then add the "mcxlab"
directory to your Matlab/Octave search path using the addpath command.
If you want to add this path permanently, please use the "pathtool" 
command, or edit your startup.m (~/.octaverc for Octave).

If everything works ok, typing "mcxlab" in Matlab/Octave will print the
help information. If you see any error, perticularly any missing libraries,
please make sure you have downloaded the matching version built for your
platform.


== # How to use MCXLAB in MATLAB/Octave ==

To learn the basic usage of MCXLAB, you can type

  help mcxlab

or simply

  mcxlab

and enter in Matlab/Octave to see the help information regarding how to use this 
function. The help information is listed below. You can find the input/output 
formats and examples. The input cfg structure has very similar field names as
the verbose command line options in MCX.

<pre>====================================================================
      MCXLAB - Monte Carlo eXtreme (MCX) for MATLAB/GNU Octave
--------------------------------------------------------------------
Copyright (c) 2010,2011 Qianqian Fang <fangq at nmr.mgh.harvard.edu>
		      URL: http://mcx.sf.net
====================================================================

 Format:
    [flux,detphoton]=mcxlab(cfg);

 Input:
    cfg: a struct, or struct array. Each element of cfg defines 
	 the parameters associated with a simulation. 

    It may contain the following fields:

     *cfg.nphoton:    the total number of photons to be simulated (integer)
     *cfg.vol:        a 3D array specifying the media index in the domain
     *cfg.prop:       an N by 4 array, each row specifies [mua, mus, g, n] in order.
		      the first row corresponds to medium type 0 which is 
		      typically [0 0 1 1]. The second row is type 1, and so on.
     *cfg.tstart:     starting time of the simulation (in seconds)
     *cfg.tstep:      time-gate width of the simulation (in seconds)
     *cfg.tend:       ending time of the simulation (in second)
     *cfg.srcpos:     a 1 by 3 vector, specifying the position of the source
     *cfg.srcdir:     a 1 by 3 vector, specifying the incident vector
      cfg.nblocksize: how many CUDA thread blocks to be used [64]
      cfg.nthread:    the total CUDA thread number [2048]
      cfg.maxgate:    the num of time-gates per simulation
      cfg.session:    a string for output file names (used when no return variables)
      cfg.seed:       seed for the random number generator (integer) [0]
      cfg.maxdetphoton:   maximum number of photons saved by the detectors [1000000]
      cfg.detpos:     an N by 4 array, each row specifying a detector: [x,y,z,radius]
      cfg.detradius:  radius of the detector (in grid unit) [1.0]
      cfg.sradius:    radius within which we use atomic operations (in grid) [0.0]
      cfg.respin:     repeat simulation for the given time (integer) [1]
      cfg.gpuid:      which GPU to use (run 'mcx -L' to list all GPUs) [1]
      cfg.isreflect:  [1]-consider refractive index mismatch, 0-matched index
      cfg.isrefint:   1-ref. index mismatch at inner boundaries, [0]-matched index
      cfg.isnormalized:[1]-normalize the output flux to unitary source, 0-no reflection
      cfg.issavedet:  1-to save detected photon partial path length, [0]-do not save
      cfg.issave2pt:  [1]-to save flux distribution, 0-do not save
      cfg.issrcfrom0: 1-first voxel is [0 0 0], [0]- first voxel is [1 1 1]
      cfg.isgpuinfo:  1-print GPU info, [0]-do not print
      cfg.autopilot:  1-automatically set threads and blocks, [0]-use nthread/nblocksize
      cfg.minenergy:  terminate photon when weight less than this level (float) [0.0]
      cfg.unitinmm:   defines the length unit for a grid edge length [1.0]

      fields with * are required; options in [] are the default values

 Output:
      flux: a struct array, with a length equals to that of cfg.
	    For each element of flux, flux(i).data is a 4D array with
	    dimensions specified by [size(vol) total-time-gates]. 
	    The content of the array is the normalized flux at 
	    each voxel of each time-gate.
      detphoton: a struct array, with a length equals to that of cfg.
	    For each element of detphoton, detphoton(i).data is a 2D array with
	    dimensions [size(cfg.prop,1)+1 saved-photon-num]. The first row
	    is the ID(>0) of the detector that captures the photon; the second
	    row is the weight of the photon when it is detected; the rest rows
	    are the partial path lengths (in grid unit) traveling in medium 1 up 
	    to the last. If you set cfg.unitinmm, you need to multiply the path-lengths
	    to convert them to mm unit.

      if detphoton is ignored, the detected photon will be saved in a .mch file 
      if cfg.issavedeet=1; if no output is given, the flux will be saved to a 
      .mc2 file if cfg.issave2pt=1 (which is true by default).

 Example:
      cfg.nphoton=1e7;
      cfg.vol=uint8(ones(60,60,60));
      cfg.srcpos=[30 30 1];
      cfg.srcdir=[0 0 1];
      cfg.gpuid=1;
      cfg.autopilot=1;
      cfg.prop=[0 0 1 1;0.005 1 0 1.37];
      cfg.tstart=0;
      cfg.tend=5e-9;
      cfg.tstep=5e-10;
      % calculate the flux distribution with the given config
      flux=mcxlab(cfg);

      cfgs(1)=cfg;
      cfgs(2)=cfg;
      cfgs(1).isreflect=0;
      cfgs(2).isreflect=1;
      cfgs(2).issavedet=1;
      cfgs(2).detpos=[30 20 1 1;30 40 1 1;20 30 1 1;40 30 1 1];
      % calculate the flux and partial path lengths for the two configurations
      [fluxs,detps]=mcxlab(cfgs);

      imagesc(squeeze(log(fluxs(1).data(:,30,:,1)))-squeeze(log(fluxs(2).data(:,30,:,1))));


 This function is part of Monte Carlo eXtreme (MCX) URL: http://mcx.sf.net

 License: GNU General Public License version 3, please read LICENSE.txt for details
</pre>

Because MCXLAB outputs the verbose simulation information, such as 
intermediate timing information, to the stderr descriptor, you will not 
be able to see this information if you launch Matlab in the GUI mode.
If you want to access to this information, please launch Matlab with the
following command:

    matlab -nojvm -nodesktop

The debug info will be printed in the console window. Alternatively, you 
can just start the matlab GUI from a console window by typing "matlab",
and the debug information will be printed in the console window instead.


== # Examples ==

We provided several examples to demonstrate the basic usage of MCXLAB,
as well as to perform validations of MCX algorithm using both simple 
homogeneous and heterogeneous domains. These examples are explained below:

==== demo_mcxlab_basic.m ====

In this example, we show the most basic usage of MCXLAB. This include
how to define the input configuration structure, launch MCX simulations
and interpret and plotting the resulting data.

==== demo_validation_homogeneous.m ====

In this example, we validate MCXLAB with a homogeneous medium in a 
cubic domain. This is exactly the example shown in Fig.5 of [Fang2009].

You can also use the alternative optical properties that has a high g
value to observe the similarity between the two scattering/g configurations.

==== demo_validation_heterogeneous.m ====

In this example, we validate the MCXLAB solver with a heterogeneous
domain and the analytical solution of the diffusion model. We also 
demonstrate how to use sub-pixel resolution to refine the representation
of heterogeneities. The domain is consisted of a 6x6x6 cm box with a 
2cm diameter sphere embedded at the center. 

This test is identical to that used for Fig. 3 in [Fang2010].

==== demo_sphere_cube_subpixel.m ====

In this example, we demonstrate how to use sub-pixel resolution 
to represent the problem domain. The domain is consisted of a 
6x6x6 cm box with a 2cm diameter sphere embedded at the center.

==== demo_4layer_head.m ====

In this example, we simulate a 4-layer brain model using MCXLAB.
We will investigate the differences between the solutions with and 
witout boundary reflections (both external and internal) and show
you how to display and analyze the resulting data.


== # How to compile MCXLAB ==

To compile MCXLAB for Matlab, you need to cd mcx/src directory, and type 

 make mex

from a shell window. You need to make sure your Matlab is installed and 
the command <tt>mex</tt> is included in your PATH environment variable. Similarly, 
to compile MCXLAB for Octave, you type

 make oct

The command <tt>mkoctfile</tt> must be accessible from your command line
and it is provided in a package named "octave3.x-headers" in Ubuntu (3.x
can be 3.2 or 3.4 etc).


== # Screenshots ==

Screenshot for using MCXLAB in Matlab:
  http://mcx.sourceforge.net/upload/matlab_mcxlab.png

Screenshot for using MCXLAB in GNU Octave:
  http://mcx.sourceforge.net/upload/octave_mcxlab.png


== # Reference ==

 [Fang2009] Qianqian Fang and David A. Boas, "Monte Carlo simulation 
  of photon migration in 3D turbid media accelerated by graphics processing 
  units," Opt. Express 17, 20178-20190 (2009)

 [Fang2010] Fang Q, "Mesh-based Monte Carlo method using fast ray-tracing
   in Plucker coordinates," Biomed. Opt. Express 1, 165-175 (2010) 

