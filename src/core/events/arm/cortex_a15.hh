#pragma once
#include <cstdint>
namespace optkit::arm::cortex_a15{
	enum cortex_a15 : uint64_t {
		SW_INCR = 0x00, // Instruction architecturally executed (condition check pass) Software increment
		L1I_CACHE_REFILL = 0x01, // Level 1 instruction cache refill
		L1I_TLB_REFILL = 0x02, // Level 1 instruction TLB refill
		L1D_CACHE_REFILL = 0x03, // Level 1 data cache refill
		L1D_CACHE_ACCESS = 0x04, // Level 1 data cache access
		L1D_TLB_REFILL = 0x05, // Level 1 data TLB refill
		INST_RETIRED = 0x08, // Instruction architecturally executed
		EXCEPTION_TAKEN = 0x09, // Exception taken
		EXCEPTION_RETURN = 0x0a, // Instruction architecturally executed (condition check pass) Exception return
		CID_WRITE_RETIRED = 0x0b, // Instruction architecturally executed (condition check pass)  Write to CONTEXTIDR
		BRANCH_MISPRED = 0x10, // Mispredicted or not predicted branch speculatively executed
		CPU_CYCLES = 0x11, // Cycles
		BRANCH_PRED = 0x12, // Predictable branch speculatively executed
		DATA_MEM_ACCESS = 0x13, // Data memory access
		L1I_CACHE_ACCESS = 0x14, // Level 1 instruction cache access
		L1D_CACHE_WB = 0x15, // Level 1 data cache WriteBack
		L2D_CACHE_ACCESS = 0x16, // Level 2 data cache access
		L2D_CACHE_REFILL = 0x17, // Level 2 data cache refill
		L2D_CACHE_WB = 0x18, // Level 2 data cache WriteBack
		BUS_ACCESS = 0x19, // Bus access
		LOCAL_MEMORY_ERROR = 0x1a, // Local memory error
		INST_SPEC_EXEC = 0x1b, // Instruction speculatively executed
		TTBR_WRITE_RETIRED = 0x1c, // Instruction architecturally executed (condition check pass)  Write to translation table base
		BUS_CYCLES = 0x1d, // Bus cycle
		L1D_READ_ACCESS = 0x40, // Level 1 data cache read access
		L1D_WRITE_ACCESS = 0x41, // Level 1 data cache write access
		L1D_READ_REFILL = 0x42, // Level 1 data cache read refill
		L1D_WRITE_REFILL = 0x43, // Level 1 data cache write refill
		L1D_WB_VICTIM = 0x46, // Level 1 data cache writeback victim
		L1D_WB_CLEAN_COHERENCY = 0x47, // Level 1 data cache writeback cleaning and coherency
		L1D_INVALIDATE = 0x48, // Level 1 data cache invalidate
		L1D_TLB_READ_REFILL = 0x4c, // Level 1 data TLB read refill
		L1D_TLB_WRITE_REFILL = 0x4d, // Level 1 data TLB write refill
		L2D_READ_ACCESS = 0x50, // Level 2 data cache read access
		L2D_WRITE_ACCESS = 0x51, // Level 2 data cache write access
		L2D_READ_REFILL = 0x52, // Level 2 data cache read refill
		L2D_WRITE_REFILL = 0x53, // Level 2 data cache write refill
		L2D_WB_VICTIM = 0x56, // Level 2 data cache writeback victim
		L2D_WB_CLEAN_COHERENCY = 0x57, // Level 2 data cache writeback cleaning and coherency
		L2D_INVALIDATE = 0x58, // Level 2 data cache invalidate
		BUS_READ_ACCESS = 0x60, // Bus read access
		BUS_WRITE_ACCESS = 0x61, // Bus write access
		BUS_NORMAL_ACCESS = 0x62, // Bus normal access
		BUS_NOT_NORMAL_ACCESS = 0x63, // Bus not normal access
		BUS_NORMAL_ACCESS_2 = 0x64, // Bus normal access
		BUS_PERIPH_ACCESS = 0x65, // Bus peripheral access
		DATA_MEM_READ_ACCESS = 0x66, // Data memory read access
		DATA_MEM_WRITE_ACCESS = 0x67, // Data memory write access
		UNALIGNED_READ_ACCESS = 0x68, // Unaligned read access
		UNALIGNED_WRITE_ACCESS = 0x69, // Unaligned read access
		UNALIGNED_ACCESS = 0x6a, // Unaligned access
		INST_SPEC_EXEC_LDREX = 0x6c, // LDREX exclusive instruction speculatively executed
		INST_SPEC_EXEC_STREX_PASS = 0x6d, // STREX pass exclusive instruction speculatively executed
		INST_SPEC_EXEC_STREX_FAIL = 0x6e, // STREX fail exclusive instruction speculatively executed
		INST_SPEC_EXEC_LOAD = 0x70, // Load instruction speculatively executed
		INST_SPEC_EXEC_STORE = 0x71, // Store instruction speculatively executed
		INST_SPEC_EXEC_LOAD_STORE = 0x72, // Load or store instruction speculatively executed
		INST_SPEC_EXEC_INTEGER_INST = 0x73, // Integer data processing instruction speculatively executed
		INST_SPEC_EXEC_SIMD = 0x74, // Advanced SIMD instruction speculatively executed
		INST_SPEC_EXEC_VFP = 0x75, // VFP instruction speculatively executed
		INST_SPEC_EXEC_SOFT_PC = 0x76, // Software of the PC instruction speculatively executed
		BRANCH_SPEC_EXEC_IMM_BRANCH = 0x78, // Immediate branch speculatively executed
		BRANCH_SPEC_EXEC_RET = 0x79, // Return branch speculatively executed
		BRANCH_SPEC_EXEC_IND = 0x7a, // Indirect branch speculatively executed
		BARRIER_SPEC_EXEC_ISB = 0x7c, // ISB barrier speculatively executed
		BARRIER_SPEC_EXEC_DSB = 0x7d, // DSB barrier speculatively executed
		BARRIER_SPEC_EXEC_DMB = 0x7e, // DMB barrier speculatively executed
		
	};
};

namespace cortex_a15 = optkit::arm::cortex_a15;