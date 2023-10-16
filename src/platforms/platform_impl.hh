#ifndef OPTIMIZER_TOOLKIT__SRC__PLATFORMS__PLATOFORM_IMPL_HH
#define OPTIMIZER_TOOLKIT__SRC__PLATFORMS__PLATOFORM_IMPL_HH

#include <platforms_gui.hh>
#include <platforms_linux.hh>
#include <platforms_opengl.hh>

namespace platforms = OPTKIT::platforms;
using platforms::opengl::render::OpenGLFrameBuffer;

#if defined(__render_api__) && __render_api__ == 1 // opengl @see linux_config.hh
using shapes = OPTKIT::platforms::opengl::scene::OpenGLShapes;
using shader = OPTKIT::platforms::opengl::render::OpenGLShader;
#endif

#endif