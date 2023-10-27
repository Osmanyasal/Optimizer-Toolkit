// #include <utils.hh>
// #include <imgui_impl.hh>
#include <block_profiler.hh>
// #include <core/events/intel/icl.hh>
int32_t main(int32_t argc, char **argv)
{
    // OPTKIT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
    // OPTKIT::utils::logger::BaseLogger::init();
    // OPTKIT::platforms::imgui::ImguiLayer_glfw_opengl_impl impl{};

    float sum = 1.12;
    {   
        BlockProfiler inst{"INSTRUCTIONS_RETIRED", 0xc0};
        for (size_t i = 1; i <= 10; i++)
        {
            if (i % 2 == 0)
                sum *= i;
        }
    }

    // while (!glfwWindowShouldClose(impl.m_window))
    // {
    //     // input
    //     // -----
    //     impl.begin_loop();

    //     // render
    //     // ------
    //     glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //     glClear(GL_COLOR_BUFFER_BIT);

    //     impl.end_loop();
    //     glfwSwapBuffers(impl.m_window);
    //     glfwPollEvents();
    // }

    // OPTKIT_PROFILE_END_SESSION();
    return 0;
}
