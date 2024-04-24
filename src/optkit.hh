#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH

#include <string>
#include <vector>
#include <utils.hh>
#include <core_profiling.hh>

namespace optkit::core
{
    struct OPTKIT_CONFIG
    {
        OPTKIT_CONFIG(bool create_folder = true, const std::string &execution_file = "") : create_folder{create_folder}, execution_file{execution_file} {}

        const bool create_folder;
        const std::string execution_file;
    };
    class OptimizerKit
    {
   
    public:
        OptimizerKit(const OPTKIT_CONFIG config = {});
        ~OptimizerKit();

        /**
         * @brief Returns current perf_event_paranoid value from "/proc/sys/kernel/perf_event_paranoid"<br>
         * Suggested value is -1 but 0 is also okay. cannot gurantee to accuretely measure for values above >0.
         *
         * @return int32_t paranoid value.
         */
        int32_t paranoid();

    private:
        const OPTKIT_CONFIG config;
    };
}

using optkit::core::OptimizerKit;
using optkit::core::OPTKIT_CONFIG;

#endif