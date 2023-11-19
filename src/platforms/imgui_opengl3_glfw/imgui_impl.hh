#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_IMPL_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_IMPL_HH

#define IMGUI_DEFINE_MATH_OPERATORS

#include <utils.hh>
#include <gui_config.hh>
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <imgui_logger.hh>
#include <implot.h>
#include <implot_internal.h> 
#include <implot_charts.hh>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace optkit::platforms::imgui
{

    class ImguiLayer_glfw_opengl_impl
    {
    public:
        ImguiLayer_glfw_opengl_impl()
        { 
            on_attach();
        }
        ~ImguiLayer_glfw_opengl_impl() { on_detach(); }

        void on_attach();
        void on_detach();
        void on_update(float delta_time);

        void begin_loop();
        void end_loop();
        void set_dark_theme_colors();
        void set_white_theme_colors(); 

    public:
        GLFWwindow *m_window;
    };

    void framebuffer_size_callback(GLFWwindow *window, int width, int height);

} // namespace OPTKIT::core::window

#endif