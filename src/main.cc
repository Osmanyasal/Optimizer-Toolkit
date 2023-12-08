#include <omp.h>
#include <optimizer_toolkit.hh>
#include <intel/icl.hh>
#include <examples.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    // optkit::examples::example__sse_avx_loop_comparison();

    std::cout << "EXECUTION DONE !!!\n";
    std::cout << optkit::core::rapl::from_json(read_file(EXECUTION_FOLDER_NAME + "/add_avx__rapl.json"));

    return 0;
}