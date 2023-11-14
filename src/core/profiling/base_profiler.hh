#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BASE_PROFILER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BASE_PROFILER_HH

#include <cstdint>
#include <cstring>
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
     * @param is_grouped indicates all events in the BlockProfiler should be groupped or not @see perf_event_open man page
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
    ProfilerConfig(bool is_grouped = false, int pid = 0, int cpu = -1);

    bool is_grouped;
    int pid;
    int cpu;
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

protected:
    ProfilerConfig config;
};

} // namespace optkit::core

#endif