= README for the validation example =

In this example, we validate MCX code with a homogeneous 
medium defined by a 60x60x60 uniform grid. The medium has
mua=0.005/mm, musp=1/mm, anisotropy g=0.01 and refraction
index n=1 (without reflection) or n=1.37 (with reflection).

The detailed report can be found in the paper Fang2009 
Section 3.2 and Fig. 5.

To run this example, you need to first compile the mcx
binary, and then run the run_validation.sh and 
run_validation_b.sh scripts to run simulations for
n=1 and n=1.37, respectively. Then you need to start
GNU Octave or Matlab, and run plotsimudata.m script
to reproduce Fig. 5 in Fang2009.


[Fang2009]   Qianqian Fang and David A. Boas, "Monte Carlo 
   Simulation of Photon Migration in 3D Turbid Media Accelerated 
   by Graphics Processing Units," Opt. Express, 
   vol. 17, issue 22, pp. 20178-20190 (2009)
