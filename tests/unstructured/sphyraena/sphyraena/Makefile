CC = /usr/bin/gcc
RCC = /usr/bin/icc #/opt/intel/Compiler/11.0/081/bin/ia32/icc
CUDA = /usr/local/cuda
NVCC = $(CUDA)/bin/nvcc #/usr/local/cuda/bin/nvcc
FLAGS = -Wall -Wextra -pedantic -std=c99
SQLITE_DIR = ../sqlite
SQLITE_VER = 3.6.22
SQLITESRC_DIR = ../sqlite-$(SQLITE_VER)/src
CUDA_INCLUDE = $(CUDA)/include
CUDA_LIBRARY = $(CUDA)/lib
DB = ../db/hundredthousand.db

CUSTOM_FLAGS = -DSPHY_DEBUG -DRUNTEST

DEBUG_FLAGS = $(FLAGS) $(CUSTOM_FLAGS) -g3 -I$(SQLITE_DIR) -I$(SQLITESRC_DIR) -I$(CUDA_INCLUDE)
OPT_FLAGS = -O2 -xHost -ipo
RELEASE_FLAGS = $(OPT_FLAGS) $(patsubst -DSPHY_DEBUG, ,$(CUSTOM_FLAGS)) -I$(SQLITE_DIR) -I$(SQLITESRC_DIR) -I$(CUDA_INCLUDE)
LD = -lm -L$(CUDA_LIBRARY) -lcudart

FILES = cleanup.c debug.c driver.c init.c prepare_data.c select.c test.c transfer_data.c transfer_results.c
DFILES = $(patsubst %.c,debug/%.o,$(FILES))
RFILES = $(patsubst %.c,release/%.o,$(FILES))


all: debug run

debug: debug/sphyraena

release: release/sphyraena

debug/sqlite3.o: $(SQLITE_DIR)/sqlite3.c
	$(CC) $(SQLITE_DIR)/sqlite3.c -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_DEPRECATED -w -g -c -o debug/sqlite3.o

debug/opcodes.o: $(SQLITE_DIR)/opcodes.c
	$(CC) $(SQLITE_DIR)/opcodes.c -g -c -o debug/opcodes.o

$(DFILES): debug/%.o: %.c *.h
	$(CC) $(DEBUG_FLAGS) -c $< -o $@

debug/vm.o: vm.cu
	$(NVCC) $(CUSTOM_FLAGS) -I$(SQLITE_DIR) -I$(SQLITESRC_DIR) --ptxas-options="-v" -arch=sm_13 -g -c vm.cu -o debug/vm.o

debug/sphyraena: $(DFILES) debug/sqlite3.o debug/vm.o debug/opcodes.o
	$(CC) $(DEBUG_FLAGS) $(LD) $(DFILES) debug/opcodes.o debug/sqlite3.o debug/vm.o -o debug/sphyraena
	

ptx:
	$(NVCC) $(CUSTOM_FLAGS) -I$(SQLITE_DIR) -I$(SQLITESRC_DIR) --ptxas-options="-v" -arch=sm_13 -g -ptx vm.cu



release/sqlite3.o: $(SQLITE_DIR)/sqlite3.c
	$(RCC) $(SQLITE_DIR)/sqlite3.c -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_DEPRECATED -DSQLITE_TEMP_STORE=3 $(OPT_FLAGS) -c -o release/sqlite3.o

$(RFILES): release/%.o: %.c *.h
	$(RCC) $(RELEASE_FLAGS) -c $< -o $@

release/vm.o: vm.cu
	$(NVCC) $(CUSTOM_FLAGS) -I$(SQLITE_DIR) -I$(SQLITESRC_DIR) --ptxas-options="-v" -arch=sm_13 -c vm.cu -o release/vm.o

release/sphyraena: $(RFILES) release/sqlite3.o release/vm.o
	$(RCC) $(RELEASE_FLAGS) $(RFILES) release/sqlite3.o -ipo-c -o release/ipo_out.o
	$(RCC) release/vm.o release/ipo_out.o -lcudart $(RELEASE_FLAGS) -L$(CUDA_LIBRARY) -o release/sphyraena


clean:
	rm -f debug/* release/*

run: debug/sphyraena
	export LD_LIBRARY_PATH=$(CUDA_LIBRARY) && debug/sphyraena -p -m -d $(DB)

rrun: release/sphyraena
	export LD_LIBRARY_PATH=$(CUDA_LIBRARY) && release/sphyraena -p -m -d $(DB)

profile:
	export LD_LIBRARY_PATH=$(CUDA_LIBRARY) && $(CUDA)/cudaprof/bin/cudaprof &



.PHONY: all debug release clean run rrun profile

