#include <omp.h>
#include <optkit.hh>
#include <intel/icl.hh>
#include <examples.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    optkit::examples::example__sse_avx_loop_comparison();

    std::cout << "EXECUTION DONE !!!\n";

    return 0;
}