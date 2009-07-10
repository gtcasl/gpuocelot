################################################################################
#	\file Makefile.am
#	\author Gregory Diamos
#	\date Thursday July 9, 2009
# 	\brief Automake input file describing the programs and sources needed to
#			build Ocelot's Parboil regression tests
################################################################################

################################################################################
## Autoconf configuration
ACLOCAL_AMFLAGS = -I m4
OCELOT_LIBS = -lcudart -lOcelotExecutive -lOcelotTrace -lOcelotIr \
	-lOcelotParser -lhydrazine libsdk.la
################################################################################

################################################################################
## Programs and Libraries
bin_PROGRAMS = 
check_PROGRAMS = Cp MriFhd MriQ Pns Rpes Sad Tpacf
################################################################################

################################################################################
## Cp
Cp_CXXFLAGS = $(CUDA_CFLAGS) $(SDK_CFLAGS)
Cp_SOURCES = tests/alignedTypes/alignedTypes.cu.cpp
Cp_LDADD = $(OCELOT_LIBS)
Cp_LDFLAGS = -static
################################################################################

################################################################################
## Regression tests
sdkTest : regression/regression.log

regression/regression.log : check
	@echo
	@echo "Running UIUC Parboil Regression Test"
	@python hydrazine/python/RunRegression.py \
		-t regression/tests.txt \
		-l regression/regression.log -v

test : sdkTest

################################################################################


