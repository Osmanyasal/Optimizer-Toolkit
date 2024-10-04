#include <omp.h>
#include <optkit.hh>
#include <test.hh>
#include <core_events.hh>

#define OPTKIT_COMPUTE_INTENSITY(var_name, block_name)                                                              \
    optkit::core::pmu::BlockGroupProfiler var_name                                                                  \
    {                                                                                                               \
        block_name, "compute_and_memory_intensity", optkit::core::recepies::intel::icl::Recepies::freq_governor_events() \
    }

#define VECTOR_SIZE 100000000  // 1 billion elements
#define NUM_ACCESSES 100000000 // 100 million random accesses

void random_access()
{
    OPTKIT_COMPUTE_INTENSITY(ci_random_access, "random_access");

    // Initialize the vector with random values
    std::vector<double> vec(VECTOR_SIZE);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 10.0); // Random values between 0.0 and 10.0

    for (size_t i = 0; i < VECTOR_SIZE; ++i)
    {
        vec[i] = dis(gen);
    }

    double sum = 0.0;

#pragma omp parallel reduction(+ : sum)
    {
        std::mt19937 thread_gen(rd() ^ omp_get_thread_num()); // Seed differently for each thread
        std::uniform_int_distribution<> thread_dis(0, vec.size() - 1);

#pragma omp for
        for (int i = 0; i < NUM_ACCESSES; ++i)
        {
            int idx = thread_dis(thread_gen); // Get a truly random index
            sum += vec[idx];
        }
    }

    std::cout << "Sum: " << std::fixed << sum << std::endl; // Output the sum to check correctness
}

void print_info()
{

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
}

void triad()
{
    BLOCK_TIMER("Triad Block");
    double aa = 0;

#pragma omp parallel for
    for (int32_t i = 0; i < 900000000; i++)
        aa = aa + i * 0.052; // 2 * 50M -> 100M

    // std::cout << aa << std::endl;
}

int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{};
    OPTKIT_RAPL(rapl_var, "main_block");
    random_access();
    return 0;
}
