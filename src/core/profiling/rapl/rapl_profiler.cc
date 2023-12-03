#include <rapl_profiler.hh>

namespace optkit::core
{
    RaplProfiler::RaplProfiler(const char *block_name, const char *event_name, const RaplConfig &config) : BaseProfiler{block_name, event_name}, rapl_config{config}
    {
        const std::map<int32_t, std::vector<int32_t>> &packages = Query::detect_packages();
        const std::vector<RaplDomainInfo> &avail_domains = Query::rapl_domain_info();

        // std::cout << rapl_config << std::endl;
        switch (rapl_config.read_method)
        {
        case RaplReadMethods::PERF:
            rapl_reader.reset(new RaplPerfReader{block_name, event_name, {packages, avail_domains, rapl_config}});
            break;

        case RaplReadMethods::MSR:
            // TODO:Implement MSR reader
            OPTKIT_CORE_WARN("MSR not implemented in this version! Switching to PERF.");
            rapl_reader.reset(new RaplPerfReader{block_name, event_name, {packages, avail_domains, rapl_config}});

            break;

        case RaplReadMethods::POWERCAP:
            // TODO:Implement POWERCAP reader
            OPTKIT_CORE_WARN("POWERCAP not implemented in this version! Switching to PERF.");
            rapl_reader.reset(new RaplPerfReader{block_name, event_name, {packages, avail_domains, rapl_config}});
            break;
        default:
            OPTKIT_CORE_WARN("unknown read method!");
            break;
        }
    }

    RaplProfiler::~RaplProfiler()
    {
        // disable clock now! 
        delete rapl_reader.release(); 
    }

    void RaplProfiler::disable()
    {
        OPTKIT_CORE_WARN("Rapl cannot be disabled");
    }
    void RaplProfiler::enable()
    {
        OPTKIT_CORE_WARN("Rapl is always enabled");
    }

    std::map<int32_t, std::map<RaplDomain, double>> RaplProfiler::read_val()
    {
        return rapl_reader->read_val();
    }

    std::string RaplProfiler::convert_buffer_to_json()
    {
        return rapl_reader->convert_buffer_to_json();
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
 