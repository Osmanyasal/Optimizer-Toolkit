#include <omp.h>
#include <optkit.hh>
#include <intel/icl.hh>
#include <examples.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    OPTKIT_RAPL(asd, "whole_block");

    {
        BlockProfiler fp_arit{"FP_ARITH", "FP_ARITH", {{icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__512B_PACKED_SINGLE | 
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__512B_PACKED_DOUBLE |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__256B_PACKED_SINGLE |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__256B_PACKED_DOUBLE |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__128B_PACKED_SINGLE |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__128B_PACKED_DOUBLE |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_SINGLE |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__4_FLOPS |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__8_FLOPS |
        icl::FP_ARITH_INST_RETIRED__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__VECTOR , ""}}, {true, false, 0, -1, false}};
        float ff{};
        ff += 3;
        ff += 3;
        ff += 3;
        ff += 3;
        ff += 3;
        ff += 3;
        ff += 3;
        ff += 3;
        ff += 3;
    }
    // optkit::examples::example__sse_avx_loop_comparison();

    std::cout << "EXECUTION DONE !!!\n";

    return 0;
}