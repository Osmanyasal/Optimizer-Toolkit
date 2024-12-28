#include "core/event_recepies/tmanalysis.hh"

namespace optkit::core::recepies
{
    TMAnalysis::TMAnalysis(const char *block_name, const char *event_name, bool verbose, const ProfilerConfig &config) : block_name{block_name}, event_name{event_name}, verbose{verbose}, config{config}
    {
        start_time = __rdtsc();
    }
    void TMAnalysis::begin_monitoring(L1Metric metric)
    {
        switch (metric)
        {
        case L1Metric::Default:
            recipie_to_monitor = L1__default__recipie();
            break;

        case L1Metric::IPC:
            recipie_to_monitor = L1__default__recipie();
            break;

        case L1Metric::BackendBound:
        {
            recipie_to_monitor = L2__backend__core();
            auto temp = L2__backend__memory();
            recipie_to_monitor.insert(recipie_to_monitor.end(), temp.begin(), temp.end());
            break;
        }

        case L1Metric::BadSpeculation:
            recipie_to_monitor = L2__bad_speculation__branch_mispredict();
            break;

        case L1Metric::Retiring:
        {
            recipie_to_monitor = L2__retiring__base();
            auto temp = L2__retiring__micro_sequencer();
            recipie_to_monitor.insert(recipie_to_monitor.end(), temp.begin(), temp.end());
            break;
        }
        case L1Metric::FrontendBound:
        {
            recipie_to_monitor = L2__frontend__fetch_bandwidth();
            auto temp = L2__frontend__fetch_latency();
            recipie_to_monitor.insert(recipie_to_monitor.end(), temp.begin(), temp.end());
            break;
        }
        default:
            recipie_to_monitor = L1__default__recipie();
            break;
        }

        choose_profiler();
    }
    void TMAnalysis::begin_monitoring(L2Metric metric)
    {
        switch (metric)
        {
        case L2Metric::Default:
            recipie_to_monitor = L2__default__recipie();
            break;

        case L2Metric::MemoryBound:
        {
            recipie_to_monitor = L3__memory__ext_memory();
            auto l1 = L3__memory__l1();
            auto l2 = L3__memory__l2();
            auto l3 = L3__memory__l3();

            recipie_to_monitor.insert(recipie_to_monitor.end(), l1.begin(), l1.end());
            recipie_to_monitor.insert(recipie_to_monitor.end(), l2.begin(), l2.end());
            recipie_to_monitor.insert(recipie_to_monitor.end(), l3.begin(), l3.end());
            break;
        }

        case L2Metric::CoreBound:
            break;

        case L2Metric::Base:
            break;

        case L2Metric::FetchLatency:
            break;

        case L2Metric::FetchBandwidth:
            break;

        default:
            recipie_to_monitor = L2__default__recipie();
            break;
        }

        choose_profiler();
    }

    void TMAnalysis::begin_monitoring(L3Metric metric)
    {

        choose_profiler();
    }

    void TMAnalysis::choose_profiler()
    {
        int32_t num_cntrs = core::pmu::QueryPMU::default_pmu_info().num_cntrs;
        if (OPT_UNLIKELY(core::pmu::PMUEventManager::number_of_events_being_monitored() + recipie_to_monitor.size() > num_cntrs))
        {
            OPTKIT_CORE_INFO("TMA chose block profiler");
            config.is_grouped = false;
            profiler_ref = std::make_unique<core::pmu::BlockProfiler>(block_name, event_name, recipie_to_monitor, true, config);
        }
        else
        {
            OPTKIT_CORE_INFO("TMA chose group profiler");
            config.is_grouped = true;
            profiler_ref = std::make_unique<core::pmu::BlockGroupProfiler>(block_name, event_name, recipie_to_monitor, true, config);
        }
    }

    TMAnalysis::~TMAnalysis()
    {
        delta_time = __rdtsc() - start_time;
    }

    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L1__default__recipie()
    {
        static std::vector<std::pair<uint64_t, std::string>> default_mapping{
            {0x3c, "CPU_CLK_UNHALTED"},                                               // 0
            {(0x9c | 0x100), "IDQ_UOPS_NOT_DELIVERED"},                               // 1
            {(0xe | 0x100), "UOPS_ISSUED_ANY"},                                       // 2
            {(0xc2 | 0x200), "UOPS_RETIRED_RETIRE_SLOTS"},                            // 3
            {(0xd | 0x300 | (1 << INTEL_X86_CMASK_BIT)), "INT_MISC_RECOVERY_CYCLES"}, // 4
            {0xc0, "INSTRUCTION_RETIRED"}};                                           // 5

        // be_bound = 1 - (fe_bound + bad_speculation + retiring)

        return default_mapping;
    }

    std::map<L1Metric, double> TMAnalysis::L1__analise()
    {
        const std::vector<uint64_t> &pmu_record = profiler_ref->read_val();
        std::map<L1Metric, double> result;

        double SLOTS = 4 * pmu_record[0];

        result[L1Metric::CPU_UTIL] = (double)pmu_record[0] / delta_time;
        result[L1Metric::IPC] = ((double)pmu_record[5] / pmu_record[0]);
        result[L1Metric::FrontendBound] = (pmu_record[1] / SLOTS) * 100.0;                                        // IDQ_UOPS_NOT_DELIVERED.CORE / Slots
        result[L1Metric::Retiring] = (pmu_record[3] / SLOTS) * 100.0;                                             // UOPS_RETIRED.RETIRE_SLOTS / Slots
        result[L1Metric::BadSpeculation] = ((pmu_record[2] - pmu_record[3] + 4 * pmu_record[4]) / SLOTS) * 100.0; // (UOPS_ISSUED.ANY - UOPS_RETIRED.RETIRE_SLOTS + 4* INT_MISC.RECOVERY_CYCLES) / Slots
        result[L1Metric::BackendBound] = (100 - (result[L1Metric::FrontendBound] +
                                                 result[L1Metric::BadSpeculation] +
                                                 result[L1Metric::Retiring])); // 1 – (Frontend Bound + Bad Speculation + Retiring)

        return result;
    }

    // TODO: Rephrase this for l2
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__default__recipie()
    {
        static std::vector<std::pair<uint64_t, std::string>> default_mapping{
            {0x3c, "CPU_CLK_UNHALTED"},                                               // 0
            {(0x9c | 0x100), "IDQ_UOPS_NOT_DELIVERED"},                               // 1
            {(0xe | 0x100), "UOPS_ISSUED_ANY"},                                       // 2
            {(0xc2 | 0x200), "UOPS_RETIRED_RETIRE_SLOTS"},                            // 3
            {(0xd | 0x300 | (1 << INTEL_X86_CMASK_BIT)), "INT_MISC_RECOVERY_CYCLES"}, // 4
            {0xc0, "INSTRUCTION_RETIRED"}};                                           // 5

        // be_bound = 1 - (fe_bound + bad_speculation + retiring)

        return default_mapping;
    }

    std::map<L1Metric, double> TMAnalysis::L2__analise()
    {
        const std::vector<uint64_t> &pmu_record = profiler_ref->read_val();
        std::map<L1Metric, double> result;

        return result;
    }

    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__backend__core() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__backend__memory() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__bad_speculation__branch_mispredict() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__frontend__fetch_bandwidth() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__frontend__fetch_latency() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__retiring__base() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L2__retiring__micro_sequencer() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L3__memory__ext_memory() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L3__memory__l1() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L3__memory__l2() {};
    std::vector<std::pair<uint64_t, std::string>> TMAnalysis::L3__memory__l3() {};

} // namespace optkit::core::recepies
