#include <rapl_profiler.hh>

namespace optkit::core
{

    RaplProfiler::RaplProfiler(const RaplConfig& config) : BaseProfiler(config)
    {
    }

    RaplProfiler::~RaplProfiler()
    {
    }

    void RaplProfiler::disable(){

    }
    void RaplProfiler::enable(){

    }

    std::unordered_map<RaplDomain, uint32_t> RaplProfiler::read()
    {
        std::unordered_map<RaplDomain, uint32_t> result;

        return result;
    }

    // Overloading << for unordered_map with RaplDomain as keys
    std::ostream &operator<<(std::ostream &os, const std::unordered_map<RaplDomain, uint32_t> &map)
    {
        os << "{ ";
        for (const auto &pair : map)
        {
            os << pair.first << ": " << pair.second << ", ";
        }
        os << "}";
        return os;
    }

    // Overloading << for RaplDomain enum class
    std::ostream &operator<<(std::ostream &os, RaplDomain raplDomain)
    {
        switch (raplDomain)
        {
        case RaplDomain::PP0:
            os << "PP0";
            break;
        case RaplDomain::PP1:
            os << "PP1";
            break;
        case RaplDomain::PACKAGE:
            os << "PACKAGE";
            break;
        case RaplDomain::DRAM:
            os << "DRAM";
            break;
        }
        return os;
    }

} // namespace optkit::core

