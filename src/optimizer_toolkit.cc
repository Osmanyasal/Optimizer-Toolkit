#include <optimizer_toolkit.hh>

namespace optkit::core
{
    OptimizerKit::OptimizerKit(/* args */)
    {
        optkit::utils::logger::BaseLogger::init();

        int32_t paranoid = this->paranoid();
        if (OPT_UNLIKELY(paranoid > 0))
        {
            OPTKIT_CORE_ERROR("perf_event_paranoid {}(current) must be <=0 for ACCURATE data collection by optimizer toolkit!", paranoid);
            OPTKIT_CORE_WARN("FOR ALL EVENTS: set perf_event_paranoid to -1 (SUGGESTED)");
            OPTKIT_CORE_WARN("FOR EVENTS WITH NO SECURITY IMPLICATIONS: set perf_event_paranoid to 0");
            OPTKIT_CORE_WARN("USE: sudo sysctl kernel.perf_event_paranoid=<parameter>");

            exit(EXIT_FAILURE);
        }
        else if (paranoid <= 0)
        {
            optkit::core::Query::init();
        }
        OPTKIT_CORE_GANTT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
    }

    OptimizerKit::~OptimizerKit()
    {
        draw();
        optkit::core::Query::destroy();
        OPTKIT_CORE_GANTT_PROFILE_END_SESSION();
    }

    void OptimizerKit::draw(const std::vector<const char *> &file_names)
    {
        if (OPT_LIKELY(file_names.size() != 0))
        {
            OPTKIT_CORE_INFO("Reading all measurement files...");
            // TODO: read all files based on the file pattern and draw charts!
        }

        std::vector<double> data = {83, 67, 23, 89, 83, 78, 91, 82, 85, 90,  // midterm  // group data
                                           80, 62, 56, 99, 55, 78, 88, 78, 90, 100, // final
                                           80, 69, 52, 92, 72, 78, 75, 76, 89, 95}; // course

        std::vector<const char *> member_labels = {"Midterm Exam", "Final Exam", "Course Grade"};             // events in the group
        std::vector<const char *> group_name = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10"}; // iterations
        std::vector<double> positions = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};                                       // iterations

        std::vector<double> data2 = {83, 67, 23, 89, 83, 78, 91, 82, 85, 90,  // midterm  // group data
                                    80, 62, 56, 99, 55, 78, 88, 78, 90, 100, // final
                                    80, 69, 52, 92, 72, 78, 75, 76, 89, 95}; // course

        std::vector<const char *> member_labels2 = {"Midterm Exam", "Final Exam", "Course Grade"};             // events in the group
        std::vector<const char *> group_name2 = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10"}; // iterations
        std::vector<double> positions2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};                                       // iterations

        std::vector<optkit::core::BarGroupsMeta> meta_list;
        meta_list.push_back({"block1", 3, data, member_labels, group_name, positions});
        meta_list.push_back({"block2", 3, data2, member_labels2, group_name2, positions2});

        optkit::platforms::imgui::ImguiLayer_glfw_opengl_impl impl{};
        while (!glfwWindowShouldClose(impl.m_window))
        {
            // Begin loop - create frame
            // -----
            impl.begin_loop();

            // render
            // ------
            impl.on_update(meta_list);

            // EndLoop - read events
            // -----
            impl.end_loop();
            glfwSwapBuffers(impl.m_window);
            glfwPollEvents();
        }
    }

    int32_t OptimizerKit::paranoid()
    {
        std::string value = read_file("/proc/sys/kernel/perf_event_paranoid");
        return std::stoi(value);
    }

} // namespace optkit::core
