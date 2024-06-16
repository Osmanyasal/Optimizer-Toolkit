
#include <base_governor.hh>

namespace optkit::core::freq
{

    BaseGovernor *BaseGovernor::current_governor = nullptr;

    int32_t BaseGovernor::COMPUTE_TRESHOLD = 0; // TODO: set values later
    int32_t BaseGovernor::IO_TRESHOLD = 0;      // TODO: set values later
    int32_t BaseGovernor::CACHE_TRESHOLD = 0;   // TODO: set values later
    int32_t BaseGovernor::DRAM_TRESHOLD = 0;    // TODO: set values later

    BaseGovernor::BaseGovernor(long sample_period) : config{false, true, false, 0, -1}, sample_period{sample_period}
    {
        this->config.perf_event_config.sample_period = this->sample_period;
        this->config.cpu = 0; /// set thread 0 for cpu_cycle callbacks!!

        memset(&sa, 0, sizeof(struct sigaction));
        sa.sa_sigaction = BaseGovernor::call_back;
        sa.sa_flags = SA_SIGINFO;
        if (sigaction(SIGIO, &sa, NULL) < 0)
        {
            OPTKIT_CORE_ERROR("Error setting up signal handler");
            exit(1);
        }
    }

    BaseGovernor::~BaseGovernor()
    {
    }

    void BaseGovernor::call_back(int signum, siginfo_t *oh, void *blah)
    {
        static int i = 0;
        OPTKIT_CORE_INFO("{} th call_back() called", ++i);
        current_governor->snapshot_pmus();
        double compute_rate = current_governor->computational_intensity();
        double io_rate = current_governor->io_intensity();
        double dram_rate = current_governor->dram_intensity();
        double cache_rate = current_governor->cache_intensity();

        if (compute_rate >= COMPUTE_TRESHOLD)
        {
            CPUFrequency::set_core_frequency(QueryFreq::get_cpuinfo_max_freq(), 1);
        }
        else
        {
            CPUFrequency::set_core_frequency(QueryFreq::get_cpuinfo_min_freq(), 1);
        }

        if (io_rate >= IO_TRESHOLD)
        {
            CPUFrequency::set_core_frequency(QueryFreq::get_cpuinfo_min_freq(), 1);
            //todo: set uncore to min as well!
        } 

        if (dram_rate >= DRAM_TRESHOLD)
        {
        }
        else
        {
        }

        if (cache_rate >= CACHE_TRESHOLD)
        {
            // todo: set uncore to max
        }
        else
        {
            //todo: set uncore to min !
        }
    }
}