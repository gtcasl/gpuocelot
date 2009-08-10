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
OCELOT_LIBS = -lcudart -lOcelotExecutive -lOcelotTrace -lOcelotIr \
	-lOcelotParser -lhydrazine libparboil.la
CUDA_CFLAGS = -I parboil
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


