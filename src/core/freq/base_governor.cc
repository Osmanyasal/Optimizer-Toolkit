
#include <base_governor.hh>

namespace optkit::core::freq
{
    BaseGovernor::BaseGovernor(long sample_period) : sample_period{sample_period}
    {
        std::cout << "ctor BaseGovernor\n";
        this->config.perf_event_config.sample_period = this->sample_period;
        memset(&sa, 0, sizeof(struct sigaction));
        sa.sa_sigaction = BaseGovernor::call_back;
        sa.sa_flags = SA_SIGINFO;
    }

    BaseGovernor::~BaseGovernor(){
        std::cout << "dtor BaseGovernor\n";
    }

    void BaseGovernor::call_back(int signum, siginfo_t *oh, void *blah)
    {
        static int i = 0;
        std::cout << ++i << " call_back() called";
    }
}