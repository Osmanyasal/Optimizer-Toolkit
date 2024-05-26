#include <omp.h>
#include <optkit.hh>
#include <test.hh>
#include <icl_governor.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{false};

    BLOCK_TIMER("osman yasal");

    optkit::core::governors::intel::icl::Governor gg;

    {
        double aa = 0;
        for (int i = 0; i < 50000000; i++)
            aa = aa + i * 0.052; // 2 * 50M -> 100M
    }

    return 0;
}
