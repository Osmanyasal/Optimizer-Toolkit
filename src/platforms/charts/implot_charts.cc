
#include <implot_charts.hh>

namespace optkit::core
{
    void ImplotCharts::bar_groups(const BarGroupsMeta &meta)
    {
        ImGui::CheckboxFlags("Stacked", (unsigned int *)&meta.flags, ImPlotBarGroupsFlags_Stacked);
        ImGui::SameLine();
        ImGui::Checkbox("Horizontal", &meta.horz);

        ImGui::SliderInt("group_member_count", &meta.group_member_count, 1, 3);
        ImGui::SliderFloat("Size", &meta.size, 0, 1);

        if (ImPlot::BeginPlot("##Bar Group",ImVec2{-1,-1}))
        {
            ImPlot::SetupLegend(ImPlotLocation_East, ImPlotLegendFlags_Outside);
            if (meta.horz)
            {
                ImPlot::SetupAxes("Score", "Student", ImPlotAxisFlags_AutoFit, ImPlotAxisFlags_AutoFit);
                ImPlot::SetupAxisTicks(ImAxis_Y1, meta.positions.data(), meta.glables.size(), meta.glables.data());
                ImPlot::PlotBarGroups(meta.member_labels.data(), meta.data.data(), meta.group_member_count, meta.glables.size(), meta.size, 0, meta.flags | ImPlotBarGroupsFlags_Horizontal);
            }
            else
            {
                ImPlot::SetupAxes("Student", "Score", ImPlotAxisFlags_AutoFit, ImPlotAxisFlags_AutoFit);
                ImPlot::SetupAxisTicks(ImAxis_X1, meta.positions.data(), meta.glables.size(), meta.glables.data());
                ImPlot::PlotBarGroups(meta.member_labels.data(), meta.data.data(), meta.group_member_count, meta.glables.size(), meta.size, 0, meta.flags);
            }
            
            ImPlot::EndPlot();
        }
    }
} // namespace optkit::core
