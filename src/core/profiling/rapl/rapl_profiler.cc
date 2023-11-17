#include <rapl_profiler.hh>

namespace optkit::core
{ 
    RaplProfiler::RaplProfiler(const RaplConfig &config) : rapl_config{config}
    {

        static const std::map<int32_t, std::vector<int32_t>> packages = Query::detect_packages();
        static const std::vector<RaplDomainInfo> avail_domains = Query::rapl_domain_info();

        switch (rapl_config.read_method)
        {
        case RaplReadMethods::PERF:
            rapl_reader.reset(new RaplPerfReader{{packages, avail_domains, rapl_config}});
            break;

        case RaplReadMethods::MSR:
            break;

        case RaplReadMethods::POWERCAP:
            break;
        default:
            break;
        }

        start = std::chrono::high_resolution_clock::now();
    }

    RaplProfiler::~RaplProfiler()
    {
        // disable clock now!
        auto end = std::chrono::high_resolution_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0f;
        std::cout << "Duration : " << duration_ms << std::endl;
    }

    void RaplProfiler::disable()
    {
        OPTKIT_CORE_WARN("Rapl cannot be disabled");
    }
    void RaplProfiler::enable()
    {
        OPTKIT_CORE_WARN("Rapl is always enabled");
    }

    std::unordered_map<int32_t, std::unordered_map<RaplDomain, int32_t>> RaplProfiler::read()
    {
        return rapl_reader->read();
    }

} // namespace optkit::core

// Overloading << for unordered_map with RaplDomain as keys
std::ostream &operator<<(std::ostream &os, const std::unordered_map<optkit::core::RaplDomain, int32_t> &map)
{
    os << "{ ";
    for (const auto &pair : map)
    {
        os << pair.first << ": " << pair.second << ", ";
    }
    os << "}";
    return os;
}
