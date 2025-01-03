#pragma once
#include <cstdint>
namespace optkit::amd64::fam17h_zen2{
	enum fam17h_zen2 : uint64_t {
		L1_ITLB_MISS_L2_ITLB_HIT = 0x84, // Number of instruction fetches that miss in the L1 ITLB but hit in the L2 ITLB.
		L1_ITLB_MISS_L2_ITLB_MISS = 0x85, // Number of instruction fetches that miss in both the L1 and L2 TLBs.
		L1_ITLB_MISS_L2_ITLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_ITLB_MISS_L2_ITLB_MISS__IF1G = 0x4, // Number of instruction fetches to a 1GB page
		L1_ITLB_MISS_L2_ITLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_ITLB_MISS_L2_ITLB_MISS__IF2M = 0x2, // Number of instruction fetches to a 2MB page
		L1_ITLB_MISS_L2_ITLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_ITLB_MISS_L2_ITLB_MISS__IF4K = 0x1, // Number of instruction fetches to a 4KB page
		RETIRED_SSE_AVX_FLOPS = 0x3, // This is a retire-based event. The number of retired SSE/AVX FLOPS. The number of events logged per cycle can vary from 0 to 64. This event can count above 15 and therefore requires the MergeEvent. On Linux
		RETIRED_SSE_AVX_FLOPS__MASK__AMD64_FAM17H_ZEN2_RETIRED_SSE_AVX_FLOPS__ADD_SUB_FLOPS = 0x1, // Addition/subtraction FLOPS
		RETIRED_SSE_AVX_FLOPS__MASK__AMD64_FAM17H_ZEN2_RETIRED_SSE_AVX_FLOPS__MULT_FLOPS = 0x2, // Multiplication FLOPS
		RETIRED_SSE_AVX_FLOPS__MASK__AMD64_FAM17H_ZEN2_RETIRED_SSE_AVX_FLOPS__DIV_FLOPS = 0x4, // Division FLOPS.
		RETIRED_SSE_AVX_FLOPS__MASK__AMD64_FAM17H_ZEN2_RETIRED_SSE_AVX_FLOPS__MAC_FLOPS = 0x8, // Double precision add/subtract flops.
		RETIRED_SSE_AVX_FLOPS__MASK__AMD64_FAM17H_ZEN2_RETIRED_SSE_AVX_FLOPS__ANY = 0xf, // Double precision add/subtract flops.
		DIV_CYCLES_BUSY_COUNT = 0xd3, // Number of cycles when the divider is busy.
		DIV_OP_COUNT = 0xd4, // Number of divide uops.
		RETIRED_BRANCH_INSTRUCTIONS = 0xc2, // Number of branch instructions retired. This includes all types of architectural control flow changes
		RETIRED_FAR_CONTROL_TRANSFERS = 0xc6, // Number of far control transfers retired including far call/jump/return
		RETIRED_INDIRECT_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xca, // Number of indirect branches retired there were not correctly predicted. Each such mispredict incurs the same penalty as a mispredicted condition branch instruction. Only EX mispredicts are counted.
		RETIRED_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xc3, // Number of branch instructions retired
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS = 0xc4, // Number of taken branches that were retired. This includes all types of architectural control flow changes
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xc5, // Number of retired taken branch instructions that were mispredicted.
		RETIRED_CONDITIONAL_BRANCH_INSTRUCTIONS = 0xd1, // Number of retired conditional branch instructions.
		RETIRED_UOPS = 0xc1, // Number of uops retired. This includes all processor activity (instructions
		RETIRED_FUSED_INSTRUCTIONS = 0x1d0, // Number of fused retired branch instructions retired per cycle. The number of events logged per cycle can vary from 0 to 3.
		RETIRED_INSTRUCTIONS = 0xc0, // Instructions Retired.
		RETIRED_MMX_FP_INSTRUCTIONS = 0xcb, // Number of MMX
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM17H_ZEN2_RETIRED_MMX_FP_INSTRUCTIONS__SSE_INSTR = 0x4, // Number of SSE instructions (SSE
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM17H_ZEN2_RETIRED_MMX_FP_INSTRUCTIONS__MMX_INSTR = 0x2, // Number of MMX instructions.
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM17H_ZEN2_RETIRED_MMX_FP_INSTRUCTIONS__X87_INSTR = 0x1, // Number of X87 instructions.
		RETIRED_NEAR_RETURNS = 0xc8, // Number of near return instructions (RET or RETI) retired.
		RETIRED_NEAR_RETURNS_MISPREDICTED = 0xc9, // Number of near returns retired that were not correctly predicted by the return address predictor. Each such mispredict incurs the same penalty as a mispredicted conditional branch instruction.
		TAGGED_IBS_OPS = 0x1cf, // TBD
		TAGGED_IBS_OPS__MASK__AMD64_FAM17H_ZEN2_TAGGED_IBS_OPS__IBS_COUNT_ROLLOVER = 0x4, // Number of times a uop could not be tagged by IBS because of a previous tagged uop that has not retired.
		TAGGED_IBS_OPS__MASK__AMD64_FAM17H_ZEN2_TAGGED_IBS_OPS__IBS_TAGGED_OPS_RET = 0x2, // Number of uops tagged by IBS that retired.
		TAGGED_IBS_OPS__MASK__AMD64_FAM17H_ZEN2_TAGGED_IBS_OPS__IBS_TAGGED_OPS = 0x1, // Number of uops tagged by IBS.
		RETIRED_BRANCH_MISPREDICTED_DIRECTION_MISMATCH = 0x1c7, // Number of retired conditional branch instructions that were not correctly predicted because of branch direction mismatch
		INSTRUCTION_CACHE_REFILLS_FROM_L2 = 0x82, // Number of 64-byte instruction cachelines that was fulfilled by the L2 cache.
		INSTRUCTION_CACHE_REFILLS_FROM_SYSTEM = 0x83, // Number of 64-byte instruction cachelines fulfilled from system memory or another cache.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS = 0x64, // L2 cache request outcomes. This event does not count accesses to the L2 cache by the L2 prefetcher.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN2_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_C_S = 0x80, // Number of data cache shared read hitting in the L2.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN2_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_L_HIT_X = 0x40, // Number of data cache reads hitting in the L2.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN2_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_L_HIT_S = 0x20, // Number of data cache reads hitting a shared in line in the L2.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN2_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_X = 0x10, // Number of data cache store or state change (to exclusive) requests hitting in the L2.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN2_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_C = 0x8, // Number of data cache fill requests missing in the L2 (all types).
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN2_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__IC_FILL_HIT_X = 0x4, // Number of I-cache fill requests hitting a modifiable (exclusive) line in the L2.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN2_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__IC_FILL_HIT_S = 0x2, // Number of I-cache fill requests hitting a clean line in the L2.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN2_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__IC_FILL_MISS = 0x1, // Number of I-cache fill requests missing the L2.
		L2_PREFETCH_HIT_L2 = 0x70, // Number of L2 prefetcher hits in the L2
		L2_PREFETCH_HIT_L2__MASK__AMD64_FAM17H_ZEN2_L2_PREFETCH_HIT_L2__ANY = 0x1f, // Any L2 prefetch requests
		L2_PREFETCH_HIT_L3 = 0x71, // Number of L2 prefetcher hits in the L3
		L2_PREFETCH_HIT_L3__MASK__AMD64_FAM17H_ZEN2_L2_PREFETCH_HIT_L2__ANY = 0x1f, // Any L2 prefetch requests
		L2_PREFETCH_MISS_L3 = 0x72, // Number of L2 prefetcher misses in the L3
		L2_PREFETCH_MISS_L3__MASK__AMD64_FAM17H_ZEN2_L2_PREFETCH_HIT_L2__ANY = 0x1f, // Any L2 prefetch requests
		REQUESTS_TO_L2_GROUP1 = 0x60, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP1__RD_BLK_L = 0x80, // Number of data cache reads (including software and hardware prefetches).
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP1__RD_BLK_X = 0x40, // Number of data cache stores
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP1__LS_RD_BLK_C_S = 0x20, // Number of data cache shared reads.
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP1__CACHEABLE_IC_READ = 0x10, // Number of instruction cache reads.
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP1__CHANGE_TO_X = 0x8, // Number of requests change to writable. Check L2 for current state.
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP1__PREFETCH_L2 = 0x4, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP1__L2_HW_PF = 0x2, // Number of prefetches accepted by L2 pipeline
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP1__GROUP2 = 0x1, // Number of miscellaneous requests covered in more details by REQUESTS_TO_L2_GROUP1
		REQUESTS_TO_L2_GROUP2 = 0x61, // Multi-events in that LS and IF requests can be received simultaneous.
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP2__GROUP1 = 0x80, // Number of miscellaneous requests covered in more details by REQUESTS_TO_L2_GROUP2
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP2__LS_RD_SIZED = 0x40, // Number of data cache reads sized.
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP2__LS_RD_SIZED_N_C = 0x20, // Number of data cache reads sized non-cacheable.
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP2__IC_RD_SIZED = 0x10, // Number of instruction cache reads sized.
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP2__IC_RD_SIZED_N_C = 0x8, // Number of instruction cache reads sized non-cacheable.
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP2__SMC_INVAL = 0x4, // Number of self-modifying code invalidates.
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP2__BUS_LOCKS_ORIGINATOR = 0x2, // Number of bus locks.
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN2_REQUESTS_TO_L2_GROUP2__BUS_LOCKS_RESPONSES = 0x1, // Number of bus lock responses.
		BAD_STATUS_2 = 0x24, // TBD
		BAD_STATUS_2__MASK__AMD64_FAM17H_ZEN2_BAD_STATUS_2__STLI_OTHER = 0x2, // Store-to-load conflicts. A load was unable to complete due to a non-forwardable conflict with an older store.
		LS_DISPATCH = 0x29, // Counts the number of operations dispatched to the LS unit. Unit Masks ADDed.
		LS_DISPATCH__MASK__AMD64_FAM17H_ZEN2_LS_DISPATCH__LD_ST_DISPATCH = 0x4, // Load/Store single uops dispatched (compare-and-exchange).
		LS_DISPATCH__MASK__AMD64_FAM17H_ZEN2_LS_DISPATCH__STORE_DISPATCH = 0x2, // Store uops dispatched.
		LS_DISPATCH__MASK__AMD64_FAM17H_ZEN2_LS_DISPATCH__LD_DISPATCH = 0x1, // Load uops dispatched.
		INEFFECTIVE_SOFTWARE_PREFETCH = 0x52, // Number of software prefetches that did not fetch data outside of the processor core.
		INEFFECTIVE_SOFTWARE_PREFETCH__MASK__AMD64_FAM17H_ZEN2_INEFFECTIVE_SOFTWARE_PREFETCH__MAB_MCH_CNT = 0x2, // Software prefetch instructions saw a match on an already allocated miss request buffer.
		INEFFECTIVE_SOFTWARE_PREFETCH__MASK__AMD64_FAM17H_ZEN2_INEFFECTIVE_SOFTWARE_PREFETCH__DATA_PIPE_SW_PF_DC_HIT = 0x1, // Software Prefetch instruction saw a DC hit
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS = 0x59, // Number of software prefetches fills by data source
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MABRESP_LCL_L2 = 0x1, // Fill from local L2.
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_CACHE = 0x2, // Fill from another cache (home node local).
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_DRAM = 0x8, // Fill from DRAM (home node local).
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_RMT_CACHE = 0x10, // Fill from another cache (home node remote).
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_RMT_DRAM = 0x40, // Fill from DRAM (home node remote).
		HARDWARE_PREFETCH_DATA_CACHE_FILLS = 0x5a, // Number of hardware prefetches fills by data source
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MABRESP_LCL_L2 = 0x1, // Fill from local L2.
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_CACHE = 0x2, // Fill from another cache (home node local).
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_DRAM = 0x8, // Fill from DRAM (home node local).
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_RMT_CACHE = 0x10, // Fill from another cache (home node remote).
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_RMT_DRAM = 0x40, // Fill from DRAM (home node remote).
		L1_DTLB_MISS = 0x45, // L1 Data TLB misses.
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_DTLB_MISS__TLB_RELOAD_1G_L2_MISS = 0x80, // Data TLB reload to a 1GB page that missed in the L2 TLB
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_DTLB_MISS__TLB_RELOAD_2M_L2_MISS = 0x40, // Data TLB reload to a 2MB page that missed in the L2 TLB
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_DTLB_MISS__TLB_RELOAD_COALESCED_PAGE_MISS = 0x20, // Data TLB reload to coalesced pages that missed
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_DTLB_MISS__TLB_RELOAD_4K_L2_MISS = 0x10, // Data TLB reload to a 4KB page that missed in the L2 TLB
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_DTLB_MISS__TLB_RELOAD_1G_L2_HIT = 0x8, // Data TLB reload to a 1GB page that hit in the L2 TLB
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_DTLB_MISS__TLB_RELOAD_2M_L2_HIT = 0x4, // Data TLB reload to a 2MB page that hit in the L2 TLB
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_DTLB_MISS__TLB_RELOAD_COALESCED_PAGE_HIT = 0x2, // Data TLB reload to coalesced pages that hit
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN2_L1_DTLB_MISS__TLB_RELOAD_4K_L2_HIT = 0x1, // Data TLB reload to a 4KB page thta hit in the L2 TLB
		RETIRED_LOCK_INSTRUCTIONS = 0x25, // Counts the number of retired locked instructions
		RETIRED_LOCK_INSTRUCTIONS__MASK__AMD64_FAM17H_ZEN2_RETIRED_LOCK_INSTRUCTIONS__CACHEABLE_LOCKS = 0xe, // Lock in cacheable memory region.
		RETIRED_LOCK_INSTRUCTIONS__MASK__AMD64_FAM17H_ZEN2_RETIRED_LOCK_INSTRUCTIONS__BUS_LOCK = 0x1, // Number of bus locks
		RETIRED_CLFLUSH_INSTRUCTIONS = 0x26, // Counts the number of retired non-speculative clflush instructions
		RETIRED_CPUID_INSTRUCTIONS = 0x27, // Counts the number of retired cpuid instructions
		SMI_RECEIVED = 0x2b, // Counts the number system management interrupts (SMI) received
		INTERRUPT_TAKEN = 0x2c, // Counts the number of interrupts taken
		MAB_ALLOCATION_BY_PIPE = 0x41, // TBD
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN2_MAB_ALLOCATION_BY_PIPE__TLB_PIPE_EARLY = 0x10, // TBD
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN2_MAB_ALLOCATION_BY_PIPE__HW_PF = 0x8, // hw_pf
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN2_MAB_ALLOCATION_BY_PIPE__TLB_PIPE_LATE = 0x4, // TBD
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN2_MAB_ALLOCATION_BY_PIPE__ST_PIPE = 0x2, // TBD
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN2_MAB_ALLOCATION_BY_PIPE__DATA_PIPE = 0x1, // TBD
		MISALIGNED_LOADS = 0x47, // Misaligned loads retired
		CYCLES_NOT_IN_HALT = 0x76, // Number of core cycles not in halted state
		TLB_FLUSHES = 0x78, // Number of TLB flushes
		TLB_FLUSHES__MASK__AMD64_FAM17H_ZEN2_TLB_FLUSHES__ALL = 0xff, // ANY TLB flush.
		PREFETCH_INSTRUCTIONS_DISPATCHED = 0x4b, // Software Prefetch Instructions Dispatched. This is a speculative event
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM17H_ZEN2_PREFETCH_INSTRUCTIONS_DISPATCHED__PREFETCH_T0_T1_T2 = 0x1, // Number of prefetcht0
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM17H_ZEN2_PREFETCH_INSTRUCTIONS_DISPATCHED__PREFETCHW = 0x2, // Number of prefetchtw instructions dispatched
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM17H_ZEN2_PREFETCH_INSTRUCTIONS_DISPATCHED__PREFETCHNTA = 0x4, // Number of prefetchtnta instructions dispatched
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM17H_ZEN2_PREFETCH_INSTRUCTIONS_DISPATCHED__ANY = 0x7, // Any prefetch
		STORE_TO_LOAD_FORWARD = 0x35, // Number of STore Lad Forward hits.
		STORE_COMMIT_CANCELS_2 = 0x37, // Number of store commit cancellations
		STORE_COMMIT_CANCELS_2__MASK__AMD64_FAM17H_ZEN2_STORE_COMMIT_CANCELS_2__WCB_FULL = 0x1, // Non cacheable store and the non-cacheable commit buffer is full.
		L1_BTB_CORRECTION = 0x8a, // Number of L1 branch prediction overrides of existing prediction. This is a speculative event.
		L2_BTB_CORRECTION = 0x8b, // Number of L2 branch prediction overrides of existing prediction. This is a speculative event.
		DYNAMIC_INDIRECT_PREDICTIONS = 0x8e, // Number of indirect branch prediction for potential multi-target branch. This is a speculative event.
		DECODER_OVERRIDE_BRANCH_PRED = 0x91, // Number of decoder overrides of existing branch prediction. This is a speculative event.
		ITLB_FETCH_HIT = 0x94, // Instruction fetches that hit in the L1 ITLB
		ITLB_FETCH_HIT__MASK__AMD64_FAM17H_ZEN2_ITLB_FETCH_HIT__IF1G = 0x4, // L1 instruction fetch that hit a 1GB page.
		ITLB_FETCH_HIT__MASK__AMD64_FAM17H_ZEN2_ITLB_FETCH_HIT__IF2M = 0x2, // L1 instruction fetch that hit a 2MB page.
		ITLB_FETCH_HIT__MASK__AMD64_FAM17H_ZEN2_ITLB_FETCH_HIT__IF4K = 0x1, // L1 instruction fetch that hit a 4KB page.
		UOPS_QUEUE_EMPTY = 0xa9, // Cycles where the uops queue is empty
		UOPS_DISPATCHED_FROM_DECODER = 0xaa, // Number of uops dispatched from either the Decoder
		UOPS_DISPATCHED_FROM_DECODER__MASK__AMD64_FAM17H_ZEN2_UOPS_DISPATCHED_FROM_DECODER__DECODER_DISPATCHED = 0x1, // Number of uops dispatched from the Decoder
		UOPS_DISPATCHED_FROM_DECODER__MASK__AMD64_FAM17H_ZEN2_UOPS_DISPATCHED_FROM_DECODER__OPCACHE_DISPATCHED = 0x2, // Number of uops dispatched from the OpCache
		DISPATCH_RESOURCE_STALL_CYCLES_1 = 0xae, // Number of cycles where a dispatch group is valid but does not get dispatched due to a Token Stall
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN2_DISPATCH_RESOURCE_STALL_CYCLES_1__INT_PHY_REG_FILE_RSRC_STALL = 0x1, // Number of cycles stalled due to integer physical register file resource stalls. Applies to all uops that have integer destination register.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN2_DISPATCH_RESOURCE_STALL_CYCLES_1__LOAD_QUEUE_RSRC_STALL = 0x2, // Number of cycles stalled due to load queue resource stalls. Applies to all uops with load semantics.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN2_DISPATCH_RESOURCE_STALL_CYCLES_1__STORE_QUEUE_RSRC_STALL = 0x4, // Number of cycles stalled due to store queue resource stalls. Applies to all uops with store semantics.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN2_DISPATCH_RESOURCE_STALL_CYCLES_1__INT_SCHEDULER_MISC_RSRC_STALL = 0x8, // Number of cycles stalled due to integer scheduler miscellaneous resource stalls.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN2_DISPATCH_RESOURCE_STALL_CYCLES_1__TAKEN_BRANCH_BUFFER_RSRC_STALL = 0x10, // Number of cycles stalled due to taken branch buffer resource stalls.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN2_DISPATCH_RESOURCE_STALL_CYCLES_1__FP_REG_FILE_RSRC_STALL = 0x20, // Number of cycles stalled due to floating-point register file resource stalls.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN2_DISPATCH_RESOURCE_STALL_CYCLES_1__FP_SCHEDULER_FILE_RSRC_STALL = 0x40, // Number of cycles stalled due to floating-point scheduler resource stalls.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN2_DISPATCH_RESOURCE_STALL_CYCLES_1__FP_MISC_FILE_RSRC_STALL = 0x80, // Number of cycles stalled due to floating-point miscellaneous resource unavailable.
		DISPATCH_RESOURCE_STALL_CYCLES_0 = 0xaf, // Number of cycles where a dispatch group is valid but does not get dispatched due to a Token Stall
		DISPATCH_RESOURCE_STALL_CYCLES_0__MASK__AMD64_FAM17H_ZEN2_DISPATCH_RESOURCE_STALL_CYCLES_0__ALU_TOKEN_STALL = 0x8, // Number of cycles ALU tokens total unavailable.
		RETIRED_SERIALIZING_OPS = 0x5, // The number of serializing Ops retired.
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM17H_ZEN2_RETIRED_SERIALIZING_OPS__X87_CTRL_RET = 0x1, // X87 control word mispredict traps due to mispredction in RC or PC
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM17H_ZEN2_RETIRED_SERIALIZING_OPS__X87_BOT_RET = 0x2, // X87 bottom-executing uops retired.
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM17H_ZEN2_RETIRED_SERIALIZING_OPS__SSE_CTRL_RET = 0x4, // SSE control word mispreduct traps due to mispredctions in RC
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM17H_ZEN2_RETIRED_SERIALIZING_OPS__SSE_BOT_RET = 0x8, // SSE bottom-executing uops retired.
		FP_DISPATCH_FAULTS = 0xe, // Floating-point dispatch faults
		FP_DISPATCH_FAULTS__MASK__AMD64_FAM17H_ZEN2_FP_DISPATCH_FAULTS__X87_FILL_FAULT = 0x1, // x87 fill faults
		FP_DISPATCH_FAULTS__MASK__AMD64_FAM17H_ZEN2_FP_DISPATCH_FAULTS__XMM_FILL_FAULT = 0x2, // XMM fill faults
		FP_DISPATCH_FAULTS__MASK__AMD64_FAM17H_ZEN2_FP_DISPATCH_FAULTS__YMM_FILL_FAULT = 0x4, // YMM fill faults
		FP_DISPATCH_FAULTS__MASK__AMD64_FAM17H_ZEN2_FP_DISPATCH_FAULTS__YMM_SPILL_FAULT = 0x8, // YMM spill faults
		FP_DISPATCH_FAULTS__MASK__AMD64_FAM17H_ZEN2_FP_DISPATCH_FAULTS__ANY = 0xf, // Any FP dispatch faults
		DATA_CACHE_REFILLS_FROM_SYSTEM = 0x43, // Demand Data Cache fills by data source
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MABRESP_LCL_L2 = 0x1, // Fill from local L2.
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_CACHE = 0x2, // Fill from another cache (home node local).
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_DRAM = 0x8, // Fill from DRAM (home node local).
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_RMT_CACHE = 0x10, // Fill from another cache (home node remote).
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_FAM17H_ZEN2_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_RMT_DRAM = 0x40, // Fill from DRAM (home node remote).
		
	};
};

namespace fam17h_zen2 = optkit::amd64::fam17h_zen2;