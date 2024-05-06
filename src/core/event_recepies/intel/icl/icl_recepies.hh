#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__ICL__ICL_RECEPIES__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__ICL__ICL_RECEPIES__HH

#include <base_recepie.hh>
#include <intel/icl.hh>

namespace optkit::core::recepies::intel::icl
{
    class ComputationalIntensity : public recepies::base::ComputationalIntensity
    {
    public:
        ComputationalIntensity() {}
        virtual ~ComputationalIntensity() {}

        virtual const std::vector<std::pair<uint64_t, std::string>> get_recepies() override
        {
            return {{optkit::intel::icl::INSTRUCTIONS_RETIRED, "instructions_retired"}, 
            {optkit::intel::icl::MEM_LOAD_RETIRED | optkit::intel::icl::MEM_LOAD_RETIRED__MASK__INTEL_ICL_MEM_LOAD_RETIRED__L3_MISS, "l3_cache_miss"}};
        }
    };
}

#endif