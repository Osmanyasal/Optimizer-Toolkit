
#include <icl_recepies.hh>

namespace optkit::core::recepies::intel::icl
{
    const std::vector<std::pair<uint64_t, std::string>> Recepies::computational_intensity()
    {
        return {{optkit::intel::icl::FP_ARITH_INST_RETIRED |
                     optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR | 
                     optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_SINGLE |
                     optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE |
                     optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__VECTOR,
                    //  optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__128B_PACKED_DOUBLE |
                    //  optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__128B_PACKED_SINGLE |
                    //  optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__256B_PACKED_DOUBLE |
                    //  optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__256B_PACKED_SINGLE |
                    //  optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__512B_PACKED_DOUBLE |
                    //  optkit::intel::icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__512B_PACKED_SINGLE,
                 "fp_arith"},
                {optkit::intel::icl::INSTRUCTIONS_RETIRED, "instructions_retired"},
                {optkit::intel::icl::MEM_LOAD_RETIRED | optkit::intel::icl::MEM_LOAD_RETIRED__MASK__INTEL_ICL_MEM_LOAD_RETIRED__L3_MISS, "l3_cache_miss"}};
    }
 
}