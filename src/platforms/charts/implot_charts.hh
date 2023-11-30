#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__PLATFORMS__IMPLOT_CHARTS_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__PLATFORMS__IMPLOT_CHARTS_HH

#include <implot.h>
#include <cstdint>
#include <vector>
#include <string>

namespace optkit::core
{
    struct BarGroupsMeta
    {
        std::string block_name;
        mutable int group_member_count;
        const std::vector<double> &data;
        const std::vector<const char *> &member_labels;
        const std::vector<const char *> &glables;
        const std::vector<double> &positions;
        mutable float size;
        mutable bool horz;
        mutable ImPlotBarGroupsFlags flags;

        // Constructor
        BarGroupsMeta(
            std::string block_name,
            int group_member_count,
            const std::vector<double> &data,
            const std::vector<const char *> &member_labels,
            const std::vector<const char *> &glables,
            const std::vector<double> &positions,
            float size = 0.67f,
            bool horz = false,
            ImPlotBarGroupsFlags flags = 0) : block_name{block_name}, group_member_count(group_member_count), data(data), member_labels(member_labels),
                                              glables(glables), positions(positions), size(size), horz(horz), flags(flags) {}
    };

    class ImplotCharts
    {
    private:
        ImplotCharts(/* args */);
        ~ImplotCharts();

    public:
        static void bar_groups(const BarGroupsMeta &meta);
    };

} // namespace optkit::core

#endif