#include <optkit.hh>

namespace optkit::core
{
    /**
     * @brief Construct a new Optimizer Kit:: Optimizer Kit object
     *
     *  Creates Execution Directory | use existing/random one
     *  Starts Logger and Query class
     *
     *
     * @param execution_file
     */
    OptimizerKit::OptimizerKit(const OPTKIT_CONFIG config) : config{config}
    {
        if (this->config.execution_file.size() > 0)
            EXECUTION_FOLDER_NAME = this->config.execution_file;

        optkit::utils::logger::BaseLogger::init();

        int32_t paranoid = this->paranoid();
        if (OPT_UNLIKELY(paranoid > 0))
        {
            OPTKIT_CORE_ERROR("perf_event_paranoid {}(current) must be <=0 for ACCURATE data collection by optimizer toolkit!", paranoid);
            OPTKIT_CORE_WARN("FOR ALL EVENTS: set perf_event_paranoid to -1 (SUGGESTED)");
            OPTKIT_CORE_WARN("FOR EVENTS WITH NO SECURITY IMPLICATIONS: set perf_event_paranoid to 0");
            OPTKIT_CORE_WARN("USE: sudo sysctl kernel.perf_event_paranoid=<parameter>");

            exit(EXIT_FAILURE);
        }
        else if (paranoid <= 0)
        {
            if (OPT_LIKELY(config.create_folder))
            {
                create_directory(EXECUTION_FOLDER_NAME);
                OPTKIT_CORE_INFO("Execution file created {}", EXECUTION_FOLDER_NAME);
            }
            else
            {
                OPTKIT_CORE_INFO("File creation skipped!");
            }

            char *core_freq = std::getenv("OPTKIT_CORE_FREQ");
            char *uncore_freq = std::getenv("OPTKIT_UNCORE_FREQ");
            char *socket_0 = std::getenv("OPTKIT_SOCKET_0");
            char *socket_1 = std::getenv("OPTKIT_SOCKET_1");

            if (core_freq == nullptr)
            {
                OPTKIT_CORE_INFO("OPTKIT_CORE_FREQ is not specified");
            }
            else
            {
                OPTKIT_CORE_INFO("env read--- core_freq:{} ", std::atol(core_freq));

                if (socket_1 == nullptr && socket_0 == nullptr)
                {
                    OPTKIT_CORE_WARN("OPTKIT_SOCKET_0 or OPTKIT_SOCKET_1 must be defined with core - uncore frequency request");
                    exit(EXIT_FAILURE);
                }

                if (socket_0 != nullptr)
                {
                    OPTKIT_CORE_INFO("env read--- socket_0:{} ", std::atol(socket_0));
                    CPUFrequency::set_core_frequency(std::atol(core_freq), std::atoi(socket_0));
                }

                if (socket_1 != nullptr)
                {
                    OPTKIT_CORE_INFO("env read--- socket_1:{} ", std::atol(socket_1));
                    CPUFrequency::set_core_frequency(std::atol(core_freq), std::atoi(socket_1));
                }
            }

            if (uncore_freq == nullptr)
            {
                OPTKIT_CORE_INFO("OPTKIT_UNCORE_FREQ is not specified");
            }
            else
            {
                OPTKIT_CORE_INFO("env read--- uncore_freq:{} ", std::atol(uncore_freq));

                if (socket_1 == nullptr && socket_0 == nullptr)
                {
                    OPTKIT_CORE_WARN("OPTKIT_SOCKET_0 or OPTKIT_SOCKET_1 must be defined with core - uncore frequency request");
                    exit(EXIT_FAILURE);
                }

                if (socket_0 != nullptr)
                {
                    OPTKIT_CORE_INFO("env read--- socket_0:{} ", std::atol(socket_0));
                    CPUFrequency::set_uncore_frequency(std::atol(uncore_freq), std::atoi(socket_0));
                }

                if (socket_1 != nullptr)
                {
                    OPTKIT_CORE_INFO("env read--- socket_1:{} ", std::atol(socket_1));
                    CPUFrequency::set_uncore_frequency(std::atol(uncore_freq), std::atoi(socket_1));
                }
            }
        }
        OPTKIT_CORE_GANTT_PROFILE_BEGIN_SESSION("Optimizer Toolkit", "optkit_gui_gantt_instr.json");
    }

    /**
     * @brief Destroy the Optimizer Kit:: Optimizer Kit object
     *
     *  Read all files under the execution directory & print them
     *  Destroy Query utility
     *
     */
    OptimizerKit::~OptimizerKit()
    {
        optkit::core::pmu::QueryPMU::destroy();
        OPTKIT_CORE_GANTT_PROFILE_END_SESSION();
    }

    int32_t OptimizerKit::paranoid()
    {
        std::string value = read_file("/proc/sys/kernel/perf_event_paranoid");
        return std::stoi(value);
    }

} // namespace optkit::core
