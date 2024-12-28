#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <iomanip>
#include <x86intrin.h>
#include <memory>
#include "intel_priv.hh"
#include "utils/utils.hh"
#include "core/profiling/pmu/pmu_event_manager.hh"
#include "core/freq/query_frequency.hh"
#include "core/event_recepies/tma_metrics.hh"
#include "core/profiling/pmu/block_group_profiler.hh"
#include "core/profiling/pmu/block_profiler.hh"

namespace optkit::core::recepies
{
    class TMAnalysis
    {
 
    public:
        TMAnalysis(const char *block_name, const char *event_name, bool verbose = true, const ProfilerConfig &config = ProfilerConfig{false, true, false, 0, -1});
        void begin_monitoring(L1Metric metric);
        void begin_monitoring(L2Metric metric);
        void begin_monitoring(L3Metric metric);
        virtual ~TMAnalysis();

    protected:
        virtual std::map<L1Metric, double> L1__analise();
        virtual std::map<L1Metric, double> L2__analise();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L1__default__recipie();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L2__default__recipie();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L2__backend__memory();

        /**
        //  * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
        //  *
        //  * @return std::vector<std::pair<uint64_t, std::string>>
        //  */
        virtual std::vector<std::pair<uint64_t, std::string>> L2__backend__core();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L2__retiring__base();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L2__retiring__micro_sequencer();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L2__bad_speculation__branch_mispredict();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L2__frontend__fetch_latency();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L2__frontend__fetch_bandwidth();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L3__memory__ext_memory();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L3__memory__l1();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L3__memory__l2();

        /**
         * @brief Returns the default set of events for most Intel architectures. To customize for your specific architecture, check the /src/core/events/intel/ directory and override this method as needed.
         *
         * @return std::vector<std::pair<uint64_t, std::string>>
         */
        virtual std::vector<std::pair<uint64_t, std::string>> L3__memory__l3();

        virtual void choose_profiler() final;

    private:
        uint64_t start_time;
        uint64_t delta_time;
        
        std::unique_ptr<core::BaseProfiler<std::vector<uint64_t>>> profiler_ref;
        std::vector<std::pair<uint64_t, std::string>> recipie_to_monitor;

        const char *block_name;
        const char *event_name;
        bool verbose;
        ProfilerConfig profiler_config;
    };

} // namespace optkit::core::recepies
