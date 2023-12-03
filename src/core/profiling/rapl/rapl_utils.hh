#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__UTILS_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__UTILS_HH

#include <string>
#include <sstream>
#include <rapl.hh>
#include <rapl_perf_reader.hh>
#include <rapl_profiler.hh>

namespace optkit::core
{
    std::string to_json();
} // namespace optkit::core

#endif