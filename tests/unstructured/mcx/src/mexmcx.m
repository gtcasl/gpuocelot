system('make clean mex');
mex -I/usr/local/cuda/include -L/usr/local/cuda/lib64 -lcudart mcxlab.cpp mcx_utils.o tictoc.o mcx_core.o -cxx -outdir ../utils
