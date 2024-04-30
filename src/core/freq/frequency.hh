#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ_HH

#include <vector>
#include <map>
#include <utils.hh>
#include <query.hh>

namespace optkit::core::freq
{

    class CPUFrequency final
    {
    public:
        static void set_core_frequency(long frequency, short socket);
        static void set_core_frequency(long frequency, short cpu, short socket);
        static void set_core_frequency(long frequency, short cpu_start, short cpu_end, short socket);
        static long get_core_frequency(short cpu);
        static std::vector<long> get_core_frequencies(short socket);
        static std::vector<long> get_core_frequency(short cpu_start, short cpu_end, short socket);

        static long get_uncore_frequency();
        static void set_uncore_frequency(long frequency);

    private:
        static std::vector<long> core_frequencies;
        static long uncore_frequency;
        static const std::map<int32_t, std::vector<int32_t>> &package_info;

    private:
        CPUFrequency();
        ~CPUFrequency();
    };

}

#endif
