#include <optimizer_toolkit.hh>

namespace optkit::core
{
    OptimizerKit::OptimizerKit(/* args */)
    {
        OPTKIT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
        optkit::utils::logger::BaseLogger::init();
        optkit::core::Query::init();

        int32_t paranoid = this->paranoid();
        if (OPT_LIKELY(paranoid > 0))
        {
            OPTKIT_CORE_ERROR("perf_event_paranoid {}(current) must be <=0 for ACCURATE data collection by optimizer toolkit!", paranoid);
            OPTKIT_CORE_WARN("FOR ALL EVENTS: set perf_event_paranoid to -1 (SUGGESTED)");
            OPTKIT_CORE_WARN("FOR EVENTS WITH NO SECURITY IMPLICATIONS: set perf_event_paranoid to 0");
            OPTKIT_CORE_WARN("USE: sudo sysctl kernel.perf_event_paranoid=<parameter>");
        }
    }

    OptimizerKit::~OptimizerKit()
    {
        /*
        OPTKIT::platforms::imgui::ImguiLayer_glfw_opengl_impl impl{};
        while (!glfwWindowShouldClose(impl.m_window))
        {
            // input
            // -----
            impl.begin_loop();

            // render
            // ------
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            impl.end_loop();
            glfwSwapBuffers(impl.m_window);
            glfwPollEvents();
        }
        */
        optkit::core::Query::destroy();
        OPTKIT_PROFILE_END_SESSION();
    }

    int32_t OptimizerKit::paranoid(){
        std::string value = read_file("/proc/sys/kernel/perf_event_paranoid");
        return std::stoi(value);
    }

} // namespace optkit::core
