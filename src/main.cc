#include <omp.h>
#include <optkit.hh>
#include <test.hh>
#include <core_events.hh>

#define VECTOR_SIZE 100000000  // 1 billion elements
#define NUM_ACCESSES 100000000 // 100 million random accesses

void randomAccesses(std::vector<double> &vec, int num_accesses)
{
    // Use a high-quality random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, vec.size() - 1);

    double sum = 0.0;

#pragma omp parallel reduction(+ : sum)
    {
        std::mt19937 thread_gen(rd() ^ omp_get_thread_num()); // Seed differently for each thread
        std::uniform_int_distribution<> thread_dis(0, vec.size() - 1);

#pragma omp for
        for (int i = 0; i < num_accesses; ++i)
        {
            int idx = thread_dis(thread_gen); // Get a truly random index
            sum += vec[idx];
        }
    }

    std::cout << "Sum: " << sum << std::endl; // Optional: Output the sum to check correctness
}
int32_t main(int32_t argc, char **argv)
{
    OptimizerKit optkit{};
    freq_governors::intel::icl::Governor gg{};

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

            BLOCK_TIMER("Triad Block");
            double aa = 0;

    #pragma omp parallel for
            for (int32_t i = 0; i < 900000000; i++)
                aa = aa + i * 0.052; // 2 * 50M -> 100M

            // std::cout << aa << std::endl;
        }

        {

            BLOCK_TIMER("Matrix MUL Block");

            #define ARRAY_SIZE 100000000
            #define SCALE_FACTOR 2.134

            double *A = new double[ARRAY_SIZE];
            double *B = new double[ARRAY_SIZE];
            double *C = new double[ARRAY_SIZE];

            // Initialize arrays A and B
            #pragma omp parallel for
            for (int i = 0; i < ARRAY_SIZE; ++i)
            {
                A[i] = 1.0;
                B[i] = 2.0;
                C[i] = 0.0; // Initialize C to zero
            }

            #pragma omp parallel for
            for (int i = 0; i < ARRAY_SIZE; ++i)
            {
                C[i] = A[i] + SCALE_FACTOR * B[i];
            }

            // Clean up
            delete[] A;
            delete[] B;
            delete[] C;
    #undef MATRIX_SIZE
        }

    {
        BLOCK_TIMER("Random access !");
        std::vector<double> vec(VECTOR_SIZE, 1.0); // Initialize a large vector with all elements set to 1.0

        randomAccesses(vec, NUM_ACCESSES);
    }

    //     {
    //         // freq_governors::intel::icl::Governor gg;
    //         BLOCK_TIMER("IO Block");

    // #pragma omp parallel for
    //         for (int32_t i = 0; i < 1000; i++)
    //         {
    //             QueryFreq::get_bios_limit();
    //             QueryFreq::get_cpuinfo_max_freq();
    //             QueryFreq::get_cpuinfo_min_freq();
    //             QueryFreq::get_scaling_driver();
    //             QueryFreq::get_scaling_governor();
    //             QueryFreq::get_scaling_max_limit();
    //             QueryFreq::get_scaling_min_limit();
    //         }
    //     }
    return 0;
}
