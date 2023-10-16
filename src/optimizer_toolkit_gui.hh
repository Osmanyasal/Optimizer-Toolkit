#ifndef OPTIMIZER_TOOLKIT__SRC__CORE__OPTIMIZER_TOOLKIT_GUI_HH
#define OPTIMIZER_TOOLKIT__SRC__CORE__OPTIMIZER_TOOLKIT_GUI_HH
 
#include <application.hh>
namespace OPTKIT::core
{ 
  
    class OptimizerToolKitGUI
    {
    public:
        OptimizerToolKitGUI();
        virtual ~OptimizerToolKitGUI();
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

    extern OptimizerToolKitGUI *optimizer_toolkit_gui_ptr;

    // global on_event function
    template <typename T>
    bool core_on_event(T &e);

} // namespace Recursion

#endif
