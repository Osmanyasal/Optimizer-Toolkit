#include <block_profiler.hh>

namespace optkit
{
    std::vector<int> BlockProfiler::fd_stack;

    BlockProfiler::BlockProfiler(const char *event_name, uint64_t raw_event, std::initializer_list<uint64_t> flags)
    {

        // disable all other counters
        for (int i = 0; i < BlockProfiler::fd_stack.size(); i++)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_DISABLE, 0);

        std::size_t sz = flags.size();
        if (OPT_UNLIKELY(sz > 1))
        {
            OPTKIT_CORE_WARN("Flags exceeded the size: {}",sz);
        }
        for (uint64_t flag : flags)
        {
            raw_event = raw_event | flag;
        }

        this->event_name = event_name;
        struct perf_event_attr attr;
        memset(&attr, 0, sizeof(struct perf_event_attr));
        attr.type = PERF_TYPE_RAW;
        attr.config = raw_event;
        attr.size = sizeof(struct perf_event_attr);
        attr.disabled = 1;       // Enable the event later
        attr.inherit = 1;        // Inherit the counter to child processes
        attr.exclude_kernel = 1; // Exclude kernel events
        attr.exclude_hv = 1;
        attr.exclude_idle = 1;
        attr.pinned = 1;

        fd = syscall(__NR_perf_event_open, &attr, 0, -1, -1, 0);
        BlockProfiler::fd_stack.push_back(fd);
        if (fd == -1)
        {
            std::cout << "perf_event_open error" << std::endl;
            return;
        }

        ioctl(fd, PERF_EVENT_IOC_RESET, 0);

        // enable all other counters
        for (int i = BlockProfiler::fd_stack.size() - 1; i >= 0; i--)
        {
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_ENABLE, 0);
        }
    }
    BlockProfiler ::~BlockProfiler()
    {

        // disable all other counters
        for (int i = 0; i < BlockProfiler::fd_stack.size(); i++)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_DISABLE, 0);

        uint64_t count;
        read(fd, &count, sizeof(count));
        std::cout << "Event:" << event_name << " Count: " << count << std::endl;
        close(fd);

        // enable all other counters
        for (int i = BlockProfiler::fd_stack.size() - 1; i >= 0; i--)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_ENABLE, 0);
    }

    void BlockProfiler::disable()
    {
        ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
    }
    void BlockProfiler::enable()
    {
        ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
    }

    uint64_t BlockProfiler::read_counter()
    {
        // disable all other counters
        for (int i = 0; i < BlockProfiler::fd_stack.size(); i++)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_DISABLE, 0);

        uint64_t count;
        read(fd, &count, sizeof(count));

        // enable all other counters
        for (int i = BlockProfiler::fd_stack.size() - 1; i >= 0; i--)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_ENABLE, 0);

        return count;
    }
}