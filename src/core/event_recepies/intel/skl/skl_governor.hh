#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__SKL__SKL_GOVERNOR__HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__EVENT_RECEPIES__INTEL__SKL__SKL_GOVERNOR__HH

#include <vector>
#include <string>
#include <skl.hh>
#include <base_governor.hh>
#include <skl_recepies.hh>

namespace optkit::core::governors::intel::skl
{
    class Governor final : public core::freq::BaseGovernor
    {
    public:
        Governor();
        virtual ~Governor() { BaseGovernor::current_governor = nullptr; }
        virtual void snapshot_pmus() override { this->pmu_record = interested_events.read_val(); }

        OPT_FORCE_INLINE virtual double compute_intensity() override
        {
            double flops_executed = pmu_record[1];
            double l3_misses = pmu_record[3];
            double compute_intensity = flops_executed / (l3_misses + 1);
            return compute_intensity;
        }

        OPT_FORCE_INLINE virtual double memory_intensity() override
        {
            double total_instructions = pmu_record[0];
            double cache_hits_misses = pmu_record[2];
            double memory_intensity = cache_hits_misses / total_instructions;
            return memory_intensity;
        }

        OPT_FORCE_INLINE void disalbe_callback_trigger() override
        {
            core_cycle_watcher.disable();
            interested_events.disable();
        }
        OPT_FORCE_INLINE void enable_callback_trigger() override
        {
            core_cycle_watcher.enable();
            interested_events.enable();
        }

    private:
        optkit::core::pmu::BlockProfiler core_cycle_watcher;
        optkit::core::pmu::BlockGroupProfiler interested_events;
    };
}

#endif