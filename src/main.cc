#include <omp.h>
#include <optkit.hh>
#include <intel/icl.hh>
#include <examples.hh>

#define REPEAT_COUNT 3
int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    OPTKIT_RAPL_REPEAT_READ(add_sse, "SYSTEM NOISE", REPEAT_COUNT)
    {
        // do nothing
        sleep(1);
    }

    // float i = 0.0f;
    // OPTKIT_RAPL_REPEAT_READ(flops, "FLOPS", 20)
    // {
    //     i += 0.356f;
    // }
    // std::cout << i << "\n";
    // // optkit::examples::example__sse_avx_loop_comparison();

    std::cout << "EXECUTION DONE !!!\n";

    return 0;
}