= README for the bubble-mode example =

Although we have shown that for biological tissues, 
the error due to non-atomic memory write is negligible,
for cases where the accuracy is critically important, 
we also proposed an approach to further reduce the
impact due to race conditions in the non-atomic version
of MCX (see paragraph 4 in Section 4 of Fang2009). 
Here we call this approach the "bubble-mode".

In the "bubble mode", user specifies a radius using 
the -R flag. When a photon is within this specified 
radius from the source, we accumulate the absorbed energy 
to a register variable rather than writing to the global
memory. This example is to show to use this flag and
what kind of improvement you are expecting.

To run this example, you need to first compile 
the mcx binary, and then run the run_bubble.sh script 
to produce simulation results for bubble size at 0mm,
3mm and 5mm, respectively. Then you start GNU Octave 
or Matlab, and run the mcxskiptest.m script and 
compare the solutions. You need to be aware that by 
setting the bubble size above 3mm, you effectively
avoid over 99% of the race conditions.

Because the atomic/non-atomic difference is so tiny,
you have to zoom in with a great magnification to 
see the differences. Generally, the bigger bubble will
give you a slightly smaller solution, because it
makes the denominator slightly bigger in Eq. (1) 
of Fang2009 by avoiding the race conditions.



[Fang2009]   Qianqian Fang and David A. Boas, "Monte Carlo 
   Simulation of Photon Migration in 3D Turbid Media Accelerated 
   by Graphics Processing Units," Opt. Express, 
   vol. 17, issue 22, pp. 20178-20190 (2009)
