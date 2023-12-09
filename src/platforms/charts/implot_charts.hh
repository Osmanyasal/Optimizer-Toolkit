#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__PLATFORMS__IMPLOT_CHARTS_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__PLATFORMS__IMPLOT_CHARTS_HH

#include <gui_config.hh>
#include <implot.h>
#include <implot_internal.h>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include <rapl.hh>
#include <query.hh>

namespace optkit::core
{
    struct BarGroupsMeta
    {
        // Static utils

        static BarGroupsMeta convert(const std::string &file_name, std::vector<std::pair<double, std::map<int32_t, std::map<optkit::core::RaplDomain, double>>>> data);

        // Constructor
        BarGroupsMeta(
            const std::string &x_axis_name,
            const std::string &y_left__axis_name,
            const std::string &y_right__axis_name,
            const std::string &block_name,
            int group_member_count,
            const std::vector<double> &data,
            const std::vector<std::string> &member_labels,
            const std::vector<std::string> &glables,
            const std::vector<double> &positions,
            float size = 0.67f,
            bool horz = false,
            ImPlotBarGroupsFlags flags = 0,
            bool show_tooltip = true,
            bool show_annotations = true) : x_axis_name{x_axis_name}, y_left__axis_name{y_left__axis_name}, y_right__axis_name{y_right__axis_name}, block_name{block_name}, group_member_count(group_member_count), data(data), member_labels(member_labels),
                                             glables(glables), positions(positions), size(size), horz(horz), flags(flags), inital_member_count{group_member_count}, show_tooltip{show_tooltip}, show_annotations{show_annotations}
        {
        }
        std::string x_axis_name;
        std::string y_left__axis_name;
        std::string y_right__axis_name;
        std::string block_name;
        mutable int group_member_count;
        std::vector<double> data;
        std::vector<std::string> member_labels;
        std::vector<std::string> glables;
        std::vector<double> positions;
        mutable float size;
        mutable bool clamp;
        mutable bool horz;
        mutable ImPlotBarGroupsFlags flags;

        int32_t inital_member_count;
        mutable bool show_tooltip;
        mutable bool show_annotations;
    };

    class ImplotCharts
    {
    private:
        ImplotCharts(/* args */);
        ~ImplotCharts();

    public:
        static void bar_groups(const BarGroupsMeta &meta);
        static optkit::core::BarGroupsMeta example_bar_group();
    };

} // namespace optkit::core

#endif