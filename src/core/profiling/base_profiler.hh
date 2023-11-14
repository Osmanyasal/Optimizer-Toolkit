#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BASE_PROFILER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BASE_PROFILER_HH

#include <cstdint>
#include <vector>
#include <linux/perf_event.h>

namespace optkit::core
{
     
/**
 * @brief perf_event_open and general Profiler Configs.
 * @see perf_event.h for more detail.
 *
 */
struct ProfilerConfig
{
    /**
     * @brief Construct a new Profiler Config object
     *
     * @param pid
     * @param cpu
     * @param is_grouped
     * @see perf_event_open man page!
     * 
     *  pid == 0 and cpu == -1
     *        This measures the calling process/thread on any CPU.
     *
     *  pid == 0 and cpu >= 0
     *         This measures the calling process/thread only when running
     *         on the specified CPU.
     *
     * pid > 0 and cpu == -1
     *         This measures the specified process/thread on any CPU.
     *
     *  pid > 0 and cpu >= 0
     *         This measures the specified process/thread only when
     *         running on the specified CPU.
     *
     *  pid == -1 and cpu >= 0
     *         This measures all processes/threads on the specified CPU.
     *         This requires CAP_PERFMON (since Linux 5.8) or
     *         CAP_SYS_ADMIN capability or a
     *         /proc/sys/kernel/perf_event_paranoid value of less than 1.
     *
     *  pid == -1 and cpu == -1
     *         This setting is invalid and will return an error.
     *
     */
    ProfilerConfig(int pid = 0, int cpu = -1,bool is_grouped = false) : pid{pid},cpu{cpu},is_grouped{is_grouped} {
        std::memset(&perf_event_config, 0, sizeof(struct perf_event_attr));
        perf_event_config.type = PERF_TYPE_RAW; 
        perf_event_config.size = sizeof(struct perf_event_attr);
        perf_event_config.disabled = 1;
        perf_event_config.inherit = 1;
        perf_event_config.exclude_kernel = 1;
        perf_event_config.exclude_hv = 1;

        if(is_grouped)
        {
            // TODO: create evetn groups !!
            // perf_event_config.read_format = PERF_FORMAT_GROUP | PERF_FORMAT_ID;
        }
    }
    
    int pid;
    int cpu;
    bool is_grouped;
    perf_event_attr perf_event_config;
};

class BaseProfiler
{
public:
    BaseProfiler(const ProfilerConfig& config) : config{config} {}
    virtual ~BaseProfiler() {}

    virtual void disable() = 0;
    virtual void enable() = 0;
    virtual std::vector<uint64_t> read() = 0;

    ProfilerConfig config;
};

} // namespace optkit::core

#endif