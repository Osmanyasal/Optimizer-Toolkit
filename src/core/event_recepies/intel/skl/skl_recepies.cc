
#include <skl_recepies.hh>

namespace optkit::core::recepies::intel::skl
{
    /**
     * @brief No need for exact numbers, we only need intuitions
     * 
     * @return const std::vector<std::pair<uint64_t, std::string>> 
     */
    const std::vector<std::pair<uint64_t, std::string>> Recepies::computational_intensity()
    {
        return {
            {{optkit::intel::skl::INSTRUCTIONS_RETIRED}, "instructions"},

            {optkit::intel::skl::FP_ARITH_INST_RETIRED |
                 optkit::intel::skl::FP_ARITH_INST_RETIRED__MASK__SKL_FP_ARITH__SCALAR_SINGLE |
                 optkit::intel::skl::FP_ARITH_INST_RETIRED__MASK__SKL_FP_ARITH__SCALAR_DOUBLE |
                 optkit::intel::skl::FP_ARITH_INST_RETIRED__MASK__SKL_FP_ARITH__128B_PACKED_SINGLE |
                 optkit::intel::skl::FP_ARITH_INST_RETIRED__MASK__SKL_FP_ARITH__128B_PACKED_DOUBLE |
                 optkit::intel::skl::FP_ARITH_INST_RETIRED__MASK__SKL_FP_ARITH__256B_PACKED_SINGLE |
                 optkit::intel::skl::FP_ARITH_INST_RETIRED__MASK__SKL_FP_ARITH__256B_PACKED_DOUBLE |
                 optkit::intel::skl::FP_ARITH_INST_RETIRED__MASK__SKL_FP_ARITH__512B_PACKED_SINGLE |
                 optkit::intel::skl::FP_ARITH_INST_RETIRED__MASK__SKL_FP_ARITH__512B_PACKED_DOUBLE,
             "fp_arith"},

            {{optkit::intel::skl::MEM_LOAD_RETIRED |
              optkit::intel::skl::MEM_LOAD_RETIRED__MASK__SKL_MEM_LOAD_RETIRED__L1_HIT |
              optkit::intel::skl::MEM_LOAD_RETIRED__MASK__SKL_MEM_LOAD_RETIRED__L1_MISS |
              optkit::intel::skl::MEM_LOAD_RETIRED__MASK__SKL_MEM_LOAD_RETIRED__L2_HIT |
              optkit::intel::skl::MEM_LOAD_RETIRED__MASK__SKL_MEM_LOAD_RETIRED__L2_MISS |
              optkit::intel::skl::MEM_LOAD_RETIRED__MASK__SKL_MEM_LOAD_RETIRED__L3_HIT},
             "l1_l2_hit_misses__l3_hit"},

            {optkit::intel::skl::MEM_LOAD_L3_MISS_RETIRED |
                 optkit::intel::skl::MEM_LOAD_L3_MISS_RETIRED__MASK__SKL_MEM_LOAD_L3_MISS_RETIRED__REMOTE_DRAM |
                 optkit::intel::skl::MEM_LOAD_L3_MISS_RETIRED__MASK__SKL_MEM_LOAD_L3_MISS_RETIRED__LOCAL_DRAM,
             "l3_miss_load_from_remote_local_dram"}};
    }

}