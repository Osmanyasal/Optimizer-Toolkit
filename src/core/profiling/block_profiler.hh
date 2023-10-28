#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BLOCK_PROFILER
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BLOCK_PROFILER

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
#include <initializer_list>
#include <vector>
#include <utils.hh>

namespace optkit
{
    class BlockProfiler
    {
    public:
        BlockProfiler(const char *event_name, uint64_t raw_event, std::initializer_list<uint64_t> flags = {});
        virtual ~BlockProfiler() final;

        void disable();
        void enable();
        uint64_t read_counter();

    public:
        int fd;
        const char *event_name;

    private:
        static std::vector<int> fd_stack;
    };
} // namespace optkit

#endif