#pragma once

#include <ostream>
#include <iostream>
#include <utils.hh>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <rapl.hh>
#include <libpfm4_wrapper.hh>
#include <unistd.h>
 
std::ostream &operator<<(std::ostream &out, const std::map<int32_t, std::vector<int32_t>> &packages);

namespace optkit::core
{
    /**
     * @brief  ASK System & CPU related queries here<br>
     * This Query class uses <b>libpfm4</b> to retrieve information
     *
     * Don't forget to call init() before using it and destroy() when you're done with it.<br>
     * These 2 method calls can be done at the beginning and end of the application.
     */
    class Query final
    {
    public:
       public:
           static long OPTKIT_SOCKET0__ENABLED;
           static long OPTKIT_SOCKET1__ENABLED;
           static long OPTKIT_SOCKET0__CORE_FREQ;
           static long OPTKIT_SOCKET1__CORE_FREQ;
           static long OPTKIT_SOCKET0__UNCORE_FREQ;
           static long OPTKIT_SOCKET1__UNCORE_FREQ;

           static const int16_t num_cores;
           static const int16_t num_sockets;
           static const bool is_root_priv_enabled;

           /**
            * @brief Gets package - # of cores information
            * @return const ref of static std::unordered_map<int32_t,std::vector<int32_t>> object: package - # of cores
            */
           static const std::map<int32_t, std::vector<int32_t>> &detect_packages();

       private:
           Query() = delete;
           ~Query() = delete;

    };

} // namespace optkit::core
