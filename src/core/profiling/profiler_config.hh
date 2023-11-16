#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__PROFILER_CONFIG_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__PROFILER_CONFIG_HH

#include <cstring>
#include <linux/perf_event.h> // for pmu monitoring
#include <rapl.hh>  // for rapl monitoring

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

    struct RaplConfig
    {
        /**
         * @brief Value must be the combination of RaplDomains.
         *        e.g RaplDomain::DRAM | RaplDomain::Core
         * @param monitor_domain 
         */
        RaplConfig(int monitor_domain = (int)RaplDomain::ALL);
        int monitor_domain;
    };

} // namespace optkit::core

#endif