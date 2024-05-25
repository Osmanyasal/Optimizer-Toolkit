#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__ICL__ICL_GOVERNOR__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__ICL__ICL_GOVERNOR__HH

#include <vector>
#include <string>
#include <icl.hh>
#include <base_governor.hh>
#include <icl_recepies.hh>

namespace optkit::core::governors::intel::icl
{
    class Governor final : public core::freq::BaseGovernor
    {
    public:
        Governor()
        {
            auto group_leader = block_group_profiler.get_group_leader();
            mmap(NULL, (1 + MMAP_PAGES) * getpagesize(),
                 PROT_READ | PROT_WRITE, MAP_SHARED, group_leader , 0);

            fcntl(group_leader, F_SETFL, O_RDWR | O_NONBLOCK | O_ASYNC);
            fcntl(group_leader, F_SETSIG, SIGIO);
            fcntl(group_leader, F_SETOWN, getpid());
            ioctl(group_leader, PERF_EVENT_IOC_RESET, PERF_IOC_FLAG_GROUP);
        }
        virtual ~Governor() {}

        virtual std::vector<uint64_t> read_pmus() override { return this->block_group_profiler.read_val(); }

    private:
        optkit::core::pmu::BlockGroupProfiler block_group_profiler{"", "", {{optkit::intel::icl::INSTRUCTIONS_RETIRED, "instructions_retired"}}, this->config};
    };
}

#endif