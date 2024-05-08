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

        // virtual const std::vector<std::pair<uint64_t, std::string>> get_recepies() override
        // {
        //     return {{optkit::intel::icl::INSTRUCTIONS_RETIRED, "instructions_retired"},
        //             {optkit::intel::icl::MEM_LOAD_RETIRED | optkit::intel::icl::MEM_LOAD_RETIRED__MASK__INTEL_ICL_MEM_LOAD_RETIRED__L3_MISS, "l3_cache_miss"}};
        // }

        virtual const std::vector<std::pair<uint64_t, std::string>> get_recepies() override
        {
            return {{optkit::intel::icl::FP_ARITH_INST_RETIRED |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_SINGLE |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__VECTOR |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__128B_PACKED_DOUBLE |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__128B_PACKED_SINGLE |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__256B_PACKED_DOUBLE |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__256B_PACKED_SINGLE |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__512B_PACKED_DOUBLE |
                         optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__512B_PACKED_SINGLE,
                     "fp_arith"},
                    {optkit::intel::icl::MEM_LOAD_RETIRED | optkit::intel::icl::MEM_LOAD_RETIRED__MASK__INTEL_ICL_MEM_LOAD_RETIRED__L3_MISS, "l3_cache_miss"}};
        }
    };
}

#endif