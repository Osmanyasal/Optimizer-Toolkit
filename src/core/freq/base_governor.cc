
#include <base_governor.hh>

namespace optkit::core::freq
{

    BaseGovernor *BaseGovernor::current_governor = nullptr;

    BaseGovernor::BaseGovernor(int64_t sample_period) : config{false, true, false, 0, -1}, sample_period{sample_period}
    {
        this->config.perf_event_config.sample_period = this->sample_period;
        this->config.cpu = 1; /// set thread 1 for cpu_cycle callbacks!!    // TODO: This must be changed based on the cores given to the program!

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

    void BaseGovernor::call_back(int32_t signum, siginfo_t *oh, void *blah)
    {
        if (OPT_UNLIKELY(BaseGovernor::current_governor == nullptr))
            return;

        // DISABLE CALL_BACK TRIGGER to prevent multiple entry
        current_governor->disalbe_callback_trigger();

        static int32_t i = 0;
        // OPTKIT_CORE_INFO("{} th call_back() called", ++i);
        current_governor->snapshot_pmus();
        double compute_intensity = current_governor->compute_intensity();
        double io_intensity = current_governor->io_intensity();
        double memory_intensity = current_governor->memory_intensity();

        // OPTKIT_CORE_INFO("compute intensity = {}", compute_intensity);
        // OPTKIT_CORE_INFO("memory intensity ={}", memory_intensity);
        // OPTKIT_CORE_INFO("io intensity ={}", io_intensity);

        // call decision model here!

        if (Query::OPTKIT_SOCKET0__ENABLED)
        {
            if (Query::OPTKIT_SOCKET0__CORE_FREQ != -1)
                CPUFrequency::set_core_frequency(Query::OPTKIT_SOCKET0__CORE_FREQ, 0);
            if (Query::OPTKIT_SOCKET0__UNCORE_FREQ != -1)
                CPUFrequency::set_uncore_frequency(Query::OPTKIT_SOCKET0__UNCORE_FREQ, 0);
        }
        if (Query::OPTKIT_SOCKET1__ENABLED)
        {
            if (Query::OPTKIT_SOCKET1__CORE_FREQ != -1)
                CPUFrequency::set_core_frequency(Query::OPTKIT_SOCKET1__CORE_FREQ, 1);
            if (Query::OPTKIT_SOCKET1__UNCORE_FREQ != -1)
                CPUFrequency::set_uncore_frequency(Query::OPTKIT_SOCKET1__UNCORE_FREQ, 1);
        }

        // ENABLE CALL_BACK TRIGGER to prevent multiple entry
        current_governor->enable_callback_trigger();
    }
}