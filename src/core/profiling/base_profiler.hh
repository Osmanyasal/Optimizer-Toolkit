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
        BaseProfiler(const char *block_name, const char *event_name) : block_name{block_name}, event_name{event_name} {}
        virtual ~BaseProfiler() {}

        virtual void disable() = 0;
        virtual void enable() = 0;

        /**
         * @brief Reads the value and STORES it in a buffer for subsequent saving to a file.
         *
         * @return T
         */
        virtual T read() final
        {
            const T &val = read_val();
            read_buffer.push_back(val);
            return val;
        }

        /**
         * @brief read_val method that refrains from storing the value in a buffer for future writing.
         *
         * @return T
         */
        virtual T read_val() = 0;

        /**
         * @brief Convert buffer to json string as you wish.
         *
         * @return std::string
         */
        virtual std::string convert_buffer_to_json() = 0;

        virtual const std::vector<T> &get_read_buffer() final
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
            file_name.append(".json");
            ::write_file(file_name, json_data);
        }

    protected:
        std::chrono::high_resolution_clock::time_point start;

    public:
        const char *block_name;
        const char *event_name;

    protected:
        std::vector<T> read_buffer;
    };

} // namespace optkit::core

#endif