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
