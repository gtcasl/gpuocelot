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
OCELOT_LIBS = $(OCELOT_LDFLAGS) libparboil.la -locelotTrace
CUDA_CFLAGS = -I $(srcdir)/parboil
################################################################################

################################################################################
## Programs and Libraries
bin_PROGRAMS = 
check_PROGRAMS = cp mri-fhd mri-q pns rpes sad tpacf
lib_LTLIBRARIES = libparboil.la
################################################################################

################################################################################
## Parboil Library
libparboil_la_CFLAGS = $(CUDA_CFLAGS)
libparboil_la_SOURCES = parboil/parboil.c
################################################################################

################################################################################
## cp
cp_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
cp_SOURCES = tests/cp/main.cu.cpp \
	tests/cp/cuenergy_pre8_coalesce.cu.cpp
cp_LDADD = $(OCELOT_LIBS)
cp_LDFLAGS = -static
################################################################################

################################################################################
## mri-fhd
mri_fhd_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
mri_fhd_SOURCES = tests/mri-fhd/main.cu.cpp \
	tests/mri-fhd/file.cc
mri_fhd_LDADD = $(OCELOT_LIBS)
mri_fhd_LDFLAGS = -static
################################################################################

################################################################################
## mri-q
mri_q_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
mri_q_SOURCES = tests/mri-q/main.cu.cpp \
	tests/mri-q/file.cc
mri_q_LDADD = $(OCELOT_LIBS)
mri_q_LDFLAGS = -static
################################################################################

################################################################################
## pns
pns_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
pns_SOURCES = tests/pns/main.cu.cpp \
	tests/pns/rand_gen.cu.cpp
pns_LDADD = $(OCELOT_LIBS)
pns_LDFLAGS = -static
################################################################################

################################################################################
## rpes
rpes_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
rpes_SOURCES = tests/rpes/main.cu.cpp
rpes_LDADD = $(OCELOT_LIBS)
rpes_LDFLAGS = -static
################################################################################

################################################################################
## sad
sad_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
sad_SOURCES = tests/sad/main.cu.cpp \
	tests/sad/largerBlocks.cu.cpp \
	tests/sad/sad4.cu.cpp \
	tests/sad/file.c \
	tests/sad/image.c
sad_LDADD = $(OCELOT_LIBS)
sad_LDFLAGS = -static
################################################################################

################################################################################
## tpacf
tpacf_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
tpacf_SOURCES = tests/tpacf/main.cu.cpp \
	tests/tpacf/args.cc \
	tests/tpacf/model_io.cc
tpacf_LDADD = $(OCELOT_LIBS)
tpacf_LDFLAGS = -static
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
	@echo "Running Parboil Regression test"
	@python hydrazine/python/RunRegression.py \
		-t regression/tests.txt \
		-l regression/regression.log -v

test : regression/regression.log

################################################################################

