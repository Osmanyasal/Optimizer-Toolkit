#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__OPTIMIZER_TOOLKIT_HH

#include <utils.hh>
#include <core_platforms.hh>
#include <core_profiling.hh>
#include <core_rapl.hh>
#include <utils.hh>
#include <string>

namespace optkit::core
{
    class OptimizerKit
    {
    public:
        OptimizerKit();
        ~OptimizerKit();

        int32_t paranoid();
    };
}

using optkit::core::BlockGroupProfiler;
using optkit::core::BlockProfiler;
using optkit::core::RaplDomain;
using optkit::core::RaplProfiler;
using optkit::core::OptimizerKit;


#endif