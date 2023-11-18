#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PROFILER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PROFILER_HH

#include <memory>
#include <utils.hh>
#include <ostream>
#include <map>

#include <base_profiler.hh>
#include <profiler_config.hh>
#include <rapl_perf_reader.hh>
#include <query.hh>
namespace optkit::core
{

    class RaplProfiler : public BaseProfiler<std::map<int32_t, std::map<RaplDomain, double>>>
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
         * @return std::map<int32_t,std::map<RaplDomain, int32_t>> SocketID - RaplDomain - reading
         */
        virtual std::map<int32_t, std::map<RaplDomain, double>> read() override;

    private:
        std::unique_ptr<BaseProfiler<std::map<int32_t, std::map<RaplDomain, double>>>> rapl_reader;
        RaplConfig rapl_config;
        std::chrono::high_resolution_clock::time_point start;
    };

} // namespace optkit::core

// Overloading << for map with RaplDomain as keys
std::ostream &operator<<(std::ostream &os, const std::map<optkit::core::RaplDomain, double> &map);
std::ostream &operator<<(std::ostream &os, const std::map<int32_t, std::map<optkit::core::RaplDomain, double>> &map);

#endif