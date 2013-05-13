/*!
 * \author Nagesh B. Lakshminarayana and Jaekyu Lee
 * \date February 4, 2011
 * \brief ptx trace generator for MacSim simulator
 */


// c++ libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <zlib.h>
#include <string.h>
#include <errno.h>
#include <map>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <cfloat>
#include <iostream>

// boost libraries
#include <boost/filesystem.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/dynamic_bitset.hpp> 

// Ocelot libraries
#include <traces/interface/X86TraceGenerator.h>
#include <traces/interface/X86TraceGeneratorCommon.h>
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/api/interface/ocelot.h>
#include <ocelot/executive/interface/ExecutableKernel.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/ir/interface/Module.h>
#include <hydrazine/interface/Exception.h>
#include <hydrazine/interface/debug.h>



#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1


#define GPU_REGISTER 49
#define GPU_SHARED 60



#define ST_INST(opcode) \
   (opcode == ir::PTXInstruction::St || \
    opcode == ir::PTXInstruction::Atom || \
    opcode == ir::PTXInstruction::Red)

#define SUR_INST(opcode) \
  (opcode == ir::PTXInstruction::Suld || \
   opcode == ir::PTXInstruction::Sust || \
   opcode == ir::PTXInstruction::Sured || \
   opcode == ir::PTXInstruction::Suq)

#define TEX_INST(opcode) \
  (opcode == ir::PTXInstruction::Tex || \
   opcode == ir::PTXInstruction::Tld4 || \
   opcode == ir::PTXInstruction::Txq)

#define BRANCH_INST(opcode) \
  (opcode == ir::PTXInstruction::Bra || \
   opcode == ir::PTXInstruction::Call || \
   opcode == ir::PTXInstruction::Ret || \
   opcode == ir::PTXInstruction::Exit)


#if TRACEGEN_VER == 131

#define SET_STORE_FLAG(inst_info, opcode) \
  do { \
  } while(0)

#define SET_LOAD_FLAG(inst_info, flag_value) \
  do { \
      inst_info->is_load = flag_value; \
  } while(0)


#define IS_MEM_INST(inst_info, ptx_inst)  ((inst_info->is_load == 1) || ST_INST(ptx_inst->opcode)) 


#define SET_ACTIVE_MASK(inst_info, warp_active_mask) \
  do { \
    inst_info->active_mask = warp_active_mask; \
  } while(0)
                                  
//all of these fields are set to zero by memset, so this is not necessary!
#if 0
#define RESET_OTHER_FIELDS(inst_info) \
  do { \
    inst_info->active_mask = 0; \
    inst_info->br_taken_mask = 0; \
    inst_info->br_target_addr = 0; \
    inst_info->mem_addr = 0; \
    inst_info->mem_access_size = 0; \
    inst_info->num_barrier_threads = 0; \
    inst_info->addr_space = GPU_ADDR_SP_INVALID; \
    inst_info->cache_level = GPU_CACHE_INVALID; \
    inst_info->cache_operator = GPU_CACHE_OP_INVALID; \
  } while(0)
#else
#define RESET_OTHER_FIELDS(inst_info) \
  do { \
  } while(0)
#endif


#define SET_LD_ADDR_AND_SIZE(inst_info, addr, size) \
  do { \
    inst_info->mem_addr = addr; \
    inst_info->mem_access_size = size; \
  } while(0)

#define SET_ST_ADDR_AND_SIZE(inst_info, addr, size) \
  do { \
    inst_info->mem_addr = addr; \
    inst_info->mem_access_size = size; \
  } while(0)

#define SET_MUL_TRACE_OP_FLAG(inst_info) \
  do { \
  } while(0)

#define RESET_MUL_TRACE_OP_FLAG(inst_info) \
  do { \
  } while(0)

#define SET_BRANCH_TARGET(inst_info, addr) \
  do { \
    inst_info->br_target_addr = addr; \
  } while(0)

#define SET_BRANCH_TAKEN_MASK(inst_info, mask) \
  do { \
    inst_info->br_taken_mask = mask; \
  } while(0)

#define SET_RECONV_ADDR(inst_info, addr) \
  do { \
    inst_info->reconv_inst_addr = addr; \
  } while(0)

#define SET_BRANCH_TAKEN_FLAG(inst_info, flag) \
  do { \
  } while(0)

#define SET_ADDR_SPACE(inst_info, address_space) \
  do { \
    inst_info->addr_space = address_space; \
  } while(0)

#define SET_CACHE_LEVEL(inst_info, level) \
  do { \
    inst_info->cache_level = level; \
  } while(0)

#define SET_CACHE_OPERATOR(inst_info, op) \
  do { \
    inst_info->cache_operator = op; \
  } while(0)

#define SET_FENCE_LEVEL(inst_info, fence_level) \
  do { \
    inst_info->level = fence_level; \
  } while(0)

#define WRITE_INST_TO_FILE(file, inst_info) \
  do { \
    file << "opcode " << dec << (uint32_t)inst_info->opcode << endl; \
    file << "num_read_regs " << (uint32_t)inst_info->num_read_regs << endl; \
    file << "num_dest_regs " << (uint32_t)inst_info->num_dest_regs << endl; \
    \
    file << "src1 " << (uint32_t)inst_info->src[0] << endl; \
    file << "src2 " << (uint32_t)inst_info->src[1] << endl; \
    file << "src3 " << (uint32_t)inst_info->src[2] << endl; \
    file << "src4 " << (uint32_t)inst_info->src[3] << endl; \
    \
    file << "dest1 " << (uint32_t)inst_info->dst[0] << endl; \
    file << "dest2 " << (uint32_t)inst_info->dst[1] << endl; \
    file << "dest3 " << (uint32_t)inst_info->dst[2] << endl; \
    file << "dest4 " << (uint32_t)inst_info->dst[3] << endl; \
    \
    file << "is_fp " << inst_info->is_fp << endl; \
    file << "cf_type " << (uint32_t)inst_info->cf_type << endl; \
    file << "is_load " << inst_info->is_load << endl; \
    \
    file << "inst_size " << (uint32_t)inst_info->size << endl; \
    \
    file << "inst_addr " << hex << inst_info->inst_addr << dec << endl; \
    file << "active_mask " << hex << inst_info->active_mask << dec << endl; \
    \
    file << "br_target_addr " << hex << inst_info->br_target_addr << dec << endl; \
    file << "reconv_inst_addr/mem_addr " << hex << inst_info->reconv_inst_addr << dec << endl; \
    file << "br_taken_mask " << hex << inst_info->br_taken_mask << dec << endl; \
    \
    file << "mem_addr/reconv_inst_addr " << hex << inst_info->mem_addr << endl; \
    file << "mem_access_size/barrier_id " << (uint32_t)inst_info->mem_access_size << endl; \
    file << "addr_space/fence_level " << (uint32_t)inst_info->addr_space << endl; \
    file << "cache_operator " << (uint32_t)inst_info->cache_operator << endl; \
    \
    file << "barrier_id/mem_access_size " << (uint32_t)inst_info->barrier_id << endl; \
    file << "num_barrier_threads " << (uint32_t)inst_info->num_barrier_threads << endl; \
    \
    file << "cache_level " << (uint32_t)inst_info->cache_level << endl; \
    file << "fence_level/addr_space " << (uint32_t)inst_info->level << endl; \
  } while(0)

#elif TRACEGEN_VER == 10

#define SET_STORE_FLAG(inst_info, opcode) \
  do { \
    inst_info->has_st = ST_INST(opcode); \
  } while(0)


// this is actually the number of loads, not a flag!
#define SET_LOAD_FLAG(inst_info, flag_value) \
  do { \
    inst_info->num_ld = flag_value; \
  } while(0)


#define IS_MEM_INST(inst_info, ptx_inst)  ((inst_info->num_ld >= 1) || (inst_info->has_st == true)) 


#define SET_ACTIVE_MASK(inst_info, warp_active_mask) \
  do { \
    inst_info->ld_vaddr2 = warp_active_mask; \
  } while(0)

//all of these fields are set to zero by memset, so this is not necessary!
#define RESET_OTHER_FIELDS(inst_info) \
  do { \
    inst_info->branch_target = 0; \
    inst_info->actually_taken = 0; \
    inst_info->st_vaddr = inst_info->mem_write_size = 0; \
    inst_info->ld_vaddr1 = inst_info->mem_read_size = 0; \
    inst_info->rep_dir = 0; \
  } while(0)


#define SET_LD_ADDR_AND_SIZE(inst_info, addr, size) \
  do { \
    inst_info->ld_vaddr1 = addr; \
    inst_info->mem_read_size = size; \
  } while(0)

#define SET_ST_ADDR_AND_SIZE(inst_info, addr, size) \
  do { \
    inst_info->st_vaddr = addr; \
    inst_info->mem_write_size = size; \
  } while(0)

#define SET_MUL_TRACE_OP_FLAG(inst_info) \
  do { \
    inst_info->has_immediate = true; \
  } while(0)

#define RESET_MUL_TRACE_OP_FLAG(inst_info) \
  do { \
    inst_info->has_immediate = false; \
  } while(0)

#define SET_BRANCH_TARGET(inst_info, addr) \
  do { \
    inst_info->branch_target = addr; \
  } while(0)

#define SET_BRANCH_TAKEN_MASK(inst_info, mask) \
  do { \
    inst_info->ld_vaddr1 = mask; \
  } while(0)

#define SET_RECONV_ADDR(inst_info, addr) \
  do { \
    inst_info->st_vaddr = addr; \
  } while(0)

#define SET_BRANCH_TAKEN_FLAG(inst_info, flag) \
  do { \
    inst_info->actually_taken = flag; \
  } while(0)

#define SET_ADDR_SPACE(inst_info, address_space) \
  do { \
  } while(0)

#define SET_CACHE_LEVEL(inst_info, level) \
  do { \
  } while(0)

#define SET_CACHE_OPERATOR(inst_info, op) \
  do { \
  } while(0)

#define SET_FENCE_LEVEL(inst_info, level) \
  do { \
  } while(0)

