#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__UTILS_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RAPL__UTILS_HH

#include <string>
#include <sstream>
#include <json.hh>
#include <rapl.hh>
#include <query.hh>

namespace optkit::core::rapl
{
    nlohmann::json to_json(const std::vector<std::pair<double, std::map<int32_t, std::map<optkit::core::RaplDomain, double>>>> &rapl_pair_list);
    std::vector<std::pair<double, std::map<int32_t, std::map<optkit::core::RaplDomain, double>>>> from_json(const std::string &json);

} // namespace optkit::core

#endif