#include <block_group_profiler.hh>

namespace optkit::core
{

    BlockGroupProfiler::BlockGroupProfiler(const char *block_name, std::vector<uint64_t> raw_event_list, ProfilerConfig config) : BaseProfiler{config}, block_name{block_name}, group_leader{-1}
    {

        PMUEventManager::disable_all_events();
        for (auto &raw_event : raw_event_list)
        {
            perf_event_attr attr = this->config.perf_event_config;
            attr.config = raw_event;

            int32_t fd = syscall(__NR_perf_event_open, &attr, config.pid, config.cpu, group_leader, 0); // <-- first becomes -1 and later we use the group_leader's fd.
            if (fd == -1)
            {
                OPTKIT_CORE_ERROR("perf_event_open error");
                return;
            }
            else
            {
                if (group_leader == -1)
                {
                    group_leader = fd;
                    PMUEventManager::register_event(group_leader, raw_event_list.size());
                }
            }
        }
 
        ioctl(group_leader, PERF_EVENT_IOC_RESET, PERF_IOC_FLAG_GROUP);
        // enable clock now!
        start = std::chrono::high_resolution_clock::now();

        PMUEventManager::enable_all_events();
    }
    BlockGroupProfiler ::~BlockGroupProfiler()
    {

        PMUEventManager::disable_all_events();

        // disable clock now!
        auto end = std::chrono::high_resolution_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0f;

        char buf[4096];
        read_format *rf = (read_format *)buf;
        ::read(group_leader, buf, sizeof(buf));
        for (int i = 0; i < rf->nr; i++)
        {
            std::cout << "\033[1;35m"
                      << "Block: " << this->block_name << "\033[0m"
                      << " [" << duration_ms << "ms] "
                      << "Measured: " << rf->values[i].value << std::endl;
        }

        PMUEventManager::enable_all_events();
    }

    void BlockGroupProfiler::disable()
    {
        ioctl(group_leader, PERF_EVENT_IOC_DISABLE, PERF_IOC_FLAG_GROUP);
    }
    void BlockGroupProfiler::enable()
    {
        ioctl(group_leader, PERF_EVENT_IOC_ENABLE, PERF_IOC_FLAG_GROUP);
    }

    std::vector<uint64_t> BlockGroupProfiler::read()
    {

        PMUEventManager::disable_all_events();

        std::vector<uint64_t> result;

        char buf[4096];
        struct read_format *rf = (struct read_format *)buf;
        ::read(group_leader, buf, sizeof(buf));
        for (int i = 0; i < rf->nr; i++)
        {
            result.push_back(rf->values[i].value);
        }

        PMUEventManager::enable_all_events();

        return result;
    }
} // namespace optkit::core