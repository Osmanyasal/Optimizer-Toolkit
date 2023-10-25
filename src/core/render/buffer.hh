#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RENDER__BUFFER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RENDER__BUFFER_HH

#include <bindable.hh>
#include <shader.hh>

namespace OPTKIT::core::render
{
    class Buffer : public Bindable
    {
    public:
        Buffer() {}
        virtual ~Buffer() {}
    };

    class Drawable : public Buffer
    {
    public:
        Drawable() {}
        virtual ~Drawable() {}
        virtual void draw(Shader &shader) = 0;
        virtual bool is_transparent() { return false; }
    };

    // MUST BE EXTENDED TO OTHER PLATFORMS
    class BufferLayout
    {
    public:
        BufferLayout() {}
        virtual ~BufferLayout() {}
    };

} // namespace OPTKIT::core::render

#endif