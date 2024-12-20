#pragma once
#include <cstdint>
namespace optkit::ibm::power7{
	enum power7 : uint64_t {
		PM_IC_DEMAND_L2_BR_ALL = 0x4898, // L2 I cache demand request due to BHT or redirect
		PM_GCT_UTIL_7_TO_10_SLOTS = 0x20a0, // GCT Utilization 7-10 entries
		PM_PMC2_SAVED = 0x10022, // PMC2 Rewind Value saved
		PM_CMPLU_STALL_DFU = 0x2003c, // Completion stall caused by Decimal Floating Point Unit
		PM_VSU0_16FLOP = 0xa0a4, // Sixteen flops operation (SP vector versions of fdiv
		PM_MRK_LSU_DERAT_MISS = 0x3d05a, // Marked DERAT Miss
		PM_MRK_ST_CMPL = 0x10034, // marked  store finished (was complete)
		PM_NEST_PAIR3_ADD = 0x40881, // Nest events (MC0/MC1/PB/GX)
		PM_L2_ST_DISP = 0x46180, // All successful store dispatches
		PM_L2_CASTOUT_MOD = 0x16180, // L2 Castouts - Modified (M
		PM_ISEG = 0x20a4, // ISEG Exception
		PM_MRK_INST_TIMEO = 0x40034, // marked Instruction finish timeout
		PM_L2_RCST_DISP_FAIL_ADDR = 0x36282, // L2  RC store dispatch attempt failed due to address collision with RC/CO/SN/SQ
		PM_LSU1_DC_PREF_STREAM_CONFIRM = 0xd0b6, // LS1 'Dcache prefetch stream confirmed
		PM_IERAT_WR_64K = 0x40be, // large page 64k
		PM_MRK_DTLB_MISS_16M = 0x4d05e, // Marked Data TLB misses for 16M page
		PM_IERAT_MISS = 0x100f6, // IERAT Miss (Not implemented as DI on POWER6)
		PM_MRK_PTEG_FROM_LMEM = 0x4d052, // Marked PTEG loaded from local memory
		PM_FLOP = 0x100f4, // Floating Point Operation Finished
		PM_THRD_PRIO_4_5_CYC = 0x40b4, // Cycles thread running at priority level 4 or 5
		PM_BR_PRED_TA = 0x40aa, // Branch predict - target address
		PM_CMPLU_STALL_FXU = 0x20014, // Completion stall caused by FXU instruction
		PM_EXT_INT = 0x200f8, // external interrupt
		PM_VSU_FSQRT_FDIV = 0xa888, // four flops operation (fdiv
		PM_MRK_LD_MISS_EXPOSED_CYC = 0x1003e, // Marked Load exposed Miss
		PM_LSU1_LDF = 0xc086, // LS1  Scalar Loads
		PM_IC_WRITE_ALL = 0x488c, // Icache sectors written
		PM_LSU0_SRQ_STFWD = 0xc0a0, // LS0 SRQ forwarded data to a load
		PM_PTEG_FROM_RL2L3_MOD = 0x1c052, // PTEG loaded from remote L2 or L3 modified
		PM_MRK_DATA_FROM_L31_SHR = 0x1d04e, // Marked data loaded from another L3 on same chip shared
		PM_DATA_FROM_L21_MOD = 0x3c046, // Data loaded from another L2 on same chip modified
		PM_VSU1_SCAL_DOUBLE_ISSUED = 0xb08a, // Double Precision scalar instruction issued on Pipe1
		PM_VSU0_8FLOP = 0xa0a0, // eight flops operation (DP vector versions of fdiv
		PM_POWER_EVENT1 = 0x1006e, // Power Management Event 1
		PM_DISP_CLB_HELD_BAL = 0x2092, // Dispatch/CLB Hold: Balance
		PM_VSU1_2FLOP = 0xa09a, // two flops operation (scalar fmadd
		PM_LWSYNC_HELD = 0x209a, // LWSYNC held at dispatch
		PM_PTEG_FROM_DL2L3_SHR = 0x3c054, // PTEG loaded from remote L2 or L3 shared
		PM_INST_FROM_L21_MOD = 0x34046, // Instruction fetched from another L2 on same chip modified
		PM_IERAT_XLATE_WR_16MPLUS = 0x40bc, // large page 16M+
		PM_IC_REQ_ALL = 0x4888, // Icache requests
		PM_DSLB_MISS = 0xd090, // Data SLB Miss - Total of all segment sizes
		PM_L3_MISS = 0x1f082, // L3 Misses
		PM_LSU0_L1_PREF = 0xd0b8, // LS0 L1 cache data prefetches
		PM_VSU_SCALAR_SINGLE_ISSUED = 0xb884, // Single Precision scalar instruction issued on Pipe0
		PM_LSU1_DC_PREF_STREAM_CONFIRM_STRIDE = 0xd0be, // LS1  Dcache Strided prefetch stream confirmed
		PM_L2_INST = 0x36080, // Instruction Load Count
		PM_VSU0_FRSP = 0xa0b4, // Round to single precision instruction executed
		PM_FLUSH_DISP = 0x2082, // Dispatch flush
		PM_PTEG_FROM_L2MISS = 0x4c058, // PTEG loaded from L2 miss
		PM_VSU1_DQ_ISSUED = 0xb09a, // 128BIT Decimal Issued on Pipe1
		PM_CMPLU_STALL_LSU = 0x20012, // Completion stall caused by LSU instruction
		PM_MRK_DATA_FROM_DMEM = 0x1d04a, // Marked data loaded from distant memory
		PM_LSU_FLUSH_ULD = 0xc8b0, // Flush: Unaligned Load
		PM_PTEG_FROM_LMEM = 0x4c052, // PTEG loaded from local memory
		PM_MRK_DERAT_MISS_16M = 0x3d05c, // Marked DERAT misses for 16M page
		PM_THRD_ALL_RUN_CYC = 0x2000c, // All Threads in run_cycles
		PM_MEM0_PREFETCH_DISP = 0x20083, // Nest events (MC0/MC1/PB/GX)
		PM_MRK_STALL_CMPLU_CYC_COUNT = 0x3003f, // Marked Group Completion Stall cycles (use edge detect to count #)
		PM_DATA_FROM_DL2L3_MOD = 0x3c04c, // Data loaded from distant L2 or L3 modified
		PM_VSU_FRSP = 0xa8b4, // Round to single precision instruction executed
		PM_MRK_DATA_FROM_L21_MOD = 0x3d046, // Marked data loaded from another L2 on same chip modified
		PM_PMC1_OVERFLOW = 0x20010, // Overflow from counter 1
		PM_VSU0_SINGLE = 0xa0a8, // FPU single precision
		PM_MRK_PTEG_FROM_L3MISS = 0x2d058, // Marked PTEG loaded from L3 miss
		PM_MRK_PTEG_FROM_L31_SHR = 0x2d056, // Marked PTEG loaded from another L3 on same chip shared
		PM_VSU0_VECTOR_SP_ISSUED = 0xb090, // Single Precision vector instruction issued (executed)
		PM_VSU1_FEST = 0xa0ba, // Estimate instruction executed
		PM_MRK_INST_DISP = 0x20030, // marked instruction dispatch
		PM_VSU0_COMPLEX_ISSUED = 0xb096, // Complex VMX instruction issued
		PM_LSU1_FLUSH_UST = 0xc0b6, // LS1 Flush: Unaligned Store
		PM_INST_CMPL = 0x2, // # PPC Instructions Finished
		PM_FXU_IDLE = 0x1000e, // fxu0 idle and fxu1 idle
		PM_LSU0_FLUSH_ULD = 0xc0b0, // LS0 Flush: Unaligned Load
		PM_MRK_DATA_FROM_DL2L3_MOD = 0x3d04c, // Marked data loaded from distant L2 or L3 modified
		PM_LSU_LMQ_SRQ_EMPTY_ALL_CYC = 0x3001c, // ALL threads lsu empty (lmq and srq empty)
		PM_LSU1_REJECT_LMQ_FULL = 0xc0a6, // LS1 Reject: LMQ Full (LHR)
		PM_INST_PTEG_FROM_L21_MOD = 0x3e056, // Instruction PTEG loaded from another L2 on same chip modified
		PM_INST_FROM_RL2L3_MOD = 0x14042, // Instruction fetched from remote L2 or L3 modified
		PM_SHL_CREATED = 0x5082, // SHL table entry Created
		PM_L2_ST_HIT = 0x46182, // All successful store dispatches that were L2Hits
		PM_DATA_FROM_DMEM = 0x1c04a, // Data loaded from distant memory
		PM_L3_LD_MISS = 0x2f082, // L3 demand LD Miss
		PM_FXU1_BUSY_FXU0_IDLE = 0x4000e, // fxu0 idle and fxu1 busy.
		PM_DISP_CLB_HELD_RES = 0x2094, // Dispatch/CLB Hold: Resource
		PM_L2_SN_SX_I_DONE = 0x36382, // SNP dispatched and went from Sx or Tx to Ix
		PM_GRP_CMPL = 0x30004, // group completed
		PM_STCX_CMPL = 0xc098, // STCX executed
		PM_VSU0_2FLOP = 0xa098, // two flops operation (scalar fmadd
		PM_L3_PREF_MISS = 0x3f082, // L3 Prefetch  Directory Miss
		PM_LSU_SRQ_SYNC_CYC = 0xd096, // A sync is in the SRQ
		PM_LSU_REJECT_ERAT_MISS = 0x20064, // LSU Reject due to ERAT (up to 2 per cycles)
		PM_L1_ICACHE_MISS = 0x200fc, // Demand iCache Miss
		PM_LSU1_FLUSH_SRQ = 0xc0be, // LS1 Flush: SRQ
		PM_LD_REF_L1_LSU0 = 0xc080, // LS0 L1 D cache load references counted at finish
		PM_VSU0_FEST = 0xa0b8, // Estimate instruction executed
		PM_VSU_VECTOR_SINGLE_ISSUED = 0xb890, // Single Precision vector instruction issued (executed)
		PM_FREQ_UP = 0x4000c, // Power Management: Above Threshold A
		PM_DATA_FROM_LMEM = 0x3c04a, // Data loaded from local memory
		PM_LSU1_LDX = 0xc08a, // LS1  Vector Loads
		PM_PMC3_OVERFLOW = 0x40010, // Overflow from counter 3
		PM_MRK_BR_MPRED = 0x30036, // Marked Branch Mispredicted
		PM_SHL_MATCH = 0x5086, // SHL Table Match
		PM_MRK_BR_TAKEN = 0x10036, // Marked Branch Taken
		PM_CMPLU_STALL_BRU = 0x4004e, // Completion stall due to BRU
		PM_ISLB_MISS = 0xd092, // Instruction SLB Miss - Tota of all segment sizes
		PM_CYC = 0x1e, // Cycles
		PM_DISP_HELD_THERMAL = 0x30006, // Dispatch Held due to Thermal
		PM_INST_PTEG_FROM_RL2L3_SHR = 0x2e054, // Instruction PTEG loaded from remote L2 or L3 shared
		PM_LSU1_SRQ_STFWD = 0xc0a2, // LS1 SRQ forwarded data to a load
		PM_GCT_NOSLOT_BR_MPRED = 0x4001a, // GCT empty by branch  mispredict
		PM_1PLUS_PPC_CMPL = 0x100f2, // 1 or more ppc  insts finished
		PM_PTEG_FROM_DMEM = 0x2c052, // PTEG loaded from distant memory
		PM_VSU_2FLOP = 0xa898, // two flops operation (scalar fmadd
		PM_GCT_FULL_CYC = 0x4086, // Cycles No room in EAT
		PM_MRK_DATA_FROM_L3_CYC = 0x40020, // Marked ld latency Data source 0001 (L3)
		PM_LSU_SRQ_S0_ALLOC = 0xd09d, // Slot 0 of SRQ valid
		PM_MRK_DERAT_MISS_4K = 0x1d05c, // Marked DERAT misses for 4K page
		PM_BR_MPRED_TA = 0x40ae, // Branch mispredict - target address
		PM_INST_PTEG_FROM_L2MISS = 0x4e058, // Instruction PTEG loaded from L2 miss
		PM_DPU_HELD_POWER = 0x20006, // Dispatch Held due to Power Management
		PM_RUN_INST_CMPL = 0x400fa, // Run_Instructions
		PM_MRK_VSU_FIN = 0x30032, // vsu (fpu) marked  instr finish
		PM_LSU_SRQ_S0_VALID = 0xd09c, // Slot 0 of SRQ valid
		PM_GCT_EMPTY_CYC = 0x20008, // GCT empty
		PM_IOPS_DISP = 0x30014, // IOPS dispatched
		PM_RUN_SPURR = 0x10008, // Run SPURR
		PM_PTEG_FROM_L21_MOD = 0x3c056, // PTEG loaded from another L2 on same chip modified
		PM_VSU0_1FLOP = 0xa080, // one flop (fadd
		PM_SNOOP_TLBIE = 0xd0b2, // TLBIE snoop
		PM_DATA_FROM_L3MISS = 0x2c048, // Demand LD - L3 Miss (not L2 hit and not L3 hit)
		PM_VSU_SINGLE = 0xa8a8, // Vector or Scalar single precision
		PM_DTLB_MISS_16G = 0x1c05e, // Data TLB miss for 16G page
		PM_CMPLU_STALL_VECTOR = 0x2001c, // Completion stall caused by Vector instruction
		PM_FLUSH = 0x400f8, // Flush (any type)
		PM_L2_LD_HIT = 0x36182, // All successful load dispatches that were L2 hits
		PM_NEST_PAIR2_AND = 0x30883, // Nest events (MC0/MC1/PB/GX)
		PM_VSU1_1FLOP = 0xa082, // one flop (fadd
		PM_IC_PREF_REQ = 0x408a, // Instruction prefetch requests
		PM_L3_LD_HIT = 0x2f080, // L3 demand LD Hits
		PM_GCT_NOSLOT_IC_MISS = 0x2001a, // GCT empty by I cache miss
		PM_DISP_HELD = 0x10006, // Dispatch Held
		PM_L2_LD = 0x16080, // Data Load Count
		PM_LSU_FLUSH_SRQ = 0xc8bc, // Flush: SRQ
		PM_BC_PLUS_8_CONV = 0x40b8, // BC+8 Converted
		PM_MRK_DATA_FROM_L31_MOD_CYC = 0x40026, // Marked ld latency Data source 0111  (L3.1 M same chip)
		PM_CMPLU_STALL_VECTOR_LONG = 0x4004a, // completion stall due to long latency vector instruction
		PM_L2_RCST_BUSY_RC_FULL = 0x26282, // L2  activated Busy to the core for stores due to all RC full
		PM_TB_BIT_TRANS = 0x300f8, // Time Base bit transition
		PM_THERMAL_MAX = 0x40006, // Processor In Thermal MAX
		PM_LSU1_FLUSH_ULD = 0xc0b2, // LS 1 Flush: Unaligned Load
		PM_LSU1_REJECT_LHS = 0xc0ae, // LS1  Reject: Load Hit Store
		PM_LSU_LRQ_S0_ALLOC = 0xd09f, // Slot 0 of LRQ valid
		PM_L3_CO_L31 = 0x4f080, // L3 Castouts to Memory
		PM_POWER_EVENT4 = 0x4006e, // Power Management Event 4
		PM_DATA_FROM_L31_SHR = 0x1c04e, // Data loaded from another L3 on same chip shared
		PM_BR_UNCOND = 0x409e, // Unconditional Branch
		PM_LSU1_DC_PREF_STREAM_ALLOC = 0xd0aa, // LS 1 D cache new prefetch stream allocated
		PM_PMC4_REWIND = 0x10020, // PMC4 Rewind Event
		PM_L2_RCLD_DISP = 0x16280, // L2  RC load dispatch attempt
		PM_THRD_PRIO_2_3_CYC = 0x40b2, // Cycles thread running at priority level 2 or 3
		PM_MRK_PTEG_FROM_L2MISS = 0x4d058, // Marked PTEG loaded from L2 miss
		PM_IC_DEMAND_L2_BHT_REDIRECT = 0x4098, // L2 I cache demand request due to BHT redirect
		PM_LSU_DERAT_MISS = 0x200f6, // DERAT Reloaded due to a DERAT miss
		PM_IC_PREF_CANCEL_L2 = 0x4094, // L2 Squashed request
		PM_MRK_FIN_STALL_CYC_COUNT = 0x1003d, // Marked instruction Finish Stall cycles (marked finish after NTC) (use edge detect to count #)
		PM_BR_PRED_CCACHE = 0x40a0, // Count Cache Predictions
		PM_GCT_UTIL_1_TO_2_SLOTS = 0x209c, // GCT Utilization 1-2 entries
		PM_MRK_ST_CMPL_INT = 0x30034, // marked  store complete (data home) with intervention
		PM_LSU_TWO_TABLEWALK_CYC = 0xd0a6, // Cycles when two tablewalks pending on this thread
		PM_MRK_DATA_FROM_L3MISS = 0x2d048, // Marked data loaded from L3 miss
		PM_GCT_NOSLOT_CYC = 0x100f8, // No itags assigned
		PM_LSU_SET_MPRED = 0xc0a8, // Line already in cache at reload time
		PM_FLUSH_DISP_TLBIE = 0x208a, // Dispatch Flush: TLBIE
		PM_VSU1_FCONV = 0xa0b2, // Convert instruction executed
		PM_DERAT_MISS_16G = 0x4c05c, // DERAT misses for 16G page
		PM_INST_FROM_LMEM = 0x3404a, // Instruction fetched from local memory
		PM_IC_DEMAND_L2_BR_REDIRECT = 0x409a, // L2 I cache demand request due to branch redirect
		PM_CMPLU_STALL_SCALAR_LONG = 0x20018, // Completion stall caused by long latency scalar instruction
		PM_INST_PTEG_FROM_L2 = 0x1e050, // Instruction PTEG loaded from L2
		PM_PTEG_FROM_L2 = 0x1c050, // PTEG loaded from L2
		PM_MRK_DATA_FROM_L21_SHR_CYC = 0x20024, // Marked ld latency Data source 0100 (L2.1 S)
		PM_MRK_DTLB_MISS_4K = 0x2d05a, // Marked Data TLB misses for 4K page
		PM_VSU0_FPSCR = 0xb09c, // Move to/from FPSCR type instruction issued on Pipe 0
		PM_VSU1_VECT_DOUBLE_ISSUED = 0xb082, // Double Precision vector instruction issued on Pipe1
		PM_MRK_PTEG_FROM_RL2L3_MOD = 0x1d052, // Marked PTEG loaded from remote L2 or L3 modified
		PM_MEM0_RQ_DISP = 0x10083, // Nest events (MC0/MC1/PB/GX)
		PM_L2_LD_MISS = 0x26080, // Data Load Miss
		PM_VMX_RESULT_SAT_1 = 0xb0a0, // 1
		PM_L1_PREF = 0xd8b8, // L1 Prefetches
		PM_MRK_DATA_FROM_LMEM_CYC = 0x2002c, // Marked ld latency Data Source 1100 (Local Memory)
		PM_GRP_IC_MISS_NONSPEC = 0x1000c, // Group experienced non-speculative I cache miss
		PM_PB_NODE_PUMP = 0x10081, // Nest events (MC0/MC1/PB/GX)
		PM_SHL_MERGED = 0x5084, // SHL table entry merged with existing
		PM_NEST_PAIR1_ADD = 0x20881, // Nest events (MC0/MC1/PB/GX)
		PM_DATA_FROM_L3 = 0x1c048, // Data loaded from L3
		PM_LSU_FLUSH = 0x208e, // Flush initiated by LSU
		PM_LSU_SRQ_SYNC_COUNT = 0xd097, // SRQ sync count (edge of PM_LSU_SRQ_SYNC_CYC)
		PM_PMC2_OVERFLOW = 0x30010, // Overflow from counter 2
		PM_LSU_LDF = 0xc884, // All Scalar Loads
		PM_POWER_EVENT3 = 0x3006e, // Power Management Event 3
		PM_DISP_WT = 0x30008, // Dispatched Starved (not held
		PM_CMPLU_STALL_REJECT = 0x40016, // Completion stall caused by reject
		PM_IC_BANK_CONFLICT = 0x4082, // Read blocked due to interleave conflict.
		PM_BR_MPRED_CR_TA = 0x48ae, // Branch mispredict - taken/not taken and target
		PM_L2_INST_MISS = 0x36082, // Instruction Load Misses
		PM_CMPLU_STALL_ERAT_MISS = 0x40018, // Completion stall caused by ERAT miss
		PM_NEST_PAIR2_ADD = 0x30881, // Nest events (MC0/MC1/PB/GX)
		PM_MRK_LSU_FLUSH = 0xd08c, // Flush: (marked) : All Cases
		PM_L2_LDST = 0x16880, // Data Load+Store Count
		PM_INST_FROM_L31_SHR = 0x1404e, // Instruction fetched from another L3 on same chip shared
		PM_VSU0_FIN = 0xa0bc, // VSU0 Finished an instruction
		PM_LARX_LSU = 0xc894, // Larx Finished
		PM_INST_FROM_RMEM = 0x34042, // Instruction fetched from remote memory
		PM_DISP_CLB_HELD_TLBIE = 0x2096, // Dispatch Hold: Due to TLBIE
		PM_MRK_DATA_FROM_DMEM_CYC = 0x2002e, // Marked ld latency Data Source 1110 (Distant Memory)
		PM_BR_PRED_CR = 0x40a8, // Branch predict - taken/not taken
		PM_LSU_REJECT = 0x10064, // LSU Reject (up to 2 per cycle)
		PM_GCT_UTIL_3_TO_6_SLOTS = 0x209e, // GCT Utilization 3-6 entries
		PM_CMPLU_STALL_END_GCT_NOSLOT = 0x10028, // Count ended because GCT went empty
		PM_LSU0_REJECT_LMQ_FULL = 0xc0a4, // LS0 Reject: LMQ Full (LHR)
		PM_VSU_FEST = 0xa8b8, // Estimate instruction executed
		PM_NEST_PAIR0_AND = 0x10883, // Nest events (MC0/MC1/PB/GX)
		PM_PTEG_FROM_L3 = 0x2c050, // PTEG loaded from L3
		PM_POWER_EVENT2 = 0x2006e, // Power Management Event 2
		PM_IC_PREF_CANCEL_PAGE = 0x4090, // Prefetch Canceled due to page boundary
		PM_VSU0_FSQRT_FDIV = 0xa088, // four flops operation (fdiv
		PM_MRK_GRP_CMPL = 0x40030, // Marked group complete
		PM_VSU0_SCAL_DOUBLE_ISSUED = 0xb088, // Double Precision scalar instruction issued on Pipe0
		PM_GRP_DISP = 0x3000a, // dispatch_success (Group Dispatched)
		PM_LSU0_LDX = 0xc088, // LS0 Vector Loads
		PM_DATA_FROM_L2 = 0x1c040, // Data loaded from L2
		PM_MRK_DATA_FROM_RL2L3_MOD = 0x1d042, // Marked data loaded from remote L2 or L3 modified
		PM_LD_REF_L1 = 0xc880, // L1 D cache load references counted at finish
		PM_VSU0_VECT_DOUBLE_ISSUED = 0xb080, // Double Precision vector instruction issued on Pipe0
		PM_VSU1_2FLOP_DOUBLE = 0xa08e, // two flop DP vector operation (xvadddp
		PM_THRD_PRIO_6_7_CYC = 0x40b6, // Cycles thread running at priority level 6 or 7
		PM_BC_PLUS_8_RSLV_TAKEN = 0x40ba, // BC+8 Resolve outcome was Taken
		PM_BR_MPRED_CR = 0x40ac, // Branch mispredict - taken/not taken
		PM_L3_CO_MEM = 0x4f082, // L3 Castouts to L3.1
		PM_LD_MISS_L1 = 0x400f0, // Load Missed L1
		PM_DATA_FROM_RL2L3_MOD = 0x1c042, // Data loaded from remote L2 or L3 modified
		PM_LSU_SRQ_FULL_CYC = 0x1001a, // Storage Queue is full and is blocking dispatch
		PM_TABLEWALK_CYC = 0x10026, // Cycles when a tablewalk (I or D) is active
		PM_MRK_PTEG_FROM_RMEM = 0x3d052, // Marked PTEG loaded from remote memory
		PM_LSU_SRQ_STFWD = 0xc8a0, // Load got data from a store
		PM_INST_PTEG_FROM_RMEM = 0x3e052, // Instruction PTEG loaded from remote memory
		PM_FXU0_FIN = 0x10004, // FXU0 Finished
		PM_LSU1_L1_SW_PREF = 0xc09e, // LSU1 Software L1 Prefetches
		PM_PTEG_FROM_L31_MOD = 0x1c054, // PTEG loaded from another L3 on same chip modified
		PM_PMC5_OVERFLOW = 0x10024, // Overflow from counter 5
		PM_LD_REF_L1_LSU1 = 0xc082, // LS1 L1 D cache load references counted at finish
		PM_INST_PTEG_FROM_L21_SHR = 0x4e056, // Instruction PTEG loaded from another L2 on same chip shared
		PM_CMPLU_STALL_THRD = 0x1001c, // Completion Stalled due to thread conflict.  Group ready to complete but it was another thread's turn
		PM_DATA_FROM_RMEM = 0x3c042, // Data loaded from remote memory
		PM_VSU0_SCAL_SINGLE_ISSUED = 0xb084, // Single Precision scalar instruction issued on Pipe0
		PM_BR_MPRED_LSTACK = 0x40a6, // Branch Mispredict due to Link Stack
		PM_MRK_DATA_FROM_RL2L3_MOD_CYC = 0x40028, // Marked ld latency Data source 1001 (L2.5/L3.5 M same 4 chip node)
		PM_LSU0_FLUSH_UST = 0xc0b4, // LS0 Flush: Unaligned Store
		PM_LSU_NCST = 0xc090, // Non-cachable Stores sent to nest
		PM_BR_TAKEN = 0x20004, // Branch Taken
		PM_INST_PTEG_FROM_LMEM = 0x4e052, // Instruction PTEG loaded from local memory
		PM_GCT_NOSLOT_BR_MPRED_IC_MISS = 0x4001c, // GCT empty by branch  mispredict + IC miss
		PM_DTLB_MISS_4K = 0x2c05a, // Data TLB miss for 4K page
		PM_PMC4_SAVED = 0x30022, // PMC4 Rewind Value saved (matched condition)
		PM_VSU1_PERMUTE_ISSUED = 0xb092, // Permute VMX Instruction Issued
		PM_SLB_MISS = 0xd890, // Data + Instruction SLB Miss - Total of all segment sizes
		PM_LSU1_FLUSH_LRQ = 0xc0ba, // LS1 Flush: LRQ
		PM_DTLB_MISS = 0x300fc, // TLB reload valid
		PM_VSU1_FRSP = 0xa0b6, // Round to single precision instruction executed
		PM_VSU_VECTOR_DOUBLE_ISSUED = 0xb880, // Double Precision vector instruction issued on Pipe0
		PM_L2_CASTOUT_SHR = 0x16182, // L2 Castouts - Shared (T
		PM_DATA_FROM_DL2L3_SHR = 0x3c044, // Data loaded from distant L2 or L3 shared
		PM_VSU1_STF = 0xb08e, // FPU store (SP or DP) issued on Pipe1
		PM_ST_FIN = 0x200f0, // Store Instructions Finished
		PM_PTEG_FROM_L21_SHR = 0x4c056, // PTEG loaded from another L2 on same chip shared
		PM_L2_LOC_GUESS_WRONG = 0x26480, // L2 guess loc and guess was not correct (ie data remote)
		PM_MRK_STCX_FAIL = 0xd08e, // Marked STCX failed
		PM_LSU0_REJECT_LHS = 0xc0ac, // LS0 Reject: Load Hit Store
		PM_IC_PREF_CANCEL_HIT = 0x4092, // Prefetch Canceled due to icache hit
		PM_L3_PREF_BUSY = 0x4f080, // threshold (8
		PM_MRK_BRU_FIN = 0x2003a, // bru marked instr finish
		PM_LSU1_NCLD = 0xc08e, // LS1 Non-cachable Loads counted at finish
		PM_INST_PTEG_FROM_L31_MOD = 0x1e054, // Instruction PTEG loaded from another L3 on same chip modified
		PM_LSU_NCLD = 0xc88c, // Non-cachable Loads counted at finish
		PM_LSU_LDX = 0xc888, // All Vector loads (vsx vector + vmx vector)
		PM_L2_LOC_GUESS_CORRECT = 0x16480, // L2 guess loc and guess was correct (ie data local)
		PM_THRESH_TIMEO = 0x10038, // Threshold  timeout  event
		PM_L3_PREF_ST = 0xd0ae, // L3 cache ST prefetches
		PM_DISP_CLB_HELD_SYNC = 0x2098, // Dispatch/CLB Hold: Sync type instruction
		PM_VSU_SIMPLE_ISSUED = 0xb894, // Simple VMX instruction issued
		PM_VSU1_SINGLE = 0xa0aa, // FPU single precision
		PM_DATA_TABLEWALK_CYC = 0x3001a, // Data Tablewalk Active
		PM_L2_RC_ST_DONE = 0x36380, // RC did st to line that was Tx or Sx
		PM_MRK_PTEG_FROM_L21_MOD = 0x3d056, // Marked PTEG loaded from another L2 on same chip modified
		PM_LARX_LSU1 = 0xc096, // ls1 Larx Finished
		PM_MRK_DATA_FROM_RMEM = 0x3d042, // Marked data loaded from remote memory
		PM_DISP_CLB_HELD = 0x2090, // CLB Hold: Any Reason
		PM_DERAT_MISS_4K = 0x1c05c, // DERAT misses for 4K page
		PM_L2_RCLD_DISP_FAIL_ADDR = 0x16282, // L2  RC load dispatch attempt failed due to address collision with RC/CO/SN/SQ
		PM_SEG_EXCEPTION = 0x28a4, // ISEG + DSEG Exception
		PM_FLUSH_DISP_SB = 0x208c, // Dispatch Flush: Scoreboard
		PM_L2_DC_INV = 0x26182, // Dcache invalidates from L2
		PM_PTEG_FROM_DL2L3_MOD = 0x4c054, // PTEG loaded from distant L2 or L3 modified
		PM_DSEG = 0x20a6, // DSEG Exception
		PM_BR_PRED_LSTACK = 0x40a2, // Link Stack Predictions
		PM_VSU0_STF = 0xb08c, // FPU store (SP or DP) issued on Pipe0
		PM_LSU_FX_FIN = 0x10066, // LSU Finished a FX operation  (up to 2 per cycle)
		PM_DERAT_MISS_16M = 0x3c05c, // DERAT misses for 16M page
		PM_MRK_PTEG_FROM_DL2L3_MOD = 0x4d054, // Marked PTEG loaded from distant L2 or L3 modified
		PM_GCT_UTIL_11_PLUS_SLOTS = 0x20a2, // GCT Utilization 11+ entries
		PM_INST_FROM_L3 = 0x14048, // Instruction fetched from L3
		PM_MRK_IFU_FIN = 0x3003a, // IFU non-branch marked instruction finished
		PM_ITLB_MISS = 0x400fc, // ITLB Reloaded (always zero on POWER6)
		PM_VSU_STF = 0xb88c, // FPU store (SP or DP) issued on Pipe0
		PM_LSU_FLUSH_UST = 0xc8b4, // Flush: Unaligned Store
		PM_L2_LDST_MISS = 0x26880, // Data Load+Store Miss
		PM_FXU1_FIN = 0x40004, // FXU1 Finished
		PM_SHL_DEALLOCATED = 0x5080, // SHL Table entry deallocated
		PM_L2_SN_M_WR_DONE = 0x46382, // SNP dispatched for a write and was M
		PM_LSU_REJECT_SET_MPRED = 0xc8a8, // Reject: Set Predict Wrong
		PM_L3_PREF_LD = 0xd0ac, // L3 cache LD prefetches
		PM_L2_SN_M_RD_DONE = 0x46380, // SNP dispatched for a read and was M
		PM_MRK_DERAT_MISS_16G = 0x4d05c, // Marked DERAT misses for 16G page
		PM_VSU_FCONV = 0xa8b0, // Convert instruction executed
		PM_ANY_THRD_RUN_CYC = 0x100fa, // One of threads in run_cycles
		PM_LSU_LMQ_FULL_CYC = 0xd0a4, // LMQ full
		PM_MRK_LSU_REJECT_LHS = 0xd082, // Reject(marked): Load Hit Store
		PM_MRK_LD_MISS_L1_CYC = 0x4003e, // L1 data load miss cycles
		PM_MRK_DATA_FROM_L2_CYC = 0x20020, // Marked ld latency Data source 0000 (L2 hit)
		PM_INST_IMC_MATCH_DISP = 0x30016, // IMC Matches dispatched
		PM_MRK_DATA_FROM_RMEM_CYC = 0x4002c, // Marked ld latency Data source 1101  (Memory same 4 chip node)
		PM_VSU0_SIMPLE_ISSUED = 0xb094, // Simple VMX instruction issued
		PM_CMPLU_STALL_DIV = 0x40014, // Completion stall caused by DIV instruction
		PM_MRK_PTEG_FROM_RL2L3_SHR = 0x2d054, // Marked PTEG loaded from remote L2 or L3 shared
		PM_VSU_FMA_DOUBLE = 0xa890, // DP vector version of fmadd
		PM_VSU_4FLOP = 0xa89c, // four flops operation (scalar fdiv
		PM_VSU1_FIN = 0xa0be, // VSU1 Finished an instruction
		PM_NEST_PAIR1_AND = 0x20883, // Nest events (MC0/MC1/PB/GX)
		PM_INST_PTEG_FROM_RL2L3_MOD = 0x1e052, // Instruction PTEG loaded from remote L2 or L3 modified
		PM_RUN_CYC = 0x200f4, // Run_cycles
		PM_PTEG_FROM_RMEM = 0x3c052, // PTEG loaded from remote memory
		PM_LSU_LRQ_S0_VALID = 0xd09e, // Slot 0 of LRQ valid
		PM_LSU0_LDF = 0xc084, // LS0 Scalar  Loads
		PM_FLUSH_COMPLETION = 0x30012, // Completion Flush
		PM_ST_MISS_L1 = 0x300f0, // L1 D cache store misses
		PM_L2_NODE_PUMP = 0x36480, // RC req that was a local (aka node) pump attempt
		PM_INST_FROM_DL2L3_SHR = 0x34044, // Instruction fetched from distant L2 or L3 shared
		PM_MRK_STALL_CMPLU_CYC = 0x3003e, // Marked Group Completion Stall cycles
		PM_VSU1_DENORM = 0xa0ae, // FPU denorm operand
		PM_MRK_DATA_FROM_L31_SHR_CYC = 0x20026, // Marked ld latency Data source 0110 (L3.1 S)
		PM_NEST_PAIR0_ADD = 0x10881, // Nest events (MC0/MC1/PB/GX)
		PM_INST_FROM_L3MISS = 0x24048, // Instruction fetched missed L3
		PM_EE_OFF_EXT_INT = 0x2080, // ee off and external interrupt
		PM_INST_PTEG_FROM_DMEM = 0x2e052, // Instruction PTEG loaded from distant memory
		PM_INST_FROM_DL2L3_MOD = 0x3404c, // Instruction fetched from distant L2 or L3 modified
		PM_PMC6_OVERFLOW = 0x30024, // Overflow from counter 6
		PM_VSU_2FLOP_DOUBLE = 0xa88c, // DP vector version of fmul
		PM_TLB_MISS = 0x20066, // TLB Miss (I + D)
		PM_FXU_BUSY = 0x2000e, // fxu0 busy and fxu1 busy.
		PM_L2_RCLD_DISP_FAIL_OTHER = 0x26280, // L2  RC load dispatch attempt failed due to other reasons
		PM_LSU_REJECT_LMQ_FULL = 0xc8a4, // Reject: LMQ Full (LHR)
		PM_IC_RELOAD_SHR = 0x4096, // Reloading line to be shared between the threads
		PM_GRP_MRK = 0x10031, // IDU Marked Instruction
		PM_MRK_ST_NEST = 0x20034, // marked store sent to Nest
		PM_VSU1_FSQRT_FDIV = 0xa08a, // four flops operation (fdiv
		PM_LSU0_FLUSH_LRQ = 0xc0b8, // LS0 Flush: LRQ
		PM_LARX_LSU0 = 0xc094, // ls0 Larx Finished
		PM_IBUF_FULL_CYC = 0x4084, // Cycles No room in ibuff
		PM_MRK_DATA_FROM_DL2L3_SHR_CYC = 0x2002a, // Marked ld latency Data Source 1010 (Distant L2.75/L3.75 S)
		PM_LSU_DC_PREF_STREAM_ALLOC = 0xd8a8, // D cache new prefetch stream allocated
		PM_GRP_MRK_CYC = 0x10030, // cycles IDU marked instruction before dispatch
		PM_MRK_DATA_FROM_RL2L3_SHR_CYC = 0x20028, // Marked ld latency Data Source 1000 (Remote L2.5/L3.5 S)
		PM_L2_GLOB_GUESS_CORRECT = 0x16482, // L2 guess glb and guess was correct (ie data remote)
		PM_LSU_REJECT_LHS = 0xc8ac, // Reject: Load Hit Store
		PM_MRK_DATA_FROM_LMEM = 0x3d04a, // Marked data loaded from local memory
		PM_INST_PTEG_FROM_L3 = 0x2e050, // Instruction PTEG loaded from L3
		PM_FREQ_DOWN = 0x3000c, // Frequency is being slewed down due to Power Management
		PM_PB_RETRY_NODE_PUMP = 0x30081, // Nest events (MC0/MC1/PB/GX)
		PM_INST_FROM_RL2L3_SHR = 0x1404c, // Instruction fetched from remote L2 or L3 shared
		PM_MRK_INST_ISSUED = 0x10032, // Marked instruction issued
		PM_PTEG_FROM_L3MISS = 0x2c058, // PTEG loaded from L3 miss
		PM_RUN_PURR = 0x400f4, // Run_PURR
		PM_MRK_GRP_IC_MISS = 0x40038, // Marked group experienced  I cache miss
		PM_MRK_DATA_FROM_L3 = 0x1d048, // Marked data loaded from L3
		PM_CMPLU_STALL_DCACHE_MISS = 0x20016, // Completion stall caused by D cache miss
		PM_PTEG_FROM_RL2L3_SHR = 0x2c054, // PTEG loaded from remote L2 or L3 shared
		PM_LSU_FLUSH_LRQ = 0xc8b8, // Flush: LRQ
		PM_MRK_DERAT_MISS_64K = 0x2d05c, // Marked DERAT misses for 64K page
		PM_INST_PTEG_FROM_DL2L3_MOD = 0x4e054, // Instruction PTEG loaded from distant L2 or L3 modified
		PM_L2_ST_MISS = 0x26082, // Data Store Miss
		PM_LWSYNC = 0xd094, // lwsync count (easier to use than IMC)
		PM_LSU0_DC_PREF_STREAM_CONFIRM_STRIDE = 0xd0bc, // LS0 Dcache Strided prefetch stream confirmed
		PM_MRK_PTEG_FROM_L21_SHR = 0x4d056, // Marked PTEG loaded from another L2 on same chip shared
		PM_MRK_LSU_FLUSH_LRQ = 0xd088, // Flush: (marked) LRQ
		PM_INST_IMC_MATCH_CMPL = 0x100f0, // IMC Match Count
		PM_NEST_PAIR3_AND = 0x40883, // Nest events (MC0/MC1/PB/GX)
		PM_PB_RETRY_SYS_PUMP = 0x40081, // Nest events (MC0/MC1/PB/GX)
		PM_MRK_INST_FIN = 0x30030, // marked instr finish any unit
		PM_MRK_PTEG_FROM_DL2L3_SHR = 0x3d054, // Marked PTEG loaded from remote L2 or L3 shared
		PM_INST_FROM_L31_MOD = 0x14044, // Instruction fetched from another L3 on same chip modified
		PM_MRK_DTLB_MISS_64K = 0x3d05e, // Marked Data TLB misses for 64K page
		PM_LSU_FIN = 0x30066, // LSU Finished an instruction (up to 2 per cycle)
		PM_MRK_LSU_REJECT = 0x40064, // LSU marked reject (up to 2 per cycle)
		PM_L2_CO_FAIL_BUSY = 0x16382, // L2  RC Cast Out dispatch attempt failed due to all CO machines busy
		PM_MEM0_WQ_DISP = 0x40083, // Nest events (MC0/MC1/PB/GX)
		PM_DATA_FROM_L31_MOD = 0x1c044, // Data loaded from another L3 on same chip modified
		PM_THERMAL_WARN = 0x10016, // Processor in Thermal Warning
		PM_VSU0_4FLOP = 0xa09c, // four flops operation (scalar fdiv
		PM_BR_MPRED_CCACHE = 0x40a4, // Branch Mispredict due to Count Cache prediction
		PM_CMPLU_STALL_IFU = 0x4004c, // Completion stall due to IFU
		PM_L1_DEMAND_WRITE = 0x408c, // Instruction Demand sectors wriittent into IL1
		PM_FLUSH_BR_MPRED = 0x2084, // Flush caused by branch mispredict
		PM_MRK_DTLB_MISS_16G = 0x1d05e, // Marked Data TLB misses for 16G page
		PM_MRK_PTEG_FROM_DMEM = 0x2d052, // Marked PTEG loaded from distant memory
		PM_L2_RCST_DISP = 0x36280, // L2  RC store dispatch attempt
		PM_CMPLU_STALL = 0x4000a, // No groups completed
		PM_LSU_PARTIAL_CDF = 0xc0aa, // A partial cacheline was returned from the L3
		PM_DISP_CLB_HELD_SB = 0x20a8, // Dispatch/CLB Hold: Scoreboard
		PM_VSU0_FMA_DOUBLE = 0xa090, // four flop DP vector operations (xvmadddp
		PM_FXU0_BUSY_FXU1_IDLE = 0x3000e, // fxu0 busy and fxu1 idle
		PM_IC_DEMAND_CYC = 0x10018, // Cycles when a demand ifetch was pending
		PM_MRK_DATA_FROM_L21_SHR = 0x3d04e, // Marked data loaded from another L2 on same chip shared
		PM_MRK_LSU_FLUSH_UST = 0xd086, // Flush: (marked) Unaligned Store
		PM_INST_PTEG_FROM_L3MISS = 0x2e058, // Instruction PTEG loaded from L3 miss
		PM_VSU_DENORM = 0xa8ac, // Vector or Scalar denorm operand
		PM_MRK_LSU_PARTIAL_CDF = 0xd080, // A partial cacheline was returned from the L3 for a marked load
		PM_INST_FROM_L21_SHR = 0x3404e, // Instruction fetched from another L2 on same chip shared
		PM_IC_PREF_WRITE = 0x408e, // Instruction prefetch written into IL1
		PM_BR_PRED = 0x409c, // Branch Predictions made
		PM_INST_FROM_DMEM = 0x1404a, // Instruction fetched from distant memory
		PM_IC_PREF_CANCEL_ALL = 0x4890, // Prefetch Canceled due to page boundary or icache hit
		PM_LSU_DC_PREF_STREAM_CONFIRM = 0xd8b4, // Dcache new prefetch stream confirmed
		PM_MRK_LSU_FLUSH_SRQ = 0xd08a, // Flush: (marked) SRQ
		PM_MRK_FIN_STALL_CYC = 0x1003c, // Marked instruction Finish Stall cycles (marked finish after NTC)
		PM_L2_RCST_DISP_FAIL_OTHER = 0x46280, // L2  RC store dispatch attempt failed due to other reasons
		PM_VSU1_DD_ISSUED = 0xb098, // 64BIT Decimal Issued on Pipe1
		PM_PTEG_FROM_L31_SHR = 0x2c056, // PTEG loaded from another L3 on same chip shared
		PM_DATA_FROM_L21_SHR = 0x3c04e, // Data loaded from another L2 on same chip shared
		PM_LSU0_NCLD = 0xc08c, // LS0 Non-cachable Loads counted at finish
		PM_VSU1_4FLOP = 0xa09e, // four flops operation (scalar fdiv
		PM_VSU1_8FLOP = 0xa0a2, // eight flops operation (DP vector versions of fdiv
		PM_VSU_8FLOP = 0xa8a0, // eight flops operation (DP vector versions of fdiv
		PM_LSU_LMQ_SRQ_EMPTY_CYC = 0x2003e, // LSU empty (lmq and srq empty)
		PM_DTLB_MISS_64K = 0x3c05e, // Data TLB miss for 64K page
		PM_THRD_CONC_RUN_INST = 0x300f4, // Concurrent Run Instructions
		PM_MRK_PTEG_FROM_L2 = 0x1d050, // Marked PTEG loaded from L2
		PM_PB_SYS_PUMP = 0x20081, // Nest events (MC0/MC1/PB/GX)
		PM_VSU_FIN = 0xa8bc, // VSU0 Finished an instruction
		PM_MRK_DATA_FROM_L31_MOD = 0x1d044, // Marked data loaded from another L3 on same chip modified
		PM_THRD_PRIO_0_1_CYC = 0x40b0, // Cycles thread running at priority level 0 or 1
		PM_DERAT_MISS_64K = 0x2c05c, // DERAT misses for 64K page
		PM_PMC2_REWIND = 0x30020, // PMC2 Rewind Event (did not match condition)
		PM_INST_FROM_L2 = 0x14040, // Instruction fetched from L2
		PM_GRP_BR_MPRED_NONSPEC = 0x1000a, // Group experienced non-speculative branch redirect
		PM_INST_DISP = 0x200f2, // # PPC Dispatched
		PM_MEM0_RD_CANCEL_TOTAL = 0x30083, // Nest events (MC0/MC1/PB/GX)
		PM_LSU0_DC_PREF_STREAM_CONFIRM = 0xd0b4, // LS0 Dcache prefetch stream confirmed
		PM_L1_DCACHE_RELOAD_VALID = 0x300f6, // L1 reload data source valid
		PM_VSU_SCALAR_DOUBLE_ISSUED = 0xb888, // Double Precision scalar instruction issued on Pipe0
		PM_L3_PREF_HIT = 0x3f080, // L3 Prefetch Directory Hit
		PM_MRK_PTEG_FROM_L31_MOD = 0x1d054, // Marked PTEG loaded from another L3 on same chip modified
		PM_CMPLU_STALL_STORE = 0x2004a, // Completion stall due to store instruction
		PM_MRK_FXU_FIN = 0x20038, // fxu marked  instr finish
		PM_PMC4_OVERFLOW = 0x10010, // Overflow from counter 4
		PM_MRK_PTEG_FROM_L3 = 0x2d050, // Marked PTEG loaded from L3
		PM_LSU0_LMQ_LHR_MERGE = 0xd098, // LS0  Load Merged with another cacheline request
		PM_BTAC_HIT = 0x508a, // BTAC Correct Prediction
		PM_L3_RD_BUSY = 0x4f082, // threshold (2
		PM_LSU0_L1_SW_PREF = 0xc09c, // LSU0 Software L1 Prefetches
		PM_INST_FROM_L2MISS = 0x44048, // Instruction fetched missed L2
		PM_LSU0_DC_PREF_STREAM_ALLOC = 0xd0a8, // LS0 D cache new prefetch stream allocated
		PM_L2_ST = 0x16082, // Data Store Count
		PM_VSU0_DENORM = 0xa0ac, // FPU denorm operand
		PM_MRK_DATA_FROM_DL2L3_SHR = 0x3d044, // Marked data loaded from distant L2 or L3 shared
		PM_BR_PRED_CR_TA = 0x48aa, // Branch predict - taken/not taken and target
		PM_VSU0_FCONV = 0xa0b0, // Convert instruction executed
		PM_MRK_LSU_FLUSH_ULD = 0xd084, // Flush: (marked) Unaligned Load
		PM_BTAC_MISS = 0x5088, // BTAC Mispredicted
		PM_MRK_LD_MISS_EXPOSED_CYC_COUNT = 0x1003f, // Marked Load exposed Miss (use edge detect to count #)
		PM_MRK_DATA_FROM_L2 = 0x1d040, // Marked data loaded from L2
		PM_LSU_DCACHE_RELOAD_VALID = 0xd0a2, // count per sector of lines reloaded in L1 (demand + prefetch)
		PM_VSU_FMA = 0xa884, // two flops operation (fmadd
		PM_LSU0_FLUSH_SRQ = 0xc0bc, // LS0 Flush: SRQ
		PM_LSU1_L1_PREF = 0xd0ba, // LS1 L1 cache data prefetches
		PM_IOPS_CMPL = 0x10014, // Internal Operations completed
		PM_L2_SYS_PUMP = 0x36482, // RC req that was a global (aka system) pump attempt
		PM_L2_RCLD_BUSY_RC_FULL = 0x46282, // L2  activated Busy to the core for loads due to all RC full
		PM_LSU_LMQ_S0_ALLOC = 0xd0a1, // Slot 0 of LMQ valid
		PM_FLUSH_DISP_SYNC = 0x2088, // Dispatch Flush: Sync
		PM_MRK_DATA_FROM_DL2L3_MOD_CYC = 0x4002a, // Marked ld latency Data source 1011  (L2.75/L3.75 M different 4 chip node)
		PM_L2_IC_INV = 0x26180, // Icache Invalidates from L2
		PM_MRK_DATA_FROM_L21_MOD_CYC = 0x40024, // Marked ld latency Data source 0101 (L2.1 M same chip)
		PM_L3_PREF_LDST = 0xd8ac, // L3 cache prefetches LD + ST
		PM_LSU_SRQ_EMPTY_CYC = 0x40008, // ALL threads srq empty
		PM_LSU_LMQ_S0_VALID = 0xd0a0, // Slot 0 of LMQ valid
		PM_FLUSH_PARTIAL = 0x2086, // Partial flush
		PM_VSU1_FMA_DOUBLE = 0xa092, // four flop DP vector operations (xvmadddp
		PM_1PLUS_PPC_DISP = 0x400f2, // Cycles at least one Instr Dispatched
		PM_DATA_FROM_L2MISS = 0x200fe, // Demand LD - L2 Miss (not L2 hit)
		PM_SUSPENDED = 0x0, // Counter OFF
		PM_VSU0_FMA = 0xa084, // two flops operation (fmadd
		PM_CMPLU_STALL_SCALAR = 0x40012, // Completion stall caused by FPU instruction
		PM_STCX_FAIL = 0xc09a, // STCX failed
		PM_VSU0_FSQRT_FDIV_DOUBLE = 0xa094, // eight flop DP vector operations (xvfdivdp
		PM_DC_PREF_DST = 0xd0b0, // Data Stream Touch
		PM_VSU1_SCAL_SINGLE_ISSUED = 0xb086, // Single Precision scalar instruction issued on Pipe1
		PM_L3_HIT = 0x1f080, // L3 Hits
		PM_L2_GLOB_GUESS_WRONG = 0x26482, // L2 guess glb and guess was not correct (ie data local)
		PM_MRK_DFU_FIN = 0x20032, // Decimal Unit marked Instruction Finish
		PM_INST_FROM_L1 = 0x4080, // Instruction fetches from L1
		PM_BRU_FIN = 0x10068, // Branch Instruction Finished
		PM_IC_DEMAND_REQ = 0x4088, // Demand Instruction fetch request
		PM_VSU1_FSQRT_FDIV_DOUBLE = 0xa096, // eight flop DP vector operations (xvfdivdp
		PM_VSU1_FMA = 0xa086, // two flops operation (fmadd
		PM_MRK_LD_MISS_L1 = 0x20036, // Marked DL1 Demand Miss
		PM_VSU0_2FLOP_DOUBLE = 0xa08c, // two flop DP vector operation (xvadddp
		PM_LSU_DC_PREF_STRIDED_STREAM_CONFIRM = 0xd8bc, // Dcache Strided prefetch stream confirmed (software + hardware)
		PM_INST_PTEG_FROM_L31_SHR = 0x2e056, // Instruction PTEG loaded from another L3 on same chip shared
		PM_MRK_LSU_REJECT_ERAT_MISS = 0x30064, // LSU marked reject due to ERAT (up to 2 per cycle)
		PM_MRK_DATA_FROM_L2MISS = 0x4d048, // Marked data loaded missed L2
		PM_DATA_FROM_RL2L3_SHR = 0x1c04c, // Data loaded from remote L2 or L3 shared
		PM_INST_FROM_PREF = 0x14046, // Instruction fetched from prefetch
		PM_VSU1_SQ = 0xb09e, // Store Vector Issued on Pipe1
		PM_L2_LD_DISP = 0x36180, // All successful load dispatches
		PM_L2_DISP_ALL = 0x46080, // All successful LD/ST dispatches for this thread(i+d)
		PM_THRD_GRP_CMPL_BOTH_CYC = 0x10012, // Cycles group completed by both threads
		PM_VSU_FSQRT_FDIV_DOUBLE = 0xa894, // DP vector versions of fdiv
		PM_BR_MPRED = 0x400f6, // Number of Branch Mispredicts
		PM_INST_PTEG_FROM_DL2L3_SHR = 0x3e054, // Instruction PTEG loaded from remote L2 or L3 shared
		PM_VSU_1FLOP = 0xa880, // one flop (fadd
		PM_HV_CYC = 0x2000a, // cycles in hypervisor mode
		PM_MRK_DATA_FROM_RL2L3_SHR = 0x1d04c, // Marked data loaded from remote L2 or L3 shared
		PM_DTLB_MISS_16M = 0x4c05e, // Data TLB miss for 16M page
		PM_MRK_LSU_FIN = 0x40032, // Marked LSU instruction finished
		PM_LSU1_LMQ_LHR_MERGE = 0xd09a, // LS1 Load Merge with another cacheline request
		PM_IFU_FIN = 0x40066, // IFU Finished a (non-branch) instruction
		PM_1THRD_CON_RUN_INSTR = 0x30062, // 1 thread Concurrent Run Instructions
		PM_CMPLU_STALL_COUNT = 0x4000B, // Marked LSU instruction finished
		PM_MEM0_PB_RD_CL = 0x30083, // Nest events (MC0/MC1/PB/GX)
		PM_THRD_1_RUN_CYC = 0x10060, // 1 thread in Run Cycles
		PM_THRD_2_CONC_RUN_INSTR = 0x40062, // 2 thread Concurrent Run Instructions
		PM_THRD_2_RUN_CYC = 0x20060, // 2 thread in Run Cycles
		PM_THRD_3_CONC_RUN_INST = 0x10062, // 3 thread in Run Cycles
		PM_THRD_3_RUN_CYC = 0x30060, // 3 thread in Run Cycles
		PM_THRD_4_CONC_RUN_INST = 0x20062, // 4 thread in Run Cycles
		PM_THRD_4_RUN_CYC = 0x40060, // 4 thread in Run Cycles
		
	};
};

namespace power7 = optkit::ibm::power7;