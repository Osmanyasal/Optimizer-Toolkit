#ifndef OPTIMIZER_TOOLKIT__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_RENDER_CONTEXT_HH
#define OPTIMIZER_TOOLKIT__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_RENDER_CONTEXT_HH

#include <gui_config.hh>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <render_context.hh>
namespace OPTKIT::platforms::opengl::render
{
    class OpenGLRenderContext : public core::render::RenderContext<GLFWwindow>
    {
    public:
        OpenGLRenderContext(const core::window::WindowProps &default_props = core::window::WindowProps());
        virtual ~OpenGLRenderContext() {}
        virtual void swap_buffer() override;
    };

} // namespace OPTKIT::opengl::render

#endif