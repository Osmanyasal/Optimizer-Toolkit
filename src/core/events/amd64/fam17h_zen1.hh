#include <cstdint>
namespace optkit::amd64{
	enum class fam17h_zen1 : uint64_t {
		L1_ITLB_MISS_L2_ITLB_HIT = 0x84, // The number of instruction fetches that miss in the L1 ITLB but hit in the L2 ITLB.
		L1_ITLB_MISS_L2_ITLB_MISS = 0x85, // The number of instruction fetches that miss in both the L1 and L2 TLBs.
		L1_ITLB_MISS_L2_ITLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_ITLB_MISS_L2_ITLB_MISS__IF1G = 0x4, // TBD
		L1_ITLB_MISS_L2_ITLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_ITLB_MISS_L2_ITLB_MISS__IF2M = 0x2, // TBD
		L1_ITLB_MISS_L2_ITLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_ITLB_MISS_L2_ITLB_MISS__IF4K = 0x1, // TBD
		PIPELINE_RESTART_DUE_TO_INSTRUCTION_STREAM_PROBE = 0x86, // The number of pipeline restarts caused by invalidating probes that hit on the instruction stream currently being executed. This would happen if the active instruction stream was being modified by another processor in an MP system - typically a highly unlikely event.
		ITLB_RELOADS = 0x99, // The number of ITLB reload requests.
		DIV_CYCLES_BUSY_COUNT = 0xd3, // TBD
		DIV_OP_COUNT = 0xd4, // TBD
		RETIRED_BRANCH_INSTRUCTIONS = 0xc2, // The number of branch instructions retired. This includes all types of architectural control flow changes
		RETIRED_FAR_CONTROL_TRANSFERS = 0xc6, // The number of far control transfers retired including far call/jump/return
		RETIRED_INDIRECT_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xca, // TBD
		RETIRED_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xc3, // The number of branch instructions retired
		RETIRED_BRANCH_RESYNCS = 0xc7, // The number of resync branches. These reflect pipeline restarts due to certain microcode assists and events such as writes to the active instruction stream
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS = 0xc4, // The number of taken branches that were retired. This includes all types of architectural control flow changes
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xc5, // The number of retired taken branch instructions that were mispredicted.
		RETIRED_CONDITIONAL_BRANCH_INSTRUCTIONS = 0xd1, // TBD
		RETIRED_CONDITIONAL_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xd2, // TBD
		RETIRED_UOPS = 0xc1, // The number of uops retired. This includes all processor activity (instructions
		RETIRED_FUSED_BRANCH_INSTRUCTIONS = 0x1d0, // The number of fused retired branch instructions retired per cycle. The number of events logged per cycle can vary from 0 to 3.
		RETIRED_INSTRUCTIONS = 0xc0, // Instructions Retired.
		RETIRED_MMX_FP_INSTRUCTIONS = 0xcb, // The number of MMX
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_MMX_FP_INSTRUCTIONS__SSE_INSTR = 0x4, // TBD
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_MMX_FP_INSTRUCTIONS__MMX_INSTR = 0x2, // TBD
		RETIRED_MMX_FP_INSTRUCTIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_MMX_FP_INSTRUCTIONS__X87_INSTR = 0x1, // TBD
		RETIRED_NEAR_RETURNS = 0xc8, // The number of near return instructions (RET or RETI) retired.
		RETIRED_NEAR_RETURNS_MISPREDICTED = 0xc9, // The number of near returns retired that were not correctly predicted by the return address predictor. Each such mispredict incurs the same penalty as a mispredicted conditional branch instruction.
		TAGGED_IBS_OPS = 0x1cf, // TBD
		TAGGED_IBS_OPS__MASK__AMD64_FAM17H_ZEN1_TAGGED_IBS_OPS__IBS_COUNT_ROLLOVER = 0x4, // Number of times a uop could not be tagged by IBS because of a previous tagged uop that has not retired.
		TAGGED_IBS_OPS__MASK__AMD64_FAM17H_ZEN1_TAGGED_IBS_OPS__IBS_TAGGED_OPS_RET = 0x2, // Number of uops tagged by IBS that retired.
		TAGGED_IBS_OPS__MASK__AMD64_FAM17H_ZEN1_TAGGED_IBS_OPS__IBS_TAGGED_OPS = 0x1, // Number of uops tagged by IBS.
		NUMBER_OF_MOVE_ELIMINATION_AND_SCALAR_OP_OPTIMIZATION = 0x4, // This is a dispatch based speculative event. It is useful for measuring the effectiveness of the Move elimination and Scalar code optimization schemes.
		NUMBER_OF_MOVE_ELIMINATION_AND_SCALAR_OP_OPTIMIZATION__MASK__AMD64_FAM17H_ZEN1_NUMBER_OF_MOVE_ELIMINATION_AND_SCALAR_OP_OPTIMIZATION__OPTIMIZED = 0x8, // Number of scalar ops optimized.
		NUMBER_OF_MOVE_ELIMINATION_AND_SCALAR_OP_OPTIMIZATION__MASK__AMD64_FAM17H_ZEN1_NUMBER_OF_MOVE_ELIMINATION_AND_SCALAR_OP_OPTIMIZATION__OPT_POTENTIAL = 0x4, // Number of ops that are candidates for optimization (have z-bit either set or pass.
		NUMBER_OF_MOVE_ELIMINATION_AND_SCALAR_OP_OPTIMIZATION__MASK__AMD64_FAM17H_ZEN1_NUMBER_OF_MOVE_ELIMINATION_AND_SCALAR_OP_OPTIMIZATION__SSE_MOV_OPS_ELIM = 0x2, // Number of SSE move ops eliminated.
		NUMBER_OF_MOVE_ELIMINATION_AND_SCALAR_OP_OPTIMIZATION__MASK__AMD64_FAM17H_ZEN1_NUMBER_OF_MOVE_ELIMINATION_AND_SCALAR_OP_OPTIMIZATION__SSE_MOV_OPS = 0x1, // Number of SSE move ops.
		RETIRED_SSE_AVX_OPERATIONS = 0x3, // This is a retire-based event. The number of retired SSE/AVX FLOPS. The number of events logged per cycle can vary from 0 to 64. This event can count above 15.
		RETIRED_SSE_AVX_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SSE_AVX_OPERATIONS__DP_MULT_ADD_FLOPS = 0x80, // Double precision multiply-add flops.
		RETIRED_SSE_AVX_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SSE_AVX_OPERATIONS__DP_DIV_FLOPS = 0x40, // Double precision divide/square root flops.
		RETIRED_SSE_AVX_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SSE_AVX_OPERATIONS__DP_MULT_FLOPS = 0x20, // Double precision multiply flops.
		RETIRED_SSE_AVX_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SSE_AVX_OPERATIONS__DP_ADD_SUB_FLOPS = 0x10, // Double precision add/subtract flops.
		RETIRED_SSE_AVX_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SSE_AVX_OPERATIONS__SP_MULT_ADD_FLOPS = 0x8, // Single precision multiply-add flops.
		RETIRED_SSE_AVX_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SSE_AVX_OPERATIONS__SP_DIV_FLOPS = 0x4, // Single precision divide/square root flops.
		RETIRED_SSE_AVX_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SSE_AVX_OPERATIONS__SP_MULT_FLOPS = 0x2, // Single precision multiply flops.
		RETIRED_SSE_AVX_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SSE_AVX_OPERATIONS__SP_ADD_SUB_FLOPS = 0x1, // Single precision add/subtract flops.
		RETIRED_SERIALIZING_OPS = 0x5, // The number of serializing Ops retired.
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SERIALIZING_OPS__X87_CTRL_RET = 0x8, // X87 control word mispredict traps due to mispredction in RC or PC
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SERIALIZING_OPS__X87_BOT_RET = 0x4, // X87 bottom-executing uops retired.
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SERIALIZING_OPS__SSE_CTRL_RET = 0x2, // SSE control word mispreduct traps due to mispredctions in RC
		RETIRED_SERIALIZING_OPS__MASK__AMD64_FAM17H_ZEN1_RETIRED_SERIALIZING_OPS__SSE_BOT_RET = 0x1, // SSE bottom-executing uops retired.
		RETIRED_X87_FLOATING_POINT_OPERATIONS = 0x2, // The number of x87 floating-point Ops that have retired. The number of events logged per cycle can vary from 0 to 8.
		RETIRED_X87_FLOATING_POINT_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_X87_FLOATING_POINT_OPERATIONS__DIV_SQR_R_OPS = 0x4, // Divide and square root ops
		RETIRED_X87_FLOATING_POINT_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_X87_FLOATING_POINT_OPERATIONS__MUL_OPS = 0x2, // Multiple ops
		RETIRED_X87_FLOATING_POINT_OPERATIONS__MASK__AMD64_FAM17H_ZEN1_RETIRED_X87_FLOATING_POINT_OPERATIONS__ADD_SUB_OPS = 0x1, // Add/subtract ops
		FP_SCHEDULER_EMPTY = 0x1, // This is a speculative event. The number of cycles in which the FPU scheduler is empty. Note that some Ops like FP loads bypass the scheduler. Invert this to count cycles in which at least one FPU operation is present in the FPU.
		FPU_PIPE_ASSIGNMENT = 0x0, // The number of operations (uOps) and dual-pipe uOps dispatched to each of the 4 FPU execution pipelines. This event reflects how busy the FPU pipelines are and may be used for workload characterization. This includes all operations performed by x87
		FPU_PIPE_ASSIGNMENT__MASK__AMD64_FAM17H_ZEN1_FPU_PIPE_ASSIGNMENT__DUAL3 = 0x80, // Total number of multi-pipe uops assigned to pipe3
		FPU_PIPE_ASSIGNMENT__MASK__AMD64_FAM17H_ZEN1_FPU_PIPE_ASSIGNMENT__DUAL2 = 0x40, // Total number of multi-pipe uops assigned to pipe2
		FPU_PIPE_ASSIGNMENT__MASK__AMD64_FAM17H_ZEN1_FPU_PIPE_ASSIGNMENT__DUAL1 = 0x20, // Total number of multi-pipe uops assigned to pipe1
		FPU_PIPE_ASSIGNMENT__MASK__AMD64_FAM17H_ZEN1_FPU_PIPE_ASSIGNMENT__DUAL0 = 0x10, // Total number of multi-pipe uops assigned to pipe0
		FPU_PIPE_ASSIGNMENT__MASK__AMD64_FAM17H_ZEN1_FPU_PIPE_ASSIGNMENT__TOTAL3 = 0x8, // Total number of uops assigned to pipe3
		FPU_PIPE_ASSIGNMENT__MASK__AMD64_FAM17H_ZEN1_FPU_PIPE_ASSIGNMENT__TOTAL2 = 0x4, // Total number of uops assigned to pipe2
		FPU_PIPE_ASSIGNMENT__MASK__AMD64_FAM17H_ZEN1_FPU_PIPE_ASSIGNMENT__TOTAL1 = 0x2, // Total number of uops assigned to pipe1
		FPU_PIPE_ASSIGNMENT__MASK__AMD64_FAM17H_ZEN1_FPU_PIPE_ASSIGNMENT__TOTAL0 = 0x1, // Total number of uops assigned to pipe0
		INSTRUCTION_CACHE_REFILLS_FROM_L2 = 0x82, // The number of 64-byte instruction cachelines that was fulfilled by the L2 cache.
		INSTRUCTION_CACHE_REFILLS_FROM_SYSTEM = 0x83, // The number of 64-byte instruction cachelines fulfilled from system memory or another cache.
		INSTRUCTION_CACHE_LINES_INVALIDATED = 0x8c, // The number of instruction cachelines invalidated. A non-SMC event is CMC (cross modifying code)
		INSTRUCTION_CACHE_LINES_INVALIDATED__MASK__AMD64_FAM17H_ZEN1_INSTRUCTION_CACHE_LINES_INVALIDATED__L2_INVALIDATING_PROBE = 0x2, // IC line invalidated due to L2 invalidating probe (external or LS).
		INSTRUCTION_CACHE_LINES_INVALIDATED__MASK__AMD64_FAM17H_ZEN1_INSTRUCTION_CACHE_LINES_INVALIDATED__FILL_INVALIDATED = 0x1, // IC line invalidated due to overwriting fill response.
		INSTRUCTION_PIPE_STALL = 0x87, // TBD
		INSTRUCTION_PIPE_STALL__MASK__AMD64_FAM17H_ZEN1_INSTRUCTION_PIPE_STALL__IC_STALL_ANY = 0x4, // IC pipe was stalled during this clock cycle for any reason (nothing valud in pipe ICM1).
		INSTRUCTION_PIPE_STALL__MASK__AMD64_FAM17H_ZEN1_INSTRUCTION_PIPE_STALL__IC_STALL_DQ_EMPTY = 0x2, // IC pipe was stalled during this clock cycle (including IC to OC fetches) due to DQ empty.
		INSTRUCTION_PIPE_STALL__MASK__AMD64_FAM17H_ZEN1_INSTRUCTION_PIPE_STALL__IC_STALL_BACK_PRESSURE = 0x1, // IC pipe was stalled during this clock cycle (ncluding IC to OC fetches) due to back pressure.
		_32_BYTE_INSTRUCTION_CACHE_FETCH = 0x80, // The number of 32B fetch windows transferred from IC pipe to DE instruction decoder (includes non-cacheable and cacheable fill responses).
		_32_BYTE_INSTRUCTION_CACHE_MISSES = 0x81, // The number of 32B fetch windows tried to read the L1 IC and missed in the full tag.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS = 0x64, // This event does not count accesses to the L2 cache by the L2 prefetcher
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN1_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_C_S = 0x80, // Load/Store ReadBlock C/S hit
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN1_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_L_HIT_X = 0x40, // Load/Store Readblock L hit eXclusive.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN1_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_L_HIT_S = 0x20, // Load/Store ReadBlock L hit Shared.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN1_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_X = 0x10, // Load/Store ReadblockX/ChangeToX hit eXclusive.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN1_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__LS_RD_BLK_C = 0x8, // Load/Store ReadBlock C S L X Change To X Miss.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN1_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__IC_FILL_HIT_X = 0x4, // Icache fill hit eXclusive.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN1_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__IC_FILL_HIT_S = 0x2, // Icache fill hit Shared.
		CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__MASK__AMD64_FAM17H_ZEN1_CORE_TO_L2_CACHEABLE_REQUEST_ACCESS_STATUS__IC_FILL_MISS = 0x1, // Icache fill miss.
		CYCLES_WITH_FILL_PENDING_FROM_L2 = 0x6d, // Total cycles spent with one or more fill requests in flight from L2.
		CYCLES_WITH_FILL_PENDING_FROM_L2__MASK__AMD64_FAM17H_ZEN1_CYCLES_WITH_FILL_PENDING_FROM_L2__L2_FILL_BUSY = 0x1, // TBD
		L2_LATENCY = 0x62, // Total cycles spent waiting for L2 fills to complete from L3 or memory
		L2_LATENCY__MASK__AMD64_FAM17H_ZEN1_L2_LATENCY__L2_CYCLES_WAITING_ON_FILLS = 0x1, // TBD
		REQUESTS_TO_L2_GROUP1 = 0x60, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP1__RD_BLK_L = 0x80, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP1__RD_BLK_X = 0x40, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP1__LS_RD_BLK_C_S = 0x20, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP1__CACHEABLE_IC_READ = 0x10, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP1__CHANGE_TO_X = 0x8, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP1__PREFETCH_L2 = 0x4, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP1__L2_HW_PF = 0x2, // TBD
		REQUESTS_TO_L2_GROUP1__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP1__OTHER_REQUESTS = 0x1, // TBD
		REQUESTS_TO_L2_GROUP2 = 0x61, // Multi-events in that LS and IF requests can be received simultaneous.
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP2__GROUP1 = 0x80, // TBD
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP2__LS_RD_SIZED = 0x40, // TBD
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP2__LS_RD_SIZED_N_C = 0x20, // TBD
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP2__IC_RD_SIZED = 0x10, // TBD
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP2__IC_RD_SIZED_N_C = 0x8, // TBD
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP2__SMC_INVAL = 0x4, // TBD
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP2__BUS_LOCKS_ORIGINATOR = 0x2, // TBD
		REQUESTS_TO_L2_GROUP2__MASK__AMD64_FAM17H_ZEN1_REQUESTS_TO_L2_GROUP2__BUS_LOCKS_RESPONSES = 0x1, // TBD
		LS_TO_L2_WBC_REQUESTS = 0x63, // TBD
		LS_TO_L2_WBC_REQUESTS__MASK__AMD64_FAM17H_ZEN1_LS_TO_L2_WBC_REQUESTS__WCB_WRITE = 0x40, // TBD
		LS_TO_L2_WBC_REQUESTS__MASK__AMD64_FAM17H_ZEN1_LS_TO_L2_WBC_REQUESTS__WCB_CLOSE = 0x20, // TBD
		LS_TO_L2_WBC_REQUESTS__MASK__AMD64_FAM17H_ZEN1_LS_TO_L2_WBC_REQUESTS__CACHE_LINE_FLUSH = 0x10, // TBD
		LS_TO_L2_WBC_REQUESTS__MASK__AMD64_FAM17H_ZEN1_LS_TO_L2_WBC_REQUESTS__I_LINE_FLUSH = 0x8, // TBD
		LS_TO_L2_WBC_REQUESTS__MASK__AMD64_FAM17H_ZEN1_LS_TO_L2_WBC_REQUESTS__ZERO_BYTE_STORE = 0x4, // TBD
		LS_TO_L2_WBC_REQUESTS__MASK__AMD64_FAM17H_ZEN1_LS_TO_L2_WBC_REQUESTS__LOCAL_IC_CLR = 0x2, // TBD
		LS_TO_L2_WBC_REQUESTS__MASK__AMD64_FAM17H_ZEN1_LS_TO_L2_WBC_REQUESTS__C_L_ZERO = 0x1, // TBD
		DATA_CACHE_ACCESSES = 0x40, // The number of accesses to the data cache for load and store references. This may include certain microcode scratchpad accesses
		LS_DISPATCH = 0x29, // Counts the number of operations dispatched to the LS unit. Unit Masks ADDed.
		LS_DISPATCH__MASK__AMD64_FAM17H_ZEN1_LS_DISPATCH__LD_ST_DISPATCH = 0x4, // Load/Store uops dispatched.
		LS_DISPATCH__MASK__AMD64_FAM17H_ZEN1_LS_DISPATCH__STORE_DISPATCH = 0x2, // Store uops dispatched.
		LS_DISPATCH__MASK__AMD64_FAM17H_ZEN1_LS_DISPATCH__LD_DISPATCH = 0x1, // Load uops dispatched.
		INEFFECTIVE_SOFTWARE_PREFETCH = 0x52, // The number of software prefetches that did not fetch data outside of the processor core.
		INEFFECTIVE_SOFTWARE_PREFETCH__MASK__AMD64_FAM17H_ZEN1_INEFFECTIVE_SOFTWARE_PREFETCH__MAB_MCH_CNT = 0x2, // TBD
		INEFFECTIVE_SOFTWARE_PREFETCH__MASK__AMD64_FAM17H_ZEN1_INEFFECTIVE_SOFTWARE_PREFETCH__DATA_PIPE_SW_PF_DC_HIT = 0x1, // TBD
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS = 0x59, // Number of software prefetches fills by data source
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MABRESP_LCL_L2 = 0x1, // Fill from local L2.
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_CACHE = 0x2, // Fill from another cache (home node local).
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_DRAM = 0x8, // Fill from DRAM (home node local).
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_RMT_CACHE = 0x10, // Fill from another cache (home node remote).
		SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_RMT_DRAM = 0x40, // Fill from DRAM (home node remote).
		HARDWARE_PREFETCH_DATA_CACHE_FILLS = 0x5a, // Number of hardware prefetches fills by data source
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__MABRESP_LCL_L2 = 0x1, // Fill from local L2.
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_CACHE = 0x2, // Fill from another cache (home node local).
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_DRAM = 0x8, // Fill from DRAM (home node local).
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_RMT_CACHE = 0x10, // Fill from another cache (home node remote).
		HARDWARE_PREFETCH_DATA_CACHE_FILLS__MASK__AMD64_FAM17H_ZEN1_SOFTWARE_PREFETCH_DATA_CACHE_FILLS__LS_MABRESP_LCL_RMT_DRAM = 0x40, // Fill from DRAM (home node remote).
		L1_DTLB_MISS = 0x45, // L1 Data TLB misses.
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_DTLB_MISS__TLB_RELOAD_1G_L2_MISS = 0x80, // TBD
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_DTLB_MISS__TLB_RELOAD_2M_L2_MISS = 0x40, // TBD
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_DTLB_MISS__TLB_RELOAD_COALESCED_PAGE_MISS = 0x20, // TBD
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_DTLB_MISS__TLB_RELOAD_4K_L2_MISS = 0x10, // TBD
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_DTLB_MISS__TLB_RELOAD_1G_L2_HIT = 0x8, // TBD
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_DTLB_MISS__TLB_RELOAD_2M_L2_HIT = 0x4, // TBD
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_DTLB_MISS__TLB_RELOAD_COALESCED_PAGE_HIT = 0x2, // TBD
		L1_DTLB_MISS__MASK__AMD64_FAM17H_ZEN1_L1_DTLB_MISS__TLB_RELOAD_4K_L2_HIT = 0x1, // TBD
		LOCKS = 0x25, // Lock operations. Unit masks ORed
		LOCKS__MASK__AMD64_FAM17H_ZEN1_LOCKS__SPEC_LOCK_MAP_COMMIT = 0x8, // TBD
		LOCKS__MASK__AMD64_FAM17H_ZEN1_LOCKS__SPEC_LOCK = 0x4, // TBD
		LOCKS__MASK__AMD64_FAM17H_ZEN1_LOCKS__NON_SPEC_LOCK = 0x2, // TBD
		LOCKS__MASK__AMD64_FAM17H_ZEN1_LOCKS__BUS_LOCK = 0x1, // TBD
		MAB_ALLOCATION_BY_PIPE = 0x41, // TBD
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN1_MAB_ALLOCATION_BY_PIPE__TLB_PIPE_EARLY = 0x10, // TBD
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN1_MAB_ALLOCATION_BY_PIPE__HW_PF = 0x8, // hw_pf
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN1_MAB_ALLOCATION_BY_PIPE__TLB_PIPE_LATE = 0x4, // TBD
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN1_MAB_ALLOCATION_BY_PIPE__ST_PIPE = 0x2, // TBD
		MAB_ALLOCATION_BY_PIPE__MASK__AMD64_FAM17H_ZEN1_MAB_ALLOCATION_BY_PIPE__DATA_PIPE = 0x1, // TBD
		MISALIGNED_LOADS = 0x47, // TBD
		CYCLES_NOT_IN_HALT = 0x76, // TBD
		PREFETCH_INSTRUCTIONS_DISPATCHED = 0x4b, // Software Prefetch Instructions Dispatched.
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM17H_ZEN1_PREFETCH_INSTRUCTIONS_DISPATCHED__PREFETCH_NTA = 0x4, // Non-temporal prefetches.
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM17H_ZEN1_PREFETCH_INSTRUCTIONS_DISPATCHED__STORE_PREFETCH_W = 0x2, // TBD
		PREFETCH_INSTRUCTIONS_DISPATCHED__MASK__AMD64_FAM17H_ZEN1_PREFETCH_INSTRUCTIONS_DISPATCHED__LOAD_PREFETCH_W = 0x1, // TBD
		STORE_TO_LOAD_FORWARD = 0x35, // Number of STore Lad Forward hits.
		TABLEWALKER_ALLOCATION = 0x46, // TBD
		TABLEWALKER_ALLOCATION__MASK__AMD64_FAM17H_ZEN1_TABLEWALKER_ALLOCATION__ALLOC_ISIDE1 = 0x8, // TBD
		TABLEWALKER_ALLOCATION__MASK__AMD64_FAM17H_ZEN1_TABLEWALKER_ALLOCATION__ALLOC_ISIDE0 = 0x4, // TBD
		TABLEWALKER_ALLOCATION__MASK__AMD64_FAM17H_ZEN1_TABLEWALKER_ALLOCATION__ALLOC_DSIDE1 = 0x2, // TBD
		TABLEWALKER_ALLOCATION__MASK__AMD64_FAM17H_ZEN1_TABLEWALKER_ALLOCATION__ALLOC_DSIDE0 = 0x1, // TBD
		L1_BTB_CORRECTION = 0x8a, // TBD
		L2_BTB_CORRECTION = 0x8b, // TBD
		OC_MODE_SWITCH = 0x28a, // TBD
		OC_MODE_SWITCH__MASK__AMD64_FAM17H_ZEN1_OC_MODE_SWITCH__OC_IC_MODE_SWITCH = 0x2, // TBD
		OC_MODE_SWITCH__MASK__AMD64_FAM17H_ZEN1_OC_MODE_SWITCH__IC_OC_MODE_SWITCH = 0x1, // TBD
		DYNAMIC_TOKENS_DISPATCH_STALLS_CYCLES_0 = 0xaf, // Cycles where a dispatch group is valid but does not get dispatched due to a token stall.
		DYNAMIC_TOKENS_DISPATCH_STALLS_CYCLES_0__MASK__AMD64_FAM17H_ZEN1_DYNAMIC_TOKENS_DISPATCH_STALL_CYCLES_0__RETIRE_TOKEN_STALL = 0x40, // Retire tokens unavailable
		DYNAMIC_TOKENS_DISPATCH_STALLS_CYCLES_0__MASK__AMD64_FAM17H_ZEN1_DYNAMIC_TOKENS_DISPATCH_STALL_CYCLES_0__AGSQ_TOKEN_STALL = 0x20, // AGSQ tokens unavailable
		DYNAMIC_TOKENS_DISPATCH_STALLS_CYCLES_0__MASK__AMD64_FAM17H_ZEN1_DYNAMIC_TOKENS_DISPATCH_STALL_CYCLES_0__ALU_TOKEN_STALL = 0x10, // ALU tokens unavailable
		DYNAMIC_TOKENS_DISPATCH_STALLS_CYCLES_0__MASK__AMD64_FAM17H_ZEN1_DYNAMIC_TOKENS_DISPATCH_STALL_CYCLES_0__ALSQ3_0_TOKEN_STALL = 0x8, // TBD
		DYNAMIC_TOKENS_DISPATCH_STALLS_CYCLES_0__MASK__AMD64_FAM17H_ZEN1_DYNAMIC_TOKENS_DISPATCH_STALL_CYCLES_0__ALSQ3_TOKEN_STALL = 0x4, // ALSQ3 tokens unavailable
		DYNAMIC_TOKENS_DISPATCH_STALLS_CYCLES_0__MASK__AMD64_FAM17H_ZEN1_DYNAMIC_TOKENS_DISPATCH_STALL_CYCLES_0__ALSQ2_TOKEN_STALL = 0x2, // ALSQ2 tokens unavailable
		DYNAMIC_TOKENS_DISPATCH_STALLS_CYCLES_0__MASK__AMD64_FAM17H_ZEN1_DYNAMIC_TOKENS_DISPATCH_STALL_CYCLES_0__ALSQ1_TOKEN_STALL = 0x1, // ALSQ1 tokens unavailable
		UOPS_DISPATCHED_FROM_DECODER = 0xaa, // Number of uops dispatched from either the Decoder
		UOPS_DISPATCHED_FROM_DECODER__MASK__AMD64_FAM17H_ZEN1_UOPS_DISPATCHED_FROM_DECODER__DECODER_DISPATCHED = 0x1, // Number of uops dispatched from the Decoder
		UOPS_DISPATCHED_FROM_DECODER__MASK__AMD64_FAM17H_ZEN1_UOPS_DISPATCHED_FROM_DECODER__OPCACHE_DISPATCHED = 0x2, // Number of uops dispatched from the OpCache
		DISPATCH_RESOURCE_STALL_CYCLES_1 = 0xae, // Number of cycles where a dispatch group is valid but does not get dispatched due to a Token Stall
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN1_DISPATCH_RESOURCE_STALL_CYCLES_1__INT_PHY_REG_FILE_RSRC_STALL = 0x1, // Number of cycles stalled due to integer physical register file resource stalls. Applies to all uops that have integer destination register.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN1_DISPATCH_RESOURCE_STALL_CYCLES_1__LOAD_QUEUE_RSRC_STALL = 0x2, // Number of cycles stalled due to load queue resource stalls. Applies to all uops with load semantics.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN1_DISPATCH_RESOURCE_STALL_CYCLES_1__STORE_QUEUE_RSRC_STALL = 0x4, // Number of cycles stalled due to store queue resource stalls. Applies to all uops with store semantics.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN1_DISPATCH_RESOURCE_STALL_CYCLES_1__INT_SCHEDULER_MISC_RSRC_STALL = 0x8, // Number of cycles stalled due to integer scheduler miscellaneous resource stalls.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN1_DISPATCH_RESOURCE_STALL_CYCLES_1__TAKEN_BRANCH_BUFFER_RSRC_STALL = 0x10, // Number of cycles stalled due to taken branch buffer resource stalls.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN1_DISPATCH_RESOURCE_STALL_CYCLES_1__FP_REG_FILE_RSRC_STALL = 0x20, // Number of cycles stalled due to floating-point register file resource stalls.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN1_DISPATCH_RESOURCE_STALL_CYCLES_1__FP_SCHEDULER_FILE_RSRC_STALL = 0x40, // Number of cycles stalled due to floating-point scheduler resource stalls.
		DISPATCH_RESOURCE_STALL_CYCLES_1__MASK__AMD64_FAM17H_ZEN1_DISPATCH_RESOURCE_STALL_CYCLES_1__FP_MISC_FILE_RSRC_STALL = 0x80, // Number of cycles stalled due to floating-point miscellaneous resource unavailable.
		L2_PREFETCH_HIT_L2 = 0x70, // Number of L2 prefetcher hits in the L2
		L2_PREFETCH_HIT_L2__MASK__AMD64_FAM17H_ZEN1_L2_PREFETCH_HIT_L2__ANY = 0x3f, // Any L2 prefetch requests
		L2_PREFETCH_HIT_L3 = 0x71, // Number of L2 prefetcher hits in the L3
		L2_PREFETCH_HIT_L3__MASK__AMD64_FAM17H_ZEN1_L2_PREFETCH_HIT_L2__ANY = 0x3f, // Any L2 prefetch requests
		L2_PREFETCH_MISS_L3 = 0x72, // Number of L2 prefetcher misses in the L3
		L2_PREFETCH_MISS_L3__MASK__AMD64_FAM17H_ZEN1_L2_PREFETCH_HIT_L2__ANY = 0x3f, // Any L2 prefetch requests
		DYNAMIC_INDIRECT_PREDICTIONS = 0x8e, // Indirect Branch Prediction for potential multi-target branch (speculative)
		DECODER_OVERRIDES_PREDICTION = 0x91, // Decoder Overrides Existing Branch Prediction (speculative)
		
	};
};