#include <block_group_profiler.hh>

namespace optkit::core
{

    BlockGroupProfiler::BlockGroupProfiler(const char *block_name, std::vector<uint64_t> raw_event_list, const ProfilerConfig &config) : profiler_config{config}, block_name{block_name}, group_leader{-1}, is_active{true}
    {

        PMUEventManager::disable_all_events();

        if (raw_event_list.size() > PMUEventManager::pmu_event_size())
        {
            this->is_active = false;
            OPTKIT_CORE_ERROR("Cannot create a blockgroup for block {} by monitoring more than pmu hardware event size {}|{}(max).",this->block_name, raw_event_list.size(), PMUEventManager::pmu_event_size());
            OPTKIT_CORE_WARN("Consider dividing the BlockGroupProfiler for block {} into multiple sub-groups!", this->block_name);
            return;
        }

        for (auto &raw_event : raw_event_list)
        {
            perf_event_attr attr = this->profiler_config.perf_event_config;
            attr.config = raw_event;

            int32_t fd = syscall(__NR_perf_event_open, &attr, this->profiler_config.pid, this->profiler_config.cpu, group_leader, 0); // <-- first becomes -1 and later we use the group_leader's fd.
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

        if (OPT_UNLIKELY(!is_active))
        {
            OPTKIT_CORE_WARN("BlockGroupProfiler for block {} is not active!",this->block_name);
            return;
        }

        // disable clock now!
        auto end = std::chrono::high_resolution_clock::now();
        auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0f;

        std::string buf;
        buf.resize(4096);
        const read_format *rf = reinterpret_cast<const read_format *>(buf.data());
        ::read(group_leader, const_cast<char *>(buf.data()), buf.size());
        ::close(group_leader);
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
        if (OPT_UNLIKELY(!is_active))
        {
            OPTKIT_CORE_WARN("BlockGroupProfiler for block {} is not active!", this->block_name);
        }

        ioctl(group_leader, PERF_EVENT_IOC_DISABLE, PERF_IOC_FLAG_GROUP);
    }
    void BlockGroupProfiler::enable()
    {
        if (OPT_UNLIKELY(!is_active))
        {
            OPTKIT_CORE_WARN("BlockGroupProfiler for block {} is not active!", this->block_name);
        }

        ioctl(group_leader, PERF_EVENT_IOC_ENABLE, PERF_IOC_FLAG_GROUP);
    }

    std::vector<uint64_t> BlockGroupProfiler::read()
    {

        PMUEventManager::disable_all_events();

        std::vector<uint64_t> result;
        if (OPT_UNLIKELY(!is_active))
        {
            OPTKIT_CORE_WARN("BlockGroupProfiler for block {} is not active!", this->block_name);
            return result;
        }

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