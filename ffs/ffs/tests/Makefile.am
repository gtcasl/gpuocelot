## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = no-dependencies foreign

noinst_HEADERS = test_funcs.h

INCLUDES = -I$(srcdir)/../../fm -I$(srcdir)/../../cod -I..

LDADD = ../libffs.la

TESTS = context_test context_test2 fortran_test marshal_test marshal_test2

bin_PROGRAMS = 
#noinst_PROGRAMS = io_read io_read2 io_dyn_read io_test io_write context_test fortran_test xml_test compat_test io_default_test io_def_write 
noinst_PROGRAMS = context_test context_test2 ffs_write io_dyn_read fortran_test ffs_file_test ffs_index_test append marshal_test marshal_test2

MOSTLYCLEANFILES = dcg/*
all-local:
install-exec-local:

context_test_SOURCES = context_test.c test_funcs.c
context_test2_SOURCES = context_test2.c test_funcs.c
fortran_test_SOURCES = fortran_test.c test_funcs.c
xml_test_SOURCES= xml_test.c test_funcs.c
compat_test_SOURCES= compat_test.c test_funcs.c
ffs_file_test_SOURCES= ffs_file_test.c test_funcs.c
ffs_index_test_SOURCES= ffs_index_test.c test_funcs.c
io_default_test_SOURCES= io_default_test.c test_funcs.c
ffs_write_SOURCES= ffs_write.c test_funcs.c
io_dyn_read_SOURCES= io_dyn_read.c test_funcs.c
marshal_test_SOURCES= marshal_test.c
marshal_test2_SOURCES= marshal_test2.c

write_output: context_test
	rm -f ../output_dir/context_test_output.@ARCH@.bin
	./context_test -w ../output_dir/context_test_output.@ARCH@.bin
	./ffs_write
	rm -f ../output_dir/file_output.@ARCH@.bin
	mv test_output ../output_dir/file_output.@ARCH@.bin

check-local: context_check file_check index_check

index_check: ffs_index_test ffs_write
	./ffs_write -i
	./ffs_index_test test_output
	rm -f ./test_output

context_check:  context_test @OUTPUT_TARGET@
	@failed=0;\
	for i in ../output_dir/context_test_output*.bin; do \
	    if ./context_test -r $$i; then\
	    	echo "PASS: $$i";\
	    else\
	    	echo "FAILED: context_test -r $$i";\
	        failed=`expr $$failed + 1`; \
	    fi;\
	done;\
	if test "$$failed" -eq 0; then \
	    echo "All context tests passed"; \
	else\
	    echo "$$failed context tests failed";\
	fi;\
	test "$$failed" -eq 0


file_check:  ffs_file_test @OUTPUT_TARGET@
	@failed=0;\
	for i in ../output_dir/file*.bin; do \
	    if ./ffs_file_test $$i; then\
	    	echo "PASS: $$i";\
	    else\
	    	echo "FAILED: ffs_file_test $$i";\
	        failed=`expr $$failed + 1`; \
	    fi;\
	done;\
	if test "$$failed" -eq 0; then \
	    echo "All file tests passed"; \
	else\
	    echo "$$failed file tests failed";\
	fi;\
	test "$$failed" -eq 0


