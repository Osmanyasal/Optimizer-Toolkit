#include <rapl.hh>

namespace optkit::core
{

} // namespace optkit::core

// Overload << operator for RaplDomain
std::ostream &operator<<(std::ostream &os, optkit::core::RaplDomain domain)
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
