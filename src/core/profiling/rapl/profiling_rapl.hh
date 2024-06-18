#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__PROFILING_RAPL_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__PROFILING_RAPL_HH

#include <deployment_config.hh>
#include <rapl.hh>
#include <rapl_perf_reader.hh>
#include <rapl_profiler.hh>
#include <rapl_utils.hh>
#include <query_rapl.hh>

using optkit::core::rapl::QueryRapl;
using optkit::core::rapl::RaplDomain;
using optkit::core::rapl::RaplDomainInfo;
using optkit::core::rapl::RaplProfiler;
using optkit::core::rapl::RaplReadMethods;

/*
    Static instance is defined because monitoring recursive methods would cause an issue
*/
 
#if defined(CONF__RAPL__MACROS__ENABLED) && CONF__RAPL__MACROS__ENABLED == 1

#define OPTKIT_RAPL(var_name, block_name)        \
    OPTKIT_CORE_GANTT_PROFILE_SCOPE(block_name); \
    RaplProfiler var_name{block_name};

#define OPTKIT_RAPL_REPEAT(var_name, block_name, count) \
    OPTKIT_CORE_GANTT_PROFILE_SCOPE(block_name);        \
    RaplProfiler var_name{block_name};                  \
    for (int32_t i = 0; i < count; i++)

#define OPTKIT_RAPL_REPEAT_READ(var_name, block_name, count) \
    OPTKIT_CORE_GANTT_PROFILE_SCOPE(block_name);             \
    RaplProfiler var_name{block_name};                       \
    for (int32_t i = 0; i < count; i++, var_name.read())

#else
    #define OPTKIT_RAPL(var_name, block_name)
    #define OPTKIT_RAPL_REPEAT(var_name, block_name, count)
    #define OPTKIT_RAPL_REPEAT_READ(var_name, block_name, count)
#endif
#endif