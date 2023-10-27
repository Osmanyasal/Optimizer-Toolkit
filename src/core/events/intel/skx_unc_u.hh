#include <cstdint>

namespace optkit_intel{
	enum class skx_unc_u : uint64_t {
		UNC_U_EVENT_MSG = 0x42, // Virtual Logical Wire (legacy) message were received from Uncore.
		UNC_U_EVENT_MSG_MASK_DOORBELL_RCVD = 0x800, // Message Received --
		UNC_U_EVENT_MSG_MASK_INT_PRIO = 0x1000, // Message Received --
		UNC_U_EVENT_MSG_MASK_IPI_RCVD = 0x400, // Message Received -- IPI
		UNC_U_EVENT_MSG_MASK_MSI_RCVD = 0x200, // Message Received -- MSI
		UNC_U_EVENT_MSG_MASK_VLW_RCVD = 0x100, // Message Received -- VLW
		UNC_U_LOCK_CYCLES = 0x44, // Number of times an IDI Lock/SplitLock sequence was started
		UNC_U_PHOLD_CYCLES = 0x45, // PHOLD cycles.
		UNC_U_PHOLD_CYCLES_MASK_ASSERT_TO_ACK = 0x100, // Cycles PHOLD Assert to Ack -- Assert to ACK
		UNC_U_RACU_DRNG = 0x4c, // TBD
		UNC_U_RACU_DRNG_MASK_PFTCH_BUF_EMPTY = 0x400, // TBD
		UNC_U_RACU_DRNG_MASK_RDRAND = 0x100, // TBD
		UNC_U_RACU_DRNG_MASK_RDSEED = 0x200, // TBD
		UNC_U_RACU_REQUESTS = 0x46, // Number outstanding register requests within message channel tracker
		};};