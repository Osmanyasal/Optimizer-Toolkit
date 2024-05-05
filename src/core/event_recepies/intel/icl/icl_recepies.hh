#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__ICL__ICL_RECEPIES__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__ICL__ICL_RECEPIES__HH

#include <base_recepie.hh>
#include <iostream>

namespace optkit::core::recepies::intel::icl
{
    class ComputationalIntensity : public recepies::base::ComputationalIntensity
    {
    public:
        ComputationalIntensity() {}
        virtual ~ComputationalIntensity() {}

        virtual const std::vector<std::pair<uint64_t, std::string>> get_recepies() override
        {
            std::cout << "hello there\n";

            return {};
        }
    };
}

#endif