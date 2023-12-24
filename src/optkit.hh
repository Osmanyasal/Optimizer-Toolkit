#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH

#include <string>
#include <vector>
#include <utils.hh>
#include <core_platforms.hh>
#include <core_profiling.hh>

namespace optkit::core
{
    class OptimizerKit
    { 

    public:
        OptimizerKit();
        ~OptimizerKit();

        void draw(const std::vector<std::string>& file_names = {});

        /**
         * @brief Returns current perf_event_paranoid value from "/proc/sys/kernel/perf_event_paranoid"<br>
         * Suggested value is -1 but 0 is also okay. cannot gurantee to accuretely measure for values above >0.
         *
         * @return int32_t paranoid value.
         */
        int32_t paranoid();

    };
}
  
using optkit::core::OptimizerKit;


#endif