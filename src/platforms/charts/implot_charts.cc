
#include <implot_charts.hh>

namespace optkit::core
{

    void ImplotCharts::bar_groups(const BarGroupsMeta &meta)
    {

        ImGui::SetWindowFontScale(1.2f);
        ImGui::SeparatorText(meta.block_name.c_str());
        ImGui::SetWindowFontScale(1.0f);
        ImGui::Checkbox("Clamp", &meta.clamp);
        ImGui::SameLine();
        ImGui::CheckboxFlags("Stacked", (unsigned int *)&meta.flags, ImPlotBarGroupsFlags_Stacked);
        ImGui::SameLine();
        ImGui::Checkbox("Horizontal", &meta.horz);
        ImGui::SameLine();
        ImGui::Checkbox("Show Tooltip", &meta.show_tooltip);
        ImGui::SameLine();
        ImGui::Checkbox("Show Annotations", &meta.show_annotations);

        ImGui::SliderInt("Group Member Count", &meta.group_member_count, 1, meta.inital_member_count);
        ImGui::SliderFloat("Size", &meta.size, 0, 1);

        std::vector<const char *> _glables;
        std::vector<const char *> _member_labels;

        for (auto &&i : meta.glables)
            _glables.push_back(i.c_str());

        for (auto &&i : meta.member_labels)
            _member_labels.push_back(i.c_str());

        if (ImPlot::BeginPlot("##Bar Group", ImVec2{-1, -1}))
        {
            ImPlot::SetupLegend(ImPlotLocation_East, ImPlotLegendFlags_Outside);
            ImPlot::SetupAxes(meta.x_axis_name.c_str(), meta.y_left__axis_name.c_str());
            ImPlot::SetupAxisTicks(ImAxis_X1, meta.positions.data(), _glables.size(), _glables.data());

            // Add annotations to each bar
            if (meta.show_tooltip || meta.show_annotations)
                for (int i = 0; i < meta.glables.size(); ++i)
                {
                    for (int j = 0; j < meta.group_member_count; ++j)
                    {
                        float totalGroupWidth = meta.size;
                        float individualColumnWidth = totalGroupWidth / meta.group_member_count;
                        float xCoord;

                        if (meta.group_member_count == 1)
                            xCoord = i;

                        else if (meta.group_member_count % 2 == 1)
                            // xCoord = i + ((j - meta.group_member_count / 3.0f) * individualColumnWidth);
                            xCoord = i - individualColumnWidth * (meta.group_member_count / 2) + (2 * j) * (individualColumnWidth / 2);

                        else
                            xCoord = i - individualColumnWidth * (meta.group_member_count / 2) + (2 * j + 1) * (individualColumnWidth / 2);

                        float yCoord = meta.data[j * meta.glables.size() + i];
                        if (meta.show_tooltip && ImPlot::IsPlotHovered())
                        {
                            ImPlotPoint mouse = ImPlot::GetPlotMousePos();
                            if (std::abs(mouse.x - xCoord) <= meta.size / (meta.group_member_count * 2))
                            {
                                ImGui::BeginTooltip();
                                ImGui::Text("Value: " CONF__OPTKIT__BAR_GROUP_TOOLKIT_PRECISION, yCoord);
                                ImGui::EndTooltip();
                            }
                        }

                        if (meta.show_annotations)
                            ImPlot::Annotation(xCoord, yCoord, ImVec4(1, 1, 1, 0), ImVec2(0, -1), meta.clamp, CONF__OPTKIT__BAR_GROUP_PRECISION, yCoord);
                    }
                }
            if (meta.horz)
                ImPlot::PlotBarGroups(_member_labels.data(), meta.data.data(), meta.group_member_count, meta.glables.size(), meta.size, 0, meta.flags | ImPlotBarGroupsFlags_Horizontal);
            else
                ImPlot::PlotBarGroups(_member_labels.data(), meta.data.data(), meta.group_member_count, meta.glables.size(), meta.size, 0, meta.flags);

            ImPlot::EndPlot();
        }
    }

    optkit::core::BarGroupsMeta ImplotCharts::example_bar_group()
    {

        std::vector<double> data = {83, 67, 23, 89, 83, 78, 91, 82, 85, 90,  // midterm
                                    80, 62, 56, 99, 55, 78, 88, 78, 90, 100, // final
                                    80, 62, 56, 99, 55, 78, 88, 78, 90, 100, // final
                                    80, 69, 52, 92, 72, 78, 75, 76, 89, 95}; // course

        std::vector<std::string> member_labels = {"Midterm Exam", "Final Exam", "Course Grade", "TMP"};      // events in the group
        std::vector<std::string> group_name = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10"}; // iterations
        std::vector<double> positions = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};                                      // iterations

        BarGroupsMeta bar_group{"Students", "Score", "", "Example Block", 4, data, member_labels, group_name, positions};
        return bar_group;
    }

    BarGroupsMeta BarGroupsMeta::convert(const std::string &file_name, std::vector<std::pair<double, std::map<int32_t, std::map<optkit::core::RaplDomain, double>>>> data)
    {

        const std::vector<optkit::core::RaplDomainInfo> &avail_domains = optkit::core::Query::rapl_domain_info();

        std::vector<double> _data;
        std::vector<std::string> member_labels = {"duration (Seconds)"}; // events in the group
        std::vector<std::string> group_name = {};                        // iterations
        std::vector<double> positions = {};                              // iterations

        int read_count = -1;
        int package_num = -1;
        for (const auto &rapl_pair : data)
        {
            read_count++;
            group_name.push_back(std::to_string(read_count));
            positions.push_back(read_count);

            _data.push_back(rapl_pair.first / 1000.0);

            for (const auto &innerpair : rapl_pair.second)
            {
                package_num = innerpair.first;
                for (const auto &domain_value : innerpair.second)
                {
                    for (const auto &info : avail_domains)
                    {
                        if (info.domain == domain_value.first)
                        {
                            std::string _info = info.event + " (" + info.units + ")";
                            if (std::find(member_labels.begin(), member_labels.end(), _info.c_str()) == member_labels.end())
                                member_labels.push_back(_info.c_str());
                            _data.push_back(domain_value.second);
                        }
                    }
                }
            }
        }

        // Rearrange the data
        std::vector<double> _data_;
        int num_groups = group_name.size();
        int num_data_points = _data.size() / num_groups;

        for (int dataIndex = 0; dataIndex < num_data_points; ++dataIndex)
        {
            for (int userIndex = 0; userIndex < num_groups; ++userIndex)
            {
                int originalIndex = userIndex * num_data_points + dataIndex;
                _data_.push_back(_data[originalIndex]);
            }
        }

        BarGroupsMeta bar_group{"Socket " + std::to_string(package_num), "Score", "", file_name, member_labels.size(), _data_, member_labels, group_name, positions};
        return bar_group;
    }
} // namespace optkit::core
