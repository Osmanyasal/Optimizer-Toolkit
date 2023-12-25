#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PMU__UTILS_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PMU__UTILS_HH

#include <string>
#include <sstream>
#include <json.hh>
#include <rapl.hh>
#include <query.hh>

namespace optkit::core::pmu
{
    nlohmann::json to_json(const char *event_name, const std::vector<std::pair<uint64_t, std::string>> &raw_events, const std::vector<std::pair<double, std::vector<uint64_t>>> &pmu_pair_list);
    std::vector<std::pair<double, uint64_t>> from_json(const std::string &json);

} // namespace optkit::core

#endif