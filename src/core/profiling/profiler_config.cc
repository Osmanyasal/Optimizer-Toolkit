
#include <profiler_config.hh>

namespace optkit::core
{
    ProfilerConfig::ProfilerConfig(bool is_reset_after_read, bool is_grouped, int pid, int cpu) : is_reset_after_read{is_reset_after_read}, is_grouped{is_grouped}, pid{pid}, cpu{cpu}
    {
        ::memset(&perf_event_config, 0, sizeof(perf_event_attr));
        perf_event_config.type = PERF_TYPE_RAW;
        perf_event_config.size = sizeof(perf_event_attr);
        perf_event_config.disabled = 1;
        perf_event_config.inherit = 1;
        perf_event_config.exclude_kernel = 1;
        perf_event_config.exclude_hv = 1;
        if (is_grouped)
            perf_event_config.read_format = PERF_FORMAT_GROUP | PERF_FORMAT_ID;
    }

    RaplConfig::RaplConfig(RaplReadMethods read_method, int32_t monitor_domain, bool is_reset_after_read) : read_method{read_method}, monitor_domain{monitor_domain}, is_reset_after_read{is_reset_after_read}
    {
    }

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, const optkit::core::RaplConfig &rapl_config)
{

    os << "Rapl Config(Read Method - Monitor Domain):\n";
    os << "  " << optkit::core::rapl_read_method_name_mapping.at((int32_t)rapl_config.read_method) << " ";

    if (rapl_config.monitor_domain & (int32_t)optkit::core::RaplDomain::PP0)
    {
        os << "PP0 ";
    }
    if (rapl_config.monitor_domain & (int32_t)optkit::core::RaplDomain::PP1)
    {
        os << "PP1 ";
    }
    if (rapl_config.monitor_domain &  (int32_t)optkit::core::RaplDomain::PACKAGE)
    {
        os << "PACKAGE ";
    }
    if (rapl_config.monitor_domain & (int32_t)optkit::core::RaplDomain::PSYS)
    {
        os << "PSYS ";
    }
    if (rapl_config.monitor_domain & (int32_t)optkit::core::RaplDomain::DRAM)
    {
        os << "DRAM ";
    } 
    return os;
}