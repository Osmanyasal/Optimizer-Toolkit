#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__AMD_ZEN3__RECEPIES__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__AMD_ZEN3__RECEPIES__HH

#include <vector>
#include <string>
#include <fam19h_zen3.hh>
#include <fam19h_zen3_l3.hh>

namespace optkit::core::recepies::amd64::zen3
{
    class Recepies final
    {
    public:
        static const std::vector<std::pair<uint64_t, std::string>> computational_intensity();
        // static const std::vector<std::pair<uint64_t, std::string>> computational_intensity();

    private:
        Recepies() = delete;
        ~Recepies() = delete;
    };
}

#endif