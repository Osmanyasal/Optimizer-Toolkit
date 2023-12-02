
#include <implot_charts.hh>

namespace optkit::core
{
    void ImplotCharts::bar_groups(const BarGroupsMeta &meta)
    {

        ImGui::SetWindowFontScale(1.2f);
        ImGui::SeparatorText(meta.block_name.c_str());
        ImGui::SetWindowFontScale(1.0f);

        ImGui::CheckboxFlags("Stacked", (unsigned int *)&meta.flags, ImPlotBarGroupsFlags_Stacked);
        ImGui::SameLine();
        ImGui::Checkbox("Horizontal", &meta.horz);

        ImGui::SliderInt("Group Member Count", &meta.group_member_count, 1, 3);
        ImGui::SliderFloat("Size", &meta.size, 0, 1);

        if (ImPlot::BeginPlot("##Bar Group", ImVec2{-1, -1}))
        {
            ImPlot::SetupLegend(ImPlotLocation_East, ImPlotLegendFlags_Outside);
            ImPlot::SetupAxes("Student", "Score");
            ImPlot::SetupAxisTicks(ImAxis_X1, meta.positions.data(), meta.glables.size(), meta.glables.data());
            
            if (meta.horz)
                ImPlot::PlotBarGroups(meta.member_labels.data(), meta.data.data(), meta.group_member_count, meta.glables.size(), meta.size, 0, meta.flags | ImPlotBarGroupsFlags_Horizontal);
            else
                ImPlot::PlotBarGroups(meta.member_labels.data(), meta.data.data(), meta.group_member_count, meta.glables.size(), meta.size, 0, meta.flags);

            ImPlot::EndPlot();
        }
    }
} // namespace optkit::core
