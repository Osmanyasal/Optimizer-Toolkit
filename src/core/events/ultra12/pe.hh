#include <cstdint>

namespace optkit_ultra12{
	enum class pe : uint64_t {
		Cycle_cnt = 0x0, // Accumulated cycles
		Instr_cnt = 0x1, // Number of instructions completed
		Dispatch0_IC_miss = 0x2, // I-buffer is empty from I-Cache miss
		Dispatch0_storeBuf = 0x3, // Store buffer can not hold additional stores
		IC_ref = 0x8, // I-cache references
		DC_rd = 0x9, // D-cache read references (including accesses that subsequently trap)
		DC_wr = 0xa, // D-cache write references (including accesses that subsequently trap)
		Load_use = 0xb, // An instruction in the execute stage depends on an earlier load result that is not yet available
		EC_ref = 0xc, // Total E-cache references
		EC_write_hit_RDO = 0xd, // E-cache hits that do a read for ownership UPA transaction
		EC_snoop_inv = 0xe, // E-cache invalidates from the following UPA transactions: S_INV_REQ
		EC_rd_hit = 0xf, // E-cache read hits from D-cache misses
		Dispatch0_mispred = 0x2, // I-buffer is empty from Branch misprediction
		Dispatch0_FP_use = 0x3, // First instruction in the group depends on an earlier floating point result that is not yet available
		IC_hit = 0x8, // I-cache hits
		DC_rd_hit = 0x9, // D-cache read hits
		DC_wr_hit = 0xa, // D-cache write hits
		Load_use_RAW = 0xb, // There is a load use in the execute stage and there is a read-after-write hazard on the oldest outstanding load
		EC_hit = 0xc, // Total E-cache hits
		EC_wb = 0xd, // E-cache misses that do writebacks
		EC_snoop_cb = 0xe, // E-cache snoop copy-backs from the following UPA transactions: S_CPB_REQ
		EC_ic_hit = 0xf, // E-cache read hits from I-cache misses
		};};