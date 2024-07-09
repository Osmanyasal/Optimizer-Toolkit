
#include <base_governor.hh>

namespace optkit::core::freq
{

    BaseGovernor *BaseGovernor::current_governor = nullptr;
    std::vector<float> BaseGovernor::mean;
    std::vector<float> BaseGovernor::scale;

    TF_Tensor *BaseGovernor::input_tensor;
    TF_SessionOptions *BaseGovernor::session_opts;
    TF_Buffer *BaseGovernor::run_opts;
    const char *BaseGovernor::saved_model_dir;
    const char *BaseGovernor::tags[1];
    TF_Graph *BaseGovernor::graph;
    TF_Status *BaseGovernor::status;
    TF_Session *BaseGovernor::session;
    
    float BaseGovernor::current_core_freq = 0;
    float BaseGovernor::current_uncore_freq = 0;

    BaseGovernor::BaseGovernor(int64_t sample_period) : config{false, true, false, 0, -1}, sample_period{sample_period}
    {
        this->config.perf_event_config.sample_period = this->sample_period;
        this->config.cpu = 1; /// set thread 1 for cpu_cycle callbacks!!    // TODO: This must be changed based on the cores given to the program!

        memset(&sa, 0, sizeof(struct sigaction));
        sa.sa_sigaction = BaseGovernor::call_back;
        sa.sa_flags = SA_SIGINFO;
        if (sigaction(SIGIO, &sa, NULL) < 0)
        {
            OPTKIT_CORE_ERROR("Error setting up signal handler");
            exit(1);
        }

        read_scaler_file(BaseGovernor::mean, BaseGovernor::scale);

        session_opts = TF_NewSessionOptions();
        run_opts = nullptr;
        tags[0] = "serve";
        graph = TF_NewGraph();
        status = TF_NewStatus();
        saved_model_dir = "/usr/local/include/optkit_governor_model/";
        session = TF_LoadSessionFromSavedModel(session_opts, run_opts, saved_model_dir, tags, 1, graph, nullptr, status);
    }

    BaseGovernor::~BaseGovernor()
    {
        // Clean up
        TF_DeleteTensor(input_tensor);
        TF_DeleteGraph(graph);
        TF_DeleteSession(session, status); // Use status for TF_DeleteSession
        TF_DeleteSessionOptions(session_opts);
        TF_DeleteStatus(status); // Clean up status
    }

    void BaseGovernor::call_back(int32_t signum, siginfo_t *oh, void *blah)
    {
        if (OPT_UNLIKELY(BaseGovernor::current_governor == nullptr))
            return;

        // DISABLE CALL_BACK TRIGGER to prevent multiple entry
        current_governor->disalbe_callback_trigger();

        // static int32_t i = 0;
        // OPTKIT_CORE_INFO("{} th call_back() called", ++i);
        current_governor->snapshot_pmus();
        double compute_intensity = current_governor->compute_intensity();
        double memory_intensity = current_governor->memory_intensity();
        // OPTKIT_CORE_INFO("compute intensity = {}", compute_intensity);
        // OPTKIT_CORE_INFO("memory intensity ={}", memory_intensity);
        std::cout << compute_intensity << "," << memory_intensity << " --- ";

        // scale input!
        static float new_data[2]{0, 0};
        new_data[0] = (compute_intensity - BaseGovernor::mean[0]) / BaseGovernor::scale[0];
        new_data[1] = (memory_intensity - BaseGovernor::mean[1]) / BaseGovernor::scale[1];

        static const int64_t input_dims[2]{1, 2};
        input_tensor = TF_NewTensor(TF_FLOAT, input_dims, 2, new_data, 2 * sizeof(float), [](void *data, size_t len, void *arg) {}, nullptr);

        static const char *input_names[] = {"serving_default_dense_input"};
        static TF_Output inputs[] = {
            {TF_GraphOperationByName(graph, input_names[0]), 0}};

        static const char *output_names[] = {"StatefulPartitionedCall"};
        static TF_Output outputs[] = {
            {TF_GraphOperationByName(graph, output_names[0]), 0}};

        // Run session to make prediction
        TF_Tensor *output_tensor = nullptr;
        TF_SessionRun(session,
                      nullptr,                    // Run options.
                      inputs, &input_tensor, 1,   // Input tensors, input tensor count.
                      outputs, &output_tensor, 1, // Output tensors, output tensor count.
                      nullptr, 0,                 // Target operations, number of targets.
                      nullptr,                    // Run metadata.
                      status);                    // Status object

        // Print prediction
        if (output_tensor)
        {
            auto data = static_cast<float *>(TF_TensorData(output_tensor));

            std::cout << "current vals: " << current_core_freq << "--" << current_uncore_freq << " *** ";
            std::cout << "predicted values: " << data[0] << "--" << data[1] << " ";
            if (std::abs(current_core_freq - data[0]) < 0.1 && std::abs(current_uncore_freq - data[1]) < 0.1){ 
                std::cout << "*** returning ***" << std::endl;
                return;
            }
            std::cout << "\n";
            current_core_freq = data[0];
            current_uncore_freq = data[1];

            // std::cout << "Predicted values: ";
            // for (int i = 0; i < 2; ++i)
            // {
            //     std::cout << data[i] << " ";
            // }
            // std::cout << std::endl;

            if (Query::OPTKIT_SOCKET0__ENABLED)
            {
                if (Query::OPTKIT_SOCKET0__CORE_FREQ != -1)
                {
                    CPUFrequency::set_core_frequency(current_core_freq * GHZ, 0);
                }
                if (Query::OPTKIT_SOCKET0__UNCORE_FREQ != -1)
                {
                    CPUFrequency::set_uncore_frequency(current_uncore_freq * GHZ, 0);
                }
            }
            if (Query::OPTKIT_SOCKET1__ENABLED)
            {
                if (Query::OPTKIT_SOCKET1__CORE_FREQ != -1)
                {
                    CPUFrequency::set_core_frequency(current_core_freq * GHZ, 1);
                }
                if (Query::OPTKIT_SOCKET1__UNCORE_FREQ != -1)
                {
                    CPUFrequency::set_uncore_frequency(current_uncore_freq * GHZ, 1);
                }
            }

            TF_DeleteTensor(output_tensor);
        }

        // ENABLE CALL_BACK TRIGGER to prevent multiple entry
        current_governor->enable_callback_trigger();
    }

    void BaseGovernor::read_scaler_file(std::vector<float> &mean_values, std::vector<float> &scale_values)
    {
        if (mean_values.size() != 0 && scale_values.size() != 0)
            return;

        mean_values.clear();
        scale_values.clear();
        static std::string file_txt = ::read_file("/usr/local/include/optkit_governor_model/scaler.txt");
        auto lines = ::str_split(file_txt, "\n");
        mean_values.push_back(std::atof(lines[0].c_str()));
        mean_values.push_back(std::atof(lines[1].c_str()));
        scale_values.push_back(std::atof(lines[2].c_str()));
        scale_values.push_back(std::atof(lines[3].c_str()));
    }
}