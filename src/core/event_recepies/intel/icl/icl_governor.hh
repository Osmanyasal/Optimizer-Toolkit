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

        OPT_FORCE_INLINE virtual double compute_intensity() override {
            double flops_executed = pmu_record[1];
            double l3_misses = pmu_record[3];
            double compute_intensity = flops_executed / (l3_misses + 1);
            OPTKIT_CORE_INFO("compute intensity = {}", compute_intensity);
            return compute_intensity;
        }

        OPT_FORCE_INLINE virtual double memory_intensity() override
        {
            double total_instructions = pmu_record[0];
            double cache_hits_misses = pmu_record[2];
            double memory_intensity = cache_hits_misses / total_instructions;
            OPTKIT_CORE_INFO("memory intensity ={}", memory_intensity);
            return memory_intensity;
        }

        OPT_FORCE_INLINE virtual double io_intensity() override
        {
            return 0;
        }

    private:
        // cycle watcher gets extended to other cores. we need to fix this to a single core only!!!
        optkit::core::pmu::BlockProfiler core_cycle_watcher;
        optkit::core::pmu::BlockGroupProfiler interested_events;
    };
}

#endif