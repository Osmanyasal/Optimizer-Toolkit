#include "core/event_recepies/tma_recepies.hh"

namespace optkit::core::recepies
{
    // Function to convert L1Metric to string
    std::string to_string(L1Metric metric)
    {
        switch (metric)
        {
        case L1Metric::BackendBound:
            return "L1 Backend Bound";
        case L1Metric::BadSpeculation:
            return "L1 Bad Speculation";
        case L1Metric::Retiring:
            return "L1 Retiring";
        case L1Metric::FrontendBound:
            return "L1 Frontend Bound";
        default:
            return "Unknown L1 Metric";
        }
    }

    // Function to convert L2Metric to string
    std::string to_string(L2Metric metric)
    {
        switch (metric)
        {
        case L2Metric::MemoryBound:
            return "L2 Memory Bound";
        case L2Metric::MemoryL1Bound:
            return "L2 Memory L1 Bound";
        case L2Metric::MemoryL2Bound:
            return "L2 Memory L2 Bound";
        case L2Metric::MemoryL3Bound:
            return "L2 Memory L3 Bound";
        case L2Metric::CoreBound:
            return "L2 Core Bound";
        case L2Metric::Base:
            return "L2 Base";
        case L2Metric::BranchMisprediction:
            return "L2 Branch Misprediction";
        case L2Metric::FetchBandwidth:
            return "L2 Fetch Bandwidth";
        case L2Metric::FetchLatency:
            return "L2 Fetch Latency";
        default:
            return "Unknown L2 Metric";
        }
    }

    std::vector<std::pair<uint64_t, std::string>> TMARecepies::L1_recipie()
    {
        static std::vector<std::pair<uint64_t, std::string>> default_mapping{
            {0x3c, "CPU_CLK_UNHALTED"},                                                // 0
            {(0x9c | 0x100), "IDQ_UOPS_NOT_DELIVERED"},                                // 1
            {(0xe | 0x100), "UOPS_ISSUED_ANY"},                                        // 2
            {(0xc2 | 0x200), "UOPS_RETIRED_RETIRE_SLOTS"},                             // 3
            {(0xd | 0x300 | (1 << INTEL_X86_CMASK_BIT)), "INT_MISC_RECOVERY_CYCLES"}}; // 4

        // be_bound = 1 - (fe_bound + bad_speculation + retiring)

        return default_mapping;
    }

    std::unordered_map<L1Metric, double> TMARecepies::L1_analysis(const std::vector<uint64_t> &pmu_record)
    {
        std::unordered_map<L1Metric, double> result;

        double SLOTS = 4 * pmu_record[0];
        result[L1Metric::FrontendBound] = (pmu_record[1] / SLOTS) * 100.0;                                        // IDQ_UOPS_NOT_DELIVERED.CORE / Slots
        result[L1Metric::Retiring] = (pmu_record[3] / SLOTS) * 100.0;                                             // UOPS_RETIRED.RETIRE_SLOTS / Slots
        result[L1Metric::BadSpeculation] = ((pmu_record[2] - pmu_record[3] + 4 * pmu_record[4]) / SLOTS) * 100.0; // (UOPS_ISSUED.ANY - UOPS_RETIRED.RETIRE_SLOTS + 4* INT_MISC.RECOVERY_CYCLES) / Slots
        result[L1Metric::BackendBound] = (100 - (result[L1Metric::FrontendBound] +
                                              result[L1Metric::BadSpeculation] +
                                              result[L1Metric::Retiring])); // 1 – (Frontend Bound + Bad Speculation + Retiring)

        return result;
    }

    std::vector<std::pair<uint64_t, std::string>> TMARecepies::L2_recipie()
    {
        static std::vector<std::pair<uint64_t, std::string>> default_mapping{
            {0x3c, "CPU_CLK_UNHALTED"},                                                // 0
            {(0x9c | 0x100), "IDQ_UOPS_NOT_DELIVERED"},                                // 1
            {(0xe | 0x100), "UOPS_ISSUED_ANY"},                                        // 2
            {(0xc2 | 0x200), "UOPS_RETIRED_RETIRE_SLOTS"},                             // 3
            {(0xd | 0x300 | (1 << INTEL_X86_CMASK_BIT)), "INT_MISC_RECOVERY_CYCLES"}}; // 4

        // be_bound = 1 - (fe_bound + bad_speculation + retiring)

        return default_mapping;
    }

    std::unordered_map<L1Metric, double> TMARecepies::L2_analysis(const std::vector<uint64_t> &pmu_record)
    {
        std::unordered_map<L1Metric, double> result;

        return result;
    }
    // Overloading the << operator for L1Metric and L2Metric unordered maps
    std::ostream &operator<<(std::ostream &out, const std::unordered_map<L1Metric, double> &map)
    {
        out << "{";
        bool first = true;
        for (const auto &pair : map)
        {
            if (!first)
            {
                out << ", ";
            }
            first = false;
            out << to_string(pair.first) << " = " << pair.second << "%";
        }
        out << "}";
        return out;
    }

    std::ostream &operator<<(std::ostream &out, const std::unordered_map<L2Metric, double> &map)
    {
        out << "{";
        bool first = true;
        for (const auto &pair : map)
        {
            if (!first)
            {
                out << ", ";
            }
            first = false;
            out << to_string(pair.first) << " = " << pair.second << "%";
        }
        out << "}";
        return out;
    }
} // namespace optkit::core::recepies
