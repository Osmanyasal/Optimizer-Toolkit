#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__BASE_GOVERNOR_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__FREQ__BASE_GOVERNOR_HH

#include <signal.h>
#include <fcntl.h>
#include <sys/ptrace.h>
#include <sys/mman.h>
#include <profiler_config.hh>
#include <block_group_profiler.hh>
#include <block_profiler.hh>
#include <query_frequency.hh>
#include <iostream>

#define MMAP_PAGES 8

namespace optkit::core::freq
{
    class BaseGovernor
    {
    public:
        // this will be called when sample period exceeds
        static void call_back(int signum, siginfo_t *oh, void *blah);

    public:
        BaseGovernor(long sample_period = QueryFreq::get_scaling_max_limit() * 10); // callback at each 10ms
        virtual ~BaseGovernor();
        virtual std::vector<uint64_t> read_pmus() = 0;
        

    protected:
        optkit::core::ProfilerConfig config{false, true, false, 0, -1};
        long sample_period;
        struct sigaction sa;
        void *our_mmap;
    };
}

#endif