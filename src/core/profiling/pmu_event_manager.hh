#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__PMU_EVENT_MANAGER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__PMU_EVENT_MANAGER_HH

#include <utils.hh>
#include <vector>
#include <unordered_map>
#include <query.hh>

namespace optkit::core
{
    class PMUEventManager
    {

    public:
        /**
         * @brief Register  a file descriptor
         *
         * @param fd file descriptor itself @see BlockProfiler
         * @param num_events number of events being registered for this fd.
         * @return bool wether fd is saved successfully
         *
         */
        static bool register_event(int32_t fd, int32_t num_events);

        /**
         * @brief UnRegister  a file descriptor
         *
         * @param fd file descriptor itself @see BlockProfiler
         * @return bool wether fd is unregistered successfully
         *
         */
        static bool unregister(int32_t fd);

        static std::vector<int32_t> all_fds();

        static int32_t number_of_events_being_monitored();
 
    private:
        static std::unordered_map<int32_t, int32_t> fd__event_count_map;
        static int32_t event_count_being_monitor;

    private:
        PMUEventManager();
        ~PMUEventManager();
};
}
#endif