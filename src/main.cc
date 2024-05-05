#include <omp.h>
#include <optkit.hh>
#include <test.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    std::cout << "num sockets: " << Query::num_sockets << " num cores:" << Query::num_cores << "\n";

    return 0;

    optkit::test::freq::run();

    std::cout << "reset frequency !!\n";

    CPUFrequency::reset_core_frequency(0);
    CPUFrequency::reset_uncore_frequency(0);
    return 0;
}

