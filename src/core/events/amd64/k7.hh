#pragma once
#include <cstdint>
namespace optkit::amd64::k7{
	enum k7 : uint64_t {
		DATA_CACHE_ACCESSES = 0x40, // Data Cache Accesses
		DATA_CACHE_MISSES = 0x41, // Data Cache Misses
		DATA_CACHE_REFILLS = 0x42, // Data Cache Refills from L2
		DATA_CACHE_REFILLS__MASK__AMD64_K7_DATA_CACHE_REFILLS__L2_INVALID = 0x1, // Invalid line from L2
		DATA_CACHE_REFILLS__MASK__AMD64_K7_DATA_CACHE_REFILLS__L2_SHARED = 0x2, // Shared-state line from L2
		DATA_CACHE_REFILLS__MASK__AMD64_K7_DATA_CACHE_REFILLS__L2_EXCLUSIVE = 0x4, // Exclusive-state line from L2
		DATA_CACHE_REFILLS__MASK__AMD64_K7_DATA_CACHE_REFILLS__L2_OWNED = 0x8, // Owned-state line from L2
		DATA_CACHE_REFILLS__MASK__AMD64_K7_DATA_CACHE_REFILLS__L2_MODIFIED = 0x10, // Modified-state line from L2
		DATA_CACHE_REFILLS__MASK__AMD64_K7_DATA_CACHE_REFILLS__ALL = 0x1f, // Shared
		DATA_CACHE_REFILLS_FROM_SYSTEM = 0x43, // Data Cache Refills from System
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__INVALID = 0x1, // Invalid
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__SHARED = 0x2, // Shared
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__EXCLUSIVE = 0x4, // Exclusive
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__OWNED = 0x8, // Owned
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__MODIFIED = 0x10, // Modified
		DATA_CACHE_REFILLS_FROM_SYSTEM__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__ALL = 0x1f, // Invalid
		DATA_CACHE_LINES_EVICTED = 0x44, // Data Cache Lines Evicted
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__INVALID = 0x1, // Invalid
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__SHARED = 0x2, // Shared
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__EXCLUSIVE = 0x4, // Exclusive
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__OWNED = 0x8, // Owned
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__MODIFIED = 0x10, // Modified
		DATA_CACHE_LINES_EVICTED__MASK__AMD64_K7_DATA_CACHE_REFILLS_FROM_SYSTEM__ALL = 0x1f, // Invalid
		L1_DTLB_MISS_AND_L2_DTLB_HIT = 0x45, // L1 DTLB Miss and L2 DTLB Hit
		L1_DTLB_AND_L2_DTLB_MISS = 0x46, // L1 DTLB and L2 DTLB Miss
		MISALIGNED_ACCESSES = 0x47, // Misaligned Accesses
		CPU_CLK_UNHALTED = 0x76, // CPU Clocks not Halted
		INSTRUCTION_CACHE_FETCHES = 0x80, // Instruction Cache Fetches
		INSTRUCTION_CACHE_MISSES = 0x81, // Instruction Cache Misses
		L1_ITLB_MISS_AND_L2_ITLB_HIT = 0x84, // L1 ITLB Miss and L2 ITLB Hit
		L1_ITLB_MISS_AND_L2_ITLB_MISS = 0x85, // L1 ITLB Miss and L2 ITLB Miss
		RETIRED_INSTRUCTIONS = 0xc0, // Retired Instructions (includes exceptions
		RETIRED_UOPS = 0xc1, // Retired uops
		RETIRED_BRANCH_INSTRUCTIONS = 0xc2, // Retired Branch Instructions
		RETIRED_MISPREDICTED_BRANCH_INSTRUCTIONS = 0xc3, // Retired Mispredicted Branch Instructions
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS = 0xc4, // Retired Taken Branch Instructions
		RETIRED_TAKEN_BRANCH_INSTRUCTIONS_MISPREDICTED = 0xc5, // Retired Taken Branch Instructions Mispredicted
		RETIRED_FAR_CONTROL_TRANSFERS = 0xc6, // Retired Far Control Transfers
		RETIRED_BRANCH_RESYNCS = 0xc7, // Retired Branch Resyncs (only non-control transfer branches)
		INTERRUPTS_MASKED_CYCLES = 0xcd, // Interrupts-Masked Cycles
		INTERRUPTS_MASKED_CYCLES_WITH_INTERRUPT_PENDING = 0xce, // Interrupts-Masked Cycles with Interrupt Pending
		INTERRUPTS_TAKEN = 0xcf, // Interrupts Taken
		
	};
};

namespace k7 = optkit::amd64::k7;