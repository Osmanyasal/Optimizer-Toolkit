
#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__PMU__PROFILING_PMU_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__PMU__PROFILING_PMU_HH

#include <block_group_profiler.hh>
#include <block_profiler.hh>
#include <libpfm4_wrapper.hh>
#include <pmu_event_manager.hh>
#include <gantt_instrumentor.hh>

using optkit::core::BlockGroupProfiler;
using optkit::core::BlockProfiler;
using optkit::core::PMUEventManager;

/*
    Static instances are defined because monitoring recursive methods would cause an issue
*/
#define OPTKIT_PERFORMANCE_EVENTS(block_name, variable_name, ...) \
    OPTKIT_CORE_GANTT_PROFILE_SCOPE(#block_name);\
    static BlockProfiler variable_name{#block_name, __VA_ARGS__}

#define OPTKIT_PERFORMANCE_BLOCK_EVENTS(block_name, variable_name, ...) \
    OPTKIT_CORE_GANTT_PROFILE_SCOPE(#block_name);\
    static BlockGroupProfiler variable_name{#block_name, __VA_ARGS__}

#endif