#include <utils.hh>
#include <imgui_impl.hh>
#include <block_profiler.hh>
// #include <core/events/intel/icl.hh>
#include <core/events/power5/power5.hh>
#include <utils.hh>

int32_t main(int32_t argc, char **argv)
{
    OPTKIT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
    OPTKIT::utils::logger::BaseLogger::init();

    // QUERY PMUs and EVENTS
    pfm_pmu_info_t pmuInfo;
    memset(&pmuInfo, 0, sizeof(pfm_pmu_info_t));
    if (pfm_initialize() == PFM_SUCCESS)
    {
        pfm_get_pmu_info(PFM_PMU_INTEL_CLX, &pmuInfo);
    }
    else
    {
        std::cerr << "İnit failed!\n";
    }

    // Print the members using std::cout
    std::cout << "name: " << pmuInfo.name << std::endl;
    std::cout << "desc: " << pmuInfo.desc << std::endl;
    std::cout << "size: " << pmuInfo.size << std::endl;
    // Print the rest of the members
    std::cout << "pmu: " << pmuInfo.pmu << std::endl;
    std::cout << "type: " << pmuInfo.type << std::endl;
    std::cout << "nevents: " << pmuInfo.nevents << std::endl;
    std::cout << "first_event: " << pmuInfo.first_event << std::endl;
    std::cout << "max_encoding: " << pmuInfo.max_encoding << std::endl;
    std::cout << "num_cntrs: " << pmuInfo.num_cntrs << std::endl;
    std::cout << "num_fixed_cntrs: " << pmuInfo.num_fixed_cntrs << std::endl;

    pfm_terminate();

    // MEASURE BLOCK
    float sum = 1.12;
    {
        optkit::ibm::power5::PM_LSU_REJECT_RELOAD_CDF;
        // BlockProfiler inst{"INSTRUCTIONS_RETIRED", (uint64_t)intel::icl::INSTRUCTIONS_RETIRED};
        for (size_t i = 1; i <= 10; i++)
        {
            if (i % 2 == 0)
                sum *= i;
        }
    }

    OPTKIT_CORE_INFO("sum:{}", sum);

    // VISUALIZE (OPTIONAL)

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

    OPTKIT_PROFILE_END_SESSION();
    return 0;
}