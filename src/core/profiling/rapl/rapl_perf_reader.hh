#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PERF_READER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__RAPL__RAPL_PERF_READER_HH

#include <ostream>
#include <base_profiler.hh>
#include <map>
#include <rapl.hh>
#include <utils.hh>
#include <perf_event.h>

namespace optkit::core
{
    struct RaplPerfReaderConfig
    {
        const std::map<int32_t, std::vector<int32_t>> &packages;
        const std::vector<RaplDomainInfo> &avail_domains;
        const RaplConfig& rapl_config;
    };

    class RaplPerfReader : public BaseProfiler<std::unordered_map<int32_t, std::unordered_map<RaplDomain, int32_t>>>
    {
    public:
        RaplPerfReader(const RaplPerfReaderConfig& rapl_perf_config);
        virtual ~RaplPerfReader();

        virtual void disable() override;
        virtual void enable() override;
        virtual std::unordered_map<int32_t, std::unordered_map<RaplDomain, int32_t>> read() override;

    private:
        RaplPerfReaderConfig rapl_perf_config;
        int** fd__package__domain;
    };

} // namespace optkit::core

std::ostream &operator<<(std::ostream &os, const optkit::core::RaplPerfReaderConfig &config);

#endif