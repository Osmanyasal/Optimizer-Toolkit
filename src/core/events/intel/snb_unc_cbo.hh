#include <cstdint>

namespace optkit::intel{
	enum class snb_unc_cbo : uint64_t {
		UNC_CBO_XSNP_RESPONSE = 0x22, // Snoop responses (must provide a snoop type and filter)
		UNC_CBO_XSNP_RESPONSE_MASK_MISS = 0x100, // Number of snoop misses
		UNC_CBO_XSNP_RESPONSE_MASK_INVAL = 0x200, // Number of snoop invalidates of a non-modified line
		UNC_CBO_XSNP_RESPONSE_MASK_HIT = 0x400, // Number of snoop hits of a non-modified line
		UNC_CBO_XSNP_RESPONSE_MASK_HITM = 0x800, // Number of snoop hits of a modified line
		UNC_CBO_XSNP_RESPONSE_MASK_INVAL_M = 0x1000, // Number of snoop invalidates of a modified line
		UNC_CBO_XSNP_RESPONSE_MASK_ANY_SNP = 0x1f00, // Number of snoops
		UNC_CBO_XSNP_RESPONSE_MASK_EXTERNAL_FILTER = 0x2000, // Filter on cross-core snoops initiated by this Cbox due to external snoop request
		UNC_CBO_XSNP_RESPONSE_MASK_XCORE_FILTER = 0x4000, // Filter on cross-core snoops initiated by this Cbox due to processor core memory request
		UNC_CBO_XSNP_RESPONSE_MASK_EVICTION_FILTER = 0x8000, // Filter on cross-core snoops initiated by this Cbox due to LLC eviction
		UNC_CBO_CACHE_LOOKUP = 0x34, // LLC cache lookups
		UNC_CBO_CACHE_LOOKUP_MASK_STATE_M = 0x100, // Number of LLC lookup requests for a line in modified state
		UNC_CBO_CACHE_LOOKUP_MASK_STATE_E = 0x200, // Number of LLC lookup requests for a line in exclusive state
		UNC_CBO_CACHE_LOOKUP_MASK_STATE_S = 0x400, // Number of LLC lookup requests for a line in shared state
		UNC_CBO_CACHE_LOOKUP_MASK_STATE_I = 0x800, // Number of LLC lookup requests for a line in invalid state
		UNC_CBO_CACHE_LOOKUP_MASK_STATE_MESI = 0xf00, // Number of LLC lookup requests for a line
		UNC_CBO_CACHE_LOOKUP_MASK_READ_FILTER = 0x1000, // Filter on processor core initiated cacheable read requests
		UNC_CBO_CACHE_LOOKUP_MASK_WRITE_FILTER = 0x2000, // Filter on processor core initiated cacheable write requests
		UNC_CBO_CACHE_LOOKUP_MASK_EXTSNP_FILTER = 0x4000, // Filter on external snoop requests
		UNC_CBO_CACHE_LOOKUP_MASK_ANY_FILTER = 0x8000, // Filter on any IRQ or IPQ initiated requests including uncacheable
		
	};
};