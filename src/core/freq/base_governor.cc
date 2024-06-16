
#include <base_governor.hh>

namespace optkit::core::freq
{

    BaseGovernor *BaseGovernor::current_governor = nullptr;

    BaseGovernor::BaseGovernor(long sample_period) : config{false, true, false, 0, -1}, sample_period{sample_period}
    {
        this->config.perf_event_config.sample_period = this->sample_period;
        this->config.cpu = 0;   /// set thread 0 for this !

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
        current_governor->computational_intensity();
        current_governor->io_intensity();
        current_governor->dram_intensity();
        current_governor->cache_intensity();
    }
}