#include <utils.hh>
#include <imgui_impl.hh>
int32_t main(int32_t argc, char **argv)
{
    OPTKIT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
    OPTKIT::utils::logger::BaseLogger::init();
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

    OPTKIT_PROFILE_END_SESSION();
    return 0;
}
