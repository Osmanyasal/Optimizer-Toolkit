#include <omp.h>
#include <optkit.hh>
#include <test.hh>
#include <core_events.hh>

  
int32_t main(int32_t argc, char **argv) 
{
    OptimizerKit optkit{false};

    std::cout << "default uncore !\n";
    std::cout << CPUFrequency::get_uncore_min_max(0) << "\n";
    std::cout << CPUFrequency::get_uncore_frequency(0) << "\n";

    std::cout << "setting uncore !\n";
    CPUFrequency::set_uncore_frequency(2400000000,0);
    std::cout << CPUFrequency::get_uncore_frequency(0) << "\n";

    std::cout << "setting uncore !\n";
    CPUFrequency::set_uncore_frequency(1100000000, 0);
    std::cout << CPUFrequency::get_uncore_frequency(0) << "\n";

    std::cout << "resetting uncore !\n";
    CPUFrequency::reset_uncore_frequency(0);
    std::cout << CPUFrequency::get_uncore_frequency(0) << "\n";
    return 0;

    BLOCK_TIMER("Whole Program");
    {
        freq_governors::intel::skl::Governor gg;

        BLOCK_TIMER("Operation Block");
        double aa = 0;

        #pragma omp parallel for
        for (int32_t i = 0; i < 20000000; i++) 
            aa = aa + i * 0.052; // 2 * 50M -> 100M

        std::cout << aa << std::endl; 
    }

    {
        freq_governors::intel::skl::Governor gg; 
        BLOCK_TIMER("IO Block");

        #pragma omp parallel for
        for (int32_t i = 0; i < 1000; i++)
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
