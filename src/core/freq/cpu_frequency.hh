#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__CPU__FREQ__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__CPU__FREQ__HH

#include <vector>
#include <map>
#include <utils.hh>
#include <query.hh>
#include <query_frequency.hh>
#include <msr_util.hh>
#include <msrs.hh>
#include <utility>

std::ostream &operator<<(std::ostream &os, const std::pair<int64_t, int64_t> &pair);

namespace optkit::core::freq
{

    class CPUFrequency final
    {
    public:
        static void set_core_frequency(int64_t frequency, int16_t socket);
        static void set_core_frequency(int64_t frequency, int16_t cpu, int16_t socket);
        static void set_core_frequency(int64_t frequency, int16_t cpu_start, int16_t cpu_end, int16_t socket);
        static void set_core_frequency(int64_t frequency, std::vector<int16_t> cpu_list);
        static int64_t get_core_frequency(int16_t cpu);
        static std::vector<int64_t> get_core_frequencies(int16_t socket);
        static std::vector<int64_t> get_core_frequency(int16_t cpu_start, int16_t cpu_end, int16_t socket);
        static std::pair<int64_t, int64_t> get_uncore_min_max(int16_t socket); 

        static int64_t get_uncore_frequency(int16_t socket);
        static void set_uncore_frequency(int64_t frequency, int16_t socket);

        static void reset_core_frequency(int16_t socket);
        static void reset_uncore_frequency(int16_t socket);

    private:
        static const std::map<int32_t, std::vector<int32_t>> &package_info;

    private:
        CPUFrequency() = delete;
        ~CPUFrequency() = delete;
    };

}

#endif
