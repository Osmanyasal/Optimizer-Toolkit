
#include <base_profiler.hh>

namespace optkit::core
{
    ProfilerConfig::ProfilerConfig(bool is_grouped, int pid, int cpu) : is_grouped{is_grouped}, pid{pid}, cpu{cpu}
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

} // namespace optkit::core
