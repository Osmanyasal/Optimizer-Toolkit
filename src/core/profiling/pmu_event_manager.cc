
#include <pmu_event_manager.hh>

namespace optkit::core
{
    std::unordered_map<int32_t, int32_t> PMUEventManager::fd__event_count_map;
    int32_t PMUEventManager::event_count_being_monitor = 0;

    bool PMUEventManager::register_event(int32_t fd, int32_t num_events){

        // before adding fd, check if fd exists
        if (OPT_UNLIKELY(PMUEventManager::fd__event_count_map.find(fd) != PMUEventManager::fd__event_count_map.end()))
        {
            OPTKIT_CORE_WARN("fd {} already exists", fd);
            return false;
        }
        
        // increment event count
        PMUEventManager::event_count_being_monitor += num_events;

        // before adding fd, check if total event coun exceeds the systems' resources. then print a warning!
        int32_t num_cntrs = Query::default_pmu_info().num_cntrs;
        if (OPT_LIKELY(PMUEventManager::event_count_being_monitor > num_cntrs))
        {
            OPTKIT_CORE_WARN("Total # of events exceed system resources. Multiplexin will take place! {}/{}", PMUEventManager::event_count_being_monitor, num_cntrs);
        }

        // add event
        fd__event_count_map.insert({fd, num_events});
        return true;
    }

    bool PMUEventManager::unregister(int32_t fd){
        fd__event_count_map.erase(fd);
        PMUEventManager::event_count_being_monitor--;
        return true;
    }

    std::vector<int32_t> PMUEventManager::all_fds(){
        std::vector<int32_t> result;
       
        return result;
    }

    int32_t PMUEventManager::number_of_events_being_monitored(){
        return PMUEventManager::event_count_being_monitor;
    }
};