#include <cstdint>
namespace optkit::arm{
	enum class kunpeng : uint64_t {
		SW_INCR = 0x00, // Instruction architecturally executed
		INST_RETIRED = 0x08, // Instruction architecturally executed
		EXC_TAKEN = 0x09, // Exception taken
		EXC_RETURN = 0x0a, // Instruction architecturally executed
		CID_WRITE_RETIRED = 0x0b, // Instruction architecturally executed
		BR_RETURN_RETIRED = 0x0e, // Instruction architecturally executed
		TTBR_WRITE_RETIRED = 0x1c, // Instruction architecturally executed
		BR_RETIRED = 0x21, // Instruction architecturally executed
		SVE_INST_RETIRED = 0x8002, // This event counts architecturally executed SVE instructions.
		L1I_CACHE_REFILL = 0x01, // Level 1 instruction cache refill.
		L1I_TLB_REFILL = 0x02, // Attributable Level 1 instruction TLB refill.
		L1D_CACHE_REFILL = 0x03, // Level 1 data cache refill.
		L1D_CACHE = 0x04, // Level 1 data cache access.
		L1D_TLB_REFILL = 0x05, // Attributable Level 1 data TLB refill.
		BR_MIS_PRED = 0x10, // Mispredicted or not predicted branch. Speculatively executed.
		CPU_CYCLES = 0x11, // Cycle.
		BR_PRED = 0x12, // Predictable branch. Speculatively executed.
		MEM_ACCESS = 0x13, // Data memory access.
		L1I_CACHE = 0x14, // Attributable Level 1 instruction cache access.
		L1D_CACHE_WB = 0x15, // Attributable Level 1 data cache write-back.
		L2D_CACHE = 0x16, // Level 2 data cache access.
		L2D_CACHE_REFILL = 0x17, // Level 2 data cache refill.
		L2D_CACHE_WB = 0x18, // Attributable Level 2 data cache write-back.
		BUS_ACCESS = 0x19, // Attributable Bus access.
		MEMORY_ERROR = 0x1a, // Local memory error.
		INST_SPEC = 0x001b, // Operation speculatively executed.
		BUS_CYCLES = 0x1d, // Bus cycle.
		BR_MIS_PRED_RETIRED = 0x22, // Instruction architecturally executed
		STALL_FRONTEND = 0x23, // No operation issued due to the frontend.
		STALL_BACKEND = 0x24, // No operation issued due to the backend.
		L1D_TLB = 0x25, // Attributable Level 1 data or unified TLB access.
		L1I_TLB = 0x26, // Attributable Level 1 instruction TLB access.
		L2I_CACHE = 0x27, // Attributable Level 2 instruction cache access.
		L2I_CACHE_REFILL = 0x28, // Attributable Level 2 instruction cache refill.
		L2D_TLB_REFILL = 0x2d, // Attributable Level 2 data TLB refill.
		L2I_TLB_REFILL = 0x2e, // Attributable Level 2 instruction TLB refill.
		L2D_TLB = 0x2f, // Attributable Level 2 data or unified TLB access.
		L2I_TLB = 0x30, // Attributable Level 2 instruction TLB access.
		REMOTE_ACCESS = 0x31, // Access to another socket in a multi-socket system.
		LL_CACHE = 0x32, // Last Level cache access.
		LL_CACHE_MISS = 0x33, // Last Level cache miss.
		DTLB_WALK = 0x34, // Access to data TLB causes a translation table walk.
		ITLB_WALK = 0x35, // Access to instruction TLB that causes a translation table walk.
		LL_CACHE_RD = 0x36, // Attributable Last level cache memory read.
		LL_CACHE_MISS_RD = 0x37, // Last level cache miss
		REMOTE_ACCESS_RD = 0x38, // Access to another socket in a multi-socket system
		SAMPLE_POP = 0x4000, // Sample Population.
		SAMPLE_FEED = 0x4001, // Sample Taken.
		SAMPLE_FILTRATE = 0x4002, // Sample taken and not removed by filtering.
		SAMPLE_COLLISION = 0x4003, // Sample collided with a previous sample.
		L1D_CACHE_RD = 0x40, // Attributable Level 1 data cache access
		L1D_CACHE_WR = 0x41, // Attributable Level 1 data cache access
		L1D_CACHE_REFILL_RD = 0x42, // Attributable Level 1 data cache refill
		L1D_CACHE_REFILL_WR = 0x43, // Attributable Level 1 data cache refill
		L1D_CACHE_WB_VICTIM = 0x46, // Attributable Level 1 data cache Write-Back
		L1D_CACHE_WB_CLEAN = 0x47, // Level 1 data cache Write-Back
		L1D_CACHE_INVAL = 0x48, // Attributable Level 1 data cache invalidate.
		L1D_TLB_REFILL_RD = 0x4c, // Attributable Level 1 data TLB refill
		L1D_TLB_REFILL_WR = 0x4d, // Attributable Level 1 data TLB refill
		L1D_TLB_RD = 0x4e, // Attributable Level 1 data or unified TLB access
		L1D_TLB_WR = 0x4f, // Attributable Level 1 data or unified TLB access
		L2D_CACHE_RD = 0x50, // Attributable Level 2 data cache access
		L2D_CACHE_WR = 0x51, // Attributable Level 2 data cache access
		L2D_CACHE_REFILL_RD = 0x52, // Attributable Level 2 data cache refill
		L2D_CACHE_REFILL_WR = 0x53, // Attributable Level 2 data cache refill
		L2D_CACHE_WB_VICTIM = 0x56, // Attributable Level 2 data cache Write-Back
		L2D_CACHE_WB_CLEAN = 0x57, // Level 2 data cache Write-Back
		L2D_CACHE_INVAL = 0x58, // Attributable Level 2 data cache invalidate.
		BUS_ACCESS_RD = 0x60, // Bus access
		BUS_ACCESS_WR = 0x61, // Bus access
		BUS_ACCESS_SHARED = 0x62, // Bus access
		BUS_ACCESS_NOT_SHARED = 0x63, // Bus access
		BUS_ACCESS_NORMAL = 0x64, // Bus access
		BUS_ACCESS_PERIPH = 0x65, // Bus access
		MEM_ACCESS_RD = 0x66, // Data memory access
		MEM_ACCESS_WR = 0x67, // Data memory access
		UNALIGNED_LD_SPEC = 0x68, // Unaligned access
		UNALIGNED_ST_SPEC = 0x69, // Unaligned access
		UNALIGNED_LDST_SPEC = 0x6a, // Unaligned access.
		LDREX_SPEC = 0x6c, // Exclusive operation speculatively executed
		STREX_PASS_SPEC = 0x6d, // Exclusive operation speculatively executed
		STREX_FAIL_SPEC = 0x6e, // Exclusive operation speculatively executed
		STREX_SPEC = 0x6f, // Exclusive operation speculatively executed
		LD_SPEC = 0x70, // Operation speculatively executed
		ST_SPEC = 0x71, // Operation speculatively executed
		LDST_SPEC = 0x72, // Operation speculatively executed
		DP_SPEC = 0x73, // Operation speculatively executed
		ASE_SPEC = 0x74, // Operation speculatively executed
		VFP_SPEC = 0x75, // Operation speculatively executed
		PC_WRITE_SPEC = 0x76, // Operation speculatively executed
		CRYPTO_SPEC = 0x77, // Operation speculatively executed
		BR_IMMED_SPEC = 0x78, // Branch speculatively executed
		BR_RETURN_SPEC = 0x79, // Branch speculatively executed
		BR_INDIRECT_SPEC = 0x7a, // Branch speculatively executed
		ISB_SPEC = 0x7c, // Barrier speculatively executed
		DSB_SPEC = 0x7d, // Barrier speculatively executed
		DMB_SPEC = 0x7e, // Barrier speculatively executed
		EXC_UNDEF = 0x81, // Exception taken
		EXC_SVC = 0x82, // Exception taken
		EXC_PABORT = 0x83, // Exception taken
		EXC_DABORT = 0x84, // Exception taken
		EXC_IRQ = 0x86, // Exception taken
		EXC_FIQ = 0x87, // Exception taken
		EXC_SMC = 0x88, // Exception taken
		EXC_HVC = 0x8a, // Exception taken
		EXC_TRAP_PABORT = 0x8b, // Exception taken
		EXC_TRAP_DABORT = 0x8c, // Exception taken
		EXC_TRAP_OTHER = 0x8d, // Exception taken
		EXC_TRAP_IRQ = 0x8e, // Exception taken
		EXC_TRAP_FIQ = 0x8f, // Exception taken
		RC_LD_SPEC = 0x90, // Release consistency operation speculatively executed
		RC_ST_SPEC = 0x91, // Release consistency operation speculatively executed
		L1I_CACHE_PRF = 0x102e, // Level 1 instruction cache prefetch access count.
		L1I_CACHE_PRF_REFILL = 0x102f, // Level 1 instruction cache miss due to prefetch access count
		IQ_IS_EMPTY = 0x1043, // Instruction queue is empty
		IF_IS_STALL = 0x1044, // Instruction fetch stall cycles
		FETCH_BUBBLE = 0x2014, // Instructions can receive
		PRF_REQ = 0x6013, // Prefetch request from LSU
		HIT_ON_PRF = 0x6014, // Hit on prefetched data
		EXE_STALL_CYCLE = 0x7001, // Cycles of that the number of issuing micro operations are less than 4
		MEM_STALL_ANYLOAD = 0x7004, // No any micro operation is issued and meanwhile any load operation is not resolved
		MEM_STALL_L1MISS = 0x7006, // No any micro operation is issued and meanwhile there is any load operation missing L1 cache and pending data refill
		
	};
};