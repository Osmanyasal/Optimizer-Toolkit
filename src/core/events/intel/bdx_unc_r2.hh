#include <cstdint>

namespace optkit_intel{
	enum class bdx_unc_r2 : uint64_t {
		UNC_R2_CLOCKTICKS = 0x1, // Counts the number of uclks in the R2PCIe uclk domain.  This could be slightly different than the count in the Ubox because of enable/freeze delays.  However
		UNC_R2_IIO_CREDIT = 0x2d, // TBD
		UNC_R2_IIO_CREDIT_MASK_ISOCH_QPI0 = 0x400, // TBD
		UNC_R2_IIO_CREDIT_MASK_ISOCH_QPI1 = 0x800, // TBD
		UNC_R2_IIO_CREDIT_MASK_PRQ_QPI0 = 0x100, // TBD
		UNC_R2_IIO_CREDIT_MASK_PRQ_QPI1 = 0x200, // TBD
		UNC_R2_RING_AD_USED = 0x7, // Counts the number of cycles that the AD ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk
		UNC_R2_RING_AD_USED_MASK_CCW = 0xc00, // Counterclockwise
		UNC_R2_RING_AD_USED_MASK_CCW_EVEN = 0x400, // Counterclockwise and Even
		UNC_R2_RING_AD_USED_MASK_CCW_ODD = 0x800, // Counterclockwise and Odd
		UNC_R2_RING_AD_USED_MASK_CW = 0x300, // Clockwise
		UNC_R2_RING_AD_USED_MASK_CW_EVEN = 0x100, // Clockwise and Even
		UNC_R2_RING_AD_USED_MASK_CW_ODD = 0x200, // Clockwise and Odd
		UNC_R2_RING_AK_BOUNCES = 0x12, // Counts the number of times when a request destined for the AK ingress bounced.
		UNC_R2_RING_AK_BOUNCES_MASK_DN = 0x200, // AK Ingress Bounced -- Dn
		UNC_R2_RING_AK_BOUNCES_MASK_UP = 0x100, // AK Ingress Bounced -- Up
		UNC_R2_RING_AK_USED = 0x8, // Counts the number of cycles that the AK ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk
		UNC_R2_RING_AK_USED_MASK_CCW = 0xc00, // Counterclockwise
		UNC_R2_RING_AK_USED_MASK_CCW_EVEN = 0x400, // Counterclockwise and Even
		UNC_R2_RING_AK_USED_MASK_CCW_ODD = 0x800, // Counterclockwise and Odd
		UNC_R2_RING_AK_USED_MASK_CW = 0x300, // Clockwise
		UNC_R2_RING_AK_USED_MASK_CW_EVEN = 0x100, // Clockwise and Even
		UNC_R2_RING_AK_USED_MASK_CW_ODD = 0x200, // Clockwise and Odd
		UNC_R2_RING_BL_USED = 0x9, // Counts the number of cycles that the BL ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sunk
		UNC_R2_RING_BL_USED_MASK_CCW = 0xc00, // Counterclockwise
		UNC_R2_RING_BL_USED_MASK_CCW_EVEN = 0x400, // Counterclockwise and Even
		UNC_R2_RING_BL_USED_MASK_CCW_ODD = 0x800, // Counterclockwise and Odd
		UNC_R2_RING_BL_USED_MASK_CW = 0x300, // Clockwise
		UNC_R2_RING_BL_USED_MASK_CW_EVEN = 0x100, // Clockwise and Even
		UNC_R2_RING_BL_USED_MASK_CW_ODD = 0x200, // Clockwise and Odd
		UNC_R2_RING_IV_USED = 0xa, // Counts the number of cycles that the IV ring is being used at this ring stop.  This includes when packets are passing by and when packets are being sent
		UNC_R2_RING_IV_USED_MASK_ANY = 0xf00, // Any directions
		UNC_R2_RING_IV_USED_MASK_CCW = 0xc00, // Counterclockwise
		UNC_R2_RING_IV_USED_MASK_CW = 0x300, // Clockwise
		UNC_R2_RXR_CYCLES_NE = 0x10, // Counts the number of cycles when the R2PCIe Ingress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue occupancy.  Multiple ingress buffers can be tracked at a given time using multiple counters.
		UNC_R2_RXR_CYCLES_NE_MASK_NCB = 0x1000, // NCB
		UNC_R2_RXR_CYCLES_NE_MASK_NCS = 0x2000, // NCS
		UNC_R2_RXR_INSERTS = 0x11, // Counts the number of allocations into the R2PCIe Ingress.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Ingress Occupancy Accumulator event in order to calculate average queue latency.  Multiple ingress buffers can be tracked at a given time using multiple counters.
		UNC_R2_RXR_INSERTS_MASK_NCB = 0x1000, // NCB
		UNC_R2_RXR_INSERTS_MASK_NCS = 0x2000, // NCS
		UNC_R2_RXR_OCCUPANCY = 0x13, // Accumulates the occupancy of a given R2PCIe Ingress queue in each cycles.  This tracks one of the three ring Ingress buffers.  This can be used with the R2PCIe Ingress Not Empty event to calculate average occupancy or the R2PCIe Ingress Allocations event in order to calculate average queuing latency.
		UNC_R2_RXR_OCCUPANCY_MASK_DRS = 0x800, // Ingress Occupancy Accumulator -- DRS
		UNC_R2_SBO0_CREDITS_ACQUIRED = 0x28, // Number of Sbo 0 credits acquired in a given cycle
		UNC_R2_SBO0_CREDITS_ACQUIRED_MASK_AD = 0x100, // SBo0 Credits Acquired -- For AD Ring
		UNC_R2_SBO0_CREDITS_ACQUIRED_MASK_BL = 0x200, // SBo0 Credits Acquired -- For BL Ring
		UNC_R2_STALL_NO_SBO_CREDIT = 0x2c, // Number of cycles Egress is stalled waiting for an Sbo credit to become available.  Per Sbo
		UNC_R2_STALL_NO_SBO_CREDIT_MASK_SBO0_AD = 0x100, // Stall on No Sbo Credits -- For SBo0
		UNC_R2_STALL_NO_SBO_CREDIT_MASK_SBO0_BL = 0x400, // Stall on No Sbo Credits -- For SBo0
		UNC_R2_STALL_NO_SBO_CREDIT_MASK_SBO1_AD = 0x200, // Stall on No Sbo Credits -- For SBo1
		UNC_R2_STALL_NO_SBO_CREDIT_MASK_SBO1_BL = 0x800, // Stall on No Sbo Credits -- For SBo1
		UNC_R2_TXR_CYCLES_FULL = 0x25, // Counts the number of cycles when the R2PCIe Egress buffer is full.
		UNC_R2_TXR_CYCLES_FULL_MASK_AD = 0x100, // Egress Cycles Full -- AD
		UNC_R2_TXR_CYCLES_FULL_MASK_AK = 0x200, // Egress Cycles Full -- AK
		UNC_R2_TXR_CYCLES_FULL_MASK_BL = 0x400, // Egress Cycles Full -- BL
		UNC_R2_TXR_CYCLES_NE = 0x23, // Counts the number of cycles when the R2PCIe Egress is not empty.  This tracks one of the three rings that are used by the R2PCIe agent.  This can be used in conjunction with the R2PCIe Egress Occupancy Accumulator event in order to calculate average queue occupancy.  Only a single Egress queue can be tracked at any given time.  It is not possible to filter based on direction or polarity.
		UNC_R2_TXR_CYCLES_NE_MASK_AD = 0x100, // Egress Cycles Not Empty -- AD
		UNC_R2_TXR_CYCLES_NE_MASK_AK = 0x200, // Egress Cycles Not Empty -- AK
		UNC_R2_TXR_CYCLES_NE_MASK_BL = 0x400, // Egress Cycles Not Empty -- BL
		UNC_R2_TXR_NACK_CW = 0x26, // TBD
		UNC_R2_TXR_NACK_CW_MASK_DN_AD = 0x100, // Egress CCW NACK -- AD CCW
		UNC_R2_TXR_NACK_CW_MASK_DN_AK = 0x400, // Egress CCW NACK -- AK CCW
		UNC_R2_TXR_NACK_CW_MASK_DN_BL = 0x200, // Egress CCW NACK -- BL CCW
		UNC_R2_TXR_NACK_CW_MASK_UP_AD = 0x800, // Egress CCW NACK -- AK CCW
		UNC_R2_TXR_NACK_CW_MASK_UP_AK = 0x2000, // Egress CCW NACK -- BL CW
		UNC_R2_TXR_NACK_CW_MASK_UP_BL = 0x1000, // Egress CCW NACK -- BL CCW
		
	};
};