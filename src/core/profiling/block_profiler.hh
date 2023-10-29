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

namespace optkit::core
{
    class BlockProfiler
    {
    public:
        BlockProfiler(const char *block_name, std::initializer_list<uint64_t> raw_event_list);
        virtual ~BlockProfiler();

        virtual void disable();
        virtual void enable();
        virtual std::vector<uint64_t> read_counter();

    public:
        std::vector<int> fd_list;
        const char *block_name;

    private:
        static std::vector<int> fd_stack;
    };
} // namespace optkit::core

#endif