#ifndef OPTIMIZER_TOOLKIT__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_INPUT_HH
#define OPTIMIZER_TOOLKIT__SRC__PLATFORMS__IMGUI_LAYER_GLFW_OPENGL_INPUT_HH
 
#include <Input.hh>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace OPTKIT::platforms::imgui::window
{
    class Glfw_OpenGL_Input : public OPTKIT::core::input::BaseInput
    {
    public:
        Glfw_OpenGL_Input(GLFWwindow *gl_window);
        virtual ~Glfw_OpenGL_Input() {}

        virtual bool is_key_pressed(int32_t key_code) override;
        virtual bool is_mouse_button_pressed(int32_t mouse_button_code) override;
        virtual void get_cursor_pos(double *xpos, double *ypos) override;

    private:
        GLFWwindow *gl_window;
    };
} // namespace OPTKIT::platforms::imgui::window

#endif