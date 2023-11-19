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
        BaseProfiler() {}
        virtual ~BaseProfiler() {}

        virtual void disable() = 0;
        virtual void enable() = 0;

        /**
         * @brief Reads the value and stores it in a buffer for subsequent saving to a file.
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

        virtual const std::vector<T>& get_read_buffer() final{
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
            ::write_file("file.txt",json_data);
        }

    private:
        std::vector<T> read_buffer;
    };

} // namespace optkit::core

#endif