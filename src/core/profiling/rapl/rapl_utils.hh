#pragma once

#include <string>
#include <sstream>
#include <json.hh>
#include <rapl.hh>
#include <query_rapl.hh>

namespace optkit::core::rapl
{                                                  // vector<duration, map<package_num, map<rapl_domain, value>>>
    nlohmann::json to_json(const char *event_name, const std::vector<std::pair<double, std::map<int32_t, std::map<optkit::core::rapl::RaplDomain, double>>>> &rapl_pair_list);
    std::map<uint32_t, std::vector<std::pair<double, std::map<int32_t, std::map<optkit::core::rapl::RaplDomain, double>>>>> from_json(const std::string &json);

} // namespace optkit::core
