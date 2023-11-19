#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__PLATFORMS__IMPLOT_CHARTS_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__PLATFORMS__IMPLOT_CHARTS_HH

#include <implot.h>
#include <cstdint>
#include <vector>
#include <string>

namespace optkit::core
{
    class ImplotCharts
    {
    private:
        ImplotCharts(/* args */);
        ~ImplotCharts();

    public:
        static void bar_groups(int group_member_count,
                               const std::vector<double> &data,
                               const std::vector<const char *> &member_labels,
                               const std::vector<const char *> &glables,
                               const std::vector<double> &positions);
    };

} // namespace optkit::core

#endif