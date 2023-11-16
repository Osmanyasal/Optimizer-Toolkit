#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__RAPL_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__RAPL_HH

#include <ostream>
namespace optkit::core
{

    /**
     * @brief All available rapl domain by 2023<br>
     * check intel_rapl for more information.
     *
     */
    enum class RaplDomain
    {
        BEGIN = 0,

        PP0 = 1,            // CORES
        PP1 = (1 << 1),     // INTEGRATED GPU
        PACKAGE = (1 << 2), // PP0 + PP1 + SYSTEM AGENT + LAST_LEVEL_CACHE MEMORY CONTROLLER
        PSYS = (1 << 3),    // PACKAGE + eDRAM + PCH
        DRAM = (1 << 4),    // DRAM DIMM 0 and DRAM DIMM 1
        ALL = (11111),      // All domains
        END,

    };

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, optkit::core::RaplDomain domain);

#endif