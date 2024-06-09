
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
                 "fp_arith"},
                {optkit::intel::icl::MEM_LOAD_L3_MISS_RETIRED |
                     optkit::intel::icl::MEM_LOAD_L3_MISS_RETIRED__MASK__INTEL_ICL_MEM_LOAD_L3_MISS_RETIRED__REMOTE_DRAM |
                     optkit::intel::icl::MEM_LOAD_L3_MISS_RETIRED__MASK__INTEL_ICL_MEM_LOAD_L3_MISS_RETIRED__LOCAL_DRAM,
                 "l3_cache_miss_load_from_local_remote_dram"}};
    }

}