## @file Makefile
## @author Naila Farooqui, naila@cc.gatech.edu
## @date 2011-11-22
## @brief Makefile to build the instrumentation library

PREFIX=/usr/local
SONAME=libinstrumentation.so

CC=g++
CCFLAGS=-O2 -Wall -Werror -std=c++0x -D_DEBUG -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS -fPIC -I. -I/usr/local/include
LDFLAGS=-lrt -shared -Wl,-soname,$(SONAME)

all:	lib/$(SONAME)

.PHONY: all

lib/$(SONAME):	instrumentation/implementation/InstrumentationConfiguration.o instrumentation/implementation/ClockCycleCountInstrumentor.o instrumentation/implementation/BasicBlockInstrumentor.o instrumentation/implementation/WarpReductionInstrumentor.o 
	mkdir -p lib
	$(CC) $(LDFLAGS) -o $@ $^

instrumentation/implementation/InstrumentationConfiguration.o:	instrumentation/implementation/InstrumentationConfiguration.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

instrumentation/implementation/ClockCycleCountInstrumentor.o:	instrumentation/implementation/ClockCycleCountInstrumentor.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

instrumentation/implementation/BasicBlockInstrumentor.o:	instrumentation/implementation/BasicBlockInstrumentor.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<
	
instrumentation/implementation/WarpReductionInstrumentor.o:	instrumentation/implementation/WarpReductionInstrumentor.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -rf lib/ instrumentation/implementation/*.o

.PHONY: clean

install: all
	mkdir -p $(PREFIX)/include/instrumentation
	mkdir -p $(PREFIX)/include/instrumentation/interface
	install -m 0444 instrumentation/interface/InstrumentationConfiguration.h $(PREFIX)/include/instrumentation/interface
	install -m 0444 instrumentation/interface/ClockCycleCountInstrumentor.h $(PREFIX)/include/instrumentation/interface
	install -m 0444 instrumentation/interface/BasicBlockInstrumentor.h $(PREFIX)/include/instrumentation/interface
	install -m 0444 instrumentation/interface/WarpReductionInstrumentor.h $(PREFIX)/include/instrumentation/interface
	install -m 0555 lib/$(SONAME) $(PREFIX)/lib
	ldconfig

.PHONY: install

uninstall:
	rm -f $(PREFIX)/include/instrumentation
	rm -f $(PREFIX)/lib/$(SONAME)
	ldconfig
	
	
