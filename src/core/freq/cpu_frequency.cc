#include <cpu_frequency.hh>

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


    void CPUFrequency::set_core_frequency(long frequency, short socket)
    {
        try
        {
            // Set core frequency for all cores
            TRAVERSE_CORES(socket)
            {

                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_max_freq", std::to_string(frequency));
                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_min_freq", std::to_string(frequency));
            }
        }
        catch (std::runtime_error err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
    }

    void CPUFrequency::set_core_frequency(long frequency, short cpu, short socket)
    {
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
            catch (std::runtime_error err)
            {
                OPTKIT_CORE_ERROR(err.what());
            }
        }
        else
        {
            OPTKIT_CORE_WARN("Invalid range cpu={}", cpu);
        }
    }

    void CPUFrequency::set_core_frequency(long frequency, short cpu_start, short cpu_end, short socket)
    {
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
            catch (std::runtime_error err)
            {
                OPTKIT_CORE_ERROR(err.what());
            }
        }
        else
        {
            OPTKIT_CORE_WARN("Invalid range cpu_start={} cpu_end={}", cpu_start, cpu_end);
        }
    }

    long CPUFrequency::get_core_frequency(short cpu)
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
    }

    std::vector<long> CPUFrequency::get_core_frequencies(short socket)
    {
        std::vector<long> core_frequencies;
        try
        {
            TRAVERSE_CORES(socket)
            {
                core_frequencies.push_back(std::atol(::read_file("/sys/devices/system/cpu/cpu" + std::to_string(__cpu) + "/cpufreq/scaling_cur_freq").c_str()));
            }
            return core_frequencies;
        }
        catch (const std::runtime_error &err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
    }

    std::vector<long> CPUFrequency::get_core_frequency(short cpu_start, short cpu_end, short socket)
    {
        if (cpu_start < 0 || cpu_end < cpu_start || cpu_end >= Query::num_cores)
        {
            OPTKIT_CORE_WARN("Invalid range cpu_start={} cpu_end={}", cpu_start, cpu_end);
            return {};
        }

        std::vector<long> core_frequencies;
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

    long CPUFrequency::get_uncore_frequency()
    {
        //TODO: implement this
        return 0;
    }

    void CPUFrequency::set_uncore_frequency(long frequency)
    {
        // TODO: implement this
    }

#undef TRAVERSE_CORES
}
