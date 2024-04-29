#include <frequency.hh>

namespace optkit::core::freq
{
    // Define static member variables

    const std::map<int32_t, std::vector<int32_t>> &BaseFrequency::package_info = Query::detect_packages();
    std::vector<long> BaseFrequency::core_frequencies(BaseFrequency::package_info.at(0).size(), 0);
    long BaseFrequency::uncore_frequency;

#define TRAVERSE_CORES(socket)                           \
    if (package_info.find(socket) == package_info.end()) \
    {                                                    \
        OPTKIT_CORE_WARN("Invalid socket {}", socket);   \
    }                                                    \
    else                                                 \
        for (int32_t cpu : package_info.at(socket))

    void BaseFrequency::set_core_frequency(long frequency, short socket)
    {
        try
        {
            // Set core frequency for all cores
            TRAVERSE_CORES(socket)
            {

                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_max_freq", std::to_string(frequency));
                ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_min_freq", std::to_string(frequency));

                BaseFrequency::core_frequencies[cpu] = frequency;
            }
        }
        catch (std::runtime_error err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
    }

    void BaseFrequency::set_core_frequency(long frequency, short cpu, short socket)
    {
        if (cpu >= 0 && cpu < BaseFrequency::core_frequencies.size())
        {
            try
            {
                TRAVERSE_CORES(socket)
                {
                    ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_max_freq", std::to_string(frequency));
                    ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_min_freq", std::to_string(frequency));
                    BaseFrequency::core_frequencies[cpu] = frequency;
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

    void BaseFrequency::set_core_frequency(long frequency, short cpu_start, short cpu_end, short socket)
    {
        if (cpu_start >= 0 && cpu_end < BaseFrequency::core_frequencies.size() && cpu_start <= cpu_end)
        {
            try
            {
                TRAVERSE_CORES(socket)
                {

                    ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_max_freq", std::to_string(frequency));
                    ::write_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_min_freq", std::to_string(frequency));
                    BaseFrequency::core_frequencies[cpu] = frequency;
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

    long BaseFrequency::get_core_frequency(short cpu, short socket)
    {
        try
        {
            if (cpu >= 0 && cpu < BaseFrequency::core_frequencies.size())
            {
                BaseFrequency::core_frequencies[cpu] = std::atol(::read_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_cur_freq").c_str());
                return BaseFrequency::core_frequencies[cpu];
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

    std::vector<long> BaseFrequency::get_core_frequency(short socket)
    {
        try
        {

            TRAVERSE_CORES(socket)
            {
                BaseFrequency::core_frequencies[cpu] = std::atol(::read_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_cur_freq").c_str());
            }
            return BaseFrequency::core_frequencies;
        }
        catch (const std::runtime_error &err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
    }

    std::vector<long> BaseFrequency::get_core_frequency(short cpu_start, short cpu_end, short socket)
    {

        if (cpu_start < 0 || cpu_end < cpu_start || cpu_end >= BaseFrequency::core_frequencies.size())
        {
            OPTKIT_CORE_WARN("Invalid range cpu_start={} cpu_end={}", cpu_start, cpu_end);
            return {};
        }

        std::vector<long> result;
        try
        {
            TRAVERSE_CORES(socket)
            {
                BaseFrequency::core_frequencies[cpu] = std::atol(::read_file("/sys/devices/system/cpu/cpu" + std::to_string(cpu) + "/cpufreq/scaling_cur_freq").c_str());
                result.push_back(BaseFrequency::core_frequencies[cpu]);
            }
        }
        catch (const std::runtime_error &err)
        {
            OPTKIT_CORE_ERROR(err.what());
        }
        return result;
    }

    long BaseFrequency::get_uncore_frequency()
    {
        return BaseFrequency::uncore_frequency;
    }

    void BaseFrequency::set_uncore_frequency(long frequency)
    {
        BaseFrequency::uncore_frequency = frequency;
    }

#undef TRAVERSE_CORES
}
