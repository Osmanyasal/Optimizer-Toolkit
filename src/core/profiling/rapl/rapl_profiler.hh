#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PROFILER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PROFILER_HH

#include <utils.hh>
#include <ostream>
#include <unordered_map>
#include <base_profiler.hh>
#include <profiler_config.hh>

namespace optkit::core
{

    class RaplProfiler : public BaseProfiler<std::unordered_map<RaplDomain, uint32_t>>
    {

    public:
        RaplProfiler(const RaplConfig &config = RaplConfig{});
        virtual ~RaplProfiler();

        /**
         * @brief Disables this rapl profiler.
         *
         */
        virtual void disable() override;

        /**
         * @brief Enables this rapl profiler.
         *
         */
        virtual void enable() override;

        /**
         * @brief Reads the values of all raw_events.
         *
         * @return std::vector<uint64_t> contains each raw_events' pmu data.
         */
        virtual std::unordered_map<RaplDomain, uint32_t> read() override;

    private:
        RaplConfig rapl_config;
    };
 
} // namespace optkit::core

// Overloading << for unordered_map with RaplDomain as keys
std::ostream &operator<<(std::ostream &os, const std::unordered_map<optkit::core::RaplDomain, uint32_t> &map);
 

#endif