#pragma once
#include <iostream>
#include <linux/perf_event.h>
#include <perfmon/pfmlib.h>
#include <sys/ioctl.h>
#include <cstdint>
#include <cstring>
#include <asm/unistd.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdint>
#include <vector>

class BlockProfiler
{
public:
    inline BlockProfiler(const char *event_name, uint64_t raw_event) __attribute__((always_inline))
    {
        // disable all other counters
        for (std::size_t i = 0; i < BlockProfiler::fd_stack.size(); i++)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_DISABLE, 0);

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

        fd = syscall(__NR_perf_event_open, &attr, 0, -1, -1, 0);
        BlockProfiler::fd_stack.push_back(fd);
        if (fd == -1)
        {
            std::cout << "perf_event_open error" << std::endl;
            return;
        }

        ioctl(fd, PERF_EVENT_IOC_RESET, 0);

        // enable all other counters
        for (std::size_t i = BlockProfiler::fd_stack.size(); i > -1; i--)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_ENABLE, 0);
    }
    inline virtual ~BlockProfiler() final __attribute__((always_inline))
    {
        // disable all other counters
        for (std::size_t i = 0; i < BlockProfiler::fd_stack.size(); i++)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_DISABLE, 0);

        uint64_t count;
        read(fd, &count, sizeof(count));
        std::cout << "Event:" << event_name << " Count: " << count << std::endl;
        close(fd);

        // enable all other counters
        for (std::size_t i = BlockProfiler::fd_stack.size(); i > -1; i--)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_ENABLE, 0);
    }

    inline void disable() __attribute__((always_inline))
    {
        ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
    }
    inline void enable() __attribute__((always_inline))
    {
        ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
    }

    inline uint64_t read_counter() __attribute__((always_inline))
    {
        // disable all other counters
        for (std::size_t i = 0; i < BlockProfiler::fd_stack.size(); i++)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_DISABLE, 0);

        uint64_t count;
        read(fd, &count, sizeof(count));

        // enable all other counters
        for (std::size_t i = BlockProfiler::fd_stack.size(); i > -1; i--)
            ioctl(BlockProfiler::fd_stack[i], PERF_EVENT_IOC_ENABLE, 0);
            
        return count;
    }

public:
    int fd;
    const char *event_name;

private:
    static std::vector<int> fd_stack;
};

std::vector<int> BlockProfiler::fd_stack;