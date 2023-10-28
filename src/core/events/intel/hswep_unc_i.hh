#include <cstdint>

namespace optkit_intel{
	enum class hswep_unc_i : uint64_t {
		UNC_I_CLOCKTICKS = 0x0, // Number of uclks in domain
		UNC_I_SNOOP_RESP = 0x17, // Snoop responses
		UNC_I_SNOOP_RESP_MASK_MISS = 0x100, // Miss
		UNC_I_SNOOP_RESP_MASK_HIT_I = 0x200, // Hit in Invalid state
		UNC_I_SNOOP_RESP_MASK_HIT_ES = 0x400, // Hit in Exclusive or Shared state
		UNC_I_SNOOP_RESP_MASK_HIT_M = 0x800, // Hit in Modified state
		UNC_I_SNOOP_RESP_MASK_SNPCODE = 0x1000, // Snoop Code
		UNC_I_SNOOP_RESP_MASK_SNPDATA = 0x2000, // Snoop Data
		UNC_I_SNOOP_RESP_MASK_SNPINV = 0x4000, // Snoop Invalid
		UNC_I_MISC0 = 0x14, // Miscellaneous events
		UNC_I_MISC0_MASK_FAST_REQ = 0x100, // Fastpath requests
		UNC_I_MISC0_MASK_FAST_REJ = 0x200, // Fastpath rejects
		UNC_I_MISC0_MASK_2ND_RD_INSERT = 0x400, // Cache insert of read transaction as secondary
		UNC_I_MISC0_MASK_2ND_WR_INSERT = 0x800, // Cache insert of write transaction as secondary
		UNC_I_MISC0_MASK_2ND_ATOMIC_INSERT = 0x1000, // Cache insert of atomic transaction as secondary
		UNC_I_MISC0_MASK_FAST_XFER = 0x2000, // Fastpath trasnfers from primary to secondary
		UNC_I_MISC0_MASK_PF_ACK_HINT = 0x4000, // Prefetch ack hints from primary to secondary
		UNC_I_MISC0_MASK_PF_TIMEOUT = 0x8000, // Prefetch timeout
		UNC_I_COHERENT_OPS = 0x13, // Coherent operations
		UNC_I_COHERENT_OPS_MASK_PCIRDCUR = 0x100, // PCI read current
		UNC_I_COHERENT_OPS_MASK_CRD = 0x200, // CRD
		UNC_I_COHERENT_OPS_MASK_DRD = 0x400, // DRD
		UNC_I_COHERENT_OPS_MASK_RFO = 0x800, // RFO
		UNC_I_COHERENT_OPS_MASK_PCITOM = 0x1000, // DRITOM
		UNC_I_COHERENT_OPS_MASK_PCIDCAHINT = 0x2000, // PCIDCAHINT
		UNC_I_COHERENT_OPS_MASK_WBMTOI = 0x4000, // WBMTOI
		UNC_I_COHERENT_OPS_MASK_CFLUSH = 0x8000, // CFLUSH
		UNC_I_CACHE_TOTAL_OCCUPANCY = 0x12, // Total write cache occupancy
		UNC_I_CACHE_TOTAL_OCCUPANCY_MASK_ANY = 0x100, // Any source
		UNC_I_CACHE_TOTAL_OCCUPANCY_MASK_SOURCE = 0x200, // Track all requests from any source port
		UNC_I_RXR_AK_INSERTS = 0xa, // Egress cycles full
		UNC_I_RXR_BL_DRS_CYCLES_FULL = 0x4, // TBD
		UNC_I_RXR_BL_DRS_INSERTS = 0x1, // BL Ingress occupancy DRS
		UNC_I_RXR_BL_DRS_OCCUPANCY = 0x7, // TBD
		UNC_I_RXR_BL_NCB_CYCLES_FULL = 0x5, // TBD
		UNC_I_RXR_BL_NCB_INSERTS = 0x2, // BL Ingress occupancy NCB
		UNC_I_RXR_BL_NCB_OCCUPANCY = 0x8, // TBD
		UNC_I_RXR_BL_NCS_CYCLES_FULL = 0x6, // TBD
		UNC_I_RXR_BL_NCS_INSERTS = 0x3, // BL Ingress Occupancy NCS
		UNC_I_RXR_BL_NCS_OCCUPANCY = 0x9, // TBD
		UNC_I_TRANSACTIONS = 0x16, // Inbound transactions
		UNC_I_TRANSACTIONS_MASK_READS = 0x100, // Reads (not including prefetches)
		UNC_I_TRANSACTIONS_MASK_WRITES = 0x200, // Writes
		UNC_I_TRANSACTIONS_MASK_RD_PREF = 0x400, // Read prefetches
		UNC_I_TRANSACTIONS_MASK_WR_PREF = 0x800, // Write prefetches
		UNC_I_TRANSACTIONS_MASK_ATOMIC = 0x1000, // Atomic transactions
		UNC_I_TRANSACTIONS_MASK_OTHER = 0x2000, // Other kinds of transactions
		UNC_I_TRANSACTIONS_MASK_ORDERINGQ = 0x4000, // Track request coming from port designated in IRP OrderingQ filter
		UNC_I_MISC1 = 0x15, // Misc events
		UNC_I_MISC1_MASK_SLOW_I = 0x100, // Slow transfer of I-state cacheline
		UNC_I_MISC1_MASK_SLOW_S = 0x200, // Slow transfer of S-state cacheline
		UNC_I_MISC1_MASK_SLOW_E = 0x400, // Slow transfer of e-state cacheline
		UNC_I_MISC1_MASK_SLOW_M = 0x800, // Slow transfer of M-state cacheline
		UNC_I_MISC1_MASK_LOST_FWD = 0x1000, // LOST forwards
		UNC_I_MISC1_MASK_SEC_RCVD_INVLD = 0x2000, // Received Invalid
		UNC_I_MISC1_MASK_SEC_RCVD_VLD = 0x4000, // Received Valid
		UNC_I_MISC1_MASK_DATA_THROTTLE = 0x8000, // Data throttled
		UNC_I_TXR_AD_STALL_CREDIT_CYCLES = 0x18, // No AD Egress credit stalls
		UNC_I_TXR_BL_STALL_CREDIT_CYCLES = 0x19, // No BL Egress credit stalls
		UNC_I_TXR_DATA_INSERTS_NCB = 0xe, // Outbound read requests
		UNC_I_TXR_DATA_INSERTS_NCS = 0xf, // Outbound read requests
		UNC_I_TXR_REQUEST_OCCUPANCY = 0xd, // Outbound request queue occupancy
		
	};
};