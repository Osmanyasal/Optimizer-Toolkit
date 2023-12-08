#ifndef OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BASE_PROFILER_HH
#define OPTIMIZER_TOOLKIT_CORE__SRC__CORE__PROFILING__BASE_PROFILER_HH

#include <utils.hh>
#include <cstdint>
#include <cstring>
#include <vector>
#include <profiler_config.hh>
namespace optkit::core
{
    template <typename T>
    class BaseProfiler
    {
    public:
        BaseProfiler(const char *block_name, const char *event_name) : block_name{block_name}, event_name{event_name}, start{std::chrono::high_resolution_clock::now()}
        {
        }
        virtual ~BaseProfiler() {}

        virtual void disable() = 0;
        virtual void enable() = 0;

        /**
         * @brief Reads the value and STORES it in a buffer for subsequent saving to a file.
         *        Read also store the duration time between start-end and re-set the start to end value afterwards
         * @return T
         */
        virtual std::pair<double, T> read() final
        {
            // stop timer
            auto end = std::chrono::high_resolution_clock::now();

            // read value
            const T &val = read_val();

            // calculate duration in ms
            auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0f;

            // write to buffer
            read_buffer.push_back({duration_ms, val});

            // re-set start time to now
            this->start = end;

            return read_buffer.back();
        }

        /**
         * @brief read_val method that refrains from storing the value in a buffer for future writing.
         *        read_val should NOT! mess with time durations, only should read data and retrun it.
         * @return T
         */
        virtual T read_val() = 0;

        /**
         * @brief Convert buffer to json string as you wish.
         *
         * @return std::string
         */
        virtual std::string convert_buffer_to_json() = 0;

        virtual const std::vector<std::pair<double, T>> &get_read_buffer() final
        {
            return read_buffer;
        }

    protected:
        /**
         * @brief Converts the buffer to JSON format and writes it to a file.
         *
         */
        virtual void save() final
        {
            const std::string &json_data = convert_buffer_to_json();
            std::string file_name = block_name;
            file_name = file_name;
            std::replace(file_name.begin(), file_name.end(), ' ', '_');
            file_name = EXECUTION_FOLDER_NAME + "/" + file_name + "__" + event_name;
            for (char &c : file_name)
                c = std::tolower(c);

            file_name.append(".json");
            ::write_file(file_name, json_data, true);
        }

    public:
        const char *block_name;
        const char *event_name;

    protected:
        std::chrono::high_resolution_clock::time_point start;
        std::vector<std::pair<double, T>> read_buffer;
    };

} // namespace optkit::core

#endif