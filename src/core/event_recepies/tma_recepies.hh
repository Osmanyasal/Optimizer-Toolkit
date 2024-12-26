#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <iomanip>
#include "intel_priv.hh"

namespace optkit::core::recepies
{
    // Enum for L1 and L2 analysis metrics
    enum class L1Metric
    {
        BackendBound,
        BadSpeculation,
        Retiring,
        FrontendBound
    };
    std::string to_string(L1Metric metric);

    enum class L2Metric
    {
        MemoryBound,
        MemoryL1Bound,
        MemoryL2Bound,
        MemoryL3Bound,
        CoreBound,
        Base,
        BranchMisprediction,
        FetchBandwidth,
        FetchLatency
    };
    std::string to_string(L2Metric metric);

    class TMARecepies
    {
    public:
        TMARecepies(/* args */) {}
        virtual ~TMARecepies() {}

        virtual std::unordered_map<L1Metric, double> L1_analysis(const std::vector<uint64_t> &pmu_record);
        virtual std::unordered_map<L1Metric, double> L2_analysis(const std::vector<uint64_t> &pmu_record);

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L1_recipie();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L2_recipie();

    };

    // Overloading the << operator for L1Metric and L2Metric unordered maps
    std::ostream &operator<<(std::ostream &out, const std::unordered_map<L1Metric, double> &map);
    std::ostream &operator<<(std::ostream &out, const std::unordered_map<L2Metric, double> &map);
} // namespace optkit::core::recepies
