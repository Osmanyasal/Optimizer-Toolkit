#include <optimizer_toolkit_gui.hh>
#include <cstdio>

namespace OPTKIT::core
{
    OptimizerToolKitGUI *optimizer_toolkit_gui_ptr;

    template <typename T>
    bool core_on_event(T &e)
    {
        if (OPT_LIKELY(optimizer_toolkit_gui_ptr != nullptr))
            optimizer_toolkit_gui_ptr->on_event(e);
        return true; // at this point, event is handled
    }

    OptimizerToolKitGUI::OptimizerToolKitGUI() : is_running{true},
                                           layer_stack{new layer::LayerStack{}}

    {
        optimizer_toolkit_gui_ptr = this;
        CREATE_WINDOW(); // GENERIC CREATE_WINDOW MACRO. DEFINE YOURS IN CONFIG.HH
        REC_CORE_INFO("OptimizerToolKitGUI Created!");

        // delete this to makesure imgui draws successfully
        if (std::remove("imgui.ini") != 0)
        {
            REC_CORE_INFO("imgui.ini file succesfully deleted!");
        }
        else
        {
            REC_CORE_INFO("imgui.ini file deletion failed!");
        }
    }

    void OptimizerToolKitGUI::add_application(Application *application)
    {
        layer_stack->add_layer((OPTKIT::core::layer::Layer *)application);
        imgui_layer = new platforms::imgui::window::ImguiLayer_glfw_opengl_impl{((platforms::linux::window::LinuxWindow *)window)->get_window(), &application->framebuffer};
        layer_stack->add_layer(imgui_layer);
        this->application.reset(application);
        REC_CORE_INFO("Application Added!");
    }

    OptimizerToolKitGUI::~OptimizerToolKitGUI()
    {
        delete layer_stack;
        REC_CORE_INFO("OptimizerToolKitGUI Terminated!");
    }

    bool OptimizerToolKitGUI::on_event(OPTKIT::core::events::Event &e)
    {
        for (auto layer = layer_stack->rbegin(); layer != layer_stack->rend(); layer++)
        {
            if (OPT_LIKELY((*layer)->is_active()))
                (*layer)->on_event(e);
            if (e.is_handled)
                break;
        }

        // all these events, it's unlikely we close the app. this's the general approach.
        if (OPT_UNLIKELY(INSTANCEOF(events::WindowCloseEvent, e) && !e.is_handled))
            is_running = false;

        return true;
    }

    void OptimizerToolKitGUI::start()
    {
        REC_CORE_PROFILE_FUNCTION();

        REC_CORE_INFO("OptimizerToolKitGUI Started!");
        DELTA_TIME_INIT();
        while (OPT_LIKELY(is_running))
        {
            DELTA_TIME_UPDATE();

            imgui_layer->begin_loop();
            application->framebuffer.bind();

            // REC_CORE_TRACE("FPS {}", GET_FPS());
            application->on_update(delta_time);

            application->framebuffer.unbind();

            imgui_layer->end_loop();
            window->on_update();
        }
    }

} // namespace OPTKIT::core
