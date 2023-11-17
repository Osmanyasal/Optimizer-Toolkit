#include <rapl_perf_reader.hh>

namespace optkit::core
{

    RaplPerfReader::RaplPerfReader(const RaplPerfReaderConfig &rapl_perf_config) : rapl_perf_config{rapl_perf_config}
    {
        std::cout << "Hello from RaplPerfReader\n";
        std::cout << rapl_perf_config << std::endl;
    }
    RaplPerfReader::~RaplPerfReader()
    {
    }
    void RaplPerfReader::disable()
    {
    }
    void RaplPerfReader::enable()
    {
    }
    std::unordered_map<int32_t, std::unordered_map<RaplDomain, int32_t>> RaplPerfReader::read()
    {
        std::unordered_map<int32_t, std::unordered_map<RaplDomain, int32_t>> result;

        return result;
    }

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, const optkit::core::RaplPerfReaderConfig &config)
{
    os << "RaplPerfReaderConfig:\n";
    os << "Packages:\n";
    for (const auto &package : config.packages)
    {
        os << "  Package " << package.first << ": ";
        for (const auto &value : package.second)
        {
            os << value << " ";
        } 
        os << "\n";
    }
    os << "Available Domains:\n";
    for (const auto &domain : config.avail_domains)
    {
        os << "  " << domain << "\n";
    }
    os << "Rapl Config:\n";
    os << "  " << config.rapl_config.read_method << " " << config.rapl_config.monitor_domain << "\n";

    return os;
}
