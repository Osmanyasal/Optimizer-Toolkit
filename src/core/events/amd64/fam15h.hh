#pragma once
#include <cstdint>
namespace optkit::amd64::fam15h{
	enum fam15h : uint64_t {
		DISPATCHED_FPU_OPS = 0x0, // FPU Pipe Assignment
		DISPATCHED_FPU_OPS__MASK__AMD64_FAM15H_DISPATCHED_FPU_OPS__OPS_PIPE0 = 0x1, // Total number uops assigned to Pipe 0
		DISPATCHED_FPU_OPS__MASK__AMD64_FAM15H_DISPATCHED_FPU_OPS__OPS_PIPE1 = 0x2, // Total number uops assigned to Pipe 1
		DISPATCHED_FPU_OPS__MASK__AMD64_FAM15H_DISPATCHED_FPU_OPS__OPS_PIPE2 = 0x4, // Total number uops assigned to Pipe 2
		DISPATCHED_FPU_OPS__MASK__AMD64_FAM15H_DISPATCHED_FPU_OPS__OPS_PIPE3 = 0x8, // Total number uops assigned to Pipe 3
		DISPATCHED_FPU_OPS__MASK__AMD64_FAM15H_DISPATCHED_FPU_OPS__OPS_DUAL_PIPE0 = 0x10, // Total number dual-pipe uops assigned to Pipe 0
		DISPATCHED_FPU_OPS__MASK__AMD64_FAM15H_DISPATCHED_FPU_OPS__OPS_DUAL_PIPE1 = 0x20, // Total number dual-pipe uops assigned to Pipe 1
		DISPATCHED_FPU_OPS__MASK__AMD64_FAM15H_DISPATCHED_FPU_OPS__OPS_DUAL_PIPE2 = 0x40, // Total number dual-pipe uops assigned to Pipe 2
		DISPATCHED_FPU_OPS__MASK__AMD64_FAM15H_DISPATCHED_FPU_OPS__OPS_DUAL_PIPE3 = 0x80, // Total number dual-pipe uops assigned to Pipe 3
		DISPATCHED_FPU_OPS__MASK__AMD64_FAM15H_DISPATCHED_FPU_OPS__ALL = 0xff, // All sub-events selected
		CYCLES_FPU_EMPTY = 0x1, // FP Scheduler Empty
		RETIRED_SSE_OPS = 0x3, // Retired SSE/BNI Ops
		RETIRED_SSE_OPS__MASK__AMD64_FAM15H_RETIRED_SSE_OPS__SINGLE_ADD_SUB_OPS = 0x1, // Single-precision add/subtract FLOPS
		RETIRED_SSE_OPS__MASK__AMD64_FAM15H_RETIRED_SSE_OPS__SINGLE_MUL_OPS = 0x2, // Single-precision multiply FLOPS
		RETIRED_SSE_OPS__MASK__AMD64_FAM15H_RETIRED_SSE_OPS__SINGLE_DIV_OPS = 0x4, // Single-precision divide/square root FLOPS
		RETIRED_SSE_OPS__MASK__AMD64_FAM15H_RETIRED_SSE_OPS__SINGLE_MUL_ADD_OPS = 0x8, // Single precision multiply-add FLOPS. Multiply-add counts as 2 FLOPS
		RETIRED_SSE_OPS__MASK__AMD64_FAM15H_RETIRED_SSE_OPS__DOUBLE_ADD_SUB_OPS = 0x10, // Double precision add/subtract FLOPS
		RETIRED_SSE_OPS__MASK__AMD64_FAM15H_RETIRED_SSE_OPS__DOUBLE_MUL_OPS = 0x20, // Double precision multiply FLOPS
		RETIRED_SSE_OPS__MASK__AMD64_FAM15H_RETIRED_SSE_OPS__DOUBLE_DIV_OPS = 0x40, // Double precision divide/square root FLOPS
		RETIRED_SSE_OPS__MASK__AMD64_FAM15H_RETIRED_SSE_OPS__DOUBLE_MUL_ADD_OPS = 0x80, // Double precision multiply-add FLOPS. Multiply-add counts as 2 FLOPS
		RETIRED_SSE_OPS__MASK__AMD64_FAM15H_RETIRED_SSE_OPS__ALL = 0xff, // All sub-events selected
		MOVE_SCALAR_OPTIMIZATION = 0x4, // Number of Move Elimination and Scalar Op Optimization
		MOVE_SCALAR_OPTIMIZATION__MASK__AMD64_FAM15H_MOVE_SCALAR_OPTIMIZATION__SSE_MOVE_OPS = 0x1, // Number of SSE Move Ops
		MOVE_SCALAR_OPTIMIZATION__MASK__AMD64_FAM15H_MOVE_SCALAR_OPTIMIZATION__SSE_MOVE_OPS_ELIM = 0x2, // Number of SSE Move Ops eliminated
		MOVE_SCALAR_OPTIMIZATION__MASK__AMD64_FAM15H_MOVE_SCALAR_OPTIMIZATION__OPT_CAND = 0x4, // Number of Ops that are candidates for optimization (Z-bit set or pass)
		MOVE_SCALAR_OPTIMIZATION__MASK__AMD64_FAM15H_MOVE_SCALAR_OPTIMIZATION__SCALAR_OPS_OPTIMIZED = 0x8, // Number of Scalar ops optimized
		MOVE_SCALAR_OPTIMIZATION__MASK__AMD64_FAM15H_MOVE_SCALAR_OPTIMIZATION__ALL = 0xf, // All sub-events selected
		RETIRED_SERIALIZING_OPS = 0x5, // Retired Serializing Ops
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM15H_RETIRED_SERIALIZING_OPS__SSE_RETIRED = 0x1, // SSE bottom-executing uops retired
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM15H_RETIRED_SERIALIZING_OPS__SSE_MISPREDICTED = 0x2, // SSE control word mispredict traps due to mispredictions
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM15H_RETIRED_SERIALIZING_OPS__X87_RETIRED = 0x4, // X87 bottom-executing uops retired
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM15H_RETIRED_SERIALIZING_OPS__X87_MISPREDICTED = 0x8, // X87 control word mispredict traps due to mispredictions
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM15H_RETIRED_SERIALIZING_OPS__ALL = 0xf, // All sub-events selected
		BOTTOM_EXECUTE_OP = 0x6, // Number of Cycles that a Bottom-Execute uop is in the FP Scheduler
		SEGMENT_REGISTER_LOADS = 0x20, // Segment Register Loads
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM15H_SEGMENT_REGISTER_LOADS__ES = 0x1, // ES
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM15H_SEGMENT_REGISTER_LOADS__CS = 0x2, // CS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM15H_SEGMENT_REGISTER_LOADS__SS = 0x4, // SS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM15H_SEGMENT_REGISTER_LOADS__DS = 0x8, // DS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM15H_SEGMENT_REGISTER_LOADS__FS = 0x10, // FS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM15H_SEGMENT_REGISTER_LOADS__GS = 0x20, // GS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM15H_SEGMENT_REGISTER_LOADS__HS = 0x40, // HS
		SEGMENT_REGISTER_LOADS__MASK__AMD64_FAM15H_SEGMENT_REGISTER_LOADS__ALL = 0x7f, // All sub-events selected
		PIPELINE_RESTART_DUE_TO_SELF_MODIFYING_CODE = 0x21, // Pipeline Restart Due to Self-Modifying Code
		PIPELINE_RESTART_DUE_TO_PROBE_HIT = 0x22, // Pipeline Restart Due to Probe Hit
		LOAD_Q_STORE_Q_FULL = 0x23, // Load Queue/Store Queue Full
		LOAD_Q_STORE_Q_FULL__MASK__AMD64_FAM15H_LOAD_Q_STORE_Q_FULL__LOAD_QUEUE = 0x1, // The number of cycles that the load buffer is full
		LOAD_Q_STORE_Q_FULL__MASK__AMD64_FAM15H_LOAD_Q_STORE_Q_FULL__STORE_QUEUE = 0x2, // The number of cycles that the store buffer is full
		LOAD_Q_STORE_Q_FULL__MASK__AMD64_FAM15H_LOAD_Q_STORE_Q_FULL__ALL = 0x3, // All sub-events selected
		LOCKED_OPS = 0x24, // Locked Operations
		LOCKED_OPS__MASK__AMD64_FAM15H_LOCKED_OPS__EXECUTED = 0x1, // Number of locked instructions executed
		LOCKED_OPS__MASK__AMD64_FAM15H_LOCKED_OPS__CYCLES_NON_SPECULATIVE_PHASE = 0x4, // Number of cycles spent in non-speculative phase
		LOCKED_OPS__MASK__AMD64_FAM15H_LOCKED_OPS__CYCLES_WAITING = 0x8, // Number of cycles spent in non-speculative phase
		LOCKED_OPS__MASK__AMD64_FAM15H_LOCKED_OPS__ALL = 0xd, // All sub-events selected
		RETIRED_CLFLUSH_INSTRUCTIONS = 0x26, // Retired CLFLUSH Instructions
		RETIRED_CPUID_INSTRUCTIONS = 0x27, // Retired CPUID Instructions
		CANCELLED_STORE_TO_LOAD = 0x2a, // Canceled Store to Load Forward Operations
		CANCELLED_STORE_TO_LOAD__MASK__AMD64_FAM15H_CANCELLED_STORE_TO_LOAD__SIZE_ADDRESS_MISMATCHES = 0x1, // Store is smaller than load or different starting byte but partial overlap
		CANCELLED_STORE_TO_LOAD__MASK__AMD64_FAM15H_CANCELLED_STORE_TO_LOAD__ALL = 0x1, // All sub-events selected
		SMIS_RECEIVED = 0x2b, // SMIs Received
		DATA_CACHE_ACCESSES = 0x40, // Data Cache Accesses
		DATA_CACHE_MISSES = 0x41, // Data Cache Misses
		DATA_CACHE_MISSES__MASK__AMD64_FAM15H_DATA_CACHE_MISSES__DC_MISS_STREAMING_STORE = 0x1, // First data cache miss or streaming store to a 64B cache line
		DATA_CACHE_MISSES__MASK__AMD64_FAM15H_DATA_CACHE_MISSES__STREAMING_STORE = 0x2, // First streaming store to a 64B cache line
		DATA_CACHE_MISSES__MASK__AMD64_FAM15H_DATA_CACHE_MISSES__ALL = 0x3, // All sub-events selected
		DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE = 0x42, // Data Cache Refills from L2 or System
		DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__MASK__AMD64_FAM15H_DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__GOOD = 0x1, // Fill with good data. (Final valid status is valid)
		DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__MASK__AMD64_FAM15H_DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__INVALID = 0x2, // Early valid status turned out to be invalid
		DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__MASK__AMD64_FAM15H_DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__POISON = 0x4, // Fill with poison data
		DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__MASK__AMD64_FAM15H_DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__READ_ERROR = 0x8, // Fill with read data error
		DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__MASK__AMD64_FAM15H_DATA_CACHE_REFILLS_FROM_L2_OR_NORTHBRIDGE__ALL = 0xf, // All sub-events selected
		DATA_CACHE_REFILLS_FROM_NORTHBRIDGE = 0x43, // Data Cache Refills from System
		UNIFIED_TLB_HIT = 0x45, // Unified TLB Hit
		UNIFIED_TLB_HIT__MASK__AMD64_FAM15H_UNIFIED_TLB_HIT__4K_DATA = 0x1, // 4 KB unified TLB hit for data
		UNIFIED_TLB_HIT__MASK__AMD64_FAM15H_UNIFIED_TLB_HIT__2M_DATA = 0x2, // 2 MB unified TLB hit for data
		UNIFIED_TLB_HIT__MASK__AMD64_FAM15H_UNIFIED_TLB_HIT__1G_DATA = 0x4, // 1 GB unified TLB hit for data
		UNIFIED_TLB_HIT__MASK__AMD64_FAM15H_UNIFIED_TLB_HIT__4K_INST = 0x10, // 4 KB unified TLB hit for instruction
		UNIFIED_TLB_HIT__MASK__AMD64_FAM15H_UNIFIED_TLB_HIT__2M_INST = 0x20, // 2 MB unified TLB hit for instruction
		UNIFIED_TLB_HIT__MASK__AMD64_FAM15H_UNIFIED_TLB_HIT__1G_INST = 0x40, // 1 GB unified TLB hit for instruction
		UNIFIED_TLB_HIT__MASK__AMD64_FAM15H_UNIFIED_TLB_HIT__ALL = 0x77, // All sub-events selected
		UNIFIED_TLB_MISS = 0x46, // Unified TLB Miss
		UNIFIED_TLB_MISS__MASK__AMD64_FAM15H_UNIFIED_TLB_MISS__4K_DATA = 0x1, // 4 KB unified TLB miss for data
		UNIFIED_TLB_MISS__MASK__AMD64_FAM15H_UNIFIED_TLB_MISS__2M_DATA = 0x2, // 2 MB unified TLB miss for data
		UNIFIED_TLB_MISS__MASK__AMD64_FAM15H_UNIFIED_TLB_MISS__1GB_DATA = 0x4, // 1 GB unified TLB miss for data
		UNIFIED_TLB_MISS__MASK__AMD64_FAM15H_UNIFIED_TLB_MISS__4K_INST = 0x10, // 4 KB unified TLB miss for instruction
		UNIFIED_TLB_MISS__MASK__AMD64_FAM15H_UNIFIED_TLB_MISS__2M_INST = 0x20, // 2 MB unified TLB miss for instruction
		UNIFIED_TLB_MISS__MASK__AMD64_FAM15H_UNIFIED_TLB_MISS__1G_INST = 0x40, // 1 GB unified TLB miss for instruction
		UNIFIED_TLB_MISS__MASK__AMD64_FAM15H_UNIFIED_TLB_MISS__ALL = 0x77, // All sub-events selected
		MISALIGNED_ACCESSES = 0x47, // Misaligned Accesses
		PREFETCH_INSTRUCTIONS_DISPATCHED = 0x4b, // Prefetch Instructions Dispatched
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM15H_PREFETCH_INSTRUCTIONS_DISPATCHED__LOAD = 0x1, // Load (Prefetch
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM15H_PREFETCH_INSTRUCTIONS_DISPATCHED__STORE = 0x2, // Store (PrefetchW)
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM15H_PREFETCH_INSTRUCTIONS_DISPATCHED__NTA = 0x4, // NTA (PrefetchNTA)
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM15H_PREFETCH_INSTRUCTIONS_DISPATCHED__ALL = 0x7, // All sub-events selected
		INEFFECTIVE_SW_PREFETCHES = 0x52, // Ineffective Software Prefetches
		INEFFECTIVE_SW_PREFETCHES__MASK__AMD64_FAM15H_INEFFECTIVE_SW_PREFETCHES__SW_PREFETCH_HIT_IN_L1 = 0x1, // Software prefetch hit in the L1
		INEFFECTIVE_SW_PREFETCHES__MASK__AMD64_FAM15H_INEFFECTIVE_SW_PREFETCHES__SW_PREFETCH_HIT_IN_L2 = 0x8, // Software prefetch hit in the L2
		INEFFECTIVE_SW_PREFETCHES__MASK__AMD64_FAM15H_INEFFECTIVE_SW_PREFETCHES__ALL = 0x9, // All sub-events selected
		MEMORY_REQUESTS = 0x65, // Memory Requests by Type
		MEMORY_REQUESTS__MASK__AMD64_FAM15H_MEMORY_REQUESTS__NON_CACHEABLE = 0x1, // Requests to non-cacheable (UC) memory
		MEMORY_REQUESTS__MASK__AMD64_FAM15H_MEMORY_REQUESTS__WRITE_COMBINING = 0x2, // Requests to non-cacheable (WC
		MEMORY_REQUESTS__MASK__AMD64_FAM15H_MEMORY_REQUESTS__STREAMING_STORE = 0x80, // Requests to non-cacheable (WC+/SS
		MEMORY_REQUESTS__MASK__AMD64_FAM15H_MEMORY_REQUESTS__ALL = 0x83, // All sub-events selected
		DATA_PREFETCHER = 0x67, // Data Prefetcher
		DATA_PREFETCHER__MASK__AMD64_FAM15H_DATA_PREFETCHER__ATTEMPTED = 0x2, // Prefetch attempts
		DATA_PREFETCHER__MASK__AMD64_FAM15H_DATA_PREFETCHER__ALL = 0x2, // All sub-events selected
		MAB_REQS = 0x68, // MAB Requests
		MAB_REQS__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_0 = 0x1, // Buffer entry index bit 0
		MAB_REQS__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_1 = 0x2, // Buffer entry index bit 1
		MAB_REQS__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_2 = 0x4, // Buffer entry index bit 2
		MAB_REQS__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_3 = 0x8, // Buffer entry index bit 3
		MAB_REQS__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_4 = 0x10, // Buffer entry index bit 4
		MAB_REQS__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_5 = 0x20, // Buffer entry index bit 5
		MAB_REQS__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_6 = 0x40, // Buffer entry index bit 6
		MAB_REQS__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_7 = 0x80, // Buffer entry index bit 7
		MAB_REQS__MASK__AMD64_FAM15H_MAB_REQS__ALL = 0xff, // All sub-events selected
		MAB_WAIT = 0x69, // MAB Wait Cycles
		MAB_WAIT__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_0 = 0x1, // Buffer entry index bit 0
		MAB_WAIT__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_1 = 0x2, // Buffer entry index bit 1
		MAB_WAIT__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_2 = 0x4, // Buffer entry index bit 2
		MAB_WAIT__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_3 = 0x8, // Buffer entry index bit 3
		MAB_WAIT__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_4 = 0x10, // Buffer entry index bit 4
		MAB_WAIT__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_5 = 0x20, // Buffer entry index bit 5
		MAB_WAIT__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_6 = 0x40, // Buffer entry index bit 6
		MAB_WAIT__MASK__AMD64_FAM15H_MAB_REQS__BUFFER_BIT_7 = 0x80, // Buffer entry index bit 7
		MAB_WAIT__MASK__AMD64_FAM15H_MAB_REQS__ALL = 0xff, // All sub-events selected
		SYSTEM_READ_RESPONSES = 0x6c, // Response From System on Cache Refills
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM15H_SYSTEM_READ_RESPONSES__EXCLUSIVE = 0x1, // Exclusive
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM15H_SYSTEM_READ_RESPONSES__MODIFIED = 0x2, // 0)
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM15H_SYSTEM_READ_RESPONSES__SHARED = 0x4, // Shared
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM15H_SYSTEM_READ_RESPONSES__OWNED = 0x8, // Owned
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM15H_SYSTEM_READ_RESPONSES__DATA_ERROR = 0x10, // Data Error
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM15H_SYSTEM_READ_RESPONSES__MODIFIED_UNWRITTEN = 0x20, // Modified unwritten
		SYSTEM_READ_RESPONSES__MASK__AMD64_FAM15H_SYSTEM_READ_RESPONSES__ALL = 0x3f, // All sub-events selected
		OCTWORD_WRITE_TRANSFERS = 0x6d, // Octwords Written to System
		OCTWORD_WRITE_TRANSFERS__MASK__AMD64_FAM15H_OCTWORD_WRITE_TRANSFERS__OCTWORD_WRITE_TRANSFER = 0x1, // OW write transfer
		OCTWORD_WRITE_TRANSFERS__MASK__AMD64_FAM15H_OCTWORD_WRITE_TRANSFERS__ALL = 0x1, // All sub-events selected
		CPU_CLK_UNHALTED = 0x76, // CPU Clocks not Halted
		REQUESTS_TO_L2 = 0x7d, // Requests to L2 Cache
		REQUESTS_TO_L2__MASK__AMD64_FAM15H_REQUESTS_TO_L2__INSTRUCTIONS = 0x1, // IC fill
		REQUESTS_TO_L2__MASK__AMD64_FAM15H_REQUESTS_TO_L2__DATA = 0x2, // DC fill
		REQUESTS_TO_L2__MASK__AMD64_FAM15H_REQUESTS_TO_L2__TLB_WALK = 0x4, // TLB fill (page table walks)
		REQUESTS_TO_L2__MASK__AMD64_FAM15H_REQUESTS_TO_L2__SNOOP = 0x8, // NB probe request
		REQUESTS_TO_L2__MASK__AMD64_FAM15H_REQUESTS_TO_L2__CANCELLED = 0x10, // Canceled request
		REQUESTS_TO_L2__MASK__AMD64_FAM15H_REQUESTS_TO_L2__PREFETCHER = 0x40, // L2 cache prefetcher request
		REQUESTS_TO_L2__MASK__AMD64_FAM15H_REQUESTS_TO_L2__ALL = 0x5f, // All sub-events selected
		L2_CACHE_MISS = 0x7e, // L2 Cache Misses
		L2_CACHE_MISS__MASK__AMD64_FAM15H_L2_CACHE_MISS__INSTRUCTIONS = 0x1, // IC fill
		L2_CACHE_MISS__MASK__AMD64_FAM15H_L2_CACHE_MISS__DATA = 0x2, // DC fill (includes possible replays
		L2_CACHE_MISS__MASK__AMD64_FAM15H_L2_CACHE_MISS__TLB_WALK = 0x4, // TLB page table walk
		L2_CACHE_MISS__MASK__AMD64_FAM15H_L2_CACHE_MISS__PREFETCHER = 0x10, // L2 Cache Prefetcher request
		L2_CACHE_MISS__MASK__AMD64_FAM15H_L2_CACHE_MISS__ALL = 0x17, // All sub-events selected
		L2_CACHE_FILL_WRITEBACK = 0x7f, // L2 Fill/Writeback
		L2_CACHE_FILL_WRITEBACK__MASK__AMD64_FAM15H_L2_CACHE_FILL_WRITEBACK__L2_FILLS = 0x1, // L2 fills from system
		L2_CACHE_FILL_WRITEBACK__MASK__AMD64_FAM15H_L2_CACHE_FILL_WRITEBACK__L2_WRITEBACKS = 0x2, // L2 Writebacks to system (Clean and Dirty)
		L2_CACHE_FILL_WRITEBACK__MASK__AMD64_FAM15H_L2_CACHE_FILL_WRITEBACK__L2_WRITEBACKS_CLEAN = 0x4, // L2 Clean Writebacks to system
		L2_CACHE_FILL_WRITEBACK__MASK__AMD64_FAM15H_L2_CACHE_FILL_WRITEBACK__ALL = 0x7, // All sub-events selected
		PAGE_SPLINTERING = 0x165, // Page Splintering
		PAGE_SPLINTERING__MASK__AMD64_FAM15H_PAGE_SPLINTERING__GUEST_LARGER = 0x1, // Guest page size is larger than host page size when nested paging is enabled
		PAGE_SPLINTERING__MASK__AMD64_FAM15H_PAGE_SPLINTERING__MTRR_MISMATCH = 0x2, // Splintering due to MTRRs
		PAGE_SPLINTERING__MASK__AMD64_FAM15H_PAGE_SPLINTERING__HOST_LARGER = 0x4, // Host page size is larger than the guest page size
		PAGE_SPLINTERING__MASK__AMD64_FAM15H_PAGE_SPLINTERING__ALL = 0x7, // All sub-events selected
		INSTRUCTION_CACHE_FETCHES = 0x80, // Instruction Cache Fetches
		INSTRUCTION_CACHE_MISSES = 0x81, // Instruction Cache Misses
		INSTRUCTION_CACHE_REFILLS_FROM_L2 = 0x82, // Instruction Cache Refills from L2
		INSTRUCTION_CACHE_REFILLS_FROM_SYSTEM = 0x83, // Instruction Cache Refills from System
		L1_ITLB_MISS_AND_L2_ITLB_HIT = 0x84, // L1 ITLB Miss
		L1_ITLB_MISS_AND_L2_ITLB_MISS = 0x85, // L1 ITLB Miss
		L1_ITLB_MISS_AND_L2_ITLB_MISS__MASK__AMD64_FAM15H_L1_ITLB_MISS_AND_L2_ITLB_MISS__4K_PAGE_FETCHES = 0x1, // Instruction fetches to a 4 KB page
		L1_ITLB_MISS_AND_L2_ITLB_MISS__MASK__AMD64_FAM15H_L1_ITLB_MISS_AND_L2_ITLB_MISS__2M_PAGE_FETCHES = 0x2, // Instruction fetches to a 2 MB page
		L1_ITLB_MISS_AND_L2_ITLB_MISS__MASK__AMD64_FAM15H_L1_ITLB_MISS_AND_L2_ITLB_MISS__1G_PAGE_FETCHES = 0x4, // Instruction fetches to a 1 GB page
		L1_ITLB_MISS_AND_L2_ITLB_MISS__MASK__AMD64_FAM15H_L1_ITLB_MISS_AND_L2_ITLB_MISS__ALL = 0x7, // All sub-events selected
		PIPELINE_RESTART_DUE_TO_INSTRUCTION_STREAM_PROBE = 0x86, // Pipeline Restart Due to Instruction Stream Probe
		INSTRUCTION_FETCH_STALL = 0x87, // Instruction Fetch Stall
		RETURN_STACK_HITS = 0x88, // Return Stack Hits
		RETURN_STACK_OVERFLOWS = 0x89, // Return Stack Overflows
		INSTRUCTION_CACHE_VICTIMS = 0x8b, // Instruction Cache Victims
		INSTRUCTION_CACHE_INVALIDATED = 0x8c, // Instruction Cache Lines Invalidated
		INSTRUCTION_CACHE_INVALIDATED__MASK__AMD64_FAM15H_INSTRUCTION_CACHE_INVALIDATED__NON_SMC_PROBE_MISS = 0x1, // Non-SMC invalidating probe that missed on in-flight instructions
		INSTRUCTION_CACHE_INVALIDATED__MASK__AMD64_FAM15H_INSTRUCTION_CACHE_INVALIDATED__NON_SMC_PROBE_HIT = 0x2, // Non-SMC invalidating probe that hit on in-flight instructions
		INSTRUCTION_CACHE_INVALIDATED__MASK__AMD64_FAM15H_INSTRUCTION_CACHE_INVALIDATED__SMC_PROBE_MISS = 0x4, // SMC invalidating probe that missed on in-flight instructions
		INSTRUCTION_CACHE_INVALIDATED__MASK__AMD64_FAM15H_INSTRUCTION_CACHE_INVALIDATED__SMC_PROBE_HIT = 0x8, // SMC invalidating probe that hit on in-flight instructions
		INSTRUCTION_CACHE_INVALIDATED__MASK__AMD64_FAM15H_INSTRUCTION_CACHE_INVALIDATED__ALL = 0xf, // All sub-events selected
		ITLB_RELOADS = 0x99, // ITLB Reloads
		ITLB_RELOADS_ABORTED = 0x9a, // ITLB Reloads Aborted
		RETIRED_INSTRUCTIONS = 0xc0, // Retired Instructions
		RETIRED_UOPS = 0xc1, // Retired uops
		RETIRED_BRANCH_INSTRUCTIONS = 0xc2, // Retired Branch Instructions
		RETIRED_MISPREDICTED_BRANCH_INSTRUCTIONS = 0xc3, // Retired Mispredicted Branch Instructions
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS = 0xc4, // Retired Taken Branch Instructions
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xc5, // Retired Taken Branch Instructions Mispredicted
		RETIRED_FAR_CONTROL_TRANSFERS = 0xc6, // Retired Far Control Transfers
		RETIRED_BRANCH_RESYNCS = 0xc7, // Retired Branch Resyncs
		RETIRED_NEAR_RETURNS = 0xc8, // Retired Near Returns
		RETIRED_NEAR_RETURNS_MISPREDICTED = 0xc9, // Retired Near Returns Mispredicted
		RETIRED_INDIRECT_BRANCHES_MISPREDICTED = 0xca, // Retired Indirect Branches Mispredicted
		RETIRED_MMX_FP_INSTRUCTIONS = 0xcb, // Retired MMX/FP Instructions
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM15H_RETIRED_MMX_FP_INSTRUCTIONS__X87 = 0x1, // X87 instructions
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM15H_RETIRED_MMX_FP_INSTRUCTIONS__MMX = 0x2, // MMX(tm) instructions
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM15H_RETIRED_MMX_FP_INSTRUCTIONS__SSE = 0x4, // SSE instructions (SSE
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM15H_RETIRED_MMX_FP_INSTRUCTIONS__ALL = 0x7, // All sub-events selected
		INTERRUPTS_MASKED_CYCLES = 0xcd, // Interrupts-Masked Cycles
		INTERRUPTS_MASKED_CYCLES_WITH_INTERRUPT_PENDING = 0xce, // Interrupts-Masked Cycles with Interrupt Pending
		INTERRUPTS_TAKEN = 0xcf, // Interrupts Taken
		DECODER_EMPTY = 0xd0, // Decoder Empty
		DISPATCH_STALLS = 0xd1, // Dispatch Stalls
		DISPATCH_STALL_FOR_SERIALIZATION = 0xd3, // Microsequencer Stall due to Serialization
		DISPATCH_STALL_FOR_RETIRE_QUEUE_FULL = 0xd5, // Dispatch Stall for Instruction Retire Q Full
		DISPATCH_STALL_FOR_INT_SCHED_QUEUE_FULL = 0xd6, // Dispatch Stall for Integer Scheduler Queue Full
		DISPATCH_STALL_FOR_FPU_FULL = 0xd7, // Dispatch Stall for FP Scheduler Queue Full
		DISPATCH_STALL_FOR_LDQ_FULL = 0xd8, // Dispatch Stall for LDQ Full
		MICROSEQ_STALL_WAITING_FOR_ALL_QUIET = 0xd9, // Microsequencer Stall Waiting for All Quiet
		FPU_EXCEPTIONS = 0xdb, // FPU Exceptions
		FPU_EXCEPTIONS__MASK__AMD64_FAM15H_FPU_EXCEPTIONS__TOTAL_FAULTS = 0x1, // Total microfaults
		FPU_EXCEPTIONS__MASK__AMD64_FAM15H_FPU_EXCEPTIONS__TOTAL_TRAPS = 0x2, // Total microtraps
		FPU_EXCEPTIONS__MASK__AMD64_FAM15H_FPU_EXCEPTIONS__INT2EXT_FAULTS = 0x4, // Int2Ext faults
		FPU_EXCEPTIONS__MASK__AMD64_FAM15H_FPU_EXCEPTIONS__EXT2INT_FAULTS = 0x8, // Ext2Int faults
		FPU_EXCEPTIONS__MASK__AMD64_FAM15H_FPU_EXCEPTIONS__BYPASS_FAULTS = 0x10, // Bypass faults
		FPU_EXCEPTIONS__MASK__AMD64_FAM15H_FPU_EXCEPTIONS__ALL = 0x1f, // All sub-events selected
		DR0_BREAKPOINTS = 0xdc, // DR0 Breakpoint Match
		DR1_BREAKPOINTS = 0xdd, // DR1 Breakpoint Match
		DR2_BREAKPOINTS = 0xde, // DR2 Breakpoint Match
		DR3_BREAKPOINTS = 0xdf, // DR3 Breakpoint Match
		IBS_OPS_TAGGED = 0x1cf, // Tagged IBS Ops
		IBS_OPS_TAGGED__MASK__AMD64_FAM15H_IBS_OPS_TAGGED__TAGGED = 0x1, // Number of ops tagged by IBS
		IBS_OPS_TAGGED__MASK__AMD64_FAM15H_IBS_OPS_TAGGED__RETIRED = 0x2, // Number of ops tagged by IBS that retired
		IBS_OPS_TAGGED__MASK__AMD64_FAM15H_IBS_OPS_TAGGED__IGNORED = 0x4, // Number of times an op could not be tagged by IBS because of a previous tagged op that has not retired
		IBS_OPS_TAGGED__MASK__AMD64_FAM15H_IBS_OPS_TAGGED__ALL = 0x7, // All sub-events selected
		LS_DISPATCH = 0x29, // LS Dispatch
		LS_DISPATCH__MASK__AMD64_FAM15H_LS_DISPATCH__LOADS = 0x1, // Loads
		LS_DISPATCH__MASK__AMD64_FAM15H_LS_DISPATCH__STORES = 0x2, // Stores
		LS_DISPATCH__MASK__AMD64_FAM15H_LS_DISPATCH__LOAD_OP_STORES = 0x4, // Load-op-Stores
		LS_DISPATCH__MASK__AMD64_FAM15H_LS_DISPATCH__ALL = 0x7, // All sub-events selected
		EXECUTED_CLFLUSH_INSTRUCTIONS = 0x30, // Executed CLFLUSH Instructions
		L2_PREFETCHER_TRIGGER_EVENTS = 0x16c, // L2 Prefetcher Trigger Events
		L2_PREFETCHER_TRIGGER_EVENTS__MASK__AMD64_FAM15H_L2_PREFETCHER_TRIGGER_EVENTS__LOAD_L1_MISS_SEEN_BY_PREFETCHER = 0x1, // Load L1 miss seen by prefetcher
		L2_PREFETCHER_TRIGGER_EVENTS__MASK__AMD64_FAM15H_L2_PREFETCHER_TRIGGER_EVENTS__STORE_L1_MISS_SEEN_BY_PREFETCHER = 0x2, // Store L1 miss seen by prefetcher
		L2_PREFETCHER_TRIGGER_EVENTS__MASK__AMD64_FAM15H_L2_PREFETCHER_TRIGGER_EVENTS__ALL = 0x3, // All sub-events selected
		DISPATCH_STALL_FOR_STQ_FULL = 0x1d8, // Dispatch Stall for STQ Full
		
	};
};

namespace fam15h = optkit::amd64::fam15h;