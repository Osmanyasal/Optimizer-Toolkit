#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__RAPL_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__RAPL_HH

#include <ostream>
#include <unordered_map>
namespace optkit::core
{
    /**
     * @brief All available rapl domain by 2023<br>
     * check intel_rapl for more information.
     *
     */
    enum class RaplDomain
    {
        BEGIN = 1,

        PP0 = 1,            // CORES
        PP1 = (1 << 1),     // INTEGRATED GPU
        PACKAGE = (1 << 2), // PP0 + PP1 + SYSTEM AGENT + LAST_LEVEL_CACHE MEMORY CONTROLLER
        PSYS = (1 << 3),    // PACKAGE + eDRAM + PCH
        DRAM = (1 << 4),    // DRAM DIMM 0 and DRAM DIMM 1
        
        END = (1 << 5),

        ALL = 11111,      // All domains
    };
    extern const std::unordered_map<int32_t, std::string> rapl_domain_name_mapping;

    /**
     * @brief Rapl Read Methods
     * 
     */
    enum class RaplReadMethods
    {
        PERF = (1 << 1),
        MSR = (1 << 2), //TODO: not supported ATM support later on.
        POWERCAP = (1 << 3),
    };

    extern const std::unordered_map<int32_t, std::string> rapl_read_method_name_mapping;

    struct RaplDomainInfo{
        std::string event;
        std::string config;
        std::string scale;
        std::string units;
    };

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, optkit::core::RaplDomain domain);
std::ostream &operator<<(std::ostream &os, optkit::core::RaplDomainInfo domain_info);
std::ostream &operator<<(std::ostream &os, optkit::core::RaplReadMethods read_method);
 
#endif