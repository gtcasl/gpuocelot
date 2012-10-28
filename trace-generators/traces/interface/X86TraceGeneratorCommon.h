//Nagesh

#ifndef INDI_H
#define INDI_H

#ifdef _MSC_VER
    typedef unsigned __int8 uint8_t;
    typedef unsigned __int32 uint32_t;
#else
    #include <inttypes.h>
#endif
#include <stdio.h>
/* added on jan-28 by nagesh */
#include <zlib.h>
#include <iostream>
/* added on jan-28 by nagesh */
//#include "xed-category-enum.h"

#define MAX_SRC_NUM 9
#define MAX_DST_NUM 6
/* added on jan-28 by nagesh */

#define USE_MAP 0

#define MAX_THREADS 1024

void init_reg_compress(void) ;

struct Model_info
{
  unsigned long Bitset;    // hash key
  unsigned long Threads;
  unsigned long Blocks;
  unsigned long INT;
  unsigned long FP;
  unsigned long Convert_move;
  unsigned long Logic_shift;
  unsigned long Comparison;
  unsigned long Synch;
  unsigned long Control;
  unsigned long Misc;
  unsigned long Total;
  unsigned long Memory_global;
  unsigned long Memory_texture;
  unsigned long Memory_shared;
  unsigned long Memory_local;
  unsigned long Memory_const;
  unsigned long Memory_param;
  unsigned long CoalMem;
  unsigned long UncoalMem;

  unsigned long FP_DIV;
  unsigned long INT_MUL;
  unsigned long INT_DIV; 
  unsigned long INT_MODULO;
};




struct Thread_info
{
  uint32_t thread_id;
  uint64_t inst_count;
};


/* decoded inst format */
struct Inst_info{
  uint8_t num_read_regs;      // 3-bits
  uint8_t num_dest_regs;      // 3-bits

  uint8_t src[MAX_SRC_NUM]; // 6-bits * 4
  uint8_t dst[MAX_DST_NUM]; // 6-bits * 4

  uint8_t cf_type;  // 4 bits

  bool has_immediate;  // 1bits

  uint8_t opcode; // 6 bits

  bool  has_st;  // 1 bit

  bool is_fp;    // 1bit
  bool write_flg;   // 1bit
  uint8_t num_ld;  // 2bit
  uint8_t size; // 5 bit

  // **** dynamic ****

  uint32_t ld_vaddr1; // 4 bytes
  uint32_t ld_vaddr2; // 4 bytes
  uint32_t st_vaddr;   // 4 bytes

  uint32_t instruction_addr; // 4 bytes

  uint32_t branch_target; // not the dynamic info. static info  // 4 bytes

  uint8_t mem_read_size; // 8 bit
  uint8_t mem_write_size;  // 8 bit
  bool rep_dir;  // 1 bit
  bool actually_taken; // 1 ibt


};


/* added on jan-28 by nagesh */
#define BUF_SIZE (10 * sizeof(struct Inst_info))
struct Trace_info
{
//  typedef void * gzFile;
  gzFile trace_stream;
  char trace_buf[BUF_SIZE];
  int bytes_accumulated;
  Inst_info inst_info;
  uint64_t inst_count;
  uint64_t ptx_inst_count;
  uint32_t vaddr1;
  uint32_t vaddr2;
  uint32_t st_vaddr;
  uint32_t target;
  uint32_t actually_taken;
  uint32_t mem_read_size;
  uint32_t mem_write_size;
  uint32_t eflags;
  std::ofstream* debug_stream;
  char trace_name[400];
};



typedef void VOID;
VOID write_inst_to_file(std::ofstream* file, Inst_info *t_info);
/* added on jan-28 by nagesh */

/*
   enum TR_OPCODE_enum {
   XED_CATEGORY_LAST,
   TR_MUL = XED_CATEGORY_LAST,
   TR_DIV,
   TR_FMUL,
   TR_FDIV,
   TR_NOP,
   PREFETCH_NTA,
   PREFETCH_T0,
   PREFETCH_T1,
   PREFETCH_T2
   }TR_OPCODE;
   */

//enum CF_TYPE_enum CF_TYPE;


extern std::string tr_cf_names[15];
extern std::string tr_opcode_names[62];

#endif //INDI_H
