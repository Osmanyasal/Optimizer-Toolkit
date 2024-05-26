
#include <base_governor.hh>

namespace optkit::core::freq
{
    BaseGovernor::BaseGovernor(long sample_period) : sample_period{sample_period} 
    {
        this->config.perf_event_config.sample_period = this->sample_period;
        memset(&sa, 0, sizeof(struct sigaction));
        sa.sa_sigaction = BaseGovernor::call_back;
        sa.sa_flags = SA_SIGINFO;
        if (sigaction(SIGIO, &sa, NULL) < 0)
        {
            fprintf(stderr, "Error setting up signal handler\n");
            exit(1);
        }
    }

    BaseGovernor::~BaseGovernor()
    {
    }

    void BaseGovernor::call_back(int signum, siginfo_t *oh, void *blah)
    {
        static int i = 0;
        std::cout << ++i << " callback() called\n";
    }
}