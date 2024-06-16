#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__BASE_GOVERNOR_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__BASE_GOVERNOR_HH

#include <signal.h>
#include <fcntl.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include <profiler_config.hh>
#include <block_group_profiler.hh>
#include <block_profiler.hh>
#include <cpu_frequency.hh>
#include <query_frequency.hh>

#define OPTKIT_BASE_GOVERNOR_MMAP_PAGES 8
#define OPTKIT_BASE_GOVERNOR_GOVERNOR_CALLBACK_PERIOD_MS 5 // 1 call per 10 ms -- on-demand checks each 10ms as well

namespace optkit::core::freq
{
    /**
     * @brief Base governor is called each 5ms by defaut.
     * 
     */
    class BaseGovernor
    {
    public:
        // this will be called when sample period exceeds
        static void call_back(int signum, siginfo_t *oh, void *blah);
        static BaseGovernor* current_governor;
        static int32_t COMPUTE_TRESHOLD;
        static int32_t IO_TRESHOLD;
        static int32_t CACHE_TRESHOLD;
        static int32_t DRAM_TRESHOLD;

    public:
        BaseGovernor(long sample_period = QueryFreq::get_cpuinfo_max_freq() * OPTKIT_BASE_GOVERNOR_GOVERNOR_CALLBACK_PERIOD_MS); // callback at each 10ms
        virtual ~BaseGovernor();

        virtual void snapshot_pmus() = 0;
        virtual double computational_intensity() = 0;
        virtual double cache_intensity() = 0;
        virtual double dram_intensity() = 0;
        virtual double io_intensity() = 0;

    protected:
        std::vector<uint64_t> pmu_record;
        optkit::core::ProfilerConfig config;
        const long sample_period;
        struct sigaction sa;
        void *our_mmap;
    };
}

#endif