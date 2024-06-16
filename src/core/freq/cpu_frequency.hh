#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__CPU__FREQ__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__CPU__FREQ__HH

#include <vector>
#include <map>
#include <utils.hh>
#include <query.hh>
#include <query_frequency.hh>

namespace optkit::core::freq
{

    class CPUFrequency final
    {
    public:
        static void set_core_frequency(long frequency, short socket);
        static void set_core_frequency(long frequency, short cpu, short socket);
        static void set_core_frequency(long frequency, short cpu_start, short cpu_end, short socket);
        static void set_core_frequency(long frequency, std::vector<short> cpu_list);
        static long get_core_frequency(short cpu);
        static std::vector<long> get_core_frequencies(short socket);
        static std::vector<long> get_core_frequency(short cpu_start, short cpu_end, short socket);

        static long get_uncore_frequency();
        static void set_uncore_frequency(long frequency);

        static void reset_core_frequency(short socket);
        static void reset_uncore_frequency(short socket);

    private:
        static const std::map<int32_t, std::vector<int32_t>> &package_info;

    private:
        CPUFrequency() = delete;
        ~CPUFrequency() = delete;
    };

}

#endif
