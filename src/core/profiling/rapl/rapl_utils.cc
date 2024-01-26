#include <rapl_utils.hh>

namespace optkit::core::rapl
{

    nlohmann::json to_json(const char *event_name, const std::vector<std::pair<double, std::map<int32_t, std::map<optkit::core::RaplDomain, double>>>> &rapl_pair_list)
    {
        const std::vector<optkit::core::RaplDomainInfo> &avail_domains = optkit::core::Query::rapl_domain_info();
        nlohmann::json result;

        for (const auto &rapl_pair : rapl_pair_list)
        {
            nlohmann::json packageJson;
            packageJson["duration"] = rapl_pair.first;
            packageJson["event_name"] = event_name;

            for (const auto &innerpair : rapl_pair.second)
            {
                packageJson["package_number"] = innerpair.first;
                for (const auto &domain_value : innerpair.second)
                {
                    for (const auto &info : avail_domains)
                    {
                        if (info.domain == domain_value.first)
                        {
                            packageJson["metrics_set"].push_back({{"metric_name", info.event},
                                                                  {"value", domain_value.second},
                                                                  {"units", info.units},
                                                                  {"description", "Consumed"}});
                        }
                    }
                }
            }
            result["readings"].push_back(packageJson);
        }
        return result;
    }

    // TODO: Fix this reading according to return parameter.
    std::vector<std::pair<double, std::map<int32_t, std::map<optkit::core::RaplDomain, double>>>> from_json(const std::string &json)
    {
        const auto json_obj = nlohmann::json::parse(json);
        std::vector<std::pair<double, std::map<int32_t, std::map<optkit::core::RaplDomain, double>>>> result;
        std::map<int32_t, std::map<optkit::core::RaplDomain, double>> rapl_map;

        if (json_obj.is_array())
        {
            for (const auto &array_elem : json_obj)
            {
                for (const auto &packageJson : array_elem["readings"])
                {
                    // std::string event_name = packageJson["event_name"];
                    int32_t duration = packageJson["duration"];
                    int32_t package_number = packageJson["package_number"];
                    
                    std::map<optkit::core::RaplDomain, double> inner_map;
                    for (const auto &metricJson : packageJson["metrics_set"])
                    {
                        std::string metric_name = metricJson["metric_name"];
                        double value = metricJson["value"];
                        // std::string units = metricJson["units"];
                        // std::string description = metricJson["description"];

                        optkit::core::RaplDomain domain = mapMetricNameToRaplDomain(metric_name);
                        inner_map[domain] = value;
                    }
                    rapl_map[package_number] = inner_map;
                    result.push_back({duration, rapl_map});
                }
            }
        }
        return result;
    }
} // namespace optkit::core
