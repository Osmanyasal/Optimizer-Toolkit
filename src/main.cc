#include <omp.h>
#include <optkit.hh>
#include <test.hh>
#include <core_events.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{};
    freq_governors::intel::skl::Governor gg;

    for (size_t i = 0; i < Query::num_sockets; i++)
    {
        std::cout << "Socket [" << i << "]\n";
        std::cout << "Core avail: ";
        const auto &freq_list = QueryFreq::get_scaling_available_frequencies(Query::detect_packages().at(i)[0]);
        for (auto iter = freq_list.rbegin(); iter != freq_list.rend(); iter++)
            std::cout << *iter << " ";
        std::cout << "\n";
        std::cout << "Core current: " << CPUFrequency::get_core_frequency(Query::detect_packages().at(i)[0]) << "\n";
        std::cout << "Uncore min-max: " << CPUFrequency::get_uncore_min_max(i) << "\n";
        std::cout << "Uncore current: " << CPUFrequency::get_uncore_frequency(i) << "\n";
    }

    BLOCK_TIMER("Whole Program");
    {

        BLOCK_TIMER("Operation Block");
        double aa = 0;

#pragma omp parallel for
        for (int32_t i = 0; i < 20000000; i++)
            aa = aa + i * 0.052; // 2 * 50M -> 100M

        std::cout << aa << std::endl;
    }

    {
        // freq_governors::intel::icl::Governor gg;
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
