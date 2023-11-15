#include <rapl.hh>

namespace optkit::core
{

    // Overload << operator for RaplDomain
    std::ostream &operator<<(std::ostream &os, RaplDomain domain)
    {
        switch (domain)
        {
        case RaplDomain::PP0:
            os << "Cores (PowerPlane:0)";
            break;
        case RaplDomain::PP1:
            os << "Integrated GPU (PowerPlane:1)";
            break;
        case RaplDomain::PACKAGE:
            os << "PACKAGE";
            break;
        case RaplDomain::PSYS:
            os << "PSYS";
            break;
        case RaplDomain::DRAM:
            os << "DRAM";
            break; 
        }

        return os;
    }

} // namespace optkit::core
 