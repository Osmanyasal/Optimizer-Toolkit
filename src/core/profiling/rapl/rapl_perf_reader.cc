#include <rapl_perf_reader.hh>

namespace optkit::core
{

    RaplPerfReader::RaplPerfReader(const RaplPerfReaderConfig &rapl_perf_config) : rapl_perf_config{rapl_perf_config}
    {
        std::cout << rapl_perf_config << std::endl;
        static std::string s_type = read_file("/sys/bus/event_source/devices/power/type");
        static int32_t type = std::atoi(s_type.c_str());

        struct perf_event_attr attr;

        fd__package__domain = new int *[rapl_perf_config.packages.size()];
        for (size_t package = 0; package < rapl_perf_config.packages.size(); package++)
        {   
            fd__package__domain[package] = new int[rapl_perf_config.avail_domains.size()];

            for (int domain = 0; domain < rapl_perf_config.avail_domains.size(); domain++)
            {
                auto selected_domain = rapl_perf_config.avail_domains[domain];
                fd__package__domain[package][domain] = -1;

                if(!((int32_t)selected_domain.domain & rapl_perf_config.rapl_config.monitor_domain)){
                    std::cout << selected_domain.domain << " is being skipped!\n";
                    continue;
                } 
                ::memset(&attr, 0x0, sizeof(attr));
                attr.type = type;
                attr.config = selected_domain.config;
                if(attr.config == 0)
                    continue;
                fd__package__domain[package][domain] = perf_event_open(&attr, -1, package, -1, 0);
                if (fd__package__domain[package][domain] < 0)
                {
                    OPTKIT_CORE_ERROR("RAPL PERF: SOMETHING WENT WRONG!! {}", fd__package__domain[package][domain]);
                }
            }
        }

    }
    RaplPerfReader::~RaplPerfReader()
    {
        long long value; 
        for (int package = 0; package < rapl_perf_config.packages.size(); package++)
        {
            std::cout << "\tPackage " << package << "\n";
            for (int domain = 0; domain < rapl_perf_config.avail_domains.size(); domain++)
            { 
                auto selected_domain = rapl_perf_config.avail_domains[domain];
                if (!((int32_t)selected_domain.domain & rapl_perf_config.rapl_config.monitor_domain))
                {
                    std::cout << selected_domain.domain << " is being skipped!\n";
                    continue;
                }
                if (fd__package__domain[package][domain] != -1)
                {
                    value = 0;
                    ::read(fd__package__domain[package][domain], &value, 8);
                    ::close(fd__package__domain[package][domain]);

                    std::cout << "\t\t" << rapl_perf_config.avail_domains.at(domain).event
                              << " Energy Consumed: " << (double)value * rapl_perf_config.avail_domains.at(domain).scale
                              << " " << rapl_perf_config.avail_domains.at(domain).units << "\n";
                }
            }
        }

        // Deallocate memory for 2D file pointers
        for (int i = 0; i < rapl_perf_config.packages.size(); ++i)
        {
            delete[] fd__package__domain[i];
        }
        delete[] fd__package__domain;
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
    os << "\nRaplPerfReaderConfig:\n";
    os << "---------------------:\n";
    os << "Packages(socket_ids - core_ids):\n";
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
    
    os << config.rapl_config << "\n";

    return os;
}
