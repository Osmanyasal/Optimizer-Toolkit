#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__HH

#include <deployment_config.hh>
#include <cpu_frequency.hh>
#include <query_frequency.hh>

using optkit::core::freq::CPUFrequency;
using optkit::core::freq::QueryFreq;
 

#if defined(CONF__PMU__MACROS__ENABLED) && CONF__PMU__MACROS__ENABLED == 1

#define OPTKIT_SET_CPU_CORE_FREQ(frequency, socket) CPUFrequency::set_core_frequency(frequency, socket)
#define OPTKIT_SET_CPU_UNCORE_FREQ(frequency, socket) CPUFrequency::set_uncore_frequency(frequency, socket)
#define OPTKIT_SET_CPU_FREQ(frequency, socket)     \
    OPTKIT_SET_CPU_UNCORE_FREQ(frequency, socket); \
    OPTKIT_SET_CPU_CORE_FREQ(frequency, socket)

#else

#define OPTKIT_SET_CPU_CORE_FREQ(frequency, socket)
#define OPTKIT_SET_CPU_UNCORE_FREQ(frequency, socket)
#define OPTKIT_SET_CPU_FREQ(frequency, socket)

#endif
#endif