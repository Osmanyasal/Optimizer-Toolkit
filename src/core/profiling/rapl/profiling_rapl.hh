#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__PROFILING_RAPL_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__PROFILING_RAPL_HH

#include <rapl.hh>
#include <rapl_perf_reader.hh>
#include <rapl_profiler.hh>

using optkit::core::RaplDomain;
using optkit::core::RaplDomainInfo;
using optkit::core::RaplProfiler;
using optkit::core::RaplReadMethods;

namespace optkit::core
{
    
#define OPTKIT_RAPL_AVG(block_name, var_name, count) \
    RaplProfiler var_name{#block_name};              \
    for (int i = 0; i < count; i++)

} // namespace optkit::core

#endif