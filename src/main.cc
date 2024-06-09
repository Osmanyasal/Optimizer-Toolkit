#include <omp.h>
#include <optkit.hh>
#include <test.hh>
#include <icl_governor.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{false};
    optkit::core::governors::intel::icl::Governor gg;

    BLOCK_TIMER("osman yasal");

    // int arr[256];
    {
        double aa = 0;
        for (int i = 0; i < 20000000; i++)
            aa = aa + i * 0.052; // 2 * 50M -> 100M

        // for (int i = 0; i < 256;i++)
        //     std::cout << (arr[i] = i) << std::endl;
    }

    return 0;
}
