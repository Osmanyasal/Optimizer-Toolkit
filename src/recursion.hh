#ifndef OPTIMIZER_TOOLKIT__SRC__CORE__RECURSION_HH
#define OPTIMIZER_TOOLKIT__SRC__CORE__RECURSION_HH
 
#include <application.hh>
namespace OPTKIT::core
{
    // global on_event function
    extern Engine *engine_ptr;
    template <typename T>
    bool core_on_event(T &e);

    class Engine
    {
    public:
        Engine();
        virtual ~Engine();
        void add_application(Application *application);
        virtual void start() final;

        bool on_event(OPTKIT::core::events::Event &e);

    private:
        std::unique_ptr<Application> application;
        bool is_running;
        window::Window *window;
        layer::LayerStack *layer_stack;
        platforms::imgui::window::ImguiLayer_glfw_opengl_impl *imgui_layer;
    };

} // namespace Recursion

#endif
