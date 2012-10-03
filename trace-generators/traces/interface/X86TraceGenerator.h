
#ifndef PTX_TRACE_GENERATOR_H_INCLUDED
#define PTX_TRACE_GENERATOR_H_INCLUDED

// c++ includes
#include <stdint.h>
#include <map>
#include <zlib.h>
#include <unordered_map>

// Boost includes
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/Dim3.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/executive/interface/ExecutableKernel.h>
#include <traces/interface/KernelEntry.h>


#define WARP_SIZE 32

#define dbg if(0) cerr
#define WRITE_DEBUG 0

#if WRITE_DEBUG == 1
#define SINGLE_WARP 1
#else
#define SINGLE_WARP 0
#endif

#define INST_START_ADDR 8000
#define INST_LAST_ADDR 262144

namespace executive {
  class EmulatedKernel;
}


struct Thread_info;
struct Trace_info;
struct Inst_info;
struct Model_info; // HSP

namespace trace {
  class X86TraceGenerator : public trace::TraceGenerator { 
    public:
      /**
       * Constructor
       */
      X86TraceGenerator();

      /**
       * Destructor
       */
      ~X86TraceGenerator();

      /**
       * Initialization
       */
      void initialize(const executive::ExecutableKernel& kernel);

      /**
       * Event function
       */
      void event(const trace::TraceEvent & event);

      /**
       * Finalization
       */
      void finalize();

      void writeInstToFile(std::ofstream &file, Inst_info *t_info);

    private:
      int calculate_occupancy(const executive::ExecutableKernel& kernel);

    private:
      bool init;
      int32_t num_warps_per_block;
      int32_t num_total_warps;
      Thread_info *thread_info;
      Trace_info *trace_info;
      //std::map<int, Thread_info *> thread_info;
      //std::map<int, Trace_info *> trace_info;
      std::map<ir::PTXU64, Inst_info *> inst_storage;
      std::map<int, bool> init_block;

      uint64_t total_inst_count;

      gzFile gz_config_file;
      std::ofstream txt_config_file;
      std::ofstream info_file;

      struct MemAccess
      {
        ir::PTXU64 mem_addr;
        ir::PTXU32 mem_size;
      };

      MemAccess mem_access[WARP_SIZE];

      std::string module;
      std::string kernel_name;
      std::string trace_name;
      std::string extension;
      std::string trace_path;

      int last_block_id;

      std::ofstream txt_kernel_config_file;

      std::unordered_map<std::string, int> m_kernel_register_map;
      std::unordered_map<std::string, int> m_kernel_sharedmem_map;
      std::string m_compute;

      ////////////////////////////////////////////////
      int blockDimX;
      int blockDimY;
      int blockDimZ;
      int gridDimX;
      int gridDimY;
      int gridDimZ;

      int kernel_count;

      unsigned int mem_addr_flag;

      std::map<std::string, int> kernel_count_map;
      ////////////////////////////////////////////////

  };
}

#endif
