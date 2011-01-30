################################################################################
#	\file Makefile.am
#	\author Gregory Diamos
#	\date Monday August 10, 2009
# 	\brief Automake input file describing the programs and sources needed to
#			build Ocelot's Parboil regression tests
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
OCELOT_LIBS = $(OCELOT_LDFLAGS)
################################################################################

################################################################################
## Programs and Libraries
bin_PROGRAMS =
check_PROGRAMS = leukocyte hwt mummergpu lu srad hotspot backprop needle
lib_LTLIBRARIES =
################################################################################

################################################################################
## leukocyte
leukocyte_CXXFLAGS = 
leukocyte_CFLAGS = 
leukocyte_SOURCES = tests/leukocyte/detect_main.c \
	tests/leukocyte/avilib.c \
	tests/leukocyte/find_ellipse.c \
	tests/leukocyte/find_ellipse_kernel.cu.cpp \
	tests/leukocyte/track_ellipse.c \
	tests/leukocyte/track_ellipse_kernel.cu.cpp \
	tests/leukocyte/misc_math.c \
	tests/leukocyte/copy.c \
	tests/leukocyte/err.c \
	tests/leukocyte/matrixio.c \
	tests/leukocyte/memory.c \
	tests/leukocyte/vecop.c \
	tests/leukocyte/matop.c \
	tests/leukocyte/pxop.c \
	tests/leukocyte/submat.c \
	tests/leukocyte/init.c \
	tests/leukocyte/otherio.c \
	tests/leukocyte/machine.c \
	tests/leukocyte/matlab.c \
	tests/leukocyte/ivecop.c \
	tests/leukocyte/version.c \
	tests/leukocyte/meminfo.c \
	tests/leukocyte/memstat.c \
	tests/leukocyte/lufactor.c \
	tests/leukocyte/bkpfacto.c \
	tests/leukocyte/chfactor.c \
	tests/leukocyte/qrfactor.c \
	tests/leukocyte/solve.c \
	tests/leukocyte/hsehldr.c \
	tests/leukocyte/givens.c \
	tests/leukocyte/update.c \
	tests/leukocyte/norm.c \
	tests/leukocyte/hessen.c \
	tests/leukocyte/symmeig.c \
	tests/leukocyte/schur.c \
	tests/leukocyte/svd.c \
	tests/leukocyte/fft.c \
	tests/leukocyte/mfunc.c \
	tests/leukocyte/bdfactor.c \
	tests/leukocyte/sparse.c \
	tests/leukocyte/sprow.c \
	tests/leukocyte/sparseio.c \
	tests/leukocyte/spchfctr.c \
	tests/leukocyte/splufctr.c \
	tests/leukocyte/spbkp.c \
	tests/leukocyte/spswap.c \
	tests/leukocyte/iter0.c \
	tests/leukocyte/itersym.c \
	tests/leukocyte/iternsym.c \
	tests/leukocyte/zmachine.c \
	tests/leukocyte/zcopy.c \
	tests/leukocyte/zmatio.c \
	tests/leukocyte/zmemory.c \
	tests/leukocyte/zvecop.c \
	tests/leukocyte/zmatop.c \
	tests/leukocyte/znorm.c \
	tests/leukocyte/zfunc.c \
	tests/leukocyte/zlufctr.c \
	tests/leukocyte/zsolve.c \
	tests/leukocyte/zmatlab.c \
	tests/leukocyte/zhsehldr.c \
	tests/leukocyte/zqrfctr.c \
	tests/leukocyte/zgivens.c \
	tests/leukocyte/zhessen.c \
	tests/leukocyte/zschur.c

leukocyte_LDADD = $(OCELOT_LIBS)
leukocyte_LDFLAGS = -static
################################################################################

################################################################################
# heart wall tracking
hwt_CXXFLAGS =
hwt_CFLAGS =
hwt_SOURCES = tests/hwt/avilib.c \
	tests/hwt/avimod.c \
	tests/hwt/main.cu.cpp
hwt_LDADD = $(OCELOT_LIBS)
hwt_LDFLAGS = -static
################################################################################

################################################################################
# mummergpu
mummergpu_CXXFLAGS = -fopenmp
mummergpu_CFLAGS = 
mummergpu_SOURCES = tests/mummergpu/PoolMalloc.cpp \
	tests/mummergpu/mummergpu.cu.cpp \
	tests/mummergpu/mummergpu_gold.cpp \
	tests/mummergpu/mummergpu_main.cpp \
	tests/mummergpu/smith-waterman.cpp \
	tests/mummergpu/suffix-tree.cpp
mummergpu_LDADD = $(OCELOT_LIBS)
mummergpu_LDFLAGS = -static
################################################################################

################################################################################
# lu
lu_CXXFLAGS = 
lu_CFLAGS = 
lu_SOURCES = tests/luDecomposition/common.c \
	tests/luDecomposition/lud.cu.cpp \
	tests/luDecomposition/lud_kernel.cu.cpp
lu_LDADD = $(OCELOT_LIBS)
lu_LDFLAGS = -static
################################################################################

################################################################################
# srad
srad_CXXFLAGS = 
srad_CFLAGS = 
srad_SOURCES = tests/srad/srad.cu.cpp
srad_LDADD = $(OCELOT_LIBS)
srad_LDFLAGS = -static
################################################################################

################################################################################
# hotspot 
hotspot_CXXFLAGS = 
hotspot_CFLAGS = 
hotspot_SOURCES = tests/hotspot/hotspot.cu.cpp
hotspot_LDADD = $(OCELOT_LIBS)
hotspot_LDFLAGS = -static
################################################################################

################################################################################
# backprop
backprop_CXXFLAGS = -fopenmp
backprop_CFLAGS = 
backprop_SOURCES = tests/backPropagation/backprop.c \
	tests/backPropagation/facetrain.c \
	tests/backPropagation/imagenet.c \
	tests/backPropagation/backprop_cuda.cu.cpp
backprop_LDADD = $(OCELOT_LIBS)
backprop_LDFLAGS = -static
################################################################################

################################################################################
# needle
needle_CXXFLAGS = 
needle_CFLAGS = 
needle_SOURCES = tests/needlemanWunsch/needle.cu.cpp
needle_LDADD = $(OCELOT_LIBS)
needle_LDFLAGS = -static
################################################################################

################################################################################
## Headers
nobase_include_HEADERS = 

################################################################################

################################################################################
## Data
EXTRA_DIST = 

################################################################################

################################################################################
## Regression tests
regression/regression.log : check
	@echo
	@echo "Running Rodinia Regression test"
	@python hydrazine/python/RunRegression.py \
		-t regression/tests.txt \
		-l regression/regression.log -v

test : regression/regression.log

################################################################################

