#include <cstdint>

namespace optkit::intel{
	enum class snbep_unc_u : uint64_t {
		UNC_U_EVENT_MSG = 0x42, // VLW Received
		UNC_U_EVENT_MSG_MASK_DOORBELL_RCVD = 0x800, // TBD
		UNC_U_EVENT_MSG_MASK_INT_PRIO = 0x1000, // TBD
		UNC_U_EVENT_MSG_MASK_IPI_RCVD = 0x400, // TBD
		UNC_U_EVENT_MSG_MASK_MSI_RCVD = 0x200, // TBD
		UNC_U_EVENT_MSG_MASK_VLW_RCVD = 0x100, // TBD
		UNC_U_LOCK_CYCLES = 0x44, // IDI Lock/SplitLock Cycles
		
	};
};