#include <cstdint>

namespace optkit_niagara1{
	enum class pe : uint64_t {
		Instr_cnt = 0x0, // Number of instructions completed
		SB_full = 0x0, // Store-buffer full
		FP_instr_cnt = 0x1, // FPU instructions
		IC_miss = 0x2, // I-cache miss
		DC_miss = 0x3, // D-cache miss
		ITLB_miss = 0x4, // I-TLB miss
		DTLB_miss = 0x5, // D-TLB miss
		L2_imiss = 0x6, // E-cache instruction fetch miss
		L2_dmiss_ld = 0x7, // E-cache data load miss
		};};