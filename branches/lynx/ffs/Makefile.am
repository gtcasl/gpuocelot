## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = no-dependencies foreign
ACLOCAL_AMFLAGS = -I config

INSTALL_HEADER = ${srcdir}/config/install-sh -m 644

SUBDIRS= fm cod ffs .

all:
	rm -f fm.h cod.h ffs.h
	$(LN_S) $(srcdir)/fm/fm.h
	$(LN_S) $(srcdir)/cod/cod.h
	$(LN_S) ffs/ffs.h

noinst_LTLIBRARIES = libfm.la libcod.la libffs.la

libfm_la_SOURCES = empty.c
libfm_la_LIBADD = fm/libfm.la
libcod_la_SOURCES = empty.c
libcod_la_LIBADD = cod/libcod.la
libffs_la_SOURCES = empty.c
libffs_la_LIBADD = ffs/libffs.la
