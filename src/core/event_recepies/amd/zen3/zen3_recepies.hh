#pragma once

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

    private:
        Recepies() = delete;
        ~Recepies() = delete;
    };
}
