#include <block_profiler.hh>

namespace optkit::core
{ 

    BlockProfiler::BlockProfiler(const char *block_name, std::initializer_list<uint64_t> raw_event_list)
    {

        PMUEventManager::disable_all_events();

        this->block_name = block_name;
        for (auto &raw_event : raw_event_list)
        {
            struct perf_event_attr attr;
            std::memset(&attr, 0, sizeof(struct perf_event_attr));
            attr.type = PERF_TYPE_RAW;
            attr.config = raw_event;
            attr.size = sizeof(struct perf_event_attr);
            attr.disabled = 1;       // Enable the event later
            attr.inherit = 1;        // Inherit the counter to child processes
            attr.exclude_kernel = 1; // Exclude kernel events
            attr.exclude_hv = 1;
            // attr.read_format = PERF_FORMAT_GROUP | PERF_FORMAT_ID;

            int32_t fd = syscall(__NR_perf_event_open, &attr, 0, -1, -1, 0); // <-- first becomes -1 and later we use the group_leader's fd.
            if (fd == -1)
            {
                std::cout << "perf_event_open error" << std::endl;
                return;
            }
            else
            {
                PMUEventManager::register_event(fd, 1);
                fd_list.push_back(fd);
            }
            ioctl(fd, PERF_EVENT_IOC_RESET, 0);
        }
        // enable clock now!
        start = std::chrono::high_resolution_clock::now();

        PMUEventManager::enable_all_events();
    }
    BlockProfiler ::~BlockProfiler()
    {

        PMUEventManager::disable_all_events();

        // disable clock now!
        auto end = std::chrono::high_resolution_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0f;

        uint64_t count;
        for (int32_t fd : fd_list)
        {
            read(fd, &count, sizeof(count)); // read last value 
            PMUEventManager::unregister_event(fd); // unregister this event
            std::cout << "\033[1;35m" << "Block: " << this->block_name << "\033[0m" << " [" << duration_ms << "ms] " << "Measured: " << count << std::endl;
        }

        PMUEventManager::enable_all_events();
    }

    void BlockProfiler::disable()
    {
        for (int32_t fd : fd_list)
        {
            ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
        }
    }
    void BlockProfiler::enable()
    {
        for (int32_t fd : fd_list)
        {
            ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
        }
    }

    std::vector<uint64_t> BlockProfiler::read_counter()
    {

        PMUEventManager::disable_all_events();

        std::vector<uint64_t> result;
        uint64_t count;
        for (int32_t fd : fd_list)
        {
            read(fd, &count, sizeof(count));
            result.push_back(count);
        }

        PMUEventManager::enable_all_events();

        return result;
    }
} // namespace optkit::core