#include <rapl.hh>

namespace optkit::core
{
    const std::unordered_map<int32_t, std::string> rapl_domain_name_mapping = {
        {static_cast<int32_t>(RaplDomain::PP0), "energy-cores"},
        {static_cast<int32_t>(RaplDomain::PP1), "energy-gpu"},
        {static_cast<int32_t>(RaplDomain::PACKAGE), "energy-pkg"},
        {static_cast<int32_t>(RaplDomain::PSYS), "energy-psys"},
        {static_cast<int32_t>(RaplDomain::DRAM), "energy-ram"},
        {static_cast<int32_t>(RaplDomain::ALL), "All domains"}};

    const std::unordered_map<int32_t, std::string> rapl_read_method_name_mapping = {
        {static_cast<int32_t>(RaplReadMethods::PERF), "PERF"},
        {static_cast<int32_t>(RaplReadMethods::MSR), "MSR"},
        {static_cast<int32_t>(RaplReadMethods::POWERCAP), "POWERCAP"}};

} // namespace optkit::core

// Overload << operator for RaplDomain
std::ostream &operator<<(std::ostream &os, const optkit::core::RaplDomain& domain)
{
    switch (domain)
    {
    case optkit::core::RaplDomain::PP0:
        os << "Cores (PowerPlane:0)";
        break;
    case optkit::core::RaplDomain::PP1:
        os << "Integrated GPU (PowerPlane:1)";
        break;
    case optkit::core::RaplDomain::PACKAGE:
        os << "PACKAGE";
        break;
    case optkit::core::RaplDomain::PSYS:
        os << "PSYS";
        break;
    case optkit::core::RaplDomain::DRAM:
        os << "DRAM";
        break;
    default:
        break;
    }

    return os;
}

std::ostream &operator<<(std::ostream &os, const optkit::core::RaplDomainInfo& domain_info)
{ 
    std::ostringstream stream;
    stream << std::scientific << domain_info.scale;
    std::string scale_scf = stream.str();
    
    os << "Event=" << domain_info.event << ", "
       << "Config=" << domain_info.config << ", "
       << "scale=" << scale_scf << ", "
       << "units=" << domain_info.units;
    return os;
}

std::ostream &operator<<(std::ostream &os, const optkit::core::RaplReadMethods& read_method)
{

    switch (read_method)
    {
    case optkit::core::RaplReadMethods::PERF:
        os << "Perf";
        break;
    case optkit::core::RaplReadMethods::MSR:
        os << "MSR";
        break;
    case optkit::core::RaplReadMethods::POWERCAP:
        os << "PowerCap";
        break;

    default:
        break;
    }
    return os;
}
