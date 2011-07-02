## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = no-dependencies foreign
ACLOCAL_AMFLAGS = -I config

lib_LTLIBRARIES = libcercs_env.la

noinst_HEADERS = 

EXTRA_libcercs_env_la_SOURCES = timing_hrtime.c timing_gettimeofday.c timing_linux_x86.c

libcercs_env_la_SOURCES = env.c trace.c bitarray.c
libcercs_env_la_LIBADD =  $(TIMING_O)
libcercs_env_la_LDFLAGS = -no-undefined
libcercs_env_la_DEPENDENCIES = $(TIMING_O)

INSTALL_HEADER = ${srcdir}/config/install-sh -m 644

include_HEADERS = cercs_env.h


bin_PROGRAMS = test_timing

LIBS = @LIBS@

test_timing_SOURCES = test_timing.c
test_timing_LDADD = libcercs_env.la
