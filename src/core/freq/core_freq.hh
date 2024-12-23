#pragma once

#include "src/utils/deployment/deployment_config.hh"
#include "src/core/freq/cpu_frequency.hh"
#include "src/core/freq/query_frequency.hh"

using optkit::core::freq::CPUFrequency;
using optkit::core::freq::QueryFreq;

#if defined(CONF__FREQ__MACROS__ENABLED) && CONF__FREQ__MACROS__ENABLED == 1

#define OPTKIT_SET_CPU_CORE_FREQ(frequency, socket) CPUFrequency::set_core_frequency(frequency, socket)
#define OPTKIT_SET_CPU_UNCORE_FREQ(frequency, socket) CPUFrequency::set_uncore_frequency(frequency, socket)
#define OPTKIT_SET_CPU_FREQ(core_freq,uncore_freq, socket)     \
    OPTKIT_SET_CPU_UNCORE_FREQ(core_freq, socket); \
    OPTKIT_SET_CPU_CORE_FREQ(uncore_freq, socket)

#define OPTKIT_RESET_CPU_CORE_FREQ(socket) CPUFrequency::reset_core_frequency(socket)
#define OPTKIT_RESET_CPU_UNCORE_FREQ(socket) CPUFrequency::reset_uncore_frequency(socket)
#else

#define OPTKIT_SET_CPU_CORE_FREQ(frequency, socket)
#define OPTKIT_SET_CPU_UNCORE_FREQ(frequency, socket)
#define OPTKIT_SET_CPU_FREQ(frequency, socket)
#define OPTKIT_RESET_CPU_CORE_FREQ(socket)   
#define OPTKIT_RESET_CPU_UNCORE_FREQ(socket) 

#endif