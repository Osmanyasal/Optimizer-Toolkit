#ifndef OPTIMIZER_TOOLKIT__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_IBO_HH
#define OPTIMIZER_TOOLKIT__SRC__PLATFORMS__RENDER__OPENGL__OPENGL_IBO_HH

#include <logger.hh>
#include <buffer.hh>
#include <GL/glew.h>

namespace OPTKIT::platforms::opengl::render
{
    class IndexBuffer : public core::render::Buffer
    {
    public:
        IndexBuffer();
        IndexBuffer(const uint32_t *data, uint32_t size_in_bytes, uint32_t draw_method = GL_STATIC_DRAW);
        virtual ~IndexBuffer();

        virtual void bind() override;
        virtual void unbind() override;
        virtual void destroy() override;

        uint32_t IBO;
    };

} // namespace OPTKIT::core::render

#endif