#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BLOCK_PROFILER
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BLOCK_PROFILER

#include <iostream>
#include <linux/perf_event.h>
#include <sys/ioctl.h>
#include <cstdint>
#include <sys/syscall.h>
#include <initializer_list>
#include <vector>
#include <utils.hh>
namespace optkit::core
{
    /**
     * @brief The BlockGroupProfiler class utilizes the RAII technique to initiate and conclude profiling for a specific raw event.
     *        Profiling commences upon instantiation and persists until the current scope is exited.
     *
     *        Note that block profiler DOES group raw_events! If you to monitor each event standalone please BlockProfiler
     *
     *        Each raw_event creates seperate file_description (fd) to read data and each raw_event is treated seperately.<br>
     *        In cases where CPU performs multiplexing and since each event treated seperately, you cannot gurantee that <br>
     *        events E1 and E2 will record the same instructions.<br>
     *        for more information about grouping @see https://man7.org/linux/man-pages/man2/perf_event_open.2.html
     */
    class BlockGroupProfiler
    {
    public:
        BlockGroupProfiler(const char *block_name, std::initializer_list<uint64_t> raw_event_list);
        virtual ~BlockGroupProfiler();

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