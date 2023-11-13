#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BLOCK_PROFILER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BLOCK_PROFILER_HH

#include <iostream>
#include <initializer_list>
#include <vector>
#include <utils.hh>
#include <pmu_event_manager.hh>

namespace optkit::core
{
    /**
     * @brief The BlockProfiler class utilizes the RAII technique to initiate and conclude profiling for a specific raw event.
     *        Profiling commences upon instantiation and persists until the current scope is exited.
     *
     *        Note that block profiler does NOT group raw_events! If you want that ability please BlockGroupProfiler
     *
     *        Each raw_event creates seperate file_description (fd) to read data and each raw_event is treated seperately.<br>
     *        In cases where CPU performs multiplexing and since each event treated seperately, you cannot gurantee that <br>
     *        events E1 and E2 will record the same instructions.<br>
     *        for more information about grouping @see https://man7.org/linux/man-pages/man2/perf_event_open.2.html
     */
    class BlockProfiler 
    {
    public:
        BlockProfiler(const char *block_name, std::initializer_list<uint64_t> raw_event_list);
        virtual ~BlockProfiler();

        virtual void disable();
        virtual void enable();
        virtual std::vector<uint64_t> read_counter();

    public:
        /**
         * @brief fd_list holds pmu events being monitor by this BlockProfiler Object.
         * when created the same file description must be registered global fd_stack
         * 
         */
        std::vector<int32_t> fd_list;

        /**
         * @brief Used for identification of blocks and chart titles
         * 
         */
        const char *block_name;

    private:
        std::chrono::high_resolution_clock::time_point start;
    };
} // namespace optkit::core

#endif