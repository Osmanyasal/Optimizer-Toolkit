#include <optkit_core.hh>
#include <core/events/intel/icl.hh>
#include <core/events/amd64/fam19h_zen3.hh>

using optkit::core::BlockProfiler;

#define POWER_CARM {11}
#define STREAM_ARRAY_SIZE 100000

double a[100000];
double b[100000];
double c[100000];
int scalar = 3;

int32_t main(int32_t argc, char **argv)
{
    OPTKIT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
    optkit::utils::logger::BaseLogger::init();
    optkit::core::Query::init();

    auto default_pmu = optkit::core::Query::default_pmu_info();
    auto default_pmu2 = optkit::core::Query::default_pmu_info();
    optkit::core::Query::list_avail_pmus();
    auto avail_pmu_list = optkit::core::Query::get_avail_pmu_ids();

    for (int32_t i : avail_pmu_list)
        std::cout << i << ", ";

    std::cout << std::endl;
    // std::cout << "___________ 447 ____________" << std::endl;
    // optkit::core::Query::list_avail_events(447);


    // STREAM TRIAD??
    {
        BlockProfiler fp_arit{"FP_ARITH", { fam19h_zen3::RETIRED_SSE_AVX_FLOPS | fam19h_zen3::RETIRED_SSE_AVX_FLOPS__MASK__AMD64_FAM19H_ZEN3_RETIRED_SSE_AVX_FLOPS__MULT_FLOPS}};

        ssize_t j;
        #pragma omp parallel for
        for (j = 0; j < STREAM_ARRAY_SIZE; j++)
            a[j] = b[j] + scalar * c[j];
    }
    /*
    optkit::platforms::imgui::ImguiLayer_glfw_opengl_impl impl{};
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

    optkit::core::Query::destroy();
    OPTKIT_PROFILE_END_SESSION();
    return 0;
}