#define WRITE_INST_TO_FILE(file, inst_info) \
  do { \
    file << "t_info->uop_opcode " << dec << inst_info->opcode << endl; \
    file << "t_info->num_read_regs: " << hex <<  (uint32_t) inst_info->num_read_regs << endl; \
    file << "t_info->num_dest_regs: " << hex << (uint32_t) inst_info->num_dest_regs << endl; \
    \
    file << "t_info->src1: " << hex << (uint32_t) inst_info->src[0] << endl; \
    file << "t_info->src2: " << hex << (uint32_t) inst_info->src[1] << endl; \
    file << "t_info->src3: " << hex << (uint32_t) inst_info->src[2] << endl; \
    file << "t_info->src4: " << hex << (uint32_t) inst_info->src[3] << endl; \
    \
    file << "t_info->dest1: " << hex << (uint32_t) inst_info->dst[0] << endl; \
    file << "t_info->dest2: " << hex << (uint32_t) inst_info->dst[1] << endl; \
    file << "t_info->dest3: " << hex << (uint32_t) inst_info->dst[2] << endl; \
    file << "t_info->dest4: " << hex << (uint32_t) inst_info->dst[3] << endl; \
    \
    file << "t_info->cf_type: " << hex << (uint32_t) inst_info->cf_type << endl; \
    file << "t_info->has_immediate: " << hex << (uint32_t) inst_info->has_immediate << endl; \
    \
    file << "t_info->r_dir:" << (uint32_t) inst_info->rep_dir << endl; \
    file << "t_info->has_st: " << hex << (uint32_t) inst_info->has_st << endl; \
    file << "t_info->num_ld: " << hex << (uint32_t) inst_info->num_ld << endl; \
    file << "t_info->mem_read_size: " << hex << (uint32_t) inst_info->mem_read_size << endl; \
    file << "t_info->mem_write_size: " << hex << (uint32_t) inst_info->mem_write_size << endl; \
    file << "t_info->is_fp: " << (uint32_t) inst_info->is_fp << endl; \
    \
    file << "t_info->ld_vaddr1: " << hex << (uint32_t) inst_info->ld_vaddr1 << endl; \
    file << "t_info->ld_vaddr2: " << hex << (uint32_t) inst_info->ld_vaddr2 << endl; \
    file << "t_info->st_vaddr: " << hex << (uint32_t) inst_info->st_vaddr << endl; \
    \
    file << "t_info->inst_addr: " << dec << (uint32_t) inst_info->inst_addr << endl; \
    \
    file << "t_info->branch_target: " << dec << (uint32_t) inst_info->branch_target << endl; \
    file << "t_info->actually_taken: " << hex << (uint32_t) inst_info->actually_taken << endl; \
    file << "t_info->write_flg: " << hex << (uint32_t) inst_info->write_flg << endl; \
  } while(0)


#endif


using namespace std;


/////////////////////////////////////////////////////////////////////////////////////////////// 
// Opcode enumerator
// These should be exactly matched with the Macsim
/////////////////////////////////////////////////////////////////////////////////////////////// 
enum GPU_OPCODE_ENUM_ {
  GPU_INVALID = 0,
  GPU_ABS,
  GPU_ABS64,
  GPU_ADD, 
  GPU_ADD64, 
	GPU_ADDC,
	GPU_AND,
	GPU_AND64,
	GPU_ATOM_GM,
	GPU_ATOM_SM,
	GPU_ATOM64_GM,
	GPU_ATOM64_SM,
	GPU_BAR_ARRIVE,
  GPU_BAR_SYNC,
  GPU_BAR_RED,
	GPU_BFE,
	GPU_BFE64,
	GPU_BFI,
	GPU_BFI64,
	GPU_BFIND,
	GPU_BFIND64,
	GPU_BRA,
	GPU_BREV,
	GPU_BREV64,
	GPU_BRKPT,
	GPU_CALL,
	GPU_CLZ,
	GPU_CLZ64,
	GPU_CNOT,
	GPU_CNOT64,
	GPU_COPYSIGN,
	GPU_COPYSIGN64,
	GPU_COS,
	GPU_CVT,
	GPU_CVT64,
	GPU_CVTA,
	GPU_CVTA64,
	GPU_DIV,
	GPU_DIV64,
	GPU_EX2,
	GPU_EXIT,
	GPU_FMA,
	GPU_FMA64,
	GPU_ISSPACEP,
	GPU_LD,
	GPU_LD64,
	GPU_LDU,
	GPU_LDU64,
	GPU_LG2,
	GPU_MAD24,
	GPU_MAD,
	GPU_MAD64,
	GPU_MAX,
	GPU_MAX64,
	GPU_MEMBAR_CTA,
	GPU_MEMBAR_GL,
	GPU_MEMBAR_SYS,
	GPU_MIN,
	GPU_MIN64,
	GPU_MOV,
	GPU_MOV64,
	GPU_MUL24,
	GPU_MUL,
	GPU_MUL64,
	GPU_NEG,
	GPU_NEG64,
	GPU_NOT,
	GPU_NOT64,
	GPU_OR,
	GPU_OR64,
	GPU_PMEVENT,
	GPU_POPC,
	GPU_POPC64,
	GPU_PREFETCH,
	GPU_PREFETCHU,
	GPU_PRMT,
	GPU_RCP,
	GPU_RCP64,
	GPU_RED_GM,
	GPU_RED_SM,
	GPU_RED64_GM,
	GPU_RED64_SM,
	GPU_REM,
	GPU_REM64,
	GPU_RET,
	GPU_RSQRT,
	GPU_RSQRT64,
	GPU_SAD,
	GPU_SAD64,
	GPU_SELP,
	GPU_SELP64,
	GPU_SET,
	GPU_SET64,
	GPU_SETP,
	GPU_SETP64,
	GPU_SHL,
	GPU_SHL64,
	GPU_SHR,
	GPU_SHR64,
	GPU_SIN,
	GPU_SLCT,
	GPU_SLCT64,
	GPU_SQRT,
	GPU_SQRT64,
	GPU_ST,
	GPU_ST64,
	GPU_SUB,
	GPU_SUB64,
	GPU_SUBC,
	GPU_SULD,
	GPU_SULD64,
	GPU_SURED,
	GPU_SURED64,
	GPU_SUST,
	GPU_SUST64,
	GPU_SUQ,
  GPU_TESTP,
  GPU_TESTP64,
  GPU_TEX,
  GPU_TLD4,
  GPU_TXQ,
  GPU_TRAP,
  GPU_VABSDIFF,
  GPU_VADD,
  GPU_VMAD,
  GPU_VMAX,
  GPU_VMIN,
  GPU_VSET,
  GPU_VSHL,
  GPU_VSHR,
  GPU_VSUB,
  GPU_VOTE,
  GPU_XOR,
  GPU_XOR64,
  GPU_RECONVERGE,
  GPU_PHI,
  GPU_MEM_LD_GM,
  GPU_MEM_LD_LM,
  GPU_MEM_LD_SM,
  GPU_MEM_LD_CM,
  GPU_MEM_LD_TM,
  GPU_MEM_LD_PM,
  GPU_MEM_LDU_GM,
  GPU_MEM_ST_GM,
  GPU_MEM_ST_LM,
  GPU_MEM_ST_SM,
  GPU_DATA_XFER_GM,
  GPU_DATA_XFER_LM,
  GPU_DATA_XFER_SM,
  GPU_OPCODE_LAST
} GPU_OPCODE_ENUM;


enum GPU_ADDRESS_SPACE_ENUM_ {
  GPU_ADDR_SP_INVALID = 0,
  GPU_ADDR_SP_CONST,
  GPU_ADDR_SP_GLOBAL,
  GPU_ADDR_SP_LOCAL,
  GPU_ADDR_SP_PARAM,
  GPU_ADDR_SP_SHARED,
  GPU_ADDR_SP_TEXTURE,
  GPU_ADDR_SP_GENERIC,
  GPU_ADDR_SP_LAST
} GPU_ADDRESS_SPACE_ENUM;


enum GPU_CACHE_OP_ENUM_ {
  GPU_CACHE_OP_INVALID = 0,
  GPU_CACHE_OP_CA,
  GPU_CACHE_OP_CV,
  GPU_CACHE_OP_CG,
  GPU_CACHE_OP_CS,
  GPU_CACHE_OP_WB,
  GPU_CACHE_OP_WT,
  GPU_CACHE_OP_LAST
} GPU_CACHE_OP_ENUM;


enum GPU_CACHE_LEVEL_ENUM_ {
  GPU_CACHE_INVALID = 0,
  GPU_CACHE_L1,
  GPU_CACHE_L2,
  GPU_CACHE_LAST
} GPU_CACHE_LEVEL_ENUM;

enum GPU_FENCE_LEVEL_ENUM_ {
  GPU_FENCE_INVALID = 0,
  GPU_FENCE_CTA,
  GPU_FENCE_GL,
  GPU_FENCE_SYS,
  GPU_FENCE_LAST
} GPU_FENCE_LEVEL_ENUM;



// Sanity check::
// We should match with total number of instructions in gpuocelot (ptx)

