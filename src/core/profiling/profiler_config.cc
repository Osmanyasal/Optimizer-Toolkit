
#include <profiler_config.hh>

namespace optkit::core
{
    ProfilerConfig::ProfilerConfig(bool dump_results_to_file, bool is_reset_after_read, bool is_grouped, int pid, int cpu)
        : dump_results_to_file{dump_results_to_file}, is_reset_after_read{is_reset_after_read}, is_grouped{is_grouped}, pid{pid}, cpu{cpu}
    {
        ::memset(&perf_event_config, 0, sizeof(perf_event_attr));
        perf_event_config.type = PERF_TYPE_RAW;
        perf_event_config.size = sizeof(perf_event_attr);
        perf_event_config.disabled = 1;
        perf_event_config.inherit = 1;
        perf_event_config.exclude_kernel = 1;
        perf_event_config.exclude_hv = 1;
        if (this->is_grouped)
            perf_event_config.read_format = PERF_FORMAT_GROUP | PERF_FORMAT_ID;
    }

    ProfilerConfig::ProfilerConfig(perf_event_attr perf_event_config, bool dump_results_to_file, bool is_reset_after_read, int pid, int cpu) : dump_results_to_file{dump_results_to_file}, is_reset_after_read{is_reset_after_read}, pid{pid}, cpu{cpu}, perf_event_config{perf_event_config}
    {
        if (perf_event_config.read_format == (PERF_FORMAT_GROUP | PERF_FORMAT_ID))
            this->is_grouped = true;
        else
            this->is_grouped = false;
    }

    RaplConfig::RaplConfig(rapl::RaplReadMethods read_method, int32_t monitor_domain, bool is_reset_after_read, bool dump_results_to_file) : read_method{read_method}, monitor_domain{monitor_domain}, is_reset_after_read{is_reset_after_read}, dump_results_to_file{dump_results_to_file}
    {
    }

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, const optkit::core::RaplConfig &rapl_config)
{

    os << "Rapl Config(Read Method - Monitor Domain):\n";
    os << "  " << optkit::core::rapl::rapl_read_method_name_mapping.at((int32_t)rapl_config.read_method) << " ";

    if (rapl_config.monitor_domain & (int32_t)optkit::core::rapl::RaplDomain::PP0)
    {
        os << "PP0 ";
    }
    if (rapl_config.monitor_domain & (int32_t)optkit::core::rapl::RaplDomain::PP1)
    {
        os << "PP1 ";
    }
    if (rapl_config.monitor_domain & (int32_t)optkit::core::rapl::RaplDomain::PACKAGE)
    {
        os << "PACKAGE ";
    }
    if (rapl_config.monitor_domain & (int32_t)optkit::core::rapl::RaplDomain::PSYS)
    {
        os << "PSYS ";
    }
    if (rapl_config.monitor_domain & (int32_t)optkit::core::rapl::RaplDomain::DRAM)
    {
        os << "DRAM ";
    }
    return os;
}