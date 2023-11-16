#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH

#include <utils.hh>
#include <core_platforms.hh>
#include <core_profiling.hh>
#include <utils.hh>
#include <string>

namespace optkit::core
{
    class OptimizerKit
    {
    public:
        OptimizerKit();
        ~OptimizerKit();

        /**
         * @brief Returns current perf_event_paranoid value from "/proc/sys/kernel/perf_event_paranoid"<br>
         * Suggested value is -1 but 0 is also okay. cannot gurantee to accuretely measure for values above >0.
         *
         * @return int32_t paranoid value.
         */
        int32_t paranoid();
    };
}

using optkit::core::BlockGroupProfiler;
using optkit::core::BlockProfiler;
using optkit::core::RaplDomain;
using optkit::core::RaplProfiler;
using optkit::core::OptimizerKit;


#endif