// Opcode translation
// missing instruction from PTX manual : madc, shfl
int opcode_translator[ir::PTXInstruction::Nop][4] = 
{
  // 32 bit integer    , 64 bit integer   , 32 bit FP        , 64 bit FP
  { (int)GPU_ABS       , (int)GPU_ABS64   , (int)GPU_ABS     , (int)GPU_ABS64     }, // Abs
  { (int)GPU_ADD       , (int)GPU_ADD64   , (int)GPU_ADD     , (int)GPU_ADD64     }, // Add
  { (int)GPU_ADDC      , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // AddC
  { (int)GPU_AND       , (int)GPU_AND64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // And
  //{ (int)GPU_ATOM    , (int)GPU_ATOM64  , (int)GPU_ATOM    , (int)GPU_INVALID   }, // Atom
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Atom
  //{ (int)GPU_BAR     , (int)GPU_BAR     , (int)GPU_INVALID , (int)GPU_INVALID   }, // Bar
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Bar
  { (int)GPU_BFE       , (int)GPU_BFE64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // Bfe
  { (int)GPU_BFI       , (int)GPU_BFI64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // Bfi
  { (int)GPU_BFIND     , (int)GPU_BFIND64 , (int)GPU_INVALID , (int)GPU_INVALID   }, // Bfind
  { (int)GPU_BRA       , (int)GPU_BRA     , (int)GPU_INVALID , (int)GPU_INVALID   }, // Bra
  { (int)GPU_BREV      , (int)GPU_BREV64  , (int)GPU_INVALID , (int)GPU_INVALID   }, // Brev
  { (int)GPU_BRKPT     , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Brkpt
  { (int)GPU_CALL      , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Call
  { (int)GPU_CLZ       , (int)GPU_CLZ64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // Clz
  { (int)GPU_CNOT      , (int)GPU_CNOT64  , (int)GPU_INVALID , (int)GPU_INVALID   }, // CNot
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_COPYSIGN, (int)GPU_COPYSIGN64}, // CopySign
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_COS     , (int)GPU_INVALID   }, // Cos
  { (int)GPU_CVT       , (int)GPU_CVT64   , (int)GPU_CVT     , (int)GPU_CVT64     }, // Cvt
  { (int)GPU_CVTA      , (int)GPU_CVTA64  , (int)GPU_INVALID , (int)GPU_INVALID   }, // Cvta
  { (int)GPU_DIV       , (int)GPU_DIV64   , (int)GPU_DIV     , (int)GPU_DIV64     }, // Div
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_EX2     , (int)GPU_INVALID   }, // Ex2
  { (int)GPU_EXIT      , (int)GPU_EXIT    , (int)GPU_INVALID , (int)GPU_INVALID   }, // Exit
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_FMA     , (int)GPU_FMA64     }, // Fma
  { (int)GPU_ISSPACEP  , (int)GPU_ISSPACEP, (int)GPU_INVALID , (int)GPU_INVALID   }, // Isspacep
  { (int)GPU_LD        , (int)GPU_LD64    , (int)GPU_LD      , (int)GPU_LD64      }, // Ld
  { (int)GPU_LDU       , (int)GPU_LDU64   , (int)GPU_LDU     , (int)GPU_LDU64     }, // Ldu
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_LG2     , (int)GPU_INVALID   }, // Lg2
  { (int)GPU_MAD24     , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Mad24
  { (int)GPU_MAD       , (int)GPU_MAD64   , (int)GPU_MAD     , (int)GPU_MAD64     }, // Mad
  { (int)GPU_MAX       , (int)GPU_MAX64   , (int)GPU_MAX     , (int)GPU_MAX64     }, // Max
  //{ (int)GPU_MEMBAR  , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Membar
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Membar
  { (int)GPU_MIN       , (int)GPU_MIN64   , (int)GPU_MIN     , (int)GPU_MIN64     }, // Min
  { (int)GPU_MOV       , (int)GPU_MOV64   , (int)GPU_MOV     , (int)GPU_MOV64     }, // Mov
  { (int)GPU_MUL24     , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Mul24
  { (int)GPU_MUL       , (int)GPU_MUL64   , (int)GPU_MUL     , (int)GPU_MUL64     }, // Mul
  { (int)GPU_NEG       , (int)GPU_NEG64   , (int)GPU_NEG     , (int)GPU_NEG64     }, // Neg
  { (int)GPU_NOT       , (int)GPU_NOT64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // Not
  { (int)GPU_OR        , (int)GPU_OR64    , (int)GPU_INVALID , (int)GPU_INVALID   }, // Or
  { (int)GPU_PMEVENT   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Pmevent
  { (int)GPU_POPC      , (int)GPU_POPC64  , (int)GPU_INVALID , (int)GPU_INVALID   }, // Popc
  { (int)GPU_PREFETCH  , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Prefetch
  { (int)GPU_PREFETCHU , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Prefetchu
  { (int)GPU_PRMT      , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Prmt
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_RCP     , (int)GPU_RCP64     }, // Rcp
  //{ (int)GPU_RED     , (int)GPU_RED64   , (int)GPU_RED     , (int)GPU_INVALID   }, // Red
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Red
  { (int)GPU_REM       , (int)GPU_REM64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // Rem
  { (int)GPU_RET       , (int)GPU_RET     , (int)GPU_INVALID , (int)GPU_INVALID   }, // Ret
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_RSQRT   , (int)GPU_RSQRT64   }, // Rsqrt
  { (int)GPU_SAD       , (int)GPU_SAD64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // Sad
  { (int)GPU_SELP      , (int)GPU_SELP64  , (int)GPU_SELP    , (int)GPU_SELP64    }, // SelP
  { (int)GPU_SET       , (int)GPU_SET64   , (int)GPU_SET     , (int)GPU_SET64     }, // Set
  { (int)GPU_SETP      , (int)GPU_SETP64  , (int)GPU_SETP    , (int)GPU_SETP64    }, // SetP
  { (int)GPU_SHL       , (int)GPU_SHL64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // Shl
  { (int)GPU_SHR       , (int)GPU_SHR64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // Shr
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_SIN     , (int)GPU_INVALID   }, // Sin
  { (int)GPU_SLCT      , (int)GPU_SLCT64  , (int)GPU_SLCT    , (int)GPU_SLCT64    }, // Slct
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_SQRT    , (int)GPU_SQRT64    }, // Sqrt
  { (int)GPU_ST        , (int)GPU_ST64    , (int)GPU_ST      , (int)GPU_ST64      }, // St
  { (int)GPU_SUB       , (int)GPU_SUB64   , (int)GPU_SUB     , (int)GPU_SUB64     }, // Sub
  { (int)GPU_SUBC      , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // SubC
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Suld
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Sured
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Sust
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Suq
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_TESTP   , (int)GPU_TESTP64   }, // TestP
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Tex
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Tld4
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Txq
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Trap
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vabsdiff
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vadd
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vmad
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vmax
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vmin
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vset
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vshl
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vshr
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vsub
  { (int)GPU_VOTE      , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Vote
  { (int)GPU_XOR       , (int)GPU_XOR64   , (int)GPU_INVALID , (int)GPU_INVALID   }, // Xor
  { (int)GPU_RECONVERGE, (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Reconverge
  { (int)GPU_INVALID   , (int)GPU_INVALID , (int)GPU_INVALID , (int)GPU_INVALID   }, // Phi
};


///////////////////////////////////////////////////////////////////////////////////////////////
// Control Flow Instruction enumerator
// These should be exactly matched with the Macsim
///////////////////////////////////////////////////////////////////////////////////////////////
enum CF_TYPE_enum {
  NOT_CF,                       // not a control flow instruction
  CF_BR,                        // an unconditional branch
  CF_CBR,                       // a conditional branch
  CF_CALL,                      // a call
  // below this point are indirect cfs
  CF_IBR,                       // an indirect branch
  CF_ICALL,                     // an indirect call
  CF_ICO,                       // an indirect jump to co-routine
  CF_RET,                       // a return
  CF_SYS,
  CF_ICBR                       // an indirect conditional branch
} CF_TYPE;


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////



#if WRITE_DEBUG == 1
ofstream *debug_stream;
#endif



///////////////////////////////////////////////////////////////////////////////////////////////
// We need to set environmental variables
// TRACE_PATH
// TRACE_NAME
// USE_KERNEL_NAME


///////////////////////////////////////////////////////////////////////////////////////////////
// Ptx to X86 trace generator constructor
///////////////////////////////////////////////////////////////////////////////////////////////
trace::X86TraceGenerator::X86TraceGenerator()
  : init(false)
  , num_warps_per_block(0)
  , num_total_warps(0)
  , total_inst_count(0)
  , blockDimX(1)
  , blockDimY(1)
  , blockDimZ(1)
  , gridDimX(1)
  , gridDimY(1)
  , gridDimZ(1)
  , kernel_count(0)
{
  m_compute = "2.0";
#ifndef USE_32BIT_ADDR
  mem_addr_flag = ~0llu;
#else
  mem_addr_flag = ~0u;
#endif

//  opcode_stats = new uint64_t[GPU_OPCODE_LAST];
}


///////////////////////////////////////////////////////////////////////////////////////////////
// destructor
// Ptx to X86 trace generator
///////////////////////////////////////////////////////////////////////////////////////////////
trace::X86TraceGenerator::~X86TraceGenerator()
{
  report("destructor");
  dump_opcode_stats();
  finalize();

  if (init) {
#if WRITE_DEBUG == 1
    debug_stream->close();
    delete debug_stream;
#endif
    txt_kernel_config_file.close();
  }

//  delete[] opcode_stats;
}


int trace::X86TraceGenerator::calculate_occupancy(const executive::ExecutableKernel& kernel)
{
  ///
  /// Kernel information
  ///
  blockDimX = kernel.blockDim().x;
  blockDimY = kernel.blockDim().y;
  blockDimZ = kernel.blockDim().z;
  gridDimX  = kernel.gridDim().x;
  gridDimY  = kernel.gridDim().y;
  gridDimZ  = kernel.gridDim().z; // will be 1 always

  assert(gridDimZ == 1);

  num_warps_per_block = (blockDimX * blockDimY * blockDimZ + (WARP_SIZE - 1)) / WARP_SIZE;
  num_total_warps = num_warps_per_block * gridDimX * gridDimY * gridDimZ;


  // maximum block calculation
  int max_block = 8;


  // base hardware configuration (2.0 compute capability)
  int total_shared_memory = 49152;
  int total_thread        = 1536;
  int total_register      = 32768;
  int shared_mem_allocation_granularity = 128;


  // Registers calculation
  int num_register_per_block  = 0;
  int num_register_per_thread = m_kernel_register_map[kernel.name];
  int shared_mem_per_block    = m_kernel_sharedmem_map[kernel.name];


  report("New kernel launched");
  report("compute version:" << m_compute);
  report("grid  " << gridDimX <<  " x " << gridDimY <<  " x " << gridDimZ);
  report("block " << blockDimX << " x " << blockDimY << " x " << blockDimZ);
  report("number of warps per block:" << num_warps_per_block);
  report("number of total warps:" << num_total_warps);
  report("# threads per block : " << num_warps_per_block * WARP_SIZE);
  report("number of register per thread:" << num_register_per_thread);
  report("number of shared memory per thread:" << shared_mem_per_block);


  // Threads calculation
  int num_threads_per_block = num_warps_per_block * WARP_SIZE;
  if (max_block > total_thread / num_threads_per_block)
    max_block = total_thread / num_threads_per_block;

  // Shared memory calculation
  if (shared_mem_per_block > 0) {
    int ceil_1 = ((shared_mem_per_block + (shared_mem_allocation_granularity - 1)) /
        shared_mem_allocation_granularity) * shared_mem_allocation_granularity;

    if (ceil_1 == 0)
      ceil_1 = shared_mem_allocation_granularity;

    if (max_block > total_shared_memory / ceil_1)
      max_block = total_shared_memory / ceil_1;
  }


  if (m_compute == "2.0") {
    int ceil_1 = num_register_per_thread * 32;
    ceil_1 = ((ceil_1 + (64-1)) / 64) * 64;
    if (ceil_1 == 0)
      ceil_1 = 64;
    ceil_1 *= num_warps_per_block;
    num_register_per_block = ceil_1;
  }
  // TODO (jaekyu, 9-26-2012)
  // To support other computing capability
  else {
    assert(0);
  }

  if (max_block > total_register / num_register_per_block)
    max_block = total_register / num_register_per_block;

  report("max blocks per core : " << max_block);

  return max_block;
}


///////////////////////////////////////////////////////////////////////////////////////////////
// called when a traced kernel is launched to retrieve some parameters from the kernel
///////////////////////////////////////////////////////////////////////////////////////////////
void trace::X86TraceGenerator::initialize(const executive::ExecutableKernel& kernel)
{
  ///
  /// Initialization of GPUOcelot-Macsim trace generator
  ///
  static bool init_x86_tracegenerator = false;
  if (!init_x86_tracegenerator) {
    // We have opcodes for 82 GPU Instructions! this check lets us 
    // know if new instructions have been added (or removed), but 
    // what if there have been modifications and count hasn't changed?
    assert(ir::PTXInstruction::Nop == 82); 
    // same concern as above, 
    // also ensure that SPECIAL_REG_START + special reg value is < 256
    // we are using 1 byte fields to store register ids
    // for trace_ver >= 1.31 we are using 2 bytes for register ids 
    // and SPECIAL_REG_START = 900
    assert(ir::PTXOperand::SpecialRegister_invalid == 54);
  
    for (int ii = 0; ii < GPU_OPCODE_LAST; ++ii) opcode_stats[ii] = 0;

    init_x86_tracegenerator = true;

    char *t_name;
    char *t_path;

    // get TRACE_PATH environment variable
    t_path = getenv("TRACE_PATH");
    if (t_path == NULL) {
      report("TRACE_PATH not set up");
    }
    // assert(t_path != NULL);

    trace_path = t_path;
    trace_path.append("/");


    // get TRACE_NAME environment variable
    t_name = getenv("TRACE_NAME");
    if (t_name != NULL)
      trace_name = t_name;
    else
      trace_name = "Trace";


    ///////////////////////////////
    // get list of kernels for which traces are to be generated (and their count as well)
    char *tracegen_info_path = getenv("TRACEGEN_INFO_PATH");
    ifstream tracegen_info_file;

    tracegen_info_file.open(tracegen_info_path);
    if (!tracegen_info_file.fail()) {
      int kernel_name_count = 0;
      int tracegen_count;
      string kernel_name;

      while (1) {
        tracegen_info_file >> kernel_name;
        if (tracegen_info_file.eof()) break;

        if (kernel_name != "") {
          ++kernel_name_count;

          if (kernel_name == "all") {
            tracegen_all = true;
            tracegen_none = false;
            break;
          }
          else if (kernel_name == "none") {
            tracegen_all = false;
            tracegen_none = true;
            break;
          }
          else {
            tracegen_info_file >> tracegen_count;
            if (tracegen_count == 0) {
              tracegen_count = 65536;
            }
            kernel_tracegen_map[kernel_name] = tracegen_count;
          }
        }
      }

      if (!kernel_name_count) {
        tracegen_all = true;
        tracegen_none = false;
      }
    }
    else {
      tracegen_all = true;
      tracegen_none = false;
      cout << "all enabled\n";
    }

    tracegen = false;
    ///////////////////////////////


    // get KERNEL_INFO_PATH : get register usage information from the file
    char* kernel_info_path = getenv("KERNEL_INFO_PATH");
    ifstream kernel_info_file;

    kernel_info_file.open(kernel_info_path);

    string kernel_name;
    int register_num;
    int sharedmem;

    if (!kernel_info_file.fail()) {
      while (kernel_info_file >> kernel_name >> register_num >> sharedmem) {
        m_kernel_register_map[kernel_name] = register_num;
        m_kernel_sharedmem_map[kernel_name] = sharedmem;
      }
    }
    else {
    }

    // get compute version
    char* compute_version = getenv("COMPUTE_VERSION");
    if (compute_version != NULL)
      m_compute = string(compute_version);


    // set trace file extension
    extension = "raw";

    last_block_id = -1;
  }


  /////////////////////////////////////////////////////////////////////////////////////////////
  // If multiple kernels exist in the program, initialize() function will be called several 
  // times. There are some structures that are used in the previous kernel
  // thus, we need to reset those values
  /////////////////////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////////////////////
  // Since each block is executed in sequential, we open gzFile for current block and
  // close when it has been terminate. However, since we don't know when exactly a block
  // terminates, we maintain last_block_id and compare with current block id.
  // When ids do not match, a new block has been started.
  /////////////////////////////////////////////////////////////////////////////////////////////
  if (last_block_id != -1) {
    int block_id = last_block_id;
    for (int ii = 0; ii < num_warps_per_block; ++ii) {
      Trace_info *tr_info = &trace_info[block_id * num_warps_per_block + ii];

      if (tracegen) {
        if (tr_info->bytes_accumulated) {
          int bytes_written = gzwrite(tr_info->trace_stream, tr_info->trace_buf, tr_info->bytes_accumulated); 
          if (bytes_written != tr_info->bytes_accumulated) {
            report("gz file write error");
            assert(0);
          }
        }
        gzclose(tr_info->trace_stream);
      }

      Thread_info *th_info = &thread_info[block_id * num_warps_per_block + ii];
      if (tracegen && sizeof(Thread_info) != gzwrite(gz_config_file, th_info, sizeof(Thread_info))) {
        report("unable to write to config file");
        exit(-1);
      }

      txt_config_file << th_info->thread_id << " " << th_info->inst_count << "\n";
      info_file << th_info->thread_id << " " << tr_info->inst_count << "\n";
    }

    txt_config_file.close();

    info_file << "kernel_count " << kernel_inst_count << "\n";
    info_file.close();
  }

  /////////////////////////////////////////////////////////////////////////////////////////////
  // Termination condition check
  /////////////////////////////////////////////////////////////////////////////////////////////
  if (total_inst_count > 100000000) {
    dump_opcode_stats();
    report("total instruction count exceeds 100M.. stop here...");
    assert(0);
    exit(0);
  }

  ///////////////////////////////////////
  if (tracegen_all) {
    tracegen = true;
  }
  else if (tracegen_none) {
    tracegen = false;
  }
  else if (kernel_tracegen_map[kernel.name]) {
    tracegen = true;
    --kernel_tracegen_map[kernel.name];
  }
  else {
    tracegen = false;
  }

  kernel_inst_count = 0;
  ///////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////////////////////
  /// reset instruction hash for a new kernel
  /////////////////////////////////////////////////////////////////////////////////////////////
  for (auto itr = inst_storage.begin(); itr != inst_storage.end(); ++itr) {
    delete (*itr).second;
  }
  inst_storage.clear();
  last_block_id = -1;


  /////////////////////////////////////////////////////////////////////////////////////////////
  // Calculate the resource occupancy of a new kernel
  /////////////////////////////////////////////////////////////////////////////////////////////
  int max_block = calculate_occupancy(kernel);




  // set kernel name
  char temp[10];
  kernel_name = kernel.name.substr(0, 251); //`getconf NAME_MAX /trace` or `getconf NAME_MAX /` returns 255, and we want to accomodate _xxx for each kernel

  // if same kernel has been called several times, corresponding suffix will be added
  // to the name of the kernel.
  if (kernel_count_map.find(kernel_name) != kernel_count_map.end()) {
    kernel_count = ++kernel_count_map[kernel_name];
  }
  else {
    kernel_count_map[kernel_name] = 0;
    kernel_count = 0;
  }

  sprintf(temp, "_%d", kernel_count);
  kernel_name.append(temp);
  kernel_name.append("/");

  string command("mkdir -p ");
  command.append(trace_path);
  command.append(kernel_name);

  string kernel_path = trace_path;
  kernel_path.append(kernel_name);


  /* to satisfy compiler */
  int status;
  status = system(command.c_str());
  if (status == -1) {
    status = system(command.c_str());
  }
  report("" << command.c_str() << " (status " <<  status << ")\n");
  report("errno is " << errno << " message is " << strerror(errno) << "\n");


  string kernel_config_file = trace_path;
  kernel_config_file.append("kernel_config.txt");
  txt_kernel_config_file.open(kernel_config_file.c_str(), std::ios_base::app);

  // open kernel configuration file
  if (init == false) {
    txt_kernel_config_file << "newptx\n";
    txt_kernel_config_file << TRACEGEN_VER << "\n";
    txt_kernel_config_file << -1 << "\n";
  }

  if (tracegen) {
    txt_kernel_config_file << kernel_path << "Trace.txt\n";
  }
  txt_kernel_config_file.close();


  char file_path[400];

#if WRITE_DEBUG == 1
  sprintf(file_path, "%s%sdebug.txt", trace_path.c_str(), kernel_name.c_str());
  debug_stream = new ofstream(file_path);
#endif


  // write config file in zlib format
  // no of threads
  // thread no and start instruction for each thread
  sprintf(file_path, "%s%s%s.%s", 
      trace_path.c_str(), kernel_name.c_str(), trace_name.c_str(), extension.c_str());
  gz_config_file = gzopen(file_path, "wb");

  // write number of threads
  if (sizeof(uint32_t) != gzwrite(gz_config_file, &num_total_warps, sizeof(uint32_t))) {
    std::cerr << "unable to write to config file\n";
    exit(-1);
  }


  /////////////////////////////////////////////////////////////////////////////////////////////
  // Get memory argument information
  /////////////////////////////////////////////////////////////////////////////////////////////
  sprintf(file_path, "%s%sdata.txt", trace_path.c_str(), kernel_name.c_str());
  ofstream data_file(file_path);

  data_file << "[MemoryArgument]\n";
  executive::Device::MemoryAllocationVector MAV = kernel.device->getAllAllocations();//event
  for (auto I = MAV.begin(), E = MAV.end(); I != E; ++I) {
    executive::Device::MemoryAllocation* ma = (*I);
    data_file << ma->pointer() << " " << ma->size() << "\n";;
//    report(ma->pointer() << " " << ma->size());
  }
  data_file.close();


  // dump PTX for kernel to kernel.txt file
  //////////////////////////////////////
  const ir::Module *module = kernel.module;
  sprintf(file_path, "%s%s%s.txt", trace_path.c_str(), kernel_name.c_str(), "kernel");
  std::ofstream kernel_file(file_path);
  module->writeIR(kernel_file);
  //////////////////////////////////////


  // write config file in text format : no of threads
  // thread no and start instruction for each thread
  sprintf(file_path, "%s%s%s.txt", trace_path.c_str(), kernel_name.c_str(), trace_name.c_str());
  txt_config_file.open(file_path);

  if (txt_config_file.fail())
    assert(0);

  txt_config_file << "newptx\n";
  txt_config_file << TRACEGEN_VER << "\n";
  txt_config_file << max_block << "\n";
  txt_config_file << num_total_warps << "\n";

  sprintf(file_path, "%s%s%s_info.txt", trace_path.c_str(), kernel_name.c_str(), trace_name.c_str());
  info_file.open(file_path);

  if (thread_info != NULL) {
    delete[] thread_info;
    delete[] trace_info;
    delete[] skip_inst;
  }

  thread_info = new Thread_info[num_total_warps];
  trace_info  = new Trace_info [num_total_warps];
  skip_inst   = new bool[num_total_warps];

  memset(thread_info, 0, num_total_warps * sizeof(Thread_info));
  memset(trace_info, 0, num_total_warps * sizeof(Trace_info));
  memset(skip_inst, 0, num_total_warps * sizeof(bool));

  init = true;
}


///////////////////////////////////////////////////////////////////////////////////////////////
/// Called whenever an event takes place.
/// Note, the const reference 'event' is only valid until event() returns
///////////////////////////////////////////////////////////////////////////////////////////////
void trace::X86TraceGenerator::event(const trace::TraceEvent & event)
{
  ++total_inst_count;
  if (total_inst_count % 1000000 == 0)
    report(">>>>> inst_count:" << total_inst_count);
  // current block id
  int cur_block = event.blockId.y * gridDimX + event.blockId.x;


  ////////////////////////////////////////////////////////////
  if (!tracegen) {

    if (last_block_id != cur_block) {
      if (last_block_id != -1) {
        int block_id = last_block_id;
        // process each warps in previous block
        for (int ii = 0; ii < num_warps_per_block; ++ii) {
          // write remaining inst info
          Trace_info *tr_info = &trace_info[block_id * num_warps_per_block + ii];

          // record warp information
          Thread_info *th_info = &thread_info[block_id * num_warps_per_block + ii];

          txt_config_file << th_info->thread_id << " " << th_info->inst_count << "\n";
          info_file << th_info->thread_id << " " << tr_info->inst_count << "\n";
        }
      }
      last_block_id = cur_block;


      // setup data structure for a new block
      for (int ii = 0; ii < num_warps_per_block; ++ii) {
        Thread_info *th_info = &thread_info[cur_block * num_warps_per_block + ii];

        /* id assigned to each warp/block - shift block_id left by 16 and add the running thread count */
        int thread_id = (cur_block << 16) + ii;
        th_info->thread_id = thread_id;

      }
    }

    int cur_warp;
    boost::dynamic_bitset<>::size_type pos;
    int warp_set_bit_count;
    Trace_info *info;

    cur_warp = 0;
    pos = event.active.find_first();

    do {
      warp_set_bit_count = 0;

      // for current warp check if any thread was active
      // if threads were active collect active mask, memory addresses accessed (if any) and branch taken mask (if applicable)
      // if all threads were inactive check the next warp for active threads
      while (pos != boost::dynamic_bitset<>::npos && pos < (unsigned int)((cur_warp + 1) * WARP_SIZE)) {
        warp_set_bit_count++;
        pos = event.active.find_next(pos);
      }

      if (warp_set_bit_count) {
        info = &trace_info[cur_block * num_warps_per_block + cur_warp];
        info->inst_count++;
        ++kernel_inst_count;
      }
      cur_warp++;

    } while (pos != boost::dynamic_bitset<>::npos);

    return;
  }
  ////////////////////////////////////////////////////////////


  ///
  /// Since each block is executed in sequential, we open gzFile for current block and
  /// close when it has been terminate. However, since we don't know when exactly a block
  /// terminates, we maintain last_block_id and compare with current block id.
  /// When ids do not match, a new block has been started.
  ///
  // open files on demand
  if (last_block_id != cur_block) {
    if (last_block_id != -1) {
      int block_id = last_block_id;
      // process each warps in previous block
      for (int ii = 0; ii < num_warps_per_block; ++ii) {
        // write remaining inst info
        Trace_info *tr_info = &trace_info[block_id * num_warps_per_block + ii];
        if (tr_info->bytes_accumulated) {
          int bytes_written = gzwrite(tr_info->trace_stream, tr_info->trace_buf, tr_info->bytes_accumulated); 
          if (bytes_written != tr_info->bytes_accumulated) {
            report("gz file write error");
            assert(0);
          }
        }
        gzclose(tr_info->trace_stream);

        // record warp information
        Thread_info *th_info = &thread_info[block_id * num_warps_per_block + ii];
        if (sizeof(Thread_info) != gzwrite(gz_config_file, th_info, sizeof(Thread_info))) {
          report("unable to write to config file");
          exit(-1);
        }

        txt_config_file << th_info->thread_id << " " << th_info->inst_count << "\n";
        info_file << th_info->thread_id << " " << tr_info->inst_count << "\n";
      }
    }

    last_block_id = cur_block;


    // setup data structure for a new block
    for (int ii = 0; ii < num_warps_per_block; ++ii) {
      Thread_info *th_info = &thread_info[cur_block * num_warps_per_block + ii];
      Trace_info *tr_info  = &trace_info[cur_block * num_warps_per_block + ii];

      /* id assigned to each warp/block - shift block_id left by 16 and add the running thread count */
      int thread_id = (cur_block << 16) + ii;
      th_info->thread_id = thread_id;

      /* open trace file for each warp/thread */
      sprintf(tr_info->trace_name, "%s%s%s_%u.%s", 
          trace_path.c_str(), kernel_name.c_str(), trace_name.c_str(), th_info->thread_id, extension.c_str());

      tr_info->trace_stream = gzopen(tr_info->trace_name, "wb");
      if (tr_info->trace_stream == NULL) {
        report("unable to open file " << tr_info->trace_name);
        dbg << "unable to open file " << tr_info->trace_name
          << ", errorno is " << errno 
          << " message is " << strerror(errno) << "\n";
        assert(0);
      }
    }
  }


#if WRITE_DEBUG == 1
#if SINGLE_WARP == 1
  static int saved_cur_block = -1;
  static int saved_cur_warp = -1;

  if (saved_cur_block == -1) {
    saved_cur_block = cur_block;
  }
#endif
#endif



  /////////////////////////////////////////////////////////////////////////////////////////////
  // process current instruction
  /////////////////////////////////////////////////////////////////////////////////////////////

  const ir::PTXInstruction *ptx_inst = event.instruction;


  // Membar : memory barrier
  // Pmevent : performance monitor event
  // Currently, not supported
  if (ptx_inst->opcode == ir::PTXInstruction::Membar || 
      ptx_inst->opcode == ir::PTXInstruction::Pmevent) {
    report("opcode " << ir::PTXInstruction::toString(ptx_inst->opcode) << " seen");
    assert(0);
  }


  ///
  /// We maintain instruction hash per static instruction(key : PC address).
  /// By storing this information, we can reduce parsing (decoding) overhead
  ///

  // search current instruction in the instruction hash
  bool inst_found = false;
  Inst_info *inst_info;
  if (inst_storage.find(event.PC) != inst_storage.end()) {
    inst_info = inst_storage[event.PC];
    inst_found = true;
  }
  else {
    // add a new static instruction
    inst_info = new Inst_info;
    if (NULL == inst_info) {
      report("failed to allocated memory");
      exit(-1);
    }
    memset(inst_info, 0, sizeof(Inst_info));
    inst_storage.insert(pair<ir::PTXU64, Inst_info *>(event.PC, inst_info));
  }


  // seeing first instance of PC
  if (false == inst_found) {
    uint32_t src_count;
    uint32_t dest_count;

    // set sources and destinations

    /* source 1 */
    src_count = 0;
    if (ptx_inst->a.addressMode == ir::PTXOperand::Register || 
        ptx_inst->a.addressMode == ir::PTXOperand::Indirect) { 
      /* scalar */
      if (ptx_inst->a.vec == ir::PTXOperand::v1) {
        assert(ptx_inst->a.reg < SPECIAL_REG_START);
        inst_info->src[src_count] = ptx_inst->a.reg;
        ++src_count;
      }
      /* vector2, vector 4 */
      else if (ptx_inst->a.vec == ir::PTXOperand::v2 || 
          ptx_inst->a.vec ==  ir::PTXOperand::v4) {
        for (unsigned int i = 0; i < ptx_inst->a.array.size(); ++i) {
          assert(ptx_inst->a.array[i].reg < SPECIAL_REG_START);
          inst_info->src[src_count] = ptx_inst->a.array[i].reg;
          ++src_count;
        }
      }
      else
        assert(0);
    }
    else if (ptx_inst->a.addressMode == ir::PTXOperand::Special) {
      inst_info->src[src_count] = SPECIAL_REG_START + ptx_inst->a.special;
      ++src_count;
    }

    /* source 2 */
    if (ptx_inst->b.addressMode == ir::PTXOperand::Register || 
        ptx_inst->b.addressMode == ir::PTXOperand::Indirect) { 
      if (ptx_inst->b.vec == ir::PTXOperand::v1) {
        assert(ptx_inst->b.reg < SPECIAL_REG_START);
        inst_info->src[src_count] = ptx_inst->b.reg;
        ++src_count;
      }
      else if (ptx_inst->b.vec == ir::PTXOperand::v2 || 
          ptx_inst->b.vec ==  ir::PTXOperand::v4) {
        for (unsigned int i = 0; i < ptx_inst->b.array.size(); ++i) {
          assert(ptx_inst->b.array[i].reg < SPECIAL_REG_START);
          inst_info->src[src_count] = ptx_inst->b.array[i].reg;
          ++src_count;
        }
      }
    }
    else if (ptx_inst->b.addressMode == ir::PTXOperand::Special) {
      inst_info->src[src_count] = SPECIAL_REG_START + ptx_inst->b.special;
      ++src_count;
    }

    /* source 3 */
    if (ptx_inst->c.addressMode == ir::PTXOperand::Register || 
        ptx_inst->c.addressMode == ir::PTXOperand::Indirect) { 
      if (ptx_inst->c.vec ==  ir::PTXOperand::v1) {
        assert(ptx_inst->c.reg < SPECIAL_REG_START);
        inst_info->src[src_count] = ptx_inst->c.reg;
        ++src_count;
      }
      else if (ptx_inst->c.vec ==  ir::PTXOperand::v2 || 
          ptx_inst->c.vec ==  ir::PTXOperand::v4) {
        for (unsigned int i = 0; i < ptx_inst->c.array.size(); ++i) {
          assert(ptx_inst->c.array[i].reg < SPECIAL_REG_START);
          inst_info->src[src_count] = ptx_inst->c.array[i].reg;
          ++src_count;
        }
      }
    }
    else if (ptx_inst->c.addressMode == ir::PTXOperand::Special) {
      inst_info->src[src_count] = SPECIAL_REG_START + ptx_inst->c.special;
      ++src_count;
    }


    // if predication variable is used, how do you specify that dependency? 
    // only predication registers will be used
    if (ptx_inst->pg.addressMode == ir::PTXOperand::Register && 
        ptx_inst->pg.type == ir::PTXOperand::pred && 
        ((ptx_inst->pg.condition == ir::PTXOperand::Pred) || 
         (ptx_inst->pg.condition == ir::PTXOperand::InvPred))) { 
      assert(ptx_inst->pg.reg < SPECIAL_REG_START);
      inst_info->src[src_count] = ptx_inst->pg.reg;
      ++src_count;
    }


    /* destination register */
    dest_count = 0;
    if (ptx_inst->d.addressMode == ir::PTXOperand::Register || 
        ptx_inst->d.addressMode == ir::PTXOperand::Indirect) {
      if (ptx_inst->opcode == ir::PTXInstruction::St) {
        // for stores, reg d is also a source (reg d contains the store address)
        assert(ptx_inst->d.vec == ir::PTXOperand::v1);
        assert(ptx_inst->d.reg < SPECIAL_REG_START);
        inst_info->src[src_count] = ptx_inst->d.reg;
        ++src_count;
      }
      else {
        if (ptx_inst->d.vec ==  ir::PTXOperand::v1) {
          assert(ptx_inst->d.reg < SPECIAL_REG_START);
          inst_info->dst[dest_count] = ptx_inst->d.reg;
          ++dest_count;
        }
        else if (ptx_inst->d.vec ==  ir::PTXOperand::v2 || 
            ptx_inst->d.vec ==  ir::PTXOperand::v4) {
          for (unsigned int i = 0; i < ptx_inst->d.array.size(); ++i) {
            assert(ptx_inst->d.array[i].reg < SPECIAL_REG_START);
            inst_info->dst[dest_count] = ptx_inst->d.array[i].reg;
            ++dest_count;
          }
        }
      }
    }

    /* second destination register for SetP */
    if (ptx_inst->pq.addressMode == ir::PTXOperand::Register || 
        ptx_inst->pq.addressMode == ir::PTXOperand::Indirect) {
      inst_info->dst[dest_count] = ptx_inst->pq.reg;
      ++dest_count;
    }

    inst_info->num_read_regs = src_count;
    inst_info->num_dest_regs = dest_count;

    assert(src_count <= MAX_SRC_NUM && dest_count <= MAX_DST_NUM);


    // set has_immediate flag - this flag is used to indicate that 
    // successive memory accesses found in the trace are from the 
    // same instruction (uncoaleced memory accesses)
#if TRACEGEN_VER == 10
    // not necessary, all fields initialized to 0 by memset
    inst_info->has_immediate = false;
#endif

    ///////////////////////////////////////////////////////////////////////////////////////////
    // Opcode parsing begin
    ///////////////////////////////////////////////////////////////////////////////////////////
    
    // load
    // TOCHECK (generic type not in ptx document)
    if (ptx_inst->opcode == ir::PTXInstruction::Ld ||
        ptx_inst->opcode == ir::PTXInstruction::Ldu) {
      switch (ptx_inst->addressSpace) {
        case ir::PTXInstruction::Const:
          inst_info->opcode = GPU_MEM_LD_CM;
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_CONST);
          break;

        case ir::PTXInstruction::Global:
        case ir::PTXInstruction::Generic:
          inst_info->opcode = GPU_MEM_LD_GM; 
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_GLOBAL);
          break;

        case ir::PTXInstruction::Local:
          inst_info->opcode = GPU_MEM_LD_LM; 
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_LOCAL);
          break;

        case ir::PTXInstruction::Param:
          inst_info->opcode = GPU_MEM_LD_PM; 
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_PARAM);
          break;

        case ir::PTXInstruction::Shared:
          inst_info->opcode = GPU_MEM_LD_SM; 
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_SHARED);
          break;

        case ir::PTXInstruction::Texture:
          report("texture load - tocheck");
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_TEXTURE);
          assert(0);
          break;

        default:
          assert(0);
      }

      switch (ptx_inst->cacheOperation) {
        case ir::PTXInstruction::Ca:
          SET_CACHE_OPERATOR(inst_info, GPU_CACHE_OP_CA);
          break;

        case ir::PTXInstruction::Cv:
          SET_CACHE_OPERATOR(inst_info, GPU_CACHE_OP_CV);
          break;

        case ir::PTXInstruction::Cg:
          SET_CACHE_OPERATOR(inst_info, GPU_CACHE_OP_CG);
          break;

        case ir::PTXInstruction::Cs:
          SET_CACHE_OPERATOR(inst_info, GPU_CACHE_OP_CS);
          break;

        default:
          assert(0);
      }
    }
    // FIXME : support LDU
    // load uniform
    else if (0 && ptx_inst->opcode == ir::PTXInstruction::Ldu) {
      report("LDU currently not supported");
      assert(0);
      switch (ptx_inst->addressSpace) {
        case ir::PTXInstruction::Global:
          inst_info->opcode = GPU_MEM_LDU_GM;
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_GLOBAL);
          break;

        default:
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_INVALID);
          assert(0);
      }
    }
    // store 
    else if (ptx_inst->opcode == ir::PTXInstruction::St) {
      switch (ptx_inst->addressSpace) {
        case ir::PTXInstruction::Global:
        case ir::PTXInstruction::Generic:
          inst_info->opcode = GPU_MEM_ST_GM;
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_GLOBAL);
          break;

        case ir::PTXInstruction::Local:
          inst_info->opcode = GPU_MEM_ST_LM;
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_LOCAL);
          break;

        case ir::PTXInstruction::Shared:
          inst_info->opcode = GPU_MEM_ST_SM;
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_SHARED);
          break;

        default:
          assert(0);
      }

      switch (ptx_inst->cacheOperation) {
        case ir::PTXInstruction::Wb:
          SET_CACHE_OPERATOR(inst_info, GPU_CACHE_OP_WB);
          break;

        case ir::PTXInstruction::Wt:
          SET_CACHE_OPERATOR(inst_info, GPU_CACHE_OP_WT);
          break;

        default:
          assert(0);
      }
    }
    // prefetch instruction
    // TODO (jaekyu, 8-5-2010)
    else if (ptx_inst->opcode == ir::PTXInstruction::Prefetch) {
      report("PREF currently not supported");
      SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_INVALID); //check this macro!
      SET_CACHE_LEVEL(inst_info, GPU_CACHE_INVALID); //check this macro!
      // cache operators dont have to be set,
      // according to ptx 3.1 document they are only for loads and stores!
      assert(0);
      /*
      switch (ptx_inst->addressSpace) {
        case ir::PTXInstruction::Global:
          inst_info->opcode = PREF_GM_L1;
          break;

        case ir::PTXInstruction::Local:
          inst_info->opcode = PREF_LM_L1;
          break;

        default:
          assert(0);
      }
      */
    }
    // prefetch uniform instruction
    // TODO (jaekyu, 8-5-2010)
    else if (ptx_inst->opcode == ir::PTXInstruction::Prefetchu) {
      report("PREF_UNIFORM currently not supported");
      SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_INVALID); //check this macro!
      SET_CACHE_LEVEL(inst_info, GPU_CACHE_INVALID); //check this macro!
      // cache operators dont have to be set,
      // according to ptx 3.1 document they are only for loads and stores!
      assert(0);
      /*
      inst_info->opcode = PREF_UNIFORM;
      */
    }
    // texture memory
    else if (TEX_INST(ptx_inst->opcode)) {
      inst_info->opcode = GPU_MEM_LD_TM;
      SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_TEXTURE);
    }
    // surface memory access
    // TODO (jaekyu, 8-5-2010)
    else if (SUR_INST(ptx_inst->opcode)) {
      report("Surface memory is not supported. 8-3-2010 Jaekyu Lee");
      SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_INVALID); // is this required?
      assert(0);
    }
    // Atomic & Reduction
    // .global, .shared
    else if (ptx_inst->opcode == ir::PTXInstruction::Atom) {
      switch (ptx_inst->addressSpace) {
        case ir::PTXInstruction::Global:
          if (ptx_inst->type == ir::PTXOperand::s64 ||
              ptx_inst->type == ir::PTXOperand::u64 ||
              ptx_inst->type == ir::PTXOperand::b64) {
            inst_info->opcode = GPU_ATOM64_GM;
          }
          else {
            inst_info->opcode = GPU_ATOM_GM;
          }
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_GLOBAL);
          break;

        case ir::PTXInstruction::Shared:
          if (ptx_inst->type == ir::PTXOperand::s64 ||
              ptx_inst->type == ir::PTXOperand::u64 ||
              ptx_inst->type == ir::PTXOperand::b64) {
            inst_info->opcode = GPU_ATOM64_SM;
          }
          else {
            inst_info->opcode = GPU_ATOM_SM;
          }
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_SHARED);
          break;

        default :
          assert(0);
          break;
      }
    }
    else if (ptx_inst->opcode == ir::PTXInstruction::Red) {
      switch (ptx_inst->addressSpace) {
        case ir::PTXInstruction::Global:
          if (ptx_inst->type == ir::PTXOperand::s64 ||
              ptx_inst->type == ir::PTXOperand::u64 ||
              ptx_inst->type == ir::PTXOperand::b64) {
            inst_info->opcode = GPU_RED64_GM;
          }
          else {
            inst_info->opcode = GPU_RED_GM;
          }
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_GLOBAL);
          break;

        case ir::PTXInstruction::Shared:
          if (ptx_inst->type == ir::PTXOperand::s64 ||
              ptx_inst->type == ir::PTXOperand::u64 ||
              ptx_inst->type == ir::PTXOperand::b64) {
            inst_info->opcode = GPU_RED64_SM;
          }
          else {
            inst_info->opcode = GPU_RED_SM;
          }
          SET_ADDR_SPACE(inst_info, GPU_ADDR_SP_SHARED);
          break;

        default :
          assert(0);
          break;
      }
    }
    else if (ptx_inst->opcode == ir::PTXInstruction::Membar) {
      switch(ptx_inst->level) {
        case ir::PTXInstruction::CtaLevel:
          inst_info->opcode = GPU_MEMBAR_CTA;
          SET_FENCE_LEVEL(inst_info, GPU_FENCE_CTA);
          break;

        case ir::PTXInstruction::GlobalLevel:
          inst_info->opcode = GPU_MEMBAR_GL;
          SET_FENCE_LEVEL(inst_info, GPU_FENCE_GL);
          break;

        default :
          assert(0);
          break;
      }
    }
    else if (ptx_inst->opcode == ir::PTXInstruction::Bar) {
      switch(ptx_inst->barrierOperation) {
        case ir::PTXInstruction::BarSync:
          inst_info->opcode = GPU_BAR_SYNC;
          break;

        case ir::PTXInstruction::BarArrive:
          inst_info->opcode = GPU_BAR_ARRIVE;
          break;

        case ir::PTXInstruction::BarReduction:
          inst_info->opcode = GPU_BAR_RED;
          break;

        default :
          assert(0);
          break;
      }
    }
    // other instructions
    else {
      // double
      if (ptx_inst->type == ir::PTXOperand::f64) {
        inst_info->opcode = opcode_translator[ptx_inst->opcode][3];
        inst_info->is_fp = true;
      }
      // floating point
      else if (ptx_inst->type == ir::PTXOperand::f16 || 
          ptx_inst->type == ir::PTXOperand::f32) {
        inst_info->opcode = opcode_translator[ptx_inst->opcode][2];
        inst_info->is_fp = true;
      }
      // integer - 64-bit
      else if (ptx_inst->type == ir::PTXOperand::s64 ||
          ptx_inst->type == ir::PTXOperand::u64 ||
          ptx_inst->type == ir::PTXOperand::b64) {
        inst_info->opcode = opcode_translator[ptx_inst->opcode][1];
        inst_info->is_fp = false;
      }
      // integer
      else {
        inst_info->opcode = opcode_translator[ptx_inst->opcode][0];
        inst_info->is_fp = false;
      }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////
    // Opcode parsing done
    ///////////////////////////////////////////////////////////////////////////////////////////

    if (inst_info->opcode == GPU_INVALID) {
      report("invalid opcode for " << ptx_inst->opcode);
      cout << "ptx inst is " << ir::PTXInstruction::toString(ptx_inst->opcode) << " inst type is " << ptx_inst->type << "\n";
      assert(0);
    }

    // set cf_type
    switch (ptx_inst->opcode) {
      case ir::PTXInstruction::Bra:
        inst_info->cf_type = CF_CBR;
        break;

      case ir::PTXInstruction::Call:
        inst_info->cf_type = CF_CALL;
        break;

      case ir::PTXInstruction::Exit:
        inst_info->cf_type = CF_SYS;
        break;

      case ir::PTXInstruction::Ret:
        inst_info->cf_type = CF_RET;
        break;

      default:
        inst_info->cf_type = NOT_CF;
        break;
    }

    // set has_st flag
    SET_STORE_FLAG(inst_info, ptx_inst->opcode);

    // set write_flg flag - this flag is not used by macsim, so setting it to false
    // not necessary, all fields are initialized to zero by default
    //inst_info->write_flg = false;

    // set num_ld
    if (ptx_inst->opcode == ir::PTXInstruction::Ld || 
        ptx_inst->opcode == ir::PTXInstruction::Ldu ||
        ptx_inst->opcode == ir::PTXInstruction::Prefetch ||
        ptx_inst->opcode == ir::PTXInstruction::Prefetchu ||
        ptx_inst->opcode == ir::PTXInstruction::Atom ||
        ptx_inst->opcode == ir::PTXInstruction::Red ||
        TEX_INST(ptx_inst->opcode)) {
      SET_LOAD_FLAG(inst_info, 1);
    }
    else {
      // not necessary
      SET_LOAD_FLAG(inst_info, 0);
    }

    /* set instruction size */
    inst_info->size = 4;
  } // A newly seen instruction has been decoded
      
  ++opcode_stats[inst_info->opcode];


  /////////////////////////////////////////////////////////////////////////////////////////////
  // current instruction has been decoded at this point
  /////////////////////////////////////////////////////////////////////////////////////////////
  int cur_warp;
  boost::dynamic_bitset<>::size_type pos;
  int warp_set_bit_count;
  bool branch_taken;
  Trace_info *info;
  unsigned int warp_active_mask;
  unsigned int branch_taken_mask;
  unsigned int mem_count;
  int mem_size;

  cur_warp = 0;
  pos = event.active.find_first();
  warp_set_bit_count = 0;
  memset(mem_access, 0, sizeof(MemAccess) * WARP_SIZE);


  // flag to indicate whether inst. is a control flow inst. or not 
  bool branch_inst = BRANCH_INST(ptx_inst->opcode);

  // flag to indicate whether inst. accesses memory or not 
  bool mem_inst = IS_MEM_INST(inst_info, ptx_inst);

  if (mem_inst && event.memory_addresses.size() == 0) {
    report("ERROR: No memory addresses found opcode:" << ir::PTXInstruction::toString(ptx_inst->opcode));
    assert(0);
  }


  // assumption : there are no mem-to-mem operations (atom, red may be mem-to-mem operations 
  // but the memory address list has only one address value for these instructions - expl better
  mem_count = 0;
  do {
    warp_set_bit_count = 0;
    branch_taken       = false;
    warp_active_mask   = 0;
    branch_taken_mask  = 0;
    mem_size           = 0;

    // for current warp check if any thread was active
    // if threads were active collect active mask, memory addresses accessed (if any) and branch taken mask (if applicable)
    // if all threads were inactive check the next warp for active threads
    while (pos != boost::dynamic_bitset<>::npos && pos < (unsigned int)((cur_warp + 1) * WARP_SIZE)) {
      if (mem_inst) {
        if (mem_count >= event.memory_addresses.size()) {
          cout << "mem_count:" << mem_count << " " << event.memory_addresses.size() << "\n";
          cerr << "opcode " << ir::PTXInstruction::toString(ptx_inst->opcode) << "\n";
          assert(mem_count < event.memory_addresses.size());
        }
        mem_access[pos % WARP_SIZE].mem_addr = event.memory_addresses[mem_count] + INST_LAST_ADDR;
        mem_access[pos % WARP_SIZE].mem_size = event.memory_size;
        if (!mem_size && event.memory_size) {
          mem_size = event.memory_size;
        }
        mem_count++;
      }
      else if (branch_inst) {
        if (pos < event.taken.size() && event.taken.test(pos)) {
          branch_taken_mask |= (1 << (pos % WARP_SIZE));
        }

        if (!branch_taken) {
          // check only for bra instruction, what about other instructions? 
          // always taken - but what if they are predicated???
          if (ptx_inst->opcode == ir::PTXInstruction::Bra) { 
            if (event.taken.test(pos)) {
              branch_taken = true;
            }
          }
          else {
            branch_taken = true;
          }
        }
      }

      warp_active_mask |= (1 << (pos % WARP_SIZE));
      warp_set_bit_count++;
      pos = event.active.find_next(pos);
    }

    bool skip = skip_inst[cur_block * num_warps_per_block + cur_warp];
    if (!warp_set_bit_count) {
      if (!skip && !branch_inst) {
        skip = true;
        skip_inst[cur_block * num_warps_per_block + cur_warp] = true;
        // branch after setp which clears all bits for warp should be executed!
        // any other instruction with no active threads is skipped!
      }
    }
    else {
      skip = false;
      skip_inst[cur_block * num_warps_per_block + cur_warp] = false;
    }


    // if current warp had active threads then generate trace for the executed instruction
    if (!skip || warp_set_bit_count) {
      ++kernel_inst_count;

      //warp_active_mask = ~warp_active_mask;
      //branch_taken_mask = ~branch_taken_mask;

      // store active thread mask in ld_vaddr2 */
      SET_ACTIVE_MASK(inst_info, warp_active_mask);

      // ocelot generates PC index instead of PC address, since we are assuming 
      // that instruction size is 8 bytes, left-shift PC index by 3
      inst_info->inst_addr = (event.PC << 3) + INST_START_ADDR;

      if ((inst_info->inst_addr + 7) > INST_LAST_ADDR) {
        report("[assert] inst_info->inst_addr + 7 > INST_LAST_ADDR");
        report("pc:" << hex << event.PC << " " << inst_info->inst_addr);
        report("start:" << hex << INST_START_ADDR << " " << INST_LAST_ADDR);
        assert((inst_info->inst_addr + 7) <= INST_LAST_ADDR);
      }

      RESET_OTHER_FIELDS(inst_info);
      /*
      inst_info->branch_target = 0; 
      inst_info->actually_taken = 0; 
      inst_info->st_vaddr = inst_info->mem_write_size = 0;
      inst_info->ld_vaddr1 = inst_info->mem_read_size = 0;
      inst_info->rep_dir = 0;
      */


      // for instructions that access memory coalesce requests into fewer, 
      // larger contiguous chunks of requests if possible MACSIM will then 
      // break these larger requests into cache block size requests
      if (mem_inst) {

        // generate instructions
        for (int i = 0; i < WARP_SIZE; ++i) {
          /* MACSIM uses only 8-bit fields for memory address sizes */
          if (mem_access[i].mem_size >= 256) { cerr << "adjusting mem size to 255 from " << mem_access[i].mem_size << "\n"; mem_access[i].mem_size = 255; }

          assert(mem_access[i].mem_size < 256);

#ifndef USE_32BIT_ADDR
          uint64_t addr = (mem_access[i].mem_addr & mem_addr_flag);
#else
          uint32_t addr = (mem_access[i].mem_addr & mem_addr_flag);
#endif
          if (ptx_inst->opcode == ir::PTXInstruction::Ld || 
              ptx_inst->opcode == ir::PTXInstruction::Mov || 
              ptx_inst->opcode == ir::PTXInstruction::Ldu ||
              ptx_inst->opcode == ir::PTXInstruction::Prefetch ||
              ptx_inst->opcode == ir::PTXInstruction::Prefetchu ||
              inst_info->opcode == GPU_MEM_LD_TM ||
              ptx_inst->opcode == ir::PTXInstruction::Atom || 
              ptx_inst->opcode == ir::PTXInstruction::Red) {
            SET_LD_ADDR_AND_SIZE(inst_info, addr, mem_size);
          }


          if (ptx_inst->opcode == ir::PTXInstruction::St || 
              ptx_inst->opcode == ir::PTXInstruction::Atom ||
              ptx_inst->opcode == ir::PTXInstruction::Red) {
            SET_ST_ADDR_AND_SIZE(inst_info, addr, mem_size);
          }

#if WRITE_DEBUG == 1
#if SINGLE_WARP == 1
          if (saved_cur_warp == -1) {
            saved_cur_warp = cur_warp;
          }


          if (saved_cur_block == cur_block && saved_cur_warp == cur_warp) {
#endif
            *debug_stream << ptx_inst->toString() << "\n";
            *debug_stream << "opcode " << ir::PTXInstruction::toString(ptx_inst->opcode) 
              << " a " << ptx_inst->a.identifier << " b " << ptx_inst->b.identifier 
              << " c " << ptx_inst->c.identifier << " d " << ptx_inst->d.identifier << "\n";
            writeInstToFile(*debug_stream, inst_info);
#if 0
          }
#endif
#if SINGLE_WARP == 1
        }
#endif
#endif
        assert((cur_block * num_warps_per_block + cur_warp) < num_total_warps);

        info = &trace_info[cur_block * num_warps_per_block + cur_warp];

        if ((i == 0) || i == (WARP_SIZE - 1)) {
          // macsim does not use this field, so using it to indicate
          // whether instruction is first/last instruction in the 
          // sequence of instructions generated for an uncoalesced 
          // instruction
          SET_MUL_TRACE_OP_FLAG(inst_info);
        }
        else {
          //macsim does not use this field, so using it to indicate
          //whether instruction is first/last instruction in the 
          //sequence of instructions generated for an uncoalesced 
          //instruction
          RESET_MUL_TRACE_OP_FLAG(inst_info);
        }

        if (i == 0) {
          memcpy(info->trace_buf + info->bytes_accumulated, inst_info, sizeof(Inst_info));
          info->bytes_accumulated += sizeof(Inst_info);
          memset(addr_buffer, 0, WARP_SIZE * ADDR_SIZE);
        }
        else {
          int num_addr = sizeof(Inst_info) / ADDR_SIZE;
          memcpy(addr_buffer + ((i - 1) % num_addr) * ADDR_SIZE, &addr, ADDR_SIZE);
          //std::cout << "copied " << i << " addr " << addr << " to addr buffer, at position " << ((i - 1) % num_addr) << "\n";
          if (!(i % num_addr) || (i == WARP_SIZE - 1)) {
            memcpy(info->trace_buf + info->bytes_accumulated, addr_buffer, sizeof(Inst_info));
            //std::cout << "copied " << i << " to addr inst info buffer\n";
            for (unsigned int j = 0; j < sizeof(Inst_info); ++j) {
              //std::cout << (int)addr_buffer[j] << " ";
            }
            //std::cout << "\n";
            info->bytes_accumulated += sizeof(Inst_info);
          }

        }
        if (info->bytes_accumulated == BUF_SIZE) {
          int bytes_written;
          bytes_written = gzwrite(info->trace_stream, info->trace_buf, BUF_SIZE);
          if (bytes_written != BUF_SIZE) {
            std::cerr << "unable to write to trace file, thread " << (cur_block * num_warps_per_block + cur_warp) 
              << " bytes written = " <<  bytes_written << "\n";
            int err;
            std::cerr << "1. error is " << gzerror(info->trace_stream, &err) << "\n";
            if (err != Z_ERRNO) {
              std::cerr << "error code is " << err << "\n";
            }
            else {
              std::cerr << "error is " << strerror(errno) << "\n";
            }

            exit(-1);
          }

          info->bytes_accumulated = 0;
        }
        info->inst_count++;
      }
      memset(mem_access, 0, sizeof(MemAccess) * WARP_SIZE);
    }
    else if (branch_inst) {
      if (ptx_inst->opcode == ir::PTXInstruction::Bra || 
          ptx_inst->opcode == ir::PTXInstruction::Call ||
          ptx_inst->opcode == ir::PTXInstruction::Ret) {
        SET_BRANCH_TARGET(inst_info, ((ptx_inst->branchTargetInstruction << 3) + INST_START_ADDR));

        SET_BRANCH_TAKEN_MASK(inst_info, branch_taken_mask);
        SET_RECONV_ADDR(inst_info, ((ptx_inst->reconvergeInstruction << 3) + INST_START_ADDR));
      }
      SET_BRANCH_TAKEN_FLAG(inst_info, branch_taken);


#if WRITE_DEBUG == 1
#if SINGLE_WARP == 1
      if (saved_cur_warp == -1) {
        saved_cur_warp = cur_warp;
      }


      if (saved_cur_block == cur_block && saved_cur_warp == cur_warp) {
#endif
        *debug_stream << ptx_inst->toString() << "\n";
        *debug_stream << "opcode " << ir::PTXInstruction::toString(ptx_inst->opcode) 
          << " a " << ptx_inst->a.identifier << " b " << ptx_inst->b.identifier 
          << " c " << ptx_inst->c.identifier << " d " << ptx_inst->d.identifier << "\n";
        writeInstToFile(*debug_stream, inst_info);
#if SINGLE_WARP == 1
      }
#endif
#endif
      assert((cur_block * num_warps_per_block + cur_warp) < num_total_warps);
      info = &trace_info[cur_block * num_warps_per_block + cur_warp];
      memcpy(info->trace_buf + info->bytes_accumulated, inst_info, sizeof(Inst_info));

      info->bytes_accumulated += sizeof(Inst_info);
      if (info->bytes_accumulated == BUF_SIZE) {
        int bytes_written;
        bytes_written = gzwrite(info->trace_stream, info->trace_buf, BUF_SIZE);
        if (bytes_written != BUF_SIZE) {
          std::cerr << "unable to write to trace file, thread " << (cur_block * num_warps_per_block + cur_warp) 
            << " bytes written = " <<  bytes_written << "\n";
          int err;
          std::cerr << "2. error is " << gzerror(info->trace_stream, &err) << "\n";
          if (err != Z_ERRNO) {
            std::cerr << "error code is " << err << "\n";
          }
          else {
            std::cerr << "error is " << strerror(errno) << "\n";
          }

          exit(-1);
        }

        info->bytes_accumulated = 0;
      }
      info->inst_count++;
    }
    else {
#if WRITE_DEBUG == 1
#if SINGLE_WARP == 1
      if (saved_cur_warp == -1) {
        saved_cur_warp = cur_warp;
      }


      if (saved_cur_block == cur_block && saved_cur_warp == cur_warp) {
#endif
        *debug_stream << ptx_inst->toString() << "\n";
        *debug_stream << "opcode " << ir::PTXInstruction::toString(ptx_inst->opcode) 
          << " a " << ptx_inst->a.identifier << " b " << ptx_inst->b.identifier 
          << " c " << ptx_inst->c.identifier << " d " << ptx_inst->d.identifier << "\n";
        writeInstToFile(*debug_stream, inst_info);
#if SINGLE_WARP == 1
      }
#endif
#endif


      assert((cur_block * num_warps_per_block + cur_warp) < num_total_warps);

      info = &trace_info[cur_block * num_warps_per_block + cur_warp];
      memcpy(info->trace_buf + info->bytes_accumulated, inst_info, sizeof(Inst_info));

      info->bytes_accumulated += sizeof(Inst_info);
      if (info->bytes_accumulated == BUF_SIZE) {
        int bytes_written;
        bytes_written = gzwrite(info->trace_stream, info->trace_buf, BUF_SIZE);
        if (bytes_written != BUF_SIZE) {
          std::cerr 
            << "unable to write to trace file, thread " << (cur_block * num_warps_per_block + cur_warp) 
            << " block " << cur_block
            << " bytes written = " <<  bytes_written  
            << " file_name:" << info->trace_name << "\n";
          int err;
          std::cerr << "3. error is " << gzerror(info->trace_stream, &err) << "\n";
          if (err != Z_ERRNO) {
            std::cerr << "error code is " << err << "\n";
          }
          else {
            std::cerr << "error is " << strerror(errno) << "\n";
          }

          exit(-1);
        }

        info->bytes_accumulated = 0;
      }
      info->inst_count++;
    }
  }
  cur_warp++;

} while (pos != boost::dynamic_bitset<>::npos);
}


