#include <cpu_frequency.hh>

std::ostream &operator<<(std::ostream &os, const std::pair<int64_t, int64_t> &pair)
{
    os << "Pair(" << pair.first << ", " << pair.second << ")\n"; 
    return os;
}

namespace optkit::core::freq
{
    // Define static member variables

    const std::map<int32_t, std::vector<int32_t>> &CPUFrequency::package_info = Query::detect_packages();

#define TRAVERSE_CORES(socket)                           \
    if (package_info.find(socket) == package_info.end()) \
    {                                                    \
        OPTKIT_CORE_WARN("Invalid socket {}", socket);   \
    }                                                    \
    else                                                 \
        for (int32_t __cpu : package_info.at(socket))

    void CPUFrequency::set_core_frequency(int64_t frequency, int16_t socket)
    {
        EXEC_IF_ROOT;
        try
        {
            // Set core frequency for all cores
            TRAVERSE_CORES(socket)
            {

                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_max_freq", std::to_string(frequency));
                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_min_freq", std::to_string(frequency));
            }
        }
        catch (const std::runtime_error &err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
    }

    void CPUFrequency::set_core_frequency(int64_t frequency, int16_t cpu, int16_t socket)
    {
        EXEC_IF_ROOT;
        if (cpu >= 0 && cpu < Query::num_cores)
        {
            try
            {
                TRAVERSE_CORES(socket)
                {
                    if (cpu == __cpu)
                    {
                        ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_max_freq", std::to_string(frequency));
                        ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_min_freq", std::to_string(frequency));
                    }
                }
            }
            catch (const std::runtime_error &err)
            {
                OPTKIT_CORE_ERROR(err.what());
            }
        }
        else
        {
            OPTKIT_CORE_WARN("Invalid range cpu={}", cpu);
        }
    }

    void CPUFrequency::set_core_frequency(int64_t frequency, int16_t cpu_start, int16_t cpu_end, int16_t socket)
    {
        EXEC_IF_ROOT;
        if (cpu_start >= 0 && cpu_end < Query::num_cores && cpu_start <= cpu_end)
        {
            try
            {
                TRAVERSE_CORES(socket)
                {
                    if (__cpu < cpu_start || __cpu > cpu_end)
                        continue;

                    ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_max_freq", std::to_string(frequency));
                    ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_min_freq", std::to_string(frequency));
                }
            }
            catch (const std::runtime_error &err)
            {
                OPTKIT_CORE_ERROR(err.what());
            }
        }
        else
        {
            OPTKIT_CORE_WARN("Invalid range cpu_start={} cpu_end={}", cpu_start, cpu_end);
        }
    }

    void CPUFrequency::set_core_frequency(int64_t frequency, std::vector<int16_t> cpu_list)
    {
        EXEC_IF_ROOT;
        try
        {
            for (int16_t &__cpu : cpu_list)
            {
                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_max_freq", std::to_string(frequency));
                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_min_freq", std::to_string(frequency));
            }
        }
        catch (const std::runtime_error &err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
    }

    int64_t CPUFrequency::get_core_frequency(int16_t cpu)
    {
        try
        {
            if (cpu >= 0 && cpu < Query::num_cores)
            {
                return std::atol(::read_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_cur_freq").c_str());
            }
            else
            {
                OPTKIT_CORE_WARN("Invalid range cpu={}", cpu);
                return -1;
            }
        }
        catch (const std::runtime_error &err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
        return -1;
    }

    std::vector<int64_t> CPUFrequency::get_core_frequencies(int16_t socket)
    {
        std::vector<int64_t> core_frequencies;
        try
        {
            TRAVERSE_CORES(socket)
            {
                core_frequencies.push_back(std::atol(::read_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_cur_freq").c_str()));
            }
        }
        catch (const std::runtime_error &err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
        return core_frequencies;
    }

    std::vector<int64_t> CPUFrequency::get_core_frequency(int16_t cpu_start, int16_t cpu_end, int16_t socket)
    {
        if (cpu_start < 0 || cpu_end < cpu_start || cpu_end >= Query::num_cores)
        {
            OPTKIT_CORE_WARN("Invalid range cpu_start={} cpu_end={}", cpu_start, cpu_end);
            return {};
        }

        std::vector<int64_t> core_frequencies;
        try
        {
            TRAVERSE_CORES(socket)
            {

                if (__cpu < cpu_start || __cpu > cpu_end)
                    continue;

                core_frequencies.push_back(std::atol(::read_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_cur_freq").c_str()));
            }
        }
        catch (const std::runtime_error &err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
        return core_frequencies;
    }

    int64_t CPUFrequency::get_uncore_frequency()
    {

        uint64_t MSR_UNCORE_RATIO_LIMIT_bits;
        core::freq::read_msr(0, MSR_UNCORE_RATIO_LIMIT, &MSR_UNCORE_RATIO_LIMIT_bits);

        int64_t max_uncore_freq = (MSR_UNCORE_RATIO_LIMIT_bits & MSR_UNCORE_RATIO_LIMIT_max_mask) * 100000000;
        int64_t min_uncore_freq = ((MSR_UNCORE_RATIO_LIMIT_bits & MSR_UNCORE_RATIO_LIMIT_min_mask) >> MSR_UNCORE_RATIO_LIMIT_min_shift) * 100000000;

        OPTKIT_CORE_INFO("uncore freq min {}, max {}", min_uncore_freq, max_uncore_freq);
        return 0;
    }

    std::pair<int64_t, int64_t> CPUFrequency::get_uncore_frequencies(int16_t socket)
    {
        static std::pair<int64_t, int64_t> result{0, 0};

        if (OPT_LIKELY(result.first != 0))
            return result;

        uint64_t MSR_UNCORE_RATIO_LIMIT_bits = 0;
        core::freq::read_msr(0, MSR_UNCORE_RATIO_LIMIT, &MSR_UNCORE_RATIO_LIMIT_bits);

        // min uncore freq
        result.first = ((MSR_UNCORE_RATIO_LIMIT_bits & MSR_UNCORE_RATIO_LIMIT_min_mask) >> MSR_UNCORE_RATIO_LIMIT_min_shift) * 100000000;

        // max uncore freq
        result.second = (MSR_UNCORE_RATIO_LIMIT_bits & MSR_UNCORE_RATIO_LIMIT_max_mask) * 100000000;

        OPTKIT_CORE_INFO("uncore freq min {}, max {}", result.first, result.second);

        return result;
    }

    void CPUFrequency::set_uncore_frequency(int64_t frequency)
    {
        EXEC_IF_ROOT;
        // TODO: implement this
    }

    void CPUFrequency::reset_core_frequency(int16_t socket)
    {
        EXEC_IF_ROOT;
        try
        {
            // Set core frequency for all cores
            TRAVERSE_CORES(socket)
            {

                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_max_freq", std::to_string(QueryFreq::get_cpuinfo_max_freq(socket)));
                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_min_freq", std::to_string(QueryFreq::get_cpuinfo_min_freq(socket)));
            }
        }
        catch (const std::runtime_error &err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
    }
    void CPUFrequency::reset_uncore_frequency(int16_t socket)
    {
        EXEC_IF_ROOT;
        // TODO: implement this
    }

#undef TRAVERSE_CORES
}
