#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__PMU__BLOCK_GROUP_PROFILER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__PMU__BLOCK_GROUP_PROFILER_HH

#include <iostream>
#include <initializer_list>
#include <vector>
#include <utils.hh>
#include <pmu_event_manager.hh>
#include <base_profiler.hh>

namespace optkit::core
{
    /**
     * @brief The BlockGroupProfiler class utilizes the RAII technique to initiate and conclude profiling for a specific raw event.
     *        Profiling commences upon instantiation and persists until the current scope is exited.
     *
     *        Note that block profiler DOES group raw_events!
     *
     *        for more information about grouping @see https://man7.org/linux/man-pages/man2/perf_event_open.2.html
     */
    class BlockGroupProfiler : public BaseProfiler<std::vector<uint64_t>>
    {

    public:
        BlockGroupProfiler(const char *block_name, std::vector<uint64_t> raw_event_list, const ProfilerConfig &config = ProfilerConfig{true, true});
        virtual ~BlockGroupProfiler();
        /**
         * @brief Disables this block profiler and associated events
         *
         */
        virtual void disable() override;

        /**
         * @brief Enables this block profiler and associated events
         *
         */
        virtual void enable() override;

        /**
         * @brief  converts buffer to json
         *
         */
        virtual std::string convert_buffer_to_json() override;

        /**
         * @brief Reads the values of all raw_events.
         *
         * @return std::vector<uint64_t> contains each raw_events' pmu data.
         */
        virtual std::vector<uint64_t> read_val() override;

    private:
        int32_t group_leader;
        std::chrono::high_resolution_clock::time_point start;
        bool is_active;
        ProfilerConfig profiler_config;

        struct read_format
        {
            uint64_t nr;
            struct
            {
                uint64_t value;
                uint64_t id;
            } values[];
        };
    };

} // namespace optkit::core

#endif