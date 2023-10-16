#include <optimizer_toolkit_gui.hh>
#include <proj1.hh>

int32_t main(int32_t argc, char **argv)
{
    REC_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
    OPTKIT::utils::logger::BaseLogger::init();
    OPTKIT::core::OptimizerToolKitGUI optkit_gui;

    // ADD YOUR PROJECT HERE!!
    optkit_gui.add_application(new Proj1);
    //**

    optkit_gui.start();
    REC_PROFILE_END_SESSION();
    return 0;
}
