#include <cstdint>

namespace optkit_intel{
	enum class hswep_unc_s : uint64_t {
		BL = 0x00, // S-box Uncore clockticks
		UNC_S_RING_AD_USED = 0x1b, // Address ring in use. Counts number of cycles ring is being used at this ring stop
		UNC_S_RING_AD_USED_MASK_UP_EVEN = 0x100, // Up and Even ring polarity filter
		UNC_S_RING_AD_USED_MASK_UP_ODD = 0x200, // Up and odd ring polarity filter
		UNC_S_RING_AD_USED_MASK_DOWN_EVEN = 0x400, // Down and even ring polarity filter
		UNC_S_RING_AD_USED_MASK_DOWN_ODD = 0x800, // Down and odd ring polarity filter
		UNC_S_RING_AD_USED_MASK_UP = 0x3300, // Up ring polarity filter
		UNC_S_RING_AD_USED_MASK_DOWN = 0xcc00, // Down ring polarity filter
		UNC_S_RING_AK_USED = 0x1c, // Acknowledgement ring in use. Counts number of cycles ring is being used at this ring stop
		UNC_S_RING_AK_USED_MASK_UP_EVEN = 0x100, // Up and Even ring polarity filter
		UNC_S_RING_AK_USED_MASK_UP_ODD = 0x200, // Up and odd ring polarity filter
		UNC_S_RING_AK_USED_MASK_DOWN_EVEN = 0x400, // Down and even ring polarity filter
		UNC_S_RING_AK_USED_MASK_DOWN_ODD = 0x800, // Down and odd ring polarity filter
		UNC_S_RING_AK_USED_MASK_UP = 0x3300, // Up ring polarity filter
		UNC_S_RING_AK_USED_MASK_DOWN = 0xcc00, // Down ring polarity filter
		UNC_S_RING_BL_USED = 0x1d, // Bus or Data ring in use. Counts number of cycles ring is being used at this ring stop
		UNC_S_RING_BL_USED_MASK_UP_EVEN = 0x100, // Up and Even ring polarity filter
		UNC_S_RING_BL_USED_MASK_UP_ODD = 0x200, // Up and odd ring polarity filter
		UNC_S_RING_BL_USED_MASK_DOWN_EVEN = 0x400, // Down and even ring polarity filter
		UNC_S_RING_BL_USED_MASK_DOWN_ODD = 0x800, // Down and odd ring polarity filter
		UNC_S_RING_BL_USED_MASK_UP = 0x3300, // Up ring polarity filter
		UNC_S_RING_BL_USED_MASK_DOWN = 0xcc00, // Down ring polarity filter
		UNC_S_RING_IV_USED = 0x1e, // Invalidate ring in use. Counts number of cycles ring is being used at this ring stop
		UNC_S_RING_IV_USED_MASK_ANY = 0x0f00, // Any filter
		UNC_S_RING_IV_USED_MASK_UP = 0x0300, // Filter on any up polarity
		UNC_S_RING_IV_USED_MASK_DOWN = 0xcc00, // Filter on any down polarity
		UNC_S_RING_BOUNCES = 0x05, // Number of LLC responses that bounced in the ring
		UNC_S_RING_BOUNCES_MASK_AD_CACHE = 0x100, // AD_CACHE
		UNC_S_RING_BOUNCES_MASK_AK_CORE = 0x200, // Acknowledgments to core
		UNC_S_RING_BOUNCES_MASK_BL_CORE = 0x400, // Data responses to core
		UNC_S_RING_BOUNCES_MASK_IV_CORE = 0x800, // Snoops of processor cache
		UNC_C_BOUNCE_CONTROL = 0x0a, // Bounce control
		UNC_S_RXR_OCCUPANCY = 0x11, // Ingress Occupancy
		UNC_S_RXR_OCCUPANCY_MASK_AD_CRD = 0x0100, // AD credis
		UNC_S_RXR_OCCUPANCY_MASK_AD_BNC = 0x0200, // AD bounces
		UNC_S_RXR_OCCUPANCY_MASK_BL_CRD = 0x0400, // BL credits
		UNC_S_RXR_OCCUPANCY_MASK_BL_BNC = 0x0800, // BL bounces
		UNC_S_RXR_OCCUPANCY_MASK_AK = 0x1000, // AK
		UNC_S_RXR_OCCUPANCY_MASK_IV = 0x2000, // IV
		UNC_S_RXR_BYPASS = 0x12, // Ingress Allocations
		UNC_S_RXR_BYPASS_MASK_AD_CRD = 0x0100, // AD credis
		UNC_S_RXR_BYPASS_MASK_AD_BNC = 0x0200, // AD bounces
		UNC_S_RXR_BYPASS_MASK_BL_CRD = 0x0400, // BL credits
		UNC_S_RXR_BYPASS_MASK_BL_BNC = 0x0800, // BL bounces
		UNC_S_RXR_BYPASS_MASK_AK = 0x1000, // AK
		UNC_S_RXR_BYPASS_MASK_IV = 0x2000, // IV
		UNC_S_RXR_INSERTS = 0x13, // Ingress Allocations
		UNC_S_RXR_INSERTS_MASK_AD_CRD = 0x0100, // AD credis
		UNC_S_RXR_INSERTS_MASK_AD_BNC = 0x0200, // AD bounces
		UNC_S_RXR_INSERTS_MASK_BL_CRD = 0x0400, // BL credits
		UNC_S_RXR_INSERTS_MASK_BL_BNC = 0x0800, // BL bounces
		UNC_S_RXR_INSERTS_MASK_AK = 0x1000, // AK
		UNC_S_RXR_INSERTS_MASK_IV = 0x2000, // IV
		UNC_S_TXR_ADS_USED = 0x04, // Egress events
		UNC_S_TXR_ADS_USED_MASK_AD = 0x100, // onto AD ring
		UNC_S_TXR_ADS_USED_MASK_AK = 0x200, // Onto AK ring
		UNC_S_TXR_INSERTS = 0x02, // Egress allocations
		UNC_S_TXR_INSERTS_MASK_AD_CRD = 0x0100, // AD credis
		UNC_S_TXR_INSERTS_MASK_AD_BNC = 0x0200, // AD bounces
		UNC_S_TXR_INSERTS_MASK_BL_CRD = 0x0400, // BL credits
		UNC_S_TXR_INSERTS_MASK_BL_BNC = 0x0800, // BL bounces
		UNC_S_TXR_INSERTS_MASK_AK = 0x1000, // AK
		UNC_S_TXR_INSERTS_MASK_IV = 0x2000, // IV
		UNC_S_TXR_OCCUPANCY = 0x01, // Egress allocations
		UNC_S_TXR_OCCUPANCY_MASK_AD_CRD = 0x0100, // AD credis
		UNC_S_TXR_OCCUPANCY_MASK_AD_BNC = 0x0200, // AD bounces
		UNC_S_TXR_OCCUPANCY_MASK_BL_CRD = 0x0400, // BL credits
		UNC_S_TXR_OCCUPANCY_MASK_BL_BNC = 0x0800, // BL bounces
		UNC_S_TXR_OCCUPANCY_MASK_AK = 0x1000, // AK
		UNC_S_TXR_OCCUPANCY_MASK_IV = 0x2000, // IV
		
	};
};