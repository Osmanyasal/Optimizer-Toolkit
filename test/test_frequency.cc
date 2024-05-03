#include <test_frequency.hh>
namespace optkit::test::freq
{

    int run()
    {
        std::cout << "Running frequency test suite...\n\n";

        test_set_core_frequency(1400000,0);
        test_get_core_frequency(7);
        // test_get_uncore_frequency();
        // test_set_uncore_frequency();

        std::cout << "\nFrequency test suite completed.\n";
        return 0;
    }
    
    void test_set_core_frequency(long freq,short socket)
    {
        utils::BlockTimer timer {"set_core_freq"};
        // Test set_core_frequency methods
        CPUFrequency::set_core_frequency(freq, socket);
        // CPUFrequency::set_core_frequency(2200000, 1, 0);
        // CPUFrequency::set_core_frequency(1800000, 2, 4, 0);
    }

    void test_get_core_frequency(short cpu)
    {
        // Test get_core_frequency methods
        long freq = CPUFrequency::get_core_frequency(cpu);  
        std::cout << "Core(" << cpu << ") Frequency: " << freq << " Hz\n";
    }

    void test_get_core_frequencies(short socket)
    {
        // Test get_core_frequency methods
        std::vector<long> freq = CPUFrequency::get_core_frequencies(socket);

        for (size_t i = 0; i < freq.size(); i++)
        {
            std::cout << freq[i] << "\n";
        }
    }

    void test_get_uncore_frequency()
    {
        // Test get_uncore_frequency method
        long uncoreFreq = CPUFrequency::get_uncore_frequency();
        std::cout << "Uncore Frequency: " << uncoreFreq << " Hz\n";
    }

    void test_set_uncore_frequency()
    {
        // Test set_uncore_frequency method
        CPUFrequency::set_uncore_frequency(3000000);
    }
 
}