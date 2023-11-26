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
        }
        else if (paranoid <= 0)
        {
            OPTKIT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
            optkit::core::Query::init();
        }
    }

    OptimizerKit::~OptimizerKit()
    {

        int32_t paranoid = this->paranoid();
        if (paranoid <= 0)
        {
            draw();
            optkit::core::Query::destroy();
            OPTKIT_PROFILE_END_SESSION();
        }
    }

    void OptimizerKit::draw(const std::vector<const char *> &file_names)
    {
        if (OPT_LIKELY(file_names.size() != 0))
        {
            OPTKIT_CORE_INFO("Reading all measurement files...");
            // TODO: read all files based on the file pattern and draw charts!
        }
        optkit::platforms::imgui::ImguiLayer_glfw_opengl_impl impl{};
        while (!glfwWindowShouldClose(impl.m_window))
        {
            // Begin loop - create frame
            // -----
            impl.begin_loop();

            // render
            // ------
            impl.on_update(0);

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
