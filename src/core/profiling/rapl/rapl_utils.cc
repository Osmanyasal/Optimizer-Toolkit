#include <rapl_utils.hh>

namespace optkit::core::rapl
{

    nlohmann::json to_json(const std::map<int32_t, std::map<optkit::core::RaplDomain, double>> &rapl_map)
    {
        const std::vector<optkit::core::RaplDomainInfo> &avail_domains = optkit::core::Query::rapl_domain_info();

        nlohmann::json result;

        for (const auto &pair : rapl_map)
        {
            rapl::RaplPackage package;
            package.package_number = pair.first;

            nlohmann::json packageJson;
            packageJson["package_number"] = package.package_number;

            for (const auto &innerpair : pair.second)
            {
                std::vector<rapl::RaplMetric> metrics;

                for (const auto &info : avail_domains)
                {
                    if (info.domain == innerpair.first)
                    {
                        packageJson["metrics_sets"].push_back({{"metric_name", info.event},
                                                               {"value", innerpair.second},
                                                               {"units", info.units},
                                                               {"description", "Consumed"}});
                    }
                }
            }
            result["packages"].push_back(packageJson);
        }

        return result;
    }

    std::map<int32_t, std::map<optkit::core::RaplDomain, double>> from_json(const std::string &json)
    {
        const auto json_obj = nlohmann::json::parse(json);

        std::map<int32_t, std::map<optkit::core::RaplDomain, double>> rapl_map;

        if (json_obj.is_array())
        {
            for (const auto &array_elem : json_obj)
            {
                if (array_elem.find("packages") != array_elem.end() && array_elem["packages"].is_array())
                {
                    for (const auto &packageJson : array_elem["packages"])
                    {
                        if (packageJson.find("package_number") != packageJson.end() && packageJson["package_number"].is_number())
                        {
                            int32_t package_number = packageJson["package_number"];
                            std::map<optkit::core::RaplDomain, double> inner_map;

                            if (packageJson.find("metrics_sets") != packageJson.end() && packageJson["metrics_sets"].is_array())
                            {
                                for (const auto &metricJson : packageJson["metrics_sets"])
                                {
                                    if (metricJson.find("metric_name") != metricJson.end() &&
                                        metricJson.find("value") != metricJson.end() && metricJson["value"].is_number() &&
                                        metricJson.find("units") != metricJson.end() &&
                                        metricJson.find("description") != metricJson.end())
                                    {
                                        std::string metric_name = metricJson["metric_name"];
                                        double value = metricJson["value"];
                                        std::string units = metricJson["units"];
                                        std::string description = metricJson["description"];

                                        optkit::core::RaplDomain domain = mapMetricNameToRaplDomain(metric_name);

                                        inner_map[domain] = value;
                                    }
                                }
                            }

                            rapl_map[package_number] = inner_map;
                        }
                    }
                }
            }
        }
        return rapl_map;
    }
} // namespace optkit::core
