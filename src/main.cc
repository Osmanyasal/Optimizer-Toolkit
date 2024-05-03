#include <omp.h>
#include <optkit.hh>
#include <test.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{false};

    optkit::test::freq::run();

    return 0;
}