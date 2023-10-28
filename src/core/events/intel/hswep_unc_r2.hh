#include <cstdint>

namespace optkit::intel{
	enum class hswep_unc_r2 : uint64_t {
		UNC_R2_CLOCKTICKS = 0x1, // Number of uclks in domain
		UNC_R2_RING_AD_USED = 0x7, // R2 AD Ring in Use
		UNC_R2_RING_AD_USED_MASK_CCW_EVEN = 0x400, // Counter-clockwise and even ring polarity on virtual ring
		UNC_R2_RING_AD_USED_MASK_CCW_ODD = 0x800, // Counter-clockwise and odd ring polarity on virtual ring
		UNC_R2_RING_AD_USED_MASK_CW_EVEN = 0x100, // Clockwise and even ring polarity on virtual ring
		UNC_R2_RING_AD_USED_MASK_CW_ODD = 0x200, // Clockwise and odd ring polarity on virtual ring
		UNC_R2_RING_AD_USED_MASK_CW = 0x0300, // Clockwise with any polarity on either virtual rings
		UNC_R2_RING_AD_USED_MASK_CCW = 0x0c00, // Counter-clockwise with any polarity on either virtual rings
		UNC_R2_RING_AK_USED = 0x8, // R2 AK Ring in Use
		UNC_R2_RING_AK_USED_MASK_CCW_EVEN = 0x400, // Counter-clockwise and even ring polarity on virtual ring
		UNC_R2_RING_AK_USED_MASK_CCW_ODD = 0x800, // Counter-clockwise and odd ring polarity on virtual ring
		UNC_R2_RING_AK_USED_MASK_CW_EVEN = 0x100, // Clockwise and even ring polarity on virtual ring
		UNC_R2_RING_AK_USED_MASK_CW_ODD = 0x200, // Clockwise and odd ring polarity on virtual ring
		UNC_R2_RING_AK_USED_MASK_CW = 0x0300, // Clockwise with any polarity on either virtual rings
		UNC_R2_RING_AK_USED_MASK_CCW = 0x0c00, // Counter-clockwise with any polarity on either virtual rings
		UNC_R2_RING_BL_USED = 0x9, // R2 BL Ring in Use
		UNC_R2_RING_BL_USED_MASK_CCW_EVEN = 0x400, // Counter-clockwise and even ring polarity on virtual ring
		UNC_R2_RING_BL_USED_MASK_CCW_ODD = 0x800, // Counter-clockwise and odd ring polarity on virtual ring
		UNC_R2_RING_BL_USED_MASK_CW_EVEN = 0x100, // Clockwise and even ring polarity on virtual ring
		UNC_R2_RING_BL_USED_MASK_CW_ODD = 0x200, // Clockwise and odd ring polarity on virtual ring
		UNC_R2_RING_BL_USED_MASK_CW = 0x0300, // Clockwise with any polarity on either virtual rings
		UNC_R2_RING_BL_USED_MASK_CCW = 0x0c00, // Counter-clockwise with any polarity on either virtual rings
		UNC_R2_RING_IV_USED = 0xa, // R2 IV Ring in Use
		UNC_R2_RING_IV_USED_MASK_CW = 0x300, // Clockwise with any polarity on virtual ring
		UNC_R2_RING_IV_USED_MASK_CCW = 0xc00, // Counter-clockwise with any polarity on virtual ring
		UNC_R2_RING_IV_USED_MASK_ANY = 0xff00, // any direction and any polarity on virtual ring
		UNC_R2_RXR_AK_BOUNCES = 0x12, // AK Ingress Bounced
		UNC_R2_RXR_AK_BOUNCES_MASK_UP = 0x100, // Up
		UNC_R2_RXR_AK_BOUNCES_MASK_DOWN = 0x200, // Down
		UNC_R2_RXR_OCCUPANCY = 0x13, // Ingress occupancy accumulator
		UNC_R2_RXR_OCCUPANCY_MASK_DRS = 0x800, // DRS Ingress queue
		UNC_R2_RXR_CYCLES_NE = 0x10, // Ingress Cycles Not Empty
		UNC_R2_RXR_CYCLES_NE_MASK_NCB = 0x1000, // NCB Ingress queue
		UNC_R2_RXR_CYCLES_NE_MASK_NCS = 0x2000, // NCS Ingress queue
		UNC_R2_RXR_INSERTS = 0x11, // Ingress inserts
		UNC_R2_RXR_INSERTS_MASK_NCB = 0x1000, // NCB Ingress queue
		UNC_R2_RXR_INSERTS_MASK_NCS = 0x2000, // NCS Ingress queue
		UNC_R2_TXR_NACK_CW = 0x26, // Egress clockwise BACK
		UNC_R2_TXR_NACK_CW_MASK_DN_AD = 0x100, // AD counter clockwise Egress queue
		UNC_R2_TXR_NACK_CW_MASK_DN_BL = 0x200, // BL counter clockwise Egress queue
		UNC_R2_TXR_NACK_CW_MASK_DN_AK = 0x400, // AK counter clockwise Egress queue
		UNC_R2_TXR_NACK_CW_MASK_UP_AD = 0x800, // AD clockwise Egress queue
		UNC_R2_TXR_NACK_CW_MASK_UP_BL = 0x1000, // BL clockwise Egress queue
		UNC_R2_TXR_NACK_CW_MASK_UP_AK = 0x2000, // AK clockwise Egress queue
		UNC_R2_SBO0_CREDITS_ACQUIRED = 0x28, // SBO0 credits acquired
		UNC_R2_SBO0_CREDITS_ACQUIRED_MASK_AD = 0x100, // For ring AD
		UNC_R2_SBO0_CREDITS_ACQUIRED_MASK_BL = 0x200, // For ring BL
		UNC_R2_STALL_NO_SBO_CREDIT = 0x2c, // Stall on No SBo Credits
		UNC_R2_STALL_NO_SBO_CREDIT_MASK_SBO0_AD = 0x100, // For SBO0
		UNC_R2_STALL_NO_SBO_CREDIT_MASK_SBO1_AD = 0x100, // For SBO1
		UNC_R2_STALL_NO_SBO_CREDIT_MASK_SBO0_BL = 0x100, // For SBO0
		UNC_R2_STALL_NO_SBO_CREDIT_MASK_SBO1_BL = 0x100, // For SBO1
		UNC_R2_IIO_CREDIT = 0x2d, // Egress counter-clockwise BACK
		UNC_R2_IIO_CREDIT_MASK_PRQ_QPI0 = 0x100, // QPI0
		UNC_R2_IIO_CREDIT_MASK_PRQ_QPI1 = 0x200, // QPI1
		UNC_R2_IIO_CREDIT_MASK_ISOCH_QPI0 = 0x400, // Isochronous QPI0
		UNC_R2_IIO_CREDIT_MASK_ISOCH_QPI1 = 0x800, // Isochronous QPI1
		
	};
};