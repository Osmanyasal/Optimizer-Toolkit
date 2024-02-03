#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH

#include <string>
#include <vector>
#include <utils.hh>
#include <core_platforms.hh>
#include <core_profiling.hh>

namespace optkit::core
{
    struct OPTKIT_CONFIG
    {
        OPTKIT_CONFIG(bool is_draw = true, const std::string &execution_file = "") : is_draw{is_draw}, execution_file{execution_file} {}

        const bool is_draw;
        const std::string execution_file;
    };
    class OptimizerKit
    {
    public:
        /**
         * @brief Draw given result files using IMGUI api.
         *
         * @param file_names
         */
        static void draw(const std::vector<std::string> &file_names = {});

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