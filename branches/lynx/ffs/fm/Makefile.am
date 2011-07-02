## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = no-dependencies foreign
ACLOCAL_AMFLAGS = -I ../config

SUBDIRS = . progs tests

noinst_HEADERS = assert.h config.h fm_internal.h

if NO_SOCKETS
libfm_la_SOURCES = fm_formats.c fm_dump.c lookup3.c string_conversion.c fm_get.c xml.c null_io.c
else
libfm_la_SOURCES = fm_formats.c fm_dump.c lookup3.c string_conversion.c fm_get.c xml.c server_acts.c server.c unix_io.c
endif


LDADD = libfm.la

lib_LTLIBRARIES = libfm.la
include_HEADERS = fm.h

