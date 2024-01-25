#include <optkit.hh>

namespace optkit::core
{
    /**
     * @brief Construct a new Optimizer Kit:: Optimizer Kit object
     * 
     *  Creates Execution Directory | use existing/random one
     *  Starts Logger and Query class
     * 
     * 
     * @param execution_file 
     */
    OptimizerKit::OptimizerKit(const OPTKIT_CONFIG config) : config{config}
    {
        if(this->config.execution_file.size() > 0)
            EXECUTION_FOLDER_NAME = this->config.execution_file;

        optkit::utils::logger::BaseLogger::init();

        int32_t paranoid = this->paranoid();
        if (OPT_UNLIKELY(paranoid > 0))
        {
            OPTKIT_CORE_ERROR("perf_event_paranoid {}(current) must be <=0 for ACCURATE data collection by optimizer toolkit!", paranoid);
            OPTKIT_CORE_WARN("FOR ALL EVENTS: set perf_event_paranoid to -1 (SUGGESTED)");
            OPTKIT_CORE_WARN("FOR EVENTS WITH NO SECURITY IMPLICATIONS: set perf_event_paranoid to 0");
            OPTKIT_CORE_WARN("USE: sudo sysctl kernel.perf_event_paranoid=<parameter>");

            exit(EXIT_FAILURE);
        }
        else if (paranoid <= 0)
        {
            optkit::core::Query::init();

            create_directory(EXECUTION_FOLDER_NAME);
            OPTKIT_CORE_INFO("Execution file created {}", EXECUTION_FOLDER_NAME);
            if (std::remove("imgui.ini") != 0)
            {
                OPTKIT_CORE_INFO("imgui.ini file succesfully deleted!");
            }
            else
            {
                OPTKIT_CORE_INFO("imgui.ini file deletion failed!");
            }
        }
        OPTKIT_CORE_GANTT_PROFILE_BEGIN_SESSION("Optimizer Toolkit GUI", "optkit_gui_gantt_instr.json");
    }


    /**
     * @brief Destroy the Optimizer Kit:: Optimizer Kit object
     * 
     *  Read all files under the execution directory & print them
     *  Destroy Query utility
     * 
     */
    OptimizerKit::~OptimizerKit()
    {
        if(OPT_LIKELY(this->config.is_draw))
            draw(::get_all_files(EXECUTION_FOLDER_NAME));
            
        optkit::core::Query::destroy();
        OPTKIT_CORE_GANTT_PROFILE_END_SESSION();
    }

    void OptimizerKit::draw(const std::vector<std::string> &file_names)
    {
        std::vector<optkit::core::BarGroupsMeta> meta_list;

#if !CONF__PORTING__IS_PRODUCTION       // don't display this in production code!
        meta_list.push_back(ImplotCharts::example_bar_group());     
#endif

        if (OPT_LIKELY(file_names.size() != 0))
        {
            for (const auto &file_name : file_names)
            {
                // read file
                const auto &val = optkit::core::rapl::from_json(read_file(EXECUTION_FOLDER_NAME + "/" + file_name));
                
                // process json data
                const auto& meta = BarGroupsMeta::convert(file_name,val);

                // add to meta_list
                meta_list.push_back(meta);
            }
        }

        optkit::platforms::imgui::ImguiLayer_glfw_opengl_impl impl{};
        while (!glfwWindowShouldClose(impl.m_window))
        {
            // Begin loop - create frame
            // -----
            impl.begin_loop();

            // render
            // ------
            impl.on_update(meta_list);

            // EndLoop - read events
            // -----
            impl.end_loop();
            glfwSwapBuffers(impl.m_window);
            glfwPollEvents();
        }
    }

    int32_t OptimizerKit::paranoid()
    {
        std::string value = read_file("/proc/sys/kernel/perf_event_paranoid");
        return std::stoi(value);
    }

} // namespace optkit::core
