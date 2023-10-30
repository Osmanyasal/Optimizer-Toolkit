#include <utils.hh>
#include <imgui_impl.hh>
#include <query.hh>
#include <block_profiler.hh>
#include <core/events/intel/icl.hh>
#include <utils.hh>

using optkit::core::BlockProfiler;

int32_t main(int32_t argc, char **argv)
{
    OPTKIT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
    optkit::utils::logger::BaseLogger::init();
    optkit::core::Query::init();

    std::cout << optkit::core::Query::pmu_info(PFM_PMU_INTEL_ICL);

    optkit::core::Query::list_avail_pmus();

    if (false)
    {
        // MEASURE BLOCK
        std::cout << "-------------------" << std::endl;

        OPTKIT_CORE_INFO("MONITOR SINGLE");
        float sum = 1.12f;
        double dsum = 0.05;
        {

            BlockProfiler fp_arit{"FP_ARITH", {icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_SINGLE | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE}};
            {
                BlockProfiler inst{"INSTRUCTIONS_RETIRED", {icl::INSTRUCTIONS_RETIRED}};

                sum += 3.14f;
                sum *= 3.14f;
                dsum += 3.152;
            }
        }

        OPTKIT_CORE_INFO("MONITOR COLLECTIVE");
        sum = 1.12f;
        dsum = 0.05;
        {
            BlockProfiler fp_arit{"COLECTIVE_FP_INST", {icl::INSTRUCTIONS_RETIRED, icl::FP_ARITH_INST_RETIRED | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_SINGLE | icl::FP_ARITH__MASK__INTEL_ICL_FP_ARITH_INST_RETIRED__SCALAR_DOUBLE}};
            {

                sum += 3.14f;
                sum *= 3.14f;
                dsum += 3.152;
            }
        }
        OPTKIT_CORE_INFO("sum:{}", sum);
        OPTKIT_CORE_INFO("dsum:{}", dsum);

        // VISUALIZE (OPTIONAL)

        /*
        OPTKIT::platforms::imgui::ImguiLayer_glfw_opengl_impl impl{};
        while (!glfwWindowShouldClose(impl.m_window))
        {
            // input
            // -----
            impl.begin_loop();

            // render
            // ------
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            impl.end_loop();
            glfwSwapBuffers(impl.m_window);
            glfwPollEvents();
        }
        */
    }
    optkit::core::Query::destroy();
    OPTKIT_PROFILE_END_SESSION();
    return 0;
}