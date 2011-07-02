## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = no-dependencies foreign

LDADD = ../libffs.la

INCLUDES = -I.. -I$(srcdir)/../../fm

if !NO_SOCKETS
bin_PROGRAMS = FFSdump
endif

all-local:
install-exec-local:

FFSdump_LDFLAGS = -static
