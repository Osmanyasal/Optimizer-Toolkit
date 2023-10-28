#include <cstdint>

namespace optkit_intel{
	enum class ivbep_unc_r2 : uint64_t {
		UNC_R2_CLOCKTICKS = 0x1, // Number of uclks in domain
		UNC_R2_RING_AD_USED = 0x7, // R2 AD Ring in Use
		UNC_R2_RING_AD_USED_MASK_CCW_VR0_EVEN = 0x400, // Counter-clockwise and even ring polarity on virtual ring 0
		UNC_R2_RING_AD_USED_MASK_CCW_VR0_ODD = 0x800, // Counter-clockwise and odd ring polarity on virtual ring 0
		UNC_R2_RING_AD_USED_MASK_CW_VR0_EVEN = 0x100, // Clockwise and even ring polarity on virtual ring 0
		UNC_R2_RING_AD_USED_MASK_CW_VR0_ODD = 0x200, // Clockwise and odd ring polarity on virtual ring 0
		UNC_R2_RING_AD_USED_MASK_CCW_VR1_EVEN = 0x400, // Counter-clockwise and even ring polarity on virtual ring 1
		UNC_R2_RING_AD_USED_MASK_CCW_VR1_ODD = 0x800, // Counter-clockwise and odd ring polarity on virtual ring 1
		UNC_R2_RING_AD_USED_MASK_CW_VR1_EVEN = 0x100, // Clockwise and even ring polarity on virtual ring 1
		UNC_R2_RING_AD_USED_MASK_CW_VR1_ODD = 0x200, // Clockwise and odd ring polarity on virtual ring 1
		UNC_R2_RING_AD_USED_MASK_CW = 0x3300, // Clockwise with any polarity on either virtual rings
		UNC_R2_RING_AD_USED_MASK_CCW = 0xcc00, // Counter-clockwise with any polarity on either virtual rings
		UNC_R2_RING_AK_USED = 0x8, // R2 AK Ring in Use
		UNC_R2_RING_AK_USED_MASK_CCW_VR0_EVEN = 0x400, // Counter-clockwise and even ring polarity on virtual ring 0
		UNC_R2_RING_AK_USED_MASK_CCW_VR0_ODD = 0x800, // Counter-clockwise and odd ring polarity on virtual ring 0
		UNC_R2_RING_AK_USED_MASK_CW_VR0_EVEN = 0x100, // Clockwise and even ring polarity on virtual ring 0
		UNC_R2_RING_AK_USED_MASK_CW_VR0_ODD = 0x200, // Clockwise and odd ring polarity on virtual ring 0
		UNC_R2_RING_AK_USED_MASK_CCW_VR1_EVEN = 0x400, // Counter-clockwise and even ring polarity on virtual ring 1
		UNC_R2_RING_AK_USED_MASK_CCW_VR1_ODD = 0x800, // Counter-clockwise and odd ring polarity on virtual ring 1
		UNC_R2_RING_AK_USED_MASK_CW_VR1_EVEN = 0x100, // Clockwise and even ring polarity on virtual ring 1
		UNC_R2_RING_AK_USED_MASK_CW_VR1_ODD = 0x200, // Clockwise and odd ring polarity on virtual ring 1
		UNC_R2_RING_AK_USED_MASK_CW = 0x3300, // Clockwise with any polarity on either virtual rings
		UNC_R2_RING_AK_USED_MASK_CCW = 0xcc00, // Counter-clockwise with any polarity on either virtual rings
		UNC_R2_RING_BL_USED = 0x9, // R2 BL Ring in Use
		UNC_R2_RING_BL_USED_MASK_CCW_VR0_EVEN = 0x400, // Counter-clockwise and even ring polarity on virtual ring 0
		UNC_R2_RING_BL_USED_MASK_CCW_VR0_ODD = 0x800, // Counter-clockwise and odd ring polarity on virtual ring 0
		UNC_R2_RING_BL_USED_MASK_CW_VR0_EVEN = 0x100, // Clockwise and even ring polarity on virtual ring 0
		UNC_R2_RING_BL_USED_MASK_CW_VR0_ODD = 0x200, // Clockwise and odd ring polarity on virtual ring 0
		UNC_R2_RING_BL_USED_MASK_CCW_VR1_EVEN = 0x400, // Counter-clockwise and even ring polarity on virtual ring 1
		UNC_R2_RING_BL_USED_MASK_CCW_VR1_ODD = 0x800, // Counter-clockwise and odd ring polarity on virtual ring 1
		UNC_R2_RING_BL_USED_MASK_CW_VR1_EVEN = 0x100, // Clockwise and even ring polarity on virtual ring 1
		UNC_R2_RING_BL_USED_MASK_CW_VR1_ODD = 0x200, // Clockwise and odd ring polarity on virtual ring 1
		UNC_R2_RING_BL_USED_MASK_CW = 0x3300, // Clockwise with any polarity on either virtual rings
		UNC_R2_RING_BL_USED_MASK_CCW = 0xcc00, // Counter-clockwise with any polarity on either virtual rings
		UNC_R2_RING_IV_USED = 0xa, // R2 IV Ring in Use
		UNC_R2_RING_IV_USED_MASK_CW = 0x3300, // Clockwise with any polarity on either virtual rings
		UNC_R2_RING_IV_USED_MASK_CCW = 0xcc00, // Counter-clockwise with any polarity on either virtual rings
		UNC_R2_RING_IV_USED_MASK_ANY = 0xff00, // any direction and any polarity on any virtual ring
		UNC_R2_RXR_AK_BOUNCES = 0x12, // AK Ingress Bounced
		UNC_R2_RXR_AK_BOUNCES_MASK_CW = 0x100, // Clockwise
		UNC_R2_RXR_AK_BOUNCES_MASK_CCW = 0x200, // Counter-clockwise
		UNC_R2_RXR_OCCUPANCY = 0x13, // Ingress occupancy accumulator
		UNC_R2_RXR_OCCUPANCY_MASK_DRS = 0x800, // DRS Ingress queue
		UNC_R2_RXR_CYCLES_NE = 0x10, // Ingress Cycles Not Empty
		UNC_R2_RXR_CYCLES_NE_MASK_NCB = 0x1000, // NCB Ingress queue
		UNC_R2_RXR_CYCLES_NE_MASK_NCS = 0x2000, // NCS Ingress queue
		UNC_R2_RXR_INSERTS = 0x11, // Ingress inserts
		UNC_R2_RXR_INSERTS_MASK_NCB = 0x1000, // NCB Ingress queue
		UNC_R2_RXR_INSERTS_MASK_NCS = 0x2000, // NCS Ingress queue
		UNC_R2_TXR_CYCLES_FULL = 0x25, // Egress Cycles Full
		UNC_R2_TXR_CYCLES_FULL_MASK_AD = 0x100, // AD Egress queue
		UNC_R2_TXR_CYCLES_FULL_MASK_AK = 0x200, // AK Egress queue
		UNC_R2_TXR_CYCLES_FULL_MASK_BL = 0x400, // BL Egress queue
		UNC_R2_TXR_CYCLES_NE = 0x23, // Egress Cycles Not Empty
		UNC_R2_TXR_CYCLES_NE_MASK_AD = 0x100, // AD Egress queue
		UNC_R2_TXR_CYCLES_NE_MASK_AK = 0x200, // AK Egress queue
		UNC_R2_TXR_CYCLES_NE_MASK_BL = 0x400, // BL Egress queue
		UNC_R2_TXR_NACK_CCW = 0x28, // Egress counter-clockwise BACK
		UNC_R2_TXR_NACK_CCW_MASK_AD = 0x100, // AD Egress queue
		UNC_R2_TXR_NACK_CCW_MASK_AK = 0x200, // AK Egress queue
		UNC_R2_TXR_NACK_CCW_MASK_BL = 0x400, // BL Egress queue
		UNC_R2_TXR_NACK_CW = 0x26, // Egress clockwise BACK
		UNC_R2_TXR_NACK_CW_MASK_AD = 0x100, // AD Egress queue
		UNC_R2_TXR_NACK_CW_MASK_AK = 0x200, // AK Egress queue
		UNC_R2_TXR_NACK_CW_MASK_BL = 0x400, // BL Egress queue
		
	};
};