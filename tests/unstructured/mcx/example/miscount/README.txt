= README for the non-atomic race condition test =

In this example, we qualitatively assess the severity of
the race condition in the non-atomic version of MCX.

To do this test, we use a register variable in each thread 
to accumulate the number of events that a thread is trying
to write to the global memory. The sum of these values
indicates the total "true" write events. On the other hand,
we accumulate 1 into the global memory when a write event
happens. Thus, from the output global memory space, we
can sum these counts to get the "actually recorded" write 
events. The differences between these two sums are due to
the write conflict in the race-conditions.

The detailed report can be found in the paper Fang2009 
Section 3.2 and Fig. 4.

To run this example, you need to compile the mcx binary 
first with "make racing", and then run the 
"runmiscount.sh > miscnt.log" command. This 
will test the missing event ratios for a 
range of scattering coefficients at different thread 
numbers (note, the absorption coefficient will not have 
influences to the race condition). If you redirect the 
output of runmiscount.sh to a text file, then you can use
script genreport.sh to get a tabulated report from the 
log file.


[Fang2009]   Qianqian Fang and David A. Boas, "Monte Carlo 
   Simulation of Photon Migration in 3D Turbid Media Accelerated 
   by Graphics Processing Units," Opt. Express, 
   vol. 17, issue 22, pp. 20178-20190 (2009)
