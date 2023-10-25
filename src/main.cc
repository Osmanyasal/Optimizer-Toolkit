#include <utils.hh>
int32_t main(int32_t argc, char **argv)
{
    REC_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
    OPTKIT::utils::logger::BaseLogger::init();
    REC_PROFILE_END_SESSION();
    return 0;
}
