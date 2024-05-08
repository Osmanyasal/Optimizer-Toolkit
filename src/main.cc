#include <omp.h>
#include <optkit.hh>
#include <test.hh>

#include <icl_recepies.hh>

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit;

    // optkit::core::recepies::intel::icl::ComputationalIntensity ci;
    // ci.get_recepies();

    // std::cout << "num sockets: " << Query::num_sockets << " num cores:" << Query::num_cores << "\n";

    // return 0;

    // optkit::test::freq::run();

    // std::cout << "reset frequency !!\n";

    // CPUFrequency::reset_core_frequency(0);
    // CPUFrequency::reset_uncore_frequency(0);

    optkit::core::recepies::intel::icl::ComputationalIntensity ci;

    {
        double aa = 0;
        OPTKIT_PERFORMANCE_BLOCK_EVENTS("for_loop", "Computational Intensity", pp, ci.get_recepies());

        for (int i = 0; i < 1000000; i++)
            aa =  aa + i * 0.052;

        std::cout << aa << "\n"; 
    }

    {
        OPTKIT_PERFORMANCE_EVENTS("file_read", "Computational Intensity", pp, ci.get_recepies());

        std::cout << QueryFreq::get_bios_limit();
    }

    {
        OPTKIT_PERFORMANCE_EVENTS("multiple_file_read", "Computational Intensity", pp, ci.get_recepies());

        std::cout << QueryFreq::get_bios_limit() << QueryFreq::get_cpuinfo_max_freq() << QueryFreq::get_cpuinfo_min_freq() << QueryFreq::get_scaling_driver() << QueryFreq::get_scaling_max_limit();
    }

    {
        OPTKIT_PERFORMANCE_EVENTS("multiple_file_write", "Computational Intensity", pp, ci.get_recepies());

        for (int i = 0; i < 100; i++)
        {
            CPUFrequency::set_core_frequency(1200000, 0);

            CPUFrequency::set_core_frequency(1300000, 0);

            CPUFrequency::set_core_frequency(3300000, 0);
        }
    }

    CPUFrequency::reset_core_frequency(0);

    return 0;
}
