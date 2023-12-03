#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__UTILS_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__UTILS_HH

#include <string>
#include <sstream>
#include <rapl.hh>
#include <rapl_perf_reader.hh>
#include <rapl_profiler.hh>
#include <json.hh>

namespace optkit::core
{
    struct RaplMetric
    {
        std::string metric_name;
        double value;
        std::string units;
        std::string description;
    };

    struct RaplPackage
    {
        int32_t package_number;
        std::vector<std::vector<RaplMetric>> metrics_sets; // Multiple sets of metrics
    };

    nlohmann::json to_json(const std::map<int32_t, std::map<optkit::core::RaplDomain, double>> &rapl_map);
} // namespace optkit::core

#endif