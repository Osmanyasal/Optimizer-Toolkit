#include <omp.h>
#include <optkit.hh>
#include <test.hh>
#include <icl_governor.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{false};
    optkit::core::governors::intel::icl::Governor gg;

    BLOCK_TIMER("osman yasal");

    {
        double aa = 0;
        for (int i = 0; i < 2000000; i++)
            aa = aa + i * 0.052; // 2 * 50M -> 100M
    }

    return 0;
}
