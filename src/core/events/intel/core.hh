#pragma once
#include <cstdint>
#include "intel_priv.hh"
namespace optkit::intel::core{
	enum core : uint64_t {
		UNHALTED_CORE_CYCLES = 0x3c, // Count core clock cycles whenever the clock signal on the specific core is running (not halted)
		INSTRUCTION_RETIRED = 0xc0, // Count the number of instructions at retirement
		INSTRUCTIONS_RETIRED = 0xc0, // This is an alias from INSTRUCTION_RETIRED
		UNHALTED_REFERENCE_CYCLES = 0x0300, // Unhalted reference cycles
		LLC_REFERENCES = 0x4f2e, // Count each request originating equiv the core to reference a cache line in the last level cache. The count may include speculation
		LAST_LEVEL_CACHE_REFERENCES = 0x4f2e, // This is an alias for LLC_REFERENCES
		LLC_MISSES = 0x412e, // Count each cache miss condition for references to the last level cache. The event count may include speculation
		LAST_LEVEL_CACHE_MISSES = 0x412e, // This is an alias for LLC_MISSES
		BRANCH_INSTRUCTIONS_RETIRED = 0xc4, // Count branch instructions at retirement. Specifically
		MISPREDICTED_BRANCH_RETIRED = 0xc5, // Count mispredicted branch instructions at retirement. Specifically
		RS_UOPS_DISPATCHED_CYCLES = 0xa1, // Cycles micro-ops dispatched for execution
		RS_UOPS_DISPATCHED_CYCLES__MASK__CORE_RS_UOPS_DISPATCHED_CYCLES__PORT_0 = 0x100, // On port 0
		RS_UOPS_DISPATCHED_CYCLES__MASK__CORE_RS_UOPS_DISPATCHED_CYCLES__PORT_1 = 0x200, // On port 1
		RS_UOPS_DISPATCHED_CYCLES__MASK__CORE_RS_UOPS_DISPATCHED_CYCLES__PORT_2 = 0x400, // On port 2
		RS_UOPS_DISPATCHED_CYCLES__MASK__CORE_RS_UOPS_DISPATCHED_CYCLES__PORT_3 = 0x800, // On port 3
		RS_UOPS_DISPATCHED_CYCLES__MASK__CORE_RS_UOPS_DISPATCHED_CYCLES__PORT_4 = 0x1000, // On port 4
		RS_UOPS_DISPATCHED_CYCLES__MASK__CORE_RS_UOPS_DISPATCHED_CYCLES__PORT_5 = 0x2000, // On port 5
		RS_UOPS_DISPATCHED_CYCLES__MASK__CORE_RS_UOPS_DISPATCHED_CYCLES__ANY = 0x3f00, // On any port
		RS_UOPS_DISPATCHED = 0xa0, // Number of micro-ops dispatched for execution
		RS_UOPS_DISPATCHED_NONE = 0xa0 | INTEL_X86_MOD_INV | (0x1 << INTEL_X86_CMASK_BIT), // Number of of cycles in which no micro-ops is dispatched for execution
		LOAD_BLOCK = 0x3, // Loads blocked
		LOAD_BLOCK__MASK__CORE_LOAD_BLOCK__STA = 0x200, // Loads blocked by a preceding store with unknown address
		LOAD_BLOCK__MASK__CORE_LOAD_BLOCK__STD = 0x400, // Loads blocked by a preceding store with unknown data
		LOAD_BLOCK__MASK__CORE_LOAD_BLOCK__OVERLAP_STORE = 0x800, // Loads that partially overlap an earlier store
		LOAD_BLOCK__MASK__CORE_LOAD_BLOCK__UNTIL_RETIRE = 0x1000, // Loads blocked until retirement
		LOAD_BLOCK__MASK__CORE_LOAD_BLOCK__L1D = 0x2000, // Loads blocked by the L1 data cache
		SB_DRAIN_CYCLES = 0x104, // Cycles while stores are blocked due to store buffer drain
		STORE_BLOCK = 0x4, // Cycles while store is waiting
		STORE_BLOCK__MASK__CORE_STORE_BLOCK__ORDER = 0x200, // Cycles while store is waiting for a preceding store to be globally observed
		STORE_BLOCK__MASK__CORE_STORE_BLOCK__SNOOP = 0x800, // A store is blocked due to a conflict with an external or internal snoop
		SEGMENT_REG_LOADS = 0x6, // Number of segment register loads
		SSE_PRE_EXEC = 0x7, // Streaming SIMD Extensions (SSE) Prefetch instructions executed
		SSE_PRE_EXEC__MASK__CORE_SSE_PRE_EXEC__NTA = 0x0, // Streaming SIMD Extensions (SSE) Prefetch NTA instructions executed
		SSE_PRE_EXEC__MASK__CORE_SSE_PRE_EXEC__L1 = 0x100, // Streaming SIMD Extensions (SSE) PrefetchT0 instructions executed
		SSE_PRE_EXEC__MASK__CORE_SSE_PRE_EXEC__L2 = 0x200, // Streaming SIMD Extensions (SSE) PrefetchT1 and PrefetchT2 instructions executed
		SSE_PRE_EXEC__MASK__CORE_SSE_PRE_EXEC__STORES = 0x300, // Streaming SIMD Extensions (SSE) Weakly-ordered store instructions executed
		DTLB_MISSES = 0x8, // Memory accesses that missed the DTLB
		DTLB_MISSES__MASK__CORE_DTLB_MISSES__ANY = 0x100, // Any memory access that missed the DTLB
		DTLB_MISSES__MASK__CORE_DTLB_MISSES__MISS_LD = 0x200, // DTLB misses due to load operations
		DTLB_MISSES__MASK__CORE_DTLB_MISSES__L0_MISS_LD = 0x400, // L0 DTLB misses due to load operations
		DTLB_MISSES__MASK__CORE_DTLB_MISSES__MISS_ST = 0x800, // DTLB misses due to store operations
		MEMORY_DISAMBIGUATION = 0x9, // Memory disambiguation
		MEMORY_DISAMBIGUATION__MASK__CORE_MEMORY_DISAMBIGUATION__RESET = 0x100, // Memory disambiguation reset cycles
		MEMORY_DISAMBIGUATION__MASK__CORE_MEMORY_DISAMBIGUATION__SUCCESS = 0x200, // Number of loads that were successfully disambiguated
		PAGE_WALKS = 0xc, // Number of page-walks executed
		PAGE_WALKS__MASK__CORE_PAGE_WALKS__COUNT = 0x100, // Number of page-walks executed
		PAGE_WALKS__MASK__CORE_PAGE_WALKS__CYCLES = 0x200, // Duration of page-walks in core cycles
		FP_COMP_OPS_EXE = 0x10, // Floating point computational micro-ops executed
		FP_ASSIST = 0x11, // Floating point assists
		MUL = 0x12, // Multiply operations executed
		DIV = 0x13, // Divide operations executed
		CYCLES_DIV_BUSY = 0x14, // Cycles the divider is busy
		IDLE_DURING_DIV = 0x18, // Cycles the divider is busy and all other execution units are idle
		DELAYED_BYPASS = 0x19, // Delayed bypass
		DELAYED_BYPASS__MASK__CORE_DELAYED_BYPASS__FP = 0x0, // Delayed bypass to FP operation
		DELAYED_BYPASS__MASK__CORE_DELAYED_BYPASS__SIMD = 0x100, // Delayed bypass to SIMD operation
		DELAYED_BYPASS__MASK__CORE_DELAYED_BYPASS__LOAD = 0x200, // Delayed bypass to load operation
		L2_ADS = 0x21, // Cycles L2 address bus is in use
		L2_ADS__MASK__CORE_L2_ADS__SELF = 0x4000, // This core
		L2_ADS__MASK__CORE_L2_ADS__BOTH_CORES = 0xc000, // Both cores
		L2_DBUS_BUSY_RD = 0x23, // Cycles the L2 transfers data to the core
		L2_DBUS_BUSY_RD__MASK__CORE_L2_ADS__SELF = 0x4000, // This core
		L2_DBUS_BUSY_RD__MASK__CORE_L2_ADS__BOTH_CORES = 0xc000, // Both cores
		L2_LINES_IN = 0x24, // L2 cache misses
		L2_LINES_IN__MASK__CORE_L2_LINES_IN__SELF = 0x4000, // This core
		L2_LINES_IN__MASK__CORE_L2_LINES_IN__BOTH_CORES = 0xc000, // Both cores
		L2_LINES_IN__MASK__CORE_L2_LINES_IN__ANY = 0x3000, // All inclusive
		L2_LINES_IN__MASK__CORE_L2_LINES_IN__PREFETCH = 0x1000, // Hardware prefetch only
		L2_LINES_IN__MASK__CORE_L2_LINES_IN__EXCL_PREFETCH = 0x0, // Exclude hardware prefetch
		L2_M_LINES_IN = 0x25, // L2 cache line modifications
		L2_M_LINES_IN__MASK__CORE_L2_ADS__SELF = 0x4000, // This core
		L2_M_LINES_IN__MASK__CORE_L2_ADS__BOTH_CORES = 0xc000, // Both cores
		L2_LINES_OUT = 0x26, // L2 cache lines evicted
		L2_LINES_OUT__MASK__CORE_L2_LINES_IN__SELF = 0x4000, // This core
		L2_LINES_OUT__MASK__CORE_L2_LINES_IN__BOTH_CORES = 0xc000, // Both cores
		L2_LINES_OUT__MASK__CORE_L2_LINES_IN__ANY = 0x3000, // All inclusive
		L2_LINES_OUT__MASK__CORE_L2_LINES_IN__PREFETCH = 0x1000, // Hardware prefetch only
		L2_LINES_OUT__MASK__CORE_L2_LINES_IN__EXCL_PREFETCH = 0x0, // Exclude hardware prefetch
		L2_M_LINES_OUT = 0x27, // Modified lines evicted from the L2 cache
		L2_M_LINES_OUT__MASK__CORE_L2_LINES_IN__SELF = 0x4000, // This core
		L2_M_LINES_OUT__MASK__CORE_L2_LINES_IN__BOTH_CORES = 0xc000, // Both cores
		L2_M_LINES_OUT__MASK__CORE_L2_LINES_IN__ANY = 0x3000, // All inclusive
		L2_M_LINES_OUT__MASK__CORE_L2_LINES_IN__PREFETCH = 0x1000, // Hardware prefetch only
		L2_M_LINES_OUT__MASK__CORE_L2_LINES_IN__EXCL_PREFETCH = 0x0, // Exclude hardware prefetch
		L2_IFETCH = 0x28, // L2 cacheable instruction fetch requests
		L2_IFETCH__MASK__CORE_L2_IFETCH__SELF = 0x4000, // This core
		L2_IFETCH__MASK__CORE_L2_IFETCH__BOTH_CORES = 0xc000, // Both cores
		L2_IFETCH__MASK__CORE_L2_IFETCH__MESI = 0xf00, // Any cacheline access
		L2_IFETCH__MASK__CORE_L2_IFETCH__I_STATE = 0x100, // Invalid cacheline
		L2_IFETCH__MASK__CORE_L2_IFETCH__S_STATE = 0x200, // Shared cacheline
		L2_IFETCH__MASK__CORE_L2_IFETCH__E_STATE = 0x400, // Exclusive cacheline
		L2_IFETCH__MASK__CORE_L2_IFETCH__M_STATE = 0x800, // Modified cacheline
		L2_LD = 0x29, // L2 cache reads
		L2_LD__MASK__CORE_L2_LD__SELF = 0x4000, // This core
		L2_LD__MASK__CORE_L2_LD__BOTH_CORES = 0xc000, // Both cores
		L2_LD__MASK__CORE_L2_LD__ANY = 0x3000, // All inclusive
		L2_LD__MASK__CORE_L2_LD__PREFETCH = 0x1000, // Hardware prefetch only
		L2_LD__MASK__CORE_L2_LD__EXCL_PREFETCH = 0x0, // Exclude hardware prefetch
		L2_LD__MASK__CORE_L2_LD__MESI = 0xf00, // Any cacheline access
		L2_LD__MASK__CORE_L2_LD__I_STATE = 0x100, // Invalid cacheline
		L2_LD__MASK__CORE_L2_LD__S_STATE = 0x200, // Shared cacheline
		L2_LD__MASK__CORE_L2_LD__E_STATE = 0x400, // Exclusive cacheline
		L2_LD__MASK__CORE_L2_LD__M_STATE = 0x800, // Modified cacheline
		L2_ST = 0x2a, // L2 store requests
		L2_ST__MASK__CORE_L2_IFETCH__SELF = 0x4000, // This core
		L2_ST__MASK__CORE_L2_IFETCH__BOTH_CORES = 0xc000, // Both cores
		L2_ST__MASK__CORE_L2_IFETCH__MESI = 0xf00, // Any cacheline access
		L2_ST__MASK__CORE_L2_IFETCH__I_STATE = 0x100, // Invalid cacheline
		L2_ST__MASK__CORE_L2_IFETCH__S_STATE = 0x200, // Shared cacheline
		L2_ST__MASK__CORE_L2_IFETCH__E_STATE = 0x400, // Exclusive cacheline
		L2_ST__MASK__CORE_L2_IFETCH__M_STATE = 0x800, // Modified cacheline
		L2_LOCK = 0x2b, // L2 locked accesses
		L2_LOCK__MASK__CORE_L2_IFETCH__SELF = 0x4000, // This core
		L2_LOCK__MASK__CORE_L2_IFETCH__BOTH_CORES = 0xc000, // Both cores
		L2_LOCK__MASK__CORE_L2_IFETCH__MESI = 0xf00, // Any cacheline access
		L2_LOCK__MASK__CORE_L2_IFETCH__I_STATE = 0x100, // Invalid cacheline
		L2_LOCK__MASK__CORE_L2_IFETCH__S_STATE = 0x200, // Shared cacheline
		L2_LOCK__MASK__CORE_L2_IFETCH__E_STATE = 0x400, // Exclusive cacheline
		L2_LOCK__MASK__CORE_L2_IFETCH__M_STATE = 0x800, // Modified cacheline
		L2_RQSTS = 0x2e, // L2 cache requests
		L2_RQSTS__MASK__CORE_L2_LD__SELF = 0x4000, // This core
		L2_RQSTS__MASK__CORE_L2_LD__BOTH_CORES = 0xc000, // Both cores
		L2_RQSTS__MASK__CORE_L2_LD__ANY = 0x3000, // All inclusive
		L2_RQSTS__MASK__CORE_L2_LD__PREFETCH = 0x1000, // Hardware prefetch only
		L2_RQSTS__MASK__CORE_L2_LD__EXCL_PREFETCH = 0x0, // Exclude hardware prefetch
		L2_RQSTS__MASK__CORE_L2_LD__MESI = 0xf00, // Any cacheline access
		L2_RQSTS__MASK__CORE_L2_LD__I_STATE = 0x100, // Invalid cacheline
		L2_RQSTS__MASK__CORE_L2_LD__S_STATE = 0x200, // Shared cacheline
		L2_RQSTS__MASK__CORE_L2_LD__E_STATE = 0x400, // Exclusive cacheline
		L2_RQSTS__MASK__CORE_L2_LD__M_STATE = 0x800, // Modified cacheline
		L2_REJECT_BUSQ = 0x30, // Rejected L2 cache requests
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__SELF = 0x4000, // This core
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__BOTH_CORES = 0xc000, // Both cores
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__ANY = 0x3000, // All inclusive
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__PREFETCH = 0x1000, // Hardware prefetch only
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__EXCL_PREFETCH = 0x0, // Exclude hardware prefetch
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__MESI = 0xf00, // Any cacheline access
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__I_STATE = 0x100, // Invalid cacheline
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__S_STATE = 0x200, // Shared cacheline
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__E_STATE = 0x400, // Exclusive cacheline
		L2_REJECT_BUSQ__MASK__CORE_L2_LD__M_STATE = 0x800, // Modified cacheline
		L2_NO_REQ = 0x32, // Cycles no L2 cache requests are pending
		L2_NO_REQ__MASK__CORE_L2_ADS__SELF = 0x4000, // This core
		L2_NO_REQ__MASK__CORE_L2_ADS__BOTH_CORES = 0xc000, // Both cores
		EIST_TRANS = 0x3a, // Number of Enhanced Intel SpeedStep(R) Technology (EIST) transitions
		THERMAL_TRIP = 0xc03b, // Number of thermal trips
		CPU_CLK_UNHALTED = 0x3c, // Core cycles when core is not halted
		CPU_CLK_UNHALTED__MASK__CORE_CPU_CLK_UNHALTED__CORE_P = 0x0, // Core cycles when core is not halted
		CPU_CLK_UNHALTED__MASK__CORE_CPU_CLK_UNHALTED__BUS = 0x100, // Bus cycles when core is not halted. This event can give a measurement of the elapsed time. This events has a constant ratio with CPU_CLK_UNHALTED:REF event
		CPU_CLK_UNHALTED__MASK__CORE_CPU_CLK_UNHALTED__NO_OTHER = 0x200, // Bus cycles when core is active and the other is halted
		L1D_CACHE_LD = 0x40, // L1 cacheable data reads
		L1D_CACHE_LD__MASK__CORE_L1D_CACHE_LD__MESI = 0xf00, // Any cacheline access
		L1D_CACHE_LD__MASK__CORE_L1D_CACHE_LD__I_STATE = 0x100, // Invalid cacheline
		L1D_CACHE_LD__MASK__CORE_L1D_CACHE_LD__S_STATE = 0x200, // Shared cacheline
		L1D_CACHE_LD__MASK__CORE_L1D_CACHE_LD__E_STATE = 0x400, // Exclusive cacheline
		L1D_CACHE_LD__MASK__CORE_L1D_CACHE_LD__M_STATE = 0x800, // Modified cacheline
		L1D_CACHE_ST = 0x41, // L1 cacheable data writes
		L1D_CACHE_ST__MASK__CORE_L1D_CACHE_LD__MESI = 0xf00, // Any cacheline access
		L1D_CACHE_ST__MASK__CORE_L1D_CACHE_LD__I_STATE = 0x100, // Invalid cacheline
		L1D_CACHE_ST__MASK__CORE_L1D_CACHE_LD__S_STATE = 0x200, // Shared cacheline
		L1D_CACHE_ST__MASK__CORE_L1D_CACHE_LD__E_STATE = 0x400, // Exclusive cacheline
		L1D_CACHE_ST__MASK__CORE_L1D_CACHE_LD__M_STATE = 0x800, // Modified cacheline
		L1D_CACHE_LOCK = 0x42, // L1 data cacheable locked reads
		L1D_CACHE_LOCK__MASK__CORE_L1D_CACHE_LD__MESI = 0xf00, // Any cacheline access
		L1D_CACHE_LOCK__MASK__CORE_L1D_CACHE_LD__I_STATE = 0x100, // Invalid cacheline
		L1D_CACHE_LOCK__MASK__CORE_L1D_CACHE_LD__S_STATE = 0x200, // Shared cacheline
		L1D_CACHE_LOCK__MASK__CORE_L1D_CACHE_LD__E_STATE = 0x400, // Exclusive cacheline
		L1D_CACHE_LOCK__MASK__CORE_L1D_CACHE_LD__M_STATE = 0x800, // Modified cacheline
		L1D_ALL_REF = 0x143, // All references to the L1 data cache
		L1D_ALL_CACHE_REF = 0x243, // L1 Data cacheable reads and writes
		L1D_REPL = 0xf45, // Cache lines allocated in the L1 data cache
		L1D_M_REPL = 0x46, // Modified cache lines allocated in the L1 data cache
		L1D_M_EVICT = 0x47, // Modified cache lines evicted from the L1 data cache
		L1D_PEND_MISS = 0x48, // Total number of outstanding L1 data cache misses at any cycle
		L1D_SPLIT = 0x49, // Cache line split from L1 data cache
		L1D_SPLIT__MASK__CORE_L1D_SPLIT__LOADS = 0x100, // Cache line split loads from the L1 data cache
		L1D_SPLIT__MASK__CORE_L1D_SPLIT__STORES = 0x200, // Cache line split stores to the L1 data cache
		SSE_PRE_MISS = 0x4b, // Streaming SIMD Extensions (SSE) instructions missing all cache levels
		SSE_PRE_MISS__MASK__CORE_SSE_PRE_MISS__NTA = 0x0, // Streaming SIMD Extensions (SSE) Prefetch NTA instructions missing all cache levels
		SSE_PRE_MISS__MASK__CORE_SSE_PRE_MISS__L1 = 0x100, // Streaming SIMD Extensions (SSE) PrefetchT0 instructions missing all cache levels
		SSE_PRE_MISS__MASK__CORE_SSE_PRE_MISS__L2 = 0x200, // Streaming SIMD Extensions (SSE) PrefetchT1 and PrefetchT2 instructions missing all cache levels
		LOAD_HIT_PRE = 0x4c, // Load operations conflicting with a software prefetch to the same address
		L1D_PREFETCH = 0x4e, // L1 data cache prefetch
		L1D_PREFETCH__MASK__CORE_L1D_PREFETCH__REQUESTS = 0x1000, // L1 data cache prefetch requests
		BUS_REQUEST_OUTSTANDING = 0x60, // Number of pending full cache line read transactions on the bus occurring in each cycle
		BUS_REQUEST_OUTSTANDING__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_REQUEST_OUTSTANDING__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_REQUEST_OUTSTANDING__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_REQUEST_OUTSTANDING__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_BNR_DRV = 0x61, // Number of Bus Not Ready signals asserted
		BUS_BNR_DRV__MASK__CORE_BUS_BNR_DRV__THIS_AGENT = 0x0, // This agent
		BUS_BNR_DRV__MASK__CORE_BUS_BNR_DRV__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_DRDY_CLOCKS = 0x62, // Bus cycles when data is sent on the bus
		BUS_DRDY_CLOCKS__MASK__CORE_BUS_BNR_DRV__THIS_AGENT = 0x0, // This agent
		BUS_DRDY_CLOCKS__MASK__CORE_BUS_BNR_DRV__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_LOCK_CLOCKS = 0x63, // Bus cycles when a LOCK signal is asserted
		BUS_LOCK_CLOCKS__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_LOCK_CLOCKS__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_LOCK_CLOCKS__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_LOCK_CLOCKS__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_DATA_RCV = 0x64, // Bus cycles while processor receives data
		BUS_DATA_RCV__MASK__CORE_L2_ADS__SELF = 0x4000, // This core
		BUS_DATA_RCV__MASK__CORE_L2_ADS__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_BRD = 0x65, // Burst read bus transactions
		BUS_TRANS_BRD__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_BRD__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_BRD__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_BRD__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_RFO = 0x66, // RFO bus transactions
		BUS_TRANS_RFO__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_RFO__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_RFO__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_RFO__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_WB = 0x67, // Explicit writeback bus transactions
		BUS_TRANS_WB__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_WB__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_WB__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_WB__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_IFETCH = 0x68, // Instruction-fetch bus transactions
		BUS_TRANS_IFETCH__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_IFETCH__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_IFETCH__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_IFETCH__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_INVAL = 0x69, // Invalidate bus transactions
		BUS_TRANS_INVAL__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_INVAL__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_INVAL__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_INVAL__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_PWR = 0x6a, // Partial write bus transaction
		BUS_TRANS_PWR__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_PWR__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_PWR__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_PWR__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_P = 0x6b, // Partial bus transactions
		BUS_TRANS_P__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_P__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_P__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_P__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_IO = 0x6c, // IO bus transactions
		BUS_TRANS_IO__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_IO__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_IO__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_IO__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_DEF = 0x6d, // Deferred bus transactions
		BUS_TRANS_DEF__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_DEF__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_DEF__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_DEF__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_BURST = 0x6e, // Burst (full cache-line) bus transactions
		BUS_TRANS_BURST__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_BURST__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_BURST__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_BURST__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_MEM = 0x6f, // Memory bus transactions
		BUS_TRANS_MEM__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_MEM__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_MEM__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_MEM__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_TRANS_ANY = 0x70, // All bus transactions
		BUS_TRANS_ANY__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		BUS_TRANS_ANY__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		BUS_TRANS_ANY__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		BUS_TRANS_ANY__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		EXT_SNOOP = 0x77, // External snoops responses
		EXT_SNOOP__MASK__CORE_EXT_SNOOP__ANY = 0xb00, // Any external snoop response
		EXT_SNOOP__MASK__CORE_EXT_SNOOP__CLEAN = 0x100, // External snoop CLEAN response
		EXT_SNOOP__MASK__CORE_EXT_SNOOP__HIT = 0x200, // External snoop HIT response
		EXT_SNOOP__MASK__CORE_EXT_SNOOP__HITM = 0x800, // External snoop HITM response
		EXT_SNOOP__MASK__CORE_EXT_SNOOP__THIS_AGENT = 0x0, // This agent
		EXT_SNOOP__MASK__CORE_EXT_SNOOP__ALL_AGENTS = 0x2000, // Any agent on the bus
		CMP_SNOOP = 0x78, // L1 data cache is snooped by other core
		CMP_SNOOP__MASK__CORE_CMP_SNOOP__ANY = 0x300, // L1 data cache is snooped by other core
		CMP_SNOOP__MASK__CORE_CMP_SNOOP__SHARE = 0x100, // L1 data cache is snooped for sharing by other core
		CMP_SNOOP__MASK__CORE_CMP_SNOOP__INVALIDATE = 0x200, // L1 data cache is snooped for Invalidation by other core
		CMP_SNOOP__MASK__CORE_CMP_SNOOP__SELF = 0x4000, // This core
		CMP_SNOOP__MASK__CORE_CMP_SNOOP__BOTH_CORES = 0xc000, // Both cores
		BUS_HIT_DRV = 0x7a, // HIT signal asserted
		BUS_HIT_DRV__MASK__CORE_BUS_BNR_DRV__THIS_AGENT = 0x0, // This agent
		BUS_HIT_DRV__MASK__CORE_BUS_BNR_DRV__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_HITM_DRV = 0x7b, // HITM signal asserted
		BUS_HITM_DRV__MASK__CORE_BUS_BNR_DRV__THIS_AGENT = 0x0, // This agent
		BUS_HITM_DRV__MASK__CORE_BUS_BNR_DRV__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUSQ_EMPTY = 0x7d, // Bus queue is empty
		BUSQ_EMPTY__MASK__CORE_BUS_BNR_DRV__THIS_AGENT = 0x0, // This agent
		BUSQ_EMPTY__MASK__CORE_BUS_BNR_DRV__ALL_AGENTS = 0x2000, // Any agent on the bus
		SNOOP_STALL_DRV = 0x7e, // Bus stalled for snoops
		SNOOP_STALL_DRV__MASK__CORE_BUS_REQUEST_OUTSTANDING__SELF = 0x4000, // This core
		SNOOP_STALL_DRV__MASK__CORE_BUS_REQUEST_OUTSTANDING__BOTH_CORES = 0xc000, // Both cores
		SNOOP_STALL_DRV__MASK__CORE_BUS_REQUEST_OUTSTANDING__THIS_AGENT = 0x0, // This agent
		SNOOP_STALL_DRV__MASK__CORE_BUS_REQUEST_OUTSTANDING__ALL_AGENTS = 0x2000, // Any agent on the bus
		BUS_IO_WAIT = 0x7f, // IO requests waiting in the bus queue
		BUS_IO_WAIT__MASK__CORE_L2_ADS__SELF = 0x4000, // This core
		BUS_IO_WAIT__MASK__CORE_L2_ADS__BOTH_CORES = 0xc000, // Both cores
		L1I_READS = 0x80, // Instruction fetches
		L1I_MISSES = 0x81, // Instruction Fetch Unit misses
		ITLB = 0x82, // ITLB small page misses
		ITLB__MASK__CORE_ITLB__SMALL_MISS = 0x200, // ITLB small page misses
		ITLB__MASK__CORE_ITLB__LARGE_MISS = 0x1000, // ITLB large page misses
		ITLB__MASK__CORE_ITLB__FLUSH = 0x4000, // ITLB flushes
		ITLB__MASK__CORE_ITLB__MISSES = 0x1200, // ITLB misses
		INST_QUEUE = 0x83, // Cycles during which the instruction queue is full
		INST_QUEUE__MASK__CORE_INST_QUEUE__FULL = 0x200, // Cycles during which the instruction queue is full
		CYCLES_L1I_MEM_STALLED = 0x86, // Cycles during which instruction fetches are stalled
		ILD_STALL = 0x87, // Instruction Length Decoder stall cycles due to a length changing prefix
		BR_INST_EXEC = 0x88, // Branch instructions executed
		BR_MISSP_EXEC = 0x89, // Mispredicted branch instructions executed
		BR_BAC_MISSP_EXEC = 0x8a, // Branch instructions mispredicted at decoding
		BR_CND_EXEC = 0x8b, // Conditional branch instructions executed
		BR_CND_MISSP_EXEC = 0x8c, // Mispredicted conditional branch instructions executed
		BR_IND_EXEC = 0x8d, // Indirect branch instructions executed
		BR_IND_MISSP_EXEC = 0x8e, // Mispredicted indirect branch instructions executed
		BR_RET_EXEC = 0x8f, // RET instructions executed
		BR_RET_MISSP_EXEC = 0x90, // Mispredicted RET instructions executed
		BR_RET_BAC_MISSP_EXEC = 0x91, // RET instructions executed mispredicted at decoding
		BR_CALL_EXEC = 0x92, // CALL instructions executed
		BR_CALL_MISSP_EXEC = 0x93, // Mispredicted CALL instructions executed
		BR_IND_CALL_EXEC = 0x94, // Indirect CALL instructions executed
		BR_TKN_BUBBLE_1 = 0x97, // Branch predicted taken with bubble I
		BR_TKN_BUBBLE_2 = 0x98, // Branch predicted taken with bubble II
		MACRO_INSTS = 0xaa, // Instructions decoded
		MACRO_INSTS__MASK__CORE_MACRO_INSTS__DECODED = 0x100, // Instructions decoded
		MACRO_INSTS__MASK__CORE_MACRO_INSTS__CISC_DECODED = 0x800, // CISC instructions decoded
		ESP = 0xab, // ESP register content synchronization
		ESP__MASK__CORE_ESP__SYNCH = 0x100, // ESP register content synchronization
		ESP__MASK__CORE_ESP__ADDITIONS = 0x200, // ESP register automatic additions
		SIMD_UOPS_EXEC = 0xb0, // SIMD micro-ops executed (excluding stores)
		SIMD_SAT_UOP_EXEC = 0xb1, // SIMD saturated arithmetic micro-ops executed
		SIMD_UOP_TYPE_EXEC = 0xb3, // SIMD packed multiply micro-ops executed
		SIMD_UOP_TYPE_EXEC__MASK__CORE_SIMD_UOP_TYPE_EXEC__MUL = 0x100, // SIMD packed multiply micro-ops executed
		SIMD_UOP_TYPE_EXEC__MASK__CORE_SIMD_UOP_TYPE_EXEC__SHIFT = 0x200, // SIMD packed shift micro-ops executed
		SIMD_UOP_TYPE_EXEC__MASK__CORE_SIMD_UOP_TYPE_EXEC__PACK = 0x400, // SIMD pack micro-ops executed
		SIMD_UOP_TYPE_EXEC__MASK__CORE_SIMD_UOP_TYPE_EXEC__UNPACK = 0x800, // SIMD unpack micro-ops executed
		SIMD_UOP_TYPE_EXEC__MASK__CORE_SIMD_UOP_TYPE_EXEC__LOGICAL = 0x1000, // SIMD packed logical micro-ops executed
		SIMD_UOP_TYPE_EXEC__MASK__CORE_SIMD_UOP_TYPE_EXEC__ARITHMETIC = 0x2000, // SIMD packed arithmetic micro-ops executed
		INST_RETIRED = 0xc0, // Instructions retired
		INST_RETIRED__MASK__CORE_INST_RETIRED__ANY_P = 0x0, // Instructions retired (Precise Event)
		INST_RETIRED__MASK__CORE_INST_RETIRED__LOADS = 0x100, // Instructions retired
		INST_RETIRED__MASK__CORE_INST_RETIRED__STORES = 0x200, // Instructions retired
		INST_RETIRED__MASK__CORE_INST_RETIRED__OTHER = 0x400, // Instructions retired
		X87_OPS_RETIRED = 0xc1, // FXCH instructions retired
		X87_OPS_RETIRED__MASK__CORE_X87_OPS_RETIRED__FXCH = 0x100, // FXCH instructions retired
		X87_OPS_RETIRED__MASK__CORE_X87_OPS_RETIRED__ANY = 0xfe00, // Retired floating-point computational operations (Precise Event)
		UOPS_RETIRED = 0xc2, // Fused load+op or load+indirect branch retired
		UOPS_RETIRED__MASK__CORE_UOPS_RETIRED__LD_IND_BR = 0x100, // Fused load+op or load+indirect branch retired
		UOPS_RETIRED__MASK__CORE_UOPS_RETIRED__STD_STA = 0x200, // Fused store address + data retired
		UOPS_RETIRED__MASK__CORE_UOPS_RETIRED__MACRO_FUSION = 0x400, // Retired instruction pairs fused into one micro-op
		UOPS_RETIRED__MASK__CORE_UOPS_RETIRED__NON_FUSED = 0x800, // Non-fused micro-ops retired
		UOPS_RETIRED__MASK__CORE_UOPS_RETIRED__FUSED = 0x700, // Fused micro-ops retired
		UOPS_RETIRED__MASK__CORE_UOPS_RETIRED__ANY = 0xf00, // Micro-ops retired
		MACHINE_NUKES = 0xc3, // Self-Modifying Code detected
		MACHINE_NUKES__MASK__CORE_MACHINE_NUKES__SMC = 0x100, // Self-Modifying Code detected
		MACHINE_NUKES__MASK__CORE_MACHINE_NUKES__MEM_ORDER = 0x400, // Execution pipeline restart due to memory ordering conflict or memory disambiguation misprediction
		BR_INST_RETIRED = 0xc4, // Retired branch instructions
		BR_INST_RETIRED__MASK__CORE_BR_INST_RETIRED__ANY = 0x0, // Retired branch instructions
		BR_INST_RETIRED__MASK__CORE_BR_INST_RETIRED__PRED_NOT_TAKEN = 0x100, // Retired branch instructions that were predicted not-taken
		BR_INST_RETIRED__MASK__CORE_BR_INST_RETIRED__MISPRED_NOT_TAKEN = 0x200, // Retired branch instructions that were mispredicted not-taken
		BR_INST_RETIRED__MASK__CORE_BR_INST_RETIRED__PRED_TAKEN = 0x400, // Retired branch instructions that were predicted taken
		BR_INST_RETIRED__MASK__CORE_BR_INST_RETIRED__MISPRED_TAKEN = 0x800, // Retired branch instructions that were mispredicted taken
		BR_INST_RETIRED__MASK__CORE_BR_INST_RETIRED__TAKEN = 0xc00, // Retired taken branch instructions
		BR_INST_RETIRED_MISPRED = 0xc5, // Retired mispredicted branch instructions (Precise_Event)
		CYCLES_INT_MASKED = 0x1c6, // Cycles during which interrupts are disabled
		CYCLES_INT_PENDING_AND_MASKED = 0x2c6, // Cycles during which interrupts are pending and disabled
		SIMD_INST_RETIRED = 0xc7, // Retired Streaming SIMD Extensions (SSE) packed-single instructions
		SIMD_INST_RETIRED__MASK__CORE_SIMD_INST_RETIRED__PACKED_SINGLE = 0x100, // Retired Streaming SIMD Extensions (SSE) packed-single instructions
		SIMD_INST_RETIRED__MASK__CORE_SIMD_INST_RETIRED__SCALAR_SINGLE = 0x200, // Retired Streaming SIMD Extensions (SSE) scalar-single instructions
		SIMD_INST_RETIRED__MASK__CORE_SIMD_INST_RETIRED__PACKED_DOUBLE = 0x400, // Retired Streaming SIMD Extensions 2 (SSE2) packed-double instructions
		SIMD_INST_RETIRED__MASK__CORE_SIMD_INST_RETIRED__SCALAR_DOUBLE = 0x800, // Retired Streaming SIMD Extensions 2 (SSE2) scalar-double instructions
		SIMD_INST_RETIRED__MASK__CORE_SIMD_INST_RETIRED__VECTOR = 0x1000, // Retired Streaming SIMD Extensions 2 (SSE2) vector integer instructions
		SIMD_INST_RETIRED__MASK__CORE_SIMD_INST_RETIRED__ANY = 0x1f00, // Retired Streaming SIMD instructions (Precise Event)
		HW_INT_RCV = 0xc8, // Hardware interrupts received
		ITLB_MISS_RETIRED = 0xc9, // Retired instructions that missed the ITLB
		SIMD_COMP_INST_RETIRED = 0xca, // Retired computational Streaming SIMD Extensions (SSE) packed-single instructions
		SIMD_COMP_INST_RETIRED__MASK__CORE_SIMD_COMP_INST_RETIRED__PACKED_SINGLE = 0x100, // Retired computational Streaming SIMD Extensions (SSE) packed-single instructions
		SIMD_COMP_INST_RETIRED__MASK__CORE_SIMD_COMP_INST_RETIRED__SCALAR_SINGLE = 0x200, // Retired computational Streaming SIMD Extensions (SSE) scalar-single instructions
		SIMD_COMP_INST_RETIRED__MASK__CORE_SIMD_COMP_INST_RETIRED__PACKED_DOUBLE = 0x400, // Retired computational Streaming SIMD Extensions 2 (SSE2) packed-double instructions
		SIMD_COMP_INST_RETIRED__MASK__CORE_SIMD_COMP_INST_RETIRED__SCALAR_DOUBLE = 0x800, // Retired computational Streaming SIMD Extensions 2 (SSE2) scalar-double instructions
		MEM_LOAD_RETIRED = 0xcb, // Retired loads that miss the L1 data cache
		MEM_LOAD_RETIRED__MASK__CORE_MEM_LOAD_RETIRED__L1D_MISS = 0x100, // Retired loads that miss the L1 data cache (Precise Event)
		MEM_LOAD_RETIRED__MASK__CORE_MEM_LOAD_RETIRED__L1D_LINE_MISS = 0x200, // L1 data cache line missed by retired loads (Precise Event)
		MEM_LOAD_RETIRED__MASK__CORE_MEM_LOAD_RETIRED__L2_MISS = 0x400, // Retired loads that miss the L2 cache (Precise Event)
		MEM_LOAD_RETIRED__MASK__CORE_MEM_LOAD_RETIRED__L2_LINE_MISS = 0x800, // L2 cache line missed by retired loads (Precise Event)
		MEM_LOAD_RETIRED__MASK__CORE_MEM_LOAD_RETIRED__DTLB_MISS = 0x1000, // Retired loads that miss the DTLB (Precise Event)
		FP_MMX_TRANS = 0xcc, // Transitions from MMX (TM) Instructions to Floating Point Instructions
		FP_MMX_TRANS__MASK__CORE_FP_MMX_TRANS__TO_FP = 0x200, // Transitions from MMX (TM) Instructions to Floating Point Instructions
		FP_MMX_TRANS__MASK__CORE_FP_MMX_TRANS__TO_MMX = 0x100, // Transitions from Floating Point to MMX (TM) Instructions
		SIMD_ASSIST = 0xcd, // SIMD assists invoked
		SIMD_INSTR_RETIRED = 0xce, // SIMD Instructions retired
		SIMD_SAT_INSTR_RETIRED = 0xcf, // Saturated arithmetic instructions retired
		RAT_STALLS = 0xd2, // ROB read port stalls cycles
		RAT_STALLS__MASK__CORE_RAT_STALLS__ROB_READ_PORT = 0x100, // ROB read port stalls cycles
		RAT_STALLS__MASK__CORE_RAT_STALLS__PARTIAL_CYCLES = 0x200, // Partial register stall cycles
		RAT_STALLS__MASK__CORE_RAT_STALLS__FLAGS = 0x400, // Flag stall cycles
		RAT_STALLS__MASK__CORE_RAT_STALLS__FPSW = 0x800, // FPU status word stall
		RAT_STALLS__MASK__CORE_RAT_STALLS__ANY = 0xf00, // All RAT stall cycles
		SEG_RENAME_STALLS = 0xd4, // Segment rename stalls - ES
		SEG_RENAME_STALLS__MASK__CORE_SEG_RENAME_STALLS__ES = 0x100, // Segment rename stalls - ES
		SEG_RENAME_STALLS__MASK__CORE_SEG_RENAME_STALLS__DS = 0x200, // Segment rename stalls - DS
		SEG_RENAME_STALLS__MASK__CORE_SEG_RENAME_STALLS__FS = 0x400, // Segment rename stalls - FS
		SEG_RENAME_STALLS__MASK__CORE_SEG_RENAME_STALLS__GS = 0x800, // Segment rename stalls - GS
		SEG_RENAME_STALLS__MASK__CORE_SEG_RENAME_STALLS__ANY = 0xf00, // Any (ES/DS/FS/GS) segment rename stall
		SEG_REG_RENAMES = 0xd5, // Segment renames - ES
		SEG_REG_RENAMES__MASK__CORE_SEG_REG_RENAMES__ES = 0x100, // Segment renames - ES
		SEG_REG_RENAMES__MASK__CORE_SEG_REG_RENAMES__DS = 0x200, // Segment renames - DS
		SEG_REG_RENAMES__MASK__CORE_SEG_REG_RENAMES__FS = 0x400, // Segment renames - FS
		SEG_REG_RENAMES__MASK__CORE_SEG_REG_RENAMES__GS = 0x800, // Segment renames - GS
		SEG_REG_RENAMES__MASK__CORE_SEG_REG_RENAMES__ANY = 0xf00, // Any (ES/DS/FS/GS) segment rename
		RESOURCE_STALLS = 0xdc, // Cycles during which the ROB is full
		RESOURCE_STALLS__MASK__CORE_RESOURCE_STALLS__ROB_FULL = 0x100, // Cycles during which the ROB is full
		RESOURCE_STALLS__MASK__CORE_RESOURCE_STALLS__RS_FULL = 0x200, // Cycles during which the RS is full
		RESOURCE_STALLS__MASK__CORE_RESOURCE_STALLS__LD_ST = 0x400, // Cycles during which the pipeline has exceeded load or store limit or waiting to commit all stores
		RESOURCE_STALLS__MASK__CORE_RESOURCE_STALLS__FPCW = 0x800, // Cycles stalled due to FPU control word write
		RESOURCE_STALLS__MASK__CORE_RESOURCE_STALLS__BR_MISS_CLEAR = 0x1000, // Cycles stalled due to branch misprediction
		RESOURCE_STALLS__MASK__CORE_RESOURCE_STALLS__ANY = 0x1f00, // Resource related stalls
		BR_INST_DECODED = 0xe0, // Branch instructions decoded
		BOGUS_BR = 0xe4, // Bogus branches
		BACLEARS = 0xe6, // BACLEARS asserted
		PREF_RQSTS_UP = 0xf0, // Upward prefetches issued from the DPL
		PREF_RQSTS_DN = 0xf8, // Downward prefetches issued from the DPL
		
	};
};

namespace core = optkit::intel::core;