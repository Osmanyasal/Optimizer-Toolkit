#include <rapl_profiler.hh>

namespace optkit::core
{
    RaplProfiler::RaplProfiler(const RaplConfig &config) : rapl_config{config}
    {
        const std::map<int32_t, std::vector<int32_t>>& packages = Query::detect_packages();
        const std::vector<RaplDomainInfo>& avail_domains = Query::rapl_domain_info();

        std::cout << rapl_config << std::endl;
        switch (rapl_config.read_method)
        {
        case RaplReadMethods::PERF:
            rapl_reader.reset(new RaplPerfReader{{packages, avail_domains, rapl_config}});
            break;

        case RaplReadMethods::MSR:
            // TODO:Implement MSR reader
            OPTKIT_CORE_WARN("MSR not implemented in this version! Switching to PERF.");
            rapl_reader.reset(new RaplPerfReader{{packages, avail_domains, rapl_config}});

            break;

        case RaplReadMethods::POWERCAP:
            // TODO:Implement POWERCAP reader
            OPTKIT_CORE_WARN("POWERCAP not implemented in this version! Switching to PERF.");
            rapl_reader.reset(new RaplPerfReader{{packages, avail_domains, rapl_config}});
            break;
        default:
            OPTKIT_CORE_WARN("unknown read method!");
            break;
        }

        start = std::chrono::high_resolution_clock::now();
    }

    RaplProfiler::~RaplProfiler()
    {
        // disable clock now!
        auto end = std::chrono::high_resolution_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0f;

        delete rapl_reader.release();
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

    std::map<int32_t, std::map<RaplDomain, double>> RaplProfiler::read()
    {
        return rapl_reader->read();
    }

} // namespace optkit::core

// Overloading << for map with RaplDomain as keys
std::ostream &operator<<(std::ostream &os, const std::map<optkit::core::RaplDomain, double> &map)
{

    for (const auto &item : map)
    {
        os << item.first << ": " << item.second << "\n";
    }

    return os;
}

std::ostream &operator<<(std::ostream &os, const std::map<int32_t, std::map<optkit::core::RaplDomain, double>> &map)
{
    const std::vector<optkit::core::RaplDomainInfo>& avail_domains = optkit::core::Query::rapl_domain_info();
    for (const auto &pair : map)
    {
        os << "\tPackage " << pair.first << "\n";
        for (const auto &innerpair : pair.second)
        {
            for (const auto &info : avail_domains)
            {
                if (info.domain == innerpair.first)
                {
                    os << "\t\t" << info.event << ": " << innerpair.second << " " << info.units << " Consumed.\n";
                }
            }
            
        }
    }
    return os;
}
