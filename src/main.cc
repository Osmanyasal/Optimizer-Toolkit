#include <omp.h>
#include <optkit.hh>
#include <test.hh>
#include <icl_governor.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{false};

    {
        optkit::core::governors::intel::icl::Governor gg;

        BLOCK_TIMER("Operation Block");
        double aa = 0;
        for (int i = 0; i < 20000000; i++)
            aa = aa + i * 0.052; // 2 * 50M -> 100M

        std::cout << aa << std::endl;
    }

    {
        optkit::core::governors::intel::icl::Governor gg;

        BLOCK_TIMER("IO Block");

        for (int i = 0; i < 100000; i++)
        {
            QueryFreq::get_bios_limit();
            QueryFreq::get_cpuinfo_max_freq();
            QueryFreq::get_cpuinfo_min_freq();
            QueryFreq::get_scaling_driver();
            QueryFreq::get_scaling_governor();
            QueryFreq::get_scaling_max_limit();
            QueryFreq::get_scaling_min_limit();
        }
    }

    return 0;
}
