#include <omp.h>
#include <optkit.hh>
#include <intel/icl.hh>
#include <examples.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    for (auto &info : optkit::core::Query::rapl_domain_info())
        std::cout << info << "\n";

    optkit::examples::example__sse_avx_loop_comparison();

    std::cout << "EXECUTION DONE !!!\n";
    // const auto &val = optkit::core::rapl::from_json(read_file(EXECUTION_FOLDER_NAME + "/add_serial__rapl.json"));
    // std::cout << "FROM JSON IS DONE!\n";
    // for (auto &&i : val)
    // {
    //     std::cout << i.first << " " << i.second << "\n";
    // }

    return 0;
}