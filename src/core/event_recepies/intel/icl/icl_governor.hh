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
        Governor();
        virtual ~Governor() {}
        virtual void snapshot_pmus() override { this->pmu_record = interested_events.read_val(); }

        virtual double computational_intensity() override {
            double flops_executed = pmu_record[1];
            double total_l3_misses = pmu_record[3];

            OPTKIT_CORE_INFO("compute_Intensity = # flops {} -- # l3 miss {}", flops_executed, total_l3_misses);
            return flops_executed / total_l3_misses;
        }

        virtual double cache_intensity() override {
            double total_l1_l2_hits_misses_l3_hits = pmu_record[2];
            double total_instructions = pmu_record[0];

            OPTKIT_CORE_INFO("cache_I = # instructions {} -- # l1_l2_hits_misses_l3_hits {}", total_instructions, total_l1_l2_hits_misses_l3_hits);
            return total_l1_l2_hits_misses_l3_hits / total_instructions;
        }

        virtual double dram_intensity() override {
            double total_instructions = pmu_record[0];
            double total_l3_misses = pmu_record[2];

            OPTKIT_CORE_INFO("dram_I = # instructions {} -- # l3 miss {}", total_instructions, total_l3_misses);
            return total_l3_misses / total_instructions;
        }
        
        virtual double io_intensity() override {
            return 0;
        }

    private:
        optkit::core::pmu::BlockProfiler core_cycle_watcher;
        optkit::core::pmu::BlockGroupProfiler interested_events;
    };
}

#endif