///////////////////////////////////////////////////////////////////////////////////////////////
// finalize
///////////////////////////////////////////////////////////////////////////////////////////////
void trace::X86TraceGenerator::finalize()
{
  report("finalize");
  if (!init)
    return ;

  report("total instruction count: " << total_inst_count);


  int block_id = last_block_id;
  for (int ii = 0; ii < num_warps_per_block; ++ii) {
    Trace_info *tr_info = &trace_info[block_id * num_warps_per_block + ii];
    if (tracegen) {
      if (tr_info->bytes_accumulated) {
        int bytes_written = gzwrite(tr_info->trace_stream, tr_info->trace_buf, tr_info->bytes_accumulated); 
        if (bytes_written != tr_info->bytes_accumulated) {
          std::cerr << "gz file write error\n";
          assert(0);
        }
      }
      gzclose(tr_info->trace_stream);
    }

    Thread_info *th_info = &thread_info[block_id * num_warps_per_block + ii];
    if (tracegen && sizeof(Thread_info) != gzwrite(gz_config_file, th_info, sizeof(Thread_info))) {
      std::cerr << "unable to write to config file\n";
      exit(-1);
    }

    txt_config_file << th_info->thread_id << " " << th_info->inst_count << "\n";
    info_file << th_info->thread_id << " " << tr_info->inst_count << "\n";
  }


  // close config and info files
  gzclose(gz_config_file);
  txt_config_file.close();

  info_file << "kernel_count " << kernel_inst_count << "\n";
  info_file.close();

}


