#pragma omp once

#include <optkit.hh>
#include <cpu_frequency.hh>

namespace optkit::test::freq
{
    // call this
    int run();

    void test_set_core_frequency(long freq);
    void test_get_core_frequency(short cpu);
    void test_get_core_frequencies(short socket);
    void test_get_uncore_frequency();
    void test_set_uncore_frequency();
}