#include <rapl_profiler.hh>

namespace optkit::core
{

    RaplProfiler::RaplProfiler(const RaplConfig &config) : rapl_config{config}
    {
        begin = read();
    }

    RaplProfiler::~RaplProfiler()
    {
        end = read();
    }

    void RaplProfiler::disable()
    {
        OPTKIT_CORE_WARN("Rapl cannot be disabled");
    }
    void RaplProfiler::enable()
    {
        OPTKIT_CORE_WARN("Rapl is always enabled");
    }

    std::unordered_map<RaplDomain, uint32_t> RaplProfiler::read()
    {
        std::unordered_map<RaplDomain, uint32_t> result;

        switch (rapl_config.read_method)
        {
        case RaplReadMethods::MSR:
            return read_msr();
            break;

        case RaplReadMethods::PERF:
            return read_perf();
            break;

        case RaplReadMethods::POWERCAP:
            return read_powercap();

        default:
            OPTKIT_CORE_WARN("Unknown Rapl read method!");
            break;
        }

        return result;
    }

    std::unordered_map<RaplDomain, uint32_t> RaplProfiler::read_perf()
    {
        std::unordered_map<RaplDomain, uint32_t> result;

        return result;
    }

    std::unordered_map<RaplDomain, uint32_t> RaplProfiler::read_powercap()
    {
        std::unordered_map<RaplDomain, uint32_t> result;

        return result;
    }

    std::unordered_map<RaplDomain, uint32_t> RaplProfiler::read_msr()
    {
        OPTKIT_CORE_WARN("MSR reading not implemented with this version!");
        std::unordered_map<RaplDomain, uint32_t> result;


        return result;
    }
} // namespace optkit::core

// Overloading << for unordered_map with RaplDomain as keys
std::ostream &operator<<(std::ostream &os, const std::unordered_map<optkit::core::RaplDomain, uint32_t> &map)
{
    os << "{ ";
    for (const auto &pair : map)
    {
        os << pair.first << ": " << pair.second << ", ";
    }
    os << "}";
    return os;
}
