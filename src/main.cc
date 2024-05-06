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

    // float aa = 0;
    {
        optkit::core::recepies::intel::icl::ComputationalIntensity ci;
        OPTKIT_PERFORMANCE_EVENTS("temp block", "Computational Intensity", pp, ci.get_recepies());

        // for (int i = 0; i < 100; i++)
        //     aa += i;

        std::cout << QueryFreq::get_bios_limit();
    }
    return 0;
}
