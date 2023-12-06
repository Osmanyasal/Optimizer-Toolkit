#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__PROFILING_RAPL_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__PROFILING_RAPL_HH

#include <rapl.hh>
#include <rapl_perf_reader.hh>
#include <rapl_profiler.hh>
#include <rapl_utils.hh>

using optkit::core::RaplDomain;
using optkit::core::RaplDomainInfo;
using optkit::core::RaplProfiler;
using optkit::core::RaplReadMethods;

/*
    Static instance is defined because monitoring recursive methods would cause an issue
*/
#define OPTKIT_RAPL_REPEAT(var_name, block_name, count) \
    OPTKIT_CORE_GANTT_PROFILE_SCOPE(block_name);        \
    static RaplProfiler var_name{block_name};           \
    for (int i = 0; i < count; i++)

#endif