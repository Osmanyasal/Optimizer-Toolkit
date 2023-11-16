#include <rapl_profiler.hh>

namespace optkit::core
{

    RaplProfiler::RaplProfiler(const RaplConfig& config) : rapl_config{config}
    {
    }

    RaplProfiler::~RaplProfiler()
    {
    }

    void RaplProfiler::disable(){
        OPTKIT_CORE_WARN("Rapl cannot be disabled");
    }
    void RaplProfiler::enable(){
        OPTKIT_CORE_WARN("Rapl is always enabled");
    }

    std::unordered_map<RaplDomain, uint32_t> RaplProfiler::read()
    {
        std::unordered_map<RaplDomain, uint32_t> result;

        return result;
    }
} // namespace optkit::core



// Overloading << for unordered_map with RaplDomain as keys
std::ostream &operator<<(std::ostream &os, const std::unordered_map<optkit::core::RaplDomain, uint32_t> &map)
{
    os << "{ ";
    for (const auto &pair : map)
    {
        os << pair.first << ": " << pair.second << ", ";
    }
    os << "}";
    return os;
}
