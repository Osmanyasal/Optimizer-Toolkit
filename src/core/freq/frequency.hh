#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQUENCY_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQUENCY_HH

#include <vector>
#include <map>
#include <utils.hh>
#include <query.hh>

namespace optkit::core::freq
{

    class BaseFrequency final
    {
    public:
        static void set_core_frequency(long frequency,short socket=0);
        static void set_core_frequency(long frequency, short cpu, short socket = 0);
        static void set_core_frequency(long frequency, short cpu_start, short cpu_end, short socket = 0);
        static long get_core_frequency(short cpu, short socket = 0);
        static std::vector<long> get_core_frequency(short socket = 0);
        static std::vector<long> get_core_frequency(short cpu_start, short cpu_end, short socket = 0);

        static long get_uncore_frequency();
        static void set_uncore_frequency(long frequency);

    private:
        static std::vector<long> core_frequencies;
        static long uncore_frequency;
        static const std::map<int32_t, std::vector<int32_t>> &package_info;

    private:
        BaseFrequency();
        ~BaseFrequency();
    };

}

#endif
