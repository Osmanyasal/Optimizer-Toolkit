#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BASE_PROFILER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BASE_PROFILER_HH

#include <cstdint>
#include <cstring>
#include <vector> 
#include <profiler_config.hh>
namespace optkit::core
{
     
template<typename T>
class BaseProfiler
{
public:
    virtual ~BaseProfiler() {}

    virtual void disable() = 0;
    virtual void enable() = 0;
    virtual T read() = 0;
};

} // namespace optkit::core

#endif