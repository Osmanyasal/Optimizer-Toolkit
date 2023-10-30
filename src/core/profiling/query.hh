#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__QUERY_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__QUERY_HH

#include <iostream> 
#include <utils.hh>
#include <iomanip>  
#include <libpfm4_wrapper.hh>

std::ostream &operator<<(std::ostream &out, const pfm_pmu_info_t &pmu_info);

namespace optkit::core
{
    /**
     * @brief  Query CPU PMU and PMU events here<br>
     * This Query class uses <b>libpfm4</b> to retrieve information 
     * @endcode
     * 
     */
    class Query
    {
    public:
        static void init();
        static void destroy();
        static pfm_pmu_info_t pmu_info(const char *pmu_name);
        static void local_pmu_info();
        static void event_info(const char *pmu_event_name);

    private:
        static bool is_active;
    };
 
} // namespace optkit::core

#endif // OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__QUERY_HH