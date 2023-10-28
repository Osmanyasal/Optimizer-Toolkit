#include <cstdint>
#include <intel_priv.hh>
namespace optkit::intel{
	enum class knl_unc_edc_eclk : uint64_t {
		UNC_E_E_CLOCKTICKS = 0x00, // EDC ECLK clockticks (generic counters)
		UNC_E_RPQ_INSERTS = 0x0101, // Counts total number of EDC RPQ insers
		UNC_E_WPQ_INSERTS = 0x0102, // Counts total number of EDC WPQ insers
		
	};
};