#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RENDER__RENDERING_API_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__RENDER__RENDERING_API_HH

namespace OPTKIT::core::render
{
    enum class RenderAPI
    {
        NONE,
        OPENGL,
        VULKAN,
        D3D
    };

} // namespace OPTKIT::core::render
#endif