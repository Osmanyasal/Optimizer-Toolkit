#include <rapl_utils.hh>

namespace optkit::core
{

    nlohmann::json to_json(const std::map<int32_t, std::map<optkit::core::RaplDomain, double>> &rapl_map)
    {
        const std::vector<optkit::core::RaplDomainInfo> &avail_domains = optkit::core::Query::rapl_domain_info();

        nlohmann::json result;

        for (const auto &pair : rapl_map)
        {
            RaplPackage package;
            package.package_number = pair.first;

            nlohmann::json packageJson;
            packageJson["package_number"] = package.package_number;

            for (const auto &innerpair : pair.second)
            {
                std::vector<RaplMetric> metrics;

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

} // namespace optkit::core
