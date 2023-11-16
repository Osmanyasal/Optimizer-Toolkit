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
        BEGIN,

        PP0,     // CORES
        PP1,     // INTEGRATED GPU
        PACKAGE, // PP0 + PP1 + SYSTEM AGENT + LAST_LEVEL_CACHE MEMORY CONTROLLER
        PSYS,    // PACKAGE + eDRAM + PCH
        DRAM,    // DRAM DIMM 0 and DRAM DIMM 1

        END,

    };

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, optkit::core::RaplDomain domain);

#endif