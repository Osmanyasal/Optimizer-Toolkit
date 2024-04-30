#include <query_frequency.hh>

namespace optkit::core::freq
{

    std::vector<long> QueryFreq::get_scaling_available_frequencies(int core)
    {
        std::vector<long> frequencies;
        std::string file_content = read_file("/sys/devices/system/cpu/cpu" + std::to_string(core) + "/cpufreq/scaling_available_frequencies", false);
        std::istringstream iss(file_content);
        long freq;
        while (iss >> freq)
        {
            frequencies.push_back(freq);
        }
        return frequencies;
    }

    long QueryFreq::get_bios_limit(int core)
    {
        std::string file_content = read_file("/sys/devices/system/cpu/cpu" + std::to_string(core) + "/cpufreq/bios_limit", false);
        return std::stol(file_content);
    }

    std::string QueryFreq::get_scaling_driver(int core)
    {
        return read_file("/sys/devices/system/cpu/cpu" + std::to_string(core) + "/cpufreq/scaling_driver", false);
    }

    std::string QueryFreq::get_scaling_governor(int core)
    {
        return read_file("/sys/devices/system/cpu/cpu" + std::to_string(core) + "/cpufreq/scaling_governor", false);
    }

    long QueryFreq::get_scaling_max_limit(int core)
    {
        std::string file_content = read_file("/sys/devices/system/cpu/cpu" + std::to_string(core) + "/cpufreq/scaling_max_freq", false);
        return std::stol(file_content);
    }

    long QueryFreq::get_scaling_min_limit(int core)
    {
        std::string file_content = read_file("/sys/devices/system/cpu/cpu" + std::to_string(core) + "/cpufreq/scaling_min_freq", false);
        return std::stol(file_content);
    }

    long QueryFreq::get_cpuinfo_scaling_max_limit(int core)
    {
        std::string file_content = read_file("/sys/devices/system/cpu/cpu" + std::to_string(core) + "/cpufreq/cpuinfo_max_freq", false);
        return std::stol(file_content);
    }

    long QueryFreq::get_cpuinfo_scaling_min_limit(int core)
    {
        std::string file_content = read_file("/sys/devices/system/cpu/cpu" + std::to_string(core) + "/cpufreq/cpuinfo_min_freq", false);
        return std::stol(file_content);
    }
}