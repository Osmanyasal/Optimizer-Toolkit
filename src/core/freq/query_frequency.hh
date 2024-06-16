#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__QUERY_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__QUERY_HH

#include <vector>
#include <string>
#include <utils.hh>

namespace optkit::core::freq
{

    class QueryFreq final
    {
    public:
        static std::vector<long> get_scaling_available_frequencies(int core = 0);
        static long get_bios_limit(int core = 0);
        static std::string get_scaling_driver(int core = 0);
        static std::string get_scaling_governor(int core = 0);
        static std::vector<std::string> get_available_governors(int core = 0);

        static long get_scaling_max_limit(int core = 0);
        static long get_scaling_min_limit(int core = 0);

        static long get_cpuinfo_max_freq(int core = 0);
        static long get_cpuinfo_min_freq(int core = 0);

    private:
        QueryFreq() = delete;
        ~QueryFreq() = delete;
    };

} // namespace optkit::core::freq

#endif