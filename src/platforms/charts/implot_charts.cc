
#include <implot_charts.hh>

namespace optkit::core
{
    void ImplotCharts::bar_groups(int group_member_count,
                                  const std::vector<double> &data,
                                  const std::vector<const char *> &member_labels,
                                  const std::vector<const char *> &group_name,
                                  const std::vector<double> &positions)
    {
        static int groups = group_name.size();
        static float size = 0.67f;
        static int mem_count = group_member_count;
        static bool horz = false;
        static ImPlotBarGroupsFlags flags = 0;

        ImGui::CheckboxFlags("Stacked", (unsigned int *)&flags, ImPlotBarGroupsFlags_Stacked);
        ImGui::SameLine();
        ImGui::Checkbox("Horizontal", &horz);

        ImGui::SliderInt("group_member_count", &mem_count, 1, 3);
        ImGui::SliderFloat("Size", &size, 0, 1);

        if (ImPlot::BeginPlot("##Bar Group",ImVec2{-1,-1}))
        {
            ImPlot::SetupLegend(ImPlotLocation_East, ImPlotLegendFlags_Outside);
            if (horz)
            {
                ImPlot::SetupAxes("Score", "Student", ImPlotAxisFlags_AutoFit, ImPlotAxisFlags_AutoFit);
                ImPlot::SetupAxisTicks(ImAxis_Y1, positions.data(), groups, group_name.data());
                ImPlot::PlotBarGroups(member_labels.data(), data.data(), mem_count, groups, size, 0, flags | ImPlotBarGroupsFlags_Horizontal);
            }
            else
            {
                ImPlot::SetupAxes("Student", "Score", ImPlotAxisFlags_AutoFit, ImPlotAxisFlags_AutoFit);
                ImPlot::SetupAxisTicks(ImAxis_X1, positions.data(), groups, group_name.data());
                ImPlot::PlotBarGroups(member_labels.data(), data.data(), mem_count, groups, size, 0, flags);
            }
            
            ImPlot::EndPlot();
        }
    }
} // namespace optkit::core
