#include <omp.h>
#include <optimizer_toolkit.hh>
#include <intel/icl.hh> 
#include <examples.hh>


int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    optkit::examples::example__sse_avx_loop_comparison();

    return 0;
}