///////////////////////////////////////////////////////////////////////////////////////////////
// for debug purpose, write instruction info in a file (text format)
///////////////////////////////////////////////////////////////////////////////////////////////
void trace::X86TraceGenerator::writeInstToFile(ofstream &file, Inst_info *inst_info)
{
  file << "*** begin of the data strcture *** " <<endl;

  WRITE_INST_TO_FILE(file, inst_info);

  file << "*** end of the data strcture *** " << endl << endl;
}



void trace::X86TraceGenerator::dump_opcode_stats(void)
{
  const char* tr_opcode_names[GPU_OPCODE_LAST] = {
    "GPU_INVALID",
    "GPU_ABS",
    "GPU_ABS64",
    "GPU_ADD", 
    "GPU_ADD64", 
    "GPU_ADDC",
    "GPU_AND",
    "GPU_AND64",
    "GPU_ATOM_GM",
    "GPU_ATOM_SM",
    "GPU_ATOM64_GM",
    "GPU_ATOM64_SM",
    "GPU_BAR_ARRIVE",
    "GPU_BAR_SYNC",
    "GPU_BAR_RED",
    "GPU_BFE",
    "GPU_BFE64",
    "GPU_BFI",
    "GPU_BFI64",
    "GPU_BFIND",
    "GPU_BFIND64",
    "GPU_BRA",
    "GPU_BREV",
    "GPU_BREV64",
    "GPU_BRKPT",
    "GPU_CALL",
    "GPU_CLZ",
    "GPU_CLZ64",
    "GPU_CNOT",
    "GPU_CNOT64",
    "GPU_COPYSIGN",
    "GPU_COPYSIGN64",
    "GPU_COS",
    "GPU_CVT",
    "GPU_CVT64",
    "GPU_CVTA",
    "GPU_CVTA64",
    "GPU_DIV",
    "GPU_DIV64",
    "GPU_EX2",
    "GPU_EXIT",
    "GPU_FMA",
    "GPU_FMA64",
    "GPU_ISSPACEP",
    "GPU_LD",
    "GPU_LD64",
    "GPU_LDU",
    "GPU_LDU64",
    "GPU_LG2",
    "GPU_MAD24",
    "GPU_MAD",
    "GPU_MAD64",
    "GPU_MAX",
    "GPU_MAX64",
    "GPU_MEMBAR_CTA",
    "GPU_MEMBAR_GL",
    "GPU_MEMBAR_SYS",
    "GPU_MIN",
    "GPU_MIN64",
    "GPU_MOV",
    "GPU_MOV64",
    "GPU_MUL24",
    "GPU_MUL",
    "GPU_MUL64",
    "GPU_NEG",
    "GPU_NEG64",
    "GPU_NOT",
    "GPU_NOT64",
    "GPU_OR",
    "GPU_OR64",
    "GPU_PMEVENT",
    "GPU_POPC",
    "GPU_POPC64",
    "GPU_PREFETCH",
    "GPU_PREFETCHU",
    "GPU_PRMT",
    "GPU_RCP",
    "GPU_RCP64",
    "GPU_RED_GM",
    "GPU_RED_SM",
    "GPU_RED64_GM",
    "GPU_RED64_SM",
    "GPU_REM",
    "GPU_REM64",
    "GPU_RET",
    "GPU_RSQRT",
    "GPU_RSQRT64",
    "GPU_SAD",
    "GPU_SAD64",
    "GPU_SELP",
    "GPU_SELP64",
    "GPU_SET",
    "GPU_SET64",
    "GPU_SETP",
    "GPU_SETP64",
    "GPU_SHL",
    "GPU_SHL64",
    "GPU_SHR",
    "GPU_SHR64",
    "GPU_SIN",
    "GPU_SLCT",
    "GPU_SLCT64",
    "GPU_SQRT",
    "GPU_SQRT64",
    "GPU_ST",
    "GPU_ST64",
    "GPU_SUB",
    "GPU_SUB64",
    "GPU_SUBC",
    "GPU_SULD",
    "GPU_SULD64",
    "GPU_SURED",
    "GPU_SURED64",
    "GPU_SUST",
    "GPU_SUST64",
    "GPU_SUQ",
    "GPU_TESTP",
    "GPU_TESTP64",
    "GPU_TEX",
    "GPU_TLD4",
    "GPU_TXQ",
    "GPU_TRAP",
    "GPU_VABSDIFF",
    "GPU_VADD",
    "GPU_VMAD",
    "GPU_VMAX",
    "GPU_VMIN",
    "GPU_VSET",
    "GPU_VSHL",
    "GPU_VSHR",
    "GPU_VSUB",
    "GPU_VOTE",
    "GPU_XOR",
    "GPU_XOR64",
    "GPU_RECONVERGE",
    "GPU_PHI",
    "GPU_MEM_LD_GM",
    "GPU_MEM_LD_LM",
    "GPU_MEM_LD_SM",
    "GPU_MEM_LD_CM",
    "GPU_MEM_LD_TM",
    "GPU_MEM_LD_PM",
    "GPU_MEM_LDU_GM",
    "GPU_MEM_ST_GM",
    "GPU_MEM_ST_LM",
    "GPU_MEM_ST_SM",
    "GPU_DATA_XFER_GM",
    "GPU_DATA_XFER_LM",
    "GPU_DATA_XFER_SM",
  };



  string output_filename(trace_path);
  output_filename.append("opcode_stat.txt");
    
  ofstream out(output_filename.c_str());

  for (int ii = 0; ii < GPU_OPCODE_LAST; ++ii) {
    out << setw(20) << left << tr_opcode_names[ii] << left << opcode_stats[ii] << "\n";
  }

  out.close();
}



