#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PROFILER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PROFILER_HH

#include <memory>
#include <utils.hh>
#include <ostream>
#include <map>
#include <query.hh>
#include <base_profiler.hh>
#include <profiler_config.hh>
#include <rapl_perf_reader.hh>
#include <rapl_utils.hh>
namespace optkit::core
{
    class RaplProfiler : public BaseProfiler<std::map<int32_t, std::map<RaplDomain, double>>>
    {
    public:
        RaplProfiler(const char *block_name, const char *event_name = "rapl", const RaplConfig &config = RaplConfig{});
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

        
        virtual std::string convert_buffer_to_json() override;

        /**
         * @brief Reads the values of all raw_events.
         *
         * @return std::map<int32_t,std::map<RaplDomain, int32_t>> SocketID - RaplDomain - reading
         */
        virtual std::map<int32_t, std::map<RaplDomain, double>> read_val() override;

    private:
        std::unique_ptr<optkit::core::RaplPerfReader> rapl_reader;
        RaplConfig rapl_config;
    };

} // namespace optkit::core

// Overloading << for map with RaplDomain as keys
std::ostream &operator<<(std::ostream &os, const std::map<optkit::core::RaplDomain, double> &map); 

#endif