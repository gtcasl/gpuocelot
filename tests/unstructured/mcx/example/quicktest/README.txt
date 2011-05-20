= README for the quicktest example =

As the name indicates, this example runs a short simulation
for the purpose of testing the command line options build
with MCX. 

To run this example, you need to first compile mcx binary.
Then you can choose to run the following shell scripts:

listgpu.sh
    A script to call mcx to print the GPU information 
    only. Run this script and find out how many GPUs you 
    have in your graphics card and the related parameters 
    (memory, cores etc) 

run_qtest.sh
    This will run MCX for a simple homogeneous medium as 
    the example used in the Fang2009 paper. It will launch 
    only 0.3 million photons and take roughly half a second. 

run_qtest_silent.sh
    This script does the same thing as run_qtest.sh, 
    except it let mcx to print messages to a log file 
    rather than printing on the screen (so called silent mode) 


[Fang2009]   Qianqian Fang and David A. Boas, "Monte Carlo 
   Simulation of Photon Migration in 3D Turbid Media Accelerated 
   by Graphics Processing Units," Opt. Express, 
   vol. 17, issue 22, pp. 20178-20190 (2009)
