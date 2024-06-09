
#include <base_governor.hh>

namespace optkit::core::freq
{

    BaseGovernor *BaseGovernor::current_governor = nullptr;

    BaseGovernor::BaseGovernor(long sample_period) : config{false, true, false, 0, -1}, sample_period{sample_period}
    {
        this->config.perf_event_config.sample_period = this->sample_period;
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

        // TODO: it's possible that current_governor is null at the very beginning... 
        // for (uint64_t i : current_governor->read_pmus())
        // {
        //     OPTKIT_CORE_INFO("{}", i);
        // }

        // OPTKIT_CORE_INFO("---------------------");
    }
}