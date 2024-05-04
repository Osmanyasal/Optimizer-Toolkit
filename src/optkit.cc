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
            else{
                OPTKIT_CORE_INFO("File creation skipped!");
            }
        }
        OPTKIT_CORE_GANTT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
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
