#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__QUERY_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__QUERY_HH

#include <iostream> 
#include <utils.hh>
#include <iomanip>  
#include <libpfm4_wrapper.hh>
#include <vector>

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
        
        static pfm_pmu_info_t pmu_info(int pmu_id);
        static void event_info(const char *pmu_event_name);

        static void list_avail_pmus();
        static std::vector<int> get_avail_pmus();

    private:
        static bool is_active;
    };
 
} // namespace optkit::core

#endif // OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__QUERY_HH